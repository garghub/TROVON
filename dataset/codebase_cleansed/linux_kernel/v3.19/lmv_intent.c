static int lmv_intent_remote(struct obd_export *exp, void *lmm,
int lmmsize, struct lookup_intent *it,
const struct lu_fid *parent_fid, int flags,
struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct ptlrpc_request *req = NULL;
struct lustre_handle plock;
struct md_op_data *op_data;
struct lmv_tgt_desc *tgt;
struct mdt_body *body;
int pmode;
int rc = 0;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (body == NULL)
return -EPROTO;
LASSERT((body->valid & OBD_MD_MDS));
if (it->it_op & IT_LOOKUP)
it->it_op = IT_GETATTR;
pmode = it->d.lustre.it_lock_mode;
if (pmode) {
plock.cookie = it->d.lustre.it_lock_handle;
it->d.lustre.it_lock_mode = 0;
it->d.lustre.it_data = NULL;
}
LASSERT(fid_is_sane(&body->fid1));
tgt = lmv_find_target(lmv, &body->fid1);
if (IS_ERR(tgt)) {
rc = PTR_ERR(tgt);
goto out;
}
OBD_ALLOC_PTR(op_data);
if (op_data == NULL) {
rc = -ENOMEM;
goto out;
}
op_data->op_fid1 = body->fid1;
if (parent_fid != NULL) {
LASSERT(it->it_op & IT_OPEN);
op_data->op_fid2 = *parent_fid;
op_data->op_fid3 = body->fid1;
}
op_data->op_bias = MDS_CROSS_REF;
CDEBUG(D_INODE, "REMOTE_INTENT with fid="DFID" -> mds #%d\n",
PFID(&body->fid1), tgt->ltd_idx);
rc = md_intent_lock(tgt->ltd_exp, op_data, lmm, lmmsize, it,
flags, &req, cb_blocking, extra_lock_flags);
if (rc)
goto out_free_op_data;
if (it->d.lustre.it_lock_mode != 0) {
it->d.lustre.it_remote_lock_handle =
it->d.lustre.it_lock_handle;
it->d.lustre.it_remote_lock_mode = it->d.lustre.it_lock_mode;
}
it->d.lustre.it_lock_handle = plock.cookie;
it->d.lustre.it_lock_mode = pmode;
out_free_op_data:
OBD_FREE_PTR(op_data);
out:
if (rc && pmode)
ldlm_lock_decref(&plock, pmode);
ptlrpc_req_finished(*reqp);
*reqp = req;
return rc;
}
int lmv_intent_open(struct obd_export *exp, struct md_op_data *op_data,
void *lmm, int lmmsize, struct lookup_intent *it,
int flags, struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct lmv_tgt_desc *tgt;
struct mdt_body *body;
int rc;
tgt = lmv_locate_mds(lmv, op_data, &op_data->op_fid1);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
if ((it->it_op & IT_CREAT) &&
!(it->it_flags & MDS_OPEN_BY_FID)) {
op_data->op_fid3 = op_data->op_fid2;
rc = lmv_fid_alloc(exp, &op_data->op_fid2, op_data);
if (rc != 0)
return rc;
}
CDEBUG(D_INODE, "OPEN_INTENT with fid1=" DFID ", fid2=" DFID ", name='%s' -> mds #%d\n",
PFID(&op_data->op_fid1),
PFID(&op_data->op_fid2), op_data->op_name, tgt->ltd_idx);
rc = md_intent_lock(tgt->ltd_exp, op_data, lmm, lmmsize, it, flags,
reqp, cb_blocking, extra_lock_flags);
if (rc != 0)
return rc;
if ((it->d.lustre.it_disposition & DISP_LOOKUP_NEG) &&
!(it->d.lustre.it_disposition & DISP_OPEN_CREATE) &&
!(it->d.lustre.it_disposition & DISP_OPEN_OPEN))
return rc;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (body == NULL)
return -EPROTO;
if (likely(!(body->valid & OBD_MD_MDS)))
return 0;
rc = lmv_intent_remote(exp, lmm, lmmsize, it, &op_data->op_fid1, flags,
reqp, cb_blocking, extra_lock_flags);
if (rc != 0) {
LASSERT(rc < 0);
CDEBUG(D_INODE, "Can't handle remote %s: dir " DFID "(" DFID "):%*s: %d\n",
LL_IT2STR(it), PFID(&op_data->op_fid2),
PFID(&op_data->op_fid1), op_data->op_namelen,
op_data->op_name, rc);
return rc;
}
return rc;
}
int lmv_intent_lookup(struct obd_export *exp, struct md_op_data *op_data,
void *lmm, int lmmsize, struct lookup_intent *it,
int flags, struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct lmv_tgt_desc *tgt = NULL;
struct mdt_body *body;
int rc = 0;
tgt = lmv_locate_mds(lmv, op_data, &op_data->op_fid1);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
if (!fid_is_sane(&op_data->op_fid2))
fid_zero(&op_data->op_fid2);
CDEBUG(D_INODE, "LOOKUP_INTENT with fid1="DFID", fid2="DFID
", name='%s' -> mds #%d\n", PFID(&op_data->op_fid1),
PFID(&op_data->op_fid2),
op_data->op_name ? op_data->op_name : "<NULL>",
tgt->ltd_idx);
op_data->op_bias &= ~MDS_CROSS_REF;
rc = md_intent_lock(tgt->ltd_exp, op_data, lmm, lmmsize, it,
flags, reqp, cb_blocking, extra_lock_flags);
if (rc < 0 || *reqp == NULL)
return rc;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (body == NULL)
return -EPROTO;
if (likely(!(body->valid & OBD_MD_MDS)))
return 0;
rc = lmv_intent_remote(exp, lmm, lmmsize, it, NULL, flags, reqp,
cb_blocking, extra_lock_flags);
return rc;
}
int lmv_intent_lock(struct obd_export *exp, struct md_op_data *op_data,
void *lmm, int lmmsize, struct lookup_intent *it,
int flags, struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
int rc;
LASSERT(it != NULL);
LASSERT(fid_is_sane(&op_data->op_fid1));
CDEBUG(D_INODE, "INTENT LOCK '%s' for '%*s' on "DFID"\n",
LL_IT2STR(it), op_data->op_namelen, op_data->op_name,
PFID(&op_data->op_fid1));
rc = lmv_check_connect(obd);
if (rc)
return rc;
if (it->it_op & (IT_LOOKUP | IT_GETATTR | IT_LAYOUT))
rc = lmv_intent_lookup(exp, op_data, lmm, lmmsize, it,
flags, reqp, cb_blocking,
extra_lock_flags);
else if (it->it_op & IT_OPEN)
rc = lmv_intent_open(exp, op_data, lmm, lmmsize, it,
flags, reqp, cb_blocking,
extra_lock_flags);
else
LBUG();
return rc;
}
