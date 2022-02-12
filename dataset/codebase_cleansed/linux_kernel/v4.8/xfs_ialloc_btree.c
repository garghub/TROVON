STATIC int
xfs_inobt_get_minrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_inobt_mnr[level != 0];
}
STATIC struct xfs_btree_cur *
xfs_inobt_dup_cursor(
struct xfs_btree_cur *cur)
{
return xfs_inobt_init_cursor(cur->bc_mp, cur->bc_tp,
cur->bc_private.a.agbp, cur->bc_private.a.agno,
cur->bc_btnum);
}
STATIC void
xfs_inobt_set_root(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *nptr,
int inc)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
agi->agi_root = nptr->s;
be32_add_cpu(&agi->agi_level, inc);
xfs_ialloc_log_agi(cur->bc_tp, agbp, XFS_AGI_ROOT | XFS_AGI_LEVEL);
}
STATIC void
xfs_finobt_set_root(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *nptr,
int inc)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
agi->agi_free_root = nptr->s;
be32_add_cpu(&agi->agi_free_level, inc);
xfs_ialloc_log_agi(cur->bc_tp, agbp,
XFS_AGI_FREE_ROOT | XFS_AGI_FREE_LEVEL);
}
STATIC int
xfs_inobt_alloc_block(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *start,
union xfs_btree_ptr *new,
int *stat)
{
xfs_alloc_arg_t args;
int error;
xfs_agblock_t sbno = be32_to_cpu(start->s);
XFS_BTREE_TRACE_CURSOR(cur, XBT_ENTRY);
memset(&args, 0, sizeof(args));
args.tp = cur->bc_tp;
args.mp = cur->bc_mp;
xfs_rmap_ag_owner(&args.oinfo, XFS_RMAP_OWN_INOBT);
args.fsbno = XFS_AGB_TO_FSB(args.mp, cur->bc_private.a.agno, sbno);
args.minlen = 1;
args.maxlen = 1;
args.prod = 1;
args.type = XFS_ALLOCTYPE_NEAR_BNO;
error = xfs_alloc_vextent(&args);
if (error) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_ERROR);
return error;
}
if (args.fsbno == NULLFSBLOCK) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
*stat = 0;
return 0;
}
ASSERT(args.len == 1);
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
new->s = cpu_to_be32(XFS_FSB_TO_AGBNO(args.mp, args.fsbno));
*stat = 1;
return 0;
}
STATIC int
xfs_inobt_free_block(
struct xfs_btree_cur *cur,
struct xfs_buf *bp)
{
struct xfs_owner_info oinfo;
xfs_rmap_ag_owner(&oinfo, XFS_RMAP_OWN_INOBT);
return xfs_free_extent(cur->bc_tp,
XFS_DADDR_TO_FSB(cur->bc_mp, XFS_BUF_ADDR(bp)), 1,
&oinfo);
}
STATIC int
xfs_inobt_get_maxrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_inobt_mxr[level != 0];
}
STATIC void
xfs_inobt_init_key_from_rec(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
key->inobt.ir_startino = rec->inobt.ir_startino;
}
STATIC void
xfs_inobt_init_rec_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec)
{
rec->inobt.ir_startino = cpu_to_be32(cur->bc_rec.i.ir_startino);
if (xfs_sb_version_hassparseinodes(&cur->bc_mp->m_sb)) {
rec->inobt.ir_u.sp.ir_holemask =
cpu_to_be16(cur->bc_rec.i.ir_holemask);
rec->inobt.ir_u.sp.ir_count = cur->bc_rec.i.ir_count;
rec->inobt.ir_u.sp.ir_freecount = cur->bc_rec.i.ir_freecount;
} else {
rec->inobt.ir_u.f.ir_freecount =
cpu_to_be32(cur->bc_rec.i.ir_freecount);
}
rec->inobt.ir_free = cpu_to_be64(cur->bc_rec.i.ir_free);
}
STATIC void
xfs_inobt_init_ptr_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *ptr)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(cur->bc_private.a.agbp);
ASSERT(cur->bc_private.a.agno == be32_to_cpu(agi->agi_seqno));
ptr->s = agi->agi_root;
}
STATIC void
xfs_finobt_init_ptr_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *ptr)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(cur->bc_private.a.agbp);
ASSERT(cur->bc_private.a.agno == be32_to_cpu(agi->agi_seqno));
ptr->s = agi->agi_free_root;
}
STATIC __int64_t
xfs_inobt_key_diff(
struct xfs_btree_cur *cur,
union xfs_btree_key *key)
{
return (__int64_t)be32_to_cpu(key->inobt.ir_startino) -
cur->bc_rec.i.ir_startino;
}
static int
xfs_inobt_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_btree_block *block = XFS_BUF_TO_BLOCK(bp);
unsigned int level;
switch (block->bb_magic) {
case cpu_to_be32(XFS_IBT_CRC_MAGIC):
case cpu_to_be32(XFS_FIBT_CRC_MAGIC):
if (!xfs_btree_sblock_v5hdr_verify(bp))
return false;
case cpu_to_be32(XFS_IBT_MAGIC):
case cpu_to_be32(XFS_FIBT_MAGIC):
break;
default:
return 0;
}
level = be16_to_cpu(block->bb_level);
if (level >= mp->m_in_maxlevels)
return false;
return xfs_btree_sblock_verify(bp, mp->m_inobt_mxr[level != 0]);
}
static void
xfs_inobt_read_verify(
struct xfs_buf *bp)
{
if (!xfs_btree_sblock_verify_crc(bp))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_inobt_verify(bp))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error) {
trace_xfs_btree_corrupt(bp, _RET_IP_);
xfs_verifier_error(bp);
}
}
static void
xfs_inobt_write_verify(
struct xfs_buf *bp)
{
if (!xfs_inobt_verify(bp)) {
trace_xfs_btree_corrupt(bp, _RET_IP_);
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
xfs_btree_sblock_calc_crc(bp);
}
STATIC int
xfs_inobt_keys_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_key *k1,
union xfs_btree_key *k2)
{
return be32_to_cpu(k1->inobt.ir_startino) <
be32_to_cpu(k2->inobt.ir_startino);
}
STATIC int
xfs_inobt_recs_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_rec *r1,
union xfs_btree_rec *r2)
{
return be32_to_cpu(r1->inobt.ir_startino) + XFS_INODES_PER_CHUNK <=
be32_to_cpu(r2->inobt.ir_startino);
}
struct xfs_btree_cur *
xfs_inobt_init_cursor(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agnumber_t agno,
xfs_btnum_t btnum)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
struct xfs_btree_cur *cur;
cur = kmem_zone_zalloc(xfs_btree_cur_zone, KM_SLEEP);
cur->bc_tp = tp;
cur->bc_mp = mp;
cur->bc_btnum = btnum;
if (btnum == XFS_BTNUM_INO) {
cur->bc_nlevels = be32_to_cpu(agi->agi_level);
cur->bc_ops = &xfs_inobt_ops;
} else {
cur->bc_nlevels = be32_to_cpu(agi->agi_free_level);
cur->bc_ops = &xfs_finobt_ops;
}
cur->bc_blocklog = mp->m_sb.sb_blocklog;
if (xfs_sb_version_hascrc(&mp->m_sb))
cur->bc_flags |= XFS_BTREE_CRC_BLOCKS;
cur->bc_private.a.agbp = agbp;
cur->bc_private.a.agno = agno;
return cur;
}
int
xfs_inobt_maxrecs(
struct xfs_mount *mp,
int blocklen,
int leaf)
{
blocklen -= XFS_INOBT_BLOCK_LEN(mp);
if (leaf)
return blocklen / sizeof(xfs_inobt_rec_t);
return blocklen / (sizeof(xfs_inobt_key_t) + sizeof(xfs_inobt_ptr_t));
}
uint64_t
xfs_inobt_irec_to_allocmask(
struct xfs_inobt_rec_incore *rec)
{
uint64_t bitmap = 0;
uint64_t inodespbit;
int nextbit;
uint allocbitmap;
inodespbit = (1 << XFS_INODES_PER_HOLEMASK_BIT) - 1;
allocbitmap = ~rec->ir_holemask & ((1 << XFS_INOBT_HOLEMASK_BITS) - 1);
nextbit = xfs_next_bit(&allocbitmap, 1, 0);
while (nextbit != -1) {
ASSERT(nextbit < (sizeof(rec->ir_holemask) * NBBY));
bitmap |= (inodespbit <<
(nextbit * XFS_INODES_PER_HOLEMASK_BIT));
nextbit = xfs_next_bit(&allocbitmap, 1, nextbit + 1);
}
return bitmap;
}
int
xfs_inobt_rec_check_count(
struct xfs_mount *mp,
struct xfs_inobt_rec_incore *rec)
{
int inocount = 0;
int nextbit = 0;
uint64_t allocbmap;
int wordsz;
wordsz = sizeof(allocbmap) / sizeof(unsigned int);
allocbmap = xfs_inobt_irec_to_allocmask(rec);
nextbit = xfs_next_bit((uint *) &allocbmap, wordsz, nextbit);
while (nextbit != -1) {
inocount++;
nextbit = xfs_next_bit((uint *) &allocbmap, wordsz,
nextbit + 1);
}
if (inocount != rec->ir_count)
return -EFSCORRUPTED;
return 0;
}
