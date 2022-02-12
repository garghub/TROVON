static int osc_page_protected(const struct lu_env *env,
const struct osc_page *opg,
enum cl_lock_mode mode, int unref)
{
return 1;
}
static void osc_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
struct osc_page *opg = cl2osc_page(slice);
CDEBUG(D_TRACE, "%p\n", opg);
LASSERT(opg->ops_lock == NULL);
}
static void osc_page_transfer_get(struct osc_page *opg, const char *label)
{
struct cl_page *page = cl_page_top(opg->ops_cl.cpl_page);
LASSERT(!opg->ops_transfer_pinned);
cl_page_get(page);
lu_ref_add_atomic(&page->cp_reference, label, page);
opg->ops_transfer_pinned = 1;
}
static void osc_page_transfer_put(const struct lu_env *env,
struct osc_page *opg)
{
struct cl_page *page = cl_page_top(opg->ops_cl.cpl_page);
if (opg->ops_transfer_pinned) {
lu_ref_del(&page->cp_reference, "transfer", page);
opg->ops_transfer_pinned = 0;
cl_page_put(env, page);
}
}
static void osc_page_transfer_add(const struct lu_env *env,
struct osc_page *opg, enum cl_req_type crt)
{
struct osc_object *obj = cl2osc(opg->ops_cl.cpl_obj);
osc_lru_del(osc_cli(obj), opg, false);
spin_lock(&obj->oo_seatbelt);
list_add(&opg->ops_inflight, &obj->oo_inflight[crt]);
opg->ops_submitter = current;
spin_unlock(&obj->oo_seatbelt);
}
static int osc_page_cache_add(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io)
{
struct osc_io *oio = osc_env_io(env);
struct osc_page *opg = cl2osc_page(slice);
int result;
LINVRNT(osc_page_protected(env, opg, CLM_WRITE, 0));
osc_page_transfer_get(opg, "transfer\0cache");
result = osc_queue_async_io(env, io, opg);
if (result != 0)
osc_page_transfer_put(env, opg);
else
osc_page_transfer_add(env, opg, CRT_WRITE);
if (cl_io_is_sync_write(io) || cl_io_is_mkwrite(io)) {
if (oio->oi_active != NULL) {
osc_extent_release(env, oio->oi_active);
oio->oi_active = NULL;
}
}
return result;
}
void osc_index2policy(ldlm_policy_data_t *policy, const struct cl_object *obj,
pgoff_t start, pgoff_t end)
{
memset(policy, 0, sizeof(*policy));
policy->l_extent.start = cl_offset(obj, start);
policy->l_extent.end = cl_offset(obj, end + 1) - 1;
}
static int osc_page_addref_lock(const struct lu_env *env,
struct osc_page *opg,
struct cl_lock *lock)
{
struct osc_lock *olock;
int rc;
LASSERT(opg->ops_lock == NULL);
olock = osc_lock_at(lock);
if (atomic_inc_return(&olock->ols_pageref) <= 0) {
atomic_dec(&olock->ols_pageref);
rc = -ENODATA;
} else {
cl_lock_get(lock);
opg->ops_lock = lock;
rc = 0;
}
return rc;
}
static void osc_page_putref_lock(const struct lu_env *env,
struct osc_page *opg)
{
struct cl_lock *lock = opg->ops_lock;
struct osc_lock *olock;
LASSERT(lock != NULL);
olock = osc_lock_at(lock);
atomic_dec(&olock->ols_pageref);
opg->ops_lock = NULL;
cl_lock_put(env, lock);
}
static int osc_page_is_under_lock(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct cl_lock *lock;
int result = -ENODATA;
lock = cl_lock_at_page(env, slice->cpl_obj, slice->cpl_page,
NULL, 1, 0);
if (lock != NULL) {
if (osc_page_addref_lock(env, cl2osc_page(slice), lock) == 0)
result = -EBUSY;
cl_lock_put(env, lock);
}
return result;
}
static void osc_page_disown(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io)
{
struct osc_page *opg = cl2osc_page(slice);
if (unlikely(opg->ops_lock))
osc_page_putref_lock(env, opg);
}
static void osc_page_completion_read(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct osc_page *opg = cl2osc_page(slice);
struct osc_object *obj = cl2osc(opg->ops_cl.cpl_obj);
if (likely(opg->ops_lock))
osc_page_putref_lock(env, opg);
osc_lru_add(osc_cli(obj), opg);
}
static void osc_page_completion_write(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct osc_page *opg = cl2osc_page(slice);
struct osc_object *obj = cl2osc(slice->cpl_obj);
osc_lru_add(osc_cli(obj), opg);
}
static int osc_page_fail(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
LBUG();
return 0;
}
static const char *osc_list(struct list_head *head)
{
return list_empty(head) ? "-" : "+";
}
static inline unsigned long osc_submit_duration(struct osc_page *opg)
{
if (opg->ops_submit_time == 0)
return 0;
return (cfs_time_current() - opg->ops_submit_time);
}
static int osc_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct osc_page *opg = cl2osc_page(slice);
struct osc_async_page *oap = &opg->ops_oap;
struct osc_object *obj = cl2osc(slice->cpl_obj);
struct client_obd *cli = &osc_export(obj)->exp_obd->u.cli;
return (*printer)(env, cookie, LUSTRE_OSC_NAME "-page@%p: 1< %#x %d %u %s %s > 2< %llu %u %u %#x %#x | %p %p %p > 3< %s %p %d %lu %d > 4< %d %d %d %lu %s | %s %s %s %s > 5< %s %s %s %s | %d %s | %d %s %s>\n",
opg,
oap->oap_magic, oap->oap_cmd,
oap->oap_interrupted,
osc_list(&oap->oap_pending_item),
osc_list(&oap->oap_rpc_item),
oap->oap_obj_off, oap->oap_page_off, oap->oap_count,
oap->oap_async_flags, oap->oap_brw_flags,
oap->oap_request, oap->oap_cli, obj,
osc_list(&opg->ops_inflight),
opg->ops_submitter, opg->ops_transfer_pinned,
osc_submit_duration(opg), opg->ops_srvlock,
cli->cl_r_in_flight, cli->cl_w_in_flight,
cli->cl_max_rpcs_in_flight,
cli->cl_avail_grant,
osc_list(&cli->cl_cache_waiters),
osc_list(&cli->cl_loi_ready_list),
osc_list(&cli->cl_loi_hp_ready_list),
osc_list(&cli->cl_loi_write_list),
osc_list(&cli->cl_loi_read_list),
osc_list(&obj->oo_ready_item),
osc_list(&obj->oo_hp_ready_item),
osc_list(&obj->oo_write_item),
osc_list(&obj->oo_read_item),
atomic_read(&obj->oo_nr_reads),
osc_list(&obj->oo_reading_exts),
atomic_read(&obj->oo_nr_writes),
osc_list(&obj->oo_hp_exts),
osc_list(&obj->oo_urgent_exts));
}
static void osc_page_delete(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct osc_page *opg = cl2osc_page(slice);
struct osc_object *obj = cl2osc(opg->ops_cl.cpl_obj);
int rc;
LINVRNT(opg->ops_temp || osc_page_protected(env, opg, CLM_READ, 1));
CDEBUG(D_TRACE, "%p\n", opg);
osc_page_transfer_put(env, opg);
rc = osc_teardown_async_page(env, obj, opg);
if (rc) {
CL_PAGE_DEBUG(D_ERROR, env, cl_page_top(slice->cpl_page),
"Trying to teardown failed: %d\n", rc);
LASSERT(0);
}
spin_lock(&obj->oo_seatbelt);
if (opg->ops_submitter != NULL) {
LASSERT(!list_empty(&opg->ops_inflight));
list_del_init(&opg->ops_inflight);
opg->ops_submitter = NULL;
}
spin_unlock(&obj->oo_seatbelt);
osc_lru_del(osc_cli(obj), opg, true);
}
void osc_page_clip(const struct lu_env *env, const struct cl_page_slice *slice,
int from, int to)
{
struct osc_page *opg = cl2osc_page(slice);
struct osc_async_page *oap = &opg->ops_oap;
LINVRNT(osc_page_protected(env, opg, CLM_READ, 0));
opg->ops_from = from;
opg->ops_to = to;
spin_lock(&oap->oap_lock);
oap->oap_async_flags |= ASYNC_COUNT_STABLE;
spin_unlock(&oap->oap_lock);
}
static int osc_page_cancel(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct osc_page *opg = cl2osc_page(slice);
int rc = 0;
LINVRNT(osc_page_protected(env, opg, CLM_READ, 0));
if (opg->ops_transfer_pinned)
rc = osc_cancel_async_page(env, opg);
LASSERT(ergo(rc == 0, opg->ops_transfer_pinned == 0));
return rc;
}
static int osc_page_flush(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io)
{
struct osc_page *opg = cl2osc_page(slice);
int rc;
rc = osc_flush_async_page(env, io, opg);
return rc;
}
int osc_page_init(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, struct page *vmpage)
{
struct osc_object *osc = cl2osc(obj);
struct osc_page *opg = cl_object_page_slice(obj, page);
int result;
opg->ops_from = 0;
opg->ops_to = PAGE_CACHE_SIZE;
result = osc_prep_async_page(osc, opg, vmpage,
cl_offset(obj, page->cp_index));
if (result == 0) {
struct osc_io *oio = osc_env_io(env);
opg->ops_srvlock = osc_io_srvlock(oio);
cl_page_slice_add(page, &opg->ops_cl, obj,
&osc_page_ops);
}
INIT_LIST_HEAD(&opg->ops_inflight);
INIT_LIST_HEAD(&opg->ops_lru);
if (page->cp_type == CPT_CACHEABLE && result == 0)
result = osc_lru_reserve(env, osc, opg);
return result;
}
void osc_page_submit(const struct lu_env *env, struct osc_page *opg,
enum cl_req_type crt, int brw_flags)
{
struct osc_async_page *oap = &opg->ops_oap;
struct osc_object *obj = oap->oap_obj;
LINVRNT(osc_page_protected(env, opg,
crt == CRT_WRITE ? CLM_WRITE : CLM_READ, 1));
LASSERTF(oap->oap_magic == OAP_MAGIC, "Bad oap magic: oap %p, magic 0x%x\n",
oap, oap->oap_magic);
LASSERT(oap->oap_async_flags & ASYNC_READY);
LASSERT(oap->oap_async_flags & ASYNC_COUNT_STABLE);
oap->oap_cmd = crt == CRT_WRITE ? OBD_BRW_WRITE : OBD_BRW_READ;
oap->oap_page_off = opg->ops_from;
oap->oap_count = opg->ops_to - opg->ops_from;
oap->oap_brw_flags = OBD_BRW_SYNC | brw_flags;
if (!client_is_remote(osc_export(obj)) &&
capable(CFS_CAP_SYS_RESOURCE)) {
oap->oap_brw_flags |= OBD_BRW_NOQUOTA;
oap->oap_cmd |= OBD_BRW_NOQUOTA;
}
opg->ops_submit_time = cfs_time_current();
osc_page_transfer_get(opg, "transfer\0imm");
osc_page_transfer_add(env, opg, crt);
}
static int osc_cache_too_much(struct client_obd *cli)
{
struct cl_client_cache *cache = cli->cl_cache;
int pages = atomic_read(&cli->cl_lru_in_list) >> 1;
if (atomic_read(&osc_lru_waiters) > 0 &&
atomic_read(cli->cl_lru_left) < lru_shrink_max)
return min(pages, lru_shrink_max);
if (atomic_read(cli->cl_lru_left) < cache->ccc_lru_max >> 4) {
unsigned long tmp;
tmp = cache->ccc_lru_max / atomic_read(&cache->ccc_users);
if (pages > tmp)
return min(pages, lru_shrink_max);
return pages > lru_shrink_min ? lru_shrink_min : 0;
}
return 0;
}
static int discard_pagevec(const struct lu_env *env, struct cl_io *io,
struct cl_page **pvec, int max_index)
{
int count;
int i;
for (count = 0, i = 0; i < max_index; i++) {
struct cl_page *page = pvec[i];
if (cl_page_own_try(env, io, page) == 0) {
if (!cl_page_in_use(page)) {
cl_page_unmap(env, io, page);
cl_page_discard(env, io, page);
++count;
}
cl_page_disown(env, io, page);
}
cl_page_put(env, page);
pvec[i] = NULL;
}
return max_index - count;
}
int osc_lru_shrink(struct client_obd *cli, int target)
{
struct cl_env_nest nest;
struct lu_env *env;
struct cl_io *io;
struct cl_object *clobj = NULL;
struct cl_page **pvec;
struct osc_page *opg;
int maxscan = 0;
int count = 0;
int index = 0;
int rc = 0;
LASSERT(atomic_read(&cli->cl_lru_in_list) >= 0);
if (atomic_read(&cli->cl_lru_in_list) == 0 || target <= 0)
return 0;
env = cl_env_nested_get(&nest);
if (IS_ERR(env))
return PTR_ERR(env);
pvec = osc_env_info(env)->oti_pvec;
io = &osc_env_info(env)->oti_io;
client_obd_list_lock(&cli->cl_lru_list_lock);
atomic_inc(&cli->cl_lru_shrinkers);
maxscan = min(target << 1, atomic_read(&cli->cl_lru_in_list));
while (!list_empty(&cli->cl_lru_list)) {
struct cl_page *page;
if (--maxscan < 0)
break;
opg = list_entry(cli->cl_lru_list.next, struct osc_page,
ops_lru);
page = cl_page_top(opg->ops_cl.cpl_page);
if (cl_page_in_use_noref(page)) {
list_move_tail(&opg->ops_lru, &cli->cl_lru_list);
continue;
}
LASSERT(page->cp_obj != NULL);
if (clobj != page->cp_obj) {
struct cl_object *tmp = page->cp_obj;
cl_object_get(tmp);
client_obd_list_unlock(&cli->cl_lru_list_lock);
if (clobj != NULL) {
count -= discard_pagevec(env, io, pvec, index);
index = 0;
cl_io_fini(env, io);
cl_object_put(env, clobj);
clobj = NULL;
}
clobj = tmp;
io->ci_obj = clobj;
io->ci_ignore_layout = 1;
rc = cl_io_init(env, io, CIT_MISC, clobj);
client_obd_list_lock(&cli->cl_lru_list_lock);
if (rc != 0)
break;
++maxscan;
continue;
}
list_move_tail(&opg->ops_lru, &cli->cl_lru_list);
cl_page_get(page);
pvec[index++] = page;
if (++count >= target)
break;
if (unlikely(index == OTI_PVEC_SIZE)) {
client_obd_list_unlock(&cli->cl_lru_list_lock);
count -= discard_pagevec(env, io, pvec, index);
index = 0;
client_obd_list_lock(&cli->cl_lru_list_lock);
}
}
client_obd_list_unlock(&cli->cl_lru_list_lock);
if (clobj != NULL) {
count -= discard_pagevec(env, io, pvec, index);
cl_io_fini(env, io);
cl_object_put(env, clobj);
}
cl_env_nested_put(&nest, env);
atomic_dec(&cli->cl_lru_shrinkers);
return count > 0 ? count : rc;
}
static void osc_lru_add(struct client_obd *cli, struct osc_page *opg)
{
bool wakeup = false;
if (!opg->ops_in_lru)
return;
atomic_dec(&cli->cl_lru_busy);
client_obd_list_lock(&cli->cl_lru_list_lock);
if (list_empty(&opg->ops_lru)) {
list_move_tail(&opg->ops_lru, &cli->cl_lru_list);
atomic_inc_return(&cli->cl_lru_in_list);
wakeup = atomic_read(&osc_lru_waiters) > 0;
}
client_obd_list_unlock(&cli->cl_lru_list_lock);
if (wakeup) {
osc_lru_shrink(cli, osc_cache_too_much(cli));
wake_up_all(&osc_lru_waitq);
}
}
static void osc_lru_del(struct client_obd *cli, struct osc_page *opg, bool del)
{
if (opg->ops_in_lru) {
client_obd_list_lock(&cli->cl_lru_list_lock);
if (!list_empty(&opg->ops_lru)) {
LASSERT(atomic_read(&cli->cl_lru_in_list) > 0);
list_del_init(&opg->ops_lru);
atomic_dec(&cli->cl_lru_in_list);
if (!del)
atomic_inc(&cli->cl_lru_busy);
} else if (del) {
LASSERT(atomic_read(&cli->cl_lru_busy) > 0);
atomic_dec(&cli->cl_lru_busy);
}
client_obd_list_unlock(&cli->cl_lru_list_lock);
if (del) {
atomic_inc(cli->cl_lru_left);
if (atomic_read(&cli->cl_lru_shrinkers) == 0 &&
!memory_pressure_get())
osc_lru_shrink(cli, osc_cache_too_much(cli));
wake_up(&osc_lru_waitq);
}
} else {
LASSERT(list_empty(&opg->ops_lru));
}
}
static inline int max_to_shrink(struct client_obd *cli)
{
return min(atomic_read(&cli->cl_lru_in_list) >> 1, lru_shrink_max);
}
static int osc_lru_reclaim(struct client_obd *cli)
{
struct cl_client_cache *cache = cli->cl_cache;
int max_scans;
int rc;
LASSERT(cache != NULL);
LASSERT(!list_empty(&cache->ccc_lru));
rc = osc_lru_shrink(cli, lru_shrink_min);
if (rc != 0) {
CDEBUG(D_CACHE, "%s: Free %d pages from own LRU: %p.\n",
cli->cl_import->imp_obd->obd_name, rc, cli);
return rc;
}
CDEBUG(D_CACHE, "%s: cli %p no free slots, pages: %d, busy: %d.\n",
cli->cl_import->imp_obd->obd_name, cli,
atomic_read(&cli->cl_lru_in_list),
atomic_read(&cli->cl_lru_busy));
spin_lock(&cache->ccc_lru_lock);
cache->ccc_lru_shrinkers++;
list_move_tail(&cli->cl_lru_osc, &cache->ccc_lru);
max_scans = atomic_read(&cache->ccc_users);
while (--max_scans > 0 && !list_empty(&cache->ccc_lru)) {
cli = list_entry(cache->ccc_lru.next, struct client_obd,
cl_lru_osc);
CDEBUG(D_CACHE, "%s: cli %p LRU pages: %d, busy: %d.\n",
cli->cl_import->imp_obd->obd_name, cli,
atomic_read(&cli->cl_lru_in_list),
atomic_read(&cli->cl_lru_busy));
list_move_tail(&cli->cl_lru_osc, &cache->ccc_lru);
if (atomic_read(&cli->cl_lru_in_list) > 0) {
spin_unlock(&cache->ccc_lru_lock);
rc = osc_lru_shrink(cli, max_to_shrink(cli));
spin_lock(&cache->ccc_lru_lock);
if (rc != 0)
break;
}
}
spin_unlock(&cache->ccc_lru_lock);
CDEBUG(D_CACHE, "%s: cli %p freed %d pages.\n",
cli->cl_import->imp_obd->obd_name, cli, rc);
return rc;
}
static int osc_lru_reserve(const struct lu_env *env, struct osc_object *obj,
struct osc_page *opg)
{
struct l_wait_info lwi = LWI_INTR(LWI_ON_SIGNAL_NOOP, NULL);
struct client_obd *cli = osc_cli(obj);
int rc = 0;
if (cli->cl_cache == NULL)
return 0;
LASSERT(atomic_read(cli->cl_lru_left) >= 0);
while (!atomic_add_unless(cli->cl_lru_left, -1, 0)) {
int gen;
rc = osc_lru_reclaim(cli);
if (rc < 0)
break;
if (rc > 0)
continue;
cond_resched();
atomic_inc(&osc_lru_waiters);
gen = atomic_read(&cli->cl_lru_in_list);
rc = l_wait_event(osc_lru_waitq,
atomic_read(cli->cl_lru_left) > 0 ||
(atomic_read(&cli->cl_lru_in_list) > 0 &&
gen != atomic_read(&cli->cl_lru_in_list)),
&lwi);
atomic_dec(&osc_lru_waiters);
if (rc < 0)
break;
}
if (rc >= 0) {
atomic_inc(&cli->cl_lru_busy);
opg->ops_in_lru = 1;
rc = 0;
}
return rc;
}
