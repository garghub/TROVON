static int mdc_reint(struct ptlrpc_request *request,
struct mdc_rpc_lock *rpc_lock,
int level)
{
int rc;
request->rq_send_state = level;
mdc_get_rpc_lock(rpc_lock, NULL);
rc = ptlrpc_queue_wait(request);
mdc_put_rpc_lock(rpc_lock, NULL);
if (rc)
CDEBUG(D_INFO, "error in handling %d\n", rc);
else if (!req_capsule_server_get(&request->rq_pill, &RMF_MDT_BODY))
rc = -EPROTO;
return rc;
}
int mdc_resource_get_unused(struct obd_export *exp, const struct lu_fid *fid,
struct list_head *cancels, enum ldlm_mode mode,
__u64 bits)
{
struct ldlm_namespace *ns = exp->exp_obd->obd_namespace;
ldlm_policy_data_t policy = {};
struct ldlm_res_id res_id;
struct ldlm_resource *res;
int count;
if (exp_connect_cancelset(exp) && !ns_connect_cancelset(ns))
return 0;
fid_build_reg_res_name(fid, &res_id);
res = ldlm_resource_get(exp->exp_obd->obd_namespace,
NULL, &res_id, 0, 0);
if (!res)
return 0;
LDLM_RESOURCE_ADDREF(res);
policy.l_inodebits.bits = bits;
count = ldlm_cancel_resource_local(res, cancels, &policy,
mode, 0, 0, NULL);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
return count;
}
int mdc_setattr(struct obd_export *exp, struct md_op_data *op_data,
void *ea, int ealen, void *ea2, int ea2len,
struct ptlrpc_request **request, struct md_open_data **mod)
{
LIST_HEAD(cancels);
struct ptlrpc_request *req;
struct mdc_rpc_lock *rpc_lock;
struct obd_device *obd = exp->exp_obd;
int count = 0, rc;
__u64 bits;
bits = MDS_INODELOCK_UPDATE;
if (op_data->op_attr.ia_valid & (ATTR_MODE|ATTR_UID|ATTR_GID))
bits |= MDS_INODELOCK_LOOKUP;
if ((op_data->op_flags & MF_MDC_CANCEL_FID1) &&
(fid_is_sane(&op_data->op_fid1)) &&
!OBD_FAIL_CHECK(OBD_FAIL_LDLM_BL_CALLBACK_NET))
count = mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, LCK_EX, bits);
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_MDS_REINT_SETATTR);
if (!req) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return -ENOMEM;
}
if ((op_data->op_flags & (MF_SOM_CHANGE | MF_EPOCH_OPEN)) == 0)
req_capsule_set_size(&req->rq_pill, &RMF_MDT_EPOCH, RCL_CLIENT,
0);
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_CLIENT, ealen);
req_capsule_set_size(&req->rq_pill, &RMF_LOGCOOKIES, RCL_CLIENT,
ea2len);
rc = mdc_prep_elc_req(exp, req, MDS_REINT, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
rpc_lock = obd->u.cli.cl_rpc_lock;
if (op_data->op_attr.ia_valid & (ATTR_MTIME | ATTR_CTIME))
CDEBUG(D_INODE, "setting mtime %ld, ctime %ld\n",
LTIME_S(op_data->op_attr.ia_mtime),
LTIME_S(op_data->op_attr.ia_ctime));
mdc_setattr_pack(req, op_data, ea, ealen, ea2, ea2len);
ptlrpc_request_set_replen(req);
if (mod && (op_data->op_flags & MF_EPOCH_OPEN) &&
req->rq_import->imp_replayable) {
LASSERT(!*mod);
*mod = obd_mod_alloc();
if (!*mod) {
DEBUG_REQ(D_ERROR, req, "Can't allocate md_open_data");
} else {
req->rq_replay = 1;
req->rq_cb_data = *mod;
(*mod)->mod_open_req = req;
req->rq_commit_cb = mdc_commit_open;
(*mod)->mod_is_create = true;
obd_mod_get(*mod);
}
}
rc = mdc_reint(req, rpc_lock, LUSTRE_IMP_FULL);
if (rc == 0 && (op_data->op_flags & MF_EPOCH_OPEN)) {
struct mdt_ioepoch *epoch;
struct mdt_body *body;
epoch = req_capsule_client_get(&req->rq_pill, &RMF_MDT_EPOCH);
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
epoch->handle = body->handle;
epoch->ioepoch = body->ioepoch;
req->rq_replay_cb = mdc_replay_open;
} else if (rc == -ESTALE && (op_data->op_flags & MF_SOM_CHANGE)) {
rc = 0;
} else if (rc == -ERESTARTSYS) {
rc = 0;
}
*request = req;
if (rc && req->rq_commit_cb) {
if (mod && *mod)
obd_mod_put(*mod);
req->rq_commit_cb(req);
}
return rc;
}
int mdc_create(struct obd_export *exp, struct md_op_data *op_data,
const void *data, int datalen, int mode, __u32 uid, __u32 gid,
cfs_cap_t cap_effective, __u64 rdev,
struct ptlrpc_request **request)
{
struct ptlrpc_request *req;
int level, rc;
int count, resends = 0;
struct obd_import *import = exp->exp_obd->u.cli.cl_import;
int generation = import->imp_generation;
LIST_HEAD(cancels);
if (!fid_is_sane(&op_data->op_fid2)) {
rc = mdc_fid_alloc(exp, &op_data->op_fid2, op_data);
if (rc < 0) {
CERROR("Can't alloc new fid, rc %d\n", rc);
return rc;
}
}
rebuild:
count = 0;
if ((op_data->op_flags & MF_MDC_CANCEL_FID1) &&
(fid_is_sane(&op_data->op_fid1)))
count = mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_MDS_REINT_CREATE_ACL);
if (!req) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return -ENOMEM;
}
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_CLIENT,
data && datalen ? datalen : 0);
rc = mdc_prep_elc_req(exp, req, MDS_REINT, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
mdc_create_pack(req, op_data, data, datalen, mode, uid,
gid, cap_effective, rdev);
ptlrpc_request_set_replen(req);
req->rq_no_retry_einprogress = 1;
if (resends) {
req->rq_generation_set = 1;
req->rq_import_generation = generation;
req->rq_sent = ktime_get_real_seconds() + resends;
}
level = LUSTRE_IMP_FULL;
resend:
rc = mdc_reint(req, exp->exp_obd->u.cli.cl_rpc_lock, level);
if (rc == -ERESTARTSYS) {
level = LUSTRE_IMP_RECOVER;
goto resend;
} else if (rc == -EINPROGRESS) {
ptlrpc_req_finished(req);
resends++;
CDEBUG(D_HA, "%s: resend:%d create on "DFID"/"DFID"\n",
exp->exp_obd->obd_name, resends,
PFID(&op_data->op_fid1), PFID(&op_data->op_fid2));
if (generation == import->imp_generation) {
goto rebuild;
} else {
CDEBUG(D_HA, "resend cross eviction\n");
return -EIO;
}
}
*request = req;
return rc;
}
int mdc_unlink(struct obd_export *exp, struct md_op_data *op_data,
struct ptlrpc_request **request)
{
LIST_HEAD(cancels);
struct obd_device *obd = class_exp2obd(exp);
struct ptlrpc_request *req = *request;
int count = 0, rc;
LASSERT(!req);
if ((op_data->op_flags & MF_MDC_CANCEL_FID1) &&
(fid_is_sane(&op_data->op_fid1)) &&
!OBD_FAIL_CHECK(OBD_FAIL_LDLM_BL_CALLBACK_NET))
count = mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
if ((op_data->op_flags & MF_MDC_CANCEL_FID3) &&
(fid_is_sane(&op_data->op_fid3)) &&
!OBD_FAIL_CHECK(OBD_FAIL_LDLM_BL_CALLBACK_NET))
count += mdc_resource_get_unused(exp, &op_data->op_fid3,
&cancels, LCK_EX,
MDS_INODELOCK_FULL);
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_MDS_REINT_UNLINK);
if (!req) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return -ENOMEM;
}
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
rc = mdc_prep_elc_req(exp, req, MDS_REINT, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
mdc_unlink_pack(req, op_data);
req_capsule_set_size(&req->rq_pill, &RMF_MDT_MD, RCL_SERVER,
obd->u.cli.cl_default_mds_easize);
req_capsule_set_size(&req->rq_pill, &RMF_LOGCOOKIES, RCL_SERVER,
obd->u.cli.cl_default_mds_cookiesize);
ptlrpc_request_set_replen(req);
*request = req;
rc = mdc_reint(req, obd->u.cli.cl_rpc_lock, LUSTRE_IMP_FULL);
if (rc == -ERESTARTSYS)
rc = 0;
return rc;
}
int mdc_link(struct obd_export *exp, struct md_op_data *op_data,
struct ptlrpc_request **request)
{
LIST_HEAD(cancels);
struct obd_device *obd = exp->exp_obd;
struct ptlrpc_request *req;
int count = 0, rc;
if ((op_data->op_flags & MF_MDC_CANCEL_FID2) &&
(fid_is_sane(&op_data->op_fid2)))
count = mdc_resource_get_unused(exp, &op_data->op_fid2,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
if ((op_data->op_flags & MF_MDC_CANCEL_FID1) &&
(fid_is_sane(&op_data->op_fid1)))
count += mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
req = ptlrpc_request_alloc(class_exp2cliimp(exp), &RQF_MDS_REINT_LINK);
if (!req) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return -ENOMEM;
}
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
op_data->op_namelen + 1);
rc = mdc_prep_elc_req(exp, req, MDS_REINT, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
mdc_link_pack(req, op_data);
ptlrpc_request_set_replen(req);
rc = mdc_reint(req, obd->u.cli.cl_rpc_lock, LUSTRE_IMP_FULL);
*request = req;
if (rc == -ERESTARTSYS)
rc = 0;
return rc;
}
int mdc_rename(struct obd_export *exp, struct md_op_data *op_data,
const char *old, int oldlen, const char *new, int newlen,
struct ptlrpc_request **request)
{
LIST_HEAD(cancels);
struct obd_device *obd = exp->exp_obd;
struct ptlrpc_request *req;
int count = 0, rc;
if ((op_data->op_flags & MF_MDC_CANCEL_FID1) &&
(fid_is_sane(&op_data->op_fid1)))
count = mdc_resource_get_unused(exp, &op_data->op_fid1,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
if ((op_data->op_flags & MF_MDC_CANCEL_FID2) &&
(fid_is_sane(&op_data->op_fid2)))
count += mdc_resource_get_unused(exp, &op_data->op_fid2,
&cancels, LCK_EX,
MDS_INODELOCK_UPDATE);
if ((op_data->op_flags & MF_MDC_CANCEL_FID3) &&
(fid_is_sane(&op_data->op_fid3)))
count += mdc_resource_get_unused(exp, &op_data->op_fid3,
&cancels, LCK_EX,
MDS_INODELOCK_LOOKUP);
if ((op_data->op_flags & MF_MDC_CANCEL_FID4) &&
(fid_is_sane(&op_data->op_fid4)))
count += mdc_resource_get_unused(exp, &op_data->op_fid4,
&cancels, LCK_EX,
MDS_INODELOCK_FULL);
req = ptlrpc_request_alloc(class_exp2cliimp(exp),
&RQF_MDS_REINT_RENAME);
if (!req) {
ldlm_lock_list_put(&cancels, l_bl_ast, count);
return -ENOMEM;
}
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT, oldlen + 1);
req_capsule_set_size(&req->rq_pill, &RMF_SYMTGT, RCL_CLIENT, newlen+1);
rc = mdc_prep_elc_req(exp, req, MDS_REINT, &cancels, count);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
if (exp_connect_cancelset(exp) && req)
ldlm_cli_cancel_list(&cancels, count, req, 0);
mdc_rename_pack(req, op_data, old, oldlen, new, newlen);
req_capsule_set_size(&req->rq_pill, &RMF_MDT_MD, RCL_SERVER,
obd->u.cli.cl_default_mds_easize);
req_capsule_set_size(&req->rq_pill, &RMF_LOGCOOKIES, RCL_SERVER,
obd->u.cli.cl_default_mds_cookiesize);
ptlrpc_request_set_replen(req);
rc = mdc_reint(req, obd->u.cli.cl_rpc_lock, LUSTRE_IMP_FULL);
*request = req;
if (rc == -ERESTARTSYS)
rc = 0;
return rc;
}
