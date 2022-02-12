int
xfs_symlink_blocks(
struct xfs_mount *mp,
int pathlen)
{
int buflen = XFS_SYMLINK_BUF_SPACE(mp, mp->m_sb.sb_blocksize);
return (pathlen + buflen - 1) / buflen;
}
int
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
memset(dsl, 0, sizeof(struct xfs_dsymlink_hdr));
dsl->sl_magic = cpu_to_be32(XFS_SYMLINK_MAGIC);
dsl->sl_offset = cpu_to_be32(offset);
dsl->sl_bytes = cpu_to_be32(size);
uuid_copy(&dsl->sl_uuid, &mp->m_sb.sb_meta_uuid);
dsl->sl_owner = cpu_to_be64(ino);
dsl->sl_blkno = cpu_to_be64(bp->b_bn);
bp->b_ops = &xfs_symlink_buf_ops;
return sizeof(struct xfs_dsymlink_hdr);
}
bool
xfs_symlink_hdr_ok(
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
if (!uuid_equal(&dsl->sl_uuid, &mp->m_sb.sb_meta_uuid))
return false;
if (bp->b_bn != be64_to_cpu(dsl->sl_blkno))
return false;
if (be32_to_cpu(dsl->sl_offset) +
be32_to_cpu(dsl->sl_bytes) >= MAXPATHLEN)
return false;
if (dsl->sl_owner == 0)
return false;
if (!xfs_log_check_lsn(mp, be64_to_cpu(dsl->sl_lsn)))
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
if (!xfs_buf_verify_cksum(bp, XFS_SYMLINK_CRC_OFF))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_symlink_verify(bp))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
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
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (bip) {
struct xfs_dsymlink_hdr *dsl = bp->b_addr;
dsl->sl_lsn = cpu_to_be64(bip->bli_item.li_lsn);
}
xfs_buf_update_cksum(bp, XFS_SYMLINK_CRC_OFF);
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
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_SYMLINK_BUF);
if (!xfs_sb_version_hascrc(&mp->m_sb)) {
bp->b_ops = NULL;
memcpy(bp->b_addr, ifp->if_u1.if_data, ifp->if_bytes);
xfs_trans_log_buf(tp, bp, 0, ifp->if_bytes - 1);
return;
}
ASSERT(BBTOB(bp->b_length) >=
ifp->if_bytes + sizeof(struct xfs_dsymlink_hdr));
bp->b_ops = &xfs_symlink_buf_ops;
buf = bp->b_addr;
buf += xfs_symlink_hdr_set(mp, ip->i_ino, 0, ifp->if_bytes, bp);
memcpy(buf, ifp->if_u1.if_data, ifp->if_bytes);
xfs_trans_log_buf(tp, bp, 0, sizeof(struct xfs_dsymlink_hdr) +
ifp->if_bytes - 1);
}
