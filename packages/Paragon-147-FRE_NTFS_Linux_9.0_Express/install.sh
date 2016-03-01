#!/bin/bash

if [ "`echo -e TEST`" = "-e TEST" ]; then
	IS_POSIX=1
fi

LP=`pwd`
D_VER=90

fecho()
{
	if [ "$1" = "COL" ]; then
		shift
		color="$1"
		shift
	fi
	if [ -z "$IS_POSIX" ]; then
		echo -e "\033[${color}m$*\033[0m" | tee -a $LP/paragon-ufsd-install.log
	else
		echo "$*" | tee -a $LP/paragon-ufsd-install.log
	fi
}

if echo $LP | grep -q :
	then
	fecho COL 31 "Path to current work directory $LP contains invalid character." 
	fecho COL 31 "Installation was aborted." 
	exit 1
fi

run_install_driver() {
fecho COL 31 "Continue installing? [yes/no/read]."
read answer
case "$answer" in
y|Y|yes|Yes|YES)

echo "================= UFSD install log ===================" > $LP/paragon-ufsd-install.log
echo "Start: "`date`  2>&1  >> $LP/paragon-ufsd-install.log
echo "OS Version: "`uname -a`  2>&1 >> $LP/paragon-ufsd-install.log

# check kernel version
# define available versions
min_major=2
min_minor=6
min_patch=36

max_major=3
max_minor=14
max_patch=4

print_version_error()
{
	fecho COL 31 "Current kernel version is out of supported range. Proceed at your own risk? [yes/No]"
	read answer
	case "$answer" in
		n|N|no|No|NO)
			exit 1
		;;
		*)
		;;
	esac
}

# get current version
curr_major=`uname -r | cut -d'-' -f1 | cut -d'.' -f1`
curr_minor=`uname -r | cut -d'-' -f1 | cut -d'.' -f2`
curr_patch=`uname -r | cut -d'-' -f1 | cut -d'.' -f3`

# compare versions
if ! [ $min_major -lt $curr_major ] 
then
  if ! [ $min_major -eq $curr_major -a $min_minor -lt $curr_minor ]
  then 
    if ! [ $min_minor -eq $curr_minor -a $min_patch -le $curr_patch ]
    then 
      print_version_error
    fi
  fi
fi

if ! [ $max_major -gt $curr_major ] 
then
  if ! [ $max_major -eq $curr_major -a $max_minor -gt $curr_minor ]
  then 
    if ! [ $max_minor -eq $curr_minor -a $max_patch -ge $curr_patch ]
    then 
      print_version_error
    fi
  fi
fi

# end check kernel version

fecho COL 32 "Searching and removing previously installed UFSD driver in /lib/modules/`uname -r`/"
[ "`find /lib/modules/\`uname -r\` -iname ufsd.ko`" ] && rm -f `find /lib/ -iname ufsd.ko`
[ "`find /lib/modules/\`uname -r\` -iname jnl.ko`" ] && rm -f `find /lib/ -iname jnl.ko`

if ! [ -d util/ ]
then
touch express.version
fi

