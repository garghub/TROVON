static int llog_client_open(const struct lu_env *env,
struct llog_handle *lgh, struct llog_logid *logid,
char *name, enum llog_open_param open_param)
{
struct obd_import *imp;
struct llogd_body *body;
struct llog_ctxt *ctxt = lgh->lgh_ctxt;
struct ptlrpc_request *req = NULL;
int rc;
ENTRY;
LLOG_CLIENT_ENTRY(ctxt, imp);
LASSERTF(open_param != LLOG_OPEN_NEW, "%#x\n", open_param);
LASSERT(lgh);
req = ptlrpc_request_alloc(imp, &RQF_LLOG_ORIGIN_HANDLE_CREATE);
if (req == NULL)
GOTO(out, rc = -ENOMEM);
if (name)
req_capsule_set_size(&req->rq_pill, &RMF_NAME, RCL_CLIENT,
strlen(name) + 1);
rc = ptlrpc_request_pack(req, LUSTRE_LOG_VERSION,
LLOG_ORIGIN_HANDLE_CREATE);
if (rc) {
ptlrpc_request_free(req);
req = NULL;
GOTO(out, rc);
}
ptlrpc_request_set_replen(req);
body = req_capsule_client_get(&req->rq_pill, &RMF_LLOGD_BODY);
if (logid)
body->lgd_logid = *logid;
body->lgd_ctxt_idx = ctxt->loc_idx - 1;
if (name) {
char *tmp;
tmp = req_capsule_client_sized_get(&req->rq_pill, &RMF_NAME,
strlen(name) + 1);
LASSERT(tmp);
strcpy(tmp, name);
}
rc = ptlrpc_queue_wait(req);
if (rc)
GOTO(out, rc);
body = req_capsule_server_get(&req->rq_pill, &RMF_LLOGD_BODY);
if (body == NULL)
GOTO(out, rc = -EFAULT);
lgh->lgh_id = body->lgd_logid;
lgh->lgh_ctxt = ctxt;
EXIT;
out:
LLOG_CLIENT_EXIT(ctxt, imp);
ptlrpc_req_finished(req);
return rc;
}
static int llog_client_destroy(const struct lu_env *env,
struct llog_handle *loghandle)
{
struct obd_import *imp;
struct ptlrpc_request *req = NULL;
struct llogd_body *body;
int rc;
ENTRY;
LLOG_CLIENT_ENTRY(loghandle->lgh_ctxt, imp);
req = ptlrpc_request_alloc_pack(imp, &RQF_LLOG_ORIGIN_HANDLE_DESTROY,
LUSTRE_LOG_VERSION,
LLOG_ORIGIN_HANDLE_DESTROY);
if (req == NULL)
GOTO(err_exit, rc =-ENOMEM);
body = req_capsule_client_get(&req->rq_pill, &RMF_LLOGD_BODY);
body->lgd_logid = loghandle->lgh_id;
body->lgd_llh_flags = loghandle->lgh_hdr->llh_flags;
if (!(body->lgd_llh_flags & LLOG_F_IS_PLAIN))
CERROR("%s: wrong llog flags %x\n", imp->imp_obd->obd_name,
body->lgd_llh_flags);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
ptlrpc_req_finished(req);
err_exit:
LLOG_CLIENT_EXIT(loghandle->lgh_ctxt, imp);
RETURN(rc);
}
static int llog_client_next_block(const struct lu_env *env,
struct llog_handle *loghandle,
int *cur_idx, int next_idx,
__u64 *cur_offset, void *buf, int len)
{
struct obd_import *imp;
struct ptlrpc_request *req = NULL;
struct llogd_body *body;
void *ptr;
int rc;
ENTRY;
LLOG_CLIENT_ENTRY(loghandle->lgh_ctxt, imp);
req = ptlrpc_request_alloc_pack(imp, &RQF_LLOG_ORIGIN_HANDLE_NEXT_BLOCK,
LUSTRE_LOG_VERSION,
LLOG_ORIGIN_HANDLE_NEXT_BLOCK);
if (req == NULL)
GOTO(err_exit, rc =-ENOMEM);
body = req_capsule_client_get(&req->rq_pill, &RMF_LLOGD_BODY);
body->lgd_logid = loghandle->lgh_id;
body->lgd_ctxt_idx = loghandle->lgh_ctxt->loc_idx - 1;
body->lgd_llh_flags = loghandle->lgh_hdr->llh_flags;
body->lgd_index = next_idx;
body->lgd_saved_index = *cur_idx;
body->lgd_len = len;
body->lgd_cur_offset = *cur_offset;
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_SERVER, len);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc)
GOTO(out, rc);
body = req_capsule_server_get(&req->rq_pill, &RMF_LLOGD_BODY);
if (body == NULL)
GOTO(out, rc =-EFAULT);
ptr = req_capsule_server_get(&req->rq_pill, &RMF_EADATA);
if (ptr == NULL)
GOTO(out, rc =-EFAULT);
*cur_idx = body->lgd_saved_index;
*cur_offset = body->lgd_cur_offset;
memcpy(buf, ptr, len);
EXIT;
out:
ptlrpc_req_finished(req);
err_exit:
LLOG_CLIENT_EXIT(loghandle->lgh_ctxt, imp);
return rc;
}
static int llog_client_prev_block(const struct lu_env *env,
struct llog_handle *loghandle,
int prev_idx, void *buf, int len)
{
struct obd_import *imp;
struct ptlrpc_request *req = NULL;
struct llogd_body *body;
void *ptr;
int rc;
ENTRY;
LLOG_CLIENT_ENTRY(loghandle->lgh_ctxt, imp);
req = ptlrpc_request_alloc_pack(imp, &RQF_LLOG_ORIGIN_HANDLE_PREV_BLOCK,
LUSTRE_LOG_VERSION,
LLOG_ORIGIN_HANDLE_PREV_BLOCK);
if (req == NULL)
GOTO(err_exit, rc = -ENOMEM);
body = req_capsule_client_get(&req->rq_pill, &RMF_LLOGD_BODY);
body->lgd_logid = loghandle->lgh_id;
body->lgd_ctxt_idx = loghandle->lgh_ctxt->loc_idx - 1;
body->lgd_llh_flags = loghandle->lgh_hdr->llh_flags;
body->lgd_index = prev_idx;
body->lgd_len = len;
req_capsule_set_size(&req->rq_pill, &RMF_EADATA, RCL_SERVER, len);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc)
GOTO(out, rc);
body = req_capsule_server_get(&req->rq_pill, &RMF_LLOGD_BODY);
if (body == NULL)
GOTO(out, rc =-EFAULT);
ptr = req_capsule_server_get(&req->rq_pill, &RMF_EADATA);
if (ptr == NULL)
GOTO(out, rc =-EFAULT);
memcpy(buf, ptr, len);
EXIT;
out:
ptlrpc_req_finished(req);
err_exit:
LLOG_CLIENT_EXIT(loghandle->lgh_ctxt, imp);
return rc;
}
static int llog_client_read_header(const struct lu_env *env,
struct llog_handle *handle)
{
struct obd_import *imp;
struct ptlrpc_request *req = NULL;
struct llogd_body *body;
struct llog_log_hdr *hdr;
struct llog_rec_hdr *llh_hdr;
int rc;
ENTRY;
LLOG_CLIENT_ENTRY(handle->lgh_ctxt, imp);
req = ptlrpc_request_alloc_pack(imp,&RQF_LLOG_ORIGIN_HANDLE_READ_HEADER,
LUSTRE_LOG_VERSION,
LLOG_ORIGIN_HANDLE_READ_HEADER);
if (req == NULL)
GOTO(err_exit, rc = -ENOMEM);
body = req_capsule_client_get(&req->rq_pill, &RMF_LLOGD_BODY);
body->lgd_logid = handle->lgh_id;
body->lgd_ctxt_idx = handle->lgh_ctxt->loc_idx - 1;
body->lgd_llh_flags = handle->lgh_hdr->llh_flags;
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc)
GOTO(out, rc);
hdr = req_capsule_server_get(&req->rq_pill, &RMF_LLOG_LOG_HDR);
if (hdr == NULL)
GOTO(out, rc =-EFAULT);
memcpy(handle->lgh_hdr, hdr, sizeof (*hdr));
handle->lgh_last_idx = handle->lgh_hdr->llh_tail.lrt_index;
llh_hdr = &handle->lgh_hdr->llh_hdr;
if (llh_hdr->lrh_type != LLOG_HDR_MAGIC) {
CERROR("bad log header magic: %#x (expecting %#x)\n",
llh_hdr->lrh_type, LLOG_HDR_MAGIC);
rc = -EIO;
} else if (llh_hdr->lrh_len != LLOG_CHUNK_SIZE) {
CERROR("incorrectly sized log header: %#x "
"(expecting %#x)\n",
llh_hdr->lrh_len, LLOG_CHUNK_SIZE);
CERROR("you may need to re-run lconf --write_conf.\n");
rc = -EIO;
}
EXIT;
out:
ptlrpc_req_finished(req);
err_exit:
LLOG_CLIENT_EXIT(handle->lgh_ctxt, imp);
return rc;
}
static int llog_client_close(const struct lu_env *env,
struct llog_handle *handle)
{
return(0);
}
