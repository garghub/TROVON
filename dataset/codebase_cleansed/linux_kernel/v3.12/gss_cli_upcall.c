static
int ctx_init_pack_request(struct obd_import *imp,
struct ptlrpc_request *req,
int lustre_srv,
uid_t uid, gid_t gid,
long token_size,
char __user *token)
{
struct lustre_msg *msg = req->rq_reqbuf;
struct gss_sec *gsec;
struct gss_header *ghdr;
struct ptlrpc_user_desc *pud;
__u32 *p, size, offset = 2;
rawobj_t obj;
LASSERT(msg->lm_bufcount <= 4);
LASSERT(req->rq_cli_ctx);
LASSERT(req->rq_cli_ctx->cc_sec);
ghdr = lustre_msg_buf(msg, 0, sizeof(*ghdr));
ghdr->gh_version = PTLRPC_GSS_VERSION;
ghdr->gh_sp = (__u8) imp->imp_sec->ps_part;
ghdr->gh_flags = 0;
ghdr->gh_proc = PTLRPC_GSS_PROC_INIT;
ghdr->gh_seq = 0;
ghdr->gh_svc = SPTLRPC_SVC_NULL;
ghdr->gh_handle.len = 0;
if (req->rq_pack_udesc) {
ghdr->gh_flags |= LUSTRE_GSS_PACK_USER;
pud = lustre_msg_buf(msg, offset, sizeof(*pud));
LASSERT(pud);
pud->pud_uid = pud->pud_fsuid = uid;
pud->pud_gid = pud->pud_fsgid = gid;
pud->pud_cap = 0;
pud->pud_ngroups = 0;
offset++;
}
p = lustre_msg_buf(msg, offset, 0);
size = msg->lm_buflens[offset];
LASSERT(p);
LASSERT(size > 4);
*p++ = cpu_to_le32(lustre_srv);
size -= 4;
obj.len = strlen(imp->imp_obd->u.cli.cl_target_uuid.uuid) + 1;
obj.data = imp->imp_obd->u.cli.cl_target_uuid.uuid;
if (rawobj_serialize(&obj, &p, &size))
LBUG();
gsec = sec2gsec(req->rq_cli_ctx->cc_sec);
obj.len = sizeof(gsec->gs_rvs_hdl);
obj.data = (__u8 *) &gsec->gs_rvs_hdl;
if (rawobj_serialize(&obj, &p, &size))
LBUG();
LASSERT(size >= (sizeof(__u32) + token_size));
*p++ = cpu_to_le32(((__u32) token_size));
if (copy_from_user(p, token, token_size)) {
CERROR("can't copy token\n");
return -EFAULT;
}
size -= sizeof(__u32) + cfs_size_round4(token_size);
req->rq_reqdata_len = lustre_shrink_msg(req->rq_reqbuf, offset,
msg->lm_buflens[offset] - size, 0);
return 0;
}
static
int ctx_init_parse_reply(struct lustre_msg *msg, int swabbed,
char __user *outbuf, long outlen)
{
struct gss_rep_header *ghdr;
__u32 obj_len, round_len;
__u32 status, effective = 0;
if (msg->lm_bufcount != 3) {
CERROR("unexpected bufcount %u\n", msg->lm_bufcount);
return -EPROTO;
}
ghdr = (struct gss_rep_header *) gss_swab_header(msg, 0, swabbed);
if (ghdr == NULL) {
CERROR("unable to extract gss reply header\n");
return -EPROTO;
}
if (ghdr->gh_version != PTLRPC_GSS_VERSION) {
CERROR("invalid gss version %u\n", ghdr->gh_version);
return -EPROTO;
}
if (outlen < (4 + 2) * 4 + cfs_size_round4(ghdr->gh_handle.len) +
cfs_size_round4(msg->lm_buflens[2])) {
CERROR("output buffer size %ld too small\n", outlen);
return -EFAULT;
}
status = 0;
effective = 0;
if (copy_to_user(outbuf, &status, 4))
return -EFAULT;
outbuf += 4;
if (copy_to_user(outbuf, &ghdr->gh_major, 4))
return -EFAULT;
outbuf += 4;
if (copy_to_user(outbuf, &ghdr->gh_minor, 4))
return -EFAULT;
outbuf += 4;
if (copy_to_user(outbuf, &ghdr->gh_seqwin, 4))
return -EFAULT;
outbuf += 4;
effective += 4 * 4;
obj_len = ghdr->gh_handle.len;
round_len = (obj_len + 3) & ~ 3;
if (copy_to_user(outbuf, &obj_len, 4))
return -EFAULT;
outbuf += 4;
if (copy_to_user(outbuf, (char *) ghdr->gh_handle.data, round_len))
return -EFAULT;
outbuf += round_len;
effective += 4 + round_len;
obj_len = msg->lm_buflens[2];
round_len = (obj_len + 3) & ~ 3;
if (copy_to_user(outbuf, &obj_len, 4))
return -EFAULT;
outbuf += 4;
if (copy_to_user(outbuf, lustre_msg_buf(msg, 2, 0), round_len))
return -EFAULT;
outbuf += round_len;
effective += 4 + round_len;
return effective;
}
int gss_do_ctx_init_rpc(__user char *buffer, unsigned long count)
{
struct obd_import *imp;
struct ptlrpc_request *req;
struct lgssd_ioctl_param param;
struct obd_device *obd;
char obdname[64];
long lsize;
int rc;
if (count != sizeof(param)) {
CERROR("ioctl size %lu, expect %lu, please check lgss_keyring "
"version\n", count, (unsigned long) sizeof(param));
return -EINVAL;
}
if (copy_from_user(&param, buffer, sizeof(param))) {
CERROR("failed copy data from lgssd\n");
return -EFAULT;
}
if (param.version != GSSD_INTERFACE_VERSION) {
CERROR("gssd interface version %d (expect %d)\n",
param.version, GSSD_INTERFACE_VERSION);
return -EINVAL;
}
if (strncpy_from_user(obdname, param.uuid, sizeof(obdname)) <= 0) {
CERROR("Invalid obdname pointer\n");
return -EFAULT;
}
obd = class_name2obd(obdname);
if (!obd) {
CERROR("no such obd %s\n", obdname);
return -EINVAL;
}
if (unlikely(!obd->obd_set_up)) {
CERROR("obd %s not setup\n", obdname);
return -EINVAL;
}
spin_lock(&obd->obd_dev_lock);
if (obd->obd_stopping) {
CERROR("obd %s has stopped\n", obdname);
spin_unlock(&obd->obd_dev_lock);
return -EINVAL;
}
if (strcmp(obd->obd_type->typ_name, LUSTRE_MDC_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_OSC_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_MGC_NAME)) {
CERROR("obd %s is not a client device\n", obdname);
spin_unlock(&obd->obd_dev_lock);
return -EINVAL;
}
spin_unlock(&obd->obd_dev_lock);
down_read(&obd->u.cli.cl_sem);
if (obd->u.cli.cl_import == NULL) {
CERROR("obd %s: import has gone\n", obd->obd_name);
up_read(&obd->u.cli.cl_sem);
return -EINVAL;
}
imp = class_import_get(obd->u.cli.cl_import);
up_read(&obd->u.cli.cl_sem);
if (imp->imp_deactive) {
CERROR("import has been deactivated\n");
class_import_put(imp);
return -EINVAL;
}
req = ptlrpc_request_alloc_pack(imp, &RQF_SEC_CTX, LUSTRE_OBD_VERSION,
SEC_CTX_INIT);
if (req == NULL) {
param.status = -ENOMEM;
goto out_copy;
}
if (req->rq_cli_ctx->cc_sec->ps_id != param.secid) {
CWARN("original secid %d, now has changed to %d, "
"cancel this negotiation\n", param.secid,
req->rq_cli_ctx->cc_sec->ps_id);
param.status = -EINVAL;
goto out_copy;
}
rc = ctx_init_pack_request(imp, req,
param.lustre_svc,
param.uid, param.gid,
param.send_token_size,
param.send_token);
if (rc) {
param.status = rc;
goto out_copy;
}
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc) {
param.status = rc;
if (rc != -EACCES)
param.status = -ETIMEDOUT;
goto out_copy;
}
LASSERT(req->rq_repdata);
lsize = ctx_init_parse_reply(req->rq_repdata,
ptlrpc_rep_need_swab(req),
param.reply_buf, param.reply_buf_size);
if (lsize < 0) {
param.status = (int) lsize;
goto out_copy;
}
param.status = 0;
param.reply_length = lsize;
out_copy:
if (copy_to_user(buffer, &param, sizeof(param)))
rc = -EFAULT;
else
rc = 0;
class_import_put(imp);
ptlrpc_req_finished(req);
return rc;
}
int gss_do_ctx_fini_rpc(struct gss_cli_ctx *gctx)
{
struct ptlrpc_cli_ctx *ctx = &gctx->gc_base;
struct obd_import *imp = ctx->cc_sec->ps_import;
struct ptlrpc_request *req;
struct ptlrpc_user_desc *pud;
int rc;
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
if (cli_ctx_is_error(ctx) || !cli_ctx_is_uptodate(ctx)) {
CDEBUG(D_SEC, "ctx %p(%u->%s) not uptodate, "
"don't send destroy rpc\n", ctx,
ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec));
return 0;
}
might_sleep();
CWARN("%s ctx %p idx "LPX64" (%u->%s)\n",
sec_is_reverse(ctx->cc_sec) ?
"server finishing reverse" : "client finishing forward",
ctx, gss_handle_to_u64(&gctx->gc_handle),
ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec));
gctx->gc_proc = PTLRPC_GSS_PROC_DESTROY;
req = ptlrpc_request_alloc(imp, &RQF_SEC_CTX);
if (req == NULL) {
CWARN("ctx %p(%u): fail to prepare rpc, destroy locally\n",
ctx, ctx->cc_vcred.vc_uid);
GOTO(out, rc = -ENOMEM);
}
rc = ptlrpc_request_bufs_pack(req, LUSTRE_OBD_VERSION, SEC_CTX_FINI,
NULL, ctx);
if (rc) {
ptlrpc_request_free(req);
GOTO(out_ref, rc);
}
if (req->rq_pack_udesc) {
pud = lustre_msg_buf(req->rq_reqbuf, 2, sizeof(*pud));
LASSERT(pud);
pud->pud_uid = pud->pud_fsuid = ctx->cc_vcred.vc_uid;
pud->pud_gid = pud->pud_fsgid = ctx->cc_vcred.vc_gid;
pud->pud_cap = 0;
pud->pud_ngroups = 0;
}
req->rq_phase = RQ_PHASE_RPC;
rc = ptl_send_rpc(req, 1);
if (rc)
CWARN("ctx %p(%u->%s): rpc error %d, destroy locally\n", ctx,
ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec), rc);
out_ref:
ptlrpc_req_finished(req);
out:
return rc;
}
int __init gss_init_cli_upcall(void)
{
return 0;
}
void __exit gss_exit_cli_upcall(void)
{
}
