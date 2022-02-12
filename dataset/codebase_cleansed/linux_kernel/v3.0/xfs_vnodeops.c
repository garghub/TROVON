int
xfs_setattr(
struct xfs_inode *ip,
struct iattr *iattr,
int flags)
{
xfs_mount_t *mp = ip->i_mount;
struct inode *inode = VFS_I(ip);
int mask = iattr->ia_valid;
xfs_trans_t *tp;
int code;
uint lock_flags;
uint commit_flags=0;
uid_t uid=0, iuid=0;
gid_t gid=0, igid=0;
struct xfs_dquot *udqp, *gdqp, *olddquot1, *olddquot2;
int need_iolock = 1;
trace_xfs_setattr(ip);
if (mp->m_flags & XFS_MOUNT_RDONLY)
return XFS_ERROR(EROFS);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
code = -inode_change_ok(inode, iattr);
if (code)
return code;
olddquot1 = olddquot2 = NULL;
udqp = gdqp = NULL;
if (XFS_IS_QUOTA_ON(mp) && (mask & (ATTR_UID|ATTR_GID))) {
uint qflags = 0;
if ((mask & ATTR_UID) && XFS_IS_UQUOTA_ON(mp)) {
uid = iattr->ia_uid;
qflags |= XFS_QMOPT_UQUOTA;
} else {
uid = ip->i_d.di_uid;
}
if ((mask & ATTR_GID) && XFS_IS_GQUOTA_ON(mp)) {
gid = iattr->ia_gid;
qflags |= XFS_QMOPT_GQUOTA;
} else {
gid = ip->i_d.di_gid;
}
ASSERT(udqp == NULL);
ASSERT(gdqp == NULL);
code = xfs_qm_vop_dqalloc(ip, uid, gid, xfs_get_projid(ip),
qflags, &udqp, &gdqp);
if (code)
return code;
}
tp = NULL;
lock_flags = XFS_ILOCK_EXCL;
if (flags & XFS_ATTR_NOLOCK)
need_iolock = 0;
if (!(mask & ATTR_SIZE)) {
tp = xfs_trans_alloc(mp, XFS_TRANS_SETATTR_NOT_SIZE);
commit_flags = 0;
code = xfs_trans_reserve(tp, 0, XFS_ICHANGE_LOG_RES(mp),
0, 0, 0);
if (code) {
lock_flags = 0;
goto error_return;
}
} else {
if (need_iolock)
lock_flags |= XFS_IOLOCK_EXCL;
}
xfs_ilock(ip, lock_flags);
if (mask & (ATTR_UID|ATTR_GID)) {
iuid = ip->i_d.di_uid;
igid = ip->i_d.di_gid;
gid = (mask & ATTR_GID) ? iattr->ia_gid : igid;
uid = (mask & ATTR_UID) ? iattr->ia_uid : iuid;
if (XFS_IS_QUOTA_RUNNING(mp) &&
((XFS_IS_UQUOTA_ON(mp) && iuid != uid) ||
(XFS_IS_GQUOTA_ON(mp) && igid != gid))) {
ASSERT(tp);
code = xfs_qm_vop_chown_reserve(tp, ip, udqp, gdqp,
capable(CAP_FOWNER) ?
XFS_QMOPT_FORCE_RES : 0);
if (code)
goto error_return;
}
}
if (mask & ATTR_SIZE) {
if (iattr->ia_size == 0 &&
ip->i_size == 0 && ip->i_d.di_nextents == 0) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
lock_flags &= ~XFS_ILOCK_EXCL;
if (mask & ATTR_CTIME) {
inode->i_mtime = inode->i_ctime =
current_fs_time(inode->i_sb);
xfs_mark_inode_dirty_sync(ip);
}
code = 0;
goto error_return;
}
if (S_ISDIR(ip->i_d.di_mode)) {
code = XFS_ERROR(EISDIR);
goto error_return;
} else if (!S_ISREG(ip->i_d.di_mode)) {
code = XFS_ERROR(EINVAL);
goto error_return;
}
code = xfs_qm_dqattach_locked(ip, 0);
if (code)
goto error_return;
if (iattr->ia_size > ip->i_size) {
code = xfs_zero_eof(ip, iattr->ia_size, ip->i_size);
if (code)
goto error_return;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
lock_flags &= ~XFS_ILOCK_EXCL;
if (ip->i_size != ip->i_d.di_size &&
iattr->ia_size > ip->i_d.di_size) {
code = xfs_flush_pages(ip,
ip->i_d.di_size, iattr->ia_size,
XBF_ASYNC, FI_NONE);
if (code)
goto error_return;
}
xfs_ioend_wait(ip);
code = -block_truncate_page(inode->i_mapping, iattr->ia_size,
xfs_get_blocks);
if (code)
goto error_return;
tp = xfs_trans_alloc(mp, XFS_TRANS_SETATTR_SIZE);
code = xfs_trans_reserve(tp, 0, XFS_ITRUNCATE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES,
XFS_ITRUNCATE_LOG_COUNT);
if (code)
goto error_return;
truncate_setsize(inode, iattr->ia_size);
commit_flags = XFS_TRANS_RELEASE_LOG_RES;
lock_flags |= XFS_ILOCK_EXCL;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
if (iattr->ia_size != ip->i_size &&
(!(mask & (ATTR_CTIME | ATTR_MTIME)))) {
iattr->ia_ctime = iattr->ia_mtime =
current_fs_time(inode->i_sb);
mask |= ATTR_CTIME | ATTR_MTIME;
}
if (iattr->ia_size > ip->i_size) {
ip->i_d.di_size = iattr->ia_size;
ip->i_size = iattr->ia_size;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
} else if (iattr->ia_size <= ip->i_size ||
(iattr->ia_size == 0 && ip->i_d.di_nextents)) {
code = xfs_itruncate_finish(&tp, ip, iattr->ia_size,
XFS_DATA_FORK,
((ip->i_d.di_nlink != 0 ||
!(mp->m_flags & XFS_MOUNT_WSYNC))
? 1 : 0));
if (code)
goto abort_return;
xfs_iflags_set(ip, XFS_ITRUNCATED);
}
} else if (tp) {
xfs_trans_ijoin(tp, ip);
}
if (mask & (ATTR_UID|ATTR_GID)) {
if ((ip->i_d.di_mode & (S_ISUID|S_ISGID)) &&
!capable(CAP_FSETID)) {
ip->i_d.di_mode &= ~(S_ISUID|S_ISGID);
}
if (iuid != uid) {
if (XFS_IS_QUOTA_RUNNING(mp) && XFS_IS_UQUOTA_ON(mp)) {
ASSERT(mask & ATTR_UID);
ASSERT(udqp);
olddquot1 = xfs_qm_vop_chown(tp, ip,
&ip->i_udquot, udqp);
}
ip->i_d.di_uid = uid;
inode->i_uid = uid;
}
if (igid != gid) {
if (XFS_IS_QUOTA_RUNNING(mp) && XFS_IS_GQUOTA_ON(mp)) {
ASSERT(!XFS_IS_PQUOTA_ON(mp));
ASSERT(mask & ATTR_GID);
ASSERT(gdqp);
olddquot2 = xfs_qm_vop_chown(tp, ip,
&ip->i_gdquot, gdqp);
}
ip->i_d.di_gid = gid;
inode->i_gid = gid;
}
}
if (mask & ATTR_MODE) {
umode_t mode = iattr->ia_mode;
if (!in_group_p(inode->i_gid) && !capable(CAP_FSETID))
mode &= ~S_ISGID;
ip->i_d.di_mode &= S_IFMT;
ip->i_d.di_mode |= mode & ~S_IFMT;
inode->i_mode &= S_IFMT;
inode->i_mode |= mode & ~S_IFMT;
}
if (mask & ATTR_ATIME) {
inode->i_atime = iattr->ia_atime;
ip->i_d.di_atime.t_sec = iattr->ia_atime.tv_sec;
ip->i_d.di_atime.t_nsec = iattr->ia_atime.tv_nsec;
ip->i_update_core = 1;
}
if (mask & ATTR_CTIME) {
inode->i_ctime = iattr->ia_ctime;
ip->i_d.di_ctime.t_sec = iattr->ia_ctime.tv_sec;
ip->i_d.di_ctime.t_nsec = iattr->ia_ctime.tv_nsec;
ip->i_update_core = 1;
}
if (mask & ATTR_MTIME) {
inode->i_mtime = iattr->ia_mtime;
ip->i_d.di_mtime.t_sec = iattr->ia_mtime.tv_sec;
ip->i_d.di_mtime.t_nsec = iattr->ia_mtime.tv_nsec;
ip->i_update_core = 1;
}
if (mask & (ATTR_UID|ATTR_GID|ATTR_MODE|
ATTR_ATIME|ATTR_CTIME|ATTR_MTIME))
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
XFS_STATS_INC(xs_ig_attrchg);
code = 0;
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
code = xfs_trans_commit(tp, commit_flags);
xfs_iunlock(ip, lock_flags);
xfs_qm_dqrele(olddquot1);
xfs_qm_dqrele(olddquot2);
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
if (code)
return code;
if ((mask & ATTR_MODE) && !(flags & XFS_ATTR_NOACL)) {
code = -xfs_acl_chmod(inode);
if (code)
return XFS_ERROR(code);
}
return 0;
abort_return:
commit_flags |= XFS_TRANS_ABORT;
error_return:
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
if (tp) {
xfs_trans_cancel(tp, commit_flags);
}
if (lock_flags != 0) {
xfs_iunlock(ip, lock_flags);
}
return code;
}
STATIC int
xfs_readlink_bmap(
xfs_inode_t *ip,
char *link)
{
xfs_mount_t *mp = ip->i_mount;
int pathlen = ip->i_d.di_size;
int nmaps = SYMLINK_MAPS;
xfs_bmbt_irec_t mval[SYMLINK_MAPS];
xfs_daddr_t d;
int byte_cnt;
int n;
xfs_buf_t *bp;
int error = 0;
error = xfs_bmapi(NULL, ip, 0, XFS_B_TO_FSB(mp, pathlen), 0, NULL, 0,
mval, &nmaps, NULL);
if (error)
goto out;
for (n = 0; n < nmaps; n++) {
d = XFS_FSB_TO_DADDR(mp, mval[n].br_startblock);
byte_cnt = XFS_FSB_TO_B(mp, mval[n].br_blockcount);
bp = xfs_buf_read(mp->m_ddev_targp, d, BTOBB(byte_cnt),
XBF_LOCK | XBF_MAPPED | XBF_DONT_BLOCK);
error = XFS_BUF_GETERROR(bp);
if (error) {
xfs_ioerror_alert("xfs_readlink",
ip->i_mount, bp, XFS_BUF_ADDR(bp));
xfs_buf_relse(bp);
goto out;
}
if (pathlen < byte_cnt)
byte_cnt = pathlen;
pathlen -= byte_cnt;
memcpy(link, XFS_BUF_PTR(bp), byte_cnt);
xfs_buf_relse(bp);
}
link[ip->i_d.di_size] = '\0';
error = 0;
out:
return error;
}
int
xfs_readlink(
xfs_inode_t *ip,
char *link)
{
xfs_mount_t *mp = ip->i_mount;
int pathlen;
int error = 0;
trace_xfs_readlink(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
xfs_ilock(ip, XFS_ILOCK_SHARED);
ASSERT((ip->i_d.di_mode & S_IFMT) == S_IFLNK);
ASSERT(ip->i_d.di_size <= MAXPATHLEN);
pathlen = ip->i_d.di_size;
if (!pathlen)
goto out;
if (ip->i_df.if_flags & XFS_IFINLINE) {
memcpy(link, ip->i_df.if_u1.if_data, pathlen);
link[pathlen] = '\0';
} else {
error = xfs_readlink_bmap(ip, link);
}
out:
xfs_iunlock(ip, XFS_ILOCK_SHARED);
return error;
}
STATIC int
xfs_free_eofblocks(
xfs_mount_t *mp,
xfs_inode_t *ip,
int flags)
{
xfs_trans_t *tp;
int error;
xfs_fileoff_t end_fsb;
xfs_fileoff_t last_fsb;
xfs_filblks_t map_len;
int nimaps;
xfs_bmbt_irec_t imap;
end_fsb = XFS_B_TO_FSB(mp, ((xfs_ufsize_t)ip->i_size));
last_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)XFS_MAXIOFFSET(mp));
if (last_fsb <= end_fsb)
return 0;
map_len = last_fsb - end_fsb;
nimaps = 1;
xfs_ilock(ip, XFS_ILOCK_SHARED);
error = xfs_bmapi(NULL, ip, end_fsb, map_len, 0,
NULL, 0, &imap, &nimaps, NULL);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (!error && (nimaps != 0) &&
(imap.br_startblock != HOLESTARTBLOCK ||
ip->i_delayed_blks)) {
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
tp = xfs_trans_alloc(mp, XFS_TRANS_INACTIVE);
if (flags & XFS_FREE_EOF_TRYLOCK) {
if (!xfs_ilock_nowait(ip, XFS_IOLOCK_EXCL)) {
xfs_trans_cancel(tp, 0);
return 0;
}
} else {
xfs_ilock(ip, XFS_IOLOCK_EXCL);
}
error = xfs_itruncate_start(ip, XFS_ITRUNC_DEFINITE,
ip->i_size);
if (error) {
xfs_trans_cancel(tp, 0);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
error = xfs_trans_reserve(tp, 0,
XFS_ITRUNCATE_LOG_RES(mp),
0, XFS_TRANS_PERM_LOG_RES,
XFS_ITRUNCATE_LOG_COUNT);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
error = xfs_itruncate_finish(&tp, ip,
ip->i_size,
XFS_DATA_FORK,
0);
if (error) {
xfs_trans_cancel(tp,
(XFS_TRANS_RELEASE_LOG_RES |
XFS_TRANS_ABORT));
} else {
error = xfs_trans_commit(tp,
XFS_TRANS_RELEASE_LOG_RES);
}
xfs_iunlock(ip, XFS_IOLOCK_EXCL|XFS_ILOCK_EXCL);
}
return error;
}
STATIC int
xfs_inactive_symlink_rmt(
xfs_inode_t *ip,
xfs_trans_t **tpp)
{
xfs_buf_t *bp;
int committed;
int done;
int error;
xfs_fsblock_t first_block;
xfs_bmap_free_t free_list;
int i;
xfs_mount_t *mp;
xfs_bmbt_irec_t mval[SYMLINK_MAPS];
int nmaps;
xfs_trans_t *ntp;
int size;
xfs_trans_t *tp;
tp = *tpp;
mp = ip->i_mount;
ASSERT(ip->i_d.di_size > XFS_IFORK_DSIZE(ip));
ASSERT(ip->i_d.di_nextents > 0 && ip->i_d.di_nextents <= 2);
if ((error = xfs_trans_reserve(tp, 0, XFS_ITRUNCATE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_ITRUNCATE_LOG_COUNT))) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
*tpp = NULL;
return error;
}
xfs_ilock(ip, XFS_IOLOCK_EXCL | XFS_ILOCK_EXCL);
size = (int)ip->i_d.di_size;
ip->i_d.di_size = 0;
xfs_trans_ijoin(tp, ip);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
done = 0;
xfs_bmap_init(&free_list, &first_block);
nmaps = ARRAY_SIZE(mval);
if ((error = xfs_bmapi(tp, ip, 0, XFS_B_TO_FSB(mp, size),
XFS_BMAPI_METADATA, &first_block, 0, mval, &nmaps,
&free_list)))
goto error0;
for (i = 0; i < nmaps; i++) {
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, mval[i].br_startblock),
XFS_FSB_TO_BB(mp, mval[i].br_blockcount), 0);
xfs_trans_binval(tp, bp);
}
if ((error = xfs_bunmapi(tp, ip, 0, size, XFS_BMAPI_METADATA, nmaps,
&first_block, &free_list, &done)))
goto error1;
ASSERT(done);
if ((error = xfs_bmap_finish(&tp, &free_list, &committed)))
goto error1;
ASSERT(committed);
xfs_trans_ijoin(tp, ip);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
ntp = xfs_trans_dup(tp);
error = xfs_trans_commit(tp, 0);
tp = ntp;
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
goto error0;
}
xfs_log_ticket_put(tp->t_ticket);
if (ip->i_df.if_bytes)
xfs_idata_realloc(ip, -ip->i_df.if_bytes, XFS_DATA_FORK);
ASSERT(ip->i_df.if_bytes == 0);
if ((error = xfs_trans_reserve(tp, 0, XFS_ITRUNCATE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_ITRUNCATE_LOG_COUNT))) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
goto error0;
}
*tpp = tp;
return 0;
error1:
xfs_bmap_cancel(&free_list);
error0:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_IOLOCK_EXCL | XFS_ILOCK_EXCL);
*tpp = NULL;
return error;
}
STATIC int
xfs_inactive_symlink_local(
xfs_inode_t *ip,
xfs_trans_t **tpp)
{
int error;
ASSERT(ip->i_d.di_size <= XFS_IFORK_DSIZE(ip));
error = xfs_trans_reserve(*tpp, 0,
XFS_ITRUNCATE_LOG_RES(ip->i_mount),
0, XFS_TRANS_PERM_LOG_RES,
XFS_ITRUNCATE_LOG_COUNT);
if (error) {
xfs_trans_cancel(*tpp, 0);
*tpp = NULL;
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
if (ip->i_df.if_bytes > 0) {
xfs_idata_realloc(ip,
-(ip->i_df.if_bytes),
XFS_DATA_FORK);
ASSERT(ip->i_df.if_bytes == 0);
}
return 0;
}
STATIC int
xfs_inactive_attrs(
xfs_inode_t *ip,
xfs_trans_t **tpp)
{
xfs_trans_t *tp;
int error;
xfs_mount_t *mp;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
tp = *tpp;
mp = ip->i_mount;
ASSERT(ip->i_d.di_forkoff != 0);
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
goto error_unlock;
error = xfs_attr_inactive(ip);
if (error)
goto error_unlock;
tp = xfs_trans_alloc(mp, XFS_TRANS_INACTIVE);
error = xfs_trans_reserve(tp, 0,
XFS_IFREE_LOG_RES(mp),
0, XFS_TRANS_PERM_LOG_RES,
XFS_INACTIVE_LOG_COUNT);
if (error)
goto error_cancel;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
xfs_idestroy_fork(ip, XFS_ATTR_FORK);
ASSERT(ip->i_d.di_anextents == 0);
*tpp = tp;
return 0;
error_cancel:
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
error_unlock:
*tpp = NULL;
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
int
xfs_release(
xfs_inode_t *ip)
{
xfs_mount_t *mp = ip->i_mount;
int error;
if (!S_ISREG(ip->i_d.di_mode) || (ip->i_d.di_mode == 0))
return 0;
if (mp->m_flags & XFS_MOUNT_RDONLY)
return 0;
if (!XFS_FORCED_SHUTDOWN(mp)) {
int truncated;
if ((ip->i_d.di_nlink == 0) && xfs_inode_is_filestream(ip))
xfs_filestream_deassociate(ip);
truncated = xfs_iflags_test_and_clear(ip, XFS_ITRUNCATED);
if (truncated) {
xfs_iflags_clear(ip, XFS_IDIRTY_RELEASE);
if (VN_DIRTY(VFS_I(ip)) && ip->i_delayed_blks > 0)
xfs_flush_pages(ip, 0, -1, XBF_ASYNC, FI_NONE);
}
}
if (ip->i_d.di_nlink == 0)
return 0;
if ((((ip->i_d.di_mode & S_IFMT) == S_IFREG) &&
((ip->i_size > 0) || (VN_CACHED(VFS_I(ip)) > 0 ||
ip->i_delayed_blks > 0)) &&
(ip->i_df.if_flags & XFS_IFEXTENTS)) &&
(!(ip->i_d.di_flags & (XFS_DIFLAG_PREALLOC | XFS_DIFLAG_APPEND)))) {
if (xfs_iflags_test(ip, XFS_IDIRTY_RELEASE))
return 0;
error = xfs_free_eofblocks(mp, ip,
XFS_FREE_EOF_TRYLOCK);
if (error)
return error;
if (ip->i_delayed_blks)
xfs_iflags_set(ip, XFS_IDIRTY_RELEASE);
}
return 0;
}
int
xfs_inactive(
xfs_inode_t *ip)
{
xfs_bmap_free_t free_list;
xfs_fsblock_t first_block;
int committed;
xfs_trans_t *tp;
xfs_mount_t *mp;
int error;
int truncate;
if (ip->i_d.di_mode == 0 || is_bad_inode(VFS_I(ip))) {
ASSERT(ip->i_df.if_real_bytes == 0);
ASSERT(ip->i_df.if_broot_bytes == 0);
return VN_INACTIVE_CACHE;
}
truncate = ((ip->i_d.di_nlink == 0) &&
((ip->i_d.di_size != 0) || (ip->i_size != 0) ||
(ip->i_d.di_nextents > 0) || (ip->i_delayed_blks > 0)) &&
((ip->i_d.di_mode & S_IFMT) == S_IFREG));
mp = ip->i_mount;
error = 0;
if (mp->m_flags & XFS_MOUNT_RDONLY)
goto out;
if (ip->i_d.di_nlink != 0) {
if ((((ip->i_d.di_mode & S_IFMT) == S_IFREG) &&
((ip->i_size > 0) || (VN_CACHED(VFS_I(ip)) > 0 ||
ip->i_delayed_blks > 0)) &&
(ip->i_df.if_flags & XFS_IFEXTENTS) &&
(!(ip->i_d.di_flags &
(XFS_DIFLAG_PREALLOC | XFS_DIFLAG_APPEND)) ||
(ip->i_delayed_blks != 0)))) {
error = xfs_free_eofblocks(mp, ip, 0);
if (error)
return VN_INACTIVE_CACHE;
}
goto out;
}
ASSERT(ip->i_d.di_nlink == 0);
error = xfs_qm_dqattach(ip, 0);
if (error)
return VN_INACTIVE_CACHE;
tp = xfs_trans_alloc(mp, XFS_TRANS_INACTIVE);
if (truncate) {
xfs_ilock(ip, XFS_IOLOCK_EXCL);
error = xfs_itruncate_start(ip, XFS_ITRUNC_DEFINITE, 0);
if (error) {
xfs_trans_cancel(tp, 0);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return VN_INACTIVE_CACHE;
}
error = xfs_trans_reserve(tp, 0,
XFS_ITRUNCATE_LOG_RES(mp),
0, XFS_TRANS_PERM_LOG_RES,
XFS_ITRUNCATE_LOG_COUNT);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return VN_INACTIVE_CACHE;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
error = xfs_itruncate_finish(&tp, ip, 0, XFS_DATA_FORK,
(!(mp->m_flags & XFS_MOUNT_WSYNC) ? 1 : 0));
if (error) {
xfs_trans_cancel(tp,
XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_IOLOCK_EXCL | XFS_ILOCK_EXCL);
return VN_INACTIVE_CACHE;
}
} else if ((ip->i_d.di_mode & S_IFMT) == S_IFLNK) {
error = (ip->i_d.di_size > XFS_IFORK_DSIZE(ip)) ?
xfs_inactive_symlink_rmt(ip, &tp) :
xfs_inactive_symlink_local(ip, &tp);
if (error) {
ASSERT(tp == NULL);
return VN_INACTIVE_CACHE;
}
xfs_trans_ijoin(tp, ip);
} else {
error = xfs_trans_reserve(tp, 0,
XFS_IFREE_LOG_RES(mp),
0, XFS_TRANS_PERM_LOG_RES,
XFS_INACTIVE_LOG_COUNT);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
return VN_INACTIVE_CACHE;
}
xfs_ilock(ip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
xfs_trans_ijoin(tp, ip);
}
if (ip->i_d.di_anextents > 0) {
error = xfs_inactive_attrs(ip, &tp);
if (error)
return VN_INACTIVE_CACHE;
} else if (ip->i_afp) {
xfs_idestroy_fork(ip, XFS_ATTR_FORK);
}
xfs_bmap_init(&free_list, &first_block);
error = xfs_ifree(tp, ip, &free_list);
if (error) {
if (!XFS_FORCED_SHUTDOWN(mp)) {
xfs_notice(mp, "%s: xfs_ifree returned error %d",
__func__, error);
xfs_force_shutdown(mp, SHUTDOWN_META_IO_ERROR);
}
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES|XFS_TRANS_ABORT);
} else {
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_ICOUNT, -1);
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
xfs_notice(mp, "%s: xfs_bmap_finish returned error %d",
__func__, error);
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
xfs_notice(mp, "%s: xfs_trans_commit returned error %d",
__func__, error);
}
xfs_qm_dqdetach(ip);
xfs_iunlock(ip, XFS_IOLOCK_EXCL | XFS_ILOCK_EXCL);
out:
return VN_INACTIVE_CACHE;
}
int
xfs_lookup(
xfs_inode_t *dp,
struct xfs_name *name,
xfs_inode_t **ipp,
struct xfs_name *ci_name)
{
xfs_ino_t inum;
int error;
uint lock_mode;
trace_xfs_lookup(dp, name);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return XFS_ERROR(EIO);
lock_mode = xfs_ilock_map_shared(dp);
error = xfs_dir_lookup(NULL, dp, name, &inum, ci_name);
xfs_iunlock_map_shared(dp, lock_mode);
if (error)
goto out;
error = xfs_iget(dp->i_mount, NULL, inum, 0, 0, ipp);
if (error)
goto out_free_name;
return 0;
out_free_name:
if (ci_name)
kmem_free(ci_name->name);
out:
*ipp = NULL;
return error;
}
int
xfs_create(
xfs_inode_t *dp,
struct xfs_name *name,
mode_t mode,
xfs_dev_t rdev,
xfs_inode_t **ipp)
{
int is_dir = S_ISDIR(mode);
struct xfs_mount *mp = dp->i_mount;
struct xfs_inode *ip = NULL;
struct xfs_trans *tp = NULL;
int error;
xfs_bmap_free_t free_list;
xfs_fsblock_t first_block;
boolean_t unlock_dp_on_error = B_FALSE;
uint cancel_flags;
int committed;
prid_t prid;
struct xfs_dquot *udqp = NULL;
struct xfs_dquot *gdqp = NULL;
uint resblks;
uint log_res;
uint log_count;
trace_xfs_create(dp, name);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
if (dp->i_d.di_flags & XFS_DIFLAG_PROJINHERIT)
prid = xfs_get_projid(dp);
else
prid = XFS_PROJID_DEFAULT;
error = xfs_qm_vop_dqalloc(dp, current_fsuid(), current_fsgid(), prid,
XFS_QMOPT_QUOTALL | XFS_QMOPT_INHERIT, &udqp, &gdqp);
if (error)
return error;
if (is_dir) {
rdev = 0;
resblks = XFS_MKDIR_SPACE_RES(mp, name->len);
log_res = XFS_MKDIR_LOG_RES(mp);
log_count = XFS_MKDIR_LOG_COUNT;
tp = xfs_trans_alloc(mp, XFS_TRANS_MKDIR);
} else {
resblks = XFS_CREATE_SPACE_RES(mp, name->len);
log_res = XFS_CREATE_LOG_RES(mp);
log_count = XFS_CREATE_LOG_COUNT;
tp = xfs_trans_alloc(mp, XFS_TRANS_CREATE);
}
cancel_flags = XFS_TRANS_RELEASE_LOG_RES;
error = xfs_trans_reserve(tp, resblks, log_res, 0,
XFS_TRANS_PERM_LOG_RES, log_count);
if (error == ENOSPC) {
xfs_flush_inodes(dp);
error = xfs_trans_reserve(tp, resblks, log_res, 0,
XFS_TRANS_PERM_LOG_RES, log_count);
}
if (error == ENOSPC) {
resblks = 0;
error = xfs_trans_reserve(tp, 0, log_res, 0,
XFS_TRANS_PERM_LOG_RES, log_count);
}
if (error) {
cancel_flags = 0;
goto out_trans_cancel;
}
xfs_ilock(dp, XFS_ILOCK_EXCL | XFS_ILOCK_PARENT);
unlock_dp_on_error = B_TRUE;
if (is_dir && dp->i_d.di_nlink >= XFS_MAXLINK) {
error = XFS_ERROR(EMLINK);
goto out_trans_cancel;
}
xfs_bmap_init(&free_list, &first_block);
error = xfs_trans_reserve_quota(tp, mp, udqp, gdqp, resblks, 1, 0);
if (error)
goto out_trans_cancel;
error = xfs_dir_canenter(tp, dp, name, resblks);
if (error)
goto out_trans_cancel;
error = xfs_dir_ialloc(&tp, dp, mode, is_dir ? 2 : 1, rdev,
prid, resblks > 0, &ip, &committed);
if (error) {
if (error == ENOSPC)
goto out_trans_cancel;
goto out_trans_abort;
}
xfs_trans_ijoin_ref(tp, dp, XFS_ILOCK_EXCL);
unlock_dp_on_error = B_FALSE;
error = xfs_dir_createname(tp, dp, name, ip->i_ino,
&first_block, &free_list, resblks ?
resblks - XFS_IALLOC_SPACE_RES(mp) : 0);
if (error) {
ASSERT(error != ENOSPC);
goto out_trans_abort;
}
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
if (is_dir) {
error = xfs_dir_init(tp, ip, dp);
if (error)
goto out_bmap_cancel;
error = xfs_bumplink(tp, dp);
if (error)
goto out_bmap_cancel;
}
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
xfs_qm_vop_create_dqattach(tp, ip, udqp, gdqp);
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto out_release_inode;
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
*ipp = ip;
return 0;
out_bmap_cancel:
xfs_bmap_cancel(&free_list);
out_trans_abort:
cancel_flags |= XFS_TRANS_ABORT;
out_trans_cancel:
xfs_trans_cancel(tp, cancel_flags);
out_release_inode:
if (ip)
IRELE(ip);
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
if (unlock_dp_on_error)
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return error;
}
static inline int
xfs_lock_inumorder(int lock_mode, int subclass)
{
if (lock_mode & (XFS_IOLOCK_SHARED|XFS_IOLOCK_EXCL))
lock_mode |= (subclass + XFS_LOCK_INUMORDER) << XFS_IOLOCK_SHIFT;
if (lock_mode & (XFS_ILOCK_SHARED|XFS_ILOCK_EXCL))
lock_mode |= (subclass + XFS_LOCK_INUMORDER) << XFS_ILOCK_SHIFT;
return lock_mode;
}
void
xfs_lock_inodes(
xfs_inode_t **ips,
int inodes,
uint lock_mode)
{
int attempts = 0, i, j, try_lock;
xfs_log_item_t *lp;
ASSERT(ips && (inodes >= 2));
try_lock = 0;
i = 0;
again:
for (; i < inodes; i++) {
ASSERT(ips[i]);
if (i && (ips[i] == ips[i-1]))
continue;
if (!try_lock) {
for (j = (i - 1); j >= 0 && !try_lock; j--) {
lp = (xfs_log_item_t *)ips[j]->i_itemp;
if (lp && (lp->li_flags & XFS_LI_IN_AIL)) {
try_lock++;
}
}
}
if (try_lock) {
ASSERT(i != 0);
if (!xfs_ilock_nowait(ips[i], xfs_lock_inumorder(lock_mode, i))) {
attempts++;
for(j = i - 1; j >= 0; j--) {
if ((j != (i - 1)) && ips[j] ==
ips[j+1])
continue;
xfs_iunlock(ips[j], lock_mode);
}
if ((attempts % 5) == 0) {
delay(1);
#ifdef DEBUG
xfs_lock_delays++;
#endif
}
i = 0;
try_lock = 0;
goto again;
}
} else {
xfs_ilock(ips[i], xfs_lock_inumorder(lock_mode, i));
}
}
#ifdef DEBUG
if (attempts) {
if (attempts < 5) xfs_small_retries++;
else if (attempts < 100) xfs_middle_retries++;
else xfs_lots_retries++;
} else {
xfs_locked_n++;
}
#endif
}
void
xfs_lock_two_inodes(
xfs_inode_t *ip0,
xfs_inode_t *ip1,
uint lock_mode)
{
xfs_inode_t *temp;
int attempts = 0;
xfs_log_item_t *lp;
if (lock_mode & (XFS_IOLOCK_SHARED|XFS_IOLOCK_EXCL))
ASSERT((lock_mode & (XFS_ILOCK_SHARED|XFS_ILOCK_EXCL)) == 0);
ASSERT(ip0->i_ino != ip1->i_ino);
if (ip0->i_ino > ip1->i_ino) {
temp = ip0;
ip0 = ip1;
ip1 = temp;
}
again:
xfs_ilock(ip0, xfs_lock_inumorder(lock_mode, 0));
lp = (xfs_log_item_t *)ip0->i_itemp;
if (lp && (lp->li_flags & XFS_LI_IN_AIL)) {
if (!xfs_ilock_nowait(ip1, xfs_lock_inumorder(lock_mode, 1))) {
xfs_iunlock(ip0, lock_mode);
if ((++attempts % 5) == 0)
delay(1);
goto again;
}
} else {
xfs_ilock(ip1, xfs_lock_inumorder(lock_mode, 1));
}
}
int
xfs_remove(
xfs_inode_t *dp,
struct xfs_name *name,
xfs_inode_t *ip)
{
xfs_mount_t *mp = dp->i_mount;
xfs_trans_t *tp = NULL;
int is_dir = S_ISDIR(ip->i_d.di_mode);
int error = 0;
xfs_bmap_free_t free_list;
xfs_fsblock_t first_block;
int cancel_flags;
int committed;
int link_zero;
uint resblks;
uint log_count;
trace_xfs_remove(dp, name);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
error = xfs_qm_dqattach(dp, 0);
if (error)
goto std_return;
error = xfs_qm_dqattach(ip, 0);
if (error)
goto std_return;
if (is_dir) {
tp = xfs_trans_alloc(mp, XFS_TRANS_RMDIR);
log_count = XFS_DEFAULT_LOG_COUNT;
} else {
tp = xfs_trans_alloc(mp, XFS_TRANS_REMOVE);
log_count = XFS_REMOVE_LOG_COUNT;
}
cancel_flags = XFS_TRANS_RELEASE_LOG_RES;
resblks = XFS_REMOVE_SPACE_RES(mp);
error = xfs_trans_reserve(tp, resblks, XFS_REMOVE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, log_count);
if (error == ENOSPC) {
resblks = 0;
error = xfs_trans_reserve(tp, 0, XFS_REMOVE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, log_count);
}
if (error) {
ASSERT(error != ENOSPC);
cancel_flags = 0;
goto out_trans_cancel;
}
xfs_lock_two_inodes(dp, ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin_ref(tp, dp, XFS_ILOCK_EXCL);
xfs_trans_ijoin_ref(tp, ip, XFS_ILOCK_EXCL);
if (is_dir) {
ASSERT(ip->i_d.di_nlink >= 2);
if (ip->i_d.di_nlink != 2) {
error = XFS_ERROR(ENOTEMPTY);
goto out_trans_cancel;
}
if (!xfs_dir_isempty(ip)) {
error = XFS_ERROR(ENOTEMPTY);
goto out_trans_cancel;
}
}
xfs_bmap_init(&free_list, &first_block);
error = xfs_dir_removename(tp, dp, name, ip->i_ino,
&first_block, &free_list, resblks);
if (error) {
ASSERT(error != ENOENT);
goto out_bmap_cancel;
}
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
if (is_dir) {
error = xfs_droplink(tp, dp);
if (error)
goto out_bmap_cancel;
error = xfs_droplink(tp, ip);
if (error)
goto out_bmap_cancel;
} else {
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
}
error = xfs_droplink(tp, ip);
if (error)
goto out_bmap_cancel;
link_zero = (ip->i_d.di_nlink == 0);
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto std_return;
if (!is_dir && link_zero && xfs_inode_is_filestream(ip))
xfs_filestream_deassociate(ip);
return 0;
out_bmap_cancel:
xfs_bmap_cancel(&free_list);
cancel_flags |= XFS_TRANS_ABORT;
out_trans_cancel:
xfs_trans_cancel(tp, cancel_flags);
std_return:
return error;
}
int
xfs_link(
xfs_inode_t *tdp,
xfs_inode_t *sip,
struct xfs_name *target_name)
{
xfs_mount_t *mp = tdp->i_mount;
xfs_trans_t *tp;
int error;
xfs_bmap_free_t free_list;
xfs_fsblock_t first_block;
int cancel_flags;
int committed;
int resblks;
trace_xfs_link(tdp, target_name);
ASSERT(!S_ISDIR(sip->i_d.di_mode));
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
error = xfs_qm_dqattach(sip, 0);
if (error)
goto std_return;
error = xfs_qm_dqattach(tdp, 0);
if (error)
goto std_return;
tp = xfs_trans_alloc(mp, XFS_TRANS_LINK);
cancel_flags = XFS_TRANS_RELEASE_LOG_RES;
resblks = XFS_LINK_SPACE_RES(mp, target_name->len);
error = xfs_trans_reserve(tp, resblks, XFS_LINK_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_LINK_LOG_COUNT);
if (error == ENOSPC) {
resblks = 0;
error = xfs_trans_reserve(tp, 0, XFS_LINK_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_LINK_LOG_COUNT);
}
if (error) {
cancel_flags = 0;
goto error_return;
}
xfs_lock_two_inodes(sip, tdp, XFS_ILOCK_EXCL);
xfs_trans_ijoin_ref(tp, sip, XFS_ILOCK_EXCL);
xfs_trans_ijoin_ref(tp, tdp, XFS_ILOCK_EXCL);
if (sip->i_d.di_nlink >= XFS_MAXLINK) {
error = XFS_ERROR(EMLINK);
goto error_return;
}
if (unlikely((tdp->i_d.di_flags & XFS_DIFLAG_PROJINHERIT) &&
(xfs_get_projid(tdp) != xfs_get_projid(sip)))) {
error = XFS_ERROR(EXDEV);
goto error_return;
}
error = xfs_dir_canenter(tp, tdp, target_name, resblks);
if (error)
goto error_return;
xfs_bmap_init(&free_list, &first_block);
error = xfs_dir_createname(tp, tdp, target_name, sip->i_ino,
&first_block, &free_list, resblks);
if (error)
goto abort_return;
xfs_trans_ichgtime(tp, tdp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, tdp, XFS_ILOG_CORE);
error = xfs_bumplink(tp, sip);
if (error)
goto abort_return;
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC)) {
xfs_trans_set_sync(tp);
}
error = xfs_bmap_finish (&tp, &free_list, &committed);
if (error) {
xfs_bmap_cancel(&free_list);
goto abort_return;
}
return xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
abort_return:
cancel_flags |= XFS_TRANS_ABORT;
error_return:
xfs_trans_cancel(tp, cancel_flags);
std_return:
return error;
}
int
xfs_symlink(
xfs_inode_t *dp,
struct xfs_name *link_name,
const char *target_path,
mode_t mode,
xfs_inode_t **ipp)
{
xfs_mount_t *mp = dp->i_mount;
xfs_trans_t *tp;
xfs_inode_t *ip;
int error;
int pathlen;
xfs_bmap_free_t free_list;
xfs_fsblock_t first_block;
boolean_t unlock_dp_on_error = B_FALSE;
uint cancel_flags;
int committed;
xfs_fileoff_t first_fsb;
xfs_filblks_t fs_blocks;
int nmaps;
xfs_bmbt_irec_t mval[SYMLINK_MAPS];
xfs_daddr_t d;
const char *cur_chunk;
int byte_cnt;
int n;
xfs_buf_t *bp;
prid_t prid;
struct xfs_dquot *udqp, *gdqp;
uint resblks;
*ipp = NULL;
error = 0;
ip = NULL;
tp = NULL;
trace_xfs_symlink(dp, link_name);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
pathlen = strlen(target_path);
if (pathlen >= MAXPATHLEN)
return XFS_ERROR(ENAMETOOLONG);
udqp = gdqp = NULL;
if (dp->i_d.di_flags & XFS_DIFLAG_PROJINHERIT)
prid = xfs_get_projid(dp);
else
prid = XFS_PROJID_DEFAULT;
error = xfs_qm_vop_dqalloc(dp, current_fsuid(), current_fsgid(), prid,
XFS_QMOPT_QUOTALL | XFS_QMOPT_INHERIT, &udqp, &gdqp);
if (error)
goto std_return;
tp = xfs_trans_alloc(mp, XFS_TRANS_SYMLINK);
cancel_flags = XFS_TRANS_RELEASE_LOG_RES;
if (pathlen <= XFS_LITINO(mp))
fs_blocks = 0;
else
fs_blocks = XFS_B_TO_FSB(mp, pathlen);
resblks = XFS_SYMLINK_SPACE_RES(mp, link_name->len, fs_blocks);
error = xfs_trans_reserve(tp, resblks, XFS_SYMLINK_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_SYMLINK_LOG_COUNT);
if (error == ENOSPC && fs_blocks == 0) {
resblks = 0;
error = xfs_trans_reserve(tp, 0, XFS_SYMLINK_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES, XFS_SYMLINK_LOG_COUNT);
}
if (error) {
cancel_flags = 0;
goto error_return;
}
xfs_ilock(dp, XFS_ILOCK_EXCL | XFS_ILOCK_PARENT);
unlock_dp_on_error = B_TRUE;
if (dp->i_d.di_flags & XFS_DIFLAG_NOSYMLINKS) {
error = XFS_ERROR(EPERM);
goto error_return;
}
error = xfs_trans_reserve_quota(tp, mp, udqp, gdqp, resblks, 1, 0);
if (error)
goto error_return;
error = xfs_dir_canenter(tp, dp, link_name, resblks);
if (error)
goto error_return;
xfs_bmap_init(&free_list, &first_block);
error = xfs_dir_ialloc(&tp, dp, S_IFLNK | (mode & ~S_IFMT), 1, 0,
prid, resblks > 0, &ip, NULL);
if (error) {
if (error == ENOSPC)
goto error_return;
goto error1;
}
xfs_trans_ijoin_ref(tp, dp, XFS_ILOCK_EXCL);
unlock_dp_on_error = B_FALSE;
xfs_qm_vop_create_dqattach(tp, ip, udqp, gdqp);
if (resblks)
resblks -= XFS_IALLOC_SPACE_RES(mp);
if (pathlen <= XFS_IFORK_DSIZE(ip)) {
xfs_idata_realloc(ip, pathlen, XFS_DATA_FORK);
memcpy(ip->i_df.if_u1.if_data, target_path, pathlen);
ip->i_d.di_size = pathlen;
ip->i_df.if_flags &= ~(XFS_IFEXTENTS | XFS_IFBROOT);
ip->i_df.if_flags |= XFS_IFINLINE;
ip->i_d.di_format = XFS_DINODE_FMT_LOCAL;
xfs_trans_log_inode(tp, ip, XFS_ILOG_DDATA | XFS_ILOG_CORE);
} else {
first_fsb = 0;
nmaps = SYMLINK_MAPS;
error = xfs_bmapi(tp, ip, first_fsb, fs_blocks,
XFS_BMAPI_WRITE | XFS_BMAPI_METADATA,
&first_block, resblks, mval, &nmaps,
&free_list);
if (error)
goto error2;
if (resblks)
resblks -= fs_blocks;
ip->i_d.di_size = pathlen;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
cur_chunk = target_path;
for (n = 0; n < nmaps; n++) {
d = XFS_FSB_TO_DADDR(mp, mval[n].br_startblock);
byte_cnt = XFS_FSB_TO_B(mp, mval[n].br_blockcount);
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp, d,
BTOBB(byte_cnt), 0);
ASSERT(bp && !XFS_BUF_GETERROR(bp));
if (pathlen < byte_cnt) {
byte_cnt = pathlen;
}
pathlen -= byte_cnt;
memcpy(XFS_BUF_PTR(bp), cur_chunk, byte_cnt);
cur_chunk += byte_cnt;
xfs_trans_log_buf(tp, bp, 0, byte_cnt - 1);
}
}
error = xfs_dir_createname(tp, dp, link_name, ip->i_ino,
&first_block, &free_list, resblks);
if (error)
goto error2;
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC)) {
xfs_trans_set_sync(tp);
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error) {
goto error2;
}
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
*ipp = ip;
return 0;
error2:
IRELE(ip);
error1:
xfs_bmap_cancel(&free_list);
cancel_flags |= XFS_TRANS_ABORT;
error_return:
xfs_trans_cancel(tp, cancel_flags);
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
if (unlock_dp_on_error)
xfs_iunlock(dp, XFS_ILOCK_EXCL);
std_return:
return error;
}
int
xfs_set_dmattrs(
xfs_inode_t *ip,
u_int evmask,
u_int16_t state)
{
xfs_mount_t *mp = ip->i_mount;
xfs_trans_t *tp;
int error;
if (!capable(CAP_SYS_ADMIN))
return XFS_ERROR(EPERM);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
tp = xfs_trans_alloc(mp, XFS_TRANS_SET_DMATTRS);
error = xfs_trans_reserve(tp, 0, XFS_ICHANGE_LOG_RES (mp), 0, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin_ref(tp, ip, XFS_ILOCK_EXCL);
ip->i_d.di_dmevmask = evmask;
ip->i_d.di_dmstate = state;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
error = xfs_trans_commit(tp, 0);
return error;
}
STATIC int
xfs_alloc_file_space(
xfs_inode_t *ip,
xfs_off_t offset,
xfs_off_t len,
int alloc_type,
int attr_flags)
{
xfs_mount_t *mp = ip->i_mount;
xfs_off_t count;
xfs_filblks_t allocated_fsb;
xfs_filblks_t allocatesize_fsb;
xfs_extlen_t extsz, temp;
xfs_fileoff_t startoffset_fsb;
xfs_fsblock_t firstfsb;
int nimaps;
int bmapi_flag;
int quota_flag;
int rt;
xfs_trans_t *tp;
xfs_bmbt_irec_t imaps[1], *imapp;
xfs_bmap_free_t free_list;
uint qblocks, resblks, resrtextents;
int committed;
int error;
trace_xfs_alloc_file_space(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
if (len <= 0)
return XFS_ERROR(EINVAL);
rt = XFS_IS_REALTIME_INODE(ip);
extsz = xfs_get_extsz_hint(ip);
count = len;
imapp = &imaps[0];
nimaps = 1;
bmapi_flag = XFS_BMAPI_WRITE | alloc_type;
startoffset_fsb = XFS_B_TO_FSBT(mp, offset);
allocatesize_fsb = XFS_B_TO_FSB(mp, count);
while (allocatesize_fsb && !error) {
xfs_fileoff_t s, e;
if (unlikely(extsz)) {
s = startoffset_fsb;
do_div(s, extsz);
s *= extsz;
e = startoffset_fsb + allocatesize_fsb;
if ((temp = do_mod(startoffset_fsb, extsz)))
e += temp;
if ((temp = do_mod(e, extsz)))
e += extsz - temp;
} else {
s = 0;
e = allocatesize_fsb;
}
resblks = min_t(xfs_fileoff_t, (e - s), (MAXEXTLEN * nimaps));
if (unlikely(rt)) {
resrtextents = qblocks = resblks;
resrtextents /= mp->m_sb.sb_rextsize;
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
quota_flag = XFS_QMOPT_RES_RTBLKS;
} else {
resrtextents = 0;
resblks = qblocks = XFS_DIOSTRAT_SPACE_RES(mp, resblks);
quota_flag = XFS_QMOPT_RES_REGBLKS;
}
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, resblks,
XFS_WRITE_LOG_RES(mp), resrtextents,
XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
if (error) {
ASSERT(error == ENOSPC || XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks,
0, quota_flag);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip);
xfs_bmap_init(&free_list, &firstfsb);
error = xfs_bmapi(tp, ip, startoffset_fsb,
allocatesize_fsb, bmapi_flag,
&firstfsb, 0, imapp, &nimaps,
&free_list);
if (error) {
goto error0;
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error) {
goto error0;
}
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error) {
break;
}
allocated_fsb = imapp->br_blockcount;
if (nimaps == 0) {
error = XFS_ERROR(ENOSPC);
break;
}
startoffset_fsb += allocated_fsb;
allocatesize_fsb -= allocated_fsb;
}
return error;
error0:
xfs_bmap_cancel(&free_list);
xfs_trans_unreserve_quota_nblks(tp, ip, qblocks, 0, quota_flag);
error1:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
STATIC int
xfs_zero_remaining_bytes(
xfs_inode_t *ip,
xfs_off_t startoff,
xfs_off_t endoff)
{
xfs_bmbt_irec_t imap;
xfs_fileoff_t offset_fsb;
xfs_off_t lastoffset;
xfs_off_t offset;
xfs_buf_t *bp;
xfs_mount_t *mp = ip->i_mount;
int nimap;
int error = 0;
if (startoff >= ip->i_size)
return 0;
if (endoff > ip->i_size)
endoff = ip->i_size;
bp = xfs_buf_get_uncached(XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp,
mp->m_sb.sb_blocksize, XBF_DONT_BLOCK);
if (!bp)
return XFS_ERROR(ENOMEM);
for (offset = startoff; offset <= endoff; offset = lastoffset + 1) {
offset_fsb = XFS_B_TO_FSBT(mp, offset);
nimap = 1;
error = xfs_bmapi(NULL, ip, offset_fsb, 1, 0,
NULL, 0, &imap, &nimap, NULL);
if (error || nimap < 1)
break;
ASSERT(imap.br_blockcount >= 1);
ASSERT(imap.br_startoff == offset_fsb);
lastoffset = XFS_FSB_TO_B(mp, imap.br_startoff + 1) - 1;
if (lastoffset > endoff)
lastoffset = endoff;
if (imap.br_startblock == HOLESTARTBLOCK)
continue;
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
if (imap.br_state == XFS_EXT_UNWRITTEN)
continue;
XFS_BUF_UNDONE(bp);
XFS_BUF_UNWRITE(bp);
XFS_BUF_READ(bp);
XFS_BUF_SET_ADDR(bp, xfs_fsb_to_db(ip, imap.br_startblock));
xfsbdstrat(mp, bp);
error = xfs_buf_iowait(bp);
if (error) {
xfs_ioerror_alert("xfs_zero_remaining_bytes(read)",
mp, bp, XFS_BUF_ADDR(bp));
break;
}
memset(XFS_BUF_PTR(bp) +
(offset - XFS_FSB_TO_B(mp, imap.br_startoff)),
0, lastoffset - offset + 1);
XFS_BUF_UNDONE(bp);
XFS_BUF_UNREAD(bp);
XFS_BUF_WRITE(bp);
xfsbdstrat(mp, bp);
error = xfs_buf_iowait(bp);
if (error) {
xfs_ioerror_alert("xfs_zero_remaining_bytes(write)",
mp, bp, XFS_BUF_ADDR(bp));
break;
}
}
xfs_buf_free(bp);
return error;
}
STATIC int
xfs_free_file_space(
xfs_inode_t *ip,
xfs_off_t offset,
xfs_off_t len,
int attr_flags)
{
int committed;
int done;
xfs_fileoff_t endoffset_fsb;
int error;
xfs_fsblock_t firstfsb;
xfs_bmap_free_t free_list;
xfs_bmbt_irec_t imap;
xfs_off_t ioffset;
xfs_extlen_t mod=0;
xfs_mount_t *mp;
int nimap;
uint resblks;
uint rounding;
int rt;
xfs_fileoff_t startoffset_fsb;
xfs_trans_t *tp;
int need_iolock = 1;
mp = ip->i_mount;
trace_xfs_free_file_space(ip);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
error = 0;
if (len <= 0)
return error;
rt = XFS_IS_REALTIME_INODE(ip);
startoffset_fsb = XFS_B_TO_FSB(mp, offset);
endoffset_fsb = XFS_B_TO_FSBT(mp, offset + len);
if (attr_flags & XFS_ATTR_NOLOCK)
need_iolock = 0;
if (need_iolock) {
xfs_ilock(ip, XFS_IOLOCK_EXCL);
xfs_ioend_wait(ip);
}
rounding = max_t(uint, 1 << mp->m_sb.sb_blocklog, PAGE_CACHE_SIZE);
ioffset = offset & ~(rounding - 1);
if (VN_CACHED(VFS_I(ip)) != 0) {
error = xfs_flushinval_pages(ip, ioffset, -1, FI_REMAPF_LOCKED);
if (error)
goto out_unlock_iolock;
}
if (rt && !xfs_sb_version_hasextflgbit(&mp->m_sb)) {
nimap = 1;
error = xfs_bmapi(NULL, ip, startoffset_fsb,
1, 0, NULL, 0, &imap, &nimap, NULL);
if (error)
goto out_unlock_iolock;
ASSERT(nimap == 0 || nimap == 1);
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
xfs_daddr_t block;
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
block = imap.br_startblock;
mod = do_div(block, mp->m_sb.sb_rextsize);
if (mod)
startoffset_fsb += mp->m_sb.sb_rextsize - mod;
}
nimap = 1;
error = xfs_bmapi(NULL, ip, endoffset_fsb - 1,
1, 0, NULL, 0, &imap, &nimap, NULL);
if (error)
goto out_unlock_iolock;
ASSERT(nimap == 0 || nimap == 1);
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
mod++;
if (mod && (mod != mp->m_sb.sb_rextsize))
endoffset_fsb -= mod;
}
}
if ((done = (endoffset_fsb <= startoffset_fsb)))
error = xfs_zero_remaining_bytes(ip, offset, offset + len - 1);
else {
if (offset < XFS_FSB_TO_B(mp, startoffset_fsb))
error = xfs_zero_remaining_bytes(ip, offset,
XFS_FSB_TO_B(mp, startoffset_fsb) - 1);
if (!error &&
XFS_FSB_TO_B(mp, endoffset_fsb) < offset + len)
error = xfs_zero_remaining_bytes(ip,
XFS_FSB_TO_B(mp, endoffset_fsb),
offset + len - 1);
}
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
while (!error && !done) {
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
tp->t_flags |= XFS_TRANS_RESERVE;
error = xfs_trans_reserve(tp,
resblks,
XFS_WRITE_LOG_RES(mp),
0,
XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
if (error) {
ASSERT(error == ENOSPC || XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota(tp, mp,
ip->i_udquot, ip->i_gdquot,
resblks, 0, XFS_QMOPT_RES_REGBLKS);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip);
xfs_bmap_init(&free_list, &firstfsb);
error = xfs_bunmapi(tp, ip, startoffset_fsb,
endoffset_fsb - startoffset_fsb,
0, 2, &firstfsb, &free_list, &done);
if (error) {
goto error0;
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error) {
goto error0;
}
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
out_unlock_iolock:
if (need_iolock)
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
error0:
xfs_bmap_cancel(&free_list);
error1:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, need_iolock ? (XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL) :
XFS_ILOCK_EXCL);
return error;
}
int
xfs_change_file_space(
xfs_inode_t *ip,
int cmd,
xfs_flock64_t *bf,
xfs_off_t offset,
int attr_flags)
{
xfs_mount_t *mp = ip->i_mount;
int clrprealloc;
int error;
xfs_fsize_t fsize;
int setprealloc;
xfs_off_t startoffset;
xfs_off_t llen;
xfs_trans_t *tp;
struct iattr iattr;
int prealloc_type;
if (!S_ISREG(ip->i_d.di_mode))
return XFS_ERROR(EINVAL);
switch (bf->l_whence) {
case 0:
break;
case 1:
bf->l_start += offset;
break;
case 2:
bf->l_start += ip->i_size;
break;
default:
return XFS_ERROR(EINVAL);
}
llen = bf->l_len > 0 ? bf->l_len - 1 : bf->l_len;
if ( (bf->l_start < 0)
|| (bf->l_start > XFS_MAXIOFFSET(mp))
|| (bf->l_start + llen < 0)
|| (bf->l_start + llen > XFS_MAXIOFFSET(mp)))
return XFS_ERROR(EINVAL);
bf->l_whence = 0;
startoffset = bf->l_start;
fsize = ip->i_size;
setprealloc = clrprealloc = 0;
prealloc_type = XFS_BMAPI_PREALLOC;
switch (cmd) {
case XFS_IOC_ZERO_RANGE:
prealloc_type |= XFS_BMAPI_CONVERT;
xfs_tosspages(ip, startoffset, startoffset + bf->l_len, 0);
case XFS_IOC_RESVSP:
case XFS_IOC_RESVSP64:
error = xfs_alloc_file_space(ip, startoffset, bf->l_len,
prealloc_type, attr_flags);
if (error)
return error;
setprealloc = 1;
break;
case XFS_IOC_UNRESVSP:
case XFS_IOC_UNRESVSP64:
if ((error = xfs_free_file_space(ip, startoffset, bf->l_len,
attr_flags)))
return error;
break;
case XFS_IOC_ALLOCSP:
case XFS_IOC_ALLOCSP64:
case XFS_IOC_FREESP:
case XFS_IOC_FREESP64:
if (startoffset > fsize) {
error = xfs_alloc_file_space(ip, fsize,
startoffset - fsize, 0, attr_flags);
if (error)
break;
}
iattr.ia_valid = ATTR_SIZE;
iattr.ia_size = startoffset;
error = xfs_setattr(ip, &iattr, attr_flags);
if (error)
return error;
clrprealloc = 1;
break;
default:
ASSERT(0);
return XFS_ERROR(EINVAL);
}
tp = xfs_trans_alloc(mp, XFS_TRANS_WRITEID);
if ((error = xfs_trans_reserve(tp, 0, XFS_WRITEID_LOG_RES(mp),
0, 0, 0))) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
if ((attr_flags & XFS_ATTR_DMI) == 0) {
ip->i_d.di_mode &= ~S_ISUID;
if (ip->i_d.di_mode & S_IXGRP)
ip->i_d.di_mode &= ~S_ISGID;
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
}
if (setprealloc)
ip->i_d.di_flags |= XFS_DIFLAG_PREALLOC;
else if (clrprealloc)
ip->i_d.di_flags &= ~XFS_DIFLAG_PREALLOC;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (attr_flags & XFS_ATTR_SYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
