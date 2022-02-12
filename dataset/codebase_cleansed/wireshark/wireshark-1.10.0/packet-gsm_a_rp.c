static guint16
de_rp_message_ref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"RP-Message Reference: 0x%02x (%u)",
oct,
oct);
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
proto_tree_add_text(tree, tvb, curr_offset, len,
"TPDU (not displayed)");
tpdu_tvb = tvb_new_subset(tvb, curr_offset, len, len);
dissector_try_uint(sms_dissector_table, 0, tpdu_tvb, pinfo, g_tree);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_rp_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s : Extension: %s",
a_bigbuf,
(oct & 0x80) ? "extended" : "not extended");
switch (oct & 0x7f)
{
case 1: str = "Unassigned (unallocated) number"; break;
case 8: str = "Operator determined barring"; break;
case 10: str = "Call barred"; break;
case 11: str = "Reserved"; break;
case 21: str = "Short message transfer rejected"; break;
case 22: str = "Memory capacity exceeded"; break;
case 27: str = "Destination out of order"; break;
case 28: str = "Unidentified subscriber"; break;
case 29: str = "Facility rejected"; break;
case 30: str = "Unknown subscriber"; break;
case 38: str = "Network out of order"; break;
case 41: str = "Temporary failure"; break;
case 42: str = "Congestion"; break;
case 47: str = "Resources unavailable, unspecified"; break;
case 50: str = "Requested facility not subscribed"; break;
case 69: str = "Requested facility not implemented"; break;
case 81: str = "Invalid short message transfer reference value"; break;
case 95: str = "Semantically incorrect message"; break;
case 96: str = "Invalid mandatory information"; break;
case 97: str = "Message type non-existent or not implemented"; break;
case 98: str = "Message not compatible with short message protocol state"; break;
case 99: str = "Information element non-existent or not implemented"; break;
case 111: str = "Protocol error, unspecified"; break;
case 127: str = "Interworking, unspecified"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s : Cause: (%u) %s",
a_bigbuf,
oct & 0x7f,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) %s", oct & 0x7f, str);
NO_MORE_DATA_CHECK(len);
proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Diagnostic field");
curr_offset += len - (curr_offset - offset);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
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
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dissect_rp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
len = tvb_length(tvb);
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
if (str == NULL) return;
if (offset >=len) return;
if (rp_msg_fcn[idx] == NULL)
{
proto_tree_add_text(rp_tree,
tvb, offset, len - offset,
"Message Elements");
}
else
{
(*rp_msg_fcn[idx])(tvb, rp_tree, pinfo, offset, len - offset);
}
}
void
proto_register_gsm_a_rp(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] =
{
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
};
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
proto_a_rp =
proto_register_protocol("GSM A-I/F RP", "GSM RP", "gsm_a.rp");
proto_register_field_array(proto_a_rp, hf, array_length(hf));
sms_dissector_table =
register_dissector_table("gsm_a.sms_tpdu", "GSM SMS TPDU",
FT_UINT8, BASE_DEC);
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_a_rp", dissect_rp, proto_a_rp);
}
void
proto_reg_handoff_gsm_a_rp(void)
{
dissector_handle_t gsm_a_rp_handle;
gsm_a_rp_handle = create_dissector_handle(dissect_rp, proto_a_rp);
dissector_add_string("media_type","application/vnd.3gpp.sms", gsm_a_rp_handle);
}
