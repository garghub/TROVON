static inline struct htb_class *htb_find(u32 handle, struct Qdisc *sch)
{
struct htb_sched *q = qdisc_priv(sch);
struct Qdisc_class_common *clc;
clc = qdisc_class_find(&q->clhash, handle);
if (clc == NULL)
return NULL;
return container_of(clc, struct htb_class, common);
}
static struct htb_class *htb_classify(struct sk_buff *skb, struct Qdisc *sch,
int *qerr)
{
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl;
struct tcf_result res;
struct tcf_proto *tcf;
int result;
if (skb->priority == sch->handle)
return HTB_DIRECT;
cl = htb_find(skb->priority, sch);
if (cl) {
if (cl->level == 0)
return cl;
tcf = cl->filter_list;
} else {
tcf = q->filter_list;
}
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
while (tcf && (result = tc_classify(skb, tcf, &res)) >= 0) {
#ifdef CONFIG_NET_CLS_ACT
switch (result) {
case TC_ACT_QUEUED:
case TC_ACT_STOLEN:
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_STOLEN;
case TC_ACT_SHOT:
return NULL;
}
#endif
cl = (void *)res.class;
if (!cl) {
if (res.classid == sch->handle)
return HTB_DIRECT;
cl = htb_find(res.classid, sch);
if (!cl)
break;
}
if (!cl->level)
return cl;
tcf = cl->filter_list;
}
cl = htb_find(TC_H_MAKE(TC_H_MAJ(sch->handle), q->defcls), sch);
if (!cl || cl->level)
return HTB_DIRECT;
return cl;
}
static void htb_add_to_id_tree(struct rb_root *root,
struct htb_class *cl, int prio)
{
struct rb_node **p = &root->rb_node, *parent = NULL;
while (*p) {
struct htb_class *c;
parent = *p;
c = rb_entry(parent, struct htb_class, node[prio]);
if (cl->common.classid > c->common.classid)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&cl->node[prio], parent, p);
rb_insert_color(&cl->node[prio], root);
}
static void htb_add_to_wait_tree(struct htb_sched *q,
struct htb_class *cl, s64 delay)
{
struct rb_node **p = &q->hlevel[cl->level].wait_pq.rb_node, *parent = NULL;
cl->pq_key = q->now + delay;
if (cl->pq_key == q->now)
cl->pq_key++;
if (q->near_ev_cache[cl->level] > cl->pq_key)
q->near_ev_cache[cl->level] = cl->pq_key;
while (*p) {
struct htb_class *c;
parent = *p;
c = rb_entry(parent, struct htb_class, pq_node);
if (cl->pq_key >= c->pq_key)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&cl->pq_node, parent, p);
rb_insert_color(&cl->pq_node, &q->hlevel[cl->level].wait_pq);
}
static inline void htb_next_rb_node(struct rb_node **n)
{
*n = rb_next(*n);
}
static inline void htb_add_class_to_row(struct htb_sched *q,
struct htb_class *cl, int mask)
{
q->row_mask[cl->level] |= mask;
while (mask) {
int prio = ffz(~mask);
mask &= ~(1 << prio);
htb_add_to_id_tree(&q->hlevel[cl->level].hprio[prio].row, cl, prio);
}
}
static void htb_safe_rb_erase(struct rb_node *rb, struct rb_root *root)
{
if (RB_EMPTY_NODE(rb)) {
WARN_ON(1);
} else {
rb_erase(rb, root);
RB_CLEAR_NODE(rb);
}
}
static inline void htb_remove_class_from_row(struct htb_sched *q,
struct htb_class *cl, int mask)
{
int m = 0;
struct htb_level *hlevel = &q->hlevel[cl->level];
while (mask) {
int prio = ffz(~mask);
struct htb_prio *hprio = &hlevel->hprio[prio];
mask &= ~(1 << prio);
if (hprio->ptr == cl->node + prio)
htb_next_rb_node(&hprio->ptr);
htb_safe_rb_erase(cl->node + prio, &hprio->row);
if (!hprio->row.rb_node)
m |= 1 << prio;
}
q->row_mask[cl->level] &= ~m;
}
static void htb_activate_prios(struct htb_sched *q, struct htb_class *cl)
{
struct htb_class *p = cl->parent;
long m, mask = cl->prio_activity;
while (cl->cmode == HTB_MAY_BORROW && p && mask) {
m = mask;
while (m) {
int prio = ffz(~m);
m &= ~(1 << prio);
if (p->un.inner.clprio[prio].feed.rb_node)
mask &= ~(1 << prio);
htb_add_to_id_tree(&p->un.inner.clprio[prio].feed, cl, prio);
}
p->prio_activity |= mask;
cl = p;
p = cl->parent;
}
if (cl->cmode == HTB_CAN_SEND && mask)
htb_add_class_to_row(q, cl, mask);
}
static void htb_deactivate_prios(struct htb_sched *q, struct htb_class *cl)
{
struct htb_class *p = cl->parent;
long m, mask = cl->prio_activity;
while (cl->cmode == HTB_MAY_BORROW && p && mask) {
m = mask;
mask = 0;
while (m) {
int prio = ffz(~m);
m &= ~(1 << prio);
if (p->un.inner.clprio[prio].ptr == cl->node + prio) {
p->un.inner.clprio[prio].last_ptr_id = cl->common.classid;
p->un.inner.clprio[prio].ptr = NULL;
}
htb_safe_rb_erase(cl->node + prio,
&p->un.inner.clprio[prio].feed);
if (!p->un.inner.clprio[prio].feed.rb_node)
mask |= 1 << prio;
}
p->prio_activity &= ~mask;
cl = p;
p = cl->parent;
}
if (cl->cmode == HTB_CAN_SEND && mask)
htb_remove_class_from_row(q, cl, mask);
}
static inline s64 htb_lowater(const struct htb_class *cl)
{
if (htb_hysteresis)
return cl->cmode != HTB_CANT_SEND ? -cl->cbuffer : 0;
else
return 0;
}
static inline s64 htb_hiwater(const struct htb_class *cl)
{
if (htb_hysteresis)
return cl->cmode == HTB_CAN_SEND ? -cl->buffer : 0;
else
return 0;
}
static inline enum htb_cmode
htb_class_mode(struct htb_class *cl, s64 *diff)
{
s64 toks;
if ((toks = (cl->ctokens + *diff)) < htb_lowater(cl)) {
*diff = -toks;
return HTB_CANT_SEND;
}
if ((toks = (cl->tokens + *diff)) >= htb_hiwater(cl))
return HTB_CAN_SEND;
*diff = -toks;
return HTB_MAY_BORROW;
}
static void
htb_change_class_mode(struct htb_sched *q, struct htb_class *cl, s64 *diff)
{
enum htb_cmode new_mode = htb_class_mode(cl, diff);
if (new_mode == cl->cmode)
return;
if (cl->prio_activity) {
if (cl->cmode != HTB_CANT_SEND)
htb_deactivate_prios(q, cl);
cl->cmode = new_mode;
if (new_mode != HTB_CANT_SEND)
htb_activate_prios(q, cl);
} else
cl->cmode = new_mode;
}
static inline void htb_activate(struct htb_sched *q, struct htb_class *cl)
{
WARN_ON(cl->level || !cl->un.leaf.q || !cl->un.leaf.q->q.qlen);
if (!cl->prio_activity) {
cl->prio_activity = 1 << cl->prio;
htb_activate_prios(q, cl);
list_add_tail(&cl->un.leaf.drop_list,
q->drops + cl->prio);
}
}
static inline void htb_deactivate(struct htb_sched *q, struct htb_class *cl)
{
WARN_ON(!cl->prio_activity);
htb_deactivate_prios(q, cl);
cl->prio_activity = 0;
list_del_init(&cl->un.leaf.drop_list);
}
static int htb_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
int uninitialized_var(ret);
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl = htb_classify(skb, sch, &ret);
if (cl == HTB_DIRECT) {
if (q->direct_queue.qlen < q->direct_qlen) {
__skb_queue_tail(&q->direct_queue, skb);
q->direct_pkts++;
} else {
return qdisc_drop(skb, sch);
}
#ifdef CONFIG_NET_CLS_ACT
} else if (!cl) {
if (ret & __NET_XMIT_BYPASS)
sch->qstats.drops++;
kfree_skb(skb);
return ret;
#endif
} else if ((ret = qdisc_enqueue(skb, cl->un.leaf.q)) != NET_XMIT_SUCCESS) {
if (net_xmit_drop_count(ret)) {
sch->qstats.drops++;
cl->qstats.drops++;
}
return ret;
} else {
htb_activate(q, cl);
}
sch->q.qlen++;
return NET_XMIT_SUCCESS;
}
static inline void htb_accnt_tokens(struct htb_class *cl, int bytes, s64 diff)
{
s64 toks = diff + cl->tokens;
if (toks > cl->buffer)
toks = cl->buffer;
toks -= (s64) psched_l2t_ns(&cl->rate, bytes);
if (toks <= -cl->mbuffer)
toks = 1 - cl->mbuffer;
cl->tokens = toks;
}
static inline void htb_accnt_ctokens(struct htb_class *cl, int bytes, s64 diff)
{
s64 toks = diff + cl->ctokens;
if (toks > cl->cbuffer)
toks = cl->cbuffer;
toks -= (s64) psched_l2t_ns(&cl->ceil, bytes);
if (toks <= -cl->mbuffer)
toks = 1 - cl->mbuffer;
cl->ctokens = toks;
}
static void htb_charge_class(struct htb_sched *q, struct htb_class *cl,
int level, struct sk_buff *skb)
{
int bytes = qdisc_pkt_len(skb);
enum htb_cmode old_mode;
s64 diff;
while (cl) {
diff = min_t(s64, q->now - cl->t_c, cl->mbuffer);
if (cl->level >= level) {
if (cl->level == level)
cl->xstats.lends++;
htb_accnt_tokens(cl, bytes, diff);
} else {
cl->xstats.borrows++;
cl->tokens += diff;
}
htb_accnt_ctokens(cl, bytes, diff);
cl->t_c = q->now;
old_mode = cl->cmode;
diff = 0;
htb_change_class_mode(q, cl, &diff);
if (old_mode != cl->cmode) {
if (old_mode != HTB_CAN_SEND)
htb_safe_rb_erase(&cl->pq_node, &q->hlevel[cl->level].wait_pq);
if (cl->cmode != HTB_CAN_SEND)
htb_add_to_wait_tree(q, cl, diff);
}
if (cl->level)
bstats_update(&cl->bstats, skb);
cl = cl->parent;
}
}
static s64 htb_do_events(struct htb_sched *q, const int level,
unsigned long start)
{
unsigned long stop_at = start + 2;
struct rb_root *wait_pq = &q->hlevel[level].wait_pq;
while (time_before(jiffies, stop_at)) {
struct htb_class *cl;
s64 diff;
struct rb_node *p = rb_first(wait_pq);
if (!p)
return 0;
cl = rb_entry(p, struct htb_class, pq_node);
if (cl->pq_key > q->now)
return cl->pq_key;
htb_safe_rb_erase(p, wait_pq);
diff = min_t(s64, q->now - cl->t_c, cl->mbuffer);
htb_change_class_mode(q, cl, &diff);
if (cl->cmode != HTB_CAN_SEND)
htb_add_to_wait_tree(q, cl, diff);
}
if (!(q->warned & HTB_WARN_TOOMANYEVENTS)) {
pr_warn("htb: too many events!\n");
q->warned |= HTB_WARN_TOOMANYEVENTS;
}
return q->now;
}
static struct rb_node *htb_id_find_next_upper(int prio, struct rb_node *n,
u32 id)
{
struct rb_node *r = NULL;
while (n) {
struct htb_class *cl =
rb_entry(n, struct htb_class, node[prio]);
if (id > cl->common.classid) {
n = n->rb_right;
} else if (id < cl->common.classid) {
r = n;
n = n->rb_left;
} else {
return n;
}
}
return r;
}
static struct htb_class *htb_lookup_leaf(struct htb_prio *hprio, const int prio)
{
int i;
struct {
struct rb_node *root;
struct rb_node **pptr;
u32 *pid;
} stk[TC_HTB_MAXDEPTH], *sp = stk;
BUG_ON(!hprio->row.rb_node);
sp->root = hprio->row.rb_node;
sp->pptr = &hprio->ptr;
sp->pid = &hprio->last_ptr_id;
for (i = 0; i < 65535; i++) {
if (!*sp->pptr && *sp->pid) {
*sp->pptr =
htb_id_find_next_upper(prio, sp->root, *sp->pid);
}
*sp->pid = 0;
if (!*sp->pptr) {
*sp->pptr = sp->root;
while ((*sp->pptr)->rb_left)
*sp->pptr = (*sp->pptr)->rb_left;
if (sp > stk) {
sp--;
if (!*sp->pptr) {
WARN_ON(1);
return NULL;
}
htb_next_rb_node(sp->pptr);
}
} else {
struct htb_class *cl;
struct htb_prio *clp;
cl = rb_entry(*sp->pptr, struct htb_class, node[prio]);
if (!cl->level)
return cl;
clp = &cl->un.inner.clprio[prio];
(++sp)->root = clp->feed.rb_node;
sp->pptr = &clp->ptr;
sp->pid = &clp->last_ptr_id;
}
}
WARN_ON(1);
return NULL;
}
static struct sk_buff *htb_dequeue_tree(struct htb_sched *q, const int prio,
const int level)
{
struct sk_buff *skb = NULL;
struct htb_class *cl, *start;
struct htb_level *hlevel = &q->hlevel[level];
struct htb_prio *hprio = &hlevel->hprio[prio];
start = cl = htb_lookup_leaf(hprio, prio);
do {
next:
if (unlikely(!cl))
return NULL;
if (unlikely(cl->un.leaf.q->q.qlen == 0)) {
struct htb_class *next;
htb_deactivate(q, cl);
if ((q->row_mask[level] & (1 << prio)) == 0)
return NULL;
next = htb_lookup_leaf(hprio, prio);
if (cl == start)
start = next;
cl = next;
goto next;
}
skb = cl->un.leaf.q->dequeue(cl->un.leaf.q);
if (likely(skb != NULL))
break;
qdisc_warn_nonwc("htb", cl->un.leaf.q);
htb_next_rb_node(level ? &cl->parent->un.inner.clprio[prio].ptr:
&q->hlevel[0].hprio[prio].ptr);
cl = htb_lookup_leaf(hprio, prio);
} while (cl != start);
if (likely(skb != NULL)) {
bstats_update(&cl->bstats, skb);
cl->un.leaf.deficit[level] -= qdisc_pkt_len(skb);
if (cl->un.leaf.deficit[level] < 0) {
cl->un.leaf.deficit[level] += cl->quantum;
htb_next_rb_node(level ? &cl->parent->un.inner.clprio[prio].ptr :
&q->hlevel[0].hprio[prio].ptr);
}
if (!cl->un.leaf.q->q.qlen)
htb_deactivate(q, cl);
htb_charge_class(q, cl, level, skb);
}
return skb;
}
static struct sk_buff *htb_dequeue(struct Qdisc *sch)
{
struct sk_buff *skb;
struct htb_sched *q = qdisc_priv(sch);
int level;
s64 next_event;
unsigned long start_at;
skb = __skb_dequeue(&q->direct_queue);
if (skb != NULL) {
ok:
qdisc_bstats_update(sch, skb);
qdisc_unthrottled(sch);
sch->q.qlen--;
return skb;
}
if (!sch->q.qlen)
goto fin;
q->now = ktime_to_ns(ktime_get());
start_at = jiffies;
next_event = q->now + 5LLU * NSEC_PER_SEC;
for (level = 0; level < TC_HTB_MAXDEPTH; level++) {
int m;
s64 event = q->near_ev_cache[level];
if (q->now >= event) {
event = htb_do_events(q, level, start_at);
if (!event)
event = q->now + NSEC_PER_SEC;
q->near_ev_cache[level] = event;
}
if (next_event > event)
next_event = event;
m = ~q->row_mask[level];
while (m != (int)(-1)) {
int prio = ffz(m);
m |= 1 << prio;
skb = htb_dequeue_tree(q, prio, level);
if (likely(skb != NULL))
goto ok;
}
}
sch->qstats.overlimits++;
if (likely(next_event > q->now)) {
if (!test_bit(__QDISC_STATE_DEACTIVATED,
&qdisc_root_sleeping(q->watchdog.qdisc)->state)) {
ktime_t time = ns_to_ktime(next_event);
qdisc_throttled(q->watchdog.qdisc);
hrtimer_start(&q->watchdog.timer, time,
HRTIMER_MODE_ABS);
}
} else {
schedule_work(&q->work);
}
fin:
return skb;
}
static unsigned int htb_drop(struct Qdisc *sch)
{
struct htb_sched *q = qdisc_priv(sch);
int prio;
for (prio = TC_HTB_NUMPRIO - 1; prio >= 0; prio--) {
struct list_head *p;
list_for_each(p, q->drops + prio) {
struct htb_class *cl = list_entry(p, struct htb_class,
un.leaf.drop_list);
unsigned int len;
if (cl->un.leaf.q->ops->drop &&
(len = cl->un.leaf.q->ops->drop(cl->un.leaf.q))) {
sch->q.qlen--;
if (!cl->un.leaf.q->q.qlen)
htb_deactivate(q, cl);
return len;
}
}
}
return 0;
}
static void htb_reset(struct Qdisc *sch)
{
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl;
unsigned int i;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], common.hnode) {
if (cl->level)
memset(&cl->un.inner, 0, sizeof(cl->un.inner));
else {
if (cl->un.leaf.q)
qdisc_reset(cl->un.leaf.q);
INIT_LIST_HEAD(&cl->un.leaf.drop_list);
}
cl->prio_activity = 0;
cl->cmode = HTB_CAN_SEND;
}
}
qdisc_watchdog_cancel(&q->watchdog);
__skb_queue_purge(&q->direct_queue);
sch->q.qlen = 0;
memset(q->hlevel, 0, sizeof(q->hlevel));
memset(q->row_mask, 0, sizeof(q->row_mask));
for (i = 0; i < TC_HTB_NUMPRIO; i++)
INIT_LIST_HEAD(q->drops + i);
}
static void htb_work_func(struct work_struct *work)
{
struct htb_sched *q = container_of(work, struct htb_sched, work);
struct Qdisc *sch = q->watchdog.qdisc;
__netif_schedule(qdisc_root(sch));
}
static int htb_init(struct Qdisc *sch, struct nlattr *opt)
{
struct htb_sched *q = qdisc_priv(sch);
struct nlattr *tb[TCA_HTB_MAX + 1];
struct tc_htb_glob *gopt;
int err;
int i;
if (!opt)
return -EINVAL;
err = nla_parse_nested(tb, TCA_HTB_MAX, opt, htb_policy);
if (err < 0)
return err;
if (!tb[TCA_HTB_INIT])
return -EINVAL;
gopt = nla_data(tb[TCA_HTB_INIT]);
if (gopt->version != HTB_VER >> 16)
return -EINVAL;
err = qdisc_class_hash_init(&q->clhash);
if (err < 0)
return err;
for (i = 0; i < TC_HTB_NUMPRIO; i++)
INIT_LIST_HEAD(q->drops + i);
qdisc_watchdog_init(&q->watchdog, sch);
INIT_WORK(&q->work, htb_work_func);
skb_queue_head_init(&q->direct_queue);
if (tb[TCA_HTB_DIRECT_QLEN])
q->direct_qlen = nla_get_u32(tb[TCA_HTB_DIRECT_QLEN]);
else {
q->direct_qlen = qdisc_dev(sch)->tx_queue_len;
if (q->direct_qlen < 2)
q->direct_qlen = 2;
}
if ((q->rate2quantum = gopt->rate2quantum) < 1)
q->rate2quantum = 1;
q->defcls = gopt->defcls;
return 0;
}
static int htb_dump(struct Qdisc *sch, struct sk_buff *skb)
{
spinlock_t *root_lock = qdisc_root_sleeping_lock(sch);
struct htb_sched *q = qdisc_priv(sch);
struct nlattr *nest;
struct tc_htb_glob gopt;
spin_lock_bh(root_lock);
gopt.direct_pkts = q->direct_pkts;
gopt.version = HTB_VER;
gopt.rate2quantum = q->rate2quantum;
gopt.defcls = q->defcls;
gopt.debug = 0;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
if (nla_put(skb, TCA_HTB_INIT, sizeof(gopt), &gopt) ||
nla_put_u32(skb, TCA_HTB_DIRECT_QLEN, q->direct_qlen))
goto nla_put_failure;
nla_nest_end(skb, nest);
spin_unlock_bh(root_lock);
return skb->len;
nla_put_failure:
spin_unlock_bh(root_lock);
nla_nest_cancel(skb, nest);
return -1;
}
static int htb_dump_class(struct Qdisc *sch, unsigned long arg,
struct sk_buff *skb, struct tcmsg *tcm)
{
struct htb_class *cl = (struct htb_class *)arg;
spinlock_t *root_lock = qdisc_root_sleeping_lock(sch);
struct nlattr *nest;
struct tc_htb_opt opt;
spin_lock_bh(root_lock);
tcm->tcm_parent = cl->parent ? cl->parent->common.classid : TC_H_ROOT;
tcm->tcm_handle = cl->common.classid;
if (!cl->level && cl->un.leaf.q)
tcm->tcm_info = cl->un.leaf.q->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
memset(&opt, 0, sizeof(opt));
psched_ratecfg_getrate(&opt.rate, &cl->rate);
opt.buffer = PSCHED_NS2TICKS(cl->buffer);
psched_ratecfg_getrate(&opt.ceil, &cl->ceil);
opt.cbuffer = PSCHED_NS2TICKS(cl->cbuffer);
opt.quantum = cl->quantum;
opt.prio = cl->prio;
opt.level = cl->level;
if (nla_put(skb, TCA_HTB_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
if ((cl->rate.rate_bytes_ps >= (1ULL << 32)) &&
nla_put_u64(skb, TCA_HTB_RATE64, cl->rate.rate_bytes_ps))
goto nla_put_failure;
if ((cl->ceil.rate_bytes_ps >= (1ULL << 32)) &&
nla_put_u64(skb, TCA_HTB_CEIL64, cl->ceil.rate_bytes_ps))
goto nla_put_failure;
nla_nest_end(skb, nest);
spin_unlock_bh(root_lock);
return skb->len;
nla_put_failure:
spin_unlock_bh(root_lock);
nla_nest_cancel(skb, nest);
return -1;
}
static int
htb_dump_class_stats(struct Qdisc *sch, unsigned long arg, struct gnet_dump *d)
{
struct htb_class *cl = (struct htb_class *)arg;
if (!cl->level && cl->un.leaf.q)
cl->qstats.qlen = cl->un.leaf.q->q.qlen;
cl->xstats.tokens = PSCHED_NS2TICKS(cl->tokens);
cl->xstats.ctokens = PSCHED_NS2TICKS(cl->ctokens);
if (gnet_stats_copy_basic(d, &cl->bstats) < 0 ||
gnet_stats_copy_rate_est(d, NULL, &cl->rate_est) < 0 ||
gnet_stats_copy_queue(d, &cl->qstats) < 0)
return -1;
return gnet_stats_copy_app(d, &cl->xstats, sizeof(cl->xstats));
}
static int htb_graft(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct htb_class *cl = (struct htb_class *)arg;
if (cl->level)
return -EINVAL;
if (new == NULL &&
(new = qdisc_create_dflt(sch->dev_queue, &pfifo_qdisc_ops,
cl->common.classid)) == NULL)
return -ENOBUFS;
sch_tree_lock(sch);
*old = cl->un.leaf.q;
cl->un.leaf.q = new;
if (*old != NULL) {
qdisc_tree_decrease_qlen(*old, (*old)->q.qlen);
qdisc_reset(*old);
}
sch_tree_unlock(sch);
return 0;
}
static struct Qdisc *htb_leaf(struct Qdisc *sch, unsigned long arg)
{
struct htb_class *cl = (struct htb_class *)arg;
return !cl->level ? cl->un.leaf.q : NULL;
}
static void htb_qlen_notify(struct Qdisc *sch, unsigned long arg)
{
struct htb_class *cl = (struct htb_class *)arg;
if (cl->un.leaf.q->q.qlen == 0)
htb_deactivate(qdisc_priv(sch), cl);
}
static unsigned long htb_get(struct Qdisc *sch, u32 classid)
{
struct htb_class *cl = htb_find(classid, sch);
if (cl)
cl->refcnt++;
return (unsigned long)cl;
}
static inline int htb_parent_last_child(struct htb_class *cl)
{
if (!cl->parent)
return 0;
if (cl->parent->children > 1)
return 0;
return 1;
}
static void htb_parent_to_leaf(struct htb_sched *q, struct htb_class *cl,
struct Qdisc *new_q)
{
struct htb_class *parent = cl->parent;
WARN_ON(cl->level || !cl->un.leaf.q || cl->prio_activity);
if (parent->cmode != HTB_CAN_SEND)
htb_safe_rb_erase(&parent->pq_node,
&q->hlevel[parent->level].wait_pq);
parent->level = 0;
memset(&parent->un.inner, 0, sizeof(parent->un.inner));
INIT_LIST_HEAD(&parent->un.leaf.drop_list);
parent->un.leaf.q = new_q ? new_q : &noop_qdisc;
parent->tokens = parent->buffer;
parent->ctokens = parent->cbuffer;
parent->t_c = ktime_to_ns(ktime_get());
parent->cmode = HTB_CAN_SEND;
}
static void htb_destroy_class(struct Qdisc *sch, struct htb_class *cl)
{
if (!cl->level) {
WARN_ON(!cl->un.leaf.q);
qdisc_destroy(cl->un.leaf.q);
}
gen_kill_estimator(&cl->bstats, &cl->rate_est);
tcf_destroy_chain(&cl->filter_list);
kfree(cl);
}
static void htb_destroy(struct Qdisc *sch)
{
struct htb_sched *q = qdisc_priv(sch);
struct hlist_node *next;
struct htb_class *cl;
unsigned int i;
cancel_work_sync(&q->work);
qdisc_watchdog_cancel(&q->watchdog);
tcf_destroy_chain(&q->filter_list);
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], common.hnode)
tcf_destroy_chain(&cl->filter_list);
}
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry_safe(cl, next, &q->clhash.hash[i],
common.hnode)
htb_destroy_class(sch, cl);
}
qdisc_class_hash_destroy(&q->clhash);
__skb_queue_purge(&q->direct_queue);
}
static int htb_delete(struct Qdisc *sch, unsigned long arg)
{
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl = (struct htb_class *)arg;
unsigned int qlen;
struct Qdisc *new_q = NULL;
int last_child = 0;
if (cl->children || cl->filter_cnt)
return -EBUSY;
if (!cl->level && htb_parent_last_child(cl)) {
new_q = qdisc_create_dflt(sch->dev_queue, &pfifo_qdisc_ops,
cl->parent->common.classid);
last_child = 1;
}
sch_tree_lock(sch);
if (!cl->level) {
qlen = cl->un.leaf.q->q.qlen;
qdisc_reset(cl->un.leaf.q);
qdisc_tree_decrease_qlen(cl->un.leaf.q, qlen);
}
qdisc_class_hash_remove(&q->clhash, &cl->common);
if (cl->parent)
cl->parent->children--;
if (cl->prio_activity)
htb_deactivate(q, cl);
if (cl->cmode != HTB_CAN_SEND)
htb_safe_rb_erase(&cl->pq_node,
&q->hlevel[cl->level].wait_pq);
if (last_child)
htb_parent_to_leaf(q, cl, new_q);
BUG_ON(--cl->refcnt == 0);
sch_tree_unlock(sch);
return 0;
}
static void htb_put(struct Qdisc *sch, unsigned long arg)
{
struct htb_class *cl = (struct htb_class *)arg;
if (--cl->refcnt == 0)
htb_destroy_class(sch, cl);
}
static int htb_change_class(struct Qdisc *sch, u32 classid,
u32 parentid, struct nlattr **tca,
unsigned long *arg)
{
int err = -EINVAL;
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl = (struct htb_class *)*arg, *parent;
struct nlattr *opt = tca[TCA_OPTIONS];
struct nlattr *tb[TCA_HTB_MAX + 1];
struct tc_htb_opt *hopt;
u64 rate64, ceil64;
if (!opt)
goto failure;
err = nla_parse_nested(tb, TCA_HTB_MAX, opt, htb_policy);
if (err < 0)
goto failure;
err = -EINVAL;
if (tb[TCA_HTB_PARMS] == NULL)
goto failure;
parent = parentid == TC_H_ROOT ? NULL : htb_find(parentid, sch);
hopt = nla_data(tb[TCA_HTB_PARMS]);
if (!hopt->rate.rate || !hopt->ceil.rate)
goto failure;
if (hopt->rate.linklayer == TC_LINKLAYER_UNAWARE)
qdisc_put_rtab(qdisc_get_rtab(&hopt->rate, tb[TCA_HTB_RTAB]));
if (hopt->ceil.linklayer == TC_LINKLAYER_UNAWARE)
qdisc_put_rtab(qdisc_get_rtab(&hopt->ceil, tb[TCA_HTB_CTAB]));
if (!cl) {
struct Qdisc *new_q;
int prio;
struct {
struct nlattr nla;
struct gnet_estimator opt;
} est = {
.nla = {
.nla_len = nla_attr_size(sizeof(est.opt)),
.nla_type = TCA_RATE,
},
.opt = {
.interval = 2,
.ewma_log = 2,
},
};
if (!classid || TC_H_MAJ(classid ^ sch->handle) ||
htb_find(classid, sch))
goto failure;
if (parent && parent->parent && parent->parent->level < 2) {
pr_err("htb: tree is too deep\n");
goto failure;
}
err = -ENOBUFS;
cl = kzalloc(sizeof(*cl), GFP_KERNEL);
if (!cl)
goto failure;
if (htb_rate_est || tca[TCA_RATE]) {
err = gen_new_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE] ? : &est.nla);
if (err) {
kfree(cl);
goto failure;
}
}
cl->refcnt = 1;
cl->children = 0;
INIT_LIST_HEAD(&cl->un.leaf.drop_list);
RB_CLEAR_NODE(&cl->pq_node);
for (prio = 0; prio < TC_HTB_NUMPRIO; prio++)
RB_CLEAR_NODE(&cl->node[prio]);
new_q = qdisc_create_dflt(sch->dev_queue,
&pfifo_qdisc_ops, classid);
sch_tree_lock(sch);
if (parent && !parent->level) {
unsigned int qlen = parent->un.leaf.q->q.qlen;
qdisc_reset(parent->un.leaf.q);
qdisc_tree_decrease_qlen(parent->un.leaf.q, qlen);
qdisc_destroy(parent->un.leaf.q);
if (parent->prio_activity)
htb_deactivate(q, parent);
if (parent->cmode != HTB_CAN_SEND) {
htb_safe_rb_erase(&parent->pq_node, &q->hlevel[0].wait_pq);
parent->cmode = HTB_CAN_SEND;
}
parent->level = (parent->parent ? parent->parent->level
: TC_HTB_MAXDEPTH) - 1;
memset(&parent->un.inner, 0, sizeof(parent->un.inner));
}
cl->un.leaf.q = new_q ? new_q : &noop_qdisc;
cl->common.classid = classid;
cl->parent = parent;
cl->tokens = PSCHED_TICKS2NS(hopt->buffer);
cl->ctokens = PSCHED_TICKS2NS(hopt->cbuffer);
cl->mbuffer = 60ULL * NSEC_PER_SEC;
cl->t_c = ktime_to_ns(ktime_get());
cl->cmode = HTB_CAN_SEND;
qdisc_class_hash_insert(&q->clhash, &cl->common);
if (parent)
parent->children++;
} else {
if (tca[TCA_RATE]) {
err = gen_replace_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE]);
if (err)
return err;
}
sch_tree_lock(sch);
}
rate64 = tb[TCA_HTB_RATE64] ? nla_get_u64(tb[TCA_HTB_RATE64]) : 0;
ceil64 = tb[TCA_HTB_CEIL64] ? nla_get_u64(tb[TCA_HTB_CEIL64]) : 0;
psched_ratecfg_precompute(&cl->rate, &hopt->rate, rate64);
psched_ratecfg_precompute(&cl->ceil, &hopt->ceil, ceil64);
if (!cl->level) {
u64 quantum = cl->rate.rate_bytes_ps;
do_div(quantum, q->rate2quantum);
cl->quantum = min_t(u64, quantum, INT_MAX);
if (!hopt->quantum && cl->quantum < 1000) {
pr_warn("HTB: quantum of class %X is small. Consider r2q change.\n",
cl->common.classid);
cl->quantum = 1000;
}
if (!hopt->quantum && cl->quantum > 200000) {
pr_warn("HTB: quantum of class %X is big. Consider r2q change.\n",
cl->common.classid);
cl->quantum = 200000;
}
if (hopt->quantum)
cl->quantum = hopt->quantum;
if ((cl->prio = hopt->prio) >= TC_HTB_NUMPRIO)
cl->prio = TC_HTB_NUMPRIO - 1;
}
cl->buffer = PSCHED_TICKS2NS(hopt->buffer);
cl->cbuffer = PSCHED_TICKS2NS(hopt->cbuffer);
sch_tree_unlock(sch);
qdisc_class_hash_grow(sch, &q->clhash);
*arg = (unsigned long)cl;
return 0;
failure:
return err;
}
static struct tcf_proto **htb_find_tcf(struct Qdisc *sch, unsigned long arg)
{
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl = (struct htb_class *)arg;
struct tcf_proto **fl = cl ? &cl->filter_list : &q->filter_list;
return fl;
}
static unsigned long htb_bind_filter(struct Qdisc *sch, unsigned long parent,
u32 classid)
{
struct htb_class *cl = htb_find(classid, sch);
if (cl)
cl->filter_cnt++;
return (unsigned long)cl;
}
static void htb_unbind_filter(struct Qdisc *sch, unsigned long arg)
{
struct htb_class *cl = (struct htb_class *)arg;
if (cl)
cl->filter_cnt--;
}
static void htb_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
struct htb_sched *q = qdisc_priv(sch);
struct htb_class *cl;
unsigned int i;
if (arg->stop)
return;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, &q->clhash.hash[i], common.hnode) {
if (arg->count < arg->skip) {
arg->count++;
continue;
}
if (arg->fn(sch, (unsigned long)cl, arg) < 0) {
arg->stop = 1;
return;
}
arg->count++;
}
}
}
static int __init htb_module_init(void)
{
return register_qdisc(&htb_qdisc_ops);
}
static void __exit htb_module_exit(void)
{
unregister_qdisc(&htb_qdisc_ops);
}
