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
    echo -e "\033[${color}m$*\033[0m"
  else
    echo "$*"
  fi
}

if [ `id -u` -ne 0 ];
  then
  fecho COL 31 "Not enough permissions to uninstall. Please login as root."
  exit 1
  else
  fecho COL 33 "Uninstalling driver"
 
  /bin/cp -f /etc/fstab /etc/fstab.ufsd
  /bin/echo -n >/etc/fstab
  while read entry; do
    device="`echo \"$entry\" | awk '{print $1}'`"
    mountpoint="`echo \"$entry\" | awk '{print $2}'`"
    fstype="`echo \"$entry\" | awk '{print $3}'`"
    options="`echo \"$entry\" | awk '{print $4}'`"
    freq="`echo \"$entry\" | awk '{print $5}'`"
    passno="`echo \"$entry\" | awk '{print $6}'`"
    unset is_ufsd
    case "$options" in
    *dev=ufsd*) is_ufsd=1;;
    esac
    case "$fstype" in
    *ufsd*) is_ufsd=1;;
    esac
    if [ -n "$is_ufsd" ]; then
      umount $device >/dev/null 2>&1
      rmdir $mountpoint >/dev/null 2>&1
      echo "removing line $device $mountpoint $options $fstype $passno $freq $passno from fstab"
    else
      echo "$device $mountpoint $fstype $options $freq $passno" >>/etc/fstab
    fi
  done < /etc/fstab.ufsd
  
  
  [ "`find /lib/modules/\`uname -r\` -iname ufsd.ko`" ] && rm -f `find /lib/ -iname ufsd.ko`
  [ "`find /lib/modules/\`uname -r\` -iname jnl.ko`" ] && rm -f `find /lib/ -iname jnl.ko`
  depmod -a


  if [ -f Makefile ]
    then
    /usr/bin/make driver_uninstall
  fi

  if [ -d /usr/src/paragon-ufsd-${D_VER} ]; then
    dkms uninstall -m paragon-ufsd -v ${D_VER} > /dev/null 2>&1
    dkms remove -m paragon-ufsd -v ${D_VER} --all > /dev/null 2>&1
    rm -rf /usr/src/paragon-ufsd-${D_VER} > /dev/null 2>&1
    rm -rf /var/lib/dkms/paragon-ufsd > /dev/null 2>&1
  fi

  fecho COL 33 "Driver uninstalled!"


  if [ -d linutil ];
  then
    fecho COL 33 "Would you like to uninstall NTFS/HFS utilites? [yes/no]"
    read answer
    case "$answer" in
    y|Y|yes|Yes|YES)
    if [ -d /usr/src/paragon-ufsd-${D_VER}/linutil/ ]
      then
      cd /usr/src/paragon-ufsd-${D_VER}/linutil/
      /usr/bin/make remove
      cd $LP
      else
      cd linutil/
      /usr/bin/make remove
    fi
    for i in $(which -a mkntfs_) ; do
    mv ${i} `echo ${i} | sed -e 's/_$//g'`
    done
    [ -f /usr/sbin/mount.paragon-ufsd ] && rm -f /usr/sbin/mount.paragon-ufsd /sbin/mount.ntfs /usr/sbin/mount.ntfs /sbin/mount.hfsplus /usr/sbin/mount.hfsplus
    [ -f /sbin/mount.ntfs.bak ] && mv /sbin/mount.ntfs.bak /sbin/mount.ntfs
    [ -f /usr/sbin/mount.ntfs.bak ] && mv /usr/sbin/mount.ntfs.bak /usr/sbin/mount.ntfs
    fecho COL 33 "Utilities uninstalled!"
    ;;
    *)
    ;;
    esac
  fi
fi

