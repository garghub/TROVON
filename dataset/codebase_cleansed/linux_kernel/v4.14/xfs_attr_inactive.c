STATIC int
xfs_attr3_leaf_freextent(
struct xfs_trans **trans,
struct xfs_inode *dp,
xfs_dablk_t blkno,
int blkcnt)
{
struct xfs_bmbt_irec map;
struct xfs_buf *bp;
xfs_dablk_t tblkno;
xfs_daddr_t dblkno;
int tblkcnt;
int dblkcnt;
int nmap;
int error;
tblkno = blkno;
tblkcnt = blkcnt;
while (tblkcnt > 0) {
nmap = 1;
error = xfs_bmapi_read(dp, (xfs_fileoff_t)tblkno, tblkcnt,
&map, &nmap, XFS_BMAPI_ATTRFORK);
if (error) {
return error;
}
ASSERT(nmap == 1);
ASSERT(map.br_startblock != DELAYSTARTBLOCK);
if (map.br_startblock != HOLESTARTBLOCK) {
dblkno = XFS_FSB_TO_DADDR(dp->i_mount,
map.br_startblock);
dblkcnt = XFS_FSB_TO_BB(dp->i_mount,
map.br_blockcount);
bp = xfs_trans_get_buf(*trans,
dp->i_mount->m_ddev_targp,
dblkno, dblkcnt, 0);
if (!bp)
return -ENOMEM;
xfs_trans_binval(*trans, bp);
error = xfs_trans_roll_inode(trans, dp);
if (error)
return error;
}
tblkno += map.br_blockcount;
tblkcnt -= map.br_blockcount;
}
return 0;
}
STATIC int
xfs_attr3_leaf_inactive(
struct xfs_trans **trans,
struct xfs_inode *dp,
struct xfs_buf *bp)
{
struct xfs_attr_leafblock *leaf;
struct xfs_attr3_icleaf_hdr ichdr;
struct xfs_attr_leaf_entry *entry;
struct xfs_attr_leaf_name_remote *name_rmt;
struct xfs_attr_inactive_list *list;
struct xfs_attr_inactive_list *lp;
int error;
int count;
int size;
int tmp;
int i;
struct xfs_mount *mp = bp->b_target->bt_mount;
leaf = bp->b_addr;
xfs_attr3_leaf_hdr_from_disk(mp->m_attr_geo, &ichdr, leaf);
count = 0;
entry = xfs_attr3_leaf_entryp(leaf);
for (i = 0; i < ichdr.count; entry++, i++) {
if (be16_to_cpu(entry->nameidx) &&
((entry->flags & XFS_ATTR_LOCAL) == 0)) {
name_rmt = xfs_attr3_leaf_name_remote(leaf, i);
if (name_rmt->valueblk)
count++;
}
}
if (count == 0) {
xfs_trans_brelse(*trans, bp);
return 0;
}
size = count * sizeof(xfs_attr_inactive_list_t);
list = kmem_alloc(size, KM_SLEEP);
lp = list;
entry = xfs_attr3_leaf_entryp(leaf);
for (i = 0; i < ichdr.count; entry++, i++) {
if (be16_to_cpu(entry->nameidx) &&
((entry->flags & XFS_ATTR_LOCAL) == 0)) {
name_rmt = xfs_attr3_leaf_name_remote(leaf, i);
if (name_rmt->valueblk) {
lp->valueblk = be32_to_cpu(name_rmt->valueblk);
lp->valuelen = xfs_attr3_rmt_blocks(dp->i_mount,
be32_to_cpu(name_rmt->valuelen));
lp++;
}
}
}
xfs_trans_brelse(*trans, bp);
error = 0;
for (lp = list, i = 0; i < count; i++, lp++) {
tmp = xfs_attr3_leaf_freextent(trans, dp,
lp->valueblk, lp->valuelen);
if (error == 0)
error = tmp;
}
kmem_free(list);
return error;
}
STATIC int
xfs_attr3_node_inactive(
struct xfs_trans **trans,
struct xfs_inode *dp,
struct xfs_buf *bp,
int level)
{
xfs_da_blkinfo_t *info;
xfs_da_intnode_t *node;
xfs_dablk_t child_fsb;
xfs_daddr_t parent_blkno, child_blkno;
int error, i;
struct xfs_buf *child_bp;
struct xfs_da_node_entry *btree;
struct xfs_da3_icnode_hdr ichdr;
if (level > XFS_DA_NODE_MAXDEPTH) {
xfs_trans_brelse(*trans, bp);
return -EIO;
}
node = bp->b_addr;
dp->d_ops->node_hdr_from_disk(&ichdr, node);
parent_blkno = bp->b_bn;
if (!ichdr.count) {
xfs_trans_brelse(*trans, bp);
return 0;
}
btree = dp->d_ops->node_tree_p(node);
child_fsb = be32_to_cpu(btree[0].before);
xfs_trans_brelse(*trans, bp);
for (i = 0; i < ichdr.count; i++) {
error = xfs_da3_node_read(*trans, dp, child_fsb, -2, &child_bp,
XFS_ATTR_FORK);
if (error)
return error;
if (child_bp) {
child_blkno = XFS_BUF_ADDR(child_bp);
info = child_bp->b_addr;
switch (info->magic) {
case cpu_to_be16(XFS_DA_NODE_MAGIC):
case cpu_to_be16(XFS_DA3_NODE_MAGIC):
error = xfs_attr3_node_inactive(trans, dp,
child_bp, level + 1);
break;
case cpu_to_be16(XFS_ATTR_LEAF_MAGIC):
case cpu_to_be16(XFS_ATTR3_LEAF_MAGIC):
error = xfs_attr3_leaf_inactive(trans, dp,
child_bp);
break;
default:
error = -EIO;
xfs_trans_brelse(*trans, child_bp);
break;
}
if (error)
return error;
error = xfs_da_get_buf(*trans, dp, 0, child_blkno,
&child_bp, XFS_ATTR_FORK);
if (error)
return error;
xfs_trans_binval(*trans, child_bp);
}
if (i + 1 < ichdr.count) {
error = xfs_da3_node_read(*trans, dp, 0, parent_blkno,
&bp, XFS_ATTR_FORK);
if (error)
return error;
node = bp->b_addr;
btree = dp->d_ops->node_tree_p(node);
child_fsb = be32_to_cpu(btree[i + 1].before);
xfs_trans_brelse(*trans, bp);
}
error = xfs_trans_roll_inode(trans, dp);
if (error)
return error;
}
return 0;
}
static int
xfs_attr3_root_inactive(
struct xfs_trans **trans,
struct xfs_inode *dp)
{
struct xfs_da_blkinfo *info;
struct xfs_buf *bp;
xfs_daddr_t blkno;
int error;
error = xfs_da3_node_read(*trans, dp, 0, -1, &bp, XFS_ATTR_FORK);
if (error)
return error;
blkno = bp->b_bn;
info = bp->b_addr;
switch (info->magic) {
case cpu_to_be16(XFS_DA_NODE_MAGIC):
case cpu_to_be16(XFS_DA3_NODE_MAGIC):
error = xfs_attr3_node_inactive(trans, dp, bp, 1);
break;
case cpu_to_be16(XFS_ATTR_LEAF_MAGIC):
case cpu_to_be16(XFS_ATTR3_LEAF_MAGIC):
error = xfs_attr3_leaf_inactive(trans, dp, bp);
break;
default:
error = -EIO;
xfs_trans_brelse(*trans, bp);
break;
}
if (error)
return error;
error = xfs_da_get_buf(*trans, dp, 0, blkno, &bp, XFS_ATTR_FORK);
if (error)
return error;
xfs_trans_binval(*trans, bp);
error = xfs_trans_roll_inode(trans, dp);
return error;
}
int
xfs_attr_inactive(
struct xfs_inode *dp)
{
struct xfs_trans *trans;
struct xfs_mount *mp;
int lock_mode = XFS_ILOCK_SHARED;
int error = 0;
mp = dp->i_mount;
ASSERT(! XFS_NOT_DQATTACHED(mp, dp));
xfs_ilock(dp, lock_mode);
if (!XFS_IFORK_Q(dp))
goto out_destroy_fork;
xfs_iunlock(dp, lock_mode);
lock_mode = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_attrinval, 0, 0, 0, &trans);
if (error)
goto out_destroy_fork;
lock_mode = XFS_ILOCK_EXCL;
xfs_ilock(dp, lock_mode);
if (!XFS_IFORK_Q(dp))
goto out_cancel;
xfs_trans_ijoin(trans, dp, 0);
if (xfs_inode_hasattr(dp) &&
dp->i_d.di_aformat != XFS_DINODE_FMT_LOCAL) {
error = xfs_attr3_root_inactive(&trans, dp);
if (error)
goto out_cancel;
error = xfs_itruncate_extents(&trans, dp, XFS_ATTR_FORK, 0);
if (error)
goto out_cancel;
}
xfs_attr_fork_remove(dp, trans);
error = xfs_trans_commit(trans);
xfs_iunlock(dp, lock_mode);
return error;
out_cancel:
xfs_trans_cancel(trans);
out_destroy_fork:
if (dp->i_afp)
xfs_idestroy_fork(dp, XFS_ATTR_FORK);
if (lock_mode)
xfs_iunlock(dp, lock_mode);
return error;
}
