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
CDEBUG(D_MGC, "log %s to resid "LPX64"/"LPX64" (%.8s)\n", name,
res_id->name[0], res_id->name[1], (char *)&res_id->name[0]);
return 0;
}
int mgc_fsname2resid(char *fsname, struct ldlm_res_id *res_id, int type)
{
return mgc_name2resid(fsname, strlen(fsname), res_id, type);
}
int mgc_logname2resid(char *logname, struct ldlm_res_id *res_id, int type)
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
if (cld->cld_sptlrpc)
config_log_put(cld->cld_sptlrpc);
if (cld->cld_params)
config_log_put(cld->cld_params);
if (cld_is_sptlrpc(cld))
sptlrpc_conf_log_stop(cld->cld_logname);
class_export_put(cld->cld_mgcexp);
OBD_FREE(cld, sizeof(*cld) + strlen(cld->cld_logname) + 1);
}
}
static
struct config_llog_data *config_log_find(char *logname,
struct config_llog_instance *cfg)
{
struct config_llog_data *cld;
struct config_llog_data *found = NULL;
void * instance;
LASSERT(logname != NULL);
instance = cfg ? cfg->cfg_instance : NULL;
spin_lock(&config_list_lock);
list_for_each_entry(cld, &config_llog_list, cld_list_chain) {
if (instance != cld->cld_cfg.cfg_instance)
continue;
if (strcmp(logname, cld->cld_logname) == 0) {
found = cld;
break;
}
}
if (found) {
atomic_inc(&found->cld_refcount);
LASSERT(found->cld_stopping == 0 || cld_is_sptlrpc(found) == 0);
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
cfg ? cfg->cfg_instance : 0);
OBD_ALLOC(cld, sizeof(*cld) + strlen(logname) + 1);
if (!cld)
return ERR_PTR(-ENOMEM);
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
rc = mgc_logname2resid(logname, &cld->cld_resid, type);
spin_lock(&config_list_lock);
list_add(&cld->cld_list_chain, &config_llog_list);
spin_unlock(&config_list_lock);
if (rc) {
config_log_put(cld);
return ERR_PTR(rc);
}
if (cld_is_sptlrpc(cld)) {
rc = mgc_process_log(obd, cld);
if (rc && rc != -ENOENT)
CERROR("failed processing sptlrpc log: %d\n", rc);
}
return cld;
}
static struct config_llog_data *config_recover_log_add(struct obd_device *obd,
char *fsname,
struct config_llog_instance *cfg,
struct super_block *sb)
{
struct config_llog_instance lcfg = *cfg;
struct lustre_sb_info *lsi = s2lsi(sb);
struct config_llog_data *cld;
char logname[32];
if (IS_OST(lsi))
return NULL;
if (IS_MDT(lsi) && lcfg.cfg_instance)
return NULL;
LASSERT(strlen(fsname) < sizeof(logname) / 2);
strcpy(logname, fsname);
if (IS_SERVER(lsi)) {
LASSERT(lcfg.cfg_instance == NULL);
lcfg.cfg_instance = sb;
strcat(logname, "-mdtir");
} else {
LASSERT(lcfg.cfg_instance != NULL);
strcat(logname, "-cliir");
}
cld = do_config_log_add(obd, logname, CONFIG_T_RECOVER, &lcfg, sb);
return cld;
}
static struct config_llog_data *config_params_log_add(struct obd_device *obd,
struct config_llog_instance *cfg, struct super_block *sb)
{
struct config_llog_instance lcfg = *cfg;
struct config_llog_data *cld;
lcfg.cfg_instance = sb;
cld = do_config_log_add(obd, PARAMS_FILENAME, CONFIG_T_PARAMS,
&lcfg, sb);
return cld;
}
static int config_log_add(struct obd_device *obd, char *logname,
struct config_llog_instance *cfg,
struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
struct config_llog_data *cld;
struct config_llog_data *sptlrpc_cld;
struct config_llog_data *params_cld;
char seclogname[32];
char *ptr;
int rc;
CDEBUG(D_MGC, "adding config log %s:%p\n", logname, cfg->cfg_instance);
ptr = strrchr(logname, '-');
if (ptr == NULL || ptr - logname > 8) {
CERROR("logname %s is too long\n", logname);
return -EINVAL;
}
memcpy(seclogname, logname, ptr - logname);
strcpy(seclogname + (ptr - logname), "-sptlrpc");
sptlrpc_cld = config_log_find(seclogname, NULL);
if (sptlrpc_cld == NULL) {
sptlrpc_cld = do_config_log_add(obd, seclogname,
CONFIG_T_SPTLRPC, NULL, NULL);
if (IS_ERR(sptlrpc_cld)) {
CERROR("can't create sptlrpc log: %s\n", seclogname);
GOTO(out_err, rc = PTR_ERR(sptlrpc_cld));
}
}
params_cld = config_params_log_add(obd, cfg, sb);
if (IS_ERR(params_cld)) {
rc = PTR_ERR(params_cld);
CERROR("%s: can't create params log: rc = %d\n",
obd->obd_name, rc);
GOTO(out_err1, rc);
}
cld = do_config_log_add(obd, logname, CONFIG_T_CONFIG, cfg, sb);
if (IS_ERR(cld)) {
CERROR("can't create log: %s\n", logname);
GOTO(out_err2, rc = PTR_ERR(cld));
}
cld->cld_sptlrpc = sptlrpc_cld;
cld->cld_params = params_cld;
LASSERT(lsi->lsi_lmd);
if (!(lsi->lsi_lmd->lmd_flags & LMD_FLG_NOIR)) {
struct config_llog_data *recover_cld;
*strrchr(seclogname, '-') = 0;
recover_cld = config_recover_log_add(obd, seclogname, cfg, sb);
if (IS_ERR(recover_cld))
GOTO(out_err3, rc = PTR_ERR(recover_cld));
cld->cld_recover = recover_cld;
}
return 0;
out_err3:
config_log_put(cld);
out_err2:
config_log_put(params_cld);
out_err1:
config_log_put(sptlrpc_cld);
out_err:
return rc;
}
static int config_log_end(char *logname, struct config_llog_instance *cfg)
{
struct config_llog_data *cld;
struct config_llog_data *cld_sptlrpc = NULL;
struct config_llog_data *cld_params = NULL;
struct config_llog_data *cld_recover = NULL;
int rc = 0;
cld = config_log_find(logname, cfg);
if (cld == NULL)
return -ENOENT;
mutex_lock(&cld->cld_lock);
if (unlikely(cld->cld_stopping)) {
mutex_unlock(&cld->cld_lock);
config_log_put(cld);
return rc;
}
cld->cld_stopping = 1;
cld_recover = cld->cld_recover;
cld->cld_recover = NULL;
mutex_unlock(&cld->cld_lock);
if (cld_recover) {
mutex_lock(&cld_recover->cld_lock);
cld_recover->cld_stopping = 1;
mutex_unlock(&cld_recover->cld_lock);
config_log_put(cld_recover);
}
spin_lock(&config_list_lock);
cld_sptlrpc = cld->cld_sptlrpc;
cld->cld_sptlrpc = NULL;
cld_params = cld->cld_params;
cld->cld_params = NULL;
spin_unlock(&config_list_lock);
if (cld_sptlrpc)
config_log_put(cld_sptlrpc);
if (cld_params) {
mutex_lock(&cld_params->cld_lock);
cld_params->cld_stopping = 1;
mutex_unlock(&cld_params->cld_lock);
config_log_put(cld_params);
}
config_log_put(cld);
config_log_put(cld);
CDEBUG(D_MGC, "end config log %s (%d)\n", logname ? logname : "client",
rc);
return rc;
}
int lprocfs_mgc_rd_ir_state(struct seq_file *m, void *data)
{
struct obd_device *obd = data;
struct obd_import *imp = obd->u.cli.cl_import;
struct obd_connect_data *ocd = &imp->imp_connect_data;
struct config_llog_data *cld;
seq_printf(m, "imperative_recovery: %s\n",
OCD_HAS_FLAG(ocd, IMP_RECOV) ? "ENABLED" : "DISABLED");
seq_printf(m, "client_state:\n");
spin_lock(&config_list_lock);
list_for_each_entry(cld, &config_llog_list, cld_list_chain) {
if (cld->cld_recover == NULL)
continue;
seq_printf(m, " - { client: %s, nidtbl_version: %u }\n",
cld->cld_logname,
cld->cld_recover->cld_cfg.cfg_last_idx);
}
spin_unlock(&config_list_lock);
return 0;
}
static void do_requeue(struct config_llog_data *cld)
{
LASSERT(atomic_read(&cld->cld_refcount) > 0);
down_read(&cld->cld_mgcexp->exp_obd->u.cli.cl_sem);
if (cld->cld_mgcexp->exp_obd->u.cli.cl_conn_count != 0) {
CDEBUG(D_MGC, "updating log %s\n", cld->cld_logname);
mgc_process_log(cld->cld_mgcexp->exp_obd, cld);
} else {
CDEBUG(D_MGC, "disconnecting, won't update log %s\n",
cld->cld_logname);
}
up_read(&cld->cld_mgcexp->exp_obd->u.cli.cl_sem);
}
static int mgc_requeue_thread(void *data)
{
int rc = 0;
CDEBUG(D_MGC, "Starting requeue thread\n");
spin_lock(&config_list_lock);
rq_state |= RQ_RUNNING;
while (1) {
struct l_wait_info lwi;
struct config_llog_data *cld, *cld_prev;
int rand = cfs_rand() & MGC_TIMEOUT_RAND_CENTISEC;
int stopped = !!(rq_state & RQ_STOP);
int to;
rq_state &= ~(RQ_NOW | RQ_LATER);
spin_unlock(&config_list_lock);
to = MGC_TIMEOUT_MIN_SECONDS * HZ;
to += rand * HZ / 100;
lwi = LWI_TIMEOUT(to, NULL, NULL);
l_wait_event(rq_waitq, rq_state & RQ_STOP, &lwi);
cld_prev = NULL;
spin_lock(&config_list_lock);
list_for_each_entry(cld, &config_llog_list,
cld_list_chain) {
if (!cld->cld_lostlock)
continue;
spin_unlock(&config_list_lock);
LASSERT(atomic_read(&cld->cld_refcount) > 0);
if (cld_prev)
config_log_put(cld_prev);
cld_prev = cld;
cld->cld_lostlock = 0;
if (likely(!stopped))
do_requeue(cld);
spin_lock(&config_list_lock);
}
spin_unlock(&config_list_lock);
if (cld_prev)
config_log_put(cld_prev);
if (unlikely(stopped)) {
spin_lock(&config_list_lock);
break;
}
lwi = (struct l_wait_info) { 0 };
l_wait_event(rq_waitq, rq_state & (RQ_NOW | RQ_STOP),
&lwi);
spin_lock(&config_list_lock);
}
rq_state &= ~RQ_RUNNING;
spin_unlock(&config_list_lock);
complete(&rq_exit);
CDEBUG(D_MGC, "Ending requeue thread\n");
return rc;
}
static void mgc_requeue_add(struct config_llog_data *cld)
{
CDEBUG(D_INFO, "log %s: requeue (r=%d sp=%d st=%x)\n",
cld->cld_logname, atomic_read(&cld->cld_refcount),
cld->cld_stopping, rq_state);
LASSERT(atomic_read(&cld->cld_refcount) > 0);
mutex_lock(&cld->cld_lock);
if (cld->cld_stopping || cld->cld_lostlock) {
mutex_unlock(&cld->cld_lock);
return;
}
config_log_get(cld);
cld->cld_lostlock = 1;
mutex_unlock(&cld->cld_lock);
spin_lock(&config_list_lock);
if (rq_state & RQ_STOP) {
spin_unlock(&config_list_lock);
cld->cld_lostlock = 0;
config_log_put(cld);
} else {
rq_state |= RQ_NOW;
spin_unlock(&config_list_lock);
wake_up(&rq_waitq);
}
}
static int mgc_local_llog_init(const struct lu_env *env,
struct obd_device *obd,
struct obd_device *disk)
{
struct llog_ctxt *ctxt;
int rc;
rc = llog_setup(env, obd, &obd->obd_olg, LLOG_CONFIG_ORIG_CTXT, disk,
&llog_osd_ops);
if (rc)
return rc;
ctxt = llog_get_context(obd, LLOG_CONFIG_ORIG_CTXT);
LASSERT(ctxt);
ctxt->loc_dir = obd->u.cli.cl_mgc_configs_dir;
llog_ctxt_put(ctxt);
return 0;
}
static int mgc_local_llog_fini(const struct lu_env *env,
struct obd_device *obd)
{
struct llog_ctxt *ctxt;
ctxt = llog_get_context(obd, LLOG_CONFIG_ORIG_CTXT);
llog_cleanup(env, ctxt);
return 0;
}
static int mgc_fs_setup(struct obd_device *obd, struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
struct client_obd *cli = &obd->u.cli;
struct lu_fid rfid, fid;
struct dt_object *root, *dto;
struct lu_env *env;
int rc = 0;
LASSERT(lsi);
LASSERT(lsi->lsi_dt_dev);
OBD_ALLOC_PTR(env);
if (env == NULL)
return -ENOMEM;
down(&cli->cl_mgc_sem);
cfs_cleanup_group_info();
rc = lu_env_init(env, LCT_MG_THREAD);
if (rc)
GOTO(out_err, rc);
fid.f_seq = FID_SEQ_LOCAL_NAME;
fid.f_oid = 1;
fid.f_ver = 0;
rc = local_oid_storage_init(env, lsi->lsi_dt_dev, &fid,
&cli->cl_mgc_los);
if (rc)
GOTO(out_env, rc);
rc = dt_root_get(env, lsi->lsi_dt_dev, &rfid);
if (rc)
GOTO(out_env, rc);
root = dt_locate_at(env, lsi->lsi_dt_dev, &rfid,
&cli->cl_mgc_los->los_dev->dd_lu_dev);
if (unlikely(IS_ERR(root)))
GOTO(out_los, rc = PTR_ERR(root));
dto = local_file_find_or_create(env, cli->cl_mgc_los, root,
MOUNT_CONFIGS_DIR,
S_IFDIR | S_IRUGO | S_IWUSR | S_IXUGO);
lu_object_put_nocache(env, &root->do_lu);
if (IS_ERR(dto))
GOTO(out_los, rc = PTR_ERR(dto));
cli->cl_mgc_configs_dir = dto;
LASSERT(lsi->lsi_osd_exp->exp_obd->obd_lvfs_ctxt.dt);
rc = mgc_local_llog_init(env, obd, lsi->lsi_osd_exp->exp_obd);
if (rc)
GOTO(out_llog, rc);
class_incref(obd, "mgc_fs", obd);
out_llog:
if (rc) {
lu_object_put(env, &cli->cl_mgc_configs_dir->do_lu);
cli->cl_mgc_configs_dir = NULL;
}
out_los:
if (rc < 0) {
local_oid_storage_fini(env, cli->cl_mgc_los);
cli->cl_mgc_los = NULL;
up(&cli->cl_mgc_sem);
}
out_env:
lu_env_fini(env);
out_err:
OBD_FREE_PTR(env);
return rc;
}
static int mgc_fs_cleanup(struct obd_device *obd)
{
struct lu_env env;
struct client_obd *cli = &obd->u.cli;
int rc;
LASSERT(cli->cl_mgc_los != NULL);
rc = lu_env_init(&env, LCT_MG_THREAD);
if (rc)
GOTO(unlock, rc);
mgc_local_llog_fini(&env, obd);
lu_object_put_nocache(&env, &cli->cl_mgc_configs_dir->do_lu);
cli->cl_mgc_configs_dir = NULL;
local_oid_storage_fini(&env, cli->cl_mgc_los);
cli->cl_mgc_los = NULL;
lu_env_fini(&env);
unlock:
class_decref(obd, "mgc_fs", obd);
up(&cli->cl_mgc_sem);
return 0;
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
static int mgc_precleanup(struct obd_device *obd, enum obd_cleanup_stage stage)
{
int rc = 0;
switch (stage) {
case OBD_CLEANUP_EARLY:
break;
case OBD_CLEANUP_EXPORTS:
if (atomic_dec_and_test(&mgc_count)) {
int running;
spin_lock(&config_list_lock);
running = rq_state & RQ_RUNNING;
if (running)
rq_state |= RQ_STOP;
spin_unlock(&config_list_lock);
if (running) {
wake_up(&rq_waitq);
wait_for_completion(&rq_exit);
}
}
obd_cleanup_client_import(obd);
rc = mgc_llog_fini(NULL, obd);
if (rc != 0)
CERROR("failed to cleanup llogging subsystems\n");
break;
}
return rc;
}
static int mgc_cleanup(struct obd_device *obd)
{
int rc;
if (obd->obd_type->typ_refcnt <= 1)
class_del_profiles();
lprocfs_obd_cleanup(obd);
ptlrpcd_decref();
rc = client_obd_cleanup(obd);
return rc;
}
static int mgc_setup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
struct lprocfs_static_vars lvars;
int rc;
ptlrpcd_addref();
rc = client_obd_setup(obd, lcfg);
if (rc)
GOTO(err_decref, rc);
rc = mgc_llog_init(NULL, obd);
if (rc) {
CERROR("failed to setup llogging subsystems\n");
GOTO(err_cleanup, rc);
}
lprocfs_mgc_init_vars(&lvars);
lprocfs_obd_setup(obd, lvars.obd_vars);
sptlrpc_lprocfs_cliobd_attach(obd);
if (atomic_inc_return(&mgc_count) == 1) {
rq_state = 0;
init_waitqueue_head(&rq_waitq);
rc = PTR_ERR(kthread_run(mgc_requeue_thread, NULL,
"ll_cfg_requeue"));
if (IS_ERR_VALUE(rc)) {
CERROR("%s: Cannot start requeue thread (%d),"
"no more log updates!\n",
obd->obd_name, rc);
GOTO(err_cleanup, rc);
}
rc = 0;
}
return rc;
err_cleanup:
client_obd_cleanup(obd);
err_decref:
ptlrpcd_decref();
return rc;
}
static int mgc_blocking_ast(struct ldlm_lock *lock, struct ldlm_lock_desc *desc,
void *data, int flag)
{
struct lustre_handle lockh;
struct config_llog_data *cld = (struct config_llog_data *)data;
int rc = 0;
switch (flag) {
case LDLM_CB_BLOCKING:
LDLM_DEBUG(lock, "MGC blocking CB");
ldlm_lock2handle(lock, &lockh);
rc = ldlm_cli_cancel(&lockh, LCF_ASYNC);
break;
case LDLM_CB_CANCELING:
LDLM_DEBUG(lock, "MGC cancel CB");
CDEBUG(D_MGC, "Lock res "DLDLMRES" (%.8s)\n",
PLDLMRES(lock->l_resource),
(char *)&lock->l_resource->lr_name.name[0]);
if (!cld) {
CDEBUG(D_INFO, "missing data, won't requeue\n");
break;
}
LASSERT(atomic_read(&cld->cld_refcount) > 0);
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
static int mgc_enqueue(struct obd_export *exp, struct lov_stripe_md *lsm,
__u32 type, ldlm_policy_data_t *policy, __u32 mode,
__u64 *flags, void *bl_cb, void *cp_cb, void *gl_cb,
void *data, __u32 lvb_len, void *lvb_swabber,
struct lustre_handle *lockh)
{
struct config_llog_data *cld = (struct config_llog_data *)data;
struct ldlm_enqueue_info einfo = {
.ei_type = type,
.ei_mode = mode,
.ei_cb_bl = mgc_blocking_ast,
.ei_cb_cp = ldlm_completion_ast,
};
struct ptlrpc_request *req;
int short_limit = cld_is_sptlrpc(cld);
int rc;
CDEBUG(D_MGC, "Enqueue for %s (res "LPX64")\n", cld->cld_logname,
cld->cld_resid.name[0]);
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp),
&RQF_LDLM_ENQUEUE, LUSTRE_DLM_VERSION,
LDLM_ENQUEUE);
if (req == NULL)
return -ENOMEM;
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER, 0);
ptlrpc_request_set_replen(req);
if (cld->cld_cfg.cfg_sb) {
struct lustre_sb_info *lsi = s2lsi(cld->cld_cfg.cfg_sb);
if (lsi && IS_SERVER(lsi))
short_limit = 1;
}
req->rq_delay_limit = short_limit ? 5 : MGC_ENQUEUE_LIMIT;
rc = ldlm_cli_enqueue(exp, &req, &einfo, &cld->cld_resid, NULL, flags,
NULL, 0, LVB_T_NONE, lockh, 0);
ptlrpc_req_finished(req);
return rc;
}
static int mgc_cancel(struct obd_export *exp, struct lov_stripe_md *md,
__u32 mode, struct lustre_handle *lockh)
{
ldlm_lock_decref(lockh, mode);
return 0;
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
if (req == NULL)
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
int mgc_set_info_async(const struct lu_env *env, struct obd_export *exp,
obd_count keylen, void *key, obd_count vallen,
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
if (KEY_IS(KEY_REGISTER_TARGET)) {
struct mgs_target_info *mti;
if (vallen != sizeof(struct mgs_target_info))
return -EINVAL;
mti = (struct mgs_target_info *)val;
CDEBUG(D_MGC, "register_target %s %#x\n",
mti->mti_svname, mti->mti_flags);
rc = mgc_target_register(exp, mti);
return rc;
}
if (KEY_IS(KEY_SET_FS)) {
struct super_block *sb = (struct super_block *)val;
if (vallen != sizeof(struct super_block))
return -EINVAL;
rc = mgc_fs_setup(exp->exp_obd, sb);
if (rc)
CERROR("set_fs got %d\n", rc);
return rc;
}
if (KEY_IS(KEY_CLEAR_FS)) {
if (vallen != 0)
return -EINVAL;
rc = mgc_fs_cleanup(exp->exp_obd);
if (rc)
CERROR("clear_fs got %d\n", rc);
return rc;
}
if (KEY_IS(KEY_SET_INFO)) {
struct mgs_send_param *msp;
msp = (struct mgs_send_param *)val;
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
(char *) val);
return rc;
}
if (cli->cl_flvr_mgc.sf_rpc == SPTLRPC_FLVR_INVALID) {
cli->cl_flvr_mgc = flvr;
} else if (memcmp(&cli->cl_flvr_mgc, &flvr,
sizeof(flvr)) != 0) {
char str[20];
sptlrpc_flavor2name(&cli->cl_flvr_mgc,
str, sizeof(str));
LCONSOLE_ERROR("asking sptlrpc flavor %s to MGS but "
"currently %s is in use\n",
(char *) val, str);
rc = -EPERM;
}
return rc;
}
return rc;
}
static int mgc_get_info(const struct lu_env *env, struct obd_export *exp,
__u32 keylen, void *key, __u32 *vallen, void *val,
struct lov_stripe_md *unused)
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
int rc = 0;
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
return rc;
}
static int mgc_apply_recover_logs(struct obd_device *mgc,
struct config_llog_data *cld,
__u64 max_version,
void *data, int datalen, bool mne_swab)
{
struct config_llog_instance *cfg = &cld->cld_cfg;
struct lustre_sb_info *lsi = s2lsi(cfg->cfg_sb);
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
LASSERT(cfg->cfg_instance != NULL);
LASSERT(cfg->cfg_sb == cfg->cfg_instance);
OBD_ALLOC(inst, PAGE_CACHE_SIZE);
if (inst == NULL)
return -ENOMEM;
if (!IS_SERVER(lsi)) {
pos = snprintf(inst, PAGE_CACHE_SIZE, "%p", cfg->cfg_instance);
if (pos >= PAGE_CACHE_SIZE) {
OBD_FREE(inst, PAGE_CACHE_SIZE);
return -E2BIG;
}
} else {
LASSERT(IS_MDT(lsi));
rc = server_name2svname(lsi->lsi_svname, inst, NULL,
PAGE_CACHE_SIZE);
if (rc) {
OBD_FREE(inst, PAGE_CACHE_SIZE);
return -EINVAL;
}
pos = strlen(inst);
}
++pos;
buf = inst + pos;
bufsz = PAGE_CACHE_SIZE - pos;
while (datalen > 0) {
int entry_len = sizeof(*entry);
int is_ost;
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
if (entry->mne_length > PAGE_CACHE_SIZE) {
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
if (cname == NULL) {
CERROR("mgc %s: invalid logname %s\n",
mgc->obd_name, obdname);
break;
}
pos = cname - obdname;
obdname[pos] = 0;
pos += sprintf(obdname + pos, "-%s%04x",
is_ost ? "OST" : "MDT", entry->mne_index);
cname = is_ost ? "osc" : "mdc",
pos += sprintf(obdname + pos, "-%s-%s", cname, inst);
lustre_cfg_bufs_reset(&bufs, obdname);
obd = class_name2obd(obdname);
if (obd == NULL) {
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
if (obd->u.cli.cl_import == NULL) {
up_read(&obd->u.cli.cl_sem);
rc = 0;
continue;
}
rc = client_import_find_conn(obd->u.cli.cl_import,
entry->u.nids[0],
(struct obd_uuid *)uuid);
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
if (lcfg == NULL) {
CERROR("mgc: cannot allocate memory\n");
break;
}
CDEBUG(D_INFO, "ir apply logs "LPD64"/"LPD64" for %s -> %s\n",
prev_version, max_version, obdname, params);
rc = class_process_config(lcfg);
lustre_cfg_free(lcfg);
if (rc)
CDEBUG(D_INFO, "process config for %s error %d\n",
obdname, rc);
}
OBD_FREE(inst, PAGE_CACHE_SIZE);
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
bool mne_swab = false;
int i;
int ealen;
int rc;
nrpages = CONFIG_READ_NRPAGES;
if (cfg->cfg_last_idx == 0)
nrpages = CONFIG_READ_NRPAGES_INIT;
OBD_ALLOC(pages, sizeof(*pages) * nrpages);
if (pages == NULL)
GOTO(out, rc = -ENOMEM);
for (i = 0; i < nrpages; i++) {
pages[i] = alloc_page(GFP_IOFS);
if (pages[i] == NULL)
GOTO(out, rc = -ENOMEM);
}
again:
LASSERT(cld_is_recover(cld));
LASSERT(mutex_is_locked(&cld->cld_lock));
req = ptlrpc_request_alloc(class_exp2cliimp(cld->cld_mgcexp),
&RQF_MGS_CONFIG_READ);
if (req == NULL)
GOTO(out, rc = -ENOMEM);
rc = ptlrpc_request_pack(req, LUSTRE_MGS_VERSION, MGS_CONFIG_READ);
if (rc)
GOTO(out, rc);
body = req_capsule_client_get(&req->rq_pill, &RMF_MGS_CONFIG_BODY);
LASSERT(body != NULL);
LASSERT(sizeof(body->mcb_name) > strlen(cld->cld_logname));
if (strlcpy(body->mcb_name, cld->cld_logname, sizeof(body->mcb_name))
>= sizeof(body->mcb_name))
GOTO(out, rc = -E2BIG);
body->mcb_offset = cfg->cfg_last_idx + 1;
body->mcb_type = cld->cld_type;
body->mcb_bits = PAGE_CACHE_SHIFT;
body->mcb_units = nrpages;
desc = ptlrpc_prep_bulk_imp(req, nrpages, 1, BULK_PUT_SINK,
MGS_BULK_PORTAL);
if (desc == NULL)
GOTO(out, rc = -ENOMEM);
for (i = 0; i < nrpages; i++)
ptlrpc_prep_bulk_page_pin(desc, pages[i], 0, PAGE_CACHE_SIZE);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc)
GOTO(out, rc);
res = req_capsule_server_get(&req->rq_pill, &RMF_MGS_CONFIG_RES);
if (res->mcr_size < res->mcr_offset)
GOTO(out, rc = -EINVAL);
cfg->cfg_last_idx = res->mcr_offset;
eof = res->mcr_offset == res->mcr_size;
CDEBUG(D_INFO, "Latest version "LPD64", more %d.\n",
res->mcr_offset, eof == false);
ealen = sptlrpc_cli_unwrap_bulk_read(req, req->rq_bulk, 0);
if (ealen < 0)
GOTO(out, rc = ealen);
if (ealen > nrpages << PAGE_CACHE_SHIFT)
GOTO(out, rc = -EINVAL);
if (ealen == 0) {
if (!eof)
rc = -EINVAL;
GOTO(out, rc);
}
mne_swab = !!ptlrpc_rep_need_swab(req);
#if LUSTRE_VERSION_CODE < OBD_OCD_VERSION(3, 2, 50, 0)
if (unlikely(req->rq_import->imp_need_mne_swab))
mne_swab = !mne_swab;
#else
#warning "LU-1644: Remove old OBD_CONNECT_MNE_SWAB fixup and imp_need_mne_swab"
#endif
for (i = 0; i < nrpages && ealen > 0; i++) {
int rc2;
void *ptr;
ptr = kmap(pages[i]);
rc2 = mgc_apply_recover_logs(obd, cld, res->mcr_offset, ptr,
min_t(int, ealen, PAGE_CACHE_SIZE),
mne_swab);
kunmap(pages[i]);
if (rc2 < 0) {
CWARN("Process recover log %s error %d\n",
cld->cld_logname, rc2);
break;
}
ealen -= PAGE_CACHE_SIZE;
}
out:
if (req)
ptlrpc_req_finished(req);
if (rc == 0 && !eof)
goto again;
if (pages) {
for (i = 0; i < nrpages; i++) {
if (pages[i] == NULL)
break;
__free_page(pages[i]);
}
OBD_FREE(pages, sizeof(*pages) * nrpages);
}
return rc;
}
static int mgc_llog_local_copy(const struct lu_env *env,
struct obd_device *obd,
struct llog_ctxt *rctxt,
struct llog_ctxt *lctxt, char *logname)
{
char *temp_log;
int rc;
OBD_ALLOC(temp_log, strlen(logname) + 1);
if (!temp_log)
return -ENOMEM;
sprintf(temp_log, "%sT", logname);
rc = llog_backup(env, obd, lctxt, lctxt, logname, temp_log);
if (rc < 0 && rc != -ENOENT)
GOTO(out, rc);
rc = llog_backup(env, obd, rctxt, lctxt, logname, logname);
if (rc == -ENOENT) {
llog_erase(env, lctxt, NULL, logname);
} else if (rc < 0) {
llog_backup(env, obd, lctxt, lctxt, temp_log, logname);
out:
CERROR("%s: failed to copy remote log %s: rc = %d\n",
obd->obd_name, logname, rc);
}
llog_erase(env, lctxt, NULL, temp_log);
OBD_FREE(temp_log, strlen(logname) + 1);
return rc;
}
static int mgc_process_cfg_log(struct obd_device *mgc,
struct config_llog_data *cld, int local_only)
{
struct llog_ctxt *ctxt, *lctxt = NULL;
struct dt_object *cl_mgc_dir = mgc->u.cli.cl_mgc_configs_dir;
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
OBD_ALLOC_PTR(env);
if (env == NULL)
return -ENOMEM;
rc = lu_env_init(env, LCT_MG_THREAD);
if (rc)
GOTO(out_free, rc);
ctxt = llog_get_context(mgc, LLOG_CONFIG_REPL_CTXT);
LASSERT(ctxt);
lctxt = llog_get_context(mgc, LLOG_CONFIG_ORIG_CTXT);
if (lctxt && lsi && IS_SERVER(lsi) && !IS_MGS(lsi) &&
cl_mgc_dir != NULL &&
lu2dt_dev(cl_mgc_dir->do_lu.lo_dev) == lsi->lsi_dt_dev) {
if (!local_only)
rc = mgc_llog_local_copy(env, mgc, ctxt, lctxt,
cld->cld_logname);
if (local_only || rc) {
if (llog_is_empty(env, lctxt, cld->cld_logname)) {
LCONSOLE_ERROR_MSG(0x13a,
"Failed to get MGS log %s and no local copy.\n",
cld->cld_logname);
GOTO(out_pop, rc = -ENOENT);
}
CDEBUG(D_MGC,
"Failed to get MGS log %s, using local copy for now, will try to update later.\n",
cld->cld_logname);
}
llog_ctxt_put(ctxt);
ctxt = lctxt;
lctxt = NULL;
} else {
if (local_only)
GOTO(out_pop, rc = -EIO);
}
if (cld_is_sptlrpc(cld)) {
sptlrpc_conf_log_update_begin(cld->cld_logname);
sptlrpc_started = true;
}
rc = class_config_parse_llog(env, ctxt, cld->cld_logname,
&cld->cld_cfg);
out_pop:
__llog_ctxt_put(env, ctxt);
if (lctxt)
__llog_ctxt_put(env, lctxt);
if (sptlrpc_started) {
LASSERT(cld_is_sptlrpc(cld));
sptlrpc_conf_log_update_end(cld->cld_logname);
class_notify_sptlrpc_conf(cld->cld_logname,
strlen(cld->cld_logname) -
strlen("-sptlrpc"));
}
lu_env_fini(env);
out_free:
OBD_FREE_PTR(env);
return rc;
}
int mgc_process_log(struct obd_device *mgc, struct config_llog_data *cld)
{
struct lustre_handle lockh = { 0 };
__u64 flags = LDLM_FL_NO_LRU;
int rc = 0, rcl;
LASSERT(cld);
mutex_lock(&cld->cld_lock);
if (cld->cld_stopping) {
mutex_unlock(&cld->cld_lock);
return 0;
}
OBD_FAIL_TIMEOUT(OBD_FAIL_MGC_PAUSE_PROCESS_LOG, 20);
CDEBUG(D_MGC, "Process log %s:%p from %d\n", cld->cld_logname,
cld->cld_cfg.cfg_instance, cld->cld_cfg.cfg_last_idx + 1);
rcl = mgc_enqueue(mgc->u.cli.cl_mgc_mgsexp, NULL, LDLM_PLAIN, NULL,
LCK_CR, &flags, NULL, NULL, NULL,
cld, 0, NULL, &lockh);
if (rcl == 0) {
config_log_get(cld);
rc = ldlm_lock_set_data(&lockh, (void *)cld);
LASSERT(rc == 0);
} else {
CDEBUG(D_MGC, "Can't get cfg lock: %d\n", rcl);
cld->cld_lostlock = 1;
config_log_get(cld);
}
if (cld_is_recover(cld)) {
rc = 0;
if (rcl == 0)
rc = mgc_process_recover_log(mgc, cld);
} else {
rc = mgc_process_cfg_log(mgc, cld, rcl != 0);
}
CDEBUG(D_MGC, "%s: configuration from log '%s' %sed (%d).\n",
mgc->obd_name, cld->cld_logname, rc ? "fail" : "succeed", rc);
mutex_unlock(&cld->cld_lock);
if (!rcl) {
rcl = mgc_cancel(mgc->u.cli.cl_mgc_mgsexp, NULL,
LCK_CR, &lockh);
if (rcl)
CERROR("Can't drop cfg lock: %d\n", rcl);
}
return rc;
}
static int mgc_process_config(struct obd_device *obd, obd_count len, void *buf)
{
struct lustre_cfg *lcfg = buf;
struct config_llog_instance *cfg = NULL;
char *logname;
int rc = 0;
switch (lcfg->lcfg_command) {
case LCFG_LOV_ADD_OBD: {
struct mgs_target_info *mti;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) !=
sizeof(struct mgs_target_info))
GOTO(out, rc = -EINVAL);
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
rc = config_log_add(obd, logname, cfg, sb);
if (rc)
break;
cld = config_log_find(logname, cfg);
if (cld == NULL) {
rc = -ENOENT;
break;
}
cld->cld_cfg.cfg_flags |= CFG_F_COMPAT146;
rc = mgc_process_log(obd, cld);
if (rc == 0 && cld->cld_recover != NULL) {
if (OCD_HAS_FLAG(&obd->u.cli.cl_import->
imp_connect_data, IMP_RECOV)) {
rc = mgc_process_log(obd, cld->cld_recover);
} else {
struct config_llog_data *cir = cld->cld_recover;
cld->cld_recover = NULL;
config_log_put(cir);
}
if (rc)
CERROR("Cannot process recover llog %d\n", rc);
}
if (rc == 0 && cld->cld_params != NULL) {
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
config_log_put(cld);
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
GOTO(out, rc = -EINVAL);
}
}
out:
return rc;
}
int __init mgc_init(void)
{
return class_register_type(&mgc_obd_ops, NULL, NULL,
LUSTRE_MGC_NAME, NULL);
}
static void mgc_exit(void)
{
class_unregister_type(LUSTRE_MGC_NAME);
}
