/* ifslinux/config.h.  Generated from config.h.in by configure.  */
/* ifslinux/config.h.in.  Generated from configure.in by autoheader.  */

/* Define to 1 if you have the declaration of `bdev_hardsect_size', and to 0
   if you don't. */
#define HAVE_DECL_BDEV_HARDSECT_SIZE 0

/* Define to 1 if you have the declaration of `bdev_physical_block_size', and
   to 0 if you don't. */
#define HAVE_DECL_BDEV_PHYSICAL_BLOCK_SIZE 1

/* int blkdev_issue_flush(struct block_device *, sector_t *); */
#define HAVE_DECL_BLKDEV_ISSUE_FLUSH_V1 0

/* int blkdev_issue_flush(struct block_device *, gfp_t, sector_t *, unsigned
   long); */
#define HAVE_DECL_BLKDEV_ISSUE_FLUSH_V2 0

/* int blkdev_issue_flush(struct block_device *, gfp_t, sector_t *); */
#define HAVE_DECL_BLKDEV_ISSUE_FLUSH_V3 1

/* Define to 1 if you have the declaration of `blkdev_issue_zeroout', and to 0
   if you don't. */
#define HAVE_DECL_BLKDEV_ISSUE_ZEROOUT 1

/* Define to 1 if you have the declaration of `blk_start_plug', and to 0 if
   you don't. */
#define HAVE_DECL_BLK_START_PLUG 1

/* ssize_t blockdev_direct_IO_no_locking(int rw, struct kiocb *iocb, struct
   inode *inode, struct block_device *bdev, const struct iovec *iov, loff_t
   offset, unsigned long nr_segs, get_block_t get_block, dio_iodone_t end_io);
   */
#define HAVE_DECL_BLOCKDEV_DIRECT_IO_V1 0

/* ssize_t blockdev_direct_IO(int rw, struct kiocb *iocb, struct inode *inode,
   const struct iovec *iov, loff_t offset, unsigned long nr_segs, get_block_t
   get_block); */
#define HAVE_DECL_BLOCKDEV_DIRECT_IO_V2 1

/* void block_invalidatepage(struct page *page, unsigned long offset); */
#define HAVE_DECL_BLOCK_INVALIDATEPAGE_V1 1

/* void block_invalidatepage(struct page *page, unsigned int offset,unsigned
   int length); */
#define HAVE_DECL_BLOCK_INVALIDATEPAGE_V2 0

/* Define to 1 if you have the declaration of `clear_inode', and to 0 if you
   don't. */
#define HAVE_DECL_CLEAR_INODE 1

/* Define to 1 if you have the declaration of `copy_page', and to 0 if you
   don't. */
#define HAVE_DECL_COPY_PAGE 1

/* Define to 1 if you have the declaration of `current_umask', and to 0 if you
   don't. */
#define HAVE_DECL_CURRENT_UMASK 1

/* int (*d_compare)(struct dentry *, struct qstr*, struct qstr*); */
#define HAVE_DECL_DCOMPARE_V1 0

/* int (*d_compare)(const struct dentry *, const struct inode *, const struct
   dentry *, const struct inode *, unsigned int, const char *, const struct
   qstr *); */
#define HAVE_DECL_DCOMPARE_V2 1

/* int (*d_compare)(const struct dentry *, const struct dentry *, unsigned
   int, const char *, const struct qstr *); */
#define HAVE_DECL_DCOMPARE_V3 0

/* int (*d_hash)(struct dentry *, int); */
#define HAVE_DECL_DHASH_V1 0

/* int (*d_hash)(const struct dentry *, const struct inode*, struct nameidata
   *); */
#define HAVE_DECL_DHASH_V2 1

/* int (*d_hash)(const struct dentry *, struct qstr *); */
#define HAVE_DECL_DHASH_V3 0

/* Define to 1 if you have the declaration of `drop_nlink', and to 0 if you
   don't. */
#define HAVE_DECL_DROP_NLINK 1

/* Define to 1 if you have the declaration of `d_make_root', and to 0 if you
   don't. */
#define HAVE_DECL_D_MAKE_ROOT 1

/* char * d_path(struct dentry *, struct vfsmount *, char *, int); */
#define HAVE_DECL_D_PATH_V1 0

/* char *d_path(const struct path *, char *, int); */
#define HAVE_DECL_D_PATH_V2 1

/* int (*encode_fh)(struct inode *inode, __u32 *fh, int *max_len, int
   connectable); */
#define HAVE_DECL_ENCODE_FH_V1 0

/* int (*encode_fh)(struct inode *inode, __u32 *fh, int *max_len, struct inode
   *parent); */
#define HAVE_DECL_ENCODE_FH_V2 1

/* Define to 1 if you have the declaration of `end_writeback', and to 0 if you
   don't. */
