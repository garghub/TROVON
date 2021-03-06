static int
dissect_e100(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tvbuff_t *next_tvb = NULL;
if (tvb_captured_length(tvb) >= e100_encap_len &&
tvb_get_guint8(tvb, e100_header_ver.offset) == 1 &&
tvb_get_ntohl(tvb, e100_bytes_cap.offset) == tvb_reported_length(tvb)-e100_encap_len)
{
guint32 bytes_captured;
guint32 bytes_original;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "e100");
col_set_str(pinfo->cinfo, COL_INFO, "E100 Encapsulated Packet");
if (tree)
{
proto_item *ti = NULL;
proto_tree *e100_tree = NULL;
ti = proto_tree_add_item(tree, proto_e100, tvb, 0, e100_encap_len, ENC_NA);
e100_tree = proto_item_add_subtree(ti, ett_e100);
proto_tree_add_item(e100_tree, hf_e100_header, tvb,
e100_header_ver.offset, e100_header_ver.len, ENC_BIG_ENDIAN);
proto_tree_add_item(e100_tree, hf_e100_port, tvb,
e100_port_recv.offset, e100_port_recv.len, ENC_BIG_ENDIAN);
proto_tree_add_item(e100_tree, hf_e100_seq, tvb,
e100_seq.offset, e100_seq.len, ENC_BIG_ENDIAN);
proto_tree_add_item(e100_tree, hf_e100_ip, tvb,
e100_ip.offset, e100_ip.len, ENC_BIG_ENDIAN);
proto_tree_add_item(e100_tree, hf_e100_mon_pkt_id, tvb,
e100_mon_pkt_id.offset, e100_mon_pkt_id.len, ENC_BIG_ENDIAN);
{
nstime_t ts;
ts.secs = tvb_get_ntohl(tvb, e100_ts.offset);
ts.nsecs = tvb_get_ntohl(tvb, e100_ts.offset+4)*1000;
proto_tree_add_time(e100_tree, hf_e100_pkt_ts, tvb,
e100_ts.offset, e100_ts.len, &ts);
}
proto_tree_add_item(e100_tree, hf_e100_bytes_cap, tvb,
e100_bytes_cap.offset, e100_bytes_cap.len, ENC_BIG_ENDIAN);
proto_tree_add_item(e100_tree, hf_e100_bytes_orig, tvb,
e100_bytes_orig.offset, e100_bytes_orig.len, ENC_BIG_ENDIAN);
}
bytes_captured = tvb_get_ntohl(tvb, e100_bytes_cap.offset);
bytes_original = tvb_get_ntohl(tvb, e100_bytes_orig.offset);
next_tvb = tvb_new_subset(tvb, e100_encap_len, bytes_captured, bytes_original);
call_dissector(eth_handle, next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
else
{
return 0;
}
}
void
proto_register_e100(void)
{
static hf_register_info hf[] =
{
{ &hf_e100_header,
{ "Header Version",
"e100.version",
FT_UINT8,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_port,
{ "E100 Port Received",
"e100.port_recv",
FT_UINT8,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_seq,
{ "Sequence Number",
"e100.seq_num",
FT_UINT16,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_ip,
{ "E100 IP Address",
"e100.ip",
FT_IPv4,
BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_mon_pkt_id,
{ "Monitor Packet ID",
"e100.mon_pkt_id",
FT_UINT32,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_pkt_ts,
{ "Packet Capture Timestamp",
"e100.pkt_ts",
FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_LOCAL,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_bytes_cap,
{ "Bytes Captured",
"e100.bytes_cap",
FT_UINT32,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_e100_bytes_orig,
{ "Bytes in Original Packet",
"e100.bytes_orig",
FT_UINT32,
BASE_DEC,
NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_e100
};
proto_e100 = proto_register_protocol("E100 Encapsulation", "E100", "e100");
proto_register_field_array(proto_e100, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_e100(void)
{
heur_dissector_add("udp", dissect_e100, "E100 over UDP", "e100_udp", proto_e100, HEURISTIC_ENABLE);
eth_handle = find_dissector_add_dependency("eth_withoutfcs", proto_e100);
}
