static __be32
nfsd3_proc_null(struct svc_rqst *rqstp, void *argp, void *resp)
{
return nfs_ok;
}
static __be32 nfsd3_proc_getacl(struct svc_rqst * rqstp,
struct nfsd3_getaclargs *argp, struct nfsd3_getaclres *resp)
{
svc_fh *fh;
struct posix_acl *acl;
__be32 nfserr = 0;
fh = fh_copy(&resp->fh, &argp->fh);
nfserr = fh_verify(rqstp, &resp->fh, 0, NFSD_MAY_NOP);
if (nfserr)
RETURN_STATUS(nfserr);
if (argp->mask & ~(NFS_ACL|NFS_ACLCNT|NFS_DFACL|NFS_DFACLCNT))
RETURN_STATUS(nfserr_inval);
resp->mask = argp->mask;
if (resp->mask & (NFS_ACL|NFS_ACLCNT)) {
acl = nfsd_get_posix_acl(fh, ACL_TYPE_ACCESS);
if (IS_ERR(acl)) {
int err = PTR_ERR(acl);
if (err == -ENODATA || err == -EOPNOTSUPP)
acl = NULL;
else {
nfserr = nfserrno(err);
goto fail;
}
}
if (acl == NULL) {
struct inode *inode = fh->fh_dentry->d_inode;
acl = posix_acl_from_mode(inode->i_mode, GFP_KERNEL);
}
resp->acl_access = acl;
}
if (resp->mask & (NFS_DFACL|NFS_DFACLCNT)) {
acl = nfsd_get_posix_acl(fh, ACL_TYPE_DEFAULT);
if (IS_ERR(acl)) {
int err = PTR_ERR(acl);
if (err == -ENODATA || err == -EOPNOTSUPP)
acl = NULL;
else {
nfserr = nfserrno(err);
goto fail;
}
}
resp->acl_default = acl;
}
RETURN_STATUS(0);
fail:
posix_acl_release(resp->acl_access);
posix_acl_release(resp->acl_default);
RETURN_STATUS(nfserr);
}
static __be32 nfsd3_proc_setacl(struct svc_rqst * rqstp,
struct nfsd3_setaclargs *argp,
struct nfsd3_attrstat *resp)
{
svc_fh *fh;
__be32 nfserr = 0;
fh = fh_copy(&resp->fh, &argp->fh);
nfserr = fh_verify(rqstp, &resp->fh, 0, NFSD_MAY_SATTR);
if (!nfserr) {
nfserr = nfserrno( nfsd_set_posix_acl(
fh, ACL_TYPE_ACCESS, argp->acl_access) );
}
if (!nfserr) {
nfserr = nfserrno( nfsd_set_posix_acl(
fh, ACL_TYPE_DEFAULT, argp->acl_default) );
}
posix_acl_release(argp->acl_access);
posix_acl_release(argp->acl_default);
RETURN_STATUS(nfserr);
}
static int nfs3svc_decode_getaclargs(struct svc_rqst *rqstp, __be32 *p,
struct nfsd3_getaclargs *args)
{
if (!(p = nfs3svc_decode_fh(p, &args->fh)))
return 0;
args->mask = ntohl(*p); p++;
return xdr_argsize_check(rqstp, p);
}
static int nfs3svc_decode_setaclargs(struct svc_rqst *rqstp, __be32 *p,
struct nfsd3_setaclargs *args)
{
struct kvec *head = rqstp->rq_arg.head;
unsigned int base;
int n;
if (!(p = nfs3svc_decode_fh(p, &args->fh)))
return 0;
args->mask = ntohl(*p++);
if (args->mask & ~(NFS_ACL|NFS_ACLCNT|NFS_DFACL|NFS_DFACLCNT) ||
!xdr_argsize_check(rqstp, p))
return 0;
base = (char *)p - (char *)head->iov_base;
n = nfsacl_decode(&rqstp->rq_arg, base, NULL,
(args->mask & NFS_ACL) ?
&args->acl_access : NULL);
if (n > 0)
n = nfsacl_decode(&rqstp->rq_arg, base + n, NULL,
(args->mask & NFS_DFACL) ?
&args->acl_default : NULL);
return (n > 0);
}
static int nfs3svc_encode_getaclres(struct svc_rqst *rqstp, __be32 *p,
struct nfsd3_getaclres *resp)
{
struct dentry *dentry = resp->fh.fh_dentry;
p = nfs3svc_encode_post_op_attr(rqstp, p, &resp->fh);
if (resp->status == 0 && dentry && dentry->d_inode) {
struct inode *inode = dentry->d_inode;
struct kvec *head = rqstp->rq_res.head;
unsigned int base;
int n;
int w;
*p++ = htonl(resp->mask);
if (!xdr_ressize_check(rqstp, p))
return 0;
base = (char *)p - (char *)head->iov_base;
rqstp->rq_res.page_len = w = nfsacl_size(
(resp->mask & NFS_ACL) ? resp->acl_access : NULL,
(resp->mask & NFS_DFACL) ? resp->acl_default : NULL);
while (w > 0) {
if (!*(rqstp->rq_next_page++))
return 0;
w -= PAGE_SIZE;
}
n = nfsacl_encode(&rqstp->rq_res, base, inode,
resp->acl_access,
resp->mask & NFS_ACL, 0);
if (n > 0)
n = nfsacl_encode(&rqstp->rq_res, base + n, inode,
resp->acl_default,
resp->mask & NFS_DFACL,
NFS_ACL_DEFAULT);
if (n <= 0)
return 0;
} else
if (!xdr_ressize_check(rqstp, p))
return 0;
return 1;
}
static int nfs3svc_encode_setaclres(struct svc_rqst *rqstp, __be32 *p,
struct nfsd3_attrstat *resp)
{
p = nfs3svc_encode_post_op_attr(rqstp, p, &resp->fh);
return xdr_ressize_check(rqstp, p);
}
static int nfs3svc_release_getacl(struct svc_rqst *rqstp, __be32 *p,
struct nfsd3_getaclres *resp)
{
fh_put(&resp->fh);
posix_acl_release(resp->acl_access);
posix_acl_release(resp->acl_default);
return 1;
}
