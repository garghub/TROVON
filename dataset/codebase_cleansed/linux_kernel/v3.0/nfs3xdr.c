static void prepare_reply_buffer(struct rpc_rqst *req, struct page **pages,
unsigned int base, unsigned int len,
unsigned int bufsize)
{
struct rpc_auth *auth = req->rq_cred->cr_auth;
unsigned int replen;
replen = RPC_REPHDRSIZE + auth->au_rslack + bufsize;
xdr_inline_pages(&req->rq_rcv_buf, replen << 2, pages, base, len);
}
static void print_overflow_msg(const char *func, const struct xdr_stream *xdr)
{
dprintk("NFS: %s prematurely hit the end of our receive buffer. "
"Remaining buffer length is %tu words.\n",
func, xdr->end - xdr->p);
}
static void encode_uint32(struct xdr_stream *xdr, u32 value)
{
__be32 *p = xdr_reserve_space(xdr, 4);
*p = cpu_to_be32(value);
}
static int decode_uint32(struct xdr_stream *xdr, u32 *value)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
*value = be32_to_cpup(p);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_uint64(struct xdr_stream *xdr, u64 *value)
{
__be32 *p;
p = xdr_inline_decode(xdr, 8);
if (unlikely(p == NULL))
goto out_overflow;
xdr_decode_hyper(p, value);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static __be32 *xdr_decode_fileid3(__be32 *p, u64 *fileid)
{
return xdr_decode_hyper(p, fileid);
}
static int decode_fileid3(struct xdr_stream *xdr, u64 *fileid)
{
return decode_uint64(xdr, fileid);
}
static void encode_filename3(struct xdr_stream *xdr,
const char *name, u32 length)
{
__be32 *p;
BUG_ON(length > NFS3_MAXNAMLEN);
p = xdr_reserve_space(xdr, 4 + length);
xdr_encode_opaque(p, name, length);
}
static int decode_inline_filename3(struct xdr_stream *xdr,
const char **name, u32 *length)
{
__be32 *p;
u32 count;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
count = be32_to_cpup(p);
if (count > NFS3_MAXNAMLEN)
goto out_nametoolong;
p = xdr_inline_decode(xdr, count);
if (unlikely(p == NULL))
goto out_overflow;
*name = (const char *)p;
*length = count;
return 0;
out_nametoolong:
dprintk("NFS: returned filename too long: %u\n", count);
return -ENAMETOOLONG;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void encode_nfspath3(struct xdr_stream *xdr, struct page **pages,
const u32 length)
{
BUG_ON(length > NFS3_MAXPATHLEN);
encode_uint32(xdr, length);
xdr_write_pages(xdr, pages, 0, length);
}
static int decode_nfspath3(struct xdr_stream *xdr)
{
u32 recvd, count;
size_t hdrlen;
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
count = be32_to_cpup(p);
if (unlikely(count >= xdr->buf->page_len || count > NFS3_MAXPATHLEN))
goto out_nametoolong;
hdrlen = (u8 *)xdr->p - (u8 *)xdr->iov->iov_base;
recvd = xdr->buf->len - hdrlen;
if (unlikely(count > recvd))
goto out_cheating;
xdr_read_pages(xdr, count);
xdr_terminate_string(xdr->buf, count);
return 0;
out_nametoolong:
dprintk("NFS: returned pathname too long: %u\n", count);
return -ENAMETOOLONG;
out_cheating:
dprintk("NFS: server cheating in pathname result: "
"count %u > recvd %u\n", count, recvd);
return -EIO;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static __be32 *xdr_encode_cookie3(__be32 *p, u64 cookie)
{
return xdr_encode_hyper(p, cookie);
}
static int decode_cookie3(struct xdr_stream *xdr, u64 *cookie)
{
return decode_uint64(xdr, cookie);
}
static __be32 *xdr_encode_cookieverf3(__be32 *p, const __be32 *verifier)
{
memcpy(p, verifier, NFS3_COOKIEVERFSIZE);
return p + XDR_QUADLEN(NFS3_COOKIEVERFSIZE);
}
static int decode_cookieverf3(struct xdr_stream *xdr, __be32 *verifier)
{
__be32 *p;
p = xdr_inline_decode(xdr, NFS3_COOKIEVERFSIZE);
if (unlikely(p == NULL))
goto out_overflow;
memcpy(verifier, p, NFS3_COOKIEVERFSIZE);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void encode_createverf3(struct xdr_stream *xdr, const __be32 *verifier)
{
__be32 *p;
p = xdr_reserve_space(xdr, NFS3_CREATEVERFSIZE);
memcpy(p, verifier, NFS3_CREATEVERFSIZE);
}
static int decode_writeverf3(struct xdr_stream *xdr, __be32 *verifier)
{
__be32 *p;
p = xdr_inline_decode(xdr, NFS3_WRITEVERFSIZE);
if (unlikely(p == NULL))
goto out_overflow;
memcpy(verifier, p, NFS3_WRITEVERFSIZE);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static __be32 *xdr_decode_size3(__be32 *p, u64 *size)
{
return xdr_decode_hyper(p, size);
}
static int decode_nfsstat3(struct xdr_stream *xdr, enum nfs_stat *status)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
*status = be32_to_cpup(p);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void encode_ftype3(struct xdr_stream *xdr, const u32 type)
{
BUG_ON(type > NF3FIFO);
encode_uint32(xdr, type);
}
static __be32 *xdr_decode_ftype3(__be32 *p, umode_t *mode)
{
u32 type;
type = be32_to_cpup(p++);
if (type > NF3FIFO)
type = NF3NON;
*mode = nfs_type2fmt[type];
return p;
}
static void encode_specdata3(struct xdr_stream *xdr, const dev_t rdev)
{
__be32 *p;
p = xdr_reserve_space(xdr, 8);
*p++ = cpu_to_be32(MAJOR(rdev));
*p = cpu_to_be32(MINOR(rdev));
}
static __be32 *xdr_decode_specdata3(__be32 *p, dev_t *rdev)
{
unsigned int major, minor;
major = be32_to_cpup(p++);
minor = be32_to_cpup(p++);
*rdev = MKDEV(major, minor);
if (MAJOR(*rdev) != major || MINOR(*rdev) != minor)
*rdev = 0;
return p;
}
static void encode_nfs_fh3(struct xdr_stream *xdr, const struct nfs_fh *fh)
{
__be32 *p;
BUG_ON(fh->size > NFS3_FHSIZE);
p = xdr_reserve_space(xdr, 4 + fh->size);
xdr_encode_opaque(p, fh->data, fh->size);
}
static int decode_nfs_fh3(struct xdr_stream *xdr, struct nfs_fh *fh)
{
u32 length;
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
length = be32_to_cpup(p++);
if (unlikely(length > NFS3_FHSIZE))
goto out_toobig;
p = xdr_inline_decode(xdr, length);
if (unlikely(p == NULL))
goto out_overflow;
fh->size = length;
memcpy(fh->data, p, length);
return 0;
out_toobig:
dprintk("NFS: file handle size (%u) too big\n", length);
return -E2BIG;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void zero_nfs_fh3(struct nfs_fh *fh)
{
memset(fh, 0, sizeof(*fh));
}
static __be32 *xdr_encode_nfstime3(__be32 *p, const struct timespec *timep)
{
*p++ = cpu_to_be32(timep->tv_sec);
*p++ = cpu_to_be32(timep->tv_nsec);
return p;
}
static __be32 *xdr_decode_nfstime3(__be32 *p, struct timespec *timep)
{
timep->tv_sec = be32_to_cpup(p++);
timep->tv_nsec = be32_to_cpup(p++);
return p;
}
static void encode_sattr3(struct xdr_stream *xdr, const struct iattr *attr)
{
u32 nbytes;
__be32 *p;
nbytes = 6 * 4;
if (attr->ia_valid & ATTR_MODE)
nbytes += 4;
if (attr->ia_valid & ATTR_UID)
nbytes += 4;
if (attr->ia_valid & ATTR_GID)
nbytes += 4;
if (attr->ia_valid & ATTR_SIZE)
nbytes += 8;
if (attr->ia_valid & ATTR_ATIME_SET)
nbytes += 8;
if (attr->ia_valid & ATTR_MTIME_SET)
nbytes += 8;
p = xdr_reserve_space(xdr, nbytes);
if (attr->ia_valid & ATTR_MODE) {
*p++ = xdr_one;
*p++ = cpu_to_be32(attr->ia_mode & S_IALLUGO);
} else
*p++ = xdr_zero;
if (attr->ia_valid & ATTR_UID) {
*p++ = xdr_one;
*p++ = cpu_to_be32(attr->ia_uid);
} else
*p++ = xdr_zero;
if (attr->ia_valid & ATTR_GID) {
*p++ = xdr_one;
*p++ = cpu_to_be32(attr->ia_gid);
} else
*p++ = xdr_zero;
if (attr->ia_valid & ATTR_SIZE) {
*p++ = xdr_one;
p = xdr_encode_hyper(p, (u64)attr->ia_size);
} else
*p++ = xdr_zero;
if (attr->ia_valid & ATTR_ATIME_SET) {
*p++ = xdr_two;
p = xdr_encode_nfstime3(p, &attr->ia_atime);
} else if (attr->ia_valid & ATTR_ATIME) {
*p++ = xdr_one;
} else
*p++ = xdr_zero;
if (attr->ia_valid & ATTR_MTIME_SET) {
*p++ = xdr_two;
xdr_encode_nfstime3(p, &attr->ia_mtime);
} else if (attr->ia_valid & ATTR_MTIME) {
*p = xdr_one;
} else
*p = xdr_zero;
}
static int decode_fattr3(struct xdr_stream *xdr, struct nfs_fattr *fattr)
{
umode_t fmode;
__be32 *p;
p = xdr_inline_decode(xdr, NFS3_fattr_sz << 2);
if (unlikely(p == NULL))
goto out_overflow;
p = xdr_decode_ftype3(p, &fmode);
fattr->mode = (be32_to_cpup(p++) & ~S_IFMT) | fmode;
fattr->nlink = be32_to_cpup(p++);
fattr->uid = be32_to_cpup(p++);
fattr->gid = be32_to_cpup(p++);
p = xdr_decode_size3(p, &fattr->size);
p = xdr_decode_size3(p, &fattr->du.nfs3.used);
p = xdr_decode_specdata3(p, &fattr->rdev);
p = xdr_decode_hyper(p, &fattr->fsid.major);
fattr->fsid.minor = 0;
p = xdr_decode_fileid3(p, &fattr->fileid);
p = xdr_decode_nfstime3(p, &fattr->atime);
p = xdr_decode_nfstime3(p, &fattr->mtime);
xdr_decode_nfstime3(p, &fattr->ctime);
fattr->valid |= NFS_ATTR_FATTR_V3;
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_post_op_attr(struct xdr_stream *xdr, struct nfs_fattr *fattr)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p != xdr_zero)
return decode_fattr3(xdr, fattr);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_wcc_attr(struct xdr_stream *xdr, struct nfs_fattr *fattr)
{
__be32 *p;
p = xdr_inline_decode(xdr, NFS3_wcc_attr_sz << 2);
if (unlikely(p == NULL))
goto out_overflow;
fattr->valid |= NFS_ATTR_FATTR_PRESIZE
| NFS_ATTR_FATTR_PREMTIME
| NFS_ATTR_FATTR_PRECTIME;
p = xdr_decode_size3(p, &fattr->pre_size);
p = xdr_decode_nfstime3(p, &fattr->pre_mtime);
xdr_decode_nfstime3(p, &fattr->pre_ctime);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_pre_op_attr(struct xdr_stream *xdr, struct nfs_fattr *fattr)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p != xdr_zero)
return decode_wcc_attr(xdr, fattr);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_wcc_data(struct xdr_stream *xdr, struct nfs_fattr *fattr)
{
int error;
error = decode_pre_op_attr(xdr, fattr);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, fattr);
out:
return error;
}
static int decode_post_op_fh3(struct xdr_stream *xdr, struct nfs_fh *fh)
{
__be32 *p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p != xdr_zero)
return decode_nfs_fh3(xdr, fh);
zero_nfs_fh3(fh);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void encode_diropargs3(struct xdr_stream *xdr, const struct nfs_fh *fh,
const char *name, u32 length)
{
encode_nfs_fh3(xdr, fh);
encode_filename3(xdr, name, length);
}
static void nfs3_xdr_enc_getattr3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_fh *fh)
{
encode_nfs_fh3(xdr, fh);
}
static void encode_sattrguard3(struct xdr_stream *xdr,
const struct nfs3_sattrargs *args)
{
__be32 *p;
if (args->guard) {
p = xdr_reserve_space(xdr, 4 + 8);
*p++ = xdr_one;
xdr_encode_nfstime3(p, &args->guardtime);
} else {
p = xdr_reserve_space(xdr, 4);
*p = xdr_zero;
}
}
static void nfs3_xdr_enc_setattr3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_sattrargs *args)
{
encode_nfs_fh3(xdr, args->fh);
encode_sattr3(xdr, args->sattr);
encode_sattrguard3(xdr, args);
}
static void nfs3_xdr_enc_lookup3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_diropargs *args)
{
encode_diropargs3(xdr, args->fh, args->name, args->len);
}
static void encode_access3args(struct xdr_stream *xdr,
const struct nfs3_accessargs *args)
{
encode_nfs_fh3(xdr, args->fh);
encode_uint32(xdr, args->access);
}
static void nfs3_xdr_enc_access3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_accessargs *args)
{
encode_access3args(xdr, args);
}
static void nfs3_xdr_enc_readlink3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_readlinkargs *args)
{
encode_nfs_fh3(xdr, args->fh);
prepare_reply_buffer(req, args->pages, args->pgbase,
args->pglen, NFS3_readlinkres_sz);
}
static void encode_read3args(struct xdr_stream *xdr,
const struct nfs_readargs *args)
{
__be32 *p;
encode_nfs_fh3(xdr, args->fh);
p = xdr_reserve_space(xdr, 8 + 4);
p = xdr_encode_hyper(p, args->offset);
*p = cpu_to_be32(args->count);
}
static void nfs3_xdr_enc_read3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_readargs *args)
{
encode_read3args(xdr, args);
prepare_reply_buffer(req, args->pages, args->pgbase,
args->count, NFS3_readres_sz);
req->rq_rcv_buf.flags |= XDRBUF_READ;
}
static void encode_write3args(struct xdr_stream *xdr,
const struct nfs_writeargs *args)
{
__be32 *p;
encode_nfs_fh3(xdr, args->fh);
p = xdr_reserve_space(xdr, 8 + 4 + 4 + 4);
p = xdr_encode_hyper(p, args->offset);
*p++ = cpu_to_be32(args->count);
*p++ = cpu_to_be32(args->stable);
*p = cpu_to_be32(args->count);
xdr_write_pages(xdr, args->pages, args->pgbase, args->count);
}
static void nfs3_xdr_enc_write3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_writeargs *args)
{
encode_write3args(xdr, args);
xdr->buf->flags |= XDRBUF_WRITE;
}
static void encode_createhow3(struct xdr_stream *xdr,
const struct nfs3_createargs *args)
{
encode_uint32(xdr, args->createmode);
switch (args->createmode) {
case NFS3_CREATE_UNCHECKED:
case NFS3_CREATE_GUARDED:
encode_sattr3(xdr, args->sattr);
break;
case NFS3_CREATE_EXCLUSIVE:
encode_createverf3(xdr, args->verifier);
break;
default:
BUG();
}
}
static void nfs3_xdr_enc_create3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_createargs *args)
{
encode_diropargs3(xdr, args->fh, args->name, args->len);
encode_createhow3(xdr, args);
}
static void nfs3_xdr_enc_mkdir3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_mkdirargs *args)
{
encode_diropargs3(xdr, args->fh, args->name, args->len);
encode_sattr3(xdr, args->sattr);
}
static void encode_symlinkdata3(struct xdr_stream *xdr,
const struct nfs3_symlinkargs *args)
{
encode_sattr3(xdr, args->sattr);
encode_nfspath3(xdr, args->pages, args->pathlen);
}
static void nfs3_xdr_enc_symlink3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_symlinkargs *args)
{
encode_diropargs3(xdr, args->fromfh, args->fromname, args->fromlen);
encode_symlinkdata3(xdr, args);
}
static void encode_devicedata3(struct xdr_stream *xdr,
const struct nfs3_mknodargs *args)
{
encode_sattr3(xdr, args->sattr);
encode_specdata3(xdr, args->rdev);
}
static void encode_mknoddata3(struct xdr_stream *xdr,
const struct nfs3_mknodargs *args)
{
encode_ftype3(xdr, args->type);
switch (args->type) {
case NF3CHR:
case NF3BLK:
encode_devicedata3(xdr, args);
break;
case NF3SOCK:
case NF3FIFO:
encode_sattr3(xdr, args->sattr);
break;
case NF3REG:
case NF3DIR:
break;
default:
BUG();
}
}
static void nfs3_xdr_enc_mknod3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_mknodargs *args)
{
encode_diropargs3(xdr, args->fh, args->name, args->len);
encode_mknoddata3(xdr, args);
}
static void nfs3_xdr_enc_remove3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_removeargs *args)
{
encode_diropargs3(xdr, args->fh, args->name.name, args->name.len);
}
static void nfs3_xdr_enc_rename3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_renameargs *args)
{
const struct qstr *old = args->old_name;
const struct qstr *new = args->new_name;
encode_diropargs3(xdr, args->old_dir, old->name, old->len);
encode_diropargs3(xdr, args->new_dir, new->name, new->len);
}
static void nfs3_xdr_enc_link3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_linkargs *args)
{
encode_nfs_fh3(xdr, args->fromfh);
encode_diropargs3(xdr, args->tofh, args->toname, args->tolen);
}
static void encode_readdir3args(struct xdr_stream *xdr,
const struct nfs3_readdirargs *args)
{
__be32 *p;
encode_nfs_fh3(xdr, args->fh);
p = xdr_reserve_space(xdr, 8 + NFS3_COOKIEVERFSIZE + 4);
p = xdr_encode_cookie3(p, args->cookie);
p = xdr_encode_cookieverf3(p, args->verf);
*p = cpu_to_be32(args->count);
}
static void nfs3_xdr_enc_readdir3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_readdirargs *args)
{
encode_readdir3args(xdr, args);
prepare_reply_buffer(req, args->pages, 0,
args->count, NFS3_readdirres_sz);
}
static void encode_readdirplus3args(struct xdr_stream *xdr,
const struct nfs3_readdirargs *args)
{
__be32 *p;
encode_nfs_fh3(xdr, args->fh);
p = xdr_reserve_space(xdr, 8 + NFS3_COOKIEVERFSIZE + 4 + 4);
p = xdr_encode_cookie3(p, args->cookie);
p = xdr_encode_cookieverf3(p, args->verf);
*p++ = cpu_to_be32(args->count >> 3);
*p = cpu_to_be32(args->count);
}
static void nfs3_xdr_enc_readdirplus3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_readdirargs *args)
{
encode_readdirplus3args(xdr, args);
prepare_reply_buffer(req, args->pages, 0,
args->count, NFS3_readdirres_sz);
}
static void encode_commit3args(struct xdr_stream *xdr,
const struct nfs_writeargs *args)
{
__be32 *p;
encode_nfs_fh3(xdr, args->fh);
p = xdr_reserve_space(xdr, 8 + 4);
p = xdr_encode_hyper(p, args->offset);
*p = cpu_to_be32(args->count);
}
static void nfs3_xdr_enc_commit3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs_writeargs *args)
{
encode_commit3args(xdr, args);
}
static void nfs3_xdr_enc_getacl3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_getaclargs *args)
{
encode_nfs_fh3(xdr, args->fh);
encode_uint32(xdr, args->mask);
if (args->mask & (NFS_ACL | NFS_DFACL))
prepare_reply_buffer(req, args->pages, 0,
NFSACL_MAXPAGES << PAGE_SHIFT,
ACL3_getaclres_sz);
}
static void nfs3_xdr_enc_setacl3args(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfs3_setaclargs *args)
{
unsigned int base;
int error;
encode_nfs_fh3(xdr, NFS_FH(args->inode));
encode_uint32(xdr, args->mask);
base = req->rq_slen;
if (args->npages != 0)
xdr_write_pages(xdr, args->pages, 0, args->len);
else
xdr_reserve_space(xdr, NFS_ACL_INLINE_BUFSIZE);
error = nfsacl_encode(xdr->buf, base, args->inode,
(args->mask & NFS_ACL) ?
args->acl_access : NULL, 1, 0);
BUG_ON(error < 0);
error = nfsacl_encode(xdr->buf, base + error, args->inode,
(args->mask & NFS_DFACL) ?
args->acl_default : NULL, 1,
NFS_ACL_DEFAULT);
BUG_ON(error < 0);
}
static int nfs3_xdr_dec_getattr3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fattr *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_fattr3(xdr, result);
out:
return error;
out_default:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_setattr3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fattr *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_lookup3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs3_diropres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_nfs_fh3(xdr, result->fh);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->dir_attr);
out:
return error;
out_default:
error = decode_post_op_attr(xdr, result->dir_attr);
if (unlikely(error))
goto out;
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_access3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs3_accessres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_uint32(xdr, &result->access);
out:
return error;
out_default:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_readlink3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fattr *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_nfspath3(xdr);
out:
return error;
out_default:
return nfs_stat_to_errno(status);
}
static int decode_read3resok(struct xdr_stream *xdr,
struct nfs_readres *result)
{
u32 eof, count, ocount, recvd;
size_t hdrlen;
__be32 *p;
p = xdr_inline_decode(xdr, 4 + 4 + 4);
if (unlikely(p == NULL))
goto out_overflow;
count = be32_to_cpup(p++);
eof = be32_to_cpup(p++);
ocount = be32_to_cpup(p++);
if (unlikely(ocount != count))
goto out_mismatch;
hdrlen = (u8 *)xdr->p - (u8 *)xdr->iov->iov_base;
recvd = xdr->buf->len - hdrlen;
if (unlikely(count > recvd))
goto out_cheating;
out:
xdr_read_pages(xdr, count);
result->eof = eof;
result->count = count;
return count;
out_mismatch:
dprintk("NFS: READ count doesn't match length of opaque: "
"count %u != ocount %u\n", count, ocount);
return -EIO;
out_cheating:
dprintk("NFS: server cheating in read result: "
"count %u > recvd %u\n", count, recvd);
count = recvd;
eof = 0;
goto out;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int nfs3_xdr_dec_read3res(struct rpc_rqst *req, struct xdr_stream *xdr,
struct nfs_readres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_read3resok(xdr, result);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int decode_write3resok(struct xdr_stream *xdr,
struct nfs_writeres *result)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4 + 4 + NFS3_WRITEVERFSIZE);
if (unlikely(p == NULL))
goto out_overflow;
result->count = be32_to_cpup(p++);
result->verf->committed = be32_to_cpup(p++);
if (unlikely(result->verf->committed > NFS_FILE_SYNC))
goto out_badvalue;
memcpy(result->verf->verifier, p, NFS3_WRITEVERFSIZE);
return result->count;
out_badvalue:
dprintk("NFS: bad stable_how value: %u\n", result->verf->committed);
return -EIO;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int nfs3_xdr_dec_write3res(struct rpc_rqst *req, struct xdr_stream *xdr,
struct nfs_writeres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_write3resok(xdr, result);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int decode_create3resok(struct xdr_stream *xdr,
struct nfs3_diropres *result)
{
int error;
error = decode_post_op_fh3(xdr, result->fh);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (result->fh->size == 0)
result->fattr->valid = 0;
error = decode_wcc_data(xdr, result->dir_attr);
out:
return error;
}
static int nfs3_xdr_dec_create3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs3_diropres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_create3resok(xdr, result);
out:
return error;
out_default:
error = decode_wcc_data(xdr, result->dir_attr);
if (unlikely(error))
goto out;
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_remove3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_removeres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->dir_attr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_rename3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_renameres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->old_fattr);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->new_fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_link3res(struct rpc_rqst *req, struct xdr_stream *xdr,
struct nfs3_linkres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->dir_attr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
int nfs3_decode_dirent(struct xdr_stream *xdr, struct nfs_entry *entry,
int plus)
{
struct nfs_entry old = *entry;
__be32 *p;
int error;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p == xdr_zero) {
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p == xdr_zero)
return -EAGAIN;
entry->eof = 1;
return -EBADCOOKIE;
}
error = decode_fileid3(xdr, &entry->ino);
if (unlikely(error))
return error;
error = decode_inline_filename3(xdr, &entry->name, &entry->len);
if (unlikely(error))
return error;
entry->prev_cookie = entry->cookie;
error = decode_cookie3(xdr, &entry->cookie);
if (unlikely(error))
return error;
entry->d_type = DT_UNKNOWN;
if (plus) {
entry->fattr->valid = 0;
error = decode_post_op_attr(xdr, entry->fattr);
if (unlikely(error))
return error;
if (entry->fattr->valid & NFS_ATTR_FATTR_V3)
entry->d_type = nfs_umode_to_dtype(entry->fattr->mode);
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_overflow;
if (*p != xdr_zero) {
error = decode_nfs_fh3(xdr, entry->fh);
if (unlikely(error)) {
if (error == -E2BIG)
goto out_truncated;
return error;
}
} else
zero_nfs_fh3(entry->fh);
}
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EAGAIN;
out_truncated:
dprintk("NFS: directory entry contains invalid file handle\n");
*entry = old;
return -EAGAIN;
}
static int decode_dirlist3(struct xdr_stream *xdr)
{
u32 recvd, pglen;
size_t hdrlen;
pglen = xdr->buf->page_len;
hdrlen = (u8 *)xdr->p - (u8 *)xdr->iov->iov_base;
recvd = xdr->buf->len - hdrlen;
if (unlikely(pglen > recvd))
goto out_cheating;
out:
xdr_read_pages(xdr, pglen);
return pglen;
out_cheating:
dprintk("NFS: server cheating in readdir result: "
"pglen %u > recvd %u\n", pglen, recvd);
pglen = recvd;
goto out;
}
static int decode_readdir3resok(struct xdr_stream *xdr,
struct nfs3_readdirres *result)
{
int error;
error = decode_post_op_attr(xdr, result->dir_attr);
if (unlikely(error))
goto out;
error = decode_cookieverf3(xdr, result->verf);
if (unlikely(error))
goto out;
error = decode_dirlist3(xdr);
out:
return error;
}
static int nfs3_xdr_dec_readdir3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs3_readdirres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_readdir3resok(xdr, result);
out:
return error;
out_default:
error = decode_post_op_attr(xdr, result->dir_attr);
if (unlikely(error))
goto out;
return nfs_stat_to_errno(status);
}
static int decode_fsstat3resok(struct xdr_stream *xdr,
struct nfs_fsstat *result)
{
__be32 *p;
p = xdr_inline_decode(xdr, 8 * 6 + 4);
if (unlikely(p == NULL))
goto out_overflow;
p = xdr_decode_size3(p, &result->tbytes);
p = xdr_decode_size3(p, &result->fbytes);
p = xdr_decode_size3(p, &result->abytes);
p = xdr_decode_size3(p, &result->tfiles);
p = xdr_decode_size3(p, &result->ffiles);
xdr_decode_size3(p, &result->afiles);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int nfs3_xdr_dec_fsstat3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fsstat *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_fsstat3resok(xdr, result);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int decode_fsinfo3resok(struct xdr_stream *xdr,
struct nfs_fsinfo *result)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4 * 7 + 8 + 8 + 4);
if (unlikely(p == NULL))
goto out_overflow;
result->rtmax = be32_to_cpup(p++);
result->rtpref = be32_to_cpup(p++);
result->rtmult = be32_to_cpup(p++);
result->wtmax = be32_to_cpup(p++);
result->wtpref = be32_to_cpup(p++);
result->wtmult = be32_to_cpup(p++);
result->dtpref = be32_to_cpup(p++);
p = xdr_decode_size3(p, &result->maxfilesize);
xdr_decode_nfstime3(p, &result->time_delta);
result->lease_time = 0;
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int nfs3_xdr_dec_fsinfo3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fsinfo *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_fsinfo3resok(xdr, result);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int decode_pathconf3resok(struct xdr_stream *xdr,
struct nfs_pathconf *result)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4 * 6);
if (unlikely(p == NULL))
goto out_overflow;
result->max_link = be32_to_cpup(p++);
result->max_namelen = be32_to_cpup(p);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int nfs3_xdr_dec_pathconf3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_pathconf *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_pathconf3resok(xdr, result);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_commit3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_writeres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
error = decode_wcc_data(xdr, result->fattr);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_status;
error = decode_writeverf3(xdr, result->verf->verifier);
out:
return error;
out_status:
return nfs_stat_to_errno(status);
}
static inline int decode_getacl3resok(struct xdr_stream *xdr,
struct nfs3_getaclres *result)
{
struct posix_acl **acl;
unsigned int *aclcnt;
size_t hdrlen;
int error;
error = decode_post_op_attr(xdr, result->fattr);
if (unlikely(error))
goto out;
error = decode_uint32(xdr, &result->mask);
if (unlikely(error))
goto out;
error = -EINVAL;
if (result->mask & ~(NFS_ACL|NFS_ACLCNT|NFS_DFACL|NFS_DFACLCNT))
goto out;
hdrlen = (u8 *)xdr->p - (u8 *)xdr->iov->iov_base;
acl = NULL;
if (result->mask & NFS_ACL)
acl = &result->acl_access;
aclcnt = NULL;
if (result->mask & NFS_ACLCNT)
aclcnt = &result->acl_access_count;
error = nfsacl_decode(xdr->buf, hdrlen, aclcnt, acl);
if (unlikely(error <= 0))
goto out;
acl = NULL;
if (result->mask & NFS_DFACL)
acl = &result->acl_default;
aclcnt = NULL;
if (result->mask & NFS_DFACLCNT)
aclcnt = &result->acl_default_count;
error = nfsacl_decode(xdr->buf, hdrlen + error, aclcnt, acl);
if (unlikely(error <= 0))
return error;
error = 0;
out:
return error;
}
static int nfs3_xdr_dec_getacl3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs3_getaclres *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_getacl3resok(xdr, result);
out:
return error;
out_default:
return nfs_stat_to_errno(status);
}
static int nfs3_xdr_dec_setacl3res(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs_fattr *result)
{
enum nfs_stat status;
int error;
error = decode_nfsstat3(xdr, &status);
if (unlikely(error))
goto out;
if (status != NFS3_OK)
goto out_default;
error = decode_post_op_attr(xdr, result);
out:
return error;
out_default:
return nfs_stat_to_errno(status);
}
