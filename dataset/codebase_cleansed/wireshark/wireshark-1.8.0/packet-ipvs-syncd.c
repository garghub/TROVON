static void
dissect_ipvs_syncd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
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
proto_tree *ctree, *ti;
proto_tree *ftree, *fi;
guint16 flags;
ti = proto_tree_add_text(tree, tvb, offset, 24, "Connection #%d", conn+1);
ctree = proto_item_add_subtree(ti, ett_conn);
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
if ( (flags & 0x0F) == IP_VS_CONN_F_MASQ )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Connection Type: Masquerade");
}
else if ( (flags & 0x0F) == IP_VS_CONN_F_LOCALNODE )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Connection Type: Local Node");
}
else if ( (flags & 0x0F) == IP_VS_CONN_F_TUNNEL )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Connection Type: Tunnel");
}
else if ( (flags & 0x0F) == IP_VS_CONN_F_DROUTE )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Connection Type: Direct Routing");
}
else
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Connection Type: Unknown (%d)",
flags & IP_VS_CONN_F_FWD_MASK);
}
if ( flags & IP_VS_CONN_F_HASHED )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "Hashed Entry");
}
if ( flags & IP_VS_CONN_F_NOOUTPUT )
{
proto_tree_add_text(ftree, tvb, offset+1, 1, "No Output Packets");
}
if ( flags & IP_VS_CONN_F_INACTIVE )
{
proto_tree_add_text(ftree, tvb, offset, 1, "Connection Not Established");
}
if ( flags & IP_VS_CONN_F_OUT_SEQ )
{
proto_tree_add_text(ftree, tvb, offset, 1, "Adjust Output Sequence");
}
if ( flags & IP_VS_CONN_F_IN_SEQ )
{
proto_tree_add_text(ftree, tvb, offset, 1, "Adjust Input Sequence");
}
if ( flags & IP_VS_CONN_F_NO_CPORT )
{
proto_tree_add_text(ftree, tvb, offset, 1, "No Client Port Set");
}
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
