int it_disposition(struct lookup_intent *it, int flag)
{
return it->d.lustre.it_disposition & flag;
}
void it_set_disposition(struct lookup_intent *it, int flag)
{
it->d.lustre.it_disposition |= flag;
}
void it_clear_disposition(struct lookup_intent *it, int flag)
{
it->d.lustre.it_disposition &= ~flag;
}
int it_open_error(int phase, struct lookup_intent *it)
{
if (it_disposition(it, DISP_OPEN_OPEN)) {
if (phase >= DISP_OPEN_OPEN)
return it->d.lustre.it_status;
else
return 0;
}
if (it_disposition(it, DISP_OPEN_CREATE)) {
if (phase >= DISP_OPEN_CREATE)
return it->d.lustre.it_status;
else
return 0;
}
if (it_disposition(it, DISP_LOOKUP_EXECD)) {
if (phase >= DISP_LOOKUP_EXECD)
return it->d.lustre.it_status;
else
return 0;
}
if (it_disposition(it, DISP_IT_EXECD)) {
if (phase >= DISP_IT_EXECD)
return it->d.lustre.it_status;
else
return 0;
}
CERROR("it disp: %X, status: %d\n", it->d.lustre.it_disposition,
it->d.lustre.it_status);
LBUG();
return 0;
}
int mdc_set_lock_data(struct obd_export *exp, __u64 *lockh, void *data,
__u64 *bits)
{
struct ldlm_lock *lock;
struct inode *new_inode = data;
if(bits)
*bits = 0;
if (!*lockh)
return 0;
lock = ldlm_handle2lock((struct lustre_handle *)lockh);
LASSERT(lock != NULL);
lock_res_and_lock(lock);
if (lock->l_resource->lr_lvb_inode &&
lock->l_resource->lr_lvb_inode != data) {
struct inode *old_inode = lock->l_resource->lr_lvb_inode;
LASSERTF(old_inode->i_state & I_FREEING,
"Found existing inode %p/%lu/%u state %lu in lock: "
"setting data to %p/%lu/%u\n", old_inode,
old_inode->i_ino, old_inode->i_generation,
old_inode->i_state,
new_inode, new_inode->i_ino, new_inode->i_generation);
}
lock->l_resource->lr_lvb_inode = new_inode;
if (bits)
*bits = lock->l_policy_data.l_inodebits.bits;
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
return 0;
}
ldlm_mode_t mdc_lock_match(struct obd_export *exp, __u64 flags,
const struct lu_fid *fid, ldlm_type_t type,
ldlm_policy_data_t *policy, ldlm_mode_t mode,
struct lustre_handle *lockh)
{
struct ldlm_res_id res_id;
ldlm_mode_t rc;
fid_build_reg_res_name(fid, &res_id);
rc = ldlm_lock_match(class_exp2obd(exp)->obd_namespace, flags,
&res_id, type, policy, mode, lockh, 0);
return rc;
}
int mdc_cancel_unused(struct obd_export *exp,
const struct lu_fid *fid,
ldlm_policy_data_t *policy,
ldlm_mode_t mode,
ldlm_cancel_flags_t flags,
void *opaque)
{
struct ldlm_res_id res_id;
struct obd_device *obd = class_exp2obd(exp);
int rc;
fid_build_reg_res_name(fid, &res_id);
rc = ldlm_cli_cancel_unused_resource(obd->obd_namespace, &res_id,
policy, mode, flags, opaque);
return rc;
}
int mdc_null_inode(struct obd_export *exp,
const struct lu_fid *fid)
{
struct ldlm_res_id res_id;
struct ldlm_resource *res;
struct ldlm_namespace *ns = class_exp2obd(exp)->obd_namespace;
LASSERTF(ns != NULL, "no namespace passed\n");
fid_build_reg_res_name(fid, &res_id);
res = ldlm_resource_get(ns, NULL, &res_id, 0, 0);
if(res == NULL)
return 0;
lock_res(res);
res->lr_lvb_inode = NULL;
unlock_res(res);
ldlm_resource_putref(res);
return 0;
}
int mdc_find_cbdata(struct obd_export *exp,
const struct lu_fid *fid,
ldlm_iterator_t it, void *data)
{
struct ldlm_res_id res_id;
int rc = 0;
fid_build_reg_res_name((struct lu_fid*)fid, &res_id);
rc = ldlm_resource_iterate(class_exp2obd(exp)->obd_namespace, &res_id,
it, data);
if (rc == LDLM_ITER_STOP)
return 1;
else if (rc == LDLM_ITER_CONTINUE)
return 0;
return rc;
}
static inline void mdc_clear_replay_flag(struct ptlrpc_request *req, int rc)
{
if (req->rq_replay) {
spin_lock(&req->rq_lock);
req->rq_replay = 0;
spin_unlock(&req->rq_lock);
}
if (rc && req->rq_transno != 0) {
DEBUG_REQ(D_ERROR, req, "transno returned on error rc %d", rc);
LBUG();
}
}
static void mdc_realloc_openmsg(struct ptlrpc_request *req,
struct mdt_body *body)
{
int rc;
rc = sptlrpc_cli_enlarge_reqbuf(req, DLM_INTENT_REC_OFF + 4,
body->eadatasize);
if (rc) {
CERROR("Can't enlarge segment %d size to %d\n",
DLM_INTENT_REC_OFF + 4, body->eadatasize);
body->valid &= ~OBD_MD_FLEASIZE;
body->eadatasize = 0;
}
}
static struct ptlrpc_request *mdc_intent_open_pack(struct obd_export *exp,
struct lookup_intent *it,
struct md_op_data *op_data,
void *lmm, int lmmsize,
void *cb_data)
{
struct ptlrpc_request *req;
struct obd_device *obddev = class_exp2obd(exp);
struct ldlm_intent *lit;
LIST_HEAD(cancels);
int count = 0;
int mode;
int rc;
it->it_create_mode = (it->it_create_mode & ~S_IFMT) | S_IFREG;
if (fid_is_sane(&op_data->op_fid2)) {
if (it->it_flags & (FMODE_WRITE|MDS_OPEN_TRUNC))
mode = LCK_CW;
#ifdef FMODE_EXEC
else if (it->it_flags & FMODE_EXEC)
mode = LCK_PR;
#endif
else
mode = LCK_CR;
count = mdc_resource_get_unused(exp, &op_data->op_fid2,
&cancels, mode,
MDS_INODELOCK_OPEN);
}
if (it->it_op & IT_CREAT)
mode = LCK_EX;
else
mode = LCK_CR;
count += mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, mode,
MDS_INODELOCK_UPDATE);
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_LDLM_INTENT_OPEN);
if (req == NULL) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return ERR_PTR(-ENOMEM);
}
mdc_set_capa_size(req, &RMF_CAPA1, op_data->op_capa1);
mdc_set_capa_size(req, &RMF_CAPA2, op_data->op_capa1);
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_CLIENT,
max(lmmsize, obddev->u.cli.cl_default_mds_easize));
rc = ldlm_prep_enqueue_req(exp, req, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return NULL;
}
spin_lock(&req->rq_lock);
req->rq_replay = req->rq_import->imp_replayable;
spin_unlock(&req->rq_lock);
lit = req_capsule_client_get(&req->rq_pill, &RMF_LDLM_INTENT);
lit->opc = (__u64)it->it_op;
mdc_open_pack(req, op_data, it->it_create_mode, 0, it->it_flags, lmm,
lmmsize);
if (client_is_remote(exp))
req_capsule_set_size(&req->rq_pill, &RMF_ACL, RCL_SERVER,
sizeof(struct mdt_remote_perm));
ptlrpc_request_set_replen(req);
return req;
}
static struct ptlrpc_request *mdc_intent_unlink_pack(struct obd_export *exp,
struct lookup_intent *it,
struct md_op_data *op_data)
{
struct ptlrpc_request *req;
struct obd_device *obddev = class_exp2obd(exp);
struct ldlm_intent *lit;
int rc;
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_LDLM_INTENT_UNLINK);
if (req == NULL)
return ERR_PTR(-ENOMEM);
mdc_set_capa_size(req, &RMF_CAPA1, op_data->op_capa1);
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
return ERR_PTR(rc);
}
lit = req_capsule_client_get(&req->rq_pill, &RMF_LDLM_INTENT);
lit->opc = (__u64)it->it_op;
mdc_unlink_pack(req, op_data);
req_capsule_set_size(&req->rq_pill, &RMF_MDT_MD, RCL_SERVER,
obddev->u.cli.cl_max_mds_easize);
req_capsule_set_size(&req->rq_pill, &RMF_ACL, RCL_SERVER,
obddev->u.cli.cl_max_mds_cookiesize);
ptlrpc_request_set_replen(req);
return req;
}
static struct ptlrpc_request *mdc_intent_getattr_pack(struct obd_export *exp,
struct lookup_intent *it,
struct md_op_data *op_data)
{
struct ptlrpc_request *req;
struct obd_device *obddev = class_exp2obd(exp);
obd_valid valid = OBD_MD_FLGETATTR | OBD_MD_FLEASIZE |
OBD_MD_FLMODEASIZE | OBD_MD_FLDIREA |
OBD_MD_FLMDSCAPA | OBD_MD_MEA |
(client_is_remote(exp) ?
OBD_MD_FLRMTPERM : OBD_MD_FLACL);
struct ldlm_intent *lit;
int rc;
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_LDLM_INTENT_GETATTR);
if (req == NULL)
return ERR_PTR(-ENOMEM);
mdc_set_capa_size(req, &RMF_CAPA1, op_data->op_capa1);
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
return ERR_PTR(rc);
}
lit = req_capsule_client_get(&req->rq_pill, &RMF_LDLM_INTENT);
lit->opc = (__u64)it->it_op;
mdc_getattr_pack(req, valid, it->it_flags, op_data,
obddev->u.cli.cl_max_mds_easize);
req_capsule_set_size(&req->rq_pill, &RMF_MDT_MD, RCL_SERVER,
obddev->u.cli.cl_max_mds_easize);
if (client_is_remote(exp))
req_capsule_set_size(&req->rq_pill, &RMF_ACL, RCL_SERVER,
sizeof(struct mdt_remote_perm));
ptlrpc_request_set_replen(req);
return req;
}
static struct ptlrpc_request *mdc_intent_layout_pack(struct obd_export *exp,
struct lookup_intent *it,
struct md_op_data *unused)
{
struct obd_device *obd = class_exp2obd(exp);
struct ptlrpc_request *req;
struct ldlm_intent *lit;
struct layout_intent *layout;
int rc;
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_LDLM_INTENT_LAYOUT);
if (req == NULL)
return ERR_PTR(-ENOMEM);
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_CLIENT, 0);
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
return ERR_PTR(rc);
}
lit = req_capsule_client_get(&req->rq_pill, &RMF_LDLM_INTENT);
lit->opc = (__u64)it->it_op;
layout = req_capsule_client_get(&req->rq_pill, &RMF_LAYOUT_INTENT);
layout->li_opc = LAYOUT_INTENT_ACCESS;
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER,
obd->u.cli.cl_max_mds_easize);
ptlrpc_request_set_replen(req);
return req;
}
static struct ptlrpc_request *
mdc_enqueue_pack(struct obd_export *exp, int lvb_len)
{
struct ptlrpc_request *req;
int rc;
req = ptlrpc_request_alloc(class_exp2cliimp(exp), &RQF_LDLM_ENQUEUE);
if (req == NULL)
return ERR_PTR(-ENOMEM);
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
return ERR_PTR(rc);
}
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER, lvb_len);
ptlrpc_request_set_replen(req);
return req;
}
static int mdc_finish_enqueue(struct obd_export *exp,
struct ptlrpc_request *req,
struct ldlm_enqueue_info *einfo,
struct lookup_intent *it,
struct lustre_handle *lockh,
int rc)
{
struct req_capsule *pill = &req->rq_pill;
struct ldlm_request *lockreq;
struct ldlm_reply *lockrep;
struct lustre_intent_data *intent = &it->d.lustre;
struct ldlm_lock *lock;
void *lvb_data = NULL;
int lvb_len = 0;
LASSERT(rc >= 0);
if (req->rq_transno || req->rq_replay) {
lockreq = req_capsule_client_get(pill, &RMF_DLM_REQ);
lockreq->lock_flags |= ldlm_flags_to_wire(LDLM_FL_INTENT_ONLY);
}
if (rc == ELDLM_LOCK_ABORTED) {
einfo->ei_mode = 0;
memset(lockh, 0, sizeof(*lockh));
rc = 0;
} else {
lock = ldlm_handle2lock(lockh);
LASSERT(lock != NULL);
if (lock->l_req_mode != einfo->ei_mode) {
ldlm_lock_addref(lockh, lock->l_req_mode);
ldlm_lock_decref(lockh, einfo->ei_mode);
einfo->ei_mode = lock->l_req_mode;
}
LDLM_LOCK_PUT(lock);
}
lockrep = req_capsule_server_get(pill, &RMF_DLM_REP);
LASSERT(lockrep != NULL);
intent->it_disposition = (int)lockrep->lock_policy_res1;
intent->it_status = (int)lockrep->lock_policy_res2;
intent->it_lock_mode = einfo->ei_mode;
intent->it_lock_handle = lockh->cookie;
intent->it_data = req;
if ((!req->rq_transno || intent->it_status < 0) && req->rq_replay)
mdc_clear_replay_flag(req, intent->it_status);
if (it->it_op & IT_OPEN && req->rq_replay &&
(!it_disposition(it, DISP_OPEN_OPEN) ||intent->it_status != 0))
mdc_clear_replay_flag(req, intent->it_status);
DEBUG_REQ(D_RPCTRACE, req, "op: %d disposition: %x, status: %d",
it->it_op, intent->it_disposition, intent->it_status);
if (it->it_op & (IT_OPEN | IT_UNLINK | IT_LOOKUP | IT_GETATTR)) {
struct mdt_body *body;
body = req_capsule_server_get(pill, &RMF_MDT_BODY);
if (body == NULL) {
CERROR ("Can't swab mdt_body\n");
return -EPROTO;
}
if (it_disposition(it, DISP_OPEN_OPEN) &&
!it_open_error(DISP_OPEN_OPEN, it)) {
mdc_set_open_replay_data(NULL, NULL, req);
}
if ((body->valid & (OBD_MD_FLDIREA | OBD_MD_FLEASIZE)) != 0) {
void *eadata;
mdc_update_max_ea_from_body(exp, body);
eadata = req_capsule_server_sized_get(pill, &RMF_MDT_MD,
body->eadatasize);
if (eadata == NULL)
return -EPROTO;
lvb_data = eadata;
lvb_len = body->eadatasize;
if ((it->it_op & IT_OPEN) && req->rq_replay) {
void *lmm;
if (req_capsule_get_size(pill, &RMF_EADATA,
RCL_CLIENT) <
body->eadatasize)
mdc_realloc_openmsg(req, body);
else
req_capsule_shrink(pill, &RMF_EADATA,
body->eadatasize,
RCL_CLIENT);
req_capsule_set_size(pill, &RMF_EADATA,
RCL_CLIENT,
body->eadatasize);
lmm = req_capsule_client_get(pill, &RMF_EADATA);
if (lmm)
memcpy(lmm, eadata, body->eadatasize);
}
}
if (body->valid & OBD_MD_FLRMTPERM) {
struct mdt_remote_perm *perm;
LASSERT(client_is_remote(exp));
perm = req_capsule_server_swab_get(pill, &RMF_ACL,
lustre_swab_mdt_remote_perm);
if (perm == NULL)
return -EPROTO;
}
if (body->valid & OBD_MD_FLMDSCAPA) {
struct lustre_capa *capa, *p;
capa = req_capsule_server_get(pill, &RMF_CAPA1);
if (capa == NULL)
return -EPROTO;
if (it->it_op & IT_OPEN) {
p = req_capsule_client_get(pill, &RMF_CAPA2);
LASSERT(p);
*p = *capa;
}
}
if (body->valid & OBD_MD_FLOSSCAPA) {
struct lustre_capa *capa;
capa = req_capsule_server_get(pill, &RMF_CAPA2);
if (capa == NULL)
return -EPROTO;
}
} else if (it->it_op & IT_LAYOUT) {
lvb_len = req_capsule_get_size(pill, &RMF_DLM_LVB, RCL_SERVER);
if (lvb_len > 0) {
lvb_data = req_capsule_server_sized_get(pill,
&RMF_DLM_LVB, lvb_len);
if (lvb_data == NULL)
return -EPROTO;
}
}
lock = ldlm_handle2lock(lockh);
if (lock != NULL && ldlm_has_layout(lock) && lvb_data != NULL) {
void *lmm;
LDLM_DEBUG(lock, "layout lock returned by: %s, lvb_len: %d\n",
ldlm_it2str(it->it_op), lvb_len);
OBD_ALLOC_LARGE(lmm, lvb_len);
if (lmm == NULL) {
LDLM_LOCK_PUT(lock);
return -ENOMEM;
}
memcpy(lmm, lvb_data, lvb_len);
lock_res_and_lock(lock);
if (lock->l_lvb_data == NULL) {
lock->l_lvb_data = lmm;
lock->l_lvb_len = lvb_len;
lmm = NULL;
}
unlock_res_and_lock(lock);
if (lmm != NULL)
OBD_FREE_LARGE(lmm, lvb_len);
}
if (lock != NULL)
LDLM_LOCK_PUT(lock);
return rc;
}
int mdc_enqueue(struct obd_export *exp, struct ldlm_enqueue_info *einfo,
struct lookup_intent *it, struct md_op_data *op_data,
struct lustre_handle *lockh, void *lmm, int lmmsize,
struct ptlrpc_request **reqp, __u64 extra_lock_flags)
{
struct obd_device *obddev = class_exp2obd(exp);
struct ptlrpc_request *req = NULL;
__u64 flags, saved_flags = extra_lock_flags;
int rc;
struct ldlm_res_id res_id;
static const ldlm_policy_data_t lookup_policy =
{ .l_inodebits = { MDS_INODELOCK_LOOKUP } };
static const ldlm_policy_data_t update_policy =
{ .l_inodebits = { MDS_INODELOCK_UPDATE } };
static const ldlm_policy_data_t layout_policy =
{ .l_inodebits = { MDS_INODELOCK_LAYOUT } };
ldlm_policy_data_t const *policy = &lookup_policy;
int generation, resends = 0;
struct ldlm_reply *lockrep;
enum lvb_type lvb_type = 0;
LASSERTF(!it || einfo->ei_type == LDLM_IBITS, "lock type %d\n",
einfo->ei_type);
fid_build_reg_res_name(&op_data->op_fid1, &res_id);
if (it) {
saved_flags |= LDLM_FL_HAS_INTENT;
if (it->it_op & (IT_UNLINK | IT_GETATTR | IT_READDIR))
policy = &update_policy;
else if (it->it_op & IT_LAYOUT)
policy = &layout_policy;
}
LASSERT(reqp == NULL);
generation = obddev->u.cli.cl_import->imp_generation;
resend:
flags = saved_flags;
if (!it) {
LASSERT(lmm && lmmsize == 0);
LASSERTF(einfo->ei_type == LDLM_FLOCK, "lock type %d\n",
einfo->ei_type);
policy = (ldlm_policy_data_t *)lmm;
res_id.name[3] = LDLM_FLOCK;
} else if (it->it_op & IT_OPEN) {
req = mdc_intent_open_pack(exp, it, op_data, lmm, lmmsize,
einfo->ei_cbdata);
policy = &update_policy;
einfo->ei_cbdata = NULL;
lmm = NULL;
} else if (it->it_op & IT_UNLINK) {
req = mdc_intent_unlink_pack(exp, it, op_data);
} else if (it->it_op & (IT_GETATTR | IT_LOOKUP)) {
req = mdc_intent_getattr_pack(exp, it, op_data);
} else if (it->it_op & IT_READDIR) {
req = mdc_enqueue_pack(exp, 0);
} else if (it->it_op & IT_LAYOUT) {
if (!imp_connect_lvb_type(class_exp2cliimp(exp)))
return -EOPNOTSUPP;
req = mdc_intent_layout_pack(exp, it, op_data);
lvb_type = LVB_T_LAYOUT;
} else {
LBUG();
return -EINVAL;
}
if (IS_ERR(req))
return PTR_ERR(req);
if (req != NULL && it && it->it_op & IT_CREAT)
req->rq_no_retry_einprogress = 1;
if (resends) {
req->rq_generation_set = 1;
req->rq_import_generation = generation;
req->rq_sent = cfs_time_current_sec() + resends;
}
if (it) {
mdc_get_rpc_lock(obddev->u.cli.cl_rpc_lock, it);
rc = mdc_enter_request(&obddev->u.cli);
if (rc != 0) {
mdc_put_rpc_lock(obddev->u.cli.cl_rpc_lock, it);
mdc_clear_replay_flag(req, 0);
ptlrpc_req_finished(req);
return rc;
}
}
rc = ldlm_cli_enqueue(exp, &req, einfo, &res_id, policy, &flags, NULL,
0, lvb_type, lockh, 0);
if (!it) {
if ((rc == -EINTR) || (rc == -ETIMEDOUT))
goto resend;
return rc;
}
mdc_exit_request(&obddev->u.cli);
mdc_put_rpc_lock(obddev->u.cli.cl_rpc_lock, it);
if (rc < 0) {
CERROR("ldlm_cli_enqueue: %d\n", rc);
mdc_clear_replay_flag(req, rc);
ptlrpc_req_finished(req);
return rc;
}
lockrep = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
LASSERT(lockrep != NULL);
lockrep->lock_policy_res2 =
ptlrpc_status_ntoh(lockrep->lock_policy_res2);
if (it && it->it_op & IT_CREAT &&
(int)lockrep->lock_policy_res2 == -EINPROGRESS) {
mdc_clear_replay_flag(req, rc);
ptlrpc_req_finished(req);
resends++;
CDEBUG(D_HA, "%s: resend:%d op:%d "DFID"/"DFID"\n",
obddev->obd_name, resends, it->it_op,
PFID(&op_data->op_fid1), PFID(&op_data->op_fid2));
if (generation == obddev->u.cli.cl_import->imp_generation) {
goto resend;
} else {
CDEBUG(D_HA, "resend cross eviction\n");
return -EIO;
}
}
rc = mdc_finish_enqueue(exp, req, einfo, it, lockh, rc);
if (rc < 0) {
if (lustre_handle_is_used(lockh)) {
ldlm_lock_decref(lockh, einfo->ei_mode);
memset(lockh, 0, sizeof(*lockh));
}
ptlrpc_req_finished(req);
}
return rc;
}
static int mdc_finish_intent_lock(struct obd_export *exp,
struct ptlrpc_request *request,
struct md_op_data *op_data,
struct lookup_intent *it,
struct lustre_handle *lockh)
{
struct lustre_handle old_lock;
struct mdt_body *mdt_body;
struct ldlm_lock *lock;
int rc;
LASSERT(request != NULL);
LASSERT(request != LP_POISON);
LASSERT(request->rq_repmsg != LP_POISON);
if (!it_disposition(it, DISP_IT_EXECD)) {
LASSERT(it->d.lustre.it_status != 0);
return it->d.lustre.it_status;
}
rc = it_open_error(DISP_IT_EXECD, it);
if (rc)
return rc;
mdt_body = req_capsule_server_get(&request->rq_pill, &RMF_MDT_BODY);
LASSERT(mdt_body != NULL);
if (fid_is_sane(&op_data->op_fid2) &&
it->it_create_mode & M_CHECK_STALE &&
it->it_op != IT_GETATTR) {
it_set_disposition(it, DISP_ENQ_COMPLETE);
if ((!lu_fid_eq(&op_data->op_fid2, &mdt_body->fid1)) &&
(!lu_fid_eq(&op_data->op_fid3, &mdt_body->fid1))) {
CDEBUG(D_DENTRY, "Found stale data "DFID"("DFID")/"DFID
"\n", PFID(&op_data->op_fid2),
PFID(&op_data->op_fid2), PFID(&mdt_body->fid1));
return -ESTALE;
}
}
rc = it_open_error(DISP_LOOKUP_EXECD, it);
if (rc)
return rc;
if (!it_disposition(it, DISP_ENQ_CREATE_REF) &&
it_disposition(it, DISP_OPEN_CREATE) &&
!it_open_error(DISP_OPEN_CREATE, it)) {
it_set_disposition(it, DISP_ENQ_CREATE_REF);
ptlrpc_request_addref(request);
}
if (!it_disposition(it, DISP_ENQ_OPEN_REF) &&
it_disposition(it, DISP_OPEN_OPEN) &&
!it_open_error(DISP_OPEN_OPEN, it)) {
it_set_disposition(it, DISP_ENQ_OPEN_REF);
ptlrpc_request_addref(request);
OBD_FAIL_TIMEOUT(OBD_FAIL_MDC_ENQUEUE_PAUSE, obd_timeout);
}
if (it->it_op & IT_CREAT) {
} else if (it->it_op == IT_OPEN) {
LASSERT(!it_disposition(it, DISP_OPEN_CREATE));
} else {
LASSERT(it->it_op & (IT_GETATTR | IT_LOOKUP | IT_LAYOUT));
}
lock = ldlm_handle2lock(lockh);
if (lock) {
ldlm_policy_data_t policy = lock->l_policy_data;
LDLM_DEBUG(lock, "matching against this");
LASSERTF(fid_res_name_eq(&mdt_body->fid1,
&lock->l_resource->lr_name),
"Lock res_id: %lu/%lu/%lu, fid: %lu/%lu/%lu.\n",
(unsigned long)lock->l_resource->lr_name.name[0],
(unsigned long)lock->l_resource->lr_name.name[1],
(unsigned long)lock->l_resource->lr_name.name[2],
(unsigned long)fid_seq(&mdt_body->fid1),
(unsigned long)fid_oid(&mdt_body->fid1),
(unsigned long)fid_ver(&mdt_body->fid1));
LDLM_LOCK_PUT(lock);
memcpy(&old_lock, lockh, sizeof(*lockh));
if (ldlm_lock_match(NULL, LDLM_FL_BLOCK_GRANTED, NULL,
LDLM_IBITS, &policy, LCK_NL, &old_lock, 0)) {
ldlm_lock_decref_and_cancel(lockh,
it->d.lustre.it_lock_mode);
memcpy(lockh, &old_lock, sizeof(old_lock));
it->d.lustre.it_lock_handle = lockh->cookie;
}
}
CDEBUG(D_DENTRY,"D_IT dentry %.*s intent: %s status %d disp %x rc %d\n",
op_data->op_namelen, op_data->op_name, ldlm_it2str(it->it_op),
it->d.lustre.it_status, it->d.lustre.it_disposition, rc);
return rc;
}
int mdc_revalidate_lock(struct obd_export *exp, struct lookup_intent *it,
struct lu_fid *fid, __u64 *bits)
{
struct ldlm_res_id res_id;
struct lustre_handle lockh;
ldlm_policy_data_t policy;
ldlm_mode_t mode;
if (it->d.lustre.it_lock_handle) {
lockh.cookie = it->d.lustre.it_lock_handle;
mode = ldlm_revalidate_lock_handle(&lockh, bits);
} else {
fid_build_reg_res_name(fid, &res_id);
switch (it->it_op) {
case IT_GETATTR:
policy.l_inodebits.bits = MDS_INODELOCK_UPDATE;
break;
case IT_LAYOUT:
policy.l_inodebits.bits = MDS_INODELOCK_LAYOUT;
break;
default:
policy.l_inodebits.bits = MDS_INODELOCK_LOOKUP;
break;
}
mode = ldlm_lock_match(exp->exp_obd->obd_namespace,
LDLM_FL_BLOCK_GRANTED, &res_id,
LDLM_IBITS, &policy,
LCK_CR|LCK_CW|LCK_PR|LCK_PW, &lockh, 0);
}
if (mode) {
it->d.lustre.it_lock_handle = lockh.cookie;
it->d.lustre.it_lock_mode = mode;
} else {
it->d.lustre.it_lock_handle = 0;
it->d.lustre.it_lock_mode = 0;
}
return !!mode;
}
int mdc_intent_lock(struct obd_export *exp, struct md_op_data *op_data,
void *lmm, int lmmsize, struct lookup_intent *it,
int lookup_flags, struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct lustre_handle lockh;
int rc = 0;
LASSERT(it);
CDEBUG(D_DLMTRACE, "(name: %.*s,"DFID") in obj "DFID
", intent: %s flags %#o\n", op_data->op_namelen,
op_data->op_name, PFID(&op_data->op_fid2),
PFID(&op_data->op_fid1), ldlm_it2str(it->it_op),
it->it_flags);
lockh.cookie = 0;
if (fid_is_sane(&op_data->op_fid2) &&
(it->it_op & (IT_LOOKUP | IT_GETATTR))) {
it->d.lustre.it_lock_handle = 0;
rc = mdc_revalidate_lock(exp, it, &op_data->op_fid2, NULL);
if (rc || op_data->op_namelen != 0)
return rc;
}
if (!it_disposition(it, DISP_ENQ_COMPLETE)) {
struct ldlm_enqueue_info einfo = {
.ei_type = LDLM_IBITS,
.ei_mode = it_to_lock_mode(it),
.ei_cb_bl = cb_blocking,
.ei_cb_cp = ldlm_completion_ast,
};
if (!fid_is_sane(&op_data->op_fid2) && it->it_op & IT_CREAT) {
rc = mdc_fid_alloc(exp, &op_data->op_fid2, op_data);
if (rc < 0) {
CERROR("Can't alloc new fid, rc %d\n", rc);
return rc;
}
}
rc = mdc_enqueue(exp, &einfo, it, op_data, &lockh,
lmm, lmmsize, NULL, extra_lock_flags);
if (rc < 0)
return rc;
} else if (!fid_is_sane(&op_data->op_fid2) ||
!(it->it_create_mode & M_CHECK_STALE)) {
it_clear_disposition(it, DISP_ENQ_COMPLETE);
}
*reqp = it->d.lustre.it_data;
rc = mdc_finish_intent_lock(exp, *reqp, op_data, it, &lockh);
return rc;
}
static int mdc_intent_getattr_async_interpret(const struct lu_env *env,
struct ptlrpc_request *req,
void *args, int rc)
{
struct mdc_getattr_args *ga = args;
struct obd_export *exp = ga->ga_exp;
struct md_enqueue_info *minfo = ga->ga_minfo;
struct ldlm_enqueue_info *einfo = ga->ga_einfo;
struct lookup_intent *it;
struct lustre_handle *lockh;
struct obd_device *obddev;
struct ldlm_reply *lockrep;
__u64 flags = LDLM_FL_HAS_INTENT;
it = &minfo->mi_it;
lockh = &minfo->mi_lockh;
obddev = class_exp2obd(exp);
mdc_exit_request(&obddev->u.cli);
if (OBD_FAIL_CHECK(OBD_FAIL_MDC_GETATTR_ENQUEUE))
rc = -ETIMEDOUT;
rc = ldlm_cli_enqueue_fini(exp, req, einfo->ei_type, 1, einfo->ei_mode,
&flags, NULL, 0, lockh, rc);
if (rc < 0) {
CERROR("ldlm_cli_enqueue_fini: %d\n", rc);
mdc_clear_replay_flag(req, rc);
GOTO(out, rc);
}
lockrep = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
LASSERT(lockrep != NULL);
lockrep->lock_policy_res2 =
ptlrpc_status_ntoh(lockrep->lock_policy_res2);
rc = mdc_finish_enqueue(exp, req, einfo, it, lockh, rc);
if (rc)
GOTO(out, rc);
rc = mdc_finish_intent_lock(exp, req, &minfo->mi_data, it, lockh);
out:
OBD_FREE_PTR(einfo);
minfo->mi_cb(req, minfo, rc);
return 0;
}
int mdc_intent_getattr_async(struct obd_export *exp,
struct md_enqueue_info *minfo,
struct ldlm_enqueue_info *einfo)
{
struct md_op_data *op_data = &minfo->mi_data;
struct lookup_intent *it = &minfo->mi_it;
struct ptlrpc_request *req;
struct mdc_getattr_args *ga;
struct obd_device *obddev = class_exp2obd(exp);
struct ldlm_res_id res_id;
ldlm_policy_data_t policy = {
.l_inodebits = { MDS_INODELOCK_LOOKUP |
MDS_INODELOCK_UPDATE }
};
int rc = 0;
__u64 flags = LDLM_FL_HAS_INTENT;
CDEBUG(D_DLMTRACE,"name: %.*s in inode "DFID", intent: %s flags %#o\n",
op_data->op_namelen, op_data->op_name, PFID(&op_data->op_fid1),
ldlm_it2str(it->it_op), it->it_flags);
fid_build_reg_res_name(&op_data->op_fid1, &res_id);
req = mdc_intent_getattr_pack(exp, it, op_data);
if (!req)
return -ENOMEM;
rc = mdc_enter_request(&obddev->u.cli);
if (rc != 0) {
ptlrpc_req_finished(req);
return rc;
}
rc = ldlm_cli_enqueue(exp, &req, einfo, &res_id, &policy, &flags, NULL,
0, LVB_T_NONE, &minfo->mi_lockh, 1);
if (rc < 0) {
mdc_exit_request(&obddev->u.cli);
ptlrpc_req_finished(req);
return rc;
}
CLASSERT(sizeof(*ga) <= sizeof(req->rq_async_args));
ga = ptlrpc_req_async_args(req);
ga->ga_exp = exp;
ga->ga_minfo = minfo;
ga->ga_einfo = einfo;
req->rq_interpret_reply = mdc_intent_getattr_async_interpret;
ptlrpcd_add_req(req, PDL_POLICY_LOCAL, -1);
return 0;
}
