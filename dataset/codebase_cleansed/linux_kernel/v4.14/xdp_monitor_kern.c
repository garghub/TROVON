static __always_inline
int xdp_redirect_collect_stat(struct xdp_redirect_ctx *ctx)
{
u32 key = XDP_REDIRECT_ERROR;
int err = ctx->err;
u64 *cnt;
if (!err)
key = XDP_REDIRECT_SUCCESS;
cnt = bpf_map_lookup_elem(&redirect_err_cnt, &key);
if (!cnt)
return 0;
*cnt += 1;
return 0;
}
int trace_xdp_redirect_err(struct xdp_redirect_ctx *ctx)
{
return xdp_redirect_collect_stat(ctx);
}
int trace_xdp_redirect_map_err(struct xdp_redirect_ctx *ctx)
{
return xdp_redirect_collect_stat(ctx);
}
int trace_xdp_redirect(struct xdp_redirect_ctx *ctx)
{
return xdp_redirect_collect_stat(ctx);
}
int trace_xdp_redirect_map(struct xdp_redirect_ctx *ctx)
{
return xdp_redirect_collect_stat(ctx);
}
