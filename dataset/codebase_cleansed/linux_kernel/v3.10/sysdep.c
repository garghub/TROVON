static int hfs_revalidate_dentry(struct dentry *dentry, unsigned int flags)
{
struct inode *inode;
int diff;
if (flags & LOOKUP_RCU)
return -ECHILD;
inode = dentry->d_inode;
if(!inode)
return 1;
diff = sys_tz.tz_minuteswest * 60 - HFS_I(inode)->tz_secondswest;
if (diff) {
inode->i_ctime.tv_sec += diff;
inode->i_atime.tv_sec += diff;
inode->i_mtime.tv_sec += diff;
HFS_I(inode)->tz_secondswest += diff;
}
return 1;
}
