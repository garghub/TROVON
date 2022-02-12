static void lovsub_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct lovsub_lock *lsl;
lsl = cl2lovsub_lock(slice);
LASSERT(list_empty(&lsl->lss_parents));
OBD_SLAB_FREE_PTR(lsl, lovsub_lock_kmem);
}
static void lovsub_parent_lock(const struct lu_env *env, struct lov_lock *lov)
{
struct cl_lock *parent;
parent = lov->lls_cl.cls_lock;
cl_lock_get(parent);
lu_ref_add(&parent->cll_reference, "lovsub-parent", current);
cl_lock_mutex_get(env, parent);
}
static void lovsub_parent_unlock(const struct lu_env *env, struct lov_lock *lov)
{
struct cl_lock *parent;
parent = lov->lls_cl.cls_lock;
cl_lock_mutex_put(env, lov->lls_cl.cls_lock);
lu_ref_del(&parent->cll_reference, "lovsub-parent", current);
cl_lock_put(env, parent);
}
static void lovsub_lock_state(const struct lu_env *env,
const struct cl_lock_slice *slice,
enum cl_lock_state state)
{
struct lovsub_lock *sub = cl2lovsub_lock(slice);
struct lov_lock_link *scan;
LASSERT(cl_lock_is_mutexed(slice->cls_lock));
list_for_each_entry(scan, &sub->lss_parents, lll_list) {
struct lov_lock *lov = scan->lll_super;
struct cl_lock *parent = lov->lls_cl.cls_lock;
if (sub->lss_active != parent) {
lovsub_parent_lock(env, lov);
cl_lock_signal(env, parent);
lovsub_parent_unlock(env, lov);
}
}
}
static unsigned long lovsub_lock_weigh(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lovsub_lock *lock = cl2lovsub_lock(slice);
struct lov_lock *lov;
unsigned long dumbbell;
LASSERT(cl_lock_is_mutexed(slice->cls_lock));
if (!list_empty(&lock->lss_parents)) {
lov = container_of(lock->lss_parents.next,
struct lov_lock_link, lll_list)->lll_super;
lovsub_parent_lock(env, lov);
dumbbell = cl_lock_weigh(env, lov->lls_cl.cls_lock);
lovsub_parent_unlock(env, lov);
} else
dumbbell = 0;
return dumbbell;
}
static void lovsub_lock_descr_map(const struct cl_lock_descr *in,
struct lov_object *lov,
int stripe, struct cl_lock_descr *out)
{
pgoff_t size;
pgoff_t skip;
pgoff_t start;
pgoff_t end;
start = in->cld_start;
end = in->cld_end;
if (lov->lo_lsm->lsm_stripe_count > 1) {
size = cl_index(lov2cl(lov), lov->lo_lsm->lsm_stripe_size);
skip = (lov->lo_lsm->lsm_stripe_count - 1) * size;
start += start/size * skip + stripe * size;
if (end != CL_PAGE_EOF) {
end += end/size * skip + stripe * size;
if (end < in->cld_end)
end = CL_PAGE_EOF;
}
}
out->cld_start = start;
out->cld_end = end;
}
int lov_sublock_modify(const struct lu_env *env, struct lov_lock *lov,
struct lovsub_lock *sublock,
const struct cl_lock_descr *d, int idx)
{
struct cl_lock *parent;
struct lovsub_object *subobj;
struct cl_lock_descr *pd;
struct cl_lock_descr *parent_descr;
int result;
parent = lov->lls_cl.cls_lock;
parent_descr = &parent->cll_descr;
LASSERT(cl_lock_mode_match(d->cld_mode, parent_descr->cld_mode));
subobj = cl2lovsub(sublock->lss_cl.cls_obj);
pd = &lov_env_info(env)->lti_ldescr;
pd->cld_obj = parent_descr->cld_obj;
pd->cld_mode = parent_descr->cld_mode;
pd->cld_gid = parent_descr->cld_gid;
lovsub_lock_descr_map(d, subobj->lso_super, subobj->lso_index, pd);
lov->lls_sub[idx].sub_got = *d;
if (!cl_lock_ext_match(parent_descr, pd))
result = cl_lock_modify(env, parent, pd);
else
result = 0;
return result;
}
static int lovsub_lock_modify(const struct lu_env *env,
const struct cl_lock_slice *s,
const struct cl_lock_descr *d)
{
struct lovsub_lock *lock = cl2lovsub_lock(s);
struct lov_lock_link *scan;
struct lov_lock *lov;
int result = 0;
LASSERT(cl_lock_mode_match(d->cld_mode,
s->cls_lock->cll_descr.cld_mode));
list_for_each_entry(scan, &lock->lss_parents, lll_list) {
int rc;
lov = scan->lll_super;
lovsub_parent_lock(env, lov);
rc = lov_sublock_modify(env, lov, lock, d, scan->lll_idx);
lovsub_parent_unlock(env, lov);
result = result ?: rc;
}
return result;
}
static int lovsub_lock_closure(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_lock_closure *closure)
{
struct lovsub_lock *sub;
struct cl_lock *parent;
struct lov_lock_link *scan;
int result;
LASSERT(cl_lock_is_mutexed(slice->cls_lock));
sub = cl2lovsub_lock(slice);
result = 0;
list_for_each_entry(scan, &sub->lss_parents, lll_list) {
parent = scan->lll_super->lls_cl.cls_lock;
result = cl_lock_closure_build(env, parent, closure);
if (result != 0)
break;
}
return result;
}
static int lovsub_lock_delete_one(const struct lu_env *env,
struct cl_lock *child, struct lov_lock *lov)
{
struct cl_lock *parent;
int result;
parent = lov->lls_cl.cls_lock;
if (parent->cll_error)
return 0;
result = 0;
switch (parent->cll_state) {
case CLS_ENQUEUED:
LASSERT(parent->cll_flags & CLF_CANCELLED);
break;
case CLS_QUEUING:
case CLS_FREEING:
cl_lock_signal(env, parent);
break;
case CLS_INTRANSIT:
if (cl_lock_is_intransit(parent))
lov->lls_cancel_race = 1;
break;
case CLS_CACHED:
cl_lock_state_set(env, parent, CLS_NEW);
case CLS_NEW:
if (lov->lls_nr_filled == 0) {
if (cl_lock_nr_mutexed(env) == 2) {
cl_lock_mutex_put(env, child);
cl_lock_cancel(env, parent);
cl_lock_delete(env, parent);
result = 1;
}
}
break;
case CLS_HELD:
CL_LOCK_DEBUG(D_ERROR, env, parent, "Delete CLS_HELD lock\n");
default:
CERROR("Impossible state: %d\n", parent->cll_state);
LBUG();
break;
}
return result;
}
static void lovsub_lock_delete(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct cl_lock *child = slice->cls_lock;
struct lovsub_lock *sub = cl2lovsub_lock(slice);
int restart;
LASSERT(cl_lock_is_mutexed(child));
do {
struct lov_lock *lov;
struct lov_lock_link *scan;
struct lov_lock_link *temp;
struct lov_lock_sub *subdata;
restart = 0;
list_for_each_entry_safe(scan, temp,
&sub->lss_parents, lll_list) {
lov = scan->lll_super;
subdata = &lov->lls_sub[scan->lll_idx];
lovsub_parent_lock(env, lov);
subdata->sub_got = subdata->sub_descr;
lov_lock_unlink(env, scan, sub);
restart = lovsub_lock_delete_one(env, child, lov);
lovsub_parent_unlock(env, lov);
if (restart) {
cl_lock_mutex_get(env, child);
break;
}
}
} while (restart);
}
static int lovsub_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct cl_lock_slice *slice)
{
struct lovsub_lock *sub = cl2lovsub_lock(slice);
struct lov_lock *lov;
struct lov_lock_link *scan;
list_for_each_entry(scan, &sub->lss_parents, lll_list) {
lov = scan->lll_super;
(*p)(env, cookie, "[%d %p ", scan->lll_idx, lov);
if (lov != NULL)
cl_lock_descr_print(env, cookie, p,
&lov->lls_cl.cls_lock->cll_descr);
(*p)(env, cookie, "] ");
}
return 0;
}
int lovsub_lock_init(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
struct lovsub_lock *lsk;
int result;
OBD_SLAB_ALLOC_PTR_GFP(lsk, lovsub_lock_kmem, GFP_NOFS);
if (lsk != NULL) {
INIT_LIST_HEAD(&lsk->lss_parents);
cl_lock_slice_add(lock, &lsk->lss_cl, obj, &lovsub_lock_ops);
result = 0;
} else
result = -ENOMEM;
return result;
}
