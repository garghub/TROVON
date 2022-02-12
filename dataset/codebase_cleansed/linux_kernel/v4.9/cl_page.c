static void cl_page_get_trust(struct cl_page *page)
{
LASSERT(atomic_read(&page->cp_ref) > 0);
atomic_inc(&page->cp_ref);
}
static const struct cl_page_slice *
cl_page_at_trusted(const struct cl_page *page,
const struct lu_device_type *dtype)
{
const struct cl_page_slice *slice;
list_for_each_entry(slice, &page->cp_layers, cpl_linkage) {
if (slice->cpl_obj->co_lu.lo_dev->ld_type == dtype)
return slice;
}
return NULL;
}
static void cl_page_free(const struct lu_env *env, struct cl_page *page)
{
struct cl_object *obj = page->cp_obj;
PASSERT(env, page, list_empty(&page->cp_batch));
PASSERT(env, page, !page->cp_owner);
PASSERT(env, page, !page->cp_req);
PASSERT(env, page, page->cp_state == CPS_FREEING);
while (!list_empty(&page->cp_layers)) {
struct cl_page_slice *slice;
slice = list_entry(page->cp_layers.next,
struct cl_page_slice, cpl_linkage);
list_del_init(page->cp_layers.next);
if (unlikely(slice->cpl_ops->cpo_fini))
slice->cpl_ops->cpo_fini(env, slice);
}
lu_object_ref_del_at(&obj->co_lu, &page->cp_obj_ref, "cl_page", page);
cl_object_put(env, obj);
lu_ref_fini(&page->cp_reference);
kfree(page);
}
static inline void cl_page_state_set_trust(struct cl_page *page,
enum cl_page_state state)
{
*(enum cl_page_state *)&page->cp_state = state;
}
struct cl_page *cl_page_alloc(const struct lu_env *env,
struct cl_object *o, pgoff_t ind,
struct page *vmpage,
enum cl_page_type type)
{
struct cl_page *page;
struct lu_object_header *head;
page = kzalloc(cl_object_header(o)->coh_page_bufsize, GFP_NOFS);
if (page) {
int result = 0;
atomic_set(&page->cp_ref, 1);
page->cp_obj = o;
cl_object_get(o);
lu_object_ref_add_at(&o->co_lu, &page->cp_obj_ref, "cl_page",
page);
page->cp_vmpage = vmpage;
cl_page_state_set_trust(page, CPS_CACHED);
page->cp_type = type;
INIT_LIST_HEAD(&page->cp_layers);
INIT_LIST_HEAD(&page->cp_batch);
INIT_LIST_HEAD(&page->cp_flight);
lu_ref_init(&page->cp_reference);
head = o->co_lu.lo_header;
list_for_each_entry(o, &head->loh_layers, co_lu.lo_linkage) {
if (o->co_ops->coo_page_init) {
result = o->co_ops->coo_page_init(env, o, page,
ind);
if (result != 0) {
cl_page_delete0(env, page);
cl_page_free(env, page);
page = ERR_PTR(result);
break;
}
}
}
} else {
page = ERR_PTR(-ENOMEM);
}
return page;
}
struct cl_page *cl_page_find(const struct lu_env *env,
struct cl_object *o,
pgoff_t idx, struct page *vmpage,
enum cl_page_type type)
{
struct cl_page *page = NULL;
struct cl_object_header *hdr;
LASSERT(type == CPT_CACHEABLE || type == CPT_TRANSIENT);
might_sleep();
hdr = cl_object_header(o);
CDEBUG(D_PAGE, "%lu@"DFID" %p %lx %d\n",
idx, PFID(&hdr->coh_lu.loh_fid), vmpage, vmpage->private, type);
if (type == CPT_CACHEABLE) {
KLASSERT(PageLocked(vmpage));
page = cl_vmpage_page(vmpage, o);
if (page)
return page;
}
page = cl_page_alloc(env, o, idx, vmpage, type);
return page;
}
static inline int cl_page_invariant(const struct cl_page *pg)
{
return cl_page_in_use_noref(pg);
}
static void cl_page_state_set0(const struct lu_env *env,
struct cl_page *page, enum cl_page_state state)
{
enum cl_page_state old;
static const int allowed_transitions[CPS_NR][CPS_NR] = {
[CPS_CACHED] = {
[CPS_CACHED] = 0,
[CPS_OWNED] = 1,
[CPS_PAGEIN] = 0,
[CPS_PAGEOUT] = 1,
[CPS_FREEING] = 1,
},
[CPS_OWNED] = {
[CPS_CACHED] = 1,
[CPS_OWNED] = 0,
[CPS_PAGEIN] = 1,
[CPS_PAGEOUT] = 1,
[CPS_FREEING] = 1,
},
[CPS_PAGEIN] = {
[CPS_CACHED] = 1,
[CPS_OWNED] = 0,
[CPS_PAGEIN] = 0,
[CPS_PAGEOUT] = 0,
[CPS_FREEING] = 0,
},
[CPS_PAGEOUT] = {
[CPS_CACHED] = 1,
[CPS_OWNED] = 0,
[CPS_PAGEIN] = 0,
[CPS_PAGEOUT] = 0,
[CPS_FREEING] = 0,
},
[CPS_FREEING] = {
[CPS_CACHED] = 0,
[CPS_OWNED] = 0,
[CPS_PAGEIN] = 0,
[CPS_PAGEOUT] = 0,
[CPS_FREEING] = 0,
}
};
old = page->cp_state;
PASSERT(env, page, allowed_transitions[old][state]);
CL_PAGE_HEADER(D_TRACE, env, page, "%d -> %d\n", old, state);
PASSERT(env, page, page->cp_state == old);
PASSERT(env, page, equi(state == CPS_OWNED, page->cp_owner));
cl_page_state_set_trust(page, state);
}
static void cl_page_state_set(const struct lu_env *env,
struct cl_page *page, enum cl_page_state state)
{
cl_page_state_set0(env, page, state);
}
void cl_page_get(struct cl_page *page)
{
cl_page_get_trust(page);
}
void cl_page_put(const struct lu_env *env, struct cl_page *page)
{
CL_PAGE_HEADER(D_TRACE, env, page, "%d\n",
atomic_read(&page->cp_ref));
if (atomic_dec_and_test(&page->cp_ref)) {
LASSERT(page->cp_state == CPS_FREEING);
LASSERT(atomic_read(&page->cp_ref) == 0);
PASSERT(env, page, !page->cp_owner);
PASSERT(env, page, list_empty(&page->cp_batch));
cl_page_free(env, page);
}
}
struct cl_page *cl_vmpage_page(struct page *vmpage, struct cl_object *obj)
{
struct cl_page *page;
KLASSERT(PageLocked(vmpage));
page = (struct cl_page *)vmpage->private;
if (page) {
cl_page_get_trust(page);
LASSERT(page->cp_type == CPT_CACHEABLE);
}
return page;
}
const struct cl_page_slice *cl_page_at(const struct cl_page *page,
const struct lu_device_type *dtype)
{
return cl_page_at_trusted(page, dtype);
}
static int cl_page_invoke(const struct lu_env *env,
struct cl_io *io, struct cl_page *page, ptrdiff_t op)
{
PINVRNT(env, page, cl_object_same(page->cp_obj, io->ci_obj));
return CL_PAGE_INVOKE(env, page, op,
(const struct lu_env *,
const struct cl_page_slice *, struct cl_io *),
io);
}
static void cl_page_invoid(const struct lu_env *env,
struct cl_io *io, struct cl_page *page, ptrdiff_t op)
{
PINVRNT(env, page, cl_object_same(page->cp_obj, io->ci_obj));
CL_PAGE_INVOID(env, page, op,
(const struct lu_env *,
const struct cl_page_slice *, struct cl_io *), io);
}
static void cl_page_owner_clear(struct cl_page *page)
{
if (page->cp_owner) {
LASSERT(page->cp_owner->ci_owned_nr > 0);
page->cp_owner->ci_owned_nr--;
page->cp_owner = NULL;
}
}
static void cl_page_owner_set(struct cl_page *page)
{
page->cp_owner->ci_owned_nr++;
}
void cl_page_disown0(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
enum cl_page_state state;
state = pg->cp_state;
PINVRNT(env, pg, state == CPS_OWNED || state == CPS_FREEING);
PINVRNT(env, pg, cl_page_invariant(pg) || state == CPS_FREEING);
cl_page_owner_clear(pg);
if (state == CPS_OWNED)
cl_page_state_set(env, pg, CPS_CACHED);
CL_PAGE_INVOID_REVERSE(env, pg, CL_PAGE_OP(cpo_disown),
(const struct lu_env *,
const struct cl_page_slice *, struct cl_io *),
io);
}
int cl_page_is_owned(const struct cl_page *pg, const struct cl_io *io)
{
struct cl_io *top = cl_io_top((struct cl_io *)io);
LINVRNT(cl_object_same(pg->cp_obj, io->ci_obj));
return pg->cp_state == CPS_OWNED && pg->cp_owner == top;
}
static int cl_page_own0(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg, int nonblock)
{
int result;
PINVRNT(env, pg, !cl_page_is_owned(pg, io));
io = cl_io_top(io);
if (pg->cp_state == CPS_FREEING) {
result = -ENOENT;
} else {
result = CL_PAGE_INVOKE(env, pg, CL_PAGE_OP(cpo_own),
(const struct lu_env *,
const struct cl_page_slice *,
struct cl_io *, int),
io, nonblock);
if (result == 0) {
PASSERT(env, pg, !pg->cp_owner);
PASSERT(env, pg, !pg->cp_req);
pg->cp_owner = cl_io_top(io);
cl_page_owner_set(pg);
if (pg->cp_state != CPS_FREEING) {
cl_page_state_set(env, pg, CPS_OWNED);
} else {
cl_page_disown0(env, io, pg);
result = -ENOENT;
}
}
}
PINVRNT(env, pg, ergo(result == 0, cl_page_invariant(pg)));
return result;
}
int cl_page_own(const struct lu_env *env, struct cl_io *io, struct cl_page *pg)
{
return cl_page_own0(env, io, pg, 0);
}
int cl_page_own_try(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg)
{
return cl_page_own0(env, io, pg, 1);
}
void cl_page_assume(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_object_same(pg->cp_obj, io->ci_obj));
io = cl_io_top(io);
cl_page_invoid(env, io, pg, CL_PAGE_OP(cpo_assume));
PASSERT(env, pg, !pg->cp_owner);
pg->cp_owner = cl_io_top(io);
cl_page_owner_set(pg);
cl_page_state_set(env, pg, CPS_OWNED);
}
void cl_page_unassume(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
io = cl_io_top(io);
cl_page_owner_clear(pg);
cl_page_state_set(env, pg, CPS_CACHED);
CL_PAGE_INVOID_REVERSE(env, pg, CL_PAGE_OP(cpo_unassume),
(const struct lu_env *,
const struct cl_page_slice *, struct cl_io *),
io);
}
void cl_page_disown(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_is_owned(pg, io) ||
pg->cp_state == CPS_FREEING);
io = cl_io_top(io);
cl_page_disown0(env, io, pg);
}
void cl_page_discard(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
cl_page_invoid(env, io, pg, CL_PAGE_OP(cpo_discard));
}
static void cl_page_delete0(const struct lu_env *env, struct cl_page *pg)
{
PASSERT(env, pg, pg->cp_state != CPS_FREEING);
cl_page_owner_clear(pg);
cl_page_state_set0(env, pg, CPS_FREEING);
CL_PAGE_INVOID_REVERSE(env, pg, CL_PAGE_OP(cpo_delete),
(const struct lu_env *,
const struct cl_page_slice *));
}
void cl_page_delete(const struct lu_env *env, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_invariant(pg));
cl_page_delete0(env, pg);
}
void cl_page_export(const struct lu_env *env, struct cl_page *pg, int uptodate)
{
PINVRNT(env, pg, cl_page_invariant(pg));
CL_PAGE_INVOID(env, pg, CL_PAGE_OP(cpo_export),
(const struct lu_env *,
const struct cl_page_slice *, int), uptodate);
}
int cl_page_is_vmlocked(const struct lu_env *env, const struct cl_page *pg)
{
int result;
const struct cl_page_slice *slice;
slice = container_of(pg->cp_layers.next,
const struct cl_page_slice, cpl_linkage);
PASSERT(env, pg, slice->cpl_ops->cpo_is_vmlocked);
result = slice->cpl_ops->cpo_is_vmlocked(env, slice);
PASSERT(env, pg, result == -EBUSY || result == -ENODATA);
return result == -EBUSY;
}
static enum cl_page_state cl_req_type_state(enum cl_req_type crt)
{
return crt == CRT_WRITE ? CPS_PAGEOUT : CPS_PAGEIN;
}
static void cl_page_io_start(const struct lu_env *env,
struct cl_page *pg, enum cl_req_type crt)
{
cl_page_owner_clear(pg);
cl_page_state_set(env, pg, cl_req_type_state(crt));
}
int cl_page_prep(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg, enum cl_req_type crt)
{
int result;
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
PINVRNT(env, pg, crt < CRT_NR);
if (crt >= CRT_NR)
return -EINVAL;
result = cl_page_invoke(env, io, pg, CL_PAGE_OP(io[crt].cpo_prep));
if (result == 0)
cl_page_io_start(env, pg, crt);
CL_PAGE_HEADER(D_TRACE, env, pg, "%d %d\n", crt, result);
return result;
}
void cl_page_completion(const struct lu_env *env,
struct cl_page *pg, enum cl_req_type crt, int ioret)
{
struct cl_sync_io *anchor = pg->cp_sync_io;
PASSERT(env, pg, crt < CRT_NR);
PASSERT(env, pg, !pg->cp_req);
PASSERT(env, pg, pg->cp_state == cl_req_type_state(crt));
CL_PAGE_HEADER(D_TRACE, env, pg, "%d %d\n", crt, ioret);
cl_page_state_set(env, pg, CPS_CACHED);
if (crt >= CRT_NR)
return;
CL_PAGE_INVOID_REVERSE(env, pg, CL_PAGE_OP(io[crt].cpo_completion),
(const struct lu_env *,
const struct cl_page_slice *, int), ioret);
if (anchor) {
LASSERT(pg->cp_sync_io == anchor);
pg->cp_sync_io = NULL;
}
cl_page_put(env, pg);
if (anchor)
cl_sync_io_note(env, anchor, ioret);
}
int cl_page_make_ready(const struct lu_env *env, struct cl_page *pg,
enum cl_req_type crt)
{
int result;
PINVRNT(env, pg, crt < CRT_NR);
if (crt >= CRT_NR)
return -EINVAL;
result = CL_PAGE_INVOKE(env, pg, CL_PAGE_OP(io[crt].cpo_make_ready),
(const struct lu_env *,
const struct cl_page_slice *));
if (result == 0) {
PASSERT(env, pg, pg->cp_state == CPS_CACHED);
cl_page_io_start(env, pg, crt);
}
CL_PAGE_HEADER(D_TRACE, env, pg, "%d %d\n", crt, result);
return result;
}
int cl_page_flush(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg)
{
int result;
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
result = cl_page_invoke(env, io, pg, CL_PAGE_OP(cpo_flush));
CL_PAGE_HEADER(D_TRACE, env, pg, "%d\n", result);
return result;
}
int cl_page_is_under_lock(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, pgoff_t *max_index)
{
int rc;
PINVRNT(env, page, cl_page_invariant(page));
rc = CL_PAGE_INVOKE_REVERSE(env, page, CL_PAGE_OP(cpo_is_under_lock),
(const struct lu_env *,
const struct cl_page_slice *,
struct cl_io *, pgoff_t *),
io, max_index);
return rc;
}
void cl_page_clip(const struct lu_env *env, struct cl_page *pg,
int from, int to)
{
PINVRNT(env, pg, cl_page_invariant(pg));
CL_PAGE_HEADER(D_TRACE, env, pg, "%d %d\n", from, to);
CL_PAGE_INVOID(env, pg, CL_PAGE_OP(cpo_clip),
(const struct lu_env *,
const struct cl_page_slice *, int, int),
from, to);
}
void cl_page_header_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_page *pg)
{
(*printer)(env, cookie,
"page@%p[%d %p %d %d %p %p]\n",
pg, atomic_read(&pg->cp_ref), pg->cp_obj,
pg->cp_state, pg->cp_type,
pg->cp_owner, pg->cp_req);
}
void cl_page_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_page *pg)
{
cl_page_header_print(env, cookie, printer, pg);
CL_PAGE_INVOKE(env, (struct cl_page *)pg, CL_PAGE_OP(cpo_print),
(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t p), cookie, printer);
(*printer)(env, cookie, "end page@%p\n", pg);
}
int cl_page_cancel(const struct lu_env *env, struct cl_page *page)
{
return CL_PAGE_INVOKE(env, page, CL_PAGE_OP(cpo_cancel),
(const struct lu_env *,
const struct cl_page_slice *));
}
loff_t cl_offset(const struct cl_object *obj, pgoff_t idx)
{
return (loff_t)idx << PAGE_SHIFT;
}
pgoff_t cl_index(const struct cl_object *obj, loff_t offset)
{
return offset >> PAGE_SHIFT;
}
size_t cl_page_size(const struct cl_object *obj)
{
return 1UL << PAGE_SHIFT;
}
void cl_page_slice_add(struct cl_page *page, struct cl_page_slice *slice,
struct cl_object *obj, pgoff_t index,
const struct cl_page_operations *ops)
{
list_add_tail(&slice->cpl_linkage, &page->cp_layers);
slice->cpl_obj = obj;
slice->cpl_index = index;
slice->cpl_ops = ops;
slice->cpl_page = page;
}
struct cl_client_cache *cl_cache_init(unsigned long lru_page_max)
{
struct cl_client_cache *cache = NULL;
cache = kzalloc(sizeof(*cache), GFP_KERNEL);
if (!cache)
return NULL;
atomic_set(&cache->ccc_users, 1);
cache->ccc_lru_max = lru_page_max;
atomic_long_set(&cache->ccc_lru_left, lru_page_max);
spin_lock_init(&cache->ccc_lru_lock);
INIT_LIST_HEAD(&cache->ccc_lru);
atomic_long_set(&cache->ccc_unstable_nr, 0);
init_waitqueue_head(&cache->ccc_unstable_waitq);
return cache;
}
void cl_cache_incref(struct cl_client_cache *cache)
{
atomic_inc(&cache->ccc_users);
}
void cl_cache_decref(struct cl_client_cache *cache)
{
if (atomic_dec_and_test(&cache->ccc_users))
kfree(cache);
}
