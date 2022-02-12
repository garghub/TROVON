static void
vxfs_put_super(struct super_block *sbp)
{
struct vxfs_sb_info *infp = VXFS_SBI(sbp);
iput(infp->vsi_fship);
iput(infp->vsi_ilist);
iput(infp->vsi_stilist);
brelse(infp->vsi_bp);
kfree(infp);
}
static int
vxfs_statfs(struct dentry *dentry, struct kstatfs *bufp)
{
struct vxfs_sb_info *infp = VXFS_SBI(dentry->d_sb);
struct vxfs_sb *raw_sb = infp->vsi_raw;
bufp->f_type = VXFS_SUPER_MAGIC;
bufp->f_bsize = dentry->d_sb->s_blocksize;
bufp->f_blocks = fs32_to_cpu(infp, raw_sb->vs_dsize);
bufp->f_bfree = fs32_to_cpu(infp, raw_sb->vs_free);
bufp->f_bavail = 0;
bufp->f_files = 0;
bufp->f_ffree = fs32_to_cpu(infp, raw_sb->vs_ifree);
bufp->f_namelen = VXFS_NAMELEN;
return 0;
}
static int vxfs_remount(struct super_block *sb, int *flags, char *data)
{
sync_filesystem(sb);
*flags |= MS_RDONLY;
return 0;
}
static struct inode *vxfs_alloc_inode(struct super_block *sb)
{
struct vxfs_inode_info *vi;
vi = kmem_cache_alloc(vxfs_inode_cachep, GFP_KERNEL);
if (!vi)
return NULL;
inode_init_once(&vi->vfs_inode);
return &vi->vfs_inode;
}
static void vxfs_i_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
kmem_cache_free(vxfs_inode_cachep, VXFS_INO(inode));
}
static void vxfs_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, vxfs_i_callback);
}
static int vxfs_try_sb_magic(struct super_block *sbp, int silent,
unsigned blk, __fs32 magic)
{
struct buffer_head *bp;
struct vxfs_sb *rsbp;
struct vxfs_sb_info *infp = VXFS_SBI(sbp);
int rc = -ENOMEM;
bp = sb_bread(sbp, blk);
do {
if (!bp || !buffer_mapped(bp)) {
if (!silent) {
printk(KERN_WARNING
"vxfs: unable to read disk superblock at %u\n",
blk);
}
break;
}
rc = -EINVAL;
rsbp = (struct vxfs_sb *)bp->b_data;
if (rsbp->vs_magic != magic) {
if (!silent)
printk(KERN_NOTICE
"vxfs: WRONG superblock magic %08x at %u\n",
rsbp->vs_magic, blk);
break;
}
rc = 0;
infp->vsi_raw = rsbp;
infp->vsi_bp = bp;
} while (0);
if (rc) {
infp->vsi_raw = NULL;
infp->vsi_bp = NULL;
brelse(bp);
}
return rc;
}
static int vxfs_fill_super(struct super_block *sbp, void *dp, int silent)
{
struct vxfs_sb_info *infp;
struct vxfs_sb *rsbp;
u_long bsize;
struct inode *root;
int ret = -EINVAL;
u32 j;
sbp->s_flags |= MS_RDONLY;
infp = kzalloc(sizeof(*infp), GFP_KERNEL);
if (!infp) {
printk(KERN_WARNING "vxfs: unable to allocate incore superblock\n");
return -ENOMEM;
}
bsize = sb_min_blocksize(sbp, BLOCK_SIZE);
if (!bsize) {
printk(KERN_WARNING "vxfs: unable to set blocksize\n");
goto out;
}
sbp->s_op = &vxfs_super_ops;
sbp->s_fs_info = infp;
if (!vxfs_try_sb_magic(sbp, silent, 1,
(__force __fs32)cpu_to_le32(VXFS_SUPER_MAGIC))) {
infp->byte_order = VXFS_BO_LE;
} else if (!vxfs_try_sb_magic(sbp, silent, 8,
(__force __fs32)cpu_to_be32(VXFS_SUPER_MAGIC))) {
infp->byte_order = VXFS_BO_BE;
} else {
if (!silent)
printk(KERN_NOTICE "vxfs: can't find superblock.\n");
goto out;
}
rsbp = infp->vsi_raw;
j = fs32_to_cpu(infp, rsbp->vs_version);
if ((j < 2 || j > 4) && !silent) {
printk(KERN_NOTICE "vxfs: unsupported VxFS version (%d)\n", j);
goto out;
}
#ifdef DIAGNOSTIC
printk(KERN_DEBUG "vxfs: supported VxFS version (%d)\n", j);
printk(KERN_DEBUG "vxfs: blocksize: %d\n",
fs32_to_cpu(infp, rsbp->vs_bsize));
#endif
sbp->s_magic = fs32_to_cpu(infp, rsbp->vs_magic);
infp->vsi_oltext = fs32_to_cpu(infp, rsbp->vs_oltext[0]);
infp->vsi_oltsize = fs32_to_cpu(infp, rsbp->vs_oltsize);
j = fs32_to_cpu(infp, rsbp->vs_bsize);
if (!sb_set_blocksize(sbp, j)) {
printk(KERN_WARNING "vxfs: unable to set final block size\n");
goto out;
}
if (vxfs_read_olt(sbp, bsize)) {
printk(KERN_WARNING "vxfs: unable to read olt\n");
goto out;
}
if (vxfs_read_fshead(sbp)) {
printk(KERN_WARNING "vxfs: unable to read fshead\n");
goto out;
}
root = vxfs_iget(sbp, VXFS_ROOT_INO);
if (IS_ERR(root)) {
ret = PTR_ERR(root);
goto out;
}
sbp->s_root = d_make_root(root);
if (!sbp->s_root) {
printk(KERN_WARNING "vxfs: unable to get root dentry.\n");
goto out_free_ilist;
}
return 0;
out_free_ilist:
iput(infp->vsi_fship);
iput(infp->vsi_ilist);
iput(infp->vsi_stilist);
out:
brelse(infp->vsi_bp);
kfree(infp);
return ret;
}
static struct dentry *vxfs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_bdev(fs_type, flags, dev_name, data, vxfs_fill_super);
}
static int __init
vxfs_init(void)
{
int rv;
vxfs_inode_cachep = kmem_cache_create("vxfs_inode",
sizeof(struct vxfs_inode_info), 0,
SLAB_RECLAIM_ACCOUNT|SLAB_MEM_SPREAD, NULL);
if (!vxfs_inode_cachep)
return -ENOMEM;
rv = register_filesystem(&vxfs_fs_type);
if (rv < 0)
kmem_cache_destroy(vxfs_inode_cachep);
return rv;
}
static void __exit
vxfs_cleanup(void)
{
unregister_filesystem(&vxfs_fs_type);
rcu_barrier();
kmem_cache_destroy(vxfs_inode_cachep);
}
