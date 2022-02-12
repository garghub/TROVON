int cl_setattr_ost(struct cl_object *obj, const struct iattr *attr,
unsigned int attr_flags)
{
struct lu_env *env;
struct cl_io *io;
int result;
u16 refcheck;
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
io = vvp_env_thread_io(env);
io->ci_obj = obj;
io->ci_verify_layout = 1;
io->u.ci_setattr.sa_attr.lvb_atime = LTIME_S(attr->ia_atime);
io->u.ci_setattr.sa_attr.lvb_mtime = LTIME_S(attr->ia_mtime);
io->u.ci_setattr.sa_attr.lvb_ctime = LTIME_S(attr->ia_ctime);
io->u.ci_setattr.sa_attr.lvb_size = attr->ia_size;
io->u.ci_setattr.sa_attr_flags = attr_flags;
io->u.ci_setattr.sa_valid = attr->ia_valid;
io->u.ci_setattr.sa_parent_fid = lu_object_fid(&obj->co_lu);
again:
if (cl_io_init(env, io, CIT_SETATTR, io->ci_obj) == 0) {
struct vvp_io *vio = vvp_env_io(env);
if (attr->ia_valid & ATTR_FILE)
vio->vui_fd = LUSTRE_FPRIVATE(attr->ia_file);
result = cl_io_loop(env, io);
} else {
result = io->ci_result;
}
cl_io_fini(env, io);
if (unlikely(io->ci_need_restart))
goto again;
cl_env_put(env, &refcheck);
return result;
}
int cl_file_inode_init(struct inode *inode, struct lustre_md *md)
{
struct lu_env *env;
struct ll_inode_info *lli;
struct cl_object *clob;
struct lu_site *site;
struct lu_fid *fid;
struct cl_object_conf conf = {
.coc_inode = inode,
.u = {
.coc_layout = md->layout,
}
};
int result = 0;
u16 refcheck;
LASSERT(md->body->mbo_valid & OBD_MD_FLID);
LASSERT(S_ISREG(inode->i_mode));
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
site = ll_i2sbi(inode)->ll_site;
lli = ll_i2info(inode);
fid = &lli->lli_fid;
LASSERT(fid_is_sane(fid));
if (!lli->lli_clob) {
LASSERT(inode->i_state & I_NEW);
conf.coc_lu.loc_flags = LOC_F_NEW;
clob = cl_object_find(env, lu2cl_dev(site->ls_top_dev),
fid, &conf);
if (!IS_ERR(clob)) {
lli->lli_clob = clob;
lu_object_ref_add(&clob->co_lu, "inode", inode);
} else {
result = PTR_ERR(clob);
}
} else {
result = cl_conf_set(env, lli->lli_clob, &conf);
}
cl_env_put(env, &refcheck);
if (result != 0)
CERROR("Failure to initialize cl object " DFID ": %d\n",
PFID(fid), result);
return result;
}
static void cl_object_put_last(struct lu_env *env, struct cl_object *obj)
{
struct lu_object_header *header = obj->co_lu.lo_header;
wait_queue_t waiter;
if (unlikely(atomic_read(&header->loh_ref) != 1)) {
struct lu_site *site = obj->co_lu.lo_dev->ld_site;
struct lu_site_bkt_data *bkt;
bkt = lu_site_bkt_from_fid(site, &header->loh_fid);
init_waitqueue_entry(&waiter, current);
add_wait_queue(&bkt->lsb_marche_funebre, &waiter);
while (1) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (atomic_read(&header->loh_ref) == 1)
break;
schedule();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&bkt->lsb_marche_funebre, &waiter);
}
cl_object_put(env, obj);
}
void cl_inode_fini(struct inode *inode)
{
struct lu_env *env;
struct ll_inode_info *lli = ll_i2info(inode);
struct cl_object *clob = lli->lli_clob;
u16 refcheck;
int emergency;
if (clob) {
env = cl_env_get(&refcheck);
emergency = IS_ERR(env);
if (emergency) {
mutex_lock(&cl_inode_fini_guard);
LASSERT(cl_inode_fini_env);
env = cl_inode_fini_env;
}
cl_object_kill(env, clob);
lu_object_ref_del(&clob->co_lu, "inode", inode);
cl_object_put_last(env, clob);
lli->lli_clob = NULL;
if (emergency)
mutex_unlock(&cl_inode_fini_guard);
else
cl_env_put(env, &refcheck);
}
}
__u64 cl_fid_build_ino(const struct lu_fid *fid, int api32)
{
if (BITS_PER_LONG == 32 || api32)
return fid_flatten32(fid);
else
return fid_flatten(fid);
}
__u32 cl_fid_build_gen(const struct lu_fid *fid)
{
__u32 gen;
if (fid_is_igif(fid)) {
gen = lu_igif_gen(fid);
return gen;
}
gen = fid_flatten(fid) >> 32;
return gen;
}
