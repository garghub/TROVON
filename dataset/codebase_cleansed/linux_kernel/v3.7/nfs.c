static struct inode *fat_dget(struct super_block *sb, int i_logstart)
{
struct msdos_sb_info *sbi = MSDOS_SB(sb);
struct hlist_head *head;
struct hlist_node *_p;
struct msdos_inode_info *i;
struct inode *inode = NULL;
head = sbi->dir_hashtable + fat_dir_hash(i_logstart);
spin_lock(&sbi->dir_hash_lock);
hlist_for_each_entry(i, _p, head, i_dir_hash) {
BUG_ON(i->vfs_inode.i_sb != sb);
if (i->i_logstart != i_logstart)
continue;
inode = igrab(&i->vfs_inode);
if (inode)
break;
}
spin_unlock(&sbi->dir_hash_lock);
return inode;
}
static struct inode *fat_nfs_get_inode(struct super_block *sb,
u64 ino, u32 generation)
{
struct inode *inode;
if ((ino < MSDOS_ROOT_INO) || (ino == MSDOS_FSINFO_INO))
return NULL;
inode = ilookup(sb, ino);
if (inode && generation && (inode->i_generation != generation)) {
iput(inode);
inode = NULL;
}
return inode;
}
struct dentry *fat_fh_to_dentry(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
return generic_fh_to_dentry(sb, fid, fh_len, fh_type,
fat_nfs_get_inode);
}
struct dentry *fat_fh_to_parent(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
return generic_fh_to_parent(sb, fid, fh_len, fh_type,
fat_nfs_get_inode);
}
struct dentry *fat_get_parent(struct dentry *child_dir)
{
struct super_block *sb = child_dir->d_sb;
struct buffer_head *bh = NULL;
struct msdos_dir_entry *de;
struct inode *parent_inode = NULL;
if (!fat_get_dotdot_entry(child_dir->d_inode, &bh, &de)) {
int parent_logstart = fat_get_start(MSDOS_SB(sb), de);
parent_inode = fat_dget(sb, parent_logstart);
}
brelse(bh);
return d_obtain_alias(parent_inode);
}
