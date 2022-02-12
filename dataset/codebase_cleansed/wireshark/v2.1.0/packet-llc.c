static void
llc_sap_value( gchar *result, guint32 sap )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%s", val_to_str_const(sap<<1, sap_vals, "Unknown"));
}
void
llc_add_oui(guint32 oui, const char *table_name, const char *table_ui_name,
hf_register_info *hf_item, const int proto)
{
oui_info_t *new_info;
new_info = (oui_info_t *)g_malloc(sizeof (oui_info_t));
new_info->table = register_dissector_table(table_name,
table_ui_name, proto, FT_UINT16, BASE_HEX, DISSECTOR_TABLE_ALLOW_DUPLICATE);
new_info->field_info = hf_item;
if (oui_info_table == NULL) {
oui_info_table = g_hash_table_new(g_direct_hash,
g_direct_equal);
}
g_hash_table_insert(oui_info_table, GUINT_TO_POINTER(oui), new_info);
}
gboolean
capture_llc(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_) {
int is_snap;
guint16 control;
int llc_header_len;
if (!BYTES_ARE_IN_FRAME(offset, len, 2))
return FALSE;
is_snap = (pd[offset] == SAP_SNAP) && (pd[offset+1] == SAP_SNAP);
llc_header_len = 2;
control = get_xdlc_control(pd, offset+2, pd[offset+1] & SSAP_CR_BIT);
llc_header_len += XDLC_CONTROL_LEN(control, TRUE);
if (!BYTES_ARE_IN_FRAME(offset, len, llc_header_len))
return FALSE;
if (!XDLC_IS_INFORMATION(control))
return FALSE;
if (is_snap)
return capture_snap(pd, offset+llc_header_len, len, cpinfo, pseudo_header);
return try_capture_dissector("llc.dsap", pd[offset], pd, offset + llc_header_len, len, cpinfo, pseudo_header);
}
gboolean
capture_snap(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
guint32 oui;
guint16 etype;
if (!BYTES_ARE_IN_FRAME(offset, len, 5))
return FALSE;
oui = pd[offset] << 16 | pd[offset+1] << 8 | pd[offset+2];
etype = pntoh16(&pd[offset+3]);
switch (oui) {
case OUI_ENCAP_ETHER:
case OUI_CISCO_90:
case OUI_APPLE_ATALK:
return try_capture_dissector("ethertype", etype, pd, offset+5, len, cpinfo, pseudo_header);
case OUI_CISCO:
return try_capture_dissector("ethertype", etype, pd, offset+5, len, cpinfo, pseudo_header);
case OUI_MARVELL:
return try_capture_dissector("ethertype", etype, pd, offset+5+5, len, cpinfo, pseudo_header);
}
return FALSE;
}
static int
dissect_basicxid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *xid_tree = NULL;
proto_item *ti = NULL;
guint8 format, types, wsize;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "XID");
col_clear(pinfo->cinfo, COL_INFO);
format = tvb_get_guint8(tvb, 0);
ti = proto_tree_add_item(tree, proto_basicxid, tvb, 0, -1, ENC_NA);
xid_tree = proto_item_add_subtree(ti, ett_llc_basicxid);
proto_tree_add_uint(xid_tree, hf_llc_xid_format, tvb, 0, 1, format);
col_append_str(pinfo->cinfo, COL_INFO, "Basic Format");
types = tvb_get_guint8(tvb, 1);
proto_tree_add_uint(xid_tree, hf_llc_xid_types, tvb, 1,
1, types & TYPES_MASK);
col_append_fstr(pinfo->cinfo, COL_INFO,
"; %s", val_to_str(types & TYPES_MASK, type_vals, "0x%02x")
);
wsize = tvb_get_guint8(tvb, 2);
proto_tree_add_uint(xid_tree, hf_llc_xid_wsize, tvb, 2,
1, (wsize & 0xFE) >> 1);
col_append_fstr(pinfo->cinfo, COL_INFO,
"; Window Size %d", (wsize & 0xFE) >> 1);
return tvb_captured_length(tvb);
}
static int
dissect_llc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *llc_tree;
proto_tree *field_tree;
proto_item *ti, *sap_item;
int is_snap;
guint16 control;
int llc_header_len;
guint8 dsap, ssap, format;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLC");
col_clear(pinfo->cinfo, COL_INFO);
dsap = tvb_get_guint8(tvb, 0);
ti = proto_tree_add_item(tree, proto_llc, tvb, 0, -1, ENC_NA);
llc_tree = proto_item_add_subtree(ti, ett_llc);
sap_item = proto_tree_add_item(llc_tree, hf_llc_dsap, tvb, 0, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(sap_item, ett_llc_dsap);
proto_tree_add_item(field_tree, hf_llc_dsap_sap, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_llc_dsap_ig, tvb, 0, 1, ENC_NA);
ssap = tvb_get_guint8(tvb, 1);
sap_item = proto_tree_add_item(llc_tree, hf_llc_ssap, tvb, 1, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(sap_item, ett_llc_ssap);
proto_tree_add_item(field_tree, hf_llc_ssap_sap, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_llc_ssap_cr, tvb, 1, 1, ENC_NA);
is_snap = (dsap == SAP_SNAP) && (ssap == SAP_SNAP);
llc_header_len = 2;
control = dissect_xdlc_control(tvb, 2, pinfo, llc_tree,
hf_llc_ctrl, ett_llc_ctrl,
&llc_cf_items, &llc_cf_items_ext,
NULL, NULL, ssap & SSAP_CR_BIT, TRUE, FALSE);
llc_header_len += XDLC_CONTROL_LEN(control, TRUE);
if (is_snap)
llc_header_len += 5;
if (tree)
proto_item_set_len(ti, llc_header_len);
if (is_snap) {
dissect_snap(tvb, 2+XDLC_CONTROL_LEN(control, TRUE), pinfo, tree, llc_tree, control,
hf_llc_oui, hf_llc_type, hf_llc_pid, 2);
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO,
"; DSAP %s %s, SSAP %s %s",
val_to_str(dsap & SAP_MASK, sap_vals, "0x%02x"),
dsap & DSAP_GI_BIT ?
"Group" : "Individual",
val_to_str(ssap & SAP_MASK, sap_vals, "0x%02x"),
ssap & SSAP_CR_BIT ?
"Response" : "Command"
);
if (tvb_reported_length_remaining(tvb, llc_header_len) > 0) {
next_tvb = tvb_new_subset_remaining(tvb, llc_header_len);
if (XDLC_IS_INFORMATION(control)) {
if (!dissector_try_uint(dsap_subdissector_table,
dsap, next_tvb, pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
} else if ((control & (XDLC_U_MODIFIER_MASK|XDLC_U))
== (XDLC_XID|XDLC_U)) {
format = tvb_get_guint8(next_tvb, 0);
if (format == 0x81) {
dissect_basicxid(next_tvb, pinfo, tree, data);
} else {
if (!dissector_try_uint(
xid_subdissector_table, dsap, next_tvb,
pinfo, tree)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
} else {
call_data_dissector(next_tvb, pinfo, tree);
}
}
}
return tvb_captured_length(tvb);
}
void
dissect_snap(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree,
proto_tree *snap_tree, int control, int hf_oui, int hf_type, int hf_pid,
int bridge_pad)
{
guint32 oui;
guint16 etype;
tvbuff_t *next_tvb;
oui_info_t *oui_info;
dissector_table_t subdissector_table;
int hf;
int mesh_header_len;
oui = tvb_get_ntoh24(tvb, offset);
etype = tvb_get_ntohs(tvb, offset+3);
col_append_fstr(pinfo->cinfo, COL_INFO,
"; SNAP, OUI 0x%06X (%s), PID 0x%04X",
oui, val_to_str_const(oui, oui_vals, "Unknown"), etype);
proto_tree_add_uint(snap_tree, hf_oui, tvb, offset, 3, oui);
switch (oui) {
case OUI_HP_2:
oui_info = get_snap_oui_info(oui);
hf = *oui_info->field_info->p_id;
proto_tree_add_uint(snap_tree, hf, tvb, offset+3, 2, etype);
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
if(!dissector_try_uint(hpteam_subdissector_table,etype, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
break;
case OUI_ENCAP_ETHER:
case OUI_CISCO_90:
case OUI_APPLE_ATALK:
if (XDLC_IS_INFORMATION(control)) {
if (tree) {
proto_tree_add_uint(snap_tree, hf_type,
tvb, offset+3, 2, etype);
}
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
if (!dissector_try_uint(ethertype_subdissector_table,
etype, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
call_data_dissector(next_tvb, pinfo, tree);
}
break;
case OUI_IEEE_802_1:
if (tree) {
proto_tree_add_uint(snap_tree, hf_pid, tvb, offset+3, 2,
etype);
}
switch (etype) {
case BPID_ETH_WITH_FCS:
next_tvb = tvb_new_subset_remaining(tvb, offset+5+bridge_pad);
call_dissector(eth_withfcs_handle, next_tvb, pinfo,
tree);
break;
case BPID_ETH_WITHOUT_FCS:
next_tvb = tvb_new_subset_remaining(tvb, offset+5+bridge_pad);
call_dissector(eth_withoutfcs_handle, next_tvb, pinfo, tree);
break;
case BPID_802_5_WITH_FCS:
case BPID_802_5_WITHOUT_FCS:
next_tvb = tvb_new_subset_remaining(tvb, offset+5+bridge_pad);
call_dissector(tr_handle, next_tvb, pinfo, tree);
break;
case BPID_FDDI_WITH_FCS:
case BPID_FDDI_WITHOUT_FCS:
next_tvb = tvb_new_subset_remaining(tvb, offset+5+1+bridge_pad);
call_dissector(fddi_handle, next_tvb, pinfo, tree);
break;
case BPID_BPDU:
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
call_dissector(bpdu_handle, next_tvb, pinfo, tree);
break;
default:
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
call_data_dissector(next_tvb, pinfo, tree);
break;
}
break;
case OUI_CABLE_BPDU:
if (tree) {
proto_tree_add_uint(snap_tree, hf_pid, tvb, offset+3, 2,
etype);
}
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
call_dissector(bpdu_handle, next_tvb, pinfo, tree);
break;
case OUI_TURBOCELL:
next_tvb = tvb_new_subset_remaining(tvb, offset+3);
call_dissector(turbo_handle, next_tvb, pinfo, tree);
break;
case OUI_MARVELL:
if (XDLC_IS_INFORMATION(control)) {
if (tree) {
proto_tree_add_uint(snap_tree, hf_type,
tvb, offset+3, 2, etype);
}
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
mesh_header_len = call_dissector(mesh_handle,
next_tvb, pinfo, tree);
next_tvb = tvb_new_subset_remaining(tvb, offset+5+mesh_header_len);
if (!dissector_try_uint(ethertype_subdissector_table,
etype, next_tvb, pinfo, tree))
call_data_dissector(next_tvb, pinfo, tree);
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
call_data_dissector(next_tvb, pinfo, tree);
}
break;
default:
oui_info = get_snap_oui_info(oui);
if (oui_info != NULL) {
hf = *oui_info->field_info->p_id;
subdissector_table = oui_info->table;
} else {
hf = hf_pid;
subdissector_table = NULL;
}
if (tree) {
proto_tree_add_uint(snap_tree, hf, tvb, offset+3, 2,
etype);
}
next_tvb = tvb_new_subset_remaining(tvb, offset+5);
if (XDLC_IS_INFORMATION(control)) {
if (subdissector_table != NULL) {
if (dissector_try_uint(subdissector_table,
etype, next_tvb, pinfo, tree))
break;
}
}
call_data_dissector(next_tvb, pinfo, tree);
break;
}
}
oui_info_t *
get_snap_oui_info(guint32 oui)
{
if (oui_info_table != NULL) {
return (oui_info_t *)g_hash_table_lookup(oui_info_table,
GUINT_TO_POINTER(oui));
} else
return NULL;
}
void
proto_register_llc(void)
{
static struct true_false_string ig_bit = { "Group", "Individual" };
static struct true_false_string cr_bit = { "Response", "Command" };
static hf_register_info hf[] = {
{ &hf_llc_dsap,
{ "DSAP", "llc.dsap", FT_UINT8, BASE_HEX,
VALS(sap_vals), 0x0, "Destination Service Access Point", HFILL }},
{ &hf_llc_dsap_sap,
{ "SAP", "llc.dsap.sap", FT_UINT8, BASE_CUSTOM,
CF_FUNC(llc_sap_value), 0xFE, "Service Access Point", HFILL }},
{ &hf_llc_dsap_ig,
{ "IG Bit", "llc.dsap.ig", FT_BOOLEAN, 8,
TFS(&ig_bit), DSAP_GI_BIT, "Individual/Group", HFILL }},
{ &hf_llc_ssap,
{ "SSAP", "llc.ssap", FT_UINT8, BASE_HEX,
VALS(sap_vals), 0x0, "Source Service Access Point", HFILL }},
{ &hf_llc_ssap_sap,
{ "SAP", "llc.ssap.sap", FT_UINT8, BASE_CUSTOM,
CF_FUNC(llc_sap_value), 0xFE, "Service Access Point", HFILL }},
{ &hf_llc_ssap_cr,
{ "CR Bit", "llc.ssap.cr", FT_BOOLEAN, 8,
TFS(&cr_bit), SSAP_CR_BIT, "Command/Response", HFILL }},
{ &hf_llc_ctrl,
{ "Control", "llc.control", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_llc_n_r,
{ "N(R)", "llc.control.n_r", FT_UINT16, BASE_DEC,
NULL, XDLC_N_R_EXT_MASK, NULL, HFILL }},
{ &hf_llc_n_s,
{ "N(S)", "llc.control.n_s", FT_UINT16, BASE_DEC,
NULL, XDLC_N_S_EXT_MASK, NULL, HFILL }},
{ &hf_llc_p,
{ "Poll", "llc.control.p", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_llc_p_ext,
{ "Poll", "llc.control.p", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), XDLC_P_F_EXT, NULL, HFILL }},
{ &hf_llc_f,
{ "Final", "llc.control.f", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_llc_f_ext,
{ "Final", "llc.control.f", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), XDLC_P_F_EXT, NULL, HFILL }},
{ &hf_llc_s_ftype,
{ "Supervisory frame type", "llc.control.s_ftype", FT_UINT16, BASE_HEX,
VALS(stype_vals), XDLC_S_FTYPE_MASK, NULL, HFILL }},
{ &hf_llc_u_modifier_cmd,
{ "Command", "llc.control.u_modifier_cmd", FT_UINT8, BASE_HEX,
VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_llc_u_modifier_resp,
{ "Response", "llc.control.u_modifier_resp", FT_UINT8, BASE_HEX,
VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_llc_ftype_i,
{ "Frame type", "llc.control.ftype", FT_UINT16, BASE_HEX,
VALS(ftype_vals), XDLC_I_MASK, NULL, HFILL }},
{ &hf_llc_ftype_s_u,
{ "Frame type", "llc.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
{ &hf_llc_ftype_s_u_ext,
{ "Frame type", "llc.control.ftype", FT_UINT16, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
{ &hf_llc_type,
{ "Type", "llc.type", FT_UINT16, BASE_HEX,
VALS(etype_vals), 0x0, NULL, HFILL }},
{ &hf_llc_oui,
{ "Organization Code", "llc.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }},
{ &hf_llc_pid,
{ "Protocol ID", "llc.pid", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_llc,
&ett_llc_dsap,
&ett_llc_ssap,
&ett_llc_ctrl,
};
proto_llc = proto_register_protocol("Logical-Link Control", "LLC", "llc");
proto_register_field_array(proto_llc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dsap_subdissector_table = register_dissector_table("llc.dsap",
"LLC SAP", proto_llc, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
xid_subdissector_table = register_dissector_table("llc.xid_dsap",
"LLC XID SAP", proto_llc, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
register_capture_dissector_table("llc.dsap", "LLC");
register_dissector("llc", dissect_llc, proto_llc);
}
void
proto_register_basicxid(void)
{
static hf_register_info hf[] = {
{ &hf_llc_xid_format,
{ "XID Format", "basicxid.llc.xid.format", FT_UINT8, BASE_HEX,
VALS(format_vals), 0x0, NULL, HFILL }},
{ &hf_llc_xid_types,
{ "LLC Types/Classes", "basicxid.llc.xid.types", FT_UINT8, BASE_HEX,
VALS(type_vals), 0x0, NULL, HFILL }},
{ &hf_llc_xid_wsize,
{ "Receive Window Size", "basicxid.llc.xid.wsize", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_llc_basicxid
};
proto_basicxid = proto_register_protocol("Logical-Link Control Basic Format XID", "Basic Format XID", "basicxid");
proto_register_field_array(proto_basicxid, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("basicxid", dissect_basicxid, proto_basicxid);
}
static void
register_hf(gpointer key _U_, gpointer value, gpointer user_data _U_)
{
oui_info_t *info = (oui_info_t *)value;
proto_register_field_array(proto_llc, info->field_info, 1);
}
void
proto_reg_handoff_llc(void)
{
dissector_handle_t llc_handle;
bpdu_handle = find_dissector_add_dependency("bpdu", proto_llc);
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_llc);
eth_withfcs_handle = find_dissector_add_dependency("eth_withfcs", proto_llc);
fddi_handle = find_dissector_add_dependency("fddi", proto_llc);
tr_handle = find_dissector_add_dependency("tr", proto_llc);
turbo_handle = find_dissector_add_dependency("turbocell", proto_llc);
mesh_handle = find_dissector_add_dependency("mesh", proto_llc);
ethertype_subdissector_table = find_dissector_table("ethertype");
hpteam_subdissector_table = find_dissector_table("llc.hpteam_pid");
llc_handle = find_dissector("llc");
dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_RFC1483, llc_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_802_2, llc_handle);
dissector_add_uint("ppp.protocol", PPP_LLC, llc_handle);
dissector_add_uint("udp.port", UDP_PORT_LLC1, llc_handle);
dissector_add_uint("udp.port", UDP_PORT_LLC2, llc_handle);
dissector_add_uint("udp.port", UDP_PORT_LLC3, llc_handle);
dissector_add_uint("udp.port", UDP_PORT_LLC4, llc_handle);
dissector_add_uint("udp.port", UDP_PORT_LLC5, llc_handle);
dissector_add_uint("fc.ftype", FC_FTYPE_IP, llc_handle);
dissector_add_uint("atm.aal5.type", TRAF_LLCMX, llc_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_BACNET, llc_handle);
dissector_add_uint("ethertype", ETHERTYPE_JUMBO_LLC, llc_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_LLC, llc_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_LLC_SNAP, llc_handle);
register_capture_dissector("ethertype", ETHERTYPE_JUMBO_LLC, capture_llc, proto_llc);
register_capture_dissector("atm.aal5.type", TRAF_LLCMX, capture_llc, proto_llc);
register_capture_dissector("sll.ltype", LINUX_SLL_P_802_2, capture_llc, proto_llc);
if (oui_info_table != NULL)
g_hash_table_foreach(oui_info_table, register_hf, NULL);
}
