blkcnt_t dirty_cnt(struct inode *inode)
{
blkcnt_t cnt = 0;
struct ccc_object *vob = cl_inode2ccc(inode);
void *results[1];
if (inode->i_mapping != NULL)
cnt += radix_tree_gang_lookup_tag(&inode->i_mapping->page_tree,
results, 0, 1,
PAGECACHE_TAG_DIRTY);
if (cnt == 0 && atomic_read(&vob->cob_mmap_cnt) > 0)
cnt = 1;
return (cnt > 0) ? 1 : 0;
}
int cl_glimpse_lock(const struct lu_env *env, struct cl_io *io,
struct inode *inode, struct cl_object *clob, int agl)
{
struct cl_lock_descr *descr = &ccc_env_info(env)->cti_descr;
struct cl_inode_info *lli = cl_i2info(inode);
const struct lu_fid *fid = lu_object_fid(&clob->co_lu);
struct ccc_io *cio = ccc_env_io(env);
struct cl_lock *lock;
int result;
ENTRY;
result = 0;
if (!(lli->lli_flags & LLIF_MDS_SIZE_LOCK)) {
CDEBUG(D_DLMTRACE, "Glimpsing inode "DFID"\n", PFID(fid));
if (lli->lli_has_smd) {
*descr = whole_file;
descr->cld_obj = clob;
descr->cld_mode = CLM_PHANTOM;
descr->cld_enq_flags = CEF_ASYNC | CEF_MUST;
if (agl)
descr->cld_enq_flags |= CEF_AGL;
cio->cui_glimpse = 1;
lock = cl_lock_request(env, io, descr, "glimpse",
current);
cio->cui_glimpse = 0;
if (lock == NULL)
RETURN(0);
if (IS_ERR(lock))
RETURN(PTR_ERR(lock));
LASSERT(agl == 0);
result = cl_wait(env, lock);
if (result == 0) {
cl_merge_lvb(env, inode);
if (cl_isize_read(inode) > 0 &&
inode->i_blocks == 0) {
inode->i_blocks = dirty_cnt(inode);
}
cl_unuse(env, lock);
}
cl_lock_release(env, lock, "glimpse", current);
} else {
CDEBUG(D_DLMTRACE, "No objects for inode\n");
cl_merge_lvb(env, inode);
}
}
RETURN(result);
}
static int cl_io_get(struct inode *inode, struct lu_env **envout,
struct cl_io **ioout, int *refcheck)
{
struct lu_env *env;
struct cl_io *io;
struct cl_inode_info *lli = cl_i2info(inode);
struct cl_object *clob = lli->lli_clob;
int result;
if (S_ISREG(cl_inode_mode(inode))) {
env = cl_env_get(refcheck);
if (!IS_ERR(env)) {
io = ccc_env_thread_io(env);
io->ci_obj = clob;
*envout = env;
*ioout = io;
result = +1;
} else
result = PTR_ERR(env);
} else
result = 0;
return result;
}
int cl_glimpse_size0(struct inode *inode, int agl)
{
struct lu_env *env = NULL;
struct cl_io *io = NULL;
int result;
int refcheck;
ENTRY;
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
RETURN(result);
}
int cl_local_size(struct inode *inode)
{
struct lu_env *env = NULL;
struct cl_io *io = NULL;
struct ccc_thread_info *cti;
struct cl_object *clob;
struct cl_lock_descr *descr;
struct cl_lock *lock;
int result;
int refcheck;
ENTRY;
if (!cl_i2info(inode)->lli_has_smd)
RETURN(0);
result = cl_io_get(inode, &env, &io, &refcheck);
if (result <= 0)
RETURN(result);
clob = io->ci_obj;
result = cl_io_init(env, io, CIT_MISC, clob);
if (result > 0)
result = io->ci_result;
else if (result == 0) {
cti = ccc_env_info(env);
descr = &cti->cti_descr;
*descr = whole_file;
descr->cld_obj = clob;
lock = cl_lock_peek(env, io, descr, "localsize", current);
if (lock != NULL) {
cl_merge_lvb(env, inode);
cl_unuse(env, lock);
cl_lock_release(env, lock, "localsize", current);
result = 0;
} else
result = -ENODATA;
}
cl_io_fini(env, io);
cl_env_put(env, &refcheck);
RETURN(result);
}
