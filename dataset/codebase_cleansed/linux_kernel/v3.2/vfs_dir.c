static inline int dt_type(struct p9_wstat *mistat)
{
unsigned long perm = mistat->mode;
int rettype = DT_REG;
if (perm & P9_DMDIR)
rettype = DT_DIR;
if (perm & P9_DMSYMLINK)
rettype = DT_LNK;
return rettype;
}
static void p9stat_init(struct p9_wstat *stbuf)
{
stbuf->name = NULL;
stbuf->uid = NULL;
stbuf->gid = NULL;
stbuf->muid = NULL;
stbuf->extension = NULL;
}
static int v9fs_alloc_rdir_buf(struct file *filp, int buflen)
{
struct p9_rdir *rdir;
struct p9_fid *fid;
int err = 0;
fid = filp->private_data;
if (!fid->rdir) {
rdir = kmalloc(sizeof(struct p9_rdir) + buflen, GFP_KERNEL);
if (rdir == NULL) {
err = -ENOMEM;
goto exit;
}
spin_lock(&filp->f_dentry->d_lock);
if (!fid->rdir) {
rdir->buf = (uint8_t *)rdir + sizeof(struct p9_rdir);
mutex_init(&rdir->mutex);
rdir->head = rdir->tail = 0;
fid->rdir = (void *) rdir;
rdir = NULL;
}
spin_unlock(&filp->f_dentry->d_lock);
kfree(rdir);
}
exit:
return err;
}
static int v9fs_dir_readdir(struct file *filp, void *dirent, filldir_t filldir)
{
int over;
struct p9_wstat st;
int err = 0;
struct p9_fid *fid;
int buflen;
int reclen = 0;
struct p9_rdir *rdir;
P9_DPRINTK(P9_DEBUG_VFS, "name %s\n", filp->f_path.dentry->d_name.name);
fid = filp->private_data;
buflen = fid->clnt->msize - P9_IOHDRSZ;
err = v9fs_alloc_rdir_buf(filp, buflen);
if (err)
goto exit;
rdir = (struct p9_rdir *) fid->rdir;
err = mutex_lock_interruptible(&rdir->mutex);
if (err)
return err;
while (err == 0) {
if (rdir->tail == rdir->head) {
err = v9fs_file_readn(filp, rdir->buf, NULL,
buflen, filp->f_pos);
if (err <= 0)
goto unlock_and_exit;
rdir->head = 0;
rdir->tail = err;
}
while (rdir->head < rdir->tail) {
p9stat_init(&st);
err = p9stat_read(fid->clnt, rdir->buf + rdir->head,
rdir->tail - rdir->head, &st);
if (err) {
P9_DPRINTK(P9_DEBUG_VFS, "returned %d\n", err);
err = -EIO;
p9stat_free(&st);
goto unlock_and_exit;
}
reclen = st.size+2;
over = filldir(dirent, st.name, strlen(st.name),
filp->f_pos, v9fs_qid2ino(&st.qid), dt_type(&st));
p9stat_free(&st);
if (over) {
err = 0;
goto unlock_and_exit;
}
rdir->head += reclen;
filp->f_pos += reclen;
}
}
unlock_and_exit:
mutex_unlock(&rdir->mutex);
exit:
return err;
}
static int v9fs_dir_readdir_dotl(struct file *filp, void *dirent,
filldir_t filldir)
{
int over;
int err = 0;
struct p9_fid *fid;
int buflen;
struct p9_rdir *rdir;
struct p9_dirent curdirent;
u64 oldoffset = 0;
P9_DPRINTK(P9_DEBUG_VFS, "name %s\n", filp->f_path.dentry->d_name.name);
fid = filp->private_data;
buflen = fid->clnt->msize - P9_READDIRHDRSZ;
err = v9fs_alloc_rdir_buf(filp, buflen);
if (err)
goto exit;
rdir = (struct p9_rdir *) fid->rdir;
err = mutex_lock_interruptible(&rdir->mutex);
if (err)
return err;
while (err == 0) {
if (rdir->tail == rdir->head) {
err = p9_client_readdir(fid, rdir->buf, buflen,
filp->f_pos);
if (err <= 0)
goto unlock_and_exit;
rdir->head = 0;
rdir->tail = err;
}
while (rdir->head < rdir->tail) {
err = p9dirent_read(fid->clnt, rdir->buf + rdir->head,
rdir->tail - rdir->head,
&curdirent);
if (err < 0) {
P9_DPRINTK(P9_DEBUG_VFS, "returned %d\n", err);
err = -EIO;
goto unlock_and_exit;
}
over = filldir(dirent, curdirent.d_name,
strlen(curdirent.d_name),
oldoffset, v9fs_qid2ino(&curdirent.qid),
curdirent.d_type);
oldoffset = curdirent.d_off;
if (over) {
err = 0;
goto unlock_and_exit;
}
filp->f_pos = curdirent.d_off;
rdir->head += err;
}
}
unlock_and_exit:
mutex_unlock(&rdir->mutex);
exit:
return err;
}
int v9fs_dir_release(struct inode *inode, struct file *filp)
{
struct p9_fid *fid;
fid = filp->private_data;
P9_DPRINTK(P9_DEBUG_VFS,
"v9fs_dir_release: inode: %p filp: %p fid: %d\n",
inode, filp, fid ? fid->fid : -1);
if (fid)
p9_client_clunk(fid);
return 0;
}
