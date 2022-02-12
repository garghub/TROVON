static guint16
de_rp_message_ref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rp_rp_message_reference, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_rp_orig_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
return(de_cld_party_bcd_num(tvb, tree, pinfo, offset, len, add_string, string_len));
}
static guint16
de_rp_dest_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
return(de_cld_party_bcd_num(tvb, tree, pinfo, offset, len, add_string, string_len));
}
static guint16
de_rp_user_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *tpdu_tvb;
curr_offset = offset;
proto_tree_add_bytes_format(tree, hf_gsm_a_rp_tpdu, tvb, curr_offset, len, NULL, "TPDU (not displayed)");
tpdu_tvb = tvb_new_subset_length(tvb, curr_offset, len);
call_dissector_only(gsm_sms_handle, tpdu_tvb, pinfo, g_tree, NULL);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_rp_extraneous_data);
return(curr_offset - offset);
}
static guint16
de_rp_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_rp_extension, tvb, curr_offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_gsm_a_rp_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) %s", oct & 0x7f, val_to_str_ext_const(oct & 0x7f, &gsm_rp_cause_vals_ext, "Reserved"));
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_rp_diagnostic_field, tvb, curr_offset, len - (curr_offset - offset), ENC_NA);
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_rp_extraneous_data);
return(curr_offset - offset);
}
void
rp_data_n_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_ORIG_ADDR, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_DEST_ADDR, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_data_ms_n(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_ORIG_ADDR, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_DEST_ADDR, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_smma(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_ack_n_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_OPT_TLV(0x41, GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_ack_ms_n(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_OPT_TLV(0x41, GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_error_n_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_CAUSE, NULL);
ELEM_OPT_TLV(0x41, GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static void
rp_error_ms_n(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V(GSM_A_PDU_TYPE_RP, DE_RP_MESSAGE_REF, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RP, DE_RP_CAUSE, NULL);
ELEM_OPT_TLV(0x41, GSM_A_PDU_TYPE_RP, DE_RP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_rp_extraneous_data);
}
static int
dissect_rp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 oct;
guint32 offset, saved_offset;
guint32 len;
gint idx;
proto_item *rp_item = NULL;
proto_tree *rp_tree = NULL;
const gchar *str;
col_append_str(pinfo->cinfo, COL_INFO, "(RP) ");
offset = 0;
saved_offset = offset;
g_tree = tree;
len = tvb_reported_length(tvb);
oct = tvb_get_guint8(tvb, offset++);
str = try_val_to_str_idx((guint32) oct, gsm_rp_msg_strings, &idx);
if (str == NULL)
{
rp_item =
proto_tree_add_protocol_format(tree, proto_a_rp, tvb, 0, len,
"GSM A-I/F RP - Unknown RP Message Type (0x%02x)",
oct);
rp_tree = proto_item_add_subtree(rp_item, ett_rp_msg);
}
else
{
rp_item =
proto_tree_add_protocol_format(tree, proto_a_rp, tvb, 0, -1,
"GSM A-I/F RP - %s",
str);
rp_tree = proto_item_add_subtree(rp_item, ett_gsm_rp_msg[idx]);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", str);
}
proto_tree_add_uint_format(rp_tree, hf_gsm_a_rp_msg_type,
tvb, saved_offset, 1, oct, "Message Type %s", str ? str : "(Unknown)");
if (str == NULL) return offset;
if (offset >=len) return offset;
if (rp_msg_fcn[idx] == NULL)
{
proto_tree_add_item(rp_tree, hf_gsm_a_rp_message_elements, tvb, offset, len - offset, ENC_NA);
}
else
{
(*rp_msg_fcn[idx])(tvb, rp_tree, pinfo, offset, len - offset);
}
return tvb_captured_length(tvb);
}
void
proto_register_gsm_a_rp(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_gsm_a_rp_msg_type,
{ "RP Message Type", "gsm_a.rp.msg_type",
FT_UINT8, BASE_HEX, VALS(gsm_rp_msg_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rp_elem_id,
{ "Element ID", "gsm_a.rp.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_rp_rp_message_reference, { "RP-Message Reference", "gsm_a.rp.rp_message_reference", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_rp_tpdu, { "TPDU", "gsm_a.rp.tpdu", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_rp_extension, { "Extension", "gsm_a.rp.extension", FT_BOOLEAN, 8, TFS(&tfs_extended_no_extension), 0x80, NULL, HFILL }},
{ &hf_gsm_a_rp_cause, { "Cause", "gsm_a.rp.cause", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gsm_rp_cause_vals_ext, 0x7F, NULL, HFILL }},
{ &hf_gsm_a_rp_diagnostic_field, { "Diagnostic field", "gsm_a.rp.diagnostic_field", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_rp_message_elements, { "Message Elements", "gsm_a.rp.message_elements", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_gsm_a_rp_extraneous_data, { "gsm_a.rp.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
};
expert_module_t* expert_gsm_a_rp;
#define NUM_INDIVIDUAL_ELEMS 1
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GSM_RP_MSG +
NUM_GSM_RP_ELEM];
ett[0] = &ett_rp_msg;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_RP_MSG; i++, last_offset++)
{
ett_gsm_rp_msg[i] = -1;
ett[last_offset] = &ett_gsm_rp_msg[i];
}
for (i=0; i < NUM_GSM_RP_ELEM; i++, last_offset++)
{
ett_gsm_rp_elem[i] = -1;
ett[last_offset] = &ett_gsm_rp_elem[i];
}
proto_a_rp = proto_register_protocol("GSM A-I/F RP", "GSM RP", "gsm_a.rp");
proto_register_field_array(proto_a_rp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_a_rp = expert_register_protocol(proto_a_rp);
expert_register_field_array(expert_gsm_a_rp, ei, array_length(ei));
register_dissector("gsm_a_rp", dissect_rp, proto_a_rp);
}
void
proto_reg_handoff_gsm_a_rp(void)
{
dissector_handle_t gsm_a_rp_handle;
gsm_a_rp_handle = create_dissector_handle(dissect_rp, proto_a_rp);
dissector_add_string("media_type","application/vnd.3gpp.sms", gsm_a_rp_handle);
gsm_sms_handle = find_dissector_add_dependency("gsm_sms", proto_a_rp);
}
