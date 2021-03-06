static inline
void null_encode_sec_part(struct lustre_msg *msg, enum lustre_sec_part sp)
{
msg->lm_secflvr |= (((__u32) sp) & 0xFF) << 24;
}
static inline
enum lustre_sec_part null_decode_sec_part(struct lustre_msg *msg)
{
return (msg->lm_secflvr >> 24) & 0xFF;
}
static int null_ctx_refresh(struct ptlrpc_cli_ctx *ctx)
{
LBUG();
return 0;
}
static
int null_ctx_sign(struct ptlrpc_cli_ctx *ctx, struct ptlrpc_request *req)
{
req->rq_reqbuf->lm_secflvr = SPTLRPC_FLVR_NULL;
if (!req->rq_import->imp_dlm_fake) {
struct obd_device *obd = req->rq_import->imp_obd;
null_encode_sec_part(req->rq_reqbuf,
obd->u.cli.cl_sp_me);
}
req->rq_reqdata_len = req->rq_reqlen;
return 0;
}
static
int null_ctx_verify(struct ptlrpc_cli_ctx *ctx, struct ptlrpc_request *req)
{
__u32 cksums, cksumc;
LASSERT(req->rq_repdata);
req->rq_repmsg = req->rq_repdata;
req->rq_replen = req->rq_repdata_len;
if (req->rq_early) {
cksums = lustre_msg_get_cksum(req->rq_repdata);
cksumc = lustre_msg_calc_cksum(req->rq_repmsg);
if (cksumc != cksums) {
CDEBUG(D_SEC,
"early reply checksum mismatch: %08x != %08x\n",
cksumc, cksums);
return -EINVAL;
}
}
return 0;
}
static
struct ptlrpc_sec *null_create_sec(struct obd_import *imp,
struct ptlrpc_svc_ctx *svc_ctx,
struct sptlrpc_flavor *sf)
{
LASSERT(SPTLRPC_FLVR_POLICY(sf->sf_rpc) == SPTLRPC_POLICY_NULL);
sptlrpc_policy_put(&null_policy);
return &null_sec;
}
static
void null_destroy_sec(struct ptlrpc_sec *sec)
{
LASSERT(sec == &null_sec);
}
static
struct ptlrpc_cli_ctx *null_lookup_ctx(struct ptlrpc_sec *sec,
struct vfs_cred *vcred,
int create, int remove_dead)
{
atomic_inc(&null_cli_ctx.cc_refcount);
return &null_cli_ctx;
}
static
int null_flush_ctx_cache(struct ptlrpc_sec *sec,
uid_t uid,
int grace, int force)
{
return 0;
}
static
int null_alloc_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
if (!req->rq_reqbuf) {
int alloc_size = size_roundup_power2(msgsize);
LASSERT(!req->rq_pool);
req->rq_reqbuf = libcfs_kvzalloc(alloc_size, GFP_NOFS);
if (!req->rq_reqbuf)
return -ENOMEM;
req->rq_reqbuf_len = alloc_size;
} else {
LASSERT(req->rq_pool);
LASSERT(req->rq_reqbuf_len >= msgsize);
memset(req->rq_reqbuf, 0, msgsize);
}
req->rq_reqmsg = req->rq_reqbuf;
return 0;
}
static
void null_free_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req)
{
if (!req->rq_pool) {
LASSERTF(req->rq_reqmsg == req->rq_reqbuf,
"req %p: reqmsg %p is not reqbuf %p in null sec\n",
req, req->rq_reqmsg, req->rq_reqbuf);
LASSERTF(req->rq_reqbuf_len >= req->rq_reqlen,
"req %p: reqlen %d should smaller than buflen %d\n",
req, req->rq_reqlen, req->rq_reqbuf_len);
kvfree(req->rq_reqbuf);
req->rq_reqbuf = NULL;
req->rq_reqbuf_len = 0;
}
}
static
int null_alloc_repbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
msgsize += lustre_msg_early_size();
msgsize = size_roundup_power2(msgsize);
req->rq_repbuf = libcfs_kvzalloc(msgsize, GFP_NOFS);
if (!req->rq_repbuf)
return -ENOMEM;
req->rq_repbuf_len = msgsize;
return 0;
}
static
void null_free_repbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req)
{
LASSERT(req->rq_repbuf);
kvfree(req->rq_repbuf);
req->rq_repbuf = NULL;
req->rq_repbuf_len = 0;
}
static
int null_enlarge_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int segment, int newsize)
{
struct lustre_msg *newbuf;
struct lustre_msg *oldbuf = req->rq_reqmsg;
int oldsize, newmsg_size, alloc_size;
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_reqbuf == req->rq_reqmsg);
LASSERT(req->rq_reqbuf_len >= req->rq_reqlen);
LASSERT(req->rq_reqlen == lustre_packed_msg_size(oldbuf));
oldsize = req->rq_reqbuf->lm_buflens[segment];
req->rq_reqbuf->lm_buflens[segment] = newsize;
newmsg_size = lustre_packed_msg_size(oldbuf);
req->rq_reqbuf->lm_buflens[segment] = oldsize;
LASSERT(!req->rq_pool || req->rq_reqbuf_len >= newmsg_size);
if (req->rq_reqbuf_len < newmsg_size) {
alloc_size = size_roundup_power2(newmsg_size);
newbuf = libcfs_kvzalloc(alloc_size, GFP_NOFS);
if (newbuf == NULL)
return -ENOMEM;
if (req->rq_import)
spin_lock(&req->rq_import->imp_lock);
memcpy(newbuf, req->rq_reqbuf, req->rq_reqlen);
kvfree(req->rq_reqbuf);
req->rq_reqbuf = req->rq_reqmsg = newbuf;
req->rq_reqbuf_len = alloc_size;
if (req->rq_import)
spin_unlock(&req->rq_import->imp_lock);
}
_sptlrpc_enlarge_msg_inplace(req->rq_reqmsg, segment, newsize);
req->rq_reqlen = newmsg_size;
return 0;
}
static
int null_accept(struct ptlrpc_request *req)
{
LASSERT(SPTLRPC_FLVR_POLICY(req->rq_flvr.sf_rpc) ==
SPTLRPC_POLICY_NULL);
if (req->rq_flvr.sf_rpc != SPTLRPC_FLVR_NULL) {
CERROR("Invalid rpc flavor 0x%x\n", req->rq_flvr.sf_rpc);
return SECSVC_DROP;
}
req->rq_sp_from = null_decode_sec_part(req->rq_reqbuf);
req->rq_reqmsg = req->rq_reqbuf;
req->rq_reqlen = req->rq_reqdata_len;
req->rq_svc_ctx = &null_svc_ctx;
atomic_inc(&req->rq_svc_ctx->sc_refcount);
return SECSVC_OK;
}
static
int null_alloc_rs(struct ptlrpc_request *req, int msgsize)
{
struct ptlrpc_reply_state *rs;
int rs_size = sizeof(*rs) + msgsize;
LASSERT(msgsize % 8 == 0);
rs = req->rq_reply_state;
if (rs) {
LASSERT(rs->rs_size >= rs_size);
} else {
rs = libcfs_kvzalloc(rs_size, GFP_NOFS);
if (rs == NULL)
return -ENOMEM;
rs->rs_size = rs_size;
}
rs->rs_svc_ctx = req->rq_svc_ctx;
atomic_inc(&req->rq_svc_ctx->sc_refcount);
rs->rs_repbuf = (struct lustre_msg *) (rs + 1);
rs->rs_repbuf_len = rs_size - sizeof(*rs);
rs->rs_msg = rs->rs_repbuf;
req->rq_reply_state = rs;
return 0;
}
static
void null_free_rs(struct ptlrpc_reply_state *rs)
{
LASSERT_ATOMIC_GT(&rs->rs_svc_ctx->sc_refcount, 1);
atomic_dec(&rs->rs_svc_ctx->sc_refcount);
if (!rs->rs_prealloc)
kvfree(rs);
}
static
int null_authorize(struct ptlrpc_request *req)
{
struct ptlrpc_reply_state *rs = req->rq_reply_state;
LASSERT(rs);
rs->rs_repbuf->lm_secflvr = SPTLRPC_FLVR_NULL;
rs->rs_repdata_len = req->rq_replen;
if (likely(req->rq_packed_final)) {
if (lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT)
req->rq_reply_off = lustre_msg_early_size();
else
req->rq_reply_off = 0;
} else {
__u32 cksum;
cksum = lustre_msg_calc_cksum(rs->rs_repbuf);
lustre_msg_set_cksum(rs->rs_repbuf, cksum);
req->rq_reply_off = 0;
}
return 0;
}
static void null_init_internal(void)
{
static HLIST_HEAD(__list);
null_sec.ps_policy = &null_policy;
atomic_set(&null_sec.ps_refcount, 1);
null_sec.ps_id = -1;
null_sec.ps_import = NULL;
null_sec.ps_flvr.sf_rpc = SPTLRPC_FLVR_NULL;
null_sec.ps_flvr.sf_flags = 0;
null_sec.ps_part = LUSTRE_SP_ANY;
null_sec.ps_dying = 0;
spin_lock_init(&null_sec.ps_lock);
atomic_set(&null_sec.ps_nctx, 1);
INIT_LIST_HEAD(&null_sec.ps_gc_list);
null_sec.ps_gc_interval = 0;
null_sec.ps_gc_next = 0;
hlist_add_head(&null_cli_ctx.cc_cache, &__list);
atomic_set(&null_cli_ctx.cc_refcount, 1);
null_cli_ctx.cc_sec = &null_sec;
null_cli_ctx.cc_ops = &null_ctx_ops;
null_cli_ctx.cc_expire = 0;
null_cli_ctx.cc_flags = PTLRPC_CTX_CACHED | PTLRPC_CTX_ETERNAL |
PTLRPC_CTX_UPTODATE;
null_cli_ctx.cc_vcred.vc_uid = 0;
spin_lock_init(&null_cli_ctx.cc_lock);
INIT_LIST_HEAD(&null_cli_ctx.cc_req_list);
INIT_LIST_HEAD(&null_cli_ctx.cc_gc_chain);
}
int sptlrpc_null_init(void)
{
int rc;
null_init_internal();
rc = sptlrpc_register_policy(&null_policy);
if (rc)
CERROR("failed to register %s: %d\n", null_policy.sp_name, rc);
return rc;
}
void sptlrpc_null_fini(void)
{
int rc;
rc = sptlrpc_unregister_policy(&null_policy);
if (rc)
CERROR("failed to unregister %s: %d\n",
null_policy.sp_name, rc);
}
