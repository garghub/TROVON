int
xfs_symlink_blocks(
struct xfs_mount *mp,
int pathlen)
{
int buflen = XFS_SYMLINK_BUF_SPACE(mp, mp->m_sb.sb_blocksize);
return (pathlen + buflen - 1) / buflen;
}
static int
xfs_symlink_hdr_set(
struct xfs_mount *mp,
xfs_ino_t ino,
uint32_t offset,
uint32_t size,
struct xfs_buf *bp)
{
struct xfs_dsymlink_hdr *dsl = bp->b_addr;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return 0;
dsl->sl_magic = cpu_to_be32(XFS_SYMLINK_MAGIC);
dsl->sl_offset = cpu_to_be32(offset);
dsl->sl_bytes = cpu_to_be32(size);
uuid_copy(&dsl->sl_uuid, &mp->m_sb.sb_uuid);
dsl->sl_owner = cpu_to_be64(ino);
dsl->sl_blkno = cpu_to_be64(bp->b_bn);
bp->b_ops = &xfs_symlink_buf_ops;
return sizeof(struct xfs_dsymlink_hdr);
}
bool
xfs_symlink_hdr_ok(
struct xfs_mount *mp,
xfs_ino_t ino,
uint32_t offset,
uint32_t size,
struct xfs_buf *bp)
{
struct xfs_dsymlink_hdr *dsl = bp->b_addr;
if (offset != be32_to_cpu(dsl->sl_offset))
return false;
if (size != be32_to_cpu(dsl->sl_bytes))
return false;
if (ino != be64_to_cpu(dsl->sl_owner))
return false;
return true;
}
static bool
xfs_symlink_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dsymlink_hdr *dsl = bp->b_addr;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return false;
if (dsl->sl_magic != cpu_to_be32(XFS_SYMLINK_MAGIC))
return false;
if (!uuid_equal(&dsl->sl_uuid, &mp->m_sb.sb_uuid))
return false;
if (bp->b_bn != be64_to_cpu(dsl->sl_blkno))
return false;
if (be32_to_cpu(dsl->sl_offset) +
be32_to_cpu(dsl->sl_bytes) >= MAXPATHLEN)
return false;
if (dsl->sl_owner == 0)
return false;
return true;
}
static void
xfs_symlink_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (!xfs_verify_cksum(bp->b_addr, BBTOB(bp->b_length),
offsetof(struct xfs_dsymlink_hdr, sl_crc)) ||
!xfs_symlink_verify(bp)) {
XFS_CORRUPTION_ERROR(__func__, XFS_ERRLEVEL_LOW, mp, bp->b_addr);
xfs_buf_ioerror(bp, EFSCORRUPTED);
}
}
static void
xfs_symlink_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (!xfs_symlink_verify(bp)) {
XFS_CORRUPTION_ERROR(__func__, XFS_ERRLEVEL_LOW, mp, bp->b_addr);
xfs_buf_ioerror(bp, EFSCORRUPTED);
return;
}
if (bip) {
struct xfs_dsymlink_hdr *dsl = bp->b_addr;
dsl->sl_lsn = cpu_to_be64(bip->bli_item.li_lsn);
}
xfs_update_cksum(bp->b_addr, BBTOB(bp->b_length),
offsetof(struct xfs_dsymlink_hdr, sl_crc));
}
void
xfs_symlink_local_to_remote(
struct xfs_trans *tp,
struct xfs_buf *bp,
struct xfs_inode *ip,
struct xfs_ifork *ifp)
{
struct xfs_mount *mp = ip->i_mount;
char *buf;
if (!xfs_sb_version_hascrc(&mp->m_sb)) {
bp->b_ops = NULL;
memcpy(bp->b_addr, ifp->if_u1.if_data, ifp->if_bytes);
return;
}
ASSERT(BBTOB(bp->b_length) >=
ifp->if_bytes + sizeof(struct xfs_dsymlink_hdr));
bp->b_ops = &xfs_symlink_buf_ops;
buf = bp->b_addr;
buf += xfs_symlink_hdr_set(mp, ip->i_ino, 0, ifp->if_bytes, bp);
memcpy(buf, ifp->if_u1.if_data, ifp->if_bytes);
}
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
return XFS_ERROR(ENOMEM);
error = bp->b_error;
if (error) {
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
goto out;
}
byte_cnt = XFS_SYMLINK_BUF_SPACE(mp, byte_cnt);
if (pathlen < byte_cnt)
byte_cnt = pathlen;
cur_chunk = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (!xfs_symlink_hdr_ok(mp, ip->i_ino, offset,
byte_cnt, bp)) {
error = EFSCORRUPTED;
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
return XFS_ERROR(EIO);
xfs_ilock(ip, XFS_ILOCK_SHARED);
pathlen = ip->i_d.di_size;
if (!pathlen)
goto out;
if (pathlen < 0 || pathlen > MAXPATHLEN) {
xfs_alert(mp, "%s: inode (%llu) bad symlink length (%lld)",
__func__, (unsigned long long) ip->i_ino,
(long long) pathlen);
ASSERT(0);
error = XFS_ERROR(EFSCORRUPTED);
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
struct xfs_dquot *udqp, *gdqp;
uint resblks;
*ipp = NULL;
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
if (pathlen <= XFS_LITINO(mp, dp->i_d.di_version))
fs_blocks = 0;
else
fs_blocks = xfs_symlink_blocks(mp, pathlen);
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
unlock_dp_on_error = true;
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
xfs_trans_ijoin(tp, dp, XFS_ILOCK_EXCL);
unlock_dp_on_error = false;
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
int offset;
first_fsb = 0;
nmaps = XFS_SYMLINK_MAPS;
error = xfs_bmapi_write(tp, ip, first_fsb, fs_blocks,
XFS_BMAPI_METADATA, &first_block, resblks,
mval, &nmaps, &free_list);
if (error)
goto error2;
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
error = ENOMEM;
goto error2;
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
xfs_trans_log_buf(tp, bp, 0, (buf + byte_cnt - 1) -
(char *)bp->b_addr);
}
ASSERT(pathlen == 0);
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
xfs_bmbt_irec_t mval[XFS_SYMLINK_MAPS];
int nmaps;
xfs_trans_t *ntp;
int size;
xfs_trans_t *tp;
tp = *tpp;
mp = ip->i_mount;
ASSERT(ip->i_d.di_size > XFS_IFORK_DSIZE(ip));
ASSERT(ip->i_d.di_nextents > 0 && ip->i_d.di_nextents <= 2);
size = (int)ip->i_d.di_size;
ip->i_d.di_size = 0;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
done = 0;
xfs_bmap_init(&free_list, &first_block);
nmaps = ARRAY_SIZE(mval);
error = xfs_bmapi_read(ip, 0, xfs_symlink_blocks(mp, size),
mval, &nmaps, 0);
if (error)
goto error0;
for (i = 0; i < nmaps; i++) {
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, mval[i].br_startblock),
XFS_FSB_TO_BB(mp, mval[i].br_blockcount), 0);
if (!bp) {
error = ENOMEM;
goto error1;
}
xfs_trans_binval(tp, bp);
}
if ((error = xfs_bunmapi(tp, ip, 0, size, XFS_BMAPI_METADATA, nmaps,
&first_block, &free_list, &done)))
goto error1;
ASSERT(done);
if ((error = xfs_bmap_finish(&tp, &free_list, &committed)))
goto error1;
ASSERT(committed);
xfs_trans_ijoin(tp, ip, 0);
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
xfs_trans_ijoin(tp, ip, 0);
*tpp = tp;
return 0;
error1:
xfs_bmap_cancel(&free_list);
error0:
return error;
}
