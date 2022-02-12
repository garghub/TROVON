static gboolean dissect_h1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tvbuff_t *next_tvb;
proto_tree *h1_tree = NULL;
proto_item *ti;
proto_tree *opcode_tree = NULL;
proto_tree *org_tree = NULL;
proto_tree *response_tree = NULL;
proto_tree *empty_tree = NULL;
unsigned int position = 3;
unsigned int offset=0;
if (tvb_length(tvb) < 2)
{
return FALSE;
}
if (!(tvb_get_guint8(tvb,offset) == 'S' && tvb_get_guint8(tvb,offset+1) == '5'))
{
return FALSE;
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "H1");
col_set_str(pinfo->cinfo, COL_INFO, "S5: ");
if (tree)
{
ti = proto_tree_add_item (tree, proto_h1, tvb, offset, 16, ENC_NA);
h1_tree = proto_item_add_subtree (ti, ett_h1);
proto_tree_add_uint (h1_tree, hf_h1_header, tvb, offset, 2,
tvb_get_ntohs(tvb,offset));
proto_tree_add_uint (h1_tree, hf_h1_len, tvb, offset + 2, 1,
tvb_get_guint8(tvb,offset+2));
}
while (position < tvb_get_guint8(tvb,offset+2))
{
switch (tvb_get_guint8(tvb,offset + position))
{
case OPCODE_BLOCK:
if (h1_tree)
{
ti = proto_tree_add_uint (h1_tree, hf_h1_opfield, tvb,
offset + position,
tvb_get_guint8(tvb,offset+position+1),
tvb_get_guint8(tvb,offset+position));
opcode_tree = proto_item_add_subtree (ti, ett_opcode);
proto_tree_add_uint (opcode_tree, hf_h1_oplen, tvb,
offset + position + 1, 1,
tvb_get_guint8(tvb,offset + position + 1));
proto_tree_add_uint (opcode_tree, hf_h1_opcode, tvb,
offset + position + 2, 1,
tvb_get_guint8(tvb,offset + position + 2));
}
if (check_col (pinfo->cinfo, COL_INFO))
{
col_append_str (pinfo->cinfo, COL_INFO,
val_to_str (tvb_get_guint8(tvb,offset + position + 2),
opcode_vals,"Unknown Opcode (0x%2.2x)"));
}
break;
case REQUEST_BLOCK:
if (h1_tree)
{
ti = proto_tree_add_uint (h1_tree, hf_h1_requestblock, tvb,
offset + position,
tvb_get_guint8(tvb,offset + position + 1),
tvb_get_guint8(tvb,offset + position));
org_tree = proto_item_add_subtree (ti, ett_org);
proto_tree_add_uint (org_tree, hf_h1_requestlen, tvb,
offset + position + 1, 1,
tvb_get_guint8(tvb,offset + position+1));
proto_tree_add_uint (org_tree, hf_h1_org, tvb,
offset + position + 2, 1,
tvb_get_guint8(tvb,offset + position+2));
proto_tree_add_uint (org_tree, hf_h1_dbnr, tvb,
offset + position + 3, 1,
tvb_get_guint8(tvb,offset + position+3));
proto_tree_add_uint (org_tree, hf_h1_dwnr, tvb,
offset + position + 4, 2,
tvb_get_ntohs(tvb,offset+position+4));
proto_tree_add_int (org_tree, hf_h1_dlen, tvb,
offset + position + 6, 2,
tvb_get_ntohs(tvb,offset+position+6));
}
if (check_col (pinfo->cinfo, COL_INFO))
{
col_append_fstr (pinfo->cinfo, COL_INFO, " %s %d",
val_to_str (tvb_get_guint8(tvb,offset + position + 2),
org_vals,"Unknown Type (0x%2.2x)"),
tvb_get_guint8(tvb,offset + position + 3));
col_append_fstr (pinfo->cinfo, COL_INFO, " DW %d",
tvb_get_ntohs(tvb,offset+position+4));
col_append_fstr (pinfo->cinfo, COL_INFO, " Count %d",
tvb_get_ntohs(tvb,offset+position+6));
}
break;
case RESPONSE_BLOCK:
if (h1_tree)
{
ti = proto_tree_add_uint (h1_tree, hf_h1_response, tvb,
offset + position,
tvb_get_guint8(tvb,offset + position + 1),
tvb_get_guint8(tvb,offset + position));
response_tree = proto_item_add_subtree (ti, ett_response);
proto_tree_add_uint (response_tree, hf_h1_response_len, tvb,
offset + position + 1, 1,
tvb_get_guint8(tvb,offset + position+1));
proto_tree_add_uint (response_tree, hf_h1_response_value, tvb,
offset + position + 2, 1,
tvb_get_guint8(tvb,offset + position+2));
}
if (check_col (pinfo->cinfo, COL_INFO))
{
col_append_fstr (pinfo->cinfo, COL_INFO, " %s",
val_to_str (tvb_get_guint8(tvb,offset + position + 2),
returncode_vals,"Unknown Returncode (0x%2.2x"));
}
break;
case EMPTY_BLOCK:
if (h1_tree)
{
ti = proto_tree_add_uint (h1_tree, hf_h1_empty, tvb,
offset + position,
tvb_get_guint8(tvb,offset + position + 1),
tvb_get_guint8(tvb,offset + position));
empty_tree = proto_item_add_subtree (ti, ett_empty);
proto_tree_add_uint (empty_tree, hf_h1_empty_len, tvb,
offset + position + 1, 1,
tvb_get_guint8(tvb,offset + position+1));
}
break;
default:
return FALSE;
}
if (tvb_get_guint8(tvb,offset + position + 1) < 1)
THROW(ReportedBoundsError);
position += tvb_get_guint8(tvb,offset + position + 1);
}
next_tvb = tvb_new_subset_remaining(tvb, offset+tvb_get_guint8(tvb,offset+2));
call_dissector(data_handle,next_tvb, pinfo, tree);
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
{&hf_h1_opfield,
{"Operation identifier", "h1.opfield", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_oplen,
{"Operation length", "h1.oplen", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_h1_opcode,
{"Opcode", "h1.opcode", FT_UINT8, BASE_HEX, VALS (opcode_vals), 0x0,
NULL, HFILL }},
{&hf_h1_requestblock,
{"Request identifier", "h1.request", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_requestlen,
{"Request length", "h1.reqlen", FT_UINT8, BASE_HEX, NULL, 0x0,
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
{&hf_h1_response,
{"Response identifier", "h1.response", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_h1_response_len,
{"Response length", "h1.reslen", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_response_value,
{"Response value", "h1.resvalue", FT_UINT8, BASE_DEC,
VALS (returncode_vals), 0x0, NULL, HFILL }},
{&hf_h1_empty,
{"Empty field", "h1.empty", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{&hf_h1_empty_len,
{"Empty field length", "h1.empty_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_h1,
&ett_opcode,
&ett_response,
&ett_org,
&ett_empty
};
proto_h1 = proto_register_protocol ("Sinec H1 Protocol", "H1", "h1");
proto_register_field_array (proto_h1, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_h1(void)
{
heur_dissector_add("cotp", dissect_h1, proto_h1);
heur_dissector_add("cotp_is", dissect_h1, proto_h1);
heur_dissector_add("tcp", dissect_h1, proto_h1);
data_handle = find_dissector("data");
}
