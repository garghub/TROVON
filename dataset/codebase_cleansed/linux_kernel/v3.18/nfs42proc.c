static int nfs42_set_rw_stateid(nfs4_stateid *dst, struct file *file,
fmode_t fmode)
{
struct nfs_open_context *open;
struct nfs_lock_context *lock;
int ret;
open = get_nfs_open_context(nfs_file_open_context(file));
lock = nfs_get_lock_context(open);
if (IS_ERR(lock)) {
put_nfs_open_context(open);
return PTR_ERR(lock);
}
ret = nfs4_set_rw_stateid(dst, open, lock, fmode);
nfs_put_lock_context(lock);
put_nfs_open_context(open);
return ret;
}
loff_t nfs42_proc_llseek(struct file *filep, loff_t offset, int whence)
{
struct inode *inode = file_inode(filep);
struct nfs42_seek_args args = {
.sa_fh = NFS_FH(inode),
.sa_offset = offset,
.sa_what = (whence == SEEK_HOLE) ?
NFS4_CONTENT_HOLE : NFS4_CONTENT_DATA,
};
struct nfs42_seek_res res;
struct rpc_message msg = {
.rpc_proc = &nfs4_procedures[NFSPROC4_CLNT_SEEK],
.rpc_argp = &args,
.rpc_resp = &res,
};
struct nfs_server *server = NFS_SERVER(inode);
int status;
if (!(server->caps & NFS_CAP_SEEK))
return -ENOTSUPP;
status = nfs42_set_rw_stateid(&args.sa_stateid, filep, FMODE_READ);
if (status)
return status;
nfs_wb_all(inode);
status = nfs4_call_sync(server->client, server, &msg,
&args.seq_args, &res.seq_res, 0);
if (status == -ENOTSUPP)
server->caps &= ~NFS_CAP_SEEK;
if (status)
return status;
return vfs_setpos(filep, res.sr_offset, inode->i_sb->s_maxbytes);
}