#define HAVE_DECL_END_WRITEBACK 0

/* Define to 1 if you have the declaration of `file_inode', and to 0 if you
   don't. */
#define HAVE_DECL_FILE_INODE 1

/* int (*fsync) (struct file *, struct dentry *, int datasync); */
#define HAVE_DECL_FO_FSYNC_V1 0

/* int (*fsync) (struct file *, int datasync); */
#define HAVE_DECL_FO_FSYNC_V2 0

/* int (*fsync) (struct file *, loff_t, loff_t, int datasync); */
#define HAVE_DECL_FO_FSYNC_V3 1

/* Define to 1 if you have the declaration of `generic_file_sendfile', and to
   0 if you don't. */
#define HAVE_DECL_GENERIC_FILE_SENDFILE 0

/* Define to 1 if you have the declaration of `generic_file_splice_read', and
   to 0 if you don't. */
#define HAVE_DECL_GENERIC_FILE_SPLICE_READ 1

/* Define to 1 if you have the declaration of `generic_file_splice_write', and
   to 0 if you don't. */
#define HAVE_DECL_GENERIC_FILE_SPLICE_WRITE 1

/* int generic_permission(struct inode *, int, int (*check_acl)(struct inode
   *, int, unsigned int)); */
#define HAVE_DECL_GENERIC_PERMISSION_V1 0

/* int generic_permission(struct inode *, int, unsigned int, int
   (*check_acl)(struct inode *, int, unsigned int)); */
#define HAVE_DECL_GENERIC_PERMISSION_V2 0

/* int generic_permission(struct inode *, int); */
#define HAVE_DECL_GENERIC_PERMISSION_V3 1

/* int generic_permission(struct inode *, int, int (*check_acl)(struct inode
   *, int)); */
#define HAVE_DECL_GENERIC_PERMISSION_V4 0

/* Define to 1 if you have the declaration of `generic_write_sync', and to 0
   if you don't. */
#define HAVE_DECL_GENERIC_WRITE_SYNC 1

/* Define to 1 if you have the declaration of `inc_nlink', and to 0 if you
   don't. */
#define HAVE_DECL_INC_NLINK 1

/* int (*create) (struct inode *,struct dentry *,int); */
#define HAVE_DECL_INOP_CREATE_V1 0

/* int (*create) (struct inode *,struct dentry *,int, struct nameidata *); */
#define HAVE_DECL_INOP_CREATE_V2 0

/* int (*create) (struct inode *,struct dentry *,umode_t,struct nameidata *);
   */
#define HAVE_DECL_INOP_CREATE_V3 0

/* int (*create) (struct inode *,struct dentry *, umode_t, bool); */
#define HAVE_DECL_INOP_CREATE_V4 1

/* struct dentry * (*lookup) (struct inode *,struct dentry *); */
#define HAVE_DECL_INOP_LOOKUP_V1 0

/* struct dentry * (*lookup) (struct inode *,struct dentry *, struct nameidata
   *); */
#define HAVE_DECL_INOP_LOOKUP_V2 0

/* struct dentry * (*lookup) (struct inode *,struct dentry *, unsigned int);
   */
#define HAVE_DECL_INOP_LOOKUP_V3 1

/* int (*permission) (struct inode *,int,struct nameidata*); */
#define HAVE_DECL_INOP_PERMISSION_V1 0

/* int (*permission) (struct inode *,int,unsigned int); */
#define HAVE_DECL_INOP_PERMISSION_V2 0

/* int (*permission) (struct inode *, int); */
#define HAVE_DECL_INOP_PERMISSION_V3 1

/* void invalidate_bdev(struct block_device *bdev); */
#define HAVE_DECL_INVALIDATE_BDEV_V1 1

/* void invalidate_bdev(struct block_device *bdev,long); */
#define HAVE_DECL_INVALIDATE_BDEV_V2 0

/* void *kmap_atomic(struct page *page, enum km_type idx); */
#define HAVE_DECL_KMAP_ATOMIC_V1 0

/* void *kmap_atomic(struct page *page); */
#define HAVE_DECL_KMAP_ATOMIC_V2 1

/* kmem_cache_t *kmem_cache_create(const char *, size_t, size_t, unsigned
   long,void (*)(void *, kmem_cache_t *, unsigned long), void (*)(void *,
   kmem_cache_t *, unsigned long)); */
#define HAVE_DECL_KMEM_CACHE_CREATE_V1 0

/* struct kmem_cache *kmem_cache_create(const char *, size_t, size_t, unsigned
   long, void (*)(void *, struct kmem_cache *, unsigned long)); */
#define HAVE_DECL_KMEM_CACHE_CREATE_V2 0

/* struct kmem_cache *kmem_cache_create(const char *, size_t, size_t, unsigned
   long, void (*)(struct kmem_cache *, void *)); */
