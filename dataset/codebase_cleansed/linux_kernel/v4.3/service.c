static struct ptlrpc_request_buffer_desc *
ptlrpc_alloc_rqbd(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_service *svc = svcpt->scp_service;
struct ptlrpc_request_buffer_desc *rqbd;
rqbd = kzalloc_node(sizeof(*rqbd), GFP_NOFS,
cfs_cpt_spread_node(svc->srv_cptable,
svcpt->scp_cpt));
if (rqbd == NULL)
return NULL;
rqbd->rqbd_svcpt = svcpt;
rqbd->rqbd_refcount = 0;
rqbd->rqbd_cbid.cbid_fn = request_in_callback;
rqbd->rqbd_cbid.cbid_arg = rqbd;
INIT_LIST_HEAD(&rqbd->rqbd_reqs);
OBD_CPT_ALLOC_LARGE(rqbd->rqbd_buffer, svc->srv_cptable,
svcpt->scp_cpt, svc->srv_buf_size);
if (rqbd->rqbd_buffer == NULL) {
kfree(rqbd);
return NULL;
}
spin_lock(&svcpt->scp_lock);
list_add(&rqbd->rqbd_list, &svcpt->scp_rqbd_idle);
svcpt->scp_nrqbds_total++;
spin_unlock(&svcpt->scp_lock);
return rqbd;
}
static void
ptlrpc_free_rqbd(struct ptlrpc_request_buffer_desc *rqbd)
{
struct ptlrpc_service_part *svcpt = rqbd->rqbd_svcpt;
LASSERT(rqbd->rqbd_refcount == 0);
LASSERT(list_empty(&rqbd->rqbd_reqs));
spin_lock(&svcpt->scp_lock);
list_del(&rqbd->rqbd_list);
svcpt->scp_nrqbds_total--;
spin_unlock(&svcpt->scp_lock);
kvfree(rqbd->rqbd_buffer);
kfree(rqbd);
}
static int
ptlrpc_grow_req_bufs(struct ptlrpc_service_part *svcpt, int post)
{
struct ptlrpc_service *svc = svcpt->scp_service;
struct ptlrpc_request_buffer_desc *rqbd;
int rc = 0;
int i;
if (svcpt->scp_rqbd_allocating)
goto try_post;
spin_lock(&svcpt->scp_lock);
if (svcpt->scp_rqbd_allocating) {
LASSERT(svcpt->scp_rqbd_allocating == 1);
spin_unlock(&svcpt->scp_lock);
goto try_post;
}
svcpt->scp_rqbd_allocating++;
spin_unlock(&svcpt->scp_lock);
for (i = 0; i < svc->srv_nbuf_per_group; i++) {
if (svcpt->scp_nrqbds_posted >= svc->srv_nbuf_per_group)
break;
rqbd = ptlrpc_alloc_rqbd(svcpt);
if (rqbd == NULL) {
CERROR("%s: Can't allocate request buffer\n",
svc->srv_name);
rc = -ENOMEM;
break;
}
}
spin_lock(&svcpt->scp_lock);
LASSERT(svcpt->scp_rqbd_allocating == 1);
svcpt->scp_rqbd_allocating--;
spin_unlock(&svcpt->scp_lock);
CDEBUG(D_RPCTRACE,
"%s: allocate %d new %d-byte reqbufs (%d/%d left), rc = %d\n",
svc->srv_name, i, svc->srv_buf_size, svcpt->scp_nrqbds_posted,
svcpt->scp_nrqbds_total, rc);
try_post:
if (post && rc == 0)
rc = ptlrpc_server_post_idle_rqbds(svcpt);
return rc;
}
void
ptlrpc_save_lock(struct ptlrpc_request *req,
struct lustre_handle *lock, int mode, int no_ack)
{
struct ptlrpc_reply_state *rs = req->rq_reply_state;
int idx;
LASSERT(rs != NULL);
LASSERT(rs->rs_nlocks < RS_MAX_LOCKS);
if (req->rq_export->exp_disconnected) {
ldlm_lock_decref(lock, mode);
} else {
idx = rs->rs_nlocks++;
rs->rs_locks[idx] = *lock;
rs->rs_modes[idx] = mode;
rs->rs_difficult = 1;
rs->rs_no_ack = !!no_ack;
}
}
static void rs_batch_init(struct rs_batch *b)
{
memset(b, 0, sizeof(*b));
INIT_LIST_HEAD(&b->rsb_replies);
}
static struct ptlrpc_hr_thread *
ptlrpc_hr_select(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_hr_partition *hrp;
unsigned int rotor;
if (svcpt->scp_cpt >= 0 &&
svcpt->scp_service->srv_cptable == ptlrpc_hr.hr_cpt_table) {
hrp = ptlrpc_hr.hr_partitions[svcpt->scp_cpt];
} else {
rotor = ptlrpc_hr.hr_rotor++;
rotor %= cfs_cpt_number(ptlrpc_hr.hr_cpt_table);
hrp = ptlrpc_hr.hr_partitions[rotor];
}
rotor = hrp->hrp_rotor++;
return &hrp->hrp_thrs[rotor % hrp->hrp_nthrs];
}
static void rs_batch_dispatch(struct rs_batch *b)
{
if (b->rsb_n_replies != 0) {
struct ptlrpc_hr_thread *hrt;
hrt = ptlrpc_hr_select(b->rsb_svcpt);
spin_lock(&hrt->hrt_lock);
list_splice_init(&b->rsb_replies, &hrt->hrt_queue);
spin_unlock(&hrt->hrt_lock);
wake_up(&hrt->hrt_waitq);
b->rsb_n_replies = 0;
}
}
static void rs_batch_add(struct rs_batch *b, struct ptlrpc_reply_state *rs)
{
struct ptlrpc_service_part *svcpt = rs->rs_svcpt;
if (svcpt != b->rsb_svcpt || b->rsb_n_replies >= MAX_SCHEDULED) {
if (b->rsb_svcpt != NULL) {
rs_batch_dispatch(b);
spin_unlock(&b->rsb_svcpt->scp_rep_lock);
}
spin_lock(&svcpt->scp_rep_lock);
b->rsb_svcpt = svcpt;
}
spin_lock(&rs->rs_lock);
rs->rs_scheduled_ever = 1;
if (rs->rs_scheduled == 0) {
list_move(&rs->rs_list, &b->rsb_replies);
rs->rs_scheduled = 1;
b->rsb_n_replies++;
}
rs->rs_committed = 1;
spin_unlock(&rs->rs_lock);
}
static void rs_batch_fini(struct rs_batch *b)
{
if (b->rsb_svcpt != NULL) {
rs_batch_dispatch(b);
spin_unlock(&b->rsb_svcpt->scp_rep_lock);
}
}
void ptlrpc_dispatch_difficult_reply(struct ptlrpc_reply_state *rs)
{
struct ptlrpc_hr_thread *hrt;
LASSERT(list_empty(&rs->rs_list));
hrt = ptlrpc_hr_select(rs->rs_svcpt);
spin_lock(&hrt->hrt_lock);
list_add_tail(&rs->rs_list, &hrt->hrt_queue);
spin_unlock(&hrt->hrt_lock);
wake_up(&hrt->hrt_waitq);
}
void
ptlrpc_schedule_difficult_reply(struct ptlrpc_reply_state *rs)
{
assert_spin_locked(&rs->rs_svcpt->scp_rep_lock);
assert_spin_locked(&rs->rs_lock);
LASSERT(rs->rs_difficult);
rs->rs_scheduled_ever = 1;
if (rs->rs_scheduled) {
return;
}
rs->rs_scheduled = 1;
list_del_init(&rs->rs_list);
ptlrpc_dispatch_difficult_reply(rs);
}
void ptlrpc_commit_replies(struct obd_export *exp)
{
struct ptlrpc_reply_state *rs, *nxt;
DECLARE_RS_BATCH(batch);
rs_batch_init(&batch);
spin_lock(&exp->exp_uncommitted_replies_lock);
list_for_each_entry_safe(rs, nxt, &exp->exp_uncommitted_replies,
rs_obd_list) {
LASSERT(rs->rs_difficult);
LASSERT(rs->rs_export);
if (rs->rs_transno <= exp->exp_last_committed) {
list_del_init(&rs->rs_obd_list);
rs_batch_add(&batch, rs);
}
}
spin_unlock(&exp->exp_uncommitted_replies_lock);
rs_batch_fini(&batch);
}
static int
ptlrpc_server_post_idle_rqbds(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_request_buffer_desc *rqbd;
int rc;
int posted = 0;
for (;;) {
spin_lock(&svcpt->scp_lock);
if (list_empty(&svcpt->scp_rqbd_idle)) {
spin_unlock(&svcpt->scp_lock);
return posted;
}
rqbd = list_entry(svcpt->scp_rqbd_idle.next,
struct ptlrpc_request_buffer_desc,
rqbd_list);
list_del(&rqbd->rqbd_list);
svcpt->scp_nrqbds_posted++;
list_add(&rqbd->rqbd_list, &svcpt->scp_rqbd_posted);
spin_unlock(&svcpt->scp_lock);
rc = ptlrpc_register_rqbd(rqbd);
if (rc != 0)
break;
posted = 1;
}
spin_lock(&svcpt->scp_lock);
svcpt->scp_nrqbds_posted--;
list_del(&rqbd->rqbd_list);
list_add_tail(&rqbd->rqbd_list, &svcpt->scp_rqbd_idle);
spin_unlock(&svcpt->scp_lock);
return -1;
}
static void ptlrpc_at_timer(unsigned long castmeharder)
{
struct ptlrpc_service_part *svcpt;
svcpt = (struct ptlrpc_service_part *)castmeharder;
svcpt->scp_at_check = 1;
svcpt->scp_at_checktime = cfs_time_current();
wake_up(&svcpt->scp_waitq);
}
static void
ptlrpc_server_nthreads_check(struct ptlrpc_service *svc,
struct ptlrpc_service_conf *conf)
{
struct ptlrpc_service_thr_conf *tc = &conf->psc_thr;
unsigned init;
unsigned total;
unsigned nthrs;
int weight;
init = PTLRPC_NTHRS_INIT + (svc->srv_ops.so_hpreq_handler != NULL);
init = max_t(int, init, tc->tc_nthrs_init);
LASSERT(tc->tc_nthrs_max != 0);
if (tc->tc_nthrs_user != 0) {
total = min(tc->tc_nthrs_max * 8, tc->tc_nthrs_user);
nthrs = total / svc->srv_ncpts;
init = max(init, nthrs);
goto out;
}
total = tc->tc_nthrs_max;
if (tc->tc_nthrs_base == 0) {
nthrs = total / svc->srv_ncpts;
goto out;
}
nthrs = tc->tc_nthrs_base;
if (svc->srv_ncpts == 1) {
int i;
weight = cfs_cpt_weight(svc->srv_cptable, CFS_CPT_ANY);
for (i = 1; (weight >> (i + 1)) != 0 &&
(tc->tc_nthrs_base >> i) != 0; i++)
nthrs += tc->tc_nthrs_base >> i;
}
if (tc->tc_thr_factor != 0) {
int factor = tc->tc_thr_factor;
const int fade = 4;
if (cpumask_weight(topology_sibling_cpumask(0)) > 1) {
factor = factor - (factor >> 1) + (factor >> 3);
}
weight = cfs_cpt_weight(svc->srv_cptable, 0);
LASSERT(weight > 0);
for (; factor > 0 && weight > 0; factor--, weight -= fade)
nthrs += min(weight, fade) * factor;
}
if (nthrs * svc->srv_ncpts > tc->tc_nthrs_max) {
nthrs = max(tc->tc_nthrs_base,
tc->tc_nthrs_max / svc->srv_ncpts);
}
out:
nthrs = max(nthrs, tc->tc_nthrs_init);
svc->srv_nthrs_cpt_limit = nthrs;
svc->srv_nthrs_cpt_init = init;
if (nthrs * svc->srv_ncpts > tc->tc_nthrs_max) {
CDEBUG(D_OTHER, "%s: This service may have more threads (%d) than the given soft limit (%d)\n",
svc->srv_name, nthrs * svc->srv_ncpts,
tc->tc_nthrs_max);
}
}
static int
ptlrpc_service_part_init(struct ptlrpc_service *svc,
struct ptlrpc_service_part *svcpt, int cpt)
{
struct ptlrpc_at_array *array;
int size;
int index;
int rc;
svcpt->scp_cpt = cpt;
INIT_LIST_HEAD(&svcpt->scp_threads);
spin_lock_init(&svcpt->scp_lock);
INIT_LIST_HEAD(&svcpt->scp_rqbd_idle);
INIT_LIST_HEAD(&svcpt->scp_rqbd_posted);
INIT_LIST_HEAD(&svcpt->scp_req_incoming);
init_waitqueue_head(&svcpt->scp_waitq);
INIT_LIST_HEAD(&svcpt->scp_hist_reqs);
INIT_LIST_HEAD(&svcpt->scp_hist_rqbds);
spin_lock_init(&svcpt->scp_req_lock);
spin_lock_init(&svcpt->scp_rep_lock);
INIT_LIST_HEAD(&svcpt->scp_rep_active);
INIT_LIST_HEAD(&svcpt->scp_rep_idle);
init_waitqueue_head(&svcpt->scp_rep_waitq);
atomic_set(&svcpt->scp_nreps_difficult, 0);
spin_lock_init(&svcpt->scp_at_lock);
array = &svcpt->scp_at_array;
size = at_est2timeout(at_max);
array->paa_size = size;
array->paa_count = 0;
array->paa_deadline = -1;
array->paa_reqs_array =
kzalloc_node(sizeof(struct list_head) * size, GFP_NOFS,
cfs_cpt_spread_node(svc->srv_cptable, cpt));
if (array->paa_reqs_array == NULL)
return -ENOMEM;
for (index = 0; index < size; index++)
INIT_LIST_HEAD(&array->paa_reqs_array[index]);
array->paa_reqs_count =
kzalloc_node(sizeof(__u32) * size, GFP_NOFS,
cfs_cpt_spread_node(svc->srv_cptable, cpt));
if (array->paa_reqs_count == NULL)
goto free_reqs_array;
cfs_timer_init(&svcpt->scp_at_timer, ptlrpc_at_timer, svcpt);
at_init(&svcpt->scp_at_estimate, 10, 0);
svcpt->scp_service = svc;
rc = ptlrpc_grow_req_bufs(svcpt, 0);
if (rc != 0)
goto free_reqs_count;
return 0;
free_reqs_count:
kfree(array->paa_reqs_count);
array->paa_reqs_count = NULL;
free_reqs_array:
kfree(array->paa_reqs_array);
array->paa_reqs_array = NULL;
return -ENOMEM;
}
struct ptlrpc_service *
ptlrpc_register_service(struct ptlrpc_service_conf *conf,
struct kset *parent,
struct dentry *debugfs_entry)
{
struct ptlrpc_service_cpt_conf *cconf = &conf->psc_cpt;
struct ptlrpc_service *service;
struct ptlrpc_service_part *svcpt;
struct cfs_cpt_table *cptable;
__u32 *cpts = NULL;
int ncpts;
int cpt;
int rc;
int i;
LASSERT(conf->psc_buf.bc_nbufs > 0);
LASSERT(conf->psc_buf.bc_buf_size >=
conf->psc_buf.bc_req_max_size + SPTLRPC_MAX_PAYLOAD);
LASSERT(conf->psc_thr.tc_ctx_tags != 0);
cptable = cconf->cc_cptable;
if (cptable == NULL)
cptable = cfs_cpt_table;
if (!conf->psc_thr.tc_cpu_affinity) {
ncpts = 1;
} else {
ncpts = cfs_cpt_number(cptable);
if (cconf->cc_pattern != NULL) {
struct cfs_expr_list *el;
rc = cfs_expr_list_parse(cconf->cc_pattern,
strlen(cconf->cc_pattern),
0, ncpts - 1, &el);
if (rc != 0) {
CERROR("%s: invalid CPT pattern string: %s",
conf->psc_name, cconf->cc_pattern);
return ERR_PTR(-EINVAL);
}
rc = cfs_expr_list_values(el, ncpts, &cpts);
cfs_expr_list_free(el);
if (rc <= 0) {
CERROR("%s: failed to parse CPT array %s: %d\n",
conf->psc_name, cconf->cc_pattern, rc);
kfree(cpts);
return ERR_PTR(rc < 0 ? rc : -EINVAL);
}
ncpts = rc;
}
}
service = kzalloc(offsetof(struct ptlrpc_service, srv_parts[ncpts]),
GFP_NOFS);
if (!service) {
kfree(cpts);
return ERR_PTR(-ENOMEM);
}
service->srv_cptable = cptable;
service->srv_cpts = cpts;
service->srv_ncpts = ncpts;
service->srv_cpt_bits = 0;
while ((1 << service->srv_cpt_bits) < cfs_cpt_number(cptable))
service->srv_cpt_bits++;
spin_lock_init(&service->srv_lock);
service->srv_name = conf->psc_name;
service->srv_watchdog_factor = conf->psc_watchdog_factor;
INIT_LIST_HEAD(&service->srv_list);
service->srv_nbuf_per_group = test_req_buffer_pressure ?
1 : conf->psc_buf.bc_nbufs;
service->srv_max_req_size = conf->psc_buf.bc_req_max_size +
SPTLRPC_MAX_PAYLOAD;
service->srv_buf_size = conf->psc_buf.bc_buf_size;
service->srv_rep_portal = conf->psc_buf.bc_rep_portal;
service->srv_req_portal = conf->psc_buf.bc_req_portal;
service->srv_max_reply_size = 1;
while (service->srv_max_reply_size <
conf->psc_buf.bc_rep_max_size + SPTLRPC_MAX_PAYLOAD)
service->srv_max_reply_size <<= 1;
service->srv_thread_name = conf->psc_thr.tc_thr_name;
service->srv_ctx_tags = conf->psc_thr.tc_ctx_tags;
service->srv_hpreq_ratio = PTLRPC_SVC_HP_RATIO;
service->srv_ops = conf->psc_ops;
for (i = 0; i < ncpts; i++) {
if (!conf->psc_thr.tc_cpu_affinity)
cpt = CFS_CPT_ANY;
else
cpt = cpts != NULL ? cpts[i] : i;
svcpt = kzalloc_node(sizeof(*svcpt), GFP_NOFS,
cfs_cpt_spread_node(cptable, cpt));
if (svcpt == NULL) {
rc = -ENOMEM;
goto failed;
}
service->srv_parts[i] = svcpt;
rc = ptlrpc_service_part_init(service, svcpt, cpt);
if (rc != 0)
goto failed;
}
ptlrpc_server_nthreads_check(service, conf);
rc = LNetSetLazyPortal(service->srv_req_portal);
LASSERT(rc == 0);
mutex_lock(&ptlrpc_all_services_mutex);
list_add(&service->srv_list, &ptlrpc_all_services);
mutex_unlock(&ptlrpc_all_services_mutex);
if (parent) {
rc = ptlrpc_sysfs_register_service(parent, service);
if (rc)
goto failed;
}
if (!IS_ERR_OR_NULL(debugfs_entry))
ptlrpc_ldebugfs_register_service(debugfs_entry, service);
rc = ptlrpc_service_nrs_setup(service);
if (rc != 0)
goto failed;
CDEBUG(D_NET, "%s: Started, listening on portal %d\n",
service->srv_name, service->srv_req_portal);
rc = ptlrpc_start_threads(service);
if (rc != 0) {
CERROR("Failed to start threads for service %s: %d\n",
service->srv_name, rc);
goto failed;
}
return service;
failed:
ptlrpc_unregister_service(service);
return ERR_PTR(rc);
}
static void ptlrpc_server_free_request(struct ptlrpc_request *req)
{
LASSERT(atomic_read(&req->rq_refcount) == 0);
LASSERT(list_empty(&req->rq_timed_list));
ptlrpc_req_drop_rs(req);
sptlrpc_svc_ctx_decref(req);
if (req != &req->rq_rqbd->rqbd_req) {
ptlrpc_request_cache_free(req);
}
}
void ptlrpc_server_drop_request(struct ptlrpc_request *req)
{
struct ptlrpc_request_buffer_desc *rqbd = req->rq_rqbd;
struct ptlrpc_service_part *svcpt = rqbd->rqbd_svcpt;
struct ptlrpc_service *svc = svcpt->scp_service;
int refcount;
struct list_head *tmp;
struct list_head *nxt;
if (!atomic_dec_and_test(&req->rq_refcount))
return;
if (req->rq_at_linked) {
spin_lock(&svcpt->scp_at_lock);
if (likely(req->rq_at_linked))
ptlrpc_at_remove_timed(req);
spin_unlock(&svcpt->scp_at_lock);
}
LASSERT(list_empty(&req->rq_timed_list));
if (req->rq_export) {
class_export_put(req->rq_export);
req->rq_export = NULL;
}
spin_lock(&svcpt->scp_lock);
list_add(&req->rq_list, &rqbd->rqbd_reqs);
refcount = --(rqbd->rqbd_refcount);
if (refcount == 0) {
list_del(&rqbd->rqbd_list);
list_add_tail(&rqbd->rqbd_list, &svcpt->scp_hist_rqbds);
svcpt->scp_hist_nrqbds++;
while (svcpt->scp_hist_nrqbds > svc->srv_hist_nrqbds_cpt_max) {
rqbd = list_entry(svcpt->scp_hist_rqbds.next,
struct ptlrpc_request_buffer_desc,
rqbd_list);
list_del(&rqbd->rqbd_list);
svcpt->scp_hist_nrqbds--;
list_for_each(tmp, &rqbd->rqbd_reqs) {
req = list_entry(tmp, struct ptlrpc_request,
rq_list);
if (req->rq_history_seq >
svcpt->scp_hist_seq_culled) {
svcpt->scp_hist_seq_culled =
req->rq_history_seq;
}
list_del(&req->rq_history_list);
}
spin_unlock(&svcpt->scp_lock);
list_for_each_safe(tmp, nxt, &rqbd->rqbd_reqs) {
req = list_entry(rqbd->rqbd_reqs.next,
struct ptlrpc_request,
rq_list);
list_del(&req->rq_list);
ptlrpc_server_free_request(req);
}
spin_lock(&svcpt->scp_lock);
LASSERT(atomic_read(&rqbd->rqbd_req.rq_refcount) ==
0);
list_add_tail(&rqbd->rqbd_list,
&svcpt->scp_rqbd_idle);
}
spin_unlock(&svcpt->scp_lock);
} else if (req->rq_reply_state && req->rq_reply_state->rs_prealloc) {
list_del(&req->rq_list);
list_del_init(&req->rq_history_list);
if (req->rq_history_seq > svcpt->scp_hist_seq_culled)
svcpt->scp_hist_seq_culled = req->rq_history_seq;
spin_unlock(&svcpt->scp_lock);
ptlrpc_server_free_request(req);
} else {
spin_unlock(&svcpt->scp_lock);
}
}
void ptlrpc_request_change_export(struct ptlrpc_request *req,
struct obd_export *export)
{
if (req->rq_export != NULL) {
if (!list_empty(&req->rq_exp_list)) {
spin_lock_bh(&req->rq_export->exp_rpc_lock);
list_del_init(&req->rq_exp_list);
spin_unlock_bh(&req->rq_export->exp_rpc_lock);
spin_lock_bh(&export->exp_rpc_lock);
list_add(&req->rq_exp_list, &export->exp_hp_rpcs);
spin_unlock_bh(&export->exp_rpc_lock);
}
class_export_rpc_dec(req->rq_export);
class_export_put(req->rq_export);
}
req->rq_export = class_export_get(export);
class_export_rpc_inc(export);
return;
}
static void ptlrpc_server_finish_request(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req)
{
ptlrpc_server_hpreq_fini(req);
ptlrpc_server_drop_request(req);
}
static void ptlrpc_server_finish_active_request(
struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req)
{
spin_lock(&svcpt->scp_req_lock);
ptlrpc_nrs_req_stop_nolock(req);
svcpt->scp_nreqs_active--;
if (req->rq_hp)
svcpt->scp_nhreqs_active--;
spin_unlock(&svcpt->scp_req_lock);
ptlrpc_nrs_req_finalize(req);
if (req->rq_export != NULL)
class_export_rpc_dec(req->rq_export);
ptlrpc_server_finish_request(svcpt, req);
}
static void ptlrpc_update_export_timer(struct obd_export *exp, long extra_delay)
{
struct obd_export *oldest_exp;
time_t oldest_time, new_time;
LASSERT(exp);
new_time = get_seconds() + extra_delay;
if (exp->exp_last_request_time + 1 >= new_time)
return;
exp->exp_last_request_time = new_time;
spin_lock(&exp->exp_obd->obd_dev_lock);
if (list_empty(&exp->exp_obd_chain_timed)) {
spin_unlock(&exp->exp_obd->obd_dev_lock);
return;
}
list_move_tail(&exp->exp_obd_chain_timed,
&exp->exp_obd->obd_exports_timed);
oldest_exp = list_entry(exp->exp_obd->obd_exports_timed.next,
struct obd_export, exp_obd_chain_timed);
oldest_time = oldest_exp->exp_last_request_time;
spin_unlock(&exp->exp_obd->obd_dev_lock);
if (exp->exp_obd->obd_recovering) {
return;
}
if (exp->exp_obd->obd_eviction_timer == 0) {
if (get_seconds() > (oldest_time + PING_EVICT_TIMEOUT +
extra_delay)) {
exp->exp_obd->obd_eviction_timer =
get_seconds() + 3 * PING_INTERVAL;
CDEBUG(D_HA, "%s: Think about evicting %s from "CFS_TIME_T"\n",
exp->exp_obd->obd_name,
obd_export_nid2str(oldest_exp), oldest_time);
}
} else {
if (get_seconds() >
(exp->exp_obd->obd_eviction_timer + extra_delay)) {
if (!ping_evictor_wake(exp))
exp->exp_obd->obd_eviction_timer = 0;
}
}
}
static int ptlrpc_check_req(struct ptlrpc_request *req)
{
struct obd_device *obd = req->rq_export->exp_obd;
int rc = 0;
if (unlikely(lustre_msg_get_conn_cnt(req->rq_reqmsg) <
req->rq_export->exp_conn_cnt)) {
DEBUG_REQ(D_RPCTRACE, req,
"DROPPING req from old connection %d < %d",
lustre_msg_get_conn_cnt(req->rq_reqmsg),
req->rq_export->exp_conn_cnt);
return -EEXIST;
}
if (unlikely(obd == NULL || obd->obd_fail)) {
CDEBUG(D_RPCTRACE, "Dropping req %p for failed obd %s\n",
req, (obd != NULL) ? obd->obd_name : "unknown");
rc = -ENODEV;
} else if (lustre_msg_get_flags(req->rq_reqmsg) &
(MSG_REPLAY | MSG_REQ_REPLAY_DONE) &&
!obd->obd_recovering) {
DEBUG_REQ(D_ERROR, req,
"Invalid replay without recovery");
class_fail_export(req->rq_export);
rc = -ENODEV;
} else if (lustre_msg_get_transno(req->rq_reqmsg) != 0 &&
!obd->obd_recovering) {
DEBUG_REQ(D_ERROR, req, "Invalid req with transno %llu without recovery",
lustre_msg_get_transno(req->rq_reqmsg));
class_fail_export(req->rq_export);
rc = -ENODEV;
}
if (unlikely(rc < 0)) {
req->rq_status = rc;
ptlrpc_error(req);
}
return rc;
}
static void ptlrpc_at_set_timer(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_at_array *array = &svcpt->scp_at_array;
__s32 next;
if (array->paa_count == 0) {
cfs_timer_disarm(&svcpt->scp_at_timer);
return;
}
next = (__s32)(array->paa_deadline - get_seconds() -
at_early_margin);
if (next <= 0) {
ptlrpc_at_timer((unsigned long)svcpt);
} else {
cfs_timer_arm(&svcpt->scp_at_timer, cfs_time_shift(next));
CDEBUG(D_INFO, "armed %s at %+ds\n",
svcpt->scp_service->srv_name, next);
}
}
static int ptlrpc_at_add_timed(struct ptlrpc_request *req)
{
struct ptlrpc_service_part *svcpt = req->rq_rqbd->rqbd_svcpt;
struct ptlrpc_at_array *array = &svcpt->scp_at_array;
struct ptlrpc_request *rq = NULL;
__u32 index;
if (AT_OFF)
return 0;
if (req->rq_no_reply)
return 0;
if ((lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT) == 0)
return -ENOSYS;
spin_lock(&svcpt->scp_at_lock);
LASSERT(list_empty(&req->rq_timed_list));
index = (unsigned long)req->rq_deadline % array->paa_size;
if (array->paa_reqs_count[index] > 0) {
list_for_each_entry_reverse(rq,
&array->paa_reqs_array[index],
rq_timed_list) {
if (req->rq_deadline >= rq->rq_deadline) {
list_add(&req->rq_timed_list,
&rq->rq_timed_list);
break;
}
}
}
if (list_empty(&req->rq_timed_list))
list_add(&req->rq_timed_list,
&array->paa_reqs_array[index]);
spin_lock(&req->rq_lock);
req->rq_at_linked = 1;
spin_unlock(&req->rq_lock);
req->rq_at_index = index;
array->paa_reqs_count[index]++;
array->paa_count++;
if (array->paa_count == 1 || array->paa_deadline > req->rq_deadline) {
array->paa_deadline = req->rq_deadline;
ptlrpc_at_set_timer(svcpt);
}
spin_unlock(&svcpt->scp_at_lock);
return 0;
}
static void
ptlrpc_at_remove_timed(struct ptlrpc_request *req)
{
struct ptlrpc_at_array *array;
array = &req->rq_rqbd->rqbd_svcpt->scp_at_array;
LASSERT(!list_empty(&req->rq_timed_list));
list_del_init(&req->rq_timed_list);
spin_lock(&req->rq_lock);
req->rq_at_linked = 0;
spin_unlock(&req->rq_lock);
array->paa_reqs_count[req->rq_at_index]--;
array->paa_count--;
}
static int ptlrpc_at_send_early_reply(struct ptlrpc_request *req)
{
struct ptlrpc_service_part *svcpt = req->rq_rqbd->rqbd_svcpt;
struct ptlrpc_request *reqcopy;
struct lustre_msg *reqmsg;
long olddl = req->rq_deadline - get_seconds();
time_t newdl;
int rc;
DEBUG_REQ(D_ADAPTTO, req,
"%ssending early reply (deadline %+lds, margin %+lds) for %d+%d",
AT_OFF ? "AT off - not " : "",
olddl, olddl - at_get(&svcpt->scp_at_estimate),
at_get(&svcpt->scp_at_estimate), at_extra);
if (AT_OFF)
return 0;
if (olddl < 0) {
DEBUG_REQ(D_WARNING, req, "Already past deadline (%+lds), not sending early reply. Consider increasing at_early_margin (%d)?",
olddl, at_early_margin);
return -ETIMEDOUT;
}
if (!(lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT)) {
DEBUG_REQ(D_INFO, req, "Wanted to ask client for more time, but no AT support");
return -ENOSYS;
}
if (req->rq_export &&
lustre_msg_get_flags(req->rq_reqmsg) &
(MSG_REPLAY | MSG_REQ_REPLAY_DONE | MSG_LOCK_REPLAY_DONE)) {
at_measured(&svcpt->scp_at_estimate, min(at_extra,
req->rq_export->exp_obd->obd_recovery_timeout / 4));
} else {
at_measured(&svcpt->scp_at_estimate, at_extra +
get_seconds() -
req->rq_arrival_time.tv_sec);
if (req->rq_deadline >= req->rq_arrival_time.tv_sec +
at_get(&svcpt->scp_at_estimate)) {
DEBUG_REQ(D_WARNING, req, "Couldn't add any time (%ld/%ld), not sending early reply\n",
olddl, req->rq_arrival_time.tv_sec +
at_get(&svcpt->scp_at_estimate) -
get_seconds());
return -ETIMEDOUT;
}
}
newdl = get_seconds() + at_get(&svcpt->scp_at_estimate);
reqcopy = ptlrpc_request_cache_alloc(GFP_NOFS);
if (reqcopy == NULL)
return -ENOMEM;
reqmsg = libcfs_kvzalloc(req->rq_reqlen, GFP_NOFS);
if (!reqmsg) {
rc = -ENOMEM;
goto out_free;
}
*reqcopy = *req;
reqcopy->rq_reply_state = NULL;
reqcopy->rq_rep_swab_mask = 0;
reqcopy->rq_pack_bulk = 0;
reqcopy->rq_pack_udesc = 0;
reqcopy->rq_packed_final = 0;
sptlrpc_svc_ctx_addref(reqcopy);
reqcopy->rq_reqmsg = reqmsg;
memcpy(reqmsg, req->rq_reqmsg, req->rq_reqlen);
LASSERT(atomic_read(&req->rq_refcount));
if (atomic_read(&req->rq_refcount) == 1) {
DEBUG_REQ(D_ADAPTTO, reqcopy, "Normal reply already sent out, abort sending early reply\n");
rc = -EINVAL;
goto out;
}
reqcopy->rq_export = class_conn2export(
lustre_msg_get_handle(reqcopy->rq_reqmsg));
if (reqcopy->rq_export == NULL) {
rc = -ENODEV;
goto out;
}
class_export_rpc_inc(reqcopy->rq_export);
if (reqcopy->rq_export->exp_obd &&
reqcopy->rq_export->exp_obd->obd_fail) {
rc = -ENODEV;
goto out_put;
}
rc = lustre_pack_reply_flags(reqcopy, 1, NULL, NULL, LPRFL_EARLY_REPLY);
if (rc)
goto out_put;
rc = ptlrpc_send_reply(reqcopy, PTLRPC_REPLY_EARLY);
if (!rc) {
req->rq_deadline = newdl;
req->rq_early_count++;
} else {
DEBUG_REQ(D_ERROR, req, "Early reply send failed %d", rc);
}
ptlrpc_req_drop_rs(reqcopy);
out_put:
class_export_rpc_dec(reqcopy->rq_export);
class_export_put(reqcopy->rq_export);
out:
sptlrpc_svc_ctx_decref(reqcopy);
kvfree(reqmsg);
out_free:
ptlrpc_request_cache_free(reqcopy);
return rc;
}
static int ptlrpc_at_check_timed(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_at_array *array = &svcpt->scp_at_array;
struct ptlrpc_request *rq, *n;
struct list_head work_list;
__u32 index, count;
time_t deadline;
time_t now = get_seconds();
long delay;
int first, counter = 0;
spin_lock(&svcpt->scp_at_lock);
if (svcpt->scp_at_check == 0) {
spin_unlock(&svcpt->scp_at_lock);
return 0;
}
delay = cfs_time_sub(cfs_time_current(), svcpt->scp_at_checktime);
svcpt->scp_at_check = 0;
if (array->paa_count == 0) {
spin_unlock(&svcpt->scp_at_lock);
return 0;
}
first = array->paa_deadline - now;
if (first > at_early_margin) {
ptlrpc_at_set_timer(svcpt);
spin_unlock(&svcpt->scp_at_lock);
return 0;
}
INIT_LIST_HEAD(&work_list);
deadline = -1;
index = (unsigned long)array->paa_deadline % array->paa_size;
count = array->paa_count;
while (count > 0) {
count -= array->paa_reqs_count[index];
list_for_each_entry_safe(rq, n,
&array->paa_reqs_array[index],
rq_timed_list) {
if (rq->rq_deadline > now + at_early_margin) {
if (deadline == -1 ||
rq->rq_deadline < deadline)
deadline = rq->rq_deadline;
break;
}
ptlrpc_at_remove_timed(rq);
if (likely(atomic_inc_not_zero(&rq->rq_refcount)))
list_add(&rq->rq_timed_list, &work_list);
counter++;
}
if (++index >= array->paa_size)
index = 0;
}
array->paa_deadline = deadline;
ptlrpc_at_set_timer(svcpt);
spin_unlock(&svcpt->scp_at_lock);
CDEBUG(D_ADAPTTO, "timeout in %+ds, asking for %d secs on %d early replies\n",
first, at_extra, counter);
if (first < 0) {
LCONSOLE_WARN("%s: This server is not able to keep up with request traffic (cpu-bound).\n",
svcpt->scp_service->srv_name);
CWARN("earlyQ=%d reqQ=%d recA=%d, svcEst=%d, delay=" CFS_DURATION_T "(jiff)\n",
counter, svcpt->scp_nreqs_incoming,
svcpt->scp_nreqs_active,
at_get(&svcpt->scp_at_estimate), delay);
}
while (!list_empty(&work_list)) {
rq = list_entry(work_list.next, struct ptlrpc_request,
rq_timed_list);
list_del_init(&rq->rq_timed_list);
if (ptlrpc_at_send_early_reply(rq) == 0)
ptlrpc_at_add_timed(rq);
ptlrpc_server_drop_request(rq);
}
return 1;
}
static int ptlrpc_server_hpreq_init(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req)
{
int rc = 0;
if (svcpt->scp_service->srv_ops.so_hpreq_handler) {
rc = svcpt->scp_service->srv_ops.so_hpreq_handler(req);
if (rc < 0)
return rc;
LASSERT(rc == 0);
}
if (req->rq_export && req->rq_ops) {
if (req->rq_ops->hpreq_check) {
rc = req->rq_ops->hpreq_check(req);
if (rc < 0)
return rc;
LASSERT(rc == 0 || rc == 1);
}
spin_lock_bh(&req->rq_export->exp_rpc_lock);
list_add(&req->rq_exp_list,
&req->rq_export->exp_hp_rpcs);
spin_unlock_bh(&req->rq_export->exp_rpc_lock);
}
ptlrpc_nrs_req_initialize(svcpt, req, rc);
return rc;
}
static void ptlrpc_server_hpreq_fini(struct ptlrpc_request *req)
{
if (req->rq_export && req->rq_ops) {
if (req->rq_ops->hpreq_fini)
req->rq_ops->hpreq_fini(req);
spin_lock_bh(&req->rq_export->exp_rpc_lock);
list_del_init(&req->rq_exp_list);
spin_unlock_bh(&req->rq_export->exp_rpc_lock);
}
}
static int ptlrpc_hpreq_check(struct ptlrpc_request *req)
{
return 1;
}
int ptlrpc_hpreq_handler(struct ptlrpc_request *req)
{
int opc = lustre_msg_get_opc(req->rq_reqmsg);
if ((req->rq_export != NULL) &&
(opc == OBD_PING || opc == MDS_CONNECT || opc == OST_CONNECT))
req->rq_ops = &ptlrpc_hpreq_common;
return 0;
}
static int ptlrpc_server_request_add(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req)
{
int rc;
rc = ptlrpc_server_hpreq_init(svcpt, req);
if (rc < 0)
return rc;
ptlrpc_nrs_req_add(svcpt, req, !!rc);
return 0;
}
static bool ptlrpc_server_allow_high(struct ptlrpc_service_part *svcpt,
bool force)
{
int running = svcpt->scp_nthrs_running;
if (!nrs_svcpt_has_hp(svcpt))
return false;
if (force)
return true;
if (unlikely(svcpt->scp_service->srv_req_portal == MDS_REQUEST_PORTAL &&
CFS_FAIL_PRECHECK(OBD_FAIL_PTLRPC_CANCEL_RESEND))) {
running = PTLRPC_NTHRS_INIT;
if (svcpt->scp_service->srv_ops.so_hpreq_handler != NULL)
running += 1;
}
if (svcpt->scp_nreqs_active >= running - 1)
return false;
if (svcpt->scp_nhreqs_active == 0)
return true;
return !ptlrpc_nrs_req_pending_nolock(svcpt, false) ||
svcpt->scp_hreq_count < svcpt->scp_service->srv_hpreq_ratio;
}
static bool ptlrpc_server_high_pending(struct ptlrpc_service_part *svcpt,
bool force)
{
return ptlrpc_server_allow_high(svcpt, force) &&
ptlrpc_nrs_req_pending_nolock(svcpt, true);
}
static bool ptlrpc_server_allow_normal(struct ptlrpc_service_part *svcpt,
bool force)
{
int running = svcpt->scp_nthrs_running;
if (unlikely(svcpt->scp_service->srv_req_portal == MDS_REQUEST_PORTAL &&
CFS_FAIL_PRECHECK(OBD_FAIL_PTLRPC_CANCEL_RESEND))) {
running = PTLRPC_NTHRS_INIT;
if (svcpt->scp_service->srv_ops.so_hpreq_handler != NULL)
running += 1;
}
if (force ||
svcpt->scp_nreqs_active < running - 2)
return true;
if (svcpt->scp_nreqs_active >= running - 1)
return false;
return svcpt->scp_nhreqs_active > 0 || !nrs_svcpt_has_hp(svcpt);
}
static bool ptlrpc_server_normal_pending(struct ptlrpc_service_part *svcpt,
bool force)
{
return ptlrpc_server_allow_normal(svcpt, force) &&
ptlrpc_nrs_req_pending_nolock(svcpt, false);
}
static inline bool
ptlrpc_server_request_pending(struct ptlrpc_service_part *svcpt, bool force)
{
return ptlrpc_server_high_pending(svcpt, force) ||
ptlrpc_server_normal_pending(svcpt, force);
}
static struct ptlrpc_request *
ptlrpc_server_request_get(struct ptlrpc_service_part *svcpt, bool force)
{
struct ptlrpc_request *req = NULL;
spin_lock(&svcpt->scp_req_lock);
if (ptlrpc_server_high_pending(svcpt, force)) {
req = ptlrpc_nrs_req_get_nolock(svcpt, true, force);
if (req != NULL) {
svcpt->scp_hreq_count++;
goto got_request;
}
}
if (ptlrpc_server_normal_pending(svcpt, force)) {
req = ptlrpc_nrs_req_get_nolock(svcpt, false, force);
if (req != NULL) {
svcpt->scp_hreq_count = 0;
goto got_request;
}
}
spin_unlock(&svcpt->scp_req_lock);
return NULL;
got_request:
svcpt->scp_nreqs_active++;
if (req->rq_hp)
svcpt->scp_nhreqs_active++;
spin_unlock(&svcpt->scp_req_lock);
if (likely(req->rq_export))
class_export_rpc_inc(req->rq_export);
return req;
}
static int
ptlrpc_server_handle_req_in(struct ptlrpc_service_part *svcpt,
struct ptlrpc_thread *thread)
{
struct ptlrpc_service *svc = svcpt->scp_service;
struct ptlrpc_request *req;
__u32 deadline;
int rc;
spin_lock(&svcpt->scp_lock);
if (list_empty(&svcpt->scp_req_incoming)) {
spin_unlock(&svcpt->scp_lock);
return 0;
}
req = list_entry(svcpt->scp_req_incoming.next,
struct ptlrpc_request, rq_list);
list_del_init(&req->rq_list);
svcpt->scp_nreqs_incoming--;
spin_unlock(&svcpt->scp_lock);
rc = sptlrpc_svc_unwrap_request(req);
switch (rc) {
case SECSVC_OK:
break;
case SECSVC_COMPLETE:
target_send_reply(req, 0, OBD_FAIL_MDS_ALL_REPLY_NET);
goto err_req;
case SECSVC_DROP:
goto err_req;
default:
LBUG();
}
if (SPTLRPC_FLVR_POLICY(req->rq_flvr.sf_rpc) != SPTLRPC_POLICY_NULL) {
rc = ptlrpc_unpack_req_msg(req, req->rq_reqlen);
if (rc != 0) {
CERROR("error unpacking request: ptl %d from %s x%llu\n",
svc->srv_req_portal, libcfs_id2str(req->rq_peer),
req->rq_xid);
goto err_req;
}
}
rc = lustre_unpack_req_ptlrpc_body(req, MSG_PTLRPC_BODY_OFF);
if (rc) {
CERROR("error unpacking ptlrpc body: ptl %d from %s x%llu\n",
svc->srv_req_portal, libcfs_id2str(req->rq_peer),
req->rq_xid);
goto err_req;
}
if (OBD_FAIL_CHECK(OBD_FAIL_PTLRPC_DROP_REQ_OPC) &&
lustre_msg_get_opc(req->rq_reqmsg) == cfs_fail_val) {
CERROR("drop incoming rpc opc %u, x%llu\n",
cfs_fail_val, req->rq_xid);
goto err_req;
}
rc = -EINVAL;
if (lustre_msg_get_type(req->rq_reqmsg) != PTL_RPC_MSG_REQUEST) {
CERROR("wrong packet type received (type=%u) from %s\n",
lustre_msg_get_type(req->rq_reqmsg),
libcfs_id2str(req->rq_peer));
goto err_req;
}
switch (lustre_msg_get_opc(req->rq_reqmsg)) {
case MDS_WRITEPAGE:
case OST_WRITE:
req->rq_bulk_write = 1;
break;
case MDS_READPAGE:
case OST_READ:
case MGS_CONFIG_READ:
req->rq_bulk_read = 1;
break;
}
CDEBUG(D_RPCTRACE, "got req x%llu\n", req->rq_xid);
req->rq_export = class_conn2export(
lustre_msg_get_handle(req->rq_reqmsg));
if (req->rq_export) {
rc = ptlrpc_check_req(req);
if (rc == 0) {
rc = sptlrpc_target_export_check(req->rq_export, req);
if (rc)
DEBUG_REQ(D_ERROR, req, "DROPPING req with illegal security flavor,");
}
if (rc)
goto err_req;
ptlrpc_update_export_timer(req->rq_export, 0);
}
if (get_seconds() - req->rq_arrival_time.tv_sec > 5)
DEBUG_REQ(D_WARNING, req, "Slow req_in handling "CFS_DURATION_T"s",
cfs_time_sub(get_seconds(),
req->rq_arrival_time.tv_sec));
deadline = (lustre_msghdr_get_flags(req->rq_reqmsg) &
MSGHDR_AT_SUPPORT) ?
lustre_msg_get_timeout(req->rq_reqmsg) : obd_timeout;
req->rq_deadline = req->rq_arrival_time.tv_sec + deadline;
if (unlikely(deadline == 0)) {
DEBUG_REQ(D_ERROR, req, "Dropping request with 0 timeout");
goto err_req;
}
req->rq_svc_thread = thread;
ptlrpc_at_add_timed(req);
rc = ptlrpc_server_request_add(svcpt, req);
if (rc)
goto err_req;
wake_up(&svcpt->scp_waitq);
return 1;
err_req:
ptlrpc_server_finish_request(svcpt, req);
return 1;
}
static int
ptlrpc_server_handle_request(struct ptlrpc_service_part *svcpt,
struct ptlrpc_thread *thread)
{
struct ptlrpc_service *svc = svcpt->scp_service;
struct ptlrpc_request *request;
struct timeval work_start;
struct timeval work_end;
long timediff;
int rc;
int fail_opc = 0;
request = ptlrpc_server_request_get(svcpt, false);
if (request == NULL)
return 0;
if (OBD_FAIL_CHECK(OBD_FAIL_PTLRPC_HPREQ_NOTIMEOUT))
fail_opc = OBD_FAIL_PTLRPC_HPREQ_NOTIMEOUT;
else if (OBD_FAIL_CHECK(OBD_FAIL_PTLRPC_HPREQ_TIMEOUT))
fail_opc = OBD_FAIL_PTLRPC_HPREQ_TIMEOUT;
if (unlikely(fail_opc)) {
if (request->rq_export && request->rq_ops)
OBD_FAIL_TIMEOUT(fail_opc, 4);
}
ptlrpc_rqphase_move(request, RQ_PHASE_INTERPRET);
if (OBD_FAIL_CHECK(OBD_FAIL_PTLRPC_DUMP_LOG))
libcfs_debug_dumplog();
do_gettimeofday(&work_start);
timediff = cfs_timeval_sub(&work_start, &request->rq_arrival_time,
NULL);
if (likely(svc->srv_stats != NULL)) {
lprocfs_counter_add(svc->srv_stats, PTLRPC_REQWAIT_CNTR,
timediff);
lprocfs_counter_add(svc->srv_stats, PTLRPC_REQQDEPTH_CNTR,
svcpt->scp_nreqs_incoming);
lprocfs_counter_add(svc->srv_stats, PTLRPC_REQACTIVE_CNTR,
svcpt->scp_nreqs_active);
lprocfs_counter_add(svc->srv_stats, PTLRPC_TIMEOUT,
at_get(&svcpt->scp_at_estimate));
}
rc = lu_context_init(&request->rq_session, LCT_SESSION | LCT_NOREF);
if (rc) {
CERROR("Failure to initialize session: %d\n", rc);
goto out_req;
}
request->rq_session.lc_thread = thread;
request->rq_session.lc_cookie = 0x5;
lu_context_enter(&request->rq_session);
CDEBUG(D_NET, "got req %llu\n", request->rq_xid);
request->rq_svc_thread = thread;
if (thread)
request->rq_svc_thread->t_env->le_ses = &request->rq_session;
if (likely(request->rq_export)) {
if (unlikely(ptlrpc_check_req(request)))
goto put_conn;
ptlrpc_update_export_timer(request->rq_export, timediff >> 19);
}
if (get_seconds() > request->rq_deadline) {
DEBUG_REQ(D_ERROR, request, "Dropping timed-out request from %s: deadline " CFS_DURATION_T ":" CFS_DURATION_T "s ago\n",
libcfs_id2str(request->rq_peer),
cfs_time_sub(request->rq_deadline,
request->rq_arrival_time.tv_sec),
cfs_time_sub(get_seconds(),
request->rq_deadline));
goto put_conn;
}
CDEBUG(D_RPCTRACE, "Handling RPC pname:cluuid+ref:pid:xid:nid:opc %s:%s+%d:%d:x%llu:%s:%d\n",
current_comm(),
(request->rq_export ?
(char *)request->rq_export->exp_client_uuid.uuid : "0"),
(request->rq_export ?
atomic_read(&request->rq_export->exp_refcount) : -99),
lustre_msg_get_status(request->rq_reqmsg), request->rq_xid,
libcfs_id2str(request->rq_peer),
lustre_msg_get_opc(request->rq_reqmsg));
if (lustre_msg_get_opc(request->rq_reqmsg) != OBD_PING)
CFS_FAIL_TIMEOUT_MS(OBD_FAIL_PTLRPC_PAUSE_REQ, cfs_fail_val);
rc = svc->srv_ops.so_req_handler(request);
ptlrpc_rqphase_move(request, RQ_PHASE_COMPLETE);
put_conn:
lu_context_exit(&request->rq_session);
lu_context_fini(&request->rq_session);
if (unlikely(get_seconds() > request->rq_deadline)) {
DEBUG_REQ(D_WARNING, request,
"Request took longer than estimated ("
CFS_DURATION_T":"CFS_DURATION_T
"s); client may timeout.",
cfs_time_sub(request->rq_deadline,
request->rq_arrival_time.tv_sec),
cfs_time_sub(get_seconds(),
request->rq_deadline));
}
do_gettimeofday(&work_end);
timediff = cfs_timeval_sub(&work_end, &work_start, NULL);
CDEBUG(D_RPCTRACE, "Handled RPC pname:cluuid+ref:pid:xid:nid:opc %s:%s+%d:%d:x%llu:%s:%d Request processed in %ldus (%ldus total) trans %llu rc %d/%d\n",
current_comm(),
(request->rq_export ?
(char *)request->rq_export->exp_client_uuid.uuid : "0"),
(request->rq_export ?
atomic_read(&request->rq_export->exp_refcount) : -99),
lustre_msg_get_status(request->rq_reqmsg),
request->rq_xid,
libcfs_id2str(request->rq_peer),
lustre_msg_get_opc(request->rq_reqmsg),
timediff,
cfs_timeval_sub(&work_end, &request->rq_arrival_time, NULL),
(request->rq_repmsg ?
lustre_msg_get_transno(request->rq_repmsg) :
request->rq_transno),
request->rq_status,
(request->rq_repmsg ?
lustre_msg_get_status(request->rq_repmsg) : -999));
if (likely(svc->srv_stats != NULL && request->rq_reqmsg != NULL)) {
__u32 op = lustre_msg_get_opc(request->rq_reqmsg);
int opc = opcode_offset(op);
if (opc > 0 && !(op == LDLM_ENQUEUE || op == MDS_REINT)) {
LASSERT(opc < LUSTRE_MAX_OPCODES);
lprocfs_counter_add(svc->srv_stats,
opc + EXTRA_MAX_OPCODES,
timediff);
}
}
if (unlikely(request->rq_early_count)) {
DEBUG_REQ(D_ADAPTTO, request,
"sent %d early replies before finishing in "
CFS_DURATION_T"s",
request->rq_early_count,
cfs_time_sub(work_end.tv_sec,
request->rq_arrival_time.tv_sec));
}
out_req:
ptlrpc_server_finish_active_request(svcpt, request);
return 1;
}
static int
ptlrpc_handle_rs(struct ptlrpc_reply_state *rs)
{
struct ptlrpc_service_part *svcpt = rs->rs_svcpt;
struct ptlrpc_service *svc = svcpt->scp_service;
struct obd_export *exp;
int nlocks;
int been_handled;
exp = rs->rs_export;
LASSERT(rs->rs_difficult);
LASSERT(rs->rs_scheduled);
LASSERT(list_empty(&rs->rs_list));
spin_lock(&exp->exp_lock);
list_del_init(&rs->rs_exp_list);
spin_unlock(&exp->exp_lock);
if (!rs->rs_committed) {
spin_lock(&exp->exp_uncommitted_replies_lock);
list_del_init(&rs->rs_obd_list);
spin_unlock(&exp->exp_uncommitted_replies_lock);
}
spin_lock(&rs->rs_lock);
been_handled = rs->rs_handled;
rs->rs_handled = 1;
nlocks = rs->rs_nlocks;
rs->rs_nlocks = 0;
if (nlocks == 0 && !been_handled) {
CDEBUG(D_HA, "All locks stolen from rs %p x%lld.t%lld o%d NID %s\n",
rs,
rs->rs_xid, rs->rs_transno, rs->rs_opc,
libcfs_nid2str(exp->exp_connection->c_peer.nid));
}
if ((!been_handled && rs->rs_on_net) || nlocks > 0) {
spin_unlock(&rs->rs_lock);
if (!been_handled && rs->rs_on_net) {
LNetMDUnlink(rs->rs_md_h);
}
while (nlocks-- > 0)
ldlm_lock_decref(&rs->rs_locks[nlocks],
rs->rs_modes[nlocks]);
spin_lock(&rs->rs_lock);
}
rs->rs_scheduled = 0;
if (!rs->rs_on_net) {
spin_unlock(&rs->rs_lock);
class_export_put(exp);
rs->rs_export = NULL;
ptlrpc_rs_decref(rs);
if (atomic_dec_and_test(&svcpt->scp_nreps_difficult) &&
svc->srv_is_stopping)
wake_up_all(&svcpt->scp_waitq);
return 1;
}
spin_unlock(&rs->rs_lock);
return 1;
}
static void
ptlrpc_check_rqbd_pool(struct ptlrpc_service_part *svcpt)
{
int avail = svcpt->scp_nrqbds_posted;
int low_water = test_req_buffer_pressure ? 0 :
svcpt->scp_service->srv_nbuf_per_group / 2;
if (avail <= low_water)
ptlrpc_grow_req_bufs(svcpt, 1);
if (svcpt->scp_service->srv_stats) {
lprocfs_counter_add(svcpt->scp_service->srv_stats,
PTLRPC_REQBUF_AVAIL_CNTR, avail);
}
}
static int
ptlrpc_retry_rqbds(void *arg)
{
struct ptlrpc_service_part *svcpt = (struct ptlrpc_service_part *)arg;
svcpt->scp_rqbd_timeout = 0;
return -ETIMEDOUT;
}
static inline int
ptlrpc_threads_enough(struct ptlrpc_service_part *svcpt)
{
return svcpt->scp_nreqs_active <
svcpt->scp_nthrs_running - 1 -
(svcpt->scp_service->srv_ops.so_hpreq_handler != NULL);
}
static inline int
ptlrpc_threads_increasable(struct ptlrpc_service_part *svcpt)
{
return svcpt->scp_nthrs_running +
svcpt->scp_nthrs_starting <
svcpt->scp_service->srv_nthrs_cpt_limit;
}
static inline int
ptlrpc_threads_need_create(struct ptlrpc_service_part *svcpt)
{
return !ptlrpc_threads_enough(svcpt) &&
ptlrpc_threads_increasable(svcpt);
}
static inline int
ptlrpc_thread_stopping(struct ptlrpc_thread *thread)
{
return thread_is_stopping(thread) ||
thread->t_svcpt->scp_service->srv_is_stopping;
}
static inline int
ptlrpc_rqbd_pending(struct ptlrpc_service_part *svcpt)
{
return !list_empty(&svcpt->scp_rqbd_idle) &&
svcpt->scp_rqbd_timeout == 0;
}
static inline int
ptlrpc_at_check(struct ptlrpc_service_part *svcpt)
{
return svcpt->scp_at_check;
}
static inline int
ptlrpc_server_request_incoming(struct ptlrpc_service_part *svcpt)
{
return !list_empty(&svcpt->scp_req_incoming);
}
int ptlrpc_main(void *arg)
{
struct ptlrpc_thread *thread = (struct ptlrpc_thread *)arg;
struct ptlrpc_service_part *svcpt = thread->t_svcpt;
struct ptlrpc_service *svc = svcpt->scp_service;
struct ptlrpc_reply_state *rs;
struct group_info *ginfo = NULL;
struct lu_env *env;
int counter = 0, rc = 0;
thread->t_pid = current_pid();
unshare_fs_struct();
rc = cfs_cpt_bind(svc->srv_cptable, svcpt->scp_cpt);
if (rc != 0) {
CWARN("%s: failed to bind %s on CPT %d\n",
svc->srv_name, thread->t_name, svcpt->scp_cpt);
}
ginfo = groups_alloc(0);
if (!ginfo) {
rc = -ENOMEM;
goto out;
}
set_current_groups(ginfo);
put_group_info(ginfo);
if (svc->srv_ops.so_thr_init != NULL) {
rc = svc->srv_ops.so_thr_init(thread);
if (rc)
goto out;
}
env = kzalloc(sizeof(*env), GFP_NOFS);
if (!env) {
rc = -ENOMEM;
goto out_srv_fini;
}
rc = lu_context_init(&env->le_ctx,
svc->srv_ctx_tags|LCT_REMEMBER|LCT_NOREF);
if (rc)
goto out_srv_fini;
thread->t_env = env;
env->le_ctx.lc_thread = thread;
env->le_ctx.lc_cookie = 0x6;
while (!list_empty(&svcpt->scp_rqbd_idle)) {
rc = ptlrpc_server_post_idle_rqbds(svcpt);
if (rc >= 0)
continue;
CERROR("Failed to post rqbd for %s on CPT %d: %d\n",
svc->srv_name, svcpt->scp_cpt, rc);
goto out_srv_fini;
}
rs = libcfs_kvzalloc(svc->srv_max_reply_size, GFP_NOFS);
if (!rs) {
rc = -ENOMEM;
goto out_srv_fini;
}
spin_lock(&svcpt->scp_lock);
LASSERT(thread_is_starting(thread));
thread_clear_flags(thread, SVC_STARTING);
LASSERT(svcpt->scp_nthrs_starting == 1);
svcpt->scp_nthrs_starting--;
thread_add_flags(thread, SVC_RUNNING);
svcpt->scp_nthrs_running++;
spin_unlock(&svcpt->scp_lock);
wake_up(&thread->t_ctl_waitq);
spin_lock(&svcpt->scp_rep_lock);
list_add(&rs->rs_list, &svcpt->scp_rep_idle);
wake_up(&svcpt->scp_rep_waitq);
spin_unlock(&svcpt->scp_rep_lock);
CDEBUG(D_NET, "service thread %d (#%d) started\n", thread->t_id,
svcpt->scp_nthrs_running);
while (!ptlrpc_thread_stopping(thread)) {
if (ptlrpc_wait_event(svcpt, thread))
break;
ptlrpc_check_rqbd_pool(svcpt);
if (ptlrpc_threads_need_create(svcpt)) {
ptlrpc_start_thread(svcpt, 0);
}
if (ptlrpc_server_request_incoming(svcpt)) {
lu_context_enter(&env->le_ctx);
env->le_ses = NULL;
ptlrpc_server_handle_req_in(svcpt, thread);
lu_context_exit(&env->le_ctx);
if (counter++ < 100)
continue;
counter = 0;
}
if (ptlrpc_at_check(svcpt))
ptlrpc_at_check_timed(svcpt);
if (ptlrpc_server_request_pending(svcpt, false)) {
lu_context_enter(&env->le_ctx);
ptlrpc_server_handle_request(svcpt, thread);
lu_context_exit(&env->le_ctx);
}
if (ptlrpc_rqbd_pending(svcpt) &&
ptlrpc_server_post_idle_rqbds(svcpt) < 0) {
svcpt->scp_rqbd_timeout = cfs_time_seconds(1) / 10;
CDEBUG(D_RPCTRACE, "Posted buffers: %d\n",
svcpt->scp_nrqbds_posted);
}
}
out_srv_fini:
if (svc->srv_ops.so_thr_done != NULL)
svc->srv_ops.so_thr_done(thread);
if (env != NULL) {
lu_context_fini(&env->le_ctx);
kfree(env);
}
out:
CDEBUG(D_RPCTRACE, "service thread [ %p : %u ] %d exiting: rc %d\n",
thread, thread->t_pid, thread->t_id, rc);
spin_lock(&svcpt->scp_lock);
if (thread_test_and_clear_flags(thread, SVC_STARTING))
svcpt->scp_nthrs_starting--;
if (thread_test_and_clear_flags(thread, SVC_RUNNING)) {
svcpt->scp_nthrs_running--;
}
thread->t_id = rc;
thread_add_flags(thread, SVC_STOPPED);
wake_up(&thread->t_ctl_waitq);
spin_unlock(&svcpt->scp_lock);
return rc;
}
static int hrt_dont_sleep(struct ptlrpc_hr_thread *hrt,
struct list_head *replies)
{
int result;
spin_lock(&hrt->hrt_lock);
list_splice_init(&hrt->hrt_queue, replies);
result = ptlrpc_hr.hr_stopping || !list_empty(replies);
spin_unlock(&hrt->hrt_lock);
return result;
}
static int ptlrpc_hr_main(void *arg)
{
struct ptlrpc_hr_thread *hrt = (struct ptlrpc_hr_thread *)arg;
struct ptlrpc_hr_partition *hrp = hrt->hrt_partition;
LIST_HEAD (replies);
char threadname[20];
int rc;
snprintf(threadname, sizeof(threadname), "ptlrpc_hr%02d_%03d",
hrp->hrp_cpt, hrt->hrt_id);
unshare_fs_struct();
rc = cfs_cpt_bind(ptlrpc_hr.hr_cpt_table, hrp->hrp_cpt);
if (rc != 0) {
CWARN("Failed to bind %s on CPT %d of CPT table %p: rc = %d\n",
threadname, hrp->hrp_cpt, ptlrpc_hr.hr_cpt_table, rc);
}
atomic_inc(&hrp->hrp_nstarted);
wake_up(&ptlrpc_hr.hr_waitq);
while (!ptlrpc_hr.hr_stopping) {
l_wait_condition(hrt->hrt_waitq, hrt_dont_sleep(hrt, &replies));
while (!list_empty(&replies)) {
struct ptlrpc_reply_state *rs;
rs = list_entry(replies.prev,
struct ptlrpc_reply_state,
rs_list);
list_del_init(&rs->rs_list);
ptlrpc_handle_rs(rs);
}
}
atomic_inc(&hrp->hrp_nstopped);
wake_up(&ptlrpc_hr.hr_waitq);
return 0;
}
static void ptlrpc_stop_hr_threads(void)
{
struct ptlrpc_hr_partition *hrp;
int i;
int j;
ptlrpc_hr.hr_stopping = 1;
cfs_percpt_for_each(hrp, i, ptlrpc_hr.hr_partitions) {
if (hrp->hrp_thrs == NULL)
continue;
for (j = 0; j < hrp->hrp_nthrs; j++)
wake_up_all(&hrp->hrp_thrs[j].hrt_waitq);
}
cfs_percpt_for_each(hrp, i, ptlrpc_hr.hr_partitions) {
if (hrp->hrp_thrs == NULL)
continue;
wait_event(ptlrpc_hr.hr_waitq,
atomic_read(&hrp->hrp_nstopped) ==
atomic_read(&hrp->hrp_nstarted));
}
}
static int ptlrpc_start_hr_threads(void)
{
struct ptlrpc_hr_partition *hrp;
int i;
int j;
cfs_percpt_for_each(hrp, i, ptlrpc_hr.hr_partitions) {
int rc = 0;
for (j = 0; j < hrp->hrp_nthrs; j++) {
struct ptlrpc_hr_thread *hrt = &hrp->hrp_thrs[j];
rc = PTR_ERR(kthread_run(ptlrpc_hr_main,
&hrp->hrp_thrs[j],
"ptlrpc_hr%02d_%03d",
hrp->hrp_cpt,
hrt->hrt_id));
if (IS_ERR_VALUE(rc))
break;
}
wait_event(ptlrpc_hr.hr_waitq,
atomic_read(&hrp->hrp_nstarted) == j);
if (!IS_ERR_VALUE(rc))
continue;
CERROR("Reply handling thread %d:%d Failed on starting: rc = %d\n",
i, j, rc);
ptlrpc_stop_hr_threads();
return rc;
}
return 0;
}
static void ptlrpc_svcpt_stop_threads(struct ptlrpc_service_part *svcpt)
{
struct l_wait_info lwi = { 0 };
struct ptlrpc_thread *thread;
LIST_HEAD (zombie);
CDEBUG(D_INFO, "Stopping threads for service %s\n",
svcpt->scp_service->srv_name);
spin_lock(&svcpt->scp_lock);
list_for_each_entry(thread, &svcpt->scp_threads, t_link) {
CDEBUG(D_INFO, "Stopping thread %s #%u\n",
svcpt->scp_service->srv_thread_name, thread->t_id);
thread_add_flags(thread, SVC_STOPPING);
}
wake_up_all(&svcpt->scp_waitq);
while (!list_empty(&svcpt->scp_threads)) {
thread = list_entry(svcpt->scp_threads.next,
struct ptlrpc_thread, t_link);
if (thread_is_stopped(thread)) {
list_del(&thread->t_link);
list_add(&thread->t_link, &zombie);
continue;
}
spin_unlock(&svcpt->scp_lock);
CDEBUG(D_INFO, "waiting for stopping-thread %s #%u\n",
svcpt->scp_service->srv_thread_name, thread->t_id);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopped(thread), &lwi);
spin_lock(&svcpt->scp_lock);
}
spin_unlock(&svcpt->scp_lock);
while (!list_empty(&zombie)) {
thread = list_entry(zombie.next,
struct ptlrpc_thread, t_link);
list_del(&thread->t_link);
kfree(thread);
}
}
void ptlrpc_stop_all_threads(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service != NULL)
ptlrpc_svcpt_stop_threads(svcpt);
}
}
int ptlrpc_start_threads(struct ptlrpc_service *svc)
{
int rc = 0;
int i;
int j;
LASSERT(svc->srv_nthrs_cpt_init >= PTLRPC_NTHRS_INIT);
for (i = 0; i < svc->srv_ncpts; i++) {
for (j = 0; j < svc->srv_nthrs_cpt_init; j++) {
rc = ptlrpc_start_thread(svc->srv_parts[i], 1);
if (rc == 0)
continue;
if (rc != -EMFILE)
goto failed;
break;
}
}
return 0;
failed:
CERROR("cannot start %s thread #%d_%d: rc %d\n",
svc->srv_thread_name, i, j, rc);
ptlrpc_stop_all_threads(svc);
return rc;
}
int ptlrpc_start_thread(struct ptlrpc_service_part *svcpt, int wait)
{
struct l_wait_info lwi = { 0 };
struct ptlrpc_thread *thread;
struct ptlrpc_service *svc;
int rc;
LASSERT(svcpt != NULL);
svc = svcpt->scp_service;
CDEBUG(D_RPCTRACE, "%s[%d] started %d min %d max %d\n",
svc->srv_name, svcpt->scp_cpt, svcpt->scp_nthrs_running,
svc->srv_nthrs_cpt_init, svc->srv_nthrs_cpt_limit);
again:
if (unlikely(svc->srv_is_stopping))
return -ESRCH;
if (!ptlrpc_threads_increasable(svcpt) ||
(OBD_FAIL_CHECK(OBD_FAIL_TGT_TOOMANY_THREADS) &&
svcpt->scp_nthrs_running == svc->srv_nthrs_cpt_init - 1))
return -EMFILE;
thread = kzalloc_node(sizeof(*thread), GFP_NOFS,
cfs_cpt_spread_node(svc->srv_cptable,
svcpt->scp_cpt));
if (thread == NULL)
return -ENOMEM;
init_waitqueue_head(&thread->t_ctl_waitq);
spin_lock(&svcpt->scp_lock);
if (!ptlrpc_threads_increasable(svcpt)) {
spin_unlock(&svcpt->scp_lock);
kfree(thread);
return -EMFILE;
}
if (svcpt->scp_nthrs_starting != 0) {
LASSERT(svcpt->scp_nthrs_starting == 1);
spin_unlock(&svcpt->scp_lock);
kfree(thread);
if (wait) {
CDEBUG(D_INFO, "Waiting for creating thread %s #%d\n",
svc->srv_thread_name, svcpt->scp_thr_nextid);
schedule();
goto again;
}
CDEBUG(D_INFO, "Creating thread %s #%d race, retry later\n",
svc->srv_thread_name, svcpt->scp_thr_nextid);
return -EAGAIN;
}
svcpt->scp_nthrs_starting++;
thread->t_id = svcpt->scp_thr_nextid++;
thread_add_flags(thread, SVC_STARTING);
thread->t_svcpt = svcpt;
list_add(&thread->t_link, &svcpt->scp_threads);
spin_unlock(&svcpt->scp_lock);
if (svcpt->scp_cpt >= 0) {
snprintf(thread->t_name, sizeof(thread->t_name), "%s%02d_%03d",
svc->srv_thread_name, svcpt->scp_cpt, thread->t_id);
} else {
snprintf(thread->t_name, sizeof(thread->t_name), "%s_%04d",
svc->srv_thread_name, thread->t_id);
}
CDEBUG(D_RPCTRACE, "starting thread '%s'\n", thread->t_name);
rc = PTR_ERR(kthread_run(ptlrpc_main, thread, "%s", thread->t_name));
if (IS_ERR_VALUE(rc)) {
CERROR("cannot start thread '%s': rc %d\n",
thread->t_name, rc);
spin_lock(&svcpt->scp_lock);
--svcpt->scp_nthrs_starting;
if (thread_is_stopping(thread)) {
thread_add_flags(thread, SVC_STOPPED);
wake_up(&thread->t_ctl_waitq);
spin_unlock(&svcpt->scp_lock);
} else {
list_del(&thread->t_link);
spin_unlock(&svcpt->scp_lock);
kfree(thread);
}
return rc;
}
if (!wait)
return 0;
l_wait_event(thread->t_ctl_waitq,
thread_is_running(thread) || thread_is_stopped(thread),
&lwi);
rc = thread_is_stopped(thread) ? thread->t_id : 0;
return rc;
}
int ptlrpc_hr_init(void)
{
struct ptlrpc_hr_partition *hrp;
struct ptlrpc_hr_thread *hrt;
int rc;
int i;
int j;
int weight;
memset(&ptlrpc_hr, 0, sizeof(ptlrpc_hr));
ptlrpc_hr.hr_cpt_table = cfs_cpt_table;
ptlrpc_hr.hr_partitions = cfs_percpt_alloc(ptlrpc_hr.hr_cpt_table,
sizeof(*hrp));
if (ptlrpc_hr.hr_partitions == NULL)
return -ENOMEM;
init_waitqueue_head(&ptlrpc_hr.hr_waitq);
weight = cpumask_weight(topology_sibling_cpumask(0));
cfs_percpt_for_each(hrp, i, ptlrpc_hr.hr_partitions) {
hrp->hrp_cpt = i;
atomic_set(&hrp->hrp_nstarted, 0);
atomic_set(&hrp->hrp_nstopped, 0);
hrp->hrp_nthrs = cfs_cpt_weight(ptlrpc_hr.hr_cpt_table, i);
hrp->hrp_nthrs /= weight;
LASSERT(hrp->hrp_nthrs > 0);
hrp->hrp_thrs =
kzalloc_node(hrp->hrp_nthrs * sizeof(*hrt), GFP_NOFS,
cfs_cpt_spread_node(ptlrpc_hr.hr_cpt_table,
i));
if (hrp->hrp_thrs == NULL) {
rc = -ENOMEM;
goto out;
}
for (j = 0; j < hrp->hrp_nthrs; j++) {
hrt = &hrp->hrp_thrs[j];
hrt->hrt_id = j;
hrt->hrt_partition = hrp;
init_waitqueue_head(&hrt->hrt_waitq);
spin_lock_init(&hrt->hrt_lock);
INIT_LIST_HEAD(&hrt->hrt_queue);
}
}
rc = ptlrpc_start_hr_threads();
out:
if (rc != 0)
ptlrpc_hr_fini();
return rc;
}
void ptlrpc_hr_fini(void)
{
struct ptlrpc_hr_partition *hrp;
int i;
if (ptlrpc_hr.hr_partitions == NULL)
return;
ptlrpc_stop_hr_threads();
cfs_percpt_for_each(hrp, i, ptlrpc_hr.hr_partitions) {
kfree(hrp->hrp_thrs);
}
cfs_percpt_free(ptlrpc_hr.hr_partitions);
ptlrpc_hr.hr_partitions = NULL;
}
static void ptlrpc_wait_replies(struct ptlrpc_service_part *svcpt)
{
while (1) {
int rc;
struct l_wait_info lwi = LWI_TIMEOUT(cfs_time_seconds(10),
NULL, NULL);
rc = l_wait_event(svcpt->scp_waitq,
atomic_read(&svcpt->scp_nreps_difficult) == 0, &lwi);
if (rc == 0)
break;
CWARN("Unexpectedly long timeout %s %p\n",
svcpt->scp_service->srv_name, svcpt->scp_service);
}
}
static void
ptlrpc_service_del_atimer(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service != NULL)
cfs_timer_disarm(&svcpt->scp_at_timer);
}
}
static void
ptlrpc_service_unlink_rqbd(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
struct ptlrpc_request_buffer_desc *rqbd;
struct l_wait_info lwi;
int rc;
int i;
svc->srv_hist_nrqbds_cpt_max = 0;
rc = LNetClearLazyPortal(svc->srv_req_portal);
LASSERT(rc == 0);
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service == NULL)
break;
list_for_each_entry(rqbd, &svcpt->scp_rqbd_posted,
rqbd_list) {
rc = LNetMDUnlink(rqbd->rqbd_md_h);
LASSERT(rc == 0 || rc == -ENOENT);
}
}
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service == NULL)
break;
spin_lock(&svcpt->scp_lock);
while (svcpt->scp_nrqbds_posted != 0) {
spin_unlock(&svcpt->scp_lock);
lwi = LWI_TIMEOUT_INTERVAL(
cfs_time_seconds(LONG_UNLINK),
cfs_time_seconds(1), NULL, NULL);
rc = l_wait_event(svcpt->scp_waitq,
svcpt->scp_nrqbds_posted == 0, &lwi);
if (rc == -ETIMEDOUT) {
CWARN("Service %s waiting for request buffers\n",
svcpt->scp_service->srv_name);
}
spin_lock(&svcpt->scp_lock);
}
spin_unlock(&svcpt->scp_lock);
}
}
static void
ptlrpc_service_purge_all(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
struct ptlrpc_request_buffer_desc *rqbd;
struct ptlrpc_request *req;
struct ptlrpc_reply_state *rs;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service == NULL)
break;
spin_lock(&svcpt->scp_rep_lock);
while (!list_empty(&svcpt->scp_rep_active)) {
rs = list_entry(svcpt->scp_rep_active.next,
struct ptlrpc_reply_state, rs_list);
spin_lock(&rs->rs_lock);
ptlrpc_schedule_difficult_reply(rs);
spin_unlock(&rs->rs_lock);
}
spin_unlock(&svcpt->scp_rep_lock);
while (!list_empty(&svcpt->scp_req_incoming)) {
req = list_entry(svcpt->scp_req_incoming.next,
struct ptlrpc_request, rq_list);
list_del(&req->rq_list);
svcpt->scp_nreqs_incoming--;
ptlrpc_server_finish_request(svcpt, req);
}
while (ptlrpc_server_request_pending(svcpt, true)) {
req = ptlrpc_server_request_get(svcpt, true);
ptlrpc_server_finish_active_request(svcpt, req);
}
LASSERT(list_empty(&svcpt->scp_rqbd_posted));
LASSERT(svcpt->scp_nreqs_incoming == 0);
LASSERT(svcpt->scp_nreqs_active == 0);
LASSERT(svcpt->scp_hist_nrqbds == 0);
while (!list_empty(&svcpt->scp_rqbd_idle)) {
rqbd = list_entry(svcpt->scp_rqbd_idle.next,
struct ptlrpc_request_buffer_desc,
rqbd_list);
ptlrpc_free_rqbd(rqbd);
}
ptlrpc_wait_replies(svcpt);
while (!list_empty(&svcpt->scp_rep_idle)) {
rs = list_entry(svcpt->scp_rep_idle.next,
struct ptlrpc_reply_state,
rs_list);
list_del(&rs->rs_list);
kvfree(rs);
}
}
}
static void
ptlrpc_service_free(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
struct ptlrpc_at_array *array;
int i;
ptlrpc_service_for_each_part(svcpt, i, svc) {
if (svcpt->scp_service == NULL)
break;
cfs_timer_disarm(&svcpt->scp_at_timer);
array = &svcpt->scp_at_array;
kfree(array->paa_reqs_array);
array->paa_reqs_array = NULL;
kfree(array->paa_reqs_count);
array->paa_reqs_count = NULL;
}
ptlrpc_service_for_each_part(svcpt, i, svc)
kfree(svcpt);
if (svc->srv_cpts != NULL)
cfs_expr_list_values_free(svc->srv_cpts, svc->srv_ncpts);
kfree(svc);
}
int ptlrpc_unregister_service(struct ptlrpc_service *service)
{
CDEBUG(D_NET, "%s: tearing down\n", service->srv_name);
service->srv_is_stopping = 1;
mutex_lock(&ptlrpc_all_services_mutex);
list_del_init(&service->srv_list);
mutex_unlock(&ptlrpc_all_services_mutex);
ptlrpc_service_del_atimer(service);
ptlrpc_stop_all_threads(service);
ptlrpc_service_unlink_rqbd(service);
ptlrpc_service_purge_all(service);
ptlrpc_service_nrs_cleanup(service);
ptlrpc_lprocfs_unregister_service(service);
ptlrpc_sysfs_unregister_service(service);
ptlrpc_service_free(service);
return 0;
}
static int ptlrpc_svcpt_health_check(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_request *request = NULL;
struct timeval right_now;
long timediff;
do_gettimeofday(&right_now);
spin_lock(&svcpt->scp_req_lock);
if (ptlrpc_server_high_pending(svcpt, true))
request = ptlrpc_nrs_req_peek_nolock(svcpt, true);
else if (ptlrpc_server_normal_pending(svcpt, true))
request = ptlrpc_nrs_req_peek_nolock(svcpt, false);
if (request == NULL) {
spin_unlock(&svcpt->scp_req_lock);
return 0;
}
timediff = cfs_timeval_sub(&right_now, &request->rq_arrival_time, NULL);
spin_unlock(&svcpt->scp_req_lock);
if ((timediff / ONE_MILLION) >
(AT_OFF ? obd_timeout * 3 / 2 : at_max)) {
CERROR("%s: unhealthy - request has been waiting %lds\n",
svcpt->scp_service->srv_name, timediff / ONE_MILLION);
return -1;
}
return 0;
}
int
ptlrpc_service_health_check(struct ptlrpc_service *svc)
{
struct ptlrpc_service_part *svcpt;
int i;
if (svc == NULL)
return 0;
ptlrpc_service_for_each_part(svcpt, i, svc) {
int rc = ptlrpc_svcpt_health_check(svcpt);
if (rc != 0)
return rc;
}
return 0;
}
