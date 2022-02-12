const char *
unpack_digits(tvbuff_t *tvb, int offset) {
int length;
guint8 octet;
int i=0;
char *digit_str;
length = tvb_length(tvb);
if (length < offset)
return "";
digit_str = (char *)ep_alloc((length - offset)*2+1);
while ( offset < length ){
octet = tvb_get_guint8(tvb,offset);
digit_str[i] = ((octet & 0x0f) + '0');
i++;
octet = octet >> 4;
if (octet == 0x0f)
break;
digit_str[i] = ((octet & 0x0f) + '0');
i++;
offset++;
}
digit_str[i]= '\0';
return digit_str;
}
static guint
gsm_map_calc_bitrate(guint8 value){
guint8 granularity;
guint returnvalue;
if (value == 0xff)
return 0;
granularity = value >> 6;
returnvalue = value & 0x7f;
switch (granularity){
case 0:
break;
case 1:
returnvalue = ((returnvalue - 0x40) << 3)+64;
break;
case 2:
returnvalue = (returnvalue << 6)+576;
break;
case 3:
returnvalue = (returnvalue << 6)+576;
break;
}
return returnvalue;
}
static void
dissect_gsm_map_ext_qos_subscribed(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx){
int offset = 0;
proto_tree *subtree;
guint8 octet;
guint16 value;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_ext_qos_subscribed);
proto_tree_add_item(subtree, hf_gsm_map_ext_qos_subscribed_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_gsm_map_qos_traffic_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_qos_del_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_qos_del_of_err_sdu, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb,offset);
switch (octet){
case 0:
proto_tree_add_text(subtree, tvb, offset, 1, "Subscribed Maximum SDU size/Reserved");
break;
case 0x93:
value = 1502;
proto_tree_add_uint(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, value);
break;
case 0x98:
value = 1510;
proto_tree_add_uint(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, value);
break;
case 0x99:
value = 1532;
proto_tree_add_uint(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, value);
break;
default:
if (octet<0x97){
value = octet * 10;
proto_tree_add_uint(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, value);
}else{
proto_tree_add_text(subtree, tvb, offset, 1, "Maximum SDU size value 0x%x not defined in TS 24.008",octet);
}
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_text(subtree, tvb, offset, 1, "Subscribed Maximum bit rate for uplink/Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_max_brate_ulink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_text(subtree, tvb, offset, 1, "Subscribed Maximum bit rate for downlink/Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_max_brate_dlink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
offset++;
proto_tree_add_item(subtree, hf_gsm_map_qos_ber, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_qos_sdu_err_rat, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_gsm_map_qos_transfer_delay, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_qos_traff_hdl_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_text(subtree, tvb, offset, 1, "Subscribed Guaranteed bit rate for uplink/Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_guaranteed_max_brate_ulink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_text(subtree, tvb, offset, 1, "Subscribed Guaranteed bit rate for downlink/Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_guaranteed_max_brate_dlink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
}
guint8
dissect_cbs_data_coding_scheme(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint16 offset)
{
guint8 octet;
guint8 coding_grp;
guint8 character_set;
octet = tvb_get_guint8(tvb,offset);
coding_grp = octet >>4;
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp, tvb, offset, 1, ENC_BIG_ENDIAN);
sms_encoding = SMS_ENCODING_NOT_SET;
switch (coding_grp){
case 0:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp0_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
sms_encoding = SMS_ENCODING_7BIT;
break;
case 1:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp1_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0x0f)== 0){
sms_encoding = SMS_ENCODING_7BIT_LANG;
}else{
sms_encoding = SMS_ENCODING_UCS2_LANG;
}
break;
case 2:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp2_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
sms_encoding = SMS_ENCODING_7BIT;
break;
case 3:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp3_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
sms_encoding = SMS_ENCODING_7BIT;
break;
case 4:
case 5:
case 6:
case 7:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_comp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_class_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_char_set, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0x10)== 0x10){
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_class, tvb, offset, 1, ENC_BIG_ENDIAN);
}
character_set = (octet&0x0c)>>2;
switch (character_set){
case 0:
sms_encoding = SMS_ENCODING_7BIT;
break;
case 1:
sms_encoding = SMS_ENCODING_8BIT;
break;
case 2:
sms_encoding = SMS_ENCODING_UCS2;
break;
case 3:
sms_encoding = SMS_ENCODING_NOT_SET;
break;
default:
break;
}
break;
case 8:
break;
case 9:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_char_set, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp4_7_class, tvb, offset, 1, ENC_BIG_ENDIAN);
character_set = (octet&0x0c)>>2;
switch (character_set){
case 0:
sms_encoding = SMS_ENCODING_7BIT;
break;
case 1:
sms_encoding = SMS_ENCODING_8BIT;
break;
case 2:
sms_encoding = SMS_ENCODING_UCS2;
break;
case 3:
sms_encoding = SMS_ENCODING_NOT_SET;
break;
default:
break;
}
break;
case 10:
case 11:
case 12:
case 13:
break;
case 14:
break;
case 15:
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp15_mess_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_cbs_coding_grp15_class, tvb, offset, 1, ENC_BIG_ENDIAN);
character_set = (octet&0x04)>>2;
if (character_set == 0){
sms_encoding = SMS_ENCODING_7BIT;
}else{
sms_encoding = SMS_ENCODING_8BIT;
}
break;
default:
break;
}
return sms_encoding;
}
void
dissect_gsm_map_msisdn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
const char *digit_str;
guint8 octet;
guint8 na;
guint8 np;
proto_tree_add_item(tree, hf_gsm_map_extension, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_nature_of_number, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_number_plan, tvb, 0,1,ENC_BIG_ENDIAN);
if(tvb_length(tvb)==1)
return;
digit_str = unpack_digits(tvb, 1);
proto_tree_add_string(tree, hf_gsm_map_address_digits, tvb, 1, -1, digit_str);
octet = tvb_get_guint8(tvb,0);
na = (octet & 0x70)>>4;
np = octet & 0x0f;
if ((na == 1) && (np==1))
dissect_e164_cc(tvb, tree, 1, TRUE);
else if(np==6)
dissect_e212_mcc_mnc_in_address(tvb, pinfo, tree, 1);
}
const gchar* gsm_map_opr_code(guint32 val) {
switch (val) {
case 44:
case 46:
if (application_context_version < 3) {
return val_to_str_const(val, gsm_map_V1V2_opr_code_strings, "Unknown GSM-MAP opcode");
}
default:
return val_to_str_ext_const(val, &gsm_old_GSMMAPOperationLocalvalue_vals_ext, "Unknown GSM-MAP opcode");
break;
}
}
static int dissect_mc_message(tvbuff_t *tvb,
int offset,
asn1_ctx_t *actx,
proto_tree *tree,
gboolean implicit_param _U_, dissect_function_t parameter, int hf_index_param _U_,
gboolean implicit_seq _U_, dissect_function_t sequence, int hf_index_seq _U_,
gboolean implicit_seq3 _U_, dissect_function_t sequence3, int hf_index_seq3 _U_ )
{
guint8 octet;
gint8 bug_class;
gboolean bug_pc, bug_ind_field;
gint32 bug_tag;
guint32 bug_len;
proto_item *cause;
octet = tvb_get_guint8(tvb,0);
if ( (octet & 0xf) == 3) {
offset = get_ber_identifier(tvb, offset, &bug_class, &bug_pc, &bug_tag);
offset = get_ber_length(tvb, offset, &bug_len, &bug_ind_field);
if (sequence3 != NULL) {
offset= (sequence3) (implicit_seq3, tvb, offset, actx, tree, hf_index_seq3);
} else {
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown or not implemented [3] sequence, cannot decode");
proto_item_set_expert_flags(cause, PI_UNDECODED, PI_ERROR);
expert_add_info_format(actx->pinfo, cause, PI_UNDECODED, PI_ERROR, "Unknown or not implemented [3] sequence");
}
} else if (octet == 0x30) {
if (sequence != NULL) {
offset= (sequence) (implicit_seq, tvb, 0, actx, tree, hf_index_seq);
} else {
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown or not implemented sequence");
proto_item_set_expert_flags(cause, PI_UNDECODED, PI_ERROR);
expert_add_info_format(actx->pinfo, cause, PI_UNDECODED, PI_ERROR, "Unknown or not implemented sequence");
}
} else {
if (parameter != NULL) {
offset= (parameter) (implicit_param, tvb, offset, actx, tree, hf_index_param);
} else {
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown or not implemented parameter");
proto_item_set_expert_flags(cause, PI_UNDECODED, PI_ERROR);
expert_add_info_format(actx->pinfo, cause, PI_UNDECODED, PI_ERROR, "Unknown or not implemented parameter");
}
}
return offset;
}
static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
proto_item *cause;
switch(opcode){
case 2:
offset=dissect_gsm_map_ms_UpdateLocationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 3:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_Identity, hf_gsm_map_ms_identity,
FALSE, dissect_gsm_map_Identity, hf_gsm_map_ms_identity,
TRUE , dissect_gsm_map_ms_CancelLocationArg, -1);
break;
case 4:
offset=dissect_gsm_map_ch_ProvideRoamingNumberArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 5:
offset=dissect_gsm_map_ms_NoteSubscriberDataModifiedArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 6:
offset=dissect_gsm_map_ch_ResumeCallHandlingArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 7:
offset=dissect_gsm_map_ms_InsertSubscriberDataArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 8:
offset=dissect_gsm_map_ms_DeleteSubscriberDataArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 10:
offset=dissect_gsm_map_ss_RegisterSS_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 11:
offset=dissect_gsm_map_ss_SS_ForBS_Code(FALSE, tvb, offset, actx, tree, -1);
break;
case 12:
offset=dissect_gsm_map_ss_SS_ForBS_Code(FALSE, tvb, offset, actx, tree, -1);
break;
case 13:
offset=dissect_gsm_map_ss_SS_ForBS_Code(FALSE, tvb, offset, actx, tree, -1);
break;
case 14:
offset=dissect_gsm_map_ss_SS_ForBS_Code(FALSE, tvb, offset, actx, tree, -1);
break;
case 15:
offset=dissect_gsm_map_ms_AuthenticationFailureReportArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 16:
offset=dissect_gsm_ss_NotifySS_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 17:
offset=dissect_gsm_map_SS_Code(FALSE, tvb, offset, actx, tree, hf_gsm_map_ss_Code);
break;
case 18:
offset=dissect_gsm_old_GetPasswordArg(FALSE, tvb, offset, actx, tree, hf_gsm_map_getPassword);
break;
case 19:
offset=dissect_gsm_ss_SS_UserData(FALSE, tvb, offset, actx, tree, hf_gsm_map_ss_SS_UserData);
break;
case 20:
offset=dissect_gsm_map_ch_ReleaseResourcesArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 21:
offset=dissect_gsm_map_sm_MT_ForwardSM_VGCS_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 22:
if (application_context_version == 3){
offset=dissect_gsm_map_ch_SendRoutingInfoArg(FALSE, tvb, offset, actx, tree, -1);
}else{
offset=dissect_gsm_old_SendRoutingInfoArgV2(FALSE, tvb, offset, actx, tree, -1);
}
break;
case 23:
offset=dissect_gsm_map_ms_UpdateGprsLocationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 24:
offset=dissect_gsm_map_ms_SendRoutingInfoForGprsArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 25:
offset=dissect_gsm_map_ms_FailureReportArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 26:
offset=dissect_gsm_map_ms_NoteMsPresentForGprsArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 29:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_Bss_APDU, -1,
TRUE , dissect_gsm_map_ms_SendEndSignal_Arg, -1);
break;
case 31:
offset=dissect_gsm_old_ProvideSIWFSNumberArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 32:
offset=dissect_gsm_old_SIWFSSignallingModifyArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 33:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_Bss_APDU, -1,
TRUE , dissect_gsm_map_ms_ProcessAccessSignalling_Arg, -1);
break;
case 34:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_Bss_APDU, -1,
TRUE , dissect_gsm_map_ms_ForwardAccessSignalling_Arg, -1);
break;
case 37:
offset=dissect_gsm_map_ms_ResetArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 38:
return offset;
break;
case 39:
offset=dissect_gsm_map_gr_PrepareGroupCallArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 40:
offset = dissect_gsm_map_gr_SendGroupCallEndSignalArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 41:
offset = dissect_gsm_map_gr_ProcessGroupCallSignallingArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 42:
offset=dissect_gsm_map_gr_ForwardGroupCallSignallingArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 43:
if (pref_ericsson_proprietary_ext) {
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMEI, hf_gsm_map_ms_imei,
FALSE, dissect_gsm_map_ericsson_EnhancedCheckIMEI_Arg, -1,
TRUE , NULL, -1);
} else {
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMEI, hf_gsm_map_ms_imei,
FALSE, dissect_gsm_map_ms_CheckIMEI_Arg, -1,
TRUE , NULL, -1);
}
break;
case 44:
if (application_context_version == 3)
offset=dissect_gsm_map_sm_MT_ForwardSM_Arg(FALSE, tvb, offset, actx, tree, -1);
else {
offset=dissect_gsm_old_ForwardSM_Arg(FALSE, tvb, offset, actx, tree, -1);
}
break;
case 45:
offset=dissect_gsm_map_sm_RoutingInfoForSM_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 46:
if (application_context_version == 3)
offset=dissect_gsm_map_sm_MO_ForwardSM_Arg(FALSE, tvb, offset, actx, tree, -1);
else {
offset=dissect_gsm_old_ForwardSM_Arg(FALSE, tvb, offset, actx, tree, -1);
}
break;
case 47:
offset=dissect_gsm_map_sm_ReportSM_DeliveryStatusArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 49:
offset = dissect_gsm_map_sm_AlertServiceCentreArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 50:
offset=dissect_gsm_map_om_ActivateTraceModeArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 51:
offset=dissect_gsm_map_om_DeactivateTraceModeArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 54:
offset=dissect_gsm_old_BeginSubscriberActivityArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 55:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_TMSI, hf_gsm_map_tmsi,
FALSE, dissect_gsm_map_ms_SendIdentificationArg, -1,
TRUE, NULL, -1);
break;
case 56:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMSI, hf_gsm_map_imsi,
FALSE, dissect_gsm_map_ms_SendAuthenticationInfoArg, -1,
TRUE, NULL, -1);
break;
case 57:
offset=dissect_gsm_map_ms_RestoreDataArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 58:
offset = dissect_gsm_map_ISDN_AddressString(FALSE, tvb, offset, actx, tree, hf_gsm_map_msisdn);
break;
case 59:
offset=dissect_gsm_map_ss_USSD_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 60:
offset=dissect_gsm_map_ss_USSD_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 61:
offset=dissect_gsm_map_ss_USSD_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 62:
offset=dissect_gsm_map_ms_AnyTimeSubscriptionInterrogationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 63:
offset=dissect_gsm_map_sm_InformServiceCentreArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 64:
offset=dissect_gsm_map_sm_AlertServiceCentreArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 65:
offset=dissect_gsm_map_ms_AnyTimeModificationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 66:
offset=dissect_gsm_map_sm_ReadyForSM_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 67:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMSI, hf_gsm_map_imsi,
FALSE, dissect_gsm_old_PurgeMSArgV2, -1,
TRUE , dissect_gsm_map_ms_PurgeMS_Arg, -1);
break;
case 68:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_PrepareHO_ArgOld, -1,
TRUE, dissect_gsm_map_ms_PrepareHO_Arg, -1);
break;
case 69:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, NULL, -1,
TRUE, dissect_gsm_map_ms_PrepareSubsequentHO_Arg, -1);
break;
case 70:
offset=dissect_gsm_map_ms_ProvideSubscriberInfoArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 71:
offset=dissect_gsm_map_ms_AnyTimeInterrogationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 72:
offset=dissect_gsm_map_ss_SS_InvocationNotificationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 73:
offset=dissect_gsm_map_ch_SetReportingStateArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 74:
offset=dissect_gsm_map_ch_StatusReportArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 75:
offset=dissect_gsm_map_ch_RemoteUserFreeArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 76:
offset=dissect_gsm_map_ss_RegisterCC_EntryArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 77:
offset=dissect_gsm_map_ss_EraseCC_EntryArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 78:
case 79:
case 80:
case 81:
offset=dissect_gsm_old_SecureTransportArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 83:
offset=dissect_gsm_map_lcs_ProvideSubscriberLocation_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 84:
offset=dissect_gsm_map_gr_SendGroupCallInfoArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 85:
offset=dissect_gsm_map_lcs_RoutingInfoForLCS_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 86:
offset=dissect_gsm_map_lcs_SubscriberLocationReport_Arg(FALSE, tvb, offset, actx, tree, -1);
break;
case 87:
offset=dissect_gsm_map_ch_IST_AlertArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 88:
offset=dissect_gsm_map_ch_IST_CommandArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 89:
offset=dissect_gsm_map_ms_NoteMM_EventArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 109:
offset=dissect_gsm_ss_LCS_PeriodicLocationCancellationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 110:
offset=dissect_gsm_ss_LCS_LocationUpdateArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 111:
offset=dissect_gsm_ss_LCS_PeriodicLocationRequestArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 112:
offset=dissect_gsm_ss_LCS_AreaEventCancellationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 113:
offset=dissect_gsm_ss_LCS_AreaEventReportArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 114:
offset=dissect_gsm_ss_LCS_AreaEventRequestArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 115:
offset=dissect_gsm_ss_LCS_MOLRArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 116:
offset=dissect_gsm_ss_LocationNotificationArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 117:
offset=dissect_gsm_ss_CallDeflectionArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 118:
offset=dissect_gsm_ss_UserUserServiceArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 119:
offset=dissect_gsm_ss_AccessRegisterCCEntryArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 120:
application_context_version = 3;
offset=dissect_gsm_ss_ForwardCUG_InfoArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 121:
break;
case 122:
break;
case 123:
break;
case 124:
break;
case 125:
offset=dissect_gsm_ss_ForwardChargeAdviceArg(FALSE, tvb, offset, actx, tree, -1);
break;
case 126:
break;
default:
if(!dissector_try_uint(map_prop_arg_opcode_table, (guint8)opcode, tvb, actx->pinfo, tree)){
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown invokeData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown invokeData %d",opcode);
}
offset+= tvb_length_remaining(tvb,offset);
break;
}
return offset;
}
static int dissect_returnResultData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
proto_item *cause;
switch(opcode){
case 2:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMSI, hf_gsm_map_imsi,
FALSE, dissect_gsm_map_ms_UpdateLocationRes, -1,
TRUE , NULL, -1);
break;
case 3:
offset=dissect_gsm_map_ms_CancelLocationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 4:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_ISDN_AddressString, hf_gsm_map_msisdn,
FALSE, dissect_gsm_map_ch_ProvideRoamingNumberRes, -1,
TRUE , NULL, -1);
break;
case 5:
offset=dissect_gsm_map_ms_NoteSubscriberDataModifiedRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 6:
offset=dissect_gsm_map_ch_ResumeCallHandlingRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 7:
offset=dissect_gsm_map_ms_InsertSubscriberDataRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 8:
offset=dissect_gsm_map_ms_DeleteSubscriberDataRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 10:
offset=dissect_gsm_map_ss_SS_Info(FALSE, tvb, offset, actx, tree, -1);
break;
case 11:
offset=dissect_gsm_map_ss_SS_Info(FALSE, tvb, offset, actx, tree, -1);
break;
case 12:
offset=dissect_gsm_map_ss_SS_Info(FALSE, tvb, offset, actx, tree, -1);
break;
case 13:
offset=dissect_gsm_map_ss_SS_Info(FALSE, tvb, offset, actx, tree, -1);
break;
case 14:
offset=dissect_gsm_map_ss_InterrogateSS_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 15:
offset=dissect_gsm_map_ms_AuthenticationFailureReportRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 17:
offset=dissect_gsm_old_NewPassword(FALSE, tvb, offset, actx, tree, hf_gsm_map_ss_Code);
break;
case 18:
offset=dissect_gsm_old_CurrentPassword(FALSE, tvb, offset, actx, tree, hf_gsm_map_currentPassword);
break;
case 19:
offset=dissect_gsm_ss_SS_UserData(FALSE, tvb, offset, actx, tree, hf_gsm_map_ss_SS_UserData);
break;
case 20:
offset=dissect_gsm_map_ch_ReleaseResourcesRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 21:
offset=dissect_gsm_map_sm_MT_ForwardSM_VGCS_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 22:
if (application_context_version == 3){
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_map_ch_SendRoutingInfoRes_U, -1,
TRUE , dissect_gsm_map_ch_SendRoutingInfoRes, -1);
}else{
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMSI, hf_gsm_map_imsi,
FALSE, dissect_gsm_old_SendRoutingInfoResV2, -1,
TRUE , dissect_gsm_map_ch_SendRoutingInfoRes, -1);
}
break;
case 23:
offset=dissect_gsm_map_ms_UpdateGprsLocationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 24:
offset=dissect_gsm_map_ms_SendRoutingInfoForGprsRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 25:
offset=dissect_gsm_map_ms_FailureReportRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 26:
offset=dissect_gsm_map_ms_NoteMsPresentForGprsRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 29:
offset=dissect_gsm_map_ms_SendEndSignal_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 31:
offset=dissect_gsm_old_ProvideSIWFSNumberRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 32:
offset=dissect_gsm_old_SIWFSSignallingModifyRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 39:
offset=dissect_gsm_map_gr_PrepareGroupCallRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 40:
offset=dissect_gsm_map_gr_SendGroupCallEndSignalRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 43:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_ms_EquipmentStatus, hf_gsm_map_ms_equipmentStatus,
FALSE, dissect_gsm_map_ms_CheckIMEI_Res, -1,
TRUE, NULL, -1);
break;
case 44:
offset=dissect_gsm_map_sm_MT_ForwardSM_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 45:
offset=dissect_gsm_map_sm_RoutingInfoForSM_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 46:
offset=dissect_gsm_map_sm_MO_ForwardSM_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 47:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_ISDN_AddressString, hf_gsm_map_sm_storedMSISDN,
FALSE, NULL, -1,
FALSE , dissect_gsm_map_sm_ReportSM_DeliveryStatusRes, -1);
break;
case 48:
break;
case 50:
offset=dissect_gsm_map_om_ActivateTraceModeRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 51:
offset=dissect_gsm_map_om_DeactivateTraceModeRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 55:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, dissect_gsm_map_IMSI, hf_gsm_map_imsi,
FALSE, dissect_gsm_old_SendIdentificationResV2, -1,
TRUE, dissect_gsm_map_ms_SendIdentificationRes, -1);
break;
case 56:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_SendAuthenticationInfoResOld, -1,
TRUE , dissect_gsm_map_ms_SendAuthenticationInfoRes, -1);
break;
case 57:
offset=dissect_gsm_map_ms_RestoreDataRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 58:
offset=dissect_gsm_map_IMSI(FALSE, tvb, offset, actx, tree, hf_gsm_map_ms_imsi);
break;
case 59:
offset=dissect_gsm_map_ss_USSD_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 60:
offset=dissect_gsm_map_ss_USSD_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 61:
proto_tree_add_text(tree, tvb, offset, -1, "Unknown returnResultData blob");
break;
case 62:
offset=dissect_gsm_map_ms_AnyTimeSubscriptionInterrogationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 64:
break;
case 65:
offset=dissect_gsm_map_ms_AnyTimeModificationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 66:
offset=dissect_gsm_map_sm_ReadyForSM_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 67:
offset=dissect_gsm_map_ms_PurgeMS_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 68:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, dissect_gsm_old_PrepareHO_ResOld, -1,
TRUE , dissect_gsm_map_ms_PrepareHO_Res, -1);
break;
case 69:
offset=dissect_mc_message(tvb, offset, actx, tree,
FALSE, NULL, -1,
FALSE, NULL, -1,
TRUE , dissect_gsm_map_ms_PrepareSubsequentHO_Res, -1);
break;
case 70:
offset=dissect_gsm_map_ms_ProvideSubscriberInfoRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 71:
offset=dissect_gsm_map_ms_AnyTimeInterrogationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 72:
offset=dissect_gsm_map_ss_SS_InvocationNotificationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 73:
offset=dissect_gsm_map_ch_SetReportingStateRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 74:
offset=dissect_gsm_map_ch_StatusReportRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 75:
offset=dissect_gsm_map_ch_RemoteUserFreeRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 76:
offset=dissect_gsm_map_ss_RegisterCC_EntryRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 77:
offset=dissect_gsm_map_ss_EraseCC_EntryRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 78:
case 79:
case 80:
case 81:
offset=dissect_gsm_old_SecureTransportRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 83:
offset=dissect_gsm_map_lcs_ProvideSubscriberLocation_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 84:
offset=dissect_gsm_map_gr_SendGroupCallInfoRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 85:
offset=dissect_gsm_map_lcs_RoutingInfoForLCS_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 86:
offset=dissect_gsm_map_lcs_SubscriberLocationReport_Res(FALSE, tvb, offset, actx, tree, -1);
break;
case 87:
offset=dissect_gsm_map_ch_IST_AlertRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 88:
offset=dissect_gsm_map_ch_IST_CommandRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 89:
offset=dissect_gsm_map_ms_NoteMM_EventRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 109:
break;
case 110:
offset=dissect_gsm_ss_LCS_LocationUpdateRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 111:
offset=dissect_gsm_ss_LCS_PeriodicLocationRequestRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 112:
break;
case 113:
break;
case 114:
break;
case 115:
offset=dissect_gsm_ss_LCS_MOLRRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 116:
offset=dissect_gsm_ss_LocationNotificationRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 117:
break;
case 118:
break;
case 119:
offset=dissect_gsm_map_ss_RegisterCC_EntryRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 120:
break;
case 121:
break;
case 122:
break;
case 123:
break;
case 124:
break;
case 125:
break;
case 126:
break;
default:
if(!dissector_try_uint(map_prop_res_opcode_table, (guint8)opcode, tvb, actx->pinfo, tree)){
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown returnResultData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown invokeData %d",opcode);
}
offset+= tvb_length_remaining(tvb,offset);
break;
}
return offset;
}
static int dissect_returnErrorData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
proto_item *cause;
switch(errorCode){
case 1:
offset=dissect_gsm_map_er_UnknownSubscriberParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 4:
offset=dissect_gsm_old_SecureTransportErrorParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 5:
offset=dissect_gsm_map_er_UnidentifiedSubParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 6:
offset=dissect_gsm_map_er_AbsentSubscriberSM_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 8:
offset=dissect_gsm_map_er_RoamingNotAllowedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 9:
offset=dissect_gsm_map_er_IllegalSubscriberParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 10:
offset=dissect_gsm_map_er_BearerServNotProvParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 11:
offset=dissect_gsm_map_er_TeleservNotProvParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 12:
offset=dissect_gsm_map_er_IllegalEquipmentParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 13:
offset=dissect_gsm_map_er_CallBarredParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 14:
offset=dissect_gsm_map_er_ForwardingViolationParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 15:
offset=dissect_gsm_map_er_CUG_RejectParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 16:
offset=dissect_gsm_map_er_IllegalSS_OperationParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 17:
offset=dissect_gsm_map_ss_SS_Status(FALSE, tvb, offset, actx, tree, hf_gsm_map_ss_ss_Status);
break;
case 18:
offset=dissect_gsm_map_er_SS_NotAvailableParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 19:
offset=dissect_gsm_map_er_SS_SubscriptionViolationParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 20:
offset=dissect_gsm_map_er_SS_IncompatibilityCause(FALSE, tvb, offset, actx, tree, -1);
break;
case 21:
offset=dissect_gsm_map_er_FacilityNotSupParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 22:
offset=dissect_gsm_map_er_OngoingGroupCallParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 27:
offset=dissect_gsm_map_er_AbsentSubscriberParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 28:
offset=dissect_gsm_map_er_IncompatibleTerminalParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 29:
offset=dissect_gsm_map_er_ShortTermDenialParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 30:
offset=dissect_gsm_map_er_LongTermDenialParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 31:
offset=dissect_gsm_map_er_SubBusyForMT_SMS_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 32:
offset=dissect_gsm_map_er_SM_DeliveryFailureCause(FALSE, tvb, offset, actx, tree, -1);
break;
case 33:
offset=dissect_gsm_map_er_MessageWaitListFullParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 34:
offset=dissect_gsm_map_er_SystemFailureParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 35:
offset=dissect_gsm_map_er_DataMissingParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 36:
offset=dissect_gsm_map_er_UnexpectedDataParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 37:
offset=dissect_gsm_map_er_PW_RegistrationFailureCause(FALSE, tvb, offset, actx, tree, -1);
break;
case 39:
offset=dissect_gsm_map_er_NoRoamingNbParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 40:
offset=dissect_gsm_map_er_TracingBufferFullParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 42:
offset=dissect_gsm_map_er_TargetCellOutsideGCA_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 44:
offset=dissect_gsm_map_er_NumberChangedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 45:
offset=dissect_gsm_map_er_BusySubscriberParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 46:
offset=dissect_gsm_map_er_NoSubscriberReplyParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 47:
offset=dissect_gsm_map_er_ForwardingFailedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 48:
offset=dissect_gsm_map_er_OR_NotAllowedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 49:
offset=dissect_gsm_map_er_ATI_NotAllowedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 50:
offset=dissect_gsm_map_er_NoGroupCallNbParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 51:
offset=dissect_gsm_map_er_ResourceLimitationParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 52:
offset=dissect_gsm_map_er_UnauthorizedRequestingNetwork_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 53:
offset=dissect_gsm_map_er_UnauthorizedLCSClient_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 54:
offset=dissect_gsm_map_er_PositionMethodFailure_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 58:
offset=dissect_gsm_map_er_UnknownOrUnreachableLCSClient_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 59:
offset=dissect_gsm_map_er_MM_EventNotSupported_Param(FALSE, tvb, offset, actx, tree, -1);
break;
case 60:
offset=dissect_gsm_map_er_ATSI_NotAllowedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 61:
offset=dissect_gsm_map_er_ATM_NotAllowedParam(FALSE, tvb, offset, actx, tree, -1);
break;
case 62:
offset=dissect_gsm_map_er_InformationNotAvailableParam(FALSE, tvb, offset, actx, tree, -1);
break;
default:
if(!dissector_try_uint(map_prop_err_opcode_table, (guint8)opcode, tvb, actx->pinfo, tree)){
cause=proto_tree_add_text(tree, tvb, offset, -1, "Unknown returnErrorData blob");
proto_item_set_expert_flags(cause, PI_MALFORMED, PI_WARN);
expert_add_info_format(actx->pinfo, cause, PI_MALFORMED, PI_WARN, "Unknown invokeData %d",errorCode);
}
offset+= tvb_length_remaining(tvb,offset);
break;
}
return offset;
}
static void dissect_gsm_mapext_PlmnContainer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, 0, -1, "MAP Ext. Plmn Container");
tree = proto_item_add_subtree(item, ett_gsm_old_PlmnContainer_U);
}
dissect_gsm_old_PlmnContainer(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static int
dissect_gsm_map_GSMMAPPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_) {
char *version_ptr;
struct tcap_private_t * p_private_tcap;
opcode = 0;
if (pref_application_context_version == APPLICATON_CONTEXT_FROM_TRACE) {
application_context_version = 0;
if (actx->pinfo->private_data != NULL){
p_private_tcap = (struct tcap_private_t *)actx->pinfo->private_data;
if (p_private_tcap->acv==TRUE ){
version_ptr = strrchr((const char*)p_private_tcap->oid,'.');
if (version_ptr){
application_context_version = atoi(version_ptr+1);
}
}
}
}else{
application_context_version = pref_application_context_version;
}
gsmmap_pdu_type = tvb_get_guint8(tvb, offset)&0x0f;
gsm_map_pdu_size = tvb_get_guint8(tvb, offset+1)+2;
col_add_str(actx->pinfo->cinfo, COL_INFO, val_to_str_const(gsmmap_pdu_type, gsm_old_Component_vals, "Unknown GSM-MAP Component"));
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " ");
offset = dissect_gsm_old_Component(FALSE, tvb, 0, actx, tree, hf_gsm_map_old_Component_PDU);
return offset;
}
static void
dissect_gsm_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
static gsm_map_tap_rec_t tap_rec;
gint op_idx;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM MAP");
top_tree = parent_tree;
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_gsm_map, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_gsm_map);
}
dissect_gsm_map_GSMMAPPDU(FALSE, tvb, 0, &asn1_ctx, tree, -1);
try_val_to_str_idx(opcode, gsm_map_opr_code_strings, &op_idx);
if (op_idx != -1) {
tap_rec.invoke = (gsmmap_pdu_type == 1) ? TRUE : FALSE;
tap_rec.opr_code_idx = op_idx;
tap_rec.size = gsm_map_pdu_size;
tap_queue_packet(gsm_map_tap, pinfo, &tap_rec);
}
}
static void range_delete_callback(guint32 ssn)
{
if (ssn) {
delete_itu_tcap_subdissector(ssn, map_handle);
}
}
static void range_add_callback(guint32 ssn)
{
if (ssn) {
add_itu_tcap_subdissector(ssn, map_handle);
}
}
void proto_reg_handoff_gsm_map(void) {
static gboolean map_prefs_initialized = FALSE;
static range_t *ssn_range;
if (!map_prefs_initialized) {
map_prefs_initialized = TRUE;
data_handle = find_dissector("data");
ranap_handle = find_dissector("ranap");
dtap_handle = find_dissector("gsm_a_dtap");
map_handle = find_dissector("gsm_map");
oid_add_from_string("itu(0) administration(2) japan(440)","0.2.440" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.1.3", map_handle, proto_gsm_map,"networkLocUpContext-v3");
register_ber_oid_dissector_handle("0.4.0.0.1.0.1.2", map_handle, proto_gsm_map,"networkLocUpContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.1.1", map_handle, proto_gsm_map,"networkLocUpContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.2.3", map_handle, proto_gsm_map,"locationCancellationContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.2.2", map_handle, proto_gsm_map,"locationCancellationContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.2.1", map_handle, proto_gsm_map,"locationCancellationContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.3.3", map_handle, proto_gsm_map,"roamingNumberEnquiryContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.3.2", map_handle, proto_gsm_map,"roamingNumberEnquiryContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.3.1", map_handle, proto_gsm_map,"roamingNumberEnquiryContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.4.3", map_handle, proto_gsm_map,"istAlertingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.5.3", map_handle, proto_gsm_map,"locationInfoRetrievalContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.5.2", map_handle, proto_gsm_map,"locationInfoRetrievalContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.5.1", map_handle, proto_gsm_map,"locationInfoRetrievalContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.6.4", map_handle, proto_gsm_map,"callControlTransferContext-v4" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.6.3", map_handle, proto_gsm_map,"callControlTransferContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.7.3", map_handle, proto_gsm_map,"reportingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.8.3", map_handle, proto_gsm_map,"callCompletionContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.9.3", map_handle, proto_gsm_map,"serviceTerminationContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.10.2", map_handle, proto_gsm_map,"resetContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.10.1", map_handle, proto_gsm_map,"resetContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.11.3", map_handle, proto_gsm_map,"handoverControlContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.11.2", map_handle, proto_gsm_map,"handoverControlContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.11.1", map_handle, proto_gsm_map,"handoverControlContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.12.3", map_handle, proto_gsm_map,"sIWFSAllocationContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.13.3", map_handle, proto_gsm_map,"equipmentMngtContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.13.2", map_handle, proto_gsm_map,"equipmentMngtContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.13.1", map_handle, proto_gsm_map,"equipmentMngtContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.14.3", map_handle, proto_gsm_map,"infoRetrievalContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.14.2", map_handle, proto_gsm_map,"infoRetrievalContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.14.1", map_handle, proto_gsm_map,"infoRetrievalContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.15.2", map_handle, proto_gsm_map,"interVlrInfoRetrievalContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.15.3", map_handle, proto_gsm_map,"interVlrInfoRetrievalContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.16.3", map_handle, proto_gsm_map,"subscriberDataMngtContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.16.2", map_handle, proto_gsm_map,"subscriberDataMngtContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.16.1", map_handle, proto_gsm_map,"subscriberDataMngtContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.17.3", map_handle, proto_gsm_map,"tracingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.17.2", map_handle, proto_gsm_map,"tracingContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.17.1", map_handle, proto_gsm_map,"tracingContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.18.2", map_handle, proto_gsm_map,"networkFunctionalSsContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.18.1", map_handle, proto_gsm_map,"networkFunctionalSsContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.19.2", map_handle, proto_gsm_map,"networkUnstructuredSsContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.20.3", map_handle, proto_gsm_map,"shortMsgGatewayContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.20.2", map_handle, proto_gsm_map,"shortMsgGatewayContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.20.1", map_handle, proto_gsm_map,"shortMsgGatewayContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.21.3", map_handle, proto_gsm_map,"shortMsgMO-RelayContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.21.2", map_handle, proto_gsm_map,"shortMsgMO-RelayContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.21.1", map_handle, proto_gsm_map,"shortMsgRelayContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.22.3", map_handle, proto_gsm_map,"subscriberDataModificationNotificationContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.23.2", map_handle, proto_gsm_map,"shortMsgAlertContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.23.1", map_handle, proto_gsm_map,"shortMsgAlertContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.24.3", map_handle, proto_gsm_map,"mwdMngtContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.24.2", map_handle, proto_gsm_map,"mwdMngtContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.24.1", map_handle, proto_gsm_map,"mwdMngtContext-v1" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.25.3", map_handle, proto_gsm_map,"shortMsgMT-RelayContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.25.2", map_handle, proto_gsm_map,"shortMsgMT-RelayContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.26.2", map_handle, proto_gsm_map,"imsiRetrievalContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.27.2", map_handle, proto_gsm_map,"msPurgingContext-v2" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.27.3", map_handle, proto_gsm_map,"msPurgingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.28.3", map_handle, proto_gsm_map,"subscriberInfoEnquiryContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.29.3", map_handle, proto_gsm_map,"anyTimeInfoEnquiryContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.31.3", map_handle, proto_gsm_map,"groupCallControlContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.32.3", map_handle, proto_gsm_map,"gprsLocationUpdateContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.33.4", map_handle, proto_gsm_map,"gprsLocationInfoRetrievalContext-v4" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.33.3", map_handle, proto_gsm_map,"gprsLocationInfoRetrievalContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.34.3", map_handle, proto_gsm_map,"failureReportContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.35.3", map_handle, proto_gsm_map,"gprsNotifyContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.36.3", map_handle, proto_gsm_map,"ss-InvocationNotificationContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.37.3", map_handle, proto_gsm_map,"locationSvcGatewayContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.38.3", map_handle, proto_gsm_map,"locationSvcEnquiryContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.39.3", map_handle, proto_gsm_map,"authenticationFailureReportContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.40.3", map_handle, proto_gsm_map,"secureTransportHandlingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.41.3", map_handle, proto_gsm_map,"shortMsgMT-Relay-VGCS-Context-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.42.3", map_handle, proto_gsm_map,"mm-EventReportingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.43.3", map_handle, proto_gsm_map,"anyTimeInfoHandlingContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.44.3", map_handle, proto_gsm_map,"resourceManagementContext-v3" );
register_ber_oid_dissector_handle("0.4.0.0.1.0.45.3", map_handle, proto_gsm_map,"groupCallInfoRetrievalContext-v3" );
register_ber_oid_dissector("1.3.12.2.1006.53.2.1.3", dissect_gsm_mapext_PlmnContainer, proto_gsm_map,"alcatel-E10-MAP-extension-PlmnContainer" );
}
else {
range_foreach(ssn_range, range_delete_callback);
g_free(ssn_range);
}
ssn_range = range_copy(global_ssn_range);
range_foreach(ssn_range, range_add_callback);
}
void proto_register_gsm_map(void) {
module_t *gsm_map_module;
static hf_register_info hf[] = {
{ &hf_gsm_map_old_Component_PDU,
{ "Component", "gsm_map.old.Component",
FT_UINT32, BASE_DEC, VALS(gsm_old_Component_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_getPassword,
{ "getPassword", "gsm_map.getPassword",
FT_UINT8, BASE_DEC, VALS(gsm_old_GetPasswordArg_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_currentPassword,
{ "currentPassword", "gsm_map.currentPassword",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_extension,
{ "Extension", "gsm_map.extension",
FT_BOOLEAN, 8, TFS(&gsm_map_extension_value), 0x80,
NULL, HFILL }},
{ &hf_gsm_map_nature_of_number,
{ "Nature of number", "gsm_map.nature_of_number",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &gsm_map_nature_of_number_values_ext, 0x70,
NULL, HFILL }},
{ &hf_gsm_map_number_plan,
{ "Number plan", "gsm_map.number_plan",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &gsm_map_number_plan_values_ext, 0x0f,
NULL, HFILL }},
{ &hf_gsm_map_isdn_address_digits,
{ "ISDN Address digits", "gsm_map.isdn.address.digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_address_digits,
{ "Address digits", "gsm_map.address.digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_servicecentreaddress_digits,
{ "ServiceCentreAddress digits", "gsm_map.servicecentreaddress_digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_TBCD_digits,
{ "TBCD digits", "gsm_map.tbcd_digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_Ss_Status_unused,
{ "Unused", "gsm_map.unused",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }},
{ &hf_gsm_map_Ss_Status_q_bit,
{ "Q bit", "gsm_map.ss_status_q_bit",
FT_BOOLEAN, 8, TFS(&gsm_map_Ss_Status_q_bit_values), 0x08,
NULL, HFILL }},
{ &hf_gsm_map_Ss_Status_p_bit,
{ "P bit", "gsm_map.ss_status_p_bit",
FT_BOOLEAN, 8, TFS(&gsm_map_Ss_Status_p_values), 0x04,
NULL, HFILL }},
{ &hf_gsm_map_Ss_Status_r_bit,
{ "R bit", "gsm_map.ss_status_r_bit",
FT_BOOLEAN, 8, TFS(&gsm_map_Ss_Status_r_values), 0x02,
NULL, HFILL }},
{ &hf_gsm_map_Ss_Status_a_bit,
{ "A bit", "gsm_map.ss_status_a_bit",
FT_BOOLEAN, 8, TFS(&gsm_map_Ss_Status_a_values), 0x01,
NULL, HFILL }},
{ &hf_gsm_map_notification_to_forwarding_party,
{ "Notification to forwarding party", "gsm_map.notification_to_forwarding_party",
FT_BOOLEAN, 8, TFS(&notification_value), 0x80,
NULL, HFILL }},
{ &hf_gsm_map_redirecting_presentation,
{ "Redirecting presentation", "gsm_map.redirecting_presentation",
FT_BOOLEAN, 8, TFS(&redirecting_presentation_value), 0x40,
NULL, HFILL }},
{ &hf_gsm_map_notification_to_calling_party,
{ "Notification to calling party", "gsm_map.notification_to_clling_party",
FT_BOOLEAN, 8, TFS(&notification_value), 0x20,
NULL, HFILL }},
{ &hf_gsm_map_forwarding_reason,
{ "Forwarding reason", "gsm_map.forwarding_reason",
FT_UINT8, BASE_HEX, VALS(forwarding_reason_values), 0x0c,
NULL, HFILL }},
{ &hf_gsm_map_pdp_type_org,
{ "PDP Type Organization", "gsm_map.pdp_type_org",
FT_UINT8, BASE_HEX, VALS(pdp_type_org_values), 0x0f,
NULL, HFILL }},
{ &hf_gsm_map_etsi_pdp_type_number,
{ "PDP Type Number", "gsm_map.pdp_type_number",
FT_UINT8, BASE_HEX, VALS(etsi_pdp_type_number_values), 0,
"ETSI PDP Type Number", HFILL }},
{ &hf_gsm_map_ietf_pdp_type_number,
{ "PDP Type Number", "gsm_map.ietf_pdp_type_number",
FT_UINT8, BASE_HEX, VALS(ietf_pdp_type_number_values), 0,
"IETF PDP Type Number", HFILL }},
{ &hf_gsm_map_ext_qos_subscribed_pri,
{ "Allocation/Retention priority", "gsm_map.ext_qos_subscribed_pri",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }},
{ &hf_gsm_map_qos_traffic_cls,
{ "Traffic class", "gsm_map.qos.traffic_cls",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traffic_cls_vals), 0xe0,
NULL, HFILL }},
{ &hf_gsm_map_qos_del_order,
{ "Delivery order", "gsm_map.qos.del_order",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traffic_cls_vals), 0x18,
NULL, HFILL }},
{ &hf_gsm_map_qos_del_of_err_sdu,
{ "Delivery of erroneous SDUs", "gsm_map.qos.del_of_err_sdu",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_del_of_err_sdu_vals), 0x03,
NULL, HFILL }},
{ &hf_gsm_map_qos_ber,
{ "Residual Bit Error Rate (BER)", "gsm_map.qos.ber",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_ber_vals), 0xf0,
NULL, HFILL }},
{ &hf_gsm_map_qos_sdu_err_rat,
{ "SDU error ratio", "gsm_map.qos.sdu_err_rat",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_sdu_err_rat_vals), 0x0f,
NULL, HFILL }},
{ &hf_gsm_map_qos_traff_hdl_pri,
{ "Traffic handling priority", "gsm_map.qos.traff_hdl_pri",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traff_hdl_pri_vals), 0x03,
NULL, HFILL }},
{ &hf_gsm_map_qos_max_sdu,
{ "Maximum SDU size", "gsm_map.qos.max_sdu",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gsm_map_max_brate_ulink,
{ "Maximum bit rate for uplink in kbit/s", "gsm_map.qos.max_brate_ulink",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Maximum bit rate for uplink", HFILL }},
{ &hf_gsm_map_max_brate_dlink,
{ "Maximum bit rate for downlink in kbit/s", "gsm_map.qos.max_brate_dlink",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Maximum bit rate for downlink", HFILL }},
{ &hf_gsm_map_qos_transfer_delay,
{ "Transfer delay (Raw data see TS 24.008 for interpretation)", "gsm_map.qos.transfer_delay",
FT_UINT8, BASE_DEC, NULL, 0xfc,
"Transfer delay", HFILL }},
{ &hf_gsm_map_guaranteed_max_brate_ulink,
{ "Guaranteed bit rate for uplink in kbit/s", "gsm_map.qos.brate_ulink",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Guaranteed bit rate for uplink", HFILL }},
{ &hf_gsm_map_guaranteed_max_brate_dlink,
{ "Guaranteed bit rate for downlink in kbit/s", "gsm_map.qos.brate_dlink",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Guaranteed bit rate for downlink", HFILL }},
{ &hf_gsm_map_GSNAddress_IPv4,
{ "GSN-Address IPv4", "gsm_map.gsnaddress_ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPAddress IPv4", HFILL }},
{ &hf_gsm_map_GSNAddress_IPv6,
{ "GSN Address IPv6", "gsm_map.gsnaddress_ipv6",
FT_IPv4, BASE_NONE, NULL, 0,
"IPAddress IPv6", HFILL }},
{ &hf_gsm_map_ranap_service_Handover,
{ "service-Handover", "gsm_map.ranap.service_Handover",
FT_UINT32, BASE_DEC, VALS(ranap_Service_Handover_vals), 0,
"gsm_map.ranap.Service_Handover", HFILL }},
{ &hf_gsm_map_IntegrityProtectionInformation,
{ "IntegrityProtectionInformation", "gsm_map.ranap.IntegrityProtectionInformation",
FT_NONE, BASE_NONE, NULL, 0,
"gsm_map.ranap.IntegrityProtectionInformation", HFILL }},
{ &hf_gsm_map_EncryptionInformation,
{ "EncryptionInformation", "gsm_map.ranap.EncryptionInformation",
FT_NONE, BASE_NONE, NULL, 0,
"gsm_map.ranap.EncryptionInformation", HFILL }},
{ &hf_gsm_map_PlmnContainer_PDU,
{ "PlmnContainer", "gsm_map.PlmnContainer",
FT_NONE, BASE_NONE, NULL, 0,
"gsm_map.PlmnContainer", HFILL }},
{ &hf_gsm_map_ss_SS_UserData,
{ "SS-UserData", "gsm_ss.SS_UserData",
FT_STRING, BASE_NONE, NULL, 0,
"gsm_map.ss.SS_UserData", HFILL }},
{ &hf_gsm_map_cbs_coding_grp,
{ "Coding Group","gsm_map.cbs.coding_grp",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_map_cbs_data_coding_scheme_coding_grp_vals_ext, 0xf0,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp0_lang,
{ "Language","gsm_map.cbs.coding_grp0_lang",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_map_cbs_coding_grp0_lang_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp1_lang,
{ "Language","gsm_map.cbs.coding_grp1_lang",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_map_cbs_coding_grp1_lang_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp2_lang,
{ "Language","gsm_map.cbs.coding_grp2_lang",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_map_cbs_coding_grp2_lang_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp3_lang,
{ "Language","gsm_map.cbs.coding_grp3_lang",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_map_cbs_coding_grp3_lang_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp4_7_comp,
{ "Compressed indicator","gsm_map.cbs.coding_grp4_7_comp",
FT_BOOLEAN, 8, TFS(&gsm_map_cbs_coding_grp4_7_comp_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp4_7_class_ind,
{ "Message Class present","gsm_map.cbs.coding_grp4_7_class_ind",
FT_BOOLEAN, 8, TFS(&gsm_map_cbs_coding_grp4_7_class_ind_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp4_7_char_set,
{ "Character set being used","gsm_map.cbs.coding_grp4_7_char_set",
FT_UINT8,BASE_DEC, VALS(gsm_map_cbs_coding_grp4_7_char_set_vals), 0x0c,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp4_7_class,
{ "Message Class","gsm_map.cbs.coding_grp4_7_class",
FT_UINT8,BASE_DEC, VALS(gsm_map_cbs_coding_grp4_7_class_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp15_mess_code,
{ "Message coding","gsm_map.cbs.cbs_coding_grp15_mess_code",
FT_UINT8,BASE_DEC, VALS(gsm_map_cbs_coding_grp15_mess_code_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_map_cbs_coding_grp15_class,
{ "Message Class","gsm_map.cbs.gsm_map_cbs_coding_grp15_class",
FT_UINT8,BASE_DEC, VALS(gsm_map_cbs_coding_grp15_class_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_map_tmsi,
{ "tmsi", "gsm_map.tmsi",
FT_BYTES, BASE_NONE, NULL, 0,
"gsm_map.TMSI", HFILL }},
{ &hf_gsm_map_ie_tag,
{ "Tag", "gsm_map.ie_tag",
FT_UINT8, BASE_DEC, VALS(gsm_map_tag_vals), 0,
"GSM 04.08 tag", HFILL }},
{ &hf_gsm_map_len,
{ "Length", "gsm_map.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_disc_par,
{ "Discrimination parameter", "gsm_map.disc_par",
FT_UINT8, BASE_DEC, VALS(gsm_map_disc_par_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_dlci,
{ "DLCI", "gsm_map.dlci",
FT_UINT8, BASE_DEC, NULL, 0,
"Data Link Connection Indicator", HFILL }},
{ &hf_gsm_apn_str,
{ "APN", "gsm_map.apn_str",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_odd_even,
{ "Odd/Even", "gsm_map.locationnumber.odd_even",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_nai,
{ "Nature of address indicator", "gsm_map.locationnumber.nai",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(gsm_map_na_vals), 0x3f,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_inn,
{ "Internal Network Number indicator (INN)", "gsm_map.locationnumber.inn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_npi,
{ "Numbering plan indicator", "gsm_map.locationnumber.npi",
FT_UINT8, BASE_DEC, VALS(gsm_map_np_vals), 0x30,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_apri,
{ "Address presentation restricted indicator", "gsm_map.locationnumber.apri",
FT_UINT8, BASE_DEC, VALS(gsm_map_addr_pres_rest_vals), 0x0c,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_screening_ind,
{ "Screening indicator", "gsm_map.locationnumber.screening_ind",
FT_UINT8, BASE_DEC, VALS(gsm_map_screening_ind_vals), 0x03,
NULL, HFILL }},
{ &hf_gsm_map_locationnumber_digits,
{ "Address digits", "gsm_map.locationnumber.digits",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ericsson_locationInformation_rat,
{ "RAT", "gsm_map.ericsson.locationInformation.rat",
FT_UINT8, BASE_DEC, VALS(gsm_map_ericsson_locationInformation_rat_vals), 0,
"Radio Access Technology", HFILL }},
{ &hf_gsm_map_ericsson_locationInformation_lac,
{ "LAC", "gsm_map.ericsson.locationInformation.lac",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
"Location Area Code", HFILL }},
{ &hf_gsm_map_ericsson_locationInformation_ci,
{ "CI", "gsm_map.ericsson.locationInformation.ci",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
"Cell Identity", HFILL }},
{ &hf_gsm_map_ericsson_locationInformation_sac,
{ "SAC", "gsm_map.ericsson.locationInformation.sac",
FT_UINT16, BASE_DEC_HEX, NULL, 0,
"Service Area Code", HFILL }},
#include "packet-gsm_map-hfarr.c"
};
static gint *ett[] = {
&ett_gsm_map,
&ett_gsm_map_InvokeId,
&ett_gsm_map_InvokePDU,
&ett_gsm_map_ReturnResultPDU,
&ett_gsm_map_ReturnErrorPDU,
&ett_gsm_map_ReturnResult_result,
&ett_gsm_map_ReturnError_result,
&ett_gsm_map_GSMMAPPDU,
&ett_gsm_map_ext_qos_subscribed,
&ett_gsm_map_pdptypenumber,
&ett_gsm_map_RAIdentity,
&ett_gsm_map_LAIFixedLength,
&ett_gsm_map_isdn_address_string,
&ett_gsm_map_geo_desc,
&ett_gsm_map_LongSignalInfo,
&ett_gsm_map_RadioResourceInformation,
&ett_gsm_map_MSNetworkCapability,
&ett_gsm_map_MSRadioAccessCapability,
&ett_gsm_map_externalsignalinfo,
&ett_gsm_map_cbs_data_coding,
&ett_gsm_map_GlobalCellId,
&ett_gsm_map_GeographicalInformation,
&ett_gsm_map_apn_str,
&ett_gsm_map_LocationNumber,
&ett_gsm_map_ericsson_locationInformation,
#include "packet-gsm_map-ettarr.c"
};
static const enum_val_t application_context_modes[] = {
{"Use Application Context from the trace", "Use application context from the trace", APPLICATON_CONTEXT_FROM_TRACE},
{"Treat as AC 1", "Treat as AC 1", 1},
{"Treat as AC 2", "Treat as AC 2", 2},
{"Treat as AC 3", "Treat as AC 3", 3},
{NULL, NULL, -1}
};
proto_gsm_map_dialogue =proto_gsm_map = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("gsm_map", dissect_gsm_map, proto_gsm_map);
proto_register_field_array(proto_gsm_map, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sms_dissector_table = register_dissector_table("gsm_map.sms_tpdu",
"GSM SMS TPDU", FT_UINT8,
BASE_DEC);
map_prop_arg_opcode_table = register_dissector_table("gsm_map.prop.arg.opcode", "Proprietary Opcodes", FT_UINT8, BASE_DEC);
map_prop_res_opcode_table = register_dissector_table("gsm_map.prop.res.opcode", "Proprietary Opcodes", FT_UINT8, BASE_DEC);
map_prop_err_opcode_table = register_dissector_table("gsm_map.prop.err.opcode", "Proprietary Opcodes", FT_UINT8, BASE_DEC);
gsm_map_tap = register_tap("gsm_map");
#include "packet-gsm_map-dis-tab.c" */
oid_add_from_string("ericsson-gsm-Map-Ext","1.2.826.0.1249.58.1.0" );
oid_add_from_string("accessTypeNotAllowed-id","1.3.12.2.1107.3.66.1.2");
range_convert_str(&global_ssn_range, "6-9", MAX_SSN);
gsm_map_module = prefs_register_protocol(proto_gsm_map, proto_reg_handoff_gsm_map);
prefs_register_range_preference(gsm_map_module, "tcap.ssn", "TCAP SSNs",
"TCAP Subsystem numbers used for GSM MAP",
&global_ssn_range, MAX_SSN);
prefs_register_enum_preference(gsm_map_module, "application.context.version",
"Application context version",
"How to treat Application context",
&pref_application_context_version, application_context_modes, APPLICATON_CONTEXT_FROM_TRACE);
prefs_register_bool_preference(gsm_map_module, "ericsson.proprietary.extensions",
"Dissect Ericsson proprietary extensions",
"When enabled, dissector will use the non 3GPP standard extensions from Ericsson (that can override the standard ones)",
&pref_ericsson_proprietary_ext);
}
