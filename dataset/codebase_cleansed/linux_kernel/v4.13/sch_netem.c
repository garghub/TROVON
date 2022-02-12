static struct sk_buff *netem_rb_to_skb(struct rb_node *rb)
{
return rb_entry(rb, struct sk_buff, rbnode);
}
static inline struct netem_skb_cb *netem_skb_cb(struct sk_buff *skb)
{
qdisc_cb_private_validate(skb, sizeof(struct netem_skb_cb));
return (struct netem_skb_cb *)qdisc_skb_cb(skb)->data;
}
static void init_crandom(struct crndstate *state, unsigned long rho)
{
state->rho = rho;
state->last = prandom_u32();
}
static u32 get_crandom(struct crndstate *state)
{
u64 value, rho;
unsigned long answer;
if (state->rho == 0)
return prandom_u32();
value = prandom_u32();
rho = (u64)state->rho + 1;
answer = (value * ((1ull<<32) - rho) + state->last * rho) >> 32;
state->last = answer;
return answer;
}
static bool loss_4state(struct netem_sched_data *q)
{
struct clgstate *clg = &q->clg;
u32 rnd = prandom_u32();
switch (clg->state) {
case TX_IN_GAP_PERIOD:
if (rnd < clg->a4) {
clg->state = LOST_IN_BURST_PERIOD;
return true;
} else if (clg->a4 < rnd && rnd < clg->a1 + clg->a4) {
clg->state = LOST_IN_GAP_PERIOD;
return true;
} else if (clg->a1 + clg->a4 < rnd) {
clg->state = TX_IN_GAP_PERIOD;
}
break;
case TX_IN_BURST_PERIOD:
if (rnd < clg->a5) {
clg->state = LOST_IN_GAP_PERIOD;
return true;
} else {
clg->state = TX_IN_BURST_PERIOD;
}
break;
case LOST_IN_GAP_PERIOD:
if (rnd < clg->a3)
clg->state = TX_IN_BURST_PERIOD;
else if (clg->a3 < rnd && rnd < clg->a2 + clg->a3) {
clg->state = TX_IN_GAP_PERIOD;
} else if (clg->a2 + clg->a3 < rnd) {
clg->state = LOST_IN_GAP_PERIOD;
return true;
}
break;
case LOST_IN_BURST_PERIOD:
clg->state = TX_IN_GAP_PERIOD;
break;
}
return false;
}
static bool loss_gilb_ell(struct netem_sched_data *q)
{
struct clgstate *clg = &q->clg;
switch (clg->state) {
case GOOD_STATE:
if (prandom_u32() < clg->a1)
clg->state = BAD_STATE;
if (prandom_u32() < clg->a4)
return true;
break;
case BAD_STATE:
if (prandom_u32() < clg->a2)
clg->state = GOOD_STATE;
if (prandom_u32() > clg->a3)
return true;
}
return false;
}
static bool loss_event(struct netem_sched_data *q)
{
switch (q->loss_model) {
case CLG_RANDOM:
return q->loss && q->loss >= get_crandom(&q->loss_cor);
case CLG_4_STATES:
return loss_4state(q);
case CLG_GILB_ELL:
return loss_gilb_ell(q);
}
return false;
}
static psched_tdiff_t tabledist(psched_tdiff_t mu, psched_tdiff_t sigma,
struct crndstate *state,
const struct disttable *dist)
{
psched_tdiff_t x;
long t;
u32 rnd;
if (sigma == 0)
return mu;
rnd = get_crandom(state);
if (dist == NULL)
return (rnd % (2*sigma)) - sigma + mu;
t = dist->table[rnd % dist->size];
x = (sigma % NETEM_DIST_SCALE) * t;
if (x >= 0)
x += NETEM_DIST_SCALE/2;
else
x -= NETEM_DIST_SCALE/2;
return x / NETEM_DIST_SCALE + (sigma / NETEM_DIST_SCALE) * t + mu;
}
static psched_time_t packet_len_2_sched_time(unsigned int len, struct netem_sched_data *q)
{
u64 ticks;
len += q->packet_overhead;
if (q->cell_size) {
u32 cells = reciprocal_divide(len, q->cell_size_reciprocal);
if (len > cells * q->cell_size)
cells++;
len = cells * (q->cell_size + q->cell_overhead);
}
ticks = (u64)len * NSEC_PER_SEC;
do_div(ticks, q->rate);
return PSCHED_NS2TICKS(ticks);
}
static void tfifo_reset(struct Qdisc *sch)
{
struct netem_sched_data *q = qdisc_priv(sch);
struct rb_node *p;
while ((p = rb_first(&q->t_root))) {
struct sk_buff *skb = netem_rb_to_skb(p);
rb_erase(p, &q->t_root);
rtnl_kfree_skbs(skb, skb);
}
}
static void tfifo_enqueue(struct sk_buff *nskb, struct Qdisc *sch)
{
struct netem_sched_data *q = qdisc_priv(sch);
psched_time_t tnext = netem_skb_cb(nskb)->time_to_send;
struct rb_node **p = &q->t_root.rb_node, *parent = NULL;
while (*p) {
struct sk_buff *skb;
parent = *p;
skb = netem_rb_to_skb(parent);
if (tnext >= netem_skb_cb(skb)->time_to_send)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&nskb->rbnode, parent, p);
rb_insert_color(&nskb->rbnode, &q->t_root);
sch->q.qlen++;
}
static struct sk_buff *netem_segment(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
struct sk_buff *segs;
netdev_features_t features = netif_skb_features(skb);
segs = skb_gso_segment(skb, features & ~NETIF_F_GSO_MASK);
if (IS_ERR_OR_NULL(segs)) {
qdisc_drop(skb, sch, to_free);
return NULL;
}
consume_skb(skb);
return segs;
}
static void netem_enqueue_skb_head(struct qdisc_skb_head *qh, struct sk_buff *skb)
{
skb->next = qh->head;
if (!qh->head)
qh->tail = skb;
qh->head = skb;
qh->qlen++;
}
static int netem_enqueue(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
struct netem_sched_data *q = qdisc_priv(sch);
struct netem_skb_cb *cb;
struct sk_buff *skb2;
struct sk_buff *segs = NULL;
unsigned int len = 0, last_len, prev_len = qdisc_pkt_len(skb);
int nb = 0;
int count = 1;
int rc = NET_XMIT_SUCCESS;
if (q->duplicate && q->duplicate >= get_crandom(&q->dup_cor))
++count;
if (loss_event(q)) {
if (q->ecn && INET_ECN_set_ce(skb))
qdisc_qstats_drop(sch);
else
--count;
}
if (count == 0) {
qdisc_qstats_drop(sch);
__qdisc_drop(skb, to_free);
return NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
}
if (q->latency || q->jitter || q->rate)
skb_orphan_partial(skb);
if (count > 1 && (skb2 = skb_clone(skb, GFP_ATOMIC)) != NULL) {
struct Qdisc *rootq = qdisc_root(sch);
u32 dupsave = q->duplicate;
q->duplicate = 0;
rootq->enqueue(skb2, rootq, to_free);
q->duplicate = dupsave;
}
if (q->corrupt && q->corrupt >= get_crandom(&q->corrupt_cor)) {
if (skb_is_gso(skb)) {
segs = netem_segment(skb, sch, to_free);
if (!segs)
return NET_XMIT_DROP;
} else {
segs = skb;
}
skb = segs;
segs = segs->next;
skb = skb_unshare(skb, GFP_ATOMIC);
if (unlikely(!skb)) {
qdisc_qstats_drop(sch);
goto finish_segs;
}
if (skb->ip_summed == CHECKSUM_PARTIAL &&
skb_checksum_help(skb)) {
qdisc_drop(skb, sch, to_free);
goto finish_segs;
}
skb->data[prandom_u32() % skb_headlen(skb)] ^=
1<<(prandom_u32() % 8);
}
if (unlikely(sch->q.qlen >= sch->limit))
return qdisc_drop(skb, sch, to_free);
qdisc_qstats_backlog_inc(sch, skb);
cb = netem_skb_cb(skb);
if (q->gap == 0 ||
q->counter < q->gap - 1 ||
q->reorder < get_crandom(&q->reorder_cor)) {
psched_time_t now;
psched_tdiff_t delay;
delay = tabledist(q->latency, q->jitter,
&q->delay_cor, q->delay_dist);
now = psched_get_time();
if (q->rate) {
struct netem_skb_cb *last = NULL;
if (sch->q.tail)
last = netem_skb_cb(sch->q.tail);
if (q->t_root.rb_node) {
struct sk_buff *t_skb;
struct netem_skb_cb *t_last;
t_skb = netem_rb_to_skb(rb_last(&q->t_root));
t_last = netem_skb_cb(t_skb);
if (!last ||
t_last->time_to_send > last->time_to_send) {
last = t_last;
}
}
if (last) {
delay -= last->time_to_send - now;
delay = max_t(psched_tdiff_t, 0, delay);
now = last->time_to_send;
}
delay += packet_len_2_sched_time(qdisc_pkt_len(skb), q);
}
cb->time_to_send = now + delay;
cb->tstamp_save = skb->tstamp;
++q->counter;
tfifo_enqueue(skb, sch);
} else {
cb->time_to_send = psched_get_time();
q->counter = 0;
netem_enqueue_skb_head(&sch->q, skb);
sch->qstats.requeues++;
}
finish_segs:
if (segs) {
while (segs) {
skb2 = segs->next;
segs->next = NULL;
qdisc_skb_cb(segs)->pkt_len = segs->len;
last_len = segs->len;
rc = qdisc_enqueue(segs, sch, to_free);
if (rc != NET_XMIT_SUCCESS) {
if (net_xmit_drop_count(rc))
qdisc_qstats_drop(sch);
} else {
nb++;
len += last_len;
}
segs = skb2;
}
sch->q.qlen += nb;
if (nb > 1)
qdisc_tree_reduce_backlog(sch, 1 - nb, prev_len - len);
}
return NET_XMIT_SUCCESS;
}
static struct sk_buff *netem_dequeue(struct Qdisc *sch)
{
struct netem_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb;
struct rb_node *p;
tfifo_dequeue:
skb = __qdisc_dequeue_head(&sch->q);
if (skb) {
qdisc_qstats_backlog_dec(sch, skb);
deliver:
qdisc_bstats_update(sch, skb);
return skb;
}
p = rb_first(&q->t_root);
if (p) {
psched_time_t time_to_send;
skb = netem_rb_to_skb(p);
time_to_send = netem_skb_cb(skb)->time_to_send;
if (time_to_send <= psched_get_time()) {
rb_erase(p, &q->t_root);
sch->q.qlen--;
qdisc_qstats_backlog_dec(sch, skb);
skb->next = NULL;
skb->prev = NULL;
skb->tstamp = netem_skb_cb(skb)->tstamp_save;
#ifdef CONFIG_NET_CLS_ACT
if (skb->tc_redirected && skb->tc_from_ingress)
skb->tstamp = 0;
#endif
if (q->qdisc) {
unsigned int pkt_len = qdisc_pkt_len(skb);
struct sk_buff *to_free = NULL;
int err;
err = qdisc_enqueue(skb, q->qdisc, &to_free);
kfree_skb_list(to_free);
if (err != NET_XMIT_SUCCESS &&
net_xmit_drop_count(err)) {
qdisc_qstats_drop(sch);
qdisc_tree_reduce_backlog(sch, 1,
pkt_len);
}
goto tfifo_dequeue;
}
goto deliver;
}
if (q->qdisc) {
skb = q->qdisc->ops->dequeue(q->qdisc);
if (skb)
goto deliver;
}
qdisc_watchdog_schedule(&q->watchdog, time_to_send);
}
if (q->qdisc) {
skb = q->qdisc->ops->dequeue(q->qdisc);
if (skb)
goto deliver;
}
return NULL;
}
static void netem_reset(struct Qdisc *sch)
{
struct netem_sched_data *q = qdisc_priv(sch);
qdisc_reset_queue(sch);
tfifo_reset(sch);
if (q->qdisc)
qdisc_reset(q->qdisc);
qdisc_watchdog_cancel(&q->watchdog);
}
static void dist_free(struct disttable *d)
{
kvfree(d);
}
static int get_dist_table(struct Qdisc *sch, const struct nlattr *attr)
{
struct netem_sched_data *q = qdisc_priv(sch);
size_t n = nla_len(attr)/sizeof(__s16);
const __s16 *data = nla_data(attr);
spinlock_t *root_lock;
struct disttable *d;
int i;
if (n > NETEM_DIST_MAX)
return -EINVAL;
d = kvmalloc(sizeof(struct disttable) + n * sizeof(s16), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->size = n;
for (i = 0; i < n; i++)
d->table[i] = data[i];
root_lock = qdisc_root_sleeping_lock(sch);
spin_lock_bh(root_lock);
swap(q->delay_dist, d);
spin_unlock_bh(root_lock);
dist_free(d);
return 0;
}
static void get_correlation(struct netem_sched_data *q, const struct nlattr *attr)
{
const struct tc_netem_corr *c = nla_data(attr);
init_crandom(&q->delay_cor, c->delay_corr);
init_crandom(&q->loss_cor, c->loss_corr);
init_crandom(&q->dup_cor, c->dup_corr);
}
static void get_reorder(struct netem_sched_data *q, const struct nlattr *attr)
{
const struct tc_netem_reorder *r = nla_data(attr);
q->reorder = r->probability;
init_crandom(&q->reorder_cor, r->correlation);
}
static void get_corrupt(struct netem_sched_data *q, const struct nlattr *attr)
{
const struct tc_netem_corrupt *r = nla_data(attr);
q->corrupt = r->probability;
init_crandom(&q->corrupt_cor, r->correlation);
}
static void get_rate(struct netem_sched_data *q, const struct nlattr *attr)
{
const struct tc_netem_rate *r = nla_data(attr);
q->rate = r->rate;
q->packet_overhead = r->packet_overhead;
q->cell_size = r->cell_size;
q->cell_overhead = r->cell_overhead;
if (q->cell_size)
q->cell_size_reciprocal = reciprocal_value(q->cell_size);
else
q->cell_size_reciprocal = (struct reciprocal_value) { 0 };
}
static int get_loss_clg(struct netem_sched_data *q, const struct nlattr *attr)
{
const struct nlattr *la;
int rem;
nla_for_each_nested(la, attr, rem) {
u16 type = nla_type(la);
switch (type) {
case NETEM_LOSS_GI: {
const struct tc_netem_gimodel *gi = nla_data(la);
if (nla_len(la) < sizeof(struct tc_netem_gimodel)) {
pr_info("netem: incorrect gi model size\n");
return -EINVAL;
}
q->loss_model = CLG_4_STATES;
q->clg.state = TX_IN_GAP_PERIOD;
q->clg.a1 = gi->p13;
q->clg.a2 = gi->p31;
q->clg.a3 = gi->p32;
q->clg.a4 = gi->p14;
q->clg.a5 = gi->p23;
break;
}
case NETEM_LOSS_GE: {
const struct tc_netem_gemodel *ge = nla_data(la);
if (nla_len(la) < sizeof(struct tc_netem_gemodel)) {
pr_info("netem: incorrect ge model size\n");
return -EINVAL;
}
q->loss_model = CLG_GILB_ELL;
q->clg.state = GOOD_STATE;
q->clg.a1 = ge->p;
q->clg.a2 = ge->r;
q->clg.a3 = ge->h;
q->clg.a4 = ge->k1;
break;
}
default:
pr_info("netem: unknown loss type %u\n", type);
return -EINVAL;
}
}
return 0;
}
static int parse_attr(struct nlattr *tb[], int maxtype, struct nlattr *nla,
const struct nla_policy *policy, int len)
{
int nested_len = nla_len(nla) - NLA_ALIGN(len);
if (nested_len < 0) {
pr_info("netem: invalid attributes len %d\n", nested_len);
return -EINVAL;
}
if (nested_len >= nla_attr_size(0))
return nla_parse(tb, maxtype, nla_data(nla) + NLA_ALIGN(len),
nested_len, policy, NULL);
memset(tb, 0, sizeof(struct nlattr *) * (maxtype + 1));
return 0;
}
static int netem_change(struct Qdisc *sch, struct nlattr *opt)
{
struct netem_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_NETEM_MAX + 1];
struct tc_netem_qopt *qopt;
struct clgstate old_clg;
int old_loss_model = CLG_RANDOM;
int ret;
if (opt == NULL)
return -EINVAL;
qopt = nla_data(opt);
ret = parse_attr(tb, TCA_NETEM_MAX, opt, netem_policy, sizeof(*qopt));
if (ret < 0)
return ret;
old_clg = q->clg;
old_loss_model = q->loss_model;
if (tb[TCA_NETEM_LOSS]) {
ret = get_loss_clg(q, tb[TCA_NETEM_LOSS]);
if (ret) {
q->loss_model = old_loss_model;
return ret;
}
} else {
q->loss_model = CLG_RANDOM;
}
if (tb[TCA_NETEM_DELAY_DIST]) {
ret = get_dist_table(sch, tb[TCA_NETEM_DELAY_DIST]);
if (ret) {
q->clg = old_clg;
q->loss_model = old_loss_model;
return ret;
}
}
sch->limit = qopt->limit;
q->latency = qopt->latency;
q->jitter = qopt->jitter;
q->limit = qopt->limit;
q->gap = qopt->gap;
q->counter = 0;
q->loss = qopt->loss;
q->duplicate = qopt->duplicate;
if (q->gap)
q->reorder = ~0;
if (tb[TCA_NETEM_CORR])
get_correlation(q, tb[TCA_NETEM_CORR]);
if (tb[TCA_NETEM_REORDER])
get_reorder(q, tb[TCA_NETEM_REORDER]);
if (tb[TCA_NETEM_CORRUPT])
get_corrupt(q, tb[TCA_NETEM_CORRUPT]);
if (tb[TCA_NETEM_RATE])
get_rate(q, tb[TCA_NETEM_RATE]);
if (tb[TCA_NETEM_RATE64])
q->rate = max_t(u64, q->rate,
nla_get_u64(tb[TCA_NETEM_RATE64]));
if (tb[TCA_NETEM_ECN])
q->ecn = nla_get_u32(tb[TCA_NETEM_ECN]);
return ret;
}
static int netem_init(struct Qdisc *sch, struct nlattr *opt)
{
struct netem_sched_data *q = qdisc_priv(sch);
int ret;
qdisc_watchdog_init(&q->watchdog, sch);
if (!opt)
return -EINVAL;
q->loss_model = CLG_RANDOM;
ret = netem_change(sch, opt);
if (ret)
pr_info("netem: change failed\n");
return ret;
}
static void netem_destroy(struct Qdisc *sch)
{
struct netem_sched_data *q = qdisc_priv(sch);
qdisc_watchdog_cancel(&q->watchdog);
if (q->qdisc)
qdisc_destroy(q->qdisc);
dist_free(q->delay_dist);
}
static int dump_loss_model(const struct netem_sched_data *q,
struct sk_buff *skb)
{
struct nlattr *nest;
nest = nla_nest_start(skb, TCA_NETEM_LOSS);
if (nest == NULL)
goto nla_put_failure;
switch (q->loss_model) {
case CLG_RANDOM:
nla_nest_cancel(skb, nest);
return 0;
case CLG_4_STATES: {
struct tc_netem_gimodel gi = {
.p13 = q->clg.a1,
.p31 = q->clg.a2,
.p32 = q->clg.a3,
.p14 = q->clg.a4,
.p23 = q->clg.a5,
};
if (nla_put(skb, NETEM_LOSS_GI, sizeof(gi), &gi))
goto nla_put_failure;
break;
}
case CLG_GILB_ELL: {
struct tc_netem_gemodel ge = {
.p = q->clg.a1,
.r = q->clg.a2,
.h = q->clg.a3,
.k1 = q->clg.a4,
};
if (nla_put(skb, NETEM_LOSS_GE, sizeof(ge), &ge))
goto nla_put_failure;
break;
}
}
nla_nest_end(skb, nest);
return 0;
nla_put_failure:
nla_nest_cancel(skb, nest);
return -1;
}
static int netem_dump(struct Qdisc *sch, struct sk_buff *skb)
{
const struct netem_sched_data *q = qdisc_priv(sch);
struct nlattr *nla = (struct nlattr *) skb_tail_pointer(skb);
struct tc_netem_qopt qopt;
struct tc_netem_corr cor;
struct tc_netem_reorder reorder;
struct tc_netem_corrupt corrupt;
struct tc_netem_rate rate;
qopt.latency = q->latency;
qopt.jitter = q->jitter;
qopt.limit = q->limit;
qopt.loss = q->loss;
qopt.gap = q->gap;
qopt.duplicate = q->duplicate;
if (nla_put(skb, TCA_OPTIONS, sizeof(qopt), &qopt))
goto nla_put_failure;
cor.delay_corr = q->delay_cor.rho;
cor.loss_corr = q->loss_cor.rho;
cor.dup_corr = q->dup_cor.rho;
if (nla_put(skb, TCA_NETEM_CORR, sizeof(cor), &cor))
goto nla_put_failure;
reorder.probability = q->reorder;
reorder.correlation = q->reorder_cor.rho;
if (nla_put(skb, TCA_NETEM_REORDER, sizeof(reorder), &reorder))
goto nla_put_failure;
corrupt.probability = q->corrupt;
corrupt.correlation = q->corrupt_cor.rho;
if (nla_put(skb, TCA_NETEM_CORRUPT, sizeof(corrupt), &corrupt))
goto nla_put_failure;
if (q->rate >= (1ULL << 32)) {
if (nla_put_u64_64bit(skb, TCA_NETEM_RATE64, q->rate,
TCA_NETEM_PAD))
goto nla_put_failure;
rate.rate = ~0U;
} else {
rate.rate = q->rate;
}
rate.packet_overhead = q->packet_overhead;
rate.cell_size = q->cell_size;
rate.cell_overhead = q->cell_overhead;
if (nla_put(skb, TCA_NETEM_RATE, sizeof(rate), &rate))
goto nla_put_failure;
if (q->ecn && nla_put_u32(skb, TCA_NETEM_ECN, q->ecn))
goto nla_put_failure;
if (dump_loss_model(q, skb) != 0)
goto nla_put_failure;
return nla_nest_end(skb, nla);
nla_put_failure:
nlmsg_trim(skb, nla);
return -1;
}
static int netem_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
struct netem_sched_data *q = qdisc_priv(sch);
if (cl != 1 || !q->qdisc)
return -ENOENT;
tcm->tcm_handle |= TC_H_MIN(1);
tcm->tcm_info = q->qdisc->handle;
return 0;
}
static int netem_graft(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct netem_sched_data *q = qdisc_priv(sch);
*old = qdisc_replace(sch, new, &q->qdisc);
return 0;
}
static struct Qdisc *netem_leaf(struct Qdisc *sch, unsigned long arg)
{
struct netem_sched_data *q = qdisc_priv(sch);
return q->qdisc;
}
static unsigned long netem_get(struct Qdisc *sch, u32 classid)
{
return 1;
}
static void netem_put(struct Qdisc *sch, unsigned long arg)
{
}
static void netem_walk(struct Qdisc *sch, struct qdisc_walker *walker)
{
if (!walker->stop) {
if (walker->count >= walker->skip)
if (walker->fn(sch, 1, walker) < 0) {
walker->stop = 1;
return;
}
walker->count++;
}
}
static int __init netem_module_init(void)
{
pr_info("netem: version " VERSION "\n");
return register_qdisc(&netem_qdisc_ops);
}
static void __exit netem_module_exit(void)
{
unregister_qdisc(&netem_qdisc_ops);
}
