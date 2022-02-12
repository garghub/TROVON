blkcnt_t dirty_cnt(struct inode *inode)
{
blkcnt_t cnt = 0;
struct vvp_object *vob = cl_inode2vvp(inode);
void *results[1];
if (inode->i_mapping)
cnt += radix_tree_gang_lookup_tag(&inode->i_mapping->page_tree,
results, 0, 1,
PAGECACHE_TAG_DIRTY);
if (cnt == 0 && atomic_read(&vob->vob_mmap_cnt) > 0)
cnt = 1;
return (cnt > 0) ? 1 : 0;
}
int cl_glimpse_lock(const struct lu_env *env, struct cl_io *io,
struct inode *inode, struct cl_object *clob, int agl)
{
const struct lu_fid *fid = lu_object_fid(&clob->co_lu);
struct cl_lock *lock = vvp_env_lock(env);
struct cl_lock_descr *descr = &lock->cll_descr;
int result = 0;
CDEBUG(D_DLMTRACE, "Glimpsing inode " DFID "\n", PFID(fid));
*descr = whole_file;
descr->cld_obj = clob;
descr->cld_mode = CLM_READ;
descr->cld_enq_flags = CEF_ASYNC | CEF_MUST;
if (agl)
descr->cld_enq_flags |= CEF_AGL;
result = cl_lock_request(env, io, lock);
if (result < 0)
return result;
if (!agl) {
ll_merge_attr(env, inode);
if (i_size_read(inode) > 0 && !inode->i_blocks) {
inode->i_blocks = dirty_cnt(inode);
}
}
cl_lock_release(env, lock);
return result;
}
static int cl_io_get(struct inode *inode, struct lu_env **envout,
struct cl_io **ioout, int *refcheck)
{
struct lu_env *env;
struct cl_io *io;
struct ll_inode_info *lli = ll_i2info(inode);
struct cl_object *clob = lli->lli_clob;
int result;
if (S_ISREG(inode->i_mode)) {
env = cl_env_get(refcheck);
if (!IS_ERR(env)) {
io = vvp_env_thread_io(env);
io->ci_obj = clob;
*envout = env;
*ioout = io;
result = 1;
} else {
result = PTR_ERR(env);
}
} else {
result = 0;
}
return result;
}
int cl_glimpse_size0(struct inode *inode, int agl)
{
struct lu_env *env = NULL;
struct cl_io *io = NULL;
int result;
int refcheck;
result = cl_io_get(inode, &env, &io, &refcheck);
if (result > 0) {
again:
io->ci_verify_layout = 1;
result = cl_io_init(env, io, CIT_MISC, io->ci_obj);
if (result > 0)
result = io->ci_result;
else if (result == 0)
result = cl_glimpse_lock(env, io, inode, io->ci_obj,
agl);
OBD_FAIL_TIMEOUT(OBD_FAIL_GLIMPSE_DELAY, 2);
cl_io_fini(env, io);
if (unlikely(io->ci_need_restart))
goto again;
cl_env_put(env, &refcheck);
}
return result;
}
