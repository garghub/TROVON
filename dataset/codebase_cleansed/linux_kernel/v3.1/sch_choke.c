static u32 random_N(unsigned int N)
{
return reciprocal_divide(random32(), N);
}
static unsigned int choke_len(const struct choke_sched_data *q)
{
return (q->tail - q->head) & q->tab_mask;
}
static int use_ecn(const struct choke_sched_data *q)
{
return q->flags & TC_RED_ECN;
}
static int use_harddrop(const struct choke_sched_data *q)
{
return q->flags & TC_RED_HARDDROP;
}
static void choke_zap_head_holes(struct choke_sched_data *q)
{
do {
q->head = (q->head + 1) & q->tab_mask;
if (q->head == q->tail)
break;
} while (q->tab[q->head] == NULL);
}
static void choke_zap_tail_holes(struct choke_sched_data *q)
{
do {
q->tail = (q->tail - 1) & q->tab_mask;
if (q->head == q->tail)
break;
} while (q->tab[q->tail] == NULL);
}
static void choke_drop_by_idx(struct Qdisc *sch, unsigned int idx)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb = q->tab[idx];
q->tab[idx] = NULL;
if (idx == q->head)
choke_zap_head_holes(q);
if (idx == q->tail)
choke_zap_tail_holes(q);
sch->qstats.backlog -= qdisc_pkt_len(skb);
qdisc_drop(skb, sch);
qdisc_tree_decrease_qlen(sch, 1);
--sch->q.qlen;
}
static bool choke_match_flow(struct sk_buff *skb1,
struct sk_buff *skb2)
{
int off1, off2, poff;
const u32 *ports1, *ports2;
u8 ip_proto;
__u32 hash1;
if (skb1->protocol != skb2->protocol)
return false;
hash1 = skb_get_rxhash(skb1);
if (!hash1 || hash1 != skb_get_rxhash(skb2))
return false;
off1 = skb_network_offset(skb1);
off2 = skb_network_offset(skb2);
switch (skb1->protocol) {
case __constant_htons(ETH_P_IP): {
const struct iphdr *ip1, *ip2;
ip1 = (const struct iphdr *) (skb1->data + off1);
ip2 = (const struct iphdr *) (skb2->data + off2);
ip_proto = ip1->protocol;
if (ip_proto != ip2->protocol ||
ip1->saddr != ip2->saddr || ip1->daddr != ip2->daddr)
return false;
if (ip_is_fragment(ip1) | ip_is_fragment(ip2))
ip_proto = 0;
off1 += ip1->ihl * 4;
off2 += ip2->ihl * 4;
break;
}
case __constant_htons(ETH_P_IPV6): {
const struct ipv6hdr *ip1, *ip2;
ip1 = (const struct ipv6hdr *) (skb1->data + off1);
ip2 = (const struct ipv6hdr *) (skb2->data + off2);
ip_proto = ip1->nexthdr;
if (ip_proto != ip2->nexthdr ||
ipv6_addr_cmp(&ip1->saddr, &ip2->saddr) ||
ipv6_addr_cmp(&ip1->daddr, &ip2->daddr))
return false;
off1 += 40;
off2 += 40;
}
default:
return false;
}
poff = proto_ports_offset(ip_proto);
if (poff < 0)
return true;
off1 += poff;
off2 += poff;
ports1 = (__force u32 *)(skb1->data + off1);
ports2 = (__force u32 *)(skb2->data + off2);
return *ports1 == *ports2;
}
static inline struct choke_skb_cb *choke_skb_cb(const struct sk_buff *skb)
{
BUILD_BUG_ON(sizeof(skb->cb) <
sizeof(struct qdisc_skb_cb) + sizeof(struct choke_skb_cb));
return (struct choke_skb_cb *)qdisc_skb_cb(skb)->data;
}
static inline void choke_set_classid(struct sk_buff *skb, u16 classid)
{
choke_skb_cb(skb)->classid = classid;
}
static u16 choke_get_classid(const struct sk_buff *skb)
{
return choke_skb_cb(skb)->classid;
}
static bool choke_classify(struct sk_buff *skb,
struct Qdisc *sch, int *qerr)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct tcf_result res;
int result;
result = tc_classify(skb, q->filter_list, &res);
if (result >= 0) {
#ifdef CONFIG_NET_CLS_ACT
switch (result) {
case TC_ACT_STOLEN:
case TC_ACT_QUEUED:
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_STOLEN;
case TC_ACT_SHOT:
return false;
}
#endif
choke_set_classid(skb, TC_H_MIN(res.classid));
return true;
}
return false;
}
static struct sk_buff *choke_peek_random(const struct choke_sched_data *q,
unsigned int *pidx)
{
struct sk_buff *skb;
int retrys = 3;
do {
*pidx = (q->head + random_N(choke_len(q))) & q->tab_mask;
skb = q->tab[*pidx];
if (skb)
return skb;
} while (--retrys > 0);
return q->tab[*pidx = q->head];
}
static bool choke_match_random(const struct choke_sched_data *q,
struct sk_buff *nskb,
unsigned int *pidx)
{
struct sk_buff *oskb;
if (q->head == q->tail)
return false;
oskb = choke_peek_random(q, pidx);
if (q->filter_list)
return choke_get_classid(nskb) == choke_get_classid(oskb);
return choke_match_flow(oskb, nskb);
}
static int choke_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct red_parms *p = &q->parms;
int ret = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
if (q->filter_list) {
if (!choke_classify(skb, sch, &ret))
goto other_drop;
}
p->qavg = red_calc_qavg(p, sch->q.qlen);
if (red_is_idling(p))
red_end_of_idle_period(p);
if (p->qavg <= p->qth_min)
p->qcount = -1;
else {
unsigned int idx;
if (choke_match_random(q, skb, &idx)) {
q->stats.matched++;
choke_drop_by_idx(sch, idx);
goto congestion_drop;
}
if (p->qavg > p->qth_max) {
p->qcount = -1;
sch->qstats.overlimits++;
if (use_harddrop(q) || !use_ecn(q) ||
!INET_ECN_set_ce(skb)) {
q->stats.forced_drop++;
goto congestion_drop;
}
q->stats.forced_mark++;
} else if (++p->qcount) {
if (red_mark_probability(p, p->qavg)) {
p->qcount = 0;
p->qR = red_random(p);
sch->qstats.overlimits++;
if (!use_ecn(q) || !INET_ECN_set_ce(skb)) {
q->stats.prob_drop++;
goto congestion_drop;
}
q->stats.prob_mark++;
}
} else
p->qR = red_random(p);
}
if (sch->q.qlen < q->limit) {
q->tab[q->tail] = skb;
q->tail = (q->tail + 1) & q->tab_mask;
++sch->q.qlen;
sch->qstats.backlog += qdisc_pkt_len(skb);
return NET_XMIT_SUCCESS;
}
q->stats.pdrop++;
sch->qstats.drops++;
kfree_skb(skb);
return NET_XMIT_DROP;
congestion_drop:
qdisc_drop(skb, sch);
return NET_XMIT_CN;
other_drop:
if (ret & __NET_XMIT_BYPASS)
sch->qstats.drops++;
kfree_skb(skb);
return ret;
}
static struct sk_buff *choke_dequeue(struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb;
if (q->head == q->tail) {
if (!red_is_idling(&q->parms))
red_start_of_idle_period(&q->parms);
return NULL;
}
skb = q->tab[q->head];
q->tab[q->head] = NULL;
choke_zap_head_holes(q);
--sch->q.qlen;
sch->qstats.backlog -= qdisc_pkt_len(skb);
qdisc_bstats_update(sch, skb);
return skb;
}
static unsigned int choke_drop(struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
unsigned int len;
len = qdisc_queue_drop(sch);
if (len > 0)
q->stats.other++;
else {
if (!red_is_idling(&q->parms))
red_start_of_idle_period(&q->parms);
}
return len;
}
static void choke_reset(struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
red_restart(&q->parms);
}
static void choke_free(void *addr)
{
if (addr) {
if (is_vmalloc_addr(addr))
vfree(addr);
else
kfree(addr);
}
}
static int choke_change(struct Qdisc *sch, struct nlattr *opt)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_CHOKE_MAX + 1];
const struct tc_red_qopt *ctl;
int err;
struct sk_buff **old = NULL;
unsigned int mask;
if (opt == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_CHOKE_MAX, opt, choke_policy);
if (err < 0)
return err;
if (tb[TCA_CHOKE_PARMS] == NULL ||
tb[TCA_CHOKE_STAB] == NULL)
return -EINVAL;
ctl = nla_data(tb[TCA_CHOKE_PARMS]);
if (ctl->limit > CHOKE_MAX_QUEUE)
return -EINVAL;
mask = roundup_pow_of_two(ctl->limit + 1) - 1;
if (mask != q->tab_mask) {
struct sk_buff **ntab;
ntab = kcalloc(mask + 1, sizeof(struct sk_buff *), GFP_KERNEL);
if (!ntab)
ntab = vzalloc((mask + 1) * sizeof(struct sk_buff *));
if (!ntab)
return -ENOMEM;
sch_tree_lock(sch);
old = q->tab;
if (old) {
unsigned int oqlen = sch->q.qlen, tail = 0;
while (q->head != q->tail) {
struct sk_buff *skb = q->tab[q->head];
q->head = (q->head + 1) & q->tab_mask;
if (!skb)
continue;
if (tail < mask) {
ntab[tail++] = skb;
continue;
}
sch->qstats.backlog -= qdisc_pkt_len(skb);
--sch->q.qlen;
qdisc_drop(skb, sch);
}
qdisc_tree_decrease_qlen(sch, oqlen - sch->q.qlen);
q->head = 0;
q->tail = tail;
}
q->tab_mask = mask;
q->tab = ntab;
} else
sch_tree_lock(sch);
q->flags = ctl->flags;
q->limit = ctl->limit;
red_set_parms(&q->parms, ctl->qth_min, ctl->qth_max, ctl->Wlog,
ctl->Plog, ctl->Scell_log,
nla_data(tb[TCA_CHOKE_STAB]));
if (q->head == q->tail)
red_end_of_idle_period(&q->parms);
sch_tree_unlock(sch);
choke_free(old);
return 0;
}
static int choke_init(struct Qdisc *sch, struct nlattr *opt)
{
return choke_change(sch, opt);
}
static int choke_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct nlattr *opts = NULL;
struct tc_red_qopt opt = {
.limit = q->limit,
.flags = q->flags,
.qth_min = q->parms.qth_min >> q->parms.Wlog,
.qth_max = q->parms.qth_max >> q->parms.Wlog,
.Wlog = q->parms.Wlog,
.Plog = q->parms.Plog,
.Scell_log = q->parms.Scell_log,
};
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
NLA_PUT(skb, TCA_CHOKE_PARMS, sizeof(opt), &opt);
return nla_nest_end(skb, opts);
nla_put_failure:
nla_nest_cancel(skb, opts);
return -EMSGSIZE;
}
static int choke_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct choke_sched_data *q = qdisc_priv(sch);
struct tc_choke_xstats st = {
.early = q->stats.prob_drop + q->stats.forced_drop,
.marked = q->stats.prob_mark + q->stats.forced_mark,
.pdrop = q->stats.pdrop,
.other = q->stats.other,
.matched = q->stats.matched,
};
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static void choke_destroy(struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
tcf_destroy_chain(&q->filter_list);
choke_free(q->tab);
}
static struct Qdisc *choke_leaf(struct Qdisc *sch, unsigned long arg)
{
return NULL;
}
static unsigned long choke_get(struct Qdisc *sch, u32 classid)
{
return 0;
}
static void choke_put(struct Qdisc *q, unsigned long cl)
{
}
static unsigned long choke_bind(struct Qdisc *sch, unsigned long parent,
u32 classid)
{
return 0;
}
static struct tcf_proto **choke_find_tcf(struct Qdisc *sch, unsigned long cl)
{
struct choke_sched_data *q = qdisc_priv(sch);
if (cl)
return NULL;
return &q->filter_list;
}
static int choke_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
tcm->tcm_handle |= TC_H_MIN(cl);
return 0;
}
static void choke_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
if (!arg->stop) {
if (arg->fn(sch, 1, arg) < 0) {
arg->stop = 1;
return;
}
arg->count++;
}
}
static struct sk_buff *choke_peek_head(struct Qdisc *sch)
{
struct choke_sched_data *q = qdisc_priv(sch);
return (q->head != q->tail) ? q->tab[q->head] : NULL;
}
static int __init choke_module_init(void)
{
return register_qdisc(&choke_qdisc_ops);
}
static void __exit choke_module_exit(void)
{
unregister_qdisc(&choke_qdisc_ops);
}
