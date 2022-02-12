static void
dissect_a21_correlation_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
proto_item *tc;
proto_tree *corr_tree;
if (tree == NULL)
return;
tc = proto_tree_add_item(tree, hf_a21_corr_id, tvb, offset, 6, ENC_BIG_ENDIAN);
corr_tree = proto_item_add_subtree(tc,ett_a21_corr_id);
proto_tree_add_item(corr_tree, hf_a21_element_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(corr_tree, hf_a21_element_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(corr_tree, hf_a21_corr_id_corr_value, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_a21_mobile_identity(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_)
{
int offset = 0;
guint identity_type;
const gchar *imsi_str;
if (tree == NULL)
return;
identity_type = tvb_get_guint8(tvb, offset) & 0x07;
proto_tree_add_item(tree, hf_a21_mn_id_type_of_identity, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (identity_type) {
case 0:
proto_tree_add_item(tree, hf_a21_mn_id_msid_value, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(tree, hf_a21_mn_id_odd_even_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 5:
proto_tree_add_item(tree, hf_a21_mn_id_odd_even_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_mn_id_identity_digit_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_a21_mn_id_esn, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 6:
proto_tree_add_item(tree, hf_a21_mn_id_odd_even_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
imsi_str = dissect_e212_imsi(tvb, pinfo, tree, offset, length, TRUE);
proto_item_append_text(item, "%s", imsi_str);
break;
}
}
static void
dissect_a21_1x_message_transmission_control(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
if (tree == NULL)
return;
proto_tree_add_item(tree, hf_a21_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_msg_tran_ctrl_paging_msg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_msg_tran_ctrl_simul_xmit_with_next, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_msg_tran_ctrl_ackrequired, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_msg_tran_ctrl_3GXLogicalChannel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_a21_msg_tran_ctrl_protocol_revision, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_a21_1x_lac_encapsulated_pdu(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_a21_1x_lac_en_pdu, tvb, offset, 3, ENC_BIG_ENDIAN);
}
static void
dissect_a21_1x_parameters(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
proto_tree_add_item(tree, hf_a21_3G1X_parameters, tvb, 0,length, ENC_NA);
}
static void
dissect_a21_pilot_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
int offset = 0;
guint8 num;
num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_a21_pilot_list_num_of_pilots, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (num>0) {
proto_tree_add_item(tree, hf_a21_pilot_list_value, tvb, offset, length-1, ENC_NA);
}
}
static void
dissect_a21_authentication_challenge_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
guint type;
if (tree == NULL)
return;
type = tvb_get_guint8(tvb, offset) & 0x0f;
proto_tree_add_item(tree, hf_a21_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_auth_chall_para_rand_num_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (type) {
case 1:
proto_tree_add_item(tree, hf_a21_auth_chall_para_rand_value, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
}
static void
dissect_a21_mobile_subscription_information(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
int offset = 0;
int i = 0;
guint8 record_id;
guint16 record_len = 0;
proto_tree *record_tree;
if (tree == NULL)
return;
while (offset<length) {
record_id = tvb_get_guint8(tvb, offset);
record_len = tvb_get_guint8(tvb, offset+1);
record_tree = proto_tree_add_subtree_format(tree, tvb, offset+2, record_len,
ett_a21_record_content, NULL, "Record %u",i+1);
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_record_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_record_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (record_id == 0) {
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_re_con_all_band_inc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_re_con_curr_band_sub, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_re_band_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_re_con_all_sub_band_inc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_re_sub_cls_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += record_len-2;
} else {
proto_tree_add_item(record_tree, hf_a21_mob_sub_info_record_content, tvb, offset, record_len, ENC_NA);
offset += record_len;
}
}
}
static void
dissect_a21_gcsna_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
guint8 priority_incl, status_incl;
if (tree == NULL)
return;
status_incl = tvb_get_guint8(tvb, offset) & 0x01;
priority_incl = tvb_get_guint8(tvb, offset) & 0x04;
proto_tree_add_item(tree, hf_a21_gcsna_status_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_gcsna_status_priority_incl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_gcsna_status_gec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_gcsna_status_status_incl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (status_incl == 1) {
proto_tree_add_item(tree, hf_a21_gcsna_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (priority_incl == 1) {
proto_tree_add_item(tree, hf_a21_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_a21_gcsna_status_call_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_a21_gcsna_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *top_tree, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_a21_gcsna_content, tvb, offset, length, ENC_NA);
if (gcsna_handle) {
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(gcsna_handle, new_tvb, pinfo, top_tree);
}
}
static void
dissect_a21_reference_cell_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
if (tree == NULL)
return;
proto_tree_add_item(tree, hf_a21_mscid_market_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_a21_mscid_switch_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_a21_reference_cell_id_cell, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_a21_reference_cell_id_sector, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_a21_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_a21_cause_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_a21_event(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
int offset = 0;
guint8 event_id;
if (tree == NULL)
return;
event_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_a21_event, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str_const(event_id, a21_event_vals, "Unknown"));
offset++;
if (length>1) {
if (event_id == 7) {
proto_tree_add_item(tree, hf_a21_allowed_foward_link_message, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(tree, hf_a21_additional_event_info, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_a21_service_option(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_a21_service_option, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_a21_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_a21_ie_data_not_dissected_yet, tvb, 0, length);
}
static void
dissect_a21_ie_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *top_tree, proto_tree *tree, gint offset, guint8 message_type)
{
guint8 ie_type, length_len;
guint16 length = 0;
tvbuff_t *ie_tvb;
proto_tree *ie_tree;
proto_item *ti;
while (offset < (gint)tvb_reported_length(tvb)) {
ie_type = tvb_get_guint8(tvb, offset);
if (ie_type == A21_IEI_GCSNA_PDU) {
length_len = 2;
length = tvb_get_ntohs(tvb, offset+1);
} else {
length_len = 1;
length = tvb_get_guint8(tvb, offset+1);
}
ie_tree = proto_tree_add_subtree_format(tree, tvb, offset, 1 + length_len + length, ett_a21_ie, &ti,
"%s : ", val_to_str_const(ie_type, a21_element_type_vals, "Unknown"));
proto_tree_add_item(ie_tree, hf_a21_element_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_a21_gcsna_pdu_length, tvb, offset, length_len, ENC_BIG_ENDIAN);
offset = offset+length_len;
ie_tvb = tvb_new_subset_remaining(tvb, offset);
switch (ie_type) {
case A21_IEI_1X_LAC_ENCAPSULATED_PDU:
dissect_a21_1x_lac_encapsulated_pdu(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_A21_1X_PARAMETERS:
dissect_a21_1x_parameters(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_PILOT_LIST:
dissect_a21_pilot_list(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_CORRELATION_ID:
dissect_a21_correlation_id(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_MOBILE_IDENTITY:
dissect_a21_mobile_identity(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_AUTHENTICATION_CHALLENGE_PARAMETER:
dissect_a21_authentication_challenge_parameter(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_A21_1X_MESSAGE_TRANSMISSION_CONTROL:
dissect_a21_1x_message_transmission_control(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_A21_CAUSE:
dissect_a21_cause(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_A21_EVENT:
dissect_a21_event(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_SERVICE_OPTION:
dissect_a21_service_option(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_A21_MOBILE_SUBSCRIPTION_INFORMATION:
dissect_a21_mobile_subscription_information(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_GCSNA_STATUS:
dissect_a21_gcsna_status(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
case A21_IEI_GCSNA_PDU:
dissect_a21_gcsna_pdu(ie_tvb,pinfo, top_tree, ie_tree, ti, length, message_type);
break;
case A21_IEI_REFERENCE_CELL_ID:
dissect_a21_reference_cell_id(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
default:
dissect_a21_unknown(ie_tvb,pinfo, ie_tree, ti, length, message_type);
break;
}
offset = offset + length;
}
}
static void
dissect_a21(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 message_type;
int offset = 0;
proto_item *ti, *tc;
proto_tree *a21_tree, *corr_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "A21");
col_clear(pinfo->cinfo, COL_INFO);
message_type = tvb_get_guint8(tvb, offset);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(message_type, a21_message_type_vals, "Unknown"));
ti = proto_tree_add_protocol_format(tree, proto_a21, tvb, 0, -1,
"A21 Protocol: %s",
val_to_str_const(message_type, a21_message_type_vals, "Unknown"));
a21_tree = proto_item_add_subtree(ti, ett_a21);
proto_tree_add_item(a21_tree, hf_a21_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tc = proto_tree_add_item(a21_tree, hf_a21_corr_id, tvb, offset, 6, ENC_BIG_ENDIAN);
corr_tree = proto_item_add_subtree(tc,ett_a21_corr_id);
proto_tree_add_item(corr_tree, hf_a21_element_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(corr_tree, hf_a21_element_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(corr_tree, hf_a21_corr_id_corr_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dissect_a21_ie_common(tvb, pinfo, tree, a21_tree, offset, message_type);
}
void proto_register_a21(void)
{
static hf_register_info hf_a21[] = {
{ &hf_a21_message_type,
{"Message Type", "a21.message_type",
FT_UINT8, BASE_DEC, VALS(a21_message_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_corr_id,
{"A21 Correlation ID", "a21.correlation_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_element_identifier,
{"A21 Element Identifier", "a21.element_identifier",
FT_UINT8, BASE_DEC, VALS(a21_element_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_element_length,
{"Length", "a21.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_corr_id_corr_value,
{"Correlation Value", "a21.corr_id_corr_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_mn_id_msid_value,
{"MSID Value", "a21.mn_id_msid_value",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_a21_mn_id_identity_digit_1,
{"Identity Digit 1", "a21.mn_id_identity_digit_1",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_a21_mn_id_odd_even_indicator,
{"Odd/Even Indicator", "a21.mn_id_odd_even_indicator",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_a21_mn_id_type_of_identity,
{"Type of Identity", "a21.mn_id_type_of_identity",
FT_UINT8, BASE_DEC, VALS(a21_mn_id_type_of_identity_vals), 0x07,
NULL, HFILL }
},
{ &hf_a21_mn_id_esn,
{"ESN", "a21.mn_id_esn",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_a21_reserved,
{"Reserved", "a21.reserved",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_a21_msg_tran_ctrl_paging_msg,
{"Paging Message", "a21.msg_tran_ctrl_paging_msg",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_a21_msg_tran_ctrl_simul_xmit_with_next,
{"Simul Xmit with Next", "a21.msg_tran_ctrl_simul_xmit_with_next",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_a21_msg_tran_ctrl_ackrequired,
{"AckRequired", "a21.msg_tran_ctrl_ackrequired",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_a21_msg_tran_ctrl_3GXLogicalChannel,
{"3GXLogicalChannel", "a21.msg_tran_ctrl_3GXLogicalChannel",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_a21_msg_tran_ctrl_protocol_revision,
{"ProtocolRevision", "a21.msg_tran_ctrl_protocol_revision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_1x_lac_en_pdu,
{"1x LAC Encapsulated PDU", "a21.1x_lac_en_pdu",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_pilot_list_num_of_pilots,
{"Number of Pilots", "a21.pilot_list_num_of_pilots",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_pilot_list_value,
{"Pilot List Value", "a21.pilot_list_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_cause_value,
{"A21 Cause Value", "a21.cause_value",
FT_UINT8, BASE_DEC, VALS(a21_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_mscid_market_id,
{"Market ID", "a21.mscid_market_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_mscid_switch_number,
{"Switch Number", "a21.mscid_switch_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_event,
{"Event", "a21.event",
FT_UINT8, BASE_DEC, VALS(a21_event_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_additional_event_info,
{"Additional Event Info", "a21.additional_event_info",
FT_UINT16, BASE_DEC, VALS(a21_additional_event_info_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_allowed_foward_link_message,
{"Allowed Forward Link Messages", "a21.allowed_foward_link_message",
FT_UINT16, BASE_DEC, VALS(a21_additional_event_info_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_gcsna_pdu_length,
{"Length", "a21.gcsna_pdu_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_gcsna_content,
{"GCSNA Content", "a21.gcsna_content",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_reference_cell_id_cell,
{"Cell", "a21.reference_cell_id_cell",
FT_UINT16, BASE_DEC, NULL, 0xfff0,
NULL, HFILL }
},
{ &hf_a21_reference_cell_id_sector,
{"Sector", "a21.reference_cell_id_sector",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_record_id,
{"Record Identifier", "a21.mob_sub_info_record_id",
FT_UINT8, BASE_DEC, VALS(a21_record_identifier_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_record_length,
{"Record Length", "a21.mob_sub_info_record_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_record_content,
{"Record Content", "a21.mob_sub_info_record_content",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_re_con_all_band_inc,
{"All Band Classes Included", "a21.mob_sub_info_re_con_all_band_inc",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_re_con_curr_band_sub,
{"Current Band Subclass", "a21.mob_sub_info_re_con_curr_band_sub",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_re_band_class,
{"Band Class", "a21.mob_sub_info_re_band_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_re_con_all_sub_band_inc,
{"All Band Subclasses Included", "a21.mob_sub_info_re_con_all_sub_band_inc",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_a21_mob_sub_info_re_sub_cls_len,
{"Subclass Length", "a21.mob_sub_info_re_sub_cls_len",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
#if 0
{ &hf_a21_mob_sub_info_re_con_band_class,
{"Band Class", "a21.mob_sub_info_re_con_band_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_a21_auth_chall_para_rand_num_type,
{"Random Number Type", "a21.auth_chall_para_rand_num_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(a21_random_number_type_rvals), 0x0f,
NULL, HFILL }
},
{ &hf_a21_auth_chall_para_rand_value,
{"RAND Value", "a21.auth_chall_para_rand_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_a21_service_option,
{"Service Option", "a21.service_option",
FT_UINT8, BASE_DEC, VALS(a21_service_option_vals), 0x7f,
NULL, HFILL }
},
{ &hf_a21_gcsna_status_reserved,
{"Reserved", "a21.gcsna_status_reserved",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_a21_gcsna_status_priority_incl,
{"Priority Incl", "a21.gcsna_status_priority_incl",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_a21_gcsna_status_gec,
{"GEC", "a21.gcsna_status_gec",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_a21_gcsna_status_status_incl,
{"Status Incl", "a21.gcsna_status_status_incl",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_a21_gcsna_status,
{"Status", "a21.gcsna_status",
FT_UINT8, BASE_DEC, VALS(a21_gcsna_status_vals), 0x0,
NULL, HFILL }
},
{ &hf_a21_gcsna_status_call_priority,
{"Call Priority", "a21.gcsna_status_call_priority",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_a21_3G1X_parameters,
{"3G1X Parameters", "a21.3G1X_parameters",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett_a21_array[] = {
&ett_a21,
&ett_a21_corr_id,
&ett_a21_ie,
&ett_a21_record_content
};
module_t *a21_module;
expert_module_t *expert_a21;
static ei_register_info ei[] = {
{ &ei_a21_ie_data_not_dissected_yet,
{ "a21.ie_data_not_dissected_yet",
PI_PROTOCOL, PI_NOTE, "IE data not dissected yet", EXPFILL }},
};
proto_a21 = proto_register_protocol("A21 Protocol", "A21", "a21");
proto_register_field_array(proto_a21, hf_a21, array_length(hf_a21));
proto_register_subtree_array(ett_a21_array, array_length(ett_a21_array));
expert_a21 = expert_register_protocol(proto_a21);
expert_register_field_array(expert_a21, ei, array_length(ei));
a21_module = prefs_register_protocol(proto_a21, proto_reg_handoff_a21);
prefs_register_uint_preference(a21_module, "udp.port",
"A21 UDP Port",
"UDP port used by A21, usually 23272",
10, &a21_udp_port);
}
void proto_reg_handoff_a21(void)
{
static dissector_handle_t a21_handle;
static gboolean a21_prefs_initialized = FALSE;
static guint saved_a21_udp_port;
if (!a21_prefs_initialized) {
a21_handle = create_dissector_handle(dissect_a21, proto_a21);
gcsna_handle = find_dissector("gcsna");
dissector_add_uint("udp.port", a21_udp_port, a21_handle);
a21_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", saved_a21_udp_port, a21_handle);
}
saved_a21_udp_port = a21_udp_port;
if (a21_udp_port != 0) {
dissector_add_uint("udp.port", a21_udp_port, a21_handle);
}
}
