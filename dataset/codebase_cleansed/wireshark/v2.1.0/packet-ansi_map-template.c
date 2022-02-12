static void
ansi_map_init(void)
{
TransactionId_table = g_hash_table_new(g_str_hash, g_str_equal);
}
static void
ansi_map_cleanup(void)
{
g_hash_table_destroy(TransactionId_table);
}
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
ansi_map_saved_invokedata = (struct ansi_map_invokedata_t *)g_hash_table_lookup(TransactionId_table,buf);
if(ansi_map_saved_invokedata)
return;
ansi_map_saved_invokedata = wmem_new(wmem_file_scope(), struct ansi_map_invokedata_t);
ansi_map_saved_invokedata->opcode = p_private_tcap->d.OperationCode_private;
ansi_map_saved_invokedata->ServiceIndicator = ServiceIndicator;
g_hash_table_insert(TransactionId_table,
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
octet_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
if(octet_len == 0)
return;
offset++;
proto_tree_add_item(subtree, hf_ansi_map_ia5_digits, tvb, offset, -1, ENC_ASCII|ENC_NA);
proto_item_append_text(actx->created_item, " - %s", tvb_get_string_enc(wmem_packet_scope(),tvb,offset,tvb_reported_length_remaining(tvb,offset),ENC_ASCII|ENC_NA));
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
proto_tree_add_item(subtree, hf_ansi_map_ia5_digits, tvb, offset, -1, ENC_ASCII|ENC_NA);
proto_item_append_text(actx->created_item, " - %s", tvb_get_string_enc(wmem_packet_scope(),tvb,offset,tvb_reported_length_remaining(tvb,offset),ENC_ASCII|ENC_NA));
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
ansi_map_saved_invokedata = (struct ansi_map_invokedata_t *)g_hash_table_lookup(TransactionId_table, buf);
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
ansi_map_handle = find_dissector("ansi_map");
}
else
{
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
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
#include "packet-ansi_map-hfarr.c"
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
#include "packet-ansi_map-ettarr.c"
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
NULL
};
proto_ansi_map = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ansi_map, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ansi_map = expert_register_protocol(proto_ansi_map);
expert_register_field_array(expert_ansi_map, ei, array_length(ei));
register_dissector("ansi_map", dissect_ansi_map, proto_ansi_map);
is637_tele_id_dissector_table =
register_dissector_table("ansi_map.tele_id", "IS-637 Teleservice ID", proto_ansi_map,
FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
is683_dissector_table =
register_dissector_table("ansi_map.ota", "IS-683-A (OTA)", proto_ansi_map,
FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
is801_dissector_table =
register_dissector_table("ansi_map.pld", "IS-801 (PLD)", proto_ansi_map,
FT_UINT8, BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
ansi_map_tap = register_tap("ansi_map");
range_convert_str(&global_ssn_range, "5-14", MAX_SSN);
ansi_map_module = prefs_register_protocol(proto_ansi_map, proto_reg_handoff_ansi_map);
prefs_register_range_preference(ansi_map_module, "map.ssn", "ANSI MAP SSNs",
"ANSI MAP SSNs to decode as ANSI MAP",
&global_ssn_range, MAX_SSN);
prefs_register_enum_preference(ansi_map_module, "transaction.matchtype",
"Type of matching invoke/response",
"Type of matching invoke/response, risk of mismatch if loose matching chosen",
&ansi_map_response_matching_type, ansi_map_response_matching_type_values, FALSE);
register_init_routine(&ansi_map_init);
register_cleanup_routine(&ansi_map_cleanup);
register_stat_tap_table_ui(&stat_table);
}
