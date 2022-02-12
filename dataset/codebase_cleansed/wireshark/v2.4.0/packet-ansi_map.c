static void
update_saved_invokedata(packet_info *pinfo, struct ansi_tcap_private_t *p_private_tcap){
struct ansi_map_invokedata_t *ansi_map_saved_invokedata;
address* src = &(pinfo->src);
address* dst = &(pinfo->dst);
guint8 *src_str;
guint8 *dst_str;
const char *buf = NULL;
src_str = address_to_str(wmem_packet_scope(), src);
dst_str = address_to_str(wmem_packet_scope(), dst);
if ((!pinfo->fd->flags.visited)&&(p_private_tcap->TransactionID_str)){
switch(ansi_map_response_matching_type){
case ANSI_MAP_TID_ONLY:
buf = wmem_strdup(wmem_packet_scope(), p_private_tcap->TransactionID_str);
break;
case ANSI_MAP_TID_AND_SOURCE:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s",p_private_tcap->TransactionID_str,src_str);
break;
case ANSI_MAP_TID_SOURCE_AND_DEST:
default:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s%s",p_private_tcap->TransactionID_str,src_str,dst_str);
break;
}
ansi_map_saved_invokedata = (struct ansi_map_invokedata_t *)wmem_map_lookup(TransactionId_table,buf);
if(ansi_map_saved_invokedata)
return;
ansi_map_saved_invokedata = wmem_new(wmem_file_scope(), struct ansi_map_invokedata_t);
ansi_map_saved_invokedata->opcode = p_private_tcap->d.OperationCode_private;
ansi_map_saved_invokedata->ServiceIndicator = ServiceIndicator;
wmem_map_insert(TransactionId_table,
wmem_strdup(wmem_file_scope(), buf),
ansi_map_saved_invokedata);
}
}
static void
dissect_ansi_map_min_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
const char *digit_str;
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_mintype);
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offset, tvb_reported_length_remaining(tvb,offset), NULL, FALSE);
proto_tree_add_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, -1, digit_str);
proto_item_append_text(actx->created_item, " - %s", digit_str);
}
static void
dissect_ansi_map_digits_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
guint8 octet , octet_len;
guint8 b1,b2,b3,b4;
int offset = 0;
const char *digit_str;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_digitstype);
proto_tree_add_item(subtree, hf_ansi_map_type_of_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_reservedBitHG, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_si, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitD, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_navail, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_pi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_na, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_np, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_digits_enc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(octet>>4){
case 0:
switch ((octet&0xf)){
case 1:
octet_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
if(octet_len == 0)
return;
offset++;
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offset, tvb_reported_length_remaining(tvb,offset), &Dgt_tbcd, FALSE);
proto_tree_add_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, -1, digit_str);
proto_item_append_text(actx->created_item, " - %s", digit_str);
break;
case 2:
{
const guint8* digits;
octet_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
if(octet_len == 0)
return;
offset++;
proto_tree_add_item_ret_string(subtree, hf_ansi_map_ia5_digits, tvb, offset, tvb_reported_length_remaining(tvb,offset),
ENC_ASCII|ENC_NA, wmem_packet_scope(), &digits);
proto_item_append_text(actx->created_item, " - %s", digits);
}
break;
case 3:
break;
default:
break;
}
break;
case 1:
case 3:
case 4:
case 5:
proto_tree_add_expert(subtree, pinfo, &ei_ansi_map_nr_not_used, tvb, offset, -1);
break;
case 2:
case 6:
case 7:
octet_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
if(octet_len == 0)
return;
offset++;
switch ((octet&0xf)){
case 1:
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offset, tvb_reported_length_remaining(tvb,offset), &Dgt_tbcd, FALSE);
proto_tree_add_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, -1, digit_str);
proto_item_append_text(actx->created_item, " - %s", digit_str);
break;
case 2:
{
const guint8* digits;
proto_tree_add_item_ret_string(subtree, hf_ansi_map_ia5_digits, tvb, offset, tvb_reported_length_remaining(tvb,offset),
ENC_ASCII|ENC_NA, wmem_packet_scope(), &digits);
proto_item_append_text(actx->created_item, " - %s", digits);
}
break;
case 3:
break;
default:
break;
}
break;
case 13:
switch ((octet&0xf)){
case 3:
b1 = tvb_get_guint8(tvb,offset);
offset++;
b2 = tvb_get_guint8(tvb,offset);
offset++;
b3 = tvb_get_guint8(tvb,offset);
offset++;
proto_tree_add_bytes_format_value(subtree, hf_ansi_map_point_code, tvb, offset-3, 3, NULL, "%u-%u-%u", b3, b2, b1);
b4 = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_SSN, tvb, offset, 1, ENC_NA);
proto_item_append_text(actx->created_item, " - Point Code %u-%u-%u SSN %u", b3, b2, b1, b4);
break;
default:
break;
}
break;
case 14:
break;
default:
proto_tree_add_expert(subtree, pinfo, &ei_ansi_map_nr_not_used, tvb, offset, -1);
break;
}
}
static void
dissect_ansi_map_subaddress(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_subaddr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_subaddr_odd_even, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_alertcode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_alertcode_pitch, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_alertcode_cadence, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_alertcode_alertaction, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_announcementcode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_announcementcode_tone, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_announcementcode_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_announcementcode_std_ann, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_announcementcode_cust_ann, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_authorizationperiod(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_authorizationperiod_period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_billingid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_idno, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset + 3;
proto_tree_add_item(subtree, hf_ansi_map_segcount, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_callingfeaturesindicator(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
int length;
proto_tree *subtree;
length = tvb_reported_length_remaining(tvb,offset);
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cwfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfnafa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfbfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfufa, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ctfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_vpfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cdfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_3wcfa, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length--;
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cniroverfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnirfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnip2fa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnip1fa, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
if ( length == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfvmfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ahfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_dpfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_pcwfa, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
if ( length == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfmsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfnrfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cpdsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ccsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
if ( length == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_epefa, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_cdmacallmode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
int length;
proto_tree *subtree;
length = tvb_reported_length_remaining(tvb,offset);
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_namps, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_amps, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cdma, tvb, offset, 1, ENC_BIG_ENDIAN);
length--;
if ( length == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls10, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls9, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls8, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls6, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_cdmachanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
int length;
proto_tree *subtree;
length = tvb_reported_length_remaining(tvb,offset);
subtree = proto_item_add_subtree(actx->created_item, ett_cdmachanneldata);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_Frame_Offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_CDMA_ch_no, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
length = length -2;
proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_band_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b1, tvb, offset, 1, ENC_BIG_ENDIAN);
length = length - 6;
if (length == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_np_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_nominal_pwr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_nr_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_cdmastationclassmark(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_cdmastationclassmark);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_dmi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_smi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitED, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_dtx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_pc, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_channeldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_channeldata);
proto_tree_add_item(subtree, hf_ansi_map_channeldata_scc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_channeldata_dtx, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_channeldata_vmac, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_channeldata_chno, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_confidentialitymodes(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_confidentialitymodes);
proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_dp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_se, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_vp, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_controlchanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_controlchanneldata);
proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_dcc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitFED, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_cmac, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_chno, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_sdcc1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitHGFE, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_sdcc2, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_deniedauthorizationperiod(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_deniedauthorizationperiod_period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_extendedmscid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_extendedmscid);
proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_extendedsystemmytypecode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_extendedsystemmytypecode);
proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dissect_ansi_map_SystemMyTypeCode(TRUE, tvb, offset, actx, subtree, hf_ansi_map_systemMyTypeCode);
}
static void
dissect_ansi_map_handoffstate(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_handoffstate);
proto_tree_add_item(subtree, hf_ansi_map_handoffstate_pi, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_intermsccircuitid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
guint8 octet, octet2;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_tgn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet2 = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_tmn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(actx->created_item, " (G %u/M %u)", octet, octet2);
}
static void
dissect_ansi_map_messagewaitingnotificationcount(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationcount_tom, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationcount_no_mw, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_messagewaitingnotificationtype(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_mwi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_apt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_pt, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_mscid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_mslocation(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_mslocation_lat, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset + 3;
proto_tree_add_item(subtree, hf_ansi_map_mslocation_long, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset + 3;
proto_tree_add_item(subtree, hf_ansi_map_mslocation_res, tvb, offset, -1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_nampscallmode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_nampscallmode_amps, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_nampscallmode_namps, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_nampschanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
proto_tree_add_item(subtree, hf_ansi_map_nampschanneldata_CCIndicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_nampschanneldata_navca, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_onetimefeatureindicator(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
}
static void
dissect_ansi_map_originationtriggers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_originationtriggers);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_rvtc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_unrec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_wz, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_int, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_olata, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ilata, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_local, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_all, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_pa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_dp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_pound, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ds, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_star, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_sevendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_sixdig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fivedig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fourdig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_threedig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_twodig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_onedig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_nodig, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fifteendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fourteendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_thirteendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_twelvedig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_elevendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_tendig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ninedig, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_eightdig, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_pacaindicator(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_pacaindicator);
proto_tree_add_item(subtree, hf_ansi_map_PACA_Level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_pacaindicator_pa, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_pc_ssn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
guint8 b1,b2,b3;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
b1 = tvb_get_guint8(tvb,offset);
offset++;
b2 = tvb_get_guint8(tvb,offset);
offset++;
b3 = tvb_get_guint8(tvb,offset);
offset++;
proto_tree_add_bytes_format_value(subtree, hf_ansi_map_point_code, tvb, offset-3, 3, NULL, "%u-%u-%u", b3, b2, b1);
proto_tree_add_item(subtree, hf_ansi_map_SSN, tvb, offset, 1, ENC_NA);
}
static void
dissect_ansi_map_pilotbillingid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_idno, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset + 3;
proto_tree_add_item(subtree, hf_ansi_map_segcount, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_sms_originationrestrictions(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_sms_originationrestrictions);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitHGFE, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_fmc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_direct, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_default, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_systemcapabilities(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_systemcapabilities);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitHG, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_dp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_ssd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_cave, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_vp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_se, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_auth, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_terminationtriggers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_transactioncapability);
proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_npr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_na, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_rf, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_busy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_transactioncapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_transactioncapability);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_nami, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_ndss, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_uzci, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_spini, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_rui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_ann, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_busy, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_trans_cap_prof, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_trans_cap_waddr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_trans_cap_tl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_trans_cap_multerm, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_cdmaserviceoption(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_cdmaserviceoption);
proto_tree_add_item(subtree, hf_ansi_map_cdmaserviceoption, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_callingpartyname(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
}
static void
dissect_ansi_map_triggercapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_triggercapability);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_ona, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_odisc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_oans, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_oaa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_rvtc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_all, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_kdigit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_init, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_obsy, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_cdraa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_it, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_cgraa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_at, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_pa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_unrec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_ct, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tdisc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tans, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tna, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tbusy, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tra, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_winoperationscapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_winoperationscapability);
proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_pos, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_ccdir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_conn, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_ansi_map_controlnetworkid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_controlnetworkid);
proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
static int
dissect_ansi_map_ElectronicSerialNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MINType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 43 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_min_type(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_MobileIdentificationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MSID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MSID_choice, hf_index, ett_ansi_map_MSID,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationAlgorithmVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationResponseReauthentication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationResponseUniqueChallenge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CallHistoryCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAPrivateLongCodeMask(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DigitsType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 50 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_digits_type(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CarrierDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_CaveKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DenyAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DestinationDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_LocationAreaID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RandomVariableReauthentication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MEID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MobileStationMIN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MSCID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 207 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_mscid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_RandomVariableSSD(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RandomVariableUniqueChallenge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RoutingDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SenderIdentificationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SharedSecretData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SignalingMessageEncryptionKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SSDNotShared(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_UpdateCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationDirective_U_set, hf_index, ett_ansi_map_AuthenticationDirective_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationDirective_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationDirectiveRes_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_InterMSCCircuitID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 182 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_intermsccircuitid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveForward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationDirectiveForward_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveForward_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveForward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationDirectiveForward_U);
return offset;
}
static int
dissect_ansi_map_CountUpdateReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_UniqueChallengeReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveForwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationDirectiveForwardRes_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveForwardRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationDirectiveForwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationDirectiveForwardRes_U);
return offset;
}
static int
dissect_ansi_map_ReportType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SystemAccessType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SystemCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 346 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_systemcapabilities(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CallHistoryCountExpected(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TerminalType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationFailureReport_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationFailureReport_U_set, hf_index, ett_ansi_map_AuthenticationFailureReport_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationFailureReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationFailureReport_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationFailureReportRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationFailureReportRes_U_set, hf_index, ett_ansi_map_AuthenticationFailureReportRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationFailureReportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationFailureReportRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMANetworkIdentification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ConfidentialityModes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 136 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_confidentialitymodes(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_ControlChannelMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Digits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_PC_SSN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 263 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_pc_ssn(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_RandomVariable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceRedirectionCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SuspiciousAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TransactionCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 363 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_transactioncapability(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_AuthenticationRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationRequest_U_set, hf_index, ett_ansi_map_AuthenticationRequest_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationRequest_U);
return offset;
}
static int
dissect_ansi_map_AnalogRedirectInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AnalogRedirectRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AnalogRedirectRecord_sequence, hf_index, ett_ansi_map_AnalogRedirectRecord);
return offset;
}
static int
dissect_ansi_map_CDMABandClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAChannelNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAChannelNumberList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMAChannelNumberList_item_sequence, hf_index, ett_ansi_map_CDMAChannelNumberList_item);
return offset;
}
static int
dissect_ansi_map_CDMAChannelNumberList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMAChannelNumberList_sequence_of, hf_index, ett_ansi_map_CDMAChannelNumberList);
return offset;
}
static int
dissect_ansi_map_CDMARedirectRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMARedirectRecord_sequence, hf_index, ett_ansi_map_CDMARedirectRecord);
return offset;
}
static int
dissect_ansi_map_DataKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RoamingIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceRedirectionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_VoicePrivacyMask(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationRequestRes_U_set, hf_index, ett_ansi_map_AuthenticationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_ReauthenticationReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 443 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
ServiceIndicator = tvb_get_guint8(parameter_tvb,0);
if (SMS_BearerData_tvb !=NULL)
{
switch(ServiceIndicator){
case 1:
case 3:
dissector_try_uint(is683_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
break;
case 4:
dissector_try_uint(is801_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
break;
default:
break;
}
}
}
return offset;
}
static int
dissect_ansi_map_SignalingMessageEncryptionReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SSDUpdateReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_VoicePrivacyReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthenticationStatusReport_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationStatusReport_U_set, hf_index, ett_ansi_map_AuthenticationStatusReport_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationStatusReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationStatusReport_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationStatusReportRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AuthenticationStatusReportRes_U_set, hf_index, ett_ansi_map_AuthenticationStatusReportRes_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationStatusReportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AuthenticationStatusReportRes_U);
return offset;
}
static int
dissect_ansi_map_RandomVariableBaseStation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_BaseStationChallenge_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BaseStationChallenge_U_set, hf_index, ett_ansi_map_BaseStationChallenge_U);
return offset;
}
static int
dissect_ansi_map_BaseStationChallenge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_BaseStationChallenge_U);
return offset;
}
static int
dissect_ansi_map_AuthenticationResponseBaseStation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_BaseStationChallengeRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BaseStationChallengeRes_U_set, hf_index, ett_ansi_map_BaseStationChallengeRes_U);
return offset;
}
static int
dissect_ansi_map_BaseStationChallengeRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_BaseStationChallengeRes_U);
return offset;
}
static int
dissect_ansi_map_Blocking_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Blocking_U_set, hf_index, ett_ansi_map_Blocking_U);
return offset;
}
static int
dissect_ansi_map_Blocking(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_Blocking_U);
return offset;
}
static int
dissect_ansi_map_BulkDeregistration_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BulkDeregistration_U_set, hf_index, ett_ansi_map_BulkDeregistration_U);
return offset;
}
static int
dissect_ansi_map_BulkDeregistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_BulkDeregistration_U);
return offset;
}
static int
dissect_ansi_map_CountRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CountRequest_U_set, hf_index, ett_ansi_map_CountRequest_U);
return offset;
}
static int
dissect_ansi_map_CountRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CountRequest_U);
return offset;
}
static int
dissect_ansi_map_CountRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CountRequestRes_U_set, hf_index, ett_ansi_map_CountRequestRes_U);
return offset;
}
static int
dissect_ansi_map_CountRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CountRequestRes_U);
return offset;
}
static int
dissect_ansi_map_BillingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 90 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_billingid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_ChannelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 128 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_channeldata(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_InterSwitchCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServingCellID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_StationClassMark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TargetCellID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_HandoffReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_HandoffState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 174 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_handoffstate(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_TDMABurstIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMACallMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMAChannelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesDirective_U_set, hf_index, ett_ansi_map_FacilitiesDirective_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesDirective_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesDirectiveRes_U_set, hf_index, ett_ansi_map_FacilitiesDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_BaseStationManufacturerCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AlertCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 65 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_alertcode(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CDMA2000HandoffInvokeIOSData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 421 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
subtree = proto_item_add_subtree(actx->created_item, ett_CDMA2000HandoffInvokeIOSData);
dissect_cdma2000_a1_elements(parameter_tvb, actx->pinfo, subtree,
0, tvb_reported_length_remaining(parameter_tvb,0));
}
return offset;
}
static int
dissect_ansi_map_CDMAMobileProtocolRevision(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAStationClassMark2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMABandClassInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMABandClassInformation_sequence, hf_index, ett_ansi_map_CDMABandClassInformation);
return offset;
}
static int
dissect_ansi_map_CDMABandClassList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMABandClassList_sequence_of, hf_index, ett_ansi_map_CDMABandClassList);
return offset;
}
static int
dissect_ansi_map_CDMACallMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 105 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_cdmacallmode(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CDMAChannelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 112 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_cdmachanneldata(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CDMAConnectionReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAServiceOption(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 371 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_cdmaserviceoption(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CDMAState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DataPrivacyParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAServiceOptionConnectionIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAConnectionReferenceInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMAConnectionReferenceInformation_sequence, hf_index, ett_ansi_map_CDMAConnectionReferenceInformation);
return offset;
}
static int
dissect_ansi_map_CDMAConnectionReferenceList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMAConnectionReferenceList_item_sequence, hf_index, ett_ansi_map_CDMAConnectionReferenceList_item);
return offset;
}
static int
dissect_ansi_map_CDMAConnectionReferenceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMAConnectionReferenceList_sequence_of, hf_index, ett_ansi_map_CDMAConnectionReferenceList);
return offset;
}
static int
dissect_ansi_map_CDMAMSMeasuredChannelIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAServiceConfigurationRecord(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAServiceOptionList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMAServiceOptionList_sequence_of, hf_index, ett_ansi_map_CDMAServiceOptionList);
return offset;
}
static int
dissect_ansi_map_CDMAServingOneWayDelay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAStationClassMark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 120 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_cdmastationclassmark(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CDMAPilotStrength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMATargetOneWayDelay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMATargetMAHOInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMATargetMAHOInformation_sequence, hf_index, ett_ansi_map_CDMATargetMAHOInformation);
return offset;
}
static int
dissect_ansi_map_CDMATargetMAHOList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMATargetMAHOList_sequence_of, hf_index, ett_ansi_map_CDMATargetMAHOList);
return offset;
}
static int
dissect_ansi_map_CDMASignalQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMATargetMeasurementInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMATargetMeasurementInformation_sequence, hf_index, ett_ansi_map_CDMATargetMeasurementInformation);
return offset;
}
static int
dissect_ansi_map_CDMATargetMeasurementList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMATargetMeasurementList_sequence_of, hf_index, ett_ansi_map_CDMATargetMeasurementList);
return offset;
}
static int
dissect_ansi_map_ISLPInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MSLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 215 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_mslocation(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_NAMPSCallMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 223 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_nampscallmode(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_NAMPSChannelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 231 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_nampschanneldata(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_NonPublicData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PDSNAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PDSNProtocolType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_QoSPriority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SystemOperatorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMABandwidth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMAServiceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMATerminalCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMAVoiceCoder(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_UserZoneData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesDirective2_U_set, hf_index, ett_ansi_map_FacilitiesDirective2_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesDirective2_U);
return offset;
}
static int
dissect_ansi_map_BSMCStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMA2000HandoffResponseIOSData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 432 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
subtree = proto_item_add_subtree(actx->created_item, ett_CDMA2000HandoffResponseIOSData);
dissect_cdma2000_a1_elements(parameter_tvb, actx->pinfo, subtree,
0, tvb_reported_length_remaining(parameter_tvb,0));
}
return offset;
}
static int
dissect_ansi_map_CDMACodeChannel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAPilotPN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAPowerCombinedIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMACodeChannelInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CDMACodeChannelInformation_sequence, hf_index, ett_ansi_map_CDMACodeChannelInformation);
return offset;
}
static int
dissect_ansi_map_CDMACodeChannelList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CDMACodeChannelList_sequence_of, hf_index, ett_ansi_map_CDMACodeChannelList);
return offset;
}
static int
dissect_ansi_map_CDMASearchParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMASearchWindow(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SOCStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesDirective2Res_U_set, hf_index, ett_ansi_map_FacilitiesDirective2Res_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesDirective2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesDirective2Res_U);
return offset;
}
static int
dissect_ansi_map_ReleaseReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FacilitiesRelease_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesRelease_U_set, hf_index, ett_ansi_map_FacilitiesRelease_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesRelease(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesRelease_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesReleaseRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitiesReleaseRes_U_set, hf_index, ett_ansi_map_FacilitiesReleaseRes_U);
return offset;
}
static int
dissect_ansi_map_FacilitiesReleaseRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitiesReleaseRes_U);
return offset;
}
static int
dissect_ansi_map_ACGEncountered(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CallingPartyName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 382 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_callingpartyname(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CallingPartyNumberDigits1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_CallingPartyNumberDigits2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_Subaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 57 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_subaddress(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_CallingPartySubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_ConferenceCallingIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MobileDirectoryNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MSCIdentificationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_OneTimeFeatureIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 239 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_onetimefeatureindicator(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_SystemMyTypeCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FeatureRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FeatureRequest_U_set, hf_index, ett_ansi_map_FeatureRequest_U);
return offset;
}
static int
dissect_ansi_map_FeatureRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FeatureRequest_U);
return offset;
}
static int
dissect_ansi_map_FeatureResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AccessDeniedReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ActionCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AnnouncementCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 73 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_announcementcode(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_AnnouncementList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AnnouncementList_sequence, hf_index, ett_ansi_map_AnnouncementList);
return offset;
}
static int
dissect_ansi_map_CallingPartyNumberString1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_CallingPartyNumberString2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_DisplayText(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DisplayText2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DMH_AccountCodeDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_DMH_AlternateBillingDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_DMH_BillingDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_DMH_RedirectionIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_GroupInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_NoAnswerTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PACAIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 255 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_pacaindicator(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_PilotNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_PreferredLanguageIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RedirectingNumberDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_RedirectingNumberString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_RedirectingSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_ResumePIC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LegInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TerminationTriggers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 355 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_terminationtriggers(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_IntersystemTermination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IntersystemTermination_sequence, hf_index, ett_ansi_map_IntersystemTermination);
return offset;
}
static int
dissect_ansi_map_TerminationTreatment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_VoiceMailboxPIN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_VoiceMailboxNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_LocalTermination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LocalTermination_sequence, hf_index, ett_ansi_map_LocalTermination);
return offset;
}
static int
dissect_ansi_map_PSTNTermination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PSTNTermination_sequence, hf_index, ett_ansi_map_PSTNTermination);
return offset;
}
static int
dissect_ansi_map_TerminationList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TerminationList_item_choice, hf_index, ett_ansi_map_TerminationList_item,
NULL);
return offset;
}
static int
dissect_ansi_map_TerminationList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
TerminationList_set_of, hf_index, ett_ansi_map_TerminationList);
return offset;
}
static int
dissect_ansi_map_GlobalTitle(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DestinationAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DestinationAddress_choice, hf_index, ett_ansi_map_DestinationAddress,
NULL);
return offset;
}
static int
dissect_ansi_map_WIN_TriggerList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 405 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_win_trigger_list(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_TriggerList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TriggerList_set, hf_index, ett_ansi_map_TriggerList);
return offset;
}
static int
dissect_ansi_map_TriggerAddressList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TriggerAddressList_set, hf_index, ett_ansi_map_TriggerAddressList);
return offset;
}
static int
dissect_ansi_map_FeatureRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FeatureRequestRes_U_set, hf_index, ett_ansi_map_FeatureRequestRes_U);
return offset;
}
static int
dissect_ansi_map_FeatureRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FeatureRequestRes_U);
return offset;
}
static int
dissect_ansi_map_EmergencyServicesRoutingDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_FlashRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FlashRequest_U_set, hf_index, ett_ansi_map_FlashRequest_U);
return offset;
}
static int
dissect_ansi_map_FlashRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FlashRequest_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffBack_U_set, hf_index, ett_ansi_map_HandoffBack_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffBack_U);
return offset;
}
static int
dissect_ansi_map_HandoffBackRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffBackRes_U_set, hf_index, ett_ansi_map_HandoffBackRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffBackRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffBackRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffBack2_U_set, hf_index, ett_ansi_map_HandoffBack2_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffBack2_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffBack2Res_U_set, hf_index, ett_ansi_map_HandoffBack2Res_U);
return offset;
}
static int
dissect_ansi_map_HandoffBack2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffBack2Res_U);
return offset;
}
static int
dissect_ansi_map_TargetCellIDList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TargetCellIDList_sequence, hf_index, ett_ansi_map_TargetCellIDList);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffMeasurementRequest_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest_U);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffMeasurementRequest_U);
return offset;
}
static int
dissect_ansi_map_SignalQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffMeasurementRequestRes_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequestRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffMeasurementRequestRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffMeasurementRequest2_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest2_U);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffMeasurementRequest2_U);
return offset;
}
static int
dissect_ansi_map_TargetMeasurementInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TargetMeasurementInformation_sequence, hf_index, ett_ansi_map_TargetMeasurementInformation);
return offset;
}
static int
dissect_ansi_map_TargetMeasurementList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TargetMeasurementList_sequence_of, hf_index, ett_ansi_map_TargetMeasurementList);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffMeasurementRequest2Res_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest2Res_U);
return offset;
}
static int
dissect_ansi_map_HandoffMeasurementRequest2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffMeasurementRequest2Res_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffToThird_U_set, hf_index, ett_ansi_map_HandoffToThird_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffToThird_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThirdRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffToThirdRes_U_set, hf_index, ett_ansi_map_HandoffToThirdRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThirdRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffToThirdRes_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffToThird2_U_set, hf_index, ett_ansi_map_HandoffToThird2_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffToThird2_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
HandoffToThird2Res_U_set, hf_index, ett_ansi_map_HandoffToThird2Res_U);
return offset;
}
static int
dissect_ansi_map_HandoffToThird2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_HandoffToThird2Res_U);
return offset;
}
static int
dissect_ansi_map_InformationDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InformationDirective_U_set, hf_index, ett_ansi_map_InformationDirective_U);
return offset;
}
static int
dissect_ansi_map_InformationDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InformationDirective_U);
return offset;
}
static int
dissect_ansi_map_AlertResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InformationDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InformationDirectiveRes_U_set, hf_index, ett_ansi_map_InformationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_InformationDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InformationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_MessageWaitingNotificationCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 190 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_messagewaitingnotificationcount(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_MessageWaitingNotificationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 198 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_messagewaitingnotificationtype(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_InformationForward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InformationForward_U_set, hf_index, ett_ansi_map_InformationForward_U);
return offset;
}
static int
dissect_ansi_map_InformationForward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InformationForward_U);
return offset;
}
static int
dissect_ansi_map_InformationForwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InformationForwardRes_U_set, hf_index, ett_ansi_map_InformationForwardRes_U);
return offset;
}
static int
dissect_ansi_map_InformationForwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InformationForwardRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemAnswer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemAnswer_U_set, hf_index, ett_ansi_map_InterSystemAnswer_U);
return offset;
}
static int
dissect_ansi_map_InterSystemAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemAnswer_U);
return offset;
}
static int
dissect_ansi_map_CDMASlotCycleIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ExtendedMSCID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 159 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_extendedmscid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_ExtendedSystemMyTypeCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 167 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_extendedsystemmytypecode(parameter_tvb, actx->pinfo, tree, actx);
}
return offset;
}
static int
dissect_ansi_map_MSIDUsage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_NetworkTMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PageCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PageIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PageResponseTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PilotBillingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 271 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_pilotbillingid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_RedirectingPartyName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMADataFeaturesIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemPage_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPage_U_set, hf_index, ett_ansi_map_InterSystemPage_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPage_U);
return offset;
}
static int
dissect_ansi_map_ConditionallyDeniedReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemPageRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPageRes_U_set, hf_index, ett_ansi_map_InterSystemPageRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPageRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPageRes_U);
return offset;
}
static int
dissect_ansi_map_PagingFrameClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PSID_RSIDInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PSID_RSIDList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PSID_RSIDList_sequence, hf_index, ett_ansi_map_PSID_RSIDList);
return offset;
}
static int
dissect_ansi_map_InterSystemPage2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPage2_U_set, hf_index, ett_ansi_map_InterSystemPage2_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPage2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPage2_U);
return offset;
}
static int
dissect_ansi_map_RANDC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMADataMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemPage2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPage2Res_U_set, hf_index, ett_ansi_map_InterSystemPage2Res_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPage2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPage2Res_U);
return offset;
}
static int
dissect_ansi_map_ChangeServiceAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemSetup_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemSetup_U_set, hf_index, ett_ansi_map_InterSystemSetup_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSetup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemSetup_U);
return offset;
}
static int
dissect_ansi_map_SetupResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemSetupRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemSetupRes_U_set, hf_index, ett_ansi_map_InterSystemSetupRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSetupRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemSetupRes_U);
return offset;
}
static int
dissect_ansi_map_TerminationAccessType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TriggerType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TriggerCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 390 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_triggercapability(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_WINOperationsCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 398 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_winoperationscapability(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_WINCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
WINCapability_set, hf_index, ett_ansi_map_WINCapability);
return offset;
}
static int
dissect_ansi_map_CallingPartyCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LocationRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
LocationRequest_U_set, hf_index, ett_ansi_map_LocationRequest_U);
return offset;
}
static int
dissect_ansi_map_LocationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_LocationRequest_U);
return offset;
}
static int
dissect_ansi_map_ControlNetworkID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 413 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_controlnetworkid(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_DMH_ServiceID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LocationRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
LocationRequestRes_U_set, hf_index, ett_ansi_map_LocationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_LocationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_LocationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_DeregistrationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServicesResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMS_MessageWaitingIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ansi_map_MSInactive_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MSInactive_U_set, hf_index, ett_ansi_map_MSInactive_U);
return offset;
}
static int
dissect_ansi_map_MSInactive(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_MSInactive_U);
return offset;
}
static int
dissect_ansi_map_OriginationTriggers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 247 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_originationtriggers(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_FeatureIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_OriginationRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OriginationRequest_U_set, hf_index, ett_ansi_map_OriginationRequest_U);
return offset;
}
static int
dissect_ansi_map_OriginationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OriginationRequest_U);
return offset;
}
static int
dissect_ansi_map_DMH_ChargeInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_OriginationRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OriginationRequestRes_U_set, hf_index, ett_ansi_map_OriginationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_OriginationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OriginationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_QualificationInformationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthorizationDenied(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AuthorizationPeriod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 81 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_authorizationperiod(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_DeniedAuthorizationPeriod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 151 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_deniedauthorizationperiod(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_AuthenticationCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CallingFeaturesIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_callingfeaturesindicator(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_GeographicAuthorization(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MEIDValidated(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ansi_map_MobilePositionCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_OriginationIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RestrictionDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginationRestrictions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 314 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_sms_originationrestrictions(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_SMS_TerminationRestrictions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SPINIPIN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SPINITriggers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TerminationRestrictionCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_UserGroup(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LIRMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_QualificationDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationDirective_U_set, hf_index, ett_ansi_map_QualificationDirective_U);
return offset;
}
static int
dissect_ansi_map_QualificationDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationDirective_U);
return offset;
}
static int
dissect_ansi_map_QualificationDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationDirectiveRes_U_set, hf_index, ett_ansi_map_QualificationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_QualificationDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationRequest_U_set, hf_index, ett_ansi_map_QualificationRequest_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationRequest_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationRequestRes_U_set, hf_index, ett_ansi_map_QualificationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_RandomVariableRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RandomVariableRequest_U_set, hf_index, ett_ansi_map_RandomVariableRequest_U);
return offset;
}
static int
dissect_ansi_map_RandomVariableRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RandomVariableRequest_U);
return offset;
}
static int
dissect_ansi_map_RANDValidTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RandomVariableRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RandomVariableRequestRes_U_set, hf_index, ett_ansi_map_RandomVariableRequestRes_U);
return offset;
}
static int
dissect_ansi_map_RandomVariableRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RandomVariableRequestRes_U);
return offset;
}
static int
dissect_ansi_map_RedirectionDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RedirectionDirective_U_set, hf_index, ett_ansi_map_RedirectionDirective_U);
return offset;
}
static int
dissect_ansi_map_RedirectionDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RedirectionDirective_U);
return offset;
}
static int
dissect_ansi_map_RedirectionReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RedirectionRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RedirectionRequest_U_set, hf_index, ett_ansi_map_RedirectionRequest_U);
return offset;
}
static int
dissect_ansi_map_RedirectionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RedirectionRequest_U);
return offset;
}
static int
dissect_ansi_map_CancellationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ControlChannelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 143 "./asn1/ansi_map/ansi_map.cnf"
tvbuff_t *parameter_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
dissect_ansi_map_controlchanneldata(parameter_tvb,actx->pinfo,tree, actx);
}
return offset;
}
static int
dissect_ansi_map_ReceivedSignalQuality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SystemAccessData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RegistrationCancellation_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RegistrationCancellation_U_set, hf_index, ett_ansi_map_RegistrationCancellation_U);
return offset;
}
static int
dissect_ansi_map_RegistrationCancellation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RegistrationCancellation_U);
return offset;
}
static int
dissect_ansi_map_CancellationDenied(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RegistrationCancellationRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RegistrationCancellationRes_U_set, hf_index, ett_ansi_map_RegistrationCancellationRes_U);
return offset;
}
static int
dissect_ansi_map_RegistrationCancellationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RegistrationCancellationRes_U);
return offset;
}
static int
dissect_ansi_map_AvailabilityType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_BorderCellAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MSC_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MPCAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MPCAddressList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MPCAddressList_set, hf_index, ett_ansi_map_MPCAddressList);
return offset;
}
static int
dissect_ansi_map_RegistrationNotification_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RegistrationNotification_U_set, hf_index, ett_ansi_map_RegistrationNotification_U);
return offset;
}
static int
dissect_ansi_map_RegistrationNotification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RegistrationNotification_U);
return offset;
}
static int
dissect_ansi_map_RegistrationNotificationRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RegistrationNotificationRes_U_set, hf_index, ett_ansi_map_RegistrationNotificationRes_U);
return offset;
}
static int
dissect_ansi_map_RegistrationNotificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RegistrationNotificationRes_U);
return offset;
}
static int
dissect_ansi_map_DigitCollectionControl(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RemoteUserInteractionDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RemoteUserInteractionDirective_U_set, hf_index, ett_ansi_map_RemoteUserInteractionDirective_U);
return offset;
}
static int
dissect_ansi_map_RemoteUserInteractionDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RemoteUserInteractionDirective_U);
return offset;
}
static int
dissect_ansi_map_RemoteUserInteractionDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RemoteUserInteractionDirectiveRes_U_set, hf_index, ett_ansi_map_RemoteUserInteractionDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_RemoteUserInteractionDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RemoteUserInteractionDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_ResetCircuit_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ResetCircuit_U_set, hf_index, ett_ansi_map_ResetCircuit_U);
return offset;
}
static int
dissect_ansi_map_ResetCircuit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ResetCircuit_U);
return offset;
}
static int
dissect_ansi_map_TrunkStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ResetCircuitRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ResetCircuitRes_U_set, hf_index, ett_ansi_map_ResetCircuitRes_U);
return offset;
}
static int
dissect_ansi_map_ResetCircuitRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ResetCircuitRes_U);
return offset;
}
static int
dissect_ansi_map_RoutingRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RoutingRequest_U_set, hf_index, ett_ansi_map_RoutingRequest_U);
return offset;
}
static int
dissect_ansi_map_RoutingRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RoutingRequest_U);
return offset;
}
static int
dissect_ansi_map_RoutingRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RoutingRequestRes_U_set, hf_index, ett_ansi_map_RoutingRequestRes_U);
return offset;
}
static int
dissect_ansi_map_RoutingRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RoutingRequestRes_U);
return offset;
}
static int
dissect_ansi_map_SMS_BearerData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 280 "./asn1/ansi_map/ansi_map.cnf"
int length;
SMS_BearerData_tvb = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&SMS_BearerData_tvb);
if (SMS_BearerData_tvb){
length = tvb_reported_length_remaining(SMS_BearerData_tvb,0);
if (length <=0){
proto_item_append_text(actx->created_item," length %u",length);
SMS_BearerData_tvb = NULL;
return offset;
}
if (ansi_map_sms_tele_id != -1)
{
dissector_try_uint(is637_tele_id_dissector_table, ansi_map_sms_tele_id, SMS_BearerData_tvb, g_pinfo, g_tree);
}
else
{
switch(ServiceIndicator){
case 1:
case 3:
dissector_try_uint(is683_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
break;
case 4:
dissector_try_uint(is801_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
break;
default:
break;
}
}
}
return offset;
}
static int
dissect_ansi_map_SMS_TeleserviceIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 323 "./asn1/ansi_map/ansi_map.cnf"
int length;
tvbuff_t *parameter_tvb = NULL;
ansi_map_sms_tele_id = -1;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb){
length = tvb_reported_length_remaining(parameter_tvb,0);
if (length <=0){
proto_item_append_text(actx->created_item, " length %u",length);
return offset;
}
ansi_map_sms_tele_id = tvb_get_ntohs(tvb,0);
if ((ansi_map_sms_tele_id != -1)&&(SMS_BearerData_tvb !=NULL))
{
dissector_try_uint(is637_tele_id_dissector_table, ansi_map_sms_tele_id, SMS_BearerData_tvb, g_pinfo, g_tree);
}
}
return offset;
}
static int
dissect_ansi_map_SMS_ChargeIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMS_DestinationAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginalDestinationAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginalDestinationSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginalOriginatingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginalOriginatingSubaddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_OriginatingAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryBackward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryBackward_U_set, hf_index, ett_ansi_map_SMSDeliveryBackward_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryBackward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryBackward_U);
return offset;
}
static int
dissect_ansi_map_SMS_CauseCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryBackwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryBackwardRes_U_set, hf_index, ett_ansi_map_SMSDeliveryBackwardRes_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryBackwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryBackwardRes_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryForward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryForward_U_set, hf_index, ett_ansi_map_SMSDeliveryForward_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryForward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryForward_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryForwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryForwardRes_U_set, hf_index, ett_ansi_map_SMSDeliveryForwardRes_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryForwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryForwardRes_U);
return offset;
}
static int
dissect_ansi_map_CDMAServingOneWayDelay2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterMessageTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_IMSIType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_NewlyAssignedIMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_IMSIType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_NewlyAssignedMIN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_NewMINExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMS_MessageCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMS_NotificationIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Teleservice_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TemporaryReferenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPoint_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryPointToPoint_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPoint_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryPointToPoint_U);
return offset;
}
static int
dissect_ansi_map_MobileStationIMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_IMSIType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_MobileStationMSID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
MobileStationMSID_choice, hf_index, ett_ansi_map_MobileStationMSID,
NULL);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPointRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryPointToPointRes_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPointRes_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPointRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryPointToPointRes_U);
return offset;
}
static int
dissect_ansi_map_SMS_TransactionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPointAck_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSDeliveryPointToPointAck_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPointAck_U);
return offset;
}
static int
dissect_ansi_map_SMSDeliveryPointToPointAck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSDeliveryPointToPointAck_U);
return offset;
}
static int
dissect_ansi_map_SMS_AccessDeniedReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SMSNotification_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSNotification_U_set, hf_index, ett_ansi_map_SMSNotification_U);
return offset;
}
static int
dissect_ansi_map_SMSNotification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSNotification_U);
return offset;
}
static int
dissect_ansi_map_SMSNotificationRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSNotificationRes_U_set, hf_index, ett_ansi_map_SMSNotificationRes_U);
return offset;
}
static int
dissect_ansi_map_SMSNotificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSNotificationRes_U);
return offset;
}
static int
dissect_ansi_map_SMSRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSRequest_U_set, hf_index, ett_ansi_map_SMSRequest_U);
return offset;
}
static int
dissect_ansi_map_SMSRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSRequest_U);
return offset;
}
static int
dissect_ansi_map_SMSRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SMSRequestRes_U_set, hf_index, ett_ansi_map_SMSRequestRes_U);
return offset;
}
static int
dissect_ansi_map_SMSRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SMSRequestRes_U);
return offset;
}
static int
dissect_ansi_map_TransferToNumberRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TransferToNumberRequest_U_set, hf_index, ett_ansi_map_TransferToNumberRequest_U);
return offset;
}
static int
dissect_ansi_map_TransferToNumberRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TransferToNumberRequest_U);
return offset;
}
static int
dissect_ansi_map_TransferToNumberRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TransferToNumberRequestRes_U_set, hf_index, ett_ansi_map_TransferToNumberRequestRes_U);
return offset;
}
static int
dissect_ansi_map_TransferToNumberRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TransferToNumberRequestRes_U);
return offset;
}
static int
dissect_ansi_map_SeizureType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TrunkTest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TrunkTest_U_set, hf_index, ett_ansi_map_TrunkTest_U);
return offset;
}
static int
dissect_ansi_map_TrunkTest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TrunkTest_U);
return offset;
}
static int
dissect_ansi_map_TrunkTestDisconnect_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TrunkTestDisconnect_U_set, hf_index, ett_ansi_map_TrunkTestDisconnect_U);
return offset;
}
static int
dissect_ansi_map_TrunkTestDisconnect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TrunkTestDisconnect_U);
return offset;
}
static int
dissect_ansi_map_Unblocking_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Unblocking_U_set, hf_index, ett_ansi_map_Unblocking_U);
return offset;
}
static int
dissect_ansi_map_Unblocking(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_Unblocking_U);
return offset;
}
static int
dissect_ansi_map_UnreliableRoamerDataDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UnreliableRoamerDataDirective_U_set, hf_index, ett_ansi_map_UnreliableRoamerDataDirective_U);
return offset;
}
static int
dissect_ansi_map_UnreliableRoamerDataDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_UnreliableRoamerDataDirective_U);
return offset;
}
static int
dissect_ansi_map_UnsolicitedResponse_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UnsolicitedResponse_U_set, hf_index, ett_ansi_map_UnsolicitedResponse_U);
return offset;
}
static int
dissect_ansi_map_UnsolicitedResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_UnsolicitedResponse_U);
return offset;
}
static int
dissect_ansi_map_UnsolicitedResponseRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UnsolicitedResponseRes_U_set, hf_index, ett_ansi_map_UnsolicitedResponseRes_U);
return offset;
}
static int
dissect_ansi_map_UnsolicitedResponseRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_UnsolicitedResponseRes_U);
return offset;
}
static int
dissect_ansi_map_RequiredParametersMask(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ParameterRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ParameterRequest_U_set, hf_index, ett_ansi_map_ParameterRequest_U);
return offset;
}
static int
dissect_ansi_map_ParameterRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ParameterRequest_U);
return offset;
}
static int
dissect_ansi_map_ReasonList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ParameterRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ParameterRequestRes_U_set, hf_index, ett_ansi_map_ParameterRequestRes_U);
return offset;
}
static int
dissect_ansi_map_ParameterRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ParameterRequestRes_U);
return offset;
}
static int
dissect_ansi_map_NetworkTMSIExpirationTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_NewNetworkTMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_TMSIDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TMSIDirective_U_set, hf_index, ett_ansi_map_TMSIDirective_U);
return offset;
}
static int
dissect_ansi_map_TMSIDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TMSIDirective_U);
return offset;
}
static int
dissect_ansi_map_TMSIDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TMSIDirectiveRes_U_set, hf_index, ett_ansi_map_TMSIDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_TMSIDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TMSIDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_NumberPortabilityRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
NumberPortabilityRequest_U_set, hf_index, ett_ansi_map_NumberPortabilityRequest_U);
return offset;
}
static int
dissect_ansi_map_NumberPortabilityRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_NumberPortabilityRequest_U);
return offset;
}
static int
dissect_ansi_map_NumberPortabilityRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
NumberPortabilityRequestRes_U_set, hf_index, ett_ansi_map_NumberPortabilityRequestRes_U);
return offset;
}
static int
dissect_ansi_map_NumberPortabilityRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_NumberPortabilityRequestRes_U);
return offset;
}
static int
dissect_ansi_map_ServiceID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DataID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Change(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DataValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DataAccessElement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DataAccessElement_sequence, hf_index, ett_ansi_map_DataAccessElement);
return offset;
}
static int
dissect_ansi_map_DataAccessElementList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DataAccessElementList_item_sequence, hf_index, ett_ansi_map_DataAccessElementList_item);
return offset;
}
static int
dissect_ansi_map_DataAccessElementList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DataAccessElementList_sequence_of, hf_index, ett_ansi_map_DataAccessElementList);
return offset;
}
static int
dissect_ansi_map_TimeDateOffset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TimeOfDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ServiceRequest_U_set, hf_index, ett_ansi_map_ServiceRequest_U);
return offset;
}
static int
dissect_ansi_map_ServiceRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ServiceRequest_U);
return offset;
}
static int
dissect_ansi_map_ServiceRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ServiceRequestRes_U_set, hf_index, ett_ansi_map_ServiceRequestRes_U);
return offset;
}
static int
dissect_ansi_map_ServiceRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ServiceRequestRes_U);
return offset;
}
static int
dissect_ansi_map_DMH_BillingIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_AnalyzedInformation_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AnalyzedInformation_U_set, hf_index, ett_ansi_map_AnalyzedInformation_U);
return offset;
}
static int
dissect_ansi_map_AnalyzedInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AnalyzedInformation_U);
return offset;
}
static int
dissect_ansi_map_AnalyzedInformationRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AnalyzedInformationRes_U_set, hf_index, ett_ansi_map_AnalyzedInformationRes_U);
return offset;
}
static int
dissect_ansi_map_AnalyzedInformationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AnalyzedInformationRes_U);
return offset;
}
static int
dissect_ansi_map_FailureType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_FailureCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ConnectionFailureReport_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ConnectionFailureReport_U_set, hf_index, ett_ansi_map_ConnectionFailureReport_U);
return offset;
}
static int
dissect_ansi_map_ConnectionFailureReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ConnectionFailureReport_U);
return offset;
}
static int
dissect_ansi_map_ConnectResource_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ConnectResource_U_set, hf_index, ett_ansi_map_ConnectResource_U);
return offset;
}
static int
dissect_ansi_map_ConnectResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ConnectResource_U);
return offset;
}
static int
dissect_ansi_map_FacilitySelectedAndAvailable_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitySelectedAndAvailable_U_set, hf_index, ett_ansi_map_FacilitySelectedAndAvailable_U);
return offset;
}
static int
dissect_ansi_map_FacilitySelectedAndAvailable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitySelectedAndAvailable_U);
return offset;
}
static int
dissect_ansi_map_FacilitySelectedAndAvailableRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
FacilitySelectedAndAvailableRes_U_set, hf_index, ett_ansi_map_FacilitySelectedAndAvailableRes_U);
return offset;
}
static int
dissect_ansi_map_FacilitySelectedAndAvailableRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_FacilitySelectedAndAvailableRes_U);
return offset;
}
static int
dissect_ansi_map_DatabaseKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceDataAccessElement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceDataAccessElement_sequence, hf_index, ett_ansi_map_ServiceDataAccessElement);
return offset;
}
static int
dissect_ansi_map_ServiceDataAccessElementList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ServiceDataAccessElementList_sequence_of, hf_index, ett_ansi_map_ServiceDataAccessElementList);
return offset;
}
static int
dissect_ansi_map_AllOrNone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ModificationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ModificationRequest_sequence, hf_index, ett_ansi_map_ModificationRequest);
return offset;
}
static int
dissect_ansi_map_ModificationRequestList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ModificationRequestList_sequence_of, hf_index, ett_ansi_map_ModificationRequestList);
return offset;
}
static int
dissect_ansi_map_Modify_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Modify_U_set, hf_index, ett_ansi_map_Modify_U);
return offset;
}
static int
dissect_ansi_map_Modify(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_Modify_U);
return offset;
}
static int
dissect_ansi_map_DataResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_DataUpdateResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DataUpdateResult_sequence, hf_index, ett_ansi_map_DataUpdateResult);
return offset;
}
static int
dissect_ansi_map_DataUpdateResultList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
DataUpdateResultList_sequence_of, hf_index, ett_ansi_map_DataUpdateResultList);
return offset;
}
static int
dissect_ansi_map_ServiceDataResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceDataResult_sequence, hf_index, ett_ansi_map_ServiceDataResult);
return offset;
}
static int
dissect_ansi_map_ServiceDataResultList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ServiceDataResultList_sequence_of, hf_index, ett_ansi_map_ServiceDataResultList);
return offset;
}
static int
dissect_ansi_map_ModificationResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ModificationResult_choice, hf_index, ett_ansi_map_ModificationResult,
NULL);
return offset;
}
static int
dissect_ansi_map_ModificationResultList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ModificationResultList_sequence_of, hf_index, ett_ansi_map_ModificationResultList);
return offset;
}
static int
dissect_ansi_map_ModifyRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ModifyRes_U_set, hf_index, ett_ansi_map_ModifyRes_U);
return offset;
}
static int
dissect_ansi_map_ModifyRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ModifyRes_U);
return offset;
}
static int
dissect_ansi_map_Search_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Search_U_set, hf_index, ett_ansi_map_Search_U);
return offset;
}
static int
dissect_ansi_map_Search(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_Search_U);
return offset;
}
static int
dissect_ansi_map_SearchRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SearchRes_U_set, hf_index, ett_ansi_map_SearchRes_U);
return offset;
}
static int
dissect_ansi_map_SearchRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SearchRes_U);
return offset;
}
static int
dissect_ansi_map_PrivateSpecializedResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SpecializedResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SeizeResource_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SeizeResource_U_set, hf_index, ett_ansi_map_SeizeResource_U);
return offset;
}
static int
dissect_ansi_map_SeizeResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SeizeResource_U);
return offset;
}
static int
dissect_ansi_map_SeizeResourceRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SeizeResourceRes_U_set, hf_index, ett_ansi_map_SeizeResourceRes_U);
return offset;
}
static int
dissect_ansi_map_SeizeResourceRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SeizeResourceRes_U);
return offset;
}
static int
dissect_ansi_map_ScriptName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ScriptArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ExecuteScript(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExecuteScript_sequence, hf_index, ett_ansi_map_ExecuteScript);
return offset;
}
static int
dissect_ansi_map_SRFDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SRFDirective_U_set, hf_index, ett_ansi_map_SRFDirective_U);
return offset;
}
static int
dissect_ansi_map_SRFDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SRFDirective_U);
return offset;
}
static int
dissect_ansi_map_ScriptResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SRFDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SRFDirectiveRes_U_set, hf_index, ett_ansi_map_SRFDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_SRFDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_SRFDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_TBusy_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TBusy_U_set, hf_index, ett_ansi_map_TBusy_U);
return offset;
}
static int
dissect_ansi_map_TBusy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TBusy_U);
return offset;
}
static int
dissect_ansi_map_TBusyRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TBusyRes_U_set, hf_index, ett_ansi_map_TBusyRes_U);
return offset;
}
static int
dissect_ansi_map_TBusyRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TBusyRes_U);
return offset;
}
static int
dissect_ansi_map_TNoAnswer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TNoAnswer_U_set, hf_index, ett_ansi_map_TNoAnswer_U);
return offset;
}
static int
dissect_ansi_map_TNoAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TNoAnswer_U);
return offset;
}
static int
dissect_ansi_map_TNoAnswerRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TNoAnswerRes_U_set, hf_index, ett_ansi_map_TNoAnswerRes_U);
return offset;
}
static int
dissect_ansi_map_TNoAnswerRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TNoAnswerRes_U);
return offset;
}
static int
dissect_ansi_map_ChangeFacilities_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChangeFacilities_U_set, hf_index, ett_ansi_map_ChangeFacilities_U);
return offset;
}
static int
dissect_ansi_map_ChangeFacilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ChangeFacilities_U);
return offset;
}
static int
dissect_ansi_map_ChangeFacilitiesRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChangeFacilitiesRes_U_set, hf_index, ett_ansi_map_ChangeFacilitiesRes_U);
return offset;
}
static int
dissect_ansi_map_ChangeFacilitiesRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ChangeFacilitiesRes_U);
return offset;
}
static int
dissect_ansi_map_TDMAVoiceMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ChangeService_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChangeService_U_set, hf_index, ett_ansi_map_ChangeService_U);
return offset;
}
static int
dissect_ansi_map_ChangeService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ChangeService_U);
return offset;
}
static int
dissect_ansi_map_ChangeServiceRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ChangeServiceRes_U_set, hf_index, ett_ansi_map_ChangeServiceRes_U);
return offset;
}
static int
dissect_ansi_map_ChangeServiceRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ChangeServiceRes_U);
return offset;
}
static int
dissect_ansi_map_MessageDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageDirective_U_set, hf_index, ett_ansi_map_MessageDirective_U);
return offset;
}
static int
dissect_ansi_map_MessageDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_MessageDirective_U);
return offset;
}
static int
dissect_ansi_map_BulkDisconnection_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BulkDisconnection_U_set, hf_index, ett_ansi_map_BulkDisconnection_U);
return offset;
}
static int
dissect_ansi_map_BulkDisconnection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_BulkDisconnection_U);
return offset;
}
static int
dissect_ansi_map_CallControlDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CallControlDirective_U_set, hf_index, ett_ansi_map_CallControlDirective_U);
return offset;
}
static int
dissect_ansi_map_CallControlDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CallControlDirective_U);
return offset;
}
static int
dissect_ansi_map_CallStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CallControlDirectiveRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CallControlDirectiveRes_U_set, hf_index, ett_ansi_map_CallControlDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_CallControlDirectiveRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CallControlDirectiveRes_U);
return offset;
}
static int
dissect_ansi_map_OAnswer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OAnswer_U_set, hf_index, ett_ansi_map_OAnswer_U);
return offset;
}
static int
dissect_ansi_map_OAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OAnswer_U);
return offset;
}
static int
dissect_ansi_map_ReleaseCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ODisconnect_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ODisconnect_U_set, hf_index, ett_ansi_map_ODisconnect_U);
return offset;
}
static int
dissect_ansi_map_ODisconnect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ODisconnect_U);
return offset;
}
static int
dissect_ansi_map_ODisconnectRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ODisconnectRes_U_set, hf_index, ett_ansi_map_ODisconnectRes_U);
return offset;
}
static int
dissect_ansi_map_ODisconnectRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ODisconnectRes_U);
return offset;
}
static int
dissect_ansi_map_CallRecoveryID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CallRecoveryID_set, hf_index, ett_ansi_map_CallRecoveryID);
return offset;
}
static int
dissect_ansi_map_CallRecoveryIDList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
CallRecoveryIDList_set_of, hf_index, ett_ansi_map_CallRecoveryIDList);
return offset;
}
static int
dissect_ansi_map_CallRecoveryReport_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CallRecoveryReport_U_set, hf_index, ett_ansi_map_CallRecoveryReport_U);
return offset;
}
static int
dissect_ansi_map_CallRecoveryReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CallRecoveryReport_U);
return offset;
}
static int
dissect_ansi_map_TAnswer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TAnswer_U_set, hf_index, ett_ansi_map_TAnswer_U);
return offset;
}
static int
dissect_ansi_map_TAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TAnswer_U);
return offset;
}
static int
dissect_ansi_map_TDisconnect_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TDisconnect_U_set, hf_index, ett_ansi_map_TDisconnect_U);
return offset;
}
static int
dissect_ansi_map_TDisconnect(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TDisconnect_U);
return offset;
}
static int
dissect_ansi_map_TDisconnectRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TDisconnectRes_U_set, hf_index, ett_ansi_map_TDisconnectRes_U);
return offset;
}
static int
dissect_ansi_map_TDisconnectRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_TDisconnectRes_U);
return offset;
}
static int
dissect_ansi_map_UnreliableCallData_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
UnreliableCallData_U_set, hf_index, ett_ansi_map_UnreliableCallData_U);
return offset;
}
static int
dissect_ansi_map_UnreliableCallData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_UnreliableCallData_U);
return offset;
}
static int
dissect_ansi_map_OCalledPartyBusy_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OCalledPartyBusy_U_set, hf_index, ett_ansi_map_OCalledPartyBusy_U);
return offset;
}
static int
dissect_ansi_map_OCalledPartyBusy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OCalledPartyBusy_U);
return offset;
}
static int
dissect_ansi_map_OCalledPartyBusyRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OCalledPartyBusyRes_U_set, hf_index, ett_ansi_map_OCalledPartyBusyRes_U);
return offset;
}
static int
dissect_ansi_map_OCalledPartyBusyRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OCalledPartyBusyRes_U);
return offset;
}
static int
dissect_ansi_map_ONoAnswer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ONoAnswer_U_set, hf_index, ett_ansi_map_ONoAnswer_U);
return offset;
}
static int
dissect_ansi_map_ONoAnswer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ONoAnswer_U);
return offset;
}
static int
dissect_ansi_map_ONoAnswerRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ONoAnswerRes_U_set, hf_index, ett_ansi_map_ONoAnswerRes_U);
return offset;
}
static int
dissect_ansi_map_ONoAnswerRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ONoAnswerRes_U);
return offset;
}
static int
dissect_ansi_map_PositionInformationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PositionRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionRequest_U_set, hf_index, ett_ansi_map_PositionRequest_U);
return offset;
}
static int
dissect_ansi_map_PositionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_PositionRequest_U);
return offset;
}
static int
dissect_ansi_map_MSStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PositionRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionRequestRes_U_set, hf_index, ett_ansi_map_PositionRequestRes_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_PositionRequestRes_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestForward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionRequestForward_U_set, hf_index, ett_ansi_map_PositionRequestForward_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestForward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_PositionRequestForward_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestForwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionRequestForwardRes_U_set, hf_index, ett_ansi_map_PositionRequestForwardRes_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestForwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_PositionRequestForwardRes_U);
return offset;
}
static int
dissect_ansi_map_CallTerminationReport_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CallTerminationReport_U_set, hf_index, ett_ansi_map_CallTerminationReport_U);
return offset;
}
static int
dissect_ansi_map_CallTerminationReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CallTerminationReport_U);
return offset;
}
static int
dissect_ansi_map_PositionRequestType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LCSBillingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LCS_Client_ID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_DTXIndication(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAMobileCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CDMAPSMMList_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CDMAPSMMList_item_set, hf_index, ett_ansi_map_CDMAPSMMList_item);
return offset;
}
static int
dissect_ansi_map_CDMAPSMMList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
CDMAPSMMList_set_of, hf_index, ett_ansi_map_CDMAPSMMList);
return offset;
}
static int
dissect_ansi_map_TDMA_MAHO_CELLID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMA_MAHO_CHANNEL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_TDMA_TimeAlignment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_HorizontalPosition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_HorizontalVelocity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_MaximumPositionAge(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_PositionPriority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_ResponseTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_VerticalPosition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PQOS_VerticalVelocity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_GeoPositionRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
GeoPositionRequest_U_set, hf_index, ett_ansi_map_GeoPositionRequest_U);
return offset;
}
static int
dissect_ansi_map_GeoPositionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_GeoPositionRequest_U);
return offset;
}
static int
dissect_ansi_map_CDMAPSMMCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_LIRAuthorization(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MPCID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_map_TDMA_MAHORequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPositionRequest_U_set, hf_index, ett_ansi_map_InterSystemPositionRequest_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPositionRequest_U);
return offset;
}
static int
dissect_ansi_map_PositionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_ansi_map_GeographicPosition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PositionSource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Horizontal_Velocity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Vertical_Velocity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PositionInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionInformation_set, hf_index, ett_ansi_map_PositionInformation);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPositionRequestRes_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPositionRequestRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestForward_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPositionRequestForward_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestForward_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestForward(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPositionRequestForward_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestForwardRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemPositionRequestForwardRes_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestForwardRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemPositionRequestForwardRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemPositionRequestForwardRes_U);
return offset;
}
static int
dissect_ansi_map_ControlType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_GapDuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_SCFOverloadGapInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ServiceManagementSystemGapInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_GapInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GapInterval_choice, hf_index, ett_ansi_map_GapInterval,
NULL);
return offset;
}
static int
dissect_ansi_map_ACGDirective_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ACGDirective_U_set, hf_index, ett_ansi_map_ACGDirective_U);
return offset;
}
static int
dissect_ansi_map_ACGDirective(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_ACGDirective_U);
return offset;
}
static int
dissect_ansi_map_InvokingNEType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_Range(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_RoamerDatabaseVerificationRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RoamerDatabaseVerificationRequest_U_set, hf_index, ett_ansi_map_RoamerDatabaseVerificationRequest_U);
return offset;
}
static int
dissect_ansi_map_RoamerDatabaseVerificationRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RoamerDatabaseVerificationRequest_U);
return offset;
}
static int
dissect_ansi_map_RoamerDatabaseVerificationRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RoamerDatabaseVerificationRequestRes_U_set, hf_index, ett_ansi_map_RoamerDatabaseVerificationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_RoamerDatabaseVerificationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_RoamerDatabaseVerificationRequestRes_U);
return offset;
}
static int
dissect_ansi_map_LCSParameterRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
LCSParameterRequest_U_set, hf_index, ett_ansi_map_LCSParameterRequest_U);
return offset;
}
static int
dissect_ansi_map_LCSParameterRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_LCSParameterRequest_U);
return offset;
}
static int
dissect_ansi_map_LCSParameterRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
LCSParameterRequestRes_U_set, hf_index, ett_ansi_map_LCSParameterRequestRes_U);
return offset;
}
static int
dissect_ansi_map_LCSParameterRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_LCSParameterRequestRes_U);
return offset;
}
static int
dissect_ansi_map_CheckMEID_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CheckMEID_U_set, hf_index, ett_ansi_map_CheckMEID_U);
return offset;
}
static int
dissect_ansi_map_CheckMEID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CheckMEID_U);
return offset;
}
static int
dissect_ansi_map_MEIDStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_CheckMEIDRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CheckMEIDRes_U_set, hf_index, ett_ansi_map_CheckMEIDRes_U);
return offset;
}
static int
dissect_ansi_map_CheckMEIDRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_CheckMEIDRes_U);
return offset;
}
static int
dissect_ansi_map_AddService_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AddService_U_set, hf_index, ett_ansi_map_AddService_U);
return offset;
}
static int
dissect_ansi_map_AddService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AddService_U);
return offset;
}
static int
dissect_ansi_map_AddServiceRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
AddServiceRes_U_set, hf_index, ett_ansi_map_AddServiceRes_U);
return offset;
}
static int
dissect_ansi_map_AddServiceRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_AddServiceRes_U);
return offset;
}
static int
dissect_ansi_map_DropService_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DropService_U_set, hf_index, ett_ansi_map_DropService_U);
return offset;
}
static int
dissect_ansi_map_DropService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_DropService_U);
return offset;
}
static int
dissect_ansi_map_DropServiceRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
DropServiceRes_U_set, hf_index, ett_ansi_map_DropServiceRes_U);
return offset;
}
static int
dissect_ansi_map_DropServiceRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_DropServiceRes_U);
return offset;
}
static int
dissect_ansi_map_PositionEventNotification_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
PositionEventNotification_U_set, hf_index, ett_ansi_map_PositionEventNotification_U);
return offset;
}
static int
dissect_ansi_map_PositionEventNotification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_PositionEventNotification_U);
return offset;
}
static int
dissect_ansi_map_AKeyProtocolVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_MobileStationPartialKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_NewlyAssignedMSID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NewlyAssignedMSID_choice, hf_index, ett_ansi_map_NewlyAssignedMSID,
NULL);
return offset;
}
static int
dissect_ansi_map_OTASPRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OTASPRequest_U_set, hf_index, ett_ansi_map_OTASPRequest_U);
return offset;
}
static int
dissect_ansi_map_OTASPRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OTASPRequest_U);
return offset;
}
static int
dissect_ansi_map_BaseStationPartialKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_ModulusValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_OTASP_ResultCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_PrimitiveValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_OTASPRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
OTASPRequestRes_U_set, hf_index, ett_ansi_map_OTASPRequestRes_U);
return offset;
}
static int
dissect_ansi_map_OTASPRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_OTASPRequestRes_U);
return offset;
}
static int
dissect_ansi_map_Record_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_StatusRequest_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
StatusRequest_U_set, hf_index, ett_ansi_map_StatusRequest_U);
return offset;
}
static int
dissect_ansi_map_StatusRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_StatusRequest_U);
return offset;
}
static int
dissect_ansi_map_Information_Record(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_StatusRequestRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
StatusRequestRes_U_set, hf_index, ett_ansi_map_StatusRequestRes_U);
return offset;
}
static int
dissect_ansi_map_StatusRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_StatusRequestRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPoint_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemSMSDeliveryPointToPoint_U_set, hf_index, ett_ansi_map_InterSystemSMSDeliveryPointToPoint_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemSMSDeliveryPointToPoint_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemSMSDeliveryPointToPointRes_U_set, hf_index, ett_ansi_map_InterSystemSMSDeliveryPointToPointRes_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes_U);
return offset;
}
static int
dissect_ansi_map_CDMA2000MobileSupportedCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSPage_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
InterSystemSMSPage_U_set, hf_index, ett_ansi_map_InterSystemSMSPage_U);
return offset;
}
static int
dissect_ansi_map_InterSystemSMSPage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_InterSystemSMSPage_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest2_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationRequest2_U_set, hf_index, ett_ansi_map_QualificationRequest2_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationRequest2_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest2Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
QualificationRequest2Res_U_set, hf_index, ett_ansi_map_QualificationRequest2Res_U);
return offset;
}
static int
dissect_ansi_map_QualificationRequest2Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 18, FALSE, dissect_ansi_map_QualificationRequest2Res_U);
return offset;
}
static void
dissect_ansi_map_win_trigger_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
int offset = 0;
int end_offset = 0;
int j = 0;
proto_tree *subtree;
guint8 octet;
end_offset = tvb_reported_length_remaining(tvb,offset);
subtree = proto_item_add_subtree(actx->created_item, ett_win_trigger_list);
while(offset< end_offset) {
octet = tvb_get_guint8(tvb,offset);
switch (octet){
case 0xdc:
proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "TDP-R's armed");
j=0;
break;
case 0xdd:
proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "TDP-N's armed");
j=0;
break;
case 0xde:
proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "EDP-R's armed");
j=0;
break;
case 0xdf:
proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "EDP-N's armed");
j=0;
break;
default:
proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "[%u] (%u) %s",j,octet,val_to_str_ext(octet, &ansi_map_TriggerType_vals_ext, "Unknown TriggerType (%u)"));
j++;
break;
}
offset++;
}
}
static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
static gboolean opCodeKnown = TRUE;
static ansi_map_tap_rec_t tap_rec[16];
static ansi_map_tap_rec_t *tap_p;
static int tap_current=0;
tap_current++;
if (tap_current == array_length(tap_rec))
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
switch(OperationCode){
case 1:
offset = dissect_ansi_map_HandoffMeasurementRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest);
break;
case 2:
offset = dissect_ansi_map_FacilitiesDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective);
break;
case 3:
proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_no_data, tvb, offset, -1);
break;
case 4:
offset = dissect_ansi_map_HandoffBack(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffBack);
break;
case 5:
offset = dissect_ansi_map_FacilitiesRelease(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesRelease);
break;
case 6:
offset = dissect_ansi_map_QualificationRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest);
break;
case 7:
offset = dissect_ansi_map_QualificationDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationDirective);
break;
case 8:
offset = dissect_ansi_map_Blocking(TRUE, tvb, offset, actx, tree, hf_ansi_map_blocking);
break;
case 9:
offset = dissect_ansi_map_Unblocking(TRUE, tvb, offset, actx, tree, hf_ansi_map_unblocking);
break;
case 10:
offset = dissect_ansi_map_ResetCircuit(TRUE, tvb, offset, actx, tree, hf_ansi_map_resetCircuit);
break;
case 11:
offset = dissect_ansi_map_TrunkTest(TRUE, tvb, offset, actx, tree, hf_ansi_map_trunkTest);
break;
case 12:
offset = dissect_ansi_map_TrunkTestDisconnect(TRUE, tvb, offset, actx, tree, hf_ansi_map_trunkTestDisconnect);
break;
case 13:
offset = dissect_ansi_map_RegistrationNotification(TRUE, tvb, offset, actx, tree, hf_ansi_map_registrationNotification);
break;
case 14:
offset = dissect_ansi_map_RegistrationCancellation(TRUE, tvb, offset, actx, tree, hf_ansi_map_registrationCancellation);
break;
case 15:
offset = dissect_ansi_map_LocationRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_locationRequest);
break;
case 16:
offset = dissect_ansi_map_RoutingRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_routingRequest);
break;
case 17:
offset = dissect_ansi_map_FeatureRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_featureRequest);
break;
case 18:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(18 (Service Profile Request, IS-41-C)");
break;
case 19:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(19 Service Profile Directive, IS-41-C)");
break;
case 20:
offset = dissect_ansi_map_UnreliableRoamerDataDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_unreliableRoamerDataDirective);
break;
case 21:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(Reserved 21 (Call Data Request, IS-41-C)");
break;
case 22:
offset = dissect_ansi_map_MSInactive(TRUE, tvb, offset, actx, tree, hf_ansi_map_mSInactive);
break;
case 23:
offset = dissect_ansi_map_TransferToNumberRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_transferToNumberRequest);
break;
case 24:
offset = dissect_ansi_map_RedirectionRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_redirectionRequest);
break;
case 25:
offset = dissect_ansi_map_HandoffToThird(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffToThird);
break;
case 26:
offset = dissect_ansi_map_FlashRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_flashRequest);
break;
case 27:
offset = dissect_ansi_map_AuthenticationDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationDirective);
break;
case 28:
offset = dissect_ansi_map_AuthenticationRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationRequest);
break;
case 29:
offset = dissect_ansi_map_BaseStationChallenge(TRUE, tvb, offset, actx, tree, hf_ansi_map_baseStationChallenge);
break;
case 30:
offset = dissect_ansi_map_AuthenticationFailureReport(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationFailureReport);
break;
case 31:
offset = dissect_ansi_map_CountRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_countRequest);
break;
case 32:
offset = dissect_ansi_map_InterSystemPage(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPage);
break;
case 33:
offset = dissect_ansi_map_UnsolicitedResponse(TRUE, tvb, offset, actx, tree, hf_ansi_map_unsolicitedResponse);
break;
case 34:
offset = dissect_ansi_map_BulkDeregistration(TRUE, tvb, offset, actx, tree, hf_ansi_map_bulkDeregistration);
break;
case 35:
offset = dissect_ansi_map_HandoffMeasurementRequest2(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest2);
break;
case 36:
offset = dissect_ansi_map_FacilitiesDirective2(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective2);
break;
case 37:
offset = dissect_ansi_map_HandoffBack2(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffBack2);
break;
case 38:
offset = dissect_ansi_map_HandoffToThird2(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffToThird2);
break;
case 39:
offset = dissect_ansi_map_AuthenticationDirectiveForward(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveForward);
break;
case 40:
offset = dissect_ansi_map_AuthenticationStatusReport(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationStatusReport);
break;
case 41:
proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Reserved 41, Unknown invokeData blob");
break;
case 42:
offset = dissect_ansi_map_InformationDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_informationDirective);
break;
case 43:
offset = dissect_ansi_map_InformationForward(TRUE, tvb, offset, actx, tree, hf_ansi_map_informationForward);
break;
case 44:
offset = dissect_ansi_map_InterSystemAnswer(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemAnswer);
break;
case 45:
offset = dissect_ansi_map_InterSystemPage2(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPage2);
break;
case 46:
offset = dissect_ansi_map_InterSystemSetup(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemSetup);
break;
case 47:
offset = dissect_ansi_map_OriginationRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_originationRequest);
break;
case 48:
offset = dissect_ansi_map_RandomVariableRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_randomVariableRequest);
break;
case 49:
offset = dissect_ansi_map_RedirectionDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_redirectionDirective);
break;
case 50:
offset = dissect_ansi_map_RemoteUserInteractionDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_remoteUserInteractionDirective);
break;
case 51:
offset = dissect_ansi_map_SMSDeliveryBackward(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryBackward);
break;
case 52:
offset = dissect_ansi_map_SMSDeliveryForward(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryForward);
break;
case 53:
offset = dissect_ansi_map_SMSDeliveryPointToPoint(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryPointToPoint);
break;
case 54:
offset = dissect_ansi_map_SMSNotification(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSNotification);
break;
case 55:
offset = dissect_ansi_map_SMSRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSRequest);
break;
case 56:
offset = dissect_ansi_map_OTASPRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_oTASPRequest);
break;
case 57:
break;
case 58:
offset = dissect_ansi_map_ChangeFacilities(TRUE, tvb, offset, actx, tree, hf_ansi_map_changeFacilities);
break;
case 59:
offset = dissect_ansi_map_ChangeService(TRUE, tvb, offset, actx, tree, hf_ansi_map_changeService);
break;
case 60:
offset = dissect_ansi_map_ParameterRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_parameterRequest);
break;
case 61:
offset = dissect_ansi_map_TMSIDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_tMSIDirective);
break;
case 62:
offset = dissect_ansi_map_NumberPortabilityRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_numberPortabilityRequest);
break;
case 63:
offset = dissect_ansi_map_ServiceRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_serviceRequest);
break;
case 64:
offset = dissect_ansi_map_AnalyzedInformation(TRUE, tvb, offset, actx, tree, hf_ansi_map_analyzedInformation);
break;
case 65:
offset = dissect_ansi_map_ConnectionFailureReport(TRUE, tvb, offset, actx, tree, hf_ansi_map_connectionFailureReport);
break;
case 66:
offset = dissect_ansi_map_ConnectResource(TRUE, tvb, offset, actx, tree, hf_ansi_map_connectResource);
break;
case 67:
break;
case 68:
offset = dissect_ansi_map_FacilitySelectedAndAvailable(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitySelectedAndAvailable);
break;
case 69:
break;
case 70:
offset = dissect_ansi_map_Modify(TRUE, tvb, offset, actx, tree, hf_ansi_map_modify);
break;
case 71:
break;
case 72:
offset = dissect_ansi_map_Search(TRUE, tvb, offset, actx, tree, hf_ansi_map_search);
break;
case 73:
offset = dissect_ansi_map_SeizeResource(TRUE, tvb, offset, actx, tree, hf_ansi_map_seizeResource);
break;
case 74:
offset = dissect_ansi_map_SRFDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_sRFDirective);
break;
case 75:
offset = dissect_ansi_map_TBusy(TRUE, tvb, offset, actx, tree, hf_ansi_map_tBusy);
break;
case 76:
offset = dissect_ansi_map_TNoAnswer(TRUE, tvb, offset, actx, tree, hf_ansi_map_tNoAnswer);
break;
case 77:
break;
case 78:
offset = dissect_ansi_map_SMSDeliveryPointToPointAck(TRUE, tvb, offset, actx, tree, hf_ansi_map_smsDeliveryPointToPointAck);
break;
case 79:
offset = dissect_ansi_map_MessageDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_messageDirective);
break;
case 80:
offset = dissect_ansi_map_BulkDisconnection(TRUE, tvb, offset, actx, tree, hf_ansi_map_bulkDisconnection);
break;
case 81:
offset = dissect_ansi_map_CallControlDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_callControlDirective);
break;
case 82:
offset = dissect_ansi_map_OAnswer(TRUE, tvb, offset, actx, tree, hf_ansi_map_oAnswer);
break;
case 83:
offset = dissect_ansi_map_ODisconnect(TRUE, tvb, offset, actx, tree, hf_ansi_map_oDisconnect);
break;
case 84:
offset = dissect_ansi_map_CallRecoveryReport(TRUE, tvb, offset, actx, tree, hf_ansi_map_callRecoveryReport);
break;
case 85:
offset = dissect_ansi_map_TAnswer(TRUE, tvb, offset, actx, tree, hf_ansi_map_tAnswer);
break;
case 86:
offset = dissect_ansi_map_TDisconnect(TRUE, tvb, offset, actx, tree, hf_ansi_map_tDisconnect);
break;
case 87:
offset = dissect_ansi_map_UnreliableCallData(TRUE, tvb, offset, actx, tree, hf_ansi_map_unreliableCallData);
break;
case 88:
offset = dissect_ansi_map_OCalledPartyBusy(TRUE, tvb, offset, actx, tree, hf_ansi_map_oCalledPartyBusy);
break;
case 89:
offset = dissect_ansi_map_ONoAnswer(TRUE, tvb, offset, actx, tree, hf_ansi_map_oNoAnswer);
break;
case 90:
offset = dissect_ansi_map_PositionRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_positionRequest);
break;
case 91:
offset = dissect_ansi_map_PositionRequestForward(TRUE, tvb, offset, actx, tree, hf_ansi_map_positionRequestForward);
break;
case 92:
offset = dissect_ansi_map_CallTerminationReport(TRUE, tvb, offset, actx, tree, hf_ansi_map_callTerminationReport);
break;
case 93:
break;
case 94:
offset = dissect_ansi_map_GeoPositionRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequest);
break;
case 95:
offset = dissect_ansi_map_InterSystemPositionRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequest);
break;
case 96:
offset = dissect_ansi_map_InterSystemPositionRequestForward(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestForward);
break;
case 97:
offset = dissect_ansi_map_ACGDirective(TRUE, tvb, offset, actx, tree, hf_ansi_map_aCGDirective);
break;
case 98:
offset = dissect_ansi_map_RoamerDatabaseVerificationRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_roamerDatabaseVerificationRequest);
break;
case 99:
offset = dissect_ansi_map_AddService(TRUE, tvb, offset, actx, tree, hf_ansi_map_addService);
break;
case 100:
offset = dissect_ansi_map_DropService(TRUE, tvb, offset, actx, tree, hf_ansi_map_dropService);
break;
case 101:
offset = dissect_ansi_map_InterSystemSMSPage(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSPage);
break;
case 102:
offset = dissect_ansi_map_LCSParameterRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_lcsParameterRequest);
break;
case 104:
offset = dissect_ansi_map_CheckMEID(TRUE, tvb, offset, actx, tree, hf_ansi_map_checkMEID);
break;
case 106:
offset = dissect_ansi_map_PositionEventNotification(TRUE, tvb, offset, actx, tree, hf_ansi_map_positionEventNotification);
break;
case 107:
offset = dissect_ansi_map_StatusRequest(TRUE, tvb, offset, actx, tree, hf_ansi_map_statusRequest);
break;
case 111:
offset = dissect_ansi_map_InterSystemSMSDeliveryPointToPoint(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSDeliveryPointToPoint);
break;
case 112:
offset = dissect_ansi_map_QualificationRequest2(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest2);
break;
default:
proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1);
opCodeKnown = FALSE;
break;
}
if (opCodeKnown)
{
tap_p->message_type = OperationCode;
tap_p->size = 0;
tap_queue_packet(ansi_map_tap, g_pinfo, tap_p);
}
return offset;
}
static int dissect_returnData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
static gboolean opCodeKnown = TRUE;
static ansi_map_tap_rec_t tap_rec[16];
static ansi_map_tap_rec_t *tap_p;
static int tap_current=0;
tap_current++;
if (tap_current == array_length(tap_rec))
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
switch(OperationCode){
case 1:
offset = dissect_ansi_map_HandoffMeasurementRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequestRes);
break;
case 2:
offset = dissect_ansi_map_FacilitiesDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirectiveRes);
break;
case 4:
offset = dissect_ansi_map_HandoffBackRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffBackRes);
break;
case 5:
offset = dissect_ansi_map_FacilitiesReleaseRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesReleaseRes);
break;
case 6:
offset = dissect_ansi_map_QualificationRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationRequestRes);
break;
case 7:
offset = dissect_ansi_map_QualificationDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationDirectiveRes);
break;
case 10:
offset = dissect_ansi_map_ResetCircuitRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_resetCircuitRes);
break;
case 13:
offset = dissect_ansi_map_RegistrationNotificationRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_registrationNotificationRes);
break;
case 14:
offset = dissect_ansi_map_RegistrationCancellationRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_registrationCancellationRes);
break;
case 15:
offset = dissect_ansi_map_LocationRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_locationRequestRes);
break;
case 16:
offset = dissect_ansi_map_RoutingRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_routingRequestRes);
break;
case 17:
offset = dissect_ansi_map_FeatureRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_featureRequestRes);
break;
case 23:
offset = dissect_ansi_map_TransferToNumberRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_transferToNumberRequestRes);
break;
case 25:
offset = dissect_ansi_map_HandoffToThirdRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffToThirdRes);
break;
case 26:
proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_no_data, tvb, offset, -1);
break;
case 27:
offset = dissect_ansi_map_AuthenticationDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveRes);
break;
case 28:
offset = dissect_ansi_map_AuthenticationRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationRequestRes);
break;
case 29:
offset = dissect_ansi_map_BaseStationChallengeRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_baseStationChallengeRes);
break;
case 30:
offset = dissect_ansi_map_AuthenticationFailureReportRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationFailureReportRes);
break;
case 31:
offset = dissect_ansi_map_CountRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_countRequestRes);
break;
case 32:
offset = dissect_ansi_map_InterSystemPageRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPageRes);
break;
case 33:
offset = dissect_ansi_map_UnsolicitedResponseRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_unsolicitedResponseRes);
break;
case 35:
offset = dissect_ansi_map_HandoffMeasurementRequest2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest2Res);
break;
case 36:
offset = dissect_ansi_map_FacilitiesDirective2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective2Res);
break;
case 37:
offset = dissect_ansi_map_HandoffBack2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffBack2Res);
break;
case 38:
offset = dissect_ansi_map_HandoffToThird2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_handoffToThird2Res);
break;
case 39:
offset = dissect_ansi_map_AuthenticationDirectiveForwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveForwardRes);
break;
case 40:
offset = dissect_ansi_map_AuthenticationStatusReportRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_authenticationStatusReportRes);
break;
case 42:
offset = dissect_ansi_map_InformationDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_informationDirectiveRes);
break;
case 43:
offset = dissect_ansi_map_InformationForwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_informationForwardRes);
break;
case 45:
offset = dissect_ansi_map_InterSystemPage2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPage2Res);
break;
case 46:
offset = dissect_ansi_map_InterSystemSetupRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemSetupRes);
break;
case 47:
offset = dissect_ansi_map_OriginationRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_originationRequestRes);
break;
case 48:
offset = dissect_ansi_map_RandomVariableRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_randomVariableRequestRes);
break;
case 50:
offset = dissect_ansi_map_RemoteUserInteractionDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_remoteUserInteractionDirectiveRes);
break;
case 51:
offset = dissect_ansi_map_SMSDeliveryBackwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryBackwardRes);
break;
case 52:
offset = dissect_ansi_map_SMSDeliveryForwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryForwardRes);
break;
case 53:
offset = dissect_ansi_map_SMSDeliveryPointToPointRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryPointToPointRes);
break;
case 54:
offset = dissect_ansi_map_SMSNotificationRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSNotificationRes);
break;
case 55:
offset = dissect_ansi_map_SMSRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sMSRequestRes);
break;
case 56:
offset = dissect_ansi_map_OTASPRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_oTASPRequestRes);
break;
case 58:
offset = dissect_ansi_map_ChangeFacilitiesRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_changeFacilitiesRes);
break;
case 59:
offset = dissect_ansi_map_ChangeServiceRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_changeServiceRes);
break;
case 60:
offset = dissect_ansi_map_ParameterRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_parameterRequestRes);
break;
case 61:
offset = dissect_ansi_map_TMSIDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_tMSIDirectiveRes);
break;
case 62:
offset = dissect_ansi_map_NumberPortabilityRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_numberPortabilityRequestRes);
break;
case 63:
offset = dissect_ansi_map_ServiceRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_serviceRequestRes);
break;
case 64:
offset = dissect_ansi_map_AnalyzedInformationRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_analyzedInformationRes);
break;
case 68:
offset = dissect_ansi_map_FacilitySelectedAndAvailableRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_facilitySelectedAndAvailableRes);
break;
case 70:
offset = dissect_ansi_map_ModifyRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_modifyRes);
break;
case 72:
offset = dissect_ansi_map_SearchRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_searchRes);
break;
case 73:
offset = dissect_ansi_map_SeizeResourceRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_seizeResourceRes);
break;
case 74:
offset = dissect_ansi_map_SRFDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_sRFDirectiveRes);
break;
case 75:
offset = dissect_ansi_map_TBusyRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_tBusyRes);
break;
case 76:
offset = dissect_ansi_map_TNoAnswerRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_tNoAnswerRes);
break;
case 81:
offset = dissect_ansi_map_CallControlDirectiveRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_callControlDirectiveRes);
break;
case 83:
offset = dissect_ansi_map_ODisconnectRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_oDisconnectRes);
break;
case 86:
offset = dissect_ansi_map_TDisconnectRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_tDisconnectRes);
break;
case 88:
offset = dissect_ansi_map_OCalledPartyBusyRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_oCalledPartyBusyRes);
break;
case 89:
offset = dissect_ansi_map_ONoAnswerRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_oNoAnswerRes);
break;
case 90:
offset = dissect_ansi_map_PositionRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_positionRequestRes);
break;
case 91:
offset = dissect_ansi_map_PositionRequestForwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_positionRequestForwardRes);
break;
case 95:
offset = dissect_ansi_map_InterSystemPositionRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestRes);
break;
case 96:
offset = dissect_ansi_map_InterSystemPositionRequestForwardRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestRes);
break;
case 98:
offset = dissect_ansi_map_RoamerDatabaseVerificationRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_roamerDatabaseVerificationRequestRes);
break;
case 99:
offset = dissect_ansi_map_AddServiceRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_addServiceRes);
break;
case 100:
offset = dissect_ansi_map_DropServiceRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_dropServiceRes);
break;
case 102:
offset = dissect_ansi_map_LCSParameterRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_lcsParameterRequestRes);
break;
case 104:
offset = dissect_ansi_map_CheckMEIDRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_checkMEIDRes);
break;
case 107:
offset = dissect_ansi_map_StatusRequestRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_statusRequestRes);
break;
case 111:
offset = dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes(TRUE, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSDeliveryPointToPointRes);
break;
case 112:
offset = dissect_ansi_map_QualificationRequest2Res(TRUE, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest2Res);
break;
default:
proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1);
opCodeKnown = FALSE;
break;
}
if (opCodeKnown)
{
tap_p->message_type = OperationCode;
tap_p->size = 0;
tap_queue_packet(ansi_map_tap, g_pinfo, tap_p);
}
return offset;
}
static int
find_saved_invokedata(asn1_ctx_t *actx, struct ansi_tcap_private_t *p_private_tcap){
struct ansi_map_invokedata_t *ansi_map_saved_invokedata;
address* src = &(actx->pinfo->src);
address* dst = &(actx->pinfo->dst);
guint8 *src_str;
guint8 *dst_str;
char *buf;
buf=(char *)wmem_alloc(wmem_packet_scope(), 1024);
src_str = address_to_str(wmem_packet_scope(), src);
dst_str = address_to_str(wmem_packet_scope(), dst);
switch(ansi_map_response_matching_type){
case ANSI_MAP_TID_ONLY:
g_snprintf(buf,1024,"%s",p_private_tcap->TransactionID_str);
break;
case ANSI_MAP_TID_AND_SOURCE:
g_snprintf(buf,1024,"%s%s",p_private_tcap->TransactionID_str,dst_str);
break;
case ANSI_MAP_TID_SOURCE_AND_DEST:
default:
g_snprintf(buf,1024,"%s%s%s",p_private_tcap->TransactionID_str,dst_str,src_str);
break;
}
ansi_map_saved_invokedata = (struct ansi_map_invokedata_t *)wmem_map_lookup(TransactionId_table, buf);
if(ansi_map_saved_invokedata){
OperationCode = ansi_map_saved_invokedata->opcode & 0xff;
ServiceIndicator = ansi_map_saved_invokedata->ServiceIndicator;
}else{
OperationCode = OperationCode & 0x00ff;
}
return OperationCode;
}
static int
dissect_ansi_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ansi_map_item;
proto_tree *ansi_map_tree = NULL;
struct ansi_tcap_private_t *p_private_tcap = (struct ansi_tcap_private_t *)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
SMS_BearerData_tvb = NULL;
ansi_map_sms_tele_id = -1;
g_pinfo = pinfo;
g_tree = tree;
if (data == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ANSI MAP");
ansi_map_item = proto_tree_add_item(tree, proto_ansi_map, tvb, 0, -1, ENC_NA);
ansi_map_tree = proto_item_add_subtree(ansi_map_item, ett_ansi_map);
ansi_map_is_invoke = FALSE;
is683_ota = FALSE;
is801_pld = FALSE;
ServiceIndicator = 0;
switch(p_private_tcap->d.pdu){
case 1:
OperationCode = p_private_tcap->d.OperationCode_private & 0x00ff;
ansi_map_is_invoke = TRUE;
col_add_fstr(pinfo->cinfo, COL_INFO,"%s Invoke ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
proto_item_append_text(p_private_tcap->d.OperationCode_item," %s",val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
dissect_invokeData(ansi_map_tree, tvb, 0, &asn1_ctx);
update_saved_invokedata(pinfo, p_private_tcap);
break;
case 2:
OperationCode = find_saved_invokedata(&asn1_ctx, p_private_tcap);
col_add_fstr(pinfo->cinfo, COL_INFO,"%s ReturnResult ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
proto_item_append_text(p_private_tcap->d.OperationCode_item," %s",val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
dissect_returnData(ansi_map_tree, tvb, 0, &asn1_ctx);
break;
case 3:
col_add_fstr(pinfo->cinfo, COL_INFO,"%s ReturnError ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
break;
case 4:
col_add_fstr(pinfo->cinfo, COL_INFO,"%s Reject ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
return tvb_captured_length(tvb);
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_ansi_tcap_subdissector(ssn , ansi_map_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_ansi_tcap_subdissector(ssn , ansi_map_handle);
}
}
static void ansi_map_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* table = new_stat_tap_init_table("ANSI MAP Operation Statistics", num_fields, 0, "ansi_map.op_code", gui_callback, gui_data);
int i = 0;
stat_tap_table_item_type items[sizeof(stat_fields)/sizeof(stat_tap_table_item)];
new_stat_tap_add_table(new_stat, table);
while (ansi_map_opr_code_strings[i].strptr)
{
items[OPCODE_COLUMN].type = TABLE_ITEM_UINT;
items[OPCODE_COLUMN].value.uint_value = ansi_map_opr_code_strings[i].value;
items[OPERATION_COLUMN].type = TABLE_ITEM_STRING;
items[OPERATION_COLUMN].value.string_value = ansi_map_opr_code_strings[i].strptr;
items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
items[COUNT_COLUMN].value.uint_value = 0;
items[TOTAL_BYTES_COLUMN].type = TABLE_ITEM_UINT;
items[TOTAL_BYTES_COLUMN].value.uint_value = 0;
items[AVG_BYTES_COLUMN].type = TABLE_ITEM_FLOAT;
items[AVG_BYTES_COLUMN].value.float_value = 0.0f;
new_stat_tap_init_table_row(table, ansi_map_opr_code_strings[i].value, num_fields, items);
i++;
}
}
static gboolean
ansi_map_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *data)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const ansi_map_tap_rec_t *data_p = (const ansi_map_tap_rec_t *)data;
stat_tap_table* table;
stat_tap_table_item_type* item_data;
guint i = 0, count, total_bytes;
if (try_val_to_str(data_p->message_type, ansi_map_opr_code_strings) == NULL)
return FALSE;
table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, i);
item_data = new_stat_tap_get_field_data(table, data_p->message_type, COUNT_COLUMN);
item_data->value.uint_value++;
count = item_data->value.uint_value;
new_stat_tap_set_field_data(table, data_p->message_type, COUNT_COLUMN, item_data);
item_data = new_stat_tap_get_field_data(table, data_p->message_type, TOTAL_BYTES_COLUMN);
item_data->value.uint_value += data_p->size;
total_bytes = item_data->value.uint_value;
new_stat_tap_set_field_data(table, data_p->message_type, TOTAL_BYTES_COLUMN, item_data);
item_data = new_stat_tap_get_field_data(table, data_p->message_type, AVG_BYTES_COLUMN);
item_data->value.float_value = (float)total_bytes/(float)count;
new_stat_tap_set_field_data(table, data_p->message_type, AVG_BYTES_COLUMN, item_data);
return TRUE;
}
static void
ansi_map_stat_reset(stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, COUNT_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, COUNT_COLUMN, item_data);
item_data = new_stat_tap_get_field_data(table, element, TOTAL_BYTES_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, TOTAL_BYTES_COLUMN, item_data);
item_data = new_stat_tap_get_field_data(table, element, AVG_BYTES_COLUMN);
item_data->value.float_value = 0.0f;
new_stat_tap_set_field_data(table, element, AVG_BYTES_COLUMN, item_data);
}
}
void
proto_reg_handoff_ansi_map(void)
{
static gboolean ansi_map_prefs_initialized = FALSE;
static range_t *ssn_range;
if(!ansi_map_prefs_initialized)
{
ansi_map_prefs_initialized = TRUE;
}
else
{
range_foreach(ssn_range, range_delete_callback);
wmem_free(wmem_epan_scope(), ssn_range);
}
ssn_range = range_copy(wmem_epan_scope(), global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_ansi_map(void) {
module_t *ansi_map_module;
static hf_register_info hf[] = {
{ &hf_ansi_map_op_code_fam,
{ "Operation Code Family", "ansi_map.op_code_fam",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitH,
{ "Reserved", "ansi_map.reserved_bitH",
FT_BOOLEAN, 8, NULL,0x80,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitD,
{ "Reserved", "ansi_map.reserved_bitD",
FT_BOOLEAN, 8, NULL,0x08,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitHG,
{ "Reserved", "ansi_map.reserved_bitHG",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitHGFE,
{ "Reserved", "ansi_map.reserved_bitHGFE",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitFED,
{ "Reserved", "ansi_map.reserved_bitFED",
FT_UINT8, BASE_DEC, NULL, 0x38,
NULL, HFILL }},
{ &hf_ansi_map_reservedBitED,
{ "Reserved", "ansi_map.reserved_bitED",
FT_UINT8, BASE_DEC, NULL, 0x18,
NULL, HFILL }},
{ &hf_ansi_map_op_code,
{ "Operation Code", "ansi_map.op_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ansi_map_opr_code_strings_ext, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_type_of_digits,
{ "Type of Digits", "ansi_map.type_of_digits",
FT_UINT8, BASE_DEC, VALS(ansi_map_type_of_digits_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_na,
{ "Nature of Number", "ansi_map.na",
FT_BOOLEAN, 8, TFS(&ansi_map_na_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_pi,
{ "Presentation Indication", "ansi_map.type_of_pi",
FT_BOOLEAN, 8, TFS(&ansi_map_pi_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_navail,
{ "Number available indication", "ansi_map.navail",
FT_BOOLEAN, 8, TFS(&ansi_map_navail_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_si,
{ "Screening indication", "ansi_map.si",
FT_UINT8, BASE_DEC, VALS(ansi_map_si_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_digits_enc,
{ "Encoding", "ansi_map.enc",
FT_UINT8, BASE_DEC, VALS(ansi_map_digits_enc_vals), 0x0f,
NULL, HFILL }},
{ &hf_ansi_map_np,
{ "Numbering Plan", "ansi_map.np",
FT_UINT8, BASE_DEC, VALS(ansi_map_np_vals), 0xf0,
NULL, HFILL }},
{ &hf_ansi_map_nr_digits,
{ "Number of Digits", "ansi_map.nr_digits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_bcd_digits,
{ "BCD digits", "ansi_map.bcd_digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_ia5_digits,
{ "IA5 digits", "ansi_map.ia5_digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_subaddr_type,
{ "Type of Subaddress", "ansi_map.subaddr_type",
FT_UINT8, BASE_DEC, VALS(ansi_map_sub_addr_type_vals), 0x70,
NULL, HFILL }},
{ &hf_ansi_map_subaddr_odd_even,
{ "Odd/Even Indicator", "ansi_map.subaddr_odd_even",
FT_BOOLEAN, 8, TFS(&ansi_map_navail_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_alertcode_cadence,
{ "Cadence", "ansi_map.alertcode.cadence",
FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Cadence_vals), 0x3f,
NULL, HFILL }},
{ &hf_ansi_alertcode_pitch,
{ "Pitch", "ansi_map.alertcode.pitch",
FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Pitch_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_alertcode_alertaction,
{ "Alert Action", "ansi_map.alertcode.alertaction",
FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Alert_Action_vals), 0x07,
NULL, HFILL }},
{ &hf_ansi_map_announcementcode_tone,
{ "Tone", "ansi_map.announcementcode.tone",
FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_tone_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_announcementcode_class,
{ "Tone", "ansi_map.announcementcode.class",
FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_class_vals), 0xf,
NULL, HFILL }},
{ &hf_ansi_map_announcementcode_std_ann,
{ "Standard Announcement", "ansi_map.announcementcode.std_ann",
FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_std_ann_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_announcementcode_cust_ann,
{ "Custom Announcement", "ansi_map.announcementcode.cust_ann",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_authorizationperiod_period,
{ "Period", "ansi_map.authorizationperiod.period",
FT_UINT8, BASE_DEC, VALS(ansi_map_authorizationperiod_period_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_value,
{ "Value", "ansi_map.value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_msc_type,
{ "Type", "ansi_map.extendedmscid.type",
FT_UINT8, BASE_DEC, VALS(ansi_map_msc_type_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_handoffstate_pi,
{ "Party Involved (PI)", "ansi_map.handoffstate.pi",
FT_BOOLEAN, 8, TFS(&ansi_map_HandoffState_pi_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_tgn,
{ "Trunk Group Number (G)", "ansi_map.tgn",
FT_UINT8, BASE_DEC, NULL,0x0,
NULL, HFILL }},
{ &hf_ansi_map_tmn,
{ "Trunk Member Number (M)", "ansi_map.tmn",
FT_UINT8, BASE_DEC, NULL,0x0,
NULL, HFILL }},
{ &hf_ansi_map_messagewaitingnotificationcount_tom,
{ "Type of messages", "ansi_map.messagewaitingnotificationcount.tom",
FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationCount_type_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_messagewaitingnotificationcount_no_mw,
{ "Number of Messages Waiting", "ansi_map.messagewaitingnotificationcount.nomw",
FT_UINT8, BASE_DEC, NULL,0x0,
NULL, HFILL }},
{ &hf_ansi_map_messagewaitingnotificationtype_mwi,
{ "Message Waiting Indication (MWI)", "ansi_map.messagewaitingnotificationcount.mwi",
FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationType_mwi_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_messagewaitingnotificationtype_apt,
{ "Alert Pip Tone (APT)", "ansi_map.messagewaitingnotificationtype.apt",
FT_BOOLEAN, 8, TFS(&ansi_map_HandoffState_pi_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_messagewaitingnotificationtype_pt,
{ "Pip Tone (PT)", "ansi_map.messagewaitingnotificationtype.pt",
FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationType_mwi_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_prof,
{ "Profile (PROF)", "ansi_map.trans_cap_prof",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_prof_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_busy,
{ "Busy Detection (BUSY)", "ansi_map.trans_cap_busy",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_busy_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_ann,
{ "Announcements (ANN)", "ansi_map.trans_cap_ann",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_ann_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_rui,
{ "Remote User Interaction (RUI)", "ansi_map.trans_cap_rui",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_rui_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_spini,
{ "Subscriber PIN Intercept (SPINI)", "ansi_map.trans_cap_spini",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_spini_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_uzci,
{ "UZ Capability Indicator (UZCI)", "ansi_map.trans_cap_uzci",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_uzci_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_ndss,
{ "NDSS Capability (NDSS)", "ansi_map.trans_cap_ndss",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_ndss_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_trans_cap_nami,
{ "NAME Capability Indicator (NAMI)", "ansi_map.trans_cap_nami",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_nami_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_trans_cap_multerm,
{ "Multiple Terminations", "ansi_map.trans_cap_multerm",
FT_UINT8, BASE_DEC, VALS(ansi_map_trans_cap_multerm_vals), 0x0f,
NULL, HFILL }},
{ &hf_ansi_map_terminationtriggers_busy,
{ "Busy", "ansi_map.terminationtriggers.busy",
FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_busy_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_terminationtriggers_rf,
{ "Routing Failure (RF)", "ansi_map.terminationtriggers.rf",
FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_rf_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_terminationtriggers_npr,
{ "No Page Response (NPR)", "ansi_map.terminationtriggers.npr",
FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_npr_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_terminationtriggers_na,
{ "No Answer (NA)", "ansi_map.terminationtriggers.na",
FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_na_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_terminationtriggers_nr,
{ "None Reachable (NR)", "ansi_map.terminationtriggers.nr",
FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_nr_vals), 0x01,
NULL, HFILL }},
{ &hf_ansi_trans_cap_tl,
{ "TerminationList (TL)", "ansi_map.trans_cap_tl",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_tl_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_cdmaserviceoption,
{ "CDMAServiceOption", "ansi_map.cdmaserviceoption",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(cdmaserviceoption_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_trans_cap_waddr,
{ "WIN Addressing (WADDR)", "ansi_map.trans_cap_waddr",
FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_waddr_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_MarketID,
{ "MarketID", "ansi_map.marketid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_swno,
{ "Switch Number (SWNO)", "ansi_map.swno",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_idno,
{ "ID Number", "ansi_map.idno",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_segcount,
{ "Segment Counter", "ansi_map.segcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_originationrestrictions_direct,
{ "DIRECT", "ansi_map.originationrestrictions.direct",
FT_BOOLEAN, 8, TFS(&ansi_map_SMS_OriginationRestrictions_direct_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_sms_originationrestrictions_default,
{ "DEFAULT", "ansi_map.originationrestrictions.default",
FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_OriginationRestrictions_default_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_sms_originationrestrictions_fmc,
{ "Force Message Center (FMC)", "ansi_map.originationrestrictions.fmc",
FT_BOOLEAN, 8, TFS(&ansi_map_SMS_OriginationRestrictions_fmc_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_auth,
{ "Authentication Parameters Requested (AUTH)", "ansi_map.systemcapabilities.auth",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_auth_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_se,
{ "Signaling Message Encryption Capable (SE )", "ansi_map.systemcapabilities.se",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_se_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_vp,
{ "Voice Privacy Capable (VP )", "ansi_map.systemcapabilities.vp",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_vp_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_cave,
{ "CAVE Algorithm Capable (CAVE)", "ansi_map.systemcapabilities.cave",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_cave_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_ssd,
{ "Shared SSD (SSD)", "ansi_map.systemcapabilities.ssd",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_ssd_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_systemcapabilities_dp,
{ "Data Privacy (DP)", "ansi_map.systemcapabilities.dp",
FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_dp_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_mslocation_lat,
{ "Latitude in tenths of a second", "ansi_map.mslocation.lat",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mslocation_long,
{ "Longitude in tenths of a second", "ansi_map.mslocation.long",
FT_UINT8, BASE_DEC, NULL, 0,
"Switch Number (SWNO)", HFILL }},
{ &hf_ansi_map_mslocation_res,
{ "Resolution in units of 1 foot", "ansi_map.mslocation.res",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_nampscallmode_namps,
{ "Call Mode", "ansi_map.nampscallmode.namps",
FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_namps_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_nampscallmode_amps,
{ "Call Mode", "ansi_map.nampscallmode.amps",
FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_amps_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_nampschanneldata_navca,
{ "Narrow Analog Voice Channel Assignment (NAVCA)", "ansi_map.nampschanneldata.navca",
FT_UINT8, BASE_DEC, VALS(ansi_map_NAMPSChannelData_navca_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_nampschanneldata_CCIndicator,
{ "Color Code Indicator (CCIndicator)", "ansi_map.nampschanneldata.ccindicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_NAMPSChannelData_ccinidicator_vals), 0x1c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cfufa,
{ "Call Forwarding Unconditional FeatureActivity, CFU-FA", "ansi_map.callingfeaturesindicator.cfufa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cfbfa,
{ "Call Forwarding Busy FeatureActivity, CFB-FA", "ansi_map.callingfeaturesindicator.cfbafa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cfnafa,
{ "Call Forwarding No Answer FeatureActivity, CFNA-FA", "ansi_map.callingfeaturesindicator.cfnafa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cwfa,
{ "Call Waiting: FeatureActivity, CW-FA", "ansi_map.callingfeaturesindicator.cwfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_3wcfa,
{ "Three-Way Calling FeatureActivity, 3WC-FA", "ansi_map.callingfeaturesindicator.3wcfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_pcwfa,
{ "Priority Call Waiting FeatureActivity PCW-FA", "ansi_map.callingfeaturesindicator.pcwfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_dpfa,
{ "Data Privacy Feature Activity DP-FA", "ansi_map.callingfeaturesindicator.dpfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_ahfa,
{ "Answer Hold: FeatureActivity AH-FA", "ansi_map.callingfeaturesindicator.ahfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_uscfvmfa,
{ "USCF divert to voice mail: FeatureActivity USCFvm-FA", "ansi_map.callingfeaturesindicator.uscfvmfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_uscfmsfa,
{ "USCF divert to mobile station provided DN:FeatureActivity.USCFms-FA", "ansi_map.callingfeaturesindicator.uscfmsfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_uscfnrfa,
{ "USCF divert to network registered DN:FeatureActivity. USCFnr-FA", "ansi_map.callingfeaturesindicator.uscfnrfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cpdsfa,
{ "CDMA-Packet Data Service: FeatureActivity. CPDS-FA", "ansi_map.callingfeaturesindicator.cpdfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_ccsfa,
{ "CDMA-Concurrent Service:FeatureActivity. CCS-FA", "ansi_map.callingfeaturesindicator.ccsfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_epefa,
{ "TDMA Enhanced Privacy and Encryption:FeatureActivity.TDMA EPE-FA", "ansi_map.callingfeaturesindicator.epefa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cdfa,
{ "Call Delivery: FeatureActivity, CD-FA", "ansi_map.callingfeaturesindicator.cdfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_vpfa,
{ "Voice Privacy FeatureActivity, VP-FA", "ansi_map.callingfeaturesindicator.vpfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_ctfa,
{ "Call Transfer: FeatureActivity, CT-FA", "ansi_map.callingfeaturesindicator.ctfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cnip1fa,
{ "One number (network-provided only) Calling Number Identification Presentation: FeatureActivity CNIP1-FA", "ansi_map.callingfeaturesindicator.cnip1fa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cnip2fa,
{ "Two number (network-provided and user-provided) Calling Number Identification Presentation: FeatureActivity CNIP2-FA", "ansi_map.callingfeaturesindicator.cnip2fa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cnirfa,
{ "Calling Number Identification Restriction: FeatureActivity CNIR-FA", "ansi_map.callingfeaturesindicator.cnirfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
NULL, HFILL }},
{ &hf_ansi_map_callingfeaturesindicator_cniroverfa,
{ "Calling Number Identification Restriction Override FeatureActivity CNIROver-FA", "ansi_map.callingfeaturesindicator.cniroverfa",
FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cdma,
{ "Call Mode", "ansi_map.cdmacallmode.cdma",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cdma_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_amps,
{ "Call Mode", "ansi_map.cdmacallmode.amps",
FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_amps_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_namps,
{ "Call Mode", "ansi_map.cdmacallmode.namps",
FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_namps_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls1,
{ "Call Mode", "ansi_map.cdmacallmode.cls1",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls1_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls2,
{ "Call Mode", "ansi_map.cdmacallmode.cls2",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls2_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls3,
{ "Call Mode", "ansi_map.cdmacallmode.cls3",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls3_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls4,
{ "Call Mode", "ansi_map.cdmacallmode.cls4",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls4_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls5,
{ "Call Mode", "ansi_map.cdmacallmode.cls5",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls5_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls6,
{ "Call Mode", "ansi_map.cdmacallmode.cls6",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls6_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls7,
{ "Call Mode", "ansi_map.cdmacallmode.cls7",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls7_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls8,
{ "Call Mode", "ansi_map.cdmacallmode.cls8",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls8_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls9,
{ "Call Mode", "ansi_map.cdmacallmode.cls9",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls9_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_cdmacallmode_cls10,
{ "Call Mode", "ansi_map.cdmacallmode.cls10",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls10_bool_val),0x10,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_Frame_Offset,
{ "Frame Offset", "ansi_map.cdmachanneldata.frameoffset",
FT_UINT8, BASE_DEC, NULL, 0x78,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_CDMA_ch_no,
{ "CDMA Channel Number", "ansi_map.cdmachanneldata.cdma_ch_no",
FT_UINT16, BASE_DEC, NULL, 0x07FF,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_band_cls,
{ "Band Class", "ansi_map.cdmachanneldata.band_cls",
FT_UINT8, BASE_DEC, VALS(ansi_map_cdmachanneldata_band_cls_vals), 0x7c,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b6,
{ "Long Code Mask (byte 6) MSB", "ansi_map.cdmachanneldata.lc_mask_b6",
FT_UINT8, BASE_HEX, NULL, 0x03,
"Long Code Mask MSB (byte 6)", HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b5,
{ "Long Code Mask (byte 5)", "ansi_map.cdmachanneldata.lc_mask_b5",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b4,
{ "Long Code Mask (byte 4)", "ansi_map.cdmachanneldata.lc_mask_b4",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b3,
{ "Long Code Mask (byte 3)", "ansi_map.cdmachanneldata.lc_mask_b3",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b2,
{ "Long Code Mask (byte 2)", "ansi_map.cdmachanneldata.lc_mask_b2",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_lc_mask_b1,
{ "Long Code Mask LSB(byte 1)", "ansi_map.cdmachanneldata.lc_mask_b1",
FT_UINT8, BASE_HEX, NULL, 0xff,
"Long Code Mask (byte 1)LSB", HFILL }},
{&hf_ansi_map_cdmachanneldata_np_ext,
{ "NP EXT", "ansi_map.cdmachanneldata.np_ext",
FT_BOOLEAN, 8, NULL,0x80,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_nominal_pwr,
{ "Nominal Power", "ansi_map.cdmachanneldata.nominal_pwr",
FT_UINT8, BASE_DEC, NULL, 0x71,
NULL, HFILL }},
{&hf_ansi_map_cdmachanneldata_nr_preamble,
{ "Number Preamble", "ansi_map.cdmachanneldata.nr_preamble",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_ansi_map_cdmastationclassmark_pc,
{ "Power Class(PC)", "ansi_map.cdmastationclassmark.pc",
FT_UINT8, BASE_DEC, VALS(ansi_map_CDMAStationClassMark_pc_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_cdmastationclassmark_dtx,
{ "Analog Transmission: (DTX)", "ansi_map.cdmastationclassmark.dtx",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_dtx_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_cdmastationclassmark_smi,
{ "Slotted Mode Indicator: (SMI)", "ansi_map.cdmastationclassmark.smi",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_smi_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_cdmastationclassmark_dmi,
{ "Dual-mode Indicator(DMI)", "ansi_map.cdmastationclassmark.dmi",
FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_dmi_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_channeldata_vmac,
{ "Voice Mobile Attenuation Code (VMAC)", "ansi_map.channeldata.vmac",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_ansi_map_channeldata_dtx,
{ "Discontinuous Transmission Mode (DTX)", "ansi_map.channeldata.dtx",
FT_UINT8, BASE_DEC, VALS(ansi_map_ChannelData_dtx_vals), 0x18,
NULL, HFILL }},
{ &hf_ansi_map_channeldata_scc,
{ "SAT Color Code (SCC)", "ansi_map.channeldata.scc",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_channeldata_chno,
{ "Channel Number (CHNO)", "ansi_map.channeldata.chno",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_ConfidentialityModes_vp,
{ "Voice Privacy (VP) Confidentiality Status", "ansi_map.confidentialitymodes.vp",
FT_BOOLEAN, 8, TFS(&ansi_map_ConfidentialityModes_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_controlchanneldata_dcc,
{ "Digital Color Code (DCC)", "ansi_map.controlchanneldata.dcc",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }},
{ &hf_ansi_map_controlchanneldata_cmac,
{ "Control Mobile Attenuation Code (CMAC)", "ansi_map.controlchanneldata.cmac",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_ansi_map_controlchanneldata_chno,
{ "Channel Number (CHNO)", "ansi_map.controlchanneldata.chno",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_controlchanneldata_sdcc1,
{ "Supplementary Digital Color Codes (SDCC1)", "ansi_map.controlchanneldata.ssdc1",
FT_UINT8, BASE_DEC, NULL, 0x0c,
NULL, HFILL }},
{ &hf_ansi_map_controlchanneldata_sdcc2,
{ "Supplementary Digital Color Codes (SDCC2)", "ansi_map.controlchanneldata.ssdc2",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL }},
{ &hf_ansi_map_ConfidentialityModes_se,
{ "Signaling Message Encryption (SE) Confidentiality Status", "ansi_map.confidentialitymodes.se",
FT_BOOLEAN, 8, TFS(&ansi_map_ConfidentialityModes_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_ConfidentialityModes_dp,
{ "DataPrivacy (DP) Confidentiality Status", "ansi_map.confidentialitymodes.dp",
FT_BOOLEAN, 8, TFS(&ansi_map_ConfidentialityModes_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_deniedauthorizationperiod_period,
{ "Period", "ansi_map.deniedauthorizationperiod.period",
FT_UINT8, BASE_DEC, VALS(ansi_map_deniedauthorizationperiod_period_vals), 0x0,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_all,
{ "All Origination (All)", "ansi_map.originationtriggers.all",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_all_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_local,
{ "Local", "ansi_map.originationtriggers.local",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_local_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_ilata,
{ "Intra-LATA Toll (ILATA)", "ansi_map.originationtriggers.ilata",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ilata_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_olata,
{ "Inter-LATA Toll (OLATA)", "ansi_map.originationtriggers.olata",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_olata_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_int,
{ "International (Int'l )", "ansi_map.originationtriggers.int",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_int_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_wz,
{ "World Zone (WZ)", "ansi_map.originationtriggers.wz",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_wz_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_unrec,
{ "Unrecognized Number (Unrec)", "ansi_map.originationtriggers.unrec",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_unrec_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_rvtc,
{ "Revertive Call (RvtC)", "ansi_map.originationtriggers.rvtc",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_rvtc_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_star,
{ "Star", "ansi_map.originationtriggers.star",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_star_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_ds,
{ "Double Star (DS)", "ansi_map.originationtriggers.ds",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ds_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_pound,
{ "Pound", "ansi_map.originationtriggers.pound",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_pound_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_dp,
{ "Double Pound (DP)", "ansi_map.originationtriggers.dp",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_dp_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_pa,
{ "Prior Agreement (PA)", "ansi_map.originationtriggers.pa",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_pa_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_nodig,
{ "No digits", "ansi_map.originationtriggers.nodig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_nodig_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_onedig,
{ "1 digit", "ansi_map.originationtriggers.onedig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_onedig_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_twodig,
{ "2 digits", "ansi_map.originationtriggers.twodig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_twodig_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_threedig,
{ "3 digits", "ansi_map.originationtriggers.threedig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_threedig_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_fourdig,
{ "4 digits", "ansi_map.originationtriggers.fourdig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fourdig_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_fivedig,
{ "5 digits", "ansi_map.originationtriggers.fivedig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fivedig_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_sixdig,
{ "6 digits", "ansi_map.originationtriggers.sixdig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_sixdig_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_sevendig,
{ "7 digits", "ansi_map.originationtriggers.sevendig",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_sevendig_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_eightdig,
{ "8 digits", "ansi_map.originationtriggers.eight",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_eightdig_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_ninedig,
{ "9 digits", "ansi_map.originationtriggers.nine",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ninedig_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_tendig,
{ "10 digits", "ansi_map.originationtriggers.ten",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_tendig_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_elevendig,
{ "11 digits", "ansi_map.originationtriggers.eleven",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_elevendig_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_twelvedig,
{ "12 digits", "ansi_map.originationtriggers.twelve",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_twelvedig_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_thirteendig,
{ "13 digits", "ansi_map.originationtriggers.thirteen",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_thirteendig_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_fourteendig,
{ "14 digits", "ansi_map.originationtriggers.fourteen",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fourteendig_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_originationtriggers_fifteendig,
{ "15 digits", "ansi_map.originationtriggers.fifteen",
FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fifteendig_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_init,
{ "Introducing Star/Pound (INIT)", "ansi_map.triggercapability.init",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_kdigit,
{ "K-digit (K-digit)", "ansi_map.triggercapability.kdigit",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_all,
{ "All_Calls (All)", "ansi_map.triggercapability.all",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_rvtc,
{ "Revertive_Call (RvtC)", "ansi_map.triggercapability.rvtc",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_oaa,
{ "Origination_Attempt_Authorized (OAA)", "ansi_map.triggercapability.oaa",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_oans,
{ "O_Answer (OANS)", "ansi_map.triggercapability.oans",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_odisc,
{ "O_Disconnect (ODISC)", "ansi_map.triggercapability.odisc",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_ona,
{ "O_No_Answer (ONA)", "ansi_map.triggercapability.ona",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_ct ,
{ "Call Types (CT)", "ansi_map.triggercapability.ct",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_unrec,
{ "Unrecognized_Number (Unrec)", "ansi_map.triggercapability.unrec",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_pa,
{ "Prior_Agreement (PA)", "ansi_map.triggercapability.pa",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_at,
{ "Advanced_Termination (AT)", "ansi_map.triggercapability.at",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_cgraa,
{ "Calling_Routing_Address_Available (CgRAA)", "ansi_map.triggercapability.cgraa",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_it,
{ "Initial_Termination (IT)", "ansi_map.triggercapability.it",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x20,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_cdraa,
{ "Called_Routing_Address_Available (CdRAA)", "ansi_map.triggercapability.cdraa",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x40,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_obsy,
{ "O_Called_Party_Busy (OBSY)", "ansi_map.triggercapability.obsy",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x80,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_tra ,
{ "Terminating_Resource_Available (TRA)", "ansi_map.triggercapability.tra",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_tbusy,
{ "T_Busy (TBusy)", "ansi_map.triggercapability.tbusy",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_tna,
{ "T_No_Answer (TNA)", "ansi_map.triggercapability.tna",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_tans,
{ "T_Answer (TANS)", "ansi_map.triggercapability.tans",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
NULL, HFILL }},
{ &hf_ansi_map_triggercapability_tdisc,
{ "T_Disconnect (TDISC)", "ansi_map.triggercapability.tdisc",
FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
NULL, HFILL }},
{ &hf_ansi_map_winoperationscapability_conn,
{ "ConnectResource (CONN)", "ansi_map.winoperationscapability.conn",
FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_conn_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_winoperationscapability_ccdir,
{ "CallControlDirective(CCDIR)", "ansi_map.winoperationscapability.ccdir",
FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_ccdir_bool_val),0x02,
NULL, HFILL }},
{ &hf_ansi_map_winoperationscapability_pos,
{ "PositionRequest (POS)", "ansi_map.winoperationscapability.pos",
FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_pos_bool_val),0x04,
NULL, HFILL }},
{ &hf_ansi_map_pacaindicator_pa,
{ "Permanent Activation (PA)", "ansi_map.pacaindicator_pa",
FT_BOOLEAN, 8, TFS(&ansi_map_pacaindicator_pa_bool_val),0x01,
NULL, HFILL }},
{ &hf_ansi_map_PACA_Level,
{ "PACA Level", "ansi_map.PACA_Level",
FT_UINT8, BASE_DEC, VALS(ansi_map_PACA_Level_vals), 0x1e,
NULL, HFILL }},
{ &hf_ansi_map_point_code,
{ "Point Code", "ansi_map.point_code",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_SSN,
{ "SSN", "ansi_map.SSN",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ansi_map_win_trigger_list,
{ "WIN trigger list", "ansi_map.win_trigger_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#line 1 "./asn1/ansi_map/packet-ansi_map-hfarr.c"
{ &hf_ansi_map_electronicSerialNumber,
{ "electronicSerialNumber", "ansi_map.electronicSerialNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_msid,
{ "msid", "ansi_map.msid",
FT_UINT32, BASE_DEC, VALS(ansi_map_MSID_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationAlgorithmVersion,
{ "authenticationAlgorithmVersion", "ansi_map.authenticationAlgorithmVersion",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationResponseReauthentication,
{ "authenticationResponseReauthentication", "ansi_map.authenticationResponseReauthentication",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationResponseUniqueChallenge,
{ "authenticationResponseUniqueChallenge", "ansi_map.authenticationResponseUniqueChallenge",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callHistoryCount,
{ "callHistoryCount", "ansi_map.callHistoryCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaPrivateLongCodeMask,
{ "cdmaPrivateLongCodeMask", "ansi_map.cdmaPrivateLongCodeMask",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_carrierDigits,
{ "carrierDigits", "ansi_map.carrierDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_caveKey,
{ "caveKey", "ansi_map.caveKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_denyAccess,
{ "denyAccess", "ansi_map.denyAccess",
FT_UINT32, BASE_DEC, VALS(ansi_map_DenyAccess_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_destinationDigits,
{ "destinationDigits", "ansi_map.destinationDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_locationAreaID,
{ "locationAreaID", "ansi_map.locationAreaID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableReauthentication,
{ "randomVariableReauthentication", "ansi_map.randomVariableReauthentication",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_meid,
{ "meid", "ansi_map.meid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobileStationMIN,
{ "mobileStationMIN", "ansi_map.mobileStationMIN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mscid,
{ "mscid", "ansi_map.mscid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableSSD,
{ "randomVariableSSD", "ansi_map.randomVariableSSD",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableUniqueChallenge,
{ "randomVariableUniqueChallenge", "ansi_map.randomVariableUniqueChallenge",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_routingDigits,
{ "routingDigits", "ansi_map.routingDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_senderIdentificationNumber,
{ "senderIdentificationNumber", "ansi_map.senderIdentificationNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sharedSecretData,
{ "sharedSecretData", "ansi_map.sharedSecretData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_signalingMessageEncryptionKey,
{ "signalingMessageEncryptionKey", "ansi_map.signalingMessageEncryptionKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_ssdnotShared,
{ "ssdnotShared", "ansi_map.ssdnotShared",
FT_UINT32, BASE_DEC, VALS(ansi_map_SSDNotShared_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_updateCount,
{ "updateCount", "ansi_map.updateCount",
FT_UINT32, BASE_DEC, VALS(ansi_map_UpdateCount_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_interMSCCircuitID,
{ "interMSCCircuitID", "ansi_map.interMSCCircuitID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobileIdentificationNumber,
{ "mobileIdentificationNumber", "ansi_map.mobileIdentificationNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_countUpdateReport,
{ "countUpdateReport", "ansi_map.countUpdateReport",
FT_UINT8, BASE_DEC, VALS(ansi_map_CountUpdateReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_uniqueChallengeReport,
{ "uniqueChallengeReport", "ansi_map.uniqueChallengeReport",
FT_UINT8, BASE_DEC, VALS(ansi_map_UniqueChallengeReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_reportType,
{ "reportType", "ansi_map.reportType",
FT_UINT32, BASE_DEC, VALS(ansi_map_ReportType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_systemAccessType,
{ "systemAccessType", "ansi_map.systemAccessType",
FT_UINT32, BASE_DEC, VALS(ansi_map_SystemAccessType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_systemCapabilities,
{ "systemCapabilities", "ansi_map.systemCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callHistoryCountExpected,
{ "callHistoryCountExpected", "ansi_map.callHistoryCountExpected",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_reportType2,
{ "reportType2", "ansi_map.reportType2",
FT_UINT32, BASE_DEC, VALS(ansi_map_ReportType_vals), 0,
"ReportType", HFILL }},
{ &hf_ansi_map_terminalType,
{ "terminalType", "ansi_map.terminalType",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_TerminalType_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationData,
{ "authenticationData", "ansi_map.authenticationData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationResponse,
{ "authenticationResponse", "ansi_map.authenticationResponse",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaNetworkIdentification,
{ "cdmaNetworkIdentification", "ansi_map.cdmaNetworkIdentification",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_confidentialityModes,
{ "confidentialityModes", "ansi_map.confidentialityModes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_controlChannelMode,
{ "controlChannelMode", "ansi_map.controlChannelMode",
FT_UINT8, BASE_DEC, VALS(ansi_map_ControlChannelMode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_digits,
{ "digits", "ansi_map.digits_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pc_ssn,
{ "pc-ssn", "ansi_map.pc_ssn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariable,
{ "randomVariable", "ansi_map.randomVariable",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceRedirectionCause,
{ "serviceRedirectionCause", "ansi_map.serviceRedirectionCause",
FT_UINT8, BASE_DEC, VALS(ansi_map_ServiceRedirectionCause_type_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_suspiciousAccess,
{ "suspiciousAccess", "ansi_map.suspiciousAccess",
FT_UINT32, BASE_DEC, VALS(ansi_map_SuspiciousAccess_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_transactionCapability,
{ "transactionCapability", "ansi_map.transactionCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_analogRedirectRecord,
{ "analogRedirectRecord", "ansi_map.analogRedirectRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaRedirectRecord,
{ "cdmaRedirectRecord", "ansi_map.cdmaRedirectRecord_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataKey,
{ "dataKey", "ansi_map.dataKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_roamingIndication,
{ "roamingIndication", "ansi_map.roamingIndication",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceRedirectionInfo,
{ "serviceRedirectionInfo", "ansi_map.serviceRedirectionInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_voicePrivacyMask,
{ "voicePrivacyMask", "ansi_map.voicePrivacyMask",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_reauthenticationReport,
{ "reauthenticationReport", "ansi_map.reauthenticationReport",
FT_UINT8, BASE_DEC, VALS(ansi_map_ReauthenticationReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceIndicator,
{ "serviceIndicator", "ansi_map.serviceIndicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_ServiceIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_signalingMessageEncryptionReport,
{ "signalingMessageEncryptionReport", "ansi_map.signalingMessageEncryptionReport",
FT_UINT8, BASE_DEC, VALS(ansi_map_SMEReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_ssdUpdateReport,
{ "ssdUpdateReport", "ansi_map.ssdUpdateReport",
FT_UINT16, BASE_DEC, VALS(ansi_map_SSDUpdateReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_voicePrivacyReport,
{ "voicePrivacyReport", "ansi_map.voicePrivacyReport",
FT_UINT8, BASE_DEC, VALS(ansi_map_VoicePrivacyReport_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableBaseStation,
{ "randomVariableBaseStation", "ansi_map.randomVariableBaseStation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationResponseBaseStation,
{ "authenticationResponseBaseStation", "ansi_map.authenticationResponseBaseStation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_billingID,
{ "billingID", "ansi_map.billingID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_channelData,
{ "channelData", "ansi_map.channelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSwitchCount,
{ "interSwitchCount", "ansi_map.interSwitchCount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_servingCellID,
{ "servingCellID", "ansi_map.servingCellID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_stationClassMark,
{ "stationClassMark", "ansi_map.stationClassMark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_targetCellID,
{ "targetCellID", "ansi_map.targetCellID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffReason,
{ "handoffReason", "ansi_map.handoffReason",
FT_UINT32, BASE_DEC, VALS(ansi_map_HandoffReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffState,
{ "handoffState", "ansi_map.handoffState",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaBurstIndicator,
{ "tdmaBurstIndicator", "ansi_map.tdmaBurstIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaCallMode,
{ "tdmaCallMode", "ansi_map.tdmaCallMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaChannelData,
{ "tdmaChannelData", "ansi_map.tdmaChannelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_baseStationManufacturerCode,
{ "baseStationManufacturerCode", "ansi_map.baseStationManufacturerCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_alertCode,
{ "alertCode", "ansi_map.alertCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdma2000HandoffInvokeIOSData,
{ "cdma2000HandoffInvokeIOSData", "ansi_map.cdma2000HandoffInvokeIOSData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaBandClassList,
{ "cdmaBandClassList", "ansi_map.cdmaBandClassList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaCallMode,
{ "cdmaCallMode", "ansi_map.cdmaCallMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaChannelData,
{ "cdmaChannelData", "ansi_map.cdmaChannelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaConnectionReferenceList,
{ "cdmaConnectionReferenceList", "ansi_map.cdmaConnectionReferenceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaMobileProtocolRevision,
{ "cdmaMobileProtocolRevision", "ansi_map.cdmaMobileProtocolRevision",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaMSMeasuredChannelIdentity,
{ "cdmaMSMeasuredChannelIdentity", "ansi_map.cdmaMSMeasuredChannelIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServiceConfigurationRecord,
{ "cdmaServiceConfigurationRecord", "ansi_map.cdmaServiceConfigurationRecord",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServiceOptionList,
{ "cdmaServiceOptionList", "ansi_map.cdmaServiceOptionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServingOneWayDelay,
{ "cdmaServingOneWayDelay", "ansi_map.cdmaServingOneWayDelay",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaStationClassMark,
{ "cdmaStationClassMark", "ansi_map.cdmaStationClassMark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaStationClassMark2,
{ "cdmaStationClassMark2", "ansi_map.cdmaStationClassMark2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaTargetMAHOList,
{ "cdmaTargetMAHOList", "ansi_map.cdmaTargetMAHOList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaTargetMeasurementList,
{ "cdmaTargetMeasurementList", "ansi_map.cdmaTargetMeasurementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataPrivacyParameters,
{ "dataPrivacyParameters", "ansi_map.dataPrivacyParameters",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_ilspInformation,
{ "ilspInformation", "ansi_map.ilspInformation",
FT_UINT8, BASE_DEC, VALS(ansi_map_islp_type_vals), 0,
"ISLPInformation", HFILL }},
{ &hf_ansi_map_msLocation,
{ "msLocation", "ansi_map.msLocation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_nampsCallMode,
{ "nampsCallMode", "ansi_map.nampsCallMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_nampsChannelData,
{ "nampsChannelData", "ansi_map.nampsChannelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_nonPublicData,
{ "nonPublicData", "ansi_map.nonPublicData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pdsnAddress,
{ "pdsnAddress", "ansi_map.pdsnAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pdsnProtocolType,
{ "pdsnProtocolType", "ansi_map.pdsnProtocolType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qosPriority,
{ "qosPriority", "ansi_map.qosPriority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_systemOperatorCode,
{ "systemOperatorCode", "ansi_map.systemOperatorCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaBandwidth,
{ "tdmaBandwidth", "ansi_map.tdmaBandwidth",
FT_UINT8, BASE_DEC, VALS(ansi_map_TDMABandwidth_vals), 0x0f,
NULL, HFILL }},
{ &hf_ansi_map_tdmaServiceCode,
{ "tdmaServiceCode", "ansi_map.tdmaServiceCode",
FT_UINT8, BASE_DEC, VALS(ansi_map_TDMAServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaTerminalCapability,
{ "tdmaTerminalCapability", "ansi_map.tdmaTerminalCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaVoiceCoder,
{ "tdmaVoiceCoder", "ansi_map.tdmaVoiceCoder",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_userZoneData,
{ "userZoneData", "ansi_map.userZoneData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_bsmcstatus,
{ "bsmcstatus", "ansi_map.bsmcstatus",
FT_UINT8, BASE_DEC, VALS(ansi_map_BSMCStatus_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_cdma2000HandoffResponseIOSData,
{ "cdma2000HandoffResponseIOSData", "ansi_map.cdma2000HandoffResponseIOSData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaCodeChannelList,
{ "cdmaCodeChannelList", "ansi_map.cdmaCodeChannelList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaSearchParameters,
{ "cdmaSearchParameters", "ansi_map.cdmaSearchParameters",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaSearchWindow,
{ "cdmaSearchWindow", "ansi_map.cdmaSearchWindow",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sOCStatus,
{ "sOCStatus", "ansi_map.sOCStatus",
FT_UINT8, BASE_DEC, VALS(ansi_map_SOCStatus_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_releaseReason,
{ "releaseReason", "ansi_map.releaseReason",
FT_UINT32, BASE_DEC, VALS(ansi_map_ReleaseReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_acgencountered,
{ "acgencountered", "ansi_map.acgencountered",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyName,
{ "callingPartyName", "ansi_map.callingPartyName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyNumberDigits1,
{ "callingPartyNumberDigits1", "ansi_map.callingPartyNumberDigits1",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyNumberDigits2,
{ "callingPartyNumberDigits2", "ansi_map.callingPartyNumberDigits2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartySubaddress,
{ "callingPartySubaddress", "ansi_map.callingPartySubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_conferenceCallingIndicator,
{ "conferenceCallingIndicator", "ansi_map.conferenceCallingIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobileDirectoryNumber,
{ "mobileDirectoryNumber", "ansi_map.mobileDirectoryNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mSCIdentificationNumber,
{ "mSCIdentificationNumber", "ansi_map.mSCIdentificationNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oneTimeFeatureIndicator,
{ "oneTimeFeatureIndicator", "ansi_map.oneTimeFeatureIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_systemMyTypeCode,
{ "systemMyTypeCode", "ansi_map.systemMyTypeCode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_SystemMyTypeCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_featureResult,
{ "featureResult", "ansi_map.featureResult",
FT_UINT32, BASE_DEC, VALS(ansi_map_FeatureResult_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_accessDeniedReason,
{ "accessDeniedReason", "ansi_map.accessDeniedReason",
FT_UINT32, BASE_DEC, VALS(ansi_map_AccessDeniedReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_actionCode,
{ "actionCode", "ansi_map.actionCode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING|BASE_EXT_STRING, &ansi_map_ActionCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_announcementList,
{ "announcementList", "ansi_map.announcementList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyNumberString1,
{ "callingPartyNumberString1", "ansi_map.callingPartyNumberString1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyNumberString2,
{ "callingPartyNumberString2", "ansi_map.callingPartyNumberString2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_digits_Destination,
{ "digits-Destination", "ansi_map.digits_Destination_element",
FT_NONE, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_ansi_map_displayText,
{ "displayText", "ansi_map.displayText",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_displayText2,
{ "displayText2", "ansi_map.displayText2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dmh_AccountCodeDigits,
{ "dmh-AccountCodeDigits", "ansi_map.dmh_AccountCodeDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dmh_AlternateBillingDigits,
{ "dmh-AlternateBillingDigits", "ansi_map.dmh_AlternateBillingDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dmh_BillingDigits,
{ "dmh-BillingDigits", "ansi_map.dmh_BillingDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dmh_RedirectionIndicator,
{ "dmh-RedirectionIndicator", "ansi_map.dmh_RedirectionIndicator",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_DMH_RedirectionIndicator_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_groupInformation,
{ "groupInformation", "ansi_map.groupInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_noAnswerTime,
{ "noAnswerTime", "ansi_map.noAnswerTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pACAIndicator,
{ "pACAIndicator", "ansi_map.pACAIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pilotNumber,
{ "pilotNumber", "ansi_map.pilotNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_preferredLanguageIndicator,
{ "preferredLanguageIndicator", "ansi_map.preferredLanguageIndicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_PreferredLanguageIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectingNumberDigits,
{ "redirectingNumberDigits", "ansi_map.redirectingNumberDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectingNumberString,
{ "redirectingNumberString", "ansi_map.redirectingNumberString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectingSubaddress,
{ "redirectingSubaddress", "ansi_map.redirectingSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_resumePIC,
{ "resumePIC", "ansi_map.resumePIC",
FT_UINT32, BASE_DEC, VALS(ansi_map_ResumePIC_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_terminationList,
{ "terminationList", "ansi_map.terminationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_terminationTriggers,
{ "terminationTriggers", "ansi_map.terminationTriggers",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_triggerAddressList,
{ "triggerAddressList", "ansi_map.triggerAddressList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_emergencyServicesRoutingDigits,
{ "emergencyServicesRoutingDigits", "ansi_map.emergencyServicesRoutingDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_targetCellIDList,
{ "targetCellIDList", "ansi_map.targetCellIDList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_signalQuality,
{ "signalQuality", "ansi_map.signalQuality",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_SignalQuality_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_targetMeasurementList,
{ "targetMeasurementList", "ansi_map.targetMeasurementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_alertResult,
{ "alertResult", "ansi_map.alertResult",
FT_UINT8, BASE_DEC, VALS(ansi_map_AlertResult_result_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_messageWaitingNotificationCount,
{ "messageWaitingNotificationCount", "ansi_map.messageWaitingNotificationCount",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_messageWaitingNotificationType,
{ "messageWaitingNotificationType", "ansi_map.messageWaitingNotificationType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaBandClass,
{ "cdmaBandClass", "ansi_map.cdmaBandClass",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServiceOption,
{ "cdmaServiceOption", "ansi_map.cdmaServiceOption",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaSlotCycleIndex,
{ "cdmaSlotCycleIndex", "ansi_map.cdmaSlotCycleIndex",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_extendedMSCID,
{ "extendedMSCID", "ansi_map.extendedMSCID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_extendedSystemMyTypeCode,
{ "extendedSystemMyTypeCode", "ansi_map.extendedSystemMyTypeCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_imsi,
{ "imsi", "ansi_map.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_legInformation,
{ "legInformation", "ansi_map.legInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mSIDUsage,
{ "mSIDUsage", "ansi_map.mSIDUsage",
FT_UINT8, BASE_DEC, VALS(ansi_MSIDUsage_m_or_i_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_networkTMSI,
{ "networkTMSI", "ansi_map.networkTMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pageCount,
{ "pageCount", "ansi_map.pageCount",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pageIndicator,
{ "pageIndicator", "ansi_map.pageIndicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_PageIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_pageResponseTime,
{ "pageResponseTime", "ansi_map.pageResponseTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pilotBillingID,
{ "pilotBillingID", "ansi_map.pilotBillingID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectingPartyName,
{ "redirectingPartyName", "ansi_map.redirectingPartyName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaDataFeaturesIndicator,
{ "tdmaDataFeaturesIndicator", "ansi_map.tdmaDataFeaturesIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_terminationTreatment,
{ "terminationTreatment", "ansi_map.terminationTreatment",
FT_UINT8, BASE_DEC, VALS(ansi_map_TerminationTreatment_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_conditionallyDeniedReason,
{ "conditionallyDeniedReason", "ansi_map.conditionallyDeniedReason",
FT_UINT32, BASE_DEC, VALS(ansi_map_ConditionallyDeniedReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_pagingFrameClass,
{ "pagingFrameClass", "ansi_map.pagingFrameClass",
FT_UINT8, BASE_DEC, VALS(ansi_map_PagingFrameClass_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_pSID_RSIDList,
{ "pSID-RSIDList", "ansi_map.pSID_RSIDList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randc,
{ "randc", "ansi_map.randc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaDataMode,
{ "tdmaDataMode", "ansi_map.tdmaDataMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_changeServiceAttributes,
{ "changeServiceAttributes", "ansi_map.changeServiceAttributes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_edirectingSubaddress,
{ "edirectingSubaddress", "ansi_map.edirectingSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"RedirectingSubaddress", HFILL }},
{ &hf_ansi_map_setupResult,
{ "setupResult", "ansi_map.setupResult",
FT_UINT8, BASE_DEC, VALS(ansi_map_SetupResult_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_terminationAccessType,
{ "terminationAccessType", "ansi_map.terminationAccessType",
FT_UINT8, BASE_DEC, VALS(ansi_map_TerminationAccessType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_triggerType,
{ "triggerType", "ansi_map.triggerType",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_TriggerType_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_winCapability,
{ "winCapability", "ansi_map.winCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callingPartyCategory,
{ "callingPartyCategory", "ansi_map.callingPartyCategory",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_controlNetworkID,
{ "controlNetworkID", "ansi_map.controlNetworkID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_digits_carrier,
{ "digits-carrier", "ansi_map.digits_carrier_element",
FT_NONE, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_ansi_map_digits_dest,
{ "digits-dest", "ansi_map.digits_dest_element",
FT_NONE, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_ansi_map_dmh_ServiceID,
{ "dmh-ServiceID", "ansi_map.dmh_ServiceID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lectronicSerialNumber,
{ "lectronicSerialNumber", "ansi_map.lectronicSerialNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ElectronicSerialNumber", HFILL }},
{ &hf_ansi_map_deregistrationType,
{ "deregistrationType", "ansi_map.deregistrationType",
FT_UINT32, BASE_DEC, VALS(ansi_map_DeregistrationType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_servicesResult,
{ "servicesResult", "ansi_map.servicesResult",
FT_UINT8, BASE_DEC, VALS(ansi_map_ServicesResult_ppr_vals), 0x03,
NULL, HFILL }},
{ &hf_ansi_map_sms_MessageWaitingIndicator,
{ "sms-MessageWaitingIndicator", "ansi_map.sms_MessageWaitingIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_originationTriggers,
{ "originationTriggers", "ansi_map.originationTriggers",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_featureIndicator,
{ "featureIndicator", "ansi_map.featureIndicator",
FT_UINT32, BASE_DEC, VALS(ansi_map_FeatureIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_dmh_ChargeInformation,
{ "dmh-ChargeInformation", "ansi_map.dmh_ChargeInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationInformationCode,
{ "qualificationInformationCode", "ansi_map.qualificationInformationCode",
FT_UINT32, BASE_DEC, VALS(ansi_map_QualificationInformationCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_authorizationDenied,
{ "authorizationDenied", "ansi_map.authorizationDenied",
FT_UINT32, BASE_DEC, VALS(ansi_map_AuthorizationDenied_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_authorizationPeriod,
{ "authorizationPeriod", "ansi_map.authorizationPeriod",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_deniedAuthorizationPeriod,
{ "deniedAuthorizationPeriod", "ansi_map.deniedAuthorizationPeriod",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationCapability,
{ "authenticationCapability", "ansi_map.authenticationCapability",
FT_UINT8, BASE_DEC, VALS(ansi_map_AuthenticationCapability_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_callingFeaturesIndicator,
{ "callingFeaturesIndicator", "ansi_map.callingFeaturesIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_geographicAuthorization,
{ "geographicAuthorization", "ansi_map.geographicAuthorization",
FT_UINT8, BASE_DEC, VALS(ansi_map_GeographicAuthorization_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_meidValidated,
{ "meidValidated", "ansi_map.meidValidated_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobilePositionCapability,
{ "mobilePositionCapability", "ansi_map.mobilePositionCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_originationIndicator,
{ "originationIndicator", "ansi_map.originationIndicator",
FT_UINT32, BASE_DEC, VALS(ansi_map_OriginationIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_restrictionDigits,
{ "restrictionDigits", "ansi_map.restrictionDigits",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginationRestrictions,
{ "sms-OriginationRestrictions", "ansi_map.sms_OriginationRestrictions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_TerminationRestrictions,
{ "sms-TerminationRestrictions", "ansi_map.sms_TerminationRestrictions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_spinipin,
{ "spinipin", "ansi_map.spinipin",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_spiniTriggers,
{ "spiniTriggers", "ansi_map.spiniTriggers",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_terminationRestrictionCode,
{ "terminationRestrictionCode", "ansi_map.terminationRestrictionCode",
FT_UINT32, BASE_DEC, VALS(ansi_map_TerminationRestrictionCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_userGroup,
{ "userGroup", "ansi_map.userGroup",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lirMode,
{ "lirMode", "ansi_map.lirMode",
FT_UINT32, BASE_DEC, VALS(ansi_map_LIRMode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_randValidTime,
{ "randValidTime", "ansi_map.randValidTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectionReason,
{ "redirectionReason", "ansi_map.redirectionReason",
FT_UINT32, BASE_DEC, VALS(ansi_map_RedirectionReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_cancellationType,
{ "cancellationType", "ansi_map.cancellationType",
FT_UINT8, BASE_DEC, VALS(ansi_map_CancellationType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_controlChannelData,
{ "controlChannelData", "ansi_map.controlChannelData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_receivedSignalQuality,
{ "receivedSignalQuality", "ansi_map.receivedSignalQuality",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_systemAccessData,
{ "systemAccessData", "ansi_map.systemAccessData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cancellationDenied,
{ "cancellationDenied", "ansi_map.cancellationDenied",
FT_UINT32, BASE_DEC, VALS(ansi_map_CancellationDenied_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_availabilityType,
{ "availabilityType", "ansi_map.availabilityType",
FT_UINT8, BASE_DEC, VALS(ansi_map_AvailabilityType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_borderCellAccess,
{ "borderCellAccess", "ansi_map.borderCellAccess",
FT_UINT32, BASE_DEC, VALS(ansi_map_BorderCellAccess_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_msc_Address,
{ "msc-Address", "ansi_map.msc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_Address,
{ "sms-Address", "ansi_map.sms_Address_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mpcAddress,
{ "mpcAddress", "ansi_map.mpcAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mpcAddressList,
{ "mpcAddressList", "ansi_map.mpcAddressList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_digits_Carrier,
{ "digits-Carrier", "ansi_map.digits_Carrier_element",
FT_NONE, BASE_NONE, NULL, 0,
"Digits", HFILL }},
{ &hf_ansi_map_digitCollectionControl,
{ "digitCollectionControl", "ansi_map.digitCollectionControl",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_trunkStatus,
{ "trunkStatus", "ansi_map.trunkStatus",
FT_UINT32, BASE_DEC, VALS(ansi_map_TrunkStatus_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_voiceMailboxNumber,
{ "voiceMailboxNumber", "ansi_map.voiceMailboxNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_voiceMailboxPIN,
{ "voiceMailboxPIN", "ansi_map.voiceMailboxPIN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_BearerData,
{ "sms-BearerData", "ansi_map.sms_BearerData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_TeleserviceIdentifier,
{ "sms-TeleserviceIdentifier", "ansi_map.sms_TeleserviceIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_ChargeIndicator,
{ "sms-ChargeIndicator", "ansi_map.sms_ChargeIndicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_ChargeIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_DestinationAddress,
{ "sms-DestinationAddress", "ansi_map.sms_DestinationAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginalDestinationAddress,
{ "sms-OriginalDestinationAddress", "ansi_map.sms_OriginalDestinationAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginalDestinationSubaddress,
{ "sms-OriginalDestinationSubaddress", "ansi_map.sms_OriginalDestinationSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginalOriginatingAddress,
{ "sms-OriginalOriginatingAddress", "ansi_map.sms_OriginalOriginatingAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginalOriginatingSubaddress,
{ "sms-OriginalOriginatingSubaddress", "ansi_map.sms_OriginalOriginatingSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_OriginatingAddress,
{ "sms-OriginatingAddress", "ansi_map.sms_OriginatingAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_CauseCode,
{ "sms-CauseCode", "ansi_map.sms_CauseCode",
FT_UINT8, BASE_DEC|BASE_EXT_STRING|BASE_EXT_STRING, &ansi_map_SMS_CauseCode_vals_ext, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServingOneWayDelay2,
{ "cdmaServingOneWayDelay2", "ansi_map.cdmaServingOneWayDelay2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interMessageTime,
{ "interMessageTime", "ansi_map.interMessageTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_newlyAssignedIMSI,
{ "newlyAssignedIMSI", "ansi_map.newlyAssignedIMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_newlyAssignedMIN,
{ "newlyAssignedMIN", "ansi_map.newlyAssignedMIN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_newMINExtension,
{ "newMINExtension", "ansi_map.newMINExtension",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_MessageCount,
{ "sms-MessageCount", "ansi_map.sms_MessageCount",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_NotificationIndicator,
{ "sms-NotificationIndicator", "ansi_map.sms_NotificationIndicator",
FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_NotificationIndicator_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_teleservice_Priority,
{ "teleservice-Priority", "ansi_map.teleservice_Priority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_temporaryReferenceNumber,
{ "temporaryReferenceNumber", "ansi_map.temporaryReferenceNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobileStationMSID,
{ "mobileStationMSID", "ansi_map.mobileStationMSID",
FT_UINT32, BASE_DEC, VALS(ansi_map_MobileStationMSID_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_TransactionID,
{ "sms-TransactionID", "ansi_map.sms_TransactionID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sms_AccessDeniedReason,
{ "sms-AccessDeniedReason", "ansi_map.sms_AccessDeniedReason",
FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_AccessDeniedReason_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_seizureType,
{ "seizureType", "ansi_map.seizureType",
FT_UINT32, BASE_DEC, VALS(ansi_map_SeizureType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_requiredParametersMask,
{ "requiredParametersMask", "ansi_map.requiredParametersMask",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_reasonList,
{ "reasonList", "ansi_map.reasonList",
FT_UINT32, BASE_DEC, VALS(ansi_map_ReasonList_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_networkTMSIExpirationTime,
{ "networkTMSIExpirationTime", "ansi_map.networkTMSIExpirationTime",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_newNetworkTMSI,
{ "newNetworkTMSI", "ansi_map.newNetworkTMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceID,
{ "serviceID", "ansi_map.serviceID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataAccessElementList,
{ "dataAccessElementList", "ansi_map.dataAccessElementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_timeDateOffset,
{ "timeDateOffset", "ansi_map.timeDateOffset",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_timeOfDay,
{ "timeOfDay", "ansi_map.timeOfDay",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dmd_BillingIndicator,
{ "dmd-BillingIndicator", "ansi_map.dmd_BillingIndicator",
FT_UINT32, BASE_DEC, VALS(ansi_map_DMH_BillingIndicator_vals), 0,
"DMH_BillingIndicator", HFILL }},
{ &hf_ansi_map_failureType,
{ "failureType", "ansi_map.failureType",
FT_UINT32, BASE_DEC, VALS(ansi_map_FailureType_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_failureCause,
{ "failureCause", "ansi_map.failureCause",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_outingDigits,
{ "outingDigits", "ansi_map.outingDigits",
FT_BYTES, BASE_NONE, NULL, 0,
"RoutingDigits", HFILL }},
{ &hf_ansi_map_databaseKey,
{ "databaseKey", "ansi_map.databaseKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_modificationRequestList,
{ "modificationRequestList", "ansi_map.modificationRequestList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_modificationResultList,
{ "modificationResultList", "ansi_map.modificationResultList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceDataAccessElementList,
{ "serviceDataAccessElementList", "ansi_map.serviceDataAccessElementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_privateSpecializedResource,
{ "privateSpecializedResource", "ansi_map.privateSpecializedResource",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_specializedResource,
{ "specializedResource", "ansi_map.specializedResource",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_executeScript,
{ "executeScript", "ansi_map.executeScript_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_scriptResult,
{ "scriptResult", "ansi_map.scriptResult",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdmaVoiceMode,
{ "tdmaVoiceMode", "ansi_map.tdmaVoiceMode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callStatus,
{ "callStatus", "ansi_map.callStatus",
FT_UINT32, BASE_DEC, VALS(ansi_map_CallStatus_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_releaseCause,
{ "releaseCause", "ansi_map.releaseCause",
FT_UINT32, BASE_DEC, VALS(ansi_map_ReleaseCause_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_callRecoveryIDList,
{ "callRecoveryIDList", "ansi_map.callRecoveryIDList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionInformationCode,
{ "positionInformationCode", "ansi_map.positionInformationCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mSStatus,
{ "mSStatus", "ansi_map.mSStatus",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pSID_RSIDInformation,
{ "pSID-RSIDInformation", "ansi_map.pSID_RSIDInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionRequestType,
{ "positionRequestType", "ansi_map.positionRequestType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lcsBillingID,
{ "lcsBillingID", "ansi_map.lcsBillingID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lcs_Client_ID,
{ "lcs-Client-ID", "ansi_map.lcs_Client_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dtxIndication,
{ "dtxIndication", "ansi_map.dtxIndication",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaCodeChannel,
{ "cdmaCodeChannel", "ansi_map.cdmaCodeChannel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaMobileCapabilities,
{ "cdmaMobileCapabilities", "ansi_map.cdmaMobileCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaPSMMList,
{ "cdmaPSMMList", "ansi_map.cdmaPSMMList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdma_MAHO_CELLID,
{ "tdma-MAHO-CELLID", "ansi_map.tdma_MAHO_CELLID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdma_MAHO_CHANNEL,
{ "tdma-MAHO-CHANNEL", "ansi_map.tdma_MAHO_CHANNEL",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdma_TimeAlignment,
{ "tdma-TimeAlignment", "ansi_map.tdma_TimeAlignment",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_HorizontalPosition,
{ "pqos-HorizontalPosition", "ansi_map.pqos_HorizontalPosition",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_HorizontalVelocity,
{ "pqos-HorizontalVelocity", "ansi_map.pqos_HorizontalVelocity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_MaximumPositionAge,
{ "pqos-MaximumPositionAge", "ansi_map.pqos_MaximumPositionAge",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_PositionPriority,
{ "pqos-PositionPriority", "ansi_map.pqos_PositionPriority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_ResponseTime,
{ "pqos-ResponseTime", "ansi_map.pqos_ResponseTime",
FT_UINT32, BASE_DEC, VALS(ansi_map_PQOS_ResponseTime_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_VerticalPosition,
{ "pqos-VerticalPosition", "ansi_map.pqos_VerticalPosition",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pqos_VerticalVelocity,
{ "pqos-VerticalVelocity", "ansi_map.pqos_VerticalVelocity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaPSMMCount,
{ "cdmaPSMMCount", "ansi_map.cdmaPSMMCount",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lirAuthorization,
{ "lirAuthorization", "ansi_map.lirAuthorization",
FT_UINT32, BASE_DEC, VALS(ansi_map_LIRAuthorization_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_mpcid,
{ "mpcid", "ansi_map.mpcid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tdma_MAHORequest,
{ "tdma-MAHORequest", "ansi_map.tdma_MAHORequest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionResult,
{ "positionResult", "ansi_map.positionResult",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionInformation,
{ "positionInformation", "ansi_map.positionInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_controlType,
{ "controlType", "ansi_map.controlType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_destinationAddress,
{ "destinationAddress", "ansi_map.destinationAddress",
FT_UINT32, BASE_DEC, VALS(ansi_map_DestinationAddress_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_gapDuration,
{ "gapDuration", "ansi_map.gapDuration",
FT_UINT32, BASE_DEC, VALS(ansi_map_GapDuration_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_gapInterval,
{ "gapInterval", "ansi_map.gapInterval",
FT_UINT32, BASE_DEC, VALS(ansi_map_GapInterval_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_invokingNEType,
{ "invokingNEType", "ansi_map.invokingNEType",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_range,
{ "range", "ansi_map.range",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_meidStatus,
{ "meidStatus", "ansi_map.meidStatus",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_aKeyProtocolVersion,
{ "aKeyProtocolVersion", "ansi_map.aKeyProtocolVersion",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mobileStationPartialKey,
{ "mobileStationPartialKey", "ansi_map.mobileStationPartialKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_newlyAssignedMSID,
{ "newlyAssignedMSID", "ansi_map.newlyAssignedMSID",
FT_UINT32, BASE_DEC, VALS(ansi_map_NewlyAssignedMSID_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_baseStationPartialKey,
{ "baseStationPartialKey", "ansi_map.baseStationPartialKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_modulusValue,
{ "modulusValue", "ansi_map.modulusValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_otasp_ResultCode,
{ "otasp-ResultCode", "ansi_map.otasp_ResultCode",
FT_UINT8, BASE_DEC, VALS(ansi_map_OTASP_ResultCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_primitiveValue,
{ "primitiveValue", "ansi_map.primitiveValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_record_Type,
{ "record-Type", "ansi_map.record_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_information_Record,
{ "information-Record", "ansi_map.information_Record",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdma2000MobileSupportedCapabilities,
{ "cdma2000MobileSupportedCapabilities", "ansi_map.cdma2000MobileSupportedCapabilities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_announcementCode1,
{ "announcementCode1", "ansi_map.announcementCode1",
FT_BYTES, BASE_NONE, NULL, 0,
"AnnouncementCode", HFILL }},
{ &hf_ansi_map_announcementCode2,
{ "announcementCode2", "ansi_map.announcementCode2",
FT_BYTES, BASE_NONE, NULL, 0,
"AnnouncementCode", HFILL }},
{ &hf_ansi_map_cdmaPilotPN,
{ "cdmaPilotPN", "ansi_map.cdmaPilotPN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaPowerCombinedIndicator,
{ "cdmaPowerCombinedIndicator", "ansi_map.cdmaPowerCombinedIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMACodeChannelList_item,
{ "CDMACodeChannelInformation", "ansi_map.CDMACodeChannelInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaPilotStrength,
{ "cdmaPilotStrength", "ansi_map.cdmaPilotStrength",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaTargetOneWayDelay,
{ "cdmaTargetOneWayDelay", "ansi_map.cdmaTargetOneWayDelay",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMATargetMAHOList_item,
{ "CDMATargetMAHOInformation", "ansi_map.CDMATargetMAHOInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaSignalQuality,
{ "cdmaSignalQuality", "ansi_map.cdmaSignalQuality",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMATargetMeasurementList_item,
{ "CDMATargetMeasurementInformation", "ansi_map.CDMATargetMeasurementInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_TargetMeasurementList_item,
{ "TargetMeasurementInformation", "ansi_map.TargetMeasurementInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_TerminationList_item,
{ "TerminationList item", "ansi_map.TerminationList_item",
FT_UINT32, BASE_DEC, VALS(ansi_map_TerminationList_item_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_intersystemTermination,
{ "intersystemTermination", "ansi_map.intersystemTermination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_localTermination,
{ "localTermination", "ansi_map.localTermination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pstnTermination,
{ "pstnTermination", "ansi_map.pstnTermination_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMABandClassList_item,
{ "CDMABandClassInformation", "ansi_map.CDMABandClassInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMAServiceOptionList_item,
{ "CDMAServiceOption", "ansi_map.CDMAServiceOption",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pSID_RSIDInformation1,
{ "pSID-RSIDInformation1", "ansi_map.pSID_RSIDInformation1",
FT_BYTES, BASE_NONE, NULL, 0,
"PSID_RSIDInformation", HFILL }},
{ &hf_ansi_map_targetCellID1,
{ "targetCellID1", "ansi_map.targetCellID1",
FT_BYTES, BASE_NONE, NULL, 0,
"TargetCellID", HFILL }},
{ &hf_ansi_map_cdmaConnectionReference,
{ "cdmaConnectionReference", "ansi_map.cdmaConnectionReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaState,
{ "cdmaState", "ansi_map.cdmaState",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaServiceOptionConnectionIdentifier,
{ "cdmaServiceOptionConnectionIdentifier", "ansi_map.cdmaServiceOptionConnectionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMAConnectionReferenceList_item,
{ "CDMAConnectionReferenceList item", "ansi_map.CDMAConnectionReferenceList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaConnectionReferenceInformation,
{ "cdmaConnectionReferenceInformation", "ansi_map.cdmaConnectionReferenceInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaConnectionReferenceInformation2,
{ "cdmaConnectionReferenceInformation2", "ansi_map.cdmaConnectionReferenceInformation2_element",
FT_NONE, BASE_NONE, NULL, 0,
"CDMAConnectionReferenceInformation", HFILL }},
{ &hf_ansi_map_analogRedirectInfo,
{ "analogRedirectInfo", "ansi_map.analogRedirectInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMAChannelNumberList_item,
{ "CDMAChannelNumberList item", "ansi_map.CDMAChannelNumberList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaChannelNumber,
{ "cdmaChannelNumber", "ansi_map.cdmaChannelNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaChannelNumber2,
{ "cdmaChannelNumber2", "ansi_map.cdmaChannelNumber2",
FT_BYTES, BASE_NONE, NULL, 0,
"CDMAChannelNumber", HFILL }},
{ &hf_ansi_map_cdmaChannelNumberList,
{ "cdmaChannelNumberList", "ansi_map.cdmaChannelNumberList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataID,
{ "dataID", "ansi_map.dataID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_change,
{ "change", "ansi_map.change",
FT_UINT32, BASE_DEC, VALS(ansi_map_Change_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_dataValue,
{ "dataValue", "ansi_map.dataValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_DataAccessElementList_item,
{ "DataAccessElementList item", "ansi_map.DataAccessElementList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataAccessElement1,
{ "dataAccessElement1", "ansi_map.dataAccessElement1_element",
FT_NONE, BASE_NONE, NULL, 0,
"DataAccessElement", HFILL }},
{ &hf_ansi_map_dataAccessElement2,
{ "dataAccessElement2", "ansi_map.dataAccessElement2_element",
FT_NONE, BASE_NONE, NULL, 0,
"DataAccessElement", HFILL }},
{ &hf_ansi_map_dataResult,
{ "dataResult", "ansi_map.dataResult",
FT_UINT32, BASE_DEC, VALS(ansi_map_DataResult_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_DataUpdateResultList_item,
{ "DataUpdateResult", "ansi_map.DataUpdateResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_globalTitle,
{ "globalTitle", "ansi_map.globalTitle",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_pC_SSN,
{ "pC-SSN", "ansi_map.pC_SSN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_scriptName,
{ "scriptName", "ansi_map.scriptName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_scriptArgument,
{ "scriptArgument", "ansi_map.scriptArgument",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_allOrNone,
{ "allOrNone", "ansi_map.allOrNone",
FT_UINT32, BASE_DEC, VALS(ansi_map_AllOrNone_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_ModificationRequestList_item,
{ "ModificationRequest", "ansi_map.ModificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceDataResultList,
{ "serviceDataResultList", "ansi_map.serviceDataResultList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_ModificationResultList_item,
{ "ModificationResult", "ansi_map.ModificationResult",
FT_UINT32, BASE_DEC, VALS(ansi_map_ModificationResult_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_ServiceDataAccessElementList_item,
{ "ServiceDataAccessElement", "ansi_map.ServiceDataAccessElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dataUpdateResultList,
{ "dataUpdateResultList", "ansi_map.dataUpdateResultList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_ServiceDataResultList_item,
{ "ServiceDataResult", "ansi_map.ServiceDataResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_triggerList,
{ "triggerList", "ansi_map.triggerList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_triggerListOpt,
{ "triggerListOpt", "ansi_map.triggerListOpt_element",
FT_NONE, BASE_NONE, NULL, 0,
"TriggerList", HFILL }},
{ &hf_ansi_map_wIN_TriggerList,
{ "wIN-TriggerList", "ansi_map.wIN_TriggerList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_triggerCapability,
{ "triggerCapability", "ansi_map.triggerCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_wINOperationsCapability,
{ "wINOperationsCapability", "ansi_map.wINOperationsCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_CallRecoveryIDList_item,
{ "CallRecoveryID", "ansi_map.CallRecoveryID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_generalizedTime,
{ "generalizedTime", "ansi_map.generalizedTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_geographicPosition,
{ "geographicPosition", "ansi_map.geographicPosition",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionSource,
{ "positionSource", "ansi_map.positionSource",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_horizontal_Velocity,
{ "horizontal-Velocity", "ansi_map.horizontal_Velocity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_vertical_Velocity,
{ "vertical-Velocity", "ansi_map.vertical_Velocity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sCFOverloadGapInterval,
{ "sCFOverloadGapInterval", "ansi_map.sCFOverloadGapInterval",
FT_UINT32, BASE_DEC, VALS(ansi_map_SCFOverloadGapInterval_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceManagementSystemGapInterval,
{ "serviceManagementSystemGapInterval", "ansi_map.serviceManagementSystemGapInterval",
FT_UINT32, BASE_DEC, VALS(ansi_map_ServiceManagementSystemGapInterval_vals), 0,
NULL, HFILL }},
{ &hf_ansi_map_CDMAPSMMList_item,
{ "CDMAPSMMList item", "ansi_map.CDMAPSMMList_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_cdmaTargetMAHOList2,
{ "cdmaTargetMAHOList2", "ansi_map.cdmaTargetMAHOList2",
FT_UINT32, BASE_DEC, NULL, 0,
"CDMATargetMAHOList", HFILL }},
{ &hf_ansi_map_mpcAddress2,
{ "mpcAddress2", "ansi_map.mpcAddress2",
FT_BYTES, BASE_NONE, NULL, 0,
"MPCAddress", HFILL }},
{ &hf_ansi_map_mobileStationIMSI,
{ "mobileStationIMSI", "ansi_map.mobileStationIMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffMeasurementRequest,
{ "handoffMeasurementRequest", "ansi_map.handoffMeasurementRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesDirective,
{ "facilitiesDirective", "ansi_map.facilitiesDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffBack,
{ "handoffBack", "ansi_map.handoffBack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesRelease,
{ "facilitiesRelease", "ansi_map.facilitiesRelease_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationRequest,
{ "qualificationRequest", "ansi_map.qualificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationDirective,
{ "qualificationDirective", "ansi_map.qualificationDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_blocking,
{ "blocking", "ansi_map.blocking_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_unblocking,
{ "unblocking", "ansi_map.unblocking_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_resetCircuit,
{ "resetCircuit", "ansi_map.resetCircuit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_trunkTest,
{ "trunkTest", "ansi_map.trunkTest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_trunkTestDisconnect,
{ "trunkTestDisconnect", "ansi_map.trunkTestDisconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_registrationNotification,
{ "registrationNotification", "ansi_map.registrationNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_registrationCancellation,
{ "registrationCancellation", "ansi_map.registrationCancellation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_locationRequest,
{ "locationRequest", "ansi_map.locationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_routingRequest,
{ "routingRequest", "ansi_map.routingRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_featureRequest,
{ "featureRequest", "ansi_map.featureRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_unreliableRoamerDataDirective,
{ "unreliableRoamerDataDirective", "ansi_map.unreliableRoamerDataDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_mSInactive,
{ "mSInactive", "ansi_map.mSInactive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_transferToNumberRequest,
{ "transferToNumberRequest", "ansi_map.transferToNumberRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectionRequest,
{ "redirectionRequest", "ansi_map.redirectionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffToThird,
{ "handoffToThird", "ansi_map.handoffToThird_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_flashRequest,
{ "flashRequest", "ansi_map.flashRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationDirective,
{ "authenticationDirective", "ansi_map.authenticationDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationRequest,
{ "authenticationRequest", "ansi_map.authenticationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_baseStationChallenge,
{ "baseStationChallenge", "ansi_map.baseStationChallenge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationFailureReport,
{ "authenticationFailureReport", "ansi_map.authenticationFailureReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_countRequest,
{ "countRequest", "ansi_map.countRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPage,
{ "interSystemPage", "ansi_map.interSystemPage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_unsolicitedResponse,
{ "unsolicitedResponse", "ansi_map.unsolicitedResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_bulkDeregistration,
{ "bulkDeregistration", "ansi_map.bulkDeregistration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffMeasurementRequest2,
{ "handoffMeasurementRequest2", "ansi_map.handoffMeasurementRequest2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesDirective2,
{ "facilitiesDirective2", "ansi_map.facilitiesDirective2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffBack2,
{ "handoffBack2", "ansi_map.handoffBack2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffToThird2,
{ "handoffToThird2", "ansi_map.handoffToThird2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationDirectiveForward,
{ "authenticationDirectiveForward", "ansi_map.authenticationDirectiveForward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationStatusReport,
{ "authenticationStatusReport", "ansi_map.authenticationStatusReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_informationDirective,
{ "informationDirective", "ansi_map.informationDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_informationForward,
{ "informationForward", "ansi_map.informationForward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemAnswer,
{ "interSystemAnswer", "ansi_map.interSystemAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPage2,
{ "interSystemPage2", "ansi_map.interSystemPage2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemSetup,
{ "interSystemSetup", "ansi_map.interSystemSetup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_originationRequest,
{ "originationRequest", "ansi_map.originationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableRequest,
{ "randomVariableRequest", "ansi_map.randomVariableRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_redirectionDirective,
{ "redirectionDirective", "ansi_map.redirectionDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_remoteUserInteractionDirective,
{ "remoteUserInteractionDirective", "ansi_map.remoteUserInteractionDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryBackward,
{ "sMSDeliveryBackward", "ansi_map.sMSDeliveryBackward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryForward,
{ "sMSDeliveryForward", "ansi_map.sMSDeliveryForward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryPointToPoint,
{ "sMSDeliveryPointToPoint", "ansi_map.sMSDeliveryPointToPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSNotification,
{ "sMSNotification", "ansi_map.sMSNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSRequest,
{ "sMSRequest", "ansi_map.sMSRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oTASPRequest,
{ "oTASPRequest", "ansi_map.oTASPRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_changeFacilities,
{ "changeFacilities", "ansi_map.changeFacilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_changeService,
{ "changeService", "ansi_map.changeService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_parameterRequest,
{ "parameterRequest", "ansi_map.parameterRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tMSIDirective,
{ "tMSIDirective", "ansi_map.tMSIDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_numberPortabilityRequest,
{ "numberPortabilityRequest", "ansi_map.numberPortabilityRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceRequest,
{ "serviceRequest", "ansi_map.serviceRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_analyzedInformation,
{ "analyzedInformation", "ansi_map.analyzedInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_connectionFailureReport,
{ "connectionFailureReport", "ansi_map.connectionFailureReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_connectResource,
{ "connectResource", "ansi_map.connectResource_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitySelectedAndAvailable,
{ "facilitySelectedAndAvailable", "ansi_map.facilitySelectedAndAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_modify,
{ "modify", "ansi_map.modify_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_search,
{ "search", "ansi_map.search_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_seizeResource,
{ "seizeResource", "ansi_map.seizeResource_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sRFDirective,
{ "sRFDirective", "ansi_map.sRFDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tBusy,
{ "tBusy", "ansi_map.tBusy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tNoAnswer,
{ "tNoAnswer", "ansi_map.tNoAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_smsDeliveryPointToPointAck,
{ "smsDeliveryPointToPointAck", "ansi_map.smsDeliveryPointToPointAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_messageDirective,
{ "messageDirective", "ansi_map.messageDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_bulkDisconnection,
{ "bulkDisconnection", "ansi_map.bulkDisconnection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callControlDirective,
{ "callControlDirective", "ansi_map.callControlDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oAnswer,
{ "oAnswer", "ansi_map.oAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oDisconnect,
{ "oDisconnect", "ansi_map.oDisconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callRecoveryReport,
{ "callRecoveryReport", "ansi_map.callRecoveryReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tAnswer,
{ "tAnswer", "ansi_map.tAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tDisconnect,
{ "tDisconnect", "ansi_map.tDisconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_unreliableCallData,
{ "unreliableCallData", "ansi_map.unreliableCallData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oCalledPartyBusy,
{ "oCalledPartyBusy", "ansi_map.oCalledPartyBusy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oNoAnswer,
{ "oNoAnswer", "ansi_map.oNoAnswer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionRequest,
{ "positionRequest", "ansi_map.positionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionRequestForward,
{ "positionRequestForward", "ansi_map.positionRequestForward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callTerminationReport,
{ "callTerminationReport", "ansi_map.callTerminationReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_geoPositionRequest,
{ "geoPositionRequest", "ansi_map.geoPositionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPositionRequest,
{ "interSystemPositionRequest", "ansi_map.interSystemPositionRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPositionRequestForward,
{ "interSystemPositionRequestForward", "ansi_map.interSystemPositionRequestForward_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_aCGDirective,
{ "aCGDirective", "ansi_map.aCGDirective_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_roamerDatabaseVerificationRequest,
{ "roamerDatabaseVerificationRequest", "ansi_map.roamerDatabaseVerificationRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_addService,
{ "addService", "ansi_map.addService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dropService,
{ "dropService", "ansi_map.dropService_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lcsParameterRequest,
{ "lcsParameterRequest", "ansi_map.lcsParameterRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_checkMEID,
{ "checkMEID", "ansi_map.checkMEID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionEventNotification,
{ "positionEventNotification", "ansi_map.positionEventNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_statusRequest,
{ "statusRequest", "ansi_map.statusRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemSMSDeliveryPointToPoint,
{ "interSystemSMSDeliveryPointToPoint", "ansi_map.interSystemSMSDeliveryPointToPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationRequest2,
{ "qualificationRequest2", "ansi_map.qualificationRequest2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffMeasurementRequestRes,
{ "handoffMeasurementRequestRes", "ansi_map.handoffMeasurementRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesDirectiveRes,
{ "facilitiesDirectiveRes", "ansi_map.facilitiesDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffBackRes,
{ "handoffBackRes", "ansi_map.handoffBackRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesReleaseRes,
{ "facilitiesReleaseRes", "ansi_map.facilitiesReleaseRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationDirectiveRes,
{ "qualificationDirectiveRes", "ansi_map.qualificationDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationRequestRes,
{ "qualificationRequestRes", "ansi_map.qualificationRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_resetCircuitRes,
{ "resetCircuitRes", "ansi_map.resetCircuitRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_registrationNotificationRes,
{ "registrationNotificationRes", "ansi_map.registrationNotificationRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_registrationCancellationRes,
{ "registrationCancellationRes", "ansi_map.registrationCancellationRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_locationRequestRes,
{ "locationRequestRes", "ansi_map.locationRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_routingRequestRes,
{ "routingRequestRes", "ansi_map.routingRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_featureRequestRes,
{ "featureRequestRes", "ansi_map.featureRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_transferToNumberRequestRes,
{ "transferToNumberRequestRes", "ansi_map.transferToNumberRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffToThirdRes,
{ "handoffToThirdRes", "ansi_map.handoffToThirdRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationDirectiveRes,
{ "authenticationDirectiveRes", "ansi_map.authenticationDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationRequestRes,
{ "authenticationRequestRes", "ansi_map.authenticationRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_baseStationChallengeRes,
{ "baseStationChallengeRes", "ansi_map.baseStationChallengeRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationFailureReportRes,
{ "authenticationFailureReportRes", "ansi_map.authenticationFailureReportRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_countRequestRes,
{ "countRequestRes", "ansi_map.countRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPageRes,
{ "interSystemPageRes", "ansi_map.interSystemPageRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_unsolicitedResponseRes,
{ "unsolicitedResponseRes", "ansi_map.unsolicitedResponseRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffMeasurementRequest2Res,
{ "handoffMeasurementRequest2Res", "ansi_map.handoffMeasurementRequest2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitiesDirective2Res,
{ "facilitiesDirective2Res", "ansi_map.facilitiesDirective2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffBack2Res,
{ "handoffBack2Res", "ansi_map.handoffBack2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_handoffToThird2Res,
{ "handoffToThird2Res", "ansi_map.handoffToThird2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationDirectiveForwardRes,
{ "authenticationDirectiveForwardRes", "ansi_map.authenticationDirectiveForwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_authenticationStatusReportRes,
{ "authenticationStatusReportRes", "ansi_map.authenticationStatusReportRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_informationDirectiveRes,
{ "informationDirectiveRes", "ansi_map.informationDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_informationForwardRes,
{ "informationForwardRes", "ansi_map.informationForwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPage2Res,
{ "interSystemPage2Res", "ansi_map.interSystemPage2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemSetupRes,
{ "interSystemSetupRes", "ansi_map.interSystemSetupRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_originationRequestRes,
{ "originationRequestRes", "ansi_map.originationRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_randomVariableRequestRes,
{ "randomVariableRequestRes", "ansi_map.randomVariableRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_remoteUserInteractionDirectiveRes,
{ "remoteUserInteractionDirectiveRes", "ansi_map.remoteUserInteractionDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryBackwardRes,
{ "sMSDeliveryBackwardRes", "ansi_map.sMSDeliveryBackwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryForwardRes,
{ "sMSDeliveryForwardRes", "ansi_map.sMSDeliveryForwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSDeliveryPointToPointRes,
{ "sMSDeliveryPointToPointRes", "ansi_map.sMSDeliveryPointToPointRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSNotificationRes,
{ "sMSNotificationRes", "ansi_map.sMSNotificationRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sMSRequestRes,
{ "sMSRequestRes", "ansi_map.sMSRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oTASPRequestRes,
{ "oTASPRequestRes", "ansi_map.oTASPRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_changeFacilitiesRes,
{ "changeFacilitiesRes", "ansi_map.changeFacilitiesRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_changeServiceRes,
{ "changeServiceRes", "ansi_map.changeServiceRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_parameterRequestRes,
{ "parameterRequestRes", "ansi_map.parameterRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tMSIDirectiveRes,
{ "tMSIDirectiveRes", "ansi_map.tMSIDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_numberPortabilityRequestRes,
{ "numberPortabilityRequestRes", "ansi_map.numberPortabilityRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_serviceRequestRes,
{ "serviceRequestRes", "ansi_map.serviceRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_analyzedInformationRes,
{ "analyzedInformationRes", "ansi_map.analyzedInformationRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_facilitySelectedAndAvailableRes,
{ "facilitySelectedAndAvailableRes", "ansi_map.facilitySelectedAndAvailableRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_modifyRes,
{ "modifyRes", "ansi_map.modifyRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_searchRes,
{ "searchRes", "ansi_map.searchRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_seizeResourceRes,
{ "seizeResourceRes", "ansi_map.seizeResourceRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_sRFDirectiveRes,
{ "sRFDirectiveRes", "ansi_map.sRFDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tBusyRes,
{ "tBusyRes", "ansi_map.tBusyRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tNoAnswerRes,
{ "tNoAnswerRes", "ansi_map.tNoAnswerRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_callControlDirectiveRes,
{ "callControlDirectiveRes", "ansi_map.callControlDirectiveRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oDisconnectRes,
{ "oDisconnectRes", "ansi_map.oDisconnectRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_tDisconnectRes,
{ "tDisconnectRes", "ansi_map.tDisconnectRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oCalledPartyBusyRes,
{ "oCalledPartyBusyRes", "ansi_map.oCalledPartyBusyRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_oNoAnswerRes,
{ "oNoAnswerRes", "ansi_map.oNoAnswerRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionRequestRes,
{ "positionRequestRes", "ansi_map.positionRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_positionRequestForwardRes,
{ "positionRequestForwardRes", "ansi_map.positionRequestForwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPositionRequestRes,
{ "interSystemPositionRequestRes", "ansi_map.interSystemPositionRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemPositionRequestForwardRes,
{ "interSystemPositionRequestForwardRes", "ansi_map.interSystemPositionRequestForwardRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_roamerDatabaseVerificationRequestRes,
{ "roamerDatabaseVerificationRequestRes", "ansi_map.roamerDatabaseVerificationRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_addServiceRes,
{ "addServiceRes", "ansi_map.addServiceRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_dropServiceRes,
{ "dropServiceRes", "ansi_map.dropServiceRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemSMSPage,
{ "interSystemSMSPage", "ansi_map.interSystemSMSPage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_lcsParameterRequestRes,
{ "lcsParameterRequestRes", "ansi_map.lcsParameterRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_checkMEIDRes,
{ "checkMEIDRes", "ansi_map.checkMEIDRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_statusRequestRes,
{ "statusRequestRes", "ansi_map.statusRequestRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_interSystemSMSDeliveryPointToPointRes,
{ "interSystemSMSDeliveryPointToPointRes", "ansi_map.interSystemSMSDeliveryPointToPointRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_map_qualificationRequest2Res,
{ "qualificationRequest2Res", "ansi_map.qualificationRequest2Res_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 5383 "./asn1/ansi_map/packet-ansi_map-template.c"
};
static gint *ett[] = {
&ett_ansi_map,
&ett_mintype,
&ett_digitstype,
&ett_billingid,
&ett_sms_bearer_data,
&ett_sms_teleserviceIdentifier,
&ett_extendedmscid,
&ett_extendedsystemmytypecode,
&ett_handoffstate,
&ett_mscid,
&ett_cdmachanneldata,
&ett_cdmastationclassmark,
&ett_channeldata,
&ett_confidentialitymodes,
&ett_controlchanneldata,
&ett_CDMA2000HandoffInvokeIOSData,
&ett_CDMA2000HandoffResponseIOSData,
&ett_originationtriggers,
&ett_pacaindicator,
&ett_callingpartyname,
&ett_triggercapability,
&ett_winoperationscapability,
&ett_win_trigger_list,
&ett_controlnetworkid,
&ett_transactioncapability,
&ett_cdmaserviceoption,
&ett_sms_originationrestrictions,
&ett_systemcapabilities,
#line 1 "./asn1/ansi_map/packet-ansi_map-ettarr.c"
&ett_ansi_map_AuthenticationDirective_U,
&ett_ansi_map_AuthenticationDirectiveRes_U,
&ett_ansi_map_AuthenticationDirectiveForward_U,
&ett_ansi_map_AuthenticationDirectiveForwardRes_U,
&ett_ansi_map_AuthenticationFailureReport_U,
&ett_ansi_map_AuthenticationFailureReportRes_U,
&ett_ansi_map_AuthenticationRequest_U,
&ett_ansi_map_AuthenticationRequestRes_U,
&ett_ansi_map_AuthenticationStatusReport_U,
&ett_ansi_map_AuthenticationStatusReportRes_U,
&ett_ansi_map_BaseStationChallenge_U,
&ett_ansi_map_BaseStationChallengeRes_U,
&ett_ansi_map_Blocking_U,
&ett_ansi_map_BulkDeregistration_U,
&ett_ansi_map_CountRequest_U,
&ett_ansi_map_CountRequestRes_U,
&ett_ansi_map_FacilitiesDirective_U,
&ett_ansi_map_FacilitiesDirectiveRes_U,
&ett_ansi_map_FacilitiesDirective2_U,
&ett_ansi_map_FacilitiesDirective2Res_U,
&ett_ansi_map_FacilitiesRelease_U,
&ett_ansi_map_FacilitiesReleaseRes_U,
&ett_ansi_map_FeatureRequest_U,
&ett_ansi_map_FeatureRequestRes_U,
&ett_ansi_map_FlashRequest_U,
&ett_ansi_map_HandoffBack_U,
&ett_ansi_map_HandoffBackRes_U,
&ett_ansi_map_HandoffBack2_U,
&ett_ansi_map_HandoffBack2Res_U,
&ett_ansi_map_HandoffMeasurementRequest_U,
&ett_ansi_map_HandoffMeasurementRequestRes_U,
&ett_ansi_map_HandoffMeasurementRequest2_U,
&ett_ansi_map_HandoffMeasurementRequest2Res_U,
&ett_ansi_map_HandoffToThird_U,
&ett_ansi_map_HandoffToThirdRes_U,
&ett_ansi_map_HandoffToThird2_U,
&ett_ansi_map_HandoffToThird2Res_U,
&ett_ansi_map_InformationDirective_U,
&ett_ansi_map_InformationDirectiveRes_U,
&ett_ansi_map_InformationForward_U,
&ett_ansi_map_InformationForwardRes_U,
&ett_ansi_map_InterSystemAnswer_U,
&ett_ansi_map_InterSystemPage_U,
&ett_ansi_map_InterSystemPageRes_U,
&ett_ansi_map_InterSystemPage2_U,
&ett_ansi_map_InterSystemPage2Res_U,
&ett_ansi_map_InterSystemSetup_U,
&ett_ansi_map_InterSystemSetupRes_U,
&ett_ansi_map_LocationRequest_U,
&ett_ansi_map_LocationRequestRes_U,
&ett_ansi_map_MSInactive_U,
&ett_ansi_map_OriginationRequest_U,
&ett_ansi_map_OriginationRequestRes_U,
&ett_ansi_map_QualificationDirective_U,
&ett_ansi_map_QualificationDirectiveRes_U,
&ett_ansi_map_QualificationRequest_U,
&ett_ansi_map_QualificationRequestRes_U,
&ett_ansi_map_RandomVariableRequest_U,
&ett_ansi_map_RandomVariableRequestRes_U,
&ett_ansi_map_RedirectionDirective_U,
&ett_ansi_map_RedirectionRequest_U,
&ett_ansi_map_RegistrationCancellation_U,
&ett_ansi_map_RegistrationCancellationRes_U,
&ett_ansi_map_RegistrationNotification_U,
&ett_ansi_map_RegistrationNotificationRes_U,
&ett_ansi_map_RemoteUserInteractionDirective_U,
&ett_ansi_map_RemoteUserInteractionDirectiveRes_U,
&ett_ansi_map_ResetCircuit_U,
&ett_ansi_map_ResetCircuitRes_U,
&ett_ansi_map_RoutingRequest_U,
&ett_ansi_map_RoutingRequestRes_U,
&ett_ansi_map_SMSDeliveryBackward_U,
&ett_ansi_map_SMSDeliveryBackwardRes_U,
&ett_ansi_map_SMSDeliveryForward_U,
&ett_ansi_map_SMSDeliveryForwardRes_U,
&ett_ansi_map_SMSDeliveryPointToPoint_U,
&ett_ansi_map_SMSDeliveryPointToPointRes_U,
&ett_ansi_map_SMSDeliveryPointToPointAck_U,
&ett_ansi_map_SMSNotification_U,
&ett_ansi_map_SMSNotificationRes_U,
&ett_ansi_map_SMSRequest_U,
&ett_ansi_map_SMSRequestRes_U,
&ett_ansi_map_TransferToNumberRequest_U,
&ett_ansi_map_TransferToNumberRequestRes_U,
&ett_ansi_map_TrunkTest_U,
&ett_ansi_map_TrunkTestDisconnect_U,
&ett_ansi_map_Unblocking_U,
&ett_ansi_map_UnreliableRoamerDataDirective_U,
&ett_ansi_map_UnsolicitedResponse_U,
&ett_ansi_map_UnsolicitedResponseRes_U,
&ett_ansi_map_ParameterRequest_U,
&ett_ansi_map_ParameterRequestRes_U,
&ett_ansi_map_TMSIDirective_U,
&ett_ansi_map_TMSIDirectiveRes_U,
&ett_ansi_map_NumberPortabilityRequest_U,
&ett_ansi_map_NumberPortabilityRequestRes_U,
&ett_ansi_map_ServiceRequest_U,
&ett_ansi_map_ServiceRequestRes_U,
&ett_ansi_map_AnalyzedInformation_U,
&ett_ansi_map_AnalyzedInformationRes_U,
&ett_ansi_map_ConnectionFailureReport_U,
&ett_ansi_map_ConnectResource_U,
&ett_ansi_map_FacilitySelectedAndAvailable_U,
&ett_ansi_map_FacilitySelectedAndAvailableRes_U,
&ett_ansi_map_Modify_U,
&ett_ansi_map_ModifyRes_U,
&ett_ansi_map_Search_U,
&ett_ansi_map_SearchRes_U,
&ett_ansi_map_SeizeResource_U,
&ett_ansi_map_SeizeResourceRes_U,
&ett_ansi_map_SRFDirective_U,
&ett_ansi_map_SRFDirectiveRes_U,
&ett_ansi_map_TBusy_U,
&ett_ansi_map_TBusyRes_U,
&ett_ansi_map_TNoAnswer_U,
&ett_ansi_map_TNoAnswerRes_U,
&ett_ansi_map_ChangeFacilities_U,
&ett_ansi_map_ChangeFacilitiesRes_U,
&ett_ansi_map_ChangeService_U,
&ett_ansi_map_ChangeServiceRes_U,
&ett_ansi_map_MessageDirective_U,
&ett_ansi_map_BulkDisconnection_U,
&ett_ansi_map_CallControlDirective_U,
&ett_ansi_map_CallControlDirectiveRes_U,
&ett_ansi_map_OAnswer_U,
&ett_ansi_map_ODisconnect_U,
&ett_ansi_map_ODisconnectRes_U,
&ett_ansi_map_CallRecoveryReport_U,
&ett_ansi_map_TAnswer_U,
&ett_ansi_map_TDisconnect_U,
&ett_ansi_map_TDisconnectRes_U,
&ett_ansi_map_UnreliableCallData_U,
&ett_ansi_map_OCalledPartyBusy_U,
&ett_ansi_map_OCalledPartyBusyRes_U,
&ett_ansi_map_ONoAnswer_U,
&ett_ansi_map_ONoAnswerRes_U,
&ett_ansi_map_PositionRequest_U,
&ett_ansi_map_PositionRequestRes_U,
&ett_ansi_map_PositionRequestForward_U,
&ett_ansi_map_PositionRequestForwardRes_U,
&ett_ansi_map_CallTerminationReport_U,
&ett_ansi_map_GeoPositionRequest_U,
&ett_ansi_map_InterSystemPositionRequest_U,
&ett_ansi_map_InterSystemPositionRequestRes_U,
&ett_ansi_map_InterSystemPositionRequestForward_U,
&ett_ansi_map_InterSystemPositionRequestForwardRes_U,
&ett_ansi_map_ACGDirective_U,
&ett_ansi_map_RoamerDatabaseVerificationRequest_U,
&ett_ansi_map_RoamerDatabaseVerificationRequestRes_U,
&ett_ansi_map_LCSParameterRequest_U,
&ett_ansi_map_LCSParameterRequestRes_U,
&ett_ansi_map_CheckMEID_U,
&ett_ansi_map_CheckMEIDRes_U,
&ett_ansi_map_AddService_U,
&ett_ansi_map_AddServiceRes_U,
&ett_ansi_map_DropService_U,
&ett_ansi_map_DropServiceRes_U,
&ett_ansi_map_PositionEventNotification_U,
&ett_ansi_map_OTASPRequest_U,
&ett_ansi_map_OTASPRequestRes_U,
&ett_ansi_map_StatusRequest_U,
&ett_ansi_map_StatusRequestRes_U,
&ett_ansi_map_InterSystemSMSDeliveryPointToPoint_U,
&ett_ansi_map_InterSystemSMSDeliveryPointToPointRes_U,
&ett_ansi_map_InterSystemSMSPage_U,
&ett_ansi_map_QualificationRequest2_U,
&ett_ansi_map_QualificationRequest2Res_U,
&ett_ansi_map_AnnouncementList,
&ett_ansi_map_CDMACodeChannelInformation,
&ett_ansi_map_CDMACodeChannelList,
&ett_ansi_map_CDMATargetMAHOInformation,
&ett_ansi_map_CDMATargetMAHOList,
&ett_ansi_map_CDMATargetMeasurementInformation,
&ett_ansi_map_CDMATargetMeasurementList,
&ett_ansi_map_IntersystemTermination,
&ett_ansi_map_LocalTermination,
&ett_ansi_map_PSTNTermination,
&ett_ansi_map_TargetMeasurementInformation,
&ett_ansi_map_TargetMeasurementList,
&ett_ansi_map_TerminationList,
&ett_ansi_map_TerminationList_item,
&ett_ansi_map_CDMABandClassInformation,
&ett_ansi_map_CDMABandClassList,
&ett_ansi_map_CDMAServiceOptionList,
&ett_ansi_map_PSID_RSIDList,
&ett_ansi_map_TargetCellIDList,
&ett_ansi_map_CDMAConnectionReferenceInformation,
&ett_ansi_map_CDMAConnectionReferenceList,
&ett_ansi_map_CDMAConnectionReferenceList_item,
&ett_ansi_map_AnalogRedirectRecord,
&ett_ansi_map_CDMAChannelNumberList,
&ett_ansi_map_CDMAChannelNumberList_item,
&ett_ansi_map_CDMARedirectRecord,
&ett_ansi_map_MSID,
&ett_ansi_map_DataAccessElement,
&ett_ansi_map_DataAccessElementList,
&ett_ansi_map_DataAccessElementList_item,
&ett_ansi_map_DataUpdateResult,
&ett_ansi_map_DataUpdateResultList,
&ett_ansi_map_DestinationAddress,
&ett_ansi_map_ExecuteScript,
&ett_ansi_map_ModificationRequest,
&ett_ansi_map_ModificationRequestList,
&ett_ansi_map_ModificationResult,
&ett_ansi_map_ModificationResultList,
&ett_ansi_map_ServiceDataAccessElement,
&ett_ansi_map_ServiceDataAccessElementList,
&ett_ansi_map_ServiceDataResult,
&ett_ansi_map_ServiceDataResultList,
&ett_ansi_map_TriggerAddressList,
&ett_ansi_map_TriggerList,
&ett_ansi_map_WINCapability,
&ett_ansi_map_CallRecoveryID,
&ett_ansi_map_CallRecoveryIDList,
&ett_ansi_map_PositionInformation,
&ett_ansi_map_GapInterval,
&ett_ansi_map_CDMAPSMMList,
&ett_ansi_map_CDMAPSMMList_item,
&ett_ansi_map_MPCAddressList,
&ett_ansi_map_MobileStationMSID,
&ett_ansi_map_NewlyAssignedMSID,
&ett_ansi_map_InvokeData,
&ett_ansi_map_ReturnData,
#line 5416 "./asn1/ansi_map/packet-ansi_map-template.c"
};
static ei_register_info ei[] = {
{ &ei_ansi_map_nr_not_used, { "ansi_map.nr_not_used", PI_PROTOCOL, PI_WARN, "This Number plan should not have been used", EXPFILL }},
{ &ei_ansi_map_unknown_invokeData_blob, { "ansi_map.unknown_invokeData_blob", PI_PROTOCOL, PI_WARN, "Unknown invokeData blob", EXPFILL }},
{ &ei_ansi_map_no_data, { "ansi_map.no_data", PI_PROTOCOL, PI_NOTE, "Carries no data", EXPFILL }},
};
expert_module_t* expert_ansi_map;
static const enum_val_t ansi_map_response_matching_type_values[] = {
{"Only Transaction ID will be used in Invoke/response matching", "Transaction ID only", ANSI_MAP_TID_ONLY},
{"Transaction ID and Source will be used in Invoke/response matching", "Transaction ID and Source", ANSI_MAP_TID_AND_SOURCE},
{"Transaction ID Source and Destination will be used in Invoke/response matching", "Transaction ID Source and Destination", ANSI_MAP_TID_SOURCE_AND_DEST},
{NULL, NULL, -1}
};
static stat_tap_table_ui stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_ANSI,
"Map Operation Statistics",
"ansi_map",
"ansi_map",
ansi_map_stat_init,
ansi_map_stat_packet,
ansi_map_stat_reset,
NULL,
NULL,
sizeof(stat_fields)/sizeof(stat_tap_table_item), stat_fields,
0, NULL,
NULL,
0
};
proto_ansi_map = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ansi_map, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ansi_map = expert_register_protocol(proto_ansi_map);
expert_register_field_array(expert_ansi_map, ei, array_length(ei));
ansi_map_handle = register_dissector("ansi_map", dissect_ansi_map, proto_ansi_map);
is637_tele_id_dissector_table =
register_dissector_table("ansi_map.tele_id", "IS-637 Teleservice ID", proto_ansi_map,
FT_UINT8, BASE_DEC);
is683_dissector_table =
register_dissector_table("ansi_map.ota", "IS-683-A (OTA)", proto_ansi_map,
FT_UINT8, BASE_DEC);
is801_dissector_table =
register_dissector_table("ansi_map.pld", "IS-801 (PLD)", proto_ansi_map,
FT_UINT8, BASE_DEC);
ansi_map_tap = register_tap("ansi_map");
range_convert_str(wmem_epan_scope(), &global_ssn_range, "5-14", MAX_SSN);
ansi_map_module = prefs_register_protocol(proto_ansi_map, proto_reg_handoff_ansi_map);
prefs_register_range_preference(ansi_map_module, "map.ssn", "ANSI MAP SSNs",
"ANSI MAP SSNs to decode as ANSI MAP",
&global_ssn_range, MAX_SSN);
prefs_register_enum_preference(ansi_map_module, "transaction.matchtype",
"Type of matching invoke/response",
"Type of matching invoke/response, risk of mismatch if loose matching chosen",
&ansi_map_response_matching_type, ansi_map_response_matching_type_values, FALSE);
TransactionId_table = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), wmem_str_hash, g_str_equal);
register_stat_tap_table_ui(&stat_table);
}
