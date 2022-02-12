STATIC int
xfs_readlink_bmap(
struct xfs_inode *ip,
char *link)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_bmbt_irec mval[XFS_SYMLINK_MAPS];
struct xfs_buf *bp;
xfs_daddr_t d;
char *cur_chunk;
int pathlen = ip->i_d.di_size;
int nmaps = XFS_SYMLINK_MAPS;
int byte_cnt;
int n;
int error = 0;
int fsblocks = 0;
int offset;
fsblocks = xfs_symlink_blocks(mp, pathlen);
error = xfs_bmapi_read(ip, 0, fsblocks, mval, &nmaps, 0);
if (error)
goto out;
offset = 0;
for (n = 0; n < nmaps; n++) {
d = XFS_FSB_TO_DADDR(mp, mval[n].br_startblock);
byte_cnt = XFS_FSB_TO_B(mp, mval[n].br_blockcount);
bp = xfs_buf_read(mp->m_ddev_targp, d, BTOBB(byte_cnt), 0,
&xfs_symlink_buf_ops);
if (!bp)
return -ENOMEM;
error = bp->b_error;
if (error) {
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
if (error == -EFSBADCRC)
error = -EFSCORRUPTED;
goto out;
}
byte_cnt = XFS_SYMLINK_BUF_SPACE(mp, byte_cnt);
if (pathlen < byte_cnt)
byte_cnt = pathlen;
cur_chunk = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (!xfs_symlink_hdr_ok(ip->i_ino, offset,
byte_cnt, bp)) {
error = -EFSCORRUPTED;
xfs_alert(mp,
"symlink header does not match required off/len/owner (0x%x/Ox%x,0x%llx)",
offset, byte_cnt, ip->i_ino);
xfs_buf_relse(bp);
goto out;
}
cur_chunk += sizeof(struct xfs_dsymlink_hdr);
}
memcpy(link + offset, bp->b_addr, byte_cnt);
pathlen -= byte_cnt;
offset += byte_cnt;
xfs_buf_relse(bp);
}
ASSERT(pathlen == 0);
link[ip->i_d.di_size] = '\0';
error = 0;
out:
return error;
}
int
xfs_readlink(
struct xfs_inode *ip,
char *link)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fsize_t pathlen;
int error = 0;
trace_xfs_readlink(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_ilock(ip, XFS_ILOCK_SHARED);
pathlen = ip->i_d.di_size;
if (!pathlen)
goto out;
if (pathlen < 0 || pathlen > MAXPATHLEN) {
xfs_alert(mp, "%s: inode (%llu) bad symlink length (%lld)",
__func__, (unsigned long long) ip->i_ino,
(long long) pathlen);
ASSERT(0);
error = -EFSCORRUPTED;
goto out;
}
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
int
xfs_symlink(
struct xfs_inode *dp,
struct xfs_name *link_name,
const char *target_path,
umode_t mode,
struct xfs_inode **ipp)
{
struct xfs_mount *mp = dp->i_mount;
struct xfs_trans *tp = NULL;
struct xfs_inode *ip = NULL;
int error = 0;
int pathlen;
struct xfs_bmap_free free_list;
xfs_fsblock_t first_block;
bool unlock_dp_on_error = false;
uint cancel_flags;
int committed;
xfs_fileoff_t first_fsb;
xfs_filblks_t fs_blocks;
int nmaps;
struct xfs_bmbt_irec mval[XFS_SYMLINK_MAPS];
xfs_daddr_t d;
const char *cur_chunk;
int byte_cnt;
int n;
xfs_buf_t *bp;
prid_t prid;
struct xfs_dquot *udqp = NULL;
struct xfs_dquot *gdqp = NULL;
struct xfs_dquot *pdqp = NULL;
uint resblks;
*ipp = NULL;
trace_xfs_symlink(dp, link_name);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
pathlen = strlen(target_path);
if (pathlen >= MAXPATHLEN)
return -ENAMETOOLONG;
udqp = gdqp = NULL;
prid = xfs_get_initial_prid(dp);
error = xfs_qm_vop_dqalloc(dp,
xfs_kuid_to_uid(current_fsuid()),
xfs_kgid_to_gid(current_fsgid()), prid,
XFS_QMOPT_QUOTALL | XFS_QMOPT_INHERIT,
&udqp, &gdqp, &pdqp);
if (error)
return error;
tp = xfs_trans_alloc(mp, XFS_TRANS_SYMLINK);
cancel_flags = XFS_TRANS_RELEASE_LOG_RES;
if (pathlen <= XFS_LITINO(mp, dp->i_d.di_version))
fs_blocks = 0;
else
fs_blocks = xfs_symlink_blocks(mp, pathlen);
resblks = XFS_SYMLINK_SPACE_RES(mp, link_name->len, fs_blocks);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_symlink, resblks, 0);
if (error == -ENOSPC && fs_blocks == 0) {
resblks = 0;
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_symlink, 0, 0);
}
if (error) {
cancel_flags = 0;
goto out_trans_cancel;
}
xfs_ilock(dp, XFS_ILOCK_EXCL | XFS_ILOCK_PARENT);
unlock_dp_on_error = true;
if (dp->i_d.di_flags & XFS_DIFLAG_NOSYMLINKS) {
error = -EPERM;
goto out_trans_cancel;
}
error = xfs_trans_reserve_quota(tp, mp, udqp, gdqp,
pdqp, resblks, 1, 0);
if (error)
goto out_trans_cancel;
if (!resblks) {
error = xfs_dir_canenter(tp, dp, link_name);
if (error)
goto out_trans_cancel;
}
xfs_bmap_init(&free_list, &first_block);
error = xfs_dir_ialloc(&tp, dp, S_IFLNK | (mode & ~S_IFMT), 1, 0,
prid, resblks > 0, &ip, NULL);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, dp, XFS_ILOCK_EXCL);
unlock_dp_on_error = false;
xfs_qm_vop_create_dqattach(tp, ip, udqp, gdqp, pdqp);
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
int offset;
first_fsb = 0;
nmaps = XFS_SYMLINK_MAPS;
error = xfs_bmapi_write(tp, ip, first_fsb, fs_blocks,
XFS_BMAPI_METADATA, &first_block, resblks,
mval, &nmaps, &free_list);
if (error)
goto out_bmap_cancel;
if (resblks)
resblks -= fs_blocks;
ip->i_d.di_size = pathlen;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
cur_chunk = target_path;
offset = 0;
for (n = 0; n < nmaps; n++) {
char *buf;
d = XFS_FSB_TO_DADDR(mp, mval[n].br_startblock);
byte_cnt = XFS_FSB_TO_B(mp, mval[n].br_blockcount);
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp, d,
BTOBB(byte_cnt), 0);
if (!bp) {
error = -ENOMEM;
goto out_bmap_cancel;
}
bp->b_ops = &xfs_symlink_buf_ops;
byte_cnt = XFS_SYMLINK_BUF_SPACE(mp, byte_cnt);
byte_cnt = min(byte_cnt, pathlen);
buf = bp->b_addr;
buf += xfs_symlink_hdr_set(mp, ip->i_ino, offset,
byte_cnt, bp);
memcpy(buf, cur_chunk, byte_cnt);
cur_chunk += byte_cnt;
pathlen -= byte_cnt;
offset += byte_cnt;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_SYMLINK_BUF);
xfs_trans_log_buf(tp, bp, 0, (buf + byte_cnt - 1) -
(char *)bp->b_addr);
}
ASSERT(pathlen == 0);
}
error = xfs_dir_createname(tp, dp, link_name, ip->i_ino,
&first_block, &free_list, resblks);
if (error)
goto out_bmap_cancel;
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC)) {
xfs_trans_set_sync(tp);
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto out_release_inode;
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
*ipp = ip;
return 0;
out_bmap_cancel:
xfs_bmap_cancel(&free_list);
cancel_flags |= XFS_TRANS_ABORT;
out_trans_cancel:
xfs_trans_cancel(tp, cancel_flags);
out_release_inode:
if (ip) {
xfs_finish_inode_setup(ip);
IRELE(ip);
}
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
if (unlock_dp_on_error)
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return error;
}
STATIC int
xfs_inactive_symlink_rmt(
struct xfs_inode *ip)
{
xfs_buf_t *bp;
int committed;
int done;
int error;
xfs_fsblock_t first_block;
xfs_bmap_free_t free_list;
int i;
xfs_mount_t *mp;
xfs_bmbt_irec_t mval[XFS_SYMLINK_MAPS];
int nmaps;
int size;
xfs_trans_t *tp;
mp = ip->i_mount;
ASSERT(ip->i_df.if_flags & XFS_IFEXTENTS);
ASSERT(ip->i_d.di_nextents > 0 && ip->i_d.di_nextents <= 2);
tp = xfs_trans_alloc(mp, XFS_TRANS_INACTIVE);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_itruncate, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
size = (int)ip->i_d.di_size;
ip->i_d.di_size = 0;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
done = 0;
xfs_bmap_init(&free_list, &first_block);
nmaps = ARRAY_SIZE(mval);
error = xfs_bmapi_read(ip, 0, xfs_symlink_blocks(mp, size),
mval, &nmaps, 0);
if (error)
goto error_trans_cancel;
for (i = 0; i < nmaps; i++) {
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, mval[i].br_startblock),
XFS_FSB_TO_BB(mp, mval[i].br_blockcount), 0);
if (!bp) {
error = -ENOMEM;
goto error_bmap_cancel;
}
xfs_trans_binval(tp, bp);
}
error = xfs_bunmapi(tp, ip, 0, size, XFS_BMAPI_METADATA, nmaps,
&first_block, &free_list, &done);
if (error)
goto error_bmap_cancel;
ASSERT(done);
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto error_bmap_cancel;
ASSERT(committed);
xfs_trans_ijoin(tp, ip, 0);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
goto error_unlock;
}
if (ip->i_df.if_bytes)
xfs_idata_realloc(ip, -ip->i_df.if_bytes, XFS_DATA_FORK);
ASSERT(ip->i_df.if_bytes == 0);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
error_bmap_cancel:
xfs_bmap_cancel(&free_list);
error_trans_cancel:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
error_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_inactive_symlink(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
int pathlen;
trace_xfs_inactive_symlink(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_ilock(ip, XFS_ILOCK_EXCL);
pathlen = (int)ip->i_d.di_size;
if (!pathlen) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
}
if (pathlen < 0 || pathlen > MAXPATHLEN) {
xfs_alert(mp, "%s: inode (0x%llx) bad symlink length (%d)",
__func__, (unsigned long long)ip->i_ino, pathlen);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
ASSERT(0);
return -EFSCORRUPTED;
}
if (ip->i_df.if_flags & XFS_IFINLINE) {
if (ip->i_df.if_bytes > 0)
xfs_idata_realloc(ip, -(ip->i_df.if_bytes),
XFS_DATA_FORK);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
ASSERT(ip->i_df.if_bytes == 0);
return 0;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return xfs_inactive_symlink_rmt(ip);
}
