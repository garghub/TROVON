static void
dissect_nettl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *nettl_tree;
proto_item *nettl_item;
pinfo->current_proto = "nettl";
if (tree) {
nettl_item = proto_tree_add_protocol_format(tree, proto_nettl, tvb,
0, -1, "HP-UX Network Tracing and Logging (nettl) header");
nettl_tree = proto_item_add_subtree(nettl_item, ett_nettl);
proto_tree_add_uint_format_value(nettl_tree, hf_nettl_subsys, tvb,
0, 0, pinfo->pseudo_header->nettl.subsys, "%d (%s)", pinfo->pseudo_header->nettl.subsys,
val_to_str_const(pinfo->pseudo_header->nettl.subsys, subsystem, "Unknown"));
proto_tree_add_int(nettl_tree, hf_nettl_devid, tvb,
0, 0, pinfo->pseudo_header->nettl.devid);
proto_tree_add_uint_format_value(nettl_tree, hf_nettl_kind, tvb,
0, 0, pinfo->pseudo_header->nettl.kind,
"0x%08x (%s)", pinfo->pseudo_header->nettl.kind,
val_to_str_const(pinfo->pseudo_header->nettl.kind & ~NETTL_HDR_SUBSYSTEM_BITS_MASK, trace_kind, "Unknown"));
proto_tree_add_int(nettl_tree, hf_nettl_pid, tvb,
0, 0, pinfo->pseudo_header->nettl.pid);
proto_tree_add_uint(nettl_tree, hf_nettl_uid, tvb,
0, 0, pinfo->pseudo_header->nettl.uid);
}
switch (pinfo->fd->lnk_t) {
case WTAP_ENCAP_NETTL_ETHERNET:
call_dissector(eth_withoutfcs_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_TOKEN_RING:
call_dissector(tr_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_FDDI:
if (!dissector_try_uint(wtap_dissector_table,
WTAP_ENCAP_FDDI_BITSWAPPED, tvb, pinfo, tree))
call_dissector(data_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_RAW_IP:
if ( (pinfo->pseudo_header->nettl.kind & NETTL_HDR_PDU_MASK) == 0 )
call_dissector(data_handle, tvb, pinfo, tree);
else if (pinfo->pseudo_header->nettl.subsys == NETTL_SUBSYS_NS_LS_SCTP )
call_dissector(sctp_handle, tvb, pinfo, tree);
else if (!dissector_try_uint(wtap_dissector_table,
WTAP_ENCAP_RAW_IP, tvb, pinfo, tree))
call_dissector(data_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_RAW_ICMP:
if (!dissector_try_uint(ip_proto_dissector_table,
IP_PROTO_ICMP, tvb, pinfo, tree))
call_dissector(data_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_RAW_ICMPV6:
if (!dissector_try_uint(ip_proto_dissector_table,
IP_PROTO_ICMPV6, tvb, pinfo, tree))
call_dissector(data_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_X25:
if (pinfo->pseudo_header->nettl.kind == NETTL_HDR_PDUIN)
pinfo->p2p_dir = P2P_DIR_RECV;
else if (pinfo->pseudo_header->nettl.kind == NETTL_HDR_PDUOUT)
pinfo->p2p_dir = P2P_DIR_SENT;
if (pinfo->pseudo_header->nettl.subsys == NETTL_SUBSYS_SX25L2)
call_dissector(lapb_handle, tvb, pinfo, tree);
else
call_dissector(x25_handle, tvb, pinfo, tree);
break;
case WTAP_ENCAP_NETTL_RAW_TELNET:
if (!dissector_try_uint(tcp_subdissector_table,
TCP_PORT_TELNET, tvb, pinfo, tree))
call_dissector(data_handle, tvb, pinfo, tree);
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UNKNOWN");
col_add_fstr(pinfo->cinfo, COL_INFO, "Unsupported nettl subsytem: %d (%s)",
pinfo->pseudo_header->nettl.subsys,
val_to_str_const(pinfo->pseudo_header->nettl.subsys, subsystem, "Unknown"));
call_dissector(data_handle, tvb, pinfo, tree);
}
}
void
proto_register_nettl(void)
{
static hf_register_info hf[] = {
{ &hf_nettl_subsys,
{ "Subsystem", "nettl.subsys", FT_UINT16, BASE_DEC, VALS(subsystem), 0x0,
"HP-UX Subsystem/Driver", HFILL }},
{ &hf_nettl_devid,
{ "Device ID", "nettl.devid", FT_INT32, BASE_DEC, NULL, 0x0,
"HP-UX Device ID", HFILL }},
{ &hf_nettl_kind,
{ "Trace Kind", "nettl.kind", FT_UINT32, BASE_HEX, VALS(trace_kind), 0x0,
"HP-UX Trace record kind", HFILL}},
{ &hf_nettl_pid,
{ "Process ID (pid/ktid)", "nettl.pid", FT_INT32, BASE_DEC, NULL, 0x0,
"HP-UX Process/thread id", HFILL}},
{ &hf_nettl_uid,
{ "User ID (uid)", "nettl.uid", FT_UINT16, BASE_DEC, NULL, 0x0,
"HP-UX User ID", HFILL}}
};
static gint *ett[] = {
&ett_nettl
};
proto_nettl = proto_register_protocol("HP-UX Network Tracing and Logging", "nettl", "nettl");
proto_register_field_array(proto_nettl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nettl(void)
{
dissector_handle_t nettl_handle;
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
tr_handle = find_dissector("tr");
lapb_handle = find_dissector("lapb");
x25_handle = find_dissector("x.25");
sctp_handle = find_dissector("sctp");
data_handle = find_dissector("data");
wtap_dissector_table = find_dissector_table("wtap_encap");
ip_proto_dissector_table = find_dissector_table("ip.proto");
tcp_subdissector_table = find_dissector_table("tcp.port");
nettl_handle = create_dissector_handle(dissect_nettl, proto_nettl);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_ETHERNET, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_TOKEN_RING, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_FDDI, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_RAW_IP, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_RAW_ICMP, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_RAW_ICMPV6, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_RAW_TELNET, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_X25, nettl_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETTL_UNKNOWN, nettl_handle);
}
