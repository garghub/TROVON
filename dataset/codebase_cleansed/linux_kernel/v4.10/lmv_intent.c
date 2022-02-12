static int lmv_intent_remote(struct obd_export *exp, struct lookup_intent *it,
const struct lu_fid *parent_fid,
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
if (!body)
return -EPROTO;
LASSERT((body->mbo_valid & OBD_MD_MDS));
if (it->it_op & IT_LOOKUP)
it->it_op = IT_GETATTR;
pmode = it->it_lock_mode;
if (pmode) {
plock.cookie = it->it_lock_handle;
it->it_lock_mode = 0;
it->it_request = NULL;
}
LASSERT(fid_is_sane(&body->mbo_fid1));
tgt = lmv_find_target(lmv, &body->mbo_fid1);
if (IS_ERR(tgt)) {
rc = PTR_ERR(tgt);
goto out;
}
op_data = kzalloc(sizeof(*op_data), GFP_NOFS);
if (!op_data) {
rc = -ENOMEM;
goto out;
}
op_data->op_fid1 = body->mbo_fid1;
if (parent_fid) {
LASSERT(it->it_op & IT_OPEN);
op_data->op_fid2 = *parent_fid;
}
op_data->op_bias = MDS_CROSS_REF;
CDEBUG(D_INODE, "REMOTE_INTENT with fid=" DFID " -> mds #%u\n",
PFID(&body->mbo_fid1), tgt->ltd_idx);
rc = md_intent_lock(tgt->ltd_exp, op_data, it, &req, cb_blocking,
extra_lock_flags);
if (rc)
goto out_free_op_data;
if (it->it_lock_mode != 0) {
it->it_remote_lock_handle =
it->it_lock_handle;
it->it_remote_lock_mode = it->it_lock_mode;
}
if (pmode) {
it->it_lock_handle = plock.cookie;
it->it_lock_mode = pmode;
}
out_free_op_data:
kfree(op_data);
out:
if (rc && pmode)
ldlm_lock_decref(&plock, pmode);
ptlrpc_req_finished(*reqp);
*reqp = req;
return rc;
}
int lmv_revalidate_slaves(struct obd_export *exp,
const struct lmv_stripe_md *lsm,
ldlm_blocking_callback cb_blocking,
int extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct ptlrpc_request *req = NULL;
struct mdt_body *body;
struct md_op_data *op_data;
int rc = 0, i;
op_data = kzalloc(sizeof(*op_data), GFP_NOFS);
if (!op_data)
return -ENOMEM;
for (i = 0; i < lsm->lsm_md_stripe_count; i++) {
struct lookup_intent it = { .it_op = IT_GETATTR };
struct lustre_handle *lockh = NULL;
struct lmv_tgt_desc *tgt = NULL;
struct inode *inode;
struct lu_fid fid;
fid = lsm->lsm_md_oinfo[i].lmo_fid;
inode = lsm->lsm_md_oinfo[i].lmo_root;
memset(op_data, 0, sizeof(*op_data));
op_data->op_fid1 = fid;
op_data->op_fid2 = fid;
tgt = lmv_locate_mds(lmv, op_data, &fid);
if (IS_ERR(tgt)) {
rc = PTR_ERR(tgt);
goto cleanup;
}
CDEBUG(D_INODE, "Revalidate slave " DFID " -> mds #%u\n",
PFID(&fid), tgt->ltd_idx);
if (req) {
ptlrpc_req_finished(req);
req = NULL;
}
rc = md_intent_lock(tgt->ltd_exp, op_data, &it, &req,
cb_blocking, extra_lock_flags);
if (rc < 0)
goto cleanup;
lockh = (struct lustre_handle *)&it.it_lock_handle;
if (rc > 0 && !req) {
CDEBUG(D_INODE, "slave "DFID" is still valid.\n",
PFID(&fid));
rc = 0;
} else {
body = req_capsule_server_get(&req->rq_pill,
&RMF_MDT_BODY);
LASSERT(body);
if (unlikely(body->mbo_nlink < 2)) {
CDEBUG(D_INODE, "%s: nlink %d < 2 corrupt stripe %d "DFID":" DFID"\n",
obd->obd_name, body->mbo_nlink, i,
PFID(&lsm->lsm_md_oinfo[i].lmo_fid),
PFID(&lsm->lsm_md_oinfo[0].lmo_fid));
if (it.it_lock_mode && lockh) {
ldlm_lock_decref(lockh, it.it_lock_mode);
it.it_lock_mode = 0;
}
rc = -ENOENT;
goto cleanup;
}
i_size_write(inode, body->mbo_size);
inode->i_blocks = body->mbo_blocks;
set_nlink(inode, body->mbo_nlink);
LTIME_S(inode->i_atime) = body->mbo_atime;
LTIME_S(inode->i_ctime) = body->mbo_ctime;
LTIME_S(inode->i_mtime) = body->mbo_mtime;
}
md_set_lock_data(tgt->ltd_exp, lockh, inode, NULL);
if (it.it_lock_mode && lockh) {
ldlm_lock_decref(lockh, it.it_lock_mode);
it.it_lock_mode = 0;
}
}
cleanup:
if (req)
ptlrpc_req_finished(req);
kfree(op_data);
return rc;
}
static int lmv_intent_open(struct obd_export *exp, struct md_op_data *op_data,
struct lookup_intent *it,
struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct lmv_tgt_desc *tgt;
struct mdt_body *body;
int rc;
if (it->it_flags & MDS_OPEN_BY_FID) {
LASSERT(fid_is_sane(&op_data->op_fid2));
if (op_data->op_mea1)
op_data->op_fid1 = op_data->op_fid2;
tgt = lmv_find_target(lmv, &op_data->op_fid2);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
op_data->op_mds = tgt->ltd_idx;
} else {
LASSERT(fid_is_sane(&op_data->op_fid1));
LASSERT(fid_is_zero(&op_data->op_fid2));
LASSERT(op_data->op_name);
tgt = lmv_locate_mds(lmv, op_data, &op_data->op_fid1);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
}
if ((it->it_op & IT_CREAT) && !(it->it_flags & MDS_OPEN_BY_FID)) {
rc = lmv_fid_alloc(NULL, exp, &op_data->op_fid2, op_data);
if (rc != 0)
return rc;
}
CDEBUG(D_INODE, "OPEN_INTENT with fid1=" DFID ", fid2=" DFID ", name='%s' -> mds #%u\n",
PFID(&op_data->op_fid1),
PFID(&op_data->op_fid2), op_data->op_name, tgt->ltd_idx);
rc = md_intent_lock(tgt->ltd_exp, op_data, it, reqp, cb_blocking,
extra_lock_flags);
if (rc != 0)
return rc;
if ((it->it_disposition & DISP_LOOKUP_NEG) &&
!(it->it_disposition & DISP_OPEN_CREATE) &&
!(it->it_disposition & DISP_OPEN_OPEN))
return rc;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (!body)
return -EPROTO;
if (unlikely((body->mbo_valid & OBD_MD_MDS))) {
rc = lmv_intent_remote(exp, it, &op_data->op_fid1, reqp,
cb_blocking, extra_lock_flags);
if (rc != 0)
return rc;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (!body)
return -EPROTO;
}
return rc;
}
static int lmv_intent_lookup(struct obd_export *exp,
struct md_op_data *op_data,
struct lookup_intent *it,
struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct lmv_stripe_md *lsm = op_data->op_mea1;
struct obd_device *obd = exp->exp_obd;
struct lmv_obd *lmv = &obd->u.lmv;
struct lmv_tgt_desc *tgt = NULL;
struct mdt_body *body;
int rc = 0;
tgt = lmv_locate_mds(lmv, op_data, &op_data->op_fid1);
if (IS_ERR(tgt) && (PTR_ERR(tgt) != -EBADFD))
return PTR_ERR(tgt);
if (lsm && !lmv_is_known_hash_type(lsm->lsm_md_hash_type)) {
struct lmv_oinfo *oinfo = &lsm->lsm_md_oinfo[0];
op_data->op_fid1 = oinfo->lmo_fid;
op_data->op_mds = oinfo->lmo_mds;
tgt = lmv_get_target(lmv, oinfo->lmo_mds, NULL);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
}
if (!fid_is_sane(&op_data->op_fid2))
fid_zero(&op_data->op_fid2);
CDEBUG(D_INODE, "LOOKUP_INTENT with fid1=" DFID ", fid2=" DFID ", name='%s' -> mds #%u lsm=%p lsm_magic=%x\n",
PFID(&op_data->op_fid1), PFID(&op_data->op_fid2),
op_data->op_name ? op_data->op_name : "<NULL>",
tgt->ltd_idx, lsm, !lsm ? -1 : lsm->lsm_md_magic);
op_data->op_bias &= ~MDS_CROSS_REF;
rc = md_intent_lock(tgt->ltd_exp, op_data, it, reqp, cb_blocking,
extra_lock_flags);
if (rc < 0)
return rc;
if (!*reqp) {
if (op_data->op_mea2) {
rc = lmv_revalidate_slaves(exp, op_data->op_mea2,
cb_blocking,
extra_lock_flags);
if (rc != 0)
return rc;
}
return rc;
} else if (it_disposition(it, DISP_LOOKUP_NEG) && lsm &&
lmv_need_try_all_stripes(lsm)) {
int stripe_index;
for (stripe_index = 1;
stripe_index < lsm->lsm_md_stripe_count &&
it_disposition(it, DISP_LOOKUP_NEG); stripe_index++) {
struct lmv_oinfo *oinfo;
ptlrpc_req_finished(*reqp);
it->it_request = NULL;
*reqp = NULL;
oinfo = &lsm->lsm_md_oinfo[stripe_index];
tgt = lmv_find_target(lmv, &oinfo->lmo_fid);
if (IS_ERR(tgt))
return PTR_ERR(tgt);
CDEBUG(D_INODE, "Try other stripes " DFID"\n",
PFID(&oinfo->lmo_fid));
op_data->op_fid1 = oinfo->lmo_fid;
it->it_disposition &= ~DISP_ENQ_COMPLETE;
rc = md_intent_lock(tgt->ltd_exp, op_data, it, reqp,
cb_blocking, extra_lock_flags);
if (rc)
return rc;
}
}
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (!body)
return -EPROTO;
if (unlikely((body->mbo_valid & OBD_MD_MDS))) {
rc = lmv_intent_remote(exp, it, NULL, reqp, cb_blocking,
extra_lock_flags);
if (rc != 0)
return rc;
body = req_capsule_server_get(&(*reqp)->rq_pill, &RMF_MDT_BODY);
if (!body)
return -EPROTO;
}
return rc;
}
int lmv_intent_lock(struct obd_export *exp, struct md_op_data *op_data,
struct lookup_intent *it, struct ptlrpc_request **reqp,
ldlm_blocking_callback cb_blocking,
__u64 extra_lock_flags)
{
struct obd_device *obd = exp->exp_obd;
int rc;
LASSERT(fid_is_sane(&op_data->op_fid1));
CDEBUG(D_INODE, "INTENT LOCK '%s' for "DFID" '%*s' on "DFID"\n",
LL_IT2STR(it), PFID(&op_data->op_fid2),
(int)op_data->op_namelen, op_data->op_name,
PFID(&op_data->op_fid1));
rc = lmv_check_connect(obd);
if (rc)
return rc;
if (it->it_op & (IT_LOOKUP | IT_GETATTR | IT_LAYOUT))
rc = lmv_intent_lookup(exp, op_data, it, reqp, cb_blocking,
extra_lock_flags);
else if (it->it_op & IT_OPEN)
rc = lmv_intent_open(exp, op_data, it, reqp, cb_blocking,
extra_lock_flags);
else
LBUG();
if (rc < 0) {
struct lustre_handle lock_handle;
if (it->it_lock_mode) {
lock_handle.cookie = it->it_lock_handle;
ldlm_lock_decref(&lock_handle, it->it_lock_mode);
}
it->it_lock_handle = 0;
it->it_lock_mode = 0;
if (it->it_remote_lock_mode) {
lock_handle.cookie = it->it_remote_lock_handle;
ldlm_lock_decref(&lock_handle,
it->it_remote_lock_mode);
}
it->it_remote_lock_handle = 0;
it->it_remote_lock_mode = 0;
}
return rc;
}
