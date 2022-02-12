STATIC int
xfs_attr_shortform_compare(const void *a, const void *b)
{
xfs_attr_sf_sort_t *sa, *sb;
sa = (xfs_attr_sf_sort_t *)a;
sb = (xfs_attr_sf_sort_t *)b;
if (sa->hash < sb->hash) {
return -1;
} else if (sa->hash > sb->hash) {
return 1;
} else {
return sa->entno - sb->entno;
}
}
int
xfs_attr_shortform_list(xfs_attr_list_context_t *context)
{
attrlist_cursor_kern_t *cursor;
xfs_attr_sf_sort_t *sbuf, *sbp;
xfs_attr_shortform_t *sf;
xfs_attr_sf_entry_t *sfe;
xfs_inode_t *dp;
int sbsize, nsbuf, count, i;
int error;
ASSERT(context != NULL);
dp = context->dp;
ASSERT(dp != NULL);
ASSERT(dp->i_afp != NULL);
sf = (xfs_attr_shortform_t *)dp->i_afp->if_u1.if_data;
ASSERT(sf != NULL);
if (!sf->hdr.count)
return 0;
cursor = context->cursor;
ASSERT(cursor != NULL);
trace_xfs_attr_list_sf(context);
if (context->bufsize == 0 ||
(XFS_ISRESET_CURSOR(cursor) &&
(dp->i_afp->if_bytes + sf->hdr.count * 16) < context->bufsize)) {
for (i = 0, sfe = &sf->list[0]; i < sf->hdr.count; i++) {
error = context->put_listent(context,
sfe->flags,
sfe->nameval,
(int)sfe->namelen,
(int)sfe->valuelen,
&sfe->nameval[sfe->namelen]);
if (context->seen_enough)
break;
if (error)
return error;
sfe = XFS_ATTR_SF_NEXTENTRY(sfe);
}
trace_xfs_attr_list_sf_all(context);
return 0;
}
if (context->bufsize == 0)
return 0;
sbsize = sf->hdr.count * sizeof(*sbuf);
sbp = sbuf = kmem_alloc(sbsize, KM_SLEEP | KM_NOFS);
nsbuf = 0;
for (i = 0, sfe = &sf->list[0]; i < sf->hdr.count; i++) {
if (unlikely(
((char *)sfe < (char *)sf) ||
((char *)sfe >= ((char *)sf + dp->i_afp->if_bytes)))) {
XFS_CORRUPTION_ERROR("xfs_attr_shortform_list",
XFS_ERRLEVEL_LOW,
context->dp->i_mount, sfe);
kmem_free(sbuf);
return -EFSCORRUPTED;
}
sbp->entno = i;
sbp->hash = xfs_da_hashname(sfe->nameval, sfe->namelen);
sbp->name = sfe->nameval;
sbp->namelen = sfe->namelen;
sbp->valuelen = sfe->valuelen;
sbp->flags = sfe->flags;
sfe = XFS_ATTR_SF_NEXTENTRY(sfe);
sbp++;
nsbuf++;
}
xfs_sort(sbuf, nsbuf, sizeof(*sbuf), xfs_attr_shortform_compare);
count = 0;
cursor->initted = 1;
cursor->blkno = 0;
for (sbp = sbuf, i = 0; i < nsbuf; i++, sbp++) {
if (sbp->hash == cursor->hashval) {
if (cursor->offset == count) {
break;
}
count++;
} else if (sbp->hash > cursor->hashval) {
break;
}
}
if (i == nsbuf) {
kmem_free(sbuf);
return 0;
}
for ( ; i < nsbuf; i++, sbp++) {
if (cursor->hashval != sbp->hash) {
cursor->hashval = sbp->hash;
cursor->offset = 0;
}
error = context->put_listent(context,
sbp->flags,
sbp->name,
sbp->namelen,
sbp->valuelen,
&sbp->name[sbp->namelen]);
if (error)
return error;
if (context->seen_enough)
break;
cursor->offset++;
}
kmem_free(sbuf);
return 0;
}
STATIC int
xfs_attr_node_list(xfs_attr_list_context_t *context)
{
attrlist_cursor_kern_t *cursor;
xfs_attr_leafblock_t *leaf;
xfs_da_intnode_t *node;
struct xfs_attr3_icleaf_hdr leafhdr;
struct xfs_da3_icnode_hdr nodehdr;
struct xfs_da_node_entry *btree;
int error, i;
struct xfs_buf *bp;
struct xfs_inode *dp = context->dp;
struct xfs_mount *mp = dp->i_mount;
trace_xfs_attr_node_list(context);
cursor = context->cursor;
cursor->initted = 1;
bp = NULL;
if (cursor->blkno > 0) {
error = xfs_da3_node_read(NULL, dp, cursor->blkno, -1,
&bp, XFS_ATTR_FORK);
if ((error != 0) && (error != -EFSCORRUPTED))
return error;
if (bp) {
struct xfs_attr_leaf_entry *entries;
node = bp->b_addr;
switch (be16_to_cpu(node->hdr.info.magic)) {
case XFS_DA_NODE_MAGIC:
case XFS_DA3_NODE_MAGIC:
trace_xfs_attr_list_wrong_blk(context);
xfs_trans_brelse(NULL, bp);
bp = NULL;
break;
case XFS_ATTR_LEAF_MAGIC:
case XFS_ATTR3_LEAF_MAGIC:
leaf = bp->b_addr;
xfs_attr3_leaf_hdr_from_disk(mp->m_attr_geo,
&leafhdr, leaf);
entries = xfs_attr3_leaf_entryp(leaf);
if (cursor->hashval > be32_to_cpu(
entries[leafhdr.count - 1].hashval)) {
trace_xfs_attr_list_wrong_blk(context);
xfs_trans_brelse(NULL, bp);
bp = NULL;
} else if (cursor->hashval <= be32_to_cpu(
entries[0].hashval)) {
trace_xfs_attr_list_wrong_blk(context);
xfs_trans_brelse(NULL, bp);
bp = NULL;
}
break;
default:
trace_xfs_attr_list_wrong_blk(context);
xfs_trans_brelse(NULL, bp);
bp = NULL;
}
}
}
if (bp == NULL) {
cursor->blkno = 0;
for (;;) {
__uint16_t magic;
error = xfs_da3_node_read(NULL, dp,
cursor->blkno, -1, &bp,
XFS_ATTR_FORK);
if (error)
return error;
node = bp->b_addr;
magic = be16_to_cpu(node->hdr.info.magic);
if (magic == XFS_ATTR_LEAF_MAGIC ||
magic == XFS_ATTR3_LEAF_MAGIC)
break;
if (magic != XFS_DA_NODE_MAGIC &&
magic != XFS_DA3_NODE_MAGIC) {
XFS_CORRUPTION_ERROR("xfs_attr_node_list(3)",
XFS_ERRLEVEL_LOW,
context->dp->i_mount,
node);
xfs_trans_brelse(NULL, bp);
return -EFSCORRUPTED;
}
dp->d_ops->node_hdr_from_disk(&nodehdr, node);
btree = dp->d_ops->node_tree_p(node);
for (i = 0; i < nodehdr.count; btree++, i++) {
if (cursor->hashval
<= be32_to_cpu(btree->hashval)) {
cursor->blkno = be32_to_cpu(btree->before);
trace_xfs_attr_list_node_descend(context,
btree);
break;
}
}
if (i == nodehdr.count) {
xfs_trans_brelse(NULL, bp);
return 0;
}
xfs_trans_brelse(NULL, bp);
}
}
ASSERT(bp != NULL);
for (;;) {
leaf = bp->b_addr;
error = xfs_attr3_leaf_list_int(bp, context);
if (error) {
xfs_trans_brelse(NULL, bp);
return error;
}
xfs_attr3_leaf_hdr_from_disk(mp->m_attr_geo, &leafhdr, leaf);
if (context->seen_enough || leafhdr.forw == 0)
break;
cursor->blkno = leafhdr.forw;
xfs_trans_brelse(NULL, bp);
error = xfs_attr3_leaf_read(NULL, dp, cursor->blkno, -1, &bp);
if (error)
return error;
}
xfs_trans_brelse(NULL, bp);
return 0;
}
int
xfs_attr3_leaf_list_int(
struct xfs_buf *bp,
struct xfs_attr_list_context *context)
{
struct attrlist_cursor_kern *cursor;
struct xfs_attr_leafblock *leaf;
struct xfs_attr3_icleaf_hdr ichdr;
struct xfs_attr_leaf_entry *entries;
struct xfs_attr_leaf_entry *entry;
int retval;
int i;
struct xfs_mount *mp = context->dp->i_mount;
trace_xfs_attr_list_leaf(context);
leaf = bp->b_addr;
xfs_attr3_leaf_hdr_from_disk(mp->m_attr_geo, &ichdr, leaf);
entries = xfs_attr3_leaf_entryp(leaf);
cursor = context->cursor;
cursor->initted = 1;
if (context->resynch) {
entry = &entries[0];
for (i = 0; i < ichdr.count; entry++, i++) {
if (be32_to_cpu(entry->hashval) == cursor->hashval) {
if (cursor->offset == context->dupcnt) {
context->dupcnt = 0;
break;
}
context->dupcnt++;
} else if (be32_to_cpu(entry->hashval) >
cursor->hashval) {
context->dupcnt = 0;
break;
}
}
if (i == ichdr.count) {
trace_xfs_attr_list_notfound(context);
return 0;
}
} else {
entry = &entries[0];
i = 0;
}
context->resynch = 0;
retval = 0;
for (; i < ichdr.count; entry++, i++) {
if (be32_to_cpu(entry->hashval) != cursor->hashval) {
cursor->hashval = be32_to_cpu(entry->hashval);
cursor->offset = 0;
}
if (entry->flags & XFS_ATTR_INCOMPLETE)
continue;
if (entry->flags & XFS_ATTR_LOCAL) {
xfs_attr_leaf_name_local_t *name_loc =
xfs_attr3_leaf_name_local(leaf, i);
retval = context->put_listent(context,
entry->flags,
name_loc->nameval,
(int)name_loc->namelen,
be16_to_cpu(name_loc->valuelen),
&name_loc->nameval[name_loc->namelen]);
if (retval)
return retval;
} else {
xfs_attr_leaf_name_remote_t *name_rmt =
xfs_attr3_leaf_name_remote(leaf, i);
int valuelen = be32_to_cpu(name_rmt->valuelen);
if (context->put_value) {
xfs_da_args_t args;
memset((char *)&args, 0, sizeof(args));
args.geo = context->dp->i_mount->m_attr_geo;
args.dp = context->dp;
args.whichfork = XFS_ATTR_FORK;
args.valuelen = valuelen;
args.rmtvaluelen = valuelen;
args.value = kmem_alloc(valuelen, KM_SLEEP | KM_NOFS);
args.rmtblkno = be32_to_cpu(name_rmt->valueblk);
args.rmtblkcnt = xfs_attr3_rmt_blocks(
args.dp->i_mount, valuelen);
retval = xfs_attr_rmtval_get(&args);
if (retval)
return retval;
retval = context->put_listent(context,
entry->flags,
name_rmt->name,
(int)name_rmt->namelen,
valuelen,
args.value);
kmem_free(args.value);
} else {
retval = context->put_listent(context,
entry->flags,
name_rmt->name,
(int)name_rmt->namelen,
valuelen,
NULL);
}
if (retval)
return retval;
}
if (context->seen_enough)
break;
cursor->offset++;
}
trace_xfs_attr_list_leaf_end(context);
return retval;
}
STATIC int
xfs_attr_leaf_list(xfs_attr_list_context_t *context)
{
int error;
struct xfs_buf *bp;
trace_xfs_attr_leaf_list(context);
context->cursor->blkno = 0;
error = xfs_attr3_leaf_read(NULL, context->dp, 0, -1, &bp);
if (error)
return error;
error = xfs_attr3_leaf_list_int(bp, context);
xfs_trans_brelse(NULL, bp);
return error;
}
int
xfs_attr_list_int(
xfs_attr_list_context_t *context)
{
int error;
xfs_inode_t *dp = context->dp;
uint lock_mode;
XFS_STATS_INC(dp->i_mount, xs_attr_list);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return -EIO;
lock_mode = xfs_ilock_attr_map_shared(dp);
if (!xfs_inode_hasattr(dp)) {
error = 0;
} else if (dp->i_d.di_aformat == XFS_DINODE_FMT_LOCAL) {
error = xfs_attr_shortform_list(context);
} else if (xfs_bmap_one_block(dp, XFS_ATTR_FORK)) {
error = xfs_attr_leaf_list(context);
} else {
error = xfs_attr_node_list(context);
}
xfs_iunlock(dp, lock_mode);
return error;
}
STATIC int
xfs_attr_put_listent(
xfs_attr_list_context_t *context,
int flags,
unsigned char *name,
int namelen,
int valuelen,
unsigned char *value)
{
struct attrlist *alist = (struct attrlist *)context->alist;
attrlist_ent_t *aep;
int arraytop;
ASSERT(!(context->flags & ATTR_KERNOVAL));
ASSERT(context->count >= 0);
ASSERT(context->count < (ATTR_MAX_VALUELEN/8));
ASSERT(context->firstu >= sizeof(*alist));
ASSERT(context->firstu <= context->bufsize);
if (((context->flags & ATTR_SECURE) == 0) !=
((flags & XFS_ATTR_SECURE) == 0))
return 0;
if (((context->flags & ATTR_ROOT) == 0) !=
((flags & XFS_ATTR_ROOT) == 0))
return 0;
arraytop = sizeof(*alist) +
context->count * sizeof(alist->al_offset[0]);
context->firstu -= ATTR_ENTSIZE(namelen);
if (context->firstu < arraytop) {
trace_xfs_attr_list_full(context);
alist->al_more = 1;
context->seen_enough = 1;
return 1;
}
aep = (attrlist_ent_t *)&context->alist[context->firstu];
aep->a_valuelen = valuelen;
memcpy(aep->a_name, name, namelen);
aep->a_name[namelen] = 0;
alist->al_offset[context->count++] = context->firstu;
alist->al_count = context->count;
trace_xfs_attr_list_add(context);
return 0;
}
int
xfs_attr_list(
xfs_inode_t *dp,
char *buffer,
int bufsize,
int flags,
attrlist_cursor_kern_t *cursor)
{
xfs_attr_list_context_t context;
struct attrlist *alist;
int error;
if (cursor->pad1 || cursor->pad2)
return -EINVAL;
if ((cursor->initted == 0) &&
(cursor->hashval || cursor->blkno || cursor->offset))
return -EINVAL;
if (((long)buffer) & (sizeof(int)-1))
return -EFAULT;
if (flags & ATTR_KERNOVAL)
bufsize = 0;
memset(&context, 0, sizeof(context));
context.dp = dp;
context.cursor = cursor;
context.resynch = 1;
context.flags = flags;
context.alist = buffer;
context.bufsize = (bufsize & ~(sizeof(int)-1));
context.firstu = context.bufsize;
context.put_listent = xfs_attr_put_listent;
alist = (struct attrlist *)context.alist;
alist->al_count = 0;
alist->al_more = 0;
alist->al_offset[0] = context.bufsize;
error = xfs_attr_list_int(&context);
ASSERT(error <= 0);
return error;
}
