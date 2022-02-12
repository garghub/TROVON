void
xfs_inobp_check(
xfs_mount_t *mp,
xfs_buf_t *bp)
{
int i;
int j;
xfs_dinode_t *dip;
j = mp->m_inode_cluster_size >> mp->m_sb.sb_inodelog;
for (i = 0; i < j; i++) {
dip = xfs_buf_offset(bp, i * mp->m_sb.sb_inodesize);
if (!dip->di_next_unlinked) {
xfs_alert(mp,
"Detected bogus zero next_unlinked field in inode %d buffer 0x%llx.",
i, (long long)bp->b_bn);
}
}
}
bool
xfs_dinode_good_version(
struct xfs_mount *mp,
__u8 version)
{
if (xfs_sb_version_hascrc(&mp->m_sb))
return version == 3;
return version == 1 || version == 2;
}
static void
xfs_inode_buf_verify(
struct xfs_buf *bp,
bool readahead)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
int i;
int ni;
ni = XFS_BB_TO_FSB(mp, bp->b_length) * mp->m_sb.sb_inopblock;
for (i = 0; i < ni; i++) {
int di_ok;
xfs_dinode_t *dip;
dip = xfs_buf_offset(bp, (i << mp->m_sb.sb_inodelog));
di_ok = dip->di_magic == cpu_to_be16(XFS_DINODE_MAGIC) &&
xfs_dinode_good_version(mp, dip->di_version);
if (unlikely(XFS_TEST_ERROR(!di_ok, mp,
XFS_ERRTAG_ITOBP_INOTOBP,
XFS_RANDOM_ITOBP_INOTOBP))) {
if (readahead) {
bp->b_flags &= ~XBF_DONE;
xfs_buf_ioerror(bp, -EIO);
return;
}
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
#ifdef DEBUG
xfs_alert(mp,
"bad inode magic/vsn daddr %lld #%d (magic=%x)",
(unsigned long long)bp->b_bn, i,
be16_to_cpu(dip->di_magic));
#endif
}
}
xfs_inobp_check(mp, bp);
}
static void
xfs_inode_buf_read_verify(
struct xfs_buf *bp)
{
xfs_inode_buf_verify(bp, false);
}
static void
xfs_inode_buf_readahead_verify(
struct xfs_buf *bp)
{
xfs_inode_buf_verify(bp, true);
}
static void
xfs_inode_buf_write_verify(
struct xfs_buf *bp)
{
xfs_inode_buf_verify(bp, false);
}
int
xfs_imap_to_bp(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_imap *imap,
struct xfs_dinode **dipp,
struct xfs_buf **bpp,
uint buf_flags,
uint iget_flags)
{
struct xfs_buf *bp;
int error;
buf_flags |= XBF_UNMAPPED;
error = xfs_trans_read_buf(mp, tp, mp->m_ddev_targp, imap->im_blkno,
(int)imap->im_len, buf_flags, &bp,
&xfs_inode_buf_ops);
if (error) {
if (error == -EAGAIN) {
ASSERT(buf_flags & XBF_TRYLOCK);
return error;
}
if (error == -EFSCORRUPTED &&
(iget_flags & XFS_IGET_UNTRUSTED))
return -EINVAL;
xfs_warn(mp, "%s: xfs_trans_read_buf() returned error %d.",
__func__, error);
return error;
}
*bpp = bp;
*dipp = xfs_buf_offset(bp, imap->im_boffset);
return 0;
}
void
xfs_inode_from_disk(
struct xfs_inode *ip,
struct xfs_dinode *from)
{
struct xfs_icdinode *to = &ip->i_d;
struct inode *inode = VFS_I(ip);
to->di_version = from->di_version;
if (to->di_version == 1) {
set_nlink(inode, be16_to_cpu(from->di_onlink));
to->di_projid_lo = 0;
to->di_projid_hi = 0;
to->di_version = 2;
} else {
set_nlink(inode, be32_to_cpu(from->di_nlink));
to->di_projid_lo = be16_to_cpu(from->di_projid_lo);
to->di_projid_hi = be16_to_cpu(from->di_projid_hi);
}
to->di_format = from->di_format;
to->di_uid = be32_to_cpu(from->di_uid);
to->di_gid = be32_to_cpu(from->di_gid);
to->di_flushiter = be16_to_cpu(from->di_flushiter);
inode->i_atime.tv_sec = (int)be32_to_cpu(from->di_atime.t_sec);
inode->i_atime.tv_nsec = (int)be32_to_cpu(from->di_atime.t_nsec);
inode->i_mtime.tv_sec = (int)be32_to_cpu(from->di_mtime.t_sec);
inode->i_mtime.tv_nsec = (int)be32_to_cpu(from->di_mtime.t_nsec);
inode->i_ctime.tv_sec = (int)be32_to_cpu(from->di_ctime.t_sec);
inode->i_ctime.tv_nsec = (int)be32_to_cpu(from->di_ctime.t_nsec);
inode->i_generation = be32_to_cpu(from->di_gen);
inode->i_mode = be16_to_cpu(from->di_mode);
to->di_size = be64_to_cpu(from->di_size);
to->di_nblocks = be64_to_cpu(from->di_nblocks);
to->di_extsize = be32_to_cpu(from->di_extsize);
to->di_nextents = be32_to_cpu(from->di_nextents);
to->di_anextents = be16_to_cpu(from->di_anextents);
to->di_forkoff = from->di_forkoff;
to->di_aformat = from->di_aformat;
to->di_dmevmask = be32_to_cpu(from->di_dmevmask);
to->di_dmstate = be16_to_cpu(from->di_dmstate);
to->di_flags = be16_to_cpu(from->di_flags);
if (to->di_version == 3) {
inode->i_version = be64_to_cpu(from->di_changecount);
to->di_crtime.t_sec = be32_to_cpu(from->di_crtime.t_sec);
to->di_crtime.t_nsec = be32_to_cpu(from->di_crtime.t_nsec);
to->di_flags2 = be64_to_cpu(from->di_flags2);
to->di_cowextsize = be32_to_cpu(from->di_cowextsize);
}
}
void
xfs_inode_to_disk(
struct xfs_inode *ip,
struct xfs_dinode *to,
xfs_lsn_t lsn)
{
struct xfs_icdinode *from = &ip->i_d;
struct inode *inode = VFS_I(ip);
to->di_magic = cpu_to_be16(XFS_DINODE_MAGIC);
to->di_onlink = 0;
to->di_version = from->di_version;
to->di_format = from->di_format;
to->di_uid = cpu_to_be32(from->di_uid);
to->di_gid = cpu_to_be32(from->di_gid);
to->di_projid_lo = cpu_to_be16(from->di_projid_lo);
to->di_projid_hi = cpu_to_be16(from->di_projid_hi);
memset(to->di_pad, 0, sizeof(to->di_pad));
to->di_atime.t_sec = cpu_to_be32(inode->i_atime.tv_sec);
to->di_atime.t_nsec = cpu_to_be32(inode->i_atime.tv_nsec);
to->di_mtime.t_sec = cpu_to_be32(inode->i_mtime.tv_sec);
to->di_mtime.t_nsec = cpu_to_be32(inode->i_mtime.tv_nsec);
to->di_ctime.t_sec = cpu_to_be32(inode->i_ctime.tv_sec);
to->di_ctime.t_nsec = cpu_to_be32(inode->i_ctime.tv_nsec);
to->di_nlink = cpu_to_be32(inode->i_nlink);
to->di_gen = cpu_to_be32(inode->i_generation);
to->di_mode = cpu_to_be16(inode->i_mode);
to->di_size = cpu_to_be64(from->di_size);
to->di_nblocks = cpu_to_be64(from->di_nblocks);
to->di_extsize = cpu_to_be32(from->di_extsize);
to->di_nextents = cpu_to_be32(from->di_nextents);
to->di_anextents = cpu_to_be16(from->di_anextents);
to->di_forkoff = from->di_forkoff;
to->di_aformat = from->di_aformat;
to->di_dmevmask = cpu_to_be32(from->di_dmevmask);
to->di_dmstate = cpu_to_be16(from->di_dmstate);
to->di_flags = cpu_to_be16(from->di_flags);
if (from->di_version == 3) {
to->di_changecount = cpu_to_be64(inode->i_version);
to->di_crtime.t_sec = cpu_to_be32(from->di_crtime.t_sec);
to->di_crtime.t_nsec = cpu_to_be32(from->di_crtime.t_nsec);
to->di_flags2 = cpu_to_be64(from->di_flags2);
to->di_cowextsize = cpu_to_be32(from->di_cowextsize);
to->di_ino = cpu_to_be64(ip->i_ino);
to->di_lsn = cpu_to_be64(lsn);
memset(to->di_pad2, 0, sizeof(to->di_pad2));
uuid_copy(&to->di_uuid, &ip->i_mount->m_sb.sb_meta_uuid);
to->di_flushiter = 0;
} else {
to->di_flushiter = cpu_to_be16(from->di_flushiter);
}
}
void
xfs_log_dinode_to_disk(
struct xfs_log_dinode *from,
struct xfs_dinode *to)
{
to->di_magic = cpu_to_be16(from->di_magic);
to->di_mode = cpu_to_be16(from->di_mode);
to->di_version = from->di_version;
to->di_format = from->di_format;
to->di_onlink = 0;
to->di_uid = cpu_to_be32(from->di_uid);
to->di_gid = cpu_to_be32(from->di_gid);
to->di_nlink = cpu_to_be32(from->di_nlink);
to->di_projid_lo = cpu_to_be16(from->di_projid_lo);
to->di_projid_hi = cpu_to_be16(from->di_projid_hi);
memcpy(to->di_pad, from->di_pad, sizeof(to->di_pad));
to->di_atime.t_sec = cpu_to_be32(from->di_atime.t_sec);
to->di_atime.t_nsec = cpu_to_be32(from->di_atime.t_nsec);
to->di_mtime.t_sec = cpu_to_be32(from->di_mtime.t_sec);
to->di_mtime.t_nsec = cpu_to_be32(from->di_mtime.t_nsec);
to->di_ctime.t_sec = cpu_to_be32(from->di_ctime.t_sec);
to->di_ctime.t_nsec = cpu_to_be32(from->di_ctime.t_nsec);
to->di_size = cpu_to_be64(from->di_size);
to->di_nblocks = cpu_to_be64(from->di_nblocks);
to->di_extsize = cpu_to_be32(from->di_extsize);
to->di_nextents = cpu_to_be32(from->di_nextents);
to->di_anextents = cpu_to_be16(from->di_anextents);
to->di_forkoff = from->di_forkoff;
to->di_aformat = from->di_aformat;
to->di_dmevmask = cpu_to_be32(from->di_dmevmask);
to->di_dmstate = cpu_to_be16(from->di_dmstate);
to->di_flags = cpu_to_be16(from->di_flags);
to->di_gen = cpu_to_be32(from->di_gen);
if (from->di_version == 3) {
to->di_changecount = cpu_to_be64(from->di_changecount);
to->di_crtime.t_sec = cpu_to_be32(from->di_crtime.t_sec);
to->di_crtime.t_nsec = cpu_to_be32(from->di_crtime.t_nsec);
to->di_flags2 = cpu_to_be64(from->di_flags2);
to->di_cowextsize = cpu_to_be32(from->di_cowextsize);
to->di_ino = cpu_to_be64(from->di_ino);
to->di_lsn = cpu_to_be64(from->di_lsn);
memcpy(to->di_pad2, from->di_pad2, sizeof(to->di_pad2));
uuid_copy(&to->di_uuid, &from->di_uuid);
to->di_flushiter = 0;
} else {
to->di_flushiter = cpu_to_be16(from->di_flushiter);
}
}
static bool
xfs_dinode_verify(
struct xfs_mount *mp,
struct xfs_inode *ip,
struct xfs_dinode *dip)
{
uint16_t flags;
uint64_t flags2;
if (dip->di_magic != cpu_to_be16(XFS_DINODE_MAGIC))
return false;
if (dip->di_version < 3)
return true;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return false;
if (!xfs_verify_cksum((char *)dip, mp->m_sb.sb_inodesize,
XFS_DINODE_CRC_OFF))
return false;
if (be64_to_cpu(dip->di_ino) != ip->i_ino)
return false;
if (!uuid_equal(&dip->di_uuid, &mp->m_sb.sb_meta_uuid))
return false;
flags = be16_to_cpu(dip->di_flags);
flags2 = be64_to_cpu(dip->di_flags2);
if ((flags2 & (XFS_DIFLAG2_REFLINK | XFS_DIFLAG2_COWEXTSIZE)) &&
!xfs_sb_version_hasreflink(&mp->m_sb))
return false;
if ((flags2 & XFS_DIFLAG2_REFLINK) && (flags & XFS_DIFLAG_REALTIME))
return false;
if ((flags2 & XFS_DIFLAG2_REFLINK) && (flags2 & XFS_DIFLAG2_DAX))
return false;
return true;
}
void
xfs_dinode_calc_crc(
struct xfs_mount *mp,
struct xfs_dinode *dip)
{
__uint32_t crc;
if (dip->di_version < 3)
return;
ASSERT(xfs_sb_version_hascrc(&mp->m_sb));
crc = xfs_start_cksum((char *)dip, mp->m_sb.sb_inodesize,
XFS_DINODE_CRC_OFF);
dip->di_crc = xfs_end_cksum(crc);
}
int
xfs_iread(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_inode_t *ip,
uint iget_flags)
{
xfs_buf_t *bp;
xfs_dinode_t *dip;
int error;
error = xfs_imap(mp, tp, ip->i_ino, &ip->i_imap, iget_flags);
if (error)
return error;
if ((iget_flags & XFS_IGET_CREATE) &&
xfs_sb_version_hascrc(&mp->m_sb) &&
!(mp->m_flags & XFS_MOUNT_IKEEP)) {
memset(&ip->i_d, 0, sizeof(ip->i_d));
VFS_I(ip)->i_generation = prandom_u32();
if (xfs_sb_version_hascrc(&mp->m_sb))
ip->i_d.di_version = 3;
else
ip->i_d.di_version = 2;
return 0;
}
error = xfs_imap_to_bp(mp, tp, &ip->i_imap, &dip, &bp, 0, iget_flags);
if (error)
return error;
if (!xfs_dinode_verify(mp, ip, dip)) {
xfs_alert(mp, "%s: validation failed for inode %lld failed",
__func__, ip->i_ino);
XFS_CORRUPTION_ERROR(__func__, XFS_ERRLEVEL_LOW, mp, dip);
error = -EFSCORRUPTED;
goto out_brelse;
}
if (dip->di_mode) {
xfs_inode_from_disk(ip, dip);
error = xfs_iformat_fork(ip, dip);
if (error) {
#ifdef DEBUG
xfs_alert(mp, "%s: xfs_iformat() returned error %d",
__func__, error);
#endif
goto out_brelse;
}
} else {
ip->i_d.di_version = dip->di_version;
VFS_I(ip)->i_generation = be32_to_cpu(dip->di_gen);
ip->i_d.di_flushiter = be16_to_cpu(dip->di_flushiter);
VFS_I(ip)->i_mode = 0;
}
ASSERT(ip->i_d.di_version >= 2);
ip->i_delayed_blks = 0;
xfs_buf_set_ref(bp, XFS_INO_REF);
out_brelse:
xfs_trans_brelse(tp, bp);
return error;
}
