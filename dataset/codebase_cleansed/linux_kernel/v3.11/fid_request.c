static int seq_client_rpc(struct lu_client_seq *seq,
struct lu_seq_range *output, __u32 opc,
const char *opcname)
{
struct obd_export *exp = seq->lcs_exp;
struct ptlrpc_request *req;
struct lu_seq_range *out, *in;
__u32 *op;
unsigned int debug_mask;
int rc;
ENTRY;
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp), &RQF_SEQ_QUERY,
LUSTRE_MDS_VERSION, SEQ_QUERY);
if (req == NULL)
RETURN(-ENOMEM);
op = req_capsule_client_get(&req->rq_pill, &RMF_SEQ_OPC);
*op = opc;
in = req_capsule_client_get(&req->rq_pill, &RMF_SEQ_RANGE);
range_init(in);
ptlrpc_request_set_replen(req);
in->lsr_index = seq->lcs_space.lsr_index;
if (seq->lcs_type == LUSTRE_SEQ_METADATA)
fld_range_set_mdt(in);
else
fld_range_set_ost(in);
if (opc == SEQ_ALLOC_SUPER) {
req->rq_request_portal = SEQ_CONTROLLER_PORTAL;
req->rq_reply_portal = MDC_REPLY_PORTAL;
if (seq->lcs_type == LUSTRE_SEQ_DATA)
req->rq_no_delay = req->rq_no_resend = 1;
debug_mask = D_CONSOLE;
} else {
if (seq->lcs_type == LUSTRE_SEQ_METADATA)
req->rq_request_portal = SEQ_METADATA_PORTAL;
else
req->rq_request_portal = SEQ_DATA_PORTAL;
debug_mask = D_INFO;
}
ptlrpc_at_set_req_timeout(req);
if (seq->lcs_type == LUSTRE_SEQ_METADATA)
mdc_get_rpc_lock(exp->exp_obd->u.cli.cl_rpc_lock, NULL);
rc = ptlrpc_queue_wait(req);
if (seq->lcs_type == LUSTRE_SEQ_METADATA)
mdc_put_rpc_lock(exp->exp_obd->u.cli.cl_rpc_lock, NULL);
if (rc)
GOTO(out_req, rc);
out = req_capsule_server_get(&req->rq_pill, &RMF_SEQ_RANGE);
*output = *out;
if (!range_is_sane(output)) {
CERROR("%s: Invalid range received from server: "
DRANGE"\n", seq->lcs_name, PRANGE(output));
GOTO(out_req, rc = -EINVAL);
}
if (range_is_exhausted(output)) {
CERROR("%s: Range received from server is exhausted: "
DRANGE"]\n", seq->lcs_name, PRANGE(output));
GOTO(out_req, rc = -EINVAL);
}
CDEBUG_LIMIT(debug_mask, "%s: Allocated %s-sequence "DRANGE"]\n",
seq->lcs_name, opcname, PRANGE(output));
EXIT;
out_req:
ptlrpc_req_finished(req);
return rc;
}
int seq_client_alloc_super(struct lu_client_seq *seq,
const struct lu_env *env)
{
int rc;
ENTRY;
mutex_lock(&seq->lcs_mutex);
if (seq->lcs_srv) {
LASSERT(env != NULL);
rc = seq_server_alloc_super(seq->lcs_srv, &seq->lcs_space,
env);
} else {
if (seq->lcs_exp == NULL) {
mutex_unlock(&seq->lcs_mutex);
RETURN(-EINPROGRESS);
}
rc = seq_client_rpc(seq, &seq->lcs_space,
SEQ_ALLOC_SUPER, "super");
}
mutex_unlock(&seq->lcs_mutex);
RETURN(rc);
}
static int seq_client_alloc_meta(const struct lu_env *env,
struct lu_client_seq *seq)
{
int rc;
ENTRY;
if (seq->lcs_srv) {
LASSERT(env != NULL);
rc = seq_server_alloc_meta(seq->lcs_srv, &seq->lcs_space, env);
} else {
do {
rc = seq_client_rpc(seq, &seq->lcs_space,
SEQ_ALLOC_META, "meta");
} while (rc == -EINPROGRESS || rc == -EAGAIN);
}
RETURN(rc);
}
static int seq_client_alloc_seq(const struct lu_env *env,
struct lu_client_seq *seq, seqno_t *seqnr)
{
int rc;
ENTRY;
LASSERT(range_is_sane(&seq->lcs_space));
if (range_is_exhausted(&seq->lcs_space)) {
rc = seq_client_alloc_meta(env, seq);
if (rc) {
CERROR("%s: Can't allocate new meta-sequence,"
"rc %d\n", seq->lcs_name, rc);
RETURN(rc);
} else {
CDEBUG(D_INFO, "%s: New range - "DRANGE"\n",
seq->lcs_name, PRANGE(&seq->lcs_space));
}
} else {
rc = 0;
}
LASSERT(!range_is_exhausted(&seq->lcs_space));
*seqnr = seq->lcs_space.lsr_start;
seq->lcs_space.lsr_start += 1;
CDEBUG(D_INFO, "%s: Allocated sequence ["LPX64"]\n", seq->lcs_name,
*seqnr);
RETURN(rc);
}
static int seq_fid_alloc_prep(struct lu_client_seq *seq,
wait_queue_t *link)
{
if (seq->lcs_update) {
add_wait_queue(&seq->lcs_waitq, link);
set_current_state(TASK_UNINTERRUPTIBLE);
mutex_unlock(&seq->lcs_mutex);
waitq_wait(link, TASK_UNINTERRUPTIBLE);
mutex_lock(&seq->lcs_mutex);
remove_wait_queue(&seq->lcs_waitq, link);
set_current_state(TASK_RUNNING);
return -EAGAIN;
}
++seq->lcs_update;
mutex_unlock(&seq->lcs_mutex);
return 0;
}
static void seq_fid_alloc_fini(struct lu_client_seq *seq)
{
LASSERT(seq->lcs_update == 1);
mutex_lock(&seq->lcs_mutex);
--seq->lcs_update;
wake_up(&seq->lcs_waitq);
}
int seq_client_get_seq(const struct lu_env *env,
struct lu_client_seq *seq, seqno_t *seqnr)
{
wait_queue_t link;
int rc;
LASSERT(seqnr != NULL);
mutex_lock(&seq->lcs_mutex);
init_waitqueue_entry_current(&link);
while (1) {
rc = seq_fid_alloc_prep(seq, &link);
if (rc == 0)
break;
}
rc = seq_client_alloc_seq(env, seq, seqnr);
if (rc) {
CERROR("%s: Can't allocate new sequence, "
"rc %d\n", seq->lcs_name, rc);
seq_fid_alloc_fini(seq);
mutex_unlock(&seq->lcs_mutex);
return rc;
}
CDEBUG(D_INFO, "%s: allocate sequence "
"[0x%16.16"LPF64"x]\n", seq->lcs_name, *seqnr);
if (seq->lcs_type == LUSTRE_SEQ_METADATA)
seq->lcs_fid.f_oid = LUSTRE_METADATA_SEQ_MAX_WIDTH;
else
seq->lcs_fid.f_oid = LUSTRE_DATA_SEQ_MAX_WIDTH;
seq->lcs_fid.f_seq = *seqnr;
seq->lcs_fid.f_ver = 0;
seq_fid_alloc_fini(seq);
mutex_unlock(&seq->lcs_mutex);
return rc;
}
int seq_client_alloc_fid(const struct lu_env *env,
struct lu_client_seq *seq, struct lu_fid *fid)
{
wait_queue_t link;
int rc;
ENTRY;
LASSERT(seq != NULL);
LASSERT(fid != NULL);
init_waitqueue_entry_current(&link);
mutex_lock(&seq->lcs_mutex);
if (OBD_FAIL_CHECK(OBD_FAIL_SEQ_EXHAUST))
seq->lcs_fid.f_oid = seq->lcs_width;
while (1) {
seqno_t seqnr;
if (!fid_is_zero(&seq->lcs_fid) &&
fid_oid(&seq->lcs_fid) < seq->lcs_width) {
seq->lcs_fid.f_oid += 1;
rc = 0;
break;
}
rc = seq_fid_alloc_prep(seq, &link);
if (rc)
continue;
rc = seq_client_alloc_seq(env, seq, &seqnr);
if (rc) {
CERROR("%s: Can't allocate new sequence, "
"rc %d\n", seq->lcs_name, rc);
seq_fid_alloc_fini(seq);
mutex_unlock(&seq->lcs_mutex);
RETURN(rc);
}
CDEBUG(D_INFO, "%s: Switch to sequence "
"[0x%16.16"LPF64"x]\n", seq->lcs_name, seqnr);
seq->lcs_fid.f_oid = LUSTRE_FID_INIT_OID;
seq->lcs_fid.f_seq = seqnr;
seq->lcs_fid.f_ver = 0;
rc = 1;
seq_fid_alloc_fini(seq);
break;
}
*fid = seq->lcs_fid;
mutex_unlock(&seq->lcs_mutex);
CDEBUG(D_INFO, "%s: Allocated FID "DFID"\n", seq->lcs_name, PFID(fid));
RETURN(rc);
}
void seq_client_flush(struct lu_client_seq *seq)
{
wait_queue_t link;
LASSERT(seq != NULL);
init_waitqueue_entry_current(&link);
mutex_lock(&seq->lcs_mutex);
while (seq->lcs_update) {
add_wait_queue(&seq->lcs_waitq, &link);
set_current_state(TASK_UNINTERRUPTIBLE);
mutex_unlock(&seq->lcs_mutex);
waitq_wait(&link, TASK_UNINTERRUPTIBLE);
mutex_lock(&seq->lcs_mutex);
remove_wait_queue(&seq->lcs_waitq, &link);
set_current_state(TASK_RUNNING);
}
fid_zero(&seq->lcs_fid);
seq->lcs_space.lsr_index = -1;
range_init(&seq->lcs_space);
mutex_unlock(&seq->lcs_mutex);
}
static int seq_client_proc_init(struct lu_client_seq *seq)
{
int rc;
ENTRY;
seq->lcs_proc_dir = lprocfs_register(seq->lcs_name,
seq_type_proc_dir,
NULL, NULL);
if (IS_ERR(seq->lcs_proc_dir)) {
CERROR("%s: LProcFS failed in seq-init\n",
seq->lcs_name);
rc = PTR_ERR(seq->lcs_proc_dir);
RETURN(rc);
}
rc = lprocfs_add_vars(seq->lcs_proc_dir,
seq_client_proc_list, seq);
if (rc) {
CERROR("%s: Can't init sequence manager "
"proc, rc %d\n", seq->lcs_name, rc);
GOTO(out_cleanup, rc);
}
RETURN(0);
out_cleanup:
seq_client_proc_fini(seq);
return rc;
}
static void seq_client_proc_fini(struct lu_client_seq *seq)
{
ENTRY;
if (seq->lcs_proc_dir) {
if (!IS_ERR(seq->lcs_proc_dir))
lprocfs_remove(&seq->lcs_proc_dir);
seq->lcs_proc_dir = NULL;
}
EXIT;
}
static int seq_client_proc_init(struct lu_client_seq *seq)
{
return 0;
}
static void seq_client_proc_fini(struct lu_client_seq *seq)
{
return;
}
int seq_client_init(struct lu_client_seq *seq,
struct obd_export *exp,
enum lu_cli_type type,
const char *prefix,
struct lu_server_seq *srv)
{
int rc;
ENTRY;
LASSERT(seq != NULL);
LASSERT(prefix != NULL);
seq->lcs_srv = srv;
seq->lcs_type = type;
mutex_init(&seq->lcs_mutex);
if (type == LUSTRE_SEQ_METADATA)
seq->lcs_width = LUSTRE_METADATA_SEQ_MAX_WIDTH;
else
seq->lcs_width = LUSTRE_DATA_SEQ_MAX_WIDTH;
init_waitqueue_head(&seq->lcs_waitq);
seq_client_flush(seq);
if (exp != NULL)
seq->lcs_exp = class_export_get(exp);
else if (type == LUSTRE_SEQ_METADATA)
LASSERT(seq->lcs_srv != NULL);
snprintf(seq->lcs_name, sizeof(seq->lcs_name),
"cli-%s", prefix);
rc = seq_client_proc_init(seq);
if (rc)
seq_client_fini(seq);
RETURN(rc);
}
void seq_client_fini(struct lu_client_seq *seq)
{
ENTRY;
seq_client_proc_fini(seq);
if (seq->lcs_exp != NULL) {
class_export_put(seq->lcs_exp);
seq->lcs_exp = NULL;
}
seq->lcs_srv = NULL;
EXIT;
}
