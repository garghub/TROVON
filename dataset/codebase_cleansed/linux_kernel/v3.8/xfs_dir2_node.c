static void
xfs_dir2_free_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dir2_free_hdr *hdr = bp->b_addr;
int block_ok = 0;
block_ok = hdr->magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC);
if (!block_ok) {
XFS_CORRUPTION_ERROR("xfs_dir2_free_verify magic",
XFS_ERRLEVEL_LOW, mp, hdr);
xfs_buf_ioerror(bp, EFSCORRUPTED);
}
}
static void
xfs_dir2_free_read_verify(
struct xfs_buf *bp)
{
xfs_dir2_free_verify(bp);
}
static void
xfs_dir2_free_write_verify(
struct xfs_buf *bp)
{
xfs_dir2_free_verify(bp);
}
static int
__xfs_dir2_free_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
xfs_daddr_t mappedbno,
struct xfs_buf **bpp)
{
return xfs_da_read_buf(tp, dp, fbno, mappedbno, bpp,
XFS_DATA_FORK, &xfs_dir2_free_buf_ops);
}
int
xfs_dir2_free_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
struct xfs_buf **bpp)
{
return __xfs_dir2_free_read(tp, dp, fbno, -1, bpp);
}
static int
xfs_dir2_free_try_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
struct xfs_buf **bpp)
{
return __xfs_dir2_free_read(tp, dp, fbno, -2, bpp);
}
STATIC void
xfs_dir2_free_log_bests(
struct xfs_trans *tp,
struct xfs_buf *bp,
int first,
int last)
{
xfs_dir2_free_t *free;
free = bp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
xfs_trans_log_buf(tp, bp,
(uint)((char *)&free->bests[first] - (char *)free),
(uint)((char *)&free->bests[last] - (char *)free +
sizeof(free->bests[0]) - 1));
}
static void
xfs_dir2_free_log_header(
struct xfs_trans *tp,
struct xfs_buf *bp)
{
xfs_dir2_free_t *free;
free = bp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
xfs_trans_log_buf(tp, bp, (uint)((char *)&free->hdr - (char *)free),
(uint)(sizeof(xfs_dir2_free_hdr_t) - 1));
}
int
xfs_dir2_leaf_to_node(
xfs_da_args_t *args,
struct xfs_buf *lbp)
{
xfs_inode_t *dp;
int error;
struct xfs_buf *fbp;
xfs_dir2_db_t fdb;
xfs_dir2_free_t *free;
__be16 *from;
int i;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int n;
xfs_dir2_data_off_t off;
__be16 *to;
xfs_trans_t *tp;
trace_xfs_dir2_leaf_to_node(args);
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
if ((error = xfs_dir2_grow_inode(args, XFS_DIR2_FREE_SPACE, &fdb))) {
return error;
}
ASSERT(fdb == XFS_DIR2_FREE_FIRSTDB(mp));
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(mp, fdb), -1, &fbp,
XFS_DATA_FORK);
if (error)
return error;
fbp->b_ops = &xfs_dir2_free_buf_ops;
free = fbp->b_addr;
leaf = lbp->b_addr;
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
free->hdr.magic = cpu_to_be32(XFS_DIR2_FREE_MAGIC);
free->hdr.firstdb = 0;
ASSERT(be32_to_cpu(ltp->bestcount) <= (uint)dp->i_d.di_size / mp->m_dirblksize);
free->hdr.nvalid = ltp->bestcount;
for (i = n = 0, from = xfs_dir2_leaf_bests_p(ltp), to = free->bests;
i < be32_to_cpu(ltp->bestcount); i++, from++, to++) {
if ((off = be16_to_cpu(*from)) != NULLDATAOFF)
n++;
*to = cpu_to_be16(off);
}
free->hdr.nused = cpu_to_be32(n);
lbp->b_ops = &xfs_dir2_leafn_buf_ops;
leaf->hdr.info.magic = cpu_to_be16(XFS_DIR2_LEAFN_MAGIC);
xfs_dir2_leaf_log_header(tp, lbp);
xfs_dir2_free_log_header(tp, fbp);
xfs_dir2_free_log_bests(tp, fbp, 0, be32_to_cpu(free->hdr.nvalid) - 1);
xfs_dir2_leafn_check(dp, lbp);
return 0;
}
static int
xfs_dir2_leafn_add(
struct xfs_buf *bp,
xfs_da_args_t *args,
int index)
{
int compact;
xfs_inode_t *dp;
int highstale;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int lfloghigh;
int lfloglow;
int lowstale;
xfs_mount_t *mp;
xfs_trans_t *tp;
trace_xfs_dir2_leafn_add(args, index);
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
leaf = bp->b_addr;
if (index < 0)
return XFS_ERROR(EFSCORRUPTED);
if (be16_to_cpu(leaf->hdr.count) == xfs_dir2_max_leaf_ents(mp)) {
if (!leaf->hdr.stale)
return XFS_ERROR(ENOSPC);
compact = be16_to_cpu(leaf->hdr.stale) > 1;
} else
compact = 0;
ASSERT(index == 0 || be32_to_cpu(leaf->ents[index - 1].hashval) <= args->hashval);
ASSERT(index == be16_to_cpu(leaf->hdr.count) ||
be32_to_cpu(leaf->ents[index].hashval) >= args->hashval);
if (args->op_flags & XFS_DA_OP_JUSTCHECK)
return 0;
if (compact) {
xfs_dir2_leaf_compact_x1(bp, &index, &lowstale, &highstale,
&lfloglow, &lfloghigh);
}
else if (leaf->hdr.stale) {
lfloglow = be16_to_cpu(leaf->hdr.count);
lfloghigh = -1;
}
lep = xfs_dir2_leaf_find_entry(leaf, index, compact, lowstale,
highstale, &lfloglow, &lfloghigh);
lep->hashval = cpu_to_be32(args->hashval);
lep->address = cpu_to_be32(xfs_dir2_db_off_to_dataptr(mp,
args->blkno, args->index));
xfs_dir2_leaf_log_header(tp, bp);
xfs_dir2_leaf_log_ents(tp, bp, lfloglow, lfloghigh);
xfs_dir2_leafn_check(dp, bp);
return 0;
}
void
xfs_dir2_leafn_check(
struct xfs_inode *dp,
struct xfs_buf *bp)
{
int i;
xfs_dir2_leaf_t *leaf;
xfs_mount_t *mp;
int stale;
leaf = bp->b_addr;
mp = dp->i_mount;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
ASSERT(be16_to_cpu(leaf->hdr.count) <= xfs_dir2_max_leaf_ents(mp));
for (i = stale = 0; i < be16_to_cpu(leaf->hdr.count); i++) {
if (i + 1 < be16_to_cpu(leaf->hdr.count)) {
ASSERT(be32_to_cpu(leaf->ents[i].hashval) <=
be32_to_cpu(leaf->ents[i + 1].hashval));
}
if (leaf->ents[i].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
stale++;
}
ASSERT(be16_to_cpu(leaf->hdr.stale) == stale);
}
xfs_dahash_t
xfs_dir2_leafn_lasthash(
struct xfs_buf *bp,
int *count)
{
xfs_dir2_leaf_t *leaf;
leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
if (count)
*count = be16_to_cpu(leaf->hdr.count);
if (!leaf->hdr.count)
return 0;
return be32_to_cpu(leaf->ents[be16_to_cpu(leaf->hdr.count) - 1].hashval);
}
STATIC int
xfs_dir2_leafn_lookup_for_addname(
struct xfs_buf *bp,
xfs_da_args_t *args,
int *indexp,
xfs_da_state_t *state)
{
struct xfs_buf *curbp = NULL;
xfs_dir2_db_t curdb = -1;
xfs_dir2_db_t curfdb = -1;
xfs_inode_t *dp;
int error;
int fi;
xfs_dir2_free_t *free = NULL;
int index;
xfs_dir2_leaf_t *leaf;
int length;
xfs_dir2_leaf_entry_t *lep;
xfs_mount_t *mp;
xfs_dir2_db_t newdb;
xfs_dir2_db_t newfdb;
xfs_trans_t *tp;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
#ifdef __KERNEL__
ASSERT(be16_to_cpu(leaf->hdr.count) > 0);
#endif
xfs_dir2_leafn_check(dp, bp);
index = xfs_dir2_leaf_search_hash(args, bp);
if (state->extravalid) {
curbp = state->extrablk.bp;
curfdb = state->extrablk.blkno;
free = curbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
}
length = xfs_dir2_data_entsize(args->namelen);
for (lep = &leaf->ents[index]; index < be16_to_cpu(leaf->hdr.count) &&
be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
if (newdb != curdb) {
curdb = newdb;
newfdb = xfs_dir2_db_to_fdb(mp, newdb);
if (newfdb != curfdb) {
if (curbp)
xfs_trans_brelse(tp, curbp);
error = xfs_dir2_free_read(tp, dp,
xfs_dir2_db_to_da(mp, newfdb),
&curbp);
if (error)
return error;
free = curbp->b_addr;
ASSERT(be32_to_cpu(free->hdr.magic) ==
XFS_DIR2_FREE_MAGIC);
ASSERT((be32_to_cpu(free->hdr.firstdb) %
xfs_dir2_free_max_bests(mp)) == 0);
ASSERT(be32_to_cpu(free->hdr.firstdb) <= curdb);
ASSERT(curdb < be32_to_cpu(free->hdr.firstdb) +
be32_to_cpu(free->hdr.nvalid));
}
fi = xfs_dir2_db_to_fdindex(mp, curdb);
if (unlikely(free->bests[fi] ==
cpu_to_be16(NULLDATAOFF))) {
XFS_ERROR_REPORT("xfs_dir2_leafn_lookup_int",
XFS_ERRLEVEL_LOW, mp);
if (curfdb != newfdb)
xfs_trans_brelse(tp, curbp);
return XFS_ERROR(EFSCORRUPTED);
}
curfdb = newfdb;
if (be16_to_cpu(free->bests[fi]) >= length)
goto out;
}
}
fi = -1;
out:
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (curbp) {
state->extravalid = 1;
state->extrablk.bp = curbp;
state->extrablk.index = fi;
state->extrablk.blkno = curfdb;
state->extrablk.magic = XFS_DIR2_FREE_MAGIC;
} else {
state->extravalid = 0;
}
*indexp = index;
return XFS_ERROR(ENOENT);
}
STATIC int
xfs_dir2_leafn_lookup_for_entry(
struct xfs_buf *bp,
xfs_da_args_t *args,
int *indexp,
xfs_da_state_t *state)
{
struct xfs_buf *curbp = NULL;
xfs_dir2_db_t curdb = -1;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_mount_t *mp;
xfs_dir2_db_t newdb;
xfs_trans_t *tp;
enum xfs_dacmp cmp;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
#ifdef __KERNEL__
ASSERT(be16_to_cpu(leaf->hdr.count) > 0);
#endif
xfs_dir2_leafn_check(dp, bp);
index = xfs_dir2_leaf_search_hash(args, bp);
if (state->extravalid) {
curbp = state->extrablk.bp;
curdb = state->extrablk.blkno;
}
for (lep = &leaf->ents[index]; index < be16_to_cpu(leaf->hdr.count) &&
be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
if (newdb != curdb) {
if (curbp && (args->cmpresult == XFS_CMP_DIFFERENT ||
curdb != state->extrablk.blkno))
xfs_trans_brelse(tp, curbp);
if (args->cmpresult != XFS_CMP_DIFFERENT &&
newdb == state->extrablk.blkno) {
ASSERT(state->extravalid);
curbp = state->extrablk.bp;
} else {
error = xfs_dir2_data_read(tp, dp,
xfs_dir2_db_to_da(mp, newdb),
-1, &curbp);
if (error)
return error;
}
xfs_dir2_data_check(dp, curbp);
curdb = newdb;
}
dep = (xfs_dir2_data_entry_t *)((char *)curbp->b_addr +
xfs_dir2_dataptr_to_off(mp, be32_to_cpu(lep->address)));
cmp = mp->m_dirnameops->compname(args, dep->name, dep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
if (args->cmpresult != XFS_CMP_DIFFERENT &&
curdb != state->extrablk.blkno)
xfs_trans_brelse(tp, state->extrablk.bp);
args->cmpresult = cmp;
args->inumber = be64_to_cpu(dep->inumber);
*indexp = index;
state->extravalid = 1;
state->extrablk.bp = curbp;
state->extrablk.blkno = curdb;
state->extrablk.index = (int)((char *)dep -
(char *)curbp->b_addr);
state->extrablk.magic = XFS_DIR2_DATA_MAGIC;
curbp->b_ops = &xfs_dir2_data_buf_ops;
if (cmp == XFS_CMP_EXACT)
return XFS_ERROR(EEXIST);
}
}
ASSERT(index == be16_to_cpu(leaf->hdr.count) ||
(args->op_flags & XFS_DA_OP_OKNOENT));
if (curbp) {
if (args->cmpresult == XFS_CMP_DIFFERENT) {
state->extravalid = 1;
state->extrablk.bp = curbp;
state->extrablk.index = -1;
state->extrablk.blkno = curdb;
state->extrablk.magic = XFS_DIR2_DATA_MAGIC;
curbp->b_ops = &xfs_dir2_data_buf_ops;
} else {
if (state->extrablk.bp != curbp)
xfs_trans_brelse(tp, curbp);
}
} else {
state->extravalid = 0;
}
*indexp = index;
return XFS_ERROR(ENOENT);
}
int
xfs_dir2_leafn_lookup_int(
struct xfs_buf *bp,
xfs_da_args_t *args,
int *indexp,
xfs_da_state_t *state)
{
if (args->op_flags & XFS_DA_OP_ADDNAME)
return xfs_dir2_leafn_lookup_for_addname(bp, args, indexp,
state);
return xfs_dir2_leafn_lookup_for_entry(bp, args, indexp, state);
}
static void
xfs_dir2_leafn_moveents(
xfs_da_args_t *args,
struct xfs_buf *bp_s,
int start_s,
struct xfs_buf *bp_d,
int start_d,
int count)
{
xfs_dir2_leaf_t *leaf_d;
xfs_dir2_leaf_t *leaf_s;
int stale;
xfs_trans_t *tp;
trace_xfs_dir2_leafn_moveents(args, start_s, start_d, count);
if (count == 0) {
return;
}
tp = args->trans;
leaf_s = bp_s->b_addr;
leaf_d = bp_d->b_addr;
if (start_d < be16_to_cpu(leaf_d->hdr.count)) {
memmove(&leaf_d->ents[start_d + count], &leaf_d->ents[start_d],
(be16_to_cpu(leaf_d->hdr.count) - start_d) *
sizeof(xfs_dir2_leaf_entry_t));
xfs_dir2_leaf_log_ents(tp, bp_d, start_d + count,
count + be16_to_cpu(leaf_d->hdr.count) - 1);
}
if (leaf_s->hdr.stale) {
int i;
for (i = start_s, stale = 0; i < start_s + count; i++) {
if (leaf_s->ents[i].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
stale++;
}
} else
stale = 0;
memcpy(&leaf_d->ents[start_d], &leaf_s->ents[start_s],
count * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir2_leaf_log_ents(tp, bp_d, start_d, start_d + count - 1);
if (start_s + count < be16_to_cpu(leaf_s->hdr.count)) {
memmove(&leaf_s->ents[start_s], &leaf_s->ents[start_s + count],
count * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir2_leaf_log_ents(tp, bp_s, start_s, start_s + count - 1);
}
be16_add_cpu(&leaf_s->hdr.count, -(count));
be16_add_cpu(&leaf_s->hdr.stale, -(stale));
be16_add_cpu(&leaf_d->hdr.count, count);
be16_add_cpu(&leaf_d->hdr.stale, stale);
xfs_dir2_leaf_log_header(tp, bp_s);
xfs_dir2_leaf_log_header(tp, bp_d);
xfs_dir2_leafn_check(args->dp, bp_s);
xfs_dir2_leafn_check(args->dp, bp_d);
}
int
xfs_dir2_leafn_order(
struct xfs_buf *leaf1_bp,
struct xfs_buf *leaf2_bp)
{
xfs_dir2_leaf_t *leaf1;
xfs_dir2_leaf_t *leaf2;
leaf1 = leaf1_bp->b_addr;
leaf2 = leaf2_bp->b_addr;
ASSERT(leaf1->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
ASSERT(leaf2->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
if (be16_to_cpu(leaf1->hdr.count) > 0 &&
be16_to_cpu(leaf2->hdr.count) > 0 &&
(be32_to_cpu(leaf2->ents[0].hashval) < be32_to_cpu(leaf1->ents[0].hashval) ||
be32_to_cpu(leaf2->ents[be16_to_cpu(leaf2->hdr.count) - 1].hashval) <
be32_to_cpu(leaf1->ents[be16_to_cpu(leaf1->hdr.count) - 1].hashval)))
return 1;
return 0;
}
static void
xfs_dir2_leafn_rebalance(
xfs_da_state_t *state,
xfs_da_state_blk_t *blk1,
xfs_da_state_blk_t *blk2)
{
xfs_da_args_t *args;
int count;
int isleft;
xfs_dir2_leaf_t *leaf1;
xfs_dir2_leaf_t *leaf2;
int mid;
#ifdef DEBUG
int oldstale;
#endif
int oldsum;
int swap;
args = state->args;
if ((swap = xfs_dir2_leafn_order(blk1->bp, blk2->bp))) {
xfs_da_state_blk_t *tmp;
tmp = blk1;
blk1 = blk2;
blk2 = tmp;
}
leaf1 = blk1->bp->b_addr;
leaf2 = blk2->bp->b_addr;
oldsum = be16_to_cpu(leaf1->hdr.count) + be16_to_cpu(leaf2->hdr.count);
#ifdef DEBUG
oldstale = be16_to_cpu(leaf1->hdr.stale) + be16_to_cpu(leaf2->hdr.stale);
#endif
mid = oldsum >> 1;
if (oldsum & 1) {
xfs_dahash_t midhash;
if (mid >= be16_to_cpu(leaf1->hdr.count))
midhash = be32_to_cpu(leaf2->ents[mid - be16_to_cpu(leaf1->hdr.count)].hashval);
else
midhash = be32_to_cpu(leaf1->ents[mid].hashval);
isleft = args->hashval <= midhash;
}
else
isleft = 1;
count = be16_to_cpu(leaf1->hdr.count) - mid + (isleft == 0);
if (count > 0)
xfs_dir2_leafn_moveents(args, blk1->bp,
be16_to_cpu(leaf1->hdr.count) - count, blk2->bp, 0, count);
else if (count < 0)
xfs_dir2_leafn_moveents(args, blk2->bp, 0, blk1->bp,
be16_to_cpu(leaf1->hdr.count), count);
ASSERT(be16_to_cpu(leaf1->hdr.count) + be16_to_cpu(leaf2->hdr.count) == oldsum);
ASSERT(be16_to_cpu(leaf1->hdr.stale) + be16_to_cpu(leaf2->hdr.stale) == oldstale);
if (be16_to_cpu(leaf1->hdr.count) < be16_to_cpu(leaf2->hdr.count))
state->inleaf = swap;
else if (be16_to_cpu(leaf1->hdr.count) > be16_to_cpu(leaf2->hdr.count))
state->inleaf = !swap;
else
state->inleaf =
swap ^ (blk1->index <= be16_to_cpu(leaf1->hdr.count));
if (!state->inleaf)
blk2->index = blk1->index - be16_to_cpu(leaf1->hdr.count);
if(blk2->index < 0) {
state->inleaf = 1;
blk2->index = 0;
xfs_alert(args->dp->i_mount,
"%s: picked the wrong leaf? reverting original leaf: blk1->index %d\n",
__func__, blk1->index);
}
}
static int
xfs_dir2_data_block_free(
xfs_da_args_t *args,
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_free *free,
xfs_dir2_db_t fdb,
int findex,
struct xfs_buf *fbp,
int longest)
{
struct xfs_trans *tp = args->trans;
int logfree = 0;
if (!hdr) {
be32_add_cpu(&free->hdr.nused, -1);
xfs_dir2_free_log_header(tp, fbp);
if (findex == be32_to_cpu(free->hdr.nvalid) - 1) {
int i;
for (i = findex - 1; i >= 0; i--) {
if (free->bests[i] != cpu_to_be16(NULLDATAOFF))
break;
}
free->hdr.nvalid = cpu_to_be32(i + 1);
logfree = 0;
} else {
free->bests[findex] = cpu_to_be16(NULLDATAOFF);
logfree = 1;
}
if (!free->hdr.nused) {
int error;
error = xfs_dir2_shrink_inode(args, fdb, fbp);
if (error == 0) {
fbp = NULL;
logfree = 0;
} else if (error != ENOSPC || args->total != 0)
return error;
}
} else {
free->bests[findex] = cpu_to_be16(longest);
logfree = 1;
}
if (logfree)
xfs_dir2_free_log_bests(tp, fbp, findex, findex);
return 0;
}
static int
xfs_dir2_leafn_remove(
xfs_da_args_t *args,
struct xfs_buf *bp,
int index,
xfs_da_state_blk_t *dblk,
int *rval)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_db_t db;
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int longest;
int off;
xfs_mount_t *mp;
int needlog;
int needscan;
xfs_trans_t *tp;
trace_xfs_dir2_leafn_remove(args, index);
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
lep = &leaf->ents[index];
db = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
ASSERT(dblk->blkno == db);
off = xfs_dir2_dataptr_to_off(mp, be32_to_cpu(lep->address));
ASSERT(dblk->index == off);
be16_add_cpu(&leaf->hdr.stale, 1);
xfs_dir2_leaf_log_header(tp, bp);
lep->address = cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
xfs_dir2_leaf_log_ents(tp, bp, index, index);
dbp = dblk->bp;
hdr = dbp->b_addr;
dep = (xfs_dir2_data_entry_t *)((char *)hdr + off);
longest = be16_to_cpu(hdr->bestfree[0].length);
needlog = needscan = 0;
xfs_dir2_data_make_free(tp, dbp, off,
xfs_dir2_data_entsize(dep->namelen), &needlog, &needscan);
if (needscan)
xfs_dir2_data_freescan(mp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dbp);
xfs_dir2_data_check(dp, dbp);
if (longest < be16_to_cpu(hdr->bestfree[0].length)) {
int error;
struct xfs_buf *fbp;
xfs_dir2_db_t fdb;
int findex;
xfs_dir2_free_t *free;
fdb = xfs_dir2_db_to_fdb(mp, db);
error = xfs_dir2_free_read(tp, dp, xfs_dir2_db_to_da(mp, fdb),
&fbp);
if (error)
return error;
free = fbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
ASSERT(be32_to_cpu(free->hdr.firstdb) ==
xfs_dir2_free_max_bests(mp) *
(fdb - XFS_DIR2_FREE_FIRSTDB(mp)));
findex = xfs_dir2_db_to_fdindex(mp, db);
longest = be16_to_cpu(hdr->bestfree[0].length);
if (longest == mp->m_dirblksize - (uint)sizeof(*hdr)) {
error = xfs_dir2_shrink_inode(args, db, dbp);
if (error == 0) {
dblk->bp = NULL;
hdr = NULL;
}
else if (!(error == ENOSPC && args->total == 0))
return error;
}
error = xfs_dir2_data_block_free(args, hdr, free,
fdb, findex, fbp, longest);
if (error)
return error;
}
xfs_dir2_leafn_check(dp, bp);
*rval =
((uint)sizeof(leaf->hdr) +
(uint)sizeof(leaf->ents[0]) *
(be16_to_cpu(leaf->hdr.count) - be16_to_cpu(leaf->hdr.stale))) <
mp->m_dir_magicpct;
return 0;
}
int
xfs_dir2_leafn_split(
xfs_da_state_t *state,
xfs_da_state_blk_t *oldblk,
xfs_da_state_blk_t *newblk)
{
xfs_da_args_t *args;
xfs_dablk_t blkno;
int error;
xfs_mount_t *mp;
args = state->args;
mp = args->dp->i_mount;
ASSERT(args != NULL);
ASSERT(oldblk->magic == XFS_DIR2_LEAFN_MAGIC);
error = xfs_da_grow_inode(args, &blkno);
if (error) {
return error;
}
error = xfs_dir2_leaf_init(args, xfs_dir2_da_to_db(mp, blkno),
&newblk->bp, XFS_DIR2_LEAFN_MAGIC);
if (error) {
return error;
}
newblk->blkno = blkno;
newblk->magic = XFS_DIR2_LEAFN_MAGIC;
xfs_dir2_leafn_rebalance(state, oldblk, newblk);
error = xfs_da_blk_link(state, oldblk, newblk);
if (error) {
return error;
}
if (state->inleaf)
error = xfs_dir2_leafn_add(oldblk->bp, args, oldblk->index);
else
error = xfs_dir2_leafn_add(newblk->bp, args, newblk->index);
oldblk->hashval = xfs_dir2_leafn_lasthash(oldblk->bp, NULL);
newblk->hashval = xfs_dir2_leafn_lasthash(newblk->bp, NULL);
xfs_dir2_leafn_check(args->dp, oldblk->bp);
xfs_dir2_leafn_check(args->dp, newblk->bp);
return error;
}
int
xfs_dir2_leafn_toosmall(
xfs_da_state_t *state,
int *action)
{
xfs_da_state_blk_t *blk;
xfs_dablk_t blkno;
struct xfs_buf *bp;
int bytes;
int count;
int error;
int forward;
int i;
xfs_da_blkinfo_t *info;
xfs_dir2_leaf_t *leaf;
int rval;
blk = &state->path.blk[state->path.active - 1];
info = blk->bp->b_addr;
ASSERT(info->magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
leaf = (xfs_dir2_leaf_t *)info;
count = be16_to_cpu(leaf->hdr.count) - be16_to_cpu(leaf->hdr.stale);
bytes = (uint)sizeof(leaf->hdr) + count * (uint)sizeof(leaf->ents[0]);
if (bytes > (state->blocksize >> 1)) {
*action = 0;
return 0;
}
if (count == 0) {
forward = (info->forw != 0);
memcpy(&state->altpath, &state->path, sizeof(state->path));
error = xfs_da_path_shift(state, &state->altpath, forward, 0,
&rval);
if (error)
return error;
*action = rval ? 2 : 0;
return 0;
}
forward = be32_to_cpu(info->forw) < be32_to_cpu(info->back);
for (i = 0, bp = NULL; i < 2; forward = !forward, i++) {
blkno = forward ? be32_to_cpu(info->forw) : be32_to_cpu(info->back);
if (blkno == 0)
continue;
error = xfs_dir2_leafn_read(state->args->trans, state->args->dp,
blkno, -1, &bp);
if (error)
return error;
leaf = (xfs_dir2_leaf_t *)info;
count = be16_to_cpu(leaf->hdr.count) - be16_to_cpu(leaf->hdr.stale);
bytes = state->blocksize - (state->blocksize >> 2);
leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
count += be16_to_cpu(leaf->hdr.count) - be16_to_cpu(leaf->hdr.stale);
bytes -= count * (uint)sizeof(leaf->ents[0]);
if (bytes >= 0)
break;
xfs_trans_brelse(state->args->trans, bp);
}
if (i >= 2) {
*action = 0;
return 0;
}
memcpy(&state->altpath, &state->path, sizeof(state->path));
if (blkno < blk->blkno)
error = xfs_da_path_shift(state, &state->altpath, forward, 0,
&rval);
else
error = xfs_da_path_shift(state, &state->path, forward, 0,
&rval);
if (error) {
return error;
}
*action = rval ? 0 : 1;
return 0;
}
void
xfs_dir2_leafn_unbalance(
xfs_da_state_t *state,
xfs_da_state_blk_t *drop_blk,
xfs_da_state_blk_t *save_blk)
{
xfs_da_args_t *args;
xfs_dir2_leaf_t *drop_leaf;
xfs_dir2_leaf_t *save_leaf;
args = state->args;
ASSERT(drop_blk->magic == XFS_DIR2_LEAFN_MAGIC);
ASSERT(save_blk->magic == XFS_DIR2_LEAFN_MAGIC);
drop_leaf = drop_blk->bp->b_addr;
save_leaf = save_blk->bp->b_addr;
ASSERT(drop_leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
ASSERT(save_leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
if (drop_leaf->hdr.stale)
xfs_dir2_leaf_compact(args, drop_blk->bp);
if (save_leaf->hdr.stale)
xfs_dir2_leaf_compact(args, save_blk->bp);
drop_blk->hashval = be32_to_cpu(drop_leaf->ents[be16_to_cpu(drop_leaf->hdr.count) - 1].hashval);
if (xfs_dir2_leafn_order(save_blk->bp, drop_blk->bp))
xfs_dir2_leafn_moveents(args, drop_blk->bp, 0, save_blk->bp, 0,
be16_to_cpu(drop_leaf->hdr.count));
else
xfs_dir2_leafn_moveents(args, drop_blk->bp, 0, save_blk->bp,
be16_to_cpu(save_leaf->hdr.count), be16_to_cpu(drop_leaf->hdr.count));
save_blk->hashval = be32_to_cpu(save_leaf->ents[be16_to_cpu(save_leaf->hdr.count) - 1].hashval);
xfs_dir2_leafn_check(args->dp, save_blk->bp);
}
int
xfs_dir2_node_addname(
xfs_da_args_t *args)
{
xfs_da_state_blk_t *blk;
int error;
int rval;
xfs_da_state_t *state;
trace_xfs_dir2_node_addname(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
state->blocksize = state->mp->m_dirblksize;
state->node_ents = state->mp->m_dir_node_ents;
error = xfs_da_node_lookup_int(state, &rval);
if (error)
rval = error;
if (rval != ENOENT) {
goto done;
}
rval = xfs_dir2_node_addname_int(args,
state->extravalid ? &state->extrablk : NULL);
if (rval) {
goto done;
}
blk = &state->path.blk[state->path.active - 1];
ASSERT(blk->magic == XFS_DIR2_LEAFN_MAGIC);
rval = xfs_dir2_leafn_add(blk->bp, args, blk->index);
if (rval == 0) {
if (!(args->op_flags & XFS_DA_OP_JUSTCHECK))
xfs_da_fixhashpath(state, &state->path);
} else {
if (args->total == 0) {
ASSERT(rval == ENOSPC);
goto done;
}
rval = xfs_da_split(state);
}
done:
xfs_da_state_free(state);
return rval;
}
static int
xfs_dir2_node_addname_int(
xfs_da_args_t *args,
xfs_da_state_blk_t *fblk)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_db_t dbno;
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
xfs_dir2_db_t fbno;
struct xfs_buf *fbp;
int findex;
xfs_dir2_free_t *free=NULL;
xfs_dir2_db_t ifbno;
xfs_dir2_db_t lastfbno=0;
int length;
int logfree;
xfs_mount_t *mp;
int needlog;
int needscan;
__be16 *tagp;
xfs_trans_t *tp;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
length = xfs_dir2_data_entsize(args->namelen);
if (fblk) {
fbp = fblk->bp;
ifbno = fblk->blkno;
free = fbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
findex = fblk->index;
if (findex >= 0) {
ASSERT(findex < be32_to_cpu(free->hdr.nvalid));
ASSERT(be16_to_cpu(free->bests[findex]) != NULLDATAOFF);
ASSERT(be16_to_cpu(free->bests[findex]) >= length);
dbno = be32_to_cpu(free->hdr.firstdb) + findex;
}
else {
dbno = -1;
findex = 0;
}
}
else {
ifbno = dbno = -1;
fbp = NULL;
findex = 0;
}
if (dbno == -1) {
xfs_fileoff_t fo;
if ((error = xfs_bmap_last_offset(tp, dp, &fo, XFS_DATA_FORK)))
return error;
lastfbno = xfs_dir2_da_to_db(mp, (xfs_dablk_t)fo);
fbno = ifbno;
}
while (dbno == -1) {
if (fbp == NULL) {
if (++fbno == 0)
fbno = XFS_DIR2_FREE_FIRSTDB(mp);
if (fbno == ifbno)
fbno++;
if (fbno >= lastfbno)
break;
error = xfs_dir2_free_try_read(tp, dp,
xfs_dir2_db_to_da(mp, fbno),
&fbp);
if (error)
return error;
if (!fbp)
continue;
free = fbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
findex = 0;
}
if (be16_to_cpu(free->bests[findex]) != NULLDATAOFF &&
be16_to_cpu(free->bests[findex]) >= length)
dbno = be32_to_cpu(free->hdr.firstdb) + findex;
else {
if (++findex == be32_to_cpu(free->hdr.nvalid)) {
xfs_trans_brelse(tp, fbp);
fbp = NULL;
if (fblk && fblk->bp)
fblk->bp = NULL;
}
}
}
if (unlikely(dbno == -1)) {
if ((args->op_flags & XFS_DA_OP_JUSTCHECK) || args->total == 0)
return XFS_ERROR(ENOSPC);
if (unlikely((error = xfs_dir2_grow_inode(args,
XFS_DIR2_DATA_SPACE,
&dbno)) ||
(error = xfs_dir2_data_init(args, dbno, &dbp))))
return error;
if (fbp)
xfs_trans_brelse(tp, fbp);
if (fblk && fblk->bp)
fblk->bp = NULL;
fbno = xfs_dir2_db_to_fdb(mp, dbno);
error = xfs_dir2_free_try_read(tp, dp,
xfs_dir2_db_to_da(mp, fbno),
&fbp);
if (error)
return error;
if( fbp == NULL ) {
if ((error = xfs_dir2_grow_inode(args, XFS_DIR2_FREE_SPACE,
&fbno))) {
return error;
}
if (unlikely(xfs_dir2_db_to_fdb(mp, dbno) != fbno)) {
xfs_alert(mp,
"%s: dir ino %llu needed freesp block %lld for\n"
" data block %lld, got %lld ifbno %llu lastfbno %d",
__func__, (unsigned long long)dp->i_ino,
(long long)xfs_dir2_db_to_fdb(mp, dbno),
(long long)dbno, (long long)fbno,
(unsigned long long)ifbno, lastfbno);
if (fblk) {
xfs_alert(mp,
" fblk 0x%p blkno %llu index %d magic 0x%x",
fblk,
(unsigned long long)fblk->blkno,
fblk->index,
fblk->magic);
} else {
xfs_alert(mp, " ... fblk is NULL");
}
XFS_ERROR_REPORT("xfs_dir2_node_addname_int",
XFS_ERRLEVEL_LOW, mp);
return XFS_ERROR(EFSCORRUPTED);
}
error = xfs_da_get_buf(tp, dp,
xfs_dir2_db_to_da(mp, fbno),
-1, &fbp, XFS_DATA_FORK);
if (error)
return error;
fbp->b_ops = &xfs_dir2_free_buf_ops;
free = fbp->b_addr;
free->hdr.magic = cpu_to_be32(XFS_DIR2_FREE_MAGIC);
free->hdr.firstdb = cpu_to_be32(
(fbno - XFS_DIR2_FREE_FIRSTDB(mp)) *
xfs_dir2_free_max_bests(mp));
free->hdr.nvalid = 0;
free->hdr.nused = 0;
} else {
free = fbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
}
findex = xfs_dir2_db_to_fdindex(mp, dbno);
if (findex >= be32_to_cpu(free->hdr.nvalid)) {
ASSERT(findex < xfs_dir2_free_max_bests(mp));
free->hdr.nvalid = cpu_to_be32(findex + 1);
free->bests[findex] = cpu_to_be16(NULLDATAOFF);
}
if (free->bests[findex] == cpu_to_be16(NULLDATAOFF)) {
be32_add_cpu(&free->hdr.nused, 1);
xfs_dir2_free_log_header(tp, fbp);
}
hdr = dbp->b_addr;
free->bests[findex] = hdr->bestfree[0].length;
logfree = 1;
}
else {
if (args->op_flags & XFS_DA_OP_JUSTCHECK)
return 0;
error = xfs_dir2_data_read(tp, dp, xfs_dir2_db_to_da(mp, dbno),
-1, &dbp);
if (error)
return error;
hdr = dbp->b_addr;
logfree = 0;
}
ASSERT(be16_to_cpu(hdr->bestfree[0].length) >= length);
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(hdr->bestfree[0].offset));
needscan = needlog = 0;
xfs_dir2_data_use_free(tp, dbp, dup,
(xfs_dir2_data_aoff_t)((char *)dup - (char *)hdr), length,
&needlog, &needscan);
dep = (xfs_dir2_data_entry_t *)dup;
dep->inumber = cpu_to_be64(args->inumber);
dep->namelen = args->namelen;
memcpy(dep->name, args->name, dep->namelen);
tagp = xfs_dir2_data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
xfs_dir2_data_log_entry(tp, dbp, dep);
if (needscan)
xfs_dir2_data_freescan(mp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dbp);
if (be16_to_cpu(free->bests[findex]) != be16_to_cpu(hdr->bestfree[0].length)) {
free->bests[findex] = hdr->bestfree[0].length;
logfree = 1;
}
if (logfree)
xfs_dir2_free_log_bests(tp, fbp, findex, findex);
args->blkno = (xfs_dablk_t)dbno;
args->index = be16_to_cpu(*tagp);
return 0;
}
int
xfs_dir2_node_lookup(
xfs_da_args_t *args)
{
int error;
int i;
int rval;
xfs_da_state_t *state;
trace_xfs_dir2_node_lookup(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
state->blocksize = state->mp->m_dirblksize;
state->node_ents = state->mp->m_dir_node_ents;
error = xfs_da_node_lookup_int(state, &rval);
if (error)
rval = error;
else if (rval == ENOENT && args->cmpresult == XFS_CMP_CASE) {
xfs_dir2_data_entry_t *dep;
dep = (xfs_dir2_data_entry_t *)
((char *)state->extrablk.bp->b_addr +
state->extrablk.index);
rval = xfs_dir_cilookup_result(args, dep->name, dep->namelen);
}
for (i = 0; i < state->path.active; i++) {
xfs_trans_brelse(args->trans, state->path.blk[i].bp);
state->path.blk[i].bp = NULL;
}
if (state->extravalid && state->extrablk.bp) {
xfs_trans_brelse(args->trans, state->extrablk.bp);
state->extrablk.bp = NULL;
}
xfs_da_state_free(state);
return rval;
}
int
xfs_dir2_node_removename(
xfs_da_args_t *args)
{
xfs_da_state_blk_t *blk;
int error;
int rval;
xfs_da_state_t *state;
trace_xfs_dir2_node_removename(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
state->blocksize = state->mp->m_dirblksize;
state->node_ents = state->mp->m_dir_node_ents;
error = xfs_da_node_lookup_int(state, &rval);
if (error)
rval = error;
if (rval != EEXIST) {
xfs_da_state_free(state);
return rval;
}
blk = &state->path.blk[state->path.active - 1];
ASSERT(blk->magic == XFS_DIR2_LEAFN_MAGIC);
ASSERT(state->extravalid);
error = xfs_dir2_leafn_remove(args, blk->bp, blk->index,
&state->extrablk, &rval);
if (error)
return error;
xfs_da_fixhashpath(state, &state->path);
if (rval && state->path.active > 1)
error = xfs_da_join(state);
if (!error)
error = xfs_dir2_node_to_leaf(state);
xfs_da_state_free(state);
return error;
}
int
xfs_dir2_node_replace(
xfs_da_args_t *args)
{
xfs_da_state_blk_t *blk;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_data_entry_t *dep;
int error;
int i;
xfs_ino_t inum;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int rval;
xfs_da_state_t *state;
trace_xfs_dir2_node_replace(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
state->blocksize = state->mp->m_dirblksize;
state->node_ents = state->mp->m_dir_node_ents;
inum = args->inumber;
error = xfs_da_node_lookup_int(state, &rval);
if (error) {
rval = error;
}
if (rval == EEXIST) {
blk = &state->path.blk[state->path.active - 1];
ASSERT(blk->magic == XFS_DIR2_LEAFN_MAGIC);
leaf = blk->bp->b_addr;
lep = &leaf->ents[blk->index];
ASSERT(state->extravalid);
hdr = state->extrablk.bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC));
dep = (xfs_dir2_data_entry_t *)
((char *)hdr +
xfs_dir2_dataptr_to_off(state->mp, be32_to_cpu(lep->address)));
ASSERT(inum != be64_to_cpu(dep->inumber));
dep->inumber = cpu_to_be64(inum);
xfs_dir2_data_log_entry(args->trans, state->extrablk.bp, dep);
rval = 0;
}
else if (state->extravalid) {
xfs_trans_brelse(args->trans, state->extrablk.bp);
state->extrablk.bp = NULL;
}
for (i = 0; i < state->path.active; i++) {
xfs_trans_brelse(args->trans, state->path.blk[i].bp);
state->path.blk[i].bp = NULL;
}
xfs_da_state_free(state);
return rval;
}
int
xfs_dir2_node_trim_free(
xfs_da_args_t *args,
xfs_fileoff_t fo,
int *rvalp)
{
struct xfs_buf *bp;
xfs_inode_t *dp;
int error;
xfs_dir2_free_t *free;
xfs_mount_t *mp;
xfs_trans_t *tp;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
error = xfs_dir2_free_try_read(tp, dp, fo, &bp);
if (error)
return error;
if (!bp)
return 0;
free = bp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC));
if (be32_to_cpu(free->hdr.nused) > 0) {
xfs_trans_brelse(tp, bp);
*rvalp = 0;
return 0;
}
if ((error =
xfs_dir2_shrink_inode(args, xfs_dir2_da_to_db(mp, (xfs_dablk_t)fo),
bp))) {
ASSERT(error != ENOSPC);
xfs_trans_brelse(tp, bp);
return error;
}
*rvalp = 1;
return 0;
}
