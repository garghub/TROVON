static void cl_lock_trace0(int level, const struct lu_env *env,
const char *prefix, const struct cl_lock *lock,
const char *func, const int line)
{
struct cl_object_header *h = cl_object_header(lock->cll_descr.cld_obj);
CDEBUG(level, "%s: %p (%p/%d) at %s():%d\n",
prefix, lock, env, h->coh_nesting, func, line);
}
void cl_lock_slice_add(struct cl_lock *lock, struct cl_lock_slice *slice,
struct cl_object *obj,
const struct cl_lock_operations *ops)
{
slice->cls_lock = lock;
list_add_tail(&slice->cls_linkage, &lock->cll_layers);
slice->cls_obj = obj;
slice->cls_ops = ops;
}
void cl_lock_fini(const struct lu_env *env, struct cl_lock *lock)
{
cl_lock_trace(D_DLMTRACE, env, "destroy lock", lock);
while (!list_empty(&lock->cll_layers)) {
struct cl_lock_slice *slice;
slice = list_entry(lock->cll_layers.next,
struct cl_lock_slice, cls_linkage);
list_del_init(lock->cll_layers.next);
slice->cls_ops->clo_fini(env, slice);
}
POISON(lock, 0x5a, sizeof(*lock));
}
int cl_lock_init(const struct lu_env *env, struct cl_lock *lock,
const struct cl_io *io)
{
struct cl_object *obj = lock->cll_descr.cld_obj;
struct cl_object *scan;
int result = 0;
LASSERT(obj);
INIT_LIST_HEAD(&lock->cll_layers);
list_for_each_entry(scan, &obj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
result = scan->co_ops->coo_lock_init(env, scan, lock, io);
if (result != 0) {
cl_lock_fini(env, lock);
break;
}
}
return result;
}
const struct cl_lock_slice *cl_lock_at(const struct cl_lock *lock,
const struct lu_device_type *dtype)
{
const struct cl_lock_slice *slice;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_obj->co_lu.lo_dev->ld_type == dtype)
return slice;
}
return NULL;
}
void cl_lock_cancel(const struct lu_env *env, struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
cl_lock_trace(D_DLMTRACE, env, "cancel lock", lock);
list_for_each_entry_reverse(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_cancel)
slice->cls_ops->clo_cancel(env, slice);
}
}
int cl_lock_enqueue(const struct lu_env *env, struct cl_io *io,
struct cl_lock *lock, struct cl_sync_io *anchor)
{
const struct cl_lock_slice *slice;
int rc = -ENOSYS;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (!slice->cls_ops->clo_enqueue)
continue;
rc = slice->cls_ops->clo_enqueue(env, slice, io, anchor);
if (rc != 0)
break;
}
return rc;
}
int cl_lock_request(const struct lu_env *env, struct cl_io *io,
struct cl_lock *lock)
{
struct cl_sync_io *anchor = NULL;
__u32 enq_flags = lock->cll_descr.cld_enq_flags;
int rc;
rc = cl_lock_init(env, lock, io);
if (rc < 0)
return rc;
if ((enq_flags & CEF_ASYNC) && !(enq_flags & CEF_AGL)) {
anchor = &cl_env_info(env)->clt_anchor;
cl_sync_io_init(anchor, 1, cl_sync_io_end);
}
rc = cl_lock_enqueue(env, io, lock, anchor);
if (anchor) {
int rc2;
cl_sync_io_note(env, anchor, 0);
rc2 = cl_sync_io_wait(env, anchor, 0);
if (rc2 < 0 && rc == 0)
rc = rc2;
}
if (rc < 0)
cl_lock_release(env, lock);
return rc;
}
void cl_lock_release(const struct lu_env *env, struct cl_lock *lock)
{
cl_lock_trace(D_DLMTRACE, env, "release lock", lock);
cl_lock_cancel(env, lock);
cl_lock_fini(env, lock);
}
const char *cl_lock_mode_name(const enum cl_lock_mode mode)
{
static const char *names[] = {
[CLM_READ] = "R",
[CLM_WRITE] = "W",
[CLM_GROUP] = "G"
};
if (0 <= mode && mode < ARRAY_SIZE(names))
return names[mode];
else
return "U";
}
void cl_lock_descr_print(const struct lu_env *env, void *cookie,
lu_printer_t printer,
const struct cl_lock_descr *descr)
{
const struct lu_fid *fid;
fid = lu_object_fid(&descr->cld_obj->co_lu);
(*printer)(env, cookie, DDESCR"@"DFID, PDESCR(descr), PFID(fid));
}
void cl_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
(*printer)(env, cookie, "lock@%p", lock);
cl_lock_descr_print(env, cookie, printer, &lock->cll_descr);
(*printer)(env, cookie, " {\n");
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
(*printer)(env, cookie, " %s@%p: ",
slice->cls_obj->co_lu.lo_dev->ld_type->ldt_name,
slice);
if (slice->cls_ops->clo_print)
slice->cls_ops->clo_print(env, cookie, printer, slice);
(*printer)(env, cookie, "\n");
}
(*printer)(env, cookie, "} lock@%p\n", lock);
}
