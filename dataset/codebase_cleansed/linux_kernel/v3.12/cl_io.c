static inline int cl_io_type_is_valid(enum cl_io_type type)
{
return CIT_READ <= type && type < CIT_OP_NR;
}
static inline int cl_io_is_loopable(const struct cl_io *io)
{
return cl_io_type_is_valid(io->ci_type) && io->ci_type != CIT_MISC;
}
int cl_io_is_going(const struct lu_env *env)
{
return cl_env_info(env)->clt_current_io != NULL;
}
static int cl_io_invariant(const struct cl_io *io)
{
struct cl_io *up;
up = io->ci_parent;
return
ergo(io->ci_owned_nr > 0, io->ci_state == CIS_IO_GOING ||
(io->ci_state == CIS_LOCKED && up != NULL));
}
void cl_io_fini(const struct lu_env *env, struct cl_io *io)
{
struct cl_io_slice *slice;
struct cl_thread_info *info;
LINVRNT(cl_io_type_is_valid(io->ci_type));
LINVRNT(cl_io_invariant(io));
while (!list_empty(&io->ci_layers)) {
slice = container_of(io->ci_layers.prev, struct cl_io_slice,
cis_linkage);
list_del_init(&slice->cis_linkage);
if (slice->cis_iop->op[io->ci_type].cio_fini != NULL)
slice->cis_iop->op[io->ci_type].cio_fini(env, slice);
slice->cis_io = NULL;
}
io->ci_state = CIS_FINI;
info = cl_env_info(env);
if (info->clt_current_io == io)
info->clt_current_io = NULL;
switch(io->ci_type) {
case CIT_READ:
case CIT_WRITE:
break;
case CIT_FAULT:
case CIT_FSYNC:
LASSERT(!io->ci_need_restart);
break;
case CIT_SETATTR:
case CIT_MISC:
LASSERT(ergo(io->ci_ignore_layout || !io->ci_verify_layout,
!io->ci_need_restart));
break;
default:
LBUG();
}
}
static int cl_io_init0(const struct lu_env *env, struct cl_io *io,
enum cl_io_type iot, struct cl_object *obj)
{
struct cl_object *scan;
int result;
LINVRNT(io->ci_state == CIS_ZERO || io->ci_state == CIS_FINI);
LINVRNT(cl_io_type_is_valid(iot));
LINVRNT(cl_io_invariant(io));
io->ci_type = iot;
INIT_LIST_HEAD(&io->ci_lockset.cls_todo);
INIT_LIST_HEAD(&io->ci_lockset.cls_curr);
INIT_LIST_HEAD(&io->ci_lockset.cls_done);
INIT_LIST_HEAD(&io->ci_layers);
result = 0;
cl_object_for_each(scan, obj) {
if (scan->co_ops->coo_io_init != NULL) {
result = scan->co_ops->coo_io_init(env, scan, io);
if (result != 0)
break;
}
}
if (result == 0)
io->ci_state = CIS_INIT;
return result;
}
int cl_io_sub_init(const struct lu_env *env, struct cl_io *io,
enum cl_io_type iot, struct cl_object *obj)
{
struct cl_thread_info *info = cl_env_info(env);
LASSERT(obj != cl_object_top(obj));
if (info->clt_current_io == NULL)
info->clt_current_io = io;
return cl_io_init0(env, io, iot, obj);
}
int cl_io_init(const struct lu_env *env, struct cl_io *io,
enum cl_io_type iot, struct cl_object *obj)
{
struct cl_thread_info *info = cl_env_info(env);
LASSERT(obj == cl_object_top(obj));
LASSERT(info->clt_current_io == NULL);
info->clt_current_io = io;
return cl_io_init0(env, io, iot, obj);
}
int cl_io_rw_init(const struct lu_env *env, struct cl_io *io,
enum cl_io_type iot, loff_t pos, size_t count)
{
LINVRNT(iot == CIT_READ || iot == CIT_WRITE);
LINVRNT(io->ci_obj != NULL);
LU_OBJECT_HEADER(D_VFSTRACE, env, &io->ci_obj->co_lu,
"io range: %u ["LPU64", "LPU64") %u %u\n",
iot, (__u64)pos, (__u64)pos + count,
io->u.ci_rw.crw_nonblock, io->u.ci_wr.wr_append);
io->u.ci_rw.crw_pos = pos;
io->u.ci_rw.crw_count = count;
return cl_io_init(env, io, iot, io->ci_obj);
}
static inline const struct lu_fid *
cl_lock_descr_fid(const struct cl_lock_descr *descr)
{
return lu_object_fid(&descr->cld_obj->co_lu);
}
static int cl_lock_descr_sort(const struct cl_lock_descr *d0,
const struct cl_lock_descr *d1)
{
return lu_fid_cmp(cl_lock_descr_fid(d0), cl_lock_descr_fid(d1)) ?:
__diff_normalize(d0->cld_start, d1->cld_start);
}
static int cl_lock_descr_cmp(const struct cl_lock_descr *d0,
const struct cl_lock_descr *d1)
{
int ret;
ret = lu_fid_cmp(cl_lock_descr_fid(d0), cl_lock_descr_fid(d1));
if (ret)
return ret;
if (d0->cld_end < d1->cld_start)
return -1;
if (d0->cld_start > d0->cld_end)
return 1;
return 0;
}
static void cl_lock_descr_merge(struct cl_lock_descr *d0,
const struct cl_lock_descr *d1)
{
d0->cld_start = min(d0->cld_start, d1->cld_start);
d0->cld_end = max(d0->cld_end, d1->cld_end);
if (d1->cld_mode == CLM_WRITE && d0->cld_mode != CLM_WRITE)
d0->cld_mode = CLM_WRITE;
if (d1->cld_mode == CLM_GROUP && d0->cld_mode != CLM_GROUP)
d0->cld_mode = CLM_GROUP;
}
static void cl_io_locks_sort(struct cl_io *io)
{
int done = 0;
do {
struct cl_io_lock_link *curr;
struct cl_io_lock_link *prev;
struct cl_io_lock_link *temp;
done = 1;
prev = NULL;
list_for_each_entry_safe(curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if (prev != NULL) {
switch (cl_lock_descr_sort(&prev->cill_descr,
&curr->cill_descr)) {
case 0:
default:
LBUG();
case +1:
list_move_tail(&curr->cill_linkage,
&prev->cill_linkage);
done = 0;
continue;
case -1:
break;
}
}
prev = curr;
}
} while (!done);
}
int cl_queue_match(const struct list_head *queue,
const struct cl_lock_descr *need)
{
struct cl_io_lock_link *scan;
list_for_each_entry(scan, queue, cill_linkage) {
if (cl_lock_descr_match(&scan->cill_descr, need))
return +1;
}
return 0;
}
static int cl_queue_merge(const struct list_head *queue,
const struct cl_lock_descr *need)
{
struct cl_io_lock_link *scan;
list_for_each_entry(scan, queue, cill_linkage) {
if (cl_lock_descr_cmp(&scan->cill_descr, need))
continue;
cl_lock_descr_merge(&scan->cill_descr, need);
CDEBUG(D_VFSTRACE, "lock: %d: [%lu, %lu]\n",
scan->cill_descr.cld_mode, scan->cill_descr.cld_start,
scan->cill_descr.cld_end);
return +1;
}
return 0;
}
static int cl_lockset_match(const struct cl_lockset *set,
const struct cl_lock_descr *need)
{
return cl_queue_match(&set->cls_curr, need) ||
cl_queue_match(&set->cls_done, need);
}
static int cl_lockset_merge(const struct cl_lockset *set,
const struct cl_lock_descr *need)
{
return cl_queue_merge(&set->cls_todo, need) ||
cl_lockset_match(set, need);
}
static int cl_lockset_lock_one(const struct lu_env *env,
struct cl_io *io, struct cl_lockset *set,
struct cl_io_lock_link *link)
{
struct cl_lock *lock;
int result;
lock = cl_lock_request(env, io, &link->cill_descr, "io", io);
if (!IS_ERR(lock)) {
link->cill_lock = lock;
list_move(&link->cill_linkage, &set->cls_curr);
if (!(link->cill_descr.cld_enq_flags & CEF_ASYNC)) {
result = cl_wait(env, lock);
if (result == 0)
list_move(&link->cill_linkage,
&set->cls_done);
} else
result = 0;
} else
result = PTR_ERR(lock);
return result;
}
static void cl_lock_link_fini(const struct lu_env *env, struct cl_io *io,
struct cl_io_lock_link *link)
{
struct cl_lock *lock = link->cill_lock;
list_del_init(&link->cill_linkage);
if (lock != NULL) {
cl_lock_release(env, lock, "io", io);
link->cill_lock = NULL;
}
if (link->cill_fini != NULL)
link->cill_fini(env, link);
}
static int cl_lockset_lock(const struct lu_env *env, struct cl_io *io,
struct cl_lockset *set)
{
struct cl_io_lock_link *link;
struct cl_io_lock_link *temp;
struct cl_lock *lock;
int result;
result = 0;
list_for_each_entry_safe(link, temp, &set->cls_todo, cill_linkage) {
if (!cl_lockset_match(set, &link->cill_descr)) {
result = cl_lockset_lock_one(env, io, set, link);
if (result != 0)
break;
} else
cl_lock_link_fini(env, io, link);
}
if (result == 0) {
list_for_each_entry_safe(link, temp,
&set->cls_curr, cill_linkage) {
lock = link->cill_lock;
result = cl_wait(env, lock);
if (result == 0)
list_move(&link->cill_linkage,
&set->cls_done);
else
break;
}
}
return result;
}
int cl_io_lock(const struct lu_env *env, struct cl_io *io)
{
const struct cl_io_slice *scan;
int result = 0;
LINVRNT(cl_io_is_loopable(io));
LINVRNT(io->ci_state == CIS_IT_STARTED);
LINVRNT(cl_io_invariant(io));
cl_io_for_each(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_lock == NULL)
continue;
result = scan->cis_iop->op[io->ci_type].cio_lock(env, scan);
if (result != 0)
break;
}
if (result == 0) {
cl_io_locks_sort(io);
result = cl_lockset_lock(env, io, &io->ci_lockset);
}
if (result != 0)
cl_io_unlock(env, io);
else
io->ci_state = CIS_LOCKED;
return result;
}
void cl_io_unlock(const struct lu_env *env, struct cl_io *io)
{
struct cl_lockset *set;
struct cl_io_lock_link *link;
struct cl_io_lock_link *temp;
const struct cl_io_slice *scan;
LASSERT(cl_io_is_loopable(io));
LASSERT(CIS_IT_STARTED <= io->ci_state && io->ci_state < CIS_UNLOCKED);
LINVRNT(cl_io_invariant(io));
set = &io->ci_lockset;
list_for_each_entry_safe(link, temp, &set->cls_todo, cill_linkage)
cl_lock_link_fini(env, io, link);
list_for_each_entry_safe(link, temp, &set->cls_curr, cill_linkage)
cl_lock_link_fini(env, io, link);
list_for_each_entry_safe(link, temp, &set->cls_done, cill_linkage) {
cl_unuse(env, link->cill_lock);
cl_lock_link_fini(env, io, link);
}
cl_io_for_each_reverse(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_unlock != NULL)
scan->cis_iop->op[io->ci_type].cio_unlock(env, scan);
}
io->ci_state = CIS_UNLOCKED;
LASSERT(!cl_env_info(env)->clt_counters[CNL_TOP].ctc_nr_locks_acquired);
}
int cl_io_iter_init(const struct lu_env *env, struct cl_io *io)
{
const struct cl_io_slice *scan;
int result;
LINVRNT(cl_io_is_loopable(io));
LINVRNT(io->ci_state == CIS_INIT || io->ci_state == CIS_IT_ENDED);
LINVRNT(cl_io_invariant(io));
result = 0;
cl_io_for_each(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_iter_init == NULL)
continue;
result = scan->cis_iop->op[io->ci_type].cio_iter_init(env,
scan);
if (result != 0)
break;
}
if (result == 0)
io->ci_state = CIS_IT_STARTED;
return result;
}
void cl_io_iter_fini(const struct lu_env *env, struct cl_io *io)
{
const struct cl_io_slice *scan;
LINVRNT(cl_io_is_loopable(io));
LINVRNT(io->ci_state == CIS_UNLOCKED);
LINVRNT(cl_io_invariant(io));
cl_io_for_each_reverse(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_iter_fini != NULL)
scan->cis_iop->op[io->ci_type].cio_iter_fini(env, scan);
}
io->ci_state = CIS_IT_ENDED;
}
void cl_io_rw_advance(const struct lu_env *env, struct cl_io *io, size_t nob)
{
const struct cl_io_slice *scan;
LINVRNT(io->ci_type == CIT_READ || io->ci_type == CIT_WRITE ||
nob == 0);
LINVRNT(cl_io_is_loopable(io));
LINVRNT(cl_io_invariant(io));
io->u.ci_rw.crw_pos += nob;
io->u.ci_rw.crw_count -= nob;
cl_io_for_each_reverse(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_advance != NULL)
scan->cis_iop->op[io->ci_type].cio_advance(env, scan,
nob);
}
}
int cl_io_lock_add(const struct lu_env *env, struct cl_io *io,
struct cl_io_lock_link *link)
{
int result;
if (cl_lockset_merge(&io->ci_lockset, &link->cill_descr))
result = +1;
else {
list_add(&link->cill_linkage, &io->ci_lockset.cls_todo);
result = 0;
}
return result;
}
static void cl_free_io_lock_link(const struct lu_env *env,
struct cl_io_lock_link *link)
{
OBD_FREE_PTR(link);
}
int cl_io_lock_alloc_add(const struct lu_env *env, struct cl_io *io,
struct cl_lock_descr *descr)
{
struct cl_io_lock_link *link;
int result;
OBD_ALLOC_PTR(link);
if (link != NULL) {
link->cill_descr = *descr;
link->cill_fini = cl_free_io_lock_link;
result = cl_io_lock_add(env, io, link);
if (result)
link->cill_fini(env, link);
} else
result = -ENOMEM;
return result;
}
int cl_io_start(const struct lu_env *env, struct cl_io *io)
{
const struct cl_io_slice *scan;
int result = 0;
LINVRNT(cl_io_is_loopable(io));
LINVRNT(io->ci_state == CIS_LOCKED);
LINVRNT(cl_io_invariant(io));
io->ci_state = CIS_IO_GOING;
cl_io_for_each(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_start == NULL)
continue;
result = scan->cis_iop->op[io->ci_type].cio_start(env, scan);
if (result != 0)
break;
}
if (result >= 0)
result = 0;
return result;
}
void cl_io_end(const struct lu_env *env, struct cl_io *io)
{
const struct cl_io_slice *scan;
LINVRNT(cl_io_is_loopable(io));
LINVRNT(io->ci_state == CIS_IO_GOING);
LINVRNT(cl_io_invariant(io));
cl_io_for_each_reverse(scan, io) {
if (scan->cis_iop->op[io->ci_type].cio_end != NULL)
scan->cis_iop->op[io->ci_type].cio_end(env, scan);
}
io->ci_state = CIS_IO_FINISHED;
}
static const struct cl_page_slice *
cl_io_slice_page(const struct cl_io_slice *ios, struct cl_page *page)
{
const struct cl_page_slice *slice;
slice = cl_page_at(page, ios->cis_obj->co_lu.lo_dev->ld_type);
LINVRNT(slice != NULL);
return slice;
}
static int cl_page_in_io(const struct cl_page *page, const struct cl_io *io)
{
int result = 1;
loff_t start;
loff_t end;
pgoff_t idx;
idx = page->cp_index;
switch (io->ci_type) {
case CIT_READ:
case CIT_WRITE:
if (!cl_io_is_append(io)) {
const struct cl_io_rw_common *crw = &(io->u.ci_rw);
start = cl_offset(page->cp_obj, idx);
end = cl_offset(page->cp_obj, idx + 1);
result = crw->crw_pos < end &&
start < crw->crw_pos + crw->crw_count;
}
break;
case CIT_FAULT:
result = io->u.ci_fault.ft_index == idx;
break;
default:
LBUG();
}
return result;
}
int cl_io_read_page(const struct lu_env *env, struct cl_io *io,
struct cl_page *page)
{
const struct cl_io_slice *scan;
struct cl_2queue *queue;
int result = 0;
LINVRNT(io->ci_type == CIT_READ || io->ci_type == CIT_FAULT);
LINVRNT(cl_page_is_owned(page, io));
LINVRNT(io->ci_state == CIS_IO_GOING || io->ci_state == CIS_LOCKED);
LINVRNT(cl_page_in_io(page, io));
LINVRNT(cl_io_invariant(io));
queue = &io->ci_queue;
cl_2queue_init(queue);
cl_io_for_each(scan, io) {
if (scan->cis_iop->cio_read_page != NULL) {
const struct cl_page_slice *slice;
slice = cl_io_slice_page(scan, page);
LINVRNT(slice != NULL);
result = scan->cis_iop->cio_read_page(env, scan, slice);
if (result != 0)
break;
}
}
if (result == 0)
result = cl_io_submit_rw(env, io, CRT_READ, queue);
cl_page_list_disown(env, io, &queue->c2_qin);
cl_2queue_fini(env, queue);
return result;
}
int cl_io_prepare_write(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, unsigned from, unsigned to)
{
const struct cl_io_slice *scan;
int result = 0;
LINVRNT(io->ci_type == CIT_WRITE);
LINVRNT(cl_page_is_owned(page, io));
LINVRNT(io->ci_state == CIS_IO_GOING || io->ci_state == CIS_LOCKED);
LINVRNT(cl_io_invariant(io));
LASSERT(cl_page_in_io(page, io));
cl_io_for_each_reverse(scan, io) {
if (scan->cis_iop->cio_prepare_write != NULL) {
const struct cl_page_slice *slice;
slice = cl_io_slice_page(scan, page);
result = scan->cis_iop->cio_prepare_write(env, scan,
slice,
from, to);
if (result != 0)
break;
}
}
return result;
}
int cl_io_commit_write(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, unsigned from, unsigned to)
{
const struct cl_io_slice *scan;
int result = 0;
LINVRNT(io->ci_type == CIT_WRITE);
LINVRNT(io->ci_state == CIS_IO_GOING || io->ci_state == CIS_LOCKED);
LINVRNT(cl_io_invariant(io));
LASSERT(cl_page_is_owned(page, io) || page->cp_parent != NULL);
LASSERT(cl_page_in_io(page, io));
cl_io_for_each(scan, io) {
if (scan->cis_iop->cio_commit_write != NULL) {
const struct cl_page_slice *slice;
slice = cl_io_slice_page(scan, page);
result = scan->cis_iop->cio_commit_write(env, scan,
slice,
from, to);
if (result != 0)
break;
}
}
LINVRNT(result <= 0);
return result;
}
int cl_io_submit_rw(const struct lu_env *env, struct cl_io *io,
enum cl_req_type crt, struct cl_2queue *queue)
{
const struct cl_io_slice *scan;
int result = 0;
LINVRNT(crt < ARRAY_SIZE(scan->cis_iop->req_op));
cl_io_for_each(scan, io) {
if (scan->cis_iop->req_op[crt].cio_submit == NULL)
continue;
result = scan->cis_iop->req_op[crt].cio_submit(env, scan, crt,
queue);
if (result != 0)
break;
}
LASSERT(ergo(result != 0, list_empty(&queue->c2_qout.pl_pages)));
return result;
}
int cl_io_submit_sync(const struct lu_env *env, struct cl_io *io,
enum cl_req_type iot, struct cl_2queue *queue,
long timeout)
{
struct cl_sync_io *anchor = &cl_env_info(env)->clt_anchor;
struct cl_page *pg;
int rc;
cl_page_list_for_each(pg, &queue->c2_qin) {
LASSERT(pg->cp_sync_io == NULL);
pg->cp_sync_io = anchor;
}
cl_sync_io_init(anchor, queue->c2_qin.pl_nr);
rc = cl_io_submit_rw(env, io, iot, queue);
if (rc == 0) {
cl_page_list_for_each(pg, &queue->c2_qin) {
pg->cp_sync_io = NULL;
cl_sync_io_note(anchor, +1);
}
rc = cl_sync_io_wait(env, io, &queue->c2_qout,
anchor, timeout);
} else {
LASSERT(list_empty(&queue->c2_qout.pl_pages));
cl_page_list_for_each(pg, &queue->c2_qin)
pg->cp_sync_io = NULL;
}
return rc;
}
int cl_io_cancel(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *queue)
{
struct cl_page *page;
int result = 0;
CERROR("Canceling ongoing page trasmission\n");
cl_page_list_for_each(page, queue) {
int rc;
LINVRNT(cl_page_in_io(page, io));
rc = cl_page_cancel(env, page);
result = result ?: rc;
}
return result;
}
int cl_io_loop(const struct lu_env *env, struct cl_io *io)
{
int result = 0;
LINVRNT(cl_io_is_loopable(io));
do {
size_t nob;
io->ci_continue = 0;
result = cl_io_iter_init(env, io);
if (result == 0) {
nob = io->ci_nob;
result = cl_io_lock(env, io);
if (result == 0) {
result = cl_io_start(env, io);
cl_io_end(env, io);
cl_io_unlock(env, io);
cl_io_rw_advance(env, io, io->ci_nob - nob);
}
}
cl_io_iter_fini(env, io);
} while (result == 0 && io->ci_continue);
if (result == 0)
result = io->ci_result;
return result < 0 ? result : 0;
}
void cl_io_slice_add(struct cl_io *io, struct cl_io_slice *slice,
struct cl_object *obj,
const struct cl_io_operations *ops)
{
struct list_head *linkage = &slice->cis_linkage;
LASSERT((linkage->prev == NULL && linkage->next == NULL) ||
list_empty(linkage));
list_add_tail(linkage, &io->ci_layers);
slice->cis_io = io;
slice->cis_obj = obj;
slice->cis_iop = ops;
}
void cl_page_list_init(struct cl_page_list *plist)
{
plist->pl_nr = 0;
INIT_LIST_HEAD(&plist->pl_pages);
plist->pl_owner = current;
}
void cl_page_list_add(struct cl_page_list *plist, struct cl_page *page)
{
LASSERT(page->cp_owner != NULL);
LINVRNT(plist->pl_owner == current);
lockdep_off();
mutex_lock(&page->cp_mutex);
lockdep_on();
LASSERT(list_empty(&page->cp_batch));
list_add_tail(&page->cp_batch, &plist->pl_pages);
++plist->pl_nr;
lu_ref_add_at(&page->cp_reference, &page->cp_queue_ref, "queue", plist);
cl_page_get(page);
}
void cl_page_list_del(const struct lu_env *env,
struct cl_page_list *plist, struct cl_page *page)
{
LASSERT(plist->pl_nr > 0);
LINVRNT(plist->pl_owner == current);
list_del_init(&page->cp_batch);
lockdep_off();
mutex_unlock(&page->cp_mutex);
lockdep_on();
--plist->pl_nr;
lu_ref_del_at(&page->cp_reference, &page->cp_queue_ref, "queue", plist);
cl_page_put(env, page);
}
void cl_page_list_move(struct cl_page_list *dst, struct cl_page_list *src,
struct cl_page *page)
{
LASSERT(src->pl_nr > 0);
LINVRNT(dst->pl_owner == current);
LINVRNT(src->pl_owner == current);
list_move_tail(&page->cp_batch, &dst->pl_pages);
--src->pl_nr;
++dst->pl_nr;
lu_ref_set_at(&page->cp_reference, &page->cp_queue_ref, "queue",
src, dst);
}
void cl_page_list_splice(struct cl_page_list *list, struct cl_page_list *head)
{
struct cl_page *page;
struct cl_page *tmp;
LINVRNT(list->pl_owner == current);
LINVRNT(head->pl_owner == current);
cl_page_list_for_each_safe(page, tmp, list)
cl_page_list_move(head, list, page);
}
void cl_page_list_disown(const struct lu_env *env,
struct cl_io *io, struct cl_page_list *plist)
{
struct cl_page *page;
struct cl_page *temp;
LINVRNT(plist->pl_owner == current);
cl_page_list_for_each_safe(page, temp, plist) {
LASSERT(plist->pl_nr > 0);
list_del_init(&page->cp_batch);
lockdep_off();
mutex_unlock(&page->cp_mutex);
lockdep_on();
--plist->pl_nr;
cl_page_disown0(env, io, page);
lu_ref_del_at(&page->cp_reference, &page->cp_queue_ref, "queue",
plist);
cl_page_put(env, page);
}
}
void cl_page_list_fini(const struct lu_env *env, struct cl_page_list *plist)
{
struct cl_page *page;
struct cl_page *temp;
LINVRNT(plist->pl_owner == current);
cl_page_list_for_each_safe(page, temp, plist)
cl_page_list_del(env, plist, page);
LASSERT(plist->pl_nr == 0);
}
int cl_page_list_own(const struct lu_env *env,
struct cl_io *io, struct cl_page_list *plist)
{
struct cl_page *page;
struct cl_page *temp;
pgoff_t index = 0;
int result;
LINVRNT(plist->pl_owner == current);
result = 0;
cl_page_list_for_each_safe(page, temp, plist) {
LASSERT(index <= page->cp_index);
index = page->cp_index;
if (cl_page_own(env, io, page) == 0)
result = result ?: page->cp_error;
else
cl_page_list_del(env, plist, page);
}
return result;
}
void cl_page_list_assume(const struct lu_env *env,
struct cl_io *io, struct cl_page_list *plist)
{
struct cl_page *page;
LINVRNT(plist->pl_owner == current);
cl_page_list_for_each(page, plist)
cl_page_assume(env, io, page);
}
void cl_page_list_discard(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *plist)
{
struct cl_page *page;
LINVRNT(plist->pl_owner == current);
cl_page_list_for_each(page, plist)
cl_page_discard(env, io, page);
}
int cl_page_list_unmap(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *plist)
{
struct cl_page *page;
int result;
LINVRNT(plist->pl_owner == current);
result = 0;
cl_page_list_for_each(page, plist) {
result = cl_page_unmap(env, io, page);
if (result != 0)
break;
}
return result;
}
void cl_2queue_init(struct cl_2queue *queue)
{
cl_page_list_init(&queue->c2_qin);
cl_page_list_init(&queue->c2_qout);
}
void cl_2queue_add(struct cl_2queue *queue, struct cl_page *page)
{
cl_page_list_add(&queue->c2_qin, page);
}
void cl_2queue_disown(const struct lu_env *env,
struct cl_io *io, struct cl_2queue *queue)
{
cl_page_list_disown(env, io, &queue->c2_qin);
cl_page_list_disown(env, io, &queue->c2_qout);
}
void cl_2queue_discard(const struct lu_env *env,
struct cl_io *io, struct cl_2queue *queue)
{
cl_page_list_discard(env, io, &queue->c2_qin);
cl_page_list_discard(env, io, &queue->c2_qout);
}
void cl_2queue_assume(const struct lu_env *env,
struct cl_io *io, struct cl_2queue *queue)
{
cl_page_list_assume(env, io, &queue->c2_qin);
cl_page_list_assume(env, io, &queue->c2_qout);
}
void cl_2queue_fini(const struct lu_env *env, struct cl_2queue *queue)
{
cl_page_list_fini(env, &queue->c2_qout);
cl_page_list_fini(env, &queue->c2_qin);
}
void cl_2queue_init_page(struct cl_2queue *queue, struct cl_page *page)
{
cl_2queue_init(queue);
cl_2queue_add(queue, page);
}
struct cl_io *cl_io_top(struct cl_io *io)
{
while (io->ci_parent != NULL)
io = io->ci_parent;
return io;
}
void cl_io_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_io *io)
{
}
void cl_req_slice_add(struct cl_req *req, struct cl_req_slice *slice,
struct cl_device *dev,
const struct cl_req_operations *ops)
{
list_add_tail(&slice->crs_linkage, &req->crq_layers);
slice->crs_dev = dev;
slice->crs_ops = ops;
slice->crs_req = req;
}
static void cl_req_free(const struct lu_env *env, struct cl_req *req)
{
unsigned i;
LASSERT(list_empty(&req->crq_pages));
LASSERT(req->crq_nrpages == 0);
LINVRNT(list_empty(&req->crq_layers));
LINVRNT(equi(req->crq_nrobjs > 0, req->crq_o != NULL));
if (req->crq_o != NULL) {
for (i = 0; i < req->crq_nrobjs; ++i) {
struct cl_object *obj = req->crq_o[i].ro_obj;
if (obj != NULL) {
lu_object_ref_del_at(&obj->co_lu,
&req->crq_o[i].ro_obj_ref,
"cl_req", req);
cl_object_put(env, obj);
}
}
OBD_FREE(req->crq_o, req->crq_nrobjs * sizeof req->crq_o[0]);
}
OBD_FREE_PTR(req);
}
static int cl_req_init(const struct lu_env *env, struct cl_req *req,
struct cl_page *page)
{
struct cl_device *dev;
struct cl_page_slice *slice;
int result;
result = 0;
page = cl_page_top(page);
do {
list_for_each_entry(slice, &page->cp_layers, cpl_linkage) {
dev = lu2cl_dev(slice->cpl_obj->co_lu.lo_dev);
if (dev->cd_ops->cdo_req_init != NULL) {
result = dev->cd_ops->cdo_req_init(env,
dev, req);
if (result != 0)
break;
}
}
page = page->cp_child;
} while (page != NULL && result == 0);
return result;
}
void cl_req_completion(const struct lu_env *env, struct cl_req *req, int rc)
{
struct cl_req_slice *slice;
while (!list_empty(&req->crq_layers)) {
slice = list_entry(req->crq_layers.prev,
struct cl_req_slice, crs_linkage);
list_del_init(&slice->crs_linkage);
if (slice->crs_ops->cro_completion != NULL)
slice->crs_ops->cro_completion(env, slice, rc);
}
cl_req_free(env, req);
}
struct cl_req *cl_req_alloc(const struct lu_env *env, struct cl_page *page,
enum cl_req_type crt, int nr_objects)
{
struct cl_req *req;
LINVRNT(nr_objects > 0);
OBD_ALLOC_PTR(req);
if (req != NULL) {
int result;
OBD_ALLOC(req->crq_o, nr_objects * sizeof req->crq_o[0]);
if (req->crq_o != NULL) {
req->crq_nrobjs = nr_objects;
req->crq_type = crt;
INIT_LIST_HEAD(&req->crq_pages);
INIT_LIST_HEAD(&req->crq_layers);
result = cl_req_init(env, req, page);
} else
result = -ENOMEM;
if (result != 0) {
cl_req_completion(env, req, result);
req = ERR_PTR(result);
}
} else
req = ERR_PTR(-ENOMEM);
return req;
}
void cl_req_page_add(const struct lu_env *env,
struct cl_req *req, struct cl_page *page)
{
struct cl_object *obj;
struct cl_req_obj *rqo;
int i;
page = cl_page_top(page);
LASSERT(list_empty(&page->cp_flight));
LASSERT(page->cp_req == NULL);
CL_PAGE_DEBUG(D_PAGE, env, page, "req %p, %d, %u\n",
req, req->crq_type, req->crq_nrpages);
list_add_tail(&page->cp_flight, &req->crq_pages);
++req->crq_nrpages;
page->cp_req = req;
obj = cl_object_top(page->cp_obj);
for (i = 0, rqo = req->crq_o; obj != rqo->ro_obj; ++i, ++rqo) {
if (rqo->ro_obj == NULL) {
rqo->ro_obj = obj;
cl_object_get(obj);
lu_object_ref_add_at(&obj->co_lu, &rqo->ro_obj_ref,
"cl_req", req);
break;
}
}
LASSERT(i < req->crq_nrobjs);
}
void cl_req_page_done(const struct lu_env *env, struct cl_page *page)
{
struct cl_req *req = page->cp_req;
page = cl_page_top(page);
LASSERT(!list_empty(&page->cp_flight));
LASSERT(req->crq_nrpages > 0);
list_del_init(&page->cp_flight);
--req->crq_nrpages;
page->cp_req = NULL;
}
int cl_req_prep(const struct lu_env *env, struct cl_req *req)
{
int i;
int result;
const struct cl_req_slice *slice;
for (i = 0; i < req->crq_nrobjs; ++i)
LASSERT(req->crq_o[i].ro_obj != NULL);
result = 0;
list_for_each_entry(slice, &req->crq_layers, crs_linkage) {
if (slice->crs_ops->cro_prep != NULL) {
result = slice->crs_ops->cro_prep(env, slice);
if (result != 0)
break;
}
}
return result;
}
void cl_req_attr_set(const struct lu_env *env, struct cl_req *req,
struct cl_req_attr *attr, obd_valid flags)
{
const struct cl_req_slice *slice;
struct cl_page *page;
int i;
LASSERT(!list_empty(&req->crq_pages));
page = list_entry(req->crq_pages.next, struct cl_page, cp_flight);
for (i = 0; i < req->crq_nrobjs; ++i) {
list_for_each_entry(slice, &req->crq_layers, crs_linkage) {
const struct cl_page_slice *scan;
const struct cl_object *obj;
scan = cl_page_at(page,
slice->crs_dev->cd_lu_dev.ld_type);
LASSERT(scan != NULL);
obj = scan->cpl_obj;
if (slice->crs_ops->cro_attr_set != NULL)
slice->crs_ops->cro_attr_set(env, slice, obj,
attr + i, flags);
}
}
}
void cl_sync_io_init(struct cl_sync_io *anchor, int nrpages)
{
init_waitqueue_head(&anchor->csi_waitq);
atomic_set(&anchor->csi_sync_nr, nrpages);
atomic_set(&anchor->csi_barrier, nrpages > 0);
anchor->csi_sync_rc = 0;
}
int cl_sync_io_wait(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *queue, struct cl_sync_io *anchor,
long timeout)
{
struct l_wait_info lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(timeout),
NULL, NULL, NULL);
int rc;
LASSERT(timeout >= 0);
rc = l_wait_event(anchor->csi_waitq,
atomic_read(&anchor->csi_sync_nr) == 0,
&lwi);
if (rc < 0) {
CERROR("SYNC IO failed with error: %d, try to cancel "
"%d remaining pages\n",
rc, atomic_read(&anchor->csi_sync_nr));
(void)cl_io_cancel(env, io, queue);
lwi = (struct l_wait_info) { 0 };
(void)l_wait_event(anchor->csi_waitq,
atomic_read(&anchor->csi_sync_nr) == 0,
&lwi);
} else {
rc = anchor->csi_sync_rc;
}
LASSERT(atomic_read(&anchor->csi_sync_nr) == 0);
cl_page_list_assume(env, io, queue);
while (unlikely(atomic_read(&anchor->csi_barrier) != 0)) {
cpu_relax();
}
POISON(anchor, 0x5a, sizeof *anchor);
return rc;
}
void cl_sync_io_note(struct cl_sync_io *anchor, int ioret)
{
if (anchor->csi_sync_rc == 0 && ioret < 0)
anchor->csi_sync_rc = ioret;
LASSERT(atomic_read(&anchor->csi_sync_nr) > 0);
if (atomic_dec_and_test(&anchor->csi_sync_nr)) {
wake_up_all(&anchor->csi_waitq);
atomic_set(&anchor->csi_barrier, 0);
}
}
