void
xfs_dir2_data_check(
xfs_inode_t *dp,
xfs_dabuf_t *bp)
{
xfs_dir2_dataptr_t addr;
xfs_dir2_data_free_t *bf;
xfs_dir2_block_tail_t *btp=NULL;
int count;
xfs_dir2_data_t *d;
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
mp = dp->i_mount;
d = bp->data;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
bf = d->hdr.bestfree;
p = (char *)d->u;
if (be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC) {
btp = xfs_dir2_block_tail_p(mp, (xfs_dir2_block_t *)d);
lep = xfs_dir2_block_leaf_p(btp);
endp = (char *)lep;
} else
endp = (char *)d + mp->m_dirblksize;
count = lastfree = freeseen = 0;
if (!bf[0].length) {
ASSERT(!bf[0].offset);
freeseen |= 1 << 0;
}
if (!bf[1].length) {
ASSERT(!bf[1].offset);
freeseen |= 1 << 1;
}
if (!bf[2].length) {
ASSERT(!bf[2].offset);
freeseen |= 1 << 2;
}
ASSERT(be16_to_cpu(bf[0].length) >= be16_to_cpu(bf[1].length));
ASSERT(be16_to_cpu(bf[1].length) >= be16_to_cpu(bf[2].length));
while (p < endp) {
dup = (xfs_dir2_data_unused_t *)p;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
ASSERT(lastfree == 0);
ASSERT(be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)) ==
(char *)dup - (char *)d);
dfp = xfs_dir2_data_freefind(d, dup);
if (dfp) {
i = (int)(dfp - bf);
ASSERT((freeseen & (1 << i)) == 0);
freeseen |= 1 << i;
} else {
ASSERT(be16_to_cpu(dup->length) <=
be16_to_cpu(bf[2].length));
}
p += be16_to_cpu(dup->length);
lastfree = 1;
continue;
}
dep = (xfs_dir2_data_entry_t *)p;
ASSERT(dep->namelen != 0);
ASSERT(xfs_dir_ino_validate(mp, be64_to_cpu(dep->inumber)) == 0);
ASSERT(be16_to_cpu(*xfs_dir2_data_entry_tag_p(dep)) ==
(char *)dep - (char *)d);
count++;
lastfree = 0;
if (be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC) {
addr = xfs_dir2_db_off_to_dataptr(mp, mp->m_dirdatablk,
(xfs_dir2_data_aoff_t)
((char *)dep - (char *)d));
name.name = dep->name;
name.len = dep->namelen;
hash = mp->m_dirnameops->hashname(&name);
for (i = 0; i < be32_to_cpu(btp->count); i++) {
if (be32_to_cpu(lep[i].address) == addr &&
be32_to_cpu(lep[i].hashval) == hash)
break;
}
ASSERT(i < be32_to_cpu(btp->count));
}
p += xfs_dir2_data_entsize(dep->namelen);
}
ASSERT(freeseen == 7);
if (be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC) {
for (i = stale = 0; i < be32_to_cpu(btp->count); i++) {
if (be32_to_cpu(lep[i].address) == XFS_DIR2_NULL_DATAPTR)
stale++;
if (i > 0)
ASSERT(be32_to_cpu(lep[i].hashval) >= be32_to_cpu(lep[i - 1].hashval));
}
ASSERT(count == be32_to_cpu(btp->count) - be32_to_cpu(btp->stale));
ASSERT(stale == be32_to_cpu(btp->stale));
}
}
xfs_dir2_data_free_t *
xfs_dir2_data_freefind(
xfs_dir2_data_t *d,
xfs_dir2_data_unused_t *dup)
{
xfs_dir2_data_free_t *dfp;
xfs_dir2_data_aoff_t off;
#if defined(DEBUG) && defined(__KERNEL__)
int matched;
int seenzero;
#endif
off = (xfs_dir2_data_aoff_t)((char *)dup - (char *)d);
#if defined(DEBUG) && defined(__KERNEL__)
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
for (dfp = &d->hdr.bestfree[0], seenzero = matched = 0;
dfp < &d->hdr.bestfree[XFS_DIR2_DATA_FD_COUNT];
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
if (dfp > &d->hdr.bestfree[0])
ASSERT(be16_to_cpu(dfp[-1].length) >= be16_to_cpu(dfp[0].length));
}
#endif
if (be16_to_cpu(dup->length) <
be16_to_cpu(d->hdr.bestfree[XFS_DIR2_DATA_FD_COUNT - 1].length))
return NULL;
for (dfp = &d->hdr.bestfree[0];
dfp < &d->hdr.bestfree[XFS_DIR2_DATA_FD_COUNT];
dfp++) {
if (!dfp->offset)
return NULL;
if (be16_to_cpu(dfp->offset) == off)
return dfp;
}
return NULL;
}
xfs_dir2_data_free_t *
xfs_dir2_data_freeinsert(
xfs_dir2_data_t *d,
xfs_dir2_data_unused_t *dup,
int *loghead)
{
xfs_dir2_data_free_t *dfp;
xfs_dir2_data_free_t new;
#ifdef __KERNEL__
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
#endif
dfp = d->hdr.bestfree;
new.length = dup->length;
new.offset = cpu_to_be16((char *)dup - (char *)d);
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
xfs_dir2_data_t *d,
xfs_dir2_data_free_t *dfp,
int *loghead)
{
#ifdef __KERNEL__
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
#endif
if (dfp == &d->hdr.bestfree[0]) {
d->hdr.bestfree[0] = d->hdr.bestfree[1];
d->hdr.bestfree[1] = d->hdr.bestfree[2];
}
else if (dfp == &d->hdr.bestfree[1])
d->hdr.bestfree[1] = d->hdr.bestfree[2];
else
ASSERT(dfp == &d->hdr.bestfree[2]);
d->hdr.bestfree[2].length = 0;
d->hdr.bestfree[2].offset = 0;
*loghead = 1;
}
void
xfs_dir2_data_freescan(
xfs_mount_t *mp,
xfs_dir2_data_t *d,
int *loghead)
{
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_unused_t *dup;
char *endp;
char *p;
#ifdef __KERNEL__
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
#endif
memset(d->hdr.bestfree, 0, sizeof(d->hdr.bestfree));
*loghead = 1;
p = (char *)d->u;
if (be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC) {
btp = xfs_dir2_block_tail_p(mp, (xfs_dir2_block_t *)d);
endp = (char *)xfs_dir2_block_leaf_p(btp);
} else
endp = (char *)d + mp->m_dirblksize;
while (p < endp) {
dup = (xfs_dir2_data_unused_t *)p;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
ASSERT((char *)dup - (char *)d ==
be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)));
xfs_dir2_data_freeinsert(d, dup, loghead);
p += be16_to_cpu(dup->length);
}
else {
dep = (xfs_dir2_data_entry_t *)p;
ASSERT((char *)dep - (char *)d ==
be16_to_cpu(*xfs_dir2_data_entry_tag_p(dep)));
p += xfs_dir2_data_entsize(dep->namelen);
}
}
}
int
xfs_dir2_data_init(
xfs_da_args_t *args,
xfs_dir2_db_t blkno,
xfs_dabuf_t **bpp)
{
xfs_dabuf_t *bp;
xfs_dir2_data_t *d;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
int i;
xfs_mount_t *mp;
xfs_trans_t *tp;
int t;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(mp, blkno), -1, &bp,
XFS_DATA_FORK);
if (error) {
return error;
}
ASSERT(bp != NULL);
d = bp->data;
d->hdr.magic = cpu_to_be32(XFS_DIR2_DATA_MAGIC);
d->hdr.bestfree[0].offset = cpu_to_be16(sizeof(d->hdr));
for (i = 1; i < XFS_DIR2_DATA_FD_COUNT; i++) {
d->hdr.bestfree[i].length = 0;
d->hdr.bestfree[i].offset = 0;
}
dup = &d->u[0].unused;
dup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
t=mp->m_dirblksize - (uint)sizeof(d->hdr);
d->hdr.bestfree[0].length = cpu_to_be16(t);
dup->length = cpu_to_be16(t);
*xfs_dir2_data_unused_tag_p(dup) = cpu_to_be16((char *)dup - (char *)d);
xfs_dir2_data_log_header(tp, bp);
xfs_dir2_data_log_unused(tp, bp, dup);
*bpp = bp;
return 0;
}
void
xfs_dir2_data_log_entry(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
xfs_dir2_data_entry_t *dep)
{
xfs_dir2_data_t *d;
d = bp->data;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
xfs_da_log_buf(tp, bp, (uint)((char *)dep - (char *)d),
(uint)((char *)(xfs_dir2_data_entry_tag_p(dep) + 1) -
(char *)d - 1));
}
void
xfs_dir2_data_log_header(
xfs_trans_t *tp,
xfs_dabuf_t *bp)
{
xfs_dir2_data_t *d;
d = bp->data;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
xfs_da_log_buf(tp, bp, (uint)((char *)&d->hdr - (char *)d),
(uint)(sizeof(d->hdr) - 1));
}
void
xfs_dir2_data_log_unused(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
xfs_dir2_data_unused_t *dup)
{
xfs_dir2_data_t *d;
d = bp->data;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
xfs_da_log_buf(tp, bp, (uint)((char *)dup - (char *)d),
(uint)((char *)&dup->length + sizeof(dup->length) -
1 - (char *)d));
xfs_da_log_buf(tp, bp,
(uint)((char *)xfs_dir2_data_unused_tag_p(dup) - (char *)d),
(uint)((char *)xfs_dir2_data_unused_tag_p(dup) - (char *)d +
sizeof(xfs_dir2_data_off_t) - 1));
}
void
xfs_dir2_data_make_free(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
xfs_dir2_data_aoff_t offset,
xfs_dir2_data_aoff_t len,
int *needlogp,
int *needscanp)
{
xfs_dir2_data_t *d;
xfs_dir2_data_free_t *dfp;
char *endptr;
xfs_mount_t *mp;
int needscan;
xfs_dir2_data_unused_t *newdup;
xfs_dir2_data_unused_t *postdup;
xfs_dir2_data_unused_t *prevdup;
mp = tp->t_mountp;
d = bp->data;
if (be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC)
endptr = (char *)d + mp->m_dirblksize;
else {
xfs_dir2_block_tail_t *btp;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
btp = xfs_dir2_block_tail_p(mp, (xfs_dir2_block_t *)d);
endptr = (char *)xfs_dir2_block_leaf_p(btp);
}
if (offset > sizeof(d->hdr)) {
__be16 *tagp;
tagp = (__be16 *)((char *)d + offset) - 1;
prevdup = (xfs_dir2_data_unused_t *)((char *)d + be16_to_cpu(*tagp));
if (be16_to_cpu(prevdup->freetag) != XFS_DIR2_DATA_FREE_TAG)
prevdup = NULL;
} else
prevdup = NULL;
if ((char *)d + offset + len < endptr) {
postdup =
(xfs_dir2_data_unused_t *)((char *)d + offset + len);
if (be16_to_cpu(postdup->freetag) != XFS_DIR2_DATA_FREE_TAG)
postdup = NULL;
} else
postdup = NULL;
ASSERT(*needscanp == 0);
needscan = 0;
if (prevdup && postdup) {
xfs_dir2_data_free_t *dfp2;
dfp = xfs_dir2_data_freefind(d, prevdup);
dfp2 = xfs_dir2_data_freefind(d, postdup);
needscan = (d->hdr.bestfree[2].length != 0);
be16_add_cpu(&prevdup->length, len + be16_to_cpu(postdup->length));
*xfs_dir2_data_unused_tag_p(prevdup) =
cpu_to_be16((char *)prevdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, prevdup);
if (!needscan) {
ASSERT(dfp && dfp2);
if (dfp == &d->hdr.bestfree[1]) {
dfp = &d->hdr.bestfree[0];
ASSERT(dfp2 == dfp);
dfp2 = &d->hdr.bestfree[1];
}
xfs_dir2_data_freeremove(d, dfp2, needlogp);
xfs_dir2_data_freeremove(d, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(d, prevdup, needlogp);
ASSERT(dfp == &d->hdr.bestfree[0]);
ASSERT(dfp->length == prevdup->length);
ASSERT(!dfp[1].length);
ASSERT(!dfp[2].length);
}
}
else if (prevdup) {
dfp = xfs_dir2_data_freefind(d, prevdup);
be16_add_cpu(&prevdup->length, len);
*xfs_dir2_data_unused_tag_p(prevdup) =
cpu_to_be16((char *)prevdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, prevdup);
if (dfp) {
xfs_dir2_data_freeremove(d, dfp, needlogp);
(void)xfs_dir2_data_freeinsert(d, prevdup, needlogp);
}
else {
needscan = be16_to_cpu(prevdup->length) >
be16_to_cpu(d->hdr.bestfree[2].length);
}
}
else if (postdup) {
dfp = xfs_dir2_data_freefind(d, postdup);
newdup = (xfs_dir2_data_unused_t *)((char *)d + offset);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(len + be16_to_cpu(postdup->length));
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(d, dfp, needlogp);
(void)xfs_dir2_data_freeinsert(d, newdup, needlogp);
}
else {
needscan = be16_to_cpu(newdup->length) >
be16_to_cpu(d->hdr.bestfree[2].length);
}
}
else {
newdup = (xfs_dir2_data_unused_t *)((char *)d + offset);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(len);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup);
(void)xfs_dir2_data_freeinsert(d, newdup, needlogp);
}
*needscanp = needscan;
}
void
xfs_dir2_data_use_free(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
xfs_dir2_data_unused_t *dup,
xfs_dir2_data_aoff_t offset,
xfs_dir2_data_aoff_t len,
int *needlogp,
int *needscanp)
{
xfs_dir2_data_t *d;
xfs_dir2_data_free_t *dfp;
int matchback;
int matchfront;
int needscan;
xfs_dir2_data_unused_t *newdup;
xfs_dir2_data_unused_t *newdup2;
int oldlen;
d = bp->data;
ASSERT(be32_to_cpu(d->hdr.magic) == XFS_DIR2_DATA_MAGIC ||
be32_to_cpu(d->hdr.magic) == XFS_DIR2_BLOCK_MAGIC);
ASSERT(be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG);
ASSERT(offset >= (char *)dup - (char *)d);
ASSERT(offset + len <= (char *)dup + be16_to_cpu(dup->length) - (char *)d);
ASSERT((char *)dup - (char *)d == be16_to_cpu(*xfs_dir2_data_unused_tag_p(dup)));
dfp = xfs_dir2_data_freefind(d, dup);
oldlen = be16_to_cpu(dup->length);
ASSERT(dfp || oldlen <= be16_to_cpu(d->hdr.bestfree[2].length));
matchfront = (char *)dup - (char *)d == offset;
matchback = (char *)dup + oldlen - (char *)d == offset + len;
ASSERT(*needscanp == 0);
needscan = 0;
if (matchfront && matchback) {
if (dfp) {
needscan = (d->hdr.bestfree[2].offset != 0);
if (!needscan)
xfs_dir2_data_freeremove(d, dfp, needlogp);
}
}
else if (matchfront) {
newdup = (xfs_dir2_data_unused_t *)((char *)d + offset + len);
newdup->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup->length = cpu_to_be16(oldlen - len);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(d, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(d, newdup, needlogp);
ASSERT(dfp != NULL);
ASSERT(dfp->length == newdup->length);
ASSERT(be16_to_cpu(dfp->offset) == (char *)newdup - (char *)d);
needscan = dfp == &d->hdr.bestfree[2];
}
}
else if (matchback) {
newdup = dup;
newdup->length = cpu_to_be16(((char *)d + offset) - (char *)newdup);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup);
if (dfp) {
xfs_dir2_data_freeremove(d, dfp, needlogp);
dfp = xfs_dir2_data_freeinsert(d, newdup, needlogp);
ASSERT(dfp != NULL);
ASSERT(dfp->length == newdup->length);
ASSERT(be16_to_cpu(dfp->offset) == (char *)newdup - (char *)d);
needscan = dfp == &d->hdr.bestfree[2];
}
}
else {
newdup = dup;
newdup->length = cpu_to_be16(((char *)d + offset) - (char *)newdup);
*xfs_dir2_data_unused_tag_p(newdup) =
cpu_to_be16((char *)newdup - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup);
newdup2 = (xfs_dir2_data_unused_t *)((char *)d + offset + len);
newdup2->freetag = cpu_to_be16(XFS_DIR2_DATA_FREE_TAG);
newdup2->length = cpu_to_be16(oldlen - len - be16_to_cpu(newdup->length));
*xfs_dir2_data_unused_tag_p(newdup2) =
cpu_to_be16((char *)newdup2 - (char *)d);
xfs_dir2_data_log_unused(tp, bp, newdup2);
if (dfp) {
needscan = (d->hdr.bestfree[2].length != 0);
if (!needscan) {
xfs_dir2_data_freeremove(d, dfp, needlogp);
(void)xfs_dir2_data_freeinsert(d, newdup,
needlogp);
(void)xfs_dir2_data_freeinsert(d, newdup2,
needlogp);
}
}
}
*needscanp = needscan;
}
