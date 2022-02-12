int
xfs_calc_dquots_per_chunk(
struct xfs_mount *mp,
unsigned int nbblks)
{
unsigned int ndquots;
ASSERT(nbblks > 0);
ndquots = BBTOB(nbblks);
do_div(ndquots, sizeof(xfs_dqblk_t));
return ndquots;
}
int
xfs_dqcheck(
struct xfs_mount *mp,
xfs_disk_dquot_t *ddq,
xfs_dqid_t id,
uint type,
uint flags,
char *str)
{
xfs_dqblk_t *d = (xfs_dqblk_t *)ddq;
int errs = 0;
if (ddq->d_magic != cpu_to_be16(XFS_DQUOT_MAGIC)) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : XFS dquot ID 0x%x, magic 0x%x != 0x%x",
str, id, be16_to_cpu(ddq->d_magic), XFS_DQUOT_MAGIC);
errs++;
}
if (ddq->d_version != XFS_DQUOT_VERSION) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : XFS dquot ID 0x%x, version 0x%x != 0x%x",
str, id, ddq->d_version, XFS_DQUOT_VERSION);
errs++;
}
if (ddq->d_flags != XFS_DQ_USER &&
ddq->d_flags != XFS_DQ_PROJ &&
ddq->d_flags != XFS_DQ_GROUP) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : XFS dquot ID 0x%x, unknown flags 0x%x",
str, id, ddq->d_flags);
errs++;
}
if (id != -1 && id != be32_to_cpu(ddq->d_id)) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : ondisk-dquot 0x%p, ID mismatch: "
"0x%x expected, found id 0x%x",
str, ddq, id, be32_to_cpu(ddq->d_id));
errs++;
}
if (!errs && ddq->d_id) {
if (ddq->d_blk_softlimit &&
be64_to_cpu(ddq->d_bcount) >
be64_to_cpu(ddq->d_blk_softlimit)) {
if (!ddq->d_btimer) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : Dquot ID 0x%x (0x%p) BLK TIMER NOT STARTED",
str, (int)be32_to_cpu(ddq->d_id), ddq);
errs++;
}
}
if (ddq->d_ino_softlimit &&
be64_to_cpu(ddq->d_icount) >
be64_to_cpu(ddq->d_ino_softlimit)) {
if (!ddq->d_itimer) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : Dquot ID 0x%x (0x%p) INODE TIMER NOT STARTED",
str, (int)be32_to_cpu(ddq->d_id), ddq);
errs++;
}
}
if (ddq->d_rtb_softlimit &&
be64_to_cpu(ddq->d_rtbcount) >
be64_to_cpu(ddq->d_rtb_softlimit)) {
if (!ddq->d_rtbtimer) {
if (flags & XFS_QMOPT_DOWARN)
xfs_alert(mp,
"%s : Dquot ID 0x%x (0x%p) RTBLK TIMER NOT STARTED",
str, (int)be32_to_cpu(ddq->d_id), ddq);
errs++;
}
}
}
if (!errs || !(flags & XFS_QMOPT_DQREPAIR))
return errs;
if (flags & XFS_QMOPT_DOWARN)
xfs_notice(mp, "Re-initializing dquot ID 0x%x", id);
ASSERT(id != -1);
ASSERT(flags & XFS_QMOPT_DQREPAIR);
memset(d, 0, sizeof(xfs_dqblk_t));
d->dd_diskdq.d_magic = cpu_to_be16(XFS_DQUOT_MAGIC);
d->dd_diskdq.d_version = XFS_DQUOT_VERSION;
d->dd_diskdq.d_flags = type;
d->dd_diskdq.d_id = cpu_to_be32(id);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
uuid_copy(&d->dd_uuid, &mp->m_sb.sb_uuid);
xfs_update_cksum((char *)d, sizeof(struct xfs_dqblk),
XFS_DQUOT_CRC_OFF);
}
return errs;
}
STATIC bool
xfs_dquot_buf_verify_crc(
struct xfs_mount *mp,
struct xfs_buf *bp)
{
struct xfs_dqblk *d = (struct xfs_dqblk *)bp->b_addr;
int ndquots;
int i;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return true;
if (mp->m_quotainfo)
ndquots = mp->m_quotainfo->qi_dqperchunk;
else
ndquots = xfs_calc_dquots_per_chunk(mp,
XFS_BB_TO_FSB(mp, bp->b_length));
for (i = 0; i < ndquots; i++, d++) {
if (!xfs_verify_cksum((char *)d, sizeof(struct xfs_dqblk),
XFS_DQUOT_CRC_OFF))
return false;
if (!uuid_equal(&d->dd_uuid, &mp->m_sb.sb_uuid))
return false;
}
return true;
}
STATIC bool
xfs_dquot_buf_verify(
struct xfs_mount *mp,
struct xfs_buf *bp)
{
struct xfs_dqblk *d = (struct xfs_dqblk *)bp->b_addr;
xfs_dqid_t id = 0;
int ndquots;
int i;
if (mp->m_quotainfo)
ndquots = mp->m_quotainfo->qi_dqperchunk;
else
ndquots = xfs_calc_dquots_per_chunk(mp, bp->b_length);
for (i = 0; i < ndquots; i++) {
struct xfs_disk_dquot *ddq;
int error;
ddq = &d[i].dd_diskdq;
if (i == 0)
id = be32_to_cpu(ddq->d_id);
error = xfs_dqcheck(mp, ddq, id + i, 0, XFS_QMOPT_DOWARN,
"xfs_dquot_buf_verify");
if (error)
return false;
}
return true;
}
static void
xfs_dquot_buf_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (!xfs_dquot_buf_verify_crc(mp, bp))
xfs_buf_ioerror(bp, EFSBADCRC);
else if (!xfs_dquot_buf_verify(mp, bp))
xfs_buf_ioerror(bp, EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
xfs_dquot_buf_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (!xfs_dquot_buf_verify(mp, bp)) {
xfs_buf_ioerror(bp, EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
}
