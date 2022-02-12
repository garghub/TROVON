static int
dissect_wlccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *wlccp_tree, *wlccp_sap_tree, *wlccp_type_tree;
guint offset = 0, old_offset;
guint8 version=0, sap_id=0;
guint16 type;
guint8 base_message_type=0, message_sub_type=0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WLCCP");
if(tvb_get_guint8(tvb, 0) == 0xC1)
{
sap_id = tvb_get_guint8(tvb,1) & SAP_VALUE_MASK;
base_message_type=(tvb_get_guint8(tvb,6)) & MT_BASE_MSG_TYPE;
message_sub_type=(tvb_get_guint8(tvb, 6) & MT_SUBTYPE ) >> 6;
switch (sap_id)
{
case WLCCP_SAP_CCM:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_0, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
case WLCCP_SAP_SEC:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_1, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
case WLCCP_SAP_RRM:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_2, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
case WLCCP_SAP_QOS:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_3, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
case WLCCP_SAP_NM:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_4, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
case WLCCP_SAP_MIP:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s",
val_to_str_const(base_message_type, wlccp_msg_type_vs_5, "Unknown"),
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
default:
{
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type: %-27s SubType: %s", "Unknown",
val_to_str_const(message_sub_type, wlccp_subtype_vs, "Unknown"));
break;
}
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_wlccp, tvb, 0, -1, ENC_NA);
wlccp_tree = proto_item_add_subtree(ti, ett_wlccp);
proto_tree_add_item(wlccp_tree, hf_wlccp_version,
tvb, offset, 1, ENC_BIG_ENDIAN);
version = tvb_get_guint8(tvb, 0);
offset += 1;
if(version == 0x0) {
proto_tree_add_item(wlccp_tree, hf_wlccp_length,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wlccp_tree, hf_wlccp_type,
tvb, 2, 2, ENC_BIG_ENDIAN);
type = tvb_get_ntohs(tvb, 2);
proto_tree_add_item(wlccp_tree, hf_wlccp_dstmac,
tvb, 4, 6, ENC_NA);
proto_tree_add_item(wlccp_tree, hf_wlccp_srcmac,
tvb, 10, 6, ENC_NA);
if(type == 0x4081) {
proto_tree_add_item(wlccp_tree, hf_wlccp_ipv4_address,
tvb, 38, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(wlccp_tree, hf_wlccp_hostname,
tvb, 44, 28, ENC_ASCII|ENC_NA);
}
}
if(version == 0xC1)
{
{
ti = proto_tree_add_item(wlccp_tree, hf_wlccp_sap,
tvb, offset, 1, ENC_BIG_ENDIAN);
wlccp_sap_tree = proto_item_add_subtree(ti, ett_wlccp_sap_tree);
proto_tree_add_item(wlccp_sap_tree, hf_wlccp_sap_version,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wlccp_sap_tree, hf_wlccp_sap_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
sap_id = tvb_get_guint8(tvb,offset) & SAP_VALUE_MASK;
offset += 1;
}
proto_tree_add_item(wlccp_tree, hf_wlccp_destination_node_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(wlccp_tree, hf_wlccp_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
{
ti = proto_tree_add_item(wlccp_tree, hf_wlccp_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
wlccp_type_tree = proto_item_add_subtree(ti, ett_wlccp_type);
proto_tree_add_item(wlccp_type_tree, hf_wlccp_subtype,
tvb, offset, 1, ENC_BIG_ENDIAN);
switch (sap_id)
{
case WLCCP_SAP_CCM:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_0,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case WLCCP_SAP_SEC:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_1,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case WLCCP_SAP_RRM:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_2,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case WLCCP_SAP_QOS:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_3,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case WLCCP_SAP_NM:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_4,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case WLCCP_SAP_MIP:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_5,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
default:
{
proto_tree_add_item(wlccp_type_tree, hf_wlccp_base_message_type_unknown,
tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
}
base_message_type=(tvb_get_guint8(tvb,offset) & MT_BASE_MSG_TYPE );
offset += 1;
}
set_mic_flag(FALSE);
set_tlv_flag(FALSE);
switch (sap_id)
{
case WLCCP_SAP_CCM:
{
offset = dissect_wlccp_ccm_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
case WLCCP_SAP_SEC:
{
offset = dissect_wlccp_sec_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
case WLCCP_SAP_RRM:
{
offset = dissect_wlccp_rrm_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
case WLCCP_SAP_QOS:
{
offset = dissect_wlccp_qos_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
case WLCCP_SAP_NM:
{
offset = dissect_wlccp_nm_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
case WLCCP_SAP_MIP:
{
offset = dissect_wlccp_mip_msg(wlccp_tree, tvb, offset, base_message_type);
break;
}
default:
{
break;
}
}
if(get_tlv_flag() || get_mic_flag())
{
if (tvb_reported_length_remaining(tvb,offset) < 4)
{
}
else
{
while (tvb_reported_length_remaining(tvb,offset) >= 4)
{
old_offset = offset;
offset = dissect_wlccp_tlvs(wlccp_tree, tvb, offset, 0);
DISSECTOR_ASSERT(offset > old_offset);
}
;
}
}
}
}
return tvb_captured_length(tvb);
}
static void set_mic_flag(gboolean flag)
{
mic_flag=flag;
}
static void set_tlv_flag(gboolean flag)
{
tlv_flag=flag;
}
static gboolean get_tlv_flag(void)
{
return(tlv_flag);
}
static gboolean get_mic_flag(void)
{
return(mic_flag);
}
static guint dissect_wlccp_ccm_msg(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, guint8 _base_message_type)
{
proto_item *_ti;
proto_tree *_wlccp_eapol_msg_tree, *_wlccp_cm_flags_tree, *_wlccp_scm_flags_tree, *_wlccp_scm_priority_flags_tree, *_wlccp_scm_bridge_priority_flags_tree;
gboolean _relay_flag=0, _mic_flag=0, _tlv_flag=0;
guint8 _aaa_msg_type=0, _eapol_type=0;
guint16 _eap_msg_length=0;
proto_tree_add_item(_tree, hf_wlccp_hops,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_msg_id,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_ti = proto_tree_add_item(_tree, hf_wlccp_flags,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_wlccp_cm_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_cm_flags);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_retry_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_response_request_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_tlv_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_tlv_flag = (tvb_get_ntohs(_tvb, _offset)>>13) & 1;
set_tlv_flag(_tlv_flag);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_inbound_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_outbound_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_hopwise_routing_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_root_cm_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_relay_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_relay_flag = (tvb_get_ntohs(_tvb, _offset)>>8) & 1;
proto_tree_add_item(_wlccp_cm_flags_tree, hf_wlccp_mic_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_mic_flag = (tvb_get_ntohs(_tvb, _offset)>>7) & 1;
set_mic_flag(_mic_flag);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_responder_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_responder,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
if(_relay_flag)
{
proto_tree_add_item(_tree, hf_wlccp_relay_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_relay_node_id,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
}
switch (_base_message_type)
{
case 0x01:
{
proto_tree_add_item(_tree, hf_wlccp_scm_hop_address,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
_ti = proto_tree_add_item(_tree, hf_wlccp_scm_flags,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_wlccp_scm_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_scm_flags);
proto_tree_add_item(_wlccp_scm_flags_tree, hf_wlccp_scm_layer2update_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_scm_flags_tree, hf_wlccp_scm_unattached_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_scm_flags_tree, hf_wlccp_scm_unscheduled_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_scm_flags_tree, hf_wlccp_scm_active_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_scm_election_group,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_scm_attach_count,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_ti = proto_tree_add_item(_tree, hf_wlccp_scm_priority_flags,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_wlccp_scm_priority_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_scm_priority_flags);
proto_tree_add_item(_wlccp_scm_priority_flags_tree, hf_wlccp_scm_priority,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_scm_priority_flags_tree, hf_wlccp_scm_preferred_flag,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_ti = proto_tree_add_item(_tree, hf_wlccp_scm_bridge_priority_flags,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_wlccp_scm_bridge_priority_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_scm_bridge_priority_flags);
proto_tree_add_item(_wlccp_scm_bridge_priority_flags_tree, hf_wlccp_scm_bridge_priority,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_scm_bridge_priority_flags_tree, hf_wlccp_scm_bridge_disable_flag,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_scm_node_id,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_scm_unknown_short,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_scm_instance_age,
_tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_scm_path_cost,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_scm_hop_count,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_scm_advperiod,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
break;
}
case 0x02:
{
break;
}
case 0x03:
{
break;
}
case 0x04:
{
break;
}
case 0x05:
{
break;
}
case 0x06:
{
break;
}
case 0x07:
{
break;
}
case 0x08:
{
break;
}
case 0x09:
{
break;
}
case 0x0a:
{
break;
}
case 0x0b:
{
proto_tree_add_item(_tree, hf_wlccp_requ_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_requ_node_id,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_aaa_msg_type,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_aaa_msg_type=tvb_get_guint8(_tvb,_offset);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_aaa_auth_type,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_keymgmt_type,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_status,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
if (_aaa_msg_type == 0x2)
{
_ti = proto_tree_add_item(_tree, hf_wlccp_eapol_msg,
_tvb, _offset, 6, ENC_NA);
_wlccp_eapol_msg_tree = proto_item_add_subtree(
_ti, ett_wlccp_eapol_msg_tree);
_offset += 2;
proto_tree_add_item(_wlccp_eapol_msg_tree, hf_wlccp_eapol_version,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_wlccp_eapol_msg_tree, hf_wlccp_eapol_type,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_eapol_type=tvb_get_guint8(_tvb, _offset);
_offset += 1;
if (_eapol_type == 0)
{
proto_tree_add_item(_wlccp_eapol_msg_tree, hf_wlccp_eap_msg_length,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_eap_msg_length=tvb_get_ntohs(_tvb, _offset);
_offset += 2;
proto_tree_add_item(_wlccp_eapol_msg_tree, hf_wlccp_eap_msg,
_tvb, _offset, _eap_msg_length, ENC_NA);
_offset += _eap_msg_length;
}
}
if (_aaa_msg_type == 0x3)
{
proto_tree_add_item(_tree, hf_wlccp_cisco_acctg_msg,
_tvb, _offset, -1, ENC_NA);
}
break;
}
case 0x0c:
{
proto_tree_add_item(_tree, hf_wlccp_requ_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_requ_node_id,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_path_init_rsvd,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_status,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset +=1;
break;
}
case 0x0f:
{
proto_tree_add_item(_tree, hf_wlccp_wids_msg_type,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_status,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset +=1;
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_sec_msg(proto_tree *_tree _U_, tvbuff_t *_tvb _U_, guint _offset, guint8 _base_message_type)
{
switch (_base_message_type)
{
case 0x01:
{
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_rrm_msg(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, guint8 _base_message_type)
{
proto_tree *_wlccp_rm_flags_tree;
proto_item *_ti;
gboolean _mic_flag=0;
_ti = proto_tree_add_item(_tree, hf_wlccp_rm_flags,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_wlccp_rm_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_rm_flags);
proto_tree_add_item(_wlccp_rm_flags_tree, hf_wlccp_rm_mic_flag,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_mic_flag = (tvb_get_guint8(_tvb, _offset) & RM_F_MIC) >> 1;
set_mic_flag(_mic_flag);
set_tlv_flag(TRUE);
proto_tree_add_item(_wlccp_rm_flags_tree, hf_wlccp_rm_request_reply_flag,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_msg_id,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_responder_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_responder,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
switch (_base_message_type)
{
case 0x01:
{
break;
}
case 0x02:
{
break;
}
case 0x03:
{
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_qos_msg(proto_tree *_tree _U_, tvbuff_t *_tvb _U_, guint _offset, guint8 _base_message_type)
{
switch (_base_message_type)
{
case 0x01:
{
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_nm_msg(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, guint8 _base_message_type)
{
proto_item *_ti;
proto_tree *_wlccp_ap_node_id_tree, *_wlccp_nm_flags_tree;
gboolean _mic_flag=0, _tlv_flag=0;
proto_tree_add_item(_tree, hf_wlccp_nm_version,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_msg_id,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_ti = proto_tree_add_item(_tree, hf_wlccp_flags,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_wlccp_nm_flags_tree = proto_item_add_subtree(_ti, ett_wlccp_nm_flags);
proto_tree_add_item(_wlccp_nm_flags_tree, hf_wlccp_retry_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_nm_flags_tree, hf_wlccp_ack_required_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_wlccp_nm_flags_tree, hf_wlccp_tlv_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_tlv_flag = (tvb_get_ntohs(_tvb, _offset)>>13) & 1;
set_tlv_flag(_tlv_flag);
proto_tree_add_item(_wlccp_nm_flags_tree, hf_wlccp_mic_flag,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_mic_flag = (tvb_get_ntohs(_tvb, _offset)>>7) & 1;
set_mic_flag(_mic_flag);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_originator,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_responder_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_responder,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
switch (_base_message_type)
{
case 0x01:
{
break;
}
case 0x10:
{
proto_tree_add_item(_tree, hf_wlccp_nmconfig,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 3;
break;
}
case 0x11:
{
proto_tree_add_item(_tree, hf_wlccp_nmconfig,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 3;
break;
}
case 0x20:
{
proto_tree_add_item(_tree, hf_wlccp_timestamp,
_tvb, _offset, 8, ENC_BIG_ENDIAN);
_offset += 8;
proto_tree_add_item(_tree, hf_wlccp_apregstatus,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 3;
_ti = proto_tree_add_item(_tree, hf_wlccp_ap_node_id,
_tvb, _offset, 8, ENC_NA);
_wlccp_ap_node_id_tree = proto_item_add_subtree(
_ti, ett_wlccp_ap_node_id);
proto_tree_add_item(_wlccp_ap_node_id_tree, hf_wlccp_ap_node_type,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_wlccp_ap_node_id_tree, hf_wlccp_ap_node_id_address,
_tvb, _offset, 6, ENC_NA);
_offset += 6;
break;
}
case 0x21:
{
proto_tree_add_item(_tree, hf_wlccp_timestamp,
_tvb, _offset, 8, ENC_BIG_ENDIAN);
_offset += 8;
proto_tree_add_item(_tree, hf_wlccp_scmstate_change,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_scmstate_change_reason,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 2;
break;
}
case 0x22:
{
proto_tree_add_item(_tree, hf_wlccp_scmattach_state,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_nmconfig,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_nmcapability,
_tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
break;
}
case 0x30:
{
proto_tree_add_item(_tree, hf_wlccp_timestamp,
_tvb, _offset, 8, ENC_BIG_ENDIAN);
_offset += 8;
break;
}
case 0x31:
{
proto_tree_add_item(_tree, hf_wlccp_refresh_req_id,
_tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_mip_msg(proto_tree *_tree _U_, tvbuff_t *_tvb _U_, guint _offset, guint8 _base_message_type)
{
switch (_base_message_type)
{
case 0x01:
{
break;
}
default:
{
break;
}
}
return(_offset);
}
static guint dissect_wlccp_tlvs( proto_tree *_tree, tvbuff_t *_tvb, guint _offset, guint _depth)
{
proto_item *_ti, *_temp_ti;
proto_tree *_tlv_tree;
proto_tree *_tlv_flags_tree;
gboolean _container_flag=0;
gint _group_id=0, _type_id=0;
guint _length=0;
guint _tlv_end=0;
guint _old_offset;
_length = tvb_get_ntohs(_tvb,_offset+2);
_tlv_end = _offset + _length;
_ti = proto_tree_add_item(_tree, hf_wlccp_tlv, _tvb, _offset, _length, ENC_NA);
_tlv_tree = proto_item_add_subtree(_ti, ett_wlccp_tlv_tree);
_temp_ti = _ti;
DISSECTOR_ASSERT(_depth < 100);
_ti = proto_tree_add_item(_tlv_tree, hf_tlv_flags, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_tlv_flags_tree = proto_item_add_subtree(_ti, ett_tlv_flags_tree);
_group_id = (tvb_get_ntohs(_tvb,_offset) & TLV_GROUP_ID) >> 8;
_type_id = (tvb_get_ntohs(_tvb,_offset) & TLV_TYPE_ID);
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_container_flag, _tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_encrypted_flag, _tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_reserved_bit, _tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_group, _tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_request_flag, _tvb, _offset, 2, ENC_BIG_ENDIAN);
switch (_group_id)
{
case WLCCP_TLV_GROUP_WLCCP:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type0, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
case WLCCP_TLV_GROUP_SEC:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type1, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
case WLCCP_TLV_GROUP_RRM:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type2, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
case WLCCP_TLV_GROUP_QOS:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type3, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
case WLCCP_TLV_GROUP_NM:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type4, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
case WLCCP_TLV_GROUP_MIP:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type5, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
default:
{
proto_tree_add_item(_tlv_flags_tree, hf_wlccp_tlv_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
break;
}
}
_container_flag = (tvb_get_ntohs(_tvb, _offset) & TLV_F_CONTAINER) >> 15;
_offset += 2;
proto_tree_add_item(_tlv_tree, hf_wlccp_tlv_length, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
switch (_group_id)
{
case WLCCP_TLV_GROUP_WLCCP:
{
_offset = dissect_wlccp_ccm_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
case WLCCP_TLV_GROUP_SEC:
{
_offset = dissect_wlccp_sec_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
case WLCCP_TLV_GROUP_RRM:
{
_offset = dissect_wlccp_rrm_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
case WLCCP_TLV_GROUP_QOS:
{
_offset = dissect_wlccp_qos_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
case WLCCP_TLV_GROUP_NM:
{
_offset = dissect_wlccp_nm_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
case WLCCP_TLV_GROUP_MIP:
{
_offset = dissect_wlccp_mip_tlv(_tlv_tree, _tvb, _offset, _type_id, _length - 4, _temp_ti);
break;
}
default:
{
_offset = _tlv_end;
break;
}
}
if (_container_flag && (_offset >= _tlv_end) )
{
}
else
{
if (_container_flag && (_offset < _tlv_end) )
{
while (_offset < _tlv_end)
{
_old_offset = _offset;
_offset = dissect_wlccp_tlvs(_tlv_tree, _tvb, _offset, _depth++);
DISSECTOR_ASSERT(_offset > _old_offset);
}
}
}
return(_tlv_end);
}
static guint dissect_wlccp_ccm_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
case 0x00:
{
proto_item_append_text(_ti, " NULL TLV");
proto_tree_add_item(_tree, hf_wlccp_null_tlv , _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
case 0x09:
{
proto_item_append_text(_ti, " IPv4Address");
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
break;
}
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
static guint dissect_wlccp_sec_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
case 0x01:
{
proto_item_append_text(_ti, " initSession");
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_path_length, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 2;
break;
}
case 0x02:
{
proto_item_append_text(_ti, " inSecureContextReq");
proto_tree_add_item(_tree, hf_wlccp_key_seq_count, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_dest_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_dest_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_supp_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_supp_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_key_mgmt_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_nonce, _tvb, _offset, 32, ENC_NA);
_offset += 32;
break;
}
case 0x06:
{
proto_item_append_text(_ti, " authenticator");
proto_tree_add_item(_tree, hf_wlccp_dest_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_dest_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_src_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_src_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_key_seq_count, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_status, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_nonce, _tvb, _offset, 32, ENC_NA);
_offset += 32;
break;
}
case 0x08:
{
guint16 _mic_length=0;
proto_item_append_text(_ti, " mic");
proto_tree_add_item(_tree, hf_wlccp_mic_msg_seq_count, _tvb, _offset, 8, ENC_BIG_ENDIAN);
_offset += 8;
proto_tree_add_item(_tree, hf_wlccp_mic_length, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_mic_length = tvb_get_ntohs(_tvb,_offset);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_mic_value, _tvb, _offset, _mic_length, ENC_NA);
_offset += _mic_length;
break;
}
case 0x0a:
{
proto_item_append_text(_ti, " inSecureContextReply");
proto_tree_add_item(_tree, hf_wlccp_key_seq_count, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_dest_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_dest_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_supp_node_type, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_supp_node_id, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_nonce, _tvb, _offset, 32, ENC_NA);
_offset += 32;
proto_tree_add_item(_tree, hf_wlccp_session_timeout, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
break;
}
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
static guint dissect_wlccp_rrm_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
case 0x02:
{
proto_item_append_text(_ti, " aggrRmReq");
proto_tree_add_item(_tree, hf_wlccp_token2, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_interval, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x03 :
{
proto_item_append_text(_ti, " rmReport");
proto_tree_add_item(_tree, hf_wlccp_sta_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_stamac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
break;
}
case 0x04:
{
proto_item_append_text(_ti, " aggrRmReport");
break;
}
case 0x12:
{
proto_item_append_text(_ti, " beaconRequest");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_scan_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x14:
{
guint _count=0, _counter=0;
proto_item_append_text(_ti, " frameRequest");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_count, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_count = tvb_get_guint8(_tvb,_offset);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
for (_counter=0; _counter < _count; _counter++)
{
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
}
break;
}
case 0x15:
{
proto_item *_fr_ti;
proto_tree *_fr_elems_tree;
guint _counter=0, _arraylen=0;
proto_item_append_text(_ti, " frameReport");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_arraylen=(_length-10)/14;
if (_arraylen > 0)
{
_fr_ti = proto_tree_add_item(_tree, hf_framereport_elements, _tvb, _offset, (_length-10), ENC_NA);
_fr_elems_tree = proto_item_add_subtree(_fr_ti, ett_framereport_elements_tree);
for(_counter=0; _counter < _arraylen; _counter++)
{
proto_tree_add_item(_fr_elems_tree, hf_wlccp_numframes, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_fr_elems_tree, hf_wlccp_rss, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_fr_elems_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_fr_elems_tree, hf_wlccp_stamac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
}
}
break;
}
case 0x16:
{
proto_item_append_text(_ti, " ccaRequest");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x17:
{
proto_item_append_text(_ti, " ccaReport");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_ccabusy, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
break;
}
case 0x18:
{
proto_item_append_text(_ti, " rpiHistRequest");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x19:
{
guint _rpi_density_length=0;
proto_item_append_text(_ti, " rpiHistReport");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_rpi_density_length = _length - 6 - 4;
proto_tree_add_item(_tree, hf_wlccp_rpidensity, _tvb, _offset, _rpi_density_length, ENC_NA);
_offset += _rpi_density_length;
break;
}
case 0x1c:
{
proto_item_append_text(_ti, " nullRequest");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_duration, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x1e:
{
proto_tree *_80211_capabilities_tree;
proto_item *_new_ti;
guint _tlv80211length=0;
proto_item_append_text(_ti, " commonBeaconReport");
proto_tree_add_item(_tree, hf_wlccp_srcidx, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_channel, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_phy_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_beacon_interval, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_new_ti = proto_tree_add_item(_tree, hf_wlccp_80211_capabilities,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_80211_capabilities_tree = proto_item_add_subtree(_new_ti, ett_80211_capability_flags_tree);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_imm_block_ack,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_dlyd_block_ack,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_dsss_ofdm,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_reserved,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_apsd,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_short_time_slot,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_qos,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_spectrum_mgmt,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_chan_agility,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_pbcc,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_short_preamble,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_cap_privacy,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_cap_cf_poll_req,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_cap_cf_pollable,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_cap_ibss,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(_80211_capabilities_tree, hf_80211_cap_ess,
_tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_tlv80211length = _length - 13 - 4;
proto_tree_add_item(_tree, hf_wlccp_tlv80211, _tvb, _offset, _tlv80211length, ENC_NA);
_offset += _tlv80211length;
break;
}
case 0x1f:
{
proto_item_append_text(_ti, " aggrBeaconReport");
proto_tree_add_item(_tree, hf_wlccp_token, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_mode, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_rss, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_srcidx, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_parent_tsf, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_target_tsf, _tvb, _offset, 8, ENC_BIG_ENDIAN);
_offset += 8;
break;
}
case 0x20:
{
guint _counter=0, _arraylen=0;
proto_item_append_text(_ti, " rmReqRoutingList");
_arraylen=(_length)/16;
if (_arraylen > 0)
{
for(_counter=0; _counter < _arraylen; _counter++)
{
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_stamac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
}
}
break;
}
case 0x21:
{
guint _counter=0, _arraylen=0;
proto_item_append_text(_ti, " rmReqRoutingResp");
proto_tree_add_item(_tree, hf_wlccp_token2, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
_arraylen=(_length)/11;
if (_arraylen > 0)
{
for(_counter=0; _counter < _arraylen; _counter++)
{
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_status, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
}
}
break;
}
case 0x22:
{
proto_item_append_text(_ti, " rmReqAck");
proto_tree_add_item(_tree, hf_wlccp_status, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
break;
}
case 0x58:
{
proto_item_append_text(_ti, " mfpCapability");
proto_tree_add_item(_tree, hf_wlccp_mfpcapability, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x5b:
{
proto_item_append_text(_ti, " mfpRouting");
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_bssid, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wlccp_mfpflags, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
case 0x5c:
{
proto_item_append_text(_ti, " mfpConfig");
proto_tree_add_item(_tree, hf_wlccp_mfpconfig, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
break;
}
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
static guint dissect_wlccp_qos_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
static guint dissect_wlccp_nm_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
case 0x20:
{
guint _radius_user_name_length = 0;
proto_item_append_text(_ti, " nmClientEventIntoWDS");
proto_tree_add_item(_tree, hf_wlccp_clientmac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_parent_ap_mac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_reg_lifetime, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_auth_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_key_mgmt_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
_radius_user_name_length = _length - 23 - 4;
proto_tree_add_item(_tree, hf_wlccp_radius_user_name, _tvb, _offset, _radius_user_name_length, ENC_ASCII|ENC_NA);
_offset += _radius_user_name_length;
break;
}
case 0x21:
{
proto_item_append_text(_ti, " nmClientEventOutOfWDS");
proto_tree_add_item(_tree, hf_wlccp_clientmac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_parent_ap_mac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_wds_reason, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
break;
}
case 0x22:
{
proto_item_append_text(_ti, " nmClientEventIntraWDS");
proto_tree_add_item(_tree, hf_wlccp_clientmac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_parent_ap_mac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_reg_lifetime, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_auth_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_key_mgmt_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 3;
break;
}
case 0x24:
{
proto_item_append_text(_ti, " nmClientEventIPAddressUpdate");
proto_tree_add_item(_tree, hf_wlccp_clientmac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_parent_ap_mac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
break;
}
case 0x26:
{
guint _radius_user_name_length = 0;
proto_item_append_text(_ti, " nmClientEventRefresh");
proto_tree_add_item(_tree, hf_wlccp_clientmac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_parent_ap_mac, _tvb, _offset, 6, ENC_NA);
_offset += 6;
proto_tree_add_item(_tree, hf_reg_lifetime, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_ipv4_address, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
proto_tree_add_item(_tree, hf_wlccp_auth_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
proto_tree_add_item(_tree, hf_wlccp_key_mgmt_type, _tvb, _offset, 1, ENC_BIG_ENDIAN);
_offset += 1;
_offset += 1;
_radius_user_name_length = _length - 23 - 4;
proto_tree_add_item(_tree, hf_wlccp_radius_user_name, _tvb, _offset, _radius_user_name_length, ENC_ASCII|ENC_NA);
_offset += _radius_user_name_length;
break;
}
case 0x27:
{
proto_item_append_text(_ti, " nmClientEventRefreshDone");
_offset += 6;
proto_tree_add_item(_tree, hf_time_elapsed, _tvb, _offset, 2, ENC_BIG_ENDIAN);
_offset += 2;
proto_tree_add_item(_tree, hf_wlccp_refresh_req_id, _tvb, _offset, 4, ENC_BIG_ENDIAN);
_offset += 4;
break;
}
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
static guint dissect_wlccp_mip_tlv(proto_tree *_tree, tvbuff_t *_tvb, guint _offset, gint _type_id, guint _length, proto_item *_ti)
{
switch (_type_id)
{
default:
{
proto_item_append_text(_ti, " Unknown");
proto_tree_add_item(_tree, hf_wlccp_tlv_unknown_value, _tvb, _offset, _length, ENC_NA);
_offset += _length;
break;
}
}
return(_offset);
}
void
proto_register_wlccp(void)
{
static hf_register_info hf[] = {
{ &hf_wlccp_version,
{ "Version", "wlccp.version",
FT_UINT8, BASE_HEX, NULL,
0x0, "Protocol ID/Version", HFILL }
},
{ &hf_wlccp_srcmac,
{ "Src MAC", "wlccp.srcmac",
FT_ETHER, BASE_NONE, NULL,
0x0, "Source MAC address", HFILL }
},
{ &hf_wlccp_dstmac,
{ "Dst MAC", "wlccp.dstmac",
FT_ETHER, BASE_NONE, NULL,
0x0, "Destination MAC address", HFILL }
},
{ &hf_wlccp_hostname,
{ "Hostname", "wlccp.hostname",
FT_STRING, BASE_NONE, NULL,
0x0, "Hostname of device", HFILL }
},
{ &hf_wlccp_sap,
{ "SAP", "wlccp.sap",
FT_UINT8, BASE_HEX, NULL,
0x0, "Service Access Point", HFILL }
},
{ &hf_wlccp_sap_version,
{ "SAP Version", "wlccp.sap_version",
FT_UINT8, BASE_DEC, NULL,
SAP_VERSION_MASK, "Service Access Point Version", HFILL }
},
{ &hf_wlccp_sap_id,
{ "SAP ID", "wlccp.sap_id",
FT_UINT8, BASE_DEC, VALS(wlccp_sap_vs),
SAP_VALUE_MASK, "Service Access Point ID", HFILL }
},
{ &hf_wlccp_destination_node_type,
{ "Destination node type", "wlccp.destination_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, "Node type of the hop destination", HFILL }
},
{ &hf_wlccp_length,
{ "Length", "wlccp.length",
FT_UINT16, BASE_DEC, NULL,
0x0, "Length of WLCCP payload (bytes)", HFILL }
},
{ &hf_wlccp_type,
{ "Message Type", "wlccp.type",
FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_subtype,
{ "Subtype", "wlccp.subtype",
FT_UINT8, BASE_DEC, VALS(wlccp_subtype_vs),
MT_SUBTYPE, "Message Subtype", HFILL }
},
{ &hf_wlccp_base_message_type_0,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_0),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_1,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_1),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_2,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_2),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_3,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_3),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_4,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_4),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_5,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, VALS(wlccp_msg_type_vs_5),
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_base_message_type_unknown,
{ "Base message type", "wlccp.base_message_type",
FT_UINT8, BASE_HEX_DEC, NULL,
MT_BASE_MSG_TYPE, NULL, HFILL }
},
{ &hf_wlccp_hops,
{ "Hops", "wlccp.hops",
FT_UINT8, BASE_DEC, NULL,
0x0, "Number of WLCCP hops", HFILL }
},
{ &hf_wlccp_nm_version,
{ "NM Version", "wlccp.nm_version",
FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_msg_id,
{ "Message ID", "wlccp.msg_id",
FT_UINT16, BASE_DEC, NULL,
0x0, "Sequence number used to match request/reply pairs",
HFILL }
},
{ &hf_wlccp_flags,
{ "Flags", "wlccp.flags",
FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_rm_flags,
{ "RM Flags", "wlccp.rm_flags",
FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_retry_flag,
{ "Retry flag", "wlccp.retry_flag",
FT_UINT16, BASE_DEC, NULL,
F_RETRY, "Set on for retransmissions", HFILL }
},
{ &hf_wlccp_response_request_flag,
{ "Response request flag", "wlccp.response_request_flag",
FT_UINT16, BASE_DEC, NULL,
F_RESPONSE_REQUEST, "Set on to request a reply", HFILL }
},
{ &hf_wlccp_rm_request_reply_flag,
{ "Request Reply flag", "wlccp.request_reply_flag",
FT_UINT8, BASE_DEC, NULL,
RM_F_REQUEST_REPLY, "Set on to request a reply", HFILL }
},
{ &hf_wlccp_ack_required_flag,
{ "Ack Required flag", "wlccp.ack_required_flag",
FT_UINT16, BASE_DEC, NULL,
F_ACK_REQD, "Set on to require an acknowledgement", HFILL }
},
{ &hf_wlccp_tlv_flag,
{ "TLV flag", "wlccp.tlv_flag",
FT_UINT16, BASE_DEC, NULL,
F_TLV, "Set to indicate that optional TLVs follow the fixed fields", HFILL }
},
{ &hf_wlccp_inbound_flag,
{ "Inbound flag", "wlccp.inbound_flag",
FT_UINT16, BASE_DEC, NULL,
F_INBOUND, "Message is inbound to the top of the topology tree", HFILL }
},
{ &hf_wlccp_outbound_flag,
{ "Outbound flag", "wlccp.outbound_flag",
FT_UINT16, BASE_DEC, NULL,
F_OUTBOUND, "Message is outbound from the top of the topology tree", HFILL }
},
{ &hf_wlccp_hopwise_routing_flag,
{ "Hopwise-routing flag", "wlccp.hopwise_routing_flag",
FT_UINT16, BASE_DEC, NULL,
F_HOPWISE_ROUTING, "On to force intermediate access points to process the message also", HFILL }
},
{ &hf_wlccp_root_cm_flag,
{ "Root context manager flag", "wlccp.root_cm_flag",
FT_UINT16, BASE_DEC, NULL,
F_ROOT_CM, "Set to on to send message to the root context manager of the topology tree", HFILL }
},
{ &hf_wlccp_relay_flag,
{ "Relay flag", "wlccp.relay_flag",
FT_UINT16, BASE_DEC, NULL,
F_RELAY, "Signifies that this header is immediately followed by a relay node field", HFILL }
},
{ &hf_wlccp_mic_flag,
{ "MIC flag", "wlccp.mic_flag",
FT_UINT16, BASE_DEC, NULL,
F_MIC, "On in a message that must be authenticated and has an authentication TLV", HFILL }
},
{ &hf_wlccp_rm_mic_flag,
{ "MIC flag", "wlccp.mic_flag",
FT_UINT8, BASE_DEC, NULL,
RM_F_MIC, "On in a message that must be authenticated and has an authentication TLV", HFILL }
},
{ &hf_wlccp_originator_node_type,
{ "Originator node type", "wlccp.originator_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, "Originating device's node type", HFILL }
},
{ &hf_wlccp_originator,
{ "Originator", "wlccp.originator",
FT_ETHER, BASE_NONE, NULL,
0x0, "Originating device's MAC address", HFILL }
},
{ &hf_wlccp_responder_node_type,
{ "Responder node type", "wlccp.responder_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, "Responding device's node type", HFILL }
},
{ &hf_wlccp_responder,
{ "Responder", "wlccp.responder",
FT_ETHER, BASE_NONE, NULL,
0x0, "Responding device's MAC address", HFILL }
},
{ &hf_wlccp_requ_node_type,
{ "Requestor node type", "wlccp.requ_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, "Requesting device's node type", HFILL }
},
{ &hf_wlccp_requ_node_id,
{ "Requestor", "wlccp.requestor",
FT_ETHER, BASE_NONE, NULL,
0x0, "Requestor device's MAC address", HFILL }
},
{ &hf_wlccp_status,
{ "Status", "wlccp.status",
FT_UINT8, BASE_DEC, VALS(wlccp_status_vs),
0x0, NULL, HFILL }
},
{ &hf_wlccp_path_init_rsvd,
{ "Reserved", "wlccp.path_init_reserved",
FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_relay_node_type,
{ "Relay node type", "wlccp.relay_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, "Type of node which relayed this message", HFILL }
},
{ &hf_wlccp_relay_node_id,
{ "Relay node ID", "wlccp.relay_node_id",
FT_ETHER, BASE_NONE, NULL,
0x0, "Node which relayed this message", HFILL }
},
#if 0
{ &hf_wlccp_priority,
{ "WDS priority", "wlccp.priority",
FT_UINT8, BASE_DEC, NULL, 0,
"WDS priority of this access point", HFILL }
},
#endif
#if 0
{ &hf_wlccp_age,
{ "Age", "wlccp.age",
FT_UINT32, BASE_DEC, NULL, 0,
"Time since AP became a WDS master", HFILL }
},
#endif
#if 0
{ &hf_wlccp_period,
{ "Period", "wlccp.period",
FT_UINT8, BASE_DEC, NULL, 0,
"Interval between announcements (seconds)", HFILL }
},
#endif
{ &hf_wlccp_ipv4_address,
{ "IPv4 Address", "wlccp.ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scm_hop_address,
{ "Hop Address", "wlccp.scm_hop_address",
FT_ETHER, BASE_NONE, NULL,
0x0, "Source 802 Port Address", HFILL }
},
{ &hf_wlccp_scm_flags,
{ "SCM flags", "wlccp.scm_flags",
FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_scm_active_flag,
{ "Active flag", "wlccp.scm_active_flag",
FT_UINT16, BASE_DEC, NULL,
F_SCM_ACTIVE, "Set to on in advertisements from the active SCM", HFILL }
},
{ &hf_wlccp_scm_unscheduled_flag,
{ "Unscheduled flag", "wlccp.scm_unscheduled_flag",
FT_UINT16, BASE_DEC, NULL,
F_SCM_UNSCHEDULED, "Set to on in unscheduled advertisement messages", HFILL }
},
{ &hf_wlccp_scm_unattached_flag,
{ "Unattached flag", "wlccp.scm_unattached_flag",
FT_UINT16, BASE_DEC, NULL,
F_SCM_UNATTACHED, "Set to on in advertisements from an unattached node", HFILL }
},
{ &hf_wlccp_scm_layer2update_flag,
{ "Layer2 Update flag", "wlccp.scm_layer2update_flag",
FT_UINT16, BASE_DEC, NULL,
F_SCM_LAYER2UPDATE, "Set to on if WLCCP Layer 2 path updates are enabled", HFILL }
},
{ &hf_wlccp_scm_election_group,
{ "SCM Election Group", "wlccp.scm_election_group",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scm_attach_count,
{ "Attach Count", "wlccp.scm_attach_count",
FT_UINT8, BASE_DEC, NULL, 0,
"Attach count of the hop source", HFILL }
},
{ &hf_wlccp_scm_priority_flags,
{ "SCM Priority flags", "wlccp.scm_priority_flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scm_priority,
{ "SCM Priority", "wlccp.scm_priority",
FT_UINT8, BASE_DEC, NULL,
F_SCM_PRIORITY, NULL, HFILL }
},
{ &hf_wlccp_scm_preferred_flag,
{ "Preferred flag", "wlccp.scm_preferred_flag",
FT_UINT8, BASE_DEC, NULL,
F_SCM_PREFERRED, "Set to off if the SCM is the preferred SCM", HFILL }
},
{ &hf_wlccp_scm_bridge_priority_flags,
{ "Bridge Priority flags", "wlccp.scm_bridge_priority_flags",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scm_bridge_priority,
{ "Bridge priority", "wlccp.scm_bridge_priority",
FT_UINT8, BASE_DEC, NULL,
F_SCM_BRIDGE_PRIORITY, "Used to negotiate the designated bridge on a non-STP secondary Ethernet LAN", HFILL }
},
{ &hf_wlccp_scm_bridge_disable_flag,
{ "Bridge disable flag", "wlccp.scm_bridge_disable_flag",
FT_UINT8, BASE_DEC, NULL,
F_SCM_BRIDGE_DISABLE, "Set to on to indicate that secondary briding is disabled", HFILL }
},
{ &hf_wlccp_scm_node_id,
{ "SCM Node ID", "wlccp.scm_node_id",
FT_ETHER, BASE_NONE, NULL,
0x0, "Node ID of the SCM", HFILL }
},
{ &hf_wlccp_scm_unknown_short,
{ "Unknown Short", "wlccp.scm_unknown_short",
FT_UINT16, BASE_HEX, NULL,
0x0, "SCM Unknown Short Value", HFILL }
},
{ &hf_wlccp_scm_instance_age,
{ "Instance Age", "wlccp.scm_instance_age",
FT_UINT32, BASE_DEC, NULL, 0,
"Instance age of the SCM in seconds", HFILL }
},
{ &hf_wlccp_scm_path_cost,
{ "Path cost", "wlccp.scm_path_cost",
FT_UINT16, BASE_DEC, NULL,
0x0, "Sum of port costs on the path to the SCM", HFILL }
},
{ &hf_wlccp_scm_hop_count,
{ "Hop Count", "wlccp.scm_hop_count",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of wireless hops on the path to SCM", HFILL }
},
{ &hf_wlccp_scm_advperiod,
{ "Advertisement Period", "wlccp.scm_advperiod",
FT_UINT8, BASE_DEC, NULL, 0,
"Average number of seconds between SCM advertisements", HFILL }
},
{ &hf_wlccp_timestamp,
{ "Timestamp", "wlccp.timestamp",
FT_UINT64, BASE_DEC, NULL, 0,
"Registration Timestamp", HFILL }
},
{ &hf_wlccp_apregstatus,
{ "Registration Status", "wlccp.apregstatus",
FT_UINT8, BASE_HEX, NULL, 0,
"AP Registration Status", HFILL }
},
{ &hf_wlccp_ap_node_id,
{ "AP Node ID", "wlccp.apnodeid",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_ap_node_type,
{ "AP Node Type", "wlccp.apnodetype",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_ap_node_id_address,
{ "AP Node Address", "wlccp.apnodeidaddress",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_aaa_msg_type,
{ "AAA Message Type", "wlccp.aaa_msg_type",
FT_UINT8, BASE_HEX, VALS(wlccp_aaa_msg_type_vs), 0,
NULL, HFILL }
},
{ &hf_wlccp_aaa_auth_type,
{ "AAA Authentication Type", "wlccp.aaa_auth_type",
FT_UINT8, BASE_HEX, VALS(wlccp_eapol_auth_type_vs), 0,
NULL, HFILL }
},
{ &hf_wlccp_keymgmt_type,
{ "AAA Key Management Type", "wlccp.aaa_keymgmt_type",
FT_UINT8, BASE_HEX, VALS(wlccp_key_mgmt_type_vs), 0,
NULL, HFILL }
},
{ &hf_wlccp_eapol_msg,
{ "EAPOL Message", "wlccp.eapol_msg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_eapol_version,
{ "EAPOL Version", "wlccp.eapol_version",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_eapol_type,
{ "EAPOL Type", "wlccp.eapol_type",
FT_UINT8, BASE_HEX, VALS(eapol_type_vs), 0,
NULL, HFILL }
},
{ &hf_wlccp_eap_msg_length,
{ "EAP Packet Length", "wlccp.eap_pkt_length",
FT_UINT16, BASE_DEC, NULL, 0,
"EAPOL Type", HFILL }
},
{ &hf_wlccp_eap_msg,
{ "EAP Message", "wlccp.eap_msg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_cisco_acctg_msg,
{ "Cisco Accounting Message", "wlccp.cisco_acctg_msg",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_wids_msg_type,
{ "WIDS Message Type", "wlccp.wids_msg_type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_nmconfig,
{ "NM Config", "wlccp.nmconfig",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scmstate_change,
{ "SCM State Change", "wlccp.scmstate_change",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scmstate_change_reason,
{ "SCM State Change Reason", "wlccp.scmstate_change_reason",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scmattach_state,
{ "SCM Attach State", "wlccp.scmattach_state",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_nmcapability,
{ "NM Capability", "wlccp.nm_capability",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_refresh_req_id,
{ "Refresh Request ID", "wlccp.refresh_request_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_tlv,
{ "WLCCP TLV", "wlccp.tlv",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_tlv_flags,
{ "TLV Flags", "wlccp.tlv_flags",
FT_UINT16, BASE_HEX, NULL, 0,
"TLV Flags, Group and Type", HFILL }
},
{ &hf_wlccp_null_tlv,
{ "NULL TLV", "wlccp.null_tlv",
FT_BYTES, BASE_NONE, NULL ,
0, NULL, HFILL }
},
{ &hf_wlccp_tlv_type,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, NULL ,
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type0,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_0),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type1,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_1),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type2,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_2),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type3,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_3),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type4,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_4),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_type5,
{ "TLV Type", "wlccp.tlv_type",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_typeID_5),
TLV_TYPE_ID, "TLV Type ID", HFILL }
},
{ &hf_wlccp_tlv_group,
{ "TLV Group", "wlccp.tlv_group",
FT_UINT16, BASE_DEC, VALS(wlccp_tlv_group_vs) ,
TLV_GROUP_ID, "TLV Group ID", HFILL }
},
{ &hf_wlccp_tlv_container_flag,
{ "TLV Container Flag", "wlccp.tlv_container_flag",
FT_UINT16, BASE_DEC, NULL,
TLV_F_CONTAINER, "Set on if the TLV is a container", HFILL }
},
{ &hf_wlccp_tlv_encrypted_flag,
{ "TLV Encrypted Flag", "wlccp.tlv_encrypted_flag",
FT_UINT16, BASE_DEC, NULL,
TLV_F_ENCRYPTED, "Set on if the TLV is encrypted", HFILL }
},
{ &hf_wlccp_tlv_reserved_bit,
{ "Reserved bits", "wlccp.tlv_reserved_bit",
FT_UINT16, BASE_DEC, NULL,
TLV_F_RESVD, "Reserved", HFILL }
},
{ &hf_wlccp_tlv_request_flag,
{ "TLV Request Flag", "wlccp.tlv_request_flag",
FT_UINT16, BASE_DEC, NULL,
TLV_F_REQUEST, "Set on if the TLV is a request", HFILL }
},
{ &hf_wlccp_tlv_length,
{ "TLV Length", "wlccp.tlv_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_path_length,
{ "Path Length", "wlccp.path_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mic_msg_seq_count,
{ "MIC Message Sequence Count", "wlccp.mic_msg_seq_count",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mic_length,
{ "MIC Length", "wlccp.mic_length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mic_value,
{ "MIC Value", "wlccp.mic_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_dest_node_type,
{ "Destination node type", "wlccp.dest_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, NULL, HFILL }
},
{ &hf_wlccp_dest_node_id,
{ "Destination node ID", "wlccp.dest_node_id",
FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_supp_node_type,
{ "Destination node type", "wlccp.supp_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, NULL, HFILL }
},
{ &hf_wlccp_supp_node_id,
{ "Supporting node ID", "wlccp.supp_node_id",
FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_src_node_type,
{ "Source node type", "wlccp.source_node_type",
FT_UINT16, BASE_DEC, VALS(wlccp_node_type_vs),
0x0, NULL, HFILL }
},
{ &hf_wlccp_src_node_id,
{ "Source node ID", "wlccp.source_node_id",
FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_key_mgmt_type,
{ "Key Management type", "wlccp.key_mgmt_type",
FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_wlccp_key_seq_count,
{ "Key Sequence Count", "wlccp.key_seq_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_session_timeout,
{ "Session Timeout", "wlccp.session_timeout",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_nonce,
{ "Nonce Value", "wlccp.nonce_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_token,
{ "Token", "wlccp.token",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_scan_mode,
{ "Scan Mode", "wlccp.scan_mode",
FT_UINT8, BASE_HEX, NULL,
0, NULL, HFILL }
},
{ &hf_wlccp_mode,
{ "Mode", "wlccp.mode",
FT_UINT8, BASE_HEX, VALS(wlccp_mode_vs),
0, NULL, HFILL }
},
{ &hf_wlccp_rss,
{ "RSS", "wlccp.rss",
FT_INT8, BASE_DEC, NULL, 0,
"Received Signal Strength", HFILL }
},
{ &hf_wlccp_srcidx,
{ "Source Index", "wlccp.srcidx",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_parent_tsf,
{ "Parent TSF", "wlccp.parenttsf",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_target_tsf,
{ "Target TSF", "wlccp.targettsf",
FT_UINT64, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_channel,
{ "Channel", "wlccp.channel",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_phy_type,
{ "PHY Type", "wlccp.phy_type",
FT_UINT8, BASE_DEC, VALS(phy_type_80211_vs), 0,
NULL, HFILL }
},
{ &hf_wlccp_bssid,
{ "BSS ID", "wlccp.bssid",
FT_ETHER, BASE_NONE, NULL, 0,
"Basic Service Set ID", HFILL }
},
{ &hf_wlccp_beacon_interval,
{ "Beacon Interval", "wlccp.beacon_interval",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_80211_capabilities,
{ "802.11 Capabilities Flags", "wlccp.80211_capabilities",
FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }
},
{ &hf_80211_cap_ess,
{ "ESS flag", "wlccp.80211_ess_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_ESS, "Set on by APs in Beacon or Probe Response", HFILL }
},
{ &hf_80211_cap_ibss,
{ "IBSS flag", "wlccp.80211_ibss_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_IBSS, "Set on by STAs in Beacon or Probe Response", HFILL }
},
{ &hf_80211_cap_cf_pollable,
{ "CF Pollable flag", "wlccp.80211_cf_pollable_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_CFPOLL, NULL, HFILL }
},
{ &hf_80211_cap_cf_poll_req,
{ "CF Poll Request flag", "wlccp.80211_cf_poll_req_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_CFPOLL_REQ, NULL, HFILL }
},
{ &hf_80211_cap_privacy,
{ "Privacy flag", "wlccp.80211_cf_poll_req_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_PRIVACY, "Set on indicate confidentiality is required in the BSS", HFILL }
},
{ &hf_80211_short_preamble,
{ "Short Preamble flag", "wlccp.80211_short_preamble_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_SHORT_PREAMBLE, NULL, HFILL }
},
{ &hf_80211_pbcc,
{ "PBCC flag", "wlccp.80211_pbcc_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_PBCC, NULL, HFILL }
},
{ &hf_80211_chan_agility,
{ "Channel Agility flag", "wlccp.80211_chan_agility_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_CH_AGILITY, NULL, HFILL }
},
{ &hf_80211_spectrum_mgmt,
{ "Spectrum Management flag", "wlccp.80211_spectrum_mgmt_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_SPEC_MGMT, NULL, HFILL }
},
{ &hf_80211_qos,
{ "QOS flag", "wlccp.80211_qos_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_QOS, NULL, HFILL }
},
{ &hf_80211_short_time_slot,
{ "Short Time Slot flag", "wlccp.80211_short_time_slot_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_SHORT_TIME_SLOT, NULL, HFILL }
},
{ &hf_80211_apsd,
{ "APSD flag", "wlccp.80211_apsd_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_APSD, NULL, HFILL }
},
{ &hf_80211_reserved,
{ "Reserved", "wlccp.80211_reserved",
FT_UINT16, BASE_DEC, NULL,
F_80211_RESVD, NULL, HFILL }
},
{ &hf_80211_dsss_ofdm,
{ "DSSS-OFDM Flag", "wlccp.dsss_ofdm_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_DSSS_OFDM, NULL, HFILL }
},
{ &hf_80211_dlyd_block_ack,
{ "Delayed Block Ack Flag", "wlccp.dsss_dlyd_block_ack_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_DLYD_BLK_ACK, NULL, HFILL }
},
{ &hf_80211_imm_block_ack,
{ "Immediate Block Ack Flag", "wlccp.dsss_imm_block_ack_flag",
FT_UINT16, BASE_DEC, NULL,
F_80211_IMM_BLK_ACK, NULL, HFILL }
},
{ &hf_wlccp_tlv80211,
{ "802.11 TLV Value", "wlccp.tlv80211",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_duration,
{ "Duration", "wlccp.duration",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_rpidensity,
{ "RPI Density", "wlccp.rpi_denisty",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_ccabusy,
{ "CCA Busy", "wlccp.cca_busy",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_stamac,
{ "Station MAC", "wlccp.station_mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_sta_type,
{ "Station Type", "wlccp.station_type",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_token2,
{ "2 Byte Token", "wlccp.token2",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_interval,
{ "Interval", "wlccp.interval",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_framereport_elements,
{ "Frame Report Elements", "wlccp.framereport_elements",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_count,
{ "Element Count", "wlccp.element_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_numframes,
{ "Number of frames", "wlccp.numframes",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mfpcapability,
{ "MFP Capability", "wlccp.mfp_capability",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mfpflags,
{ "MFP Flags", "wlccp.mfp_flags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_mfpconfig,
{ "MFP Config", "wlccp.mfp_config",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_clientmac,
{ "Client MAC", "wlccp.client_mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_reg_lifetime,
{ "Reg. LifeTime", "wlccp.reg_lifetime",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_time_elapsed,
{ "Elapsed Time", "wlccp.time_elapsed",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_parent_ap_mac,
{ "Parent AP MAC", "wlccp.parent_ap_mac",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_auth_type,
{ "Authentication Type", "wlccp.auth_type",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_radius_user_name,
{ "RADIUS Username", "wlccp.radius_username",
FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL }
},
{ &hf_wds_reason,
{ "Reason Code", "wlccp.wds_reason",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_wlccp_tlv_unknown_value,
{ "Unknown TLV Contents", "wlccp.tlv_unknown_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
}
};
static hf_register_info oui_hf[] = {
{ &hf_llc_wlccp_pid,
{ "PID", "llc.wlccp_pid",
FT_UINT16, BASE_HEX, VALS(cisco_pid_vals),
0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_wlccp,
&ett_wlccp_sap_tree,
&ett_wlccp_type,
&ett_wlccp_flags,
&ett_wlccp_cm_flags,
&ett_wlccp_scm_flags,
&ett_wlccp_scm_priority_flags,
&ett_wlccp_scm_bridge_priority_flags,
&ett_wlccp_rm_flags,
&ett_wlccp_nm_flags,
&ett_wlccp_ap_node_id,
&ett_wlccp_eapol_msg_tree,
&ett_wlccp_eap_tree,
&ett_wlccp_tlv_tree,
&ett_tlv_flags_tree,
&ett_tlv_sub_tree,
&ett_80211_capability_flags_tree,
&ett_framereport_elements_tree
};
proto_wlccp = proto_register_protocol("Cisco Wireless LAN Context Control Protocol", "WLCCP", "wlccp");
proto_register_field_array(proto_wlccp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
llc_add_oui(OUI_CISCOWL, "llc.wlccp_pid", "LLC Cisco WLCCP OUI PID", oui_hf, proto_wlccp);
}
void
proto_reg_handoff_wlccp(void)
{
dissector_handle_t wlccp_handle;
wlccp_handle = create_dissector_handle(dissect_wlccp, proto_wlccp);
dissector_add_uint("ethertype", ETHERTYPE_WLCCP, wlccp_handle);
dissector_add_uint("udp.port", WLCCP_UDP_PORT, wlccp_handle);
dissector_add_uint("llc.wlccp_pid", 0x0000, wlccp_handle);
}
