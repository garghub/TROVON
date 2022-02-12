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
ti = proto_tree_add_item(tree, proto_j1939, tvb, offset, tvb_reported_length(tvb), ENC_NA);
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
set_address(&pinfo->src, j1939_address_type, 1, (const void*)src_addr);
pgn = (can_id.id & 0x3FFFF00) >> 8;
if (((can_id.id & 0xFF0000) >> 16) < 240)
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
set_address(&pinfo->dst, j1939_address_type, 1, (const void*)dest_addr);
col_add_fstr(pinfo->cinfo, COL_INFO, "PGN: %d", pgn);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, 0, data_length, ' '));
msg_tree = proto_tree_add_subtree(j1939_tree, tvb, 0, tvb_reported_length(tvb), ett_j1939_message, NULL, "Message");
ti = proto_tree_add_uint(msg_tree, hf_j1939_pgn, tvb, 0, 0, pgn);
PROTO_ITEM_SET_GENERATED(ti);
if (!dissector_try_uint_new(subdissector_pgn_table, pgn, tvb, pinfo, msg_tree, TRUE, data))
{
proto_tree_add_item(msg_tree, hf_j1939_data, tvb, 0, tvb_reported_length(tvb), ENC_NA);
}
return tvb_captured_length(tvb);
}
static int J1939_addr_to_str(const address* addr, gchar *buf, int buf_len _U_)
{
const guint8 *addrdata = (const guint8 *)addr->data;
gchar *start_buf = buf;
buf = uint_to_str_back(buf, *addrdata);
*buf = '\0';
return (int)(buf-start_buf+1);
}
static int J1939_addr_str_len(const address* addr _U_)
{
return 11;
}
static const char* J1939_col_filter_str(const address* addr _U_, gboolean is_src)
{
if (is_src)
return "j1939.src_addr";
return "j1939.dst_addr";
}
static int J1939_addr_len(void)
{
return 1;
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
FT_UINT32, BASE_CUSTOM, CF_FUNC(j1939_fmt_address), 0x000000FF, NULL, HFILL }
},
{ &hf_j1939_dst_addr,
{"Destination Address", "j1939.dst_addr",
FT_UINT32, BASE_CUSTOM, CF_FUNC(j1939_fmt_address), 0x0000FF00, NULL, HFILL }
},
{ &hf_j1939_group_extension,
{"Group Extension", "j1939.group_extension",
FT_UINT32, BASE_DEC, NULL, 0x0000FF00, NULL, HFILL }
},
{ &hf_j1939_data,
{"Data", "j1939.data",
FT_BYTES, BASE_NONE|BASE_ALLOW_ZERO, NULL, 0x0, NULL, HFILL }
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
subdissector_pgn_table = register_dissector_table("j1939.pgn", "PGN Handle", proto_j1939, FT_UINT32, BASE_DEC, DISSECTOR_TABLE_ALLOW_DUPLICATE);
j1939_address_type = address_type_dissector_register("AT_J1939", "J1939 Address", J1939_addr_to_str, J1939_addr_str_len, J1939_col_filter_str, J1939_addr_len, NULL, NULL);
}
void
proto_reg_handoff_j1939(void)
{
dissector_handle_t j1939_handle;
j1939_handle = create_dissector_handle( dissect_j1939, proto_j1939 );
dissector_add_for_decode_as("can.subdissector", j1939_handle );
}
