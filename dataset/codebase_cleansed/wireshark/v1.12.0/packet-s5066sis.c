void
proto_register_s5066(void)
{
static hf_register_info hf[] = {
{ &hf_s5066_sync_word,
{ "Sync preamble", "s5066sis.sync", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_version,
{ "S5066 version", "s5066sis.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_size,
{ "S_Primitive size", "s5066sis.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_type,
{ "PDU Type", "s5066sis.type", FT_UINT8, BASE_DEC, VALS(s5066_pdu_type), 0x0, NULL, HFILL }
},
{ &hf_s5066_ad_size,
{ "Address size (1/2 Bytes)", "s5066sis.address.size", FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL }
},
{ &hf_s5066_ad_group,
{ "Group address", "s5066sis.address.group", FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL }
},
{ &hf_s5066_ad_address,
{ "Address", "s5066sis.address.address", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_s5066_st_txmode,
{ "Transmission mode", "s5066sis.st.txmode", FT_UINT8, BASE_HEX, VALS(s5066_st_txmode), 0xF0, NULL, HFILL }
},
{ &hf_s5066_st_delivery_confirmation,
{ "Delivery confirmation", "s5066sis.st.confirm", FT_UINT8, BASE_HEX, VALS(s5066_st_delivery_confirmation), 0x0C, NULL, HFILL }
},
{ &hf_s5066_st_delivery_order,
{ "Delivery order", "s5066sis.st.order", FT_UINT8, BASE_HEX, VALS(s5066_st_delivery_order), 0x02, NULL, HFILL }
},
{ &hf_s5066_st_extended,
{ "Extended field", "s5066sis.st.extended", FT_UINT8, BASE_HEX, VALS(s5066_st_extended), 0x01, NULL, HFILL }
},
{ &hf_s5066_st_retries,
{ "Minimum number of retransmissions", "s5066sis.st.retries", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_01_sapid,
{ "Sap ID", "s5066sis.01.sapid", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_01_rank,
{ "Rank", "s5066sis.01.rank", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_01_unused,
{ "(Unused)", "s5066sis.01.unused", FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_03_sapid,
{ "Sap ID", "s5066sis.03.sapid", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_03_unused,
{ "(Unused)", "s5066sis.03.unused", FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_03_mtu,
{ "MTU", "s5066sis.03.mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_04_reason,
{ "Reason", "s5066sis.04.reason", FT_UINT8, BASE_DEC, VALS(s5066_04_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_05_reason,
{ "Reason", "s5066sis.05.reason", FT_UINT8, BASE_DEC, VALS(s5066_05_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_06_link_type,
{ "Hardlink type", "s5066sis.06.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_06_link_priority,
{ "Priority", "s5066sis.06.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_06_sapid,
{ "Remote Sap ID", "s5066sis.06.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_08_remote_status,
{ "Remote node status", "s5066sis.08.status", FT_UINT8, BASE_DEC, VALS(s5066_08_remote_status), 0x0, NULL, HFILL }
},
{ &hf_s5066_08_link_type,
{ "Hardlink type", "s5066sis.08.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_08_link_priority,
{ "Priority", "s5066sis.08.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_08_sapid,
{ "Remote Sap ID", "s5066sis.08.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_09_reason,
{ "Reason", "s5066sis.09.reason", FT_UINT8, BASE_DEC, VALS(s5066_09_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_09_link_type,
{ "Hardlink type", "s5066sis.09.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_09_link_priority,
{ "Priority", "s5066sis.09.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_09_sapid,
{ "Remote Sap ID", "s5066sis.09.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_10_reason,
{ "Reason", "s5066sis.10.reason", FT_UINT8, BASE_DEC, VALS(s5066_10_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_10_link_type,
{ "Hardlink type", "s5066sis.10.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_10_link_priority,
{ "Priority", "s5066sis.10.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_10_sapid,
{ "Remote Sap ID", "s5066sis.10.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_11_remote_status,
{ "Remote node status", "s5066sis.11.status", FT_UINT8, BASE_DEC, VALS(s5066_11_remote_status), 0x0, NULL, HFILL }
},
{ &hf_s5066_11_link_type,
{ "Hardlink type", "s5066sis.11.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_11_link_priority,
{ "Priority", "s5066sis.11.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_11_sapid,
{ "Remote Sap ID", "s5066sis.11.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_12_link_type,
{ "Hardlink type", "s5066sis.12.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_12_link_priority,
{ "Priority", "s5066sis.12.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_12_sapid,
{ "Remote Sap ID", "s5066sis.12.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_13_reason,
{ "Reason", "s5066sis.13.reason", FT_UINT8, BASE_DEC, VALS(s5066_13_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_13_link_type,
{ "Hardlink type", "s5066sis.13.type", FT_UINT8, BASE_DEC, VALS(s5066_hard_link_type), 0xC0, NULL, HFILL }
},
{ &hf_s5066_13_link_priority,
{ "Priority", "s5066sis.13.priority", FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL }
},
{ &hf_s5066_13_sapid,
{ "Remote Sap ID", "s5066sis.13.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_14_status,
{ "Status", "s5066sis.14.status", FT_UINT8, BASE_DEC, VALS(s5066_14_status), 0x0, NULL, HFILL }
},
{ &hf_s5066_14_reason,
{ "Reason", "s5066sis.14.reason", FT_UINT8, BASE_DEC, VALS(s5066_14_reason), 0x0, NULL, HFILL }
},
{ &hf_s5066_18_type,
{ "Message Type", "s5066sis.18.type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_18_body,
{ "Message Body", "s5066sis.18.body", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_19_type,
{ "Message Type", "s5066sis.19.type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_19_body,
{ "Message Body", "s5066sis.19.body", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_20_priority,
{ "Priority", "s5066sis.20.priority", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_20_sapid,
{ "Destination Sap ID", "s5066sis.20.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_20_ttl,
{ "Time-To-Live (x2 seconds)", "s5066sis.20.ttl", FT_UINT24, BASE_DEC, NULL, 0x0FFFFF, NULL, HFILL }
},
{ &hf_s5066_20_size,
{ "U_PDU Size", "s5066sis.20.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_priority,
{ "Priority", "s5066sis.21.priority", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_21_dest_sapid,
{ "Destination Sap ID", "s5066sis.21.dest_sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_21_tx_mode,
{ "Transmission Mode", "s5066sis.21.txmode", FT_UINT8, BASE_HEX, VALS(s5066_st_txmode), 0xF0, NULL, HFILL }
},
{ &hf_s5066_21_src_sapid,
{ "Source Sap ID", "s5066sis.21.src_sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_21_size,
{ "U_PDU Size", "s5066sis.21.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_err_blocks,
{ "Number of errored blocks", "s5066sis.21.err_blocks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_err_ptr,
{ "Pointer to error block", "s5066sis.21.err_ptr", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_err_size,
{ "Size of error block", "s5066sis.21.err_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_nrx_blocks,
{ "Number of non-received blocks", "s5066sis.21.nrx_blocks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_nrx_ptr,
{ "Pointer to non-received block", "s5066sis.21.nrx_ptr", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_21_nrx_size,
{ "Size of non-received block", "s5066sis.21.nrx_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_22_unused,
{ "(Unused)", "s5066sis.22.unused", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_22_sapid,
{ "Destination Sap ID", "s5066sis.22.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_22_size,
{ "U_PDU Size", "s5066sis.22.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_22_data,
{ "(Part of) Confirmed data", "s5066sis.22.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_23_reason,
{ "Reason", "s5066sis.23.reason", FT_UINT8, BASE_DEC, VALS(s5066_23_reason), 0xF0, NULL, HFILL }
},
{ &hf_s5066_23_sapid,
{ "Destination Sap ID", "s5066sis.23.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_23_size,
{ "U_PDU Size", "s5066sis.23.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_23_data,
{ "(Part of) Rejected data", "s5066sis.23.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_24_unused,
{ "(Unused)", "s5066sis.24.unused", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_24_sapid,
{ "Destination Sap ID", "s5066sis.24.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_24_ttl,
{ "Time-To-Live (x2 seconds)", "s5066sis.24.ttl", FT_UINT24, BASE_DEC, NULL, 0x0FFFFF, NULL, HFILL }
},
{ &hf_s5066_24_size,
{ "U_PDU Size", "s5066sis.24.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_unused,
{ "(Unused)", "s5066sis.25.unused", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_25_dest_sapid,
{ "Destination Sap ID", "s5066sis.25.dest_sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_25_tx_mode,
{ "Transmission Mode", "s5066sis.25.txmode", FT_UINT8, BASE_HEX, VALS(s5066_st_txmode), 0xF0, NULL, HFILL }
},
{ &hf_s5066_25_src_sapid,
{ "Source Sap ID", "s5066sis.25.src_sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_25_size,
{ "U_PDU Size", "s5066sis.25.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_err_blocks,
{ "Number of errored blocks", "s5066sis.25.err_blocks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_err_ptr,
{ "Pointer to error block", "s5066sis.25.err_ptr", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_err_size,
{ "Size of error block", "s5066sis.25.err_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_nrx_blocks,
{ "Number of non-received blocks", "s5066sis.25.nrx_blocks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_nrx_ptr,
{ "Pointer to non-received block", "s5066sis.25.nrx_ptr", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_25_nrx_size,
{ "Size of non-received block", "s5066sis.25.nrx_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_26_unused,
{ "(Unused)", "s5066sis.26.unused", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066_26_sapid,
{ "Destination Sap ID", "s5066sis.26.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_26_size,
{ "U_PDU Size", "s5066sis.26.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_26_data,
{ "(Part of) Confirmed data", "s5066sis.26.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_27_reason,
{ "Reason", "s5066sis.27.reason", FT_UINT8, BASE_DEC, VALS(s5066_27_reason), 0xF0, NULL, HFILL }
},
{ &hf_s5066_27_sapid,
{ "Destination Sap ID", "s5066sis.27.sapid", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
{ &hf_s5066_27_size,
{ "U_PDU Size", "s5066sis.27.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066_27_data,
{ "(Part of) Rejected data", "s5066sis.27.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_s5066,
&ett_s5066_pdu,
&ett_s5066_servicetype,
&ett_s5066_address,
};
module_t *s5066_module;
proto_s5066 = proto_register_protocol (
"STANAG 5066 (SIS layer)",
"STANAG 5066 SIS",
"s5066sis"
);
proto_register_field_array(proto_s5066, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
s5066_module = prefs_register_protocol(proto_s5066, proto_reg_handoff_s5066);
prefs_register_bool_preference(s5066_module, "desegment_pdus",
"Reassemble S5066 SIS PDUs spanning multiple TCP segments",
"Whether the S5066 SIS dissector should reassemble PDUs spanning multiple TCP segments."
" The default is to use reassembly.",
&s5066_desegment);
prefs_register_bool_preference(s5066_module, "edition_one",
"Dissect edition 1.0 of STANAG 5066",
"Whether the S5066 SIS dissector should dissect this edition of the STANAG."
" This edition was never formally approved and is very rare. The common edition is edition 1.2.",
&s5066_edition_one);
prefs_register_uint_preference(s5066_module, "tcp.port",
"STANAG 5066 SIS TCP Port",
"Set the port for STANAG 5066 SIS. (If other than the default 5066."
" This number is registered with IANA.)",
10, &global_s5066_port);
}
void
proto_reg_handoff_s5066(void)
{
static gboolean Initialized = FALSE;
static dissector_handle_t s5066_tcp_handle;
static guint saved_s5066_port;
if (!Initialized) {
s5066_tcp_handle = new_create_dissector_handle(dissect_s5066_tcp, proto_s5066);
data_handle = find_dissector("data");
Initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", saved_s5066_port, s5066_tcp_handle);
}
dissector_add_uint("tcp.port", global_s5066_port, s5066_tcp_handle);
saved_s5066_port = global_s5066_port;
if (!s5066_edition_one) {
s5066_header_size = 5;
s5066_size_offset = 3;
} else {
s5066_header_size = 4;
s5066_size_offset = 2;
}
}
static guint
dissect_s5066_address(tvbuff_t *tvb, guint offset, proto_tree *tree, gint source)
{
proto_item *ti = NULL;
proto_tree *s5066_tree_address = NULL;
guint32 addr;
if (source) {
ti = proto_tree_add_text(tree, tvb, offset, 4, "Source Address");
}
else {
ti = proto_tree_add_text(tree, tvb, offset, 4, "Destination Address");
}
s5066_tree_address = proto_item_add_subtree(ti, ett_s5066_address);
proto_tree_add_item(s5066_tree_address, hf_s5066_ad_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(s5066_tree_address, hf_s5066_ad_group, tvb, offset, 1, ENC_BIG_ENDIAN);
addr = tvb_get_ntohl(tvb, offset);
addr = addr & 0x1FFFFFFF;
proto_tree_add_ipv4(s5066_tree_address, hf_s5066_ad_address, tvb, offset, 4, g_htonl(addr));
return offset + 4;
}
static guint
dissect_s5066_servicetype(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *s5066_tree_servicetype = NULL;
ti = proto_tree_add_text(tree, tvb, offset, 2, "Service type");
s5066_tree_servicetype = proto_item_add_subtree(ti, ett_s5066_servicetype);
proto_tree_add_item(s5066_tree_servicetype, hf_s5066_st_txmode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(s5066_tree_servicetype, hf_s5066_st_delivery_confirmation, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(s5066_tree_servicetype, hf_s5066_st_delivery_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(s5066_tree_servicetype, hf_s5066_st_extended, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(s5066_tree_servicetype, hf_s5066_st_retries, tvb, offset, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
dissect_s5066_01(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_01_sapid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_01_rank, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_servicetype(tvb, offset, tree);
proto_tree_add_item(tree, hf_s5066_01_unused, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint
dissect_s5066_03(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_03_sapid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_03_unused, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_03_mtu, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
return offset;
}
static guint
dissect_s5066_04(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_04_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint
dissect_s5066_05(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_05_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint
dissect_s5066_06(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_06_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_06_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_06_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_07(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_08(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_08_remote_status, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_08_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_08_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_08_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_09(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_09_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_09_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_09_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_09_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_10(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_10_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_10_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_10_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_10_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_11(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_11_remote_status, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_11_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_11_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_11_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_12(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_12_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_12_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_12_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_13(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_13_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_13_link_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_13_link_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_13_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
return offset;
}
static guint
dissect_s5066_14(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_14_status, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066_14_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint
dissect_s5066_18(tvbuff_t *tvb, guint offset, proto_tree *tree, guint pdu_size)
{
guint body_size = 0;
proto_tree_add_item(tree, hf_s5066_18_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
body_size = pdu_size - offset;
proto_tree_add_item(tree, hf_s5066_18_body, tvb, offset, body_size, ENC_NA); offset += body_size;
return offset;
}
static guint
dissect_s5066_19(tvbuff_t *tvb, guint offset, proto_tree *tree, guint pdu_size)
{
guint body_size = 0;
proto_tree_add_item(tree, hf_s5066_19_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
body_size = pdu_size - offset;
proto_tree_add_item(tree, hf_s5066_19_body, tvb, offset, body_size, ENC_NA); offset += body_size;
return offset;
}
static guint
dissect_s5066_20(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_20_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_20_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
offset = dissect_s5066_servicetype(tvb, offset, tree);
proto_tree_add_item(tree, hf_s5066_20_ttl, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
proto_tree_add_item(tree, hf_s5066_20_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
return offset;
}
static guint
dissect_s5066_21(tvbuff_t *tvb, guint offset, proto_tree *tree, guint pdu_size)
{
guint i=0;
proto_item *ti = NULL;
guint d_pdu_size = 0;
guint8 tx_mode = 0;
guint16 no_err_blocks = 0;
guint16 no_nrx_blocks = 0;
gboolean non_arq_w_errors = FALSE;
proto_tree_add_item(tree, hf_s5066_21_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_21_dest_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
tx_mode = tvb_get_guint8(tvb, offset);
tx_mode = (tx_mode & 0xF0) >> 4;
if (tx_mode == 3) {
non_arq_w_errors = TRUE;
}
proto_tree_add_item(tree, hf_s5066_21_tx_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_21_src_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, TRUE);
d_pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_21_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
if ( (pdu_size - offset) == (d_pdu_size + 4) ) {
ti = proto_tree_add_item(tree, hf_s5066_21_err_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_append_text(ti, ", (Field should not be present. Rockwell Collins v2.1 or earlier.) ");
ti = proto_tree_add_item(tree, hf_s5066_21_nrx_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_append_text(ti, ", (Field should not be present. Rockwell Collins v2.1 or earlier.) ");
}
if ( non_arq_w_errors ) {
no_err_blocks = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_21_err_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
for (i=0; i<no_err_blocks; i++) {
proto_tree_add_item(tree, hf_s5066_21_err_ptr, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_21_err_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
no_nrx_blocks = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_21_nrx_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
for (i=0; i<no_nrx_blocks; i++) {
proto_tree_add_item(tree, hf_s5066_21_nrx_ptr, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_21_nrx_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
}
return offset;
}
static guint
dissect_s5066_22(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint pdu_size = 0;
proto_tree_add_item(tree, hf_s5066_22_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_22_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_22_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_22_data, tvb, offset, pdu_size, ENC_NA); offset += pdu_size;
return offset;
}
static guint
dissect_s5066_23(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint pdu_size = 0;
proto_tree_add_item(tree, hf_s5066_23_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_23_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_23_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_23_data, tvb, offset, pdu_size, ENC_NA); offset += pdu_size;
return offset;
}
static guint
dissect_s5066_24(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066_24_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_24_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
offset = dissect_s5066_servicetype(tvb, offset, tree);
proto_tree_add_item(tree, hf_s5066_24_ttl, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
proto_tree_add_item(tree, hf_s5066_24_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
return offset;
}
static guint
dissect_s5066_25(tvbuff_t *tvb, guint offset, proto_tree *tree, guint pdu_size)
{
guint i=0;
proto_item *ti = NULL;
guint d_pdu_size = 0;
guint8 tx_mode = 0;
guint16 no_err_blocks = 0;
guint16 no_nrx_blocks = 0;
gboolean non_arq_w_errors = FALSE;
proto_tree_add_item(tree, hf_s5066_25_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_25_dest_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
tx_mode = tvb_get_guint8(tvb, offset);
tx_mode = (tx_mode & 0xF0) >> 4;
if (tx_mode == 3) {
non_arq_w_errors = TRUE;
}
proto_tree_add_item(tree, hf_s5066_25_tx_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_25_src_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, TRUE);
d_pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_25_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
if ( (pdu_size - offset) == (d_pdu_size + 4) ) {
ti = proto_tree_add_item(tree, hf_s5066_25_err_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_append_text(ti, ", (Field should not be present. Rockwell Collins v2.1 or earlier.) ");
ti = proto_tree_add_item(tree, hf_s5066_25_nrx_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_item_append_text(ti, ", (Field should not be present. Rockwell Collins v2.1 or earlier.) ");
}
if ( non_arq_w_errors ) {
no_err_blocks = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_25_err_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
for (i=0; i<no_err_blocks; i++) {
proto_tree_add_item(tree, hf_s5066_25_err_ptr, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_25_err_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
no_nrx_blocks = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_25_nrx_blocks, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
for (i=0; i<no_nrx_blocks; i++) {
proto_tree_add_item(tree, hf_s5066_25_nrx_ptr, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_25_nrx_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
}
return offset;
}
static guint
dissect_s5066_26(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint pdu_size = 0;
proto_tree_add_item(tree, hf_s5066_26_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_26_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_26_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_26_data, tvb, offset, pdu_size, ENC_NA); offset += pdu_size;
return offset;
}
static guint
dissect_s5066_27(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint pdu_size = 0;
proto_tree_add_item(tree, hf_s5066_27_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066_27_sapid, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066_address(tvb, offset, tree, FALSE);
pdu_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_s5066_27_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(tree, hf_s5066_27_data, tvb, offset, pdu_size, ENC_NA); offset += pdu_size;
return offset;
}
static guint
get_s5066_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset + s5066_size_offset);
return plen + s5066_header_size;
}
static int
dissect_s5066_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
if (tvb_length(tvb) < 5)
return 0;
if( (tvb_get_guint8(tvb, 0) != 0x90) ||
(tvb_get_guint8(tvb, 1) != 0xEB) ||
(tvb_get_guint8(tvb, 2) != 0x00) ) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, s5066_desegment, s5066_header_size, get_s5066_pdu_len, dissect_s5066_common, data);
return tvb_length(tvb);
}
static int
dissect_s5066_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint pdu_size = 0;
proto_item *ti_s5066 = NULL;
proto_item *ti_pdu = NULL;
tvbuff_t *next_tvb;
gint available_length = 0;
gint reported_length = 0;
guint8 pdu_type = tvb_get_guint8(tvb, s5066_header_size);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S5066");
col_add_fstr(pinfo->cinfo, COL_INFO, "PDU type %s", val_to_str(pdu_type, s5066_pdu_type, "Unknown (0x%02x)"));
if (tree) {
proto_tree *s5066_tree = NULL;
proto_tree *s5066_tree_pdu = NULL;
pdu_size = tvb_get_ntohs(tvb, s5066_size_offset) + s5066_header_size;
ti_s5066 = proto_tree_add_item(tree, proto_s5066, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti_s5066, ", PDU type %s", val_to_str(pdu_type, s5066_pdu_type, "Unknown (0x%02x)"));
s5066_tree = proto_item_add_subtree(ti_s5066, ett_s5066);
proto_tree_add_item(s5066_tree, hf_s5066_sync_word, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
if (!s5066_edition_one) {
proto_tree_add_item(s5066_tree, hf_s5066_version, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
}
proto_tree_add_item(s5066_tree, hf_s5066_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
ti_pdu = proto_tree_add_item(s5066_tree, hf_s5066_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
s5066_tree_pdu = proto_item_add_subtree(ti_pdu, ett_s5066_pdu);
switch (pdu_type) {
case 1: offset = dissect_s5066_01(tvb, offset, s5066_tree_pdu); break;
case 3: offset = dissect_s5066_03(tvb, offset, s5066_tree_pdu); break;
case 4: offset = dissect_s5066_04(tvb, offset, s5066_tree_pdu); break;
case 5: offset = dissect_s5066_05(tvb, offset, s5066_tree_pdu); break;
case 6: offset = dissect_s5066_06(tvb, offset, s5066_tree_pdu); break;
case 7: offset = dissect_s5066_07(tvb, offset, s5066_tree_pdu); break;
case 8: offset = dissect_s5066_08(tvb, offset, s5066_tree_pdu); break;
case 9: offset = dissect_s5066_09(tvb, offset, s5066_tree_pdu); break;
case 10: offset = dissect_s5066_10(tvb, offset, s5066_tree_pdu); break;
case 11: offset = dissect_s5066_11(tvb, offset, s5066_tree_pdu); break;
case 12: offset = dissect_s5066_12(tvb, offset, s5066_tree_pdu); break;
case 13: offset = dissect_s5066_13(tvb, offset, s5066_tree_pdu); break;
case 14: offset = dissect_s5066_14(tvb, offset, s5066_tree_pdu); break;
case 18: offset = dissect_s5066_18(tvb, offset, s5066_tree_pdu, pdu_size); break;
case 19: offset = dissect_s5066_19(tvb, offset, s5066_tree_pdu, pdu_size); break;
case 20: offset = dissect_s5066_20(tvb, offset, s5066_tree_pdu); break;
case 21: offset = dissect_s5066_21(tvb, offset, s5066_tree_pdu, pdu_size); break;
case 22: offset = dissect_s5066_22(tvb, offset, s5066_tree_pdu); break;
case 23: offset = dissect_s5066_23(tvb, offset, s5066_tree_pdu); break;
case 24: offset = dissect_s5066_24(tvb, offset, s5066_tree_pdu); break;
case 25: offset = dissect_s5066_25(tvb, offset, s5066_tree_pdu, pdu_size); break;
case 26: offset = dissect_s5066_26(tvb, offset, s5066_tree_pdu); break;
case 27: offset = dissect_s5066_27(tvb, offset, s5066_tree_pdu); break;
}
}
proto_item_set_len(ti_s5066, offset);
reported_length = pdu_size - offset;
available_length = tvb_length(tvb) - offset;
next_tvb = tvb_new_subset(tvb, offset, MIN(available_length, reported_length), reported_length);
call_dissector(data_handle, next_tvb, pinfo, tree);
return tvb_length(tvb);
}
