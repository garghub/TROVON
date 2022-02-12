static inline struct sfq_head *sfq_dep_head(struct sfq_sched_data *q, sfq_index val)
{
if (val < SFQ_SLOTS)
return &q->slots[val].dep;
return &q->dep[val - SFQ_SLOTS];
}
static unsigned int sfq_fold_hash(struct sfq_sched_data *q, u32 h, u32 h1)
{
return jhash_2words(h, h1, q->perturbation) & (q->divisor - 1);
}
static unsigned int sfq_hash(struct sfq_sched_data *q, struct sk_buff *skb)
{
u32 h, h2;
switch (skb->protocol) {
case htons(ETH_P_IP):
{
const struct iphdr *iph;
int poff;
if (!pskb_network_may_pull(skb, sizeof(*iph)))
goto err;
iph = ip_hdr(skb);
h = (__force u32)iph->daddr;
h2 = (__force u32)iph->saddr ^ iph->protocol;
if (iph->frag_off & htons(IP_MF | IP_OFFSET))
break;
poff = proto_ports_offset(iph->protocol);
if (poff >= 0 &&
pskb_network_may_pull(skb, iph->ihl * 4 + 4 + poff)) {
iph = ip_hdr(skb);
h2 ^= *(u32 *)((void *)iph + iph->ihl * 4 + poff);
}
break;
}
case htons(ETH_P_IPV6):
{
const struct ipv6hdr *iph;
int poff;
if (!pskb_network_may_pull(skb, sizeof(*iph)))
goto err;
iph = ipv6_hdr(skb);
h = (__force u32)iph->daddr.s6_addr32[3];
h2 = (__force u32)iph->saddr.s6_addr32[3] ^ iph->nexthdr;
poff = proto_ports_offset(iph->nexthdr);
if (poff >= 0 &&
pskb_network_may_pull(skb, sizeof(*iph) + 4 + poff)) {
iph = ipv6_hdr(skb);
h2 ^= *(u32 *)((void *)iph + sizeof(*iph) + poff);
}
break;
}
default:
err:
h = (unsigned long)skb_dst(skb) ^ (__force u32)skb->protocol;
h2 = (unsigned long)skb->sk;
}
return sfq_fold_hash(q, h, h2);
}
static unsigned int sfq_classify(struct sk_buff *skb, struct Qdisc *sch,
int *qerr)
{
struct sfq_sched_data *q = qdisc_priv(sch);
struct tcf_result res;
int result;
if (TC_H_MAJ(skb->priority) == sch->handle &&
TC_H_MIN(skb->priority) > 0 &&
TC_H_MIN(skb->priority) <= q->divisor)
return TC_H_MIN(skb->priority);
if (!q->filter_list)
return sfq_hash(q, skb) + 1;
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
result = tc_classify(skb, q->filter_list, &res);
if (result >= 0) {
#ifdef CONFIG_NET_CLS_ACT
switch (result) {
case TC_ACT_STOLEN:
case TC_ACT_QUEUED:
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_STOLEN;
case TC_ACT_SHOT:
return 0;
}
#endif
if (TC_H_MIN(res.classid) <= q->divisor)
return TC_H_MIN(res.classid);
}
return 0;
}
static inline void sfq_link(struct sfq_sched_data *q, sfq_index x)
{
sfq_index p, n;
int qlen = q->slots[x].qlen;
p = qlen + SFQ_SLOTS;
n = q->dep[qlen].next;
q->slots[x].dep.next = n;
q->slots[x].dep.prev = p;
q->dep[qlen].next = x;
sfq_dep_head(q, n)->prev = x;
}
static inline void sfq_dec(struct sfq_sched_data *q, sfq_index x)
{
sfq_index p, n;
int d;
sfq_unlink(q, x, n, p);
d = q->slots[x].qlen--;
if (n == p && q->cur_depth == d)
q->cur_depth--;
sfq_link(q, x);
}
static inline void sfq_inc(struct sfq_sched_data *q, sfq_index x)
{
sfq_index p, n;
int d;
sfq_unlink(q, x, n, p);
d = ++q->slots[x].qlen;
if (q->cur_depth < d)
q->cur_depth = d;
sfq_link(q, x);
}
static inline struct sk_buff *slot_dequeue_tail(struct sfq_slot *slot)
{
struct sk_buff *skb = slot->skblist_prev;
slot->skblist_prev = skb->prev;
skb->prev->next = (struct sk_buff *)slot;
skb->next = skb->prev = NULL;
return skb;
}
static inline struct sk_buff *slot_dequeue_head(struct sfq_slot *slot)
{
struct sk_buff *skb = slot->skblist_next;
slot->skblist_next = skb->next;
skb->next->prev = (struct sk_buff *)slot;
skb->next = skb->prev = NULL;
return skb;
}
static inline void slot_queue_init(struct sfq_slot *slot)
{
slot->skblist_prev = slot->skblist_next = (struct sk_buff *)slot;
}
static inline void slot_queue_add(struct sfq_slot *slot, struct sk_buff *skb)
{
skb->prev = slot->skblist_prev;
skb->next = (struct sk_buff *)slot;
slot->skblist_prev->next = skb;
slot->skblist_prev = skb;
}
static unsigned int sfq_drop(struct Qdisc *sch)
{
struct sfq_sched_data *q = qdisc_priv(sch);
sfq_index x, d = q->cur_depth;
struct sk_buff *skb;
unsigned int len;
struct sfq_slot *slot;
if (d > 1) {
x = q->dep[d].next;
slot = &q->slots[x];
drop:
skb = slot_dequeue_tail(slot);
len = qdisc_pkt_len(skb);
sfq_dec(q, x);
kfree_skb(skb);
sch->q.qlen--;
sch->qstats.drops++;
sch->qstats.backlog -= len;
return len;
}
if (d == 1) {
x = q->tail->next;
slot = &q->slots[x];
q->tail->next = slot->next;
q->ht[slot->hash] = SFQ_EMPTY_SLOT;
goto drop;
}
return 0;
}
static int
sfq_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct sfq_sched_data *q = qdisc_priv(sch);
unsigned int hash;
sfq_index x, qlen;
struct sfq_slot *slot;
int uninitialized_var(ret);
hash = sfq_classify(skb, sch, &ret);
if (hash == 0) {
if (ret & __NET_XMIT_BYPASS)
sch->qstats.drops++;
kfree_skb(skb);
return ret;
}
hash--;
x = q->ht[hash];
slot = &q->slots[x];
if (x == SFQ_EMPTY_SLOT) {
x = q->dep[0].next;
q->ht[hash] = x;
slot = &q->slots[x];
slot->hash = hash;
}
if (slot->qlen >= q->limit)
return qdisc_drop(skb, sch);
sch->qstats.backlog += qdisc_pkt_len(skb);
slot_queue_add(slot, skb);
sfq_inc(q, x);
if (slot->qlen == 1) {
if (q->tail == NULL) {
slot->next = x;
} else {
slot->next = q->tail->next;
q->tail->next = x;
}
q->tail = slot;
slot->allot = q->scaled_quantum;
}
if (++sch->q.qlen <= q->limit)
return NET_XMIT_SUCCESS;
qlen = slot->qlen;
sfq_drop(sch);
return (qlen != slot->qlen) ? NET_XMIT_CN : NET_XMIT_SUCCESS;
}
static struct sk_buff *
sfq_dequeue(struct Qdisc *sch)
{
struct sfq_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb;
sfq_index a, next_a;
struct sfq_slot *slot;
if (q->tail == NULL)
return NULL;
next_slot:
a = q->tail->next;
slot = &q->slots[a];
if (slot->allot <= 0) {
q->tail = slot;
slot->allot += q->scaled_quantum;
goto next_slot;
}
skb = slot_dequeue_head(slot);
sfq_dec(q, a);
qdisc_bstats_update(sch, skb);
sch->q.qlen--;
sch->qstats.backlog -= qdisc_pkt_len(skb);
if (slot->qlen == 0) {
q->ht[slot->hash] = SFQ_EMPTY_SLOT;
next_a = slot->next;
if (a == next_a) {
q->tail = NULL;
return skb;
}
q->tail->next = next_a;
} else {
slot->allot -= SFQ_ALLOT_SIZE(qdisc_pkt_len(skb));
}
return skb;
}
static void
sfq_reset(struct Qdisc *sch)
{
struct sk_buff *skb;
while ((skb = sfq_dequeue(sch)) != NULL)
kfree_skb(skb);
}
static void sfq_perturbation(unsigned long arg)
{
struct Qdisc *sch = (struct Qdisc *)arg;
struct sfq_sched_data *q = qdisc_priv(sch);
q->perturbation = net_random();
if (q->perturb_period)
mod_timer(&q->perturb_timer, jiffies + q->perturb_period);
}
static int sfq_change(struct Qdisc *sch, struct nlattr *opt)
{
struct sfq_sched_data *q = qdisc_priv(sch);
struct tc_sfq_qopt *ctl = nla_data(opt);
unsigned int qlen;
if (opt->nla_len < nla_attr_size(sizeof(*ctl)))
return -EINVAL;
if (ctl->divisor &&
(!is_power_of_2(ctl->divisor) || ctl->divisor > 65536))
return -EINVAL;
sch_tree_lock(sch);
q->quantum = ctl->quantum ? : psched_mtu(qdisc_dev(sch));
q->scaled_quantum = SFQ_ALLOT_SIZE(q->quantum);
q->perturb_period = ctl->perturb_period * HZ;
if (ctl->limit)
q->limit = min_t(u32, ctl->limit, SFQ_DEPTH - 1);
if (ctl->divisor)
q->divisor = ctl->divisor;
qlen = sch->q.qlen;
while (sch->q.qlen > q->limit)
sfq_drop(sch);
qdisc_tree_decrease_qlen(sch, qlen - sch->q.qlen);
del_timer(&q->perturb_timer);
if (q->perturb_period) {
mod_timer(&q->perturb_timer, jiffies + q->perturb_period);
q->perturbation = net_random();
}
sch_tree_unlock(sch);
return 0;
}
static int sfq_init(struct Qdisc *sch, struct nlattr *opt)
{
struct sfq_sched_data *q = qdisc_priv(sch);
size_t sz;
int i;
q->perturb_timer.function = sfq_perturbation;
q->perturb_timer.data = (unsigned long)sch;
init_timer_deferrable(&q->perturb_timer);
for (i = 0; i < SFQ_DEPTH; i++) {
q->dep[i].next = i + SFQ_SLOTS;
q->dep[i].prev = i + SFQ_SLOTS;
}
q->limit = SFQ_DEPTH - 1;
q->cur_depth = 0;
q->tail = NULL;
q->divisor = SFQ_DEFAULT_HASH_DIVISOR;
if (opt == NULL) {
q->quantum = psched_mtu(qdisc_dev(sch));
q->scaled_quantum = SFQ_ALLOT_SIZE(q->quantum);
q->perturb_period = 0;
q->perturbation = net_random();
} else {
int err = sfq_change(sch, opt);
if (err)
return err;
}
sz = sizeof(q->ht[0]) * q->divisor;
q->ht = kmalloc(sz, GFP_KERNEL);
if (!q->ht && sz > PAGE_SIZE)
q->ht = vmalloc(sz);
if (!q->ht)
return -ENOMEM;
for (i = 0; i < q->divisor; i++)
q->ht[i] = SFQ_EMPTY_SLOT;
for (i = 0; i < SFQ_SLOTS; i++) {
slot_queue_init(&q->slots[i]);
sfq_link(q, i);
}
if (q->limit >= 1)
sch->flags |= TCQ_F_CAN_BYPASS;
else
sch->flags &= ~TCQ_F_CAN_BYPASS;
return 0;
}
static void sfq_destroy(struct Qdisc *sch)
{
struct sfq_sched_data *q = qdisc_priv(sch);
tcf_destroy_chain(&q->filter_list);
q->perturb_period = 0;
del_timer_sync(&q->perturb_timer);
if (is_vmalloc_addr(q->ht))
vfree(q->ht);
else
kfree(q->ht);
}
static int sfq_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct sfq_sched_data *q = qdisc_priv(sch);
unsigned char *b = skb_tail_pointer(skb);
struct tc_sfq_qopt opt;
opt.quantum = q->quantum;
opt.perturb_period = q->perturb_period / HZ;
opt.limit = q->limit;
opt.divisor = q->divisor;
opt.flows = q->limit;
NLA_PUT(skb, TCA_OPTIONS, sizeof(opt), &opt);
return skb->len;
nla_put_failure:
nlmsg_trim(skb, b);
return -1;
}
static struct Qdisc *sfq_leaf(struct Qdisc *sch, unsigned long arg)
{
return NULL;
}
static unsigned long sfq_get(struct Qdisc *sch, u32 classid)
{
return 0;
}
static unsigned long sfq_bind(struct Qdisc *sch, unsigned long parent,
u32 classid)
{
sch->flags &= ~TCQ_F_CAN_BYPASS;
return 0;
}
static void sfq_put(struct Qdisc *q, unsigned long cl)
{
}
static struct tcf_proto **sfq_find_tcf(struct Qdisc *sch, unsigned long cl)
{
struct sfq_sched_data *q = qdisc_priv(sch);
if (cl)
return NULL;
return &q->filter_list;
}
static int sfq_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
tcm->tcm_handle |= TC_H_MIN(cl);
return 0;
}
static int sfq_dump_class_stats(struct Qdisc *sch, unsigned long cl,
struct gnet_dump *d)
{
struct sfq_sched_data *q = qdisc_priv(sch);
sfq_index idx = q->ht[cl - 1];
struct gnet_stats_queue qs = { 0 };
struct tc_sfq_xstats xstats = { 0 };
struct sk_buff *skb;
if (idx != SFQ_EMPTY_SLOT) {
const struct sfq_slot *slot = &q->slots[idx];
xstats.allot = slot->allot << SFQ_ALLOT_SHIFT;
qs.qlen = slot->qlen;
slot_queue_walk(slot, skb)
qs.backlog += qdisc_pkt_len(skb);
}
if (gnet_stats_copy_queue(d, &qs) < 0)
return -1;
return gnet_stats_copy_app(d, &xstats, sizeof(xstats));
}
static void sfq_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
struct sfq_sched_data *q = qdisc_priv(sch);
unsigned int i;
if (arg->stop)
return;
for (i = 0; i < q->divisor; i++) {
if (q->ht[i] == SFQ_EMPTY_SLOT ||
arg->count < arg->skip) {
arg->count++;
continue;
}
if (arg->fn(sch, i + 1, arg) < 0) {
arg->stop = 1;
break;
}
arg->count++;
}
}
static int __init sfq_module_init(void)
{
return register_qdisc(&sfq_qdisc_ops);
}
static void __exit sfq_module_exit(void)
{
unregister_qdisc(&sfq_qdisc_ops);
}
