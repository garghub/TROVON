void
capture_ieee8021ah(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint16 encap_proto;
if (!BYTES_ARE_IN_FRAME(offset, len, IEEE8021AH_LEN + 1)) {
ld->other++;
return;
}
encap_proto = pntoh16( &pd[offset + IEEE8021AH_LEN - 2] );
if (encap_proto <= IEEE_802_3_MAX_LEN) {
if ( pd[offset + IEEE8021AH_LEN] == 0xff
&& pd[offset + IEEE8021AH_LEN + 1] == 0xff ) {
capture_ipx(ld);
}
else {
capture_llc(pd, offset + IEEE8021AH_LEN,len,ld);
}
}
else {
capture_ethertype(encap_proto, pd, offset + IEEE8021AH_LEN, len, ld);
}
}
static
void
dissect_ieee8021ad(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
proto_tree *ptree = NULL;
proto_tree *tagtree = NULL;
guint32 tci, ctci;
guint16 encap_proto;
int proto_tree_index;
ethertype_data_t ethertype_data;
tvbuff_t *volatile next_tvb = NULL;
proto_tree *volatile ieee8021ad_tree;
proto_tree *volatile ieee8021ad_tag_tree;
proto_tree_index = proto_ieee8021ad;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "802.1ad");
col_clear(pinfo->cinfo, COL_INFO);
tci = tvb_get_ntohs( tvb, 0 );
col_add_fstr(pinfo->cinfo, COL_INFO,
"PRI: %d DROP: %d ID: %d",
(tci >> 13), ((tci >> 12) & 1), (tci & 0xFFF));
ieee8021ad_tree = NULL;
if (tree) {
ptree = proto_tree_add_item(tree, proto_tree_index, tvb, 0, IEEE8021AD_LEN, ENC_NA);
ieee8021ad_tree = proto_item_add_subtree(ptree, ett_ieee8021ad);
}
encap_proto = tvb_get_ntohs(tvb, IEEE8021AD_LEN - 2);
ethertype_data.fh_tree = ieee8021ad_tree;
ethertype_data.etype_id = hf_ieee8021ah_etype;
ethertype_data.trailer_id = hf_ieee8021ah_trailer;
ethertype_data.fcs_len = 0;
if (encap_proto == ETHERTYPE_IEEE_802_1AH) {
if (tree) {
tagtree = proto_tree_add_item(ptree, proto_tree_index, tvb, 0, 2, ENC_NA);
ieee8021ad_tag_tree = proto_item_add_subtree(tagtree, ett_ieee8021ad);
proto_tree_add_uint(ieee8021ad_tag_tree, hf_ieee8021ad_priority, tvb,
0, 1, tci);
proto_tree_add_uint(ieee8021ad_tag_tree, hf_ieee8021ad_cfi, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ad_tag_tree, hf_ieee8021ad_id, tvb, 0, 2, tci);
proto_item_set_text(ieee8021ad_tag_tree, "B-Tag, B-VID: %d", tci & 0x0FFF);
}
next_tvb = tvb_new_subset_remaining(tvb, IEEE8021AD_LEN);
if (ptree) {
proto_item_set_text(ptree, "IEEE 802.1ah, B-VID: %d", tci & 0x0FFF);
dissect_ieee8021ah_common(next_tvb, pinfo, ptree, tree, proto_tree_index);
}
else {
dissect_ieee8021ah_common(next_tvb, pinfo, tree, NULL, proto_tree_index);
}
return;
} else if (encap_proto == ETHERTYPE_IEEE_802_1AD) {
ctci = tvb_get_ntohs(tvb, IEEE8021AD_LEN);
if (tree) {
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_priority, tvb,
0, 1, tci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_cfi, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_svid, tvb, 0, 2, tci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_priority, tvb,
IEEE8021AD_LEN, 1, ctci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_cfi, tvb,
IEEE8021AD_LEN, 1, ctci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_cvid, tvb, IEEE8021AD_LEN,
2, ctci);
}
proto_item_set_text(ptree, "IEEE 802.1ad, S-VID: %d, C-VID: %d", tci & 0x0FFF,
ctci & 0x0FFF);
ethertype_data.etype = tvb_get_ntohs(tvb, IEEE8021AD_LEN * 2 - 2);
ethertype_data.offset_after_ethertype = IEEE8021AD_LEN * 2;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
} else {
if (tree) {
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_priority, tvb,
0, 1, tci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_cfi, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ad_tree, hf_ieee8021ad_id, tvb, 0, 2, tci);
}
proto_item_set_text(ptree, "IEEE 802.1ad, ID: %d", tci & 0x0FFF);
ethertype_data.etype = encap_proto;
ethertype_data.offset_after_ethertype = IEEE8021AD_LEN;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
}
}
void
dissect_ieee8021ah_common(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, proto_tree *parent, int tree_index) {
guint32 tci;
guint16 encap_proto;
proto_tree *ptree;
ethertype_data_t ethertype_data;
proto_tree *volatile ieee8021ah_tag_tree;
const guint8 *src_addr, *dst_addr;
tci = tvb_get_ntohl( tvb, 0 );
col_add_fstr(pinfo->cinfo, COL_INFO,
"PRI: %d Drop: %d NCA: %d Res1: %d Res2: %d I-SID: %d",
(tci >> 29), ((tci >> 28) & 1), ((tci >> 27) & 1),
((tci >> 26) & 1), ((tci >> 24) & 3), tci & IEEE8021AH_ISIDMASK);
ptree = NULL;
ieee8021ah_tag_tree = NULL;
if (tree) {
ptree = proto_tree_add_item(tree, tree_index, tvb, 0, 4, ENC_NA);
ieee8021ah_tag_tree = proto_item_add_subtree(ptree, ett_ieee8021ah);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_priority, tvb,
0, 1, tci);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_drop, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_nca, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_res1, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_res2, tvb, 0, 1, tci);
proto_tree_add_uint(ieee8021ah_tag_tree, hf_ieee8021ah_isid, tvb, 1, 3, tci);
proto_item_set_text(ieee8021ah_tag_tree, "I-Tag, I-SID: %d",
tci & IEEE8021AH_ISIDMASK);
tvb_ensure_bytes_exist(tvb, 4, 12);
dst_addr = tvb_get_ptr(tvb, 4, 6);
src_addr = tvb_get_ptr(tvb, 10, 6);
proto_tree_add_ether(tree, hf_ieee8021ah_c_daddr,
tvb, 4, 6, dst_addr);
proto_tree_add_ether(tree, hf_ieee8021ah_c_saddr,
tvb, 10, 6, src_addr);
if (parent) {
proto_item_append_text(tree, ", I-SID: %d, C-Src: %s (%s), C-Dst: %s (%s)",
tci & IEEE8021AH_ISIDMASK, get_ether_name(src_addr),
ether_to_str(src_addr), get_ether_name(dst_addr),
ether_to_str(dst_addr));
}
}
encap_proto = tvb_get_ntohs(tvb, IEEE8021AH_LEN - 2);
ethertype_data.etype = encap_proto;
ethertype_data.fh_tree = tree;
ethertype_data.offset_after_ethertype = IEEE8021AH_LEN;
ethertype_data.etype_id = hf_ieee8021ah_etype;
ethertype_data.trailer_id = hf_ieee8021ah_trailer;
ethertype_data.fcs_len = 0;
if (parent) {
call_dissector_with_data(ethertype_handle, tvb, pinfo, parent, &ethertype_data);
}
else {
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
}
}
static
void
dissect_ieee8021ah(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
proto_tree *ptree;
guint32 tci;
int proto_tree_index;
proto_tree *volatile ieee8021ah_tree;
proto_tree_index = proto_ieee8021ah;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "802.1ah");
col_clear(pinfo->cinfo, COL_INFO);
tci = tvb_get_ntohl( tvb, 0 );
col_add_fstr(pinfo->cinfo, COL_INFO,
"PRI: %d Drop: %d NCA: %d Res1: %d Res2: %d I-SID: %d",
(tci >> 29), ((tci >> 28) & 1), ((tci >> 27) & 1),
((tci >> 26) & 1), ((tci >> 24) & 3), (tci & 0x00FFFFFF));
ieee8021ah_tree = NULL;
if (tree) {
ptree = proto_tree_add_item(tree, proto_tree_index, tvb, 0, IEEE8021AH_LEN, ENC_NA);
ieee8021ah_tree = proto_item_add_subtree(ptree, ett_ieee8021ah);
dissect_ieee8021ah_common(tvb, pinfo, ieee8021ah_tree, tree, proto_tree_index);
}
}
void
proto_register_ieee8021ah(void)
{
static hf_register_info hf[] = {
{ &hf_ieee8021ah_priority, {
"Priority", "ieee8021ah.priority", FT_UINT32, BASE_DEC,
0, 0xE0000000, NULL, HFILL }},
{ &hf_ieee8021ah_drop, {
"DROP", "ieee8021ah.drop", FT_UINT32, BASE_DEC,
0, 0x10000000, NULL, HFILL }},
{ &hf_ieee8021ah_nca, {
"NCA", "ieee8021ah.nca", FT_UINT32, BASE_DEC,
0, 0x08000000, "No Customer Addresses", HFILL }},
{ &hf_ieee8021ah_res1, {
"RES1", "ieee8021ah.res1", FT_UINT32, BASE_DEC,
0, 0x04000000, "Reserved1", HFILL }},
{ &hf_ieee8021ah_res2, {
"RES2", "ieee8021ah.res2", FT_UINT32, BASE_DEC,
0, 0x03000000, "Reserved2", HFILL }},
{ &hf_ieee8021ah_isid, {
"I-SID", "ieee8021ah.isid", FT_UINT32, BASE_DEC,
0, 0x00FFFFFF, NULL, HFILL }},
{ &hf_ieee8021ah_c_daddr, {
"C-Destination", "ieee8021ah.cdst", FT_ETHER, BASE_NONE,
NULL, 0x0, "Customer Destination Address", HFILL }},
{ &hf_ieee8021ah_c_saddr, {
"C-Source", "ieee8021ah.csrc", FT_ETHER, BASE_NONE,
NULL, 0x0, "Customer Source Address", HFILL }},
{ &hf_ieee8021ah_etype, {
"Type", "ieee8021ah.etype", FT_UINT16, BASE_HEX,
VALS(etype_vals), 0x0, NULL, HFILL }},
#if 0
{ &hf_ieee8021ah_len, {
"Length", "ieee8021ah.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_ieee8021ah_trailer, {
"Trailer", "ieee8021ah.trailer", FT_BYTES, BASE_NONE,
NULL, 0x0, "802.1ah Trailer", HFILL }}
};
static hf_register_info hf_1ad[] = {
{ &hf_ieee8021ad_priority, {
"Priority", "ieee8021ad.priority", FT_UINT16, BASE_DEC,
0, 0xE000, NULL, HFILL }},
{ &hf_ieee8021ad_cfi, {
"DEI", "ieee8021ad.dei", FT_UINT16, BASE_DEC,
0, 0x1000, "Drop Eligibility", HFILL }},
{ &hf_ieee8021ad_id, {
"ID", "ieee8021ad.id", FT_UINT16, BASE_DEC,
0, 0x0FFF, "Vlan ID", HFILL }},
{ &hf_ieee8021ad_svid, {
"ID", "ieee8021ad.svid", FT_UINT16, BASE_DEC,
0, 0x0FFF, "S-Vlan ID", HFILL }},
{ &hf_ieee8021ad_cvid, {
"ID", "ieee8021ad.cvid", FT_UINT16, BASE_DEC,
0, 0x0FFF, "C-Vlan ID", HFILL }},
};
static gint *ett[] = {
&ett_ieee8021ah,
&ett_ieee8021ad
};
module_t *ieee8021ah_module;
proto_ieee8021ah = proto_register_protocol("IEEE 802.1ah", "IEEE 802.1AH",
"ieee8021ah");
proto_register_field_array(proto_ieee8021ah, hf, array_length(hf));
proto_ieee8021ad = proto_register_protocol("IEEE 802.1ad", "IEEE 802.1AD",
"ieee8021ad");
proto_register_field_array(proto_ieee8021ad, hf_1ad, array_length(hf_1ad));
proto_register_subtree_array(ett, array_length(ett));
ieee8021ah_module = prefs_register_protocol(proto_ieee8021ah,
proto_reg_handoff_ieee8021ah);
prefs_register_uint_preference(ieee8021ah_module, "8021ah_ethertype",
"802.1ah Ethertype (in hex)",
"(Hexadecimal) Ethertype used to indicate IEEE 802.1ah tag.",
16, &ieee8021ah_ethertype);
}
void
proto_reg_handoff_ieee8021ah(void)
{
static gboolean prefs_initialized = FALSE;
static dissector_handle_t ieee8021ah_handle;
static unsigned int old_ieee8021ah_ethertype;
if (!prefs_initialized){
dissector_handle_t ieee8021ad_handle;
ieee8021ah_handle = create_dissector_handle(dissect_ieee8021ah,
proto_ieee8021ah);
ieee8021ad_handle = create_dissector_handle(dissect_ieee8021ad,
proto_ieee8021ad);
dissector_add_uint("ethertype", ETHERTYPE_IEEE_802_1AD, ieee8021ad_handle);
ethertype_handle = find_dissector("ethertype");
prefs_initialized = TRUE;
}
else {
dissector_delete_uint("ethertype", old_ieee8021ah_ethertype, ieee8021ah_handle);
}
old_ieee8021ah_ethertype = ieee8021ah_ethertype;
dissector_add_uint("ethertype", ieee8021ah_ethertype, ieee8021ah_handle);
}
