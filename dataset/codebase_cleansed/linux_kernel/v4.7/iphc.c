static inline void
lowpan_iphc_uncompress_802154_lladdr(struct in6_addr *ipaddr,
const void *lladdr)
{
const struct ieee802154_addr *addr = lladdr;
u8 eui64[EUI64_ADDR_LEN];
switch (addr->mode) {
case IEEE802154_ADDR_LONG:
ieee802154_le64_to_be64(eui64, &addr->extended_addr);
lowpan_iphc_uncompress_eui64_lladdr(ipaddr, eui64);
break;
case IEEE802154_ADDR_SHORT:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
ipaddr->s6_addr[11] = 0xFF;
ipaddr->s6_addr[12] = 0xFE;
ieee802154_le16_to_be16(&ipaddr->s6_addr16[7],
&addr->short_addr);
break;
default:
WARN_ON_ONCE(1);
break;
}
}
static struct lowpan_iphc_ctx *
lowpan_iphc_ctx_get_by_id(const struct net_device *dev, u8 id)
{
struct lowpan_iphc_ctx *ret = &lowpan_dev(dev)->ctx.table[id];
if (!lowpan_iphc_ctx_is_active(ret))
return NULL;
return ret;
}
static struct lowpan_iphc_ctx *
lowpan_iphc_ctx_get_by_addr(const struct net_device *dev,
const struct in6_addr *addr)
{
struct lowpan_iphc_ctx *table = lowpan_dev(dev)->ctx.table;
struct lowpan_iphc_ctx *ret = NULL;
struct in6_addr addr_pfx;
u8 addr_plen;
int i;
for (i = 0; i < LOWPAN_IPHC_CTX_TABLE_SIZE; i++) {
if (!lowpan_iphc_ctx_is_active(&table[i]) ||
!lowpan_iphc_ctx_is_compression(&table[i]))
continue;
ipv6_addr_prefix(&addr_pfx, addr, table[i].plen);
if (table[i].plen < 64)
addr_plen = 64;
else
addr_plen = table[i].plen;
if (ipv6_prefix_equal(&addr_pfx, &table[i].pfx, addr_plen)) {
if (!ret) {
ret = &table[i];
continue;
}
if (table[i].plen > ret->plen)
ret = &table[i];
}
}
return ret;
}
static struct lowpan_iphc_ctx *
lowpan_iphc_ctx_get_by_mcast_addr(const struct net_device *dev,
const struct in6_addr *addr)
{
struct lowpan_iphc_ctx *table = lowpan_dev(dev)->ctx.table;
struct lowpan_iphc_ctx *ret = NULL;
struct in6_addr addr_mcast, network_pfx = {};
int i;
memcpy(&addr_mcast, addr, sizeof(*addr));
for (i = 0; i < LOWPAN_IPHC_CTX_TABLE_SIZE; i++) {
if (!lowpan_iphc_ctx_is_active(&table[i]) ||
!lowpan_iphc_ctx_is_compression(&table[i]))
continue;
addr_mcast.s6_addr[3] = table[i].plen;
ipv6_addr_prefix(&network_pfx, &table[i].pfx,
table[i].plen);
memcpy(&addr_mcast.s6_addr[4], &network_pfx, 8);
if (ipv6_addr_equal(addr, &addr_mcast)) {
ret = &table[i];
break;
}
}
return ret;
}
static int lowpan_iphc_uncompress_addr(struct sk_buff *skb,
const struct net_device *dev,
struct in6_addr *ipaddr,
u8 address_mode, const void *lladdr)
{
bool fail;
switch (address_mode) {
case LOWPAN_IPHC_DAM_00:
fail = lowpan_fetch_skb(skb, ipaddr->s6_addr, 16);
break;
case LOWPAN_IPHC_SAM_01:
case LOWPAN_IPHC_DAM_01:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[8], 8);
break;
case LOWPAN_IPHC_SAM_10:
case LOWPAN_IPHC_DAM_10:
ipaddr->s6_addr[0] = 0xFE;
ipaddr->s6_addr[1] = 0x80;
ipaddr->s6_addr[11] = 0xFF;
ipaddr->s6_addr[12] = 0xFE;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[14], 2);
break;
case LOWPAN_IPHC_SAM_11:
case LOWPAN_IPHC_DAM_11:
fail = false;
switch (lowpan_dev(dev)->lltype) {
case LOWPAN_LLTYPE_IEEE802154:
lowpan_iphc_uncompress_802154_lladdr(ipaddr, lladdr);
break;
default:
lowpan_iphc_uncompress_eui64_lladdr(ipaddr, lladdr);
break;
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
static int lowpan_iphc_uncompress_ctx_addr(struct sk_buff *skb,
const struct net_device *dev,
const struct lowpan_iphc_ctx *ctx,
struct in6_addr *ipaddr,
u8 address_mode, const void *lladdr)
{
bool fail;
switch (address_mode) {
case LOWPAN_IPHC_DAM_00:
fail = false;
break;
case LOWPAN_IPHC_SAM_01:
case LOWPAN_IPHC_DAM_01:
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[8], 8);
ipv6_addr_prefix_copy(ipaddr, &ctx->pfx, ctx->plen);
break;
case LOWPAN_IPHC_SAM_10:
case LOWPAN_IPHC_DAM_10:
ipaddr->s6_addr[11] = 0xFF;
ipaddr->s6_addr[12] = 0xFE;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[14], 2);
ipv6_addr_prefix_copy(ipaddr, &ctx->pfx, ctx->plen);
break;
case LOWPAN_IPHC_SAM_11:
case LOWPAN_IPHC_DAM_11:
fail = false;
switch (lowpan_dev(dev)->lltype) {
case LOWPAN_LLTYPE_IEEE802154:
lowpan_iphc_uncompress_802154_lladdr(ipaddr, lladdr);
break;
default:
lowpan_iphc_uncompress_eui64_lladdr(ipaddr, lladdr);
break;
}
ipv6_addr_prefix_copy(ipaddr, &ctx->pfx, ctx->plen);
break;
default:
pr_debug("Invalid sam value: 0x%x\n", address_mode);
return -EINVAL;
}
if (fail) {
pr_debug("Failed to fetch skb data\n");
return -EIO;
}
raw_dump_inline(NULL,
"Reconstructed context based ipv6 src addr is",
ipaddr->s6_addr, 16);
return 0;
}
static int lowpan_uncompress_multicast_daddr(struct sk_buff *skb,
struct in6_addr *ipaddr,
u8 address_mode)
{
bool fail;
switch (address_mode) {
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
pr_debug("DAM value has a wrong value: 0x%x\n", address_mode);
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
static int lowpan_uncompress_multicast_ctx_daddr(struct sk_buff *skb,
struct lowpan_iphc_ctx *ctx,
struct in6_addr *ipaddr,
u8 address_mode)
{
struct in6_addr network_pfx = {};
bool fail;
ipaddr->s6_addr[0] = 0xFF;
fail = lowpan_fetch_skb(skb, &ipaddr->s6_addr[1], 2);
fail |= lowpan_fetch_skb(skb, &ipaddr->s6_addr[12], 4);
if (fail)
return -EIO;
ipaddr->s6_addr[3] = ctx->plen;
ipv6_addr_prefix(&network_pfx, &ctx->pfx, ctx->plen);
memcpy(&ipaddr->s6_addr[4], &network_pfx, 8);
return 0;
}
static inline void lowpan_iphc_tf_set_ecn(struct ipv6hdr *hdr, const u8 *tf)
{
u8 ecn = tf[0] & 0xc0;
hdr->flow_lbl[0] |= (ecn >> 2);
}
static inline void lowpan_iphc_tf_set_dscp(struct ipv6hdr *hdr, const u8 *tf)
{
u8 dscp = tf[0] & 0x3f;
hdr->priority |= ((dscp & 0x3c) >> 2);
hdr->flow_lbl[0] |= ((dscp & 0x03) << 6);
}
static inline void lowpan_iphc_tf_set_lbl(struct ipv6hdr *hdr, const u8 *lbl)
{
hdr->flow_lbl[0] |= lbl[0] & 0x0f;
memcpy(&hdr->flow_lbl[1], &lbl[1], 2);
}
static int lowpan_iphc_tf_decompress(struct sk_buff *skb, struct ipv6hdr *hdr,
u8 val)
{
u8 tf[4];
switch (val) {
case LOWPAN_IPHC_TF_00:
if (lowpan_fetch_skb(skb, tf, 4))
return -EINVAL;
lowpan_iphc_tf_set_ecn(hdr, tf);
lowpan_iphc_tf_set_dscp(hdr, tf);
lowpan_iphc_tf_set_lbl(hdr, &tf[1]);
break;
case LOWPAN_IPHC_TF_01:
if (lowpan_fetch_skb(skb, tf, 3))
return -EINVAL;
lowpan_iphc_tf_set_ecn(hdr, tf);
lowpan_iphc_tf_set_lbl(hdr, &tf[0]);
break;
case LOWPAN_IPHC_TF_10:
if (lowpan_fetch_skb(skb, tf, 1))
return -EINVAL;
lowpan_iphc_tf_set_ecn(hdr, tf);
lowpan_iphc_tf_set_dscp(hdr, tf);
break;
case LOWPAN_IPHC_TF_11:
break;
default:
WARN_ON_ONCE(1);
return -EINVAL;
}
return 0;
}
int lowpan_header_decompress(struct sk_buff *skb, const struct net_device *dev,
const void *daddr, const void *saddr)
{
struct ipv6hdr hdr = {};
struct lowpan_iphc_ctx *ci;
u8 iphc0, iphc1, cid = 0;
int err;
raw_dump_table(__func__, "raw skb data dump uncompressed",
skb->data, skb->len);
if (lowpan_fetch_skb(skb, &iphc0, sizeof(iphc0)) ||
lowpan_fetch_skb(skb, &iphc1, sizeof(iphc1)))
return -EINVAL;
hdr.version = 6;
if (iphc1 & LOWPAN_IPHC_CID) {
if (lowpan_fetch_skb(skb, &cid, sizeof(cid)))
return -EINVAL;
}
err = lowpan_iphc_tf_decompress(skb, &hdr,
iphc0 & LOWPAN_IPHC_TF_MASK);
if (err < 0)
return err;
if (!(iphc0 & LOWPAN_IPHC_NH)) {
if (lowpan_fetch_skb(skb, &hdr.nexthdr, sizeof(hdr.nexthdr)))
return -EINVAL;
pr_debug("NH flag is set, next header carried inline: %02x\n",
hdr.nexthdr);
}
if ((iphc0 & LOWPAN_IPHC_HLIM_MASK) != LOWPAN_IPHC_HLIM_00) {
hdr.hop_limit = lowpan_ttl_values[iphc0 & LOWPAN_IPHC_HLIM_MASK];
} else {
if (lowpan_fetch_skb(skb, &hdr.hop_limit,
sizeof(hdr.hop_limit)))
return -EINVAL;
}
if (iphc1 & LOWPAN_IPHC_SAC) {
spin_lock_bh(&lowpan_dev(dev)->ctx.lock);
ci = lowpan_iphc_ctx_get_by_id(dev, LOWPAN_IPHC_CID_SCI(cid));
if (!ci) {
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
return -EINVAL;
}
pr_debug("SAC bit is set. Handle context based source address.\n");
err = lowpan_iphc_uncompress_ctx_addr(skb, dev, ci, &hdr.saddr,
iphc1 & LOWPAN_IPHC_SAM_MASK,
saddr);
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
} else {
pr_debug("source address stateless compression\n");
err = lowpan_iphc_uncompress_addr(skb, dev, &hdr.saddr,
iphc1 & LOWPAN_IPHC_SAM_MASK,
saddr);
}
if (err)
return -EINVAL;
switch (iphc1 & (LOWPAN_IPHC_M | LOWPAN_IPHC_DAC)) {
case LOWPAN_IPHC_M | LOWPAN_IPHC_DAC:
spin_lock_bh(&lowpan_dev(dev)->ctx.lock);
ci = lowpan_iphc_ctx_get_by_id(dev, LOWPAN_IPHC_CID_DCI(cid));
if (!ci) {
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
return -EINVAL;
}
pr_debug("dest: context-based mcast compression\n");
err = lowpan_uncompress_multicast_ctx_daddr(skb, ci,
&hdr.daddr,
iphc1 & LOWPAN_IPHC_DAM_MASK);
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
break;
case LOWPAN_IPHC_M:
err = lowpan_uncompress_multicast_daddr(skb, &hdr.daddr,
iphc1 & LOWPAN_IPHC_DAM_MASK);
break;
case LOWPAN_IPHC_DAC:
spin_lock_bh(&lowpan_dev(dev)->ctx.lock);
ci = lowpan_iphc_ctx_get_by_id(dev, LOWPAN_IPHC_CID_DCI(cid));
if (!ci) {
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
return -EINVAL;
}
pr_debug("DAC bit is set. Handle context based destination address.\n");
err = lowpan_iphc_uncompress_ctx_addr(skb, dev, ci, &hdr.daddr,
iphc1 & LOWPAN_IPHC_DAM_MASK,
daddr);
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
break;
default:
err = lowpan_iphc_uncompress_addr(skb, dev, &hdr.daddr,
iphc1 & LOWPAN_IPHC_DAM_MASK,
daddr);
pr_debug("dest: stateless compression mode %d dest %pI6c\n",
iphc1 & LOWPAN_IPHC_DAM_MASK, &hdr.daddr);
break;
}
if (err)
return -EINVAL;
if (iphc0 & LOWPAN_IPHC_NH) {
err = lowpan_nhc_do_uncompression(skb, dev, &hdr);
if (err < 0)
return err;
} else {
err = skb_cow(skb, sizeof(hdr));
if (unlikely(err))
return err;
}
switch (lowpan_dev(dev)->lltype) {
case LOWPAN_LLTYPE_IEEE802154:
if (lowpan_802154_cb(skb)->d_size)
hdr.payload_len = htons(lowpan_802154_cb(skb)->d_size -
sizeof(struct ipv6hdr));
else
hdr.payload_len = htons(skb->len);
break;
default:
hdr.payload_len = htons(skb->len);
break;
}
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
static u8 lowpan_compress_ctx_addr(u8 **hc_ptr, const struct in6_addr *ipaddr,
const struct lowpan_iphc_ctx *ctx,
const unsigned char *lladdr, bool sam)
{
struct in6_addr tmp = {};
u8 dam;
memcpy(&tmp.s6_addr[8], lladdr, 8);
tmp.s6_addr[8] ^= 0x02;
ipv6_addr_prefix_copy(&tmp, &ctx->pfx, ctx->plen);
if (ipv6_addr_equal(&tmp, ipaddr)) {
dam = LOWPAN_IPHC_DAM_11;
goto out;
}
memset(&tmp, 0, sizeof(tmp));
tmp.s6_addr[11] = 0xFF;
tmp.s6_addr[12] = 0xFE;
memcpy(&tmp.s6_addr[14], &ipaddr->s6_addr[14], 2);
ipv6_addr_prefix_copy(&tmp, &ctx->pfx, ctx->plen);
if (ipv6_addr_equal(&tmp, ipaddr)) {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[14], 2);
dam = LOWPAN_IPHC_DAM_10;
goto out;
}
memset(&tmp, 0, sizeof(tmp));
memcpy(&tmp.s6_addr[8], &ipaddr->s6_addr[8], 8);
ipv6_addr_prefix_copy(&tmp, &ctx->pfx, ctx->plen);
if (ipv6_addr_equal(&tmp, ipaddr)) {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[8], 8);
dam = LOWPAN_IPHC_DAM_01;
goto out;
}
WARN_ONCE(1, "context found but no address mode matched\n");
return LOWPAN_IPHC_DAM_00;
out:
if (sam)
return lowpan_iphc_dam_to_sam_value[dam];
else
return dam;
}
static u8 lowpan_compress_addr_64(u8 **hc_ptr, const struct in6_addr *ipaddr,
const unsigned char *lladdr, bool sam)
{
u8 dam = LOWPAN_IPHC_DAM_00;
if (is_addr_mac_addr_based(ipaddr, lladdr)) {
dam = LOWPAN_IPHC_DAM_11;
pr_debug("address compression 0 bits\n");
} else if (lowpan_is_iid_16_bit_compressable(ipaddr)) {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr16[7], 2);
dam = LOWPAN_IPHC_DAM_10;
raw_dump_inline(NULL, "Compressed ipv6 addr is (16 bits)",
*hc_ptr - 2, 2);
} else {
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr16[4], 8);
dam = LOWPAN_IPHC_DAM_01;
raw_dump_inline(NULL, "Compressed ipv6 addr is (64 bits)",
*hc_ptr - 8, 8);
}
if (sam)
return lowpan_iphc_dam_to_sam_value[dam];
else
return dam;
}
static inline u8 lowpan_iphc_get_tc(const struct ipv6hdr *hdr)
{
u8 dscp, ecn;
dscp = (hdr->priority << 2) | ((hdr->flow_lbl[0] & 0xc0) >> 6);
ecn = (hdr->flow_lbl[0] & 0x30);
pr_debug("ecn 0x%02x dscp 0x%02x\n", ecn >> 4, dscp);
return (ecn << 2) | dscp;
}
static inline bool lowpan_iphc_is_flow_lbl_zero(const struct ipv6hdr *hdr)
{
return ((!(hdr->flow_lbl[0] & 0x0f)) &&
!hdr->flow_lbl[1] && !hdr->flow_lbl[2]);
}
static u8 lowpan_iphc_tf_compress(u8 **hc_ptr, const struct ipv6hdr *hdr)
{
u8 tc = lowpan_iphc_get_tc(hdr), tf[4], val;
pr_debug("tc 0x%02x\n", tc);
if (lowpan_iphc_is_flow_lbl_zero(hdr)) {
if (!tc) {
val = LOWPAN_IPHC_TF_11;
} else {
lowpan_push_hc_data(hc_ptr, &tc, sizeof(tc));
val = LOWPAN_IPHC_TF_10;
}
} else {
if (!(tc & 0x3f)) {
memcpy(&tf[0], &hdr->flow_lbl[0], 3);
tf[0] &= ~0xf0;
tf[0] |= (tc & 0xc0);
lowpan_push_hc_data(hc_ptr, tf, 3);
val = LOWPAN_IPHC_TF_01;
} else {
memcpy(&tf[0], &tc, sizeof(tc));
memcpy(&tf[1], &hdr->flow_lbl[0], 3);
tf[1] &= ~0xf0;
lowpan_push_hc_data(hc_ptr, tf, 4);
val = LOWPAN_IPHC_TF_00;
}
}
return val;
}
static u8 lowpan_iphc_mcast_ctx_addr_compress(u8 **hc_ptr,
const struct lowpan_iphc_ctx *ctx,
const struct in6_addr *ipaddr)
{
u8 data[6];
memcpy(data, &ipaddr->s6_addr[1], 2);
memcpy(&data[1], &ipaddr->s6_addr[11], 4);
lowpan_push_hc_data(hc_ptr, data, 6);
return LOWPAN_IPHC_DAM_00;
}
static u8 lowpan_iphc_mcast_addr_compress(u8 **hc_ptr,
const struct in6_addr *ipaddr)
{
u8 val;
if (lowpan_is_mcast_addr_compressable8(ipaddr)) {
pr_debug("compressed to 1 octet\n");
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[15], 1);
val = LOWPAN_IPHC_DAM_11;
} else if (lowpan_is_mcast_addr_compressable32(ipaddr)) {
pr_debug("compressed to 4 octets\n");
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[1], 1);
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[13], 3);
val = LOWPAN_IPHC_DAM_10;
} else if (lowpan_is_mcast_addr_compressable48(ipaddr)) {
pr_debug("compressed to 6 octets\n");
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[1], 1);
lowpan_push_hc_data(hc_ptr, &ipaddr->s6_addr[11], 5);
val = LOWPAN_IPHC_DAM_01;
} else {
pr_debug("using full address\n");
lowpan_push_hc_data(hc_ptr, ipaddr->s6_addr, 16);
val = LOWPAN_IPHC_DAM_00;
}
return val;
}
int lowpan_header_compress(struct sk_buff *skb, const struct net_device *dev,
const void *daddr, const void *saddr)
{
u8 iphc0, iphc1, *hc_ptr, cid = 0;
struct ipv6hdr *hdr;
u8 head[LOWPAN_IPHC_MAX_HC_BUF_LEN] = {};
struct lowpan_iphc_ctx *dci, *sci, dci_entry, sci_entry;
int ret, ipv6_daddr_type, ipv6_saddr_type;
if (skb->protocol != htons(ETH_P_IPV6))
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
raw_dump_inline(__func__, "saddr", saddr, EUI64_ADDR_LEN);
raw_dump_inline(__func__, "daddr", daddr, EUI64_ADDR_LEN);
raw_dump_table(__func__, "sending raw skb network uncompressed packet",
skb->data, skb->len);
ipv6_daddr_type = ipv6_addr_type(&hdr->daddr);
spin_lock_bh(&lowpan_dev(dev)->ctx.lock);
if (ipv6_daddr_type & IPV6_ADDR_MULTICAST)
dci = lowpan_iphc_ctx_get_by_mcast_addr(dev, &hdr->daddr);
else
dci = lowpan_iphc_ctx_get_by_addr(dev, &hdr->daddr);
if (dci) {
memcpy(&dci_entry, dci, sizeof(*dci));
cid |= dci->id;
}
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
spin_lock_bh(&lowpan_dev(dev)->ctx.lock);
sci = lowpan_iphc_ctx_get_by_addr(dev, &hdr->saddr);
if (sci) {
memcpy(&sci_entry, sci, sizeof(*sci));
cid |= (sci->id << 4);
}
spin_unlock_bh(&lowpan_dev(dev)->ctx.lock);
if (cid) {
iphc1 |= LOWPAN_IPHC_CID;
lowpan_push_hc_data(&hc_ptr, &cid, sizeof(cid));
}
iphc0 |= lowpan_iphc_tf_compress(&hc_ptr, hdr);
ret = lowpan_nhc_check_compression(skb, hdr, &hc_ptr);
if (ret == -ENOENT)
lowpan_push_hc_data(&hc_ptr, &hdr->nexthdr,
sizeof(hdr->nexthdr));
else
iphc0 |= LOWPAN_IPHC_NH;
switch (hdr->hop_limit) {
case 1:
iphc0 |= LOWPAN_IPHC_HLIM_01;
break;
case 64:
iphc0 |= LOWPAN_IPHC_HLIM_10;
break;
case 255:
iphc0 |= LOWPAN_IPHC_HLIM_11;
break;
default:
lowpan_push_hc_data(&hc_ptr, &hdr->hop_limit,
sizeof(hdr->hop_limit));
}
ipv6_saddr_type = ipv6_addr_type(&hdr->saddr);
if (ipv6_saddr_type == IPV6_ADDR_ANY) {
pr_debug("source address is unspecified, setting SAC\n");
iphc1 |= LOWPAN_IPHC_SAC;
} else {
if (sci) {
iphc1 |= lowpan_compress_ctx_addr(&hc_ptr, &hdr->saddr,
&sci_entry, saddr,
true);
iphc1 |= LOWPAN_IPHC_SAC;
} else {
if (ipv6_saddr_type & IPV6_ADDR_LINKLOCAL &&
lowpan_is_linklocal_zero_padded(hdr->saddr)) {
iphc1 |= lowpan_compress_addr_64(&hc_ptr,
&hdr->saddr,
saddr, true);
pr_debug("source address unicast link-local %pI6c iphc1 0x%02x\n",
&hdr->saddr, iphc1);
} else {
pr_debug("send the full source address\n");
lowpan_push_hc_data(&hc_ptr,
hdr->saddr.s6_addr, 16);
}
}
}
if (ipv6_daddr_type & IPV6_ADDR_MULTICAST) {
pr_debug("destination address is multicast: ");
iphc1 |= LOWPAN_IPHC_M;
if (dci) {
iphc1 |= lowpan_iphc_mcast_ctx_addr_compress(&hc_ptr,
&dci_entry,
&hdr->daddr);
iphc1 |= LOWPAN_IPHC_DAC;
} else {
iphc1 |= lowpan_iphc_mcast_addr_compress(&hc_ptr,
&hdr->daddr);
}
} else {
if (dci) {
iphc1 |= lowpan_compress_ctx_addr(&hc_ptr, &hdr->daddr,
&dci_entry, daddr,
false);
iphc1 |= LOWPAN_IPHC_DAC;
} else {
if (ipv6_daddr_type & IPV6_ADDR_LINKLOCAL &&
lowpan_is_linklocal_zero_padded(hdr->daddr)) {
iphc1 |= lowpan_compress_addr_64(&hc_ptr,
&hdr->daddr,
daddr, false);
pr_debug("dest address unicast link-local %pI6c iphc1 0x%02x\n",
&hdr->daddr, iphc1);
} else {
pr_debug("dest address unicast %pI6c\n",
&hdr->daddr);
lowpan_push_hc_data(&hc_ptr,
hdr->daddr.s6_addr, 16);
}
}
}
if (iphc0 & LOWPAN_IPHC_NH) {
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
