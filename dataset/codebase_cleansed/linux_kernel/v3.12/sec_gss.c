static inline int msg_last_segidx(struct lustre_msg *msg)
{
LASSERT(msg->lm_bufcount > 0);
return msg->lm_bufcount - 1;
}
static inline int msg_last_seglen(struct lustre_msg *msg)
{
return msg->lm_buflens[msg_last_segidx(msg)];
}
static
void gss_header_swabber(struct gss_header *ghdr)
{
__swab32s(&ghdr->gh_flags);
__swab32s(&ghdr->gh_proc);
__swab32s(&ghdr->gh_seq);
__swab32s(&ghdr->gh_svc);
__swab32s(&ghdr->gh_pad1);
__swab32s(&ghdr->gh_handle.len);
}
struct gss_header *gss_swab_header(struct lustre_msg *msg, int segment,
int swabbed)
{
struct gss_header *ghdr;
ghdr = lustre_msg_buf(msg, segment, sizeof(*ghdr));
if (ghdr == NULL)
return NULL;
if (swabbed)
gss_header_swabber(ghdr);
if (sizeof(*ghdr) + ghdr->gh_handle.len > msg->lm_buflens[segment]) {
CERROR("gss header has length %d, now %u received\n",
(int) sizeof(*ghdr) + ghdr->gh_handle.len,
msg->lm_buflens[segment]);
return NULL;
}
return ghdr;
}
static inline
int gss_mech_payload(struct gss_ctx *mechctx, int msgsize, int privacy)
{
if (privacy)
return GSS_KRB5_INTEG_MAX_PAYLOAD + 16 + 16 + 16 + msgsize;
else
return GSS_KRB5_INTEG_MAX_PAYLOAD;
}
static int gss_sign_msg(struct lustre_msg *msg,
struct gss_ctx *mechctx,
enum lustre_sec_part sp,
__u32 flags, __u32 proc, __u32 seq, __u32 svc,
rawobj_t *handle)
{
struct gss_header *ghdr;
rawobj_t text[4], mic;
int textcnt, max_textcnt, mic_idx;
__u32 major;
LASSERT(msg->lm_bufcount >= 2);
LASSERT(msg->lm_buflens[0] >=
sizeof(*ghdr) + (handle ? handle->len : 0));
ghdr = lustre_msg_buf(msg, 0, 0);
ghdr->gh_version = PTLRPC_GSS_VERSION;
ghdr->gh_sp = (__u8) sp;
ghdr->gh_flags = flags;
ghdr->gh_proc = proc;
ghdr->gh_seq = seq;
ghdr->gh_svc = svc;
if (!handle) {
ghdr->gh_handle.len = 0;
} else {
ghdr->gh_handle.len = handle->len;
memcpy(ghdr->gh_handle.data, handle->data, handle->len);
}
if (svc == SPTLRPC_SVC_NULL)
return lustre_msg_size_v2(msg->lm_bufcount, msg->lm_buflens);
mic_idx = msg_last_segidx(msg);
max_textcnt = (svc == SPTLRPC_SVC_AUTH) ? 1 : mic_idx;
for (textcnt = 0; textcnt < max_textcnt; textcnt++) {
text[textcnt].len = msg->lm_buflens[textcnt];
text[textcnt].data = lustre_msg_buf(msg, textcnt, 0);
}
mic.len = msg->lm_buflens[mic_idx];
mic.data = lustre_msg_buf(msg, mic_idx, 0);
major = lgss_get_mic(mechctx, textcnt, text, 0, NULL, &mic);
if (major != GSS_S_COMPLETE) {
CERROR("fail to generate MIC: %08x\n", major);
return -EPERM;
}
LASSERT(mic.len <= msg->lm_buflens[mic_idx]);
return lustre_shrink_msg(msg, mic_idx, mic.len, 0);
}
static
__u32 gss_verify_msg(struct lustre_msg *msg,
struct gss_ctx *mechctx,
__u32 svc)
{
rawobj_t text[4], mic;
int textcnt, max_textcnt;
int mic_idx;
__u32 major;
LASSERT(msg->lm_bufcount >= 2);
if (svc == SPTLRPC_SVC_NULL)
return GSS_S_COMPLETE;
mic_idx = msg_last_segidx(msg);
max_textcnt = (svc == SPTLRPC_SVC_AUTH) ? 1 : mic_idx;
for (textcnt = 0; textcnt < max_textcnt; textcnt++) {
text[textcnt].len = msg->lm_buflens[textcnt];
text[textcnt].data = lustre_msg_buf(msg, textcnt, 0);
}
mic.len = msg->lm_buflens[mic_idx];
mic.data = lustre_msg_buf(msg, mic_idx, 0);
major = lgss_verify_mic(mechctx, textcnt, text, 0, NULL, &mic);
if (major != GSS_S_COMPLETE)
CERROR("mic verify error: %08x\n", major);
return major;
}
static
__u32 gss_unseal_msg(struct gss_ctx *mechctx,
struct lustre_msg *msgbuf,
int *msg_len, int msgbuf_len)
{
rawobj_t clear_obj, hdrobj, token;
__u8 *clear_buf;
int clear_buflen;
__u32 major;
if (msgbuf->lm_bufcount != 2) {
CERROR("invalid bufcount %d\n", msgbuf->lm_bufcount);
return GSS_S_FAILURE;
}
clear_buflen = lustre_msg_buflen(msgbuf, 1);
OBD_ALLOC_LARGE(clear_buf, clear_buflen);
if (!clear_buf)
return GSS_S_FAILURE;
hdrobj.len = lustre_msg_buflen(msgbuf, 0);
hdrobj.data = lustre_msg_buf(msgbuf, 0, 0);
token.len = lustre_msg_buflen(msgbuf, 1);
token.data = lustre_msg_buf(msgbuf, 1, 0);
clear_obj.len = clear_buflen;
clear_obj.data = clear_buf;
major = lgss_unwrap(mechctx, &hdrobj, &token, &clear_obj);
if (major != GSS_S_COMPLETE) {
CERROR("unwrap message error: %08x\n", major);
GOTO(out_free, major = GSS_S_FAILURE);
}
LASSERT(clear_obj.len <= clear_buflen);
LASSERT(clear_obj.len <= msgbuf_len);
memcpy(msgbuf, clear_obj.data, clear_obj.len);
*msg_len = clear_obj.len;
major = GSS_S_COMPLETE;
out_free:
OBD_FREE_LARGE(clear_buf, clear_buflen);
return major;
}
int cli_ctx_expire(struct ptlrpc_cli_ctx *ctx)
{
LASSERT(atomic_read(&ctx->cc_refcount));
if (!test_and_set_bit(PTLRPC_CTX_DEAD_BIT, &ctx->cc_flags)) {
if (!ctx->cc_early_expire)
clear_bit(PTLRPC_CTX_UPTODATE_BIT, &ctx->cc_flags);
CWARN("ctx %p(%u->%s) get expired: %lu(%+lds)\n",
ctx, ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec),
ctx->cc_expire,
ctx->cc_expire == 0 ? 0 :
cfs_time_sub(ctx->cc_expire, cfs_time_current_sec()));
sptlrpc_cli_ctx_wakeup(ctx);
return 1;
}
return 0;
}
int cli_ctx_check_death(struct ptlrpc_cli_ctx *ctx)
{
if (unlikely(cli_ctx_is_dead(ctx)))
return 1;
if (ctx->cc_expire == 0)
return 0;
if (cfs_time_after(ctx->cc_expire, cfs_time_current_sec()))
return 0;
cli_ctx_expire(ctx);
return 1;
}
void gss_cli_ctx_uptodate(struct gss_cli_ctx *gctx)
{
struct ptlrpc_cli_ctx *ctx = &gctx->gc_base;
unsigned long ctx_expiry;
if (lgss_inquire_context(gctx->gc_mechctx, &ctx_expiry)) {
CERROR("ctx %p(%u): unable to inquire, expire it now\n",
gctx, ctx->cc_vcred.vc_uid);
ctx_expiry = 1;
}
ctx->cc_expire = gss_round_ctx_expiry(ctx_expiry,
ctx->cc_sec->ps_flvr.sf_flags);
set_bit(PTLRPC_CTX_UPTODATE_BIT, &ctx->cc_flags);
if (sec_is_reverse(ctx->cc_sec)) {
CWARN("server installed reverse ctx %p idx "LPX64", "
"expiry %lu(%+lds)\n", ctx,
gss_handle_to_u64(&gctx->gc_handle),
ctx->cc_expire, ctx->cc_expire - cfs_time_current_sec());
} else {
CWARN("client refreshed ctx %p idx "LPX64" (%u->%s), "
"expiry %lu(%+lds)\n", ctx,
gss_handle_to_u64(&gctx->gc_handle),
ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec),
ctx->cc_expire, ctx->cc_expire - cfs_time_current_sec());
if (ctx->cc_vcred.vc_uid == 0)
gss_sec_install_rctx(ctx->cc_sec->ps_import,
ctx->cc_sec, ctx);
}
sptlrpc_cli_ctx_wakeup(ctx);
}
static void gss_cli_ctx_finalize(struct gss_cli_ctx *gctx)
{
LASSERT(gctx->gc_base.cc_sec);
if (gctx->gc_mechctx) {
lgss_delete_sec_context(&gctx->gc_mechctx);
gctx->gc_mechctx = NULL;
}
if (!rawobj_empty(&gctx->gc_svc_handle)) {
if (!sec_is_reverse(gctx->gc_base.cc_sec) &&
!rawobj_empty(&gctx->gc_svc_handle))
gss_svc_upcall_expire_rvs_ctx(&gctx->gc_svc_handle);
rawobj_free(&gctx->gc_svc_handle);
}
rawobj_free(&gctx->gc_handle);
}
static
int gss_do_check_seq(unsigned long *window, __u32 win_size, __u32 *max_seq,
__u32 seq_num, int phase)
{
LASSERT(phase >= 0 && phase <= 2);
if (seq_num > *max_seq) {
if (phase == 0)
return 0;
if (seq_num >= *max_seq + win_size) {
memset(window, 0, win_size / 8);
*max_seq = seq_num;
} else {
while(*max_seq < seq_num) {
(*max_seq)++;
__clear_bit((*max_seq) % win_size, window);
}
}
__set_bit(seq_num % win_size, window);
} else if (seq_num + win_size <= *max_seq) {
if (phase == 0 || phase == 2)
goto replay;
CWARN("seq %u is %u behind (size %d), check backup window\n",
seq_num, *max_seq - win_size - seq_num, win_size);
return 1;
} else {
switch (phase) {
case 0:
if (test_bit(seq_num % win_size, window))
goto replay;
break;
case 1:
case 2:
if (__test_and_set_bit(seq_num % win_size, window))
goto replay;
break;
}
}
return 0;
replay:
CERROR("seq %u (%s %s window) is a replay: max %u, winsize %d\n",
seq_num,
seq_num + win_size > *max_seq ? "in" : "behind",
phase == 2 ? "backup " : "main",
*max_seq, win_size);
return -1;
}
int gss_check_seq_num(struct gss_svc_seq_data *ssd, __u32 seq_num, int set)
{
int rc = 0;
spin_lock(&ssd->ssd_lock);
if (set == 0) {
rc = gss_do_check_seq(ssd->ssd_win_main, GSS_SEQ_WIN_MAIN,
&ssd->ssd_max_main, seq_num, 0);
if (unlikely(rc))
gss_stat_oos_record_svc(0, 1);
} else {
rc = gss_do_check_seq(ssd->ssd_win_main, GSS_SEQ_WIN_MAIN,
&ssd->ssd_max_main, seq_num, 1);
switch (rc) {
case -1:
gss_stat_oos_record_svc(1, 1);
case 0:
goto exit;
}
rc = gss_do_check_seq(ssd->ssd_win_back, GSS_SEQ_WIN_BACK,
&ssd->ssd_max_back, seq_num, 2);
if (rc)
gss_stat_oos_record_svc(2, 1);
else
gss_stat_oos_record_svc(2, 0);
}
exit:
spin_unlock(&ssd->ssd_lock);
return rc;
}
static inline int gss_cli_payload(struct ptlrpc_cli_ctx *ctx,
int msgsize, int privacy)
{
return gss_mech_payload(NULL, msgsize, privacy);
}
static int gss_cli_bulk_payload(struct ptlrpc_cli_ctx *ctx,
struct sptlrpc_flavor *flvr,
int reply, int read)
{
int payload = sizeof(struct ptlrpc_bulk_sec_desc);
LASSERT(SPTLRPC_FLVR_BULK_TYPE(flvr->sf_rpc) == SPTLRPC_BULK_DEFAULT);
if ((!reply && !read) || (reply && read)) {
switch (SPTLRPC_FLVR_BULK_SVC(flvr->sf_rpc)) {
case SPTLRPC_BULK_SVC_NULL:
break;
case SPTLRPC_BULK_SVC_INTG:
payload += gss_cli_payload(ctx, 0, 0);
break;
case SPTLRPC_BULK_SVC_PRIV:
payload += gss_cli_payload(ctx, 0, 1);
break;
case SPTLRPC_BULK_SVC_AUTH:
default:
LBUG();
}
}
return payload;
}
int gss_cli_ctx_match(struct ptlrpc_cli_ctx *ctx, struct vfs_cred *vcred)
{
return (ctx->cc_vcred.vc_uid == vcred->vc_uid);
}
void gss_cli_ctx_flags2str(unsigned long flags, char *buf, int bufsize)
{
buf[0] = '\0';
if (flags & PTLRPC_CTX_NEW)
strncat(buf, "new,", bufsize);
if (flags & PTLRPC_CTX_UPTODATE)
strncat(buf, "uptodate,", bufsize);
if (flags & PTLRPC_CTX_DEAD)
strncat(buf, "dead,", bufsize);
if (flags & PTLRPC_CTX_ERROR)
strncat(buf, "error,", bufsize);
if (flags & PTLRPC_CTX_CACHED)
strncat(buf, "cached,", bufsize);
if (flags & PTLRPC_CTX_ETERNAL)
strncat(buf, "eternal,", bufsize);
if (buf[0] == '\0')
strncat(buf, "-,", bufsize);
buf[strlen(buf) - 1] = '\0';
}
int gss_cli_ctx_sign(struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_request *req)
{
struct gss_cli_ctx *gctx = ctx2gctx(ctx);
__u32 flags = 0, seq, svc;
int rc;
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_reqbuf->lm_bufcount >= 2);
LASSERT(req->rq_cli_ctx == ctx);
if (req->rq_ctx_init)
return 0;
svc = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc);
if (req->rq_pack_bulk)
flags |= LUSTRE_GSS_PACK_BULK;
if (req->rq_pack_udesc)
flags |= LUSTRE_GSS_PACK_USER;
redo:
seq = atomic_inc_return(&gctx->gc_seq);
rc = gss_sign_msg(req->rq_reqbuf, gctx->gc_mechctx,
ctx->cc_sec->ps_part,
flags, gctx->gc_proc, seq, svc,
&gctx->gc_handle);
if (rc < 0)
return rc;
if (svc != SPTLRPC_SVC_NULL &&
atomic_read(&gctx->gc_seq) - seq > GSS_SEQ_REPACK_THRESHOLD) {
int behind = atomic_read(&gctx->gc_seq) - seq;
gss_stat_oos_record_cli(behind);
CWARN("req %p: %u behind, retry signing\n", req, behind);
goto redo;
}
req->rq_reqdata_len = rc;
return 0;
}
static
int gss_cli_ctx_handle_err_notify(struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_request *req,
struct gss_header *ghdr)
{
struct gss_err_header *errhdr;
int rc;
LASSERT(ghdr->gh_proc == PTLRPC_GSS_PROC_ERR);
errhdr = (struct gss_err_header *) ghdr;
CWARN("req x"LPU64"/t"LPU64", ctx %p idx "LPX64"(%u->%s): "
"%sserver respond (%08x/%08x)\n",
req->rq_xid, req->rq_transno, ctx,
gss_handle_to_u64(&ctx2gctx(ctx)->gc_handle),
ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec),
sec_is_reverse(ctx->cc_sec) ? "reverse" : "",
errhdr->gh_major, errhdr->gh_minor);
if (req->rq_ctx_fini) {
CWARN("context fini rpc failed\n");
return -EINVAL;
}
if (sec_is_reverse(ctx->cc_sec))
return -EINVAL;
if (errhdr->gh_major != GSS_S_NO_CONTEXT &&
errhdr->gh_major != GSS_S_BAD_SIG)
return -EACCES;
CWARN("%s: server might lost the context, retrying\n",
errhdr->gh_major == GSS_S_NO_CONTEXT ? "NO_CONTEXT" : "BAD_SIG");
sptlrpc_cli_ctx_expire(ctx);
rc = sptlrpc_req_replace_dead_ctx(req);
if (rc == 0)
req->rq_resend = 1;
return rc;
}
int gss_cli_ctx_verify(struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_request *req)
{
struct gss_cli_ctx *gctx;
struct gss_header *ghdr, *reqhdr;
struct lustre_msg *msg = req->rq_repdata;
__u32 major;
int pack_bulk, swabbed, rc = 0;
LASSERT(req->rq_cli_ctx == ctx);
LASSERT(msg);
gctx = container_of(ctx, struct gss_cli_ctx, gc_base);
if (req->rq_ctx_init && !req->rq_early) {
req->rq_repmsg = lustre_msg_buf(msg, 1, 0);
req->rq_replen = msg->lm_buflens[1];
return 0;
}
if (msg->lm_bufcount < 2 || msg->lm_bufcount > 4) {
CERROR("unexpected bufcount %u\n", msg->lm_bufcount);
return -EPROTO;
}
swabbed = ptlrpc_rep_need_swab(req);
ghdr = gss_swab_header(msg, 0, swabbed);
if (ghdr == NULL) {
CERROR("can't decode gss header\n");
return -EPROTO;
}
reqhdr = lustre_msg_buf(msg, 0, sizeof(*reqhdr));
LASSERT(reqhdr);
if (ghdr->gh_version != reqhdr->gh_version) {
CERROR("gss version %u mismatch, expect %u\n",
ghdr->gh_version, reqhdr->gh_version);
return -EPROTO;
}
switch (ghdr->gh_proc) {
case PTLRPC_GSS_PROC_DATA:
pack_bulk = ghdr->gh_flags & LUSTRE_GSS_PACK_BULK;
if (!req->rq_early && !equi(req->rq_pack_bulk == 1, pack_bulk)){
CERROR("%s bulk flag in reply\n",
req->rq_pack_bulk ? "missing" : "unexpected");
return -EPROTO;
}
if (ghdr->gh_seq != reqhdr->gh_seq) {
CERROR("seqnum %u mismatch, expect %u\n",
ghdr->gh_seq, reqhdr->gh_seq);
return -EPROTO;
}
if (ghdr->gh_svc != reqhdr->gh_svc) {
CERROR("svc %u mismatch, expect %u\n",
ghdr->gh_svc, reqhdr->gh_svc);
return -EPROTO;
}
if (swabbed)
gss_header_swabber(ghdr);
major = gss_verify_msg(msg, gctx->gc_mechctx, reqhdr->gh_svc);
if (major != GSS_S_COMPLETE) {
CERROR("failed to verify reply: %x\n", major);
return -EPERM;
}
if (req->rq_early && reqhdr->gh_svc == SPTLRPC_SVC_NULL) {
__u32 cksum;
cksum = crc32_le(!(__u32) 0,
lustre_msg_buf(msg, 1, 0),
lustre_msg_buflen(msg, 1));
if (cksum != msg->lm_cksum) {
CWARN("early reply checksum mismatch: "
"%08x != %08x\n", cksum, msg->lm_cksum);
return -EPROTO;
}
}
if (pack_bulk) {
if (msg->lm_bufcount < 3) {
CERROR("Invalid reply bufcount %u\n",
msg->lm_bufcount);
return -EPROTO;
}
rc = bulk_sec_desc_unpack(msg, 2, swabbed);
if (rc) {
CERROR("unpack bulk desc: %d\n", rc);
return rc;
}
}
req->rq_repmsg = lustre_msg_buf(msg, 1, 0);
req->rq_replen = msg->lm_buflens[1];
break;
case PTLRPC_GSS_PROC_ERR:
if (req->rq_early) {
CERROR("server return error with early reply\n");
rc = -EPROTO;
} else {
rc = gss_cli_ctx_handle_err_notify(ctx, req, ghdr);
}
break;
default:
CERROR("unknown gss proc %d\n", ghdr->gh_proc);
rc = -EPROTO;
}
return rc;
}
int gss_cli_ctx_seal(struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_request *req)
{
struct gss_cli_ctx *gctx;
rawobj_t hdrobj, msgobj, token;
struct gss_header *ghdr;
__u32 buflens[2], major;
int wiresize, rc;
LASSERT(req->rq_clrbuf);
LASSERT(req->rq_cli_ctx == ctx);
LASSERT(req->rq_reqlen);
gctx = container_of(ctx, struct gss_cli_ctx, gc_base);
req->rq_clrdata_len = lustre_msg_size_v2(req->rq_clrbuf->lm_bufcount,
req->rq_clrbuf->lm_buflens);
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = gss_cli_payload(&gctx->gc_base, req->rq_clrdata_len, 1);
wiresize = lustre_msg_size_v2(2, buflens);
if (req->rq_pool) {
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_reqbuf != req->rq_clrbuf);
LASSERT(req->rq_reqbuf_len >= wiresize);
} else {
OBD_ALLOC_LARGE(req->rq_reqbuf, wiresize);
if (!req->rq_reqbuf)
return -ENOMEM;
req->rq_reqbuf_len = wiresize;
}
lustre_init_msg_v2(req->rq_reqbuf, 2, buflens, NULL);
req->rq_reqbuf->lm_secflvr = req->rq_flvr.sf_rpc;
ghdr = lustre_msg_buf(req->rq_reqbuf, 0, 0);
ghdr->gh_version = PTLRPC_GSS_VERSION;
ghdr->gh_sp = (__u8) ctx->cc_sec->ps_part;
ghdr->gh_flags = 0;
ghdr->gh_proc = gctx->gc_proc;
ghdr->gh_svc = SPTLRPC_SVC_PRIV;
ghdr->gh_handle.len = gctx->gc_handle.len;
memcpy(ghdr->gh_handle.data, gctx->gc_handle.data, gctx->gc_handle.len);
if (req->rq_pack_bulk)
ghdr->gh_flags |= LUSTRE_GSS_PACK_BULK;
if (req->rq_pack_udesc)
ghdr->gh_flags |= LUSTRE_GSS_PACK_USER;
redo:
ghdr->gh_seq = atomic_inc_return(&gctx->gc_seq);
hdrobj.len = PTLRPC_GSS_HEADER_SIZE;
hdrobj.data = (__u8 *) ghdr;
msgobj.len = req->rq_clrdata_len;
msgobj.data = (__u8 *) req->rq_clrbuf;
token.len = lustre_msg_buflen(req->rq_reqbuf, 1);
token.data = lustre_msg_buf(req->rq_reqbuf, 1, 0);
major = lgss_wrap(gctx->gc_mechctx, &hdrobj, &msgobj,
req->rq_clrbuf_len, &token);
if (major != GSS_S_COMPLETE) {
CERROR("priv: wrap message error: %08x\n", major);
GOTO(err_free, rc = -EPERM);
}
LASSERT(token.len <= buflens[1]);
if (unlikely(atomic_read(&gctx->gc_seq) - ghdr->gh_seq >
GSS_SEQ_REPACK_THRESHOLD)) {
int behind = atomic_read(&gctx->gc_seq) - ghdr->gh_seq;
gss_stat_oos_record_cli(behind);
CWARN("req %p: %u behind, retry sealing\n", req, behind);
ghdr->gh_seq = atomic_inc_return(&gctx->gc_seq);
goto redo;
}
req->rq_reqdata_len = lustre_shrink_msg(req->rq_reqbuf, 1, token.len,0);
return 0;
err_free:
if (!req->rq_pool) {
OBD_FREE_LARGE(req->rq_reqbuf, req->rq_reqbuf_len);
req->rq_reqbuf = NULL;
req->rq_reqbuf_len = 0;
}
return rc;
}
int gss_cli_ctx_unseal(struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_request *req)
{
struct gss_cli_ctx *gctx;
struct gss_header *ghdr;
struct lustre_msg *msg = req->rq_repdata;
int msglen, pack_bulk, swabbed, rc;
__u32 major;
LASSERT(req->rq_cli_ctx == ctx);
LASSERT(req->rq_ctx_init == 0);
LASSERT(msg);
gctx = container_of(ctx, struct gss_cli_ctx, gc_base);
swabbed = ptlrpc_rep_need_swab(req);
ghdr = gss_swab_header(msg, 0, swabbed);
if (ghdr == NULL) {
CERROR("can't decode gss header\n");
return -EPROTO;
}
if (ghdr->gh_version != PTLRPC_GSS_VERSION) {
CERROR("gss version %u mismatch, expect %u\n",
ghdr->gh_version, PTLRPC_GSS_VERSION);
return -EPROTO;
}
switch (ghdr->gh_proc) {
case PTLRPC_GSS_PROC_DATA:
pack_bulk = ghdr->gh_flags & LUSTRE_GSS_PACK_BULK;
if (!req->rq_early && !equi(req->rq_pack_bulk == 1, pack_bulk)){
CERROR("%s bulk flag in reply\n",
req->rq_pack_bulk ? "missing" : "unexpected");
return -EPROTO;
}
if (swabbed)
gss_header_swabber(ghdr);
major = gss_unseal_msg(gctx->gc_mechctx, msg,
&msglen, req->rq_repdata_len);
if (major != GSS_S_COMPLETE) {
CERROR("failed to unwrap reply: %x\n", major);
rc = -EPERM;
break;
}
swabbed = __lustre_unpack_msg(msg, msglen);
if (swabbed < 0) {
CERROR("Failed to unpack after decryption\n");
return -EPROTO;
}
if (msg->lm_bufcount < 1) {
CERROR("Invalid reply buffer: empty\n");
return -EPROTO;
}
if (pack_bulk) {
if (msg->lm_bufcount < 2) {
CERROR("bufcount %u: missing bulk sec desc\n",
msg->lm_bufcount);
return -EPROTO;
}
if (bulk_sec_desc_unpack(msg, msg->lm_bufcount - 1,
swabbed))
return -EPROTO;
}
req->rq_repmsg = lustre_msg_buf(msg, 0, 0);
req->rq_replen = msg->lm_buflens[0];
rc = 0;
break;
case PTLRPC_GSS_PROC_ERR:
if (req->rq_early) {
CERROR("server return error with early reply\n");
rc = -EPROTO;
} else {
rc = gss_cli_ctx_handle_err_notify(ctx, req, ghdr);
}
break;
default:
CERROR("unexpected proc %d\n", ghdr->gh_proc);
rc = -EPERM;
}
return rc;
}
static inline
int gss_install_rvs_svc_ctx(struct obd_import *imp,
struct gss_sec *gsec,
struct gss_cli_ctx *gctx)
{
return gss_svc_upcall_install_rvs_ctx(imp, gsec, gctx);
}
int gss_sec_create_common(struct gss_sec *gsec,
struct ptlrpc_sec_policy *policy,
struct obd_import *imp,
struct ptlrpc_svc_ctx *svcctx,
struct sptlrpc_flavor *sf)
{
struct ptlrpc_sec *sec;
LASSERT(imp);
LASSERT(SPTLRPC_FLVR_POLICY(sf->sf_rpc) == SPTLRPC_POLICY_GSS);
gsec->gs_mech = lgss_subflavor_to_mech(
SPTLRPC_FLVR_BASE_SUB(sf->sf_rpc));
if (!gsec->gs_mech) {
CERROR("gss backend 0x%x not found\n",
SPTLRPC_FLVR_BASE_SUB(sf->sf_rpc));
return -EOPNOTSUPP;
}
spin_lock_init(&gsec->gs_lock);
gsec->gs_rvs_hdl = 0ULL;
sec = &gsec->gs_base;
sec->ps_policy = policy;
atomic_set(&sec->ps_refcount, 0);
atomic_set(&sec->ps_nctx, 0);
sec->ps_id = sptlrpc_get_next_secid();
sec->ps_flvr = *sf;
sec->ps_import = class_import_get(imp);
spin_lock_init(&sec->ps_lock);
INIT_LIST_HEAD(&sec->ps_gc_list);
if (!svcctx) {
sec->ps_gc_interval = GSS_GC_INTERVAL;
} else {
LASSERT(sec_is_reverse(sec));
sec->ps_gc_interval = 0;
}
if (SPTLRPC_FLVR_BULK_SVC(sec->ps_flvr.sf_rpc) == SPTLRPC_BULK_SVC_PRIV)
sptlrpc_enc_pool_add_user();
CDEBUG(D_SEC, "create %s%s@%p\n", (svcctx ? "reverse " : ""),
policy->sp_name, gsec);
return 0;
}
void gss_sec_destroy_common(struct gss_sec *gsec)
{
struct ptlrpc_sec *sec = &gsec->gs_base;
LASSERT(sec->ps_import);
LASSERT(atomic_read(&sec->ps_refcount) == 0);
LASSERT(atomic_read(&sec->ps_nctx) == 0);
if (gsec->gs_mech) {
lgss_mech_put(gsec->gs_mech);
gsec->gs_mech = NULL;
}
class_import_put(sec->ps_import);
if (SPTLRPC_FLVR_BULK_SVC(sec->ps_flvr.sf_rpc) == SPTLRPC_BULK_SVC_PRIV)
sptlrpc_enc_pool_del_user();
}
void gss_sec_kill(struct ptlrpc_sec *sec)
{
sec->ps_dying = 1;
}
int gss_cli_ctx_init_common(struct ptlrpc_sec *sec,
struct ptlrpc_cli_ctx *ctx,
struct ptlrpc_ctx_ops *ctxops,
struct vfs_cred *vcred)
{
struct gss_cli_ctx *gctx = ctx2gctx(ctx);
gctx->gc_win = 0;
atomic_set(&gctx->gc_seq, 0);
INIT_HLIST_NODE(&ctx->cc_cache);
atomic_set(&ctx->cc_refcount, 0);
ctx->cc_sec = sec;
ctx->cc_ops = ctxops;
ctx->cc_expire = 0;
ctx->cc_flags = PTLRPC_CTX_NEW;
ctx->cc_vcred = *vcred;
spin_lock_init(&ctx->cc_lock);
INIT_LIST_HEAD(&ctx->cc_req_list);
INIT_LIST_HEAD(&ctx->cc_gc_chain);
atomic_inc(&sec->ps_refcount);
atomic_inc(&sec->ps_nctx);
CDEBUG(D_SEC, "%s@%p: create ctx %p(%u->%s)\n",
sec->ps_policy->sp_name, ctx->cc_sec,
ctx, ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec));
return 0;
}
int gss_cli_ctx_fini_common(struct ptlrpc_sec *sec,
struct ptlrpc_cli_ctx *ctx)
{
struct gss_cli_ctx *gctx = ctx2gctx(ctx);
LASSERT(atomic_read(&sec->ps_nctx) > 0);
LASSERT(atomic_read(&ctx->cc_refcount) == 0);
LASSERT(ctx->cc_sec == sec);
if (sec_is_reverse(sec))
ctx->cc_flags &= ~PTLRPC_CTX_UPTODATE;
if (gctx->gc_mechctx) {
atomic_inc(&ctx->cc_refcount);
gss_do_ctx_fini_rpc(gctx);
gss_cli_ctx_finalize(gctx);
if (!atomic_dec_and_test(&ctx->cc_refcount))
return 1;
}
if (sec_is_reverse(sec))
CWARN("reverse sec %p: destroy ctx %p\n",
ctx->cc_sec, ctx);
else
CWARN("%s@%p: destroy ctx %p(%u->%s)\n",
sec->ps_policy->sp_name, ctx->cc_sec,
ctx, ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec));
return 0;
}
static
int gss_alloc_reqbuf_intg(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int svc, int msgsize)
{
int bufsize, txtsize;
int bufcnt = 2;
__u32 buflens[5];
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
txtsize = buflens[0];
buflens[1] = msgsize;
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[1];
if (req->rq_pack_udesc) {
buflens[bufcnt] = sptlrpc_current_user_desc_size();
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[bufcnt];
bufcnt++;
}
if (req->rq_pack_bulk) {
buflens[bufcnt] = gss_cli_bulk_payload(req->rq_cli_ctx,
&req->rq_flvr,
0, req->rq_bulk_read);
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[bufcnt];
bufcnt++;
}
if (req->rq_ctx_init)
buflens[bufcnt++] = GSS_CTX_INIT_MAX_LEN;
else if (svc != SPTLRPC_SVC_NULL)
buflens[bufcnt++] = gss_cli_payload(req->rq_cli_ctx, txtsize,0);
bufsize = lustre_msg_size_v2(bufcnt, buflens);
if (!req->rq_reqbuf) {
bufsize = size_roundup_power2(bufsize);
OBD_ALLOC_LARGE(req->rq_reqbuf, bufsize);
if (!req->rq_reqbuf)
return -ENOMEM;
req->rq_reqbuf_len = bufsize;
} else {
LASSERT(req->rq_pool);
LASSERT(req->rq_reqbuf_len >= bufsize);
memset(req->rq_reqbuf, 0, bufsize);
}
lustre_init_msg_v2(req->rq_reqbuf, bufcnt, buflens, NULL);
req->rq_reqbuf->lm_secflvr = req->rq_flvr.sf_rpc;
req->rq_reqmsg = lustre_msg_buf(req->rq_reqbuf, 1, msgsize);
LASSERT(req->rq_reqmsg);
if (req->rq_pack_udesc)
sptlrpc_pack_user_desc(req->rq_reqbuf, 2);
return 0;
}
static
int gss_alloc_reqbuf_priv(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
__u32 ibuflens[3], wbuflens[2];
int ibufcnt;
int clearsize, wiresize;
LASSERT(req->rq_clrbuf == NULL);
LASSERT(req->rq_clrbuf_len == 0);
ibufcnt = 1;
ibuflens[0] = msgsize;
if (req->rq_pack_udesc)
ibuflens[ibufcnt++] = sptlrpc_current_user_desc_size();
if (req->rq_pack_bulk)
ibuflens[ibufcnt++] = gss_cli_bulk_payload(req->rq_cli_ctx,
&req->rq_flvr, 0,
req->rq_bulk_read);
clearsize = lustre_msg_size_v2(ibufcnt, ibuflens);
clearsize += GSS_MAX_CIPHER_BLOCK;
wbuflens[0] = PTLRPC_GSS_HEADER_SIZE;
wbuflens[1] = gss_cli_payload(req->rq_cli_ctx, clearsize, 1);
wiresize = lustre_msg_size_v2(2, wbuflens);
if (req->rq_pool) {
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_reqbuf_len >= wiresize);
memset(req->rq_reqbuf, 0, req->rq_reqbuf_len);
if (clearsize + wiresize <= req->rq_reqbuf_len) {
req->rq_clrbuf =
(void *) (((char *) req->rq_reqbuf) + wiresize);
} else {
CWARN("pre-allocated buf size %d is not enough for "
"both clear (%d) and cipher (%d) text, proceed "
"with extra allocation\n", req->rq_reqbuf_len,
clearsize, wiresize);
}
}
if (!req->rq_clrbuf) {
clearsize = size_roundup_power2(clearsize);
OBD_ALLOC_LARGE(req->rq_clrbuf, clearsize);
if (!req->rq_clrbuf)
return -ENOMEM;
}
req->rq_clrbuf_len = clearsize;
lustre_init_msg_v2(req->rq_clrbuf, ibufcnt, ibuflens, NULL);
req->rq_reqmsg = lustre_msg_buf(req->rq_clrbuf, 0, msgsize);
if (req->rq_pack_udesc)
sptlrpc_pack_user_desc(req->rq_clrbuf, 1);
return 0;
}
int gss_alloc_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
int svc = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc);
LASSERT(!req->rq_pack_bulk ||
(req->rq_bulk_read || req->rq_bulk_write));
switch (svc) {
case SPTLRPC_SVC_NULL:
case SPTLRPC_SVC_AUTH:
case SPTLRPC_SVC_INTG:
return gss_alloc_reqbuf_intg(sec, req, svc, msgsize);
case SPTLRPC_SVC_PRIV:
return gss_alloc_reqbuf_priv(sec, req, msgsize);
default:
LASSERTF(0, "bad rpc flavor %x\n", req->rq_flvr.sf_rpc);
return 0;
}
}
void gss_free_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req)
{
int privacy;
LASSERT(!req->rq_pool || req->rq_reqbuf);
privacy = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc) == SPTLRPC_SVC_PRIV;
if (!req->rq_clrbuf)
goto release_reqbuf;
LASSERT(privacy);
LASSERT(req->rq_clrbuf_len);
if (req->rq_pool == NULL ||
req->rq_clrbuf < req->rq_reqbuf ||
(char *) req->rq_clrbuf >=
(char *) req->rq_reqbuf + req->rq_reqbuf_len)
OBD_FREE_LARGE(req->rq_clrbuf, req->rq_clrbuf_len);
req->rq_clrbuf = NULL;
req->rq_clrbuf_len = 0;
release_reqbuf:
if (!req->rq_pool && req->rq_reqbuf) {
LASSERT(req->rq_reqbuf_len);
OBD_FREE_LARGE(req->rq_reqbuf, req->rq_reqbuf_len);
req->rq_reqbuf = NULL;
req->rq_reqbuf_len = 0;
}
}
static int do_alloc_repbuf(struct ptlrpc_request *req, int bufsize)
{
bufsize = size_roundup_power2(bufsize);
OBD_ALLOC_LARGE(req->rq_repbuf, bufsize);
if (!req->rq_repbuf)
return -ENOMEM;
req->rq_repbuf_len = bufsize;
return 0;
}
static
int gss_alloc_repbuf_intg(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int svc, int msgsize)
{
int txtsize;
__u32 buflens[4];
int bufcnt = 2;
int alloc_size;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
txtsize = buflens[0];
buflens[1] = msgsize;
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[1];
if (req->rq_pack_bulk) {
buflens[bufcnt] = gss_cli_bulk_payload(req->rq_cli_ctx,
&req->rq_flvr,
1, req->rq_bulk_read);
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[bufcnt];
bufcnt++;
}
if (req->rq_ctx_init)
buflens[bufcnt++] = GSS_CTX_INIT_MAX_LEN;
else if (svc != SPTLRPC_SVC_NULL)
buflens[bufcnt++] = gss_cli_payload(req->rq_cli_ctx, txtsize,0);
alloc_size = lustre_msg_size_v2(bufcnt, buflens);
alloc_size += gss_at_reply_off_integ;
return do_alloc_repbuf(req, alloc_size);
}
static
int gss_alloc_repbuf_priv(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
int txtsize;
__u32 buflens[2];
int bufcnt;
int alloc_size;
bufcnt = 1;
buflens[0] = msgsize;
if (req->rq_pack_bulk)
buflens[bufcnt++] = gss_cli_bulk_payload(req->rq_cli_ctx,
&req->rq_flvr,
1, req->rq_bulk_read);
txtsize = lustre_msg_size_v2(bufcnt, buflens);
txtsize += GSS_MAX_CIPHER_BLOCK;
bufcnt = 2;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = gss_cli_payload(req->rq_cli_ctx, txtsize, 1);
alloc_size = lustre_msg_size_v2(bufcnt, buflens);
alloc_size += gss_at_reply_off_priv;
return do_alloc_repbuf(req, alloc_size);
}
int gss_alloc_repbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int msgsize)
{
int svc = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc);
LASSERT(!req->rq_pack_bulk ||
(req->rq_bulk_read || req->rq_bulk_write));
switch (svc) {
case SPTLRPC_SVC_NULL:
case SPTLRPC_SVC_AUTH:
case SPTLRPC_SVC_INTG:
return gss_alloc_repbuf_intg(sec, req, svc, msgsize);
case SPTLRPC_SVC_PRIV:
return gss_alloc_repbuf_priv(sec, req, msgsize);
default:
LASSERTF(0, "bad rpc flavor %x\n", req->rq_flvr.sf_rpc);
return 0;
}
}
void gss_free_repbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req)
{
OBD_FREE_LARGE(req->rq_repbuf, req->rq_repbuf_len);
req->rq_repbuf = NULL;
req->rq_repbuf_len = 0;
req->rq_repdata = NULL;
req->rq_repdata_len = 0;
}
static int get_enlarged_msgsize(struct lustre_msg *msg,
int segment, int newsize)
{
int save, newmsg_size;
LASSERT(newsize >= msg->lm_buflens[segment]);
save = msg->lm_buflens[segment];
msg->lm_buflens[segment] = newsize;
newmsg_size = lustre_msg_size_v2(msg->lm_bufcount, msg->lm_buflens);
msg->lm_buflens[segment] = save;
return newmsg_size;
}
static int get_enlarged_msgsize2(struct lustre_msg *msg,
int segment1, int newsize1,
int segment2, int newsize2)
{
int save1, save2, newmsg_size;
LASSERT(newsize1 >= msg->lm_buflens[segment1]);
LASSERT(newsize2 >= msg->lm_buflens[segment2]);
save1 = msg->lm_buflens[segment1];
save2 = msg->lm_buflens[segment2];
msg->lm_buflens[segment1] = newsize1;
msg->lm_buflens[segment2] = newsize2;
newmsg_size = lustre_msg_size_v2(msg->lm_bufcount, msg->lm_buflens);
msg->lm_buflens[segment1] = save1;
msg->lm_buflens[segment2] = save2;
return newmsg_size;
}
static
int gss_enlarge_reqbuf_intg(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int svc,
int segment, int newsize)
{
struct lustre_msg *newbuf;
int txtsize, sigsize = 0, i;
int newmsg_size, newbuf_size;
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_reqbuf_len > req->rq_reqlen);
LASSERT(req->rq_reqbuf->lm_bufcount >= 2);
LASSERT(lustre_msg_buf(req->rq_reqbuf, 1, 0) == req->rq_reqmsg);
newmsg_size = get_enlarged_msgsize(req->rq_reqmsg, segment, newsize);
LASSERT(newmsg_size >= req->rq_reqbuf->lm_buflens[1]);
if (svc == SPTLRPC_SVC_NULL) {
newbuf_size = get_enlarged_msgsize(req->rq_reqbuf,
1, newmsg_size);
} else {
txtsize = req->rq_reqbuf->lm_buflens[0];
if (svc == SPTLRPC_SVC_INTG) {
for (i = 1; i < req->rq_reqbuf->lm_bufcount; i++)
txtsize += req->rq_reqbuf->lm_buflens[i];
txtsize += newmsg_size - req->rq_reqbuf->lm_buflens[1];
}
sigsize = gss_cli_payload(req->rq_cli_ctx, txtsize, 0);
LASSERT(sigsize >= msg_last_seglen(req->rq_reqbuf));
newbuf_size = get_enlarged_msgsize2(
req->rq_reqbuf,
1, newmsg_size,
msg_last_segidx(req->rq_reqbuf),
sigsize);
}
LASSERT(!req->rq_pool || req->rq_reqbuf_len >= newbuf_size);
if (req->rq_reqbuf_len < newbuf_size) {
newbuf_size = size_roundup_power2(newbuf_size);
OBD_ALLOC_LARGE(newbuf, newbuf_size);
if (newbuf == NULL)
return -ENOMEM;
memcpy(newbuf, req->rq_reqbuf, req->rq_reqbuf_len);
OBD_FREE_LARGE(req->rq_reqbuf, req->rq_reqbuf_len);
req->rq_reqbuf = newbuf;
req->rq_reqbuf_len = newbuf_size;
req->rq_reqmsg = lustre_msg_buf(req->rq_reqbuf, 1, 0);
}
if (svc != SPTLRPC_SVC_NULL)
_sptlrpc_enlarge_msg_inplace(req->rq_reqbuf,
msg_last_segidx(req->rq_reqbuf),
sigsize);
_sptlrpc_enlarge_msg_inplace(req->rq_reqbuf, 1, newmsg_size);
_sptlrpc_enlarge_msg_inplace(req->rq_reqmsg, segment, newsize);
req->rq_reqlen = newmsg_size;
return 0;
}
static
int gss_enlarge_reqbuf_priv(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int segment, int newsize)
{
struct lustre_msg *newclrbuf;
int newmsg_size, newclrbuf_size, newcipbuf_size;
__u32 buflens[3];
LASSERT(req->rq_pool ||
(req->rq_reqbuf == NULL && req->rq_reqbuf_len == 0));
LASSERT(req->rq_reqbuf == NULL ||
(req->rq_pool && req->rq_reqbuf->lm_bufcount == 3));
LASSERT(req->rq_clrbuf);
LASSERT(req->rq_clrbuf_len > req->rq_reqlen);
LASSERT(lustre_msg_buf(req->rq_clrbuf, 0, 0) == req->rq_reqmsg);
newmsg_size = get_enlarged_msgsize(req->rq_reqmsg, segment, newsize);
newclrbuf_size = get_enlarged_msgsize(req->rq_clrbuf, 0, newmsg_size);
newclrbuf_size += GSS_MAX_CIPHER_BLOCK;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = gss_cli_payload(req->rq_cli_ctx, buflens[0], 0);
buflens[2] = gss_cli_payload(req->rq_cli_ctx, newclrbuf_size, 1);
newcipbuf_size = lustre_msg_size_v2(3, buflens);
if (unlikely(req->rq_pool) &&
req->rq_clrbuf >= req->rq_reqbuf &&
(char *) req->rq_clrbuf <
(char *) req->rq_reqbuf + req->rq_reqbuf_len) {
if (newclrbuf_size + newcipbuf_size <= req->rq_reqbuf_len) {
void *src, *dst;
src = req->rq_clrbuf;
dst = (char *) req->rq_reqbuf + newcipbuf_size;
memmove(dst, src, req->rq_clrbuf_len);
req->rq_clrbuf = (struct lustre_msg *) dst;
req->rq_clrbuf_len = newclrbuf_size;
req->rq_reqmsg = lustre_msg_buf(req->rq_clrbuf, 0, 0);
} else {
LASSERT(req->rq_reqbuf_len >= newcipbuf_size);
LASSERT(req->rq_clrbuf_len < newclrbuf_size);
}
}
if (req->rq_clrbuf_len < newclrbuf_size) {
newclrbuf_size = size_roundup_power2(newclrbuf_size);
OBD_ALLOC_LARGE(newclrbuf, newclrbuf_size);
if (newclrbuf == NULL)
return -ENOMEM;
memcpy(newclrbuf, req->rq_clrbuf, req->rq_clrbuf_len);
if (req->rq_reqbuf == NULL ||
req->rq_clrbuf < req->rq_reqbuf ||
(char *) req->rq_clrbuf >=
(char *) req->rq_reqbuf + req->rq_reqbuf_len) {
OBD_FREE_LARGE(req->rq_clrbuf, req->rq_clrbuf_len);
}
req->rq_clrbuf = newclrbuf;
req->rq_clrbuf_len = newclrbuf_size;
req->rq_reqmsg = lustre_msg_buf(req->rq_clrbuf, 0, 0);
}
_sptlrpc_enlarge_msg_inplace(req->rq_clrbuf, 0, newmsg_size);
_sptlrpc_enlarge_msg_inplace(req->rq_reqmsg, segment, newsize);
req->rq_reqlen = newmsg_size;
return 0;
}
int gss_enlarge_reqbuf(struct ptlrpc_sec *sec,
struct ptlrpc_request *req,
int segment, int newsize)
{
int svc = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc);
LASSERT(!req->rq_ctx_init && !req->rq_ctx_fini);
switch (svc) {
case SPTLRPC_SVC_NULL:
case SPTLRPC_SVC_AUTH:
case SPTLRPC_SVC_INTG:
return gss_enlarge_reqbuf_intg(sec, req, svc, segment, newsize);
case SPTLRPC_SVC_PRIV:
return gss_enlarge_reqbuf_priv(sec, req, segment, newsize);
default:
LASSERTF(0, "bad rpc flavor %x\n", req->rq_flvr.sf_rpc);
return 0;
}
}
int gss_sec_install_rctx(struct obd_import *imp,
struct ptlrpc_sec *sec,
struct ptlrpc_cli_ctx *ctx)
{
struct gss_sec *gsec;
struct gss_cli_ctx *gctx;
int rc;
gsec = container_of(sec, struct gss_sec, gs_base);
gctx = container_of(ctx, struct gss_cli_ctx, gc_base);
rc = gss_install_rvs_svc_ctx(imp, gsec, gctx);
return rc;
}
static inline
int gss_svc_reqctx_is_special(struct gss_svc_reqctx *grctx)
{
LASSERT(grctx);
return (grctx->src_init || grctx->src_init_continue ||
grctx->src_err_notify);
}
static
void gss_svc_reqctx_free(struct gss_svc_reqctx *grctx)
{
if (grctx->src_ctx)
gss_svc_upcall_put_ctx(grctx->src_ctx);
sptlrpc_policy_put(grctx->src_base.sc_policy);
OBD_FREE_PTR(grctx);
}
static inline
void gss_svc_reqctx_addref(struct gss_svc_reqctx *grctx)
{
LASSERT(atomic_read(&grctx->src_base.sc_refcount) > 0);
atomic_inc(&grctx->src_base.sc_refcount);
}
static inline
void gss_svc_reqctx_decref(struct gss_svc_reqctx *grctx)
{
LASSERT(atomic_read(&grctx->src_base.sc_refcount) > 0);
if (atomic_dec_and_test(&grctx->src_base.sc_refcount))
gss_svc_reqctx_free(grctx);
}
static
int gss_svc_sign(struct ptlrpc_request *req,
struct ptlrpc_reply_state *rs,
struct gss_svc_reqctx *grctx,
__u32 svc)
{
__u32 flags = 0;
int rc;
LASSERT(rs->rs_msg == lustre_msg_buf(rs->rs_repbuf, 1, 0));
if (req->rq_replen != rs->rs_repbuf->lm_buflens[1])
lustre_shrink_msg(rs->rs_repbuf, 1, req->rq_replen, 1);
if (req->rq_pack_bulk)
flags |= LUSTRE_GSS_PACK_BULK;
rc = gss_sign_msg(rs->rs_repbuf, grctx->src_ctx->gsc_mechctx,
LUSTRE_SP_ANY, flags, PTLRPC_GSS_PROC_DATA,
grctx->src_wirectx.gw_seq, svc, NULL);
if (rc < 0)
return rc;
rs->rs_repdata_len = rc;
if (likely(req->rq_packed_final)) {
if (lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT)
req->rq_reply_off = gss_at_reply_off_integ;
else
req->rq_reply_off = 0;
} else {
if (svc == SPTLRPC_SVC_NULL)
rs->rs_repbuf->lm_cksum = crc32_le(!(__u32) 0,
lustre_msg_buf(rs->rs_repbuf, 1, 0),
lustre_msg_buflen(rs->rs_repbuf, 1));
req->rq_reply_off = 0;
}
return 0;
}
int gss_pack_err_notify(struct ptlrpc_request *req, __u32 major, __u32 minor)
{
struct gss_svc_reqctx *grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
struct ptlrpc_reply_state *rs;
struct gss_err_header *ghdr;
int replen = sizeof(struct ptlrpc_body);
int rc;
grctx->src_err_notify = 1;
grctx->src_reserve_len = 0;
rc = lustre_pack_reply_v2(req, 1, &replen, NULL, 0);
if (rc) {
CERROR("could not pack reply, err %d\n", rc);
return rc;
}
rs = req->rq_reply_state;
LASSERT(rs->rs_repbuf->lm_buflens[1] >= sizeof(*ghdr));
ghdr = lustre_msg_buf(rs->rs_repbuf, 0, 0);
ghdr->gh_version = PTLRPC_GSS_VERSION;
ghdr->gh_flags = 0;
ghdr->gh_proc = PTLRPC_GSS_PROC_ERR;
ghdr->gh_major = major;
ghdr->gh_minor = minor;
ghdr->gh_handle.len = 0;
rs->rs_repdata_len = lustre_msg_size_v2(rs->rs_repbuf->lm_bufcount,
rs->rs_repbuf->lm_buflens);
CDEBUG(D_SEC, "prepare gss error notify(0x%x/0x%x) to %s\n",
major, minor, libcfs_nid2str(req->rq_peer.nid));
return 0;
}
static
int gss_svc_handle_init(struct ptlrpc_request *req,
struct gss_wire_ctx *gw)
{
struct gss_svc_reqctx *grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
struct lustre_msg *reqbuf = req->rq_reqbuf;
struct obd_uuid *uuid;
struct obd_device *target;
rawobj_t uuid_obj, rvs_hdl, in_token;
__u32 lustre_svc;
__u32 *secdata, seclen;
int swabbed, rc;
CDEBUG(D_SEC, "processing gss init(%d) request from %s\n", gw->gw_proc,
libcfs_nid2str(req->rq_peer.nid));
req->rq_ctx_init = 1;
if (gw->gw_flags & LUSTRE_GSS_PACK_BULK) {
CERROR("unexpected bulk flag\n");
return SECSVC_DROP;
}
if (gw->gw_proc == PTLRPC_GSS_PROC_INIT && gw->gw_handle.len != 0) {
CERROR("proc %u: invalid handle length %u\n",
gw->gw_proc, gw->gw_handle.len);
return SECSVC_DROP;
}
if (reqbuf->lm_bufcount < 3 || reqbuf->lm_bufcount > 4){
CERROR("Invalid bufcount %d\n", reqbuf->lm_bufcount);
return SECSVC_DROP;
}
swabbed = ptlrpc_req_need_swab(req);
secdata = lustre_msg_buf(reqbuf, reqbuf->lm_bufcount - 1, 0);
seclen = reqbuf->lm_buflens[reqbuf->lm_bufcount - 1];
if (seclen < 4 + 4) {
CERROR("sec size %d too small\n", seclen);
return SECSVC_DROP;
}
lustre_svc = le32_to_cpu(*secdata++);
seclen -= 4;
if (rawobj_extract(&uuid_obj, &secdata, &seclen)) {
CERROR("failed to extract target uuid\n");
return SECSVC_DROP;
}
uuid_obj.data[uuid_obj.len - 1] = '\0';
uuid = (struct obd_uuid *) uuid_obj.data;
target = class_uuid2obd(uuid);
if (!target || target->obd_stopping || !target->obd_set_up) {
CERROR("target '%s' is not available for context init (%s)\n",
uuid->uuid, target == NULL ? "no target" :
(target->obd_stopping ? "stopping" : "not set up"));
return SECSVC_DROP;
}
if (rawobj_extract(&rvs_hdl, &secdata, &seclen)) {
CERROR("failed extract reverse handle\n");
return SECSVC_DROP;
}
if (rawobj_extract(&in_token, &secdata, &seclen)) {
CERROR("can't extract token\n");
return SECSVC_DROP;
}
rc = gss_svc_upcall_handle_init(req, grctx, gw, target, lustre_svc,
&rvs_hdl, &in_token);
if (rc != SECSVC_OK)
return rc;
if (grctx->src_ctx->gsc_usr_mds || grctx->src_ctx->gsc_usr_oss ||
grctx->src_ctx->gsc_usr_root)
CWARN("create svc ctx %p: user from %s authenticated as %s\n",
grctx->src_ctx, libcfs_nid2str(req->rq_peer.nid),
grctx->src_ctx->gsc_usr_mds ? "mds" :
(grctx->src_ctx->gsc_usr_oss ? "oss" : "root"));
else
CWARN("create svc ctx %p: accept user %u from %s\n",
grctx->src_ctx, grctx->src_ctx->gsc_uid,
libcfs_nid2str(req->rq_peer.nid));
if (gw->gw_flags & LUSTRE_GSS_PACK_USER) {
if (reqbuf->lm_bufcount < 4) {
CERROR("missing user descriptor\n");
return SECSVC_DROP;
}
if (sptlrpc_unpack_user_desc(reqbuf, 2, swabbed)) {
CERROR("Mal-formed user descriptor\n");
return SECSVC_DROP;
}
req->rq_pack_udesc = 1;
req->rq_user_desc = lustre_msg_buf(reqbuf, 2, 0);
}
req->rq_reqmsg = lustre_msg_buf(reqbuf, 1, 0);
req->rq_reqlen = lustre_msg_buflen(reqbuf, 1);
return rc;
}
static
int gss_svc_verify_request(struct ptlrpc_request *req,
struct gss_svc_reqctx *grctx,
struct gss_wire_ctx *gw,
__u32 *major)
{
struct gss_svc_ctx *gctx = grctx->src_ctx;
struct lustre_msg *msg = req->rq_reqbuf;
int offset = 2;
int swabbed;
*major = GSS_S_COMPLETE;
if (msg->lm_bufcount < 2) {
CERROR("Too few segments (%u) in request\n", msg->lm_bufcount);
return -EINVAL;
}
if (gw->gw_svc == SPTLRPC_SVC_NULL)
goto verified;
if (gss_check_seq_num(&gctx->gsc_seqdata, gw->gw_seq, 0)) {
CERROR("phase 0: discard replayed req: seq %u\n", gw->gw_seq);
*major = GSS_S_DUPLICATE_TOKEN;
return -EACCES;
}
*major = gss_verify_msg(msg, gctx->gsc_mechctx, gw->gw_svc);
if (*major != GSS_S_COMPLETE) {
CERROR("failed to verify request: %x\n", *major);
return -EACCES;
}
if (gctx->gsc_reverse == 0 &&
gss_check_seq_num(&gctx->gsc_seqdata, gw->gw_seq, 1)) {
CERROR("phase 1+: discard replayed req: seq %u\n", gw->gw_seq);
*major = GSS_S_DUPLICATE_TOKEN;
return -EACCES;
}
verified:
swabbed = ptlrpc_req_need_swab(req);
if (gw->gw_flags & LUSTRE_GSS_PACK_USER) {
if (msg->lm_bufcount < (offset + 1)) {
CERROR("no user desc included\n");
return -EINVAL;
}
if (sptlrpc_unpack_user_desc(msg, offset, swabbed)) {
CERROR("Mal-formed user descriptor\n");
return -EINVAL;
}
req->rq_pack_udesc = 1;
req->rq_user_desc = lustre_msg_buf(msg, offset, 0);
offset++;
}
if (gw->gw_flags & LUSTRE_GSS_PACK_BULK) {
if (msg->lm_bufcount < (offset + 1)) {
CERROR("missing bulk sec descriptor\n");
return -EINVAL;
}
if (bulk_sec_desc_unpack(msg, offset, swabbed))
return -EINVAL;
req->rq_pack_bulk = 1;
grctx->src_reqbsd = lustre_msg_buf(msg, offset, 0);
grctx->src_reqbsd_size = lustre_msg_buflen(msg, offset);
}
req->rq_reqmsg = lustre_msg_buf(msg, 1, 0);
req->rq_reqlen = msg->lm_buflens[1];
return 0;
}
static
int gss_svc_unseal_request(struct ptlrpc_request *req,
struct gss_svc_reqctx *grctx,
struct gss_wire_ctx *gw,
__u32 *major)
{
struct gss_svc_ctx *gctx = grctx->src_ctx;
struct lustre_msg *msg = req->rq_reqbuf;
int swabbed, msglen, offset = 1;
if (gss_check_seq_num(&gctx->gsc_seqdata, gw->gw_seq, 0)) {
CERROR("phase 0: discard replayed req: seq %u\n", gw->gw_seq);
*major = GSS_S_DUPLICATE_TOKEN;
return -EACCES;
}
*major = gss_unseal_msg(gctx->gsc_mechctx, msg,
&msglen, req->rq_reqdata_len);
if (*major != GSS_S_COMPLETE) {
CERROR("failed to unwrap request: %x\n", *major);
return -EACCES;
}
if (gss_check_seq_num(&gctx->gsc_seqdata, gw->gw_seq, 1)) {
CERROR("phase 1+: discard replayed req: seq %u\n", gw->gw_seq);
*major = GSS_S_DUPLICATE_TOKEN;
return -EACCES;
}
swabbed = __lustre_unpack_msg(msg, msglen);
if (swabbed < 0) {
CERROR("Failed to unpack after decryption\n");
return -EINVAL;
}
req->rq_reqdata_len = msglen;
if (msg->lm_bufcount < 1) {
CERROR("Invalid buffer: is empty\n");
return -EINVAL;
}
if (gw->gw_flags & LUSTRE_GSS_PACK_USER) {
if (msg->lm_bufcount < offset + 1) {
CERROR("no user descriptor included\n");
return -EINVAL;
}
if (sptlrpc_unpack_user_desc(msg, offset, swabbed)) {
CERROR("Mal-formed user descriptor\n");
return -EINVAL;
}
req->rq_pack_udesc = 1;
req->rq_user_desc = lustre_msg_buf(msg, offset, 0);
offset++;
}
if (gw->gw_flags & LUSTRE_GSS_PACK_BULK) {
if (msg->lm_bufcount < offset + 1) {
CERROR("no bulk checksum included\n");
return -EINVAL;
}
if (bulk_sec_desc_unpack(msg, offset, swabbed))
return -EINVAL;
req->rq_pack_bulk = 1;
grctx->src_reqbsd = lustre_msg_buf(msg, offset, 0);
grctx->src_reqbsd_size = lustre_msg_buflen(msg, offset);
}
req->rq_reqmsg = lustre_msg_buf(req->rq_reqbuf, 0, 0);
req->rq_reqlen = req->rq_reqbuf->lm_buflens[0];
return 0;
}
static
int gss_svc_handle_data(struct ptlrpc_request *req,
struct gss_wire_ctx *gw)
{
struct gss_svc_reqctx *grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
__u32 major = 0;
int rc = 0;
grctx->src_ctx = gss_svc_upcall_get_ctx(req, gw);
if (!grctx->src_ctx) {
major = GSS_S_NO_CONTEXT;
goto error;
}
switch (gw->gw_svc) {
case SPTLRPC_SVC_NULL:
case SPTLRPC_SVC_AUTH:
case SPTLRPC_SVC_INTG:
rc = gss_svc_verify_request(req, grctx, gw, &major);
break;
case SPTLRPC_SVC_PRIV:
rc = gss_svc_unseal_request(req, grctx, gw, &major);
break;
default:
CERROR("unsupported gss service %d\n", gw->gw_svc);
rc = -EINVAL;
}
if (rc == 0)
return SECSVC_OK;
CERROR("svc %u failed: major 0x%08x: req xid "LPU64" ctx %p idx "
LPX64"(%u->%s)\n", gw->gw_svc, major, req->rq_xid,
grctx->src_ctx, gss_handle_to_u64(&gw->gw_handle),
grctx->src_ctx->gsc_uid, libcfs_nid2str(req->rq_peer.nid));
error:
if ((major == GSS_S_NO_CONTEXT || major == GSS_S_BAD_SIG) &&
gss_pack_err_notify(req, major, 0) == 0)
return SECSVC_COMPLETE;
return SECSVC_DROP;
}
static
int gss_svc_handle_destroy(struct ptlrpc_request *req,
struct gss_wire_ctx *gw)
{
struct gss_svc_reqctx *grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
__u32 major;
req->rq_ctx_fini = 1;
req->rq_no_reply = 1;
grctx->src_ctx = gss_svc_upcall_get_ctx(req, gw);
if (!grctx->src_ctx) {
CDEBUG(D_SEC, "invalid gss context handle for destroy.\n");
return SECSVC_DROP;
}
if (gw->gw_svc != SPTLRPC_SVC_INTG) {
CERROR("svc %u is not supported in destroy.\n", gw->gw_svc);
return SECSVC_DROP;
}
if (gss_svc_verify_request(req, grctx, gw, &major))
return SECSVC_DROP;
CWARN("destroy svc ctx %p idx "LPX64" (%u->%s)\n",
grctx->src_ctx, gss_handle_to_u64(&gw->gw_handle),
grctx->src_ctx->gsc_uid, libcfs_nid2str(req->rq_peer.nid));
gss_svc_upcall_destroy_ctx(grctx->src_ctx);
if (gw->gw_flags & LUSTRE_GSS_PACK_USER) {
if (req->rq_reqbuf->lm_bufcount < 4) {
CERROR("missing user descriptor, ignore it\n");
return SECSVC_OK;
}
if (sptlrpc_unpack_user_desc(req->rq_reqbuf, 2,
ptlrpc_req_need_swab(req))) {
CERROR("Mal-formed user descriptor, ignore it\n");
return SECSVC_OK;
}
req->rq_pack_udesc = 1;
req->rq_user_desc = lustre_msg_buf(req->rq_reqbuf, 2, 0);
}
return SECSVC_OK;
}
int gss_svc_accept(struct ptlrpc_sec_policy *policy, struct ptlrpc_request *req)
{
struct gss_header *ghdr;
struct gss_svc_reqctx *grctx;
struct gss_wire_ctx *gw;
int swabbed, rc;
LASSERT(req->rq_reqbuf);
LASSERT(req->rq_svc_ctx == NULL);
if (req->rq_reqbuf->lm_bufcount < 2) {
CERROR("buf count only %d\n", req->rq_reqbuf->lm_bufcount);
return SECSVC_DROP;
}
swabbed = ptlrpc_req_need_swab(req);
ghdr = gss_swab_header(req->rq_reqbuf, 0, swabbed);
if (ghdr == NULL) {
CERROR("can't decode gss header\n");
return SECSVC_DROP;
}
if (ghdr->gh_version != PTLRPC_GSS_VERSION) {
CERROR("gss version %u, expect %u\n", ghdr->gh_version,
PTLRPC_GSS_VERSION);
return SECSVC_DROP;
}
req->rq_sp_from = ghdr->gh_sp;
OBD_ALLOC_PTR(grctx);
if (!grctx)
return SECSVC_DROP;
grctx->src_base.sc_policy = sptlrpc_policy_get(policy);
atomic_set(&grctx->src_base.sc_refcount, 1);
req->rq_svc_ctx = &grctx->src_base;
gw = &grctx->src_wirectx;
gw->gw_flags = ghdr->gh_flags;
gw->gw_proc = ghdr->gh_proc;
gw->gw_seq = ghdr->gh_seq;
gw->gw_svc = ghdr->gh_svc;
rawobj_from_netobj(&gw->gw_handle, &ghdr->gh_handle);
if (swabbed)
gss_header_swabber(ghdr);
switch(ghdr->gh_proc) {
case PTLRPC_GSS_PROC_INIT:
case PTLRPC_GSS_PROC_CONTINUE_INIT:
rc = gss_svc_handle_init(req, gw);
break;
case PTLRPC_GSS_PROC_DATA:
rc = gss_svc_handle_data(req, gw);
break;
case PTLRPC_GSS_PROC_DESTROY:
rc = gss_svc_handle_destroy(req, gw);
break;
default:
CERROR("unknown proc %u\n", gw->gw_proc);
rc = SECSVC_DROP;
break;
}
switch (rc) {
case SECSVC_OK:
LASSERT (grctx->src_ctx);
req->rq_auth_gss = 1;
req->rq_auth_remote = grctx->src_ctx->gsc_remote;
req->rq_auth_usr_mdt = grctx->src_ctx->gsc_usr_mds;
req->rq_auth_usr_ost = grctx->src_ctx->gsc_usr_oss;
req->rq_auth_usr_root = grctx->src_ctx->gsc_usr_root;
req->rq_auth_uid = grctx->src_ctx->gsc_uid;
req->rq_auth_mapped_uid = grctx->src_ctx->gsc_mapped_uid;
break;
case SECSVC_COMPLETE:
break;
case SECSVC_DROP:
gss_svc_reqctx_free(grctx);
req->rq_svc_ctx = NULL;
break;
}
return rc;
}
void gss_svc_invalidate_ctx(struct ptlrpc_svc_ctx *svc_ctx)
{
struct gss_svc_reqctx *grctx;
if (svc_ctx == NULL) {
return;
}
grctx = gss_svc_ctx2reqctx(svc_ctx);
CWARN("gss svc invalidate ctx %p(%u)\n",
grctx->src_ctx, grctx->src_ctx->gsc_uid);
gss_svc_upcall_destroy_ctx(grctx->src_ctx);
}
static inline
int gss_svc_payload(struct gss_svc_reqctx *grctx, int early,
int msgsize, int privacy)
{
if (early == 0 && gss_svc_reqctx_is_special(grctx))
return grctx->src_reserve_len;
return gss_mech_payload(NULL, msgsize, privacy);
}
static int gss_svc_bulk_payload(struct gss_svc_ctx *gctx,
struct sptlrpc_flavor *flvr,
int read)
{
int payload = sizeof(struct ptlrpc_bulk_sec_desc);
if (read) {
switch (SPTLRPC_FLVR_BULK_SVC(flvr->sf_rpc)) {
case SPTLRPC_BULK_SVC_NULL:
break;
case SPTLRPC_BULK_SVC_INTG:
payload += gss_mech_payload(NULL, 0, 0);
break;
case SPTLRPC_BULK_SVC_PRIV:
payload += gss_mech_payload(NULL, 0, 1);
break;
case SPTLRPC_BULK_SVC_AUTH:
default:
LBUG();
}
}
return payload;
}
int gss_svc_alloc_rs(struct ptlrpc_request *req, int msglen)
{
struct gss_svc_reqctx *grctx;
struct ptlrpc_reply_state *rs;
int early, privacy, svc, bsd_off = 0;
__u32 ibuflens[2], buflens[4];
int ibufcnt = 0, bufcnt;
int txtsize, wmsg_size, rs_size;
LASSERT(msglen % 8 == 0);
if (req->rq_pack_bulk && !req->rq_bulk_read && !req->rq_bulk_write) {
CERROR("client request bulk sec on non-bulk rpc\n");
return -EPROTO;
}
svc = SPTLRPC_FLVR_SVC(req->rq_flvr.sf_rpc);
early = (req->rq_packed_final == 0);
grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
if (!early && gss_svc_reqctx_is_special(grctx))
privacy = 0;
else
privacy = (svc == SPTLRPC_SVC_PRIV);
if (privacy) {
ibufcnt = 1;
ibuflens[0] = msglen;
if (req->rq_pack_bulk) {
LASSERT(grctx->src_reqbsd);
bsd_off = ibufcnt;
ibuflens[ibufcnt++] = gss_svc_bulk_payload(
grctx->src_ctx,
&req->rq_flvr,
req->rq_bulk_read);
}
txtsize = lustre_msg_size_v2(ibufcnt, ibuflens);
txtsize += GSS_MAX_CIPHER_BLOCK;
bufcnt = 2;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = gss_svc_payload(grctx, early, txtsize, 1);
} else {
bufcnt = 2;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = msglen;
txtsize = buflens[0];
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[1];
if (req->rq_pack_bulk) {
LASSERT(grctx->src_reqbsd);
bsd_off = bufcnt;
buflens[bufcnt] = gss_svc_bulk_payload(
grctx->src_ctx,
&req->rq_flvr,
req->rq_bulk_read);
if (svc == SPTLRPC_SVC_INTG)
txtsize += buflens[bufcnt];
bufcnt++;
}
if ((!early && gss_svc_reqctx_is_special(grctx)) ||
svc != SPTLRPC_SVC_NULL)
buflens[bufcnt++] = gss_svc_payload(grctx, early,
txtsize, 0);
}
wmsg_size = lustre_msg_size_v2(bufcnt, buflens);
rs_size = sizeof(*rs) + wmsg_size;
rs = req->rq_reply_state;
if (rs) {
LASSERT(rs->rs_size >= rs_size);
} else {
OBD_ALLOC_LARGE(rs, rs_size);
if (rs == NULL)
return -ENOMEM;
rs->rs_size = rs_size;
}
rs->rs_repbuf = (struct lustre_msg *) (rs + 1);
rs->rs_repbuf_len = wmsg_size;
if (privacy) {
lustre_init_msg_v2(rs->rs_repbuf, ibufcnt, ibuflens, NULL);
rs->rs_msg = lustre_msg_buf(rs->rs_repbuf, 0, msglen);
} else {
lustre_init_msg_v2(rs->rs_repbuf, bufcnt, buflens, NULL);
rs->rs_repbuf->lm_secflvr = req->rq_flvr.sf_rpc;
rs->rs_msg = lustre_msg_buf(rs->rs_repbuf, 1, 0);
}
if (bsd_off) {
grctx->src_repbsd = lustre_msg_buf(rs->rs_repbuf, bsd_off, 0);
grctx->src_repbsd_size = lustre_msg_buflen(rs->rs_repbuf,
bsd_off);
}
gss_svc_reqctx_addref(grctx);
rs->rs_svc_ctx = req->rq_svc_ctx;
LASSERT(rs->rs_msg);
req->rq_reply_state = rs;
return 0;
}
static int gss_svc_seal(struct ptlrpc_request *req,
struct ptlrpc_reply_state *rs,
struct gss_svc_reqctx *grctx)
{
struct gss_svc_ctx *gctx = grctx->src_ctx;
rawobj_t hdrobj, msgobj, token;
struct gss_header *ghdr;
__u8 *token_buf;
int token_buflen;
__u32 buflens[2], major;
int msglen, rc;
if (req->rq_replen != lustre_msg_buflen(rs->rs_repbuf, 0))
msglen = lustre_shrink_msg(rs->rs_repbuf, 0, req->rq_replen, 1);
else
msglen = lustre_msg_size_v2(rs->rs_repbuf->lm_bufcount,
rs->rs_repbuf->lm_buflens);
LASSERT(msglen + PTLRPC_GSS_HEADER_SIZE <= rs->rs_repbuf_len);
ghdr = (struct gss_header *) ((char *) rs->rs_repbuf +
rs->rs_repbuf_len - PTLRPC_GSS_HEADER_SIZE);
ghdr->gh_version = PTLRPC_GSS_VERSION;
ghdr->gh_sp = LUSTRE_SP_ANY;
ghdr->gh_flags = 0;
ghdr->gh_proc = PTLRPC_GSS_PROC_DATA;
ghdr->gh_seq = grctx->src_wirectx.gw_seq;
ghdr->gh_svc = SPTLRPC_SVC_PRIV;
ghdr->gh_handle.len = 0;
if (req->rq_pack_bulk)
ghdr->gh_flags |= LUSTRE_GSS_PACK_BULK;
token_buflen = gss_mech_payload(gctx->gsc_mechctx, msglen, 1);
OBD_ALLOC_LARGE(token_buf, token_buflen);
if (token_buf == NULL)
return -ENOMEM;
hdrobj.len = PTLRPC_GSS_HEADER_SIZE;
hdrobj.data = (__u8 *) ghdr;
msgobj.len = msglen;
msgobj.data = (__u8 *) rs->rs_repbuf;
token.len = token_buflen;
token.data = token_buf;
major = lgss_wrap(gctx->gsc_mechctx, &hdrobj, &msgobj,
rs->rs_repbuf_len - PTLRPC_GSS_HEADER_SIZE, &token);
if (major != GSS_S_COMPLETE) {
CERROR("wrap message error: %08x\n", major);
GOTO(out_free, rc = -EPERM);
}
LASSERT(token.len <= token_buflen);
if (req->rq_pack_bulk) {
grctx->src_repbsd = NULL;
grctx->src_repbsd_size = 0;
}
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = token.len;
rs->rs_repdata_len = lustre_msg_size_v2(2, buflens);
LASSERT(rs->rs_repdata_len <= rs->rs_repbuf_len);
lustre_init_msg_v2(rs->rs_repbuf, 2, buflens, NULL);
rs->rs_repbuf->lm_secflvr = req->rq_flvr.sf_rpc;
memcpy(lustre_msg_buf(rs->rs_repbuf, 0, 0), ghdr,
PTLRPC_GSS_HEADER_SIZE);
memcpy(lustre_msg_buf(rs->rs_repbuf, 1, 0), token.data, token.len);
if (req->rq_packed_final &&
(lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT))
req->rq_reply_off = gss_at_reply_off_priv;
else
req->rq_reply_off = 0;
rs->rs_msg = NULL;
req->rq_repmsg = NULL;
req->rq_replen = 0;
rc = 0;
out_free:
OBD_FREE_LARGE(token_buf, token_buflen);
return rc;
}
int gss_svc_authorize(struct ptlrpc_request *req)
{
struct ptlrpc_reply_state *rs = req->rq_reply_state;
struct gss_svc_reqctx *grctx = gss_svc_ctx2reqctx(req->rq_svc_ctx);
struct gss_wire_ctx *gw = &grctx->src_wirectx;
int early, rc;
early = (req->rq_packed_final == 0);
if (!early && gss_svc_reqctx_is_special(grctx)) {
LASSERT(rs->rs_repdata_len != 0);
req->rq_reply_off = gss_at_reply_off_integ;
return 0;
}
if (!early &&
gw->gw_proc != PTLRPC_GSS_PROC_DATA &&
gw->gw_proc != PTLRPC_GSS_PROC_DESTROY) {
CERROR("proc %d not support\n", gw->gw_proc);
return -EINVAL;
}
LASSERT(grctx->src_ctx);
switch (gw->gw_svc) {
case SPTLRPC_SVC_NULL:
case SPTLRPC_SVC_AUTH:
case SPTLRPC_SVC_INTG:
rc = gss_svc_sign(req, rs, grctx, gw->gw_svc);
break;
case SPTLRPC_SVC_PRIV:
rc = gss_svc_seal(req, rs, grctx);
break;
default:
CERROR("Unknown service %d\n", gw->gw_svc);
GOTO(out, rc = -EINVAL);
}
rc = 0;
out:
return rc;
}
void gss_svc_free_rs(struct ptlrpc_reply_state *rs)
{
struct gss_svc_reqctx *grctx;
LASSERT(rs->rs_svc_ctx);
grctx = container_of(rs->rs_svc_ctx, struct gss_svc_reqctx, src_base);
gss_svc_reqctx_decref(grctx);
rs->rs_svc_ctx = NULL;
if (!rs->rs_prealloc)
OBD_FREE_LARGE(rs, rs->rs_size);
}
void gss_svc_free_ctx(struct ptlrpc_svc_ctx *ctx)
{
LASSERT(atomic_read(&ctx->sc_refcount) == 0);
gss_svc_reqctx_free(gss_svc_ctx2reqctx(ctx));
}
int gss_copy_rvc_cli_ctx(struct ptlrpc_cli_ctx *cli_ctx,
struct ptlrpc_svc_ctx *svc_ctx)
{
struct gss_cli_ctx *cli_gctx = ctx2gctx(cli_ctx);
struct gss_svc_ctx *svc_gctx = gss_svc_ctx2gssctx(svc_ctx);
struct gss_ctx *mechctx = NULL;
LASSERT(cli_gctx);
LASSERT(svc_gctx && svc_gctx->gsc_mechctx);
cli_gctx->gc_proc = PTLRPC_GSS_PROC_DATA;
cli_gctx->gc_win = GSS_SEQ_WIN;
atomic_set(&cli_gctx->gc_seq, svc_gctx->gsc_rvs_seq);
if (gss_svc_upcall_dup_handle(&cli_gctx->gc_svc_handle, svc_gctx)) {
CERROR("failed to dup svc handle\n");
goto err_out;
}
if (lgss_copy_reverse_context(svc_gctx->gsc_mechctx, &mechctx) !=
GSS_S_COMPLETE) {
CERROR("failed to copy mech context\n");
goto err_svc_handle;
}
if (rawobj_dup(&cli_gctx->gc_handle, &svc_gctx->gsc_rvs_hdl)) {
CERROR("failed to dup reverse handle\n");
goto err_ctx;
}
cli_gctx->gc_mechctx = mechctx;
gss_cli_ctx_uptodate(cli_gctx);
return 0;
err_ctx:
lgss_delete_sec_context(&mechctx);
err_svc_handle:
rawobj_free(&cli_gctx->gc_svc_handle);
err_out:
return -ENOMEM;
}
static void gss_init_at_reply_offset(void)
{
__u32 buflens[3];
int clearsize;
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = lustre_msg_early_size();
buflens[2] = gss_cli_payload(NULL, buflens[1], 0);
gss_at_reply_off_integ = lustre_msg_size_v2(3, buflens);
buflens[0] = lustre_msg_early_size();
clearsize = lustre_msg_size_v2(1, buflens);
buflens[0] = PTLRPC_GSS_HEADER_SIZE;
buflens[1] = gss_cli_payload(NULL, clearsize, 0);
buflens[2] = gss_cli_payload(NULL, clearsize, 1);
gss_at_reply_off_priv = lustre_msg_size_v2(3, buflens);
}
int __init sptlrpc_gss_init(void)
{
int rc;
rc = gss_init_lproc();
if (rc)
return rc;
rc = gss_init_cli_upcall();
if (rc)
goto out_lproc;
rc = gss_init_svc_upcall();
if (rc)
goto out_cli_upcall;
rc = init_kerberos_module();
if (rc)
goto out_svc_upcall;
rc = gss_init_keyring();
if (rc)
goto out_kerberos;
#ifdef HAVE_GSS_PIPEFS
rc = gss_init_pipefs();
if (rc)
goto out_keyring;
#endif
gss_init_at_reply_offset();
return 0;
#ifdef HAVE_GSS_PIPEFS
out_keyring:
gss_exit_keyring();
#endif
out_kerberos:
cleanup_kerberos_module();
out_svc_upcall:
gss_exit_svc_upcall();
out_cli_upcall:
gss_exit_cli_upcall();
out_lproc:
gss_exit_lproc();
return rc;
}
static void __exit sptlrpc_gss_exit(void)
{
gss_exit_keyring();
#ifdef HAVE_GSS_PIPEFS
gss_exit_pipefs();
#endif
cleanup_kerberos_module();
gss_exit_svc_upcall();
gss_exit_cli_upcall();
gss_exit_lproc();
}
