void jfs_set_inode_flags(struct inode *inode)
{
unsigned int flags = JFS_IP(inode)->mode2;
unsigned int new_fl = 0;
if (flags & JFS_IMMUTABLE_FL)
new_fl |= S_IMMUTABLE;
if (flags & JFS_APPEND_FL)
new_fl |= S_APPEND;
if (flags & JFS_NOATIME_FL)
new_fl |= S_NOATIME;
if (flags & JFS_DIRSYNC_FL)
new_fl |= S_DIRSYNC;
if (flags & JFS_SYNC_FL)
new_fl |= S_SYNC;
inode_set_flags(inode, new_fl, S_IMMUTABLE | S_APPEND | S_NOATIME |
S_DIRSYNC | S_SYNC);
}
void jfs_get_inode_flags(struct jfs_inode_info *jfs_ip)
{
unsigned int flags = jfs_ip->vfs_inode.i_flags;
jfs_ip->mode2 &= ~(JFS_IMMUTABLE_FL | JFS_APPEND_FL | JFS_NOATIME_FL |
JFS_DIRSYNC_FL | JFS_SYNC_FL);
if (flags & S_IMMUTABLE)
jfs_ip->mode2 |= JFS_IMMUTABLE_FL;
if (flags & S_APPEND)
jfs_ip->mode2 |= JFS_APPEND_FL;
if (flags & S_NOATIME)
jfs_ip->mode2 |= JFS_NOATIME_FL;
if (flags & S_DIRSYNC)
jfs_ip->mode2 |= JFS_DIRSYNC_FL;
if (flags & S_SYNC)
jfs_ip->mode2 |= JFS_SYNC_FL;
}
struct inode *ialloc(struct inode *parent, umode_t mode)
{
struct super_block *sb = parent->i_sb;
struct inode *inode;
struct jfs_inode_info *jfs_inode;
int rc;
inode = new_inode(sb);
if (!inode) {
jfs_warn("ialloc: new_inode returned NULL!");
rc = -ENOMEM;
goto fail;
}
jfs_inode = JFS_IP(inode);
rc = diAlloc(parent, S_ISDIR(mode), inode);
if (rc) {
jfs_warn("ialloc: diAlloc returned %d!", rc);
if (rc == -EIO)
make_bad_inode(inode);
goto fail_put;
}
if (insert_inode_locked(inode) < 0) {
rc = -EINVAL;
goto fail_put;
}
inode_init_owner(inode, parent, mode);
jfs_inode->saved_uid = inode->i_uid;
jfs_inode->saved_gid = inode->i_gid;
rc = dquot_initialize(inode);
if (rc)
goto fail_drop;
rc = dquot_alloc_inode(inode);
if (rc)
goto fail_drop;
jfs_inode->mode2 = JFS_IP(parent)->mode2 & JFS_FL_INHERIT;
if (S_ISDIR(mode)) {
jfs_inode->mode2 |= IDIRECTORY;
jfs_inode->mode2 &= ~JFS_DIRSYNC_FL;
}
else {
jfs_inode->mode2 |= INLINEEA | ISPARSE;
if (S_ISLNK(mode))
jfs_inode->mode2 &= ~(JFS_IMMUTABLE_FL|JFS_APPEND_FL);
}
jfs_inode->mode2 |= inode->i_mode;
inode->i_blocks = 0;
inode->i_mtime = inode->i_atime = inode->i_ctime = current_time(inode);
jfs_inode->otime = inode->i_ctime.tv_sec;
inode->i_generation = JFS_SBI(sb)->gengen++;
jfs_inode->cflag = 0;
memset(&jfs_inode->acl, 0, sizeof(dxd_t));
memset(&jfs_inode->ea, 0, sizeof(dxd_t));
jfs_inode->next_index = 0;
jfs_inode->acltype = 0;
jfs_inode->btorder = 0;
jfs_inode->btindex = 0;
jfs_inode->bxflag = 0;
jfs_inode->blid = 0;
jfs_inode->atlhead = 0;
jfs_inode->atltail = 0;
jfs_inode->xtlid = 0;
jfs_set_inode_flags(inode);
jfs_info("ialloc returns inode = 0x%p", inode);
return inode;
fail_drop:
dquot_drop(inode);
inode->i_flags |= S_NOQUOTA;
clear_nlink(inode);
unlock_new_inode(inode);
fail_put:
iput(inode);
fail:
return ERR_PTR(rc);
}
