static void
dissect_mtp2_header(tvbuff_t *su_tvb, proto_item *mtp2_tree, gboolean use_extended_sequence_numbers)
{
if (mtp2_tree) {
if (use_extended_sequence_numbers) {
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_bsn, su_tvb, EXTENDED_BSN_BIB_OFFSET, EXTENDED_BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_res, su_tvb, EXTENDED_BSN_BIB_OFFSET, EXTENDED_BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_bib, su_tvb, EXTENDED_BSN_BIB_OFFSET, EXTENDED_BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_fsn, su_tvb, EXTENDED_FSN_FIB_OFFSET, EXTENDED_FSN_FIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_res, su_tvb, EXTENDED_BSN_BIB_OFFSET, EXTENDED_BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_fib, su_tvb, EXTENDED_FSN_FIB_OFFSET, EXTENDED_FSN_FIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_li, su_tvb, EXTENDED_LI_OFFSET, EXTENDED_LI_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_ext_spare, su_tvb, EXTENDED_LI_OFFSET, EXTENDED_LI_LENGTH, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(mtp2_tree, hf_mtp2_bsn, su_tvb, BSN_BIB_OFFSET, BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_bib, su_tvb, BSN_BIB_OFFSET, BSN_BIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_fsn, su_tvb, FSN_FIB_OFFSET, FSN_FIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_fib, su_tvb, FSN_FIB_OFFSET, FSN_FIB_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_li, su_tvb, LI_OFFSET, LI_LENGTH, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mtp2_tree, hf_mtp2_spare, su_tvb, LI_OFFSET, LI_LENGTH, ENC_LITTLE_ENDIAN);
}
}
}
static guint16
mtp2_fcs16(tvbuff_t * tvbuff)
{
guint len = tvb_reported_length(tvbuff)-2;
if (len == 0)
return (0x0000);
return crc16_ccitt_tvb(tvbuff, len);
}
static tvbuff_t *
mtp2_decode_crc16(tvbuff_t *tvb, proto_tree *fh_tree, packet_info *pinfo)
{
tvbuff_t *next_tvb;
gint len, reported_len;
int rx_fcs_offset;
guint32 rx_fcs_exp;
guint32 rx_fcs_got;
int proto_offset=0;
proto_item *cause;
len = tvb_reported_length_remaining(tvb, proto_offset);
reported_len = tvb_reported_length_remaining(tvb, proto_offset);
if (reported_len < 2 || len < 0) {
next_tvb = tvb_new_subset_remaining(tvb, proto_offset);
} else if (len < reported_len) {
reported_len -= 2;
if (len > reported_len)
len = reported_len;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
} else {
len -= 2;
reported_len -= 2;
next_tvb = tvb_new_subset(tvb, proto_offset, len, reported_len);
rx_fcs_offset = proto_offset + len;
rx_fcs_exp = mtp2_fcs16(tvb);
rx_fcs_got = tvb_get_letohs(tvb, rx_fcs_offset);
cause=proto_tree_add_item(fh_tree, hf_mtp2_fcs_16, tvb, rx_fcs_offset, 2, ENC_LITTLE_ENDIAN);
if (rx_fcs_got != rx_fcs_exp) {
proto_item_append_text(cause, " [incorrect, should be 0x%04x]", rx_fcs_exp);
expert_add_info(pinfo, cause, &ei_mtp2_checksum_error);
} else {
proto_item_append_text(cause, " [correct]");
}
}
return next_tvb;
}
static void
dissect_mtp2_fisu(packet_info *pinfo)
{
col_set_str(pinfo->cinfo, COL_INFO, "FISU ");
}
static void
dissect_mtp2_lssu(tvbuff_t *su_tvb, packet_info *pinfo, proto_item *mtp2_tree,
gboolean use_extended_sequence_numbers)
{
guint8 sf = 0xFF;
guint8 sf_offset, sf_extra_offset;
if (use_extended_sequence_numbers) {
sf_offset = EXTENDED_SF_OFFSET;
sf_extra_offset = EXTENDED_SF_EXTRA_OFFSET;
} else {
sf_offset = SF_OFFSET;
sf_extra_offset = SF_EXTRA_OFFSET;
}
proto_tree_add_item(mtp2_tree, hf_mtp2_sf, su_tvb, sf_offset, SF_LENGTH, ENC_LITTLE_ENDIAN);
sf = tvb_get_guint8(su_tvb, SF_OFFSET);
if ((tvb_get_guint8(su_tvb, LI_OFFSET) & LI_MASK) == 2)
proto_tree_add_item(mtp2_tree, hf_mtp2_sf_extra, su_tvb, sf_extra_offset, SF_EXTRA_LENGTH, ENC_LITTLE_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(sf, status_field_acro_vals, "Unknown"));
}
static void
dissect_mtp2_msu(tvbuff_t *su_tvb, packet_info *pinfo, proto_item *mtp2_item,
proto_item *tree, gboolean use_extended_sequence_numbers)
{
gint sif_sio_length;
tvbuff_t *sif_sio_tvb;
col_set_str(pinfo->cinfo, COL_INFO, "MSU ");
if (use_extended_sequence_numbers) {
sif_sio_length = tvb_reported_length(su_tvb) - EXTENDED_HEADER_LENGTH;
sif_sio_tvb = tvb_new_subset_length(su_tvb, EXTENDED_SIO_OFFSET, sif_sio_length);
} else {
sif_sio_length = tvb_reported_length(su_tvb) - HEADER_LENGTH;
sif_sio_tvb = tvb_new_subset_length(su_tvb, SIO_OFFSET, sif_sio_length);
}
call_dissector(mtp3_handle, sif_sio_tvb, pinfo, tree);
if (tree) {
if (use_extended_sequence_numbers)
proto_item_set_len(mtp2_item, EXTENDED_HEADER_LENGTH);
else
proto_item_set_len(mtp2_item, HEADER_LENGTH);
}
}
static void
dissect_mtp2_su(tvbuff_t *su_tvb, packet_info *pinfo, proto_item *mtp2_item,
proto_item *mtp2_tree, proto_tree *tree, gboolean validate_crc,
gboolean use_extended_sequence_numbers)
{
guint16 li;
tvbuff_t *next_tvb = NULL;
dissect_mtp2_header(su_tvb, mtp2_tree, use_extended_sequence_numbers);
if (validate_crc)
next_tvb = mtp2_decode_crc16(su_tvb, mtp2_tree, pinfo);
if (use_extended_sequence_numbers)
li = tvb_get_letohs(su_tvb, EXTENDED_LI_OFFSET) & EXTENDED_LI_MASK;
else
li = tvb_get_guint8(su_tvb, LI_OFFSET) & LI_MASK;
switch(li) {
case 0:
dissect_mtp2_fisu(pinfo);
break;
case 1:
case 2:
if (validate_crc)
dissect_mtp2_lssu(next_tvb, pinfo, mtp2_tree, use_extended_sequence_numbers);
else
dissect_mtp2_lssu(su_tvb, pinfo, mtp2_tree, use_extended_sequence_numbers);
break;
default:
if (validate_crc)
dissect_mtp2_msu(next_tvb, pinfo, mtp2_item, tree, use_extended_sequence_numbers);
else
dissect_mtp2_msu(su_tvb, pinfo, mtp2_item, tree, use_extended_sequence_numbers);
break;
}
}
static void
dissect_mtp2_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean validate_crc, gboolean use_extended_sequence_numbers)
{
proto_item *mtp2_item;
proto_tree *mtp2_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MTP2");
mtp2_item = proto_tree_add_item(tree, proto_mtp2, tvb, 0, -1, ENC_NA);
mtp2_tree = proto_item_add_subtree(mtp2_item, ett_mtp2);
dissect_mtp2_su(tvb, pinfo, mtp2_item, mtp2_tree, tree, validate_crc,
use_extended_sequence_numbers);
}
static int
dissect_mtp2_with_phdr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
if (pinfo->pseudo_header->mtp2.annex_a_used == MTP2_ANNEX_A_USED_UNKNOWN)
dissect_mtp2_common(tvb, pinfo, tree, FALSE, use_extended_sequence_numbers_default);
else
dissect_mtp2_common(tvb, pinfo, tree, FALSE,
(pinfo->pseudo_header->mtp2.annex_a_used == MTP2_ANNEX_A_USED));
return tvb_captured_length(tvb);
}
static int
dissect_mtp2_with_crc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_mtp2_common(tvb, pinfo, tree, TRUE, use_extended_sequence_numbers_default);
return tvb_captured_length(tvb);
}
static int
dissect_mtp2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_mtp2_common(tvb, pinfo, tree, FALSE, use_extended_sequence_numbers_default);
return tvb_captured_length(tvb);
}
void
proto_register_mtp2(void)
{
static hf_register_info hf[] = {
{ &hf_mtp2_bsn, { "Backward sequence number", "mtp2.bsn", FT_UINT8, BASE_DEC, NULL, BSN_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_bsn, { "Backward sequence number", "mtp2.bsn", FT_UINT16, BASE_DEC, NULL, EXTENDED_BSN_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_res, { "Reserved", "mtp2.res", FT_UINT16, BASE_DEC, NULL, EXTENDED_RES_MASK, NULL, HFILL } },
{ &hf_mtp2_bib, { "Backward indicator bit", "mtp2.bib", FT_UINT8, BASE_DEC, NULL, BIB_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_bib, { "Backward indicator bit", "mtp2.bib", FT_UINT16, BASE_DEC, NULL, EXTENDED_BIB_MASK, NULL, HFILL } },
{ &hf_mtp2_fsn, { "Forward sequence number", "mtp2.fsn", FT_UINT8, BASE_DEC, NULL, FSN_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_fsn, { "Forward sequence number", "mtp2.fsn", FT_UINT16, BASE_DEC, NULL, EXTENDED_FSN_MASK, NULL, HFILL } },
{ &hf_mtp2_fib, { "Forward indicator bit", "mtp2.fib", FT_UINT8, BASE_DEC, NULL, FIB_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_fib, { "Forward indicator bit", "mtp2.fib", FT_UINT16, BASE_DEC, NULL, EXTENDED_FIB_MASK, NULL, HFILL } },
{ &hf_mtp2_li, { "Length Indicator", "mtp2.li", FT_UINT8, BASE_DEC, NULL, LI_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_li, { "Length Indicator", "mtp2.li", FT_UINT16, BASE_DEC, NULL, EXTENDED_LI_MASK, NULL, HFILL } },
{ &hf_mtp2_spare, { "Spare", "mtp2.spare", FT_UINT8, BASE_DEC, NULL, SPARE_MASK, NULL, HFILL } },
{ &hf_mtp2_ext_spare, { "Spare", "mtp2.spare", FT_UINT16, BASE_DEC, NULL, EXTENDED_SPARE_MASK, NULL, HFILL } },
{ &hf_mtp2_sf, { "Status field", "mtp2.sf", FT_UINT8, BASE_DEC, VALS(status_field_vals), 0x0, NULL, HFILL } },
{ &hf_mtp2_sf_extra, { "Status field extra octet", "mtp2.sf_extra", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_mtp2_fcs_16, { "FCS 16", "mtp2.fcs_16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_mtp2
};
static ei_register_info ei[] = {
{ &ei_mtp2_checksum_error, { "mtp2.checksum.error", PI_CHECKSUM, PI_WARN, "MTP2 Frame CheckFCS 16 Error", EXPFILL }},
};
module_t *mtp2_module;
expert_module_t* expert_mtp2;
proto_mtp2 = proto_register_protocol("Message Transfer Part Level 2", "MTP2", "mtp2");
mtp2_handle = register_dissector("mtp2", dissect_mtp2, proto_mtp2);
register_dissector("mtp2_with_crc", dissect_mtp2_with_crc, proto_mtp2);
proto_register_field_array(proto_mtp2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mtp2 = expert_register_protocol(proto_mtp2);
expert_register_field_array(expert_mtp2, ei, array_length(ei));
mtp2_module = prefs_register_protocol(proto_mtp2, NULL);
prefs_register_bool_preference(mtp2_module,
"use_extended_sequence_numbers",
"Use extended sequence numbers",
"Whether the MTP2 dissector should use extended sequence numbers as described in Q.703, Annex A as a default.",
&use_extended_sequence_numbers_default);
}
void
proto_reg_handoff_mtp2(void)
{
dissector_handle_t mtp2_with_phdr_handle;
dissector_add_uint("wtap_encap", WTAP_ENCAP_MTP2, mtp2_handle);
mtp2_with_phdr_handle = create_dissector_handle(dissect_mtp2_with_phdr,
proto_mtp2);
dissector_add_uint("wtap_encap", WTAP_ENCAP_MTP2_WITH_PHDR,
mtp2_with_phdr_handle);
mtp3_handle = find_dissector_add_dependency("mtp3", proto_mtp2);
}
