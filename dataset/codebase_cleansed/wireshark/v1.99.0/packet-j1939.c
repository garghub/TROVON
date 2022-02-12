static void
j1939_fmt_address(gchar *result, guint32 addr )
{
if ((addr < 128) || (addr > 247))
g_snprintf(result, ITEM_LABEL_LENGTH, "%d (%s)", addr, val_to_str_ext_const(addr, &j1939_address_vals_ext, "Reserved"));
else
g_snprintf(result, ITEM_LABEL_LENGTH, "%d (Arbitrary)", addr);
}
static int dissect_j1939(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti, *can_id_item;
proto_tree *j1939_tree, *can_tree, *msg_tree;
gint offset = 0;
struct can_identifier can_id;
guint32 data_length = tvb_reported_length(tvb);
guint32 pgn;
guint8 *src_addr, *dest_addr;
DISSECTOR_ASSERT(data);
can_id = *((struct can_identifier*)data);
if (can_id.id & (~J1939_CANID_MASK))
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "J1939");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_j1939, tvb, offset, -1, ENC_NA);
j1939_tree = proto_item_add_subtree(ti, ett_j1939);
can_tree = proto_tree_add_subtree_format(j1939_tree, tvb, 0, 0,
ett_j1939_can, NULL, "CAN Identifier: 0x%08x", can_id.id);
can_id_item = proto_tree_add_uint(can_tree, hf_j1939_can_id, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(can_id_item);
ti = proto_tree_add_uint(can_tree, hf_j1939_priority, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_j1939_extended_data_page, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_j1939_data_page, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_j1939_pdu_format, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_j1939_pdu_specific, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(can_tree, hf_j1939_src_addr, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
src_addr = (guint8*)wmem_alloc(pinfo->pool, 1);
*src_addr = (guint8)(can_id.id & 0xFF);
SET_ADDRESS(&pinfo->src, AT_J1939, 1, (const void*)src_addr);
pgn = (can_id.id & 0x3FFFF00) >> 8;
if (((can_id.id & 0xFF00) >> 8) < 240)
{
pgn &= 0x3FF00;
ti = proto_tree_add_uint(can_tree, hf_j1939_dst_addr, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
}
else
{
ti = proto_tree_add_uint(can_tree, hf_j1939_group_extension, tvb, 0, 0, can_id.id);
PROTO_ITEM_SET_GENERATED(ti);
}
dest_addr = (guint8*)wmem_alloc(pinfo->pool, 1);
*dest_addr = (guint8)((can_id.id & 0xFF00) >> 8);
SET_ADDRESS(&pinfo->dst, AT_J1939, 1, (const void*)dest_addr);
col_add_fstr(pinfo->cinfo, COL_INFO, "PGN: %d", pgn);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", tvb_bytes_to_ep_str_punct(tvb, 0, data_length, ' '));
msg_tree = proto_tree_add_subtree(j1939_tree, tvb, 0, -1, ett_j1939_message, NULL, "Message");
ti = proto_tree_add_uint(msg_tree, hf_j1939_pgn, tvb, 0, 0, pgn);
PROTO_ITEM_SET_GENERATED(ti);
if (!dissector_try_uint_new(subdissector_pgn_table, pgn, tvb, pinfo, msg_tree, TRUE, data))
{
proto_tree_add_item(msg_tree, hf_j1939_data, tvb, 0, -1, ENC_NA);
}
return tvb_length(tvb);
}
void proto_register_j1939(void)
{
static hf_register_info hf[] = {
{ &hf_j1939_can_id,
{"CAN Identifier", "j1939.can_id",
FT_UINT32, BASE_HEX, NULL, J1939_CANID_MASK, NULL, HFILL }
},
{ &hf_j1939_priority,
{"Priority", "j1939.priority",
FT_UINT32, BASE_DEC, NULL, 0x1C000000, NULL, HFILL }
},
{ &hf_j1939_pgn,
{"PGN", "j1939.pgn",
FT_UINT32, BASE_DEC, NULL, 0x3FFFFFF, NULL, HFILL }
},
{ &hf_j1939_extended_data_page,
{"Extended Data Page", "j1939.ex_data_page",
FT_UINT32, BASE_DEC, NULL, 0x02000000, NULL, HFILL }
},
{ &hf_j1939_data_page,
{"Data Page", "j1939.data_page",
FT_UINT32, BASE_DEC, NULL, 0x01000000, NULL, HFILL }
},
{ &hf_j1939_pdu_format,
{"PDU Format", "j1939.pdu_format",
FT_UINT32, BASE_DEC, NULL, 0x00FF0000, NULL, HFILL }
},
{ &hf_j1939_pdu_specific,
{"PDU Specific", "j1939.pdu_specific",
FT_UINT32, BASE_DEC, NULL, 0x0000FF00, NULL, HFILL }
},
{ &hf_j1939_src_addr,
{"Source Address", "j1939.src_addr",
FT_UINT32, BASE_CUSTOM, j1939_fmt_address, 0x000000FF, NULL, HFILL }
},
{ &hf_j1939_dst_addr,
{"Destination Address", "j1939.dst_addr",
FT_UINT32, BASE_CUSTOM, j1939_fmt_address, 0x0000FF00, NULL, HFILL }
},
{ &hf_j1939_group_extension,
{"Group Extension", "j1939.group_extension",
FT_UINT32, BASE_DEC, NULL, 0x0000FF00, NULL, HFILL }
},
{ &hf_j1939_data,
{"Data", "j1939.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_j1939,
&ett_j1939_can,
&ett_j1939_message
};
proto_j1939 = proto_register_protocol("SAE J1939", "J1939", "j1939");
proto_register_field_array(proto_j1939, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("j1939", dissect_j1939, proto_j1939);
subdissector_pgn_table = register_dissector_table("j1939.pgn", "PGN Handle", FT_UINT32, BASE_DEC);
}
