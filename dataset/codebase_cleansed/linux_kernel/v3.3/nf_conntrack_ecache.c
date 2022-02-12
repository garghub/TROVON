void nf_ct_deliver_cached_events(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
unsigned long events;
struct nf_ct_event_notifier *notify;
struct nf_conntrack_ecache *e;
rcu_read_lock();
notify = rcu_dereference(net->ct.nf_conntrack_event_cb);
if (notify == NULL)
goto out_unlock;
e = nf_ct_ecache_find(ct);
if (e == NULL)
goto out_unlock;
events = xchg(&e->cache, 0);
if (nf_ct_is_confirmed(ct) && !nf_ct_is_dying(ct) && events) {
struct nf_ct_event item = {
.ct = ct,
.pid = 0,
.report = 0
};
int ret;
unsigned long missed = e->missed;
if (!((events | missed) & e->ctmask))
goto out_unlock;
ret = notify->fcn(events | missed, &item);
if (unlikely(ret < 0 || missed)) {
spin_lock_bh(&ct->lock);
if (ret < 0)
e->missed |= events;
else
e->missed &= ~missed;
spin_unlock_bh(&ct->lock);
}
}
out_unlock:
rcu_read_unlock();
}
int nf_conntrack_register_notifier(struct net *net,
struct nf_ct_event_notifier *new)
{
int ret = 0;
struct nf_ct_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_conntrack_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
if (notify != NULL) {
ret = -EBUSY;
goto out_unlock;
}
rcu_assign_pointer(net->ct.nf_conntrack_event_cb, new);
mutex_unlock(&nf_ct_ecache_mutex);
return ret;
out_unlock:
mutex_unlock(&nf_ct_ecache_mutex);
return ret;
}
void nf_conntrack_unregister_notifier(struct net *net,
struct nf_ct_event_notifier *new)
{
struct nf_ct_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_conntrack_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
BUG_ON(notify != new);
RCU_INIT_POINTER(net->ct.nf_conntrack_event_cb, NULL);
mutex_unlock(&nf_ct_ecache_mutex);
}
int nf_ct_expect_register_notifier(struct net *net,
struct nf_exp_event_notifier *new)
{
int ret = 0;
struct nf_exp_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_expect_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
if (notify != NULL) {
ret = -EBUSY;
goto out_unlock;
}
rcu_assign_pointer(net->ct.nf_expect_event_cb, new);
mutex_unlock(&nf_ct_ecache_mutex);
return ret;
out_unlock:
mutex_unlock(&nf_ct_ecache_mutex);
return ret;
}
void nf_ct_expect_unregister_notifier(struct net *net,
struct nf_exp_event_notifier *new)
{
struct nf_exp_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_expect_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
BUG_ON(notify != new);
RCU_INIT_POINTER(net->ct.nf_expect_event_cb, NULL);
mutex_unlock(&nf_ct_ecache_mutex);
}
static int nf_conntrack_event_init_sysctl(struct net *net)
{
struct ctl_table *table;
table = kmemdup(event_sysctl_table, sizeof(event_sysctl_table),
GFP_KERNEL);
if (!table)
goto out;
table[0].data = &net->ct.sysctl_events;
table[1].data = &net->ct.sysctl_events_retry_timeout;
net->ct.event_sysctl_header =
register_net_sysctl_table(net,
nf_net_netfilter_sysctl_path, table);
if (!net->ct.event_sysctl_header) {
printk(KERN_ERR "nf_ct_event: can't register to sysctl.\n");
goto out_register;
}
return 0;
out_register:
kfree(table);
out:
return -ENOMEM;
}
static void nf_conntrack_event_fini_sysctl(struct net *net)
{
struct ctl_table *table;
table = net->ct.event_sysctl_header->ctl_table_arg;
unregister_net_sysctl_table(net->ct.event_sysctl_header);
kfree(table);
}
static int nf_conntrack_event_init_sysctl(struct net *net)
{
return 0;
}
static void nf_conntrack_event_fini_sysctl(struct net *net)
{
}
int nf_conntrack_ecache_init(struct net *net)
{
int ret;
net->ct.sysctl_events = nf_ct_events;
net->ct.sysctl_events_retry_timeout = nf_ct_events_retry_timeout;
if (net_eq(net, &init_net)) {
ret = nf_ct_extend_register(&event_extend);
if (ret < 0) {
printk(KERN_ERR "nf_ct_event: Unable to register "
"event extension.\n");
goto out_extend_register;
}
}
ret = nf_conntrack_event_init_sysctl(net);
if (ret < 0)
goto out_sysctl;
return 0;
out_sysctl:
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&event_extend);
out_extend_register:
return ret;
}
void nf_conntrack_ecache_fini(struct net *net)
{
nf_conntrack_event_fini_sysctl(net);
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&event_extend);
}
