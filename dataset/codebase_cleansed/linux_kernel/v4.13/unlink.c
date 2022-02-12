static void
nfs_free_unlinkdata(struct nfs_unlinkdata *data)
{
put_rpccred(data->cred);
kfree(data->args.name.name);
kfree(data);
}
static void nfs_async_unlink_done(struct rpc_task *task, void *calldata)
{
struct nfs_unlinkdata *data = calldata;
struct inode *dir = d_inode(data->dentry->d_parent);
trace_nfs_sillyrename_unlink(data, task->tk_status);
if (!NFS_PROTO(dir)->unlink_done(task, dir))
rpc_restart_call_prepare(task);
}
static void nfs_async_unlink_release(void *calldata)
{
struct nfs_unlinkdata *data = calldata;
struct dentry *dentry = data->dentry;
struct super_block *sb = dentry->d_sb;
up_read_non_owner(&NFS_I(d_inode(dentry->d_parent))->rmdir_sem);
d_lookup_done(dentry);
nfs_free_unlinkdata(data);
dput(dentry);
nfs_sb_deactive(sb);
}
static void nfs_unlink_prepare(struct rpc_task *task, void *calldata)
{
struct nfs_unlinkdata *data = calldata;
struct inode *dir = d_inode(data->dentry->d_parent);
NFS_PROTO(dir)->unlink_rpc_prepare(task, data);
}
static void nfs_do_call_unlink(struct nfs_unlinkdata *data)
{
struct rpc_message msg = {
.rpc_argp = &data->args,
.rpc_resp = &data->res,
.rpc_cred = data->cred,
};
struct rpc_task_setup task_setup_data = {
.rpc_message = &msg,
.callback_ops = &nfs_unlink_ops,
.callback_data = data,
.workqueue = nfsiod_workqueue,
.flags = RPC_TASK_ASYNC,
};
struct rpc_task *task;
struct inode *dir = d_inode(data->dentry->d_parent);
nfs_sb_active(dir->i_sb);
data->args.fh = NFS_FH(dir);
nfs_fattr_init(data->res.dir_attr);
NFS_PROTO(dir)->unlink_setup(&msg, dir);
task_setup_data.rpc_client = NFS_CLIENT(dir);
task = rpc_run_task(&task_setup_data);
if (!IS_ERR(task))
rpc_put_task_async(task);
}
static int nfs_call_unlink(struct dentry *dentry, struct nfs_unlinkdata *data)
{
struct inode *dir = d_inode(dentry->d_parent);
struct dentry *alias;
down_read_non_owner(&NFS_I(dir)->rmdir_sem);
alias = d_alloc_parallel(dentry->d_parent, &data->args.name, &data->wq);
if (IS_ERR(alias)) {
up_read_non_owner(&NFS_I(dir)->rmdir_sem);
return 0;
}
if (!d_in_lookup(alias)) {
int ret;
void *devname_garbage = NULL;
spin_lock(&alias->d_lock);
if (d_really_is_positive(alias) &&
!(alias->d_flags & DCACHE_NFSFS_RENAMED)) {
devname_garbage = alias->d_fsdata;
alias->d_fsdata = data;
alias->d_flags |= DCACHE_NFSFS_RENAMED;
ret = 1;
} else
ret = 0;
spin_unlock(&alias->d_lock);
dput(alias);
up_read_non_owner(&NFS_I(dir)->rmdir_sem);
kfree(devname_garbage);
return ret;
}
data->dentry = alias;
nfs_do_call_unlink(data);
return 1;
}
static int
nfs_async_unlink(struct dentry *dentry, const struct qstr *name)
{
struct nfs_unlinkdata *data;
int status = -ENOMEM;
void *devname_garbage = NULL;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (data == NULL)
goto out;
data->args.name.name = kstrdup(name->name, GFP_KERNEL);
if (!data->args.name.name)
goto out_free;
data->args.name.len = name->len;
data->cred = rpc_lookup_cred();
if (IS_ERR(data->cred)) {
status = PTR_ERR(data->cred);
goto out_free_name;
}
data->res.dir_attr = &data->dir_attr;
init_waitqueue_head(&data->wq);
status = -EBUSY;
spin_lock(&dentry->d_lock);
if (dentry->d_flags & DCACHE_NFSFS_RENAMED)
goto out_unlock;
dentry->d_flags |= DCACHE_NFSFS_RENAMED;
devname_garbage = dentry->d_fsdata;
dentry->d_fsdata = data;
spin_unlock(&dentry->d_lock);
kfree(devname_garbage);
return 0;
out_unlock:
spin_unlock(&dentry->d_lock);
put_rpccred(data->cred);
out_free_name:
kfree(data->args.name.name);
out_free:
kfree(data);
out:
return status;
}
void
nfs_complete_unlink(struct dentry *dentry, struct inode *inode)
{
struct nfs_unlinkdata *data;
spin_lock(&dentry->d_lock);
dentry->d_flags &= ~DCACHE_NFSFS_RENAMED;
data = dentry->d_fsdata;
dentry->d_fsdata = NULL;
spin_unlock(&dentry->d_lock);
if (NFS_STALE(inode) || !nfs_call_unlink(dentry, data))
nfs_free_unlinkdata(data);
}
static void
nfs_cancel_async_unlink(struct dentry *dentry)
{
spin_lock(&dentry->d_lock);
if (dentry->d_flags & DCACHE_NFSFS_RENAMED) {
struct nfs_unlinkdata *data = dentry->d_fsdata;
dentry->d_flags &= ~DCACHE_NFSFS_RENAMED;
dentry->d_fsdata = NULL;
spin_unlock(&dentry->d_lock);
nfs_free_unlinkdata(data);
return;
}
spin_unlock(&dentry->d_lock);
}
static void nfs_async_rename_done(struct rpc_task *task, void *calldata)
{
struct nfs_renamedata *data = calldata;
struct inode *old_dir = data->old_dir;
struct inode *new_dir = data->new_dir;
struct dentry *old_dentry = data->old_dentry;
trace_nfs_sillyrename_rename(old_dir, old_dentry,
new_dir, data->new_dentry, task->tk_status);
if (!NFS_PROTO(old_dir)->rename_done(task, old_dir, new_dir)) {
rpc_restart_call_prepare(task);
return;
}
if (data->complete)
data->complete(task, data);
}
static void nfs_async_rename_release(void *calldata)
{
struct nfs_renamedata *data = calldata;
struct super_block *sb = data->old_dir->i_sb;
if (d_really_is_positive(data->old_dentry))
nfs_mark_for_revalidate(d_inode(data->old_dentry));
if (data->cancelled) {
spin_lock(&data->old_dir->i_lock);
nfs_force_lookup_revalidate(data->old_dir);
spin_unlock(&data->old_dir->i_lock);
if (data->new_dir != data->old_dir) {
spin_lock(&data->new_dir->i_lock);
nfs_force_lookup_revalidate(data->new_dir);
spin_unlock(&data->new_dir->i_lock);
}
}
dput(data->old_dentry);
dput(data->new_dentry);
iput(data->old_dir);
iput(data->new_dir);
nfs_sb_deactive(sb);
put_rpccred(data->cred);
kfree(data);
}
static void nfs_rename_prepare(struct rpc_task *task, void *calldata)
{
struct nfs_renamedata *data = calldata;
NFS_PROTO(data->old_dir)->rename_rpc_prepare(task, data);
}
struct rpc_task *
nfs_async_rename(struct inode *old_dir, struct inode *new_dir,
struct dentry *old_dentry, struct dentry *new_dentry,
void (*complete)(struct rpc_task *, struct nfs_renamedata *))
{
struct nfs_renamedata *data;
struct rpc_message msg = { };
struct rpc_task_setup task_setup_data = {
.rpc_message = &msg,
.callback_ops = &nfs_rename_ops,
.workqueue = nfsiod_workqueue,
.rpc_client = NFS_CLIENT(old_dir),
.flags = RPC_TASK_ASYNC,
};
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (data == NULL)
return ERR_PTR(-ENOMEM);
task_setup_data.callback_data = data;
data->cred = rpc_lookup_cred();
if (IS_ERR(data->cred)) {
struct rpc_task *task = ERR_CAST(data->cred);
kfree(data);
return task;
}
msg.rpc_argp = &data->args;
msg.rpc_resp = &data->res;
msg.rpc_cred = data->cred;
data->old_dir = old_dir;
ihold(old_dir);
data->new_dir = new_dir;
ihold(new_dir);
data->old_dentry = dget(old_dentry);
data->new_dentry = dget(new_dentry);
nfs_fattr_init(&data->old_fattr);
nfs_fattr_init(&data->new_fattr);
data->complete = complete;
data->args.old_dir = NFS_FH(old_dir);
data->args.old_name = &old_dentry->d_name;
data->args.new_dir = NFS_FH(new_dir);
data->args.new_name = &new_dentry->d_name;
data->res.old_fattr = &data->old_fattr;
data->res.new_fattr = &data->new_fattr;
nfs_sb_active(old_dir->i_sb);
NFS_PROTO(data->old_dir)->rename_setup(&msg, old_dir);
return rpc_run_task(&task_setup_data);
}
static void
nfs_complete_sillyrename(struct rpc_task *task, struct nfs_renamedata *data)
{
struct dentry *dentry = data->old_dentry;
if (task->tk_status != 0) {
nfs_cancel_async_unlink(dentry);
return;
}
fsnotify_nameremove(dentry, 0);
}
int
nfs_sillyrename(struct inode *dir, struct dentry *dentry)
{
static unsigned int sillycounter;
unsigned char silly[SILLYNAME_LEN + 1];
unsigned long long fileid;
struct dentry *sdentry;
struct rpc_task *task;
int error = -EBUSY;
dfprintk(VFS, "NFS: silly-rename(%pd2, ct=%d)\n",
dentry, d_count(dentry));
nfs_inc_stats(dir, NFSIOS_SILLYRENAME);
if (dentry->d_flags & DCACHE_NFSFS_RENAMED)
goto out;
fileid = NFS_FILEID(d_inode(dentry));
NFS_PROTO(d_inode(dentry))->return_delegation(d_inode(dentry));
sdentry = NULL;
do {
int slen;
dput(sdentry);
sillycounter++;
slen = scnprintf(silly, sizeof(silly),
SILLYNAME_PREFIX "%0*llx%0*x",
SILLYNAME_FILEID_LEN, fileid,
SILLYNAME_COUNTER_LEN, sillycounter);
dfprintk(VFS, "NFS: trying to rename %pd to %s\n",
dentry, silly);
sdentry = lookup_one_len(silly, dentry->d_parent, slen);
if (IS_ERR(sdentry))
goto out;
} while (d_inode(sdentry) != NULL);
error = nfs_async_unlink(dentry, &sdentry->d_name);
if (error)
goto out_dput;
task = nfs_async_rename(dir, dir, dentry, sdentry,
nfs_complete_sillyrename);
if (IS_ERR(task)) {
error = -EBUSY;
nfs_cancel_async_unlink(dentry);
goto out_dput;
}
error = rpc_wait_for_completion_task(task);
if (error == 0)
error = task->tk_status;
switch (error) {
case 0:
nfs_set_verifier(dentry, nfs_save_change_attribute(dir));
d_move(dentry, sdentry);
break;
case -ERESTARTSYS:
d_drop(dentry);
d_drop(sdentry);
}
rpc_put_task(task);
out_dput:
dput(sdentry);
out:
return error;
}
