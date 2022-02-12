static __always_inline bool is_vip_addr(__be16 eth_proto, __be32 daddr)
{
if (eth_proto == htons(ETH_P_IP))
return (_htonl(0xffffff00) & daddr) == _htonl(0x0a0a0100);
else if (eth_proto == htons(ETH_P_IPV6))
return (daddr == _htonl(0x2401face));
return false;
}
int _l2_to_iptun_ingress_forward(struct __sk_buff *skb)
{
struct bpf_tunnel_key tkey = {};
void *data = (void *)(long)skb->data;
struct eth_hdr *eth = data;
void *data_end = (void *)(long)skb->data_end;
int key = 0, *ifindex;
int ret;
if (data + sizeof(*eth) > data_end)
return TC_ACT_OK;
ifindex = bpf_map_lookup_elem(&tun_iface, &key);
if (!ifindex)
return TC_ACT_OK;
if (eth->h_proto == htons(ETH_P_IP)) {
char fmt4[] = "ingress forward to ifindex:%d daddr4:%x\n";
struct iphdr *iph = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*iph) > data_end)
return TC_ACT_OK;
if (iph->protocol != IPPROTO_IPIP)
return TC_ACT_OK;
bpf_trace_printk(fmt4, sizeof(fmt4), *ifindex,
_htonl(iph->daddr));
return bpf_redirect(*ifindex, BPF_F_INGRESS);
} else if (eth->h_proto == htons(ETH_P_IPV6)) {
char fmt6[] = "ingress forward to ifindex:%d daddr6:%x::%x\n";
struct ipv6hdr *ip6h = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*ip6h) > data_end)
return TC_ACT_OK;
if (ip6h->nexthdr != IPPROTO_IPIP &&
ip6h->nexthdr != IPPROTO_IPV6)
return TC_ACT_OK;
bpf_trace_printk(fmt6, sizeof(fmt6), *ifindex,
_htonl(ip6h->daddr.s6_addr32[0]),
_htonl(ip6h->daddr.s6_addr32[3]));
return bpf_redirect(*ifindex, BPF_F_INGRESS);
}
return TC_ACT_OK;
}
int _l2_to_iptun_ingress_redirect(struct __sk_buff *skb)
{
struct bpf_tunnel_key tkey = {};
void *data = (void *)(long)skb->data;
struct eth_hdr *eth = data;
void *data_end = (void *)(long)skb->data_end;
int key = 0, *ifindex;
int ret;
if (data + sizeof(*eth) > data_end)
return TC_ACT_OK;
ifindex = bpf_map_lookup_elem(&tun_iface, &key);
if (!ifindex)
return TC_ACT_OK;
if (eth->h_proto == htons(ETH_P_IP)) {
char fmt4[] = "e/ingress redirect daddr4:%x to ifindex:%d\n";
struct iphdr *iph = data + sizeof(*eth);
__be32 daddr = iph->daddr;
if (data + sizeof(*eth) + sizeof(*iph) > data_end)
return TC_ACT_OK;
if (!is_vip_addr(eth->h_proto, daddr))
return TC_ACT_OK;
bpf_trace_printk(fmt4, sizeof(fmt4), _htonl(daddr), *ifindex);
} else {
return TC_ACT_OK;
}
tkey.tunnel_id = 10000;
tkey.tunnel_ttl = 64;
tkey.remote_ipv4 = 0x0a020166;
bpf_skb_set_tunnel_key(skb, &tkey, sizeof(tkey), 0);
return bpf_redirect(*ifindex, 0);
}
int _l2_to_ip6tun_ingress_redirect(struct __sk_buff *skb)
{
struct bpf_tunnel_key tkey = {};
void *data = (void *)(long)skb->data;
struct eth_hdr *eth = data;
void *data_end = (void *)(long)skb->data_end;
int key = 0, *ifindex;
if (data + sizeof(*eth) > data_end)
return TC_ACT_OK;
ifindex = bpf_map_lookup_elem(&tun_iface, &key);
if (!ifindex)
return TC_ACT_OK;
if (eth->h_proto == htons(ETH_P_IP)) {
char fmt4[] = "e/ingress redirect daddr4:%x to ifindex:%d\n";
struct iphdr *iph = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*iph) > data_end)
return TC_ACT_OK;
if (!is_vip_addr(eth->h_proto, iph->daddr))
return TC_ACT_OK;
bpf_trace_printk(fmt4, sizeof(fmt4), _htonl(iph->daddr),
*ifindex);
} else if (eth->h_proto == htons(ETH_P_IPV6)) {
char fmt6[] = "e/ingress redirect daddr6:%x to ifindex:%d\n";
struct ipv6hdr *ip6h = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*ip6h) > data_end)
return TC_ACT_OK;
if (!is_vip_addr(eth->h_proto, ip6h->daddr.s6_addr32[0]))
return TC_ACT_OK;
bpf_trace_printk(fmt6, sizeof(fmt6),
_htonl(ip6h->daddr.s6_addr32[0]), *ifindex);
} else {
return TC_ACT_OK;
}
tkey.tunnel_id = 10000;
tkey.tunnel_ttl = 64;
tkey.remote_ipv6[0] = _htonl(0x2401db02);
tkey.remote_ipv6[1] = 0;
tkey.remote_ipv6[2] = 0;
tkey.remote_ipv6[3] = _htonl(0x00000066);
bpf_skb_set_tunnel_key(skb, &tkey, sizeof(tkey), BPF_F_TUNINFO_IPV6);
return bpf_redirect(*ifindex, 0);
}
int _drop_non_tun_vip(struct __sk_buff *skb)
{
struct bpf_tunnel_key tkey = {};
void *data = (void *)(long)skb->data;
struct eth_hdr *eth = data;
void *data_end = (void *)(long)skb->data_end;
if (data + sizeof(*eth) > data_end)
return TC_ACT_OK;
if (eth->h_proto == htons(ETH_P_IP)) {
struct iphdr *iph = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*iph) > data_end)
return TC_ACT_OK;
if (is_vip_addr(eth->h_proto, iph->daddr))
return TC_ACT_SHOT;
} else if (eth->h_proto == htons(ETH_P_IPV6)) {
struct ipv6hdr *ip6h = data + sizeof(*eth);
if (data + sizeof(*eth) + sizeof(*ip6h) > data_end)
return TC_ACT_OK;
if (is_vip_addr(eth->h_proto, ip6h->daddr.s6_addr32[0]))
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
