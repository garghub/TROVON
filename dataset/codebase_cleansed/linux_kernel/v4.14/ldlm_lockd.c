void ldlm_handle_bl_callback(struct ldlm_namespace *ns,
struct ldlm_lock_desc *ld, struct ldlm_lock *lock)
{
int do_ast;
LDLM_DEBUG(lock, "client blocking AST callback handler");
lock_res_and_lock(lock);
ldlm_set_cbpending(lock);
if (ldlm_is_cancel_on_block(lock))
ldlm_set_cancel(lock);
do_ast = !lock->l_readers && !lock->l_writers;
unlock_res_and_lock(lock);
if (do_ast) {
CDEBUG(D_DLMTRACE,
"Lock %p already unused, calling callback (%p)\n", lock,
lock->l_blocking_ast);
if (lock->l_blocking_ast)
lock->l_blocking_ast(lock, ld, lock->l_ast_data,
LDLM_CB_BLOCKING);
} else {
CDEBUG(D_DLMTRACE,
"Lock %p is referenced, will be cancelled later\n",
lock);
}
LDLM_DEBUG(lock, "client blocking callback handler END");
LDLM_LOCK_RELEASE(lock);
}
static void ldlm_handle_cp_callback(struct ptlrpc_request *req,
struct ldlm_namespace *ns,
struct ldlm_request *dlm_req,
struct ldlm_lock *lock)
{
int lvb_len;
LIST_HEAD(ast_list);
int rc = 0;
LDLM_DEBUG(lock, "client completion callback handler START");
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_CANCEL_BL_CB_RACE)) {
int to = cfs_time_seconds(1);
while (to > 0) {
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(to);
if (lock->l_granted_mode == lock->l_req_mode ||
ldlm_is_destroyed(lock))
break;
}
}
lvb_len = req_capsule_get_size(&req->rq_pill, &RMF_DLM_LVB, RCL_CLIENT);
if (lvb_len < 0) {
LDLM_ERROR(lock, "Fail to get lvb_len, rc = %d", lvb_len);
rc = lvb_len;
goto out;
} else if (lvb_len > 0) {
if (lock->l_lvb_len > 0) {
LASSERT(lock->l_lvb_data);
if (unlikely(lock->l_lvb_len < lvb_len)) {
LDLM_ERROR(lock, "Replied LVB is larger than expectation, expected = %d, replied = %d",
lock->l_lvb_len, lvb_len);
rc = -EINVAL;
goto out;
}
} else if (ldlm_has_layout(lock)) {
void *lvb_data;
lvb_data = kzalloc(lvb_len, GFP_NOFS);
if (!lvb_data) {
LDLM_ERROR(lock, "No memory: %d.\n", lvb_len);
rc = -ENOMEM;
goto out;
}
lock_res_and_lock(lock);
LASSERT(!lock->l_lvb_data);
lock->l_lvb_type = LVB_T_LAYOUT;
lock->l_lvb_data = lvb_data;
lock->l_lvb_len = lvb_len;
unlock_res_and_lock(lock);
}
}
lock_res_and_lock(lock);
if (ldlm_is_destroyed(lock) ||
lock->l_granted_mode == lock->l_req_mode) {
unlock_res_and_lock(lock);
LDLM_DEBUG(lock, "Double grant race happened");
rc = 0;
goto out;
}
if (dlm_req->lock_desc.l_granted_mode != lock->l_req_mode) {
lock->l_req_mode = dlm_req->lock_desc.l_granted_mode;
LDLM_DEBUG(lock, "completion AST, new lock mode");
}
if (lock->l_resource->lr_type != LDLM_PLAIN) {
ldlm_convert_policy_to_local(req->rq_export,
dlm_req->lock_desc.l_resource.lr_type,
&dlm_req->lock_desc.l_policy_data,
&lock->l_policy_data);
LDLM_DEBUG(lock, "completion AST, new policy data");
}
ldlm_resource_unlink_lock(lock);
if (memcmp(&dlm_req->lock_desc.l_resource.lr_name,
&lock->l_resource->lr_name,
sizeof(lock->l_resource->lr_name)) != 0) {
unlock_res_and_lock(lock);
rc = ldlm_lock_change_resource(ns, lock,
&dlm_req->lock_desc.l_resource.lr_name);
if (rc < 0) {
LDLM_ERROR(lock, "Failed to allocate resource");
goto out;
}
LDLM_DEBUG(lock, "completion AST, new resource");
CERROR("change resource!\n");
lock_res_and_lock(lock);
}
if (dlm_req->lock_flags & LDLM_FL_AST_SENT) {
ldlm_lock_remove_from_lru(lock);
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_BL_AST;
LDLM_DEBUG(lock, "completion AST includes blocking AST");
}
if (lock->l_lvb_len > 0) {
rc = ldlm_fill_lvb(lock, &req->rq_pill, RCL_CLIENT,
lock->l_lvb_data, lvb_len);
if (rc < 0) {
unlock_res_and_lock(lock);
goto out;
}
}
ldlm_grant_lock(lock, &ast_list);
unlock_res_and_lock(lock);
LDLM_DEBUG(lock, "callback handler finished, about to run_ast_work");
OBD_FAIL_TIMEOUT(OBD_FAIL_OSC_CP_ENQ_RACE, 2);
ldlm_run_ast_work(ns, &ast_list, LDLM_WORK_CP_AST);
LDLM_DEBUG_NOLOCK("client completion callback handler END (lock %p)",
lock);
goto out;
out:
if (rc < 0) {
lock_res_and_lock(lock);
ldlm_set_failed(lock);
unlock_res_and_lock(lock);
wake_up(&lock->l_waitq);
}
LDLM_LOCK_RELEASE(lock);
}
static void ldlm_handle_gl_callback(struct ptlrpc_request *req,
struct ldlm_namespace *ns,
struct ldlm_request *dlm_req,
struct ldlm_lock *lock)
{
int rc = -ENOSYS;
LDLM_DEBUG(lock, "client glimpse AST callback handler");
if (lock->l_glimpse_ast)
rc = lock->l_glimpse_ast(lock, req);
if (req->rq_repmsg) {
ptlrpc_reply(req);
} else {
req->rq_status = rc;
ptlrpc_error(req);
}
lock_res_and_lock(lock);
if (lock->l_granted_mode == LCK_PW &&
!lock->l_readers && !lock->l_writers &&
cfs_time_after(cfs_time_current(),
cfs_time_add(lock->l_last_used,
cfs_time_seconds(10)))) {
unlock_res_and_lock(lock);
if (ldlm_bl_to_thread_lock(ns, NULL, lock))
ldlm_handle_bl_callback(ns, NULL, lock);
return;
}
unlock_res_and_lock(lock);
LDLM_LOCK_RELEASE(lock);
}
static int ldlm_callback_reply(struct ptlrpc_request *req, int rc)
{
if (req->rq_no_reply)
return 0;
req->rq_status = rc;
if (!req->rq_packed_final) {
rc = lustre_pack_reply(req, 1, NULL, NULL);
if (rc)
return rc;
}
return ptlrpc_reply(req);
}
static int __ldlm_bl_to_thread(struct ldlm_bl_work_item *blwi,
enum ldlm_cancel_flags cancel_flags)
{
struct ldlm_bl_pool *blp = ldlm_state->ldlm_bl_pool;
spin_lock(&blp->blp_lock);
if (blwi->blwi_lock && ldlm_is_discard_data(blwi->blwi_lock)) {
list_add_tail(&blwi->blwi_entry, &blp->blp_prio_list);
} else {
list_add_tail(&blwi->blwi_entry, &blp->blp_list);
}
spin_unlock(&blp->blp_lock);
wake_up(&blp->blp_waitq);
if (!(cancel_flags & LCF_ASYNC))
wait_for_completion(&blwi->blwi_comp);
return 0;
}
static inline void init_blwi(struct ldlm_bl_work_item *blwi,
struct ldlm_namespace *ns,
struct ldlm_lock_desc *ld,
struct list_head *cancels, int count,
struct ldlm_lock *lock,
enum ldlm_cancel_flags cancel_flags)
{
init_completion(&blwi->blwi_comp);
INIT_LIST_HEAD(&blwi->blwi_head);
if (memory_pressure_get())
blwi->blwi_mem_pressure = 1;
blwi->blwi_ns = ns;
blwi->blwi_flags = cancel_flags;
if (ld)
blwi->blwi_ld = *ld;
if (count) {
list_add(&blwi->blwi_head, cancels);
list_del_init(cancels);
blwi->blwi_count = count;
} else {
blwi->blwi_lock = lock;
}
}
static int ldlm_bl_to_thread(struct ldlm_namespace *ns,
struct ldlm_lock_desc *ld,
struct ldlm_lock *lock,
struct list_head *cancels, int count,
enum ldlm_cancel_flags cancel_flags)
{
if (cancels && count == 0)
return 0;
if (cancel_flags & LCF_ASYNC) {
struct ldlm_bl_work_item *blwi;
blwi = kzalloc(sizeof(*blwi), GFP_NOFS);
if (!blwi)
return -ENOMEM;
init_blwi(blwi, ns, ld, cancels, count, lock, cancel_flags);
return __ldlm_bl_to_thread(blwi, cancel_flags);
} else {
struct ldlm_bl_work_item blwi;
memset(&blwi, 0, sizeof(blwi));
init_blwi(&blwi, ns, ld, cancels, count, lock, cancel_flags);
return __ldlm_bl_to_thread(&blwi, cancel_flags);
}
}
int ldlm_bl_to_thread_lock(struct ldlm_namespace *ns, struct ldlm_lock_desc *ld,
struct ldlm_lock *lock)
{
return ldlm_bl_to_thread(ns, ld, lock, NULL, 0, LCF_ASYNC);
}
int ldlm_bl_to_thread_list(struct ldlm_namespace *ns, struct ldlm_lock_desc *ld,
struct list_head *cancels, int count,
enum ldlm_cancel_flags cancel_flags)
{
return ldlm_bl_to_thread(ns, ld, NULL, cancels, count, cancel_flags);
}
int ldlm_bl_thread_wakeup(void)
{
wake_up(&ldlm_state->ldlm_bl_pool->blp_waitq);
return 0;
}
static int ldlm_handle_setinfo(struct ptlrpc_request *req)
{
struct obd_device *obd = req->rq_export->exp_obd;
char *key;
void *val;
int keylen, vallen;
int rc = -ENOSYS;
DEBUG_REQ(D_HSM, req, "%s: handle setinfo\n", obd->obd_name);
req_capsule_set(&req->rq_pill, &RQF_OBD_SET_INFO);
key = req_capsule_client_get(&req->rq_pill, &RMF_SETINFO_KEY);
if (!key) {
DEBUG_REQ(D_IOCTL, req, "no set_info key");
return -EFAULT;
}
keylen = req_capsule_get_size(&req->rq_pill, &RMF_SETINFO_KEY,
RCL_CLIENT);
val = req_capsule_client_get(&req->rq_pill, &RMF_SETINFO_VAL);
if (!val) {
DEBUG_REQ(D_IOCTL, req, "no set_info val");
return -EFAULT;
}
vallen = req_capsule_get_size(&req->rq_pill, &RMF_SETINFO_VAL,
RCL_CLIENT);
if (KEY_IS(KEY_HSM_COPYTOOL_SEND))
rc = obd_set_info_async(req->rq_svc_thread->t_env,
req->rq_export,
sizeof(KEY_HSM_COPYTOOL_SEND),
KEY_HSM_COPYTOOL_SEND,
vallen, val, NULL);
else
DEBUG_REQ(D_WARNING, req, "ignoring unknown key %s", key);
return rc;
}
static inline void ldlm_callback_errmsg(struct ptlrpc_request *req,
const char *msg, int rc,
const struct lustre_handle *handle)
{
DEBUG_REQ((req->rq_no_reply || rc) ? D_WARNING : D_DLMTRACE, req,
"%s: [nid %s] [rc %d] [lock %#llx]",
msg, libcfs_id2str(req->rq_peer), rc,
handle ? handle->cookie : 0);
if (req->rq_no_reply)
CWARN("No reply was sent, maybe cause bug 21636.\n");
else if (rc)
CWARN("Send reply failed, maybe cause bug 21636.\n");
}
static int ldlm_callback_handler(struct ptlrpc_request *req)
{
struct ldlm_namespace *ns;
struct ldlm_request *dlm_req;
struct ldlm_lock *lock;
int rc;
if (lustre_msg_get_opc(req->rq_reqmsg) == SEC_CTX_FINI)
return 0;
req_capsule_init(&req->rq_pill, req, RCL_SERVER);
if (!req->rq_export) {
rc = ldlm_callback_reply(req, -ENOTCONN);
ldlm_callback_errmsg(req, "Operate on unconnected server",
rc, NULL);
return 0;
}
LASSERT(req->rq_export->exp_obd);
switch (lustre_msg_get_opc(req->rq_reqmsg)) {
case LDLM_BL_CALLBACK:
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_BL_CALLBACK_NET)) {
if (cfs_fail_err)
ldlm_callback_reply(req, -(int)cfs_fail_err);
return 0;
}
break;
case LDLM_CP_CALLBACK:
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_CP_CALLBACK_NET))
return 0;
break;
case LDLM_GL_CALLBACK:
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_GL_CALLBACK_NET))
return 0;
break;
case LDLM_SET_INFO:
rc = ldlm_handle_setinfo(req);
ldlm_callback_reply(req, rc);
return 0;
default:
CERROR("unknown opcode %u\n",
lustre_msg_get_opc(req->rq_reqmsg));
ldlm_callback_reply(req, -EPROTO);
return 0;
}
ns = req->rq_export->exp_obd->obd_namespace;
LASSERT(ns);
req_capsule_set(&req->rq_pill, &RQF_LDLM_CALLBACK);
dlm_req = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
if (!dlm_req) {
rc = ldlm_callback_reply(req, -EPROTO);
ldlm_callback_errmsg(req, "Operate without parameter", rc,
NULL);
return 0;
}
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_CANCEL_BL_CB_RACE) &&
lustre_msg_get_opc(req->rq_reqmsg) == LDLM_BL_CALLBACK) {
rc = ldlm_cli_cancel(&dlm_req->lock_handle[0], 0);
if (rc < 0)
CERROR("ldlm_cli_cancel: %d\n", rc);
}
lock = ldlm_handle2lock_long(&dlm_req->lock_handle[0], 0);
if (!lock) {
CDEBUG(D_DLMTRACE, "callback on lock %#llx - lock disappeared\n",
dlm_req->lock_handle[0].cookie);
rc = ldlm_callback_reply(req, -EINVAL);
ldlm_callback_errmsg(req, "Operate with invalid parameter", rc,
&dlm_req->lock_handle[0]);
return 0;
}
if (ldlm_is_fail_loc(lock) &&
lustre_msg_get_opc(req->rq_reqmsg) == LDLM_BL_CALLBACK)
OBD_RACE(OBD_FAIL_LDLM_CP_BL_RACE);
lock_res_and_lock(lock);
lock->l_flags |= ldlm_flags_from_wire(dlm_req->lock_flags &
LDLM_FL_AST_MASK);
if (lustre_msg_get_opc(req->rq_reqmsg) == LDLM_BL_CALLBACK) {
if ((ldlm_is_canceling(lock) && ldlm_is_bl_done(lock)) ||
ldlm_is_failed(lock)) {
LDLM_DEBUG(lock,
"callback on lock %#llx - lock disappeared",
dlm_req->lock_handle[0].cookie);
unlock_res_and_lock(lock);
LDLM_LOCK_RELEASE(lock);
rc = ldlm_callback_reply(req, -EINVAL);
ldlm_callback_errmsg(req, "Operate on stale lock", rc,
&dlm_req->lock_handle[0]);
return 0;
}
ldlm_lock_remove_from_lru(lock);
ldlm_set_bl_ast(lock);
}
unlock_res_and_lock(lock);
switch (lustre_msg_get_opc(req->rq_reqmsg)) {
case LDLM_BL_CALLBACK:
CDEBUG(D_INODE, "blocking ast\n");
req_capsule_extend(&req->rq_pill, &RQF_LDLM_BL_CALLBACK);
if (!ldlm_is_cancel_on_block(lock)) {
rc = ldlm_callback_reply(req, 0);
if (req->rq_no_reply || rc)
ldlm_callback_errmsg(req, "Normal process", rc,
&dlm_req->lock_handle[0]);
}
if (ldlm_bl_to_thread_lock(ns, &dlm_req->lock_desc, lock))
ldlm_handle_bl_callback(ns, &dlm_req->lock_desc, lock);
break;
case LDLM_CP_CALLBACK:
CDEBUG(D_INODE, "completion ast\n");
req_capsule_extend(&req->rq_pill, &RQF_LDLM_CP_CALLBACK);
ldlm_callback_reply(req, 0);
ldlm_handle_cp_callback(req, ns, dlm_req, lock);
break;
case LDLM_GL_CALLBACK:
CDEBUG(D_INODE, "glimpse ast\n");
req_capsule_extend(&req->rq_pill, &RQF_LDLM_GL_CALLBACK);
ldlm_handle_gl_callback(req, ns, dlm_req, lock);
break;
default:
LBUG();
}
return 0;
}
static int ldlm_bl_get_work(struct ldlm_bl_pool *blp,
struct ldlm_bl_work_item **p_blwi,
struct obd_export **p_exp)
{
int num_th = atomic_read(&blp->blp_num_threads);
struct ldlm_bl_work_item *blwi = NULL;
static unsigned int num_bl;
spin_lock(&blp->blp_lock);
if (!list_empty(&blp->blp_list) &&
(list_empty(&blp->blp_prio_list) || num_bl == 0))
blwi = list_entry(blp->blp_list.next,
struct ldlm_bl_work_item, blwi_entry);
else
if (!list_empty(&blp->blp_prio_list))
blwi = list_entry(blp->blp_prio_list.next,
struct ldlm_bl_work_item,
blwi_entry);
if (blwi) {
if (++num_bl >= num_th)
num_bl = 0;
list_del(&blwi->blwi_entry);
}
spin_unlock(&blp->blp_lock);
*p_blwi = blwi;
return (*p_blwi || *p_exp) ? 1 : 0;
}
static int ldlm_bl_thread_start(struct ldlm_bl_pool *blp, bool check_busy)
{
struct ldlm_bl_thread_data bltd = { .bltd_blp = blp };
struct task_struct *task;
init_completion(&bltd.bltd_comp);
bltd.bltd_num = atomic_inc_return(&blp->blp_num_threads);
if (bltd.bltd_num >= blp->blp_max_threads) {
atomic_dec(&blp->blp_num_threads);
return 0;
}
LASSERTF(bltd.bltd_num > 0, "thread num:%d\n", bltd.bltd_num);
if (check_busy &&
atomic_read(&blp->blp_busy_threads) < (bltd.bltd_num - 1)) {
atomic_dec(&blp->blp_num_threads);
return 0;
}
task = kthread_run(ldlm_bl_thread_main, &bltd, "ldlm_bl_%02d",
bltd.bltd_num);
if (IS_ERR(task)) {
CERROR("cannot start LDLM thread ldlm_bl_%02d: rc %ld\n",
bltd.bltd_num, PTR_ERR(task));
atomic_dec(&blp->blp_num_threads);
return PTR_ERR(task);
}
wait_for_completion(&bltd.bltd_comp);
return 0;
}
static int ldlm_bl_thread_need_create(struct ldlm_bl_pool *blp,
struct ldlm_bl_work_item *blwi)
{
if (atomic_read(&blp->blp_num_threads) >= blp->blp_max_threads)
return 0;
if (atomic_read(&blp->blp_busy_threads) <
atomic_read(&blp->blp_num_threads))
return 0;
if (blwi && (!blwi->blwi_ns || blwi->blwi_mem_pressure))
return 0;
return 1;
}
static int ldlm_bl_thread_blwi(struct ldlm_bl_pool *blp,
struct ldlm_bl_work_item *blwi)
{
if (!blwi->blwi_ns)
return LDLM_ITER_STOP;
if (blwi->blwi_mem_pressure)
memory_pressure_set();
OBD_FAIL_TIMEOUT(OBD_FAIL_LDLM_PAUSE_CANCEL2, 4);
if (blwi->blwi_count) {
int count;
count = ldlm_cli_cancel_list_local(&blwi->blwi_head,
blwi->blwi_count,
LCF_BL_AST);
ldlm_cli_cancel_list(&blwi->blwi_head, count, NULL,
blwi->blwi_flags);
} else {
ldlm_handle_bl_callback(blwi->blwi_ns, &blwi->blwi_ld,
blwi->blwi_lock);
}
if (blwi->blwi_mem_pressure)
memory_pressure_clr();
if (blwi->blwi_flags & LCF_ASYNC)
kfree(blwi);
else
complete(&blwi->blwi_comp);
return 0;
}
static int ldlm_bl_thread_main(void *arg)
{
struct ldlm_bl_pool *blp;
struct ldlm_bl_thread_data *bltd = arg;
blp = bltd->bltd_blp;
complete(&bltd->bltd_comp);
while (1) {
struct l_wait_info lwi = { 0 };
struct ldlm_bl_work_item *blwi = NULL;
struct obd_export *exp = NULL;
int rc;
rc = ldlm_bl_get_work(blp, &blwi, &exp);
if (!rc)
l_wait_event_exclusive(blp->blp_waitq,
ldlm_bl_get_work(blp, &blwi,
&exp),
&lwi);
atomic_inc(&blp->blp_busy_threads);
if (ldlm_bl_thread_need_create(blp, blwi))
ldlm_bl_thread_start(blp, true);
if (blwi)
rc = ldlm_bl_thread_blwi(blp, blwi);
atomic_dec(&blp->blp_busy_threads);
if (rc == LDLM_ITER_STOP)
break;
}
atomic_dec(&blp->blp_num_threads);
complete(&blp->blp_comp);
return 0;
}
int ldlm_get_ref(void)
{
int rc = 0;
mutex_lock(&ldlm_ref_mutex);
if (++ldlm_refcount == 1) {
rc = ldlm_setup();
if (rc)
ldlm_refcount--;
}
mutex_unlock(&ldlm_ref_mutex);
return rc;
}
void ldlm_put_ref(void)
{
mutex_lock(&ldlm_ref_mutex);
if (ldlm_refcount == 1) {
int rc = ldlm_cleanup();
if (rc)
CERROR("ldlm_cleanup failed: %d\n", rc);
else
ldlm_refcount--;
} else {
ldlm_refcount--;
}
mutex_unlock(&ldlm_ref_mutex);
}
static ssize_t cancel_unused_locks_before_replay_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", ldlm_cancel_unused_locks_before_replay);
}
static ssize_t cancel_unused_locks_before_replay_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer,
size_t count)
{
int rc;
unsigned long val;
rc = kstrtoul(buffer, 10, &val);
if (rc)
return rc;
ldlm_cancel_unused_locks_before_replay = val;
return count;
}
static int ldlm_setup(void)
{
static struct ptlrpc_service_conf conf;
struct ldlm_bl_pool *blp = NULL;
int rc = 0;
int i;
if (ldlm_state)
return -EALREADY;
ldlm_state = kzalloc(sizeof(*ldlm_state), GFP_NOFS);
if (!ldlm_state)
return -ENOMEM;
ldlm_kobj = kobject_create_and_add("ldlm", lustre_kobj);
if (!ldlm_kobj) {
rc = -ENOMEM;
goto out;
}
rc = sysfs_create_group(ldlm_kobj, &ldlm_attr_group);
if (rc)
goto out;
ldlm_ns_kset = kset_create_and_add("namespaces", NULL, ldlm_kobj);
if (!ldlm_ns_kset) {
rc = -ENOMEM;
goto out;
}
ldlm_svc_kset = kset_create_and_add("services", NULL, ldlm_kobj);
if (!ldlm_svc_kset) {
rc = -ENOMEM;
goto out;
}
rc = ldlm_debugfs_setup();
if (rc != 0)
goto out;
memset(&conf, 0, sizeof(conf));
conf = (typeof(conf)) {
.psc_name = "ldlm_cbd",
.psc_watchdog_factor = 2,
.psc_buf = {
.bc_nbufs = LDLM_CLIENT_NBUFS,
.bc_buf_size = LDLM_BUFSIZE,
.bc_req_max_size = LDLM_MAXREQSIZE,
.bc_rep_max_size = LDLM_MAXREPSIZE,
.bc_req_portal = LDLM_CB_REQUEST_PORTAL,
.bc_rep_portal = LDLM_CB_REPLY_PORTAL,
},
.psc_thr = {
.tc_thr_name = "ldlm_cb",
.tc_thr_factor = LDLM_THR_FACTOR,
.tc_nthrs_init = LDLM_NTHRS_INIT,
.tc_nthrs_base = LDLM_NTHRS_BASE,
.tc_nthrs_max = LDLM_NTHRS_MAX,
.tc_nthrs_user = ldlm_num_threads,
.tc_cpu_affinity = 1,
.tc_ctx_tags = LCT_MD_THREAD | LCT_DT_THREAD,
},
.psc_cpt = {
.cc_pattern = ldlm_cpts,
},
.psc_ops = {
.so_req_handler = ldlm_callback_handler,
},
};
ldlm_state->ldlm_cb_service =
ptlrpc_register_service(&conf, ldlm_svc_kset,
ldlm_svc_debugfs_dir);
if (IS_ERR(ldlm_state->ldlm_cb_service)) {
CERROR("failed to start service\n");
rc = PTR_ERR(ldlm_state->ldlm_cb_service);
ldlm_state->ldlm_cb_service = NULL;
goto out;
}
blp = kzalloc(sizeof(*blp), GFP_NOFS);
if (!blp) {
rc = -ENOMEM;
goto out;
}
ldlm_state->ldlm_bl_pool = blp;
spin_lock_init(&blp->blp_lock);
INIT_LIST_HEAD(&blp->blp_list);
INIT_LIST_HEAD(&blp->blp_prio_list);
init_waitqueue_head(&blp->blp_waitq);
atomic_set(&blp->blp_num_threads, 0);
atomic_set(&blp->blp_busy_threads, 0);
if (ldlm_num_threads == 0) {
blp->blp_min_threads = LDLM_NTHRS_INIT;
blp->blp_max_threads = LDLM_NTHRS_MAX;
} else {
blp->blp_min_threads = min_t(int, LDLM_NTHRS_MAX,
max_t(int, LDLM_NTHRS_INIT,
ldlm_num_threads));
blp->blp_max_threads = blp->blp_min_threads;
}
for (i = 0; i < blp->blp_min_threads; i++) {
rc = ldlm_bl_thread_start(blp, false);
if (rc < 0)
goto out;
}
rc = ldlm_pools_init();
if (rc) {
CERROR("Failed to initialize LDLM pools: %d\n", rc);
goto out;
}
return 0;
out:
ldlm_cleanup();
return rc;
}
static int ldlm_cleanup(void)
{
if (!list_empty(ldlm_namespace_list(LDLM_NAMESPACE_SERVER)) ||
!list_empty(ldlm_namespace_list(LDLM_NAMESPACE_CLIENT))) {
CERROR("ldlm still has namespaces; clean these up first.\n");
ldlm_dump_all_namespaces(LDLM_NAMESPACE_SERVER, D_DLMTRACE);
ldlm_dump_all_namespaces(LDLM_NAMESPACE_CLIENT, D_DLMTRACE);
return -EBUSY;
}
ldlm_pools_fini();
if (ldlm_state->ldlm_bl_pool) {
struct ldlm_bl_pool *blp = ldlm_state->ldlm_bl_pool;
while (atomic_read(&blp->blp_num_threads) > 0) {
struct ldlm_bl_work_item blwi = { .blwi_ns = NULL };
init_completion(&blp->blp_comp);
spin_lock(&blp->blp_lock);
list_add_tail(&blwi.blwi_entry, &blp->blp_list);
wake_up(&blp->blp_waitq);
spin_unlock(&blp->blp_lock);
wait_for_completion(&blp->blp_comp);
}
kfree(blp);
}
if (ldlm_state->ldlm_cb_service)
ptlrpc_unregister_service(ldlm_state->ldlm_cb_service);
if (ldlm_ns_kset)
kset_unregister(ldlm_ns_kset);
if (ldlm_svc_kset)
kset_unregister(ldlm_svc_kset);
if (ldlm_kobj)
kobject_put(ldlm_kobj);
ldlm_debugfs_cleanup();
kfree(ldlm_state);
ldlm_state = NULL;
return 0;
}
int ldlm_init(void)
{
mutex_init(&ldlm_ref_mutex);
mutex_init(ldlm_namespace_lock(LDLM_NAMESPACE_SERVER));
mutex_init(ldlm_namespace_lock(LDLM_NAMESPACE_CLIENT));
ldlm_resource_slab = kmem_cache_create("ldlm_resources",
sizeof(struct ldlm_resource), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!ldlm_resource_slab)
return -ENOMEM;
ldlm_lock_slab = kmem_cache_create("ldlm_locks",
sizeof(struct ldlm_lock), 0,
SLAB_HWCACHE_ALIGN |
SLAB_TYPESAFE_BY_RCU, NULL);
if (!ldlm_lock_slab) {
kmem_cache_destroy(ldlm_resource_slab);
return -ENOMEM;
}
ldlm_interval_slab = kmem_cache_create("interval_node",
sizeof(struct ldlm_interval),
0, SLAB_HWCACHE_ALIGN, NULL);
if (!ldlm_interval_slab) {
kmem_cache_destroy(ldlm_resource_slab);
kmem_cache_destroy(ldlm_lock_slab);
return -ENOMEM;
}
#if LUSTRE_TRACKS_LOCK_EXP_REFS
class_export_dump_hook = ldlm_dump_export_locks;
#endif
return 0;
}
void ldlm_exit(void)
{
if (ldlm_refcount)
CERROR("ldlm_refcount is %d in %s!\n", ldlm_refcount, __func__);
kmem_cache_destroy(ldlm_resource_slab);
synchronize_rcu();
kmem_cache_destroy(ldlm_lock_slab);
kmem_cache_destroy(ldlm_interval_slab);
}
