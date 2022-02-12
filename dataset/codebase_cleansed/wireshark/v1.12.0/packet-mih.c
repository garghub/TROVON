static gint16 dissect_mih_list(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree, gint16 (*base_dissect)(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree))
{
guint8 i = 0;
guint8 list_len = tvb_get_guint8(tvb, offset);
offset ++;
for(i=0; i < list_len; i++)
offset = base_dissect(tvb, offset, tlv_tree);
return (offset);
}
static gint16 dissect_ip_addr(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint16 addr_type = tvb_get_ntohs(tvb, offset);
guint8 len = 0;
if(addr_type == 1 )
{
len = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_item(tlv_tree, hf_ipv4_addr, tvb, offset+2, len, ENC_BIG_ENDIAN);
return (offset+3+len);
}
if(addr_type == 2)
{
len = tvb_get_guint8(tvb, offset + 3);
proto_tree_add_item(tlv_tree,hf_ipv6_addr, tvb, offset+2, len, ENC_NA);
return (offset+3+len);
}
else
{
len = tvb_get_guint8(tvb, offset + 3);
return (offset+3+len);
}
}
static gint16 dissect_qos_val(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
proto_tree_add_item(tlv_tree, hf_cos_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++ ;
proto_tree_add_item(tlv_tree, hf_cos_value, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return (offset);
}
static gint16 dissect_link_addr(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree )
{
guint8 link_addr_choice = tvb_get_guint8(tvb, offset);
guint8 len = 0;
proto_tree_add_item(tlv_tree, hf_link_addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (link_addr_choice)
{
case 0 :
proto_tree_add_item(tlv_tree, hf_link_transport_addr_type, tvb, offset+1, 2, ENC_BIG_ENDIAN);
if(tvb_get_ntohs(tvb, offset+1) == 0x06)
proto_tree_add_item(tlv_tree, hf_mac_addr, tvb, offset+4, tvb_get_guint8(tvb, offset+3), ENC_NA);
return (offset + 10);
case 1 :
proto_tree_add_item(tlv_tree, hf_plmn_id, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_cell_id, tvb, offset+4, 4, ENC_BIG_ENDIAN);
return (offset + 8);
case 2 :
proto_tree_add_item(tlv_tree, hf_plmn_id, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_location_area_id, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_ci, tvb, offset+6, 2, ENC_BIG_ENDIAN);
return (offset + 8);
case 3 :
case 4 :
case 5 :
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_link_addr_string, tvb, offset+2, len, ENC_ASCII|ENC_NA);
return (offset + 2 + len);
}
return 0;
}
static gint16 dissect_tsp_container(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
if(tvb_get_guint8(tvb, offset) == 1)
{
proto_tree_add_item(tlv_tree, hf_predef_cfg_id, tvb, offset+1, 1, ENC_BIG_ENDIAN);
return (offset + 2);
}
else if(tvb_get_guint8(tvb, offset) == 2)
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_tsp_carrier, tvb, offset+2, len, ENC_ASCII|ENC_NA);
return (offset + len + 2);
}
else
return (offset + 1);
}
static gint16 dissect_iq_rdf_data(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
if(tvb_get_guint8(tvb, offset))
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_rdf_mime_type, tvb, offset+2, len, ENC_ASCII|ENC_NA);
offset += len + 1;
}
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_rdf_data, tvb, offset+1, len, ENC_ASCII|ENC_NA);
return (offset+len+1);
}
static gint16 dissect_qos_list(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
proto_tree_add_item(tlv_tree, hf_num_cos, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_text(tlv_tree, tvb, offset, 1, "MIN_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_qos_val);
proto_tree_add_text(tlv_tree, tvb, offset, 1, "AVG_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_qos_val);
proto_tree_add_text(tlv_tree, tvb, offset, 1, "MAX_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_qos_val);
proto_tree_add_text(tlv_tree, tvb, offset, 1, "PK_DELAY_JITTER - ");
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_qos_val);
proto_tree_add_text(tlv_tree, tvb, offset, 1, "PK_LOSS_RATE- ");
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_qos_val);
return (offset);
}
static gint16 dissect_dev_states(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
proto_tree *sub_tree = NULL;
sub_tree = proto_tree_add_item(tlv_tree, hf_dev_states_resp, tvb, offset, 1, ENC_BIG_ENDIAN);
if(tvb_get_guint8(tvb, offset))
{
offset++;
proto_tree_add_item(sub_tree, hf_dev_batt_level, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1);
}
else
{
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree, hf_dev_info, tvb, offset+1, len, ENC_ASCII|ENC_NA);
return (offset + len + 1);
}
}
static gint16 dissect_net_type(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
guint8 type = 0;
if(!tvb_get_guint8(tvb, offset))
{
type = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_link_type, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 1;
}
offset += 1;
if(!tvb_get_guint8(tvb, offset))
{
switch (type)
{
case 15 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_eth, ett_subtype_eth_bitmap, subtype_eth_fields, ENC_BIG_ENDIAN);
break;
case 18 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_wireless_other, ett_subtype_wireless_other_bitmap, subtype_wireless_other_fields, ENC_BIG_ENDIAN);
break;
case 19 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_ieee80211, ett_subtype_ieee80211_bitmap, subtype_ieee80211_fields, ENC_BIG_ENDIAN);
break;
case 23 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_umts, ett_subtype_umts_bitmap, subtype_umts_fields, ENC_BIG_ENDIAN);
break;
case 24 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_cdma2000, ett_subtype_cdma2000_bitmap, subtype_cdma2000_fields, ENC_BIG_ENDIAN);
break;
case 27 :
proto_tree_add_bitmask(tlv_tree, tvb, offset+1, hf_link_subtype_ieee80216, ett_subtype_ieee80216_bitmap, subtype_ieee80216_fields, ENC_BIG_ENDIAN);
break;
default :
proto_item_append_text(tlv_tree, "N/A");
}
offset += 8;
}
offset += 1;
if(!tvb_get_guint8(tvb, offset))
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_link_type_ext, tvb, offset+2, len, ENC_ASCII|ENC_NA);
offset += len + 2;
}
return (offset);
}
static gint16 dissect_net_type_addr(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_net_type(tvb, offset, tlv_tree);
offset = dissect_link_addr(tvb, offset, tlv_tree);
return (offset) ;
}
static gint16 dissect_mbb_ho_supp(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_net_type(tvb, offset, tlv_tree);
offset = dissect_net_type(tvb, offset, tlv_tree);
proto_tree_add_item(tlv_tree, hf_mbb_ho_supp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return (offset);
}
static gint16 dissect_tgt_net_info(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
if(!tvb_get_guint8(tvb, offset))
{
offset +=1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_network_id, tvb, offset+1, len, ENC_ASCII|ENC_NA);
offset += len + 2;
if(!tvb_get_guint8(tvb, offset))
{
offset +=1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_net_aux_id, tvb, offset+1, len, ENC_ASCII|ENC_NA);
return (offset + 1);
}
return (offset + 2);
}
else
{
offset +=1;
offset = dissect_link_addr(tvb, offset, tlv_tree);
return (offset);
}
}
static gint16 dissect_link_id(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
gint16 next_offset = 0;
proto_tree_add_item(tlv_tree, hf_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
next_offset = dissect_link_addr(tvb, offset+1, tlv_tree);
return (next_offset);
}
static gint16 dissect_link_poa(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_id(tvb, offset, tlv_tree);
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_addr);
return (offset);
}
static gint16 dissect_rq_result(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
proto_tree *temp = NULL;
temp = proto_tree_add_text(tlv_tree, tvb, offset, 1, "List of preffered links:");
offset = dissect_link_poa(tvb, offset, temp);
offset = dissect_qos_list(tvb, offset, tlv_tree);
offset++;
switch(tvb_get_guint8(tvb, offset-1))
{
case 1: proto_tree_add_text(tlv_tree, tvb, offset, 1, "IP methods supported: ");
proto_tree_add_item(tlv_tree, hf_boolean, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 2: temp = proto_tree_add_text(tlv_tree, tvb, offset, 2, "ip configuration methods- ");
proto_tree_add_bitmask(temp, tvb, offset, hf_cfg_mthds, ett_cfg_mtd_bitmap, cfg_fields, ENC_BIG_ENDIAN);
offset += 2;
break;
}
offset++;
switch(tvb_get_guint8(tvb, offset-1))
{
case 1: proto_tree_add_text(tlv_tree, tvb, offset, 1, "IP DHCP services: ");
proto_tree_add_item(tlv_tree, hf_boolean, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 2: proto_tree_add_text(tlv_tree, tvb, offset, 1, "IP DHCP server: ");
offset = dissect_ip_addr(tvb, offset, tlv_tree);
break;
}
offset++;
switch(tvb_get_guint8(tvb, offset-1))
{
case 1: proto_tree_add_text(tlv_tree, tvb, offset, 1, "FN Agent ");
proto_tree_add_item(tlv_tree, hf_boolean, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 2: proto_tree_add_text(tlv_tree, tvb, offset, 1, "FN Agent: ");
offset = dissect_ip_addr(tvb, offset, tlv_tree);
break;
}
offset++;
switch(tvb_get_guint8(tvb, offset-1))
{
case 1: proto_tree_add_text(tlv_tree, tvb, offset, 1, "Access Router ");
proto_tree_add_item(tlv_tree, hf_boolean, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 2: proto_tree_add_text(tlv_tree, tvb, offset, 1, "Access Router: ");
offset = dissect_ip_addr(tvb, offset, tlv_tree);
break;
}
return (offset+1);
}
static gint16 dissect_link_det_info(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
offset = dissect_link_id(tvb, offset, tlv_tree);
if(tvb_get_guint8(tvb, offset))
{
offset++;
offset = dissect_link_addr(tvb, offset, tlv_tree);
offset --;
}
offset++;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_network_id, tvb, offset+1, len, ENC_ASCII|ENC_NA);
offset += len + 1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_net_aux_id, tvb, offset+1, len, ENC_ASCII|ENC_NA);
offset += len + 1;
if(tvb_get_guint8(tvb, offset))
proto_tree_add_item(tlv_tree, hf_sig_strength_per, tvb, offset+1, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tlv_tree, hf_sig_strength_dbm, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_sinr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_link_data_rate, tvb, offset,4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_mihcap, ett_mihcap_bitmap, mihcap_fields, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_net_caps, ett_net_caps_bitmap, net_caps_fields, ENC_BIG_ENDIAN);
offset += 4;
return (offset);
}
static gint16 dissect_link_scan_rsp(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
offset = dissect_link_addr(tvb, offset, tlv_tree);
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tlv_tree, hf_network_id, tvb, offset+1, len, ENC_ASCII|ENC_NA);
offset = offset + len + 1;
if(tvb_get_guint8(tvb, offset))
proto_tree_add_item(tlv_tree, hf_sig_strength_per, tvb, offset+1, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tlv_tree, hf_sig_strength_dbm, tvb, offset+1, 1, ENC_BIG_ENDIAN);
return offset+2;
}
static gint16 dissect_link_action_rsp(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_id(tvb, offset, tlv_tree);
proto_tree_add_item(tlv_tree, hf_link_ac_result, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(tvb_get_guint8(tvb, offset))
{
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_link_scan_rsp);
return offset;
}
else
return (offset+1);
}
static gint16 dissect_link_action_req(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_id(tvb, offset, tlv_tree);
if(tvb_get_guint8(tvb, offset))
{
offset = dissect_link_addr(tvb, offset+1, tlv_tree);
}
else
{
offset++;
}
proto_tree_add_item(tlv_tree, hf_link_ac_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_link_ac_attr, ett_ac_attr_bitmap, ac_attr_fields, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tlv_tree, hf_link_ac_ext_time, tvb, offset, 2, ENC_BIG_ENDIAN);
return (offset+2);
}
static gint16 dissect_link_states_rsp(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
if(!tvb_get_guint8(tvb, offset))
{
proto_tree_add_item(tlv_tree, hf_op_mode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(tlv_tree, hf_channel_id, tvb, offset+1, 2, ENC_BIG_ENDIAN);
offset += 3;
}
return (offset);
}
static gint16 dissect_link_param_type(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 type = tvb_get_guint8(tvb, offset);
offset++;
switch (type)
{
case 0 :
proto_tree_add_item(tlv_tree, hf_link_param_gen, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 1 :
proto_tree_add_item(tlv_tree, hf_link_param_qos, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2 :
proto_tree_add_item(tlv_tree, hf_link_param_gg, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3 :
proto_tree_add_item(tlv_tree, hf_link_param_edge, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 4 :
proto_tree_add_item(tlv_tree, hf_link_param_eth, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 5 :
proto_tree_add_item(tlv_tree, hf_link_param_802_11, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 6 :
proto_tree_add_item(tlv_tree, hf_link_param_c2k, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 7 :
proto_tree_add_item(tlv_tree, hf_link_param_fdd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 8 :
proto_tree_add_item(tlv_tree, hf_link_param_hrpd, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 9 :
proto_tree_add_item(tlv_tree, hf_link_param_802_16, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 10 :
proto_tree_add_item(tlv_tree, hf_link_param_802_20, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 11 :
proto_tree_add_item(tlv_tree, hf_link_param_802_22, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
return (offset+1);
}
static void dissect_link_status_req(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
proto_tree *tree_temp;
guint16 temp = tvb_get_ntohs(tvb, offset);
if(!temp)
{
tree_temp = proto_tree_add_text(tlv_tree, tvb, offset, 3, "LINK_STATES_REQ: ");
proto_tree_add_item(tree_temp, hf_op_mode, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset+=3;
}
else
{
tree_temp = proto_tree_add_text(tlv_tree, tvb, offset, 4, "LINK_STATES_REQ: ");
proto_tree_add_item(tree_temp, hf_channel_id, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset+=4;
}
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_param_type);
temp = tvb_get_ntohs(tvb, offset);
tree_temp = proto_tree_add_text(tlv_tree, tvb, offset, 3, "LINK_DESC_REQ: ");
offset+=2;
if(!temp)
proto_tree_add_item(tree_temp, hf_num_cos, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tree_temp, hf_num_queue, tvb, offset, 1, ENC_BIG_ENDIAN);
return ;
}
static gint16 dissect_link_cfg_status(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_param_type(tvb, offset, tlv_tree);
proto_tree_add_item(tlv_tree, hf_threshold_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_threshold_x_dir, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(tlv_tree, hf_config_status, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1);
}
static gint16 dissect_link_param(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_param_type(tvb, offset, tlv_tree);
if(!tvb_get_guint8(tvb, offset))
{
offset ++;
proto_tree_add_item(tlv_tree, hf_link_param_value, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
offset ++;
switch(tvb_get_guint8(tvb, offset))
{
case 0:
proto_tree_add_item(tlv_tree, hf_num_cos, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
break;
case 1:
proto_tree_add_text(tlv_tree, tvb, offset+1, 1, "MIN_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_qos_val);
break;
case 2:
proto_tree_add_text(tlv_tree, tvb, offset+1, 1, "AVG_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_qos_val);
break;
case 3:
proto_tree_add_text(tlv_tree, tvb, offset+1, 1, "MAX_PK_TX_DELAY- ");
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_qos_val);
break;
case 4:
proto_tree_add_text(tlv_tree, tvb, offset+1, 1, "PK_DELAY_JITTER - ");
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_qos_val);
break;
case 5:
proto_tree_add_text(tlv_tree, tvb, offset+1, 1, "PK_LOSS_RATE- ");
offset = dissect_mih_list(tvb, offset+1, tlv_tree, dissect_qos_val);
break;
}
}
return offset;
}
static gint16 dissect_link_param_rpt(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_param(tvb, offset, tlv_tree);
if(tvb_get_guint8(tvb, offset))
{
offset++;
proto_tree_add_item(tlv_tree, hf_threshold_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_threshold_x_dir, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1);
}
else
return (offset+1);
}
static gint16 dissect_link_desc_rsp(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
if(!tvb_get_guint8(tvb, offset))
proto_tree_add_item(tlv_tree, hf_num_cos, tvb, offset+1, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tlv_tree, hf_num_queue, tvb, offset+1, 1, ENC_BIG_ENDIAN);
return (offset+2);
}
static gint16 dissect_status_list(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_id(tvb, offset, tlv_tree);
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_states_rsp);
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_param);
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_desc_rsp);
return offset;
}
static gint16 dissect_link_det_cfg(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
guint8 len = 0;
if(tvb_get_guint8(tvb, offset))
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_network_id, tvb, offset+2, len, ENC_ASCII|ENC_NA);
offset += len + 1;
}
offset++;
if(tvb_get_guint8(tvb, offset))
{
if(tvb_get_guint8(tvb, offset+1))
proto_tree_add_item(tlv_tree, hf_sig_strength_per, tvb, offset+2, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(tlv_tree, hf_sig_strength_dbm, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += 2;
}
offset++;
if(tvb_get_guint8(tvb, offset))
{
proto_tree_add_item(tlv_tree, hf_link_data_rate, tvb, offset+1,4, ENC_BIG_ENDIAN);
offset += 4;
}
return (offset+1);
}
static gint16 dissect_link_cfg_param(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_link_param_type(tvb, offset, tlv_tree);
if(tvb_get_guint8(tvb, offset))
{
proto_tree_add_item(tlv_tree, hf_time_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset++;
proto_tree_add_item(tlv_tree, hf_threshold_action, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tlv_tree, hf_threshold_val, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_threshold_x_dir, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1) ;
}
static gint16 dissect_mih_evt_cfg_info(tvbuff_t *tvb, gint16 offset, proto_tree *tlv_tree)
{
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_det_cfg);
offset = dissect_mih_list(tvb, offset, tlv_tree, dissect_link_cfg_param);
return offset;
}
static void dissect_mih_tlv(tvbuff_t *tvb,int offset, proto_tree *tlv_tree, guint8 type, guint32 length)
{
guint8 mihf_id_len = 0;
char mihf_id_first_char = 0;
guint8 i = 0;
guint8 len = 0;
tvbuff_t *volatile tvb_mihf_id = NULL;
tvbuff_t* tvb_temp = NULL;
volatile gboolean composite_error = FALSE;
switch (type)
{
case SRC_MIHF_ID :
case DEST_MIHF_ID :
case MN_MIHF_ID :
mihf_id_len = tvb_get_guint8(tvb, offset);
mihf_id_first_char = (char)tvb_get_guint8(tvb, offset+1);
if(mihf_id_first_char!='\\')
proto_tree_add_item(tlv_tree, hf_mihf_id, tvb, offset+1, mihf_id_len, ENC_ASCII|ENC_NA);
else
{
if(mihf_id_len<tvb_length_remaining(tvb,0) && (mihf_id_len==12 || mihf_id_len==64 || mihf_id_len==128))
{
tvb_mihf_id = tvb_new_composite();
for(i=0; i < mihf_id_len/2; i++)
{
tvb_temp = tvb_new_subset(tvb, offset + 2 + 2*i, 1 , 1);
tvb_composite_append(tvb_mihf_id, tvb_temp);
}
TRY
{
tvb_composite_finalize(tvb_mihf_id);
}
CATCH_ALL
{
composite_error = TRUE;
}
ENDTRY;
if(!composite_error)
{
switch(mihf_id_len)
{
case 12:
proto_tree_add_item(tlv_tree, hf_mihf_id_mac, tvb_mihf_id, 0, mihf_id_len/2, ENC_NA);
break;
case 64:
proto_tree_add_item(tlv_tree, hf_mihf_id_ipv4, tvb_mihf_id, 0, mihf_id_len/2, ENC_BIG_ENDIAN);
break;
case 128:
proto_tree_add_item(tlv_tree, hf_mihf_id_ipv6, tvb_mihf_id, 0, mihf_id_len/2, ENC_NA);
break;
}
}
else
tvb_free(tvb_mihf_id);
}
}
break;
case STATUS :
proto_tree_add_item(tlv_tree, hf_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case LINK_TYPE :
proto_tree_add_item(tlv_tree, hf_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MIH_EVT_LIST :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_event_list, ett_event_bitmap, event_fields, ENC_BIG_ENDIAN);
break;
case MIH_CMD_LIST :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_cmd_list, ett_cmd_bitmap, cmd_fields, ENC_BIG_ENDIAN);
break;
case MIH_IQ_TYPE_LIST :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_iq_list, ett_iq_type_bitmap, iq_type_fields, ENC_BIG_ENDIAN);
break;
case MIH_TRANS_LIST :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_trans_list, ett_trans_list_bitmap, trans_fields, ENC_BIG_ENDIAN);
break;
case LINK_ADDR_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_net_type_addr);
break;
case MBB_HO_SUPP_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_mbb_ho_supp);
break;
case REG_REQUEST_CODE :
proto_tree_add_item(tlv_tree, hf_reg_request_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case VALID_TIME_INTR :
proto_tree_add_item(tlv_tree, hf_valid_time_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case LINK_ID :
case NEW_LINK_ID :
case MN_LINK_ID :
dissect_link_id(tvb, offset, tlv_tree);
break;
case OLD_ACCESS_ROUTER :
case NEW_ACCESS_ROUTER :
case POA_LINK_ADDR :
dissect_link_addr(tvb, offset, tlv_tree);
break;
case IP_RENEWAL_FLAG :
proto_tree_add_item(tlv_tree, hf_ip_renewal, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case IP_MOB_MGMT :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_mob_list, ett_mob_mgt_bitmap, mob_fields, ENC_BIG_ENDIAN);
break;
case IP_CFG_MTHDS :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_cfg_mthds, ett_cfg_mtd_bitmap, cfg_fields, ENC_BIG_ENDIAN);
break;
case LINK_DN_REASON :
proto_tree_add_item(tlv_tree, hf_link_dn_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case TIMER_INTERVAL :
proto_tree_add_item(tlv_tree, hf_time_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case LINK_GOING_DN_REASON :
proto_tree_add_item(tlv_tree, hf_link_gdn_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case LINK_PARAM_RPT_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_param_rpt);
break;
case DEV_STATES_REQ :
proto_tree_add_bitmask(tlv_tree, tvb, offset, hf_dev_states_req, ett_dev_states_bitmap, dev_states_fields, ENC_BIG_ENDIAN);
break;
case LINK_ID_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_id);
break;
case DEV_STATES_RSP_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_dev_states);
break;
case STATUS_REQ_SET :
dissect_link_status_req(tvb, offset, tlv_tree);
break;
case STATUS_RSP_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_status_list);
break;
case CFG_REQ_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_cfg_param);
break;
case CFG_RSP_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_cfg_status);
break;
case LINK_POA_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_poa);
break;
case PREF_LINK_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_rq_result);
break;
case HO_REQ_QUERY_LIST :
dissect_qos_list(tvb, offset, tlv_tree);
break;
case HO_STATUS:
proto_tree_add_item(tlv_tree, hf_ho_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case ACCESS_ROUTER_ADDR :
case DHCP_SER_ADDR :
case FA_ADDR :
dissect_ip_addr(tvb, offset, tlv_tree);
break;
case LINK_ACTION_REQ_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_action_req);
break;
case LINK_ACTION_RSP_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_action_rsp);
break;
case HO_RESULT :
proto_tree_add_item(tlv_tree, hf_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case LINK_RES_STATUS :
proto_tree_add_item(tlv_tree, hf_link_res_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case RES_RETENTION_STATUS :
proto_tree_add_item(tlv_tree, hf_res_retention_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case IQ_RDF_SCHEMA_URL :
proto_tree_add_item(tlv_tree, hf_iq_rdf_sch_url, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q_RES_RPT_FLAG :
proto_tree_add_item(tlv_tree, hf_res_rpt_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case UNAUTH_INFO_REQ :
proto_tree_add_item(tlv_tree, hf_unauth_info_req, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case IQ_BIN_DATA_LIST :
proto_tree_add_item(tlv_tree, hf_iq_bin_data_x, tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case IQ_RDF_DATA_LIST :
case IR_RDF_DATA_LIST :
case IR_RDF_SCHM_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_iq_rdf_data);
break;
case IQ_RDF_SCHM_LIST :
for(i=0; i < tvb_get_guint8(tvb, offset); i++)
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_rdf_sch, tvb, offset+2, len, ENC_ASCII|ENC_NA);
offset += len;
}
break;
case MAX_RSP_SIZE :
proto_tree_add_item(tlv_tree, hf_max_resp_size, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case IR_BIN_DATA_LIST :
proto_tree_add_item(tlv_tree, hf_ir_bin_data, tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case IR_SCHM_URL_LIST :
for(i=0; i < tvb_get_guint8(tvb, offset); i++)
{
len = tvb_get_guint8(tvb, offset+1);
proto_tree_add_item(tlv_tree, hf_rdf_sch_url, tvb, offset+2, len, ENC_ASCII|ENC_NA);
offset += len;
}
break;
case EVT_CFG_INFO_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_mih_evt_cfg_info);
break;
case TGT_NET_INFO :
dissect_tgt_net_info(tvb, offset, tlv_tree);
break;
case TGT_NET_INFO_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_tgt_net_info);
break;
case ASGN_RES_SET :
offset = dissect_qos_list(tvb, offset, tlv_tree);
dissect_tsp_container(tvb, offset, tlv_tree);
break;
case LINK_DET_INFO_LIST :
dissect_mih_list(tvb, offset, tlv_tree, dissect_link_det_info);
break;
case NET_TYPE :
dissect_net_type(tvb, offset, tlv_tree);
break;
case REQ_RES_SET :
offset = dissect_qos_list(tvb, offset, tlv_tree);
offset = dissect_tsp_container(tvb, offset, tlv_tree);
proto_tree_add_item(tlv_tree, hf_ho_reason, tvb, offset, 1, ENC_BIG_ENDIAN );
break;
case VEND_SPECIFIC_TLV :
proto_tree_add_text(tlv_tree, tvb, offset, length, "Vendor Specific TLV :%s", tvb_get_string(wmem_packet_scope(), tvb, offset, length));
break;
default :
if(type > 63 && type < 100)
proto_tree_add_text(tlv_tree, tvb, offset, length, "Reserved TLV :%s", tvb_get_string(wmem_packet_scope(), tvb, offset, length));
else if(type > 100 && type < 255)
proto_tree_add_text(tlv_tree, tvb, offset, length, "Experimental TLV :%s", tvb_get_string(wmem_packet_scope(), tvb, offset, length));
else
proto_tree_add_text(tlv_tree, tvb, offset, length, "UNKNOWN TLV :%s", tvb_get_string(wmem_packet_scope(), tvb, offset, length));
}
return;
}
static void dissect_mih(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
int offset = 0;
proto_item *item = NULL;
proto_tree *mih_tree = NULL;
proto_tree *ver_flags_tree = NULL;
guint8 serviceid = 0;
guint8 opcode = 0;
guint8 service = 0;
guint16 action = 0;
gint16 payload_length = 0;
guint64 len = 0;
guint8 len_of_len = 0;
guint8 type = 0;
proto_tree *mid_tree = NULL;
proto_tree *tlv_tree = NULL;
guint8 fragment = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MIH");
col_clear(pinfo->cinfo,COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree, proto_mih, tvb, 0, -1, ENC_NA);
}
mih_tree = proto_item_add_subtree(ti, ett_mih);
if(mih_tree)
item = proto_tree_add_item(mih_tree, hf_mih_version, tvb, offset, 1, ENC_BIG_ENDIAN);
if(item)
{
ver_flags_tree = proto_item_add_subtree(item, ett_ver_flags);
proto_tree_add_item(ver_flags_tree, hf_mih_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_flags_tree, hf_mih_ack_req, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_flags_tree, hf_mih_ack_resp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_flags_tree, hf_mih_uir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ver_flags_tree, hf_mih_more_frag, tvb, offset, 1, ENC_BIG_ENDIAN);
fragment = tvb_get_guint8(tvb, offset);
fragment = fragment << 7;
}
offset += 1;
if(mih_tree)
{
proto_tree_add_item(mih_tree, hf_mih_frag_no, tvb, offset, 1, ENC_BIG_ENDIAN);
fragment = fragment + (tvb_get_guint8(tvb, offset)>>1);
item = proto_tree_add_item(mih_tree, hf_mih_mid, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
}
offset += 1;
mid_tree = proto_item_add_subtree(item, ett_mid);
serviceid = tvb_get_guint8(tvb, offset);
serviceid = serviceid & 0xF0;
serviceid >>= 4;
proto_tree_add_item(mid_tree, hf_mih_service_id, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(serviceid, servicevalues, "Unknown"));
opcode = tvb_get_guint8(tvb, offset);
opcode = opcode & 0x0C;
opcode >>= 2;
if(mid_tree)
proto_tree_add_item(mid_tree, hf_mih_opcode, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(opcode, opcodevalues, "Unknown"));
service = tvb_get_guint8(tvb, offset);
service = service & 0xF0;
service >>= 4;
action = tvb_get_ntohs(tvb, offset);
action = action & 0x03FF;
switch (service)
{
case 1 :
if(mid_tree)
proto_tree_add_item(mid_tree, hf_mih_serv_actionid, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "\"%s\"", val_to_str(action, serv_act_id_values, "Unknown"));
break;
case 2 :
if(mid_tree)
proto_tree_add_item(mid_tree, hf_mih_event_actionid, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "\"%s\"", val_to_str(action, event_act_id_values, "Unknown"));
break;
case 3 :
if(mid_tree)
proto_tree_add_item(mid_tree, hf_mih_command_actionid, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "\"%s\"", val_to_str(action, command_act_id_values, "Unknown"));
break;
case 4 :
if(mid_tree)
proto_tree_add_item(mid_tree, hf_mih_info_actionid, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "\"%s\"", val_to_str(action, info_act_id_values, "Unknown"));
break;
}
offset += 2;
if(mih_tree)
{
proto_tree_add_item(mih_tree, hf_mih_tid, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item(mih_tree, hf_mih_pay_len, tvb, offset + 2, 2, ENC_BIG_ENDIAN );
}
offset += 2;
payload_length = tvb_get_ntohs(tvb, offset);
offset += 2;
while(payload_length > 0 && fragment==0)
{
len = tvb_get_guint8(tvb, offset+1);
if(len > 128)
{
len_of_len = (guint8)len - 128;
switch (len_of_len)
{
case 1:
len = tvb_get_guint8(tvb, offset+2);
break;
case 2:
len = tvb_get_ntohs(tvb, offset+2);
break;
case 3:
len = tvb_get_ntoh24(tvb, offset+2);
break;
case 4:
len = tvb_get_ntohl(tvb, offset+2);
break;
case 5:
len = tvb_get_ntoh40(tvb, offset+2);
break;
case 6:
len = tvb_get_ntoh48(tvb, offset+2);
break;
case 7:
len = tvb_get_ntoh56(tvb, offset+2);
break;
case 8:
len = tvb_get_ntoh64(tvb, offset+2);
}
len_of_len++;
len = 128 + len;
}
else
len_of_len = 1;
if(len <= (guint64)payload_length)
{
item = proto_tree_add_text(mih_tree, tvb, offset, 1 + len_of_len + (guint32)len, "MIH TLV : %s", val_to_str(tvb_get_guint8(tvb, offset), typevaluenames, "UNKNOWN"));
tlv_tree = proto_item_add_subtree(item, ett_tlv);
if(tlv_tree)
{
proto_tree_add_item(tlv_tree, hf_mih_type, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
if(len_of_len == 1)
{
proto_tree_add_item(tlv_tree, hf_mih_type_length, tvb, offset+1, len_of_len, ENC_BIG_ENDIAN);
}
else if(len_of_len>1 && len_of_len<=5)
{
proto_tree_add_item(tlv_tree, hf_mih_type_length_ext, tvb, offset+2, len_of_len-1, ENC_BIG_ENDIAN);
}
}
offset += 1 + len_of_len;
if(len<(2^32)){
dissect_mih_tlv(tvb, offset, tlv_tree, type, (guint32)len);
offset += (guint32)len;
payload_length -= (1 + len_of_len + (guint16)len);
}else{
return;
}
}
else
{
proto_tree_add_text(mih_tree, tvb, offset, -1, "FRAGMENTED TLV");
payload_length = 0;
}
}
if(fragment!=0)
proto_tree_add_text(mih_tree, tvb, offset, -1, "FRAGMENTED TLV");
}
void proto_register_mih(void)
{
static hf_register_info hf[] =
{
{
&hf_mih_version,
{
"MIH Version",
"mih.version",
FT_UINT8,
BASE_DEC,
NULL,
VERSION_MASK,
NULL, HFILL
}
},
{
&hf_mih_ack_req,
{
"MIH ACK-Req",
"mih.acq_req",
FT_BOOLEAN,
1,
NULL,
ACKREQ_MASK,
NULL, HFILL
}
},
{
&hf_mih_ack_resp,
{
"MIH ACK-Resp",
"mih.acq_resp",
FT_BOOLEAN,
1,
NULL,
ACKRESP_MASK,
NULL, HFILL
}
},
{
&hf_mih_uir,
{
"MIH Unauthenticated info request",
"mih.uir",
FT_BOOLEAN,
1,
NULL,
UIR_MASK,
NULL, HFILL
}
},
{
&hf_mih_more_frag,
{
"MIH more fragment",
"mih.more_frag",
FT_BOOLEAN,
1,
NULL,
MORE_FRAG_MASK,
NULL, HFILL
}
},
{
&hf_mih_frag_no,
{
"Fragment No",
"mih.frag_no",
FT_UINT8,
BASE_DEC,
NULL,
FRAG_NO_MASK,
NULL, HFILL
}
},
{
&hf_mih_mid,
{
"MIH message ID",
"mih.mid",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mih_service_id,
{
"Service ID",
"mih.service_id",
FT_UINT16,
BASE_HEX,
VALS(servicevalues),
SID_MASK,
NULL, HFILL
}
},
{
&hf_mih_opcode,
{
"Opcode",
"mih.opcode",
FT_UINT16,
BASE_HEX,
VALS(opcodevalues),
OPCODE_MASK,
NULL, HFILL
}
},
{
&hf_mih_serv_actionid,
{
"Action ID",
"mih.action_id",
FT_UINT16,
BASE_HEX,
VALS(serv_act_id_values),
AID_MASK,
NULL, HFILL
}
},
{
&hf_mih_event_actionid,
{
"Action ID",
"mih.action_id",
FT_UINT16,
BASE_HEX,
VALS(event_act_id_values),
AID_MASK,
NULL, HFILL
}
},
{
&hf_mih_command_actionid,
{
"Action ID",
"mih.action_id",
FT_UINT16,
BASE_HEX,
VALS(command_act_id_values),
AID_MASK,
NULL, HFILL
}
},
{
&hf_mih_info_actionid,
{
"Action ID",
"mih.action_id",
FT_UINT16,
BASE_HEX,
VALS(info_act_id_values),
AID_MASK,
NULL, HFILL
}
},
{
&hf_mih_tid,
{
"TID",
"mih.tid",
FT_UINT16,
BASE_DEC,
NULL,
TRANS_ID_MASK,
NULL, HFILL
}
},
{
&hf_mih_pay_len,
{
"Payload length",
"mih.pay_len",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mih_type,
{
"MIH TLV type",
"mih.tlv_type",
FT_UINT8,
BASE_DEC,
VALS(typevaluenames),
0x0,
NULL, HFILL
}
},
{
&hf_mih_type_length,
{
"MIH TLV length",
"mih.tlv_length",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mih_type_length_ext,
{
"MIH TLV length",
"mih.tlv_length",
FT_UINT64,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mihf_id,
{
"MIHF_ID",
"mih.mihf_id",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mihf_id_mac,
{
"MIHF_ID",
"mih.mihf_id",
FT_ETHER,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mihf_id_ipv4,
{
"MIHF_ID",
"mih.mihf_id",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mihf_id_ipv6,
{
"MIHF_ID",
"mih.mihf_id",
FT_IPv6,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_status,
{
"STATUS",
"mih.status",
FT_UINT8,
BASE_DEC,
VALS(status_types),
0x0,
NULL, HFILL
}
},
{
&hf_boolean,
{
"flag",
"mih.bool",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_link_type,
{
"Link Type",
"mih.link_type",
FT_UINT8,
BASE_DEC,
VALS(link_type_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_eth,
{
"Ethernet - IEEE802.3 Subtype",
"mih.link_subtype_eth",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_eth_10m,
{
"Ethernet 10 Mb",
"mih.link_subtype_eth.10mb",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_eth_100m,
{
"Ethernet 100 Mb",
"mih.link_subtype_eth.100mb",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_subtype_eth_1000m,
{
"Ethernet 1000 Mb",
"mih.link_subtype_eth.1000mb",
FT_BOOLEAN,
32,
NULL,
0x0004,
NULL, HFILL
}
},
{
&hf_link_subtype_wireless_other,
{
"Wireless Other Subtype",
"mih.link_subtype_wireless_other",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_wireless_other_dvb,
{
"DVB",
"mih.link_subtype_wireless_other.dvb",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_wireless_other_tdmb,
{
"T-DVB",
"mih.link_subtype_wireless_other.tdmb",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_subtype_wireless_other_atsc,
{
"ATSC-M/H",
"mih.link_subtype_wireless_other.atsc",
FT_BOOLEAN,
32,
NULL,
0x0004,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211,
{
"Wireless - IEEE 802.11 Subtype",
"mih.link_subtype_ieee80211",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211_24,
{
"2.4 GHz",
"mih.link_subtype_ieee80211.2_4ghz",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211_5,
{
"5 GHz",
"mih.link_subtype_ieee80211.5ghz",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211_49,
{
"4.9 GHz",
"mih.link_subtype_ieee80211.4_9ghz",
FT_BOOLEAN,
32,
NULL,
0x0004,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211_365,
{
"3.65 GHz",
"mih.link_subtype_ieee80211.3_65ghz",
FT_BOOLEAN,
32,
NULL,
0x0008,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80211_316,
{
"316 THz",
"mih.link_subtype_ieee80211.316thz",
FT_BOOLEAN,
32,
NULL,
0x0010,
NULL, HFILL
}
},
{
&hf_link_subtype_umts,
{
"Wireless - UMTS Subtype",
"mih.link_subtype_umts",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_99,
{
"Rel-99",
"mih.link_subtype_umts.rel99",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_4,
{
"Rel-4",
"mih.link_subtype_umts.rel4",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_5,
{
"Rel-5 (w/HSDPA)",
"mih.link_subtype_umts.rel5",
FT_BOOLEAN,
32,
NULL,
0x0004,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_6,
{
"Rel-6 (w/ HSUPA)",
"mih.link_subtype_umts.rel6",
FT_BOOLEAN,
32,
NULL,
0x0008,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_7,
{
"Rel-7 (MIMO/OFDM)",
"mih.link_subtype_umts.rel7",
FT_BOOLEAN,
32,
NULL,
0x0010,
NULL, HFILL
}
},
{
&hf_link_subtype_umts_8,
{
"Rel-8",
"mih.link_subtype_umts.rel8",
FT_BOOLEAN,
32,
NULL,
0x0020,
NULL, HFILL
}
},
{
&hf_link_subtype_cdma2000,
{
"Wireless - cdma2000-HRPD",
"mih.link_subtype_cdma2000",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_cdma2000_0,
{
"Rev-0",
"mih.link_subtype_cdma2000.rev0",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_cdma2000_a,
{
"Rev-A",
"mih.link_subtype_cdma2000.reva",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_subtype_cdma2000_b,
{
"Rev-B",
"mih.link_subtype_cdma2000.revb",
FT_BOOLEAN,
32,
NULL,
0x0004,
NULL, HFILL
}
},
{
&hf_link_subtype_cdma2000_c,
{
"Rev-C",
"mih.link_subtype_cdma2000.revc",
FT_BOOLEAN,
32,
NULL,
0x0008,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80216,
{
"Wireless - IEEE 802.16",
"mih.link_subtype_ieee80216",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80216_25,
{
"2.5 GHz",
"mih.link_subtype_ieee80216.2_5ghz",
FT_BOOLEAN,
32,
NULL,
0x0001,
NULL, HFILL
}
},
{
&hf_link_subtype_ieee80216_35,
{
"3.5 GHz",
"mih.link_subtype_ieee80216.3_5ghz",
FT_BOOLEAN,
32,
NULL,
0x0002,
NULL, HFILL
}
},
{
&hf_link_type_ext,
{
"LINK_TYPE_EXT",
"mih.link_type_ext",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_ipv4_addr,
{
"IP Address",
"mih.ipv4_addr",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_ipv6_addr,
{
"IP Address",
"mih.ipv6_addr",
FT_IPv6,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_dn_reason,
{
"LINK Down Reason",
"mih.link_dn_reason",
FT_UINT8,
BASE_DEC,
VALS(link_dn_reason_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_gdn_reason,
{
"LINK Going Down Reason",
"mih.link_gdn_reason",
FT_UINT8,
BASE_DEC,
VALS(link_gdn_reason_vals),
0x0,
NULL, HFILL
}
},
{
&hf_mac_addr,
{
"MAC ADDRESS",
"mih.mac_addr",
FT_ETHER,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_gen,
{
"LINK_PARAM",
"mih.link_param_gen",
FT_UINT8,
BASE_DEC,
VALS(link_param_gen_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_qos,
{
"LINK_PARAM",
"mih.link_param_qos",
FT_UINT8,
BASE_DEC,
VALS(link_param_qos_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_gg,
{
"LINK_PARAM",
"mih.link_param_gg",
FT_UINT8,
BASE_DEC,
VALS(link_param_gg_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_edge,
{
"LINK_PARAM",
"mih.link_param_edge",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_eth,
{
"LINK_PARAM",
"mih.link_param_eth",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_802_11,
{
"LINK_PARAM",
"mih.link_param_802_11",
FT_UINT8,
BASE_DEC,
VALS(link_param_802_11_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_c2k,
{
"LINK_PARAM",
"mih.link_param_c2k",
FT_UINT8,
BASE_DEC,
VALS(link_param_c2k_hrpd_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_fdd,
{
"LINK_PARAM",
"mih.link_param_fdd",
FT_UINT8,
BASE_DEC,
VALS(link_param_fdd_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_hrpd,
{
"LINK_PARAM",
"mih.link_param_hrpd",
FT_UINT8,
BASE_DEC,
VALS(link_param_c2k_hrpd_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_param_802_16,
{
"LINK_PARAM",
"mih.link_param_802_16",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_802_20,
{
"LINK_PARAM",
"mih.link_param_802_20",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_802_22,
{
"LINK_PARAM",
"mih.link_param_802_22",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_param_value,
{
"LINK_VALUE",
"mih.link_param_value",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_op_mode,
{
"OP_MODE",
"mih.op_mode",
FT_UINT8,
BASE_DEC,
VALS(op_mode_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_ac_type,
{
"LINK_AC_TYPE",
"mih.link_ac_type",
FT_UINT8,
BASE_DEC,
VALS(link_ac_type_vals),
0x0,
NULL, HFILL
}
},
{
&hf_link_ac_ext_time,
{
"LINK_AC_ext_time",
"mih.link_ac_ext_time",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_ac_result,
{
"LINK_AC_RESULT",
"mih.link_ac_result",
FT_UINT8,
BASE_DEC,
VALS(link_ac_result_vals),
0x0,
NULL, HFILL
}
},
{
&hf_ho_reason,
{
"HO CAUSE",
"mih.ho_reason",
FT_UINT8,
BASE_DEC,
VALS(link_dn_reason_vals),
0x0,
NULL, HFILL
}
},
{
&hf_ho_status,
{
"HO STATUS",
"mih.ho_status",
FT_UINT8,
BASE_DEC,
VALS(ho_status_vals),
0x0,
NULL, HFILL
}
},
{
&hf_mbb_ho_supp,
{
"MBB HO SUPP",
"mih.mbb_ho_supp",
FT_UINT8,
BASE_DEC,
VALS(mbb_ho_supp_vals),
0x0,
NULL, HFILL
}
},
{
&hf_reg_request_code,
{
"REGISTER REQUEST CODE",
"mih.reg_request_code",
FT_UINT8,
BASE_DEC,
VALS(reg_request_code_vals),
0x0,
NULL, HFILL
}
},
{
&hf_ip_renewal,
{
"IP RENEWAL FLAG",
"mih.ip_renewal",
FT_UINT8,
BASE_DEC,
VALS(ip_renewal_vals),
0x0,
NULL, HFILL
}
},
{
&hf_dev_states_resp,
{
"SUPPORTED TRANSPORTS",
"mih.dev_states_resp",
FT_UINT8,
BASE_DEC,
VALS(dev_states_req_vals),
0x0,
NULL, HFILL
}
},
{
&hf_dev_batt_level,
{
"Battery Level",
"mih.dev_states_resp.batt_level",
FT_INT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_dev_info,
{
"Device Info",
"mih.dev_states_resp.dev_info",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_max_resp_size,
{
"Maximum Response Size",
"mih.max_resp_size",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_time_interval,
{
"Time Interval",
"mih.time_interval",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_valid_time_interval,
{
"Valid Time Interval",
"mih.valid_time_interval",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_tsp_carrier,
{
"TSP Carrier",
"mih.tsp_carrier",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_addr_type,
{
"Link Address Type",
"mih.link_addr_type",
FT_UINT8,
BASE_DEC,
VALS(link_addr_types),
0x0,
NULL, HFILL
}
},
{
&hf_link_transport_addr_type,
{
"Link Transport Address Type",
"mih.link_transport_addr_type",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_addr_string,
{
"Link Address String",
"mih.link_addr_string",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_cell_id,
{
"3G Cell ID",
"mih.cell_id",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_ci,
{
"2G Cell ID",
"mih.ci",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_plmn_id,
{
"Public Land Mobile Network (PLMN) ID",
"mih.plmn_id",
FT_UINT24,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_location_area_id,
{
"Location Area Code (LAC)",
"mih.lac",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_threshold_val,
{
"Threshold Value",
"mih.threshold_val",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_threshold_x_dir,
{
"Threshold Direction",
"mih.threshold_x_dir",
FT_UINT8,
BASE_DEC,
VALS(threshold_x_dir_vals),
0x0,
NULL, HFILL
}
},
{
&hf_threshold_action,
{
"Threshold Action",
"mih.threshold_action",
FT_UINT8,
BASE_DEC,
VALS(threshold_action_vals),
0x0,
NULL, HFILL
}
},
{
&hf_config_status,
{
"Config Status",
"mih.config_status",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_num_cos,
{
"Number of differentiable classes",
"mih.num_cos",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_num_queue,
{
"Number of transmit queues supported",
"mih.num_queue",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_channel_id,
{
"Channel ID",
"mih.channel_id",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_predef_cfg_id,
{
"Pre-defined Configuration Identifier",
"mih.predef_cfg_id",
FT_INT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_network_id,
{
"Network ID",
"mih.network_id",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_net_aux_id,
{
"Auxiliary Network ID",
"mih.net_aux_id",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_sig_strength_dbm,
{
"Signal Strength (dBm)",
"mih.sig_strength",
FT_INT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_sig_strength_per,
{
"Signal Strength (%)",
"mih.sig_strength",
FT_INT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_cos_id,
{
"Class of Service ID",
"mih.cos_id",
FT_INT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_cos_value,
{
"Class of Service Value",
"mih.cos_value",
FT_INT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_sinr,
{
"SINR",
"mih.sinr",
FT_INT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_data_rate,
{
"Link Data Rate (kb/s)",
"mih.link_data_rate",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rdf_data,
{
"RDF data",
"mih.rdf_data",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rdf_mime_type,
{
"RDF data",
"mih.rdf_mime_type",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_res_status,
{
"Resource Status",
"mih.res_status",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_res_retention_status,
{
"Info query RDF schema URL",
"mih.res_retention_status",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_res_rpt_flag,
{
"Query resource report flag",
"mih.res_rpt_flag",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_unauth_info_req,
{
"Unauthenticated information request",
"mih.unauth_info_req",
FT_UINT8,
BASE_DEC,
VALS(boolean_types),
0x0,
NULL, HFILL
}
},
{
&hf_rdf_sch,
{
"RDF Schema",
"mih.rdf_sch",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rdf_sch_url,
{
"RDF Schema URL",
"mih.rdf_sch_url",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_ir_bin_data,
{
"IR Binary Data",
"mih.ir_bin_data",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_iq_bin_data_x,
{
"IQ Binary Data",
"mih.iq_bin_data",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_event_list,
{
"List of Events",
"mih.event_list",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_event_link_detect,
{
"MIH LINK Detected",
"mih.event_list.link_detect",
FT_BOOLEAN,
32,
NULL,
LINK_DETECT_MASK,
NULL, HFILL
}
},
{
&hf_event_link_up,
{
"MIH LINK UP",
"mih.event_list.link_up",
FT_BOOLEAN,
32,
NULL,
LINK_UP_MASK,
NULL, HFILL
}
},
{
&hf_event_link_dn,
{
"MIH LINK DOWN",
"mih.event_list.link_down",
FT_BOOLEAN,
32,
NULL,
LINK_DOWN_MASK,
NULL, HFILL
}
},
{
&hf_event_link_param,
{
"MIH LINK Parameters Report",
"mih.event_list.link_param_rpt",
FT_BOOLEAN,
32,
NULL,
LINK_PARAM_MASK,
NULL, HFILL
}
},
{
&hf_event_link_gd,
{
"MIH LINK Going Down",
"mih.event_list.link_gd",
FT_BOOLEAN,
32,
NULL,
LINK_GD_MASK,
NULL, HFILL
}
},
{
&hf_event_ho_imm,
{
"Link Handover Imminent",
"mih.event_list.link_ho_imm",
FT_BOOLEAN,
32,
NULL,
LINK_HO_IMM_MASK,
NULL, HFILL
}
},
{
&hf_event_ho_comp,
{
"MIH LINK Handover Complete",
"mih.event_list.link_ho_comp",
FT_BOOLEAN,
32,
NULL,
LINK_HO_COMP_MASK,
NULL, HFILL
}
},
{
&hf_event_pdu_tx_stat,
{
"MIH LINK PDU Transmit Status",
"mih.event_list.link_pdu_tx_stat",
FT_BOOLEAN,
32,
NULL,
LINK_PDU_MASK,
NULL, HFILL
}
},
{
&hf_cmd_list,
{
"List of Commands",
"mih.command_list",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_cmd_event_subs,
{
"MIH LINK Event Subscribe",
"mih.cmd_list.evt_subs",
FT_BOOLEAN,
32,
NULL,
CMD_EVT_SUBS_MASK,
NULL, HFILL
}
},
{
&hf_cmd_event_unsub,
{
"Link Event Unsubscribe",
"mih.cmd_list.evt_unsubs",
FT_BOOLEAN,
32,
NULL,
CMD_EVT_UNSUBS_MASK,
NULL, HFILL
}
},
{
&hf_cmd_get_param,
{
"MIH LINK Get Parameters",
"mih.cmd_list.evt_get_param",
FT_BOOLEAN,
32,
NULL,
CMD_GET_PARA_MASK,
NULL, HFILL
}
},
{
&hf_cmd_con_thres,
{
"Link Configure Thresholds",
"mih.cmd_list.evt_conf_th",
FT_BOOLEAN,
32,
NULL,
CMD_CONF_TH_MASK,
NULL, HFILL
}
},
{
&hf_cmd_link_action,
{
"MIH LINK Action",
"mih.cmd_list.evt_link_action",
FT_BOOLEAN,
32,
NULL,
CMD_LINK_AC_MASK,
NULL, HFILL
}
},
{
&hf_iq_list,
{
"List of of IS query types",
"mih.iq_type_list",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_iq_bin_data,
{
"Binary data",
"mih.iq_type_list.bin_data",
FT_BOOLEAN,
32,
NULL,
IQ_BIN_DATA_MASK,
NULL, HFILL
}
},
{
&hf_iq_rdf_data,
{
"RDF data",
"mih.iq_type_list.rdf_data",
FT_BOOLEAN,
32,
NULL,
IQ_RDF_DATA_MASK,
NULL, HFILL
}
},
{
&hf_iq_rdf_sch_url,
{
"RDF schema URL",
"mih.iq_type_list.rdf_sch_u",
FT_BOOLEAN,
32,
NULL,
IQ_RDF_SCH_U_MASK,
NULL, HFILL
}
},
{
&hf_iq_rdf_sch,
{
"RDF schema",
"mih.iq_type_list.rdf_sch",
FT_BOOLEAN,
32,
NULL,
IQ_RDF_SCH_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_type,
{
"IE_NETWORK_TYPE",
"mih.iq_type_list.ie_net_type",
FT_BOOLEAN,
32,
NULL,
IQ_IE_NET_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_iq_op_id,
{
"IE_OPERATOR_ID",
"mih.iq_type_list.ie_op_id",
FT_BOOLEAN,
32,
NULL,
IQ_IE_OP_ID_MASK,
NULL, HFILL
}
},
{
&hf_iq_serv_pro_id,
{
"IE_SERVICE_PROVIDER_ID",
"mih.iq_type_list.ie_serv_id",
FT_BOOLEAN,
32,
NULL,
IQ_SERV_ID_MASK,
NULL, HFILL
}
},
{
&hf_iq_country_code,
{
"IE_COUNTRY_CODE",
"mih.iq_type_list.ie_country_code",
FT_BOOLEAN,
32,
NULL,
IQ_IE_COUN_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_id,
{
"IE_NETWORK_ID",
"mih.iq_type_list.ie_net_id",
FT_BOOLEAN,
32,
NULL,
IQ_NET_ID_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_aux_id,
{
"IE_NETWORK_AUX_ID",
"mih.iq_type_list.net_aux_id",
FT_BOOLEAN,
32,
NULL,
IQ_NET_AUX_MASK,
NULL, HFILL
}
},
{
&hf_iq_roam_part,
{
"IE_ROAMING_PARTNERS",
"mih.iq_type_list.ie_roam_part",
FT_BOOLEAN,
32,
NULL,
IQ_IE_ROAM_MASK,
NULL, HFILL
}
},
{
&hf_iq_cost,
{
"IE_COST",
"mih.iq_type_list.ie_cost",
FT_BOOLEAN,
32,
NULL,
IQ_IE_COST_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_qos,
{
"IE_NETWORK_QOS",
"mih.iq_type_list.ie_net_qos",
FT_BOOLEAN,
32,
NULL,
IQ_IE_QOS_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_dat_rt,
{
"IE_NETWORK_DATA_RATE",
"mih.iq_type_list.ie_net_dat_rt",
FT_BOOLEAN,
32,
NULL,
IQ_IE_DATA_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_reg_dom,
{
"IE_NET_REGULT_DOMAIN",
"mih.iq_type_list.ie_net_reg_dom",
FT_BOOLEAN,
32,
NULL,
IQ_IE_REGDOM_MASK,
NULL, HFILL
}
},
{
&hf_iq_freq_bands,
{
"IE_NET_FREQUENCY_BANDS",
"mih.iq_type_list.ie_net_freq",
FT_BOOLEAN,
32,
NULL,
IQ_IE_FREQ_MASK,
NULL, HFILL
}
},
{
&hf_iq_ip_cfg_mthds,
{
"IE_NET_IP_CFG_METHODS",
"mih.iq_type_list.ie_net_ip_cfg",
FT_BOOLEAN,
32,
NULL,
IQ_IE_IP_CFG_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_cap,
{
"IE_NET_CAPABILITIES",
"mih.iq_type_list.ie_net_cap",
FT_BOOLEAN,
32,
NULL,
IQ_IE_CAP_MASK,
NULL, HFILL
}
},
{
&hf_iq_supp_lcp,
{
"IE_NET_SUPPORTED_LCP",
"mih.iq_type_list.ie_net_sup_lcp",
FT_BOOLEAN,
32,
NULL,
IQ_IE_SUP_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_mob_mg,
{
"IE_NET_MOB_MGMT_PROT",
"mih.iq_type_list.ie_net_mob_mg",
FT_BOOLEAN,
32,
NULL,
IQ_IE_MOB_MG_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_emserv,
{
"IE_NET_EMSERV_PROXY",
"mih.iq_type_list.ie_net_emer_serv",
FT_BOOLEAN,
32,
NULL,
IQ_IE_EM_SERV_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_ims_pcscf,
{
"IE_NET_IMS_PROXY_CSCF",
"mih.iq_type_list.ie_net_ims_pcscf",
FT_BOOLEAN,
32,
NULL,
IQ_IE_IMS_MASK,
NULL, HFILL
}
},
{
&hf_iq_net_mob_net,
{
"IE_NET_MOBILE_NETWORK",
"mih.iq_type_list.ie_net_mob_net",
FT_BOOLEAN,
32,
NULL,
IQ_IE_MOB_NET_MASK,
NULL, HFILL
}
},
{
&hf_iq_link_addr,
{
"IE_POA_LINK_ADDR",
"mih.iq_type_list.ie_poa_link",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_ADDR_MASK,
NULL, HFILL
}
},
{
&hf_iq_poa_loc,
{
"IE_POA_LOCATION",
"mih.iq_type_list.ie_poa_loc",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_LOC_MASK,
NULL, HFILL
}
},
{
&hf_iq_poa_chan_range,
{
"IE_POA_CHANNEL_RANGE",
"mih.iq_type_list.ie_poa_chan_rg",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_CHAN_MASK,
NULL, HFILL
}
},
{
&hf_iq_poa_sys_info,
{
"IE_POA_SYSTEM_INFO",
"mih.iq_type_list.ie_poa_syst_info",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_SYS_MASK,
NULL, HFILL
}
},
{
&hf_iq_poa_sub_info,
{
"IE_POA_SUBNET_INFO",
"mih.iq_type_list.ie_poa_sub_info",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_SUB_MASK,
NULL, HFILL
}
},
{
&hf_iq_poa_ip,
{
"IE_POA_IP_ADDR",
"mih.iq_type_list.ie_poa_ip",
FT_BOOLEAN,
32,
NULL,
IQ_IE_POA_IP_MASK,
NULL, HFILL
}
},
{
&hf_mob_list,
{
"List of supported mobility management protocols",
"mih.mob_list",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mob_mip4,
{
"Mobile IPv4",
"mih.mob_list.mip4",
FT_BOOLEAN,
16,
NULL,
MOB_MIP4_MASK,
NULL, HFILL
}
},
{
&hf_mob_mip4_reg,
{
"Mobile IPv4 Regional Registration",
"mih.mob_list.mip4_reg",
FT_BOOLEAN,
16,
NULL,
MOB_MIP4_REG_MASK,
NULL, HFILL
}
},
{
&hf_mob_mip6,
{
"Mobile IPv6",
"mih.mob_list.mip6",
FT_BOOLEAN,
16,
NULL,
MOB_MIP6_MASK,
NULL, HFILL
}
},
{
&hf_mob_hmip6,
{
"Hierarchical Mobile IPv6",
"mih.mob_list.hmip6",
FT_BOOLEAN,
16,
NULL,
MOB_HMIP6_MASK,
NULL, HFILL
}
},
{
&hf_mob_low_lat,
{
"Low Latency Handoffs",
"mih.mob_list.low_lat",
FT_BOOLEAN,
16,
NULL,
MOB_LOW_LAT_MASK,
NULL, HFILL
}
},
{
&hf_mob_fmip6,
{
"Mobile IPv6 Fast Handovers",
"mih.mob_list.fmip6",
FT_BOOLEAN,
16,
NULL,
MOB_FMIP6_MASK,
NULL, HFILL
}
},
{
&hf_mob_ike_multi,
{
"IKEv2 Mobility and Multihoming Protocol",
"mih.mob_list.ike_multi",
FT_BOOLEAN,
16,
NULL,
MOB_IKE_MULTI_MASK,
NULL, HFILL
}
},
{
&hf_cfg_mthds,
{
"A set of IP configuration methods",
"mih.cfg_mthds",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_cfg_ip4_stat,
{
"IPv4 static configuration",
"mih.ip_cfg_mthds.static",
FT_BOOLEAN,
32,
NULL,
IP_CFG_STAT_MASK,
NULL, HFILL
}
},
{
&hf_cfg_dhcp4,
{
"DHCPv4",
"mih.ip_cfg_mthds.dhcp4",
FT_BOOLEAN,
32,
NULL,
IP_CFG_DHCP4_MASK,
NULL, HFILL
}
},
{
&hf_cfg_mip_fa,
{
"Mobile IPv4 with foreign agent",
"mih.ip_cfg_mthds.mip4_fa",
FT_BOOLEAN,
32,
NULL,
IP_CFG_MIP4_FA_MASK,
NULL, HFILL
}
},
{
&hf_cfg_mip_wo_fa,
{
"Mobile IPv4 without FA",
"mih.ip_cfg_mthds.mip4_wo_fa",
FT_BOOLEAN,
32,
NULL,
IP_CFG_MIP4_NFA_MASK,
NULL, HFILL
}
},
{
&hf_cfg_ip6_sac,
{
"IPv6 stateless address configuration",
"mih.ip_cfg_mthds.ip6_state_less",
FT_BOOLEAN,
32,
NULL,
IP_CFG_IP6_SL_MASK,
NULL, HFILL
}
},
{
&hf_cfg_dhcp6,
{
"DHCPv6",
"mih.ip_cfg_mthds.dhcp6",
FT_BOOLEAN,
32,
NULL,
IP_CFG_DHCP6_MASK,
NULL, HFILL
}
},
{
&hf_cfg_ip6_manual,
{
"IPv6 manual configuration",
"mih.ip_cfg_mthds.ip6_manual",
FT_BOOLEAN,
32,
NULL,
IP_CFG_IP6_MAN_MASK,
NULL, HFILL
}
},
{
&hf_trans_list,
{
"Supported Transports",
"mih.trans_list",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_trans_udp,
{
"UDP",
"mih.trans_list.udp",
FT_BOOLEAN,
16,
NULL,
0x8000,
NULL, HFILL
}
},
{
&hf_trans_tcp,
{
"TCP",
"mih.trans_list.tcp",
FT_BOOLEAN,
16,
NULL,
0x4000,
NULL, HFILL
}
},
{
&hf_dev_states_req,
{
"Device Status Request",
"mih.dev_states_req",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_dev_states_req_dev_info,
{
"Device Info",
"mih.dev_states_req.dev_info",
FT_BOOLEAN,
16,
NULL,
0x8000,
NULL, HFILL
}
},
{
&hf_dev_states_req_batt_lvl,
{
"Battery Level",
"mih.dev_states_req.batt_level",
FT_BOOLEAN,
16,
NULL,
0x4000,
NULL, HFILL
}
},
{
&hf_mihcap,
{
"Supported MIH Capability",
"mih.mihcap",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_mihcap_es,
{
"Event Service (ES)",
"mih.mihcap.event_service",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_mihcap_cs,
{
"Command Service (CS)",
"mih.mihcap.command_service",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_mihcap_is,
{
"Information Service (IS)",
"mih.mihcap.information_service",
FT_BOOLEAN,
8,
NULL,
0x20,
NULL, HFILL
}
},
{
&hf_net_caps,
{
"High Level Network Capability",
"mih.net_caps",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_net_caps_sec,
{
"Security",
"mih.net_caps.sec",
FT_BOOLEAN,
32,
NULL,
0x80000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos0,
{
"QoS Class 0",
"mih.net_caps.qos0",
FT_BOOLEAN,
32,
NULL,
0x40000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos1,
{
"QoS Class 1",
"mih.net_caps.qos1",
FT_BOOLEAN,
32,
NULL,
0x20000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos2,
{
"QoS Class 2",
"mih.net_caps.qos2",
FT_BOOLEAN,
32,
NULL,
0x10000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos3,
{
"QoS Class 3",
"mih.net_caps.qos3",
FT_BOOLEAN,
32,
NULL,
0x08000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos4,
{
"QoS Class 4",
"mih.net_caps.qos4",
FT_BOOLEAN,
32,
NULL,
0x04000000,
NULL, HFILL
}
},
{
&hf_net_caps_qos5,
{
"QoS Class 5",
"mih.net_caps.qos5",
FT_BOOLEAN,
32,
NULL,
0x02000000,
NULL, HFILL
}
},
{
&hf_net_caps_ia,
{
"Internet Access",
"mih.net_caps.internet_access",
FT_BOOLEAN,
32,
NULL,
0x01000000,
NULL, HFILL
}
},
{
&hf_net_caps_es,
{
"Emergency Services",
"mih.net_caps.emergency_services",
FT_BOOLEAN,
32,
NULL,
0x00800000,
NULL, HFILL
}
},
{
&hf_net_caps_mihcap,
{
"MIH Capability",
"mih.net_caps.mihcap",
FT_BOOLEAN,
32,
NULL,
0x00400000,
NULL, HFILL
}
},
{
&hf_link_ac_attr,
{
"Link Action Attribute",
"mih.link_ac_attr",
FT_UINT8,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_link_ac_attr_link_scan,
{
"Link_Scan",
"mih.link_ac_attr.link_scan",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_link_ac_attr_link_res_retain,
{
"Link Resource Retain",
"mih.link_ac_attr.link_res_retain",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_link_ac_attr_data_fwd_req,
{
"Forward Data Request",
"mih.link_ac_attr.data_fwd_req",
FT_BOOLEAN,
8,
NULL,
0x20,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mih,
&ett_ver_flags,
&ett_mid,
&ett_tlv,
&ett_cmd_bitmap,
&ett_event_bitmap,
&ett_mob_mgt_bitmap,
&ett_cfg_mtd_bitmap,
&ett_iq_type_bitmap,
&ett_trans_list_bitmap,
&ett_dev_states_bitmap,
&ett_mihcap_bitmap,
&ett_net_caps_bitmap,
&ett_ac_attr_bitmap,
&ett_subtype_eth_bitmap,
&ett_subtype_wireless_other_bitmap,
&ett_subtype_ieee80211_bitmap,
&ett_subtype_umts_bitmap,
&ett_subtype_cdma2000_bitmap,
&ett_subtype_ieee80216_bitmap
};
proto_mih = proto_register_protocol("Media-Independent Handover", "MIH", "mih");
proto_register_field_array(proto_mih, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_mih(void)
{
dissector_handle_t mih_handle;
mih_handle = create_dissector_handle(dissect_mih, proto_mih);
dissector_add_uint("udp.port", MIH_PORT, mih_handle);
dissector_add_uint("tcp.port", MIH_PORT, mih_handle);
dissector_add_uint("ethertype", ETHERTYPE_MIH, mih_handle);
}
