static int
dissect_userlog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *userlog_header, *userlog_tree;
proto_tree *userlog_log;
gint offset = 0;
guint log_count = 1;
guint log_type, log_max;
if (tvb_reported_length(tvb) < USERLOG_MIN_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UserLog");
col_clear(pinfo->cinfo,COL_INFO);
ti = proto_tree_add_item(tree, proto_userlog, tvb, 0, -1, ENC_NA);
userlog_tree = proto_item_add_subtree(ti, ett_userlog);
userlog_header = proto_tree_add_subtree(userlog_tree, tvb, 0, 16, ett_userlog_header, NULL, "UserLog Header");
proto_tree_add_item(userlog_header, hf_userlog_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(userlog_header, hf_userlog_logtype, tvb, offset, 1, ENC_BIG_ENDIAN, &log_type);
col_add_fstr(pinfo->cinfo, COL_INFO, "LogType = %s", val_to_str(log_type, logtype, "Unknown (0x%02x)"));
offset += 1;
proto_tree_add_item_ret_uint(userlog_header, hf_userlog_count, tvb, offset, 2, ENC_BIG_ENDIAN, &log_max);
proto_item_append_text(ti, ", Log Count = %d", log_max);
offset += 2;
proto_tree_add_item(userlog_header, hf_userlog_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_header, hf_userlog_header_reserved, tvb, offset, 8, ENC_NA);
offset += 8;
if (userlog_tree) {
while ( log_count <= log_max)
{
userlog_log = proto_tree_add_subtree_format(userlog_tree, tvb, offset, 64, ett_userlog_log, NULL, "UserLog No.%d", log_count);
proto_tree_add_item(userlog_log, hf_userlog_proto, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(userlog_log, hf_userlog_Operator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(userlog_log, hf_userlog_IPVerion, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(userlog_log, hf_userlog_IPToS, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(userlog_log, hf_userlog_SourceIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_SrcNatIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_DestIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_DestNatIP, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_SrcPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(userlog_log, hf_userlog_SrcNatPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(userlog_log, hf_userlog_DestPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(userlog_log, hf_userlog_DestNatPort, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(userlog_log, hf_userlog_StartTime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_EndTime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_InTotalPkg, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_InTotalByte, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_OutTotalPkg, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_OutTotalByte, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_Reserved1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_Reserved2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(userlog_log, hf_userlog_Reserved3, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
log_count++;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_userlog(void)
{
static hf_register_info hf[] = {
{ &hf_userlog_version,
{ "Version", "userlog.version",
FT_UINT8, BASE_DEC,
VALS(version), 0x0,
NULL, HFILL }
},
{ &hf_userlog_logtype,
{ "LogType", "userlog.logtype",
FT_UINT8, BASE_DEC,
VALS(logtype), 0x0,
NULL, HFILL }
},
{ &hf_userlog_count,
{ "LogCount", "userlog.count",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_timestamp,
{ "TimeStamp", "userlog.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_header_reserved,
{ "Reserved", "userlog.header_reserved",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_proto,
{ "Protocol", "userlog.proto",
FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_userlog_Operator,
{ "Operator", "userlog.Operator",
FT_UINT8, BASE_DEC,
VALS(Operator), 0x0,
NULL, HFILL }
},
{ &hf_userlog_IPVerion,
{ "IP Version", "userlog.IPVersion",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_IPToS,
{ "IP ToS", "userlog.IPToS",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_SourceIP,
{ "Source-IP", "userlog.SourceIP",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_SrcNatIP,
{ "Source-NAT-IP", "userlog.Source-NAT-IP",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_DestIP,
{ "Destination-IP", "userlog.Destination-IP",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_DestNatIP,
{ "Destination-NAT-IP", "userlog.Destination-NAT-IP",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_SrcPort,
{ "Source-Port", "userlog.Source-Port",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_SrcNatPort,
{ "Source-NAT-Port", "userlog.Source-NAT-Port",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_DestPort,
{ "Destination-Port", "userlog.Destination-Port",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_DestNatPort,
{ "Destination-NAT-Port", "userlog.Destination-NAT-Port",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_StartTime,
{ "StartTime", "userlog.StartTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_EndTime,
{ "EndTime", "userlog.EndTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_InTotalPkg,
{ "InTotalPkg", "userlog.InTotalPkg",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_InTotalByte,
{ "InTotalByte", "userlog.InTotalByte",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_OutTotalPkg,
{ "OutTotalPkg", "userlog.OutTotalPkg",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_OutTotalByte,
{ "OutTotalByte", "userlog.OutTotalByte",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_Reserved1,
{ "Reserved1", "userlog.Reserved1",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_Reserved2,
{ "Reserved2", "userlog.Reserved2",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_userlog_Reserved3,
{ "Reserved3", "userlog.Reserved3",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_userlog,
&ett_userlog_header,
&ett_userlog_log
};
proto_userlog = proto_register_protocol("UserLog Protocol", "UserLog", "userlog");
proto_register_field_array(proto_userlog, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_userlog(void)
{
dissector_handle_t userlog_handle;
userlog_handle = create_dissector_handle(dissect_userlog, proto_userlog);
dissector_add_for_decode_as_with_preference("udp.port", userlog_handle);
}
