int ptlrpc_pinger_suppress_pings(void)
{
return suppress_pings;
}
struct ptlrpc_request *
ptlrpc_prep_ping(struct obd_import *imp)
{
struct ptlrpc_request *req;
req = ptlrpc_request_alloc_pack(imp, &RQF_OBD_PING,
LUSTRE_OBD_VERSION, OBD_PING);
if (req) {
ptlrpc_request_set_replen(req);
req->rq_no_resend = req->rq_no_delay = 1;
}
return req;
}
int ptlrpc_obd_ping(struct obd_device *obd)
{
int rc;
struct ptlrpc_request *req;
req = ptlrpc_prep_ping(obd->u.cli.cl_import);
if (req == NULL)
return -ENOMEM;
req->rq_send_state = LUSTRE_IMP_FULL;
rc = ptlrpc_queue_wait(req);
ptlrpc_req_finished(req);
return rc;
}
int ptlrpc_ping(struct obd_import *imp)
{
struct ptlrpc_request *req;
req = ptlrpc_prep_ping(imp);
if (req == NULL) {
CERROR("OOM trying to ping %s->%s\n",
imp->imp_obd->obd_uuid.uuid,
obd2cli_tgt(imp->imp_obd));
return -ENOMEM;
}
DEBUG_REQ(D_INFO, req, "pinging %s->%s",
imp->imp_obd->obd_uuid.uuid, obd2cli_tgt(imp->imp_obd));
ptlrpcd_add_req(req, PDL_POLICY_ROUND, -1);
return 0;
}
void ptlrpc_update_next_ping(struct obd_import *imp, int soon)
{
int time = soon ? PING_INTERVAL_SHORT : PING_INTERVAL;
if (imp->imp_state == LUSTRE_IMP_DISCON) {
int dtime = max_t(int, CONNECTION_SWITCH_MIN,
AT_OFF ? 0 :
at_get(&imp->imp_at.iat_net_latency));
time = min(time, dtime);
}
imp->imp_next_ping = cfs_time_shift(time);
}
void ptlrpc_ping_import_soon(struct obd_import *imp)
{
imp->imp_next_ping = cfs_time_current();
}
static inline int imp_is_deactive(struct obd_import *imp)
{
return (imp->imp_deactive ||
OBD_FAIL_CHECK(OBD_FAIL_PTLRPC_IMP_DEACTIVE));
}
static inline int ptlrpc_next_reconnect(struct obd_import *imp)
{
if (imp->imp_server_timeout)
return cfs_time_shift(obd_timeout / 2);
else
return cfs_time_shift(obd_timeout);
}
cfs_duration_t pinger_check_timeout(cfs_time_t time)
{
struct timeout_item *item;
cfs_time_t timeout = PING_INTERVAL;
mutex_lock(&pinger_mutex);
list_for_each_entry(item, &timeout_list, ti_chain) {
int ti_timeout = item->ti_timeout;
if (timeout > ti_timeout)
timeout = ti_timeout;
break;
}
mutex_unlock(&pinger_mutex);
return cfs_time_sub(cfs_time_add(time, cfs_time_seconds(timeout)),
cfs_time_current());
}
void ptlrpc_pinger_ir_up(void)
{
CDEBUG(D_HA, "IR up\n");
ir_up = true;
}
void ptlrpc_pinger_ir_down(void)
{
CDEBUG(D_HA, "IR down\n");
ir_up = false;
}
static void ptlrpc_pinger_process_import(struct obd_import *imp,
unsigned long this_ping)
{
int level;
int force;
int force_next;
int suppress;
spin_lock(&imp->imp_lock);
level = imp->imp_state;
force = imp->imp_force_verify;
force_next = imp->imp_force_next_verify;
suppress = ir_up && OCD_HAS_FLAG(&imp->imp_connect_data, PINGLESS);
imp->imp_force_verify = 0;
if (cfs_time_aftereq(imp->imp_next_ping - 5 * CFS_TICK, this_ping) &&
!force) {
spin_unlock(&imp->imp_lock);
return;
}
imp->imp_force_next_verify = 0;
spin_unlock(&imp->imp_lock);
CDEBUG(level == LUSTRE_IMP_FULL ? D_INFO : D_HA, "%s->%s: level %s/%u "
"force %u force_next %u deactive %u pingable %u suppress %u\n",
imp->imp_obd->obd_uuid.uuid, obd2cli_tgt(imp->imp_obd),
ptlrpc_import_state_name(level), level, force, force_next,
imp->imp_deactive, imp->imp_pingable, suppress);
if (level == LUSTRE_IMP_DISCON && !imp_is_deactive(imp)) {
imp->imp_next_ping = ptlrpc_next_reconnect(imp);
if (!imp->imp_no_pinger_recover)
ptlrpc_initiate_recovery(imp);
} else if (level != LUSTRE_IMP_FULL ||
imp->imp_obd->obd_no_recov ||
imp_is_deactive(imp)) {
CDEBUG(D_HA, "%s->%s: not pinging (in recovery "
"or recovery disabled: %s)\n",
imp->imp_obd->obd_uuid.uuid, obd2cli_tgt(imp->imp_obd),
ptlrpc_import_state_name(level));
} else if ((imp->imp_pingable && !suppress) || force_next || force) {
ptlrpc_ping(imp);
}
}
static int ptlrpc_pinger_main(void *arg)
{
struct ptlrpc_thread *thread = (struct ptlrpc_thread *)arg;
thread_set_flags(thread, SVC_RUNNING);
wake_up(&thread->t_ctl_waitq);
while (1) {
cfs_time_t this_ping = cfs_time_current();
struct l_wait_info lwi;
cfs_duration_t time_to_next_wake;
struct timeout_item *item;
struct list_head *iter;
mutex_lock(&pinger_mutex);
list_for_each_entry(item, &timeout_list, ti_chain) {
item->ti_cb(item, item->ti_cb_data);
}
list_for_each(iter, &pinger_imports) {
struct obd_import *imp =
list_entry(iter, struct obd_import,
imp_pinger_chain);
ptlrpc_pinger_process_import(imp, this_ping);
if (imp->imp_pingable && imp->imp_next_ping &&
cfs_time_after(imp->imp_next_ping,
cfs_time_add(this_ping,
cfs_time_seconds(PING_INTERVAL))))
ptlrpc_update_next_ping(imp, 0);
}
mutex_unlock(&pinger_mutex);
obd_update_maxusage();
time_to_next_wake = pinger_check_timeout(this_ping);
CDEBUG(D_INFO, "next wakeup in "CFS_DURATION_T" ("
CFS_TIME_T")\n", time_to_next_wake,
cfs_time_add(this_ping,cfs_time_seconds(PING_INTERVAL)));
if (time_to_next_wake > 0) {
lwi = LWI_TIMEOUT(max_t(cfs_duration_t,
time_to_next_wake,
cfs_time_seconds(1)),
NULL, NULL);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopping(thread) ||
thread_is_event(thread),
&lwi);
if (thread_test_and_clear_flags(thread, SVC_STOPPING)) {
break;
} else {
thread_test_and_clear_flags(thread, SVC_EVENT);
}
}
}
thread_set_flags(thread, SVC_STOPPED);
wake_up(&thread->t_ctl_waitq);
CDEBUG(D_NET, "pinger thread exiting, process %d\n", current_pid());
return 0;
}
int ptlrpc_start_pinger(void)
{
struct l_wait_info lwi = { 0 };
int rc;
if (!thread_is_init(&pinger_thread) &&
!thread_is_stopped(&pinger_thread))
return -EALREADY;
init_waitqueue_head(&pinger_thread.t_ctl_waitq);
strcpy(pinger_thread.t_name, "ll_ping");
rc = PTR_ERR(kthread_run(ptlrpc_pinger_main, &pinger_thread,
"%s", pinger_thread.t_name));
if (IS_ERR_VALUE(rc)) {
CERROR("cannot start thread: %d\n", rc);
return rc;
}
l_wait_event(pinger_thread.t_ctl_waitq,
thread_is_running(&pinger_thread), &lwi);
if (suppress_pings)
CWARN("Pings will be suppressed at the request of the "
"administrator. The configuration shall meet the "
"additional requirements described in the manual. "
"(Search for the \"suppress_pings\" kernel module "
"parameter.)\n");
return 0;
}
int ptlrpc_stop_pinger(void)
{
struct l_wait_info lwi = { 0 };
int rc = 0;
if (thread_is_init(&pinger_thread) ||
thread_is_stopped(&pinger_thread))
return -EALREADY;
ptlrpc_pinger_remove_timeouts();
thread_set_flags(&pinger_thread, SVC_STOPPING);
wake_up(&pinger_thread.t_ctl_waitq);
l_wait_event(pinger_thread.t_ctl_waitq,
thread_is_stopped(&pinger_thread), &lwi);
return rc;
}
void ptlrpc_pinger_sending_on_import(struct obd_import *imp)
{
ptlrpc_update_next_ping(imp, 0);
}
void ptlrpc_pinger_commit_expected(struct obd_import *imp)
{
ptlrpc_update_next_ping(imp, 1);
assert_spin_locked(&imp->imp_lock);
if (imp->imp_state != LUSTRE_IMP_FULL ||
OCD_HAS_FLAG(&imp->imp_connect_data, PINGLESS))
imp->imp_force_next_verify = 1;
}
int ptlrpc_pinger_add_import(struct obd_import *imp)
{
if (!list_empty(&imp->imp_pinger_chain))
return -EALREADY;
mutex_lock(&pinger_mutex);
CDEBUG(D_HA, "adding pingable import %s->%s\n",
imp->imp_obd->obd_uuid.uuid, obd2cli_tgt(imp->imp_obd));
imp->imp_obd->obd_no_recov = 0;
ptlrpc_update_next_ping(imp, 0);
list_add_tail(&imp->imp_pinger_chain, &pinger_imports);
class_import_get(imp);
ptlrpc_pinger_wake_up();
mutex_unlock(&pinger_mutex);
return 0;
}
int ptlrpc_pinger_del_import(struct obd_import *imp)
{
if (list_empty(&imp->imp_pinger_chain))
return -ENOENT;
mutex_lock(&pinger_mutex);
list_del_init(&imp->imp_pinger_chain);
CDEBUG(D_HA, "removing pingable import %s->%s\n",
imp->imp_obd->obd_uuid.uuid, obd2cli_tgt(imp->imp_obd));
imp->imp_obd->obd_no_recov = 1;
class_import_put(imp);
mutex_unlock(&pinger_mutex);
return 0;
}
struct timeout_item* ptlrpc_new_timeout(int time, enum timeout_event event,
timeout_cb_t cb, void *data)
{
struct timeout_item *ti;
OBD_ALLOC_PTR(ti);
if (!ti)
return(NULL);
INIT_LIST_HEAD(&ti->ti_obd_list);
INIT_LIST_HEAD(&ti->ti_chain);
ti->ti_timeout = time;
ti->ti_event = event;
ti->ti_cb = cb;
ti->ti_cb_data = data;
return ti;
}
static struct timeout_item*
ptlrpc_pinger_register_timeout(int time, enum timeout_event event,
timeout_cb_t cb, void *data)
{
struct timeout_item *item, *tmp;
LASSERT(mutex_is_locked(&pinger_mutex));
list_for_each_entry(item, &timeout_list, ti_chain)
if (item->ti_event == event)
goto out;
item = ptlrpc_new_timeout(time, event, cb, data);
if (item) {
list_for_each_entry_reverse(tmp, &timeout_list, ti_chain) {
if (tmp->ti_timeout < time) {
list_add(&item->ti_chain, &tmp->ti_chain);
goto out;
}
}
list_add(&item->ti_chain, &timeout_list);
}
out:
return item;
}
int ptlrpc_add_timeout_client(int time, enum timeout_event event,
timeout_cb_t cb, void *data,
struct list_head *obd_list)
{
struct timeout_item *ti;
mutex_lock(&pinger_mutex);
ti = ptlrpc_pinger_register_timeout(time, event, cb, data);
if (!ti) {
mutex_unlock(&pinger_mutex);
return (-EINVAL);
}
list_add(obd_list, &ti->ti_obd_list);
mutex_unlock(&pinger_mutex);
return 0;
}
int ptlrpc_del_timeout_client(struct list_head *obd_list,
enum timeout_event event)
{
struct timeout_item *ti = NULL, *item;
if (list_empty(obd_list))
return 0;
mutex_lock(&pinger_mutex);
list_del_init(obd_list);
list_for_each_entry(item, &timeout_list, ti_chain) {
if (item->ti_event == event) {
ti = item;
break;
}
}
LASSERTF(ti != NULL, "ti is NULL !\n");
if (list_empty(&ti->ti_obd_list)) {
list_del(&ti->ti_chain);
OBD_FREE_PTR(ti);
}
mutex_unlock(&pinger_mutex);
return 0;
}
int ptlrpc_pinger_remove_timeouts(void)
{
struct timeout_item *item, *tmp;
mutex_lock(&pinger_mutex);
list_for_each_entry_safe(item, tmp, &timeout_list, ti_chain) {
LASSERT(list_empty(&item->ti_obd_list));
list_del(&item->ti_chain);
OBD_FREE_PTR(item);
}
mutex_unlock(&pinger_mutex);
return 0;
}
void ptlrpc_pinger_wake_up(void)
{
thread_add_flags(&pinger_thread, SVC_EVENT);
wake_up(&pinger_thread.t_ctl_waitq);
}
int ping_evictor_wake(struct obd_export *exp)
{
struct obd_device *obd;
spin_lock(&pet_lock);
if (pet_state != PET_READY) {
spin_unlock(&pet_lock);
return 1;
}
obd = class_exp2obd(exp);
if (list_empty(&obd->obd_evict_list)) {
class_incref(obd, "evictor", obd);
list_add(&obd->obd_evict_list, &pet_list);
}
spin_unlock(&pet_lock);
wake_up(&pet_waitq);
return 0;
}
static int ping_evictor_main(void *arg)
{
struct obd_device *obd;
struct obd_export *exp;
struct l_wait_info lwi = { 0 };
time_t expire_time;
unshare_fs_struct();
CDEBUG(D_HA, "Starting Ping Evictor\n");
pet_state = PET_READY;
while (1) {
l_wait_event(pet_waitq, (!list_empty(&pet_list)) ||
(pet_state == PET_TERMINATE), &lwi);
if ((pet_state == PET_TERMINATE) && list_empty(&pet_list))
break;
spin_lock(&pet_lock);
obd = list_entry(pet_list.next, struct obd_device,
obd_evict_list);
spin_unlock(&pet_lock);
expire_time = cfs_time_current_sec() - PING_EVICT_TIMEOUT;
CDEBUG(D_HA, "evicting all exports of obd %s older than %ld\n",
obd->obd_name, expire_time);
spin_lock(&obd->obd_dev_lock);
while (!list_empty(&obd->obd_exports_timed)) {
exp = list_entry(obd->obd_exports_timed.next,
struct obd_export,
exp_obd_chain_timed);
if (expire_time > exp->exp_last_request_time) {
class_export_get(exp);
spin_unlock(&obd->obd_dev_lock);
LCONSOLE_WARN("%s: haven't heard from client %s"
" (at %s) in %ld seconds. I think"
" it's dead, and I am evicting"
" it. exp %p, cur %ld expire %ld"
" last %ld\n",
obd->obd_name,
obd_uuid2str(&exp->exp_client_uuid),
obd_export_nid2str(exp),
(long)(cfs_time_current_sec() -
exp->exp_last_request_time),
exp, (long)cfs_time_current_sec(),
(long)expire_time,
(long)exp->exp_last_request_time);
CDEBUG(D_HA, "Last request was at %ld\n",
exp->exp_last_request_time);
class_fail_export(exp);
class_export_put(exp);
spin_lock(&obd->obd_dev_lock);
} else {
break;
}
}
spin_unlock(&obd->obd_dev_lock);
spin_lock(&pet_lock);
list_del_init(&obd->obd_evict_list);
spin_unlock(&pet_lock);
class_decref(obd, "evictor", obd);
}
CDEBUG(D_HA, "Exiting Ping Evictor\n");
return 0;
}
void ping_evictor_start(void)
{
struct task_struct *task;
if (++pet_refcount > 1)
return;
init_waitqueue_head(&pet_waitq);
task = kthread_run(ping_evictor_main, NULL, "ll_evictor");
if (IS_ERR(task)) {
pet_refcount--;
CERROR("Cannot start ping evictor thread: %ld\n",
PTR_ERR(task));
}
}
void ping_evictor_stop(void)
{
if (--pet_refcount > 0)
return;
pet_state = PET_TERMINATE;
wake_up(&pet_waitq);
}
