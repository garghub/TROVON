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
cur->bc_private.a.agbp, cur->bc_private.a.agno);
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
STATIC int
xfs_inobt_alloc_block(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *start,
union xfs_btree_ptr *new,
int length,
int *stat)
{
xfs_alloc_arg_t args;
int error;
xfs_agblock_t sbno = be32_to_cpu(start->s);
XFS_BTREE_TRACE_CURSOR(cur, XBT_ENTRY);
memset(&args, 0, sizeof(args));
args.tp = cur->bc_tp;
args.mp = cur->bc_mp;
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
xfs_fsblock_t fsbno;
int error;
fsbno = XFS_DADDR_TO_FSB(cur->bc_mp, XFS_BUF_ADDR(bp));
error = xfs_free_extent(cur->bc_tp, fsbno, 1);
if (error)
return error;
xfs_trans_binval(cur->bc_tp, bp);
return error;
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
xfs_inobt_init_rec_from_key(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
rec->inobt.ir_startino = key->inobt.ir_startino;
}
STATIC void
xfs_inobt_init_rec_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec)
{
rec->inobt.ir_startino = cpu_to_be32(cur->bc_rec.i.ir_startino);
rec->inobt.ir_freecount = cpu_to_be32(cur->bc_rec.i.ir_freecount);
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
STATIC __int64_t
xfs_inobt_key_diff(
struct xfs_btree_cur *cur,
union xfs_btree_key *key)
{
return (__int64_t)be32_to_cpu(key->inobt.ir_startino) -
cur->bc_rec.i.ir_startino;
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
xfs_agnumber_t agno)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
struct xfs_btree_cur *cur;
cur = kmem_zone_zalloc(xfs_btree_cur_zone, KM_SLEEP);
cur->bc_tp = tp;
cur->bc_mp = mp;
cur->bc_nlevels = be32_to_cpu(agi->agi_level);
cur->bc_btnum = XFS_BTNUM_INO;
cur->bc_blocklog = mp->m_sb.sb_blocklog;
cur->bc_ops = &xfs_inobt_ops;
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
