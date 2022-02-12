static __be32
nlm_fopen(struct svc_rqst *rqstp, struct nfs_fh *f, struct file **filp)
{
__be32 nfserr;
struct svc_fh fh;
fh_init(&fh,0);
fh.fh_handle.fh_size = f->size;
memcpy((char*)&fh.fh_handle.fh_base, f->data, f->size);
fh.fh_export = NULL;
nfserr = nfsd_open(rqstp, &fh, S_IFREG, NFSD_MAY_LOCK, filp);
fh_put(&fh);
switch (nfserr) {
case nfs_ok:
return 0;
case nfserr_dropit:
return nlm_drop_reply;
case nfserr_stale:
return nlm_stale_fh;
default:
return nlm_failed;
}
}
static void
nlm_fclose(struct file *filp)
{
fput(filp);
}
void
nfsd_lockd_init(void)
{
dprintk("nfsd: initializing lockd\n");
nlmsvc_ops = &nfsd_nlm_ops;
}
void
nfsd_lockd_shutdown(void)
{
nlmsvc_ops = NULL;
}
