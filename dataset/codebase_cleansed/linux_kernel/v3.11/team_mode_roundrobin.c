static struct rr_priv *rr_priv(struct team *team)
{
return (struct rr_priv *) &team->mode_priv;
}
static bool rr_transmit(struct team *team, struct sk_buff *skb)
{
struct team_port *port;
int port_index;
port_index = team_num_to_port_index(team,
rr_priv(team)->sent_packets++);
port = team_get_port_by_index_rcu(team, port_index);
if (unlikely(!port))
goto drop;
port = team_get_first_port_txable_rcu(team, port);
if (unlikely(!port))
goto drop;
if (team_dev_queue_xmit(team, port, skb))
return false;
return true;
drop:
dev_kfree_skb_any(skb);
return false;
}
static int __init rr_init_module(void)
{
return team_mode_register(&rr_mode);
}
static void __exit rr_cleanup_module(void)
{
team_mode_unregister(&rr_mode);
}
