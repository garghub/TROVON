static int parse_ipv4(void *data, u64 nh_off, void *data_end)
{
struct iphdr *iph = data + nh_off;
if (iph + 1 > data_end)
return 0;
return iph->protocol;
}
static int parse_ipv6(void *data, u64 nh_off, void *data_end)
{
struct ipv6hdr *ip6h = data + nh_off;
if (ip6h + 1 > data_end)
return 0;
return ip6h->nexthdr;
}
int xdp_prog1(struct xdp_md *ctx)
{
void *data_end = (void *)(long)ctx->data_end;
void *data = (void *)(long)ctx->data;
struct ethhdr *eth = data;
int rc = XDP_DROP;
long *value;
u16 h_proto;
u64 nh_off;
u32 ipproto;
nh_off = sizeof(*eth);
if (data + nh_off > data_end)
return rc;
h_proto = eth->h_proto;
if (h_proto == htons(ETH_P_8021Q) || h_proto == htons(ETH_P_8021AD)) {
struct vlan_hdr *vhdr;
vhdr = data + nh_off;
nh_off += sizeof(struct vlan_hdr);
if (data + nh_off > data_end)
return rc;
h_proto = vhdr->h_vlan_encapsulated_proto;
}
if (h_proto == htons(ETH_P_8021Q) || h_proto == htons(ETH_P_8021AD)) {
struct vlan_hdr *vhdr;
vhdr = data + nh_off;
nh_off += sizeof(struct vlan_hdr);
if (data + nh_off > data_end)
return rc;
h_proto = vhdr->h_vlan_encapsulated_proto;
}
if (h_proto == htons(ETH_P_IP))
ipproto = parse_ipv4(data, nh_off, data_end);
else if (h_proto == htons(ETH_P_IPV6))
ipproto = parse_ipv6(data, nh_off, data_end);
else
ipproto = 0;
value = bpf_map_lookup_elem(&rxcnt, &ipproto);
if (value)
*value += 1;
return rc;
}
