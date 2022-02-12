STATIC bool
xfs_dir3_leaf1_check(
struct xfs_inode *dp,
struct xfs_buf *bp)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
struct xfs_dir3_icleaf_hdr leafhdr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
if (leafhdr.magic == XFS_DIR3_LEAF1_MAGIC) {
struct xfs_dir3_leaf_hdr *leaf3 = bp->b_addr;
if (be64_to_cpu(leaf3->info.blkno) != bp->b_bn)
return false;
} else if (leafhdr.magic != XFS_DIR2_LEAF1_MAGIC)
return false;
return xfs_dir3_leaf_check_int(dp->i_mount, dp, &leafhdr, leaf);
}
bool
xfs_dir3_leaf_check_int(
struct xfs_mount *mp,
struct xfs_inode *dp,
struct xfs_dir3_icleaf_hdr *hdr,
struct xfs_dir2_leaf *leaf)
{
struct xfs_dir2_leaf_entry *ents;
xfs_dir2_leaf_tail_t *ltp;
int stale;
int i;
const struct xfs_dir_ops *ops;
struct xfs_dir3_icleaf_hdr leafhdr;
struct xfs_da_geometry *geo = mp->m_dir_geo;
ops = xfs_dir_get_ops(mp, dp);
if (!hdr) {
ops->leaf_hdr_from_disk(&leafhdr, leaf);
hdr = &leafhdr;
}
ents = ops->leaf_ents_p(leaf);
ltp = xfs_dir2_leaf_tail_p(geo, leaf);
if (hdr->count > ops->leaf_max_ents(geo))
return false;
if ((hdr->magic == XFS_DIR2_LEAF1_MAGIC ||
hdr->magic == XFS_DIR3_LEAF1_MAGIC) &&
(char *)&ents[hdr->count] > (char *)xfs_dir2_leaf_bests_p(ltp))
return false;
for (i = stale = 0; i < hdr->count; i++) {
if (i + 1 < hdr->count) {
if (be32_to_cpu(ents[i].hashval) >
be32_to_cpu(ents[i + 1].hashval))
return false;
}
if (ents[i].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
stale++;
}
if (hdr->stale != stale)
return false;
return true;
}
static bool
xfs_dir3_leaf_verify(
struct xfs_buf *bp,
__uint16_t magic)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dir2_leaf *leaf = bp->b_addr;
ASSERT(magic == XFS_DIR2_LEAF1_MAGIC || magic == XFS_DIR2_LEAFN_MAGIC);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_leaf_hdr *leaf3 = bp->b_addr;
__uint16_t magic3;
magic3 = (magic == XFS_DIR2_LEAF1_MAGIC) ? XFS_DIR3_LEAF1_MAGIC
: XFS_DIR3_LEAFN_MAGIC;
if (leaf3->info.hdr.magic != cpu_to_be16(magic3))
return false;
if (!uuid_equal(&leaf3->info.uuid, &mp->m_sb.sb_uuid))
return false;
if (be64_to_cpu(leaf3->info.blkno) != bp->b_bn)
return false;
} else {
if (leaf->hdr.info.magic != cpu_to_be16(magic))
return false;
}
return xfs_dir3_leaf_check_int(mp, NULL, NULL, leaf);
}
static void
__read_verify(
struct xfs_buf *bp,
__uint16_t magic)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb) &&
!xfs_buf_verify_cksum(bp, XFS_DIR3_LEAF_CRC_OFF))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_dir3_leaf_verify(bp, magic))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
__write_verify(
struct xfs_buf *bp,
__uint16_t magic)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
struct xfs_dir3_leaf_hdr *hdr3 = bp->b_addr;
if (!xfs_dir3_leaf_verify(bp, magic)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (bip)
hdr3->info.lsn = cpu_to_be64(bip->bli_item.li_lsn);
xfs_buf_update_cksum(bp, XFS_DIR3_LEAF_CRC_OFF);
}
static void
xfs_dir3_leaf1_read_verify(
struct xfs_buf *bp)
{
__read_verify(bp, XFS_DIR2_LEAF1_MAGIC);
}
static void
xfs_dir3_leaf1_write_verify(
struct xfs_buf *bp)
{
__write_verify(bp, XFS_DIR2_LEAF1_MAGIC);
}
static void
xfs_dir3_leafn_read_verify(
struct xfs_buf *bp)
{
__read_verify(bp, XFS_DIR2_LEAFN_MAGIC);
}
static void
xfs_dir3_leafn_write_verify(
struct xfs_buf *bp)
{
__write_verify(bp, XFS_DIR2_LEAFN_MAGIC);
}
static int
xfs_dir3_leaf_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
xfs_daddr_t mappedbno,
struct xfs_buf **bpp)
{
int err;
err = xfs_da_read_buf(tp, dp, fbno, mappedbno, bpp,
XFS_DATA_FORK, &xfs_dir3_leaf1_buf_ops);
if (!err && tp)
xfs_trans_buf_set_type(tp, *bpp, XFS_BLFT_DIR_LEAF1_BUF);
return err;
}
int
xfs_dir3_leafn_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t fbno,
xfs_daddr_t mappedbno,
struct xfs_buf **bpp)
{
int err;
err = xfs_da_read_buf(tp, dp, fbno, mappedbno, bpp,
XFS_DATA_FORK, &xfs_dir3_leafn_buf_ops);
if (!err && tp)
xfs_trans_buf_set_type(tp, *bpp, XFS_BLFT_DIR_LEAFN_BUF);
return err;
}
static void
xfs_dir3_leaf_init(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *bp,
xfs_ino_t owner,
__uint16_t type)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
ASSERT(type == XFS_DIR2_LEAF1_MAGIC || type == XFS_DIR2_LEAFN_MAGIC);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_leaf_hdr *leaf3 = bp->b_addr;
memset(leaf3, 0, sizeof(*leaf3));
leaf3->info.hdr.magic = (type == XFS_DIR2_LEAF1_MAGIC)
? cpu_to_be16(XFS_DIR3_LEAF1_MAGIC)
: cpu_to_be16(XFS_DIR3_LEAFN_MAGIC);
leaf3->info.blkno = cpu_to_be64(bp->b_bn);
leaf3->info.owner = cpu_to_be64(owner);
uuid_copy(&leaf3->info.uuid, &mp->m_sb.sb_uuid);
} else {
memset(leaf, 0, sizeof(*leaf));
leaf->hdr.info.magic = cpu_to_be16(type);
}
if (type == XFS_DIR2_LEAF1_MAGIC) {
struct xfs_dir2_leaf_tail *ltp;
ltp = xfs_dir2_leaf_tail_p(mp->m_dir_geo, leaf);
ltp->bestcount = 0;
bp->b_ops = &xfs_dir3_leaf1_buf_ops;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DIR_LEAF1_BUF);
} else {
bp->b_ops = &xfs_dir3_leafn_buf_ops;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DIR_LEAFN_BUF);
}
}
int
xfs_dir3_leaf_get_buf(
xfs_da_args_t *args,
xfs_dir2_db_t bno,
struct xfs_buf **bpp,
__uint16_t magic)
{
struct xfs_inode *dp = args->dp;
struct xfs_trans *tp = args->trans;
struct xfs_mount *mp = dp->i_mount;
struct xfs_buf *bp;
int error;
ASSERT(magic == XFS_DIR2_LEAF1_MAGIC || magic == XFS_DIR2_LEAFN_MAGIC);
ASSERT(bno >= xfs_dir2_byte_to_db(args->geo, XFS_DIR2_LEAF_OFFSET) &&
bno < xfs_dir2_byte_to_db(args->geo, XFS_DIR2_FREE_OFFSET));
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(args->geo, bno),
-1, &bp, XFS_DATA_FORK);
if (error)
return error;
xfs_dir3_leaf_init(mp, tp, bp, dp->i_ino, magic);
xfs_dir3_leaf_log_header(args, bp);
if (magic == XFS_DIR2_LEAF1_MAGIC)
xfs_dir3_leaf_log_tail(args, bp);
*bpp = bp;
return 0;
}
int
xfs_dir2_block_to_leaf(
xfs_da_args_t *args,
struct xfs_buf *dbp)
{
__be16 *bestsp;
xfs_dablk_t blkno;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
xfs_dir2_block_tail_t *btp;
xfs_inode_t *dp;
int error;
struct xfs_buf *lbp;
xfs_dir2_db_t ldb;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
int needlog;
int needscan;
xfs_trans_t *tp;
struct xfs_dir2_data_free *bf;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
trace_xfs_dir2_block_to_leaf(args);
dp = args->dp;
tp = args->trans;
if ((error = xfs_da_grow_inode(args, &blkno))) {
return error;
}
ldb = xfs_dir2_da_to_db(args->geo, blkno);
ASSERT(ldb == xfs_dir2_byte_to_db(args->geo, XFS_DIR2_LEAF_OFFSET));
error = xfs_dir3_leaf_get_buf(args, ldb, &lbp, XFS_DIR2_LEAF1_MAGIC);
if (error)
return error;
leaf = lbp->b_addr;
hdr = dbp->b_addr;
xfs_dir3_data_check(dp, dbp);
btp = xfs_dir2_block_tail_p(args->geo, hdr);
blp = xfs_dir2_block_leaf_p(btp);
bf = dp->d_ops->data_bestfree_p(hdr);
ents = dp->d_ops->leaf_ents_p(leaf);
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
leafhdr.count = be32_to_cpu(btp->count);
leafhdr.stale = be32_to_cpu(btp->stale);
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, lbp);
memcpy(ents, blp, be32_to_cpu(btp->count) * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir3_leaf_log_ents(args, lbp, 0, leafhdr.count - 1);
needscan = 0;
needlog = 1;
xfs_dir2_data_make_free(args, dbp,
(xfs_dir2_data_aoff_t)((char *)blp - (char *)hdr),
(xfs_dir2_data_aoff_t)((char *)hdr + args->geo->blksize -
(char *)blp),
&needlog, &needscan);
dbp->b_ops = &xfs_dir3_data_buf_ops;
xfs_trans_buf_set_type(tp, dbp, XFS_BLFT_DIR_DATA_BUF);
if (hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC))
hdr->magic = cpu_to_be32(XFS_DIR2_DATA_MAGIC);
else
hdr->magic = cpu_to_be32(XFS_DIR3_DATA_MAGIC);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
ltp->bestcount = cpu_to_be32(1);
bestsp = xfs_dir2_leaf_bests_p(ltp);
bestsp[0] = bf[0].length;
if (needlog)
xfs_dir2_data_log_header(args, dbp);
xfs_dir3_leaf_check(dp, lbp);
xfs_dir3_data_check(dp, dbp);
xfs_dir3_leaf_log_bests(args, lbp, 0, 0);
return 0;
}
STATIC void
xfs_dir3_leaf_find_stale(
struct xfs_dir3_icleaf_hdr *leafhdr,
struct xfs_dir2_leaf_entry *ents,
int index,
int *lowstale,
int *highstale)
{
for (*lowstale = index - 1; *lowstale >= 0; --*lowstale) {
if (ents[*lowstale].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
break;
}
for (*highstale = index; *highstale < leafhdr->count; ++*highstale) {
if (ents[*highstale].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
break;
if (*lowstale >= 0 && index - *lowstale <= *highstale - index)
break;
}
}
struct xfs_dir2_leaf_entry *
xfs_dir3_leaf_find_entry(
struct xfs_dir3_icleaf_hdr *leafhdr,
struct xfs_dir2_leaf_entry *ents,
int index,
int compact,
int lowstale,
int highstale,
int *lfloglow,
int *lfloghigh)
{
if (!leafhdr->stale) {
xfs_dir2_leaf_entry_t *lep;
lep = &ents[index];
if (index < leafhdr->count)
memmove(lep + 1, lep,
(leafhdr->count - index) * sizeof(*lep));
*lfloglow = index;
*lfloghigh = leafhdr->count++;
return lep;
}
if (compact == 0)
xfs_dir3_leaf_find_stale(leafhdr, ents, index,
&lowstale, &highstale);
if (lowstale >= 0 &&
(highstale == leafhdr->count ||
index - lowstale - 1 < highstale - index)) {
ASSERT(index - lowstale - 1 >= 0);
ASSERT(ents[lowstale].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR));
if (index - lowstale - 1 > 0) {
memmove(&ents[lowstale], &ents[lowstale + 1],
(index - lowstale - 1) *
sizeof(xfs_dir2_leaf_entry_t));
}
*lfloglow = MIN(lowstale, *lfloglow);
*lfloghigh = MAX(index - 1, *lfloghigh);
leafhdr->stale--;
return &ents[index - 1];
}
ASSERT(highstale - index >= 0);
ASSERT(ents[highstale].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR));
if (highstale - index > 0) {
memmove(&ents[index + 1], &ents[index],
(highstale - index) * sizeof(xfs_dir2_leaf_entry_t));
}
*lfloglow = MIN(index, *lfloglow);
*lfloghigh = MAX(highstale, *lfloghigh);
leafhdr->stale--;
return &ents[index];
}
int
xfs_dir2_leaf_addname(
xfs_da_args_t *args)
{
__be16 *bestsp;
int compact;
xfs_dir2_data_hdr_t *hdr;
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
int grown;
int highstale;
int i;
int index;
struct xfs_buf *lbp;
xfs_dir2_leaf_t *leaf;
int length;
xfs_dir2_leaf_entry_t *lep;
int lfloglow;
int lfloghigh;
int lowstale;
xfs_dir2_leaf_tail_t *ltp;
int needbytes;
int needlog;
int needscan;
__be16 *tagp;
xfs_trans_t *tp;
xfs_dir2_db_t use_block;
struct xfs_dir2_data_free *bf;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
trace_xfs_dir2_leaf_addname(args);
dp = args->dp;
tp = args->trans;
error = xfs_dir3_leaf_read(tp, dp, args->geo->leafblk, -1, &lbp);
if (error)
return error;
index = xfs_dir2_leaf_search_hash(args, lbp);
leaf = lbp->b_addr;
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
bestsp = xfs_dir2_leaf_bests_p(ltp);
length = dp->d_ops->data_entsize(args->namelen);
for (use_block = -1, lep = &ents[index];
index < leafhdr.count && be32_to_cpu(lep->hashval) == args->hashval;
index++, lep++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
i = xfs_dir2_dataptr_to_db(args->geo, be32_to_cpu(lep->address));
ASSERT(i < be32_to_cpu(ltp->bestcount));
ASSERT(bestsp[i] != cpu_to_be16(NULLDATAOFF));
if (be16_to_cpu(bestsp[i]) >= length) {
use_block = i;
break;
}
}
if (use_block == -1) {
for (i = 0; i < be32_to_cpu(ltp->bestcount); i++) {
if (bestsp[i] == cpu_to_be16(NULLDATAOFF) &&
use_block == -1)
use_block = i;
else if (be16_to_cpu(bestsp[i]) >= length) {
use_block = i;
break;
}
}
}
needbytes = 0;
if (!leafhdr.stale)
needbytes += sizeof(xfs_dir2_leaf_entry_t);
if (use_block == -1)
needbytes += sizeof(xfs_dir2_data_off_t);
if (use_block != -1 && bestsp[use_block] == cpu_to_be16(NULLDATAOFF))
use_block = -1;
if ((char *)bestsp - (char *)&ents[leafhdr.count] < needbytes &&
leafhdr.stale > 1)
compact = 1;
else if ((char *)bestsp - (char *)&ents[leafhdr.count] < needbytes) {
if ((args->op_flags & XFS_DA_OP_JUSTCHECK) ||
args->total == 0) {
xfs_trans_brelse(tp, lbp);
return -ENOSPC;
}
error = xfs_dir2_leaf_to_node(args, lbp);
if (error)
return error;
return xfs_dir2_node_addname(args);
}
else
compact = 0;
if (args->op_flags & XFS_DA_OP_JUSTCHECK) {
xfs_trans_brelse(tp, lbp);
return use_block == -1 ? -ENOSPC : 0;
}
if (args->total == 0 && use_block == -1) {
xfs_trans_brelse(tp, lbp);
return -ENOSPC;
}
if (compact) {
xfs_dir3_leaf_compact_x1(&leafhdr, ents, &index, &lowstale,
&highstale, &lfloglow, &lfloghigh);
}
else if (leafhdr.stale) {
lfloglow = leafhdr.count;
lfloghigh = -1;
}
if (use_block == -1) {
if ((error = xfs_dir2_grow_inode(args, XFS_DIR2_DATA_SPACE,
&use_block))) {
xfs_trans_brelse(tp, lbp);
return error;
}
if ((error = xfs_dir3_data_init(args, use_block, &dbp))) {
xfs_trans_brelse(tp, lbp);
return error;
}
if (use_block >= be32_to_cpu(ltp->bestcount)) {
bestsp--;
memmove(&bestsp[0], &bestsp[1],
be32_to_cpu(ltp->bestcount) * sizeof(bestsp[0]));
be32_add_cpu(&ltp->bestcount, 1);
xfs_dir3_leaf_log_tail(args, lbp);
xfs_dir3_leaf_log_bests(args, lbp, 0,
be32_to_cpu(ltp->bestcount) - 1);
}
else
xfs_dir3_leaf_log_bests(args, lbp, use_block, use_block);
hdr = dbp->b_addr;
bf = dp->d_ops->data_bestfree_p(hdr);
bestsp[use_block] = bf[0].length;
grown = 1;
} else {
error = xfs_dir3_data_read(tp, dp,
xfs_dir2_db_to_da(args->geo, use_block),
-1, &dbp);
if (error) {
xfs_trans_brelse(tp, lbp);
return error;
}
hdr = dbp->b_addr;
bf = dp->d_ops->data_bestfree_p(hdr);
grown = 0;
}
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(bf[0].offset));
ASSERT(be16_to_cpu(dup->length) >= length);
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
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(args, dbp);
xfs_dir2_data_log_entry(args, dbp, dep);
if (be16_to_cpu(bestsp[use_block]) != be16_to_cpu(bf[0].length)) {
bestsp[use_block] = bf[0].length;
if (!grown)
xfs_dir3_leaf_log_bests(args, lbp, use_block, use_block);
}
lep = xfs_dir3_leaf_find_entry(&leafhdr, ents, index, compact, lowstale,
highstale, &lfloglow, &lfloghigh);
lep->hashval = cpu_to_be32(args->hashval);
lep->address = cpu_to_be32(
xfs_dir2_db_off_to_dataptr(args->geo, use_block,
be16_to_cpu(*tagp)));
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, lbp);
xfs_dir3_leaf_log_ents(args, lbp, lfloglow, lfloghigh);
xfs_dir3_leaf_check(dp, lbp);
xfs_dir3_data_check(dp, dbp);
return 0;
}
void
xfs_dir3_leaf_compact(
xfs_da_args_t *args,
struct xfs_dir3_icleaf_hdr *leafhdr,
struct xfs_buf *bp)
{
int from;
xfs_dir2_leaf_t *leaf;
int loglow;
int to;
struct xfs_dir2_leaf_entry *ents;
struct xfs_inode *dp = args->dp;
leaf = bp->b_addr;
if (!leafhdr->stale)
return;
ents = dp->d_ops->leaf_ents_p(leaf);
for (from = to = 0, loglow = -1; from < leafhdr->count; from++) {
if (ents[from].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
continue;
if (from > to) {
if (loglow == -1)
loglow = to;
ents[to] = ents[from];
}
to++;
}
ASSERT(leafhdr->stale == from - to);
leafhdr->count -= leafhdr->stale;
leafhdr->stale = 0;
dp->d_ops->leaf_hdr_to_disk(leaf, leafhdr);
xfs_dir3_leaf_log_header(args, bp);
if (loglow != -1)
xfs_dir3_leaf_log_ents(args, bp, loglow, to - 1);
}
void
xfs_dir3_leaf_compact_x1(
struct xfs_dir3_icleaf_hdr *leafhdr,
struct xfs_dir2_leaf_entry *ents,
int *indexp,
int *lowstalep,
int *highstalep,
int *lowlogp,
int *highlogp)
{
int from;
int highstale;
int index;
int keepstale;
int lowstale;
int newindex=0;
int to;
ASSERT(leafhdr->stale > 1);
index = *indexp;
xfs_dir3_leaf_find_stale(leafhdr, ents, index, &lowstale, &highstale);
if (lowstale >= 0 &&
(highstale == leafhdr->count ||
index - lowstale <= highstale - index))
keepstale = lowstale;
else
keepstale = highstale;
for (from = to = 0; from < leafhdr->count; from++) {
if (index == from)
newindex = to;
if (from != keepstale &&
ents[from].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR)) {
if (from == to)
*lowlogp = to;
continue;
}
if (from == keepstale)
lowstale = highstale = to;
if (from > to)
ents[to] = ents[from];
to++;
}
ASSERT(from > to);
if (index == from)
newindex = to;
*indexp = newindex;
leafhdr->count -= from - to;
leafhdr->stale = 1;
if (lowstale >= newindex)
lowstale = -1;
else
highstale = leafhdr->count;
*highlogp = leafhdr->count - 1;
*lowstalep = lowstale;
*highstalep = highstale;
}
static void
xfs_dir3_leaf_log_bests(
struct xfs_da_args *args,
struct xfs_buf *bp,
int first,
int last)
{
__be16 *firstb;
__be16 *lastb;
struct xfs_dir2_leaf *leaf = bp->b_addr;
xfs_dir2_leaf_tail_t *ltp;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAF1_MAGIC));
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
firstb = xfs_dir2_leaf_bests_p(ltp) + first;
lastb = xfs_dir2_leaf_bests_p(ltp) + last;
xfs_trans_log_buf(args->trans, bp,
(uint)((char *)firstb - (char *)leaf),
(uint)((char *)lastb - (char *)leaf + sizeof(*lastb) - 1));
}
void
xfs_dir3_leaf_log_ents(
struct xfs_da_args *args,
struct xfs_buf *bp,
int first,
int last)
{
xfs_dir2_leaf_entry_t *firstlep;
xfs_dir2_leaf_entry_t *lastlep;
struct xfs_dir2_leaf *leaf = bp->b_addr;
struct xfs_dir2_leaf_entry *ents;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAFN_MAGIC));
ents = args->dp->d_ops->leaf_ents_p(leaf);
firstlep = &ents[first];
lastlep = &ents[last];
xfs_trans_log_buf(args->trans, bp,
(uint)((char *)firstlep - (char *)leaf),
(uint)((char *)lastlep - (char *)leaf + sizeof(*lastlep) - 1));
}
void
xfs_dir3_leaf_log_header(
struct xfs_da_args *args,
struct xfs_buf *bp)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAFN_MAGIC));
xfs_trans_log_buf(args->trans, bp,
(uint)((char *)&leaf->hdr - (char *)leaf),
args->dp->d_ops->leaf_hdr_size - 1);
}
STATIC void
xfs_dir3_leaf_log_tail(
struct xfs_da_args *args,
struct xfs_buf *bp)
{
struct xfs_dir2_leaf *leaf = bp->b_addr;
xfs_dir2_leaf_tail_t *ltp;
ASSERT(leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAF1_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC) ||
leaf->hdr.info.magic == cpu_to_be16(XFS_DIR3_LEAFN_MAGIC));
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
xfs_trans_log_buf(args->trans, bp, (uint)((char *)ltp - (char *)leaf),
(uint)(args->geo->blksize - 1));
}
int
xfs_dir2_leaf_lookup(
xfs_da_args_t *args)
{
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
struct xfs_buf *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_trans_t *tp;
struct xfs_dir2_leaf_entry *ents;
trace_xfs_dir2_leaf_lookup(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
tp = args->trans;
dp = args->dp;
xfs_dir3_leaf_check(dp, lbp);
leaf = lbp->b_addr;
ents = dp->d_ops->leaf_ents_p(leaf);
lep = &ents[index];
dep = (xfs_dir2_data_entry_t *)
((char *)dbp->b_addr +
xfs_dir2_dataptr_to_off(args->geo, be32_to_cpu(lep->address)));
args->inumber = be64_to_cpu(dep->inumber);
args->filetype = dp->d_ops->data_get_ftype(dep);
error = xfs_dir_cilookup_result(args, dep->name, dep->namelen);
xfs_trans_brelse(tp, dbp);
xfs_trans_brelse(tp, lbp);
return error;
}
static int
xfs_dir2_leaf_lookup_int(
xfs_da_args_t *args,
struct xfs_buf **lbpp,
int *indexp,
struct xfs_buf **dbpp)
{
xfs_dir2_db_t curdb = -1;
struct xfs_buf *dbp = NULL;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
struct xfs_buf *lbp;
xfs_dir2_leaf_entry_t *lep;
xfs_dir2_leaf_t *leaf;
xfs_mount_t *mp;
xfs_dir2_db_t newdb;
xfs_trans_t *tp;
xfs_dir2_db_t cidb = -1;
enum xfs_dacmp cmp;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
error = xfs_dir3_leaf_read(tp, dp, args->geo->leafblk, -1, &lbp);
if (error)
return error;
*lbpp = lbp;
leaf = lbp->b_addr;
xfs_dir3_leaf_check(dp, lbp);
ents = dp->d_ops->leaf_ents_p(leaf);
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
index = xfs_dir2_leaf_search_hash(args, lbp);
for (lep = &ents[index];
index < leafhdr.count && be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(args->geo,
be32_to_cpu(lep->address));
if (newdb != curdb) {
if (dbp)
xfs_trans_brelse(tp, dbp);
error = xfs_dir3_data_read(tp, dp,
xfs_dir2_db_to_da(args->geo, newdb),
-1, &dbp);
if (error) {
xfs_trans_brelse(tp, lbp);
return error;
}
curdb = newdb;
}
dep = (xfs_dir2_data_entry_t *)((char *)dbp->b_addr +
xfs_dir2_dataptr_to_off(args->geo,
be32_to_cpu(lep->address)));
cmp = mp->m_dirnameops->compname(args, dep->name, dep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
args->cmpresult = cmp;
*indexp = index;
if (cmp == XFS_CMP_EXACT) {
*dbpp = dbp;
return 0;
}
cidb = curdb;
}
}
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (args->cmpresult == XFS_CMP_CASE) {
ASSERT(cidb != -1);
if (cidb != curdb) {
xfs_trans_brelse(tp, dbp);
error = xfs_dir3_data_read(tp, dp,
xfs_dir2_db_to_da(args->geo, cidb),
-1, &dbp);
if (error) {
xfs_trans_brelse(tp, lbp);
return error;
}
}
*dbpp = dbp;
return 0;
}
ASSERT(cidb == -1);
if (dbp)
xfs_trans_brelse(tp, dbp);
xfs_trans_brelse(tp, lbp);
return -ENOENT;
}
int
xfs_dir2_leaf_removename(
xfs_da_args_t *args)
{
__be16 *bestsp;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_db_t db;
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
xfs_dir2_db_t i;
int index;
struct xfs_buf *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_dir2_leaf_tail_t *ltp;
int needlog;
int needscan;
xfs_dir2_data_off_t oldbest;
struct xfs_dir2_data_free *bf;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
trace_xfs_dir2_leaf_removename(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
dp = args->dp;
leaf = lbp->b_addr;
hdr = dbp->b_addr;
xfs_dir3_data_check(dp, dbp);
bf = dp->d_ops->data_bestfree_p(hdr);
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
lep = &ents[index];
db = xfs_dir2_dataptr_to_db(args->geo, be32_to_cpu(lep->address));
dep = (xfs_dir2_data_entry_t *)((char *)hdr +
xfs_dir2_dataptr_to_off(args->geo, be32_to_cpu(lep->address)));
needscan = needlog = 0;
oldbest = be16_to_cpu(bf[0].length);
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
bestsp = xfs_dir2_leaf_bests_p(ltp);
ASSERT(be16_to_cpu(bestsp[db]) == oldbest);
xfs_dir2_data_make_free(args, dbp,
(xfs_dir2_data_aoff_t)((char *)dep - (char *)hdr),
dp->d_ops->data_entsize(dep->namelen), &needlog, &needscan);
leafhdr.stale++;
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, lbp);
lep->address = cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
xfs_dir3_leaf_log_ents(args, lbp, index, index);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(args, dbp);
if (be16_to_cpu(bf[0].length) != oldbest) {
bestsp[db] = bf[0].length;
xfs_dir3_leaf_log_bests(args, lbp, db, db);
}
xfs_dir3_data_check(dp, dbp);
if (be16_to_cpu(bf[0].length) ==
args->geo->blksize - dp->d_ops->data_entry_offset) {
ASSERT(db != args->geo->datablk);
if ((error = xfs_dir2_shrink_inode(args, db, dbp))) {
if (error == -ENOSPC && args->total == 0)
error = 0;
xfs_dir3_leaf_check(dp, lbp);
return error;
}
dbp = NULL;
if (db == be32_to_cpu(ltp->bestcount) - 1) {
for (i = db - 1; i > 0; i--) {
if (bestsp[i] != cpu_to_be16(NULLDATAOFF))
break;
}
memmove(&bestsp[db - i], bestsp,
(be32_to_cpu(ltp->bestcount) - (db - i)) * sizeof(*bestsp));
be32_add_cpu(&ltp->bestcount, -(db - i));
xfs_dir3_leaf_log_tail(args, lbp);
xfs_dir3_leaf_log_bests(args, lbp, 0,
be32_to_cpu(ltp->bestcount) - 1);
} else
bestsp[db] = cpu_to_be16(NULLDATAOFF);
}
else if (db != args->geo->datablk)
dbp = NULL;
xfs_dir3_leaf_check(dp, lbp);
return xfs_dir2_leaf_to_block(args, lbp, dbp);
}
int
xfs_dir2_leaf_replace(
xfs_da_args_t *args)
{
struct xfs_buf *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
struct xfs_buf *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_trans_t *tp;
struct xfs_dir2_leaf_entry *ents;
trace_xfs_dir2_leaf_replace(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
dp = args->dp;
leaf = lbp->b_addr;
ents = dp->d_ops->leaf_ents_p(leaf);
lep = &ents[index];
dep = (xfs_dir2_data_entry_t *)
((char *)dbp->b_addr +
xfs_dir2_dataptr_to_off(args->geo, be32_to_cpu(lep->address)));
ASSERT(args->inumber != be64_to_cpu(dep->inumber));
dep->inumber = cpu_to_be64(args->inumber);
dp->d_ops->data_put_ftype(dep, args->filetype);
tp = args->trans;
xfs_dir2_data_log_entry(args, dbp, dep);
xfs_dir3_leaf_check(dp, lbp);
xfs_trans_brelse(tp, lbp);
return 0;
}
int
xfs_dir2_leaf_search_hash(
xfs_da_args_t *args,
struct xfs_buf *lbp)
{
xfs_dahash_t hash=0;
xfs_dahash_t hashwant;
int high;
int low;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int mid=0;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
leaf = lbp->b_addr;
ents = args->dp->d_ops->leaf_ents_p(leaf);
args->dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
for (lep = ents, low = 0, high = leafhdr.count - 1,
hashwant = args->hashval;
low <= high; ) {
mid = (low + high) >> 1;
if ((hash = be32_to_cpu(lep[mid].hashval)) == hashwant)
break;
if (hash < hashwant)
low = mid + 1;
else
high = mid - 1;
}
if (hash == hashwant) {
while (mid > 0 && be32_to_cpu(lep[mid - 1].hashval) == hashwant) {
mid--;
}
}
else if (hash < hashwant)
mid++;
return mid;
}
int
xfs_dir2_leaf_trim_data(
xfs_da_args_t *args,
struct xfs_buf *lbp,
xfs_dir2_db_t db)
{
__be16 *bestsp;
struct xfs_buf *dbp;
xfs_inode_t *dp;
int error;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_trans_t *tp;
dp = args->dp;
tp = args->trans;
error = xfs_dir3_data_read(tp, dp, xfs_dir2_db_to_da(args->geo, db),
-1, &dbp);
if (error)
return error;
leaf = lbp->b_addr;
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
#ifdef DEBUG
{
struct xfs_dir2_data_hdr *hdr = dbp->b_addr;
struct xfs_dir2_data_free *bf = dp->d_ops->data_bestfree_p(hdr);
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC));
ASSERT(be16_to_cpu(bf[0].length) ==
args->geo->blksize - dp->d_ops->data_entry_offset);
ASSERT(db == be32_to_cpu(ltp->bestcount) - 1);
}
#endif
if ((error = xfs_dir2_shrink_inode(args, db, dbp))) {
ASSERT(error != -ENOSPC);
xfs_trans_brelse(tp, dbp);
return error;
}
bestsp = xfs_dir2_leaf_bests_p(ltp);
be32_add_cpu(&ltp->bestcount, -1);
memmove(&bestsp[1], &bestsp[0], be32_to_cpu(ltp->bestcount) * sizeof(*bestsp));
xfs_dir3_leaf_log_tail(args, lbp);
xfs_dir3_leaf_log_bests(args, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
return 0;
}
static inline size_t
xfs_dir3_leaf_size(
struct xfs_dir3_icleaf_hdr *hdr,
int counts)
{
int entries;
int hdrsize;
entries = hdr->count - hdr->stale;
if (hdr->magic == XFS_DIR2_LEAF1_MAGIC ||
hdr->magic == XFS_DIR2_LEAFN_MAGIC)
hdrsize = sizeof(struct xfs_dir2_leaf_hdr);
else
hdrsize = sizeof(struct xfs_dir3_leaf_hdr);
return hdrsize + entries * sizeof(xfs_dir2_leaf_entry_t)
+ counts * sizeof(xfs_dir2_data_off_t)
+ sizeof(xfs_dir2_leaf_tail_t);
}
int
xfs_dir2_node_to_leaf(
xfs_da_state_t *state)
{
xfs_da_args_t *args;
xfs_inode_t *dp;
int error;
struct xfs_buf *fbp;
xfs_fileoff_t fo;
xfs_dir2_free_t *free;
struct xfs_buf *lbp;
xfs_dir2_leaf_tail_t *ltp;
xfs_dir2_leaf_t *leaf;
xfs_mount_t *mp;
int rval;
xfs_trans_t *tp;
struct xfs_dir3_icleaf_hdr leafhdr;
struct xfs_dir3_icfree_hdr freehdr;
if (state->path.active > 1)
return 0;
args = state->args;
trace_xfs_dir2_node_to_leaf(args);
mp = state->mp;
dp = args->dp;
tp = args->trans;
if ((error = xfs_bmap_last_offset(dp, &fo, XFS_DATA_FORK))) {
return error;
}
fo -= args->geo->fsbcount;
while (fo > args->geo->freeblk) {
if ((error = xfs_dir2_node_trim_free(args, fo, &rval))) {
return error;
}
if (rval)
fo -= args->geo->fsbcount;
else
return 0;
}
if ((error = xfs_bmap_last_before(tp, dp, &fo, XFS_DATA_FORK))) {
return error;
}
if (XFS_FSB_TO_B(mp, fo) > XFS_DIR2_LEAF_OFFSET + args->geo->blksize)
return 0;
lbp = state->path.blk[0].bp;
leaf = lbp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ASSERT(leafhdr.magic == XFS_DIR2_LEAFN_MAGIC ||
leafhdr.magic == XFS_DIR3_LEAFN_MAGIC);
error = xfs_dir2_free_read(tp, dp, args->geo->freeblk, &fbp);
if (error)
return error;
free = fbp->b_addr;
dp->d_ops->free_hdr_from_disk(&freehdr, free);
ASSERT(!freehdr.firstdb);
if (xfs_dir3_leaf_size(&leafhdr, freehdr.nvalid) > args->geo->blksize) {
xfs_trans_brelse(tp, fbp);
return 0;
}
if (leafhdr.stale)
xfs_dir3_leaf_compact(args, &leafhdr, lbp);
lbp->b_ops = &xfs_dir3_leaf1_buf_ops;
xfs_trans_buf_set_type(tp, lbp, XFS_BLFT_DIR_LEAF1_BUF);
leafhdr.magic = (leafhdr.magic == XFS_DIR2_LEAFN_MAGIC)
? XFS_DIR2_LEAF1_MAGIC
: XFS_DIR3_LEAF1_MAGIC;
ltp = xfs_dir2_leaf_tail_p(args->geo, leaf);
ltp->bestcount = cpu_to_be32(freehdr.nvalid);
memcpy(xfs_dir2_leaf_bests_p(ltp), dp->d_ops->free_bests_p(free),
freehdr.nvalid * sizeof(xfs_dir2_data_off_t));
dp->d_ops->leaf_hdr_to_disk(leaf, &leafhdr);
xfs_dir3_leaf_log_header(args, lbp);
xfs_dir3_leaf_log_bests(args, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
xfs_dir3_leaf_log_tail(args, lbp);
xfs_dir3_leaf_check(dp, lbp);
error = xfs_dir2_shrink_inode(args,
xfs_dir2_byte_to_db(args->geo, XFS_DIR2_FREE_OFFSET),
fbp);
if (error) {
ASSERT(error != -ENOSPC);
return error;
}
fbp = NULL;
error = xfs_dir2_leaf_to_block(args, lbp, NULL);
state->path.blk[0].bp = NULL;
return error;
}
