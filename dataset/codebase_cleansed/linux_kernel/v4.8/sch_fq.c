static void fq_flow_set_detached(struct fq_flow *f)
{
f->next = &detached;
f->age = jiffies;
}
static bool fq_flow_is_detached(const struct fq_flow *f)
{
return f->next == &detached;
}
static void fq_flow_set_throttled(struct fq_sched_data *q, struct fq_flow *f)
{
struct rb_node **p = &q->delayed.rb_node, *parent = NULL;
while (*p) {
struct fq_flow *aux;
parent = *p;
aux = container_of(parent, struct fq_flow, rate_node);
if (f->time_next_packet >= aux->time_next_packet)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&f->rate_node, parent, p);
rb_insert_color(&f->rate_node, &q->delayed);
q->throttled_flows++;
q->stat_throttled++;
f->next = &throttled;
if (q->time_next_delayed_flow > f->time_next_packet)
q->time_next_delayed_flow = f->time_next_packet;
}
static void fq_flow_add_tail(struct fq_flow_head *head, struct fq_flow *flow)
{
if (head->first)
head->last->next = flow;
else
head->first = flow;
head->last = flow;
flow->next = NULL;
}
static bool fq_gc_candidate(const struct fq_flow *f)
{
return fq_flow_is_detached(f) &&
time_after(jiffies, f->age + FQ_GC_AGE);
}
static void fq_gc(struct fq_sched_data *q,
struct rb_root *root,
struct sock *sk)
{
struct fq_flow *f, *tofree[FQ_GC_MAX];
struct rb_node **p, *parent;
int fcnt = 0;
p = &root->rb_node;
parent = NULL;
while (*p) {
parent = *p;
f = container_of(parent, struct fq_flow, fq_node);
if (f->sk == sk)
break;
if (fq_gc_candidate(f)) {
tofree[fcnt++] = f;
if (fcnt == FQ_GC_MAX)
break;
}
if (f->sk > sk)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
q->flows -= fcnt;
q->inactive_flows -= fcnt;
q->stat_gc_flows += fcnt;
while (fcnt) {
struct fq_flow *f = tofree[--fcnt];
rb_erase(&f->fq_node, root);
kmem_cache_free(fq_flow_cachep, f);
}
}
static struct fq_flow *fq_classify(struct sk_buff *skb, struct fq_sched_data *q)
{
struct rb_node **p, *parent;
struct sock *sk = skb->sk;
struct rb_root *root;
struct fq_flow *f;
if (unlikely((skb->priority & TC_PRIO_MAX) == TC_PRIO_CONTROL))
return &q->internal;
if (!sk || sk_listener(sk)) {
unsigned long hash = skb_get_hash(skb) & q->orphan_mask;
sk = (struct sock *)((hash << 1) | 1UL);
skb_orphan(skb);
}
root = &q->fq_root[hash_32((u32)(long)sk, q->fq_trees_log)];
if (q->flows >= (2U << q->fq_trees_log) &&
q->inactive_flows > q->flows/2)
fq_gc(q, root, sk);
p = &root->rb_node;
parent = NULL;
while (*p) {
parent = *p;
f = container_of(parent, struct fq_flow, fq_node);
if (f->sk == sk) {
if (unlikely(skb->sk &&
f->socket_hash != sk->sk_hash)) {
f->credit = q->initial_quantum;
f->socket_hash = sk->sk_hash;
f->time_next_packet = 0ULL;
}
return f;
}
if (f->sk > sk)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
f = kmem_cache_zalloc(fq_flow_cachep, GFP_ATOMIC | __GFP_NOWARN);
if (unlikely(!f)) {
q->stat_allocation_errors++;
return &q->internal;
}
fq_flow_set_detached(f);
f->sk = sk;
if (skb->sk)
f->socket_hash = sk->sk_hash;
f->credit = q->initial_quantum;
rb_link_node(&f->fq_node, parent, p);
rb_insert_color(&f->fq_node, root);
q->flows++;
q->inactive_flows++;
return f;
}
static struct sk_buff *fq_dequeue_head(struct Qdisc *sch, struct fq_flow *flow)
{
struct sk_buff *skb = flow->head;
if (skb) {
flow->head = skb->next;
skb->next = NULL;
flow->qlen--;
qdisc_qstats_backlog_dec(sch, skb);
sch->q.qlen--;
}
return skb;
}
static bool skb_is_retransmit(struct sk_buff *skb)
{
return false;
}
static void flow_queue_add(struct fq_flow *flow, struct sk_buff *skb)
{
struct sk_buff *prev, *head = flow->head;
skb->next = NULL;
if (!head) {
flow->head = skb;
flow->tail = skb;
return;
}
if (likely(!skb_is_retransmit(skb))) {
flow->tail->next = skb;
flow->tail = skb;
return;
}
prev = NULL;
while (skb_is_retransmit(head)) {
prev = head;
head = head->next;
if (!head)
break;
}
if (!prev) {
skb->next = flow->head;
flow->head = skb;
} else {
if (prev == flow->tail)
flow->tail = skb;
else
skb->next = prev->next;
prev->next = skb;
}
}
static int fq_enqueue(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
struct fq_sched_data *q = qdisc_priv(sch);
struct fq_flow *f;
if (unlikely(sch->q.qlen >= sch->limit))
return qdisc_drop(skb, sch, to_free);
f = fq_classify(skb, q);
if (unlikely(f->qlen >= q->flow_plimit && f != &q->internal)) {
q->stat_flows_plimit++;
return qdisc_drop(skb, sch, to_free);
}
f->qlen++;
if (skb_is_retransmit(skb))
q->stat_tcp_retrans++;
qdisc_qstats_backlog_inc(sch, skb);
if (fq_flow_is_detached(f)) {
fq_flow_add_tail(&q->new_flows, f);
if (time_after(jiffies, f->age + q->flow_refill_delay))
f->credit = max_t(u32, f->credit, q->quantum);
q->inactive_flows--;
}
flow_queue_add(f, skb);
if (unlikely(f == &q->internal)) {
q->stat_internal_packets++;
}
sch->q.qlen++;
return NET_XMIT_SUCCESS;
}
static void fq_check_throttled(struct fq_sched_data *q, u64 now)
{
struct rb_node *p;
if (q->time_next_delayed_flow > now)
return;
q->time_next_delayed_flow = ~0ULL;
while ((p = rb_first(&q->delayed)) != NULL) {
struct fq_flow *f = container_of(p, struct fq_flow, rate_node);
if (f->time_next_packet > now) {
q->time_next_delayed_flow = f->time_next_packet;
break;
}
rb_erase(p, &q->delayed);
q->throttled_flows--;
fq_flow_add_tail(&q->old_flows, f);
}
}
static struct sk_buff *fq_dequeue(struct Qdisc *sch)
{
struct fq_sched_data *q = qdisc_priv(sch);
u64 now = ktime_get_ns();
struct fq_flow_head *head;
struct sk_buff *skb;
struct fq_flow *f;
u32 rate;
skb = fq_dequeue_head(sch, &q->internal);
if (skb)
goto out;
fq_check_throttled(q, now);
begin:
head = &q->new_flows;
if (!head->first) {
head = &q->old_flows;
if (!head->first) {
if (q->time_next_delayed_flow != ~0ULL)
qdisc_watchdog_schedule_ns(&q->watchdog,
q->time_next_delayed_flow);
return NULL;
}
}
f = head->first;
if (f->credit <= 0) {
f->credit += q->quantum;
head->first = f->next;
fq_flow_add_tail(&q->old_flows, f);
goto begin;
}
skb = f->head;
if (unlikely(skb && now < f->time_next_packet &&
!skb_is_tcp_pure_ack(skb))) {
head->first = f->next;
fq_flow_set_throttled(q, f);
goto begin;
}
skb = fq_dequeue_head(sch, f);
if (!skb) {
head->first = f->next;
if ((head == &q->new_flows) && q->old_flows.first) {
fq_flow_add_tail(&q->old_flows, f);
} else {
fq_flow_set_detached(f);
q->inactive_flows++;
}
goto begin;
}
prefetch(&skb->end);
f->credit -= qdisc_pkt_len(skb);
if (f->credit > 0 || !q->rate_enable)
goto out;
if (skb_is_tcp_pure_ack(skb))
goto out;
rate = q->flow_max_rate;
if (skb->sk)
rate = min(skb->sk->sk_pacing_rate, rate);
if (rate != ~0U) {
u32 plen = max(qdisc_pkt_len(skb), q->quantum);
u64 len = (u64)plen * NSEC_PER_SEC;
if (likely(rate))
do_div(len, rate);
if (unlikely(len > NSEC_PER_SEC)) {
len = NSEC_PER_SEC;
q->stat_pkts_too_long++;
}
f->time_next_packet = now + len;
}
out:
qdisc_bstats_update(sch, skb);
return skb;
}
static void fq_flow_purge(struct fq_flow *flow)
{
rtnl_kfree_skbs(flow->head, flow->tail);
flow->head = NULL;
flow->qlen = 0;
}
static void fq_reset(struct Qdisc *sch)
{
struct fq_sched_data *q = qdisc_priv(sch);
struct rb_root *root;
struct rb_node *p;
struct fq_flow *f;
unsigned int idx;
sch->q.qlen = 0;
sch->qstats.backlog = 0;
fq_flow_purge(&q->internal);
if (!q->fq_root)
return;
for (idx = 0; idx < (1U << q->fq_trees_log); idx++) {
root = &q->fq_root[idx];
while ((p = rb_first(root)) != NULL) {
f = container_of(p, struct fq_flow, fq_node);
rb_erase(p, root);
fq_flow_purge(f);
kmem_cache_free(fq_flow_cachep, f);
}
}
q->new_flows.first = NULL;
q->old_flows.first = NULL;
q->delayed = RB_ROOT;
q->flows = 0;
q->inactive_flows = 0;
q->throttled_flows = 0;
}
static void fq_rehash(struct fq_sched_data *q,
struct rb_root *old_array, u32 old_log,
struct rb_root *new_array, u32 new_log)
{
struct rb_node *op, **np, *parent;
struct rb_root *oroot, *nroot;
struct fq_flow *of, *nf;
int fcnt = 0;
u32 idx;
for (idx = 0; idx < (1U << old_log); idx++) {
oroot = &old_array[idx];
while ((op = rb_first(oroot)) != NULL) {
rb_erase(op, oroot);
of = container_of(op, struct fq_flow, fq_node);
if (fq_gc_candidate(of)) {
fcnt++;
kmem_cache_free(fq_flow_cachep, of);
continue;
}
nroot = &new_array[hash_32((u32)(long)of->sk, new_log)];
np = &nroot->rb_node;
parent = NULL;
while (*np) {
parent = *np;
nf = container_of(parent, struct fq_flow, fq_node);
BUG_ON(nf->sk == of->sk);
if (nf->sk > of->sk)
np = &parent->rb_right;
else
np = &parent->rb_left;
}
rb_link_node(&of->fq_node, parent, np);
rb_insert_color(&of->fq_node, nroot);
}
}
q->flows -= fcnt;
q->inactive_flows -= fcnt;
q->stat_gc_flows += fcnt;
}
static void *fq_alloc_node(size_t sz, int node)
{
void *ptr;
ptr = kmalloc_node(sz, GFP_KERNEL | __GFP_REPEAT | __GFP_NOWARN, node);
if (!ptr)
ptr = vmalloc_node(sz, node);
return ptr;
}
static void fq_free(void *addr)
{
kvfree(addr);
}
static int fq_resize(struct Qdisc *sch, u32 log)
{
struct fq_sched_data *q = qdisc_priv(sch);
struct rb_root *array;
void *old_fq_root;
u32 idx;
if (q->fq_root && log == q->fq_trees_log)
return 0;
array = fq_alloc_node(sizeof(struct rb_root) << log,
netdev_queue_numa_node_read(sch->dev_queue));
if (!array)
return -ENOMEM;
for (idx = 0; idx < (1U << log); idx++)
array[idx] = RB_ROOT;
sch_tree_lock(sch);
old_fq_root = q->fq_root;
if (old_fq_root)
fq_rehash(q, old_fq_root, q->fq_trees_log, array, log);
q->fq_root = array;
q->fq_trees_log = log;
sch_tree_unlock(sch);
fq_free(old_fq_root);
return 0;
}
static int fq_change(struct Qdisc *sch, struct nlattr *opt)
{
struct fq_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_FQ_MAX + 1];
int err, drop_count = 0;
unsigned drop_len = 0;
u32 fq_log;
if (!opt)
return -EINVAL;
err = nla_parse_nested(tb, TCA_FQ_MAX, opt, fq_policy);
if (err < 0)
return err;
sch_tree_lock(sch);
fq_log = q->fq_trees_log;
if (tb[TCA_FQ_BUCKETS_LOG]) {
u32 nval = nla_get_u32(tb[TCA_FQ_BUCKETS_LOG]);
if (nval >= 1 && nval <= ilog2(256*1024))
fq_log = nval;
else
err = -EINVAL;
}
if (tb[TCA_FQ_PLIMIT])
sch->limit = nla_get_u32(tb[TCA_FQ_PLIMIT]);
if (tb[TCA_FQ_FLOW_PLIMIT])
q->flow_plimit = nla_get_u32(tb[TCA_FQ_FLOW_PLIMIT]);
if (tb[TCA_FQ_QUANTUM]) {
u32 quantum = nla_get_u32(tb[TCA_FQ_QUANTUM]);
if (quantum > 0)
q->quantum = quantum;
else
err = -EINVAL;
}
if (tb[TCA_FQ_INITIAL_QUANTUM])
q->initial_quantum = nla_get_u32(tb[TCA_FQ_INITIAL_QUANTUM]);
if (tb[TCA_FQ_FLOW_DEFAULT_RATE])
pr_warn_ratelimited("sch_fq: defrate %u ignored.\n",
nla_get_u32(tb[TCA_FQ_FLOW_DEFAULT_RATE]));
if (tb[TCA_FQ_FLOW_MAX_RATE])
q->flow_max_rate = nla_get_u32(tb[TCA_FQ_FLOW_MAX_RATE]);
if (tb[TCA_FQ_RATE_ENABLE]) {
u32 enable = nla_get_u32(tb[TCA_FQ_RATE_ENABLE]);
if (enable <= 1)
q->rate_enable = enable;
else
err = -EINVAL;
}
if (tb[TCA_FQ_FLOW_REFILL_DELAY]) {
u32 usecs_delay = nla_get_u32(tb[TCA_FQ_FLOW_REFILL_DELAY]) ;
q->flow_refill_delay = usecs_to_jiffies(usecs_delay);
}
if (tb[TCA_FQ_ORPHAN_MASK])
q->orphan_mask = nla_get_u32(tb[TCA_FQ_ORPHAN_MASK]);
if (!err) {
sch_tree_unlock(sch);
err = fq_resize(sch, fq_log);
sch_tree_lock(sch);
}
while (sch->q.qlen > sch->limit) {
struct sk_buff *skb = fq_dequeue(sch);
if (!skb)
break;
drop_len += qdisc_pkt_len(skb);
rtnl_kfree_skbs(skb, skb);
drop_count++;
}
qdisc_tree_reduce_backlog(sch, drop_count, drop_len);
sch_tree_unlock(sch);
return err;
}
static void fq_destroy(struct Qdisc *sch)
{
struct fq_sched_data *q = qdisc_priv(sch);
fq_reset(sch);
fq_free(q->fq_root);
qdisc_watchdog_cancel(&q->watchdog);
}
static int fq_init(struct Qdisc *sch, struct nlattr *opt)
{
struct fq_sched_data *q = qdisc_priv(sch);
int err;
sch->limit = 10000;
q->flow_plimit = 100;
q->quantum = 2 * psched_mtu(qdisc_dev(sch));
q->initial_quantum = 10 * psched_mtu(qdisc_dev(sch));
q->flow_refill_delay = msecs_to_jiffies(40);
q->flow_max_rate = ~0U;
q->rate_enable = 1;
q->new_flows.first = NULL;
q->old_flows.first = NULL;
q->delayed = RB_ROOT;
q->fq_root = NULL;
q->fq_trees_log = ilog2(1024);
q->orphan_mask = 1024 - 1;
qdisc_watchdog_init(&q->watchdog, sch);
if (opt)
err = fq_change(sch, opt);
else
err = fq_resize(sch, q->fq_trees_log);
return err;
}
static int fq_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct fq_sched_data *q = qdisc_priv(sch);
struct nlattr *opts;
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, TCA_FQ_PLIMIT, sch->limit) ||
nla_put_u32(skb, TCA_FQ_FLOW_PLIMIT, q->flow_plimit) ||
nla_put_u32(skb, TCA_FQ_QUANTUM, q->quantum) ||
nla_put_u32(skb, TCA_FQ_INITIAL_QUANTUM, q->initial_quantum) ||
nla_put_u32(skb, TCA_FQ_RATE_ENABLE, q->rate_enable) ||
nla_put_u32(skb, TCA_FQ_FLOW_MAX_RATE, q->flow_max_rate) ||
nla_put_u32(skb, TCA_FQ_FLOW_REFILL_DELAY,
jiffies_to_usecs(q->flow_refill_delay)) ||
nla_put_u32(skb, TCA_FQ_ORPHAN_MASK, q->orphan_mask) ||
nla_put_u32(skb, TCA_FQ_BUCKETS_LOG, q->fq_trees_log))
goto nla_put_failure;
return nla_nest_end(skb, opts);
nla_put_failure:
return -1;
}
static int fq_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct fq_sched_data *q = qdisc_priv(sch);
u64 now = ktime_get_ns();
struct tc_fq_qd_stats st = {
.gc_flows = q->stat_gc_flows,
.highprio_packets = q->stat_internal_packets,
.tcp_retrans = q->stat_tcp_retrans,
.throttled = q->stat_throttled,
.flows_plimit = q->stat_flows_plimit,
.pkts_too_long = q->stat_pkts_too_long,
.allocation_errors = q->stat_allocation_errors,
.flows = q->flows,
.inactive_flows = q->inactive_flows,
.throttled_flows = q->throttled_flows,
.time_next_delayed_flow = q->time_next_delayed_flow - now,
};
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static int __init fq_module_init(void)
{
int ret;
fq_flow_cachep = kmem_cache_create("fq_flow_cache",
sizeof(struct fq_flow),
0, 0, NULL);
if (!fq_flow_cachep)
return -ENOMEM;
ret = register_qdisc(&fq_qdisc_ops);
if (ret)
kmem_cache_destroy(fq_flow_cachep);
return ret;
}
static void __exit fq_module_exit(void)
{
unregister_qdisc(&fq_qdisc_ops);
kmem_cache_destroy(fq_flow_cachep);
}
