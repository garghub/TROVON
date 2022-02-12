static unsigned int
nfqueue_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_NFQ_info *tinfo = par->targinfo;
return NF_QUEUE_NR(tinfo->queuenum);
}
static u32 hash_v4(const struct sk_buff *skb)
{
const struct iphdr *iph = ip_hdr(skb);
if ((__force u32)iph->saddr < (__force u32)iph->daddr)
return jhash_3words((__force u32)iph->saddr,
(__force u32)iph->daddr, iph->protocol, jhash_initval);
return jhash_3words((__force u32)iph->daddr,
(__force u32)iph->saddr, iph->protocol, jhash_initval);
}
static u32 hash_v6(const struct sk_buff *skb)
{
const struct ipv6hdr *ip6h = ipv6_hdr(skb);
u32 a, b, c;
if ((__force u32)ip6h->saddr.s6_addr32[3] <
(__force u32)ip6h->daddr.s6_addr32[3]) {
a = (__force u32) ip6h->saddr.s6_addr32[3];
b = (__force u32) ip6h->daddr.s6_addr32[3];
} else {
b = (__force u32) ip6h->saddr.s6_addr32[3];
a = (__force u32) ip6h->daddr.s6_addr32[3];
}
if ((__force u32)ip6h->saddr.s6_addr32[1] <
(__force u32)ip6h->daddr.s6_addr32[1])
c = (__force u32) ip6h->saddr.s6_addr32[1];
else
c = (__force u32) ip6h->daddr.s6_addr32[1];
return jhash_3words(a, b, c, jhash_initval);
}
static u32
nfqueue_hash(const struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_NFQ_info_v1 *info = par->targinfo;
u32 queue = info->queuenum;
if (par->family == NFPROTO_IPV4)
queue += ((u64) hash_v4(skb) * info->queues_total) >> 32;
#if IS_ENABLED(CONFIG_IP6_NF_IPTABLES)
else if (par->family == NFPROTO_IPV6)
queue += ((u64) hash_v6(skb) * info->queues_total) >> 32;
#endif
return queue;
}
static unsigned int
nfqueue_tg_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_NFQ_info_v1 *info = par->targinfo;
u32 queue = info->queuenum;
if (info->queues_total > 1)
queue = nfqueue_hash(skb, par);
return NF_QUEUE_NR(queue);
}
static unsigned int
nfqueue_tg_v2(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_NFQ_info_v2 *info = par->targinfo;
unsigned int ret = nfqueue_tg_v1(skb, par);
if (info->bypass)
ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;
return ret;
}
static int nfqueue_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_NFQ_info_v3 *info = par->targinfo;
u32 maxid;
if (unlikely(!rnd_inited)) {
get_random_bytes(&jhash_initval, sizeof(jhash_initval));
rnd_inited = true;
}
if (info->queues_total == 0) {
pr_err("NFQUEUE: number of total queues is 0\n");
return -EINVAL;
}
maxid = info->queues_total - 1 + info->queuenum;
if (maxid > 0xffff) {
pr_err("NFQUEUE: number of queues (%u) out of range (got %u)\n",
info->queues_total, maxid);
return -ERANGE;
}
if (par->target->revision == 2 && info->flags > 1)
return -EINVAL;
if (par->target->revision == 3 && info->flags & ~NFQ_FLAG_MASK)
return -EINVAL;
return 0;
}
static unsigned int
nfqueue_tg_v3(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_NFQ_info_v3 *info = par->targinfo;
u32 queue = info->queuenum;
if (info->queues_total > 1) {
if (info->flags & NFQ_FLAG_CPU_FANOUT) {
int cpu = smp_processor_id();
queue = info->queuenum + cpu % info->queues_total;
} else
queue = nfqueue_hash(skb, par);
}
return NF_QUEUE_NR(queue);
}
static int __init nfqueue_tg_init(void)
{
return xt_register_targets(nfqueue_tg_reg, ARRAY_SIZE(nfqueue_tg_reg));
}
static void __exit nfqueue_tg_exit(void)
{
xt_unregister_targets(nfqueue_tg_reg, ARRAY_SIZE(nfqueue_tg_reg));
}
