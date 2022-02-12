static void
dissect_lmi_report_type(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_uint(tree, hf_lmi_rcd_type, tvb, offset, 1, tvb_get_guint8( tvb, offset));
}
static void
dissect_lmi_link_int(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_uint(tree, hf_lmi_send_seq, tvb, offset, 1, tvb_get_guint8( tvb, offset));
++offset;
proto_tree_add_uint(tree, hf_lmi_recv_seq, tvb, offset, 1, tvb_get_guint8( tvb, offset));
}
static void
dissect_lmi_pvc_status(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_uint(tree, hf_lmi_dlci_high, tvb, offset, 1, tvb_get_guint8( tvb, offset));
++offset;
proto_tree_add_uint(tree, hf_lmi_dlci_low, tvb, offset, 1, tvb_get_guint8( tvb, offset));
++offset;
proto_tree_add_uint(tree, hf_lmi_new, tvb, offset, 1, tvb_get_guint8( tvb, offset));
proto_tree_add_uint(tree, hf_lmi_act, tvb, offset, 1, tvb_get_guint8( tvb, offset));
}
static void
dissect_lmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *lmi_tree, *lmi_subtree;
proto_item *ti;
int offset = 2, len;
guint8 msg_type;
guint8 ele_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LMI");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lmi, tvb, 0, 3, ENC_NA);
lmi_tree = proto_item_add_subtree(ti, ett_lmi_ele);
proto_tree_add_item(lmi_tree, hf_lmi_call_ref, tvb, 0, 1, ENC_BIG_ENDIAN);
msg_type = tvb_get_guint8( tvb, 1);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msg_type, msg_type_str, "Unknown message type (0x%02x)"));
proto_tree_add_uint(lmi_tree, hf_lmi_msg_type, tvb, 1, 1, msg_type);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ele_id = tvb_get_guint8( tvb, offset);
len = tvb_get_guint8( tvb, offset + 1);
lmi_subtree = proto_tree_add_subtree_format(lmi_tree, tvb, offset, len + 2,
ett_lmi_ele, NULL, "Information Element: %s",
val_to_str(ele_id, element_type_str, "Unknown (%u)"));
proto_tree_add_uint(lmi_subtree, hf_lmi_inf_ele, tvb, offset, 1,
ele_id);
++offset;
proto_tree_add_uint(lmi_subtree, hf_lmi_inf_len, tvb, offset, 1, len);
++offset;
if (( ele_id == 1) || (ele_id == 51))
dissect_lmi_report_type( tvb, offset, lmi_subtree);
else if (( ele_id == 3) || (ele_id == 53))
dissect_lmi_link_int( tvb, offset, lmi_subtree);
else if (( ele_id == 7) || (ele_id == 57))
dissect_lmi_pvc_status( tvb, offset, lmi_subtree);
offset += len;
}
}
void
proto_register_lmi(void)
{
static hf_register_info hf[] = {
{ &hf_lmi_call_ref,
{ "Call reference", "lmi.cmd", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_lmi_msg_type,
{ "Message Type", "lmi.msg_type", FT_UINT8, BASE_HEX, VALS(msg_type_str), 0,
NULL, HFILL }},
{ &hf_lmi_inf_ele,
{ "Type", "lmi.inf_ele_type", FT_UINT8, BASE_DEC, VALS(element_type_str), 0,
"Information Element Type", HFILL }},
{ &hf_lmi_inf_len,
{ "Length", "lmi.inf_ele_len", FT_UINT8, BASE_DEC, NULL, 0,
"Information Element Length", HFILL }},
{ &hf_lmi_rcd_type,
{ "Record Type", "lmi.ele_rcd_type", FT_UINT8, BASE_DEC, VALS(record_type_str), 0,
NULL, HFILL }},
{ &hf_lmi_send_seq,
{ "Send Seq", "lmi.send_seq", FT_UINT8, BASE_DEC, NULL, 0,
"Send Sequence", HFILL }},
{ &hf_lmi_recv_seq,
{ "Recv Seq", "lmi.recv_seq", FT_UINT8, BASE_DEC, NULL, 0,
"Receive Sequence", HFILL }},
{ &hf_lmi_dlci_high,
{ "DLCI High", "lmi.dlci_hi", FT_UINT8, BASE_DEC, NULL, 0x3f,
"DLCI High bits", HFILL }},
{ &hf_lmi_dlci_low,
{ "DLCI Low", "lmi.dlci_low", FT_UINT8, BASE_DEC, NULL, 0x78,
"DLCI Low bits", HFILL }},
{ &hf_lmi_new,
{ "DLCI New", "lmi.dlci_new", FT_UINT8, BASE_DEC, VALS(pvc_status_new_str), 0x08,
"DLCI New Flag", HFILL }},
{ &hf_lmi_act,
{ "DLCI Active","lmi.dlci_act", FT_UINT8, BASE_DEC, VALS(pvc_status_act_str), 0x02,
"DLCI Active Flag", HFILL }},
};
static gint *ett[] = {
&ett_lmi,
&ett_lmi_ele,
};
proto_lmi = proto_register_protocol ("Local Management Interface", "LMI", "lmi");
proto_register_field_array (proto_lmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lmi(void)
{
dissector_handle_t lmi_handle;
lmi_handle = create_dissector_handle(dissect_lmi, proto_lmi);
dissector_add_uint("fr.nlpid", NLPID_LMI, lmi_handle);
}
