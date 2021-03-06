STATIC struct xfs_btree_cur *
xfs_allocbt_dup_cursor(
struct xfs_btree_cur *cur)
{
return xfs_allocbt_init_cursor(cur->bc_mp, cur->bc_tp,
cur->bc_private.a.agbp, cur->bc_private.a.agno,
cur->bc_btnum);
}
STATIC void
xfs_allocbt_set_root(
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
xfs_allocbt_alloc_block(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *start,
union xfs_btree_ptr *new,
int length,
int *stat)
{
int error;
xfs_agblock_t bno;
XFS_BTREE_TRACE_CURSOR(cur, XBT_ENTRY);
error = xfs_alloc_get_freelist(cur->bc_tp, cur->bc_private.a.agbp,
&bno, 1);
if (error) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_ERROR);
return error;
}
if (bno == NULLAGBLOCK) {
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
*stat = 0;
return 0;
}
xfs_alloc_busy_reuse(cur->bc_mp, cur->bc_private.a.agno, bno, 1, false);
xfs_trans_agbtree_delta(cur->bc_tp, 1);
new->s = cpu_to_be32(bno);
XFS_BTREE_TRACE_CURSOR(cur, XBT_EXIT);
*stat = 1;
return 0;
}
STATIC int
xfs_allocbt_free_block(
struct xfs_btree_cur *cur,
struct xfs_buf *bp)
{
struct xfs_buf *agbp = cur->bc_private.a.agbp;
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
xfs_agblock_t bno;
int error;
bno = xfs_daddr_to_agbno(cur->bc_mp, XFS_BUF_ADDR(bp));
error = xfs_alloc_put_freelist(cur->bc_tp, agbp, NULL, bno, 1);
if (error)
return error;
xfs_alloc_busy_insert(cur->bc_tp, be32_to_cpu(agf->agf_seqno), bno, 1,
XFS_ALLOC_BUSY_SKIP_DISCARD);
xfs_trans_agbtree_delta(cur->bc_tp, -1);
return 0;
}
STATIC void
xfs_allocbt_update_lastrec(
struct xfs_btree_cur *cur,
struct xfs_btree_block *block,
union xfs_btree_rec *rec,
int ptr,
int reason)
{
struct xfs_agf *agf = XFS_BUF_TO_AGF(cur->bc_private.a.agbp);
xfs_agnumber_t seqno = be32_to_cpu(agf->agf_seqno);
struct xfs_perag *pag;
__be32 len;
int numrecs;
ASSERT(cur->bc_btnum == XFS_BTNUM_CNT);
switch (reason) {
case LASTREC_UPDATE:
if (ptr != xfs_btree_get_numrecs(block))
return;
len = rec->alloc.ar_blockcount;
break;
case LASTREC_INSREC:
if (be32_to_cpu(rec->alloc.ar_blockcount) <=
be32_to_cpu(agf->agf_longest))
return;
len = rec->alloc.ar_blockcount;
break;
case LASTREC_DELREC:
numrecs = xfs_btree_get_numrecs(block);
if (ptr <= numrecs)
return;
ASSERT(ptr == numrecs + 1);
if (numrecs) {
xfs_alloc_rec_t *rrp;
rrp = XFS_ALLOC_REC_ADDR(cur->bc_mp, block, numrecs);
len = rrp->ar_blockcount;
} else {
len = 0;
}
break;
default:
ASSERT(0);
return;
}
agf->agf_longest = len;
pag = xfs_perag_get(cur->bc_mp, seqno);
pag->pagf_longest = be32_to_cpu(len);
xfs_perag_put(pag);
xfs_alloc_log_agf(cur->bc_tp, cur->bc_private.a.agbp, XFS_AGF_LONGEST);
}
STATIC int
xfs_allocbt_get_minrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_alloc_mnr[level != 0];
}
STATIC int
xfs_allocbt_get_maxrecs(
struct xfs_btree_cur *cur,
int level)
{
return cur->bc_mp->m_alloc_mxr[level != 0];
}
STATIC void
xfs_allocbt_init_key_from_rec(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
ASSERT(rec->alloc.ar_startblock != 0);
key->alloc.ar_startblock = rec->alloc.ar_startblock;
key->alloc.ar_blockcount = rec->alloc.ar_blockcount;
}
STATIC void
xfs_allocbt_init_rec_from_key(
union xfs_btree_key *key,
union xfs_btree_rec *rec)
{
ASSERT(key->alloc.ar_startblock != 0);
rec->alloc.ar_startblock = key->alloc.ar_startblock;
rec->alloc.ar_blockcount = key->alloc.ar_blockcount;
}
STATIC void
xfs_allocbt_init_rec_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec)
{
ASSERT(cur->bc_rec.a.ar_startblock != 0);
rec->alloc.ar_startblock = cpu_to_be32(cur->bc_rec.a.ar_startblock);
rec->alloc.ar_blockcount = cpu_to_be32(cur->bc_rec.a.ar_blockcount);
}
STATIC void
xfs_allocbt_init_ptr_from_cur(
struct xfs_btree_cur *cur,
union xfs_btree_ptr *ptr)
{
struct xfs_agf *agf = XFS_BUF_TO_AGF(cur->bc_private.a.agbp);
ASSERT(cur->bc_private.a.agno == be32_to_cpu(agf->agf_seqno));
ASSERT(agf->agf_roots[cur->bc_btnum] != 0);
ptr->s = agf->agf_roots[cur->bc_btnum];
}
STATIC __int64_t
xfs_allocbt_key_diff(
struct xfs_btree_cur *cur,
union xfs_btree_key *key)
{
xfs_alloc_rec_incore_t *rec = &cur->bc_rec.a;
xfs_alloc_key_t *kp = &key->alloc;
__int64_t diff;
if (cur->bc_btnum == XFS_BTNUM_BNO) {
return (__int64_t)be32_to_cpu(kp->ar_startblock) -
rec->ar_startblock;
}
diff = (__int64_t)be32_to_cpu(kp->ar_blockcount) - rec->ar_blockcount;
if (diff)
return diff;
return (__int64_t)be32_to_cpu(kp->ar_startblock) - rec->ar_startblock;
}
STATIC int
xfs_allocbt_keys_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_key *k1,
union xfs_btree_key *k2)
{
if (cur->bc_btnum == XFS_BTNUM_BNO) {
return be32_to_cpu(k1->alloc.ar_startblock) <
be32_to_cpu(k2->alloc.ar_startblock);
} else {
return be32_to_cpu(k1->alloc.ar_blockcount) <
be32_to_cpu(k2->alloc.ar_blockcount) ||
(k1->alloc.ar_blockcount == k2->alloc.ar_blockcount &&
be32_to_cpu(k1->alloc.ar_startblock) <
be32_to_cpu(k2->alloc.ar_startblock));
}
}
STATIC int
xfs_allocbt_recs_inorder(
struct xfs_btree_cur *cur,
union xfs_btree_rec *r1,
union xfs_btree_rec *r2)
{
if (cur->bc_btnum == XFS_BTNUM_BNO) {
return be32_to_cpu(r1->alloc.ar_startblock) +
be32_to_cpu(r1->alloc.ar_blockcount) <=
be32_to_cpu(r2->alloc.ar_startblock);
} else {
return be32_to_cpu(r1->alloc.ar_blockcount) <
be32_to_cpu(r2->alloc.ar_blockcount) ||
(r1->alloc.ar_blockcount == r2->alloc.ar_blockcount &&
be32_to_cpu(r1->alloc.ar_startblock) <
be32_to_cpu(r2->alloc.ar_startblock));
}
}
STATIC void
xfs_allocbt_trace_enter(
struct xfs_btree_cur *cur,
const char *func,
char *s,
int type,
int line,
__psunsigned_t a0,
__psunsigned_t a1,
__psunsigned_t a2,
__psunsigned_t a3,
__psunsigned_t a4,
__psunsigned_t a5,
__psunsigned_t a6,
__psunsigned_t a7,
__psunsigned_t a8,
__psunsigned_t a9,
__psunsigned_t a10)
{
ktrace_enter(xfs_allocbt_trace_buf, (void *)(__psint_t)type,
(void *)func, (void *)s, NULL, (void *)cur,
(void *)a0, (void *)a1, (void *)a2, (void *)a3,
(void *)a4, (void *)a5, (void *)a6, (void *)a7,
(void *)a8, (void *)a9, (void *)a10);
}
STATIC void
xfs_allocbt_trace_cursor(
struct xfs_btree_cur *cur,
__uint32_t *s0,
__uint64_t *l0,
__uint64_t *l1)
{
*s0 = cur->bc_private.a.agno;
*l0 = cur->bc_rec.a.ar_startblock;
*l1 = cur->bc_rec.a.ar_blockcount;
}
STATIC void
xfs_allocbt_trace_key(
struct xfs_btree_cur *cur,
union xfs_btree_key *key,
__uint64_t *l0,
__uint64_t *l1)
{
*l0 = be32_to_cpu(key->alloc.ar_startblock);
*l1 = be32_to_cpu(key->alloc.ar_blockcount);
}
STATIC void
xfs_allocbt_trace_record(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec,
__uint64_t *l0,
__uint64_t *l1,
__uint64_t *l2)
{
*l0 = be32_to_cpu(rec->alloc.ar_startblock);
*l1 = be32_to_cpu(rec->alloc.ar_blockcount);
*l2 = 0;
}
struct xfs_btree_cur *
xfs_allocbt_init_cursor(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agnumber_t agno,
xfs_btnum_t btnum)
{
struct xfs_agf *agf = XFS_BUF_TO_AGF(agbp);
struct xfs_btree_cur *cur;
ASSERT(btnum == XFS_BTNUM_BNO || btnum == XFS_BTNUM_CNT);
cur = kmem_zone_zalloc(xfs_btree_cur_zone, KM_SLEEP);
cur->bc_tp = tp;
cur->bc_mp = mp;
cur->bc_nlevels = be32_to_cpu(agf->agf_levels[btnum]);
cur->bc_btnum = btnum;
cur->bc_blocklog = mp->m_sb.sb_blocklog;
cur->bc_ops = &xfs_allocbt_ops;
if (btnum == XFS_BTNUM_CNT)
cur->bc_flags = XFS_BTREE_LASTREC_UPDATE;
cur->bc_private.a.agbp = agbp;
cur->bc_private.a.agno = agno;
return cur;
}
int
xfs_allocbt_maxrecs(
struct xfs_mount *mp,
int blocklen,
int leaf)
{
blocklen -= XFS_ALLOC_BLOCK_LEN(mp);
if (leaf)
return blocklen / sizeof(xfs_alloc_rec_t);
return blocklen / (sizeof(xfs_alloc_key_t) + sizeof(xfs_alloc_ptr_t));
}
