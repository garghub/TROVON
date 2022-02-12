static int mgc_name2resid(char *name, int len, struct ldlm_res_id *res_id,
int type)
{
__u64 resname = 0;
if (len > sizeof(resname)) {
CERROR("name too long: %s\n", name);
return -EINVAL;
}
if (len <= 0) {
CERROR("missing name: %s\n", name);
return -EINVAL;
}
memcpy(&resname, name, len);
memset(res_id, 0, sizeof(*res_id));
res_id->name[0] = cpu_to_le64(resname);
switch (type) {
case CONFIG_T_CONFIG:
case CONFIG_T_SPTLRPC:
resname = 0;
break;
case CONFIG_T_RECOVER:
case CONFIG_T_PARAMS:
resname = type;
break;
default:
LBUG();
}
res_id->name[1] = cpu_to_le64(resname);
CDEBUG(D_MGC, "log %s to resid %#llx/%#llx (%.8s)\n", name,
res_id->name[0], res_id->name[1], (char *)&res_id->name[0]);
return 0;
}
int mgc_fsname2resid(char *fsname, struct ldlm_res_id *res_id, int type)
{
return mgc_name2resid(fsname, strlen(fsname), res_id, type);
}
static int mgc_logname2resid(char *logname, struct ldlm_res_id *res_id, int type)
{
char *name_end;
int len;
name_end = strrchr(logname, '-');
if (!name_end)
len = strlen(logname);
else
len = name_end - logname;
return mgc_name2resid(logname, len, res_id, type);
}
static int config_log_get(struct config_llog_data *cld)
{
atomic_inc(&cld->cld_refcount);
CDEBUG(D_INFO, "log %s refs %d\n", cld->cld_logname,
atomic_read(&cld->cld_refcount));
return 0;
}
static void config_log_put(struct config_llog_data *cld)
{
CDEBUG(D_INFO, "log %s refs %d\n", cld->cld_logname,
atomic_read(&cld->cld_refcount));
LASSERT(atomic_read(&cld->cld_refcount) > 0);
if (atomic_dec_and_lock(&cld->cld_refcount, &config_list_lock)) {
list_del(&cld->cld_list_chain);
spin_unlock(&config_list_lock);
CDEBUG(D_MGC, "dropping config log %s\n", cld->cld_logname);
if (cld->cld_recover)
config_log_put(cld->cld_recover);
if (cld->cld_params)
config_log_put(cld->cld_params);
if (cld->cld_sptlrpc)
config_log_put(cld->cld_sptlrpc);
if (cld_is_sptlrpc(cld))
sptlrpc_conf_log_stop(cld->cld_logname);
class_export_put(cld->cld_mgcexp);
kfree(cld);
}
}
static
struct config_llog_data *config_log_find(char *logname,
struct config_llog_instance *cfg)
{
struct config_llog_data *cld;
struct config_llog_data *found = NULL;
void *instance;
LASSERT(logname);
instance = cfg ? cfg->cfg_instance : NULL;
spin_lock(&config_list_lock);
list_for_each_entry(cld, &config_llog_list, cld_list_chain) {
if (instance != cld->cld_cfg.cfg_instance)
continue;
if (strcmp(logname, cld->cld_logname) == 0) {
found = cld;
config_log_get(found);
break;
}
}
spin_unlock(&config_list_lock);
return found;
}
static
struct config_llog_data *do_config_log_add(struct obd_device *obd,
char *logname,
int type,
struct config_llog_instance *cfg,
struct super_block *sb)
{
struct config_llog_data *cld;
int rc;
CDEBUG(D_MGC, "do adding config log %s:%p\n", logname,
cfg ? cfg->cfg_instance : NULL);
cld = kzalloc(sizeof(*cld) + strlen(logname) + 1, GFP_NOFS);
if (!cld)
return ERR_PTR(-ENOMEM);
rc = mgc_logname2resid(logname, &cld->cld_resid, type);
if (rc) {
kfree(cld);
return ERR_PTR(rc);
}
strcpy(cld->cld_logname, logname);
if (cfg)
cld->cld_cfg = *cfg;
else
cld->cld_cfg.cfg_callback = class_config_llog_handler;
mutex_init(&cld->cld_lock);
cld->cld_cfg.cfg_last_idx = 0;
cld->cld_cfg.cfg_flags = 0;
cld->cld_cfg.cfg_sb = sb;
cld->cld_type = type;
atomic_set(&cld->cld_refcount, 1);
cld->cld_mgcexp = class_export_get(obd->obd_self_export);
if (cld_is_sptlrpc(cld)) {
sptlrpc_conf_log_start(logname);
cld->cld_cfg.cfg_obdname = obd->obd_name;
}
spin_lock(&config_list_lock);
list_add(&cld->cld_list_chain, &config_llog_list);
spin_unlock(&config_list_lock);
if (cld_is_sptlrpc(cld)) {
rc = mgc_process_log(obd, cld);
if (rc && rc != -ENOENT)
CERROR("failed processing sptlrpc log: %d\n", rc);
}
return cld;
}
static struct config_llog_data *
config_recover_log_add(struct obd_device *obd, char *fsname,
struct config_llog_instance *cfg,
struct super_block *sb)
{
struct config_llog_instance lcfg = *cfg;
struct config_llog_data *cld;
char logname[32];
LASSERT(strlen(fsname) < sizeof(logname) / 2);
strcpy(logname, fsname);
LASSERT(lcfg.cfg_instance);
strcat(logname, "-cliir");
cld = do_config_log_add(obd, logname, CONFIG_T_RECOVER, &lcfg, sb);
return cld;
}
static struct config_llog_data *
config_params_log_add(struct obd_device *obd,
struct config_llog_instance *cfg, struct super_block *sb)
{
struct config_llog_instance lcfg = *cfg;
struct config_llog_data *cld;
lcfg.cfg_instance = sb;
cld = do_config_log_add(obd, PARAMS_FILENAME, CONFIG_T_PARAMS,
&lcfg, sb);
return cld;
}
static struct config_llog_data *
config_log_add(struct obd_device *obd, char *logname,
struct config_llog_instance *cfg, struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
struct config_llog_data *cld;
struct config_llog_data *sptlrpc_cld;
struct config_llog_data *params_cld;
bool locked = false;
char seclogname[32];
char *ptr;
int rc;
CDEBUG(D_MGC, "adding config log %s:%p\n", logname, cfg->cfg_instance);
ptr = strrchr(logname, '-');
if (!ptr || ptr - logname > 8) {
CERROR("logname %s is too long\n", logname);
return ERR_PTR(-EINVAL);
}
memcpy(seclogname, logname, ptr - logname);
strcpy(seclogname + (ptr - logname), "-sptlrpc");
sptlrpc_cld = config_log_find(seclogname, NULL);
if (!sptlrpc_cld) {
sptlrpc_cld = do_config_log_add(obd, seclogname,
CONFIG_T_SPTLRPC, NULL, NULL);
if (IS_ERR(sptlrpc_cld)) {
CERROR("can't create sptlrpc log: %s\n", seclogname);
rc = PTR_ERR(sptlrpc_cld);
goto out_err;
}
}
params_cld = config_params_log_add(obd, cfg, sb);
if (IS_ERR(params_cld)) {
rc = PTR_ERR(params_cld);
CERROR("%s: can't create params log: rc = %d\n",
obd->obd_name, rc);
goto out_sptlrpc;
}
cld = do_config_log_add(obd, logname, CONFIG_T_CONFIG, cfg, sb);
if (IS_ERR(cld)) {
CERROR("can't create log: %s\n", logname);
rc = PTR_ERR(cld);
goto out_params;
}
cld->cld_sptlrpc = sptlrpc_cld;
cld->cld_params = params_cld;
LASSERT(lsi->lsi_lmd);
if (!(lsi->lsi_lmd->lmd_flags & LMD_FLG_NOIR)) {
struct config_llog_data *recover_cld;
ptr = strrchr(seclogname, '-');
if (ptr) {
*ptr = 0;
} else {
CERROR("%s: sptlrpc log name not correct, %s: rc = %d\n",
obd->obd_name, seclogname, -EINVAL);
config_log_put(cld);
rc = -EINVAL;
goto out_cld;
}
recover_cld = config_recover_log_add(obd, seclogname, cfg, sb);
if (IS_ERR(recover_cld)) {
rc = PTR_ERR(recover_cld);
goto out_cld;
}
mutex_lock(&cld->cld_lock);
locked = true;
cld->cld_recover = recover_cld;
}
if (!locked)
mutex_lock(&cld->cld_lock);
cld->cld_params = params_cld;
cld->cld_sptlrpc = sptlrpc_cld;
mutex_unlock(&cld->cld_lock);
return cld;
out_cld:
config_log_put(cld);
out_params:
config_log_put(params_cld);
out_sptlrpc:
config_log_put(sptlrpc_cld);
out_err:
return ERR_PTR(rc);
}
static inline void config_mark_cld_stop(struct config_llog_data *cld)
{
mutex_lock(&cld->cld_lock);
spin_lock(&config_list_lock);
cld->cld_stopping = 1;
spin_unlock(&config_list_lock);
mutex_unlock(&cld->cld_lock);
}
static int config_log_end(char *logname, struct config_llog_instance *cfg)
{
struct config_llog_data *cld;
struct config_llog_data *cld_sptlrpc = NULL;
struct config_llog_data *cld_params = NULL;
struct config_llog_data *cld_recover = NULL;
int rc = 0;
cld = config_log_find(logname, cfg);
if (!cld)
return -ENOENT;
mutex_lock(&cld->cld_lock);
if (unlikely(cld->cld_stopping)) {
mutex_unlock(&cld->cld_lock);
config_log_put(cld);
return rc;
}
spin_lock(&config_list_lock);
cld->cld_stopping = 1;
spin_unlock(&config_list_lock);
cld_recover = cld->cld_recover;
cld->cld_recover = NULL;
cld_params = cld->cld_params;
cld->cld_params = NULL;
cld_sptlrpc = cld->cld_sptlrpc;
cld->cld_sptlrpc = NULL;
mutex_unlock(&cld->cld_lock);
if (cld_recover) {
config_mark_cld_stop(cld_recover);
config_log_put(cld_recover);
}
if (cld_params) {
config_mark_cld_stop(cld_params);
config_log_put(cld_params);
}
if (cld_sptlrpc)
config_log_put(cld_sptlrpc);
config_log_put(cld);
config_log_put(cld);
CDEBUG(D_MGC, "end config log %s (%d)\n", logname ? logname : "client",
rc);
return rc;
}
int lprocfs_mgc_rd_ir_state(struct seq_file *m, void *data)
{
struct obd_device *obd = data;
struct obd_import *imp;
struct obd_connect_data *ocd;
struct config_llog_data *cld;
int rc;
rc = lprocfs_climp_check(obd);
if (rc)
return rc;
imp = obd->u.cli.cl_import;
ocd = &imp->imp_connect_data;
seq_printf(m, "imperative_recovery: %s\n",
OCD_HAS_FLAG(ocd, IMP_RECOV) ? "ENABLED" : "DISABLED");
seq_printf(m, "client_state:\n");
spin_lock(&config_list_lock);
list_for_each_entry(cld, &config_llog_list, cld_list_chain) {
if (!cld->cld_recover)
continue;
seq_printf(m, " - { client: %s, nidtbl_version: %u }\n",
cld->cld_logname,
cld->cld_recover->cld_cfg.cfg_last_idx);
}
spin_unlock(&config_list_lock);
up_read(&obd->u.cli.cl_sem);
return 0;
}
static void do_requeue(struct config_llog_data *cld)
{
LASSERT(atomic_read(&cld->cld_refcount) > 0);
down_read_nested(&cld->cld_mgcexp->exp_obd->u.cli.cl_sem,
OBD_CLI_SEM_MGC);
if (cld->cld_mgcexp->exp_obd->u.cli.cl_conn_count != 0) {
int rc;
CDEBUG(D_MGC, "updating log %s\n", cld->cld_logname);
rc = mgc_process_log(cld->cld_mgcexp->exp_obd, cld);
if (rc && rc != -ENOENT)
CERROR("failed processing log: %d\n", rc);
} else {
CDEBUG(D_MGC, "disconnecting, won't update log %s\n",
cld->cld_logname);
}
up_read(&cld->cld_mgcexp->exp_obd->u.cli.cl_sem);
}
static int mgc_requeue_thread(void *data)
{
bool first = true;
CDEBUG(D_MGC, "Starting requeue thread\n");
spin_lock(&config_list_lock);
rq_state |= RQ_RUNNING;
while (!(rq_state & RQ_STOP)) {
struct l_wait_info lwi;
struct config_llog_data *cld, *cld_prev;
int rand = cfs_rand() & MGC_TIMEOUT_RAND_CENTISEC;
int to;
rq_state &= ~(RQ_NOW | RQ_LATER);
spin_unlock(&config_list_lock);
if (first) {
first = false;
complete(&rq_start);
}
to = msecs_to_jiffies(MGC_TIMEOUT_MIN_SECONDS * MSEC_PER_SEC);
to += msecs_to_jiffies(rand * MSEC_PER_SEC / 100);
lwi = LWI_TIMEOUT(to, NULL, NULL);
l_wait_event(rq_waitq, rq_state & (RQ_STOP | RQ_PRECLEANUP),
&lwi);
cld_prev = NULL;
spin_lock(&config_list_lock);
rq_state &= ~RQ_PRECLEANUP;
list_for_each_entry(cld, &config_llog_list, cld_list_chain) {
if (!cld->cld_lostlock || cld->cld_stopping)
continue;
config_log_get(cld);
cld->cld_lostlock = 0;
spin_unlock(&config_list_lock);
if (cld_prev)
config_log_put(cld_prev);
cld_prev = cld;
if (likely(!(rq_state & RQ_STOP))) {
do_requeue(cld);
spin_lock(&config_list_lock);
} else {
spin_lock(&config_list_lock);
break;
}
}
spin_unlock(&config_list_lock);
if (cld_prev)
config_log_put(cld_prev);
lwi = (struct l_wait_info) { 0 };
l_wait_event(rq_waitq, rq_state & (RQ_NOW | RQ_STOP),
&lwi);
spin_lock(&config_list_lock);
}
rq_state &= ~RQ_RUNNING;
spin_unlock(&config_list_lock);
complete(&rq_exit);
CDEBUG(D_MGC, "Ending requeue thread\n");
return 0;
}
static void mgc_requeue_add(struct config_llog_data *cld)
{
bool wakeup = false;
CDEBUG(D_INFO, "log %s: requeue (r=%d sp=%d st=%x)\n",
cld->cld_logname, atomic_read(&cld->cld_refcount),
cld->cld_stopping, rq_state);
LASSERT(atomic_read(&cld->cld_refcount) > 0);
mutex_lock(&cld->cld_lock);
spin_lock(&config_list_lock);
if (!(rq_state & RQ_STOP) && !cld->cld_stopping && !cld->cld_lostlock) {
cld->cld_lostlock = 1;
rq_state |= RQ_NOW;
wakeup = true;
}
spin_unlock(&config_list_lock);
mutex_unlock(&cld->cld_lock);
if (wakeup)
wake_up(&rq_waitq);
}
static int mgc_llog_init(const struct lu_env *env, struct obd_device *obd)
{
struct llog_ctxt *ctxt;
int rc;
rc = llog_setup(env, obd, &obd->obd_olg, LLOG_CONFIG_REPL_CTXT, obd,
&llog_client_ops);
if (rc)
return rc;
ctxt = llog_get_context(obd, LLOG_CONFIG_REPL_CTXT);
LASSERT(ctxt);
llog_initiator_connect(ctxt);
llog_ctxt_put(ctxt);
return 0;
}
static int mgc_llog_fini(const struct lu_env *env, struct obd_device *obd)
{
struct llog_ctxt *ctxt;
ctxt = llog_get_context(obd, LLOG_CONFIG_REPL_CTXT);
if (ctxt)
llog_cleanup(env, ctxt);
return 0;
}
static int mgc_precleanup(struct obd_device *obd)
{
int rc = 0;
int temp;
if (atomic_dec_and_test(&mgc_count)) {
LASSERT(rq_state & RQ_RUNNING);
temp = RQ_STOP;
} else {
temp = RQ_NOW | RQ_PRECLEANUP;
}
spin_lock(&config_list_lock);
rq_state |= temp;
spin_unlock(&config_list_lock);
wake_up(&rq_waitq);
if (temp & RQ_STOP)
wait_for_completion(&rq_exit);
obd_cleanup_client_import(obd);
rc = mgc_llog_fini(NULL, obd);
if (rc)
CERROR("failed to cleanup llogging subsystems\n");
return rc;
}
static int mgc_cleanup(struct obd_device *obd)
{
if (obd->obd_type->typ_refcnt <= 1)
class_del_profiles();
lprocfs_obd_cleanup(obd);
ptlrpcd_decref();
return client_obd_cleanup(obd);
}
static int mgc_setup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
struct lprocfs_static_vars lvars = { NULL };
struct task_struct *task;
int rc;
rc = ptlrpcd_addref();
if (rc < 0)
goto err_noref;
rc = client_obd_setup(obd, lcfg);
if (rc)
goto err_decref;
rc = mgc_llog_init(NULL, obd);
if (rc) {
CERROR("failed to setup llogging subsystems\n");
goto err_cleanup;
}
lprocfs_mgc_init_vars(&lvars);
lprocfs_obd_setup(obd, lvars.obd_vars, lvars.sysfs_vars);
sptlrpc_lprocfs_cliobd_attach(obd);
if (atomic_inc_return(&mgc_count) == 1) {
rq_state = 0;
init_waitqueue_head(&rq_waitq);
task = kthread_run(mgc_requeue_thread, NULL, "ll_cfg_requeue");
if (IS_ERR(task)) {
rc = PTR_ERR(task);
CERROR("%s: cannot start requeue thread: rc = %d; no more log updates\n",
obd->obd_name, rc);
goto err_cleanup;
}
rc = 0;
wait_for_completion(&rq_start);
}
return rc;
err_cleanup:
client_obd_cleanup(obd);
err_decref:
ptlrpcd_decref();
err_noref:
return rc;
}
static int mgc_blocking_ast(struct ldlm_lock *lock, struct ldlm_lock_desc *desc,
void *data, int flag)
{
struct lustre_handle lockh;
struct config_llog_data *cld = data;
int rc = 0;
switch (flag) {
case LDLM_CB_BLOCKING:
LDLM_DEBUG(lock, "MGC blocking CB");
ldlm_lock2handle(lock, &lockh);
rc = ldlm_cli_cancel(&lockh, LCF_ASYNC);
break;
case LDLM_CB_CANCELING:
LDLM_DEBUG(lock, "MGC cancel CB");
CDEBUG(D_MGC, "Lock res " DLDLMRES " (%.8s)\n",
PLDLMRES(lock->l_resource),
(char *)&lock->l_resource->lr_name.name[0]);
if (!cld) {
CDEBUG(D_INFO, "missing data, won't requeue\n");
break;
}
LASSERT(atomic_read(&cld->cld_refcount) > 0);
lock->l_ast_data = NULL;
if (cld->cld_stopping) {
CDEBUG(D_MGC, "log %s: stopping, won't requeue\n",
cld->cld_logname);
config_log_put(cld);
break;
}
if (!lock->l_conn_export ||
!lock->l_conn_export->exp_obd->u.cli.cl_conn_count) {
CDEBUG(D_MGC, "log %.8s: disconnecting, won't requeue\n",
cld->cld_logname);
config_log_put(cld);
break;
}
mgc_requeue_add(cld);
config_log_put(cld);
break;
default:
LBUG();
}
return rc;
}
static int mgc_set_mgs_param(struct obd_export *exp,
struct mgs_send_param *msp)
{
struct ptlrpc_request *req;
struct mgs_send_param *req_msp, *rep_msp;
int rc;
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp),
&RQF_MGS_SET_INFO, LUSTRE_MGS_VERSION,
MGS_SET_INFO);
if (!req)
return -ENOMEM;
req_msp = req_capsule_client_get(&req->rq_pill, &RMF_MGS_SEND_PARAM);
if (!req_msp) {
ptlrpc_req_finished(req);
return -ENOMEM;
}
memcpy(req_msp, msp, sizeof(*req_msp));
ptlrpc_request_set_replen(req);
req->rq_delay_limit = MGC_SEND_PARAM_LIMIT;
rc = ptlrpc_queue_wait(req);
if (!rc) {
rep_msp = req_capsule_server_get(&req->rq_pill, &RMF_MGS_SEND_PARAM);
memcpy(msp, rep_msp, sizeof(*rep_msp));
}
ptlrpc_req_finished(req);
return rc;
}
static int mgc_enqueue(struct obd_export *exp, __u32 type,
union ldlm_policy_data *policy, __u32 mode,
__u64 *flags, void *bl_cb, void *cp_cb, void *gl_cb,
void *data, __u32 lvb_len, void *lvb_swabber,
struct lustre_handle *lockh)
{
struct config_llog_data *cld = data;
struct ldlm_enqueue_info einfo = {
.ei_type = type,
.ei_mode = mode,
.ei_cb_bl = mgc_blocking_ast,
.ei_cb_cp = ldlm_completion_ast,
};
struct ptlrpc_request *req;
int short_limit = cld_is_sptlrpc(cld);
int rc;
CDEBUG(D_MGC, "Enqueue for %s (res %#llx)\n", cld->cld_logname,
cld->cld_resid.name[0]);
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp),
&RQF_LDLM_ENQUEUE, LUSTRE_DLM_VERSION,
LDLM_ENQUEUE);
if (!req)
return -ENOMEM;
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER, 0);
ptlrpc_request_set_replen(req);
req->rq_delay_limit = short_limit ? 5 : MGC_ENQUEUE_LIMIT;
rc = ldlm_cli_enqueue(exp, &req, &einfo, &cld->cld_resid, NULL, flags,
NULL, 0, LVB_T_NONE, lockh, 0);
ptlrpc_req_finished(req);
return rc;
}
static void mgc_notify_active(struct obd_device *unused)
{
spin_lock(&config_list_lock);
rq_state |= RQ_NOW;
spin_unlock(&config_list_lock);
wake_up(&rq_waitq);
}
static int mgc_target_register(struct obd_export *exp,
struct mgs_target_info *mti)
{
struct ptlrpc_request *req;
struct mgs_target_info *req_mti, *rep_mti;
int rc;
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp),
&RQF_MGS_TARGET_REG, LUSTRE_MGS_VERSION,
MGS_TARGET_REG);
if (!req)
return -ENOMEM;
req_mti = req_capsule_client_get(&req->rq_pill, &RMF_MGS_TARGET_INFO);
if (!req_mti) {
ptlrpc_req_finished(req);
return -ENOMEM;
}
memcpy(req_mti, mti, sizeof(*req_mti));
ptlrpc_request_set_replen(req);
CDEBUG(D_MGC, "register %s\n", mti->mti_svname);
req->rq_delay_limit = MGC_TARGET_REG_LIMIT;
rc = ptlrpc_queue_wait(req);
if (!rc) {
rep_mti = req_capsule_server_get(&req->rq_pill,
&RMF_MGS_TARGET_INFO);
memcpy(mti, rep_mti, sizeof(*rep_mti));
CDEBUG(D_MGC, "register %s got index = %d\n",
mti->mti_svname, mti->mti_stripe_index);
}
ptlrpc_req_finished(req);
return rc;
}
static int mgc_set_info_async(const struct lu_env *env, struct obd_export *exp,
u32 keylen, void *key, u32 vallen,
void *val, struct ptlrpc_request_set *set)
{
int rc = -EINVAL;
if (KEY_IS(KEY_INIT_RECOV_BACKUP)) {
struct obd_import *imp = class_exp2cliimp(exp);
int value;
if (vallen != sizeof(int))
return -EINVAL;
value = *(int *)val;
CDEBUG(D_MGC, "InitRecov %s %d/d%d:i%d:r%d:or%d:%s\n",
imp->imp_obd->obd_name, value,
imp->imp_deactive, imp->imp_invalid,
imp->imp_replayable, imp->imp_obd->obd_replayable,
ptlrpc_import_state_name(imp->imp_state));
if ((imp->imp_state != LUSTRE_IMP_FULL &&
imp->imp_state != LUSTRE_IMP_NEW) || value > 1)
ptlrpc_reconnect_import(imp);
return 0;
}
if (KEY_IS(KEY_SET_INFO)) {
struct mgs_send_param *msp;
msp = val;
rc = mgc_set_mgs_param(exp, msp);
return rc;
}
if (KEY_IS(KEY_MGSSEC)) {
struct client_obd *cli = &exp->exp_obd->u.cli;
struct sptlrpc_flavor flvr;
if (vallen == 0) {
if (cli->cl_flvr_mgc.sf_rpc != SPTLRPC_FLVR_INVALID)
return 0;
val = "null";
vallen = 4;
}
rc = sptlrpc_parse_flavor(val, &flvr);
if (rc) {
CERROR("invalid sptlrpc flavor %s to MGS\n",
(char *)val);
return rc;
}
if (cli->cl_flvr_mgc.sf_rpc == SPTLRPC_FLVR_INVALID) {
cli->cl_flvr_mgc = flvr;
} else if (memcmp(&cli->cl_flvr_mgc, &flvr,
sizeof(flvr)) != 0) {
char str[20];
sptlrpc_flavor2name(&cli->cl_flvr_mgc,
str, sizeof(str));
LCONSOLE_ERROR("asking sptlrpc flavor %s to MGS but currently %s is in use\n",
(char *)val, str);
rc = -EPERM;
}
return rc;
}
return rc;
}
static int mgc_get_info(const struct lu_env *env, struct obd_export *exp,
__u32 keylen, void *key, __u32 *vallen, void *val)
{
int rc = -EINVAL;
if (KEY_IS(KEY_CONN_DATA)) {
struct obd_import *imp = class_exp2cliimp(exp);
struct obd_connect_data *data = val;
if (*vallen == sizeof(*data)) {
*data = imp->imp_connect_data;
rc = 0;
}
}
return rc;
}
static int mgc_import_event(struct obd_device *obd,
struct obd_import *imp,
enum obd_import_event event)
{
LASSERT(imp->imp_obd == obd);
CDEBUG(D_MGC, "import event %#x\n", event);
switch (event) {
case IMP_EVENT_DISCON:
if (OCD_HAS_FLAG(&imp->imp_connect_data, IMP_RECOV))
ptlrpc_pinger_ir_down();
break;
case IMP_EVENT_INACTIVE:
break;
case IMP_EVENT_INVALIDATE: {
struct ldlm_namespace *ns = obd->obd_namespace;
ldlm_namespace_cleanup(ns, LDLM_FL_LOCAL_ONLY);
break;
}
case IMP_EVENT_ACTIVE:
CDEBUG(D_INFO, "%s: Reactivating import\n", obd->obd_name);
obd->obd_no_recov = 0;
mgc_notify_active(obd);
if (OCD_HAS_FLAG(&imp->imp_connect_data, IMP_RECOV))
ptlrpc_pinger_ir_up();
break;
case IMP_EVENT_OCD:
break;
case IMP_EVENT_DEACTIVATE:
case IMP_EVENT_ACTIVATE:
break;
default:
CERROR("Unknown import event %#x\n", event);
LBUG();
}
return 0;
}
static int mgc_apply_recover_logs(struct obd_device *mgc,
struct config_llog_data *cld,
__u64 max_version,
void *data, int datalen, bool mne_swab)
{
struct config_llog_instance *cfg = &cld->cld_cfg;
struct mgs_nidtbl_entry *entry;
struct lustre_cfg *lcfg;
struct lustre_cfg_bufs bufs;
u64 prev_version = 0;
char *inst;
char *buf;
int bufsz;
int pos;
int rc = 0;
int off = 0;
LASSERT(cfg->cfg_instance);
LASSERT(cfg->cfg_sb == cfg->cfg_instance);
inst = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!inst)
return -ENOMEM;
pos = snprintf(inst, PAGE_SIZE, "%p", cfg->cfg_instance);
if (pos >= PAGE_SIZE) {
kfree(inst);
return -E2BIG;
}
++pos;
buf = inst + pos;
bufsz = PAGE_SIZE - pos;
while (datalen > 0) {
int entry_len = sizeof(*entry);
int is_ost, i;
struct obd_device *obd;
char *obdname;
char *cname;
char *params;
char *uuid;
rc = -EINVAL;
if (datalen < sizeof(*entry))
break;
entry = (typeof(entry))(data + off);
if (entry->mne_nid_type != 0)
break;
if (entry->mne_nid_count == 0)
break;
if (entry->mne_nid_size != sizeof(lnet_nid_t))
break;
entry_len += entry->mne_nid_count * entry->mne_nid_size;
if (datalen < entry_len)
break;
if (mne_swab)
lustre_swab_mgs_nidtbl_entry(entry);
if (entry->mne_length > PAGE_SIZE) {
CERROR("MNE too large (%u)\n", entry->mne_length);
break;
}
if (entry->mne_length < entry_len)
break;
off += entry->mne_length;
datalen -= entry->mne_length;
if (datalen < 0)
break;
if (entry->mne_version > max_version) {
CERROR("entry index(%lld) is over max_index(%lld)\n",
entry->mne_version, max_version);
break;
}
if (prev_version >= entry->mne_version) {
CERROR("index unsorted, prev %lld, now %lld\n",
prev_version, entry->mne_version);
break;
}
prev_version = entry->mne_version;
is_ost = entry->mne_type == LDD_F_SV_TYPE_OST;
memset(buf, 0, bufsz);
obdname = buf;
pos = 0;
strcpy(obdname, cld->cld_logname);
cname = strrchr(obdname, '-');
if (!cname) {
CERROR("mgc %s: invalid logname %s\n",
mgc->obd_name, obdname);
break;
}
pos = cname - obdname;
obdname[pos] = 0;
pos += sprintf(obdname + pos, "-%s%04x",
is_ost ? "OST" : "MDT", entry->mne_index);
cname = is_ost ? "osc" : "mdc";
pos += sprintf(obdname + pos, "-%s-%s", cname, inst);
lustre_cfg_bufs_reset(&bufs, obdname);
obd = class_name2obd(obdname);
if (!obd) {
CDEBUG(D_INFO, "mgc %s: cannot find obdname %s\n",
mgc->obd_name, obdname);
rc = 0;
continue;
}
++pos;
params = buf + pos;
pos += sprintf(params, "%s.import=%s", cname, "connection=");
uuid = buf + pos;
down_read(&obd->u.cli.cl_sem);
if (!obd->u.cli.cl_import) {
up_read(&obd->u.cli.cl_sem);
rc = 0;
continue;
}
rc = -ENOENT;
for (i = 0; i < entry->mne_nid_count; i++) {
rc = client_import_find_conn(obd->u.cli.cl_import,
entry->u.nids[0],
(struct obd_uuid *)uuid);
if (!rc)
break;
}
up_read(&obd->u.cli.cl_sem);
if (rc < 0) {
CERROR("mgc: cannot find uuid by nid %s\n",
libcfs_nid2str(entry->u.nids[0]));
break;
}
CDEBUG(D_INFO, "Find uuid %s by nid %s\n",
uuid, libcfs_nid2str(entry->u.nids[0]));
pos += strlen(uuid);
pos += sprintf(buf + pos, "::%u", entry->mne_instance);
LASSERT(pos < bufsz);
lustre_cfg_bufs_set_string(&bufs, 1, params);
rc = -ENOMEM;
lcfg = lustre_cfg_new(LCFG_PARAM, &bufs);
if (IS_ERR(lcfg)) {
CERROR("mgc: cannot allocate memory\n");
break;
}
CDEBUG(D_INFO, "ir apply logs %lld/%lld for %s -> %s\n",
prev_version, max_version, obdname, params);
rc = class_process_config(lcfg);
lustre_cfg_free(lcfg);
if (rc)
CDEBUG(D_INFO, "process config for %s error %d\n",
obdname, rc);
}
kfree(inst);
return rc;
}
static int mgc_process_recover_log(struct obd_device *obd,
struct config_llog_data *cld)
{
struct ptlrpc_request *req = NULL;
struct config_llog_instance *cfg = &cld->cld_cfg;
struct mgs_config_body *body;
struct mgs_config_res *res;
struct ptlrpc_bulk_desc *desc;
struct page **pages;
int nrpages;
bool eof = true;
bool mne_swab;
int i;
int ealen;
int rc;
nrpages = CONFIG_READ_NRPAGES;
if (cfg->cfg_last_idx == 0)
nrpages = CONFIG_READ_NRPAGES_INIT;
pages = kcalloc(nrpages, sizeof(*pages), GFP_KERNEL);
if (!pages) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < nrpages; i++) {
pages[i] = alloc_page(GFP_KERNEL);
if (!pages[i]) {
rc = -ENOMEM;
goto out;
}
}
again:
LASSERT(cld_is_recover(cld));
LASSERT(mutex_is_locked(&cld->cld_lock));
req = ptlrpc_request_alloc(class_exp2cliimp(cld->cld_mgcexp),
&RQF_MGS_CONFIG_READ);
if (!req) {
rc = -ENOMEM;
goto out;
}
rc = ptlrpc_request_pack(req, LUSTRE_MGS_VERSION, MGS_CONFIG_READ);
if (rc)
goto out;
body = req_capsule_client_get(&req->rq_pill, &RMF_MGS_CONFIG_BODY);
LASSERT(sizeof(body->mcb_name) > strlen(cld->cld_logname));
if (strlcpy(body->mcb_name, cld->cld_logname, sizeof(body->mcb_name))
>= sizeof(body->mcb_name)) {
rc = -E2BIG;
goto out;
}
body->mcb_offset = cfg->cfg_last_idx + 1;
body->mcb_type = cld->cld_type;
body->mcb_bits = PAGE_SHIFT;
body->mcb_units = nrpages;
desc = ptlrpc_prep_bulk_imp(req, nrpages, 1,
PTLRPC_BULK_PUT_SINK | PTLRPC_BULK_BUF_KIOV,
MGS_BULK_PORTAL,
&ptlrpc_bulk_kiov_pin_ops);
if (!desc) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < nrpages; i++)
desc->bd_frag_ops->add_kiov_frag(desc, pages[i], 0, PAGE_SIZE);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc)
goto out;
res = req_capsule_server_get(&req->rq_pill, &RMF_MGS_CONFIG_RES);
if (res->mcr_size < res->mcr_offset) {
rc = -EINVAL;
goto out;
}
cfg->cfg_last_idx = res->mcr_offset;
eof = res->mcr_offset == res->mcr_size;
CDEBUG(D_INFO, "Latest version %lld, more %d.\n",
res->mcr_offset, eof == false);
ealen = sptlrpc_cli_unwrap_bulk_read(req, req->rq_bulk, 0);
if (ealen < 0) {
rc = ealen;
goto out;
}
if (ealen > nrpages << PAGE_SHIFT) {
rc = -EINVAL;
goto out;
}
if (ealen == 0) {
if (!eof)
rc = -EINVAL;
goto out;
}
mne_swab = !!ptlrpc_rep_need_swab(req);
#if OBD_OCD_VERSION(3, 0, 53, 0) > LUSTRE_VERSION_CODE
if (unlikely(req->rq_import->imp_need_mne_swab))
mne_swab = !mne_swab;
#endif
for (i = 0; i < nrpages && ealen > 0; i++) {
int rc2;
void *ptr;
ptr = kmap(pages[i]);
rc2 = mgc_apply_recover_logs(obd, cld, res->mcr_offset, ptr,
min_t(int, ealen, PAGE_SIZE),
mne_swab);
kunmap(pages[i]);
if (rc2 < 0) {
CWARN("Process recover log %s error %d\n",
cld->cld_logname, rc2);
break;
}
ealen -= PAGE_SIZE;
}
out:
if (req)
ptlrpc_req_finished(req);
if (rc == 0 && !eof)
goto again;
if (pages) {
for (i = 0; i < nrpages; i++) {
if (!pages[i])
break;
__free_page(pages[i]);
}
kfree(pages);
}
return rc;
}
static int mgc_process_cfg_log(struct obd_device *mgc,
struct config_llog_data *cld, int local_only)
{
struct llog_ctxt *ctxt;
struct lustre_sb_info *lsi = NULL;
int rc = 0;
bool sptlrpc_started = false;
struct lu_env *env;
LASSERT(cld);
LASSERT(mutex_is_locked(&cld->cld_lock));
if (cld_is_sptlrpc(cld) && local_only)
return 0;
if (cld->cld_cfg.cfg_sb)
lsi = s2lsi(cld->cld_cfg.cfg_sb);
env = kzalloc(sizeof(*env), GFP_KERNEL);
if (!env)
return -ENOMEM;
rc = lu_env_init(env, LCT_MG_THREAD);
if (rc)
goto out_free;
ctxt = llog_get_context(mgc, LLOG_CONFIG_REPL_CTXT);
LASSERT(ctxt);
if (local_only) {
rc = -EIO;
goto out_pop;
}
if (cld_is_sptlrpc(cld)) {
sptlrpc_conf_log_update_begin(cld->cld_logname);
sptlrpc_started = true;
}
rc = class_config_parse_llog(env, ctxt, cld->cld_logname,
&cld->cld_cfg);
out_pop:
__llog_ctxt_put(env, ctxt);
if (sptlrpc_started) {
LASSERT(cld_is_sptlrpc(cld));
sptlrpc_conf_log_update_end(cld->cld_logname);
class_notify_sptlrpc_conf(cld->cld_logname,
strlen(cld->cld_logname) -
strlen("-sptlrpc"));
}
lu_env_fini(env);
out_free:
kfree(env);
return rc;
}
static bool mgc_import_in_recovery(struct obd_import *imp)
{
bool in_recovery = true;
spin_lock(&imp->imp_lock);
if (imp->imp_state == LUSTRE_IMP_FULL ||
imp->imp_state == LUSTRE_IMP_CLOSED)
in_recovery = false;
spin_unlock(&imp->imp_lock);
return in_recovery;
}
int mgc_process_log(struct obd_device *mgc, struct config_llog_data *cld)
{
struct lustre_handle lockh = { 0 };
__u64 flags = LDLM_FL_NO_LRU;
bool retry = false;
int rc = 0, rcl;
LASSERT(cld);
restart:
mutex_lock(&cld->cld_lock);
if (cld->cld_stopping) {
mutex_unlock(&cld->cld_lock);
return 0;
}
OBD_FAIL_TIMEOUT(OBD_FAIL_MGC_PAUSE_PROCESS_LOG, 20);
CDEBUG(D_MGC, "Process log %s:%p from %d\n", cld->cld_logname,
cld->cld_cfg.cfg_instance, cld->cld_cfg.cfg_last_idx + 1);
rcl = mgc_enqueue(mgc->u.cli.cl_mgc_mgsexp, LDLM_PLAIN, NULL,
LCK_CR, &flags, NULL, NULL, NULL,
cld, 0, NULL, &lockh);
if (rcl == 0) {
config_log_get(cld);
rc = ldlm_lock_set_data(&lockh, (void *)cld);
LASSERT(rc == 0);
} else {
CDEBUG(D_MGC, "Can't get cfg lock: %d\n", rcl);
if (rcl == -ESHUTDOWN &&
atomic_read(&mgc->u.cli.cl_mgc_refcount) > 0 && !retry) {
int secs = cfs_time_seconds(obd_timeout);
struct obd_import *imp;
struct l_wait_info lwi;
mutex_unlock(&cld->cld_lock);
imp = class_exp2cliimp(mgc->u.cli.cl_mgc_mgsexp);
ptlrpc_pinger_force(imp);
lwi = LWI_TIMEOUT(secs, NULL, NULL);
l_wait_event(imp->imp_recovery_waitq,
!mgc_import_in_recovery(imp), &lwi);
if (imp->imp_state == LUSTRE_IMP_FULL) {
retry = true;
goto restart;
} else {
mutex_lock(&cld->cld_lock);
spin_lock(&config_list_lock);
cld->cld_lostlock = 1;
spin_unlock(&config_list_lock);
}
} else {
spin_lock(&config_list_lock);
cld->cld_lostlock = 1;
spin_unlock(&config_list_lock);
}
}
if (cld_is_recover(cld)) {
rc = 0;
if (!rcl) {
rc = mgc_process_recover_log(mgc, cld);
if (rc) {
CERROR("%s: recover log %s failed: rc = %d not fatal.\n",
mgc->obd_name, cld->cld_logname, rc);
rc = 0;
spin_lock(&config_list_lock);
cld->cld_lostlock = 1;
spin_unlock(&config_list_lock);
}
}
} else {
rc = mgc_process_cfg_log(mgc, cld, rcl != 0);
}
CDEBUG(D_MGC, "%s: configuration from log '%s' %sed (%d).\n",
mgc->obd_name, cld->cld_logname, rc ? "fail" : "succeed", rc);
mutex_unlock(&cld->cld_lock);
if (!rcl)
ldlm_lock_decref(&lockh, LCK_CR);
return rc;
}
static int mgc_process_config(struct obd_device *obd, u32 len, void *buf)
{
struct lustre_cfg *lcfg = buf;
struct config_llog_instance *cfg = NULL;
char *logname;
int rc = 0;
switch (lcfg->lcfg_command) {
case LCFG_LOV_ADD_OBD: {
struct mgs_target_info *mti;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) !=
sizeof(struct mgs_target_info)) {
rc = -EINVAL;
goto out;
}
mti = (struct mgs_target_info *)lustre_cfg_buf(lcfg, 1);
CDEBUG(D_MGC, "add_target %s %#x\n",
mti->mti_svname, mti->mti_flags);
rc = mgc_target_register(obd->u.cli.cl_mgc_mgsexp, mti);
break;
}
case LCFG_LOV_DEL_OBD:
CERROR("lov_del_obd unimplemented\n");
rc = -ENOSYS;
break;
case LCFG_SPTLRPC_CONF: {
rc = sptlrpc_process_config(lcfg);
break;
}
case LCFG_LOG_START: {
struct config_llog_data *cld;
struct super_block *sb;
logname = lustre_cfg_string(lcfg, 1);
cfg = (struct config_llog_instance *)lustre_cfg_buf(lcfg, 2);
sb = *(struct super_block **)lustre_cfg_buf(lcfg, 3);
CDEBUG(D_MGC, "parse_log %s from %d\n", logname,
cfg->cfg_last_idx);
cld = config_log_add(obd, logname, cfg, sb);
if (IS_ERR(cld)) {
rc = PTR_ERR(cld);
break;
}
cld->cld_cfg.cfg_flags |= CFG_F_COMPAT146;
rc = mgc_process_log(obd, cld);
if (rc == 0 && cld->cld_recover) {
if (OCD_HAS_FLAG(&obd->u.cli.cl_import->
imp_connect_data, IMP_RECOV)) {
rc = mgc_process_log(obd, cld->cld_recover);
} else {
struct config_llog_data *cir;
mutex_lock(&cld->cld_lock);
cir = cld->cld_recover;
cld->cld_recover = NULL;
mutex_unlock(&cld->cld_lock);
config_log_put(cir);
}
if (rc)
CERROR("Cannot process recover llog %d\n", rc);
}
if (rc == 0 && cld->cld_params) {
rc = mgc_process_log(obd, cld->cld_params);
if (rc == -ENOENT) {
CDEBUG(D_MGC,
"There is no params config file yet\n");
rc = 0;
}
if (rc)
CERROR(
"%s: can't process params llog: rc = %d\n",
obd->obd_name, rc);
}
break;
}
case LCFG_LOG_END: {
logname = lustre_cfg_string(lcfg, 1);
if (lcfg->lcfg_bufcount >= 2)
cfg = (struct config_llog_instance *)lustre_cfg_buf(
lcfg, 2);
rc = config_log_end(logname, cfg);
break;
}
default: {
CERROR("Unknown command: %d\n", lcfg->lcfg_command);
rc = -EINVAL;
goto out;
}
}
out:
return rc;
}
static int __init mgc_init(void)
{
return class_register_type(&mgc_obd_ops, NULL,
LUSTRE_MGC_NAME, NULL);
}
static void mgc_exit(void)
{
class_unregister_type(LUSTRE_MGC_NAME);
}
