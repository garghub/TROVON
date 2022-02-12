static inline struct sfb_skb_cb *sfb_skb_cb(const struct sk_buff *skb)
{
qdisc_cb_private_validate(skb, sizeof(struct sfb_skb_cb));
return (struct sfb_skb_cb *)qdisc_skb_cb(skb)->data;
}
static u32 sfb_hash(const struct sk_buff *skb, u32 slot)
{
return sfb_skb_cb(skb)->hashes[slot];
}
static u32 prob_plus(u32 p1, u32 p2)
{
u32 res = p1 + p2;
return min_t(u32, res, SFB_MAX_PROB);
}
static u32 prob_minus(u32 p1, u32 p2)
{
return p1 > p2 ? p1 - p2 : 0;
}
static void increment_one_qlen(u32 sfbhash, u32 slot, struct sfb_sched_data *q)
{
int i;
struct sfb_bucket *b = &q->bins[slot].bins[0][0];
for (i = 0; i < SFB_LEVELS; i++) {
u32 hash = sfbhash & SFB_BUCKET_MASK;
sfbhash >>= SFB_BUCKET_SHIFT;
if (b[hash].qlen < 0xFFFF)
b[hash].qlen++;
b += SFB_NUMBUCKETS;
}
}
static void increment_qlen(const struct sk_buff *skb, struct sfb_sched_data *q)
{
u32 sfbhash;
sfbhash = sfb_hash(skb, 0);
if (sfbhash)
increment_one_qlen(sfbhash, 0, q);
sfbhash = sfb_hash(skb, 1);
if (sfbhash)
increment_one_qlen(sfbhash, 1, q);
}
static void decrement_one_qlen(u32 sfbhash, u32 slot,
struct sfb_sched_data *q)
{
int i;
struct sfb_bucket *b = &q->bins[slot].bins[0][0];
for (i = 0; i < SFB_LEVELS; i++) {
u32 hash = sfbhash & SFB_BUCKET_MASK;
sfbhash >>= SFB_BUCKET_SHIFT;
if (b[hash].qlen > 0)
b[hash].qlen--;
b += SFB_NUMBUCKETS;
}
}
static void decrement_qlen(const struct sk_buff *skb, struct sfb_sched_data *q)
{
u32 sfbhash;
sfbhash = sfb_hash(skb, 0);
if (sfbhash)
decrement_one_qlen(sfbhash, 0, q);
sfbhash = sfb_hash(skb, 1);
if (sfbhash)
decrement_one_qlen(sfbhash, 1, q);
}
static void decrement_prob(struct sfb_bucket *b, struct sfb_sched_data *q)
{
b->p_mark = prob_minus(b->p_mark, q->decrement);
}
static void increment_prob(struct sfb_bucket *b, struct sfb_sched_data *q)
{
b->p_mark = prob_plus(b->p_mark, q->increment);
}
static void sfb_zero_all_buckets(struct sfb_sched_data *q)
{
memset(&q->bins, 0, sizeof(q->bins));
}
static u32 sfb_compute_qlen(u32 *prob_r, u32 *avgpm_r, const struct sfb_sched_data *q)
{
int i;
u32 qlen = 0, prob = 0, totalpm = 0;
const struct sfb_bucket *b = &q->bins[q->slot].bins[0][0];
for (i = 0; i < SFB_LEVELS * SFB_NUMBUCKETS; i++) {
if (qlen < b->qlen)
qlen = b->qlen;
totalpm += b->p_mark;
if (prob < b->p_mark)
prob = b->p_mark;
b++;
}
*prob_r = prob;
*avgpm_r = totalpm / (SFB_LEVELS * SFB_NUMBUCKETS);
return qlen;
}
static void sfb_init_perturbation(u32 slot, struct sfb_sched_data *q)
{
q->bins[slot].perturbation = prandom_u32();
}
static void sfb_swap_slot(struct sfb_sched_data *q)
{
sfb_init_perturbation(q->slot, q);
q->slot ^= 1;
q->double_buffering = false;
}
static bool sfb_rate_limit(struct sk_buff *skb, struct sfb_sched_data *q)
{
if (q->penalty_rate == 0 || q->penalty_burst == 0)
return true;
if (q->tokens_avail < 1) {
unsigned long age = min(10UL * HZ, jiffies - q->token_time);
q->tokens_avail = (age * q->penalty_rate) / HZ;
if (q->tokens_avail > q->penalty_burst)
q->tokens_avail = q->penalty_burst;
q->token_time = jiffies;
if (q->tokens_avail < 1)
return true;
}
q->tokens_avail--;
return false;
}
static bool sfb_classify(struct sk_buff *skb, struct tcf_proto *fl,
int *qerr, u32 *salt)
{
struct tcf_result res;
int result;
result = tc_classify(skb, fl, &res, false);
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
*salt = TC_H_MIN(res.classid);
return true;
}
return false;
}
static int sfb_enqueue(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
struct tcf_proto *fl;
int i;
u32 p_min = ~0;
u32 minqlen = ~0;
u32 r, sfbhash;
u32 slot = q->slot;
int ret = NET_XMIT_SUCCESS | __NET_XMIT_BYPASS;
if (unlikely(sch->q.qlen >= q->limit)) {
qdisc_qstats_overlimit(sch);
q->stats.queuedrop++;
goto drop;
}
if (q->rehash_interval > 0) {
unsigned long limit = q->rehash_time + q->rehash_interval;
if (unlikely(time_after(jiffies, limit))) {
sfb_swap_slot(q);
q->rehash_time = jiffies;
} else if (unlikely(!q->double_buffering && q->warmup_time > 0 &&
time_after(jiffies, limit - q->warmup_time))) {
q->double_buffering = true;
}
}
fl = rcu_dereference_bh(q->filter_list);
if (fl) {
u32 salt;
if (!sfb_classify(skb, fl, &ret, &salt))
goto other_drop;
sfbhash = jhash_1word(salt, q->bins[slot].perturbation);
} else {
sfbhash = skb_get_hash_perturb(skb, q->bins[slot].perturbation);
}
if (!sfbhash)
sfbhash = 1;
sfb_skb_cb(skb)->hashes[slot] = sfbhash;
for (i = 0; i < SFB_LEVELS; i++) {
u32 hash = sfbhash & SFB_BUCKET_MASK;
struct sfb_bucket *b = &q->bins[slot].bins[i][hash];
sfbhash >>= SFB_BUCKET_SHIFT;
if (b->qlen == 0)
decrement_prob(b, q);
else if (b->qlen >= q->bin_size)
increment_prob(b, q);
if (minqlen > b->qlen)
minqlen = b->qlen;
if (p_min > b->p_mark)
p_min = b->p_mark;
}
slot ^= 1;
sfb_skb_cb(skb)->hashes[slot] = 0;
if (unlikely(minqlen >= q->max)) {
qdisc_qstats_overlimit(sch);
q->stats.bucketdrop++;
goto drop;
}
if (unlikely(p_min >= SFB_MAX_PROB)) {
if (q->double_buffering) {
sfbhash = skb_get_hash_perturb(skb,
q->bins[slot].perturbation);
if (!sfbhash)
sfbhash = 1;
sfb_skb_cb(skb)->hashes[slot] = sfbhash;
for (i = 0; i < SFB_LEVELS; i++) {
u32 hash = sfbhash & SFB_BUCKET_MASK;
struct sfb_bucket *b = &q->bins[slot].bins[i][hash];
sfbhash >>= SFB_BUCKET_SHIFT;
if (b->qlen == 0)
decrement_prob(b, q);
else if (b->qlen >= q->bin_size)
increment_prob(b, q);
}
}
if (sfb_rate_limit(skb, q)) {
qdisc_qstats_overlimit(sch);
q->stats.penaltydrop++;
goto drop;
}
goto enqueue;
}
r = prandom_u32() & SFB_MAX_PROB;
if (unlikely(r < p_min)) {
if (unlikely(p_min > SFB_MAX_PROB / 2)) {
if (r < (p_min - SFB_MAX_PROB / 2) * 2) {
q->stats.earlydrop++;
goto drop;
}
}
if (INET_ECN_set_ce(skb)) {
q->stats.marked++;
} else {
q->stats.earlydrop++;
goto drop;
}
}
enqueue:
ret = qdisc_enqueue(skb, child, to_free);
if (likely(ret == NET_XMIT_SUCCESS)) {
qdisc_qstats_backlog_inc(sch, skb);
sch->q.qlen++;
increment_qlen(skb, q);
} else if (net_xmit_drop_count(ret)) {
q->stats.childdrop++;
qdisc_qstats_drop(sch);
}
return ret;
drop:
qdisc_drop(skb, sch, to_free);
return NET_XMIT_CN;
other_drop:
if (ret & __NET_XMIT_BYPASS)
qdisc_qstats_drop(sch);
kfree_skb(skb);
return ret;
}
static struct sk_buff *sfb_dequeue(struct Qdisc *sch)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
struct sk_buff *skb;
skb = child->dequeue(q->qdisc);
if (skb) {
qdisc_bstats_update(sch, skb);
qdisc_qstats_backlog_dec(sch, skb);
sch->q.qlen--;
decrement_qlen(skb, q);
}
return skb;
}
static struct sk_buff *sfb_peek(struct Qdisc *sch)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
return child->ops->peek(child);
}
static void sfb_reset(struct Qdisc *sch)
{
struct sfb_sched_data *q = qdisc_priv(sch);
qdisc_reset(q->qdisc);
sch->qstats.backlog = 0;
sch->q.qlen = 0;
q->slot = 0;
q->double_buffering = false;
sfb_zero_all_buckets(q);
sfb_init_perturbation(0, q);
}
static void sfb_destroy(struct Qdisc *sch)
{
struct sfb_sched_data *q = qdisc_priv(sch);
tcf_destroy_chain(&q->filter_list);
qdisc_destroy(q->qdisc);
}
static int sfb_change(struct Qdisc *sch, struct nlattr *opt)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct Qdisc *child;
struct nlattr *tb[TCA_SFB_MAX + 1];
const struct tc_sfb_qopt *ctl = &sfb_default_ops;
u32 limit;
int err;
if (opt) {
err = nla_parse_nested(tb, TCA_SFB_MAX, opt, sfb_policy);
if (err < 0)
return -EINVAL;
if (tb[TCA_SFB_PARMS] == NULL)
return -EINVAL;
ctl = nla_data(tb[TCA_SFB_PARMS]);
}
limit = ctl->limit;
if (limit == 0)
limit = qdisc_dev(sch)->tx_queue_len;
child = fifo_create_dflt(sch, &pfifo_qdisc_ops, limit);
if (IS_ERR(child))
return PTR_ERR(child);
sch_tree_lock(sch);
qdisc_tree_reduce_backlog(q->qdisc, q->qdisc->q.qlen,
q->qdisc->qstats.backlog);
qdisc_destroy(q->qdisc);
q->qdisc = child;
q->rehash_interval = msecs_to_jiffies(ctl->rehash_interval);
q->warmup_time = msecs_to_jiffies(ctl->warmup_time);
q->rehash_time = jiffies;
q->limit = limit;
q->increment = ctl->increment;
q->decrement = ctl->decrement;
q->max = ctl->max;
q->bin_size = ctl->bin_size;
q->penalty_rate = ctl->penalty_rate;
q->penalty_burst = ctl->penalty_burst;
q->tokens_avail = ctl->penalty_burst;
q->token_time = jiffies;
q->slot = 0;
q->double_buffering = false;
sfb_zero_all_buckets(q);
sfb_init_perturbation(0, q);
sfb_init_perturbation(1, q);
sch_tree_unlock(sch);
return 0;
}
static int sfb_init(struct Qdisc *sch, struct nlattr *opt)
{
struct sfb_sched_data *q = qdisc_priv(sch);
q->qdisc = &noop_qdisc;
return sfb_change(sch, opt);
}
static int sfb_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct nlattr *opts;
struct tc_sfb_qopt opt = {
.rehash_interval = jiffies_to_msecs(q->rehash_interval),
.warmup_time = jiffies_to_msecs(q->warmup_time),
.limit = q->limit,
.max = q->max,
.bin_size = q->bin_size,
.increment = q->increment,
.decrement = q->decrement,
.penalty_rate = q->penalty_rate,
.penalty_burst = q->penalty_burst,
};
sch->qstats.backlog = q->qdisc->qstats.backlog;
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
if (nla_put(skb, TCA_SFB_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
return nla_nest_end(skb, opts);
nla_put_failure:
nla_nest_cancel(skb, opts);
return -EMSGSIZE;
}
static int sfb_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct sfb_sched_data *q = qdisc_priv(sch);
struct tc_sfb_xstats st = {
.earlydrop = q->stats.earlydrop,
.penaltydrop = q->stats.penaltydrop,
.bucketdrop = q->stats.bucketdrop,
.queuedrop = q->stats.queuedrop,
.childdrop = q->stats.childdrop,
.marked = q->stats.marked,
};
st.maxqlen = sfb_compute_qlen(&st.maxprob, &st.avgprob, q);
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static int sfb_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
return -ENOSYS;
}
static int sfb_graft(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct sfb_sched_data *q = qdisc_priv(sch);
if (new == NULL)
new = &noop_qdisc;
*old = qdisc_replace(sch, new, &q->qdisc);
return 0;
}
static struct Qdisc *sfb_leaf(struct Qdisc *sch, unsigned long arg)
{
struct sfb_sched_data *q = qdisc_priv(sch);
return q->qdisc;
}
static unsigned long sfb_get(struct Qdisc *sch, u32 classid)
{
return 1;
}
static void sfb_put(struct Qdisc *sch, unsigned long arg)
{
}
static int sfb_change_class(struct Qdisc *sch, u32 classid, u32 parentid,
struct nlattr **tca, unsigned long *arg)
{
return -ENOSYS;
}
static int sfb_delete(struct Qdisc *sch, unsigned long cl)
{
return -ENOSYS;
}
static void sfb_walk(struct Qdisc *sch, struct qdisc_walker *walker)
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
static struct tcf_proto __rcu **sfb_find_tcf(struct Qdisc *sch,
unsigned long cl)
{
struct sfb_sched_data *q = qdisc_priv(sch);
if (cl)
return NULL;
return &q->filter_list;
}
static unsigned long sfb_bind(struct Qdisc *sch, unsigned long parent,
u32 classid)
{
return 0;
}
static int __init sfb_module_init(void)
{
return register_qdisc(&sfb_qdisc_ops);
}
static void __exit sfb_module_exit(void)
{
unregister_qdisc(&sfb_qdisc_ops);
}
