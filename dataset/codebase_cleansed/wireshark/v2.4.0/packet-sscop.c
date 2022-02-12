static void dissect_stat_list(proto_tree *tree, tvbuff_t *tvb,guint h) {
gint n,i;
if ((n = (tvb_reported_length(tvb))/4 - h)) {
tree = proto_tree_add_subtree(tree,tvb,0,n*4,ett_stat,NULL,"SD List");
for (i = 0; i < n; i++) {
proto_tree_add_item(tree, hf_sscop_stat_s, tvb, i*4 + 1,3,ENC_BIG_ENDIAN);
}
}
}
extern void
dissect_sscop_and_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, dissector_handle_t payload_handle)
{
guint reported_length;
proto_item *ti;
proto_tree *sscop_tree = NULL;
guint8 sscop_pdu_type;
int pdu_len;
int pad_len;
tvbuff_t *next_tvb;
reported_length = tvb_reported_length(tvb);
sscop_pdu_type = tvb_get_guint8(tvb, SSCOP_PDU_TYPE);
sscop_info.type = sscop_pdu_type & SSCOP_TYPE_MASK;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSCOP");
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(sscop_info.type, &sscop_type_vals_ext,
"Unknown PDU type (0x%02x)"));
switch (sscop_info.type) {
case SSCOP_SD:
pad_len = (sscop_pdu_type >> 6) & 0x03;
pdu_len = 4;
break;
case SSCOP_BGN:
case SSCOP_BGAK:
case SSCOP_BGREJ:
case SSCOP_END:
case SSCOP_RS:
#if 0
case SSCOP_SDP:
#endif
pad_len = (sscop_pdu_type >> 6) & 0x03;
sscop_info.payload_len = pdu_len = 8;
break;
case SSCOP_UD:
pad_len = (sscop_pdu_type >> 6) & 0x03;
sscop_info.payload_len = pdu_len = 4;
break;
default:
pad_len = 0;
pdu_len = reported_length;
sscop_info.payload_len = 0;
break;
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_sscop, tvb,
reported_length - pdu_len,
pdu_len, "SSCOP");
sscop_tree = proto_item_add_subtree(ti, ett_sscop);
proto_tree_add_item(sscop_tree, hf_sscop_type, tvb, SSCOP_PDU_TYPE, 1,ENC_BIG_ENDIAN);
switch (sscop_info.type) {
case SSCOP_BGN:
case SSCOP_RS:
case SSCOP_ER:
proto_tree_add_item(sscop_tree, hf_sscop_sq, tvb, SSCOP_N_SQ, 1,ENC_BIG_ENDIAN);
proto_tree_add_item(sscop_tree, hf_sscop_mr, tvb, SSCOP_N_MR + 1, 3, ENC_BIG_ENDIAN);
break;
case SSCOP_END:
proto_tree_add_string(sscop_tree, hf_sscop_source, tvb, SSCOP_PDU_TYPE, 1,
(sscop_pdu_type & SSCOP_S) ? "SSCOP" : "User");
break;
case SSCOP_BGAK:
case SSCOP_RSAK:
proto_tree_add_item(sscop_tree, hf_sscop_mr, tvb, SSCOP_N_MR + 1, 3, ENC_BIG_ENDIAN);
break;
case SSCOP_ERAK:
proto_tree_add_item(sscop_tree, hf_sscop_mr, tvb, SSCOP_N_MR + 1, 3, ENC_BIG_ENDIAN);
break;
case SSCOP_SD:
proto_tree_add_item(sscop_tree, hf_sscop_s, tvb, SSCOP_N_S + 1, 3, ENC_BIG_ENDIAN);
break;
#if 0
case SSCOP_SDP:
#endif
case SSCOP_POLL:
proto_tree_add_item(sscop_tree, hf_sscop_ps, tvb, SSCOP_N_PS + 1, 3,ENC_BIG_ENDIAN);
proto_tree_add_item(sscop_tree, hf_sscop_s, tvb, SSCOP_N_S + 1, 3,ENC_BIG_ENDIAN);
break;
case SSCOP_STAT:
proto_tree_add_item(sscop_tree, hf_sscop_ps, tvb, SSCOP_SS_N_PS + 1, 3,ENC_BIG_ENDIAN);
proto_tree_add_item(sscop_tree, hf_sscop_mr, tvb, SSCOP_SS_N_MR + 1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sscop_tree, hf_sscop_r, tvb, SSCOP_SS_N_R + 1, 3,ENC_BIG_ENDIAN);
dissect_stat_list(sscop_tree,tvb,3);
break;
case SSCOP_USTAT:
proto_tree_add_item(sscop_tree, hf_sscop_mr, tvb, SSCOP_SS_N_MR + 1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(sscop_tree, hf_sscop_r, tvb, SSCOP_SS_N_R + 1, 3,ENC_BIG_ENDIAN);
dissect_stat_list(sscop_tree,tvb,2);
break;
}
}
switch (sscop_info.type) {
case SSCOP_SD:
case SSCOP_UD:
case SSCOP_BGN:
case SSCOP_BGAK:
case SSCOP_BGREJ:
case SSCOP_END:
case SSCOP_RS:
#if 0
case SSCOP_SDP:
#endif
if (tree) {
proto_tree_add_uint(sscop_tree, hf_sscop_pad_length, tvb, SSCOP_PDU_TYPE, 1, pad_len);
}
reported_length -= (pdu_len + pad_len);
if (reported_length != 0) {
next_tvb = tvb_new_subset_length(tvb, 0, reported_length);
if (sscop_info.type == SSCOP_SD)
{
call_dissector(payload_handle, next_tvb, pinfo, tree);
}
break;
}
}
}
static int dissect_sscop(tvbuff_t* tvb, packet_info* pinfo,proto_tree* tree, void* data _U_)
{
struct _sscop_payload_info *p_sscop_info;
dissector_handle_t subdissector;
p_sscop_info = (struct _sscop_payload_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_sscop, 0);
if ( p_sscop_info
&& ( subdissector = p_sscop_info->subdissector )
&& ( subdissector == data_handle
|| subdissector == q2931_handle
|| subdissector == sscf_nni_handle
|| subdissector == alcap_handle
|| subdissector == nbap_handle) )
dissect_sscop_and_payload(tvb,pinfo,tree,subdissector);
else
dissect_sscop_and_payload(tvb,pinfo,tree,default_handle);
return tvb_captured_length(tvb);
}
static void initialize_handles_once(void) {
static gboolean initialized = FALSE;
if (!initialized) {
q2931_handle = find_dissector("q2931");
data_handle = find_dissector("data");
sscf_nni_handle = find_dissector("sscf-nni");
alcap_handle = find_dissector("alcap");
nbap_handle = find_dissector("nbap");
initialized = TRUE;
}
}
gboolean sscop_allowed_subdissector(dissector_handle_t handle)
{
initialize_handles_once();
if (handle == q2931_handle || handle == data_handle
|| handle == sscf_nni_handle || handle == alcap_handle
|| handle == nbap_handle)
return TRUE;
return FALSE;
}
void
proto_reg_handoff_sscop(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
initialize_handles_once();
dissector_add_uint_range_with_preference("udp.port", "", sscop_handle);
prefs_initialized = TRUE;
}
dissector_add_uint("atm.aal5.type", TRAF_SSCOP, sscop_handle);
switch(sscop_payload_dissector) {
case DATA_DISSECTOR: default_handle = data_handle; break;
case Q2931_DISSECTOR: default_handle = q2931_handle; break;
case SSCF_NNI_DISSECTOR: default_handle = sscf_nni_handle; break;
case ALCAP_DISSECTOR: default_handle = alcap_handle; break;
case NBAP_DISSECTOR: default_handle = nbap_handle; break;
}
}
void
proto_register_sscop(void)
{
static hf_register_info hf[] = {
{ &hf_sscop_type, { "PDU Type", "sscop.type", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &sscop_type_vals_ext, SSCOP_TYPE_MASK, NULL, HFILL }},
{ &hf_sscop_sq, { "N(SQ)", "sscop.sq", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_mr, { "N(MR)", "sscop.mr", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_s, { "N(S)", "sscop.s", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_ps, { "N(PS)", "sscop.ps", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_r, { "N(R)", "sscop.r", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_stat_s, { "N(S)", "sscop.stat.s", FT_UINT24, BASE_DEC, NULL, 0x0,NULL, HFILL }},
{ &hf_sscop_pad_length, { "Pad length", "sscop.pad_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sscop_source, { "Source", "sscop.source", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_sscop_stat_count, { "Number of NACKed pdus", "sscop.stat.count", FT_UINT32, BASE_DEC, NULL, 0x0,NULL, HFILL }}
#endif
};
static gint *ett[] = {
&ett_sscop,
&ett_stat
};
module_t *sscop_module;
proto_sscop = proto_register_protocol("SSCOP", "SSCOP", "sscop");
proto_register_field_array(proto_sscop, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sscop_handle = register_dissector("sscop", dissect_sscop, proto_sscop);
sscop_module = prefs_register_protocol(proto_sscop, proto_reg_handoff_sscop);
prefs_register_enum_preference(sscop_module, "payload",
"SSCOP payload protocol",
"SSCOP payload (dissector to call on SSCOP payload)",
(gint *)&sscop_payload_dissector,
sscop_payload_dissector_options, FALSE);
}
