static void
dissect_gtpv2_unknown(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_imsi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
const gchar *imsi_str;
imsi_str = dissect_e212_imsi(tvb, pinfo, tree, offset, length, FALSE);
proto_item_append_text(item, "%s", imsi_str);
}
static void
dissect_gtpv2_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 tmp;
tmp = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s (%u)", val_to_str_ext_const(tmp, &gtpv2_cause_vals_ext, "Unknown"), tmp);
offset += 1;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_cause_pce, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_cause_bce, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_cause_cs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if ( length == 2 ) {
return;
}
proto_tree_add_item(tree, hf_gtpv2_cause_off_ie_t, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ie_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_half_octet, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_instance, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_recovery(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 recovery;
recovery = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_rec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", recovery);
}
static void
dissect_gtpv2_stn_sr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_item *stn_sr_item;
proto_tree *sub_tree;
tvbuff_t *new_tvb;
int offset = 0;
stn_sr_item = proto_tree_add_item(tree, hf_gtpv2_stn_sr, tvb, offset, length, ENC_NA);
new_tvb = tvb_new_subset_length(tvb, offset, length);
sub_tree = proto_item_add_subtree(stn_sr_item, ett_gtpv2_stn_sr);
dissect_gsm_map_msisdn(new_tvb, pinfo, sub_tree);
}
static void
dissect_gtpv2_src_tgt_trans_con(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_len_trans_con, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_transparent_container, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_tgt_src_trans_con(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_len_trans_con, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_transparent_container, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_mm_con_eutran_srvcc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 elm_len;
proto_tree *ms_tree, *fi;
proto_tree_add_item(tree, hf_gtpv2_eksi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_cksrvcc, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_iksrvcc, tvb, offset, 16, ENC_NA);
offset += 16;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark2, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_ms_mark);
de_ms_cm_2(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark3, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_ms_mark);
de_ms_cm_3(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_supp_codec_list, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_supported_codec_list, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_supp_codec_list);
de_sup_codec_list(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
}
static void
dissect_gtpv2_mm_con_utran_srvcc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 elm_len;
proto_tree *ms_tree, *fi;
proto_tree_add_item(tree, hf_gtpv2_ksi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_utran_srvcc_ck_cs, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_utran_srvcc_ik_cs, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_utran_srvcc_kc, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_gtpv2_cksn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark2, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_ms_mark);
de_ms_cm_2(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark3, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_ms_mark);
de_ms_cm_3(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_supp_codec_list, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
fi = proto_tree_add_item(tree, hf_gtpv2_supported_codec_list, tvb, offset, elm_len, ENC_NA);
ms_tree = proto_item_add_subtree(fi, ett_gtpv2_supp_codec_list);
de_sup_codec_list(tvb, ms_tree, pinfo, offset, elm_len, NULL, 0);
}
static void
dissect_gtpv2_srvcc_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 srvcc_cause;
srvcc_cause = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_srvcc_cause, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s (%u)", val_to_str_ext_const(srvcc_cause, &gtpv2_srvcc_cause_vals_ext, "Unknown"), srvcc_cause);
}
static void
dissect_gtpv2_tgt_rnc_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint16 rnc_id;
proto_tree *subtree;
guint32 mcc;
guint32 mnc;
guint32 lac;
guint32 curr_offset;
curr_offset = offset;
mcc = (tvb_get_guint8(tvb, curr_offset) & 0x0f) << 8;
mcc |= (tvb_get_guint8(tvb, curr_offset) & 0xf0);
mcc |= (tvb_get_guint8(tvb, curr_offset+1) & 0x0f);
mnc = (tvb_get_guint8(tvb, curr_offset+2) & 0x0f) << 8;
mnc |= (tvb_get_guint8(tvb, curr_offset+2) & 0xf0);
mnc |= (tvb_get_guint8(tvb, curr_offset+1) & 0xf0) >> 4;
if ((mnc & 0x000f) == 0x000f)
mnc = mnc >> 4;
lac = tvb_get_ntohs(tvb, curr_offset + 3);
rnc_id = tvb_get_ntohs(tvb, curr_offset + 5);
subtree = proto_tree_add_subtree_format(tree,
tvb, curr_offset, 6, ett_gtpv2_rai, NULL,
"Routing area identification: %x-%x-%u-%u",
mcc, mnc, lac, rnc_id);
dissect_e212_mcc_mnc(tvb, pinfo, subtree, offset, E212_RAI, TRUE);
curr_offset+=3;
proto_tree_add_item(subtree, hf_gtpv2_lac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset+=2;
proto_tree_add_item(subtree, hf_gtpv2_rnc_id, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_tgt_global_cell_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 tgt_cell_id;
proto_tree *subtree;
guint32 mcc;
guint32 mnc;
guint32 lac;
guint32 curr_offset;
curr_offset = offset;
mcc = (tvb_get_guint8(tvb, curr_offset) & 0x0f) << 8;
mcc |= (tvb_get_guint8(tvb, curr_offset) & 0xf0);
mcc |= (tvb_get_guint8(tvb, curr_offset+1) & 0x0f);
mnc = (tvb_get_guint8(tvb, curr_offset+2) & 0x0f) << 8;
mnc |= (tvb_get_guint8(tvb, curr_offset+2) & 0xf0);
mnc |= (tvb_get_guint8(tvb, curr_offset+1) & 0xf0) >> 4;
if ((mnc & 0x000f) == 0x000f)
mnc = mnc >> 4;
lac = tvb_get_ntohs(tvb, curr_offset + 3);
tgt_cell_id = tvb_get_guint8(tvb, curr_offset + 5);
subtree = proto_tree_add_subtree_format(tree,
tvb, curr_offset, 6, ett_gtpv2_rai, NULL,
"Routing area identification: %x-%x-%u-%u",
mcc, mnc, lac, tgt_cell_id);
dissect_e212_mcc_mnc(tvb, pinfo, subtree, offset, E212_RAI, TRUE);
proto_tree_add_item(subtree, hf_gtpv2_lac, tvb, curr_offset + 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gtpv2_tgt_g_cell_id, tvb, curr_offset + 5, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%x-%x-%u-%u", mcc, mnc, lac, tgt_cell_id);
}
static void
dissect_gtpv2_teid_c(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_teid_c, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (length > 4)
proto_tree_add_item(tree, hf_gtpv2_teid_c_spare, tvb, offset, length-4, ENC_NA);
proto_item_append_text(item, "%u", tvb_get_ntohl(tvb, offset-4));
}
static void
dissect_gtpv2_sv_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_sv_sti, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_sv_ics, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_sv_emind, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_teid_c_spare, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_sai(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_SAI, TRUE);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_sac, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_mm_ctx_for_cs_to_ps_srvcc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_ksi_ps, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gtpv2_ck_ps, tvb, offset, 16, ENC_NA);
offset+=16;
proto_tree_add_item(tree, hf_gtpv2_ik_ps, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_kc_ps, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, hf_gtpv2_cksn_ps, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_apn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 *apn = NULL;
int name_len, tmp;
if (length > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
apn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, length - 1, ENC_ASCII);
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + apn[tmp] + 1;
apn[tmp] = '.';
}
} else{
apn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
}
proto_tree_add_string(tree, hf_gtpv2_apn, tvb, offset, length, apn);
}
if (apn)
proto_item_append_text(item, "%s", apn);
}
static void
dissect_gtpv2_ambr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_ambr_up, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gtpv2_ambr_down, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_ebi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 ebi;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset, 4, ENC_BIG_ENDIAN);
ebi = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_ebi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", ebi);
}
static void
dissect_gtpv2_ip_address(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
if (length == 4)
{
proto_tree_add_item(tree, hf_gtpv2_ip_address_ipv4, tvb, offset, length, ENC_BIG_ENDIAN);
proto_item_append_text(item, "IPv4 %s", tvb_ip_to_str(tvb, offset));
}
else if (length == 16)
{
proto_tree_add_item(tree, hf_gtpv2_ip_address_ipv6, tvb, offset, length, ENC_NA);
proto_item_append_text(item, "IPv6 %s", tvb_ip6_to_str(tvb, offset));
}
}
static void
dissect_gtpv2_mei(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
const gchar *mei_str;
mei_str = tvb_bcd_dig_to_wmem_packet_str( tvb, 0, length, NULL, FALSE);
proto_tree_add_string(tree, hf_gtpv2_mei, tvb, offset, length, mei_str);
proto_item_append_text(item, "%s", mei_str);
}
static void
dissect_gtpv2_msisdn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
const char *digit_str;
digit_str = dissect_e164_msisdn(tvb, tree, 0, length, E164_ENC_BCD);
proto_item_append_text(item, "%s", digit_str);
}
static void
dissect_gtpv2_ind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_daf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_dtf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_hi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_dfi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_oi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_isrsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_israi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_sgwci, tvb, offset, 1, ENC_BIG_ENDIAN);
if (length == 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_len_invalid, tvb, 0, length, "Older version?, should be 2 octets in 8.0.0");
return;
}
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_sqci, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_uimsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_cfsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_crsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ps, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_pt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_si, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_msv, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length == 2) {
return;
}
proto_tree_add_item(tree, hf_gtpv2_retloc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_pbic, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_srni, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_s6af, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_s4af, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_mbmdt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_israu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ccrsi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length == 3) {
return;
}
proto_tree_add_item(tree, hf_gtpv2_cprai, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_arrl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ppof, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ppon_ppei, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ppsi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_csfbi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_clii, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_cpsr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length == 4) {
return;
}
proto_tree_add_item(tree, hf_gtpv2_pcri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_aosi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_aopi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length == 5) {
return;
}
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
static void
dissect_gtpv2_pco(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
switch (message_type) {
case GTPV2_CREATE_SESSION_REQUEST:
case GTPV2_DELETE_SESSION_REQUEST:
case GTPV2_BEARER_RESOURCE_COMMAND:
case GTPV2_CREATE_BEARER_RESPONSE:
case GTPV2_UPDATE_BEARER_RESPONSE:
case GTPV2_DELETE_BEARER_RESPONSE:
pinfo->link_dir = P2P_DIR_UL;
break;
case GTPV2_CREATE_SESSION_RESPONSE:
case GTPV2_MODIFY_BEARER_RESPONSE:
case GTPV2_DELETE_SESSION_RESPONSE:
case GTPV2_CREATE_BEARER_REQUEST:
case GTPV2_UPDATE_BEARER_REQUEST:
case GTPV2_DELETE_BEARER_REQUEST:
pinfo->link_dir = P2P_DIR_DL;
break;
default:
break;
}
de_sm_pco(tvb, tree, pinfo, 0, length, NULL, 0);
}
static void
dissect_gtpv2_paa(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 pdn_type;
pdn_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_pdn_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (pdn_type)
{
case 1:
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv6_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv6, tvb, offset, 16, ENC_NA);
break;
case 3:
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv6_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_pdn_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
dissect_gtpv2_bearer_qos(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_pvi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_pl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_pci, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_label_qci, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_mbr_up, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_mbr_down, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_gbr_up, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_bearer_qos_gbr_down, tvb, offset, 5, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_flow_qos(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_flow_qos_label_qci, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_flow_qos_mbr_up, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_flow_qos_mbr_down, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_flow_qos_gbr_up, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_gtpv2_flow_qos_gbr_down, tvb, offset, 5, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_rat_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint8 rat_type;
rat_type = tvb_get_guint8(tvb, 0);
proto_tree_add_item(tree, hf_gtpv2_rat_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s (%u)", val_to_str_ext_const(rat_type, &gtpv2_rat_type_vals_ext, "Unknown"), rat_type);
}
static void
dissect_gtpv2_serv_net(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
gchar *mcc_mnc_str;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, 0, E212_NONE, TRUE);
proto_item_append_text(item, "%s", mcc_mnc_str);
}
static void
dissect_gtpv2_bearer_tft(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
de_sm_tflow_temp(tvb, tree, pinfo, 0, length, NULL, 0);
}
static void
dissect_gtpv2_tad(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
de_sm_tflow_temp(tvb, tree, pinfo, 0, length, NULL, 0);
}
static gchar*
dissect_gtpv2_tai(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint16 tac;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_NONE, TRUE);
*offset += 3;
tac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_tai_tac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, TAC 0x%x",
mcc_mnc_str,
tac);
return str;
}
static gchar*
dissect_gtpv2_ecgi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint8 octet;
guint32 octet4;
guint8 spare;
guint32 ECGI;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_NONE, TRUE);
*offset += 3;
octet = tvb_get_guint8(tvb, *offset);
spare = octet & 0xF0;
octet4 = tvb_get_ntohl(tvb, *offset);
ECGI = octet4 & 0x0FFFFFFF;
proto_tree_add_uint(tree, hf_gtpv2_ecgi_eci_spare, tvb, *offset, 1, spare);
proto_tree_add_uint(tree, hf_gtpv2_ecgi_eci, tvb, *offset, 4, ECGI);
*offset += 4;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, ECGI 0x%x",
mcc_mnc_str,
ECGI);
return str;
}
static gchar*
dissect_gtpv2_rai(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint16 lac, rac;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_RAI, TRUE);
*offset += 3;
lac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_rai_lac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
rac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_rai_rac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, LAC 0x%x, RAC 0x%x",
mcc_mnc_str,
lac,
rac);
return str;
}
static gchar*
dissect_gtpv2_sai_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint16 lac, sac;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_SAI, TRUE);
*offset += 3;
lac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_sai_lac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
sac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_sai_sac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, LAC 0x%x, SAC 0x%x",
mcc_mnc_str,
lac,
sac);
return str;
}
static gchar*
dissect_gtpv2_cgi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint16 lac, ci;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_NONE, TRUE);
*offset += 3;
lac = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_uli_cgi_lac, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
ci = tvb_get_ntohs(tvb, *offset);
proto_tree_add_item(tree, hf_gtpv2_uli_cgi_ci, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, LAC 0x%x, CI 0x%x",
mcc_mnc_str,
lac,
ci);
return str;
}
static gchar*
decode_gtpv2_uli(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length, guint8 instance _U_, guint flags)
{
int offset = 1;
proto_tree *part_tree;
gchar *mcc_mnc_str;
gchar *str = NULL;
if (flags & GTPv2_ULI_CGI_MASK)
{
proto_item_append_text(item, "CGI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 7,
ett_gtpv2_uli_field, NULL, "Cell Global Identity (CGI)");
str = dissect_gtpv2_cgi(tvb, pinfo, part_tree, &offset);
if (offset == length)
return str;
}
if (flags & GTPv2_ULI_SAI_MASK)
{
proto_item_append_text(item, "SAI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 7,
ett_gtpv2_uli_field, NULL, "Service Area Identity (SAI)");
str = dissect_gtpv2_sai_common(tvb, pinfo, part_tree, &offset);
if (offset == length)
return str;
}
if (flags & GTPv2_ULI_RAI_MASK)
{
proto_item_append_text(item, "RAI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 7,
ett_gtpv2_uli_field, NULL, "Routeing Area Identity (RAI)");
str = dissect_gtpv2_rai(tvb, pinfo, part_tree, &offset);
if (offset == length)
return str;
}
if (flags & GTPv2_ULI_TAI_MASK)
{
proto_item_append_text(item, "TAI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 5,
ett_gtpv2_uli_field, NULL, "Tracking Area Identity (TAI)");
str = dissect_gtpv2_tai(tvb, pinfo, part_tree, &offset);
if (offset == length)
return str;
}
if (flags & GTPv2_ULI_ECGI_MASK)
{
proto_item_append_text(item, "ECGI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 7,
ett_gtpv2_uli_field, NULL, "E-UTRAN Cell Global Identifier (ECGI)");
str = dissect_gtpv2_ecgi(tvb, pinfo, part_tree, &offset);
if (offset == length)
return str;
}
if (flags & GTPv2_ULI_LAI_MASK)
{
guint16 lac;
proto_item_append_text(item, "LAI ");
part_tree = proto_tree_add_subtree(tree, tvb, offset, 5,
ett_gtpv2_uli_field, NULL, "LAI (Location Area Identifier)");
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, part_tree, offset, E212_LAI, TRUE);
offset += 3;
proto_tree_add_item(part_tree, hf_gtpv2_uli_lai_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
lac = tvb_get_ntohs(tvb, offset);
str = wmem_strdup_printf(wmem_packet_scope(), "%s, LAC 0x%x",
mcc_mnc_str,
lac);
}
return str;
}
static void
dissect_gtpv2_uli(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
int offset = 0;
guint flags;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_gtpv2_uli_flags, NULL, "Flags");
flags = tvb_get_guint8(tvb, offset) & 0x3f;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, offset >> 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_lai_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_ecgi_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_tai_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_rai_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_sai_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_uli_cgi_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
decode_gtpv2_uli(tvb, pinfo, tree, item, length, instance, flags);
return;
}
static int
dissect_diameter_3gpp_uli(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
diam_sub_dis_t *diam_sub_dis = (diam_sub_dis_t*)data;
int offset = 0;
guint length;
guint flags;
guint flags_3gpp;
length = tvb_reported_length(tvb);
flags_3gpp = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_glt, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (flags_3gpp)
{
case 0:
flags = GTPv2_ULI_CGI_MASK;
break;
case 1:
flags = GTPv2_ULI_SAI_MASK;
break;
case 2:
flags = GTPv2_ULI_RAI_MASK;
break;
case 128:
flags = GTPv2_ULI_TAI_MASK;
break;
case 129:
flags = GTPv2_ULI_ECGI_MASK;
break;
case 130:
flags = GTPv2_ULI_TAI_MASK + GTPv2_ULI_ECGI_MASK;
break;
default:
proto_tree_add_item(tree, hf_gtpv2_geographic_location, tvb, 1, -1, ENC_NA);
return length;
}
diam_sub_dis->avp_str = decode_gtpv2_uli(tvb, pinfo, tree, NULL, length, 0, flags);
return length;
}
static void
dissect_gtpv2_f_teid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 flags;
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_f_teid_v4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_f_teid_v6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_f_teid_interface_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_f_teid_gre_key, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s, TEID/GRE Key: 0x%s",
val_to_str_ext_const((flags & 0x3f), &gtpv2_f_teid_interface_type_vals_ext, "Unknown"),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 4));
offset += 4;
if (flags & 0x80)
{
proto_tree_add_item(tree, hf_gtpv2_f_teid_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, ", IPv4 %s", tvb_ip_to_str(tvb, offset));
offset += 4;
}
if (flags & 0x40)
{
proto_tree_add_item(tree, hf_gtpv2_f_teid_ipv6, tvb, offset, 16, ENC_NA);
proto_item_append_text(item, ", IPv6 %s", tvb_ip6_to_str(tvb, offset));
}
}
static void
dissect_gtpv2_tmsi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_tmsi, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(item, hf_gtpv2_tmsi_bytes, tvb, 0, length, ENC_NA);
}
static void
dissect_gtpv2_g_cn_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
dissect_e212_mcc_mnc(tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_cn_id, tvb, offset, 2, ENC_NA);
}
static void
dissect_gtpv2_s103pdf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 m, k, i;
m = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_hsgw_addr_f_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (m) {
case 4:
proto_tree_add_item(tree, hf_gtpv2_hsgw_addr_ipv4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
break;
case 16:
proto_tree_add_item(tree, hf_gtpv2_hsgw_addr_ipv6, tvb, offset, 1, ENC_NA);
offset += 16;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_len_invalid, tvb, 0, length,
"Wrong length %u, should be 4 or 16", m);
return;
}
proto_tree_add_item(tree, hf_gtpv2_gre_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
k = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_eps_bearer_id_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for ( i = 0; i < k; i++ ) {
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ebi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
static void
dissect_gtpv2_s1udf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 m;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ebi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
m = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_serving_gw_address_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (m) {
case 4:
proto_tree_add_item(tree, hf_gtpv2_sgw_addr_ipv4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
break;
case 16:
proto_tree_add_item(tree, hf_gtpv2_sgw_addr_ipv6, tvb, offset, 1, ENC_NA);
offset += 16;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_len_invalid, tvb, 0, length,
"Wrong length %u, should be 4 or 16", m);
return;
}
proto_tree_add_item(tree, hf_gtpv2_sgw_s1u_teid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_delay_value(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_delay_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_bearer_ctx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
tvbuff_t *new_tvb;
proto_tree *grouped_tree;
proto_item_append_text(item, "[Grouped IE]");
grouped_tree = proto_item_add_subtree(item, ett_gtpv2_bearer_ctx);
new_tvb = tvb_new_subset_length(tvb, offset, length);
dissect_gtpv2_ie_common(new_tvb, pinfo, grouped_tree, 0, message_type);
}
static void
dissect_gtpv2_charging_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_charging_id, tvb, offset, length, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_char_char(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_charging_characteristic, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length > 2) {
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_charging_characteristic_remaining_octets, tvb, offset, length-2, ENC_NA);
}
}
static void
dissect_gtpv2_bearer_flag(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_bearer_flag_ppc, tvb, offset, length, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_bearer_flag_vb, tvb, offset, length, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_pdn_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 pdn;
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_len_invalid, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 5, ENC_BIG_ENDIAN);
pdn = tvb_get_guint8(tvb, offset)& 0x7;
proto_tree_add_item(tree, hf_gtpv2_pdn_type, tvb, offset, length, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str_const(pdn, gtpv2_pdn_type_vals, "Unknown"));
}
static void
dissect_gtpv2_tra_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *trigg_tree, *msc_server_tree, *mgw_tree, *sgsn_tree, *ggsn_tree;
proto_tree *bm_sc_tree, *sgw_mme_tree, *sgw_tree, *pgw_tree, *ne_types_tree;
proto_tree *interfaces_tree, *imsc_server_tree, *lmgw_tree, *lsgsn_tree, *lggsn_tree, *lrnc_tree;
proto_tree *lbm_sc_tree, *lmme_tree, *lsgw_tree, *lpdn_gw_tree, *lenb_tree;
int offset = 0;
#if 0
guint8 *trace_id = NULL;
#endif
guint16 tid;
guint32 bit_offset;
dissect_e212_mcc_mnc(tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
tid = tvb_get_ntohs(tvb, offset);
proto_item_append_text(item, "Trace ID: %d ", tid);
proto_tree_add_item(tree, hf_gtpv2_trace_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
trigg_tree = proto_tree_add_subtree(tree, tvb, offset, 9, ett_gtpv2_tra_info_trigg, NULL, "Triggering Events");
msc_server_tree = proto_tree_add_subtree(trigg_tree, tvb, offset, 2, ett_gtpv2_tra_info_trigg_msc_server, NULL, "MSC Server");
mgw_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 2, 1, ett_gtpv2_tra_info_trigg_mgw, NULL, "MGW");
sgsn_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 3, 2, ett_gtpv2_tra_info_trigg_sgsn, NULL, "SGSN");
ggsn_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 5, 1, ett_gtpv2_tra_info_trigg_ggsn, NULL, "GGSN");
bm_sc_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 6, 1, ett_gtpv2_tra_info_trigg_bm_sc, NULL, "BM-SC");
sgw_mme_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 7, 1, ett_gtpv2_tra_info_trigg_sgw_mme, NULL, "SGW MME");
sgw_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 8, 1, ett_gtpv2_tra_info_trigg_sgw, NULL, "SGW");
pgw_tree = proto_tree_add_subtree(trigg_tree, tvb, offset + 8, 1, ett_gtpv2_tra_info_trigg_pgw, NULL, "PGW");
proto_tree_add_item(msc_server_tree, hf_gtpv2_tra_info_msc_momt_calls, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msc_server_tree, hf_gtpv2_tra_info_msc_momt_sms, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msc_server_tree, hf_gtpv2_tra_info_msc_lu_imsi_ad, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msc_server_tree, hf_gtpv2_tra_info_msc_handovers, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msc_server_tree, hf_gtpv2_tra_info_msc_ss, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(msc_server_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
offset += 1;
bit_offset = offset << 3;
proto_tree_add_bits_item(msc_server_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mgw_tree, hf_gtpv2_tra_info_mgw_context, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(mgw_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sgsn_tree, hf_gtpv2_tra_info_sgsn_pdp_context, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgsn_tree, hf_gtpv2_tra_info_sgsn_momt_sms, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgsn_tree, hf_gtpv2_tra_info_sgsn_rau_gprs_ad, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgsn_tree, hf_gtpv2_tra_info_sgsn_mbms, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(sgsn_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sgsn_tree, hf_gtpv2_tra_info_sgsn_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ggsn_tree, hf_gtpv2_tra_info_ggsn_pdp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ggsn_tree, hf_gtpv2_tra_info_ggsn_mbms, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(ggsn_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(bm_sc_tree, hf_gtpv2_tra_info_bm_sc, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(bm_sc_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_ss, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_sr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_iataud, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_ue_init_pdn_disc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_bearer_act_mod_del, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_mme_tree, hf_gtpv2_tra_info_mme_sgw_ho, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(sgw_mme_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sgw_tree, hf_gtpv2_tra_info_sgw_pdn_con_creat, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_tree, hf_gtpv2_tra_info_sgw_pdn_con_term, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sgw_tree, hf_gtpv2_tra_info_sgw_bearer_act_mod_del, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = (offset << 3) + 4;
proto_tree_add_bits_item(sgw_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pgw_tree, hf_gtpv2_tra_info_pgw_pdn_con_creat, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pgw_tree, hf_gtpv2_tra_info_pgw_pdn_con_term, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pgw_tree, hf_gtpv2_tra_info_pgw_bearer_act_mod_del, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(pgw_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ne_types_tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_gtpv2_tra_info_ne_types, NULL, "List of NE Types");
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_msc_s, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_mgw, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_sgsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_ggsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_rnc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_bm_sc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_mme, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_sgw, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_pdn_gw, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ne_types_tree, hf_gtpv2_tra_info_lne_enb, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(ne_types_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_tra_info_tdl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
interfaces_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_gtpv2_tra_info_interfaces, NULL, "List of Interfaces");
imsc_server_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset, 2, ett_gtpv2_tra_info_interfaces_imsc_server, NULL, "MSC Server");
lmgw_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 2, 1, ett_gtpv2_tra_info_interfaces_lmgw, NULL, "MGW");
lsgsn_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 3, 2, ett_gtpv2_tra_info_interfaces_lsgsn, NULL, "SGSN");
lggsn_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 5, 1, ett_gtpv2_tra_info_interfaces_lggsn, NULL, "GGSN");
lrnc_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 6, 1, ett_gtpv2_tra_info_interfaces_lrnc, NULL, "RNC");
lbm_sc_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 7, 1, ett_gtpv2_tra_info_interfaces_lbm_sc, NULL, "BM-SC");
lmme_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 8, 1, ett_gtpv2_tra_info_interfaces_lmme, NULL, "MME");
lsgw_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 9, 1,ett_gtpv2_tra_info_interfaces_lsgw, NULL, "SGW");
lpdn_gw_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 10, 1, ett_gtpv2_tra_info_interfaces_lpdn_gw, NULL, "PDN GW");
lenb_tree = proto_tree_add_subtree(interfaces_tree, tvb, offset + 11, 1, ett_gtpv2_tra_info_interfaces_lpdn_lenb, NULL, "eNB");
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_lu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_mc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_g, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_e, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_f, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_cap, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_d, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(imsc_server_tree, hf_gtpv2_tra_info_lmsc_map_c, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(imsc_server_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lmgw_tree, hf_gtpv2_tra_info_lmgw_mc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmgw_tree, hf_gtpv2_tra_info_lmgw_nb_up, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmgw_tree, hf_gtpv2_tra_info_lmgw_lu_up, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lmgw_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_gb, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_lu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_gn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_map_gr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_map_gd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_map_gf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_gs, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgsn_tree, hf_gtpv2_tra_info_lsgsn_ge, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
bit_offset = offset << 3;
proto_tree_add_bits_item(lsgsn_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lggsn_tree, hf_gtpv2_tra_info_lggsn_gn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lggsn_tree, hf_gtpv2_tra_info_lggsn_gi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lggsn_tree, hf_gtpv2_tra_info_lggsn_gmb, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lggsn_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lrnc_tree, hf_gtpv2_tra_info_lrnc_lu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lrnc_tree, hf_gtpv2_tra_info_lrnc_lur, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lrnc_tree, hf_gtpv2_tra_info_lrnc_lub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lrnc_tree, hf_gtpv2_tra_info_lrnc_uu, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lrnc_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lbm_sc_tree, hf_gtpv2_tra_info_lbm_sc_gmb, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lbm_sc_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lmme_tree, hf_gtpv2_tra_info_lmme_s1_mme, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmme_tree, hf_gtpv2_tra_info_lmme_s3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmme_tree, hf_gtpv2_tra_info_lmme_s6a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmme_tree, hf_gtpv2_tra_info_lmme_s10, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lmme_tree, hf_gtpv2_tra_info_lmme_s11, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lmme_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lsgw_tree, hf_gtpv2_tra_info_lsgw_s4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgw_tree, hf_gtpv2_tra_info_lsgw_s5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgw_tree, hf_gtpv2_tra_info_lsgw_s8b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lsgw_tree, hf_gtpv2_tra_info_lsgw_s11, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lsgw_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s2a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s2b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s2c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s6c, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_gx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_s8b, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lpdn_gw_tree, hf_gtpv2_tra_info_lpdn_gw_sgi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lenb_tree, hf_gtpv2_tra_info_lenb_s1_mme, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lenb_tree, hf_gtpv2_tra_info_lenb_x2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lenb_tree, hf_gtpv2_tra_info_lenb_uu, tvb, offset, 1, ENC_BIG_ENDIAN);
bit_offset = offset << 3;
proto_tree_add_bits_item(lenb_tree, hf_gtpv2_spare_bits, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
while ( (offset + 4) <= length ) {
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ipv4_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 3;
}
}
static void
dissect_gtpv2_pti(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_pti, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_drx_param(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_drx_parameter, tvb, offset, length, ENC_NA);
}
static void
dissect_gtpv2_ue_net_capability(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
de_emm_ue_net_cap(tvb, tree, pinfo, 0, length, NULL, 0);
}
static int
dissect_gtpv2_authentication_triplets(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 num_triplet)
{
proto_tree *auth_tri_tree;
int i;
for (i = 0; i < num_triplet; i++) {
auth_tri_tree = proto_tree_add_subtree_format(tree, tvb, offset, 0,
ett_gtpv2_mm_context_auth_tri, NULL, "Authentication Triplet %u", i);
proto_tree_add_item(auth_tri_tree, hf_gtpv2_mm_context_rand, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(auth_tri_tree, hf_gtpv2_mm_context_sres, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(auth_tri_tree, hf_gtpv2_mm_context_kc, tvb, offset, 8, ENC_NA);
offset += 8;
}
return offset;
}
static int
dissect_gtpv2_authentication_quintuplets(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 nr_qui)
{
proto_tree *auth_qui_tree;
int i;
guint8 xres_len, autn_len;
for (i = 0; i < nr_qui; i++) {
auth_qui_tree = proto_tree_add_subtree_format(tree, tvb, offset, 0,
ett_gtpv2_mm_context_auth_qui, NULL, "Authentication Quintuplet %u", i);
proto_tree_add_item(auth_qui_tree, hf_gtpv2_mm_context_rand, tvb, offset, 16, ENC_NA);
offset += 16;
xres_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(auth_qui_tree, hf_gtpv2_mm_context_xres_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(auth_qui_tree, hf_gtpv2_mm_context_xres, tvb, offset, xres_len, ENC_NA);
offset += xres_len;
proto_tree_add_item(auth_qui_tree, hf_gtpv2_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(auth_qui_tree, hf_gtpv2_ik, tvb, offset, 16, ENC_NA);
offset += 16;
autn_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(auth_qui_tree, hf_gtpv2_mm_context_autn_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(auth_qui_tree, hf_gtpv2_mm_context_autn, tvb, offset, autn_len, ENC_NA);
offset += autn_len;
}
return offset;
}
static int
dissect_gtpv2_authentication_quadruplets(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 nr_qui)
{
proto_tree *auth_qua_tree;
guint8 tmp;
int i;
for (i = 0; i < nr_qui; i++) {
auth_qua_tree = proto_tree_add_subtree(tree, tvb, offset, 0,
ett_gtpv2_mm_context_auth_qua, NULL, "Authentication Quadruplet");
proto_tree_add_item(auth_qua_tree, hf_gtpv2_mm_context_rand, tvb, offset, 16, ENC_NA);
offset += 16;
tmp = tvb_get_guint8(tvb, offset++);
proto_tree_add_item(auth_qua_tree, hf_gtpv2_mm_context_xres, tvb, offset, tmp, ENC_NA);
offset += tmp;
tmp = tvb_get_guint8(tvb, offset++);
proto_tree_add_item(auth_qua_tree, hf_gtpv2_mm_context_autn, tvb, offset, tmp, ENC_NA);
offset += tmp;
proto_tree_add_item(tree, hf_gtpv2_mm_context_kasme, tvb, offset, 32, ENC_NA);
offset += 32;
}
return offset;
}
static int
dissect_gtpv2_mm_context_common_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint8 samb_ri, guint8 uamb_ri)
{
proto_tree *net_cap_tree, *msnt_cap_tree;
guint8 ue_net_cap_len, ms_net_cap_len, mei_len;
guint32 tmp;
if (samb_ri) {
tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_uplink_subscribed_ue_ambr, tvb, offset, 4, tmp, "%d Kbps", tmp);
offset += 4;
tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_downlink_subscribed_ue_ambr, tvb, offset, 4, tmp, "%d Kbps", tmp);
offset += 4;
}
if (uamb_ri) {
tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_uplink_used_ue_ambr, tvb, offset, 4, tmp, "%d Kbps", tmp);
offset += 4;
tmp = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_downlink_used_ue_ambr, tvb, offset, 4, tmp, "%d Kbps", tmp);
offset += 4;
}
ue_net_cap_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_ue_net_cap_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (ue_net_cap_len) {
net_cap_tree = proto_tree_add_subtree(tree, tvb, offset, ue_net_cap_len,
ett_gtpv2_mm_context_net_cap, NULL, "UE Network Capability");
offset += de_emm_ue_net_cap(tvb, net_cap_tree, pinfo, offset, ue_net_cap_len, NULL, 0);
}
ms_net_cap_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_ms_net_cap_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (ms_net_cap_len) {
msnt_cap_tree = proto_tree_add_subtree(tree, tvb, offset, ms_net_cap_len,
ett_gtpv2_ms_network_capability, NULL, "MS network capability");
offset += de_gmm_ms_net_cap(tvb, msnt_cap_tree, pinfo, offset, ms_net_cap_len, NULL, 0);
}
mei_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_mei_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (mei_len) {
const gchar *mei_str;
mei_str = tvb_bcd_dig_to_wmem_packet_str( tvb, offset, mei_len, NULL, FALSE);
proto_tree_add_string(tree, hf_gtpv2_mei, tvb, offset, mei_len, mei_str);
offset += mei_len;
}
return offset;
}
static int
dissect_gtpv2_access_restriction_data(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *accrstdata_tree;
accrstdata_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_gtpv2_access_rest_data, NULL, "Access restriction data");
proto_tree_add_bits_item(accrstdata_tree, hf_gtpv2_spare_bits, tvb, (offset << 3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_hnna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_ena, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_ina, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_gana, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_gena, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(accrstdata_tree, hf_gtpv2_una, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
dissect_gtpv2_mm_context_gsm_t(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
int offset;
guint8 oct, drxi, num_triplet, uamb_ri, samb_ri;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
drxi = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, offset << 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_cksn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
oct = tvb_get_guint8(tvb, offset);
num_triplet = oct >> 5;
uamb_ri = (oct & 0x02) >> 1;
samb_ri = oct & 0x01;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_tri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, (offset << 3) + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, (offset << 3) + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3)), 5, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_used_cipher, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mm_context_kc, tvb, offset, 8, ENC_NA);
offset += 8;
if (num_triplet) {
dissect_gtpv2_authentication_triplets(tvb, tree, offset, num_triplet);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
proto_tree_add_expert_format(flag_tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
static void
dissect_gtpv2_mm_context_utms_cq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
int offset;
guint8 oct, drxi, nr_qui, uamb_ri, samb_ri, vdp_len, hbr_len;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
drxi = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3) + 3), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_cksn_ksi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
oct = tvb_get_guint8(tvb, offset);
nr_qui = oct >> 5;
uamb_ri = (oct & 0x02) >> 1;
samb_ri = oct & 0x01;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, (offset << 3) + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, (offset << 3) + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3)), 5, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_used_cipher, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_ik, tvb, offset, 16, ENC_NA);
offset += 16;
if (nr_qui) {
offset = dissect_gtpv2_authentication_quintuplets(tvb, tree, offset, nr_qui);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
if (offset < (gint)length) {
offset = dissect_gtpv2_access_restriction_data(tvb, tree, offset);
} else {
return;
}
if (offset == (gint)length) {
return;
}
vdp_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_vdp_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (vdp_len) {
proto_tree_add_item(tree, hf_gtpv2_voice_domain_and_ue_usage_setting, tvb, offset, vdp_len, ENC_NA);
offset += vdp_len;
}
if (offset == (gint)length) {
hbr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (hbr_len) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += hbr_len;
}
} else {
return;
}
proto_tree_add_expert_format(flag_tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
static void
dissect_gtpv2_mm_context_gsm_cq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
int offset;
guint8 oct, drxi, nr_qui, uamb_ri, samb_ri, vdp_len, hbr_len;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
drxi = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3) + 3), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_cksn_ksi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
oct = tvb_get_guint8(tvb, offset);
nr_qui = oct >> 5;
uamb_ri = (oct & 0x02) >> 1;
samb_ri = oct & 0x01;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, (offset << 3) + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, (offset << 3) + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3)), 5, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_used_cipher, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mm_context_kc, tvb, offset, 8, ENC_NA);
offset += 8;
if (nr_qui) {
offset = dissect_gtpv2_authentication_quintuplets(tvb, tree, offset, nr_qui);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
if (offset < (gint)length) {
offset = dissect_gtpv2_access_restriction_data(tvb, tree, offset);
} else {
return;
}
if (offset == (gint)length) {
return;
}
vdp_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_vdp_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (vdp_len) {
proto_tree_add_item(tree, hf_gtpv2_voice_domain_and_ue_usage_setting, tvb, offset, vdp_len, ENC_NA);
offset += vdp_len;
}
if (offset < (gint)length) {
hbr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (hbr_len) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += hbr_len;
}
} else {
return;
}
proto_tree_add_expert_format(flag_tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
static void
dissect_gtpv2_mm_context_utms_q(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
int offset;
guint8 oct, drxi, nr_qui, uamb_ri, samb_ri, vdp_len, hbr_len;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3) + 3), 1, ENC_BIG_ENDIAN);
drxi = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_ksi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
oct = tvb_get_guint8(tvb, offset);
nr_qui = oct >> 5;
uamb_ri = (oct & 0x02) >> 1;
samb_ri = oct & 0x01;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, (offset << 3) + 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, (offset << 3) + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(flag_tree, hf_gtpv2_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_ik, tvb, offset, 16, ENC_NA);
offset += 16;
if (nr_qui) {
offset = dissect_gtpv2_authentication_quintuplets(tvb, tree, offset, nr_qui);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
if (offset < (gint)length) {
offset = dissect_gtpv2_access_restriction_data(tvb, tree, offset);
} else {
return;
}
if (offset == (gint)length) {
return;
}
vdp_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_vdp_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (vdp_len) {
proto_tree_add_item(tree, hf_gtpv2_voice_domain_and_ue_usage_setting, tvb, offset, vdp_len, ENC_NA);
offset += vdp_len;
}
if (offset < (gint)length) {
hbr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (hbr_len) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_higher_br_16mb_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += hbr_len;
}
} else {
return;
}
proto_tree_add_expert_format(flag_tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
static void
dissect_gtpv2_mm_context_eps_qq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_item *qua_item, *qui_item;
proto_tree *flag_tree, *qua_tree, *qui_tree;
gint offset;
guint8 tmp, nhi, drxi, nr_qua, nr_qui, uamb_ri, samb_ri, vdp_len;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nhi, tvb, offset, 1, ENC_BIG_ENDIAN);
tmp = tvb_get_guint8(tvb, offset);
nhi = (tmp & 0x10) >> 4;
drxi = (tmp & 0x08) >> 3;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_ksi_a, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tmp = tvb_get_guint8(tvb, offset);
nr_qui = (tmp & 0xe0) >> 5;
nr_qua = tmp & 0x1c;
nr_qua >>= 2;
uamb_ri = (tmp & 0x2) >> 1;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qua, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_osci, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
samb_ri = tvb_get_guint8(tvb, offset) >> 7;
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, offset << 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_unipa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_unc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mm_context_nas_dl_cnt, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_mm_context_nas_ul_cnt, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_mm_context_kasme, tvb, offset, 32, ENC_NA);
offset += 32;
qua_item = proto_tree_add_uint(tree, hf_gtpv2_authentication_quadruplets, tvb, offset, 0, nr_qua);
if ( nr_qua ){
qua_tree = proto_item_add_subtree(qua_item, ett_gtpv2_qua);
offset = dissect_gtpv2_authentication_quadruplets(tvb, qua_tree, offset, nr_qua);
}else {
PROTO_ITEM_SET_GENERATED(qua_item);
}
qui_item = proto_tree_add_uint(tree, hf_gtpv2_authentication_quintuplets, tvb, offset, 0, nr_qui);
if (nr_qui) {
qui_tree = proto_item_add_subtree(qui_item, ett_gtpv2_qui);
offset = dissect_gtpv2_authentication_quintuplets(tvb, qui_tree, offset, nr_qui);
}else{
PROTO_ITEM_SET_GENERATED(qui_item);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if ( nhi )
{
proto_tree_add_item(tree, hf_gtpv2_mm_context_nh, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_gtpv2_mm_context_ncc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
if (offset < (gint)length) {
offset = dissect_gtpv2_access_restriction_data(tvb, tree, offset);
} else {
return;
}
if (offset == (gint)length) {
return;
}
vdp_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_mm_context_vdp_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (vdp_len) {
proto_tree_add_item(tree, hf_gtpv2_voice_domain_and_ue_usage_setting, tvb, offset, vdp_len, ENC_NA);
}
}
static void
dissect_gtpv2_mm_context_utms_qq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree *flag_tree;
guint32 offset;
guint8 tmp, drxi, nr_qua, nr_qui, uamb_ri, samb_ri, vdp_length;
offset = 0;
flag_tree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_gtpv2_mm_context_flag, NULL, "MM Context flags");
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_sm, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_spare_bits, tvb, ((offset << 3) + 3), 1, ENC_BIG_ENDIAN);
drxi = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_drxi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_ksi_a, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tmp = tvb_get_guint8(tvb, offset);
nr_qui = (tmp & 0xe0) >> 5;
nr_qua = tmp & 0x1c;
nr_qua >>= 2;
uamb_ri = (tmp & 0x2) >> 1;
samb_ri = tmp & 0x01;
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_nr_qua, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_gtpv2_mm_context_uamb_ri, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(flag_tree, hf_gtpv2_mm_context_samb_ri, tvb, (offset << 3) + 7, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(flag_tree, hf_gtpv2_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ck, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_gtpv2_ik, tvb, offset, 16, ENC_NA);
offset += 16;
if ( nr_qua ) {
offset = dissect_gtpv2_authentication_quadruplets(tvb, tree, offset, nr_qua);
}
if (nr_qui) {
offset = dissect_gtpv2_authentication_quintuplets(tvb, tree, offset, nr_qui);
}
if (drxi) {
proto_tree_add_item(tree, hf_gtpv2_mm_context_drx, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
offset = dissect_gtpv2_mm_context_common_data(tvb, pinfo, tree, offset, samb_ri, uamb_ri);
if (offset >= (guint32)length) {
return;
}
offset = dissect_gtpv2_access_restriction_data(tvb, tree, offset);
if (offset >= (guint32)length) {
return;
}
vdp_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_vdp_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(vdp_length !=0){
offset += de_gmm_voice_domain_pref(tvb, tree, pinfo, offset, vdp_length, NULL, 0);
}
if (offset < (guint32)length) {
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, -1, "The rest of the IE not dissected yet");
}
}
static void
dissect_gtpv2_PDN_conn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree *grouped_tree;
tvbuff_t *new_tvb;
proto_item_append_text(item, "[Grouped IE]");
grouped_tree = proto_item_add_subtree(item, ett_gtpv2_PDN_conn);
new_tvb = tvb_new_subset_length(tvb, offset, length);
dissect_gtpv2_ie_common(new_tvb, pinfo, grouped_tree, offset, message_type);
}
static void
dissect_gtpv2_pdn_numbers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_item *nsapi_ti;
proto_tree *nsapi_tree;
guint8 nsapi;
int offset = 0;
nsapi = (tvb_get_guint8(tvb, offset) & 0x08);
nsapi_ti = proto_tree_add_item(tree, hf_gtpv2_nsapi08, tvb, offset, 1, ENC_BIG_ENDIAN);
nsapi_tree = proto_item_add_subtree(nsapi_ti, ett_gtpv2_pdn_numbers_nsapi);
proto_tree_add_bits_item(nsapi_tree, hf_gtpv2_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nsapi_tree, hf_gtpv2_pdn_numbers_nsapi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "NSAPI: %u", nsapi);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_dl_gtp_u_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_ul_gtp_u_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_send_n_pdu_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_receive_n_pdu_number, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_p_tmsi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_p_tmsi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 4));
}
static void
dissect_gtpv2_p_tmsi_sig(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_p_tmsi_sig, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 3));
}
static void
dissect_gtpv2_hop_counter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 hop_counter;
hop_counter = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_hop_counter, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%d", hop_counter);
}
static void
dissect_gtpv2_ue_time_zone(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
de_time_zone(tvb, tree, pinfo, offset, 1, NULL, 0);
offset += 1;
proto_tree_add_item(item, hf_gtpv2_ue_time_zone_dst, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_trace_reference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint32 trace_id;
gchar *mcc_mnc_str;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
trace_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_trace_id, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s,Trace ID %u", mcc_mnc_str, trace_id);
}
static void
dissect_complete_request_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
tvbuff_t *new_tvb;
int offset;
offset = 0;
proto_tree_add_item(tree, hf_gtpv2_complete_req_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
new_tvb = tvb_new_subset(tvb, offset, length-1, length-1);
call_dissector(nas_eps_handle, new_tvb, pinfo, tree);
}
static void
dissect_gtpv2_guti(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
offset = 0;
dissect_e212_mcc_mnc(tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_mme_grp_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_mme_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_m_tmsi, tvb, offset, 4, ENC_NA);
}
static void
dissect_gtpv2_F_container(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type, guint8 instance _U_)
{
tvbuff_t *new_tvb;
proto_tree *sub_tree;
int offset = 0;
guint8 container_type;
guint8 container_flags, xid_len;
proto_tree_add_item(tree, hf_gtpv2_container_type, tvb, offset, 1, ENC_BIG_ENDIAN);
container_type = tvb_get_guint8(tvb, offset);
offset += 1;
if ( (message_type == GTPV2_FORWARD_RELOCATION_REQ)
|| (message_type == GTPV2_CONTEXT_RESPONSE)
|| (message_type == GTPV2_RAN_INFORMATION_RELAY)) {
switch (container_type) {
case 1:
sub_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_gtpv2_utran_con, NULL, "UTRAN transparent container");
new_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_ranap_Source_ToTarget_TransparentContainer_PDU(new_tvb, pinfo, sub_tree, NULL);
return;
case 2:
sub_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_gtpv2_bss_con, NULL, "BSS container");
proto_tree_add_item(sub_tree, hf_gtpv2_bss_container_phx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_sapi_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_rp_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_pfi_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
container_flags = tvb_get_guint8(tvb, offset);
offset += 1;
if ((container_flags & 0x01) == 1) {
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_pfi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (((container_flags & 0x04) == 4) || ((container_flags & 0x02) == 2)) {
if ((container_flags & 0x04) == 4) {
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_sapi, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if ((container_flags & 0x02) == 2) {
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_rp, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
}
if ((container_flags & 0x08) == 8) {
xid_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_xid_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_gtpv2_bss_con_xid, tvb, offset, xid_len, ENC_NA);
}
return;
case 3:
sub_tree = proto_tree_add_subtree(tree, tvb, offset, length, ett_gtpv2_eutran_con, NULL, "E-UTRAN transparent container");
proto_tree_add_expert(sub_tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, length - offset);
return;
default:
break;
}
}
if (message_type == GTPV2_FORWARD_CTX_NOTIFICATION) {
switch (container_type) {
case 3:
new_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU(new_tvb, pinfo, tree, NULL);
return;
default:
break;
}
}
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, length-offset);
}
static void
dissect_gtpv2_s1ap_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset, guint8 cause_type)
{
switch (cause_type) {
case 0:
proto_tree_add_item(tree, hf_gtpv2_CauseRadioNetwork, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(tree, hf_gtpv2_CauseTransport, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(tree, hf_gtpv2_CauseNas, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(tree, hf_gtpv2_CauseProtocol, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 4:
proto_tree_add_item(tree, hf_gtpv2_CauseMisc, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
return;
}
static void
dissect_gtpv2_F_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type, guint8 instance)
{
int offset = 0;
guint8 cause_type;
if (message_type == GTPV2_FORWARD_RELOCATION_REQ) {
switch (instance) {
case 0:
proto_item_append_text(item, "[RAN Cause]");
proto_tree_add_item(tree, hf_gtpv2_cause_type, tvb, offset, 1, ENC_BIG_ENDIAN);
cause_type = tvb_get_guint8(tvb, offset);
offset += 1;
dissect_gtpv2_s1ap_cause(tvb, pinfo, tree, offset, cause_type);
return;
case 1:
proto_item_append_text(item, "[RANAP Cause]");
break;
case 2:
proto_item_append_text(item, "[BSSGP Cause]");
break;
default:
break;
}
}
else if (message_type == GTPV2_FORWARD_RELOCATION_RESP) {
switch (instance) {
case 0:
proto_item_append_text(item, "[S1-AP Cause]");
proto_tree_add_item(tree, hf_gtpv2_cause_type, tvb, offset, 1, ENC_BIG_ENDIAN);
cause_type = tvb_get_guint8(tvb, offset);
offset++;
dissect_gtpv2_s1ap_cause(tvb, pinfo, tree, offset, cause_type);
return;
case 1:
proto_item_append_text(item, "[RANAP Cause]");
break;
case 2:
proto_item_append_text(item, "[BSSGP Cause]");
break;
default:
break;
}
}
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, length-offset);
}
static void
dissect_gtpv2_sel_plmn_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
gchar *mcc_mnc_str;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, 0, E212_NONE, FALSE);
proto_item_append_text(item, "%s", mcc_mnc_str);
}
static gchar*
dissect_gtpv2_macro_enodeb_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint32 macro_enodeb_id;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_NONE, TRUE);
*offset += 3;
macro_enodeb_id = tvb_get_ntoh24(tvb, *offset) & 0x0fffff;
proto_tree_add_item(tree, hf_gtpv2_macro_enodeb_id, tvb, *offset, 3, ENC_BIG_ENDIAN);
*offset += 3;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, Macro eNodeB ID 0x%x",
mcc_mnc_str,
macro_enodeb_id);
return str;
}
static gchar*
dissect_gtpv2_home_enodeb_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int *offset)
{
gchar *str = NULL;
gchar *mcc_mnc_str;
guint32 home_enodeb_id;
mcc_mnc_str = dissect_e212_mcc_mnc_wmem_packet_str(tvb, pinfo, tree, *offset, E212_NONE, TRUE);
*offset += 3;
home_enodeb_id = tvb_get_ntohl(tvb, *offset) & 0x0fffffff;
proto_tree_add_item(tree, hf_gtpv2_home_enodeb_id, tvb, *offset, 4 , ENC_BIG_ENDIAN);
*offset += 4;
str = wmem_strdup_printf(wmem_packet_scope(), "%s, Home eNodeB ID 0x%x",
mcc_mnc_str,
home_enodeb_id);
return str;
}
static void
dissect_gtpv2_target_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
tvbuff_t *new_tvb;
int offset = 0;
guint8 target_type;
proto_tree_add_item(tree, hf_gtpv2_target_type, tvb, 0, 1, ENC_BIG_ENDIAN);
target_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch (target_type) {
case 0:
new_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_e212_mcc_mnc(new_tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_lac, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_gtpv2_rac, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gtpv2_rnc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
if(length == 11){
proto_tree_add_item(tree, hf_gtpv2_ext_rnc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
}
return;
case 1:
dissect_gtpv2_macro_enodeb_id(tvb, pinfo, tree, &offset);
proto_tree_add_item(tree, hf_gtpv2_tai_tac, tvb, offset, 2, ENC_BIG_ENDIAN);
return;
case 2:
new_tvb = tvb_new_subset_remaining(tvb, offset);
de_bssgp_cell_id(new_tvb, tree, pinfo, 0, 0, NULL, 0);
return;
case 3:
dissect_gtpv2_home_enodeb_id(tvb, pinfo, tree, &offset);
proto_tree_add_item(tree, hf_gtpv2_tac, tvb, offset, 2 , ENC_BIG_ENDIAN);
return;
default:
break;
}
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, offset, length-offset);
}
static void
dissect_gtpv2_pkt_flow_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ebi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_packet_flow_id, tvb, offset, length, ENC_NA);
}
static void
dissect_gtpv2_rab_context(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_bits_item(tree, hf_gtpv2_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_nsapi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gtpv2_dl_gtp_u_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_ul_gtp_u_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_dl_pdcp_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_gtpv2_ul_pdcp_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_s_rnc_pdcp_ctx_info(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_rrc_container, tvb, 0, length, ENC_NA);
}
static void
dissect_udp_s_port_nr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_upd_source_port_number, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%u", tvb_get_ntohs(tvb, 0));
}
static void
dissect_gtpv2_apn_rest(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint8 type_value;
type_value = tvb_get_guint8(tvb, 0);
proto_tree_add_item(tree, hf_gtpv2_apn_rest, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "value %u", type_value);
}
void
dissect_gtpv2_selec_mode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 ss_mode;
ss_mode = tvb_get_guint8(tvb, offset) & 0x03;
proto_tree_add_item(tree, hf_gtpv2_selec_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str_const(ss_mode, gtpv2_selec_mode_vals, "Unknown"));
}
static void
dissect_gtpv2_source_ident(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 source_type;
de_cell_id(tvb, tree, pinfo, offset, 8, NULL, 0);
offset += 8;
source_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_source_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (source_type) {
case 0:
de_cell_id(tvb, tree, pinfo, offset, 8, NULL, 0);
break;
case 1:
break;
case 2:
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_source_type_unknown, tvb, offset-1, 1);
break;
}
}
static void
dissect_gtpv2_bearer_control_mode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint8 bcm;
proto_tree_add_item(tree, hf_gtpv2_bearer_control_mode, tvb, 0, 1, ENC_BIG_ENDIAN);
bcm = tvb_get_guint8(tvb, 0);
proto_item_append_text(item, "%s", val_to_str_const(bcm, gtpv2_bearer_control_mode_short_vals, "Unknown"));
}
static void
dissect_gtpv2_cng_rep_act(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint8 action;
action = tvb_get_guint8(tvb, 0);
proto_tree_add_item(tree, hf_gtpv2_cng_rep_act, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%s", val_to_str_const(action, gtpv2_cng_rep_act_vals, "Unknown"));
}
void
dissect_gtpv2_fq_csid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 octet, node_id_type, csids;
octet = tvb_get_guint8(tvb, offset);
node_id_type = octet >> 4;
csids = octet & 0x0f;
proto_tree_add_item(tree, hf_gtpv2_fq_csid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_fq_csid_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (node_id_type) {
case 0:
proto_tree_add_item(tree, hf_gtpv2_fq_csid_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 1:
proto_tree_add_item(tree, hf_gtpv2_fq_csid_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
break;
case 2:
proto_tree_add_item(tree, hf_gtpv2_fq_csid_node_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_fq_csid_mcc_mnc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gtpv2_fq_csid_type_bad, tvb, offset-1, 1,
"Wrong Node-ID Type %u, should be 0-2(Or this is a newer spec)", node_id_type);
return;
}
while ( csids-- ) {
proto_tree_add_item(tree, hf_gtpv2_fq_csid_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
static void
dissect_gtpv2_channel_needed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
de_rr_chnl_needed(tvb, tree, pinfo, 0, length, NULL, 0);
}
static void
dissect_gtpv2_emlpp_pri(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
be_emlpp_prio(tvb, tree, pinfo, 0, length, NULL, 0);
}
static void
dissect_gtpv2_node_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint8 node_type;
proto_tree_add_item(tree, hf_gtpv2_node_type, tvb, 0, 1, ENC_BIG_ENDIAN);
node_type = tvb_get_guint8(tvb, 0);
proto_item_append_text(item, "%s", val_to_str_const(node_type, gtpv2_node_type_vals, "Unknown"));
}
static void
dissect_gtpv2_fqdn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0, name_len, tmp;
guint8 *fqdn = NULL;
if (length > 0) {
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20) {
fqdn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, length - 1, ENC_ASCII);
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + fqdn[tmp] + 1;
fqdn[tmp] = '.';
}
} else {
fqdn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
}
proto_tree_add_string(tree, hf_gtpv2_fqdn, tvb, offset, length, fqdn);
proto_item_append_text(item, "%s", fqdn);
}
}
static void
dissect_gtpv2_private_ext(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance)
{
int offset = 0;
tvbuff_t *next_tvb;
guint16 ext_id;
ext_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_enterprise_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_append_text(item, "%s (%u)", val_to_str_ext_const(ext_id, &sminmpec_values_ext, "Unknown"), ext_id);
next_tvb = tvb_new_subset_length(tvb, offset, length-2);
if (dissector_try_uint_new(gtpv2_priv_ext_dissector_table, ext_id, next_tvb, pinfo, tree, FALSE, GUINT_TO_POINTER((guint32)instance))){
return;
}
proto_tree_add_item(tree, hf_gtpv2_proprietary_value, tvb, offset, length-2, ENC_NA);
}
static void
dissect_gtpv2_ti(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_ti, tvb, 0, length, ENC_NA);
}
void
dissect_gtpv2_mbms_session_duration(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
int bit_offset = 0;
guint32 days;
guint32 hours;
guint32 minutes;
guint32 seconds;
guint32 durations_seconds;
proto_item *day_item, *sec_item;
durations_seconds = tvb_get_bits32(tvb, bit_offset, 17, ENC_BIG_ENDIAN);
bit_offset += 17;
days = tvb_get_bits32(tvb, bit_offset, 7, ENC_BIG_ENDIAN);
if ((durations_seconds == 0) && (days == 0)) {
day_item = proto_tree_add_item(tree, hf_gtpv2_mbms_session_duration_days, tvb, offset, 3, ENC_BIG_ENDIAN);
sec_item = proto_tree_add_item(tree, hf_gtpv2_mbms_session_duration_secs, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(item, "Indefinite (always-on)");
} else {
hours = durations_seconds / 3600;
minutes = (durations_seconds % 3600) / 60;
seconds = (durations_seconds % 3600) % 60;
day_item = proto_tree_add_item(tree, hf_gtpv2_mbms_session_duration_days, tvb, offset, 3, ENC_BIG_ENDIAN);
sec_item = proto_tree_add_item(tree, hf_gtpv2_mbms_session_duration_secs, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(item, "%d days %02d:%02d:%02d (DD days HH:MM:SS)", days, hours, minutes, seconds);
}
if (days > 18) {
expert_add_info(pinfo, day_item, &ei_gtpv2_mbms_session_duration_days);
}
if (durations_seconds > 86400) {
expert_add_info(pinfo, sec_item, &ei_gtpv2_mbms_session_duration_secs);
}
offset += 3;
if (length > 3)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-3, ENC_NA);
}
void
dissect_gtpv2_mbms_service_area(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_item *sai_item;
guint8 binary_nr;
guint16 real_nr;
guint16 sai;
binary_nr = tvb_get_guint8(tvb, offset);
real_nr = (guint16)binary_nr + 1;
proto_tree_add_uint(tree, hf_gtpv2_mbms_service_area_nr, tvb, offset, 1, real_nr);
offset += 1;
while (offset < length) {
sai = tvb_get_ntohs(tvb, offset);
sai_item = proto_tree_add_item(tree, hf_gtpv2_mbms_service_area_id, tvb, offset, 2, ENC_BIG_ENDIAN);
if (sai == 0) {
proto_item_append_text(sai_item, " Entire PLMN");
}
proto_item_append_text(item, " %u", sai);
offset += 2;
}
}
static void
dissect_gtpv2_mbms_session_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length, _U_ guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_mbms_session_id, tvb, offset, 1, ENC_NA);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_mbms_flow_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_mbms_flow_id, tvb, offset, 2, ENC_NA);
proto_item_append_text(item, " %s", tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, 2));
offset += 2;
if (length > 2)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-2, ENC_NA);
}
static void
dissect_gtpv2_mbms_ip_mc_dist(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_cteid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gtpv2_ip_addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ip_addr_len, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset) & 0x3f) == 4) {
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mbms_ip_mc_dist_addrv4, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " IPv4 Dist %s", tvb_ip_to_str(tvb, offset));
offset += 4;
} else if ((tvb_get_guint8(tvb, offset) & 0x3f) == 16) {
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mbms_ip_mc_dist_addrv6, tvb, offset, 16, ENC_NA);
proto_item_append_text(item, " IPv6 Dist %s", tvb_ip6_to_str(tvb, offset));
offset += 16;
}
proto_tree_add_item(tree, hf_gtpv2_ip_addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_ip_addr_len, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset) & 0x3f) == 4) {
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mbms_ip_mc_src_addrv4, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(item, " IPv4 Src %s", tvb_ip_to_str(tvb, offset));
offset += 4;
} else if ((tvb_get_guint8(tvb, offset) & 0x3f) == 16) {
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_mbms_ip_mc_src_addrv6, tvb, offset, 16, ENC_NA);
proto_item_append_text(item, " IPv6 Src %s", tvb_ip6_to_str(tvb, offset));
offset += 16;
}
proto_tree_add_item(tree, hf_gtpv2_mbms_hc_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > offset)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-offset, ENC_NA);
}
static void
dissect_gtpv2_mbms_dist_ack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_mbms_dist_indication, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_uci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
dissect_e212_mcc_mnc(tvb, pinfo, tree, 0, E212_NONE, TRUE);
offset += 3;
proto_tree_add_item(tree, hf_gtpv2_uci_csg_id_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_uci_csg_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_gtpv2_uci_access_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_uci_lcsg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_uci_csg_membership, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_csg_info_rep_action(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_rfsp_index(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
if(instance == 0){
proto_tree_add_item(tree, hf_gtpv2_subscriber_rfsp, tvb, offset, 2, ENC_BIG_ENDIAN);
}else if(instance == 1){
proto_tree_add_item(tree, hf_gtpv2_rfsp_inuse, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_gtpv2_csg_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_cmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_service_indicator(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_detach_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_ldn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_node_features(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_node_features_prn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_node_features_mabr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_node_features_ntsr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
void
dissect_gtpv2_mbms_time_to_data_xfer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 binary_secs;
guint16 real_secs;
binary_secs = tvb_get_guint8(tvb, offset);
real_secs = (guint16)binary_secs + 1;
proto_tree_add_string_format_value(tree, hf_gtpv2_time_to_data_xfer, tvb, offset, 1, "", "%d second(s)", real_secs);
proto_item_append_text(item, " %u second(s)", real_secs);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_throttling(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 oct;
proto_tree_add_item(tree, hf_gtpv2_throttling_delay_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_throttling_delay_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_throttling_factor, tvb, offset, 1, ENC_BIG_ENDIAN);
if (oct > 0x64)
proto_item_append_text(item, "Throttling factor: value beyond (0,100) is considered as 0");
offset++;
if (length > 2)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length - 2, ENC_NA);
}
void
dissect_gtpv2_arp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_arp_pvi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_arp_pl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_arp_pci, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
void
dissect_gtpv2_epc_timer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_timer_unit, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_timer_value, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_sig_prio_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_item(tree, hf_gtpv2_lapi, tvb, 0, 1, ENC_BIG_ENDIAN);
}
static void
dissect_gtpv2_tmgi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint64 tmgi;
tmgi = tvb_get_ntoh48(tvb, offset);
proto_item_append_text(item, "%012" G_GINT64_MODIFIER "x", tmgi);
proto_tree_add_item(tree, hf_gtpv2_mbms_service_id, tvb, offset, 3, ENC_NA);
offset += 3;
dissect_e212_mcc_mnc(tvb, pinfo, tree, offset, E212_NONE, TRUE);
offset += 3;
if (length > offset)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-offset, ENC_NA);
}
static void
dissect_gtpv2_add_mm_cont_for_srvcc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_item *ms_cm_item;
proto_tree *ms_cm_tree;
guint8 elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ms_cm_item = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark2, tvb, offset, elm_len, ENC_NA);
ms_cm_tree = proto_item_add_subtree(ms_cm_item, ett_gtpv2_ms_mark);
de_ms_cm_2(tvb, ms_cm_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_ms_classmark3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ms_cm_item = proto_tree_add_item(tree, hf_gtpv2_mobile_station_classmark3, tvb, offset, elm_len, ENC_NA);
ms_cm_tree = proto_item_add_subtree(ms_cm_item, ett_gtpv2_ms_mark);
de_ms_cm_3(tvb, ms_cm_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
elm_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_len_supp_codec_list, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ms_cm_item = proto_tree_add_item(tree, hf_gtpv2_supported_codec_list, tvb, offset, elm_len, ENC_NA);
ms_cm_tree = proto_item_add_subtree(ms_cm_item, ett_gtpv2_supp_codec_list);
de_sup_codec_list(tvb, ms_cm_tree, pinfo, offset, elm_len, NULL, 0);
offset += elm_len;
if (length > offset)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-offset, ENC_NA);
}
static void
dissect_gtpv2_add_flags_for_srvcc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_add_flags_for_srvcc_ics, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_vsrvcc_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_mmbr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint32 max_ul;
guint32 max_dl;
max_ul = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_mmbr_ul, tvb, offset, 4, max_ul, "%u %s",
(max_ul) > 1000 ? max_ul/1000 : max_ul,
(max_ul) > 1000 ? "Mbps" : "kbps");
offset += 4;
max_dl = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gtpv2_mmbr_dl, tvb, offset, 4, max_dl, "%u %s",
(max_dl) > 1000 ? max_dl/1000 : max_dl,
(max_dl) > 1000 ? "Mbps" : "kbps");
}
static void
dissect_gtpv2_mdt_config(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_apco(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
switch (message_type) {
case GTPV2_CREATE_SESSION_REQUEST:
case GTPV2_DELETE_SESSION_REQUEST:
case GTPV2_BEARER_RESOURCE_COMMAND:
case GTPV2_CREATE_BEARER_RESPONSE:
case GTPV2_UPDATE_BEARER_RESPONSE:
case GTPV2_DELETE_BEARER_RESPONSE:
pinfo->link_dir = P2P_DIR_UL;
break;
case GTPV2_CREATE_SESSION_RESPONSE:
case GTPV2_MODIFY_BEARER_RESPONSE:
case GTPV2_DELETE_SESSION_RESPONSE:
case GTPV2_CREATE_BEARER_REQUEST:
case GTPV2_UPDATE_BEARER_REQUEST:
case GTPV2_DELETE_BEARER_REQUEST:
pinfo->link_dir = P2P_DIR_DL;
break;
default:
break;
}
de_sm_pco(tvb, tree, pinfo, 0, length, NULL, 0);
}
static void
dissect_gtpv2_abs_mbms_data_tf_time(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
const gchar *time_str;
time_str = tvb_ntp_fmt_ts(tvb, offset);
proto_tree_add_string(tree, hf_gtpv2_abs_time_mbms_data, tvb, offset, 8, time_str);
proto_item_append_text(item, "%s", time_str);
offset += 8;
if (length > offset)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-offset, ENC_NA);
}
static void
dissect_gtpv2_henb_info_report(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_henb_info_report_fti, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_ip4cp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_ip4cp_subnet_prefix_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gtpv2_ip4cp_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (length > offset)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-offset, ENC_NA);
}
static void
dissect_gtpv2_change_report_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_change_report_flags_sncr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_change_report_flags_tzcr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_action_indication(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gtpv2_action_indication_val, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > 1)
proto_tree_add_item(tree, hf_gtpv2_spare_bytes, tvb, offset, length-1, ENC_NA);
}
static void
dissect_gtpv2_twan_Identifier(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_uli_timestamp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
const gchar *time_str;
time_str = tvb_ntp_fmt_ts_sec(tvb, 0);
proto_tree_add_string(tree, hf_gtpv2_uli_timestamp, tvb, 0, 8, time_str);
proto_item_append_text(item, "%s", time_str);
}
static void
dissect_gtpv2_mbms_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_ran_nas_cause(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_cn_operator_selection_entity(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_trust_wlan_mode_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_node_number(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_node_identifier(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static int
dissect_diameter_3gpp_presence_reporting_area_elements_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_tree *sub_tree;
proto_item *item;
int offset = 0, i;
guint length;
guint8 oct, no_tai, no_rai, no_mENB, no_hENB, no_ECGI, no_sai, no_cgi;
gchar *append_str;
length = tvb_reported_length(tvb);
oct = tvb_get_guint8(tvb,offset);
no_tai = oct >> 4;
no_rai = oct & 0x0f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_tai, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_rai, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_mENB = tvb_get_guint8(tvb,offset) & 0x3f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_m_enodeb, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_hENB = tvb_get_guint8(tvb,offset) & 0x3f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_h_enodeb, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_ECGI = tvb_get_guint8(tvb,offset) & 0x3f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_ecgi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_sai = tvb_get_guint8(tvb,offset) & 0x3f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_sai, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
no_cgi = tvb_get_guint8(tvb,offset) & 0x3f;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_act_no_cgi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(no_tai > 0){
i = 1;
while (no_tai > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 5, ett_gtpv2_preaa_tais, &item, "Tracking Area Identity (TAI) Number %u",i);
append_str = dissect_gtpv2_tai(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_tai--;
}
}
if(no_mENB > 0){
i = 1;
while (no_mENB > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 6, ett_gtpv2_preaa_menbs, &item, "Macro eNB ID %u",i);
append_str = dissect_gtpv2_macro_enodeb_id(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_mENB--;
}
}
if(no_hENB > 0){
i = 1;
while (no_hENB > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 7, ett_gtpv2_preaa_henbs, &item, "Home eNB ID %u",i);
append_str = dissect_gtpv2_home_enodeb_id(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_hENB--;
}
}
if(no_ECGI > 0){
i = 1;
while (no_ECGI > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 7, ett_gtpv2_preaa_ecgis, &item, "ECGI ID %u",i);
append_str = dissect_gtpv2_ecgi(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_ECGI--;
}
}
if(no_rai > 0){
i = 1;
while (no_rai > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 7, ett_gtpv2_preaa_rais, &item, "RAI ID %u",i);
append_str = dissect_gtpv2_rai(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_rai--;
}
}
if(no_sai > 0){
i = 1;
while (no_sai > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 7, ett_gtpv2_preaa_sais, &item, "SAI ID %u",i);
append_str = dissect_gtpv2_sai_common(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_sai--;
}
}
if(no_cgi > 0){
i = 1;
while (no_cgi > 0){
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 7, ett_gtpv2_preaa_cgis, &item, "CGI ID %u",i);
append_str = dissect_gtpv2_cgi(tvb, pinfo, sub_tree, &offset);
proto_item_append_text(item, " %s",append_str);
i++;
no_cgi--;
}
}
return length;
}
static void
dissect_gtpv2_pres_rep_area_action(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 length, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
tvbuff_t * new_tvb;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_action, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length == 1)
return;
proto_tree_add_item(tree, hf_gtpv2_pres_rep_area_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
if (length == 3)
return;
new_tvb = tvb_new_subset_length(tvb, offset, length-3);
dissect_diameter_3gpp_presence_reporting_area_elements_list(new_tvb, pinfo, tree, NULL);
}
static void
dissect_gtpv2_pres_rep_area_information(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_twan_identifier_timestamp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
proto_tree_add_expert(tree, pinfo, &ei_gtpv2_ie_data_not_dissected, tvb, 0, length);
}
static void
dissect_gtpv2_overload_control_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
proto_tree *grouped_tree;
tvbuff_t *new_tvb;
proto_item_append_text(item, "[Grouped IE]");
grouped_tree = proto_item_add_subtree(item, ett_gtpv2_overload_control_information);
new_tvb = tvb_new_subset_length(tvb, offset, length);
dissect_gtpv2_ie_common(new_tvb, pinfo, grouped_tree, offset, message_type);
}
static void
dissect_gtpv2_load_control_inf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
tvbuff_t *new_tvb;
proto_tree *grouped_tree;
proto_item_append_text(item, "[Grouped IE]");
grouped_tree = proto_item_add_subtree(item, ett_gtpv2_load_control_inf);
new_tvb = tvb_new_subset_length(tvb, offset, length);
dissect_gtpv2_ie_common(new_tvb, pinfo, grouped_tree, 0, message_type);
}
static void
dissect_gtpv2_metric(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint32 oct;
proto_tree_add_item_ret_uint(tree, hf_gtpv2_metric, tvb, 0, 1, ENC_BIG_ENDIAN, &oct);
if (oct > 0x64) {
proto_item_append_text(item, "Metric: value beyond 100 is considered as 0");
} else {
proto_item_append_text(item, "%u", oct);
}
}
static void
dissect_gtpv2_seq_no(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
guint32 seq;
proto_tree_add_item_ret_uint(tree, hf_gtpv2_sequence_number, tvb, 0, 4, ENC_BIG_ENDIAN, &seq);
proto_item_append_text(item, "%u", seq);
}
static void
dissect_gtpv2_apn_and_relative_capacity(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, guint16 length _U_, guint8 message_type _U_, guint8 instance _U_)
{
int offset = 0;
guint8 oct, apn_length;
guint8 *apn = NULL;
int name_len, tmp;
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_relative_capacity, tvb, offset, 1, ENC_BIG_ENDIAN);
if((oct > 0x64) || (oct < 0x01))
proto_item_append_text(item, "Relative Capacity: value beyond (1,100) is considered as 0");
offset += 1;
apn_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gtpv2_apn_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (apn_length > 0)
{
name_len = tvb_get_guint8(tvb, offset);
if (name_len < 0x20)
{
apn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, apn_length - 1, ENC_ASCII);
for (;;)
{
if (name_len >= apn_length - 1)
break;
tmp = name_len;
name_len = name_len + apn[tmp] + 1;
apn[tmp] = '.';
}
}
else
{
apn = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, apn_length, ENC_ASCII);
}
proto_tree_add_string(tree, hf_gtpv2_apn, tvb, offset, apn_length, apn);
}
}
static void
dissect_gtpv2_ie_common(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, gint offset, guint8 message_type)
{
proto_tree *ie_tree;
proto_item *ti;
tvbuff_t *ie_tvb;
guint8 type, instance;
guint16 length;
int i;
while (offset < (gint)tvb_reported_length(tvb)) {
type = tvb_get_guint8(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 1);
ie_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 + length, ett_gtpv2_ie, &ti, "%s : ",
val_to_str_ext_const(type, &gtpv2_element_type_vals_ext, "Unknown"));
proto_tree_add_item(ie_tree, hf_gtpv2_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ie_tree, hf_gtpv2_ie_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ie_tree, hf_gtpv2_cr, tvb, offset, 1, ENC_BIG_ENDIAN);
instance = tvb_get_guint8(tvb, offset) & 0x0f;
proto_tree_add_item(ie_tree, hf_gtpv2_instance, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (type == GTPV2_IE_RESERVED) {
expert_add_info(pinfo, ti, &ei_gtpv2_ie);
} else {
i = -1;
while (gtpv2_ies[++i].ie_type) {
if (gtpv2_ies[i].ie_type == type)
break;
}
ie_tvb = tvb_new_subset_remaining(tvb, offset);
(*gtpv2_ies[i].decode) (ie_tvb, pinfo , ie_tree, ti, length, message_type, instance);
}
offset += length;
}
}
static void
dissect_gtpv2(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_tree *gtpv2_tree, *flags_tree;
proto_item *tf;
guint8 message_type, t_flag, p_flag;
int offset = 0;
guint16 msg_length;
tvbuff_t *msg_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GTPv2");
col_clear(pinfo->cinfo, COL_INFO);
message_type = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(message_type, &gtpv2_message_type_vals_ext, "Unknown"));
p_flag = (tvb_get_guint8(tvb, offset) & 0x10) >> 4;
msg_length = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(tree, proto_gtpv2, tvb, offset, msg_length + 4, ENC_NA);
if (tree) {
gtpv2_tree = proto_tree_add_subtree(tree, tvb, offset, msg_length + 4, ett_gtpv2, NULL,
val_to_str_ext_const(message_type, &gtpv2_message_type_vals_ext, "Unknown"));
tf = proto_tree_add_item(gtpv2_tree, hf_gtpv2_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(tf, ett_gtpv2_flags);
t_flag = (tvb_get_guint8(tvb, offset) & 0x08) >> 3;
proto_tree_add_item(flags_tree, hf_gtpv2_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_gtpv2_p, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_gtpv2_t, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(gtpv2_tree, hf_gtpv2_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(gtpv2_tree, hf_gtpv2_msg_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (t_flag) {
proto_tree_add_item(gtpv2_tree, hf_gtpv2_teid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(gtpv2_tree, hf_gtpv2_seq, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(gtpv2_tree, hf_gtpv2_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (p_flag) {
msg_tvb = tvb_new_subset_length(tvb, 0, msg_length + 4);
dissect_gtpv2_ie_common(msg_tvb, pinfo, gtpv2_tree, offset, message_type);
} else {
dissect_gtpv2_ie_common(tvb, pinfo, gtpv2_tree, offset, message_type);
}
}
if (p_flag) {
tvbuff_t *new_p_tvb;
new_p_tvb = tvb_new_subset_remaining(tvb, msg_length + 4);
col_append_str(pinfo->cinfo, COL_INFO, " / ");
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_gtpv2(new_p_tvb, pinfo, tree);
}
}
void proto_register_gtpv2(void)
{
static hf_register_info hf_gtpv2[] = {
{ &hf_gtpv2_spare_half_octet,
{"Spare half octet", "gtpv2.spare_half_octet",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gtpv2_spare_bits,
{"Spare bit(s)", "gtpv2.spare_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_gtpv2_flags,
{"Flags", "gtpv2.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_version,
{"Version", "gtpv2.version",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL}
},
{&hf_gtpv2_p,
{"Piggybacking flag (P)", "gtpv2.p",
FT_UINT8, BASE_DEC, NULL, 0x10,
"If Piggybacked message is present or not", HFILL}
},
{ &hf_gtpv2_t,
{"TEID flag (T)", "gtpv2.t",
FT_UINT8, BASE_DEC, NULL, 0x08,
"If TEID field is present or not", HFILL}
},
{ &hf_gtpv2_message_type,
{"Message Type", "gtpv2.message_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_message_type_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_msg_length,
{"Message Length", "gtpv2.msg_lengt",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_teid,
{"Tunnel Endpoint Identifier", "gtpv2.teid",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
"TEID", HFILL}
},
{ &hf_gtpv2_seq,
{"Sequence Number", "gtpv2.seq",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
"SEQ", HFILL}
},
{ &hf_gtpv2_spare,
{"Spare", "gtpv2.spare",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ie,
{"IE Type", "gtpv2.ie_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_element_type_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ie_len,
{"IE Length", "gtpv2.ie_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"length of the information element excluding the first four octets", HFILL}
},
{ &hf_gtpv2_cr,
{"CR flag", "gtpv2.cr",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_gtpv2_instance,
{"Instance", "gtpv2.instance",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_ipv4_addr,
{"IPv4 Address", "gtpv2.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_cause,
{"Cause", "gtpv2.cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_cause_vals_ext, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_cause_cs,
{"CS (Cause Source)", "gtpv2.cs",
FT_BOOLEAN, 8, TFS(&gtpv2_cause_cs), 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_cause_bce,
{"BCE (Bearer Context IE Error)", "gtpv2.bce",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_cause_pce,
{"PCE (PDN Connection IE Error)", "gtpv2.pce",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL}
},
{ &hf_gtpv2_cause_off_ie_t,
{"Type of the offending IE", "gtpv2.cause_off_ie_t",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_element_type_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_rec,
{"Restart Counter", "gtpv2.rec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_stn_sr,
{"STN-SR", "gtpv2.stn_sr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_len_trans_con,
{"Length of the Transparent Container", "gtpv2.len_trans_con",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_eksi,
{"eKSI", "gtpv2.eksi",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_ck,
{"CK", "gtpv2.ck",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ik,
{"IK", "gtpv2.ik",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_len_ms_classmark2,
{"Length of Mobile Station Classmark2", "gtpv2.len_ms_classmark2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_len_ms_classmark3,
{"Length of Mobile Station Classmark3", "gtpv2.len_ms_classmark3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_len_supp_codec_list,
{"Length of Supported Codec List", "gtpv2.len_supp_codec_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ksi,
{"KSI'cs", "gtpv2.ksi",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL}
},
{ &hf_gtpv2_cksn,
{"CKSN'", "gtpv2.cksn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_srvcc_cause,
{"SRVCC Cause", "gtpv2.srvcc_cause",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_srvcc_cause_vals_ext, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_rac,
{ "Routing Area Code (RAC)", "gtpv2.rac",
FT_UINT8, BASE_DEC, NULL, 0,
"Routing Area Code", HFILL}
},
{ &hf_gtpv2_rnc_id,
{"RNC ID", "gtpv2.rnc_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ext_rnc_id,
{"Extended RNC-ID", "gtpv2.ext_rnc_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_lac,
{ "Location Area Code (LAC)", "gtpv2.lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gtpv2_sac,
{ "Service Area Code (SAC)", "gtpv2.sac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gtpv2_tgt_g_cell_id,
{"Cell ID", "gtpv2.tgt_g_cell_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_teid_c,
{"Tunnel Endpoint Identifier for Control Plane(TEID-C)", "gtpv2.teid_c",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_sv_sti,
{"STI (Session Transfer Indicator)", "gtpv2.sv_sti",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_sv_ics,
{"ICS (IMS Centralized Service)", "gtpv2.sv_ics",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_sv_emind,
{"EmInd(Emergency Indicator)", "gtpv2.sv_emind",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{&hf_gtpv2_apn,
{"APN (Access Point Name)", "gtpv2.apn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_ambr_up,
{"AMBR Uplink (Aggregate Maximum Bit Rate for Uplink)", "gtpv2.ambr_up",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_ambr_down,
{"AMBR Downlink(Aggregate Maximum Bit Rate for Downlink)", "gtpv2.ambr_down",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_ebi,
{"EPS Bearer ID (EBI)", "gtpv2.ebi",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_ip_address_ipv4,
{"IP address IPv4", "gtpv2.ip_address_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ip_address_ipv6,
{"IP address IPv6", "gtpv2.ip_address_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_mei,
{"MEI(Mobile Equipment Identity)", "gtpv2.mei",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_gtpv2_pdn_numbers_nsapi,
{"NSAPI", "gtpv2.pdn_numbers_nsapi",
FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL}
},
{ &hf_gtpv2_p_tmsi,
{"Packet TMSI (P-TMSI)", "gtpv2.p_tmsi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_gtpv2_p_tmsi_sig,
{"P-TMSI Signature", "gtpv2.p_tmsi_sig",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_gtpv2_daf,
{"DAF (Dual Address Bearer Flag)", "gtpv2.daf",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{&hf_gtpv2_dtf,
{"DTF (Direct Tunnel Flag)", "gtpv2.dtf",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}
},
{&hf_gtpv2_hi,
{"HI (Handover Indication)", "gtpv2.hi",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}
},
{&hf_gtpv2_dfi,
{"DFI (Direct Forwarding Indication)", "gtpv2.dfi",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL}
},
{&hf_gtpv2_oi,
{"OI (Operation Indication)", "gtpv2.oi",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL}
},
{&hf_gtpv2_isrsi,
{"ISRSI (Idle mode Signalling Reduction Supported Indication)", "gtpv2.isrsi",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_israi,
{"ISRAI (Idle mode Signalling Reduction Activation Indication)", "gtpv2.israi",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_sgwci,
{"SGWCI (SGW Change Indication)", "gtpv2.sgwci",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{&hf_gtpv2_sqci,
{"SQCI (Subscribed QoS Change Indication", "gtpv2.sqci",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{&hf_gtpv2_uimsi,
{"UIMSI (Unauthenticated IMSI)", "gtpv2.uimsi",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}
},
{&hf_gtpv2_cfsi,
{"CFSI (Change F-TEID support indication)", "gtpv2.cfsi",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}
},
{&hf_gtpv2_crsi,
{"CRSI (Change Reporting support indication):", "gtpv2.crsi",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL}
},
{&hf_gtpv2_ps,
{"PS (Piggybacking Supported).)", "gtpv2.ps",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL}
},
{&hf_gtpv2_pt,
{"PT (Protocol Type)", "gtpv2.pt",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_si,
{"SI (Scope Indication)", "gtpv2.si",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_msv,
{"MSV (MS Validated)", "gtpv2.msv",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{&hf_gtpv2_retloc,
{"RetLoc (Retrieve Location Indication Flag)", "gtpv2.retloc",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{&hf_gtpv2_pbic,
{"PBIC (Propagate BBAI Information Change)", "gtpv2.pbic",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}
},
{&hf_gtpv2_srni,
{"SRNI (SGW Restoration Needed Indication)", "gtpv2.snri",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}
},
{&hf_gtpv2_s6af,
{"S6AF (Static IPv6 Address Flag)", "gtpv2.s6af",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL}
},
{&hf_gtpv2_s4af,
{"S4AF (Static IPv4 Address Flag))", "gtpv2.s4af",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL}
},
{&hf_gtpv2_mbmdt,
{"MBMDT (Management Based MDT allowed flag)", "gtpv2.mbmdt",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_israu,
{"ISRAU (ISR is activated for the UE)", "gtpv2.israu",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_ccrsi,
{"CCRSI (CSG Change Reporting support indication)", "gtpv2.ccrsi",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{&hf_gtpv2_cprai,
{"CPRAI (Change of Presence Reporting Area information Indication)", "gtpv2.cprai",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{&hf_gtpv2_arrl,
{"ARRL (Abnormal Release of Radio Link)", "gtpv2.arrl",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}
},
{&hf_gtpv2_ppof,
{"PPOFF (PDN Pause Off Indication)", "gtpv2.ppof",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}
},
{&hf_gtpv2_ppon_ppei,
{"PPON (PDN Pause On Indication) / PPEI (PDN Pause Enabled Indication)", "gtpv2.ppon_ppei",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL}
},
{&hf_gtpv2_ppsi,
{"PPSI (PDN Pause Support Indication)", "gtpv2.ppsi",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL}
},
{&hf_gtpv2_csfbi,
{"CSFBI (CSFB Indication)", "gtpv2.csfbi",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_clii,
{"CLII (Change of Location Information Indication):", "gtpv2.clii",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_cpsr,
{"CPSR (CS to PS SRVCC indication)", "gtpv2.cpsr",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{&hf_gtpv2_pcri,
{"PCRI (P-CSCF Restoration Indication)", "gtpv2.pcri",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL}
},
{&hf_gtpv2_aosi,
{"AOSI (Associate OCI with SGW node's Identity)", "gtpv2.aosi",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL}
},
{&hf_gtpv2_aopi,
{"AOPI (Associate OCI with PGW node's Identity)", "gtpv2.aopi",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL}
},
{ &hf_gtpv2_pdn_type,
{"PDN Type", "gtpv2.pdn_type",
FT_UINT8, BASE_DEC, VALS(gtpv2_pdn_type_vals), 0x07,
NULL, HFILL}
},
#if 0
{ &hf_gtpv2_tra_info,
{"Trace ID", "gtpv2.tra_info",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
#endif
{ &hf_gtpv2_tra_info_msc_momt_calls,
{"MO and MT calls", "gtpv2.tra_info_msc_momt_calls",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_msc_momt_sms,
{"MO and MT SMS", "gtpv2.tra_info_msc_momt_sms",
FT_UINT8, BASE_DEC, NULL, 0x02,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_msc_lu_imsi_ad,
{"LU, IMSI attach, IMSI detach", "gtpv2.tra_info_msc_lu_imsi_ad",
FT_UINT8, BASE_DEC, NULL, 0x04,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_msc_handovers,
{"Handovers", "gtpv2.tra_info_msc_handovers",
FT_UINT8, BASE_DEC, NULL, 0x08,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_msc_ss,
{"SS", "gtpv2.tra_info_msc_ss",
FT_UINT8, BASE_DEC, NULL, 0x10,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_mgw_context,
{"Context", "gtpv2.tra_info_mgw_context",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MGW", HFILL}
},
{ &hf_gtpv2_tra_info_sgsn_pdp_context,
{"PDP context", "gtpv2.tra_info_sgsn_pdp_context",
FT_UINT8, BASE_DEC, NULL, 0x01,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_sgsn_momt_sms,
{"MO and MT SMS", "gtpv2.tra_info_sgsn_momt_sms",
FT_UINT8, BASE_DEC, NULL, 0x02,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_sgsn_rau_gprs_ad,
{"RAU, GPRS attach, GPRS detach", "gtpv2.tra_info_sgsn_rau_gprs_ad",
FT_UINT8, BASE_DEC, NULL, 0x04,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_sgsn_mbms,
{"MBMS Context", "gtpv2.tra_into_sgsn_mbms",
FT_UINT8, BASE_DEC, NULL, 0x08,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_sgsn_reserved,
{"Reserved", "gtpv2.",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_ggsn_pdp,
{"PDP Cpntext", "gtpv2.tra_info_ggsn_pdp",
FT_UINT8, BASE_DEC, NULL, 0x01,
"GGSN", HFILL}
},
{ &hf_gtpv2_tra_info_ggsn_mbms,
{"MBMS Context", "gtpv2.tra_info_ggsn_mbms",
FT_UINT8, BASE_DEC, NULL, 0x02,
"GGSN", HFILL}
},
{ &hf_gtpv2_tra_info_bm_sc,
{"MBMS Multicast service activation", "gtpv2.tra_info_bm_sc",
FT_UINT8, BASE_DEC, NULL, 0x01,
"BM-SC", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_ss,
{"Session setup", "gtpv2.tra_info_mme_sgw_ss",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_sr,
{"Service Request", "gtpv2.tra_info_mme_sgw_sr",
FT_UINT8, BASE_DEC, NULL, 0x02,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_iataud,
{"Initial Attach, Tracking area update, Detach", "gtpv2.tra_info_mme_sgw_iataud",
FT_UINT8, BASE_DEC, NULL, 0x04,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_ue_init_pdn_disc,
{"UE initiated PDN disconnection", "gtpv2.tra_info_mme_sgw_ue_init_pdn_disc",
FT_UINT8, BASE_DEC, NULL, 0x08,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_bearer_act_mod_del,
{"Bearer Activation Modification Deletion", "gtpv2.tra_info_mme_sgw_bearer_act_mod_del",
FT_UINT8, BASE_DEC, NULL, 0x10,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_mme_sgw_ho,
{"Handover", "gtpv2.tra_info_mme_sgw_ho",
FT_UINT8, BASE_DEC, NULL, 0x20,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_sgw_pdn_con_creat,
{"PDN Connection creation", "gtpv2.tra_info_sgw_pdn_con_creat",
FT_UINT8, BASE_DEC, NULL, 0x01,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_sgw_pdn_con_term,
{"PDN connection termination", "gtpv2.tra_info_sgw_pdn_con_term",
FT_UINT8, BASE_DEC, NULL, 0x02,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_sgw_bearer_act_mod_del,
{"Bearer Activation Modification Deletion", "gtpv2.tra_info_sgw_bearer_act_mod_del",
FT_UINT8, BASE_DEC, NULL, 0x04,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_pgw_pdn_con_creat,
{"PDN Connection creation", "gtpv2.tra_info_pgw_pdn_con_creat",
FT_UINT8, BASE_DEC, NULL, 0x10,
"PGW", HFILL}
},
{ &hf_gtpv2_tra_info_pgw_pdn_con_term,
{"PDN connection termination", "gtpv2.tra_info_pgw_pdn_con_term",
FT_UINT8, BASE_DEC, NULL, 0x20,
"PGW", HFILL}
},
{ &hf_gtpv2_tra_info_pgw_bearer_act_mod_del,
{"Bearer Activation Modification Deletion", "gtpv2.tra_info_pgw_bearer_act_mod_del",
FT_UINT8, BASE_DEC, NULL, 0x40,
"PGW", HFILL}
},
{ &hf_gtpv2_tra_info_lne_msc_s,
{"MSC-S", "gtpv2.tra_info_lne_msc_s",
FT_UINT8, BASE_DEC, NULL, 0x01,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_mgw,
{"MGW", "gtpv2.tra_info_lne_mgw",
FT_UINT8, BASE_DEC, NULL, 0x02,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_sgsn,
{"SGSN", "gtpv2.tra_info_lne_sgsn",
FT_UINT8, BASE_DEC, NULL, 0x04,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_ggsn,
{"GGSN", "gtpv2.tra_info_lne_ggsn",
FT_UINT8, BASE_DEC, NULL, 0x08,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_rnc,
{"RNC", "gtpv2.tra_info_lne_rnc",
FT_UINT8, BASE_DEC, NULL, 0x10,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_bm_sc,
{"BM-SC", "gtpv2.tra_info_lne_bm_sc",
FT_UINT8, BASE_DEC, NULL, 0x20,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_mme,
{"MME", "gtpv2.tra_info_lne_mme",
FT_UINT8, BASE_DEC, NULL, 0x40,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_sgw,
{"SGW", "gtpv2.tra_info_lne_sgw",
FT_UINT8, BASE_DEC, NULL, 0x80,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_pdn_gw,
{"PDN GW", "gtpv2.tra_info_lne_pdn_gw",
FT_UINT8, BASE_DEC, NULL, 0x01,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_lne_enb,
{"eNB", "gtpv2.tra_info_lne_enb",
FT_UINT8, BASE_DEC, NULL, 0x02,
"List of NE Types", HFILL}
},
{ &hf_gtpv2_tra_info_tdl,
{"Trace Depth Length", "gtpv2.tra_info_tdl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_a,
{"A", "gtpv2.tra_info_lmsc_a",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_lu,
{"Iu", "gtpv2.tra_info_lmsc_lu",
FT_UINT8, BASE_DEC, NULL, 0x02,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_mc,
{"Mc", "gtpv2.tra_info_lmsc_mc",
FT_UINT8, BASE_DEC, NULL, 0x04,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_g,
{"MAP-G", "gtpv2.tra_info_lmsc_map_g",
FT_UINT8, BASE_DEC, NULL, 0x08,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_b,
{"MAP-B", "gtpv2.tra_info_lmsc_map_b",
FT_UINT8, BASE_DEC, NULL, 0x10,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_e,
{"MAP-E", "gtpv2.tra_info_lmsc_map_e",
FT_UINT8, BASE_DEC, NULL, 0x20,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_f,
{"MAP-F", "gtpv2.tra_info_lmsc_map_f",
FT_UINT8, BASE_DEC, NULL, 0x40,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_cap,
{"CAP", "gtpv2.tra_info_lmsc_cap",
FT_UINT8, BASE_DEC, NULL, 0x80,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_d,
{"MAP-D", "gtpv2.tra_info_lmsc_map_d",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmsc_map_c,
{"MAP-C", "gtpv2.tra_info_lmsc_map_c",
FT_UINT8, BASE_DEC, NULL, 0x02,
"MSC Server", HFILL}
},
{ &hf_gtpv2_tra_info_lmgw_mc,
{"Mc", "gtpv2.tra_info_lmgw_mc",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MGW", HFILL}
},
{ &hf_gtpv2_tra_info_lmgw_nb_up,
{"Nb-UP", "gtpv2.tra_info_lmgw_nb_up",
FT_UINT8, BASE_DEC, NULL, 0x2,
"MGW", HFILL}
},
{ &hf_gtpv2_tra_info_lmgw_lu_up,
{"Iu-UP", "gtpv2.tra_info_lmgw_lu_up",
FT_UINT8, BASE_DEC, NULL, 0x04,
"MGW", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_gb,
{"Gb", "gtpv2.tra_info_lsgsn_gb",
FT_UINT8, BASE_DEC, NULL, 0x01,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_lu,
{"Iu", "gtpv2.tra_info_lsgsn_lu",
FT_UINT8, BASE_DEC, NULL, 0x02,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_gn,
{"Gn", "gtpv2.tra_info_lsgsn_gn",
FT_UINT8, BASE_DEC, NULL, 0x04,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_map_gr,
{"MAP-Gr", "gtpv2.tra_info_lsgsn_map_gr",
FT_UINT8, BASE_DEC, NULL, 0x08,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_map_gd,
{"MAP-Gd", "gtpv2.tra_info_lsgsn_map_gd",
FT_UINT8, BASE_DEC, NULL, 0x10,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_map_gf,
{"MAP-Gf", "gtpv2.tra_info_lsgsn_map_gf",
FT_UINT8, BASE_DEC, NULL, 0x20,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_gs,
{"Gs", "gtpv2.tra_info_lsgsn_gs",
FT_UINT8, BASE_DEC, NULL, 0x40,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lsgsn_ge,
{"Ge", "gtpv2.tra_info_lsgsn_ge",
FT_UINT8, BASE_DEC, NULL, 0x80,
"SGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lggsn_gn,
{"Gn", "gtpv2.tra_info_lggsn_gn",
FT_UINT8, BASE_DEC, NULL, 0x01,
"GGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lggsn_gi,
{"Gi", "gtpv2.tra_info_lggsn_gi",
FT_UINT8, BASE_DEC, NULL, 0x02,
"GGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lggsn_gmb,
{"Gmb", "gtpv2.tra_info_lggsn_gmb",
FT_UINT8, BASE_DEC, NULL, 0x04,
"GGSN", HFILL}
},
{ &hf_gtpv2_tra_info_lrnc_lu,
{"Iu", "gtpv2.tra_info_lrnc_lu",
FT_UINT8, BASE_DEC, NULL, 0x01,
"RNC", HFILL}
},
{ &hf_gtpv2_tra_info_lrnc_lur,
{"Iur", "gtpv2.tra_info_lrnc_lur",
FT_UINT8, BASE_DEC, NULL, 0x02,
"RNC", HFILL}
},
{ &hf_gtpv2_tra_info_lrnc_lub,
{"Iub", "gtpv2.tra_info_lrnc_lub",
FT_UINT8, BASE_DEC, NULL, 0x04,
"RNC", HFILL}
},
{ &hf_gtpv2_tra_info_lrnc_uu,
{"Uu", "gtpv2.tra_info_lrnc_uu",
FT_UINT8, BASE_DEC, NULL, 0x08,
"RNC", HFILL}
},
{ &hf_gtpv2_tra_info_lbm_sc_gmb,
{"Gmb", "gtpv2.tra_info_lbm_sc_gmb",
FT_UINT8, BASE_DEC, NULL, 0x01,
"BM-SC", HFILL}
},
{ &hf_gtpv2_tra_info_lmme_s1_mme,
{"S1-MME", "gtpv2.tra_info_lmme_s1_mme",
FT_UINT8, BASE_DEC, NULL, 0x01,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_lmme_s3,
{"S3", "gtpv2.tra_info_lmme_s3",
FT_UINT8, BASE_DEC, NULL, 0x02,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_lmme_s6a,
{"S6a", "gtpv2.tra_info_lmme_s6a",
FT_UINT8, BASE_DEC, NULL, 0x04,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_lmme_s10,
{"S10", "gtpv2.tra_info_lmme_s10",
FT_UINT8, BASE_DEC, NULL, 0x08,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_lmme_s11,
{"S11", "gtpv2.tra_info_lmme_s11",
FT_UINT8, BASE_DEC, NULL, 0x10,
"MME", HFILL}
},
{ &hf_gtpv2_tra_info_lsgw_s4,
{"S4", "gtpv2.tra_info_lsgw_s4",
FT_UINT8, BASE_DEC, NULL, 0x01,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_lsgw_s5,
{"S5", "gtpv2.tra_info_lsgw_s5",
FT_UINT8, BASE_DEC, NULL, 0x02,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_lsgw_s8b,
{"S8b", "gtpv2.tra_info_lsgw_s8b",
FT_UINT8, BASE_DEC, NULL, 0x04,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_lsgw_s11,
{"S11", "gtpv2.tra_info_lsgw_s11",
FT_UINT8, BASE_DEC, NULL, 0x08,
"SGW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s2a,
{"S2a", "gtpv2.tra_info_lpdn_gw_s2a",
FT_UINT8, BASE_DEC, NULL, 0x01,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s2b,
{"S2b", "gtpv2.tra_info_lpdn_gw_s2b",
FT_UINT8, BASE_DEC, NULL, 0x02,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s2c,
{"S2c", "gtpv2.tra_info_lpdn_gw_s2c",
FT_UINT8, BASE_DEC, NULL, 0x04,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s5,
{"S5", "gtpv2.tra_info_lpdn_gw_s5",
FT_UINT8, BASE_DEC, NULL, 0x08,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s6c,
{"S6c", "gtpv2.tra_info_lpdn_gw_s6c",
FT_UINT8, BASE_DEC, NULL, 0x10,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_gx,
{"Gx", "gtpv2.tra_info_lpdn_gw_gx",
FT_UINT8, BASE_DEC, NULL, 0x20,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_s8b,
{"S8b", "gtpv2.tra_info_lpdn_gw_s8b",
FT_UINT8, BASE_DEC, NULL, 0x40,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lpdn_gw_sgi,
{"SGi", "gtpv2.tra_info_lpdn_gw_sgi",
FT_UINT8, BASE_DEC, NULL, 0x80,
"PDN GW", HFILL}
},
{ &hf_gtpv2_tra_info_lenb_s1_mme,
{"S1-MME", "gtpv2.tra_info_lenb_s1_mme",
FT_UINT8, BASE_DEC, NULL, 0x01,
"eNB", HFILL}
},
{ &hf_gtpv2_tra_info_lenb_x2,
{"X2", "gtpv2.tra_info_lenb_x2",
FT_UINT8, BASE_DEC, NULL, 0x02,
"eNB", HFILL}
},
{ &hf_gtpv2_tra_info_lenb_uu,
{"Uu", "gtpv2.tra_info_lenb_uu",
FT_UINT8, BASE_DEC, NULL, 0x04,
"eNB", HFILL}
},
{ &hf_gtpv2_pdn_ipv4,
{"PDN Address and Prefix(IPv4)", "gtpv2.pdn_addr_and_prefix.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_pdn_ipv6_len,
{"IPv6 Prefix Length", "gtpv2.pdn_ipv6_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_pdn_ipv6,
{"PDN Address and Prefix(IPv6)", "gtpv2.pdn_addr_and_prefix.ipv6",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_pvi,
{"PVI (Pre-emption Vulnerability)", "gtpv2.bearer_qos_pvi",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x01,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_pl,
{"PL (Priority Level)", "gtpv2.bearer_qos_pl",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_pci,
{"PCI (Pre-emption Capability)", "gtpv2.bearer_qos_pci",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x40,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_label_qci,
{"Label (QCI)", "gtpv2.bearer_qos_label_qci",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_mbr_up,
{"Maximum Bit Rate For Uplink", "gtpv2.bearer_qos_mbr_up",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_mbr_down,
{"Maximum Bit Rate For Downlink", "gtpv2.bearer_qos_mbr_down",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_gbr_up,
{"Guaranteed Bit Rate For Uplink", "gtpv2.bearer_qos_gbr_up",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_qos_gbr_down,
{"Guaranteed Bit Rate For Downlink", "gtpv2.bearer_qos_gbr_down",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_flow_qos_label_qci,
{"Label (QCI)", "gtpv2.flow_qos_label_qci",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_flow_qos_mbr_up,
{"Maximum Bit Rate For Uplink", "gtpv2.flow_qos_mbr_up",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_flow_qos_mbr_down,
{"Maximum Bit Rate For Downlink", "gtpv2.flow_qos_mbr_down",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_flow_qos_gbr_up,
{"Guaranteed Bit Rate For Uplink", "gtpv2.flow_qos_gbr_up",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_flow_qos_gbr_down,
{"Guaranteed Bit Rate For Downlink", "gtpv2.flow_qos_gbr_down",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_rat_type,
{"RAT Type", "gtpv2.rat_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_rat_type_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_uli_ecgi_flg,
{"ECGI Present Flag", "gtpv2.uli_ecgi_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_ECGI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_uli_lai_flg,
{"LAI Present Flag", "gtpv2.uli_lai_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_LAI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_uli_tai_flg,
{"TAI Present Flag", "gtpv2.uli_tai_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_TAI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_uli_rai_flg,
{"RAI Present Flag", "gtpv2.uli_rai_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_RAI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_uli_sai_flg,
{"SAI Present Flag", "gtpv2.uli_sai_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_SAI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_uli_cgi_flg,
{"CGI Present Flag", "gtpv2.uli_cgi_flg",
FT_BOOLEAN, 8, NULL, GTPv2_ULI_CGI_MASK,
NULL, HFILL}
},
{ &hf_gtpv2_glt,
{"Geographic Location Type", "gtpv2.glt",
FT_UINT8, BASE_DEC, VALS(geographic_location_type_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_uli_cgi_lac,
{"Location Area Code", "gtpv2.uli_cgi_lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_uli_cgi_ci,
{"Cell Identity", "gtpv2.uli_cgi_ci",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_sai_lac,
{"Location Area Code", "gtpv2.sai_lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_sai_sac,
{"Service Area Code", "gtpv2.sai_sac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_rai_lac,
{"Location Area Code", "gtpv2.rai_lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_rai_rac,
{"Routing Area Code", "gtpv2.rai_rac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_tai_tac,
{"Tracking Area Code", "gtpv2.tai_tac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_ecgi_eci,
{"ECI (E-UTRAN Cell Identifier)", "gtpv2.ecgi_eci",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_uli_lai_lac,
{"Location Area Code (LAC)", "gtpv2.uli_lai_lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_ecgi_eci_spare,
{"Spare", "gtpv2.uli_ecgi_eci_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_nsapi,
{"NSAPI", "gtpv2.nsapi",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{&hf_gtpv2_f_teid_v4,
{"V4", "gtpv2.f_teid_v4",
FT_BOOLEAN, 8, TFS(&gtpv2_f_teid_v4_vals), 0x80,
NULL, HFILL}
},
{&hf_gtpv2_f_teid_v6,
{"V6", "gtpv2.f_teid_v6",
FT_BOOLEAN, 8, TFS(&gtpv2_f_teid_v6_vals), 0x40,
NULL, HFILL}
},
{&hf_gtpv2_f_teid_interface_type,
{"Interface Type", "gtpv2.f_teid_interface_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_f_teid_interface_type_vals_ext, 0x3f,
NULL , HFILL}
},
{&hf_gtpv2_f_teid_gre_key,
{"TEID/GRE Key", "gtpv2.f_teid_gre_key",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL , HFILL}
},
{ &hf_gtpv2_f_teid_ipv4,
{"F-TEID IPv4", "gtpv2.f_teid_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_f_teid_ipv6,
{"F-TEID IPv6", "gtpv2.f_teid_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_tmsi,
{"TMSI", "gtpv2.tmsi",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_hsgw_addr_f_len,
{"HSGW Address for forwarding Length", "gtpv2.hsgw_addr_f_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_hsgw_addr_ipv4,
{"HSGW Address for forwarding", "gtpv2.hsgw_addr_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_hsgw_addr_ipv6,
{"HSGW Address for forwarding", "gtpv2.hsgw_addr_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_gre_key,
{"GRE Key", "gtpv2.gre_key",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL , HFILL}
},
{ &hf_gtpv2_sgw_addr_ipv4,
{"Serving GW Address", "gtpv2.sgw_addr_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_sgw_addr_ipv6,
{"Serving GW Address", "gtpv2.sgw_addr_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_sgw_s1u_teid,
{"Serving GW S1-U TEID", "gtpv2.sgw_s1u_teid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_delay_value,
{"Delay Value (In integer multiples of 50 milliseconds or zero)", "gtpv2.delay_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_charging_id,
{"Charging id", "gtpv2.charging_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_charging_characteristic,
{"Charging Characteristic", "gtpv2.charging_characteristic",
FT_UINT16, BASE_HEX, NULL, 0xffff,
NULL, HFILL}
},
{&hf_gtpv2_bearer_flag_ppc,
{"PPC (Prohibit Payload Compression)", "gtpv2.bearer_flag.ppc",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{&hf_gtpv2_bearer_flag_vb,
{"VB (Voice Bearer)", "gtpv2.bearer_flag.vb",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{&hf_gtpv2_pti,
{"Procedure Transaction Id", "gtpv2.pti",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_sm,
{"Security Mode", "gtpv2.mm_context_sm",
FT_UINT8, BASE_DEC, VALS(gtpv2_mm_context_security_mode), 0xe0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nhi,
{"NHI(Next Hop Indicator)", "gtpv2.mm_context_nhi",
FT_BOOLEAN, 8, TFS(&gtpv2_nhi_vals), 0x10,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_drxi,
{"DRXI", "gtpv2.mm_context_drxi",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_cksn,
{"CKSN", "gtpv2.mm_context_cksn",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_cksn_ksi,
{"CKSN/KSI", "gtpv2.mm_context_cksn_ksi",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_metric,
{"Metric", "gtpv2.metric",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_throttling_factor,
{"Throttling Factor", "gtpv2.throttling_factor",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gtpv2_relative_capacity,
{"Relative Capacity", "gtpv2.relative_capacity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_apn_length,
{"APN Length", "gtpv2.apn_length",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_sequence_number,
{"Sequence Number", "gtpv2.sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_ksi_a,
{"KSI_asme", "gtpv2.mm_context_ksi_a",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nr_tri,
{"Number of Triplet", "gtpv2.mm_context_nr_tri",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_used_cipher,
{"Used Cipher", "gtpv2.mm_context_used_cipher",
FT_UINT8, BASE_DEC, VALS(gtpv2_mm_context_used_cipher_vals), 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_unipa,
{"Used NAS integrity protection algorithm", "gtpv2.mm_context_unipa",
FT_UINT8, BASE_DEC, VALS(gtpv2_mm_context_unipa_vals), 0x70,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_unc,
{"Used NAS Cipher", "gtpv2.mm_context_unc",
FT_UINT8, BASE_DEC, VALS(gtpv2_mm_context_unc_vals), 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nas_dl_cnt,
{"NAS Downlink Count", "gtpv2.mm_context_nas_dl_cnt",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nas_ul_cnt,
{"NAS Uplink Count", "gtpv2.mm_context_nas_ul_cnt",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_kasme,
{"Kasme", "gtpv2.mm_context_kasme",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_rand,
{"RAND", "gtpv2.mm_context_rand",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_uci_csg_id,
{"CSG ID", "gtpv2.cui_csg_id",
FT_UINT32, BASE_DEC, NULL, 0x07FFFFFF,
NULL, HFILL}
},
{&hf_gtpv2_uci_csg_id_spare,
{"Spare", "gtpv2.cui_csg_id_spare",
FT_UINT8, BASE_DEC, NULL, 0xF8,
NULL, HFILL}
},
{ &hf_gtpv2_uci_csg_membership,
{ "CSG Membership Indication", "gtpv2.uci_csg_membership",
FT_UINT8, BASE_DEC, VALS(gtpv2_uci_csg_membership_status), 0x01,
NULL, HFILL }
},
{ &hf_gtpv2_uci_access_mode,
{"Access Mode", "gtpv2.uci_access_mode",
FT_UINT8, BASE_DEC, VALS(gtpv2_uci_access_mode), 0xC0,
NULL, HFILL }
},
{ &hf_gtpv2_uci_lcsg,
{"Leave CSG", "gtpv2.uci_leave_csg",
FT_UINT8, BASE_DEC, VALS(gtpv2_uci_leave_csg), 0x02,
NULL, HFILL }
},
{ &hf_gtpv2_mm_context_xres_len,
{"XRES Length", "gtpv2.mm_context_xres_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_xres,
{"XRES", "gtpv2.mm_context_xres",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_autn_len,
{"AUTN Length", "gtpv2.mm_context_autn_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_autn,
{"AUTN", "gtpv2.mm_context_autn",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_drx,
{"DRX", "gtpv2.mm_context_drx",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_vdp_length,
{"VDP and UE's Usage Setting length", "gtpv2.vdp_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_ue_net_cap_len,
{"Length of UE Network Capability", "gtpv2.mm_context_ue_net_cap_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_ms_net_cap_len,
{"Length of MS Network Capability", "gtpv2.mm_context_ms_net_cap_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_mei_len,
{"Length of Mobile Equipment Identity (MEI)", "gtpv2.mm_context_mei_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_vdp_len,
{"Length of Voice Domain Preference and UE's Usage Setting", "gtpv2.mm_context_vdp_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_una,
{ "UTRAN", "gtpv2.mm_context.una",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x01,
NULL, HFILL }
},
{ &hf_gtpv2_gena,
{ "GERAN", "gtpv2.mm_context.gena",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x02,
NULL, HFILL }
},
{ &hf_gtpv2_gana,
{ "GAN", "gtpv2.mm_context.gana",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x04,
NULL, HFILL }
},
{ &hf_gtpv2_ina,
{ "I-HSPA-EVOLUTION", "gtpv2.mm_context.ina",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x08,
NULL, HFILL }
},
{ &hf_gtpv2_ena,
{ "E-UTRAN", "gtpv2.mm_context.ena",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x10,
NULL, HFILL }
},
{ &hf_gtpv2_hnna,
{ "HO-toNone3GPP-Access", "gtpv2.mm_context.hnna",
FT_BOOLEAN, 8, TFS(&tfs_not_allowed_allowed), 0x20,
NULL, HFILL }
},
{ &hf_gtpv2_mm_context_ksi,
{"KSI", "gtpv2.mm_context_ksi",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nr_qui,
{"Number of Quintuplets", "gtpv2.mm_context_nr_qui",
FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_nr_qua,
{"Number of Quadruplet", "gtpv2.mm_context_nr_qua",
FT_UINT8, BASE_DEC, NULL, 0x1c,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_uamb_ri,
{"UAMB RI", "gtpv2.mm_context_uamb_ri",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_osci,
{"OSCI", "gtpv2.mm_context_osci",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_samb_ri,
{"SAMB RI", "gtpv2.mm_context_samb_ri",
FT_BOOLEAN, 8, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ue_time_zone_dst,
{"Daylight Saving Time", "gtpv2.ue_time_zone_dst",
FT_UINT8, BASE_DEC, VALS(gtpv2_ue_time_zone_dst_vals), 0x03,
NULL, HFILL}
},
{ &hf_gtpv2_fq_csid_type,
{"Node-ID Type", "gtpv2.fq_csid_type",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_gtpv2_fq_csid_nr,
{"Number of CSIDs", "gtpv2.fq_csid_nr",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_fq_csid_ipv4,
{"Node-ID (IPv4)", "gtpv2.fq_csid_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_fq_csid_ipv6,
{"Node-ID (IPv6)", "gtpv2.fq_csid_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_fq_csid_id,
{"CSID", "gtpv2.fq_csid_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_complete_req_msg_type,
{"Complete Request Message Type", "gtpv2.complete_req_msg_type",
FT_UINT8, BASE_DEC, VALS(gtpv2_complete_req_msg_type_vals), 0x0,
NULL, HFILL}
},
{&hf_gtpv2_mme_grp_id,
{"MME Group ID", "gtpv2.mme_grp_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mme_code,
{"MME Code", "gtpv2.mme_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_m_tmsi,
{"M-TMSI", "gtpv2.m_tmsi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_container_type,
{"Container Type", "gtpv2.container_type",
FT_UINT8, BASE_DEC, VALS(gtpv2_container_type_vals), 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_cause_type,
{"Cause Type", "gtpv2.cause_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_cause_type_vals_ext, 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_CauseRadioNetwork,
{"Radio Network Layer Cause", "gtpv2.CauseRadioNetwork",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseRadioNetwork_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_CauseTransport,
{"Transport Layer Cause", "gtpv2.CauseTransport",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseTransport_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_CauseNas,
{"NAS Cause", "gtpv2.CauseNas",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseNas_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_CauseMisc,
{"Miscellaneous Cause", "gtpv2.CauseMisc",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseMisc_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_target_type,
{"Target Type", "gtpv2.target_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_target_type_vals_ext, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_macro_enodeb_id,
{"Macro eNodeB ID", "gtpv2.macro_enodeb_id",
FT_UINT24, BASE_HEX, NULL, 0x0fffff,
NULL, HFILL}
},
{ &hf_gtpv2_CauseProtocol,
{"Protocol Cause", "gtpv2.CauseProtocol",
FT_UINT8, BASE_DEC, VALS(s1ap_CauseProtocol_vals), 0x0,
NULL, HFILL}
},
{&hf_gtpv2_apn_rest,
{"APN Restriction", "gtpv2.apn_rest",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_selec_mode,
{"Selection Mode", "gtpv2.selec_mode",
FT_UINT8, BASE_DEC, VALS(gtpv2_selec_mode_vals), 0x03,
NULL, HFILL}
},
{ &hf_gtpv2_source_type,
{"Source Type", "gtpv2.source_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_gtpv2_bearer_control_mode,
{"Bearer Control Mode", "gtpv2.bearer_control_mode",
FT_UINT8, BASE_DEC, VALS(gtpv2_bearer_control_mode_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_cng_rep_act,
{"Change Reporting Action", "gtpv2.cng_rep_act",
FT_UINT8, BASE_DEC, VALS(gtpv2_cng_rep_act_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_node_type,
{"Node Type", "gtpv2.node_type",
FT_UINT8, BASE_DEC, VALS(gtpv2_node_type_vals), 0x0,
NULL, HFILL}
},
{&hf_gtpv2_fqdn,
{"FQDN", "gtpv2.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_enterprise_id,
{"Enterprise ID", "gtpv2.enterprise_id",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ti,
{"Transaction Identifier", "gtpv2.ti",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_bss_container_phx,
{"PHX", "gtpv2.bss_cont.phx",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x08,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_sapi_flg,
{"SAPI", "gtpv2.bss_cont.sapi_flg",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x04,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_rp_flg,
{"RP", "gtpv2.bss_cont.rp_flg",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_pfi_flg,
{"PFI", "gtpv2.bss_cont.pfi_flg",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_pfi,
{"Packet Flow ID(PFI)", "gtpv2.bss_cont.pfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_rp,
{"Radio Priority(RP)", "gtpv2.bss_cont.rp",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_sapi,
{"SAPI", "gtpv2.bss_cont.sapi",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_xid_len,
{"XiD parameters length", "gtpv2.bss_cont.xid_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_bss_con_xid,
{"XiD parameters", "gtpv2.bss_cont.xid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_home_enodeb_id,
{"Home eNodeB ID", "gtpv2.home_enodeb_id",
FT_UINT32, BASE_HEX, NULL, 0x0fffffff,
NULL, HFILL}
},
{ &hf_gtpv2_tac,
{"Tracking Area Code (TAC)", "gtpv2.tac",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_service_area_nr,
{"Number of MBMS Service Area codes", "gtpv2.mbms_service_area_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_service_area_id,
{"MBMS Service Area code (Service Area Identity)", "gtpv2.mbms_service_area_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_session_id,
{"MBMS Session Identifier", "gtpv2.mbms_session_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_flow_id,
{"MBMS Flow Identifier", "gtpv2.mbms_flow_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_cteid,
{"Common Tunnel Endpoint Identifier", "gtpv2.cetid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ip_addr_type,
{"IP Address Type", "gtpv2.ip_addr_type",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL}
},
{ &hf_gtpv2_ip_addr_len,
{"IP Address Length", "gtpv2.ip_addr_len",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_ip_mc_dist_addrv4,
{"MBMS IP Multicast Distribution Address (IPv4)", "gtpv2.mbms_ip_mc_dist_addrv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_ip_mc_dist_addrv6,
{"MBMS IP Multicast Distribution Address (IPv6)", "gtpv2.mbms_ip_mc_dist_addrv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_ip_mc_src_addrv4,
{"MBMS IP Multicast Source Address (IPv4)", "gtpv2.mbms_ip_mc_src_addrv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_ip_mc_src_addrv6,
{"MBMS IP Multicast Source Address (IPv6)", "gtpv2.mbms_ip_mc_src_addrv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_hc_indicator,
{"MBMS HC Indicator", "gtpv2.mbms_hc_indicator",
FT_UINT8, BASE_DEC, VALS(gtpv2_mbms_hc_indicator_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_dist_indication,
{"MBMS Distribution Indication", "gtpv2.mbms_dist_indication",
FT_UINT8, BASE_DEC, VALS(gtpv2_mbms_dist_indication_vals), 0x03,
NULL, HFILL}
},
{ &hf_gtpv2_subscriber_rfsp,
{"Subscribed RFSP Index", "gtpv2.subscriber_rfsp",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_rfsp_inuse,
{"RFSP Index in Use", "gtpv2.rfsp_inuse",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_service_id,
{"MBMS Service ID", "gtpv2.mbms_service_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_add_flags_for_srvcc_ics,
{"ICS (IMS Centralized Service)", "gtpv2.add_flags_for_srvcc_ics",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_vsrvcc_flag,
{"VF (vSRVCC Flag)", "gtpv2.vsrvcc_flag",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_henb_info_report_fti,
{"FTI", "gtpv2.henb_info_report_fti",
FT_BOOLEAN, 8, TFS(&gtpv2_henb_info_report_fti_vals), 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_ip4cp_subnet_prefix_len,
{"Subnet Prefix Length", "gtpv2.ip4cp_subnet_prefix_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_ip4cp_ipv4,
{"IPv4 Default Router Address", "gtpv2.ip4cp_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_change_report_flags_sncr,
{"SNCR (Service Network Change to Report)", "gtpv2.change_report_flags_sncr",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_change_report_flags_tzcr,
{"TZCR (Time Zone Change to Report)", "gtpv2.change_report_flags_tzcr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{&hf_gtpv2_action_indication_val,
{"Action Indication", "gtpv2.action_indication_val",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gtpv2_action_indication_vals_ext, 0x07,
NULL , HFILL}
},
{ &hf_gtpv2_uli_timestamp,
{ "ULI Timestamp", "gtpv2.uli_timestamp",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gtpv2_abs_time_mbms_data,
{ "Absolute Time of MBMS Data Transfer", "gtpv2.abs_time_mbms_data",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gtpv2_mbms_session_duration_days,
{"MBMS Session Duration (days)", "gtpv2.mbms_session_duration_days",
FT_UINT24, BASE_DEC, NULL, 0x00007F,
NULL, HFILL}
},
{ &hf_gtpv2_mbms_session_duration_secs,
{"MBMS Session Duration (seconds)", "gtpv2.mbms_session_duration_secs",
FT_UINT24, BASE_DEC, NULL, 0xFFFF80,
NULL, HFILL}
},
{ &hf_gtpv2_node_features_prn,
{"PGW Restart Notification (PRN)", "gtpv2.node_features_prn",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_node_features_mabr,
{"Modify Access Bearers Request (MABR)", "gtpv2.node_features_mabr",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL}
},
{ &hf_gtpv2_node_features_ntsr,
{"Network Triggered Service Restoration (NTSR)", "gtpv2.node_features_ntsr",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04,
NULL, HFILL}
},
{ &hf_gtpv2_time_to_data_xfer,
{"MBMS Time to Data Transfer", "gtpv2.time_to_data_xfer",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_gtpv2_arp_pvi,
{"Pre-emption Vulnerability (PVI)", "gtpv2.arp_pvi",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_arp_pl,
{"Priority Level", "gtpv2.arp_pl",
FT_UINT8, BASE_DEC, NULL, 0x3c,
NULL, HFILL}
},
{ &hf_gtpv2_arp_pci,
{"Pre-emption Capability (PCI)", "gtpv2.arp_pci",
FT_BOOLEAN, 8, TFS(&tfs_disabled_enabled), 0x40,
NULL, HFILL}
},
{ &hf_gtpv2_timer_unit,
{"Timer unit", "gtpv2.timer_unit",
FT_UINT8, BASE_DEC, VALS(gtpv2_timer_unit_vals), 0xe0,
NULL, HFILL}
},
{ &hf_gtpv2_throttling_delay_unit,
{"Throttling Delay unit", "gtpv2.throttling_delay_unit",
FT_UINT8, BASE_DEC, VALS(gtpv2_throttling_delay_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gtpv2_timer_value,
{"Timer value", "gtpv2.timer_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL}
},
{ &hf_gtpv2_throttling_delay_value,
{"Throttling Delay value", "gtpv2.throttling_delay_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gtpv2_lapi,
{"LAPI (Low Access Priority Indication)", "gtpv2.lapi",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_higher_br_16mb_flg_len,
{"Length of Higher bitrates than 16 Mbps flag", "gtpv2.mm_context_higher_br_16mb_flg_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mm_context_higher_br_16mb_flg,
{"Higher bitrates than 16 Mbps flag", "gtpv2.mm_context_higher_br_16mb_flg",
FT_UINT8, BASE_DEC, VALS(gtpv2_mm_context_higher_br_16mb_flg_vals), 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mmbr_ul,
{"Max MBR/APN-AMBR for uplink", "gtpv2.mmbr_ul",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_mmbr_dl,
{"Max MBR/APN-AMBR for downlink", "gtpv2.mmbr_dl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_action,
{"Action", "gtpv2.pres_rep_area_action.action",
FT_UINT8, BASE_DEC, VALS(gtpv2_pres_rep_area_action_vals), 0x03,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_id,
{"Presence Reporting Area Identifier", "gtpv2.pres_rep_area_action.pres_rep_area_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_tai,
{"Number of TAI", "gtpv2.pres_rep_area_action.no_tai",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_rai,
{"Number of RAI", "gtpv2.pres_rep_area_action.no_rai",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_m_enodeb,
{"Number of Macro eNodeB", "gtpv2.pres_rep_area_action.no_m_enodeb",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_h_enodeb,
{"Number of Home eNodeB", "gtpv2.pres_rep_area_action.no_h_enodeb",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_ecgi,
{"Number of ECGI", "gtpv2.pres_rep_area_action.no_ecgi",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_sai,
{"Number of SAI", "gtpv2.pres_rep_area_action.no_sai",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_pres_rep_area_act_no_cgi,
{"Number of CGI", "gtpv2.pres_rep_area_action.no_cgi",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_gtpv2_ksi_ps,
{ "KSI'ps", "gtpv2.ksi_ps",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gtpv2_ck_ps,
{ "CK'ps", "gtpv2.ck_ps",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gtpv2_ik_ps,
{ "IK'ps", "gtpv2.ik_ps",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gtpv2_kc_ps,
{ "KC'ps", "gtpv2.kc_ps",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gtpv2_cksn_ps,
{ "CKSN'ps", "gtpv2.cksn_ps",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gtpv2_transparent_container, { "Transparent Container", "gtpv2.transparent_container", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_cksrvcc, { "CKsrvcc", "gtpv2.cksrvcc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_iksrvcc, { "IKsrvcc", "gtpv2.iksrvcc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mobile_station_classmark2, { "Mobile Station Classmark2", "gtpv2.mobile_station_classmark2", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mobile_station_classmark3, { "Mobile Station Classmark3", "gtpv2.mobile_station_classmark3", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_supported_codec_list, { "Supported Codec List", "gtpv2.supported_codec_list", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_utran_srvcc_ck_cs, { "CK'cs", "gtpv2.utran_srvcc.ck_cs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_utran_srvcc_ik_cs, { "IK'cs", "gtpv2.utran_srvcc.ik_cs", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_utran_srvcc_kc, { "Kc'", "gtpv2.utran_srvcc.kc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_teid_c_spare, { "Spare", "gtpv2.teid_c.spare", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_geographic_location, { "Geographic Location", "gtpv2.geographic_location", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_tmsi_bytes, { "TMSI", "gtpv2.tmsi_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_cn_id, { "CN-Id", "gtpv2.cn_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_eps_bearer_id_number, { "EPS Bearer ID Number", "gtpv2.eps_bearer_id_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_serving_gw_address_length, { "Serving GW Address Length", "gtpv2.serving_gw_address_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_charging_characteristic_remaining_octets, { "Remaining octets", "gtpv2.charging_characteristic.remaining_octets", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_trace_id, { "Trace ID", "gtpv2.trace_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_drx_parameter, { "DRX parameter", "gtpv2.drx_parameter", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mm_context_sres, { "SRES'", "gtpv2.mm_context_sres", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mm_context_kc, { "Kc'", "gtpv2.mm_context_kc", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_uplink_subscribed_ue_ambr, { "Uplink Subscribed UE AMBR", "gtpv2.uplink_subscribed_ue_ambr", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_downlink_subscribed_ue_ambr, { "Downlink Subscribed UE AMBR", "gtpv2.downlink_subscribed_ue_ambr", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_uplink_used_ue_ambr, { "Uplink Used UE AMBR", "gtpv2.uplink_used_ue_ambr", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_downlink_used_ue_ambr, { "Downlink Used UE AMBR", "gtpv2.downlink_used_ue_ambr", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_voice_domain_and_ue_usage_setting, { "Voice Domain Preference and UE's Usage Setting", "gtpv2.voice_domain_and_ue_usage_setting", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_authentication_quadruplets, { "Authentication Quadruplets", "gtpv2.authentication_quadruplets", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_authentication_quintuplets, { "Authentication Quintuplets", "gtpv2.authentication_quintuplets", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mm_context_nh, { "NH (Next Hop)", "gtpv2.mm_context_nh", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_mm_context_ncc, { "NCC (Next Hop Chaining Count)", "gtpv2.mm_context_ncc", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_gtpv2_nsapi08, { "NSAPI", "gtpv2.nsapi", FT_UINT8, BASE_DEC, NULL, 0x08, NULL, HFILL }},
{ &hf_gtpv2_dl_gtp_u_sequence_number, { "DL GTP-U Sequence Number", "gtpv2.dl_gtp_u_sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_ul_gtp_u_sequence_number, { "UL GTP-U Sequence Number", "gtpv2.ul_gtp_u_sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_send_n_pdu_number, { "Send N-PDU Number", "gtpv2.send_n_pdu_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_receive_n_pdu_number, { "Receive N-PDU Number", "gtpv2.receive_n_pdu_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_hop_counter, { "Hop Counter", "gtpv2.hop_counter", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_packet_flow_id, { "Packet Flow ID", "gtpv2.packet_flow_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_rrc_container, { "RRC Container", "gtpv2.rrc_container", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_upd_source_port_number, { "UPD Source Port Number", "gtpv2.upd_source_port_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_proprietary_value, { "Proprietary value", "gtpv2.proprietary_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_spare_bytes, { "Spare", "gtpv2.spare_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_dl_pdcp_sequence_number, { "DL PDCP Sequence Number", "gtpv2.dl_pdcp_sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_ul_pdcp_sequence_number, { "UL PDCP Sequence Number", "gtpv2.ul_pdcp_sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gtpv2_fq_csid_node_id, { "Node-ID", "gtpv2.fq_csid_node_id", FT_UINT32, BASE_DEC, NULL, 0x00000FFF, NULL, HFILL }},
{ &hf_gtpv2_fq_csid_mcc_mnc, { "MCC+MNC", "gtpv2.fq_csid_mcc_mnc", FT_UINT32, BASE_DEC, NULL, 0xFFFFF000, NULL, HFILL }},
};
static gint *ett_gtpv2_array[] = {
&ett_gtpv2,
&ett_gtpv2_flags,
&ett_gtpv2_ie,
&ett_gtpv2_uli_flags,
&ett_gtpv2_uli_field,
&ett_gtpv2_bearer_ctx,
&ett_gtpv2_PDN_conn,
&ett_gtpv2_overload_control_information,
&ett_gtpv2_mm_context_flag,
&ett_gtpv2_pdn_numbers_nsapi,
&ett_gtpv2_tra_info_trigg,
&ett_gtpv2_tra_info_trigg_msc_server,
&ett_gtpv2_tra_info_trigg_mgw,
&ett_gtpv2_tra_info_trigg_sgsn,
&ett_gtpv2_tra_info_trigg_ggsn,
&ett_gtpv2_tra_info_trigg_bm_sc,
&ett_gtpv2_tra_info_trigg_sgw_mme,
&ett_gtpv2_tra_info_trigg_sgw,
&ett_gtpv2_tra_info_trigg_pgw,
&ett_gtpv2_tra_info_interfaces,
&ett_gtpv2_tra_info_interfaces_imsc_server,
&ett_gtpv2_tra_info_interfaces_lmgw,
&ett_gtpv2_tra_info_interfaces_lsgsn,
&ett_gtpv2_tra_info_interfaces_lggsn,
&ett_gtpv2_tra_info_interfaces_lrnc,
&ett_gtpv2_tra_info_interfaces_lbm_sc,
&ett_gtpv2_tra_info_interfaces_lmme,
&ett_gtpv2_tra_info_interfaces_lsgw,
&ett_gtpv2_tra_info_interfaces_lpdn_gw,
&ett_gtpv2_tra_info_interfaces_lpdn_lenb,
&ett_gtpv2_tra_info_ne_types,
&ett_gtpv2_rai,
&ett_gtpv2_stn_sr,
&ett_gtpv2_ms_mark,
&ett_gtpv2_supp_codec_list,
&ett_gtpv2_bss_con,
&ett_gtpv2_utran_con,
&ett_gtpv2_eutran_con,
&ett_gtpv2_mm_context_auth_qua,
&ett_gtpv2_mm_context_auth_qui,
&ett_gtpv2_mm_context_auth_tri,
&ett_gtpv2_mm_context_net_cap,
&ett_gtpv2_ms_network_capability,
&ett_gtpv2_vd_pref,
&ett_gtpv2_access_rest_data,
&ett_gtpv2_qua,
&ett_gtpv2_qui,
&ett_gtpv2_preaa_tais,
&ett_gtpv2_preaa_menbs,
&ett_gtpv2_preaa_henbs,
&ett_gtpv2_preaa_ecgis,
&ett_gtpv2_preaa_rais,
&ett_gtpv2_preaa_sais,
&ett_gtpv2_preaa_cgis,
&ett_gtpv2_load_control_inf,
};
static ei_register_info ei[] = {
{ &ei_gtpv2_ie_data_not_dissected, { "gtpv2.ie_data_not_dissected", PI_UNDECODED, PI_NOTE, "IE data not dissected yet", EXPFILL }},
{ &ei_gtpv2_ie_len_invalid, { "gtpv2.ie_len_invalid", PI_PROTOCOL, PI_ERROR, "Wrong length", EXPFILL }},
{ &ei_gtpv2_source_type_unknown, { "gtpv2.source_type.unknown", PI_PROTOCOL, PI_ERROR, "Unknown source type", EXPFILL }},
{ &ei_gtpv2_fq_csid_type_bad, { "gtpv2.fq_csid_type.unknown", PI_PROTOCOL, PI_ERROR, "Wrong Node-ID Type", EXPFILL }},
{ &ei_gtpv2_mbms_session_duration_days, { "gtpv2.mbms_session_duration_days.invalid", PI_PROTOCOL, PI_WARN, "Days out of allowed range", EXPFILL }},
{ &ei_gtpv2_mbms_session_duration_secs, { "gtpv2.mbms_session_duration_secs.unknown", PI_PROTOCOL, PI_WARN, "Seconds out of allowed range", EXPFILL }},
{ &ei_gtpv2_ie, { "gtpv2.ie_type.reserved", PI_PROTOCOL, PI_WARN, "IE type Zero is Reserved and should not be used", EXPFILL }},
};
expert_module_t* expert_gtpv2;
proto_gtpv2 = proto_register_protocol("GPRS Tunneling Protocol V2", "GTPv2", "gtpv2");
proto_register_field_array(proto_gtpv2, hf_gtpv2, array_length(hf_gtpv2));
proto_register_subtree_array(ett_gtpv2_array, array_length(ett_gtpv2_array));
expert_gtpv2 = expert_register_protocol(proto_gtpv2);
expert_register_field_array(expert_gtpv2, ei, array_length(ei));
dissector_add_uint("diameter.3gpp", 22, new_create_dissector_handle(dissect_diameter_3gpp_uli, proto_gtpv2));
dissector_add_uint("diameter.3gpp", 2820, new_create_dissector_handle(dissect_diameter_3gpp_presence_reporting_area_elements_list, proto_gtpv2));
register_dissector("gtpv2", dissect_gtpv2, proto_gtpv2);
gtpv2_priv_ext_dissector_table = register_dissector_table("gtpv2.priv_ext", "GTPv2 PRIVATE EXT", FT_UINT16, BASE_DEC);
}
void
proto_reg_handoff_gtpv2(void)
{
nas_eps_handle = find_dissector("nas-eps");
}
