static gboolean dissect_h1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *h1_tree, *block_tree;
proto_item *h1_ti, *block_ti;
gint offset = 0, offset_block_start;
guint8 h1_len;
guint8 block_type, block_len;
tvbuff_t *next_tvb;
if (tvb_captured_length(tvb) < 2) {
return FALSE;
}
if (!(tvb_get_guint8(tvb, 0) == 'S' && tvb_get_guint8(tvb, 1) == '5')) {
return FALSE;
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "H1");
col_set_str(pinfo->cinfo, COL_INFO, "S5: ");
h1_ti = proto_tree_add_item(tree, proto_h1, tvb, offset, -1, ENC_NA);
h1_tree = proto_item_add_subtree(h1_ti, ett_h1);
proto_tree_add_item(h1_tree, hf_h1_header, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
h1_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(h1_tree, hf_h1_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_len(h1_ti, h1_len);
offset++;
while (offset < h1_len) {
offset_block_start = offset;
block_type = tvb_get_guint8(tvb, offset);
block_len = tvb_get_guint8(tvb, offset+1);
if (!try_val_to_str(block_type, block_type_vals)) {
return FALSE;
}
if (block_len == 0) {
break;
}
block_tree = proto_tree_add_subtree_format(h1_tree,
tvb, offset, -1, ett_block, &block_ti, "%s",
val_to_str_const(block_type, block_type_vals, "Unknown block"));
proto_tree_add_item(block_tree, hf_h1_block_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(block_tree, hf_h1_block_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_len(block_ti, block_len);
offset++;
switch (block_type) {
case OPCODE_BLOCK:
proto_tree_add_item(block_tree, hf_h1_opcode,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_str (pinfo->cinfo, COL_INFO,
val_to_str (tvb_get_guint8(tvb, offset),
opcode_vals, "Unknown Opcode (0x%2.2x)"));
break;
case REQUEST_BLOCK:
proto_tree_add_item(block_tree, hf_h1_org, tvb,
offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str (tvb_get_guint8(tvb, offset),
org_vals,"Unknown Type (0x%2.2x)"));
offset++;
proto_tree_add_item(block_tree, hf_h1_dbnr, tvb,
offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " %d",
tvb_get_guint8(tvb, offset));
offset++;
proto_tree_add_item(block_tree, hf_h1_dwnr, tvb,
offset, 2, ENC_BIG_ENDIAN);
col_append_fstr (pinfo->cinfo, COL_INFO, " DW %d",
tvb_get_ntohs(tvb, offset));
offset += 2;
proto_tree_add_item(block_tree, hf_h1_dlen, tvb,
offset, 2, ENC_BIG_ENDIAN);
col_append_fstr (pinfo->cinfo, COL_INFO, " Count %d",
tvb_get_ntohs(tvb, offset));
break;
case RESPONSE_BLOCK:
proto_tree_add_item(block_tree, hf_h1_response_value,
tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr (pinfo->cinfo, COL_INFO, " %s",
val_to_str (tvb_get_guint8(tvb, offset),
returncode_vals,"Unknown Returncode (0x%2.2x"));
break;
}
offset = offset_block_start + block_len;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
return TRUE;
}
void
proto_register_h1 (void)
{
static hf_register_info hf[] = {
{&hf_h1_header,
{"H1-Header", "h1.header", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_len,
{"Length indicator", "h1.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_block_type,
{"Block type", "h1.block_type", FT_UINT8, BASE_HEX, VALS(block_type_vals), 0x0,
NULL, HFILL }},
{&hf_h1_block_len,
{"Block length", "h1.block_len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_h1_opcode,
{"Opcode", "h1.opcode", FT_UINT8, BASE_HEX, VALS (opcode_vals), 0x0,
NULL, HFILL }},
{&hf_h1_org,
{"Memory type", "h1.org", FT_UINT8, BASE_HEX, VALS (org_vals), 0x0,
NULL, HFILL }},
{&hf_h1_dbnr,
{"Memory block number", "h1.dbnr", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_h1_dwnr,
{"Address within memory block", "h1.dwnr", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_dlen,
{"Length in words", "h1.dlen", FT_INT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_h1_response_value,
{"Response value", "h1.resvalue", FT_UINT8, BASE_DEC,
VALS (returncode_vals), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_h1,
&ett_block,
};
proto_h1 = proto_register_protocol ("Sinec H1 Protocol", "H1", "h1");
proto_register_field_array (proto_h1, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_h1(void)
{
heur_dissector_add("cotp", dissect_h1,
"Sinec H1 over COTP", "hi_cotp", proto_h1, HEURISTIC_ENABLE);
heur_dissector_add("cotp_is", dissect_h1,
"Sinec H1 over COTP (inactive subset)", "hi_cotp_is", proto_h1, HEURISTIC_ENABLE);
heur_dissector_add("tcp", dissect_h1,
"Sinec H1 over TCP", "hi_tcp", proto_h1, HEURISTIC_ENABLE);
data_handle = find_dissector("data");
}
