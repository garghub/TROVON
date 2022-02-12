void dissect_mac_mgmt_msg_rep_req_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type;
gint tlv_type, tlv_len, tlv_value_offset, length, tlv_offset;
proto_item *rep_item = NULL;
proto_tree *rep_tree = NULL;
proto_tree *tlv_tree = NULL;
proto_tree *ti_tree = NULL;
tlv_info_t tlv_info;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_REP_REQ)
{
return;
}
if(tree)
{
tvb_len = tvb_reported_length(tvb);
rep_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_rep_decoder, tvb, offset, tvb_len, "Report Request (REP-REQ) (%u bytes)", tvb_len);
rep_tree = proto_item_add_subtree(rep_item, ett_mac_mgmt_msg_rep_req_decoder);
proto_tree_add_item(rep_tree, hf_rep_req_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-REQ TLV error");
proto_tree_add_item(rep_tree, hf_rep_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(rep_tree, proto_mac_mgmt_msg_rep_decoder, tvb, offset, (tlv_len + tlv_value_offset), "REP-REQ Type: %u (%u bytes, offset=%u, length=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tlv_len, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case REP_REQ_REPORT_REQUEST:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, rep_tree, hf_rep_req_report_request, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-REQ Report Request TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, (offset + tlv_offset), (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
#ifdef DEBUG
proto_tree_add_protocol_format(rep_tree, proto_mac_mgmt_msg_rep_decoder, tvb, offset, (length + tlv_value_offset), "REP-REQ Report Request Type: %u (%u bytes, offset=%u, length=%u, tvb_len=%u)", tlv_type, (length + tlv_value_offset), offset, length, tvb_len);
#endif
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_REQ_REPORT_TYPE:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_report_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_rep_type_bit0, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_rep_type_bit1, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_rep_type_bit2, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_rep_type_bit3_6, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_rep_type_bit7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_CHANNEL_NUMBER:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_channel_number, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_channel_number, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_CHANNEL_TYPE:
ti_tree = add_protocol_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, proto_mac_mgmt_msg_rep_decoder, tvb, (offset + tlv_offset), length, "Channel Type (%u byte(s))", length);
proto_tree_add_item(ti_tree, hf_rep_req_channel_type_request, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_channel_type_reserved, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_ZONE_SPEC_PHY_CINR_REQ:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_zone_spec_phy_cinr_request, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit0_2, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit3, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit4, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit5_6, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit8_13, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit14_17, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit18, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_phy_cinr_req_bit19_23, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_PREAMBLE_PHY_CINR_REQ:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_preamble_phy_cinr_request, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_phy_cinr_req_bit0_1, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_phy_cinr_req_bit2_5, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_phy_cinr_req_bit6, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_phy_cinr_req_bit7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_ZONE_SPEC_EFF_CINR_REQ:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_zone_spec_effective_cinr_request, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit0_2, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit3, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit4, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit5_6, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit8_13, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_zone_spec_effective_cinr_req_bit14_15, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_PREAMBLE_EFF_CINR_REQ:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_preamble_effective_cinr_request, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_effective_cinr_req_bit0_1, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_preamble_effective_cinr_req_bit2_7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_REQ_CHANNEL_SELECTIVITY_REPORT:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_req_channel_selectivity_report, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_req_channel_selectivity_rep_bit0, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_req_channel_selectivity_rep_bit1_7, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
default:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_req_decoder, rep_tree, hf_rep_unknown_type, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_rep_unknown_type, tvb, offset, tlv_len, ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void dissect_mac_mgmt_msg_rep_rsp_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint tvb_len, payload_type, length, value;
gint tlv_type, tlv_len, tlv_value_offset, tlv_offset;
gint db_val;
proto_item *rep_item = NULL;
proto_tree *rep_tree = NULL;
proto_tree *tlv_tree = NULL;
proto_item *ti = NULL;
proto_tree *ti_tree = NULL;
tlv_info_t tlv_info;
gfloat current_power;
payload_type = tvb_get_guint8(tvb, offset);
if(payload_type != MAC_MGMT_MSG_REP_RSP)
{
return;
}
if(tree)
{
tvb_len = tvb_reported_length(tvb);
rep_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_rep_decoder, tvb, offset, tvb_len, "Report Response (REP-RSP) (%u bytes)", tvb_len);
rep_tree = proto_item_add_subtree(rep_item, ett_mac_mgmt_msg_rep_rsp_decoder);
proto_tree_add_item(rep_tree, hf_rep_rsp_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while(offset < tvb_len)
{
init_tlv_info(&tlv_info, tvb, offset);
tlv_type = get_tlv_type(&tlv_info);
tlv_len = get_tlv_length(&tlv_info);
if(tlv_type == -1 || tlv_len > MAX_TLV_LEN || tlv_len < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP TLV error");
proto_tree_add_item(rep_tree, hf_rep_invalid_tlv, tvb, offset, (tvb_len - offset), ENC_NA);
break;
}
tlv_value_offset = get_tlv_value_offset(&tlv_info);
#ifdef DEBUG
proto_tree_add_protocol_format(rep_tree, proto_mac_mgmt_msg_rep_decoder, tvb, offset, (tlv_len + tlv_value_offset), "REP-RSP Type: %u (%u bytes, offset=%u, tlv_len=%u, tvb_len=%u)", tlv_type, (tlv_len + tlv_value_offset), offset, tlv_len, tvb_len);
#endif
offset += tlv_value_offset;
switch (tlv_type)
{
case REP_RSP_REPORT_TYPE:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_report_type, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP report subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_REPORT_CHANNEL_NUMBER:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_channel_number, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_channel_number, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_REPORT_START_FRAME:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_frame_number, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_frame_number, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_REPORT_DURATION:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_duration, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_duration, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_REPORT_BASIC_REPORT:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_basic_report, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_basic_report_bit0, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_basic_report_bit1, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_basic_report_bit2, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_basic_report_bit3, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_basic_report_reserved, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_REPORT_CINR_REPORT:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_cinr_report, tvb, (offset + tlv_offset), length, FALSE);
ti = proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_cinr_report_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
db_val = tvb_get_guint8(tvb, offset + tlv_offset) - 20;
if (db_val > 37)
db_val = 37;
proto_item_append_text(ti, " (%d dBm)", db_val);
ti = proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_cinr_report_deviation, tvb, (offset + tlv_offset +1), 1, ENC_BIG_ENDIAN);
db_val = tvb_get_guint8(tvb, offset + tlv_offset + 1) - 20;
if (db_val > 37)
db_val = 37;
proto_item_append_text(ti, " (%d dBm)", db_val);
break;
case REP_RSP_REPORT_RSSI_REPORT:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_report_type_rssi_report, tvb, (offset + tlv_offset), length, FALSE);
ti = proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_rssi_report_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
db_val = tvb_get_guint8(tvb, offset + tlv_offset) - 123;
if (db_val > -40)
db_val = -40;
proto_item_append_text(ti, " (%d dBm)", db_val);
ti = proto_tree_add_item(ti_tree, hf_rep_rsp_report_type_rssi_report_deviation, tvb, (offset + tlv_offset +1), 1, ENC_BIG_ENDIAN);
db_val = tvb_get_guint8(tvb, offset + tlv_offset + 1) - 123;
if (db_val > -40)
db_val = -40;
proto_item_append_text(ti, " (%d dBm)", db_val);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case REP_RSP_CHANNEL_TYPE:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_channel_type_report, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP channel subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_CHANNEL_TYPE_SUBCHANNEL:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_channel_type_subchannel, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_channel_type_subchannel, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_CHANNEL_TYPE_BAND_AMC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_channel_type_band_amc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_channel_type_band_amc, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_CHANNEL_TYPE_SAFETY_CHANNEL:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_channel_type_safety_channel, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_channel_type_safety_channel, tvb, (offset + tlv_offset), length, ENC_NA);
break;
case REP_RSP_CHANNEL_TYPE_ENHANCED_BAND_AMC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_channel_type_enhanced_band_amc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_channel_type_enhanced_band_amc, tvb, (offset + tlv_offset), length, ENC_NA);
break;
case REP_RSP_CHANNEL_TYPE_SOUNDING:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_channel_type_sounding, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_channel_type_sounding, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_zone_spec_phy_cinr_report, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP zone-specific phy CINR report subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_PUSC_SC0:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_pusc_sc0, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_report_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
{
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_PUSC_SC1:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_pusc_sc1, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_report_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
{
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_FUSC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_fusc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_report_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
{
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_OPTIONAL_FUSC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_optional_fusc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_report_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
{
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_SAFETY_CHANNEL:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_safety_channel, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_safety_channel, tvb, (offset + tlv_offset), length, ENC_NA);
break;
case REP_RSP_ZONE_SPECIFIC_PHY_CINR_AMC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_amc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_report_type, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
{
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
}
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case REP_RSP_PREAMBLE_PHY_CINR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_preamble_phy_cinr_report, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP preamble physical CINR report subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_PREAMBLE_PHY_CINR_CONFIGURATION1:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_preamble_phy_cinr_rep_configuration_1, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
break;
case REP_RSP_PREAMBLE_PHY_CINR_CONFIGURATION3:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_preamble_phy_cinr_rep_configuration_3, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_mean, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
if (length == 2)
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_phy_cinr_rep_deviation, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
break;
case REP_RSP_PREAMBLE_PHY_CINR_BAND_AMC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_preamble_phy_cinr_rep_band_amc_zone, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_preamble_phy_cinr_rep_band_amc_zone, tvb, (offset + tlv_offset), length, ENC_NA);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_zone_spec_effective_cinr_report, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP zone-specific effective CINR report subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR_PUSC_SC0:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_pusc_sc0, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_report_type, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR_PUSC_SC1:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_pusc_sc1, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_report_type, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR_FUSC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_fusc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_report_type, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR_OPTIONAL_FUSC:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_optional_fusc, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_report_type, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_ZONE_SPECIFIC_EFFECTIVE_CINR_AMC_AAS:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_amc_aas, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_report_type, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case REP_RSP_PREAMBLE_EFFECTIVE_CINR:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_preamble_effective_cinr_report, tvb, offset, tlv_len, FALSE);
for( tlv_offset = 0; tlv_offset < tlv_len; )
{
init_tlv_info(&tlv_info, tvb, (offset + tlv_offset));
tlv_type = get_tlv_type(&tlv_info);
length = get_tlv_length(&tlv_info);
if(tlv_type == -1 || length > MAX_TLV_LEN || length < 1)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "REP-RSP preamble effective CINR report subtype TLV error");
proto_tree_add_item(tlv_tree, hf_rep_invalid_tlv, tvb, offset, (tlv_len - offset - tlv_offset), ENC_NA);
break;
}
tlv_offset += get_tlv_value_offset(&tlv_info);
switch (tlv_type)
{
case REP_RSP_PREAMBLE_EFFECTIVE_CINR_CONFIGURATION1:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_preamble_effective_cinr_rep_configuration_1, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_preamble_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_PREAMBLE_EFFECTIVE_CINR_CONFIGURATION3:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_rsp_preamble_effective_cinr_rep_configuration_3, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_rep_rsp_preamble_effective_cinr_rep_cqich_id, tvb, (offset + tlv_offset), length, ENC_BIG_ENDIAN);
break;
case REP_RSP_CHANNEL_SELECTIVITY:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_rsp_channel_selectivity_report, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_rep_rsp_channel_selectivity_rep_frequency_a, tvb, (offset + tlv_offset + 2), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rep_rsp_channel_selectivity_rep_frequency_b, tvb, (offset + tlv_offset + 1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_rep_rsp_channel_selectivity_rep_frequency_c, tvb, (offset + tlv_offset), 1, ENC_BIG_ENDIAN);
break;
default:
ti_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, tlv_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, FALSE);
proto_tree_add_item(ti_tree, hf_rep_unknown_type, tvb, (offset + tlv_offset), length, ENC_NA);
break;
}
tlv_offset += length;
}
break;
case CURRENT_TX_POWER:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_unknown_type, tvb, offset, tlv_len, FALSE);
value = tvb_get_guint8(tvb, offset);
current_power = ((gfloat)value - 128) / 2;
ti = proto_tree_add_item(tlv_tree, hf_rep_rsp_current_transmitted_power, tvb, offset, tlv_len, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%.1f dBm)", current_power);
break;
default:
tlv_tree = add_tlv_subtree(&tlv_info, ett_mac_mgmt_msg_rep_rsp_decoder, rep_tree, hf_rep_unknown_type, tvb, offset, tlv_len, FALSE);
proto_tree_add_item(tlv_tree, hf_rep_unknown_type, tvb, offset, tlv_len, ENC_NA);
break;
}
offset += tlv_len;
}
}
}
void proto_register_mac_mgmt_msg_rep(void)
{
static hf_register_info hf_rep[] =
{
{
&hf_rep_invalid_tlv,
{
"Invalid TLV", "wmx.rep.invalid_tlv",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
}
},
{
&hf_rep_req_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.rep_req",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_channel_number,
{
"Channel Number", "wmx.rep_req.channel_number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_channel_selectivity_report,
{
"Channel Selectivity Report", "wmx.rep_req.channel_selectivity_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_channel_selectivity_rep_bit0,
{
"Include Frequency Selectivity Report", "wmx.rep_req.channel_selectivity_report.bit0",
FT_BOOLEAN, 8, NULL, REP_REQ_CHANNEL_SELECTIVITY_REPORT_BIT0, NULL, HFILL
}
},
{
&hf_rep_req_channel_selectivity_rep_bit1_7,
{
"Reserved", "wmx.rep_req.channel_selectivity_report.bit1_7",
FT_UINT8, BASE_HEX, NULL, REP_REQ_CHANNEL_SELECTIVITY_REPORT_BIT1_7, NULL, HFILL
}
},
{
&hf_rep_req_channel_type_request,
{
"Channel Type Request", "wmx.rep_req.channel_type.request",
FT_UINT8, BASE_DEC, VALS(vals_channel_types), 0x03, NULL, HFILL
}
},
{
&hf_rep_req_channel_type_reserved,
{
"Reserved", "wmx.rep_req.channel_type.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFC, NULL, HFILL
}
},
{
&hf_rep_req_preamble_effective_cinr_request,
{
"Preamble Effective CINR Request", "wmx.rep_req.preamble_effective_cinr_request",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_preamble_effective_cinr_req_bit0_1,
{
"Type Of Preamble Physical CINR Measurement", "wmx.rep_req.preamble_effective_cinr_request.bit0_1",
FT_UINT8, BASE_DEC, VALS(vals_type_of_measurements), REP_REQ_PREAMBLE_EFFECTIVE_CINR_REQUEST_BIT0_1, NULL, HFILL
}
},
{
&hf_rep_req_preamble_effective_cinr_req_bit2_7,
{
"Reserved", "wmx.rep_req.preamble_effective_cinr_request.bit2_7",
FT_UINT8, BASE_HEX, NULL, REP_REQ_PREAMBLE_EFFECTIVE_CINR_REQUEST_BIT2_7, NULL, HFILL
}
},
{
&hf_rep_req_preamble_phy_cinr_request,
{
"Preamble Physical CINR Request", "wmx.rep_req.preamble_phy_cinr_request",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_preamble_phy_cinr_req_bit0_1,
{
"Type Of Preamble Physical CINR Measurement", "wmx.rep_req.preamble_phy_cinr_request.bit0_1",
FT_UINT8, BASE_DEC, VALS(vals_type_of_measurements), REP_REQ_PREAMBLE_PHY_CINR_REQUEST_BIT0_1, NULL, HFILL
}
},
{
&hf_rep_req_preamble_phy_cinr_req_bit2_5,
{
"Alpha (ave) in multiples of 1/16", "wmx.rep_req.preamble_phy_cinr_request.bit2_5",
FT_UINT8, BASE_DEC, NULL, REP_REQ_PREAMBLE_PHY_CINR_REQUEST_BIT2_5, NULL, HFILL
}
},
{
&hf_rep_req_preamble_phy_cinr_req_bit6,
{
"CINR Report Type", "wmx.rep_req.preamble_phy_cinr_request.bit6",
FT_UINT8, BASE_DEC, VALS(vals_cinr_report_types), REP_REQ_PREAMBLE_PHY_CINR_REQUEST_BIT6, NULL, HFILL
}
},
{
&hf_rep_req_preamble_phy_cinr_req_bit7,
{
"Reserved", "wmx.rep_req.preamble_phy_cinr_request.bit7",
FT_UINT8, BASE_HEX, NULL, REP_REQ_PREAMBLE_PHY_CINR_REQUEST_BIT7, NULL, HFILL
}
},
{
&hf_rep_req_report_request,
{
"Report Request", "wmx.rep_req.report_request",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_report_type,
{
"Report Type", "wmx.rep_req.report_type",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_rep_type_bit0,
{
"Include DFS Basic Report", "wmx.rep_req.report_type.bit0",
FT_BOOLEAN, 8, NULL, REP_REQ_REPORT_TYPE_BIT0, NULL, HFILL
}
},
{
&hf_rep_req_rep_type_bit1,
{
"Include CINR Report", "wmx.rep_req.report_type.bit1",
FT_BOOLEAN, 8, NULL, REP_REQ_REPORT_TYPE_BIT1, NULL, HFILL
}
},
{
&hf_rep_req_rep_type_bit2,
{
"Include RSSI Report", "wmx.rep_req.report_type.bit2",
FT_BOOLEAN, 8, NULL, REP_REQ_REPORT_TYPE_BIT2, NULL, HFILL
}
},
{
&hf_rep_req_rep_type_bit3_6,
{
"Alpha (ave) in multiples of 1/32", "wmx.rep_req.report_type.bit3_6",
FT_UINT8, BASE_DEC, NULL, REP_REQ_REPORT_TYPE_BIT3_6, NULL, HFILL
}
},
{
&hf_rep_req_rep_type_bit7,
{
"Include Current Transmit Power Report", "wmx.rep_req.report_type.bit7",
FT_BOOLEAN, 8, NULL, REP_REQ_REPORT_TYPE_BIT7, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_effective_cinr_rep_cqich_id,
{
"The 4 least significant bits of CQICH_ID", "wmx.rep_req.zone_spec_effective_cinr_report.cqich_id_4",
FT_UINT8, BASE_HEX, NULL, REP_RSP_ZONE_SPEC_EFFECTIVE_CINR_CQICH_ID_4_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_cqich_id,
{
"The 3 least significant bits of CQICH_ID", "wmx.rep_req.zone_spec_effective_cinr_report.cqich_id",
FT_UINT8, BASE_HEX, NULL, REP_RSP_ZONE_SPEC_EFFECTIVE_CINR_CQICH_ID_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_effective_cinr,
{
"Effective CINR", "wmx.rep_req.zone_spec_effective_cinr_report.effective_cinr",
FT_UINT8, BASE_DEC, NULL, REP_RSP_ZONE_SPEC_EFFECTIVE_CINR_EFFECTIVE_CINR_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_report_type,
{
"Effective CINR Report", "wmx.rep_req.zone_spec_effective_cinr_report.report_type",
FT_UINT8, BASE_DEC, VALS(vals_data_cinr_measurements), REP_RSP_ZONE_SPEC_EFFECTIVE_CINR_REPORT_TYPE_MASK, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_request,
{
"Zone-specific Effective CINR Request", "wmx.rep_req.zone_spec_effective_cinr_request",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit0_2,
{
"Type Of Zone On Which CINR Is To Be Reported", "wmx.rep_req.zone_spec_effective_cinr_request.bit0_2",
FT_UINT16, BASE_HEX, VALS(vals_type_of_zones), REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT0_2, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit3,
{
"STC Zone", "wmx.rep_req.zone_spec_effective_cinr_request.bit3",
FT_BOOLEAN, 16, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT3, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit4,
{
"AAS Zone", "wmx.rep_req.zone_spec_effective_cinr_request.bit4",
FT_BOOLEAN, 16, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT4, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit5_6,
{
"PRBS ID", "wmx.rep_req.zone_spec_effective_cinr_request.bit5_6",
FT_UINT16, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT5_6, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit7,
{
"CINR Measurement Report", "wmx.rep_req.zone_spec_effective_cinr_request.bit7",
FT_UINT16, BASE_HEX, VALS(vals_data_cinr_measurements), REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT7, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit8_13,
{
"PUSC Major Group Map", "wmx.rep_req.zone_spec_effective_cinr_request.bit8_13",
FT_UINT16, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT8_13, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_effective_cinr_req_bit14_15,
{
"Reserved", "wmx.rep_req.zone_spec_effective_cinr_request.bit14_15",
FT_UINT16, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_16_BIT14_15, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_deviation,
{
"Standard Deviation of CINR", "wmx.rep_req.zone_spec_phy_cinr_report.deviation",
FT_UINT8, BASE_DEC, NULL, REP_RSP_ZONE_SPEC_PHY_CINR_DEVIATION_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_mean,
{
"Mean of Physical CINR", "wmx.rep_req.zone_spec_phy_cinr_report.mean",
FT_UINT8, BASE_DEC, NULL, REP_RSP_ZONE_SPEC_PHY_CINR_MEAN_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_report_type,
{
"CINR Report Type", "wmx.rep_req.zone_spec_phy_cinr_report.report_type",
FT_UINT8, BASE_DEC, VALS(vals_data_cinr_measurements), REP_RSP_ZONE_SPEC_PHY_CINR_REP_TYPE_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_reserved1,
{
"Reserved", "wmx.rep_req.zone_spec_phy_cinr_report.reserved1",
FT_UINT8, BASE_HEX, NULL, REP_RSP_ZONE_SPEC_PHY_CINR_RSV1_MASK, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_reserved2,
{
"Reserved", "wmx.rep_req.zone_spec_phy_cinr_report.reserved2",
FT_UINT8, BASE_HEX, NULL, REP_RSP_ZONE_SPEC_PHY_CINR_RSV2_MASK, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_request,
{
"Zone-specific Physical CINR Request", "wmx.rep_req.zone_spec_phy_cinr_request",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit0_2,
{
"Type Of Zone On Which CINR Is To Be Reported", "wmx.rep_req.zone_spec_phy_cinr_request.bit0_2",
FT_UINT24, BASE_HEX, VALS(vals_type_of_zones), REP_REQ_TYPE_OF_ZONE_REQUEST_BIT0_2, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit3,
{
"STC Zone", "wmx.rep_req.zone_spec_phy_cinr_request.bit3",
FT_BOOLEAN, 24, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT3, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit4,
{
"AAS Zone", "wmx.rep_req.zone_spec_phy_cinr_request.bit4",
FT_BOOLEAN, 24, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT4, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit5_6,
{
"PRBS ID", "wmx.rep_req.zone_spec_phy_cinr_request.bit5_6",
FT_UINT24, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT5_6, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit7,
{
"CINR Measurement Report", "wmx.rep_req.zone_spec_phy_cinr_request.bit7",
FT_UINT24, BASE_HEX, VALS(vals_data_cinr_measurements), REP_REQ_TYPE_OF_ZONE_REQUEST_BIT7, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit8_13,
{
"PUSC Major Group Map", "wmx.rep_req.zone_spec_phy_cinr_request.bit8_13",
FT_UINT24, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT8_13, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit14_17,
{
"Alpha (ave) in multiples of 1/16", "wmx.rep_req.zone_spec_phy_cinr_request.bit14_17",
FT_UINT24, BASE_DEC, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT14_17, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit18,
{
"CINR Report Type", "wmx.rep_req.zone_spec_phy_cinr_request.bit18",
FT_UINT24, BASE_HEX, VALS(vals_cinr_report_types), REP_REQ_TYPE_OF_ZONE_REQUEST_BIT18, NULL, HFILL
}
},
{
&hf_rep_req_zone_spec_phy_cinr_req_bit19_23,
{
"Reserved", "wmx.rep_req.zone_spec_phy_cinr_request.bit19_23",
FT_UINT24, BASE_HEX, NULL, REP_REQ_TYPE_OF_ZONE_REQUEST_BIT19_23, NULL, HFILL
}
},
{
&hf_rep_rsp_message_type,
{
"MAC Management Message Type", "wmx.macmgtmsgtype.rep_rsp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_selectivity_report,
{
"Channel Selectivity Report", "wmx.rep_rsp.channel_selectivity_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_selectivity_rep_frequency_a,
{
"Frequency Selectivity Report a", "wmx.rep_rsp.channel_selectivity_report.frequency_a",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_selectivity_rep_frequency_b,
{
"Frequency Selectivity Report b", "wmx.rep_rsp.channel_selectivity_report.frequency_b",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_selectivity_rep_frequency_c,
{
"Frequency Selectivity Report c", "wmx.rep_rsp.channel_selectivity_report.frequency_c",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_report,
{
"Channel Type Report", "wmx.rep_rsp.channel_type_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_band_amc,
{
"Band AMC", "wmx.rep_rsp.channel_type_report.band_amc",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_enhanced_band_amc,
{
"Enhanced Band AMC", "wmx.rep_rsp.channel_type_report.enhanced_band_amc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_safety_channel,
{
"Safety Channel", "wmx.rep_rsp.channel_type_report.safety_channel",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_sounding,
{
"Sounding", "wmx.rep_rsp.channel_type_report.sounding",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_channel_type_subchannel,
{
"Normal Subchannel", "wmx.rep_rsp.channel_type_report.subchannel",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_effective_cinr_report,
{
"Preamble Effective CINR Report", "wmx.rep_rsp.preamble_effective_cinr_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_effective_cinr_rep_configuration_1,
{
"The Estimation Of Effective CINR Measured From Preamble For Frequency Reuse Configuration=1", "wmx.rep_rsp.preamble_effective_cinr_report.configuration_1",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_effective_cinr_rep_configuration_3,
{
"The Estimation Of Effective CINR Measured From Preamble For Frequency Reuse Configuration=3", "wmx.rep_rsp.preamble_effective_cinr_report.configuration_3",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_phy_cinr_report,
{
"Preamble Physical CINR Report", "wmx.rep_rsp.preamble_phy_cinr_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_phy_cinr_rep_band_amc_zone,
{
"The Estimation Of Physical CINR Measured From Preamble For Band AMC Zone", "wmx.rep_rsp.preamble_phy_cinr_report.band_amc_zone",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_phy_cinr_rep_configuration_1,
{
"The Estimation Of Physical CINR Measured From Preamble For Frequency Reuse Configuration=1", "wmx.rep_rsp.preamble_phy_cinr_report.configuration_1",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_preamble_phy_cinr_rep_configuration_3,
{
"The Estimation Of Physical CINR Measured From Preamble For Frequency Reuse Configuration=3", "wmx.rep_rsp.preamble_phy_cinr_report.configuration_3",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type,
{
"Report Type", "wmx.rep_rsp.report_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report,
{
"Basic Report", "wmx.rep_rsp.report_type.basic_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report_bit0,
{
"Wireless HUMAN Detected", "wmx.rep_rsp.report_type.basic_report.bit0",
FT_BOOLEAN, 8, NULL, REP_RSP_REPORT_TYPE_BASIC_REPORT_BIT0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report_bit1,
{
"Unknown Transmission Detected", "wmx.rep_rsp.report_type.basic_report.bit1",
FT_BOOLEAN, 8, NULL, REP_RSP_REPORT_TYPE_BASIC_REPORT_BIT1, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report_bit2,
{
"Specific Spectrum User Detected", "wmx.rep_rsp.report_type.basic_report.bit2",
FT_BOOLEAN, 8, NULL, REP_RSP_REPORT_TYPE_BASIC_REPORT_BIT2, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report_bit3,
{
"Channel Not Measured", "wmx.rep_rsp.report_type.basic_report.bit3",
FT_BOOLEAN, 8, NULL, REP_RSP_REPORT_TYPE_BASIC_REPORT_BIT3, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_basic_report_reserved,
{
"Reserved", "wmx.rep_rsp.report_type.basic_report.reserved",
FT_UINT8, BASE_HEX, NULL, REP_RSP_REPORT_TYPE_BASIC_REPORT_RSV, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_channel_number,
{
"Channel Number", "wmx.rep_rsp.report_type.channel_number",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_cinr_report,
{
"CINR Report", "wmx.rep_rsp.report_type.cinr_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_cinr_report_deviation,
{
"CINR Standard Deviation", "wmx.rep_rsp.report_type.cinr_report_deviation",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_cinr_report_mean,
{
"CINR Mean", "wmx.rep_rsp.report_type.cinr_report_mean",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_duration,
{
"Duration", "wmx.rep_rsp.report_type.duration",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_frame_number,
{
"Start Frame", "wmx.rep_rsp.report_type.frame_number",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_rssi_report,
{
"RSSI Report", "wmx.rep_rsp.report_type.rssi_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_rssi_report_deviation,
{
"RSSI Standard Deviation", "wmx.rep_rsp.report_type.rssi_report_deviation",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_current_transmitted_power,
{
"Current Transmitted Power", "wmx.rep_rsp.current_transmitted_power",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_report_type_rssi_report_mean,
{
"RSSI Mean", "wmx.rep_rsp.report_type.rssi_report_mean",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_report,
{
"Zone-specific Effective CINR Report", "wmx.rep_rsp.zone_spec_effective_cinr_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_amc_aas,
{
"AMC AAS Zone", "wmx.rep_rsp.zone_spec_effective_cinr_report.amc_aas",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_fusc,
{
"FUSC Zone", "wmx.rep_rsp.zone_spec_effective_cinr_report.fusc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_optional_fusc,
{
"Optional FUSC Zone", "wmx.rep_rsp.zone_spec_effective_cinr_report.optional_fusc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_pusc_sc0,
{
"PUSC Zone (use all SC=0)", "wmx.rep_rsp.zone_spec_effective_cinr_report.pusc_sc0",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_effective_cinr_rep_pusc_sc1,
{
"PUSC Zone (use all SC=1)", "wmx.rep_rsp.zone_spec_effective_cinr_report.pusc_sc1",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_report,
{
"Zone-specific Physical CINR Report", "wmx.rep_rsp.zone_spec_phy_cinr_report",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_amc,
{
"AMC Zone", "wmx.rep_rsp.zone_spec_phy_cinr_report.amc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_fusc,
{
"FUSC Zone", "wmx.rep_rsp.zone_spec_phy_cinr_report.fusc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_optional_fusc,
{
"Optional FUSC Zone", "wmx.rep_rsp.zone_spec_phy_cinr_report.optional_fusc",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_pusc_sc0,
{
"PUSC Zone (use all SC=0)", "wmx.rep_rsp.zone_spec_phy_cinr_report.pusc_sc0",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_pusc_sc1,
{
"PUSC Zone (use all SC=1)", "wmx.rep_rsp.zone_spec_phy_cinr_report.pusc_sc1",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_rsp_zone_spec_phy_cinr_rep_safety_channel,
{
"Safety Channel", "wmx.rep_rsp.zone_spec_phy_cinr_report.safety_channel",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_rep_unknown_type,
{
"Unknown TLV type", "wmx.rep.unknown_tlv_type",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett_rep[] =
{
&ett_mac_mgmt_msg_rep_req_decoder,
&ett_mac_mgmt_msg_rep_rsp_decoder,
};
proto_mac_mgmt_msg_rep_decoder = proto_register_protocol (
"WiMax REP-REQ/RSP Messages",
"WiMax REP-REQ/RSP (rep)",
"wmx.rep"
);
proto_register_field_array(proto_mac_mgmt_msg_rep_decoder, hf_rep, array_length(hf_rep));
proto_register_subtree_array(ett_rep, array_length(ett_rep));
}
