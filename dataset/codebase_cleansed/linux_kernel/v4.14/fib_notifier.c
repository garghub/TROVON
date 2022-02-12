int call_fib4_notifier(struct notifier_block *nb, struct net *net,
enum fib_event_type event_type,
struct fib_notifier_info *info)
{
info->family = AF_INET;
return call_fib_notifier(nb, net, event_type, info);
}
int call_fib4_notifiers(struct net *net, enum fib_event_type event_type,
struct fib_notifier_info *info)
{
ASSERT_RTNL();
info->family = AF_INET;
net->ipv4.fib_seq++;
return call_fib_notifiers(net, event_type, info);
}
static unsigned int fib4_seq_read(struct net *net)
{
ASSERT_RTNL();
return net->ipv4.fib_seq + fib4_rules_seq_read(net);
}
static int fib4_dump(struct net *net, struct notifier_block *nb)
{
int err;
err = fib4_rules_dump(net, nb);
if (err)
return err;
fib_notify(net, nb);
return 0;
}
int __net_init fib4_notifier_init(struct net *net)
{
struct fib_notifier_ops *ops;
net->ipv4.fib_seq = 0;
ops = fib_notifier_ops_register(&fib4_notifier_ops_template, net);
if (IS_ERR(ops))
return PTR_ERR(ops);
net->ipv4.notifier_ops = ops;
return 0;
}
void __net_exit fib4_notifier_exit(struct net *net)
{
fib_notifier_ops_unregister(net->ipv4.notifier_ops);
}
