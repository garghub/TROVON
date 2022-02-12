static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
if (valid_hooks & ~FILTER_VALID_HOOKS)
return -EINVAL;
return 0;
}
static unsigned int
ebt_in_hook(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ebt_do_table(ops->hooknum, skb, in, out,
dev_net(in)->xt.frame_filter);
}
static unsigned int
ebt_out_hook(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return ebt_do_table(ops->hooknum, skb, in, out,
dev_net(out)->xt.frame_filter);
}
static int __net_init frame_filter_net_init(struct net *net)
{
net->xt.frame_filter = ebt_register_table(net, &frame_filter);
return PTR_ERR_OR_ZERO(net->xt.frame_filter);
}
static void __net_exit frame_filter_net_exit(struct net *net)
{
ebt_unregister_table(net, net->xt.frame_filter);
}
static int __init ebtable_filter_init(void)
{
int ret;
ret = register_pernet_subsys(&frame_filter_net_ops);
if (ret < 0)
return ret;
ret = nf_register_hooks(ebt_ops_filter, ARRAY_SIZE(ebt_ops_filter));
if (ret < 0)
unregister_pernet_subsys(&frame_filter_net_ops);
return ret;
}
static void __exit ebtable_filter_fini(void)
{
nf_unregister_hooks(ebt_ops_filter, ARRAY_SIZE(ebt_ops_filter));
unregister_pernet_subsys(&frame_filter_net_ops);
}
