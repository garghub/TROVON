static void fake_update_pmtu(struct dst_entry *dst, struct sock *sk,
struct sk_buff *skb, u32 mtu)
{
}
static void fake_redirect(struct dst_entry *dst, struct sock *sk,
struct sk_buff *skb)
{
}
static u32 *fake_cow_metrics(struct dst_entry *dst, unsigned long old)
{
return NULL;
}
static struct neighbour *fake_neigh_lookup(const struct dst_entry *dst,
struct sk_buff *skb,
const void *daddr)
{
return NULL;
}
static unsigned int fake_mtu(const struct dst_entry *dst)
{
return dst->dev->mtu;
}
void br_netfilter_rtable_init(struct net_bridge *br)
{
struct rtable *rt = &br->fake_rtable;
atomic_set(&rt->dst.__refcnt, 1);
rt->dst.dev = br->dev;
rt->dst.path = &rt->dst;
dst_init_metrics(&rt->dst, br_dst_default_metrics, true);
rt->dst.flags = DST_NOXFRM | DST_FAKE_RTABLE;
rt->dst.ops = &fake_dst_ops;
}
int __init br_nf_core_init(void)
{
return dst_entries_init(&fake_dst_ops);
}
void br_nf_core_fini(void)
{
dst_entries_destroy(&fake_dst_ops);
}
