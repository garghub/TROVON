void
xfs_do_force_shutdown(
xfs_mount_t *mp,
int flags,
char *fname,
int lnnum)
{
int logerror;
logerror = flags & SHUTDOWN_LOG_IO_ERROR;
if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
xfs_notice(mp,
"%s(0x%x) called from line %d of file %s. Return address = 0x%p",
__func__, flags, lnnum, fname, __return_address);
}
if (XFS_FORCED_SHUTDOWN(mp) && !logerror)
return;
if (xfs_log_force_umount(mp, logerror))
return;
if (flags & SHUTDOWN_CORRUPT_INCORE) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_CORRUPT,
"Corruption of in-memory data detected. Shutting down filesystem");
if (XFS_ERRLEVEL_HIGH <= xfs_error_level)
xfs_stack_trace();
} else if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
if (logerror) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_LOGERROR,
"Log I/O Error Detected. Shutting down filesystem");
} else if (flags & SHUTDOWN_DEVICE_REQ) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_IOERROR,
"All device paths lost. Shutting down filesystem");
} else if (!(flags & SHUTDOWN_REMOTE_REQ)) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_IOERROR,
"I/O Error Detected. Shutting down filesystem");
}
}
if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
xfs_alert(mp,
"Please umount the filesystem and rectify the problem(s)");
}
}
void
xfs_ioerror_alert(
char *func,
struct xfs_mount *mp,
xfs_buf_t *bp,
xfs_daddr_t blkno)
{
xfs_alert(mp,
"I/O error occurred: meta-data dev %s block 0x%llx"
" (\"%s\") error %d buf count %zd",
xfs_buf_target_name(bp->b_target),
(__uint64_t)blkno, func,
bp->b_error, XFS_BUF_COUNT(bp));
}
int
xfs_read_buf(
struct xfs_mount *mp,
xfs_buftarg_t *target,
xfs_daddr_t blkno,
int len,
uint flags,
xfs_buf_t **bpp)
{
xfs_buf_t *bp;
int error;
if (!flags)
flags = XBF_LOCK | XBF_MAPPED;
bp = xfs_buf_read(target, blkno, len, flags);
if (!bp)
return XFS_ERROR(EIO);
error = bp->b_error;
if (!error && !XFS_FORCED_SHUTDOWN(mp)) {
*bpp = bp;
} else {
*bpp = NULL;
if (error) {
xfs_ioerror_alert("xfs_read_buf", mp, bp, XFS_BUF_ADDR(bp));
} else {
error = XFS_ERROR(EIO);
}
if (bp) {
XFS_BUF_UNDONE(bp);
XFS_BUF_UNDELAYWRITE(bp);
XFS_BUF_STALE(bp);
xfs_buf_relse(bp);
}
}
return (error);
}
xfs_extlen_t
xfs_get_extsz_hint(
struct xfs_inode *ip)
{
if ((ip->i_d.di_flags & XFS_DIFLAG_EXTSIZE) && ip->i_d.di_extsize)
return ip->i_d.di_extsize;
if (XFS_IS_REALTIME_INODE(ip))
return ip->i_mount->m_sb.sb_rextsize;
return 0;
}
