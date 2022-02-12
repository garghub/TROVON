static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
if (valid_hooks & ~(1 << NF_BR_BROUTING))
return -EINVAL;
return 0;
}
static int ebt_broute(struct sk_buff *skb)
{
struct nf_hook_state state;
int ret;
nf_hook_state_init(&state, NF_BR_BROUTING,
NFPROTO_BRIDGE, skb->dev, NULL, NULL,
dev_net(skb->dev), NULL);
ret = ebt_do_table(skb, &state, state.net->xt.broute_table);
if (ret == NF_DROP)
return 1;
return 0;
}
static int __net_init broute_net_init(struct net *net)
{
net->xt.broute_table = ebt_register_table(net, &broute_table);
return PTR_ERR_OR_ZERO(net->xt.broute_table);
}
static void __net_exit broute_net_exit(struct net *net)
{
ebt_unregister_table(net, net->xt.broute_table);
}
static int __init ebtable_broute_init(void)
{
int ret;
ret = register_pernet_subsys(&broute_net_ops);
if (ret < 0)
return ret;
RCU_INIT_POINTER(br_should_route_hook,
(br_should_route_hook_t *)ebt_broute);
return 0;
}
static void __exit ebtable_broute_fini(void)
{
RCU_INIT_POINTER(br_should_route_hook, NULL);
synchronize_net();
unregister_pernet_subsys(&broute_net_ops);
}
