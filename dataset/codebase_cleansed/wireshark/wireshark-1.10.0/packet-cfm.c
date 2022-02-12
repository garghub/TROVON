static int dissect_cfm_ccm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint maid_offset;
gint itu_offset;
guint8 cfm_maid_md_name_format;
guint8 cfm_maid_ma_name_format;
guint8 cfm_maid_ma_name_length;
proto_item *ti;
proto_item *fi;
proto_item *mi;
proto_item *wi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
proto_tree *cfm_ccm_maid_tree;
proto_tree *cfm_ccm_itu_tree;
ti = proto_tree_add_item(tree, hf_cfm_ccm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_RDI, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ccm_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Interval, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_ccm_seq_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_ccm_ma_ep_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_ccm_maid, tvb, offset, 48, ENC_NA);
cfm_ccm_maid_tree = proto_item_add_subtree(mi, ett_cfm_ccm_maid);
maid_offset = offset;
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_format, tvb, maid_offset, 1, ENC_BIG_ENDIAN);
cfm_maid_md_name_format = tvb_get_guint8(tvb, maid_offset);
maid_offset += 1;
if (cfm_maid_md_name_format != 1) {
guint8 cfm_maid_md_name_length;
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_length,
tvb, maid_offset, 1, ENC_BIG_ENDIAN);
cfm_maid_md_name_length = tvb_get_guint8(tvb, maid_offset);
maid_offset += 1;
if (cfm_maid_md_name_length) {
if (cfm_maid_md_name_format == 3) {
if (cfm_maid_md_name_length != 8) {
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_hex,
tvb, maid_offset, cfm_maid_md_name_length, ENC_NA);
} else {
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_mac,
tvb, maid_offset, 6, ENC_NA);
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_mac_id,
tvb, maid_offset+6, 2, ENC_NA);
}
} else {
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_md_name_string,
tvb, maid_offset, cfm_maid_md_name_length, ENC_ASCII|ENC_NA);
}
maid_offset += cfm_maid_md_name_length;
}
}
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_ma_name_format, tvb, maid_offset, 1, ENC_BIG_ENDIAN);
cfm_maid_ma_name_format = tvb_get_guint8(tvb, maid_offset);
maid_offset += 1;
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_ma_name_length, tvb, maid_offset, 1, ENC_BIG_ENDIAN);
cfm_maid_ma_name_length = tvb_get_guint8(tvb, maid_offset);
maid_offset += 1;
if ((cfm_maid_ma_name_format == 2) ||
(cfm_maid_ma_name_format == 32)) {
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_ma_name_string,
tvb, maid_offset, cfm_maid_ma_name_length, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_ma_name_hex,
tvb, maid_offset, cfm_maid_ma_name_length, ENC_NA);
}
maid_offset += cfm_maid_ma_name_length;
offset += 48;
if (offset > maid_offset) {
gint padding_length;
padding_length = offset - maid_offset;
proto_tree_add_item(cfm_ccm_maid_tree, hf_cfm_maid_padding,
tvb, maid_offset, padding_length, ENC_NA);
}
wi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_ccm_itu_t_y1731, tvb, offset, 16, ENC_NA);
cfm_ccm_itu_tree = proto_item_add_subtree(wi, ett_cfm_ccm_itu);
itu_offset = offset;
proto_tree_add_item(cfm_ccm_itu_tree, hf_cfm_itu_TxFCf, tvb, itu_offset, 4, ENC_NA);
itu_offset += 4;
proto_tree_add_item(cfm_ccm_itu_tree, hf_cfm_itu_RxFCb, tvb, itu_offset, 4, ENC_NA);
itu_offset += 4;
proto_tree_add_item(cfm_ccm_itu_tree, hf_cfm_itu_TxFCb, tvb, itu_offset, 4, ENC_NA);
itu_offset += 4;
proto_tree_add_item(cfm_ccm_itu_tree, hf_cfm_itu_reserved, tvb, itu_offset, 4, ENC_NA);
itu_offset += 4;
offset += 16;
return offset;
}
static int dissect_cfm_lbm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *cfm_pdu_tree;
ti = proto_tree_add_item(tree, hf_cfm_lbm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lb_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_cfm_lbr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *cfm_pdu_tree;
ti = proto_tree_add_item(tree, hf_cfm_lbr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lb_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_cfm_ltm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_ltm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_UseFDBonly, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ltm_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lt_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lt_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_ltm_orig_addr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_ltm_targ_addr, tvb, offset, 6, ENC_NA);
offset += 6;
return offset;
}
static int dissect_cfm_ltr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_ltr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_UseFDBonly, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_FwdYes, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_TerminalMEP, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ltr_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lt_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lt_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_ltr_relay_action, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int dissect_cfm_ais(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_ais_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ais_lck_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ais_lck_Period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int dissect_cfm_lck(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_lck_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ais_lck_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_ais_lck_Period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int dissect_cfm_tst(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_tst_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_tst_sequence_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_cfm_aps(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_aps_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_req_st, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_protection_type_A, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_protection_type_B, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_protection_type_D, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_protection_type_R, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_requested_signal, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_bridged_signal, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_aps_bridge_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int dissect_cfm_raps(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_item *ri;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
proto_tree *raps_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_raps_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_raps_req_st, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ri = proto_tree_add_item(cfm_pdu_tree, hf_cfm_raps_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
raps_flag_tree = proto_item_add_subtree(ri, ett_cfm_raps_flags);
proto_tree_add_item(raps_flag_tree, hf_cfm_raps_flags_rb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(raps_flag_tree, hf_cfm_raps_flags_dnf, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_raps_node_id, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_raps_reserved, tvb, offset, 24, ENC_NA);
offset += 24;
return offset;
}
static int dissect_cfm_mcc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint cfm_tlv_offset;
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_mcc_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_oui, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset -= 4;
if (cfm_tlv_offset > 0) {
proto_tree_add_item(cfm_pdu_tree, hf_cfm_mcc_data, tvb, offset, cfm_tlv_offset, ENC_NA);
offset += cfm_tlv_offset;
}
return offset;
}
static int dissect_cfm_lmm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_lmm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_TxFCf, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_RxFCf, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_TxFCb, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int dissect_cfm_lmr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_lmr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_TxFCf, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_RxFCf, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_lmm_lmr_TxFCb, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int dissect_cfm_odm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_odm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_TxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_RxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int dissect_cfm_dmm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_dmm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_TxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_RxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_dmm_dmr_TxTimestampb, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_dmm_dmr_RxTimestampb, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int dissect_cfm_dmr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_dmr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_TxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_odm_dmm_dmr_RxTimestampf, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_dmm_dmr_TxTimestampb, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_dmm_dmr_RxTimestampb, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int dissect_cfm_exm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint cfm_tlv_offset;
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_exm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_oui, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset -= 4;
if (cfm_tlv_offset > 0) {
proto_tree_add_item(cfm_pdu_tree, hf_cfm_exm_exr_data, tvb, offset, cfm_tlv_offset, ENC_NA);
offset += cfm_tlv_offset;
}
return offset;
}
static int dissect_cfm_exr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint cfm_tlv_offset;
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_exr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_oui, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset -= 4;
if (cfm_tlv_offset > 0) {
proto_tree_add_item(cfm_pdu_tree, hf_cfm_exm_exr_data, tvb, offset, cfm_tlv_offset, ENC_NA);
offset += cfm_tlv_offset;
}
return offset;
}
static int dissect_cfm_vsm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint cfm_tlv_offset;
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_vsm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_oui, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset -= 4;
if (cfm_tlv_offset > 0) {
proto_tree_add_item(cfm_pdu_tree, hf_cfm_vsm_vsr_data, tvb, offset, cfm_tlv_offset, ENC_NA);
offset += cfm_tlv_offset;
}
return offset;
}
static int dissect_cfm_vsr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
gint cfm_tlv_offset;
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_vsr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_oui, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(cfm_pdu_tree, hf_tlv_org_spec_subtype, tvb, offset, 1, ENC_NA);
offset += 1;
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset -= 4;
if (cfm_tlv_offset > 0) {
proto_tree_add_item(cfm_pdu_tree, hf_cfm_vsm_vsr_data, tvb, offset, cfm_tlv_offset, ENC_NA);
offset += cfm_tlv_offset;
}
return offset;
}
static int dissect_cfm_slm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_slm_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_src_mep, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slr_rsp_mep, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_testid, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_txfcf, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slr_txfcb, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_cfm_slr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_item *fi;
proto_tree *cfm_pdu_tree;
proto_tree *cfm_flag_tree;
ti = proto_tree_add_item(tree, hf_cfm_slr_pdu, tvb, offset, -1, ENC_NA);
cfm_pdu_tree = proto_item_add_subtree(ti, ett_cfm_pdu);
fi = proto_tree_add_item(cfm_pdu_tree, hf_cfm_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
cfm_flag_tree = proto_item_add_subtree(fi, ett_cfm_flags);
proto_tree_add_item(cfm_flag_tree, hf_cfm_flags_Reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_first_tlv_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_src_mep, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slr_rsp_mep, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_testid, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slm_txfcf, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfm_pdu_tree, hf_cfm_slr_txfcb, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static void dissect_cfm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
guint8 cfm_pdu_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CFM");
col_clear(pinfo->cinfo, COL_INFO);
cfm_pdu_type = tvb_get_guint8(tvb, 1);
col_add_fstr(pinfo->cinfo, COL_INFO, "Type %s",
val_to_str(cfm_pdu_type, opcodetypenames, "Unknown (0x%02x)"));
if (tree) {
gint cfm_tlv_offset;
proto_item *ti;
proto_tree *cfm_tree;
ti = proto_tree_add_item(tree, proto_cfm, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Type %s",
val_to_str(cfm_pdu_type, opcodetypenames, "Unknown (0x%02x)"));
cfm_tree = proto_item_add_subtree(ti, ett_cfm);
proto_tree_add_item(cfm_tree, hf_cfm_md_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cfm_tree, hf_cfm_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cfm_tree, hf_cfm_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch(cfm_pdu_type) {
case CCM:
offset = dissect_cfm_ccm(tvb, pinfo, tree, offset);
break;
case LBM:
offset = dissect_cfm_lbm(tvb, pinfo, tree, offset);
break;
case LBR:
offset = dissect_cfm_lbr(tvb, pinfo, tree, offset);
break;
case LTM:
offset = dissect_cfm_ltm(tvb, pinfo, tree, offset);
break;
case LTR:
offset = dissect_cfm_ltr(tvb, pinfo, tree, offset);
break;
case AIS:
offset = dissect_cfm_ais(tvb, pinfo, tree, offset);
break;
case LCK:
offset = dissect_cfm_lck(tvb, pinfo, tree, offset);
break;
case TST:
offset = dissect_cfm_tst(tvb, pinfo, tree, offset);
break;
case APS:
offset = dissect_cfm_aps(tvb, pinfo, tree, offset);
break;
case RAPS:
offset = dissect_cfm_raps(tvb, pinfo, tree, offset);
break;
case MCC:
offset = dissect_cfm_mcc(tvb, pinfo, tree, offset);
break;
case LMM:
offset = dissect_cfm_lmm(tvb, pinfo, tree, offset);
break;
case LMR:
offset = dissect_cfm_lmr(tvb, pinfo, tree, offset);
break;
case ODM:
offset = dissect_cfm_odm(tvb, pinfo, tree, offset);
break;
case DMM:
offset = dissect_cfm_dmm(tvb, pinfo, tree, offset);
break;
case DMR:
offset = dissect_cfm_dmr(tvb, pinfo, tree, offset);
break;
case EXM:
offset = dissect_cfm_exm(tvb, pinfo, tree, offset);
break;
case EXR:
offset = dissect_cfm_exr(tvb, pinfo, tree, offset);
break;
case VSM:
offset = dissect_cfm_vsm(tvb, pinfo, tree, offset);
break;
case VSR:
offset = dissect_cfm_vsr(tvb, pinfo, tree, offset);
break;
case SLM:
offset = dissect_cfm_slm(tvb, pinfo, tree, offset);
break;
case SLR:
offset = dissect_cfm_slr(tvb, pinfo, tree, offset);
break;
}
cfm_tlv_offset = tvb_get_guint8(tvb, 3);
cfm_tlv_offset += 4;
if ((cfm_tlv_offset == offset) && (cfm_tlv_offset > 3)) {
proto_tree *cfm_all_tlvs_tree;
guint8 cfm_tlv_type = 255;
ti = proto_tree_add_item(tree, hf_cfm_all_tlvs, tvb, cfm_tlv_offset, -1, ENC_NA);
cfm_all_tlvs_tree = proto_item_add_subtree(ti, ett_cfm_all_tlvs);
while (cfm_tlv_type != END_TLV)
{
guint16 cfm_tlv_length;
gint tlv_header_modifier;
proto_item *fi;
proto_tree *cfm_tlv_tree;
cfm_tlv_type = tvb_get_guint8(tvb, cfm_tlv_offset);
if (cfm_tlv_type == END_TLV) {
tlv_header_modifier = 1;
cfm_tlv_length = 0;
} else {
tlv_header_modifier = 3;
cfm_tlv_length = tvb_get_ntohs(tvb, cfm_tlv_offset+1);
}
fi = proto_tree_add_text(cfm_all_tlvs_tree, tvb, cfm_tlv_offset, cfm_tlv_length+tlv_header_modifier,
"TLV: %s (t=%d,l=%d)", val_to_str(cfm_tlv_type, tlvtypefieldvalues, "Unknown (0x%02x)"),
cfm_tlv_type, cfm_tlv_length);
cfm_tlv_tree = proto_item_add_subtree(fi, ett_cfm_tlv);
proto_tree_add_item(cfm_tlv_tree, hf_cfm_tlv_type, tvb, cfm_tlv_offset, 1, ENC_BIG_ENDIAN);
cfm_tlv_offset += 1;
if (cfm_tlv_type != END_TLV) {
proto_tree_add_item(cfm_tlv_tree, hf_cfm_tlv_length, tvb, cfm_tlv_offset, 2, ENC_BIG_ENDIAN);
cfm_tlv_offset += 2;
if (cfm_tlv_length != 0) {
gint tlv_data_offset;
guint8 tlv_chassis_id_length;
guint8 tlv_tst_test_pattern_type;
tlv_data_offset = cfm_tlv_offset;
switch(cfm_tlv_type) {
case SENDER_ID_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_chassis_id_length,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_chassis_id_length = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (tlv_chassis_id_length > 0) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_chassis_id_subtype,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_chassis_id,
tvb, tlv_data_offset, tlv_chassis_id_length, ENC_NA);
tlv_data_offset += tlv_chassis_id_length;
}
if (cfm_tlv_length > (2 + tlv_chassis_id_length)) {
guint8 tlv_ma_domain_length;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ma_domain_length,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_ma_domain_length = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (tlv_ma_domain_length > 0) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ma_domain,
tvb, tlv_data_offset, tlv_ma_domain_length, ENC_NA);
tlv_data_offset += tlv_ma_domain_length;
}
if (cfm_tlv_length > (2 + tlv_chassis_id_length + 1 + tlv_ma_domain_length)) {
guint8 tlv_management_addr_length;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_management_addr_length,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_management_addr_length = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (tlv_management_addr_length > 0) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_management_addr,
tvb, tlv_data_offset, tlv_management_addr_length, ENC_NA);
tlv_data_offset += tlv_management_addr_length;
}
}
}
break;
case PORT_STAT_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_port_status_value,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
break;
case DATA_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_data_value,
tvb, tlv_data_offset, cfm_tlv_length, ENC_NA);
tlv_data_offset += cfm_tlv_length;
break;
case INTERF_STAT_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_interface_status_value,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
break;
case REPLY_ING_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ingress_action,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ingress_mac_address,
tvb, tlv_data_offset, 6, ENC_NA);
tlv_data_offset += 6;
if (cfm_tlv_length > 7) {
guint8 tlv_reply_ingress_portid_length;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid_length,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_reply_ingress_portid_length = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (tlv_reply_ingress_portid_length > 0) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid_subtype,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid,
tvb, tlv_data_offset, tlv_reply_ingress_portid_length, ENC_NA);
tlv_data_offset += tlv_reply_ingress_portid_length;
}
}
break;
case REPLY_EGR_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_egress_action,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_egress_mac_address,
tvb, tlv_data_offset, 6, ENC_NA);
tlv_data_offset += 6;
if (cfm_tlv_length > 7) {
guint8 tlv_reply_egress_portid_length;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid_length,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_reply_egress_portid_length = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (tlv_reply_egress_portid_length > 0) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid_subtype,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_reply_ing_egr_portid,
tvb, tlv_data_offset, tlv_reply_egress_portid_length, ENC_NA);
tlv_data_offset += tlv_reply_egress_portid_length;
}
}
break;
case LTM_EGR_ID_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltm_egress_id_unique_identifier,
tvb, tlv_data_offset, 2, ENC_NA);
tlv_data_offset += 2;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltm_egress_id_mac,
tvb, tlv_data_offset, 6, ENC_NA);
tlv_data_offset += 6;
break;
case LTR_EGR_ID_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltr_egress_last_id_unique_identifier,
tvb, tlv_data_offset, 2, ENC_NA);
tlv_data_offset += 2;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltr_egress_last_id_mac,
tvb, tlv_data_offset, 6, ENC_NA);
tlv_data_offset += 6;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltr_egress_next_id_unique_identifier,
tvb, tlv_data_offset, 2, ENC_NA);
tlv_data_offset += 2;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_ltr_egress_next_id_mac,
tvb, tlv_data_offset, 6, ENC_NA);
tlv_data_offset += 6;
break;
case ORG_SPEC_TLV:
if (cfm_tlv_length > 3) {
proto_tree_add_item(cfm_tlv_tree, hf_tlv_org_spec_oui,
tvb, tlv_data_offset, 3, ENC_NA);
tlv_data_offset += 3;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_org_spec_subtype,
tvb, tlv_data_offset, 1, ENC_NA);
tlv_data_offset += 1;
proto_tree_add_item(cfm_tlv_tree, hf_tlv_org_spec_value,
tvb, tlv_data_offset, cfm_tlv_length-4, ENC_NA);
tlv_data_offset -= 4;
}
tlv_data_offset += cfm_tlv_length;
break;
case TEST_TLV:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_tst_test_pattern_type,
tvb, tlv_data_offset, 1, ENC_BIG_ENDIAN);
tlv_tst_test_pattern_type = tvb_get_guint8(tvb,tlv_data_offset);
tlv_data_offset += 1;
if (cfm_tlv_length > 0) {
switch (tlv_tst_test_pattern_type) {
case 0:
case 2:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_tst_test_pattern,
tvb, tlv_data_offset, cfm_tlv_length-1, ENC_NA);
tlv_data_offset += cfm_tlv_length;
break;
case 1:
case 3:
proto_tree_add_item(cfm_tlv_tree, hf_tlv_tst_test_pattern,
tvb, tlv_data_offset, cfm_tlv_length-5, ENC_NA);
tlv_data_offset += (cfm_tlv_length-5);
proto_tree_add_item(cfm_tlv_tree, hf_tlv_tst_CRC32,
tvb, tlv_data_offset, 4, ENC_NA);
tlv_data_offset += 4;
break;
}
}
break;
}
cfm_tlv_offset += cfm_tlv_length;
}
}
}
}
}
}
void proto_register_cfm(void)
{
static hf_register_info hf[] = {
{ &hf_cfm_md_level,
{ "CFM MD Level", "cfm.md.level", FT_UINT8,
BASE_DEC, NULL, 0xe0, NULL, HFILL }
},
{ &hf_cfm_version,
{ "CFM Version", "cfm.version", FT_UINT8,
BASE_DEC, NULL, 0x1f, NULL, HFILL }
},
{ &hf_cfm_opcode,
{ "CFM OpCode", "cfm.opcode", FT_UINT8,
BASE_DEC, VALS(opcodetypenames), 0x0, NULL, HFILL }
},
{ &hf_cfm_ccm_pdu,
{ "CFM CCM PDU", "cfm.ccm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags,
{ "Flags", "cfm.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags_RDI,
{ "RDI", "cfm.flags.rdi", FT_UINT8,
BASE_DEC, NULL, 0x80, NULL, HFILL }
},
{ &hf_cfm_flags_ccm_Reserved,
{ "Reserved", "cfm.flags.ccm.reserved", FT_UINT8,
BASE_DEC, NULL, 0x78, NULL, HFILL }
},
{ &hf_cfm_flags_Interval,
{ "Interval Field", "cfm.flags.interval", FT_UINT8,
BASE_DEC, VALS(CCM_IntervalFieldEncoding), 0x07, NULL, HFILL }
},
{ &hf_cfm_first_tlv_offset,
{ "First TLV Offset", "cfm.first.tlv.offset", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ccm_seq_number,
{ "Sequence Number", "cfm.ccm.seq.num", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ccm_ma_ep_id,
{ "Maintenance Association End Point Identifier", "cfm.ccm.ma.ep.id",
FT_UINT16, BASE_DEC, NULL, 0x1FFF, NULL, HFILL }
},
{ &hf_cfm_ccm_maid,
{ "Maintenance Association Identifier (MEG ID)", "cfm.ccm.maid", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_format,
{ "MD Name Format", "cfm.maid.md.name.format", FT_UINT8,
BASE_DEC, VALS(mdnameformattypes), 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_length,
{ "MD Name Length", "cfm.maid.md.name.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_string,
{ "MD Name (String)", "cfm.maid.md.name.string", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_hex,
{ "MD Name", "cfm.maid.md.name.hex", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_mac,
{ "MD Name (MAC)", "cfm.maid.md.name.mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_md_name_mac_id,
{ "MD Name (MAC)", "cfm.maid.md.name.mac.id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_ma_name_format,
{ "Short MA Name (MEG ID) Format", "cfm.maid.ma.name.format", FT_UINT8,
BASE_DEC, VALS(manameformattypes), 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_ma_name_length,
{ "Short MA Name (MEG ID) Length", "cfm.maid.ma.name.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_ma_name_string,
{ "Short MA Name", "cfm.maid.ma.name.string", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_ma_name_hex,
{ "Short MA Name", "cfm.maid.ma.name.hex", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_maid_padding,
{ "Zero-Padding", "cfm.ccm.maid.padding", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ccm_itu_t_y1731,
{ "Defined by ITU-T Y.1731", "cfm.ccm.itu.t.y1731", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_itu_TxFCf,
{ "TxFCf", "cfm.itu.txfcf", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_itu_RxFCb,
{ "RxFCb", "cfm.itu.rxfcb", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_itu_TxFCb,
{ "TxFCb", "cfm.itu.txfcb", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_itu_reserved,
{ "Reserved", "cfm.itu.reserved", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lbm_pdu,
{ "CFM LBM PDU", "cfm.lbm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lb_transaction_id,
{ "Loopback Transaction Identifier", "cfm.lb.transaction.id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lbr_pdu,
{ "CFM LBR PDU", "cfm.lbr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ltm_pdu,
{ "CFM LTM PDU", "cfm.ltm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags_UseFDBonly,
{ "UseFDBonly", "cfm.flags.usefdbonly", FT_UINT8,
BASE_DEC, NULL, 0x80, NULL, HFILL }
},
{ &hf_cfm_flags_ltm_Reserved,
{ "Reserved", "cfm.flags.ltm.reserved", FT_UINT8,
BASE_DEC, NULL, 0x7F, NULL, HFILL }
},
{ &hf_cfm_lt_transaction_id,
{ "Linktrace Transaction Identifier", "cfm.lt.transaction.id", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lt_ttl,
{ "Linktrace TTL", "cfm.lt.ttl", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ltm_orig_addr,
{ "Linktrace Message: Original Address", "cfm.ltm.orig.addr", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ltm_targ_addr,
{ "Linktrace Message: Target Address", "cfm.ltm.targ.addr", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_ltr_pdu,
{ "CFM LTR PDU", "cfm.ltr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags_FwdYes,
{ "FwdYes", "cfm.flags.fwdyes", FT_UINT8,
BASE_DEC, NULL, 0x40, NULL, HFILL }
},
{ &hf_cfm_flags_TerminalMEP,
{ "TerminalMEP", "cfm.flags.ltr.terminalmep", FT_UINT8,
BASE_DEC, NULL, 0x20, NULL, HFILL }
},
{ &hf_cfm_flags_ltr_Reserved,
{ "Reserved", "cfm.flags.ltr.reserved", FT_UINT8,
BASE_DEC, NULL, 0x1F, NULL, HFILL }
},
{ &hf_cfm_ltr_relay_action,
{ "Linktrace Reply Relay Action", "cfm.ltr.relay.action", FT_UINT8,
BASE_DEC, VALS(relayactiontypes), 0x0, NULL, HFILL}
},
{ &hf_cfm_ais_pdu,
{ "CFM AIS PDU", "cfm.ais.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags_ais_lck_Reserved,
{ "Reserved", "cfm.flags.ais_lck_Reserved", FT_UINT8,
BASE_DEC, NULL, 0xF8, NULL, HFILL }
},
{ &hf_cfm_flags_ais_lck_Period,
{ "Period", "cfm.flags.ais_lck_Period", FT_UINT8,
BASE_DEC, VALS(aislckperiodtypes), 0x07, NULL, HFILL }
},
{ &hf_cfm_lck_pdu,
{ "CFM LCK PDU", "cfm.lck.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_tst_pdu,
{ "CFM TST PDU", "cfm.tst.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_flags_Reserved,
{ "Reserved", "cfm.flags.reserved", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_tst_sequence_num,
{ "Sequence Number", "cfm.tst.sequence.num", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_aps_pdu,
{ "CFM APS PDU", "cfm.aps.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_aps_req_st,
{ "Request/State", "cfm.raps.req.st", FT_UINT8,
BASE_DEC, VALS(aps_request_state_values), 0xf0, NULL, HFILL }
},
{ &hf_cfm_aps_protection_type_A,
{ "Protection type A", "cfm.aps.protec.type.A", FT_UINT8,
BASE_DEC, VALS(aps_protection_type_A_values), 0x08, NULL, HFILL }
},
{ &hf_cfm_aps_protection_type_B,
{ "Protection type B", "cfm.aps.protec.type.B", FT_UINT8,
BASE_DEC, VALS(aps_protection_type_B_values), 0x04, NULL, HFILL }
},
{ &hf_cfm_aps_protection_type_D,
{ "Protection type D", "cfm.aps.protec.type.D", FT_UINT8,
BASE_DEC, VALS(aps_protection_type_D_values), 0x02, NULL, HFILL }
},
{ &hf_cfm_aps_protection_type_R,
{ "Protection type R", "cfm.aps.protec.type.R", FT_UINT8,
BASE_DEC, VALS(aps_protection_type_R_values), 0x01, NULL, HFILL }
},
{ &hf_cfm_aps_requested_signal,
{ "Requested signal", "cfm.aps.req.sgnl", FT_UINT8,
BASE_HEX, VALS(aps_requested_signal_values), 0x0, NULL, HFILL }
},
{ &hf_cfm_aps_bridged_signal,
{ "Bridged signal", "cfm.aps.brdgd.sgnl", FT_UINT8,
BASE_HEX, VALS( aps_bridged_signal_values), 0x0, NULL, HFILL }
},
{ &hf_cfm_aps_bridge_type,
{ "Bridge type", "cfm.aps.bridge.type", FT_UINT8,
BASE_HEX, VALS( aps_bridge_type_values), 0x80, NULL, HFILL }
},
{ &hf_cfm_raps_pdu,
{ "CFM R-APS PDU", "cfm.raps.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_raps_req_st,
{ "Request/State", "cfm.raps.req.st", FT_UINT8,
BASE_HEX, VALS(rapsrequeststatevalues), 0xF0, NULL, HFILL }
},
{ &hf_cfm_raps_flags,
{ "R-APS Flags", "cfm.raps.flags", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_raps_flags_rb,
{ "RPL Blocked", "cfm.raps.flags.rb", FT_UINT8,
BASE_HEX, VALS(rapsrplblockedvalues), 0x80, NULL, HFILL }
},
{ &hf_cfm_raps_flags_dnf,
{ "Do Not Flush", "cfm.raps.flags.dnf", FT_UINT8,
BASE_HEX, VALS(rapsdnfvalues), 0x40, NULL, HFILL }
},
{ &hf_cfm_raps_node_id,
{ "R-APS Node ID", "cfm.raps.node.id", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_raps_reserved,
{ "R-APS Reserved", "cfm.raps.reserved", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_mcc_pdu,
{ "CFM MCC PDU", "cfm.mcc.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_mcc_data,
{ "MCC data", "cfm.mcc.data", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lmm_pdu,
{ "CFM LMM PDU", "cfm.lmm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lmm_lmr_TxFCf,
{ "TxFCf", "cfm.lmm.lmr.txfcf", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lmm_lmr_RxFCf,
{ "RxFCf", "cfm.lmm.lmr.rxfcf", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lmm_lmr_TxFCb,
{ "TxFCb", "cfm.lmm.lmr.txfcb", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_lmr_pdu,
{ "CFM LMR PDU", "cfm.lmr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_odm_pdu,
{ "CFM 1DM PDU", "cfm.odm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_odm_dmm_dmr_TxTimestampf,
{ "TxTimestampf", "cfm.odm.dmm.dmr.txtimestampf", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_odm_dmm_dmr_RxTimestampf,
{ "RxTimestampf", "cfm.odm.dmm.dmr.rxtimestampf", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_dmm_pdu,
{ "CFM DMM PDU", "cfm.dmm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_dmm_dmr_TxTimestampb,
{ "TxTimestampb", "cfm.dmm.dmr.txtimestampb", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_dmm_dmr_RxTimestampb,
{ "RxTimestampb", "cfm.dmm.dmr.rxtimestampb", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_dmr_pdu,
{ "CFM DMR PDU", "cfm.dmr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_exm_pdu,
{ "CFM EXM PDU", "cfm.exm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_exm_exr_data,
{ "EXM/EXR data", "cfm.exm_exr.data", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_exr_pdu,
{ "CFM EXR PDU", "cfm.exr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_vsm_pdu,
{ "CFM VSM PDU", "cfm.vsm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_vsm_vsr_data,
{ "VSM/VSR data", "cfm.vsm_vsr.data", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_vsr_pdu,
{ "CFM VSR PDU", "cfm.vsr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slm_pdu,
{ "CFM SLM PDU", "cfm.slm.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slr_pdu,
{ "CFM SLR PDU", "cfm.slr.pdu", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slm_src_mep,
{ "SrcMepID", "cfm.slm.src_mep_id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slr_rsp_mep,
{ "RspMepID", "cfm.slr.rsp_mep_id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slm_testid,
{ "TestID", "cfm.slm.test_id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slm_txfcf,
{ "TxFcF", "cfm.slm.txfcf", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_slr_txfcb,
{ "TxFcB", "cfm.slr.txfcb", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_all_tlvs,
{ "CFM TLVs", "cfm.all.tlvs", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_cfm_tlv_type,
{ "TLV Type", "cfm.tlv.type", FT_UINT8,
BASE_DEC, VALS(tlvtypefieldvalues), 0x0, NULL, HFILL}
},
{ &hf_cfm_tlv_length,
{ "TLV Length", "cfm.tlv.length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_chassis_id_length,
{ "Chassis ID Length", "cfm.tlv.chassis.id.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_chassis_id_subtype,
{ "Chassis ID Sub-type", "cfm.tlv.chassis.id.subtype", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_chassis_id,
{ "Chassis ID", "cfm.tlv.chassis.id", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_ma_domain_length,
{ "Management Address Domain Length", "cfm.tlv.ma.domain.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_ma_domain,
{ "Management Address Domain", "cfm.tlv.ma.domain", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_management_addr_length,
{ "Management Address Length", "cfm.tlv.management.addr.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_management_addr,
{ "Management Address", "cfm.tlv.management.addr", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_port_status_value,
{ "Port Status value", "cfm.tlv.port.status.value", FT_UINT8,
BASE_DEC, VALS(portstatTLVvalues), 0x0, NULL, HFILL}
},
{ &hf_tlv_data_value,
{ "Data Value", "cfm.tlv.data.value", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_interface_status_value,
{ "Interface Status value", "cfm.tlv.port.interface.value", FT_UINT8,
BASE_DEC, VALS(interfacestatTLVvalues), 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_ingress_action,
{ "Ingress Action", "cfm.tlv.reply.ingress.action", FT_UINT8,
BASE_DEC, VALS(replyingressTLVvalues), 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_ingress_mac_address,
{ "Ingress MAC address", "cfm.tlv.reply.ingress.mac.address", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_reply_ing_egr_portid_length,
{ "Chassis ID Length", "cfm.tlv.reply.ing.egr.portid.length", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_ing_egr_portid_subtype,
{ "Chassis ID Sub-type", "cfm.tlv.reply.ing.egr.portid.subtype", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_ing_egr_portid,
{ "Chassis ID", "cfm.tlv.reply.ing.egr.portid", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_egress_action,
{ "Egress Action", "cfm.tlv.reply.egress.action", FT_UINT8,
BASE_DEC, VALS(replyegressTLVvalues), 0x0, NULL, HFILL}
},
{ &hf_tlv_reply_egress_mac_address,
{ "Egress MAC address", "cfm.tlv.reply.egress.mac.address", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltm_egress_id_mac,
{ "Egress Identifier - MAC of LT Initiator/Responder", "cfm.tlv.ltm.egress.id.mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltm_egress_id_unique_identifier,
{ "Egress Identifier - Unique Identifier", "cfm.tlv.ltm.egress.id.ui", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltr_egress_last_id_mac,
{ "Last Egress Identifier - MAC address", "cfm.tlv.ltr.egress.last.id.mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltr_egress_last_id_unique_identifier,
{ "Last Egress Identifier - Unique Identifier", "cfm.tlv.ltr.egress.last.id.ui", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltr_egress_next_id_mac,
{ "Next Egress Identifier - MAC address", "cfm.tlv.ltr.egress.next.id.mac", FT_ETHER,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_ltr_egress_next_id_unique_identifier,
{ "Next Egress Identifier - Unique Identifier", "cfm.tlv.ltr.egress.next.id.ui", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_org_spec_oui,
{ "OUI", "cfm.tlv.org.spec.oui", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_org_spec_subtype,
{ "Sub-Type", "cfm.tlv.org.spec.subtype", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_org_spec_value,
{ "Value", "cfm.tlv.org.spec.value", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_tst_test_pattern_type,
{ "Test Pattern Type", "cfm.tlv.tst.test.pattern.type", FT_UINT8,
BASE_DEC, VALS(testTLVpatterntypes), 0x0, NULL, HFILL}
},
{ &hf_tlv_tst_test_pattern,
{ "Test Pattern", "cfm.tlv.tst.test.pattern", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_tlv_tst_CRC32,
{ "CRC-32", "cfm.tlv.tst.crc32", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_cfm,
&ett_cfm_flags,
&ett_cfm_ccm_maid,
&ett_cfm_ccm_itu,
&ett_cfm_pdu,
&ett_cfm_all_tlvs,
&ett_cfm_tlv,
&ett_cfm_raps_flags
};
proto_cfm = proto_register_protocol (
"CFM EOAM 802.1ag/ITU Protocol",
"CFM",
"cfm"
);
register_dissector("cfm", dissect_cfm, proto_cfm);
proto_register_field_array(proto_cfm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_cfm(void)
{
dissector_handle_t cfm_handle;
cfm_handle = create_dissector_handle(dissect_cfm, proto_cfm);
dissector_add_uint("ethertype", ETHERTYPE_CFM, cfm_handle);
}
