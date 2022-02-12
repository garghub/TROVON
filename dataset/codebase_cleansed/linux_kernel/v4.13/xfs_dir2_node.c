static bool
xfs_dir3_leafn_check(
struct xfs_inode *dp,
struct xfs_buf *bp)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
struct xfs_dir3_icleaf_hdr leafhdr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
if (leafhdr.magic == XFS_DIR3_LEAFN_MAGIC) {
struct xfs_dir3_leaf_hdr *leaf3 = bp->b_addr;
if (be64_to_cpu(leaf3->info.blkno) != bp->b_bn)
return false;
} else if (leafhdr.magic != XFS_DIR2_LEAFN_MAGIC)
return false;
return xfs_dir3_leaf_check_int(dp->i_mount, dp, &leafhdr, leaf);
}
static bool
xfs_dir3_free_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dir2_free_hdr *hdr = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (hdr3->magic != cpu_to_be32(XFS_DIR3_FREE_MAGIC))
return false;
if (!uuid_equal(&hdr3->uuid, &mp->m_sb.sb_meta_uuid))
return false;
if (be64_to_cpu(hdr3->blkno) != bp->b_bn)
return false;
if (!xfs_log_check_lsn(mp, be64_to_cpu(hdr3->lsn)))
return false;
} else {
if (hdr->magic != cpu_to_be32(XFS_DIR2_FREE_MAGIC))
return false;
}
return true;
}
static void
xfs_dir3_free_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb) &&
!xfs_buf_verify_cksum(bp, XFS_DIR3_FREE_CRC_OFF))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_dir3_free_verify(bp))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
xfs_dir3_free_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (!xfs_dir3_free_verify(bp)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (bip)
hdr3->lsn = cpu_to_be64(bip->bli_item.li_lsn);
xfs_buf_update_cksum(bp, XFS_DIR3_FREE_CRC_OFF);
}
static bool
xfs_dir3_free_header_check(
struct xfs_inode *dp,
xfs_dablk_t fbno,
struct xfs_buf *bp)
{
struct xfs_mount *mp = dp->i_mount;
unsigned int firstdb;
int maxbests;
maxbests = dp->d_ops->free_max_bests(mp->m_dir_geo);
firstdb = (xfs_dir2_da_to_db(mp->m_dir_geo, fbno) -
xfs_dir2_byte_to_db(mp->m_dir_geo, XFS_DIR2_FREE_OFFSET)) *
maxbests;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_free_hdr *hdr3 = bp->b_addr;
if (be32_to_cpu(hdr3->firstdb) != firstdb)
return false;
if (be32_to_cpu(hdr3->nvalid) > maxbests)
return false;
if (be32_to_cpu(hdr3->nvalid) < be32_to_cpu(hdr3->nused))
return false;
} else {
struct xfs_dir2_free_hdr *hdr = bp->b_addr;
if (be32_to_cpu(hdr->firstdb) != firstdb)
return false;
if (be32_to_cpu(hdr->nvalid) > maxbests)
return false;
if (be32_to_cpu(hdr->nvalid) < be32_to_cpu(hdr->nused))
return false;
}
return true;
}
static int
__xfs_dir3_free_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
xfs_daddr_t mappedbno,
struct xfs_buf **bpp)
{
int err;
err = xfs_da_read_buf(tp, dp, fbno, mappedbno, bpp,
XFS_DATA_FORK, &xfs_dir3_free_buf_ops);
if (err || !*bpp)
return err;
if (!xfs_dir3_free_header_check(dp, fbno, *bpp)) {
xfs_buf_ioerror(*bpp, -EFSCORRUPTED);
xfs_verifier_error(*bpp);
xfs_trans_brelse(tp, *bpp);
return -EFSCORRUPTED;
}
if (tp)
xfs_trans_buf_set_type(tp, *bpp, XFS_BLFT_DIR_FREE_BUF);
return 0;
}
int
xfs_dir2_free_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
struct xfs_buf **bpp)
{
return __xfs_dir3_free_read(tp, dp, fbno, -1, bpp);
}
static int
xfs_dir2_free_try_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
struct xfs_buf **bpp)
{
return __xfs_dir3_free_read(tp, dp, fbno, -2, bpp);
}
static int
xfs_dir3_free_get_buf(
xfs_da_args_t *args,
xfs_dir2_db_t fbno,
struct xfs_buf **bpp)
{
struct xfs_trans *tp = args->trans;
struct xfs_inode *dp = args->dp;
struct xfs_mount *mp = dp->i_mount;
struct xfs_buf *bp;
int error;
struct xfs_dir3_icfree_hdr hdr;
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(args->geo, fbno),
-1, &bp, XFS_DATA_FORK);
if (error)
return error;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DIR_FREE_BUF);
bp->b_ops = &xfs_dir3_free_buf_ops;
memset(bp->b_addr, 0, sizeof(struct xfs_dir3_free_hdr));
memset(&hdr, 0, sizeof(hdr));
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_free_hdr *hdr3 = bp->b_addr;
hdr.magic = XFS_DIR3_FREE_MAGIC;
hdr3->hdr.blkno = cpu_to_be64(bp->b_bn);
hdr3->hdr.owner = cpu_to_be64(dp->i_ino);
uuid_copy(&hdr3->hdr.uuid, &mp->m_sb.sb_meta_uuid);
} else
hdr.magic = XFS_DIR2_FREE_MAGIC;
dp->d_ops->free_hdr_to_disk(bp->b_addr, &hdr);
*bpp = bp;
return 0;
}
STATIC void
xfs_dir2_free_log_bests(
struct xfs_da_args *args,
struct xfs_buf *bp,
int first,
int last)
{
xfs_dir2_free_t *free;
__be16 *bests;
free = bp->b_addr;
bests = args->dp->d_ops->free_bests_p(free);
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC) ||
free->hdr.magic == cpu_to_be32(XFS_DIR3_FREE_MAGIC));
xfs_trans_log_buf(args->trans, bp,
(uint)((char *)&bests[first] - (char *)free),
(uint)((char *)&bests[last] - (char *)free +
sizeof(bests[0]) - 1));
}
static void
xfs_dir2_free_log_header(
struct xfs_da_args *args,
struct xfs_buf *bp)
{
#ifdef DEBUG
xfs_dir2_free_t *free;
free = bp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC) ||
free->hdr.magic == cpu_to_be32(XFS_DIR3_FREE_MAGIC));
#endif
xfs_trans_log_buf(args->trans, bp, 0,
args->dp->d_ops->free_hdr_size - 1);
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
int n;
xfs_dir2_data_off_t off;
__be16 *to;
xfs_trans_t *tp;
struct xfs_dir3_icfree_hdr freehdr;
trace_xfs_dir2_leaf_to_node(args);
dp = args->dp;
tp = args->trans;
if ((error = xfs_dir2_grow_inode(args, XFS_DIR2_FREE_SPACE, &fdb))) {
return error;
}
ASSERT(fdb == xfs_dir2_byte_to_db(args->geo, XFS_DIR2_FREE_OFFSET));
error = xfs_dir3_free_get_buf(args, fdb, &fbp);
if (error)
return error;
free = fbp->b_addr;
dp->d_ops->free_hdr_from_disk(&freehdr, free);
leaf = lbp->b_addr;
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
ASSERT(be32_to_cpu(ltp->bestcount) <=
(uint)dp->i_d.di_size / args->geo->blksize);
from = xfs_dir2_leaf_bests_p(ltp);
to = dp->d_ops->free_bests_p(free);
for (i = n = 0; i < be32_to_cpu(ltp->bestcount); i++, from++, to++) {
if ((off = be16_to_cpu(*from)) != NULLDATAOFF)
n++;
*to = cpu_to_be16(off);
}
freehdr.nused = n;
freehdr.nvalid = be32_to_cpu(ltp->bestcount);
dp->d_ops->free_hdr_to_disk(fbp->b_addr, &freehdr);
xfs_dir2_free_log_bests(args, fbp, 0, freehdr.nvalid - 1);
xfs_dir2_free_log_header(args, fbp);
if (leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAF1_MAGIC))
leaf->hdr.info.magic = cpu_to_be16(XFS_DIR2_LEAFN_MAGIC);
else
leaf->hdr.info.magic = cpu_to_be16(XFS_DIR3_LEAFN_MAGIC);
lbp->b_ops = &xfs_dir3_leafn_buf_ops;
xfs_trans_buf_set_type(tp, lbp, XFS_BLFT_DIR_LEAFN_BUF);
xfs_dir3_leaf_log_header(args, lbp);
xfs_dir3_leaf_check(dp, lbp);
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
struct xfs_dir3_icleaf_hdr leafhdr;
struct xfs_dir2_leaf_entry *ents;
trace_xfs_dir2_leafn_add(args, index);
dp = args->dp;
leaf = bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
if (index < 0)
return -EFSCORRUPTED;
if (leafhdr.count == dp->d_ops->leaf_max_ents(args->geo)) {
if (!leafhdr.stale)
return -ENOSPC;
compact = leafhdr.stale > 1;
} else
compact = 0;
ASSERT(index == 0 || be32_to_cpu(ents[index - 1].hashval) <= args->hashval);
ASSERT(index == leafhdr.count ||
be32_to_cpu(ents[index].hashval) >= args->hashval);
if (args->op_flags & XFS_DA_OP_JUSTCHECK)
return 0;
if (compact)
xfs_dir3_leaf_compact_x1(&leafhdr, ents, &index, &lowstale,
&highstale, &lfloglow, &lfloghigh);
else if (leafhdr.stale) {
lfloglow = leafhdr.count;
lfloghigh = -1;
}
lep = xfs_dir3_leaf_find_entry(&leafhdr, ents, index, compact, lowstale,
highstale, &lfloglow, &lfloghigh);
lep->hashval = cpu_to_be32(args->hashval);
lep->address = cpu_to_be32(xfs_dir2_db_off_to_dataptr(args->geo,
args->blkno, args->index));
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, bp);
xfs_dir3_leaf_log_ents(args, bp, lfloglow, lfloghigh);
xfs_dir3_leaf_check(dp, bp);
return 0;
}
static void
xfs_dir2_free_hdr_check(
struct xfs_inode *dp,
struct xfs_buf *bp,
xfs_dir2_db_t db)
{
struct xfs_dir3_icfree_hdr hdr;
dp->d_ops->free_hdr_from_disk(&hdr, bp->b_addr);
ASSERT((hdr.firstdb %
dp->d_ops->free_max_bests(dp->i_mount->m_dir_geo)) == 0);
ASSERT(hdr.firstdb <= db);
ASSERT(db < hdr.firstdb + hdr.nvalid);
}
xfs_dahash_t
xfs_dir2_leaf_lasthash(
struct xfs_inode *dp,
struct xfs_buf *bp,
int *count)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ASSERT(leafhdr.magic == XFS_DIR2_LEAFN_MAGIC ||
leafhdr.magic == XFS_DIR3_LEAFN_MAGIC ||
leafhdr.magic == XFS_DIR2_LEAF1_MAGIC ||
leafhdr.magic == XFS_DIR3_LEAF1_MAGIC);
if (count)
*count = leafhdr.count;
if (!leafhdr.count)
return 0;
ents = dp->d_ops->leaf_ents_p(leaf);
return be32_to_cpu(ents[leafhdr.count - 1].hashval);
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
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
xfs_dir3_leaf_check(dp, bp);
ASSERT(leafhdr.count > 0);
index = xfs_dir2_leaf_search_hash(args, bp);
if (state->extravalid) {
curbp = state->extrablk.bp;
curfdb = state->extrablk.blkno;
free = curbp->b_addr;
ASSERT(free->hdr.magic == cpu_to_be32(XFS_DIR2_FREE_MAGIC) ||
free->hdr.magic == cpu_to_be32(XFS_DIR3_FREE_MAGIC));
}
length = dp->d_ops->data_entsize(args->namelen);
for (lep = &ents[index];
index < leafhdr.count && be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(args->geo,
be32_to_cpu(lep->address));
if (newdb != curdb) {
__be16 *bests;
curdb = newdb;
newfdb = dp->d_ops->db_to_fdb(args->geo, newdb);
if (newfdb != curfdb) {
if (curbp)
xfs_trans_brelse(tp, curbp);
error = xfs_dir2_free_read(tp, dp,
xfs_dir2_db_to_da(args->geo,
newfdb),
&curbp);
if (error)
return error;
free = curbp->b_addr;
xfs_dir2_free_hdr_check(dp, curbp, curdb);
}
fi = dp->d_ops->db_to_fdindex(args->geo, curdb);
bests = dp->d_ops->free_bests_p(free);
if (unlikely(bests[fi] == cpu_to_be16(NULLDATAOFF))) {
XFS_ERROR_REPORT("xfs_dir2_leafn_lookup_int",
XFS_ERRLEVEL_LOW, mp);
if (curfdb != newfdb)
xfs_trans_brelse(tp, curbp);
return -EFSCORRUPTED;
}
curfdb = newfdb;
if (be16_to_cpu(bests[fi]) >= length)
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
return -ENOENT;
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
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
xfs_dir3_leaf_check(dp, bp);
ASSERT(leafhdr.count > 0);
index = xfs_dir2_leaf_search_hash(args, bp);
if (state->extravalid) {
curbp = state->extrablk.bp;
curdb = state->extrablk.blkno;
}
for (lep = &ents[index];
index < leafhdr.count && be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(args->geo,
be32_to_cpu(lep->address));
if (newdb != curdb) {
if (curbp && (args->cmpresult == XFS_CMP_DIFFERENT ||
curdb != state->extrablk.blkno))
xfs_trans_brelse(tp, curbp);
if (args->cmpresult != XFS_CMP_DIFFERENT &&
newdb == state->extrablk.blkno) {
ASSERT(state->extravalid);
curbp = state->extrablk.bp;
} else {
error = xfs_dir3_data_read(tp, dp,
xfs_dir2_db_to_da(args->geo,
newdb),
-1, &curbp);
if (error)
return error;
}
xfs_dir3_data_check(dp, curbp);
curdb = newdb;
}
dep = (xfs_dir2_data_entry_t *)((char *)curbp->b_addr +
xfs_dir2_dataptr_to_off(args->geo,
be32_to_cpu(lep->address)));
cmp = mp->m_dirnameops->compname(args, dep->name, dep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
if (args->cmpresult != XFS_CMP_DIFFERENT &&
curdb != state->extrablk.blkno)
xfs_trans_brelse(tp, state->extrablk.bp);
args->cmpresult = cmp;
args->inumber = be64_to_cpu(dep->inumber);
args->filetype = dp->d_ops->data_get_ftype(dep);
*indexp = index;
state->extravalid = 1;
state->extrablk.bp = curbp;
state->extrablk.blkno = curdb;
state->extrablk.index = (int)((char *)dep -
(char *)curbp->b_addr);
state->extrablk.magic = XFS_DIR2_DATA_MAGIC;
curbp->b_ops = &xfs_dir3_data_buf_ops;
xfs_trans_buf_set_type(tp, curbp, XFS_BLFT_DIR_DATA_BUF);
if (cmp == XFS_CMP_EXACT)
return -EEXIST;
}
}
ASSERT(index == leafhdr.count || (args->op_flags & XFS_DA_OP_OKNOENT));
if (curbp) {
if (args->cmpresult == XFS_CMP_DIFFERENT) {
state->extravalid = 1;
state->extrablk.bp = curbp;
state->extrablk.index = -1;
state->extrablk.blkno = curdb;
state->extrablk.magic = XFS_DIR2_DATA_MAGIC;
curbp->b_ops = &xfs_dir3_data_buf_ops;
xfs_trans_buf_set_type(tp, curbp, XFS_BLFT_DIR_DATA_BUF);
} else {
if (state->extrablk.bp != curbp)
xfs_trans_brelse(tp, curbp);
}
} else {
state->extravalid = 0;
}
*indexp = index;
return -ENOENT;
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
xfs_dir3_leafn_moveents(
xfs_da_args_t *args,
struct xfs_buf *bp_s,
struct xfs_dir3_icleaf_hdr *shdr,
struct xfs_dir2_leaf_entry *sents,
int start_s,
struct xfs_buf *bp_d,
struct xfs_dir3_icleaf_hdr *dhdr,
struct xfs_dir2_leaf_entry *dents,
int start_d,
int count)
{
int stale;
trace_xfs_dir2_leafn_moveents(args, start_s, start_d, count);
if (count == 0)
return;
if (start_d < dhdr->count) {
memmove(&dents[start_d + count], &dents[start_d],
(dhdr->count - start_d) * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir3_leaf_log_ents(args, bp_d, start_d + count,
count + dhdr->count - 1);
}
if (shdr->stale) {
int i;
for (i = start_s, stale = 0; i < start_s + count; i++) {
if (sents[i].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
stale++;
}
} else
stale = 0;
memcpy(&dents[start_d], &sents[start_s],
count * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir3_leaf_log_ents(args, bp_d, start_d, start_d + count - 1);
if (start_s + count < shdr->count) {
memmove(&sents[start_s], &sents[start_s + count],
count * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir3_leaf_log_ents(args, bp_s, start_s, start_s + count - 1);
}
shdr->count -= count;
shdr->stale -= stale;
dhdr->count += count;
dhdr->stale += stale;
}
int
xfs_dir2_leafn_order(
struct xfs_inode *dp,
struct xfs_buf *leaf1_bp,
struct xfs_buf *leaf2_bp)
{
struct xfs_dir2_leaf *leaf1 = leaf1_bp->b_addr;
struct xfs_dir2_leaf *leaf2 = leaf2_bp->b_addr;
struct xfs_dir2_leaf_entry *ents1;
struct xfs_dir2_leaf_entry *ents2;
struct xfs_dir3_icleaf_hdr hdr1;
struct xfs_dir3_icleaf_hdr hdr2;
dp->d_ops->leaf_hdr_from_disk(&hdr1, leaf1);
dp->d_ops->leaf_hdr_from_disk(&hdr2, leaf2);
ents1 = dp->d_ops->leaf_ents_p(leaf1);
ents2 = dp->d_ops->leaf_ents_p(leaf2);
if (hdr1.count > 0 && hdr2.count > 0 &&
(be32_to_cpu(ents2[0].hashval) < be32_to_cpu(ents1[0].hashval) ||
be32_to_cpu(ents2[hdr2.count - 1].hashval) <
be32_to_cpu(ents1[hdr1.count - 1].hashval)))
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
#if defined(DEBUG) || defined(XFS_WARN)
int oldstale;
#endif
int oldsum;
int swap;
struct xfs_dir2_leaf_entry *ents1;
struct xfs_dir2_leaf_entry *ents2;
struct xfs_dir3_icleaf_hdr hdr1;
struct xfs_dir3_icleaf_hdr hdr2;
struct xfs_inode *dp = state->args->dp;
args = state->args;
if ((swap = xfs_dir2_leafn_order(dp, blk1->bp, blk2->bp))) {
xfs_da_state_blk_t *tmp;
tmp = blk1;
blk1 = blk2;
blk2 = tmp;
}
leaf1 = blk1->bp->b_addr;
leaf2 = blk2->bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&hdr1, leaf1);
dp->d_ops->leaf_hdr_from_disk(&hdr2, leaf2);
ents1 = dp->d_ops->leaf_ents_p(leaf1);
ents2 = dp->d_ops->leaf_ents_p(leaf2);
oldsum = hdr1.count + hdr2.count;
#if defined(DEBUG) || defined(XFS_WARN)
oldstale = hdr1.stale + hdr2.stale;
#endif
mid = oldsum >> 1;
if (oldsum & 1) {
xfs_dahash_t midhash;
if (mid >= hdr1.count)
midhash = be32_to_cpu(ents2[mid - hdr1.count].hashval);
else
midhash = be32_to_cpu(ents1[mid].hashval);
isleft = args->hashval <= midhash;
}
else
isleft = 1;
count = hdr1.count - mid + (isleft == 0);
if (count > 0)
xfs_dir3_leafn_moveents(args, blk1->bp, &hdr1, ents1,
hdr1.count - count, blk2->bp,
&hdr2, ents2, 0, count);
else if (count < 0)
xfs_dir3_leafn_moveents(args, blk2->bp, &hdr2, ents2, 0,
blk1->bp, &hdr1, ents1,
hdr1.count, count);
ASSERT(hdr1.count + hdr2.count == oldsum);
ASSERT(hdr1.stale + hdr2.stale == oldstale);
dp->d_ops->leaf_hdr_to_disk(leaf1, &hdr1);
dp->d_ops->leaf_hdr_to_disk(leaf2, &hdr2);
xfs_dir3_leaf_log_header(args, blk1->bp);
xfs_dir3_leaf_log_header(args, blk2->bp);
xfs_dir3_leaf_check(dp, blk1->bp);
xfs_dir3_leaf_check(dp, blk2->bp);
if (hdr1.count < hdr2.count)
state->inleaf = swap;
else if (hdr1.count > hdr2.count)
state->inleaf = !swap;
else
state->inleaf = swap ^ (blk1->index <= hdr1.count);
if (!state->inleaf)
blk2->index = blk1->index - hdr1.count;
if (blk2->index < 0) {
state->inleaf = 1;
blk2->index = 0;
xfs_alert(dp->i_mount,
"%s: picked the wrong leaf? reverting original leaf: blk1->index %d",
__func__, blk1->index);
}
}
static int
xfs_dir3_data_block_free(
xfs_da_args_t *args,
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_free *free,
xfs_dir2_db_t fdb,
int findex,
struct xfs_buf *fbp,
int longest)
{
int logfree = 0;
__be16 *bests;
struct xfs_dir3_icfree_hdr freehdr;
struct xfs_inode *dp = args->dp;
dp->d_ops->free_hdr_from_disk(&freehdr, free);
bests = dp->d_ops->free_bests_p(free);
if (hdr) {
bests[findex] = cpu_to_be16(longest);
xfs_dir2_free_log_bests(args, fbp, findex, findex);
return 0;
}
freehdr.nused--;
if (findex == freehdr.nvalid - 1) {
int i;
for (i = findex - 1; i >= 0; i--) {
if (bests[i] != cpu_to_be16(NULLDATAOFF))
break;
}
freehdr.nvalid = i + 1;
logfree = 0;
} else {
bests[findex] = cpu_to_be16(NULLDATAOFF);
logfree = 1;
}
dp->d_ops->free_hdr_to_disk(free, &freehdr);
xfs_dir2_free_log_header(args, fbp);
if (!freehdr.nused) {
int error;
error = xfs_dir2_shrink_inode(args, fdb, fbp);
if (error == 0) {
fbp = NULL;
logfree = 0;
} else if (error != -ENOSPC || args->total != 0)
return error;
}
if (logfree)
xfs_dir2_free_log_bests(args, fbp, findex, findex);
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
int needlog;
int needscan;
xfs_trans_t *tp;
struct xfs_dir2_data_free *bf;
struct xfs_dir3_icleaf_hdr leafhdr;
struct xfs_dir2_leaf_entry *ents;
trace_xfs_dir2_leafn_remove(args, index);
dp = args->dp;
tp = args->trans;
leaf = bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
lep = &ents[index];
db = xfs_dir2_dataptr_to_db(args->geo, be32_to_cpu(lep->address));
ASSERT(dblk->blkno == db);
off = xfs_dir2_dataptr_to_off(args->geo, be32_to_cpu(lep->address));
ASSERT(dblk->index == off);
leafhdr.stale++;
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, bp);
lep->address = cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
xfs_dir3_leaf_log_ents(args, bp, index, index);
dbp = dblk->bp;
hdr = dbp->b_addr;
dep = (xfs_dir2_data_entry_t *)((char *)hdr + off);
bf = dp->d_ops->data_bestfree_p(hdr);
longest = be16_to_cpu(bf[0].length);
needlog = needscan = 0;
xfs_dir2_data_make_free(args, dbp, off,
dp->d_ops->data_entsize(dep->namelen), &needlog, &needscan);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(args, dbp);
xfs_dir3_data_check(dp, dbp);
if (longest < be16_to_cpu(bf[0].length)) {
int error;
struct xfs_buf *fbp;
xfs_dir2_db_t fdb;
int findex;
xfs_dir2_free_t *free;
fdb = dp->d_ops->db_to_fdb(args->geo, db);
error = xfs_dir2_free_read(tp, dp,
xfs_dir2_db_to_da(args->geo, fdb),
&fbp);
if (error)
return error;
free = fbp->b_addr;
#ifdef DEBUG
{
struct xfs_dir3_icfree_hdr freehdr;
dp->d_ops->free_hdr_from_disk(&freehdr, free);
ASSERT(freehdr.firstdb == dp->d_ops->free_max_bests(args->geo) *
(fdb - xfs_dir2_byte_to_db(args->geo,
XFS_DIR2_FREE_OFFSET)));
}
#endif
findex = dp->d_ops->db_to_fdindex(args->geo, db);
longest = be16_to_cpu(bf[0].length);
if (longest == args->geo->blksize -
dp->d_ops->data_entry_offset) {
error = xfs_dir2_shrink_inode(args, db, dbp);
if (error == 0) {
dblk->bp = NULL;
hdr = NULL;
}
else if (!(error == -ENOSPC && args->total == 0))
return error;
}
error = xfs_dir3_data_block_free(args, hdr, free,
fdb, findex, fbp, longest);
if (error)
return error;
}
xfs_dir3_leaf_check(dp, bp);
*rval = (dp->d_ops->leaf_hdr_size +
(uint)sizeof(ents[0]) * (leafhdr.count - leafhdr.stale)) <
args->geo->magicpct;
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
struct xfs_inode *dp;
args = state->args;
dp = args->dp;
ASSERT(oldblk->magic == XFS_DIR2_LEAFN_MAGIC);
error = xfs_da_grow_inode(args, &blkno);
if (error) {
return error;
}
error = xfs_dir3_leaf_get_buf(args, xfs_dir2_da_to_db(args->geo, blkno),
&newblk->bp, XFS_DIR2_LEAFN_MAGIC);
if (error)
return error;
newblk->blkno = blkno;
newblk->magic = XFS_DIR2_LEAFN_MAGIC;
xfs_dir2_leafn_rebalance(state, oldblk, newblk);
error = xfs_da3_blk_link(state, oldblk, newblk);
if (error) {
return error;
}
if (state->inleaf)
error = xfs_dir2_leafn_add(oldblk->bp, args, oldblk->index);
else
error = xfs_dir2_leafn_add(newblk->bp, args, newblk->index);
oldblk->hashval = xfs_dir2_leaf_lasthash(dp, oldblk->bp, NULL);
newblk->hashval = xfs_dir2_leaf_lasthash(dp, newblk->bp, NULL);
xfs_dir3_leaf_check(dp, oldblk->bp);
xfs_dir3_leaf_check(dp, newblk->bp);
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
xfs_dir2_leaf_t *leaf;
int rval;
struct xfs_dir3_icleaf_hdr leafhdr;
struct xfs_dir2_leaf_entry *ents;
struct xfs_inode *dp = state->args->dp;
blk = &state->path.blk[state->path.active - 1];
leaf = blk->bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
xfs_dir3_leaf_check(dp, blk->bp);
count = leafhdr.count - leafhdr.stale;
bytes = dp->d_ops->leaf_hdr_size + count * sizeof(ents[0]);
if (bytes > (state->args->geo->blksize >> 1)) {
*action = 0;
return 0;
}
if (count == 0) {
forward = (leafhdr.forw != 0);
memcpy(&state->altpath, &state->path, sizeof(state->path));
error = xfs_da3_path_shift(state, &state->altpath, forward, 0,
&rval);
if (error)
return error;
*action = rval ? 2 : 0;
return 0;
}
forward = leafhdr.forw < leafhdr.back;
for (i = 0, bp = NULL; i < 2; forward = !forward, i++) {
struct xfs_dir3_icleaf_hdr hdr2;
blkno = forward ? leafhdr.forw : leafhdr.back;
if (blkno == 0)
continue;
error = xfs_dir3_leafn_read(state->args->trans, dp,
blkno, -1, &bp);
if (error)
return error;
count = leafhdr.count - leafhdr.stale;
bytes = state->args->geo->blksize -
(state->args->geo->blksize >> 2);
leaf = bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&hdr2, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
count += hdr2.count - hdr2.stale;
bytes -= count * sizeof(ents[0]);
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
error = xfs_da3_path_shift(state, &state->altpath, forward, 0,
&rval);
else
error = xfs_da3_path_shift(state, &state->path, forward, 0,
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
struct xfs_dir3_icleaf_hdr savehdr;
struct xfs_dir3_icleaf_hdr drophdr;
struct xfs_dir2_leaf_entry *sents;
struct xfs_dir2_leaf_entry *dents;
struct xfs_inode *dp = state->args->dp;
args = state->args;
ASSERT(drop_blk->magic == XFS_DIR2_LEAFN_MAGIC);
ASSERT(save_blk->magic == XFS_DIR2_LEAFN_MAGIC);
drop_leaf = drop_blk->bp->b_addr;
save_leaf = save_blk->bp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&savehdr, save_leaf);
dp->d_ops->leaf_hdr_from_disk(&drophdr, drop_leaf);
sents = dp->d_ops->leaf_ents_p(save_leaf);
dents = dp->d_ops->leaf_ents_p(drop_leaf);
if (drophdr.stale)
xfs_dir3_leaf_compact(args, &drophdr, drop_blk->bp);
if (savehdr.stale)
xfs_dir3_leaf_compact(args, &savehdr, save_blk->bp);
drop_blk->hashval = be32_to_cpu(dents[drophdr.count - 1].hashval);
if (xfs_dir2_leafn_order(dp, save_blk->bp, drop_blk->bp))
xfs_dir3_leafn_moveents(args, drop_blk->bp, &drophdr, dents, 0,
save_blk->bp, &savehdr, sents, 0,
drophdr.count);
else
xfs_dir3_leafn_moveents(args, drop_blk->bp, &drophdr, dents, 0,
save_blk->bp, &savehdr, sents,
savehdr.count, drophdr.count);
save_blk->hashval = be32_to_cpu(sents[savehdr.count - 1].hashval);
dp->d_ops->leaf_hdr_to_disk(save_leaf, &savehdr);
dp->d_ops->leaf_hdr_to_disk(drop_leaf, &drophdr);
xfs_dir3_leaf_log_header(args, save_blk->bp);
xfs_dir3_leaf_log_header(args, drop_blk->bp);
xfs_dir3_leaf_check(dp, save_blk->bp);
xfs_dir3_leaf_check(dp, drop_blk->bp);
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
error = xfs_da3_node_lookup_int(state, &rval);
if (error)
rval = error;
if (rval != -ENOENT) {
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
xfs_da3_fixhashpath(state, &state->path);
} else {
if (args->total == 0) {
ASSERT(rval == -ENOSPC);
goto done;
}
rval = xfs_da3_split(state);
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
__be16 *bests;
struct xfs_dir3_icfree_hdr freehdr;
struct xfs_dir2_data_free *bf;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
length = dp->d_ops->data_entsize(args->namelen);
if (fblk) {
fbp = fblk->bp;
ifbno = fblk->blkno;
free = fbp->b_addr;
findex = fblk->index;
bests = dp->d_ops->free_bests_p(free);
dp->d_ops->free_hdr_from_disk(&freehdr, free);
if (findex >= 0) {
ASSERT(findex < freehdr.nvalid);
ASSERT(be16_to_cpu(bests[findex]) != NULLDATAOFF);
ASSERT(be16_to_cpu(bests[findex]) >= length);
dbno = freehdr.firstdb + findex;
} else {
dbno = -1;
findex = 0;
}
} else {
ifbno = dbno = -1;
fbp = NULL;
findex = 0;
}
if (dbno == -1) {
xfs_fileoff_t fo;
if ((error = xfs_bmap_last_offset(dp, &fo, XFS_DATA_FORK)))
return error;
lastfbno = xfs_dir2_da_to_db(args->geo, (xfs_dablk_t)fo);
fbno = ifbno;
}
while (dbno == -1) {
if (fbp == NULL) {
if (++fbno == 0)
fbno = xfs_dir2_byte_to_db(args->geo,
XFS_DIR2_FREE_OFFSET);
if (fbno == ifbno)
fbno++;
if (fbno >= lastfbno)
break;
error = xfs_dir2_free_try_read(tp, dp,
xfs_dir2_db_to_da(args->geo, fbno),
&fbp);
if (error)
return error;
if (!fbp)
continue;
free = fbp->b_addr;
findex = 0;
}
bests = dp->d_ops->free_bests_p(free);
dp->d_ops->free_hdr_from_disk(&freehdr, free);
if (be16_to_cpu(bests[findex]) != NULLDATAOFF &&
be16_to_cpu(bests[findex]) >= length)
dbno = freehdr.firstdb + findex;
else {
if (++findex == freehdr.nvalid) {
xfs_trans_brelse(tp, fbp);
fbp = NULL;
if (fblk && fblk->bp)
fblk->bp = NULL;
}
}
}
if (unlikely(dbno == -1)) {
if ((args->op_flags & XFS_DA_OP_JUSTCHECK) || args->total == 0)
return -ENOSPC;
if (unlikely((error = xfs_dir2_grow_inode(args,
XFS_DIR2_DATA_SPACE,
&dbno)) ||
(error = xfs_dir3_data_init(args, dbno, &dbp))))
return error;
if (fbp)
xfs_trans_brelse(tp, fbp);
if (fblk && fblk->bp)
fblk->bp = NULL;
fbno = dp->d_ops->db_to_fdb(args->geo, dbno);
error = xfs_dir2_free_try_read(tp, dp,
xfs_dir2_db_to_da(args->geo, fbno),
&fbp);
if (error)
return error;
if (!fbp) {
error = xfs_dir2_grow_inode(args, XFS_DIR2_FREE_SPACE,
&fbno);
if (error)
return error;
if (dp->d_ops->db_to_fdb(args->geo, dbno) != fbno) {
xfs_alert(mp,
"%s: dir ino %llu needed freesp block %lld for data block %lld, got %lld ifbno %llu lastfbno %d",
__func__, (unsigned long long)dp->i_ino,
(long long)dp->d_ops->db_to_fdb(
args->geo, dbno),
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
return -EFSCORRUPTED;
}
error = xfs_dir3_free_get_buf(args, fbno, &fbp);
if (error)
return error;
free = fbp->b_addr;
bests = dp->d_ops->free_bests_p(free);
dp->d_ops->free_hdr_from_disk(&freehdr, free);
freehdr.firstdb =
(fbno - xfs_dir2_byte_to_db(args->geo,
XFS_DIR2_FREE_OFFSET)) *
dp->d_ops->free_max_bests(args->geo);
} else {
free = fbp->b_addr;
bests = dp->d_ops->free_bests_p(free);
dp->d_ops->free_hdr_from_disk(&freehdr, free);
}
findex = dp->d_ops->db_to_fdindex(args->geo, dbno);
if (findex >= freehdr.nvalid) {
ASSERT(findex < dp->d_ops->free_max_bests(args->geo));
freehdr.nvalid = findex + 1;
bests[findex] = cpu_to_be16(NULLDATAOFF);
}
if (bests[findex] == cpu_to_be16(NULLDATAOFF)) {
freehdr.nused++;
dp->d_ops->free_hdr_to_disk(fbp->b_addr, &freehdr);
xfs_dir2_free_log_header(args, fbp);
}
hdr = dbp->b_addr;
bf = dp->d_ops->data_bestfree_p(hdr);
bests[findex] = bf[0].length;
logfree = 1;
}
else {
if (args->op_flags & XFS_DA_OP_JUSTCHECK)
return 0;
error = xfs_dir3_data_read(tp, dp,
xfs_dir2_db_to_da(args->geo, dbno),
-1, &dbp);
if (error)
return error;
hdr = dbp->b_addr;
bf = dp->d_ops->data_bestfree_p(hdr);
logfree = 0;
}
ASSERT(be16_to_cpu(bf[0].length) >= length);
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(bf[0].offset));
needscan = needlog = 0;
xfs_dir2_data_use_free(args, dbp, dup,
(xfs_dir2_data_aoff_t)((char *)dup - (char *)hdr), length,
&needlog, &needscan);
dep = (xfs_dir2_data_entry_t *)dup;
dep->inumber = cpu_to_be64(args->inumber);
dep->namelen = args->namelen;
memcpy(dep->name, args->name, dep->namelen);
dp->d_ops->data_put_ftype(dep, args->filetype);
tagp = dp->d_ops->data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
xfs_dir2_data_log_entry(args, dbp, dep);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(args, dbp);
bests = dp->d_ops->free_bests_p(free);
if (be16_to_cpu(bests[findex]) != be16_to_cpu(bf[0].length)) {
bests[findex] = bf[0].length;
logfree = 1;
}
if (logfree)
xfs_dir2_free_log_bests(args, fbp, findex, findex);
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
error = xfs_da3_node_lookup_int(state, &rval);
if (error)
rval = error;
else if (rval == -ENOENT && args->cmpresult == XFS_CMP_CASE) {
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
struct xfs_da_args *args)
{
struct xfs_da_state_blk *blk;
int error;
int rval;
struct xfs_da_state *state;
trace_xfs_dir2_node_removename(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
error = xfs_da3_node_lookup_int(state, &rval);
if (error)
goto out_free;
if (rval != -EEXIST) {
error = rval;
goto out_free;
}
blk = &state->path.blk[state->path.active - 1];
ASSERT(blk->magic == XFS_DIR2_LEAFN_MAGIC);
ASSERT(state->extravalid);
error = xfs_dir2_leafn_remove(args, blk->bp, blk->index,
&state->extrablk, &rval);
if (error)
goto out_free;
xfs_da3_fixhashpath(state, &state->path);
if (rval && state->path.active > 1)
error = xfs_da3_join(state);
if (!error)
error = xfs_dir2_node_to_leaf(state);
out_free:
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
int ftype;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int rval;
xfs_da_state_t *state;
trace_xfs_dir2_node_replace(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
inum = args->inumber;
ftype = args->filetype;
error = xfs_da3_node_lookup_int(state, &rval);
if (error) {
rval = error;
}
if (rval == -EEXIST) {
struct xfs_dir2_leaf_entry *ents;
blk = &state->path.blk[state->path.active - 1];
ASSERT(blk->magic == XFS_DIR2_LEAFN_MAGIC);
leaf = blk->bp->b_addr;
ents = args->dp->d_ops->leaf_ents_p(leaf);
lep = &ents[blk->index];
ASSERT(state->extravalid);
hdr = state->extrablk.bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC));
dep = (xfs_dir2_data_entry_t *)
((char *)hdr +
xfs_dir2_dataptr_to_off(args->geo,
be32_to_cpu(lep->address)));
ASSERT(inum != be64_to_cpu(dep->inumber));
dep->inumber = cpu_to_be64(inum);
args->dp->d_ops->data_put_ftype(dep, ftype);
xfs_dir2_data_log_entry(args, state->extrablk.bp, dep);
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
xfs_trans_t *tp;
struct xfs_dir3_icfree_hdr freehdr;
dp = args->dp;
tp = args->trans;
*rvalp = 0;
error = xfs_dir2_free_try_read(tp, dp, fo, &bp);
if (error)
return error;
if (!bp)
return 0;
free = bp->b_addr;
dp->d_ops->free_hdr_from_disk(&freehdr, free);
if (freehdr.nused > 0) {
xfs_trans_brelse(tp, bp);
return 0;
}
error = xfs_dir2_shrink_inode(args,
xfs_dir2_da_to_db(args->geo, (xfs_dablk_t)fo), bp);
if (error) {
ASSERT(error != -ENOSPC);
xfs_trans_brelse(tp, bp);
return error;
}
*rvalp = 1;
return 0;
}
