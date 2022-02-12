static int
dissect_openflow_header_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v6_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v6_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_xid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_oxm_header_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
guint16 oxm_class;
guint8 oxm_length;
oxm_class = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_oxm_class, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (oxm_class == OFPXMC_OPENFLOW_BASIC) {
proto_tree_add_bits_item(tree, hf_openflow_v6_oxm_field_basic, tvb, (offset * 8), 7, ENC_NA);
} else {
proto_tree_add_bits_item(tree, hf_openflow_v6_oxm_field, tvb, (offset * 8), 7, ENC_NA);
}
proto_tree_add_bits_item(tree, hf_openflow_v6_oxm_hm, tvb, (offset * 8) + 7, 1, ENC_NA);
offset+=1;
oxm_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_oxm_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (oxm_class == OFPXMC_EXPERIMENTER) {
proto_tree_add_item(tree, hf_openflow_v6_oxm_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_oxm_experimenter_value, tvb, offset, oxm_length - 4, ENC_NA);
offset+=(oxm_length - 4);
}
return offset;
}
static int
dissect_openflow_oxm_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *oxm_tree;
guint16 oxm_class;
guint16 oxm_end;
guint8 oxm_field_hm;
guint8 oxm_hm;
guint8 oxm_field;
guint8 oxm_length;
guint8 field_length;
oxm_class = tvb_get_ntohs(tvb, offset);
oxm_field_hm = tvb_get_guint8(tvb, offset + 2);
oxm_length = tvb_get_guint8(tvb, offset + 3);
oxm_end = offset + 4 + oxm_length;
oxm_field = (oxm_field_hm & OXM_FIELD_MASK) >> OXM_FIELD_OFFSET;
oxm_hm = oxm_field_hm & OXM_HM_MASK;
field_length = (oxm_hm == 0) ? oxm_length : (oxm_length / 2);
oxm_tree = proto_tree_add_subtree(tree, tvb, offset, oxm_length + 4, ett_openflow_v6_oxm, NULL, "OXM field");
offset = dissect_openflow_oxm_header_v6(tvb, pinfo, oxm_tree, offset, length);
if (oxm_class == OFPXMC_OPENFLOW_BASIC) {
switch(oxm_field) {
case OFPXMT_OFB_IN_PORT:
case OFPXMT_OFB_IN_PHY_PORT:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_uint32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPXMT_OFB_ETH_DST:
case OFPXMT_OFB_ETH_SRC:
case OFPXMT_OFB_ARP_SHA:
case OFPXMT_OFB_ARP_THA:
case OFPXMT_OFB_IPV6_ND_SLL:
case OFPXMT_OFB_IPV6_ND_TLL:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_etheraddr, tvb, offset, 6, ENC_NA);
offset+=6;
if (oxm_hm) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_mask_etheraddr, tvb, offset, 6, ENC_NA);
offset+=6;
}
break;
case OFPXMT_OFB_ETH_TYPE:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_ethertype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case OFPXMT_OFB_VLAN_VID:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_vlan_present, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_vlan_vid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (oxm_hm) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_mask_vlan, tvb, offset, 2, ENC_NA);
offset+=2;
}
break;
case OFPXMT_OFB_IP_PROTO:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_ipproto, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
break;
case OFPXMT_OFB_IPV4_SRC:
case OFPXMT_OFB_IPV4_DST:
case OFPXMT_OFB_ARP_SPA:
case OFPXMT_OFB_ARP_TPA:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_ipv4addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (oxm_hm) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_mask_ipv4addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
break;
case OFPXMT_OFB_TCP_SRC:
case OFPXMT_OFB_TCP_DST:
case OFPXMT_OFB_UDP_SRC:
case OFPXMT_OFB_UDP_DST:
case OFPXMT_OFB_SCTP_SRC:
case OFPXMT_OFB_SCTP_DST:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_uint16, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case OFPXMT_OFB_IPV6_SRC:
case OFPXMT_OFB_IPV6_DST:
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_ipv6addr, tvb, offset, 16, ENC_NA);
offset+=16;
if (oxm_hm) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_mask_ipv6addr, tvb, offset, 16, ENC_NA);
offset+=16;
}
break;
case OFPXMT_OFB_MPLS_LABEL:
if (field_length == 3) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_uint24, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=3;
} else if (field_length == 4) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value_uint32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
break;
default:
if (field_length > 0) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_value, tvb, offset, field_length, ENC_NA);
offset += field_length;
}
if (field_length > 0 && oxm_hm != 0) {
proto_tree_add_item(oxm_tree, hf_openflow_v6_oxm_mask, tvb, offset, field_length, ENC_NA);
offset += field_length;
}
break;
}
if(oxm_end > offset){
proto_tree_add_expert_format(oxm_tree, pinfo, &ei_openflow_v6_oxm_undecoded,
tvb, offset, oxm_end-offset, "Undecoded Data");
offset = oxm_end;
}
} else {
proto_tree_add_expert_format(oxm_tree, pinfo, &ei_openflow_v6_oxm_undecoded,
tvb, offset, oxm_length, "Unknown OXM body.");
offset+=oxm_length;
}
return offset;
}
static int
dissect_openflow_match_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *match_tree;
guint16 match_type;
guint16 match_length;
gint32 fields_end;
guint16 pad_length;
match_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_match, &ti, "Match");
match_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(match_tree, hf_openflow_v6_match_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
match_length = tvb_get_ntohs(tvb, offset);
pad_length = (match_length + 7)/8*8 - match_length;
proto_item_set_len(ti, match_length + pad_length);
ti = proto_tree_add_item(match_tree, hf_openflow_v6_match_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (match_length < 4) {
expert_add_info(pinfo, ti, &ei_openflow_v6_length_too_short);
return offset;
}
switch (match_type) {
case OFPMT_STANDARD:
proto_tree_add_expert_format(match_tree, pinfo, &ei_openflow_v6_match_undecoded,
tvb, offset, match_length - 4, "Standard match body (deprecated).");
offset+=match_length-4;
break;
case OFPMT_OXM:
fields_end = offset + match_length - 4;
while(offset < fields_end) {
offset = dissect_openflow_oxm_v6(tvb, pinfo, match_tree, offset, length);
}
break;
default:
proto_tree_add_expert_format(match_tree, pinfo, &ei_openflow_v6_match_undecoded,
tvb, offset, match_length - 4, "Unknown match body.");
offset+=match_length-4;
break;
}
if (pad_length > 0) {
proto_tree_add_item(match_tree, hf_openflow_v6_match_pad, tvb, offset, pad_length, ENC_NA);
offset+=pad_length;
}
return offset;
}
static int
dissect_openflow_meter_band_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *band_tree;
guint16 band_type;
guint16 band_len;
band_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_meter_band, &ti, "Meter band");
band_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
band_len = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, band_len);
ti = proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_burst_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (band_len < 12) {
expert_add_info(pinfo, ti, &ei_openflow_v6_length_too_short);
return offset;
}
switch (band_type) {
case OFPMBT_DROP:
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_drop_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPMBT_DSCP_REMARK:
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_dscp_remark_prec_level, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_dscp_remark_pad, tvb, offset, 3, ENC_NA);
offset+=3;
break;
case OFPMBT_EXPERIMENTER:
proto_tree_add_item(band_tree, hf_openflow_v6_meter_band_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(band_tree, pinfo, &ei_openflow_v6_meter_band_undecoded,
tvb, offset, offset - 16 + band_len, "Experimenter meter band body.");
offset+=band_len-16;
break;
default:
proto_tree_add_expert_format(band_tree, pinfo, &ei_openflow_v6_meter_band_undecoded,
tvb, offset, offset - 12 + band_len, "Unknown meter band body.");
offset+=band_len-12;
break;
}
return offset;
}
static int
dissect_openflow_hello_element_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree *elem_tree;
guint16 elem_type;
guint16 elem_length;
guint16 pad_length;
elem_tree = proto_tree_add_subtree(tree, tvb, offset, length - offset, ett_openflow_v6_hello_element, NULL, "Element");
elem_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(elem_tree, hf_openflow_v6_hello_element_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
elem_length = tvb_get_ntohs(tvb, offset);
pad_length = (elem_length + 7)/8*8 - elem_length;
proto_tree_add_item(elem_tree, hf_openflow_v6_hello_element_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (elem_length >= 4) {
elem_length -= 4;
}
switch (elem_type) {
case OFPHET_VERSIONBITMAP:
proto_tree_add_item(elem_tree, hf_openflow_v6_hello_element_version_bitmap, tvb, offset, elem_length, ENC_NA);
offset += elem_length;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_hello_element_undecoded,
tvb, offset, elem_length, "Unknown hello element body.");
offset += elem_length;
break;
}
if (pad_length > 0) {
proto_tree_add_item(tree, hf_openflow_v6_hello_element_pad, tvb, offset, pad_length, ENC_NA);
offset+=pad_length;
}
return offset;
}
static void
dissect_openflow_hello_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
while (offset < length) {
offset = dissect_openflow_hello_element_v6(tvb, pinfo, tree, offset, length);
}
}
static void
dissect_openflow_error_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree *data_tree;
proto_item *data_ti;
guint16 error_type;
error_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_error_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
switch(error_type) {
case OFPET_HELLO_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_hello_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BAD_REQUEST:
proto_tree_add_item(tree, hf_openflow_v6_error_bad_request_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BAD_ACTION:
proto_tree_add_item(tree, hf_openflow_v6_error_bad_action_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BAD_INSTRUCTION:
proto_tree_add_item(tree, hf_openflow_v6_error_bad_instruction_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BAD_MATCH:
proto_tree_add_item(tree, hf_openflow_v6_error_bad_match_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_FLOW_MOD_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_flow_mod_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_GROUP_MOD_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_group_mod_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_PORT_MOD_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_port_mod_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_TABLE_MOD_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_table_mod_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_QUEUE_OP_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_queue_op_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_SWITCH_CONFIG_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_switch_config_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_ROLE_REQUEST_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_role_request_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_METER_MOD_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_meter_mod_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_TABLE_FEATURES_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_table_features_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BAD_PROPERTY:
proto_tree_add_item(tree, hf_openflow_v6_error_bad_property_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_ASYNC_CONFIG_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_async_config_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_FLOW_MONITOR_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_flow_monitor_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_BUNDLE_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_bundle_failed_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OFPET_EXPERIMENTER:
default:
proto_tree_add_item(tree, hf_openflow_v6_error_code, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
offset +=2;
switch(error_type) {
case OFPET_HELLO_FAILED:
proto_tree_add_item(tree, hf_openflow_v6_error_data_text, tvb, offset, length - 12, ENC_NA|ENC_ASCII);
break;
case OFPET_BAD_REQUEST:
case OFPET_BAD_ACTION:
case OFPET_BAD_INSTRUCTION:
case OFPET_BAD_MATCH:
case OFPET_FLOW_MOD_FAILED:
case OFPET_GROUP_MOD_FAILED:
case OFPET_PORT_MOD_FAILED:
case OFPET_TABLE_MOD_FAILED:
case OFPET_QUEUE_OP_FAILED:
case OFPET_SWITCH_CONFIG_FAILED:
case OFPET_ROLE_REQUEST_FAILED:
case OFPET_METER_MOD_FAILED:
case OFPET_TABLE_FEATURES_FAILED: {
gboolean save_in_error_pkt;
data_ti = proto_tree_add_item(tree, hf_openflow_v6_error_data_body, tvb, offset, length - 20, ENC_NA);
data_tree = proto_item_add_subtree(data_ti, ett_openflow_v6_error_data);
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
col_set_writable(pinfo->cinfo, -1, FALSE);
dissect_openflow_message_v6(tvb, pinfo, data_tree, offset);
pinfo->flags.in_error_pkt = save_in_error_pkt;
col_set_writable(pinfo->cinfo, -1, TRUE);
}
break;
case OFPET_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_error_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_error_undecoded,
tvb, offset, length - 16, "Experimenter error body.");
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_error_undecoded,
tvb, offset, length - 12, "Unknown error body.");
break;
}
}
static void
dissect_openflow_echo_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
if (offset < length) {
proto_tree_add_item(tree, hf_openflow_v6_echo_data, tvb, offset, length - offset, ENC_NA);
}
}
static void
dissect_openflow_experimenter_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree_add_item(tree, hf_openflow_v6_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (offset < length) {
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_experimenter_undecoded,
tvb, offset, length - 16, "Experimenter body.");
}
}
static void
dissect_openflow_switch_features_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *cap_tree;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_datapath_id, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_n_buffers, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_n_tables, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_auxiliary_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_pad, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_switch_features_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
cap_tree = proto_item_add_subtree(ti, ett_openflow_v6_switch_features_capabilities);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_flow_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_table_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_port_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_group_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_ip_reasm, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_queue_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(cap_tree, hf_openflow_v6_switch_features_capabilities_port_blocked, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_switch_features_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_switch_config_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *flags_tree;
ti = proto_tree_add_item(tree, hf_openflow_v6_switch_config_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_switch_config_flags);
proto_tree_add_bits_item(flags_tree, hf_openflow_v6_switch_config_flags_fragments, tvb, (offset * 8) + 14, 2, ENC_NA);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_switch_config_miss_send_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_packet_in_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *data_tree;
tvbuff_t *next_tvb;
gboolean save_writable;
gboolean save_in_error_pkt;
address save_dl_src, save_dl_dst, save_net_src, save_net_dst, save_src, save_dst;
proto_tree_add_item(tree, hf_openflow_v6_packet_in_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_packet_in_total_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_packet_in_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_packet_in_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_packet_in_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
offset = dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
proto_tree_add_item(tree, hf_openflow_v6_packet_in_pad, tvb, offset, 2, ENC_NA);
offset+=2;
if (offset < length) {
data_tree = proto_tree_add_subtree(tree, tvb, offset, length - offset, ett_openflow_v6_packet_in_data, NULL, "Data");
save_writable = col_get_writable(pinfo->cinfo, -1);
save_in_error_pkt = pinfo->flags.in_error_pkt;
copy_address_shallow(&save_dl_src, &pinfo->dl_src);
copy_address_shallow(&save_dl_dst, &pinfo->dl_dst);
copy_address_shallow(&save_net_src, &pinfo->net_src);
copy_address_shallow(&save_net_dst, &pinfo->net_dst);
copy_address_shallow(&save_src, &pinfo->src);
copy_address_shallow(&save_dst, &pinfo->dst);
col_set_writable(pinfo->cinfo, -1, FALSE);
next_tvb = tvb_new_subset_length(tvb, offset, length - offset);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, data_tree);
col_set_writable(pinfo->cinfo, -1, save_writable);
pinfo->flags.in_error_pkt = save_in_error_pkt;
copy_address_shallow(&pinfo->dl_src, &save_dl_src);
copy_address_shallow(&pinfo->dl_dst, &save_dl_dst);
copy_address_shallow(&pinfo->net_src, &save_net_src);
copy_address_shallow(&pinfo->net_dst, &save_net_dst);
copy_address_shallow(&pinfo->src, &save_src);
copy_address_shallow(&pinfo->dst, &save_dst);
}
}
static void
dissect_openflow_flow_removed_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_idle_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_hard_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_packet_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_flow_removed_byte_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
}
static int
dissect_openflow_action_header_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
guint16 act_type;
act_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_action_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_action_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (act_type == OFPAT_EXPERIMENTER) {
proto_tree_add_item(tree, hf_openflow_v6_action_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
return offset;
}
static int
dissect_openflow_action_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *act_tree;
guint16 act_type;
guint16 act_length;
gint32 act_end;
act_type = tvb_get_ntohs(tvb, offset);
act_length = tvb_get_ntohs(tvb, offset + 2);
act_end = offset + act_length;
act_tree = proto_tree_add_subtree(tree, tvb, offset, act_length, ett_openflow_v6_action, NULL, "Action");
offset = dissect_openflow_action_header_v6(tvb, pinfo, act_tree, offset, length);
switch (act_type) {
case OFPAT_OUTPUT:
proto_tree_add_item(act_tree, hf_openflow_v6_action_output_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(act_tree, hf_openflow_v6_action_output_max_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_output_pad, tvb, offset, 6, ENC_NA);
offset+=6;
break;
case OFPAT_COPY_TTL_OUT:
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_ttl_out_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_COPY_TTL_IN:
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_ttl_in_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_SET_MPLS_TTL:
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_mpls_ttl_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_mpls_ttl_pad, tvb, offset, 3, ENC_NA);
offset+=3;
break;
case OFPAT_DEC_MPLS_TTL:
proto_tree_add_item(act_tree, hf_openflow_v6_action_dec_mpls_ttl_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_PUSH_VLAN:
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_vlan_ethertype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_vlan_pad, tvb, offset, 2, ENC_NA);
offset+=2;
break;
case OFPAT_POP_VLAN:
proto_tree_add_item(act_tree, hf_openflow_v6_action_pop_vlan_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_PUSH_MPLS:
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_mpls_ethertype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_mpls_pad, tvb, offset, 2, ENC_NA);
offset+=2;
break;
case OFPAT_POP_MPLS:
proto_tree_add_item(act_tree, hf_openflow_v6_action_pop_mpls_ethertype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_pop_mpls_pad, tvb, offset, 2, ENC_NA);
offset+=2;
break;
case OFPAT_SET_QUEUE:
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_queue_queue_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPAT_GROUP:
proto_tree_add_item(act_tree, hf_openflow_v6_action_group_group_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPAT_SET_NW_TTL:
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_nw_ttl_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_nw_ttl_pad, tvb, offset, 3, ENC_NA);
offset+=3;
break;
case OFPAT_DEC_NW_TTL:
proto_tree_add_item(act_tree, hf_openflow_v6_action_dec_nw_ttl_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_SET_FIELD:
offset = dissect_openflow_oxm_v6(tvb, pinfo, act_tree, offset, length);
if (offset < act_end) {
proto_tree_add_item(act_tree, hf_openflow_v6_action_set_field_pad, tvb, offset, act_end - offset, ENC_NA);
offset = act_end;
}
break;
case OFPAT_PUSH_PBB:
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_pbb_ethertype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_push_pbb_pad, tvb, offset, 2, ENC_NA);
offset+=2;
break;
case OFPAT_POP_PBB:
proto_tree_add_item(act_tree, hf_openflow_v6_action_pop_pbb_pad, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_COPY_FIELD:
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_field_n_bits, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_field_src_offset, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_field_dst_offset, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(act_tree, hf_openflow_v6_action_copy_field_pad, tvb, offset, 2, ENC_NA);
offset+=2;
break;
case OFPAT_METER:
proto_tree_add_item(act_tree, hf_openflow_v6_action_meter_id, tvb, offset, 4, ENC_NA);
offset+=4;
break;
case OFPAT_EXPERIMENTER:
proto_tree_add_expert_format(act_tree, pinfo, &ei_openflow_v6_action_undecoded,
tvb, offset, act_length - 8, "Experimenter action body.");
offset += act_length - 8;
break;
default:
proto_tree_add_expert_format(act_tree, pinfo, &ei_openflow_v6_action_undecoded,
tvb, offset, act_length - 4, "Unknown action body.");
offset += act_length - 4;
break;
}
return offset;
}
static int
dissect_openflow_port_desc_prop_ethernet_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *curr_tree, *adv_tree, *supp_tree, *peer_tree;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_pad, tvb, offset, 2, ENC_NA);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_current, tvb, offset, 4, ENC_BIG_ENDIAN);
curr_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_desc_prop_ethernet_current);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_40gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_100gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_1tb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(curr_tree, hf_openflow_v6_port_desc_prop_ethernet_current_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_advertised, tvb, offset, 4, ENC_BIG_ENDIAN);
adv_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_desc_prop_ethernet_advertised);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_40gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_100gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_1tb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_port_desc_prop_ethernet_advertised_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
supp_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_desc_prop_ethernet_supported);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_40gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_100gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_1tb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_ethernet_supported_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_peer, tvb, offset, 4, ENC_BIG_ENDIAN);
peer_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_desc_prop_ethernet_peer);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_40gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_100gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_1tb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(peer_tree, hf_openflow_v6_port_desc_prop_ethernet_peer_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_curr_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(tree, " Speed: %u Mb", tvb_get_ntohl(tvb, offset)/1000);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_ethernet_max_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_port_desc_prop_optical_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *supp_tree;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_pad, tvb, offset, 2, ENC_NA);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_supported, tvb, offset, 4, ENC_BIG_ENDIAN);
supp_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_desc_prop_optical_supported);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_optical_supported_rx_tune, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_optical_supported_tx_tune, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_optical_supported_tx_pwr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(supp_tree, hf_openflow_v6_port_desc_prop_optical_supported_use_freq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_tx_min_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_tx_max_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_tx_grid_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_rx_min_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_rx_max_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_rx_grid_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_tx_pwr_min, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_optical_tx_pwr_max, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_port_desc_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *prop_tree;
guint16 prop_type;
guint16 prop_length;
prop_type = tvb_get_ntohs(tvb, offset);
prop_length = tvb_get_ntohs(tvb, offset);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_length, ett_openflow_v6_port_desc_prop, NULL, "Port desc. property");
proto_tree_add_item(prop_tree, hf_openflow_v6_port_desc_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_port_desc_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch (prop_type) {
case OFPPDPT_ETHERNET:
offset = dissect_openflow_port_desc_prop_ethernet_v6(tvb, pinfo, prop_tree, offset, length);
break;
case OFPPDPT_OPTICAL:
offset = dissect_openflow_port_desc_prop_optical_v6(tvb, pinfo, prop_tree, offset, length);
break;
case OFPPDPT_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_desc_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_port_desc_prop_undecoded,
tvb, offset, prop_length - 12, "Experimenter port desc. property.");
offset += prop_length - 12;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_port_desc_prop_undecoded,
tvb, offset, prop_length - 4, "Unknown port desc. property.");
offset += prop_length - 4;
break;
}
return offset;
}
static int
dissect_openflow_port_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *port_tree, *conf_tree, *state_tree;
guint16 port_end;
port_tree = proto_tree_add_subtree(tree, tvb, offset, 64, ett_openflow_v6_port, NULL, "Port");
proto_tree_add_item(port_tree, hf_openflow_v6_port_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
port_end = tvb_get_ntohs(tvb, offset) + offset - 4;
proto_tree_add_item(port_tree, hf_openflow_v6_port_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(port_tree, hf_openflow_v6_port_pad, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(port_tree, hf_openflow_v6_port_hw_addr, tvb, offset, OFP_ETH_ALEN, ENC_NA);
proto_item_append_text(port_tree, ": %s", tvb_ether_to_str(tvb, offset));
offset+=OFP_ETH_ALEN;
proto_tree_add_item(port_tree, hf_openflow_v6_port_pad2, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(port_tree, hf_openflow_v6_port_name, tvb, offset, OFP_MAX_PORT_NAME_LEN, ENC_ASCII|ENC_NA);
proto_item_append_text(port_tree, " (%s)", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, OFP_ETH_ALEN, ENC_ASCII));
offset+=OFP_MAX_PORT_NAME_LEN;
ti = proto_tree_add_item(port_tree, hf_openflow_v6_port_config, tvb, offset, 4, ENC_BIG_ENDIAN);
conf_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_config);
proto_tree_add_item(conf_tree, hf_openflow_v6_port_config_port_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_port_config_no_recv, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_port_config_no_fwd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_port_config_no_packet_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(port_tree, hf_openflow_v6_port_state, tvb, offset, 4, ENC_BIG_ENDIAN);
state_tree = proto_item_add_subtree(ti, ett_openflow_v6_port_state);
proto_tree_add_item(state_tree, hf_openflow_v6_port_state_link_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(state_tree, hf_openflow_v6_port_state_blocked, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(state_tree, hf_openflow_v6_port_state_live, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < port_end) {
offset = dissect_openflow_port_desc_prop_v6(tvb, pinfo, tree, offset, length);
}
return offset;
}
static void
dissect_openflow_port_status_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_port_status_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_port_status_pad, tvb, offset, 7, ENC_NA);
offset+=7;
dissect_openflow_port_v6(tvb, pinfo, tree, offset, length);
}
static void
dissect_openflow_packet_out_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *data_tree;
guint16 acts_len;
gint32 acts_end;
tvbuff_t *next_tvb;
gboolean save_writable;
gboolean save_in_error_pkt;
address save_dl_src, save_dl_dst, save_net_src, save_net_dst, save_src, save_dst;
proto_tree_add_item(tree, hf_openflow_v6_packet_out_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_packet_out_in_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
acts_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_packet_out_acts_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_packet_out_pad, tvb, offset, 6, ENC_NA);
offset+=6;
acts_end = offset + acts_len;
while (offset < acts_end) {
offset = dissect_openflow_action_v6(tvb, pinfo, tree, offset, length);
}
if (offset < length) {
data_tree = proto_tree_add_subtree(tree, tvb, offset, length - offset, ett_openflow_v6_packet_out_data, NULL, "Data");
save_writable = col_get_writable(pinfo->cinfo, -1);
save_in_error_pkt = pinfo->flags.in_error_pkt;
copy_address_shallow(&save_dl_src, &pinfo->dl_src);
copy_address_shallow(&save_dl_dst, &pinfo->dl_dst);
copy_address_shallow(&save_net_src, &pinfo->net_src);
copy_address_shallow(&save_net_dst, &pinfo->net_dst);
copy_address_shallow(&save_src, &pinfo->src);
copy_address_shallow(&save_dst, &pinfo->dst);
col_set_writable(pinfo->cinfo, -1, FALSE);
next_tvb = tvb_new_subset_length(tvb, offset, length - offset);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, data_tree);
col_set_writable(pinfo->cinfo, -1, save_writable);
pinfo->flags.in_error_pkt = save_in_error_pkt;
copy_address_shallow(&pinfo->dl_src, &save_dl_src);
copy_address_shallow(&pinfo->dl_dst, &save_dl_dst);
copy_address_shallow(&pinfo->net_src, &save_net_src);
copy_address_shallow(&pinfo->net_dst, &save_net_dst);
copy_address_shallow(&pinfo->src, &save_src);
copy_address_shallow(&pinfo->dst, &save_dst);
}
}
static int
dissect_openflow_instruction_header_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
guint16 inst_type;
inst_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_instruction_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_instruction_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (inst_type == OFPIT_EXPERIMENTER) {
proto_tree_add_item(tree, hf_openflow_v6_instruction_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
}
return offset;
}
static int
dissect_openflow_instruction_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *inst_tree;
guint16 inst_type;
guint16 inst_length;
gint32 acts_end;
inst_type = tvb_get_ntohs(tvb, offset);
inst_length = tvb_get_ntohs(tvb, offset + 2);
inst_tree = proto_tree_add_subtree(tree, tvb, offset, inst_length, ett_openflow_v6_instruction, NULL, "Instruction");
offset = dissect_openflow_instruction_header_v6(tvb, pinfo, inst_tree, offset, length);
if (inst_length < 8) {
inst_length = 8;
}
switch (inst_type) {
case OFPIT_GOTO_TABLE:
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_goto_table_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_goto_table_pad, tvb, offset, 3, ENC_NA);
offset+=3;
break;
case OFPIT_WRITE_METADATA:
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_write_metadata_pad, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_write_metadata_value, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_write_metadata_mask, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
break;
case OFPIT_WRITE_ACTIONS:
case OFPIT_APPLY_ACTIONS:
case OFPIT_CLEAR_ACTIONS:
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_actions_pad, tvb, offset, 4, ENC_NA);
offset+=4;
acts_end = offset + inst_length - 8;
while (offset < acts_end) {
offset = dissect_openflow_action_v6(tvb, pinfo, inst_tree, offset, length);
}
break;
case OFPIT_METER:
proto_tree_add_item(inst_tree, hf_openflow_v6_instruction_meter_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPIT_EXPERIMENTER:
proto_tree_add_expert_format(inst_tree, pinfo, &ei_openflow_v6_instruction_undecoded,
tvb, offset, inst_length - 8, "Experimenter instruction body.");
offset += inst_length - 8;
break;
default:
proto_tree_add_expert_format(inst_tree, pinfo, &ei_openflow_v6_instruction_undecoded,
tvb, offset, inst_length - 4, "Unknown instruction body.");
offset += inst_length - 4;
break;
}
return offset;
}
static void
dissect_openflow_flowmod_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *flags_tree;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_cookie_mask, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_command, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_idle_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_hard_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_buffer_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_out_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_out_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_flowmod_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_flowmod_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_flowmod_flags_send_flow_rem, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flowmod_flags_check_overlap, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flowmod_flags_reset_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flowmod_flags_no_packet_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flowmod_flags_no_byte_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flowmod_importance, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
offset = dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
while (offset < length) {
offset = dissect_openflow_instruction_v6(tvb, pinfo, tree, offset, length);
}
}
static int
dissect_openflow_bucket_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *bucket_tree;
guint16 bucket_length;
gint32 acts_end;
bucket_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_bucket, &ti, "Bucket");
bucket_length = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, bucket_length);
proto_tree_add_item(bucket_tree, hf_openflow_v6_bucket_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (bucket_length < 16) {
bucket_length = 16;
}
proto_tree_add_item(bucket_tree, hf_openflow_v6_bucket_weight, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(bucket_tree, hf_openflow_v6_bucket_watch_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(bucket_tree, hf_openflow_v6_bucket_watch_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(bucket_tree, hf_openflow_v6_bucket_pad, tvb, offset, 4, ENC_NA);
offset+=4;
acts_end = offset + bucket_length - 16;
while (offset < acts_end) {
offset = dissect_openflow_action_v6(tvb, pinfo, bucket_tree, offset, length);
}
return offset;
}
static void
dissect_openflow_groupmod_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree_add_item(tree, hf_openflow_v6_groupmod_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_pad, tvb, offset, 1, ENC_NA);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_group_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_bucket_array_len, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_pad, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_groupmod_command_bucket_id, tvb, offset, 4, ENC_NA);
offset+=4;
while (offset < length) {
offset = dissect_openflow_bucket_v6(tvb, pinfo, tree, offset, length);
}
}
static int
dissect_openflow_portmod_prop_ethernet_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *adv_tree;
ti = proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_ethernet_advertise, tvb, offset, 4, ENC_BIG_ENDIAN);
adv_tree = proto_item_add_subtree(ti, ett_openflow_v6_portmod_prop_ethernet_advertise);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_10mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_10mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_100mb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_100mb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_1gb_hd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_1gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_10gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_40gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_100gb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_1tb_fd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_copper, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_fiber, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_autoneg, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_pause, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(adv_tree, hf_openflow_v6_portmod_prop_ethernet_advertise_pause_asym, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_portmod_prop_optical_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *conf_tree;
ti = proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_optical_configure, tvb, offset, 4, ENC_BIG_ENDIAN);
conf_tree = proto_item_add_subtree(ti, ett_openflow_v6_portmod_prop_optical_configure);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_prop_optical_configure_rx_tune, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_prop_optical_configure_tx_tune, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_prop_optical_configure_tx_pwr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_prop_optical_configure_use_freq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_optical_freq_lmda, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_optical_fl_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_optical_grid_span, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_optical_tx_pwr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_portmod_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *prop_tree;
guint16 prop_type;
guint16 prop_length;
prop_type = tvb_get_ntohs(tvb, offset);
prop_length = tvb_get_ntohs(tvb, offset + 2);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_length, ett_openflow_v6_portmod_prop, NULL, "Portmod property");
proto_tree_add_item(prop_tree, hf_openflow_v6_portmod_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_portmod_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch (prop_type) {
case OFPPMPT_ETHERNET:
offset = dissect_openflow_portmod_prop_ethernet_v6(tvb, pinfo, prop_tree, offset, length);
break;
case OFPPMPT_OPTICAL:
offset = dissect_openflow_portmod_prop_optical_v6(tvb, pinfo, prop_tree, offset, length);
break;
case OFPPMPT_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_portmod_prop_undecoded,
tvb, offset, prop_length - 12, "Experimenter port desc. property.");
offset += prop_length - 12;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_portmod_prop_undecoded,
tvb, offset, prop_length - 4, "Unknown port desc. property.");
offset += prop_length - 4;
break;
}
return offset;
}
static void
dissect_openflow_portmod_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *conf_tree, *mask_tree;
proto_tree_add_item(tree, hf_openflow_v6_portmod_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_pad, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_portmod_hw_addr, tvb, offset, OFP_ETH_ALEN, ENC_NA);
offset+=OFP_ETH_ALEN;
proto_tree_add_item(tree, hf_openflow_v6_portmod_pad2, tvb, offset, 2, ENC_NA);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_portmod_config, tvb, offset, 4, ENC_BIG_ENDIAN);
conf_tree = proto_item_add_subtree(ti, ett_openflow_v6_portmod_config);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_config_port_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_config_no_recv, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_config_no_fwd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_portmod_config_no_packet_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_portmod_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
mask_tree = proto_item_add_subtree(ti, ett_openflow_v6_portmod_mask);
proto_tree_add_item(mask_tree, hf_openflow_v6_portmod_mask_port_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mask_tree, hf_openflow_v6_portmod_mask_no_recv, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mask_tree, hf_openflow_v6_portmod_mask_no_fwd, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mask_tree, hf_openflow_v6_portmod_mask_no_packet_in, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < length) {
offset = dissect_openflow_portmod_prop_v6(tvb, pinfo, tree, offset, length);
}
}
static int
dissect_openflow_tablemod_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *prop_tree, *flags_tree;
guint16 prop_type;
guint16 prop_length;
prop_type = tvb_get_ntohs(tvb, offset);
prop_length = tvb_get_ntohs(tvb, offset + 2);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_length, ett_openflow_v6_tablemod_prop, NULL, "Tablemod property");
proto_tree_add_item(prop_tree, hf_openflow_v6_tablemod_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_tablemod_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch (prop_type) {
case OFPTMPT_EVICTION:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_tablemod_prop_eviction_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_tablemod_prop_eviction_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_tablemod_prop_eviction_flags_other, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_tablemod_prop_eviction_flags_importance, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_tablemod_prop_eviction_flags_lifetime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPTMPT_VACANCY:
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_vacancy_vacancy_down, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_vacancy_vacancy_up, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_vacancy_vacancy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_vacancy_pad, tvb, offset, 1, ENC_NA);
offset+=1;
break;
case OFPTMPT_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_tablemod_prop_undecoded,
tvb, offset, prop_length - 12, "Experimenter table mod. property.");
offset += prop_length - 12;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_tablemod_prop_undecoded,
tvb, offset, prop_length - 4, "Unknown table mod. property.");
offset += prop_length - 4;
break;
}
return offset;
}
static void
dissect_openflow_tablemod_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *conf_tree;
int save_offset;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_tablemod_pad, tvb, offset, 3, ENC_NA);
offset+=3;
ti = proto_tree_add_item(tree, hf_openflow_v6_tablemod_config, tvb, offset, 4, ENC_NA);
conf_tree = proto_item_add_subtree(ti, ett_openflow_v6_tablemod_config);
proto_tree_add_item(conf_tree, hf_openflow_v6_tablemod_config_eviction, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_tablemod_config_vacancy_events, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < length) {
save_offset = offset;
offset = dissect_openflow_tablemod_prop_v6(tvb, pinfo, tree, offset, length);
if (offset <= save_offset) {
break;
}
}
}
static void
dissect_openflow_flow_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_pad, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_out_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_out_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_pad2, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_flow_stats_request_cookie_mask, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
}
static void
dissect_openflow_aggregate_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_pad, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_out_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_out_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_pad2, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_request_cookie_mask, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
}
static int
dissect_openflow_table_feature_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *prop_tree, *elem_tree;
guint16 prop_type;
guint16 prop_length;
guint16 elem_begin;
gint32 body_end;
guint16 pad_length;
prop_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_table_feature_prop, &ti, "Table feature property");
prop_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
prop_length = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, prop_length);
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (prop_length < 4) {
prop_length = 4;
}
body_end = offset + prop_length - 4;
switch (prop_type) {
case OFPTFPT_INSTRUCTIONS:
case OFPTFPT_INSTRUCTIONS_MISS:
while (offset < body_end) {
elem_begin = offset;
elem_tree = proto_tree_add_subtree(prop_tree, tvb, offset, -1, ett_openflow_v6_table_feature_prop_instruction_id, &ti, "Instruction ID");
offset = dissect_openflow_instruction_header_v6(tvb, pinfo, elem_tree, offset, length);
proto_item_set_len(ti, offset - elem_begin);
}
break;
case OFPTFPT_NEXT_TABLES:
case OFPTFPT_NEXT_TABLES_MISS:
while (offset < body_end) {
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_next_tables_next_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
}
break;
case OFPTFPT_WRITE_ACTIONS:
case OFPTFPT_WRITE_ACTIONS_MISS:
case OFPTFPT_APPLY_ACTIONS:
case OFPTFPT_APPLY_ACTIONS_MISS:
while (offset < body_end) {
elem_begin = offset;
elem_tree = proto_tree_add_subtree(prop_tree, tvb, offset, -1, ett_openflow_v6_table_feature_prop_action_id, &ti, "Action ID");
offset = dissect_openflow_action_header_v6(tvb, pinfo, elem_tree, offset, length);
proto_item_set_len(ti, offset - elem_begin);
}
break;
case OFPTFPT_MATCH:
case OFPTFPT_WILDCARDS:
case OFPTFPT_WRITE_SETFIELD:
case OFPTFPT_WRITE_SETFIELD_MISS:
case OFPTFPT_APPLY_SETFIELD:
case OFPTFPT_APPLY_SETFIELD_MISS:
while (offset < body_end) {
elem_begin = offset;
elem_tree = proto_tree_add_subtree(prop_tree, tvb, offset, -1, ett_openflow_v6_table_feature_prop_oxm_id, &ti, "OXM ID");
offset = dissect_openflow_oxm_header_v6(tvb, pinfo, elem_tree, offset, length);
proto_item_set_len(ti, offset - elem_begin);
}
break;
case OFPTFPT_TABLE_SYNC_FROM:
while (offset < body_end) {
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_table_sync_from_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
}
break;
case OFPTFPT_EXPERIMENTER:
case OFPTFPT_EXPERIMENTER_MISS:
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_table_feature_prop_undecoded,
tvb, offset, body_end - offset, "Experimenter table property body.");
offset = body_end;
break;
default:
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_table_feature_prop_undecoded,
tvb, offset, body_end - offset, "Unknown table property body.");
offset = body_end;
break;
};
pad_length = (prop_length + 7)/8*8 - prop_length;
if (pad_length > 0) {
proto_tree_add_item(prop_tree, hf_openflow_v6_table_feature_prop_pad, tvb, offset, pad_length, ENC_NA);
offset+=pad_length;
}
return offset;
}
static int
dissect_openflow_table_features_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *feat_tree, *caps_tree;
guint16 feat_length;
gint32 feat_end;
feat_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_table_features, &ti, "Table features");
feat_length = tvb_get_ntohs(tvb, offset);
feat_end = offset + feat_length;
proto_item_set_len(ti, feat_length);
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_pad, tvb, offset, 5, ENC_NA);
offset+=5;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_name, tvb, offset, OFP_MAX_TABLE_NAME_LEN, ENC_ASCII|ENC_NA);
offset+=OFP_MAX_TABLE_NAME_LEN;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_metadata_match, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_metadata_write, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
ti = proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
caps_tree = proto_item_add_subtree(ti, ett_openflow_v6_table_features_capabilities);
proto_tree_add_item(caps_tree, hf_openflow_v6_table_features_capabilities_eviction, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_table_features_capabilities_vacancy_events, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(feat_tree, hf_openflow_v6_table_features_max_entries, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < feat_end) {
offset = dissect_openflow_table_feature_prop_v6(tvb, pinfo, feat_tree, offset, length);
}
return offset;
}
static void
dissect_openflow_port_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_port_stats_request_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_port_stats_request_pad, tvb, offset, 4, ENC_NA);
}
static void
dissect_openflow_queue_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_queue_stats_request_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_queue_stats_request_queue_id, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_group_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_group_stats_request_group_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_group_stats_request_pad, tvb, offset, 4, ENC_NA);
}
static void
dissect_openflow_meter_stats_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_meter_stats_request_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_meter_stats_request_pad, tvb, offset, 4, ENC_NA);
}
static void
dissect_openflow_meter_desc_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_meter_desc_request_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_meter_desc_request_pad, tvb, offset, 4, ENC_NA);
}
static void
dissect_openflow_queue_desc_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_queue_desc_request_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_queue_desc_request_queue_id, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_flow_monitor_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *flags_tree;
proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_monitor_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_out_port, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_out_group, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_flow_monitor_request_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_initial, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_add, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_removed, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_modify, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_instructions, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_no_abbrev, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_monitor_request_flags_only_own, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_flow_monitor_request_command, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
dissect_openflow_match_v6(tvb, pinfo, tree, offset, length);
}
static void
dissect_openflow_multipart_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *flags_tree;
guint16 type;
type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_multipart_request_type , tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_multipart_request_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_multipart_request_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_multipart_request_flags_more, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_multipart_request_pad, tvb, offset, 4, ENC_NA);
offset+=4;
switch(type){
case OFPMP_DESC:
break;
case OFPMP_FLOW:
dissect_openflow_flow_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_AGGREGATE:
dissect_openflow_aggregate_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_TABLE:
break;
case OFPMP_PORT_STATS:
dissect_openflow_port_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_QUEUE_STATS:
dissect_openflow_queue_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_GROUP:
dissect_openflow_group_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_GROUP_DESC:
break;
case OFPMP_GROUP_FEATURES:
break;
case OFPMP_METER:
dissect_openflow_meter_stats_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_METER_DESC:
dissect_openflow_meter_desc_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_METER_FEATURES:
break;
case OFPMP_TABLE_FEATURES:
while (offset < length) {
offset = dissect_openflow_table_features_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_PORT_DESC:
break;
case OFPMP_TABLE_DESC:
break;
case OFPMP_QUEUE_DESC:
dissect_openflow_queue_desc_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_FLOW_MONITOR:
dissect_openflow_flow_monitor_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_multipart_request_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_multipart_request_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (offset < length) {
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_multipart_request_undecoded,
tvb, offset, length - offset, "Experimenter multipart request body.");
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_multipart_request_undecoded,
tvb, offset, length - offset, "Unknown multipart request body.");
break;
}
}
static void
dissect_openflow_switch_description_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_switch_description_mfr_desc, tvb, offset, DESC_STR_LEN, ENC_ASCII|ENC_NA);
offset+=DESC_STR_LEN;
proto_tree_add_item(tree, hf_openflow_v6_switch_description_hw_desc, tvb, offset, DESC_STR_LEN, ENC_ASCII|ENC_NA);
offset+=DESC_STR_LEN;
proto_tree_add_item(tree, hf_openflow_v6_switch_description_sw_desc, tvb, offset, DESC_STR_LEN, ENC_ASCII|ENC_NA);
offset+=DESC_STR_LEN;
proto_tree_add_item(tree, hf_openflow_v6_switch_description_serial_num, tvb, offset, SERIAL_NUM_LEN, ENC_ASCII|ENC_NA);
offset+=SERIAL_NUM_LEN;
proto_tree_add_item(tree, hf_openflow_v6_switch_description_dp_desc, tvb, offset, DESC_STR_LEN, ENC_ASCII|ENC_NA);
}
static int
dissect_openflow_flow_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *stats_tree, *flags_tree;
guint16 stats_len;
gint32 stats_end;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_flow_stats, &ti, "Flow stats");
stats_len = tvb_get_ntohs(tvb, offset);
stats_end = offset + stats_len;
proto_item_set_len(ti, stats_len);
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_pad, tvb, offset, 1, ENC_NA);
offset+=1;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_idle_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_hard_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_flow_stats_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_stats_flags_send_flow_rem, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_stats_flags_check_overlap, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_stats_flags_reset_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_stats_flags_no_packet_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_flow_stats_flags_no_byte_counts, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_importance, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_pad2, tvb, offset, 4, ENC_NA);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_packet_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_byte_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
offset = dissect_openflow_match_v6(tvb, pinfo, stats_tree, offset, length);
while (offset < stats_end) {
offset = dissect_openflow_instruction_v6(tvb, pinfo, stats_tree, offset, length);
}
return offset;
}
static void
dissect_openflow_aggregate_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_packet_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_byte_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_flow_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_aggregate_stats_pad, tvb, offset, 4, ENC_NA);
}
static int
dissect_openflow_table_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *stats_tree;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_openflow_v6_table_stats, NULL, "Table stats");
proto_tree_add_item(stats_tree, hf_openflow_v6_table_stats_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(stats_tree, hf_openflow_v6_table_stats_pad, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(stats_tree, hf_openflow_v6_table_stats_active_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_table_stats_lookup_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_table_stats_match_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_openflow_port_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *stats_tree;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, 112, ett_openflow_v6_port_stats, NULL, "Port stats");
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_pad, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_packets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_tx_packets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_bytes, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_tx_bytes, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_dropped, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_tx_dropped, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_errors, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_tx_errors, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_frame_error, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_over_error, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_rx_crc_error, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_collisions, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_port_stats_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
return offset;
}
static int
dissect_openflow_table_desc_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *desc_tree, *conf_tree;
guint16 desc_length;
gint32 desc_end;
desc_length = tvb_get_ntohs(tvb, offset);
desc_end = offset + desc_length;
desc_tree = proto_tree_add_subtree(tree, tvb, offset, desc_length, ett_openflow_v6_table_desc, NULL, "Table desc");
proto_tree_add_item(desc_tree, hf_openflow_v6_table_desc_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(desc_tree, hf_openflow_v6_table_desc_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(desc_tree, hf_openflow_v6_table_desc_pad, tvb, offset, 1, ENC_NA);
offset+=1;
ti = proto_tree_add_item(desc_tree, hf_openflow_v6_table_desc_config, tvb, offset, 4, ENC_NA);
conf_tree = proto_item_add_subtree(ti, ett_openflow_v6_table_desc_config);
proto_tree_add_item(conf_tree, hf_openflow_v6_table_desc_config_eviction, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conf_tree, hf_openflow_v6_table_desc_config_vacancy_events, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < desc_end) {
offset = dissect_openflow_tablemod_prop_v6(tvb, pinfo, desc_tree, offset, length);
}
return offset;
}
static int
dissect_openflow_queue_stats_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *prop_tree;
guint16 prop_type;
guint16 prop_length;
prop_type = tvb_get_ntohs(tvb, offset);
prop_length = tvb_get_ntohs(tvb, offset + 2);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_length, ett_openflow_v6_queue_stats_prop, NULL, "Queue stats property");
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_stats_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_stats_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
switch (prop_type) {
case OFPMP_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_queue_stats_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_queue_stats_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_queue_stats_prop_undecoded,
tvb, offset, length - 12, "Experimenter queue stats prop body.");
offset += prop_length - 12;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_queue_stats_prop_undecoded,
tvb, offset, length - 4, "Unknown queue stats prop body.");
offset += prop_length - 4;
break;
}
return offset;
}
static int
dissect_openflow_queue_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *stats_tree;
guint16 stats_len;
gint32 stats_end;
stats_len = tvb_get_ntohs(tvb, offset);
stats_end = offset + stats_len;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, stats_len, ett_openflow_v6_queue_stats, NULL, "Queue stats");
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_pad, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_queue_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_tx_bytes, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_tx_packets, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_tx_errors, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_queue_stats_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < stats_end) {
offset = dissect_openflow_queue_stats_prop_v6(tvb, pinfo, stats_tree, offset, length);
}
return offset;
}
static int
dissect_openflow_bucket_counter_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *counter_tree;
counter_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_openflow_v6_bucket_counter, NULL, "Bucket counter");
proto_tree_add_item(counter_tree, hf_openflow_v6_bucket_counter_packet_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(counter_tree, hf_openflow_v6_bucket_counter_byte_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_openflow_group_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *stats_tree;
guint16 stats_len;
gint32 stats_end;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_group_stats, &ti, "Group stats");
stats_len = tvb_get_ntohs(tvb, offset);
stats_end = offset + stats_len;
proto_item_set_len(ti, stats_len);
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_pad, tvb, offset, 2, ENC_NA);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_group_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_ref_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_pad2, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_packet_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_group_stats_byte_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_flow_stats_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < stats_end) {
offset = dissect_openflow_bucket_counter_v6(tvb, pinfo, stats_tree, offset, length);
}
return offset;
}
static int
dissect_openflow_group_desc_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *desc_tree;
guint16 desc_len;
gint32 desc_end;
desc_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_group_desc, &ti, "Group description");
desc_len = tvb_get_ntohs(tvb, offset);
desc_end = offset + desc_len;
proto_item_set_len(ti, desc_len);
proto_tree_add_item(desc_tree, hf_openflow_v6_group_desc_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(desc_tree, hf_openflow_v6_group_desc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(desc_tree, hf_openflow_v6_group_desc_pad, tvb, offset, 1, ENC_NA);
offset+=1;
proto_tree_add_item(desc_tree, hf_openflow_v6_group_desc_group_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < desc_end) {
offset = dissect_openflow_bucket_v6(tvb, pinfo, desc_tree, offset, length);
}
return offset;
}
static void
dissect_openflow_group_features_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *types_tree, *caps_tree, *acts_tree;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_types, tvb, offset, 4, ENC_BIG_ENDIAN);
types_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_types);
proto_tree_add_item(types_tree, hf_openflow_v6_group_features_types_all, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(types_tree, hf_openflow_v6_group_features_types_select, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(types_tree, hf_openflow_v6_group_features_types_indirect, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(types_tree, hf_openflow_v6_group_features_types_ff, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
caps_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_capabilities);
proto_tree_add_item(caps_tree, hf_openflow_v6_group_features_capabilities_select_weight, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_group_features_capabilities_select_liveness, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_group_features_capabilities_chaining, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_group_features_capabilities_chaining_checks, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_group_features_max_groups_all, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_group_features_max_groups_select, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_group_features_max_groups_indirect, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_group_features_max_groups_ff, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_actions_all, tvb, offset, 4, ENC_BIG_ENDIAN);
acts_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_actions_all);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_output, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_copy_ttl_out, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_copy_ttl_in, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_set_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_dec_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_push_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_pop_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_push_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_pop_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_set_queue, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_group, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_set_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_dec_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_set_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_push_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_pop_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_copy_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_all_meter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_actions_select, tvb, offset, 4, ENC_BIG_ENDIAN);
acts_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_actions_select);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_output, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_copy_ttl_out, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_copy_ttl_in, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_set_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_dec_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_push_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_pop_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_push_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_pop_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_set_queue, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_group, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_set_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_dec_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_set_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_push_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_pop_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_copy_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_select_meter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_actions_indirect, tvb, offset, 4, ENC_BIG_ENDIAN);
acts_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_actions_indirect);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_output, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_copy_ttl_out, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_copy_ttl_in, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_set_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_dec_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_push_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_pop_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_push_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_pop_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_set_queue, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_group, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_set_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_dec_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_set_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_push_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_pop_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_copy_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_indirect_meter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_group_features_actions_ff, tvb, offset, 4, ENC_BIG_ENDIAN);
acts_tree = proto_item_add_subtree(ti, ett_openflow_v6_group_features_actions_ff);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_output, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_copy_ttl_out, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_copy_ttl_in, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_set_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_dec_mpls_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_push_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_pop_vlan, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_push_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_pop_mpls, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_set_queue, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_group, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_set_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_dec_nw_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_set_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_push_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_pop_pbb, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_copy_field, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(acts_tree, hf_openflow_v6_group_features_actions_ff_meter, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static int
dissect_openflow_meter_band_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *stats_tree;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_openflow_v6_meter_band_stats, NULL, "Meter band stats");
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_band_stats_packet_band_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_band_stats_byte_band_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
return offset;
}
static int
dissect_openflow_meter_stats_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *stats_tree;
guint16 stats_len;
guint16 stats_end;
stats_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_meter_stats, &ti, "Meter stats");
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
stats_len = tvb_get_ntohs(tvb, offset);
stats_end = offset - 4 + stats_len;
proto_item_set_len(ti, stats_len);
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_pad, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_flow_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_packet_in_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_byte_in_count, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_duration_sec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(stats_tree, hf_openflow_v6_meter_stats_duration_nsec, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < stats_end) {
offset = dissect_openflow_meter_band_stats_v6(tvb, pinfo, stats_tree, offset, length);
}
return offset;
}
static int
dissect_openflow_meter_desc_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *conf_tree, *flags_tree;
guint16 config_len;
gint32 config_end;
conf_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_meter_desc, &ti, "Meter desc");
config_len = tvb_get_ntohs(tvb, offset);
config_end = offset + config_len;
proto_item_set_len(ti, config_len);
proto_tree_add_item(conf_tree, hf_openflow_v6_meter_desc_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(conf_tree, hf_openflow_v6_meter_desc_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_meter_desc_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_meter_desc_flags_kbps, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_meter_desc_flags_pktps, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_meter_desc_flags_burst, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_meter_desc_flags_stats, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(conf_tree, hf_openflow_v6_meter_desc_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < config_end) {
offset = dissect_openflow_meter_band_v6(tvb, pinfo, conf_tree, offset, length);
}
return offset;
}
static void
dissect_openflow_meter_features_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *bands_tree, *caps_tree;
proto_tree_add_item(tree, hf_openflow_v6_meter_features_max_meter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_meter_features_band_types, tvb, offset, 4, ENC_BIG_ENDIAN);
bands_tree = proto_item_add_subtree(ti, ett_openflow_v6_meter_features_band_types);
proto_tree_add_item(bands_tree, hf_openflow_v6_meter_features_band_types_drop, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(bands_tree, hf_openflow_v6_meter_features_band_types_dscp_remark, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
ti = proto_tree_add_item(tree, hf_openflow_v6_meter_features_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
caps_tree = proto_item_add_subtree(ti, ett_openflow_v6_meter_features_capabilities);
proto_tree_add_item(caps_tree, hf_openflow_v6_meter_features_capabilities_kbps, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_meter_features_capabilities_pktps, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_meter_features_capabilities_burst, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(caps_tree, hf_openflow_v6_meter_features_capabilities_stats, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_meter_features_max_bands, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_meter_features_max_color, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_meter_features_pad, tvb, offset, 2, ENC_NA);
}
static int
dissect_openflow_queue_desc_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *prop_tree;
guint16 prop_type;
guint16 prop_len;
prop_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_queue_desc_prop, &ti, "Queue property");
prop_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_property, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
prop_len = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, prop_len);
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_pad, tvb, offset, 4, ENC_NA);
offset+=4;
if (prop_len < 8) {
expert_add_info(pinfo, ti, &ei_openflow_v6_length_too_short);
return offset;
}
switch (prop_type) {
case OFPQDPT_MIN_RATE:
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_min_rate_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_min_rate_pad, tvb, offset, 6, ENC_NA);
offset+=6;
break;
case OFPQDPT_MAX_RATE:
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_max_rate_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_max_rate_pad, tvb, offset, 6, ENC_NA);
offset+=6;
break;
case OFPQDPT_EXPERIMENTER:
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(prop_tree, hf_openflow_v6_queue_desc_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_queue_desc_prop_undecoded,
tvb, offset, prop_len - 16, "Experimenter queue property body.");
offset+=prop_len-16;
break;
default:
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_queue_desc_prop_undecoded,
tvb, offset, prop_len - 8, "Unknown queue property body.");
offset+=prop_len-8;
break;
}
return offset;
}
static int
dissect_openflow_queue_desc_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *desc_tree;
guint16 desc_len;
gint32 desc_end;
desc_len = tvb_get_ntohs(tvb, offset + 8);
desc_end = offset + desc_len;
desc_tree = proto_tree_add_subtree(tree, tvb, offset, desc_len, ett_openflow_v6_queue_desc, NULL, "Queue desc");
proto_tree_add_item(tree, hf_openflow_v6_queue_desc_port_no, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(desc_tree, hf_openflow_v6_queue_desc_queue_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(desc_tree, hf_openflow_v6_queue_desc_len, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(desc_tree, hf_openflow_v6_queue_desc_pad, tvb, offset, 6, ENC_NA);
offset+=6;
while (offset < desc_end) {
offset = dissect_openflow_queue_desc_prop_v6(tvb, pinfo, desc_tree, offset, length);
}
return offset;
}
static int
dissect_openflow_flow_update_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *update_tree;
guint16 update_len;
guint16 update_event;
gint32 update_end;
proto_item *ti;
update_len = tvb_get_ntohs(tvb, offset);
update_end = offset + update_len;
update_event = tvb_get_ntohs(tvb, offset + 2);
update_tree = proto_tree_add_subtree(tree, tvb, offset, update_len, ett_openflow_v6_flow_update, NULL, "Flow update");
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_event, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (update_len < 4) {
expert_add_info(pinfo, ti, &ei_openflow_v6_length_too_short);
return offset;
}
switch (update_event) {
case OFPFME_INITIAL:
case OFPFME_ADDED:
case OFPFME_REMOVED:
case OFPFME_MODIFIED:
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (update_event == OFPFME_REMOVED) {
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_zero, tvb, offset, 1, ENC_NA);
}
offset+=1;
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_idle_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_hard_timeout, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_priority, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_zeros, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_full_cookie, tvb, offset, 8, ENC_BIG_ENDIAN);
offset+=8;
offset = dissect_openflow_match_v6(tvb, pinfo, update_tree, offset, length);
while (offset < update_end) {
offset = dissect_openflow_instruction_v6(tvb, pinfo, update_tree, offset, length);
}
break;
case OFPFME_ABBREV:
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_abbrev_xid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPFME_PAUSED:
case OFPFME_RESUMED:
proto_tree_add_item(update_tree, hf_openflow_v6_flow_update_paused_zeros, tvb, offset, 4, ENC_NA);
offset+=4;
break;
default:
proto_tree_add_expert_format(update_tree, pinfo, &ei_openflow_v6_flow_update_undecoded,
tvb, offset, update_len - 4, "Unknown flow update body.");
offset+=update_len-4;
break;
}
return offset;
}
static void
dissect_openflow_multipart_reply_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length)
{
proto_item *ti;
proto_tree *flags_tree;
guint16 type;
type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_openflow_v6_multipart_reply_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_multipart_reply_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_multipart_reply_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_multipart_reply_flags_more, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_multipart_reply_pad, tvb, offset, 4, ENC_NA);
offset+=4;
switch(type){
case OFPMP_DESC:
dissect_openflow_switch_description_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_FLOW:
while (offset < length) {
offset = dissect_openflow_flow_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_AGGREGATE:
dissect_openflow_aggregate_stats_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_TABLE:
while (offset < length) {
offset = dissect_openflow_table_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_PORT_STATS:
while (offset < length) {
offset = dissect_openflow_port_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_QUEUE_STATS:
while (offset < length) {
offset = dissect_openflow_queue_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_GROUP:
while (offset < length) {
offset = dissect_openflow_group_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_GROUP_DESC:
while (offset < length) {
offset = dissect_openflow_group_desc_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_GROUP_FEATURES:
dissect_openflow_group_features_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_METER:
while (offset < length) {
offset = dissect_openflow_meter_stats_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_METER_DESC:
while (offset < length) {
offset = dissect_openflow_meter_desc_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_METER_FEATURES:
dissect_openflow_meter_features_v6(tvb, pinfo, tree, offset, length);
break;
case OFPMP_TABLE_FEATURES:
while (offset < length) {
offset = dissect_openflow_table_features_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_PORT_DESC:
while (offset < length) {
offset = dissect_openflow_port_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_TABLE_DESC:
while (offset < length) {
offset = dissect_openflow_table_desc_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_QUEUE_DESC:
while (offset < length) {
offset = dissect_openflow_queue_desc_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_FLOW_MONITOR:
while (offset < length) {
offset = dissect_openflow_flow_update_v6(tvb, pinfo, tree, offset, length);
}
break;
case OFPMP_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_multipart_reply_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_multipart_reply_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_multipart_reply_undecoded,
tvb, offset, length - 16, "Experimenter multipart reply body.");
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_multipart_reply_undecoded,
tvb, offset, length - 8, "Unknown multipart reply body.");
break;
}
}
static void
dissect_openflow_role_request_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_role_request_role, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_role_request_pad, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_role_request_generation_id, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_role_reply_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_role_reply_role, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_role_reply_pad, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_role_reply_generation_id, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static int
dissect_openflow_async_config_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *prop_tree, *pi_tree, *ps_tree, *fr_tree, *rs_tree, *ts_tree, *rf_tree;
guint16 prop_type;
guint16 prop_len;
prop_type = tvb_get_ntohs(tvb, offset);
prop_len = tvb_get_ntohs(tvb, offset + 2);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_len, ett_openflow_v6_async_config_prop, NULL, "Async config prop");
proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (prop_type) {
case OFPACPT_PACKET_IN_SLAVE:
case OFPACPT_PACKET_IN_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
pi_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_packet_in_mask);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_table_miss, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_apply_action, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_invalid_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_action_set, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_group, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pi_tree, hf_openflow_v6_async_config_prop_reason_packet_in_mask_packet_out, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_PORT_STATUS_SLAVE:
case OFPACPT_PORT_STATUS_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_port_status_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
ps_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_port_status_mask);
proto_tree_add_item(ps_tree, hf_openflow_v6_async_config_prop_reason_port_status_mask_add, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ps_tree, hf_openflow_v6_async_config_prop_reason_port_status_mask_delete, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ps_tree, hf_openflow_v6_async_config_prop_reason_port_status_mask_modify, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_FLOW_REMOVED_SLAVE:
case OFPACPT_FLOW_REMOVED_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
fr_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_flow_removed_mask);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_idle_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_hard_timeout, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_delete, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_group_delete, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_meter_delete, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(fr_tree, hf_openflow_v6_async_config_prop_reason_flow_removed_mask_eviction, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_ROLE_STATUS_SLAVE:
case OFPACPT_ROLE_STATUS_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_role_status_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
rs_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_role_status_mask);
proto_tree_add_item(rs_tree, hf_openflow_v6_async_config_prop_reason_role_status_mask_master_request, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rs_tree, hf_openflow_v6_async_config_prop_reason_role_status_mask_config, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rs_tree, hf_openflow_v6_async_config_prop_reason_role_status_mask_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_TABLE_STATUS_SLAVE:
case OFPACPT_TABLE_STATUS_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_table_status_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
ts_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_table_status_mask);
proto_tree_add_item(ts_tree, hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_down, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ts_tree, hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_up, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_REQUESTFORWARD_SLAVE:
case OFPACPT_REQUESTFORWARD_MASTER:
ti = proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_reason_requestforward_mask, tvb, offset, 4, ENC_BIG_ENDIAN);
rf_tree = proto_item_add_subtree(ti, ett_openflow_v6_async_config_prop_reason_requestforward_mask);
proto_tree_add_item(rf_tree, hf_openflow_v6_async_config_prop_reason_requestforward_mask_group_mod, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rf_tree, hf_openflow_v6_async_config_prop_reason_requestforward_mask_meter_mod, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
case OFPACPT_EXPERIMENTER_SLAVE:
case OFPACPT_EXPERIMENTER_MASTER:
proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(prop_tree, hf_openflow_v6_async_config_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_async_config_prop_undecoded,
tvb, offset, prop_len - 12, "Experimenter async config prop body.");
offset += prop_len - 12;
break;
default:
proto_tree_add_expert_format(prop_tree, pinfo, &ei_openflow_v6_async_config_prop_undecoded,
tvb, offset, prop_len - 4, "Unknown async config prop body.");
offset += prop_len - 4;
break;
}
return offset;
}
static void
dissect_openflow_async_config_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
while (offset < length) {
offset = dissect_openflow_async_config_prop_v6(tvb, pinfo, tree, offset, length);
}
}
static void
dissect_openflow_metermod_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *flags_tree;
proto_tree_add_item(tree, hf_openflow_v6_metermod_command, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_metermod_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_metermod_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_metermod_flags_kbps, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_metermod_flags_pktps, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_metermod_flags_burst, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_metermod_flags_stats, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_openflow_v6_metermod_meter_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (offset < length) {
offset = dissect_openflow_meter_band_v6(tvb, pinfo, tree, offset, length);
}
}
static void
dissect_openflow_role_status_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_role_status_role, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_role_status_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_role_status_pad, tvb, offset, 3, ENC_NA);
offset+=3;
proto_tree_add_item(tree, hf_openflow_v6_role_status_generation_id, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static void
dissect_openflow_table_status_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree_add_item(tree, hf_openflow_v6_table_status_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(tree, hf_openflow_v6_table_status_pad, tvb, offset, 7, ENC_NA);
offset+=1;
dissect_openflow_table_desc_v6(tvb, pinfo, tree, offset, length);
}
static void
dissect_openflow_requestforward_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *req_tree;
guint16 req_begin;
req_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_requestforward_request, &ti, "Request");
req_begin = offset;
offset = dissect_openflow_message_v6(tvb, pinfo, req_tree, offset);
proto_item_set_len(ti, offset - req_begin);
}
static int
dissect_openflow_bundle_prop_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_tree *prop_tree;
guint16 prop_type;
guint16 prop_len;
prop_type = tvb_get_ntohs(tvb, offset);
prop_len = tvb_get_ntohs(tvb, offset + 2);
prop_tree = proto_tree_add_subtree(tree, tvb, offset, prop_len, ett_openflow_v6_bundle_prop, NULL, "Bundle prop");
proto_tree_add_item(prop_tree, hf_openflow_v6_bundle_prop_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(prop_tree, hf_openflow_v6_bundle_prop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
switch (prop_type) {
case OFPBPT_EXPERIMENTER:
proto_tree_add_item(tree, hf_openflow_v6_bundle_prop_experimenter_experimenter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_bundle_prop_experimenter_exp_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_bundle_prop_undecoded,
tvb, offset, prop_len - 12, "Experimenter bundle prop body.");
offset += prop_len - 12;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_bundle_prop_undecoded,
tvb, offset, prop_len - 4, "Unknown bundle prop body.");
offset += prop_len - 4;
break;
}
return offset;
}
static void
dissect_openflow_bundle_control_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *flags_tree;
proto_tree_add_item(tree, hf_openflow_v6_bundle_control_bundle_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_bundle_control_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_bundle_control_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_bundle_control_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_bundle_control_flags_atomic, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_bundle_control_flags_ordered, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
while (offset < length) {
offset = dissect_openflow_bundle_prop_v6(tvb, pinfo, tree, offset, length);
}
}
static void
dissect_openflow_bundle_add_v6(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint16 length _U_)
{
proto_item *ti;
proto_tree *flags_tree, *msg_tree;
guint16 msg_begin;
proto_tree_add_item(tree, hf_openflow_v6_bundle_add_bundle_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(tree, hf_openflow_v6_bundle_add_pad, tvb, offset, 2, ENC_NA);
offset+=2;
ti = proto_tree_add_item(tree, hf_openflow_v6_bundle_add_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_openflow_v6_bundle_add_flags);
proto_tree_add_item(flags_tree, hf_openflow_v6_bundle_add_flags_atomic, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_openflow_v6_bundle_add_flags_ordered, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
msg_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_openflow_v6_bundle_add_message, &ti, "Message");
msg_begin = offset;
offset = dissect_openflow_message_v6(tvb, pinfo, msg_tree, offset);
proto_item_set_len(ti, offset - msg_begin);
while (offset < length) {
offset = dissect_openflow_bundle_prop_v6(tvb, pinfo, tree, offset, length);
}
}
static int
dissect_openflow_message_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 type;
guint16 length;
gint32 msg_end;
type = tvb_get_guint8(tvb, offset + 1);
length = tvb_get_ntohs(tvb, offset + 2);
msg_end = offset + length;
offset = dissect_openflow_header_v6(tvb, pinfo, tree, offset, length);
switch(type) {
case OFPT_HELLO:
dissect_openflow_hello_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_ERROR:
dissect_openflow_error_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_ECHO_REQUEST:
case OFPT_ECHO_REPLY:
dissect_openflow_echo_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_EXPERIMENTER:
dissect_openflow_experimenter_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_FEATURES_REQUEST:
break;
case OFPT_FEATURES_REPLY:
dissect_openflow_switch_features_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_GET_CONFIG_REQUEST:
break;
case OFPT_GET_CONFIG_REPLY:
case OFPT_SET_CONFIG:
dissect_openflow_switch_config_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_PACKET_IN:
dissect_openflow_packet_in_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_FLOW_REMOVED:
dissect_openflow_flow_removed_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_PORT_STATUS:
dissect_openflow_port_status_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_PACKET_OUT:
dissect_openflow_packet_out_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_FLOW_MOD:
dissect_openflow_flowmod_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_GROUP_MOD:
dissect_openflow_groupmod_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_PORT_MOD:
dissect_openflow_portmod_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_TABLE_MOD:
dissect_openflow_tablemod_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_MULTIPART_REQUEST:
dissect_openflow_multipart_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_MULTIPART_REPLY:
dissect_openflow_multipart_reply_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_BARRIER_REQUEST:
case OFPT_BARRIER_REPLY:
break;
case OFPT_ROLE_REQUEST:
dissect_openflow_role_request_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_ROLE_REPLY:
dissect_openflow_role_reply_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_GET_ASYNC_REQUEST:
break;
case OFPT_GET_ASYNC_REPLY:
case OFPT_SET_ASYNC:
dissect_openflow_async_config_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_METER_MOD:
dissect_openflow_metermod_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_ROLE_STATUS:
dissect_openflow_role_status_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_TABLE_STATUS:
dissect_openflow_table_status_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_REQUESTFORWARD:
dissect_openflow_requestforward_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_BUNDLE_CONTROL:
dissect_openflow_bundle_control_v6(tvb, pinfo, tree, offset, length);
break;
case OFPT_BUNDLE_ADD_MESSAGE:
dissect_openflow_bundle_add_v6(tvb, pinfo, tree, offset, length);
break;
default:
if (length > 8) {
proto_tree_add_expert_format(tree, pinfo, &ei_openflow_v6_message_undecoded,
tvb, offset, length - 8, "Unknown message body.");
}
break;
}
return msg_end;
}
static int
dissect_openflow_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *openflow_tree;
guint8 type;
type = tvb_get_guint8(tvb, 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "Type: %s",
val_to_str_ext_const(type, &openflow_v6_type_values_ext, "Unknown message type"));
ti = proto_tree_add_item(tree, proto_openflow_v6, tvb, 0, -1, ENC_NA);
openflow_tree = proto_item_add_subtree(ti, ett_openflow_v6);
dissect_openflow_message_v6(tvb, pinfo, openflow_tree, 0);
return tvb_reported_length(tvb);
}
void
proto_register_openflow_v6(void)
{
static hf_register_info hf[] = {
{ &hf_openflow_v6_version,
{ "Version", "openflow_v6.version",
FT_UINT8, BASE_HEX, VALS(openflow_v6_version_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_type,
{ "Type", "openflow_v6.type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &openflow_v6_type_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_xid,
{ "Transaction ID", "openflow_v6.xid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_length,
{ "Length", "openflow_v6.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_class,
{ "Class", "openflow_v6.oxm.class",
FT_UINT16, BASE_HEX, VALS(openflow_v6_oxm_class_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_field,
{ "Field", "openflow_v6.oxm.field",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_field_basic,
{ "Field", "openflow_v6.oxm.field",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &openflow_v6_oxm_basic_field_values_ext, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_hm,
{ "Has mask", "openflow_v6.oxm.hm",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_length,
{ "Length", "openflow_v6.oxm.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_experimenter_experimenter,
{ "Experimenter", "openflow_v6.oxm_experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_experimenter_value,
{ "Experimenter Value", "openflow_v6.oxm_experimenter.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value,
{ "Value", "openflow_v6.oxm.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_etheraddr,
{ "Value", "openflow_v6.oxm.value_etheraddr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_ethertype,
{ "Value", "openflow_v6.oxm.value_ethertype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_vlan_present,
{ "OFPVID_PRESENT", "openflow_v6.oxm.value_vlan_present",
FT_BOOLEAN, 16, NULL, OFPVID_PRESENT,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_vlan_vid,
{ "Value", "openflow_v6.oxm.value_vlan_vid",
FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_ipv4addr,
{ "Value", "openflow_v6.oxm.value_ipv4addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_ipv6addr,
{ "Value", "openflow_v6.oxm.value_ipv6addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_ipproto,
{ "Value", "openflow_v6.oxm.value_ipproto",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_uint16,
{ "Value", "openflow_v6.oxm.value_uint16",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_uint24,
{ "Value", "openflow_v6.oxm.value_uint24",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_value_uint32,
{ "Value", "openflow_v6.oxm.value_uint32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_mask,
{ "Mask", "openflow_v6.oxm.mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_mask_etheraddr,
{ "Mask", "openflow_v6.oxm.ether_mask",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_mask_ipv4addr,
{ "Mask", "openflow_v6.oxm.ipv4_mask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_mask_ipv6addr,
{ "Mask", "openflow_v6.oxm.ipv6_mask",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_oxm_mask_vlan,
{ "Mask", "openflow_v6.oxm.vlan_mask",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_match_type,
{ "Type", "openflow_v6.match.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_match_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_match_length,
{ "Length", "openflow_v6.match.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_match_pad,
{ "Pad", "openflow_v6.match.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_type,
{ "Type", "openflow_v6.action.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_action_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_length,
{ "Length", "openflow_v6.action.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_experimenter_experimenter,
{ "Experimenter", "openflow_v6.action_experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_output_port,
{ "Port", "openflow_v6.action.output.port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_output_max_len,
{ "Max length", "openflow_v6.action.output.max_len",
FT_UINT16, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_controller_max_len_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_output_pad,
{ "Pad", "openflow_v6.action.output.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_ttl_out_pad,
{ "Pad", "openflow_v6.action.copy_ttl_out.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_ttl_in_pad,
{ "Pad", "openflow_v6.action.copy_ttl_in.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_mpls_ttl_ttl,
{ "TTL", "openflow_v6.action.set_mpls_ttl.ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_mpls_ttl_pad,
{ "Pad", "openflow_v6.action.set_mpls_ttl.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_dec_mpls_ttl_pad,
{ "Pad", "openflow_v6.action.dec_mpls_ttl.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_vlan_ethertype,
{ "Ethertype", "openflow_v6.action.push_vlan.ethertype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_vlan_pad,
{ "Pad", "openflow_v6.action.push_vlan.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_pop_vlan_pad,
{ "Pad", "openflow_v6.action.pop_vlan.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_mpls_ethertype,
{ "Ethertype", "openflow_v6.action.push_mpls.ethertype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_mpls_pad,
{ "Pad", "openflow_v6.action.push_mpls.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_pop_mpls_ethertype,
{ "Ethertype", "openflow_v6.action.pop_mpls.ethertype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_pop_mpls_pad,
{ "Pad", "openflow_v6.action.pop_mpls.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_queue_queue_id,
{ "Queue ID", "openflow_v6.action.set_queue.queue_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_group_group_id,
{ "Group ID", "openflow_v6.action.group.group_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_nw_ttl_ttl,
{ "TTL", "openflow_v6.action.set_nw_ttl.ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_nw_ttl_pad,
{ "Pad", "openflow_v6.action.set_nw_ttl.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_dec_nw_ttl_pad,
{ "Pad", "openflow_v6.action.dec_nw_ttl.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_set_field_pad,
{ "Pad", "openflow_v6.action.set_field.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_pbb_ethertype,
{ "Ethertype", "openflow_v6.action.push_pbb.ethertype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_push_pbb_pad,
{ "Pad", "openflow_v6.action.push_pbb.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_pop_pbb_pad,
{ "Pad", "openflow_v6.action.pop_pbb.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_field_n_bits,
{ "Number of bits", "openflow_v6.action.copy_field.n_bits",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_field_src_offset,
{ "Source Offset", "openflow_v6.action.copy_field.src_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_field_dst_offset,
{ "Destination Offset", "openflow_v6.action.copy_field.dst_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_copy_field_pad,
{ "Pad", "openflow_v6.action.copy_field.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_action_meter_id,
{ "Meter instance", "openflow_v6.action.meter.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_type,
{ "Type", "openflow_v6.instruction.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_instruction_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_length,
{ "Length", "openflow_v6.instruction.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_experimenter_experimenter,
{ "Experimenter", "openflow_v6.instruction_experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_goto_table_table_id,
{ "Table ID", "openflow_v6.instruction.goto_table.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_goto_table_pad,
{ "Pad", "openflow_v6.instruction.goto_table.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_write_metadata_pad,
{ "Pad", "openflow_v6.instruction.write_metadata.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_write_metadata_value,
{ "Value", "openflow_v6.instruction.write_metadata.value",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_write_metadata_mask,
{ "Mask", "openflow_v6.instruction.write_metadata.mask",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_actions_pad,
{ "Pad", "openflow_v6.instruction.actions.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_instruction_meter_meter_id,
{ "Meter ID", "openflow_v6.instruction.meter.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_type,
{ "Type", "openflow_v6.port.desc_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_port_desc_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_length,
{ "Length", "openflow_v6.port.desc_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_pad,
{ "Pad", "openflow_v6.port.desc_prop.ethernet.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current,
{ "Current", "openflow_v6.port.desc_prop.ethernet.current",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_10mb_hd,
{ "OFPPF_10MB_HD", "openflow_v6.port.desc_prop.ethernet.current.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_10mb_fd,
{ "OFPPF_10MB_FD", "openflow_v6.port.desc_prop.ethernet.current.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_100mb_hd,
{ "OFPPF_100MB_HD", "openflow_v6.port.desc_prop.ethernet.current.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_100mb_fd,
{ "OFPPF_100MB_FD", "openflow_v6.port.desc_prop.ethernet.current.100mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_1gb_hd,
{ "OFPPF_1GB_HD", "openflow_v6.port.desc_prop.ethernet.current.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_1gb_fd,
{ "OFPPF_1GB_FD", "openflow_v6.port.desc_prop.ethernet.current.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_10gb_fd,
{ "OFPPF_10_GB_FD", "openflow_v6.port.desc_prop.ethernet.current.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_40gb_fd,
{ "OFPPF_40GB_FD", "openflow_v6.port.desc_prop.ethernet.current.40gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_40GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_100gb_fd,
{ "OFPPF_100_GB_FD", "openflow_v6.port.desc_prop.ethernet.current.100_gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_1tb_fd,
{ "OFPPF_1TB_FD", "openflow_v6.port.desc_prop.ethernet.current.1tb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1TB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_other,
{ "OFPPF_OTHER", "openflow_v6.port.desc_prop.ethernet.current.other",
FT_BOOLEAN, 32, NULL, OFPPF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_copper,
{ "OFPPF_COPPER", "openflow_v6.port.desc_prop.ethernet.current.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_fiber,
{ "OFPPF_FIBER", "openflow_v6.port.desc_prop.ethernet.current.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_autoneg,
{ "OFPPF_AUTONEG", "openflow_v6.port.desc_prop.ethernet.current.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_pause,
{ "OFPPF_PAUSE", "openflow_v6.port.desc_prop.ethernet.current.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_pause_asym,
{ "OFPPF_PAUSE_ASYM", "openflow_v6.port.desc_prop.ethernet.current.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_current_reserved,
{ "Reserved", "openflow_v6.port.desc_prop.ethernet.current.reserved",
FT_UINT32, BASE_HEX, NULL, OFPPF_RESERVED,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised,
{ "Advertised", "openflow_v6.port.desc_prop.ethernet.advertised",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_10mb_hd,
{ "OFPPF_10MB_HD", "openflow_v6.port.desc_prop.ethernet.advertised.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_10mb_fd,
{ "OFPPF_10MB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_100mb_hd,
{ "OFPPF_100MB_HD", "openflow_v6.port.desc_prop.ethernet.advertised.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_100mb_fd,
{ "OFPPF_100MB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.100mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_1gb_hd,
{ "OFPPF_1GB_HD", "openflow_v6.port.desc_prop.ethernet.advertised.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_1gb_fd,
{ "OFPPF_1GB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_10gb_fd,
{ "OFPPF_10_GB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_40gb_fd,
{ "OFPPF_40GB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.40gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_40GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_100gb_fd,
{ "OFPPF_100GB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.100gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_1tb_fd,
{ "OFPPF_1TB_FD", "openflow_v6.port.desc_prop.ethernet.advertised.1tb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1TB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_other,
{ "OFPPF_OTHER", "openflow_v6.port.desc_prop.ethernet.advertised.other",
FT_BOOLEAN, 32, NULL, OFPPF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_copper,
{ "OFPPF_COPPER", "openflow_v6.port.desc_prop.ethernet.advertised.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_fiber,
{ "OFPPF_FIBER", "openflow_v6.port.desc_prop.ethernet.advertised.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_autoneg,
{ "OFPPF_AUTONEG", "openflow_v6.port.desc_prop.ethernet.advertised.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_pause,
{ "OFPPF_PAUSE", "openflow_v6.port.desc_prop.ethernet.advertised.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_pause_asym,
{ "OFPPF_PAUSE_ASYM", "openflow_v6.port.desc_prop.ethernet.advertised.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_advertised_reserved,
{ "Reserved", "openflow_v6.port.desc_prop.ethernet.advertised.reserved",
FT_UINT32, BASE_HEX, NULL, OFPPF_RESERVED,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported,
{ "Supported", "openflow_v6.port.desc_prop.ethernet.supported",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_10mb_hd,
{ "OFPPF_10MB_HD", "openflow_v6.port.desc_prop.ethernet.supported.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_10mb_fd,
{ "OFPPF_10MB_FD", "openflow_v6.port.desc_prop.ethernet.supported.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_100mb_hd,
{ "OFPPF_100MB_HD", "openflow_v6.port.desc_prop.ethernet.supported.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_100mb_fd,
{ "OFPPF_100MB_FD", "openflow_v6.port.desc_prop.ethernet.supported.100mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_1gb_hd,
{ "OFPPF_1GB_HD", "openflow_v6.port.desc_prop.ethernet.supported.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_1gb_fd,
{ "OFPPF_1GB_FD", "openflow_v6.port.desc_prop.ethernet.supported.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_10gb_fd,
{ "OFPPF_10_GB_FD", "openflow_v6.port.desc_prop.ethernet.supported.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_40gb_fd,
{ "OFPPF_40GB_FD", "openflow_v6.port.desc_prop.ethernet.supported.40gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_40GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_100gb_fd,
{ "OFPPF_100GB_FD", "openflow_v6.port.desc_prop.ethernet.supported.100gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_1tb_fd,
{ "OFPPF_1TB_FD", "openflow_v6.port.desc_prop.ethernet.supported.1tb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1TB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_other,
{ "OFPPF_OTHER", "openflow_v6.port.desc_prop.ethernet.supported.other",
FT_BOOLEAN, 32, NULL, OFPPF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_copper,
{ "OFPPF_COPPER", "openflow_v6.port.desc_prop.ethernet.supported.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_fiber,
{ "OFPPF_FIBER", "openflow_v6.port.desc_prop.ethernet.supported.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_autoneg,
{ "OFPPF_AUTONEG", "openflow_v6.port.desc_prop.ethernet.supported.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_pause,
{ "OFPPF_PAUSE", "openflow_v6.port.desc_prop.ethernet.supported.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_pause_asym,
{ "OFPPF_PAUSE_ASYM", "openflow_v6.port.desc_prop.ethernet.supported.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_supported_reserved,
{ "Reserved", "openflow_v6.port.desc_prop.ethernet.supported.reserved",
FT_UINT32, BASE_HEX, NULL, OFPPF_RESERVED,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer,
{ "Peer", "openflow_v6.port.desc_prop.ethernet.peer",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_10mb_hd,
{ "OFPPF_10MB_HD", "openflow_v6.port.desc_prop.ethernet.peer.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_10mb_fd,
{ "OFPPF_10MB_FD", "openflow_v6.port.desc_prop.ethernet.peer.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_100mb_hd,
{ "OFPPF_100MB_HD", "openflow_v6.port.desc_prop.ethernet.peer.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_100mb_fd,
{ "OFPPF_100MB_FD", "openflow_v6.port.desc_prop.ethernet.peer.100mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_1gb_hd,
{ "OFPPF_1GB_HD", "openflow_v6.port.desc_prop.ethernet.peer.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_1gb_fd,
{ "OFPPF_1GB_FD", "openflow_v6.port.desc_prop.ethernet.peer.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_10gb_fd,
{ "OFPPF_10_GB_FD", "openflow_v6.port.desc_prop.ethernet.peer.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_40gb_fd,
{ "OFPPF_40GB_FD", "openflow_v6.port.desc_prop.ethernet.peer.40gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_40GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_100gb_fd,
{ "OFPPF_100GB_FD", "openflow_v6.port.desc_prop.ethernet.peer.100gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_1tb_fd,
{ "OFPPF_1TB_FD", "openflow_v6.port.desc_prop.ethernet.peer.1tb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1TB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_other,
{ "OFPPF_OTHER", "openflow_v6.port.desc_prop.ethernet.peer.other",
FT_BOOLEAN, 32, NULL, OFPPF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_copper,
{ "OFPPF_COPPER", "openflow_v6.port.desc_prop.ethernet.peer.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_fiber,
{ "OFPPF_FIBER", "openflow_v6.port.desc_prop.ethernet.peer.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_autoneg,
{ "OFPPF_AUTONEG", "openflow_v6.port.desc_prop.ethernet.peer.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_pause,
{ "OFPPF_PAUSE", "openflow_v6.port.desc_prop.ethernet.peer.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_pause_asym,
{ "OFPPF_PAUSE_ASYM", "openflow_v6.port.desc_prop.ethernet.peer.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_peer_reserved,
{ "Reserved", "openflow_v6.port.desc_prop.ethernet.peer.reserved",
FT_UINT32, BASE_HEX, NULL, OFPPF_RESERVED,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_curr_speed,
{ "Curr speed", "openflow_v6.port.desc_prop.ethernet.curr_speed",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_ethernet_max_speed,
{ "Max speed", "openflow_v6.port.desc_prop.ethernet.max_speed",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_pad,
{ "Pad", "openflow_v6.port.desc_prop.optical.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_supported,
{ "Supported", "openflow_v6.port.desc_prop.optical.supported",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_supported_rx_tune,
{ "OFPOPF_RX_TUNE", "openflow_v6.port.desc_prop.optical.supported.rx_tune",
FT_UINT32, BASE_HEX, NULL, OFPOPF_RX_TUNE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_supported_tx_tune,
{ "OFPOPF_TX_TUNE", "openflow_v6.port.desc_prop.optical.supported.tx_tune",
FT_UINT32, BASE_HEX, NULL, OFPOPF_TX_TUNE,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_supported_tx_pwr,
{ "OFPOPF_TX_PWR", "openflow_v6.port.desc_prop.optical.supported.tx_pwr",
FT_UINT32, BASE_HEX, NULL, OFPOPF_TX_PWR,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_supported_use_freq,
{ "OFPOPF_USE_FREQ", "openflow_v6.port.desc_prop.optical.supported.use_freq",
FT_UINT32, BASE_HEX, NULL, OFPOPF_USE_FREQ,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_tx_min_freq_lmda,
{ "Tx. Min. Freq. Lambda", "openflow_v6.port.desc_prop.optical.tx_min_freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_tx_max_freq_lmda,
{ "Tx. Max. Freq. Lambda", "openflow_v6.port.desc_prop.optical.tx_max_freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_tx_grid_freq_lmda,
{ "Tx. Grid Freq. Lambda", "openflow_v6.port.desc_prop.optical.tx_grid_freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_rx_min_freq_lmda,
{ "Rx. Min. Freq. Lambda", "openflow_v6.port.desc_prop.optical.rx_min_freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_rx_max_freq_lmda,
{ "Rx. Max. Freq Lambda", "openflow_v6.port.desc_prop.optical.rx_max_freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_rx_grid_freq_lmda,
{ "Rx. Grid Freq. Lambda", "openflow_v6.port.desc_prop.optical.rx_grid_freq_lambda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_tx_pwr_min,
{ "Tx. Power Min.", "openflow_v6.port.desc_prop.optical.tx_pwr_min",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_optical_tx_pwr_max,
{ "Tx. Power Max.", "openflow_v6.port.desc_prop.optical.tx_pwr_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.port_desc_prop.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_desc_prop_experimenter_exp_type,
{ "Exp. type", "openflow_v6.port_desc_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_port_no,
{ "Port no", "openflow_v6.port.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_pad,
{ "Pad", "openflow_v6.port.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_length,
{ "Pad", "openflow_v6.port.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_hw_addr,
{ "Hw addr", "openflow_v6.port.hw_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_pad2,
{ "Pad", "openflow_v6.port.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_name,
{ "Name", "openflow_v6.port.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_config,
{ "Config", "openflow_v6.port.config",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_config_port_down,
{ "OFPPC_PORT_DOWN", "openflow_v6.port.config.port_down",
FT_BOOLEAN, 32, NULL, OFPPC_PORT_DOWN,
NULL, HFILL }
},
{ &hf_openflow_v6_port_config_no_recv,
{ "OFPPC_NO_RECV", "openflow_v6.port.config.no_recv",
FT_BOOLEAN, 32, NULL, OFPPC_NO_RECV,
NULL, HFILL }
},
{ &hf_openflow_v6_port_config_no_fwd,
{ "OFPPC_NO_FWD", "openflow_v6.port.config.no_fwd",
FT_BOOLEAN, 32, NULL, OFPPC_NO_FWD,
NULL, HFILL }
},
{ &hf_openflow_v6_port_config_no_packet_in,
{ "OFPPC_NO_PACKET_IN", "openflow_v6.port.config.no_packet_in",
FT_BOOLEAN, 32, NULL, OFPPC_NO_PACKET_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_port_state,
{ "State", "openflow_v6.port.sate",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_state_link_down,
{ "OFPPS_LINK_DOWN", "openflow_v6.port.state.link_down",
FT_BOOLEAN, 32, NULL, OFPPS_LINK_DOWN,
NULL, HFILL }
},
{ &hf_openflow_v6_port_state_blocked,
{ "OFPPS_BLOCKED", "openflow_v6.port.state.blocked",
FT_BOOLEAN, 32, NULL, OFPPS_BLOCKED,
NULL, HFILL }
},
{ &hf_openflow_v6_port_state_live,
{ "OFPPS_LIVE", "openflow_v6.port.state.live",
FT_BOOLEAN, 32, NULL, OFPPS_LIVE,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_type,
{ "Type", "openflow_v6.meter_band.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_meter_band_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_len,
{ "Length", "openflow_v6.meter_band.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_rate,
{ "Rate", "openflow_v6.meter_band.rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_burst_size,
{ "Burst size", "openflow_v6.meter_band.burst_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_drop_pad,
{ "Pad", "openflow_v6.meter_band.drop.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_dscp_remark_prec_level,
{ "Precedence level", "openflow_v6.meter_band.dscp_remark.prec_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_dscp_remark_pad,
{ "Pad", "openflow_v6.meter_band.dscp_remark.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_experimenter_experimenter,
{ "Experimenter", "openflow_v6.meter_band.experimenter.experimenter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_hello_element_type,
{ "Type", "openflow_v6.hello_element.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_hello_element_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_hello_element_length,
{ "Length", "openflow_v6.hello_element.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_hello_element_version_bitmap,
{ "Bitmap", "openflow_v6.hello_element.version.bitmap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_hello_element_pad,
{ "Pad", "openflow_v6.hello_element.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_type,
{ "Type", "openflow_v6.error.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_hello_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_hello_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bad_request_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bad_request_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bad_action_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bad_action_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bad_instruction_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bad_instruction_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bad_match_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bad_match_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_flow_mod_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_flow_mod_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_group_mod_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_group_mod_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_port_mod_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_port_mod_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_table_mod_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_table_mod_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_queue_op_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_queue_op_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_switch_config_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_switch_config_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_role_request_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_role_request_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_meter_mod_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_meter_mod_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_table_features_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_table_features_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bad_property_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bad_property_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_async_config_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_async_config_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_flow_monitor_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_flow_monitor_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_bundle_failed_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, VALS(openflow_v6_error_bundle_failed_code_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_code,
{ "Code", "openflow_v6.error.code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_data_text,
{ "Data", "openflow_v6.error.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_echo_data,
{ "Data", "openflow_v6.echo.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_data_body,
{ "Body", "openflow_v6.error.data.body",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_error_experimenter,
{ "Experimenter", "openflow_v6.error.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_experimenter_experimenter,
{ "Experimenter", "openflow_v6.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_experimenter_exp_type,
{ "Experimenter type", "openflow_v6.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_datapath_id,
{ "datapath_id", "openflow_v6.switch_features.datapath_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_n_buffers,
{ "n_buffers", "openflow_v6.switch_features.n_buffers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_n_tables,
{ "n_tables", "openflow_v6.switch_features.n_tables",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_auxiliary_id,
{ "auxiliary_id", "openflow_v6.switch_features.auxiliary_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_pad,
{ "Pad", "openflow_v6.switch_features.pad",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities,
{ "capabilities", "openflow_v6.switch_features.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_flow_stats,
{ "OFPC_FLOW_STATS", "openflow_v6.switch_features.capabilities.flow_stats",
FT_BOOLEAN, 32, NULL, OFPC_FLOW_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_table_stats,
{ "OFPC_TABLE_STATS", "openflow_v6.switch_features.capabilities.table_stats",
FT_BOOLEAN, 32, NULL, OFPC_TABLE_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_port_stats,
{ "OFPC_PORT_STATS", "openflow_v6.switch_features.capabilities.port_stats",
FT_BOOLEAN, 32, NULL, OFPC_PORT_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_group_stats,
{ "OFPC_GROUP_STATS", "openflow_v6.switch_features.capabilities.group_stats",
FT_BOOLEAN, 32, NULL, OFPC_GROUP_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_ip_reasm,
{ "OFPC_IP_REASM", "openflow_v6.switch_features.capabilities.ip_reasm",
FT_BOOLEAN, 32, NULL, OFPC_IP_REASM,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_queue_stats,
{ "OFPC_QUEUE_STATS", "openflow_v6.switch_features.capabilities.queue_stats",
FT_BOOLEAN, 32, NULL, OFPC_QUEUE_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_capabilities_port_blocked,
{ "OFPC_PORT_BLOCKED", "openflow_v6.switch_features.capabilities.port_blocked",
FT_BOOLEAN, 32, NULL, OFPC_PORT_BLOCKED,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_features_reserved,
{ "Reserved", "openflow_v6.switch_features_reserved",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_config_flags,
{ "Flags", "openflow_v6.switch_config.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_config_flags_fragments,
{ "IP Fragments", "openflow_v6.switch_config.flags.fragments",
FT_UINT16, BASE_DEC, VALS(openflow_v6_switch_config_fragments_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_config_miss_send_len,
{ "Miss send length", "openflow_v6.switch_config.miss_send_len",
FT_UINT16, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_controller_max_len_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_buffer_id,
{ "Buffer ID", "openflow_v6.packet_in.buffer_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_buffer_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_total_len,
{ "Total length", "openflow_v6.packet_in.total_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_reason,
{ "Reason", "openflow_v6.packet_in.reason",
FT_UINT8, BASE_DEC, VALS(openflow_v6_packet_in_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_table_id,
{ "Table ID", "openflow_v6.packet_in.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_cookie,
{ "Cookie", "openflow_v6.packet_in.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_in_pad,
{ "Pad", "openflow_v6.packet_in.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_cookie,
{ "Cookie", "openflow_v6.flow_removed.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_priority,
{ "Priority", "openflow_v6.flow_removed.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_reason,
{ "Reason", "openflow_v6.flow_removed.reason",
FT_UINT8, BASE_DEC, VALS(openflow_v6_flow_removed_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_table_id,
{ "Table ID", "openflow_v6.flow_removed.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_duration_sec,
{ "Duration sec", "openflow_v6.flow_removed.duration_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_duration_nsec,
{ "Duration nsec", "openflow_v6.flow_removed.duration_nsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_idle_timeout,
{ "Idle timeout", "openflow_v6.flow_removed.idle_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_hard_timeout,
{ "Hard timeout", "openflow_v6.flow_removed.hard_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_packet_count,
{ "Packet count", "openflow_v6.flow_removed.packet_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_removed_byte_count,
{ "Byte count", "openflow_v6.flow_removed.byte_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_status_reason,
{ "Reason", "openflow_v6.port_status.reason",
FT_UINT8, BASE_DEC, VALS(openflow_v6_port_status_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_status_pad,
{ "Pad", "openflow_v6.port_status.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_out_buffer_id,
{ "Buffer ID", "openflow_v6.packet_out.buffer_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_buffer_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_out_in_port,
{ "In port", "openflow_v6.packet_out.in_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_out_acts_len,
{ "Actions length", "openflow_v6.packet_out.acts_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_packet_out_pad,
{ "Pad", "openflow_v6.packet_out.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_cookie,
{ "Cookie", "openflow_v6.flowmod.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_cookie_mask,
{ "Cookie mask", "openflow_v6.flowmod.cookie_mask",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_table_id,
{ "Table ID", "openflow_v6.flowmod.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_command,
{ "Command", "openflow_v6.flowmod.command",
FT_UINT8, BASE_DEC, VALS(openflow_v6_flowmod_command_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_idle_timeout,
{ "Idle timeout", "openflow_v6.flowmod.idle_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_hard_timeout,
{ "Hard timeout", "openflow_v6.flowmod.hard_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_priority,
{ "Priority", "openflow_v6.flowmod.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_buffer_id,
{ "Buffer ID", "openflow_v6.flowmod.buffer_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_buffer_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_out_port,
{ "Out port", "openflow_v6.flowmod.out_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_out_group,
{ "Out group", "openflow_v6.flowmod.out_group",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags,
{ "Flags", "openflow_v6.flowmod.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags_send_flow_rem,
{ "Send flow removed", "openflow_v6.flowmod.flags.send_flow_rem",
FT_BOOLEAN, 16, NULL, OFPFF_SEND_FLOW_REM,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags_check_overlap,
{ "Check overlap", "openflow_v6.flowmod.flags.check_overlap",
FT_BOOLEAN, 16, NULL, OFPFF_CHECK_OVERLAP,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags_reset_counts,
{ "Reset counts", "openflow_v6.flowmod.flags.reset_counts",
FT_BOOLEAN, 16, NULL, OFPFF_RESET_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags_no_packet_counts,
{ "Don't count packets", "openflow_v6.flowmod.flags.no_packet_counts",
FT_BOOLEAN, 16, NULL, OFPFF_NO_PKT_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_flags_no_byte_counts,
{ "Don't count bytes", "openflow_v6.flowmod.flags.no_byte_counts",
FT_BOOLEAN, 16, NULL, OFPFF_NO_BYT_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flowmod_importance,
{ "Importance", "openflow_v6.flowmod.importance",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_length,
{ "Length", "openflow_v6.bucket.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_weight,
{ "Weight", "openflow_v6.bucket.weight",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_watch_port,
{ "Watch port", "openflow_v6.bucket.watch_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_watch_group,
{ "Watch group", "openflow_v6.bucket.watch_group",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_pad,
{ "Pad", "openflow_v6.bucket.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_command,
{ "Command", "openflow_v6.groupmod.command",
FT_UINT16, BASE_DEC, VALS(openflow_v6_groupmod_command_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_type,
{ "Type", "openflow_v6.groupmod.type",
FT_UINT8, BASE_DEC, VALS(openflow_v6_group_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_pad,
{ "Pad", "openflow_v6.groupmod.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_group_id,
{ "Group ID", "openflow_v6.groupmod.group_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_bucket_array_len,
{ "Bucket Array Len", "openflow_v6.groupmod.bucket_array_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_groupmod_command_bucket_id,
{ "Command Bucket id", "openflow_v6.groupmod.command_bucket_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_type,
{ "Type", "openflow_v6.portmod.prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_portmod_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_length,
{ "Length", "openflow_v6.portmod.prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise,
{ "Advertise", "openflow_v6.portmod.prop_ethernet.advertise",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_10mb_hd,
{ "OFPPF_10MB_HD", "openflow_v6.portmod.prop_ethernet.advertise.10mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_10mb_fd,
{ "OFPPF_10MB_FD", "openflow_v6.portmod.prop_ethernet.advertise.10mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_100mb_hd,
{ "OFPPF_100MB_HD", "openflow_v6.portmod.prop_ethernet.advertise.100mb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_100mb_fd,
{ "OFPPF_100MB_FD", "openflow_v6.portmod.prop_ethernet.advertise.100mb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100MB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_1gb_hd,
{ "OFPPF_1GB_HD", "openflow_v6.portmod.prop_ethernet.advertise.1gb_hd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_HD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_1gb_fd,
{ "OFPPF_1GB_FD", "openflow_v6.portmod.prop_ethernet.advertise.1gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_10gb_fd,
{ "OFPPF_10_GB_FD", "openflow_v6.portmod.prop_ethernet.advertise.10gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_10GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_40gb_fd,
{ "OFPPF_40GB_FD", "openflow_v6.portmod.prop_ethernet.advertise.40gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_40GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_100gb_fd,
{ "OFPPF_100_GB_FD", "openflow_v6.portmod.prop_ethernet.advertise.100_gb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_100GB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_1tb_fd,
{ "OFPPF_1TB_FD", "openflow_v6.portmod.prop_ethernet.advertise.1tb_fd",
FT_BOOLEAN, 32, NULL, OFPPF_1TB_FD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_other,
{ "OFPPF_OTHER", "openflow_v6.portmod.prop_ethernet.advertise.other",
FT_BOOLEAN, 32, NULL, OFPPF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_copper,
{ "OFPPF_COPPER", "openflow_v6.portmod.prop_ethernet.advertise.copper",
FT_BOOLEAN, 32, NULL, OFPPF_COPPER,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_fiber,
{ "OFPPF_FIBER", "openflow_v6.portmod.prop_ethernet.advertise.fiber",
FT_BOOLEAN, 32, NULL, OFPPF_FIBER,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_autoneg,
{ "OFPPF_AUTONEG", "openflow_v6.portmod.prop_ethernet.advertise.autoneg",
FT_BOOLEAN, 32, NULL, OFPPF_AUTONEG,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_pause,
{ "OFPPF_PAUSE", "openflow_v6.portmod.prop_ethernet.advertise.pause",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_ethernet_advertise_pause_asym,
{ "OFPPF_PAUSE_ASYM", "openflow_v6.portmod.prop_ethernet.advertise.pause_asym",
FT_BOOLEAN, 32, NULL, OFPPF_PAUSE_ASYM,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_configure,
{ "Configure", "openflow_v6.portmod.prop.optical.configure",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_configure_rx_tune,
{ "OFPOPF_RX_TUNE", "openflow_v6.portmod.prop.optical.configure.rx_tune",
FT_UINT32, BASE_HEX, NULL, OFPOPF_RX_TUNE,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_configure_tx_tune,
{ "OFPOPF_TX_TUNE", "openflow_v6.portmod.prop.optical.configure.tx_tune",
FT_UINT32, BASE_HEX, NULL, OFPOPF_TX_TUNE,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_configure_tx_pwr,
{ "OFPOPF_TX_PWR", "openflow_v6.portmod.prop.optical.configure.tx_pwr",
FT_UINT32, BASE_HEX, NULL, OFPOPF_TX_PWR,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_configure_use_freq,
{ "OFPOPF_USE_FREQ", "openflow_v6.portmod.prop.optical.configure.use_freq",
FT_UINT32, BASE_HEX, NULL, OFPOPF_USE_FREQ,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_freq_lmda,
{ "Freq. lambda", "openflow_v6.portmod.prop.optical.freq_lmda",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_fl_offset,
{ "Freq. offset", "openflow_v6.portmod.prop.optical.fl_offset",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_grid_span,
{ "Grid span", "openflow_v6.portmod.prop.optical.grid_span",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_optical_tx_pwr,
{ "Tx power", "openflow_v6.portmod.prop.optical.tx_pwr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.portmod.prop.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_prop_experimenter_exp_type,
{ "Exp. type", "openflow_v6.portmod.prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_port_no,
{ "Port no", "openflow_v6.portmod.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_pad,
{ "Pad", "openflow_v6.portmod.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_hw_addr,
{ "Hw addr", "openflow_v6.portmod.hw_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_pad2,
{ "Pad", "openflow_v6.portmod.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_config,
{ "Config", "openflow_v6.portmod.config",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_config_port_down,
{ "OFPPC_PORT_DOWN", "openflow_v6.portmod.config.port_down",
FT_BOOLEAN, 32, NULL, OFPPC_PORT_DOWN,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_config_no_recv,
{ "OFPPC_NO_RECV", "openflow_v6.portmod.config.no_recv",
FT_BOOLEAN, 32, NULL, OFPPC_NO_RECV,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_config_no_fwd,
{ "OFPPC_NO_FWD", "openflow_v6.portmod.config.no_fwd",
FT_BOOLEAN, 32, NULL, OFPPC_NO_FWD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_config_no_packet_in,
{ "OFPPC_NO_PACKET_IN", "openflow_v6.portmod.config.no_packet_in",
FT_BOOLEAN, 32, NULL, OFPPC_NO_PACKET_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_mask,
{ "Mask", "openflow_v6.portmod.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_mask_port_down,
{ "OFPPC_PORT_DOWN", "openflow_v6.portmod.mask.port_down",
FT_BOOLEAN, 32, NULL, OFPPC_PORT_DOWN,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_mask_no_recv,
{ "OFPPC_NO_RECV", "openflow_v6.portmod.mask.no_recv",
FT_BOOLEAN, 32, NULL, OFPPC_NO_RECV,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_mask_no_fwd,
{ "OFPPC_NO_FWD", "openflow_v6.portmod.mask.no_fwd",
FT_BOOLEAN, 32, NULL, OFPPC_NO_FWD,
NULL, HFILL }
},
{ &hf_openflow_v6_portmod_mask_no_packet_in,
{ "OFPPC_NO_PACKET_IN", "openflow_v6.portmod.mask.no_packet_in",
FT_BOOLEAN, 32, NULL, OFPPC_NO_PACKET_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_table_id,
{ "Table ID", "openflow_v6.tablemod.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_pad,
{ "Pad", "openflow_v6.tablemod.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_config,
{ "Config", "openflow_v6.tablemod.config",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_config_eviction,
{ "OFPTC_EVICTION", "openflow_v6.tablemod.config.eviction",
FT_BOOLEAN, 32, NULL, OFPTC_EVICTION,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_config_vacancy_events,
{ "OFPTC_VACANCY_EVENTS", "openflow_v6.tablemod.config.vacancy_events",
FT_BOOLEAN, 32, NULL, OFPTC_VACANCY_EVENTS,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_type,
{ "Type", "openflow_v6.tablemod_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_tablemod_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_length,
{ "Length", "openflow_v6.tablemod_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_eviction_flags,
{ "Flags", "openflow_v6.tablemod.prop.eviction.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_eviction_flags_other,
{ "OFPTMPEF_OTHER", "openflow_v6.tablemod.prop.eviction.flags.other",
FT_BOOLEAN, 32, NULL, OFPTMPEF_OTHER,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_eviction_flags_importance,
{ "OFPTMPEF_IMPORTANCE", "openflow_v6.tablemod.prop.eviction.flags.importance",
FT_BOOLEAN, 32, NULL, OFPTMPEF_IMPORTANCE,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_eviction_flags_lifetime,
{ "OFPTMPEF_LIFETIME", "openflow_v6.tablemod.prop.eviction.flags.lifetime",
FT_BOOLEAN, 32, NULL, OFPTMPEF_LIFETIME,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_vacancy_vacancy_down,
{ "Vacancy down", "openflow_v6.tablemod.prop.vacancy.vacancy_down",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_vacancy_vacancy_up,
{ "Vacancy up", "openflow_v6.tablemod.prop.vacancy.vacancy_up",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_vacancy_vacancy,
{ "Vacancy", "openflow_v6.tablemod.prop.vacancy.vacancy",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_vacancy_pad,
{ "Pad", "openflow_v6.tablemod.prop.vacancy.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.tablemod.prop.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_tablemod_prop_experimenter_exp_type,
{ "Exp. type", "openflow_v6.tablemod.prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_table_id,
{ "Table ID", "openflow_v6.flow_stats_request.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_pad,
{ "Pad", "openflow_v6.flow_stats_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_out_port,
{ "Out port", "openflow_v6.flow_stats_request.out_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_out_group,
{ "Out group", "openflow_v6.flow_stats_request.out_group",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_pad2,
{ "Pad", "openflow_v6.flow_stats_request.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_cookie,
{ "Cookie", "openflow_v6.flow_stats_request.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_request_cookie_mask,
{ "Cookie mask", "openflow_v6.flow_stats_request.cookie_mask",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_table_id,
{ "Table ID", "openflow_v6.aggregate_stats_request.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_pad,
{ "Pad", "openflow_v6.aggregate_stats_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_out_port,
{ "Out port", "openflow_v6.aggregate_stats_request.out_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_out_group,
{ "Out group", "openflow_v6.aggregate_stats_request.out_group",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_pad2,
{ "Pad", "openflow_v6.aggregate_stats_request.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_cookie,
{ "Cookie", "openflow_v6.aggregate_stats_request.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_request_cookie_mask,
{ "Cookie mask", "openflow_v6.aggregate_stats_request.cookie_mask",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_type,
{ "Type", "openflow_v6.table_feature_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_table_feature_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_length,
{ "Length", "openflow_v6.table_feature_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_next_tables_next_table_id,
{ "Next table ID", "openflow_v6.table_feature_prop.next_tables.next_table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_table_sync_from_table_id,
{ "Sync table ID", "openflow_v6.table_feature_prop.table_sync_from.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.table_feature_prop.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_experimenter_exp_type,
{ "Experimenter type", "openflow_v6.table_feature_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_feature_prop_pad,
{ "Pad", "openflow_v6.table_feature_prop.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_length,
{ "Length", "openflow_v6.table_features.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_table_id,
{ "Table ID", "openflow_v6.table_features.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_pad,
{ "Pad", "openflow_v6.table_features.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_name,
{ "Name", "openflow_v6.table_features.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_metadata_match,
{ "Metadata match", "openflow_v6.table_features.metadata_match",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_metadata_write,
{ "Metadata write", "openflow_v6.table_features.metadata_write",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_capabilities,
{ "Capabilities", "openflow_v6.table_features.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_capabilities_eviction,
{ "OFPTC_EVICTION", "openflow_v6.table_features.capabilities.eviction",
FT_UINT32, BASE_HEX, NULL, OFPTC_EVICTION,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_capabilities_vacancy_events,
{ "OFPTC_VACANCY_EVENTS", "openflow_v6.table_features.capabilities.vacancy_events",
FT_UINT32, BASE_HEX, NULL, OFPTC_VACANCY_EVENTS,
NULL, HFILL }
},
{ &hf_openflow_v6_table_features_max_entries,
{ "Max entries", "openflow_v6.table_features.max_entries",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_request_port_no,
{ "Port number", "openflow_v6.port_stats_request.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_request_pad,
{ "Pad", "openflow_v6.port_stats_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_request_port_no,
{ "Port number", "openflow_v6.queue_stats_request.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_request_queue_id,
{ "Queue ID", "openflow_v6.queue_stats_request.queue_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_request_group_id,
{ "Group ID", "openflow_v6.group_stats_request.group_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_request_pad,
{ "Pad", "openflow_v6.group_stats_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_request_meter_id,
{ "Meter ID", "openflow_v6.meter_stats_request.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_request_pad,
{ "Pad", "openflow_v6.meter_stats_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_request_meter_id,
{ "Meter ID", "openflow_v6.meter_desc_request.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_request_pad,
{ "Pad", "openflow_v6.meter_desc.request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_request_port_no,
{ "Port number", "openflow_v6.queue_desc_request.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_request_queue_id,
{ "Queue ID", "openflow_v6.queue_desc_request.queue_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_monitor_id,
{ "Monitor ID", "openflow_v6.flow_monitor_request.monitor_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_out_port,
{ "Out port", "openflow_v6.flow_monitor_request.out_port",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_out_group,
{ "Out group", "openflow_v6.flow_monitor_request.out_group",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags,
{ "Flags", "openflow_v6.flow_monitor_request.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_initial,
{ "OFPFMF_INITIAL", "openflow_v6.flow_monitor_request.flags.initial",
FT_UINT16, BASE_HEX, NULL, OFPFMF_INITIAL,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_add,
{ "OFPFMF_ADD", "openflow_v6.flow_monitor_request.flags.add",
FT_UINT16, BASE_HEX, NULL, OFPFMF_ADD,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_removed,
{ "OFPFMF_REMOVED", "openflow_v6.flow_monitor_request.flags.removed",
FT_UINT16, BASE_HEX, NULL, OFPFMF_REMOVED,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_modify,
{ "OFPFMF_MODIFY", "openflow_v6.flow_monitor_request.flags.modify",
FT_UINT16, BASE_HEX, NULL, OFPFMF_MODIFY,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_instructions,
{ "OFPFMF_INSTRUCTIONS", "openflow_v6.flow_monitor_request.flags.instructions",
FT_UINT16, BASE_HEX, NULL, OFPFMF_INSTRUCTIONS,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_no_abbrev,
{ "OFPFMF_NO_ABBREV", "openflow_v6.flow_monitor_request.flags.no_abbrev",
FT_UINT16, BASE_HEX, NULL, OFPFMF_NO_ABBREV,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_flags_only_own,
{ "OFPFMF_ONLY_OWN", "openflow_v6.flow_monitor_request.flags.only_own",
FT_UINT16, BASE_HEX, NULL, OFPFMF_ONLY_OWN,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_table_id,
{ "Table ID", "openflow_v6.flow_monitor_request.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_monitor_request_command,
{ "Command", "openflow_v6.flow_monitor_request.command",
FT_UINT16, BASE_DEC, VALS(openflow_v6_flow_monitor_request_command_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_type,
{ "Type", "openflow_v6.multipart_request.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_multipart_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_flags,
{ "Flags", "openflow_v6.multipart_request.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_flags_more,
{ "OFPMPF_REQ_MORE", "openflow_v6.multipart_request.flags.more",
FT_UINT16, BASE_HEX, NULL, OFPMPF_REQ_MORE,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_pad,
{ "Pad", "openflow_v6.multipart_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_experimenter_experimenter,
{ "Experimenter", "openflow_v6.multipart_request.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_request_experimenter_exp_type,
{ "Experimenter type", "openflow_v6.multipart_request.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_description_mfr_desc,
{ "Manufacturer desc.", "openflow_v6.switch_description.mfr_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_description_hw_desc,
{ "Hardware desc.", "openflow_v6.switch_description.hw_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_description_sw_desc,
{ "Software desc.", "openflow_v6.switch_description.sw_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_description_serial_num,
{ "Serial no.", "openflow_v6.switch_description.serial_num",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_switch_description_dp_desc,
{ "Datapath desc.", "openflow_v6.switch_description.dp_desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_length,
{ "Length", "openflow_v6.flow_stats.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_table_id,
{ "Table ID", "openflow_v6.flow_stats.table_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_pad,
{ "Pad", "openflow_v6.flow_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_duration_sec,
{ "Duration sec", "openflow_v6.flow_stats.duration_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_duration_nsec,
{ "Duration nsec", "openflow_v6.flow_stats.duration_nsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_priority,
{ "Priority", "openflow_v6.flow_stats.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_idle_timeout,
{ "Idle timeout", "openflow_v6.flow_stats.idle_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_hard_timeout,
{ "Hard timeout", "openflow_v6.flow_stats.hard_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags,
{ "Flags", "openflow_v6.flow_stats.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags_send_flow_rem,
{ "Send flow removed", "openflow_v6.flow_stats.flags.send_flow_rem",
FT_BOOLEAN, 16, NULL, OFPFF_SEND_FLOW_REM,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags_check_overlap,
{ "Check overlap", "openflow_v6.flow_stats.flags.check_overlap",
FT_BOOLEAN, 16, NULL, OFPFF_CHECK_OVERLAP,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags_reset_counts,
{ "Reset counts", "openflow_v6.flow_stats.flags.reset_counts",
FT_BOOLEAN, 16, NULL, OFPFF_RESET_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags_no_packet_counts,
{ "Don't count packets", "openflow_v6.flow_stats.flags.no_packet_counts",
FT_BOOLEAN, 16, NULL, OFPFF_NO_PKT_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_flags_no_byte_counts,
{ "Don't count bytes", "openflow_v6.flow_stats.flags.no_byte_counts",
FT_BOOLEAN, 16, NULL, OFPFF_NO_BYT_COUNTS,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_importance,
{ "Importance", "openflow_v6.flow_stats.importance",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_pad2,
{ "Pad", "openflow_v6.flow_stats.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_cookie,
{ "Cookie", "openflow_v6.flow_stats.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_packet_count,
{ "Packet count", "openflow_v6.flow_stats.packet_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_stats_byte_count,
{ "Byte count", "openflow_v6.flow_stats.byte_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_packet_count,
{ "Packet count", "openflow_v6.aggregate_stats.packet_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_byte_count,
{ "Byte count", "openflow_v6.aggregate_stats.byte_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_flow_count,
{ "Flow count", "openflow_v6.aggregate_stats.flow_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_aggregate_stats_pad,
{ "Pad", "openflow_v6.aggregate_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_stats_table_id,
{ "Table ID", "openflow_v6.table_stats.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_stats_pad,
{ "Pad", "openflow_v6.table_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_stats_active_count,
{ "Active count", "openflow_v6.table_stats.active_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_stats_lookup_count,
{ "Lookup count", "openflow_v6.table_stats.lookup_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_stats_match_count,
{ "Match count", "openflow_v6.table_stats.match_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_port_no,
{ "Port number", "openflow_v6.port_stats.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_pad,
{ "Pad", "openflow_v6.port_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_packets,
{ "Rx packets", "openflow_v6.port_stats.rx_packets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_tx_packets,
{ "Tx packets", "openflow_v6.port_stats.tx_packets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_bytes,
{ "Rx bytes", "openflow_v6.port_stats.rx_bytes",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_tx_bytes,
{ "Tx bytes", "openflow_v6.port_stats.tx_bytes",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_dropped,
{ "Rx dropped", "openflow_v6.port_stats.rx_dropped",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_tx_dropped,
{ "Tx dropped", "openflow_v6.port_stats.tx_dropped",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_errors,
{ "Rx errors", "openflow_v6.port_stats.rx_errors",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_tx_errors,
{ "Tx errors", "openflow_v6.port_stats.tx_errors",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_frame_error,
{ "Rx frame errors", "openflow_v6.port_stats.rx_frame_error",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_over_error,
{ "Rx overrun errors", "openflow_v6.port_stats.rx_over_error",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_rx_crc_error,
{ "Rx CRC errors", "openflow_v6.port_stats.rx_crc_error",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_collisions,
{ "Collisions", "openflow_v6.port_stats.collisions",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_duration_sec,
{ "Duration sec", "openflow_v6.port_stats.duration_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_port_stats_duration_nsec,
{ "Duration nsec", "openflow_v6.port_stats.duration_nsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_length,
{ "Length", "openflow_v6.queue_stats.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_pad,
{ "Pad", "openflow_v6.queue_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_port_no,
{ "Port number", "openflow_v6.queue_stats.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_queue_id,
{ "Queue ID", "openflow_v6.queue_stats.queue_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_tx_bytes,
{ "Tx bytes", "openflow_v6.queue_stats.tx_bytes",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_tx_packets,
{ "Tx packets", "openflow_v6.quee_stats.tx_packets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_tx_errors,
{ "Tx errors", "openflow_v6.port_stats.tx_errors",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_duration_sec,
{ "Duration sec", "openflow_v6.queue_stats.duration_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_duration_nsec,
{ "Duration nsec", "openflow_v6.queue_stats.duration_nsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_prop_type,
{ "Type", "openflow_v6.queue_stats_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_queue_stats_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_prop_length,
{ "Length", "openflow_v6.queue_stats_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.queue_stats_prop.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_stats_prop_experimenter_exp_type,
{ "Experimenter type", "openflow_v6.queue_stats_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_counter_packet_count,
{ "Packet count", "openflow_v6.bucket_counter.packet_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bucket_counter_byte_count,
{ "Byte count", "openflow_v6.bucket_counter.byte_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_length,
{ "Length", "openflow_v6.group_stats.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_pad,
{ "Pad", "openflow_v6.group_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_group_id,
{ "Group ID", "openflow_v6.group_stats.group_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_ref_count,
{ "Ref. count", "openflow_v6.group_stats.ref_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_pad2,
{ "Pad", "openflow_v6.group_stats.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_packet_count,
{ "Packet count", "openflow_v6.group_stats.packet_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_stats_byte_count,
{ "Byte count", "openflow_v6.group_stats.byte_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_desc_length,
{ "Length", "openflow_v6.group_desc.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_desc_type,
{ "Type", "openflow_v6.group_desc.type",
FT_UINT8, BASE_DEC, VALS(openflow_v6_group_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_desc_pad,
{ "Pad", "openflow_v6.group_desc.pad2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_desc_group_id,
{ "Group ID", "openflow_v6.group_desc.group_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_group_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_types,
{ "Types", "openflow_v6.group_features.types",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_types_all,
{ "OFPGT_ALL", "openflow_v6.group_features.types.all",
FT_BOOLEAN, 32, NULL, 1 << OFPGT_ALL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_types_select,
{ "OFPGT_SELECT", "openflow_v6.group_features.types.select",
FT_BOOLEAN, 32, NULL, 1 << OFPGT_SELECT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_types_indirect,
{ "OFPGT_INDIRECT", "openflow_v6.group_features.types.indirect",
FT_BOOLEAN, 32, NULL, 1 << OFPGT_INDIRECT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_types_ff,
{ "OFPGT_FF", "openflow_v6.group_features.types.ff",
FT_BOOLEAN, 32, NULL, 1 << OFPGT_FF,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_capabilities,
{ "Capabilities", "openflow_v6.group_features.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_capabilities_select_weight,
{ "OFPGFC_SELECT_WEIGHT", "openflow_v6.group_features.capabilities.select_weight",
FT_BOOLEAN, 32, NULL, OFPGFC_SELECT_WEIGHT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_capabilities_select_liveness,
{ "OFPGFC_SELECT_LIVENESS", "openflow_v6.group_features.capabilities.select_liveness",
FT_BOOLEAN, 32, NULL, OFPGFC_SELECT_LIVENESS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_capabilities_chaining,
{ "OFPGFC_CHAINING", "openflow_v6.group_features.capabilities.chaining",
FT_BOOLEAN, 32, NULL, OFPGFC_CHAINING,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_capabilities_chaining_checks,
{ "OFPGFC_CHAINING_CHECKS", "openflow_v6.group_features.capabilities.chaining_checks",
FT_BOOLEAN, 32, NULL, OFPGFC_CHAINING_CHECKS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_max_groups_all,
{ "Max groups (all)", "openflow_v6.group_stats.max_groups.all",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_max_groups_select,
{ "Max groups (select)", "openflow_v6.group_stats.max_groups.select",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_max_groups_indirect,
{ "Max groups (indirect)", "openflow_v6.group_stats.max_groups.indirect",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_max_groups_ff,
{ "Max groups (ff)", "openflow_v6.group_stats.max_groups.ff",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all,
{ "Actions (all)", "openflow_v6.group_features.actions.all",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_output,
{ "OFPAT_OUTPUT", "openflow_v6.group_features.actions.all.output",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_OUTPUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_copy_ttl_out,
{ "OFPAT_COPY_TTL_OUT", "openflow_v6.group_features.actions.all.copy_ttl_out",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_OUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_copy_ttl_in,
{ "OFPAT_COPY_TTL_IN", "openflow_v6.group_features.actions.all.copy_ttl_in",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_set_mpls_ttl,
{ "OFPAT_SET_MPLS_TTL", "openflow_v6.group_features.actions.all.set_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_dec_mpls_ttl,
{ "OFPAT_DEC_MPLS_TTL", "openflow_v6.group_features.actions.all.dec_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_push_vlan,
{ "OFPAT_PUSH_VLAN", "openflow_v6.group_features.actions.all.push_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_pop_vlan,
{ "OFPAT_POP_VLAN", "openflow_v6.group_features.actions.all.pop_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_push_mpls,
{ "OFPAT_PUSH_MPLS", "openflow_v6.group_features.actions.all.push_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_pop_mpls,
{ "OFPAT_POP_MPLS", "openflow_v6.group_features.actions.all.pop_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_set_queue,
{ "OFPAT_SET_QUEUE", "openflow_v6.group_features.actions.all.set_queue",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_QUEUE,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_group,
{ "OFPAT_GROUP", "openflow_v6.group_features.actions.all.group",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_GROUP,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_set_nw_ttl,
{ "OFPAT_SET_NW_TTL", "openflow_v6.group_features.actions.all.set_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_dec_nw_ttl,
{ "OFPAT_DEC_NW_TTL", "openflow_v6.group_features.actions.all.dec_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_set_field,
{ "OFPAT_SET_FIELD", "openflow_v6.group_features.actions.all.set_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_push_pbb,
{ "OFPAT_PUSH_PBB", "openflow_v6.group_features.actions.all.push_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_pop_pbb,
{ "OFPAT_POP_PBB", "openflow_v6.group_features.actions.all.pop_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_copy_field,
{ "OFPAT_COPY_FIELD", "openflow_v6.group_features.actions.all.copy_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_all_meter,
{ "OFPAT_METER", "openflow_v6.group_features.actions.all.meter",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_METER,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select,
{ "Actions (select)", "openflow_v6.group_features.actions.select",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_output,
{ "OFPAT_OUTPUT", "openflow_v6.group_features.actions.select.output",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_OUTPUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_copy_ttl_out,
{ "OFPAT_COPY_TTL_OUT", "openflow_v6.group_features.actions.select.copy_ttl_out",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_OUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_copy_ttl_in,
{ "OFPAT_COPY_TTL_IN", "openflow_v6.group_features.actions.select.copy_ttl_in",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_set_mpls_ttl,
{ "OFPAT_SET_MPLS_TTL", "openflow_v6.group_features.actions.select.set_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_dec_mpls_ttl,
{ "OFPAT_DEC_MPLS_TTL", "openflow_v6.group_features.actions.select.dec_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_push_vlan,
{ "OFPAT_PUSH_VLAN", "openflow_v6.group_features.actions.select.push_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_pop_vlan,
{ "OFPAT_POP_VLAN", "openflow_v6.group_features.actions.select.pop_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_push_mpls,
{ "OFPAT_PUSH_MPLS", "openflow_v6.group_features.actions.select.push_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_pop_mpls,
{ "OFPAT_POP_MPLS", "openflow_v6.group_features.actions.select.pop_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_set_queue,
{ "OFPAT_SET_QUEUE", "openflow_v6.group_features.actions.select.set_queue",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_QUEUE,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_group,
{ "OFPAT_GROUP", "openflow_v6.group_features.actions.select.group",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_GROUP,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_set_nw_ttl,
{ "OFPAT_SET_NW_TTL", "openflow_v6.group_features.actions.select.set_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_dec_nw_ttl,
{ "OFPAT_DEC_NW_TTL", "openflow_v6.group_features.actions.select.dec_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_set_field,
{ "OFPAT_SET_FIELD", "openflow_v6.group_features.actions.select.set_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_push_pbb,
{ "OFPAT_PUSH_PBB", "openflow_v6.group_features.actions.select.push_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_pop_pbb,
{ "OFPAT_POP_PBB", "openflow_v6.group_features.actions.select.pop_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_copy_field,
{ "OFPAT_COPY_FIELD", "openflow_v6.group_features.actions.select.copy_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_select_meter,
{ "OFPAT_METER", "openflow_v6.group_features.actions.select.meter",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_METER,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect,
{ "Actions (indirect)", "openflow_v6.group_features.actions.indirect",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_output,
{ "OFPAT_OUTPUT", "openflow_v6.group_features.actions.indirect.output",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_OUTPUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_copy_ttl_out,
{ "OFPAT_COPY_TTL_OUT", "openflow_v6.group_features.actions.indirect.copy_ttl_out",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_OUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_copy_ttl_in,
{ "OFPAT_COPY_TTL_IN", "openflow_v6.group_features.actions.indirect.copy_ttl_in",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_set_mpls_ttl,
{ "OFPAT_SET_MPLS_TTL", "openflow_v6.group_features.actions.indirect.set_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_dec_mpls_ttl,
{ "OFPAT_DEC_MPLS_TTL", "openflow_v6.group_features.actions.indirect.dec_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_push_vlan,
{ "OFPAT_PUSH_VLAN", "openflow_v6.group_features.actions.indirect.push_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_pop_vlan,
{ "OFPAT_POP_VLAN", "openflow_v6.group_features.actions.indirect.pop_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_push_mpls,
{ "OFPAT_PUSH_MPLS", "openflow_v6.group_features.actions.indirect.push_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_pop_mpls,
{ "OFPAT_POP_MPLS", "openflow_v6.group_features.actions.indirect.pop_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_set_queue,
{ "OFPAT_SET_QUEUE", "openflow_v6.group_features.actions.indirect.set_queue",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_QUEUE,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_group,
{ "OFPAT_GROUP", "openflow_v6.group_features.actions.indirect.group",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_GROUP,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_set_nw_ttl,
{ "OFPAT_SET_NW_TTL", "openflow_v6.group_features.actions.indirect.set_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_dec_nw_ttl,
{ "OFPAT_DEC_NW_TTL", "openflow_v6.group_features.actions.indirect.dec_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_set_field,
{ "OFPAT_SET_FIELD", "openflow_v6.group_features.actions.indirect.set_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_push_pbb,
{ "OFPAT_PUSH_PBB", "openflow_v6.group_features.actions.indirect.push_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_pop_pbb,
{ "OFPAT_POP_PBB", "openflow_v6.group_features.actions.indirect.pop_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_copy_field,
{ "OFPAT_COPY_FIELD", "openflow_v6.group_features.actions.indirect.copy_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_indirect_meter,
{ "OFPAT_METER", "openflow_v6.group_features.actions.indirect.meter",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_METER,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff,
{ "Actions (ff)", "openflow_v6.group_features.actions.ff",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_output,
{ "OFPAT_OUTPUT", "openflow_v6.group_features.actions.ff.output",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_OUTPUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_copy_ttl_out,
{ "OFPAT_COPY_TTL_OUT", "openflow_v6.group_features.actions.ff.copy_ttl_out",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_OUT,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_copy_ttl_in,
{ "OFPAT_COPY_TTL_IN", "openflow_v6.group_features.actions.ff.copy_ttl_in",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_TTL_IN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_set_mpls_ttl,
{ "OFPAT_SET_MPLS_TTL", "openflow_v6.group_features.actions.ff.set_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_dec_mpls_ttl,
{ "OFPAT_DEC_MPLS_TTL", "openflow_v6.group_features.actions.ff.dec_mpls_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_MPLS_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_push_vlan,
{ "OFPAT_PUSH_VLAN", "openflow_v6.group_features.actions.ff.push_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_pop_vlan,
{ "OFPAT_POP_VLAN", "openflow_v6.group_features.actions.ff.pop_vlan",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_VLAN,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_push_mpls,
{ "OFPAT_PUSH_MPLS", "openflow_v6.group_features.actions.ff.push_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_pop_mpls,
{ "OFPAT_POP_MPLS", "openflow_v6.group_features.actions.ff.pop_mpls",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_MPLS,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_set_queue,
{ "OFPAT_SET_QUEUE", "openflow_v6.group_features.actions.ff.set_queue",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_QUEUE,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_group,
{ "OFPAT_GROUP", "openflow_v6.group_features.actions.ff.group",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_GROUP,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_set_nw_ttl,
{ "OFPAT_SET_NW_TTL", "openflow_v6.group_features.actions.ff.set_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_dec_nw_ttl,
{ "OFPAT_DEC_NW_TTL", "openflow_v6.group_features.actions.ff.dec_nw_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_DEC_NW_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_set_field,
{ "OFPAT_SET_FIELD", "openflow_v6.group_features.actions.ff.set_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_SET_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_push_pbb,
{ "OFPAT_PUSH_PBB", "openflow_v6.group_features.actions.ff.push_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_PUSH_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_pop_pbb,
{ "OFPAT_POP_PBB", "openflow_v6.group_features.actions.ff.pop_pbb",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_POP_PBB,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_copy_field,
{ "OFPAT_COPY_FIELD", "openflow_v6.group_features.actions.ff.copy_field",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_COPY_FIELD,
NULL, HFILL }
},
{ &hf_openflow_v6_group_features_actions_ff_meter,
{ "OFPAT_METER", "openflow_v6.group_features.actions.ff.meter",
FT_BOOLEAN, 32, NULL, 1 << OFPAT_METER,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_stats_packet_band_count,
{ "Packet count", "openflow_v6.meter_band_stats.packet_band_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_band_stats_byte_band_count,
{ "Byte count", "openflow_v6.meter_band_stats.byte_band_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_meter_id,
{ "Meter ID", "openflow_v6.meter_stats.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_len,
{ "Length", "openflow_v6.meter_stats.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_pad,
{ "Pad", "openflow_v6.meter_stats.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_flow_count,
{ "Flow count", "openflow_v6.meter_stats.flow_count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_packet_in_count,
{ "Packet in count", "openflow_v6.meter_stats.packet_in_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_byte_in_count,
{ "Byte in count", "openflow_v6.meter_stats.byte_in_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_duration_sec,
{ "Duration sec", "openflow_v6.meter_stats.duration_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_stats_duration_nsec,
{ "Duration nsec", "openflow_v6.meter_stats.duration_nsec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_len,
{ "Length", "openflow_v6.meter_desc.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_flags,
{ "Flags", "openflow_v6.meter_desc.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_flags_kbps,
{ "OFPMF_KBPS", "openflow_v6.meter_desc.flags.kbps",
FT_BOOLEAN, 32, NULL, OFPMF_KBPS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_flags_pktps,
{ "OFPMF_PKTPS", "openflow_v6.meter_desc.flags.ptkps",
FT_BOOLEAN, 32, NULL, OFPMF_PKTPS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_flags_burst,
{ "OFPMF_BURST", "openflow_v6.meter_desc.flags.burst",
FT_BOOLEAN, 32, NULL, OFPMF_BURST,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_flags_stats,
{ "OFPMF_STATS", "openflow_v6.meter_desc.flags.stats",
FT_BOOLEAN, 32, NULL, OFPMF_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_desc_meter_id,
{ "Meter ID", "openflow_v6.meter_desc.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_max_meter,
{ "Max meters", "openflow_v6.meter_features.max_meter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_band_types,
{ "Band types", "openflow_v6.features.band_types",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_band_types_drop,
{ "OFPMBT_DROP", "openflow_v6.meter_features.band_types.drop",
FT_BOOLEAN, 32, NULL, 1 << OFPMBT_DROP,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_band_types_dscp_remark,
{ "OFPMBT_DSCP_REMARK", "openflow_v6.meter_features.band_types.dscp_remark",
FT_BOOLEAN, 32, NULL, 1 << OFPMBT_DSCP_REMARK,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_capabilities,
{ "Capabilities", "openflow_v6.meter_features.capabilities",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_capabilities_kbps,
{ "OFPMF_KBPS", "openflow_v6.meter_features.capabilities.kbps",
FT_BOOLEAN, 32, NULL, OFPMF_KBPS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_capabilities_pktps,
{ "OFPMF_PKTPS", "openflow_v6.meter_features.capabilities.ptkps",
FT_BOOLEAN, 32, NULL, OFPMF_PKTPS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_capabilities_burst,
{ "OFPMF_BURST", "openflow_v6.meter_features.capabilities.burst",
FT_BOOLEAN, 32, NULL, OFPMF_BURST,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_capabilities_stats,
{ "OFPMF_STATS", "openflow_v6.meter_features.capabilities.stats",
FT_BOOLEAN, 32, NULL, OFPMF_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_max_bands,
{ "Max bands", "openflow_v6.meter_features.max_bands",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_max_color,
{ "Max colors", "openflow_v6.meter_features.max_color",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_meter_features_pad,
{ "Pad", "openflow_v6.meter_features.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_length,
{ "Length", "openflow_v6.flow_update.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_event,
{ "Length", "openflow_v6.flow_update.event",
FT_UINT16, BASE_DEC, VALS(openflow_v6_flow_monitor_events), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_table_id,
{ "Table ID", "openflow_v6.flow_update.full.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_reason,
{ "Reason", "openflow_v6.flow_update.full.reason",
FT_UINT8, BASE_DEC, VALS(openflow_v6_flow_removed_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_zero,
{ "Zero", "openflow_v6.flow_update.full.zero",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_idle_timeout,
{ "Idle timeout", "openflow_v6.flow_update.full.idle_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_hard_timeout,
{ "Hard timeout", "openflow_v6.flow_update.full.hard_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_priority,
{ "Priority", "openflow_v6.flow_update.full.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_zeros,
{ "Zeros", "openflow_v6.flow_update.full.zeros",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_full_cookie,
{ "Cookie", "openflow_v6.flow_update.full.cookie",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_abbrev_xid,
{ "Transaction ID", "openflow_v6.flow_update.abbrev.xid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_flow_update_paused_zeros,
{ "Zeros", "openflow_v6.flow_update.paused.zeros",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_type ,
{ "Type", "openflow_v6.multipart_reply.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_multipart_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_flags,
{ "Flags", "openflow_v6.multipart_reply.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_flags_more,
{ "OFPMPF_REPLY_MORE", "openflow_v6.multipart_reply.flags.more",
FT_UINT16, BASE_HEX, NULL, OFPMPF_REPLY_MORE,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_pad,
{ "Pad", "openflow_v6.multipart_reply.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_experimenter_experimenter,
{ "Experimenter", "openflow_v6.multipart_reply.experimenter.experimenter",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_multipart_reply_experimenter_exp_type,
{ "Experimenter type", "openflow_v6.multipart_reply.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_length,
{ "Length", "openflow_v6.table_desc.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_table_id,
{ "Table ID", "openflow_v6.table_desc.table_id",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_table_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_pad,
{ "Pad", "openflow_v6.table_desc.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_config,
{ "Config", "openflow_v6.table_desc.config",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_config_eviction,
{ "OFPTC_EVICTION", "openflow_v6.table_desc.config.eviction",
FT_BOOLEAN, 32, NULL, OFPTC_EVICTION,
NULL, HFILL }
},
{ &hf_openflow_v6_table_desc_config_vacancy_events,
{ "OFPTC_VACANCY_EVENTS", "openflow_v6.table_desc.config.vacancy_events",
FT_BOOLEAN, 32, NULL, OFPTC_VACANCY_EVENTS,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_port_no,
{ "Port", "openflow_v6.queue_desc.port_no",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_port_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_queue_id,
{ "Queue ID", "openflow_v6.queue_desc.queue_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_len,
{ "Length", "openflow_v6.queue_desc.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_pad,
{ "Pad", "openflow_v6.queue_desc.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_property,
{ "Property", "openflow_v6.queue_desc_prop.property",
FT_UINT16, BASE_DEC, VALS(openflow_v6_queue_desc_prop_property_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_len,
{ "Length", "openflow_v6.queue_desc_prop.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_pad,
{ "Pad", "openflow_v6.queue_desc_prop.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_min_rate_rate,
{ "Rate", "openflow_v6.queue_desc_prop.min_rate.rate",
FT_UINT16, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_desc_prop_min_rate_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_min_rate_pad,
{ "Pad", "openflow_v6.queue_desc_prop.min_rate.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_max_rate_rate,
{ "Rate", "openflow_v6.queue_desc_prop.max_rate.rate",
FT_UINT16, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_queue_desc_prop_max_rate_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_max_rate_pad,
{ "Pad", "openflow_v6.queue_desc_prop.max_rate.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.queue_desc_prop.experimenter.experimenter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_queue_desc_prop_experimenter_exp_type,
{ "Exp type", "openflow_v6.queue_desc_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_request_role,
{ "Role", "openflow_v6.role_request.role",
FT_UINT32, BASE_HEX, VALS(openflow_v6_controller_role_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_request_pad,
{ "Pad", "openflow_v6.role_request.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_request_generation_id,
{ "Generation ID", "openflow_v6.role_request.generation_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_reply_role,
{ "Role", "openflow_v6.role_reply.role",
FT_UINT32, BASE_HEX, VALS(openflow_v6_controller_role_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_reply_pad,
{ "Pad", "openflow_v6.role_reply.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_reply_generation_id,
{ "Generation ID", "openflow_v6.role_reply.generation_id",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_type,
{ "Type", "openflow_v6.async_config_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_async_config_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_length,
{ "Length", "openflow_v6.async_config_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.packet_in.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_table_miss,
{ "OFPR_TABLE_MISS", "openflow_v6.async_config_prop.reason.packet_in.mask.table_miss",
FT_BOOLEAN, 32, NULL, 1 << OFPR_TABLE_MISS,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_apply_action,
{ "OFPR_APPLY_ACTION", "openflow_v6.async_config_prop.reason.packet_in.mask.apply_action",
FT_BOOLEAN, 32, NULL, 1 << OFPR_APPLY_ACTION,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_invalid_ttl,
{ "OFPR_INVALID_TTL", "openflow_v6.async_config_prop.reason.packet_in.mask.invalid_ttl",
FT_BOOLEAN, 32, NULL, 1 << OFPR_INVALID_TTL,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_action_set,
{ "OFPR_ACTION_SET", "openflow_v6.async_config_prop.reason.packet_in.mask.action_set",
FT_BOOLEAN, 32, NULL, 1 << OFPR_ACTION_SET,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_group,
{ "OFPR_GROUP", "openflow_v6.async_config_prop.reason.packet_in.mask.group",
FT_BOOLEAN, 32, NULL, 1 << OFPR_GROUP,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_packet_in_mask_packet_out,
{ "OFPR_PACKET_OUT", "openflow_v6.async_config_prop.reason.packet_in.mask.packet_out",
FT_BOOLEAN, 32, NULL, 1 << OFPR_PACKET_OUT,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_port_status_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.port_status.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_port_status_mask_add,
{ "OFPPR_ADD", "openflow_v6.async_config_prop.reason.port_status.mask.add",
FT_BOOLEAN, 32, NULL, 1 << OFPPR_ADD,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_port_status_mask_delete,
{ "OFPPR_DELETE", "openflow_v6.async_config_prop.reason.port_status.mask.delete",
FT_BOOLEAN, 32, NULL, 1 << OFPPR_DELETE,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_port_status_mask_modify,
{ "OFPPR_MODIFY", "openflow_v6.async_config_prop.reason.port_status.mask.modify",
FT_BOOLEAN, 32, NULL, 1 << OFPPR_MODIFY,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.flow_removed.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_idle_timeout,
{ "OFPRR_IDLE_TIMEOUT", "openflow_v6.async_config_prop.reason.flow_removed.mask.idle_timeout",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_IDLE_TIMEOUT,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_hard_timeout,
{ "OFPRR_HARD_TIMEOUT", "openflow_v6.async_config_prop.reason.flow_removed.mask.hard_timeout",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_HARD_TIMEOUT,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_delete,
{ "OFPRR_DELETE", "openflow_v6.async_config_prop.reason.flow_removed.mask.delete",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_DELETE,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_group_delete,
{ "OFPRR_GROUP_DELETE", "openflow_v6.async_config_prop.reason.flow_removed.mask.group_delete",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_GROUP_DELETE,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_meter_delete,
{ "OFPRR_METER_DELETE", "openflow_v6.async_config_prop.reason.flow_removed.mask.meter_delete",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_METER_DELETE,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_flow_removed_mask_eviction,
{ "OFPRR_EVICTION", "openflow_v6.async_config_prop.reason.flow_removed.mask.eviction",
FT_BOOLEAN, 32, NULL, 1 << OFPRR_EVICTION,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_role_status_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.role_status.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_role_status_mask_master_request,
{ "OFPCRR_MASTER_REQUEST", "openflow_v6.async_config_prop.reason.role_status.mask.master_request",
FT_BOOLEAN, 32, NULL, 1 << OFPCRR_MASTER_REQUEST,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_role_status_mask_config,
{ "OFPCRR_CONFIG", "openflow_v6.async_config_prop.reason.role_status.mask.config",
FT_BOOLEAN, 32, NULL, 1 << OFPCRR_CONFIG,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_role_status_mask_experimenter,
{ "OFPCRR_EXPERIMENTER", "openflow_v6.async_config_prop.reason.role_status.mask.experimenter",
FT_BOOLEAN, 32, NULL, 1 << OFPCRR_EXPERIMENTER,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_table_status_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.table_status.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_down,
{ "OFPTR_VACANCY_DOWN", "openflow_v6.async_config_prop.reason.table_status.mask.vacancy_u",
FT_BOOLEAN, 32, NULL, 1 << OFPTR_VACANCY_DOWN,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_up,
{ "OFPTR_VACANCY_UP", "openflow_v6.async_config_prop.reason.table_status.mask.vacancy_up",
FT_BOOLEAN, 32, NULL, 1 << OFPTR_VACANCY_UP,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_requestforward_mask,
{ "Mask", "openflow_v6.async_config_prop.reason.requestforward.mask",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_requestforward_mask_group_mod,
{ "OFPRFR_GROUP_MOD", "openflow_v6.async_config_prop.reason.requestforward.mask.group_mod",
FT_BOOLEAN, 32, NULL, 1 << OFPRFR_GROUP_MOD,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_reason_requestforward_mask_meter_mod,
{ "OFPRFR_METER_MOD", "openflow_v6.async_config_prop.reason.requestforward.mask.meter_mod",
FT_BOOLEAN, 32, NULL, 1 << OFPRFR_METER_MOD,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.async_config_prop.experimenter.experimenter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_async_config_prop_experimenter_exp_type,
{ "Exp type", "openflow_v6.async_config_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_command,
{ "Command", "openflow_v6.metermod.command",
FT_UINT8, BASE_DEC, VALS(openflow_v6_metermod_command_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_flags,
{ "Flags", "openflow_v6.metermod.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_flags_kbps,
{ "OFPMF_KBPS", "openflow_v6.metermod.flags.kbps",
FT_BOOLEAN, 32, NULL, OFPMF_KBPS,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_flags_pktps,
{ "OFPMF_PKTPS", "openflow_v6.metermod.flags.ptkps",
FT_BOOLEAN, 32, NULL, OFPMF_PKTPS,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_flags_burst,
{ "OFPMF_BURST", "openflow_v6.metermod.flags.burst",
FT_BOOLEAN, 32, NULL, OFPMF_BURST,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_flags_stats,
{ "OFPMF_STATS", "openflow_v6.metermod.flags.stats",
FT_BOOLEAN, 32, NULL, OFPMF_STATS,
NULL, HFILL }
},
{ &hf_openflow_v6_metermod_meter_id,
{ "Meter ID", "openflow_v6.metermod.meter_id",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(openflow_v6_meter_id_reserved_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_status_role,
{ "Role", "openflow_v6.role_status.role",
FT_UINT32, BASE_HEX, VALS(openflow_v6_controller_role_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_status_reason,
{ "Reason", "openflow_v6.role_status.reason",
FT_UINT8, BASE_HEX, VALS(openflow_v6_role_status_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_status_pad,
{ "Pad", "openflow_v6.role_status.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_role_status_generation_id,
{ "Generation ID", "openflow_v6.role_status.generation_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_status_reason,
{ "Reason", "openflow_v6.table_status.reason",
FT_UINT8, BASE_HEX, VALS(openflow_v6_table_status_reason_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_table_status_pad,
{ "Pad", "openflow_v6.table_status.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_control_bundle_id,
{ "Bundle ID", "openflow_v6.bundle_control.bundle_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_control_type,
{ "Type", "openflow_v6.bundle_control.type",
FT_UINT8, BASE_HEX, VALS(openflow_v6_bundle_control_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_control_flags,
{ "Flags", "openflow_v6.bundle_control.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_control_flags_atomic,
{ "OFPBF_ATOMIC", "openflow_v6.bundle_control.flags.atomic",
FT_BOOLEAN, 16, NULL, OFPBF_ATOMIC,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_control_flags_ordered,
{ "OFPBF_ORDERED", "openflow_v6.bundle_control.flags.ordered",
FT_BOOLEAN, 16, NULL, OFPBF_ORDERED,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_prop_type,
{ "Type", "openflow_v6.bundle_prop.type",
FT_UINT16, BASE_DEC, VALS(openflow_v6_bundle_prop_type_values), 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_prop_length,
{ "Length", "openflow_v6.bundle_prop.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_prop_experimenter_experimenter,
{ "Experimenter", "openflow_v6.bundle_prop.experimenter.experimenter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_prop_experimenter_exp_type,
{ "Exp type", "openflow_v6.bundle_prop.experimenter.exp_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_add_bundle_id,
{ "Bundle ID", "openflow_v6.bundle_add.bundle_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_add_pad,
{ "Pad", "openflow_v6.table_status.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_add_flags,
{ "Flags", "openflow_v6.bundle_add.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_add_flags_atomic,
{ "OFPBF_ATOMIC", "openflow_v6.bundle_add.flags.atomic",
FT_BOOLEAN, 16, NULL, OFPBF_ATOMIC,
NULL, HFILL }
},
{ &hf_openflow_v6_bundle_add_flags_ordered,
{ "OFPBF_ORDERED", "openflow_v6.bundle_add.flags.ordered",
FT_BOOLEAN, 16, NULL, OFPBF_ORDERED,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_openflow_v6,
&ett_openflow_v6_flowmod_flags,
&ett_openflow_v6_bucket,
&ett_openflow_v6_oxm,
&ett_openflow_v6_match,
&ett_openflow_v6_action,
&ett_openflow_v6_instruction,
&ett_openflow_v6_port,
&ett_openflow_v6_port_desc_prop,
&ett_openflow_v6_port_desc_prop_ethernet_current,
&ett_openflow_v6_port_desc_prop_ethernet_advertised,
&ett_openflow_v6_port_desc_prop_ethernet_supported,
&ett_openflow_v6_port_desc_prop_ethernet_peer,
&ett_openflow_v6_port_desc_prop_optical_supported,
&ett_openflow_v6_port_config,
&ett_openflow_v6_port_state,
&ett_openflow_v6_meter_band,
&ett_openflow_v6_hello_element,
&ett_openflow_v6_error_data,
&ett_openflow_v6_switch_features_capabilities,
&ett_openflow_v6_switch_config_flags,
&ett_openflow_v6_packet_in_data,
&ett_openflow_v6_packet_out_data,
&ett_openflow_v6_portmod_prop,
&ett_openflow_v6_portmod_prop_ethernet_advertise,
&ett_openflow_v6_portmod_prop_optical_configure,
&ett_openflow_v6_portmod_config,
&ett_openflow_v6_portmod_mask,
&ett_openflow_v6_tablemod_config,
&ett_openflow_v6_tablemod_prop,
&ett_openflow_v6_tablemod_prop_eviction_flags,
&ett_openflow_v6_table_features,
&ett_openflow_v6_table_features_capabilities,
&ett_openflow_v6_table_feature_prop,
&ett_openflow_v6_table_feature_prop_instruction_id,
&ett_openflow_v6_table_feature_prop_action_id,
&ett_openflow_v6_table_feature_prop_oxm_id,
&ett_openflow_v6_flow_monitor_request_flags,
&ett_openflow_v6_multipart_request_flags,
&ett_openflow_v6_flow_stats,
&ett_openflow_v6_flow_stats_flags,
&ett_openflow_v6_table_stats,
&ett_openflow_v6_port_stats,
&ett_openflow_v6_queue_stats,
&ett_openflow_v6_queue_stats_prop,
&ett_openflow_v6_bucket_counter,
&ett_openflow_v6_group_stats,
&ett_openflow_v6_group_desc,
&ett_openflow_v6_group_features_types,
&ett_openflow_v6_group_features_capabilities,
&ett_openflow_v6_group_features_actions_all,
&ett_openflow_v6_group_features_actions_select,
&ett_openflow_v6_group_features_actions_indirect,
&ett_openflow_v6_group_features_actions_ff,
&ett_openflow_v6_meter_band_stats,
&ett_openflow_v6_meter_stats,
&ett_openflow_v6_meter_desc,
&ett_openflow_v6_meter_desc_flags,
&ett_openflow_v6_meter_features_band_types,
&ett_openflow_v6_meter_features_capabilities,
&ett_openflow_v6_flow_update,
&ett_openflow_v6_multipart_reply_flags,
&ett_openflow_v6_table_desc,
&ett_openflow_v6_table_desc_config,
&ett_openflow_v6_queue_desc,
&ett_openflow_v6_queue_desc_prop,
&ett_openflow_v6_async_config_prop,
&ett_openflow_v6_async_config_prop_reason_packet_in_mask,
&ett_openflow_v6_async_config_prop_reason_port_status_mask,
&ett_openflow_v6_async_config_prop_reason_flow_removed_mask,
&ett_openflow_v6_async_config_prop_reason_role_status_mask,
&ett_openflow_v6_async_config_prop_reason_table_status_mask,
&ett_openflow_v6_async_config_prop_reason_requestforward_mask,
&ett_openflow_v6_metermod_flags,
&ett_openflow_v6_requestforward_request,
&ett_openflow_v6_bundle_control_flags,
&ett_openflow_v6_bundle_prop,
&ett_openflow_v6_bundle_add_flags,
&ett_openflow_v6_bundle_add_message
};
static ei_register_info ei[] = {
{ &ei_openflow_v6_oxm_undecoded,
{ "openflow_v6.oxm.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown OMX body.", EXPFILL }
},
{ &ei_openflow_v6_match_undecoded,
{ "openflow_v6.match.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown match body.", EXPFILL }
},
{ &ei_openflow_v6_action_undecoded,
{ "openflow_v6.action.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown action body.", EXPFILL }
},
{ &ei_openflow_v6_instruction_undecoded,
{ "openflow_v6.instruction.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown instruction body.", EXPFILL }
},
{ &ei_openflow_v6_port_desc_prop_undecoded,
{ "openflow_v6.port.desc_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown port desc. property body.", EXPFILL }
},
{ &ei_openflow_v6_meter_band_undecoded,
{ "openflow_v6.meter_band.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown meter band body.", EXPFILL }
},
{ &ei_openflow_v6_hello_element_undecoded,
{ "openflow_v6.hello_element.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown hello element body.", EXPFILL }
},
{ &ei_openflow_v6_error_undecoded,
{ "openflow_v6.error.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown error data.", EXPFILL }
},
{ &ei_openflow_v6_experimenter_undecoded,
{ "openflow_v6.experimenter.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown experimenter body.", EXPFILL }
},
{ &ei_openflow_v6_portmod_prop_undecoded,
{ "openflow_v6.portmod_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown portmod property body.", EXPFILL }
},
{ &ei_openflow_v6_tablemod_prop_undecoded,
{ "openflow_v6.tablemod_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown tablemod property body.", EXPFILL }
},
{ &ei_openflow_v6_table_feature_prop_undecoded,
{ "openflow_v6.table_feature_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown table feature property body.", EXPFILL }
},
{ &ei_openflow_v6_multipart_request_undecoded,
{ "openflow_v6.multipart_request.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown multipart reqeuest body.", EXPFILL }
},
{ &ei_openflow_v6_queue_stats_prop_undecoded,
{ "openflow_v6.queue_stats_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown queue stats prop body.", EXPFILL }
},
{ &ei_openflow_v6_flow_update_undecoded,
{ "openflow_v6.flow_update.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown flow update body.", EXPFILL }
},
{ &ei_openflow_v6_multipart_reply_undecoded,
{ "openflow_v6.multipart_reply.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown multipart reply body.", EXPFILL }
},
{ &ei_openflow_v6_queue_desc_prop_undecoded,
{ "openflow_v6.queue_desc_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown queue property body.", EXPFILL }
},
{ &ei_openflow_v6_async_config_prop_undecoded,
{ "openflow_v6.async_config_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown async config property body.", EXPFILL }
},
{&ei_openflow_v6_bundle_prop_undecoded,
{ "openflow_v6.bundle_prop.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown bundle prop body.", EXPFILL }
},
{&ei_openflow_v6_message_undecoded,
{ "openflow_v6.message.undecoded", PI_UNDECODED, PI_NOTE,
"Unknown message body.", EXPFILL }
},
{&ei_openflow_v6_length_too_short,
{ "openflow_v6.message.length_too_short", PI_MALFORMED, PI_ERROR,
"Length is too short.", EXPFILL }
}
};
expert_module_t *expert_openflow_v6;
proto_openflow_v6 = proto_register_protocol("OpenFlow 1.5",
"openflow_v6", "openflow_v6");
register_dissector("openflow_v6", dissect_openflow_v6, proto_openflow_v6);
proto_register_field_array(proto_openflow_v6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_openflow_v6 = expert_register_protocol(proto_openflow_v6);
expert_register_field_array(expert_openflow_v6, ei, array_length(ei));
}
void
proto_reg_handoff_openflow_v6(void)
{
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_openflow_v6);
}
