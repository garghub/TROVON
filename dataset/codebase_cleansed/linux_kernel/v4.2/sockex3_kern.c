static inline void parse_eth_proto(struct __sk_buff *skb, u32 proto)
{
switch (proto) {
case ETH_P_8021Q:
case ETH_P_8021AD:
bpf_tail_call(skb, &jmp_table, PARSE_VLAN);
break;
case ETH_P_MPLS_UC:
case ETH_P_MPLS_MC:
bpf_tail_call(skb, &jmp_table, PARSE_MPLS);
break;
case ETH_P_IP:
bpf_tail_call(skb, &jmp_table, PARSE_IP);
break;
case ETH_P_IPV6:
bpf_tail_call(skb, &jmp_table, PARSE_IPV6);
break;
}
}
static inline int ip_is_fragment(struct __sk_buff *ctx, __u64 nhoff)
{
return load_half(ctx, nhoff + offsetof(struct iphdr, frag_off))
& (IP_MF | IP_OFFSET);
}
static inline __u32 ipv6_addr_hash(struct __sk_buff *ctx, __u64 off)
{
__u64 w0 = load_word(ctx, off);
__u64 w1 = load_word(ctx, off + 4);
__u64 w2 = load_word(ctx, off + 8);
__u64 w3 = load_word(ctx, off + 12);
return (__u32)(w0 ^ w1 ^ w2 ^ w3);
}
static struct globals *this_cpu_globals(void)
{
u32 key = bpf_get_smp_processor_id();
return bpf_map_lookup_elem(&percpu_map, &key);
}
static void update_stats(struct __sk_buff *skb, struct globals *g)
{
struct flow_keys key = g->flow;
struct pair *value;
value = bpf_map_lookup_elem(&hash_map, &key);
if (value) {
__sync_fetch_and_add(&value->packets, 1);
__sync_fetch_and_add(&value->bytes, skb->len);
} else {
struct pair val = {1, skb->len};
bpf_map_update_elem(&hash_map, &key, &val, BPF_ANY);
}
}
static __always_inline void parse_ip_proto(struct __sk_buff *skb,
struct globals *g, __u32 ip_proto)
{
__u32 nhoff = skb->cb[0];
int poff;
switch (ip_proto) {
case IPPROTO_GRE: {
struct gre_hdr {
__be16 flags;
__be16 proto;
};
__u32 gre_flags = load_half(skb,
nhoff + offsetof(struct gre_hdr, flags));
__u32 gre_proto = load_half(skb,
nhoff + offsetof(struct gre_hdr, proto));
if (gre_flags & (GRE_VERSION|GRE_ROUTING))
break;
nhoff += 4;
if (gre_flags & GRE_CSUM)
nhoff += 4;
if (gre_flags & GRE_KEY)
nhoff += 4;
if (gre_flags & GRE_SEQ)
nhoff += 4;
skb->cb[0] = nhoff;
parse_eth_proto(skb, gre_proto);
break;
}
case IPPROTO_IPIP:
parse_eth_proto(skb, ETH_P_IP);
break;
case IPPROTO_IPV6:
parse_eth_proto(skb, ETH_P_IPV6);
break;
case IPPROTO_TCP:
case IPPROTO_UDP:
g->flow.ports = load_word(skb, nhoff);
case IPPROTO_ICMP:
g->flow.ip_proto = ip_proto;
update_stats(skb, g);
break;
default:
break;
}
}
PROG(PARSE_IP)(struct __sk_buff *skb)
{
struct globals *g = this_cpu_globals();
__u32 nhoff, verlen, ip_proto;
if (!g)
return 0;
nhoff = skb->cb[0];
if (unlikely(ip_is_fragment(skb, nhoff)))
return 0;
ip_proto = load_byte(skb, nhoff + offsetof(struct iphdr, protocol));
if (ip_proto != IPPROTO_GRE) {
g->flow.src = load_word(skb, nhoff + offsetof(struct iphdr, saddr));
g->flow.dst = load_word(skb, nhoff + offsetof(struct iphdr, daddr));
}
verlen = load_byte(skb, nhoff + 0);
nhoff += (verlen & 0xF) << 2;
skb->cb[0] = nhoff;
parse_ip_proto(skb, g, ip_proto);
return 0;
}
PROG(PARSE_IPV6)(struct __sk_buff *skb)
{
struct globals *g = this_cpu_globals();
__u32 nhoff, ip_proto;
if (!g)
return 0;
nhoff = skb->cb[0];
ip_proto = load_byte(skb,
nhoff + offsetof(struct ipv6hdr, nexthdr));
g->flow.src = ipv6_addr_hash(skb,
nhoff + offsetof(struct ipv6hdr, saddr));
g->flow.dst = ipv6_addr_hash(skb,
nhoff + offsetof(struct ipv6hdr, daddr));
nhoff += sizeof(struct ipv6hdr);
skb->cb[0] = nhoff;
parse_ip_proto(skb, g, ip_proto);
return 0;
}
PROG(PARSE_VLAN)(struct __sk_buff *skb)
{
__u32 nhoff, proto;
nhoff = skb->cb[0];
proto = load_half(skb, nhoff + offsetof(struct vlan_hdr,
h_vlan_encapsulated_proto));
nhoff += sizeof(struct vlan_hdr);
skb->cb[0] = nhoff;
parse_eth_proto(skb, proto);
return 0;
}
PROG(PARSE_MPLS)(struct __sk_buff *skb)
{
__u32 nhoff, label;
nhoff = skb->cb[0];
label = load_word(skb, nhoff);
nhoff += sizeof(struct mpls_label);
skb->cb[0] = nhoff;
if (label & MPLS_LS_S_MASK) {
__u8 verlen = load_byte(skb, nhoff);
if ((verlen & 0xF0) == 4)
parse_eth_proto(skb, ETH_P_IP);
else
parse_eth_proto(skb, ETH_P_IPV6);
} else {
parse_eth_proto(skb, ETH_P_MPLS_UC);
}
return 0;
}
int main_prog(struct __sk_buff *skb)
{
__u32 nhoff = ETH_HLEN;
__u32 proto = load_half(skb, 12);
skb->cb[0] = nhoff;
parse_eth_proto(skb, proto);
return 0;
}
