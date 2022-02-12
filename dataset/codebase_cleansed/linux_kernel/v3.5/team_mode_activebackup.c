static struct ab_priv *ab_priv(struct team *team)
{
return (struct ab_priv *) &team->mode_priv;
}
static rx_handler_result_t ab_receive(struct team *team, struct team_port *port,
struct sk_buff *skb) {
struct team_port *active_port;
active_port = rcu_dereference(ab_priv(team)->active_port);
if (active_port != port)
return RX_HANDLER_EXACT;
return RX_HANDLER_ANOTHER;
}
static bool ab_transmit(struct team *team, struct sk_buff *skb)
{
struct team_port *active_port;
active_port = rcu_dereference(ab_priv(team)->active_port);
if (unlikely(!active_port))
goto drop;
skb->dev = active_port->dev;
if (dev_queue_xmit(skb))
return false;
return true;
drop:
dev_kfree_skb_any(skb);
return false;
}
static void ab_port_leave(struct team *team, struct team_port *port)
{
if (ab_priv(team)->active_port == port)
RCU_INIT_POINTER(ab_priv(team)->active_port, NULL);
}
static int ab_active_port_get(struct team *team, struct team_gsetter_ctx *ctx)
{
if (ab_priv(team)->active_port)
ctx->data.u32_val = ab_priv(team)->active_port->dev->ifindex;
else
ctx->data.u32_val = 0;
return 0;
}
static int ab_active_port_set(struct team *team, struct team_gsetter_ctx *ctx)
{
struct team_port *port;
list_for_each_entry(port, &team->port_list, list) {
if (port->dev->ifindex == ctx->data.u32_val) {
rcu_assign_pointer(ab_priv(team)->active_port, port);
return 0;
}
}
return -ENOENT;
}
static int ab_init(struct team *team)
{
return team_options_register(team, ab_options, ARRAY_SIZE(ab_options));
}
static void ab_exit(struct team *team)
{
team_options_unregister(team, ab_options, ARRAY_SIZE(ab_options));
}
static int __init ab_init_module(void)
{
return team_mode_register(&ab_mode);
}
static void __exit ab_cleanup_module(void)
{
team_mode_unregister(&ab_mode);
}