#################################################################################################
# Next options such as dkms support and additional utilities are available in Professional      #
# version only.                                                                                 #
# Please consider buying Paragon NTF/HFS for Linux Professional if you want to make them work.  #
# http://www.paragon-software.com/home/ntfs-linux-professional/                                 #
#################################################################################################

	if [ -f util/mount.paragon-ufsd ];
	then
	fecho COL 33 "Would you like to mount NTFS/HFS volumes with UFSD driver automatically? [yes/no]"
	read answer
	case "$answer" in
	y|Y|yes|Yes|YES)

	[ -f /sbin/mount.ntfs ] && mv -n /sbin/mount.ntfs /sbin/mount.ntfs.bak
	[ -f /usr/sbin/mount.ntfs ] && mv -n /usr/sbin/mount.ntfs /usr/sbin/mount.ntfs.bak
		
	cp util/mount.paragon-ufsd  /usr/sbin/
	chown root:root /usr/sbin/mount.paragon-ufsd
	chmod 04755 /usr/sbin/mount.paragon-ufsd

	ln -sf /usr/sbin/mount.paragon-ufsd /sbin/mount.ntfs
	ln -sf /usr/sbin/mount.paragon-ufsd /usr/sbin/mount.ntfs
	ln -sf /usr/sbin/mount.paragon-ufsd /sbin/mount.hfsplus
	ln -sf /usr/sbin/mount.paragon-ufsd /usr/sbin/mount.hfsplus
	fecho COL 32 "Automount configured"
	;;
	*)
   	;;
	esac
	fi

	if [ -f util/paragon-dkms.conf ]
	then
	fecho COL 33 "Would you like UFSD driver to rebuild after kernel updates? [yes/no]"
	read answer
	case "$answer" in
	y|Y|yes|Yes|YES)

		if ! which dkms > /dev/null
		then
		fecho COL 32 "Error: please install dkms package first"
		else

		[ -d /usr/src/paragon-ufsd-${D_VER} ] && rm -rf /usr/src/paragon-ufsd-${D_VER}
		[ -d /var/lib/dkms/paragon-ufsd/ ] && rm -rf /var/lib/dkms/paragon-ufsd/

		if [ -x "`which systemd`" ]
		then
			if ! [ "`systemctl status dkms_autoinstaller | grep active`" ]
			then
			fecho COL 31 "Service dkms_autoinstaller is disabled or not installed. Driver may not rebuild with kernel updates."
			fecho COL 31 "Please run 'insserv /usr/lib/dkms/dkms_autoinstaller' to install and\or 'systemctl start dkms_autoinstaller' to enable it."
			fi
		fi

		fecho COL 32 "Setting DKMS configuration"
		mkdir /usr/src/paragon-ufsd-${D_VER}/
		cp -r ./ /usr/src/paragon-ufsd-${D_VER}/
		mv /usr/src/paragon-ufsd-${D_VER}/util/paragon-dkms.conf /usr/src/paragon-ufsd-${D_VER}/dkms.conf
		dkms add -m paragon-ufsd -v ${D_VER} >> $LP/paragon-ufsd-install.log
		fecho COL 32 "Preparing to install"
		dkms build -m paragon-ufsd -v ${D_VER} >> $LP/paragon-ufsd-install.log
		
			if [ "$?" != "0" ]
			then
			fecho COL 31 "Can't prepare driver configuration"
			echo "=====\/\/\/========= DKMS Configure log ==========\/\/\/======" >> $LP/paragon-ufsd-install.log
			cat /var/lib/dkms/paragon-ufsd/${D_VER}/`uname -r`/`uname -m`/log/make.log >> $LP/paragon-ufsd-install.log
			echo "=====/\/\/\========= DKMS Configure log ==========/\/\/\======" >> $LP/paragon-ufsd-install.log
			exit 1
			fi

		echo "=====\/\/\/========= DKMS Configure log ==========\/\/\/======" >> $LP/paragon-ufsd-install.log
		cat /var/lib/dkms/paragon-ufsd/${D_VER}/`uname -r`/`uname -m`/log/make.log >> $LP/paragon-ufsd-install.log
		echo "=====/\/\/\========= DKMS Configure log ==========/\/\/\======" >> $LP/paragon-ufsd-install.log		


		fecho COL 32 "Building and installing driver to kernel `uname -r`"
		dkms install -m paragon-ufsd -v ${D_VER} >> $LP/paragon-ufsd-install.log
		
			if [ "$?" != "0" ]			
			then
			fecho COL 31 "Can't build driver"
			exit 1
			fi
		
		fecho COL 32 "Driver was installed to system"
		fi
	;;
	*)
	touch no_dkms.version
	;;
	esac
	fi

	if [ -f express.version ] || [ -f no_dkms.version ]
	then
	fecho COL 32 "Preparing to install"
	
		[ -f Makefile ] && make clean >> $LP/paragon-ufsd-install.log

		if ! ./configure >> $LP/paragon-ufsd-install.log 2>&1
		then
		fecho COL 31 "Can't prepare driver configuration"
		echo "=====\/\/\/========= Configure log ==========\/\/\/======" >> $LP/paragon-ufsd-install.log
		cat config.log >> $LP/paragon-ufsd-install.log
		echo "=====/\/\/\========= Configure log ==========/\/\/\======" >> $LP/paragon-ufsd-install.log
		exit 1
		fi
	
	fecho COL 32 "Building driver to kernel `uname -r`"

		if ! make driver >> $LP/paragon-ufsd-install.log 2>&1
		then
		fecho COL 31 "Can't build driver"
		exit 1
		fi

	fecho COL 32 "Install driver to kernel `uname -r`"

		if ! make driver_install >> $LP/paragon-ufsd-install.log 2>&1
		then
		fecho COL 31 "Can't install driver"
		exit 1
		fi

	fecho COL 32 "Driver was installed to system"
	fi

	if [ -x "`which systemd`" ]
	then
	fecho COL 32 "Setting driver autoload at system startup"
	echo ufsd > /etc/modules-load.d/paragon-ufsd.conf
	fi

	if [ -f /etc/modules ] && [ -z "`grep ufsd /etc/modules`" ]
	then
    echo jnl >> /etc/modules
    echo ufsd >> /etc/modules
	fi

	if [ -d linutil ];
	then
	fecho COL 33 "Would you like to install NTFS/HFS utilites? [yes/no]"
	read answer
	case "$answer" in
	y|Y|yes|Yes|YES)
	
	
	which mkntfs > /dev/null 2>&1
		if [ "$?" != "1" ]			
		then
		for i in $(which -a mkntfs) ; do
		mv -n ${i} ${i}_
		done
		fi

		if [ -d /usr/src/paragon-ufsd-${D_VER}/linutil/ ]
		then
		cd /usr/src/paragon-ufsd-${D_VER}/linutil/
		else
		cd linutil/
		fi

	fecho COL 32 "Making NTFS/HFS utilites"

		if ! make >> $LP/paragon-ufsd-install.log 2>&1
		then
		fecho COL 31 "Can't make utilites"
		exit -1
		fi

	fecho COL 32 "Installing NTFS/HFS utilites"

		if ! make install >> $LP/paragon-ufsd-install.log 2>&1
		then
		fecho COL 31 "Can't install utilites"
		exit -1
		fi

	fecho COL 32 "Utilites installed"
	cd $LP
   	;;
	*)
   	;;
	esac
	fi

fecho COL 32 "Installation complete!"
;;
r|R|read|Read|READ)
less License.txt
run_install_driver
;;
*)
;;
esac
}

if [ `id -u` -ne 0 ];
then
fecho COL 31 "Not enough permissions to install. Please login as root."
exit 1
	
else
fecho COL 31 "By installing this software you accept the terms of End User License Agreement listed in License file."
run_install_driver
fi
