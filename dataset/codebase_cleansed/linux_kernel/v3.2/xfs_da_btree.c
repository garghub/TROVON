int
xfs_da_node_create(xfs_da_args_t *args, xfs_dablk_t blkno, int level,
xfs_dabuf_t **bpp, int whichfork)
{
xfs_da_intnode_t *node;
xfs_dabuf_t *bp;
int error;
xfs_trans_t *tp;
tp = args->trans;
error = xfs_da_get_buf(tp, args->dp, blkno, -1, &bp, whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
node = bp->data;
node->hdr.info.forw = 0;
node->hdr.info.back = 0;
node->hdr.info.magic = cpu_to_be16(XFS_DA_NODE_MAGIC);
node->hdr.info.pad = 0;
node->hdr.count = 0;
node->hdr.level = cpu_to_be16(level);
xfs_da_log_buf(tp, bp,
XFS_DA_LOGRANGE(node, &node->hdr, sizeof(node->hdr)));
*bpp = bp;
return(0);
}
int
xfs_da_split(xfs_da_state_t *state)
{
xfs_da_state_blk_t *oldblk, *newblk, *addblk;
xfs_da_intnode_t *node;
xfs_dabuf_t *bp;
int max, action, error, i;
max = state->path.active - 1;
ASSERT((max >= 0) && (max < XFS_DA_NODE_MAXDEPTH));
ASSERT(state->path.blk[max].magic == XFS_ATTR_LEAF_MAGIC ||
state->path.blk[max].magic == XFS_DIR2_LEAFN_MAGIC);
addblk = &state->path.blk[max];
for (i = max; (i >= 0) && addblk; state->path.active--, i--) {
oldblk = &state->path.blk[i];
newblk = &state->altpath.blk[i];
switch (oldblk->magic) {
case XFS_ATTR_LEAF_MAGIC:
error = xfs_attr_leaf_split(state, oldblk, newblk);
if ((error != 0) && (error != ENOSPC)) {
return(error);
}
if (!error) {
addblk = newblk;
break;
}
state->extravalid = 1;
if (state->inleaf) {
state->extraafter = 0;
error = xfs_attr_leaf_split(state, oldblk,
&state->extrablk);
} else {
state->extraafter = 1;
error = xfs_attr_leaf_split(state, newblk,
&state->extrablk);
}
if (error)
return(error);
addblk = newblk;
break;
case XFS_DIR2_LEAFN_MAGIC:
error = xfs_dir2_leafn_split(state, oldblk, newblk);
if (error)
return error;
addblk = newblk;
break;
case XFS_DA_NODE_MAGIC:
error = xfs_da_node_split(state, oldblk, newblk, addblk,
max - i, &action);
xfs_da_buf_done(addblk->bp);
addblk->bp = NULL;
if (error)
return(error);
if (action)
addblk = newblk;
else
addblk = NULL;
break;
}
xfs_da_fixhashpath(state, &state->path);
if (i > 0 || !addblk)
xfs_da_buf_done(oldblk->bp);
}
if (!addblk)
return(0);
ASSERT(state->path.active == 0);
oldblk = &state->path.blk[0];
error = xfs_da_root_split(state, oldblk, addblk);
if (error) {
xfs_da_buf_done(oldblk->bp);
xfs_da_buf_done(addblk->bp);
addblk->bp = NULL;
return(error);
}
node = oldblk->bp->data;
if (node->hdr.info.forw) {
if (be32_to_cpu(node->hdr.info.forw) == addblk->blkno) {
bp = addblk->bp;
} else {
ASSERT(state->extravalid);
bp = state->extrablk.bp;
}
node = bp->data;
node->hdr.info.back = cpu_to_be32(oldblk->blkno);
xfs_da_log_buf(state->args->trans, bp,
XFS_DA_LOGRANGE(node, &node->hdr.info,
sizeof(node->hdr.info)));
}
node = oldblk->bp->data;
if (node->hdr.info.back) {
if (be32_to_cpu(node->hdr.info.back) == addblk->blkno) {
bp = addblk->bp;
} else {
ASSERT(state->extravalid);
bp = state->extrablk.bp;
}
node = bp->data;
node->hdr.info.forw = cpu_to_be32(oldblk->blkno);
xfs_da_log_buf(state->args->trans, bp,
XFS_DA_LOGRANGE(node, &node->hdr.info,
sizeof(node->hdr.info)));
}
xfs_da_buf_done(oldblk->bp);
xfs_da_buf_done(addblk->bp);
addblk->bp = NULL;
return(0);
}
STATIC int
xfs_da_root_split(xfs_da_state_t *state, xfs_da_state_blk_t *blk1,
xfs_da_state_blk_t *blk2)
{
xfs_da_intnode_t *node, *oldroot;
xfs_da_args_t *args;
xfs_dablk_t blkno;
xfs_dabuf_t *bp;
int error, size;
xfs_inode_t *dp;
xfs_trans_t *tp;
xfs_mount_t *mp;
xfs_dir2_leaf_t *leaf;
args = state->args;
ASSERT(args != NULL);
error = xfs_da_grow_inode(args, &blkno);
if (error)
return(error);
dp = args->dp;
tp = args->trans;
mp = state->mp;
error = xfs_da_get_buf(tp, dp, blkno, -1, &bp, args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
node = bp->data;
oldroot = blk1->bp->data;
if (oldroot->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC)) {
size = (int)((char *)&oldroot->btree[be16_to_cpu(oldroot->hdr.count)] -
(char *)oldroot);
} else {
ASSERT(oldroot->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC));
leaf = (xfs_dir2_leaf_t *)oldroot;
size = (int)((char *)&leaf->ents[be16_to_cpu(leaf->hdr.count)] -
(char *)leaf);
}
memcpy(node, oldroot, size);
xfs_da_log_buf(tp, bp, 0, size - 1);
xfs_da_buf_done(blk1->bp);
blk1->bp = bp;
blk1->blkno = blkno;
error = xfs_da_node_create(args,
(args->whichfork == XFS_DATA_FORK) ? mp->m_dirleafblk : 0,
be16_to_cpu(node->hdr.level) + 1, &bp, args->whichfork);
if (error)
return(error);
node = bp->data;
node->btree[0].hashval = cpu_to_be32(blk1->hashval);
node->btree[0].before = cpu_to_be32(blk1->blkno);
node->btree[1].hashval = cpu_to_be32(blk2->hashval);
node->btree[1].before = cpu_to_be32(blk2->blkno);
node->hdr.count = cpu_to_be16(2);
#ifdef DEBUG
if (oldroot->hdr.info.magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC)) {
ASSERT(blk1->blkno >= mp->m_dirleafblk &&
blk1->blkno < mp->m_dirfreeblk);
ASSERT(blk2->blkno >= mp->m_dirleafblk &&
blk2->blkno < mp->m_dirfreeblk);
}
#endif
xfs_da_log_buf(tp, bp,
XFS_DA_LOGRANGE(node, node->btree,
sizeof(xfs_da_node_entry_t) * 2));
xfs_da_buf_done(bp);
return(0);
}
STATIC int
xfs_da_node_split(xfs_da_state_t *state, xfs_da_state_blk_t *oldblk,
xfs_da_state_blk_t *newblk,
xfs_da_state_blk_t *addblk,
int treelevel, int *result)
{
xfs_da_intnode_t *node;
xfs_dablk_t blkno;
int newcount, error;
int useextra;
node = oldblk->bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
useextra = state->extravalid && state->args->whichfork == XFS_ATTR_FORK;
newcount = 1 + useextra;
if ((be16_to_cpu(node->hdr.count) + newcount) > state->node_ents) {
error = xfs_da_grow_inode(state->args, &blkno);
if (error)
return(error);
error = xfs_da_node_create(state->args, blkno, treelevel,
&newblk->bp, state->args->whichfork);
if (error)
return(error);
newblk->blkno = blkno;
newblk->magic = XFS_DA_NODE_MAGIC;
xfs_da_node_rebalance(state, oldblk, newblk);
error = xfs_da_blk_link(state, oldblk, newblk);
if (error)
return(error);
*result = 1;
} else {
*result = 0;
}
node = oldblk->bp->data;
if (oldblk->index <= be16_to_cpu(node->hdr.count)) {
oldblk->index++;
xfs_da_node_add(state, oldblk, addblk);
if (useextra) {
if (state->extraafter)
oldblk->index++;
xfs_da_node_add(state, oldblk, &state->extrablk);
state->extravalid = 0;
}
} else {
newblk->index++;
xfs_da_node_add(state, newblk, addblk);
if (useextra) {
if (state->extraafter)
newblk->index++;
xfs_da_node_add(state, newblk, &state->extrablk);
state->extravalid = 0;
}
}
return(0);
}
STATIC void
xfs_da_node_rebalance(xfs_da_state_t *state, xfs_da_state_blk_t *blk1,
xfs_da_state_blk_t *blk2)
{
xfs_da_intnode_t *node1, *node2, *tmpnode;
xfs_da_node_entry_t *btree_s, *btree_d;
int count, tmp;
xfs_trans_t *tp;
node1 = blk1->bp->data;
node2 = blk2->bp->data;
if ((be16_to_cpu(node1->hdr.count) > 0) && (be16_to_cpu(node2->hdr.count) > 0) &&
((be32_to_cpu(node2->btree[0].hashval) < be32_to_cpu(node1->btree[0].hashval)) ||
(be32_to_cpu(node2->btree[be16_to_cpu(node2->hdr.count)-1].hashval) <
be32_to_cpu(node1->btree[be16_to_cpu(node1->hdr.count)-1].hashval)))) {
tmpnode = node1;
node1 = node2;
node2 = tmpnode;
}
ASSERT(node1->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
ASSERT(node2->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
count = (be16_to_cpu(node1->hdr.count) - be16_to_cpu(node2->hdr.count)) / 2;
if (count == 0)
return;
tp = state->args->trans;
if (count > 0) {
if ((tmp = be16_to_cpu(node2->hdr.count)) > 0) {
tmp *= (uint)sizeof(xfs_da_node_entry_t);
btree_s = &node2->btree[0];
btree_d = &node2->btree[count];
memmove(btree_d, btree_s, tmp);
}
be16_add_cpu(&node2->hdr.count, count);
tmp = count * (uint)sizeof(xfs_da_node_entry_t);
btree_s = &node1->btree[be16_to_cpu(node1->hdr.count) - count];
btree_d = &node2->btree[0];
memcpy(btree_d, btree_s, tmp);
be16_add_cpu(&node1->hdr.count, -count);
} else {
count = -count;
tmp = count * (uint)sizeof(xfs_da_node_entry_t);
btree_s = &node2->btree[0];
btree_d = &node1->btree[be16_to_cpu(node1->hdr.count)];
memcpy(btree_d, btree_s, tmp);
be16_add_cpu(&node1->hdr.count, count);
xfs_da_log_buf(tp, blk1->bp,
XFS_DA_LOGRANGE(node1, btree_d, tmp));
tmp = be16_to_cpu(node2->hdr.count) - count;
tmp *= (uint)sizeof(xfs_da_node_entry_t);
btree_s = &node2->btree[count];
btree_d = &node2->btree[0];
memmove(btree_d, btree_s, tmp);
be16_add_cpu(&node2->hdr.count, -count);
}
xfs_da_log_buf(tp, blk1->bp,
XFS_DA_LOGRANGE(node1, &node1->hdr, sizeof(node1->hdr)));
xfs_da_log_buf(tp, blk2->bp,
XFS_DA_LOGRANGE(node2, &node2->hdr,
sizeof(node2->hdr) +
sizeof(node2->btree[0]) * be16_to_cpu(node2->hdr.count)));
node1 = blk1->bp->data;
node2 = blk2->bp->data;
blk1->hashval = be32_to_cpu(node1->btree[be16_to_cpu(node1->hdr.count)-1].hashval);
blk2->hashval = be32_to_cpu(node2->btree[be16_to_cpu(node2->hdr.count)-1].hashval);
if (blk1->index >= be16_to_cpu(node1->hdr.count)) {
blk2->index = blk1->index - be16_to_cpu(node1->hdr.count);
blk1->index = be16_to_cpu(node1->hdr.count) + 1;
}
}
STATIC void
xfs_da_node_add(xfs_da_state_t *state, xfs_da_state_blk_t *oldblk,
xfs_da_state_blk_t *newblk)
{
xfs_da_intnode_t *node;
xfs_da_node_entry_t *btree;
int tmp;
node = oldblk->bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
ASSERT((oldblk->index >= 0) && (oldblk->index <= be16_to_cpu(node->hdr.count)));
ASSERT(newblk->blkno != 0);
if (state->args->whichfork == XFS_DATA_FORK)
ASSERT(newblk->blkno >= state->mp->m_dirleafblk &&
newblk->blkno < state->mp->m_dirfreeblk);
tmp = 0;
btree = &node->btree[ oldblk->index ];
if (oldblk->index < be16_to_cpu(node->hdr.count)) {
tmp = (be16_to_cpu(node->hdr.count) - oldblk->index) * (uint)sizeof(*btree);
memmove(btree + 1, btree, tmp);
}
btree->hashval = cpu_to_be32(newblk->hashval);
btree->before = cpu_to_be32(newblk->blkno);
xfs_da_log_buf(state->args->trans, oldblk->bp,
XFS_DA_LOGRANGE(node, btree, tmp + sizeof(*btree)));
be16_add_cpu(&node->hdr.count, 1);
xfs_da_log_buf(state->args->trans, oldblk->bp,
XFS_DA_LOGRANGE(node, &node->hdr, sizeof(node->hdr)));
oldblk->hashval = be32_to_cpu(node->btree[be16_to_cpu(node->hdr.count)-1 ].hashval);
}
int
xfs_da_join(xfs_da_state_t *state)
{
xfs_da_state_blk_t *drop_blk, *save_blk;
int action, error;
action = 0;
drop_blk = &state->path.blk[ state->path.active-1 ];
save_blk = &state->altpath.blk[ state->path.active-1 ];
ASSERT(state->path.blk[0].magic == XFS_DA_NODE_MAGIC);
ASSERT(drop_blk->magic == XFS_ATTR_LEAF_MAGIC ||
drop_blk->magic == XFS_DIR2_LEAFN_MAGIC);
for ( ; state->path.active >= 2; drop_blk--, save_blk--,
state->path.active--) {
switch (drop_blk->magic) {
case XFS_ATTR_LEAF_MAGIC:
error = xfs_attr_leaf_toosmall(state, &action);
if (error)
return(error);
if (action == 0)
return(0);
xfs_attr_leaf_unbalance(state, drop_blk, save_blk);
break;
case XFS_DIR2_LEAFN_MAGIC:
error = xfs_dir2_leafn_toosmall(state, &action);
if (error)
return error;
if (action == 0)
return 0;
xfs_dir2_leafn_unbalance(state, drop_blk, save_blk);
break;
case XFS_DA_NODE_MAGIC:
xfs_da_node_remove(state, drop_blk);
xfs_da_fixhashpath(state, &state->path);
error = xfs_da_node_toosmall(state, &action);
if (error)
return(error);
if (action == 0)
return 0;
xfs_da_node_unbalance(state, drop_blk, save_blk);
break;
}
xfs_da_fixhashpath(state, &state->altpath);
error = xfs_da_blk_unlink(state, drop_blk, save_blk);
xfs_da_state_kill_altpath(state);
if (error)
return(error);
error = xfs_da_shrink_inode(state->args, drop_blk->blkno,
drop_blk->bp);
drop_blk->bp = NULL;
if (error)
return(error);
}
xfs_da_node_remove(state, drop_blk);
xfs_da_fixhashpath(state, &state->path);
error = xfs_da_root_join(state, &state->path.blk[0]);
return(error);
}
static void
xfs_da_blkinfo_onlychild_validate(struct xfs_da_blkinfo *blkinfo, __u16 level)
{
__be16 magic = blkinfo->magic;
if (level == 1) {
ASSERT(magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC) ||
magic == cpu_to_be16(XFS_ATTR_LEAF_MAGIC));
} else
ASSERT(magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
ASSERT(!blkinfo->forw);
ASSERT(!blkinfo->back);
}
STATIC int
xfs_da_root_join(xfs_da_state_t *state, xfs_da_state_blk_t *root_blk)
{
xfs_da_intnode_t *oldroot;
xfs_da_args_t *args;
xfs_dablk_t child;
xfs_dabuf_t *bp;
int error;
args = state->args;
ASSERT(args != NULL);
ASSERT(root_blk->magic == XFS_DA_NODE_MAGIC);
oldroot = root_blk->bp->data;
ASSERT(oldroot->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
ASSERT(!oldroot->hdr.info.forw);
ASSERT(!oldroot->hdr.info.back);
if (be16_to_cpu(oldroot->hdr.count) > 1)
return(0);
child = be32_to_cpu(oldroot->btree[0].before);
ASSERT(child != 0);
error = xfs_da_read_buf(args->trans, args->dp, child, -1, &bp,
args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
xfs_da_blkinfo_onlychild_validate(bp->data,
be16_to_cpu(oldroot->hdr.level));
memcpy(root_blk->bp->data, bp->data, state->blocksize);
xfs_da_log_buf(args->trans, root_blk->bp, 0, state->blocksize - 1);
error = xfs_da_shrink_inode(args, child, bp);
return(error);
}
STATIC int
xfs_da_node_toosmall(xfs_da_state_t *state, int *action)
{
xfs_da_intnode_t *node;
xfs_da_state_blk_t *blk;
xfs_da_blkinfo_t *info;
int count, forward, error, retval, i;
xfs_dablk_t blkno;
xfs_dabuf_t *bp;
blk = &state->path.blk[ state->path.active-1 ];
info = blk->bp->data;
ASSERT(info->magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
node = (xfs_da_intnode_t *)info;
count = be16_to_cpu(node->hdr.count);
if (count > (state->node_ents >> 1)) {
*action = 0;
return(0);
}
if (count == 0) {
forward = (info->forw != 0);
memcpy(&state->altpath, &state->path, sizeof(state->path));
error = xfs_da_path_shift(state, &state->altpath, forward,
0, &retval);
if (error)
return(error);
if (retval) {
*action = 0;
} else {
*action = 2;
}
return(0);
}
forward = (be32_to_cpu(info->forw) < be32_to_cpu(info->back));
for (i = 0; i < 2; forward = !forward, i++) {
if (forward)
blkno = be32_to_cpu(info->forw);
else
blkno = be32_to_cpu(info->back);
if (blkno == 0)
continue;
error = xfs_da_read_buf(state->args->trans, state->args->dp,
blkno, -1, &bp, state->args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
node = (xfs_da_intnode_t *)info;
count = state->node_ents;
count -= state->node_ents >> 2;
count -= be16_to_cpu(node->hdr.count);
node = bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
count -= be16_to_cpu(node->hdr.count);
xfs_da_brelse(state->args->trans, bp);
if (count >= 0)
break;
}
if (i >= 2) {
*action = 0;
return(0);
}
memcpy(&state->altpath, &state->path, sizeof(state->path));
if (blkno < blk->blkno) {
error = xfs_da_path_shift(state, &state->altpath, forward,
0, &retval);
if (error) {
return(error);
}
if (retval) {
*action = 0;
return(0);
}
} else {
error = xfs_da_path_shift(state, &state->path, forward,
0, &retval);
if (error) {
return(error);
}
if (retval) {
*action = 0;
return(0);
}
}
*action = 1;
return(0);
}
void
xfs_da_fixhashpath(xfs_da_state_t *state, xfs_da_state_path_t *path)
{
xfs_da_state_blk_t *blk;
xfs_da_intnode_t *node;
xfs_da_node_entry_t *btree;
xfs_dahash_t lasthash=0;
int level, count;
level = path->active-1;
blk = &path->blk[ level ];
switch (blk->magic) {
case XFS_ATTR_LEAF_MAGIC:
lasthash = xfs_attr_leaf_lasthash(blk->bp, &count);
if (count == 0)
return;
break;
case XFS_DIR2_LEAFN_MAGIC:
lasthash = xfs_dir2_leafn_lasthash(blk->bp, &count);
if (count == 0)
return;
break;
case XFS_DA_NODE_MAGIC:
lasthash = xfs_da_node_lasthash(blk->bp, &count);
if (count == 0)
return;
break;
}
for (blk--, level--; level >= 0; blk--, level--) {
node = blk->bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
btree = &node->btree[ blk->index ];
if (be32_to_cpu(btree->hashval) == lasthash)
break;
blk->hashval = lasthash;
btree->hashval = cpu_to_be32(lasthash);
xfs_da_log_buf(state->args->trans, blk->bp,
XFS_DA_LOGRANGE(node, btree, sizeof(*btree)));
lasthash = be32_to_cpu(node->btree[be16_to_cpu(node->hdr.count)-1].hashval);
}
}
STATIC void
xfs_da_node_remove(xfs_da_state_t *state, xfs_da_state_blk_t *drop_blk)
{
xfs_da_intnode_t *node;
xfs_da_node_entry_t *btree;
int tmp;
node = drop_blk->bp->data;
ASSERT(drop_blk->index < be16_to_cpu(node->hdr.count));
ASSERT(drop_blk->index >= 0);
btree = &node->btree[drop_blk->index];
if (drop_blk->index < (be16_to_cpu(node->hdr.count)-1)) {
tmp = be16_to_cpu(node->hdr.count) - drop_blk->index - 1;
tmp *= (uint)sizeof(xfs_da_node_entry_t);
memmove(btree, btree + 1, tmp);
xfs_da_log_buf(state->args->trans, drop_blk->bp,
XFS_DA_LOGRANGE(node, btree, tmp));
btree = &node->btree[be16_to_cpu(node->hdr.count)-1];
}
memset((char *)btree, 0, sizeof(xfs_da_node_entry_t));
xfs_da_log_buf(state->args->trans, drop_blk->bp,
XFS_DA_LOGRANGE(node, btree, sizeof(*btree)));
be16_add_cpu(&node->hdr.count, -1);
xfs_da_log_buf(state->args->trans, drop_blk->bp,
XFS_DA_LOGRANGE(node, &node->hdr, sizeof(node->hdr)));
btree--;
drop_blk->hashval = be32_to_cpu(btree->hashval);
}
STATIC void
xfs_da_node_unbalance(xfs_da_state_t *state, xfs_da_state_blk_t *drop_blk,
xfs_da_state_blk_t *save_blk)
{
xfs_da_intnode_t *drop_node, *save_node;
xfs_da_node_entry_t *btree;
int tmp;
xfs_trans_t *tp;
drop_node = drop_blk->bp->data;
save_node = save_blk->bp->data;
ASSERT(drop_node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
ASSERT(save_node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
tp = state->args->trans;
if ((be32_to_cpu(drop_node->btree[0].hashval) < be32_to_cpu(save_node->btree[ 0 ].hashval)) ||
(be32_to_cpu(drop_node->btree[be16_to_cpu(drop_node->hdr.count)-1].hashval) <
be32_to_cpu(save_node->btree[be16_to_cpu(save_node->hdr.count)-1].hashval)))
{
btree = &save_node->btree[be16_to_cpu(drop_node->hdr.count)];
tmp = be16_to_cpu(save_node->hdr.count) * (uint)sizeof(xfs_da_node_entry_t);
memmove(btree, &save_node->btree[0], tmp);
btree = &save_node->btree[0];
xfs_da_log_buf(tp, save_blk->bp,
XFS_DA_LOGRANGE(save_node, btree,
(be16_to_cpu(save_node->hdr.count) + be16_to_cpu(drop_node->hdr.count)) *
sizeof(xfs_da_node_entry_t)));
} else {
btree = &save_node->btree[be16_to_cpu(save_node->hdr.count)];
xfs_da_log_buf(tp, save_blk->bp,
XFS_DA_LOGRANGE(save_node, btree,
be16_to_cpu(drop_node->hdr.count) *
sizeof(xfs_da_node_entry_t)));
}
tmp = be16_to_cpu(drop_node->hdr.count) * (uint)sizeof(xfs_da_node_entry_t);
memcpy(btree, &drop_node->btree[0], tmp);
be16_add_cpu(&save_node->hdr.count, be16_to_cpu(drop_node->hdr.count));
xfs_da_log_buf(tp, save_blk->bp,
XFS_DA_LOGRANGE(save_node, &save_node->hdr,
sizeof(save_node->hdr)));
save_blk->hashval = be32_to_cpu(save_node->btree[be16_to_cpu(save_node->hdr.count)-1].hashval);
}
int
xfs_da_node_lookup_int(xfs_da_state_t *state, int *result)
{
xfs_da_state_blk_t *blk;
xfs_da_blkinfo_t *curr;
xfs_da_intnode_t *node;
xfs_da_node_entry_t *btree;
xfs_dablk_t blkno;
int probe, span, max, error, retval;
xfs_dahash_t hashval, btreehashval;
xfs_da_args_t *args;
args = state->args;
blkno = (args->whichfork == XFS_DATA_FORK)? state->mp->m_dirleafblk : 0;
for (blk = &state->path.blk[0], state->path.active = 1;
state->path.active <= XFS_DA_NODE_MAXDEPTH;
blk++, state->path.active++) {
blk->blkno = blkno;
error = xfs_da_read_buf(args->trans, args->dp, blkno,
-1, &blk->bp, args->whichfork);
if (error) {
blk->blkno = 0;
state->path.active--;
return(error);
}
curr = blk->bp->data;
blk->magic = be16_to_cpu(curr->magic);
ASSERT(blk->magic == XFS_DA_NODE_MAGIC ||
blk->magic == XFS_DIR2_LEAFN_MAGIC ||
blk->magic == XFS_ATTR_LEAF_MAGIC);
if (blk->magic == XFS_DA_NODE_MAGIC) {
node = blk->bp->data;
max = be16_to_cpu(node->hdr.count);
blk->hashval = be32_to_cpu(node->btree[max-1].hashval);
probe = span = max / 2;
hashval = args->hashval;
for (btree = &node->btree[probe]; span > 4;
btree = &node->btree[probe]) {
span /= 2;
btreehashval = be32_to_cpu(btree->hashval);
if (btreehashval < hashval)
probe += span;
else if (btreehashval > hashval)
probe -= span;
else
break;
}
ASSERT((probe >= 0) && (probe < max));
ASSERT((span <= 4) || (be32_to_cpu(btree->hashval) == hashval));
while ((probe > 0) && (be32_to_cpu(btree->hashval) >= hashval)) {
btree--;
probe--;
}
while ((probe < max) && (be32_to_cpu(btree->hashval) < hashval)) {
btree++;
probe++;
}
if (probe == max) {
blk->index = max-1;
blkno = be32_to_cpu(node->btree[max-1].before);
} else {
blk->index = probe;
blkno = be32_to_cpu(btree->before);
}
} else if (blk->magic == XFS_ATTR_LEAF_MAGIC) {
blk->hashval = xfs_attr_leaf_lasthash(blk->bp, NULL);
break;
} else if (blk->magic == XFS_DIR2_LEAFN_MAGIC) {
blk->hashval = xfs_dir2_leafn_lasthash(blk->bp, NULL);
break;
}
}
for (;;) {
if (blk->magic == XFS_DIR2_LEAFN_MAGIC) {
retval = xfs_dir2_leafn_lookup_int(blk->bp, args,
&blk->index, state);
} else if (blk->magic == XFS_ATTR_LEAF_MAGIC) {
retval = xfs_attr_leaf_lookup_int(blk->bp, args);
blk->index = args->index;
args->blkno = blk->blkno;
} else {
ASSERT(0);
return XFS_ERROR(EFSCORRUPTED);
}
if (((retval == ENOENT) || (retval == ENOATTR)) &&
(blk->hashval == args->hashval)) {
error = xfs_da_path_shift(state, &state->path, 1, 1,
&retval);
if (error)
return(error);
if (retval == 0) {
continue;
} else if (blk->magic == XFS_ATTR_LEAF_MAGIC) {
retval = XFS_ERROR(ENOATTR);
}
}
break;
}
*result = retval;
return(0);
}
int
xfs_da_blk_link(xfs_da_state_t *state, xfs_da_state_blk_t *old_blk,
xfs_da_state_blk_t *new_blk)
{
xfs_da_blkinfo_t *old_info, *new_info, *tmp_info;
xfs_da_args_t *args;
int before=0, error;
xfs_dabuf_t *bp;
args = state->args;
ASSERT(args != NULL);
old_info = old_blk->bp->data;
new_info = new_blk->bp->data;
ASSERT(old_blk->magic == XFS_DA_NODE_MAGIC ||
old_blk->magic == XFS_DIR2_LEAFN_MAGIC ||
old_blk->magic == XFS_ATTR_LEAF_MAGIC);
ASSERT(old_blk->magic == be16_to_cpu(old_info->magic));
ASSERT(new_blk->magic == be16_to_cpu(new_info->magic));
ASSERT(old_blk->magic == new_blk->magic);
switch (old_blk->magic) {
case XFS_ATTR_LEAF_MAGIC:
before = xfs_attr_leaf_order(old_blk->bp, new_blk->bp);
break;
case XFS_DIR2_LEAFN_MAGIC:
before = xfs_dir2_leafn_order(old_blk->bp, new_blk->bp);
break;
case XFS_DA_NODE_MAGIC:
before = xfs_da_node_order(old_blk->bp, new_blk->bp);
break;
}
if (before) {
new_info->forw = cpu_to_be32(old_blk->blkno);
new_info->back = old_info->back;
if (old_info->back) {
error = xfs_da_read_buf(args->trans, args->dp,
be32_to_cpu(old_info->back),
-1, &bp, args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
tmp_info = bp->data;
ASSERT(be16_to_cpu(tmp_info->magic) == be16_to_cpu(old_info->magic));
ASSERT(be32_to_cpu(tmp_info->forw) == old_blk->blkno);
tmp_info->forw = cpu_to_be32(new_blk->blkno);
xfs_da_log_buf(args->trans, bp, 0, sizeof(*tmp_info)-1);
xfs_da_buf_done(bp);
}
old_info->back = cpu_to_be32(new_blk->blkno);
} else {
new_info->forw = old_info->forw;
new_info->back = cpu_to_be32(old_blk->blkno);
if (old_info->forw) {
error = xfs_da_read_buf(args->trans, args->dp,
be32_to_cpu(old_info->forw),
-1, &bp, args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
tmp_info = bp->data;
ASSERT(tmp_info->magic == old_info->magic);
ASSERT(be32_to_cpu(tmp_info->back) == old_blk->blkno);
tmp_info->back = cpu_to_be32(new_blk->blkno);
xfs_da_log_buf(args->trans, bp, 0, sizeof(*tmp_info)-1);
xfs_da_buf_done(bp);
}
old_info->forw = cpu_to_be32(new_blk->blkno);
}
xfs_da_log_buf(args->trans, old_blk->bp, 0, sizeof(*tmp_info) - 1);
xfs_da_log_buf(args->trans, new_blk->bp, 0, sizeof(*tmp_info) - 1);
return(0);
}
STATIC int
xfs_da_node_order(xfs_dabuf_t *node1_bp, xfs_dabuf_t *node2_bp)
{
xfs_da_intnode_t *node1, *node2;
node1 = node1_bp->data;
node2 = node2_bp->data;
ASSERT(node1->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC) &&
node2->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
if ((be16_to_cpu(node1->hdr.count) > 0) && (be16_to_cpu(node2->hdr.count) > 0) &&
((be32_to_cpu(node2->btree[0].hashval) <
be32_to_cpu(node1->btree[0].hashval)) ||
(be32_to_cpu(node2->btree[be16_to_cpu(node2->hdr.count)-1].hashval) <
be32_to_cpu(node1->btree[be16_to_cpu(node1->hdr.count)-1].hashval)))) {
return(1);
}
return(0);
}
STATIC uint
xfs_da_node_lasthash(xfs_dabuf_t *bp, int *count)
{
xfs_da_intnode_t *node;
node = bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
if (count)
*count = be16_to_cpu(node->hdr.count);
if (!node->hdr.count)
return(0);
return be32_to_cpu(node->btree[be16_to_cpu(node->hdr.count)-1].hashval);
}
STATIC int
xfs_da_blk_unlink(xfs_da_state_t *state, xfs_da_state_blk_t *drop_blk,
xfs_da_state_blk_t *save_blk)
{
xfs_da_blkinfo_t *drop_info, *save_info, *tmp_info;
xfs_da_args_t *args;
xfs_dabuf_t *bp;
int error;
args = state->args;
ASSERT(args != NULL);
save_info = save_blk->bp->data;
drop_info = drop_blk->bp->data;
ASSERT(save_blk->magic == XFS_DA_NODE_MAGIC ||
save_blk->magic == XFS_DIR2_LEAFN_MAGIC ||
save_blk->magic == XFS_ATTR_LEAF_MAGIC);
ASSERT(save_blk->magic == be16_to_cpu(save_info->magic));
ASSERT(drop_blk->magic == be16_to_cpu(drop_info->magic));
ASSERT(save_blk->magic == drop_blk->magic);
ASSERT((be32_to_cpu(save_info->forw) == drop_blk->blkno) ||
(be32_to_cpu(save_info->back) == drop_blk->blkno));
ASSERT((be32_to_cpu(drop_info->forw) == save_blk->blkno) ||
(be32_to_cpu(drop_info->back) == save_blk->blkno));
if (be32_to_cpu(save_info->back) == drop_blk->blkno) {
save_info->back = drop_info->back;
if (drop_info->back) {
error = xfs_da_read_buf(args->trans, args->dp,
be32_to_cpu(drop_info->back),
-1, &bp, args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
tmp_info = bp->data;
ASSERT(tmp_info->magic == save_info->magic);
ASSERT(be32_to_cpu(tmp_info->forw) == drop_blk->blkno);
tmp_info->forw = cpu_to_be32(save_blk->blkno);
xfs_da_log_buf(args->trans, bp, 0,
sizeof(*tmp_info) - 1);
xfs_da_buf_done(bp);
}
} else {
save_info->forw = drop_info->forw;
if (drop_info->forw) {
error = xfs_da_read_buf(args->trans, args->dp,
be32_to_cpu(drop_info->forw),
-1, &bp, args->whichfork);
if (error)
return(error);
ASSERT(bp != NULL);
tmp_info = bp->data;
ASSERT(tmp_info->magic == save_info->magic);
ASSERT(be32_to_cpu(tmp_info->back) == drop_blk->blkno);
tmp_info->back = cpu_to_be32(save_blk->blkno);
xfs_da_log_buf(args->trans, bp, 0,
sizeof(*tmp_info) - 1);
xfs_da_buf_done(bp);
}
}
xfs_da_log_buf(args->trans, save_blk->bp, 0, sizeof(*save_info) - 1);
return(0);
}
int
xfs_da_path_shift(xfs_da_state_t *state, xfs_da_state_path_t *path,
int forward, int release, int *result)
{
xfs_da_state_blk_t *blk;
xfs_da_blkinfo_t *info;
xfs_da_intnode_t *node;
xfs_da_args_t *args;
xfs_dablk_t blkno=0;
int level, error;
args = state->args;
ASSERT(args != NULL);
ASSERT(path != NULL);
ASSERT((path->active > 0) && (path->active < XFS_DA_NODE_MAXDEPTH));
level = (path->active-1) - 1;
for (blk = &path->blk[level]; level >= 0; blk--, level--) {
ASSERT(blk->bp != NULL);
node = blk->bp->data;
ASSERT(node->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
if (forward && (blk->index < be16_to_cpu(node->hdr.count)-1)) {
blk->index++;
blkno = be32_to_cpu(node->btree[blk->index].before);
break;
} else if (!forward && (blk->index > 0)) {
blk->index--;
blkno = be32_to_cpu(node->btree[blk->index].before);
break;
}
}
if (level < 0) {
*result = XFS_ERROR(ENOENT);
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
return(0);
}
for (blk++, level++; level < path->active; blk++, level++) {
if (release)
xfs_da_brelse(args->trans, blk->bp);
blk->blkno = blkno;
error = xfs_da_read_buf(args->trans, args->dp, blkno, -1,
&blk->bp, args->whichfork);
if (error)
return(error);
ASSERT(blk->bp != NULL);
info = blk->bp->data;
ASSERT(info->magic == cpu_to_be16(XFS_DA_NODE_MAGIC) ||
info->magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC) ||
info->magic == cpu_to_be16(XFS_ATTR_LEAF_MAGIC));
blk->magic = be16_to_cpu(info->magic);
if (blk->magic == XFS_DA_NODE_MAGIC) {
node = (xfs_da_intnode_t *)info;
blk->hashval = be32_to_cpu(node->btree[be16_to_cpu(node->hdr.count)-1].hashval);
if (forward)
blk->index = 0;
else
blk->index = be16_to_cpu(node->hdr.count)-1;
blkno = be32_to_cpu(node->btree[blk->index].before);
} else {
ASSERT(level == path->active-1);
blk->index = 0;
switch(blk->magic) {
case XFS_ATTR_LEAF_MAGIC:
blk->hashval = xfs_attr_leaf_lasthash(blk->bp,
NULL);
break;
case XFS_DIR2_LEAFN_MAGIC:
blk->hashval = xfs_dir2_leafn_lasthash(blk->bp,
NULL);
break;
default:
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC ||
blk->magic == XFS_DIR2_LEAFN_MAGIC);
break;
}
}
}
*result = 0;
return(0);
}
xfs_dahash_t
xfs_da_hashname(const __uint8_t *name, int namelen)
{
xfs_dahash_t hash;
for (hash = 0; namelen >= 4; namelen -= 4, name += 4)
hash = (name[0] << 21) ^ (name[1] << 14) ^ (name[2] << 7) ^
(name[3] << 0) ^ rol32(hash, 7 * 4);
switch (namelen) {
case 3:
return (name[0] << 14) ^ (name[1] << 7) ^ (name[2] << 0) ^
rol32(hash, 7 * 3);
case 2:
return (name[0] << 7) ^ (name[1] << 0) ^ rol32(hash, 7 * 2);
case 1:
return (name[0] << 0) ^ rol32(hash, 7 * 1);
default:
return hash;
}
}
enum xfs_dacmp
xfs_da_compname(
struct xfs_da_args *args,
const unsigned char *name,
int len)
{
return (args->namelen == len && memcmp(args->name, name, len) == 0) ?
XFS_CMP_EXACT : XFS_CMP_DIFFERENT;
}
static xfs_dahash_t
xfs_default_hashname(
struct xfs_name *name)
{
return xfs_da_hashname(name->name, name->len);
}
int
xfs_da_grow_inode_int(
struct xfs_da_args *args,
xfs_fileoff_t *bno,
int count)
{
struct xfs_trans *tp = args->trans;
struct xfs_inode *dp = args->dp;
int w = args->whichfork;
xfs_drfsbno_t nblks = dp->i_d.di_nblocks;
struct xfs_bmbt_irec map, *mapp;
int nmap, error, got, i, mapi;
error = xfs_bmap_first_unused(tp, dp, count, bno, w);
if (error)
return error;
nmap = 1;
ASSERT(args->firstblock != NULL);
error = xfs_bmapi_write(tp, dp, *bno, count,
xfs_bmapi_aflag(w)|XFS_BMAPI_METADATA|XFS_BMAPI_CONTIG,
args->firstblock, args->total, &map, &nmap,
args->flist);
if (error)
return error;
ASSERT(nmap <= 1);
if (nmap == 1) {
mapp = &map;
mapi = 1;
} else if (nmap == 0 && count > 1) {
xfs_fileoff_t b;
int c;
mapp = kmem_alloc(sizeof(*mapp) * count, KM_SLEEP);
for (b = *bno, mapi = 0; b < *bno + count; ) {
nmap = MIN(XFS_BMAP_MAX_NMAP, count);
c = (int)(*bno + count - b);
error = xfs_bmapi_write(tp, dp, b, c,
xfs_bmapi_aflag(w)|XFS_BMAPI_METADATA,
args->firstblock, args->total,
&mapp[mapi], &nmap, args->flist);
if (error)
goto out_free_map;
if (nmap < 1)
break;
mapi += nmap;
b = mapp[mapi - 1].br_startoff +
mapp[mapi - 1].br_blockcount;
}
} else {
mapi = 0;
mapp = NULL;
}
for (i = 0, got = 0; i < mapi; i++)
got += mapp[i].br_blockcount;
if (got != count || mapp[0].br_startoff != *bno ||
mapp[mapi - 1].br_startoff + mapp[mapi - 1].br_blockcount !=
*bno + count) {
error = XFS_ERROR(ENOSPC);
goto out_free_map;
}
args->total -= dp->i_d.di_nblocks - nblks;
out_free_map:
if (mapp != &map)
kmem_free(mapp);
return error;
}
int
xfs_da_grow_inode(
struct xfs_da_args *args,
xfs_dablk_t *new_blkno)
{
xfs_fileoff_t bno;
int count;
int error;
if (args->whichfork == XFS_DATA_FORK) {
bno = args->dp->i_mount->m_dirleafblk;
count = args->dp->i_mount->m_dirblkfsbs;
} else {
bno = 0;
count = 1;
}
error = xfs_da_grow_inode_int(args, &bno, count);
if (!error)
*new_blkno = (xfs_dablk_t)bno;
return error;
}
STATIC int
xfs_da_swap_lastblock(xfs_da_args_t *args, xfs_dablk_t *dead_blknop,
xfs_dabuf_t **dead_bufp)
{
xfs_dablk_t dead_blkno, last_blkno, sib_blkno, par_blkno;
xfs_dabuf_t *dead_buf, *last_buf, *sib_buf, *par_buf;
xfs_fileoff_t lastoff;
xfs_inode_t *ip;
xfs_trans_t *tp;
xfs_mount_t *mp;
int error, w, entno, level, dead_level;
xfs_da_blkinfo_t *dead_info, *sib_info;
xfs_da_intnode_t *par_node, *dead_node;
xfs_dir2_leaf_t *dead_leaf2;
xfs_dahash_t dead_hash;
dead_buf = *dead_bufp;
dead_blkno = *dead_blknop;
tp = args->trans;
ip = args->dp;
w = args->whichfork;
ASSERT(w == XFS_DATA_FORK);
mp = ip->i_mount;
lastoff = mp->m_dirfreeblk;
error = xfs_bmap_last_before(tp, ip, &lastoff, w);
if (error)
return error;
if (unlikely(lastoff == 0)) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(1)", XFS_ERRLEVEL_LOW,
mp);
return XFS_ERROR(EFSCORRUPTED);
}
last_blkno = (xfs_dablk_t)lastoff - mp->m_dirblkfsbs;
if ((error = xfs_da_read_buf(tp, ip, last_blkno, -1, &last_buf, w)))
return error;
memcpy(dead_buf->data, last_buf->data, mp->m_dirblksize);
xfs_da_log_buf(tp, dead_buf, 0, mp->m_dirblksize - 1);
dead_info = dead_buf->data;
if (dead_info->magic == cpu_to_be16(XFS_DIR2_LEAFN_MAGIC)) {
dead_leaf2 = (xfs_dir2_leaf_t *)dead_info;
dead_level = 0;
dead_hash = be32_to_cpu(dead_leaf2->ents[be16_to_cpu(dead_leaf2->hdr.count) - 1].hashval);
} else {
ASSERT(dead_info->magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
dead_node = (xfs_da_intnode_t *)dead_info;
dead_level = be16_to_cpu(dead_node->hdr.level);
dead_hash = be32_to_cpu(dead_node->btree[be16_to_cpu(dead_node->hdr.count) - 1].hashval);
}
sib_buf = par_buf = NULL;
if ((sib_blkno = be32_to_cpu(dead_info->back))) {
if ((error = xfs_da_read_buf(tp, ip, sib_blkno, -1, &sib_buf, w)))
goto done;
sib_info = sib_buf->data;
if (unlikely(
be32_to_cpu(sib_info->forw) != last_blkno ||
sib_info->magic != dead_info->magic)) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(2)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
sib_info->forw = cpu_to_be32(dead_blkno);
xfs_da_log_buf(tp, sib_buf,
XFS_DA_LOGRANGE(sib_info, &sib_info->forw,
sizeof(sib_info->forw)));
xfs_da_buf_done(sib_buf);
sib_buf = NULL;
}
if ((sib_blkno = be32_to_cpu(dead_info->forw))) {
if ((error = xfs_da_read_buf(tp, ip, sib_blkno, -1, &sib_buf, w)))
goto done;
sib_info = sib_buf->data;
if (unlikely(
be32_to_cpu(sib_info->back) != last_blkno ||
sib_info->magic != dead_info->magic)) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(3)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
sib_info->back = cpu_to_be32(dead_blkno);
xfs_da_log_buf(tp, sib_buf,
XFS_DA_LOGRANGE(sib_info, &sib_info->back,
sizeof(sib_info->back)));
xfs_da_buf_done(sib_buf);
sib_buf = NULL;
}
par_blkno = mp->m_dirleafblk;
level = -1;
for (;;) {
if ((error = xfs_da_read_buf(tp, ip, par_blkno, -1, &par_buf, w)))
goto done;
par_node = par_buf->data;
if (unlikely(par_node->hdr.info.magic !=
cpu_to_be16(XFS_DA_NODE_MAGIC) ||
(level >= 0 && level != be16_to_cpu(par_node->hdr.level) + 1))) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(4)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
level = be16_to_cpu(par_node->hdr.level);
for (entno = 0;
entno < be16_to_cpu(par_node->hdr.count) &&
be32_to_cpu(par_node->btree[entno].hashval) < dead_hash;
entno++)
continue;
if (unlikely(entno == be16_to_cpu(par_node->hdr.count))) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(5)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
par_blkno = be32_to_cpu(par_node->btree[entno].before);
if (level == dead_level + 1)
break;
xfs_da_brelse(tp, par_buf);
par_buf = NULL;
}
for (;;) {
for (;
entno < be16_to_cpu(par_node->hdr.count) &&
be32_to_cpu(par_node->btree[entno].before) != last_blkno;
entno++)
continue;
if (entno < be16_to_cpu(par_node->hdr.count))
break;
par_blkno = be32_to_cpu(par_node->hdr.info.forw);
xfs_da_brelse(tp, par_buf);
par_buf = NULL;
if (unlikely(par_blkno == 0)) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(6)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
if ((error = xfs_da_read_buf(tp, ip, par_blkno, -1, &par_buf, w)))
goto done;
par_node = par_buf->data;
if (unlikely(
be16_to_cpu(par_node->hdr.level) != level ||
par_node->hdr.info.magic != cpu_to_be16(XFS_DA_NODE_MAGIC))) {
XFS_ERROR_REPORT("xfs_da_swap_lastblock(7)",
XFS_ERRLEVEL_LOW, mp);
error = XFS_ERROR(EFSCORRUPTED);
goto done;
}
entno = 0;
}
par_node->btree[entno].before = cpu_to_be32(dead_blkno);
xfs_da_log_buf(tp, par_buf,
XFS_DA_LOGRANGE(par_node, &par_node->btree[entno].before,
sizeof(par_node->btree[entno].before)));
xfs_da_buf_done(par_buf);
xfs_da_buf_done(dead_buf);
*dead_blknop = last_blkno;
*dead_bufp = last_buf;
return 0;
done:
if (par_buf)
xfs_da_brelse(tp, par_buf);
if (sib_buf)
xfs_da_brelse(tp, sib_buf);
xfs_da_brelse(tp, last_buf);
return error;
}
int
xfs_da_shrink_inode(xfs_da_args_t *args, xfs_dablk_t dead_blkno,
xfs_dabuf_t *dead_buf)
{
xfs_inode_t *dp;
int done, error, w, count;
xfs_trans_t *tp;
xfs_mount_t *mp;
dp = args->dp;
w = args->whichfork;
tp = args->trans;
mp = dp->i_mount;
if (w == XFS_DATA_FORK)
count = mp->m_dirblkfsbs;
else
count = 1;
for (;;) {
if ((error = xfs_bunmapi(tp, dp, dead_blkno, count,
xfs_bmapi_aflag(w)|XFS_BMAPI_METADATA,
0, args->firstblock, args->flist,
&done)) == ENOSPC) {
if (w != XFS_DATA_FORK)
break;
if ((error = xfs_da_swap_lastblock(args, &dead_blkno,
&dead_buf)))
break;
} else {
break;
}
}
xfs_da_binval(tp, dead_buf);
return error;
}
STATIC int
xfs_da_map_covers_blocks(
int nmap,
xfs_bmbt_irec_t *mapp,
xfs_dablk_t bno,
int count)
{
int i;
xfs_fileoff_t off;
for (i = 0, off = bno; i < nmap; i++) {
if (mapp[i].br_startblock == HOLESTARTBLOCK ||
mapp[i].br_startblock == DELAYSTARTBLOCK) {
return 0;
}
if (off != mapp[i].br_startoff) {
return 0;
}
off += mapp[i].br_blockcount;
}
return off == bno + count;
}
STATIC int
xfs_da_do_buf(
xfs_trans_t *trans,
xfs_inode_t *dp,
xfs_dablk_t bno,
xfs_daddr_t *mappedbnop,
xfs_dabuf_t **bpp,
int whichfork,
int caller)
{
xfs_buf_t *bp = NULL;
xfs_buf_t **bplist;
int error=0;
int i;
xfs_bmbt_irec_t map;
xfs_bmbt_irec_t *mapp;
xfs_daddr_t mappedbno;
xfs_mount_t *mp;
int nbplist=0;
int nfsb;
int nmap;
xfs_dabuf_t *rbp;
mp = dp->i_mount;
nfsb = (whichfork == XFS_DATA_FORK) ? mp->m_dirblkfsbs : 1;
mappedbno = *mappedbnop;
if (mappedbno == -1 || mappedbno == -2) {
if (nfsb == 1)
mapp = &map;
else
mapp = kmem_alloc(sizeof(*mapp) * nfsb, KM_SLEEP);
nmap = nfsb;
error = xfs_bmapi_read(dp, (xfs_fileoff_t)bno, nfsb, mapp,
&nmap, xfs_bmapi_aflag(whichfork));
if (error)
goto exit0;
} else {
map.br_startblock = XFS_DADDR_TO_FSB(mp, mappedbno);
map.br_startoff = (xfs_fileoff_t)bno;
map.br_blockcount = nfsb;
mapp = &map;
nmap = 1;
}
if (!xfs_da_map_covers_blocks(nmap, mapp, bno, nfsb)) {
error = mappedbno == -2 ? 0 : XFS_ERROR(EFSCORRUPTED);
if (unlikely(error == EFSCORRUPTED)) {
if (xfs_error_level >= XFS_ERRLEVEL_LOW) {
xfs_alert(mp, "%s: bno %lld dir: inode %lld",
__func__, (long long)bno,
(long long)dp->i_ino);
for (i = 0; i < nmap; i++) {
xfs_alert(mp,
"[%02d] br_startoff %lld br_startblock %lld br_blockcount %lld br_state %d",
i,
(long long)mapp[i].br_startoff,
(long long)mapp[i].br_startblock,
(long long)mapp[i].br_blockcount,
mapp[i].br_state);
}
}
XFS_ERROR_REPORT("xfs_da_do_buf(1)",
XFS_ERRLEVEL_LOW, mp);
}
goto exit0;
}
if (caller != 3 && nmap > 1) {
bplist = kmem_alloc(sizeof(*bplist) * nmap, KM_SLEEP);
nbplist = 0;
} else
bplist = NULL;
for (i = 0; i < nmap; i++) {
int nmapped;
mappedbno = XFS_FSB_TO_DADDR(mp, mapp[i].br_startblock);
if (i == 0)
*mappedbnop = mappedbno;
nmapped = (int)XFS_FSB_TO_BB(mp, mapp[i].br_blockcount);
switch (caller) {
case 0:
bp = xfs_trans_get_buf(trans, mp->m_ddev_targp,
mappedbno, nmapped, 0);
error = bp ? bp->b_error : XFS_ERROR(EIO);
break;
case 1:
case 2:
bp = NULL;
error = xfs_trans_read_buf(mp, trans, mp->m_ddev_targp,
mappedbno, nmapped, 0, &bp);
break;
case 3:
xfs_buf_readahead(mp->m_ddev_targp, mappedbno, nmapped);
error = 0;
bp = NULL;
break;
}
if (error) {
if (bp)
xfs_trans_brelse(trans, bp);
goto exit1;
}
if (!bp)
continue;
if (caller == 1) {
if (whichfork == XFS_ATTR_FORK)
xfs_buf_set_ref(bp, XFS_ATTR_BTREE_REF);
else
xfs_buf_set_ref(bp, XFS_DIR_BTREE_REF);
}
if (bplist) {
bplist[nbplist++] = bp;
}
}
if (bplist) {
rbp = xfs_da_buf_make(nbplist, bplist);
} else if (bp)
rbp = xfs_da_buf_make(1, &bp);
else
rbp = NULL;
if (caller == 1) {
xfs_dir2_data_hdr_t *hdr = rbp->data;
xfs_dir2_free_t *free = rbp->data;
xfs_da_blkinfo_t *info = rbp->data;
uint magic, magic1;
magic = be16_to_cpu(info->magic);
magic1 = be32_to_cpu(hdr->magic);
if (unlikely(
XFS_TEST_ERROR((magic != XFS_DA_NODE_MAGIC) &&
(magic != XFS_ATTR_LEAF_MAGIC) &&
(magic != XFS_DIR2_LEAF1_MAGIC) &&
(magic != XFS_DIR2_LEAFN_MAGIC) &&
(magic1 != XFS_DIR2_BLOCK_MAGIC) &&
(magic1 != XFS_DIR2_DATA_MAGIC) &&
(free->hdr.magic != cpu_to_be32(XFS_DIR2_FREE_MAGIC)),
mp, XFS_ERRTAG_DA_READ_BUF,
XFS_RANDOM_DA_READ_BUF))) {
trace_xfs_da_btree_corrupt(rbp->bps[0], _RET_IP_);
XFS_CORRUPTION_ERROR("xfs_da_do_buf(2)",
XFS_ERRLEVEL_LOW, mp, info);
error = XFS_ERROR(EFSCORRUPTED);
xfs_da_brelse(trans, rbp);
nbplist = 0;
goto exit1;
}
}
if (bplist) {
kmem_free(bplist);
}
if (mapp != &map) {
kmem_free(mapp);
}
if (bpp)
*bpp = rbp;
return 0;
exit1:
if (bplist) {
for (i = 0; i < nbplist; i++)
xfs_trans_brelse(trans, bplist[i]);
kmem_free(bplist);
}
exit0:
if (mapp != &map)
kmem_free(mapp);
if (bpp)
*bpp = NULL;
return error;
}
int
xfs_da_get_buf(
xfs_trans_t *trans,
xfs_inode_t *dp,
xfs_dablk_t bno,
xfs_daddr_t mappedbno,
xfs_dabuf_t **bpp,
int whichfork)
{
return xfs_da_do_buf(trans, dp, bno, &mappedbno, bpp, whichfork, 0);
}
int
xfs_da_read_buf(
xfs_trans_t *trans,
xfs_inode_t *dp,
xfs_dablk_t bno,
xfs_daddr_t mappedbno,
xfs_dabuf_t **bpp,
int whichfork)
{
return xfs_da_do_buf(trans, dp, bno, &mappedbno, bpp, whichfork, 1);
}
xfs_daddr_t
xfs_da_reada_buf(
xfs_trans_t *trans,
xfs_inode_t *dp,
xfs_dablk_t bno,
int whichfork)
{
xfs_daddr_t rval;
rval = -1;
if (xfs_da_do_buf(trans, dp, bno, &rval, NULL, whichfork, 3))
return -1;
else
return rval;
}
xfs_da_state_t *
xfs_da_state_alloc(void)
{
return kmem_zone_zalloc(xfs_da_state_zone, KM_NOFS);
}
STATIC void
xfs_da_state_kill_altpath(xfs_da_state_t *state)
{
int i;
for (i = 0; i < state->altpath.active; i++) {
if (state->altpath.blk[i].bp) {
if (state->altpath.blk[i].bp != state->path.blk[i].bp)
xfs_da_buf_done(state->altpath.blk[i].bp);
state->altpath.blk[i].bp = NULL;
}
}
state->altpath.active = 0;
}
void
xfs_da_state_free(xfs_da_state_t *state)
{
int i;
xfs_da_state_kill_altpath(state);
for (i = 0; i < state->path.active; i++) {
if (state->path.blk[i].bp)
xfs_da_buf_done(state->path.blk[i].bp);
}
if (state->extravalid && state->extrablk.bp)
xfs_da_buf_done(state->extrablk.bp);
#ifdef DEBUG
memset((char *)state, 0, sizeof(*state));
#endif
kmem_zone_free(xfs_da_state_zone, state);
}
STATIC xfs_dabuf_t *
xfs_da_buf_make(int nbuf, xfs_buf_t **bps)
{
xfs_buf_t *bp;
xfs_dabuf_t *dabuf;
int i;
int off;
if (nbuf == 1)
dabuf = kmem_zone_alloc(xfs_dabuf_zone, KM_NOFS);
else
dabuf = kmem_alloc(XFS_DA_BUF_SIZE(nbuf), KM_NOFS);
dabuf->dirty = 0;
if (nbuf == 1) {
dabuf->nbuf = 1;
bp = bps[0];
dabuf->bbcount = (short)BTOBB(XFS_BUF_COUNT(bp));
dabuf->data = bp->b_addr;
dabuf->bps[0] = bp;
} else {
dabuf->nbuf = nbuf;
for (i = 0, dabuf->bbcount = 0; i < nbuf; i++) {
dabuf->bps[i] = bp = bps[i];
dabuf->bbcount += BTOBB(XFS_BUF_COUNT(bp));
}
dabuf->data = kmem_alloc(BBTOB(dabuf->bbcount), KM_SLEEP);
for (i = off = 0; i < nbuf; i++, off += XFS_BUF_COUNT(bp)) {
bp = bps[i];
memcpy((char *)dabuf->data + off, bp->b_addr,
XFS_BUF_COUNT(bp));
}
}
return dabuf;
}
STATIC void
xfs_da_buf_clean(xfs_dabuf_t *dabuf)
{
xfs_buf_t *bp;
int i;
int off;
if (dabuf->dirty) {
ASSERT(dabuf->nbuf > 1);
dabuf->dirty = 0;
for (i = off = 0; i < dabuf->nbuf;
i++, off += XFS_BUF_COUNT(bp)) {
bp = dabuf->bps[i];
memcpy(bp->b_addr, dabuf->data + off,
XFS_BUF_COUNT(bp));
}
}
}
void
xfs_da_buf_done(xfs_dabuf_t *dabuf)
{
ASSERT(dabuf);
ASSERT(dabuf->nbuf && dabuf->data && dabuf->bbcount && dabuf->bps[0]);
if (dabuf->dirty)
xfs_da_buf_clean(dabuf);
if (dabuf->nbuf > 1) {
kmem_free(dabuf->data);
kmem_free(dabuf);
} else {
kmem_zone_free(xfs_dabuf_zone, dabuf);
}
}
void
xfs_da_log_buf(xfs_trans_t *tp, xfs_dabuf_t *dabuf, uint first, uint last)
{
xfs_buf_t *bp;
uint f;
int i;
uint l;
int off;
ASSERT(dabuf->nbuf && dabuf->data && dabuf->bbcount && dabuf->bps[0]);
if (dabuf->nbuf == 1) {
ASSERT(dabuf->data == dabuf->bps[0]->b_addr);
xfs_trans_log_buf(tp, dabuf->bps[0], first, last);
return;
}
dabuf->dirty = 1;
ASSERT(first <= last);
for (i = off = 0; i < dabuf->nbuf; i++, off += XFS_BUF_COUNT(bp)) {
bp = dabuf->bps[i];
f = off;
l = f + XFS_BUF_COUNT(bp) - 1;
if (f < first)
f = first;
if (l > last)
l = last;
if (f <= l)
xfs_trans_log_buf(tp, bp, f - off, l - off);
else if (!(XFS_BUF_ISDONE(bp)))
XFS_BUF_DONE(bp);
}
ASSERT(last < off);
}
void
xfs_da_brelse(xfs_trans_t *tp, xfs_dabuf_t *dabuf)
{
xfs_buf_t *bp;
xfs_buf_t **bplist;
int i;
int nbuf;
ASSERT(dabuf->nbuf && dabuf->data && dabuf->bbcount && dabuf->bps[0]);
if ((nbuf = dabuf->nbuf) == 1) {
bplist = &bp;
bp = dabuf->bps[0];
} else {
bplist = kmem_alloc(nbuf * sizeof(*bplist), KM_SLEEP);
memcpy(bplist, dabuf->bps, nbuf * sizeof(*bplist));
}
xfs_da_buf_done(dabuf);
for (i = 0; i < nbuf; i++)
xfs_trans_brelse(tp, bplist[i]);
if (bplist != &bp)
kmem_free(bplist);
}
void
xfs_da_binval(xfs_trans_t *tp, xfs_dabuf_t *dabuf)
{
xfs_buf_t *bp;
xfs_buf_t **bplist;
int i;
int nbuf;
ASSERT(dabuf->nbuf && dabuf->data && dabuf->bbcount && dabuf->bps[0]);
if ((nbuf = dabuf->nbuf) == 1) {
bplist = &bp;
bp = dabuf->bps[0];
} else {
bplist = kmem_alloc(nbuf * sizeof(*bplist), KM_SLEEP);
memcpy(bplist, dabuf->bps, nbuf * sizeof(*bplist));
}
xfs_da_buf_done(dabuf);
for (i = 0; i < nbuf; i++)
xfs_trans_binval(tp, bplist[i]);
if (bplist != &bp)
kmem_free(bplist);
}
xfs_daddr_t
xfs_da_blkno(xfs_dabuf_t *dabuf)
{
ASSERT(dabuf->nbuf);
ASSERT(dabuf->data);
return XFS_BUF_ADDR(dabuf->bps[0]);
}
