int client_fid_init(struct obd_device *obd,
struct obd_export *exp, enum lu_cli_type type)
{
struct client_obd *cli = &obd->u.cli;
char *prefix;
int rc;
ENTRY;
OBD_ALLOC_PTR(cli->cl_seq);
if (cli->cl_seq == NULL)
RETURN(-ENOMEM);
OBD_ALLOC(prefix, MAX_OBD_NAME + 5);
if (prefix == NULL)
GOTO(out_free_seq, rc = -ENOMEM);
snprintf(prefix, MAX_OBD_NAME + 5, "cli-%s", obd->obd_name);
rc = seq_client_init(cli->cl_seq, exp, type, prefix, NULL);
OBD_FREE(prefix, MAX_OBD_NAME + 5);
if (rc)
GOTO(out_free_seq, rc);
RETURN(rc);
out_free_seq:
OBD_FREE_PTR(cli->cl_seq);
cli->cl_seq = NULL;
return rc;
}
int client_fid_fini(struct obd_device *obd)
{
struct client_obd *cli = &obd->u.cli;
ENTRY;
if (cli->cl_seq != NULL) {
seq_client_fini(cli->cl_seq);
OBD_FREE_PTR(cli->cl_seq);
cli->cl_seq = NULL;
}
RETURN(0);
}
int seq_server_set_cli(struct lu_server_seq *seq,
struct lu_client_seq *cli,
const struct lu_env *env)
{
int rc = 0;
ENTRY;
mutex_lock(&seq->lss_mutex);
if (cli == NULL) {
CDEBUG(D_INFO, "%s: Detached sequence client %s\n",
seq->lss_name, cli->lcs_name);
seq->lss_cli = cli;
GOTO(out_up, rc = 0);
}
if (seq->lss_cli != NULL) {
CDEBUG(D_HA, "%s: Sequence controller is already "
"assigned\n", seq->lss_name);
GOTO(out_up, rc = -EEXIST);
}
CDEBUG(D_INFO, "%s: Attached sequence controller %s\n",
seq->lss_name, cli->lcs_name);
seq->lss_cli = cli;
cli->lcs_space.lsr_index = seq->lss_site->ss_node_id;
EXIT;
out_up:
mutex_unlock(&seq->lss_mutex);
return rc;
}
static inline void range_alloc(struct lu_seq_range *to,
struct lu_seq_range *from,
__u64 width)
{
width = min(range_space(from), width);
to->lsr_start = from->lsr_start;
to->lsr_end = from->lsr_start + width;
from->lsr_start += width;
}
static int __seq_server_alloc_super(struct lu_server_seq *seq,
struct lu_seq_range *out,
const struct lu_env *env)
{
struct lu_seq_range *space = &seq->lss_space;
int rc;
ENTRY;
LASSERT(range_is_sane(space));
if (range_is_exhausted(space)) {
CERROR("%s: Sequences space is exhausted\n",
seq->lss_name);
RETURN(-ENOSPC);
} else {
range_alloc(out, space, seq->lss_width);
}
rc = seq_store_update(env, seq, out, 1 );
LCONSOLE_INFO("%s: super-sequence allocation rc = %d " DRANGE"\n",
seq->lss_name, rc, PRANGE(out));
RETURN(rc);
}
int seq_server_alloc_super(struct lu_server_seq *seq,
struct lu_seq_range *out,
const struct lu_env *env)
{
int rc;
ENTRY;
mutex_lock(&seq->lss_mutex);
rc = __seq_server_alloc_super(seq, out, env);
mutex_unlock(&seq->lss_mutex);
RETURN(rc);
}
static int __seq_set_init(const struct lu_env *env,
struct lu_server_seq *seq)
{
struct lu_seq_range *space = &seq->lss_space;
int rc;
range_alloc(&seq->lss_lowater_set, space, seq->lss_set_width);
range_alloc(&seq->lss_hiwater_set, space, seq->lss_set_width);
rc = seq_store_update(env, seq, NULL, 1);
return rc;
}
static int range_alloc_set(const struct lu_env *env,
struct lu_seq_range *out,
struct lu_server_seq *seq)
{
struct lu_seq_range *space = &seq->lss_space;
struct lu_seq_range *loset = &seq->lss_lowater_set;
struct lu_seq_range *hiset = &seq->lss_hiwater_set;
int rc = 0;
if (range_is_zero(loset))
__seq_set_init(env, seq);
if (OBD_FAIL_CHECK(OBD_FAIL_SEQ_ALLOC))
loset->lsr_start = loset->lsr_end;
if (range_is_exhausted(loset)) {
struct lu_device *dev = seq->lss_site->ss_lu->ls_top_dev;
int obd_num_clients = dev->ld_obd->obd_num_exports;
__u64 set_sz;
set_sz = max(seq->lss_set_width,
obd_num_clients * seq->lss_width);
set_sz = min(range_space(space), set_sz);
*loset = *hiset;
range_alloc(hiset, space, set_sz);
rc = seq_store_update(env, seq, NULL, seq->lss_need_sync);
}
LASSERTF(!range_is_exhausted(loset) || range_is_sane(loset),
DRANGE"\n", PRANGE(loset));
if (rc == 0)
range_alloc(out, loset, seq->lss_width);
RETURN(rc);
}
static int __seq_server_alloc_meta(struct lu_server_seq *seq,
struct lu_seq_range *out,
const struct lu_env *env)
{
struct lu_seq_range *space = &seq->lss_space;
int rc = 0;
ENTRY;
LASSERT(range_is_sane(space));
if (range_is_exhausted(space)) {
if (!seq->lss_cli) {
CERROR("%s: No sequence controller is attached.\n",
seq->lss_name);
RETURN(-ENODEV);
}
rc = seq_client_alloc_super(seq->lss_cli, env);
if (rc) {
CERROR("%s: Can't allocate super-sequence, rc %d\n",
seq->lss_name, rc);
RETURN(rc);
}
*space = seq->lss_cli->lcs_space;
LASSERT(range_is_sane(space));
}
rc = range_alloc_set(env, out, seq);
if (rc != 0) {
CERROR("%s: Allocated meta-sequence failed: rc = %d\n",
seq->lss_name, rc);
RETURN(rc);
}
CDEBUG(D_INFO, "%s: Allocated meta-sequence " DRANGE"\n",
seq->lss_name, PRANGE(out));
RETURN(rc);
}
int seq_server_alloc_meta(struct lu_server_seq *seq,
struct lu_seq_range *out,
const struct lu_env *env)
{
int rc;
ENTRY;
mutex_lock(&seq->lss_mutex);
rc = __seq_server_alloc_meta(seq, out, env);
mutex_unlock(&seq->lss_mutex);
RETURN(rc);
}
static int seq_server_handle(struct lu_site *site,
const struct lu_env *env,
__u32 opc, struct lu_seq_range *out)
{
int rc;
struct seq_server_site *ss_site;
ENTRY;
ss_site = lu_site2seq(site);
switch (opc) {
case SEQ_ALLOC_META:
if (!ss_site->ss_server_seq) {
CERROR("Sequence server is not "
"initialized\n");
RETURN(-EINVAL);
}
rc = seq_server_alloc_meta(ss_site->ss_server_seq, out, env);
break;
case SEQ_ALLOC_SUPER:
if (!ss_site->ss_control_seq) {
CERROR("Sequence controller is not "
"initialized\n");
RETURN(-EINVAL);
}
rc = seq_server_alloc_super(ss_site->ss_control_seq, out, env);
break;
default:
rc = -EINVAL;
break;
}
RETURN(rc);
}
static int seq_req_handle(struct ptlrpc_request *req,
const struct lu_env *env,
struct seq_thread_info *info)
{
struct lu_seq_range *out, *tmp;
struct lu_site *site;
int rc = -EPROTO;
__u32 *opc;
ENTRY;
LASSERT(!(lustre_msg_get_flags(req->rq_reqmsg) & MSG_REPLAY));
site = req->rq_export->exp_obd->obd_lu_dev->ld_site;
LASSERT(site != NULL);
rc = req_capsule_server_pack(info->sti_pill);
if (rc)
RETURN(err_serious(rc));
opc = req_capsule_client_get(info->sti_pill, &RMF_SEQ_OPC);
if (opc != NULL) {
out = req_capsule_server_get(info->sti_pill, &RMF_SEQ_RANGE);
if (out == NULL)
RETURN(err_serious(-EPROTO));
tmp = req_capsule_client_get(info->sti_pill, &RMF_SEQ_RANGE);
out->lsr_index = tmp->lsr_index;
out->lsr_flags = tmp->lsr_flags;
rc = seq_server_handle(site, env, *opc, out);
} else
rc = err_serious(-EPROTO);
RETURN(rc);
}
static void seq_thread_info_init(struct ptlrpc_request *req,
struct seq_thread_info *info)
{
info->sti_pill = &req->rq_pill;
req_capsule_init(info->sti_pill, req, RCL_SERVER);
req_capsule_set(info->sti_pill, &RQF_SEQ_QUERY);
}
static void seq_thread_info_fini(struct seq_thread_info *info)
{
req_capsule_fini(info->sti_pill);
}
int seq_handle(struct ptlrpc_request *req)
{
const struct lu_env *env;
struct seq_thread_info *info;
int rc;
env = req->rq_svc_thread->t_env;
LASSERT(env != NULL);
info = lu_context_key_get(&env->le_ctx, &seq_thread_key);
LASSERT(info != NULL);
seq_thread_info_init(req, info);
rc = seq_req_handle(req, env, info);
lustre_msg_set_transno(req->rq_repmsg, 0);
seq_thread_info_fini(info);
return rc;
}
int seq_query(struct com_thread_info *info)
{
return seq_handle(info->cti_pill->rc_req);
}
static int seq_server_proc_init(struct lu_server_seq *seq)
{
int rc;
ENTRY;
seq->lss_proc_dir = lprocfs_register(seq->lss_name,
seq_type_proc_dir,
NULL, NULL);
if (IS_ERR(seq->lss_proc_dir)) {
rc = PTR_ERR(seq->lss_proc_dir);
RETURN(rc);
}
rc = lprocfs_add_vars(seq->lss_proc_dir,
seq_server_proc_list, seq);
if (rc) {
CERROR("%s: Can't init sequence manager "
"proc, rc %d\n", seq->lss_name, rc);
GOTO(out_cleanup, rc);
}
RETURN(0);
out_cleanup:
seq_server_proc_fini(seq);
return rc;
}
static void seq_server_proc_fini(struct lu_server_seq *seq)
{
ENTRY;
if (seq->lss_proc_dir != NULL) {
if (!IS_ERR(seq->lss_proc_dir))
lprocfs_remove(&seq->lss_proc_dir);
seq->lss_proc_dir = NULL;
}
EXIT;
}
static int seq_server_proc_init(struct lu_server_seq *seq)
{
return 0;
}
static void seq_server_proc_fini(struct lu_server_seq *seq)
{
return;
}
int seq_server_init(struct lu_server_seq *seq,
struct dt_device *dev,
const char *prefix,
enum lu_mgr_type type,
struct seq_server_site *ss,
const struct lu_env *env)
{
int rc, is_srv = (type == LUSTRE_SEQ_SERVER);
ENTRY;
LASSERT(dev != NULL);
LASSERT(prefix != NULL);
LASSERT(ss != NULL);
LASSERT(ss->ss_lu != NULL);
seq->lss_cli = NULL;
seq->lss_type = type;
seq->lss_site = ss;
range_init(&seq->lss_space);
range_init(&seq->lss_lowater_set);
range_init(&seq->lss_hiwater_set);
seq->lss_set_width = LUSTRE_SEQ_BATCH_WIDTH;
mutex_init(&seq->lss_mutex);
seq->lss_width = is_srv ?
LUSTRE_SEQ_META_WIDTH : LUSTRE_SEQ_SUPER_WIDTH;
snprintf(seq->lss_name, sizeof(seq->lss_name),
"%s-%s", (is_srv ? "srv" : "ctl"), prefix);
rc = seq_store_init(seq, env, dev);
if (rc)
GOTO(out, rc);
rc = seq_store_read(seq, env);
if (rc == -ENODATA) {
seq->lss_space = is_srv ?
LUSTRE_SEQ_ZERO_RANGE:
LUSTRE_SEQ_SPACE_RANGE;
LASSERT(ss != NULL);
seq->lss_space.lsr_index = ss->ss_node_id;
LCONSOLE_INFO("%s: No data found "
"on store. Initialize space\n",
seq->lss_name);
rc = seq_store_update(env, seq, NULL, 0);
if (rc) {
CERROR("%s: Can't write space data, "
"rc %d\n", seq->lss_name, rc);
}
} else if (rc) {
CERROR("%s: Can't read space data, rc %d\n",
seq->lss_name, rc);
GOTO(out, rc);
}
if (is_srv) {
LASSERT(range_is_sane(&seq->lss_space));
} else {
LASSERT(!range_is_zero(&seq->lss_space) &&
range_is_sane(&seq->lss_space));
}
rc = seq_server_proc_init(seq);
if (rc)
GOTO(out, rc);
EXIT;
out:
if (rc)
seq_server_fini(seq, env);
return rc;
}
void seq_server_fini(struct lu_server_seq *seq,
const struct lu_env *env)
{
ENTRY;
seq_server_proc_fini(seq);
seq_store_fini(seq, env);
EXIT;
}
int seq_site_fini(const struct lu_env *env, struct seq_server_site *ss)
{
if (ss == NULL)
RETURN(0);
if (ss->ss_server_seq) {
seq_server_fini(ss->ss_server_seq, env);
OBD_FREE_PTR(ss->ss_server_seq);
ss->ss_server_seq = NULL;
}
if (ss->ss_control_seq) {
seq_server_fini(ss->ss_control_seq, env);
OBD_FREE_PTR(ss->ss_control_seq);
ss->ss_control_seq = NULL;
}
if (ss->ss_client_seq) {
seq_client_fini(ss->ss_client_seq);
OBD_FREE_PTR(ss->ss_client_seq);
ss->ss_client_seq = NULL;
}
RETURN(0);
}
static int __init fid_mod_init(void)
{
seq_type_proc_dir = lprocfs_register(LUSTRE_SEQ_NAME,
proc_lustre_root,
NULL, NULL);
if (IS_ERR(seq_type_proc_dir))
return PTR_ERR(seq_type_proc_dir);
LU_CONTEXT_KEY_INIT(&seq_thread_key);
lu_context_key_register(&seq_thread_key);
return 0;
}
static void __exit fid_mod_exit(void)
{
lu_context_key_degister(&seq_thread_key);
if (seq_type_proc_dir != NULL && !IS_ERR(seq_type_proc_dir)) {
lprocfs_remove(&seq_type_proc_dir);
seq_type_proc_dir = NULL;
}
}
