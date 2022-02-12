int _gre_set_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
__builtin_memset(&key, 0x0, sizeof(key));
key.remote_ipv4 = 0xac100164;
key.tunnel_id = 2;
key.tunnel_tos = 0;
key.tunnel_ttl = 64;
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), BPF_F_ZERO_CSUM_TX);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _gre_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
char fmt[] = "key %d remote ip 0x%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), 0);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt), key.tunnel_id, key.remote_ipv4);
return TC_ACT_OK;
}
int _vxlan_set_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
struct vxlan_metadata md;
__builtin_memset(&key, 0x0, sizeof(key));
key.remote_ipv4 = 0xac100164;
key.tunnel_id = 2;
key.tunnel_tos = 0;
key.tunnel_ttl = 64;
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), BPF_F_ZERO_CSUM_TX);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
md.gbp = 0x800FF;
ret = bpf_skb_set_tunnel_opt(skb, &md, sizeof(md));
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _vxlan_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
struct vxlan_metadata md;
char fmt[] = "key %d remote ip 0x%x vxlan gbp 0x%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), 0);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
ret = bpf_skb_get_tunnel_opt(skb, &md, sizeof(md));
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt),
key.tunnel_id, key.remote_ipv4, md.gbp);
return TC_ACT_OK;
}
int _geneve_set_tunnel(struct __sk_buff *skb)
{
int ret, ret2;
struct bpf_tunnel_key key;
struct geneve_opt gopt;
__builtin_memset(&key, 0x0, sizeof(key));
key.remote_ipv4 = 0xac100164;
key.tunnel_id = 2;
key.tunnel_tos = 0;
key.tunnel_ttl = 64;
__builtin_memset(&gopt, 0x0, sizeof(gopt));
gopt.opt_class = 0x102;
gopt.type = 0x08;
gopt.r1 = 0;
gopt.r2 = 0;
gopt.r3 = 0;
gopt.length = 2;
*(int *) &gopt.opt_data = 0xdeadbeef;
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), BPF_F_ZERO_CSUM_TX);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
ret = bpf_skb_set_tunnel_opt(skb, &gopt, sizeof(gopt));
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _geneve_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
struct geneve_opt gopt;
char fmt[] = "key %d remote ip 0x%x geneve class 0x%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), 0);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
ret = bpf_skb_get_tunnel_opt(skb, &gopt, sizeof(gopt));
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt),
key.tunnel_id, key.remote_ipv4, gopt.opt_class);
return TC_ACT_OK;
}
int _ipip_set_tunnel(struct __sk_buff *skb)
{
struct bpf_tunnel_key key = {};
void *data = (void *)(long)skb->data;
struct iphdr *iph = data;
struct tcphdr *tcp = data + sizeof(*iph);
void *data_end = (void *)(long)skb->data_end;
int ret;
if (data + sizeof(*iph) + sizeof(*tcp) > data_end) {
ERROR(1);
return TC_ACT_SHOT;
}
key.tunnel_ttl = 64;
if (iph->protocol == IPPROTO_ICMP) {
key.remote_ipv4 = 0xac100164;
} else {
if (iph->protocol != IPPROTO_TCP || iph->ihl != 5)
return TC_ACT_SHOT;
if (tcp->dest == htons(5200))
key.remote_ipv4 = 0xac100164;
else if (tcp->dest == htons(5201))
key.remote_ipv4 = 0xac100165;
else
return TC_ACT_SHOT;
}
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), 0);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _ipip_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
char fmt[] = "remote ip 0x%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), 0);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt), key.remote_ipv4);
return TC_ACT_OK;
}
int _ipip6_set_tunnel(struct __sk_buff *skb)
{
struct bpf_tunnel_key key = {};
void *data = (void *)(long)skb->data;
struct iphdr *iph = data;
struct tcphdr *tcp = data + sizeof(*iph);
void *data_end = (void *)(long)skb->data_end;
int ret;
if (data + sizeof(*iph) + sizeof(*tcp) > data_end) {
ERROR(1);
return TC_ACT_SHOT;
}
key.remote_ipv6[0] = _htonl(0x2401db00);
key.tunnel_ttl = 64;
if (iph->protocol == IPPROTO_ICMP) {
key.remote_ipv6[3] = _htonl(1);
} else {
if (iph->protocol != IPPROTO_TCP || iph->ihl != 5) {
ERROR(iph->protocol);
return TC_ACT_SHOT;
}
if (tcp->dest == htons(5200)) {
key.remote_ipv6[3] = _htonl(1);
} else if (tcp->dest == htons(5201)) {
key.remote_ipv6[3] = _htonl(2);
} else {
ERROR(tcp->dest);
return TC_ACT_SHOT;
}
}
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), BPF_F_TUNINFO_IPV6);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _ipip6_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
char fmt[] = "remote ip6 %x::%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), BPF_F_TUNINFO_IPV6);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt), _htonl(key.remote_ipv6[0]),
_htonl(key.remote_ipv6[3]));
return TC_ACT_OK;
}
int _ip6ip6_set_tunnel(struct __sk_buff *skb)
{
struct bpf_tunnel_key key = {};
void *data = (void *)(long)skb->data;
struct ipv6hdr *iph = data;
struct tcphdr *tcp = data + sizeof(*iph);
void *data_end = (void *)(long)skb->data_end;
int ret;
if (data + sizeof(*iph) + sizeof(*tcp) > data_end) {
ERROR(1);
return TC_ACT_SHOT;
}
key.remote_ipv6[0] = _htonl(0x2401db00);
key.tunnel_ttl = 64;
if (iph->nexthdr == NEXTHDR_ICMP) {
key.remote_ipv6[3] = _htonl(1);
} else {
if (iph->nexthdr != NEXTHDR_TCP) {
ERROR(iph->nexthdr);
return TC_ACT_SHOT;
}
if (tcp->dest == htons(5200)) {
key.remote_ipv6[3] = _htonl(1);
} else if (tcp->dest == htons(5201)) {
key.remote_ipv6[3] = _htonl(2);
} else {
ERROR(tcp->dest);
return TC_ACT_SHOT;
}
}
ret = bpf_skb_set_tunnel_key(skb, &key, sizeof(key), BPF_F_TUNINFO_IPV6);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
return TC_ACT_OK;
}
int _ip6ip6_get_tunnel(struct __sk_buff *skb)
{
int ret;
struct bpf_tunnel_key key;
char fmt[] = "remote ip6 %x::%x\n";
ret = bpf_skb_get_tunnel_key(skb, &key, sizeof(key), BPF_F_TUNINFO_IPV6);
if (ret < 0) {
ERROR(ret);
return TC_ACT_SHOT;
}
bpf_trace_printk(fmt, sizeof(fmt), _htonl(key.remote_ipv6[0]),
_htonl(key.remote_ipv6[3]));
return TC_ACT_OK;
}
