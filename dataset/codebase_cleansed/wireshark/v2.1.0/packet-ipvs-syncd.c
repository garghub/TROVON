static int
dissect_ipvs_syncd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_tree *tree;
proto_item *item;
int offset = 0;
guint8 cnt = 0;
int conn = 0;
item = proto_tree_add_item(parent_tree, proto_ipvs_syncd, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_ipvs_syncd);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPVS");
col_clear(pinfo->cinfo, COL_INFO);
cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_conn_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_syncid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (conn = 0; conn < cnt; conn++)
{
proto_tree *ctree;
proto_tree *ftree, *fi;
guint16 flags;
ctree = proto_tree_add_subtree_format(tree, tvb, offset, 24, ett_conn, NULL,
"Connection #%d", conn+1);
proto_tree_add_item(ctree, hf_resv8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ctree, hf_proto, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ctree, hf_cport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ctree, hf_vport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ctree, hf_dport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ctree, hf_caddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_vaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_daddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
flags = tvb_get_ntohs(tvb, offset);
fi = proto_tree_add_item(ctree, hf_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
ftree = proto_item_add_subtree(fi, ett_flags);
proto_tree_add_item(ftree, hf_flags_conn_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_hashed_entry, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_no_output_packets, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_conn_not_established, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_adjust_output_seq, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_adjust_input_seq, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ftree, hf_flags_no_client_port_set, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ctree, hf_state, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ( flags & IP_VS_CONN_F_SEQ_MASK )
{
proto_tree_add_item(ctree, hf_in_seq_init, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_in_seq_delta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_in_seq_pdelta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_out_seq_init, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_out_seq_delta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ctree, hf_out_seq_pdelta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_ipvs_syncd(void)
{
static hf_register_info hf[] = {
{ &hf_conn_count,
{ "Connection Count", "ipvs.conncount", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_syncid,
{ "Synchronization ID", "ipvs.syncid", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_size,
{ "Size", "ipvs.size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_resv8,
{ "Reserved", "ipvs.resv8", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_proto,
{ "Protocol", "ipvs.proto", FT_UINT8, BASE_HEX,
VALS(proto_strings), 0, NULL, HFILL }},
{ &hf_cport,
{ "Client Port", "ipvs.cport", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_vport,
{ "Virtual Port", "ipvs.vport", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_dport,
{ "Destination Port", "ipvs.dport", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_caddr,
{ "Client Address", "ipvs.caddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_vaddr,
{ "Virtual Address", "ipvs.vaddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_daddr,
{ "Destination Address", "ipvs.daddr", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_flags,
{ "Flags", "ipvs.flags", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_flags_conn_type,
{ "Connection Type", "ipvs.flags.conn_type", FT_UINT16, BASE_HEX,
VALS(connection_type_strings), 0x0F, NULL, HFILL }},
{ &hf_flags_hashed_entry,
{ "Hashed Entry", "ipvs.flags.hashed_entry", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_HASHED, NULL, HFILL }},
{ &hf_flags_no_output_packets,
{ "No Output Packets", "ipvs.flags.no_output_packets", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_NOOUTPUT, NULL, HFILL }},
{ &hf_flags_conn_not_established,
{ "Connection Not Established", "ipvs.flags.conn_not_established", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_INACTIVE, NULL, HFILL }},
{ &hf_flags_adjust_output_seq,
{ "Adjust Output Sequence", "ipvs.flags.adjust_output_seq", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_OUT_SEQ, NULL, HFILL }},
{ &hf_flags_adjust_input_seq,
{ "Adjust Input Sequence", "ipvs.flags.adjust_input_seq", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_IN_SEQ, NULL, HFILL }},
{ &hf_flags_no_client_port_set,
{ "No Client Port Set", "ipvs.flags.no_client_port_set", FT_BOOLEAN, 16,
TFS(&tfs_true_false), IP_VS_CONN_F_NO_CPORT, NULL, HFILL }},
{ &hf_state,
{ "State", "ipvs.state", FT_UINT16, BASE_HEX,
VALS(state_strings), 0, NULL, HFILL }},
{ &hf_in_seq_init,
{ "Input Sequence (Initial)", "ipvs.in_seq.initial", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_in_seq_delta,
{ "Input Sequence (Delta)", "ipvs.in_seq.delta", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_in_seq_pdelta,
{ "Input Sequence (Previous Delta)", "ipvs.in_seq.pdelta", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_out_seq_init,
{ "Output Sequence (Initial)", "ipvs.out_seq.initial", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_out_seq_delta,
{ "Output Sequence (Delta)", "ipvs.out_seq.delta", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_out_seq_pdelta,
{ "Output Sequence (Previous Delta)", "ipvs.out_seq.pdelta", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipvs_syncd,
&ett_conn,
&ett_flags,
};
proto_ipvs_syncd = proto_register_protocol("IP Virtual Services Sync Daemon",
"IPVS", "ipvs");
proto_register_field_array(proto_ipvs_syncd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ipvs_syncd(void)
{
dissector_handle_t ipvs_syncd_handle;
ipvs_syncd_handle = create_dissector_handle(dissect_ipvs_syncd, proto_ipvs_syncd);
dissector_add_uint("udp.port", IPVS_SYNCD_PORT, ipvs_syncd_handle);
}
