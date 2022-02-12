int
__xfs_dir3_data_check(
struct xfs_inode *dp,
struct xfs_buf *bp)
{
xfs_dir2_dataptr_t addr;
xfs_dir2_data_free_t *bf;
xfs_dir2_block_tail_t *btp=NULL;
int count;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_free_t *dfp;
xfs_dir2_data_unused_t *dup;
char *endp;
int freeseen;
xfs_dahash_t hash;
int i;
int lastfree;
xfs_dir2_leaf_entry_t *lep=NULL;
xfs_mount_t *mp;
char *p;
int stale;
struct xfs_name name;
const struct xfs_dir_ops *ops;
struct xfs_da_geometry *geo;
mp = bp->b_target->bt_mount;
geo = mp->m_dir_geo;
ops = xfs_dir_get_ops(mp, dp);
hdr = bp->b_addr;
p = (char *)ops->data_entry_p(hdr);
switch (hdr->magic) {
case cpu_to_be32(XFS_DIR3_BLOCK_MAGIC):
case cpu_to_be32(XFS_DIR2_BLOCK_MAGIC):
btp = xfs_dir2_block_tail_p(geo, hdr);
lep = xfs_dir2_block_leaf_p(btp);
endp = (char *)lep;
XFS_WANT_CORRUPTED_RETURN(mp, be32_to_cpu(btp->count) <
((char *)btp - p) / sizeof(struct xfs_dir2_leaf_entry));
break;
case cpu_to_be32(XFS_DIR3_DATA_MAGIC):
case cpu_to_be32(XFS_DIR2_DATA_MAGIC):
endp = (char *)hdr + geo->blksize;
break;
default:
XFS_ERROR_REPORT("Bad Magic", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
bf = ops->data_bestfree_p(hdr);
count = lastfree = freeseen = 0;
if (!bf[0].length) {
XFS_WANT_CORRUPTED_RETURN(mp, !bf[0].offset);
freeseen |= 1 << 0;
}
if (!bf[1].length) {
XFS_WANT_CORRUPTED_RETURN(mp, !bf[1].offset);
freeseen |= 1 << 1;
}
if (!bf[2].length) {
XFS_WANT_CORRUPTED_RETURN(mp, !bf[2].offset);
freeseen |= 1 << 2;
}
XFS_WANT_CORRUPTED_RETURN(mp, be16_to_cpu(bf[0].length) >=
be16_to_cpu(bf[1].length));
XFS_WANT_CORRUPTED_RETURN(mp, be16_to_cpu(bf[1].length) >=
be16_to_cpu(bf[2].length));
while (p < endp) {
dup = (xfs_dir2_data_unused_t *)p;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
XFS_WANT_CORRUPTED_RETURN(mp, lastfree == 0);
XFS_WANT_CORRUPTED_RETURN(mp,
be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)) ==
(char *)dup - (char *)hdr);
dfp = xfs_dir2_data_freefind(hdr, bf, dup);
if (dfp) {
i = (int)(dfp - bf);
XFS_WANT_CORRUPTED_RETURN(mp,
(freeseen & (1 << i)) == 0);
freeseen |= 1 << i;
} else {
XFS_WANT_CORRUPTED_RETURN(mp,
be16_to_cpu(dup->length) <=
be16_to_cpu(bf[2].length));
}
p += be16_to_cpu(dup->length);
lastfree = 1;
continue;
}
dep = (xfs_dir2_data_entry_t *)p;
XFS_WANT_CORRUPTED_RETURN(mp, dep->namelen != 0);
XFS_WANT_CORRUPTED_RETURN(mp,
!xfs_dir_ino_validate(mp, be64_to_cpu(dep->inumber)));
XFS_WANT_CORRUPTED_RETURN(mp,
be16_to_cpu(*ops->data_entry_tag_p(dep)) ==
(char *)dep - (char *)hdr);
XFS_WANT_CORRUPTED_RETURN(mp,
ops->data_get_ftype(dep) < XFS_DIR3_FT_MAX);
count++;
lastfree = 0;
if (hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC)) {
addr = xfs_dir2_db_off_to_dataptr(geo, geo->datablk,
(xfs_dir2_data_aoff_t)
((char *)dep - (char *)hdr));
name.name = dep->name;
name.len = dep->namelen;
hash = mp->m_dirnameops->hashname(&name);
for (i = 0; i < be32_to_cpu(btp->count); i++) {
if (be32_to_cpu(lep[i].address) == addr &&
be32_to_cpu(lep[i].hashval) == hash)
break;
}
XFS_WANT_CORRUPTED_RETURN(mp,
i < be32_to_cpu(btp->count));
}
p += ops->data_entsize(dep->namelen);
}
XFS_WANT_CORRUPTED_RETURN(mp, freeseen == 7);
if (hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC)) {
for (i = stale = 0; i < be32_to_cpu(btp->count); i++) {
if (lep[i].address ==
cpu_to_be32(XFS_DIR2_NULL_DATAPTR))
stale++;
if (i > 0)
XFS_WANT_CORRUPTED_RETURN(mp,
be32_to_cpu(lep[i].hashval) >=
be32_to_cpu(lep[i - 1].hashval));
}
XFS_WANT_CORRUPTED_RETURN(mp, count ==
be32_to_cpu(btp->count) - be32_to_cpu(btp->stale));
XFS_WANT_CORRUPTED_RETURN(mp, stale == be32_to_cpu(btp->stale));
}
return 0;
}
static bool
xfs_dir3_data_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (hdr3->magic != cpu_to_be32(XFS_DIR3_DATA_MAGIC))
return false;
if (!uuid_equal(&hdr3->uuid, &mp->m_sb.sb_meta_uuid))
return false;
if (be64_to_cpu(hdr3->blkno) != bp->b_bn)
return false;
if (!xfs_log_check_lsn(mp, be64_to_cpu(hdr3->lsn)))
return false;
} else {
if (hdr3->magic != cpu_to_be32(XFS_DIR2_DATA_MAGIC))
return false;
}
if (__xfs_dir3_data_check(NULL, bp))
return false;
return true;
}
static void
xfs_dir3_data_reada_verify(
struct xfs_buf *bp)
{
struct xfs_dir2_data_hdr *hdr = bp->b_addr;
switch (hdr->magic) {
case cpu_to_be32(XFS_DIR2_BLOCK_MAGIC):
case cpu_to_be32(XFS_DIR3_BLOCK_MAGIC):
bp->b_ops = &xfs_dir3_block_buf_ops;
bp->b_ops->verify_read(bp);
return;
case cpu_to_be32(XFS_DIR2_DATA_MAGIC):
case cpu_to_be32(XFS_DIR3_DATA_MAGIC):
bp->b_ops = &xfs_dir3_data_buf_ops;
bp->b_ops->verify_read(bp);
return;
default:
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
break;
}
}
static void
xfs_dir3_data_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb) &&
!xfs_buf_verify_cksum(bp, XFS_DIR3_DATA_CRC_OFF))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (!xfs_dir3_data_verify(bp))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
xfs_dir3_data_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
if (!xfs_dir3_data_verify(bp)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
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
xfs_dir3_data_read(
struct xfs_trans *tp,
struct xfs_inode *dp,
xfs_dablk_t bno,
xfs_daddr_t mapped_bno,
struct xfs_buf **bpp)
{
int err;
err = xfs_da_read_buf(tp, dp, bno, mapped_bno, bpp,
XFS_DATA_FORK, &xfs_dir3_data_buf_ops);
if (!err && tp)
xfs_trans_buf_set_type(tp, *bpp, XFS_BLFT_DIR_DATA_BUF);
return err;
}
int
xfs_dir3_data_readahead(
struct xfs_inode *dp,
xfs_dablk_t bno,
xfs_daddr_t mapped_bno)
{
return xfs_da_reada_buf(dp, bno, mapped_bno,
XFS_DATA_FORK, &xfs_dir3_data_reada_buf_ops);
}
xfs_dir2_data_free_t *
xfs_dir2_data_freefind(
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_data_free *bf,
struct xfs_dir2_data_unused *dup)
{
xfs_dir2_data_free_t *dfp;
xfs_dir2_data_aoff_t off;
#ifdef DEBUG
int matched;
int seenzero;
#endif
off = (xfs_dir2_data_aoff_t)((char *)dup - (char *)hdr);
#ifdef DEBUG
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
for (dfp = &bf[0], seenzero = matched = 0;
dfp < &bf[XFS_DIR2_DATA_FD_COUNT];
dfp++) {
if (!dfp->offset) {
ASSERT(!dfp->length);
seenzero = 1;
continue;
}
ASSERT(seenzero == 0);
if (be16_to_cpu(dfp->offset) == off) {
matched = 1;
ASSERT(dfp->length == dup->length);
} else if (off < be16_to_cpu(dfp->offset))
ASSERT(off + be16_to_cpu(dup->length) <= be16_to_cpu(dfp->offset));
else
ASSERT(be16_to_cpu(dfp->offset) + be16_to_cpu(dfp->length) <= off);
ASSERT(matched || be16_to_cpu(dfp->length) >= be16_to_cpu(dup->length));
if (dfp > &bf[0])
ASSERT(be16_to_cpu(dfp[-1].length) >= be16_to_cpu(dfp[0].length));
}
#endif
if (be16_to_cpu(dup->length) <
be16_to_cpu(bf[XFS_DIR2_DATA_FD_COUNT - 1].length))
return NULL;
for (dfp = &bf[0]; dfp < &bf[XFS_DIR2_DATA_FD_COUNT]; dfp++) {
if (!dfp->offset)
return NULL;
if (be16_to_cpu(dfp->offset) == off)
return dfp;
}
return NULL;
}
xfs_dir2_data_free_t *
xfs_dir2_data_freeinsert(
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_data_free *dfp,
struct xfs_dir2_data_unused *dup,
int *loghead)
{
xfs_dir2_data_free_t new;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
new.length = dup->length;
new.offset = cpu_to_be16((char *)dup - (char *)hdr);
if (be16_to_cpu(new.length) > be16_to_cpu(dfp[0].length)) {
dfp[2] = dfp[1];
dfp[1] = dfp[0];
dfp[0] = new;
*loghead = 1;
return &dfp[0];
}
if (be16_to_cpu(new.length) > be16_to_cpu(dfp[1].length)) {
dfp[2] = dfp[1];
dfp[1] = new;
*loghead = 1;
return &dfp[1];
}
if (be16_to_cpu(new.length) > be16_to_cpu(dfp[2].length)) {
dfp[2] = new;
*loghead = 1;
return &dfp[2];
}
return NULL;
}
STATIC void
xfs_dir2_data_freeremove(
struct xfs_dir2_data_hdr *hdr,
struct xfs_dir2_data_free *bf,
struct xfs_dir2_data_free *dfp,
int *loghead)
{
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
if (dfp == &bf[0]) {
bf[0] = bf[1];
bf[1] = bf[2];
}
else if (dfp == &bf[1])
bf[1] = bf[2];
else
ASSERT(dfp == &bf[2]);
bf[2].length = 0;
bf[2].offset = 0;
*loghead = 1;
}
void
xfs_dir2_data_freescan(
struct xfs_inode *dp,
struct xfs_dir2_data_hdr *hdr,
int *loghead)
{
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_unused_t *dup;
struct xfs_dir2_data_free *bf;
char *endp;
char *p;
struct xfs_da_geometry *geo = dp->i_mount->m_dir_geo;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
bf = dp->d_ops->data_bestfree_p(hdr);
memset(bf, 0, sizeof(*bf) * XFS_DIR2_DATA_FD_COUNT);
*loghead = 1;
p = (char *)dp->d_ops->data_entry_p(hdr);
if (hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC)) {
btp = xfs_dir2_block_tail_p(geo, hdr);
endp = (char *)xfs_dir2_block_leaf_p(btp);
} else
endp = (char *)hdr + geo->blksize;
while (p < endp) {
dup = (xfs_dir2_data_unused_t *)p;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
ASSERT((char *)dup - (char *)hdr ==
be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)));
xfs_dir2_data_freeinsert(hdr, bf, dup, loghead);
p += be16_to_cpu(dup->length);
}
else {
dep = (xfs_dir2_data_entry_t *)p;
ASSERT((char *)dep - (char *)hdr ==
be16_to_cpu(*dp->d_ops->data_entry_tag_p(dep)));
p += dp->d_ops->data_entsize(dep->namelen);
}
}
}
int
xfs_dir3_data_init(
xfs_da_args_t *args,
xfs_dir2_db_t blkno,
struct xfs_buf **bpp)
{
struct xfs_buf *bp;
xfs_dir2_data_hdr_t *hdr;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
struct xfs_dir2_data_free *bf;
int error;
int i;
xfs_mount_t *mp;
xfs_trans_t *tp;
int t;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(args->geo, blkno),
-1, &bp, XFS_DATA_FORK);
if (error)
return error;
bp->b_ops = &xfs_dir3_data_buf_ops;
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DIR_DATA_BUF);
hdr = bp->b_addr;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
struct xfs_dir3_blk_hdr *hdr3 = bp->b_addr;
memset(hdr3, 0, sizeof(*hdr3));
hdr3->magic = cpu_to_be32(XFS_DIR3_DATA_MAGIC);
hdr3->blkno = cpu_to_be64(bp->b_bn);
hdr3->owner = cpu_to_be64(dp->i_ino);
uuid_copy(&hdr3->uuid, &mp->m_sb.sb_meta_uuid);
} else
hdr->magic = cpu_to_be32(XFS_DIR2_DATA_MAGIC);
bf = dp->d_ops->data_bestfree_p(hdr);
bf[0].offset = cpu_to_be16(dp->d_ops->data_entry_offset);
for (i = 1; i < XFS_DIR2_DATA_FD_COUNT; i++) {
bf[i].length = 0;
bf[i].offset = 0;
}
dup = dp->d_ops->data_unused_p(hdr);
dup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
t = args->geo->blksize - (uint)dp->d_ops->data_entry_offset;
bf[0].length = cpu_to_be16(t);
dup->length = cpu_to_be16(t);
*xfs_dir2_data_unused_tag_p(dup) = cpu_to_be16((char *)dup - (char *)hdr);
xfs_dir2_data_log_header(args, bp);
xfs_dir2_data_log_unused(args, bp, dup);
*bpp = bp;
return 0;
}
void
xfs_dir2_data_log_entry(
struct xfs_da_args *args,
struct xfs_buf *bp,
xfs_dir2_data_entry_t *dep)
{
struct xfs_dir2_data_hdr *hdr = bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
xfs_trans_log_buf(args->trans, bp, (uint)((char *)dep - (char *)hdr),
(uint)((char *)(args->dp->d_ops->data_entry_tag_p(dep) + 1) -
(char *)hdr - 1));
}
void
xfs_dir2_data_log_header(
struct xfs_da_args *args,
struct xfs_buf *bp)
{
#ifdef DEBUG
struct xfs_dir2_data_hdr *hdr = bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
#endif
xfs_trans_log_buf(args->trans, bp, 0,
args->dp->d_ops->data_entry_offset - 1);
}
void
xfs_dir2_data_log_unused(
struct xfs_da_args *args,
struct xfs_buf *bp,
xfs_dir2_data_unused_t *dup)
{
xfs_dir2_data_hdr_t *hdr = bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
xfs_trans_log_buf(args->trans, bp, (uint)((char *)dup - (char *)hdr),
(uint)((char *)&dup->length + sizeof(dup->length) -
1 - (char *)hdr));
xfs_trans_log_buf(args->trans, bp,
(uint)((char *)xfs_dir2_data_unused_tag_p(dup) - (char *)hdr),
(uint)((char *)xfs_dir2_data_unused_tag_p(dup) - (char *)hdr +
sizeof(xfs_dir2_data_off_t) - 1));
}
void
xfs_dir2_data_make_free(
struct xfs_da_args *args,
struct xfs_buf *bp,
xfs_dir2_data_aoff_t offset,
xfs_dir2_data_aoff_t len,
int *needlogp,
int *needscanp)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_data_free_t *dfp;
char *endptr;
int needscan;
xfs_dir2_data_unused_t *newdup;
xfs_dir2_data_unused_t *postdup;
xfs_dir2_data_unused_t *prevdup;
struct xfs_dir2_data_free *bf;
hdr = bp->b_addr;
if (hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC))
endptr = (char *)hdr + args->geo->blksize;
else {
xfs_dir2_block_tail_t *btp;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
btp = xfs_dir2_block_tail_p(args->geo, hdr);
endptr = (char *)xfs_dir2_block_leaf_p(btp);
}
if (offset > args->dp->d_ops->data_entry_offset) {
__be16 *tagp;
tagp = (__be16 *)((char *)hdr + offset) - 1;
prevdup = (xfs_dir2_data_unused_t *)((char *)hdr + be16_to_cpu(*tagp));
if (be16_to_cpu(prevdup->freetag) != XFS_DIR2_DATA_FREE_TAG)
prevdup = NULL;
} else
prevdup = NULL;
if ((char *)hdr + offset + len < endptr) {
postdup =
(xfs_dir2_data_unused_t *)((char *)hdr + offset + len);
if (be16_to_cpu(postdup->freetag) != XFS_DIR2_DATA_FREE_TAG)
postdup = NULL;
} else
postdup = NULL;
ASSERT(*needscanp == 0);
needscan = 0;
bf = args->dp->d_ops->data_bestfree_p(hdr);
if (prevdup && postdup) {
xfs_dir2_data_free_t *dfp2;
dfp = xfs_dir2_data_freefind(hdr, bf, prevdup);
dfp2 = xfs_dir2_data_freefind(hdr, bf, postdup);
needscan = (bf[2].length != 0);
be16_add_cpu(&prevdup->length, len + be16_to_cpu(postdup->length));
*xfs_dir2_data_unused_tag_p(prevdup) =
cpu_to_be16((char *)prevdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, prevdup);
if (!needscan) {
ASSERT(dfp && dfp2);
if (dfp == &bf[1]) {
dfp = &bf[0];
ASSERT(dfp2 == dfp);
dfp2 = &bf[1];
}
xfs_dir2_data_freeremove(hdr, bf, dfp2, needlogp);
xfs_dir2_data_freeremove(hdr, bf, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(hdr, bf, prevdup,
needlogp);
ASSERT(dfp == &bf[0]);
ASSERT(dfp->length == prevdup->length);
ASSERT(!dfp[1].length);
ASSERT(!dfp[2].length);
}
}
else if (prevdup) {
dfp = xfs_dir2_data_freefind(hdr, bf, prevdup);
be16_add_cpu(&prevdup->length, len);
*xfs_dir2_data_unused_tag_p(prevdup) =
cpu_to_be16((char *)prevdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, prevdup);
if (dfp) {
xfs_dir2_data_freeremove(hdr, bf, dfp, needlogp);
xfs_dir2_data_freeinsert(hdr, bf, prevdup, needlogp);
}
else {
needscan = be16_to_cpu(prevdup->length) >
be16_to_cpu(bf[2].length);
}
}
else if (postdup) {
dfp = xfs_dir2_data_freefind(hdr, bf, postdup);
newdup = (xfs_dir2_data_unused_t *)((char *)hdr + offset);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(len + be16_to_cpu(postdup->length));
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(hdr, bf, dfp, needlogp);
xfs_dir2_data_freeinsert(hdr, bf, newdup, needlogp);
}
else {
needscan = be16_to_cpu(newdup->length) >
be16_to_cpu(bf[2].length);
}
}
else {
newdup = (xfs_dir2_data_unused_t *)((char *)hdr + offset);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(len);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup);
xfs_dir2_data_freeinsert(hdr, bf, newdup, needlogp);
}
*needscanp = needscan;
}
void
xfs_dir2_data_use_free(
struct xfs_da_args *args,
struct xfs_buf *bp,
xfs_dir2_data_unused_t *dup,
xfs_dir2_data_aoff_t offset,
xfs_dir2_data_aoff_t len,
int *needlogp,
int *needscanp)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_data_free_t *dfp;
int matchback;
int matchfront;
int needscan;
xfs_dir2_data_unused_t *newdup;
xfs_dir2_data_unused_t *newdup2;
int oldlen;
struct xfs_dir2_data_free *bf;
hdr = bp->b_addr;
ASSERT(hdr->magic == cpu_to_be32(XFS_DIR2_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_DATA_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR2_BLOCK_MAGIC) ||
hdr->magic == cpu_to_be32(XFS_DIR3_BLOCK_MAGIC));
ASSERT(be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG);
ASSERT(offset >= (char *)dup - (char *)hdr);
ASSERT(offset + len <= (char *)dup + be16_to_cpu(dup->length) - (char *)hdr);
ASSERT((char *)dup - (char *)hdr == be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)));
oldlen = be16_to_cpu(dup->length);
bf = args->dp->d_ops->data_bestfree_p(hdr);
dfp = xfs_dir2_data_freefind(hdr, bf, dup);
ASSERT(dfp || oldlen <= be16_to_cpu(bf[2].length));
matchfront = (char *)dup - (char *)hdr == offset;
matchback = (char *)dup + oldlen - (char *)hdr == offset + len;
ASSERT(*needscanp == 0);
needscan = 0;
if (matchfront && matchback) {
if (dfp) {
needscan = (bf[2].offset != 0);
if (!needscan)
xfs_dir2_data_freeremove(hdr, bf, dfp,
needlogp);
}
}
else if (matchfront) {
newdup = (xfs_dir2_data_unused_t *)((char *)hdr + offset + len);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(oldlen - len);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(hdr, bf, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(hdr, bf, newdup,
needlogp);
ASSERT(dfp != NULL);
ASSERT(dfp->length == newdup->length);
ASSERT(be16_to_cpu(dfp->offset) == (char *)newdup - (char *)hdr);
needscan = dfp == &bf[2];
}
}
else if (matchback) {
newdup = dup;
newdup->length = cpu_to_be16(((char *)hdr + offset) - (char *)newdup);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(hdr, bf, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(hdr, bf, newdup,
needlogp);
ASSERT(dfp != NULL);
ASSERT(dfp->length == newdup->length);
ASSERT(be16_to_cpu(dfp->offset) == (char *)newdup - (char *)hdr);
needscan = dfp == &bf[2];
}
}
else {
newdup = dup;
newdup->length = cpu_to_be16(((char *)hdr + offset) - (char *)newdup);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup);
newdup2 = (xfs_dir2_data_unused_t *)((char *)hdr + offset + len);
newdup2->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup2->length = cpu_to_be16(oldlen - len - be16_to_cpu(newdup->length));
*xfs_dir2_data_unused_tag_p(newdup2) =
cpu_to_be16((char *)newdup2 - (char *)hdr);
xfs_dir2_data_log_unused(args, bp, newdup2);
if (dfp) {
needscan = (bf[2].length != 0);
if (!needscan) {
xfs_dir2_data_freeremove(hdr, bf, dfp,
needlogp);
xfs_dir2_data_freeinsert(hdr, bf, newdup,
needlogp);
xfs_dir2_data_freeinsert(hdr, bf, newdup2,
needlogp);
}
}
}
*needscanp = needscan;
}
