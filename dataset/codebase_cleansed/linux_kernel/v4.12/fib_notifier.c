int call_fib_notifier(struct notifier_block *nb, struct net *net,
enum fib_event_type event_type,
struct fib_notifier_info *info)
{
info->net = net;
return nb->notifier_call(nb, event_type, info);
}
int call_fib_notifiers(struct net *net, enum fib_event_type event_type,
struct fib_notifier_info *info)
{
net->ipv4.fib_seq++;
info->net = net;
return atomic_notifier_call_chain(&fib_chain, event_type, info);
}
static unsigned int fib_seq_sum(void)
{
unsigned int fib_seq = 0;
struct net *net;
rtnl_lock();
for_each_net(net)
fib_seq += net->ipv4.fib_seq;
rtnl_unlock();
return fib_seq;
}
static bool fib_dump_is_consistent(struct notifier_block *nb,
void (*cb)(struct notifier_block *nb),
unsigned int fib_seq)
{
atomic_notifier_chain_register(&fib_chain, nb);
if (fib_seq == fib_seq_sum())
return true;
atomic_notifier_chain_unregister(&fib_chain, nb);
if (cb)
cb(nb);
return false;
}
int register_fib_notifier(struct notifier_block *nb,
void (*cb)(struct notifier_block *nb))
{
int retries = 0;
do {
unsigned int fib_seq = fib_seq_sum();
struct net *net;
rcu_read_lock();
for_each_net_rcu(net) {
fib_rules_notify(net, nb);
fib_notify(net, nb);
}
rcu_read_unlock();
if (fib_dump_is_consistent(nb, cb, fib_seq))
return 0;
} while (++retries < FIB_DUMP_MAX_RETRIES);
return -EBUSY;
}
int unregister_fib_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&fib_chain, nb);
}
