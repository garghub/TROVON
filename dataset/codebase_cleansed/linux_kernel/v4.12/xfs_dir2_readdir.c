static unsigned char
xfs_dir3_get_dtype(
struct xfs_mount *mp,
__uint8_t filetype)
{
if (!xfs_sb_version_hasftype(&mp->m_sb))
return DT_UNKNOWN;
if (filetype >= XFS_DIR3_FT_MAX)
return DT_UNKNOWN;
return xfs_dir3_filetype_table[filetype];
}
STATIC int
xfs_dir2_sf_getdents(
struct xfs_da_args *args,
struct dir_context *ctx)
{
int i;
struct xfs_inode *dp = args->dp;
xfs_dir2_dataptr_t off;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
xfs_dir2_dataptr_t dot_offset;
xfs_dir2_dataptr_t dotdot_offset;
xfs_ino_t ino;
struct xfs_da_geometry *geo = args->geo;
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
ASSERT(dp->i_df.if_bytes == dp->i_d.di_size);
ASSERT(dp->i_df.if_u1.if_data != NULL);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
if (xfs_dir2_dataptr_to_db(geo, ctx->pos) > geo->datablk)
return 0;
dot_offset = xfs_dir2_db_off_to_dataptr(geo, geo->datablk,
dp->d_ops->data_dot_offset);
dotdot_offset = xfs_dir2_db_off_to_dataptr(geo, geo->datablk,
dp->d_ops->data_dotdot_offset);
if (ctx->pos <= dot_offset) {
ctx->pos = dot_offset & 0x7fffffff;
if (!dir_emit(ctx, ".", 1, dp->i_ino, DT_DIR))
return 0;
}
if (ctx->pos <= dotdot_offset) {
ino = dp->d_ops->sf_get_parent_ino(sfp);
ctx->pos = dotdot_offset & 0x7fffffff;
if (!dir_emit(ctx, "..", 2, ino, DT_DIR))
return 0;
}
sfep = xfs_dir2_sf_firstentry(sfp);
for (i = 0; i < sfp->count; i++) {
__uint8_t filetype;
off = xfs_dir2_db_off_to_dataptr(geo, geo->datablk,
xfs_dir2_sf_get_offset(sfep));
if (ctx->pos > off) {
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
continue;
}
ino = dp->d_ops->sf_get_ino(sfp, sfep);
filetype = dp->d_ops->sf_get_ftype(sfep);
ctx->pos = off & 0x7fffffff;
if (!dir_emit(ctx, (char *)sfep->name, sfep->namelen, ino,
xfs_dir3_get_dtype(dp->i_mount, filetype)))
return 0;
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
}
ctx->pos = xfs_dir2_db_off_to_dataptr(geo, geo->datablk + 1, 0) &
0x7fffffff;
return 0;
}
STATIC int
xfs_dir2_block_getdents(
struct xfs_da_args *args,
struct dir_context *ctx)
{
struct xfs_inode *dp = args->dp;
xfs_dir2_data_hdr_t *hdr;
struct xfs_buf *bp;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_unused_t *dup;
char *endptr;
int error;
char *ptr;
int wantoff;
xfs_off_t cook;
struct xfs_da_geometry *geo = args->geo;
int lock_mode;
if (xfs_dir2_dataptr_to_db(geo, ctx->pos) > geo->datablk)
return 0;
lock_mode = xfs_ilock_data_map_shared(dp);
error = xfs_dir3_block_read(NULL, dp, &bp);
xfs_iunlock(dp, lock_mode);
if (error)
return error;
wantoff = xfs_dir2_dataptr_to_off(geo, ctx->pos);
hdr = bp->b_addr;
xfs_dir3_data_check(dp, bp);
btp = xfs_dir2_block_tail_p(geo, hdr);
ptr = (char *)dp->d_ops->data_entry_p(hdr);
endptr = (char *)xfs_dir2_block_leaf_p(btp);
while (ptr < endptr) {
__uint8_t filetype;
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
ptr += be16_to_cpu(dup->length);
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
ptr += dp->d_ops->data_entsize(dep->namelen);
if ((char *)dep - (char *)hdr < wantoff)
continue;
cook = xfs_dir2_db_off_to_dataptr(geo, geo->datablk,
(char *)dep - (char *)hdr);
ctx->pos = cook & 0x7fffffff;
filetype = dp->d_ops->data_get_ftype(dep);
if (!dir_emit(ctx, (char *)dep->name, dep->namelen,
be64_to_cpu(dep->inumber),
xfs_dir3_get_dtype(dp->i_mount, filetype))) {
xfs_trans_brelse(NULL, bp);
return 0;
}
}
ctx->pos = xfs_dir2_db_off_to_dataptr(geo, geo->datablk + 1, 0) &
0x7fffffff;
xfs_trans_brelse(NULL, bp);
return 0;
}
STATIC int
xfs_dir2_leaf_readbuf(
struct xfs_da_args *args,
size_t bufsize,
struct xfs_dir2_leaf_map_info *mip,
xfs_dir2_off_t *curoff,
struct xfs_buf **bpp,
bool trim_map)
{
struct xfs_inode *dp = args->dp;
struct xfs_buf *bp = NULL;
struct xfs_bmbt_irec *map = mip->map;
struct blk_plug plug;
int error = 0;
int length;
int i;
int j;
struct xfs_da_geometry *geo = args->geo;
if (trim_map) {
mip->map_blocks -= geo->fsbcount;
for (i = geo->fsbcount; i > 0; ) {
j = min_t(int, map->br_blockcount, i);
map->br_blockcount -= j;
map->br_startblock += j;
map->br_startoff += j;
if (!map->br_blockcount && --mip->map_valid)
memmove(&map[0], &map[1],
sizeof(map[0]) * mip->map_valid);
i -= j;
}
}
mip->ra_want = howmany(bufsize + geo->blksize, (1 << geo->fsblog)) - 1;
ASSERT(mip->ra_want >= 0);
if (1 + mip->ra_want > mip->map_blocks &&
mip->map_off < xfs_dir2_byte_to_da(geo, XFS_DIR2_LEAF_OFFSET)) {
mip->nmap = mip->map_size - mip->map_valid;
error = xfs_bmapi_read(dp, mip->map_off,
xfs_dir2_byte_to_da(geo, XFS_DIR2_LEAF_OFFSET) -
mip->map_off,
&map[mip->map_valid], &mip->nmap, 0);
if (error)
goto out;
if (mip->nmap == mip->map_size - mip->map_valid) {
i = mip->map_valid + mip->nmap - 1;
mip->map_off = map[i].br_startoff + map[i].br_blockcount;
} else
mip->map_off = xfs_dir2_byte_to_da(geo,
XFS_DIR2_LEAF_OFFSET);
for (i = mip->map_valid; i < mip->map_valid + mip->nmap; ) {
if (map[i].br_startblock == HOLESTARTBLOCK) {
mip->nmap--;
length = mip->map_valid + mip->nmap - i;
if (length)
memmove(&map[i], &map[i + 1],
sizeof(map[i]) * length);
} else {
mip->map_blocks += map[i].br_blockcount;
i++;
}
}
mip->map_valid += mip->nmap;
}
if (!mip->map_valid) {
*curoff = xfs_dir2_da_to_byte(geo, mip->map_off);
goto out;
}
mip->curdb = xfs_dir2_da_to_db(geo, map->br_startoff);
error = xfs_dir3_data_read(NULL, dp, map->br_startoff,
map->br_blockcount >= geo->fsbcount ?
XFS_FSB_TO_DADDR(dp->i_mount, map->br_startblock) :
-1, &bp);
if (error)
goto out;
if (mip->ra_current)
mip->ra_current -= geo->fsbcount;
blk_start_plug(&plug);
for (mip->ra_index = mip->ra_offset = i = 0;
mip->ra_want > mip->ra_current && i < mip->map_blocks;
i += geo->fsbcount) {
ASSERT(mip->ra_index < mip->map_valid);
if (i > mip->ra_current &&
(map[mip->ra_index].br_blockcount - mip->ra_offset) >=
geo->fsbcount) {
xfs_dir3_data_readahead(dp,
map[mip->ra_index].br_startoff + mip->ra_offset,
XFS_FSB_TO_DADDR(dp->i_mount,
map[mip->ra_index].br_startblock +
mip->ra_offset));
mip->ra_current = i;
}
else if (i > mip->ra_current) {
xfs_dir3_data_readahead(dp,
map[mip->ra_index].br_startoff +
mip->ra_offset, -1);
mip->ra_current = i;
}
for (j = 0;
j < geo->fsbcount && mip->ra_index < mip->map_valid;
j += length ) {
length = min_t(int, geo->fsbcount - j,
map[mip->ra_index].br_blockcount -
mip->ra_offset);
mip->ra_offset += length;
if (mip->ra_offset == map[mip->ra_index].br_blockcount) {
mip->ra_offset = 0;
mip->ra_index++;
}
}
}
blk_finish_plug(&plug);
out:
*bpp = bp;
return error;
}
STATIC int
xfs_dir2_leaf_getdents(
struct xfs_da_args *args,
struct dir_context *ctx,
size_t bufsize)
{
struct xfs_inode *dp = args->dp;
struct xfs_buf *bp = NULL;
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_unused_t *dup;
int error = 0;
int length;
int byteoff;
xfs_dir2_off_t curoff;
xfs_dir2_off_t newoff;
char *ptr = NULL;
struct xfs_dir2_leaf_map_info *map_info;
struct xfs_da_geometry *geo = args->geo;
if (ctx->pos >= XFS_DIR2_MAX_DATAPTR)
return 0;
length = howmany(bufsize + geo->blksize, (1 << geo->fsblog));
map_info = kmem_zalloc(offsetof(struct xfs_dir2_leaf_map_info, map) +
(length * sizeof(struct xfs_bmbt_irec)),
KM_SLEEP | KM_NOFS);
map_info->map_size = length;
curoff = xfs_dir2_dataptr_to_byte(ctx->pos);
map_info->map_off = xfs_dir2_db_to_da(geo,
xfs_dir2_byte_to_db(geo, curoff));
while (curoff < XFS_DIR2_LEAF_OFFSET) {
__uint8_t filetype;
if (!bp || ptr >= (char *)bp->b_addr + geo->blksize) {
int lock_mode;
bool trim_map = false;
if (bp) {
xfs_trans_brelse(NULL, bp);
bp = NULL;
trim_map = true;
}
lock_mode = xfs_ilock_data_map_shared(dp);
error = xfs_dir2_leaf_readbuf(args, bufsize, map_info,
&curoff, &bp, trim_map);
xfs_iunlock(dp, lock_mode);
if (error || !map_info->map_valid)
break;
newoff = xfs_dir2_db_off_to_byte(geo,
map_info->curdb, 0);
if (curoff < newoff)
curoff = newoff;
else if (curoff > newoff)
ASSERT(xfs_dir2_byte_to_db(geo, curoff) ==
map_info->curdb);
hdr = bp->b_addr;
xfs_dir3_data_check(dp, bp);
ptr = (char *)dp->d_ops->data_entry_p(hdr);
byteoff = xfs_dir2_byte_to_off(geo, curoff);
if (byteoff == 0)
curoff += dp->d_ops->data_entry_offset;
else {
while ((char *)ptr - (char *)hdr < byteoff) {
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag)
== XFS_DIR2_DATA_FREE_TAG) {
length = be16_to_cpu(dup->length);
ptr += length;
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
length =
dp->d_ops->data_entsize(dep->namelen);
ptr += length;
}
curoff =
xfs_dir2_db_off_to_byte(geo,
xfs_dir2_byte_to_db(geo, curoff),
(char *)ptr - (char *)hdr);
if (ptr >= (char *)hdr + geo->blksize) {
continue;
}
}
}
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
length = be16_to_cpu(dup->length);
ptr += length;
curoff += length;
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
length = dp->d_ops->data_entsize(dep->namelen);
filetype = dp->d_ops->data_get_ftype(dep);
ctx->pos = xfs_dir2_byte_to_dataptr(curoff) & 0x7fffffff;
if (!dir_emit(ctx, (char *)dep->name, dep->namelen,
be64_to_cpu(dep->inumber),
xfs_dir3_get_dtype(dp->i_mount, filetype)))
break;
ptr += length;
curoff += length;
bufsize = bufsize > length ? bufsize - length : 0;
}
if (curoff > xfs_dir2_dataptr_to_byte(XFS_DIR2_MAX_DATAPTR))
ctx->pos = XFS_DIR2_MAX_DATAPTR & 0x7fffffff;
else
ctx->pos = xfs_dir2_byte_to_dataptr(curoff) & 0x7fffffff;
kmem_free(map_info);
if (bp)
xfs_trans_brelse(NULL, bp);
return error;
}
int
xfs_readdir(
struct xfs_inode *dp,
struct dir_context *ctx,
size_t bufsize)
{
struct xfs_da_args args = { NULL };
int rval;
int v;
trace_xfs_readdir(dp);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return -EIO;
ASSERT(S_ISDIR(VFS_I(dp)->i_mode));
XFS_STATS_INC(dp->i_mount, xs_dir_getdents);
args.dp = dp;
args.geo = dp->i_mount->m_dir_geo;
if (dp->i_d.di_format == XFS_DINODE_FMT_LOCAL)
rval = xfs_dir2_sf_getdents(&args, ctx);
else if ((rval = xfs_dir2_isblock(&args, &v)))
;
else if (v)
rval = xfs_dir2_block_getdents(&args, ctx);
else
rval = xfs_dir2_leaf_getdents(&args, ctx, bufsize);
return rval;
}
