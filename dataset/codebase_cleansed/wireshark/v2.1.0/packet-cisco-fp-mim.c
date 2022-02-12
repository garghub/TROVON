static gboolean
dissect_fp_heur (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint16 type = 0;
type = tvb_get_ntohs (tvb, 12);
if (type == ETHERTYPE_DCE) {
dissect_fp (tvb, pinfo, tree, NULL);
return TRUE;
} else {
return FALSE;
}
}
static gboolean
fp_is_ig_set (guint64 hmac)
{
if (hmac & FP_HMAC_IG_MASK) {
return TRUE;
} else {
return FALSE;
}
}
static void
fp_get_hmac_addr (guint64 hmac, guint16 *swid, guint16 *sswid, guint16 *lid) {
if (!swid || !sswid || !lid) {
return;
}
*swid = (guint16) ((hmac & FP_HMAC_SWID_MASK) >> 24);
*sswid = (guint16) ((hmac & FP_HMAC_SSWID_MASK) >> 16);
*lid = (guint16) (hmac & FP_HMAC_LID_MASK);
}
static void
fp_add_hmac (tvbuff_t *tvb, proto_tree *tree, int offset) {
guint16 eid;
if (!tree) {
return;
}
eid = tvb_get_ntohs(tvb, offset);
eid &= FP_EID_MASK;
eid = ((eid & 0x00C0) >> 6) + ((eid & 0xFC00) >> 8);
proto_tree_add_uint(tree, hf_eid, tvb, offset, FP_BF_LEN, eid);
proto_tree_add_item (tree, hf_ul, tvb, offset, FP_BF_LEN, ENC_NA);
proto_tree_add_item (tree, hf_ig, tvb, offset, FP_BF_LEN, ENC_NA);
proto_tree_add_item (tree, hf_ooodl, tvb, offset, FP_BF_LEN, ENC_NA);
proto_tree_add_item (tree, hf_swid, tvb, offset, FP_BF_LEN, ENC_BIG_ENDIAN);
offset += FP_BF_LEN;
proto_tree_add_item (tree, hf_sswid, tvb, offset, FP_SSWID_LEN, ENC_BIG_ENDIAN);
offset += FP_SSWID_LEN;
proto_tree_add_item (tree, hf_lid, tvb, offset, FP_LID_LEN, ENC_BIG_ENDIAN);
}
static int
dissect_fp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
proto_item *ti ;
proto_tree *fp_tree ;
proto_tree *fp_addr_tree ;
tvbuff_t *next_tvb ;
int offset = 0 ;
guint64 hmac_src;
guint64 hmac_dst;
guint16 sswid = 0;
guint16 ssswid = 0;
guint16 slid = 0;
guint16 dswid = 0;
guint16 dsswid = 0;
guint16 dlid = 0;
const guint8 *dst_addr = NULL;
gboolean dest_ig = FALSE;
col_set_str( pinfo->cinfo, COL_PROTOCOL, FP_PROTO_COL_NAME ) ;
col_set_str( pinfo->cinfo, COL_INFO, FP_PROTO_COL_INFO ) ;
if (tree) {
hmac_dst = tvb_get_ntoh48 (tvb, 0);
hmac_src = tvb_get_ntoh48 (tvb, 6);
dest_ig = fp_is_ig_set(hmac_dst);
if (!dest_ig) {
fp_get_hmac_addr (hmac_dst, &dswid, &dsswid, &dlid);
} else {
hmac_dst = GUINT64_TO_BE (hmac_dst);
dst_addr = ((const guint8 *) &hmac_dst) + 2;
}
fp_get_hmac_addr (hmac_src, &sswid, &ssswid, &slid);
if (PTREE_DATA(tree)->visible) {
if (dest_ig) {
address ether_addr;
set_address(&ether_addr, AT_ETHER, 6, dst_addr);
ti = proto_tree_add_protocol_format(tree, proto_fp, tvb, 0, FP_HEADER_SIZE,
"Cisco FabricPath, Src: %03x.%02x.%04x, Dst: %s",
sswid, ssswid, slid,
address_with_resolution_to_str(wmem_packet_scope(), &ether_addr));
} else {
ti = proto_tree_add_protocol_format(tree, proto_fp, tvb, 0, FP_HEADER_SIZE,
"Cisco FabricPath, Src: %03x.%02x.%04x, Dst: %03x.%02x.%04x",
sswid, ssswid, slid,
dswid, dsswid, dlid);
}
} else {
ti = proto_tree_add_item( tree, proto_fp, tvb, 0, -1, ENC_NA ) ;
}
fp_tree = proto_item_add_subtree( ti, ett_mim ) ;
offset = 0;
if (dest_ig) {
proto_tree_add_ether( fp_tree, hf_d_hmac_mc, tvb, offset, 6,
dst_addr);
} else {
ti = proto_tree_add_none_format (fp_tree, hf_d_hmac, tvb, offset, 6, "Destination: %03x.%02x.%04x", dswid, dsswid, dlid);
fp_addr_tree = proto_item_add_subtree (ti, ett_hmac);
fp_add_hmac (tvb, fp_addr_tree, offset);
}
offset += FP_HMAC_LEN;
ti = proto_tree_add_none_format (fp_tree, hf_s_hmac, tvb, offset, 6,
"Source: %03x.%02x.%04x", sswid, ssswid, slid);
fp_addr_tree = proto_item_add_subtree (ti, ett_hmac);
fp_add_hmac (tvb, fp_addr_tree, offset);
offset += FP_HMAC_LEN;
offset += 2;
proto_tree_add_item (fp_tree, hf_ftag, tvb, offset, FP_FTAG_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item (fp_tree, hf_ttl, tvb, offset, FP_FTAG_LEN, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining( tvb, FP_HEADER_SIZE) ;
call_dissector( eth_maybefcs_dissector, next_tvb, pinfo, tree ) ;
return tvb_captured_length( tvb ) ;
}
void
proto_register_mim(void)
{
static hf_register_info hf[] = {
{ &hf_s_hmac,
{ "Source HMAC", "cfp.s_hmac",
FT_NONE, BASE_NONE, NULL,
0, "Source Hierarchical MAC", HFILL }},
{ &hf_d_hmac,
{ "Destination HMAC", "cfp.d_hmac",
FT_NONE, BASE_NONE, NULL,
0, "Destination Hierarchical MAC", HFILL }},
{ &hf_d_hmac_mc,
{ "MC Destination", "cfp.d_hmac_mc",
FT_ETHER, BASE_NONE, NULL,
0, "Multicast Destination Address", HFILL }},
{ &hf_ftag,
{ "FTAG", "cfp.ftag",
FT_UINT16, BASE_DEC, NULL, FP_FTAG_MASK,
"FTAG field identifying forwarding distribution tree.", HFILL }},
{ &hf_ttl,
{ "TTL", "cfp.ttl",
FT_UINT16, BASE_DEC, NULL, FP_TTL_MASK,
"The remaining hop count for this frame", HFILL }},
{
&hf_swid,
{ "switch-id", "cfp.swid",
FT_UINT24, BASE_DEC_HEX, NULL, FP_SWID_MASK,
"Switch-id/nickname of switch in FabricPath network", HFILL }},
{
&hf_sswid,
{ "sub-switch-id", "cfp.sswid",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
"Sub-switch-id of switch in FabricPath network", HFILL }},
{
&hf_eid,
{ "End Node ID", "cfp.eid",
FT_UINT24, BASE_DEC_HEX, NULL, FP_3B_EID_MASK,
"Cisco FabricPath End node ID", HFILL }},
{
&hf_lid,
{ "Source LID", "cfp.lid",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"Source or Destination Port index on switch in FabricPath network", HFILL }},
{
&hf_ul,
{ "U/L bit", "cfp.ul",
FT_BOOLEAN, 24, TFS(&ul_tfs), FP_UL_MASK,
"Specifies if this is a locally administered or globally unique (IEEE assigned) address", HFILL }},
{
&hf_ig,
{ "I/G bit", "cfp.ig",
FT_BOOLEAN, 24 , TFS(&ig_tfs), FP_IG_MASK,
"Specifies if this is an individual (unicast) or group (broadcast/multicast) address", HFILL }},
{
&hf_ooodl,
{ "OOO/DL Bit", "cfp.ooodl",
FT_BOOLEAN, 24 , TFS(&ooodl_tfs), FP_OOO_MASK,
"Specifies Out of Order Delivery OK in destination address and Do Not Learn when set in source address", HFILL }}
};
static gint *ett[] = {
&ett_mim,
&ett_hmac
};
module_t *mim_module;
proto_fp = proto_register_protocol("Cisco FabricPath", "CFP", "cfp");
mim_module = prefs_register_protocol (proto_fp, proto_reg_handoff_fabricpath);
prefs_register_obsolete_preference (mim_module, "enable");
proto_register_field_array(proto_fp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_fabricpath(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
heur_dissector_add ("eth", dissect_fp_heur, "Cisco FabricPath over Ethernet", "fp_eth", proto_fp, HEURISTIC_DISABLE);
eth_maybefcs_dissector = find_dissector_add_dependency( "eth_maybefcs", proto_fp );
prefs_initialized = TRUE;
}
}
