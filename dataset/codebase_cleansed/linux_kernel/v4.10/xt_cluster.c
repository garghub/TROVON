static inline u32 nf_ct_orig_ipv4_src(const struct nf_conn *ct)
{
return (__force u32)ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip;
}
static inline const u32 *nf_ct_orig_ipv6_src(const struct nf_conn *ct)
{
return (__force u32 *)ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u3.ip6;
}
static inline u_int32_t
xt_cluster_hash_ipv4(u_int32_t ip, const struct xt_cluster_match_info *info)
{
return jhash_1word(ip, info->hash_seed);
}
static inline u_int32_t
xt_cluster_hash_ipv6(const void *ip, const struct xt_cluster_match_info *info)
{
return jhash2(ip, NF_CT_TUPLE_L3SIZE / sizeof(__u32), info->hash_seed);
}
static inline u_int32_t
xt_cluster_hash(const struct nf_conn *ct,
const struct xt_cluster_match_info *info)
{
u_int32_t hash = 0;
switch(nf_ct_l3num(ct)) {
case AF_INET:
hash = xt_cluster_hash_ipv4(nf_ct_orig_ipv4_src(ct), info);
break;
case AF_INET6:
hash = xt_cluster_hash_ipv6(nf_ct_orig_ipv6_src(ct), info);
break;
default:
WARN_ON(1);
break;
}
return reciprocal_scale(hash, info->total_nodes);
}
static inline bool
xt_cluster_ipv6_is_multicast(const struct in6_addr *addr)
{
__be32 st = addr->s6_addr32[0];
return ((st & htonl(0xFF000000)) == htonl(0xFF000000));
}
static inline bool
xt_cluster_is_multicast_addr(const struct sk_buff *skb, u_int8_t family)
{
bool is_multicast = false;
switch(family) {
case NFPROTO_IPV4:
is_multicast = ipv4_is_multicast(ip_hdr(skb)->daddr);
break;
case NFPROTO_IPV6:
is_multicast =
xt_cluster_ipv6_is_multicast(&ipv6_hdr(skb)->daddr);
break;
default:
WARN_ON(1);
break;
}
return is_multicast;
}
static bool
xt_cluster_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
struct sk_buff *pskb = (struct sk_buff *)skb;
const struct xt_cluster_match_info *info = par->matchinfo;
const struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
unsigned long hash;
if (!xt_cluster_is_multicast_addr(skb, xt_family(par)) &&
skb->pkt_type == PACKET_MULTICAST) {
pskb->pkt_type = PACKET_HOST;
}
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL)
return false;
if (nf_ct_is_untracked(ct))
return false;
if (ct->master)
hash = xt_cluster_hash(ct->master, info);
else
hash = xt_cluster_hash(ct, info);
return !!((1 << hash) & info->node_mask) ^
!!(info->flags & XT_CLUSTER_F_INV);
}
static int xt_cluster_mt_checkentry(const struct xt_mtchk_param *par)
{
struct xt_cluster_match_info *info = par->matchinfo;
if (info->total_nodes > XT_CLUSTER_NODES_MAX) {
pr_info("you have exceeded the maximum "
"number of cluster nodes (%u > %u)\n",
info->total_nodes, XT_CLUSTER_NODES_MAX);
return -EINVAL;
}
if (info->node_mask >= (1ULL << info->total_nodes)) {
pr_info("this node mask cannot be "
"higher than the total number of nodes\n");
return -EDOM;
}
return 0;
}
static int __init xt_cluster_mt_init(void)
{
return xt_register_match(&xt_cluster_match);
}
static void __exit xt_cluster_mt_fini(void)
{
xt_unregister_match(&xt_cluster_match);
}
