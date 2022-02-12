void
xfs_dir_startup(void)
{
xfs_dir_hash_dot = xfs_da_hashname((unsigned char *)".", 1);
xfs_dir_hash_dotdot = xfs_da_hashname((unsigned char *)"..", 2);
}
static bool
xfs_dir3_block_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (hdr3->magic != cpu_to_be32(XFS_DIR3_BLOCK_MAGIC))
return false;
if (!uuid_equal(&hdr3->uuid, &mp->m_sb.sb_uuid))
return false;
if (be64_to_cpu(hdr3->blkno) != bp->b_bn)
return false;
} else {
if (hdr3->magic != cpu_to_be32(XFS_DIR2_BLOCK_MAGIC))
return false;
}
if (__xfs_dir3_data_check(NULL, bp))
return false;
return true;
}
static void
xfs_dir3_block_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb) &&
!xfs_buf_verify_cksum(bp, XFS_DIR3_DATA_CRC_OFF))
xfs_buf_ioerror(bp, EFSBADCRC);
else if (!xfs_dir3_block_verify(bp))
xfs_buf_ioerror(bp, EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
xfs_dir3_block_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (!xfs_dir3_block_verify(bp)) {
xfs_buf_ioerror(bp, EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (bip)
hdr3->lsn = cpu_to_be64(bip->bli_item.li_lsn);
xfs_buf_update_cksum(bp, XFS_DIR3_DATA_CRC_OFF);
}
int
xfs_dir3_block_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
struct xfs_buf **bpp)
{
struct xfs_mount *mp = dp->i_mount;
int err;
err = xfs_da_read_buf(tp, dp, mp->m_dirdatablk, -1, bpp,
XFS_DATA_FORK, &xfs_dir3_block_buf_ops);
if (!err && tp)
xfs_trans_buf_set_type(tp, *bpp, XFS_BLFT_DIR_BLOCK_BUF);
return err;
}
static void
xfs_dir3_block_init(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *bp,
struct xfs_inode *dp)
{
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
bp->b_ops = &xfs_dir3_block_buf_ops;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DIR_BLOCK_BUF);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
memset(hdr3, 0, sizeof(*hdr3));
hdr3->magic = cpu_to_be32(XFS_DIR3_BLOCK_MAGIC);
hdr3->blkno = cpu_to_be64(bp->b_bn);
hdr3->owner = cpu_to_be64(dp->i_ino);
uuid_copy(&hdr3->uuid, &mp->m_sb.sb_uuid);
return;
}
hdr3->magic = cpu_to_be32(XFS_DIR2_BLOCK_MAGIC);
}
static void
xfs_dir2_block_need_space(
struct xfs_inode *dp,
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_block_tail *btp,
struct xfs_dir2_leaf_entry *blp,
__be16 **tagpp,
struct xfs_dir2_data_unused **dupp,
struct xfs_dir2_data_unused **enddupp,
int *compact,
int len)
{
struct xfs_dir2_data_free *bf;
__be16 *tagp = NULL;
struct xfs_dir2_data_unused *dup = NULL;
struct xfs_dir2_data_unused *enddup = NULL;
*compact = 0;
bf = dp->d_ops->data_bestfree_p(hdr);
if (btp->stale) {
if (be16_to_cpu(bf[0].length) >= len) {
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(bf[0].offset));
goto out;
}
*compact = 1;
tagp = (__be16 *)blp - 1;
dup = (xfs_dir2_data_unused_t *)((char *)hdr + be16_to_cpu(*tagp));
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
if (be16_to_cpu(dup->length) + (be32_to_cpu(btp->stale) - 1) *
(uint)sizeof(*blp) < len)
dup = NULL;
} else if ((be32_to_cpu(btp->stale) - 1) * (uint)sizeof(*blp) < len)
dup = NULL;
else
dup = (xfs_dir2_data_unused_t *)blp;
goto out;
}
tagp = (__be16 *)blp - 1;
enddup = (xfs_dir2_data_unused_t *)((char *)hdr + be16_to_cpu(*tagp));
if (be16_to_cpu(enddup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(bf[0].offset));
if (dup != enddup) {
if (be16_to_cpu(dup->length) < len)
dup = NULL;
goto out;
}
if (be16_to_cpu(dup->length) < len + (uint)sizeof(*blp)) {
if (be16_to_cpu(bf[1].length) >= len)
dup = (xfs_dir2_data_unused_t *)
((char *)hdr + be16_to_cpu(bf[1].offset));
else
dup = NULL;
}
}
out:
*tagpp = tagp;
*dupp = dup;
*enddupp = enddup;
}
static void
xfs_dir2_block_compact(
struct xfs_trans *tp,
struct xfs_inode *dp,
struct xfs_buf *bp,
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_block_tail *btp,
struct xfs_dir2_leaf_entry *blp,
int *needlog,
int *lfloghigh,
int *lfloglow)
{
int fromidx;
int toidx;
int needscan = 0;
int highstale;
fromidx = toidx = be32_to_cpu(btp->count) - 1;
highstale = *lfloghigh = -1;
for (; fromidx >= 0; fromidx--) {
if (blp[fromidx].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR)) {
if (highstale == -1)
highstale = toidx;
else {
if (*lfloghigh == -1)
*lfloghigh = toidx;
continue;
}
}
if (fromidx < toidx)
blp[toidx] = blp[fromidx];
toidx--;
}
*lfloglow = toidx + 1 - (be32_to_cpu(btp->stale) - 1);
*lfloghigh -= be32_to_cpu(btp->stale) - 1;
be32_add_cpu(&btp->count, -(be32_to_cpu(btp->stale) - 1));
xfs_dir2_data_make_free(tp, dp, bp,
(xfs_dir2_data_aoff_t)((char *)blp - (char *)hdr),
(xfs_dir2_data_aoff_t)((be32_to_cpu(btp->stale) - 1) * sizeof(*blp)),
needlog, &needscan);
blp += be32_to_cpu(btp->stale) - 1;
btp->stale = cpu_to_be32(1);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, needlog);
}
int
xfs_dir2_block_addname(
xfs_da_args_t *args)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
int compact;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
xfs_dir2_data_unused_t *enddup=NULL;
xfs_dahash_t hash;
int high;
int highstale;
int lfloghigh=0;
int lfloglow=0;
int len;
int low;
int lowstale;
int mid=0;
xfs_mount_t *mp;
int needlog;
int needscan;
__be16 *tagp;
xfs_trans_t *tp;
trace_xfs_dir2_block_addname(args);
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
error = xfs_dir3_block_read(tp, dp, &bp);
if (error)
return error;
len = dp->d_ops->data_entsize(args->namelen);
hdr = bp->b_addr;
btp = xfs_dir2_block_tail_p(mp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
xfs_dir2_block_need_space(dp, hdr, btp, blp, &tagp, &dup,
&enddup, &compact, len);
if (args->op_flags & XFS_DA_OP_JUSTCHECK) {
xfs_trans_brelse(tp, bp);
if (!dup)
return XFS_ERROR(ENOSPC);
return 0;
}
if (!dup) {
if (args->total == 0)
return XFS_ERROR(ENOSPC);
error = xfs_dir2_block_to_leaf(args, bp);
if (error)
return error;
return xfs_dir2_leaf_addname(args);
}
needlog = needscan = 0;
if (compact) {
xfs_dir2_block_compact(tp, dp, bp, hdr, btp, blp, &needlog,
&lfloghigh, &lfloglow);
blp = xfs_dir2_block_leaf_p(btp);
} else if (btp->stale) {
lfloglow = be32_to_cpu(btp->count);
lfloghigh = -1;
}
for (low = 0, high = be32_to_cpu(btp->count) - 1; low <= high; ) {
mid = (low + high) >> 1;
if ((hash = be32_to_cpu(blp[mid].hashval)) == args->hashval)
break;
if (hash < args->hashval)
low = mid + 1;
else
high = mid - 1;
}
while (mid >= 0 && be32_to_cpu(blp[mid].hashval) >= args->hashval) {
mid--;
}
if (!btp->stale) {
xfs_dir2_data_use_free(tp, dp, bp, enddup,
(xfs_dir2_data_aoff_t)
((char *)enddup - (char *)hdr + be16_to_cpu(enddup->length) -
sizeof(*blp)),
(xfs_dir2_data_aoff_t)sizeof(*blp),
&needlog, &needscan);
be32_add_cpu(&btp->count, 1);
if (needscan) {
xfs_dir2_data_freescan(dp, hdr, &needlog);
needscan = 0;
}
blp--;
mid++;
if (mid)
memmove(blp, &blp[1], mid * sizeof(*blp));
lfloglow = 0;
lfloghigh = mid;
}
else {
for (lowstale = mid;
lowstale >= 0 &&
blp[lowstale].address !=
cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
lowstale--)
continue;
for (highstale = mid + 1;
highstale < be32_to_cpu(btp->count) &&
blp[highstale].address !=
cpu_to_be32(XFS_DIR2_NULL_DATAPTR) &&
(lowstale < 0 || mid - lowstale > highstale - mid);
highstale++)
continue;
if (lowstale >= 0 &&
(highstale == be32_to_cpu(btp->count) ||
mid - lowstale <= highstale - mid)) {
if (mid - lowstale)
memmove(&blp[lowstale], &blp[lowstale + 1],
(mid - lowstale) * sizeof(*blp));
lfloglow = MIN(lowstale, lfloglow);
lfloghigh = MAX(mid, lfloghigh);
}
else {
ASSERT(highstale < be32_to_cpu(btp->count));
mid++;
if (highstale - mid)
memmove(&blp[mid + 1], &blp[mid],
(highstale - mid) * sizeof(*blp));
lfloglow = MIN(mid, lfloglow);
lfloghigh = MAX(highstale, lfloghigh);
}
be32_add_cpu(&btp->stale, -1);
}
dep = (xfs_dir2_data_entry_t *)dup;
blp[mid].hashval = cpu_to_be32(args->hashval);
blp[mid].address = cpu_to_be32(xfs_dir2_byte_to_dataptr(mp,
(char *)dep - (char *)hdr));
xfs_dir2_block_log_leaf(tp, bp, lfloglow, lfloghigh);
xfs_dir2_data_use_free(tp, dp, bp, dup,
(xfs_dir2_data_aoff_t)((char *)dup - (char *)hdr),
(xfs_dir2_data_aoff_t)len, &needlog, &needscan);
dep->inumber = cpu_to_be64(args->inumber);
dep->namelen = args->namelen;
memcpy(dep->name, args->name, args->namelen);
dp->d_ops->data_put_ftype(dep, args->filetype);
tagp = dp->d_ops->data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dp, bp);
xfs_dir2_block_log_tail(tp, bp);
xfs_dir2_data_log_entry(tp, dp, bp, dep);
xfs_dir3_data_check(dp, bp);
return 0;
}
static void
xfs_dir2_block_log_leaf(
xfs_trans_t *tp,
struct xfs_buf *bp,
int first,
int last)
{
xfs_dir2_data_hdr_t *hdr = bp->b_addr;
xfs_dir2_leaf_entry_t *blp;
xfs_dir2_block_tail_t *btp;
btp = xfs_dir2_block_tail_p(tp->t_mountp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
xfs_trans_log_buf(tp, bp, (uint)((char *)&blp[first] - (char *)hdr),
(uint)((char *)&blp[last + 1] - (char *)hdr - 1));
}
static void
xfs_dir2_block_log_tail(
xfs_trans_t *tp,
struct xfs_buf *bp)
{
xfs_dir2_data_hdr_t *hdr = bp->b_addr;
xfs_dir2_block_tail_t *btp;
btp = xfs_dir2_block_tail_p(tp->t_mountp, hdr);
xfs_trans_log_buf(tp, bp, (uint)((char *)btp - (char *)hdr),
(uint)((char *)(btp + 1) - (char *)hdr - 1));
}
int
xfs_dir2_block_lookup(
xfs_da_args_t *args)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int ent;
int error;
xfs_mount_t *mp;
trace_xfs_dir2_block_lookup(args);
if ((error = xfs_dir2_block_lookup_int(args, &bp, &ent)))
return error;
dp = args->dp;
mp = dp->i_mount;
hdr = bp->b_addr;
xfs_dir3_data_check(dp, bp);
btp = xfs_dir2_block_tail_p(mp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
dep = (xfs_dir2_data_entry_t *)((char *)hdr +
xfs_dir2_dataptr_to_off(mp, be32_to_cpu(blp[ent].address)));
args->inumber = be64_to_cpu(dep->inumber);
args->filetype = dp->d_ops->data_get_ftype(dep);
error = xfs_dir_cilookup_result(args, dep->name, dep->namelen);
xfs_trans_brelse(args->trans, bp);
return XFS_ERROR(error);
}
static int
xfs_dir2_block_lookup_int(
xfs_da_args_t *args,
struct xfs_buf **bpp,
int *entno)
{
xfs_dir2_dataptr_t addr;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
xfs_dahash_t hash;
int high;
int low;
int mid;
xfs_mount_t *mp;
xfs_trans_t *tp;
enum xfs_dacmp cmp;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
error = xfs_dir3_block_read(tp, dp, &bp);
if (error)
return error;
hdr = bp->b_addr;
xfs_dir3_data_check(dp, bp);
btp = xfs_dir2_block_tail_p(mp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
for (low = 0, high = be32_to_cpu(btp->count) - 1; ; ) {
ASSERT(low <= high);
mid = (low + high) >> 1;
if ((hash = be32_to_cpu(blp[mid].hashval)) == args->hashval)
break;
if (hash < args->hashval)
low = mid + 1;
else
high = mid - 1;
if (low > high) {
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
xfs_trans_brelse(tp, bp);
return XFS_ERROR(ENOENT);
}
}
while (mid > 0 && be32_to_cpu(blp[mid - 1].hashval) == args->hashval) {
mid--;
}
do {
if ((addr = be32_to_cpu(blp[mid].address)) == XFS_DIR2_NULL_DATAPTR)
continue;
dep = (xfs_dir2_data_entry_t *)
((char *)hdr + xfs_dir2_dataptr_to_off(mp, addr));
cmp = mp->m_dirnameops->compname(args, dep->name, dep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
args->cmpresult = cmp;
*bpp = bp;
*entno = mid;
if (cmp == XFS_CMP_EXACT)
return 0;
}
} while (++mid < be32_to_cpu(btp->count) &&
be32_to_cpu(blp[mid].hashval) == hash);
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (args->cmpresult == XFS_CMP_CASE)
return 0;
xfs_trans_brelse(tp, bp);
return XFS_ERROR(ENOENT);
}
int
xfs_dir2_block_removename(
xfs_da_args_t *args)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int ent;
int error;
xfs_mount_t *mp;
int needlog;
int needscan;
xfs_dir2_sf_hdr_t sfh;
int size;
xfs_trans_t *tp;
trace_xfs_dir2_block_removename(args);
if ((error = xfs_dir2_block_lookup_int(args, &bp, &ent))) {
return error;
}
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
hdr = bp->b_addr;
btp = xfs_dir2_block_tail_p(mp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
dep = (xfs_dir2_data_entry_t *)
((char *)hdr + xfs_dir2_dataptr_to_off(mp, be32_to_cpu(blp[ent].address)));
needlog = needscan = 0;
xfs_dir2_data_make_free(tp, dp, bp,
(xfs_dir2_data_aoff_t)((char *)dep - (char *)hdr),
dp->d_ops->data_entsize(dep->namelen), &needlog, &needscan);
be32_add_cpu(&btp->stale, 1);
xfs_dir2_block_log_tail(tp, bp);
blp[ent].address = cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
xfs_dir2_block_log_leaf(tp, bp, ent, ent);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dp, bp);
xfs_dir3_data_check(dp, bp);
size = xfs_dir2_block_sfsize(dp, hdr, &sfh);
if (size > XFS_IFORK_DSIZE(dp))
return 0;
return xfs_dir2_block_to_sf(args, bp, size, &sfh);
}
int
xfs_dir2_block_replace(
xfs_da_args_t *args)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int ent;
int error;
xfs_mount_t *mp;
trace_xfs_dir2_block_replace(args);
if ((error = xfs_dir2_block_lookup_int(args, &bp, &ent))) {
return error;
}
dp = args->dp;
mp = dp->i_mount;
hdr = bp->b_addr;
btp = xfs_dir2_block_tail_p(mp, hdr);
blp = xfs_dir2_block_leaf_p(btp);
dep = (xfs_dir2_data_entry_t *)
((char *)hdr + xfs_dir2_dataptr_to_off(mp, be32_to_cpu(blp[ent].address)));
ASSERT(be64_to_cpu(dep->inumber) != args->inumber);
dep->inumber = cpu_to_be64(args->inumber);
dp->d_ops->data_put_ftype(dep, args->filetype);
xfs_dir2_data_log_entry(args->trans, dp, bp, dep);
xfs_dir3_data_check(dp, bp);
return 0;
}
static int
xfs_dir2_block_sort(
const void *a,
const void *b)
{
const xfs_dir2_leaf_entry_t *la;
const xfs_dir2_leaf_entry_t *lb;
la = a;
lb = b;
return be32_to_cpu(la->hashval) < be32_to_cpu(lb->hashval) ? -1 :
(be32_to_cpu(la->hashval) > be32_to_cpu(lb->hashval) ? 1 : 0);
}
int
xfs_dir2_leaf_to_block(
xfs_da_args_t *args,
struct xfs_buf *lbp,
struct xfs_buf *dbp)
{
__be16 *bestsp;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_block_tail_t *btp;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
int from;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int needlog;
int needscan;
xfs_dir2_sf_hdr_t sfh;
int size;
__be16 *tagp;
int to;
xfs_trans_t *tp;
struct xfs_dir2_leaf_entry *ents;
struct xfs_dir3_icleaf_hdr leafhdr;
trace_xfs_dir2_leaf_to_block(args);
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = lbp->b_addr;
dp->d_ops->leaf_hdr_from_disk(&leafhdr, leaf);
ents = dp->d_ops->leaf_ents_p(leaf);
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ASSERT(leafhdr.magic == XFS_DIR2_LEAF1_MAGIC ||
leafhdr.magic == XFS_DIR3_LEAF1_MAGIC);
while (dp->i_d.di_size > mp->m_dirblksize) {
int hdrsz;
hdrsz = dp->d_ops->data_entry_offset;
bestsp = xfs_dir2_leaf_bests_p(ltp);
if (be16_to_cpu(bestsp[be32_to_cpu(ltp->bestcount) - 1]) ==
mp->m_dirblksize - hdrsz) {
if ((error =
xfs_dir2_leaf_trim_data(args, lbp,
(xfs_dir2_db_t)(be32_to_cpu(ltp->bestcount) - 1))))
return error;
} else
return 0;
}
if (!dbp) {
error = xfs_dir3_data_read(tp, dp, mp->m_dirdatablk, -1, &dbp);
if (error)
return error;
}
hdr = dbp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC));
size = (uint)sizeof(xfs_dir2_block_tail_t) +
(uint)sizeof(*lep) * (leafhdr.count - leafhdr.stale);
tagp = (__be16 *)((char *)hdr + mp->m_dirblksize) - 1;
dup = (xfs_dir2_data_unused_t *)((char *)hdr + be16_to_cpu(*tagp));
if (be16_to_cpu(dup->freetag) != XFS_DIR2_DATA_FREE_TAG ||
be16_to_cpu(dup->length) < size)
return 0;
xfs_dir3_block_init(mp, tp, dbp, dp);
needlog = 1;
needscan = 0;
xfs_dir2_data_use_free(tp, dp, dbp, dup, mp->m_dirblksize - size, size,
&needlog, &needscan);
btp = xfs_dir2_block_tail_p(mp, hdr);
btp->count = cpu_to_be32(leafhdr.count - leafhdr.stale);
btp->stale = 0;
xfs_dir2_block_log_tail(tp, dbp);
lep = xfs_dir2_block_leaf_p(btp);
for (from = to = 0; from < leafhdr.count; from++) {
if (ents[from].address == cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
continue;
lep[to++] = ents[from];
}
ASSERT(to == be32_to_cpu(btp->count));
xfs_dir2_block_log_leaf(tp, dbp, 0, be32_to_cpu(btp->count) - 1);
if (needscan)
xfs_dir2_data_freescan(dp, hdr, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dp, dbp);
error = xfs_da_shrink_inode(args, mp->m_dirleafblk, lbp);
if (error)
return error;
size = xfs_dir2_block_sfsize(dp, hdr, &sfh);
if (size > XFS_IFORK_DSIZE(dp))
return 0;
return xfs_dir2_block_to_sf(args, dbp, size, &sfh);
}
int
xfs_dir2_sf_to_block(
xfs_da_args_t *args)
{
xfs_dir2_db_t blkno;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_leaf_entry_t *blp;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int dummy;
xfs_dir2_data_unused_t *dup;
int endoffset;
int error;
int i;
xfs_mount_t *mp;
int needlog;
int needscan;
int newoffset;
int offset;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *oldsfp;
xfs_dir2_sf_hdr_t *sfp;
__be16 *tagp;
xfs_trans_t *tp;
struct xfs_name name;
struct xfs_ifork *ifp;
trace_xfs_dir2_sf_to_block(args);
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
ifp = XFS_IFORK_PTR(dp, XFS_DATA_FORK);
ASSERT(ifp->if_flags & XFS_IFINLINE);
if (dp->i_d.di_size < offsetof(xfs_dir2_sf_hdr_t, parent)) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
return XFS_ERROR(EIO);
}
oldsfp = (xfs_dir2_sf_hdr_t *)ifp->if_u1.if_data;
ASSERT(ifp->if_bytes == dp->i_d.di_size);
ASSERT(ifp->if_u1.if_data != NULL);
ASSERT(dp->i_d.di_size >= xfs_dir2_sf_hdr_size(oldsfp->i8count));
ASSERT(dp->i_d.di_nextents == 0);
sfp = kmem_alloc(ifp->if_bytes, KM_SLEEP);
memcpy(sfp, oldsfp, ifp->if_bytes);
xfs_idata_realloc(dp, -ifp->if_bytes, XFS_DATA_FORK);
xfs_bmap_local_to_extents_empty(dp, XFS_DATA_FORK);
dp->i_d.di_size = 0;
error = xfs_dir2_grow_inode(args, XFS_DIR2_DATA_SPACE, &blkno);
if (error) {
kmem_free(sfp);
return error;
}
error = xfs_dir3_data_init(args, blkno, &bp);
if (error) {
kmem_free(sfp);
return error;
}
xfs_dir3_block_init(mp, tp, bp, dp);
hdr = bp->b_addr;
i = (uint)sizeof(*btp) +
(sfp->count + 2) * (uint)sizeof(xfs_dir2_leaf_entry_t);
dup = dp->d_ops->data_unused_p(hdr);
needlog = needscan = 0;
xfs_dir2_data_use_free(tp, dp, bp, dup, mp->m_dirblksize - i, i, &needlog,
&needscan);
ASSERT(needscan == 0);
btp = xfs_dir2_block_tail_p(mp, hdr);
btp->count = cpu_to_be32(sfp->count + 2);
btp->stale = 0;
blp = xfs_dir2_block_leaf_p(btp);
endoffset = (uint)((char *)blp - (char *)hdr);
xfs_dir2_data_use_free(tp, dp, bp, dup,
(xfs_dir2_data_aoff_t)((char *)dup - (char *)hdr),
be16_to_cpu(dup->length), &needlog, &needscan);
dep = dp->d_ops->data_dot_entry_p(hdr);
dep->inumber = cpu_to_be64(dp->i_ino);
dep->namelen = 1;
dep->name[0] = '.';
dp->d_ops->data_put_ftype(dep, XFS_DIR3_FT_DIR);
tagp = dp->d_ops->data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
xfs_dir2_data_log_entry(tp, dp, bp, dep);
blp[0].hashval = cpu_to_be32(xfs_dir_hash_dot);
blp[0].address = cpu_to_be32(xfs_dir2_byte_to_dataptr(mp,
(char *)dep - (char *)hdr));
dep = dp->d_ops->data_dotdot_entry_p(hdr);
dep->inumber = cpu_to_be64(dp->d_ops->sf_get_parent_ino(sfp));
dep->namelen = 2;
dep->name[0] = dep->name[1] = '.';
dp->d_ops->data_put_ftype(dep, XFS_DIR3_FT_DIR);
tagp = dp->d_ops->data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
xfs_dir2_data_log_entry(tp, dp, bp, dep);
blp[1].hashval = cpu_to_be32(xfs_dir_hash_dotdot);
blp[1].address = cpu_to_be32(xfs_dir2_byte_to_dataptr(mp,
(char *)dep - (char *)hdr));
offset = dp->d_ops->data_first_offset;
i = 0;
if (!sfp->count)
sfep = NULL;
else
sfep = xfs_dir2_sf_firstentry(sfp);
while (offset < endoffset) {
if (sfep == NULL)
newoffset = endoffset;
else
newoffset = xfs_dir2_sf_get_offset(sfep);
if (offset < newoffset) {
dup = (xfs_dir2_data_unused_t *)((char *)hdr + offset);
dup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
dup->length = cpu_to_be16(newoffset - offset);
*xfs_dir2_data_unused_tag_p(dup) = cpu_to_be16(
((char *)dup - (char *)hdr));
xfs_dir2_data_log_unused(tp, bp, dup);
xfs_dir2_data_freeinsert(hdr,
dp->d_ops->data_bestfree_p(hdr),
dup, &dummy);
offset += be16_to_cpu(dup->length);
continue;
}
dep = (xfs_dir2_data_entry_t *)((char *)hdr + newoffset);
dep->inumber = cpu_to_be64(dp->d_ops->sf_get_ino(sfp, sfep));
dep->namelen = sfep->namelen;
dp->d_ops->data_put_ftype(dep, dp->d_ops->sf_get_ftype(sfep));
memcpy(dep->name, sfep->name, dep->namelen);
tagp = dp->d_ops->data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)hdr);
xfs_dir2_data_log_entry(tp, dp, bp, dep);
name.name = sfep->name;
name.len = sfep->namelen;
blp[2 + i].hashval = cpu_to_be32(mp->m_dirnameops->
hashname(&name));
blp[2 + i].address = cpu_to_be32(xfs_dir2_byte_to_dataptr(mp,
(char *)dep - (char *)hdr));
offset = (int)((char *)(tagp + 1) - (char *)hdr);
if (++i == sfp->count)
sfep = NULL;
else
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
}
kmem_free(sfp);
xfs_sort(blp, be32_to_cpu(btp->count), sizeof(*blp), xfs_dir2_block_sort);
ASSERT(needscan == 0);
xfs_dir2_block_log_leaf(tp, bp, 0, be32_to_cpu(btp->count) - 1);
xfs_dir2_block_log_tail(tp, bp);
xfs_dir3_data_check(dp, bp);
return 0;
}
