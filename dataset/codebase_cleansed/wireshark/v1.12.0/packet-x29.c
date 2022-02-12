static int
dissect_x29(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
int offset = 0;
proto_tree *x29_tree;
proto_item *ti;
gboolean *q_bit_set;
guint8 msg_code;
guint8 error_type;
guint8 type_ref;
gint next_offset;
int linelen;
if (data == NULL)
return 0;
q_bit_set = (gboolean *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X.29");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_x29, tvb, offset, -1, ENC_NA);
x29_tree = proto_item_add_subtree(ti, ett_x29);
if (*q_bit_set) {
msg_code = tvb_get_guint8(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s PAD message",
val_to_str(msg_code, message_code_vals,
"Unknown (0x%02x)"));
proto_tree_add_uint(x29_tree, hf_msg_code, tvb,
offset, 1, msg_code);
offset++;
switch (msg_code) {
case SET_MSG:
case READ_MSG:
case SET_AND_READ_MSG:
case PARAMETER_IND_MSG:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_text(x29_tree, tvb, offset, 2,
"Parameter %u, value %u",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1));
offset += 2;
}
break;
case INV_TO_CLEAR_MSG:
break;
case ERROR_MSG:
error_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(x29_tree, hf_error_type, tvb,
offset, 1, error_type);
offset++;
if (error_type != 0) {
proto_tree_add_item(x29_tree, hf_inv_msg_code,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case BREAK_IND_MSG:
if (tvb_reported_length_remaining(tvb, offset) > 0) {
type_ref = tvb_get_guint8(tvb, offset);
switch (type_ref) {
case 0x01:
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Type reference: Change in PAD Aspect");
offset++;
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Type of aspect: 0x%02x",
type_ref);
offset++;
break;
case 0x08:
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Type reference: Break");
offset++;
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Break value: 0x%02x",
type_ref);
offset++;
break;
default:
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Unknown type reference (0x%02x)",
type_ref);
offset++;
proto_tree_add_text(x29_tree, tvb,
offset, 1, "Type value: 0x%02x",
type_ref);
offset++;
break;
}
}
break;
case RESELECTION_MSG:
proto_tree_add_text(x29_tree, tvb, offset, -1,
"Reselection message data");
break;
case RESEL_WITH_TOA_NPI_MSG:
proto_tree_add_text(x29_tree, tvb, offset, -1,
"Reselection message data");
break;
default:
proto_tree_add_text(x29_tree, tvb, offset, -1,
"PAD message data");
break;
}
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Data ...");
if (tree) {
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1,
&next_offset, FALSE);
linelen = next_offset - offset;
proto_tree_add_text(x29_tree, tvb, offset,
linelen, "Data: %s",
tvb_format_text(tvb, offset, linelen));
offset = next_offset;
}
}
}
return tvb_length(tvb);
}
void
proto_register_x29(void)
{
static hf_register_info hf[] = {
{ &hf_msg_code,
{ "Message code", "x29.msg_code", FT_UINT8, BASE_HEX,
VALS(message_code_vals), 0x0, "X.29 PAD message code",
HFILL }},
{ &hf_error_type,
{ "Error type", "x29.error_type", FT_UINT8, BASE_HEX,
VALS(error_type_vals), 0x0, "X.29 error PAD message error type",
HFILL }},
{ &hf_inv_msg_code,
{ "Invalid message code", "x29.inv_msg_code", FT_UINT8, BASE_HEX,
VALS(message_code_vals), 0x0, "X.29 Error PAD message invalid message code",
HFILL }},
};
static gint *ett[] = {
&ett_x29,
};
proto_x29 = proto_register_protocol("X.29", "X.29", "x29");
proto_register_field_array(proto_x29, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_x29(void)
{
dissector_handle_t x29_handle;
x29_handle = new_create_dissector_handle(dissect_x29, proto_x29);
dissector_add_uint("x.25.spi", NLPID_SPI_X_29, x29_handle);
}
