static struct qfq_class *qfq_find_class(struct Qdisc *sch, u32 classid)
{
struct qfq_sched *q = qdisc_priv(sch);
struct Qdisc_class_common *clc;
clc = qdisc_class_find(&q->clhash, classid);
if (clc == NULL)
return NULL;
return container_of(clc, struct qfq_class, common);
}
static void qfq_purge_queue(struct qfq_class *cl)
{
unsigned int len = cl->qdisc->q.qlen;
qdisc_reset(cl->qdisc);
qdisc_tree_decrease_qlen(cl->qdisc, len);
}
static int qfq_calc_index(u32 inv_w, unsigned int maxlen)
{
u64 slot_size = (u64)maxlen * inv_w;
unsigned long size_map;
int index = 0;
size_map = slot_size >> QFQ_MIN_SLOT_SHIFT;
if (!size_map)
goto out;
index = __fls(size_map) + 1;
index -= !(slot_size - (1ULL << (index + QFQ_MIN_SLOT_SHIFT - 1)));
if (index < 0)
index = 0;
out:
pr_debug("qfq calc_index: W = %lu, L = %u, I = %d\n",
(unsigned long) ONE_FP/inv_w, maxlen, index);
return index;
}
static int qfq_change_class(struct Qdisc *sch, u32 classid, u32 parentid,
struct nlattr **tca, unsigned long *arg)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl = (struct qfq_class *)*arg;
struct nlattr *tb[TCA_QFQ_MAX + 1];
u32 weight, lmax, inv_w;
int i, err;
if (tca[TCA_OPTIONS] == NULL) {
pr_notice("qfq: no options\n");
return -EINVAL;
}
err = nla_parse_nested(tb, TCA_QFQ_MAX, tca[TCA_OPTIONS], qfq_policy);
if (err < 0)
return err;
if (tb[TCA_QFQ_WEIGHT]) {
weight = nla_get_u32(tb[TCA_QFQ_WEIGHT]);
if (!weight || weight > (1UL << QFQ_MAX_WSHIFT)) {
pr_notice("qfq: invalid weight %u\n", weight);
return -EINVAL;
}
} else
weight = 1;
inv_w = ONE_FP / weight;
weight = ONE_FP / inv_w;
if (q->wsum + weight > QFQ_MAX_WSUM) {
pr_notice("qfq: total weight out of range (%u + %u)\n",
weight, q->wsum);
return -EINVAL;
}
if (tb[TCA_QFQ_LMAX]) {
lmax = nla_get_u32(tb[TCA_QFQ_LMAX]);
if (!lmax || lmax > (1UL << QFQ_MTU_SHIFT)) {
pr_notice("qfq: invalid max length %u\n", lmax);
return -EINVAL;
}
} else
lmax = 1UL << QFQ_MTU_SHIFT;
if (cl != NULL) {
if (tca[TCA_RATE]) {
err = gen_replace_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE]);
if (err)
return err;
}
sch_tree_lock(sch);
if (tb[TCA_QFQ_WEIGHT]) {
q->wsum = weight - ONE_FP / cl->inv_w;
cl->inv_w = inv_w;
}
sch_tree_unlock(sch);
return 0;
}
cl = kzalloc(sizeof(struct qfq_class), GFP_KERNEL);
if (cl == NULL)
return -ENOBUFS;
cl->refcnt = 1;
cl->common.classid = classid;
cl->lmax = lmax;
cl->inv_w = inv_w;
i = qfq_calc_index(cl->inv_w, cl->lmax);
cl->grp = &q->groups[i];
q->wsum += weight;
cl->qdisc = qdisc_create_dflt(sch->dev_queue,
&pfifo_qdisc_ops, classid);
if (cl->qdisc == NULL)
cl->qdisc = &noop_qdisc;
if (tca[TCA_RATE]) {
err = gen_new_estimator(&cl->bstats, &cl->rate_est,
qdisc_root_sleeping_lock(sch),
tca[TCA_RATE]);
if (err) {
qdisc_destroy(cl->qdisc);
kfree(cl);
return err;
}
}
sch_tree_lock(sch);
qdisc_class_hash_insert(&q->clhash, &cl->common);
sch_tree_unlock(sch);
qdisc_class_hash_grow(sch, &q->clhash);
*arg = (unsigned long)cl;
return 0;
}
static void qfq_destroy_class(struct Qdisc *sch, struct qfq_class *cl)
{
struct qfq_sched *q = qdisc_priv(sch);
if (cl->inv_w) {
q->wsum -= ONE_FP / cl->inv_w;
cl->inv_w = 0;
}
gen_kill_estimator(&cl->bstats, &cl->rate_est);
qdisc_destroy(cl->qdisc);
kfree(cl);
}
static int qfq_delete_class(struct Qdisc *sch, unsigned long arg)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl = (struct qfq_class *)arg;
if (cl->filter_cnt > 0)
return -EBUSY;
sch_tree_lock(sch);
qfq_purge_queue(cl);
qdisc_class_hash_remove(&q->clhash, &cl->common);
BUG_ON(--cl->refcnt == 0);
sch_tree_unlock(sch);
return 0;
}
static unsigned long qfq_get_class(struct Qdisc *sch, u32 classid)
{
struct qfq_class *cl = qfq_find_class(sch, classid);
if (cl != NULL)
cl->refcnt++;
return (unsigned long)cl;
}
static void qfq_put_class(struct Qdisc *sch, unsigned long arg)
{
struct qfq_class *cl = (struct qfq_class *)arg;
if (--cl->refcnt == 0)
qfq_destroy_class(sch, cl);
}
static struct tcf_proto **qfq_tcf_chain(struct Qdisc *sch, unsigned long cl)
{
struct qfq_sched *q = qdisc_priv(sch);
if (cl)
return NULL;
return &q->filter_list;
}
static unsigned long qfq_bind_tcf(struct Qdisc *sch, unsigned long parent,
u32 classid)
{
struct qfq_class *cl = qfq_find_class(sch, classid);
if (cl != NULL)
cl->filter_cnt++;
return (unsigned long)cl;
}
static void qfq_unbind_tcf(struct Qdisc *sch, unsigned long arg)
{
struct qfq_class *cl = (struct qfq_class *)arg;
cl->filter_cnt--;
}
static int qfq_graft_class(struct Qdisc *sch, unsigned long arg,
struct Qdisc *new, struct Qdisc **old)
{
struct qfq_class *cl = (struct qfq_class *)arg;
if (new == NULL) {
new = qdisc_create_dflt(sch->dev_queue,
&pfifo_qdisc_ops, cl->common.classid);
if (new == NULL)
new = &noop_qdisc;
}
sch_tree_lock(sch);
qfq_purge_queue(cl);
*old = cl->qdisc;
cl->qdisc = new;
sch_tree_unlock(sch);
return 0;
}
static struct Qdisc *qfq_class_leaf(struct Qdisc *sch, unsigned long arg)
{
struct qfq_class *cl = (struct qfq_class *)arg;
return cl->qdisc;
}
static int qfq_dump_class(struct Qdisc *sch, unsigned long arg,
struct sk_buff *skb, struct tcmsg *tcm)
{
struct qfq_class *cl = (struct qfq_class *)arg;
struct nlattr *nest;
tcm->tcm_parent = TC_H_ROOT;
tcm->tcm_handle = cl->common.classid;
tcm->tcm_info = cl->qdisc->handle;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
NLA_PUT_U32(skb, TCA_QFQ_WEIGHT, ONE_FP/cl->inv_w);
NLA_PUT_U32(skb, TCA_QFQ_LMAX, cl->lmax);
return nla_nest_end(skb, nest);
nla_put_failure:
nla_nest_cancel(skb, nest);
return -EMSGSIZE;
}
static int qfq_dump_class_stats(struct Qdisc *sch, unsigned long arg,
struct gnet_dump *d)
{
struct qfq_class *cl = (struct qfq_class *)arg;
struct tc_qfq_stats xstats;
memset(&xstats, 0, sizeof(xstats));
cl->qdisc->qstats.qlen = cl->qdisc->q.qlen;
xstats.weight = ONE_FP/cl->inv_w;
xstats.lmax = cl->lmax;
if (gnet_stats_copy_basic(d, &cl->bstats) < 0 ||
gnet_stats_copy_rate_est(d, &cl->bstats, &cl->rate_est) < 0 ||
gnet_stats_copy_queue(d, &cl->qdisc->qstats) < 0)
return -1;
return gnet_stats_copy_app(d, &xstats, sizeof(xstats));
}
static void qfq_walk(struct Qdisc *sch, struct qdisc_walker *arg)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl;
struct hlist_node *n;
unsigned int i;
if (arg->stop)
return;
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, n, &q->clhash.hash[i], common.hnode) {
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
static struct qfq_class *qfq_classify(struct sk_buff *skb, struct Qdisc *sch,
int *qerr)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl;
struct tcf_result res;
int result;
if (TC_H_MAJ(skb->priority ^ sch->handle) == 0) {
pr_debug("qfq_classify: found %d\n", skb->priority);
cl = qfq_find_class(sch, skb->priority);
if (cl != NULL)
return cl;
}
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
result = tc_classify(skb, q->filter_list, &res);
if (result >= 0) {
#ifdef CONFIG_NET_CLS_ACT
switch (result) {
case TC_ACT_QUEUED:
case TC_ACT_STOLEN:
*qerr = NET_XMIT_SUCCESS | __NET_XMIT_STOLEN;
case TC_ACT_SHOT:
return NULL;
}
#endif
cl = (struct qfq_class *)res.class;
if (cl == NULL)
cl = qfq_find_class(sch, res.classid);
return cl;
}
return NULL;
}
static inline int qfq_gt(u64 a, u64 b)
{
return (s64)(a - b) > 0;
}
static inline u64 qfq_round_down(u64 ts, unsigned int shift)
{
return ts & ~((1ULL << shift) - 1);
}
static inline struct qfq_group *qfq_ffs(struct qfq_sched *q,
unsigned long bitmap)
{
int index = __ffs(bitmap);
return &q->groups[index];
}
static inline unsigned long mask_from(unsigned long bitmap, int from)
{
return bitmap & ~((1UL << from) - 1);
}
static int qfq_calc_state(struct qfq_sched *q, const struct qfq_group *grp)
{
unsigned int state = qfq_gt(grp->S, q->V);
unsigned long mask = mask_from(q->bitmaps[ER], grp->index);
struct qfq_group *next;
if (mask) {
next = qfq_ffs(q, mask);
if (qfq_gt(grp->F, next->F))
state |= EB;
}
return state;
}
static inline void qfq_move_groups(struct qfq_sched *q, unsigned long mask,
int src, int dst)
{
q->bitmaps[dst] |= q->bitmaps[src] & mask;
q->bitmaps[src] &= ~mask;
}
static void qfq_unblock_groups(struct qfq_sched *q, int index, u64 old_F)
{
unsigned long mask = mask_from(q->bitmaps[ER], index + 1);
struct qfq_group *next;
if (mask) {
next = qfq_ffs(q, mask);
if (!qfq_gt(next->F, old_F))
return;
}
mask = (1UL << index) - 1;
qfq_move_groups(q, mask, EB, ER);
qfq_move_groups(q, mask, IB, IR);
}
static void qfq_make_eligible(struct qfq_sched *q, u64 old_V)
{
unsigned long vslot = q->V >> QFQ_MIN_SLOT_SHIFT;
unsigned long old_vslot = old_V >> QFQ_MIN_SLOT_SHIFT;
if (vslot != old_vslot) {
unsigned long mask = (1UL << fls(vslot ^ old_vslot)) - 1;
qfq_move_groups(q, mask, IR, ER);
qfq_move_groups(q, mask, IB, EB);
}
}
static void qfq_slot_insert(struct qfq_group *grp, struct qfq_class *cl,
u64 roundedS)
{
u64 slot = (roundedS - grp->S) >> grp->slot_shift;
unsigned int i = (grp->front + slot) % QFQ_MAX_SLOTS;
hlist_add_head(&cl->next, &grp->slots[i]);
__set_bit(slot, &grp->full_slots);
}
static struct qfq_class *qfq_slot_head(struct qfq_group *grp)
{
return hlist_entry(grp->slots[grp->front].first,
struct qfq_class, next);
}
static void qfq_front_slot_remove(struct qfq_group *grp)
{
struct qfq_class *cl = qfq_slot_head(grp);
BUG_ON(!cl);
hlist_del(&cl->next);
if (hlist_empty(&grp->slots[grp->front]))
__clear_bit(0, &grp->full_slots);
}
static struct qfq_class *qfq_slot_scan(struct qfq_group *grp)
{
unsigned int i;
pr_debug("qfq slot_scan: grp %u full %#lx\n",
grp->index, grp->full_slots);
if (grp->full_slots == 0)
return NULL;
i = __ffs(grp->full_slots);
if (i > 0) {
grp->front = (grp->front + i) % QFQ_MAX_SLOTS;
grp->full_slots >>= i;
}
return qfq_slot_head(grp);
}
static void qfq_slot_rotate(struct qfq_group *grp, u64 roundedS)
{
unsigned int i = (grp->S - roundedS) >> grp->slot_shift;
grp->full_slots <<= i;
grp->front = (grp->front - i) % QFQ_MAX_SLOTS;
}
static void qfq_update_eligible(struct qfq_sched *q, u64 old_V)
{
struct qfq_group *grp;
unsigned long ineligible;
ineligible = q->bitmaps[IR] | q->bitmaps[IB];
if (ineligible) {
if (!q->bitmaps[ER]) {
grp = qfq_ffs(q, ineligible);
if (qfq_gt(grp->S, q->V))
q->V = grp->S;
}
qfq_make_eligible(q, old_V);
}
}
static unsigned int qdisc_peek_len(struct Qdisc *sch)
{
struct sk_buff *skb;
skb = sch->ops->peek(sch);
return skb ? qdisc_pkt_len(skb) : 0;
}
static bool qfq_update_class(struct qfq_group *grp, struct qfq_class *cl)
{
unsigned int len = qdisc_peek_len(cl->qdisc);
cl->S = cl->F;
if (!len)
qfq_front_slot_remove(grp);
else {
u64 roundedS;
cl->F = cl->S + (u64)len * cl->inv_w;
roundedS = qfq_round_down(cl->S, grp->slot_shift);
if (roundedS == grp->S)
return false;
qfq_front_slot_remove(grp);
qfq_slot_insert(grp, cl, roundedS);
}
return true;
}
static struct sk_buff *qfq_dequeue(struct Qdisc *sch)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_group *grp;
struct qfq_class *cl;
struct sk_buff *skb;
unsigned int len;
u64 old_V;
if (!q->bitmaps[ER])
return NULL;
grp = qfq_ffs(q, q->bitmaps[ER]);
cl = qfq_slot_head(grp);
skb = qdisc_dequeue_peeked(cl->qdisc);
if (!skb) {
WARN_ONCE(1, "qfq_dequeue: non-workconserving leaf\n");
return NULL;
}
sch->q.qlen--;
qdisc_bstats_update(sch, skb);
old_V = q->V;
len = qdisc_pkt_len(skb);
q->V += (u64)len * IWSUM;
pr_debug("qfq dequeue: len %u F %lld now %lld\n",
len, (unsigned long long) cl->F, (unsigned long long) q->V);
if (qfq_update_class(grp, cl)) {
u64 old_F = grp->F;
cl = qfq_slot_scan(grp);
if (!cl)
__clear_bit(grp->index, &q->bitmaps[ER]);
else {
u64 roundedS = qfq_round_down(cl->S, grp->slot_shift);
unsigned int s;
if (grp->S == roundedS)
goto skip_unblock;
grp->S = roundedS;
grp->F = roundedS + (2ULL << grp->slot_shift);
__clear_bit(grp->index, &q->bitmaps[ER]);
s = qfq_calc_state(q, grp);
__set_bit(grp->index, &q->bitmaps[s]);
}
qfq_unblock_groups(q, grp->index, old_F);
}
skip_unblock:
qfq_update_eligible(q, old_V);
return skb;
}
static void qfq_update_start(struct qfq_sched *q, struct qfq_class *cl)
{
unsigned long mask;
u64 limit, roundedF;
int slot_shift = cl->grp->slot_shift;
roundedF = qfq_round_down(cl->F, slot_shift);
limit = qfq_round_down(q->V, slot_shift) + (1ULL << slot_shift);
if (!qfq_gt(cl->F, q->V) || qfq_gt(roundedF, limit)) {
mask = mask_from(q->bitmaps[ER], cl->grp->index);
if (mask) {
struct qfq_group *next = qfq_ffs(q, mask);
if (qfq_gt(roundedF, next->F)) {
cl->S = next->F;
return;
}
}
cl->S = q->V;
} else
cl->S = cl->F;
}
static int qfq_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_group *grp;
struct qfq_class *cl;
int err;
u64 roundedS;
int s;
cl = qfq_classify(skb, sch, &err);
if (cl == NULL) {
if (err & __NET_XMIT_BYPASS)
sch->qstats.drops++;
kfree_skb(skb);
return err;
}
pr_debug("qfq_enqueue: cl = %x\n", cl->common.classid);
err = qdisc_enqueue(skb, cl->qdisc);
if (unlikely(err != NET_XMIT_SUCCESS)) {
pr_debug("qfq_enqueue: enqueue failed %d\n", err);
if (net_xmit_drop_count(err)) {
cl->qstats.drops++;
sch->qstats.drops++;
}
return err;
}
bstats_update(&cl->bstats, skb);
++sch->q.qlen;
if (cl->qdisc->q.qlen != 1)
return err;
grp = cl->grp;
qfq_update_start(q, cl);
cl->F = cl->S + (u64)qdisc_pkt_len(skb) * cl->inv_w;
roundedS = qfq_round_down(cl->S, grp->slot_shift);
if (grp->full_slots) {
if (!qfq_gt(grp->S, cl->S))
goto skip_update;
qfq_slot_rotate(grp, roundedS);
__clear_bit(grp->index, &q->bitmaps[IR]);
__clear_bit(grp->index, &q->bitmaps[IB]);
} else if (!q->bitmaps[ER] && qfq_gt(roundedS, q->V))
q->V = roundedS;
grp->S = roundedS;
grp->F = roundedS + (2ULL << grp->slot_shift);
s = qfq_calc_state(q, grp);
__set_bit(grp->index, &q->bitmaps[s]);
pr_debug("qfq enqueue: new state %d %#lx S %lld F %lld V %lld\n",
s, q->bitmaps[s],
(unsigned long long) cl->S,
(unsigned long long) cl->F,
(unsigned long long) q->V);
skip_update:
qfq_slot_insert(grp, cl, roundedS);
return err;
}
static void qfq_slot_remove(struct qfq_sched *q, struct qfq_group *grp,
struct qfq_class *cl)
{
unsigned int i, offset;
u64 roundedS;
roundedS = qfq_round_down(cl->S, grp->slot_shift);
offset = (roundedS - grp->S) >> grp->slot_shift;
i = (grp->front + offset) % QFQ_MAX_SLOTS;
hlist_del(&cl->next);
if (hlist_empty(&grp->slots[i]))
__clear_bit(offset, &grp->full_slots);
}
static void qfq_deactivate_class(struct qfq_sched *q, struct qfq_class *cl)
{
struct qfq_group *grp = cl->grp;
unsigned long mask;
u64 roundedS;
int s;
cl->F = cl->S;
qfq_slot_remove(q, grp, cl);
if (!grp->full_slots) {
__clear_bit(grp->index, &q->bitmaps[IR]);
__clear_bit(grp->index, &q->bitmaps[EB]);
__clear_bit(grp->index, &q->bitmaps[IB]);
if (test_bit(grp->index, &q->bitmaps[ER]) &&
!(q->bitmaps[ER] & ~((1UL << grp->index) - 1))) {
mask = q->bitmaps[ER] & ((1UL << grp->index) - 1);
if (mask)
mask = ~((1UL << __fls(mask)) - 1);
else
mask = ~0UL;
qfq_move_groups(q, mask, EB, ER);
qfq_move_groups(q, mask, IB, IR);
}
__clear_bit(grp->index, &q->bitmaps[ER]);
} else if (hlist_empty(&grp->slots[grp->front])) {
cl = qfq_slot_scan(grp);
roundedS = qfq_round_down(cl->S, grp->slot_shift);
if (grp->S != roundedS) {
__clear_bit(grp->index, &q->bitmaps[ER]);
__clear_bit(grp->index, &q->bitmaps[IR]);
__clear_bit(grp->index, &q->bitmaps[EB]);
__clear_bit(grp->index, &q->bitmaps[IB]);
grp->S = roundedS;
grp->F = roundedS + (2ULL << grp->slot_shift);
s = qfq_calc_state(q, grp);
__set_bit(grp->index, &q->bitmaps[s]);
}
}
qfq_update_eligible(q, q->V);
}
static void qfq_qlen_notify(struct Qdisc *sch, unsigned long arg)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl = (struct qfq_class *)arg;
if (cl->qdisc->q.qlen == 0)
qfq_deactivate_class(q, cl);
}
static unsigned int qfq_drop(struct Qdisc *sch)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_group *grp;
unsigned int i, j, len;
for (i = 0; i <= QFQ_MAX_INDEX; i++) {
grp = &q->groups[i];
for (j = 0; j < QFQ_MAX_SLOTS; j++) {
struct qfq_class *cl;
struct hlist_node *n;
hlist_for_each_entry(cl, n, &grp->slots[j], next) {
if (!cl->qdisc->ops->drop)
continue;
len = cl->qdisc->ops->drop(cl->qdisc);
if (len > 0) {
sch->q.qlen--;
if (!cl->qdisc->q.qlen)
qfq_deactivate_class(q, cl);
return len;
}
}
}
}
return 0;
}
static int qfq_init_qdisc(struct Qdisc *sch, struct nlattr *opt)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_group *grp;
int i, j, err;
err = qdisc_class_hash_init(&q->clhash);
if (err < 0)
return err;
for (i = 0; i <= QFQ_MAX_INDEX; i++) {
grp = &q->groups[i];
grp->index = i;
grp->slot_shift = QFQ_MTU_SHIFT + FRAC_BITS
- (QFQ_MAX_INDEX - i);
for (j = 0; j < QFQ_MAX_SLOTS; j++)
INIT_HLIST_HEAD(&grp->slots[j]);
}
return 0;
}
static void qfq_reset_qdisc(struct Qdisc *sch)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_group *grp;
struct qfq_class *cl;
struct hlist_node *n, *tmp;
unsigned int i, j;
for (i = 0; i <= QFQ_MAX_INDEX; i++) {
grp = &q->groups[i];
for (j = 0; j < QFQ_MAX_SLOTS; j++) {
hlist_for_each_entry_safe(cl, n, tmp,
&grp->slots[j], next) {
qfq_deactivate_class(q, cl);
}
}
}
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry(cl, n, &q->clhash.hash[i], common.hnode)
qdisc_reset(cl->qdisc);
}
sch->q.qlen = 0;
}
static void qfq_destroy_qdisc(struct Qdisc *sch)
{
struct qfq_sched *q = qdisc_priv(sch);
struct qfq_class *cl;
struct hlist_node *n, *next;
unsigned int i;
tcf_destroy_chain(&q->filter_list);
for (i = 0; i < q->clhash.hashsize; i++) {
hlist_for_each_entry_safe(cl, n, next, &q->clhash.hash[i],
common.hnode) {
qfq_destroy_class(sch, cl);
}
}
qdisc_class_hash_destroy(&q->clhash);
}
static int __init qfq_init(void)
{
return register_qdisc(&qfq_qdisc_ops);
}
static void __exit qfq_exit(void)
{
unregister_qdisc(&qfq_qdisc_ops);
}
