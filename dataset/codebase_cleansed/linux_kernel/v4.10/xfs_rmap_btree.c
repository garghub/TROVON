static struct xfs_btree_cur *
xfs_rmapbt_dup_cursor(
struct xfs_btree_cur *cur)
{
return xfs_rmapbt_init_cursor(cur->bc_mp, cur->bc_tp,
cur->bc_private.a.agbp, cur->bc_private.a.agno);
}
STATIC void
xfs_rmapbt_set_root(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *ptr,
int inc)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
xfs_agnumber_t seqno = be32_to_cpu(agf->agf_seqno);
int btnum = cur->bc_btnum;
struct xfs_perag *pag = xfs_perag_get(cur->bc_mp, seqno);
ASSERT(ptr->s != 0);
agf->agf_roots[btnum] = ptr->s;
be32_add_cpu(&agf->agf_levels[btnum], inc);
pag->pagf_levels[btnum] += inc;
xfs_perag_put(pag);
xfs_alloc_log_agf(cur->bc_tp, agbp, XFS_AGF_ROOTS | XFS_AGF_LEVELS);
}
STATIC int
xfs_rmapbt_alloc_block(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *start,
union xfs_btree_ptr *new,
int *stat)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
int error;
xfs_agblock_t bno;
XFS_BTREE_TRACE_CURSOR(cur, XBT_ENTRY);
error = xfs_alloc_get_freelist(cur->bc_tp, cur->bc_private.a.agbp,
&bno, 1);
if (error) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_ERROR);
return error;
}
trace_xfs_rmapbt_alloc_block(cur->bc_mp, cur->bc_private.a.agno,
bno, 1);
if (bno == NULLAGBLOCK) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
*stat = 0;
return 0;
}
xfs_extent_busy_reuse(cur->bc_mp, cur->bc_private.a.agno, bno, 1,
false);
xfs_trans_agbtree_delta(cur->bc_tp, 1);
new->s = cpu_to_be32(bno);
be32_add_cpu(&agf->agf_rmap_blocks, 1);
xfs_alloc_log_agf(cur->bc_tp, agbp, XFS_AGF_RMAP_BLOCKS);
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
*stat = 1;
return 0;
}
STATIC int
xfs_rmapbt_free_block(
struct xfs_btree_cur *cur,
struct xfs_buf *bp)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
xfs_agblock_t bno;
int error;
bno = xfs_daddr_to_agbno(cur->bc_mp, XFS_BUF_ADDR(bp));
trace_xfs_rmapbt_free_block(cur->bc_mp, cur->bc_private.a.agno,
bno, 1);
be32_add_cpu(&agf->agf_rmap_blocks, -1);
xfs_alloc_log_agf(cur->bc_tp, agbp, XFS_AGF_RMAP_BLOCKS);
error = xfs_alloc_put_freelist(cur->bc_tp, agbp, NULL, bno, 1);
if (error)
return error;
xfs_extent_busy_insert(cur->bc_tp, be32_to_cpu(agf->agf_seqno), bno, 1,
XFS_EXTENT_BUSY_SKIP_DISCARD);
xfs_trans_agbtree_delta(cur->bc_tp, -1);
return 0;
}
STATIC int
xfs_rmapbt_get_minrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_rmap_mnr[level != 0];
}
STATIC int
xfs_rmapbt_get_maxrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_rmap_mxr[level != 0];
}
STATIC void
xfs_rmapbt_init_key_from_rec(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
key->rmap.rm_startblock = rec->rmap.rm_startblock;
key->rmap.rm_owner = rec->rmap.rm_owner;
key->rmap.rm_offset = rec->rmap.rm_offset;
}
STATIC void
xfs_rmapbt_init_high_key_from_rec(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
__uint64_t off;
int adj;
adj = be32_to_cpu(rec->rmap.rm_blockcount) - 1;
key->rmap.rm_startblock = rec->rmap.rm_startblock;
be32_add_cpu(&key->rmap.rm_startblock, adj);
key->rmap.rm_owner = rec->rmap.rm_owner;
key->rmap.rm_offset = rec->rmap.rm_offset;
if (XFS_RMAP_NON_INODE_OWNER(be64_to_cpu(rec->rmap.rm_owner)) ||
XFS_RMAP_IS_BMBT_BLOCK(be64_to_cpu(rec->rmap.rm_offset)))
return;
off = be64_to_cpu(key->rmap.rm_offset);
off = (XFS_RMAP_OFF(off) + adj) | (off & ~XFS_RMAP_OFF_MASK);
key->rmap.rm_offset = cpu_to_be64(off);
}
STATIC void
xfs_rmapbt_init_rec_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec)
{
rec->rmap.rm_startblock = cpu_to_be32(cur->bc_rec.r.rm_startblock);
rec->rmap.rm_blockcount = cpu_to_be32(cur->bc_rec.r.rm_blockcount);
rec->rmap.rm_owner = cpu_to_be64(cur->bc_rec.r.rm_owner);
rec->rmap.rm_offset = cpu_to_be64(
xfs_rmap_irec_offset_pack(&cur->bc_rec.r));
}
STATIC void
xfs_rmapbt_init_ptr_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *ptr)
{
struct xfs_agf *agf = XFS_BUF_TO_AGF(cur->bc_private.a.agbp);
ASSERT(cur->bc_private.a.agno == be32_to_cpu(agf->agf_seqno));
ASSERT(agf->agf_roots[cur->bc_btnum] != 0);
ptr->s = agf->agf_roots[cur->bc_btnum];
}
STATIC __int64_t
xfs_rmapbt_key_diff(
struct xfs_btree_cur *cur,
union xfs_btree_key *key)
{
struct xfs_rmap_irec *rec = &cur->bc_rec.r;
struct xfs_rmap_key *kp = &key->rmap;
__u64 x, y;
__int64_t d;
d = (__int64_t)be32_to_cpu(kp->rm_startblock) - rec->rm_startblock;
if (d)
return d;
x = be64_to_cpu(kp->rm_owner);
y = rec->rm_owner;
if (x > y)
return 1;
else if (y > x)
return -1;
x = XFS_RMAP_OFF(be64_to_cpu(kp->rm_offset));
y = rec->rm_offset;
if (x > y)
return 1;
else if (y > x)
return -1;
return 0;
}
STATIC __int64_t
xfs_rmapbt_diff_two_keys(
struct xfs_btree_cur *cur,
union xfs_btree_key *k1,
union xfs_btree_key *k2)
{
struct xfs_rmap_key *kp1 = &k1->rmap;
struct xfs_rmap_key *kp2 = &k2->rmap;
__int64_t d;
__u64 x, y;
d = (__int64_t)be32_to_cpu(kp1->rm_startblock) -
be32_to_cpu(kp2->rm_startblock);
if (d)
return d;
x = be64_to_cpu(kp1->rm_owner);
y = be64_to_cpu(kp2->rm_owner);
if (x > y)
return 1;
else if (y > x)
return -1;
x = XFS_RMAP_OFF(be64_to_cpu(kp1->rm_offset));
y = XFS_RMAP_OFF(be64_to_cpu(kp2->rm_offset));
if (x > y)
return 1;
else if (y > x)
return -1;
return 0;
}
static bool
xfs_rmapbt_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_btree_block *block = XFS_BUF_TO_BLOCK(bp);
struct xfs_perag *pag = bp->b_pag;
unsigned int level;
if (block->bb_magic != cpu_to_be32(XFS_RMAP_CRC_MAGIC))
return false;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return false;
if (!xfs_btree_sblock_v5hdr_verify(bp))
return false;
level = be16_to_cpu(block->bb_level);
if (pag && pag->pagf_init) {
if (level >= pag->pagf_levels[XFS_BTNUM_RMAPi])
return false;
} else if (level >= mp->m_rmap_maxlevels)
return false;
return xfs_btree_sblock_verify(bp, mp->m_rmap_mxr[level != 0]);
}
static void
xfs_rmapbt_read_verify(
struct xfs_buf *bp)
{
if (!xfs_btree_sblock_verify_crc(bp))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_rmapbt_verify(bp))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error) {
trace_xfs_btree_corrupt(bp, _RET_IP_);
xfs_verifier_error(bp);
}
}
static void
xfs_rmapbt_write_verify(
struct xfs_buf *bp)
{
if (!xfs_rmapbt_verify(bp)) {
trace_xfs_btree_corrupt(bp, _RET_IP_);
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
xfs_btree_sblock_calc_crc(bp);
}
STATIC int
xfs_rmapbt_keys_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_key *k1,
union xfs_btree_key *k2)
{
__uint32_t x;
__uint32_t y;
__uint64_t a;
__uint64_t b;
x = be32_to_cpu(k1->rmap.rm_startblock);
y = be32_to_cpu(k2->rmap.rm_startblock);
if (x < y)
return 1;
else if (x > y)
return 0;
a = be64_to_cpu(k1->rmap.rm_owner);
b = be64_to_cpu(k2->rmap.rm_owner);
if (a < b)
return 1;
else if (a > b)
return 0;
a = XFS_RMAP_OFF(be64_to_cpu(k1->rmap.rm_offset));
b = XFS_RMAP_OFF(be64_to_cpu(k2->rmap.rm_offset));
if (a <= b)
return 1;
return 0;
}
STATIC int
xfs_rmapbt_recs_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_rec *r1,
union xfs_btree_rec *r2)
{
__uint32_t x;
__uint32_t y;
__uint64_t a;
__uint64_t b;
x = be32_to_cpu(r1->rmap.rm_startblock);
y = be32_to_cpu(r2->rmap.rm_startblock);
if (x < y)
return 1;
else if (x > y)
return 0;
a = be64_to_cpu(r1->rmap.rm_owner);
b = be64_to_cpu(r2->rmap.rm_owner);
if (a < b)
return 1;
else if (a > b)
return 0;
a = XFS_RMAP_OFF(be64_to_cpu(r1->rmap.rm_offset));
b = XFS_RMAP_OFF(be64_to_cpu(r2->rmap.rm_offset));
if (a <= b)
return 1;
return 0;
}
struct xfs_btree_cur *
xfs_rmapbt_init_cursor(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agnumber_t agno)
{
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
struct xfs_btree_cur *cur;
cur = kmem_zone_zalloc(xfs_btree_cur_zone, KM_NOFS);
cur->bc_tp = tp;
cur->bc_mp = mp;
cur->bc_btnum = XFS_BTNUM_RMAP;
cur->bc_flags = XFS_BTREE_CRC_BLOCKS | XFS_BTREE_OVERLAPPING;
cur->bc_blocklog = mp->m_sb.sb_blocklog;
cur->bc_ops = &xfs_rmapbt_ops;
cur->bc_nlevels = be32_to_cpu(agf->agf_levels[XFS_BTNUM_RMAP]);
cur->bc_statoff = XFS_STATS_CALC_INDEX(xs_rmap_2);
cur->bc_private.a.agbp = agbp;
cur->bc_private.a.agno = agno;
return cur;
}
int
xfs_rmapbt_maxrecs(
struct xfs_mount *mp,
int blocklen,
int leaf)
{
blocklen -= XFS_RMAP_BLOCK_LEN;
if (leaf)
return blocklen / sizeof(struct xfs_rmap_rec);
return blocklen /
(2 * sizeof(struct xfs_rmap_key) + sizeof(xfs_rmap_ptr_t));
}
void
xfs_rmapbt_compute_maxlevels(
struct xfs_mount *mp)
{
if (xfs_sb_version_hasreflink(&mp->m_sb))
mp->m_rmap_maxlevels = XFS_BTREE_MAXLEVELS;
else
mp->m_rmap_maxlevels = xfs_btree_compute_maxlevels(mp,
mp->m_rmap_mnr, mp->m_sb.sb_agblocks);
}
xfs_extlen_t
xfs_rmapbt_calc_size(
struct xfs_mount *mp,
unsigned long long len)
{
return xfs_btree_calc_size(mp, mp->m_rmap_mnr, len);
}
xfs_extlen_t
xfs_rmapbt_max_size(
struct xfs_mount *mp,
xfs_agblock_t agblocks)
{
if (mp->m_rmap_mxr[0] == 0)
return 0;
return xfs_rmapbt_calc_size(mp, agblocks);
}
int
xfs_rmapbt_calc_reserves(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_extlen_t *ask,
xfs_extlen_t *used)
{
struct xfs_buf *agbp;
struct xfs_agf *agf;
xfs_agblock_t agblocks;
xfs_extlen_t tree_len;
int error;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return 0;
error = xfs_alloc_read_agf(mp, NULL, agno, 0, &agbp);
if (error)
return error;
agf = XFS_BUF_TO_AGF(agbp);
agblocks = be32_to_cpu(agf->agf_length);
tree_len = be32_to_cpu(agf->agf_rmap_blocks);
xfs_buf_relse(agbp);
*ask += max(agblocks / 100, xfs_rmapbt_max_size(mp, agblocks));
*used += tree_len;
return error;
}
