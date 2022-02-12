static int
detect_add_path_prefix4(tvbuff_t *tvb, gint offset, gint end) {
guint32 addr_len;
guint8 prefix_len;
gint o;
for (o = offset + 4; o < end; o += 4) {
prefix_len = tvb_get_guint8(tvb, o);
if( prefix_len > 32) {
return 0;
}
addr_len = (prefix_len + 7) / 8;
o += 1 + addr_len;
if( o > end ) {
return 0;
}
if (prefix_len % 8) {
if( tvb_get_guint8(tvb, o - 1 ) & (0xFF >> (prefix_len % 8)) ) {
return 0;
}
}
}
for (o = offset; o < end; ) {
prefix_len = tvb_get_guint8(tvb, o);
if( prefix_len > 32) {
return 1;
}
addr_len = (prefix_len + 7) / 8;
o += 1 + addr_len;
if( o > end ) {
return 1;
}
if (prefix_len % 8) {
if( tvb_get_guint8(tvb, o - 1 ) & (0xFF >> (prefix_len % 8)) ) {
return 1;
}
}
}
return 0;
}
static int
decode_path_prefix4(proto_tree *tree, int hf_path_id, int hf_addr, tvbuff_t *tvb, gint offset,
const char *tag)
{
proto_item *ti;
proto_tree *prefix_tree;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip_addr;
guint8 plen;
int length;
guint32 path_identifier;
path_identifier = tvb_get_ntohl(tvb, offset);
plen = tvb_get_guint8(tvb, offset + 4);
length = ipv4_addr_and_mask(tvb, offset + 4 + 1, ip_addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, offset + 4 , 1, "%s length %u invalid (> 32)",
tag, plen);
return -1;
}
ti = proto_tree_add_text(tree, tvb, offset,
4 + 1 + length, "%s/%u PathId %u ",
ip_to_str(ip_addr.addr_bytes), plen, path_identifier);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
if (hf_path_id != -1) {
proto_tree_add_uint(prefix_tree, hf_path_id, tvb, offset, 4,
path_identifier);
} else {
proto_tree_add_text(prefix_tree, tvb, offset, 4,
"%s Path Id: %u", tag, path_identifier);
}
proto_tree_add_text(prefix_tree, tvb, offset + 4, 1, "%s prefix length: %u",
tag, plen);
if (hf_addr != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr, tvb, offset + 4 + 1, length,
ip_addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 4 + 1, length,
"%s prefix: %s", tag, ip_to_str(ip_addr.addr_bytes));
}
return(4 + 1 + length);
}
static int
decode_prefix4(proto_tree *tree, int hf_addr, tvbuff_t *tvb, gint offset,
guint16 tlen, const char *tag)
{
proto_item *ti;
proto_tree *prefix_tree;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip_addr;
guint8 plen;
int length;
plen = tvb_get_guint8(tvb, offset);
length = ipv4_addr_and_mask(tvb, offset + 1, ip_addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, offset, 1, "%s length %u invalid (> 32)",
tag, plen);
return -1;
}
ti = proto_tree_add_text(tree, tvb, offset,
tlen != 0 ? tlen : 1 + length, "%s/%u",
ip_to_str(ip_addr.addr_bytes), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, offset, 1, "%s prefix length: %u",
tag, plen);
if (hf_addr != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr, tvb, offset + 1, length,
ip_addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 1, length,
"%s prefix: %s", tag, ip_to_str(ip_addr.addr_bytes));
}
return(1 + length);
}
static int
decode_prefix6(proto_tree *tree, int hf_addr, tvbuff_t *tvb, gint offset,
guint16 tlen, const char *tag)
{
proto_item *ti;
proto_tree *prefix_tree;
struct e_in6_addr addr;
int plen;
int length;
plen = tvb_get_guint8(tvb, offset);
length = ipv6_addr_and_mask(tvb, offset + 1, &addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, offset, 1, "%s length %u invalid",
tag, plen);
return -1;
}
ti = proto_tree_add_text(tree, tvb, offset,
tlen != 0 ? tlen : 1 + length, "%s/%u",
ip6_to_str(&addr), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, offset, 1, "%s prefix length: %u",
tag, plen);
if (hf_addr != -1) {
proto_tree_add_ipv6(prefix_tree, hf_addr, tvb, offset + 1, length,
addr.bytes);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 1, length,
"%s prefix: %s", tag, ip6_to_str(&addr));
}
return(1 + length);
}
static char*
decode_bgp_rd(tvbuff_t *tvb, gint offset)
{
guint16 rd_type;
emem_strbuf_t *strbuf;
rd_type = tvb_get_ntohs(tvb,offset);
strbuf = ep_strbuf_new_label(NULL);
switch (rd_type) {
case FORMAT_AS2_LOC:
ep_strbuf_printf(strbuf, "%u:%u", tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4));
break;
case FORMAT_IP_LOC:
ep_strbuf_printf(strbuf, "%s:%u", tvb_ip_to_str(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6));
break ;
case FORMAT_AS4_LOC:
ep_strbuf_printf(strbuf, "%u:%u", tvb_get_ntohl(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6));
break ;
default:
ep_strbuf_printf(strbuf, "Unknown (0x%04x) RD type",rd_type);
break;
}
return strbuf->str;
}
static int
decode_mcast_vpn_nlri_addresses(proto_tree *tree, tvbuff_t *tvb,
gint offset)
{
guint8 addr_len;
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_length, tvb, offset,
1, ENC_BIG_ENDIAN);
addr_len = tvb_get_guint8(tvb, offset);
if (addr_len != 32 && addr_len != 128)
return -1;
offset++;
if (addr_len == 32) {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_addr_ipv4, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_source_addr_ipv6, tvb,
offset, 16, ENC_NA);
offset += 16;
}
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_length, tvb, offset,
1, ENC_BIG_ENDIAN);
addr_len = tvb_get_guint8(tvb, offset);
if (addr_len != 32 && addr_len != 128)
return -1;
offset++;
if (addr_len == 32) {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_addr_ipv4, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_group_addr_ipv6, tvb,
offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int
decode_mcast_vpn_nlri(proto_tree *tree, tvbuff_t *tvb, gint offset, guint16 afi)
{
guint8 route_type, length, ip_length;
proto_item *item;
proto_tree *nlri_tree;
guint32 route_key_length;
int ret;
ip_length = (afi == AFNUM_INET) ? 4 : 16;
route_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_route_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_length, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
if (length < tvb_reported_length_remaining(tvb, offset))
return -1;
item = proto_tree_add_item(tree, hf_bgp_mcast_vpn_nlri_t, tvb, offset,
length, ENC_NA);
proto_item_set_text(item, "%s (%u byte%s)",
val_to_str_const(route_type, mcast_vpn_route_type, "Unknown"),
length, plurality(length, "", "s"));
nlri_tree = proto_item_add_subtree(item, ett_bgp_mcast_vpn_nlri);
switch (route_type) {
case MCAST_VPN_RTYPE_INTRA_AS_IPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
if (afi == AFNUM_INET)
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
tvb, offset, ip_length, ENC_BIG_ENDIAN);
else
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
tvb, offset, ip_length, ENC_NA);
break;
case MCAST_VPN_RTYPE_INTER_AS_IPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_source_as, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
case MCAST_VPN_RTYPE_SPMSI_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
case MCAST_VPN_RTYPE_LEAF_AD:
route_key_length = length - ip_length;
item = proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_route_key, tvb,
offset, route_key_length, ENC_NA);
proto_item_set_text(item, "Route Key (%u byte%s)", route_key_length,
plurality(route_key_length, "", "s"));
offset += route_key_length;
if (afi == AFNUM_INET)
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
tvb, offset, ip_length, ENC_BIG_ENDIAN);
else
proto_tree_add_item(nlri_tree,
hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
tvb, offset, ip_length, ENC_NA);
break;
case MCAST_VPN_RTYPE_SOURCE_ACTIVE_AD:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
case MCAST_VPN_RTYPE_SHARED_TREE_JOIN:
case MCAST_VPN_RTYPE_SOURCE_TREE_JOIN:
item = proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE,
ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(nlri_tree, hf_bgp_mcast_vpn_nlri_source_as, tvb,
offset, 4, ENC_NA);
offset += 4;
ret = decode_mcast_vpn_nlri_addresses(nlri_tree, tvb, offset);
if (ret < 0)
return -1;
break;
}
return 2 + length;
}
static guint
decode_mdt_safi(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
const guint ip_length = 4;
const guint mdt_safi_nlri_length_bits = 128;
guint length;
gint orig_offset = offset;
proto_item *item;
length = tvb_get_guint8(tvb, offset);
if (length != mdt_safi_nlri_length_bits)
return -1;
offset++;
item = proto_tree_add_item(tree, hf_bgp_mdt_safi_rd, tvb,
offset, BGP_ROUTE_DISTINGUISHER_SIZE, ENC_NA);
proto_item_set_text(item, "Route Distinguisher: %s",
decode_bgp_rd(tvb, offset));
offset += BGP_ROUTE_DISTINGUISHER_SIZE;
proto_tree_add_item(tree, hf_bgp_mdt_safi_ipv4_addr, tvb,
offset, ip_length, ENC_BIG_ENDIAN);
offset += ip_length;
proto_tree_add_item(tree, hf_bgp_mdt_safi_group_addr, tvb,
offset, ip_length, ENC_BIG_ENDIAN);
offset += ip_length;
return offset - orig_offset;
}
static guint
decode_MPLS_stack(tvbuff_t *tvb, gint offset, emem_strbuf_t *stack_strbuf)
{
guint32 label_entry;
gint indx;
indx = offset ;
label_entry = 0x000000 ;
ep_strbuf_truncate(stack_strbuf, 0);
while ((label_entry & 0x000001) == 0) {
label_entry = tvb_get_ntoh24(tvb, indx) ;
if((indx-offset)==0&&(label_entry==0||label_entry==0x800000)) {
ep_strbuf_append(stack_strbuf, "0 (withdrawn)");
return (1);
}
ep_strbuf_append_printf(stack_strbuf, "%u%s", label_entry >> 4,
((label_entry & 0x000001) == 0) ? "," : " (bottom)");
indx += 3 ;
if ((label_entry & 0x000001) == 0) {
ep_strbuf_append(stack_strbuf, " (BOGUS: Bottom of Stack NOT set!)");
break;
}
}
return((indx - offset) / 3);
}
static int
mp_addr_to_str (guint16 afi, guint8 safi, tvbuff_t *tvb, gint offset, emem_strbuf_t *strbuf, gint nhlen)
{
int length;
guint32 ip4addr,ip4addr2;
guint16 rd_type;
struct e_in6_addr ip6addr;
switch (afi) {
case AFNUM_INET:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
case SAFNUM_MPLS_LABEL:
case SAFNUM_ENCAPSULATION:
case SAFNUM_ROUTE_TARGET:
length = nhlen;
if (nhlen == 4) {
ep_strbuf_append(strbuf, tvb_ip_to_str(tvb, offset));
} else if (nhlen == 16) {
ep_strbuf_append(strbuf, tvb_ip6_to_str(tvb, offset));
} else {
ep_strbuf_append(strbuf, "Unknown address");
}
break;
case SAFNUM_TUNNEL:
length = 4 ;
ip4addr = tvb_get_ipv4(tvb, offset);
ep_strbuf_append(strbuf, ip_to_str((guint8 *)&ip4addr));
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
rd_type=tvb_get_ntohs(tvb,offset) ;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = 8 + sizeof(ip4addr);
ip4addr = tvb_get_ipv4(tvb, offset + 8);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%u:%u IPv4=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
ip_to_str((guint8 *)&ip4addr));
break;
case FORMAT_IP_LOC:
length = 8 + sizeof(ip4addr);
ip4addr = tvb_get_ipv4(tvb, offset + 2);
ip4addr2 = tvb_get_ipv4(tvb, offset + 8);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%s:%u IPv4=%s",
ip_to_str((guint8 *)&ip4addr),
tvb_get_ntohs(tvb, offset + 6),
ip_to_str((guint8 *)&ip4addr2));
break ;
case FORMAT_AS4_LOC:
length = 8 + sizeof(ip4addr);
ip4addr = tvb_get_ipv4(tvb, offset + 8);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%u.%u:%u IPv4=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
ip_to_str((guint8 *)&ip4addr));
break ;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown (0x%04x) labeled VPN IPv4 address format",rd_type);
break;
}
break;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
case AFNUM_INET6:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
case SAFNUM_MPLS_LABEL:
case SAFNUM_ENCAPSULATION:
case SAFNUM_TUNNEL:
length = 16 ;
tvb_get_ipv6(tvb, offset, &ip6addr);
ep_strbuf_printf(strbuf, "%s", ip6_to_str(&ip6addr));
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
rd_type=tvb_get_ntohs(tvb,offset) ;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = 8 + 16;
tvb_get_ipv6(tvb, offset + 8, &ip6addr);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%u:%u IPv6=%s",
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
ip6_to_str(&ip6addr));
break;
case FORMAT_IP_LOC:
length = 8 + 16;
ip4addr = tvb_get_ipv4(tvb, offset + 2);
tvb_get_ipv6(tvb, offset + 8, &ip6addr);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%s:%u IPv6=%s",
ip_to_str((guint8 *)&ip4addr),
tvb_get_ntohs(tvb, offset + 6),
ip6_to_str(&ip6addr));
break ;
case FORMAT_AS4_LOC:
length = 8 + 16;
tvb_get_ipv6(tvb, offset + 8, &ip6addr);
ep_strbuf_printf(strbuf, "Empty Label Stack RD=%u:%u IPv6=%s",
tvb_get_ntohl(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 6),
ip6_to_str(&ip6addr));
break ;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown (0x%04x) labeled VPN IPv6 address format",rd_type);
break;
}
break;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
switch (safi) {
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
case SAFNUM_VPLS:
length = 4;
ip4addr = tvb_get_ipv4(tvb, offset + 0);
ep_strbuf_printf(strbuf, "IPv4=%s",
ip_to_str((guint8 *)&ip4addr));
break;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown SAFI (%u) for AFI %u", safi, afi);
break;
}
break;
default:
length = 0 ;
ep_strbuf_printf(strbuf, "Unknown AFI (%u) value", afi);
break;
}
return(length) ;
}
static int
decode_prefix_MP(proto_tree *tree, int hf_addr4, int hf_addr6,
guint16 afi, guint8 safi, tvbuff_t *tvb, gint offset,
const char *tag)
{
int start_offset = offset;
proto_item *ti;
proto_tree *prefix_tree;
int total_length;
int length;
guint plen;
guint labnum;
guint16 tnl_id;
int ce_id,labblk_off,labblk_size;
union {
guint8 addr_bytes[4];
guint32 addr;
} ip4addr, ip4addr2;
struct e_in6_addr ip6addr;
guint16 rd_type;
emem_strbuf_t *stack_strbuf;
emem_strbuf_t *comm_strbuf;
switch (afi) {
case AFNUM_INET:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
total_length = decode_prefix4(tree, hf_addr4, tvb, offset, 0, tag);
if (total_length < 0)
return -1;
break;
case SAFNUM_MPLS_LABEL:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = ep_strbuf_new_label(NULL);
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
plen -= (labnum * 3*8);
length = ipv4_addr_and_mask(tvb, offset, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
ti = proto_tree_add_text(tree, tvb, start_offset,
(offset + length) - start_offset,
"Label Stack=%s IPv4=%s/%u",
stack_strbuf->str, ip_to_str(ip4addr.addr_bytes), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, start_offset, 1, "%s Prefix length: %u",
tag, plen + labnum * 3 * 8);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1, 3 * labnum, "%s Label Stack: %s",
tag, stack_strbuf->str);
if (hf_addr4 != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb, offset,
length, ip4addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset, length,
"%s IPv4 prefix: %s",
tag, ip_to_str(ip4addr.addr_bytes));
}
total_length = (1 + labnum*3) + length;
break;
case SAFNUM_MCAST_VPN:
total_length = decode_mcast_vpn_nlri(tree, tvb, offset, afi);
if (total_length < 0)
return -1;
break;
case SAFNUM_MDT:
total_length = decode_mdt_safi(tree, tvb, offset);
if (total_length < 0)
return -1;
break;
case SAFNUM_ROUTE_TARGET:
plen = tvb_get_guint8(tvb, offset);
if (plen == 0) {
proto_tree_add_text(tree, tvb, offset, 1,
"%s Wildcard route target", tag);
total_length = 1;
break;
}
if ((plen < 32) || (plen > 96)) {
proto_tree_add_text(tree, tvb, offset, 1,
"%s Route target length %u invalid",
tag, plen);
return -1;
}
length = (plen + 7)/8;
comm_strbuf = ep_strbuf_new_label(NULL);
switch (tvb_get_ntohs(tvb, offset + 1 + 4)) {
case BGP_EXT_COM_RT_0:
ep_strbuf_printf(comm_strbuf, "%u:%u",
tvb_get_ntohs(tvb, offset + 1 + 6),
tvb_get_ntohl(tvb, offset + 1 + 8));
break;
case BGP_EXT_COM_RT_1:
ep_strbuf_printf(comm_strbuf, "%s:%u",
tvb_ip_to_str(tvb, offset + 1 + 6),
tvb_get_ntohs(tvb, offset + 1 + 10));
break;
case BGP_EXT_COM_RT_2:
ep_strbuf_printf(comm_strbuf, "%u:%u",
tvb_get_ntohl(tvb, 6),
tvb_get_ntohs(tvb, offset + 1 + 10));
break;
default:
ep_strbuf_printf(comm_strbuf, "Invalid RT type");
break;
}
ti = proto_tree_add_text(tree, tvb, offset + 1, length, "%s %u:%s/%u",
tag, tvb_get_ntohl(tvb, offset + 1 + 0),
comm_strbuf->str,
plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, offset, 1, "%s Prefix length: %u",
tag, plen);
proto_tree_add_text(prefix_tree, tvb, offset + 1, 4, "%s Originating AS: %u",
tag, tvb_get_ntohl(tvb, offset + 1 + 0));
proto_tree_add_text(prefix_tree, tvb, offset + 1 + 4, length - 4, "%s Community prefix: %s",
tag, comm_strbuf->str);
total_length = 1 + length;
break;
case SAFNUM_ENCAPSULATION:
plen = tvb_get_guint8(tvb, offset);
if (plen != 32){
proto_tree_add_text(tree, tvb, offset, 1,
"%s IPv4 address length %u invalid",
tag, plen);
return -1;
}
offset += 1;
ip4addr.addr = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(tree, tvb, offset,
offset + 4,
"Endpoint Address: %s",
ip_to_str((guint8 *)&ip4addr));
total_length = 5;
break;
case SAFNUM_TUNNEL:
plen = tvb_get_guint8(tvb, offset);
if (plen <= 16){
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Tunnel IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
tnl_id = tvb_get_ntohs(tvb, offset + 1);
offset += 3;
plen -= 16;
length = ipv4_addr_and_mask(tvb, offset, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Tunnel IPv4 prefix length %u invalid",
tag, plen + 16);
return -1;
}
ti = proto_tree_add_text(tree, tvb, start_offset,
(offset + length) - start_offset,
"Tunnel Identifier=0x%x IPv4=%s/%u",
tnl_id, ip_to_str(ip4addr.addr_bytes), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, start_offset, 1, "%s Prefix length: %u",
tag, plen + 16);
proto_tree_add_item(prefix_tree, hf_bgp_mp_nlri_tnl_id, tvb,
start_offset + 1, 2, ENC_BIG_ENDIAN);
if (hf_addr4 != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb, offset,
length, ip4addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset, length,
"%s IPv4 prefix: %s",
tag, ip_to_str(ip4addr.addr_bytes));
}
total_length = 1 + 2 + length;
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = ep_strbuf_new_label(NULL);
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen);
return -1;
}
plen -= (labnum * 3*8);
rd_type = tvb_get_ntohs(tvb, offset);
if (plen < 8*8) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
plen -= 8*8;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = ipv4_addr_and_mask(tvb, offset + 8, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
ti = proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%u:%u, IPv4=%s/%u",
stack_strbuf->str,
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
ip_to_str(ip4addr.addr_bytes), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, start_offset, 1, "%s Prefix length: %u",
tag, plen + labnum * 3 * 8 + 8 * 8);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1, 3 * labnum,
"%s Label Stack: %s", tag, stack_strbuf->str);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1 + 3 * labnum, 8,
"%s Route Distinguisher: %u:%u", tag, tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4));
if (hf_addr4 != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb,
offset + 8, length, ip4addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 8,
length, "%s IPv4 prefix: %s", tag,
ip_to_str(ip4addr.addr_bytes));
}
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_IP_LOC:
tvb_memcpy(tvb, ip4addr.addr_bytes, offset + 2, 4);
length = ipv4_addr_and_mask(tvb, offset + 8, ip4addr2.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
ti = proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%s:%u, IPv4=%s/%u",
stack_strbuf->str,
ip_to_str(ip4addr.addr_bytes),
tvb_get_ntohs(tvb, offset + 6),
ip_to_str(ip4addr2.addr_bytes),
plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, start_offset, 1, "%s Prefix length: %u",
tag, plen + labnum * 3 * 8 + 8 * 8);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1, 3 * labnum,
"%s Label Stack: %s", tag, stack_strbuf->str);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1 + 3 * labnum, 8,
"%s Route Distinguisher: %s:%u", tag, ip_to_str(ip4addr.addr_bytes),
tvb_get_ntohs(tvb, offset + 6));
if (hf_addr4 != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb,
offset + 8, length, ip4addr2.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 8,
length, "%s IPv4 prefix: %s", tag,
ip_to_str(ip4addr2.addr_bytes));
}
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_AS4_LOC:
length = ipv4_addr_and_mask(tvb, offset + 8, ip4addr.addr_bytes, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv4 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
ti = proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%u.%u:%u, IPv4=%s/%u",
stack_strbuf->str,
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
ip_to_str(ip4addr.addr_bytes), plen);
prefix_tree = proto_item_add_subtree(ti, ett_bgp_prefix);
proto_tree_add_text(prefix_tree, tvb, start_offset, 1, "%s Prefix length: %u",
tag, plen + labnum * 3 * 8 + 8 * 8);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1, 3 * labnum,
"%s Label Stack: %s", tag, stack_strbuf->str);
proto_tree_add_text(prefix_tree, tvb, start_offset + 1 + 3 * labnum, 8,
"%s Route Distinguisher: %u.%u:%u", tag, tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4), tvb_get_ntohs(tvb, offset + 6));
if (hf_addr4 != -1) {
proto_tree_add_ipv4(prefix_tree, hf_addr4, tvb,
offset + 8, length, ip4addr.addr);
} else {
proto_tree_add_text(prefix_tree, tvb, offset + 8,
length, "%s IPv4 prefix: %s", tag,
ip_to_str(ip4addr.addr_bytes));
}
total_length = (1 + labnum * 3 + 8) + length;
break;
default:
proto_tree_add_text(tree, tvb, start_offset,
(offset - start_offset) + 2,
"Unknown labeled VPN IPv4 address format %u", rd_type);
return -1;
}
break;
default:
proto_tree_add_text(tree, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
case AFNUM_INET6:
switch (safi) {
case SAFNUM_UNICAST:
case SAFNUM_MULCAST:
case SAFNUM_UNIMULC:
total_length = decode_prefix6(tree, hf_addr6, tvb, offset, 0, tag);
if (total_length < 0)
return -1;
break;
case SAFNUM_MPLS_LABEL:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = ep_strbuf_new_label(NULL);
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled IPv6 prefix length %u invalid", tag, plen);
return -1;
}
plen -= (labnum * 3*8);
length = ipv6_addr_and_mask(tvb, offset, &ip6addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
proto_tree_add_text(tree, tvb, start_offset,
(offset + length) - start_offset,
"Label Stack=%s, IPv6=%s/%u",
stack_strbuf->str,
ip6_to_str(&ip6addr), plen);
total_length = (1 + labnum * 3) + length;
break;
case SAFNUM_ENCAPSULATION:
plen = tvb_get_guint8(tvb, offset);
if (plen != 128){
proto_tree_add_text(tree, tvb, offset, 1,
"%s IPv6 address length %u invalid",
tag, plen);
return -1;
}
offset += 1;
tvb_get_ipv6(tvb, offset, &ip6addr);
proto_tree_add_text(tree, tvb, offset,
offset + 16,
"Endpoint Address: %s",
ip6_to_str(&ip6addr));
total_length = 17;
break;
case SAFNUM_TUNNEL:
plen = tvb_get_guint8(tvb, offset);
if (plen <= 16){
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Tunnel IPv6 prefix length %u invalid",
tag, plen);
return -1;
}
tnl_id = tvb_get_ntohs(tvb, offset + 1);
offset += 3;
plen -= 16;
length = ipv6_addr_and_mask(tvb, offset, &ip6addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Tunnel IPv6 prefix length %u invalid",
tag, plen + 16);
return -1;
}
proto_tree_add_text(tree, tvb, start_offset,
(offset + length) - start_offset,
"Tunnel Identifier=0x%x IPv6=%s/%u",
tnl_id, ip6_to_str(&ip6addr), plen);
total_length = (1 + 2) + length;
break;
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
plen = tvb_get_guint8(tvb, offset);
stack_strbuf = ep_strbuf_new_label(NULL);
labnum = decode_MPLS_stack(tvb, offset + 1, stack_strbuf);
offset += (1 + labnum * 3);
if (plen <= (labnum * 3*8)) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid", tag, plen);
return -1;
}
plen -= (labnum * 3*8);
rd_type = tvb_get_ntohs(tvb,offset);
if (plen < 8*8) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8));
return -1;
}
plen -= 8*8;
switch (rd_type) {
case FORMAT_AS2_LOC:
length = ipv6_addr_and_mask(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%u:%u, IPv6=%s/%u",
stack_strbuf->str,
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohl(tvb, offset + 4),
ip6_to_str(&ip6addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_IP_LOC:
tvb_memcpy(tvb, ip4addr.addr_bytes, offset + 2, 4);
length = ipv6_addr_and_mask(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%s:%u, IPv6=%s/%u",
stack_strbuf->str,
ip_to_str(ip4addr.addr_bytes),
tvb_get_ntohs(tvb, offset + 6),
ip6_to_str(&ip6addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
case FORMAT_AS4_LOC:
length = ipv6_addr_and_mask(tvb, offset + 8, &ip6addr, plen);
if (length < 0) {
proto_tree_add_text(tree, tvb, start_offset, 1,
"%s Labeled VPN IPv6 prefix length %u invalid",
tag, plen + (labnum * 3*8) + 8*8);
return -1;
}
proto_tree_add_text(tree, tvb, start_offset,
(offset + 8 + length) - start_offset,
"Label Stack=%s RD=%u.%u:%u, IPv6=%s/%u",
stack_strbuf->str,
tvb_get_ntohs(tvb, offset + 2),
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
ip6_to_str(&ip6addr), plen);
total_length = (1 + labnum * 3 + 8) + length;
break;
default:
proto_tree_add_text(tree, tvb, start_offset, 0,
"Unknown labeled VPN IPv6 address format %u", rd_type);
return -1;
}
break;
default:
proto_tree_add_text(tree, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
switch (safi) {
case SAFNUM_LAB_VPNUNICAST:
case SAFNUM_LAB_VPNMULCAST:
case SAFNUM_LAB_VPNUNIMULC:
case SAFNUM_VPLS:
plen = tvb_get_ntohs(tvb,offset);
rd_type=tvb_get_ntohs(tvb,offset+2);
if(plen == 12)
{
switch (rd_type) {
case FORMAT_AS2_LOC:
proto_tree_add_text(tree, tvb, start_offset,
(offset + plen + 2) - start_offset,
"RD: %u:%u, PE_addr: %s",
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohl(tvb, offset + 6),
tvb_ip_to_str(tvb, offset + 10));
break;
case FORMAT_IP_LOC:
proto_tree_add_text(tree, tvb, offset,
(offset + plen + 2) - start_offset,
"RD: %s:%u, PE_addr: %s",
tvb_ip_to_str(tvb, offset + 10),
tvb_get_ntohs(tvb, offset + 8),
tvb_ip_to_str(tvb, offset + 10));
break;
case FORMAT_AS4_LOC:
proto_tree_add_text(tree, tvb, start_offset,
(offset + plen + 2) - start_offset,
"RD: %u.%u:%u, PE_addr: %s",
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
tvb_get_ntohs(tvb, offset + 8),
tvb_ip_to_str(tvb, offset + 10));
break;
default:
proto_tree_add_text(tree, tvb, start_offset,
(offset - start_offset) + 2,
"Unknown labeled VPN address format %u", rd_type);
return -1;
}
}else{
ce_id=tvb_get_ntohs(tvb,offset+10);
labblk_off=tvb_get_ntohs(tvb,offset+12);
labblk_size=tvb_get_ntohs(tvb,offset+14);
stack_strbuf = ep_strbuf_new_label(NULL);
decode_MPLS_stack(tvb, offset + 16, stack_strbuf);
switch (rd_type) {
case FORMAT_AS2_LOC:
tvb_memcpy(tvb, ip4addr.addr_bytes, offset + 6, 4);
proto_tree_add_text(tree, tvb, start_offset,
(offset + plen + 1) - start_offset,
"RD: %u:%s, CE-ID: %u, Label-Block Offset: %u, "
"Label-Block Size: %u Label Base %s",
tvb_get_ntohs(tvb, offset + 4),
ip_to_str(ip4addr.addr_bytes),
ce_id,
labblk_off,
labblk_size,
stack_strbuf->str);
break;
case FORMAT_IP_LOC:
tvb_memcpy(tvb, ip4addr.addr_bytes, offset + 4, 4);
proto_tree_add_text(tree, tvb, offset,
(offset + plen + 1) - start_offset,
"RD: %s:%u, CE-ID: %u, Label-Block Offset: %u, "
"Label-Block Size: %u, Label Base %s",
ip_to_str(ip4addr.addr_bytes),
tvb_get_ntohs(tvb, offset + 8),
ce_id,
labblk_off,
labblk_size,
stack_strbuf->str);
break;
case FORMAT_AS4_LOC:
proto_tree_add_text(tree, tvb, offset,
(offset + plen + 1) - start_offset,
"RD: %u.%u:%u, CE-ID: %u, Label-Block Offset: %u, "
"Label-Block Size: %u, Label Base %s",
tvb_get_ntohs(tvb, offset + 4),
tvb_get_ntohs(tvb, offset + 6),
tvb_get_ntohs(tvb, offset + 8),
ce_id,
labblk_off,
labblk_size,
stack_strbuf->str);
break;
default:
proto_tree_add_text(tree, tvb, start_offset,
(offset - start_offset) + 2,
"Unknown labeled VPN address format %u", rd_type);
return -1;
}
}
total_length = plen+2;
break;
default:
proto_tree_add_text(tree, tvb, start_offset, 0,
"Unknown SAFI (%u) for AFI %u", safi, afi);
return -1;
}
break;
default:
proto_tree_add_text(tree, tvb, start_offset, 0,
"Unknown AFI (%u) value", afi);
return -1;
}
return(total_length);
}
static int
dissect_bgp_capability_item(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, gboolean action)
{
proto_tree *cap_tree;
proto_item *ti;
proto_item *ti_len;
guint8 ctype;
guint8 clen;
ti = proto_tree_add_item(tree, hf_bgp_cap, tvb, offset, -1, ENC_NA);
cap_tree = proto_item_add_subtree(ti, ett_bgp_cap);
proto_tree_add_item(cap_tree, hf_bgp_cap_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ctype = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s", val_to_str(ctype, capability_vals, "Unknown capability %d"));
offset += 1;
ti_len = proto_tree_add_item(cap_tree, hf_bgp_cap_length, tvb, offset, 1, ENC_BIG_ENDIAN);
clen = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, clen+2);
offset += 1;
if(action){
proto_tree_add_item(cap_tree, hf_bgp_cap_action, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_len(ti, clen+3);
offset += 1;
}
switch (ctype) {
case BGP_CAPABILITY_RESERVED:
if (clen != 0) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u wrong, must be = 0", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
case BGP_CAPABILITY_MULTIPROTOCOL:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_mp_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_mp_safi, tvb, offset, 1, ENC_NA);
offset += 1;
}
break;
case BGP_CAPABILITY_GRACEFUL_RESTART:
if ((clen < 6) && (clen != 2)) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u too short, must be greater than 6", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
int eclen = offset + clen;
proto_tree *sub_tree;
if (clen == 2){
expert_add_info_format(pinfo, ti_len, PI_REQUEST_CODE, PI_CHAT, "Graceful Restart Capability supported in Helper mode only");
}
ti = proto_tree_add_item(cap_tree, hf_bgp_cap_gr_timers, tvb, offset, 2, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_bgp_cap);
proto_tree_add_item(sub_tree, hf_bgp_cap_gr_timers_restart_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_bgp_cap_gr_timers_restart_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (offset < eclen) {
proto_tree_add_item(cap_tree, hf_bgp_cap_gr_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_gr_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(cap_tree, hf_bgp_cap_gr_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(ti, ett_bgp_cap);
proto_tree_add_item(sub_tree, hf_bgp_cap_gr_flag_pfs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case BGP_CAPABILITY_4_OCTET_AS_NUMBER:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_4as, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case BGP_CAPABILITY_DYNAMIC_CAPABILITY:
if (clen > 0) {
int eclen = offset + clen;
while (offset < eclen) {
proto_tree_add_item(cap_tree, hf_bgp_cap_dc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case BGP_CAPABILITY_ADDITIONAL_PATHS:
if (clen != 4) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u is wrong, must be = 4", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_ap_sendreceive, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case BGP_CAPABILITY_ENHANCED_ROUTE_REFRESH:
case BGP_CAPABILITY_ROUTE_REFRESH_CISCO:
case BGP_CAPABILITY_ROUTE_REFRESH:
if (clen != 0) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u wrong, must be = 0", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
case BGP_CAPABILITY_ORF_CISCO:
case BGP_CAPABILITY_COOPERATIVE_ROUTE_FILTERING:
if (clen < 6) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Capability length %u too short, must be greater than 6", clen);
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
offset += clen;
}
else {
guint8 orfnum;
int i;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cap_tree, hf_bgp_cap_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_safi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
orfnum = tvb_get_guint8(tvb, offset);
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i=0; i<orfnum; i++) {
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cap_tree, hf_bgp_cap_orf_sendreceive, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
default:
if (clen != 0) {
proto_tree_add_item(cap_tree, hf_bgp_cap_unknown, tvb, offset, clen, ENC_NA);
}
offset += clen;
break;
}
return offset;
}
static void
dissect_bgp_open(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint8 optlen;
int ptype;
int plen;
int cend;
int oend;
int offset;
proto_item *ti;
proto_tree *opt_tree;
proto_tree *par_tree;
offset = BGP_MARKER_SIZE + 2 + 1;
proto_tree_add_item(tree, hf_bgp_open_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_bgp_open_myas, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bgp_open_holdtime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_bgp_open_identifier, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_bgp_open_opt_len, tvb, offset, 1, ENC_BIG_ENDIAN);
optlen = tvb_get_guint8(tvb, offset);
offset += 1;
if (optlen > 0) {
oend = offset + optlen;
ti = proto_tree_add_item(tree, hf_bgp_open_opt_params, tvb, offset, optlen, ENC_NA);
opt_tree = proto_item_add_subtree(ti, ett_bgp_options);
while (offset < oend) {
ti = proto_tree_add_item(opt_tree, hf_bgp_open_opt_param, tvb, offset, -1, ENC_NA);
par_tree = proto_item_add_subtree(ti, ett_bgp_options);
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_type, tvb, offset, 1, ENC_BIG_ENDIAN);
ptype = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti, ": %s", val_to_str(ptype, bgp_open_opt_vals, "Unknown Parameter %d"));
offset += 1;
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_len, tvb, offset, 1, ENC_BIG_ENDIAN);
plen = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, plen+2);
offset += 1;
switch (ptype) {
case BGP_OPTION_AUTHENTICATION:
proto_tree_add_item(par_tree, hf_bgp_open_opt_param_auth, tvb, offset, plen, ENC_NA);
offset += plen;
break;
case BGP_OPTION_CAPABILITY:
cend = offset + plen;
while (offset < cend) {
offset = dissect_bgp_capability_item(tvb, par_tree, pinfo, offset, FALSE);
}
break;
default:
proto_tree_add_item(opt_tree, hf_bgp_open_opt_param_unknown, tvb, offset, plen, ENC_NA);
break;
}
}
}
}
static void
dissect_bgp_update(tvbuff_t *tvb, proto_tree *tree)
{
guint8 bgpa_flags;
guint8 bgpa_type;
guint16 hlen;
gint o;
gint q;
gint end;
guint16 ext_com;
guint8 ext_com8;
gboolean is_regular_type;
gboolean is_extended_type;
guint16 len;
int advance;
proto_item *ti;
proto_tree *subtree;
proto_tree *subtree2;
proto_tree *subtree3;
proto_tree *subtree4;
proto_tree *subtree5;
proto_tree *subtree6;
proto_tree *as_paths_tree;
proto_tree *as_path_tree;
proto_tree *as_path_segment_tree;
proto_tree *communities_tree;
proto_tree *community_tree;
proto_tree *cluster_list_tree;
int i, j;
guint8 length;
guint8 type;
guint32 as_path_item;
emem_strbuf_t *as_path_emstr = NULL;
emem_strbuf_t *communities_emstr = NULL;
emem_strbuf_t *cluster_list_emstr = NULL;
emem_strbuf_t *junk_emstr;
guint32 ipaddr;
guint32 aggregator_as;
guint16 ssa_type;
guint16 ssa_len;
guint8 ssa_v3_len;
gfloat linkband;
guint16 as_num;
guint16 encaps_tunnel_type;
guint16 encaps_tunnel_len;
guint8 encaps_tunnel_subtype;
guint8 encaps_tunnel_sublen;
if (!tree)
return;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
o = BGP_HEADER_SIZE;
junk_emstr = ep_strbuf_new_label(NULL);
len = tvb_get_ntohs(tvb, o);
proto_tree_add_text(tree, tvb, o, 2,
"Unfeasible routes length: %u byte%s", len, plurality(len, "", "s"));
o += 2;
if (len > 0) {
ti = proto_tree_add_text(tree, tvb, o, len, "Withdrawn routes:");
subtree = proto_item_add_subtree(ti, ett_bgp_unfeas);
end = o + len;
if( detect_add_path_prefix4(tvb, o, end) ) {
while (o < end) {
i = decode_path_prefix4(subtree, hf_bgp_nlri_path_id, hf_bgp_withdrawn_prefix, tvb, o,
"Withdrawn route");
if (i < 0)
return;
o += i;
}
} else {
while (o < end) {
i = decode_prefix4(subtree, hf_bgp_withdrawn_prefix, tvb, o, len,
"Withdrawn route");
if (i < 0)
return;
o += i;
}
}
}
len = tvb_get_ntohs(tvb, o);
proto_tree_add_text(tree, tvb, o, 2, "Total path attribute length: %u byte%s",
len, plurality(len, "", "s"));
if (len > 0) {
ti = proto_tree_add_text(tree, tvb, o + 2, len, "Path attributes");
subtree = proto_item_add_subtree(ti, ett_bgp_attrs);
i = 2;
while (i < len) {
proto_item *hidden_item;
const char *msg;
int off;
gint k;
guint16 alen, tlen, aoff, aoff_save;
guint16 af;
guint8 saf, snpa;
guint8 nexthop_len;
guint8 asn_len = 0;
bgpa_flags = tvb_get_guint8(tvb, o + i);
bgpa_type = tvb_get_guint8(tvb, o + i+1);
if (bgpa_flags & BGP_ATTR_FLAG_EXTENDED_LENGTH) {
alen = tvb_get_ntohs(tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE);
aoff = BGP_SIZE_OF_PATH_ATTRIBUTE+2;
} else {
alen = tvb_get_guint8(tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE);
aoff = BGP_SIZE_OF_PATH_ATTRIBUTE+1;
}
tlen = alen;
switch (bgpa_type) {
case BGPTYPE_ORIGIN:
if (tlen != 1)
goto default_attribute_top;
msg = val_to_str_const(tvb_get_guint8(tvb, o + i + aoff), bgpattr_origin, "Unknown");
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
msg, tlen + aoff, plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_AS_PATH:
case BGPTYPE_NEW_AS_PATH:
q = o + i + aoff;
end = q + tlen;
if (as_path_emstr == NULL)
as_path_emstr = ep_strbuf_sized_new((tlen + 1) * 11, 0);
ep_strbuf_truncate(as_path_emstr, 0);
if (bgpa_type == BGPTYPE_NEW_AS_PATH)
asn_len = 4;
else {
if (bgp_asn_len == 0) {
guint unknown_segment_type = 0;
guint asn_is_null = 0;
guint d;
asn_len = 2;
k = q;
while ((k < end) && !unknown_segment_type && !asn_is_null)
{
type = tvb_get_guint8(tvb, k++);
if (type != AS_SET &&
type != AS_SEQUENCE &&
type != AS_CONFED_SEQUENCE &&
type != AS_CONFED_SEQUENCE)
unknown_segment_type = 1;
length = tvb_get_guint8(tvb, k++);
for (d = 0; d < length && !unknown_segment_type && !asn_is_null; d++)
{
if(tvb_get_ntohs(tvb, k) == 0)
asn_is_null = 1;
k += 2;
}
}
if(k != end || unknown_segment_type || asn_is_null)
asn_len = 4;
}
else {
asn_len = bgp_asn_len;
}
}
while (q < end) {
type = tvb_get_guint8(tvb, q++);
if (as_path_emstr->len > 1 &&
as_path_emstr->str[as_path_emstr->len - 1] != ' ')
ep_strbuf_append_c(as_path_emstr, ' ');
if (type == AS_SET) {
ep_strbuf_append_c(as_path_emstr, '{');
}
else if (type == AS_CONFED_SET) {
ep_strbuf_append_c(as_path_emstr, '[');
}
else if (type == AS_CONFED_SEQUENCE) {
ep_strbuf_append_c(as_path_emstr, '(');
}
length = tvb_get_guint8(tvb, q++);
for (j = 0; j < length; j++) {
ep_strbuf_append_printf(as_path_emstr, "%u%s",
(asn_len == 2) ?
tvb_get_ntohs(tvb, q) : tvb_get_ntohl(tvb, q),
(type == AS_SET || type == AS_CONFED_SET) ?
", " : " ");
q += asn_len;
}
if (type == AS_SET) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 2);
ep_strbuf_append_c(as_path_emstr, '}');
}
else if (type == AS_CONFED_SET) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 2);
ep_strbuf_append_c(as_path_emstr, ']');
}
else if (type == AS_CONFED_SEQUENCE) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 1);
ep_strbuf_append_c(as_path_emstr, ')');
}
else {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 1);
}
}
if (tlen == 0)
ep_strbuf_printf(as_path_emstr, "empty");
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
as_path_emstr->str, tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_NEXT_HOP:
if (tlen != 4)
goto default_attribute_top;
ipaddr = tvb_get_ipv4(tvb, o + i + aoff);
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
ip_to_str((guint8 *)&ipaddr), tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_MULTI_EXIT_DISC:
if (tlen != 4)
goto default_attribute_top;
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %u (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
tvb_get_ntohl(tvb, o + i + aoff), tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_LOCAL_PREF:
if (tlen != 4)
goto default_attribute_top;
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %u (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
tvb_get_ntohl(tvb, o + i + aoff), tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_ATOMIC_AGGREGATE:
if (tlen != 0)
goto default_attribute_top;
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
tlen + aoff, plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_AGGREGATOR:
if (tlen != 6 && tlen != 8)
goto default_attribute_top;
case BGPTYPE_NEW_AGGREGATOR:
if (bgpa_type == BGPTYPE_NEW_AGGREGATOR && tlen != 8)
goto default_attribute_top;
asn_len = tlen - 4;
ipaddr = tvb_get_ipv4(tvb, o + i + aoff + asn_len);
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: AS: %u origin: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
(asn_len == 2) ? tvb_get_ntohs(tvb, o + i + aoff) :
tvb_get_ntohl(tvb, o + i + aoff),
ip_to_str((guint8 *)&ipaddr),
tlen + aoff, plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_COMMUNITIES:
if (tlen % 4 != 0)
goto default_attribute_top;
q = o + i + aoff;
end = q + tlen;
if (communities_emstr == NULL)
communities_emstr = ep_strbuf_sized_new((tlen + 1) * 12, 0);
ep_strbuf_truncate(communities_emstr, 0);
while (q < end) {
if (tvb_get_ntohl(tvb, q) == BGP_COMM_NO_EXPORT)
ep_strbuf_append(communities_emstr, "NO_EXPORT ");
else if (tvb_get_ntohl(tvb, q) == BGP_COMM_NO_ADVERTISE)
ep_strbuf_append(communities_emstr, "NO_ADVERTISE ");
else if (tvb_get_ntohl(tvb, q) == BGP_COMM_NO_EXPORT_SUBCONFED)
ep_strbuf_append(communities_emstr, "NO_EXPORT_SUBCONFED ");
else {
ep_strbuf_append_printf(communities_emstr, "%u:%u ",
tvb_get_ntohs(tvb, q),
tvb_get_ntohs(tvb, q + 2));
}
q += 4;
}
ep_strbuf_truncate(communities_emstr, communities_emstr->len - 1);
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
communities_emstr->str, tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_ORIGINATOR_ID:
if (tlen != 4)
goto default_attribute_top;
ipaddr = tvb_get_ipv4(tvb, o + i + aoff);
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
ip_to_str((guint8 *)&ipaddr),
tlen + aoff, plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_CLUSTER_LIST:
if (tlen % 4 != 0)
goto default_attribute_top;
q = o + i + aoff;
end = q + tlen;
if (cluster_list_emstr == NULL)
cluster_list_emstr = ep_strbuf_sized_new((tlen + 1) * 16, 0);
ep_strbuf_truncate(cluster_list_emstr, 0);
while (q < end) {
ipaddr = tvb_get_ipv4(tvb, q);
ep_strbuf_append_printf(cluster_list_emstr, "%s ", ip_to_str((guint8 *)&ipaddr));
q += 4;
}
ep_strbuf_truncate(cluster_list_emstr, cluster_list_emstr->len - 1);
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s: %s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
cluster_list_emstr->str, tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_EXTENDED_COMMUNITY:
if (tlen %8 != 0)
break;
ti = proto_tree_add_text(subtree,tvb,o+i,tlen+aoff,
"%s: (%u byte%s)",
val_to_str_const(bgpa_type,bgpattr_type,"Unknown"),
tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
case BGPTYPE_SAFI_SPECIFIC_ATTR:
ti = proto_tree_add_text(subtree,tvb,o+i,tlen+aoff,
"%s: (%u byte%s)",
val_to_str_const(bgpa_type,bgpattr_type,"Unknown"),
tlen + aoff,
plurality(tlen + aoff, "", "s"));
break;
default:
default_attribute_top:
ti = proto_tree_add_text(subtree, tvb, o + i, tlen + aoff,
"%s (%u byte%s)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
tlen + aoff, plurality(tlen + aoff, "", "s"));
}
subtree2 = proto_item_add_subtree(ti, ett_bgp_attr);
ep_strbuf_truncate(junk_emstr, 0);
if (bgpa_flags & BGP_ATTR_FLAG_OPTIONAL) {
ep_strbuf_append(junk_emstr, "Optional, ");
}
else {
ep_strbuf_append(junk_emstr, "Well-known, ");
}
if (bgpa_flags & BGP_ATTR_FLAG_TRANSITIVE) {
ep_strbuf_append(junk_emstr, "Transitive, ");
}
else {
ep_strbuf_append(junk_emstr, "Non-transitive, ");
}
if (bgpa_flags & BGP_ATTR_FLAG_PARTIAL) {
ep_strbuf_append(junk_emstr, "Partial");
}
else {
ep_strbuf_append(junk_emstr, "Complete");
}
if (bgpa_flags & BGP_ATTR_FLAG_EXTENDED_LENGTH) {
ep_strbuf_append(junk_emstr, ", Extended Length");
}
ti = proto_tree_add_text(subtree2, tvb, o + i, 1,
"Flags: 0x%02x (%s)", bgpa_flags, junk_emstr->str);
subtree3 = proto_item_add_subtree(ti, ett_bgp_attr_flags);
proto_tree_add_item(subtree3, hf_bgp_flags_optional, tvb, o + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_flags_transitive, tvb, o + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_flags_partial, tvb, o + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree3, hf_bgp_flags_extended_length, tvb, o + i, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(subtree2, tvb,
o + i + 1, 1,
"Type code: %s (%u)",
val_to_str_const(bgpa_type, bgpattr_type, "Unknown"),
bgpa_type);
proto_tree_add_text(subtree2, tvb, o + i + BGP_SIZE_OF_PATH_ATTRIBUTE,
aoff - BGP_SIZE_OF_PATH_ATTRIBUTE, "Length: %d byte%s", tlen,
plurality(tlen, "", "s"));
switch (bgpa_type) {
case BGPTYPE_ORIGIN:
if (tlen != 1) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Origin (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_origin, tvb,
o + i + aoff, 1, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_AS_PATH:
case BGPTYPE_NEW_AS_PATH:
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"AS path: %s", as_path_emstr->str);
as_paths_tree = proto_item_add_subtree(ti, ett_bgp_as_paths);
q = o + i + aoff;
end = q + tlen;
while (q < end) {
ep_strbuf_truncate(as_path_emstr, 0);
type = tvb_get_guint8(tvb, q++);
if (type == AS_SET) {
ep_strbuf_append_c(as_path_emstr, '{');
}
else if (type == AS_CONFED_SET) {
ep_strbuf_append_c(as_path_emstr, '[');
}
else if (type == AS_CONFED_SEQUENCE) {
ep_strbuf_append_c(as_path_emstr, '(');
}
length = tvb_get_guint8(tvb, q++);
for (j = 0; j < length; j++) {
ep_strbuf_append_printf(as_path_emstr, "%u%s",
(asn_len == 2) ?
tvb_get_ntohs(tvb, q) : tvb_get_ntohl(tvb, q),
(type == AS_SET || type == AS_CONFED_SET) ? ", " : " ");
q += asn_len;
}
if (type == AS_SET) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 2);
ep_strbuf_append_c(as_path_emstr, '}');
}
else if (type == AS_CONFED_SET) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 2);
ep_strbuf_append_c(as_path_emstr, ']');
}
else if (type == AS_CONFED_SEQUENCE) {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 1);
ep_strbuf_append_c(as_path_emstr, ')');
}
else {
ep_strbuf_truncate(as_path_emstr, as_path_emstr->len - 1);
}
ti = proto_tree_add_text(as_paths_tree, tvb,
q - length * asn_len - 2,
length * asn_len + 2, "AS path segment: %s", as_path_emstr->str);
as_path_tree = proto_item_add_subtree(ti, ett_bgp_as_paths);
proto_tree_add_text(as_path_tree, tvb, q - length * asn_len - 2,
1, "Path segment type: %s (%u)",
val_to_str_const(type, as_segment_type, "Unknown"), type);
proto_tree_add_text(as_path_tree, tvb, q - length * asn_len - 1,
1, "Path segment length: %u AS%s", length,
plurality(length, "", "s"));
q -= asn_len * length;
ti = proto_tree_add_text(as_path_tree, tvb, q,
length * asn_len, "Path segment value:");
as_path_segment_tree = proto_item_add_subtree(ti,
ett_bgp_as_path_segments);
for (j = 0; j < length; j++) {
as_path_item = (asn_len == 2) ?
tvb_get_ntohs(tvb, q) : tvb_get_ntohl(tvb, q);
proto_item_append_text(ti, " %u", as_path_item);
hidden_item = proto_tree_add_uint(as_path_segment_tree, hf_bgp_as_path, tvb,
q, asn_len, as_path_item);
PROTO_ITEM_SET_HIDDEN(hidden_item);
q += asn_len;
}
}
break;
case BGPTYPE_NEXT_HOP:
if (tlen != 4) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Next hop (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_next_hop, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_MULTI_EXIT_DISC:
if (tlen != 4) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Multiple exit discriminator (invalid): %u byte%s",
tlen, plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_multi_exit_disc, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_LOCAL_PREF:
if (tlen != 4) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Local preference (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_local_pref, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_ATOMIC_AGGREGATE:
if (tlen != 0) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Atomic aggregate (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
}
break;
case BGPTYPE_AGGREGATOR:
if (tlen != 6 && tlen != 8) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Aggregator (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
case BGPTYPE_NEW_AGGREGATOR:
if (bgpa_type == BGPTYPE_NEW_AGGREGATOR && tlen != 8)
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Aggregator (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
else {
asn_len = tlen - 4;
aggregator_as = (asn_len == 2) ?
tvb_get_ntohs(tvb, o + i + aoff) :
tvb_get_ntohl(tvb, o + i + aoff);
proto_tree_add_uint(subtree2, hf_bgp_aggregator_as, tvb,
o + i + aoff, asn_len, aggregator_as);
proto_tree_add_item(subtree2, hf_bgp_aggregator_origin, tvb,
o + i + aoff + asn_len, 4, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_COMMUNITIES:
if (tlen % 4 != 0) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Communities (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Communities: %s", communities_emstr ? communities_emstr->str : "<none>");
communities_tree = proto_item_add_subtree(ti,
ett_bgp_communities);
q = o + i + aoff;
end = q + tlen;
while (q < end) {
guint32 community = tvb_get_ntohl(tvb, q);
if ((community & 0xFFFF0000) == FOURHEX0 ||
(community & 0xFFFF0000) == FOURHEXF) {
proto_tree_add_text(communities_tree, tvb,
q - 3 + aoff, 4,
"Community: %s (0x%08x)",
val_to_str_const(community, community_vals, "(reserved)"),
community);
}
else {
ti = proto_tree_add_text(communities_tree, tvb,
q - 3 + aoff, 4, "Community: %u:%u",
tvb_get_ntohs(tvb, q), tvb_get_ntohs(tvb, q + 2));
community_tree = proto_item_add_subtree(ti,
ett_bgp_communities);
proto_tree_add_item(community_tree, hf_bgp_community_as,
tvb, q - 3 + aoff, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(community_tree, hf_bgp_community_value,
tvb, q - 1 + aoff, 2, ENC_BIG_ENDIAN);
}
q += 4;
}
break;
case BGPTYPE_ORIGINATOR_ID:
if (tlen != 4) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Originator identifier (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
proto_tree_add_item(subtree2, hf_bgp_originator_id, tvb,
o + i + aoff, tlen, ENC_BIG_ENDIAN);
}
break;
case BGPTYPE_MP_REACH_NLRI:
af = tvb_get_ntohs(tvb, o + i + aoff);
proto_tree_add_text(subtree2, tvb, o + i + aoff, 2,
"Address family: %s (%u)",
val_to_str_const(af, afn_vals, "Unknown"), af);
saf = tvb_get_guint8(tvb, o + i + aoff + 2) ;
proto_tree_add_text(subtree2, tvb, o + i + aoff + 2, 1,
"Subsequent address family identifier: %s (%u)",
val_to_str_const(saf, bgpattr_nlri_safi, saf >= 128 ? "Vendor specific" : "Unknown"),
saf);
nexthop_len = tvb_get_guint8(tvb, o + i + aoff + 3);
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff + 3,
nexthop_len + 1,
"Next hop network address (%d byte%s)",
nexthop_len, plurality(nexthop_len, "", "s"));
subtree3 = proto_item_add_subtree(ti, ett_bgp_mp_nhna);
switch (af) {
default:
proto_tree_add_text(subtree3, tvb, o + i + aoff + 4,
nexthop_len, "Unknown Address Family");
break;
case AFNUM_INET:
case AFNUM_INET6:
case AFNUM_L2VPN:
case AFNUM_L2VPN_OLD:
j = 0;
while (j < nexthop_len) {
advance = mp_addr_to_str(af, saf, tvb, o + i + aoff + 4 + j,
junk_emstr, nexthop_len) ;
if (advance == 0)
break;
if (j + advance > nexthop_len)
break;
proto_tree_add_text(subtree3, tvb,o + i + aoff + 4 + j,
advance, "Next hop: %s (%u)", junk_emstr->str, advance);
j += advance;
}
break;
}
aoff_save = aoff;
tlen -= nexthop_len + 4;
aoff += nexthop_len + 4 ;
off = 0;
snpa = tvb_get_guint8(tvb, o + i + aoff);
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff, 1,
"Subnetwork points of attachment: %u", snpa);
off++;
if (snpa) {
subtree3 = proto_item_add_subtree(ti, ett_bgp_mp_snpa);
for (; snpa > 0; snpa--) {
proto_tree_add_text(subtree3, tvb, o + i + aoff + off, 1,
"SNPA length: %u", tvb_get_guint8(tvb, o + i + aoff + off));
off++;
proto_tree_add_text(subtree3, tvb, o + i + aoff + off,
tvb_get_guint8(tvb, o + i + aoff + off - 1),
"SNPA (%u byte%s)", tvb_get_guint8(tvb, o + i + aoff + off - 1),
plurality(tvb_get_guint8(tvb, o + i + aoff + off - 1), "", "s"));
off += tvb_get_guint8(tvb, o + i + aoff + off - 1);
}
}
tlen -= off;
aoff += off;
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Network layer reachability information (%u byte%s)",
tlen, plurality(tlen, "", "s"));
if (tlen) {
subtree3 = proto_item_add_subtree(ti,ett_bgp_mp_reach_nlri);
if (af != AFNUM_INET && af != AFNUM_INET6 && af != AFNUM_L2VPN) {
proto_tree_add_text(subtree3, tvb, o + i + aoff,
tlen, "Unknown Address Family");
} else {
while (tlen > 0) {
advance = decode_prefix_MP(subtree3,
hf_bgp_mp_reach_nlri_ipv4_prefix,
-1,
af, saf,
tvb, o + i + aoff, "MP Reach NLRI");
if (advance < 0)
break;
tlen -= advance;
aoff += advance;
}
}
}
aoff = aoff_save;
break;
case BGPTYPE_MP_UNREACH_NLRI:
af = tvb_get_ntohs(tvb, o + i + aoff);
proto_tree_add_text(subtree2, tvb, o + i + aoff, 2,
"Address family: %s (%u)",
val_to_str_const(af, afn_vals, "Unknown"), af);
saf = tvb_get_guint8(tvb, o + i + aoff + 2) ;
proto_tree_add_text(subtree2, tvb, o + i + aoff + 2, 1,
"Subsequent address family identifier: %s (%u)",
val_to_str_const(saf, bgpattr_nlri_safi, saf >= 128 ? "Vendor specific" : "Unknown"),
saf);
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff + 3,
tlen - 3, "Withdrawn routes (%u byte%s)", tlen - 3,
plurality(tlen - 3, "", "s"));
aoff_save = aoff;
tlen -= 3;
aoff += 3;
if (tlen > 0) {
subtree3 = proto_item_add_subtree(ti,ett_bgp_mp_unreach_nlri);
while (tlen > 0) {
advance = decode_prefix_MP(subtree3,
hf_bgp_mp_unreach_nlri_ipv4_prefix,
-1,
af, saf,
tvb, o + i + aoff, "MP Unreach NLRI");
if (advance < 0)
break;
tlen -= advance;
aoff += advance;
}
}
aoff = aoff_save;
break;
case BGPTYPE_CLUSTER_LIST:
if (tlen % 4 != 0) {
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Cluster list (invalid): %u byte%s", tlen,
plurality(tlen, "", "s"));
break;
}
ti = proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Cluster list: %s", cluster_list_emstr ? cluster_list_emstr->str : "<none>");
cluster_list_tree = proto_item_add_subtree(ti,
ett_bgp_cluster_list);
q = o + i + aoff;
end = q + tlen;
while (q < end) {
proto_tree_add_item(cluster_list_tree, hf_bgp_cluster_list,
tvb, q - 3 + aoff, 4, ENC_NA);
q += 4;
}
break;
case BGPTYPE_EXTENDED_COMMUNITY:
if (tlen %8 != 0) {
proto_tree_add_text(subtree3, tvb, o + i + aoff, tlen, "Extended community (invalid) : %u byte%s", tlen,
plurality(tlen, "", "s"));
} else {
q = o + i + aoff ;
end = o + i + aoff + tlen ;
ti = proto_tree_add_text(subtree2,tvb,q,tlen, "Carried Extended communities");
subtree3 = proto_item_add_subtree(ti,ett_bgp_extended_communities);
while (q < end) {
ext_com8 = tvb_get_guint8(tvb,q);
ext_com = tvb_get_ntohs(tvb,q);
ep_strbuf_printf(junk_emstr, "%s", val_to_str(ext_com8,bgpext_com8_type,"Unknown %d"));
is_regular_type = FALSE;
is_extended_type = FALSE;
switch (ext_com8) {
case BGP_EXT_COM_QOS_MARK_T:
case BGP_EXT_COM_QOS_MARK_NT:
is_regular_type = TRUE;
ti = proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
subtree4 = proto_item_add_subtree(ti,ett_bgp_extended_communities);
proto_tree_add_text(subtree4, tvb, q, 1,
"Type: 0x%02x", tvb_get_guint8(tvb,q));
ti = proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_flags, tvb, q+1, 1, ENC_BIG_ENDIAN);
subtree5 = proto_item_add_subtree(ti,ett_bgp_ext_com_flags);
proto_tree_add_item(subtree5, hf_bgp_ext_com_qos_flags_remarking, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree5, hf_bgp_ext_com_qos_flags_ignore_remarking, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree5, hf_bgp_ext_com_qos_flags_agg_marking, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_set_number, tvb, q+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_tech_type, tvb, q+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_marking_o, tvb, q+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_marking_a, tvb, q+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ext_com_qos_default_to_zero, tvb, q+7, 1, ENC_BIG_ENDIAN);
break;
case BGP_EXT_COM_COS_CAP_T:
is_regular_type = TRUE;
ti = proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
subtree4 = proto_item_add_subtree(ti,ett_bgp_extended_communities);
proto_tree_add_text(subtree4, tvb, q, 1,
"Type: 0x%02x", tvb_get_guint8(tvb,q));
ti = proto_tree_add_item(subtree4, hf_bgp_ext_com_cos_flags, tvb, q+1, 1, ENC_BIG_ENDIAN);
subtree5 = proto_item_add_subtree(ti,ett_bgp_ext_com_flags);
proto_tree_add_item(subtree5, hf_bgp_ext_com_cos_flags_be, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree5, hf_bgp_ext_com_cos_flags_ef, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree5, hf_bgp_ext_com_cos_flags_af, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree5, hf_bgp_ext_com_cos_flags_le, tvb, q+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(subtree4, tvb, q+2, 1,
"Flags byte 2..7 : 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
tvb_get_guint8(tvb,q+2),tvb_get_guint8(tvb,q+3),tvb_get_guint8(tvb,q+4),
tvb_get_guint8(tvb,q+5),tvb_get_guint8(tvb,q+6),tvb_get_guint8(tvb,q+7));
break;
}
if (!is_regular_type) {
ep_strbuf_printf(junk_emstr, "%s", val_to_str(ext_com,bgpext_com_type,"Unknown %d"));
switch (ext_com) {
case BGP_EXT_COM_RT_0:
case BGP_EXT_COM_RO_0:
is_extended_type = TRUE;
ep_strbuf_append_printf(junk_emstr, ": %u%s%d",
tvb_get_ntohs(tvb,q+2),":",tvb_get_ntohl(tvb,q+4));
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break ;
case BGP_EXT_COM_RT_1:
case BGP_EXT_COM_RO_1:
is_extended_type = TRUE;
ipaddr = tvb_get_ipv4(tvb,q+2);
ep_strbuf_append_printf(junk_emstr, ": %s%s%u",
ip_to_str((guint8 *)&ipaddr),":",tvb_get_ntohs(tvb,q+6));
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break;
case BGP_EXT_COM_RT_2:
case BGP_EXT_COM_RO_2:
is_extended_type = TRUE;
ep_strbuf_append_printf(junk_emstr, ": %u.%u:%u",
tvb_get_ntohs(tvb,q+2),tvb_get_ntohs(tvb,q+4) ,tvb_get_ntohs(tvb,q+6));
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break;
case BGP_EXT_COM_VPN_ORIGIN:
case BGP_EXT_COM_OSPF_RID:
is_extended_type = TRUE;
ipaddr = tvb_get_ipv4(tvb,q+2);
ep_strbuf_append_printf(junk_emstr, ": %s", ip_to_str((guint8 *)&ipaddr));
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break;
case BGP_EXT_COM_OSPF_RTYPE:
is_extended_type = TRUE;
ipaddr = tvb_get_ipv4(tvb,q+2);
ep_strbuf_append_printf(junk_emstr, ": Area: %s, Type: %s", ip_to_str((guint8 *)&ipaddr),
val_to_str_const(tvb_get_guint8(tvb,q+6),bgpext_ospf_rtype,"Unknown"));
if ( (tvb_get_guint8(tvb,q+7)) & BGP_OSPF_RTYPE_METRIC_TYPE ) {
ep_strbuf_append(junk_emstr, " E2");
} else if ((tvb_get_guint8(tvb,q+6)==BGP_OSPF_RTYPE_EXT) || (tvb_get_guint8(tvb,q+6)==BGP_OSPF_RTYPE_NSSA)) {
ep_strbuf_append(junk_emstr, " E1");
} else {
ep_strbuf_append(junk_emstr, ", no options");
}
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break;
case BGP_EXT_COM_LINKBAND:
is_extended_type = TRUE;
as_num = tvb_get_ntohs(tvb,q+2);
linkband = tvb_get_ntohieee_float(tvb,q+4);
ep_strbuf_append_printf(junk_emstr, ": ASN %u, %.3f Mbps", as_num,linkband*8/1000000);
proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
break;
case BGP_EXT_COM_L2INFO:
is_extended_type = TRUE;
ep_strbuf_append_printf(junk_emstr,
": %s, Control Flags: %s%s%s%s%s, MTU: %u byte%s",
val_to_str_const(tvb_get_guint8(tvb,q+2),bgp_l2vpn_encaps,"Unknown"),
tvb_get_guint8(tvb,q+3) ? "" : "none",
tvb_get_ntohs(tvb,q+3)&0x08 ? "Q" : "",
tvb_get_ntohs(tvb,q+3)&0x04 ? "F" : "",
tvb_get_ntohs(tvb,q+3)&0x02 ? "C" : "",
tvb_get_ntohs(tvb,q+3)&0x01 ? "S" : "",
tvb_get_ntohs(tvb,q+4),
plurality(tvb_get_ntohs(tvb,q+4), "", "s"));
ti = proto_tree_add_text(subtree3,tvb,q,8, "%s",junk_emstr->str);
subtree4 = proto_item_add_subtree(ti,ett_bgp_extended_communities);
proto_tree_add_text(subtree4,tvb,q+2,1, "Encapsulation: %s",
val_to_str_const(tvb_get_guint8(tvb,q+2),bgp_l2vpn_encaps,"Unknown"));
proto_tree_add_text(subtree4,tvb,q+3,1, "Control Flags: %s%sControl Word %s required, Sequenced delivery %s required",
tvb_get_ntohs(tvb,q+3)&0x08 ? "Q flag (Reserved) set" : "",
tvb_get_ntohs(tvb,q+3)&0x04 ? "F flag (reserved) set" : "",
tvb_get_ntohs(tvb,q+3)&0x02 ? "is" : "not",
tvb_get_ntohs(tvb,q+3)&0x01 ? "is" : "not");
proto_tree_add_text(subtree4,tvb,q+4,2, "MTU: %u byte%s",
tvb_get_ntohs(tvb,q+4),
plurality(tvb_get_ntohs(tvb,q+4), "", "s"));
break;
}
}
if (!is_regular_type && !is_extended_type)
proto_tree_add_text(subtree3,tvb,q,8, "%s","Unknown");
q = q + 8;
}
}
break;
case BGPTYPE_SAFI_SPECIFIC_ATTR:
q = o + i + aoff;
end = o + i + aoff + tlen ;
while(q < end) {
ssa_type = tvb_get_ntohs(tvb, q) & BGP_SSA_TYPE;
ssa_len = tvb_get_ntohs(tvb, q + 2);
ti = proto_tree_add_text(subtree2, tvb, q, MIN(ssa_len + 4, end - q),
"%s Information",
val_to_str_const(ssa_type, bgp_ssa_type, "Unknown SSA"));
subtree3 = proto_item_add_subtree(ti, ett_bgp_ssa);
proto_tree_add_item(subtree3, hf_bgp_ssa_t, tvb,
q, 1, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(subtree3, hf_bgp_ssa_type, tvb,
q, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(subtree3, tvb, q, 2,
"Type: %s", val_to_str_const(ssa_type, bgp_ssa_type, "Unknown"));
if ((ssa_len == 0) || (q + ssa_len > end)) {
proto_tree_add_text(subtree3, tvb, q + 2, end - q - 2,
"Invalid Length of %u", ssa_len);
break;
}
proto_tree_add_item(subtree3, hf_bgp_ssa_len, tvb,
q + 2, 2, ENC_BIG_ENDIAN);
switch (ssa_type) {
case BGP_SSA_L2TPv3:
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_pref, tvb,
q + 4, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_text(subtree3, tvb, q + 6, 1, "Flags");
subtree4 = proto_item_add_subtree(ti, ett_bgp_ssa_subtree) ;
proto_tree_add_item(subtree4, hf_bgp_ssa_l2tpv3_s, tvb,
q + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree4, hf_bgp_ssa_l2tpv3_unused, tvb,
q + 6, 1, ENC_BIG_ENDIAN);
ssa_v3_len = tvb_get_guint8(tvb, q + 7);
if (ssa_v3_len + 8 == ssa_len){
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_cookie_len, tvb,
q + 7, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_text(subtree3, tvb, q + 7, 1,
"Invalid Cookie Length of %u", ssa_v3_len);
q += ssa_len + 4;
break;
}
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_session_id, tvb,
q + 8, 4, ENC_BIG_ENDIAN);
if (ssa_v3_len)
proto_tree_add_item(subtree3, hf_bgp_ssa_l2tpv3_cookie, tvb,
q + 12, ssa_v3_len, ENC_NA);
q += ssa_len + 4;
break;
case BGP_SSA_mGRE:
case BGP_SSA_IPSec:
case BGP_SSA_MPLS:
default:
proto_tree_add_item(subtree3, hf_bgp_ssa_value, tvb,
q + 4, ssa_len, ENC_NA);
q += ssa_len + 4;
break;
case BGP_SSA_L2TPv3_IN_IPSec:
case BGP_SSA_mGRE_IN_IPSec:
q += 4;
break;
}
}
break;
case BGPTYPE_TUNNEL_ENCAPS_ATTR:
q = o + i + aoff;
end = o + i + aoff + tlen;
ti = proto_tree_add_text(subtree2, tvb, q, tlen, "TLV Encodings");
subtree3 = proto_item_add_subtree(ti, ett_bgp_tunnel_tlv);
while (q < end) {
encaps_tunnel_type = tvb_get_ntohs(tvb, q);
encaps_tunnel_len = tvb_get_ntohs(tvb, q + 2);
ti = proto_tree_add_text(subtree3, tvb, q, encaps_tunnel_len + 4, "%s (%u bytes)", val_to_str_const(encaps_tunnel_type, tunnel_type, "Unknown"), encaps_tunnel_len + 4);
subtree4 = proto_item_add_subtree(ti, ett_bgp_tunnel_tlv_subtree);
proto_tree_add_item(subtree4, hf_bgp_encaps_tunnel_tlv_type, tvb, q, 2, ENC_NA);
proto_tree_add_item(subtree4, hf_bgp_encaps_tunnel_tlv_len, tvb, q + 2, 2, ENC_NA);
ti = proto_tree_add_text(subtree4, tvb, q + 4, encaps_tunnel_len, "Sub-TLV Encodings");
subtree5 = proto_item_add_subtree(ti, ett_bgp_tunnel_subtlv);
q += 4;
j = q + encaps_tunnel_len;
while ( q < j ) {
encaps_tunnel_subtype = tvb_get_guint8(tvb, q);
encaps_tunnel_sublen = tvb_get_guint8(tvb, q + 1);
ti = proto_tree_add_text(subtree5, tvb, q, encaps_tunnel_sublen + 2, "%s (%u bytes)", val_to_str_const(encaps_tunnel_subtype, subtlv_type, "Unknown"), encaps_tunnel_sublen + 2);
subtree6 = proto_item_add_subtree(ti, ett_bgp_tunnel_tlv_subtree);
proto_tree_add_item(subtree6, hf_bgp_encaps_tunnel_subtlv_type, tvb, q, 1, ENC_NA);
proto_tree_add_item(subtree6, hf_bgp_encaps_tunnel_subtlv_len, tvb, q + 1, 1, ENC_NA);
switch (encaps_tunnel_subtype) {
case TUNNEL_SUBTLV_ENCAPSULATION:
if (encaps_tunnel_type == TUNNEL_TYPE_L2TP_OVER_IP) {
proto_tree_add_text(subtree6, tvb, q + 2, 4, "Session ID: %u", tvb_get_letohl(tvb, q + 2));
proto_tree_add_text(subtree6, tvb, q + 6, encaps_tunnel_sublen - 4, "Cookie: %s", tvb_bytes_to_str(tvb, q + 6, encaps_tunnel_sublen - 4));
} else if (encaps_tunnel_type == TUNNEL_TYPE_GRE) {
proto_tree_add_text(subtree6, tvb, q + 2, encaps_tunnel_sublen, "GRE key: %x", tvb_get_letohl(tvb, q + 2));
}
break;
case TUNNEL_SUBTLV_PROTO_TYPE:
proto_tree_add_text(subtree6, tvb, q + 2, encaps_tunnel_sublen, "Protocol type: %s (0x%x)", val_to_str_const(tvb_get_ntohs(tvb, q + 2), etype_vals, "Unknown"), tvb_get_ntohs(tvb, q + 2));
break;
case TUNNEL_SUBTLV_COLOR:
proto_tree_add_text(subtree6, tvb, q + 6, encaps_tunnel_sublen - 4, "Color value: %u", tvb_get_letohl(tvb, q + 6));
break;
case TUNNEL_SUBTLV_LOAD_BALANCE:
if (encaps_tunnel_type == TUNNEL_TYPE_L2TP_OVER_IP || encaps_tunnel_type == TUNNEL_TYPE_GRE) {
proto_tree_add_text(subtree6, tvb, q + 2, encaps_tunnel_sublen, "Load-balancing block length: %u", tvb_get_ntohs(tvb, q + 2));
}
break;
default:
break;
}
q += 2 + encaps_tunnel_sublen;
}
}
break;
default:
proto_tree_add_text(subtree2, tvb, o + i + aoff, tlen,
"Unknown (%u byte%s)", tlen, plurality(tlen, "", "s"));
break;
}
i += alen + aoff;
}
o += 2 + len;
len = hlen - o;
if (len > 0) {
ti = proto_tree_add_text(tree, tvb, o, len,
"Network layer reachability information: %u byte%s", len,
plurality(len, "", "s"));
subtree = proto_item_add_subtree(ti, ett_bgp_nlri);
end = o + len;
if( detect_add_path_prefix4(tvb, o, end) ) {
while (o < end) {
i = decode_path_prefix4(subtree, hf_bgp_nlri_path_id, hf_bgp_nlri_prefix, tvb, o,
"NLRI");
if (i < 0)
return;
o += i;
}
} else {
while (o < end) {
i = decode_prefix4(subtree, hf_bgp_nlri_prefix, tvb, o, 0,
"NLRI");
if (i < 0)
return;
o += i;
}
}
}
}
}
static void
dissect_bgp_notification(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int hlen;
int offset;
guint major_error;
proto_item *ti;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
offset = BGP_MARKER_SIZE + 2 + 1;
proto_tree_add_item(tree, hf_bgp_notify_major_error, tvb, offset, 1, ENC_NA);
major_error = tvb_get_guint8(tvb, offset);
offset += 1;
switch(major_error){
case BGP_MAJOR_ERROR_MSG_HDR:
proto_tree_add_item(tree, hf_bgp_notify_minor_msg_hdr, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_OPEN_MSG:
proto_tree_add_item(tree, hf_bgp_notify_minor_open_msg, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_UPDATE_MSG:
proto_tree_add_item(tree,hf_bgp_notify_minor_update_msg, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_HT_EXPIRED:
proto_tree_add_item(tree, hf_bgp_notify_minor_ht_expired, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_STATE_MACHINE:
proto_tree_add_item(tree, hf_bgp_notify_minor_state_machine, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_CEASE:
proto_tree_add_item(tree, hf_bgp_notify_minor_cease, tvb, offset, 1, ENC_NA);
break;
case BGP_MAJOR_ERROR_CAP_MSG:
proto_tree_add_item(tree, hf_bgp_notify_minor_cap_msg, tvb, offset, 1, ENC_NA);
break;
default:
ti = proto_tree_add_item(tree, hf_bgp_notify_minor_unknown, tvb, offset, 1, ENC_NA);
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_NOTE, "Unknown notification error (%d)",major_error);
break;
}
offset += 1;
if (hlen > BGP_MIN_NOTIFICATION_MSG_SIZE) {
proto_tree_add_item(tree, hf_bgp_notify_data, tvb, offset, hlen - BGP_MIN_NOTIFICATION_MSG_SIZE, ENC_NA);
}
}
static void
dissect_bgp_route_refresh(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int p;
int pend;
guint16 hlen;
proto_item *ti;
proto_item *ti1;
proto_tree *subtree;
proto_tree *subtree1;
guint8 orftype;
guint16 orflen;
guint8 entryflag;
int entrylen;
int advance;
if (!tree)
return;
hlen = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
p = BGP_HEADER_SIZE;
proto_tree_add_item(tree, hf_bgp_route_refresh_afi, tvb, p, 2, ENC_BIG_ENDIAN);
p += 2;
proto_tree_add_item(tree, hf_bgp_route_refresh_subtype, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(tree, hf_bgp_route_refresh_safi, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
if ( hlen == BGP_HEADER_SIZE + 4 )
return;
while (p < hlen) {
ti = proto_tree_add_item(tree, hf_bgp_route_refresh_orf, tvb, p, 4, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_bgp_orf);
proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_flag, tvb, p, 1, ENC_BIG_ENDIAN);
p += 1;
ti1 = proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_type, tvb, p , 1, ENC_BIG_ENDIAN);
orftype = tvb_get_guint8(tvb, p);
p += 1;
proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_length, tvb, p , 2, ENC_BIG_ENDIAN);
orflen = tvb_get_ntohs(tvb, p);
proto_item_set_len(ti, orflen + 4);
p += 2;
if (orftype != BGP_ORF_PREFIX_CISCO) {
expert_add_info_format(pinfo, ti1, PI_CHAT, PI_ERROR, "ORFEntry-Unknown (type %u)", orftype);
p += orflen;
continue;
}
pend = p + orflen;
while (p < pend) {
ti1 = proto_tree_add_item(subtree, hf_bgp_route_refresh_orf_entry_prefixlist, tvb, p, 1, ENC_NA);
subtree1 = proto_item_add_subtree(ti1, ett_bgp_orf_entry);
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_action, tvb, p, 1, ENC_BIG_ENDIAN);
entryflag = tvb_get_guint8(tvb, p);
if (((entryflag & BGP_ORF_ACTION) >> 6) == BGP_ORF_REMOVEALL) {
p++;
continue;
}
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_match, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_sequence, tvb, p, 4, ENC_BIG_ENDIAN);
p +=4;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_prefixmask_lower, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
proto_tree_add_item(subtree1, hf_bgp_route_refresh_orf_entry_prefixmask_upper, tvb, p, 1, ENC_BIG_ENDIAN);
p++;
advance = decode_prefix4(subtree1, -1, tvb, p, 0, "ORF");
if (advance < 0)
break;
entrylen = 7 + 1 + advance;
proto_item_set_len(ti1, entrylen);
p += advance;
}
}
}
static void
dissect_bgp_capability(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
int offset = 0;
int mend;
mend = offset + tvb_get_ntohs(tvb, offset + BGP_MARKER_SIZE);
offset += BGP_HEADER_SIZE;
while (offset < mend) {
offset = dissect_bgp_capability_item(tvb, tree, pinfo, offset, TRUE);
}
}
static void
dissect_bgp_pdu(tvbuff_t *volatile tvb, packet_info *pinfo, proto_tree *tree,
gboolean first)
{
guint16 bgp_len;
guint8 bgp_type;
const char *typ;
proto_item *ti_len = NULL;
proto_tree *bgp_tree = NULL;
bgp_len = tvb_get_ntohs(tvb, BGP_MARKER_SIZE);
bgp_type = tvb_get_guint8(tvb, BGP_MARKER_SIZE + 2);
typ = val_to_str(bgp_type, bgptypevals, "Unknown message type (0x%02x)");
if (first)
col_add_str(pinfo->cinfo, COL_INFO, typ);
else
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", typ);
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_bgp, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " - %s", typ);
switch (bgp_type) {
case BGP_OPEN:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_open);
break;
case BGP_UPDATE:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_update);
break;
case BGP_NOTIFICATION:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_notification);
break;
case BGP_KEEPALIVE:
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
break;
case BGP_ROUTE_REFRESH_CISCO:
case BGP_ROUTE_REFRESH:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_route_refresh);
break;
case BGP_CAPABILITY:
bgp_tree = proto_item_add_subtree(ti, ett_bgp_capability);
break;
default:
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
break;
}
proto_tree_add_item(bgp_tree, hf_bgp_marker, tvb, 0, 16, ENC_NA);
ti_len = proto_tree_add_item(bgp_tree, hf_bgp_length, tvb, 16, 2, ENC_BIG_ENDIAN);
}
if (bgp_len < BGP_HEADER_SIZE || bgp_len > BGP_MAX_PACKET_SIZE) {
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Length is invalid %u", bgp_len);
return;
}
proto_tree_add_item(bgp_tree, hf_bgp_type, tvb, 16 + 2, 1, ENC_BIG_ENDIAN);
switch (bgp_type) {
case BGP_OPEN:
dissect_bgp_open(tvb, bgp_tree, pinfo);
break;
case BGP_UPDATE:
dissect_bgp_update(tvb, bgp_tree);
break;
case BGP_NOTIFICATION:
dissect_bgp_notification(tvb, bgp_tree, pinfo);
break;
case BGP_KEEPALIVE:
break;
case BGP_ROUTE_REFRESH_CISCO:
case BGP_ROUTE_REFRESH:
dissect_bgp_route_refresh(tvb, bgp_tree, pinfo);
break;
case BGP_CAPABILITY:
dissect_bgp_capability(tvb, bgp_tree, pinfo);
break;
default:
break;
}
}
static void
dissect_bgp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
volatile int offset = 0;
gint reported_length_remaining;
guint8 bgp_marker[BGP_MARKER_SIZE];
static guchar marker[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
proto_item *ti;
proto_tree *bgp_tree;
guint16 bgp_len;
int offset_before;
guint length_remaining;
guint length;
volatile gboolean first = TRUE;
tvbuff_t *volatile next_tvb;
void *pd_save;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BGP");
col_clear(pinfo->cinfo, COL_INFO);
while ((reported_length_remaining = tvb_reported_length_remaining(tvb, offset))
> 0) {
if (reported_length_remaining > BGP_MARKER_SIZE)
reported_length_remaining = BGP_MARKER_SIZE;
tvb_memcpy(tvb, bgp_marker, offset, reported_length_remaining);
if (memcmp(bgp_marker, marker, reported_length_remaining) == 0) {
break;
}
offset++;
}
if (offset > 0) {
ti = proto_tree_add_item(tree, proto_bgp, tvb, 0, -1, ENC_NA);
bgp_tree = proto_item_add_subtree(ti, ett_bgp);
proto_tree_add_text(bgp_tree, tvb, 0, offset, "Continuation");
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (bgp_desegment && pinfo->can_desegment) {
if (length_remaining < BGP_HEADER_SIZE) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
bgp_len = tvb_get_ntohs(tvb, offset + BGP_MARKER_SIZE);
if (bgp_len < BGP_HEADER_SIZE) {
show_reported_bounds_error(tvb, pinfo, tree);
return;
}
if (bgp_desegment && pinfo->can_desegment) {
if (length_remaining < bgp_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = bgp_len - length_remaining;
return;
}
}
length = length_remaining;
if (length > bgp_len)
length = bgp_len;
next_tvb = tvb_new_subset(tvb, offset, length, bgp_len);
pd_save = pinfo->private_data;
TRY {
dissect_bgp_pdu(next_tvb, pinfo, tree, first);
}
CATCH_NONFATAL_ERRORS {
pinfo->private_data = pd_save;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
first = FALSE;
offset_before = offset;
offset += bgp_len;
if (offset <= offset_before)
break;
}
}
void
proto_register_bgp(void)
{
static hf_register_info hf[] = {
{ &hf_bgp_marker,
{ "Marker", "bgp.marker", FT_BYTES, BASE_NONE,
NULL, 0x0, "Must be set to all ones (16 Bytes)", HFILL }},
{ &hf_bgp_length,
{ "Length", "bgp.length", FT_UINT16, BASE_DEC,
NULL, 0x0, "The total length of the message, including the header in octets", HFILL }},
{ &hf_bgp_type,
{ "Type", "bgp.type", FT_UINT8, BASE_DEC,
VALS(bgptypevals), 0x0, "BGP message type", HFILL }},
{ &hf_bgp_open_version,
{ "Version", "bgp.open.version", FT_UINT8, BASE_DEC,
NULL, 0x0, "The protocol version number", HFILL }},
{ &hf_bgp_open_myas,
{ "My AS", "bgp.open.myas", FT_UINT16, BASE_DEC,
NULL, 0x0, "The Autonomous System number of the sender", HFILL }},
{ &hf_bgp_open_holdtime,
{ "Hold Time", "bgp.open.holdtime", FT_UINT16, BASE_DEC,
NULL, 0x0, "The number of seconds the sender proposes for Hold Time", HFILL }},
{ &hf_bgp_open_identifier,
{ "BGP Identifier", "bgp.open.identifier", FT_IPv4, BASE_NONE,
NULL, 0x0, "The BGP Identifier of the sender", HFILL }},
{ &hf_bgp_open_opt_len,
{ "Optional Parameters Length", "bgp.open.opt.len", FT_UINT8, BASE_DEC,
NULL, 0x0, "The total length of the Optional Parameters field in octets", HFILL }},
{ &hf_bgp_open_opt_params,
{ "Optional Parameters", "bgp.open.opt", FT_NONE, BASE_NONE,
NULL, 0x0, "List of optional parameters", HFILL }},
{ &hf_bgp_open_opt_param,
{ "Optional Parameter", "bgp.open.opt.param", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_open_opt_param_type,
{ "Parameter Type", "bgp.open.opt.param.type", FT_UINT8, BASE_DEC,
VALS(bgp_open_opt_vals), 0x0, "Unambiguously identifies individual parameters", HFILL }},
{ &hf_bgp_open_opt_param_len,
{ "Parameter Length", "bgp.open.opt.param.len", FT_UINT8, BASE_DEC,
NULL, 0x0, "Length of the Parameter Value", HFILL }},
{ &hf_bgp_open_opt_param_auth,
{ "Authentication Data", "bgp.open.opt.param.auth", FT_BYTES, BASE_NONE,
NULL, 0x0, "Deprecated", HFILL }},
{ &hf_bgp_open_opt_param_unknown,
{ "Unknown", "bgp.open.opt.param.unknown", FT_BYTES, BASE_NONE,
NULL, 0x0, "Unknown Parameter", HFILL }},
{ &hf_bgp_notify_major_error,
{ "Major error Code", "bgp.notify.major_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_major), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_msg_hdr,
{ "Minor error Code (Message Header)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_msg_hdr), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_open_msg,
{ "Minor error Code (Open Message)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_open_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_update_msg,
{ "Minor error Code (Update Message)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_update_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_ht_expired,
{ "Minor error Code (Hold Timer Expired)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_state_machine,
{ "Minor error Code (State Machine)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_state_machine), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_cease,
{ "Minor error Code (Cease)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_cease), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_cap_msg,
{ "Minor error Code (Capability Message)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
VALS(bgpnotify_minor_cap_msg), 0x0, NULL, HFILL }},
{ &hf_bgp_notify_minor_unknown,
{ "Minor error Code (Unknown)", "bgp.notify.minor_error", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_notify_data,
{ "Data", "bgp.notify.minor_error", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_afi,
{ "Address family identifier (AFI)", "bgp.route_refresh.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_subtype,
{ "Subtype", "bgp.route_refresh.subtype", FT_UINT8, BASE_DEC,
VALS(route_refresh_subtype_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_safi,
{ "Subsequent address family identifier (SAFI)", "bgp.route_refresh.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf,
{ "ORF information", "bgp.route_refresh.orf", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_flag,
{ "ORF flag", "bgp.route_refresh.orf.flag", FT_UINT8, BASE_DEC,
VALS(orf_when_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_type,
{ "ORF type", "bgp.route_refresh.orf.type", FT_UINT8, BASE_DEC,
VALS(orf_type_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_length,
{ "ORF length", "bgp.route_refresh.orf.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixlist,
{ "ORFEntry PrefixList", "bgp.route_refresh.orf.entry", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_action,
{ "ORFEntry Action", "bgp.route_refresh.orf.entry.action", FT_UINT8, BASE_DEC,
VALS(orf_entry_action_vals), BGP_ORF_ACTION, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_match,
{ "ORFEntry Match", "bgp.route_refresh.orf.entry.match", FT_UINT8, BASE_DEC,
VALS(orf_entry_match_vals), BGP_ORF_MATCH, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_sequence,
{ "ORFEntry Sequence", "bgp.route_refresh.orf.entry.sequence", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixmask_lower,
{ "ORFEntry PrefixMask length lower bound", "bgp.route_refresh.orf.entry.prefixmask_lower", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_route_refresh_orf_entry_prefixmask_upper,
{ "ORFEntry PrefixMask length upper bound", "bgp.route_refresh.orf.entry.prefixmask_upper", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap,
{ "Capability", "bgp.cap", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_type,
{ "Type", "bgp.cap.type", FT_UINT8, BASE_DEC,
VALS(capability_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_length,
{ "Length", "bgp.cap.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_action,
{ "Action", "bgp.cap.action", FT_UINT8, BASE_DEC,
VALS(bgpcap_action), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_unknown,
{ "Unknown", "bgp.cap.unknown", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_reserved,
{ "Reserved", "bgp.cap.reserved", FT_BYTES, BASE_NONE,
NULL, 0x0, "Must be Zero", HFILL }},
{ &hf_bgp_cap_mp_afi,
{ "AFI", "bgp.cap.mp.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_mp_safi,
{ "SAFI", "bgp.cap.mp.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers,
{ "Restart Timers", "bgp.cap.gr.timers", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers_restart_flag,
{ "Restart", "bgp.cap.gr.timers.restart_flag", FT_BOOLEAN, 16,
TFS(&tfs_yes_no), 0x8000, NULL, HFILL }},
{ &hf_bgp_cap_gr_timers_restart_time,
{ "Time", "bgp.cap.gr.timers.restart_time", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, "in us", HFILL }},
{ &hf_bgp_cap_gr_afi,
{ "AFI", "bgp.cap.gr.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_safi,
{ "SAFI", "bgp.cap.gr.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_flag,
{ "Flag", "bgp.cap.gr.flag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_gr_flag_pfs,
{ "Preserve forwarding state", "bgp.cap.gr.flag.pfs", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x80, NULL, HFILL }},
{ &hf_bgp_cap_4as,
{ "AS Number", "bgp.cap.4as", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_dc,
{ "Capability Dynamic", "bgp.cap.dc", FT_UINT8, BASE_DEC,
VALS(capability_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_afi,
{ "AFI", "bgp.cap.ap.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_safi,
{ "SAFI", "bgp.cap.ap.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_ap_sendreceive,
{ "Send/Receive", "bgp.cap.ap.sendreceive", FT_UINT8, BASE_DEC,
VALS(orf_send_recv_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_afi,
{ "AFI", "bgp.cap.orf.afi", FT_UINT16, BASE_DEC,
VALS(afn_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_safi,
{ "SAFI", "bgp.cap.orf.safi", FT_UINT8, BASE_DEC,
VALS(bgpattr_nlri_safi), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_number,
{ "Number", "bgp.cap.orf.number", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_type,
{ "Type", "bgp.cap.orf.type", FT_UINT8, BASE_DEC,
VALS(orf_type_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_cap_orf_sendreceive,
{ "Send Receive", "bgp.cap.orf.sendreceive", FT_UINT8, BASE_DEC,
VALS(orf_send_recv_vals), 0x0, NULL, HFILL }},
{ &hf_bgp_aggregator_as,
{ "Aggregator AS", "bgp.aggregator_as", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_aggregator_origin,
{ "Aggregator origin", "bgp.aggregator_origin", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_as_path,
{ "AS Path", "bgp.as_path", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_community_as,
{ "Community AS", "bgp.community_as", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_community_value,
{ "Community value", "bgp.community_value", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_local_pref,
{ "Local preference", "bgp.local_pref", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_reach_nlri_ipv4_prefix,
{ "MP Reach NLRI IPv4 prefix", "bgp.mp_reach_nlri_ipv4_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_unreach_nlri_ipv4_prefix,
{ "MP Unreach NLRI IPv4 prefix", "bgp.mp_unreach_nlri_ipv4_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mp_nlri_tnl_id,
{ "MP Reach NLRI Tunnel Identifier", "bgp.mp_nlri_tnl_id", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_multi_exit_disc,
{ "Multiple exit discriminator", "bgp.multi_exit_disc", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_next_hop,
{ "Next hop", "bgp.next_hop", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_nlri_prefix,
{ "NLRI prefix", "bgp.nlri_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_nlri_path_id,
{ "NLRI path id", "bgp.nlri_path_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_origin,
{ "Origin", "bgp.origin", FT_UINT8, BASE_DEC,
VALS(bgpattr_origin), 0x0, NULL, HFILL}},
{ &hf_bgp_originator_id,
{ "Originator identifier", "bgp.originator_id", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_t,
{ "Transitive bit", "bgp.ssa_t", FT_BOOLEAN, 8,
NULL, 0x80, "SSA Transitive bit", HFILL}},
{ &hf_bgp_ssa_type,
{ "SSA Type", "bgp.ssa_type", FT_UINT16, BASE_DEC,
VALS(bgp_ssa_type), 0x7FFF, NULL, HFILL}},
{ &hf_bgp_ssa_len,
{ "Length", "bgp.ssa_len", FT_UINT16, BASE_DEC,
NULL, 0x0, "SSA Length", HFILL}},
{ &hf_bgp_ssa_value,
{ "Value", "bgp.ssa_value", FT_BYTES, BASE_NONE,
NULL, 0x0, "SSA Value", HFILL}},
{ &hf_bgp_ssa_l2tpv3_pref,
{ "Preference", "bgp.ssa_l2tpv3_pref", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_s,
{ "Sequencing bit", "bgp.ssa_l2tpv3_s", FT_BOOLEAN, 8,
NULL, 0x80, "Sequencing S-bit", HFILL}},
{ &hf_bgp_ssa_l2tpv3_unused,
{ "Unused", "bgp.ssa_l2tpv3_Unused", FT_BOOLEAN, 8,
NULL, 0x7F, "Unused Flags", HFILL}},
{ &hf_bgp_ssa_l2tpv3_cookie_len,
{ "Cookie Length", "bgp.ssa_l2tpv3_cookie_len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_session_id,
{ "Session ID", "bgp.ssa_l2tpv3_session_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_ssa_l2tpv3_cookie,
{ "Cookie", "bgp.ssa_l2tpv3_cookie", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_withdrawn_prefix,
{ "Withdrawn prefix", "bgp.withdrawn_prefix", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_cluster_list,
{ "Cluster List", "bgp.cluster_list", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_t,
{ "MCAST-VPN nlri", "bgp.mcast_vpn_nlri", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_route_type,
{ "Route Type", "bgp.mcast_vpn_nlri_route_type", FT_UINT8,
BASE_DEC, VALS(mcast_vpn_route_type), 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_length,
{ "Length", "bgp.mcast_vpn_nlri_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_rd,
{ "Route Distinguisher", "bgp.mcast_vpn_nlri_rd", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_origin_router_ipv4,
{ "Originating Router", "bgp.mcast_vpn_nlri_origin_router_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_origin_router_ipv6,
{ "Originating Router", "bgp.mcast_vpn_nlri_origin_router_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_as,
{ "Source AS", "bgp.mcast_vpn_nlri_source_as", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_length,
{ "Multicast Source Length", "bgp.mcast_vpn_nlri_source_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_length,
{ "Multicast Group Length", "bgp.mcast_vpn_nlri_group_length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_addr_ipv4,
{ "Multicast Source Address", "bgp.mcast_vpn_nlri_source_addr_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_source_addr_ipv6,
{ "Multicast Source Address", "bgp.mcast_vpn_nlri_source_addr_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_addr_ipv4,
{ "Multicast Group Address", "bgp.mcast_vpn_nlri_group_addr_ipv4", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_group_addr_ipv6,
{ "Group Address", "bgp.mcast_vpn_nlri_group_addr_ipv6", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mcast_vpn_nlri_route_key,
{ "Route Key", "bgp.mcast_vpn_nlri_route_key", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_encaps_tunnel_tlv_len,
{ "Length", "bgp.encaps_tunnel_tlv_len", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_encaps_tunnel_tlv_type,
{ "Type code", "bgp.encaps_tunnel_tlv_type", FT_UINT16, BASE_DEC,
VALS(tunnel_type), 0x0, NULL, HFILL}},
{ &hf_bgp_encaps_tunnel_subtlv_len,
{ "Length", "bgp.encaps_tunnel_tlv_sublen", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_encaps_tunnel_subtlv_type,
{ "Type code", "bgp.encaps_tunnel_subtlv_type", FT_UINT8, BASE_DEC,
VALS(subtlv_type), 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_safi_rd,
{ "Route Distinguisher", "bgp.mdt_safi_rd", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_safi_ipv4_addr,
{ "IPv4 Address", "bgp.mdt_safi_ipv4_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_mdt_safi_group_addr,
{ "Group Address", "bgp.mdt_safi_group_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_bgp_flags_optional,
{ "Optional", "bgp.flags.optional", FT_BOOLEAN, 8,
TFS(&tfs_optional_wellknown), BGP_ATTR_FLAG_OPTIONAL, NULL, HFILL}},
{ &hf_bgp_flags_transitive,
{ "Transitive", "bgp.flags.transitive", FT_BOOLEAN, 8,
TFS(&tfs_transitive_non_transitive), BGP_ATTR_FLAG_TRANSITIVE, NULL, HFILL}},
{ &hf_bgp_flags_partial,
{ "Partial", "bgp.flags.partial", FT_BOOLEAN, 8,
TFS(&tfs_partial_complete), BGP_ATTR_FLAG_PARTIAL, NULL, HFILL}},
{ &hf_bgp_flags_extended_length,
{ "Length", "bgp.flags.extended_length", FT_BOOLEAN, 8,
TFS(&tfs_extended_regular_length), BGP_ATTR_FLAG_EXTENDED_LENGTH, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags,
{ "Flags", "bgp.ext_com_qos.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_remarking,
{ "Remarking", "bgp.ext_com_qos.flags.remarking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x10, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_ignore_remarking,
{ "Ignore remarking", "bgp.ext_com_qos.flags.ignore_remarking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x08, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_flags_agg_marking,
{ "Aggegation of markins", "bgp.ext_com_qos.flags.agg_marking", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x04, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags,
{ "Flags byte 1", "bgp.ext_com_cos.flags", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_be,
{ "BE class", "bgp.ext_com_cos.flags.be", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x80, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_ef,
{ "EF class", "bgp.ext_com_cos.flags.ef", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x40, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_af,
{ "AF class", "bgp.ext_com_cos.flags.af", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x20, NULL, HFILL}},
{ &hf_bgp_ext_com_cos_flags_le,
{ "LE class", "bgp.ext_com_cos.flags.le", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x10, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_set_number,
{ "QoS Set Number", "bgp.ext_com_qos.set_number", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_tech_type,
{ "Technology Type", "bgp.ext_com_qos.tech_type", FT_UINT8, BASE_HEX,
VALS(qos_tech_type), 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_marking_o,
{ "QoS Marking O", "bgp.ext_com_qos.marking_o", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_marking_a,
{ "QoS Marking A", "bgp.ext_com_qos.marking_a", FT_UINT8, BASE_HEX_DEC,
NULL, 0, NULL, HFILL}},
{ &hf_bgp_ext_com_qos_default_to_zero,
{ "Defaults to zero", "bgp.ext_com_qos.default_to_zero", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_bgp,
&ett_bgp_prefix,
&ett_bgp_unfeas,
&ett_bgp_attrs,
&ett_bgp_attr,
&ett_bgp_attr_flags,
&ett_bgp_mp_nhna,
&ett_bgp_mp_reach_nlri,
&ett_bgp_mp_unreach_nlri,
&ett_bgp_mp_snpa,
&ett_bgp_nlri,
&ett_bgp_open,
&ett_bgp_update,
&ett_bgp_notification,
&ett_bgp_route_refresh,
&ett_bgp_capability,
&ett_bgp_as_paths,
&ett_bgp_as_path_segments,
&ett_bgp_communities,
&ett_bgp_cluster_list,
&ett_bgp_options,
&ett_bgp_option,
&ett_bgp_cap,
&ett_bgp_extended_communities,
&ett_bgp_ext_com_flags,
&ett_bgp_ssa,
&ett_bgp_ssa_subtree,
&ett_bgp_orf,
&ett_bgp_orf_entry,
&ett_bgp_mcast_vpn_nlri,
&ett_bgp_tunnel_tlv,
&ett_bgp_tunnel_tlv_subtree,
&ett_bgp_tunnel_subtlv,
&ett_bgp_tunnel_subtlv_subtree,
};
module_t *bgp_module;
static const enum_val_t asn_len[] = {
{"auto-detect", "Auto-detect", 0},
{"2", "2 octet", 2},
{"4", "4 octet", 4},
{NULL, NULL, -1}
};
proto_bgp = proto_register_protocol("Border Gateway Protocol",
"BGP", "bgp");
proto_register_field_array(proto_bgp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bgp_module = prefs_register_protocol(proto_bgp, NULL);
prefs_register_bool_preference(bgp_module, "desegment",
"Reassemble BGP messages spanning multiple TCP segments",
"Whether the BGP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&bgp_desegment);
prefs_register_enum_preference(bgp_module, "asn_len",
"Length of the AS number",
"BGP dissector detect the length of the AS number in AS_PATH attributes automatically or manually (NOTE: Automatic detection is not 100% accurate)",
&bgp_asn_len, asn_len, FALSE);
}
void
proto_reg_handoff_bgp(void)
{
dissector_handle_t bgp_handle;
bgp_handle = create_dissector_handle(dissect_bgp, proto_bgp);
dissector_add_uint("tcp.port", BGP_TCP_PORT, bgp_handle);
}
