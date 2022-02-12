static inline int ip_is_fragment(struct __sk_buff *ctx, __u64 nhoff)
{
return load_half(ctx, nhoff + offsetof(struct iphdr, frag_off))
& (IP_MF | IP_OFFSET);
}
int handle_ingress(struct __sk_buff *skb)
{
__u64 troff = ETH_HLEN + sizeof(struct iphdr);
if (load_half(skb, offsetof(struct ethhdr, h_proto)) != ETH_P_IP)
return 0;
if (load_byte(skb, ETH_HLEN + offsetof(struct iphdr, protocol)) != IPPROTO_UDP ||
load_byte(skb, ETH_HLEN) != 0x45)
return 0;
if (ip_is_fragment(skb, ETH_HLEN))
return 0;
if (load_half(skb, troff + offsetof(struct udphdr, dest)) == DEFAULT_PKTGEN_UDP_PORT)
return TC_ACT_SHOT;
return 0;
}
