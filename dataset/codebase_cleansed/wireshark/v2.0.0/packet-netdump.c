static void
dissect_netdump(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_reported_length(tvb) == 0)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netdump");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti = NULL;
proto_tree *netdump_tree = NULL;
ti = proto_tree_add_item(tree, proto_netdump, tvb, 0, -1, ENC_NA);
netdump_tree = proto_item_add_subtree(ti, ett_netdump);
if (tvb_reported_length(tvb) == 24) {
proto_tree_add_item(netdump_tree, hf_netdump_magic_number, tvb, 0, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_seq_nr, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_command, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_from, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_to, tvb, 20, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(netdump_tree, hf_netdump_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_seq_nr, tvb, 1, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_code, tvb, 5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_info, tvb, 9, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netdump_tree, hf_netdump_payload, tvb, 13, -1, ENC_NA);
}
}
}
void proto_register_netdump(void)
{
module_t *netdump_module;
static gint *ett[] = {
&ett_netdump
};
static hf_register_info hf[] = {
{ &hf_netdump_magic_number,
{ "Netdump Magic Number", "netdump.magic",
FT_UINT64, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_netdump_seq_nr,
{"Netdump seq number", "netdump.seq_nr",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{ &hf_netdump_command,
{"Netdump command", "netdump.command",
FT_UINT32, BASE_DEC,
VALS(command_names), 0x0,
NULL, HFILL}
},
{ &hf_netdump_from,
{"Netdump from val", "netdump.from",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{ &hf_netdump_to,
{"Netdump to val", "netdump.to",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{ &hf_netdump_code,
{"Netdump code", "netdump.code",
FT_UINT32, BASE_DEC,
VALS(reply_code_names), 0x0,
NULL, HFILL}
},
{ &hf_netdump_info,
{"Netdump info", "netdump.info",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
},
{ &hf_netdump_payload,
{"Netdump payload", "netdump.payload",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL}
},
{ &hf_netdump_version,
{"Netdump version", "netdump.version",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL}
}
};
proto_netdump = proto_register_protocol (
"Netdump Protocol",
"Netdump",
"netdump"
);
proto_register_field_array(proto_netdump, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
netdump_module = prefs_register_protocol(proto_netdump,
proto_reg_handoff_netdump);
prefs_register_uint_preference(netdump_module, "udp.port",
"Netdump UDP port",
"port if other than the default",
10, &gPORT_PREF);
}
void proto_reg_handoff_netdump(void)
{
static gboolean initalized = FALSE;
static dissector_handle_t netdump_handle;
static int CurrentPort;
if (!initalized) {
netdump_handle = create_dissector_handle(dissect_netdump,
proto_netdump);
dissector_add_for_decode_as("udp.port", netdump_handle);
initalized = TRUE;
} else {
if (CurrentPort != 0)
dissector_delete_uint("udp.port", CurrentPort, netdump_handle);
}
CurrentPort = gPORT_PREF;
if (CurrentPort != 0)
dissector_add_uint("udp.port", CurrentPort, netdump_handle);
}
