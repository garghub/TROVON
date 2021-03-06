static __be32
nfsd_proc_null(struct svc_rqst *rqstp, void *argp, void *resp)
{
return nfs_ok;
}
static __be32
nfsd_return_attrs(__be32 err, struct nfsd_attrstat *resp)
{
if (err) return err;
return nfserrno(vfs_getattr(resp->fh.fh_export->ex_path.mnt,
resp->fh.fh_dentry,
&resp->stat));
}
static __be32
nfsd_return_dirop(__be32 err, struct nfsd_diropres *resp)
{
if (err) return err;
return nfserrno(vfs_getattr(resp->fh.fh_export->ex_path.mnt,
resp->fh.fh_dentry,
&resp->stat));
}
static __be32
nfsd_proc_getattr(struct svc_rqst *rqstp, struct nfsd_fhandle *argp,
struct nfsd_attrstat *resp)
{
__be32 nfserr;
dprintk("nfsd: GETATTR %s\n", SVCFH_fmt(&argp->fh));
fh_copy(&resp->fh, &argp->fh);
nfserr = fh_verify(rqstp, &resp->fh, 0,
NFSD_MAY_NOP | NFSD_MAY_BYPASS_GSS_ON_ROOT);
return nfsd_return_attrs(nfserr, resp);
}
static __be32
nfsd_proc_setattr(struct svc_rqst *rqstp, struct nfsd_sattrargs *argp,
struct nfsd_attrstat *resp)
{
__be32 nfserr;
dprintk("nfsd: SETATTR %s, valid=%x, size=%ld\n",
SVCFH_fmt(&argp->fh),
argp->attrs.ia_valid, (long) argp->attrs.ia_size);
fh_copy(&resp->fh, &argp->fh);
nfserr = nfsd_setattr(rqstp, &resp->fh, &argp->attrs,0, (time_t)0);
return nfsd_return_attrs(nfserr, resp);
}
static __be32
nfsd_proc_lookup(struct svc_rqst *rqstp, struct nfsd_diropargs *argp,
struct nfsd_diropres *resp)
{
__be32 nfserr;
dprintk("nfsd: LOOKUP %s %.*s\n",
SVCFH_fmt(&argp->fh), argp->len, argp->name);
fh_init(&resp->fh, NFS_FHSIZE);
nfserr = nfsd_lookup(rqstp, &argp->fh, argp->name, argp->len,
&resp->fh);
fh_put(&argp->fh);
return nfsd_return_dirop(nfserr, resp);
}
static __be32
nfsd_proc_readlink(struct svc_rqst *rqstp, struct nfsd_readlinkargs *argp,
struct nfsd_readlinkres *resp)
{
__be32 nfserr;
dprintk("nfsd: READLINK %s\n", SVCFH_fmt(&argp->fh));
resp->len = NFS_MAXPATHLEN;
nfserr = nfsd_readlink(rqstp, &argp->fh, argp->buffer, &resp->len);
fh_put(&argp->fh);
return nfserr;
}
static __be32
nfsd_proc_read(struct svc_rqst *rqstp, struct nfsd_readargs *argp,
struct nfsd_readres *resp)
{
__be32 nfserr;
dprintk("nfsd: READ %s %d bytes at %d\n",
SVCFH_fmt(&argp->fh),
argp->count, argp->offset);
if (NFSSVC_MAXBLKSIZE_V2 < argp->count) {
char buf[RPC_MAX_ADDRBUFLEN];
printk(KERN_NOTICE
"oversized read request from %s (%d bytes)\n",
svc_print_addr(rqstp, buf, sizeof(buf)),
argp->count);
argp->count = NFSSVC_MAXBLKSIZE_V2;
}
svc_reserve_auth(rqstp, (19<<2) + argp->count + 4);
resp->count = argp->count;
nfserr = nfsd_read(rqstp, fh_copy(&resp->fh, &argp->fh),
argp->offset,
rqstp->rq_vec, argp->vlen,
&resp->count);
if (nfserr) return nfserr;
return nfserrno(vfs_getattr(resp->fh.fh_export->ex_path.mnt,
resp->fh.fh_dentry,
&resp->stat));
}
static __be32
nfsd_proc_write(struct svc_rqst *rqstp, struct nfsd_writeargs *argp,
struct nfsd_attrstat *resp)
{
__be32 nfserr;
int stable = 1;
unsigned long cnt = argp->len;
dprintk("nfsd: WRITE %s %d bytes at %d\n",
SVCFH_fmt(&argp->fh),
argp->len, argp->offset);
nfserr = nfsd_write(rqstp, fh_copy(&resp->fh, &argp->fh), NULL,
argp->offset,
rqstp->rq_vec, argp->vlen,
&cnt,
&stable);
return nfsd_return_attrs(nfserr, resp);
}
static __be32
nfsd_proc_create(struct svc_rqst *rqstp, struct nfsd_createargs *argp,
struct nfsd_diropres *resp)
{
svc_fh *dirfhp = &argp->fh;
svc_fh *newfhp = &resp->fh;
struct iattr *attr = &argp->attrs;
struct inode *inode;
struct dentry *dchild;
int type, mode;
__be32 nfserr;
int hosterr;
dev_t rdev = 0, wanted = new_decode_dev(attr->ia_size);
dprintk("nfsd: CREATE %s %.*s\n",
SVCFH_fmt(dirfhp), argp->len, argp->name);
nfserr = fh_verify(rqstp, dirfhp, S_IFDIR, NFSD_MAY_EXEC);
if (nfserr)
goto done;
nfserr = nfserr_acces;
if (!argp->len)
goto done;
nfserr = nfserr_exist;
if (isdotent(argp->name, argp->len))
goto done;
hosterr = fh_want_write(dirfhp);
if (hosterr) {
nfserr = nfserrno(hosterr);
goto done;
}
fh_lock_nested(dirfhp, I_MUTEX_PARENT);
dchild = lookup_one_len(argp->name, dirfhp->fh_dentry, argp->len);
if (IS_ERR(dchild)) {
nfserr = nfserrno(PTR_ERR(dchild));
goto out_unlock;
}
fh_init(newfhp, NFS_FHSIZE);
nfserr = fh_compose(newfhp, dirfhp->fh_export, dchild, dirfhp);
if (!nfserr && !dchild->d_inode)
nfserr = nfserr_noent;
dput(dchild);
if (nfserr) {
if (nfserr != nfserr_noent)
goto out_unlock;
nfserr = nfserr_acces;
if (!newfhp->fh_dentry) {
printk(KERN_WARNING
"nfsd_proc_create: file handle not verified\n");
goto out_unlock;
}
}
inode = newfhp->fh_dentry->d_inode;
if (attr->ia_valid & ATTR_MODE) {
type = attr->ia_mode & S_IFMT;
mode = attr->ia_mode & ~S_IFMT;
if (!type) {
if (inode) {
type = inode->i_mode & S_IFMT;
switch(type) {
case S_IFCHR:
case S_IFBLK:
rdev = inode->i_rdev;
attr->ia_valid |= ATTR_SIZE;
case S_IFIFO:
nfserr = nfsd_permission(rqstp,
newfhp->fh_export,
newfhp->fh_dentry,
NFSD_MAY_WRITE|NFSD_MAY_LOCAL_ACCESS);
if (nfserr && nfserr != nfserr_rofs)
goto out_unlock;
}
} else
type = S_IFREG;
}
} else if (inode) {
type = inode->i_mode & S_IFMT;
mode = inode->i_mode & ~S_IFMT;
} else {
type = S_IFREG;
mode = 0;
}
attr->ia_valid |= ATTR_MODE;
attr->ia_mode = mode;
if (type != S_IFREG) {
if (type != S_IFBLK && type != S_IFCHR) {
rdev = 0;
} else if (type == S_IFCHR && !(attr->ia_valid & ATTR_SIZE)) {
type = S_IFIFO;
} else {
if (!rdev)
rdev = wanted;
}
attr->ia_valid &= ~ATTR_SIZE;
nfserr = nfserr_exist;
if (inode && type != (inode->i_mode & S_IFMT))
goto out_unlock;
}
nfserr = 0;
if (!inode) {
nfserr = nfsd_create(rqstp, dirfhp, argp->name, argp->len,
attr, type, rdev, newfhp);
} else if (type == S_IFREG) {
dprintk("nfsd: existing %s, valid=%x, size=%ld\n",
argp->name, attr->ia_valid, (long) attr->ia_size);
attr->ia_valid &= ATTR_SIZE;
if (attr->ia_valid)
nfserr = nfsd_setattr(rqstp, newfhp, attr, 0, (time_t)0);
}
out_unlock:
fh_unlock(dirfhp);
fh_drop_write(dirfhp);
done:
fh_put(dirfhp);
return nfsd_return_dirop(nfserr, resp);
}
static __be32
nfsd_proc_remove(struct svc_rqst *rqstp, struct nfsd_diropargs *argp,
void *resp)
{
__be32 nfserr;
dprintk("nfsd: REMOVE %s %.*s\n", SVCFH_fmt(&argp->fh),
argp->len, argp->name);
nfserr = nfsd_unlink(rqstp, &argp->fh, -S_IFDIR, argp->name, argp->len);
fh_put(&argp->fh);
return nfserr;
}
static __be32
nfsd_proc_rename(struct svc_rqst *rqstp, struct nfsd_renameargs *argp,
void *resp)
{
__be32 nfserr;
dprintk("nfsd: RENAME %s %.*s -> \n",
SVCFH_fmt(&argp->ffh), argp->flen, argp->fname);
dprintk("nfsd: -> %s %.*s\n",
SVCFH_fmt(&argp->tfh), argp->tlen, argp->tname);
nfserr = nfsd_rename(rqstp, &argp->ffh, argp->fname, argp->flen,
&argp->tfh, argp->tname, argp->tlen);
fh_put(&argp->ffh);
fh_put(&argp->tfh);
return nfserr;
}
static __be32
nfsd_proc_link(struct svc_rqst *rqstp, struct nfsd_linkargs *argp,
void *resp)
{
__be32 nfserr;
dprintk("nfsd: LINK %s ->\n",
SVCFH_fmt(&argp->ffh));
dprintk("nfsd: %s %.*s\n",
SVCFH_fmt(&argp->tfh),
argp->tlen,
argp->tname);
nfserr = nfsd_link(rqstp, &argp->tfh, argp->tname, argp->tlen,
&argp->ffh);
fh_put(&argp->ffh);
fh_put(&argp->tfh);
return nfserr;
}
static __be32
nfsd_proc_symlink(struct svc_rqst *rqstp, struct nfsd_symlinkargs *argp,
void *resp)
{
struct svc_fh newfh;
__be32 nfserr;
dprintk("nfsd: SYMLINK %s %.*s -> %.*s\n",
SVCFH_fmt(&argp->ffh), argp->flen, argp->fname,
argp->tlen, argp->tname);
fh_init(&newfh, NFS_FHSIZE);
nfserr = nfsd_symlink(rqstp, &argp->ffh, argp->fname, argp->flen,
argp->tname, argp->tlen,
&newfh, &argp->attrs);
fh_put(&argp->ffh);
fh_put(&newfh);
return nfserr;
}
static __be32
nfsd_proc_mkdir(struct svc_rqst *rqstp, struct nfsd_createargs *argp,
struct nfsd_diropres *resp)
{
__be32 nfserr;
dprintk("nfsd: MKDIR %s %.*s\n", SVCFH_fmt(&argp->fh), argp->len, argp->name);
if (resp->fh.fh_dentry) {
printk(KERN_WARNING
"nfsd_proc_mkdir: response already verified??\n");
}
argp->attrs.ia_valid &= ~ATTR_SIZE;
fh_init(&resp->fh, NFS_FHSIZE);
nfserr = nfsd_create(rqstp, &argp->fh, argp->name, argp->len,
&argp->attrs, S_IFDIR, 0, &resp->fh);
fh_put(&argp->fh);
return nfsd_return_dirop(nfserr, resp);
}
static __be32
nfsd_proc_rmdir(struct svc_rqst *rqstp, struct nfsd_diropargs *argp,
void *resp)
{
__be32 nfserr;
dprintk("nfsd: RMDIR %s %.*s\n", SVCFH_fmt(&argp->fh), argp->len, argp->name);
nfserr = nfsd_unlink(rqstp, &argp->fh, S_IFDIR, argp->name, argp->len);
fh_put(&argp->fh);
return nfserr;
}
static __be32
nfsd_proc_readdir(struct svc_rqst *rqstp, struct nfsd_readdirargs *argp,
struct nfsd_readdirres *resp)
{
int count;
__be32 nfserr;
loff_t offset;
dprintk("nfsd: READDIR %s %d bytes at %d\n",
SVCFH_fmt(&argp->fh),
argp->count, argp->cookie);
count = (argp->count >> 2) - 2;
count -= 2;
if (count < 0)
count = 0;
resp->buffer = argp->buffer;
resp->offset = NULL;
resp->buflen = count;
resp->common.err = nfs_ok;
offset = argp->cookie;
nfserr = nfsd_readdir(rqstp, &argp->fh, &offset,
&resp->common, nfssvc_encode_entry);
resp->count = resp->buffer - argp->buffer;
if (resp->offset)
*resp->offset = htonl(offset);
fh_put(&argp->fh);
return nfserr;
}
static __be32
nfsd_proc_statfs(struct svc_rqst * rqstp, struct nfsd_fhandle *argp,
struct nfsd_statfsres *resp)
{
__be32 nfserr;
dprintk("nfsd: STATFS %s\n", SVCFH_fmt(&argp->fh));
nfserr = nfsd_statfs(rqstp, &argp->fh, &resp->stats,
NFSD_MAY_BYPASS_GSS_ON_ROOT);
fh_put(&argp->fh);
return nfserr;
}
__be32
nfserrno (int errno)
{
static struct {
__be32 nfserr;
int syserr;
} nfs_errtbl[] = {
{ nfs_ok, 0 },
{ nfserr_perm, -EPERM },
{ nfserr_noent, -ENOENT },
{ nfserr_io, -EIO },
{ nfserr_nxio, -ENXIO },
{ nfserr_acces, -EACCES },
{ nfserr_exist, -EEXIST },
{ nfserr_xdev, -EXDEV },
{ nfserr_mlink, -EMLINK },
{ nfserr_nodev, -ENODEV },
{ nfserr_notdir, -ENOTDIR },
{ nfserr_isdir, -EISDIR },
{ nfserr_inval, -EINVAL },
{ nfserr_fbig, -EFBIG },
{ nfserr_nospc, -ENOSPC },
{ nfserr_rofs, -EROFS },
{ nfserr_mlink, -EMLINK },
{ nfserr_nametoolong, -ENAMETOOLONG },
{ nfserr_notempty, -ENOTEMPTY },
#ifdef EDQUOT
{ nfserr_dquot, -EDQUOT },
#endif
{ nfserr_stale, -ESTALE },
{ nfserr_jukebox, -ETIMEDOUT },
{ nfserr_jukebox, -ERESTARTSYS },
{ nfserr_jukebox, -EAGAIN },
{ nfserr_jukebox, -EWOULDBLOCK },
{ nfserr_jukebox, -ENOMEM },
{ nfserr_io, -ETXTBSY },
{ nfserr_notsupp, -EOPNOTSUPP },
{ nfserr_toosmall, -ETOOSMALL },
{ nfserr_serverfault, -ESERVERFAULT },
};
int i;
for (i = 0; i < ARRAY_SIZE(nfs_errtbl); i++) {
if (nfs_errtbl[i].syserr == errno)
return nfs_errtbl[i].nfserr;
}
printk (KERN_INFO "nfsd: non-standard errno: %d\n", errno);
return nfserr_io;
}
