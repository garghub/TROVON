static void
fp_get_hmac_addr (guint64 hmac, guint16 *swid, guint16 *sswid, guint16 *lid) {
if (!swid || !sswid || !lid) {
return;
}
*swid = (guint16) ((hmac & FP_HMAC_SWID_MASK) >> 32);
*sswid = (guint16) ((hmac & FP_HMAC_SSWID_MASK) >> 16);
*lid = (guint16) (hmac & FP_HMAC_LID_MASK);
}
static void
dissect_lsp_mt_id(tvbuff_t *tvb, proto_tree *tree, int offset)
{
int mt_block, mt_id;
const char *mt_desc="";
mt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text ( tree, tvb, offset, 1 ,
"4 most significant bits reserved, should be set to 0 (%d)", ISIS_LSP_MT_MSHIP_RES(mt_block));
mt_id = ISIS_LSP_MT_MSHIP_ID(mt_block);
switch(mt_id) {
case 0:
mt_desc="'standard' topology";
break;
case 1:
mt_desc="IPv4 In-Band Management purposes";
break;
case 2:
mt_desc="IPv6 routing topology";
break;
case 3:
mt_desc="IPv4 multicast routing topology";
break;
case 4:
mt_desc="IPv6 multicast routing topology";
break;
default:
mt_desc=((mt_block & 0x0fff) < 3996) ? "Reserved for IETF Consensus" : "Development, Experimental and Proprietary features";
}
proto_tree_add_text ( tree, tvb, offset, 2 ,
"%s (%d)", mt_desc, mt_id);
}
static void
dissect_metric(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 value,
const char *pstr, int force_supported )
{
int s;
if ( !tree ) return;
s = ISIS_LSP_CLV_METRIC_SUPPORTED(value);
proto_tree_add_text(tree, tvb, offset, 1,
"%s Metric: %s%s %s%d:%d", pstr,
s ? "Not supported" : "Supported",
(s && force_supported) ? "(but is required to be)":"",
ISIS_LSP_CLV_METRIC_RESERVED(value) ? "(reserved bit != 0)":"",
ISIS_LSP_CLV_METRIC_VALUE(value), value );
}
static void
dissect_lsp_ip_reachability_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_item *ti;
proto_tree *ntree = NULL;
guint32 src, mask, bitmask;
int prefix_len;
gboolean found_mask = FALSE;
while ( length > 0 ) {
if (length<12) {
isis_dissect_unknown(tvb, tree, offset,
"short IP reachability (%d vs 12)", length );
return;
}
if ( tree ) {
src = tvb_get_ipv4(tvb, offset+4);
mask = tvb_get_ntohl(tvb, offset+8);
bitmask = 0xffffffff;
for(prefix_len = 32; prefix_len >= 0; prefix_len--) {
if (bitmask==mask) {
found_mask = TRUE;
break;
}
bitmask = bitmask << 1;
}
if(found_mask) {
ti = proto_tree_add_text ( tree, tvb, offset, 12,
"IPv4 prefix: %s/%d",
ip_to_str((guint8*)&src),
prefix_len );
} else {
ti = proto_tree_add_text ( tree, tvb, offset, 12,
"IPv4 prefix: %s mask %s",
ip_to_str((guint8*)&src),
tvb_ip_to_str(tvb, offset+8));
};
ntree = proto_item_add_subtree(ti,
ett_isis_lsp_clv_ip_reachability);
proto_tree_add_text (ntree, tvb, offset, 1,
"Default Metric: %d, %s, Distribution: %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset)) ? "External" : "Internal",
ISIS_LSP_CLV_METRIC_UPDOWN(tvb_get_guint8(tvb, offset)) ? "down" : "up");
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+1))) {
proto_tree_add_text (ntree, tvb, offset+1, 1, "Delay Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+1, 1, "Delay Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+1)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+1)) ? "External" : "Internal");
}
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+2))) {
proto_tree_add_text (ntree, tvb, offset+2, 1, "Expense Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+2, 1, "Expense Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+2)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+2)) ? "External" : "Internal");
}
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+3))) {
proto_tree_add_text (ntree, tvb, offset+3, 1, "Error Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+3, 1, "Error Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+3)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+3)) ? "External" : "Internal");
}
}
offset += 12;
length -= 12;
}
}
static void
dissect_ipreach_subclv(tvbuff_t *tvb, proto_tree *tree, int offset, int clv_code, int clv_len)
{
switch (clv_code) {
case 1:
while (clv_len >= 4) {
proto_tree_add_text(tree, tvb, offset, 4,
"32-Bit Administrative tag: 0x%08x (=%u)",
tvb_get_ntohl(tvb, offset),
tvb_get_ntohl(tvb, offset));
offset+=4;
clv_len-=4;
}
break;
case 2:
while (clv_len >= 8) {
proto_tree_add_text(tree, tvb, offset, 8,
"64-Bit Administrative tag: 0x%08x%08x",
tvb_get_ntohl(tvb, offset),
tvb_get_ntohl(tvb, offset+4));
offset+=8;
clv_len-=8;
}
break;
default :
proto_tree_add_text (tree, tvb, offset, clv_len+2,
"Unknown sub-TLV: code %u, length %u",
clv_code, clv_len );
break;
}
}
static void
dissect_lsp_ext_ip_reachability_clv(tvbuff_t *tvb, proto_tree *tree,
int offset, int id_length _U_, int length)
{
proto_item *pi = NULL;
proto_tree *subtree = NULL;
proto_tree *subtree2 = NULL;
guint8 ctrl_info;
guint bit_length;
int byte_length;
guint8 prefix [4];
guint32 metric;
guint len,i;
guint subclvs_len;
guint clv_code, clv_len;
if (!tree) return;
while (length > 0) {
ctrl_info = tvb_get_guint8(tvb, offset+4);
bit_length = ctrl_info & 0x3f;
byte_length = ipv4_addr_and_mask(tvb, offset+5, prefix, bit_length);
if (byte_length == -1) {
isis_dissect_unknown(tvb, tree, offset,
"IPv4 prefix has an invalid length: %d bits", bit_length );
return;
}
metric = tvb_get_ntohl(tvb, offset);
subclvs_len = 0;
if ((ctrl_info & 0x40) != 0)
subclvs_len = 1+tvb_get_guint8(tvb, offset+5+byte_length);
pi = proto_tree_add_text (tree, tvb, offset, 5+byte_length+subclvs_len,
"IPv4 prefix: %s/%d, Metric: %u, Distribution: %s, %ssub-TLVs present",
ip_to_str (prefix),
bit_length,
metric,
((ctrl_info & 0x80) == 0) ? "up" : "down",
((ctrl_info & 0x40) == 0) ? "no " : "" );
subtree = proto_item_add_subtree (pi, ett_isis_lsp_part_of_clv_ext_ip_reachability);
proto_tree_add_text (subtree, tvb, offset+5, byte_length, "IPv4 prefix: %s/%u",
ip_to_str (prefix), bit_length);
proto_tree_add_text (subtree, tvb, offset, 4, "Metric: %u", metric);
proto_tree_add_text (subtree, tvb, offset+4, 1, "Distribution: %s",
((ctrl_info & 0x80) == 0) ? "up" : "down");
len = 5 + byte_length;
if ((ctrl_info & 0x40) != 0) {
subclvs_len = tvb_get_guint8(tvb, offset+len);
pi = proto_tree_add_text (subtree, tvb, offset+len, 1, "sub-TLVs present, total length: %u bytes",
subclvs_len);
proto_item_set_len (pi, subclvs_len+1);
subtree2 = proto_item_add_subtree (pi, ett_isis_lsp_clv_ip_reach_subclv);
i =0;
while (i < subclvs_len) {
clv_code = tvb_get_guint8(tvb, offset+len+1);
clv_len = tvb_get_guint8(tvb, offset+len+2);
dissect_ipreach_subclv(tvb, subtree2, offset+len+3, clv_code, clv_len);
i += clv_len + 2;
}
len += 1 + subclvs_len;
} else {
proto_tree_add_text (subtree, tvb, offset+4, 1, "no sub-TLVs present");
proto_item_set_len (pi, len);
}
offset += len;
length -= len;
}
}
static void
dissect_isis_grp_address_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int tree_id,int length)
{
gint len;
gint record_num;
gint source_num;
gint k=1;
guint16 mt_block;
guint64 hmac_src;
guint16 swid = 0;
guint16 sswid = 0;
guint16 lid = 0;
proto_item *ti=NULL;
proto_tree *rt_tree=NULL;
const char *mt_desc;
while (length>0) {
mt_block=tvb_get_ntohs(tvb, offset);
switch((mt_block&0xff00)>>8) {
case GRP_MAC_ADDRESS:
mt_desc="GROUP MAC ADDRESS";
ti = proto_tree_add_text (tree, tvb, offset,(mt_block&0x00ff)+2 , "%s SUB TLV", mt_desc);
rt_tree = proto_item_add_subtree(ti,ett_isis_lsp_clv_grp_address_IPv4_prefx);
length=length-1;
offset=offset+1;
len=tvb_get_guint8(tvb, offset);
proto_tree_add_text (rt_tree, tvb, offset,1," Length :%d ",len);
if(len < 5) {
length=length-len;
offset=offset+len;
break;
}
length=length-1;
offset=offset+1;
mt_block=tvb_get_ntohs(tvb, offset);
proto_tree_add_text (rt_tree, tvb, offset,2," Topology ID:%d ",(mt_block&0x0fff) );
length=length-2;
offset=offset+2;
len=len-2;
mt_block=tvb_get_ntohs(tvb, offset);
proto_tree_add_text (rt_tree,tvb, offset,2," VLAN ID:%d ",(mt_block&0x0fff) );
length=length-2;
offset=offset+2;
len=len-2;
record_num=tvb_get_guint8(tvb, offset);
proto_tree_add_text (rt_tree,tvb, offset,1, " Number of records :%d ",record_num);
length=length-1;
offset=offset+1;
len=len-1;
while(len > 0) {
source_num=tvb_get_guint8(tvb, offset);
proto_tree_add_text (rt_tree,tvb, offset,1," Number of sources :%d ",source_num);
length=length-1;
offset=offset+1;
len=len-1;
hmac_src=tvb_get_ntoh48(tvb, offset);
fp_get_hmac_addr (hmac_src, &swid, &sswid, &lid);
proto_tree_add_text (rt_tree,tvb, offset,6," Group Address:%04x.%04x.%04x ",swid, sswid, lid );
length=length-6;
offset=offset+6;
len=len-6;
while((len > 0) && (source_num > 0)) {
hmac_src = tvb_get_ntoh48 (tvb, offset);
fp_get_hmac_addr (hmac_src, &swid, &sswid, &lid);
proto_tree_add_text (rt_tree,tvb, offset,6," Source Address (%d):%04x.%04x.%04x",k,swid, sswid, lid);
k=k+1;
length=length-6;
offset=offset+6;
len=len-6;
source_num--;
}
}
break;
default:
mt_desc="INVALID";
proto_tree_add_uint_format ( tree, tree_id, tvb, offset,(mt_block&0x00ff)+2,
mt_block,
"%s SUB TLV",mt_desc );
offset=offset+1;
length=length-2-(tvb_get_guint8(tvb, offset));
offset=offset+1+(tvb_get_guint8(tvb, offset));
break;
}
}
}
static void
dissect_isis_rt_capable_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
gint len;
guint16 rt_block;
guint32 rt_block1;
proto_item *ti;
proto_tree *rt_tree;
const char *mt_desc;
gint root_id = 1;
gint sec_vlan_id = 1;
length = length - 5;
offset = offset + 5;
while (length>1) {
rt_block = tvb_get_ntohs(tvb, offset);
switch ((rt_block&0xff00)>>8) {
case TRILL_VERSION:
mt_desc = "TRILL version";
ti = proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset+1, 1, "Maximum version: %d", (rt_block&0x00ff));
length = length-2;
offset = offset+2;
break;
case TREES:
mt_desc = "Trees";
ti = proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
length = length-1;
offset = offset+1;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Nof. trees to compute: %d", rt_block);
length = length-2;
offset = offset+2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Maximum nof. trees to compute: %d", rt_block);
length = length-2;
offset = offset+2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Nof. trees to use: %d", rt_block);
length = length-2;
offset = offset+2;
break;
case TREE_IDENTIFIER:
mt_desc = "Tree root identifier";
ti=proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
rt_block = tvb_get_ntohs(tvb, offset+1);
proto_tree_add_text(rt_tree, tvb, offset+1, 2, "Starting tree no: %d", rt_block);
len = len-2;
length = length-2;
offset = offset+3;
while (len>1) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Nickname(%dth root): %d", root_id, rt_block);
root_id = root_id+1;
len = len-2;
length = length-2;
offset = offset+2;
}
break;
case NICKNAME:
mt_desc = "The nickname";
ti=proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
length = length-1;
offset = offset+1;
while (len>0) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Nickname priority: %d", ((rt_block&0xff00)>>8));
length = length-1;
offset = offset+1;
len = len-1;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Tree root priority: %d", rt_block);
length = length-2;
offset = offset+2;
len = len-2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Nickname: %x", rt_block);
length = length-2;
offset = offset+2;
len = len-2;
}
break;
case INTERESTED_VLANS:
mt_desc = "Interested VLAN and spanning tree root";
ti = proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
length = length-1;
offset = offset+1;
len = len-1;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Nickname: %x", rt_block);
length = length-2;
offset = offset+2;
len = len-2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2,
"%s%s", (rt_block&0x8000) ? "IPv4 multicast router set, " : "IPv4 multicast router not set, ",
(rt_block&0x4000) ? "IPv6 multicast router set" : "IPv6 multicast router not set");
proto_tree_add_text(rt_tree, tvb, offset, 2, "Vlan start id: %x", (rt_block&0x0fff));
length = length-2;
offset = offset+2;
len = len-2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Vlan end id: %x", (rt_block&0x0fff));
length = length-2;
offset = offset+2;
len = len-2;
rt_block1 = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 4, "Appointed forward state lost counter: %d", rt_block1);
length = length-4;
offset = offset+4;
len = len-4;
while (len>0) {
proto_tree_add_item(rt_tree, hf_isis_lsp_root_id, tvb, offset, 6, ENC_BIG_ENDIAN);
length = length-6;
offset = offset+6;
len = len-6;
length = length-2;
}
break;
case TREES_USED_IDENTIFIER:
mt_desc = "Trees used identifier";
ti=proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
rt_block = tvb_get_ntohs(tvb, offset+1);
proto_tree_add_text(rt_tree, tvb, offset+1, 2, "Starting tree no: %d", rt_block);
len = len-2;
length = length-2;
offset = offset+3;
root_id = 1;
while (len>0) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset,2,"Nickname(%dth root): %d", root_id, rt_block);
root_id = root_id+1;
len = len-2;
offset = offset+2;
length = length-2;
}
break;
case VLAN_GROUP:
mt_desc = "The VLAN group";
ti = proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
rt_tree = proto_item_add_subtree(ti, ett_isis_lsp_clv_rt_capable_IPv4_prefx);
length = length-1;
offset = offset+1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 1, "Length: %d", len);
len = len-1;
length = length-1;
offset = offset+1;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Primary vlan id: %d", (rt_block&0x0fff));
length = length-2;
offset = offset+2;
len = len-2;
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "Secondary vlan id: %d", (rt_block&0x0fff));
length = length-2;
offset = offset+2;
len = len-2;
sec_vlan_id = 1;
while (len>0) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(rt_tree, tvb, offset, 2, "%dth secondary vlan id: %x", sec_vlan_id, rt_block);
length = length-2;
offset = offset+2;
sec_vlan_id = sec_vlan_id+1;
len = len-2;
}
break;
default:
mt_desc = "INVALID";
proto_tree_add_text(tree, tvb, offset, (rt_block&0x00ff)+2, "%s sub tlv", mt_desc);
offset = offset+1;
length = length-2-(tvb_get_guint8(tvb, offset));
offset = offset+1+(tvb_get_guint8(tvb, offset));
break;
}
}
}
static void
dissect_lsp_ipv6_reachability_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_item *pi;
proto_tree *subtree = NULL;
proto_tree *subtree2 = NULL;
guint8 ctrl_info;
guint bit_length;
int byte_length;
struct e_in6_addr prefix;
guint32 metric;
guint len,i;
guint subclvs_len;
guint clv_code, clv_len;
if (!tree) return;
while (length > 0) {
ctrl_info = tvb_get_guint8(tvb, offset+4);
bit_length = tvb_get_guint8(tvb, offset+5);
byte_length = ipv6_addr_and_mask(tvb, offset+6, &prefix, bit_length);
if (byte_length == -1) {
isis_dissect_unknown(tvb, tree, offset,
"IPv6 prefix has an invalid length: %d bits", bit_length );
return;
}
metric = tvb_get_ntohl(tvb, offset);
subclvs_len = 0;
if ((ctrl_info & 0x20) != 0)
subclvs_len = 1+tvb_get_guint8(tvb, offset+6+byte_length);
pi = proto_tree_add_text (tree, tvb, offset, 6+byte_length+subclvs_len,
"IPv6 prefix: %s/%u, Metric: %u, Distribution: %s, %s, %ssub-TLVs present",
ip6_to_str (&prefix),
bit_length,
metric,
((ctrl_info & 0x80) == 0) ? "up" : "down",
((ctrl_info & 0x40) == 0) ? "internal" : "external",
((ctrl_info & 0x20) == 0) ? "no " : "" );
subtree = proto_item_add_subtree (pi, ett_isis_lsp_part_of_clv_ipv6_reachability);
proto_tree_add_text (subtree, tvb, offset+6, byte_length, "IPv6 prefix: %s/%u",
ip6_to_str (&prefix),
bit_length);
proto_tree_add_text (subtree, tvb, offset, 4,
"Metric: %u", metric);
proto_tree_add_text (subtree, tvb, offset+4, 1,
"Distribution: %s, %s",
((ctrl_info & 0x80) == 0) ? "up" : "down",
((ctrl_info & 0x40) == 0) ? "internal" : "external" );
if ((ctrl_info & 0x1f) != 0) {
proto_tree_add_text (subtree, tvb, offset+4, 1,
"Reserved bits: 0x%x",
(ctrl_info & 0x1f) );
}
len = 6 + byte_length;
if ((ctrl_info & 0x20) != 0) {
subclvs_len = tvb_get_guint8(tvb, offset+len);
pi = proto_tree_add_text (subtree, tvb, offset+len, 1, "sub-TLVs present, total length: %u bytes",
subclvs_len);
proto_item_set_len (pi, subclvs_len+1);
subtree2 = proto_item_add_subtree (pi, ett_isis_lsp_clv_ip_reach_subclv);
i =0;
while (i < subclvs_len) {
clv_code = tvb_get_guint8(tvb, offset+len+1);
clv_len = tvb_get_guint8(tvb, offset+len+2);
dissect_ipreach_subclv(tvb, subtree2, offset+len+3, clv_code, clv_len);
i += clv_len + 2;
}
len += 1 + subclvs_len;
} else {
proto_tree_add_text (subtree, tvb, offset+4, 1, "no sub-TLVs present");
proto_item_set_len (pi, len);
}
offset += len;
length -= len;
}
}
static void
dissect_lsp_nlpid_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_nlpid_clv(tvb, tree, offset, length);
}
static void
dissect_lsp_mt_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_mt_clv(tvb, tree, offset, length, hf_isis_lsp_clv_mt );
}
static void
dissect_lsp_hostname_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_hostname_clv(tvb, tree, offset, length,
hf_isis_lsp_hostname);
}
static void
dissect_lsp_te_router_id_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_te_router_id_clv(tvb, tree, offset, length,
hf_isis_lsp_clv_te_router_id );
}
static void
dissect_lsp_ip_int_addr_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ip_int_clv(tvb, tree, offset, length,
hf_isis_lsp_clv_ipv4_int_addr );
}
static void
dissect_lsp_ipv6_int_addr_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ipv6_int_clv(tvb, tree, offset, length,
hf_isis_lsp_clv_ipv6_int_addr );
}
static void
dissect_isis_lsp_clv_mt_cap_spb_instance(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int CIST_ROOT_ID_LEN = 8;
const int CIST_EXT_ROOT_PATH_COST_LEN = 4;
const int BRIDGE_PRI_LEN = 2;
const int V_SPSOURCEID_LEN = 4;
const int NUM_TREES_LEN = 1;
const int CIST_ROOT_ID_OFFSET = 0;
const int CIST_EXT_ROOT_PATH_COST_OFFSET = CIST_ROOT_ID_OFFSET + CIST_ROOT_ID_LEN;
const int BRIDGE_PRI_OFFSET = CIST_EXT_ROOT_PATH_COST_OFFSET + CIST_EXT_ROOT_PATH_COST_LEN;
const int V_SPSOURCEID_OFFSET = BRIDGE_PRI_OFFSET + BRIDGE_PRI_LEN;
const int NUM_TREES_OFFSET = V_SPSOURCEID_OFFSET + V_SPSOURCEID_LEN;
const int FIXED_LEN = NUM_TREES_OFFSET + NUM_TREES_LEN;
const int VLAN_ID_TUPLE_LEN = 8;
if (sublen < FIXED_LEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPB Digest subTLV (%d vs %d)", sublen, FIXED_LEN);
return;
}
else {
proto_tree *subtree, *ti;
int subofs = offset;
const guint8 *cist_root_identifier = tvb_get_ptr (tvb, subofs + CIST_ROOT_ID_OFFSET, CIST_ROOT_ID_LEN);
const guint32 cist_root_path_cost = tvb_get_ntohl (tvb, subofs + CIST_EXT_ROOT_PATH_COST_OFFSET);
const guint16 bridge_priority = tvb_get_ntohs (tvb, subofs + BRIDGE_PRI_OFFSET);
const guint32 v_spsourceid = tvb_get_ntohl (tvb, subofs + V_SPSOURCEID_OFFSET);
guint8 num_trees = tvb_get_guint8(tvb, subofs + NUM_TREES_OFFSET);
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB Instance: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_lsp_clv_mt_cap_spb_instance);
proto_tree_add_text( subtree, tvb, subofs + CIST_ROOT_ID_OFFSET, CIST_ROOT_ID_LEN,
"CIST Root Identifier: %08x-%08x-%08x-%08x-%08x-%08x-%08x-%08x",
cist_root_identifier[0],
cist_root_identifier[1],
cist_root_identifier[2],
cist_root_identifier[3],
cist_root_identifier[4],
cist_root_identifier[5],
cist_root_identifier[6],
cist_root_identifier[7]);
proto_tree_add_text( subtree, tvb, subofs + CIST_EXT_ROOT_PATH_COST_OFFSET, CIST_EXT_ROOT_PATH_COST_LEN,
"CIST External Root Path Cost: 0x%08x (%u)",
cist_root_path_cost,
cist_root_path_cost);
proto_tree_add_text( subtree, tvb, subofs + BRIDGE_PRI_OFFSET, BRIDGE_PRI_LEN,
"Bridge Priority: 0x%04x (%u)",
bridge_priority,
bridge_priority);
proto_tree_add_text( subtree, tvb, subofs + V_SPSOURCEID_OFFSET, V_SPSOURCEID_LEN,
"V: %u, SPSourceId: 0x%05x (%u)",
(v_spsourceid & (1 << 20)) ? 1 : 0,
v_spsourceid & 0xfffff,
v_spsourceid & 0xfffff);
proto_tree_add_text( subtree, tvb, subofs + NUM_TREES_OFFSET, NUM_TREES_LEN,
"Number of Trees: 0x%02x (%u)%s",
num_trees,
num_trees,
num_trees ? "" : " Invalid subTLV: zero trees");
subofs += FIXED_LEN;
sublen -= FIXED_LEN;
if (sublen != (num_trees * VLAN_ID_TUPLE_LEN)) {
proto_tree_add_text( subtree, tvb, subofs, 0,
"SubTLV length doesn't match number of trees");
return;
}
while (sublen > 0 && num_trees > 0) {
if (sublen < VLAN_ID_TUPLE_LEN) {
isis_dissect_unknown( tvb, subtree, offset,
"Short VLAN_ID entry (%d vs %d)", sublen, VLAN_ID_TUPLE_LEN);
return;
}
else {
const guint8 flags = tvb_get_guint8(tvb, subofs);
const guint8 *ect_id = tvb_get_ptr(tvb, subofs + 1, 4);
const guint8 *bvid_spvid = tvb_get_ptr(tvb, subofs + 1 + 4, 3);
const guint16 bvid = (0xff0 & (((guint16)bvid_spvid[0]) << 4)) | (0x0f & (bvid_spvid[1] >> 4));
const guint16 spvid = (0xf00 & (((guint16)bvid_spvid[1]) << 8)) | (0xff & (bvid_spvid[2]));
proto_tree_add_text( subtree, tvb, subofs, VLAN_ID_TUPLE_LEN,
" U: %u, M: %u, A: %u, ECT: %02x-%02x-%02x-%02x, BVID: 0x%03x (%d),%s SPVID: 0x%03x (%d)",
(flags >> 7) & 1,
(flags >> 6) & 1,
(flags >> 5) & 1,
ect_id[0], ect_id[1], ect_id[2], ect_id[3],
bvid, bvid,
( bvid < 10 ? " "
: bvid < 100 ? " "
: bvid < 1000 ? " "
: ""),
spvid, spvid);
subofs += VLAN_ID_TUPLE_LEN;
sublen -= VLAN_ID_TUPLE_LEN;
--num_trees;
}
}
if (num_trees) {
isis_dissect_unknown( tvb, subtree, offset,
"Short subTLV (%d vs %d)", sublen, num_trees * VLAN_ID_TUPLE_LEN);
return;
}
}
}
static void
dissect_isis_lsp_clv_mt_cap_spb_oalg(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
isis_dissect_unknown( tvb, tree, offset,
"MT-Cap SPB Opaque Algorithm: Type: 0x%02x, Length: %d", subtype, sublen);
}
static void
dissect_isis_lsp_clv_mt_cap_spbm_service_identifier(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int BMAC_LEN = 6;
const int BVID_LEN = 2;
const int BMAC_OFFSET = 0;
const int BVID_OFFSET = BMAC_OFFSET + BMAC_LEN;
const int FIXED_LEN = BVID_OFFSET + BVID_LEN;
const int ISID_LEN = 4;
if (sublen < FIXED_LEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPBM Service Identifier and Unicast Address subTLV (%d vs %d)", sublen, FIXED_LEN);
return;
}
else {
proto_tree *subtree, *ti;
int subofs = offset;
const guint8 *bmac = tvb_get_ptr (tvb, subofs + BMAC_OFFSET, BMAC_LEN);
const guint16 bvid = tvb_get_ntohs(tvb, subofs + BVID_OFFSET);
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB Service ID and Unicast Address: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_lsp_clv_mt_cap_spbm_service_identifier);
proto_tree_add_text( subtree, tvb, subofs + BMAC_OFFSET, BMAC_LEN,
"B-MAC: %02x-%02x-%02x-%02x-%02x-%02x",
bmac[0],
bmac[1],
bmac[2],
bmac[3],
bmac[4],
bmac[5]);
proto_tree_add_text( subtree, tvb, subofs + BVID_OFFSET, BVID_LEN,
"Base-VID: 0x%03x (%u)",
bvid, bvid);
subofs += FIXED_LEN;
sublen -= FIXED_LEN;
while (sublen > 0) {
if (sublen < ISID_LEN) {
isis_dissect_unknown( tvb, subtree, offset,
"Short ISID entry (%d vs %d)", sublen, ISID_LEN);
return;
}
else {
const guint32 isid = tvb_get_ntohl(tvb, subofs);
proto_tree_add_text( subtree, tvb, subofs, ISID_LEN,
" T: %u, R: %u, ISID: 0x%06x (%d)",
(isid >> 31) & 1,
(isid >> 30) & 1,
isid & 0x00ffffff,
isid & 0x00ffffff);
subofs += ISID_LEN;
sublen -= ISID_LEN;
}
}
}
}
static void
dissect_isis_lsp_clv_mt_cap_spbv_mac_address(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
guint16 fixed_data;
guint16 spvid;
guint8 sr_bit;
const int GMAC_LEN = 6;
const int SPVID_LEN = 2;
const int MAC_TUPLE_LEN = 7;
const int SPVID_OFFSET = 0;
const int FIXED_LEN = SPVID_OFFSET + SPVID_LEN;
if (sublen < FIXED_LEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPBV Mac Address subTLV (%d vs %d)", sublen, FIXED_LEN);
return;
}
else {
proto_tree *subtree, *ti;
int subofs = offset;
fixed_data = tvb_get_ntohs(tvb, subofs);
spvid = (fixed_data & 0x0FFF);
sr_bit = (fixed_data & 0x3000) >> 12;
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPBV Mac Address: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_lsp_clv_mt_cap_spbv_mac_address);
proto_tree_add_uint(subtree, hf_isis_lsp_spb_sr_bit,
tvb, subofs, 1, sr_bit);
proto_tree_add_uint(subtree, hf_isis_lsp_spb_spvid,
tvb, subofs, 2, spvid);
subofs += FIXED_LEN;
sublen -= FIXED_LEN;
while (sublen > 0) {
if (sublen < MAC_TUPLE_LEN) {
isis_dissect_unknown( tvb, subtree, offset,
" Short MAC Address entry (%d vs %d)", sublen, MAC_TUPLE_LEN);
return;
}
else {
const guint32 tr_bit = tvb_get_guint8(tvb, subofs);
const guint8 *gmac = tvb_get_ptr(tvb, subofs + 1, GMAC_LEN);
proto_tree_add_text( subtree, tvb, subofs, MAC_TUPLE_LEN,
" T: %u, R: %u, MAC: %02x-%02x-%02x-%02x-%02x-%02x",
(tr_bit >> 7) & 1,
(tr_bit >> 6) & 1,
gmac[0],
gmac[1],
gmac[2],
gmac[3],
gmac[4],
gmac[5]);
subofs += MAC_TUPLE_LEN;
sublen -= MAC_TUPLE_LEN;
}
}
}
}
static void
dissect_isis_lsp_clv_mt_cap(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
if (length >= 2) {
guint16 mtid = tvb_get_ntohs(tvb, offset);
proto_tree_add_text( tree, tvb, offset, 2,
"MTID: 0x%03x, Overload: %d",
(mtid & 0xfff),
(mtid & 0x8000) ? 1 : 0);
length -= 2;
offset += 2;
while (length >= 2) {
guint8 subtype = tvb_get_guint8(tvb, offset);
guint8 subtlvlen = tvb_get_guint8(tvb, offset+1);
length -= 2;
offset += 2;
if (subtlvlen > length) {
isis_dissect_unknown( tvb, tree, offset,
"Short type 0x%02x TLV (%d vs %d)", subtype, subtlvlen, length);
return;
}
if (subtype == 0x01) {
dissect_isis_lsp_clv_mt_cap_spb_instance(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x02) {
dissect_isis_lsp_clv_mt_cap_spb_oalg(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x03) {
dissect_isis_lsp_clv_mt_cap_spbm_service_identifier(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x04) {
dissect_isis_lsp_clv_mt_cap_spbv_mac_address(tvb, tree, offset, subtype, subtlvlen);
}
else {
isis_dissect_unknown( tvb, tree, offset,
"Unknown SubTlv: Type: 0x%02x, Length: %d", subtype, subtlvlen);
}
length -= subtlvlen;
offset += subtlvlen;
}
}
}
static void
dissect_lsp_authentication_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_lsp_ip_authentication_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ip_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_lsp_area_address_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_area_address_clv(tvb, tree, offset, length);
}
static void
dissect_lsp_eis_neighbors_clv_inner(tvbuff_t *tvb, proto_tree *tree,
int offset, int length, int id_length, int show_virtual, int is_eis)
{
proto_item *ti;
proto_tree *ntree = NULL;
int tlen;
if (!is_eis) {
id_length++;
if ( tree ) {
if ( show_virtual ) {
proto_tree_add_text ( tree, tvb, offset, 1,
tvb_get_guint8(tvb, offset) ? "IsVirtual" : "IsNotVirtual" );
} else {
proto_tree_add_text ( tree, tvb, offset, 1,
"Reserved value 0x%02x, must == 0",
tvb_get_guint8(tvb, offset) );
}
}
offset++;
length--;
}
tlen = 4 + id_length;
while ( length > 0 ) {
if (length<tlen) {
isis_dissect_unknown(tvb, tree, offset,
"short E/IS reachability (%d vs %d)", length,
tlen );
return;
}
if ( tree ) {
if ( is_eis ) {
ti = proto_tree_add_text(tree, tvb, offset, tlen,
"ES Neighbor: %s",
print_system_id( tvb_get_ptr(tvb, offset+4, id_length), id_length ) );
} else {
ti = proto_tree_add_text(tree, tvb, offset, tlen,
"IS Neighbor: %s",
print_system_id(tvb_get_ptr(tvb, offset+4, id_length), id_length ) );
}
ntree = proto_item_add_subtree(ti,
ett_isis_lsp_clv_is_neighbors);
proto_tree_add_text (ntree, tvb, offset, 1,
"Default Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset)) ? "External" : "Internal");
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+1))) {
proto_tree_add_text (ntree, tvb, offset+1, 1, "Delay Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+1, 1, "Delay Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+1)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+1)) ? "External" : "Internal");
}
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+2))) {
proto_tree_add_text (ntree, tvb, offset+2, 1, "Expense Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+2, 1, "Expense Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+2)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+2)) ? "External" : "Internal");
}
if (ISIS_LSP_CLV_METRIC_SUPPORTED(tvb_get_guint8(tvb, offset+3))) {
proto_tree_add_text (ntree, tvb, offset+3, 1, "Error Metric: Not supported");
} else {
proto_tree_add_text (ntree, tvb, offset+3, 1, "Error Metric: %d, %s",
ISIS_LSP_CLV_METRIC_VALUE(tvb_get_guint8(tvb, offset+3)),
ISIS_LSP_CLV_METRIC_IE(tvb_get_guint8(tvb, offset+3)) ? "External" : "Internal");
}
}
offset += tlen;
length -= tlen;
}
}
static void
dissect_lsp_l1_is_neighbors_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, tree, offset,
length, id_length, TRUE, FALSE);
}
static void
dissect_lsp_l1_es_neighbors_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, tree, offset,
length, id_length, TRUE, TRUE);
}
static void
dissect_lsp_l2_is_neighbors_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, tree, offset,
length, id_length, FALSE, FALSE);
}
static void
dissect_subclv_admin_group (tvbuff_t *tvb, proto_tree *tree, int offset) {
proto_item *ti;
proto_tree *ntree;
guint32 clv_value;
guint32 mask;
int i;
ti = proto_tree_add_text(tree, tvb, offset-2, 6, "Administrative group(s):");
ntree = proto_item_add_subtree (ti, ett_isis_lsp_subclv_admin_group);
clv_value = tvb_get_ntohl(tvb, offset);
mask = 1;
for (i = 0 ; i < 32 ; i++) {
if ( (clv_value & mask) != 0 ) {
proto_tree_add_text (ntree, tvb, offset, 4, "group %d", i);
}
mask <<= 1;
}
}
static void
dissect_subclv_max_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
gfloat bw;
bw = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text (tree, tvb, offset-2, 6,
"Maximum link bandwidth : %.2f Mbps", bw*8/1000000 );
}
static void
dissect_subclv_rsv_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
gfloat bw;
bw = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text (tree, tvb, offset-2, 6,
"Reservable link bandwidth: %.2f Mbps", bw*8/1000000 );
}
static void
dissect_subclv_unrsv_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *ntree;
gfloat bw;
int i;
ti = proto_tree_add_text (tree, tvb, offset-2, 34, "Unreserved bandwidth:");
ntree = proto_item_add_subtree (ti, ett_isis_lsp_subclv_unrsv_bw);
for (i = 0 ; i < 8 ; i++) {
bw = tvb_get_ntohieee_float(tvb, offset+4*i);
proto_tree_add_text (ntree, tvb, offset+4*i, 4,
"priority level %d: %.2f Mbps", i, bw*8/1000000 );
}
}
static void
dissect_subclv_spb_link_metric(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int SUBLEN = 6;
if (sublen != SUBLEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPB Link Metric sub-TLV (%d vs %d)", sublen, SUBLEN);
return;
}
else {
proto_tree *subtree, *ti;
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB Link Metric: Type: 0x%02x (%d), Length: %d", subtype, subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_lsp_subclv_spb_link_metric);
proto_tree_add_item(subtree, hf_isis_lsp_spb_link_metric,
tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_port_count,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_port_id,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_lsp_ext_is_reachability_clv(tvbuff_t *tvb, proto_tree *tree,
int offset, int id_length _U_, int length)
{
proto_item *ti;
proto_tree *ntree = NULL;
guint subclvs_len;
guint len, i;
guint clv_code, clv_len;
if (!tree) return;
while (length > 0) {
ti = proto_tree_add_text (tree, tvb, offset, -1,
"IS neighbor: %s",
print_system_id (tvb_get_ptr(tvb, offset, 7), 7) );
ntree = proto_item_add_subtree (ti,
ett_isis_lsp_part_of_clv_ext_is_reachability );
proto_tree_add_text (ntree, tvb, offset+7, 3,
"Metric: %d", tvb_get_ntoh24(tvb, offset+7) );
subclvs_len = tvb_get_guint8(tvb, offset+10);
if (subclvs_len == 0) {
proto_tree_add_text (ntree, tvb, offset+10, 1, "no sub-TLVs present");
}
else {
i = 0;
while (i < subclvs_len) {
clv_code = tvb_get_guint8(tvb, offset+11+i);
clv_len = tvb_get_guint8(tvb, offset+12+i);
switch (clv_code) {
case 3 :
dissect_subclv_admin_group(tvb, ntree, offset+13+i);
break;
case 4 :
proto_tree_add_text(ntree, tvb, offset+13+i, 4,
"Link Local Identifier: %d", tvb_get_ntohl(tvb, offset+13+i));
proto_tree_add_text(ntree, tvb, offset+17+i, 4,
"Link Remote Identifier: %d", tvb_get_ntohl(tvb, offset+17+i));
break;
case 6 :
proto_tree_add_text (ntree, tvb, offset+11+i, 6,
"IPv4 interface address: %s", tvb_ip_to_str(tvb, offset+13+i));
break;
case 8 :
proto_tree_add_text (ntree, tvb, offset+11+i, 6,
"IPv4 neighbor address: %s", tvb_ip_to_str(tvb, offset+13+i));
break;
case 9 :
dissect_subclv_max_bw (tvb, ntree, offset+13+i);
break;
case 10:
dissect_subclv_rsv_bw (tvb, ntree, offset+13+i);
break;
case 11:
dissect_subclv_unrsv_bw (tvb, ntree, offset+13+i);
break;
case 18:
proto_tree_add_text (ntree, tvb, offset+11+i, 5,
"Traffic engineering default metric: %d",
tvb_get_ntoh24(tvb, offset+13+i) );
break;
case 29:
dissect_subclv_spb_link_metric(tvb, ntree,
offset+13+i, clv_code, clv_len);
break;
case 250:
case 251:
case 252:
case 253:
case 254:
proto_tree_add_text (ntree, tvb, offset+11+i, clv_len+2,
"Unknown Cisco specific extensions: code %d, length %d",
clv_code, clv_len );
break;
default :
proto_tree_add_text (ntree, tvb, offset+11+i, clv_len+2,
"Unknown sub-CLV: code %d, length %d", clv_code, clv_len );
break;
}
i += clv_len + 2;
}
}
len = 11 + subclvs_len;
proto_item_set_len (ti, len);
offset += len;
length -= len;
}
}
static void
dissect_lsp_mt_reachable_IPv4_prefx_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
if (!tree) return;
if (length < 2) {
isis_dissect_unknown(tvb, tree, offset,
"short lsp multi-topology reachable IPv4 prefixes(%d vs %d)", length,
2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ext_ip_reachability_clv(tvb, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_mt_reachable_IPv6_prefx_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
if (!tree) return;
if (length < 2) {
isis_dissect_unknown(tvb, tree, offset,
"short lsp multi-topology reachable IPv6 prefixes(%d vs %d)", length,
2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ipv6_reachability_clv(tvb, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_mt_is_reachability_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
if (!tree) return;
if (length < 2) {
isis_dissect_unknown(tvb, tree, offset,
"short lsp reachability(%d vs %d)", length,
2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ext_is_reachability_clv(tvb, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_partition_dis_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length, int length)
{
if ( length < id_length ) {
isis_dissect_unknown(tvb, tree, offset,
"short lsp partition DIS(%d vs %d)", length,
id_length );
return;
}
if ( tree ) {
proto_tree_add_text ( tree, tvb, offset, id_length,
"Partition designated L2 IS: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length), id_length ) );
}
length -= id_length;
offset += id_length;
if ( length > 0 ) {
isis_dissect_unknown(tvb, tree, offset,
"Long lsp partition DIS, %d left over", length );
return;
}
}
static void
dissect_lsp_prefix_neighbors_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
char *sbuf;
int mylen;
if ( length < 4 ) {
isis_dissect_unknown(tvb, tree, offset,
"Short lsp prefix neighbors (%d vs 4)", length );
return;
}
if ( tree ) {
dissect_metric (tvb, tree, offset,
tvb_get_guint8(tvb, offset), "Default", TRUE );
dissect_metric (tvb, tree, offset+1,
tvb_get_guint8(tvb, offset+1), "Delay", FALSE );
dissect_metric (tvb, tree, offset+2,
tvb_get_guint8(tvb, offset+2), "Expense", FALSE );
dissect_metric (tvb, tree, offset+3,
tvb_get_guint8(tvb, offset+3), "Error", FALSE );
}
offset += 4;
length -= 4;
while ( length > 0 ) {
mylen = tvb_get_guint8(tvb, offset);
length--;
if (length<=0) {
isis_dissect_unknown(tvb, tree, offset,
"Zero payload space after length in prefix neighbor" );
return;
}
if ( mylen > length) {
isis_dissect_unknown(tvb, tree, offset,
"Integral length of prefix neighbor too long (%d vs %d)",
mylen, length );
return;
}
sbuf = print_area( tvb_get_ptr(tvb, offset+1, mylen), mylen );
if ( tree ) {
proto_tree_add_text ( tree, tvb, offset, mylen + 1,
"Area address (%d): %s", mylen, sbuf );
}
offset += mylen + 1;
length -= mylen;
}
}
static void isis_lsp_checkum_additional_info(tvbuff_t * tvb, packet_info * pinfo,
proto_item * it_cksum, int offset, gboolean is_cksum_correct)
{
proto_tree * checksum_tree;
proto_item * item;
checksum_tree = proto_item_add_subtree(it_cksum, ett_isis_lsp_cksum);
item = proto_tree_add_boolean(checksum_tree, hf_isis_lsp_checksum_good, tvb,
offset, 2, is_cksum_correct);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_isis_lsp_checksum_bad, tvb,
offset, 2, !is_cksum_correct);
PROTO_ITEM_SET_GENERATED(item);
if (!is_cksum_correct) {
expert_add_info(pinfo, item, &ie_isis_lsp_checksum_bad);
col_append_str(pinfo->cinfo, COL_INFO, " [ISIS CHECKSUM INCORRECT]");
}
}
void
isis_dissect_isis_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int lsp_type, int header_length, int id_length)
{
proto_item *ti, *to, *ta;
proto_tree *lsp_tree = NULL, *info_tree, *att_tree;
guint16 pdu_length, lifetime, checksum, cacl_checksum=0;
guint8 lsp_info, lsp_att;
int len, offset_checksum;
proto_item *it_cksum;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, -1,
PROTO_STRING_LSP);
lsp_tree = proto_item_add_subtree(ti, ett_isis_lsp);
}
pdu_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(lsp_tree, hf_isis_lsp_pdu_length, tvb,
offset, 2, pdu_length);
}
offset += 2;
if (tree) {
proto_tree_add_item(lsp_tree, hf_isis_lsp_remaining_life,
tvb, offset, 2, ENC_BIG_ENDIAN);
}
lifetime = tvb_get_ntohs(tvb, offset);
offset += 2;
offset_checksum = offset;
if (tree) {
char* value = print_system_id( tvb_get_ptr(tvb, offset, id_length+2),
id_length+2);
proto_tree_add_string_format_value(lsp_tree, hf_isis_lsp_lsp_id,
tvb, offset, id_length + 2,
value, "%s", value);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", LSP-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+2), id_length+2 ) );
offset += id_length + 2;
proto_tree_add_item(lsp_tree, hf_isis_lsp_sequence_number,
tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Sequence: 0x%08x, Lifetime: %5us",
tvb_get_ntohl(tvb, offset),
tvb_get_ntohs(tvb, offset - (id_length+2+2)));
offset += 4;
if (tree) {
checksum = lifetime ? tvb_get_ntohs(tvb, offset) : 0;
switch (check_and_get_checksum(tvb, offset_checksum, pdu_length-12, checksum, offset, &cacl_checksum)) {
case NO_CKSUM :
checksum = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(lsp_tree, hf_isis_lsp_checksum, tvb, offset, 2, checksum,
"0x%04x [unused]", checksum);
break;
case DATA_MISSING :
isis_dissect_unknown(tvb, tree, offset,
"[packet length %d went beyond packet]",
tvb_length_remaining(tvb, offset_checksum));
break;
case CKSUM_NOT_OK :
it_cksum = proto_tree_add_uint_format_value(lsp_tree, hf_isis_lsp_checksum, tvb, offset, 2, checksum,
"0x%04x [incorrect, should be 0x%04x]",
checksum, cacl_checksum);
isis_lsp_checkum_additional_info(tvb, pinfo, it_cksum, offset, FALSE);
break;
case CKSUM_OK :
it_cksum = proto_tree_add_uint_format_value(lsp_tree, hf_isis_lsp_checksum, tvb, offset, 2, checksum,
"0x%04x [correct]", checksum);
isis_lsp_checkum_additional_info(tvb, pinfo, it_cksum, offset, TRUE);
break;
default :
g_message("'check_and_get_checksum' returned an invalid value");
}
}
offset += 2;
if (tree) {
lsp_info = tvb_get_guint8(tvb, offset);
to = proto_tree_add_text(lsp_tree, tvb, offset, 1,
"Type block(0x%02x): Partition Repair:%d, Attached bits:%d, Overload bit:%d, IS type:%d",
lsp_info,
ISIS_LSP_PARTITION(lsp_info),
ISIS_LSP_ATT(lsp_info),
ISIS_LSP_HIPPITY(lsp_info),
ISIS_LSP_IS_TYPE(lsp_info)
);
info_tree = proto_item_add_subtree(to, ett_isis_lsp_info);
proto_tree_add_boolean(info_tree, hf_isis_lsp_p, tvb, offset, 1, lsp_info);
ta = proto_tree_add_uint(info_tree, hf_isis_lsp_att, tvb, offset, 1, lsp_info);
att_tree = proto_item_add_subtree(ta, ett_isis_lsp_att);
lsp_att = ISIS_LSP_ATT(lsp_info);
proto_tree_add_text(att_tree, tvb, offset, 1,
"%d... = Error metric: %s", ISIS_LSP_ATT_ERROR(lsp_att), ISIS_LSP_ATT_ERROR(lsp_att) ? "Set" : "Unset");
proto_tree_add_text(att_tree, tvb, offset, 1,
".%d.. = Expense metric: %s", ISIS_LSP_ATT_EXPENSE(lsp_att), ISIS_LSP_ATT_EXPENSE(lsp_att) ? "Set" : "Unset");
proto_tree_add_text(att_tree, tvb, offset, 1,
"..%d. = Delay metric: %s", ISIS_LSP_ATT_DELAY(lsp_att), ISIS_LSP_ATT_DELAY(lsp_att) ? "Set" : "Unset");
proto_tree_add_text(att_tree, tvb, offset, 1,
"...%d = Default metric: %s", ISIS_LSP_ATT_DEFAULT(lsp_att), ISIS_LSP_ATT_DEFAULT(lsp_att) ? "Set" : "Unset");
proto_tree_add_boolean(info_tree, hf_isis_lsp_hippity, tvb, offset, 1, lsp_info);
proto_tree_add_uint(info_tree, hf_isis_lsp_is_type, tvb, offset, 1, lsp_info);
}
offset += 1;
len = pdu_length - header_length;
if (len < 0) {
isis_dissect_unknown(tvb, tree, offset,
"packet header length %d went beyond packet",
header_length );
return;
}
if (lsp_type == ISIS_TYPE_L1_LSP) {
isis_dissect_clvs(tvb, lsp_tree, offset,
clv_l1_lsp_opts, len, id_length,
ett_isis_lsp_clv_unknown );
} else {
isis_dissect_clvs(tvb, lsp_tree, offset,
clv_l2_lsp_opts, len, id_length,
ett_isis_lsp_clv_unknown );
}
}
void
isis_register_lsp(int proto_isis) {
static hf_register_info hf[] = {
{ &hf_isis_lsp_pdu_length,
{ "PDU length", "isis.lsp.pdu_length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_remaining_life,
{ "Remaining lifetime", "isis.lsp.remaining_life", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_lsp_id,
{ "LSP-ID", "isis.lsp.lsp_id", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_hostname,
{ "Hostname", "isis.lsp.hostname", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_sequence_number,
{ "Sequence number", "isis.lsp.sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_checksum,
{ "Checksum", "isis.lsp.checksum",FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_checksum_good,
{ "Good Checksum", "isis.lsp.checksum_good", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Good IS-IS LSP Checksum", HFILL }},
{ &hf_isis_lsp_checksum_bad,
{ "Bad Checksum", "isis.lsp.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Bad IS-IS LSP Checksum", HFILL }},
{ &hf_isis_lsp_clv_ipv4_int_addr,
{ "IPv4 interface address", "isis.lsp.clv_ipv4_int_addr", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_clv_ipv6_int_addr,
{ "IPv6 interface address", "isis.lsp.clv_ipv6_int_addr", FT_IPv6,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_clv_te_router_id,
{ "Traffic Engineering Router ID", "isis.lsp.clv_te_router_id", FT_IPv4,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_clv_mt,
{ "MT-ID", "isis.lsp.clv_mt",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_p,
{ "Partition Repair", "isis.lsp.partition_repair", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), ISIS_LSP_PARTITION_MASK,
"If set, this router supports the optional Partition Repair function", HFILL }},
{ &hf_isis_lsp_att,
{ "Attachment", "isis.lsp.att", FT_UINT8, BASE_DEC,
NULL, ISIS_LSP_ATT_MASK,
NULL, HFILL }},
{ &hf_isis_lsp_hippity,
{ "Overload bit", "isis.lsp.overload", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), ISIS_LSP_HIPPITY_MASK,
"If set, this router will not be used by any decision process to calculate routes", HFILL }},
{ &hf_isis_lsp_root_id,
{ "Root Bridge ID", "isis.lsp.root.id", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_isis_lsp_is_type,
{ "Type of Intermediate System", "isis.lsp.is_type", FT_UINT8, BASE_DEC,
VALS(isis_lsp_istype_vals), ISIS_LSP_IS_TYPE_MASK,
NULL, HFILL }},
{ &hf_isis_lsp_spb_link_metric,
{ "SPB Link Metric", "isis.lsp.spb.link_metric",
FT_UINT24, BASE_HEX_DEC, NULL, 0, NULL, HFILL }},
{ &hf_isis_lsp_spb_port_count,
{ "Number of Ports", "isis.lsp.spb.port_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_isis_lsp_spb_port_id,
{ "Port Id", "isis.lsp.spb.port_id",
FT_UINT16, BASE_HEX_DEC, NULL, 0, NULL, HFILL }},
{ &hf_isis_lsp_spb_sr_bit,
{ "SR Bit", "isis.lsp.spb.sr_bit",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_isis_lsp_spb_spvid,
{ "SPVID", "isis.lsp.spb.spvid",
FT_UINT16, BASE_HEX_DEC, NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_isis_lsp,
&ett_isis_lsp_info,
&ett_isis_lsp_att,
&ett_isis_lsp_cksum,
&ett_isis_lsp_clv_area_addr,
&ett_isis_lsp_clv_is_neighbors,
&ett_isis_lsp_clv_ext_is_reachability,
&ett_isis_lsp_part_of_clv_ext_is_reachability,
&ett_isis_lsp_subclv_admin_group,
&ett_isis_lsp_subclv_unrsv_bw,
&ett_isis_lsp_subclv_spb_link_metric,
&ett_isis_lsp_clv_unknown,
&ett_isis_lsp_clv_partition_dis,
&ett_isis_lsp_clv_prefix_neighbors,
&ett_isis_lsp_clv_authentication,
&ett_isis_lsp_clv_ip_authentication,
&ett_isis_lsp_clv_nlpid,
&ett_isis_lsp_clv_hostname,
&ett_isis_lsp_clv_ipv4_int_addr,
&ett_isis_lsp_clv_ipv6_int_addr,
&ett_isis_lsp_clv_mt_cap,
&ett_isis_lsp_clv_mt_cap_spb_instance,
&ett_isis_lsp_clv_mt_cap_spbm_service_identifier,
&ett_isis_lsp_clv_te_router_id,
&ett_isis_lsp_clv_ip_reachability,
&ett_isis_lsp_clv_ip_reach_subclv,
&ett_isis_lsp_clv_ext_ip_reachability,
&ett_isis_lsp_part_of_clv_ext_ip_reachability,
&ett_isis_lsp_clv_ipv6_reachability,
&ett_isis_lsp_part_of_clv_ipv6_reachability,
&ett_isis_lsp_clv_mt,
&ett_isis_lsp_clv_mt_is,
&ett_isis_lsp_part_of_clv_mt_is,
&ett_isis_lsp_clv_rt_capable_IPv4_prefx,
&ett_isis_lsp_clv_grp_address_IPv4_prefx,
&ett_isis_lsp_clv_mt_reachable_IPv4_prefx,
&ett_isis_lsp_clv_mt_reachable_IPv6_prefx,
&ett_isis_lsp_clv_mt_cap_spbv_mac_address
};
static ei_register_info ei[] = {
{ &ie_isis_lsp_checksum_bad, { "isis.lsp.checksum_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_isis;
proto_register_field_array(proto_isis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isis = expert_register_protocol(proto_isis);
expert_register_field_array(expert_isis, ei, array_length(ei));
}
