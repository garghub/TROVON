static int
dissect_dpnss_sic(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint8 octet, type_of_data;
octet = tvb_get_guint8(tvb,offset);
type_of_data = (octet & 0x70)>>4;
proto_tree_add_item(tree, hf_dpnss_ext_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_sic_type, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (type_of_data) {
case 1:
proto_tree_add_item(tree, hf_dpnss_sic_details_for_speech, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_dpnss_sic_details_for_data1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(tree, hf_dpnss_sic_details_for_data2, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset++;
if ((octet&0x80)==0x80) {
octet = tvb_get_guint8(tvb,offset);
type_of_data = octet&0x3;
proto_tree_add_item(tree, hf_dpnss_ext_bit_notall, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (type_of_data) {
case 3:
case 4:
proto_tree_add_item(tree, hf_dpnss_sic_oct2_net_ind_clk, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_sic_oct2_sync_data_format, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_sic_oct2_sync_byte_timing, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 5:
case 6:
case 7:
proto_tree_add_item(tree, hf_dpnss_sic_oct2_async_flow_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_sic_oct2_async_data, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
proto_tree_add_item(tree, hf_dpnss_sic_oct2_duplex, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_sic_oct2_data_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
return offset;
}
static void
dissect_dpnns_sup_str_par(tvbuff_t *tvb, proto_tree * tree, int par_type_num, int par_start_offset, int par_end_offset)
{
int par_len;
gchar * par_data;
par_len = par_end_offset - par_start_offset;
if (par_len==0) {
par_type_num = DPNSS_NONE;
}
switch (par_type_num) {
case DPNSS_NONE:
proto_tree_add_string(tree, hf_dpnss_parameter, tvb, par_start_offset, par_len, "None");
break;
case DPNSS_A_B_PARTY_ADDR:
proto_tree_add_item(tree, hf_dpnss_a_b_party_addr, tvb, par_start_offset, par_len, ENC_ASCII|ENC_NA);
break;
case DPNSS_CALL_INDEX:
proto_tree_add_item(tree, hf_dpnss_call_idx, tvb, par_start_offset, par_len, ENC_ASCII|ENC_NA);
break;
default:
par_data = tvb_format_text(tvb,par_start_offset, par_len);
proto_tree_add_string_format(tree, hf_dpnss_parameter, tvb, par_start_offset, par_len, par_data, "Parameter %s: %s",
val_to_str(par_type_num, dpnss_sup_serv_par_str_vals, "Unknown (%d)" ), par_data);
break;
}
}
static int
dissect_dpnss_sup_info_str(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
proto_tree *sup_str_tree;
gint start_offset, hash_offset, tvb_end_offset, sup_inf_str_end_offset, str_no;
gint par_start_offset, par_end_offset, number_of_found_par;
gint sup_inf_str_len, par_type_num;
guint sup_str_num;
guint8 octet;
gboolean last_string = FALSE;
gboolean has_par;
tvb_end_offset = tvb_reported_length(tvb);
str_no = 1;
while ((offset<tvb_end_offset)&&(last_string == FALSE)) {
octet = tvb_get_guint8(tvb,offset);
if (octet == '*') {
start_offset = offset;
has_par = TRUE;
number_of_found_par = 0;
offset++;
hash_offset = tvb_find_guint8(tvb, offset, -1, '#');
sup_str_tree = proto_tree_add_subtree_format(tree, tvb, start_offset, hash_offset-start_offset+1,
ett_dpnss_sup_str, NULL, "Supplementary Information %u: %s",str_no,
tvb_format_text(tvb,start_offset,hash_offset-start_offset+1));
sup_inf_str_end_offset = tvb_find_guint8(tvb, offset, hash_offset-offset, '*');
if (sup_inf_str_end_offset==-1) {
has_par = FALSE;
sup_inf_str_end_offset = hash_offset;
}
sup_inf_str_len = sup_inf_str_end_offset - offset;
sup_str_num = atoi(tvb_format_text(tvb, offset, sup_inf_str_len));
if ((sup_str_num != 0) && (sup_str_num < array_length(dpnns_sup_serv_set))) {
proto_tree_add_string(sup_str_tree, hf_dpnss_sup_str, tvb, offset, sup_inf_str_len,
dpnns_sup_serv_set[sup_str_num].compact_name);
offset = sup_inf_str_end_offset+1;
while (has_par) {
number_of_found_par++;
par_start_offset = offset;
par_end_offset = tvb_find_guint8(tvb, offset, -1, '*');
if (par_end_offset == -1) {
par_end_offset = hash_offset;
has_par = FALSE;
}
switch (number_of_found_par) {
case 1:
par_type_num = dpnns_sup_serv_set[sup_str_num].par1_num;
dissect_dpnns_sup_str_par(tvb,sup_str_tree, par_type_num, par_start_offset, par_end_offset);
break;
case 2:
par_type_num = dpnns_sup_serv_set[sup_str_num].par2_num;
dissect_dpnns_sup_str_par(tvb,sup_str_tree, par_type_num, par_start_offset, par_end_offset);
break;
case 3:
par_type_num = dpnns_sup_serv_set[sup_str_num].par3_num;
dissect_dpnns_sup_str_par(tvb,sup_str_tree, par_type_num, par_start_offset, par_end_offset);
break;
case 4:
par_type_num = dpnns_sup_serv_set[sup_str_num].par4_num;
dissect_dpnns_sup_str_par(tvb,sup_str_tree, par_type_num, par_start_offset, par_end_offset);
break;
default:
break;
}
offset = par_end_offset+1;
}
}
offset = hash_offset+1;
str_no++;
} else {
last_string = TRUE;
proto_tree_add_item(tree, hf_dpnss_dest_addr, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
}
return offset;
}
static int
dissect_dpnss_LbL_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ind_field_item;
proto_tree *sic_field_tree, *ind_field_tree;
int offset = 0;
int tvb_end_offset;
guint8 octet;
tvb_end_offset = tvb_reported_length(tvb);
proto_tree_add_item(tree, hf_dpnss_LbL_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset)&0x0f;
offset++;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(octet, dpnss_LbL_msg_short_type_vals, "Unknown (%d)" ));
if (tree) {
switch (octet) {
case DPNSS_LbL_MSG_LLM_C:
case DPNSS_LbL_MSG_LLM_I:
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
case DPNSS_LbL_MSG_LLRM:
proto_tree_add_item(tree, hf_dpnss_rejection_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tvb_end_offset>offset) {
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
}
break;
case DPNSS_LbL_MSG_SM:
sic_field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dpnss_sic_field, NULL, "Service Indicator Code");
offset =dissect_dpnss_sic(tvb, pinfo, sic_field_tree, offset);
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
case DPNSS_LbL_MSG_LMM:
proto_tree_add_item(tree, hf_dpnss_maintenance_action, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
case DPNSS_LbL_MSG_LMRM:
proto_tree_add_item(tree, hf_dpnss_clearing_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_dpnss_not_supported_yet, tvb, offset, -1);
break;
}
}
return offset;
}
static int
dissect_dpnss_e2e_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sel_field_item, *ind_field_item;
proto_tree *sel_field_tree, *sic_field_tree, *ind_field_tree;
int offset = 0;
int tvb_end_offset;
guint8 octet;
tvb_end_offset = tvb_reported_length(tvb);
proto_tree_add_item(tree, hf_dpnss_e2e_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset)&0x0f;
offset++;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(octet, dpnss_e2e_msg_short_type_vals, "Unknown (%d)" ));
if (tree) {
switch (octet) {
case DPNSS_E2E_MSG_EEM_C:
case DPNSS_E2E_MSG_EEM_I:
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
case DPNSS_E2E_MSG_SCRM:
case DPNSS_E2E_MSG_SCIM:
proto_tree_add_item(tree, hf_dpnss_clearing_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tvb_end_offset>offset) {
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
}
break;
case DPNSS_E2E_MSG_ERM_C:
case DPNSS_E2E_MSG_ERM_I:
sic_field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dpnss_sic_field, NULL, "Service Indicator Code");
offset =dissect_dpnss_sic(tvb, pinfo, sic_field_tree, offset);
sel_field_item = proto_tree_add_item(tree, hf_dpnss_selection_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
sel_field_tree = proto_item_add_subtree(sel_field_item, ett_dpnss_sel_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, sel_field_tree, offset);
break;
case DPNSS_E2E_MSG_NSIM:
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_dpnss_ext_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_man_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dpnss_subcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if ((octet&0x80)==0x80) {
offset++;
}
proto_tree_add_item(tree, hf_dpnss_user_information, tvb, offset, -1, ENC_NA);
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_dpnss_not_supported_yet, tvb, offset, -1);
break;
}
}
return offset;
}
static int
dissect_dpnss_cc_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sel_field_item, *ind_field_item;
proto_tree *sel_field_tree, *sic_field_tree, *ind_field_tree;
int offset = 0;
int tvb_end_offset;
guint8 octet;
tvb_end_offset = tvb_reported_length(tvb);
proto_tree_add_item(tree, hf_dpnss_cc_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset)&0x0f;
offset++;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(octet, dpnss_cc_msg_short_type_vals, "Unknown (%d)" ));
if (tree) {
switch (octet) {
case DPNSS_CC_MSG_ISRM_C:
case DPNSS_CC_MSG_ISRM_I:
case DPNSS_CC_MSG_RM_C:
case DPNSS_CC_MSG_RM_I:
sic_field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_dpnss_sic_field, NULL, "Service Indicator Code");
offset =dissect_dpnss_sic(tvb, pinfo, sic_field_tree, offset);
sel_field_item = proto_tree_add_item(tree, hf_dpnss_selection_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
sel_field_tree = proto_item_add_subtree(sel_field_item, ett_dpnss_sel_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, sel_field_tree, offset);
break;
case DPNSS_CC_MSG_CCM:
if (tvb_end_offset>offset) {
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
}
break;
case DPNSS_CC_MSG_NIM:
case DPNSS_CC_MSG_NAM:
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
break;
case DPNSS_CC_MSG_CRM:
proto_tree_add_item(tree, hf_dpnss_clearing_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tvb_end_offset>offset) {
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
}
break;
case DPNSS_CC_MSG_RRM:
proto_tree_add_item(tree, hf_dpnss_rejection_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tvb_end_offset>offset) {
ind_field_item = proto_tree_add_item(tree, hf_dpnss_indication_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
ind_field_tree = proto_item_add_subtree(ind_field_item, ett_dpnss_ind_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, ind_field_tree, offset);
}
break;
case DPNSS_CC_MSG_SSRM_I:
sel_field_item = proto_tree_add_item(tree, hf_dpnss_selection_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
sel_field_tree = proto_item_add_subtree(sel_field_item, ett_dpnss_sel_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, sel_field_tree, offset);
break;
case DPNSS_CC_MSG_SSRM_C:
if (tvb_end_offset>offset) {
sel_field_item = proto_tree_add_item(tree, hf_dpnss_selection_field, tvb, offset, -1, ENC_NA|ENC_ASCII);
sel_field_tree = proto_item_add_subtree(sel_field_item, ett_dpnss_sel_field);
offset = dissect_dpnss_sup_info_str(tvb, pinfo, sel_field_tree, offset);
}
break;
case DPNSS_CC_MSG_CS:
case DPNSS_CC_MSG_CA:
default:
proto_tree_add_expert_format(tree, pinfo, &ei_dpnss_not_supported_yet, tvb, offset, -1, "Unknown or Dissection of this message not supported yet");
break;
}
}
return offset;
}
static int
dissect_dpnss(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item *item, *group_item;
proto_tree *dpnss_tree;
guint8 octet;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DPNSS");
item = proto_tree_add_item(tree, proto_dpnss, tvb, 0, -1, ENC_NA);
dpnss_tree = proto_item_add_subtree(item, ett_dpnss);
group_item = proto_tree_add_item(dpnss_tree, hf_dpnss_msg_grp_id, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,offset)>>4;
switch (octet) {
case DPNNS_MESSAGE_GROUP_CC:
dissect_dpnss_cc_msg(tvb, pinfo, dpnss_tree);
break;
case DPNNS_MESSAGE_GROUP_E2E:
dissect_dpnss_e2e_msg(tvb, pinfo, dpnss_tree);
break;
case DPNNS_MESSAGE_GROUP_LbL:
dissect_dpnss_LbL_msg(tvb, pinfo, dpnss_tree);
break;
default:
expert_add_info(pinfo, group_item, &ei_dpnss_msg_grp_id);
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_dpnss(void)
{
static hf_register_info hf[] = {
{ &hf_dpnss_msg_grp_id,
{ "Message Group Identifier", "dpnss.msg_grp_id",
FT_UINT8, BASE_DEC, VALS(dpnss_msg_grp_id_vals), 0xf0,
NULL, HFILL }
},
{ &hf_dpnss_cc_msg_type,
{ "Call Control Message Type", "dpnss.cc_msg_type",
FT_UINT8, BASE_DEC, VALS(dpnss_cc_msg_type_vals), 0x0f,
NULL, HFILL }
},
{ &hf_dpnss_e2e_msg_type,
{ "END-TO-END Message Type", "dpnss.e2e_msg_type",
FT_UINT8, BASE_DEC, VALS(dpnss_e2e_msg_type_vals), 0x0f,
NULL, HFILL }
},
{ &hf_dpnss_LbL_msg_type,
{ "LINK-BY-LINK Message Type", "dpnss.lbl_msg_type",
FT_UINT8, BASE_DEC, VALS(dpnss_LbL_msg_type_vals), 0x0f,
NULL, HFILL }
},
{ &hf_dpnss_ext_bit,
{ "Extension bit", "dpnss.ext_bit",
FT_BOOLEAN, 8, TFS(&dpnss_ext_bit_vals), 0x80,
NULL, HFILL }
},
{ &hf_dpnss_ext_bit_notall,
{ "Extension bit", "dpnss.ext_bit_notall",
FT_BOOLEAN, 8, TFS(&dpnss_ext_bit_no_ext_vals), 0x80,
NULL, HFILL }
},
{ &hf_dpnss_sic_type,
{ "Type of data", "dpnss.sic_type",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_type_type_vals), 0x70,
NULL, HFILL }
},
{ &hf_dpnss_sic_details_for_speech,
{ "Details for Speech", "dpnss.sic_details_for_speech",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_details_for_speech_vals), 0x0f,
NULL, HFILL }
},
{ &hf_dpnss_sic_details_for_data1,
{ "Data Rates", "dpnss.sic_details_for_data1",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_details_for_data_rates1_vals), 0x0f,
"Type of Data (010) : Data Rates", HFILL }
},
{ &hf_dpnss_sic_details_for_data2,
{ "Data Rates", "dpnss.sic_details_data2",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_details_for_data_rates2_vals), 0x0f,
"Type of Data (011) : Data Rates", HFILL }
},
{ &hf_dpnss_dest_addr,
{ "Destination Address", "dpnss.dest_addr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_data_type,
{ "Data Type", "dpnss.sic_oct2_data_type",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_oct2_data_type_vals), 0x03,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_duplex,
{ "Data Type", "dpnss.sic_oct2_duplex",
FT_BOOLEAN, 8, TFS(&dpnss_duplex_vals), 0x08,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_net_ind_clk,
{ "Network Independent Clock", "dpnss.sic_oct2_net_ind_clk",
FT_BOOLEAN, 8, TFS(&dpnss_sic_oct2_net_ind_clk_vals), 0x40,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_sync_data_format,
{ "Data Format", "dpnss.sic_oct2_sync_data_format",
FT_BOOLEAN, 8, TFS(&dpnss_sic_oct2_sync_data_format_vals), 0x20,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_sync_byte_timing,
{ "Byte Timing", "dpnss.sic_oct2_sync_byte_timing",
FT_BOOLEAN, 8, TFS(&dpnss_provided_vals), 0x10,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_async_data,
{ "Data Format", "dpnss.sic_oct2_async_data",
FT_UINT8, BASE_DEC, VALS(dpnss_sic_oct2_async_data_type_vals), 0x30,
NULL, HFILL }
},
{ &hf_dpnss_sic_oct2_async_flow_ctrl,
{ "Flow Control", "dpnss.sic_oct2_async_flow_ctrl",
FT_BOOLEAN, 8, TFS(&dpnss_flow_control_vals), 0x40,
NULL, HFILL }
},
{ &hf_dpnss_clearing_cause,
{ "Clearing Cause", "dpnss.clearing_cause",
FT_UINT8, BASE_DEC, VALS(dpnss_clearing_cause_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_dpnss_rejection_cause,
{ "Rejection Cause", "dpnss.rejection_cause",
FT_UINT8, BASE_DEC, VALS(dpnss_clearing_cause_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_dpnss_man_code,
{ "Manufacturer Code", "dpnss.man_code",
FT_UINT8, BASE_DEC, VALS(dpnss_man_code_vals), 0x3c,
NULL, HFILL }
},
{ &hf_dpnss_subcode,
{ "Subcode", "dpnss.subcode",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }
},
{ &hf_dpnss_maintenance_action,
{ "Maintenance action", "dpnss.maint_act",
FT_UINT8, BASE_DEC, VALS(dpnss_maintenance_actions_vals), 0x0,
NULL, HFILL }
},
{ &hf_dpnss_a_b_party_addr,
{ "A/B party Address", "dpnss.a_b_party_addr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dpnss_call_idx,
{ "Call Index", "dpnss.call_idx",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dpnss_indication_field, { "Indication Field", "dpnss.indication_field", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dpnss_selection_field, { "Selection Field", "dpnss.selection_field", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dpnss_user_information, { "User Information", "dpnss.user_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dpnss_sup_str, { "Sup str", "dpnss.sup_str", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dpnss_parameter, { "Parameter", "dpnss.parameter", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dpnss,
&ett_dpnss_sel_field,
&ett_dpnss_sic_field,
&ett_dpnss_ind_field,
&ett_dpnss_sup_str,
};
static ei_register_info ei[] = {
{ &ei_dpnss_not_supported_yet, { "dpnss.not_supported_yet", PI_UNDECODED, PI_WARN, "Dissection of this message not supported yet", EXPFILL }},
{ &ei_dpnss_msg_grp_id, { "dpnss.msg_grp_id.unknown", PI_PROTOCOL, PI_WARN, "Unknown Message Group", EXPFILL }},
};
expert_module_t* expert_dpnss;
proto_dpnss = proto_register_protocol("Digital Private Signalling System No 1","DPNSS", "dpnss");
register_dissector("dpnss", dissect_dpnss, proto_dpnss);
proto_register_field_array(proto_dpnss, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dpnss = expert_register_protocol(proto_dpnss);
expert_register_field_array(expert_dpnss, ei, array_length(ei));
}
