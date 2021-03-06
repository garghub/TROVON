static int gssx_enc_bool(struct xdr_stream *xdr, int v)
{
__be32 *p;
p = xdr_reserve_space(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
*p = v ? xdr_one : xdr_zero;
return 0;
}
static int gssx_dec_bool(struct xdr_stream *xdr, u32 *v)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
*v = be32_to_cpu(*p);
return 0;
}
static int gssx_enc_buffer(struct xdr_stream *xdr,
gssx_buffer *buf)
{
__be32 *p;
p = xdr_reserve_space(xdr, sizeof(u32) + buf->len);
if (!p)
return -ENOSPC;
xdr_encode_opaque(p, buf->data, buf->len);
return 0;
}
static int gssx_enc_in_token(struct xdr_stream *xdr,
struct gssp_in_token *in)
{
__be32 *p;
p = xdr_reserve_space(xdr, 4);
if (!p)
return -ENOSPC;
*p = cpu_to_be32(in->page_len);
xdr_write_pages(xdr, in->pages, in->page_base, in->page_len);
return 0;
}
static int gssx_dec_buffer(struct xdr_stream *xdr,
gssx_buffer *buf)
{
u32 length;
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
length = be32_to_cpup(p);
p = xdr_inline_decode(xdr, length);
if (unlikely(p == NULL))
return -ENOSPC;
if (buf->len == 0) {
return 0;
}
if (length > buf->len)
return -ENOSPC;
if (!buf->data) {
buf->data = kmemdup(p, length, GFP_KERNEL);
if (!buf->data)
return -ENOMEM;
} else {
memcpy(buf->data, p, length);
}
buf->len = length;
return 0;
}
static int gssx_enc_option(struct xdr_stream *xdr,
struct gssx_option *opt)
{
int err;
err = gssx_enc_buffer(xdr, &opt->option);
if (err)
return err;
err = gssx_enc_buffer(xdr, &opt->value);
return err;
}
static int gssx_dec_option(struct xdr_stream *xdr,
struct gssx_option *opt)
{
int err;
err = gssx_dec_buffer(xdr, &opt->option);
if (err)
return err;
err = gssx_dec_buffer(xdr, &opt->value);
return err;
}
static int dummy_enc_opt_array(struct xdr_stream *xdr,
struct gssx_option_array *oa)
{
__be32 *p;
if (oa->count != 0)
return -EINVAL;
p = xdr_reserve_space(xdr, 4);
if (!p)
return -ENOSPC;
*p = 0;
return 0;
}
static int dummy_dec_opt_array(struct xdr_stream *xdr,
struct gssx_option_array *oa)
{
struct gssx_option dummy;
u32 count, i;
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
count = be32_to_cpup(p++);
memset(&dummy, 0, sizeof(dummy));
for (i = 0; i < count; i++) {
gssx_dec_option(xdr, &dummy);
}
oa->count = 0;
oa->data = NULL;
return 0;
}
static int get_s32(void **p, void *max, s32 *res)
{
void *base = *p;
void *next = (void *)((char *)base + sizeof(s32));
if (unlikely(next > max || next < base))
return -EINVAL;
memcpy(res, base, sizeof(s32));
*p = next;
return 0;
}
static int gssx_dec_linux_creds(struct xdr_stream *xdr,
struct svc_cred *creds)
{
u32 length;
__be32 *p;
void *q, *end;
s32 tmp;
int N, i, err;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
length = be32_to_cpup(p);
p = xdr_inline_decode(xdr, length);
if (unlikely(p == NULL))
return -ENOSPC;
q = p;
end = q + length;
err = get_s32(&q, end, &tmp);
if (err)
return err;
creds->cr_uid = make_kuid(&init_user_ns, tmp);
err = get_s32(&q, end, &tmp);
if (err)
return err;
creds->cr_gid = make_kgid(&init_user_ns, tmp);
err = get_s32(&q, end, &tmp);
if (err)
return err;
N = tmp;
creds->cr_group_info = groups_alloc(N);
if (creds->cr_group_info == NULL)
return -ENOMEM;
for (i = 0; i < N; i++) {
kgid_t kgid;
err = get_s32(&q, end, &tmp);
if (err)
goto out_free_groups;
err = -EINVAL;
kgid = make_kgid(&init_user_ns, tmp);
if (!gid_valid(kgid))
goto out_free_groups;
GROUP_AT(creds->cr_group_info, i) = kgid;
}
return 0;
out_free_groups:
groups_free(creds->cr_group_info);
return err;
}
static int gssx_dec_option_array(struct xdr_stream *xdr,
struct gssx_option_array *oa)
{
struct svc_cred *creds;
u32 count, i;
__be32 *p;
int err;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
count = be32_to_cpup(p++);
if (!count)
return 0;
oa->count = 1;
oa->data = kmalloc(sizeof(struct gssx_option), GFP_KERNEL);
if (!oa->data)
return -ENOMEM;
creds = kmalloc(sizeof(struct svc_cred), GFP_KERNEL);
if (!creds) {
kfree(oa->data);
return -ENOMEM;
}
oa->data[0].option.data = CREDS_VALUE;
oa->data[0].option.len = sizeof(CREDS_VALUE);
oa->data[0].value.data = (void *)creds;
oa->data[0].value.len = 0;
for (i = 0; i < count; i++) {
gssx_buffer dummy = { 0, NULL };
u32 length;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
length = be32_to_cpup(p);
p = xdr_inline_decode(xdr, length);
if (unlikely(p == NULL))
return -ENOSPC;
if (length == sizeof(CREDS_VALUE) &&
memcmp(p, CREDS_VALUE, sizeof(CREDS_VALUE)) == 0) {
err = gssx_dec_linux_creds(xdr, creds);
if (err)
return err;
oa->data[0].value.len = 1;
} else {
err = gssx_dec_buffer(xdr, &dummy);
if (err)
return err;
}
}
return 0;
}
static int gssx_dec_status(struct xdr_stream *xdr,
struct gssx_status *status)
{
__be32 *p;
int err;
p = xdr_inline_decode(xdr, 8);
if (unlikely(p == NULL))
return -ENOSPC;
p = xdr_decode_hyper(p, &status->major_status);
err = gssx_dec_buffer(xdr, &status->mech);
if (err)
return err;
p = xdr_inline_decode(xdr, 8);
if (unlikely(p == NULL))
return -ENOSPC;
p = xdr_decode_hyper(p, &status->minor_status);
err = gssx_dec_buffer(xdr, &status->major_status_string);
if (err)
return err;
err = gssx_dec_buffer(xdr, &status->minor_status_string);
if (err)
return err;
err = gssx_dec_buffer(xdr, &status->server_ctx);
if (err)
return err;
err = dummy_dec_opt_array(xdr, &status->options);
return err;
}
static int gssx_enc_call_ctx(struct xdr_stream *xdr,
struct gssx_call_ctx *ctx)
{
struct gssx_option opt;
__be32 *p;
int err;
err = gssx_enc_buffer(xdr, &ctx->locale);
if (err)
return err;
err = gssx_enc_buffer(xdr, &ctx->server_ctx);
if (err)
return err;
p = xdr_reserve_space(xdr, 4);
*p = cpu_to_be32(2);
opt.option.data = LUCID_OPTION;
opt.option.len = sizeof(LUCID_OPTION);
opt.value.data = LUCID_VALUE;
opt.value.len = sizeof(LUCID_VALUE);
err = gssx_enc_option(xdr, &opt);
opt.option.data = CREDS_OPTION;
opt.option.len = sizeof(CREDS_OPTION);
opt.value.data = CREDS_VALUE;
opt.value.len = sizeof(CREDS_VALUE);
err = gssx_enc_option(xdr, &opt);
return err;
}
static int gssx_dec_name_attr(struct xdr_stream *xdr,
struct gssx_name_attr *attr)
{
int err;
err = gssx_dec_buffer(xdr, &attr->attr);
if (err)
return err;
err = gssx_dec_buffer(xdr, &attr->value);
if (err)
return err;
err = dummy_dec_opt_array(xdr, &attr->extensions);
return err;
}
static int dummy_enc_nameattr_array(struct xdr_stream *xdr,
struct gssx_name_attr_array *naa)
{
__be32 *p;
if (naa->count != 0)
return -EINVAL;
p = xdr_reserve_space(xdr, 4);
if (!p)
return -ENOSPC;
*p = 0;
return 0;
}
static int dummy_dec_nameattr_array(struct xdr_stream *xdr,
struct gssx_name_attr_array *naa)
{
struct gssx_name_attr dummy = { .attr = {.len = 0} };
u32 count, i;
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -ENOSPC;
count = be32_to_cpup(p++);
for (i = 0; i < count; i++) {
gssx_dec_name_attr(xdr, &dummy);
}
naa->count = 0;
naa->data = NULL;
return 0;
}
static int gssx_enc_name(struct xdr_stream *xdr,
struct gssx_name *name)
{
int err;
err = gssx_enc_buffer(xdr, &name->display_name);
if (err)
return err;
err = gssx_enc_buffer(xdr, &zero_netobj);
if (err)
return err;
err = gssx_enc_buffer(xdr, &zero_netobj);
if (err)
return err;
err = gssx_enc_buffer(xdr, &zero_netobj);
if (err)
return err;
err = dummy_enc_nameattr_array(xdr, &zero_name_attr_array);
if (err)
return err;
err = dummy_enc_opt_array(xdr, &zero_option_array);
return err;
}
static int gssx_dec_name(struct xdr_stream *xdr,
struct gssx_name *name)
{
struct xdr_netobj dummy_netobj = { .len = 0 };
struct gssx_name_attr_array dummy_name_attr_array = { .count = 0 };
struct gssx_option_array dummy_option_array = { .count = 0 };
int err;
err = gssx_dec_buffer(xdr, &name->display_name);
if (err)
return err;
err = gssx_dec_buffer(xdr, &dummy_netobj);
if (err)
return err;
err = gssx_dec_buffer(xdr, &dummy_netobj);
if (err)
return err;
err = gssx_dec_buffer(xdr, &dummy_netobj);
if (err)
return err;
err = dummy_dec_nameattr_array(xdr, &dummy_name_attr_array);
if (err)
return err;
err = dummy_dec_opt_array(xdr, &dummy_option_array);
return err;
}
static int dummy_enc_credel_array(struct xdr_stream *xdr,
struct gssx_cred_element_array *cea)
{
__be32 *p;
if (cea->count != 0)
return -EINVAL;
p = xdr_reserve_space(xdr, 4);
if (!p)
return -ENOSPC;
*p = 0;
return 0;
}
static int gssx_enc_cred(struct xdr_stream *xdr,
struct gssx_cred *cred)
{
int err;
err = gssx_enc_name(xdr, &cred->desired_name);
if (err)
return err;
err = dummy_enc_credel_array(xdr, &cred->elements);
err = gssx_enc_buffer(xdr, &cred->cred_handle_reference);
if (err)
return err;
err = gssx_enc_bool(xdr, cred->needs_release);
return err;
}
static int gssx_enc_ctx(struct xdr_stream *xdr,
struct gssx_ctx *ctx)
{
__be32 *p;
int err;
err = gssx_enc_buffer(xdr, &ctx->exported_context_token);
if (err)
return err;
err = gssx_enc_buffer(xdr, &ctx->state);
if (err)
return err;
err = gssx_enc_bool(xdr, ctx->need_release);
if (err)
return err;
err = gssx_enc_buffer(xdr, &ctx->mech);
if (err)
return err;
err = gssx_enc_name(xdr, &ctx->src_name);
if (err)
return err;
err = gssx_enc_name(xdr, &ctx->targ_name);
if (err)
return err;
p = xdr_reserve_space(xdr, 8+8);
if (!p)
return -ENOSPC;
p = xdr_encode_hyper(p, ctx->lifetime);
p = xdr_encode_hyper(p, ctx->ctx_flags);
err = gssx_enc_bool(xdr, ctx->locally_initiated);
if (err)
return err;
err = gssx_enc_bool(xdr, ctx->open);
if (err)
return err;
err = dummy_enc_opt_array(xdr, &ctx->options);
return err;
}
static int gssx_dec_ctx(struct xdr_stream *xdr,
struct gssx_ctx *ctx)
{
__be32 *p;
int err;
err = gssx_dec_buffer(xdr, &ctx->exported_context_token);
if (err)
return err;
err = gssx_dec_buffer(xdr, &ctx->state);
if (err)
return err;
err = gssx_dec_bool(xdr, &ctx->need_release);
if (err)
return err;
err = gssx_dec_buffer(xdr, &ctx->mech);
if (err)
return err;
err = gssx_dec_name(xdr, &ctx->src_name);
if (err)
return err;
err = gssx_dec_name(xdr, &ctx->targ_name);
if (err)
return err;
p = xdr_inline_decode(xdr, 8+8);
if (unlikely(p == NULL))
return -ENOSPC;
p = xdr_decode_hyper(p, &ctx->lifetime);
p = xdr_decode_hyper(p, &ctx->ctx_flags);
err = gssx_dec_bool(xdr, &ctx->locally_initiated);
if (err)
return err;
err = gssx_dec_bool(xdr, &ctx->open);
if (err)
return err;
err = dummy_dec_opt_array(xdr, &ctx->options);
return err;
}
static int gssx_enc_cb(struct xdr_stream *xdr, struct gssx_cb *cb)
{
__be32 *p;
int err;
p = xdr_reserve_space(xdr, 8);
if (!p)
return -ENOSPC;
p = xdr_encode_hyper(p, cb->initiator_addrtype);
err = gssx_enc_buffer(xdr, &cb->initiator_address);
if (err)
return err;
p = xdr_reserve_space(xdr, 8);
if (!p)
return -ENOSPC;
p = xdr_encode_hyper(p, cb->acceptor_addrtype);
err = gssx_enc_buffer(xdr, &cb->acceptor_address);
if (err)
return err;
err = gssx_enc_buffer(xdr, &cb->application_data);
return err;
}
void gssx_enc_accept_sec_context(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct gssx_arg_accept_sec_context *arg)
{
int err;
err = gssx_enc_call_ctx(xdr, &arg->call_ctx);
if (err)
goto done;
if (arg->context_handle) {
err = gssx_enc_ctx(xdr, arg->context_handle);
if (err)
goto done;
} else {
err = gssx_enc_bool(xdr, 0);
}
if (arg->cred_handle) {
err = gssx_enc_cred(xdr, arg->cred_handle);
if (err)
goto done;
} else {
err = gssx_enc_bool(xdr, 0);
}
err = gssx_enc_in_token(xdr, &arg->input_token);
if (err)
goto done;
if (arg->input_cb) {
err = gssx_enc_cb(xdr, arg->input_cb);
if (err)
goto done;
} else {
err = gssx_enc_bool(xdr, 0);
}
err = gssx_enc_bool(xdr, arg->ret_deleg_cred);
if (err)
goto done;
err = dummy_enc_opt_array(xdr, &arg->options);
done:
if (err)
dprintk("RPC: gssx_enc_accept_sec_context: %d\n", err);
}
int gssx_dec_accept_sec_context(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct gssx_res_accept_sec_context *res)
{
u32 value_follows;
int err;
err = gssx_dec_status(xdr, &res->status);
if (err)
return err;
err = gssx_dec_bool(xdr, &value_follows);
if (err)
return err;
if (value_follows) {
err = gssx_dec_ctx(xdr, res->context_handle);
if (err)
return err;
} else {
res->context_handle = NULL;
}
err = gssx_dec_bool(xdr, &value_follows);
if (err)
return err;
if (value_follows) {
err = gssx_dec_buffer(xdr, res->output_token);
if (err)
return err;
} else {
res->output_token = NULL;
}
err = gssx_dec_bool(xdr, &value_follows);
if (err)
return err;
if (value_follows) {
return -EINVAL;
}
err = gssx_dec_option_array(xdr, &res->options);
return err;
}