#define HAVE_DECL_KMEM_CACHE_CREATE_V3 0

/* struct kmem_cache *kmem_cache_create(const char *, size_t, size_t, unsigned
   long, void (*)(void *)); */
#define HAVE_DECL_KMEM_CACHE_CREATE_V4 1

/* mode type is mode_t */
#define HAVE_DECL_MODE_TYPE_MODE_T 0

/* mode type is umode_t */
#define HAVE_DECL_MODE_TYPE_UMODE_T 1

/* Define to 1 if you have the declaration of `PDE_DATA', and to 0 if you
   don't. */
#define HAVE_DECL_PDE_DATA 1

/* int posix_acl_chmod(struct posix_acl **, gfp_t, umode_t); */
#define HAVE_DECL_POSIX_ACL_CHMOD_V1 1

/* int posix_acl_chmod(struct inode *, umode_t); */
#define HAVE_DECL_POSIX_ACL_CHMOD_V2 0

/* int posix_acl_create(struct posix_acl **, gfp_t, umode_t *); */
#define HAVE_DECL_POSIX_ACL_CREATE_V1 1

/* int posix_acl_create(struct inode *, umode_t *, struct posix_acl **, struct
   posix_acl **); */
#define HAVE_DECL_POSIX_ACL_CREATE_V2 0

/* Define to 1 if you have the declaration of `posix_acl_from_xattr', and to 0
   if you don't. */
#define HAVE_DECL_POSIX_ACL_FROM_XATTR 1

/* int posix_acl_to_xattr(struct user_namespace *user_ns,const struct
   posix_acl *acl, void *buffer, size_t size); */
#define HAVE_DECL_POSIX_ACL_TO_XATTR_V2 1

/* Define to 1 if you have the declaration of `proc_create_data', and to 0 if
   you don't. */
#define HAVE_DECL_PROC_CREATE_DATA 1

/* int (*readdir) (struct file *, void *, filldir_t); */
#define HAVE_DECL_READDIR_V1 1

/* int (*iterate) (struct file *, struct dir_context *); */
#define HAVE_DECL_READDIR_V2 0

/* Define to 1 if you have the declaration of `refrigerator', and to 0 if you
   don't. */
#define HAVE_DECL_REFRIGERATOR 0

/* Define to 1 if you have the declaration of `set_buffer_ordered', and to 0
   if you don't. */
#define HAVE_DECL_SET_BUFFER_ORDERED 0

/* Define to 1 if you have the declaration of `set_freezable', and to 0 if you
   don't. */
#define HAVE_DECL_SET_FREEZABLE 1

/* Define to 1 if you have the declaration of `set_nlink', and to 0 if you
   don't. */
#define HAVE_DECL_SET_NLINK 1

/* int (*show_options)(struct seq_file *, struct vfsmount *); */
#define HAVE_DECL_SO_SHOW_OPTIONS_V1 0

/* int (*show_options)(struct seq_file *, struct dentry *); */
#define HAVE_DECL_SO_SHOW_OPTIONS_V2 1

/* int (*statfs) (struct super_block *, struct statfs *); */
#define HAVE_DECL_SO_STATFS_V1 0

/* int (*statfs) (struct dentry *, struct kstatfs *); */
#define HAVE_DECL_SO_STATFS_V2 1

/* int (*write_inode) (struct inode *, int); */
#define HAVE_DECL_SO_WRITE_INODE_V2 0

/* int (*write_inode) (struct inode *, struct writeback_control *wbc); */
#define HAVE_DECL_SO_WRITE_INODE_V3 1

/* Define to 1 if you have the declaration of `tag_pages_for_writeback', and
   to 0 if you don't. */
#define HAVE_DECL_TAG_PAGES_FOR_WRITEBACK 1

/* Define to 1 if you have the declaration of `truncate_setsize', and to 0 if
   you don't. */
#define HAVE_DECL_TRUNCATE_SETSIZE 1

/* Define to 1 if you have the declaration of `try_to_writeback_inodes_sb',
   and to 0 if you don't. */
#define HAVE_DECL_TRY_TO_WRITEBACK_INODES_SB 1

/* Define to 1 if you have the declaration of `update_atime', and to 0 if you
   don't. */
#define HAVE_DECL_UPDATE_ATIME 0

/* Define to 1 if you have the declaration of `vprintk', and to 0 if you
   don't. */
#define HAVE_DECL_VPRINTK 1

/* int writeback_inodes_sb_if_idle(struct super_block *); */
#define HAVE_DECL_WRITEBACK_INODES_SB_IF_IDLE_V1 0

/* int writeback_inodes_sb_if_idle(struct super_block *, enum wb_reason
   reason); */
#define HAVE_DECL_WRITEBACK_INODES_SB_IF_IDLE_V2 0

