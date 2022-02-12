static bool bc_transmit(struct team *team, struct sk_buff *skb)
{
struct team_port *cur;
struct team_port *last = NULL;
struct sk_buff *skb2;
bool ret;
bool sum_ret = false;
list_for_each_entry_rcu(cur, &team->port_list, list) {
if (team_port_txable(cur)) {
if (last) {
skb2 = skb_clone(skb, GFP_ATOMIC);
if (skb2) {
ret = !team_dev_queue_xmit(team, last,
skb2);
if (!sum_ret)
sum_ret = ret;
}
}
last = cur;
}
}
if (last) {
ret = !team_dev_queue_xmit(team, last, skb);
if (!sum_ret)
sum_ret = ret;
}
return sum_ret;
}
static int __init bc_init_module(void)
{
return team_mode_register(&bc_mode);
}
static void __exit bc_cleanup_module(void)
{
team_mode_unregister(&bc_mode);
}
