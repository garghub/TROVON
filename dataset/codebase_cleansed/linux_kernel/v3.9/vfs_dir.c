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
static struct p9_rdir *v9fs_alloc_rdir_buf(struct file *filp, int buflen)
{
struct p9_fid *fid = filp->private_data;
if (!fid->rdir)
fid->rdir = kzalloc(sizeof(struct p9_rdir) + buflen, GFP_KERNEL);
return fid->rdir;
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
p9_debug(P9_DEBUG_VFS, "name %s\n", filp->f_path.dentry->d_name.name);
fid = filp->private_data;
buflen = fid->clnt->msize - P9_IOHDRSZ;
rdir = v9fs_alloc_rdir_buf(filp, buflen);
if (!rdir)
return -ENOMEM;
while (1) {
if (rdir->tail == rdir->head) {
err = v9fs_file_readn(filp, rdir->buf, NULL,
buflen, filp->f_pos);
if (err <= 0)
return err;
rdir->head = 0;
rdir->tail = err;
}
while (rdir->head < rdir->tail) {
p9stat_init(&st);
err = p9stat_read(fid->clnt, rdir->buf + rdir->head,
rdir->tail - rdir->head, &st);
if (err) {
p9_debug(P9_DEBUG_VFS, "returned %d\n", err);
p9stat_free(&st);
return -EIO;
}
reclen = st.size+2;
over = filldir(dirent, st.name, strlen(st.name),
filp->f_pos, v9fs_qid2ino(&st.qid), dt_type(&st));
p9stat_free(&st);
if (over)
return 0;
rdir->head += reclen;
filp->f_pos += reclen;
}
}
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
p9_debug(P9_DEBUG_VFS, "name %s\n", filp->f_path.dentry->d_name.name);
fid = filp->private_data;
buflen = fid->clnt->msize - P9_READDIRHDRSZ;
rdir = v9fs_alloc_rdir_buf(filp, buflen);
if (!rdir)
return -ENOMEM;
while (1) {
if (rdir->tail == rdir->head) {
err = p9_client_readdir(fid, rdir->buf, buflen,
filp->f_pos);
if (err <= 0)
return err;
rdir->head = 0;
rdir->tail = err;
}
while (rdir->head < rdir->tail) {
err = p9dirent_read(fid->clnt, rdir->buf + rdir->head,
rdir->tail - rdir->head,
&curdirent);
if (err < 0) {
p9_debug(P9_DEBUG_VFS, "returned %d\n", err);
return -EIO;
}
over = filldir(dirent, curdirent.d_name,
strlen(curdirent.d_name),
oldoffset, v9fs_qid2ino(&curdirent.qid),
curdirent.d_type);
oldoffset = curdirent.d_off;
if (over)
return 0;
filp->f_pos = curdirent.d_off;
rdir->head += err;
}
}
}
int v9fs_dir_release(struct inode *inode, struct file *filp)
{
struct p9_fid *fid;
fid = filp->private_data;
p9_debug(P9_DEBUG_VFS, "inode: %p filp: %p fid: %d\n",
inode, filp, fid ? fid->fid : -1);
if (fid)
p9_client_clunk(fid);
return 0;
}
