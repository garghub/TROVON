STATIC unsigned long
suffix_kstrtoint(char *s, unsigned int base, int *res)
{
int last, shift_left_factor = 0, _res;
char *value = s;
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
if (kstrtoint(s, base, &_res))
return -EINVAL;
*res = _res << shift_left_factor;
return 0;
}
STATIC int
xfs_parseargs(
struct xfs_mount *mp,
char *options)
{
struct super_block *sb = mp->m_super;
char *this_char, *value;
int dsunit = 0;
int dswidth = 0;
int iosize = 0;
__uint8_t iosizelog = 0;
mp->m_fsname = kstrndup(sb->s_id, MAXNAMELEN, GFP_KERNEL);
if (!mp->m_fsname)
return ENOMEM;
mp->m_fsname_len = strlen(mp->m_fsname) + 1;
if (sb->s_flags & MS_RDONLY)
mp->m_flags |= XFS_MOUNT_RDONLY;
if (sb->s_flags & MS_DIRSYNC)
mp->m_flags |= XFS_MOUNT_DIRSYNC;
if (sb->s_flags & MS_SYNCHRONOUS)
mp->m_flags |= XFS_MOUNT_WSYNC;
mp->m_flags |= XFS_MOUNT_BARRIER;
mp->m_flags |= XFS_MOUNT_COMPAT_IOSIZE;
#if !XFS_BIG_INUMS
mp->m_flags |= XFS_MOUNT_SMALL_INUMS;
#endif
mp->m_logbufs = -1;
mp->m_logbsize = -1;
if (!options)
goto done;
while ((this_char = strsep(&options, ",")) != NULL) {
if (!*this_char)
continue;
if ((value = strchr(this_char, '=')) != NULL)
*value++ = 0;
if (!strcmp(this_char, MNTOPT_LOGBUFS)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (kstrtoint(value, 10, &mp->m_logbufs))
return EINVAL;
} else if (!strcmp(this_char, MNTOPT_LOGBSIZE)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (suffix_kstrtoint(value, 10, &mp->m_logbsize))
return EINVAL;
} else if (!strcmp(this_char, MNTOPT_LOGDEV)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
mp->m_logname = kstrndup(value, MAXNAMELEN, GFP_KERNEL);
if (!mp->m_logname)
return ENOMEM;
} else if (!strcmp(this_char, MNTOPT_MTPT)) {
xfs_warn(mp, "%s option not allowed on this system",
this_char);
return EINVAL;
} else if (!strcmp(this_char, MNTOPT_RTDEV)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
mp->m_rtname = kstrndup(value, MAXNAMELEN, GFP_KERNEL);
if (!mp->m_rtname)
return ENOMEM;
} else if (!strcmp(this_char, MNTOPT_BIOSIZE)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (kstrtoint(value, 10, &iosize))
return EINVAL;
iosizelog = ffs(iosize) - 1;
} else if (!strcmp(this_char, MNTOPT_ALLOCSIZE)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (suffix_kstrtoint(value, 10, &iosize))
return EINVAL;
iosizelog = ffs(iosize) - 1;
} else if (!strcmp(this_char, MNTOPT_GRPID) ||
!strcmp(this_char, MNTOPT_BSDGROUPS)) {
mp->m_flags |= XFS_MOUNT_GRPID;
} else if (!strcmp(this_char, MNTOPT_NOGRPID) ||
!strcmp(this_char, MNTOPT_SYSVGROUPS)) {
mp->m_flags &= ~XFS_MOUNT_GRPID;
} else if (!strcmp(this_char, MNTOPT_WSYNC)) {
mp->m_flags |= XFS_MOUNT_WSYNC;
} else if (!strcmp(this_char, MNTOPT_NORECOVERY)) {
mp->m_flags |= XFS_MOUNT_NORECOVERY;
} else if (!strcmp(this_char, MNTOPT_NOALIGN)) {
mp->m_flags |= XFS_MOUNT_NOALIGN;
} else if (!strcmp(this_char, MNTOPT_SWALLOC)) {
mp->m_flags |= XFS_MOUNT_SWALLOC;
} else if (!strcmp(this_char, MNTOPT_SUNIT)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (kstrtoint(value, 10, &dsunit))
return EINVAL;
} else if (!strcmp(this_char, MNTOPT_SWIDTH)) {
if (!value || !*value) {
xfs_warn(mp, "%s option requires an argument",
this_char);
return EINVAL;
}
if (kstrtoint(value, 10, &dswidth))
return EINVAL;
} else if (!strcmp(this_char, MNTOPT_32BITINODE)) {
mp->m_flags |= XFS_MOUNT_SMALL_INUMS;
} else if (!strcmp(this_char, MNTOPT_64BITINODE)) {
mp->m_flags &= ~XFS_MOUNT_SMALL_INUMS;
#if !XFS_BIG_INUMS
xfs_warn(mp, "%s option not allowed on this system",
this_char);
return EINVAL;
#endif
} else if (!strcmp(this_char, MNTOPT_NOUUID)) {
mp->m_flags |= XFS_MOUNT_NOUUID;
} else if (!strcmp(this_char, MNTOPT_BARRIER)) {
mp->m_flags |= XFS_MOUNT_BARRIER;
} else if (!strcmp(this_char, MNTOPT_NOBARRIER)) {
mp->m_flags &= ~XFS_MOUNT_BARRIER;
} else if (!strcmp(this_char, MNTOPT_IKEEP)) {
mp->m_flags |= XFS_MOUNT_IKEEP;
} else if (!strcmp(this_char, MNTOPT_NOIKEEP)) {
mp->m_flags &= ~XFS_MOUNT_IKEEP;
} else if (!strcmp(this_char, MNTOPT_LARGEIO)) {
mp->m_flags &= ~XFS_MOUNT_COMPAT_IOSIZE;
} else if (!strcmp(this_char, MNTOPT_NOLARGEIO)) {
mp->m_flags |= XFS_MOUNT_COMPAT_IOSIZE;
} else if (!strcmp(this_char, MNTOPT_ATTR2)) {
mp->m_flags |= XFS_MOUNT_ATTR2;
} else if (!strcmp(this_char, MNTOPT_NOATTR2)) {
mp->m_flags &= ~XFS_MOUNT_ATTR2;
mp->m_flags |= XFS_MOUNT_NOATTR2;
} else if (!strcmp(this_char, MNTOPT_FILESTREAM)) {
mp->m_flags |= XFS_MOUNT_FILESTREAMS;
} else if (!strcmp(this_char, MNTOPT_NOQUOTA)) {
mp->m_qflags &= ~XFS_ALL_QUOTA_ACCT;
mp->m_qflags &= ~XFS_ALL_QUOTA_ENFD;
mp->m_qflags &= ~XFS_ALL_QUOTA_ACTIVE;
} else if (!strcmp(this_char, MNTOPT_QUOTA) ||
!strcmp(this_char, MNTOPT_UQUOTA) ||
!strcmp(this_char, MNTOPT_USRQUOTA)) {
mp->m_qflags |= (XFS_UQUOTA_ACCT | XFS_UQUOTA_ACTIVE |
XFS_UQUOTA_ENFD);
} else if (!strcmp(this_char, MNTOPT_QUOTANOENF) ||
!strcmp(this_char, MNTOPT_UQUOTANOENF)) {
mp->m_qflags |= (XFS_UQUOTA_ACCT | XFS_UQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_UQUOTA_ENFD;
} else if (!strcmp(this_char, MNTOPT_PQUOTA) ||
!strcmp(this_char, MNTOPT_PRJQUOTA)) {
mp->m_qflags |= (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE |
XFS_OQUOTA_ENFD);
} else if (!strcmp(this_char, MNTOPT_PQUOTANOENF)) {
mp->m_qflags |= (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_OQUOTA_ENFD;
} else if (!strcmp(this_char, MNTOPT_GQUOTA) ||
!strcmp(this_char, MNTOPT_GRPQUOTA)) {
mp->m_qflags |= (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE |
XFS_OQUOTA_ENFD);
} else if (!strcmp(this_char, MNTOPT_GQUOTANOENF)) {
mp->m_qflags |= (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE);
mp->m_qflags &= ~XFS_OQUOTA_ENFD;
} else if (!strcmp(this_char, MNTOPT_DELAYLOG)) {
xfs_warn(mp,
"delaylog is the default now, option is deprecated.");
} else if (!strcmp(this_char, MNTOPT_NODELAYLOG)) {
xfs_warn(mp,
"nodelaylog support has been removed, option is deprecated.");
} else if (!strcmp(this_char, MNTOPT_DISCARD)) {
mp->m_flags |= XFS_MOUNT_DISCARD;
} else if (!strcmp(this_char, MNTOPT_NODISCARD)) {
mp->m_flags &= ~XFS_MOUNT_DISCARD;
} else if (!strcmp(this_char, "ihashsize")) {
xfs_warn(mp,
"ihashsize no longer used, option is deprecated.");
} else if (!strcmp(this_char, "osyncisdsync")) {
xfs_warn(mp,
"osyncisdsync has no effect, option is deprecated.");
} else if (!strcmp(this_char, "osyncisosync")) {
xfs_warn(mp,
"osyncisosync has no effect, option is deprecated.");
} else if (!strcmp(this_char, "irixsgid")) {
xfs_warn(mp,
"irixsgid is now a sysctl(2) variable, option is deprecated.");
} else {
xfs_warn(mp, "unknown mount option [%s].", this_char);
return EINVAL;
}
}
if ((mp->m_flags & XFS_MOUNT_NORECOVERY) &&
!(mp->m_flags & XFS_MOUNT_RDONLY)) {
xfs_warn(mp, "no-recovery mounts must be read-only.");
return EINVAL;
}
if ((mp->m_flags & XFS_MOUNT_NOALIGN) && (dsunit || dswidth)) {
xfs_warn(mp,
"sunit and swidth options incompatible with the noalign option");
return EINVAL;
}
#ifndef CONFIG_XFS_QUOTA
if (XFS_IS_QUOTA_RUNNING(mp)) {
xfs_warn(mp, "quota support not available in this kernel.");
return EINVAL;
}
#endif
if ((mp->m_qflags & (XFS_GQUOTA_ACCT | XFS_GQUOTA_ACTIVE)) &&
(mp->m_qflags & (XFS_PQUOTA_ACCT | XFS_PQUOTA_ACTIVE))) {
xfs_warn(mp, "cannot mount with both project and group quota");
return EINVAL;
}
if ((dsunit && !dswidth) || (!dsunit && dswidth)) {
xfs_warn(mp, "sunit and swidth must be specified together");
return EINVAL;
}
if (dsunit && (dswidth % dsunit != 0)) {
xfs_warn(mp,
"stripe width (%d) must be a multiple of the stripe unit (%d)",
dswidth, dsunit);
return EINVAL;
}
done:
if (!(mp->m_flags & XFS_MOUNT_NOALIGN)) {
if (dsunit) {
mp->m_dalign = dsunit;
mp->m_flags |= XFS_MOUNT_RETERR;
}
if (dswidth)
mp->m_swidth = dswidth;
}
if (mp->m_logbufs != -1 &&
mp->m_logbufs != 0 &&
(mp->m_logbufs < XLOG_MIN_ICLOGS ||
mp->m_logbufs > XLOG_MAX_ICLOGS)) {
xfs_warn(mp, "invalid logbufs value: %d [not %d-%d]",
mp->m_logbufs, XLOG_MIN_ICLOGS, XLOG_MAX_ICLOGS);
return XFS_ERROR(EINVAL);
}
if (mp->m_logbsize != -1 &&
mp->m_logbsize != 0 &&
(mp->m_logbsize < XLOG_MIN_RECORD_BSIZE ||
mp->m_logbsize > XLOG_MAX_RECORD_BSIZE ||
!is_power_of_2(mp->m_logbsize))) {
xfs_warn(mp,
"invalid logbufsize: %d [not 16k,32k,64k,128k or 256k]",
mp->m_logbsize);
return XFS_ERROR(EINVAL);
}
if (iosizelog) {
if (iosizelog > XFS_MAX_IO_LOG ||
iosizelog < XFS_MIN_IO_LOG) {
xfs_warn(mp, "invalid log iosize: %d [not %d-%d]",
iosizelog, XFS_MIN_IO_LOG,
XFS_MAX_IO_LOG);
return XFS_ERROR(EINVAL);
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
{ XFS_MOUNT_IKEEP, "," MNTOPT_IKEEP },
{ XFS_MOUNT_WSYNC, "," MNTOPT_WSYNC },
{ XFS_MOUNT_NOALIGN, "," MNTOPT_NOALIGN },
{ XFS_MOUNT_SWALLOC, "," MNTOPT_SWALLOC },
{ XFS_MOUNT_NOUUID, "," MNTOPT_NOUUID },
{ XFS_MOUNT_NORECOVERY, "," MNTOPT_NORECOVERY },
{ XFS_MOUNT_ATTR2, "," MNTOPT_ATTR2 },
{ XFS_MOUNT_FILESTREAMS, "," MNTOPT_FILESTREAM },
{ XFS_MOUNT_GRPID, "," MNTOPT_GRPID },
{ XFS_MOUNT_DISCARD, "," MNTOPT_DISCARD },
{ XFS_MOUNT_SMALL_INUMS, "," MNTOPT_32BITINODE },
{ 0, NULL }
};
static struct proc_xfs_info xfs_info_unset[] = {
{ XFS_MOUNT_COMPAT_IOSIZE, "," MNTOPT_LARGEIO },
{ XFS_MOUNT_BARRIER, "," MNTOPT_NOBARRIER },
{ XFS_MOUNT_SMALL_INUMS, "," MNTOPT_64BITINODE },
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
seq_printf(m, "," MNTOPT_ALLOCSIZE "=%dk",
(int)(1 << mp->m_writeio_log) >> 10);
if (mp->m_logbufs > 0)
seq_printf(m, "," MNTOPT_LOGBUFS "=%d", mp->m_logbufs);
if (mp->m_logbsize > 0)
seq_printf(m, "," MNTOPT_LOGBSIZE "=%dk", mp->m_logbsize >> 10);
if (mp->m_logname)
seq_printf(m, "," MNTOPT_LOGDEV "=%s", mp->m_logname);
if (mp->m_rtname)
seq_printf(m, "," MNTOPT_RTDEV "=%s", mp->m_rtname);
if (mp->m_dalign > 0)
seq_printf(m, "," MNTOPT_SUNIT "=%d",
(int)XFS_FSB_TO_BB(mp, mp->m_dalign));
if (mp->m_swidth > 0)
seq_printf(m, "," MNTOPT_SWIDTH "=%d",
(int)XFS_FSB_TO_BB(mp, mp->m_swidth));
if (mp->m_qflags & (XFS_UQUOTA_ACCT|XFS_UQUOTA_ENFD))
seq_puts(m, "," MNTOPT_USRQUOTA);
else if (mp->m_qflags & XFS_UQUOTA_ACCT)
seq_puts(m, "," MNTOPT_UQUOTANOENF);
if (mp->m_qflags & XFS_PQUOTA_ACCT) {
if (mp->m_qflags & XFS_OQUOTA_ENFD)
seq_puts(m, "," MNTOPT_PRJQUOTA);
else
seq_puts(m, "," MNTOPT_PQUOTANOENF);
} else if (mp->m_qflags & XFS_GQUOTA_ACCT) {
if (mp->m_qflags & XFS_OQUOTA_ENFD)
seq_puts(m, "," MNTOPT_GRPQUOTA);
else
seq_puts(m, "," MNTOPT_GQUOTANOENF);
}
if (!(mp->m_qflags & XFS_ALL_QUOTA_ACCT))
seq_puts(m, "," MNTOPT_NOQUOTA);
return 0;
}
__uint64_t
xfs_max_file_offset(
unsigned int blockshift)
{
unsigned int pagefactor = 1;
unsigned int bitshift = BITS_PER_LONG - 1;
#if BITS_PER_LONG == 32
# if defined(CONFIG_LBDAF)
ASSERT(sizeof(sector_t) == 8);
pagefactor = PAGE_CACHE_SIZE;
bitshift = BITS_PER_LONG;
# else
pagefactor = PAGE_CACHE_SIZE >> (PAGE_CACHE_SHIFT - blockshift);
# endif
#endif
return (((__uint64_t)pagefactor) << bitshift) - 1;
}
xfs_agnumber_t
xfs_set_inode32(struct xfs_mount *mp)
{
xfs_agnumber_t index = 0;
xfs_agnumber_t maxagi = 0;
xfs_sb_t *sbp = &mp->m_sb;
xfs_agnumber_t max_metadata;
xfs_agino_t agino = XFS_OFFBNO_TO_AGINO(mp, sbp->sb_agblocks -1, 0);
xfs_ino_t ino = XFS_AGINO_TO_INO(mp, sbp->sb_agcount -1, agino);
xfs_perag_t *pag;
if (mp->m_maxicount) {
__uint64_t icount;
icount = sbp->sb_dblocks * sbp->sb_imax_pct;
do_div(icount, 100);
icount += sbp->sb_agblocks - 1;
do_div(icount, sbp->sb_agblocks);
max_metadata = icount;
} else {
max_metadata = sbp->sb_agcount;
}
for (index = 0; index < sbp->sb_agcount; index++) {
ino = XFS_AGINO_TO_INO(mp, index, agino);
if (ino > XFS_MAXINUMBER_32) {
pag = xfs_perag_get(mp, index);
pag->pagi_inodeok = 0;
pag->pagf_metadata = 0;
xfs_perag_put(pag);
continue;
}
pag = xfs_perag_get(mp, index);
pag->pagi_inodeok = 1;
maxagi++;
if (index < max_metadata)
pag->pagf_metadata = 1;
xfs_perag_put(pag);
}
mp->m_flags |= (XFS_MOUNT_32BITINODES |
XFS_MOUNT_SMALL_INUMS);
return maxagi;
}
xfs_agnumber_t
xfs_set_inode64(struct xfs_mount *mp)
{
xfs_agnumber_t index = 0;
for (index = 0; index < mp->m_sb.sb_agcount; index++) {
struct xfs_perag *pag;
pag = xfs_perag_get(mp, index);
pag->pagi_inodeok = 1;
pag->pagf_metadata = 0;
xfs_perag_put(pag);
}
mp->m_flags &= ~(XFS_MOUNT_32BITINODES |
XFS_MOUNT_SMALL_INUMS);
return index;
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
xfs_warn(mp, "Invalid device [%s], error=%d\n", name, error);
}
return -error;
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
if (mp->m_logdev_targp && mp->m_logdev_targp != mp->m_ddev_targp) {
struct block_device *logdev = mp->m_logdev_targp->bt_bdev;
xfs_free_buftarg(mp, mp->m_logdev_targp);
xfs_blkdev_put(logdev);
}
if (mp->m_rtdev_targp) {
struct block_device *rtdev = mp->m_rtdev_targp->bt_bdev;
xfs_free_buftarg(mp, mp->m_rtdev_targp);
xfs_blkdev_put(rtdev);
}
xfs_free_buftarg(mp, mp->m_ddev_targp);
}
STATIC int
xfs_open_devices(
struct xfs_mount *mp)
{
struct block_device *ddev = mp->m_super->s_bdev;
struct block_device *logdev = NULL, *rtdev = NULL;
int error;
if (mp->m_logname) {
error = xfs_blkdev_get(mp, mp->m_logname, &logdev);
if (error)
goto out;
}
if (mp->m_rtname) {
error = xfs_blkdev_get(mp, mp->m_rtname, &rtdev);
if (error)
goto out_close_logdev;
if (rtdev == ddev || rtdev == logdev) {
xfs_warn(mp,
"Cannot mount filesystem with identical rtdev and ddev/logdev.");
error = EINVAL;
goto out_close_rtdev;
}
}
error = ENOMEM;
mp->m_ddev_targp = xfs_alloc_buftarg(mp, ddev, 0, mp->m_fsname);
if (!mp->m_ddev_targp)
goto out_close_rtdev;
if (rtdev) {
mp->m_rtdev_targp = xfs_alloc_buftarg(mp, rtdev, 1,
mp->m_fsname);
if (!mp->m_rtdev_targp)
goto out_free_ddev_targ;
}
if (logdev && logdev != ddev) {
mp->m_logdev_targp = xfs_alloc_buftarg(mp, logdev, 1,
mp->m_fsname);
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
if (rtdev)
xfs_blkdev_put(rtdev);
out_close_logdev:
if (logdev && logdev != ddev)
xfs_blkdev_put(logdev);
out:
return error;
}
STATIC int
xfs_setup_devices(
struct xfs_mount *mp)
{
int error;
error = xfs_setsize_buftarg(mp->m_ddev_targp, mp->m_sb.sb_blocksize,
mp->m_sb.sb_sectsize);
if (error)
return error;
if (mp->m_logdev_targp && mp->m_logdev_targp != mp->m_ddev_targp) {
unsigned int log_sector_size = BBSIZE;
if (xfs_sb_version_hassector(&mp->m_sb))
log_sector_size = mp->m_sb.sb_logsectsize;
error = xfs_setsize_buftarg(mp->m_logdev_targp,
mp->m_sb.sb_blocksize,
log_sector_size);
if (error)
return error;
}
if (mp->m_rtdev_targp) {
error = xfs_setsize_buftarg(mp->m_rtdev_targp,
mp->m_sb.sb_blocksize,
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
mp->m_data_workqueue = alloc_workqueue("xfs-data/%s",
WQ_MEM_RECLAIM, 0, mp->m_fsname);
if (!mp->m_data_workqueue)
goto out;
mp->m_unwritten_workqueue = alloc_workqueue("xfs-conv/%s",
WQ_MEM_RECLAIM, 0, mp->m_fsname);
if (!mp->m_unwritten_workqueue)
goto out_destroy_data_iodone_queue;
mp->m_cil_workqueue = alloc_workqueue("xfs-cil/%s",
WQ_MEM_RECLAIM, 0, mp->m_fsname);
if (!mp->m_cil_workqueue)
goto out_destroy_unwritten;
mp->m_reclaim_workqueue = alloc_workqueue("xfs-reclaim/%s",
WQ_NON_REENTRANT, 0, mp->m_fsname);
if (!mp->m_reclaim_workqueue)
goto out_destroy_cil;
mp->m_log_workqueue = alloc_workqueue("xfs-log/%s",
WQ_NON_REENTRANT, 0, mp->m_fsname);
if (!mp->m_log_workqueue)
goto out_destroy_reclaim;
mp->m_eofblocks_workqueue = alloc_workqueue("xfs-eofblocks/%s",
WQ_NON_REENTRANT, 0, mp->m_fsname);
if (!mp->m_eofblocks_workqueue)
goto out_destroy_log;
return 0;
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
out:
return -ENOMEM;
}
STATIC void
xfs_destroy_mount_workqueues(
struct xfs_mount *mp)
{
destroy_workqueue(mp->m_eofblocks_workqueue);
destroy_workqueue(mp->m_log_workqueue);
destroy_workqueue(mp->m_reclaim_workqueue);
destroy_workqueue(mp->m_cil_workqueue);
destroy_workqueue(mp->m_data_workqueue);
destroy_workqueue(mp->m_unwritten_workqueue);
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
trace_xfs_destroy_inode(ip);
XFS_STATS_INC(vn_reclaim);
if (is_bad_inode(inode))
goto out_reclaim;
ASSERT(XFS_FORCED_SHUTDOWN(ip->i_mount) || ip->i_delayed_blks == 0);
ASSERT_ALWAYS(!xfs_iflags_test(ip, XFS_IRECLAIMABLE));
ASSERT_ALWAYS(!xfs_iflags_test(ip, XFS_IRECLAIM));
out_reclaim:
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
mrlock_init(&ip->i_lock, MRLOCK_ALLOW_EQUAL_PRI|MRLOCK_BARRIER,
"xfsino", ip->i_ino);
}
STATIC void
xfs_fs_evict_inode(
struct inode *inode)
{
xfs_inode_t *ip = XFS_I(inode);
ASSERT(!rwsem_is_locked(&ip->i_iolock.mr_lock));
trace_xfs_evict_inode(ip);
truncate_inode_pages(&inode->i_data, 0);
clear_inode(inode);
XFS_STATS_INC(vn_rele);
XFS_STATS_INC(vn_remove);
XFS_STATS_DEC(vn_active);
xfs_inactive(ip);
}
STATIC int
xfs_fs_drop_inode(
struct inode *inode)
{
struct xfs_inode *ip = XFS_I(inode);
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
STATIC void
xfs_fs_put_super(
struct super_block *sb)
{
struct xfs_mount *mp = XFS_M(sb);
xfs_filestream_unmount(mp);
xfs_unmountfs(mp);
xfs_freesb(mp);
xfs_icsb_destroy_counters(mp);
xfs_destroy_mount_workqueues(mp);
xfs_close_devices(mp);
xfs_free_fsname(mp);
kfree(mp);
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
struct xfs_inode *ip = XFS_I(dentry->d_inode);
__uint64_t fakeinos, id;
xfs_extlen_t lsize;
__int64_t ffree;
statp->f_type = XFS_SB_MAGIC;
statp->f_namelen = MAXNAMELEN - 1;
id = huge_encode_dev(mp->m_ddev_targp->bt_dev);
statp->f_fsid.val[0] = (u32)id;
statp->f_fsid.val[1] = (u32)(id >> 32);
xfs_icsb_sync_counters(mp, XFS_ICSB_LAZY_COUNT);
spin_lock(&mp->m_sb_lock);
statp->f_bsize = sbp->sb_blocksize;
lsize = sbp->sb_logstart ? sbp->sb_logblocks : 0;
statp->f_blocks = sbp->sb_dblocks - lsize;
statp->f_bfree = statp->f_bavail =
sbp->sb_fdblocks - XFS_ALLOC_SET_ASIDE(mp);
fakeinos = statp->f_bfree << sbp->sb_inopblog;
statp->f_files =
MIN(sbp->sb_icount + fakeinos, (__uint64_t)XFS_MAXINUMBER);
if (mp->m_maxicount)
statp->f_files = min_t(typeof(statp->f_files),
statp->f_files,
mp->m_maxicount);
ffree = statp->f_files - (sbp->sb_icount - sbp->sb_ifree);
statp->f_ffree = max_t(__int64_t, ffree, 0);
spin_unlock(&mp->m_sb_lock);
if ((ip->i_d.di_flags & XFS_DIFLAG_PROJINHERIT) &&
((mp->m_qflags & (XFS_PQUOTA_ACCT|XFS_OQUOTA_ENFD))) ==
(XFS_PQUOTA_ACCT|XFS_OQUOTA_ENFD))
xfs_qm_statvfs(ip, statp);
return 0;
}
STATIC void
xfs_save_resvblks(struct xfs_mount *mp)
{
__uint64_t resblks = 0;
mp->m_resblks_save = mp->m_resblks;
xfs_reserve_blocks(mp, &resblks, NULL);
}
STATIC void
xfs_restore_resvblks(struct xfs_mount *mp)
{
__uint64_t resblks;
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
xfs_fs_remount(
struct super_block *sb,
int *flags,
char *options)
{
struct xfs_mount *mp = XFS_M(sb);
substring_t args[MAX_OPT_ARGS];
char *p;
int error;
while ((p = strsep(&options, ",")) != NULL) {
int token;
if (!*p)
continue;
token = match_token(p, tokens, args);
switch (token) {
case Opt_barrier:
mp->m_flags |= XFS_MOUNT_BARRIER;
break;
case Opt_nobarrier:
mp->m_flags &= ~XFS_MOUNT_BARRIER;
break;
case Opt_inode64:
mp->m_maxagi = xfs_set_inode64(mp);
break;
case Opt_inode32:
mp->m_maxagi = xfs_set_inode32(mp);
break;
default:
#if 0
xfs_info(mp,
"mount option \"%s\" not supported for remount\n", p);
return -EINVAL;
#else
break;
#endif
}
}
if ((mp->m_flags & XFS_MOUNT_RDONLY) && !(*flags & MS_RDONLY)) {
mp->m_flags &= ~XFS_MOUNT_RDONLY;
if (mp->m_update_flags) {
error = xfs_mount_log_sb(mp, mp->m_update_flags);
if (error) {
xfs_warn(mp, "failed to write sb changes");
return error;
}
mp->m_update_flags = 0;
}
xfs_restore_resvblks(mp);
xfs_log_work_queue(mp);
}
if (!(mp->m_flags & XFS_MOUNT_RDONLY) && (*flags & MS_RDONLY)) {
xfs_save_resvblks(mp);
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
return -xfs_fs_log_dummy(mp);
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
return -xfs_showargs(XFS_M(root->d_sb), m);
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
return XFS_ERROR(EINVAL);
}
} else {
if (mp->m_logbsize > XLOG_BIG_RECORD_BSIZE) {
xfs_warn(mp,
"logbuf size for version 1 logs must be 16K or 32K");
return XFS_ERROR(EINVAL);
}
}
if (xfs_sb_version_hascrc(&mp->m_sb) &&
(mp->m_flags & XFS_MOUNT_NOATTR2)) {
xfs_warn(mp,
"Cannot mount a V5 filesystem as %s. %s is always enabled for V5 filesystems.",
MNTOPT_NOATTR2, MNTOPT_ATTR2);
return XFS_ERROR(EINVAL);
}
if (xfs_sb_version_hasattr2(&mp->m_sb) &&
!(mp->m_flags & XFS_MOUNT_NOATTR2))
mp->m_flags |= XFS_MOUNT_ATTR2;
if ((mp->m_sb.sb_flags & XFS_SBF_READONLY) && !ronly) {
xfs_warn(mp,
"cannot mount a read-only filesystem as read-write");
return XFS_ERROR(EROFS);
}
return 0;
}
STATIC int
xfs_fs_fill_super(
struct super_block *sb,
void *data,
int silent)
{
struct inode *root;
struct xfs_mount *mp = NULL;
int flags = 0, error = ENOMEM;
mp = kzalloc(sizeof(struct xfs_mount), GFP_KERNEL);
if (!mp)
goto out;
spin_lock_init(&mp->m_sb_lock);
mutex_init(&mp->m_growlock);
atomic_set(&mp->m_active_trans, 0);
INIT_DELAYED_WORK(&mp->m_reclaim_work, xfs_reclaim_worker);
INIT_DELAYED_WORK(&mp->m_eofblocks_work, xfs_eofblocks_worker);
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
error = xfs_icsb_init_counters(mp);
if (error)
goto out_destroy_workqueues;
error = xfs_readsb(mp, flags);
if (error)
goto out_destroy_counters;
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
error = xfs_mountfs(mp);
if (error)
goto out_filestream_unmount;
root = igrab(VFS_I(mp->m_rootip));
if (!root) {
error = ENOENT;
goto out_unmount;
}
if (is_bad_inode(root)) {
error = EINVAL;
goto out_unmount;
}
sb->s_root = d_make_root(root);
if (!sb->s_root) {
error = ENOMEM;
goto out_unmount;
}
return 0;
out_filestream_unmount:
xfs_filestream_unmount(mp);
out_free_sb:
xfs_freesb(mp);
out_destroy_counters:
xfs_icsb_destroy_counters(mp);
out_destroy_workqueues:
xfs_destroy_mount_workqueues(mp);
out_close_devices:
xfs_close_devices(mp);
out_free_fsname:
xfs_free_fsname(mp);
kfree(mp);
out:
return -error;
out_unmount:
xfs_filestream_unmount(mp);
xfs_unmountfs(mp);
goto out_free_sb;
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
static int
xfs_fs_nr_cached_objects(
struct super_block *sb)
{
return xfs_reclaim_inodes_count(XFS_M(sb));
}
static void
xfs_fs_free_cached_objects(
struct super_block *sb,
int nr_to_scan)
{
xfs_reclaim_inodes_nr(XFS_M(sb), nr_to_scan);
}
STATIC int __init
xfs_init_zones(void)
{
xfs_ioend_zone = kmem_zone_init(sizeof(xfs_ioend_t), "xfs_ioend");
if (!xfs_ioend_zone)
goto out;
xfs_ioend_pool = mempool_create_slab_pool(4 * MAX_BUF_PER_PAGE,
xfs_ioend_zone);
if (!xfs_ioend_pool)
goto out_destroy_ioend_zone;
xfs_log_ticket_zone = kmem_zone_init(sizeof(xlog_ticket_t),
"xfs_log_ticket");
if (!xfs_log_ticket_zone)
goto out_destroy_ioend_pool;
xfs_bmap_free_item_zone = kmem_zone_init(sizeof(xfs_bmap_free_item_t),
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
KM_ZONE_HWALIGN | KM_ZONE_RECLAIM | KM_ZONE_SPREAD,
xfs_fs_inode_init_once);
if (!xfs_inode_zone)
goto out_destroy_efi_zone;
xfs_ili_zone =
kmem_zone_init_flags(sizeof(xfs_inode_log_item_t), "xfs_ili",
KM_ZONE_SPREAD, NULL);
if (!xfs_ili_zone)
goto out_destroy_inode_zone;
return 0;
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
out_destroy_ioend_pool:
mempool_destroy(xfs_ioend_pool);
out_destroy_ioend_zone:
kmem_zone_destroy(xfs_ioend_zone);
out:
return -ENOMEM;
}
STATIC void
xfs_destroy_zones(void)
{
rcu_barrier();
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
mempool_destroy(xfs_ioend_pool);
kmem_zone_destroy(xfs_ioend_zone);
}
STATIC int __init
xfs_init_workqueues(void)
{
xfs_alloc_wq = alloc_workqueue("xfsalloc", WQ_MEM_RECLAIM, 0);
if (!xfs_alloc_wq)
return -ENOMEM;
return 0;
}
STATIC void
xfs_destroy_workqueues(void)
{
destroy_workqueue(xfs_alloc_wq);
}
STATIC int __init
init_xfs_fs(void)
{
int error;
printk(KERN_INFO XFS_VERSION_STRING " with "
XFS_BUILD_OPTIONS " enabled\n");
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
error = xfs_filestream_init();
if (error)
goto out_mru_cache_uninit;
error = xfs_buf_init();
if (error)
goto out_filestream_uninit;
error = xfs_init_procfs();
if (error)
goto out_buf_terminate;
error = xfs_sysctl_register();
if (error)
goto out_cleanup_procfs;
error = xfs_qm_init();
if (error)
goto out_sysctl_unregister;
error = register_filesystem(&xfs_fs_type);
if (error)
goto out_qm_exit;
return 0;
out_qm_exit:
xfs_qm_exit();
out_sysctl_unregister:
xfs_sysctl_unregister();
out_cleanup_procfs:
xfs_cleanup_procfs();
out_buf_terminate:
xfs_buf_terminate();
out_filestream_uninit:
xfs_filestream_uninit();
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
xfs_sysctl_unregister();
xfs_cleanup_procfs();
xfs_buf_terminate();
xfs_filestream_uninit();
xfs_mru_cache_uninit();
xfs_destroy_workqueues();
xfs_destroy_zones();
}
