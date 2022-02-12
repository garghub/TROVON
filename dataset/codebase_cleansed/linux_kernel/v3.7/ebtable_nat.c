static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
if (valid_hooks & ~NAT_VALID_HOOKS)
return -EINVAL;
return 0;
}
static unsigned int
ebt_nat_in(unsigned int hook, struct sk_buff *skb, const struct net_device *in
, const struct net_device *out, int (*okfn)(struct sk_buff *))
{
return ebt_do_table(hook, skb, in, out, dev_net(in)->xt.frame_nat);
}
static unsigned int
ebt_nat_out(unsigned int hook, struct sk_buff *skb, const struct net_device *in
, const struct net_device *out, int (*okfn)(struct sk_buff *))
{
return ebt_do_table(hook, skb, in, out, dev_net(out)->xt.frame_nat);
}
static int __net_init frame_nat_net_init(struct net *net)
{
net->xt.frame_nat = ebt_register_table(net, &frame_nat);
return PTR_RET(net->xt.frame_nat);
}
static void __net_exit frame_nat_net_exit(struct net *net)
{
ebt_unregister_table(net, net->xt.frame_nat);
}
static int __init ebtable_nat_init(void)
{
int ret;
ret = register_pernet_subsys(&frame_nat_net_ops);
if (ret < 0)
return ret;
ret = nf_register_hooks(ebt_ops_nat, ARRAY_SIZE(ebt_ops_nat));
if (ret < 0)
unregister_pernet_subsys(&frame_nat_net_ops);
return ret;
}
static void __exit ebtable_nat_fini(void)
{
nf_unregister_hooks(ebt_ops_nat, ARRAY_SIZE(ebt_ops_nat));
unregister_pernet_subsys(&frame_nat_net_ops);
}
