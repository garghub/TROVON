static int
dissect_lge_monitor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint32 lge_monitor_proto_id;
tvbuff_t* next_tvb = NULL;
proto_tree* header_tree;
proto_item *ti;
proto_tree *lge_monitor_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LGE Monitor");
ti = proto_tree_add_item(tree, proto_lge_monitor, tvb, 0, LGEMON_PROTO_HEADER_LENGTH, ENC_NA);
lge_monitor_tree = proto_item_add_subtree(ti, ett_lge_monitor);
header_tree = proto_tree_add_subtree(lge_monitor_tree, tvb, offset, LGEMON_PROTO_HEADER_LENGTH, ett_lge_header, NULL, "LGE Monitor PDU");
proto_tree_add_item(header_tree, hf_lge_monitor_dir, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
lge_monitor_proto_id = tvb_get_ntohl(tvb,offset);
proto_tree_add_item(header_tree, hf_lge_monitor_prot, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(header_tree, hf_lge_monitor_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
switch (lge_monitor_proto_id){
case 0:
call_dissector(mtp3_handle, next_tvb, pinfo, tree);
break;
case 1:
call_dissector(sccp_handle, next_tvb, pinfo, tree);
break;
case 2:
call_dissector(sctp_handle, next_tvb, pinfo, tree);
break;
case 3:
call_dissector(m3ua_handle, next_tvb, pinfo, tree);
break;
default:
proto_tree_add_item(lge_monitor_tree, hf_lge_monitor_data, tvb, offset, -1, ENC_NA);
break;
}
return tvb_captured_length(tvb);
}
void
proto_reg_handoff_lge_monitor(void)
{
static dissector_handle_t lge_monitor_handle;
static guint saved_udp_port;
static gboolean lge_monitor_prefs_initialized = FALSE;
if (!lge_monitor_prefs_initialized) {
lge_monitor_handle = create_dissector_handle(dissect_lge_monitor, proto_lge_monitor);
dissector_add_for_decode_as("udp.port", lge_monitor_handle);
mtp3_handle = find_dissector_add_dependency("mtp3", proto_lge_monitor);
m3ua_handle = find_dissector_add_dependency("m3ua", proto_lge_monitor);
sccp_handle = find_dissector_add_dependency("sccp", proto_lge_monitor);
sctp_handle = find_dissector_add_dependency("sctp", proto_lge_monitor);
lge_monitor_prefs_initialized = TRUE;
}
else {
if (saved_udp_port != 0) {
dissector_delete_uint("udp.port", saved_udp_port, lge_monitor_handle);
}
}
if (LGEMonitorUDPPort != 0) {
dissector_add_uint("udp.port", LGEMonitorUDPPort, lge_monitor_handle);
}
saved_udp_port = LGEMonitorUDPPort;
}
void
proto_register_lge_monitor(void)
{
module_t *lge_monitor_module;
static hf_register_info hf[] = {
{ &hf_lge_monitor_dir,
{ "Direction", "lge_monitor.dir",
FT_UINT32, BASE_DEC, VALS(lge_monitor_dir_vals), 0x0,
NULL, HFILL }
},
{ &hf_lge_monitor_prot,
{ "Protocol Identifier", "lge_monitor.prot",
FT_UINT32, BASE_DEC, VALS(lge_monitor_prot_vals), 0x0,
NULL, HFILL }
},
{ &hf_lge_monitor_length,
{ "Payload Length", "lge_monitor.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_lge_monitor_data,
{ "LGE Monitor data", "lge_monitor.monitor_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_lge_monitor,
&ett_lge_header
};
proto_lge_monitor = proto_register_protocol("LGE Monitor","LGE_Monitor", "lge_monitor");
proto_register_field_array(proto_lge_monitor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
lge_monitor_module = prefs_register_protocol(proto_lge_monitor, proto_reg_handoff_lge_monitor);
prefs_register_uint_preference(lge_monitor_module, "udp.port",
"LGE Monitor UDP Port",
"Set UDP port for LGE Monitor messages",
10,
&LGEMonitorUDPPort);
}
