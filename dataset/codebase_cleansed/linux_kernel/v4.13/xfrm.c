static inline int selinux_authorizable_ctx(struct xfrm_sec_ctx *ctx)
{
return (ctx &&
(ctx->ctx_doi == XFRM_SC_DOI_LSM) &&
(ctx->ctx_alg == XFRM_SC_ALG_SELINUX));
}
static inline int selinux_authorizable_xfrm(struct xfrm_state *x)
{
return selinux_authorizable_ctx(x->security);
}
static int selinux_xfrm_alloc_user(struct xfrm_sec_ctx **ctxp,
struct xfrm_user_sec_ctx *uctx,
gfp_t gfp)
{
int rc;
const struct task_security_struct *tsec = current_security();
struct xfrm_sec_ctx *ctx = NULL;
u32 str_len;
if (ctxp == NULL || uctx == NULL ||
uctx->ctx_doi != XFRM_SC_DOI_LSM ||
uctx->ctx_alg != XFRM_SC_ALG_SELINUX)
return -EINVAL;
str_len = uctx->ctx_len;
if (str_len >= PAGE_SIZE)
return -ENOMEM;
ctx = kmalloc(sizeof(*ctx) + str_len + 1, gfp);
if (!ctx)
return -ENOMEM;
ctx->ctx_doi = XFRM_SC_DOI_LSM;
ctx->ctx_alg = XFRM_SC_ALG_SELINUX;
ctx->ctx_len = str_len;
memcpy(ctx->ctx_str, &uctx[1], str_len);
ctx->ctx_str[str_len] = '\0';
rc = security_context_to_sid(ctx->ctx_str, str_len, &ctx->ctx_sid, gfp);
if (rc)
goto err;
rc = avc_has_perm(tsec->sid, ctx->ctx_sid,
SECCLASS_ASSOCIATION, ASSOCIATION__SETCONTEXT, NULL);
if (rc)
goto err;
*ctxp = ctx;
atomic_inc(&selinux_xfrm_refcount);
return 0;
err:
kfree(ctx);
return rc;
}
static void selinux_xfrm_free(struct xfrm_sec_ctx *ctx)
{
if (!ctx)
return;
atomic_dec(&selinux_xfrm_refcount);
kfree(ctx);
}
static int selinux_xfrm_delete(struct xfrm_sec_ctx *ctx)
{
const struct task_security_struct *tsec = current_security();
if (!ctx)
return 0;
return avc_has_perm(tsec->sid, ctx->ctx_sid,
SECCLASS_ASSOCIATION, ASSOCIATION__SETCONTEXT,
NULL);
}
int selinux_xfrm_policy_lookup(struct xfrm_sec_ctx *ctx, u32 fl_secid, u8 dir)
{
int rc;
if (!ctx)
return 0;
if (!selinux_authorizable_ctx(ctx))
return -EINVAL;
rc = avc_has_perm(fl_secid, ctx->ctx_sid,
SECCLASS_ASSOCIATION, ASSOCIATION__POLMATCH, NULL);
return (rc == -EACCES ? -ESRCH : rc);
}
int selinux_xfrm_state_pol_flow_match(struct xfrm_state *x,
struct xfrm_policy *xp,
const struct flowi *fl)
{
u32 state_sid;
if (!xp->security)
if (x->security)
return 0;
else
return 1;
else
if (!x->security)
return 0;
else
if (!selinux_authorizable_xfrm(x))
return 0;
state_sid = x->security->ctx_sid;
if (fl->flowi_secid != state_sid)
return 0;
return (avc_has_perm(fl->flowi_secid, state_sid,
SECCLASS_ASSOCIATION, ASSOCIATION__SENDTO,
NULL) ? 0 : 1);
}
static u32 selinux_xfrm_skb_sid_egress(struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct xfrm_state *x;
if (dst == NULL)
return SECSID_NULL;
x = dst->xfrm;
if (x == NULL || !selinux_authorizable_xfrm(x))
return SECSID_NULL;
return x->security->ctx_sid;
}
static int selinux_xfrm_skb_sid_ingress(struct sk_buff *skb,
u32 *sid, int ckall)
{
u32 sid_session = SECSID_NULL;
struct sec_path *sp = skb->sp;
if (sp) {
int i;
for (i = sp->len - 1; i >= 0; i--) {
struct xfrm_state *x = sp->xvec[i];
if (selinux_authorizable_xfrm(x)) {
struct xfrm_sec_ctx *ctx = x->security;
if (sid_session == SECSID_NULL) {
sid_session = ctx->ctx_sid;
if (!ckall)
goto out;
} else if (sid_session != ctx->ctx_sid) {
*sid = SECSID_NULL;
return -EINVAL;
}
}
}
}
out:
*sid = sid_session;
return 0;
}
int selinux_xfrm_decode_session(struct sk_buff *skb, u32 *sid, int ckall)
{
if (skb == NULL) {
*sid = SECSID_NULL;
return 0;
}
return selinux_xfrm_skb_sid_ingress(skb, sid, ckall);
}
int selinux_xfrm_skb_sid(struct sk_buff *skb, u32 *sid)
{
int rc;
rc = selinux_xfrm_skb_sid_ingress(skb, sid, 0);
if (rc == 0 && *sid == SECSID_NULL)
*sid = selinux_xfrm_skb_sid_egress(skb);
return rc;
}
int selinux_xfrm_policy_alloc(struct xfrm_sec_ctx **ctxp,
struct xfrm_user_sec_ctx *uctx,
gfp_t gfp)
{
return selinux_xfrm_alloc_user(ctxp, uctx, gfp);
}
int selinux_xfrm_policy_clone(struct xfrm_sec_ctx *old_ctx,
struct xfrm_sec_ctx **new_ctxp)
{
struct xfrm_sec_ctx *new_ctx;
if (!old_ctx)
return 0;
new_ctx = kmemdup(old_ctx, sizeof(*old_ctx) + old_ctx->ctx_len,
GFP_ATOMIC);
if (!new_ctx)
return -ENOMEM;
atomic_inc(&selinux_xfrm_refcount);
*new_ctxp = new_ctx;
return 0;
}
void selinux_xfrm_policy_free(struct xfrm_sec_ctx *ctx)
{
selinux_xfrm_free(ctx);
}
int selinux_xfrm_policy_delete(struct xfrm_sec_ctx *ctx)
{
return selinux_xfrm_delete(ctx);
}
int selinux_xfrm_state_alloc(struct xfrm_state *x,
struct xfrm_user_sec_ctx *uctx)
{
return selinux_xfrm_alloc_user(&x->security, uctx, GFP_KERNEL);
}
int selinux_xfrm_state_alloc_acquire(struct xfrm_state *x,
struct xfrm_sec_ctx *polsec, u32 secid)
{
int rc;
struct xfrm_sec_ctx *ctx;
char *ctx_str = NULL;
int str_len;
if (!polsec)
return 0;
if (secid == 0)
return -EINVAL;
rc = security_sid_to_context(secid, &ctx_str, &str_len);
if (rc)
return rc;
ctx = kmalloc(sizeof(*ctx) + str_len, GFP_ATOMIC);
if (!ctx) {
rc = -ENOMEM;
goto out;
}
ctx->ctx_doi = XFRM_SC_DOI_LSM;
ctx->ctx_alg = XFRM_SC_ALG_SELINUX;
ctx->ctx_sid = secid;
ctx->ctx_len = str_len;
memcpy(ctx->ctx_str, ctx_str, str_len);
x->security = ctx;
atomic_inc(&selinux_xfrm_refcount);
out:
kfree(ctx_str);
return rc;
}
void selinux_xfrm_state_free(struct xfrm_state *x)
{
selinux_xfrm_free(x->security);
}
int selinux_xfrm_state_delete(struct xfrm_state *x)
{
return selinux_xfrm_delete(x->security);
}
int selinux_xfrm_sock_rcv_skb(u32 sk_sid, struct sk_buff *skb,
struct common_audit_data *ad)
{
int i;
struct sec_path *sp = skb->sp;
u32 peer_sid = SECINITSID_UNLABELED;
if (sp) {
for (i = 0; i < sp->len; i++) {
struct xfrm_state *x = sp->xvec[i];
if (x && selinux_authorizable_xfrm(x)) {
struct xfrm_sec_ctx *ctx = x->security;
peer_sid = ctx->ctx_sid;
break;
}
}
}
return avc_has_perm(sk_sid, peer_sid,
SECCLASS_ASSOCIATION, ASSOCIATION__RECVFROM, ad);
}
int selinux_xfrm_postroute_last(u32 sk_sid, struct sk_buff *skb,
struct common_audit_data *ad, u8 proto)
{
struct dst_entry *dst;
switch (proto) {
case IPPROTO_AH:
case IPPROTO_ESP:
case IPPROTO_COMP:
return 0;
default:
break;
}
dst = skb_dst(skb);
if (dst) {
struct dst_entry *iter;
for (iter = dst; iter != NULL; iter = iter->child) {
struct xfrm_state *x = iter->xfrm;
if (x && selinux_authorizable_xfrm(x))
return 0;
}
}
return avc_has_perm(sk_sid, SECINITSID_UNLABELED,
SECCLASS_ASSOCIATION, ASSOCIATION__SENDTO, ad);
}