/* Define to 1 if you have the declaration of `write_dirty_buffer', and to 0
   if you don't. */
#define HAVE_DECL_WRITE_DIRTY_BUFFER 1

/* int (*get) (struct dentry*,const char*,void*,size_t,int); */
#define HAVE_DECL_XATTR_HANDLER_V2 1

/* Define to 1 if you have the <generated/compile.h> header file. */
#define HAVE_GENERATED_COMPILE_H 1

/* Define to 1 if you have the <generated/utsrelease.h> header file. */
#define HAVE_GENERATED_UTSRELEASE_H 1

/* Define to 1 if you have the <linux/proc_ns.h> header file. */
#define HAVE_LINUX_PROC_NS_H 1

/* Define to 1 if you have the <linux/uidgid.h> header file. */
#define HAVE_LINUX_UIDGID_H 1

/* Define to 1 if `error_remove_page' is member of `struct
   address_space_operations'. */
#define HAVE_STRUCT_ADDRESS_SPACE_OPERATIONS_ERROR_REMOVE_PAGE 1

/* Define to 1 if `is_partially_uptodate' is member of `struct
   address_space_operations'. */
#define HAVE_STRUCT_ADDRESS_SPACE_OPERATIONS_IS_PARTIALLY_UPTODATE 1

/* Define to 1 if `sync_page' is member of `struct address_space_operations'.
   */
/* #undef HAVE_STRUCT_ADDRESS_SPACE_OPERATIONS_SYNC_PAGE */

/* Define to 1 if `bi_iter' is member of `struct bio'. */
/* #undef HAVE_STRUCT_BIO_BI_ITER */

/* Define to 1 if `fallocate' is member of `struct file_operations'. */
#define HAVE_STRUCT_FILE_OPERATIONS_FALLOCATE 1

/* Define to 1 if `ioctl' is member of `struct file_operations'. */
/* #undef HAVE_STRUCT_FILE_OPERATIONS_IOCTL */

/* Define to 1 if `mount' is member of `struct file_system_type'. */
#define HAVE_STRUCT_FILE_SYSTEM_TYPE_MOUNT 1

/* Define to 1 if `i_acl' is member of `struct inode'. */
#define HAVE_STRUCT_INODE_I_ACL 1

/* Define to 1 if `fallocate' is member of `struct inode_operations'. */
/* #undef HAVE_STRUCT_INODE_OPERATIONS_FALLOCATE */

/* Define to 1 if `get_acl' is member of `struct inode_operations'. */
#define HAVE_STRUCT_INODE_OPERATIONS_GET_ACL 1

/* Define to 1 if `module_core' is member of `struct module'. */
#define HAVE_STRUCT_MODULE_MODULE_CORE 1

/* Define to 1 if `module_core_rx' is member of `struct module'. */
/* #undef HAVE_STRUCT_MODULE_MODULE_CORE_RX */

/* Define to 1 if `owner' is member of `struct proc_dir_entry'. */
/* #undef HAVE_STRUCT_PROC_DIR_ENTRY_OWNER */

/* Define to 1 if `s_bdi' is member of `struct super_block'. */
#define HAVE_STRUCT_SUPER_BLOCK_S_BDI 1

/* Define to 1 if `s_d_op' is member of `struct super_block'. */
#define HAVE_STRUCT_SUPER_BLOCK_S_D_OP 1

/* Define to 1 if `evict_inode' is member of `struct super_operations'. */
#define HAVE_STRUCT_SUPER_OPERATIONS_EVICT_INODE 1

/* Define to 1 if `write_super' is member of `struct super_operations'. */
/* #undef HAVE_STRUCT_SUPER_OPERATIONS_WRITE_SUPER */

/* Define to 1 if `count' is member of `struct user_namespace'. */
#define HAVE_STRUCT_USER_NAMESPACE_COUNT 1

/* Define to 1 if `proc_inum' is member of `struct user_namespace'. */
#define HAVE_STRUCT_USER_NAMESPACE_PROC_INUM 1

/* Define to 1 if the system has the type `struct va_format'. */
#define HAVE_STRUCT_VA_FORMAT 1

/* Define to 1 if `tagged_writepages' is member of `struct writeback_control'.
   */
#define HAVE_STRUCT_WRITEBACK_CONTROL_TAGGED_WRITEPAGES 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "ufsd"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ufsd lke_9.0.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ufsd"

/* Define to the version of this package. */
#define PACKAGE_VERSION "lke_9.0.0"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* EXFAT Using flag */
/* #undef UFSD_EXFAT */

/* HFS Using flag */
#define UFSD_HFS /**/

/* NTFS Using flag */
#define UFSD_NTFS2 /**/

/* Refs Using flag */
/* #undef UFSD_REFS */
