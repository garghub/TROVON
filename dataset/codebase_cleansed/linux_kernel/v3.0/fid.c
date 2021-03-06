int v9fs_fid_add(struct dentry *dentry, struct p9_fid *fid)
{
struct v9fs_dentry *dent;
P9_DPRINTK(P9_DEBUG_VFS, "fid %d dentry %s\n",
fid->fid, dentry->d_name.name);
dent = dentry->d_fsdata;
if (!dent) {
dent = kmalloc(sizeof(struct v9fs_dentry), GFP_KERNEL);
if (!dent)
return -ENOMEM;
spin_lock_init(&dent->lock);
INIT_LIST_HEAD(&dent->fidlist);
dentry->d_fsdata = dent;
}
spin_lock(&dent->lock);
list_add(&fid->dlist, &dent->fidlist);
spin_unlock(&dent->lock);
return 0;
}
static struct p9_fid *v9fs_fid_find(struct dentry *dentry, u32 uid, int any)
{
struct v9fs_dentry *dent;
struct p9_fid *fid, *ret;
P9_DPRINTK(P9_DEBUG_VFS, " dentry: %s (%p) uid %d any %d\n",
dentry->d_name.name, dentry, uid, any);
dent = (struct v9fs_dentry *) dentry->d_fsdata;
ret = NULL;
if (dent) {
spin_lock(&dent->lock);
list_for_each_entry(fid, &dent->fidlist, dlist) {
if (any || fid->uid == uid) {
ret = fid;
break;
}
}
spin_unlock(&dent->lock);
}
return ret;
}
static int build_path_from_dentry(struct v9fs_session_info *v9ses,
struct dentry *dentry, char ***names)
{
int n = 0, i;
char **wnames;
struct dentry *ds;
for (ds = dentry; !IS_ROOT(ds); ds = ds->d_parent)
n++;
wnames = kmalloc(sizeof(char *) * n, GFP_KERNEL);
if (!wnames)
goto err_out;
for (ds = dentry, i = (n-1); i >= 0; i--, ds = ds->d_parent)
wnames[i] = (char *)ds->d_name.name;
*names = wnames;
return n;
err_out:
return -ENOMEM;
}
static struct p9_fid *v9fs_fid_lookup_with_uid(struct dentry *dentry,
uid_t uid, int any)
{
struct dentry *ds;
char **wnames, *uname;
int i, n, l, clone, access;
struct v9fs_session_info *v9ses;
struct p9_fid *fid, *old_fid = NULL;
v9ses = v9fs_dentry2v9ses(dentry);
access = v9ses->flags & V9FS_ACCESS_MASK;
fid = v9fs_fid_find(dentry, uid, any);
if (fid)
return fid;
down_read(&v9ses->rename_sem);
ds = dentry->d_parent;
fid = v9fs_fid_find(ds, uid, any);
if (fid) {
fid = p9_client_walk(fid, 1, (char **)&dentry->d_name.name, 1);
goto fid_out;
}
up_read(&v9ses->rename_sem);
fid = v9fs_fid_find(dentry->d_sb->s_root, uid, any);
if (!fid) {
if (access == V9FS_ACCESS_SINGLE)
return ERR_PTR(-EPERM);
if (v9fs_proto_dotu(v9ses) || v9fs_proto_dotl(v9ses))
uname = NULL;
else
uname = v9ses->uname;
fid = p9_client_attach(v9ses->clnt, NULL, uname, uid,
v9ses->aname);
if (IS_ERR(fid))
return fid;
v9fs_fid_add(dentry->d_sb->s_root, fid);
}
if (dentry->d_sb->s_root == dentry)
return fid;
down_read(&v9ses->rename_sem);
n = build_path_from_dentry(v9ses, dentry, &wnames);
if (n < 0) {
fid = ERR_PTR(n);
goto err_out;
}
clone = 1;
i = 0;
while (i < n) {
l = min(n - i, P9_MAXWELEM);
fid = p9_client_walk(fid, l, &wnames[i], clone);
if (IS_ERR(fid)) {
if (old_fid) {
p9_client_clunk(old_fid);
}
kfree(wnames);
goto err_out;
}
old_fid = fid;
i += l;
clone = 0;
}
kfree(wnames);
fid_out:
if (!IS_ERR(fid))
v9fs_fid_add(dentry, fid);
err_out:
up_read(&v9ses->rename_sem);
return fid;
}
struct p9_fid *v9fs_fid_lookup(struct dentry *dentry)
{
uid_t uid;
int any, access;
struct v9fs_session_info *v9ses;
v9ses = v9fs_dentry2v9ses(dentry);
access = v9ses->flags & V9FS_ACCESS_MASK;
switch (access) {
case V9FS_ACCESS_SINGLE:
case V9FS_ACCESS_USER:
case V9FS_ACCESS_CLIENT:
uid = current_fsuid();
any = 0;
break;
case V9FS_ACCESS_ANY:
uid = v9ses->uid;
any = 1;
break;
default:
uid = ~0;
any = 0;
break;
}
return v9fs_fid_lookup_with_uid(dentry, uid, any);
}
struct p9_fid *v9fs_fid_clone(struct dentry *dentry)
{
struct p9_fid *fid, *ret;
fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return fid;
ret = p9_client_walk(fid, 0, NULL, 1);
return ret;
}
static struct p9_fid *v9fs_fid_clone_with_uid(struct dentry *dentry, uid_t uid)
{
struct p9_fid *fid, *ret;
fid = v9fs_fid_lookup_with_uid(dentry, uid, 0);
if (IS_ERR(fid))
return fid;
ret = p9_client_walk(fid, 0, NULL, 1);
return ret;
}
struct p9_fid *v9fs_writeback_fid(struct dentry *dentry)
{
int err;
struct p9_fid *fid;
fid = v9fs_fid_clone_with_uid(dentry, 0);
if (IS_ERR(fid))
goto error_out;
err = p9_client_open(fid, O_RDWR);
if (err < 0) {
p9_client_clunk(fid);
fid = ERR_PTR(err);
goto error_out;
}
error_out:
return fid;
}
