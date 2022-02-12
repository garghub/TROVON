static struct lb_priv *lb_priv(struct team *team)
{
return (struct lb_priv *) &team->mode_priv;
}
static bool lb_transmit(struct team *team, struct sk_buff *skb)
{
struct sk_filter *fp;
struct team_port *port;
unsigned int hash;
int port_index;
fp = rcu_dereference(lb_priv(team)->fp);
if (unlikely(!fp))
goto drop;
hash = SK_RUN_FILTER(fp, skb);
port_index = hash % team->en_port_count;
port = team_get_port_by_index_rcu(team, port_index);
if (unlikely(!port))
goto drop;
skb->dev = port->dev;
if (dev_queue_xmit(skb))
return false;
return true;
drop:
dev_kfree_skb_any(skb);
return false;
}
static int lb_bpf_func_get(struct team *team, struct team_gsetter_ctx *ctx)
{
if (!lb_priv(team)->orig_fprog) {
ctx->data.bin_val.len = 0;
ctx->data.bin_val.ptr = NULL;
return 0;
}
ctx->data.bin_val.len = lb_priv(team)->orig_fprog->len *
sizeof(struct sock_filter);
ctx->data.bin_val.ptr = lb_priv(team)->orig_fprog->filter;
return 0;
}
static int __fprog_create(struct sock_fprog **pfprog, u32 data_len,
const void *data)
{
struct sock_fprog *fprog;
struct sock_filter *filter = (struct sock_filter *) data;
if (data_len % sizeof(struct sock_filter))
return -EINVAL;
fprog = kmalloc(sizeof(struct sock_fprog), GFP_KERNEL);
if (!fprog)
return -ENOMEM;
fprog->filter = kmemdup(filter, data_len, GFP_KERNEL);
if (!fprog->filter) {
kfree(fprog);
return -ENOMEM;
}
fprog->len = data_len / sizeof(struct sock_filter);
*pfprog = fprog;
return 0;
}
static void __fprog_destroy(struct sock_fprog *fprog)
{
kfree(fprog->filter);
kfree(fprog);
}
static int lb_bpf_func_set(struct team *team, struct team_gsetter_ctx *ctx)
{
struct sk_filter *fp = NULL;
struct sock_fprog *fprog = NULL;
int err;
if (ctx->data.bin_val.len) {
err = __fprog_create(&fprog, ctx->data.bin_val.len,
ctx->data.bin_val.ptr);
if (err)
return err;
err = sk_unattached_filter_create(&fp, fprog);
if (err) {
__fprog_destroy(fprog);
return err;
}
}
if (lb_priv(team)->orig_fprog) {
__fprog_destroy(lb_priv(team)->orig_fprog);
sk_unattached_filter_destroy(lb_priv(team)->fp);
}
rcu_assign_pointer(lb_priv(team)->fp, fp);
lb_priv(team)->orig_fprog = fprog;
return 0;
}
static int lb_init(struct team *team)
{
return team_options_register(team, lb_options,
ARRAY_SIZE(lb_options));
}
static void lb_exit(struct team *team)
{
team_options_unregister(team, lb_options,
ARRAY_SIZE(lb_options));
}
static int __init lb_init_module(void)
{
return team_mode_register(&lb_mode);
}
static void __exit lb_cleanup_module(void)
{
team_mode_unregister(&lb_mode);
}
