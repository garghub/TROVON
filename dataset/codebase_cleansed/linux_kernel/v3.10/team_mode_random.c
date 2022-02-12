static u32 random_N(unsigned int N)
{
return reciprocal_divide(prandom_u32(), N);
}
static bool rnd_transmit(struct team *team, struct sk_buff *skb)
{
struct team_port *port;
int port_index;
port_index = random_N(team->en_port_count);
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
static int __init rnd_init_module(void)
{
return team_mode_register(&rnd_mode);
}
static void __exit rnd_cleanup_module(void)
{
team_mode_unregister(&rnd_mode);
}
