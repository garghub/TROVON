int
xfs_dir2_block_sfsize(
xfs_inode_t *dp,
xfs_dir2_data_hdr_t *hdr,
xfs_dir2_sf_hdr_t *sfhp)
{
xfs_dir2_dataptr_t addr;
xfs_dir2_leaf_entry_t *blp;
xfs_dir2_block_tail_t *btp;
int count;
xfs_dir2_data_entry_t *dep;
int i;
int i8count;
int isdot;
int isdotdot;
xfs_mount_t *mp;
int namelen;
xfs_ino_t parent = 0;
int size=0;
int has_ftype;
struct xfs_da_geometry *geo;
mp = dp->i_mount;
geo = mp->m_dir_geo;
has_ftype = xfs_sb_version_hasftype(&mp->m_sb) ? 1 : 0;
count = i8count = namelen = 0;
btp = xfs_dir2_block_tail_p(geo, hdr);
blp = xfs_dir2_block_leaf_p(btp);
for (i = 0; i < be32_to_cpu(btp->count); i++) {
if ((addr = be32_to_cpu(blp[i].address)) == XFS_DIR2_NULL_DATAPTR)
continue;
dep = (xfs_dir2_data_entry_t *)((char *)hdr +
xfs_dir2_dataptr_to_off(geo, addr));
isdot = dep->namelen == 1 && dep->name[0] == '.';
isdotdot =
dep->namelen == 2 &&
dep->name[0] == '.' && dep->name[1] == '.';
if (!isdot)
i8count += be64_to_cpu(dep->inumber) > XFS_DIR2_MAX_SHORT_INUM;
if (!isdot && !isdotdot) {
count++;
namelen += dep->namelen + has_ftype;
} else if (isdotdot)
parent = be64_to_cpu(dep->inumber);
size = xfs_dir2_sf_hdr_size(i8count) +
count +
count * (uint)sizeof(xfs_dir2_sf_off_t) +
namelen +
(i8count ?
(uint)sizeof(xfs_dir2_ino8_t) * count :
(uint)sizeof(xfs_dir2_ino4_t) * count);
if (size > XFS_IFORK_DSIZE(dp))
return size;
}
sfhp->count = count;
sfhp->i8count = i8count;
dp->d_ops->sf_put_parent_ino(sfhp, parent);
return size;
}
int
xfs_dir2_block_to_sf(
xfs_da_args_t *args,
struct xfs_buf *bp,
int size,
xfs_dir2_sf_hdr_t *sfhp)
{
xfs_dir2_data_hdr_t *hdr;
xfs_dir2_block_tail_t *btp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
char *endptr;
int error;
int logflags;
xfs_mount_t *mp;
char *ptr;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
xfs_dir2_sf_hdr_t *dst;
trace_xfs_dir2_block_to_sf(args);
dp = args->dp;
mp = dp->i_mount;
dst = kmem_alloc(mp->m_sb.sb_inodesize, KM_SLEEP);
hdr = bp->b_addr;
sfp = (xfs_dir2_sf_hdr_t *)dst;
memcpy(sfp, sfhp, xfs_dir2_sf_hdr_size(sfhp->i8count));
btp = xfs_dir2_block_tail_p(args->geo, hdr);
ptr = (char *)dp->d_ops->data_entry_p(hdr);
endptr = (char *)xfs_dir2_block_leaf_p(btp);
sfep = xfs_dir2_sf_firstentry(sfp);
while (ptr < endptr) {
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
ptr += be16_to_cpu(dup->length);
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
if (dep->namelen == 1 && dep->name[0] == '.')
ASSERT(be64_to_cpu(dep->inumber) == dp->i_ino);
else if (dep->namelen == 2 &&
dep->name[0] == '.' && dep->name[1] == '.')
ASSERT(be64_to_cpu(dep->inumber) ==
dp->d_ops->sf_get_parent_ino(sfp));
else {
sfep->namelen = dep->namelen;
xfs_dir2_sf_put_offset(sfep,
(xfs_dir2_data_aoff_t)
((char *)dep - (char *)hdr));
memcpy(sfep->name, dep->name, dep->namelen);
dp->d_ops->sf_put_ino(sfp, sfep,
be64_to_cpu(dep->inumber));
dp->d_ops->sf_put_ftype(sfep,
dp->d_ops->data_get_ftype(dep));
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
}
ptr += dp->d_ops->data_entsize(dep->namelen);
}
ASSERT((char *)sfep - (char *)sfp == size);
logflags = XFS_ILOG_CORE;
error = xfs_dir2_shrink_inode(args, args->geo->datablk, bp);
if (error) {
ASSERT(error != -ENOSPC);
goto out;
}
ASSERT(dp->i_df.if_bytes == 0);
xfs_init_local_fork(dp, XFS_DATA_FORK, dst, size);
dp->i_d.di_format = XFS_DINODE_FMT_LOCAL;
dp->i_d.di_size = size;
logflags |= XFS_ILOG_DDATA;
xfs_dir2_sf_check(args);
out:
xfs_trans_log_inode(args->trans, dp, logflags);
kmem_free(dst);
return error;
}
int
xfs_dir2_sf_addname(
xfs_da_args_t *args)
{
xfs_inode_t *dp;
int error;
int incr_isize;
int new_isize;
int objchange;
xfs_dir2_data_aoff_t offset = 0;
int pick;
xfs_dir2_sf_hdr_t *sfp;
xfs_dir2_sf_entry_t *sfep = NULL;
trace_xfs_dir2_sf_addname(args);
ASSERT(xfs_dir2_sf_lookup(args) == -ENOENT);
dp = args->dp;
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
if (dp->i_d.di_size < offsetof(xfs_dir2_sf_hdr_t, parent)) {
ASSERT(XFS_FORCED_SHUTDOWN(dp->i_mount));
return -EIO;
}
ASSERT(dp->i_df.if_bytes == dp->i_d.di_size);
ASSERT(dp->i_df.if_u1.if_data != NULL);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(dp->i_d.di_size >= xfs_dir2_sf_hdr_size(sfp->i8count));
incr_isize = dp->d_ops->sf_entsize(sfp, args->namelen);
objchange = 0;
if (args->inumber > XFS_DIR2_MAX_SHORT_INUM && sfp->i8count == 0) {
incr_isize +=
(sfp->count + 2) *
((uint)sizeof(xfs_dir2_ino8_t) -
(uint)sizeof(xfs_dir2_ino4_t));
objchange = 1;
}
new_isize = (int)dp->i_d.di_size + incr_isize;
if (new_isize > XFS_IFORK_DSIZE(dp) ||
(pick =
xfs_dir2_sf_addname_pick(args, objchange, &sfep, &offset)) == 0) {
if ((args->op_flags & XFS_DA_OP_JUSTCHECK) || args->total == 0)
return -ENOSPC;
error = xfs_dir2_sf_to_block(args);
if (error)
return error;
return xfs_dir2_block_addname(args);
}
if (args->op_flags & XFS_DA_OP_JUSTCHECK)
return 0;
if (pick == 1)
xfs_dir2_sf_addname_easy(args, sfep, offset, new_isize);
else {
ASSERT(pick == 2);
if (objchange)
xfs_dir2_sf_toino8(args);
xfs_dir2_sf_addname_hard(args, objchange, new_isize);
}
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE | XFS_ILOG_DDATA);
return 0;
}
static void
xfs_dir2_sf_addname_easy(
xfs_da_args_t *args,
xfs_dir2_sf_entry_t *sfep,
xfs_dir2_data_aoff_t offset,
int new_isize)
{
int byteoff;
xfs_inode_t *dp;
xfs_dir2_sf_hdr_t *sfp;
dp = args->dp;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
byteoff = (int)((char *)sfep - (char *)sfp);
xfs_idata_realloc(dp, dp->d_ops->sf_entsize(sfp, args->namelen),
XFS_DATA_FORK);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
sfep = (xfs_dir2_sf_entry_t *)((char *)sfp + byteoff);
sfep->namelen = args->namelen;
xfs_dir2_sf_put_offset(sfep, offset);
memcpy(sfep->name, args->name, sfep->namelen);
dp->d_ops->sf_put_ino(sfp, sfep, args->inumber);
dp->d_ops->sf_put_ftype(sfep, args->filetype);
sfp->count++;
if (args->inumber > XFS_DIR2_MAX_SHORT_INUM)
sfp->i8count++;
dp->i_d.di_size = new_isize;
xfs_dir2_sf_check(args);
}
static void
xfs_dir2_sf_addname_hard(
xfs_da_args_t *args,
int objchange,
int new_isize)
{
int add_datasize;
char *buf;
xfs_inode_t *dp;
int eof;
int nbytes;
xfs_dir2_data_aoff_t new_offset;
xfs_dir2_data_aoff_t offset;
int old_isize;
xfs_dir2_sf_entry_t *oldsfep;
xfs_dir2_sf_hdr_t *oldsfp;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
dp = args->dp;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
old_isize = (int)dp->i_d.di_size;
buf = kmem_alloc(old_isize, KM_SLEEP);
oldsfp = (xfs_dir2_sf_hdr_t *)buf;
memcpy(oldsfp, sfp, old_isize);
for (offset = dp->d_ops->data_first_offset,
oldsfep = xfs_dir2_sf_firstentry(oldsfp),
add_datasize = dp->d_ops->data_entsize(args->namelen),
eof = (char *)oldsfep == &buf[old_isize];
!eof;
offset = new_offset + dp->d_ops->data_entsize(oldsfep->namelen),
oldsfep = dp->d_ops->sf_nextentry(oldsfp, oldsfep),
eof = (char *)oldsfep == &buf[old_isize]) {
new_offset = xfs_dir2_sf_get_offset(oldsfep);
if (offset + add_datasize <= new_offset)
break;
}
xfs_idata_realloc(dp, -old_isize, XFS_DATA_FORK);
xfs_idata_realloc(dp, new_isize, XFS_DATA_FORK);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
nbytes = (int)((char *)oldsfep - (char *)oldsfp);
memcpy(sfp, oldsfp, nbytes);
sfep = (xfs_dir2_sf_entry_t *)((char *)sfp + nbytes);
sfep->namelen = args->namelen;
xfs_dir2_sf_put_offset(sfep, offset);
memcpy(sfep->name, args->name, sfep->namelen);
dp->d_ops->sf_put_ino(sfp, sfep, args->inumber);
dp->d_ops->sf_put_ftype(sfep, args->filetype);
sfp->count++;
if (args->inumber > XFS_DIR2_MAX_SHORT_INUM && !objchange)
sfp->i8count++;
if (!eof) {
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
memcpy(sfep, oldsfep, old_isize - nbytes);
}
kmem_free(buf);
dp->i_d.di_size = new_isize;
xfs_dir2_sf_check(args);
}
static int
xfs_dir2_sf_addname_pick(
xfs_da_args_t *args,
int objchange,
xfs_dir2_sf_entry_t **sfepp,
xfs_dir2_data_aoff_t *offsetp)
{
xfs_inode_t *dp;
int holefit;
int i;
xfs_dir2_data_aoff_t offset;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
int size;
int used;
dp = args->dp;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
size = dp->d_ops->data_entsize(args->namelen);
offset = dp->d_ops->data_first_offset;
sfep = xfs_dir2_sf_firstentry(sfp);
holefit = 0;
for (i = 0; i < sfp->count; i++) {
if (!holefit)
holefit = offset + size <= xfs_dir2_sf_get_offset(sfep);
offset = xfs_dir2_sf_get_offset(sfep) +
dp->d_ops->data_entsize(sfep->namelen);
sfep = dp->d_ops->sf_nextentry(sfp, sfep);
}
used = offset +
(sfp->count + 3) * (uint)sizeof(xfs_dir2_leaf_entry_t) +
(uint)sizeof(xfs_dir2_block_tail_t);
if (used + (holefit ? 0 : size) > args->geo->blksize)
return 0;
if (objchange)
return 2;
if (used + size > args->geo->blksize)
return 2;
*sfepp = sfep;
*offsetp = offset;
return 1;
}
static void
xfs_dir2_sf_check(
xfs_da_args_t *args)
{
xfs_inode_t *dp;
int i;
int i8count;
xfs_ino_t ino;
int offset;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
dp = args->dp;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
offset = dp->d_ops->data_first_offset;
ino = dp->d_ops->sf_get_parent_ino(sfp);
i8count = ino > XFS_DIR2_MAX_SHORT_INUM;
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp);
i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep)) {
ASSERT(xfs_dir2_sf_get_offset(sfep) >= offset);
ino = dp->d_ops->sf_get_ino(sfp, sfep);
i8count += ino > XFS_DIR2_MAX_SHORT_INUM;
offset =
xfs_dir2_sf_get_offset(sfep) +
dp->d_ops->data_entsize(sfep->namelen);
ASSERT(dp->d_ops->sf_get_ftype(sfep) < XFS_DIR3_FT_MAX);
}
ASSERT(i8count == sfp->i8count);
ASSERT((char *)sfep - (char *)sfp == dp->i_d.di_size);
ASSERT(offset +
(sfp->count + 2) * (uint)sizeof(xfs_dir2_leaf_entry_t) +
(uint)sizeof(xfs_dir2_block_tail_t) <= args->geo->blksize);
}
int
xfs_dir2_sf_create(
xfs_da_args_t *args,
xfs_ino_t pino)
{
xfs_inode_t *dp;
int i8count;
xfs_dir2_sf_hdr_t *sfp;
int size;
trace_xfs_dir2_sf_create(args);
dp = args->dp;
ASSERT(dp != NULL);
ASSERT(dp->i_d.di_size == 0);
if (dp->i_d.di_format == XFS_DINODE_FMT_EXTENTS) {
dp->i_df.if_flags &= ~XFS_IFEXTENTS;
dp->i_d.di_format = XFS_DINODE_FMT_LOCAL;
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE);
dp->i_df.if_flags |= XFS_IFINLINE;
}
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
ASSERT(dp->i_df.if_bytes == 0);
i8count = pino > XFS_DIR2_MAX_SHORT_INUM;
size = xfs_dir2_sf_hdr_size(i8count);
xfs_idata_realloc(dp, size, XFS_DATA_FORK);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
sfp->i8count = i8count;
dp->d_ops->sf_put_parent_ino(sfp, pino);
sfp->count = 0;
dp->i_d.di_size = size;
xfs_dir2_sf_check(args);
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE | XFS_ILOG_DDATA);
return 0;
}
int
xfs_dir2_sf_lookup(
xfs_da_args_t *args)
{
xfs_inode_t *dp;
int i;
int error;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
enum xfs_dacmp cmp;
xfs_dir2_sf_entry_t *ci_sfep;
trace_xfs_dir2_sf_lookup(args);
xfs_dir2_sf_check(args);
dp = args->dp;
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
if (dp->i_d.di_size < offsetof(xfs_dir2_sf_hdr_t, parent)) {
ASSERT(XFS_FORCED_SHUTDOWN(dp->i_mount));
return -EIO;
}
ASSERT(dp->i_df.if_bytes == dp->i_d.di_size);
ASSERT(dp->i_df.if_u1.if_data != NULL);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(dp->i_d.di_size >= xfs_dir2_sf_hdr_size(sfp->i8count));
if (args->namelen == 1 && args->name[0] == '.') {
args->inumber = dp->i_ino;
args->cmpresult = XFS_CMP_EXACT;
args->filetype = XFS_DIR3_FT_DIR;
return -EEXIST;
}
if (args->namelen == 2 &&
args->name[0] == '.' && args->name[1] == '.') {
args->inumber = dp->d_ops->sf_get_parent_ino(sfp);
args->cmpresult = XFS_CMP_EXACT;
args->filetype = XFS_DIR3_FT_DIR;
return -EEXIST;
}
ci_sfep = NULL;
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp); i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep)) {
cmp = dp->i_mount->m_dirnameops->compname(args, sfep->name,
sfep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
args->cmpresult = cmp;
args->inumber = dp->d_ops->sf_get_ino(sfp, sfep);
args->filetype = dp->d_ops->sf_get_ftype(sfep);
if (cmp == XFS_CMP_EXACT)
return -EEXIST;
ci_sfep = sfep;
}
}
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (!ci_sfep)
return -ENOENT;
error = xfs_dir_cilookup_result(args, ci_sfep->name, ci_sfep->namelen);
return error;
}
int
xfs_dir2_sf_removename(
xfs_da_args_t *args)
{
int byteoff;
xfs_inode_t *dp;
int entsize;
int i;
int newsize;
int oldsize;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
trace_xfs_dir2_sf_removename(args);
dp = args->dp;
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
oldsize = (int)dp->i_d.di_size;
if (oldsize < offsetof(xfs_dir2_sf_hdr_t, parent)) {
ASSERT(XFS_FORCED_SHUTDOWN(dp->i_mount));
return -EIO;
}
ASSERT(dp->i_df.if_bytes == oldsize);
ASSERT(dp->i_df.if_u1.if_data != NULL);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(oldsize >= xfs_dir2_sf_hdr_size(sfp->i8count));
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp); i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep)) {
if (xfs_da_compname(args, sfep->name, sfep->namelen) ==
XFS_CMP_EXACT) {
ASSERT(dp->d_ops->sf_get_ino(sfp, sfep) ==
args->inumber);
break;
}
}
if (i == sfp->count)
return -ENOENT;
byteoff = (int)((char *)sfep - (char *)sfp);
entsize = dp->d_ops->sf_entsize(sfp, args->namelen);
newsize = oldsize - entsize;
if (byteoff + entsize < oldsize)
memmove((char *)sfp + byteoff, (char *)sfp + byteoff + entsize,
oldsize - (byteoff + entsize));
sfp->count--;
dp->i_d.di_size = newsize;
xfs_idata_realloc(dp, newsize - oldsize, XFS_DATA_FORK);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
if (args->inumber > XFS_DIR2_MAX_SHORT_INUM) {
if (sfp->i8count == 1)
xfs_dir2_sf_toino4(args);
else
sfp->i8count--;
}
xfs_dir2_sf_check(args);
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE | XFS_ILOG_DDATA);
return 0;
}
int
xfs_dir2_sf_replace(
xfs_da_args_t *args)
{
xfs_inode_t *dp;
int i;
xfs_ino_t ino=0;
int i8elevated;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
trace_xfs_dir2_sf_replace(args);
dp = args->dp;
ASSERT(dp->i_df.if_flags & XFS_IFINLINE);
if (dp->i_d.di_size < offsetof(xfs_dir2_sf_hdr_t, parent)) {
ASSERT(XFS_FORCED_SHUTDOWN(dp->i_mount));
return -EIO;
}
ASSERT(dp->i_df.if_bytes == dp->i_d.di_size);
ASSERT(dp->i_df.if_u1.if_data != NULL);
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(dp->i_d.di_size >= xfs_dir2_sf_hdr_size(sfp->i8count));
if (args->inumber > XFS_DIR2_MAX_SHORT_INUM && sfp->i8count == 0) {
int error;
int newsize;
newsize =
dp->i_df.if_bytes +
(sfp->count + 1) *
((uint)sizeof(xfs_dir2_ino8_t) -
(uint)sizeof(xfs_dir2_ino4_t));
if (newsize > XFS_IFORK_DSIZE(dp)) {
error = xfs_dir2_sf_to_block(args);
if (error) {
return error;
}
return xfs_dir2_block_replace(args);
}
xfs_dir2_sf_toino8(args);
i8elevated = 1;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
} else
i8elevated = 0;
ASSERT(args->namelen != 1 || args->name[0] != '.');
if (args->namelen == 2 &&
args->name[0] == '.' && args->name[1] == '.') {
ino = dp->d_ops->sf_get_parent_ino(sfp);
ASSERT(args->inumber != ino);
dp->d_ops->sf_put_parent_ino(sfp, args->inumber);
}
else {
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp); i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep)) {
if (xfs_da_compname(args, sfep->name, sfep->namelen) ==
XFS_CMP_EXACT) {
ino = dp->d_ops->sf_get_ino(sfp, sfep);
ASSERT(args->inumber != ino);
dp->d_ops->sf_put_ino(sfp, sfep, args->inumber);
dp->d_ops->sf_put_ftype(sfep, args->filetype);
break;
}
}
if (i == sfp->count) {
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (i8elevated)
xfs_dir2_sf_toino4(args);
return -ENOENT;
}
}
if (ino > XFS_DIR2_MAX_SHORT_INUM &&
args->inumber <= XFS_DIR2_MAX_SHORT_INUM) {
if (sfp->i8count == 1)
xfs_dir2_sf_toino4(args);
else
sfp->i8count--;
}
if (ino <= XFS_DIR2_MAX_SHORT_INUM &&
args->inumber > XFS_DIR2_MAX_SHORT_INUM) {
ASSERT(sfp->i8count != 0);
if (!i8elevated)
sfp->i8count++;
}
xfs_dir2_sf_check(args);
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_DDATA);
return 0;
}
static void
xfs_dir2_sf_toino4(
xfs_da_args_t *args)
{
char *buf;
xfs_inode_t *dp;
int i;
int newsize;
xfs_dir2_sf_entry_t *oldsfep;
xfs_dir2_sf_hdr_t *oldsfp;
int oldsize;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
trace_xfs_dir2_sf_toino4(args);
dp = args->dp;
oldsize = dp->i_df.if_bytes;
buf = kmem_alloc(oldsize, KM_SLEEP);
oldsfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(oldsfp->i8count == 1);
memcpy(buf, oldsfp, oldsize);
newsize =
oldsize -
(oldsfp->count + 1) *
((uint)sizeof(xfs_dir2_ino8_t) - (uint)sizeof(xfs_dir2_ino4_t));
xfs_idata_realloc(dp, -oldsize, XFS_DATA_FORK);
xfs_idata_realloc(dp, newsize, XFS_DATA_FORK);
oldsfp = (xfs_dir2_sf_hdr_t *)buf;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
sfp->count = oldsfp->count;
sfp->i8count = 0;
dp->d_ops->sf_put_parent_ino(sfp, dp->d_ops->sf_get_parent_ino(oldsfp));
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp),
oldsfep = xfs_dir2_sf_firstentry(oldsfp);
i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep),
oldsfep = dp->d_ops->sf_nextentry(oldsfp, oldsfep)) {
sfep->namelen = oldsfep->namelen;
sfep->offset = oldsfep->offset;
memcpy(sfep->name, oldsfep->name, sfep->namelen);
dp->d_ops->sf_put_ino(sfp, sfep,
dp->d_ops->sf_get_ino(oldsfp, oldsfep));
dp->d_ops->sf_put_ftype(sfep, dp->d_ops->sf_get_ftype(oldsfep));
}
kmem_free(buf);
dp->i_d.di_size = newsize;
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE | XFS_ILOG_DDATA);
}
static void
xfs_dir2_sf_toino8(
xfs_da_args_t *args)
{
char *buf;
xfs_inode_t *dp;
int i;
int newsize;
xfs_dir2_sf_entry_t *oldsfep;
xfs_dir2_sf_hdr_t *oldsfp;
int oldsize;
xfs_dir2_sf_entry_t *sfep;
xfs_dir2_sf_hdr_t *sfp;
trace_xfs_dir2_sf_toino8(args);
dp = args->dp;
oldsize = dp->i_df.if_bytes;
buf = kmem_alloc(oldsize, KM_SLEEP);
oldsfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
ASSERT(oldsfp->i8count == 0);
memcpy(buf, oldsfp, oldsize);
newsize =
oldsize +
(oldsfp->count + 1) *
((uint)sizeof(xfs_dir2_ino8_t) - (uint)sizeof(xfs_dir2_ino4_t));
xfs_idata_realloc(dp, -oldsize, XFS_DATA_FORK);
xfs_idata_realloc(dp, newsize, XFS_DATA_FORK);
oldsfp = (xfs_dir2_sf_hdr_t *)buf;
sfp = (xfs_dir2_sf_hdr_t *)dp->i_df.if_u1.if_data;
sfp->count = oldsfp->count;
sfp->i8count = 1;
dp->d_ops->sf_put_parent_ino(sfp, dp->d_ops->sf_get_parent_ino(oldsfp));
for (i = 0, sfep = xfs_dir2_sf_firstentry(sfp),
oldsfep = xfs_dir2_sf_firstentry(oldsfp);
i < sfp->count;
i++, sfep = dp->d_ops->sf_nextentry(sfp, sfep),
oldsfep = dp->d_ops->sf_nextentry(oldsfp, oldsfep)) {
sfep->namelen = oldsfep->namelen;
sfep->offset = oldsfep->offset;
memcpy(sfep->name, oldsfep->name, sfep->namelen);
dp->d_ops->sf_put_ino(sfp, sfep,
dp->d_ops->sf_get_ino(oldsfp, oldsfep));
dp->d_ops->sf_put_ftype(sfep, dp->d_ops->sf_get_ftype(oldsfep));
}
kmem_free(buf);
dp->i_d.di_size = newsize;
xfs_trans_log_inode(args->trans, dp, XFS_ILOG_CORE | XFS_ILOG_DDATA);
}
