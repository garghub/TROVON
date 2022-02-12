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
static int v9fs_dir_readdir(struct file *file, struct dir_context *ctx)
{
bool over;
struct p9_wstat st;
int err = 0;
struct p9_fid *fid;
int buflen;
int reclen = 0;
struct p9_rdir *rdir;
struct kvec kvec;
p9_debug(P9_DEBUG_VFS, "name %pD\n", file);
fid = file->private_data;
buflen = fid->clnt->msize - P9_IOHDRSZ;
rdir = v9fs_alloc_rdir_buf(file, buflen);
if (!rdir)
return -ENOMEM;
kvec.iov_base = rdir->buf;
kvec.iov_len = buflen;
while (1) {
if (rdir->tail == rdir->head) {
struct iov_iter to;
int n;
iov_iter_kvec(&to, READ | ITER_KVEC, &kvec, 1, buflen);
n = p9_client_read(file->private_data, ctx->pos, &to,
&err);
if (err)
return err;
if (n == 0)
return 0;
rdir->head = 0;
rdir->tail = n;
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
over = !dir_emit(ctx, st.name, strlen(st.name),
v9fs_qid2ino(&st.qid), dt_type(&st));
p9stat_free(&st);
if (over)
return 0;
rdir->head += reclen;
ctx->pos += reclen;
}
}
}
static int v9fs_dir_readdir_dotl(struct file *file, struct dir_context *ctx)
{
int err = 0;
struct p9_fid *fid;
int buflen;
struct p9_rdir *rdir;
struct p9_dirent curdirent;
p9_debug(P9_DEBUG_VFS, "name %pD\n", file);
fid = file->private_data;
buflen = fid->clnt->msize - P9_READDIRHDRSZ;
rdir = v9fs_alloc_rdir_buf(file, buflen);
if (!rdir)
return -ENOMEM;
while (1) {
if (rdir->tail == rdir->head) {
err = p9_client_readdir(fid, rdir->buf, buflen,
ctx->pos);
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
if (!dir_emit(ctx, curdirent.d_name,
strlen(curdirent.d_name),
v9fs_qid2ino(&curdirent.qid),
curdirent.d_type))
return 0;
ctx->pos = curdirent.d_off;
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
