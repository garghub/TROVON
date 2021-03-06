static int dissect_egd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EGD");
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "Data Msg: ExchangeID=0x%08X, RequestID=%05u",
tvb_get_letohl(tvb, 8), tvb_get_letohs(tvb, 2));
if (tree)
{
proto_item *ti = NULL;
proto_item *notime = NULL;
proto_tree *egd_tree = NULL;
tvbuff_t *next_tvb = NULL;
gint offset, data_length;
guint32 sectime;
nstime_t egd_time;
memset(&egd_time, 0, sizeof(nstime_t));
offset = 0;
ti = proto_tree_add_item(tree, proto_egd, tvb, 0, -1, ENC_NA);
egd_tree = proto_item_add_subtree(ti, ett_egd);
proto_tree_add_item(egd_tree, hf_egd_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(egd_tree, hf_egd_ver, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(egd_tree, hf_egd_rid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(egd_tree, hf_egd_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(egd_tree, hf_egd_exid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
sectime = tvb_get_letohl(tvb, offset);
if (0 == sectime)
{
notime = proto_tree_add_item(egd_tree, hf_egd_notime, tvb, offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(notime, "--No TimeStamp");
}
else
{
egd_time.secs = tvb_get_letohl(tvb, offset);
egd_time.nsecs = tvb_get_letohl(tvb, offset+4);
proto_tree_add_time(egd_tree, hf_egd_time, tvb, offset, 8, &egd_time);
}
offset += 8;
proto_tree_add_item(egd_tree, hf_egd_stat, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(egd_tree, hf_egd_csig, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(egd_tree, hf_egd_resv, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
data_length = tvb_reported_length_remaining(tvb, offset);
if (data_length > 0)
{
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, egd_tree);
}
}
return tvb_captured_length(tvb);
}
void proto_register_egd(void)
{
static hf_register_info hf[] =
{
{ &hf_egd_ver,
{ "Version", "egd.ver",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_type,
{ "Type", "egd.type",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_rid,
{ "RequestID", "egd.rid",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_pid,
{ "ProducerID", "egd.pid",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_exid,
{ "ExchangeID", "egd.exid",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_time,
{ "Timestamp", "egd.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_notime,
{ "Timestamp", "egd.notime",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_stat,
{ "Status", "egd.stat",
FT_UINT32, BASE_DEC,
VALS(egd_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_egd_csig,
{ "ConfigSignature", "egd.csig",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_egd_resv,
{ "Reserved", "egd.rsrv",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] =
{
&ett_egd,
&ett_status_item
};
proto_egd = proto_register_protocol ("Ethernet Global Data", "EGD", "egd");
proto_register_field_array(proto_egd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_egd(void)
{
dissector_handle_t egd_handle;
egd_handle = create_dissector_handle(dissect_egd, proto_egd);
dissector_add_uint_with_preference("udp.port", EGD_PORT, egd_handle);
}
