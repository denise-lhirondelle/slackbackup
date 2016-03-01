ifdef src
    src := $(src)/
endif

#Module
#Module
MODULE_SRC := ifslinux
ifeq (0,1)
MODULE_NAME := ufsd_debug
else
MODULE_NAME := ufsd
endif

ifeq (1,1)
ifeq (0,1)
MODULE_NAME2 := jnl_debug
else
MODULE_NAME2 := jnl
endif
endif

MODULE_LIBNAME := libufsd
MODULE_OBJECTS := $(MODULE_SRC)/ufsdvfs.o $(MODULE_SRC)/vfsdebug.o

MODULE_EXTRA_FLAGS := -include $(src)$(MODULE_SRC)/fs_conf.h -DUFSD_DEVICE=ufsd -DUFSD_USE_ASM_DIV64
ifeq (0,1)
MODULE_EXTRA_FLAGS += -DUFSD_DEBUG -g3
LDFLAGS   += -d
else
MODULE_EXTRA_FLAGS += -DNDEBUG -g0
#In some cases -x breaks exports
#LDFLAGS   += -s -O2 -d -x -X
LDFLAGS   += -s -O2 -d -X
endif

ifeq (0,1)
MODULE_EXTRA_FLAGS += -include drv_config.h
endif

ifeq (0,1)
    MODULE_EXTRA_FLAGS += -DUFSD_TRACE
endif

ifeq (1,0)
    MODULE_EXTRA_FLAGS += -DUFSD_NO_PRINTK
endif

ifndef CONFIG_UFSD_FS
    CONFIG_UFSD_FS = m
endif

MODULE_OBJECTS += $(MODULE_SRC)/$(MODULE_LIBNAME).bin

#KERNEL_SOURCE_DIR:=/lib/modules/3.10.17/source
#KERNEL_BUILD_DIR:=/lib/modules/3.10.17/build
#KERNEL_INSTALL_DIR:=/lib/modules/3.10.17/kernel/external/ufsd

#ARCH:=x86_64
#VERSION:=3.10
#PATCHLEVEL:=@KERNEL_PATCHLEVEL@
#MODULE_EXT:=ko

$(MODULE_NAME)-objs := $(MODULE_OBJECTS)
$(MODULE_NAME)-y := $(MODULE_OBJECTS)

ifeq (1,1)
$(MODULE_NAME2)-objs := $(MODULE_SRC)/ufsdjnl.o
$(MODULE_NAME2)-y    := $(MODULE_SRC)/ufsdjnl.o
obj-m := $(MODULE_NAME2).o $(MODULE_NAME).o
else
obj-m := $(MODULE_NAME).o
endif

## Add diagnostic module
#kdiag-objs := $(MODULE_SRC)/kdiag.o
#kdiag-y := $(MODULE_SRC)/kdiag.o
#obj-m += kdiag.o

ifeq (3.10,2.4)
O_TARGET := $(MODULE_NAME).o
obj-y := $(MODULE_OBJECTS)
endif

EXTRA_CFLAGS +=	 $(MODULE_EXTRA_FLAGS)

ifeq (3.10,2.4)
EXTRA_CFLAGS += -DNO_MM
endif


ifdef PACKAGE_TAG
EXTRA_CFLAGS += "-DPACKAGE_TAG=\"$(PACKAGE_TAG)\""
endif

ifdef EXT_MODULE_FLAGS
EXTRA_CFLAGS += $(EXT_MODULE_FLAGS)
endif


$(src)$(MODULE_SRC)/$(MODULE_LIBNAME).bin:
	@ln -s "/home/denise/Paragon-147-FRE_NTFS_Linux_9.0_Express/ifslinux/objfre/libufsd_x86_64.bin" "$(src)$(MODULE_SRC)/$(MODULE_LIBNAME).bin"

clean:
	@$(MAKE) -C "/lib/modules/3.10.17/source" SUBDIRS="/home/denise/Paragon-147-FRE_NTFS_Linux_9.0_Express" clean 2>&1 > /dev/null
	@/usr/bin/rm -Rf "$(src)$(MODULE_SRC)/$(MODULE_LIBNAME).bin"

-include $(TOPDIR)/Rules.make


$(MODULE_NAME).ko:
ifeq (3.10,2.4)
	@if [ ! -e "/lib/modules/3.10.17/source/.config" ] ; then $(MAKE) -C "/lib/modules/3.10.17/source" SUBDIRS="/home/denise/Paragon-147-FRE_NTFS_Linux_9.0_Express" V=1 cloneconfig >/dev/null 2>&1 ; true ; fi
	@if [ ! -e "/lib/modules/3.10.17/source/.config" ] ; then echo -e "\033[32mPlease run 'make menuconfig' or 'make defconfig' from kernel source dir to make config file\033[0m" ; exit -1 ; fi
endif
	$(MAKE) -C "/lib/modules/3.10.17/source" SUBDIRS="/home/denise/Paragon-147-FRE_NTFS_Linux_9.0_Express" O="/lib/modules/3.10.17/build" V=1 modules 2>&1

driver:$(MODULE_NAME).ko
	/usr/bin/strip -g --strip-unneeded ufsd.ko

ifeq (1,1)
driver_install: $(MODULE_NAME).ko
ifeq ($(shell /usr/bin/id -u),0)
	@/sbin/modprobe -qr $(MODULE_NAME) 2>&1 > /dev/null ; /sbin/modprobe -qr $(MODULE_NAME2) 2>&1 > /dev/null ; /usr/bin/mkdir -p /lib/modules/3.10.17/kernel/external/ufsd 2>&1 ; /usr/bin/cp -f $(MODULE_NAME).ko $(MODULE_NAME2).ko /lib/modules/3.10.17/kernel/external/ufsd 2>&1 && /sbin/depmod -a 2>&1 ; /sbin/modprobe $(MODULE_NAME) 2>&1
else
	@echo -e "\033[33mEnter Root password for install driver\033[0m"
	@/bin/su -c '/sbin/modprobe -qr $(MODULE_NAME) 2>&1 > /dev/null ; /sbin/modprobe -qr $(MODULE_NAME2) 2>&1 > /dev/null ; /usr/bin/mkdir -p /lib/modules/3.10.17/kernel/external/ufsd 2>&1 ; /usr/bin/cp -f $(MODULE_NAME).ko $(MODULE_NAME2).ko /lib/modules/3.10.17/kernel/external/ufsd 2>&1 && /sbin/depmod -a 2>&1 ; /sbin/modprobe $(MODULE_NAME) 2>&1'
endif

driver_uninstall:
ifeq ($(shell /usr/bin/id -u),0)
	@/sbin/modprobe -qr $(MODULE_NAME) 2>&1 ; /sbin/modprobe -qr $(MODULE_NAME2) 2>&1 > /dev/null ; /usr/bin/rm -Rf /lib/modules/3.10.17/kernel/external/ufsd 2>&1 && /sbin/depmod -a 2>&1
else
	@echo -e "\033[33mEnter Root password for uninstall driver\033[0m"
	@/bin/su -c '/sbin/modprobe -qr $(MODULE_NAME) 2>&1 ; /sbin/modprobe -qr $(MODULE_NAME2) 2>&1 > /dev/null ; /usr/bin/rm -Rf /lib/modules/3.10.17/kernel/external/ufsd 2>&1 && /sbin/depmod -a 2>&1'
endif
endif
