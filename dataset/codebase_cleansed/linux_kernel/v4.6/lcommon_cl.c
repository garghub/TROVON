void *ccc_key_init(const struct lu_context *ctx, struct lu_context_key *key)
{
struct ccc_thread_info *info;
info = kmem_cache_zalloc(ccc_thread_kmem, GFP_NOFS);
if (!info)
info = ERR_PTR(-ENOMEM);
return info;
}
void ccc_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct ccc_thread_info *info = data;
kmem_cache_free(ccc_thread_kmem, info);
}
void *ccc_session_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct ccc_session *session;
session = kmem_cache_zalloc(ccc_session_kmem, GFP_NOFS);
if (!session)
session = ERR_PTR(-ENOMEM);
return session;
}
void ccc_session_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct ccc_session *session = data;
kmem_cache_free(ccc_session_kmem, session);
}
int ccc_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
struct ccc_device *vdv;
int rc;
vdv = lu2ccc_dev(d);
vdv->cdv_next = lu2cl_dev(next);
LASSERT(d->ld_site && next->ld_type);
next->ld_site = d->ld_site;
rc = next->ld_type->ldt_ops->ldto_device_init(
env, next, next->ld_type->ldt_name, NULL);
if (rc == 0) {
lu_device_get(next);
lu_ref_add(&next->ld_reference, "lu-stack", &lu_site_init);
}
return rc;
}
struct lu_device *ccc_device_fini(const struct lu_env *env,
struct lu_device *d)
{
return cl2lu_dev(lu2ccc_dev(d)->cdv_next);
}
struct lu_device *ccc_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg,
const struct lu_device_operations *luops,
const struct cl_device_operations *clops)
{
struct ccc_device *vdv;
struct lu_device *lud;
struct cl_site *site;
int rc;
vdv = kzalloc(sizeof(*vdv), GFP_NOFS);
if (!vdv)
return ERR_PTR(-ENOMEM);
lud = &vdv->cdv_cl.cd_lu_dev;
cl_device_init(&vdv->cdv_cl, t);
ccc2lu_dev(vdv)->ld_ops = luops;
vdv->cdv_cl.cd_ops = clops;
site = kzalloc(sizeof(*site), GFP_NOFS);
if (site) {
rc = cl_site_init(site, &vdv->cdv_cl);
if (rc == 0)
rc = lu_site_init_finish(&site->cs_lu);
else {
LASSERT(!lud->ld_site);
CERROR("Cannot init lu_site, rc %d.\n", rc);
kfree(site);
}
} else
rc = -ENOMEM;
if (rc != 0) {
ccc_device_free(env, lud);
lud = ERR_PTR(rc);
}
return lud;
}
struct lu_device *ccc_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct ccc_device *vdv = lu2ccc_dev(d);
struct cl_site *site = lu2cl_site(d->ld_site);
struct lu_device *next = cl2lu_dev(vdv->cdv_next);
if (d->ld_site) {
cl_site_fini(site);
kfree(site);
}
cl_device_fini(lu2cl_dev(d));
kfree(vdv);
return next;
}
int ccc_req_init(const struct lu_env *env, struct cl_device *dev,
struct cl_req *req)
{
struct ccc_req *vrq;
int result;
vrq = kmem_cache_zalloc(ccc_req_kmem, GFP_NOFS);
if (vrq) {
cl_req_slice_add(req, &vrq->crq_cl, dev, &ccc_req_ops);
result = 0;
} else
result = -ENOMEM;
return result;
}
int ccc_global_init(struct lu_device_type *device_type)
{
int result;
result = lu_kmem_init(ccc_caches);
if (result)
return result;
result = lu_device_type_init(device_type);
if (result)
goto out_kmem;
ccc_inode_fini_env = cl_env_alloc(&dummy_refcheck,
LCT_REMEMBER|LCT_NOREF);
if (IS_ERR(ccc_inode_fini_env)) {
result = PTR_ERR(ccc_inode_fini_env);
goto out_device;
}
ccc_inode_fini_env->le_ctx.lc_cookie = 0x4;
return 0;
out_device:
lu_device_type_fini(device_type);
out_kmem:
lu_kmem_fini(ccc_caches);
return result;
}
void ccc_global_fini(struct lu_device_type *device_type)
{
if (ccc_inode_fini_env) {
cl_env_put(ccc_inode_fini_env, &dummy_refcheck);
ccc_inode_fini_env = NULL;
}
lu_device_type_fini(device_type);
lu_kmem_fini(ccc_caches);
}
struct lu_object *ccc_object_alloc(const struct lu_env *env,
const struct lu_object_header *unused,
struct lu_device *dev,
const struct cl_object_operations *clops,
const struct lu_object_operations *luops)
{
struct ccc_object *vob;
struct lu_object *obj;
vob = kmem_cache_zalloc(ccc_object_kmem, GFP_NOFS);
if (vob) {
struct cl_object_header *hdr;
obj = ccc2lu(vob);
hdr = &vob->cob_header;
cl_object_header_init(hdr);
lu_object_init(obj, &hdr->coh_lu, dev);
lu_object_add_top(&hdr->coh_lu, obj);
vob->cob_cl.co_ops = clops;
obj->lo_ops = luops;
} else
obj = NULL;
return obj;
}
int ccc_object_init0(const struct lu_env *env,
struct ccc_object *vob,
const struct cl_object_conf *conf)
{
vob->cob_inode = conf->coc_inode;
vob->cob_transient_pages = 0;
cl_object_page_init(&vob->cob_cl, sizeof(struct ccc_page));
return 0;
}
int ccc_object_init(const struct lu_env *env, struct lu_object *obj,
const struct lu_object_conf *conf)
{
struct ccc_device *dev = lu2ccc_dev(obj->lo_dev);
struct ccc_object *vob = lu2ccc(obj);
struct lu_object *below;
struct lu_device *under;
int result;
under = &dev->cdv_next->cd_lu_dev;
below = under->ld_ops->ldo_object_alloc(env, obj->lo_header, under);
if (below) {
const struct cl_object_conf *cconf;
cconf = lu2cl_conf(conf);
INIT_LIST_HEAD(&vob->cob_pending_list);
lu_object_add(obj, below);
result = ccc_object_init0(env, vob, cconf);
} else
result = -ENOMEM;
return result;
}
void ccc_object_free(const struct lu_env *env, struct lu_object *obj)
{
struct ccc_object *vob = lu2ccc(obj);
lu_object_fini(obj);
lu_object_header_fini(obj->lo_header);
kmem_cache_free(ccc_object_kmem, vob);
}
int ccc_lock_init(const struct lu_env *env,
struct cl_object *obj, struct cl_lock *lock,
const struct cl_io *unused,
const struct cl_lock_operations *lkops)
{
struct ccc_lock *clk;
int result;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
clk = kmem_cache_zalloc(ccc_lock_kmem, GFP_NOFS);
if (clk) {
cl_lock_slice_add(lock, &clk->clk_cl, obj, lkops);
result = 0;
} else
result = -ENOMEM;
return result;
}
int ccc_object_glimpse(const struct lu_env *env,
const struct cl_object *obj, struct ost_lvb *lvb)
{
struct inode *inode = ccc_object_inode(obj);
lvb->lvb_mtime = cl_inode_mtime(inode);
lvb->lvb_atime = cl_inode_atime(inode);
lvb->lvb_ctime = cl_inode_ctime(inode);
if (lvb->lvb_size > 0 && lvb->lvb_blocks == 0)
lvb->lvb_blocks = dirty_cnt(inode);
return 0;
}
static void ccc_object_size_lock(struct cl_object *obj)
{
struct inode *inode = ccc_object_inode(obj);
ll_inode_size_lock(inode);
cl_object_attr_lock(obj);
}
static void ccc_object_size_unlock(struct cl_object *obj)
{
struct inode *inode = ccc_object_inode(obj);
cl_object_attr_unlock(obj);
ll_inode_size_unlock(inode);
}
struct page *ccc_page_vmpage(const struct lu_env *env,
const struct cl_page_slice *slice)
{
return cl2vm_page(slice);
}
int ccc_page_is_under_lock(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io)
{
struct ccc_io *cio = ccc_env_io(env);
struct cl_lock_descr *desc = &ccc_env_info(env)->cti_descr;
struct cl_page *page = slice->cpl_page;
int result;
if (io->ci_type == CIT_READ || io->ci_type == CIT_WRITE ||
io->ci_type == CIT_FAULT) {
if (cio->cui_fd->fd_flags & LL_FILE_GROUP_LOCKED)
result = -EBUSY;
else {
desc->cld_start = page->cp_index;
desc->cld_end = page->cp_index;
desc->cld_obj = page->cp_obj;
desc->cld_mode = CLM_READ;
result = cl_queue_match(&io->ci_lockset.cls_done,
desc) ? -EBUSY : 0;
}
} else
result = 0;
return result;
}
int ccc_fail(const struct lu_env *env, const struct cl_page_slice *slice)
{
LBUG();
return 0;
}
int ccc_transient_page_prep(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
return 0;
}
void ccc_lock_delete(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
CLOBINVRNT(env, slice->cls_obj, ccc_object_invariant(slice->cls_obj));
}
void ccc_lock_fini(const struct lu_env *env, struct cl_lock_slice *slice)
{
struct ccc_lock *clk = cl2ccc_lock(slice);
kmem_cache_free(ccc_lock_kmem, clk);
}
int ccc_lock_enqueue(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_io *unused, __u32 enqflags)
{
CLOBINVRNT(env, slice->cls_obj, ccc_object_invariant(slice->cls_obj));
return 0;
}
int ccc_lock_use(const struct lu_env *env, const struct cl_lock_slice *slice)
{
CLOBINVRNT(env, slice->cls_obj, ccc_object_invariant(slice->cls_obj));
return 0;
}
int ccc_lock_unuse(const struct lu_env *env, const struct cl_lock_slice *slice)
{
CLOBINVRNT(env, slice->cls_obj, ccc_object_invariant(slice->cls_obj));
return 0;
}
int ccc_lock_wait(const struct lu_env *env, const struct cl_lock_slice *slice)
{
CLOBINVRNT(env, slice->cls_obj, ccc_object_invariant(slice->cls_obj));
return 0;
}
int ccc_lock_fits_into(const struct lu_env *env,
const struct cl_lock_slice *slice,
const struct cl_lock_descr *need,
const struct cl_io *io)
{
const struct cl_lock *lock = slice->cls_lock;
const struct cl_lock_descr *descr = &lock->cll_descr;
const struct ccc_io *cio = ccc_env_io(env);
int result;
if (cio->cui_glimpse)
result = descr->cld_mode != CLM_WRITE;
else if (need->cld_mode != descr->cld_mode)
result = lock->cll_state >= CLS_ENQUEUED;
else
result = 1;
return result;
}
void ccc_lock_state(const struct lu_env *env,
const struct cl_lock_slice *slice,
enum cl_lock_state state)
{
struct cl_lock *lock = slice->cls_lock;
if (state == CLS_HELD && lock->cll_state < CLS_HELD) {
struct cl_object *obj;
struct inode *inode;
obj = slice->cls_obj;
inode = ccc_object_inode(obj);
if (lock->cll_descr.cld_start == 0 &&
lock->cll_descr.cld_end == CL_PAGE_EOF)
cl_merge_lvb(env, inode);
}
}
int ccc_io_one_lock_index(const struct lu_env *env, struct cl_io *io,
__u32 enqflags, enum cl_lock_mode mode,
pgoff_t start, pgoff_t end)
{
struct ccc_io *cio = ccc_env_io(env);
struct cl_lock_descr *descr = &cio->cui_link.cill_descr;
struct cl_object *obj = io->ci_obj;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
CDEBUG(D_VFSTRACE, "lock: %d [%lu, %lu]\n", mode, start, end);
memset(&cio->cui_link, 0, sizeof(cio->cui_link));
if (cio->cui_fd && (cio->cui_fd->fd_flags & LL_FILE_GROUP_LOCKED)) {
descr->cld_mode = CLM_GROUP;
descr->cld_gid = cio->cui_fd->fd_grouplock.cg_gid;
} else {
descr->cld_mode = mode;
}
descr->cld_obj = obj;
descr->cld_start = start;
descr->cld_end = end;
descr->cld_enq_flags = enqflags;
cl_io_lock_add(env, io, &cio->cui_link);
return 0;
}
void ccc_io_update_iov(const struct lu_env *env,
struct ccc_io *cio, struct cl_io *io)
{
size_t size = io->u.ci_rw.crw_count;
if (!cl_is_normalio(env, io) || !cio->cui_iter)
return;
iov_iter_truncate(cio->cui_iter, size);
}
int ccc_io_one_lock(const struct lu_env *env, struct cl_io *io,
__u32 enqflags, enum cl_lock_mode mode,
loff_t start, loff_t end)
{
struct cl_object *obj = io->ci_obj;
return ccc_io_one_lock_index(env, io, enqflags, mode,
cl_index(obj, start), cl_index(obj, end));
}
void ccc_io_end(const struct lu_env *env, const struct cl_io_slice *ios)
{
CLOBINVRNT(env, ios->cis_io->ci_obj,
ccc_object_invariant(ios->cis_io->ci_obj));
}
void ccc_io_advance(const struct lu_env *env,
const struct cl_io_slice *ios,
size_t nob)
{
struct ccc_io *cio = cl2ccc_io(env, ios);
struct cl_io *io = ios->cis_io;
struct cl_object *obj = ios->cis_io->ci_obj;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
if (!cl_is_normalio(env, io))
return;
iov_iter_reexpand(cio->cui_iter, cio->cui_tot_count -= nob);
}
int ccc_prep_size(const struct lu_env *env, struct cl_object *obj,
struct cl_io *io, loff_t start, size_t count, int *exceed)
{
struct cl_attr *attr = ccc_env_thread_attr(env);
struct inode *inode = ccc_object_inode(obj);
loff_t pos = start + count - 1;
loff_t kms;
int result;
ccc_object_size_lock(obj);
result = cl_object_attr_get(env, obj, attr);
if (result == 0) {
kms = attr->cat_kms;
if (pos > kms) {
ccc_object_size_unlock(obj);
result = cl_glimpse_lock(env, io, inode, obj, 0);
if (result == 0 && exceed) {
loff_t size = cl_isize_read(inode);
loff_t cur_index = start >> PAGE_SHIFT;
loff_t size_index = (size - 1) >>
PAGE_SHIFT;
if ((size == 0 && cur_index != 0) ||
size_index < cur_index)
*exceed = 1;
}
return result;
}
if (cl_isize_read(inode) < kms) {
cl_isize_write_nolock(inode, kms);
CDEBUG(D_VFSTRACE,
DFID" updating i_size %llu\n",
PFID(lu_object_fid(&obj->co_lu)),
(__u64)cl_isize_read(inode));
}
}
ccc_object_size_unlock(obj);
return result;
}
void ccc_req_completion(const struct lu_env *env,
const struct cl_req_slice *slice, int ioret)
{
struct ccc_req *vrq;
if (ioret > 0)
cl_stats_tally(slice->crs_dev, slice->crs_req->crq_type, ioret);
vrq = cl2ccc_req(slice);
kmem_cache_free(ccc_req_kmem, vrq);
}
void ccc_req_attr_set(const struct lu_env *env,
const struct cl_req_slice *slice,
const struct cl_object *obj,
struct cl_req_attr *attr, u64 flags)
{
struct inode *inode;
struct obdo *oa;
u32 valid_flags;
oa = attr->cra_oa;
inode = ccc_object_inode(obj);
valid_flags = OBD_MD_FLTYPE;
if (slice->crs_req->crq_type == CRT_WRITE) {
if (flags & OBD_MD_FLEPOCH) {
oa->o_valid |= OBD_MD_FLEPOCH;
oa->o_ioepoch = cl_i2info(inode)->lli_ioepoch;
valid_flags |= OBD_MD_FLMTIME | OBD_MD_FLCTIME |
OBD_MD_FLUID | OBD_MD_FLGID;
}
}
obdo_from_inode(oa, inode, valid_flags & flags);
obdo_set_parent_fid(oa, &cl_i2info(inode)->lli_fid);
memcpy(attr->cra_jobid, cl_i2info(inode)->lli_jobid,
JOBSTATS_JOBID_SIZE);
}
int cl_setattr_ost(struct inode *inode, const struct iattr *attr)
{
struct lu_env *env;
struct cl_io *io;
int result;
int refcheck;
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
io = ccc_env_thread_io(env);
io->ci_obj = cl_i2info(inode)->lli_clob;
io->u.ci_setattr.sa_attr.lvb_atime = LTIME_S(attr->ia_atime);
io->u.ci_setattr.sa_attr.lvb_mtime = LTIME_S(attr->ia_mtime);
io->u.ci_setattr.sa_attr.lvb_ctime = LTIME_S(attr->ia_ctime);
io->u.ci_setattr.sa_attr.lvb_size = attr->ia_size;
io->u.ci_setattr.sa_valid = attr->ia_valid;
again:
if (cl_io_init(env, io, CIT_SETATTR, io->ci_obj) == 0) {
struct ccc_io *cio = ccc_env_io(env);
if (attr->ia_valid & ATTR_FILE)
cio->cui_fd = cl_iattr2fd(inode, attr);
result = cl_io_loop(env, io);
} else {
result = io->ci_result;
}
cl_io_fini(env, io);
if (unlikely(io->ci_need_restart))
goto again;
if (result == -ENODATA && io->ci_restore_needed &&
io->ci_result != -ENODATA)
result = 0;
cl_env_put(env, &refcheck);
return result;
}
struct lu_device *ccc2lu_dev(struct ccc_device *vdv)
{
return &vdv->cdv_cl.cd_lu_dev;
}
struct ccc_device *lu2ccc_dev(const struct lu_device *d)
{
return container_of0(d, struct ccc_device, cdv_cl.cd_lu_dev);
}
struct ccc_device *cl2ccc_dev(const struct cl_device *d)
{
return container_of0(d, struct ccc_device, cdv_cl);
}
struct lu_object *ccc2lu(struct ccc_object *vob)
{
return &vob->cob_cl.co_lu;
}
struct ccc_object *lu2ccc(const struct lu_object *obj)
{
return container_of0(obj, struct ccc_object, cob_cl.co_lu);
}
struct ccc_object *cl2ccc(const struct cl_object *obj)
{
return container_of0(obj, struct ccc_object, cob_cl);
}
struct ccc_lock *cl2ccc_lock(const struct cl_lock_slice *slice)
{
return container_of(slice, struct ccc_lock, clk_cl);
}
struct ccc_io *cl2ccc_io(const struct lu_env *env,
const struct cl_io_slice *slice)
{
struct ccc_io *cio;
cio = container_of(slice, struct ccc_io, cui_cl);
LASSERT(cio == ccc_env_io(env));
return cio;
}
struct ccc_req *cl2ccc_req(const struct cl_req_slice *slice)
{
return container_of0(slice, struct ccc_req, crq_cl);
}
struct page *cl2vm_page(const struct cl_page_slice *slice)
{
return cl2ccc_page(slice)->cpg_page;
}
int ccc_object_invariant(const struct cl_object *obj)
{
struct inode *inode = ccc_object_inode(obj);
struct cl_inode_info *lli = cl_i2info(inode);
return (S_ISREG(cl_inode_mode(inode)) ||
cl_inode_mode(inode) == 0) && lli->lli_clob == obj;
}
struct inode *ccc_object_inode(const struct cl_object *obj)
{
return cl2ccc(obj)->cob_inode;
}
int cl_file_inode_init(struct inode *inode, struct lustre_md *md)
{
struct lu_env *env;
struct cl_inode_info *lli;
struct cl_object *clob;
struct lu_site *site;
struct lu_fid *fid;
struct cl_object_conf conf = {
.coc_inode = inode,
.u = {
.coc_md = md
}
};
int result = 0;
int refcheck;
LASSERT(md->body->valid & OBD_MD_FLID);
LASSERT(S_ISREG(cl_inode_mode(inode)));
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
site = cl_i2sbi(inode)->ll_site;
lli = cl_i2info(inode);
fid = &lli->lli_fid;
LASSERT(fid_is_sane(fid));
if (!lli->lli_clob) {
LASSERT(inode->i_state & I_NEW);
conf.coc_lu.loc_flags = LOC_F_NEW;
clob = cl_object_find(env, lu2cl_dev(site->ls_top_dev),
fid, &conf);
if (!IS_ERR(clob)) {
lli->lli_clob = clob;
lli->lli_has_smd = lsm_has_objects(md->lsm);
lu_object_ref_add(&clob->co_lu, "inode", inode);
} else
result = PTR_ERR(clob);
} else {
result = cl_conf_set(env, lli->lli_clob, &conf);
}
cl_env_put(env, &refcheck);
if (result != 0)
CERROR("Failure to initialize cl object "DFID": %d\n",
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
struct cl_inode_info *lli = cl_i2info(inode);
struct cl_object *clob = lli->lli_clob;
int refcheck;
int emergency;
if (clob) {
void *cookie;
cookie = cl_env_reenter();
env = cl_env_get(&refcheck);
emergency = IS_ERR(env);
if (emergency) {
mutex_lock(&ccc_inode_fini_guard);
LASSERT(ccc_inode_fini_env);
cl_env_implant(ccc_inode_fini_env, &refcheck);
env = ccc_inode_fini_env;
}
cl_object_kill(env, clob);
lu_object_ref_del(&clob->co_lu, "inode", inode);
cl_object_put_last(env, clob);
lli->lli_clob = NULL;
if (emergency) {
cl_env_unplant(ccc_inode_fini_env, &refcheck);
mutex_unlock(&ccc_inode_fini_guard);
} else
cl_env_put(env, &refcheck);
cl_env_reexit(cookie);
}
}
__u16 ll_dirent_type_get(struct lu_dirent *ent)
{
__u16 type = 0;
struct luda_type *lt;
int len = 0;
if (le32_to_cpu(ent->lde_attrs) & LUDA_TYPE) {
const unsigned align = sizeof(struct luda_type) - 1;
len = le16_to_cpu(ent->lde_namelen);
len = (len + align) & ~align;
lt = (void *)ent->lde_name + len;
type = IFTODT(le16_to_cpu(lt->lt_type));
}
return type;
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
struct lov_stripe_md *ccc_inode_lsm_get(struct inode *inode)
{
return lov_lsm_get(cl_i2info(inode)->lli_clob);
}
inline void ccc_inode_lsm_put(struct inode *inode, struct lov_stripe_md *lsm)
{
lov_lsm_put(cl_i2info(inode)->lli_clob, lsm);
}
