static struct cl_page *cl_page_top_trusted(struct cl_page *page)
{
while (page->cp_parent)
page = page->cp_parent;
return page;
}
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
page = cl_page_top_trusted((struct cl_page *)page);
do {
list_for_each_entry(slice, &page->cp_layers, cpl_linkage) {
if (slice->cpl_obj->co_lu.lo_dev->ld_type == dtype)
return slice;
}
page = page->cp_child;
} while (page);
return NULL;
}
struct cl_page *cl_page_lookup(struct cl_object_header *hdr, pgoff_t index)
{
struct cl_page *page;
assert_spin_locked(&hdr->coh_page_guard);
page = radix_tree_lookup(&hdr->coh_tree, index);
if (page)
cl_page_get_trust(page);
return page;
}
int cl_page_gang_lookup(const struct lu_env *env, struct cl_object *obj,
struct cl_io *io, pgoff_t start, pgoff_t end,
cl_page_gang_cb_t cb, void *cbdata)
{
struct cl_object_header *hdr;
struct cl_page *page;
struct cl_page **pvec;
const struct cl_page_slice *slice;
const struct lu_device_type *dtype;
pgoff_t idx;
unsigned int nr;
unsigned int i;
unsigned int j;
int res = CLP_GANG_OKAY;
int tree_lock = 1;
idx = start;
hdr = cl_object_header(obj);
pvec = cl_env_info(env)->clt_pvec;
dtype = cl_object_top(obj)->co_lu.lo_dev->ld_type;
spin_lock(&hdr->coh_page_guard);
while ((nr = radix_tree_gang_lookup(&hdr->coh_tree, (void **)pvec,
idx, CLT_PVEC_SIZE)) > 0) {
int end_of_region = 0;
idx = pvec[nr - 1]->cp_index + 1;
for (i = 0, j = 0; i < nr; ++i) {
page = pvec[i];
pvec[i] = NULL;
LASSERT(page->cp_type == CPT_CACHEABLE);
if (page->cp_index > end) {
end_of_region = 1;
break;
}
if (page->cp_state == CPS_FREEING)
continue;
slice = cl_page_at_trusted(page, dtype);
PASSERT(env, page, slice);
page = slice->cpl_page;
cl_page_get_trust(page);
lu_ref_add_atomic(&page->cp_reference,
"gang_lookup", current);
pvec[j++] = page;
}
spin_unlock(&hdr->coh_page_guard);
tree_lock = 0;
for (i = 0; i < j; ++i) {
page = pvec[i];
if (res == CLP_GANG_OKAY)
res = (*cb)(env, io, page, cbdata);
lu_ref_del(&page->cp_reference,
"gang_lookup", current);
cl_page_put(env, page);
}
if (nr < CLT_PVEC_SIZE || end_of_region)
break;
if (res == CLP_GANG_OKAY && need_resched())
res = CLP_GANG_RESCHED;
if (res != CLP_GANG_OKAY)
break;
spin_lock(&hdr->coh_page_guard);
tree_lock = 1;
}
if (tree_lock)
spin_unlock(&hdr->coh_page_guard);
return res;
}
static void cl_page_free(const struct lu_env *env, struct cl_page *page)
{
struct cl_object *obj = page->cp_obj;
PASSERT(env, page, list_empty(&page->cp_batch));
PASSERT(env, page, !page->cp_owner);
PASSERT(env, page, !page->cp_req);
PASSERT(env, page, !page->cp_parent);
PASSERT(env, page, page->cp_state == CPS_FREEING);
might_sleep();
while (!list_empty(&page->cp_layers)) {
struct cl_page_slice *slice;
slice = list_entry(page->cp_layers.next,
struct cl_page_slice, cpl_linkage);
list_del_init(page->cp_layers.next);
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
static struct cl_page *cl_page_alloc(const struct lu_env *env,
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
if (type == CPT_CACHEABLE)
atomic_inc(&page->cp_ref);
page->cp_obj = o;
cl_object_get(o);
lu_object_ref_add_at(&o->co_lu, &page->cp_obj_ref, "cl_page",
page);
page->cp_index = ind;
cl_page_state_set_trust(page, CPS_CACHED);
page->cp_type = type;
INIT_LIST_HEAD(&page->cp_layers);
INIT_LIST_HEAD(&page->cp_batch);
INIT_LIST_HEAD(&page->cp_flight);
mutex_init(&page->cp_mutex);
lu_ref_init(&page->cp_reference);
head = o->co_lu.lo_header;
list_for_each_entry(o, &head->loh_layers, co_lu.lo_linkage) {
if (o->co_ops->coo_page_init) {
result = o->co_ops->coo_page_init(env, o,
page, vmpage);
if (result != 0) {
cl_page_delete0(env, page, 0);
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
static struct cl_page *cl_page_find0(const struct lu_env *env,
struct cl_object *o,
pgoff_t idx, struct page *vmpage,
enum cl_page_type type,
struct cl_page *parent)
{
struct cl_page *page = NULL;
struct cl_page *ghost = NULL;
struct cl_object_header *hdr;
int err;
LASSERT(type == CPT_CACHEABLE || type == CPT_TRANSIENT);
might_sleep();
hdr = cl_object_header(o);
CDEBUG(D_PAGE, "%lu@"DFID" %p %lx %d\n",
idx, PFID(&hdr->coh_lu.loh_fid), vmpage, vmpage->private, type);
if (type == CPT_CACHEABLE) {
KLASSERT(PageLocked(vmpage));
page = cl_vmpage_page(vmpage, o);
PINVRNT(env, page,
ergo(page,
cl_page_vmpage(env, page) == vmpage &&
(void *)radix_tree_lookup(&hdr->coh_tree,
idx) == page));
}
if (page)
return page;
page = cl_page_alloc(env, o, idx, vmpage, type);
if (IS_ERR(page))
return page;
if (type == CPT_TRANSIENT) {
if (parent) {
LASSERT(!page->cp_parent);
page->cp_parent = parent;
parent->cp_child = page;
}
return page;
}
spin_lock(&hdr->coh_page_guard);
err = radix_tree_insert(&hdr->coh_tree, idx, page);
if (err != 0) {
ghost = page;
page = ERR_PTR(err);
CL_PAGE_DEBUG(D_ERROR, env, ghost,
"fail to insert into radix tree: %d\n", err);
} else {
if (parent) {
LASSERT(!page->cp_parent);
page->cp_parent = parent;
parent->cp_child = page;
}
hdr->coh_pages++;
}
spin_unlock(&hdr->coh_page_guard);
if (unlikely(ghost)) {
cl_page_delete0(env, ghost, 0);
cl_page_free(env, ghost);
}
return page;
}
struct cl_page *cl_page_find(const struct lu_env *env, struct cl_object *o,
pgoff_t idx, struct page *vmpage,
enum cl_page_type type)
{
return cl_page_find0(env, o, idx, vmpage, type, NULL);
}
struct cl_page *cl_page_find_sub(const struct lu_env *env, struct cl_object *o,
pgoff_t idx, struct page *vmpage,
struct cl_page *parent)
{
return cl_page_find0(env, o, idx, vmpage, parent->cp_type, parent);
}
static inline int cl_page_invariant(const struct cl_page *pg)
{
struct cl_object_header *header;
struct cl_page *parent;
struct cl_page *child;
struct cl_io *owner;
LINVRNT(cl_page_is_vmlocked(NULL, pg));
header = cl_object_header(pg->cp_obj);
parent = pg->cp_parent;
child = pg->cp_child;
owner = pg->cp_owner;
return cl_page_in_use(pg) &&
ergo(parent, parent->cp_child == pg) &&
ergo(child, child->cp_parent == pg) &&
ergo(child, pg->cp_obj != child->cp_obj) &&
ergo(parent, pg->cp_obj != parent->cp_obj) &&
ergo(owner && parent,
parent->cp_owner == pg->cp_owner->ci_parent) &&
ergo(owner && child, child->cp_owner->ci_parent == owner) &&
ergo(pg->cp_state < CPS_FREEING && pg->cp_type == CPT_CACHEABLE,
(void *)radix_tree_lookup(&header->coh_tree,
pg->cp_index) == pg ||
(!child && !parent));
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
for (; page; page = page->cp_child) {
PASSERT(env, page, page->cp_state == old);
PASSERT(env, page,
equi(state == CPS_OWNED, page->cp_owner));
cl_page_state_set_trust(page, state);
}
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
PASSERT(env, page, atomic_read(&page->cp_ref) > !!page->cp_parent);
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
struct page *cl_page_vmpage(const struct lu_env *env, struct cl_page *page)
{
const struct cl_page_slice *slice;
page = cl_page_top(page);
do {
list_for_each_entry(slice, &page->cp_layers, cpl_linkage) {
if (slice->cpl_ops->cpo_vmpage)
return slice->cpl_ops->cpo_vmpage(env, slice);
}
page = page->cp_child;
} while (page);
LBUG();
}
struct cl_page *cl_vmpage_page(struct page *vmpage, struct cl_object *obj)
{
struct cl_page *top;
struct cl_page *page;
KLASSERT(PageLocked(vmpage));
top = (struct cl_page *)vmpage->private;
if (!top)
return NULL;
for (page = top; page; page = page->cp_child) {
if (cl_object_same(page->cp_obj, obj)) {
cl_page_get_trust(page);
break;
}
}
LASSERT(ergo(page, page->cp_type == CPT_CACHEABLE));
return page;
}
struct cl_page *cl_page_top(struct cl_page *page)
{
return cl_page_top_trusted(page);
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
for (page = cl_page_top(page); page; page = page->cp_child) {
if (page->cp_owner) {
LASSERT(page->cp_owner->ci_owned_nr > 0);
page->cp_owner->ci_owned_nr--;
page->cp_owner = NULL;
page->cp_task = NULL;
}
}
}
static void cl_page_owner_set(struct cl_page *page)
{
for (page = cl_page_top(page); page; page = page->cp_child)
page->cp_owner->ci_owned_nr++;
}
void cl_page_disown0(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
enum cl_page_state state;
state = pg->cp_state;
PINVRNT(env, pg, state == CPS_OWNED || state == CPS_FREEING);
PINVRNT(env, pg, cl_page_invariant(pg));
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
LINVRNT(cl_object_same(pg->cp_obj, io->ci_obj));
return pg->cp_state == CPS_OWNED && pg->cp_owner == io;
}
static int cl_page_own0(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg, int nonblock)
{
int result;
PINVRNT(env, pg, !cl_page_is_owned(pg, io));
pg = cl_page_top(pg);
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
pg->cp_owner = io;
pg->cp_task = current;
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
pg = cl_page_top(pg);
io = cl_io_top(io);
cl_page_invoid(env, io, pg, CL_PAGE_OP(cpo_assume));
PASSERT(env, pg, !pg->cp_owner);
pg->cp_owner = io;
pg->cp_task = current;
cl_page_owner_set(pg);
cl_page_state_set(env, pg, CPS_OWNED);
}
void cl_page_unassume(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
pg = cl_page_top(pg);
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
PINVRNT(env, pg, cl_page_is_owned(pg, io));
pg = cl_page_top(pg);
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
static void cl_page_delete0(const struct lu_env *env, struct cl_page *pg,
int radix)
{
struct cl_page *tmp = pg;
PASSERT(env, pg, pg == cl_page_top(pg));
PASSERT(env, pg, pg->cp_state != CPS_FREEING);
cl_page_owner_clear(pg);
cl_page_export(env, pg, 0);
cl_page_state_set0(env, pg, CPS_FREEING);
CL_PAGE_INVOID(env, pg, CL_PAGE_OP(cpo_delete),
(const struct lu_env *, const struct cl_page_slice *));
if (tmp->cp_type == CPT_CACHEABLE) {
if (!radix)
tmp = pg->cp_child;
for (; tmp; tmp = tmp->cp_child) {
void *value;
struct cl_object_header *hdr;
hdr = cl_object_header(tmp->cp_obj);
spin_lock(&hdr->coh_page_guard);
value = radix_tree_delete(&hdr->coh_tree,
tmp->cp_index);
PASSERT(env, tmp, value == tmp);
PASSERT(env, tmp, hdr->coh_pages > 0);
hdr->coh_pages--;
spin_unlock(&hdr->coh_page_guard);
cl_page_put(env, tmp);
}
}
}
void cl_page_delete(const struct lu_env *env, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_invariant(pg));
cl_page_delete0(env, pg, 1);
}
int cl_page_unmap(const struct lu_env *env,
struct cl_io *io, struct cl_page *pg)
{
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
return cl_page_invoke(env, io, pg, CL_PAGE_OP(cpo_unmap));
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
pg = cl_page_top_trusted((struct cl_page *)pg);
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
if (crt == CRT_READ && ioret == 0) {
PASSERT(env, pg, !(pg->cp_flags & CPF_READ_COMPLETED));
pg->cp_flags |= CPF_READ_COMPLETED;
}
cl_page_state_set(env, pg, CPS_CACHED);
if (crt >= CRT_NR)
return;
CL_PAGE_INVOID_REVERSE(env, pg, CL_PAGE_OP(io[crt].cpo_completion),
(const struct lu_env *,
const struct cl_page_slice *, int), ioret);
if (anchor) {
LASSERT(cl_page_is_vmlocked(env, pg));
LASSERT(pg->cp_sync_io == anchor);
pg->cp_sync_io = NULL;
}
cl_page_put(env, pg);
if (anchor)
cl_sync_io_note(anchor, ioret);
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
int cl_page_cache_add(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg, enum cl_req_type crt)
{
const struct cl_page_slice *scan;
int result = 0;
PINVRNT(env, pg, crt < CRT_NR);
PINVRNT(env, pg, cl_page_is_owned(pg, io));
PINVRNT(env, pg, cl_page_invariant(pg));
if (crt >= CRT_NR)
return -EINVAL;
list_for_each_entry(scan, &pg->cp_layers, cpl_linkage) {
if (!scan->cpl_ops->io[crt].cpo_cache_add)
continue;
result = scan->cpl_ops->io[crt].cpo_cache_add(env, scan, io);
if (result != 0)
break;
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
struct cl_page *page)
{
int rc;
PINVRNT(env, page, cl_page_invariant(page));
rc = CL_PAGE_INVOKE(env, page, CL_PAGE_OP(cpo_is_under_lock),
(const struct lu_env *,
const struct cl_page_slice *, struct cl_io *),
io);
PASSERT(env, page, rc != 0);
return rc;
}
static int page_prune_cb(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, void *cbdata)
{
cl_page_own(env, io, page);
cl_page_unmap(env, io, page);
cl_page_discard(env, io, page);
cl_page_disown(env, io, page);
return CLP_GANG_OKAY;
}
int cl_pages_prune(const struct lu_env *env, struct cl_object *clobj)
{
struct cl_thread_info *info;
struct cl_object *obj = cl_object_top(clobj);
struct cl_io *io;
int result;
info = cl_env_info(env);
io = &info->clt_io;
io->ci_obj = obj;
io->ci_ignore_layout = 1;
result = cl_io_init(env, io, CIT_MISC, obj);
if (result != 0) {
cl_io_fini(env, io);
return io->ci_result;
}
do {
result = cl_page_gang_lookup(env, obj, io, 0, CL_PAGE_EOF,
page_prune_cb, NULL);
if (result == CLP_GANG_RESCHED)
cond_resched();
} while (result != CLP_GANG_OKAY);
cl_io_fini(env, io);
return result;
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
"page@%p[%d %p:%lu ^%p_%p %d %d %d %p %p %#x]\n",
pg, atomic_read(&pg->cp_ref), pg->cp_obj,
pg->cp_index, pg->cp_parent, pg->cp_child,
pg->cp_state, pg->cp_error, pg->cp_type,
pg->cp_owner, pg->cp_req, pg->cp_flags);
}
void cl_page_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_page *pg)
{
struct cl_page *scan;
for (scan = cl_page_top((struct cl_page *)pg); scan;
scan = scan->cp_child)
cl_page_header_print(env, cookie, printer, scan);
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
int cl_page_size(const struct cl_object *obj)
{
return 1 << PAGE_SHIFT;
}
void cl_page_slice_add(struct cl_page *page, struct cl_page_slice *slice,
struct cl_object *obj,
const struct cl_page_operations *ops)
{
list_add_tail(&slice->cpl_linkage, &page->cp_layers);
slice->cpl_obj = obj;
slice->cpl_ops = ops;
slice->cpl_page = page;
}
int cl_page_init(void)
{
return 0;
}
void cl_page_fini(void)
{
}
