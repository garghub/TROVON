void
capture_fr(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint8 fr_octet;
guint32 addr;
guint8 fr_ctrl;
guint8 fr_nlpid;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_octet = pd[offset];
if (fr_octet & FRELAY_EA) {
ld->other++;
return;
}
addr = (fr_octet & FRELAY_UPPER_DLCI) >> 2;
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_octet = pd[offset];
addr = (addr << 4) | ((fr_octet & FRELAY_SECOND_DLCI) >> 4);
offset++;
if (!(fr_octet & FRELAY_EA)) {
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_octet = pd[offset];
if (!(fr_octet & FRELAY_EA)) {
addr = (addr << 7) | ((fr_octet & FRELAY_THIRD_DLCI) >> 1);
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_octet = pd[offset];
while (!(fr_octet & FRELAY_EA)) {
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_octet = pd[offset];
}
}
if (fr_octet & FRELAY_DC) {
} else {
addr = (addr << 6) | ((fr_octet & FRELAY_LOWER_DLCI) >> 2);
}
}
switch (fr_encap) {
case FRF_3_2:
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_ctrl = pd[offset];
if (fr_ctrl == XDLC_U) {
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_nlpid = pd[offset];
if (fr_nlpid == 0) {
offset++;
if (!BYTES_ARE_IN_FRAME(offset, len, 1)) {
ld->other++;
return;
}
fr_nlpid = pd[offset];
}
offset++;
switch (fr_nlpid) {
case NLPID_IP:
capture_ip(pd, offset, len, ld);
break;
case NLPID_IP6:
capture_ipv6(pd, offset, len, ld);
break;
case NLPID_PPP:
capture_ppp_hdlc(pd, offset, len, ld);
break;
case NLPID_SNAP:
capture_snap(pd, offset, len, ld);
break;
default:
ld->other++;
break;
}
} else {
if (addr == 0) {
ld->other++;
return;
}
if (fr_ctrl == (XDLC_U|XDLC_XID)) {
ld->other++;
return;
}
capture_chdlc(pd, offset, len, ld);
}
break;
case GPRS_NS:
ld->other++;
break;
case RAW_ETHER:
if (addr != 0)
capture_eth(pd, offset, len, ld);
else
ld->other++;
break;
}
}
static void
dissect_fr_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean has_direction, gboolean decode_address )
{
int offset = 0;
proto_item *ti = NULL;
proto_tree *fr_tree = NULL;
proto_tree *octet_tree = NULL;
guint8 fr_octet;
int is_response = FALSE;
guint32 addr = 0;
guint8 fr_ctrl;
guint16 fr_type;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FR");
col_clear(pinfo->cinfo, COL_INFO);
if (has_direction) {
if (pinfo->pseudo_header->x25.flags & FROM_DCE) {
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DTE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DCE");
} else {
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DCE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DTE");
}
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_fr, tvb, 0, -1, "Frame Relay");
fr_tree = proto_item_add_subtree(ti, ett_fr);
}
if (decode_address)
{
fr_octet = tvb_get_guint8(tvb, offset);
if (fr_octet & FRELAY_EA) {
addr = 0;
proto_tree_add_expert_format(fr_tree, pinfo, &ei_fr_bogus_address, tvb, offset, 1,
"Bogus 1-octet address field");
offset++;
} else {
static const int *first_address_bits[] = {&hf_fr_upper_dlci, &hf_fr_cr, &hf_fr_ea, NULL};
static const int *second_address_bits[] = {&hf_fr_second_dlci, &hf_fr_fecn,
&hf_fr_becn, &hf_fr_de, &hf_fr_ea, NULL};
static const int *third_address_bits[] = {&hf_fr_third_dlci, &hf_fr_ea, NULL};
addr = (fr_octet & FRELAY_UPPER_DLCI) >> 2;
is_response = (fr_octet & FRELAY_CR);
proto_tree_add_bitmask(fr_tree, tvb, offset, hf_fr_first_addr_octet,
ett_fr_address, first_address_bits, ENC_NA);
offset++;
fr_octet = tvb_get_guint8(tvb, offset);
addr = (addr << 4) | ((fr_octet & FRELAY_SECOND_DLCI) >> 4);
proto_tree_add_bitmask(fr_tree, tvb, offset, hf_fr_second_addr_octet,
ett_fr_address, second_address_bits, ENC_NA);
offset++;
if (!(fr_octet & FRELAY_EA)) {
fr_octet = tvb_get_guint8(tvb, offset);
if (!(fr_octet & FRELAY_EA)) {
addr = (addr << 7) | ((fr_octet & FRELAY_THIRD_DLCI) >> 1);
proto_tree_add_bitmask(fr_tree, tvb, offset, hf_fr_third_addr_octet,
ett_fr_address, third_address_bits, ENC_NA);
offset++;
fr_octet = tvb_get_guint8(tvb, offset);
while (!(fr_octet & FRELAY_EA)) {
proto_tree_add_expert_format(fr_tree, pinfo, &ei_fr_bogus_address, tvb, offset, 1,
"Bogus extra address octet");
offset++;
fr_octet = tvb_get_guint8(tvb, offset);
}
}
octet_tree = proto_tree_add_subtree_format(fr_tree, tvb, offset, 1,
ett_fr_address, NULL, "Final address octet: 0x%02x",
fr_octet);
if (fr_octet & FRELAY_DC) {
proto_tree_add_uint(octet_tree, hf_fr_dlcore_control, tvb, offset, 1, fr_octet);
} else {
addr = (addr << 6) | ((fr_octet & FRELAY_LOWER_DLCI) >> 2);
proto_tree_add_uint(octet_tree, hf_fr_lower_dlci, tvb, offset, 1, fr_octet);
}
proto_tree_add_boolean(octet_tree, hf_fr_dc, tvb, offset, 1, fr_octet);
proto_tree_add_boolean(octet_tree, hf_fr_ea, tvb, offset, 1, fr_octet);
offset++;
}
}
if (tree) {
proto_tree_add_uint(fr_tree, hf_fr_dlci, tvb, 0, offset, addr);
}
pinfo->ctype = CT_DLCI;
pinfo->circuit_id = addr;
col_add_fstr(pinfo->cinfo, COL_INFO, "DLCI %u", addr);
}
switch (fr_encap) {
case FRF_3_2:
fr_ctrl = tvb_get_guint8(tvb, offset);
if (fr_ctrl == XDLC_U) {
dissect_xdlc_control(tvb, offset, pinfo, fr_tree, hf_fr_control,
ett_fr_control, &fr_cf_items, &fr_cf_items_ext,
NULL, NULL, is_response, TRUE, TRUE);
offset++;
dissect_fr_nlpid(tvb, offset, pinfo, tree, ti, fr_tree, fr_ctrl);
} else {
if (addr == 0) {
dissect_xdlc_control(tvb, offset, pinfo, fr_tree,
hf_fr_control, ett_fr_control,
&fr_cf_items, &fr_cf_items_ext,
NULL, NULL, is_response, TRUE, TRUE);
dissect_lapf(tvb_new_subset_remaining(tvb,offset),pinfo,tree);
return;
}
if (fr_ctrl == (XDLC_U|XDLC_XID)) {
dissect_xdlc_control(tvb, offset, pinfo, fr_tree,
hf_fr_control, ett_fr_control,
&fr_cf_items, &fr_cf_items_ext,
NULL, NULL, is_response, TRUE, TRUE);
dissect_fr_xid(tvb_new_subset_remaining(tvb,offset),pinfo,tree);
return;
}
fr_type = tvb_get_ntohs(tvb, offset);
if (ti != NULL) {
proto_item_set_end(ti, tvb, offset+2);
}
chdlctype(fr_type, tvb, offset+2, pinfo, tree, fr_tree, hf_fr_chdlctype);
}
break;
case GPRS_NS:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(gprs_ns_handle, next_tvb, pinfo, tree);
break;
case RAW_ETHER:
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (addr != 0)
call_dissector(eth_withfcs_handle, next_tvb, pinfo, tree);
else
dissect_lapf(next_tvb, pinfo, tree);
break;
}
}
static void
dissect_fr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_fr_common(tvb, pinfo, tree, FALSE, TRUE );
}
static void
dissect_fr_phdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_fr_common(tvb, pinfo, tree, TRUE, TRUE );
}
static void
dissect_fr_stripped_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_fr_common(tvb, pinfo, tree, TRUE, FALSE );
}
static void
dissect_fr_uncompressed(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
proto_item *ti;
proto_tree *fr_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FR");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_protocol_format(tree, proto_fr, tvb, 0, -1, "Frame Relay");
fr_tree = proto_item_add_subtree(ti, ett_fr);
dissect_fr_nlpid(tvb, 0, pinfo, tree, ti, fr_tree, XDLC_U);
}
static void
dissect_fr_nlpid(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_item *ti,
proto_tree *fr_tree, guint8 fr_ctrl)
{
guint8 fr_nlpid;
tvbuff_t *next_tvb;
proto_item_set_end(ti, tvb, offset);
fr_nlpid = tvb_get_guint8 (tvb,offset);
if (fr_nlpid == 0) {
proto_tree_add_uint_format(fr_tree, hf_fr_nlpid, tvb, offset, 1, fr_nlpid, "Padding");
offset++;
if (ti != NULL) {
proto_item_set_end(ti, tvb, offset);
}
fr_nlpid=tvb_get_guint8( tvb,offset);
}
next_tvb = tvb_new_subset_remaining(tvb,offset);
if (dissector_try_uint(osinl_incl_subdissector_table, fr_nlpid, next_tvb,
pinfo, tree) ||
dissector_try_uint(fr_osinl_subdissector_table, fr_nlpid, next_tvb,
pinfo, tree)) {
if (tree) {
proto_item *hidden_item;
hidden_item = proto_tree_add_uint(fr_tree, hf_fr_nlpid,
tvb, offset, 1, fr_nlpid );
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
return;
}
if (tree)
proto_tree_add_uint(fr_tree, hf_fr_nlpid, tvb, offset, 1, fr_nlpid );
offset++;
switch (fr_nlpid) {
case NLPID_SNAP:
if (ti != NULL) {
proto_item_set_end(ti, tvb, offset+5);
}
dissect_snap(tvb, offset, pinfo, tree, fr_tree, fr_ctrl,
hf_fr_oui, hf_fr_snaptype, hf_fr_pid, 0);
return;
default:
if (ti != NULL) {
proto_item_set_end(ti, tvb, offset);
}
next_tvb = tvb_new_subset_remaining(tvb,offset);
if (!dissector_try_uint(fr_subdissector_table,fr_nlpid,
next_tvb, pinfo, tree))
call_dissector(data_handle,next_tvb, pinfo, tree);
break;
}
}
static void
dissect_lapf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree_add_expert(tree, pinfo, &ei_fr_frame_relay_lapf, tvb, 0, 0);
call_dissector(data_handle,tvb_new_subset_remaining(tvb,0),pinfo,tree);
}
static void
dissect_fr_xid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree_add_expert(tree, pinfo, &ei_fr_frame_relay_xid, tvb, 0, 0);
call_dissector(data_handle,tvb_new_subset_remaining(tvb,0),pinfo,tree);
}
void
proto_register_fr(void)
{
static hf_register_info hf[] = {
{ &hf_fr_ea,
{ "EA", "fr.ea",
FT_BOOLEAN, 8, TFS(&ea_string), FRELAY_EA,
"Extended Address", HFILL }},
{ &hf_fr_upper_dlci,
{ "Upper DLCI", "fr.upper_dlci",
FT_UINT8, BASE_HEX, NULL, FRELAY_UPPER_DLCI,
"Upper bits of DLCI", HFILL }},
{ &hf_fr_cr,
{ "CR", "fr.cr",
FT_BOOLEAN, 8, TFS(&tfs_command_response), FRELAY_CR,
"Command/Response", HFILL }},
{ &hf_fr_second_dlci,
{ "Second DLCI", "fr.second_dlci",
FT_UINT8, BASE_HEX, NULL, FRELAY_SECOND_DLCI,
"Bits below upper bits of DLCI", HFILL }},
{ &hf_fr_fecn,
{ "FECN", "fr.fecn",
FT_BOOLEAN, 8, NULL, FRELAY_FECN,
"Forward Explicit Congestion Notification", HFILL }},
{ &hf_fr_becn,
{ "BECN", "fr.becn",
FT_BOOLEAN, 8, NULL, FRELAY_BECN,
"Backward Explicit Congestion Notification", HFILL }},
{ &hf_fr_de,
{ "DE", "fr.de",
FT_BOOLEAN, 8, NULL, FRELAY_DE,
"Discard Eligibility", HFILL }},
{ &hf_fr_third_dlci,
{ "Third DLCI", "fr.third_dlci",
FT_UINT8, BASE_HEX, NULL, FRELAY_THIRD_DLCI,
"Additional bits of DLCI", HFILL }},
{ &hf_fr_dlcore_control,
{ "DL-CORE Control", "fr.dlcore_control",
FT_UINT8, BASE_HEX, NULL, FRELAY_LOWER_DLCI,
"DL-Core control bits", HFILL }},
{ &hf_fr_lower_dlci,
{ "Lower DLCI", "fr.lower_dlci",
FT_UINT8, BASE_HEX, NULL, FRELAY_LOWER_DLCI,
"Lower bits of DLCI", HFILL }},
{ &hf_fr_dc,
{ "DC", "fr.dc",
FT_BOOLEAN, 16, TFS(&ctrl_string), FRELAY_CR,
"Address/Control", HFILL }},
{ &hf_fr_dlci,
{ "DLCI", "fr.dlci",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Data-Link Connection Identifier", HFILL }},
{ &hf_fr_control,
{ "Control Field", "fr.control",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fr_n_r,
{ "N(R)", "fr.control.n_r",
FT_UINT16, BASE_DEC, NULL, XDLC_N_R_EXT_MASK,
NULL, HFILL }},
{ &hf_fr_n_s,
{ "N(S)", "fr.control.n_s",
FT_UINT16, BASE_DEC, NULL, XDLC_N_S_EXT_MASK,
NULL, HFILL }},
{ &hf_fr_p,
{ "Poll", "fr.control.p",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), XDLC_P_F,
NULL, HFILL }},
{ &hf_fr_p_ext,
{ "Poll", "fr.control.p",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), XDLC_P_F_EXT,
NULL, HFILL }},
{ &hf_fr_f,
{ "Final", "fr.control.f",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), XDLC_P_F,
NULL, HFILL }},
{ &hf_fr_f_ext,
{ "Final", "fr.control.f",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), XDLC_P_F_EXT,
NULL, HFILL }},
{ &hf_fr_s_ftype,
{ "Supervisory frame type", "fr.control.s_ftype",
FT_UINT16, BASE_HEX, VALS(stype_vals), XDLC_S_FTYPE_MASK,
NULL, HFILL }},
{ &hf_fr_u_modifier_cmd,
{ "Command", "fr.control.u_modifier_cmd",
FT_UINT8, BASE_HEX, VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK,
NULL, HFILL }},
{ &hf_fr_u_modifier_resp,
{ "Response", "fr.control.u_modifier_resp",
FT_UINT8, BASE_HEX, VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK,
NULL, HFILL }},
{ &hf_fr_ftype_i,
{ "Frame type", "fr.control.ftype",
FT_UINT16, BASE_HEX, VALS(ftype_vals), XDLC_I_MASK,
NULL, HFILL }},
{ &hf_fr_ftype_s_u,
{ "Frame type", "fr.control.ftype",
FT_UINT8, BASE_HEX, VALS(ftype_vals), XDLC_S_U_MASK,
NULL, HFILL }},
{ &hf_fr_ftype_s_u_ext,
{ "Frame type", "fr.control.ftype",
FT_UINT16, BASE_HEX, VALS(ftype_vals), XDLC_S_U_MASK,
NULL, HFILL }},
{ &hf_fr_nlpid,
{ "NLPID", "fr.nlpid",
FT_UINT8, BASE_HEX, VALS(fr_nlpid_vals), 0x0,
"Frame Relay Encapsulated Protocol NLPID", HFILL }},
{ &hf_fr_oui,
{ "Organization Code", "fr.snap.oui",
FT_UINT24, BASE_HEX, VALS(oui_vals), 0x0,
NULL, HFILL }},
{ &hf_fr_pid,
{ "Protocol ID", "fr.snap.pid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fr_snaptype,
{ "Type", "fr.snaptype",
FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
"Frame Relay SNAP Encapsulated Protocol", HFILL }},
{ &hf_fr_chdlctype,
{ "Type", "fr.chdlctype",
FT_UINT16, BASE_HEX, VALS(chdlc_vals), 0x0,
"Frame Relay Cisco HDLC Encapsulated Protocol", HFILL }},
{ &hf_fr_first_addr_octet,
{ "First address octet", "fr.first_addr_octet",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fr_second_addr_octet,
{ "Second address octet", "fr.second_addr_octet",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_fr_third_addr_octet,
{ "Third address octet", "fr.third_addr_octet",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_fr,
&ett_fr_address,
&ett_fr_control,
};
static ei_register_info ei[] = {
{ &ei_fr_bogus_address, { "fr.bogus_address", PI_PROTOCOL, PI_WARN, "Bogus address", EXPFILL }},
{ &ei_fr_frame_relay_lapf, { "fr.frame_relay.lapf", PI_UNDECODED, PI_WARN, "Frame relay lapf not yet implemented", EXPFILL }},
{ &ei_fr_frame_relay_xid, { "fr.frame_relay.xid", PI_UNDECODED, PI_WARN, "Frame relay xid not yet implemented", EXPFILL }},
};
static const enum_val_t fr_encap_options[] = {
{ "frf-3.2", "FRF 3.2/Cisco HDLC", FRF_3_2 },
{ "gprs-ns", "GPRS Network Service", GPRS_NS },
{ "ethernet", "Raw Ethernet", RAW_ETHER },
{ NULL, NULL, 0 },
};
module_t *frencap_module;
expert_module_t* expert_fr;
proto_fr = proto_register_protocol("Frame Relay", "FR", "fr");
proto_register_field_array(proto_fr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fr = expert_register_protocol(proto_fr);
expert_register_field_array(expert_fr, ei, array_length(ei));
fr_subdissector_table = register_dissector_table("fr.nlpid",
"Frame Relay NLPID", FT_UINT8, BASE_HEX);
fr_osinl_subdissector_table = register_dissector_table("fr.osinl",
"Frame Relay OSI NLPID", FT_UINT8, BASE_HEX);
register_dissector("fr_uncompressed", dissect_fr_uncompressed, proto_fr);
register_dissector("fr", dissect_fr, proto_fr);
register_dissector("fr_stripped_address", dissect_fr_stripped_address, proto_fr);
frencap_module = prefs_register_protocol(proto_fr, NULL);
prefs_register_enum_preference(frencap_module, "encap", "Encapsulation",
"Encapsulation", &fr_encap,
fr_encap_options, FALSE);
}
void
proto_reg_handoff_fr(void)
{
dissector_handle_t fr_handle, fr_phdr_handle;
fr_handle = find_dissector("fr");
dissector_add_uint("gre.proto", ETHERTYPE_RAW_FR, fr_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_FRELAY, fr_handle);
fr_phdr_handle = create_dissector_handle(dissect_fr_phdr, proto_fr);
dissector_add_uint("wtap_encap", WTAP_ENCAP_FRELAY_WITH_PHDR, fr_phdr_handle);
eth_withfcs_handle = find_dissector("eth_withfcs");
gprs_ns_handle = find_dissector("gprs_ns");
data_handle = find_dissector("data");
osinl_incl_subdissector_table = find_dissector_table("osinl.incl");
}
