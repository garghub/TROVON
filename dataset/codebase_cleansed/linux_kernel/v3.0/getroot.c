static int nfs_superblock_set_dummy_root(struct super_block *sb, struct inode *inode)
{
if (sb->s_root == NULL) {
sb->s_root = d_alloc_root(inode);
if (sb->s_root == NULL) {
iput(inode);
return -ENOMEM;
}
ihold(inode);
spin_lock(&sb->s_root->d_inode->i_lock);
spin_lock(&sb->s_root->d_lock);
list_del_init(&sb->s_root->d_alias);
spin_unlock(&sb->s_root->d_lock);
spin_unlock(&sb->s_root->d_inode->i_lock);
}
return 0;
}
struct dentry *nfs_get_root(struct super_block *sb, struct nfs_fh *mntfh,
const char *devname)
{
struct nfs_server *server = NFS_SB(sb);
struct nfs_fsinfo fsinfo;
struct dentry *ret;
struct inode *inode;
void *name = kstrdup(devname, GFP_KERNEL);
int error;
if (!name)
return ERR_PTR(-ENOMEM);
fsinfo.fattr = nfs_alloc_fattr();
if (fsinfo.fattr == NULL) {
kfree(name);
return ERR_PTR(-ENOMEM);
}
error = server->nfs_client->rpc_ops->getroot(server, mntfh, &fsinfo);
if (error < 0) {
dprintk("nfs_get_root: getattr error = %d\n", -error);
ret = ERR_PTR(error);
goto out;
}
inode = nfs_fhget(sb, mntfh, fsinfo.fattr);
if (IS_ERR(inode)) {
dprintk("nfs_get_root: get root inode failed\n");
ret = ERR_CAST(inode);
goto out;
}
error = nfs_superblock_set_dummy_root(sb, inode);
if (error != 0) {
ret = ERR_PTR(error);
goto out;
}
ret = d_obtain_alias(inode);
if (IS_ERR(ret)) {
dprintk("nfs_get_root: get root dentry failed\n");
goto out;
}
security_d_instantiate(ret, inode);
spin_lock(&ret->d_lock);
if (IS_ROOT(ret) && !(ret->d_flags & DCACHE_NFSFS_RENAMED)) {
ret->d_fsdata = name;
name = NULL;
}
spin_unlock(&ret->d_lock);
out:
if (name)
kfree(name);
nfs_free_fattr(fsinfo.fattr);
return ret;
}
int nfs4_get_rootfh(struct nfs_server *server, struct nfs_fh *mntfh)
{
struct nfs_fsinfo fsinfo;
int ret = -ENOMEM;
dprintk("--> nfs4_get_rootfh()\n");
fsinfo.fattr = nfs_alloc_fattr();
if (fsinfo.fattr == NULL)
goto out;
ret = server->nfs_client->rpc_ops->getroot(server, mntfh, &fsinfo);
if (ret < 0) {
dprintk("nfs4_get_rootfh: getroot error = %d\n", -ret);
goto out;
}
if (!(fsinfo.fattr->valid & NFS_ATTR_FATTR_TYPE)
|| !S_ISDIR(fsinfo.fattr->mode)) {
printk(KERN_ERR "nfs4_get_rootfh:"
" getroot encountered non-directory\n");
ret = -ENOTDIR;
goto out;
}
if (fsinfo.fattr->valid & NFS_ATTR_FATTR_V4_REFERRAL) {
printk(KERN_ERR "nfs4_get_rootfh:"
" getroot obtained referral\n");
ret = -EREMOTE;
goto out;
}
memcpy(&server->fsid, &fsinfo.fattr->fsid, sizeof(server->fsid));
out:
nfs_free_fattr(fsinfo.fattr);
dprintk("<-- nfs4_get_rootfh() = %d\n", ret);
return ret;
}
struct dentry *nfs4_get_root(struct super_block *sb, struct nfs_fh *mntfh,
const char *devname)
{
struct nfs_server *server = NFS_SB(sb);
struct nfs_fattr *fattr = NULL;
struct dentry *ret;
struct inode *inode;
void *name = kstrdup(devname, GFP_KERNEL);
int error;
dprintk("--> nfs4_get_root()\n");
if (!name)
return ERR_PTR(-ENOMEM);
error = nfs4_server_capabilities(server, mntfh);
if (error < 0) {
dprintk("nfs_get_root: getcaps error = %d\n",
-error);
kfree(name);
return ERR_PTR(error);
}
fattr = nfs_alloc_fattr();
if (fattr == NULL) {
kfree(name);
return ERR_PTR(-ENOMEM);
}
error = server->nfs_client->rpc_ops->getattr(server, mntfh, fattr);
if (error < 0) {
dprintk("nfs_get_root: getattr error = %d\n", -error);
ret = ERR_PTR(error);
goto out;
}
if (fattr->valid & NFS_ATTR_FATTR_FSID &&
!nfs_fsid_equal(&server->fsid, &fattr->fsid))
memcpy(&server->fsid, &fattr->fsid, sizeof(server->fsid));
inode = nfs_fhget(sb, mntfh, fattr);
if (IS_ERR(inode)) {
dprintk("nfs_get_root: get root inode failed\n");
ret = ERR_CAST(inode);
goto out;
}
error = nfs_superblock_set_dummy_root(sb, inode);
if (error != 0) {
ret = ERR_PTR(error);
goto out;
}
ret = d_obtain_alias(inode);
if (IS_ERR(ret)) {
dprintk("nfs_get_root: get root dentry failed\n");
goto out;
}
security_d_instantiate(ret, inode);
spin_lock(&ret->d_lock);
if (IS_ROOT(ret) && !(ret->d_flags & DCACHE_NFSFS_RENAMED)) {
ret->d_fsdata = name;
name = NULL;
}
spin_unlock(&ret->d_lock);
out:
if (name)
kfree(name);
nfs_free_fattr(fattr);
dprintk("<-- nfs4_get_root()\n");
return ret;
}
