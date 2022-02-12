static inline struct lov_device *lov_object_dev(struct lov_object *obj)
{
return lu2lov_dev(obj->lo_cl.co_lu.lo_dev);
}
static void lov_lsm_put(struct lov_stripe_md *lsm)
{
if (lsm)
lov_free_memmd(&lsm);
}
static void lov_install_empty(const struct lu_env *env,
struct lov_object *lov,
union lov_layout_state *state)
{
}
static int lov_init_empty(const struct lu_env *env, struct lov_device *dev,
struct lov_object *lov, struct lov_stripe_md *lsm,
const struct cl_object_conf *conf,
union lov_layout_state *state)
{
return 0;
}
static void lov_install_raid0(const struct lu_env *env,
struct lov_object *lov,
union lov_layout_state *state)
{
}
static struct cl_object *lov_sub_find(const struct lu_env *env,
struct cl_device *dev,
const struct lu_fid *fid,
const struct cl_object_conf *conf)
{
struct lu_object *o;
o = lu_object_find_at(env, cl2lu_dev(dev), fid, &conf->coc_lu);
LASSERT(ergo(!IS_ERR(o), o->lo_dev->ld_type == &lovsub_device_type));
return lu2cl(o);
}
static int lov_init_sub(const struct lu_env *env, struct lov_object *lov,
struct cl_object *stripe, struct lov_layout_raid0 *r0,
int idx)
{
struct cl_object_header *hdr;
struct cl_object_header *subhdr;
struct cl_object_header *parent;
struct lov_oinfo *oinfo;
int result;
if (OBD_FAIL_CHECK(OBD_FAIL_LOV_INIT)) {
cl_object_kill(env, stripe);
cl_object_put(env, stripe);
return -EIO;
}
hdr = cl_object_header(lov2cl(lov));
subhdr = cl_object_header(stripe);
oinfo = lov->lo_lsm->lsm_oinfo[idx];
CDEBUG(D_INODE, DFID "@%p[%d] -> " DFID "@%p: ostid: " DOSTID " idx: %d gen: %d\n",
PFID(&subhdr->coh_lu.loh_fid), subhdr, idx,
PFID(&hdr->coh_lu.loh_fid), hdr, POSTID(&oinfo->loi_oi),
oinfo->loi_ost_idx, oinfo->loi_ost_gen);
spin_lock(&subhdr->coh_attr_guard);
parent = subhdr->coh_parent;
if (!parent) {
subhdr->coh_parent = hdr;
spin_unlock(&subhdr->coh_attr_guard);
subhdr->coh_nesting = hdr->coh_nesting + 1;
lu_object_ref_add(&stripe->co_lu, "lov-parent", lov);
r0->lo_sub[idx] = cl2lovsub(stripe);
r0->lo_sub[idx]->lso_super = lov;
r0->lo_sub[idx]->lso_index = idx;
result = 0;
} else {
struct lu_object *old_obj;
struct lov_object *old_lov;
unsigned int mask = D_INODE;
spin_unlock(&subhdr->coh_attr_guard);
old_obj = lu_object_locate(&parent->coh_lu, &lov_device_type);
LASSERT(old_obj);
old_lov = cl2lov(lu2cl(old_obj));
if (old_lov->lo_layout_invalid) {
lu_object_unhash(env, &stripe->co_lu);
result = -EAGAIN;
} else {
mask = D_ERROR;
result = -EIO;
}
LU_OBJECT_DEBUG(mask, env, &stripe->co_lu,
"stripe %d is already owned.", idx);
LU_OBJECT_DEBUG(mask, env, old_obj, "owned.");
LU_OBJECT_HEADER(mask, env, lov2lu(lov), "try to own.\n");
cl_object_put(env, stripe);
}
return result;
}
static int lov_page_slice_fixup(struct lov_object *lov,
struct cl_object *stripe)
{
struct cl_object_header *hdr = cl_object_header(&lov->lo_cl);
struct cl_object *o;
if (!stripe)
return hdr->coh_page_bufsize - lov->lo_cl.co_slice_off -
cfs_size_round(sizeof(struct lov_page));
cl_object_for_each(o, stripe)
o->co_slice_off += hdr->coh_page_bufsize;
return cl_object_header(stripe)->coh_page_bufsize;
}
static int lov_init_raid0(const struct lu_env *env, struct lov_device *dev,
struct lov_object *lov, struct lov_stripe_md *lsm,
const struct cl_object_conf *conf,
union lov_layout_state *state)
{
int result;
int i;
struct cl_object *stripe;
struct lov_thread_info *lti = lov_env_info(env);
struct cl_object_conf *subconf = &lti->lti_stripe_conf;
struct lu_fid *ofid = &lti->lti_fid;
struct lov_layout_raid0 *r0 = &state->raid0;
if (lsm->lsm_magic != LOV_MAGIC_V1 && lsm->lsm_magic != LOV_MAGIC_V3) {
dump_lsm(D_ERROR, lsm);
LASSERTF(0, "magic mismatch, expected %d/%d, actual %d.\n",
LOV_MAGIC_V1, LOV_MAGIC_V3, lsm->lsm_magic);
}
LASSERT(!lov->lo_lsm);
lov->lo_lsm = lsm_addref(lsm);
lov->lo_layout_invalid = true;
r0->lo_nr = lsm->lsm_stripe_count;
LASSERT(r0->lo_nr <= lov_targets_nr(dev));
r0->lo_sub = libcfs_kvzalloc(r0->lo_nr * sizeof(r0->lo_sub[0]),
GFP_NOFS);
if (r0->lo_sub) {
int psz = 0;
result = 0;
subconf->coc_inode = conf->coc_inode;
spin_lock_init(&r0->lo_sub_lock);
for (i = 0; i < r0->lo_nr && result == 0; ++i) {
struct cl_device *subdev;
struct lov_oinfo *oinfo = lsm->lsm_oinfo[i];
int ost_idx = oinfo->loi_ost_idx;
if (lov_oinfo_is_dummy(oinfo))
continue;
result = ostid_to_fid(ofid, &oinfo->loi_oi,
oinfo->loi_ost_idx);
if (result != 0)
goto out;
if (!dev->ld_target[ost_idx]) {
CERROR("%s: OST %04x is not initialized\n",
lov2obd(dev->ld_lov)->obd_name, ost_idx);
result = -EIO;
goto out;
}
subdev = lovsub2cl_dev(dev->ld_target[ost_idx]);
subconf->u.coc_oinfo = oinfo;
LASSERTF(subdev, "not init ost %d\n", ost_idx);
stripe = lov_sub_find(env, subdev, ofid, subconf);
if (!IS_ERR(stripe)) {
result = lov_init_sub(env, lov, stripe, r0, i);
if (result == -EAGAIN) {
--i;
result = 0;
continue;
}
} else {
result = PTR_ERR(stripe);
}
if (result == 0) {
int sz = lov_page_slice_fixup(lov, stripe);
LASSERT(ergo(psz > 0, psz == sz));
psz = sz;
}
}
if (result == 0)
cl_object_header(&lov->lo_cl)->coh_page_bufsize += psz;
} else {
result = -ENOMEM;
}
out:
return result;
}
static int lov_init_released(const struct lu_env *env, struct lov_device *dev,
struct lov_object *lov, struct lov_stripe_md *lsm,
const struct cl_object_conf *conf,
union lov_layout_state *state)
{
LASSERT(lsm);
LASSERT(lsm_is_released(lsm));
LASSERT(!lov->lo_lsm);
lov->lo_lsm = lsm_addref(lsm);
return 0;
}
static struct cl_object *lov_find_subobj(const struct lu_env *env,
struct lov_object *lov,
struct lov_stripe_md *lsm,
int stripe_idx)
{
struct lov_device *dev = lu2lov_dev(lov2lu(lov)->lo_dev);
struct lov_oinfo *oinfo = lsm->lsm_oinfo[stripe_idx];
struct lov_thread_info *lti = lov_env_info(env);
struct lu_fid *ofid = &lti->lti_fid;
struct cl_device *subdev;
struct cl_object *result;
int ost_idx;
int rc;
if (lov->lo_type != LLT_RAID0) {
result = NULL;
goto out;
}
ost_idx = oinfo->loi_ost_idx;
rc = ostid_to_fid(ofid, &oinfo->loi_oi, ost_idx);
if (rc) {
result = NULL;
goto out;
}
subdev = lovsub2cl_dev(dev->ld_target[ost_idx]);
result = lov_sub_find(env, subdev, ofid, NULL);
out:
if (!result)
result = ERR_PTR(-EINVAL);
return result;
}
static int lov_delete_empty(const struct lu_env *env, struct lov_object *lov,
union lov_layout_state *state)
{
LASSERT(lov->lo_type == LLT_EMPTY || lov->lo_type == LLT_RELEASED);
lov_layout_wait(env, lov);
return 0;
}
static void lov_subobject_kill(const struct lu_env *env, struct lov_object *lov,
struct lovsub_object *los, int idx)
{
struct cl_object *sub;
struct lov_layout_raid0 *r0;
struct lu_site *site;
struct lu_site_bkt_data *bkt;
wait_queue_entry_t *waiter;
r0 = &lov->u.raid0;
LASSERT(r0->lo_sub[idx] == los);
sub = lovsub2cl(los);
site = sub->co_lu.lo_dev->ld_site;
bkt = lu_site_bkt_from_fid(site, &sub->co_lu.lo_header->loh_fid);
cl_object_kill(env, sub);
lu_object_ref_del(&sub->co_lu, "lov-parent", lov);
cl_object_put(env, sub);
if (r0->lo_sub[idx] == los) {
waiter = &lov_env_info(env)->lti_waiter;
init_waitqueue_entry(waiter, current);
add_wait_queue(&bkt->lsb_marche_funebre, waiter);
set_current_state(TASK_UNINTERRUPTIBLE);
while (1) {
set_current_state(TASK_UNINTERRUPTIBLE);
spin_lock(&r0->lo_sub_lock);
if (r0->lo_sub[idx] == los) {
spin_unlock(&r0->lo_sub_lock);
schedule();
} else {
spin_unlock(&r0->lo_sub_lock);
set_current_state(TASK_RUNNING);
break;
}
}
remove_wait_queue(&bkt->lsb_marche_funebre, waiter);
}
LASSERT(!r0->lo_sub[idx]);
}
static int lov_delete_raid0(const struct lu_env *env, struct lov_object *lov,
union lov_layout_state *state)
{
struct lov_layout_raid0 *r0 = &state->raid0;
struct lov_stripe_md *lsm = lov->lo_lsm;
int i;
dump_lsm(D_INODE, lsm);
lov_layout_wait(env, lov);
if (r0->lo_sub) {
for (i = 0; i < r0->lo_nr; ++i) {
struct lovsub_object *los = r0->lo_sub[i];
if (los) {
cl_object_prune(env, &los->lso_cl);
lov_subobject_kill(env, lov, los, i);
}
}
}
return 0;
}
static void lov_fini_empty(const struct lu_env *env, struct lov_object *lov,
union lov_layout_state *state)
{
LASSERT(lov->lo_type == LLT_EMPTY || lov->lo_type == LLT_RELEASED);
}
static void lov_fini_raid0(const struct lu_env *env, struct lov_object *lov,
union lov_layout_state *state)
{
struct lov_layout_raid0 *r0 = &state->raid0;
if (r0->lo_sub) {
kvfree(r0->lo_sub);
r0->lo_sub = NULL;
}
dump_lsm(D_INODE, lov->lo_lsm);
lov_free_memmd(&lov->lo_lsm);
}
static void lov_fini_released(const struct lu_env *env, struct lov_object *lov,
union lov_layout_state *state)
{
dump_lsm(D_INODE, lov->lo_lsm);
lov_free_memmd(&lov->lo_lsm);
}
static int lov_print_empty(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *o)
{
(*p)(env, cookie, "empty %d\n", lu2lov(o)->lo_layout_invalid);
return 0;
}
static int lov_print_raid0(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *o)
{
struct lov_object *lov = lu2lov(o);
struct lov_layout_raid0 *r0 = lov_r0(lov);
struct lov_stripe_md *lsm = lov->lo_lsm;
int i;
(*p)(env, cookie, "stripes: %d, %s, lsm{%p 0x%08X %d %u %u}:\n",
r0->lo_nr, lov->lo_layout_invalid ? "invalid" : "valid", lsm,
lsm->lsm_magic, atomic_read(&lsm->lsm_refc),
lsm->lsm_stripe_count, lsm->lsm_layout_gen);
for (i = 0; i < r0->lo_nr; ++i) {
struct lu_object *sub;
if (r0->lo_sub[i]) {
sub = lovsub2lu(r0->lo_sub[i]);
lu_object_print(env, cookie, p, sub);
} else {
(*p)(env, cookie, "sub %d absent\n", i);
}
}
return 0;
}
static int lov_print_released(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *o)
{
struct lov_object *lov = lu2lov(o);
struct lov_stripe_md *lsm = lov->lo_lsm;
(*p)(env, cookie,
"released: %s, lsm{%p 0x%08X %d %u %u}:\n",
lov->lo_layout_invalid ? "invalid" : "valid", lsm,
lsm->lsm_magic, atomic_read(&lsm->lsm_refc),
lsm->lsm_stripe_count, lsm->lsm_layout_gen);
return 0;
}
static int lov_attr_get_empty(const struct lu_env *env, struct cl_object *obj,
struct cl_attr *attr)
{
attr->cat_blocks = 0;
return 0;
}
static int lov_attr_get_raid0(const struct lu_env *env, struct cl_object *obj,
struct cl_attr *attr)
{
struct lov_object *lov = cl2lov(obj);
struct lov_layout_raid0 *r0 = lov_r0(lov);
struct cl_attr *lov_attr = &r0->lo_attr;
int result = 0;
if (!r0->lo_attr_valid) {
struct lov_stripe_md *lsm = lov->lo_lsm;
struct ost_lvb *lvb = &lov_env_info(env)->lti_lvb;
__u64 kms = 0;
memset(lvb, 0, sizeof(*lvb));
lvb->lvb_atime = LLONG_MIN;
lvb->lvb_ctime = LLONG_MIN;
lvb->lvb_mtime = LLONG_MIN;
lov_stripe_lock(lsm);
result = lov_merge_lvb_kms(lsm, lvb, &kms);
lov_stripe_unlock(lsm);
if (result == 0) {
cl_lvb2attr(lov_attr, lvb);
lov_attr->cat_kms = kms;
r0->lo_attr_valid = 1;
}
}
if (result == 0) {
attr->cat_blocks = lov_attr->cat_blocks;
attr->cat_size = lov_attr->cat_size;
attr->cat_kms = lov_attr->cat_kms;
if (attr->cat_atime < lov_attr->cat_atime)
attr->cat_atime = lov_attr->cat_atime;
if (attr->cat_ctime < lov_attr->cat_ctime)
attr->cat_ctime = lov_attr->cat_ctime;
if (attr->cat_mtime < lov_attr->cat_mtime)
attr->cat_mtime = lov_attr->cat_mtime;
}
return result;
}
static enum lov_layout_type lov_type(struct lov_stripe_md *lsm)
{
if (!lsm)
return LLT_EMPTY;
if (lsm_is_released(lsm))
return LLT_RELEASED;
return LLT_RAID0;
}
static inline void lov_conf_freeze(struct lov_object *lov)
{
CDEBUG(D_INODE, "To take share lov(%p) owner %p/%p\n",
lov, lov->lo_owner, current);
if (lov->lo_owner != current)
down_read(&lov->lo_type_guard);
}
static inline void lov_conf_thaw(struct lov_object *lov)
{
CDEBUG(D_INODE, "To release share lov(%p) owner %p/%p\n",
lov, lov->lo_owner, current);
if (lov->lo_owner != current)
up_read(&lov->lo_type_guard);
}
static void lov_conf_lock(struct lov_object *lov)
{
LASSERT(lov->lo_owner != current);
down_write(&lov->lo_type_guard);
LASSERT(!lov->lo_owner);
lov->lo_owner = current;
CDEBUG(D_INODE, "Took exclusive lov(%p) owner %p\n",
lov, lov->lo_owner);
}
static void lov_conf_unlock(struct lov_object *lov)
{
CDEBUG(D_INODE, "To release exclusive lov(%p) owner %p\n",
lov, lov->lo_owner);
lov->lo_owner = NULL;
up_write(&lov->lo_type_guard);
}
static int lov_layout_wait(const struct lu_env *env, struct lov_object *lov)
{
struct l_wait_info lwi = { 0 };
while (atomic_read(&lov->lo_active_ios) > 0) {
CDEBUG(D_INODE, "file:" DFID " wait for active IO, now: %d.\n",
PFID(lu_object_fid(lov2lu(lov))),
atomic_read(&lov->lo_active_ios));
l_wait_event(lov->lo_waitq,
atomic_read(&lov->lo_active_ios) == 0, &lwi);
}
return 0;
}
static int lov_layout_change(const struct lu_env *unused,
struct lov_object *lov, struct lov_stripe_md *lsm,
const struct cl_object_conf *conf)
{
struct lov_device *lov_dev = lov_object_dev(lov);
enum lov_layout_type llt = lov_type(lsm);
union lov_layout_state *state = &lov->u;
const struct lov_layout_operations *old_ops;
const struct lov_layout_operations *new_ops;
struct lu_env *env;
u16 refcheck;
int rc;
LASSERT(0 <= lov->lo_type && lov->lo_type < ARRAY_SIZE(lov_dispatch));
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
LASSERT(0 <= llt && llt < ARRAY_SIZE(lov_dispatch));
CDEBUG(D_INODE, DFID " from %s to %s\n",
PFID(lu_object_fid(lov2lu(lov))),
llt2str(lov->lo_type), llt2str(llt));
old_ops = &lov_dispatch[lov->lo_type];
new_ops = &lov_dispatch[llt];
rc = cl_object_prune(env, &lov->lo_cl);
if (rc)
goto out;
rc = old_ops->llo_delete(env, lov, &lov->u);
if (rc)
goto out;
old_ops->llo_fini(env, lov, &lov->u);
LASSERT(!atomic_read(&lov->lo_active_ios));
CDEBUG(D_INODE, DFID "Apply new layout lov %p, type %d\n",
PFID(lu_object_fid(lov2lu(lov))), lov, llt);
lov->lo_type = LLT_EMPTY;
cl_object_header(&lov->lo_cl)->coh_page_bufsize -=
lov_page_slice_fixup(lov, NULL);
rc = new_ops->llo_init(env, lov_dev, lov, lsm, conf, state);
if (rc) {
struct obd_device *obd = lov2obd(lov_dev->ld_lov);
CERROR("%s: cannot apply new layout on " DFID " : rc = %d\n",
obd->obd_name, PFID(lu_object_fid(lov2lu(lov))), rc);
new_ops->llo_delete(env, lov, state);
new_ops->llo_fini(env, lov, state);
goto out;
}
new_ops->llo_install(env, lov, state);
lov->lo_type = llt;
out:
cl_env_put(env, &refcheck);
return rc;
}
int lov_object_init(const struct lu_env *env, struct lu_object *obj,
const struct lu_object_conf *conf)
{
struct lov_object *lov = lu2lov(obj);
struct lov_device *dev = lov_object_dev(lov);
const struct cl_object_conf *cconf = lu2cl_conf(conf);
union lov_layout_state *set = &lov->u;
const struct lov_layout_operations *ops;
struct lov_stripe_md *lsm = NULL;
int rc;
init_rwsem(&lov->lo_type_guard);
atomic_set(&lov->lo_active_ios, 0);
init_waitqueue_head(&lov->lo_waitq);
cl_object_page_init(lu2cl(obj), sizeof(struct lov_page));
lov->lo_type = LLT_EMPTY;
if (cconf->u.coc_layout.lb_buf) {
lsm = lov_unpackmd(dev->ld_lov,
cconf->u.coc_layout.lb_buf,
cconf->u.coc_layout.lb_len);
if (IS_ERR(lsm))
return PTR_ERR(lsm);
}
lov->lo_type = lov_type(lsm);
ops = &lov_dispatch[lov->lo_type];
rc = ops->llo_init(env, dev, lov, lsm, cconf, set);
if (!rc)
ops->llo_install(env, lov, set);
lov_lsm_put(lsm);
return rc;
}
static int lov_conf_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_object_conf *conf)
{
struct lov_stripe_md *lsm = NULL;
struct lov_object *lov = cl2lov(obj);
int result = 0;
if (conf->coc_opc == OBJECT_CONF_SET &&
conf->u.coc_layout.lb_buf) {
lsm = lov_unpackmd(lov_object_dev(lov)->ld_lov,
conf->u.coc_layout.lb_buf,
conf->u.coc_layout.lb_len);
if (IS_ERR(lsm))
return PTR_ERR(lsm);
}
lov_conf_lock(lov);
if (conf->coc_opc == OBJECT_CONF_INVALIDATE) {
lov->lo_layout_invalid = true;
result = 0;
goto out;
}
if (conf->coc_opc == OBJECT_CONF_WAIT) {
if (lov->lo_layout_invalid &&
atomic_read(&lov->lo_active_ios) > 0) {
lov_conf_unlock(lov);
result = lov_layout_wait(env, lov);
lov_conf_lock(lov);
}
goto out;
}
LASSERT(conf->coc_opc == OBJECT_CONF_SET);
if ((!lsm && !lov->lo_lsm) ||
((lsm && lov->lo_lsm) &&
(lov->lo_lsm->lsm_layout_gen == lsm->lsm_layout_gen) &&
(lov->lo_lsm->lsm_pattern == lsm->lsm_pattern))) {
lov->lo_layout_invalid = false;
result = 0;
goto out;
}
if (atomic_read(&lov->lo_active_ios) > 0) {
lov->lo_layout_invalid = true;
result = -EBUSY;
goto out;
}
result = lov_layout_change(env, lov, lsm, conf);
lov->lo_layout_invalid = result != 0;
out:
lov_conf_unlock(lov);
lov_lsm_put(lsm);
CDEBUG(D_INODE, DFID " lo_layout_invalid=%d\n",
PFID(lu_object_fid(lov2lu(lov))), lov->lo_layout_invalid);
return result;
}
static void lov_object_delete(const struct lu_env *env, struct lu_object *obj)
{
struct lov_object *lov = lu2lov(obj);
LOV_2DISPATCH_VOID(lov, llo_delete, env, lov, &lov->u);
}
static void lov_object_free(const struct lu_env *env, struct lu_object *obj)
{
struct lov_object *lov = lu2lov(obj);
LOV_2DISPATCH_VOID(lov, llo_fini, env, lov, &lov->u);
lu_object_fini(obj);
kmem_cache_free(lov_object_kmem, lov);
}
static int lov_object_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *o)
{
return LOV_2DISPATCH_NOLOCK(lu2lov(o), llo_print, env, cookie, p, o);
}
int lov_page_init(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, pgoff_t index)
{
return LOV_2DISPATCH_NOLOCK(cl2lov(obj), llo_page_init, env, obj, page,
index);
}
int lov_io_init(const struct lu_env *env, struct cl_object *obj,
struct cl_io *io)
{
CL_IO_SLICE_CLEAN(lov_env_io(env), lis_cl);
CDEBUG(D_INODE, DFID "io %p type %d ignore/verify layout %d/%d\n",
PFID(lu_object_fid(&obj->co_lu)), io, io->ci_type,
io->ci_ignore_layout, io->ci_verify_layout);
return LOV_2DISPATCH_MAYLOCK(cl2lov(obj), llo_io_init,
!io->ci_ignore_layout, env, obj, io);
}
static int lov_attr_get(const struct lu_env *env, struct cl_object *obj,
struct cl_attr *attr)
{
return LOV_2DISPATCH_NOLOCK(cl2lov(obj), llo_getattr, env, obj, attr);
}
static int lov_attr_update(const struct lu_env *env, struct cl_object *obj,
const struct cl_attr *attr, unsigned int valid)
{
return 0;
}
int lov_lock_init(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
return LOV_2DISPATCH_NOLOCK(cl2lov(obj), llo_lock_init, env, obj, lock,
io);
}
static int fiemap_calc_last_stripe(struct lov_stripe_md *lsm,
loff_t fm_start, loff_t fm_end,
int start_stripe, int *stripe_count)
{
int last_stripe;
loff_t obd_start;
loff_t obd_end;
int i, j;
if (fm_end - fm_start > lsm->lsm_stripe_size * lsm->lsm_stripe_count) {
last_stripe = (start_stripe < 1 ? lsm->lsm_stripe_count - 1 :
start_stripe - 1);
*stripe_count = lsm->lsm_stripe_count;
} else {
for (j = 0, i = start_stripe; j < lsm->lsm_stripe_count;
i = (i + 1) % lsm->lsm_stripe_count, j++) {
if (!(lov_stripe_intersects(lsm, i, fm_start, fm_end,
&obd_start, &obd_end)))
break;
}
*stripe_count = j;
last_stripe = (start_stripe + j - 1) % lsm->lsm_stripe_count;
}
return last_stripe;
}
static void fiemap_prepare_and_copy_exts(struct fiemap *fiemap,
struct fiemap_extent *lcl_fm_ext,
int ost_index, unsigned int ext_count,
int current_extent)
{
unsigned int ext;
char *to;
for (ext = 0; ext < ext_count; ext++) {
lcl_fm_ext[ext].fe_device = ost_index;
lcl_fm_ext[ext].fe_flags |= FIEMAP_EXTENT_NET;
}
to = (char *)fiemap + fiemap_count_to_size(current_extent);
memcpy(to, lcl_fm_ext, ext_count * sizeof(struct fiemap_extent));
}
static loff_t fiemap_calc_fm_end_offset(struct fiemap *fiemap,
struct lov_stripe_md *lsm,
loff_t fm_start, loff_t fm_end,
int *start_stripe)
{
loff_t local_end = fiemap->fm_extents[0].fe_logical;
loff_t lun_start, lun_end;
loff_t fm_end_offset;
int stripe_no = -1;
int i;
if (!fiemap->fm_extent_count || !fiemap->fm_extents[0].fe_logical)
return 0;
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_oinfo *oinfo = lsm->lsm_oinfo[i];
if (lov_oinfo_is_dummy(oinfo))
continue;
if (oinfo->loi_ost_idx == fiemap->fm_extents[0].fe_device) {
stripe_no = i;
break;
}
}
if (stripe_no == -1)
return -EINVAL;
if (lov_stripe_intersects(lsm, stripe_no, fm_start, fm_end,
&lun_start, &lun_end) &&
local_end < lun_end) {
fm_end_offset = local_end;
*start_stripe = stripe_no;
} else {
fm_end_offset = 0;
*start_stripe = (stripe_no + 1) % lsm->lsm_stripe_count;
}
return fm_end_offset;
}
static int lov_object_fiemap(const struct lu_env *env, struct cl_object *obj,
struct ll_fiemap_info_key *fmkey,
struct fiemap *fiemap, size_t *buflen)
{
struct lov_obd *lov = lu2lov_dev(obj->co_lu.lo_dev)->ld_lov;
unsigned int buffer_size = FIEMAP_BUFFER_SIZE;
struct fiemap_extent *lcl_fm_ext;
struct cl_object *subobj = NULL;
struct fiemap *fm_local = NULL;
struct lov_stripe_md *lsm;
loff_t fm_start;
loff_t fm_end;
loff_t fm_length;
loff_t fm_end_offset;
int count_local;
int ost_index = 0;
int start_stripe;
int current_extent = 0;
int rc = 0;
int last_stripe;
int cur_stripe = 0;
int cur_stripe_wrap = 0;
int stripe_count;
bool enough = false;
bool ost_eof = false;
bool ost_done = false;
lsm = lov_lsm_addref(cl2lov(obj));
if (!lsm)
return -ENODATA;
if (lsm->lsm_stripe_count > 1 &&
!(fiemap->fm_flags & FIEMAP_FLAG_DEVICE_ORDER)) {
rc = -ENOTSUPP;
goto out;
}
if (lsm_is_released(lsm)) {
if (fiemap->fm_start < fmkey->lfik_oa.o_size) {
fiemap->fm_mapped_extents = 1;
fiemap->fm_extents[0].fe_logical = fiemap->fm_start;
if (fiemap->fm_start + fiemap->fm_length <
fmkey->lfik_oa.o_size)
fiemap->fm_extents[0].fe_length =
fiemap->fm_length;
else
fiemap->fm_extents[0].fe_length =
fmkey->lfik_oa.o_size -
fiemap->fm_start;
fiemap->fm_extents[0].fe_flags |=
FIEMAP_EXTENT_UNKNOWN | FIEMAP_EXTENT_LAST;
}
rc = 0;
goto out;
}
if (fiemap_count_to_size(fiemap->fm_extent_count) < buffer_size)
buffer_size = fiemap_count_to_size(fiemap->fm_extent_count);
fm_local = libcfs_kvzalloc(buffer_size, GFP_NOFS);
if (!fm_local) {
rc = -ENOMEM;
goto out;
}
lcl_fm_ext = &fm_local->fm_extents[0];
count_local = fiemap_size_to_count(buffer_size);
fm_start = fiemap->fm_start;
fm_length = fiemap->fm_length;
start_stripe = lov_stripe_number(lsm, fm_start);
fm_end = (fm_length == ~0ULL) ? fmkey->lfik_oa.o_size :
fm_start + fm_length - 1;
if (fm_end > fmkey->lfik_oa.o_size)
fm_end = fmkey->lfik_oa.o_size;
last_stripe = fiemap_calc_last_stripe(lsm, fm_start, fm_end,
start_stripe, &stripe_count);
fm_end_offset = fiemap_calc_fm_end_offset(fiemap, lsm, fm_start, fm_end,
&start_stripe);
if (fm_end_offset == -EINVAL) {
rc = -EINVAL;
goto out;
}
if (fiemap_count_to_size(fiemap->fm_extent_count) > *buflen)
fiemap->fm_extent_count = fiemap_size_to_count(*buflen);
if (!fiemap->fm_extent_count)
count_local = 0;
for (cur_stripe = start_stripe; stripe_count > 0;
--stripe_count,
cur_stripe = (cur_stripe + 1) % lsm->lsm_stripe_count) {
loff_t req_fm_len;
loff_t len_mapped_single_call;
loff_t lun_start;
loff_t lun_end;
loff_t obd_object_end;
unsigned int ext_count;
cur_stripe_wrap = cur_stripe;
if (!(lov_stripe_intersects(lsm, cur_stripe, fm_start, fm_end,
&lun_start, &obd_object_end)))
continue;
if (lov_oinfo_is_dummy(lsm->lsm_oinfo[cur_stripe])) {
rc = -EIO;
goto out;
}
if (fm_end_offset && cur_stripe == start_stripe)
lun_start = fm_end_offset;
if (fm_length != ~0ULL) {
if (fm_start + fm_length < fm_start)
fm_length = ~0ULL - fm_start;
lun_end = lov_size_to_stripe(lsm, fm_start + fm_length,
cur_stripe);
} else {
lun_end = ~0ULL;
}
if (lun_start == lun_end)
continue;
req_fm_len = obd_object_end - lun_start;
fm_local->fm_length = 0;
len_mapped_single_call = 0;
subobj = lov_find_subobj(env, cl2lov(obj), lsm,
cur_stripe);
if (IS_ERR(subobj)) {
rc = PTR_ERR(subobj);
goto out;
}
ost_eof = false;
ost_done = false;
do {
if (fiemap->fm_extent_count > 0) {
if (current_extent + count_local >
fiemap->fm_extent_count)
count_local = fiemap->fm_extent_count -
current_extent;
}
lun_start += len_mapped_single_call;
fm_local->fm_length = req_fm_len -
len_mapped_single_call;
req_fm_len = fm_local->fm_length;
fm_local->fm_extent_count = enough ? 1 : count_local;
fm_local->fm_mapped_extents = 0;
fm_local->fm_flags = fiemap->fm_flags;
ost_index = lsm->lsm_oinfo[cur_stripe]->loi_ost_idx;
if (ost_index < 0 ||
ost_index >= lov->desc.ld_tgt_count) {
rc = -EINVAL;
goto obj_put;
}
if (!lov->lov_tgts[ost_index]->ltd_active) {
fm_local->fm_flags |= FIEMAP_EXTENT_LAST;
fm_local->fm_mapped_extents = 1;
lcl_fm_ext[0].fe_logical = lun_start;
lcl_fm_ext[0].fe_length = obd_object_end -
lun_start;
lcl_fm_ext[0].fe_flags |= FIEMAP_EXTENT_UNKNOWN;
goto inactive_tgt;
}
fm_local->fm_start = lun_start;
fm_local->fm_flags &= ~FIEMAP_FLAG_DEVICE_ORDER;
memcpy(&fmkey->lfik_fiemap, fm_local, sizeof(*fm_local));
*buflen = fiemap_count_to_size(fm_local->fm_extent_count);
rc = cl_object_fiemap(env, subobj, fmkey, fm_local,
buflen);
if (rc)
goto obj_put;
inactive_tgt:
ext_count = fm_local->fm_mapped_extents;
if (!ext_count) {
ost_done = true;
if (cur_stripe_wrap == last_stripe) {
fiemap->fm_mapped_extents = 0;
goto finish;
}
break;
} else if (enough) {
goto finish;
}
if (!fiemap->fm_extent_count) {
current_extent += ext_count;
break;
}
len_mapped_single_call =
lcl_fm_ext[ext_count - 1].fe_logical -
lun_start + lcl_fm_ext[ext_count - 1].fe_length;
if (req_fm_len <= len_mapped_single_call)
ost_done = true;
if (lcl_fm_ext[ext_count - 1].fe_flags &
FIEMAP_EXTENT_LAST)
lcl_fm_ext[ext_count - 1].fe_flags &=
~FIEMAP_EXTENT_LAST;
if (lov_stripe_size(lsm,
lcl_fm_ext[ext_count - 1].fe_logical +
lcl_fm_ext[ext_count - 1].fe_length,
cur_stripe) >= fmkey->lfik_oa.o_size)
ost_eof = true;
fiemap_prepare_and_copy_exts(fiemap, lcl_fm_ext,
ost_index, ext_count,
current_extent);
current_extent += ext_count;
if (current_extent >= fiemap->fm_extent_count)
enough = true;
} while (!ost_done && !ost_eof);
cl_object_put(env, subobj);
subobj = NULL;
if (cur_stripe_wrap == last_stripe)
goto finish;
}
finish:
if (lsm->lsm_stripe_count > 1)
fiemap->fm_flags |= FIEMAP_FLAG_DEVICE_ORDER;
if (!fiemap->fm_extent_count)
goto skip_last_device_calc;
if ((cur_stripe_wrap == last_stripe) && (ost_done || ost_eof))
fiemap->fm_extents[current_extent - 1].fe_flags |=
FIEMAP_EXTENT_LAST;
skip_last_device_calc:
fiemap->fm_mapped_extents = current_extent;
obj_put:
if (subobj)
cl_object_put(env, subobj);
out:
kvfree(fm_local);
lov_lsm_put(lsm);
return rc;
}
static int lov_object_getstripe(const struct lu_env *env, struct cl_object *obj,
struct lov_user_md __user *lum)
{
struct lov_object *lov = cl2lov(obj);
struct lov_stripe_md *lsm;
int rc = 0;
lsm = lov_lsm_addref(lov);
if (!lsm)
return -ENODATA;
rc = lov_getstripe(cl2lov(obj), lsm, lum);
lov_lsm_put(lsm);
return rc;
}
static int lov_object_layout_get(const struct lu_env *env,
struct cl_object *obj,
struct cl_layout *cl)
{
struct lov_object *lov = cl2lov(obj);
struct lov_stripe_md *lsm = lov_lsm_addref(lov);
struct lu_buf *buf = &cl->cl_buf;
ssize_t rc;
if (!lsm) {
cl->cl_size = 0;
cl->cl_layout_gen = CL_LAYOUT_GEN_EMPTY;
return 0;
}
cl->cl_size = lov_mds_md_size(lsm->lsm_stripe_count, lsm->lsm_magic);
cl->cl_layout_gen = lsm->lsm_layout_gen;
rc = lov_lsm_pack(lsm, buf->lb_buf, buf->lb_len);
lov_lsm_put(lsm);
return rc < 0 ? rc : 0;
}
static loff_t lov_object_maxbytes(struct cl_object *obj)
{
struct lov_object *lov = cl2lov(obj);
struct lov_stripe_md *lsm = lov_lsm_addref(lov);
loff_t maxbytes;
if (!lsm)
return LLONG_MAX;
maxbytes = lsm->lsm_maxbytes;
lov_lsm_put(lsm);
return maxbytes;
}
struct lu_object *lov_object_alloc(const struct lu_env *env,
const struct lu_object_header *unused,
struct lu_device *dev)
{
struct lov_object *lov;
struct lu_object *obj;
lov = kmem_cache_zalloc(lov_object_kmem, GFP_NOFS);
if (lov) {
obj = lov2lu(lov);
lu_object_init(obj, NULL, dev);
lov->lo_cl.co_ops = &lov_ops;
lov->lo_type = -1;
obj->lo_ops = &lov_lu_obj_ops;
} else {
obj = NULL;
}
return obj;
}
struct lov_stripe_md *lov_lsm_addref(struct lov_object *lov)
{
struct lov_stripe_md *lsm = NULL;
lov_conf_freeze(lov);
if (lov->lo_lsm) {
lsm = lsm_addref(lov->lo_lsm);
CDEBUG(D_INODE, "lsm %p addref %d/%d by %p.\n",
lsm, atomic_read(&lsm->lsm_refc),
lov->lo_layout_invalid, current);
}
lov_conf_thaw(lov);
return lsm;
}
int lov_read_and_clear_async_rc(struct cl_object *clob)
{
struct lu_object *luobj;
int rc = 0;
luobj = lu_object_locate(&cl_object_header(clob)->coh_lu,
&lov_device_type);
if (luobj) {
struct lov_object *lov = lu2lov(luobj);
lov_conf_freeze(lov);
switch (lov->lo_type) {
case LLT_RAID0: {
struct lov_stripe_md *lsm;
int i;
lsm = lov->lo_lsm;
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
if (lov_oinfo_is_dummy(loi))
continue;
if (loi->loi_ar.ar_rc && !rc)
rc = loi->loi_ar.ar_rc;
loi->loi_ar.ar_rc = 0;
}
}
case LLT_RELEASED:
case LLT_EMPTY:
break;
default:
LBUG();
}
lov_conf_thaw(lov);
}
return rc;
}
