static void
dissect_ax4000(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *ax4000_tree;
guint8 ax_port;
guint8 ax_chassis;
guint16 ax_index;
guint32 ax_seq;
guint32 ax_timestamp;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AX4000");
col_clear(pinfo->cinfo, COL_INFO);
ax_port = tvb_get_guint8(tvb, 0);
ax_chassis = tvb_get_guint8(tvb, 1);
ax_index = tvb_get_ntohs(tvb, 2) & 0x0FFF;
ax_timestamp = tvb_get_letohl(tvb, 6);
ax_seq = tvb_get_letohl(tvb, 10);
col_append_fstr(pinfo->cinfo, COL_INFO,
"Chss:%u Prt:%u Idx:%u Seq:0x%08x TS:%.6f[msec]",
ax_chassis, ax_port, ax_index, ax_seq, ax_timestamp*1e-5);
if (tree) {
ti = proto_tree_add_item(tree, proto_ax4000, tvb, 0, -1, ENC_NA);
ax4000_tree = proto_item_add_subtree(ti, ett_ax4000);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_port, tvb, 0, 1, ax_port);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_chassis, tvb, 1, 1, ax_chassis);
proto_tree_add_item(ax4000_tree,
hf_ax4000_fill, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_index, tvb, 2, 2, ax_index);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_timestamp, tvb, 6, 4, ax_timestamp);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_seq, tvb, 10, 4, ax_seq);
proto_tree_add_uint(ax4000_tree,
hf_ax4000_crc, tvb, 14, 2, tvb_get_letohs(tvb, 14));
}
}
void
proto_register_ax4000(void)
{
static hf_register_info hf[] = {
{ &hf_ax4000_port,
{ "Port Number", "ax4000.port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax4000_chassis,
{ "Chassis Number", "ax4000.chassis",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax4000_fill,
{ "Fill Type", "ax4000.fill",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_ax4000_index,
{ "Index", "ax4000.index",
FT_UINT16, BASE_DEC, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_ax4000_timestamp,
{ "Timestamp", "ax4000.timestamp",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax4000_seq,
{ "Sequence Number", "ax4000.seq",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax4000_crc,
{ "CRC (unchecked)", "ax4000.crc",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_ax4000
};
proto_ax4000 = proto_register_protocol("AX/4000 Test Block",
"AX4000", "ax4000");
proto_register_field_array(proto_ax4000, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ax4000(void)
{
dissector_handle_t ax4000_handle;
ax4000_handle = create_dissector_handle(dissect_ax4000,
proto_ax4000);
dissector_add_uint("ip.proto", IP_PROTO_AX4000, ax4000_handle);
dissector_add_uint("tcp.port", AX4000_TCP_PORT, ax4000_handle);
dissector_add_uint("udp.port", AX4000_UDP_PORT, ax4000_handle);
}
