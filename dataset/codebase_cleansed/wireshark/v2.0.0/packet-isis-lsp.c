static void
dissect_lsp_mt_id(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_isis_lsp_mt_id_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isis_lsp_mt_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_metric(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset, guint8 value,
int hf, int hf_support, int force_supported )
{
int s;
proto_item *item, *support_item;
s = ISIS_LSP_CLV_METRIC_SUPPORTED(value);
item = proto_tree_add_uint(tree, hf, tvb, offset, 1, value);
support_item = proto_tree_add_uint(tree, hf_support, tvb, offset, 1, value);
if (s && force_supported)
proto_item_append_text(support_item, " (but is required to be)");
if (ISIS_LSP_CLV_METRIC_RESERVED(value))
expert_add_info(pinfo, item, &ei_isis_lsp_reserved_not_zero);
}
static void
dissect_lsp_ip_reachability_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_item *ti;
proto_tree *ntree = NULL;
guint32 src, mask, bitmask;
int prefix_len;
gboolean found_mask = FALSE;
while ( length > 0 ) {
if (length<12) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
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
ti = proto_tree_add_ipv4_format_value( tree, hf_isis_lsp_ip_reachability_ipv4_prefix, tvb, offset, 12,
src, "%s/%d", tvb_ip_to_str(tvb, offset+4), prefix_len );
} else {
ti = proto_tree_add_ipv4_format_value( tree, hf_isis_lsp_ip_reachability_ipv4_prefix, tvb, offset, 12,
src, "%s mask %s", tvb_ip_to_str(tvb, offset+4), tvb_ip_to_str(tvb, offset+8));
};
ntree = proto_item_add_subtree(ti, ett_isis_lsp_clv_ip_reachability);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_default_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_default_metric_ie, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_distribution, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_delay_metric, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_delay_metric_support, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_delay_metric_ie, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_expense_metric, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_expense_metric_support, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_expense_metric_ie, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_error_metric, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_error_metric_support, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_ip_reachability_error_metric_ie, tvb, offset+3, 1, ENC_NA);
}
offset += 12;
length -= 12;
}
}
static void
dissect_ipreach_subclv(tvbuff_t *tvb, proto_tree *tree, int offset, int clv_code, int clv_len)
{
guint8 flags;
switch (clv_code) {
case 1:
while (clv_len >= 4) {
proto_tree_add_item(tree, hf_isis_lsp_32_bit_administrative_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
clv_len-=4;
}
break;
case 2:
while (clv_len >= 8) {
proto_tree_add_item(tree, hf_isis_lsp_64_bit_administrative_tag, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
clv_len-=8;
}
break;
case 3:
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_isis_lsp_ext_ip_reachability_prefix_flags,
ett_isis_lsp_prefix_sid_flags, prefix_sid_flags, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_isis_lsp_clv_sr_alg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if ((flags & 0xC) == 0xC) {
proto_tree_add_item(tree, hf_isis_lsp_sid_sli_label, tvb, offset, 3, ENC_BIG_ENDIAN);
} else if (!(flags & 0xC)) {
proto_tree_add_item(tree, hf_isis_lsp_sid_sli_index, tvb, offset, 4, ENC_BIG_ENDIAN);
}
break;
default :
break;
}
}
static void
dissect_lsp_ext_ip_reachability_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree,
int offset, int id_length _U_, int length)
{
proto_tree *subtree = NULL;
proto_tree *subclv_tree = NULL;
proto_item *ti_subclvs = NULL;
guint8 ctrl_info;
guint bit_length;
int byte_length;
guint8 prefix [4];
address prefix_addr;
guint len,i;
guint subclvs_len;
guint clv_code, clv_len;
while (length > 0) {
ctrl_info = tvb_get_guint8(tvb, offset+4);
bit_length = ctrl_info & 0x3f;
byte_length = ipv4_addr_and_mask(tvb, offset+5, prefix, bit_length);
if (byte_length == -1) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"IPv4 prefix has an invalid length: %d bits", bit_length );
return;
}
subclvs_len = 0;
if ((ctrl_info & 0x40) != 0)
subclvs_len = 1+tvb_get_guint8(tvb, offset+5+byte_length);
subtree = proto_tree_add_subtree(tree, tvb, offset, 5+byte_length+subclvs_len,
ett_isis_lsp_part_of_clv_ext_ip_reachability, NULL, "Ext. IP Reachability");
SET_ADDRESS(&prefix_addr, AT_IPv4, 4, prefix);
proto_tree_add_ipv4_format_value(subtree, hf_isis_lsp_ext_ip_reachability_ipv4_prefix, tvb, offset+5, byte_length,
tvb_get_ntohl(tvb, offset+5), "%s/%u", address_to_str(wmem_packet_scope(), &prefix_addr), bit_length);
proto_tree_add_item(subtree, hf_isis_lsp_ext_ip_reachability_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_ext_ip_reachability_distribution, tvb, offset+4, 1, ENC_NA);
len = 5 + byte_length;
if ((ctrl_info & 0x40) != 0) {
subclvs_len = tvb_get_guint8(tvb, offset+len);
proto_tree_add_item(subtree, hf_isis_lsp_ext_ip_reachability_subclvs_len, tvb, offset+len, 1, ENC_BIG_ENDIAN);
i =0;
while (i < subclvs_len) {
clv_code = tvb_get_guint8(tvb, offset+len+1);
clv_len = tvb_get_guint8(tvb, offset+len+2);
subclv_tree = proto_tree_add_subtree(subtree, tvb, offset+len+1, clv_len + 2,
ett_isis_lsp_clv_ip_reach_subclv,
&ti_subclvs, "subTLV");
proto_tree_add_item(subclv_tree, hf_isis_lsp_ext_ip_reachability_code,
tvb, offset+len+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subclv_tree, hf_isis_lsp_ext_ip_reachability_len, tvb, offset+len+2, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_subclvs, ": %s (c=%u, l=%u)", val_to_str(clv_code, isis_lsp_ext_ip_reachability_code_vals, "Unknown"), clv_code, clv_len);
dissect_ipreach_subclv(tvb, subclv_tree, offset+len+3, clv_code, clv_len);
i += clv_len + 2;
}
len += 1 + subclvs_len;
} else {
proto_tree_add_uint_format(subtree, hf_isis_lsp_ext_ip_reachability_subclvs_len, tvb, offset, len, 0, "no sub-TLVs present");
}
offset += len;
length -= len;
}
}
static void
dissect_isis_grp_address_clv(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, int offset,
int tree_id,int length)
{
gint len;
gint source_num;
guint16 mt_block;
proto_tree *rt_tree=NULL;
while (length>0) {
mt_block=tvb_get_ntohs(tvb, offset);
switch((mt_block&0xff00)>>8) {
case GRP_MAC_ADDRESS:
rt_tree = proto_tree_add_subtree(tree, tvb, offset, (mt_block&0x00ff)+2,
ett_isis_lsp_clv_grp_macaddr, NULL, "Group MAC Address Sub-TLV");
length--;
offset++;
len=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_length, tvb, offset, 1, ENC_BIG_ENDIAN);
if(len < 5) {
length -= len;
offset += len;
break;
}
length--;
offset++;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_topology_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_number_of_records, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
while(len > 0) {
source_num=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_number_of_sources, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_group_address, tvb, offset, 6, ENC_NA);
length -= 6;
offset += 6;
len -= 6;
while((len > 0) && (source_num > 0)) {
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_macaddr_source_address, tvb, offset, 6, ENC_NA);
length -= 6;
offset += 6;
len -= 6;
source_num--;
}
}
break;
case GRP_IPV4_ADDRESS:
rt_tree = proto_tree_add_subtree(tree, tvb, offset, (mt_block&0x00ff)+2,
ett_isis_lsp_clv_grp_ipv4addr, NULL, "Group IPv4 Address Sub-TLV");
length--;
offset++;
len=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_length, tvb, offset, 1, ENC_BIG_ENDIAN);
if(len < 5) {
length -= len;
offset += len;
break;
}
length--;
offset++;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_topology_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_number_of_records, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
while(len > 0) {
source_num=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_number_of_sources, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_group_address, tvb, offset, 4, ENC_BIG_ENDIAN);
length -= 4;
offset += 4;
len -= 4;
while((len > 0) && (source_num > 0)) {
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv4addr_source_address, tvb, offset, 4, ENC_BIG_ENDIAN);
length -= 4;
offset += 4;
len -= 4;
source_num--;
}
}
break;
case GRP_IPV6_ADDRESS:
rt_tree = proto_tree_add_subtree(tree, tvb, offset, (mt_block&0x00ff)+2,
ett_isis_lsp_clv_grp_ipv6addr, NULL, "Group IPv6 Address Sub-TLV");
length--;
offset++;
len=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_length, tvb, offset, 1, ENC_BIG_ENDIAN);
if(len < 5) {
length -= len;
offset += len;
break;
}
length--;
offset++;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_topology_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
len -= 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_number_of_records, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
while(len > 0) {
source_num=tvb_get_guint8(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_number_of_sources, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
offset++;
len--;
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_group_address, tvb, offset, 16, ENC_NA);
length -= 16;
offset += 16;
len -= 16;
while((len > 0) && (source_num > 0)) {
proto_tree_add_item(rt_tree, hf_isis_lsp_grp_ipv6addr_source_address, tvb, offset, 16, ENC_NA);
length -= 16;
offset += 16;
len -= 16;
source_num--;
}
}
break;
default:
proto_tree_add_uint_format ( tree, tree_id, tvb, offset,(mt_block&0x00ff)+2,
mt_block, "Unknown Sub-TLV");
offset++;
length -= (2+tvb_get_guint8(tvb, offset));
offset += (1+tvb_get_guint8(tvb, offset));
break;
}
}
}
static void
dissect_lsp_sr_sid_label_clv(tvbuff_t *tvb, packet_info* pinfo _U_,
proto_tree *tree, int offset, guint8 tlv_len)
{
proto_tree *subtree;
subtree = proto_tree_add_subtree_format(tree, tvb, offset-2, tlv_len+2, ett_isis_lsp_clv_sr_sid_label,
NULL, "SID/Label (t=1, l=%u)", tlv_len);
switch (tlv_len) {
case 4:
proto_tree_add_item(subtree, hf_isis_lsp_clv_sr_cap_sid, tvb, offset+6, tlv_len, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(subtree, hf_isis_lsp_clv_sr_cap_label, tvb, offset+6, tlv_len, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert_format(subtree, pinfo, &ei_isis_lsp_subtlv, tvb, offset+4, tlv_len+2,
"SID/Label SubTlv - Bad length: Type: %d, Length: %d", ISIS_SR_SID_LABEL, tlv_len);
break;
}
}
static int
dissect_isis_trill_clv(tvbuff_t *tvb, packet_info* pinfo _U_,
proto_tree *tree, int offset, int subtype, int sublen)
{
guint16 rt_block;
proto_tree *rt_tree, *cap_tree;
guint16 root_id;
guint8 tlv_type, tlv_len;
int i;
switch (subtype) {
case ISIS_TE_NODE_CAP_DESC:
cap_tree = proto_tree_add_subtree(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_te_node_cap_desc, NULL, "TE Node Capability Descriptor");
proto_tree_add_item(cap_tree, hf_isis_lsp_clv_te_node_cap_b_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_isis_lsp_clv_te_node_cap_e_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_isis_lsp_clv_te_node_cap_m_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_isis_lsp_clv_te_node_cap_g_bit, tvb, offset, 1, ENC_NA);
proto_tree_add_item(cap_tree, hf_isis_lsp_clv_te_node_cap_p_bit, tvb, offset, 1, ENC_NA);
return(0);
case SEGMENT_ROUTING_CAP:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2, ett_isis_lsp_clv_sr_cap,
NULL, "Segment Routing - Capability (t=%u, l=%u)", subtype, sublen);
proto_tree_add_item(rt_tree, hf_isis_lsp_clv_sr_cap_i_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rt_tree, hf_isis_lsp_clv_sr_cap_v_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(rt_tree, hf_isis_lsp_clv_sr_cap_range, tvb, offset+1, 3, ENC_BIG_ENDIAN);
tlv_type = tvb_get_guint8(tvb, offset+4);
tlv_len = tvb_get_guint8(tvb, offset+5);
if (tlv_type == ISIS_SR_SID_LABEL) {
dissect_lsp_sr_sid_label_clv(tvb, pinfo, rt_tree, offset, tlv_len);
} else
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_subtlv, tvb, offset+4, tlv_len+2,
"Unknown SubTlv: Type: %d, Length: %d", tlv_type, tlv_len);
return(0);
case TRILL_VERSION:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_trill_version, NULL, "TRILL version (t=%u, l=%u)", subtype, sublen);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trill_maximum_version, tvb, offset, 1, ENC_BIG_ENDIAN);
if ( sublen == 5 ) {
offset++;
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trill_affinity_tlv, tvb, offset, 4, ENC_NA);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trill_fgl_safe, tvb, offset, 4, ENC_NA);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trill_caps, tvb, offset, 4, ENC_NA);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trill_flags, tvb, offset, 4, ENC_NA);
}
return(0);
case TREES:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_trees, NULL, "Trees (t=%u, l=%u)", subtype, sublen);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trees_nof_trees_to_compute, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trees_maximum_nof_trees_to_compute, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_trees_nof_trees_to_use, tvb, offset+4, 2, ENC_BIG_ENDIAN);
return(0);
case TREE_IDENTIFIER:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_root_id, NULL, "Tree root identifiers (t=%u, l=%u)", subtype, sublen);
root_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_tree_root_id_starting_tree_no, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
while (sublen>=2) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(rt_tree, hf_isis_lsp_rt_capable_tree_root_id_nickname, tvb, offset, 2,
rt_block, "Nickname(%dth root): 0x%04x (%d)", root_id, rt_block, rt_block);
root_id++;
sublen -= 2;
offset += 2;
}
return(0);
case NICKNAME:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_nickname, NULL, "Nickname (t=%u, l=%u)", subtype, sublen);
while (sublen>=5) {
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_nickname_nickname_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_nickname_tree_root_priority, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_nickname_nickname, tvb, offset+3, 2, ENC_BIG_ENDIAN);
sublen -= 5;
offset += 5;
}
return(0);
case INTERESTED_VLANS:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_interested_vlans, NULL, "Interested VLANs and spanning tree roots (t=%u, l=%u)", subtype, sublen);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_nickname, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_multicast_ipv4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_multicast_ipv6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_vlan_start_id, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_vlan_end_id, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_interested_vlans_afs_lost_counter, tvb, offset, 4, ENC_BIG_ENDIAN);
sublen -= 4;
offset += 4;
while (sublen>=6) {
proto_tree_add_item(rt_tree, hf_isis_lsp_root_id, tvb, offset, 6, ENC_NA);
sublen -= 6;
offset += 6;
}
return(0);
case TREES_USED_IDENTIFIER:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_tree_used, NULL, "Trees used identifiers (t=%u, l=%u)", subtype, sublen);
root_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_tree_used_id_starting_tree_no, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
while (sublen>=2) {
rt_block = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(rt_tree, hf_isis_lsp_rt_capable_tree_used_id_nickname, tvb, offset,2,
rt_block, "Nickname(%dth root): 0x%04x (%d)", root_id, rt_block, rt_block);
root_id++;
offset += 2;
sublen -= 2;
}
return(0);
case VLAN_GROUP:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_vlan_group, NULL, "VLAN group (t=%u, l=%u)", subtype, sublen);
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_vlan_group_primary_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
sublen -= 2;
while (sublen>=2) {
proto_tree_add_item(rt_tree, hf_isis_lsp_rt_capable_vlan_group_secondary_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
sublen -= 2;
offset += 2;
}
return(0);
case SEGMENT_ROUTING_ALG:
rt_tree = proto_tree_add_subtree_format(tree, tvb, offset-2, sublen+2,
ett_isis_lsp_clv_sr_alg, NULL, "Segment Routing - Algorithms (t=%u, l=%u)",
subtype, sublen);
i = 0;
while (i < sublen) {
proto_tree_add_item(rt_tree, hf_isis_lsp_clv_sr_alg, tvb, offset+i, 1, ENC_NA);
i++;
}
return(0);
default:
return(-1);
}
}
static void
dissect_isis_rt_capable_clv(tvbuff_t *tvb, packet_info* pinfo _U_,
proto_tree *tree, int offset, int id_length _U_, int length)
{
guint8 subtype, subtlvlen;
proto_tree_add_item(tree, hf_isis_lsp_rt_capable_router_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
proto_tree_add_item(tree, hf_isis_lsp_rt_capable_flag_s, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isis_lsp_rt_capable_flag_d, tvb, offset, 1, ENC_BIG_ENDIAN);
length -= 1;
offset += 1;
while (length>=2) {
subtype = tvb_get_guint8(tvb, offset);
subtlvlen = tvb_get_guint8(tvb, offset+1);
length -= 2;
offset += 2;
if (subtlvlen > length) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset-2, -1,
"Short type %d TLV (%d vs %d)", subtype, subtlvlen, length);
return;
}
if (dissect_isis_trill_clv(tvb, pinfo, tree, offset, subtype, subtlvlen)==-1) {
proto_tree_add_expert_format( tree, pinfo, &ei_isis_lsp_subtlv, tvb, offset-2, subtlvlen+2,
"Unknown SubTlv: Type: %d, Length: %d", subtype, subtlvlen);
}
length -= subtlvlen;
offset += subtlvlen;
}
}
static void
dissect_lsp_ipv6_reachability_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_tree *subtree = NULL;
proto_tree *subtree2 = NULL;
guint8 ctrl_info;
guint bit_length;
int byte_length;
struct e_in6_addr prefix;
address prefix_addr;
guint len,i;
guint subclvs_len;
guint clv_code, clv_len;
if (!tree) return;
while (length > 0) {
ctrl_info = tvb_get_guint8(tvb, offset+4);
bit_length = tvb_get_guint8(tvb, offset+5);
byte_length = ipv6_addr_and_mask(tvb, offset+6, &prefix, bit_length);
if (byte_length == -1) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"IPv6 prefix has an invalid length: %d bits", bit_length );
return;
}
subclvs_len = 0;
if ((ctrl_info & 0x20) != 0)
subclvs_len = 1+tvb_get_guint8(tvb, offset+6+byte_length);
subtree = proto_tree_add_subtree(tree, tvb, offset, 6+byte_length+subclvs_len,
ett_isis_lsp_part_of_clv_ipv6_reachability, NULL, "IPv6 Reachability");
SET_ADDRESS(&prefix_addr, AT_IPv6, 16, prefix.bytes);
proto_tree_add_ipv6_format_value(subtree, hf_isis_lsp_ipv6_reachability_ipv6_prefix, tvb, offset+6, byte_length,
&prefix, "IPv6 prefix: %s/%u", address_to_str(wmem_packet_scope(), &prefix_addr), bit_length);
proto_tree_add_item(subtree, hf_isis_lsp_ipv6_reachability_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_ipv6_reachability_distribution, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_ipv6_reachability_distribution_internal, tvb, offset+4, 1, ENC_NA);
if ((ctrl_info & 0x1f) != 0) {
proto_tree_add_item(subtree, hf_isis_lsp_ipv6_reachability_reserved_bits, tvb, offset+4, 1, ENC_BIG_ENDIAN);
}
len = 6 + byte_length;
if ((ctrl_info & 0x20) != 0) {
subclvs_len = tvb_get_guint8(tvb, offset+len);
subtree2 = proto_tree_add_subtree_format(subtree, tvb, offset+len, subclvs_len+1,
ett_isis_lsp_clv_ip_reach_subclv, NULL, "sub-TLVs present, total length: %u bytes",
subclvs_len);
i =0;
while (i < subclvs_len) {
clv_code = tvb_get_guint8(tvb, offset+len+1);
clv_len = tvb_get_guint8(tvb, offset+len+2);
dissect_ipreach_subclv(tvb, subtree2, offset+len+3, clv_code, clv_len);
i += clv_len + 2;
}
len += 1 + subclvs_len;
} else {
proto_tree_add_uint_format(subtree, hf_isis_lsp_ext_ip_reachability_subclvs_len, tvb, offset, len, 0, "no sub-TLVs present");
}
offset += len;
length -= len;
}
}
static void
dissect_lsp_nlpid_clv(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_nlpid_clv(tvb, tree, hf_isis_lsp_clv_nlpid, offset, length);
}
static void
dissect_lsp_mt_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_mt_clv(tvb, pinfo, tree, offset, length, hf_isis_lsp_clv_mt, &ei_isis_lsp_clv_mt );
}
static void
dissect_lsp_hostname_clv(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_hostname_clv(tvb, tree, offset, length,
hf_isis_lsp_hostname);
}
static void
dissect_lsp_srlg_clv(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_tree_add_item(tree, hf_isis_lsp_srlg_system_id, tvb, offset, 6, ENC_BIG_ENDIAN);
offset += 6;
proto_tree_add_item(tree, hf_isis_lsp_srlg_pseudo_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isis_lsp_srlg_flags_numbered, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_isis_lsp_srlg_ipv4_local, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_isis_lsp_srlg_ipv4_remote, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 16;
while(length){
proto_tree_add_item(tree, hf_isis_lsp_srlg_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
}
}
static void
dissect_lsp_te_router_id_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_te_router_id_clv(tree, pinfo, tvb, &ei_isis_lsp_short_packet, offset, length,
hf_isis_lsp_clv_te_router_id );
}
static void
dissect_lsp_ip_int_addr_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ip_int_clv(tree, pinfo, tvb, &ei_isis_lsp_short_packet, offset, length,
hf_isis_lsp_clv_ipv4_int_addr );
}
static void
dissect_lsp_ipv6_int_addr_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ipv6_int_clv(tree, pinfo, tvb, &ei_isis_lsp_short_packet, offset, length,
hf_isis_lsp_clv_ipv6_int_addr );
}
static void
dissect_isis_lsp_clv_mt_cap_spb_instance(tvbuff_t *tvb, packet_info *pinfo,
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
static const int *lsp_cap_spb_instance_vlanid_tuple[] = {
&hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_u,
&hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_m,
&hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_a,
&hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_reserved,
NULL
};
if (sublen < FIXED_LEN) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short SPB Digest subTLV (%d vs %d)", sublen, FIXED_LEN);
return;
}
else {
proto_tree *subtree, *ti;
int subofs = offset;
const guint8 *cist_root_identifier = tvb_get_ptr (tvb, subofs + CIST_ROOT_ID_OFFSET, CIST_ROOT_ID_LEN);
guint8 num_trees = tvb_get_guint8(tvb, subofs + NUM_TREES_OFFSET);
subtree = proto_tree_add_subtree_format( tree, tvb, offset-2, sublen+2, ett_isis_lsp_clv_mt_cap_spb_instance, NULL,
"SPB Instance: Type: 0x%02x, Length: %d", subtype, sublen);
proto_tree_add_bytes_format_value( subtree, hf_isis_lsp_mt_cap_spb_instance_cist_root_identifier, tvb, subofs + CIST_ROOT_ID_OFFSET, CIST_ROOT_ID_LEN,
cist_root_identifier, "%08x-%08x-%08x-%08x-%08x-%08x-%08x-%08x",
cist_root_identifier[0], cist_root_identifier[1], cist_root_identifier[2],
cist_root_identifier[3], cist_root_identifier[4], cist_root_identifier[5],
cist_root_identifier[6], cist_root_identifier[7]);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_cist_external_root_path_cost, tvb, subofs + CIST_EXT_ROOT_PATH_COST_OFFSET, CIST_EXT_ROOT_PATH_COST_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_bridge_priority, tvb, subofs + BRIDGE_PRI_OFFSET, BRIDGE_PRI_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_v, tvb, subofs + V_SPSOURCEID_OFFSET, V_SPSOURCEID_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spsourceid, tvb, subofs + V_SPSOURCEID_OFFSET, V_SPSOURCEID_LEN, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_number_of_trees, tvb, subofs + NUM_TREES_OFFSET, NUM_TREES_LEN, ENC_BIG_ENDIAN);
if (num_trees == 0)
proto_item_append_text(ti, " Invalid subTLV: zero trees");
subofs += FIXED_LEN;
sublen -= FIXED_LEN;
if (sublen != (num_trees * VLAN_ID_TUPLE_LEN)) {
proto_tree_add_expert_format( subtree, pinfo, &ei_isis_lsp_short_packet, tvb, subofs, 0, "SubTLV length doesn't match number of trees");
return;
}
while (sublen > 0 && num_trees > 0) {
if (sublen < VLAN_ID_TUPLE_LEN) {
proto_tree_add_expert_format(subtree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short VLAN_ID entry (%d vs %d)", sublen, VLAN_ID_TUPLE_LEN);
return;
}
else {
proto_tree_add_bitmask_list(subtree, tvb, subofs, 1, lsp_cap_spb_instance_vlanid_tuple, ENC_BIG_ENDIAN);
subofs += 1;
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_ect, tvb, subofs, 4, ENC_BIG_ENDIAN);
subofs += 4;
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_base_vid, tvb, subofs, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_spvid, tvb, subofs, 3, ENC_BIG_ENDIAN);
subofs += 3;
sublen -= VLAN_ID_TUPLE_LEN;
--num_trees;
}
}
if (num_trees) {
proto_tree_add_expert_format(subtree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short subTLV (%d vs %d)", sublen, num_trees * VLAN_ID_TUPLE_LEN);
return;
}
}
}
static void
dissect_isis_lsp_clv_mt_cap_spb_oalg(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype _U_, int sublen _U_)
{
proto_tree_add_item(tree, hf_isis_lsp_mt_cap_spb_opaque_algorithm, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_isis_lsp_mt_cap_spb_opaque_information, tvb, offset, -1, ENC_NA);
}
static void
dissect_isis_lsp_clv_mt_cap_spbm_service_identifier(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int BMAC_LEN = 6;
const int BVID_LEN = 2;
const int BMAC_OFFSET = 0;
const int BVID_OFFSET = BMAC_OFFSET + BMAC_LEN;
const int FIXED_LEN = BVID_OFFSET + BVID_LEN;
const int ISID_LEN = 4;
static const int *lsp_cap_spbm_service_identifier[] = {
&hf_isis_lsp_mt_cap_spbm_service_identifier_t,
&hf_isis_lsp_mt_cap_spbm_service_identifier_r,
&hf_isis_lsp_mt_cap_spbm_service_identifier_reserved,
NULL
};
if (sublen < FIXED_LEN) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short SPBM Service Identifier and Unicast Address subTLV (%d vs %d)", sublen, FIXED_LEN);
return;
}
else {
proto_tree *subtree;
int subofs = offset;
subtree = proto_tree_add_subtree_format( tree, tvb, offset-2, sublen+2, ett_isis_lsp_clv_mt_cap_spbm_service_identifier, NULL,
"SPB Service ID and Unicast Address: Type: 0x%02x, Length: %d", subtype, sublen);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spbm_service_identifier_b_mac, tvb, subofs + BMAC_OFFSET, BMAC_LEN, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spbm_service_identifier_base_vid, tvb, subofs + BVID_OFFSET, BVID_LEN, ENC_BIG_ENDIAN);
subofs += FIXED_LEN;
sublen -= FIXED_LEN;
while (sublen > 0) {
if (sublen < ISID_LEN) {
proto_tree_add_expert_format(subtree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short ISID entry (%d vs %d)", sublen, 4);
return;
}
else {
proto_tree_add_bitmask_list(subtree, tvb, subofs, 1, lsp_cap_spbm_service_identifier, ENC_BIG_ENDIAN);
subofs += 1;
sublen -= 1;
proto_tree_add_item(subtree, hf_isis_lsp_mt_cap_spbm_service_identifier_i_sid, tvb, subofs, 3, ENC_BIG_ENDIAN);
subofs += 3;
sublen -= 3;
}
}
}
}
static void
dissect_isis_lsp_clv_mt_cap_spbv_mac_address(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, int subtype, int sublen)
{
static const int *lsp_spb_short_mac_address[] = {
&hf_isis_lsp_spb_short_mac_address_t,
&hf_isis_lsp_spb_short_mac_address_r,
&hf_isis_lsp_spb_short_mac_address_reserved,
NULL
};
if (sublen < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short SPBV Mac Address subTLV (%d vs %d)", sublen, 2);
return;
}
else {
proto_tree *subtree;
int subofs = offset;
subtree = proto_tree_add_subtree_format( tree, tvb, offset-2, sublen+2, ett_isis_lsp_clv_mt_cap_spbv_mac_address, NULL,
"SPBV Mac Address: Type: 0x%02x, Length: %d", subtype, sublen);
proto_tree_add_item(subtree, hf_isis_lsp_spb_reserved, tvb, subofs, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_sr_bit, tvb, subofs, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_spvid, tvb, subofs, 2, ENC_BIG_ENDIAN);
subofs += 2;
sublen -= 2;
while (sublen > 0) {
if (sublen < 7) {
proto_tree_add_expert_format(subtree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short MAC Address entry (%d vs %d)", sublen, 7);
return;
}
else {
proto_tree_add_bitmask_list(subtree, tvb, subofs, 1, lsp_spb_short_mac_address, ENC_BIG_ENDIAN);
subofs += 1;
sublen -= 1;
proto_tree_add_item(subtree, hf_isis_lsp_spb_short_mac_address, tvb, subofs, 6, ENC_NA);
subofs += 6;
sublen -= 6;
}
}
}
}
static void
dissect_isis_lsp_clv_mt_cap(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
if (length >= 2) {
proto_tree_add_item( tree, hf_isis_lsp_mt_cap_mtid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isis_lsp_mt_cap_overload, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
while (length >= 2) {
guint8 subtype = tvb_get_guint8(tvb, offset);
guint8 subtlvlen = tvb_get_guint8(tvb, offset+1);
length -= 2;
offset += 2;
if (subtlvlen > length) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset-2, -1,
"Short type %d TLV (%d vs %d)", subtype, subtlvlen, length);
return;
}
if (subtype == 0x01) {
dissect_isis_lsp_clv_mt_cap_spb_instance(tvb, pinfo, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x02) {
dissect_isis_lsp_clv_mt_cap_spb_oalg(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x03) {
dissect_isis_lsp_clv_mt_cap_spbm_service_identifier(tvb, pinfo, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x04) {
dissect_isis_lsp_clv_mt_cap_spbv_mac_address(tvb, pinfo, tree, offset, subtype, subtlvlen);
}
else if (dissect_isis_trill_clv(tvb, pinfo, tree, offset, subtype, subtlvlen)==-1) {
proto_tree_add_expert_format( tree, pinfo, &ei_isis_lsp_subtlv, tvb, offset-2, subtlvlen+2,
"Unknown SubTlv: Type: %d, Length: %d", subtype, subtlvlen);
}
length -= subtlvlen;
offset += subtlvlen;
}
}
}
static void
dissect_isis_lsp_clv_sid_label_binding(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
proto_item *ti_subclvs = NULL;
proto_tree *subtree = NULL;
int tlv_offset = 0;
int sub_tlv_len = 0;
int i = 0;
guint8 clv_pref_l = 0;
guint clv_code = 0;
guint clv_len = 0;
static const int *lsp_sl_flags[] = {
&hf_isis_lsp_sl_binding_flags_f,
&hf_isis_lsp_sl_binding_flags_m,
NULL
};
if ( length <= 0 ) {
return;
}
tlv_offset = offset;
proto_tree_add_bitmask(tree, tvb, tlv_offset,
hf_isis_lsp_sl_binding_flags, ett_isis_lsp_sl_flags, lsp_sl_flags, ENC_NA);
tlv_offset++;
proto_tree_add_item(tree, hf_isis_lsp_sl_binding_weight, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
tlv_offset++;
proto_tree_add_item(tree, hf_isis_lsp_sl_binding_range, tvb, tlv_offset, 2, ENC_BIG_ENDIAN);
tlv_offset = tlv_offset+2;
proto_tree_add_item(tree, hf_isis_lsp_sl_binding_prefix_length, tvb, tlv_offset, 1, ENC_BIG_ENDIAN);
clv_pref_l = tvb_get_guint8(tvb, tlv_offset);
tlv_offset++;
if (clv_pref_l == 32) {
proto_tree_add_item(tree, hf_isis_lsp_sl_binding_fec_prefix_ipv4, tvb, tlv_offset, clv_pref_l/8, ENC_NA);
}
else if (clv_pref_l == 128) {
proto_tree_add_item(tree, hf_isis_lsp_sl_binding_fec_prefix_ipv6, tvb, tlv_offset, clv_pref_l/8, ENC_NA);
}
else {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb, tlv_offset, -1,
"Prefix address format unknown length : %d",clv_pref_l);
}
tlv_offset = tlv_offset+(clv_pref_l/8);
sub_tlv_len = length - (5+clv_pref_l/8);
while (i < sub_tlv_len) {
clv_code = tvb_get_guint8(tvb, i+tlv_offset);
clv_len = tvb_get_guint8(tvb, i+1+tlv_offset);
ti_subclvs = proto_tree_add_item(tree, hf_isis_lsp_sl_sub_tlv, tvb, tlv_offset, clv_len+2, ENC_NA);
proto_item_append_text(ti_subclvs, " %s",
val_to_str(clv_code, isis_lsp_sl_sub_tlv_vals, "Unknown capability sub-tlv type"));
subtree = proto_item_add_subtree(ti_subclvs, ett_isis_lsp_sl_sub_tlv);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_type, tvb, i+tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_length, tvb, i+1+tlv_offset, 1, ENC_BIG_ENDIAN);
switch (clv_code) {
case ISIS_LSP_SL_SUB_SID_LAB :
switch (clv_len) {
case 3 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_label_20,
tvb, i+2+tlv_offset, clv_len, ENC_BIG_ENDIAN);
break;
case 4 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_label_32,
tvb, i+2+tlv_offset, clv_len, ENC_BIG_ENDIAN);
break;
default :
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb, i+2+tlv_offset, -1,
"Label badly formatted");
break;
}
break;
case ISIS_LSP_SL_SUB_ERO_MET :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_metric, tvb, i+2+tlv_offset, 4, ENC_BIG_ENDIAN);
break;
case ISIS_LSP_SL_SUB_IPV4_ERO :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_flag, tvb, i+2+tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_ipv4, tvb, i+3+tlv_offset, 4, ENC_NA);
break;
case ISIS_LSP_SL_SUB_IPV6_ERO :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_flag, tvb, i+2+tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_ipv6, tvb, i+3+tlv_offset, 16, ENC_NA);
break;
case ISIS_LSP_SL_SUB_UN_IF :
switch (clv_len) {
case 8 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_router_id32,
tvb, i+2+tlv_offset, 4, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_inter_id,
tvb, i+6+tlv_offset, 4, ENC_BIG_ENDIAN);
break;
case 20 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_router_id128,
tvb, i+2+tlv_offset, 16, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_inter_id,
tvb, i+2+16+tlv_offset, 4, ENC_BIG_ENDIAN);
break;
default :
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb, i+2+tlv_offset, -1,
"Router ID badly formatted");
break;
}
break;
case ISIS_LSP_SL_SUB_IPV4_B_ERO :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_flag, tvb, i+2+tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_ero_ipv4, tvb, i+3+tlv_offset, 4, ENC_NA);
break;
case ISIS_LSP_SL_SUB_IPV6_B_ERO :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_ero_flag, tvb, i+2+tlv_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_ero_ipv6, tvb, i+3+tlv_offset, 16, ENC_NA);
break;
case ISIS_LSP_SL_SUB_B_UN_IF :
switch (clv_len) {
case 8 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_router_id32,
tvb, i+2+tlv_offset, 4, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_inter_id,
tvb, i+6+tlv_offset, 4, ENC_BIG_ENDIAN);
break;
case 20 :
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_router_id128,
tvb, i+2+tlv_offset, 16, ENC_NA);
proto_tree_add_item(subtree, hf_isis_lsp_sl_sub_tlv_backup_inter_id,
tvb, i+2+16+tlv_offset, 4, ENC_BIG_ENDIAN);
break;
default :
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb, i+2+tlv_offset, -1,
"backup Router ID badly formatted");
break;
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb, i+2+tlv_offset, -1,
"Sub TLV badly formatted, type unknown %d", clv_code);
break;
}
i += clv_len + 2;
}
}
static void
dissect_lsp_authentication_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_authentication_clv(tree, pinfo, tvb, hf_isis_lsp_authentication, &ei_isis_lsp_authentication, offset, length);
}
static void
dissect_lsp_ip_authentication_clv(tvbuff_t *tvb, packet_info* pinfo _U_, proto_tree *tree, int offset,
int id_length _U_, int length)
{
if ( length != 0 ) {
proto_tree_add_item(tree, hf_isis_lsp_ip_authentication, tvb, offset, length, ENC_ASCII|ENC_NA);
}
}
static void
dissect_lsp_area_address_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_area_address_clv(tree, pinfo, tvb, &ei_isis_lsp_short_packet, hf_isis_lsp_area_address, offset, length);
}
static void
dissect_lsp_eis_neighbors_clv_inner(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int length, int id_length, int show_virtual, int is_eis)
{
proto_item *ti;
proto_tree *ntree = NULL;
int tlen;
if (!is_eis) {
id_length++;
if ( tree ) {
if ( show_virtual ) {
proto_tree_add_item( tree, hf_isis_lsp_is_virtual, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(tree, hf_isis_lsp_eis_neighbors_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
offset++;
length--;
}
tlen = 4 + id_length;
while ( length > 0 ) {
if (length<tlen) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short E/IS reachability (%d vs %d)", length, tlen );
return;
}
if ( tree ) {
if ( is_eis ) {
ntree = proto_tree_add_subtree(tree, tvb, offset, tlen, ett_isis_lsp_clv_is_neighbors, &ti, "ES Neighbor");
} else {
ntree = proto_tree_add_subtree(tree, tvb, offset, tlen, ett_isis_lsp_clv_is_neighbors, &ti, "IS Neighbor");
}
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_default_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_default_metric_ie, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_delay_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_delay_metric_supported, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_delay_metric_ie, tvb, offset+1, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_expense_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_expense_metric_supported, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_expense_metric_ie, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_error_metric, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_error_metric_supported, tvb, offset, 1, ENC_NA);
proto_tree_add_item(ntree, hf_isis_lsp_eis_neighbors_error_metric_ie, tvb, offset+3, 1, ENC_NA);
proto_tree_add_item(ntree, is_eis ? hf_isis_lsp_eis_neighbors_es_neighbor_id : hf_isis_lsp_eis_neighbors_is_neighbor_id,
tvb, offset+4, id_length, ENC_NA);
proto_item_append_text(ti, ": %s", tvb_print_system_id(tvb, offset+4, id_length));
}
offset += tlen;
length -= tlen;
}
}
static void
dissect_lsp_l1_is_neighbors_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, pinfo, tree, offset,
length, id_length, TRUE, FALSE);
}
static void
dissect_lsp_l1_es_neighbors_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, pinfo, tree, offset,
length, id_length, TRUE, TRUE);
}
static void
dissect_lsp_l2_is_neighbors_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length, int length)
{
dissect_lsp_eis_neighbors_clv_inner(tvb, pinfo, tree, offset,
length, id_length, FALSE, FALSE);
}
static void
dissect_subclv_admin_group (tvbuff_t *tvb, proto_tree *tree, int offset) {
proto_tree *ntree;
guint32 clv_value;
guint32 mask;
int i;
ntree = proto_tree_add_subtree(tree, tvb, offset-2, 6,
ett_isis_lsp_subclv_admin_group, NULL, "Administrative group(s):");
clv_value = tvb_get_ntohl(tvb, offset);
mask = 1;
for (i = 0 ; i < 32 ; i++) {
if ( (clv_value & mask) != 0 ) {
proto_tree_add_uint_format(ntree, hf_isis_lsp_group, tvb, offset, 4, clv_value & mask, "group %d", i);
}
mask <<= 1;
}
}
static void
dissect_subclv_max_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
gfloat bw;
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(tree, hf_isis_lsp_maximum_link_bandwidth, tvb, offset-2, 6,
bw, "%.2f Mbps", bw);
}
static void
dissect_subclv_rsv_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
gfloat bw;
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value (tree, hf_isis_lsp_reservable_link_bandwidth, tvb, offset-2, 6,
bw, "%.2f Mbps", bw );
}
static void
dissect_subclv_unrsv_bw(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *ntree;
gfloat bw;
int i;
ntree = proto_tree_add_subtree(tree, tvb, offset-2, 34,
ett_isis_lsp_subclv_unrsv_bw, NULL, "Unreserved bandwidth:");
for (i = 0 ; i < 8 ; i++) {
bw = tvb_get_ntohieee_float(tvb, offset+4*i)*8/1000000;
proto_tree_add_float_format(ntree, hf_isis_lsp_unrsv_bw_priority_level, tvb, offset+4*i, 4,
bw, "priority level %d: %.2f Mbps", i, bw );
}
}
static void
dissect_subclv_bw_ct(tvbuff_t *tvb, proto_tree *tree, int offset, int sublen)
{
proto_tree *ntree;
int offset_end = offset + sublen;
gfloat bw;
ntree = proto_tree_add_subtree(tree, tvb, offset-2, sublen,
ett_isis_lsp_subclv_bw_ct, NULL, "Bandwidth Constraints:");
proto_tree_add_item(ntree, hf_isis_lsp_bw_ct_model, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(ntree, hf_isis_lsp_bw_ct_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
offset +=3;
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct0, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct1, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct2, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct3, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct4, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct5, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct6, tvb, offset, 4,
bw, "%.2f Mbps", bw);
offset += 4;
}
if(offset < offset_end){
bw = tvb_get_ntohieee_float(tvb, offset)*8/1000000;
proto_tree_add_float_format_value(ntree, hf_isis_lsp_bw_ct7, tvb, offset, 4,
bw, "%.2f Mbps", bw);
}
}
static void
dissect_subclv_spb_link_metric(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int SUBLEN = 6;
if (sublen != SUBLEN) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short SPB Link Metric sub-TLV (%d vs %d)", sublen, SUBLEN);
return;
}
else {
proto_tree *subtree;
subtree = proto_tree_add_subtree_format( tree, tvb, offset-2, sublen+2, ett_isis_lsp_subclv_spb_link_metric, NULL,
"SPB Link Metric: Type: 0x%02x (%d), Length: %d", subtype, subtype, sublen);
proto_tree_add_item(subtree, hf_isis_lsp_spb_link_metric,
tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_port_count,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_spb_port_id,
tvb, offset+4, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_subclv_adj_sid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int local_offset, int subtype, int sublen)
{
int offset = local_offset;
proto_item *ti;
int sli_len;
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_isis_lsp_adj_sid_flags,
ett_isis_lsp_adj_sid_flags, adj_sid_flags, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_isis_lsp_adj_sid_weight, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (subtype == 32) {
proto_tree_add_item(tree, hf_isis_lsp_adj_sid_system_id, tvb, offset, 6, ENC_NA);
offset += 6;
}
sli_len = local_offset + sublen - offset;
switch(sli_len) {
case 3:
if (!((flags & 0x30) == 0x30))
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb,
local_offset, sublen, "V & L flags must be set");
proto_tree_add_item(tree, hf_isis_lsp_sid_sli_label, tvb, offset, sli_len, ENC_BIG_ENDIAN);
break;
case 4:
if (flags & 0x30)
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb,
local_offset, sublen, "V & L flags must be unset");
proto_tree_add_item(tree, hf_isis_lsp_sid_sli_index, tvb, offset, sli_len, ENC_BIG_ENDIAN);
break;
case 16:
if (!(flags & 0x20))
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_malformed_subtlv, tvb,
local_offset, sublen, "V flag must be set");
ti = proto_tree_add_item(tree, hf_isis_lsp_sid_sli_ipv6, tvb, offset, sli_len, ENC_NA);
if (flags & 0x10)
proto_item_append_text(ti, "Globally unique");
break;
default:
break;
}
}
static void
dissect_sub_clv_tlv_22_22_23_141_222_223(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree,
int offset, int subclvs_len)
{
proto_item *ti_subclvs = NULL;
proto_tree *subtree = NULL;
int sub_tlv_offset = 0;
int i = 0;
guint clv_code, clv_len;
sub_tlv_offset = offset;
while (i < subclvs_len) {
subtree = proto_tree_add_subtree(tree, tvb, sub_tlv_offset+11+i, 0,
ett_isis_lsp_part_of_clv_ext_is_reachability_subtlv,
&ti_subclvs, "subTLV");
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_code,
tvb, sub_tlv_offset+11+i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_len, tvb, sub_tlv_offset+12+i, 1, ENC_BIG_ENDIAN);
clv_code = tvb_get_guint8(tvb, sub_tlv_offset+11+i);
clv_len = tvb_get_guint8(tvb, sub_tlv_offset+12+i);
proto_item_append_text(ti_subclvs, ": %s (c=%u, l=%u)", val_to_str(clv_code, isis_lsp_ext_is_reachability_code_vals, "Unknown"), clv_code, clv_len);
proto_item_set_len(ti_subclvs, clv_len+2);
switch (clv_code) {
case 3 :
dissect_subclv_admin_group(tvb, subtree, sub_tlv_offset+13+i);
break;
case 4 :
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_link_local_identifier,
tvb, sub_tlv_offset+13+i, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_link_remote_identifier,
tvb, sub_tlv_offset+17+i, 4, ENC_BIG_ENDIAN);
break;
case 6 :
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_ipv4_interface_address, tvb, sub_tlv_offset+13+i, 4, ENC_BIG_ENDIAN);
break;
case 8 :
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_ipv4_neighbor_address, tvb, sub_tlv_offset+13+i, 4, ENC_BIG_ENDIAN);
break;
case 9 :
dissect_subclv_max_bw(tvb, subtree, sub_tlv_offset+13+i);
break;
case 10:
dissect_subclv_rsv_bw(tvb, subtree, sub_tlv_offset+13+i);
break;
case 11:
dissect_subclv_unrsv_bw(tvb, subtree, sub_tlv_offset+13+i);
break;
case 18:
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_traffic_engineering_default_metric,
tvb, sub_tlv_offset+13+i, 3, ENC_BIG_ENDIAN);
break;
case 22:
dissect_subclv_bw_ct(tvb, subtree, sub_tlv_offset+13+i, clv_len);
break;
case 29:
dissect_subclv_spb_link_metric(tvb, pinfo, subtree,
sub_tlv_offset+13+i, clv_code, clv_len);
break;
case 31:
case 32:
dissect_subclv_adj_sid(tvb, pinfo, subtree, sub_tlv_offset+13+i, clv_code, clv_len);
break;
default:
proto_tree_add_item(subtree, hf_isis_lsp_ext_is_reachability_value, tvb, sub_tlv_offset+13+i, clv_len, ENC_NA);
break;
}
i += clv_len + 2;
}
}
static void
dissect_lsp_ext_is_reachability_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree,
int offset, int id_length _U_, int length)
{
proto_item *ti, *ti_subclvs_len;
proto_tree *ntree = NULL;
guint subclvs_len;
guint len;
while (length > 0) {
ntree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_isis_lsp_part_of_clv_ext_is_reachability, &ti, "IS Neighbor");
proto_tree_add_item(ntree, hf_isis_lsp_ext_is_reachability_is_neighbor_id, tvb, offset, 7, ENC_NA);
proto_item_append_text(ti, ": %s", tvb_print_system_id(tvb, offset, 7));
proto_tree_add_item(ntree, hf_isis_lsp_ext_is_reachability_metric, tvb, offset+7, 3, ENC_BIG_ENDIAN);
ti_subclvs_len = proto_tree_add_item(ntree, hf_isis_lsp_ext_is_reachability_subclvs_len, tvb, offset+10, 1, ENC_BIG_ENDIAN);
subclvs_len = tvb_get_guint8(tvb, offset+10);
if (subclvs_len == 0) {
proto_item_append_text(ti_subclvs_len, " (no sub-TLVs present)");
}
else {
dissect_sub_clv_tlv_22_22_23_141_222_223(tvb, pinfo, ntree,
offset, subclvs_len);
}
len = 11 + subclvs_len;
proto_item_set_len (ti, len);
offset += len;
length -= len;
}
}
static void
dissect_lsp_mt_reachable_IPv4_prefx_clv(tvbuff_t *tvb, packet_info* pinfo,
proto_tree *tree, int offset, int id_length _U_, int length)
{
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short lsp multi-topology reachable IPv4 prefixes(%d vs %d)", length, 2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ext_ip_reachability_clv(tvb, pinfo, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_mt_reachable_IPv6_prefx_clv(tvbuff_t *tvb, packet_info* pinfo,
proto_tree *tree, int offset, int id_length _U_, int length)
{
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short lsp multi-topology reachable IPv6 prefixes(%d vs %d)", length, 2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ipv6_reachability_clv(tvb, pinfo, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_mt_is_reachability_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
if (length < 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short lsp reachability(%d vs %d)", length, 2 );
return;
}
dissect_lsp_mt_id(tvb, tree, offset);
dissect_lsp_ext_is_reachability_clv(tvb, pinfo, tree, offset+2, 0, length-2);
}
static void
dissect_lsp_ori_buffersize_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length, int length)
{
if ( length != 2 ) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short lsp partition DIS(%d vs %d)", length, id_length );
return;
}
proto_tree_add_item(tree, hf_isis_lsp_originating_lsp_buffer_size, tvb, offset, length, ENC_BIG_ENDIAN);
}
static void
dissect_lsp_partition_dis_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length, int length)
{
if ( length < id_length ) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"short lsp partition DIS(%d vs %d)", length, id_length );
return;
}
proto_tree_add_item( tree, hf_isis_lsp_partition_designated_l2_is, tvb, offset, id_length, ENC_NA);
length -= id_length;
offset += id_length;
if ( length > 0 ) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_long_packet, tvb, offset, -1,
"Long lsp partition DIS, %d left over", length );
return;
}
}
static void
dissect_lsp_prefix_neighbors_clv(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
int id_length _U_, int length)
{
char *sbuf;
int mylen;
if ( length < 4 ) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Short lsp prefix neighbors (%d vs 4)", length );
return;
}
if ( tree ) {
dissect_metric (tvb, pinfo, tree, offset,
tvb_get_guint8(tvb, offset), hf_isis_lsp_default, hf_isis_lsp_default_support, TRUE );
dissect_metric (tvb, pinfo, tree, offset+1,
tvb_get_guint8(tvb, offset+1), hf_isis_lsp_delay, hf_isis_lsp_delay_support, FALSE );
dissect_metric (tvb, pinfo, tree, offset+2,
tvb_get_guint8(tvb, offset+2), hf_isis_lsp_expense, hf_isis_lsp_expense_support, FALSE );
dissect_metric (tvb, pinfo, tree, offset+3,
tvb_get_guint8(tvb, offset+3), hf_isis_lsp_error, hf_isis_lsp_error_support, FALSE );
}
offset += 4;
length -= 4;
while ( length > 0 ) {
mylen = tvb_get_guint8(tvb, offset);
length--;
if (length<=0) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_short_packet, tvb, offset, -1,
"Zero payload space after length in prefix neighbor" );
return;
}
if ( mylen > length) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_long_packet, tvb, offset, -1,
"Integral length of prefix neighbor too long (%d vs %d)", mylen, length );
return;
}
sbuf = print_area( tvb, offset+1, mylen );
proto_tree_add_string( tree, hf_isis_lsp_area_address_str, tvb, offset, mylen + 1, sbuf);
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
static void
dissect_isis_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
const isis_clv_handle_t *opts, int header_length, int id_length)
{
proto_item *ti;
proto_tree *lsp_tree, *info_tree;
guint16 pdu_length, lifetime, checksum, cacl_checksum=0;
guint8 lsp_info;
int len, offset_checksum;
proto_item *it_cksum;
char* system_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISIS LSP");
ti = proto_tree_add_item(tree, proto_isis_lsp, tvb, offset, -1, ENC_NA);
lsp_tree = proto_item_add_subtree(ti, ett_isis_lsp);
pdu_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(lsp_tree, hf_isis_lsp_pdu_length, tvb,
offset, 2, pdu_length);
offset += 2;
proto_tree_add_item(lsp_tree, hf_isis_lsp_remaining_life,
tvb, offset, 2, ENC_BIG_ENDIAN);
lifetime = tvb_get_ntohs(tvb, offset);
offset += 2;
offset_checksum = offset;
proto_tree_add_item(lsp_tree, hf_isis_lsp_lsp_id, tvb, offset, id_length + 2, ENC_NA);
system_id = tvb_print_system_id( tvb, offset, id_length+2 );
col_append_fstr(pinfo->cinfo, COL_INFO, ", LSP-ID: %s", system_id);
offset += (id_length + 2);
proto_tree_add_item(lsp_tree, hf_isis_lsp_sequence_number,
tvb, offset, 4, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Sequence: 0x%08x, Lifetime: %5us",
tvb_get_ntohl(tvb, offset),
tvb_get_ntohs(tvb, offset - (id_length+2+2)));
offset += 4;
checksum = lifetime ? tvb_get_ntohs(tvb, offset) : 0;
switch (check_and_get_checksum(tvb, offset_checksum, pdu_length-12, checksum, offset, &cacl_checksum)) {
case NO_CKSUM :
checksum = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(lsp_tree, hf_isis_lsp_checksum, tvb, offset, 2, checksum,
"0x%04x [unused]", checksum);
break;
case DATA_MISSING :
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_long_packet, tvb, offset, -1,
"Packet length %d went beyond packet",
tvb_reported_length_remaining(tvb, offset_checksum));
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
}
offset += 2;
if (tree) {
static const int * attach_flags[] = {
&hf_isis_lsp_error_metric,
&hf_isis_lsp_expense_metric,
&hf_isis_lsp_delay_metric,
&hf_isis_lsp_default_metric,
NULL
};
lsp_info = tvb_get_guint8(tvb, offset);
info_tree = proto_tree_add_subtree_format(lsp_tree, tvb, offset, 1, ett_isis_lsp_info, NULL,
"Type block(0x%02x): Partition Repair:%d, Attached bits:%d, Overload bit:%d, IS type:%d",
lsp_info,
ISIS_LSP_PARTITION(lsp_info),
ISIS_LSP_ATT(lsp_info),
ISIS_LSP_HIPPITY(lsp_info),
ISIS_LSP_IS_TYPE(lsp_info)
);
proto_tree_add_boolean(info_tree, hf_isis_lsp_p, tvb, offset, 1, lsp_info);
proto_tree_add_bitmask_with_flags(info_tree, tvb, offset, hf_isis_lsp_att,
ett_isis_lsp_att, attach_flags, ENC_NA, BMT_NO_APPEND);
proto_tree_add_boolean(info_tree, hf_isis_lsp_hippity, tvb, offset, 1, lsp_info);
proto_tree_add_uint(info_tree, hf_isis_lsp_is_type, tvb, offset, 1, lsp_info);
}
offset += 1;
len = pdu_length - header_length;
if (len < 0) {
proto_tree_add_expert_format(tree, pinfo, &ei_isis_lsp_long_packet, tvb, offset, -1,
"packet header length %d went beyond packet",
header_length );
return;
}
isis_dissect_clvs(tvb, pinfo, lsp_tree, offset,
opts, &ei_isis_lsp_short_packet, len, id_length, ett_isis_lsp_clv_unknown, hf_isis_lsp_clv_type, hf_isis_lsp_clv_length );
}
static int
dissect_isis_l1_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
isis_data_t* isis = (isis_data_t*)data;
dissect_isis_lsp(tvb, pinfo, tree, 0,
clv_l1_lsp_opts, isis->header_length, isis->system_id_len);
return tvb_reported_length(tvb);
}
static int
dissect_isis_l2_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
isis_data_t* isis = (isis_data_t*)data;
dissect_isis_lsp(tvb, pinfo, tree, 0,
clv_l2_lsp_opts, isis->header_length, isis->system_id_len);
return tvb_reported_length(tvb);
}
void
proto_register_isis_lsp(void)
{
static hf_register_info hf[] = {
{ &hf_isis_lsp_pdu_length,
{ "PDU length", "isis.lsp.pdu_length",
FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_isis_lsp_remaining_life,
{ "Remaining lifetime", "isis.lsp.remaining_life",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_lsp_id,
{ "LSP-ID", "isis.lsp.lsp_id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_hostname,
{ "Hostname", "isis.lsp.hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_system_id,
{ "System ID", "isis.lsp.srlg.system_id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_pseudo_num,
{ "Pseudonode num", "isis.lsp.srlg.pseudo_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_flags_numbered,
{ "Numbered", "isis.lsp.srlg.flags_numbered",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_ipv4_local,
{ "IPv4 interface address/Link Local Identifier", "isis.lsp.srlg.ipv4_local",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_ipv4_remote,
{ "IPv4 neighbor address/Link remote Identifier", "isis.lsp.srlg.ipv4_remote",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_srlg_value,
{ "Shared Risk Link Group Value", "isis.lsp.srlg.value",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_sequence_number,
{ "Sequence number", "isis.lsp.sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_checksum,
{ "Checksum", "isis.lsp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_checksum_good,
{ "Good Checksum", "isis.lsp.checksum_good",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Good IS-IS LSP Checksum", HFILL }
},
{ &hf_isis_lsp_checksum_bad,
{ "Bad Checksum", "isis.lsp.checksum_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Bad IS-IS LSP Checksum", HFILL }
},
{ &hf_isis_lsp_clv_ipv4_int_addr,
{ "IPv4 interface address", "isis.lsp.clv_ipv4_int_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_ipv6_int_addr,
{ "IPv6 interface address", "isis.lsp.clv_ipv6_int_addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_router_id,
{ "Traffic Engineering Router ID", "isis.lsp.clv_te_router_id",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_mt,
{ "MT-ID", "isis.lsp.clv_mt",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_p,
{ "Partition Repair", "isis.lsp.partition_repair",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), ISIS_LSP_PARTITION_MASK,
"If set, this router supports the optional Partition Repair function", HFILL }
},
{ &hf_isis_lsp_att,
{ "Attachment", "isis.lsp.att",
FT_UINT8, BASE_DEC, NULL, ISIS_LSP_ATT_MASK,
NULL, HFILL }
},
{ &hf_isis_lsp_hippity,
{ "Overload bit", "isis.lsp.overload",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), ISIS_LSP_HIPPITY_MASK,
"If set, this router will not be used by any decision process to calculate routes", HFILL }
},
{ &hf_isis_lsp_root_id,
{ "Root Bridge ID", "isis.lsp.root.id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_is_type,
{ "Type of Intermediate System", "isis.lsp.is_type",
FT_UINT8, BASE_DEC, VALS(isis_lsp_istype_vals), ISIS_LSP_IS_TYPE_MASK,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_type,
{ "Type", "isis.lsp.clv.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_length,
{ "Length", "isis.lsp.clv.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct_model,
{ "Bandwidth Constraints Model Id", "isis.lsp.bw_ct.model",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct_reserved,
{ "Reserved", "isis.lsp.bw_ct.rsv",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct0,
{ "Bandwidth Constraints 0", "isis.lsp.bw_ct.0",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct1,
{ "Bandwidth Constraints 1", "isis.lsp.bw_ct.1",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct2,
{ "Bandwidth Constraints 2", "isis.lsp.bw_ct.2",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct3,
{ "Bandwidth Constraints 3", "isis.lsp.bw_ct.3",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct4,
{ "Bandwidth Constraints 4", "isis.lsp.bw_ct.4",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct5,
{ "Bandwidth Constraints 5", "isis.lsp.bw_ct.5",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct6,
{ "Bandwidth Constraints 6", "isis.lsp.bw_ct.6",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_bw_ct7,
{ "Bandwidth Constraints 7", "isis.lsp.bw_ct.7",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_link_metric,
{ "SPB Link Metric", "isis.lsp.spb.link_metric",
FT_UINT24, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_port_count,
{ "Number of Ports", "isis.lsp.spb.port_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_port_id,
{ "Port Id", "isis.lsp.spb.port_id",
FT_UINT16, BASE_HEX_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_flags,
{ "Flags", "isis.lsp.adj_sid.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_family_flag,
{ "Outgoing Encapsulation", "isis.lsp.adj_sid.flags.f",
FT_BOOLEAN, 8, TFS(&tfs_ipv6_ipv4), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_backup_flag,
{ "Backup", "isis.lsp.adj_sid.flags.b",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_value_flag,
{ "Value", "isis.lsp.adj_sid.flags.v",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_local_flag,
{ "Local Significance", "isis.lsp.adj_sid.flags.l",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_set_flag,
{ "Set", "isis.lsp.adj_sid.flags.s",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x8,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_weight,
{ "Weight", "isis.lsp.adj_sid.weight",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_adj_sid_system_id,
{ "System-ID", "isis.lsp.adj_sid.system_id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_sid_sli_label,
{ "SID/Label/Index", "isis.lsp.sid.sli_label",
FT_UINT24, BASE_DEC, NULL, 0xFFFFF,
NULL, HFILL }
},
{ &hf_isis_lsp_sid_sli_index,
{ "SID/Label/Index", "isis.lsp.sid.sli_index",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_sid_sli_ipv6,
{ "SID/Label/Index", "isis.lsp.sid.sli_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_reserved,
{ "SR Bit", "isis.lsp.spb.reserved",
FT_UINT16, BASE_DEC, NULL, 0xC000,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_sr_bit,
{ "SR Bit", "isis.lsp.spb.sr_bit",
FT_UINT16, BASE_DEC, NULL, 0x3000,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_spvid,
{ "SPVID", "isis.lsp.spb.spvid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_short_mac_address_t,
{ "T", "isis.lsp.spb.mac_address.t",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_short_mac_address_r,
{ "R", "isis.lsp.spb.mac_address.r",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_short_mac_address_reserved,
{ "Reserved", "isis.lsp.spb.mac_address.reserved",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_spb_short_mac_address,
{ "MAC Address", "isis.lsp.spb.mac_address",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_isis_lsp_sl_binding_flags,
{ "TLV Flags", "isis.lsp.sl_binding.flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_isis_lsp_sl_binding_flags_f,
{ "Flag F", "isis.lsp.sl_binding.flags_f",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_flags_m,
{ "Flag M", "isis.lsp.sl_binding.flags_m",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_weight,
{ "Weight", "isis.lsp.sl_binding.weight",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_range,
{ "Range", "isis.lsp.sl_binding.range",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_prefix_length,
{ "Prefix length", "isis.lsp.sl_binding.prefix_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_fec_prefix_ipv4,
{ "Prefix", "isis.lsp.sl_binding.prefix_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_binding_fec_prefix_ipv6,
{ "Prefix", "isis.lsp.sl_binding.prefix_ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv,
{ "SID/Label sub-TLV :", "isis.lsp.sl_binding.subtlv",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_type,
{ "SID/label sub-TLV type", "isis.lsp.sl_sub_tlv_type",
FT_UINT8, BASE_DEC, VALS(isis_lsp_sl_sub_tlv_vals), 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_length,
{ "Sub-TLV length", "isis.lsp.sl_binding.sub_tlv_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_label_20,
{ "SID/Label", "isis.lsp.sl_sub_tlv.label20",
FT_UINT24, BASE_DEC, NULL, 0x0FFFFF,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_label_32,
{ "SID/Label", "isis.lsp.sl_sub_tlv.label32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_metric,
{ "Metric", "isis.lsp.sl_sub_tlv.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_ero_flag,
{ "L bit", "isis.lsp.sl_sub_tlv.ero_flag_l",
FT_BOOLEAN, 8, TFS(&tfs_isis_tlv_sl_sub_tlv_f), ISIS_TLV_SL_SUB_TLV_L_BIT,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_ero_ipv4,
{ "ERO IPv4", "isis.lsp.sl_sub_tlv.ero_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_ero_ipv6,
{ "ERO IPv6", "isis.lsp.sl_sub_tlv.ero_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_router_id32,
{ "Router ID", "isis.lsp.sl_sub_tlv.router_id32",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_router_id128,
{ "Router ID", "isis.lsp.sl_sub_tlv.router_id128",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_inter_id,
{ "Interface ID", "isis.lsp.sl_sub_tlv.interface_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_backup_ero_ipv4,
{ "Backup ERO IPv4", "isis.lsp.sl_sub_tlv.backup_ero_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_backup_ero_ipv6,
{ "Backup ERO IPv6", "isis.lsp.sl_sub_tlv.backup_ero_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_backup_router_id32,
{ "Backup Router ID", "isis.lsp.sl_sub_tlv.backup_router_id32",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_backup_router_id128,
{ "Backup Router ID", "isis.lsp.sl_sub_tlv.backup_router_id128",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_sl_sub_tlv_backup_inter_id,
{ "Backup Interface ID", "isis.lsp.sl_sub_tlv.backup_interface_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_isis_lsp_mt_id_reserved,
{ "Reserved", "isis.lsp.reserved",
FT_UINT16, BASE_HEX, NULL, ISIS_LSP_MT_MSHIP_RES_MASK,
NULL, HFILL}
},
{ &hf_isis_lsp_mt_id,
{ "Topology ID", "isis.lsp.mtid",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(mtid_strings), 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_ipv4_prefix,
{ "IPv4 prefix", "isis.lsp.ip_reachability.ipv4_prefix",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_default_metric,
{ "Default Metric", "isis.lsp.ip_reachability.default_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_delay_metric,
{ "Delay Metric", "isis.lsp.ip_reachability.delay_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_expense_metric,
{ "Expense Metric", "isis.lsp.ip_reachability.expense_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_error_metric,
{ "Error Metric", "isis.lsp.ip_reachability.error_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_subclvs_len,
{ "SubCLV Length", "isis.lsp.ext_ip_reachability.subclvs_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_code,
{ "Code", "isis.lsp.ext_ip_reachability.code",
FT_UINT8, BASE_DEC, VALS(isis_lsp_ext_ip_reachability_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_len,
{ "Length", "isis.lsp.ext_ip_reachability.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_flags,
{ "Flags", "isis.lsp.ext_ip_reachability.prefix_sid.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_re_adv_flag,
{ "Re-advertisement", "isis.lsp.ext_ip_reachability.prefix_sid.flags.r",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_node_sid_flag,
{ "Node-SID", "isis.lsp.ext_ip_reachability.prefix_sid.flags.n",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_nophp_flag,
{ "no-PHP", "isis.lsp.ext_ip_reachability.prefix_sid.flags.p",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_expl_null_flag,
{ "Explicit-Null", "isis.lsp.ext_ip_reachability.prefix_sid.flags.e",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x10,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_value_flag,
{ "Value", "isis.lsp.ext_ip_reachability.prefix_sid.flags.v",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x8,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_prefix_local_flag,
{ "Local", "isis.lsp.ext_ip_reachability.prefix_sid.flags.l",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x4,
NULL, HFILL }
},
{ &hf_isis_lsp_32_bit_administrative_tag,
{ "32-Bit Administrative tag", "isis.lsp.32_bit_administrative_tag",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_64_bit_administrative_tag,
{ "64-Bit Administrative tag", "isis.lsp.64_bit_administrative_tag",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_ipv4_prefix,
{ "IPv4 prefix", "isis.lsp.ext_ip_reachability.ipv4_prefix",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_metric,
{ "Metric", "isis.lsp.ext_ip_reachability.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_ip_reachability_distribution,
{ "Distribution", "isis.lsp.ext_ip_reachability.distribution",
FT_BOOLEAN, 8, TFS(&tfs_up_down), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_length,
{ "Length", "isis.lsp.grp_macaddr.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_topology_id,
{ "Topology ID", "isis.lsp.grp_macaddr.mtid",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(mtid_strings), 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_vlan_id,
{ "VLAN ID", "isis.lsp.grp_macaddr.vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_number_of_records,
{ "Number of records", "isis.lsp.grp_macaddr.number_of_records",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_number_of_sources,
{ "Number of sources", "isis.lsp.grp_macaddr.number_of_sources",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_group_address,
{ "Group Address", "isis.lsp.grp_macaddr.group_address",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_macaddr_source_address,
{ "Source Address", "isis.lsp.grp_macaddr.source_address",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_length,
{ "Length", "isis.lsp.grp_ipv4addr.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_topology_id,
{ "Topology ID", "isis.lsp.grp_ipv4addr.mtid",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(mtid_strings), 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_vlan_id,
{ "VLAN ID", "isis.lsp.grp_ipv4addr.vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_number_of_records,
{ "Number of records", "isis.lsp.grp_ipv4addr.number_of_records",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_number_of_sources,
{ "Number of sources", "isis.lsp.grp_ipv4addr.number_of_sources",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_group_address,
{ "Group Address", "isis.lsp.grp_ipv4addr.group_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv4addr_source_address,
{ "Source Address", "isis.lsp.grp_ipv4addr.source_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_length,
{ "Length", "isis.lsp.grp_ipv6addr.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_topology_id,
{ "Topology ID", "isis.lsp.grp_ipv6addr.mtid",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(mtid_strings), 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_vlan_id,
{ "VLAN ID", "isis.lsp.grp_ipv6addr.vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_number_of_records,
{ "Number of records", "isis.lsp.grp_ipv6addr.number_of_records",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_number_of_sources,
{ "Number of sources", "isis.lsp.grp_ipv6addr.number_of_sources",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_group_address,
{ "Group Address", "isis.lsp.grp_ipv6addr.group_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_grp_ipv6addr_source_address,
{ "Source Address", "isis.lsp.grp_ipv6addr.source_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trill_affinity_tlv,
{ "Affinity Sub-TLV", "isis.lsp.rt_capable.trill.affinity_tlv",
FT_BOOLEAN, 32 , TFS(&tfs_supported_not_supported), 0x80000000,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trill_fgl_safe,
{ "FGL-safe", "isis.lsp.rt_capable.trill.fgl_safe",
FT_BOOLEAN, 32 , TFS(&tfs_yes_no), 0x40000000,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trill_caps,
{ "Other Capabilities", "isis.lsp.rt_capable.trill.caps",
FT_BOOLEAN, 32 , TFS(&tfs_supported_not_supported), 0x3ffc0000,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trill_flags,
{ "Extended Header Flags", "isis.lsp.rt_capable.trill.flags",
FT_BOOLEAN, 32 , TFS(&tfs_supported_not_supported), 0x0003ffff,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trill_maximum_version,
{ "Maximum version", "isis.lsp.rt_capable.trill.maximum_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trees_nof_trees_to_compute,
{ "Nof. trees to compute", "isis.lsp.rt_capable.trees.nof_trees_to_compute",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trees_maximum_nof_trees_to_compute,
{ "Maximum nof. trees to compute", "isis.lsp.rt_capable.trees.maximum_nof_trees_to_compute",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_trees_nof_trees_to_use,
{ "Nof. trees to use", "isis.lsp.rt_capable.trees.nof_trees_to_use",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_tree_root_id_starting_tree_no,
{ "Starting tree no", "isis.lsp.rt_capable.tree_root_id.starting_tree_no",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_tree_root_id_nickname,
{ "Nickname", "isis.lsp.rt_capable.tree_root_id.nickname",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_nickname_nickname_priority,
{ "Nickname priority", "isis.lsp.rt_capable.nickname.nickname_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_nickname_tree_root_priority,
{ "Tree root priority", "isis.lsp.rt_capable.nickname.tree_root_priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_nickname_nickname,
{ "Nickname", "isis.lsp.rt_capable.nickname.nickname",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_nickname,
{ "Nickname", "isis.lsp.rt_capable.interested_vlans.nickname",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_multicast_ipv4,
{ "IPv4 multicast router", "isis.lsp.rt_capable.interested_vlans.multicast_ipv4",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x8000,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_multicast_ipv6,
{ "IPv6 multicast router", "isis.lsp.rt_capable.interested_vlans.multicast_ipv6",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x4000,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_vlan_start_id,
{ "Vlan start id", "isis.lsp.rt_capable.interested_vlans.vlan_start_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_vlan_end_id,
{ "Vlan end id", "isis.lsp.rt_capable.interested_vlans.vlan_end_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_interested_vlans_afs_lost_counter,
{ "Appointed forward state lost counter", "isis.lsp.rt_capable.interested_vlans.afs_lost_counter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_tree_used_id_starting_tree_no,
{ "Starting tree no", "isis.lsp.rt_capable.tree_used_id.starting_tree_no",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_tree_used_id_nickname,
{ "Nickname", "isis.lsp.rt_capable.tree_used_id.nickname",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_vlan_group_primary_vlan_id,
{ "Primary vlan id", "isis.lsp.rt_capable.vlan_group.primary_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_vlan_group_secondary_vlan_id,
{ "Secondary vlan id", "isis.lsp.rt_capable.vlan_group.secondary_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_ipv6_reachability_ipv6_prefix,
{ "IPv6 prefix", "isis.lsp.ipv6_reachability.ipv6_prefix",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ipv6_reachability_metric,
{ "Metric", "isis.lsp.ipv6_reachability.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ipv6_reachability_distribution,
{ "Distribution", "isis.lsp.ipv6_reachability.distribution",
FT_BOOLEAN, 8, TFS(&tfs_up_down), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_ipv6_reachability_distribution_internal,
{ "Distribution", "isis.lsp.ipv6_reachability.distribution_internal",
FT_BOOLEAN, 8, TFS(&tfs_internal_external), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_ipv6_reachability_reserved_bits,
{ "Reserved bits", "isis.lsp.ipv6_reachability.reserved_bits",
FT_UINT8, BASE_HEX, NULL, 0x1F,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_cist_root_identifier,
{ "CIST Root Identifier", "isis.lsp.mt_cap_spb_instance.cist_root_identifier",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_cist_external_root_path_cost,
{ "CIST External Root Path Cost", "isis.lsp.mt_cap_spb_instance.cist_external_root_path_cost",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_bridge_priority,
{ "Bridge Priority", "isis.lsp.mt_cap_spb_instance.bridge_priority",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_v,
{ "V", "isis.lsp.mt_cap_spb_instance.v",
FT_BOOLEAN, 32, NULL, 0x00100000,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_number_of_trees,
{ "Number of Trees", "isis.lsp.mt_cap_spb_instance.number_of_trees",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_u,
{ "U", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.u",
FT_BOOLEAN, 8, NULL, 0x80,
"Set if this bridge is currently using this ECT-ALGORITHM for I-SIDs it sources or sinks", HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_m,
{ "M", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.m",
FT_BOOLEAN, 8, NULL, 0x40,
"indicates if this is SPBM or SPBV mode", HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_a,
{ "A", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.a",
FT_BOOLEAN, 8, NULL, 0x20,
"When set, declares this is an SPVID with auto-allocation", HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_reserved,
{ "Reserved", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.reserved",
FT_UINT8, BASE_HEX, NULL, 0x1F,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_ect,
{ "ECT-ALGORITHM", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.ect",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_base_vid,
{ "Base VID", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.basevid",
FT_UINT24, BASE_DEC, NULL, 0xFFF000,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_instance_vlanid_tuple_spvid,
{ "SPVID", "isis.lsp.mt_cap_spb_instance.vlanid_tuple.spvid",
FT_UINT24, BASE_DEC, NULL, 0xFFF000,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_opaque_algorithm,
{ "Algorithm", "isis.lsp.mt_cap_spb_opaque.algorithm",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spb_opaque_information,
{ "information", "isis.lsp.mt_cap_spb_opaque.information",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_b_mac,
{ "B-MAC", "isis.lsp.mt_cap_spbm_service_identifier.b_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_base_vid,
{ "Base-VID", "isis.lsp.mt_cap_spbm_service_identifier.base_vid",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_t,
{ "T", "isis.lsp.mt_cap_spbm_service_identifier.t",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_r,
{ "R", "isis.lsp.mt_cap_spbm_service_identifier.r",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_reserved,
{ "Reserved", "isis.lsp.mt_cap_spbm_service_identifier.reserved",
FT_UINT8, BASE_HEX, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spbm_service_identifier_i_sid,
{ "I-SID", "isis.lsp.mt_cap_spbm_service_identifier.i_sid",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_mtid,
{ "Topology ID", "isis.lsp.mt_cap.mtid",
FT_UINT16, BASE_DEC|BASE_RANGE_STRING, RVALS(mtid_strings), 0x0fff,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_reserved,
{ "Reserved", "isis.lsp.eis_neighbors_clv_inner.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_es_neighbor_id,
{ "ES Neighbor ID", "isis.lsp.eis_neighbors.es_neighbor_id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_is_neighbor_id,
{ "IS Neighbor", "isis.lsp.eis_neighbors.is_neighbor",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_default_metric,
{ "Default Metric", "isis.lsp.eis_neighbors.default_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_delay_metric,
{ "Delay Metric", "isis.lsp.eis_neighbors.delay_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_expense_metric,
{ "Expense Metric", "isis.lsp.eis_neighbors.expense_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_error_metric,
{ "Error Metric", "isis.lsp.eis_neighbors.error_metric",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_isis_lsp_maximum_link_bandwidth,
{ "Maximum link bandwidth", "isis.lsp.maximum_link_bandwidth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_reservable_link_bandwidth,
{ "Reservable link bandwidth", "isis.lsp.reservable_link_bandwidth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_is_neighbor_id,
{ "IS neighbor ID", "isis.lsp.ext_is_reachability.is_neighbor_id",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_metric,
{ "Metric", "isis.lsp.ext_is_reachability.metric",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_subclvs_len,
{ "SubCLV Length", "isis.lsp.ext_is_reachability.subclvs_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_code,
{ "Code", "isis.lsp.ext_is_reachability.code",
FT_UINT8, BASE_DEC, VALS(isis_lsp_ext_is_reachability_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_len,
{ "Length", "isis.lsp.ext_is_reachability.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_value,
{ "Value", "isis.lsp.ext_is_reachability.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_link_local_identifier,
{ "Link Local Identifier", "isis.lsp.ext_is_reachability.link_local_identifier",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_link_remote_identifier,
{ "Link Remote Identifier", "isis.lsp.ext_is_reachability.link_remote_identifier",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_ipv4_interface_address,
{ "IPv4 interface address", "isis.lsp.ext_is_reachability.ipv4_interface_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_ipv4_neighbor_address,
{ "IPv4 neighbor address", "isis.lsp.ext_is_reachability.ipv4_neighbor_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ext_is_reachability_traffic_engineering_default_metric,
{ "Traffic engineering default metric", "isis.lsp.ext_is_reachability.traffic_engineering_default_metric",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_partition_designated_l2_is,
{ "Partition designated L2 IS", "isis.lsp.partition_designated_l2_is",
FT_SYSTEM_ID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_originating_lsp_buffer_size,
{ "Neighbor originating buffer size", "isis.lsp.originating_lsp_buffer_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_error_metric,
{ "Error metric", "isis.lsp.error_metric",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x08,
NULL, HFILL }
},
{ &hf_isis_lsp_expense_metric,
{ "Expense metric", "isis.lsp.expense_metric",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x04,
NULL, HFILL }
},
{ &hf_isis_lsp_delay_metric,
{ "Delay metric", "isis.lsp.delay_metric",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x02,
NULL, HFILL }
},
{ &hf_isis_lsp_default_metric,
{ "Default metric", "isis.lsp.default_metric",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x01,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_default_metric_ie,
{ "Default Metric IE", "isis.lsp.ip_reachability.default_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_delay_metric_support,
{ "Delay Metric", "isis.lsp.ip_reachability.delay_metric_support",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_expense_metric_support,
{ "Expense Metric", "isis.lsp.ip_reachability.expense_metric_support",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_error_metric_support,
{ "Error Metric", "isis.lsp.ip_reachability.error_metric_support",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_spsourceid,
{ "SPSourceId", "isis.lsp.mt_cap.spsourceid",
FT_UINT32, BASE_HEX_DEC, NULL, 0xfffff,
NULL, HFILL }
},
{ &hf_isis_lsp_mt_cap_overload,
{ "Overload", "isis.lsp.overload",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_default_metric_ie,
{ "Default Metric", "isis.lsp.eis_neighbors.default_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_delay_metric_supported,
{ "Delay Metric", "isis.lsp.eis_neighbors_delay_metric.supported",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_expense_metric_supported,
{ "Expense Metric", "isis.lsp.eis_neighbors.expense_metric_supported",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_error_metric_supported,
{ "Error Metric", "isis.lsp.eis_neighbors.error_metric_supported",
FT_BOOLEAN, 8, TFS(&tfs_notsupported_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_unrsv_bw_priority_level,
{ "priority level", "isis.lsp.unrsv_bw.priority_level",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_distribution,
{ "Distribution", "isis.lsp.ip_reachability.distribution",
FT_BOOLEAN, 8, TFS(&tfs_up_down), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_delay_metric_ie,
{ "Delay Metric", "isis.lsp.ip_reachability.delay_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_expense_metric_ie,
{ "Expense Metric", "isis.lsp.ip_reachability.expense_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_reachability_error_metric_ie,
{ "Error Metric", "isis.lsp.ip_reachability.error_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_delay_metric_ie,
{ "Delay Metric", "isis.lsp.eis_neighbors.delay_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_expense_metric_ie,
{ "Expense Metric", "isis.lsp.eis_neighbors.expense_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_eis_neighbors_error_metric_ie,
{ "Error Metric", "isis.lsp.eis_neighbors.error_metric_ie",
FT_BOOLEAN, 8, TFS(&tfs_external_internal), 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_router_id,
{ "Router ID", "isis.lsp.rt_capable.router_id",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_flag_s,
{ "S bit", "isis.lsp.rt_capable.flag_s",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_isis_lsp_rt_capable_flag_d,
{ "D bit", "isis.lsp.rt_capable.flag_d",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_node_cap_b_bit,
{ "B bit: P2MP Branch LSR capability", "isis.lsp.te_node_cap.b_bit",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_node_cap_e_bit,
{ "E bit: P2MP Bud LSR capability", "isis.lsp.te_node_cap.e_bit",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_node_cap_m_bit,
{ "M bit: MPLS-TE support", "isis.lsp.te_node_cap.m_bit",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_node_cap_g_bit,
{ "G bit: GMPLS support", "isis.lsp.te_node_cap.g_bit",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_te_node_cap_p_bit,
{ "P bit: P2MP RSVP-TE support", "isis.lsp.te_node_cap.p_bit",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_cap_i_flag,
{ "I flag: IPv4 support", "isis.lsp.sr_cap.i_flag",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_cap_v_flag,
{ "V flag: IPv6 support", "isis.lsp.sr_cap.v_flag",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_cap_range,
{ "Range", "isis.lsp.sr_cap.range",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_cap_sid,
{ "SID", "isis.lsp.sr_cap.sid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_cap_label,
{ "Label", "isis.lsp.sr_cap.label",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_sr_alg,
{ "Algorithm", "isis.lsp.sr_alg",
FT_UINT8, BASE_DEC, VALS(isis_lsp_sr_alg_vals), 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_area_address,
{ "Area address", "isis.lsp.area_address",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_clv_nlpid,
{ "NLPID", "isis.lsp.clv_nlpid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_ip_authentication,
{ "IP Authentication", "isis.lsp.ip_authentication",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_authentication,
{ "Authentication", "isis.lsp.authentication",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_area_address_str,
{ "Area address", "isis.lsp.area_address_str",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_is_virtual,
{ "IsVirtual", "isis.lsp.is_virtual",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_group,
{ "Group", "isis.lsp.group",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_default,
{ "Default", "isis.lsp.default",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_default_support,
{ "Default", "isis.lsp.default_support",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_delay,
{ "Delay", "isis.lsp.delay",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_delay_support,
{ "Delay", "isis.lsp.delay_support",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_expense,
{ "Expense", "isis.lsp.expense",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_expense_support,
{ "Expense", "isis.lsp.expense_support",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
{ &hf_isis_lsp_error,
{ "Error", "isis.lsp.error",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_isis_lsp_error_support,
{ "Error", "isis.lsp.error_support",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL }
},
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
&ett_isis_lsp_part_of_clv_ext_is_reachability_subtlv,
&ett_isis_lsp_subclv_admin_group,
&ett_isis_lsp_subclv_unrsv_bw,
&ett_isis_lsp_subclv_bw_ct,
&ett_isis_lsp_subclv_spb_link_metric,
&ett_isis_lsp_adj_sid_flags,
&ett_isis_lsp_clv_unknown,
&ett_isis_lsp_clv_partition_dis,
&ett_isis_lsp_clv_prefix_neighbors,
&ett_isis_lsp_clv_authentication,
&ett_isis_lsp_clv_ip_authentication,
&ett_isis_lsp_clv_nlpid,
&ett_isis_lsp_clv_hostname,
&ett_isis_lsp_clv_srlg,
&ett_isis_lsp_clv_ipv4_int_addr,
&ett_isis_lsp_clv_ipv6_int_addr,
&ett_isis_lsp_clv_mt_cap,
&ett_isis_lsp_clv_mt_cap_spb_instance,
&ett_isis_lsp_clv_mt_cap_spbm_service_identifier,
&ett_isis_lsp_clv_mt_cap_spbv_mac_address,
&ett_isis_lsp_clv_sid_label_binding,
&ett_isis_lsp_clv_te_router_id,
&ett_isis_lsp_clv_ip_reachability,
&ett_isis_lsp_clv_ip_reach_subclv,
&ett_isis_lsp_clv_ext_ip_reachability,
&ett_isis_lsp_part_of_clv_ext_ip_reachability,
&ett_isis_lsp_prefix_sid_flags,
&ett_isis_lsp_clv_ipv6_reachability,
&ett_isis_lsp_part_of_clv_ipv6_reachability,
&ett_isis_lsp_clv_mt,
&ett_isis_lsp_clv_mt_is,
&ett_isis_lsp_part_of_clv_mt_is,
&ett_isis_lsp_clv_rt_capable,
&ett_isis_lsp_clv_te_node_cap_desc,
&ett_isis_lsp_clv_trill_version,
&ett_isis_lsp_clv_trees,
&ett_isis_lsp_clv_root_id,
&ett_isis_lsp_clv_nickname,
&ett_isis_lsp_clv_interested_vlans,
&ett_isis_lsp_clv_tree_used,
&ett_isis_lsp_clv_vlan_group,
&ett_isis_lsp_clv_grp_address,
&ett_isis_lsp_clv_grp_macaddr,
&ett_isis_lsp_clv_grp_ipv4addr,
&ett_isis_lsp_clv_grp_ipv6addr,
&ett_isis_lsp_clv_mt_reachable_IPv4_prefx,
&ett_isis_lsp_clv_mt_reachable_IPv6_prefx,
&ett_isis_lsp_clv_originating_buff_size,
&ett_isis_lsp_clv_sr_cap,
&ett_isis_lsp_clv_sr_sid_label,
&ett_isis_lsp_clv_sr_alg,
&ett_isis_lsp_sl_flags,
&ett_isis_lsp_sl_sub_tlv
};
static ei_register_info ei[] = {
{ &ie_isis_lsp_checksum_bad, { "isis.lsp.checksum_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_isis_lsp_short_packet, { "isis.lsp.short_packet", PI_MALFORMED, PI_ERROR, "Short packet", EXPFILL }},
{ &ei_isis_lsp_long_packet, { "isis.lsp.long_packet", PI_MALFORMED, PI_ERROR, "Long packet", EXPFILL }},
{ &ei_isis_lsp_subtlv, { "isis.lsp.subtlv.unknown", PI_PROTOCOL, PI_WARN, "Unknown SubTLV", EXPFILL }},
{ &ei_isis_lsp_authentication, { "isis.lsp.authentication.unknown", PI_PROTOCOL, PI_WARN, "Unknown authentication type", EXPFILL }},
{ &ei_isis_lsp_clv_mt, { "isis.lsp.clv_mt.malformed", PI_MALFORMED, PI_ERROR, "malformed MT-ID", EXPFILL }},
{ &ei_isis_lsp_malformed_subtlv, { "isis.lsp.subtlv.malformed", PI_MALFORMED, PI_ERROR, "malformed SubTLV", EXPFILL }},
{ &ei_isis_lsp_reserved_not_zero, { "isis.lsp.reserved_not_zero", PI_PROTOCOL, PI_WARN, "Reserve bit not 0", EXPFILL }},
};
expert_module_t* expert_isis_lsp;
proto_isis_lsp = proto_register_protocol(PROTO_STRING_LSP, "ISIS LSP", "isis.lsp");
proto_register_field_array(proto_isis_lsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isis_lsp = expert_register_protocol(proto_isis_lsp);
expert_register_field_array(expert_isis_lsp, ei, array_length(ei));
}
void
proto_reg_handoff_isis_lsp(void)
{
dissector_add_uint("isis.type", ISIS_TYPE_L1_LSP, new_create_dissector_handle(dissect_isis_l1_lsp, proto_isis_lsp));
dissector_add_uint("isis.type", ISIS_TYPE_L2_LSP, new_create_dissector_handle(dissect_isis_l2_lsp, proto_isis_lsp));
}
