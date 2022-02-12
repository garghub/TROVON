static int v9fs_dentry_delete(const struct dentry *dentry)
{
p9_debug(P9_DEBUG_VFS, " dentry: %s (%p)\n",
dentry->d_name.name, dentry);
return 1;
}
static int v9fs_cached_dentry_delete(const struct dentry *dentry)
{
p9_debug(P9_DEBUG_VFS, " dentry: %s (%p)\n",
dentry->d_name.name, dentry);
if (!dentry->d_inode)
return 1;
return 0;
}
static void v9fs_dentry_release(struct dentry *dentry)
{
struct v9fs_dentry *dent;
struct p9_fid *temp, *current_fid;
p9_debug(P9_DEBUG_VFS, " dentry: %s (%p)\n",
dentry->d_name.name, dentry);
dent = dentry->d_fsdata;
if (dent) {
list_for_each_entry_safe(current_fid, temp, &dent->fidlist,
dlist) {
p9_client_clunk(current_fid);
}
kfree(dent);
dentry->d_fsdata = NULL;
}
}
static int v9fs_lookup_revalidate(struct dentry *dentry, unsigned int flags)
{
struct p9_fid *fid;
struct inode *inode;
struct v9fs_inode *v9inode;
if (flags & LOOKUP_RCU)
return -ECHILD;
inode = dentry->d_inode;
if (!inode)
goto out_valid;
v9inode = V9FS_I(inode);
if (v9inode->cache_validity & V9FS_INO_INVALID_ATTR) {
int retval;
struct v9fs_session_info *v9ses;
fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return PTR_ERR(fid);
v9ses = v9fs_inode2v9ses(inode);
if (v9fs_proto_dotl(v9ses))
retval = v9fs_refresh_inode_dotl(fid, inode);
else
retval = v9fs_refresh_inode(fid, inode);
if (retval == -ENOENT)
return 0;
if (retval < 0)
return retval;
}
out_valid:
return 1;
}
