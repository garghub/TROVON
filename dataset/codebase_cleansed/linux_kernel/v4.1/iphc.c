static int uncompress_addr(struct sk_buff *skb,
struct in6_addr *ipaddr, const u8 address_mode,
const u8 *lladdr, const u8 addr_type,
const u8 addr_len)
{
bool fail;
switch (address_mode) {
case LOWPAN_IPHC_ADDR_00:
fail = lowpan_fetch_skb(skb, ipaddr->s6_addr, 16);
break;
case LOWPAN_IPHC_ADDR_01:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[8], 8);
break;
case LOWPAN_IPHC_ADDR_02:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
ipaddr->s6_addr[11] = 0xFF;
ipaddr->s6_addr[12] = 0xFE;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[14], 2);
break;
case LOWPAN_IPHC_ADDR_03:
fail = false;
switch (addr_type) {
case IEEE802154_ADDR_LONG:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
memcpy(&ipaddr->s6_addr[8], lladdr, addr_len);
ipaddr->s6_addr[8] ^= 0x02;
break;
case IEEE802154_ADDR_SHORT:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
ipaddr->s6_addr[11] = 0xFF;
ipaddr->s6_addr[12] = 0xFE;
ipaddr->s6_addr16[7] = htons(*((u16 *)lladdr));
break;
default:
pr_debug("Invalid addr_type set\n");
return -EINVAL;
}
break;
default:
pr_debug("Invalid address mode value: 0x%x\n", address_mode);
return -EINVAL;
}
if (fail) {
pr_debug("Failed to fetch skb data\n");
return -EIO;
}
raw_dump_inline(NULL, "Reconstructed ipv6 addr is",
ipaddr->s6_addr, 16);
return 0;
}
static int uncompress_context_based_src_addr(struct sk_buff *skb,
struct in6_addr *ipaddr,
const u8 sam)
{
switch (sam) {
case LOWPAN_IPHC_ADDR_00:
break;
case LOWPAN_IPHC_ADDR_01:
case LOWPAN_IPHC_ADDR_02:
case LOWPAN_IPHC_ADDR_03:
netdev_warn(skb->dev, "SAM value 0x%x not supported\n", sam);
return -EINVAL;
default:
pr_debug("Invalid sam value: 0x%x\n", sam);
return -EINVAL;
}
raw_dump_inline(NULL,
"Reconstructed context based ipv6 src addr is",
ipaddr->s6_addr, 16);
return 0;
}
static int lowpan_uncompress_multicast_daddr(struct sk_buff *skb,
struct in6_addr *ipaddr,
const u8 dam)
{
bool fail;
switch (dam) {
case LOWPAN_IPHC_DAM_00:
fail = lowpan_fetch_skb(skb, ipaddr->s6_addr, 16);
break;
case LOWPAN_IPHC_DAM_01:
ipaddr->s6_addr[0] = 0xFF;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[1], 1);
fail |= lowpan_fetch_skb(skb, &ipaddr->s6_addr[11], 5);
break;
case LOWPAN_IPHC_DAM_10:
ipaddr->s6_addr[0] = 0xFF;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[1], 1);
fail |= lowpan_fetch_skb(skb, &ipaddr->s6_addr[13], 3);
break;
case LOWPAN_IPHC_DAM_11:
ipaddr->s6_addr[0] = 0xFF;
ipaddr->s6_addr[1] = 0x02;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[15], 1);
break;
default:
pr_debug("DAM value has a wrong value: 0x%x\n", dam);
return -EINVAL;
}
if (fail) {
pr_debug("Failed to fetch skb data\n");
return -EIO;
}
raw_dump_inline(NULL, "Reconstructed ipv6 multicast addr is",
ipaddr->s6_addr, 16);
return 0;
}
int
lowpan_header_decompress(struct sk_buff *skb, struct net_device *dev,
const u8 *saddr, const u8 saddr_type,
const u8 saddr_len, const u8 *daddr,
const u8 daddr_type, const u8 daddr_len,
u8 iphc0, u8 iphc1)
{
struct ipv6hdr hdr = {};
u8 tmp, num_context = 0;
int err;
raw_dump_table(__func__, "raw skb data dump uncompressed",
skb->data, skb->len);
if (iphc1 & LOWPAN_IPHC_CID) {
pr_debug("CID flag is set, increase header with one\n");
if (lowpan_fetch_skb(skb, &num_context, sizeof(num_context)))
return -EINVAL;
}
hdr.version = 6;
switch ((iphc0 & LOWPAN_IPHC_TF) >> 3) {
case 0:
if (lowpan_fetch_skb(skb, &tmp, sizeof(tmp)))
return -EINVAL;
memcpy(&hdr.flow_lbl, &skb->data[0], 3);
skb_pull(skb, 3);
hdr.priority = ((tmp >> 2) & 0x0f);
hdr.flow_lbl[0] = ((tmp >> 2) & 0x30) | (tmp << 6) |
(hdr.flow_lbl[0] & 0x0f);
break;
case 2:
if (lowpan_fetch_skb(skb, &tmp, sizeof(tmp)))
return -EINVAL;
hdr.priority = ((tmp >> 2) & 0x0f);
hdr.flow_lbl[0] = ((tmp << 6) & 0xC0) | ((tmp >> 2) & 0x30);
break;
case 1:
if (lowpan_fetch_skb(skb, &tmp, sizeof(tmp)))
return -EINVAL;
hdr.flow_lbl[0] = (skb->data[0] & 0x0F) | ((tmp >> 2) & 0x30);
memcpy(&hdr.flow_lbl[1], &skb->data[0], 2);
skb_pull(skb, 2);
break;
case 3:
break;
default:
break;
}
if ((iphc0 & LOWPAN_IPHC_NH_C) == 0) {
if (lowpan_fetch_skb(skb, &hdr.nexthdr, sizeof(hdr.nexthdr)))
return -EINVAL;
pr_debug("NH flag is set, next header carried inline: %02x\n",
hdr.nexthdr);
}
if ((iphc0 & 0x03) != LOWPAN_IPHC_TTL_I) {
hdr.hop_limit = lowpan_ttl_values[iphc0 & 0x03];
} else {
if (lowpan_fetch_skb(skb, &hdr.hop_limit,
sizeof(hdr.hop_limit)))
return -EINVAL;
}
tmp = ((iphc1 & LOWPAN_IPHC_SAM) >> LOWPAN_IPHC_SAM_BIT) & 0x03;
if (iphc1 & LOWPAN_IPHC_SAC) {
pr_debug("SAC bit is set. Handle context based source address.\n");
err = uncompress_context_based_src_addr(skb, &hdr.saddr, tmp);
} else {
pr_debug("source address stateless compression\n");
err = uncompress_addr(skb, &hdr.saddr, tmp, saddr,
saddr_type, saddr_len);
}
if (err)
return -EINVAL;
tmp = ((iphc1 & LOWPAN_IPHC_DAM_11) >> LOWPAN_IPHC_DAM_BIT) & 0x03;
if (iphc1 & LOWPAN_IPHC_M) {
if (iphc1 & LOWPAN_IPHC_DAC) {
pr_debug("dest: context-based mcast compression\n");
} else {
err = lowpan_uncompress_multicast_daddr(skb, &hdr.daddr,
tmp);
if (err)
return -EINVAL;
}
} else {
err = uncompress_addr(skb, &hdr.daddr, tmp, daddr,
daddr_type, daddr_len);
pr_debug("dest: stateless compression mode %d dest %pI6c\n",
tmp, &hdr.daddr);
if (err)
return -EINVAL;
}
if (iphc0 & LOWPAN_IPHC_NH_C) {
err = lowpan_nhc_do_uncompression(skb, dev, &hdr);
if (err < 0)
return err;
} else {
err = skb_cow(skb, sizeof(hdr));
if (unlikely(err))
return err;
}
hdr.payload_len = htons(skb->len);
pr_debug("skb headroom size = %d, data length = %d\n",
skb_headroom(skb), skb->len);
pr_debug("IPv6 header dump:\n\tversion = %d\n\tlength = %d\n\t"
"nexthdr = 0x%02x\n\thop_lim = %d\n\tdest = %pI6c\n",
hdr.version, ntohs(hdr.payload_len), hdr.nexthdr,
hdr.hop_limit, &hdr.daddr);
skb_push(skb, sizeof(hdr));
skb_reset_network_header(skb);
skb_copy_to_linear_data(skb, &hdr, sizeof(hdr));
raw_dump_table(__func__, "raw header dump", (u8 *)&hdr, sizeof(hdr));
return 0;
}
static u8 lowpan_compress_addr_64(u8 **hc_ptr, u8 shift,
const struct in6_addr *ipaddr,
const unsigned char *lladdr)
{
u8 val = 0;
if (is_addr_mac_addr_based(ipaddr, lladdr)) {
val = 3;
pr_debug("address compression 0 bits\n");
} else if (lowpan_is_iid_16_bit_compressable(ipaddr)) {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr16[7], 2);
val = 2;
raw_dump_inline(NULL, "Compressed ipv6 addr is (16 bits)",
*hc_ptr - 2, 2);
} else {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr16[4], 8);
val = 1;
raw_dump_inline(NULL, "Compressed ipv6 addr is (64 bits)",
*hc_ptr - 8, 8);
}
return rol8(val, shift);
}
int lowpan_header_compress(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *_daddr,
const void *_saddr, unsigned int len)
{
u8 tmp, iphc0, iphc1, *hc_ptr;
struct ipv6hdr *hdr;
u8 head[100] = {};
int ret, addr_type;
if (type != ETH_P_IPV6)
return -EINVAL;
hdr = ipv6_hdr(skb);
hc_ptr = head + 2;
pr_debug("IPv6 header dump:\n\tversion = %d\n\tlength = %d\n"
"\tnexthdr = 0x%02x\n\thop_lim = %d\n\tdest = %pI6c\n",
hdr->version, ntohs(hdr->payload_len), hdr->nexthdr,
hdr->hop_limit, &hdr->daddr);
raw_dump_table(__func__, "raw skb network header dump",
skb_network_header(skb), sizeof(struct ipv6hdr));
iphc0 = LOWPAN_DISPATCH_IPHC;
iphc1 = 0;
raw_dump_inline(__func__, "saddr",
(unsigned char *)_saddr, IEEE802154_ADDR_LEN);
raw_dump_inline(__func__, "daddr",
(unsigned char *)_daddr, IEEE802154_ADDR_LEN);
raw_dump_table(__func__, "sending raw skb network uncompressed packet",
skb->data, skb->len);
tmp = (hdr->priority << 4) | (hdr->flow_lbl[0] >> 4);
tmp = ((tmp & 0x03) << 6) | (tmp >> 2);
if (((hdr->flow_lbl[0] & 0x0F) == 0) &&
(hdr->flow_lbl[1] == 0) && (hdr->flow_lbl[2] == 0)) {
iphc0 |= LOWPAN_IPHC_FL_C;
if ((hdr->priority == 0) &&
((hdr->flow_lbl[0] & 0xF0) == 0)) {
iphc0 |= LOWPAN_IPHC_TC_C;
} else {
*hc_ptr = tmp;
hc_ptr += 1;
}
} else {
if ((hdr->priority == 0) &&
((hdr->flow_lbl[0] & 0xF0) == 0)) {
iphc0 |= LOWPAN_IPHC_TC_C;
*hc_ptr = (tmp & 0xc0) | (hdr->flow_lbl[0] & 0x0F);
memcpy(hc_ptr + 1, &hdr->flow_lbl[1], 2);
hc_ptr += 3;
} else {
memcpy(hc_ptr, hdr, 4);
*hc_ptr = tmp;
hc_ptr += 4;
}
}
ret = lowpan_nhc_check_compression(skb, hdr, &hc_ptr, &iphc0);
if (ret < 0)
return ret;
switch (hdr->hop_limit) {
case 1:
iphc0 |= LOWPAN_IPHC_TTL_1;
break;
case 64:
iphc0 |= LOWPAN_IPHC_TTL_64;
break;
case 255:
iphc0 |= LOWPAN_IPHC_TTL_255;
break;
default:
lowpan_push_hc_data(&hc_ptr, &hdr->hop_limit,
sizeof(hdr->hop_limit));
}
addr_type = ipv6_addr_type(&hdr->saddr);
if (addr_type == IPV6_ADDR_ANY) {
pr_debug("source address is unspecified, setting SAC\n");
iphc1 |= LOWPAN_IPHC_SAC;
} else {
if (addr_type & IPV6_ADDR_LINKLOCAL) {
iphc1 |= lowpan_compress_addr_64(&hc_ptr,
LOWPAN_IPHC_SAM_BIT,
&hdr->saddr, _saddr);
pr_debug("source address unicast link-local %pI6c iphc1 0x%02x\n",
&hdr->saddr, iphc1);
} else {
pr_debug("send the full source address\n");
lowpan_push_hc_data(&hc_ptr, hdr->saddr.s6_addr, 16);
}
}
addr_type = ipv6_addr_type(&hdr->daddr);
if (addr_type & IPV6_ADDR_MULTICAST) {
pr_debug("destination address is multicast: ");
iphc1 |= LOWPAN_IPHC_M;
if (lowpan_is_mcast_addr_compressable8(&hdr->daddr)) {
pr_debug("compressed to 1 octet\n");
iphc1 |= LOWPAN_IPHC_DAM_11;
lowpan_push_hc_data(&hc_ptr,
&hdr->daddr.s6_addr[15], 1);
} else if (lowpan_is_mcast_addr_compressable32(&hdr->daddr)) {
pr_debug("compressed to 4 octets\n");
iphc1 |= LOWPAN_IPHC_DAM_10;
lowpan_push_hc_data(&hc_ptr,
&hdr->daddr.s6_addr[1], 1);
lowpan_push_hc_data(&hc_ptr,
&hdr->daddr.s6_addr[13], 3);
} else if (lowpan_is_mcast_addr_compressable48(&hdr->daddr)) {
pr_debug("compressed to 6 octets\n");
iphc1 |= LOWPAN_IPHC_DAM_01;
lowpan_push_hc_data(&hc_ptr,
&hdr->daddr.s6_addr[1], 1);
lowpan_push_hc_data(&hc_ptr,
&hdr->daddr.s6_addr[11], 5);
} else {
pr_debug("using full address\n");
iphc1 |= LOWPAN_IPHC_DAM_00;
lowpan_push_hc_data(&hc_ptr, hdr->daddr.s6_addr, 16);
}
} else {
if (addr_type & IPV6_ADDR_LINKLOCAL) {
iphc1 |= lowpan_compress_addr_64(&hc_ptr,
LOWPAN_IPHC_DAM_BIT, &hdr->daddr, _daddr);
pr_debug("dest address unicast link-local %pI6c "
"iphc1 0x%02x\n", &hdr->daddr, iphc1);
} else {
pr_debug("dest address unicast %pI6c\n", &hdr->daddr);
lowpan_push_hc_data(&hc_ptr, hdr->daddr.s6_addr, 16);
}
}
if (iphc0 & LOWPAN_IPHC_NH_C) {
ret = lowpan_nhc_do_compression(skb, hdr, &hc_ptr);
if (ret < 0)
return ret;
}
head[0] = iphc0;
head[1] = iphc1;
skb_pull(skb, sizeof(struct ipv6hdr));
skb_reset_transport_header(skb);
memcpy(skb_push(skb, hc_ptr - head), head, hc_ptr - head);
skb_reset_network_header(skb);
pr_debug("header len %d skb %u\n", (int)(hc_ptr - head), skb->len);
raw_dump_table(__func__, "raw skb data dump compressed",
skb->data, skb->len);
return 0;
}
static int __init lowpan_module_init(void)
{
request_module_nowait("nhc_dest");
request_module_nowait("nhc_fragment");
request_module_nowait("nhc_hop");
request_module_nowait("nhc_ipv6");
request_module_nowait("nhc_mobility");
request_module_nowait("nhc_routing");
request_module_nowait("nhc_udp");
return 0;
}
