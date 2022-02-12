static bool dissector_uses_key(const struct flow_dissector *flow_dissector,
enum flow_dissector_key_id key_id)
{
return flow_dissector->used_keys & (1 << key_id);
}
static void dissector_set_key(struct flow_dissector *flow_dissector,
enum flow_dissector_key_id key_id)
{
flow_dissector->used_keys |= (1 << key_id);
}
static void *skb_flow_dissector_target(struct flow_dissector *flow_dissector,
enum flow_dissector_key_id key_id,
void *target_container)
{
return ((char *) target_container) + flow_dissector->offset[key_id];
}
void skb_flow_dissector_init(struct flow_dissector *flow_dissector,
const struct flow_dissector_key *key,
unsigned int key_count)
{
unsigned int i;
memset(flow_dissector, 0, sizeof(*flow_dissector));
for (i = 0; i < key_count; i++, key++) {
BUG_ON(key->offset > USHRT_MAX);
BUG_ON(dissector_uses_key(flow_dissector,
key->key_id));
dissector_set_key(flow_dissector, key->key_id);
flow_dissector->offset[key->key_id] = key->offset;
}
BUG_ON(!dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_CONTROL));
BUG_ON(!dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_BASIC));
}
__be32 __skb_flow_get_ports(const struct sk_buff *skb, int thoff, u8 ip_proto,
void *data, int hlen)
{
int poff = proto_ports_offset(ip_proto);
if (!data) {
data = skb->data;
hlen = skb_headlen(skb);
}
if (poff >= 0) {
__be32 *ports, _ports;
ports = __skb_header_pointer(skb, thoff + poff,
sizeof(_ports), data, hlen, &_ports);
if (ports)
return *ports;
}
return 0;
}
bool __skb_flow_dissect(const struct sk_buff *skb,
struct flow_dissector *flow_dissector,
void *target_container,
void *data, __be16 proto, int nhoff, int hlen,
unsigned int flags)
{
struct flow_dissector_key_control *key_control;
struct flow_dissector_key_basic *key_basic;
struct flow_dissector_key_addrs *key_addrs;
struct flow_dissector_key_ports *key_ports;
struct flow_dissector_key_tags *key_tags;
struct flow_dissector_key_keyid *key_keyid;
u8 ip_proto = 0;
bool ret = false;
if (!data) {
data = skb->data;
proto = skb->protocol;
nhoff = skb_network_offset(skb);
hlen = skb_headlen(skb);
}
key_control = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_CONTROL,
target_container);
key_basic = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_BASIC,
target_container);
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_ETH_ADDRS)) {
struct ethhdr *eth = eth_hdr(skb);
struct flow_dissector_key_eth_addrs *key_eth_addrs;
key_eth_addrs = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_ETH_ADDRS,
target_container);
memcpy(key_eth_addrs, &eth->h_dest, sizeof(*key_eth_addrs));
}
again:
switch (proto) {
case htons(ETH_P_IP): {
const struct iphdr *iph;
struct iphdr _iph;
ip:
iph = __skb_header_pointer(skb, nhoff, sizeof(_iph), data, hlen, &_iph);
if (!iph || iph->ihl < 5)
goto out_bad;
nhoff += iph->ihl * 4;
ip_proto = iph->protocol;
if (!dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_IPV4_ADDRS))
break;
key_addrs = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_IPV4_ADDRS, target_container);
memcpy(&key_addrs->v4addrs, &iph->saddr,
sizeof(key_addrs->v4addrs));
key_control->addr_type = FLOW_DISSECTOR_KEY_IPV4_ADDRS;
if (ip_is_fragment(iph)) {
key_control->flags |= FLOW_DIS_IS_FRAGMENT;
if (iph->frag_off & htons(IP_OFFSET)) {
goto out_good;
} else {
key_control->flags |= FLOW_DIS_FIRST_FRAG;
if (!(flags & FLOW_DISSECTOR_F_PARSE_1ST_FRAG))
goto out_good;
}
}
if (flags & FLOW_DISSECTOR_F_STOP_AT_L3)
goto out_good;
break;
}
case htons(ETH_P_IPV6): {
const struct ipv6hdr *iph;
struct ipv6hdr _iph;
__be32 flow_label;
ipv6:
iph = __skb_header_pointer(skb, nhoff, sizeof(_iph), data, hlen, &_iph);
if (!iph)
goto out_bad;
ip_proto = iph->nexthdr;
nhoff += sizeof(struct ipv6hdr);
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_IPV6_ADDRS)) {
struct flow_dissector_key_ipv6_addrs *key_ipv6_addrs;
key_ipv6_addrs = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_IPV6_ADDRS,
target_container);
memcpy(key_ipv6_addrs, &iph->saddr, sizeof(*key_ipv6_addrs));
key_control->addr_type = FLOW_DISSECTOR_KEY_IPV6_ADDRS;
}
flow_label = ip6_flowlabel(iph);
if (flow_label) {
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_FLOW_LABEL)) {
key_tags = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_FLOW_LABEL,
target_container);
key_tags->flow_label = ntohl(flow_label);
}
if (flags & FLOW_DISSECTOR_F_STOP_AT_FLOW_LABEL)
goto out_good;
}
if (flags & FLOW_DISSECTOR_F_STOP_AT_L3)
goto out_good;
break;
}
case htons(ETH_P_8021AD):
case htons(ETH_P_8021Q): {
const struct vlan_hdr *vlan;
struct vlan_hdr _vlan;
vlan = __skb_header_pointer(skb, nhoff, sizeof(_vlan), data, hlen, &_vlan);
if (!vlan)
goto out_bad;
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_VLANID)) {
key_tags = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_VLANID,
target_container);
key_tags->vlan_id = skb_vlan_tag_get_id(skb);
}
proto = vlan->h_vlan_encapsulated_proto;
nhoff += sizeof(*vlan);
goto again;
}
case htons(ETH_P_PPP_SES): {
struct {
struct pppoe_hdr hdr;
__be16 proto;
} *hdr, _hdr;
hdr = __skb_header_pointer(skb, nhoff, sizeof(_hdr), data, hlen, &_hdr);
if (!hdr)
goto out_bad;
proto = hdr->proto;
nhoff += PPPOE_SES_HLEN;
switch (proto) {
case htons(PPP_IP):
goto ip;
case htons(PPP_IPV6):
goto ipv6;
default:
goto out_bad;
}
}
case htons(ETH_P_TIPC): {
struct {
__be32 pre[3];
__be32 srcnode;
} *hdr, _hdr;
hdr = __skb_header_pointer(skb, nhoff, sizeof(_hdr), data, hlen, &_hdr);
if (!hdr)
goto out_bad;
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_TIPC_ADDRS)) {
key_addrs = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_TIPC_ADDRS,
target_container);
key_addrs->tipcaddrs.srcnode = hdr->srcnode;
key_control->addr_type = FLOW_DISSECTOR_KEY_TIPC_ADDRS;
}
goto out_good;
}
case htons(ETH_P_MPLS_UC):
case htons(ETH_P_MPLS_MC): {
struct mpls_label *hdr, _hdr[2];
mpls:
hdr = __skb_header_pointer(skb, nhoff, sizeof(_hdr), data,
hlen, &_hdr);
if (!hdr)
goto out_bad;
if ((ntohl(hdr[0].entry) & MPLS_LS_LABEL_MASK) >>
MPLS_LS_LABEL_SHIFT == MPLS_LABEL_ENTROPY) {
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_MPLS_ENTROPY)) {
key_keyid = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_MPLS_ENTROPY,
target_container);
key_keyid->keyid = hdr[1].entry &
htonl(MPLS_LS_LABEL_MASK);
}
goto out_good;
}
goto out_good;
}
case htons(ETH_P_FCOE):
key_control->thoff = (u16)(nhoff + FCOE_HEADER_LEN);
default:
goto out_bad;
}
ip_proto_again:
switch (ip_proto) {
case IPPROTO_GRE: {
struct gre_hdr {
__be16 flags;
__be16 proto;
} *hdr, _hdr;
hdr = __skb_header_pointer(skb, nhoff, sizeof(_hdr), data, hlen, &_hdr);
if (!hdr)
goto out_bad;
if (hdr->flags & (GRE_VERSION | GRE_ROUTING))
break;
proto = hdr->proto;
nhoff += 4;
if (hdr->flags & GRE_CSUM)
nhoff += 4;
if (hdr->flags & GRE_KEY) {
const __be32 *keyid;
__be32 _keyid;
keyid = __skb_header_pointer(skb, nhoff, sizeof(_keyid),
data, hlen, &_keyid);
if (!keyid)
goto out_bad;
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_GRE_KEYID)) {
key_keyid = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_GRE_KEYID,
target_container);
key_keyid->keyid = *keyid;
}
nhoff += 4;
}
if (hdr->flags & GRE_SEQ)
nhoff += 4;
if (proto == htons(ETH_P_TEB)) {
const struct ethhdr *eth;
struct ethhdr _eth;
eth = __skb_header_pointer(skb, nhoff,
sizeof(_eth),
data, hlen, &_eth);
if (!eth)
goto out_bad;
proto = eth->h_proto;
nhoff += sizeof(*eth);
}
key_control->flags |= FLOW_DIS_ENCAPSULATION;
if (flags & FLOW_DISSECTOR_F_STOP_AT_ENCAP)
goto out_good;
goto again;
}
case NEXTHDR_HOP:
case NEXTHDR_ROUTING:
case NEXTHDR_DEST: {
u8 _opthdr[2], *opthdr;
if (proto != htons(ETH_P_IPV6))
break;
opthdr = __skb_header_pointer(skb, nhoff, sizeof(_opthdr),
data, hlen, &_opthdr);
if (!opthdr)
goto out_bad;
ip_proto = opthdr[0];
nhoff += (opthdr[1] + 1) << 3;
goto ip_proto_again;
}
case NEXTHDR_FRAGMENT: {
struct frag_hdr _fh, *fh;
if (proto != htons(ETH_P_IPV6))
break;
fh = __skb_header_pointer(skb, nhoff, sizeof(_fh),
data, hlen, &_fh);
if (!fh)
goto out_bad;
key_control->flags |= FLOW_DIS_IS_FRAGMENT;
nhoff += sizeof(_fh);
if (!(fh->frag_off & htons(IP6_OFFSET))) {
key_control->flags |= FLOW_DIS_FIRST_FRAG;
if (flags & FLOW_DISSECTOR_F_PARSE_1ST_FRAG) {
ip_proto = fh->nexthdr;
goto ip_proto_again;
}
}
goto out_good;
}
case IPPROTO_IPIP:
proto = htons(ETH_P_IP);
key_control->flags |= FLOW_DIS_ENCAPSULATION;
if (flags & FLOW_DISSECTOR_F_STOP_AT_ENCAP)
goto out_good;
goto ip;
case IPPROTO_IPV6:
proto = htons(ETH_P_IPV6);
key_control->flags |= FLOW_DIS_ENCAPSULATION;
if (flags & FLOW_DISSECTOR_F_STOP_AT_ENCAP)
goto out_good;
goto ipv6;
case IPPROTO_MPLS:
proto = htons(ETH_P_MPLS_UC);
goto mpls;
default:
break;
}
if (dissector_uses_key(flow_dissector,
FLOW_DISSECTOR_KEY_PORTS)) {
key_ports = skb_flow_dissector_target(flow_dissector,
FLOW_DISSECTOR_KEY_PORTS,
target_container);
key_ports->ports = __skb_flow_get_ports(skb, nhoff, ip_proto,
data, hlen);
}
out_good:
ret = true;
out_bad:
key_basic->n_proto = proto;
key_basic->ip_proto = ip_proto;
key_control->thoff = (u16)nhoff;
return ret;
}
static __always_inline void __flow_hash_secret_init(void)
{
net_get_random_once(&hashrnd, sizeof(hashrnd));
}
static __always_inline u32 __flow_hash_words(const u32 *words, u32 length,
u32 keyval)
{
return jhash2(words, length, keyval);
}
static inline const u32 *flow_keys_hash_start(const struct flow_keys *flow)
{
const void *p = flow;
BUILD_BUG_ON(FLOW_KEYS_HASH_OFFSET % sizeof(u32));
return (const u32 *)(p + FLOW_KEYS_HASH_OFFSET);
}
static inline size_t flow_keys_hash_length(const struct flow_keys *flow)
{
size_t diff = FLOW_KEYS_HASH_OFFSET + sizeof(flow->addrs);
BUILD_BUG_ON((sizeof(*flow) - FLOW_KEYS_HASH_OFFSET) % sizeof(u32));
BUILD_BUG_ON(offsetof(typeof(*flow), addrs) !=
sizeof(*flow) - sizeof(flow->addrs));
switch (flow->control.addr_type) {
case FLOW_DISSECTOR_KEY_IPV4_ADDRS:
diff -= sizeof(flow->addrs.v4addrs);
break;
case FLOW_DISSECTOR_KEY_IPV6_ADDRS:
diff -= sizeof(flow->addrs.v6addrs);
break;
case FLOW_DISSECTOR_KEY_TIPC_ADDRS:
diff -= sizeof(flow->addrs.tipcaddrs);
break;
}
return (sizeof(*flow) - diff) / sizeof(u32);
}
__be32 flow_get_u32_src(const struct flow_keys *flow)
{
switch (flow->control.addr_type) {
case FLOW_DISSECTOR_KEY_IPV4_ADDRS:
return flow->addrs.v4addrs.src;
case FLOW_DISSECTOR_KEY_IPV6_ADDRS:
return (__force __be32)ipv6_addr_hash(
&flow->addrs.v6addrs.src);
case FLOW_DISSECTOR_KEY_TIPC_ADDRS:
return flow->addrs.tipcaddrs.srcnode;
default:
return 0;
}
}
__be32 flow_get_u32_dst(const struct flow_keys *flow)
{
switch (flow->control.addr_type) {
case FLOW_DISSECTOR_KEY_IPV4_ADDRS:
return flow->addrs.v4addrs.dst;
case FLOW_DISSECTOR_KEY_IPV6_ADDRS:
return (__force __be32)ipv6_addr_hash(
&flow->addrs.v6addrs.dst);
default:
return 0;
}
}
static inline void __flow_hash_consistentify(struct flow_keys *keys)
{
int addr_diff, i;
switch (keys->control.addr_type) {
case FLOW_DISSECTOR_KEY_IPV4_ADDRS:
addr_diff = (__force u32)keys->addrs.v4addrs.dst -
(__force u32)keys->addrs.v4addrs.src;
if ((addr_diff < 0) ||
(addr_diff == 0 &&
((__force u16)keys->ports.dst <
(__force u16)keys->ports.src))) {
swap(keys->addrs.v4addrs.src, keys->addrs.v4addrs.dst);
swap(keys->ports.src, keys->ports.dst);
}
break;
case FLOW_DISSECTOR_KEY_IPV6_ADDRS:
addr_diff = memcmp(&keys->addrs.v6addrs.dst,
&keys->addrs.v6addrs.src,
sizeof(keys->addrs.v6addrs.dst));
if ((addr_diff < 0) ||
(addr_diff == 0 &&
((__force u16)keys->ports.dst <
(__force u16)keys->ports.src))) {
for (i = 0; i < 4; i++)
swap(keys->addrs.v6addrs.src.s6_addr32[i],
keys->addrs.v6addrs.dst.s6_addr32[i]);
swap(keys->ports.src, keys->ports.dst);
}
break;
}
}
static inline u32 __flow_hash_from_keys(struct flow_keys *keys, u32 keyval)
{
u32 hash;
__flow_hash_consistentify(keys);
hash = __flow_hash_words(flow_keys_hash_start(keys),
flow_keys_hash_length(keys), keyval);
if (!hash)
hash = 1;
return hash;
}
u32 flow_hash_from_keys(struct flow_keys *keys)
{
__flow_hash_secret_init();
return __flow_hash_from_keys(keys, hashrnd);
}
static inline u32 ___skb_get_hash(const struct sk_buff *skb,
struct flow_keys *keys, u32 keyval)
{
skb_flow_dissect_flow_keys(skb, keys,
FLOW_DISSECTOR_F_STOP_AT_FLOW_LABEL);
return __flow_hash_from_keys(keys, keyval);
}
void make_flow_keys_digest(struct flow_keys_digest *digest,
const struct flow_keys *flow)
{
struct _flow_keys_digest_data *data =
(struct _flow_keys_digest_data *)digest;
BUILD_BUG_ON(sizeof(*data) > sizeof(*digest));
memset(digest, 0, sizeof(*digest));
data->n_proto = flow->basic.n_proto;
data->ip_proto = flow->basic.ip_proto;
data->ports = flow->ports.ports;
data->src = flow->addrs.v4addrs.src;
data->dst = flow->addrs.v4addrs.dst;
}
void __skb_get_hash(struct sk_buff *skb)
{
struct flow_keys keys;
__flow_hash_secret_init();
__skb_set_sw_hash(skb, ___skb_get_hash(skb, &keys, hashrnd),
flow_keys_have_l4(&keys));
}
__u32 skb_get_hash_perturb(const struct sk_buff *skb, u32 perturb)
{
struct flow_keys keys;
return ___skb_get_hash(skb, &keys, perturb);
}
__u32 __skb_get_hash_flowi6(struct sk_buff *skb, const struct flowi6 *fl6)
{
struct flow_keys keys;
memset(&keys, 0, sizeof(keys));
memcpy(&keys.addrs.v6addrs.src, &fl6->saddr,
sizeof(keys.addrs.v6addrs.src));
memcpy(&keys.addrs.v6addrs.dst, &fl6->daddr,
sizeof(keys.addrs.v6addrs.dst));
keys.control.addr_type = FLOW_DISSECTOR_KEY_IPV6_ADDRS;
keys.ports.src = fl6->fl6_sport;
keys.ports.dst = fl6->fl6_dport;
keys.keyid.keyid = fl6->fl6_gre_key;
keys.tags.flow_label = (__force u32)fl6->flowlabel;
keys.basic.ip_proto = fl6->flowi6_proto;
__skb_set_sw_hash(skb, flow_hash_from_keys(&keys),
flow_keys_have_l4(&keys));
return skb->hash;
}
__u32 __skb_get_hash_flowi4(struct sk_buff *skb, const struct flowi4 *fl4)
{
struct flow_keys keys;
memset(&keys, 0, sizeof(keys));
keys.addrs.v4addrs.src = fl4->saddr;
keys.addrs.v4addrs.dst = fl4->daddr;
keys.control.addr_type = FLOW_DISSECTOR_KEY_IPV4_ADDRS;
keys.ports.src = fl4->fl4_sport;
keys.ports.dst = fl4->fl4_dport;
keys.keyid.keyid = fl4->fl4_gre_key;
keys.basic.ip_proto = fl4->flowi4_proto;
__skb_set_sw_hash(skb, flow_hash_from_keys(&keys),
flow_keys_have_l4(&keys));
return skb->hash;
}
u32 __skb_get_poff(const struct sk_buff *skb, void *data,
const struct flow_keys *keys, int hlen)
{
u32 poff = keys->control.thoff;
switch (keys->basic.ip_proto) {
case IPPROTO_TCP: {
const u8 *doff;
u8 _doff;
doff = __skb_header_pointer(skb, poff + 12, sizeof(_doff),
data, hlen, &_doff);
if (!doff)
return poff;
poff += max_t(u32, sizeof(struct tcphdr), (*doff & 0xF0) >> 2);
break;
}
case IPPROTO_UDP:
case IPPROTO_UDPLITE:
poff += sizeof(struct udphdr);
break;
case IPPROTO_ICMP:
poff += sizeof(struct icmphdr);
break;
case IPPROTO_ICMPV6:
poff += sizeof(struct icmp6hdr);
break;
case IPPROTO_IGMP:
poff += sizeof(struct igmphdr);
break;
case IPPROTO_DCCP:
poff += sizeof(struct dccp_hdr);
break;
case IPPROTO_SCTP:
poff += sizeof(struct sctphdr);
break;
}
return poff;
}
u32 skb_get_poff(const struct sk_buff *skb)
{
struct flow_keys keys;
if (!skb_flow_dissect_flow_keys(skb, &keys, 0))
return 0;
return __skb_get_poff(skb, skb->data, &keys, skb_headlen(skb));
}
__u32 __get_hash_from_flowi6(const struct flowi6 *fl6, struct flow_keys *keys)
{
memset(keys, 0, sizeof(*keys));
memcpy(&keys->addrs.v6addrs.src, &fl6->saddr,
sizeof(keys->addrs.v6addrs.src));
memcpy(&keys->addrs.v6addrs.dst, &fl6->daddr,
sizeof(keys->addrs.v6addrs.dst));
keys->control.addr_type = FLOW_DISSECTOR_KEY_IPV6_ADDRS;
keys->ports.src = fl6->fl6_sport;
keys->ports.dst = fl6->fl6_dport;
keys->keyid.keyid = fl6->fl6_gre_key;
keys->tags.flow_label = (__force u32)fl6->flowlabel;
keys->basic.ip_proto = fl6->flowi6_proto;
return flow_hash_from_keys(keys);
}
__u32 __get_hash_from_flowi4(const struct flowi4 *fl4, struct flow_keys *keys)
{
memset(keys, 0, sizeof(*keys));
keys->addrs.v4addrs.src = fl4->saddr;
keys->addrs.v4addrs.dst = fl4->daddr;
keys->control.addr_type = FLOW_DISSECTOR_KEY_IPV4_ADDRS;
keys->ports.src = fl4->fl4_sport;
keys->ports.dst = fl4->fl4_dport;
keys->keyid.keyid = fl4->fl4_gre_key;
keys->basic.ip_proto = fl4->flowi4_proto;
return flow_hash_from_keys(keys);
}
static int __init init_default_flow_dissectors(void)
{
skb_flow_dissector_init(&flow_keys_dissector,
flow_keys_dissector_keys,
ARRAY_SIZE(flow_keys_dissector_keys));
skb_flow_dissector_init(&flow_keys_buf_dissector,
flow_keys_buf_dissector_keys,
ARRAY_SIZE(flow_keys_buf_dissector_keys));
return 0;
}
