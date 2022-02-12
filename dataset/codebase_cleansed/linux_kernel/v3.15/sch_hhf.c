static u32 hhf_time_stamp(void)
{
return jiffies;
}
static unsigned int skb_hash(const struct hhf_sched_data *q,
const struct sk_buff *skb)
{
struct flow_keys keys;
unsigned int hash;
if (skb->sk && skb->sk->sk_hash)
return skb->sk->sk_hash;
skb_flow_dissect(skb, &keys);
hash = jhash_3words((__force u32)keys.dst,
(__force u32)keys.src ^ keys.ip_proto,
(__force u32)keys.ports, q->perturbation);
return hash;
}
static struct hh_flow_state *seek_list(const u32 hash,
struct list_head *head,
struct hhf_sched_data *q)
{
struct hh_flow_state *flow, *next;
u32 now = hhf_time_stamp();
if (list_empty(head))
return NULL;
list_for_each_entry_safe(flow, next, head, flowchain) {
u32 prev = flow->hit_timestamp + q->hhf_evict_timeout;
if (hhf_time_before(prev, now)) {
if (list_is_last(&flow->flowchain, head))
return NULL;
list_del(&flow->flowchain);
kfree(flow);
q->hh_flows_current_cnt--;
} else if (flow->hash_id == hash) {
return flow;
}
}
return NULL;
}
static struct hh_flow_state *alloc_new_hh(struct list_head *head,
struct hhf_sched_data *q)
{
struct hh_flow_state *flow;
u32 now = hhf_time_stamp();
if (!list_empty(head)) {
list_for_each_entry(flow, head, flowchain) {
u32 prev = flow->hit_timestamp + q->hhf_evict_timeout;
if (hhf_time_before(prev, now))
return flow;
}
}
if (q->hh_flows_current_cnt >= q->hh_flows_limit) {
q->hh_flows_overlimit++;
return NULL;
}
flow = kzalloc(sizeof(struct hh_flow_state), GFP_ATOMIC);
if (!flow)
return NULL;
q->hh_flows_current_cnt++;
INIT_LIST_HEAD(&flow->flowchain);
list_add_tail(&flow->flowchain, head);
return flow;
}
static enum wdrr_bucket_idx hhf_classify(struct sk_buff *skb, struct Qdisc *sch)
{
struct hhf_sched_data *q = qdisc_priv(sch);
u32 tmp_hash, hash;
u32 xorsum, filter_pos[HHF_ARRAYS_CNT], flow_pos;
struct hh_flow_state *flow;
u32 pkt_len, min_hhf_val;
int i;
u32 prev;
u32 now = hhf_time_stamp();
prev = q->hhf_arrays_reset_timestamp + q->hhf_reset_timeout;
if (hhf_time_before(prev, now)) {
for (i = 0; i < HHF_ARRAYS_CNT; i++)
bitmap_zero(q->hhf_valid_bits[i], HHF_ARRAYS_LEN);
q->hhf_arrays_reset_timestamp = now;
}
hash = skb_hash(q, skb);
flow_pos = hash & HHF_BIT_MASK;
flow = seek_list(hash, &q->hh_flows[flow_pos], q);
if (flow) {
flow->hit_timestamp = now;
return WDRR_BUCKET_FOR_HH;
}
tmp_hash = hash;
xorsum = 0;
for (i = 0; i < HHF_ARRAYS_CNT - 1; i++) {
filter_pos[i] = tmp_hash & HHF_BIT_MASK;
xorsum ^= filter_pos[i];
tmp_hash >>= HHF_BIT_MASK_LEN;
}
filter_pos[HHF_ARRAYS_CNT - 1] = xorsum ^ tmp_hash;
pkt_len = qdisc_pkt_len(skb);
min_hhf_val = ~0U;
for (i = 0; i < HHF_ARRAYS_CNT; i++) {
u32 val;
if (!test_bit(filter_pos[i], q->hhf_valid_bits[i])) {
q->hhf_arrays[i][filter_pos[i]] = 0;
__set_bit(filter_pos[i], q->hhf_valid_bits[i]);
}
val = q->hhf_arrays[i][filter_pos[i]] + pkt_len;
if (min_hhf_val > val)
min_hhf_val = val;
}
if (min_hhf_val > q->hhf_admit_bytes) {
flow = alloc_new_hh(&q->hh_flows[flow_pos], q);
if (!flow)
return WDRR_BUCKET_FOR_NON_HH;
flow->hash_id = hash;
flow->hit_timestamp = now;
q->hh_flows_total_cnt++;
return WDRR_BUCKET_FOR_HH;
}
for (i = 0; i < HHF_ARRAYS_CNT; i++) {
if (q->hhf_arrays[i][filter_pos[i]] < min_hhf_val)
q->hhf_arrays[i][filter_pos[i]] = min_hhf_val;
}
return WDRR_BUCKET_FOR_NON_HH;
}
static struct sk_buff *dequeue_head(struct wdrr_bucket *bucket)
{
struct sk_buff *skb = bucket->head;
bucket->head = skb->next;
skb->next = NULL;
return skb;
}
static void bucket_add(struct wdrr_bucket *bucket, struct sk_buff *skb)
{
if (bucket->head == NULL)
bucket->head = skb;
else
bucket->tail->next = skb;
bucket->tail = skb;
skb->next = NULL;
}
static unsigned int hhf_drop(struct Qdisc *sch)
{
struct hhf_sched_data *q = qdisc_priv(sch);
struct wdrr_bucket *bucket;
bucket = &q->buckets[WDRR_BUCKET_FOR_HH];
if (!bucket->head)
bucket = &q->buckets[WDRR_BUCKET_FOR_NON_HH];
if (bucket->head) {
struct sk_buff *skb = dequeue_head(bucket);
sch->q.qlen--;
sch->qstats.drops++;
sch->qstats.backlog -= qdisc_pkt_len(skb);
kfree_skb(skb);
}
return bucket - q->buckets;
}
static int hhf_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct hhf_sched_data *q = qdisc_priv(sch);
enum wdrr_bucket_idx idx;
struct wdrr_bucket *bucket;
idx = hhf_classify(skb, sch);
bucket = &q->buckets[idx];
bucket_add(bucket, skb);
sch->qstats.backlog += qdisc_pkt_len(skb);
if (list_empty(&bucket->bucketchain)) {
unsigned int weight;
if (idx == WDRR_BUCKET_FOR_HH) {
weight = 1;
list_add_tail(&bucket->bucketchain, &q->old_buckets);
} else {
weight = q->hhf_non_hh_weight;
list_add_tail(&bucket->bucketchain, &q->new_buckets);
}
bucket->deficit = weight * q->quantum;
}
if (++sch->q.qlen < sch->limit)
return NET_XMIT_SUCCESS;
q->drop_overlimit++;
if (hhf_drop(sch) == idx)
return NET_XMIT_CN;
qdisc_tree_decrease_qlen(sch, 1);
return NET_XMIT_SUCCESS;
}
static struct sk_buff *hhf_dequeue(struct Qdisc *sch)
{
struct hhf_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb = NULL;
struct wdrr_bucket *bucket;
struct list_head *head;
begin:
head = &q->new_buckets;
if (list_empty(head)) {
head = &q->old_buckets;
if (list_empty(head))
return NULL;
}
bucket = list_first_entry(head, struct wdrr_bucket, bucketchain);
if (bucket->deficit <= 0) {
int weight = (bucket - q->buckets == WDRR_BUCKET_FOR_HH) ?
1 : q->hhf_non_hh_weight;
bucket->deficit += weight * q->quantum;
list_move_tail(&bucket->bucketchain, &q->old_buckets);
goto begin;
}
if (bucket->head) {
skb = dequeue_head(bucket);
sch->q.qlen--;
sch->qstats.backlog -= qdisc_pkt_len(skb);
}
if (!skb) {
if ((head == &q->new_buckets) && !list_empty(&q->old_buckets))
list_move_tail(&bucket->bucketchain, &q->old_buckets);
else
list_del_init(&bucket->bucketchain);
goto begin;
}
qdisc_bstats_update(sch, skb);
bucket->deficit -= qdisc_pkt_len(skb);
return skb;
}
static void hhf_reset(struct Qdisc *sch)
{
struct sk_buff *skb;
while ((skb = hhf_dequeue(sch)) != NULL)
kfree_skb(skb);
}
static void *hhf_zalloc(size_t sz)
{
void *ptr = kzalloc(sz, GFP_KERNEL | __GFP_NOWARN);
if (!ptr)
ptr = vzalloc(sz);
return ptr;
}
static void hhf_free(void *addr)
{
if (addr) {
if (is_vmalloc_addr(addr))
vfree(addr);
else
kfree(addr);
}
}
static void hhf_destroy(struct Qdisc *sch)
{
int i;
struct hhf_sched_data *q = qdisc_priv(sch);
for (i = 0; i < HHF_ARRAYS_CNT; i++) {
hhf_free(q->hhf_arrays[i]);
hhf_free(q->hhf_valid_bits[i]);
}
for (i = 0; i < HH_FLOWS_CNT; i++) {
struct hh_flow_state *flow, *next;
struct list_head *head = &q->hh_flows[i];
if (list_empty(head))
continue;
list_for_each_entry_safe(flow, next, head, flowchain) {
list_del(&flow->flowchain);
kfree(flow);
}
}
hhf_free(q->hh_flows);
}
static int hhf_change(struct Qdisc *sch, struct nlattr *opt)
{
struct hhf_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_HHF_MAX + 1];
unsigned int qlen;
int err;
u64 non_hh_quantum;
u32 new_quantum = q->quantum;
u32 new_hhf_non_hh_weight = q->hhf_non_hh_weight;
if (!opt)
return -EINVAL;
err = nla_parse_nested(tb, TCA_HHF_MAX, opt, hhf_policy);
if (err < 0)
return err;
if (tb[TCA_HHF_QUANTUM])
new_quantum = nla_get_u32(tb[TCA_HHF_QUANTUM]);
if (tb[TCA_HHF_NON_HH_WEIGHT])
new_hhf_non_hh_weight = nla_get_u32(tb[TCA_HHF_NON_HH_WEIGHT]);
non_hh_quantum = (u64)new_quantum * new_hhf_non_hh_weight;
if (non_hh_quantum > INT_MAX)
return -EINVAL;
sch_tree_lock(sch);
if (tb[TCA_HHF_BACKLOG_LIMIT])
sch->limit = nla_get_u32(tb[TCA_HHF_BACKLOG_LIMIT]);
q->quantum = new_quantum;
q->hhf_non_hh_weight = new_hhf_non_hh_weight;
if (tb[TCA_HHF_HH_FLOWS_LIMIT])
q->hh_flows_limit = nla_get_u32(tb[TCA_HHF_HH_FLOWS_LIMIT]);
if (tb[TCA_HHF_RESET_TIMEOUT]) {
u32 us = nla_get_u32(tb[TCA_HHF_RESET_TIMEOUT]);
q->hhf_reset_timeout = usecs_to_jiffies(us);
}
if (tb[TCA_HHF_ADMIT_BYTES])
q->hhf_admit_bytes = nla_get_u32(tb[TCA_HHF_ADMIT_BYTES]);
if (tb[TCA_HHF_EVICT_TIMEOUT]) {
u32 us = nla_get_u32(tb[TCA_HHF_EVICT_TIMEOUT]);
q->hhf_evict_timeout = usecs_to_jiffies(us);
}
qlen = sch->q.qlen;
while (sch->q.qlen > sch->limit) {
struct sk_buff *skb = hhf_dequeue(sch);
kfree_skb(skb);
}
qdisc_tree_decrease_qlen(sch, qlen - sch->q.qlen);
sch_tree_unlock(sch);
return 0;
}
static int hhf_init(struct Qdisc *sch, struct nlattr *opt)
{
struct hhf_sched_data *q = qdisc_priv(sch);
int i;
sch->limit = 1000;
q->quantum = psched_mtu(qdisc_dev(sch));
q->perturbation = prandom_u32();
INIT_LIST_HEAD(&q->new_buckets);
INIT_LIST_HEAD(&q->old_buckets);
q->hhf_reset_timeout = HZ / 25;
q->hhf_admit_bytes = 131072;
q->hhf_evict_timeout = HZ;
q->hhf_non_hh_weight = 2;
if (opt) {
int err = hhf_change(sch, opt);
if (err)
return err;
}
if (!q->hh_flows) {
q->hh_flows = hhf_zalloc(HH_FLOWS_CNT *
sizeof(struct list_head));
if (!q->hh_flows)
return -ENOMEM;
for (i = 0; i < HH_FLOWS_CNT; i++)
INIT_LIST_HEAD(&q->hh_flows[i]);
q->hh_flows_limit = 2 * HH_FLOWS_CNT;
q->hh_flows_overlimit = 0;
q->hh_flows_total_cnt = 0;
q->hh_flows_current_cnt = 0;
for (i = 0; i < HHF_ARRAYS_CNT; i++) {
q->hhf_arrays[i] = hhf_zalloc(HHF_ARRAYS_LEN *
sizeof(u32));
if (!q->hhf_arrays[i]) {
hhf_destroy(sch);
return -ENOMEM;
}
}
q->hhf_arrays_reset_timestamp = hhf_time_stamp();
for (i = 0; i < HHF_ARRAYS_CNT; i++) {
q->hhf_valid_bits[i] = hhf_zalloc(HHF_ARRAYS_LEN /
BITS_PER_BYTE);
if (!q->hhf_valid_bits[i]) {
hhf_destroy(sch);
return -ENOMEM;
}
}
for (i = 0; i < WDRR_BUCKET_CNT; i++) {
struct wdrr_bucket *bucket = q->buckets + i;
INIT_LIST_HEAD(&bucket->bucketchain);
}
}
return 0;
}
static int hhf_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct hhf_sched_data *q = qdisc_priv(sch);
struct nlattr *opts;
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, TCA_HHF_BACKLOG_LIMIT, sch->limit) ||
nla_put_u32(skb, TCA_HHF_QUANTUM, q->quantum) ||
nla_put_u32(skb, TCA_HHF_HH_FLOWS_LIMIT, q->hh_flows_limit) ||
nla_put_u32(skb, TCA_HHF_RESET_TIMEOUT,
jiffies_to_usecs(q->hhf_reset_timeout)) ||
nla_put_u32(skb, TCA_HHF_ADMIT_BYTES, q->hhf_admit_bytes) ||
nla_put_u32(skb, TCA_HHF_EVICT_TIMEOUT,
jiffies_to_usecs(q->hhf_evict_timeout)) ||
nla_put_u32(skb, TCA_HHF_NON_HH_WEIGHT, q->hhf_non_hh_weight))
goto nla_put_failure;
return nla_nest_end(skb, opts);
nla_put_failure:
return -1;
}
static int hhf_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct hhf_sched_data *q = qdisc_priv(sch);
struct tc_hhf_xstats st = {
.drop_overlimit = q->drop_overlimit,
.hh_overlimit = q->hh_flows_overlimit,
.hh_tot_count = q->hh_flows_total_cnt,
.hh_cur_count = q->hh_flows_current_cnt,
};
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static int __init hhf_module_init(void)
{
return register_qdisc(&hhf_qdisc_ops);
}
static void __exit hhf_module_exit(void)
{
unregister_qdisc(&hhf_qdisc_ops);
}
