void
capture_vlan(const guchar *pd, int offset, int len, packet_counts *ld ) {
guint16 encap_proto;
if ( !BYTES_ARE_IN_FRAME(offset,len,5) ) {
ld->other++;
return;
}
encap_proto = pntohs( &pd[offset+2] );
if ( encap_proto <= IEEE_802_3_MAX_LEN) {
if ( pd[offset+4] == 0xff && pd[offset+5] == 0xff ) {
capture_ipx(ld);
} else {
capture_llc(pd,offset+4,len,ld);
}
} else {
capture_ethertype(encap_proto, pd, offset+4, len, ld);
}
}
static void
dissect_vlan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
guint16 tci;
volatile guint16 encap_proto;
volatile gboolean is_802_2;
proto_tree *volatile vlan_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VLAN");
col_clear(pinfo->cinfo, COL_INFO);
tci = tvb_get_ntohs( tvb, 0 );
col_add_fstr(pinfo->cinfo, COL_INFO, "PRI: %u CFI: %u ID: %u",
(tci >> 13), ((tci >> 12) & 1), (tci & 0xFFF));
col_add_fstr(pinfo->cinfo, COL_8021Q_VLAN_ID, "%u", (tci & 0xFFF));
vlan_tree = NULL;
if (tree) {
ti = proto_tree_add_item(tree, proto_vlan, tvb, 0, 4, ENC_NA);
if (vlan_summary_in_tree) {
proto_item_append_text(ti, ", PRI: %u, CFI: %u, ID: %u",
(tci >> 13), ((tci >> 12) & 1), (tci & 0xFFF));
}
vlan_tree = proto_item_add_subtree(ti, ett_vlan);
proto_tree_add_item(vlan_tree, hf_vlan_priority, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(vlan_tree, hf_vlan_cfi, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(vlan_tree, hf_vlan_id, tvb, 0, 2, ENC_BIG_ENDIAN);
}
encap_proto = tvb_get_ntohs(tvb, 2);
if (encap_proto <= IEEE_802_3_MAX_LEN) {
is_802_2 = TRUE;
if (tvb_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff) {
is_802_2 = FALSE;
}
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, vlan_tree,
hf_vlan_len, hf_vlan_trailer, 0);
} else {
ethertype(encap_proto, tvb, 4, pinfo, tree, vlan_tree,
hf_vlan_etype, hf_vlan_trailer, 0);
}
}
void
proto_register_vlan(void)
{
static hf_register_info hf[] = {
{ &hf_vlan_priority, {
"Priority", "vlan.priority", FT_UINT16, BASE_DEC,
VALS(pri_vals), 0xE000, "Descriptions are recommendations from IEEE standard 802.1D-2004", HFILL }},
{ &hf_vlan_cfi, {
"CFI", "vlan.cfi", FT_UINT16, BASE_DEC,
VALS(cfi_vals), 0x1000, "Canonical Format Identifier", HFILL }},
{ &hf_vlan_id, {
"ID", "vlan.id", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, "VLAN ID", HFILL }},
{ &hf_vlan_etype, {
"Type", "vlan.etype", FT_UINT16, BASE_HEX,
VALS(etype_vals), 0x0, "Ethertype", HFILL }},
{ &hf_vlan_len, {
"Length", "vlan.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_vlan_trailer, {
"Trailer", "vlan.trailer", FT_BYTES, BASE_NONE,
NULL, 0x0, "VLAN Trailer", HFILL }}
};
static gint *ett[] = {
&ett_vlan
};
module_t *vlan_module;
proto_vlan = proto_register_protocol("802.1Q Virtual LAN", "VLAN", "vlan");
proto_register_field_array(proto_vlan, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
vlan_module = prefs_register_protocol(proto_vlan, proto_reg_handoff_vlan);
prefs_register_bool_preference(vlan_module, "summary_in_tree",
"Show vlan summary in protocol tree",
"Whether the vlan summary line should be shown in the protocol tree",
&vlan_summary_in_tree);
prefs_register_uint_preference(vlan_module, "qinq_ethertype",
"802.1QinQ Ethertype (in hex)",
"The (hexadecimal) Ethertype used to indicate 802.1QinQ VLAN in VLAN tunneling.",
16, &q_in_q_ethertype);
}
void
proto_reg_handoff_vlan(void)
{
static gboolean prefs_initialized = FALSE;
static dissector_handle_t vlan_handle;
static unsigned int old_q_in_q_ethertype;
if (!prefs_initialized)
{
vlan_handle = create_dissector_handle(dissect_vlan, proto_vlan);
dissector_add_uint("ethertype", ETHERTYPE_VLAN, vlan_handle);
prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("ethertype", old_q_in_q_ethertype, vlan_handle);
}
old_q_in_q_ethertype = q_in_q_ethertype;
dissector_add_uint("ethertype", q_in_q_ethertype, vlan_handle);
}
