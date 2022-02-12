static enum retry_state ecache_work_evict_list(struct ct_pcpu *pcpu)
{
struct nf_conn *refs[16];
struct nf_conntrack_tuple_hash *h;
struct hlist_nulls_node *n;
unsigned int evicted = 0;
enum retry_state ret = STATE_DONE;
spin_lock(&pcpu->lock);
hlist_nulls_for_each_entry(h, n, &pcpu->dying, hnnode) {
struct nf_conn *ct = nf_ct_tuplehash_to_ctrack(h);
struct nf_conntrack_ecache *e;
if (!nf_ct_is_confirmed(ct))
continue;
e = nf_ct_ecache_find(ct);
if (!e || e->state != NFCT_ECACHE_DESTROY_FAIL)
continue;
if (nf_conntrack_event(IPCT_DESTROY, ct)) {
ret = STATE_CONGESTED;
break;
}
e->state = NFCT_ECACHE_DESTROY_SENT;
refs[evicted] = ct;
if (++evicted >= ARRAY_SIZE(refs)) {
ret = STATE_RESTART;
break;
}
}
spin_unlock(&pcpu->lock);
while (evicted)
nf_ct_put(refs[--evicted]);
return ret;
}
static void ecache_work(struct work_struct *work)
{
struct netns_ct *ctnet =
container_of(work, struct netns_ct, ecache_dwork.work);
int cpu, delay = -1;
struct ct_pcpu *pcpu;
local_bh_disable();
for_each_possible_cpu(cpu) {
enum retry_state ret;
pcpu = per_cpu_ptr(ctnet->pcpu_lists, cpu);
ret = ecache_work_evict_list(pcpu);
switch (ret) {
case STATE_CONGESTED:
delay = ECACHE_RETRY_WAIT;
goto out;
case STATE_RESTART:
delay = 0;
break;
case STATE_DONE:
break;
}
}
out:
local_bh_enable();
ctnet->ecache_dwork_pending = delay > 0;
if (delay >= 0)
schedule_delayed_work(&ctnet->ecache_dwork, delay);
}
int nf_conntrack_eventmask_report(unsigned int eventmask, struct nf_conn *ct,
u32 portid, int report)
{
int ret = 0;
struct net *net = nf_ct_net(ct);
struct nf_ct_event_notifier *notify;
struct nf_conntrack_ecache *e;
rcu_read_lock();
notify = rcu_dereference(net->ct.nf_conntrack_event_cb);
if (!notify)
goto out_unlock;
e = nf_ct_ecache_find(ct);
if (!e)
goto out_unlock;
if (nf_ct_is_confirmed(ct)) {
struct nf_ct_event item = {
.ct = ct,
.portid = e->portid ? e->portid : portid,
.report = report
};
unsigned long missed = e->portid ? 0 : e->missed;
if (!((eventmask | missed) & e->ctmask))
goto out_unlock;
ret = notify->fcn(eventmask | missed, &item);
if (unlikely(ret < 0 || missed)) {
spin_lock_bh(&ct->lock);
if (ret < 0) {
if (eventmask & (1 << IPCT_DESTROY)) {
if (e->portid == 0 && portid != 0)
e->portid = portid;
e->state = NFCT_ECACHE_DESTROY_FAIL;
} else {
e->missed |= eventmask;
}
} else {
e->missed &= ~missed;
}
spin_unlock_bh(&ct->lock);
}
}
out_unlock:
rcu_read_unlock();
return ret;
}
void nf_ct_deliver_cached_events(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
unsigned long events, missed;
struct nf_ct_event_notifier *notify;
struct nf_conntrack_ecache *e;
struct nf_ct_event item;
int ret;
rcu_read_lock();
notify = rcu_dereference(net->ct.nf_conntrack_event_cb);
if (notify == NULL)
goto out_unlock;
e = nf_ct_ecache_find(ct);
if (e == NULL)
goto out_unlock;
events = xchg(&e->cache, 0);
if (!nf_ct_is_confirmed(ct) || nf_ct_is_dying(ct) || !events)
goto out_unlock;
missed = e->missed;
if (!((events | missed) & e->ctmask))
goto out_unlock;
item.ct = ct;
item.portid = 0;
item.report = 0;
ret = notify->fcn(events | missed, &item);
if (likely(ret >= 0 && !missed))
goto out_unlock;
spin_lock_bh(&ct->lock);
if (ret < 0)
e->missed |= events;
else
e->missed &= ~missed;
spin_unlock_bh(&ct->lock);
out_unlock:
rcu_read_unlock();
}
void nf_ct_expect_event_report(enum ip_conntrack_expect_events event,
struct nf_conntrack_expect *exp,
u32 portid, int report)
{
struct net *net = nf_ct_exp_net(exp);
struct nf_exp_event_notifier *notify;
struct nf_conntrack_ecache *e;
rcu_read_lock();
notify = rcu_dereference(net->ct.nf_expect_event_cb);
if (!notify)
goto out_unlock;
e = nf_ct_ecache_find(exp->master);
if (!e)
goto out_unlock;
if (e->expmask & (1 << event)) {
struct nf_exp_event item = {
.exp = exp,
.portid = portid,
.report = report
};
notify->fcn(1 << event, &item);
}
out_unlock:
rcu_read_unlock();
}
int nf_conntrack_register_notifier(struct net *net,
struct nf_ct_event_notifier *new)
{
int ret;
struct nf_ct_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_conntrack_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
if (notify != NULL) {
ret = -EBUSY;
goto out_unlock;
}
rcu_assign_pointer(net->ct.nf_conntrack_event_cb, new);
ret = 0;
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
int ret;
struct nf_exp_event_notifier *notify;
mutex_lock(&nf_ct_ecache_mutex);
notify = rcu_dereference_protected(net->ct.nf_expect_event_cb,
lockdep_is_held(&nf_ct_ecache_mutex));
if (notify != NULL) {
ret = -EBUSY;
goto out_unlock;
}
rcu_assign_pointer(net->ct.nf_expect_event_cb, new);
ret = 0;
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
if (net->user_ns != &init_user_ns)
table[0].procname = NULL;
net->ct.event_sysctl_header =
register_net_sysctl(net, "net/netfilter", table);
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
int nf_conntrack_ecache_pernet_init(struct net *net)
{
net->ct.sysctl_events = nf_ct_events;
INIT_DELAYED_WORK(&net->ct.ecache_dwork, ecache_work);
return nf_conntrack_event_init_sysctl(net);
}
void nf_conntrack_ecache_pernet_fini(struct net *net)
{
cancel_delayed_work_sync(&net->ct.ecache_dwork);
nf_conntrack_event_fini_sysctl(net);
}
int nf_conntrack_ecache_init(void)
{
int ret = nf_ct_extend_register(&event_extend);
if (ret < 0)
pr_err("nf_ct_event: Unable to register event extension.\n");
return ret;
}
void nf_conntrack_ecache_fini(void)
{
nf_ct_extend_unregister(&event_extend);
}
