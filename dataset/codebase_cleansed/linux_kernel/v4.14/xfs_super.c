STATIC int
suffix_kstrtoint(const substring_t *s, unsigned int base, int *res)
{
int last, shift_left_factor = 0, _res;
char *value;
int ret = 0;
value = match_strdup(s);
if (!value)
return -ENOMEM;
last = strlen(value) - 1;
if (value[last] == 'K' || value[last] == 'k') {
shift_left_factor = 10;
value[last] = '\0';
}
if (value[last] == 'M' || value[last] == 'm') {
shift_left_factor = 20;
value[last] = '\0';
}
if (value[last] == 'G' || value[last] == 'g') {
shift_left_factor = 30;
value[last] = '\0';
}
if (kstrtoint(value, base, &_res))
ret = -EINVAL;
kfree(value);
*res = _res << shift_left_factor;
return ret;
}
STATIC int
xfs_parseargs(
struct xfs_mount *mp,
char *options)
{
const struct super_block *sb = mp->m_super;
char *p;
substring_t args[MAX_OPT_ARGS];
int dsunit = 0;
int dswidth = 0;
int iosize = 0;
uint8_t iosizelog = 0;
mp->m_fsname = kstrndup(sb->s_id, MAXNAMELEN, GFP_KERNEL);
if (!mp->m_fsname)
return -ENOMEM;
mp->m_fsname_len = strlen(mp->m_fsname) + 1;
if (sb_rdonly(sb))
mp->m_flags |= XFS_MOUNT_RDONLY;
if (sb->s_flags & MS_DIRSYNC)
mp->m_flags |= XFS_MOUNT_DIRSYNC;
if (sb->s_flags & MS_SYNCHRONOUS)
mp->m_flags |= XFS_MOUNT_WSYNC;
mp->m_flags |= XFS_MOUNT_BARRIER;
mp->m_flags |= XFS_MOUNT_COMPAT_IOSIZE;
mp->m_logbufs = -1;
mp->m_logbsize = -1;
if (!options)
goto done;
while ((p = strsep(&options, ",")) != NULL) {
int token;
if (!*p)
continue;
token = match_token(p, tokens, args);
switch (token) {
case Opt_logbufs:
if (match_int(args, &mp->m_logbufs))
return -EINVAL;
break;
case Opt_logbsize:
if (suffix_kstrtoint(args, 10, &mp->m_logbsize))
return -EINVAL;
break;
case Opt_logdev:
mp->m_logname = match_strdup(args);
if (!mp->m_logname)
return -ENOMEM;
break;
case Opt_mtpt:
xfs_warn(mp, "%s option not allowed on this system", p);
return -EINVAL;
case Opt_rtdev:
mp->m_rtname = match_strdup(args);
if (!mp->m_rtname)
return -ENOMEM;
break;
case Opt_allocsize:
case Opt_biosize:
if (suffix_kstrtoint(args, 10, &iosize))
return -EINVAL;
iosizelog = ffs(iosize) - 1;
break;
case Opt_grpid:
case Opt_bsdgroups:
mp->m_flags |= XFS_MOUNT_GRPID;
break;
case Opt_nogrpid:
case Opt_sysvgroups:
mp->m_flags &= ~XFS_MOUNT_GRPID;
break;
case Opt_wsync:
mp->m_flags |= XFS_MOUNT_WSYNC;
break;
case Opt_norecovery:
mp->m_flags |= XFS_MOUNT_NORECOVERY;
break;
case Opt_noalign:
mp->m_flags |= XFS_MOUNT_NOALIGN;
break;
case Opt_swalloc:
mp->m_flags |= XFS_MOUNT_SWALLOC;
break;
case Opt_sunit:
if (match_int(args, &dsunit))
return -EINVAL;
break;
case Opt_swidth:
if (match_int(args, &dswidth))
return -EINVAL;
break;
case Opt_inode32:
mp->m_flags |= XFS_MOUNT_SMALL_INUMS;
break;
case Opt_inode64:
mp->m_flags &= ~XFS_MOUNT_SMALL_INUMS;
break;
case Opt_nouuid:
mp->m_flags |= XFS_MOUNT_NOUUID;
break;
case Opt_ikeep:
mp->m_flags |= XFS_MOUNT_IKEEP;
break;
case Opt_noikeep:
mp->m_flags &= ~XFS_MOUNT_IKEEP;
break;
case Opt_largeio:
mp->m_flags &= ~XFS_MOUNT_COMPAT_IOSIZE;
break;
case Opt_nolargeio:
mp->m_flags |= XFS_MOUNT_COMPAT_IOSIZE;
break;
case Opt_attr2:
mp->m_flags |= XFS_MOUNT_ATTR2;
break;
case Opt_noattr2:
mp->m_flags &= ~XFS_MOUNT_ATTR2;
mp->m_flags |= XFS_MOUNT_NOATTR2;
break;
case Opt_filestreams:
mp->m_flags |= XFS_MOUNT_FILESTREAMS;
break;
case Opt_noquota:
mp->m_qflags &= ~XFS_ALL_QUOTA_ACCT;
mp->m_qflags &= ~XFS_ALL_QUOTA_ENFD;
mp->m_qflags &= ~XFS_ALL_QUOTA_ACTIVE;
break;
case Opt_quota:
case Opt_uquota:
case Opt_usrquota:
mp->m_qflags |= (XFS_UQUOTA_ACCT | XFS_UQUOTA_ACTIVE |
XFS_UQUOTA_ENFD);
break;
case Opt_qnoenforce:
case Opt_uqnoenforce:
mp->m_qflags |= (XFS_UQUOTA_ACCT | XFS_UQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_UQUOTA_ENFD;
break;
case Opt_pquota:
case Opt_prjquota:
mp->m_qflags |= (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE |
XFS_PQUOTA_ENFD);
break;
case Opt_pqnoenforce:
mp->m_qflags |= (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_PQUOTA_ENFD;
break;
case Opt_gquota:
case Opt_grpquota:
mp->m_qflags |= (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE |
XFS_GQUOTA_ENFD);
break;
case Opt_gqnoenforce:
mp->m_qflags |= (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_GQUOTA_ENFD;
break;
case Opt_discard:
mp->m_flags |= XFS_MOUNT_DISCARD;
break;
case Opt_nodiscard:
mp->m_flags &= ~XFS_MOUNT_DISCARD;
break;
#ifdef CONFIG_FS_DAX
case Opt_dax:
mp->m_flags |= XFS_MOUNT_DAX;
break;
#endif
case Opt_barrier:
xfs_warn(mp, "%s option is deprecated, ignoring.", p);
mp->m_flags |= XFS_MOUNT_BARRIER;
break;
case Opt_nobarrier:
xfs_warn(mp, "%s option is deprecated, ignoring.", p);
mp->m_flags &= ~XFS_MOUNT_BARRIER;
break;
default:
xfs_warn(mp, "unknown mount option [%s].", p);
return -EINVAL;
}
}
if ((mp->m_flags & XFS_MOUNT_NORECOVERY) &&
!(mp->m_flags & XFS_MOUNT_RDONLY)) {
xfs_warn(mp, "no-recovery mounts must be read-only.");
return -EINVAL;
}
if ((mp->m_flags & XFS_MOUNT_NOALIGN) && (dsunit || dswidth)) {
xfs_warn(mp,
"sunit and swidth options incompatible with the noalign option");
return -EINVAL;
}
#ifndef CONFIG_XFS_QUOTA
if (XFS_IS_QUOTA_RUNNING(mp)) {
xfs_warn(mp, "quota support not available in this kernel.");
return -EINVAL;
}
#endif
if ((dsunit && !dswidth) || (!dsunit && dswidth)) {
xfs_warn(mp, "sunit and swidth must be specified together");
return -EINVAL;
}
if (dsunit && (dswidth % dsunit != 0)) {
xfs_warn(mp,
"stripe width (%d) must be a multiple of the stripe unit (%d)",
dswidth, dsunit);
return -EINVAL;
}
done:
if (dsunit && !(mp->m_flags & XFS_MOUNT_NOALIGN)) {
mp->m_dalign = dsunit;
mp->m_swidth = dswidth;
}
if (mp->m_logbufs != -1 &&
mp->m_logbufs != 0 &&
(mp->m_logbufs < XLOG_MIN_ICLOGS ||
mp->m_logbufs > XLOG_MAX_ICLOGS)) {
xfs_warn(mp, "invalid logbufs value: %d [not %d-%d]",
mp->m_logbufs, XLOG_MIN_ICLOGS, XLOG_MAX_ICLOGS);
return -EINVAL;
}
if (mp->m_logbsize != -1 &&
mp->m_logbsize != 0 &&
(mp->m_logbsize < XLOG_MIN_RECORD_BSIZE ||
mp->m_logbsize > XLOG_MAX_RECORD_BSIZE ||
!is_power_of_2(mp->m_logbsize))) {
xfs_warn(mp,
"invalid logbufsize: %d [not 16k,32k,64k,128k or 256k]",
mp->m_logbsize);
return -EINVAL;
}
if (iosizelog) {
if (iosizelog > XFS_MAX_IO_LOG ||
iosizelog < XFS_MIN_IO_LOG) {
xfs_warn(mp, "invalid log iosize: %d [not %d-%d]",
iosizelog, XFS_MIN_IO_LOG,
XFS_MAX_IO_LOG);
return -EINVAL;
}
mp->m_flags |= XFS_MOUNT_DFLT_IOSIZE;
mp->m_readio_log = iosizelog;
mp->m_writeio_log = iosizelog;
}
return 0;
}
STATIC int
xfs_showargs(
struct xfs_mount *mp,
struct seq_file *m)
{
static struct proc_xfs_info xfs_info_set[] = {
{ XFS_MOUNT_IKEEP, ",ikeep" },
{ XFS_MOUNT_WSYNC, ",wsync" },
{ XFS_MOUNT_NOALIGN, ",noalign" },
{ XFS_MOUNT_SWALLOC, ",swalloc" },
{ XFS_MOUNT_NOUUID, ",nouuid" },
{ XFS_MOUNT_NORECOVERY, ",norecovery" },
{ XFS_MOUNT_ATTR2, ",attr2" },
{ XFS_MOUNT_FILESTREAMS, ",filestreams" },
{ XFS_MOUNT_GRPID, ",grpid" },
{ XFS_MOUNT_DISCARD, ",discard" },
{ XFS_MOUNT_SMALL_INUMS, ",inode32" },
{ XFS_MOUNT_DAX, ",dax" },
{ 0, NULL }
};
static struct proc_xfs_info xfs_info_unset[] = {
{ XFS_MOUNT_COMPAT_IOSIZE, ",largeio" },
{ XFS_MOUNT_BARRIER, ",nobarrier" },
{ XFS_MOUNT_SMALL_INUMS, ",inode64" },
{ 0, NULL }
};
struct proc_xfs_info *xfs_infop;
for (xfs_infop = xfs_info_set; xfs_infop->flag; xfs_infop++) {
if (mp->m_flags & xfs_infop->flag)
seq_puts(m, xfs_infop->str);
}
for (xfs_infop = xfs_info_unset; xfs_infop->flag; xfs_infop++) {
if (!(mp->m_flags & xfs_infop->flag))
seq_puts(m, xfs_infop->str);
}
if (mp->m_flags & XFS_MOUNT_DFLT_IOSIZE)
seq_printf(m, ",allocsize=%dk",
(int)(1 << mp->m_writeio_log) >> 10);
if (mp->m_logbufs > 0)
seq_printf(m, ",logbufs=%d", mp->m_logbufs);
if (mp->m_logbsize > 0)
seq_printf(m, ",logbsize=%dk", mp->m_logbsize >> 10);
if (mp->m_logname)
seq_show_option(m, "logdev", mp->m_logname);
if (mp->m_rtname)
seq_show_option(m, "rtdev", mp->m_rtname);
if (mp->m_dalign > 0)
seq_printf(m, ",sunit=%d",
(int)XFS_FSB_TO_BB(mp, mp->m_dalign));
if (mp->m_swidth > 0)
seq_printf(m, ",swidth=%d",
(int)XFS_FSB_TO_BB(mp, mp->m_swidth));
if (mp->m_qflags & (XFS_UQUOTA_ACCT|XFS_UQUOTA_ENFD))
seq_puts(m, ",usrquota");
else if (mp->m_qflags & XFS_UQUOTA_ACCT)
seq_puts(m, ",uqnoenforce");
if (mp->m_qflags & XFS_PQUOTA_ACCT) {
if (mp->m_qflags & XFS_PQUOTA_ENFD)
seq_puts(m, ",prjquota");
else
seq_puts(m, ",pqnoenforce");
}
if (mp->m_qflags & XFS_GQUOTA_ACCT) {
if (mp->m_qflags & XFS_GQUOTA_ENFD)
seq_puts(m, ",grpquota");
else
seq_puts(m, ",gqnoenforce");
}
if (!(mp->m_qflags & XFS_ALL_QUOTA_ACCT))
seq_puts(m, ",noquota");
return 0;
}
static uint64_t
xfs_max_file_offset(
unsigned int blockshift)
{
unsigned int pagefactor = 1;
unsigned int bitshift = BITS_PER_LONG - 1;
#if BITS_PER_LONG == 32
# if defined(CONFIG_LBDAF)
ASSERT(sizeof(sector_t) == 8);
pagefactor = PAGE_SIZE;
bitshift = BITS_PER_LONG;
# else
pagefactor = PAGE_SIZE >> (PAGE_SHIFT - blockshift);
# endif
#endif
return (((uint64_t)pagefactor) << bitshift) - 1;
}
xfs_agnumber_t
xfs_set_inode_alloc(
struct xfs_mount *mp,
xfs_agnumber_t agcount)
{
xfs_agnumber_t index;
xfs_agnumber_t maxagi = 0;
xfs_sb_t *sbp = &mp->m_sb;
xfs_agnumber_t max_metadata;
xfs_agino_t agino;
xfs_ino_t ino;
if (mp->m_maxicount) {
uint64_t icount;
icount = sbp->sb_dblocks * sbp->sb_imax_pct;
do_div(icount, 100);
icount += sbp->sb_agblocks - 1;
do_div(icount, sbp->sb_agblocks);
max_metadata = icount;
} else {
max_metadata = agcount;
}
agino = XFS_OFFBNO_TO_AGINO(mp, sbp->sb_agblocks - 1, 0);
ino = XFS_AGINO_TO_INO(mp, agcount - 1, agino);
if ((mp->m_flags & XFS_MOUNT_SMALL_INUMS) && ino > XFS_MAXINUMBER_32)
mp->m_flags |= XFS_MOUNT_32BITINODES;
else
mp->m_flags &= ~XFS_MOUNT_32BITINODES;
for (index = 0; index < agcount; index++) {
struct xfs_perag *pag;
ino = XFS_AGINO_TO_INO(mp, index, agino);
pag = xfs_perag_get(mp, index);
if (mp->m_flags & XFS_MOUNT_32BITINODES) {
if (ino > XFS_MAXINUMBER_32) {
pag->pagi_inodeok = 0;
pag->pagf_metadata = 0;
} else {
pag->pagi_inodeok = 1;
maxagi++;
if (index < max_metadata)
pag->pagf_metadata = 1;
else
pag->pagf_metadata = 0;
}
} else {
pag->pagi_inodeok = 1;
pag->pagf_metadata = 0;
}
xfs_perag_put(pag);
}
return (mp->m_flags & XFS_MOUNT_32BITINODES) ? maxagi : agcount;
}
STATIC int
xfs_blkdev_get(
xfs_mount_t *mp,
const char *name,
struct block_device **bdevp)
{
int error = 0;
*bdevp = blkdev_get_by_path(name, FMODE_READ|FMODE_WRITE|FMODE_EXCL,
mp);
if (IS_ERR(*bdevp)) {
error = PTR_ERR(*bdevp);
xfs_warn(mp, "Invalid device [%s], error=%d", name, error);
}
return error;
}
STATIC void
xfs_blkdev_put(
struct block_device *bdev)
{
if (bdev)
blkdev_put(bdev, FMODE_READ|FMODE_WRITE|FMODE_EXCL);
}
void
xfs_blkdev_issue_flush(
xfs_buftarg_t *buftarg)
{
blkdev_issue_flush(buftarg->bt_bdev, GFP_NOFS, NULL);
}
STATIC void
xfs_close_devices(
struct xfs_mount *mp)
{
struct dax_device *dax_ddev = mp->m_ddev_targp->bt_daxdev;
if (mp->m_logdev_targp && mp->m_logdev_targp != mp->m_ddev_targp) {
struct block_device *logdev = mp->m_logdev_targp->bt_bdev;
struct dax_device *dax_logdev = mp->m_logdev_targp->bt_daxdev;
xfs_free_buftarg(mp, mp->m_logdev_targp);
xfs_blkdev_put(logdev);
fs_put_dax(dax_logdev);
}
if (mp->m_rtdev_targp) {
struct block_device *rtdev = mp->m_rtdev_targp->bt_bdev;
struct dax_device *dax_rtdev = mp->m_rtdev_targp->bt_daxdev;
xfs_free_buftarg(mp, mp->m_rtdev_targp);
xfs_blkdev_put(rtdev);
fs_put_dax(dax_rtdev);
}
xfs_free_buftarg(mp, mp->m_ddev_targp);
fs_put_dax(dax_ddev);
}
STATIC int
xfs_open_devices(
struct xfs_mount *mp)
{
struct block_device *ddev = mp->m_super->s_bdev;
struct dax_device *dax_ddev = fs_dax_get_by_bdev(ddev);
struct dax_device *dax_logdev = NULL, *dax_rtdev = NULL;
struct block_device *logdev = NULL, *rtdev = NULL;
int error;
if (mp->m_logname) {
error = xfs_blkdev_get(mp, mp->m_logname, &logdev);
if (error)
goto out;
dax_logdev = fs_dax_get_by_bdev(logdev);
}
if (mp->m_rtname) {
error = xfs_blkdev_get(mp, mp->m_rtname, &rtdev);
if (error)
goto out_close_logdev;
if (rtdev == ddev || rtdev == logdev) {
xfs_warn(mp,
"Cannot mount filesystem with identical rtdev and ddev/logdev.");
error = -EINVAL;
goto out_close_rtdev;
}
dax_rtdev = fs_dax_get_by_bdev(rtdev);
}
error = -ENOMEM;
mp->m_ddev_targp = xfs_alloc_buftarg(mp, ddev, dax_ddev);
if (!mp->m_ddev_targp)
goto out_close_rtdev;
if (rtdev) {
mp->m_rtdev_targp = xfs_alloc_buftarg(mp, rtdev, dax_rtdev);
if (!mp->m_rtdev_targp)
goto out_free_ddev_targ;
}
if (logdev && logdev != ddev) {
mp->m_logdev_targp = xfs_alloc_buftarg(mp, logdev, dax_logdev);
if (!mp->m_logdev_targp)
goto out_free_rtdev_targ;
} else {
mp->m_logdev_targp = mp->m_ddev_targp;
}
return 0;
out_free_rtdev_targ:
if (mp->m_rtdev_targp)
xfs_free_buftarg(mp, mp->m_rtdev_targp);
out_free_ddev_targ:
xfs_free_buftarg(mp, mp->m_ddev_targp);
out_close_rtdev:
xfs_blkdev_put(rtdev);
fs_put_dax(dax_rtdev);
out_close_logdev:
if (logdev && logdev != ddev) {
xfs_blkdev_put(logdev);
fs_put_dax(dax_logdev);
}
out:
fs_put_dax(dax_ddev);
return error;
}
STATIC int
xfs_setup_devices(
struct xfs_mount *mp)
{
int error;
error = xfs_setsize_buftarg(mp->m_ddev_targp, mp->m_sb.sb_sectsize);
if (error)
return error;
if (mp->m_logdev_targp && mp->m_logdev_targp != mp->m_ddev_targp) {
unsigned int log_sector_size = BBSIZE;
if (xfs_sb_version_hassector(&mp->m_sb))
log_sector_size = mp->m_sb.sb_logsectsize;
error = xfs_setsize_buftarg(mp->m_logdev_targp,
log_sector_size);
if (error)
return error;
}
if (mp->m_rtdev_targp) {
error = xfs_setsize_buftarg(mp->m_rtdev_targp,
mp->m_sb.sb_sectsize);
if (error)
return error;
}
return 0;
}
STATIC int
xfs_init_mount_workqueues(
struct xfs_mount *mp)
{
mp->m_buf_workqueue = alloc_workqueue("xfs-buf/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 1, mp->m_fsname);
if (!mp->m_buf_workqueue)
goto out;
mp->m_data_workqueue = alloc_workqueue("xfs-data/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0, mp->m_fsname);
if (!mp->m_data_workqueue)
goto out_destroy_buf;
mp->m_unwritten_workqueue = alloc_workqueue("xfs-conv/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0, mp->m_fsname);
if (!mp->m_unwritten_workqueue)
goto out_destroy_data_iodone_queue;
mp->m_cil_workqueue = alloc_workqueue("xfs-cil/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0, mp->m_fsname);
if (!mp->m_cil_workqueue)
goto out_destroy_unwritten;
mp->m_reclaim_workqueue = alloc_workqueue("xfs-reclaim/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0, mp->m_fsname);
if (!mp->m_reclaim_workqueue)
goto out_destroy_cil;
mp->m_log_workqueue = alloc_workqueue("xfs-log/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE|WQ_HIGHPRI, 0,
mp->m_fsname);
if (!mp->m_log_workqueue)
goto out_destroy_reclaim;
mp->m_eofblocks_workqueue = alloc_workqueue("xfs-eofblocks/%s",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0, mp->m_fsname);
if (!mp->m_eofblocks_workqueue)
goto out_destroy_log;
mp->m_sync_workqueue = alloc_workqueue("xfs-sync/%s", WQ_FREEZABLE, 0,
mp->m_fsname);
if (!mp->m_sync_workqueue)
goto out_destroy_eofb;
return 0;
out_destroy_eofb:
destroy_workqueue(mp->m_eofblocks_workqueue);
out_destroy_log:
destroy_workqueue(mp->m_log_workqueue);
out_destroy_reclaim:
destroy_workqueue(mp->m_reclaim_workqueue);
out_destroy_cil:
destroy_workqueue(mp->m_cil_workqueue);
out_destroy_unwritten:
destroy_workqueue(mp->m_unwritten_workqueue);
out_destroy_data_iodone_queue:
destroy_workqueue(mp->m_data_workqueue);
out_destroy_buf:
destroy_workqueue(mp->m_buf_workqueue);
out:
return -ENOMEM;
}
STATIC void
xfs_destroy_mount_workqueues(
struct xfs_mount *mp)
{
destroy_workqueue(mp->m_sync_workqueue);
destroy_workqueue(mp->m_eofblocks_workqueue);
destroy_workqueue(mp->m_log_workqueue);
destroy_workqueue(mp->m_reclaim_workqueue);
destroy_workqueue(mp->m_cil_workqueue);
destroy_workqueue(mp->m_data_workqueue);
destroy_workqueue(mp->m_unwritten_workqueue);
destroy_workqueue(mp->m_buf_workqueue);
}
void
xfs_flush_inodes(
struct xfs_mount *mp)
{
struct super_block *sb = mp->m_super;
if (down_read_trylock(&sb->s_umount)) {
sync_inodes_sb(sb);
up_read(&sb->s_umount);
}
}
STATIC struct inode *
xfs_fs_alloc_inode(
struct super_block *sb)
{
BUG();
return NULL;
}
STATIC void
xfs_fs_destroy_inode(
struct inode *inode)
{
struct xfs_inode *ip = XFS_I(inode);
int error;
trace_xfs_destroy_inode(ip);
ASSERT(!rwsem_is_locked(&inode->i_rwsem));
XFS_STATS_INC(ip->i_mount, vn_rele);
XFS_STATS_INC(ip->i_mount, vn_remove);
if (xfs_is_reflink_inode(ip)) {
error = xfs_reflink_cancel_cow_range(ip, 0, NULLFILEOFF, true);
if (error && !XFS_FORCED_SHUTDOWN(ip->i_mount))
xfs_warn(ip->i_mount,
"Error %d while evicting CoW blocks for inode %llu.",
error, ip->i_ino);
}
xfs_inactive(ip);
ASSERT(XFS_FORCED_SHUTDOWN(ip->i_mount) || ip->i_delayed_blks == 0);
XFS_STATS_INC(ip->i_mount, vn_reclaim);
ASSERT_ALWAYS(!xfs_iflags_test(ip, XFS_IRECLAIMABLE));
ASSERT_ALWAYS(!xfs_iflags_test(ip, XFS_IRECLAIM));
xfs_inode_set_reclaim_tag(ip);
}
STATIC void
xfs_fs_inode_init_once(
void *inode)
{
struct xfs_inode *ip = inode;
memset(ip, 0, sizeof(struct xfs_inode));
inode_init_once(VFS_I(ip));
atomic_set(&ip->i_pincount, 0);
spin_lock_init(&ip->i_flags_lock);
mrlock_init(&ip->i_mmaplock, MRLOCK_ALLOW_EQUAL_PRI|MRLOCK_BARRIER,
"xfsino", ip->i_ino);
mrlock_init(&ip->i_lock, MRLOCK_ALLOW_EQUAL_PRI|MRLOCK_BARRIER,
"xfsino", ip->i_ino);
}
STATIC int
xfs_fs_drop_inode(
struct inode *inode)
{
struct xfs_inode *ip = XFS_I(inode);
if (ip->i_flags & XFS_IRECOVERY) {
ASSERT(ip->i_mount->m_log->l_flags & XLOG_RECOVERY_NEEDED);
return 0;
}
return generic_drop_inode(inode) || (ip->i_flags & XFS_IDONTCACHE);
}
STATIC void
xfs_free_fsname(
struct xfs_mount *mp)
{
kfree(mp->m_fsname);
kfree(mp->m_rtname);
kfree(mp->m_logname);
}
STATIC int
xfs_fs_sync_fs(
struct super_block *sb,
int wait)
{
struct xfs_mount *mp = XFS_M(sb);
if (!wait)
return 0;
xfs_log_force(mp, XFS_LOG_SYNC);
if (laptop_mode) {
flush_delayed_work(&mp->m_log->l_work);
}
return 0;
}
STATIC int
xfs_fs_statfs(
struct dentry *dentry,
struct kstatfs *statp)
{
struct xfs_mount *mp = XFS_M(dentry->d_sb);
xfs_sb_t *sbp = &mp->m_sb;
struct xfs_inode *ip = XFS_I(d_inode(dentry));
uint64_t fakeinos, id;
uint64_t icount;
uint64_t ifree;
uint64_t fdblocks;
xfs_extlen_t lsize;
int64_t ffree;
statp->f_type = XFS_SB_MAGIC;
statp->f_namelen = MAXNAMELEN - 1;
id = huge_encode_dev(mp->m_ddev_targp->bt_dev);
statp->f_fsid.val[0] = (u32)id;
statp->f_fsid.val[1] = (u32)(id >> 32);
icount = percpu_counter_sum(&mp->m_icount);
ifree = percpu_counter_sum(&mp->m_ifree);
fdblocks = percpu_counter_sum(&mp->m_fdblocks);
spin_lock(&mp->m_sb_lock);
statp->f_bsize = sbp->sb_blocksize;
lsize = sbp->sb_logstart ? sbp->sb_logblocks : 0;
statp->f_blocks = sbp->sb_dblocks - lsize;
spin_unlock(&mp->m_sb_lock);
statp->f_bfree = fdblocks - mp->m_alloc_set_aside;
statp->f_bavail = statp->f_bfree;
fakeinos = statp->f_bfree << sbp->sb_inopblog;
statp->f_files = MIN(icount + fakeinos, (uint64_t)XFS_MAXINUMBER);
if (mp->m_maxicount)
statp->f_files = min_t(typeof(statp->f_files),
statp->f_files,
mp->m_maxicount);
statp->f_files = max_t(typeof(statp->f_files),
statp->f_files,
sbp->sb_icount);
ffree = statp->f_files - (icount - ifree);
statp->f_ffree = max_t(int64_t, ffree, 0);
if ((ip->i_d.di_flags & XFS_DIFLAG_PROJINHERIT) &&
((mp->m_qflags & (XFS_PQUOTA_ACCT|XFS_PQUOTA_ENFD))) ==
(XFS_PQUOTA_ACCT|XFS_PQUOTA_ENFD))
xfs_qm_statvfs(ip, statp);
return 0;
}
STATIC void
xfs_save_resvblks(struct xfs_mount *mp)
{
uint64_t resblks = 0;
mp->m_resblks_save = mp->m_resblks;
xfs_reserve_blocks(mp, &resblks, NULL);
}
STATIC void
xfs_restore_resvblks(struct xfs_mount *mp)
{
uint64_t resblks;
if (mp->m_resblks_save) {
resblks = mp->m_resblks_save;
mp->m_resblks_save = 0;
} else
resblks = xfs_default_resblks(mp);
xfs_reserve_blocks(mp, &resblks, NULL);
}
void
xfs_quiesce_attr(
struct xfs_mount *mp)
{
int error = 0;
while (atomic_read(&mp->m_active_trans) > 0)
delay(100);
xfs_log_force(mp, XFS_LOG_SYNC);
xfs_reclaim_inodes(mp, 0);
xfs_reclaim_inodes(mp, SYNC_WAIT);
error = xfs_log_sbcount(mp);
if (error)
xfs_warn(mp, "xfs_attr_quiesce: failed to log sb changes. "
"Frozen image may not be consistent.");
WARN_ON(atomic_read(&mp->m_active_trans) != 0);
xfs_log_quiesce(mp);
}
STATIC int
xfs_test_remount_options(
struct super_block *sb,
struct xfs_mount *mp,
char *options)
{
int error = 0;
struct xfs_mount *tmp_mp;
tmp_mp = kmem_zalloc(sizeof(*tmp_mp), KM_MAYFAIL);
if (!tmp_mp)
return -ENOMEM;
tmp_mp->m_super = sb;
error = xfs_parseargs(tmp_mp, options);
xfs_free_fsname(tmp_mp);
kmem_free(tmp_mp);
return error;
}
STATIC int
xfs_fs_remount(
struct super_block *sb,
int *flags,
char *options)
{
struct xfs_mount *mp = XFS_M(sb);
xfs_sb_t *sbp = &mp->m_sb;
substring_t args[MAX_OPT_ARGS];
char *p;
int error;
error = xfs_test_remount_options(sb, mp, options);
if (error)
return error;
sync_filesystem(sb);
while ((p = strsep(&options, ",")) != NULL) {
int token;
if (!*p)
continue;
token = match_token(p, tokens, args);
switch (token) {
case Opt_barrier:
xfs_warn(mp, "%s option is deprecated, ignoring.", p);
mp->m_flags |= XFS_MOUNT_BARRIER;
break;
case Opt_nobarrier:
xfs_warn(mp, "%s option is deprecated, ignoring.", p);
mp->m_flags &= ~XFS_MOUNT_BARRIER;
break;
case Opt_inode64:
mp->m_flags &= ~XFS_MOUNT_SMALL_INUMS;
mp->m_maxagi = xfs_set_inode_alloc(mp, sbp->sb_agcount);
break;
case Opt_inode32:
mp->m_flags |= XFS_MOUNT_SMALL_INUMS;
mp->m_maxagi = xfs_set_inode_alloc(mp, sbp->sb_agcount);
break;
default:
#if 0
xfs_info(mp,
"mount option \"%s\" not supported for remount", p);
return -EINVAL;
#else
break;
#endif
}
}
if ((mp->m_flags & XFS_MOUNT_RDONLY) && !(*flags & MS_RDONLY)) {
if (mp->m_flags & XFS_MOUNT_NORECOVERY) {
xfs_warn(mp,
"ro->rw transition prohibited on norecovery mount");
return -EINVAL;
}
if (XFS_SB_VERSION_NUM(sbp) == XFS_SB_VERSION_5 &&
xfs_sb_has_ro_compat_feature(sbp,
XFS_SB_FEAT_RO_COMPAT_UNKNOWN)) {
xfs_warn(mp,
"ro->rw transition prohibited on unknown (0x%x) ro-compat filesystem",
(sbp->sb_features_ro_compat &
XFS_SB_FEAT_RO_COMPAT_UNKNOWN));
return -EINVAL;
}
mp->m_flags &= ~XFS_MOUNT_RDONLY;
if (mp->m_update_sb) {
error = xfs_sync_sb(mp, false);
if (error) {
xfs_warn(mp, "failed to write sb changes");
return error;
}
mp->m_update_sb = false;
}
xfs_restore_resvblks(mp);
xfs_log_work_queue(mp);
xfs_queue_eofblocks(mp);
error = xfs_reflink_recover_cow(mp);
if (error) {
xfs_err(mp,
"Error %d recovering leftover CoW allocations.", error);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
return error;
}
error = xfs_fs_reserve_ag_blocks(mp);
if (error && error != -ENOSPC)
return error;
}
if (!(mp->m_flags & XFS_MOUNT_RDONLY) && (*flags & MS_RDONLY)) {
error = xfs_fs_unreserve_ag_blocks(mp);
if (error) {
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
return error;
}
xfs_save_resvblks(mp);
cancel_delayed_work_sync(&mp->m_eofblocks_work);
xfs_quiesce_attr(mp);
mp->m_flags |= XFS_MOUNT_RDONLY;
}
return 0;
}
STATIC int
xfs_fs_freeze(
struct super_block *sb)
{
struct xfs_mount *mp = XFS_M(sb);
xfs_save_resvblks(mp);
xfs_quiesce_attr(mp);
return xfs_sync_sb(mp, true);
}
STATIC int
xfs_fs_unfreeze(
struct super_block *sb)
{
struct xfs_mount *mp = XFS_M(sb);
xfs_restore_resvblks(mp);
xfs_log_work_queue(mp);
return 0;
}
STATIC int
xfs_fs_show_options(
struct seq_file *m,
struct dentry *root)
{
return xfs_showargs(XFS_M(root->d_sb), m);
}
STATIC int
xfs_finish_flags(
struct xfs_mount *mp)
{
int ronly = (mp->m_flags & XFS_MOUNT_RDONLY);
if (xfs_sb_version_haslogv2(&mp->m_sb)) {
if (mp->m_logbsize <= 0 &&
mp->m_sb.sb_logsunit > XLOG_BIG_RECORD_BSIZE) {
mp->m_logbsize = mp->m_sb.sb_logsunit;
} else if (mp->m_logbsize > 0 &&
mp->m_logbsize < mp->m_sb.sb_logsunit) {
xfs_warn(mp,
"logbuf size must be greater than or equal to log stripe size");
return -EINVAL;
}
} else {
if (mp->m_logbsize > XLOG_BIG_RECORD_BSIZE) {
xfs_warn(mp,
"logbuf size for version 1 logs must be 16K or 32K");
return -EINVAL;
}
}
if (xfs_sb_version_hascrc(&mp->m_sb) &&
(mp->m_flags & XFS_MOUNT_NOATTR2)) {
xfs_warn(mp, "Cannot mount a V5 filesystem as noattr2. "
"attr2 is always enabled for V5 filesystems.");
return -EINVAL;
}
if (xfs_sb_version_hasattr2(&mp->m_sb) &&
!(mp->m_flags & XFS_MOUNT_NOATTR2))
mp->m_flags |= XFS_MOUNT_ATTR2;
if ((mp->m_sb.sb_flags & XFS_SBF_READONLY) && !ronly) {
xfs_warn(mp,
"cannot mount a read-only filesystem as read-write");
return -EROFS;
}
if ((mp->m_qflags & (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE)) &&
(mp->m_qflags & (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE)) &&
!xfs_sb_version_has_pquotino(&mp->m_sb)) {
xfs_warn(mp,
"Super block does not support project and group quota together");
return -EINVAL;
}
return 0;
}
static int
xfs_init_percpu_counters(
struct xfs_mount *mp)
{
int error;
error = percpu_counter_init(&mp->m_icount, 0, GFP_KERNEL);
if (error)
return -ENOMEM;
error = percpu_counter_init(&mp->m_ifree, 0, GFP_KERNEL);
if (error)
goto free_icount;
error = percpu_counter_init(&mp->m_fdblocks, 0, GFP_KERNEL);
if (error)
goto free_ifree;
return 0;
free_ifree:
percpu_counter_destroy(&mp->m_ifree);
free_icount:
percpu_counter_destroy(&mp->m_icount);
return -ENOMEM;
}
void
xfs_reinit_percpu_counters(
struct xfs_mount *mp)
{
percpu_counter_set(&mp->m_icount, mp->m_sb.sb_icount);
percpu_counter_set(&mp->m_ifree, mp->m_sb.sb_ifree);
percpu_counter_set(&mp->m_fdblocks, mp->m_sb.sb_fdblocks);
}
static void
xfs_destroy_percpu_counters(
struct xfs_mount *mp)
{
percpu_counter_destroy(&mp->m_icount);
percpu_counter_destroy(&mp->m_ifree);
percpu_counter_destroy(&mp->m_fdblocks);
}
STATIC int
xfs_fs_fill_super(
struct super_block *sb,
void *data,
int silent)
{
struct inode *root;
struct xfs_mount *mp = NULL;
int flags = 0, error = -ENOMEM;
mp = kzalloc(sizeof(struct xfs_mount), GFP_KERNEL);
if (!mp)
goto out;
spin_lock_init(&mp->m_sb_lock);
mutex_init(&mp->m_growlock);
atomic_set(&mp->m_active_trans, 0);
INIT_DELAYED_WORK(&mp->m_reclaim_work, xfs_reclaim_worker);
INIT_DELAYED_WORK(&mp->m_eofblocks_work, xfs_eofblocks_worker);
INIT_DELAYED_WORK(&mp->m_cowblocks_work, xfs_cowblocks_worker);
mp->m_kobj.kobject.kset = xfs_kset;
mp->m_super = sb;
sb->s_fs_info = mp;
error = xfs_parseargs(mp, (char *)data);
if (error)
goto out_free_fsname;
sb_min_blocksize(sb, BBSIZE);
sb->s_xattr = xfs_xattr_handlers;
sb->s_export_op = &xfs_export_operations;
#ifdef CONFIG_XFS_QUOTA
sb->s_qcop = &xfs_quotactl_operations;
sb->s_quota_types = QTYPE_MASK_USR | QTYPE_MASK_GRP | QTYPE_MASK_PRJ;
#endif
sb->s_op = &xfs_super_operations;
if (silent)
flags |= XFS_MFSI_QUIET;
error = xfs_open_devices(mp);
if (error)
goto out_free_fsname;
error = xfs_init_mount_workqueues(mp);
if (error)
goto out_close_devices;
error = xfs_init_percpu_counters(mp);
if (error)
goto out_destroy_workqueues;
mp->m_stats.xs_stats = alloc_percpu(struct xfsstats);
if (!mp->m_stats.xs_stats) {
error = -ENOMEM;
goto out_destroy_counters;
}
error = xfs_readsb(mp, flags);
if (error)
goto out_free_stats;
error = xfs_finish_flags(mp);
if (error)
goto out_free_sb;
error = xfs_setup_devices(mp);
if (error)
goto out_free_sb;
error = xfs_filestream_mount(mp);
if (error)
goto out_free_sb;
sb->s_magic = XFS_SB_MAGIC;
sb->s_blocksize = mp->m_sb.sb_blocksize;
sb->s_blocksize_bits = ffs(sb->s_blocksize) - 1;
sb->s_maxbytes = xfs_max_file_offset(sb->s_blocksize_bits);
sb->s_max_links = XFS_MAXLINK;
sb->s_time_gran = 1;
set_posix_acl_flag(sb);
if (XFS_SB_VERSION_NUM(&mp->m_sb) == XFS_SB_VERSION_5)
sb->s_flags |= SB_I_VERSION;
if (mp->m_flags & XFS_MOUNT_DAX) {
xfs_warn(mp,
"DAX enabled. Warning: EXPERIMENTAL, use at your own risk");
error = bdev_dax_supported(sb, sb->s_blocksize);
if (error) {
xfs_alert(mp,
"DAX unsupported by block device. Turning off DAX.");
mp->m_flags &= ~XFS_MOUNT_DAX;
}
if (xfs_sb_version_hasreflink(&mp->m_sb))
xfs_alert(mp,
"DAX and reflink have not been tested together!");
}
if (mp->m_flags & XFS_MOUNT_DISCARD) {
struct request_queue *q = bdev_get_queue(sb->s_bdev);
if (!blk_queue_discard(q)) {
xfs_warn(mp, "mounting with \"discard\" option, but "
"the device does not support discard");
mp->m_flags &= ~XFS_MOUNT_DISCARD;
}
}
if (xfs_sb_version_hasrmapbt(&mp->m_sb)) {
if (mp->m_sb.sb_rblocks) {
xfs_alert(mp,
"EXPERIMENTAL reverse mapping btree not compatible with realtime device!");
error = -EINVAL;
goto out_filestream_unmount;
}
xfs_alert(mp,
"EXPERIMENTAL reverse mapping btree feature enabled. Use at your own risk!");
}
if (xfs_sb_version_hasreflink(&mp->m_sb))
xfs_alert(mp,
"EXPERIMENTAL reflink feature enabled. Use at your own risk!");
error = xfs_mountfs(mp);
if (error)
goto out_filestream_unmount;
root = igrab(VFS_I(mp->m_rootip));
if (!root) {
error = -ENOENT;
goto out_unmount;
}
sb->s_root = d_make_root(root);
if (!sb->s_root) {
error = -ENOMEM;
goto out_unmount;
}
return 0;
out_filestream_unmount:
xfs_filestream_unmount(mp);
out_free_sb:
xfs_freesb(mp);
out_free_stats:
free_percpu(mp->m_stats.xs_stats);
out_destroy_counters:
xfs_destroy_percpu_counters(mp);
out_destroy_workqueues:
xfs_destroy_mount_workqueues(mp);
out_close_devices:
xfs_close_devices(mp);
out_free_fsname:
xfs_free_fsname(mp);
kfree(mp);
out:
return error;
out_unmount:
xfs_filestream_unmount(mp);
xfs_unmountfs(mp);
goto out_free_sb;
}
STATIC void
xfs_fs_put_super(
struct super_block *sb)
{
struct xfs_mount *mp = XFS_M(sb);
xfs_notice(mp, "Unmounting Filesystem");
xfs_filestream_unmount(mp);
xfs_unmountfs(mp);
xfs_freesb(mp);
free_percpu(mp->m_stats.xs_stats);
xfs_destroy_percpu_counters(mp);
xfs_destroy_mount_workqueues(mp);
xfs_close_devices(mp);
xfs_free_fsname(mp);
kfree(mp);
}
STATIC struct dentry *
xfs_fs_mount(
struct file_system_type *fs_type,
int flags,
const char *dev_name,
void *data)
{
return mount_bdev(fs_type, flags, dev_name, data, xfs_fs_fill_super);
}
static long
xfs_fs_nr_cached_objects(
struct super_block *sb,
struct shrink_control *sc)
{
return xfs_reclaim_inodes_count(XFS_M(sb));
}
static long
xfs_fs_free_cached_objects(
struct super_block *sb,
struct shrink_control *sc)
{
return xfs_reclaim_inodes_nr(XFS_M(sb), sc->nr_to_scan);
}
STATIC int __init
xfs_init_zones(void)
{
xfs_ioend_bioset = bioset_create(4 * MAX_BUF_PER_PAGE,
offsetof(struct xfs_ioend, io_inline_bio),
BIOSET_NEED_BVECS);
if (!xfs_ioend_bioset)
goto out;
xfs_log_ticket_zone = kmem_zone_init(sizeof(xlog_ticket_t),
"xfs_log_ticket");
if (!xfs_log_ticket_zone)
goto out_free_ioend_bioset;
xfs_bmap_free_item_zone = kmem_zone_init(
sizeof(struct xfs_extent_free_item),
"xfs_bmap_free_item");
if (!xfs_bmap_free_item_zone)
goto out_destroy_log_ticket_zone;
xfs_btree_cur_zone = kmem_zone_init(sizeof(xfs_btree_cur_t),
"xfs_btree_cur");
if (!xfs_btree_cur_zone)
goto out_destroy_bmap_free_item_zone;
xfs_da_state_zone = kmem_zone_init(sizeof(xfs_da_state_t),
"xfs_da_state");
if (!xfs_da_state_zone)
goto out_destroy_btree_cur_zone;
xfs_ifork_zone = kmem_zone_init(sizeof(xfs_ifork_t), "xfs_ifork");
if (!xfs_ifork_zone)
goto out_destroy_da_state_zone;
xfs_trans_zone = kmem_zone_init(sizeof(xfs_trans_t), "xfs_trans");
if (!xfs_trans_zone)
goto out_destroy_ifork_zone;
xfs_log_item_desc_zone =
kmem_zone_init(sizeof(struct xfs_log_item_desc),
"xfs_log_item_desc");
if (!xfs_log_item_desc_zone)
goto out_destroy_trans_zone;
xfs_buf_item_zone = kmem_zone_init(sizeof(struct xfs_buf_log_item),
"xfs_buf_item");
if (!xfs_buf_item_zone)
goto out_destroy_log_item_desc_zone;
xfs_efd_zone = kmem_zone_init((sizeof(xfs_efd_log_item_t) +
((XFS_EFD_MAX_FAST_EXTENTS - 1) *
sizeof(xfs_extent_t))), "xfs_efd_item");
if (!xfs_efd_zone)
goto out_destroy_buf_item_zone;
xfs_efi_zone = kmem_zone_init((sizeof(xfs_efi_log_item_t) +
((XFS_EFI_MAX_FAST_EXTENTS - 1) *
sizeof(xfs_extent_t))), "xfs_efi_item");
if (!xfs_efi_zone)
goto out_destroy_efd_zone;
xfs_inode_zone =
kmem_zone_init_flags(sizeof(xfs_inode_t), "xfs_inode",
KM_ZONE_HWALIGN | KM_ZONE_RECLAIM | KM_ZONE_SPREAD |
KM_ZONE_ACCOUNT, xfs_fs_inode_init_once);
if (!xfs_inode_zone)
goto out_destroy_efi_zone;
xfs_ili_zone =
kmem_zone_init_flags(sizeof(xfs_inode_log_item_t), "xfs_ili",
KM_ZONE_SPREAD, NULL);
if (!xfs_ili_zone)
goto out_destroy_inode_zone;
xfs_icreate_zone = kmem_zone_init(sizeof(struct xfs_icreate_item),
"xfs_icr");
if (!xfs_icreate_zone)
goto out_destroy_ili_zone;
xfs_rud_zone = kmem_zone_init(sizeof(struct xfs_rud_log_item),
"xfs_rud_item");
if (!xfs_rud_zone)
goto out_destroy_icreate_zone;
xfs_rui_zone = kmem_zone_init(
xfs_rui_log_item_sizeof(XFS_RUI_MAX_FAST_EXTENTS),
"xfs_rui_item");
if (!xfs_rui_zone)
goto out_destroy_rud_zone;
xfs_cud_zone = kmem_zone_init(sizeof(struct xfs_cud_log_item),
"xfs_cud_item");
if (!xfs_cud_zone)
goto out_destroy_rui_zone;
xfs_cui_zone = kmem_zone_init(
xfs_cui_log_item_sizeof(XFS_CUI_MAX_FAST_EXTENTS),
"xfs_cui_item");
if (!xfs_cui_zone)
goto out_destroy_cud_zone;
xfs_bud_zone = kmem_zone_init(sizeof(struct xfs_bud_log_item),
"xfs_bud_item");
if (!xfs_bud_zone)
goto out_destroy_cui_zone;
xfs_bui_zone = kmem_zone_init(
xfs_bui_log_item_sizeof(XFS_BUI_MAX_FAST_EXTENTS),
"xfs_bui_item");
if (!xfs_bui_zone)
goto out_destroy_bud_zone;
return 0;
out_destroy_bud_zone:
kmem_zone_destroy(xfs_bud_zone);
out_destroy_cui_zone:
kmem_zone_destroy(xfs_cui_zone);
out_destroy_cud_zone:
kmem_zone_destroy(xfs_cud_zone);
out_destroy_rui_zone:
kmem_zone_destroy(xfs_rui_zone);
out_destroy_rud_zone:
kmem_zone_destroy(xfs_rud_zone);
out_destroy_icreate_zone:
kmem_zone_destroy(xfs_icreate_zone);
out_destroy_ili_zone:
kmem_zone_destroy(xfs_ili_zone);
out_destroy_inode_zone:
kmem_zone_destroy(xfs_inode_zone);
out_destroy_efi_zone:
kmem_zone_destroy(xfs_efi_zone);
out_destroy_efd_zone:
kmem_zone_destroy(xfs_efd_zone);
out_destroy_buf_item_zone:
kmem_zone_destroy(xfs_buf_item_zone);
out_destroy_log_item_desc_zone:
kmem_zone_destroy(xfs_log_item_desc_zone);
out_destroy_trans_zone:
kmem_zone_destroy(xfs_trans_zone);
out_destroy_ifork_zone:
kmem_zone_destroy(xfs_ifork_zone);
out_destroy_da_state_zone:
kmem_zone_destroy(xfs_da_state_zone);
out_destroy_btree_cur_zone:
kmem_zone_destroy(xfs_btree_cur_zone);
out_destroy_bmap_free_item_zone:
kmem_zone_destroy(xfs_bmap_free_item_zone);
out_destroy_log_ticket_zone:
kmem_zone_destroy(xfs_log_ticket_zone);
out_free_ioend_bioset:
bioset_free(xfs_ioend_bioset);
out:
return -ENOMEM;
}
STATIC void
xfs_destroy_zones(void)
{
rcu_barrier();
kmem_zone_destroy(xfs_bui_zone);
kmem_zone_destroy(xfs_bud_zone);
kmem_zone_destroy(xfs_cui_zone);
kmem_zone_destroy(xfs_cud_zone);
kmem_zone_destroy(xfs_rui_zone);
kmem_zone_destroy(xfs_rud_zone);
kmem_zone_destroy(xfs_icreate_zone);
kmem_zone_destroy(xfs_ili_zone);
kmem_zone_destroy(xfs_inode_zone);
kmem_zone_destroy(xfs_efi_zone);
kmem_zone_destroy(xfs_efd_zone);
kmem_zone_destroy(xfs_buf_item_zone);
kmem_zone_destroy(xfs_log_item_desc_zone);
kmem_zone_destroy(xfs_trans_zone);
kmem_zone_destroy(xfs_ifork_zone);
kmem_zone_destroy(xfs_da_state_zone);
kmem_zone_destroy(xfs_btree_cur_zone);
kmem_zone_destroy(xfs_bmap_free_item_zone);
kmem_zone_destroy(xfs_log_ticket_zone);
bioset_free(xfs_ioend_bioset);
}
STATIC int __init
xfs_init_workqueues(void)
{
xfs_alloc_wq = alloc_workqueue("xfsalloc",
WQ_MEM_RECLAIM|WQ_FREEZABLE, 0);
if (!xfs_alloc_wq)
return -ENOMEM;
xfs_discard_wq = alloc_workqueue("xfsdiscard", WQ_UNBOUND, 0);
if (!xfs_discard_wq)
goto out_free_alloc_wq;
return 0;
out_free_alloc_wq:
destroy_workqueue(xfs_alloc_wq);
return -ENOMEM;
}
STATIC void
xfs_destroy_workqueues(void)
{
destroy_workqueue(xfs_discard_wq);
destroy_workqueue(xfs_alloc_wq);
}
STATIC int __init
init_xfs_fs(void)
{
int error;
xfs_check_ondisk_structs();
printk(KERN_INFO XFS_VERSION_STRING " with "
XFS_BUILD_OPTIONS " enabled\n");
xfs_extent_free_init_defer_op();
xfs_rmap_update_init_defer_op();
xfs_refcount_update_init_defer_op();
xfs_bmap_update_init_defer_op();
xfs_dir_startup();
error = xfs_init_zones();
if (error)
goto out;
error = xfs_init_workqueues();
if (error)
goto out_destroy_zones;
error = xfs_mru_cache_init();
if (error)
goto out_destroy_wq;
error = xfs_buf_init();
if (error)
goto out_mru_cache_uninit;
error = xfs_init_procfs();
if (error)
goto out_buf_terminate;
error = xfs_sysctl_register();
if (error)
goto out_cleanup_procfs;
xfs_kset = kset_create_and_add("xfs", NULL, fs_kobj);
if (!xfs_kset) {
error = -ENOMEM;
goto out_sysctl_unregister;
}
xfsstats.xs_kobj.kobject.kset = xfs_kset;
xfsstats.xs_stats = alloc_percpu(struct xfsstats);
if (!xfsstats.xs_stats) {
error = -ENOMEM;
goto out_kset_unregister;
}
error = xfs_sysfs_init(&xfsstats.xs_kobj, &xfs_stats_ktype, NULL,
"stats");
if (error)
goto out_free_stats;
#ifdef DEBUG
xfs_dbg_kobj.kobject.kset = xfs_kset;
error = xfs_sysfs_init(&xfs_dbg_kobj, &xfs_dbg_ktype, NULL, "debug");
if (error)
goto out_remove_stats_kobj;
#endif
error = xfs_qm_init();
if (error)
goto out_remove_dbg_kobj;
error = register_filesystem(&xfs_fs_type);
if (error)
goto out_qm_exit;
return 0;
out_qm_exit:
xfs_qm_exit();
out_remove_dbg_kobj:
#ifdef DEBUG
xfs_sysfs_del(&xfs_dbg_kobj);
out_remove_stats_kobj:
#endif
xfs_sysfs_del(&xfsstats.xs_kobj);
out_free_stats:
free_percpu(xfsstats.xs_stats);
out_kset_unregister:
kset_unregister(xfs_kset);
out_sysctl_unregister:
xfs_sysctl_unregister();
out_cleanup_procfs:
xfs_cleanup_procfs();
out_buf_terminate:
xfs_buf_terminate();
out_mru_cache_uninit:
xfs_mru_cache_uninit();
out_destroy_wq:
xfs_destroy_workqueues();
out_destroy_zones:
xfs_destroy_zones();
out:
return error;
}
STATIC void __exit
exit_xfs_fs(void)
{
xfs_qm_exit();
unregister_filesystem(&xfs_fs_type);
#ifdef DEBUG
xfs_sysfs_del(&xfs_dbg_kobj);
#endif
xfs_sysfs_del(&xfsstats.xs_kobj);
free_percpu(xfsstats.xs_stats);
kset_unregister(xfs_kset);
xfs_sysctl_unregister();
xfs_cleanup_procfs();
xfs_buf_terminate();
xfs_mru_cache_uninit();
xfs_destroy_workqueues();
xfs_destroy_zones();
xfs_uuid_table_free();
}
