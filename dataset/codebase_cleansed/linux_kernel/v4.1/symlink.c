static void *ext2_follow_link(struct dentry *dentry, struct nameidata *nd)
{
struct ext2_inode_info *ei = EXT2_I(d_inode(dentry));
nd_set_link(nd, (char *)ei->i_data);
return NULL;
}
