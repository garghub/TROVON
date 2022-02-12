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
proto_tree_add_uint_format_value(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, octet, "Reserved");
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
proto_tree_add_uint_format_value(subtree, hf_gsm_map_qos_max_sdu, tvb, offset, 1, octet, "0x%x not defined in TS 24.008", octet);
}
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_uint_format_value(subtree, hf_gsm_map_max_brate_ulink, tvb, offset, 1, octet, "Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_max_brate_ulink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_uint_format_value(subtree, hf_gsm_map_max_brate_dlink, tvb, offset, 1, octet, "Reserved" );
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
proto_tree_add_uint_format_value(subtree, hf_gsm_map_guaranteed_max_brate_ulink, tvb, offset, 1, octet, "Reserved" );
}else{
proto_tree_add_uint(subtree, hf_gsm_map_guaranteed_max_brate_ulink, tvb, offset, 1, gsm_map_calc_bitrate(octet));
}
offset++;
octet = tvb_get_guint8(tvb,offset);
if (octet == 0 ){
proto_tree_add_uint_format_value(subtree, hf_gsm_map_guaranteed_max_brate_dlink, tvb, offset, 1, octet, "Reserved" );
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
dissect_gsm_map_msisdn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const char *digit_str;
guint8 octet;
guint8 na;
guint8 np;
proto_tree_add_item(tree, hf_gsm_map_extension, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_nature_of_number, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_number_plan, tvb, 0,1,ENC_BIG_ENDIAN);
if(tvb_reported_length(tvb)==1)
return;
octet = tvb_get_guint8(tvb,0);
na = (octet & 0x70)>>4;
np = octet & 0x0f;
switch(np){
case 1:
switch(na){
case 1:
dissect_e164_msisdn(tvb, tree, 1, tvb_reported_length(tvb)-1, E164_ENC_BCD);
break;
default:
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, 1, -1, NULL, FALSE);
proto_tree_add_string(tree, hf_gsm_map_address_digits, tvb, 1, -1, digit_str);
break;
}
break;
case 6:
dissect_e212_imsi(tvb, pinfo, tree, 1, tvb_reported_length(tvb)-1, FALSE);
break;
default:
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, 1, -1, NULL, FALSE);
proto_tree_add_string(tree, hf_gsm_map_address_digits, tvb, 1, -1, digit_str);
break;
}
}
int
dissect_gsm_map_SS_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_BearerServiceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_Ext_BearerServiceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_TeleserviceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_Ext_TeleserviceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_T_extId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 227 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
actx->external.direct_ref_present = (actx->external.direct_reference != NULL) ? TRUE : FALSE;
return offset;
}
static int
dissect_gsm_map_T_extType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 231 "../../asn1/gsm_map/gsm_map.cnf"
proto_tree *ext_tree;
ext_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_gsm_map_extention_data, NULL, "Extension Data");
if (actx->external.direct_ref_present){
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, ext_tree, NULL);
}else{
call_dissector(data_handle, tvb, actx->pinfo, ext_tree);
offset = tvb_reported_length_remaining(tvb,offset);
}
return offset;
}
static int
dissect_gsm_map_PrivateExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_PrivateExtension_sequence, hf_index, ett_gsm_map_PrivateExtension);
return offset;
}
static int
dissect_gsm_map_PrivateExtensionList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_PrivateExtensionList_sequence_of, hf_index, ett_gsm_map_PrivateExtensionList);
return offset;
}
static int
dissect_gsm_map_PCS_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_PCS_Extensions_sequence, hf_index, ett_gsm_map_PCS_Extensions);
return offset;
}
int
dissect_gsm_map_ExtensionContainer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ExtensionContainer_sequence, hf_index, ett_gsm_map_ExtensionContainer);
return offset;
}
static int
dissect_gsm_map_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_SLR_Arg_PCS_Extensions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_SLR_Arg_PCS_Extensions_sequence, hf_index, ett_gsm_map_SLR_Arg_PCS_Extensions);
return offset;
}
static int
dissect_gsm_map_SLR_ArgExtensionContainer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_SLR_ArgExtensionContainer_sequence, hf_index, ett_gsm_map_SLR_ArgExtensionContainer);
return offset;
}
int
dissect_gsm_map_TBCD_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 273 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
const char *digit_str;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
if(tvb_reported_length(parameter_tvb)==0)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_tbcd_digits);
digit_str = tvb_bcd_dig_to_wmem_packet_str(parameter_tvb, 0, -1, NULL, FALSE);
proto_tree_add_string(subtree, hf_gsm_map_TBCD_digits, parameter_tvb, 0, -1, digit_str);
return offset;
}
static int
dissect_gsm_map_DiameterIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_AddressString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 245 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_isdn_address_string);
dissect_gsm_map_msisdn(parameter_tvb, actx->pinfo , subtree);
return offset;
}
int
dissect_gsm_map_ISDN_AddressString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_FTN_AddressString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_gsm_map_ISDN_SubaddressString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ProtocolId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&ProtocolId);
return offset;
}
static int
dissect_gsm_map_SignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 380 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
actx->value_ptr = (void*)parameter_tvb;
return offset;
}
int
dissect_gsm_map_ExternalSignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 808 "../../asn1/gsm_map/gsm_map.cnf"
guint8 octet;
guint8 length;
tvbuff_t *next_tvb;
proto_tree *subtree;
ProtocolId = 0xffffffff;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ExternalSignalInfo_sequence, hf_index, ett_gsm_map_ExternalSignalInfo);
if (!actx->value_ptr)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_externalsignalinfo);
switch (ProtocolId){
case 1:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
proto_tree_add_item(subtree, hf_gsm_map_ie_tag, (tvbuff_t*)actx->value_ptr, 0,1,ENC_BIG_ENDIAN);
length = tvb_get_guint8((tvbuff_t*)actx->value_ptr,1);
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
switch(octet){
case 4:
de_bearer_cap((tvbuff_t*)actx->value_ptr, subtree, actx->pinfo, 2, length, NULL, 0);
break;
default:
proto_tree_add_expert(subtree, actx->pinfo, &ei_gsm_map_undecoded, (tvbuff_t*)actx->value_ptr, 0, length);
break;
}
break;
case 2:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
proto_tree_add_item(subtree, hf_gsm_map_disc_par, (tvbuff_t*)actx->value_ptr, 0,1,ENC_BIG_ENDIAN);
if ( octet == 0) {
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 2);
call_dissector_with_data(bssap_handle, next_tvb, actx->pinfo, subtree,
p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_gsm_map, actx->pinfo->curr_layer_num));
}else if(octet==1){
proto_tree_add_item(subtree, hf_gsm_map_dlci, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 2,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 3);
call_dissector(dtap_handle, next_tvb, actx->pinfo, subtree);
}
break;
case 3:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
if ( octet == 0) {
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 2);
call_dissector_with_data(bssap_handle, next_tvb, actx->pinfo, subtree,
p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_gsm_map, actx->pinfo->curr_layer_num));
}
break;
case 4:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
length = tvb_get_guint8((tvbuff_t*)actx->value_ptr,1);
if ( octet == 4 )
dissect_q931_bearer_capability_ie((tvbuff_t*)actx->value_ptr, 2, length, subtree);
break;
default:
break;
}
return offset;
}
static int
dissect_gsm_map_Ext_ProtocolId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_Ext_ExternalSignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_Ext_ExternalSignalInfo_sequence, hf_index, ett_gsm_map_Ext_ExternalSignalInfo);
return offset;
}
static int
dissect_gsm_map_AccessNetworkProtocolId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&AccessNetworkProtocolId);
return offset;
}
static int
dissect_gsm_map_LongSignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 296 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
guint8 octet;
tvbuff_t *next_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_LongSignalInfo);
switch (AccessNetworkProtocolId){
case 1:
octet = tvb_get_guint8(parameter_tvb,0);
proto_tree_add_item(subtree, hf_gsm_map_disc_par, parameter_tvb, 0,1,ENC_BIG_ENDIAN);
if ( octet == 0) {
proto_tree_add_item(subtree, hf_gsm_map_len, parameter_tvb, 1,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(parameter_tvb, 2);
call_dissector_with_data(bssap_handle, next_tvb, actx->pinfo, subtree,
p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_gsm_map, actx->pinfo->curr_layer_num));
}else if(octet==1){
proto_tree_add_item(subtree, hf_gsm_map_dlci, parameter_tvb, 1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_len, parameter_tvb, 2,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(parameter_tvb, 3);
call_dissector(dtap_handle, next_tvb, actx->pinfo, subtree);
}
break;
case 2:
call_dissector(ranap_handle, parameter_tvb, actx->pinfo, tree);
break;
default:
break;
}
return offset;
}
static int
dissect_gsm_map_AccessNetworkSignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_AccessNetworkSignalInfo_sequence, hf_index, ett_gsm_map_AccessNetworkSignalInfo);
return offset;
}
int
dissect_gsm_map_AlertingPattern(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_GSN_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 631 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
guint8 octet;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_pdptypenumber);
octet = tvb_get_guint8(parameter_tvb,0);
switch(octet){
case 0x04:
proto_tree_add_item(subtree, hf_gsm_map_GSNAddress_IPv4, parameter_tvb, 1, 4, ENC_BIG_ENDIAN);
break;
case 0x50:
proto_tree_add_item(subtree, hf_gsm_map_GSNAddress_IPv6, parameter_tvb, 1, 16, ENC_NA);
break;
default:
break;
}
return offset;
}
static int
dissect_gsm_map_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_IMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 258 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, &parameter_tvb);
if (!parameter_tvb)
return offset;
if(tvb_reported_length(parameter_tvb)==0)
return offset;
PROTO_ITEM_SET_HIDDEN(actx->created_item);
dissect_e212_imsi(parameter_tvb, actx->pinfo, tree, 0, tvb_reported_length(parameter_tvb), FALSE);
return offset;
}
static int
dissect_gsm_map_LMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_IMSI_WithLMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_IMSI_WithLMSI_sequence, hf_index, ett_gsm_map_IMSI_WithLMSI);
return offset;
}
static int
dissect_gsm_map_Identity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_Identity_choice, hf_index, ett_gsm_map_Identity,
NULL);
return offset;
}
static int
dissect_gsm_map_ASCI_CallReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_TMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_IMEI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_HLR_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_IMSI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_HLR_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_HLR_List_sequence_of, hf_index, ett_gsm_map_HLR_List);
return offset;
}
int
dissect_gsm_map_GlobalCellId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 890 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_GlobalCellId);
be_cell_id_aux(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length_remaining(tvb,0), NULL, 0, 0);
return offset;
}
int
dissect_gsm_map_NetworkResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_AdditionalNetworkResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_NAEA_CIC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_NAEA_PreferredCI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_NAEA_PreferredCI_sequence, hf_index, ett_gsm_map_NAEA_PreferredCI);
return offset;
}
static int
dissect_gsm_map_SubscriberIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_SubscriberIdentity_choice, hf_index, ett_gsm_map_SubscriberIdentity,
NULL);
return offset;
}
int
dissect_gsm_map_LCSClientExternalID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_LCSClientExternalID_sequence, hf_index, ett_gsm_map_LCSClientExternalID);
return offset;
}
int
dissect_gsm_map_LCSClientInternalID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_LCSServiceTypeID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_PLMN_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_E_UTRAN_CGI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_TA_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_RAIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 655 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_RAIdentity);
de_gmm_rai(parameter_tvb, subtree, actx->pinfo, 0, 3, NULL,0);
return offset;
}
static int
dissect_gsm_map_NetworkNodeDiameterAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_NetworkNodeDiameterAddress_sequence, hf_index, ett_gsm_map_NetworkNodeDiameterAddress);
return offset;
}
int
dissect_gsm_map_CellGlobalIdOrServiceAreaIdFixedLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_LAIFixedLength(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 667 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_LAIFixedLength);
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_LAI, TRUE);
return offset;
}
int
dissect_gsm_map_CellGlobalIdOrServiceAreaIdOrLAI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_CellGlobalIdOrServiceAreaIdOrLAI_choice, hf_index, ett_gsm_map_CellGlobalIdOrServiceAreaIdOrLAI,
NULL);
return offset;
}
int
dissect_gsm_map_BasicServiceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_BasicServiceCode_choice, hf_index, ett_gsm_map_BasicServiceCode,
NULL);
return offset;
}
int
dissect_gsm_map_Ext_BasicServiceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_Ext_BasicServiceCode_choice, hf_index, ett_gsm_map_Ext_BasicServiceCode,
NULL);
return offset;
}
static int
dissect_gsm_map_EMLPP_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_EMLPP_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_EMLPP_Info_sequence, hf_index, ett_gsm_map_EMLPP_Info);
return offset;
}
static int
dissect_gsm_map_Ext_SS_Status(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 507 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
guint8 octet;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
octet = tvb_get_guint8(parameter_tvb,0);
proto_tree_add_uint(tree, hf_gsm_map_Ss_Status_unused, parameter_tvb, 0,1,octet);
if ((octet & 0x01)== 1)
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_q_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_p_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_r_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_a_bit, parameter_tvb, 0,1,octet);
return offset;
}
static int
dissect_gsm_map_MaxMC_Bearers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_MC_Bearers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_MC_SS_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_MC_SS_Info_sequence, hf_index, ett_gsm_map_MC_SS_Info);
return offset;
}
int
dissect_gsm_map_AgeOfLocationInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int dissect_gsm_map_ISDN_AddressString_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_gsm_map_ISDN_AddressString(FALSE, tvb, offset, &asn1_ctx, tree, hf_gsm_map_gsm_map_ISDN_AddressString_PDU);
return offset;
}
static int
dissect_gsm_map_ss_NoReplyConditionTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_gsm_map_ss_RegisterSS_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_RegisterSS_Arg_sequence, hf_index, ett_gsm_map_ss_RegisterSS_Arg);
return offset;
}
int
dissect_gsm_map_ss_SS_Status(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 487 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
guint8 octet;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
octet = tvb_get_guint8(parameter_tvb,0);
proto_tree_add_uint(tree, hf_gsm_map_Ss_Status_unused, parameter_tvb, 0,1,octet);
if ((octet & 0x01)== 1)
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_q_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_p_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_r_bit, parameter_tvb, 0,1,octet);
proto_tree_add_boolean(tree, hf_gsm_map_Ss_Status_a_bit, parameter_tvb, 0,1,octet);
return offset;
}
int
dissect_gsm_map_ss_ForwardingOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#line 574 "../../asn1/gsm_map/gsm_map.cnf"
proto_tree_add_item(tree, hf_gsm_map_notification_to_forwarding_party, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_redirecting_presentation, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_notification_to_calling_party, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_forwarding_reason, tvb, 0,1,ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_gsm_map_ss_ForwardingFeature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_ForwardingFeature_sequence, hf_index, ett_gsm_map_ss_ForwardingFeature);
return offset;
}
static int
dissect_gsm_map_ss_ForwardingFeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_ForwardingFeatureList_sequence_of, hf_index, ett_gsm_map_ss_ForwardingFeatureList);
return offset;
}
static int
dissect_gsm_map_ss_ForwardingInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_ForwardingInfo_sequence, hf_index, ett_gsm_map_ss_ForwardingInfo);
return offset;
}
static int
dissect_gsm_map_ss_CallBarringFeature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CallBarringFeature_sequence, hf_index, ett_gsm_map_ss_CallBarringFeature);
return offset;
}
static int
dissect_gsm_map_ss_CallBarringFeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CallBarringFeatureList_sequence_of, hf_index, ett_gsm_map_ss_CallBarringFeatureList);
return offset;
}
static int
dissect_gsm_map_ss_CallBarringInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CallBarringInfo_sequence, hf_index, ett_gsm_map_ss_CallBarringInfo);
return offset;
}
static int
dissect_gsm_map_ss_CliRestrictionOption(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_OverrideCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_SS_SubscriptionOption(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ss_SS_SubscriptionOption_choice, hf_index, ett_gsm_map_ss_SS_SubscriptionOption,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_BasicServiceGroupList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_BasicServiceGroupList_sequence_of, hf_index, ett_gsm_map_ss_BasicServiceGroupList);
return offset;
}
static int
dissect_gsm_map_ss_SS_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_Data_sequence, hf_index, ett_gsm_map_ss_SS_Data);
return offset;
}
int
dissect_gsm_map_ss_SS_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ss_SS_Info_choice, hf_index, ett_gsm_map_ss_SS_Info,
NULL);
return offset;
}
int
dissect_gsm_map_ss_SS_ForBS_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_ForBS_Code_sequence, hf_index, ett_gsm_map_ss_SS_ForBS_Code);
return offset;
}
static int
dissect_gsm_map_ss_CCBS_Index(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ss_CCBS_Feature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CCBS_Feature_sequence, hf_index, ett_gsm_map_ss_CCBS_Feature);
return offset;
}
static int
dissect_gsm_map_ss_CCBS_FeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CCBS_FeatureList_sequence_of, hf_index, ett_gsm_map_ss_CCBS_FeatureList);
return offset;
}
static int
dissect_gsm_map_ss_GenericServiceInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_GenericServiceInfo_sequence, hf_index, ett_gsm_map_ss_GenericServiceInfo);
return offset;
}
int
dissect_gsm_map_ss_InterrogateSS_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ss_InterrogateSS_Res_choice, hf_index, ett_gsm_map_ss_InterrogateSS_Res,
NULL);
return offset;
}
int
dissect_gsm_map_ss_USSD_DataCodingScheme(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 530 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_cbs_data_coding);
dissect_cbs_data_coding_scheme(parameter_tvb, actx->pinfo, subtree, 0);
return offset;
}
int
dissect_gsm_map_ss_USSD_String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 545 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
guint length;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
length = tvb_ensure_captured_length_remaining(parameter_tvb,0);
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_ussd_string);
switch(sms_encoding){
case SMS_ENCODING_7BIT:
case SMS_ENCODING_7BIT_LANG:
proto_tree_add_string(subtree, hf_gsm_map_ussd_string, parameter_tvb, 0, length, tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 0, length, ENC_3GPP_TS_23_038_7BITS|ENC_NA));
break;
case SMS_ENCODING_8BIT:
proto_tree_add_string(subtree, hf_gsm_map_ussd_string, parameter_tvb, 0, length, tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 0, length, ENC_ASCII|ENC_NA));
break;
case SMS_ENCODING_UCS2:
case SMS_ENCODING_UCS2_LANG:
proto_tree_add_string(subtree, hf_gsm_map_ussd_string, parameter_tvb, 0, length, tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 0, length, ENC_UCS_2|ENC_BIG_ENDIAN));
break;
default:
break;
}
return offset;
}
int
dissect_gsm_map_ss_USSD_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_USSD_Arg_sequence, hf_index, ett_gsm_map_ss_USSD_Arg);
return offset;
}
int
dissect_gsm_map_ss_USSD_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_USSD_Res_sequence, hf_index, ett_gsm_map_ss_USSD_Res);
return offset;
}
static int
dissect_gsm_map_ss_Password(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_SS_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_List_sequence_of, hf_index, ett_gsm_map_ss_SS_List);
return offset;
}
static int
dissect_gsm_map_ss_SS_EventSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_EventSpecification_sequence_of, hf_index, ett_gsm_map_ss_SS_EventSpecification);
return offset;
}
static int
dissect_gsm_map_ss_CCBS_RequestState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_SS_InvocationNotificationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_InvocationNotificationArg_sequence, hf_index, ett_gsm_map_ss_SS_InvocationNotificationArg);
return offset;
}
static int
dissect_gsm_map_ss_SS_InvocationNotificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_SS_InvocationNotificationRes_sequence, hf_index, ett_gsm_map_ss_SS_InvocationNotificationRes);
return offset;
}
static int
dissect_gsm_map_ss_ServiceIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_ServiceIndicator_bits, hf_index, ett_gsm_map_ss_ServiceIndicator,
NULL);
return offset;
}
static int
dissect_gsm_map_ss_CCBS_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_CCBS_Data_sequence, hf_index, ett_gsm_map_ss_CCBS_Data);
return offset;
}
static int
dissect_gsm_map_ss_RegisterCC_EntryArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_RegisterCC_EntryArg_sequence, hf_index, ett_gsm_map_ss_RegisterCC_EntryArg);
return offset;
}
int
dissect_gsm_map_ss_RegisterCC_EntryRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_RegisterCC_EntryRes_sequence, hf_index, ett_gsm_map_ss_RegisterCC_EntryRes);
return offset;
}
int
dissect_gsm_map_ss_EraseCC_EntryArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_EraseCC_EntryArg_sequence, hf_index, ett_gsm_map_ss_EraseCC_EntryArg);
return offset;
}
int
dissect_gsm_map_ss_EraseCC_EntryRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ss_EraseCC_EntryRes_sequence, hf_index, ett_gsm_map_ss_EraseCC_EntryRes);
return offset;
}
static int
dissect_gsm_map_er_RoamingNotAllowedCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_AdditionalRoamingNotAllowedCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_RoamingNotAllowedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_RoamingNotAllowedParam_sequence, hf_index, ett_gsm_map_er_RoamingNotAllowedParam);
return offset;
}
static int
dissect_gsm_map_er_CallBarringCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_er_ExtensibleCallBarredParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ExtensibleCallBarredParam_sequence, hf_index, ett_gsm_map_er_ExtensibleCallBarredParam);
return offset;
}
static int
dissect_gsm_map_er_CallBarredParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_er_CallBarredParam_choice, hf_index, ett_gsm_map_er_CallBarredParam,
NULL);
return offset;
}
static int
dissect_gsm_map_er_CUG_RejectCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_CUG_RejectParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_CUG_RejectParam_sequence, hf_index, ett_gsm_map_er_CUG_RejectParam);
return offset;
}
static int
dissect_gsm_map_er_SS_IncompatibilityCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_SS_IncompatibilityCause_sequence, hf_index, ett_gsm_map_er_SS_IncompatibilityCause);
return offset;
}
static int
dissect_gsm_map_er_PW_RegistrationFailureCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_SM_EnumeratedDeliveryFailureCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_SM_DeliveryFailureCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 387 "../../asn1/gsm_map/gsm_map.cnf"
guint8 oct;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_SM_DeliveryFailureCause_sequence, hf_index, ett_gsm_map_er_SM_DeliveryFailureCause);
if (!actx->value_ptr)
return offset;
oct = tvb_get_guint8((tvbuff_t*)actx->value_ptr, 0);
actx->pinfo->p2p_dir = ((oct & 0x03) == 0) ? P2P_DIR_RECV : P2P_DIR_SENT;
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_er_AbsentSubscriberDiagnosticSM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_AbsentSubscriberSM_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_AbsentSubscriberSM_Param_sequence, hf_index, ett_gsm_map_er_AbsentSubscriberSM_Param);
return offset;
}
static int
dissect_gsm_map_er_FailureCauseParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_ExtensibleSystemFailureParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ExtensibleSystemFailureParam_sequence, hf_index, ett_gsm_map_er_ExtensibleSystemFailureParam);
return offset;
}
static int
dissect_gsm_map_er_SystemFailureParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_er_SystemFailureParam_choice, hf_index, ett_gsm_map_er_SystemFailureParam,
NULL);
return offset;
}
static int
dissect_gsm_map_er_DataMissingParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_DataMissingParam_sequence, hf_index, ett_gsm_map_er_DataMissingParam);
return offset;
}
static int
dissect_gsm_map_er_UnexpectedDataParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnexpectedDataParam_sequence, hf_index, ett_gsm_map_er_UnexpectedDataParam);
return offset;
}
static int
dissect_gsm_map_er_FacilityNotSupParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_FacilityNotSupParam_sequence, hf_index, ett_gsm_map_er_FacilityNotSupParam);
return offset;
}
static int
dissect_gsm_map_er_OR_NotAllowedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_OR_NotAllowedParam_sequence, hf_index, ett_gsm_map_er_OR_NotAllowedParam);
return offset;
}
static int
dissect_gsm_map_er_UnknownSubscriberDiagnostic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_UnknownSubscriberParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnknownSubscriberParam_sequence, hf_index, ett_gsm_map_er_UnknownSubscriberParam);
return offset;
}
static int
dissect_gsm_map_er_NumberChangedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_NumberChangedParam_sequence, hf_index, ett_gsm_map_er_NumberChangedParam);
return offset;
}
static int
dissect_gsm_map_er_UnidentifiedSubParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnidentifiedSubParam_sequence, hf_index, ett_gsm_map_er_UnidentifiedSubParam);
return offset;
}
static int
dissect_gsm_map_er_IllegalSubscriberParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_IllegalSubscriberParam_sequence, hf_index, ett_gsm_map_er_IllegalSubscriberParam);
return offset;
}
static int
dissect_gsm_map_er_IllegalEquipmentParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_IllegalEquipmentParam_sequence, hf_index, ett_gsm_map_er_IllegalEquipmentParam);
return offset;
}
static int
dissect_gsm_map_er_BearerServNotProvParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_BearerServNotProvParam_sequence, hf_index, ett_gsm_map_er_BearerServNotProvParam);
return offset;
}
static int
dissect_gsm_map_er_TeleservNotProvParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_TeleservNotProvParam_sequence, hf_index, ett_gsm_map_er_TeleservNotProvParam);
return offset;
}
static int
dissect_gsm_map_er_TracingBufferFullParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_TracingBufferFullParam_sequence, hf_index, ett_gsm_map_er_TracingBufferFullParam);
return offset;
}
static int
dissect_gsm_map_er_NoRoamingNbParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_NoRoamingNbParam_sequence, hf_index, ett_gsm_map_er_NoRoamingNbParam);
return offset;
}
static int
dissect_gsm_map_er_AbsentSubscriberReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_AbsentSubscriberParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_AbsentSubscriberParam_sequence, hf_index, ett_gsm_map_er_AbsentSubscriberParam);
return offset;
}
static int
dissect_gsm_map_er_BusySubscriberParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_BusySubscriberParam_sequence, hf_index, ett_gsm_map_er_BusySubscriberParam);
return offset;
}
static int
dissect_gsm_map_er_NoSubscriberReplyParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_NoSubscriberReplyParam_sequence, hf_index, ett_gsm_map_er_NoSubscriberReplyParam);
return offset;
}
static int
dissect_gsm_map_er_ForwardingViolationParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ForwardingViolationParam_sequence, hf_index, ett_gsm_map_er_ForwardingViolationParam);
return offset;
}
static int
dissect_gsm_map_er_ForwardingFailedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ForwardingFailedParam_sequence, hf_index, ett_gsm_map_er_ForwardingFailedParam);
return offset;
}
static int
dissect_gsm_map_er_ATI_NotAllowedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ATI_NotAllowedParam_sequence, hf_index, ett_gsm_map_er_ATI_NotAllowedParam);
return offset;
}
static int
dissect_gsm_map_er_ATSI_NotAllowedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ATSI_NotAllowedParam_sequence, hf_index, ett_gsm_map_er_ATSI_NotAllowedParam);
return offset;
}
static int
dissect_gsm_map_er_ATM_NotAllowedParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ATM_NotAllowedParam_sequence, hf_index, ett_gsm_map_er_ATM_NotAllowedParam);
return offset;
}
static int
dissect_gsm_map_er_IllegalSS_OperationParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_IllegalSS_OperationParam_sequence, hf_index, ett_gsm_map_er_IllegalSS_OperationParam);
return offset;
}
static int
dissect_gsm_map_er_SS_NotAvailableParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_SS_NotAvailableParam_sequence, hf_index, ett_gsm_map_er_SS_NotAvailableParam);
return offset;
}
static int
dissect_gsm_map_er_SS_SubscriptionViolationParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_SS_SubscriptionViolationParam_sequence, hf_index, ett_gsm_map_er_SS_SubscriptionViolationParam);
return offset;
}
static int
dissect_gsm_map_er_InformationNotAvailableParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_InformationNotAvailableParam_sequence, hf_index, ett_gsm_map_er_InformationNotAvailableParam);
return offset;
}
static int
dissect_gsm_map_er_SubBusyForMT_SMS_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_SubBusyForMT_SMS_Param_sequence, hf_index, ett_gsm_map_er_SubBusyForMT_SMS_Param);
return offset;
}
static int
dissect_gsm_map_er_MessageWaitListFullParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_MessageWaitListFullParam_sequence, hf_index, ett_gsm_map_er_MessageWaitListFullParam);
return offset;
}
static int
dissect_gsm_map_er_ResourceLimitationParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ResourceLimitationParam_sequence, hf_index, ett_gsm_map_er_ResourceLimitationParam);
return offset;
}
static int
dissect_gsm_map_er_NoGroupCallNbParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_NoGroupCallNbParam_sequence, hf_index, ett_gsm_map_er_NoGroupCallNbParam);
return offset;
}
static int
dissect_gsm_map_er_IncompatibleTerminalParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_IncompatibleTerminalParam_sequence, hf_index, ett_gsm_map_er_IncompatibleTerminalParam);
return offset;
}
static int
dissect_gsm_map_er_ShortTermDenialParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_ShortTermDenialParam_sequence, hf_index, ett_gsm_map_er_ShortTermDenialParam);
return offset;
}
static int
dissect_gsm_map_er_LongTermDenialParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_LongTermDenialParam_sequence, hf_index, ett_gsm_map_er_LongTermDenialParam);
return offset;
}
static int
dissect_gsm_map_er_UnauthorizedRequestingNetwork_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnauthorizedRequestingNetwork_Param_sequence, hf_index, ett_gsm_map_er_UnauthorizedRequestingNetwork_Param);
return offset;
}
int
dissect_gsm_map_er_UnauthorizedLCSClient_Diagnostic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_UnauthorizedLCSClient_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnauthorizedLCSClient_Param_sequence, hf_index, ett_gsm_map_er_UnauthorizedLCSClient_Param);
return offset;
}
int
dissect_gsm_map_er_PositionMethodFailure_Diagnostic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_er_PositionMethodFailure_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_PositionMethodFailure_Param_sequence, hf_index, ett_gsm_map_er_PositionMethodFailure_Param);
return offset;
}
static int
dissect_gsm_map_er_UnknownOrUnreachableLCSClient_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_UnknownOrUnreachableLCSClient_Param_sequence, hf_index, ett_gsm_map_er_UnknownOrUnreachableLCSClient_Param);
return offset;
}
static int
dissect_gsm_map_er_MM_EventNotSupported_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_MM_EventNotSupported_Param_sequence, hf_index, ett_gsm_map_er_MM_EventNotSupported_Param);
return offset;
}
static int
dissect_gsm_map_er_TargetCellOutsideGCA_Param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_TargetCellOutsideGCA_Param_sequence, hf_index, ett_gsm_map_er_TargetCellOutsideGCA_Param);
return offset;
}
static int
dissect_gsm_map_er_OngoingGroupCallParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_er_OngoingGroupCallParam_sequence, hf_index, ett_gsm_map_er_OngoingGroupCallParam);
return offset;
}
static int
dissect_gsm_map_sm_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_map_sm_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_sm_SM_RP_MTI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_SM_RP_SMEA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_SM_DeliveryNotIntended(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_SIP_URI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_CorrelationID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_CorrelationID_sequence, hf_index, ett_gsm_map_sm_CorrelationID);
return offset;
}
static int
dissect_gsm_map_sm_RoutingInfoForSM_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_RoutingInfoForSM_Arg_sequence, hf_index, ett_gsm_map_sm_RoutingInfoForSM_Arg);
return offset;
}
static int
dissect_gsm_map_sm_Additional_Number(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_sm_Additional_Number_choice, hf_index, ett_gsm_map_sm_Additional_Number,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_LocationInfoWithLMSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_LocationInfoWithLMSI_sequence, hf_index, ett_gsm_map_sm_LocationInfoWithLMSI);
return offset;
}
static int
dissect_gsm_map_sm_SM_DeliveryTimerValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_IP_SM_GW_Guidance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_IP_SM_GW_Guidance_sequence, hf_index, ett_gsm_map_sm_IP_SM_GW_Guidance);
return offset;
}
static int
dissect_gsm_map_sm_RoutingInfoForSM_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_RoutingInfoForSM_Res_sequence, hf_index, ett_gsm_map_sm_RoutingInfoForSM_Res);
return offset;
}
static int
dissect_gsm_map_sm_T_imsi(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 356 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_IMSI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_sm_T_lmsi(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 360 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_LMSI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_sm_T_serviceCentreAddressDA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 376 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_RECV;
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_gsm_map_sm_SM_RP_DA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_sm_SM_RP_DA_choice, hf_index, ett_gsm_map_sm_SM_RP_DA,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_T_msisdn(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 368 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_RECV;
offset = dissect_gsm_map_ISDN_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_sm_T_serviceCentreAddressOA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 344 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_gsm_map_sm_SM_RP_OA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_sm_SM_RP_OA_choice, hf_index, ett_gsm_map_sm_SM_RP_OA,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_SM_DeliveryOutcome(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_MO_ForwardSM_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 415 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MO_ForwardSM_Arg_sequence, hf_index, ett_gsm_map_sm_MO_ForwardSM_Arg);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_RECV;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_sm_MO_ForwardSM_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 427 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MO_ForwardSM_Res_sequence, hf_index, ett_gsm_map_sm_MO_ForwardSM_Res);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_SENT;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_sm_MT_ForwardSM_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 439 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MT_ForwardSM_Arg_sequence, hf_index, ett_gsm_map_sm_MT_ForwardSM_Arg);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_SENT;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_sm_MT_ForwardSM_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 451 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MT_ForwardSM_Res_sequence, hf_index, ett_gsm_map_sm_MT_ForwardSM_Res);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_RECV;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_sm_ReportSM_DeliveryStatusArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_ReportSM_DeliveryStatusArg_sequence, hf_index, ett_gsm_map_sm_ReportSM_DeliveryStatusArg);
return offset;
}
static int
dissect_gsm_map_sm_ReportSM_DeliveryStatusRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_ReportSM_DeliveryStatusRes_sequence, hf_index, ett_gsm_map_sm_ReportSM_DeliveryStatusRes);
return offset;
}
static int
dissect_gsm_map_sm_AlertServiceCentreArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_AlertServiceCentreArg_sequence, hf_index, ett_gsm_map_sm_AlertServiceCentreArg);
return offset;
}
static int
dissect_gsm_map_sm_MW_Status(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MW_Status_bits, hf_index, ett_gsm_map_sm_MW_Status,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_InformServiceCentreArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_InformServiceCentreArg_sequence, hf_index, ett_gsm_map_sm_InformServiceCentreArg);
return offset;
}
static int
dissect_gsm_map_sm_AlertReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_sm_ReadyForSM_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_ReadyForSM_Arg_sequence, hf_index, ett_gsm_map_sm_ReadyForSM_Arg);
return offset;
}
static int
dissect_gsm_map_sm_ReadyForSM_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_ReadyForSM_Res_sequence, hf_index, ett_gsm_map_sm_ReadyForSM_Res);
return offset;
}
static int
dissect_gsm_map_sm_MT_ForwardSM_VGCS_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 463 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MT_ForwardSM_VGCS_Arg_sequence, hf_index, ett_gsm_map_sm_MT_ForwardSM_VGCS_Arg);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_SENT;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_sm_DispatcherList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_DispatcherList_sequence_of, hf_index, ett_gsm_map_sm_DispatcherList);
return offset;
}
static int
dissect_gsm_map_sm_AdditionalDispatcherList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_AdditionalDispatcherList_sequence_of, hf_index, ett_gsm_map_sm_AdditionalDispatcherList);
return offset;
}
static int
dissect_gsm_map_sm_MT_ForwardSM_VGCS_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 475 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_sm_MT_ForwardSM_VGCS_Res_sequence, hf_index, ett_gsm_map_sm_MT_ForwardSM_VGCS_Res);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
actx->pinfo->p2p_dir = P2P_DIR_RECV;
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceReference2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceDepth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceDepthExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceDepthList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TraceDepthList_sequence, hf_index, ett_gsm_map_om_TraceDepthList);
return offset;
}
static int
dissect_gsm_map_om_TraceNE_TypeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TraceNE_TypeList_bits, hf_index, ett_gsm_map_om_TraceNE_TypeList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MSC_S_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MSC_S_InterfaceList_bits, hf_index, ett_gsm_map_om_MSC_S_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MGW_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MGW_InterfaceList_bits, hf_index, ett_gsm_map_om_MGW_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_SGSN_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_SGSN_InterfaceList_bits, hf_index, ett_gsm_map_om_SGSN_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_GGSN_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_GGSN_InterfaceList_bits, hf_index, ett_gsm_map_om_GGSN_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_RNC_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_RNC_InterfaceList_bits, hf_index, ett_gsm_map_om_RNC_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_BMSC_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_BMSC_InterfaceList_bits, hf_index, ett_gsm_map_om_BMSC_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MME_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MME_InterfaceList_bits, hf_index, ett_gsm_map_om_MME_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_SGW_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_SGW_InterfaceList_bits, hf_index, ett_gsm_map_om_SGW_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_PGW_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_PGW_InterfaceList_bits, hf_index, ett_gsm_map_om_PGW_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_ENB_InterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_ENB_InterfaceList_bits, hf_index, ett_gsm_map_om_ENB_InterfaceList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceInterfaceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TraceInterfaceList_sequence, hf_index, ett_gsm_map_om_TraceInterfaceList);
return offset;
}
static int
dissect_gsm_map_om_MSC_S_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MSC_S_EventList_bits, hf_index, ett_gsm_map_om_MSC_S_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MGW_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MGW_EventList_bits, hf_index, ett_gsm_map_om_MGW_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_SGSN_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_SGSN_EventList_bits, hf_index, ett_gsm_map_om_SGSN_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_GGSN_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_GGSN_EventList_bits, hf_index, ett_gsm_map_om_GGSN_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_BMSC_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_BMSC_EventList_bits, hf_index, ett_gsm_map_om_BMSC_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MME_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MME_EventList_bits, hf_index, ett_gsm_map_om_MME_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_SGW_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_SGW_EventList_bits, hf_index, ett_gsm_map_om_SGW_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_PGW_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_PGW_EventList_bits, hf_index, ett_gsm_map_om_PGW_EventList,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TraceEventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TraceEventList_sequence, hf_index, ett_gsm_map_om_TraceEventList);
return offset;
}
static int
dissect_gsm_map_om_JobType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_CGI_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_CGI_List_sequence_of, hf_index, ett_gsm_map_om_CGI_List);
return offset;
}
static int
dissect_gsm_map_om_E_UTRAN_CGI_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_E_UTRAN_CGI_List_sequence_of, hf_index, ett_gsm_map_om_E_UTRAN_CGI_List);
return offset;
}
static int
dissect_gsm_map_om_RoutingAreaId_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_RoutingAreaId_List_sequence_of, hf_index, ett_gsm_map_om_RoutingAreaId_List);
return offset;
}
static int
dissect_gsm_map_om_LocationAreaId_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_LocationAreaId_List_sequence_of, hf_index, ett_gsm_map_om_LocationAreaId_List);
return offset;
}
static int
dissect_gsm_map_om_TrackingAreaId_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TrackingAreaId_List_sequence_of, hf_index, ett_gsm_map_om_TrackingAreaId_List);
return offset;
}
static int
dissect_gsm_map_om_AreaScope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_AreaScope_sequence, hf_index, ett_gsm_map_om_AreaScope);
return offset;
}
static int
dissect_gsm_map_om_ListOfMeasurements(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_ReportingTrigger(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_ReportInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_ReportAmount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_EventThresholdRSRP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_EventThresholdRSRQ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_LoggingInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_LoggingDuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_PeriodUMTS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_PeriodLTE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_PositioningMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MeasurementQuantity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_EventThreshold1F(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_EventThreshold1I(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_MDT_Configuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_MDT_Configuration_sequence, hf_index, ett_gsm_map_om_MDT_Configuration);
return offset;
}
static int
dissect_gsm_map_om_ActivateTraceModeArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_ActivateTraceModeArg_sequence, hf_index, ett_gsm_map_om_ActivateTraceModeArg);
return offset;
}
static int
dissect_gsm_map_om_TraceRecordingSessionReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_om_TracePropagationList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_TracePropagationList_sequence, hf_index, ett_gsm_map_om_TracePropagationList);
return offset;
}
static int
dissect_gsm_map_om_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_om_ActivateTraceModeRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_ActivateTraceModeRes_sequence, hf_index, ett_gsm_map_om_ActivateTraceModeRes);
return offset;
}
static int
dissect_gsm_map_om_DeactivateTraceModeArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_DeactivateTraceModeArg_sequence, hf_index, ett_gsm_map_om_DeactivateTraceModeArg);
return offset;
}
static int
dissect_gsm_map_om_DeactivateTraceModeRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_om_DeactivateTraceModeRes_sequence, hf_index, ett_gsm_map_om_DeactivateTraceModeRes);
return offset;
}
int
dissect_gsm_map_ms_SupportedCamelPhases(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SupportedCamelPhases_bits, hf_index, ett_gsm_map_ms_SupportedCamelPhases,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_ms_IST_SupportIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AgeIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SuperChargerInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_SuperChargerInfo_choice, hf_index, ett_gsm_map_ms_SuperChargerInfo,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SupportedLCS_CapabilitySets(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SupportedLCS_CapabilitySets_bits, hf_index, ett_gsm_map_ms_SupportedLCS_CapabilitySets,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_OfferedCamel4CSIs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_OfferedCamel4CSIs_bits, hf_index, ett_gsm_map_ms_OfferedCamel4CSIs,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SupportedRAT_Types(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SupportedRAT_Types_bits, hf_index, ett_gsm_map_ms_SupportedRAT_Types,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_VLR_Capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VLR_Capability_sequence, hf_index, ett_gsm_map_ms_VLR_Capability);
return offset;
}
static int
dissect_gsm_map_ms_ADD_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ADD_Info_sequence, hf_index, ett_gsm_map_ms_ADD_Info);
return offset;
}
static int
dissect_gsm_map_ms_LAC(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LocationArea(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_LocationArea_choice, hf_index, ett_gsm_map_ms_LocationArea,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PagingArea(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PagingArea_sequence_of, hf_index, ett_gsm_map_ms_PagingArea);
return offset;
}
static int
dissect_gsm_map_ms_EPLMN_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPLMN_List_sequence_of, hf_index, ett_gsm_map_ms_EPLMN_List);
return offset;
}
static int
dissect_gsm_map_ms_UpdateLocationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateLocationArg_sequence, hf_index, ett_gsm_map_ms_UpdateLocationArg);
return offset;
}
static int
dissect_gsm_map_ms_UpdateLocationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateLocationRes_sequence, hf_index, ett_gsm_map_ms_UpdateLocationRes);
return offset;
}
static int
dissect_gsm_map_ms_CancellationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_TypeOfUpdate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CancelLocationArg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CancelLocationArg_U_sequence, hf_index, ett_gsm_map_ms_CancelLocationArg_U);
return offset;
}
static int
dissect_gsm_map_ms_CancelLocationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_CancelLocationArg_U);
return offset;
}
static int
dissect_gsm_map_ms_CancelLocationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CancelLocationRes_sequence, hf_index, ett_gsm_map_ms_CancelLocationRes);
return offset;
}
int
dissect_gsm_map_ms_GeographicalInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LocationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 951 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
const char *digit_str;
guint8 na;
guint8 np;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_LocationNumber);
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_odd_even, tvb, 0, 1, ENC_BIG_ENDIAN);
na = tvb_get_guint8(tvb,0) & 0x7f;
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_nai, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_inn, tvb, 1, 1, ENC_BIG_ENDIAN);
np = (tvb_get_guint8(tvb,1) & 0x70) >> 4;
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_npi, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_apri, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_locationnumber_screening_ind, tvb, 1, 1, ENC_BIG_ENDIAN);
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, 2, -1, NULL, FALSE);
proto_tree_add_string(subtree, hf_gsm_map_locationnumber_digits, tvb, 2, -1, digit_str);
if ((na == 3) && (np==1))
dissect_e164_cc(tvb, subtree, 2, E164_ENC_BCD);
return offset;
}
int
dissect_gsm_map_ms_LSAIdentity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GeodeticInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LocationInformationEPS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LocationInformationEPS_sequence, hf_index, ett_gsm_map_ms_LocationInformationEPS);
return offset;
}
static int
dissect_gsm_map_ms_CSG_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UserCSGInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UserCSGInformation_sequence, hf_index, ett_gsm_map_ms_UserCSGInformation);
return offset;
}
int
dissect_gsm_map_ms_LocationInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LocationInformation_sequence, hf_index, ett_gsm_map_ms_LocationInformation);
return offset;
}
static int
dissect_gsm_map_ms_LocationInformationGPRS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LocationInformationGPRS_sequence, hf_index, ett_gsm_map_ms_LocationInformationGPRS);
return offset;
}
static int
dissect_gsm_map_ms_PurgeMS_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PurgeMS_Arg_U_sequence, hf_index, ett_gsm_map_ms_PurgeMS_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_PurgeMS_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_PurgeMS_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_PurgeMS_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PurgeMS_Res_sequence, hf_index, ett_gsm_map_ms_PurgeMS_Res);
return offset;
}
static int
dissect_gsm_map_ms_NumberOfRequestedVectors(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_HopCounter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SendIdentificationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendIdentificationArg_sequence, hf_index, ett_gsm_map_ms_SendIdentificationArg);
return offset;
}
static int
dissect_gsm_map_ms_RAND(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SRES(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Kc(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AuthenticationTriplet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AuthenticationTriplet_sequence, hf_index, ett_gsm_map_ms_AuthenticationTriplet);
return offset;
}
static int
dissect_gsm_map_ms_TripletList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_TripletList_sequence_of, hf_index, ett_gsm_map_ms_TripletList);
return offset;
}
static int
dissect_gsm_map_ms_XRES(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CK(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_IK(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AUTN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AuthenticationQuintuplet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AuthenticationQuintuplet_sequence, hf_index, ett_gsm_map_ms_AuthenticationQuintuplet);
return offset;
}
static int
dissect_gsm_map_ms_QuintupletList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_QuintupletList_sequence_of, hf_index, ett_gsm_map_ms_QuintupletList);
return offset;
}
static int
dissect_gsm_map_ms_AuthenticationSetList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_AuthenticationSetList_choice, hf_index, ett_gsm_map_ms_AuthenticationSetList,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Cksn(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GSM_SecurityContextData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GSM_SecurityContextData_sequence, hf_index, ett_gsm_map_ms_GSM_SecurityContextData);
return offset;
}
static int
dissect_gsm_map_ms_KSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UMTS_SecurityContextData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UMTS_SecurityContextData_sequence, hf_index, ett_gsm_map_ms_UMTS_SecurityContextData);
return offset;
}
static int
dissect_gsm_map_ms_CurrentSecurityContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_CurrentSecurityContext_choice, hf_index, ett_gsm_map_ms_CurrentSecurityContext,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SendIdentificationRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendIdentificationRes_U_sequence, hf_index, ett_gsm_map_ms_SendIdentificationRes_U);
return offset;
}
static int
dissect_gsm_map_ms_SendIdentificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_SendIdentificationRes_U);
return offset;
}
static int
dissect_gsm_map_ms_AUTS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_FailureCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_map_ms_AccessType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AuthenticationFailureReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AuthenticationFailureReportArg_sequence, hf_index, ett_gsm_map_ms_AuthenticationFailureReportArg);
return offset;
}
static int
dissect_gsm_map_ms_AuthenticationFailureReportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AuthenticationFailureReportRes_sequence, hf_index, ett_gsm_map_ms_AuthenticationFailureReportRes);
return offset;
}
static int
dissect_gsm_map_ms_SupportedFeatures(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SupportedFeatures_bits, hf_index, ett_gsm_map_ms_SupportedFeatures,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SGSN_Capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SGSN_Capability_sequence, hf_index, ett_gsm_map_ms_SGSN_Capability);
return offset;
}
static int
dissect_gsm_map_ms_APN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 924 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
int length, name_len, tmp;
guint8 *apn_str = NULL;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
length = tvb_reported_length(parameter_tvb);
name_len = tvb_get_guint8(parameter_tvb, 0);
apn_str = tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 1, length - 1, ENC_ASCII|ENC_NA);
if (name_len < length-1) {
for (;;) {
if (name_len >= length - 1)
break;
tmp = name_len;
name_len = name_len + apn_str[tmp] + 1;
apn_str[tmp] = '.';
}
}
proto_item_append_text(actx->created_item, " - %s", apn_str);
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_apn_str);
proto_tree_add_string(subtree, hf_gsm_apn_str, parameter_tvb, 0, -1, apn_str);
return offset;
}
static int
dissect_gsm_map_ms_PDP_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_FQDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PDN_GW_Identity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PDN_GW_Identity_sequence, hf_index, ett_gsm_map_ms_PDN_GW_Identity);
return offset;
}
static int
dissect_gsm_map_ms_ContextId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PDN_GW_Update(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PDN_GW_Update_sequence, hf_index, ett_gsm_map_ms_PDN_GW_Update);
return offset;
}
static int
dissect_gsm_map_ms_ISR_Information(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ISR_Information_bits, hf_index, ett_gsm_map_ms_ISR_Information,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_EPS_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_EPS_Info_choice, hf_index, ett_gsm_map_ms_EPS_Info,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Used_RAT_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UE_SRVCC_Capability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SMSRegisterRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UpdateGprsLocationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateGprsLocationArg_sequence, hf_index, ett_gsm_map_ms_UpdateGprsLocationArg);
return offset;
}
static int
dissect_gsm_map_ms_UpdateGprsLocationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateGprsLocationRes_sequence, hf_index, ett_gsm_map_ms_UpdateGprsLocationRes);
return offset;
}
static int
dissect_gsm_map_ms_IntegrityProtectionInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 703 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
asn1_ctx_t asn1_ctx;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, actx->pinfo);
dissect_ranap_IntegrityProtectionInformation(parameter_tvb, 0, &asn1_ctx, tree, hf_gsm_map_IntegrityProtectionInformation);
return offset;
}
static int
dissect_gsm_map_ms_EncryptionInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 715 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
asn1_ctx_t asn1_ctx;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, actx->pinfo);
dissect_ranap_EncryptionInformation(parameter_tvb, 0, &asn1_ctx, tree, hf_gsm_map_EncryptionInformation);
return offset;
}
static int
dissect_gsm_map_ms_KeyStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AllowedGSM_Algorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PermittedIntegrityProtectionAlgorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PermittedEncryptionAlgorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AllowedUMTS_Algorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AllowedUMTS_Algorithms_sequence, hf_index, ett_gsm_map_ms_AllowedUMTS_Algorithms);
return offset;
}
static int
dissect_gsm_map_ms_RadioResourceInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 679 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_RadioResourceInformation);
be_chan_type(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length_remaining(tvb,0), NULL, 0);
return offset;
}
static int
dissect_gsm_map_ms_RAB_Id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RadioResource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RadioResource_sequence, hf_index, ett_gsm_map_ms_RadioResource);
return offset;
}
static int
dissect_gsm_map_ms_RadioResourceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RadioResourceList_sequence_of, hf_index, ett_gsm_map_ms_RadioResourceList);
return offset;
}
static int
dissect_gsm_map_ms_BSSMAP_ServiceHandover(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RANAP_ServiceHandover(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 691 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
asn1_ctx_t asn1_ctx;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, actx->pinfo);
dissect_ranap_Service_Handover(parameter_tvb, 0, &asn1_ctx, tree, hf_gsm_map_ranap_service_Handover);
return offset;
}
static int
dissect_gsm_map_ms_BSSMAP_ServiceHandoverInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_BSSMAP_ServiceHandoverInfo_sequence, hf_index, ett_gsm_map_ms_BSSMAP_ServiceHandoverInfo);
return offset;
}
static int
dissect_gsm_map_ms_BSSMAP_ServiceHandoverList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_BSSMAP_ServiceHandoverList_sequence_of, hf_index, ett_gsm_map_ms_BSSMAP_ServiceHandoverList);
return offset;
}
static int
dissect_gsm_map_ms_Codec(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CodecList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CodecList_sequence, hf_index, ett_gsm_map_ms_CodecList);
return offset;
}
static int
dissect_gsm_map_ms_SupportedCodecsList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SupportedCodecsList_sequence, hf_index, ett_gsm_map_ms_SupportedCodecsList);
return offset;
}
static int
dissect_gsm_map_ms_AoIPCodec(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AoIPCodecsList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AoIPCodecsList_sequence, hf_index, ett_gsm_map_ms_AoIPCodecsList);
return offset;
}
static int
dissect_gsm_map_ms_ForwardAccessSignalling_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ForwardAccessSignalling_Arg_U_sequence, hf_index, ett_gsm_map_ms_ForwardAccessSignalling_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_ForwardAccessSignalling_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_ForwardAccessSignalling_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_RNCId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GERAN_Classmark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UESBI_IuA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UESBI_IuB(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_UESBI_Iu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UESBI_Iu_sequence, hf_index, ett_gsm_map_ms_UESBI_Iu);
return offset;
}
static int
dissect_gsm_map_ms_ZoneCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ZoneCodeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ZoneCodeList_sequence_of, hf_index, ett_gsm_map_ms_ZoneCodeList);
return offset;
}
static int
dissect_gsm_map_ms_LCLS_GlobalCallReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LCLS_Negotiation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LCLS_Negotiation_bits, hf_index, ett_gsm_map_ms_LCLS_Negotiation,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LCLS_ConfigurationPreference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LCLS_ConfigurationPreference_bits, hf_index, ett_gsm_map_ms_LCLS_ConfigurationPreference,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LIPA_AllowedAPNList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LIPA_AllowedAPNList_sequence_of, hf_index, ett_gsm_map_ms_LIPA_AllowedAPNList);
return offset;
}
static int
dissect_gsm_map_ms_CSG_SubscriptionData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CSG_SubscriptionData_sequence, hf_index, ett_gsm_map_ms_CSG_SubscriptionData);
return offset;
}
static int
dissect_gsm_map_ms_CSG_SubscriptionDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CSG_SubscriptionDataList_sequence_of, hf_index, ett_gsm_map_ms_CSG_SubscriptionDataList);
return offset;
}
static int
dissect_gsm_map_ms_PrepareHO_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PrepareHO_Arg_U_sequence, hf_index, ett_gsm_map_ms_PrepareHO_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareHO_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_PrepareHO_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_RelocationNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RelocationNumber_sequence, hf_index, ett_gsm_map_ms_RelocationNumber);
return offset;
}
static int
dissect_gsm_map_ms_RelocationNumberList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RelocationNumberList_sequence_of, hf_index, ett_gsm_map_ms_RelocationNumberList);
return offset;
}
static int
dissect_gsm_map_ms_MulticallBearerInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ChosenIntegrityProtectionAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ChosenEncryptionAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SelectedUMTS_Algorithms(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SelectedUMTS_Algorithms_sequence, hf_index, ett_gsm_map_ms_SelectedUMTS_Algorithms);
return offset;
}
static int
dissect_gsm_map_ms_ChosenChannelInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ChosenSpeechVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ChosenRadioResourceInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ChosenRadioResourceInformation_sequence, hf_index, ett_gsm_map_ms_ChosenRadioResourceInformation);
return offset;
}
static int
dissect_gsm_map_ms_PrepareHO_Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PrepareHO_Res_U_sequence, hf_index, ett_gsm_map_ms_PrepareHO_Res_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareHO_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_PrepareHO_Res_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareSubsequentHO_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PrepareSubsequentHO_Arg_U_sequence, hf_index, ett_gsm_map_ms_PrepareSubsequentHO_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareSubsequentHO_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_PrepareSubsequentHO_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareSubsequentHO_Res_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PrepareSubsequentHO_Res_U_sequence, hf_index, ett_gsm_map_ms_PrepareSubsequentHO_Res_U);
return offset;
}
static int
dissect_gsm_map_ms_PrepareSubsequentHO_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_PrepareSubsequentHO_Res_U);
return offset;
}
static int
dissect_gsm_map_ms_SelectedGSM_Algorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ProcessAccessSignalling_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ProcessAccessSignalling_Arg_U_sequence, hf_index, ett_gsm_map_ms_ProcessAccessSignalling_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_ProcessAccessSignalling_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_ProcessAccessSignalling_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_SendEndSignal_Arg_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendEndSignal_Arg_U_sequence, hf_index, ett_gsm_map_ms_SendEndSignal_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_SendEndSignal_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_SendEndSignal_Arg_U);
return offset;
}
static int
dissect_gsm_map_ms_SendEndSignal_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendEndSignal_Res_sequence, hf_index, ett_gsm_map_ms_SendEndSignal_Res);
return offset;
}
static int
dissect_gsm_map_ms_Re_synchronisationInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Re_synchronisationInfo_sequence, hf_index, ett_gsm_map_ms_Re_synchronisationInfo);
return offset;
}
static int
dissect_gsm_map_ms_RequestingNodeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SendAuthenticationInfoArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendAuthenticationInfoArg_sequence, hf_index, ett_gsm_map_ms_SendAuthenticationInfoArg);
return offset;
}
static int
dissect_gsm_map_ms_KASME(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_EPC_AV(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPC_AV_sequence, hf_index, ett_gsm_map_ms_EPC_AV);
return offset;
}
static int
dissect_gsm_map_ms_EPS_AuthenticationSetList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPS_AuthenticationSetList_sequence_of, hf_index, ett_gsm_map_ms_EPS_AuthenticationSetList);
return offset;
}
static int
dissect_gsm_map_ms_SendAuthenticationInfoRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendAuthenticationInfoRes_U_sequence, hf_index, ett_gsm_map_ms_SendAuthenticationInfoRes_U);
return offset;
}
static int
dissect_gsm_map_ms_SendAuthenticationInfoRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ms_SendAuthenticationInfoRes_U);
return offset;
}
static int
dissect_gsm_map_ms_RequestedEquipmentInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RequestedEquipmentInfo_bits, hf_index, ett_gsm_map_ms_RequestedEquipmentInfo,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CheckIMEI_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CheckIMEI_Arg_sequence, hf_index, ett_gsm_map_ms_CheckIMEI_Arg);
return offset;
}
static int
dissect_gsm_map_ms_EquipmentStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CheckIMEI_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CheckIMEI_Res_sequence, hf_index, ett_gsm_map_ms_CheckIMEI_Res);
return offset;
}
static int
dissect_gsm_map_ms_Category(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SubscriberStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_BearerServiceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_BearerServiceList_sequence_of, hf_index, ett_gsm_map_ms_BearerServiceList);
return offset;
}
static int
dissect_gsm_map_ms_TeleserviceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_TeleserviceList_sequence_of, hf_index, ett_gsm_map_ms_TeleserviceList);
return offset;
}
int
dissect_gsm_map_ms_Ext_ForwOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_T_forwardingOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_ms_Ext_ForwOptions(implicit_tag, tvb, offset, actx, tree, hf_index);
#line 580 "../../asn1/gsm_map/gsm_map.cnf"
proto_tree_add_item(tree, hf_gsm_map_notification_to_forwarding_party, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_redirecting_presentation, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_notification_to_calling_party, tvb, 0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_map_forwarding_reason, tvb, 0,1,ENC_BIG_ENDIAN);
return offset;
}
int
dissect_gsm_map_ms_Ext_NoRepCondTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext_ForwFeature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_ForwFeature_sequence, hf_index, ett_gsm_map_ms_Ext_ForwFeature);
return offset;
}
static int
dissect_gsm_map_ms_Ext_ForwFeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_ForwFeatureList_sequence_of, hf_index, ett_gsm_map_ms_Ext_ForwFeatureList);
return offset;
}
static int
dissect_gsm_map_ms_Ext_ForwInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_ForwInfo_sequence, hf_index, ett_gsm_map_ms_Ext_ForwInfo);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CallBarringFeature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CallBarringFeature_sequence, hf_index, ett_gsm_map_ms_Ext_CallBarringFeature);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CallBarFeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CallBarFeatureList_sequence_of, hf_index, ett_gsm_map_ms_Ext_CallBarFeatureList);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CallBarInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CallBarInfo_sequence, hf_index, ett_gsm_map_ms_Ext_CallBarInfo);
return offset;
}
int
dissect_gsm_map_ms_CUG_Index(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_CUG_Interlock(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_IntraCUG_Options(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext_BasicServiceGroupList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_BasicServiceGroupList_sequence_of, hf_index, ett_gsm_map_ms_Ext_BasicServiceGroupList);
return offset;
}
static int
dissect_gsm_map_ms_CUG_Subscription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CUG_Subscription_sequence, hf_index, ett_gsm_map_ms_CUG_Subscription);
return offset;
}
static int
dissect_gsm_map_ms_CUG_SubscriptionList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CUG_SubscriptionList_sequence_of, hf_index, ett_gsm_map_ms_CUG_SubscriptionList);
return offset;
}
static int
dissect_gsm_map_ms_InterCUG_Restrictions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CUG_Feature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CUG_Feature_sequence, hf_index, ett_gsm_map_ms_CUG_Feature);
return offset;
}
static int
dissect_gsm_map_ms_CUG_FeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CUG_FeatureList_sequence_of, hf_index, ett_gsm_map_ms_CUG_FeatureList);
return offset;
}
int
dissect_gsm_map_ms_CUG_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CUG_Info_sequence, hf_index, ett_gsm_map_ms_CUG_Info);
return offset;
}
static int
dissect_gsm_map_ms_Ext_SS_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_SS_Data_sequence, hf_index, ett_gsm_map_ms_Ext_SS_Data);
return offset;
}
static int
dissect_gsm_map_ms_Ext_SS_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_Ext_SS_Info_choice, hf_index, ett_gsm_map_ms_Ext_SS_Info,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext_SS_InfoList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_SS_InfoList_sequence_of, hf_index, ett_gsm_map_ms_Ext_SS_InfoList);
return offset;
}
static int
dissect_gsm_map_ms_ODB_GeneralData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ODB_GeneralData_bits, hf_index, ett_gsm_map_ms_ODB_GeneralData,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ODB_HPLMN_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ODB_HPLMN_Data_bits, hf_index, ett_gsm_map_ms_ODB_HPLMN_Data,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ODB_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ODB_Data_sequence, hf_index, ett_gsm_map_ms_ODB_Data);
return offset;
}
static int
dissect_gsm_map_ms_GroupId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_ms_Long_GroupId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_ms_VoiceBroadcastData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VoiceBroadcastData_sequence, hf_index, ett_gsm_map_ms_VoiceBroadcastData);
return offset;
}
static int
dissect_gsm_map_ms_VBSDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VBSDataList_sequence_of, hf_index, ett_gsm_map_ms_VBSDataList);
return offset;
}
static int
dissect_gsm_map_ms_AdditionalSubscriptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AdditionalSubscriptions_bits, hf_index, ett_gsm_map_ms_AdditionalSubscriptions,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AdditionalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_VoiceGroupCallData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VoiceGroupCallData_sequence, hf_index, ett_gsm_map_ms_VoiceGroupCallData);
return offset;
}
static int
dissect_gsm_map_ms_VGCSDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VGCSDataList_sequence_of, hf_index, ett_gsm_map_ms_VGCSDataList);
return offset;
}
static int
dissect_gsm_map_ms_O_BcsmTriggerDetectionPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_ServiceKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_DefaultCallHandling(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_O_BcsmCamelTDPData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_BcsmCamelTDPData_sequence, hf_index, ett_gsm_map_ms_O_BcsmCamelTDPData);
return offset;
}
static int
dissect_gsm_map_ms_O_BcsmCamelTDPDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_BcsmCamelTDPDataList_sequence_of, hf_index, ett_gsm_map_ms_O_BcsmCamelTDPDataList);
return offset;
}
static int
dissect_gsm_map_ms_CamelCapabilityHandling(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_O_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_CSI_sequence, hf_index, ett_gsm_map_ms_O_CSI);
return offset;
}
static int
dissect_gsm_map_ms_SS_EventList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SS_EventList_sequence_of, hf_index, ett_gsm_map_ms_SS_EventList);
return offset;
}
static int
dissect_gsm_map_ms_SS_CamelData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SS_CamelData_sequence, hf_index, ett_gsm_map_ms_SS_CamelData);
return offset;
}
static int
dissect_gsm_map_ms_SS_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SS_CSI_sequence, hf_index, ett_gsm_map_ms_SS_CSI);
return offset;
}
static int
dissect_gsm_map_ms_MatchType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_DestinationNumberList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DestinationNumberList_sequence_of, hf_index, ett_gsm_map_ms_DestinationNumberList);
return offset;
}
static int
dissect_gsm_map_ms_INTEGER_1_maxNumOfISDN_AddressDigits(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_DestinationNumberLengthList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DestinationNumberLengthList_sequence_of, hf_index, ett_gsm_map_ms_DestinationNumberLengthList);
return offset;
}
static int
dissect_gsm_map_ms_DestinationNumberCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DestinationNumberCriteria_sequence, hf_index, ett_gsm_map_ms_DestinationNumberCriteria);
return offset;
}
static int
dissect_gsm_map_ms_BasicServiceCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_BasicServiceCriteria_sequence_of, hf_index, ett_gsm_map_ms_BasicServiceCriteria);
return offset;
}
static int
dissect_gsm_map_ms_CallTypeCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CauseValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_O_CauseValueCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_CauseValueCriteria_sequence_of, hf_index, ett_gsm_map_ms_O_CauseValueCriteria);
return offset;
}
static int
dissect_gsm_map_ms_O_BcsmCamelTDP_Criteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_BcsmCamelTDP_Criteria_sequence, hf_index, ett_gsm_map_ms_O_BcsmCamelTDP_Criteria);
return offset;
}
int
dissect_gsm_map_ms_O_BcsmCamelTDPCriteriaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_O_BcsmCamelTDPCriteriaList_sequence_of, hf_index, ett_gsm_map_ms_O_BcsmCamelTDPCriteriaList);
return offset;
}
static int
dissect_gsm_map_ms_MM_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_MobilityTriggers(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MobilityTriggers_sequence_of, hf_index, ett_gsm_map_ms_MobilityTriggers);
return offset;
}
static int
dissect_gsm_map_ms_M_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_M_CSI_sequence, hf_index, ett_gsm_map_ms_M_CSI);
return offset;
}
static int
dissect_gsm_map_ms_SMS_TriggerDetectionPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_DefaultSMS_Handling(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SMS_CAMEL_TDP_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SMS_CAMEL_TDP_Data_sequence, hf_index, ett_gsm_map_ms_SMS_CAMEL_TDP_Data);
return offset;
}
static int
dissect_gsm_map_ms_SMS_CAMEL_TDP_DataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SMS_CAMEL_TDP_DataList_sequence_of, hf_index, ett_gsm_map_ms_SMS_CAMEL_TDP_DataList);
return offset;
}
static int
dissect_gsm_map_ms_SMS_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SMS_CSI_sequence, hf_index, ett_gsm_map_ms_SMS_CSI);
return offset;
}
static int
dissect_gsm_map_ms_T_BcsmTriggerDetectionPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_T_BcsmCamelTDPData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_BcsmCamelTDPData_sequence, hf_index, ett_gsm_map_ms_T_BcsmCamelTDPData);
return offset;
}
static int
dissect_gsm_map_ms_T_BcsmCamelTDPDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_BcsmCamelTDPDataList_sequence_of, hf_index, ett_gsm_map_ms_T_BcsmCamelTDPDataList);
return offset;
}
static int
dissect_gsm_map_ms_T_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_CSI_sequence, hf_index, ett_gsm_map_ms_T_CSI);
return offset;
}
static int
dissect_gsm_map_ms_T_CauseValueCriteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_CauseValueCriteria_sequence_of, hf_index, ett_gsm_map_ms_T_CauseValueCriteria);
return offset;
}
static int
dissect_gsm_map_ms_T_BCSM_CAMEL_TDP_Criteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_BCSM_CAMEL_TDP_Criteria_sequence, hf_index, ett_gsm_map_ms_T_BCSM_CAMEL_TDP_Criteria);
return offset;
}
static int
dissect_gsm_map_ms_T_BCSM_CAMEL_TDP_CriteriaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_T_BCSM_CAMEL_TDP_CriteriaList_sequence_of, hf_index, ett_gsm_map_ms_T_BCSM_CAMEL_TDP_CriteriaList);
return offset;
}
static int
dissect_gsm_map_ms_DP_AnalysedInfoCriterium(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DP_AnalysedInfoCriterium_sequence, hf_index, ett_gsm_map_ms_DP_AnalysedInfoCriterium);
return offset;
}
static int
dissect_gsm_map_ms_DP_AnalysedInfoCriteriaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DP_AnalysedInfoCriteriaList_sequence_of, hf_index, ett_gsm_map_ms_DP_AnalysedInfoCriteriaList);
return offset;
}
int
dissect_gsm_map_ms_D_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_D_CSI_sequence, hf_index, ett_gsm_map_ms_D_CSI);
return offset;
}
static int
dissect_gsm_map_ms_MT_SMS_TPDU_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_TPDU_TypeCriterion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_TPDU_TypeCriterion_sequence_of, hf_index, ett_gsm_map_ms_TPDU_TypeCriterion);
return offset;
}
static int
dissect_gsm_map_ms_MT_smsCAMELTDP_Criteria(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MT_smsCAMELTDP_Criteria_sequence, hf_index, ett_gsm_map_ms_MT_smsCAMELTDP_Criteria);
return offset;
}
static int
dissect_gsm_map_ms_MT_smsCAMELTDP_CriteriaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MT_smsCAMELTDP_CriteriaList_sequence_of, hf_index, ett_gsm_map_ms_MT_smsCAMELTDP_CriteriaList);
return offset;
}
static int
dissect_gsm_map_ms_VlrCamelSubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VlrCamelSubscriptionInfo_sequence, hf_index, ett_gsm_map_ms_VlrCamelSubscriptionInfo);
return offset;
}
static int
dissect_gsm_map_ms_PDP_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 588 "../../asn1/gsm_map/gsm_map.cnf"
guint8 pdp_type_org;
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
proto_tree_add_item(tree, hf_gsm_map_pdp_type_org, parameter_tvb, 0,1,ENC_BIG_ENDIAN);
pdp_type_org = tvb_get_guint8(parameter_tvb,1);
switch (pdp_type_org){
case 0:
proto_tree_add_item(tree, hf_gsm_map_etsi_pdp_type_number, parameter_tvb, 0,1,ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(tree, hf_gsm_map_ietf_pdp_type_number, parameter_tvb, 0,1,ENC_BIG_ENDIAN);
break;
default:
break;
}
return offset;
}
int
dissect_gsm_map_ms_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 610 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
de_sm_qos(parameter_tvb, tree, actx->pinfo, 0, 3, NULL,0);
return offset;
}
int
dissect_gsm_map_ms_Ext_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 621 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
dissect_gsm_map_ext_qos_subscribed(tvb, actx->pinfo, tree, actx);
return offset;
}
static int
dissect_gsm_map_ms_ChargingCharacteristics(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_Ext2_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_Ext3_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext4_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_APN_OI_Replacement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext_PDP_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Bandwidth(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AMBR(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AMBR_sequence, hf_index, ett_gsm_map_ms_AMBR);
return offset;
}
static int
dissect_gsm_map_ms_SIPTO_Permission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LIPA_Permission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Restoration_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SIPTO_Local_Network_Permission(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PDP_Context(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PDP_Context_sequence, hf_index, ett_gsm_map_ms_PDP_Context);
return offset;
}
static int
dissect_gsm_map_ms_GPRSDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRSDataList_sequence_of, hf_index, ett_gsm_map_ms_GPRSDataList);
return offset;
}
static int
dissect_gsm_map_ms_GPRSSubscriptionData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRSSubscriptionData_sequence, hf_index, ett_gsm_map_ms_GPRSSubscriptionData);
return offset;
}
static int
dissect_gsm_map_ms_NetworkAccessMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LSAOnlyAccessIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LSAAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LSAData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LSAData_sequence, hf_index, ett_gsm_map_ms_LSAData);
return offset;
}
static int
dissect_gsm_map_ms_LSADataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LSADataList_sequence_of, hf_index, ett_gsm_map_ms_LSADataList);
return offset;
}
static int
dissect_gsm_map_ms_LSAInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LSAInformation_sequence, hf_index, ett_gsm_map_ms_LSAInformation);
return offset;
}
static int
dissect_gsm_map_ms_GMLC_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GMLC_List_sequence_of, hf_index, ett_gsm_map_ms_GMLC_List);
return offset;
}
int
dissect_gsm_map_ms_NotificationToMSUser(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GMLC_Restriction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ExternalClient(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ExternalClient_sequence, hf_index, ett_gsm_map_ms_ExternalClient);
return offset;
}
static int
dissect_gsm_map_ms_ExternalClientList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ExternalClientList_sequence_of, hf_index, ett_gsm_map_ms_ExternalClientList);
return offset;
}
static int
dissect_gsm_map_ms_PLMNClientList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PLMNClientList_sequence_of, hf_index, ett_gsm_map_ms_PLMNClientList);
return offset;
}
static int
dissect_gsm_map_ms_Ext_ExternalClientList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_ExternalClientList_sequence_of, hf_index, ett_gsm_map_ms_Ext_ExternalClientList);
return offset;
}
static int
dissect_gsm_map_ms_ServiceType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ServiceType_sequence, hf_index, ett_gsm_map_ms_ServiceType);
return offset;
}
static int
dissect_gsm_map_ms_ServiceTypeList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ServiceTypeList_sequence_of, hf_index, ett_gsm_map_ms_ServiceTypeList);
return offset;
}
static int
dissect_gsm_map_ms_LCS_PrivacyClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LCS_PrivacyClass_sequence, hf_index, ett_gsm_map_ms_LCS_PrivacyClass);
return offset;
}
static int
dissect_gsm_map_ms_LCS_PrivacyExceptionList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LCS_PrivacyExceptionList_sequence_of, hf_index, ett_gsm_map_ms_LCS_PrivacyExceptionList);
return offset;
}
static int
dissect_gsm_map_ms_MOLR_Class(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MOLR_Class_sequence, hf_index, ett_gsm_map_ms_MOLR_Class);
return offset;
}
static int
dissect_gsm_map_ms_MOLR_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MOLR_List_sequence_of, hf_index, ett_gsm_map_ms_MOLR_List);
return offset;
}
static int
dissect_gsm_map_ms_LCSInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LCSInformation_sequence, hf_index, ett_gsm_map_ms_LCSInformation);
return offset;
}
static int
dissect_gsm_map_ms_IST_AlertTimerValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CS_AllocationRetentionPriority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GPRS_TriggerDetectionPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_DefaultGPRS_Handling(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_GPRS_CamelTDPData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRS_CamelTDPData_sequence, hf_index, ett_gsm_map_ms_GPRS_CamelTDPData);
return offset;
}
static int
dissect_gsm_map_ms_GPRS_CamelTDPDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRS_CamelTDPDataList_sequence_of, hf_index, ett_gsm_map_ms_GPRS_CamelTDPDataList);
return offset;
}
static int
dissect_gsm_map_ms_GPRS_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRS_CSI_sequence, hf_index, ett_gsm_map_ms_GPRS_CSI);
return offset;
}
static int
dissect_gsm_map_ms_MG_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MG_CSI_sequence, hf_index, ett_gsm_map_ms_MG_CSI);
return offset;
}
static int
dissect_gsm_map_ms_SGSN_CAMEL_SubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SGSN_CAMEL_SubscriptionInfo_sequence, hf_index, ett_gsm_map_ms_SGSN_CAMEL_SubscriptionInfo);
return offset;
}
static int
dissect_gsm_map_ms_AccessRestrictionData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AccessRestrictionData_bits, hf_index, ett_gsm_map_ms_AccessRestrictionData,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RFSP_ID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PDN_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_QoS_Class_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Allocation_Retention_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Allocation_Retention_Priority_sequence, hf_index, ett_gsm_map_ms_Allocation_Retention_Priority);
return offset;
}
static int
dissect_gsm_map_ms_EPS_QoS_Subscribed(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPS_QoS_Subscribed_sequence, hf_index, ett_gsm_map_ms_EPS_QoS_Subscribed);
return offset;
}
static int
dissect_gsm_map_ms_PDN_GW_AllocationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SpecificAPNInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SpecificAPNInfo_sequence, hf_index, ett_gsm_map_ms_SpecificAPNInfo);
return offset;
}
static int
dissect_gsm_map_ms_SpecificAPNInfoList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SpecificAPNInfoList_sequence_of, hf_index, ett_gsm_map_ms_SpecificAPNInfoList);
return offset;
}
static int
dissect_gsm_map_ms_APN_Configuration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_APN_Configuration_sequence, hf_index, ett_gsm_map_ms_APN_Configuration);
return offset;
}
static int
dissect_gsm_map_ms_EPS_DataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPS_DataList_sequence_of, hf_index, ett_gsm_map_ms_EPS_DataList);
return offset;
}
static int
dissect_gsm_map_ms_APN_ConfigurationProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_APN_ConfigurationProfile_sequence, hf_index, ett_gsm_map_ms_APN_ConfigurationProfile);
return offset;
}
static int
dissect_gsm_map_ms_EPS_SubscriptionData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EPS_SubscriptionData_sequence, hf_index, ett_gsm_map_ms_EPS_SubscriptionData);
return offset;
}
static int
dissect_gsm_map_ms_SubscribedPeriodicRAUTAUtimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SubscribedPeriodicLAUtimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_VPLMN_CSG_SubscriptionDataList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_VPLMN_CSG_SubscriptionDataList_sequence_of, hf_index, ett_gsm_map_ms_VPLMN_CSG_SubscriptionDataList);
return offset;
}
static int
dissect_gsm_map_ms_InsertSubscriberDataArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_InsertSubscriberDataArg_sequence, hf_index, ett_gsm_map_ms_InsertSubscriberDataArg);
return offset;
}
static int
dissect_gsm_map_ms_SubscriberData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SubscriberData_sequence, hf_index, ett_gsm_map_ms_SubscriberData);
return offset;
}
static int
dissect_gsm_map_ms_RegionalSubscriptionResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_InsertSubscriberDataRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_InsertSubscriberDataRes_sequence, hf_index, ett_gsm_map_ms_InsertSubscriberDataRes);
return offset;
}
static int
dissect_gsm_map_ms_BasicServiceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_BasicServiceList_sequence_of, hf_index, ett_gsm_map_ms_BasicServiceList);
return offset;
}
static int
dissect_gsm_map_ms_ContextIdList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ContextIdList_sequence_of, hf_index, ett_gsm_map_ms_ContextIdList);
return offset;
}
static int
dissect_gsm_map_ms_GPRSSubscriptionDataWithdraw(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_GPRSSubscriptionDataWithdraw_choice, hf_index, ett_gsm_map_ms_GPRSSubscriptionDataWithdraw,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_LSAIdentityList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_LSAIdentityList_sequence_of, hf_index, ett_gsm_map_ms_LSAIdentityList);
return offset;
}
static int
dissect_gsm_map_ms_LSAInformationWithdraw(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_LSAInformationWithdraw_choice, hf_index, ett_gsm_map_ms_LSAInformationWithdraw,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SpecificCSI_Withdraw(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SpecificCSI_Withdraw_bits, hf_index, ett_gsm_map_ms_SpecificCSI_Withdraw,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_EPS_SubscriptionDataWithdraw(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_EPS_SubscriptionDataWithdraw_choice, hf_index, ett_gsm_map_ms_EPS_SubscriptionDataWithdraw,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_DeleteSubscriberDataArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DeleteSubscriberDataArg_sequence, hf_index, ett_gsm_map_ms_DeleteSubscriberDataArg);
return offset;
}
static int
dissect_gsm_map_ms_DeleteSubscriberDataRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_DeleteSubscriberDataRes_sequence, hf_index, ett_gsm_map_ms_DeleteSubscriberDataRes);
return offset;
}
int
dissect_gsm_map_ms_OfferedCamel4Functionalities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_OfferedCamel4Functionalities_bits, hf_index, ett_gsm_map_ms_OfferedCamel4Functionalities,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SendRoutingInfoForGprsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendRoutingInfoForGprsArg_sequence, hf_index, ett_gsm_map_ms_SendRoutingInfoForGprsArg);
return offset;
}
static int
dissect_gsm_map_ms_SendRoutingInfoForGprsRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SendRoutingInfoForGprsRes_sequence, hf_index, ett_gsm_map_ms_SendRoutingInfoForGprsRes);
return offset;
}
static int
dissect_gsm_map_ms_FailureReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_FailureReportArg_sequence, hf_index, ett_gsm_map_ms_FailureReportArg);
return offset;
}
static int
dissect_gsm_map_ms_FailureReportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_FailureReportRes_sequence, hf_index, ett_gsm_map_ms_FailureReportRes);
return offset;
}
static int
dissect_gsm_map_ms_NoteMsPresentForGprsArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteMsPresentForGprsArg_sequence, hf_index, ett_gsm_map_ms_NoteMsPresentForGprsArg);
return offset;
}
static int
dissect_gsm_map_ms_NoteMsPresentForGprsRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteMsPresentForGprsRes_sequence, hf_index, ett_gsm_map_ms_NoteMsPresentForGprsRes);
return offset;
}
static int
dissect_gsm_map_ms_SendingNode_Number(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_SendingNode_Number_choice, hf_index, ett_gsm_map_ms_SendingNode_Number,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ResetArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ResetArg_sequence, hf_index, ett_gsm_map_ms_ResetArg);
return offset;
}
static int
dissect_gsm_map_ms_RestoreDataArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RestoreDataArg_sequence, hf_index, ett_gsm_map_ms_RestoreDataArg);
return offset;
}
static int
dissect_gsm_map_ms_RestoreDataRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RestoreDataRes_sequence, hf_index, ett_gsm_map_ms_RestoreDataRes);
return offset;
}
static int
dissect_gsm_map_ms_DomainType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RequestedNodes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RequestedNodes_bits, hf_index, ett_gsm_map_ms_RequestedNodes,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RequestedInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RequestedInfo_sequence, hf_index, ett_gsm_map_ms_RequestedInfo);
return offset;
}
static int
dissect_gsm_map_ms_ProvideSubscriberInfoArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ProvideSubscriberInfoArg_sequence, hf_index, ett_gsm_map_ms_ProvideSubscriberInfoArg);
return offset;
}
static int
dissect_gsm_map_ms_NotReachableReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_SubscriberState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_SubscriberState_choice, hf_index, ett_gsm_map_ms_SubscriberState,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_NSAPI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_TransactionId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_TEID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_GPRSChargingID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_PDP_ContextInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PDP_ContextInfo_sequence, hf_index, ett_gsm_map_ms_PDP_ContextInfo);
return offset;
}
static int
dissect_gsm_map_ms_PDP_ContextInfoList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_PDP_ContextInfoList_sequence_of, hf_index, ett_gsm_map_ms_PDP_ContextInfoList);
return offset;
}
static int
dissect_gsm_map_ms_PS_SubscriberState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_PS_SubscriberState_choice, hf_index, ett_gsm_map_ms_PS_SubscriberState,
NULL);
return offset;
}
int
dissect_gsm_map_ms_MS_Classmark2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_MSNetworkCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_MSRadioAccessCapability(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ms_GPRSMSClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_GPRSMSClass_sequence, hf_index, ett_gsm_map_ms_GPRSMSClass);
return offset;
}
static int
dissect_gsm_map_ms_RouteingNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_ms_NumberPortabilityStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_MNPInfoRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MNPInfoRes_sequence, hf_index, ett_gsm_map_ms_MNPInfoRes);
return offset;
}
static int
dissect_gsm_map_ms_IMS_VoiceOverPS_SessionsInd(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_TimeZone(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_DaylightSavingTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_SubscriberInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_SubscriberInfo_sequence, hf_index, ett_gsm_map_ms_SubscriberInfo);
return offset;
}
static int
dissect_gsm_map_ms_ProvideSubscriberInfoRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ProvideSubscriberInfoRes_sequence, hf_index, ett_gsm_map_ms_ProvideSubscriberInfoRes);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeInterrogationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeInterrogationArg_sequence, hf_index, ett_gsm_map_ms_AnyTimeInterrogationArg);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeInterrogationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeInterrogationRes_sequence, hf_index, ett_gsm_map_ms_AnyTimeInterrogationRes);
return offset;
}
static int
dissect_gsm_map_ms_RequestedCAMEL_SubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AdditionalRequestedCAMEL_SubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_RequestedSubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RequestedSubscriptionInfo_sequence, hf_index, ett_gsm_map_ms_RequestedSubscriptionInfo);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeSubscriptionInterrogationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeSubscriptionInterrogationArg_sequence, hf_index, ett_gsm_map_ms_AnyTimeSubscriptionInterrogationArg);
return offset;
}
static int
dissect_gsm_map_ms_CallForwardingData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CallForwardingData_sequence, hf_index, ett_gsm_map_ms_CallForwardingData);
return offset;
}
static int
dissect_gsm_map_ms_WrongPasswordAttemptsCounter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_CallBarringData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CallBarringData_sequence, hf_index, ett_gsm_map_ms_CallBarringData);
return offset;
}
static int
dissect_gsm_map_ms_ODB_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ODB_Info_sequence, hf_index, ett_gsm_map_ms_ODB_Info);
return offset;
}
static int
dissect_gsm_map_ms_CAMEL_SubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CAMEL_SubscriptionInfo_sequence, hf_index, ett_gsm_map_ms_CAMEL_SubscriptionInfo);
return offset;
}
static int
dissect_gsm_map_ms_MSISDN_BS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MSISDN_BS_sequence, hf_index, ett_gsm_map_ms_MSISDN_BS);
return offset;
}
static int
dissect_gsm_map_ms_MSISDN_BS_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_MSISDN_BS_List_sequence_of, hf_index, ett_gsm_map_ms_MSISDN_BS_List);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CwFeature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CwFeature_sequence, hf_index, ett_gsm_map_ms_Ext_CwFeature);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CwFeatureList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CwFeatureList_sequence_of, hf_index, ett_gsm_map_ms_Ext_CwFeatureList);
return offset;
}
static int
dissect_gsm_map_ms_CallWaitingData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CallWaitingData_sequence, hf_index, ett_gsm_map_ms_CallWaitingData);
return offset;
}
static int
dissect_gsm_map_ms_CallHoldData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CallHoldData_sequence, hf_index, ett_gsm_map_ms_CallHoldData);
return offset;
}
static int
dissect_gsm_map_ms_ClipData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ClipData_sequence, hf_index, ett_gsm_map_ms_ClipData);
return offset;
}
static int
dissect_gsm_map_ms_ClirData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ClirData_sequence, hf_index, ett_gsm_map_ms_ClirData);
return offset;
}
static int
dissect_gsm_map_ms_EctData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_EctData_sequence, hf_index, ett_gsm_map_ms_EctData);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeSubscriptionInterrogationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeSubscriptionInterrogationRes_sequence, hf_index, ett_gsm_map_ms_AnyTimeSubscriptionInterrogationRes);
return offset;
}
static int
dissect_gsm_map_ms_ModificationInstruction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CF_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CF_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CF_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CB_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CB_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CB_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CSI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CSI_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CSI);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_ODB_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_ODB_data_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_ODB_data);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_IP_SM_GW_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_IP_SM_GW_Data_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_IP_SM_GW_Data);
return offset;
}
static int
dissect_gsm_map_ms_RequestedServingNode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_RequestedServingNode_bits, hf_index, ett_gsm_map_ms_RequestedServingNode,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CSG(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CSG_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CSG);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CW_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CW_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CW_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CLIP_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CLIP_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CLIP_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CLIR_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CLIR_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CLIR_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_CH_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_CH_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_CH_Info);
return offset;
}
static int
dissect_gsm_map_ms_ModificationRequestFor_ECT_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ModificationRequestFor_ECT_Info_sequence, hf_index, ett_gsm_map_ms_ModificationRequestFor_ECT_Info);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeModificationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeModificationArg_sequence, hf_index, ett_gsm_map_ms_AnyTimeModificationArg);
return offset;
}
static int
dissect_gsm_map_ms_ServingNode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_ServingNode_bits, hf_index, ett_gsm_map_ms_ServingNode,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_Ext_ForwardingInfoFor_CSE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_ForwardingInfoFor_CSE_sequence, hf_index, ett_gsm_map_ms_Ext_ForwardingInfoFor_CSE);
return offset;
}
static int
dissect_gsm_map_ms_Ext_CallBarringInfoFor_CSE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_Ext_CallBarringInfoFor_CSE_sequence, hf_index, ett_gsm_map_ms_Ext_CallBarringInfoFor_CSE);
return offset;
}
static int
dissect_gsm_map_ms_Ext_SS_InfoFor_CSE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ms_Ext_SS_InfoFor_CSE_choice, hf_index, ett_gsm_map_ms_Ext_SS_InfoFor_CSE,
NULL);
return offset;
}
static int
dissect_gsm_map_ms_AnyTimeModificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_AnyTimeModificationRes_sequence, hf_index, ett_gsm_map_ms_AnyTimeModificationRes);
return offset;
}
static int
dissect_gsm_map_ms_NoteSubscriberDataModifiedArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteSubscriberDataModifiedArg_sequence, hf_index, ett_gsm_map_ms_NoteSubscriberDataModifiedArg);
return offset;
}
static int
dissect_gsm_map_ms_NoteSubscriberDataModifiedRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteSubscriberDataModifiedRes_sequence, hf_index, ett_gsm_map_ms_NoteSubscriberDataModifiedRes);
return offset;
}
static int
dissect_gsm_map_ms_NoteMM_EventArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteMM_EventArg_sequence, hf_index, ett_gsm_map_ms_NoteMM_EventArg);
return offset;
}
static int
dissect_gsm_map_ms_NoteMM_EventRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_NoteMM_EventRes_sequence, hf_index, ett_gsm_map_ms_NoteMM_EventRes);
return offset;
}
static int
dissect_gsm_map_ms_UpdateVcsgLocationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateVcsgLocationArg_sequence, hf_index, ett_gsm_map_ms_UpdateVcsgLocationArg);
return offset;
}
static int
dissect_gsm_map_ms_UpdateVcsgLocationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_UpdateVcsgLocationRes_sequence, hf_index, ett_gsm_map_ms_UpdateVcsgLocationRes);
return offset;
}
static int
dissect_gsm_map_ms_CancelVcsgLocationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CancelVcsgLocationArg_sequence, hf_index, ett_gsm_map_ms_CancelVcsgLocationArg);
return offset;
}
static int
dissect_gsm_map_ms_CancelVcsgLocationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ms_CancelVcsgLocationRes_sequence, hf_index, ett_gsm_map_ms_CancelVcsgLocationRes);
return offset;
}
static int
dissect_gsm_map_ch_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
int
dissect_gsm_map_ch_CUG_CheckInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_CUG_CheckInfo_sequence, hf_index, ett_gsm_map_ch_CUG_CheckInfo);
return offset;
}
static int
dissect_gsm_map_ch_NumberOfForwarding(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_InterrogationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_OR_Phase(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ch_CallReferenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_ForwardingReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_CamelInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_CamelInfo_sequence, hf_index, ett_gsm_map_ch_CamelInfo);
return offset;
}
int
dissect_gsm_map_ch_SuppressionOfAnnouncement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_ch_SupportedCCBS_Phase(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_CallDiversionTreatmentIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_SuppressMTSS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_SuppressMTSS_bits, hf_index, ett_gsm_map_ch_SuppressMTSS,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_SendRoutingInfoArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_SendRoutingInfoArg_sequence, hf_index, ett_gsm_map_ch_SendRoutingInfoArg);
return offset;
}
static int
dissect_gsm_map_ch_ForwardingData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ForwardingData_sequence, hf_index, ett_gsm_map_ch_ForwardingData);
return offset;
}
static int
dissect_gsm_map_ch_RoutingInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ch_RoutingInfo_choice, hf_index, ett_gsm_map_ch_RoutingInfo,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_GmscCamelSubscriptionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_GmscCamelSubscriptionInfo_sequence, hf_index, ett_gsm_map_ch_GmscCamelSubscriptionInfo);
return offset;
}
static int
dissect_gsm_map_ch_CamelRoutingInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_CamelRoutingInfo_sequence, hf_index, ett_gsm_map_ch_CamelRoutingInfo);
return offset;
}
static int
dissect_gsm_map_ch_ExtendedRoutingInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_ch_ExtendedRoutingInfo_choice, hf_index, ett_gsm_map_ch_ExtendedRoutingInfo,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_CCBS_Indicators(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_CCBS_Indicators_sequence, hf_index, ett_gsm_map_ch_CCBS_Indicators);
return offset;
}
static int
dissect_gsm_map_ch_AllowedServices(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_AllowedServices_bits, hf_index, ett_gsm_map_ch_AllowedServices,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_UnavailabilityCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_SendRoutingInfoRes_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_SendRoutingInfoRes_U_sequence, hf_index, ett_gsm_map_ch_SendRoutingInfoRes_U);
return offset;
}
static int
dissect_gsm_map_ch_SendRoutingInfoRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_CON, 3, TRUE, dissect_gsm_map_ch_SendRoutingInfoRes_U);
return offset;
}
static int
dissect_gsm_map_ch_ProvideRoamingNumberArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ProvideRoamingNumberArg_sequence, hf_index, ett_gsm_map_ch_ProvideRoamingNumberArg);
return offset;
}
static int
dissect_gsm_map_ch_ProvideRoamingNumberRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ProvideRoamingNumberRes_sequence, hf_index, ett_gsm_map_ch_ProvideRoamingNumberRes);
return offset;
}
static int
dissect_gsm_map_ch_UUIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_UUI(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_ch_UU_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_UU_Data_sequence, hf_index, ett_gsm_map_ch_UU_Data);
return offset;
}
static int
dissect_gsm_map_ch_ResumeCallHandlingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ResumeCallHandlingArg_sequence, hf_index, ett_gsm_map_ch_ResumeCallHandlingArg);
return offset;
}
static int
dissect_gsm_map_ch_ResumeCallHandlingRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ResumeCallHandlingRes_sequence, hf_index, ett_gsm_map_ch_ResumeCallHandlingRes);
return offset;
}
static int
dissect_gsm_map_ch_ReportingState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_SetReportingStateArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_SetReportingStateArg_sequence, hf_index, ett_gsm_map_ch_SetReportingStateArg);
return offset;
}
static int
dissect_gsm_map_ch_CCBS_SubscriberStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_SetReportingStateRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_SetReportingStateRes_sequence, hf_index, ett_gsm_map_ch_SetReportingStateRes);
return offset;
}
static int
dissect_gsm_map_ch_EventReportData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_EventReportData_sequence, hf_index, ett_gsm_map_ch_EventReportData);
return offset;
}
static int
dissect_gsm_map_ch_MonitoringMode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_CallOutcome(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_CallReportData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_CallReportData_sequence, hf_index, ett_gsm_map_ch_CallReportData);
return offset;
}
static int
dissect_gsm_map_ch_StatusReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_StatusReportArg_sequence, hf_index, ett_gsm_map_ch_StatusReportArg);
return offset;
}
static int
dissect_gsm_map_ch_StatusReportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_StatusReportRes_sequence, hf_index, ett_gsm_map_ch_StatusReportRes);
return offset;
}
static int
dissect_gsm_map_ch_RemoteUserFreeArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_RemoteUserFreeArg_sequence, hf_index, ett_gsm_map_ch_RemoteUserFreeArg);
return offset;
}
static int
dissect_gsm_map_ch_RUF_Outcome(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_RemoteUserFreeRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_RemoteUserFreeRes_sequence, hf_index, ett_gsm_map_ch_RemoteUserFreeRes);
return offset;
}
static int
dissect_gsm_map_ch_IST_AlertArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_IST_AlertArg_sequence, hf_index, ett_gsm_map_ch_IST_AlertArg);
return offset;
}
static int
dissect_gsm_map_ch_CallTerminationIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_ch_IST_AlertRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_IST_AlertRes_sequence, hf_index, ett_gsm_map_ch_IST_AlertRes);
return offset;
}
static int
dissect_gsm_map_ch_IST_CommandArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_IST_CommandArg_sequence, hf_index, ett_gsm_map_ch_IST_CommandArg);
return offset;
}
static int
dissect_gsm_map_ch_IST_CommandRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_IST_CommandRes_sequence, hf_index, ett_gsm_map_ch_IST_CommandRes);
return offset;
}
static int
dissect_gsm_map_ch_ReleaseResourcesArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ReleaseResourcesArg_sequence, hf_index, ett_gsm_map_ch_ReleaseResourcesArg);
return offset;
}
static int
dissect_gsm_map_ch_ReleaseResourcesRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ch_ReleaseResourcesRes_sequence, hf_index, ett_gsm_map_ch_ReleaseResourcesRes);
return offset;
}
static int
dissect_gsm_map_lcs_RoutingInfoForLCS_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_RoutingInfoForLCS_Arg_sequence, hf_index, ett_gsm_map_lcs_RoutingInfoForLCS_Arg);
return offset;
}
static int
dissect_gsm_map_lcs_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_lcs_LCSLocationInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCSLocationInfo_sequence, hf_index, ett_gsm_map_lcs_LCSLocationInfo);
return offset;
}
static int
dissect_gsm_map_lcs_RoutingInfoForLCS_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_RoutingInfoForLCS_Res_sequence, hf_index, ett_gsm_map_lcs_RoutingInfoForLCS_Res);
return offset;
}
static int
dissect_gsm_map_lcs_LocationEstimateType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_DeferredLocationEventType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_DeferredLocationEventType_bits, hf_index, ett_gsm_map_lcs_DeferredLocationEventType,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_LocationType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LocationType_sequence, hf_index, ett_gsm_map_lcs_LocationType);
return offset;
}
int
dissect_gsm_map_lcs_LCSClientType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_NameString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_ss_USSD_String(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_map_lcs_LCS_FormatIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_LCSClientName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCSClientName_sequence, hf_index, ett_gsm_map_lcs_LCSClientName);
return offset;
}
static int
dissect_gsm_map_lcs_RequestorIDString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_ss_USSD_String(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_gsm_map_lcs_LCSRequestorID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCSRequestorID_sequence, hf_index, ett_gsm_map_lcs_LCSRequestorID);
return offset;
}
int
dissect_gsm_map_lcs_LCS_ClientID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCS_ClientID_sequence, hf_index, ett_gsm_map_lcs_LCS_ClientID);
return offset;
}
int
dissect_gsm_map_lcs_LCS_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_Horizontal_Accuracy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_Vertical_Accuracy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ResponseTimeCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ResponseTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_ResponseTime_sequence, hf_index, ett_gsm_map_lcs_ResponseTime);
return offset;
}
int
dissect_gsm_map_lcs_LCS_QoS(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCS_QoS_sequence, hf_index, ett_gsm_map_lcs_LCS_QoS);
return offset;
}
int
dissect_gsm_map_lcs_SupportedGADShapes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_SupportedGADShapes_bits, hf_index, ett_gsm_map_lcs_SupportedGADShapes,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_LCS_ReferenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_LCSCodewordString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_ss_USSD_String(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_gsm_map_lcs_LCSCodeword(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCSCodeword_sequence, hf_index, ett_gsm_map_lcs_LCSCodeword);
return offset;
}
static int
dissect_gsm_map_lcs_PrivacyCheckRelatedAction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_LCS_PrivacyCheck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_LCS_PrivacyCheck_sequence, hf_index, ett_gsm_map_lcs_LCS_PrivacyCheck);
return offset;
}
static int
dissect_gsm_map_lcs_AreaType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_AreaIdentification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_Area(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_Area_sequence, hf_index, ett_gsm_map_lcs_Area);
return offset;
}
static int
dissect_gsm_map_lcs_AreaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_AreaList_sequence_of, hf_index, ett_gsm_map_lcs_AreaList);
return offset;
}
static int
dissect_gsm_map_lcs_AreaDefinition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_AreaDefinition_sequence, hf_index, ett_gsm_map_lcs_AreaDefinition);
return offset;
}
static int
dissect_gsm_map_lcs_OccurrenceInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_IntervalTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_AreaEventInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_AreaEventInfo_sequence, hf_index, ett_gsm_map_lcs_AreaEventInfo);
return offset;
}
static int
dissect_gsm_map_lcs_ReportingAmount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ReportingInterval(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_PeriodicLDRInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_PeriodicLDRInfo_sequence, hf_index, ett_gsm_map_lcs_PeriodicLDRInfo);
return offset;
}
static int
dissect_gsm_map_lcs_RAN_Technology(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ReportingPLMN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_ReportingPLMN_sequence, hf_index, ett_gsm_map_lcs_ReportingPLMN);
return offset;
}
static int
dissect_gsm_map_lcs_PLMNList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_PLMNList_sequence_of, hf_index, ett_gsm_map_lcs_PLMNList);
return offset;
}
static int
dissect_gsm_map_lcs_ReportingPLMNList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_ReportingPLMNList_sequence, hf_index, ett_gsm_map_lcs_ReportingPLMNList);
return offset;
}
static int
dissect_gsm_map_lcs_ProvideSubscriberLocation_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_ProvideSubscriberLocation_Arg_sequence, hf_index, ett_gsm_map_lcs_ProvideSubscriberLocation_Arg);
return offset;
}
int
dissect_gsm_map_lcs_Ext_GeographicalInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 902 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (!parameter_tvb)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_GeographicalInformation);
dissect_geographical_description(parameter_tvb, actx->pinfo, subtree);
return offset;
}
int
dissect_gsm_map_lcs_Add_GeographicalInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_PositioningDataInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_UtranPositioningDataInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_AccuracyFulfilmentIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_map_lcs_VelocityEstimate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_GeranGANSSpositioningData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_UtranGANSSpositioningData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ServingNodeAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_lcs_ServingNodeAddress_choice, hf_index, ett_gsm_map_lcs_ServingNodeAddress,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_ProvideSubscriberLocation_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_ProvideSubscriberLocation_Res_sequence, hf_index, ett_gsm_map_lcs_ProvideSubscriberLocation_Res);
return offset;
}
static int
dissect_gsm_map_lcs_LCS_Event(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_TerminationCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_Deferredmt_lrData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_Deferredmt_lrData_sequence, hf_index, ett_gsm_map_lcs_Deferredmt_lrData);
return offset;
}
static int
dissect_gsm_map_lcs_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_lcs_SubscriberLocationReport_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_SubscriberLocationReport_Arg_sequence, hf_index, ett_gsm_map_lcs_SubscriberLocationReport_Arg);
return offset;
}
static int
dissect_gsm_map_lcs_SubscriberLocationReport_Res(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_lcs_SubscriberLocationReport_Res_sequence, hf_index, ett_gsm_map_lcs_SubscriberLocationReport_Res);
return offset;
}
int dissect_gsm_map_lcs_LCS_ClientID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_gsm_map_lcs_LCS_ClientID(FALSE, tvb, offset, &asn1_ctx, tree, hf_gsm_map_lcs_gsm_map_lcs_LCS_ClientID_PDU);
return offset;
}
static int
dissect_gsm_map_gr_CODEC_Info(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_CipheringAlgorithm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_GroupKeyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_gr_VSTK(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_VSTK_RAND(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_PrepareGroupCallArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_PrepareGroupCallArg_sequence, hf_index, ett_gsm_map_gr_PrepareGroupCallArg);
return offset;
}
static int
dissect_gsm_map_gr_PrepareGroupCallRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_PrepareGroupCallRes_sequence, hf_index, ett_gsm_map_gr_PrepareGroupCallRes);
return offset;
}
static int
dissect_gsm_map_gr_TalkerPriority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_SendGroupCallEndSignalArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_SendGroupCallEndSignalArg_sequence, hf_index, ett_gsm_map_gr_SendGroupCallEndSignalArg);
return offset;
}
static int
dissect_gsm_map_gr_SendGroupCallEndSignalRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_SendGroupCallEndSignalRes_sequence, hf_index, ett_gsm_map_gr_SendGroupCallEndSignalRes);
return offset;
}
static int
dissect_gsm_map_gr_StateAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_StateAttributes_sequence, hf_index, ett_gsm_map_gr_StateAttributes);
return offset;
}
static int
dissect_gsm_map_gr_ForwardGroupCallSignallingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_ForwardGroupCallSignallingArg_sequence, hf_index, ett_gsm_map_gr_ForwardGroupCallSignallingArg);
return offset;
}
static int
dissect_gsm_map_gr_ProcessGroupCallSignallingArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_ProcessGroupCallSignallingArg_sequence, hf_index, ett_gsm_map_gr_ProcessGroupCallSignallingArg);
return offset;
}
static int
dissect_gsm_map_gr_RequestedInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_gr_SendGroupCallInfoArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_SendGroupCallInfoArg_sequence, hf_index, ett_gsm_map_gr_SendGroupCallInfoArg);
return offset;
}
static int
dissect_gsm_map_gr_SendGroupCallInfoRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_gr_SendGroupCallInfoRes_sequence, hf_index, ett_gsm_map_gr_SendGroupCallInfoRes);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_OpenInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_OpenInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_OpenInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_AcceptInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_AcceptInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_AcceptInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_CloseInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_CloseInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_CloseInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_Reason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_RefuseInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_RefuseInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_RefuseInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_map_dialogue_ResourceUnavailableReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_ProcedureCancellationReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_UserAbortChoice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_dialogue_MAP_UserAbortChoice_choice, hf_index, ett_gsm_map_dialogue_MAP_UserAbortChoice,
NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_UserAbortInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_UserAbortInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_UserAbortInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_ProviderAbortReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_ProviderAbortInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_dialogue_MAP_ProviderAbortInfo_sequence, hf_index, ett_gsm_map_dialogue_MAP_ProviderAbortInfo);
return offset;
}
static int
dissect_gsm_map_dialogue_MAP_DialoguePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_map_dialogue_MAP_DialoguePDU_choice, hf_index, ett_gsm_map_dialogue_MAP_DialoguePDU,
NULL);
return offset;
}
static int dissect_gsm_map_dialogue_MAP_DialoguePDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_gsm_map_dialogue_MAP_DialoguePDU(FALSE, tvb, offset, &asn1_ctx, tree, hf_gsm_map_dialogue_gsm_map_dialogue_MAP_DialoguePDU_PDU);
return offset;
}
static int
dissect_gsm_old_InvokeIdType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_GSMMAPOperationLocalvalue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 212 "../../asn1/gsm_map/gsm_map.cnf"
const char *opcode_string;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&opcode);
opcode_string = gsm_map_opr_code(opcode, actx->created_item);
col_append_str(actx->pinfo->cinfo, COL_INFO, opcode_string);
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
return offset;
}
static int
dissect_gsm_old_OperationLocalvalue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_old_GSMMAPOperationLocalvalue(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_old_MAP_OPERATION(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_MAP_OPERATION_choice, hf_index, ett_gsm_old_MAP_OPERATION,
NULL);
return offset;
}
static int
dissect_gsm_old_InvokeParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 199 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_invokeData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_gsm_old_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_Invoke_sequence, hf_index, ett_gsm_old_Invoke);
return offset;
}
static int
dissect_gsm_old_ReturnResultParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 202 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_returnResultData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_gsm_old_T_resultretres(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_T_resultretres_sequence, hf_index, ett_gsm_old_T_resultretres);
return offset;
}
static int
dissect_gsm_old_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_ReturnResult_sequence, hf_index, ett_gsm_old_ReturnResult);
return offset;
}
int
dissect_gsm_old_GSMMAPLocalErrorcode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&errorCode);
return offset;
}
static int
dissect_gsm_old_LocalErrorcode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_old_GSMMAPLocalErrorcode(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_MAP_ERROR(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_MAP_ERROR_choice, hf_index, ett_gsm_old_MAP_ERROR,
NULL);
return offset;
}
static int
dissect_gsm_old_ReturnErrorParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 205 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_returnErrorData(tree, tvb, offset, actx);
return offset;
}
static int
dissect_gsm_old_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_ReturnError_sequence, hf_index, ett_gsm_old_ReturnError);
return offset;
}
static int
dissect_gsm_old_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_old_T_invokeIDRej(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_T_invokeIDRej_choice, hf_index, ett_gsm_old_T_invokeIDRej,
NULL);
return offset;
}
static int
dissect_gsm_old_GeneralProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_InvokeProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_ReturnResultProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_ReturnErrorProblem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_T_problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_T_problem_choice, hf_index, ett_gsm_old_T_problem,
NULL);
return offset;
}
static int
dissect_gsm_old_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_Reject_sequence, hf_index, ett_gsm_old_Reject);
return offset;
}
static int
dissect_gsm_old_Component(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_Component_choice, hf_index, ett_gsm_old_Component,
NULL);
return offset;
}
static int
dissect_gsm_old_Bss_APDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 728 "../../asn1/gsm_map/gsm_map.cnf"
guint8 octet;
guint8 length;
tvbuff_t *next_tvb;
proto_tree *subtree;
ProtocolId = 0xffffffff;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_Bss_APDU_sequence, hf_index, ett_gsm_old_Bss_APDU);
if (!actx->value_ptr)
return offset;
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_externalsignalinfo);
switch (ProtocolId){
case 1:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
proto_tree_add_item(subtree, hf_gsm_map_ie_tag, (tvbuff_t*)actx->value_ptr, 0,1,ENC_BIG_ENDIAN);
length = tvb_get_guint8((tvbuff_t*)actx->value_ptr,1);
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
switch(octet){
case 4:
de_bearer_cap((tvbuff_t*)actx->value_ptr, subtree, actx->pinfo, 2, length, NULL, 0);
break;
default:
proto_tree_add_expert(subtree, actx->pinfo, &ei_gsm_map_undecoded, (tvbuff_t*)actx->value_ptr, 0, length);
break;
}
break;
case 2:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
proto_tree_add_item(subtree, hf_gsm_map_disc_par, (tvbuff_t*)actx->value_ptr, 0,1,ENC_BIG_ENDIAN);
if ( octet == 0) {
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 2);
call_dissector_with_data(bssap_handle, next_tvb, actx->pinfo, subtree,
p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_gsm_map, actx->pinfo->curr_layer_num));
}else if(octet==1){
proto_tree_add_item(subtree, hf_gsm_map_dlci, (tvbuff_t*)actx->value_ptr, 1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_len, (tvbuff_t*)actx->value_ptr, 2,1,ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 3);
call_dissector(dtap_handle, next_tvb, actx->pinfo, subtree);
}
break;
case 3:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
if ( octet == 0) {
next_tvb = tvb_new_subset_remaining((tvbuff_t*)actx->value_ptr, 2);
call_dissector_with_data(bssap_handle, next_tvb, actx->pinfo, subtree,
p_get_proto_data(actx->pinfo->pool, actx->pinfo, proto_gsm_map, actx->pinfo->curr_layer_num));
}
break;
case 4:
octet = tvb_get_guint8((tvbuff_t*)actx->value_ptr,0);
length = tvb_get_guint8((tvbuff_t*)actx->value_ptr,1);
if ( octet == 4 )
dissect_q931_bearer_capability_ie((tvbuff_t*)actx->value_ptr, 2, length, subtree);
break;
default:
break;
}
return offset;
}
static int
dissect_gsm_old_CallDirection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_ProvideSIWFSNumberArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_ProvideSIWFSNumberArg_sequence, hf_index, ett_gsm_old_ProvideSIWFSNumberArg);
return offset;
}
static int
dissect_gsm_old_ProvideSIWFSNumberRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_ProvideSIWFSNumberRes_sequence, hf_index, ett_gsm_old_ProvideSIWFSNumberRes);
return offset;
}
static int
dissect_gsm_old_PurgeMSArgV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_PurgeMSArgV2_sequence, hf_index, ett_gsm_old_PurgeMSArgV2);
return offset;
}
static int
dissect_gsm_old_PrepareHO_ArgOld(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_PrepareHO_ArgOld_sequence, hf_index, ett_gsm_old_PrepareHO_ArgOld);
return offset;
}
static int
dissect_gsm_old_PrepareHO_ResOld(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_PrepareHO_ResOld_sequence, hf_index, ett_gsm_old_PrepareHO_ResOld);
return offset;
}
static int
dissect_gsm_old_RAND(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_SRES(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_Kc(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_SendAuthenticationInfoResOld_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendAuthenticationInfoResOld_item_sequence, hf_index, ett_gsm_old_SendAuthenticationInfoResOld_item);
return offset;
}
static int
dissect_gsm_old_SendAuthenticationInfoResOld(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendAuthenticationInfoResOld_sequence_of, hf_index, ett_gsm_old_SendAuthenticationInfoResOld);
return offset;
}
static int
dissect_gsm_old_AuthenticationTriplet_v2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_AuthenticationTriplet_v2_sequence, hf_index, ett_gsm_old_AuthenticationTriplet_v2);
return offset;
}
static int
dissect_gsm_old_TripletListold(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_old_TripletListold_sequence_of, hf_index, ett_gsm_old_TripletListold);
return offset;
}
static int
dissect_gsm_old_SendIdentificationResV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendIdentificationResV2_sequence, hf_index, ett_gsm_old_SendIdentificationResV2);
return offset;
}
static int
dissect_gsm_old_SIWFSSignallingModifyArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SIWFSSignallingModifyArg_sequence, hf_index, ett_gsm_old_SIWFSSignallingModifyArg);
return offset;
}
static int
dissect_gsm_old_SIWFSSignallingModifyRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SIWFSSignallingModifyRes_sequence, hf_index, ett_gsm_old_SIWFSSignallingModifyRes);
return offset;
}
int
dissect_gsm_old_NewPassword(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_old_GetPasswordArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_old_CurrentPassword(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_NumericString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_SecurityParametersIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_OperationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_OperationCode_choice, hf_index, ett_gsm_old_OperationCode,
NULL);
return offset;
}
static int
dissect_gsm_old_ErrorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_ErrorCode_choice, hf_index, ett_gsm_old_ErrorCode,
NULL);
return offset;
}
static int
dissect_gsm_old_OriginalComponentIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_OriginalComponentIdentifier_choice, hf_index, ett_gsm_old_OriginalComponentIdentifier,
NULL);
return offset;
}
static int
dissect_gsm_old_InitialisationVector(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_old_SecurityHeader(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SecurityHeader_sequence, hf_index, ett_gsm_old_SecurityHeader);
return offset;
}
int
dissect_gsm_old_ProtectedPayload(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_SecureTransportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SecureTransportArg_sequence, hf_index, ett_gsm_old_SecureTransportArg);
return offset;
}
static int
dissect_gsm_old_SecureTransportErrorParam(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SecureTransportErrorParam_sequence, hf_index, ett_gsm_old_SecureTransportErrorParam);
return offset;
}
static int
dissect_gsm_old_SecureTransportRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SecureTransportRes_sequence, hf_index, ett_gsm_old_SecureTransportRes);
return offset;
}
static int
dissect_gsm_old_Category(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_T_operatorSS_Code(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_old_T_operatorSS_Code_sequence_of, hf_index, ett_gsm_old_T_operatorSS_Code);
return offset;
}
static int
dissect_gsm_old_PlmnContainer_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_PlmnContainer_U_sequence, hf_index, ett_gsm_old_PlmnContainer_U);
return offset;
}
static int
dissect_gsm_old_PlmnContainer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 2, TRUE, dissect_gsm_old_PlmnContainer_U);
return offset;
}
static int
dissect_gsm_old_T_imsi(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 348 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_IMSI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_T_lmsi(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 352 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_LMSI(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_T_serviceCentreAddressDA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 372 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_RECV;
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_SM_RP_DAold(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_SM_RP_DAold_choice, hf_index, ett_gsm_old_SM_RP_DAold,
NULL);
return offset;
}
static int
dissect_gsm_old_T_msisdn(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 364 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_RECV;
offset = dissect_gsm_map_ISDN_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_T_serviceCentreAddressOA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 340 "../../asn1/gsm_map/gsm_map.cnf"
actx->pinfo->p2p_dir = P2P_DIR_SENT;
offset = dissect_gsm_map_AddressString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_gsm_old_SM_RP_OAold(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_SM_RP_OAold_choice, hf_index, ett_gsm_old_SM_RP_OAold,
NULL);
return offset;
}
static int
dissect_gsm_old_ForwardSM_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 399 "../../asn1/gsm_map/gsm_map.cnf"
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_ForwardSM_Arg_sequence, hf_index, ett_gsm_old_ForwardSM_Arg);
if (!actx->value_ptr)
return offset;
if (actx->pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
if (gsmmap_pdu_type == 1) {
actx->pinfo->p2p_dir = P2P_DIR_SENT;
} else {
actx->pinfo->p2p_dir = P2P_DIR_RECV;
}
}
call_dissector_only(gsm_sms_handle, (tvbuff_t*)actx->value_ptr, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_gsm_old_SendRoutingInfoArgV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendRoutingInfoArgV2_sequence, hf_index, ett_gsm_old_SendRoutingInfoArgV2);
return offset;
}
static int
dissect_gsm_old_SendRoutingInfoResV2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendRoutingInfoResV2_sequence, hf_index, ett_gsm_old_SendRoutingInfoResV2);
return offset;
}
static int
dissect_gsm_old_BeginSubscriberActivityArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_BeginSubscriberActivityArg_sequence, hf_index, ett_gsm_old_BeginSubscriberActivityArg);
return offset;
}
static int
dissect_gsm_old_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_old_RoutingInfoForSM_ArgV1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_RoutingInfoForSM_ArgV1_sequence, hf_index, ett_gsm_old_RoutingInfoForSM_ArgV1);
return offset;
}
static int
dissect_gsm_old_Ki(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_RequestParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_old_RequestParameterList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_old_RequestParameterList_sequence_of, hf_index, ett_gsm_old_RequestParameterList);
return offset;
}
static int
dissect_gsm_old_SendParametersArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_old_SendParametersArg_sequence, hf_index, ett_gsm_old_SendParametersArg);
return offset;
}
static int
dissect_gsm_old_SentParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_old_SentParameter_choice, hf_index, ett_gsm_old_SentParameter,
NULL);
return offset;
}
static int
dissect_gsm_old_SentParameterList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_old_SentParameterList_sequence_of, hf_index, ett_gsm_old_SentParameterList);
return offset;
}
static int
dissect_gsm_ss_SS_UserData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_SS_Notification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_gsm_ss_CallOnHold_Indicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_ECT_CallState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_RemotePartyNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_RemotePartyNumber_sequence, hf_index, ett_gsm_ss_RemotePartyNumber);
return offset;
}
static int
dissect_gsm_ss_RDN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_ss_RDN_choice, hf_index, ett_gsm_ss_RDN,
NULL);
return offset;
}
static int
dissect_gsm_ss_ECT_Indicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_ECT_Indicator_sequence, hf_index, ett_gsm_ss_ECT_Indicator);
return offset;
}
static int
dissect_gsm_ss_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_NameSet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_NameSet_sequence, hf_index, ett_gsm_ss_NameSet);
return offset;
}
static int
dissect_gsm_ss_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
gsm_ss_Name_choice, hf_index, ett_gsm_ss_Name,
NULL);
return offset;
}
static int
dissect_gsm_ss_NameIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_NameIndicator_sequence, hf_index, ett_gsm_ss_NameIndicator);
return offset;
}
static int
dissect_gsm_ss_Multicall_Indicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_NotifySS_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_NotifySS_Arg_sequence, hf_index, ett_gsm_ss_NotifySS_Arg);
return offset;
}
static int
dissect_gsm_ss_E1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E3(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E4(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E5(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E6(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_E7(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_ChargingInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_ChargingInformation_sequence, hf_index, ett_gsm_ss_ChargingInformation);
return offset;
}
static int
dissect_gsm_ss_ForwardChargeAdviceArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_ForwardChargeAdviceArg_sequence, hf_index, ett_gsm_ss_ForwardChargeAdviceArg);
return offset;
}
static int
dissect_gsm_ss_ForwardCUG_InfoArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_ForwardCUG_InfoArg_sequence, hf_index, ett_gsm_ss_ForwardCUG_InfoArg);
return offset;
}
static int
dissect_gsm_ss_AccessRegisterCCEntryArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_AccessRegisterCCEntryArg_sequence, hf_index, ett_gsm_ss_AccessRegisterCCEntryArg);
return offset;
}
static int
dissect_gsm_ss_CallDeflectionArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_CallDeflectionArg_sequence, hf_index, ett_gsm_ss_CallDeflectionArg);
return offset;
}
static int
dissect_gsm_ss_UUS_Service(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_gsm_ss_UserUserServiceArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_UserUserServiceArg_sequence, hf_index, ett_gsm_ss_UserUserServiceArg);
return offset;
}
static int
dissect_gsm_ss_LocationNotificationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LocationNotificationArg_sequence, hf_index, ett_gsm_ss_LocationNotificationArg);
return offset;
}
static int
dissect_gsm_ss_VerificationResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_LocationNotificationRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LocationNotificationRes_sequence, hf_index, ett_gsm_ss_LocationNotificationRes);
return offset;
}
static int
dissect_gsm_ss_MOLR_Type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_gsm_ss_LocationMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_GPSAssistanceData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_TerminationCause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_GANSSAssistanceData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_PositioningProtocolPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_MultiplePositioningProtocolPDUs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
gsm_ss_MultiplePositioningProtocolPDUs_sequence_of, hf_index, ett_gsm_ss_MultiplePositioningProtocolPDUs);
return offset;
}
static int
dissect_gsm_ss_LCS_MOLRArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_MOLRArg_sequence, hf_index, ett_gsm_ss_LCS_MOLRArg);
return offset;
}
static int
dissect_gsm_ss_DecipheringKeys(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_gsm_ss_LCS_MOLRRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_MOLRRes_sequence, hf_index, ett_gsm_ss_LCS_MOLRRes);
return offset;
}
static int
dissect_gsm_ss_LCS_AreaEventRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_AreaEventRequestArg_sequence, hf_index, ett_gsm_ss_LCS_AreaEventRequestArg);
return offset;
}
static int
dissect_gsm_ss_LCS_AreaEventReportArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_AreaEventReportArg_sequence, hf_index, ett_gsm_ss_LCS_AreaEventReportArg);
return offset;
}
static int
dissect_gsm_ss_LCS_AreaEventCancellationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_AreaEventCancellationArg_sequence, hf_index, ett_gsm_ss_LCS_AreaEventCancellationArg);
return offset;
}
static int
dissect_gsm_ss_LCS_PeriodicLocationRequestArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_PeriodicLocationRequestArg_sequence, hf_index, ett_gsm_ss_LCS_PeriodicLocationRequestArg);
return offset;
}
static int
dissect_gsm_ss_LCS_PeriodicLocationRequestRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_PeriodicLocationRequestRes_sequence, hf_index, ett_gsm_ss_LCS_PeriodicLocationRequestRes);
return offset;
}
static int
dissect_gsm_ss_LCS_LocationUpdateArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_LocationUpdateArg_sequence, hf_index, ett_gsm_ss_LCS_LocationUpdateArg);
return offset;
}
static int
dissect_gsm_ss_LCS_LocationUpdateRes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_LocationUpdateRes_sequence, hf_index, ett_gsm_ss_LCS_LocationUpdateRes);
return offset;
}
static int
dissect_gsm_ss_LCS_PeriodicLocationCancellationArg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_ss_LCS_PeriodicLocationCancellationArg_sequence, hf_index, ett_gsm_ss_LCS_PeriodicLocationCancellationArg);
return offset;
}
static int
dissect_gsm_map_ericsson_T_locationInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 980 "../../asn1/gsm_map/gsm_map.cnf"
tvbuff_t *parameter_tvb;
proto_tree *subtree;
guint8 rat;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&parameter_tvb);
if (parameter_tvb) {
subtree = proto_item_add_subtree(actx->created_item, ett_gsm_map_ericsson_locationInformation);
rat = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(subtree, hf_gsm_map_ericsson_locationInformation_rat, parameter_tvb, 0, 1, rat);
switch (rat) {
case 0:
proto_tree_add_item(subtree, hf_gsm_map_ericsson_locationInformation_lac, parameter_tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_ericsson_locationInformation_ci, parameter_tvb, 3, 2, ENC_BIG_ENDIAN);
break;
case 1:
proto_tree_add_item(subtree, hf_gsm_map_ericsson_locationInformation_lac, parameter_tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_map_ericsson_locationInformation_sac, parameter_tvb, 3, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
return offset;
}
static int
dissect_gsm_map_ericsson_EnhancedCheckIMEI_Arg(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
gsm_map_ericsson_EnhancedCheckIMEI_Arg_sequence, hf_index, ett_gsm_map_ericsson_EnhancedCheckIMEI_Arg);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RoutingCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ActiveSS_List(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ExtRoutingCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MAPserviceList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MAPserviceCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_VersionInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MKeyVer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MmTdpName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_NokiaMAP_Extensions_ServiceKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_LocupType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_MKey_sequence, hf_index, ett_NokiaMAP_Extensions_MKey);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SmsTdpName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SMSKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SMSKey_sequence, hf_index, ett_NokiaMAP_Extensions_SMSKey);
return offset;
}
static int
dissect_NokiaMAP_Extensions_INKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NokiaMAP_Extensions_INKey_choice, hf_index, ett_NokiaMAP_Extensions_INKey,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_TimeLimit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ActionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_FraudMaxCount(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_FraudData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_FraudData_sequence, hf_index, ett_NokiaMAP_Extensions_FraudData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_FraudInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_FraudInfo_sequence, hf_index, ett_NokiaMAP_Extensions_FraudInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ServiceWithInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ServiceWithInfo_sequence, hf_index, ett_NokiaMAP_Extensions_ServiceWithInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ServiceListWithInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ServiceListWithInfo_sequence_of, hf_index, ett_NokiaMAP_Extensions_ServiceListWithInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_IsdArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_IsdArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_IsdArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DsdArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_DsdArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_DsdArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DsdArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_DsdArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UlResExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_UlResExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_UlResExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UlResExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_UlResExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_InTriggerKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PnpIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CallRedirectionIndex(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ChargingArea(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ChargingAreaList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ChargingAreaList_sequence_of, hf_index, ett_NokiaMAP_Extensions_ChargingAreaList);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RegionalChargingData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_RegionalChargingData_sequence, hf_index, ett_NokiaMAP_Extensions_RegionalChargingData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SS_DataExtension_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SS_DataExtension_U_sequence, hf_index, ett_NokiaMAP_Extensions_SS_DataExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SS_DataExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_SS_DataExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CallingCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_InternalServiceIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriExtension_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriExtension_U_sequence, hf_index, ett_NokiaMAP_Extensions_SriExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_SriExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ExtraProtocolId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ExtraSignalInfo_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ExtraSignalInfo_U_sequence, hf_index, ett_NokiaMAP_Extensions_ExtraSignalInfo_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ExtraSignalInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 1, TRUE, dissect_NokiaMAP_Extensions_ExtraSignalInfo_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CUG_CallInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_Nokia_CUG_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_Nokia_CUG_Data_sequence, hf_index, ett_NokiaMAP_Extensions_Nokia_CUG_Data);
return offset;
}
static int
dissect_NokiaMAP_Extensions_LeaId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OlcmTraceReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OlcmInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_OlcmInfo_sequence, hf_index, ett_NokiaMAP_Extensions_OlcmInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OlcmInfoTable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_OlcmInfoTable_sequence_of, hf_index, ett_NokiaMAP_Extensions_OlcmInfoTable);
return offset;
}
static int
dissect_NokiaMAP_Extensions_NoAnswerTimer(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MemberList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_MemberList_sequence_of, hf_index, ett_NokiaMAP_Extensions_MemberList);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AlertingMethod(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UserType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_RgData_sequence, hf_index, ett_NokiaMAP_Extensions_RgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriResExtension_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriResExtension_U_sequence, hf_index, ett_NokiaMAP_Extensions_SriResExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriResExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_SriResExtension_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CanLocArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_CanLocArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_CanLocArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CanLocArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_CanLocArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ATMargExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ATMargExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_ATMargExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ATMargExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_ATMargExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ATMresExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ATMresExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_ATMresExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ATMresExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_ATMresExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DTMargExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_DTMargExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_DTMargExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DTMargExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_DTMargExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_NumberPorted_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_NumberPorted(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 20, TRUE, dissect_NokiaMAP_Extensions_NumberPorted_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MapOptFields(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CodecExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CodecListExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_CodecListExt_sequence_of, hf_index, ett_NokiaMAP_Extensions_CodecListExt);
return offset;
}
static int
dissect_NokiaMAP_Extensions_Modes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SelectedCodec(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SelectedCodec_sequence, hf_index, ett_NokiaMAP_Extensions_SelectedCodec);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OCTET_STRING_SIZE_5_17(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IPPortNb(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_HO_Ext_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_HO_Ext_U_sequence, hf_index, ett_NokiaMAP_Extensions_HO_Ext_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_HO_Ext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_HO_Ext_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AbsentSubscriberExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_AbsentSubscriberExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_AbsentSubscriberExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AbsentSubscriberExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_AbsentSubscriberExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ErrOlcmInfoTableExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ErrOlcmInfoTableExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_ErrOlcmInfoTableExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ErrOlcmInfoTableExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_ErrOlcmInfoTableExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RoutingCategoryExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_RoutingCategoryExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_RoutingCategoryExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RoutingCategoryExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_RoutingCategoryExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PrivateFeatureCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_INCategoryKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_gsm_map_TBCD_STRING(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_NokiaMAP_Extensions_OickInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_OickInfo_sequence, hf_index, ett_NokiaMAP_Extensions_OickInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SubscriptionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SubscriptionTypeInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SubscriptionTypeInfo_sequence, hf_index, ett_NokiaMAP_Extensions_SubscriptionTypeInfo);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PrivateFeatureData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NokiaMAP_Extensions_PrivateFeatureData_choice, hf_index, ett_NokiaMAP_Extensions_PrivateFeatureData,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_IsdArgData_sequence, hf_index, ett_NokiaMAP_Extensions_IsdArgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdArgType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_IsdArgType_sequence_of, hf_index, ett_NokiaMAP_Extensions_IsdArgType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdResData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_IsdResData_sequence, hf_index, ett_NokiaMAP_Extensions_IsdResData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_IsdResType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_IsdResType_sequence_of, hf_index, ett_NokiaMAP_Extensions_IsdResType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DsdArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_DsdArgData_sequence, hf_index, ett_NokiaMAP_Extensions_DsdArgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_DsdArgType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_DsdArgType_sequence_of, hf_index, ett_NokiaMAP_Extensions_DsdArgType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriArgData_sequence, hf_index, ett_NokiaMAP_Extensions_SriArgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriArgType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriArgType_sequence_of, hf_index, ett_NokiaMAP_Extensions_SriArgType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriResData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriResData_sequence, hf_index, ett_NokiaMAP_Extensions_SriResData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriResType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriResType_sequence_of, hf_index, ett_NokiaMAP_Extensions_SriResType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PrnArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_PrnArgData_sequence, hf_index, ett_NokiaMAP_Extensions_PrnArgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PrnArgType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_PrnArgType_sequence_of, hf_index, ett_NokiaMAP_Extensions_PrnArgType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_PrivateFeatureUlArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NokiaMAP_Extensions_PrivateFeatureUlArgData_choice, hf_index, ett_NokiaMAP_Extensions_PrivateFeatureUlArgData,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UlArgData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_UlArgData_sequence, hf_index, ett_NokiaMAP_Extensions_UlArgData);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UlArgType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_UlArgType_sequence_of, hf_index, ett_NokiaMAP_Extensions_UlArgType);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ExtensionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
NokiaMAP_Extensions_ExtensionType_choice, hf_index, ett_NokiaMAP_Extensions_ExtensionType,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_CfuSMSCounter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriForSMArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_SriForSMArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_SriForSMArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_SriForSMArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_SriForSMArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ReportSMDelStatArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_ReportSMDelStatArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_ReportSMDelStatArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_ReportSMDelStatArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_ReportSMDelStatArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_LocationAreaCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_MO_ForwardSM_ArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UdlArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_UdlArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_UdlArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_UdlArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_UdlArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RoamNotAllowedExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_RoamNotAllowedExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_RoamNotAllowedExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_RoamNotAllowedExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_RoamNotAllowedExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AnyTimeModArgExt_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_AnyTimeModArgExt_U_sequence, hf_index, ett_NokiaMAP_Extensions_AnyTimeModArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AnyTimeModArgExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 0, TRUE, dissect_NokiaMAP_Extensions_AnyTimeModArgExt_U);
return offset;
}
static int
dissect_NokiaMAP_Extensions_Access(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_Version(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AccessTypeExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_AccessTypeExt_sequence, hf_index, ett_NokiaMAP_Extensions_AccessTypeExt);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AccessSubscriptionListExt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_AccessSubscriptionListExt_sequence_of, hf_index, ett_NokiaMAP_Extensions_AccessSubscriptionListExt);
return offset;
}
static int
dissect_NokiaMAP_Extensions_AllowedServiceData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NokiaMAP_Extensions_AllowedServiceData_bits, hf_index, ett_NokiaMAP_Extensions_AllowedServiceData,
NULL);
return offset;
}
const gchar* gsm_map_opr_code(guint32 val, proto_item *item) {
switch (val) {
case 44:
case 46:
if (application_context_version < 3) {
proto_item_set_text(item, "%s (%d)", val_to_str_const(val, gsm_map_V1V2_opr_code_strings, "Unknown GSM-MAP opcode"), val);
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
octet = tvb_get_guint8(tvb,0);
if ( (octet & 0xf) == 3) {
offset = get_ber_identifier(tvb, offset, &bug_class, &bug_pc, &bug_tag);
offset = get_ber_length(tvb, offset, &bug_len, &bug_ind_field);
if (sequence3 != NULL) {
offset= (sequence3) (implicit_seq3, tvb, offset, actx, tree, hf_index_seq3);
} else {
proto_tree_add_expert(tree, actx->pinfo, &ei_gsm_map_unknown_sequence3, tvb, offset, -1);
}
} else if (octet == 0x30) {
if (sequence != NULL) {
offset= (sequence) (implicit_seq, tvb, 0, actx, tree, hf_index_seq);
} else {
proto_tree_add_expert(tree, actx->pinfo, &ei_gsm_map_unknown_sequence, tvb, offset, -1);
}
} else {
if (parameter != NULL) {
offset= (parameter) (implicit_param, tvb, offset, actx, tree, hf_index_param);
} else {
proto_tree_add_expert(tree, actx->pinfo, &ei_gsm_map_unknown_parameter, tvb, offset, -1);
}
}
return offset;
}
static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
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
case 9:
offset = dissect_gsm_old_SendParametersArg(FALSE, tvb, offset, actx, tree, -1);
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
case 36:
offset=dissect_gsm_map_ms_CancelVcsgLocationArg(FALSE, tvb, offset, actx, tree, -1);
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
if (application_context_version == 1) {
offset=dissect_gsm_old_RoutingInfoForSM_ArgV1(FALSE, tvb, offset, actx, tree, -1);
} else {
offset=dissect_gsm_map_sm_RoutingInfoForSM_Arg(FALSE, tvb, offset, actx, tree, -1);
}
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
case 53:
offset=dissect_gsm_map_ms_UpdateVcsgLocationArg(FALSE, tvb, offset, actx, tree, -1);
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
proto_tree_add_expert_format(tree, actx->pinfo, &ei_gsm_map_unknown_invokeData,
tvb, offset, -1, "Unknown invokeData %d", opcode);
}
offset+= tvb_reported_length_remaining(tvb,offset);
break;
}
return offset;
}
static int dissect_returnResultData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
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
case 9:
offset = dissect_gsm_old_SentParameterList(FALSE, tvb, offset, actx, tree, -1);
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
case 36:
offset=dissect_gsm_map_ms_CancelVcsgLocationRes(FALSE, tvb, offset, actx, tree, -1);
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
FALSE, dissect_gsm_map_sm_ReportSM_DeliveryStatusRes, -1,
FALSE, NULL, -1);
break;
case 48:
break;
case 50:
offset=dissect_gsm_map_om_ActivateTraceModeRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 51:
offset=dissect_gsm_map_om_DeactivateTraceModeRes(FALSE, tvb, offset, actx, tree, -1);
break;
case 53:
offset=dissect_gsm_map_ms_UpdateVcsgLocationRes(FALSE, tvb, offset, actx, tree, -1);
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
proto_tree_add_expert_format(tree, actx->pinfo, &ei_gsm_map_unknown_invokeData, tvb, offset, -1, "Unknown returnResultData blob");
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
proto_tree_add_expert_format(tree, actx->pinfo, &ei_gsm_map_unknown_invokeData,
tvb, offset, -1, "Unknown returnResultData %d", opcode);
}
offset+= tvb_reported_length_remaining(tvb,offset);
break;
}
return offset;
}
static int dissect_returnErrorData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
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
proto_tree_add_expert_format(tree, actx->pinfo, &ei_gsm_map_unknown_invokeData,
tvb, offset, -1, "Unknown returnErrorData %d", opcode);
}
offset+= tvb_reported_length_remaining(tvb,offset);
break;
}
return offset;
}
static void dissect_gsm_mapext_PlmnContainer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_gsm_old_PlmnContainer_U, NULL, "MAP Ext. Plmn Container");
dissect_gsm_old_PlmnContainer(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_SriResExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_SriResExtension_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_SriResExtension(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_CanLocArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_CanLocArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_CanLocArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_ATMargExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_ATMargExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_ATMargExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_DTMargExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_DTMargExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_DTMargExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_NumberPorted(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_NumberPorted(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_ATMresExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_ATMresExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_ATMresExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_AbsentSubscriberExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_AbsentSubscriberExt(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_SriForSMArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_SriForSMArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_SriForSMArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_ReportSMDelStatArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_ReportSMDelStatArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_ReportSMDelStatArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_UdlArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_UdlArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_UdlArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_RoamNotAllowedExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_RoamNotAllowedExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_RoamNotAllowedExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_MO_ForwardSM_ArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_MO_ForwardSM_ArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_ErrOlcmInfoTableExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_ErrOlcmInfoTableExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_ErrOlcmInfoTableExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_RoutingCategoryExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_RoutingCategoryExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_RoutingCategoryExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_AnyTimeModArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_AnyTimeModArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_AnyTimeModArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_ExtensionType(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_ExtensionType(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_AccessTypeExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_AccessTypeExt(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_AccessSubscriptionListExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_AccessSubscriptionListExt(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_AllowedServiceData(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_NokiaMAP_Extensions_AllowedServiceData(FALSE, tvb, 0, &asn1_ctx, parent_tree, -1);
}
static void dissect_NokiaMAP_ext_SriExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_SriExtension_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_SriExtension(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ExtraSignalInfo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_ExtraSignalInfo_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_ExtraSignalInfo(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_SS_DataExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_SS_DataExtension_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_SS_DataExtension(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_HOExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_HO_Ext_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_HO_Ext(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_UlResExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_UlResExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_UlResExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_IsdArgExtension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_IsdArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_IsdArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static void dissect_NokiaMAP_ext_DsdArgExt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree) {
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
tree = proto_tree_add_subtree(parent_tree, tvb, 0, -1, ett_NokiaMAP_Extensions_DsdArgExt_U, NULL, "Nokia Extension");
dissect_NokiaMAP_Extensions_DsdArgExt(FALSE, tvb, 0, &asn1_ctx, tree, -1);
}
static int
dissect_gsm_map_GSMMAPPDU(gboolean implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree,
int hf_index _U_, struct tcap_private_t * p_private_tcap) {
char *version_ptr;
opcode = 0;
if (pref_application_context_version == APPLICATON_CONTEXT_FROM_TRACE) {
application_context_version = 0;
if (p_private_tcap != NULL){
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
col_set_str(actx->pinfo->cinfo, COL_INFO, val_to_str_const(gsmmap_pdu_type, gsm_old_Component_vals, "Unknown GSM-MAP Component"));
col_append_str(actx->pinfo->cinfo, COL_INFO, " ");
offset = dissect_gsm_old_Component(FALSE, tvb, 0, actx, tree, hf_gsm_map_old_Component_PDU);
return offset;
}
static int
dissect_gsm_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
static gsm_map_tap_rec_t tap_rec;
gint op_idx;
struct tcap_private_t * p_private_tcap = (struct tcap_private_t *)data;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM MAP");
top_tree = parent_tree;
item = proto_tree_add_item(parent_tree, proto_gsm_map, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_gsm_map);
dissect_gsm_map_GSMMAPPDU(FALSE, tvb, 0, &asn1_ctx, tree, -1, p_private_tcap);
try_val_to_str_idx(opcode, gsm_map_opr_code_strings, &op_idx);
if (op_idx != -1) {
tap_rec.invoke = (gsmmap_pdu_type == 1) ? TRUE : FALSE;
tap_rec.opcode = opcode;
tap_rec.size = gsm_map_pdu_size;
tap_queue_packet(gsm_map_tap, pinfo, &tap_rec);
}
return tvb_captured_length(tvb);
}
static int
dissect_gsm_map_sccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
static gsm_map_tap_rec_t tap_rec;
gint op_idx;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM MAP");
top_tree = parent_tree;
item = proto_tree_add_item(parent_tree, proto_gsm_map, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_gsm_map);
p_add_proto_data(pinfo->pool, pinfo, proto_gsm_map, pinfo->curr_layer_num, data);
dissect_gsm_map_GSMMAPPDU(FALSE, tvb, 0, &asn1_ctx, tree, -1, NULL);
try_val_to_str_idx(opcode, gsm_map_opr_code_strings, &op_idx);
if (op_idx != -1) {
tap_rec.invoke = (gsmmap_pdu_type == 1) ? TRUE : FALSE;
tap_rec.opcode = opcode;
tap_rec.size = gsm_map_pdu_size;
tap_queue_packet(gsm_map_tap, pinfo, &tap_rec);
}
return tvb_captured_length(tvb);
}
static void gsm_map_stat_init(new_stat_tap_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(gsm_map_stat_fields)/sizeof(stat_tap_table_item);
new_stat_tap_table* table;
guint i;
stat_tap_table_item_type items[sizeof(gsm_map_stat_fields)/sizeof(stat_tap_table_item)];
memset(items, 0, sizeof(items));
items[ID_COLUMN].type = TABLE_ITEM_UINT;
items[OP_CODE_COLUMN].type = TABLE_ITEM_STRING;
items[INVOKES_COLUMN].type = TABLE_ITEM_UINT;
items[NUM_BYTES_FWD_COLUMN].type = TABLE_ITEM_UINT;
items[AVG_BYTES_FWD_COLUMN].type = TABLE_ITEM_FLOAT;
items[RET_RES_COLUMN].type = TABLE_ITEM_UINT;
items[NUM_BYTES_REV_COLUMN].type = TABLE_ITEM_UINT;
items[AVG_BYTES_REV_COLUMN].type = TABLE_ITEM_FLOAT;
items[TOT_BYTES_COLUMN].type = TABLE_ITEM_UINT;
items[AVG_BYTES_COLUMN].type = TABLE_ITEM_FLOAT;
table = new_stat_tap_init_table("GSM MAP Operation Statistics", num_fields, 0, NULL, gui_callback, gui_data);
new_stat_tap_add_table(new_stat, table);
for (i = 0; i < GSM_MAP_MAX_NUM_OPR_CODES; i++)
{
const char *ocs = try_val_to_str(i, gsm_map_opr_code_strings);
char *col_str;
if (ocs) {
col_str = g_strdup(ocs);
} else {
col_str = g_strdup_printf("Unknown op code %d", i);
}
items[ID_COLUMN].value.uint_value = i;
items[OP_CODE_COLUMN].value.string_value = col_str;
new_stat_tap_init_table_row(table, i, num_fields, items);
}
}
static gboolean
gsm_map_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gmtr_ptr)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const gsm_map_tap_rec_t *gmtr = (const gsm_map_tap_rec_t *)gmtr_ptr;
new_stat_tap_table* table;
stat_tap_table_item_type *invoke_data, *fwd_bytes_data, *result_data, *rev_bytes_data, *avg_data;
guint invokes, fwd_bytes, results, rev_bytes;
guint i = 0;
table = g_array_index(stat_data->new_stat_tap_data->tables, new_stat_tap_table*, i);
invoke_data = new_stat_tap_get_field_data(table, gmtr->opcode, INVOKES_COLUMN);
fwd_bytes_data = new_stat_tap_get_field_data(table, gmtr->opcode, NUM_BYTES_FWD_COLUMN);
result_data = new_stat_tap_get_field_data(table, gmtr->opcode, RET_RES_COLUMN);
rev_bytes_data = new_stat_tap_get_field_data(table, gmtr->opcode, NUM_BYTES_REV_COLUMN);
if (gmtr->invoke)
{
invoke_data->value.uint_value++;
new_stat_tap_set_field_data(table, gmtr->opcode, INVOKES_COLUMN, invoke_data);
fwd_bytes_data->value.uint_value += gmtr->size;
new_stat_tap_set_field_data(table, gmtr->opcode, NUM_BYTES_FWD_COLUMN, fwd_bytes_data);
}
else
{
result_data->value.uint_value++;
new_stat_tap_set_field_data(table, gmtr->opcode, RET_RES_COLUMN, result_data);
rev_bytes_data->value.uint_value += gmtr->size;
new_stat_tap_set_field_data(table, gmtr->opcode, NUM_BYTES_REV_COLUMN, rev_bytes_data);
}
invokes = invoke_data->value.uint_value;
fwd_bytes = fwd_bytes_data->value.uint_value;
results = result_data->value.uint_value;
rev_bytes = rev_bytes_data->value.uint_value;
if (gmtr->invoke)
{
avg_data = new_stat_tap_get_field_data(table, gmtr->opcode, AVG_BYTES_FWD_COLUMN);
avg_data->value.float_value += (float) fwd_bytes / invokes;
new_stat_tap_set_field_data(table, gmtr->opcode, AVG_BYTES_FWD_COLUMN, avg_data);
}
else
{
avg_data = new_stat_tap_get_field_data(table, gmtr->opcode, AVG_BYTES_REV_COLUMN);
avg_data->value.float_value += (float) rev_bytes / results;
new_stat_tap_set_field_data(table, gmtr->opcode, AVG_BYTES_REV_COLUMN, avg_data);
}
avg_data = new_stat_tap_get_field_data(table, gmtr->opcode, AVG_BYTES_COLUMN);
avg_data->value.float_value += (float) (fwd_bytes + rev_bytes) / (invokes + results);
new_stat_tap_set_field_data(table, gmtr->opcode, AVG_BYTES_COLUMN, avg_data);
return TRUE;
}
static void
gsm_map_stat_reset(new_stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, INVOKES_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, INVOKES_COLUMN, item_data);
}
}
static void
gsm_map_stat_free_table_item(new_stat_tap_table* table _U_, guint row _U_, guint column, stat_tap_table_item_type* field_data)
{
if (column != OP_CODE_COLUMN) return;
g_free((char*)field_data->value.string_value);
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
gsm_sms_handle = find_dissector("gsm_sms");
bssap_handle = find_dissector("gsm_a_bssmap");
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
register_ber_oid_dissector("0.34.0",dissect_NokiaMAP_ext_IsdArgExtension,proto_gsm_map,"Nokia ISD Extension");
register_ber_oid_dissector("0.34.1",dissect_NokiaMAP_ext_DsdArgExt,proto_gsm_map,"Nokia Dsd Extension");
register_ber_oid_dissector("0.34.2",dissect_NokiaMAP_ext_UlResExtension,proto_gsm_map,"Nokia Location Update Extension");
register_ber_oid_dissector("0.34.4",dissect_NokiaMAP_ext_SS_DataExtension,proto_gsm_map,"Nokia SS Data Extension");
register_ber_oid_dissector("0.34.5",dissect_NokiaMAP_ext_SriExtension,proto_gsm_map,"Nokia SRI Request Extension");
register_ber_oid_dissector("0.34.6",dissect_NokiaMAP_ExtraSignalInfo,proto_gsm_map,"Nokia ExtraSignalInfo Extension");
register_ber_oid_dissector("0.34.7",dissect_NokiaMAP_ext_SriResExtension,proto_gsm_map,"Nokia SRI Response Extension");
register_ber_oid_dissector("0.34.10",dissect_NokiaMAP_ext_CanLocArgExt,proto_gsm_map,"Nokia Cancel Location Extension");
register_ber_oid_dissector("0.34.11",dissect_NokiaMAP_ext_ATMargExt,proto_gsm_map,"Nokia ATM Extension");
register_ber_oid_dissector("0.34.12",dissect_NokiaMAP_ext_DTMargExt,proto_gsm_map,"Nokia DTM Extension");
register_ber_oid_dissector("0.34.13",dissect_NokiaMAP_ext_NumberPorted,proto_gsm_map,"Nokia NumberPorted Extension");
register_ber_oid_dissector("0.34.15",dissect_NokiaMAP_ext_HOExtension,proto_gsm_map,"Nokia HandOver Extension");
register_ber_oid_dissector("0.34.16",dissect_NokiaMAP_ext_ATMresExt,proto_gsm_map,"Nokia ATMres Extension");
register_ber_oid_dissector("0.34.17",dissect_NokiaMAP_ext_AbsentSubscriberExt,proto_gsm_map,"Nokia AbsentSubscriber Extension");
register_ber_oid_dissector("0.34.18",dissect_NokiaMAP_ext_SriForSMArgExt,proto_gsm_map,"Nokia SriForSM Extension");
register_ber_oid_dissector("0.34.19",dissect_NokiaMAP_ext_ReportSMDelStatArgExt,proto_gsm_map,"Nokia ReportSMDelStatt Extension");
register_ber_oid_dissector("0.34.20",dissect_NokiaMAP_ext_UdlArgExt,proto_gsm_map,"Nokia Udl Extension");
register_ber_oid_dissector("0.34.21",dissect_NokiaMAP_ext_RoamNotAllowedExt,proto_gsm_map,"Nokia RoamNotAllowed Extension");
register_ber_oid_dissector("0.34.22",dissect_NokiaMAP_ext_MO_ForwardSM_ArgExt,proto_gsm_map,"Nokia MO-ForwardSM Extension");
register_ber_oid_dissector("0.34.23",dissect_NokiaMAP_ext_ErrOlcmInfoTableExt,proto_gsm_map,"Nokia ErrOlcmInfoTable Extension");
register_ber_oid_dissector("0.34.25",dissect_NokiaMAP_ext_RoutingCategoryExt,proto_gsm_map,"Nokia Routing Category Extension");
register_ber_oid_dissector("0.34.26",dissect_NokiaMAP_ext_AnyTimeModArgExt,proto_gsm_map,"Nokia AnyTimeMod Extension");
register_ber_oid_dissector("1.2.826.0.1249.58.1.0",dissect_NokiaMAP_ext_ExtensionType,proto_gsm_map,"Nokia ExtensionType Extension");
register_ber_oid_dissector("1.3.12.2.1107.3.66.1.1",dissect_NokiaMAP_ext_AccessTypeExt,proto_gsm_map,"Nokia AccessTypeExt Extension");
register_ber_oid_dissector("1.3.12.2.1107.3.66.1.3",dissect_NokiaMAP_ext_AccessSubscriptionListExt,proto_gsm_map,"Nokia AccessSubscriptionListExt Extension");
register_ber_oid_dissector("1.3.12.2.1107.3.66.1.6",dissect_NokiaMAP_ext_AllowedServiceData,proto_gsm_map,"Nokia AllowedServiceData Extension");
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
expert_module_t* expert_gsm_map;
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
{ &hf_gsm_map_address_digits,
{ "Address digits", "gsm_map.address.digits",
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
FT_IPv6, BASE_NONE, NULL, 0,
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
{ &hf_gsm_map_ussd_string,
{ "USSD String", "gsm_map.ussd_string",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 1 "../../asn1/gsm_map/packet-gsm_map-hfarr.c"
{ &hf_gsm_map_privateExtensionList,
{ "privateExtensionList", "gsm_map.privateExtensionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_pcs_Extensions,
{ "pcs-Extensions", "gsm_map.pcs_Extensions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_slr_Arg_PCS_Extensions,
{ "slr-Arg-PCS-Extensions", "gsm_map.slr_Arg_PCS_Extensions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_PrivateExtensionList_item,
{ "PrivateExtension", "gsm_map.PrivateExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_extId,
{ "extId", "gsm_map.extId",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_extType,
{ "extType", "gsm_map.extType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_na_ESRK_Request,
{ "na-ESRK-Request", "gsm_map.na_ESRK_Request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gsm_map_ISDN_AddressString_PDU,
{ "ISDN-AddressString", "gsm_map.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_protocolId,
{ "protocolId", "gsm_map.protocolId",
FT_UINT32, BASE_DEC, VALS(gsm_map_ProtocolId_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_signalInfo,
{ "signalInfo", "gsm_map.signalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_extensionContainer,
{ "extensionContainer", "gsm_map.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ext_ProtocolId,
{ "ext-ProtocolId", "gsm_map.ext_ProtocolId",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_ProtocolId_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_accessNetworkProtocolId,
{ "accessNetworkProtocolId", "gsm_map.accessNetworkProtocolId",
FT_UINT32, BASE_DEC, VALS(gsm_map_AccessNetworkProtocolId_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_signalInfo_01,
{ "signalInfo", "gsm_map.signalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"LongSignalInfo", HFILL }},
{ &hf_gsm_map_imsi,
{ "imsi", "gsm_map.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_imsi_WithLMSI,
{ "imsi-WithLMSI", "gsm_map.imsi_WithLMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lmsi,
{ "lmsi", "gsm_map.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_HLR_List_item,
{ "HLR-Id", "gsm_map.HLR_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_naea_PreferredCIC,
{ "naea-PreferredCIC", "gsm_map.naea_PreferredCIC",
FT_BYTES, BASE_NONE, NULL, 0,
"NAEA_CIC", HFILL }},
{ &hf_gsm_map_msisdn,
{ "msisdn", "gsm_map.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_externalAddress,
{ "externalAddress", "gsm_map.externalAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_diameter_Name,
{ "diameter-Name", "gsm_map.diameter_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_diameter_Realm,
{ "diameter-Realm", "gsm_map.diameter_Realm",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_cellGlobalIdOrServiceAreaIdFixedLength,
{ "cellGlobalIdOrServiceAreaIdFixedLength", "gsm_map.cellGlobalIdOrServiceAreaIdFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_laiFixedLength,
{ "laiFixedLength", "gsm_map.laiFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_bearerService,
{ "bearerService", "gsm_map.bearerService",
FT_UINT8, BASE_DEC, VALS(Bearerservice_vals), 0,
"BearerServiceCode", HFILL }},
{ &hf_gsm_map_teleservice,
{ "teleservice", "gsm_map.teleservice",
FT_UINT8, BASE_DEC, VALS(Teleservice_vals), 0,
"TeleserviceCode", HFILL }},
{ &hf_gsm_map_ext_BearerService,
{ "ext-BearerService", "gsm_map.ext_BearerService",
FT_UINT8, BASE_DEC, VALS(Bearerservice_vals), 0,
"Ext_BearerServiceCode", HFILL }},
{ &hf_gsm_map_ext_Teleservice,
{ "ext-Teleservice", "gsm_map.ext_Teleservice",
FT_UINT8, BASE_DEC, VALS(Teleservice_vals), 0,
"Ext_TeleserviceCode", HFILL }},
{ &hf_gsm_map_maximumentitledPriority,
{ "maximumentitledPriority", "gsm_map.maximumentitledPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_defaultPriority,
{ "defaultPriority", "gsm_map.defaultPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_ss_Code,
{ "ss-Code", "gsm_map.ss_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_Status,
{ "ss-Status", "gsm_map.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_SS_Status", HFILL }},
{ &hf_gsm_map_nbrSB,
{ "nbrSB", "gsm_map.nbrSB",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxMC_Bearers", HFILL }},
{ &hf_gsm_map_nbrUser,
{ "nbrUser", "gsm_map.nbrUser",
FT_UINT32, BASE_DEC, NULL, 0,
"MC_Bearers", HFILL }},
{ &hf_gsm_map_ss_ss_Code,
{ "ss-Code", "gsm_map.ss.ss_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_basicService,
{ "basicService", "gsm_map.ss.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
"BasicServiceCode", HFILL }},
{ &hf_gsm_map_ss_forwardedToNumber,
{ "forwardedToNumber", "gsm_map.ss.forwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_ss_forwardedToSubaddress,
{ "forwardedToSubaddress", "gsm_map.ss.forwardedToSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_map_ss_noReplyConditionTime,
{ "noReplyConditionTime", "gsm_map.ss.noReplyConditionTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_defaultPriority,
{ "defaultPriority", "gsm_map.ss.defaultPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_ss_nbrUser,
{ "nbrUser", "gsm_map.ss.nbrUser",
FT_UINT32, BASE_DEC, NULL, 0,
"MC_Bearers", HFILL }},
{ &hf_gsm_map_ss_longFTN_Supported,
{ "longFTN-Supported", "gsm_map.ss.longFTN_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_forwardingInfo,
{ "forwardingInfo", "gsm_map.ss.forwardingInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_callBarringInfo,
{ "callBarringInfo", "gsm_map.ss.callBarringInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ss_Data,
{ "ss-Data", "gsm_map.ss.ss_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_forwardingFeatureList,
{ "forwardingFeatureList", "gsm_map.ss.forwardingFeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ForwardingFeatureList_item,
{ "ForwardingFeature", "gsm_map.ss.ForwardingFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ss_Status,
{ "ss-Status", "gsm_map.ss.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_forwardedToNumber_01,
{ "forwardedToNumber", "gsm_map.ss.forwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ss_forwardingOptions,
{ "forwardingOptions", "gsm_map.ss.forwardingOptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_longForwardedToNumber,
{ "longForwardedToNumber", "gsm_map.ss.longForwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"FTN_AddressString", HFILL }},
{ &hf_gsm_map_ss_callBarringFeatureList,
{ "callBarringFeatureList", "gsm_map.ss.callBarringFeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_CallBarringFeatureList_item,
{ "CallBarringFeature", "gsm_map.ss.CallBarringFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ss_SubscriptionOption,
{ "ss-SubscriptionOption", "gsm_map.ss.ss_SubscriptionOption",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_SS_SubscriptionOption_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_basicServiceGroupList,
{ "basicServiceGroupList", "gsm_map.ss.basicServiceGroupList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_cliRestrictionOption,
{ "cliRestrictionOption", "gsm_map.ss.cliRestrictionOption",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_CliRestrictionOption_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_overrideCategory,
{ "overrideCategory", "gsm_map.ss.overrideCategory",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_OverrideCategory_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_maximumEntitledPriority,
{ "maximumEntitledPriority", "gsm_map.ss.maximumEntitledPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_ss_ccbs_FeatureList,
{ "ccbs-FeatureList", "gsm_map.ss.ccbs_FeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_nbrSB,
{ "nbrSB", "gsm_map.ss.nbrSB",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxMC_Bearers", HFILL }},
{ &hf_gsm_map_ss_nbrSN,
{ "nbrSN", "gsm_map.ss.nbrSN",
FT_UINT32, BASE_DEC, NULL, 0,
"MC_Bearers", HFILL }},
{ &hf_gsm_map_ss_CCBS_FeatureList_item,
{ "CCBS-Feature", "gsm_map.ss.CCBS_Feature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ccbs_Index,
{ "ccbs-Index", "gsm_map.ss.ccbs_Index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_b_subscriberNumber,
{ "b-subscriberNumber", "gsm_map.ss.b_subscriberNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ss_b_subscriberSubaddress,
{ "b-subscriberSubaddress", "gsm_map.ss.b_subscriberSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_map_ss_basicServiceGroup,
{ "basicServiceGroup", "gsm_map.ss.basicServiceGroup",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
"BasicServiceCode", HFILL }},
{ &hf_gsm_map_ss_genericServiceInfo,
{ "genericServiceInfo", "gsm_map.ss.genericServiceInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ussd_DataCodingScheme,
{ "ussd-DataCodingScheme", "gsm_map.ss.ussd_DataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ussd_String,
{ "ussd-String", "gsm_map.ss.ussd_String",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_alertingPattern,
{ "alertingPattern", "gsm_map.ss.alertingPattern",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_msisdn,
{ "msisdn", "gsm_map.ss.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ss_SS_List_item,
{ "SS-Code", "gsm_map.ss.SS_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_BasicServiceGroupList_item,
{ "BasicServiceCode", "gsm_map.ss.BasicServiceCode",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_imsi,
{ "imsi", "gsm_map.ss.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ss_Event,
{ "ss-Event", "gsm_map.ss.ss_Event",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
"SS_Code", HFILL }},
{ &hf_gsm_map_ss_ss_EventSpecification,
{ "ss-EventSpecification", "gsm_map.ss.ss_EventSpecification",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_extensionContainer,
{ "extensionContainer", "gsm_map.ss.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ccbs_RequestState,
{ "ccbs-RequestState", "gsm_map.ss.ccbs_RequestState",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_CCBS_RequestState_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_SS_EventSpecification_item,
{ "AddressString", "gsm_map.ss.AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ccbs_Data,
{ "ccbs-Data", "gsm_map.ss.ccbs_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_ccbs_Feature,
{ "ccbs-Feature", "gsm_map.ss.ccbs_Feature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_translatedB_Number,
{ "translatedB-Number", "gsm_map.ss.translatedB_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ss_serviceIndicator,
{ "serviceIndicator", "gsm_map.ss.serviceIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ss_callInfo,
{ "callInfo", "gsm_map.ss.callInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ss_networkSignalInfo,
{ "networkSignalInfo", "gsm_map.ss.networkSignalInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ss_ServiceIndicator_clir_invoked,
{ "clir-invoked", "gsm_map.ss.clir-invoked",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ss_ServiceIndicator_camel_invoked,
{ "camel-invoked", "gsm_map.ss.camel-invoked",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_er_roamingNotAllowedCause,
{ "roamingNotAllowedCause", "gsm_map.er.roamingNotAllowedCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_RoamingNotAllowedCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_extensionContainer,
{ "extensionContainer", "gsm_map.er.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_additionalRoamingNotAllowedCause,
{ "additionalRoamingNotAllowedCause", "gsm_map.er.additionalRoamingNotAllowedCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_AdditionalRoamingNotAllowedCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_callBarringCause,
{ "callBarringCause", "gsm_map.er.callBarringCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_CallBarringCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_extensibleCallBarredParam,
{ "extensibleCallBarredParam", "gsm_map.er.extensibleCallBarredParam_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_unauthorisedMessageOriginator,
{ "unauthorisedMessageOriginator", "gsm_map.er.unauthorisedMessageOriginator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_anonymousCallRejection,
{ "anonymousCallRejection", "gsm_map.er.anonymousCallRejection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_cug_RejectCause,
{ "cug-RejectCause", "gsm_map.er.cug_RejectCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_CUG_RejectCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_ss_Code,
{ "ss-Code", "gsm_map.er.ss_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_basicService,
{ "basicService", "gsm_map.er.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
"BasicServiceCode", HFILL }},
{ &hf_gsm_map_er_ss_Status,
{ "ss-Status", "gsm_map.er.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_sm_EnumeratedDeliveryFailureCause,
{ "sm-EnumeratedDeliveryFailureCause", "gsm_map.er.sm_EnumeratedDeliveryFailureCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_SM_EnumeratedDeliveryFailureCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_diagnosticInfo,
{ "diagnosticInfo", "gsm_map.er.diagnosticInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"SignalInfo", HFILL }},
{ &hf_gsm_map_er_absentSubscriberDiagnosticSM,
{ "absentSubscriberDiagnosticSM", "gsm_map.er.absentSubscriberDiagnosticSM",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_additionalAbsentSubscriberDiagnosticSM,
{ "additionalAbsentSubscriberDiagnosticSM", "gsm_map.er.additionalAbsentSubscriberDiagnosticSM",
FT_UINT32, BASE_DEC, NULL, 0,
"AbsentSubscriberDiagnosticSM", HFILL }},
{ &hf_gsm_map_er_imsi,
{ "imsi", "gsm_map.er.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_networkResource,
{ "networkResource", "gsm_map.er.networkResource",
FT_UINT32, BASE_DEC, VALS(gsm_map_NetworkResource_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_extensibleSystemFailureParam,
{ "extensibleSystemFailureParam", "gsm_map.er.extensibleSystemFailureParam_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_additionalNetworkResource,
{ "additionalNetworkResource", "gsm_map.er.additionalNetworkResource",
FT_UINT32, BASE_DEC, VALS(gsm_map_AdditionalNetworkResource_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_failureCauseParam,
{ "failureCauseParam", "gsm_map.er.failureCauseParam",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_FailureCauseParam_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_unexpectedSubscriber,
{ "unexpectedSubscriber", "gsm_map.er.unexpectedSubscriber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_shapeOfLocationEstimateNotSupported,
{ "shapeOfLocationEstimateNotSupported", "gsm_map.er.shapeOfLocationEstimateNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_neededLcsCapabilityNotSupportedInServingNode,
{ "neededLcsCapabilityNotSupportedInServingNode", "gsm_map.er.neededLcsCapabilityNotSupportedInServingNode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_unknownSubscriberDiagnostic,
{ "unknownSubscriberDiagnostic", "gsm_map.er.unknownSubscriberDiagnostic",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_UnknownSubscriberDiagnostic_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_absentSubscriberReason,
{ "absentSubscriberReason", "gsm_map.er.absentSubscriberReason",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_AbsentSubscriberReason_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_ccbs_Possible,
{ "ccbs-Possible", "gsm_map.er.ccbs_Possible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_ccbs_Busy,
{ "ccbs-Busy", "gsm_map.er.ccbs_Busy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_gprsConnectionSuspended,
{ "gprsConnectionSuspended", "gsm_map.er.gprsConnectionSuspended_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_er_unauthorizedLCSClient_Diagnostic,
{ "unauthorizedLCSClient-Diagnostic", "gsm_map.er.unauthorizedLCSClient_Diagnostic",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_UnauthorizedLCSClient_Diagnostic_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_er_positionMethodFailure_Diagnostic,
{ "positionMethodFailure-Diagnostic", "gsm_map.er.positionMethodFailure_Diagnostic",
FT_UINT32, BASE_DEC, VALS(gsm_map_er_PositionMethodFailure_Diagnostic_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_msisdn,
{ "msisdn", "gsm_map.sm.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_sm_sm_RP_PRI,
{ "sm-RP-PRI", "gsm_map.sm.sm_RP_PRI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_sm_serviceCentreAddress,
{ "serviceCentreAddress", "gsm_map.sm.serviceCentreAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_sm_extensionContainer,
{ "extensionContainer", "gsm_map.sm.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_gprsSupportIndicator,
{ "gprsSupportIndicator", "gsm_map.sm.gprsSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sm_RP_MTI,
{ "sm-RP-MTI", "gsm_map.sm.sm_RP_MTI",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sm_RP_SMEA,
{ "sm-RP-SMEA", "gsm_map.sm.sm_RP_SMEA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sm_deliveryNotIntended,
{ "sm-deliveryNotIntended", "gsm_map.sm.sm_deliveryNotIntended",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_DeliveryNotIntended_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_ip_sm_gwGuidanceIndicator,
{ "ip-sm-gwGuidanceIndicator", "gsm_map.sm.ip_sm_gwGuidanceIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_imsi,
{ "imsi", "gsm_map.sm.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_t4_Trigger_Indicator,
{ "t4-Trigger-Indicator", "gsm_map.sm.t4_Trigger_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_singleAttemptDelivery,
{ "singleAttemptDelivery", "gsm_map.sm.singleAttemptDelivery_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_correlationID,
{ "correlationID", "gsm_map.sm.correlationID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_locationInfoWithLMSI,
{ "locationInfoWithLMSI", "gsm_map.sm.locationInfoWithLMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_ip_sm_gwGuidance,
{ "ip-sm-gwGuidance", "gsm_map.sm.ip_sm_gwGuidance_element",
FT_NONE, BASE_NONE, NULL, 0,
"IP_SM_GW_Guidance", HFILL }},
{ &hf_gsm_map_sm_minimumDeliveryTimeValue,
{ "minimumDeliveryTimeValue", "gsm_map.sm.minimumDeliveryTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"SM_DeliveryTimerValue", HFILL }},
{ &hf_gsm_map_sm_recommendedDeliveryTimeValue,
{ "recommendedDeliveryTimeValue", "gsm_map.sm.recommendedDeliveryTimeValue",
FT_UINT32, BASE_DEC, NULL, 0,
"SM_DeliveryTimerValue", HFILL }},
{ &hf_gsm_map_sm_networkNode_Number,
{ "networkNode-Number", "gsm_map.sm.networkNode_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_sm_lmsi,
{ "lmsi", "gsm_map.sm.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_gprsNodeIndicator,
{ "gprsNodeIndicator", "gsm_map.sm.gprsNodeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_additional_Number,
{ "additional-Number", "gsm_map.sm.additional_Number",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_Additional_Number_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_networkNodeDiameterAddress,
{ "networkNodeDiameterAddress", "gsm_map.sm.networkNodeDiameterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_additionalNetworkNodeDiameterAddress,
{ "additionalNetworkNodeDiameterAddress", "gsm_map.sm.additionalNetworkNodeDiameterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"NetworkNodeDiameterAddress", HFILL }},
{ &hf_gsm_map_sm_thirdNumber,
{ "thirdNumber", "gsm_map.sm.thirdNumber",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_Additional_Number_vals), 0,
"Additional_Number", HFILL }},
{ &hf_gsm_map_sm_thirdNetworkNodeDiameterAddress,
{ "thirdNetworkNodeDiameterAddress", "gsm_map.sm.thirdNetworkNodeDiameterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"NetworkNodeDiameterAddress", HFILL }},
{ &hf_gsm_map_sm_imsNodeIndicator,
{ "imsNodeIndicator", "gsm_map.sm.imsNodeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_msc_Number,
{ "msc-Number", "gsm_map.sm.msc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_sm_sgsn_Number,
{ "sgsn-Number", "gsm_map.sm.sgsn_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_sm_sm_RP_DA,
{ "sm-RP-DA", "gsm_map.sm.sm_RP_DA",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_RP_DA_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sm_RP_OA,
{ "sm-RP-OA", "gsm_map.sm.sm_RP_OA",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_RP_OA_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sm_RP_UI,
{ "sm-RP-UI", "gsm_map.sm.sm_RP_UI",
FT_BYTES, BASE_NONE, NULL, 0,
"SignalInfo", HFILL }},
{ &hf_gsm_map_sm_sm_DeliveryOutcome,
{ "sm-DeliveryOutcome", "gsm_map.sm.sm_DeliveryOutcome",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_DeliveryOutcome_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_moreMessagesToSend,
{ "moreMessagesToSend", "gsm_map.sm.moreMessagesToSend_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_smDeliveryTimer,
{ "smDeliveryTimer", "gsm_map.sm.smDeliveryTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"SM_DeliveryTimerValue", HFILL }},
{ &hf_gsm_map_sm_smDeliveryStartTime,
{ "smDeliveryStartTime", "gsm_map.sm.smDeliveryStartTime",
FT_BYTES, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_gsm_map_sm_smsOverIP_OnlyIndicator,
{ "smsOverIP-OnlyIndicator", "gsm_map.sm.smsOverIP_OnlyIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_hlr_id,
{ "hlr-id", "gsm_map.sm.hlr_id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_sip_uri_A,
{ "sip-uri-A", "gsm_map.sm.sip_uri_A",
FT_BYTES, BASE_NONE, NULL, 0,
"SIP_URI", HFILL }},
{ &hf_gsm_map_sm_sip_uri_B,
{ "sip-uri-B", "gsm_map.sm.sip_uri_B",
FT_BYTES, BASE_NONE, NULL, 0,
"SIP_URI", HFILL }},
{ &hf_gsm_map_sm_imsi_01,
{ "imsi", "gsm_map.sm.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_lmsi_01,
{ "lmsi", "gsm_map.sm.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_serviceCentreAddressDA,
{ "serviceCentreAddressDA", "gsm_map.sm.serviceCentreAddressDA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_noSM_RP_DA,
{ "noSM-RP-DA", "gsm_map.sm.noSM_RP_DA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_msisdn_01,
{ "msisdn", "gsm_map.sm.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_serviceCentreAddressOA,
{ "serviceCentreAddressOA", "gsm_map.sm.serviceCentreAddressOA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_noSM_RP_OA,
{ "noSM-RP-OA", "gsm_map.sm.noSM_RP_OA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_absentSubscriberDiagnosticSM,
{ "absentSubscriberDiagnosticSM", "gsm_map.sm.absentSubscriberDiagnosticSM",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_deliveryOutcomeIndicator,
{ "deliveryOutcomeIndicator", "gsm_map.sm.deliveryOutcomeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_additionalSM_DeliveryOutcome,
{ "additionalSM-DeliveryOutcome", "gsm_map.sm.additionalSM_DeliveryOutcome",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_DeliveryOutcome_vals), 0,
"SM_DeliveryOutcome", HFILL }},
{ &hf_gsm_map_sm_additionalAbsentSubscriberDiagnosticSM,
{ "additionalAbsentSubscriberDiagnosticSM", "gsm_map.sm.additionalAbsentSubscriberDiagnosticSM",
FT_UINT32, BASE_DEC, NULL, 0,
"AbsentSubscriberDiagnosticSM", HFILL }},
{ &hf_gsm_map_sm_ip_sm_gw_Indicator,
{ "ip-sm-gw-Indicator", "gsm_map.sm.ip_sm_gw_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_ip_sm_gw_sm_deliveryOutcome,
{ "ip-sm-gw-sm-deliveryOutcome", "gsm_map.sm.ip_sm_gw_sm_deliveryOutcome",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_SM_DeliveryOutcome_vals), 0,
"SM_DeliveryOutcome", HFILL }},
{ &hf_gsm_map_sm_ip_sm_gw_absentSubscriberDiagnosticSM,
{ "ip-sm-gw-absentSubscriberDiagnosticSM", "gsm_map.sm.ip_sm_gw_absentSubscriberDiagnosticSM",
FT_UINT32, BASE_DEC, NULL, 0,
"AbsentSubscriberDiagnosticSM", HFILL }},
{ &hf_gsm_map_sm_storedMSISDN,
{ "storedMSISDN", "gsm_map.sm.storedMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_sm_mw_Status,
{ "mw-Status", "gsm_map.sm.mw_Status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_alertReason,
{ "alertReason", "gsm_map.sm.alertReason",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_AlertReason_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_alertReasonIndicator,
{ "alertReasonIndicator", "gsm_map.sm.alertReasonIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_additionalAlertReasonIndicator,
{ "additionalAlertReasonIndicator", "gsm_map.sm.additionalAlertReasonIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_asciCallReference,
{ "asciCallReference", "gsm_map.sm.asciCallReference",
FT_BYTES, BASE_NONE, NULL, 0,
"ASCI_CallReference", HFILL }},
{ &hf_gsm_map_sm_dispatcherList,
{ "dispatcherList", "gsm_map.sm.dispatcherList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_ongoingCall,
{ "ongoingCall", "gsm_map.sm.ongoingCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_additionalDispatcherList,
{ "additionalDispatcherList", "gsm_map.sm.additionalDispatcherList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_DispatcherList_item,
{ "ISDN-AddressString", "gsm_map.sm.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_AdditionalDispatcherList_item,
{ "ISDN-AddressString", "gsm_map.sm.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_sm_MW_Status_sc_AddressNotIncluded,
{ "sc-AddressNotIncluded", "gsm_map.sm.sc-AddressNotIncluded",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_sm_MW_Status_mnrf_Set,
{ "mnrf-Set", "gsm_map.sm.mnrf-Set",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_sm_MW_Status_mcef_Set,
{ "mcef-Set", "gsm_map.sm.mcef-Set",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_sm_MW_Status_mnrg_Set,
{ "mnrg-Set", "gsm_map.sm.mnrg-Set",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_imsi,
{ "imsi", "gsm_map.om.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceReference,
{ "traceReference", "gsm_map.om.traceReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceType,
{ "traceType", "gsm_map.om.traceType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_omc_Id,
{ "omc-Id", "gsm_map.om.omc_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_om_extensionContainer,
{ "extensionContainer", "gsm_map.om.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceReference2,
{ "traceReference2", "gsm_map.om.traceReference2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceDepthList,
{ "traceDepthList", "gsm_map.om.traceDepthList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceNE_TypeList,
{ "traceNE-TypeList", "gsm_map.om.traceNE_TypeList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceInterfaceList,
{ "traceInterfaceList", "gsm_map.om.traceInterfaceList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceEventList,
{ "traceEventList", "gsm_map.om.traceEventList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceCollectionEntity,
{ "traceCollectionEntity", "gsm_map.om.traceCollectionEntity",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_om_mdt_Configuration,
{ "mdt-Configuration", "gsm_map.om.mdt_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_jobType,
{ "jobType", "gsm_map.om.jobType",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_JobType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_om_areaScope,
{ "areaScope", "gsm_map.om.areaScope_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_listOfMeasurements,
{ "listOfMeasurements", "gsm_map.om.listOfMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_reportingTrigger,
{ "reportingTrigger", "gsm_map.om.reportingTrigger",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_reportInterval,
{ "reportInterval", "gsm_map.om.reportInterval",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_ReportInterval_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_om_reportAmount,
{ "reportAmount", "gsm_map.om.reportAmount",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_ReportAmount_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_om_eventThresholdRSRP,
{ "eventThresholdRSRP", "gsm_map.om.eventThresholdRSRP",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_eventThresholdRSRQ,
{ "eventThresholdRSRQ", "gsm_map.om.eventThresholdRSRQ",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_loggingInterval,
{ "loggingInterval", "gsm_map.om.loggingInterval",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_LoggingInterval_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_om_loggingDuration,
{ "loggingDuration", "gsm_map.om.loggingDuration",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_LoggingDuration_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_om_measurementPeriodUMTS,
{ "measurementPeriodUMTS", "gsm_map.om.measurementPeriodUMTS",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_PeriodUMTS_vals), 0,
"PeriodUMTS", HFILL }},
{ &hf_gsm_map_om_measurementPeriodLTE,
{ "measurementPeriodLTE", "gsm_map.om.measurementPeriodLTE",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_PeriodLTE_vals), 0,
"PeriodLTE", HFILL }},
{ &hf_gsm_map_om_collectionPeriodRRM_UMTS,
{ "collectionPeriodRRM-UMTS", "gsm_map.om.collectionPeriodRRM_UMTS",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_PeriodUMTS_vals), 0,
"PeriodUMTS", HFILL }},
{ &hf_gsm_map_om_collectionPeriodRRM_LTE,
{ "collectionPeriodRRM-LTE", "gsm_map.om.collectionPeriodRRM_LTE",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_PeriodLTE_vals), 0,
"PeriodLTE", HFILL }},
{ &hf_gsm_map_om_positioningMethod,
{ "positioningMethod", "gsm_map.om.positioningMethod",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_measurementQuantity,
{ "measurementQuantity", "gsm_map.om.measurementQuantity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_eventThreshold1F,
{ "eventThreshold1F", "gsm_map.om.eventThreshold1F",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_eventThreshold1I,
{ "eventThreshold1I", "gsm_map.om.eventThreshold1I",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_cgi_List,
{ "cgi-List", "gsm_map.om.cgi_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_e_utran_cgi_List,
{ "e-utran-cgi-List", "gsm_map.om.e_utran_cgi_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_routingAreaId_List,
{ "routingAreaId-List", "gsm_map.om.routingAreaId_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_locationAreaId_List,
{ "locationAreaId-List", "gsm_map.om.locationAreaId_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_trackingAreaId_List,
{ "trackingAreaId-List", "gsm_map.om.trackingAreaId_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_CGI_List_item,
{ "GlobalCellId", "gsm_map.om.GlobalCellId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_E_UTRAN_CGI_List_item,
{ "E-UTRAN-CGI", "gsm_map.om.E_UTRAN_CGI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_RoutingAreaId_List_item,
{ "RAIdentity", "gsm_map.om.RAIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_LocationAreaId_List_item,
{ "LAIFixedLength", "gsm_map.om.LAIFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_TrackingAreaId_List_item,
{ "TA-Id", "gsm_map.om.TA_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_msc_s_TraceDepth,
{ "msc-s-TraceDepth", "gsm_map.om.msc_s_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_mgw_TraceDepth,
{ "mgw-TraceDepth", "gsm_map.om.mgw_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_sgsn_TraceDepth,
{ "sgsn-TraceDepth", "gsm_map.om.sgsn_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_ggsn_TraceDepth,
{ "ggsn-TraceDepth", "gsm_map.om.ggsn_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_rnc_TraceDepth,
{ "rnc-TraceDepth", "gsm_map.om.rnc_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_bmsc_TraceDepth,
{ "bmsc-TraceDepth", "gsm_map.om.bmsc_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_mme_TraceDepth,
{ "mme-TraceDepth", "gsm_map.om.mme_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_sgw_TraceDepth,
{ "sgw-TraceDepth", "gsm_map.om.sgw_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_pgw_TraceDepth,
{ "pgw-TraceDepth", "gsm_map.om.pgw_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_eNB_TraceDepth,
{ "eNB-TraceDepth", "gsm_map.om.eNB_TraceDepth",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepth_vals), 0,
"TraceDepth", HFILL }},
{ &hf_gsm_map_om_msc_s_TraceDepthExtension,
{ "msc-s-TraceDepthExtension", "gsm_map.om.msc_s_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_mgw_TraceDepthExtension,
{ "mgw-TraceDepthExtension", "gsm_map.om.mgw_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_sgsn_TraceDepthExtension,
{ "sgsn-TraceDepthExtension", "gsm_map.om.sgsn_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_ggsn_TraceDepthExtension,
{ "ggsn-TraceDepthExtension", "gsm_map.om.ggsn_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_rnc_TraceDepthExtension,
{ "rnc-TraceDepthExtension", "gsm_map.om.rnc_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_bmsc_TraceDepthExtension,
{ "bmsc-TraceDepthExtension", "gsm_map.om.bmsc_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_mme_TraceDepthExtension,
{ "mme-TraceDepthExtension", "gsm_map.om.mme_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_sgw_TraceDepthExtension,
{ "sgw-TraceDepthExtension", "gsm_map.om.sgw_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_pgw_TraceDepthExtension,
{ "pgw-TraceDepthExtension", "gsm_map.om.pgw_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_eNB_TraceDepthExtension,
{ "eNB-TraceDepthExtension", "gsm_map.om.eNB_TraceDepthExtension",
FT_UINT32, BASE_DEC, VALS(gsm_map_om_TraceDepthExtension_vals), 0,
"TraceDepthExtension", HFILL }},
{ &hf_gsm_map_om_msc_s_List,
{ "msc-s-List", "gsm_map.om.msc_s_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MSC_S_InterfaceList", HFILL }},
{ &hf_gsm_map_om_mgw_List,
{ "mgw-List", "gsm_map.om.mgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MGW_InterfaceList", HFILL }},
{ &hf_gsm_map_om_sgsn_List,
{ "sgsn-List", "gsm_map.om.sgsn_List",
FT_BYTES, BASE_NONE, NULL, 0,
"SGSN_InterfaceList", HFILL }},
{ &hf_gsm_map_om_ggsn_List,
{ "ggsn-List", "gsm_map.om.ggsn_List",
FT_BYTES, BASE_NONE, NULL, 0,
"GGSN_InterfaceList", HFILL }},
{ &hf_gsm_map_om_rnc_List,
{ "rnc-List", "gsm_map.om.rnc_List",
FT_BYTES, BASE_NONE, NULL, 0,
"RNC_InterfaceList", HFILL }},
{ &hf_gsm_map_om_bmsc_List,
{ "bmsc-List", "gsm_map.om.bmsc_List",
FT_BYTES, BASE_NONE, NULL, 0,
"BMSC_InterfaceList", HFILL }},
{ &hf_gsm_map_om_mme_List,
{ "mme-List", "gsm_map.om.mme_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MME_InterfaceList", HFILL }},
{ &hf_gsm_map_om_sgw_List,
{ "sgw-List", "gsm_map.om.sgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"SGW_InterfaceList", HFILL }},
{ &hf_gsm_map_om_pgw_List,
{ "pgw-List", "gsm_map.om.pgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"PGW_InterfaceList", HFILL }},
{ &hf_gsm_map_om_eNB_List,
{ "eNB-List", "gsm_map.om.eNB_List",
FT_BYTES, BASE_NONE, NULL, 0,
"ENB_InterfaceList", HFILL }},
{ &hf_gsm_map_om_msc_s_List_01,
{ "msc-s-List", "gsm_map.om.msc_s_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MSC_S_EventList", HFILL }},
{ &hf_gsm_map_om_mgw_List_01,
{ "mgw-List", "gsm_map.om.mgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MGW_EventList", HFILL }},
{ &hf_gsm_map_om_sgsn_List_01,
{ "sgsn-List", "gsm_map.om.sgsn_List",
FT_BYTES, BASE_NONE, NULL, 0,
"SGSN_EventList", HFILL }},
{ &hf_gsm_map_om_ggsn_List_01,
{ "ggsn-List", "gsm_map.om.ggsn_List",
FT_BYTES, BASE_NONE, NULL, 0,
"GGSN_EventList", HFILL }},
{ &hf_gsm_map_om_bmsc_List_01,
{ "bmsc-List", "gsm_map.om.bmsc_List",
FT_BYTES, BASE_NONE, NULL, 0,
"BMSC_EventList", HFILL }},
{ &hf_gsm_map_om_mme_List_01,
{ "mme-List", "gsm_map.om.mme_List",
FT_BYTES, BASE_NONE, NULL, 0,
"MME_EventList", HFILL }},
{ &hf_gsm_map_om_sgw_List_01,
{ "sgw-List", "gsm_map.om.sgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"SGW_EventList", HFILL }},
{ &hf_gsm_map_om_pgw_List_01,
{ "pgw-List", "gsm_map.om.pgw_List",
FT_BYTES, BASE_NONE, NULL, 0,
"PGW_EventList", HFILL }},
{ &hf_gsm_map_om_traceRecordingSessionReference,
{ "traceRecordingSessionReference", "gsm_map.om.traceRecordingSessionReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_rnc_InterfaceList,
{ "rnc-InterfaceList", "gsm_map.om.rnc_InterfaceList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_msc_s_InterfaceList,
{ "msc-s-InterfaceList", "gsm_map.om.msc_s_InterfaceList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_msc_s_EventList,
{ "msc-s-EventList", "gsm_map.om.msc_s_EventList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_mgw_InterfaceList,
{ "mgw-InterfaceList", "gsm_map.om.mgw_InterfaceList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_mgw_EventList,
{ "mgw-EventList", "gsm_map.om.mgw_EventList",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_traceSupportIndicator,
{ "traceSupportIndicator", "gsm_map.om.traceSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_msc_s,
{ "msc-s", "gsm_map.om.msc-s",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_mgw,
{ "mgw", "gsm_map.om.mgw",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_sgsn,
{ "sgsn", "gsm_map.om.sgsn",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_ggsn,
{ "ggsn", "gsm_map.om.ggsn",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_rnc,
{ "rnc", "gsm_map.om.rnc",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_bm_sc,
{ "bm-sc", "gsm_map.om.bm-sc",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_mme,
{ "mme", "gsm_map.om.mme",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_sgw,
{ "sgw", "gsm_map.om.sgw",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_pgw,
{ "pgw", "gsm_map.om.pgw",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_TraceNE_TypeList_eNB,
{ "eNB", "gsm_map.om.eNB",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_a,
{ "a", "gsm_map.om.a",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_iu,
{ "iu", "gsm_map.om.iu",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_mc,
{ "mc", "gsm_map.om.mc",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_g,
{ "map-g", "gsm_map.om.map-g",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_b,
{ "map-b", "gsm_map.om.map-b",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_e,
{ "map-e", "gsm_map.om.map-e",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_f,
{ "map-f", "gsm_map.om.map-f",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_cap,
{ "cap", "gsm_map.om.cap",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_d,
{ "map-d", "gsm_map.om.map-d",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_InterfaceList_map_c,
{ "map-c", "gsm_map.om.map-c",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MGW_InterfaceList_mc,
{ "mc", "gsm_map.om.mc",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MGW_InterfaceList_nb_up,
{ "nb-up", "gsm_map.om.nb-up",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MGW_InterfaceList_iu_up,
{ "iu-up", "gsm_map.om.iu-up",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_gb,
{ "gb", "gsm_map.om.gb",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_iu,
{ "iu", "gsm_map.om.iu",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_gn,
{ "gn", "gsm_map.om.gn",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_map_gr,
{ "map-gr", "gsm_map.om.map-gr",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_map_gd,
{ "map-gd", "gsm_map.om.map-gd",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_map_gf,
{ "map-gf", "gsm_map.om.map-gf",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_gs,
{ "gs", "gsm_map.om.gs",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_ge,
{ "ge", "gsm_map.om.ge",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_s3,
{ "s3", "gsm_map.om.s3",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_s4,
{ "s4", "gsm_map.om.s4",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_InterfaceList_s6d,
{ "s6d", "gsm_map.om.s6d",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_GGSN_InterfaceList_gn,
{ "gn", "gsm_map.om.gn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_GGSN_InterfaceList_gi,
{ "gi", "gsm_map.om.gi",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_GGSN_InterfaceList_gmb,
{ "gmb", "gsm_map.om.gmb",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_RNC_InterfaceList_iu,
{ "iu", "gsm_map.om.iu",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_RNC_InterfaceList_iur,
{ "iur", "gsm_map.om.iur",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_RNC_InterfaceList_iub,
{ "iub", "gsm_map.om.iub",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_RNC_InterfaceList_uu,
{ "uu", "gsm_map.om.uu",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_BMSC_InterfaceList_gmb,
{ "gmb", "gsm_map.om.gmb",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_InterfaceList_s1_mme,
{ "s1-mme", "gsm_map.om.s1-mme",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_InterfaceList_s3,
{ "s3", "gsm_map.om.s3",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_InterfaceList_s6a,
{ "s6a", "gsm_map.om.s6a",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_InterfaceList_s10,
{ "s10", "gsm_map.om.s10",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_InterfaceList_s11,
{ "s11", "gsm_map.om.s11",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_InterfaceList_s4,
{ "s4", "gsm_map.om.s4",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_InterfaceList_s5,
{ "s5", "gsm_map.om.s5",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_InterfaceList_s8b,
{ "s8b", "gsm_map.om.s8b",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_InterfaceList_s11,
{ "s11", "gsm_map.om.s11",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_InterfaceList_gxc,
{ "gxc", "gsm_map.om.gxc",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s2a,
{ "s2a", "gsm_map.om.s2a",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s2b,
{ "s2b", "gsm_map.om.s2b",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s2c,
{ "s2c", "gsm_map.om.s2c",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s5,
{ "s5", "gsm_map.om.s5",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s6b,
{ "s6b", "gsm_map.om.s6b",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_gx,
{ "gx", "gsm_map.om.gx",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_s8b,
{ "s8b", "gsm_map.om.s8b",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_InterfaceList_sgi,
{ "sgi", "gsm_map.om.sgi",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_om_ENB_InterfaceList_s1_mme,
{ "s1-mme", "gsm_map.om.s1-mme",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_ENB_InterfaceList_x2,
{ "x2", "gsm_map.om.x2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_ENB_InterfaceList_uu,
{ "uu", "gsm_map.om.uu",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_EventList_mo_mtCall,
{ "mo-mtCall", "gsm_map.om.mo-mtCall",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_EventList_mo_mt_sms,
{ "mo-mt-sms", "gsm_map.om.mo-mt-sms",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_EventList_lu_imsiAttach_imsiDetach,
{ "lu-imsiAttach-imsiDetach", "gsm_map.om.lu-imsiAttach-imsiDetach",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_EventList_handovers,
{ "handovers", "gsm_map.om.handovers",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_MSC_S_EventList_ss,
{ "ss", "gsm_map.om.ss",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_MGW_EventList_context,
{ "context", "gsm_map.om.context",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_EventList_pdpContext,
{ "pdpContext", "gsm_map.om.pdpContext",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_EventList_mo_mt_sms,
{ "mo-mt-sms", "gsm_map.om.mo-mt-sms",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_EventList_rau_gprsAttach_gprsDetach,
{ "rau-gprsAttach-gprsDetach", "gsm_map.om.rau-gprsAttach-gprsDetach",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_SGSN_EventList_mbmsContext,
{ "mbmsContext", "gsm_map.om.mbmsContext",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_GGSN_EventList_pdpContext,
{ "pdpContext", "gsm_map.om.pdpContext",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_GGSN_EventList_mbmsContext,
{ "mbmsContext", "gsm_map.om.mbmsContext",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_BMSC_EventList_mbmsMulticastServiceActivation,
{ "mbmsMulticastServiceActivation", "gsm_map.om.mbmsMulticastServiceActivation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_ue_initiatedPDNconectivityRequest,
{ "ue-initiatedPDNconectivityRequest", "gsm_map.om.ue-initiatedPDNconectivityRequest",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_serviceRequestts,
{ "serviceRequestts", "gsm_map.om.serviceRequestts",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_initialAttachTrackingAreaUpdateDetach,
{ "initialAttachTrackingAreaUpdateDetach", "gsm_map.om.initialAttachTrackingAreaUpdateDetach",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_ue_initiatedPDNdisconnection,
{ "ue-initiatedPDNdisconnection", "gsm_map.om.ue-initiatedPDNdisconnection",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_bearerActivationModificationDeletion,
{ "bearerActivationModificationDeletion", "gsm_map.om.bearerActivationModificationDeletion",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_om_MME_EventList_handover,
{ "handover", "gsm_map.om.handover",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_EventList_pdn_connectionCreation,
{ "pdn-connectionCreation", "gsm_map.om.pdn-connectionCreation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_EventList_pdn_connectionTermination,
{ "pdn-connectionTermination", "gsm_map.om.pdn-connectionTermination",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_SGW_EventList_bearerActivationModificationDeletion,
{ "bearerActivationModificationDeletion", "gsm_map.om.bearerActivationModificationDeletion",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_EventList_pdn_connectionCreation,
{ "pdn-connectionCreation", "gsm_map.om.pdn-connectionCreation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_EventList_pdn_connectionTermination,
{ "pdn-connectionTermination", "gsm_map.om.pdn-connectionTermination",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_om_PGW_EventList_bearerActivationModificationDeletion,
{ "bearerActivationModificationDeletion", "gsm_map.om.bearerActivationModificationDeletion",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_imsi,
{ "imsi", "gsm_map.ms.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_msc_Number,
{ "msc-Number", "gsm_map.ms.msc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_vlr_Number,
{ "vlr-Number", "gsm_map.ms.vlr_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_lmsi,
{ "lmsi", "gsm_map.ms.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_extensionContainer,
{ "extensionContainer", "gsm_map.ms.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vlr_Capability,
{ "vlr-Capability", "gsm_map.ms.vlr_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_informPreviousNetworkEntity,
{ "informPreviousNetworkEntity", "gsm_map.ms.informPreviousNetworkEntity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cs_LCS_NotSupportedByUE,
{ "cs-LCS-NotSupportedByUE", "gsm_map.ms.cs_LCS_NotSupportedByUE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_v_gmlc_Address,
{ "v-gmlc-Address", "gsm_map.ms.v_gmlc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_ms_add_info,
{ "add-info", "gsm_map.ms.add_info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pagingArea,
{ "pagingArea", "gsm_map.ms.pagingArea",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_skipSubscriberDataUpdate,
{ "skipSubscriberDataUpdate", "gsm_map.ms.skipSubscriberDataUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_restorationIndicator,
{ "restorationIndicator", "gsm_map.ms.restorationIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_eplmn_List,
{ "eplmn-List", "gsm_map.ms.eplmn_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mme_DiameterAddress,
{ "mme-DiameterAddress", "gsm_map.ms.mme_DiameterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"NetworkNodeDiameterAddress", HFILL }},
{ &hf_gsm_map_ms_supportedCamelPhases,
{ "supportedCamelPhases", "gsm_map.ms.supportedCamelPhases",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_solsaSupportIndicator,
{ "solsaSupportIndicator", "gsm_map.ms.solsaSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_istSupportIndicator,
{ "istSupportIndicator", "gsm_map.ms.istSupportIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_IST_SupportIndicator_vals), 0,
"IST_SupportIndicator", HFILL }},
{ &hf_gsm_map_ms_superChargerSupportedInServingNetworkEntity,
{ "superChargerSupportedInServingNetworkEntity", "gsm_map.ms.superChargerSupportedInServingNetworkEntity",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SuperChargerInfo_vals), 0,
"SuperChargerInfo", HFILL }},
{ &hf_gsm_map_ms_longFTN_Supported,
{ "longFTN-Supported", "gsm_map.ms.longFTN_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedLCS_CapabilitySets,
{ "supportedLCS-CapabilitySets", "gsm_map.ms.supportedLCS_CapabilitySets",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_offeredCamel4CSIs,
{ "offeredCamel4CSIs", "gsm_map.ms.offeredCamel4CSIs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedRAT_TypesIndicator,
{ "supportedRAT-TypesIndicator", "gsm_map.ms.supportedRAT_TypesIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedRAT_Types", HFILL }},
{ &hf_gsm_map_ms_longGroupID_Supported,
{ "longGroupID-Supported", "gsm_map.ms.longGroupID_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mtRoamingForwardingSupported,
{ "mtRoamingForwardingSupported", "gsm_map.ms.mtRoamingForwardingSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_msisdn_lessOperation_Supported,
{ "msisdn-lessOperation-Supported", "gsm_map.ms.msisdn_lessOperation_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sendSubscriberData,
{ "sendSubscriberData", "gsm_map.ms.sendSubscriberData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscriberDataStored,
{ "subscriberDataStored", "gsm_map.ms.subscriberDataStored",
FT_BYTES, BASE_NONE, NULL, 0,
"AgeIndicator", HFILL }},
{ &hf_gsm_map_ms_hlr_Number,
{ "hlr-Number", "gsm_map.ms.hlr_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_add_Capability,
{ "add-Capability", "gsm_map.ms.add_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pagingArea_Capability,
{ "pagingArea-Capability", "gsm_map.ms.pagingArea_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_imeisv,
{ "imeisv", "gsm_map.ms.imeisv",
FT_BYTES, BASE_NONE, NULL, 0,
"IMEI", HFILL }},
{ &hf_gsm_map_ms_PagingArea_item,
{ "LocationArea", "gsm_map.ms.LocationArea",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_LocationArea_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_laiFixedLength,
{ "laiFixedLength", "gsm_map.ms.laiFixedLength",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lac,
{ "lac", "gsm_map.ms.lac",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_identity,
{ "identity", "gsm_map.ms.identity",
FT_UINT32, BASE_DEC, VALS(gsm_map_Identity_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cancellationType,
{ "cancellationType", "gsm_map.ms.cancellationType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_CancellationType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_typeOfUpdate,
{ "typeOfUpdate", "gsm_map.ms.typeOfUpdate",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_TypeOfUpdate_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mtrf_SupportedAndAuthorized,
{ "mtrf-SupportedAndAuthorized", "gsm_map.ms.mtrf_SupportedAndAuthorized_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mtrf_SupportedAndNotAuthorized,
{ "mtrf-SupportedAndNotAuthorized", "gsm_map.ms.mtrf_SupportedAndNotAuthorized_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_newMSC_Number,
{ "newMSC-Number", "gsm_map.ms.newMSC_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_newVLR_Number,
{ "newVLR-Number", "gsm_map.ms.newVLR_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_new_lmsi,
{ "new-lmsi", "gsm_map.ms.new_lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
"LMSI", HFILL }},
{ &hf_gsm_map_ms_reattach_Required,
{ "reattach-Required", "gsm_map.ms.reattach_Required_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sgsn_Number,
{ "sgsn-Number", "gsm_map.ms.sgsn_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_locationInformation,
{ "locationInformation", "gsm_map.ms.locationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_locationInformationGPRS,
{ "locationInformationGPRS", "gsm_map.ms.locationInformationGPRS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_locationInformationEPS,
{ "locationInformationEPS", "gsm_map.ms.locationInformationEPS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_freezeTMSI,
{ "freezeTMSI", "gsm_map.ms.freezeTMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_freezeP_TMSI,
{ "freezeP-TMSI", "gsm_map.ms.freezeP_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_freezeM_TMSI,
{ "freezeM-TMSI", "gsm_map.ms.freezeM_TMSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_tmsi,
{ "tmsi", "gsm_map.ms.tmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_numberOfRequestedVectors,
{ "numberOfRequestedVectors", "gsm_map.ms.numberOfRequestedVectors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_segmentationProhibited,
{ "segmentationProhibited", "gsm_map.ms.segmentationProhibited_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_previous_LAI,
{ "previous-LAI", "gsm_map.ms.previous_LAI",
FT_BYTES, BASE_NONE, NULL, 0,
"LAIFixedLength", HFILL }},
{ &hf_gsm_map_ms_hopCounter,
{ "hopCounter", "gsm_map.ms.hopCounter",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_authenticationSetList,
{ "authenticationSetList", "gsm_map.ms.authenticationSetList",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_AuthenticationSetList_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_currentSecurityContext,
{ "currentSecurityContext", "gsm_map.ms.currentSecurityContext",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_CurrentSecurityContext_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lastUsedLtePLMN_Id,
{ "lastUsedLtePLMN-Id", "gsm_map.ms.lastUsedLtePLMN_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gsm_map_ms_mtCallPendingFlag,
{ "mtCallPendingFlag", "gsm_map.ms.mtCallPendingFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_tripletList,
{ "tripletList", "gsm_map.ms.tripletList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_quintupletList,
{ "quintupletList", "gsm_map.ms.quintupletList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_TripletList_item,
{ "AuthenticationTriplet", "gsm_map.ms.AuthenticationTriplet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_QuintupletList_item,
{ "AuthenticationQuintuplet", "gsm_map.ms.AuthenticationQuintuplet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_rand,
{ "rand", "gsm_map.ms.rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sres,
{ "sres", "gsm_map.ms.sres",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_kc,
{ "kc", "gsm_map.ms.kc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_xres,
{ "xres", "gsm_map.ms.xres",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ck,
{ "ck", "gsm_map.ms.ck",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ik,
{ "ik", "gsm_map.ms.ik",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_autn,
{ "autn", "gsm_map.ms.autn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gsm_SecurityContextData,
{ "gsm-SecurityContextData", "gsm_map.ms.gsm_SecurityContextData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_umts_SecurityContextData,
{ "umts-SecurityContextData", "gsm_map.ms.umts_SecurityContextData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cksn,
{ "cksn", "gsm_map.ms.cksn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ksi,
{ "ksi", "gsm_map.ms.ksi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_failureCause,
{ "failureCause", "gsm_map.ms.failureCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_FailureCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_re_attempt,
{ "re-attempt", "gsm_map.ms.re_attempt",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_accessType,
{ "accessType", "gsm_map.ms.accessType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_AccessType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sgsn_Address,
{ "sgsn-Address", "gsm_map.ms.sgsn_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_ms_sgsn_Capability,
{ "sgsn-Capability", "gsm_map.ms.sgsn_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_LCS_NotSupportedByUE,
{ "ps-LCS-NotSupportedByUE", "gsm_map.ms.ps_LCS_NotSupportedByUE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_eps_info,
{ "eps-info", "gsm_map.ms.eps_info",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_EPS_Info_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_servingNodeTypeIndicator,
{ "servingNodeTypeIndicator", "gsm_map.ms.servingNodeTypeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_usedRAT_Type,
{ "usedRAT-Type", "gsm_map.ms.usedRAT_Type",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_Used_RAT_Type_vals), 0,
"Used_RAT_Type", HFILL }},
{ &hf_gsm_map_ms_gprsSubscriptionDataNotNeeded,
{ "gprsSubscriptionDataNotNeeded", "gsm_map.ms.gprsSubscriptionDataNotNeeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_nodeTypeIndicator,
{ "nodeTypeIndicator", "gsm_map.ms.nodeTypeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_areaRestricted,
{ "areaRestricted", "gsm_map.ms.areaRestricted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ue_reachableIndicator,
{ "ue-reachableIndicator", "gsm_map.ms.ue_reachableIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_epsSubscriptionDataNotNeeded,
{ "epsSubscriptionDataNotNeeded", "gsm_map.ms.epsSubscriptionDataNotNeeded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ue_srvcc_Capability,
{ "ue-srvcc-Capability", "gsm_map.ms.ue_srvcc_Capability",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_UE_SRVCC_Capability_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mmeNumberforMTSMS,
{ "mmeNumberforMTSMS", "gsm_map.ms.mmeNumberforMTSMS",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_smsRegisterRequest,
{ "smsRegisterRequest", "gsm_map.ms.smsRegisterRequest",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SMSRegisterRequest_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sms_Only,
{ "sms-Only", "gsm_map.ms.sms_Only_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_removalofMMERegistrationforSMS,
{ "removalofMMERegistrationforSMS", "gsm_map.ms.removalofMMERegistrationforSMS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sgsn_Name,
{ "sgsn-Name", "gsm_map.ms.sgsn_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_ms_sgsn_Realm,
{ "sgsn-Realm", "gsm_map.ms.sgsn_Realm",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_ms_lgd_supportIndicator,
{ "lgd-supportIndicator", "gsm_map.ms.lgd_supportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdn_gw_update,
{ "pdn-gw-update", "gsm_map.ms.pdn_gw_update_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_isr_Information,
{ "isr-Information", "gsm_map.ms.isr_Information",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_apn,
{ "apn", "gsm_map.ms.apn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdn_gw_Identity,
{ "pdn-gw-Identity", "gsm_map.ms.pdn_gw_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_contextId,
{ "contextId", "gsm_map.ms.contextId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprsEnhancementsSupportIndicator,
{ "gprsEnhancementsSupportIndicator", "gsm_map.ms.gprsEnhancementsSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_smsCallBarringSupportIndicator,
{ "smsCallBarringSupportIndicator", "gsm_map.ms.smsCallBarringSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedFeatures,
{ "supportedFeatures", "gsm_map.ms.supportedFeatures",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_adsDataRetrieval,
{ "t-adsDataRetrieval", "gsm_map.ms.t_adsDataRetrieval_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_homogeneousSupportOfIMSVoiceOverPSSessions,
{ "homogeneousSupportOfIMSVoiceOverPSSessions", "gsm_map.ms.homogeneousSupportOfIMSVoiceOverPSSessions",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_cancellationTypeInitialAttach,
{ "cancellationTypeInitialAttach", "gsm_map.ms.cancellationTypeInitialAttach_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_updateofHomogeneousSupportOfIMSVoiceOverPSSessions,
{ "updateofHomogeneousSupportOfIMSVoiceOverPSSessions", "gsm_map.ms.updateofHomogeneousSupportOfIMSVoiceOverPSSessions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sgsn_mmeSeparationSupported,
{ "sgsn-mmeSeparationSupported", "gsm_map.ms.sgsn_mmeSeparationSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mmeRegisteredforSMS,
{ "mmeRegisteredforSMS", "gsm_map.ms.mmeRegisteredforSMS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_EPLMN_List_item,
{ "PLMN-Id", "gsm_map.ms.PLMN_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_an_APDU,
{ "an-APDU", "gsm_map.ms.an_APDU_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessNetworkSignalInfo", HFILL }},
{ &hf_gsm_map_ms_integrityProtectionInfo,
{ "integrityProtectionInfo", "gsm_map.ms.integrityProtectionInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"IntegrityProtectionInformation", HFILL }},
{ &hf_gsm_map_ms_encryptionInfo,
{ "encryptionInfo", "gsm_map.ms.encryptionInfo",
FT_BYTES, BASE_NONE, NULL, 0,
"EncryptionInformation", HFILL }},
{ &hf_gsm_map_ms_keyStatus,
{ "keyStatus", "gsm_map.ms.keyStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_KeyStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allowedGSM_Algorithms,
{ "allowedGSM-Algorithms", "gsm_map.ms.allowedGSM_Algorithms",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allowedUMTS_Algorithms,
{ "allowedUMTS-Algorithms", "gsm_map.ms.allowedUMTS_Algorithms_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_radioResourceInformation,
{ "radioResourceInformation", "gsm_map.ms.radioResourceInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_radioResourceList,
{ "radioResourceList", "gsm_map.ms.radioResourceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_bssmap_ServiceHandover,
{ "bssmap-ServiceHandover", "gsm_map.ms.bssmap_ServiceHandover",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ranap_ServiceHandover,
{ "ranap-ServiceHandover", "gsm_map.ms.ranap_ServiceHandover",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_bssmap_ServiceHandoverList,
{ "bssmap-ServiceHandoverList", "gsm_map.ms.bssmap_ServiceHandoverList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_currentlyUsedCodec,
{ "currentlyUsedCodec", "gsm_map.ms.currentlyUsedCodec",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_iuSupportedCodecsList,
{ "iuSupportedCodecsList", "gsm_map.ms.iuSupportedCodecsList_element",
FT_NONE, BASE_NONE, NULL, 0,
"SupportedCodecsList", HFILL }},
{ &hf_gsm_map_ms_rab_ConfigurationIndicator,
{ "rab-ConfigurationIndicator", "gsm_map.ms.rab_ConfigurationIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_iuSelectedCodec,
{ "iuSelectedCodec", "gsm_map.ms.iuSelectedCodec",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_alternativeChannelType,
{ "alternativeChannelType", "gsm_map.ms.alternativeChannelType",
FT_BYTES, BASE_NONE, NULL, 0,
"RadioResourceInformation", HFILL }},
{ &hf_gsm_map_ms_tracePropagationList,
{ "tracePropagationList", "gsm_map.ms.tracePropagationList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_aoipSupportedCodecsListAnchor,
{ "aoipSupportedCodecsListAnchor", "gsm_map.ms.aoipSupportedCodecsListAnchor_element",
FT_NONE, BASE_NONE, NULL, 0,
"AoIPCodecsList", HFILL }},
{ &hf_gsm_map_ms_aoipSelectedCodecTarget,
{ "aoipSelectedCodecTarget", "gsm_map.ms.aoipSelectedCodecTarget",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_integrityProtectionAlgorithms,
{ "integrityProtectionAlgorithms", "gsm_map.ms.integrityProtectionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
"PermittedIntegrityProtectionAlgorithms", HFILL }},
{ &hf_gsm_map_ms_encryptionAlgorithms,
{ "encryptionAlgorithms", "gsm_map.ms.encryptionAlgorithms",
FT_BYTES, BASE_NONE, NULL, 0,
"PermittedEncryptionAlgorithms", HFILL }},
{ &hf_gsm_map_ms_targetCellId,
{ "targetCellId", "gsm_map.ms.targetCellId",
FT_BYTES, BASE_NONE, NULL, 0,
"GlobalCellId", HFILL }},
{ &hf_gsm_map_ms_ho_NumberNotRequired,
{ "ho-NumberNotRequired", "gsm_map.ms.ho_NumberNotRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_targetRNCId,
{ "targetRNCId", "gsm_map.ms.targetRNCId",
FT_BYTES, BASE_NONE, NULL, 0,
"RNCId", HFILL }},
{ &hf_gsm_map_ms_multipleBearerRequested,
{ "multipleBearerRequested", "gsm_map.ms.multipleBearerRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_rab_Id,
{ "rab-Id", "gsm_map.ms.rab_Id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_asciCallReference,
{ "asciCallReference", "gsm_map.ms.asciCallReference",
FT_BYTES, BASE_NONE, NULL, 0,
"ASCI_CallReference", HFILL }},
{ &hf_gsm_map_ms_geran_classmark,
{ "geran-classmark", "gsm_map.ms.geran_classmark",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_iuCurrentlyUsedCodec,
{ "iuCurrentlyUsedCodec", "gsm_map.ms.iuCurrentlyUsedCodec",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_uesbi_Iu,
{ "uesbi-Iu", "gsm_map.ms.uesbi_Iu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_regionalSubscriptionData,
{ "regionalSubscriptionData", "gsm_map.ms.regionalSubscriptionData",
FT_UINT32, BASE_DEC, NULL, 0,
"ZoneCodeList", HFILL }},
{ &hf_gsm_map_ms_lclsGlobalCallReference,
{ "lclsGlobalCallReference", "gsm_map.ms.lclsGlobalCallReference",
FT_BYTES, BASE_NONE, NULL, 0,
"LCLS_GlobalCallReference", HFILL }},
{ &hf_gsm_map_ms_lcls_Negotiation,
{ "lcls-Negotiation", "gsm_map.ms.lcls_Negotiation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lcls_Configuration_Preference,
{ "lcls-Configuration-Preference", "gsm_map.ms.lcls_Configuration_Preference",
FT_BYTES, BASE_NONE, NULL, 0,
"LCLS_ConfigurationPreference", HFILL }},
{ &hf_gsm_map_ms_csg_SubscriptionDataList,
{ "csg-SubscriptionDataList", "gsm_map.ms.csg_SubscriptionDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_BSSMAP_ServiceHandoverList_item,
{ "BSSMAP-ServiceHandoverInfo", "gsm_map.ms.BSSMAP_ServiceHandoverInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_RadioResourceList_item,
{ "RadioResource", "gsm_map.ms.RadioResource_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_handoverNumber,
{ "handoverNumber", "gsm_map.ms.handoverNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_relocationNumberList,
{ "relocationNumberList", "gsm_map.ms.relocationNumberList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_multicallBearerInfo,
{ "multicallBearerInfo", "gsm_map.ms.multicallBearerInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_multipleBearerNotSupported,
{ "multipleBearerNotSupported", "gsm_map.ms.multipleBearerNotSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_selectedUMTS_Algorithms,
{ "selectedUMTS-Algorithms", "gsm_map.ms.selectedUMTS_Algorithms_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_chosenRadioResourceInformation,
{ "chosenRadioResourceInformation", "gsm_map.ms.chosenRadioResourceInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_iuAvailableCodecsList,
{ "iuAvailableCodecsList", "gsm_map.ms.iuAvailableCodecsList_element",
FT_NONE, BASE_NONE, NULL, 0,
"CodecList", HFILL }},
{ &hf_gsm_map_ms_aoipAvailableCodecsListMap,
{ "aoipAvailableCodecsListMap", "gsm_map.ms.aoipAvailableCodecsListMap_element",
FT_NONE, BASE_NONE, NULL, 0,
"AoIPCodecsList", HFILL }},
{ &hf_gsm_map_ms_integrityProtectionAlgorithm,
{ "integrityProtectionAlgorithm", "gsm_map.ms.integrityProtectionAlgorithm",
FT_BYTES, BASE_NONE, NULL, 0,
"ChosenIntegrityProtectionAlgorithm", HFILL }},
{ &hf_gsm_map_ms_encryptionAlgorithm,
{ "encryptionAlgorithm", "gsm_map.ms.encryptionAlgorithm",
FT_BYTES, BASE_NONE, NULL, 0,
"ChosenEncryptionAlgorithm", HFILL }},
{ &hf_gsm_map_ms_chosenChannelInfo,
{ "chosenChannelInfo", "gsm_map.ms.chosenChannelInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_chosenSpeechVersion,
{ "chosenSpeechVersion", "gsm_map.ms.chosenSpeechVersion",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_targetMSC_Number,
{ "targetMSC-Number", "gsm_map.ms.targetMSC_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_selectedRab_Id,
{ "selectedRab-Id", "gsm_map.ms.selectedRab_Id",
FT_UINT32, BASE_DEC, NULL, 0,
"RAB_Id", HFILL }},
{ &hf_gsm_map_ms_selectedGSM_Algorithm,
{ "selectedGSM-Algorithm", "gsm_map.ms.selectedGSM_Algorithm",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_iUSelectedCodec,
{ "iUSelectedCodec", "gsm_map.ms.iUSelectedCodec",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec1,
{ "codec1", "gsm_map.ms.codec1",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec2,
{ "codec2", "gsm_map.ms.codec2",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec3,
{ "codec3", "gsm_map.ms.codec3",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec4,
{ "codec4", "gsm_map.ms.codec4",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec5,
{ "codec5", "gsm_map.ms.codec5",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec6,
{ "codec6", "gsm_map.ms.codec6",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec7,
{ "codec7", "gsm_map.ms.codec7",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_codec8,
{ "codec8", "gsm_map.ms.codec8",
FT_BYTES, BASE_NONE, NULL, 0,
"AoIPCodec", HFILL }},
{ &hf_gsm_map_ms_utranCodecList,
{ "utranCodecList", "gsm_map.ms.utranCodecList_element",
FT_NONE, BASE_NONE, NULL, 0,
"CodecList", HFILL }},
{ &hf_gsm_map_ms_geranCodecList,
{ "geranCodecList", "gsm_map.ms.geranCodecList_element",
FT_NONE, BASE_NONE, NULL, 0,
"CodecList", HFILL }},
{ &hf_gsm_map_ms_codec1_01,
{ "codec1", "gsm_map.ms.codec1",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec2_01,
{ "codec2", "gsm_map.ms.codec2",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec3_01,
{ "codec3", "gsm_map.ms.codec3",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec4_01,
{ "codec4", "gsm_map.ms.codec4",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec5_01,
{ "codec5", "gsm_map.ms.codec5",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec6_01,
{ "codec6", "gsm_map.ms.codec6",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec7_01,
{ "codec7", "gsm_map.ms.codec7",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_codec8_01,
{ "codec8", "gsm_map.ms.codec8",
FT_BYTES, BASE_NONE, NULL, 0,
"Codec", HFILL }},
{ &hf_gsm_map_ms_RelocationNumberList_item,
{ "RelocationNumber", "gsm_map.ms.RelocationNumber_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_immediateResponsePreferred,
{ "immediateResponsePreferred", "gsm_map.ms.immediateResponsePreferred_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_re_synchronisationInfo,
{ "re-synchronisationInfo", "gsm_map.ms.re_synchronisationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestingNodeType,
{ "requestingNodeType", "gsm_map.ms.requestingNodeType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_RequestingNodeType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestingPLMN_Id,
{ "requestingPLMN-Id", "gsm_map.ms.requestingPLMN_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gsm_map_ms_numberOfRequestedAdditional_Vectors,
{ "numberOfRequestedAdditional-Vectors", "gsm_map.ms.numberOfRequestedAdditional_Vectors",
FT_UINT32, BASE_DEC, NULL, 0,
"NumberOfRequestedVectors", HFILL }},
{ &hf_gsm_map_ms_additionalVectorsAreForEPS,
{ "additionalVectorsAreForEPS", "gsm_map.ms.additionalVectorsAreForEPS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_auts,
{ "auts", "gsm_map.ms.auts",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_eps_AuthenticationSetList,
{ "eps-AuthenticationSetList", "gsm_map.ms.eps_AuthenticationSetList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_EPS_AuthenticationSetList_item,
{ "EPC-AV", "gsm_map.ms.EPC_AV_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_kasme,
{ "kasme", "gsm_map.ms.kasme",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_imei,
{ "imei", "gsm_map.ms.imei",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedEquipmentInfo,
{ "requestedEquipmentInfo", "gsm_map.ms.requestedEquipmentInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_equipmentStatus,
{ "equipmentStatus", "gsm_map.ms.equipmentStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_EquipmentStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_bmuef,
{ "bmuef", "gsm_map.ms.bmuef_element",
FT_NONE, BASE_NONE, NULL, 0,
"UESBI_Iu", HFILL }},
{ &hf_gsm_map_ms_uesbi_IuA,
{ "uesbi-IuA", "gsm_map.ms.uesbi_IuA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_uesbi_IuB,
{ "uesbi-IuB", "gsm_map.ms.uesbi_IuB",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_CSG_SubscriptionDataList_item,
{ "CSG-SubscriptionData", "gsm_map.ms.CSG_SubscriptionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_csg_Id,
{ "csg-Id", "gsm_map.ms.csg_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_expirationDate,
{ "expirationDate", "gsm_map.ms.expirationDate",
FT_BYTES, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_gsm_map_ms_lipa_AllowedAPNList,
{ "lipa-AllowedAPNList", "gsm_map.ms.lipa_AllowedAPNList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_plmn_Id,
{ "plmn-Id", "gsm_map.ms.plmn_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_VPLMN_CSG_SubscriptionDataList_item,
{ "CSG-SubscriptionData", "gsm_map.ms.CSG_SubscriptionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_LIPA_AllowedAPNList_item,
{ "APN", "gsm_map.ms.APN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_apn_oi_Replacement,
{ "apn-oi-Replacement", "gsm_map.ms.apn_oi_Replacement",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_rfsp_id,
{ "rfsp-id", "gsm_map.ms.rfsp_id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ambr,
{ "ambr", "gsm_map.ms.ambr_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_apn_ConfigurationProfile,
{ "apn-ConfigurationProfile", "gsm_map.ms.apn_ConfigurationProfile_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_stn_sr,
{ "stn-sr", "gsm_map.ms.stn_sr",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_mps_CSPriority,
{ "mps-CSPriority", "gsm_map.ms.mps_CSPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mps_EPSPriority,
{ "mps-EPSPriority", "gsm_map.ms.mps_EPSPriority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscribed_vsrvcc,
{ "subscribed-vsrvcc", "gsm_map.ms.subscribed_vsrvcc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_defaultContext,
{ "defaultContext", "gsm_map.ms.defaultContext",
FT_UINT32, BASE_DEC, NULL, 0,
"ContextId", HFILL }},
{ &hf_gsm_map_ms_completeDataListIncluded,
{ "completeDataListIncluded", "gsm_map.ms.completeDataListIncluded_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_epsDataList,
{ "epsDataList", "gsm_map.ms.epsDataList",
FT_UINT32, BASE_DEC, NULL, 0,
"EPS_DataList", HFILL }},
{ &hf_gsm_map_ms_EPS_DataList_item,
{ "APN-Configuration", "gsm_map.ms.APN_Configuration_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdn_Type,
{ "pdn-Type", "gsm_map.ms.pdn_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_servedPartyIP_IPv4_Address,
{ "servedPartyIP-IPv4-Address", "gsm_map.ms.servedPartyIP_IPv4_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"PDP_Address", HFILL }},
{ &hf_gsm_map_ms_eps_qos_Subscribed,
{ "eps-qos-Subscribed", "gsm_map.ms.eps_qos_Subscribed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdn_gw_AllocationType,
{ "pdn-gw-AllocationType", "gsm_map.ms.pdn_gw_AllocationType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_PDN_GW_AllocationType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vplmnAddressAllowed,
{ "vplmnAddressAllowed", "gsm_map.ms.vplmnAddressAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_chargingCharacteristics,
{ "chargingCharacteristics", "gsm_map.ms.chargingCharacteristics",
FT_UINT16, BASE_DEC, VALS(chargingcharacteristics_values), 0x0f00,
NULL, HFILL }},
{ &hf_gsm_map_ms_specificAPNInfoList,
{ "specificAPNInfoList", "gsm_map.ms.specificAPNInfoList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_servedPartyIP_IPv6_Address,
{ "servedPartyIP-IPv6-Address", "gsm_map.ms.servedPartyIP_IPv6_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"PDP_Address", HFILL }},
{ &hf_gsm_map_ms_sipto_Permission,
{ "sipto-Permission", "gsm_map.ms.sipto_Permission",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SIPTO_Permission_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lipa_Permission,
{ "lipa-Permission", "gsm_map.ms.lipa_Permission",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_LIPA_Permission_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_restoration_Priority,
{ "restoration-Priority", "gsm_map.ms.restoration_Priority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sipto_local_network_Permission,
{ "sipto-local-network-Permission", "gsm_map.ms.sipto_local_network_Permission",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SIPTO_Local_Network_Permission_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_qos_Class_Identifier,
{ "qos-Class-Identifier", "gsm_map.ms.qos_Class_Identifier",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allocation_Retention_Priority,
{ "allocation-Retention-Priority", "gsm_map.ms.allocation_Retention_Priority_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_max_RequestedBandwidth_UL,
{ "max-RequestedBandwidth-UL", "gsm_map.ms.max_RequestedBandwidth_UL",
FT_INT32, BASE_DEC, NULL, 0,
"Bandwidth", HFILL }},
{ &hf_gsm_map_ms_max_RequestedBandwidth_DL,
{ "max-RequestedBandwidth-DL", "gsm_map.ms.max_RequestedBandwidth_DL",
FT_INT32, BASE_DEC, NULL, 0,
"Bandwidth", HFILL }},
{ &hf_gsm_map_ms_SpecificAPNInfoList_item,
{ "SpecificAPNInfo", "gsm_map.ms.SpecificAPNInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_priority_level,
{ "priority-level", "gsm_map.ms.priority_level",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gsm_map_ms_pre_emption_capability,
{ "pre-emption-capability", "gsm_map.ms.pre_emption_capability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_pre_emption_vulnerability,
{ "pre-emption-vulnerability", "gsm_map.ms.pre_emption_vulnerability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_pdn_gw_ipv4_Address,
{ "pdn-gw-ipv4-Address", "gsm_map.ms.pdn_gw_ipv4_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"PDP_Address", HFILL }},
{ &hf_gsm_map_ms_pdn_gw_ipv6_Address,
{ "pdn-gw-ipv6-Address", "gsm_map.ms.pdn_gw_ipv6_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"PDP_Address", HFILL }},
{ &hf_gsm_map_ms_pdn_gw_name,
{ "pdn-gw-name", "gsm_map.ms.pdn_gw_name",
FT_BYTES, BASE_NONE, NULL, 0,
"FQDN", HFILL }},
{ &hf_gsm_map_ms_gmlc_List,
{ "gmlc-List", "gsm_map.ms.gmlc_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lcs_PrivacyExceptionList,
{ "lcs-PrivacyExceptionList", "gsm_map.ms.lcs_PrivacyExceptionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_molr_List,
{ "molr-List", "gsm_map.ms.molr_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_add_lcs_PrivacyExceptionList,
{ "add-lcs-PrivacyExceptionList", "gsm_map.ms.add_lcs_PrivacyExceptionList",
FT_UINT32, BASE_DEC, NULL, 0,
"LCS_PrivacyExceptionList", HFILL }},
{ &hf_gsm_map_ms_GMLC_List_item,
{ "ISDN-AddressString", "gsm_map.ms.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_GPRSDataList_item,
{ "PDP-Context", "gsm_map.ms.PDP_Context_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdp_ContextId,
{ "pdp-ContextId", "gsm_map.ms.pdp_ContextId",
FT_UINT32, BASE_DEC, NULL, 0,
"ContextId", HFILL }},
{ &hf_gsm_map_ms_pdp_Type,
{ "pdp-Type", "gsm_map.ms.pdp_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdp_Address,
{ "pdp-Address", "gsm_map.ms.pdp_Address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_qos_Subscribed,
{ "qos-Subscribed", "gsm_map.ms.qos_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext_QoS_Subscribed,
{ "ext-QoS-Subscribed", "gsm_map.ms.ext_QoS_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdp_ChargingCharacteristics,
{ "pdp-ChargingCharacteristics", "gsm_map.ms.pdp_ChargingCharacteristics",
FT_UINT16, BASE_DEC, VALS(chargingcharacteristics_values), 0x0f00,
"ChargingCharacteristics", HFILL }},
{ &hf_gsm_map_ms_ext2_QoS_Subscribed,
{ "ext2-QoS-Subscribed", "gsm_map.ms.ext2_QoS_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext3_QoS_Subscribed,
{ "ext3-QoS-Subscribed", "gsm_map.ms.ext3_QoS_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext4_QoS_Subscribed,
{ "ext4-QoS-Subscribed", "gsm_map.ms.ext4_QoS_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext_pdp_Type,
{ "ext-pdp-Type", "gsm_map.ms.ext_pdp_Type",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext_pdp_Address,
{ "ext-pdp-Address", "gsm_map.ms.ext_pdp_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"PDP_Address", HFILL }},
{ &hf_gsm_map_ms_gprsDataList,
{ "gprsDataList", "gsm_map.ms.gprsDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprs_CSI,
{ "gprs-CSI", "gsm_map.ms.gprs_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mo_sms_CSI,
{ "mo-sms-CSI", "gsm_map.ms.mo_sms_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMS_CSI", HFILL }},
{ &hf_gsm_map_ms_mt_sms_CSI,
{ "mt-sms-CSI", "gsm_map.ms.mt_sms_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMS_CSI", HFILL }},
{ &hf_gsm_map_ms_mt_smsCAMELTDP_CriteriaList,
{ "mt-smsCAMELTDP-CriteriaList", "gsm_map.ms.mt_smsCAMELTDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mg_csi,
{ "mg-csi", "gsm_map.ms.mg_csi_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprs_CamelTDPDataList,
{ "gprs-CamelTDPDataList", "gsm_map.ms.gprs_CamelTDPDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_camelCapabilityHandling,
{ "camelCapabilityHandling", "gsm_map.ms.camelCapabilityHandling",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_notificationToCSE,
{ "notificationToCSE", "gsm_map.ms.notificationToCSE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_csi_Active,
{ "csi-Active", "gsm_map.ms.csi_Active_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_GPRS_CamelTDPDataList_item,
{ "GPRS-CamelTDPData", "gsm_map.ms.GPRS_CamelTDPData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprs_TriggerDetectionPoint,
{ "gprs-TriggerDetectionPoint", "gsm_map.ms.gprs_TriggerDetectionPoint",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_GPRS_TriggerDetectionPoint_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_serviceKey,
{ "serviceKey", "gsm_map.ms.serviceKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gsmSCF_Address,
{ "gsmSCF-Address", "gsm_map.ms.gsmSCF_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_defaultSessionHandling,
{ "defaultSessionHandling", "gsm_map.ms.defaultSessionHandling",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DefaultGPRS_Handling_vals), 0,
"DefaultGPRS_Handling", HFILL }},
{ &hf_gsm_map_ms_LSADataList_item,
{ "LSAData", "gsm_map.ms.LSAData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaIdentity,
{ "lsaIdentity", "gsm_map.ms.lsaIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaAttributes,
{ "lsaAttributes", "gsm_map.ms.lsaAttributes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaActiveModeIndicator,
{ "lsaActiveModeIndicator", "gsm_map.ms.lsaActiveModeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaOnlyAccessIndicator,
{ "lsaOnlyAccessIndicator", "gsm_map.ms.lsaOnlyAccessIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_LSAOnlyAccessIndicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaDataList,
{ "lsaDataList", "gsm_map.ms.lsaDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_msisdn,
{ "msisdn", "gsm_map.ms.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_category,
{ "category", "gsm_map.ms.category",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscriberStatus,
{ "subscriberStatus", "gsm_map.ms.subscriberStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SubscriberStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_bearerServiceList,
{ "bearerServiceList", "gsm_map.ms.bearerServiceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_teleserviceList,
{ "teleserviceList", "gsm_map.ms.teleserviceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_provisionedSS,
{ "provisionedSS", "gsm_map.ms.provisionedSS",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_SS_InfoList", HFILL }},
{ &hf_gsm_map_ms_odb_Data,
{ "odb-Data", "gsm_map.ms.odb_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_roamingRestrictionDueToUnsupportedFeature,
{ "roamingRestrictionDueToUnsupportedFeature", "gsm_map.ms.roamingRestrictionDueToUnsupportedFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vbsSubscriptionData,
{ "vbsSubscriptionData", "gsm_map.ms.vbsSubscriptionData",
FT_UINT32, BASE_DEC, NULL, 0,
"VBSDataList", HFILL }},
{ &hf_gsm_map_ms_vgcsSubscriptionData,
{ "vgcsSubscriptionData", "gsm_map.ms.vgcsSubscriptionData",
FT_UINT32, BASE_DEC, NULL, 0,
"VGCSDataList", HFILL }},
{ &hf_gsm_map_ms_vlrCamelSubscriptionInfo,
{ "vlrCamelSubscriptionInfo", "gsm_map.ms.vlrCamelSubscriptionInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_BearerServiceList_item,
{ "Ext-BearerServiceCode", "gsm_map.ms.Ext_BearerServiceCode",
FT_UINT8, BASE_DEC, VALS(Bearerservice_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_TeleserviceList_item,
{ "Ext-TeleserviceCode", "gsm_map.ms.Ext_TeleserviceCode",
FT_UINT8, BASE_DEC, VALS(Teleservice_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_odb_GeneralData,
{ "odb-GeneralData", "gsm_map.ms.odb_GeneralData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_odb_HPLMN_Data,
{ "odb-HPLMN-Data", "gsm_map.ms.odb_HPLMN_Data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_Ext_SS_InfoList_item,
{ "Ext-SS-Info", "gsm_map.ms.Ext_SS_Info",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_Ext_SS_Info_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_forwardingInfo,
{ "forwardingInfo", "gsm_map.ms.forwardingInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_ForwInfo", HFILL }},
{ &hf_gsm_map_ms_callBarringInfo,
{ "callBarringInfo", "gsm_map.ms.callBarringInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_CallBarInfo", HFILL }},
{ &hf_gsm_map_ms_cug_Info,
{ "cug-Info", "gsm_map.ms.cug_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_Data,
{ "ss-Data", "gsm_map.ms.ss_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_SS_Data", HFILL }},
{ &hf_gsm_map_ms_emlpp_Info,
{ "emlpp-Info", "gsm_map.ms.emlpp_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_Code,
{ "ss-Code", "gsm_map.ms.ss_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_forwardingFeatureList,
{ "forwardingFeatureList", "gsm_map.ms.forwardingFeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_ForwFeatureList", HFILL }},
{ &hf_gsm_map_ms_Ext_ForwFeatureList_item,
{ "Ext-ForwFeature", "gsm_map.ms.Ext_ForwFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_basicService,
{ "basicService", "gsm_map.ms.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_gsm_map_ms_ss_Status,
{ "ss-Status", "gsm_map.ms.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_SS_Status", HFILL }},
{ &hf_gsm_map_ms_forwardedToNumber,
{ "forwardedToNumber", "gsm_map.ms.forwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_forwardedToSubaddress,
{ "forwardedToSubaddress", "gsm_map.ms.forwardedToSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_map_ms_forwardingOptions,
{ "forwardingOptions", "gsm_map.ms.forwardingOptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_noReplyConditionTime,
{ "noReplyConditionTime", "gsm_map.ms.noReplyConditionTime",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_NoRepCondTime", HFILL }},
{ &hf_gsm_map_ms_longForwardedToNumber,
{ "longForwardedToNumber", "gsm_map.ms.longForwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"FTN_AddressString", HFILL }},
{ &hf_gsm_map_ms_callBarringFeatureList,
{ "callBarringFeatureList", "gsm_map.ms.callBarringFeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_CallBarFeatureList", HFILL }},
{ &hf_gsm_map_ms_Ext_CallBarFeatureList_item,
{ "Ext-CallBarringFeature", "gsm_map.ms.Ext_CallBarringFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cug_SubscriptionList,
{ "cug-SubscriptionList", "gsm_map.ms.cug_SubscriptionList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cug_FeatureList,
{ "cug-FeatureList", "gsm_map.ms.cug_FeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_CUG_SubscriptionList_item,
{ "CUG-Subscription", "gsm_map.ms.CUG_Subscription_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cug_Index,
{ "cug-Index", "gsm_map.ms.cug_Index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cug_Interlock,
{ "cug-Interlock", "gsm_map.ms.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_intraCUG_Options,
{ "intraCUG-Options", "gsm_map.ms.intraCUG_Options",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_IntraCUG_Options_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_basicServiceGroupList,
{ "basicServiceGroupList", "gsm_map.ms.basicServiceGroupList",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_BasicServiceGroupList", HFILL }},
{ &hf_gsm_map_ms_CUG_FeatureList_item,
{ "CUG-Feature", "gsm_map.ms.CUG_Feature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_Ext_BasicServiceGroupList_item,
{ "Ext-BasicServiceCode", "gsm_map.ms.Ext_BasicServiceCode",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_preferentialCUG_Indicator,
{ "preferentialCUG-Indicator", "gsm_map.ms.preferentialCUG_Indicator",
FT_UINT32, BASE_DEC, NULL, 0,
"CUG_Index", HFILL }},
{ &hf_gsm_map_ms_interCUG_Restrictions,
{ "interCUG-Restrictions", "gsm_map.ms.interCUG_Restrictions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_SubscriptionOption,
{ "ss-SubscriptionOption", "gsm_map.ms.ss_SubscriptionOption",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_SS_SubscriptionOption_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCS_PrivacyExceptionList_item,
{ "LCS-PrivacyClass", "gsm_map.ms.LCS_PrivacyClass_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_notificationToMSUser,
{ "notificationToMSUser", "gsm_map.ms.notificationToMSUser",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NotificationToMSUser_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_externalClientList,
{ "externalClientList", "gsm_map.ms.externalClientList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_plmnClientList,
{ "plmnClientList", "gsm_map.ms.plmnClientList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ext_externalClientList,
{ "ext-externalClientList", "gsm_map.ms.ext_externalClientList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_serviceTypeList,
{ "serviceTypeList", "gsm_map.ms.serviceTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ExternalClientList_item,
{ "ExternalClient", "gsm_map.ms.ExternalClient_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_PLMNClientList_item,
{ "LCSClientInternalID", "gsm_map.ms.LCSClientInternalID",
FT_UINT32, BASE_DEC, VALS(gsm_map_LCSClientInternalID_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_Ext_ExternalClientList_item,
{ "ExternalClient", "gsm_map.ms.ExternalClient_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_clientIdentity,
{ "clientIdentity", "gsm_map.ms.clientIdentity_element",
FT_NONE, BASE_NONE, NULL, 0,
"LCSClientExternalID", HFILL }},
{ &hf_gsm_map_ms_gmlc_Restriction,
{ "gmlc-Restriction", "gsm_map.ms.gmlc_Restriction",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_GMLC_Restriction_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ServiceTypeList_item,
{ "ServiceType", "gsm_map.ms.ServiceType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_serviceTypeIdentity,
{ "serviceTypeIdentity", "gsm_map.ms.serviceTypeIdentity",
FT_UINT32, BASE_DEC, VALS(gsm_map_LCSServiceTypeID_vals), 0,
"LCSServiceTypeID", HFILL }},
{ &hf_gsm_map_ms_MOLR_List_item,
{ "MOLR-Class", "gsm_map.ms.MOLR_Class_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ZoneCodeList_item,
{ "ZoneCode", "gsm_map.ms.ZoneCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_List,
{ "ss-List", "gsm_map.ms.ss_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_regionalSubscriptionResponse,
{ "regionalSubscriptionResponse", "gsm_map.ms.regionalSubscriptionResponse",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_RegionalSubscriptionResponse_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_basicServiceList,
{ "basicServiceList", "gsm_map.ms.basicServiceList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_regionalSubscriptionIdentifier,
{ "regionalSubscriptionIdentifier", "gsm_map.ms.regionalSubscriptionIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"ZoneCode", HFILL }},
{ &hf_gsm_map_ms_vbsGroupIndication,
{ "vbsGroupIndication", "gsm_map.ms.vbsGroupIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vgcsGroupIndication,
{ "vgcsGroupIndication", "gsm_map.ms.vgcsGroupIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_camelSubscriptionInfoWithdraw,
{ "camelSubscriptionInfoWithdraw", "gsm_map.ms.camelSubscriptionInfoWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprsSubscriptionDataWithdraw,
{ "gprsSubscriptionDataWithdraw", "gsm_map.ms.gprsSubscriptionDataWithdraw",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_GPRSSubscriptionDataWithdraw_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_roamingRestrictedInSgsnDueToUnsuppportedFeature,
{ "roamingRestrictedInSgsnDueToUnsuppportedFeature", "gsm_map.ms.roamingRestrictedInSgsnDueToUnsuppportedFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaInformationWithdraw,
{ "lsaInformationWithdraw", "gsm_map.ms.lsaInformationWithdraw",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_LSAInformationWithdraw_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gmlc_ListWithdraw,
{ "gmlc-ListWithdraw", "gsm_map.ms.gmlc_ListWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_istInformationWithdraw,
{ "istInformationWithdraw", "gsm_map.ms.istInformationWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_specificCSI_Withdraw,
{ "specificCSI-Withdraw", "gsm_map.ms.specificCSI_Withdraw",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_chargingCharacteristicsWithdraw,
{ "chargingCharacteristicsWithdraw", "gsm_map.ms.chargingCharacteristicsWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_stn_srWithdraw,
{ "stn-srWithdraw", "gsm_map.ms.stn_srWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_epsSubscriptionDataWithdraw,
{ "epsSubscriptionDataWithdraw", "gsm_map.ms.epsSubscriptionDataWithdraw",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_EPS_SubscriptionDataWithdraw_vals), 0,
"EPS_SubscriptionDataWithdraw", HFILL }},
{ &hf_gsm_map_ms_apn_oi_replacementWithdraw,
{ "apn-oi-replacementWithdraw", "gsm_map.ms.apn_oi_replacementWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_csg_SubscriptionDeleted,
{ "csg-SubscriptionDeleted", "gsm_map.ms.csg_SubscriptionDeleted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscribedPeriodicTAU_RAU_TimerWithdraw,
{ "subscribedPeriodicTAU-RAU-TimerWithdraw", "gsm_map.ms.subscribedPeriodicTAU_RAU_TimerWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscribedPeriodicLAU_TimerWithdraw,
{ "subscribedPeriodicLAU-TimerWithdraw", "gsm_map.ms.subscribedPeriodicLAU_TimerWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscribed_vsrvccWithdraw,
{ "subscribed-vsrvccWithdraw", "gsm_map.ms.subscribed_vsrvccWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vplmn_Csg_SubscriptionDeleted,
{ "vplmn-Csg-SubscriptionDeleted", "gsm_map.ms.vplmn_Csg_SubscriptionDeleted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_additionalMSISDN_Withdraw,
{ "additionalMSISDN-Withdraw", "gsm_map.ms.additionalMSISDN_Withdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allGPRSData,
{ "allGPRSData", "gsm_map.ms.allGPRSData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_contextIdList,
{ "contextIdList", "gsm_map.ms.contextIdList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allEPS_Data,
{ "allEPS-Data", "gsm_map.ms.allEPS_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ContextIdList_item,
{ "ContextId", "gsm_map.ms.ContextId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_allLSAData,
{ "allLSAData", "gsm_map.ms.allLSAData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaIdentityList,
{ "lsaIdentityList", "gsm_map.ms.lsaIdentityList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_LSAIdentityList_item,
{ "LSAIdentity", "gsm_map.ms.LSAIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_BasicServiceList_item,
{ "Ext-BasicServiceCode", "gsm_map.ms.Ext_BasicServiceCode",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_o_CSI,
{ "o-CSI", "gsm_map.ms.o_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_CSI,
{ "ss-CSI", "gsm_map.ms.ss_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_o_BcsmCamelTDP_CriteriaList,
{ "o-BcsmCamelTDP-CriteriaList", "gsm_map.ms.o_BcsmCamelTDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
"O_BcsmCamelTDPCriteriaList", HFILL }},
{ &hf_gsm_map_ms_tif_CSI,
{ "tif-CSI", "gsm_map.ms.tif_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_m_CSI,
{ "m-CSI", "gsm_map.ms.m_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vt_CSI,
{ "vt-CSI", "gsm_map.ms.vt_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_CSI", HFILL }},
{ &hf_gsm_map_ms_t_BCSM_CAMEL_TDP_CriteriaList,
{ "t-BCSM-CAMEL-TDP-CriteriaList", "gsm_map.ms.t_BCSM_CAMEL_TDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_d_CSI,
{ "d-CSI", "gsm_map.ms.d_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_MT_smsCAMELTDP_CriteriaList_item,
{ "MT-smsCAMELTDP-Criteria", "gsm_map.ms.MT_smsCAMELTDP_Criteria_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sms_TriggerDetectionPoint,
{ "sms-TriggerDetectionPoint", "gsm_map.ms.sms_TriggerDetectionPoint",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SMS_TriggerDetectionPoint_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_tpdu_TypeCriterion,
{ "tpdu-TypeCriterion", "gsm_map.ms.tpdu_TypeCriterion",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_TPDU_TypeCriterion_item,
{ "MT-SMS-TPDU-Type", "gsm_map.ms.MT_SMS_TPDU_Type",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_MT_SMS_TPDU_Type_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_dp_AnalysedInfoCriteriaList,
{ "dp-AnalysedInfoCriteriaList", "gsm_map.ms.dp_AnalysedInfoCriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_DP_AnalysedInfoCriteriaList_item,
{ "DP-AnalysedInfoCriterium", "gsm_map.ms.DP_AnalysedInfoCriterium_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_dialledNumber,
{ "dialledNumber", "gsm_map.ms.dialledNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_defaultCallHandling,
{ "defaultCallHandling", "gsm_map.ms.defaultCallHandling",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DefaultCallHandling_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_CamelData,
{ "ss-CamelData", "gsm_map.ms.ss_CamelData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ss_EventList,
{ "ss-EventList", "gsm_map.ms.ss_EventList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_SS_EventList_item,
{ "SS-Code", "gsm_map.ms.SS_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_o_BcsmCamelTDPDataList,
{ "o-BcsmCamelTDPDataList", "gsm_map.ms.o_BcsmCamelTDPDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_csiActive,
{ "csiActive", "gsm_map.ms.csiActive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_O_BcsmCamelTDPDataList_item,
{ "O-BcsmCamelTDPData", "gsm_map.ms.O_BcsmCamelTDPData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_o_BcsmTriggerDetectionPoint,
{ "o-BcsmTriggerDetectionPoint", "gsm_map.ms.o_BcsmTriggerDetectionPoint",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_O_BcsmTriggerDetectionPoint_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_O_BcsmCamelTDPCriteriaList_item,
{ "O-BcsmCamelTDP-Criteria", "gsm_map.ms.O_BcsmCamelTDP_Criteria_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_T_BCSM_CAMEL_TDP_CriteriaList_item,
{ "T-BCSM-CAMEL-TDP-Criteria", "gsm_map.ms.T_BCSM_CAMEL_TDP_Criteria_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_destinationNumberCriteria,
{ "destinationNumberCriteria", "gsm_map.ms.destinationNumberCriteria_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_basicServiceCriteria,
{ "basicServiceCriteria", "gsm_map.ms.basicServiceCriteria",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_callTypeCriteria,
{ "callTypeCriteria", "gsm_map.ms.callTypeCriteria",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_CallTypeCriteria_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_o_CauseValueCriteria,
{ "o-CauseValueCriteria", "gsm_map.ms.o_CauseValueCriteria",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_BCSM_TriggerDetectionPoint,
{ "t-BCSM-TriggerDetectionPoint", "gsm_map.ms.t_BCSM_TriggerDetectionPoint",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_T_BcsmTriggerDetectionPoint_vals), 0,
"T_BcsmTriggerDetectionPoint", HFILL }},
{ &hf_gsm_map_ms_t_CauseValueCriteria,
{ "t-CauseValueCriteria", "gsm_map.ms.t_CauseValueCriteria",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_matchType,
{ "matchType", "gsm_map.ms.matchType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_MatchType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_destinationNumberList,
{ "destinationNumberList", "gsm_map.ms.destinationNumberList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_destinationNumberLengthList,
{ "destinationNumberLengthList", "gsm_map.ms.destinationNumberLengthList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_DestinationNumberList_item,
{ "ISDN-AddressString", "gsm_map.ms.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_DestinationNumberLengthList_item,
{ "DestinationNumberLengthList item", "gsm_map.ms.DestinationNumberLengthList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_maxNumOfISDN_AddressDigits", HFILL }},
{ &hf_gsm_map_ms_BasicServiceCriteria_item,
{ "Ext-BasicServiceCode", "gsm_map.ms.Ext_BasicServiceCode",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_O_CauseValueCriteria_item,
{ "CauseValue", "gsm_map.ms.CauseValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_T_CauseValueCriteria_item,
{ "CauseValue", "gsm_map.ms.CauseValue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sms_CAMEL_TDP_DataList,
{ "sms-CAMEL-TDP-DataList", "gsm_map.ms.sms_CAMEL_TDP_DataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_SMS_CAMEL_TDP_DataList_item,
{ "SMS-CAMEL-TDP-Data", "gsm_map.ms.SMS_CAMEL_TDP_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_defaultSMS_Handling,
{ "defaultSMS-Handling", "gsm_map.ms.defaultSMS_Handling",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DefaultSMS_Handling_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mobilityTriggers,
{ "mobilityTriggers", "gsm_map.ms.mobilityTriggers",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_MobilityTriggers_item,
{ "MM-Code", "gsm_map.ms.MM_Code",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_BcsmCamelTDPDataList,
{ "t-BcsmCamelTDPDataList", "gsm_map.ms.t_BcsmCamelTDPDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_T_BcsmCamelTDPDataList_item,
{ "T-BcsmCamelTDPData", "gsm_map.ms.T_BcsmCamelTDPData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_BcsmTriggerDetectionPoint,
{ "t-BcsmTriggerDetectionPoint", "gsm_map.ms.t_BcsmTriggerDetectionPoint",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_T_BcsmTriggerDetectionPoint_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ggsn_Address,
{ "ggsn-Address", "gsm_map.ms.ggsn_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_ms_ggsn_Number,
{ "ggsn-Number", "gsm_map.ms.ggsn_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_mobileNotReachableReason,
{ "mobileNotReachableReason", "gsm_map.ms.mobileNotReachableReason",
FT_UINT32, BASE_DEC, NULL, 0,
"AbsentSubscriberDiagnosticSM", HFILL }},
{ &hf_gsm_map_ms_sendingNodenumber,
{ "sendingNodenumber", "gsm_map.ms.sendingNodenumber",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SendingNode_Number_vals), 0,
"SendingNode_Number", HFILL }},
{ &hf_gsm_map_ms_hlr_List,
{ "hlr-List", "gsm_map.ms.hlr_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_css_Number,
{ "css-Number", "gsm_map.ms.css_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_msNotReachable,
{ "msNotReachable", "gsm_map.ms.msNotReachable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_VBSDataList_item,
{ "VoiceBroadcastData", "gsm_map.ms.VoiceBroadcastData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_VGCSDataList_item,
{ "VoiceGroupCallData", "gsm_map.ms.VoiceGroupCallData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_groupId,
{ "groupId", "gsm_map.ms.groupId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_additionalSubscriptions,
{ "additionalSubscriptions", "gsm_map.ms.additionalSubscriptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_additionalInfo,
{ "additionalInfo", "gsm_map.ms.additionalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_longGroupId,
{ "longGroupId", "gsm_map.ms.longGroupId",
FT_BYTES, BASE_NONE, NULL, 0,
"Long_GroupId", HFILL }},
{ &hf_gsm_map_ms_groupid,
{ "groupid", "gsm_map.ms.groupid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_broadcastInitEntitlement,
{ "broadcastInitEntitlement", "gsm_map.ms.broadcastInitEntitlement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedInfo,
{ "requestedInfo", "gsm_map.ms.requestedInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_callPriority,
{ "callPriority", "gsm_map.ms.callPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_ms_subscriberInfo,
{ "subscriberInfo", "gsm_map.ms.subscriberInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscriberState,
{ "subscriberState", "gsm_map.ms.subscriberState",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_SubscriberState_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_SubscriberState,
{ "ps-SubscriberState", "gsm_map.ms.ps_SubscriberState",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_PS_SubscriberState_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ms_Classmark2,
{ "ms-Classmark2", "gsm_map.ms.ms_Classmark2",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprs_MS_Class,
{ "gprs-MS-Class", "gsm_map.ms.gprs_MS_Class_element",
FT_NONE, BASE_NONE, NULL, 0,
"GPRSMSClass", HFILL }},
{ &hf_gsm_map_ms_mnpInfoRes,
{ "mnpInfoRes", "gsm_map.ms.mnpInfoRes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_imsVoiceOverPS_SessionsIndication,
{ "imsVoiceOverPS-SessionsIndication", "gsm_map.ms.imsVoiceOverPS_SessionsIndication",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_IMS_VoiceOverPS_SessionsInd_vals), 0,
"IMS_VoiceOverPS_SessionsInd", HFILL }},
{ &hf_gsm_map_ms_lastUE_ActivityTime,
{ "lastUE-ActivityTime", "gsm_map.ms.lastUE_ActivityTime",
FT_BYTES, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_gsm_map_ms_lastRAT_Type,
{ "lastRAT-Type", "gsm_map.ms.lastRAT_Type",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_Used_RAT_Type_vals), 0,
"Used_RAT_Type", HFILL }},
{ &hf_gsm_map_ms_eps_SubscriberState,
{ "eps-SubscriberState", "gsm_map.ms.eps_SubscriberState",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_PS_SubscriberState_vals), 0,
"PS_SubscriberState", HFILL }},
{ &hf_gsm_map_ms_timeZone,
{ "timeZone", "gsm_map.ms.timeZone",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_daylightSavingTime,
{ "daylightSavingTime", "gsm_map.ms.daylightSavingTime",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DaylightSavingTime_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_routeingNumber,
{ "routeingNumber", "gsm_map.ms.routeingNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_numberPortabilityStatus,
{ "numberPortabilityStatus", "gsm_map.ms.numberPortabilityStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NumberPortabilityStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mSNetworkCapability,
{ "mSNetworkCapability", "gsm_map.ms.mSNetworkCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mSRadioAccessCapability,
{ "mSRadioAccessCapability", "gsm_map.ms.mSRadioAccessCapability",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_locationInformation_01,
{ "locationInformation", "gsm_map.ms.locationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscriberState_01,
{ "subscriberState", "gsm_map.ms.subscriberState_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_currentLocation,
{ "currentLocation", "gsm_map.ms.currentLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedDomain,
{ "requestedDomain", "gsm_map.ms.requestedDomain",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_DomainType_vals), 0,
"DomainType", HFILL }},
{ &hf_gsm_map_ms_imei_01,
{ "imei", "gsm_map.ms.imei_null_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ms_classmark,
{ "ms-classmark", "gsm_map.ms.ms_classmark_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mnpRequestedInfo,
{ "mnpRequestedInfo", "gsm_map.ms.mnpRequestedInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_locationInformationEPS_Supported,
{ "locationInformationEPS-Supported", "gsm_map.ms.locationInformationEPS_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_adsData,
{ "t-adsData", "gsm_map.ms.t_adsData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedNodes,
{ "requestedNodes", "gsm_map.ms.requestedNodes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_servingNodeIndication,
{ "servingNodeIndication", "gsm_map.ms.servingNodeIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_localTimeZoneRequest,
{ "localTimeZoneRequest", "gsm_map.ms.localTimeZoneRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ageOfLocationInformation,
{ "ageOfLocationInformation", "gsm_map.ms.ageOfLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_geographicalInformation,
{ "geographicalInformation", "gsm_map.ms.geographicalInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vlr_number,
{ "vlr-number", "gsm_map.ms.vlr_number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_locationNumber,
{ "locationNumber", "gsm_map.ms.locationNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cellGlobalIdOrServiceAreaIdOrLAI,
{ "cellGlobalIdOrServiceAreaIdOrLAI", "gsm_map.ms.cellGlobalIdOrServiceAreaIdOrLAI",
FT_UINT32, BASE_DEC, VALS(gsm_map_CellGlobalIdOrServiceAreaIdOrLAI_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_selectedLSA_Id,
{ "selectedLSA-Id", "gsm_map.ms.selectedLSA_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"LSAIdentity", HFILL }},
{ &hf_gsm_map_ms_geodeticInformation,
{ "geodeticInformation", "gsm_map.ms.geodeticInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_currentLocationRetrieved,
{ "currentLocationRetrieved", "gsm_map.ms.currentLocationRetrieved_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sai_Present,
{ "sai-Present", "gsm_map.ms.sai_Present_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_userCSGInformation,
{ "userCSGInformation", "gsm_map.ms.userCSGInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_e_utranCellGlobalIdentity,
{ "e-utranCellGlobalIdentity", "gsm_map.ms.e_utranCellGlobalIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"E_UTRAN_CGI", HFILL }},
{ &hf_gsm_map_ms_trackingAreaIdentity,
{ "trackingAreaIdentity", "gsm_map.ms.trackingAreaIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"TA_Id", HFILL }},
{ &hf_gsm_map_ms_mme_Name,
{ "mme-Name", "gsm_map.ms.mme_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_ms_routeingAreaIdentity,
{ "routeingAreaIdentity", "gsm_map.ms.routeingAreaIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"RAIdentity", HFILL }},
{ &hf_gsm_map_ms_selectedLSAIdentity,
{ "selectedLSAIdentity", "gsm_map.ms.selectedLSAIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"LSAIdentity", HFILL }},
{ &hf_gsm_map_ms_accessMode,
{ "accessMode", "gsm_map.ms.accessMode",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_gsm_map_ms_cmi,
{ "cmi", "gsm_map.ms.cmi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_gsm_map_ms_assumedIdle,
{ "assumedIdle", "gsm_map.ms.assumedIdle_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_camelBusy,
{ "camelBusy", "gsm_map.ms.camelBusy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_netDetNotReachable,
{ "netDetNotReachable", "gsm_map.ms.netDetNotReachable",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NotReachableReason_vals), 0,
"NotReachableReason", HFILL }},
{ &hf_gsm_map_ms_notProvidedFromVLR,
{ "notProvidedFromVLR", "gsm_map.ms.notProvidedFromVLR_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_notProvidedFromSGSNorMME,
{ "notProvidedFromSGSNorMME", "gsm_map.ms.notProvidedFromSGSNorMME_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_Detached,
{ "ps-Detached", "gsm_map.ms.ps_Detached_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_AttachedNotReachableForPaging,
{ "ps-AttachedNotReachableForPaging", "gsm_map.ms.ps_AttachedNotReachableForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_AttachedReachableForPaging,
{ "ps-AttachedReachableForPaging", "gsm_map.ms.ps_AttachedReachableForPaging_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ps_PDP_ActiveNotReachableForPaging,
{ "ps-PDP-ActiveNotReachableForPaging", "gsm_map.ms.ps_PDP_ActiveNotReachableForPaging",
FT_UINT32, BASE_DEC, NULL, 0,
"PDP_ContextInfoList", HFILL }},
{ &hf_gsm_map_ms_ps_PDP_ActiveReachableForPaging,
{ "ps-PDP-ActiveReachableForPaging", "gsm_map.ms.ps_PDP_ActiveReachableForPaging",
FT_UINT32, BASE_DEC, NULL, 0,
"PDP_ContextInfoList", HFILL }},
{ &hf_gsm_map_ms_PDP_ContextInfoList_item,
{ "PDP-ContextInfo", "gsm_map.ms.PDP_ContextInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_pdp_ContextIdentifier,
{ "pdp-ContextIdentifier", "gsm_map.ms.pdp_ContextIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
"ContextId", HFILL }},
{ &hf_gsm_map_ms_pdp_ContextActive,
{ "pdp-ContextActive", "gsm_map.ms.pdp_ContextActive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_apn_Subscribed,
{ "apn-Subscribed", "gsm_map.ms.apn_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
"APN", HFILL }},
{ &hf_gsm_map_ms_apn_InUse,
{ "apn-InUse", "gsm_map.ms.apn_InUse",
FT_BYTES, BASE_NONE, NULL, 0,
"APN", HFILL }},
{ &hf_gsm_map_ms_nsapi,
{ "nsapi", "gsm_map.ms.nsapi",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_transactionId,
{ "transactionId", "gsm_map.ms.transactionId",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_teid_ForGnAndGp,
{ "teid-ForGnAndGp", "gsm_map.ms.teid_ForGnAndGp",
FT_BYTES, BASE_NONE, NULL, 0,
"TEID", HFILL }},
{ &hf_gsm_map_ms_teid_ForIu,
{ "teid-ForIu", "gsm_map.ms.teid_ForIu",
FT_BYTES, BASE_NONE, NULL, 0,
"TEID", HFILL }},
{ &hf_gsm_map_ms_qos_Subscribed_01,
{ "qos-Subscribed", "gsm_map.ms.qos_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos_Requested,
{ "qos-Requested", "gsm_map.ms.qos_Requested",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos_Negotiated,
{ "qos-Negotiated", "gsm_map.ms.qos_Negotiated",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_chargingId,
{ "chargingId", "gsm_map.ms.chargingId",
FT_BYTES, BASE_NONE, NULL, 0,
"GPRSChargingID", HFILL }},
{ &hf_gsm_map_ms_rnc_Address,
{ "rnc-Address", "gsm_map.ms.rnc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_ms_qos2_Subscribed,
{ "qos2-Subscribed", "gsm_map.ms.qos2_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext2_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos2_Requested,
{ "qos2-Requested", "gsm_map.ms.qos2_Requested",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext2_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos2_Negotiated,
{ "qos2-Negotiated", "gsm_map.ms.qos2_Negotiated",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext2_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos3_Subscribed,
{ "qos3-Subscribed", "gsm_map.ms.qos3_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext3_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos3_Requested,
{ "qos3-Requested", "gsm_map.ms.qos3_Requested",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext3_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos3_Negotiated,
{ "qos3-Negotiated", "gsm_map.ms.qos3_Negotiated",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext3_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos4_Subscribed,
{ "qos4-Subscribed", "gsm_map.ms.qos4_Subscribed",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext4_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos4_Requested,
{ "qos4-Requested", "gsm_map.ms.qos4_Requested",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext4_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_qos4_Negotiated,
{ "qos4-Negotiated", "gsm_map.ms.qos4_Negotiated",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext4_QoS_Subscribed", HFILL }},
{ &hf_gsm_map_ms_subscriberIdentity,
{ "subscriberIdentity", "gsm_map.ms.subscriberIdentity",
FT_UINT32, BASE_DEC, VALS(gsm_map_SubscriberIdentity_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedSubscriptionInfo,
{ "requestedSubscriptionInfo", "gsm_map.ms.requestedSubscriptionInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_callForwardingData,
{ "callForwardingData", "gsm_map.ms.callForwardingData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_callBarringData,
{ "callBarringData", "gsm_map.ms.callBarringData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_odb_Info,
{ "odb-Info", "gsm_map.ms.odb_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_camel_SubscriptionInfo,
{ "camel-SubscriptionInfo", "gsm_map.ms.camel_SubscriptionInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedVLR_CAMEL_Phases,
{ "supportedVLR-CAMEL-Phases", "gsm_map.ms.supportedVLR_CAMEL_Phases",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedCamelPhases", HFILL }},
{ &hf_gsm_map_ms_supportedSGSN_CAMEL_Phases,
{ "supportedSGSN-CAMEL-Phases", "gsm_map.ms.supportedSGSN_CAMEL_Phases",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedCamelPhases", HFILL }},
{ &hf_gsm_map_ms_offeredCamel4CSIsInVLR,
{ "offeredCamel4CSIsInVLR", "gsm_map.ms.offeredCamel4CSIsInVLR",
FT_BYTES, BASE_NONE, NULL, 0,
"OfferedCamel4CSIs", HFILL }},
{ &hf_gsm_map_ms_offeredCamel4CSIsInSGSN,
{ "offeredCamel4CSIsInSGSN", "gsm_map.ms.offeredCamel4CSIsInSGSN",
FT_BYTES, BASE_NONE, NULL, 0,
"OfferedCamel4CSIs", HFILL }},
{ &hf_gsm_map_ms_msisdn_BS_List,
{ "msisdn-BS-List", "gsm_map.ms.msisdn_BS_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cw_Data,
{ "cw-Data", "gsm_map.ms.cw_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallWaitingData", HFILL }},
{ &hf_gsm_map_ms_ch_Data,
{ "ch-Data", "gsm_map.ms.ch_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"CallHoldData", HFILL }},
{ &hf_gsm_map_ms_clip_Data,
{ "clip-Data", "gsm_map.ms.clip_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ClipData", HFILL }},
{ &hf_gsm_map_ms_clir_Data,
{ "clir-Data", "gsm_map.ms.clir_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ClirData", HFILL }},
{ &hf_gsm_map_ms_ect_data,
{ "ect-data", "gsm_map.ms.ect_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"EctData", HFILL }},
{ &hf_gsm_map_ms_cwFeatureList,
{ "cwFeatureList", "gsm_map.ms.cwFeatureList",
FT_UINT32, BASE_DEC, NULL, 0,
"Ext_CwFeatureList", HFILL }},
{ &hf_gsm_map_ms_Ext_CwFeatureList_item,
{ "Ext-CwFeature", "gsm_map.ms.Ext_CwFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_overrideCategory,
{ "overrideCategory", "gsm_map.ms.overrideCategory",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_OverrideCategory_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cliRestrictionOption,
{ "cliRestrictionOption", "gsm_map.ms.cliRestrictionOption",
FT_UINT32, BASE_DEC, VALS(gsm_map_ss_CliRestrictionOption_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedSS_Info,
{ "requestedSS-Info", "gsm_map.ms.requestedSS_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
"SS_ForBS_Code", HFILL }},
{ &hf_gsm_map_ms_odb,
{ "odb", "gsm_map.ms.odb_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedCAMEL_SubscriptionInfo,
{ "requestedCAMEL-SubscriptionInfo", "gsm_map.ms.requestedCAMEL_SubscriptionInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_RequestedCAMEL_SubscriptionInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedVLR_CAMEL_Phases_01,
{ "supportedVLR-CAMEL-Phases", "gsm_map.ms.supportedVLR_CAMEL_Phases_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_supportedSGSN_CAMEL_Phases_01,
{ "supportedSGSN-CAMEL-Phases", "gsm_map.ms.supportedSGSN_CAMEL_Phases_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_additionalRequestedCAMEL_SubscriptionInfo,
{ "additionalRequestedCAMEL-SubscriptionInfo", "gsm_map.ms.additionalRequestedCAMEL_SubscriptionInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_AdditionalRequestedCAMEL_SubscriptionInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_msisdn_BS_List_01,
{ "msisdn-BS-List", "gsm_map.ms.msisdn_BS_List_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_csg_SubscriptionDataRequested,
{ "csg-SubscriptionDataRequested", "gsm_map.ms.csg_SubscriptionDataRequested_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cw_Info,
{ "cw-Info", "gsm_map.ms.cw_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_clip_Info,
{ "clip-Info", "gsm_map.ms.clip_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_clir_Info,
{ "clir-Info", "gsm_map.ms.clir_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_hold_Info,
{ "hold-Info", "gsm_map.ms.hold_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ect_Info,
{ "ect-Info", "gsm_map.ms.ect_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_MSISDN_BS_List_item,
{ "MSISDN-BS", "gsm_map.ms.MSISDN_BS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_password,
{ "password", "gsm_map.ms.password",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_wrongPasswordAttemptsCounter,
{ "wrongPasswordAttemptsCounter", "gsm_map.ms.wrongPasswordAttemptsCounter",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_t_CSI,
{ "t-CSI", "gsm_map.ms.t_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vt_BCSM_CAMEL_TDP_CriteriaList,
{ "vt-BCSM-CAMEL-TDP-CriteriaList", "gsm_map.ms.vt_BCSM_CAMEL_TDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
"T_BCSM_CAMEL_TDP_CriteriaList", HFILL }},
{ &hf_gsm_map_ms_tif_CSI_NotificationToCSE,
{ "tif-CSI-NotificationToCSE", "gsm_map.ms.tif_CSI_NotificationToCSE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_specificCSIDeletedList,
{ "specificCSIDeletedList", "gsm_map.ms.specificCSIDeletedList",
FT_BYTES, BASE_NONE, NULL, 0,
"SpecificCSI_Withdraw", HFILL }},
{ &hf_gsm_map_ms_o_IM_CSI,
{ "o-IM-CSI", "gsm_map.ms.o_IM_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"O_CSI", HFILL }},
{ &hf_gsm_map_ms_o_IM_BcsmCamelTDP_CriteriaList,
{ "o-IM-BcsmCamelTDP-CriteriaList", "gsm_map.ms.o_IM_BcsmCamelTDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
"O_BcsmCamelTDPCriteriaList", HFILL }},
{ &hf_gsm_map_ms_d_IM_CSI,
{ "d-IM-CSI", "gsm_map.ms.d_IM_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_CSI", HFILL }},
{ &hf_gsm_map_ms_vt_IM_CSI,
{ "vt-IM-CSI", "gsm_map.ms.vt_IM_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_CSI", HFILL }},
{ &hf_gsm_map_ms_vt_IM_BCSM_CAMEL_TDP_CriteriaList,
{ "vt-IM-BCSM-CAMEL-TDP-CriteriaList", "gsm_map.ms.vt_IM_BCSM_CAMEL_TDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
"T_BCSM_CAMEL_TDP_CriteriaList", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CF_Info,
{ "modificationRequestFor-CF-Info", "gsm_map.ms.modificationRequestFor_CF_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CB_Info,
{ "modificationRequestFor-CB-Info", "gsm_map.ms.modificationRequestFor_CB_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CSI,
{ "modificationRequestFor-CSI", "gsm_map.ms.modificationRequestFor_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_ODB_data,
{ "modificationRequestFor-ODB-data", "gsm_map.ms.modificationRequestFor_ODB_data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_IP_SM_GW_Data,
{ "modificationRequestFor-IP-SM-GW-Data", "gsm_map.ms.modificationRequestFor_IP_SM_GW_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_activationRequestForUE_reachability,
{ "activationRequestForUE-reachability", "gsm_map.ms.activationRequestForUE_reachability",
FT_BYTES, BASE_NONE, NULL, 0,
"RequestedServingNode", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CSG,
{ "modificationRequestFor-CSG", "gsm_map.ms.modificationRequestFor_CSG_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CW_Data,
{ "modificationRequestFor-CW-Data", "gsm_map.ms.modificationRequestFor_CW_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModificationRequestFor_CW_Info", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CLIP_Data,
{ "modificationRequestFor-CLIP-Data", "gsm_map.ms.modificationRequestFor_CLIP_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModificationRequestFor_CLIP_Info", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_CLIR_Data,
{ "modificationRequestFor-CLIR-Data", "gsm_map.ms.modificationRequestFor_CLIR_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModificationRequestFor_CLIR_Info", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_HOLD_Data,
{ "modificationRequestFor-HOLD-Data", "gsm_map.ms.modificationRequestFor_HOLD_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModificationRequestFor_CH_Info", HFILL }},
{ &hf_gsm_map_ms_modificationRequestFor_ECT_Data,
{ "modificationRequestFor-ECT-Data", "gsm_map.ms.modificationRequestFor_ECT_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
"ModificationRequestFor_ECT_Info", HFILL }},
{ &hf_gsm_map_ms_modifyNotificationToCSE,
{ "modifyNotificationToCSE", "gsm_map.ms.modifyNotificationToCSE",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_ModificationInstruction_vals), 0,
"ModificationInstruction", HFILL }},
{ &hf_gsm_map_ms_ss_InfoFor_CSE,
{ "ss-InfoFor-CSE", "gsm_map.ms.ss_InfoFor_CSE",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_Ext_SS_InfoFor_CSE_vals), 0,
"Ext_SS_InfoFor_CSE", HFILL }},
{ &hf_gsm_map_ms_serviceCentreAddress,
{ "serviceCentreAddress", "gsm_map.ms.serviceCentreAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_ms_forwardedToNumber_01,
{ "forwardedToNumber", "gsm_map.ms.forwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_ms_odb_data,
{ "odb-data", "gsm_map.ms.odb_data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_requestedCamel_SubscriptionInfo,
{ "requestedCamel-SubscriptionInfo", "gsm_map.ms.requestedCamel_SubscriptionInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_RequestedCAMEL_SubscriptionInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_modifyCSI_State,
{ "modifyCSI-State", "gsm_map.ms.modifyCSI_State",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_ModificationInstruction_vals), 0,
"ModificationInstruction", HFILL }},
{ &hf_gsm_map_ms_modifyRegistrationStatus,
{ "modifyRegistrationStatus", "gsm_map.ms.modifyRegistrationStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_ModificationInstruction_vals), 0,
"ModificationInstruction", HFILL }},
{ &hf_gsm_map_ms_ip_sm_gw_DiameterAddress,
{ "ip-sm-gw-DiameterAddress", "gsm_map.ms.ip_sm_gw_DiameterAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"NetworkNodeDiameterAddress", HFILL }},
{ &hf_gsm_map_ms_forwardingInfoFor_CSE,
{ "forwardingInfoFor-CSE", "gsm_map.ms.forwardingInfoFor_CSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_ForwardingInfoFor_CSE", HFILL }},
{ &hf_gsm_map_ms_callBarringInfoFor_CSE,
{ "callBarringInfoFor-CSE", "gsm_map.ms.callBarringInfoFor_CSE_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_CallBarringInfoFor_CSE", HFILL }},
{ &hf_gsm_map_ms_allInformationSent,
{ "allInformationSent", "gsm_map.ms.allInformationSent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ue_reachable,
{ "ue-reachable", "gsm_map.ms.ue_reachable",
FT_BYTES, BASE_NONE, NULL, 0,
"ServingNode", HFILL }},
{ &hf_gsm_map_ms_eventMet,
{ "eventMet", "gsm_map.ms.eventMet",
FT_BYTES, BASE_NONE, NULL, 0,
"MM_Code", HFILL }},
{ &hf_gsm_map_ms_supportedCAMELPhases,
{ "supportedCAMELPhases", "gsm_map.ms.supportedCAMELPhases",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_offeredCamel4Functionalities,
{ "offeredCamel4Functionalities", "gsm_map.ms.offeredCamel4Functionalities",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_temporaryEmptySubscriptiondataIndicator,
{ "temporaryEmptySubscriptiondataIndicator", "gsm_map.ms.temporaryEmptySubscriptiondataIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_naea_PreferredCI,
{ "naea-PreferredCI", "gsm_map.ms.naea_PreferredCI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_gprsSubscriptionData,
{ "gprsSubscriptionData", "gsm_map.ms.gprsSubscriptionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_roamingRestrictedInSgsnDueToUnsupportedFeature,
{ "roamingRestrictedInSgsnDueToUnsupportedFeature", "gsm_map.ms.roamingRestrictedInSgsnDueToUnsupportedFeature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_networkAccessMode,
{ "networkAccessMode", "gsm_map.ms.networkAccessMode",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NetworkAccessMode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lsaInformation,
{ "lsaInformation", "gsm_map.ms.lsaInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lmu_Indicator,
{ "lmu-Indicator", "gsm_map.ms.lmu_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_lcsInformation,
{ "lcsInformation", "gsm_map.ms.lcsInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_istAlertTimer,
{ "istAlertTimer", "gsm_map.ms.istAlertTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"IST_AlertTimerValue", HFILL }},
{ &hf_gsm_map_ms_superChargerSupportedInHLR,
{ "superChargerSupportedInHLR", "gsm_map.ms.superChargerSupportedInHLR",
FT_BYTES, BASE_NONE, NULL, 0,
"AgeIndicator", HFILL }},
{ &hf_gsm_map_ms_mc_SS_Info,
{ "mc-SS-Info", "gsm_map.ms.mc_SS_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_cs_AllocationRetentionPriority,
{ "cs-AllocationRetentionPriority", "gsm_map.ms.cs_AllocationRetentionPriority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_sgsn_CAMEL_SubscriptionInfo,
{ "sgsn-CAMEL-SubscriptionInfo", "gsm_map.ms.sgsn_CAMEL_SubscriptionInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_accessRestrictionData,
{ "accessRestrictionData", "gsm_map.ms.accessRestrictionData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ics_Indicator,
{ "ics-Indicator", "gsm_map.ms.ics_Indicator",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_eps_SubscriptionData,
{ "eps-SubscriptionData", "gsm_map.ms.eps_SubscriptionData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_ue_ReachabilityRequestIndicator,
{ "ue-ReachabilityRequestIndicator", "gsm_map.ms.ue_ReachabilityRequestIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_subscribedPeriodicRAUTAUtimer,
{ "subscribedPeriodicRAUTAUtimer", "gsm_map.ms.subscribedPeriodicRAUTAUtimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vplmnLIPAAllowed,
{ "vplmnLIPAAllowed", "gsm_map.ms.vplmnLIPAAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_mdtUserConsent,
{ "mdtUserConsent", "gsm_map.ms.mdtUserConsent",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_map_ms_subscribedPeriodicLAUtimer,
{ "subscribedPeriodicLAUtimer", "gsm_map.ms.subscribedPeriodicLAUtimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_vplmn_Csg_SubscriptionDataList,
{ "vplmn-Csg-SubscriptionDataList", "gsm_map.ms.vplmn_Csg_SubscriptionDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_additionalMSISDN,
{ "additionalMSISDN", "gsm_map.ms.additionalMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ms_psAndSMS_OnlyServiceProvision,
{ "psAndSMS-OnlyServiceProvision", "gsm_map.ms.psAndSMS_OnlyServiceProvision_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_smsInSGSNAllowed,
{ "smsInSGSNAllowed", "gsm_map.ms.smsInSGSNAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedRAT_Types_utran,
{ "utran", "gsm_map.ms.utran",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedRAT_Types_geran,
{ "geran", "gsm_map.ms.geran",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedRAT_Types_gan,
{ "gan", "gsm_map.ms.gan",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedRAT_Types_i_hspa_evolution,
{ "i-hspa-evolution", "gsm_map.ms.i-hspa-evolution",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedRAT_Types_e_utran,
{ "e-utran", "gsm_map.ms.e-utran",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedLCS_CapabilitySets_lcsCapabilitySet1,
{ "lcsCapabilitySet1", "gsm_map.ms.lcsCapabilitySet1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedLCS_CapabilitySets_lcsCapabilitySet2,
{ "lcsCapabilitySet2", "gsm_map.ms.lcsCapabilitySet2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedLCS_CapabilitySets_lcsCapabilitySet3,
{ "lcsCapabilitySet3", "gsm_map.ms.lcsCapabilitySet3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedLCS_CapabilitySets_lcsCapabilitySet4,
{ "lcsCapabilitySet4", "gsm_map.ms.lcsCapabilitySet4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedLCS_CapabilitySets_lcsCapabilitySet5,
{ "lcsCapabilitySet5", "gsm_map.ms.lcsCapabilitySet5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_ISR_Information_updateLocation,
{ "updateLocation", "gsm_map.ms.updateLocation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ISR_Information_cancelSGSN,
{ "cancelSGSN", "gsm_map.ms.cancelSGSN",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ISR_Information_initialAttachIndicator,
{ "initialAttachIndicator", "gsm_map.ms.initialAttachIndicator",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_apn,
{ "odb-all-apn", "gsm_map.ms.odb-all-apn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_HPLMN_APN,
{ "odb-HPLMN-APN", "gsm_map.ms.odb-HPLMN-APN",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_VPLMN_APN,
{ "odb-VPLMN-APN", "gsm_map.ms.odb-VPLMN-APN",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_og,
{ "odb-all-og", "gsm_map.ms.odb-all-og",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_international_og,
{ "odb-all-international-og", "gsm_map.ms.odb-all-international-og",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_int_og_not_to_HPLMN_country,
{ "odb-all-int-og-not-to-HPLMN-country", "gsm_map.ms.odb-all-int-og-not-to-HPLMN-country",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_interzonal_og,
{ "odb-all-interzonal-og", "gsm_map.ms.odb-all-interzonal-og",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_interzonal_og_not_to_HPLMN_country,
{ "odb-all-interzonal-og-not-to-HPLMN-country", "gsm_map.ms.odb-all-interzonal-og-not-to-HPLMN-country",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_odb_all_interzonal_og_and_internat_og_not_to_HPLMN_country,
{ "odb-all-interzonal-og-and-internat-og-not-to-HPLMN-country", "gsm_map.ms.odb-all-interzonal-og-and-internat-og-not-to-HPLMN-country",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_regSub,
{ "regSub", "gsm_map.ms.regSub",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_trace,
{ "trace", "gsm_map.ms.trace",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_all_PrivExcep,
{ "lcs-all-PrivExcep", "gsm_map.ms.lcs-all-PrivExcep",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_universal,
{ "lcs-universal", "gsm_map.ms.lcs-universal",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_CallSessionRelated,
{ "lcs-CallSessionRelated", "gsm_map.ms.lcs-CallSessionRelated",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_CallSessionUnrelated,
{ "lcs-CallSessionUnrelated", "gsm_map.ms.lcs-CallSessionUnrelated",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_PLMN_operator,
{ "lcs-PLMN-operator", "gsm_map.ms.lcs-PLMN-operator",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_ServiceType,
{ "lcs-ServiceType", "gsm_map.ms.lcs-ServiceType",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_all_MOLR_SS,
{ "lcs-all-MOLR-SS", "gsm_map.ms.lcs-all-MOLR-SS",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_basicSelfLocation,
{ "lcs-basicSelfLocation", "gsm_map.ms.lcs-basicSelfLocation",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_autonomousSelfLocation,
{ "lcs-autonomousSelfLocation", "gsm_map.ms.lcs-autonomousSelfLocation",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_lcs_transferToThirdParty,
{ "lcs-transferToThirdParty", "gsm_map.ms.lcs-transferToThirdParty",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_sm_mo_pp,
{ "sm-mo-pp", "gsm_map.ms.sm-mo-pp",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_barring_OutgoingCalls,
{ "barring-OutgoingCalls", "gsm_map.ms.barring-OutgoingCalls",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_baoc,
{ "baoc", "gsm_map.ms.baoc",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_boic,
{ "boic", "gsm_map.ms.boic",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_boicExHC,
{ "boicExHC", "gsm_map.ms.boicExHC",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_localTimeZoneRetrieval,
{ "localTimeZoneRetrieval", "gsm_map.ms.localTimeZoneRetrieval",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_additionalMsisdn,
{ "additionalMsisdn", "gsm_map.ms.additionalMsisdn",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_smsInMME,
{ "smsInMME", "gsm_map.ms.smsInMME",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_smsInSGSN,
{ "smsInSGSN", "gsm_map.ms.smsInSGSN",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_ue_Reachability_Notification,
{ "ue-Reachability-Notification", "gsm_map.ms.ue-Reachability-Notification",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_state_Location_Information_Retrieval,
{ "state-Location-Information-Retrieval", "gsm_map.ms.state-Location-Information-Retrieval",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_partialPurge,
{ "partialPurge", "gsm_map.ms.partialPurge",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedFeatures_gddInSGSN,
{ "gddInSGSN", "gsm_map.ms.gddInSGSN",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_Negotiation_permission_indicator_not_allowed_bit,
{ "permission-indicator-not-allowed-bit", "gsm_map.ms.permission-indicator-not-allowed-bit",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_Negotiation_permission_indicator_spare_bit,
{ "permission-indicator-spare-bit", "gsm_map.ms.permission-indicator-spare-bit",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_ConfigurationPreference_forward_data_sending_indicator,
{ "forward-data-sending-indicator", "gsm_map.ms.forward-data-sending-indicator",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_ConfigurationPreference_backward_data_sending_indicator,
{ "backward-data-sending-indicator", "gsm_map.ms.backward-data-sending-indicator",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_ConfigurationPreference_forward_data_reception_indicator,
{ "forward-data-reception-indicator", "gsm_map.ms.forward-data-reception-indicator",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_LCLS_ConfigurationPreference_backward_data_reception_indicator,
{ "backward-data-reception-indicator", "gsm_map.ms.backward-data-reception-indicator",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_RequestedEquipmentInfo_equipmentStatus,
{ "equipmentStatus", "gsm_map.ms.equipmentStatus",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_RequestedEquipmentInfo_bmuef,
{ "bmuef", "gsm_map.ms.bmuef",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_utranNotAllowed,
{ "utranNotAllowed", "gsm_map.ms.utranNotAllowed",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_geranNotAllowed,
{ "geranNotAllowed", "gsm_map.ms.geranNotAllowed",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_ganNotAllowed,
{ "ganNotAllowed", "gsm_map.ms.ganNotAllowed",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_i_hspa_evolutionNotAllowed,
{ "i-hspa-evolutionNotAllowed", "gsm_map.ms.i-hspa-evolutionNotAllowed",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_e_utranNotAllowed,
{ "e-utranNotAllowed", "gsm_map.ms.e-utranNotAllowed",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_AccessRestrictionData_ho_toNon3GPP_AccessNotAllowed,
{ "ho-toNon3GPP-AccessNotAllowed", "gsm_map.ms.ho-toNon3GPP-AccessNotAllowed",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_allOG_CallsBarred,
{ "allOG-CallsBarred", "gsm_map.ms.allOG-CallsBarred",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_internationalOGCallsBarred,
{ "internationalOGCallsBarred", "gsm_map.ms.internationalOGCallsBarred",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_internationalOGCallsNotToHPLMN_CountryBarred,
{ "internationalOGCallsNotToHPLMN-CountryBarred", "gsm_map.ms.internationalOGCallsNotToHPLMN-CountryBarred",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_interzonalOGCallsBarred,
{ "interzonalOGCallsBarred", "gsm_map.ms.interzonalOGCallsBarred",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_interzonalOGCallsNotToHPLMN_CountryBarred,
{ "interzonalOGCallsNotToHPLMN-CountryBarred", "gsm_map.ms.interzonalOGCallsNotToHPLMN-CountryBarred",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_interzonalOGCallsAndInternationalOGCallsNotToHPLMN_CountryBarred,
{ "interzonalOGCallsAndInternationalOGCallsNotToHPLMN-CountryBarred", "gsm_map.ms.interzonalOGCallsAndInternationalOGCallsNotToHPLMN-CountryBarred",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_premiumRateInformationOGCallsBarred,
{ "premiumRateInformationOGCallsBarred", "gsm_map.ms.premiumRateInformationOGCallsBarred",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_premiumRateEntertainementOGCallsBarred,
{ "premiumRateEntertainementOGCallsBarred", "gsm_map.ms.premiumRateEntertainementOGCallsBarred",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_ss_AccessBarred,
{ "ss-AccessBarred", "gsm_map.ms.ss-AccessBarred",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_allECT_Barred,
{ "allECT-Barred", "gsm_map.ms.allECT-Barred",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_chargeableECT_Barred,
{ "chargeableECT-Barred", "gsm_map.ms.chargeableECT-Barred",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_internationalECT_Barred,
{ "internationalECT-Barred", "gsm_map.ms.internationalECT-Barred",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_interzonalECT_Barred,
{ "interzonalECT-Barred", "gsm_map.ms.interzonalECT-Barred",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_doublyChargeableECT_Barred,
{ "doublyChargeableECT-Barred", "gsm_map.ms.doublyChargeableECT-Barred",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_multipleECT_Barred,
{ "multipleECT-Barred", "gsm_map.ms.multipleECT-Barred",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_allPacketOrientedServicesBarred,
{ "allPacketOrientedServicesBarred", "gsm_map.ms.allPacketOrientedServicesBarred",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamerAccessToHPLMN_AP_Barred,
{ "roamerAccessToHPLMN-AP-Barred", "gsm_map.ms.roamerAccessToHPLMN-AP-Barred",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamerAccessToVPLMN_AP_Barred,
{ "roamerAccessToVPLMN-AP-Barred", "gsm_map.ms.roamerAccessToVPLMN-AP-Barred",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamingOutsidePLMNOG_CallsBarred,
{ "roamingOutsidePLMNOG-CallsBarred", "gsm_map.ms.roamingOutsidePLMNOG-CallsBarred",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_allIC_CallsBarred,
{ "allIC-CallsBarred", "gsm_map.ms.allIC-CallsBarred",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamingOutsidePLMNIC_CallsBarred,
{ "roamingOutsidePLMNIC-CallsBarred", "gsm_map.ms.roamingOutsidePLMNIC-CallsBarred",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamingOutsidePLMNICountryIC_CallsBarred,
{ "roamingOutsidePLMNICountryIC-CallsBarred", "gsm_map.ms.roamingOutsidePLMNICountryIC-CallsBarred",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamingOutsidePLMN_Barred,
{ "roamingOutsidePLMN-Barred", "gsm_map.ms.roamingOutsidePLMN-Barred",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_roamingOutsidePLMN_CountryBarred,
{ "roamingOutsidePLMN-CountryBarred", "gsm_map.ms.roamingOutsidePLMN-CountryBarred",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_registrationAllCF_Barred,
{ "registrationAllCF-Barred", "gsm_map.ms.registrationAllCF-Barred",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_registrationCFNotToHPLMN_Barred,
{ "registrationCFNotToHPLMN-Barred", "gsm_map.ms.registrationCFNotToHPLMN-Barred",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_registrationInterzonalCF_Barred,
{ "registrationInterzonalCF-Barred", "gsm_map.ms.registrationInterzonalCF-Barred",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_registrationInterzonalCFNotToHPLMN_Barred,
{ "registrationInterzonalCFNotToHPLMN-Barred", "gsm_map.ms.registrationInterzonalCFNotToHPLMN-Barred",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_GeneralData_registrationInternationalCF_Barred,
{ "registrationInternationalCF-Barred", "gsm_map.ms.registrationInternationalCF-Barred",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_HPLMN_Data_plmn_SpecificBarringType1,
{ "plmn-SpecificBarringType1", "gsm_map.ms.plmn-SpecificBarringType1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_HPLMN_Data_plmn_SpecificBarringType2,
{ "plmn-SpecificBarringType2", "gsm_map.ms.plmn-SpecificBarringType2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_HPLMN_Data_plmn_SpecificBarringType3,
{ "plmn-SpecificBarringType3", "gsm_map.ms.plmn-SpecificBarringType3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_ODB_HPLMN_Data_plmn_SpecificBarringType4,
{ "plmn-SpecificBarringType4", "gsm_map.ms.plmn-SpecificBarringType4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_o_csi,
{ "o-csi", "gsm_map.ms.o-csi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_ss_csi,
{ "ss-csi", "gsm_map.ms.ss-csi",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_tif_csi,
{ "tif-csi", "gsm_map.ms.tif-csi",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_d_csi,
{ "d-csi", "gsm_map.ms.d-csi",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_vt_csi,
{ "vt-csi", "gsm_map.ms.vt-csi",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_mo_sms_csi,
{ "mo-sms-csi", "gsm_map.ms.mo-sms-csi",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_m_csi,
{ "m-csi", "gsm_map.ms.m-csi",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_gprs_csi,
{ "gprs-csi", "gsm_map.ms.gprs-csi",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_t_csi,
{ "t-csi", "gsm_map.ms.t-csi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_mt_sms_csi,
{ "mt-sms-csi", "gsm_map.ms.mt-sms-csi",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_mg_csi,
{ "mg-csi", "gsm_map.ms.mg-csi",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_o_IM_CSI,
{ "o-IM-CSI", "gsm_map.ms.o-IM-CSI",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_d_IM_CSI,
{ "d-IM-CSI", "gsm_map.ms.d-IM-CSI",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_SpecificCSI_Withdraw_vt_IM_CSI,
{ "vt-IM-CSI", "gsm_map.ms.vt-IM-CSI",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedCamelPhases_phase1,
{ "phase1", "gsm_map.ms.phase1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedCamelPhases_phase2,
{ "phase2", "gsm_map.ms.phase2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedCamelPhases_phase3,
{ "phase3", "gsm_map.ms.phase3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_SupportedCamelPhases_phase4,
{ "phase4", "gsm_map.ms.phase4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_o_csi,
{ "o-csi", "gsm_map.ms.o-csi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_d_csi,
{ "d-csi", "gsm_map.ms.d-csi",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_vt_csi,
{ "vt-csi", "gsm_map.ms.vt-csi",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_t_csi,
{ "t-csi", "gsm_map.ms.t-csi",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_mt_sms_csi,
{ "mt-sms-csi", "gsm_map.ms.mt-sms-csi",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_mg_csi,
{ "mg-csi", "gsm_map.ms.mg-csi",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4CSIs_psi_enhancements,
{ "psi-enhancements", "gsm_map.ms.psi-enhancements",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_initiateCallAttempt,
{ "initiateCallAttempt", "gsm_map.ms.initiateCallAttempt",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_splitLeg,
{ "splitLeg", "gsm_map.ms.splitLeg",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_moveLeg,
{ "moveLeg", "gsm_map.ms.moveLeg",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_disconnectLeg,
{ "disconnectLeg", "gsm_map.ms.disconnectLeg",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_entityReleased,
{ "entityReleased", "gsm_map.ms.entityReleased",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_dfc_WithArgument,
{ "dfc-WithArgument", "gsm_map.ms.dfc-WithArgument",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_playTone,
{ "playTone", "gsm_map.ms.playTone",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_dtmf_MidCall,
{ "dtmf-MidCall", "gsm_map.ms.dtmf-MidCall",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_chargingIndicator,
{ "chargingIndicator", "gsm_map.ms.chargingIndicator",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_alertingDP,
{ "alertingDP", "gsm_map.ms.alertingDP",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_locationAtAlerting,
{ "locationAtAlerting", "gsm_map.ms.locationAtAlerting",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_changeOfPositionDP,
{ "changeOfPositionDP", "gsm_map.ms.changeOfPositionDP",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_or_Interactions,
{ "or-Interactions", "gsm_map.ms.or-Interactions",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_warningToneEnhancements,
{ "warningToneEnhancements", "gsm_map.ms.warningToneEnhancements",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_cf_Enhancements,
{ "cf-Enhancements", "gsm_map.ms.cf-Enhancements",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_subscribedEnhancedDialledServices,
{ "subscribedEnhancedDialledServices", "gsm_map.ms.subscribedEnhancedDialledServices",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_servingNetworkEnhancedDialledServices,
{ "servingNetworkEnhancedDialledServices", "gsm_map.ms.servingNetworkEnhancedDialledServices",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_criteriaForChangeOfPositionDP,
{ "criteriaForChangeOfPositionDP", "gsm_map.ms.criteriaForChangeOfPositionDP",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_serviceChangeDP,
{ "serviceChangeDP", "gsm_map.ms.serviceChangeDP",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_OfferedCamel4Functionalities_collectInformation,
{ "collectInformation", "gsm_map.ms.collectInformation",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_ms_AdditionalSubscriptions_privilegedUplinkRequest,
{ "privilegedUplinkRequest", "gsm_map.ms.privilegedUplinkRequest",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_AdditionalSubscriptions_emergencyUplinkRequest,
{ "emergencyUplinkRequest", "gsm_map.ms.emergencyUplinkRequest",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_AdditionalSubscriptions_emergencyReset,
{ "emergencyReset", "gsm_map.ms.emergencyReset",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_ms_RequestedNodes_mme,
{ "mme", "gsm_map.ms.mme",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_RequestedNodes_sgsn,
{ "sgsn", "gsm_map.ms.sgsn",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ms_RequestedServingNode_mmeAndSgsn,
{ "mmeAndSgsn", "gsm_map.ms.mmeAndSgsn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ServingNode_mme,
{ "mme", "gsm_map.ms.mme",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ms_ServingNode_sgsn,
{ "sgsn", "gsm_map.ms.sgsn",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ch_cug_Interlock,
{ "cug-Interlock", "gsm_map.ch.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_cug_OutgoingAccess,
{ "cug-OutgoingAccess", "gsm_map.ch.cug_OutgoingAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_extensionContainer,
{ "extensionContainer", "gsm_map.ch.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_msisdn,
{ "msisdn", "gsm_map.ch.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_cug_CheckInfo,
{ "cug-CheckInfo", "gsm_map.ch.cug_CheckInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_numberOfForwarding,
{ "numberOfForwarding", "gsm_map.ch.numberOfForwarding",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_interrogationType,
{ "interrogationType", "gsm_map.ch.interrogationType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_InterrogationType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_or_Interrogation,
{ "or-Interrogation", "gsm_map.ch.or_Interrogation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_or_Capability,
{ "or-Capability", "gsm_map.ch.or_Capability",
FT_UINT32, BASE_DEC, NULL, 0,
"OR_Phase", HFILL }},
{ &hf_gsm_map_ch_gmsc_OrGsmSCF_Address,
{ "gmsc-OrGsmSCF-Address", "gsm_map.ch.gmsc_OrGsmSCF_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_callReferenceNumber,
{ "callReferenceNumber", "gsm_map.ch.callReferenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_forwardingReason,
{ "forwardingReason", "gsm_map.ch.forwardingReason",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_ForwardingReason_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_basicServiceGroup,
{ "basicServiceGroup", "gsm_map.ch.basicServiceGroup",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_gsm_map_ch_networkSignalInfo,
{ "networkSignalInfo", "gsm_map.ch.networkSignalInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ch_camelInfo,
{ "camelInfo", "gsm_map.ch.camelInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_suppressionOfAnnouncement,
{ "suppressionOfAnnouncement", "gsm_map.ch.suppressionOfAnnouncement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_alertingPattern,
{ "alertingPattern", "gsm_map.ch.alertingPattern",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_ccbs_Call,
{ "ccbs-Call", "gsm_map.ch.ccbs_Call_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_supportedCCBS_Phase,
{ "supportedCCBS-Phase", "gsm_map.ch.supportedCCBS_Phase",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_additionalSignalInfo,
{ "additionalSignalInfo", "gsm_map.ch.additionalSignalInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ext_ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ch_istSupportIndicator,
{ "istSupportIndicator", "gsm_map.ch.istSupportIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_IST_SupportIndicator_vals), 0,
"IST_SupportIndicator", HFILL }},
{ &hf_gsm_map_ch_pre_pagingSupported,
{ "pre-pagingSupported", "gsm_map.ch.pre_pagingSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callDiversionTreatmentIndicator,
{ "callDiversionTreatmentIndicator", "gsm_map.ch.callDiversionTreatmentIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_longFTN_Supported,
{ "longFTN-Supported", "gsm_map.ch.longFTN_Supported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_suppress_VT_CSI,
{ "suppress-VT-CSI", "gsm_map.ch.suppress_VT_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_suppressIncomingCallBarring,
{ "suppressIncomingCallBarring", "gsm_map.ch.suppressIncomingCallBarring_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_gsmSCF_InitiatedCall,
{ "gsmSCF-InitiatedCall", "gsm_map.ch.gsmSCF_InitiatedCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_basicServiceGroup2,
{ "basicServiceGroup2", "gsm_map.ch.basicServiceGroup2",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_gsm_map_ch_networkSignalInfo2,
{ "networkSignalInfo2", "gsm_map.ch.networkSignalInfo2_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ch_suppressMTSS,
{ "suppressMTSS", "gsm_map.ch.suppressMTSS",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_mtRoamingRetrySupported,
{ "mtRoamingRetrySupported", "gsm_map.ch.mtRoamingRetrySupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callPriority,
{ "callPriority", "gsm_map.ch.callPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_ch_imsi,
{ "imsi", "gsm_map.ch.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_extendedRoutingInfo,
{ "extendedRoutingInfo", "gsm_map.ch.extendedRoutingInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_ExtendedRoutingInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_cugSubscriptionFlag,
{ "cugSubscriptionFlag", "gsm_map.ch.cugSubscriptionFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_subscriberInfo,
{ "subscriberInfo", "gsm_map.ch.subscriberInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_ss_List,
{ "ss-List", "gsm_map.ch.ss_List",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_basicService,
{ "basicService", "gsm_map.ch.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_gsm_map_ch_forwardingInterrogationRequired,
{ "forwardingInterrogationRequired", "gsm_map.ch.forwardingInterrogationRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_vmsc_Address,
{ "vmsc-Address", "gsm_map.ch.vmsc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_naea_PreferredCI,
{ "naea-PreferredCI", "gsm_map.ch.naea_PreferredCI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_ccbs_Indicators,
{ "ccbs-Indicators", "gsm_map.ch.ccbs_Indicators_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_numberPortabilityStatus,
{ "numberPortabilityStatus", "gsm_map.ch.numberPortabilityStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NumberPortabilityStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_istAlertTimer,
{ "istAlertTimer", "gsm_map.ch.istAlertTimer",
FT_UINT32, BASE_DEC, NULL, 0,
"IST_AlertTimerValue", HFILL }},
{ &hf_gsm_map_ch_supportedCamelPhasesInVMSC,
{ "supportedCamelPhasesInVMSC", "gsm_map.ch.supportedCamelPhasesInVMSC",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedCamelPhases", HFILL }},
{ &hf_gsm_map_ch_offeredCamel4CSIsInVMSC,
{ "offeredCamel4CSIsInVMSC", "gsm_map.ch.offeredCamel4CSIsInVMSC",
FT_BYTES, BASE_NONE, NULL, 0,
"OfferedCamel4CSIs", HFILL }},
{ &hf_gsm_map_ch_routingInfo2,
{ "routingInfo2", "gsm_map.ch.routingInfo2",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_RoutingInfo_vals), 0,
"RoutingInfo", HFILL }},
{ &hf_gsm_map_ch_ss_List2,
{ "ss-List2", "gsm_map.ch.ss_List2",
FT_UINT32, BASE_DEC, NULL, 0,
"SS_List", HFILL }},
{ &hf_gsm_map_ch_basicService2,
{ "basicService2", "gsm_map.ch.basicService2",
FT_UINT32, BASE_DEC, VALS(gsm_map_Ext_BasicServiceCode_vals), 0,
"Ext_BasicServiceCode", HFILL }},
{ &hf_gsm_map_ch_allowedServices,
{ "allowedServices", "gsm_map.ch.allowedServices",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_unavailabilityCause,
{ "unavailabilityCause", "gsm_map.ch.unavailabilityCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_UnavailabilityCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_releaseResourcesSupported,
{ "releaseResourcesSupported", "gsm_map.ch.releaseResourcesSupported_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_gsm_BearerCapability,
{ "gsm-BearerCapability", "gsm_map.ch.gsm_BearerCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ch_ccbs_Possible,
{ "ccbs-Possible", "gsm_map.ch.ccbs_Possible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_keepCCBS_CallIndicator,
{ "keepCCBS-CallIndicator", "gsm_map.ch.keepCCBS_CallIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_roamingNumber,
{ "roamingNumber", "gsm_map.ch.roamingNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_forwardingData,
{ "forwardingData", "gsm_map.ch.forwardingData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_forwardedToNumber,
{ "forwardedToNumber", "gsm_map.ch.forwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_forwardedToSubaddress,
{ "forwardedToSubaddress", "gsm_map.ch.forwardedToSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_map_ch_forwardingOptions,
{ "forwardingOptions", "gsm_map.ch.forwardingOptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_longForwardedToNumber,
{ "longForwardedToNumber", "gsm_map.ch.longForwardedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"FTN_AddressString", HFILL }},
{ &hf_gsm_map_ch_msc_Number,
{ "msc-Number", "gsm_map.ch.msc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_lmsi,
{ "lmsi", "gsm_map.ch.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_gmsc_Address,
{ "gmsc-Address", "gsm_map.ch.gmsc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_supportedCamelPhasesInInterrogatingNode,
{ "supportedCamelPhasesInInterrogatingNode", "gsm_map.ch.supportedCamelPhasesInInterrogatingNode",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedCamelPhases", HFILL }},
{ &hf_gsm_map_ch_orNotSupportedInGMSC,
{ "orNotSupportedInGMSC", "gsm_map.ch.orNotSupportedInGMSC_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_offeredCamel4CSIsInInterrogatingNode,
{ "offeredCamel4CSIsInInterrogatingNode", "gsm_map.ch.offeredCamel4CSIsInInterrogatingNode",
FT_BYTES, BASE_NONE, NULL, 0,
"OfferedCamel4CSIs", HFILL }},
{ &hf_gsm_map_ch_pagingArea,
{ "pagingArea", "gsm_map.ch.pagingArea",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_mtrf_Indicator,
{ "mtrf-Indicator", "gsm_map.ch.mtrf_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_oldMSC_Number,
{ "oldMSC-Number", "gsm_map.ch.oldMSC_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_lastUsedLtePLMN_Id,
{ "lastUsedLtePLMN-Id", "gsm_map.ch.lastUsedLtePLMN_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_Id", HFILL }},
{ &hf_gsm_map_ch_o_CSI,
{ "o-CSI", "gsm_map.ch.o_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_uu_Data,
{ "uu-Data", "gsm_map.ch.uu_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_allInformationSent,
{ "allInformationSent", "gsm_map.ch.allInformationSent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_d_csi,
{ "d-csi", "gsm_map.ch.d_csi_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_o_BcsmCamelTDPCriteriaList,
{ "o-BcsmCamelTDPCriteriaList", "gsm_map.ch.o_BcsmCamelTDPCriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_mtRoamingRetry,
{ "mtRoamingRetry", "gsm_map.ch.mtRoamingRetry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_uuIndicator,
{ "uuIndicator", "gsm_map.ch.uuIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_uui,
{ "uui", "gsm_map.ch.uui",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_uusCFInteraction,
{ "uusCFInteraction", "gsm_map.ch.uusCFInteraction_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_supportedCamelPhases,
{ "supportedCamelPhases", "gsm_map.ch.supportedCamelPhases",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_suppress_T_CSI,
{ "suppress-T-CSI", "gsm_map.ch.suppress_T_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_offeredCamel4CSIs,
{ "offeredCamel4CSIs", "gsm_map.ch.offeredCamel4CSIs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_routingInfo,
{ "routingInfo", "gsm_map.ch.routingInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_RoutingInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_camelRoutingInfo,
{ "camelRoutingInfo", "gsm_map.ch.camelRoutingInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_gmscCamelSubscriptionInfo,
{ "gmscCamelSubscriptionInfo", "gsm_map.ch.gmscCamelSubscriptionInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_t_CSI,
{ "t-CSI", "gsm_map.ch.t_CSI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_o_BcsmCamelTDP_CriteriaList,
{ "o-BcsmCamelTDP-CriteriaList", "gsm_map.ch.o_BcsmCamelTDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
"O_BcsmCamelTDPCriteriaList", HFILL }},
{ &hf_gsm_map_ch_t_BCSM_CAMEL_TDP_CriteriaList,
{ "t-BCSM-CAMEL-TDP-CriteriaList", "gsm_map.ch.t_BCSM_CAMEL_TDP_CriteriaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_ccbs_Monitoring,
{ "ccbs-Monitoring", "gsm_map.ch.ccbs_Monitoring",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_ReportingState_vals), 0,
"ReportingState", HFILL }},
{ &hf_gsm_map_ch_ccbs_SubscriberStatus,
{ "ccbs-SubscriberStatus", "gsm_map.ch.ccbs_SubscriberStatus",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_CCBS_SubscriberStatus_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_eventReportData,
{ "eventReportData", "gsm_map.ch.eventReportData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callReportdata,
{ "callReportdata", "gsm_map.ch.callReportdata_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_monitoringMode,
{ "monitoringMode", "gsm_map.ch.monitoringMode",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_MonitoringMode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callOutcome,
{ "callOutcome", "gsm_map.ch.callOutcome",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_CallOutcome_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callInfo,
{ "callInfo", "gsm_map.ch.callInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_map_ch_ccbs_Feature,
{ "ccbs-Feature", "gsm_map.ch.ccbs_Feature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_translatedB_Number,
{ "translatedB-Number", "gsm_map.ch.translatedB_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_replaceB_Number,
{ "replaceB-Number", "gsm_map.ch.replaceB_Number_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_ruf_Outcome,
{ "ruf-Outcome", "gsm_map.ch.ruf_Outcome",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_RUF_Outcome_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_istInformationWithdraw,
{ "istInformationWithdraw", "gsm_map.ch.istInformationWithdraw_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_callTerminationIndicator,
{ "callTerminationIndicator", "gsm_map.ch.callTerminationIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_CallTerminationIndicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_ch_msrn,
{ "msrn", "gsm_map.ch.msrn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_ch_SuppressMTSS_suppressCUG,
{ "suppressCUG", "gsm_map.ch.suppressCUG",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ch_SuppressMTSS_suppressCCBS,
{ "suppressCCBS", "gsm_map.ch.suppressCCBS",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_ch_AllowedServices_firstServiceAllowed,
{ "firstServiceAllowed", "gsm_map.ch.firstServiceAllowed",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_ch_AllowedServices_secondServiceAllowed,
{ "secondServiceAllowed", "gsm_map.ch.secondServiceAllowed",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_lcs_gsm_map_lcs_LCS_ClientID_PDU,
{ "LCS-ClientID", "gsm_map.lcs.LCS_ClientID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_mlcNumber,
{ "mlcNumber", "gsm_map.lcs.mlcNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_targetMS,
{ "targetMS", "gsm_map.lcs.targetMS",
FT_UINT32, BASE_DEC, VALS(gsm_map_SubscriberIdentity_vals), 0,
"SubscriberIdentity", HFILL }},
{ &hf_gsm_map_lcs_extensionContainer,
{ "extensionContainer", "gsm_map.lcs.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsLocationInfo,
{ "lcsLocationInfo", "gsm_map.lcs.lcsLocationInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_v_gmlc_Address,
{ "v-gmlc-Address", "gsm_map.lcs.v_gmlc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_lcs_h_gmlc_Address,
{ "h-gmlc-Address", "gsm_map.lcs.h_gmlc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_lcs_ppr_Address,
{ "ppr-Address", "gsm_map.lcs.ppr_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_lcs_additional_v_gmlc_Address,
{ "additional-v-gmlc-Address", "gsm_map.lcs.additional_v_gmlc_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_map_lcs_networkNode_Number,
{ "networkNode-Number", "gsm_map.lcs.networkNode_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_lmsi,
{ "lmsi", "gsm_map.lcs.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_gprsNodeIndicator,
{ "gprsNodeIndicator", "gsm_map.lcs.gprsNodeIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_additional_Number,
{ "additional-Number", "gsm_map.lcs.additional_Number",
FT_UINT32, BASE_DEC, VALS(gsm_map_sm_Additional_Number_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_supportedLCS_CapabilitySets,
{ "supportedLCS-CapabilitySets", "gsm_map.lcs.supportedLCS_CapabilitySets",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_additional_LCS_CapabilitySets,
{ "additional-LCS-CapabilitySets", "gsm_map.lcs.additional_LCS_CapabilitySets",
FT_BYTES, BASE_NONE, NULL, 0,
"SupportedLCS_CapabilitySets", HFILL }},
{ &hf_gsm_map_lcs_mme_Name,
{ "mme-Name", "gsm_map.lcs.mme_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_lcs_aaa_Server_Name,
{ "aaa-Server-Name", "gsm_map.lcs.aaa_Server_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_lcs_sgsn_Name,
{ "sgsn-Name", "gsm_map.lcs.sgsn_Name",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_lcs_sgsn_Realm,
{ "sgsn-Realm", "gsm_map.lcs.sgsn_Realm",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_lcs_locationType,
{ "locationType", "gsm_map.lcs.locationType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_mlc_Number,
{ "mlc-Number", "gsm_map.lcs.mlc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_lcs_ClientID,
{ "lcs-ClientID", "gsm_map.lcs.lcs_ClientID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_privacyOverride,
{ "privacyOverride", "gsm_map.lcs.privacyOverride_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_imsi,
{ "imsi", "gsm_map.lcs.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_msisdn,
{ "msisdn", "gsm_map.lcs.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_imei,
{ "imei", "gsm_map.lcs.imei",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcs_Priority,
{ "lcs-Priority", "gsm_map.lcs.lcs_Priority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcs_QoS,
{ "lcs-QoS", "gsm_map.lcs.lcs_QoS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_supportedGADShapes,
{ "supportedGADShapes", "gsm_map.lcs.supportedGADShapes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcs_ReferenceNumber,
{ "lcs-ReferenceNumber", "gsm_map.lcs.lcs_ReferenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsServiceTypeID,
{ "lcsServiceTypeID", "gsm_map.lcs.lcsServiceTypeID",
FT_UINT32, BASE_DEC, VALS(gsm_map_LCSServiceTypeID_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsCodeword,
{ "lcsCodeword", "gsm_map.lcs.lcsCodeword_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcs_PrivacyCheck,
{ "lcs-PrivacyCheck", "gsm_map.lcs.lcs_PrivacyCheck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_areaEventInfo,
{ "areaEventInfo", "gsm_map.lcs.areaEventInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_mo_lrShortCircuitIndicator,
{ "mo-lrShortCircuitIndicator", "gsm_map.lcs.mo_lrShortCircuitIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_periodicLDRInfo,
{ "periodicLDRInfo", "gsm_map.lcs.periodicLDRInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_reportingPLMNList,
{ "reportingPLMNList", "gsm_map.lcs.reportingPLMNList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_locationEstimateType,
{ "locationEstimateType", "gsm_map.lcs.locationEstimateType",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_LocationEstimateType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_deferredLocationEventType,
{ "deferredLocationEventType", "gsm_map.lcs.deferredLocationEventType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsClientType,
{ "lcsClientType", "gsm_map.lcs.lcsClientType",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_LCSClientType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsClientExternalID,
{ "lcsClientExternalID", "gsm_map.lcs.lcsClientExternalID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsClientDialedByMS,
{ "lcsClientDialedByMS", "gsm_map.lcs.lcsClientDialedByMS",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_lcs_lcsClientInternalID,
{ "lcsClientInternalID", "gsm_map.lcs.lcsClientInternalID",
FT_UINT32, BASE_DEC, VALS(gsm_map_LCSClientInternalID_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsClientName,
{ "lcsClientName", "gsm_map.lcs.lcsClientName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsAPN,
{ "lcsAPN", "gsm_map.lcs.lcsAPN",
FT_BYTES, BASE_NONE, NULL, 0,
"APN", HFILL }},
{ &hf_gsm_map_lcs_lcsRequestorID,
{ "lcsRequestorID", "gsm_map.lcs.lcsRequestorID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_dataCodingScheme,
{ "dataCodingScheme", "gsm_map.lcs.dataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
"USSD_DataCodingScheme", HFILL }},
{ &hf_gsm_map_lcs_nameString,
{ "nameString", "gsm_map.lcs.nameString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcs_FormatIndicator,
{ "lcs-FormatIndicator", "gsm_map.lcs.lcs_FormatIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_LCS_FormatIndicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_requestorIDString,
{ "requestorIDString", "gsm_map.lcs.requestorIDString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_horizontal_accuracy,
{ "horizontal-accuracy", "gsm_map.lcs.horizontal_accuracy",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_verticalCoordinateRequest,
{ "verticalCoordinateRequest", "gsm_map.lcs.verticalCoordinateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_vertical_accuracy,
{ "vertical-accuracy", "gsm_map.lcs.vertical_accuracy",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_responseTime,
{ "responseTime", "gsm_map.lcs.responseTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_velocityRequest,
{ "velocityRequest", "gsm_map.lcs.velocityRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_responseTimeCategory,
{ "responseTimeCategory", "gsm_map.lcs.responseTimeCategory",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_ResponseTimeCategory_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_lcsCodewordString,
{ "lcsCodewordString", "gsm_map.lcs.lcsCodewordString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_callSessionUnrelated,
{ "callSessionUnrelated", "gsm_map.lcs.callSessionUnrelated",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_PrivacyCheckRelatedAction_vals), 0,
"PrivacyCheckRelatedAction", HFILL }},
{ &hf_gsm_map_lcs_callSessionRelated,
{ "callSessionRelated", "gsm_map.lcs.callSessionRelated",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_PrivacyCheckRelatedAction_vals), 0,
"PrivacyCheckRelatedAction", HFILL }},
{ &hf_gsm_map_lcs_areaDefinition,
{ "areaDefinition", "gsm_map.lcs.areaDefinition_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_occurrenceInfo,
{ "occurrenceInfo", "gsm_map.lcs.occurrenceInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_OccurrenceInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_intervalTime,
{ "intervalTime", "gsm_map.lcs.intervalTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_areaList,
{ "areaList", "gsm_map.lcs.areaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_AreaList_item,
{ "Area", "gsm_map.lcs.Area_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_areaType,
{ "areaType", "gsm_map.lcs.areaType",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_AreaType_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_areaIdentification,
{ "areaIdentification", "gsm_map.lcs.areaIdentification",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_reportingAmount,
{ "reportingAmount", "gsm_map.lcs.reportingAmount",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_reportingInterval,
{ "reportingInterval", "gsm_map.lcs.reportingInterval",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_plmn_ListPrioritized,
{ "plmn-ListPrioritized", "gsm_map.lcs.plmn_ListPrioritized_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_plmn_List,
{ "plmn-List", "gsm_map.lcs.plmn_List",
FT_UINT32, BASE_DEC, NULL, 0,
"PLMNList", HFILL }},
{ &hf_gsm_map_lcs_PLMNList_item,
{ "ReportingPLMN", "gsm_map.lcs.ReportingPLMN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_plmn_Id,
{ "plmn-Id", "gsm_map.lcs.plmn_Id",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_ran_Technology,
{ "ran-Technology", "gsm_map.lcs.ran_Technology",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_RAN_Technology_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_ran_PeriodicLocationSupport,
{ "ran-PeriodicLocationSupport", "gsm_map.lcs.ran_PeriodicLocationSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_locationEstimate,
{ "locationEstimate", "gsm_map.lcs.locationEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_GeographicalInformation", HFILL }},
{ &hf_gsm_map_lcs_ageOfLocationEstimate,
{ "ageOfLocationEstimate", "gsm_map.lcs.ageOfLocationEstimate",
FT_UINT32, BASE_DEC, NULL, 0,
"AgeOfLocationInformation", HFILL }},
{ &hf_gsm_map_lcs_add_LocationEstimate,
{ "add-LocationEstimate", "gsm_map.lcs.add_LocationEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"Add_GeographicalInformation", HFILL }},
{ &hf_gsm_map_lcs_deferredmt_lrResponseIndicator,
{ "deferredmt-lrResponseIndicator", "gsm_map.lcs.deferredmt_lrResponseIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_geranPositioningData,
{ "geranPositioningData", "gsm_map.lcs.geranPositioningData",
FT_BYTES, BASE_NONE, NULL, 0,
"PositioningDataInformation", HFILL }},
{ &hf_gsm_map_lcs_utranPositioningData,
{ "utranPositioningData", "gsm_map.lcs.utranPositioningData",
FT_BYTES, BASE_NONE, NULL, 0,
"UtranPositioningDataInfo", HFILL }},
{ &hf_gsm_map_lcs_cellIdOrSai,
{ "cellIdOrSai", "gsm_map.lcs.cellIdOrSai",
FT_UINT32, BASE_DEC, VALS(gsm_map_CellGlobalIdOrServiceAreaIdOrLAI_vals), 0,
"CellGlobalIdOrServiceAreaIdOrLAI", HFILL }},
{ &hf_gsm_map_lcs_sai_Present,
{ "sai-Present", "gsm_map.lcs.sai_Present_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_accuracyFulfilmentIndicator,
{ "accuracyFulfilmentIndicator", "gsm_map.lcs.accuracyFulfilmentIndicator",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_AccuracyFulfilmentIndicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_velocityEstimate,
{ "velocityEstimate", "gsm_map.lcs.velocityEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_geranGANSSpositioningData,
{ "geranGANSSpositioningData", "gsm_map.lcs.geranGANSSpositioningData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_utranGANSSpositioningData,
{ "utranGANSSpositioningData", "gsm_map.lcs.utranGANSSpositioningData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_targetServingNodeForHandover,
{ "targetServingNodeForHandover", "gsm_map.lcs.targetServingNodeForHandover",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_ServingNodeAddress_vals), 0,
"ServingNodeAddress", HFILL }},
{ &hf_gsm_map_lcs_lcs_Event,
{ "lcs-Event", "gsm_map.lcs.lcs_Event",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_LCS_Event_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_na_ESRD,
{ "na-ESRD", "gsm_map.lcs.na_ESRD",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_na_ESRK,
{ "na-ESRK", "gsm_map.lcs.na_ESRK",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_slr_ArgExtensionContainer,
{ "slr-ArgExtensionContainer", "gsm_map.lcs.slr_ArgExtensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_deferredmt_lrData,
{ "deferredmt-lrData", "gsm_map.lcs.deferredmt_lrData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_pseudonymIndicator,
{ "pseudonymIndicator", "gsm_map.lcs.pseudonymIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_sequenceNumber,
{ "sequenceNumber", "gsm_map.lcs.sequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_terminationCause,
{ "terminationCause", "gsm_map.lcs.terminationCause",
FT_UINT32, BASE_DEC, VALS(gsm_map_lcs_TerminationCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_lcs_msc_Number,
{ "msc-Number", "gsm_map.lcs.msc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_sgsn_Number,
{ "sgsn-Number", "gsm_map.lcs.sgsn_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_lcs_mme_Number,
{ "mme-Number", "gsm_map.lcs.mme_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"DiameterIdentity", HFILL }},
{ &hf_gsm_map_lcs_DeferredLocationEventType_msAvailable,
{ "msAvailable", "gsm_map.lcs.msAvailable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_lcs_DeferredLocationEventType_enteringIntoArea,
{ "enteringIntoArea", "gsm_map.lcs.enteringIntoArea",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_lcs_DeferredLocationEventType_leavingFromArea,
{ "leavingFromArea", "gsm_map.lcs.leavingFromArea",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_lcs_DeferredLocationEventType_beingInsideArea,
{ "beingInsideArea", "gsm_map.lcs.beingInsideArea",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_lcs_DeferredLocationEventType_periodicLDR,
{ "periodicLDR", "gsm_map.lcs.periodicLDR",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidPoint,
{ "ellipsoidPoint", "gsm_map.lcs.ellipsoidPoint",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidPointWithUncertaintyCircle,
{ "ellipsoidPointWithUncertaintyCircle", "gsm_map.lcs.ellipsoidPointWithUncertaintyCircle",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidPointWithUncertaintyEllipse,
{ "ellipsoidPointWithUncertaintyEllipse", "gsm_map.lcs.ellipsoidPointWithUncertaintyEllipse",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_polygon,
{ "polygon", "gsm_map.lcs.polygon",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidPointWithAltitude,
{ "ellipsoidPointWithAltitude", "gsm_map.lcs.ellipsoidPointWithAltitude",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidPointWithAltitudeAndUncertaintyElipsoid,
{ "ellipsoidPointWithAltitudeAndUncertaintyElipsoid", "gsm_map.lcs.ellipsoidPointWithAltitudeAndUncertaintyElipsoid",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_gsm_map_lcs_SupportedGADShapes_ellipsoidArc,
{ "ellipsoidArc", "gsm_map.lcs.ellipsoidArc",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_gsm_map_gr_teleservice,
{ "teleservice", "gsm_map.gr.teleservice",
FT_UINT8, BASE_DEC, VALS(Teleservice_vals), 0,
"Ext_TeleserviceCode", HFILL }},
{ &hf_gsm_map_gr_asciCallReference,
{ "asciCallReference", "gsm_map.gr.asciCallReference",
FT_BYTES, BASE_NONE, NULL, 0,
"ASCI_CallReference", HFILL }},
{ &hf_gsm_map_gr_codec_Info,
{ "codec-Info", "gsm_map.gr.codec_Info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_cipheringAlgorithm,
{ "cipheringAlgorithm", "gsm_map.gr.cipheringAlgorithm",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_groupKeyNumber_Vk_Id,
{ "groupKeyNumber-Vk-Id", "gsm_map.gr.groupKeyNumber_Vk_Id",
FT_UINT32, BASE_DEC, NULL, 0,
"GroupKeyNumber", HFILL }},
{ &hf_gsm_map_gr_groupKey,
{ "groupKey", "gsm_map.gr.groupKey",
FT_BYTES, BASE_NONE, NULL, 0,
"Kc", HFILL }},
{ &hf_gsm_map_gr_priority,
{ "priority", "gsm_map.gr.priority",
FT_UINT32, BASE_DEC, VALS(gsm_map_EMLPP_Priority_vals), 0,
"EMLPP_Priority", HFILL }},
{ &hf_gsm_map_gr_uplinkFree,
{ "uplinkFree", "gsm_map.gr.uplinkFree_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_extensionContainer,
{ "extensionContainer", "gsm_map.gr.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_vstk,
{ "vstk", "gsm_map.gr.vstk",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_vstk_rand,
{ "vstk-rand", "gsm_map.gr.vstk_rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_talkerChannelParameter,
{ "talkerChannelParameter", "gsm_map.gr.talkerChannelParameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkReplyIndicator,
{ "uplinkReplyIndicator", "gsm_map.gr.uplinkReplyIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_groupCallNumber,
{ "groupCallNumber", "gsm_map.gr.groupCallNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_gr_imsi,
{ "imsi", "gsm_map.gr.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_talkerPriority,
{ "talkerPriority", "gsm_map.gr.talkerPriority",
FT_UINT32, BASE_DEC, VALS(gsm_map_gr_TalkerPriority_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_additionalInfo,
{ "additionalInfo", "gsm_map.gr.additionalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkRequestAck,
{ "uplinkRequestAck", "gsm_map.gr.uplinkRequestAck_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkReleaseIndication,
{ "uplinkReleaseIndication", "gsm_map.gr.uplinkReleaseIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkRejectCommand,
{ "uplinkRejectCommand", "gsm_map.gr.uplinkRejectCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkSeizedCommand,
{ "uplinkSeizedCommand", "gsm_map.gr.uplinkSeizedCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkReleaseCommand,
{ "uplinkReleaseCommand", "gsm_map.gr.uplinkReleaseCommand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_stateAttributes,
{ "stateAttributes", "gsm_map.gr.stateAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_emergencyModeResetCommandFlag,
{ "emergencyModeResetCommandFlag", "gsm_map.gr.emergencyModeResetCommandFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_sm_RP_UI,
{ "sm-RP-UI", "gsm_map.gr.sm_RP_UI",
FT_BYTES, BASE_NONE, NULL, 0,
"SignalInfo", HFILL }},
{ &hf_gsm_map_gr_an_APDU,
{ "an-APDU", "gsm_map.gr.an_APDU_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessNetworkSignalInfo", HFILL }},
{ &hf_gsm_map_gr_uplinkRequest,
{ "uplinkRequest", "gsm_map.gr.uplinkRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_releaseGroupCall,
{ "releaseGroupCall", "gsm_map.gr.releaseGroupCall_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_downlinkAttached,
{ "downlinkAttached", "gsm_map.gr.downlinkAttached_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_uplinkAttached,
{ "uplinkAttached", "gsm_map.gr.uplinkAttached_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_dualCommunication,
{ "dualCommunication", "gsm_map.gr.dualCommunication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_callOriginator,
{ "callOriginator", "gsm_map.gr.callOriginator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_requestedInfo,
{ "requestedInfo", "gsm_map.gr.requestedInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_gr_RequestedInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_groupId,
{ "groupId", "gsm_map.gr.groupId",
FT_BYTES, BASE_NONE, NULL, 0,
"Long_GroupId", HFILL }},
{ &hf_gsm_map_gr_cellId,
{ "cellId", "gsm_map.gr.cellId",
FT_BYTES, BASE_NONE, NULL, 0,
"GlobalCellId", HFILL }},
{ &hf_gsm_map_gr_tmsi,
{ "tmsi", "gsm_map.gr.tmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_cksn,
{ "cksn", "gsm_map.gr.cksn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_anchorMSC_Address,
{ "anchorMSC-Address", "gsm_map.gr.anchorMSC_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_map_gr_additionalSubscriptions,
{ "additionalSubscriptions", "gsm_map.gr.additionalSubscriptions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_gr_kc,
{ "kc", "gsm_map.gr.kc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_gsm_map_dialogue_MAP_DialoguePDU_PDU,
{ "MAP-DialoguePDU", "gsm_map.dialogue.MAP_DialoguePDU",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_MAP_DialoguePDU_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_map_open,
{ "map-open", "gsm_map.dialogue.map_open_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_OpenInfo", HFILL }},
{ &hf_gsm_map_dialogue_map_accept,
{ "map-accept", "gsm_map.dialogue.map_accept_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_AcceptInfo", HFILL }},
{ &hf_gsm_map_dialogue_map_close,
{ "map-close", "gsm_map.dialogue.map_close_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_CloseInfo", HFILL }},
{ &hf_gsm_map_dialogue_map_refuse,
{ "map-refuse", "gsm_map.dialogue.map_refuse_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_RefuseInfo", HFILL }},
{ &hf_gsm_map_dialogue_map_userAbort,
{ "map-userAbort", "gsm_map.dialogue.map_userAbort_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_UserAbortInfo", HFILL }},
{ &hf_gsm_map_dialogue_map_providerAbort,
{ "map-providerAbort", "gsm_map.dialogue.map_providerAbort_element",
FT_NONE, BASE_NONE, NULL, 0,
"MAP_ProviderAbortInfo", HFILL }},
{ &hf_gsm_map_dialogue_destinationReference,
{ "destinationReference", "gsm_map.dialogue.destinationReference",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_dialogue_originationReference,
{ "originationReference", "gsm_map.dialogue.originationReference",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_map_dialogue_extensionContainer,
{ "extensionContainer", "gsm_map.dialogue.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_reason,
{ "reason", "gsm_map.dialogue.reason",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_Reason_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_alternativeApplicationContext,
{ "alternativeApplicationContext", "gsm_map.dialogue.alternativeApplicationContext",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_gsm_map_dialogue_map_UserAbortChoice,
{ "map-UserAbortChoice", "gsm_map.dialogue.map_UserAbortChoice",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_MAP_UserAbortChoice_vals), 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_userSpecificReason,
{ "userSpecificReason", "gsm_map.dialogue.userSpecificReason_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_userResourceLimitation,
{ "userResourceLimitation", "gsm_map.dialogue.userResourceLimitation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_dialogue_resourceUnavailable,
{ "resourceUnavailable", "gsm_map.dialogue.resourceUnavailable",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_ResourceUnavailableReason_vals), 0,
"ResourceUnavailableReason", HFILL }},
{ &hf_gsm_map_dialogue_applicationProcedureCancellation,
{ "applicationProcedureCancellation", "gsm_map.dialogue.applicationProcedureCancellation",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_ProcedureCancellationReason_vals), 0,
"ProcedureCancellationReason", HFILL }},
{ &hf_gsm_map_dialogue_map_ProviderAbortReason,
{ "map-ProviderAbortReason", "gsm_map.dialogue.map_ProviderAbortReason",
FT_UINT32, BASE_DEC, VALS(gsm_map_dialogue_MAP_ProviderAbortReason_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_invoke,
{ "invoke", "gsm_old.invoke_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_returnResultLast,
{ "returnResultLast", "gsm_old.returnResultLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_gsm_old_returnError,
{ "returnError", "gsm_old.returnError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_reject,
{ "reject", "gsm_old.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_returnResultNotLast,
{ "returnResultNotLast", "gsm_old.returnResultNotLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_gsm_old_invokeID,
{ "invokeID", "gsm_old.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_gsm_old_linkedID,
{ "linkedID", "gsm_old.linkedID",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_gsm_old_opCode,
{ "opCode", "gsm_old.opCode",
FT_UINT32, BASE_DEC, VALS(gsm_old_MAP_OPERATION_vals), 0,
"MAP_OPERATION", HFILL }},
{ &hf_gsm_old_invokeparameter,
{ "invokeparameter", "gsm_old.invokeparameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_resultretres,
{ "resultretres", "gsm_old.resultretres_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_returnparameter,
{ "returnparameter", "gsm_old.returnparameter_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResultParameter", HFILL }},
{ &hf_gsm_old_errorCode,
{ "errorCode", "gsm_old.errorCode",
FT_UINT32, BASE_DEC, VALS(gsm_old_MAP_ERROR_vals), 0,
"MAP_ERROR", HFILL }},
{ &hf_gsm_old_parameter,
{ "parameter", "gsm_old.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnErrorParameter", HFILL }},
{ &hf_gsm_old_invokeIDRej,
{ "invokeIDRej", "gsm_old.invokeIDRej",
FT_UINT32, BASE_DEC, VALS(gsm_old_T_invokeIDRej_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_derivable,
{ "derivable", "gsm_old.derivable",
FT_INT32, BASE_DEC, NULL, 0,
"InvokeIdType", HFILL }},
{ &hf_gsm_old_not_derivable,
{ "not-derivable", "gsm_old.not_derivable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_problem,
{ "problem", "gsm_old.problem",
FT_UINT32, BASE_DEC, VALS(gsm_old_T_problem_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_generalProblem,
{ "generalProblem", "gsm_old.generalProblem",
FT_INT32, BASE_DEC, VALS(gsm_old_GeneralProblem_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_invokeProblem,
{ "invokeProblem", "gsm_old.invokeProblem",
FT_INT32, BASE_DEC, VALS(gsm_old_InvokeProblem_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_returnResultProblem,
{ "returnResultProblem", "gsm_old.returnResultProblem",
FT_INT32, BASE_DEC, VALS(gsm_old_ReturnResultProblem_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_returnErrorProblem,
{ "returnErrorProblem", "gsm_old.returnErrorProblem",
FT_INT32, BASE_DEC, VALS(gsm_old_ReturnErrorProblem_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_localValue,
{ "localValue", "gsm_old.localValue",
FT_INT32, BASE_DEC|BASE_EXT_STRING, &gsm_old_GSMMAPOperationLocalvalue_vals_ext, 0,
"OperationLocalvalue", HFILL }},
{ &hf_gsm_old_globalValue,
{ "globalValue", "gsm_old.globalValue",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_gsm_old_localValue_01,
{ "localValue", "gsm_old.localValue",
FT_INT32, BASE_DEC, VALS(gsm_old_GSMMAPLocalErrorcode_vals), 0,
"LocalErrorcode", HFILL }},
{ &hf_gsm_old_protocolId,
{ "protocolId", "gsm_old.protocolId",
FT_UINT32, BASE_DEC, VALS(gsm_map_ProtocolId_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_signalInfo,
{ "signalInfo", "gsm_old.signalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_extensionContainer,
{ "extensionContainer", "gsm_old.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_gsm_BearerCapability,
{ "gsm-BearerCapability", "gsm_old.gsm_BearerCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_isdn_BearerCapability,
{ "isdn-BearerCapability", "gsm_old.isdn_BearerCapability_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_call_Direction,
{ "call-Direction", "gsm_old.call_Direction",
FT_BYTES, BASE_NONE, NULL, 0,
"CallDirection", HFILL }},
{ &hf_gsm_old_b_Subscriber_Address,
{ "b-Subscriber-Address", "gsm_old.b_Subscriber_Address",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_chosenChannel,
{ "chosenChannel", "gsm_old.chosenChannel_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_lowerLayerCompatibility,
{ "lowerLayerCompatibility", "gsm_old.lowerLayerCompatibility_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_highLayerCompatibility,
{ "highLayerCompatibility", "gsm_old.highLayerCompatibility_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_sIWFSNumber,
{ "sIWFSNumber", "gsm_old.sIWFSNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_imsi,
{ "imsi", "gsm_old.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_vlr_Number,
{ "vlr-Number", "gsm_old.vlr_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_targetCellId,
{ "targetCellId", "gsm_old.targetCellId",
FT_BYTES, BASE_NONE, NULL, 0,
"GlobalCellId", HFILL }},
{ &hf_gsm_old_ho_NumberNotRequired,
{ "ho-NumberNotRequired", "gsm_old.ho_NumberNotRequired_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_bss_APDU,
{ "bss-APDU", "gsm_old.bss_APDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_handoverNumber,
{ "handoverNumber", "gsm_old.handoverNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_SendAuthenticationInfoResOld_item,
{ "SendAuthenticationInfoResOld item", "gsm_old.SendAuthenticationInfoResOld_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_rand,
{ "rand", "gsm_old.rand",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_sres,
{ "sres", "gsm_old.sres",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_kc,
{ "kc", "gsm_old.kc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_tripletList,
{ "tripletList", "gsm_old.tripletList",
FT_UINT32, BASE_DEC, NULL, 0,
"TripletListold", HFILL }},
{ &hf_gsm_old_TripletListold_item,
{ "AuthenticationTriplet-v2", "gsm_old.AuthenticationTriplet_v2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_channelType,
{ "channelType", "gsm_old.channelType_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_securityHeader,
{ "securityHeader", "gsm_old.securityHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_protectedPayload,
{ "protectedPayload", "gsm_old.protectedPayload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_securityParametersIndex,
{ "securityParametersIndex", "gsm_old.securityParametersIndex",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_originalComponentIdentifier,
{ "originalComponentIdentifier", "gsm_old.originalComponentIdentifier",
FT_UINT32, BASE_DEC, VALS(gsm_old_OriginalComponentIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_initialisationVector,
{ "initialisationVector", "gsm_old.initialisationVector",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_operationCode,
{ "operationCode", "gsm_old.operationCode",
FT_UINT32, BASE_DEC, VALS(gsm_old_OperationCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_errorCode_01,
{ "errorCode", "gsm_old.errorCode",
FT_UINT32, BASE_DEC, VALS(gsm_old_ErrorCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_userInfo,
{ "userInfo", "gsm_old.userInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_localValue_02,
{ "localValue", "gsm_old.localValue",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gsm_old_msisdn,
{ "msisdn", "gsm_old.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_category,
{ "category", "gsm_old.category",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_basicService,
{ "basicService", "gsm_old.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
"BasicServiceCode", HFILL }},
{ &hf_gsm_old_operatorSS_Code,
{ "operatorSS-Code", "gsm_old.operatorSS_Code",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_operatorSS_Code_item,
{ "operatorSS-Code item", "gsm_old.operatorSS_Code_item",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_gsm_old_sm_RP_DA,
{ "sm-RP-DA", "gsm_old.sm_RP_DA",
FT_UINT32, BASE_DEC, VALS(gsm_old_SM_RP_DAold_vals), 0,
"SM_RP_DAold", HFILL }},
{ &hf_gsm_old_sm_RP_OA,
{ "sm-RP-OA", "gsm_old.sm_RP_OA",
FT_UINT32, BASE_DEC, VALS(gsm_old_SM_RP_OAold_vals), 0,
"SM_RP_OAold", HFILL }},
{ &hf_gsm_old_sm_RP_UI,
{ "sm-RP-UI", "gsm_old.sm_RP_UI",
FT_BYTES, BASE_NONE, NULL, 0,
"SignalInfo", HFILL }},
{ &hf_gsm_old_moreMessagesToSend,
{ "moreMessagesToSend", "gsm_old.moreMessagesToSend_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_imsi_01,
{ "imsi", "gsm_old.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_lmsi,
{ "lmsi", "gsm_old.lmsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_serviceCentreAddressDA,
{ "serviceCentreAddressDA", "gsm_old.serviceCentreAddressDA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_noSM_RP_DA,
{ "noSM-RP-DA", "gsm_old.noSM_RP_DA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_msisdn_01,
{ "msisdn", "gsm_old.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_serviceCentreAddressOA,
{ "serviceCentreAddressOA", "gsm_old.serviceCentreAddressOA",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_noSM_RP_OA,
{ "noSM-RP-OA", "gsm_old.noSM_RP_OA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_cug_CheckInfo,
{ "cug-CheckInfo", "gsm_old.cug_CheckInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_numberOfForwarding,
{ "numberOfForwarding", "gsm_old.numberOfForwarding",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_networkSignalInfo,
{ "networkSignalInfo", "gsm_old.networkSignalInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalSignalInfo", HFILL }},
{ &hf_gsm_old_routingInfo,
{ "routingInfo", "gsm_old.routingInfo",
FT_UINT32, BASE_DEC, VALS(gsm_map_ch_RoutingInfo_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_originatingEntityNumber,
{ "originatingEntityNumber", "gsm_old.originatingEntityNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_old_msisdn_02,
{ "msisdn", "gsm_old.msisdn",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_old_sm_RP_PRI,
{ "sm-RP-PRI", "gsm_old.sm_RP_PRI",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_old_serviceCentreAddress,
{ "serviceCentreAddress", "gsm_old.serviceCentreAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_old_cug_Interlock,
{ "cug-Interlock", "gsm_old.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_subscriberId,
{ "subscriberId", "gsm_old.subscriberId",
FT_UINT32, BASE_DEC, VALS(gsm_map_SubscriberIdentity_vals), 0,
"SubscriberIdentity", HFILL }},
{ &hf_gsm_old_requestParameterList,
{ "requestParameterList", "gsm_old.requestParameterList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_RequestParameterList_item,
{ "RequestParameter", "gsm_old.RequestParameter",
FT_UINT32, BASE_DEC, VALS(gsm_old_RequestParameter_vals), 0,
NULL, HFILL }},
{ &hf_gsm_old_authenticationSet,
{ "authenticationSet", "gsm_old.authenticationSet",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_AuthenticationSetList_vals), 0,
"AuthenticationSetList", HFILL }},
{ &hf_gsm_old_subscriberData,
{ "subscriberData", "gsm_old.subscriberData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_ki,
{ "ki", "gsm_old.ki",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_old_SentParameterList_item,
{ "SentParameter", "gsm_old.SentParameter",
FT_UINT32, BASE_DEC, VALS(gsm_old_SentParameter_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_ss_Code,
{ "ss-Code", "gsm_ss.ss_Code",
FT_UINT8, BASE_DEC, VALS(ssCode_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_ss_Status,
{ "ss-Status", "gsm_ss.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ss_Notification,
{ "ss-Notification", "gsm_ss.ss_Notification",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_callIsWaiting_Indicator,
{ "callIsWaiting-Indicator", "gsm_ss.callIsWaiting_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_callOnHold_Indicator,
{ "callOnHold-Indicator", "gsm_ss.callOnHold_Indicator",
FT_UINT32, BASE_DEC, VALS(gsm_ss_CallOnHold_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_mpty_Indicator,
{ "mpty-Indicator", "gsm_ss.mpty_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_cug_Index,
{ "cug-Index", "gsm_ss.cug_Index",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_clirSuppressionRejected,
{ "clirSuppressionRejected", "gsm_ss.clirSuppressionRejected_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ect_Indicator,
{ "ect-Indicator", "gsm_ss.ect_Indicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_nameIndicator,
{ "nameIndicator", "gsm_ss.nameIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ccbs_Feature,
{ "ccbs-Feature", "gsm_ss.ccbs_Feature_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_alertingPattern,
{ "alertingPattern", "gsm_ss.alertingPattern",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_multicall_Indicator,
{ "multicall-Indicator", "gsm_ss.multicall_Indicator",
FT_UINT32, BASE_DEC, VALS(gsm_ss_Multicall_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_chargingInformation,
{ "chargingInformation", "gsm_ss.chargingInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e1,
{ "e1", "gsm_ss.e1",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e2,
{ "e2", "gsm_ss.e2",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e3,
{ "e3", "gsm_ss.e3",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e4,
{ "e4", "gsm_ss.e4",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e5,
{ "e5", "gsm_ss.e5",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e6,
{ "e6", "gsm_ss.e6",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_e7,
{ "e7", "gsm_ss.e7",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_suppressPrefCUG,
{ "suppressPrefCUG", "gsm_ss.suppressPrefCUG_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_suppressOA,
{ "suppressOA", "gsm_ss.suppressOA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ect_CallState,
{ "ect-CallState", "gsm_ss.ect_CallState",
FT_UINT32, BASE_DEC, VALS(gsm_ss_ECT_CallState_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_rdn,
{ "rdn", "gsm_ss.rdn",
FT_UINT32, BASE_DEC, VALS(gsm_ss_RDN_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_callingName,
{ "callingName", "gsm_ss.callingName",
FT_UINT32, BASE_DEC, VALS(gsm_ss_Name_vals), 0,
"Name", HFILL }},
{ &hf_gsm_ss_namePresentationAllowed,
{ "namePresentationAllowed", "gsm_ss.namePresentationAllowed_element",
FT_NONE, BASE_NONE, NULL, 0,
"NameSet", HFILL }},
{ &hf_gsm_ss_presentationRestricted,
{ "presentationRestricted", "gsm_ss.presentationRestricted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_nameUnavailable,
{ "nameUnavailable", "gsm_ss.nameUnavailable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_namePresentationRestricted,
{ "namePresentationRestricted", "gsm_ss.namePresentationRestricted_element",
FT_NONE, BASE_NONE, NULL, 0,
"NameSet", HFILL }},
{ &hf_gsm_ss_dataCodingScheme,
{ "dataCodingScheme", "gsm_ss.dataCodingScheme",
FT_BYTES, BASE_NONE, NULL, 0,
"USSD_DataCodingScheme", HFILL }},
{ &hf_gsm_ss_lengthInCharacters,
{ "lengthInCharacters", "gsm_ss.lengthInCharacters",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_gsm_ss_nameString,
{ "nameString", "gsm_ss.nameString",
FT_BYTES, BASE_NONE, NULL, 0,
"USSD_String", HFILL }},
{ &hf_gsm_ss_presentationAllowedAddress,
{ "presentationAllowedAddress", "gsm_ss.presentationAllowedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemotePartyNumber", HFILL }},
{ &hf_gsm_ss_numberNotAvailableDueToInterworking,
{ "numberNotAvailableDueToInterworking", "gsm_ss.numberNotAvailableDueToInterworking_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_presentationRestrictedAddress,
{ "presentationRestrictedAddress", "gsm_ss.presentationRestrictedAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemotePartyNumber", HFILL }},
{ &hf_gsm_ss_partyNumber,
{ "partyNumber", "gsm_ss.partyNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_ss_partyNumberSubaddress,
{ "partyNumberSubaddress", "gsm_ss.partyNumberSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_ss_deflectedToNumber,
{ "deflectedToNumber", "gsm_ss.deflectedToNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_gsm_ss_deflectedToSubaddress,
{ "deflectedToSubaddress", "gsm_ss.deflectedToSubaddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_SubaddressString", HFILL }},
{ &hf_gsm_ss_uUS_Service,
{ "uUS-Service", "gsm_ss.uUS_Service",
FT_UINT32, BASE_DEC, VALS(gsm_ss_UUS_Service_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_uUS_Required,
{ "uUS-Required", "gsm_ss.uUS_Required",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_gsm_ss_notificationType,
{ "notificationType", "gsm_ss.notificationType",
FT_UINT32, BASE_DEC, VALS(gsm_map_ms_NotificationToMSUser_vals), 0,
"NotificationToMSUser", HFILL }},
{ &hf_gsm_ss_locationType,
{ "locationType", "gsm_ss.locationType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcsClientExternalID,
{ "lcsClientExternalID", "gsm_ss.lcsClientExternalID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcsClientName,
{ "lcsClientName", "gsm_ss.lcsClientName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcsRequestorID,
{ "lcsRequestorID", "gsm_ss.lcsRequestorID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcsCodeword,
{ "lcsCodeword", "gsm_ss.lcsCodeword_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcsServiceTypeID,
{ "lcsServiceTypeID", "gsm_ss.lcsServiceTypeID",
FT_UINT32, BASE_DEC, VALS(gsm_map_LCSServiceTypeID_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_verificationResponse,
{ "verificationResponse", "gsm_ss.verificationResponse",
FT_UINT32, BASE_DEC, VALS(gsm_ss_VerificationResponse_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_molr_Type,
{ "molr-Type", "gsm_ss.molr_Type",
FT_UINT32, BASE_DEC, VALS(gsm_ss_MOLR_Type_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_locationMethod,
{ "locationMethod", "gsm_ss.locationMethod",
FT_UINT32, BASE_DEC, VALS(gsm_ss_LocationMethod_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_lcs_QoS,
{ "lcs-QoS", "gsm_ss.lcs_QoS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_mlc_Number,
{ "mlc-Number", "gsm_ss.mlc_Number",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_gsm_ss_gpsAssistanceData,
{ "gpsAssistanceData", "gsm_ss.gpsAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_supportedGADShapes,
{ "supportedGADShapes", "gsm_ss.supportedGADShapes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ageOfLocationInfo,
{ "ageOfLocationInfo", "gsm_ss.ageOfLocationInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"AgeOfLocationInformation", HFILL }},
{ &hf_gsm_ss_pseudonymIndicator,
{ "pseudonymIndicator", "gsm_ss.pseudonymIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_h_gmlc_address,
{ "h-gmlc-address", "gsm_ss.h_gmlc_address",
FT_BYTES, BASE_NONE, NULL, 0,
"GSN_Address", HFILL }},
{ &hf_gsm_ss_locationEstimate,
{ "locationEstimate", "gsm_ss.locationEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_GeographicalInformation", HFILL }},
{ &hf_gsm_ss_velocityEstimate,
{ "velocityEstimate", "gsm_ss.velocityEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_referenceNumber,
{ "referenceNumber", "gsm_ss.referenceNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"LCS_ReferenceNumber", HFILL }},
{ &hf_gsm_ss_periodicLDRInfo,
{ "periodicLDRInfo", "gsm_ss.periodicLDRInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_locationUpdateRequest,
{ "locationUpdateRequest", "gsm_ss.locationUpdateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_sequenceNumber,
{ "sequenceNumber", "gsm_ss.sequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_terminationCause,
{ "terminationCause", "gsm_ss.terminationCause",
FT_UINT32, BASE_DEC, VALS(gsm_ss_TerminationCause_vals), 0,
NULL, HFILL }},
{ &hf_gsm_ss_mo_lrShortCircuit,
{ "mo-lrShortCircuit", "gsm_ss.mo_lrShortCircuit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_ganssAssistanceData,
{ "ganssAssistanceData", "gsm_ss.ganssAssistanceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_multiplePositioningProtocolPDUs,
{ "multiplePositioningProtocolPDUs", "gsm_ss.multiplePositioningProtocolPDUs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_MultiplePositioningProtocolPDUs_item,
{ "PositioningProtocolPDU", "gsm_ss.PositioningProtocolPDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_decipheringKeys,
{ "decipheringKeys", "gsm_ss.decipheringKeys",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_add_LocationEstimate,
{ "add-LocationEstimate", "gsm_ss.add_LocationEstimate",
FT_BYTES, BASE_NONE, NULL, 0,
"Add_GeographicalInformation", HFILL }},
{ &hf_gsm_ss_reportingPLMNList,
{ "reportingPLMNList", "gsm_ss.reportingPLMNList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_deferredLocationEventType,
{ "deferredLocationEventType", "gsm_ss.deferredLocationEventType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_areaEventInfo,
{ "areaEventInfo", "gsm_ss.areaEventInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_ss_qoS,
{ "qoS", "gsm_ss.qoS_element",
FT_NONE, BASE_NONE, NULL, 0,
"LCS_QoS", HFILL }},
{ &hf_gsm_map_ericsson_imei,
{ "imei", "gsm_map.ericsson.imei",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ericsson_requestedEquipmentInfo,
{ "requestedEquipmentInfo", "gsm_map.ericsson.requestedEquipmentInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ericsson_imsi,
{ "imsi", "gsm_map.ericsson.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ericsson_locationInformation,
{ "locationInformation", "gsm_map.ericsson.locationInformation",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_gsm_map_ericsson_extensionContainer,
{ "extensionContainer", "gsm_map.ericsson.extensionContainer_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_alsLineIndicator,
{ "alsLineIndicator", "NokiaMAP-Extensions.alsLineIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_routingCategory,
{ "routingCategory", "NokiaMAP-Extensions.routingCategory",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_serviceList,
{ "serviceList", "NokiaMAP-Extensions.serviceList",
FT_BYTES, BASE_NONE, NULL, 0,
"MAPserviceList", HFILL }},
{ &hf_NokiaMAP_Extensions_serv_info_list,
{ "serv-info-list", "NokiaMAP-Extensions.serv_info_list",
FT_UINT32, BASE_DEC, NULL, 0,
"ServiceListWithInfo", HFILL }},
{ &hf_NokiaMAP_Extensions_extRoutingCategory,
{ "extRoutingCategory", "NokiaMAP-Extensions.extRoutingCategory",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ownMSISDN,
{ "ownMSISDN", "NokiaMAP-Extensions.ownMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_mwd_Set,
{ "mwd-Set", "NokiaMAP-Extensions.mwd_Set_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ChargingAreaList_item,
{ "ChargingArea", "NokiaMAP-Extensions.ChargingArea",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_chargingAreaList,
{ "chargingAreaList", "NokiaMAP-Extensions.chargingAreaList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_inTriggerKey,
{ "inTriggerKey", "NokiaMAP-Extensions.inTriggerKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_pnpIndex,
{ "pnpIndex", "NokiaMAP-Extensions.pnpIndex",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_callRedirectionIndex,
{ "callRedirectionIndex", "NokiaMAP-Extensions.callRedirectionIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_regionalChargingData,
{ "regionalChargingData", "NokiaMAP-Extensions.regionalChargingData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_callForwardingOverride,
{ "callForwardingOverride", "NokiaMAP-Extensions.callForwardingOverride_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_in_Capability,
{ "in-Capability", "NokiaMAP-Extensions.in_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_callingCategory,
{ "callingCategory", "NokiaMAP-Extensions.callingCategory",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_internalServiceIndicator,
{ "internalServiceIndicator", "NokiaMAP-Extensions.internalServiceIndicator",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_srbtSupportIndicator,
{ "srbtSupportIndicator", "NokiaMAP-Extensions.srbtSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_gmscSupportIndicator,
{ "gmscSupportIndicator", "NokiaMAP-Extensions.gmscSupportIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_protocolId,
{ "protocolId", "NokiaMAP-Extensions.protocolId",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_ExtraProtocolId_vals), 0,
"ExtraProtocolId", HFILL }},
{ &hf_NokiaMAP_Extensions_signalInfo,
{ "signalInfo", "NokiaMAP-Extensions.signalInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_cug_Interlock,
{ "cug-Interlock", "NokiaMAP-Extensions.cug_Interlock",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_cug_OutgoingAccess,
{ "cug-OutgoingAccess", "NokiaMAP-Extensions.cug_OutgoingAccess",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_NokiaMAP_Extensions_cug_CallInfo,
{ "cug-CallInfo", "NokiaMAP-Extensions.cug_CallInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_vlrNumber,
{ "vlrNumber", "NokiaMAP-Extensions.vlrNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_activeSs,
{ "activeSs", "NokiaMAP-Extensions.activeSs",
FT_BYTES, BASE_NONE, NULL, 0,
"ActiveSS_List", HFILL }},
{ &hf_NokiaMAP_Extensions_traceReference,
{ "traceReference", "NokiaMAP-Extensions.traceReference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_traceType,
{ "traceType", "NokiaMAP-Extensions.traceType_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_omc_Id,
{ "omc-Id", "NokiaMAP-Extensions.omc_Id",
FT_BYTES, BASE_NONE, NULL, 0,
"AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_hotBilling,
{ "hotBilling", "NokiaMAP-Extensions.hotBilling",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_NokiaMAP_Extensions_cfoIsDone,
{ "cfoIsDone", "NokiaMAP-Extensions.cfoIsDone",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_NokiaMAP_Extensions_cfInCug,
{ "cfInCug", "NokiaMAP-Extensions.cfInCug",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_NokiaMAP_Extensions_basicService,
{ "basicService", "NokiaMAP-Extensions.basicService",
FT_UINT32, BASE_DEC, VALS(gsm_map_BasicServiceCode_vals), 0,
"BasicServiceCode", HFILL }},
{ &hf_NokiaMAP_Extensions_category,
{ "category", "NokiaMAP-Extensions.category_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_nokia_CUG,
{ "nokia-CUG", "NokiaMAP-Extensions.nokia_CUG_element",
FT_NONE, BASE_NONE, NULL, 0,
"Nokia_CUG_Data", HFILL }},
{ &hf_NokiaMAP_Extensions_noBarrings,
{ "noBarrings", "NokiaMAP-Extensions.noBarrings_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_odb_Data,
{ "odb-Data", "NokiaMAP-Extensions.odb_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_fraudData,
{ "fraudData", "NokiaMAP-Extensions.fraudData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_leaId,
{ "leaId", "NokiaMAP-Extensions.leaId",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_olcmInfoTable,
{ "olcmInfoTable", "NokiaMAP-Extensions.olcmInfoTable",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_commonMSISDN,
{ "commonMSISDN", "NokiaMAP-Extensions.commonMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_rgData,
{ "rgData", "NokiaMAP-Extensions.rgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_olcmTraceReference,
{ "olcmTraceReference", "NokiaMAP-Extensions.olcmTraceReference",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_noAnswerTimer,
{ "noAnswerTimer", "NokiaMAP-Extensions.noAnswerTimer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_memberList,
{ "memberList", "NokiaMAP-Extensions.memberList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_alertingMethod,
{ "alertingMethod", "NokiaMAP-Extensions.alertingMethod",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_userType,
{ "userType", "NokiaMAP-Extensions.userType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_divertedToNbr,
{ "divertedToNbr", "NokiaMAP-Extensions.divertedToNbr",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_memberOfSuppression,
{ "memberOfSuppression", "NokiaMAP-Extensions.memberOfSuppression_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ringbacktone,
{ "ringbacktone", "NokiaMAP-Extensions.ringbacktone_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_MemberList_item,
{ "ISDN-AddressString", "NokiaMAP-Extensions.ISDN_AddressString",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_termination,
{ "termination", "NokiaMAP-Extensions.termination",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_NokiaMAP_Extensions_OlcmInfoTable_item,
{ "OlcmInfo", "NokiaMAP-Extensions.OlcmInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_olcmActive,
{ "olcmActive", "NokiaMAP-Extensions.olcmActive_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_moc,
{ "moc", "NokiaMAP-Extensions.moc_element",
FT_NONE, BASE_NONE, NULL, 0,
"FraudData", HFILL }},
{ &hf_NokiaMAP_Extensions_cf,
{ "cf", "NokiaMAP-Extensions.cf_element",
FT_NONE, BASE_NONE, NULL, 0,
"FraudData", HFILL }},
{ &hf_NokiaMAP_Extensions_ct,
{ "ct", "NokiaMAP-Extensions.ct_element",
FT_NONE, BASE_NONE, NULL, 0,
"FraudData", HFILL }},
{ &hf_NokiaMAP_Extensions_time,
{ "time", "NokiaMAP-Extensions.time",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeLimit", HFILL }},
{ &hf_NokiaMAP_Extensions_timeAction,
{ "timeAction", "NokiaMAP-Extensions.timeAction",
FT_BYTES, BASE_NONE, NULL, 0,
"ActionType", HFILL }},
{ &hf_NokiaMAP_Extensions_maxCount,
{ "maxCount", "NokiaMAP-Extensions.maxCount",
FT_UINT32, BASE_DEC, NULL, 0,
"FraudMaxCount", HFILL }},
{ &hf_NokiaMAP_Extensions_maxCountAction,
{ "maxCountAction", "NokiaMAP-Extensions.maxCountAction",
FT_BYTES, BASE_NONE, NULL, 0,
"ActionType", HFILL }},
{ &hf_NokiaMAP_Extensions_serviceCode,
{ "serviceCode", "NokiaMAP-Extensions.serviceCode",
FT_BYTES, BASE_NONE, NULL, 0,
"MAPserviceCode", HFILL }},
{ &hf_NokiaMAP_Extensions_versionInfo,
{ "versionInfo", "NokiaMAP-Extensions.versionInfo",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_in_key,
{ "in-key", "NokiaMAP-Extensions.in_key",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_INKey_vals), 0,
"INKey", HFILL }},
{ &hf_NokiaMAP_Extensions_fraudInfo,
{ "fraudInfo", "NokiaMAP-Extensions.fraudInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ServiceListWithInfo_item,
{ "ServiceWithInfo", "NokiaMAP-Extensions.ServiceWithInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_mobile_IN_key,
{ "mobile-IN-key", "NokiaMAP-Extensions.mobile_IN_key_element",
FT_NONE, BASE_NONE, NULL, 0,
"MKey", HFILL }},
{ &hf_NokiaMAP_Extensions_sms_IN_key,
{ "sms-IN-key", "NokiaMAP-Extensions.sms_IN_key_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMSKey", HFILL }},
{ &hf_NokiaMAP_Extensions_mKeyVer,
{ "mKeyVer", "NokiaMAP-Extensions.mKeyVer",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_mmScfAddress,
{ "mmScfAddress", "NokiaMAP-Extensions.mmScfAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_mmTdpName,
{ "mmTdpName", "NokiaMAP-Extensions.mmTdpName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_serviceKey,
{ "serviceKey", "NokiaMAP-Extensions.serviceKey",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_locupType,
{ "locupType", "NokiaMAP-Extensions.locupType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_mmSCPAddress,
{ "mmSCPAddress", "NokiaMAP-Extensions.mmSCPAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_smsTdpName,
{ "smsTdpName", "NokiaMAP-Extensions.smsTdpName",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_mmsFlag,
{ "mmsFlag", "NokiaMAP-Extensions.mmsFlag_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_map_Opt,
{ "map-Opt", "NokiaMAP-Extensions.map_Opt",
FT_BYTES, BASE_NONE, NULL, 0,
"MapOptFields", HFILL }},
{ &hf_NokiaMAP_Extensions_codec_List,
{ "codec-List", "NokiaMAP-Extensions.codec_List",
FT_UINT32, BASE_DEC, NULL, 0,
"CodecListExt", HFILL }},
{ &hf_NokiaMAP_Extensions_selected_Codec,
{ "selected-Codec", "NokiaMAP-Extensions.selected_Codec_element",
FT_NONE, BASE_NONE, NULL, 0,
"SelectedCodec", HFILL }},
{ &hf_NokiaMAP_Extensions_uma_access,
{ "uma-access", "NokiaMAP-Extensions.uma_access_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_uma_ip_address,
{ "uma-ip-address", "NokiaMAP-Extensions.uma_ip_address",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_5_17", HFILL }},
{ &hf_NokiaMAP_Extensions_uma_ip_port_nb,
{ "uma-ip-port-nb", "NokiaMAP-Extensions.uma_ip_port_nb",
FT_UINT32, BASE_DEC, NULL, 0,
"IPPortNb", HFILL }},
{ &hf_NokiaMAP_Extensions_CodecListExt_item,
{ "CodecExt", "NokiaMAP-Extensions.CodecExt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_codec,
{ "codec", "NokiaMAP-Extensions.codec",
FT_BYTES, BASE_NONE, NULL, 0,
"CodecExt", HFILL }},
{ &hf_NokiaMAP_Extensions_modes,
{ "modes", "NokiaMAP-Extensions.modes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_imsi,
{ "imsi", "NokiaMAP-Extensions.imsi",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_isdArgType,
{ "isdArgType", "NokiaMAP-Extensions.isdArgType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_isdResType,
{ "isdResType", "NokiaMAP-Extensions.isdResType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_dsdArgType,
{ "dsdArgType", "NokiaMAP-Extensions.dsdArgType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_sriArgType,
{ "sriArgType", "NokiaMAP-Extensions.sriArgType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_sriResType,
{ "sriResType", "NokiaMAP-Extensions.sriResType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_prnArgType,
{ "prnArgType", "NokiaMAP-Extensions.prnArgType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ulArgType,
{ "ulArgType", "NokiaMAP-Extensions.ulArgType",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_IsdArgType_item,
{ "IsdArgData", "NokiaMAP-Extensions.IsdArgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_privateFeatureCode,
{ "privateFeatureCode", "NokiaMAP-Extensions.privateFeatureCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_privateFeatureData,
{ "privateFeatureData", "NokiaMAP-Extensions.privateFeatureData",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_PrivateFeatureData_vals), 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_oickInfo,
{ "oickInfo", "NokiaMAP-Extensions.oickInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_subscriptionTypeInfo,
{ "subscriptionTypeInfo", "NokiaMAP-Extensions.subscriptionTypeInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_ss_Status,
{ "ss-Status", "NokiaMAP-Extensions.ss_Status",
FT_BYTES, BASE_NONE, NULL, 0,
"Ext_SS_Status", HFILL }},
{ &hf_NokiaMAP_Extensions_inCategoryKey,
{ "inCategoryKey", "NokiaMAP-Extensions.inCategoryKey",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_subscriptionType,
{ "subscriptionType", "NokiaMAP-Extensions.subscriptionType",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_IsdResType_item,
{ "IsdResData", "NokiaMAP-Extensions.IsdResData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_supportedPrivateFeature,
{ "supportedPrivateFeature", "NokiaMAP-Extensions.supportedPrivateFeature",
FT_BYTES, BASE_NONE, NULL, 0,
"PrivateFeatureCode", HFILL }},
{ &hf_NokiaMAP_Extensions_DsdArgType_item,
{ "DsdArgData", "NokiaMAP-Extensions.DsdArgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_privateFeatureWithdraw,
{ "privateFeatureWithdraw", "NokiaMAP-Extensions.privateFeatureWithdraw",
FT_BYTES, BASE_NONE, NULL, 0,
"PrivateFeatureCode", HFILL }},
{ &hf_NokiaMAP_Extensions_SriArgType_item,
{ "SriArgData", "NokiaMAP-Extensions.SriArgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_extraNetworkInfo,
{ "extraNetworkInfo", "NokiaMAP-Extensions.extraNetworkInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtraSignalInfo", HFILL }},
{ &hf_NokiaMAP_Extensions_SriResType_item,
{ "SriResData", "NokiaMAP-Extensions.SriResData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_PrnArgType_item,
{ "PrnArgData", "NokiaMAP-Extensions.PrnArgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_UlArgType_item,
{ "UlArgData", "NokiaMAP-Extensions.UlArgData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_privateFeatureUlArgData,
{ "privateFeatureUlArgData", "NokiaMAP-Extensions.privateFeatureUlArgData",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_PrivateFeatureUlArgData_vals), 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_adc,
{ "adc", "NokiaMAP-Extensions.adc",
FT_BYTES, BASE_NONE, NULL, 0,
"IMEI", HFILL }},
{ &hf_NokiaMAP_Extensions_cfuSMSCounter,
{ "cfuSMSCounter", "NokiaMAP-Extensions.cfuSMSCounter",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_cfusmcfo,
{ "cfusmcfo", "NokiaMAP-Extensions.cfusmcfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_memberInterrogate,
{ "memberInterrogate", "NokiaMAP-Extensions.memberInterrogate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_locationAreaCode,
{ "locationAreaCode", "NokiaMAP-Extensions.locationAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_cellId,
{ "cellId", "NokiaMAP-Extensions.cellId",
FT_BYTES, BASE_NONE, NULL, 0,
"CellGlobalIdOrServiceAreaIdFixedLength", HFILL }},
{ &hf_NokiaMAP_Extensions_lai,
{ "lai", "NokiaMAP-Extensions.lai",
FT_BYTES, BASE_NONE, NULL, 0,
"LAIFixedLength", HFILL }},
{ &hf_NokiaMAP_Extensions_sendImmResp,
{ "sendImmResp", "NokiaMAP-Extensions.sendImmResp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_rejectCause,
{ "rejectCause", "NokiaMAP-Extensions.rejectCause",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_1", HFILL }},
{ &hf_NokiaMAP_Extensions_senderMSISDN,
{ "senderMSISDN", "NokiaMAP-Extensions.senderMSISDN",
FT_BYTES, BASE_NONE, NULL, 0,
"ISDN_AddressString", HFILL }},
{ &hf_NokiaMAP_Extensions_access,
{ "access", "NokiaMAP-Extensions.access",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_Access_vals), 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_version,
{ "version", "NokiaMAP-Extensions.version",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_AccessSubscriptionListExt_item,
{ "Access", "NokiaMAP-Extensions.Access",
FT_UINT32, BASE_DEC, VALS(NokiaMAP_Extensions_Access_vals), 0,
NULL, HFILL }},
{ &hf_NokiaMAP_Extensions_AllowedServiceData_amr_wb_allowed,
{ "amr-wb-allowed", "NokiaMAP-Extensions.amr-wb-allowed",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
#line 3051 "../../asn1/gsm_map/packet-gsm_map-template.c"
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
&ett_gsm_map_extention_data,
&ett_gsm_map_tbcd_digits,
&ett_gsm_map_ussd_string,
#line 1 "../../asn1/gsm_map/packet-gsm_map-ettarr.c"
&ett_gsm_map_ExtensionContainer,
&ett_gsm_map_SLR_ArgExtensionContainer,
&ett_gsm_map_PrivateExtensionList,
&ett_gsm_map_PrivateExtension,
&ett_gsm_map_PCS_Extensions,
&ett_gsm_map_SLR_Arg_PCS_Extensions,
&ett_gsm_map_ExternalSignalInfo,
&ett_gsm_map_Ext_ExternalSignalInfo,
&ett_gsm_map_AccessNetworkSignalInfo,
&ett_gsm_map_Identity,
&ett_gsm_map_IMSI_WithLMSI,
&ett_gsm_map_HLR_List,
&ett_gsm_map_NAEA_PreferredCI,
&ett_gsm_map_SubscriberIdentity,
&ett_gsm_map_LCSClientExternalID,
&ett_gsm_map_NetworkNodeDiameterAddress,
&ett_gsm_map_CellGlobalIdOrServiceAreaIdOrLAI,
&ett_gsm_map_BasicServiceCode,
&ett_gsm_map_Ext_BasicServiceCode,
&ett_gsm_map_EMLPP_Info,
&ett_gsm_map_MC_SS_Info,
&ett_gsm_map_ss_RegisterSS_Arg,
&ett_gsm_map_ss_SS_Info,
&ett_gsm_map_ss_ForwardingInfo,
&ett_gsm_map_ss_ForwardingFeatureList,
&ett_gsm_map_ss_ForwardingFeature,
&ett_gsm_map_ss_CallBarringInfo,
&ett_gsm_map_ss_CallBarringFeatureList,
&ett_gsm_map_ss_CallBarringFeature,
&ett_gsm_map_ss_SS_Data,
&ett_gsm_map_ss_SS_SubscriptionOption,
&ett_gsm_map_ss_SS_ForBS_Code,
&ett_gsm_map_ss_GenericServiceInfo,
&ett_gsm_map_ss_CCBS_FeatureList,
&ett_gsm_map_ss_CCBS_Feature,
&ett_gsm_map_ss_InterrogateSS_Res,
&ett_gsm_map_ss_USSD_Arg,
&ett_gsm_map_ss_USSD_Res,
&ett_gsm_map_ss_SS_List,
&ett_gsm_map_ss_BasicServiceGroupList,
&ett_gsm_map_ss_SS_InvocationNotificationArg,
&ett_gsm_map_ss_SS_InvocationNotificationRes,
&ett_gsm_map_ss_SS_EventSpecification,
&ett_gsm_map_ss_RegisterCC_EntryArg,
&ett_gsm_map_ss_CCBS_Data,
&ett_gsm_map_ss_ServiceIndicator,
&ett_gsm_map_ss_RegisterCC_EntryRes,
&ett_gsm_map_ss_EraseCC_EntryArg,
&ett_gsm_map_ss_EraseCC_EntryRes,
&ett_gsm_map_er_RoamingNotAllowedParam,
&ett_gsm_map_er_CallBarredParam,
&ett_gsm_map_er_ExtensibleCallBarredParam,
&ett_gsm_map_er_CUG_RejectParam,
&ett_gsm_map_er_SS_IncompatibilityCause,
&ett_gsm_map_er_SM_DeliveryFailureCause,
&ett_gsm_map_er_AbsentSubscriberSM_Param,
&ett_gsm_map_er_SystemFailureParam,
&ett_gsm_map_er_ExtensibleSystemFailureParam,
&ett_gsm_map_er_DataMissingParam,
&ett_gsm_map_er_UnexpectedDataParam,
&ett_gsm_map_er_FacilityNotSupParam,
&ett_gsm_map_er_OR_NotAllowedParam,
&ett_gsm_map_er_UnknownSubscriberParam,
&ett_gsm_map_er_NumberChangedParam,
&ett_gsm_map_er_UnidentifiedSubParam,
&ett_gsm_map_er_IllegalSubscriberParam,
&ett_gsm_map_er_IllegalEquipmentParam,
&ett_gsm_map_er_BearerServNotProvParam,
&ett_gsm_map_er_TeleservNotProvParam,
&ett_gsm_map_er_TracingBufferFullParam,
&ett_gsm_map_er_NoRoamingNbParam,
&ett_gsm_map_er_AbsentSubscriberParam,
&ett_gsm_map_er_BusySubscriberParam,
&ett_gsm_map_er_NoSubscriberReplyParam,
&ett_gsm_map_er_ForwardingViolationParam,
&ett_gsm_map_er_ForwardingFailedParam,
&ett_gsm_map_er_ATI_NotAllowedParam,
&ett_gsm_map_er_ATSI_NotAllowedParam,
&ett_gsm_map_er_ATM_NotAllowedParam,
&ett_gsm_map_er_IllegalSS_OperationParam,
&ett_gsm_map_er_SS_NotAvailableParam,
&ett_gsm_map_er_SS_SubscriptionViolationParam,
&ett_gsm_map_er_InformationNotAvailableParam,
&ett_gsm_map_er_SubBusyForMT_SMS_Param,
&ett_gsm_map_er_MessageWaitListFullParam,
&ett_gsm_map_er_ResourceLimitationParam,
&ett_gsm_map_er_NoGroupCallNbParam,
&ett_gsm_map_er_IncompatibleTerminalParam,
&ett_gsm_map_er_ShortTermDenialParam,
&ett_gsm_map_er_LongTermDenialParam,
&ett_gsm_map_er_UnauthorizedRequestingNetwork_Param,
&ett_gsm_map_er_UnauthorizedLCSClient_Param,
&ett_gsm_map_er_PositionMethodFailure_Param,
&ett_gsm_map_er_UnknownOrUnreachableLCSClient_Param,
&ett_gsm_map_er_MM_EventNotSupported_Param,
&ett_gsm_map_er_TargetCellOutsideGCA_Param,
&ett_gsm_map_er_OngoingGroupCallParam,
&ett_gsm_map_sm_RoutingInfoForSM_Arg,
&ett_gsm_map_sm_RoutingInfoForSM_Res,
&ett_gsm_map_sm_IP_SM_GW_Guidance,
&ett_gsm_map_sm_LocationInfoWithLMSI,
&ett_gsm_map_sm_Additional_Number,
&ett_gsm_map_sm_MO_ForwardSM_Arg,
&ett_gsm_map_sm_MO_ForwardSM_Res,
&ett_gsm_map_sm_MT_ForwardSM_Arg,
&ett_gsm_map_sm_CorrelationID,
&ett_gsm_map_sm_MT_ForwardSM_Res,
&ett_gsm_map_sm_SM_RP_DA,
&ett_gsm_map_sm_SM_RP_OA,
&ett_gsm_map_sm_ReportSM_DeliveryStatusArg,
&ett_gsm_map_sm_ReportSM_DeliveryStatusRes,
&ett_gsm_map_sm_AlertServiceCentreArg,
&ett_gsm_map_sm_InformServiceCentreArg,
&ett_gsm_map_sm_MW_Status,
&ett_gsm_map_sm_ReadyForSM_Arg,
&ett_gsm_map_sm_ReadyForSM_Res,
&ett_gsm_map_sm_MT_ForwardSM_VGCS_Arg,
&ett_gsm_map_sm_MT_ForwardSM_VGCS_Res,
&ett_gsm_map_sm_DispatcherList,
&ett_gsm_map_sm_AdditionalDispatcherList,
&ett_gsm_map_om_ActivateTraceModeArg,
&ett_gsm_map_om_MDT_Configuration,
&ett_gsm_map_om_AreaScope,
&ett_gsm_map_om_CGI_List,
&ett_gsm_map_om_E_UTRAN_CGI_List,
&ett_gsm_map_om_RoutingAreaId_List,
&ett_gsm_map_om_LocationAreaId_List,
&ett_gsm_map_om_TrackingAreaId_List,
&ett_gsm_map_om_TraceDepthList,
&ett_gsm_map_om_TraceNE_TypeList,
&ett_gsm_map_om_TraceInterfaceList,
&ett_gsm_map_om_MSC_S_InterfaceList,
&ett_gsm_map_om_MGW_InterfaceList,
&ett_gsm_map_om_SGSN_InterfaceList,
&ett_gsm_map_om_GGSN_InterfaceList,
&ett_gsm_map_om_RNC_InterfaceList,
&ett_gsm_map_om_BMSC_InterfaceList,
&ett_gsm_map_om_MME_InterfaceList,
&ett_gsm_map_om_SGW_InterfaceList,
&ett_gsm_map_om_PGW_InterfaceList,
&ett_gsm_map_om_ENB_InterfaceList,
&ett_gsm_map_om_TraceEventList,
&ett_gsm_map_om_MSC_S_EventList,
&ett_gsm_map_om_MGW_EventList,
&ett_gsm_map_om_SGSN_EventList,
&ett_gsm_map_om_GGSN_EventList,
&ett_gsm_map_om_BMSC_EventList,
&ett_gsm_map_om_MME_EventList,
&ett_gsm_map_om_SGW_EventList,
&ett_gsm_map_om_PGW_EventList,
&ett_gsm_map_om_TracePropagationList,
&ett_gsm_map_om_ActivateTraceModeRes,
&ett_gsm_map_om_DeactivateTraceModeArg,
&ett_gsm_map_om_DeactivateTraceModeRes,
&ett_gsm_map_ms_UpdateLocationArg,
&ett_gsm_map_ms_VLR_Capability,
&ett_gsm_map_ms_SupportedRAT_Types,
&ett_gsm_map_ms_SuperChargerInfo,
&ett_gsm_map_ms_SupportedLCS_CapabilitySets,
&ett_gsm_map_ms_UpdateLocationRes,
&ett_gsm_map_ms_ADD_Info,
&ett_gsm_map_ms_PagingArea,
&ett_gsm_map_ms_LocationArea,
&ett_gsm_map_ms_CancelLocationArg_U,
&ett_gsm_map_ms_CancelLocationRes,
&ett_gsm_map_ms_PurgeMS_Arg_U,
&ett_gsm_map_ms_PurgeMS_Res,
&ett_gsm_map_ms_SendIdentificationArg,
&ett_gsm_map_ms_SendIdentificationRes_U,
&ett_gsm_map_ms_AuthenticationSetList,
&ett_gsm_map_ms_TripletList,
&ett_gsm_map_ms_QuintupletList,
&ett_gsm_map_ms_AuthenticationTriplet,
&ett_gsm_map_ms_AuthenticationQuintuplet,
&ett_gsm_map_ms_CurrentSecurityContext,
&ett_gsm_map_ms_GSM_SecurityContextData,
&ett_gsm_map_ms_UMTS_SecurityContextData,
&ett_gsm_map_ms_AuthenticationFailureReportArg,
&ett_gsm_map_ms_AuthenticationFailureReportRes,
&ett_gsm_map_ms_UpdateGprsLocationArg,
&ett_gsm_map_ms_EPS_Info,
&ett_gsm_map_ms_PDN_GW_Update,
&ett_gsm_map_ms_ISR_Information,
&ett_gsm_map_ms_SGSN_Capability,
&ett_gsm_map_ms_SupportedFeatures,
&ett_gsm_map_ms_UpdateGprsLocationRes,
&ett_gsm_map_ms_EPLMN_List,
&ett_gsm_map_ms_ForwardAccessSignalling_Arg_U,
&ett_gsm_map_ms_AllowedUMTS_Algorithms,
&ett_gsm_map_ms_PrepareHO_Arg_U,
&ett_gsm_map_ms_LCLS_Negotiation,
&ett_gsm_map_ms_LCLS_ConfigurationPreference,
&ett_gsm_map_ms_BSSMAP_ServiceHandoverList,
&ett_gsm_map_ms_BSSMAP_ServiceHandoverInfo,
&ett_gsm_map_ms_RadioResourceList,
&ett_gsm_map_ms_RadioResource,
&ett_gsm_map_ms_PrepareHO_Res_U,
&ett_gsm_map_ms_SelectedUMTS_Algorithms,
&ett_gsm_map_ms_ChosenRadioResourceInformation,
&ett_gsm_map_ms_PrepareSubsequentHO_Arg_U,
&ett_gsm_map_ms_PrepareSubsequentHO_Res_U,
&ett_gsm_map_ms_ProcessAccessSignalling_Arg_U,
&ett_gsm_map_ms_AoIPCodecsList,
&ett_gsm_map_ms_SupportedCodecsList,
&ett_gsm_map_ms_CodecList,
&ett_gsm_map_ms_SendEndSignal_Arg_U,
&ett_gsm_map_ms_SendEndSignal_Res,
&ett_gsm_map_ms_RelocationNumberList,
&ett_gsm_map_ms_RelocationNumber,
&ett_gsm_map_ms_SendAuthenticationInfoArg,
&ett_gsm_map_ms_Re_synchronisationInfo,
&ett_gsm_map_ms_SendAuthenticationInfoRes_U,
&ett_gsm_map_ms_EPS_AuthenticationSetList,
&ett_gsm_map_ms_EPC_AV,
&ett_gsm_map_ms_CheckIMEI_Arg,
&ett_gsm_map_ms_CheckIMEI_Res,
&ett_gsm_map_ms_RequestedEquipmentInfo,
&ett_gsm_map_ms_UESBI_Iu,
&ett_gsm_map_ms_InsertSubscriberDataArg,
&ett_gsm_map_ms_CSG_SubscriptionDataList,
&ett_gsm_map_ms_CSG_SubscriptionData,
&ett_gsm_map_ms_VPLMN_CSG_SubscriptionDataList,
&ett_gsm_map_ms_LIPA_AllowedAPNList,
&ett_gsm_map_ms_EPS_SubscriptionData,
&ett_gsm_map_ms_APN_ConfigurationProfile,
&ett_gsm_map_ms_EPS_DataList,
&ett_gsm_map_ms_APN_Configuration,
&ett_gsm_map_ms_EPS_QoS_Subscribed,
&ett_gsm_map_ms_AMBR,
&ett_gsm_map_ms_SpecificAPNInfoList,
&ett_gsm_map_ms_SpecificAPNInfo,
&ett_gsm_map_ms_Allocation_Retention_Priority,
&ett_gsm_map_ms_PDN_GW_Identity,
&ett_gsm_map_ms_AccessRestrictionData,
&ett_gsm_map_ms_LCSInformation,
&ett_gsm_map_ms_GMLC_List,
&ett_gsm_map_ms_GPRSDataList,
&ett_gsm_map_ms_PDP_Context,
&ett_gsm_map_ms_GPRSSubscriptionData,
&ett_gsm_map_ms_SGSN_CAMEL_SubscriptionInfo,
&ett_gsm_map_ms_GPRS_CSI,
&ett_gsm_map_ms_GPRS_CamelTDPDataList,
&ett_gsm_map_ms_GPRS_CamelTDPData,
&ett_gsm_map_ms_LSADataList,
&ett_gsm_map_ms_LSAData,
&ett_gsm_map_ms_LSAInformation,
&ett_gsm_map_ms_SubscriberData,
&ett_gsm_map_ms_BearerServiceList,
&ett_gsm_map_ms_TeleserviceList,
&ett_gsm_map_ms_ODB_Data,
&ett_gsm_map_ms_ODB_GeneralData,
&ett_gsm_map_ms_ODB_HPLMN_Data,
&ett_gsm_map_ms_Ext_SS_InfoList,
&ett_gsm_map_ms_Ext_SS_Info,
&ett_gsm_map_ms_Ext_ForwInfo,
&ett_gsm_map_ms_Ext_ForwFeatureList,
&ett_gsm_map_ms_Ext_ForwFeature,
&ett_gsm_map_ms_Ext_CallBarInfo,
&ett_gsm_map_ms_Ext_CallBarFeatureList,
&ett_gsm_map_ms_Ext_CallBarringFeature,
&ett_gsm_map_ms_CUG_Info,
&ett_gsm_map_ms_CUG_SubscriptionList,
&ett_gsm_map_ms_CUG_Subscription,
&ett_gsm_map_ms_CUG_FeatureList,
&ett_gsm_map_ms_Ext_BasicServiceGroupList,
&ett_gsm_map_ms_CUG_Feature,
&ett_gsm_map_ms_Ext_SS_Data,
&ett_gsm_map_ms_LCS_PrivacyExceptionList,
&ett_gsm_map_ms_LCS_PrivacyClass,
&ett_gsm_map_ms_ExternalClientList,
&ett_gsm_map_ms_PLMNClientList,
&ett_gsm_map_ms_Ext_ExternalClientList,
&ett_gsm_map_ms_ExternalClient,
&ett_gsm_map_ms_ServiceTypeList,
&ett_gsm_map_ms_ServiceType,
&ett_gsm_map_ms_MOLR_List,
&ett_gsm_map_ms_MOLR_Class,
&ett_gsm_map_ms_ZoneCodeList,
&ett_gsm_map_ms_InsertSubscriberDataRes,
&ett_gsm_map_ms_DeleteSubscriberDataArg,
&ett_gsm_map_ms_SpecificCSI_Withdraw,
&ett_gsm_map_ms_GPRSSubscriptionDataWithdraw,
&ett_gsm_map_ms_EPS_SubscriptionDataWithdraw,
&ett_gsm_map_ms_ContextIdList,
&ett_gsm_map_ms_LSAInformationWithdraw,
&ett_gsm_map_ms_LSAIdentityList,
&ett_gsm_map_ms_BasicServiceList,
&ett_gsm_map_ms_DeleteSubscriberDataRes,
&ett_gsm_map_ms_VlrCamelSubscriptionInfo,
&ett_gsm_map_ms_MT_smsCAMELTDP_CriteriaList,
&ett_gsm_map_ms_MT_smsCAMELTDP_Criteria,
&ett_gsm_map_ms_TPDU_TypeCriterion,
&ett_gsm_map_ms_D_CSI,
&ett_gsm_map_ms_DP_AnalysedInfoCriteriaList,
&ett_gsm_map_ms_DP_AnalysedInfoCriterium,
&ett_gsm_map_ms_SS_CSI,
&ett_gsm_map_ms_SS_CamelData,
&ett_gsm_map_ms_SS_EventList,
&ett_gsm_map_ms_O_CSI,
&ett_gsm_map_ms_O_BcsmCamelTDPDataList,
&ett_gsm_map_ms_O_BcsmCamelTDPData,
&ett_gsm_map_ms_O_BcsmCamelTDPCriteriaList,
&ett_gsm_map_ms_T_BCSM_CAMEL_TDP_CriteriaList,
&ett_gsm_map_ms_O_BcsmCamelTDP_Criteria,
&ett_gsm_map_ms_T_BCSM_CAMEL_TDP_Criteria,
&ett_gsm_map_ms_DestinationNumberCriteria,
&ett_gsm_map_ms_DestinationNumberList,
&ett_gsm_map_ms_DestinationNumberLengthList,
&ett_gsm_map_ms_BasicServiceCriteria,
&ett_gsm_map_ms_O_CauseValueCriteria,
&ett_gsm_map_ms_T_CauseValueCriteria,
&ett_gsm_map_ms_SupportedCamelPhases,
&ett_gsm_map_ms_OfferedCamel4CSIs,
&ett_gsm_map_ms_OfferedCamel4Functionalities,
&ett_gsm_map_ms_SMS_CSI,
&ett_gsm_map_ms_SMS_CAMEL_TDP_DataList,
&ett_gsm_map_ms_SMS_CAMEL_TDP_Data,
&ett_gsm_map_ms_M_CSI,
&ett_gsm_map_ms_MG_CSI,
&ett_gsm_map_ms_MobilityTriggers,
&ett_gsm_map_ms_T_CSI,
&ett_gsm_map_ms_T_BcsmCamelTDPDataList,
&ett_gsm_map_ms_T_BcsmCamelTDPData,
&ett_gsm_map_ms_SendRoutingInfoForGprsArg,
&ett_gsm_map_ms_SendRoutingInfoForGprsRes,
&ett_gsm_map_ms_FailureReportArg,
&ett_gsm_map_ms_FailureReportRes,
&ett_gsm_map_ms_NoteMsPresentForGprsArg,
&ett_gsm_map_ms_NoteMsPresentForGprsRes,
&ett_gsm_map_ms_ResetArg,
&ett_gsm_map_ms_SendingNode_Number,
&ett_gsm_map_ms_RestoreDataArg,
&ett_gsm_map_ms_RestoreDataRes,
&ett_gsm_map_ms_VBSDataList,
&ett_gsm_map_ms_VGCSDataList,
&ett_gsm_map_ms_VoiceGroupCallData,
&ett_gsm_map_ms_AdditionalSubscriptions,
&ett_gsm_map_ms_VoiceBroadcastData,
&ett_gsm_map_ms_ProvideSubscriberInfoArg,
&ett_gsm_map_ms_ProvideSubscriberInfoRes,
&ett_gsm_map_ms_SubscriberInfo,
&ett_gsm_map_ms_MNPInfoRes,
&ett_gsm_map_ms_GPRSMSClass,
&ett_gsm_map_ms_RequestedInfo,
&ett_gsm_map_ms_RequestedNodes,
&ett_gsm_map_ms_LocationInformation,
&ett_gsm_map_ms_LocationInformationEPS,
&ett_gsm_map_ms_LocationInformationGPRS,
&ett_gsm_map_ms_UserCSGInformation,
&ett_gsm_map_ms_SubscriberState,
&ett_gsm_map_ms_PS_SubscriberState,
&ett_gsm_map_ms_PDP_ContextInfoList,
&ett_gsm_map_ms_PDP_ContextInfo,
&ett_gsm_map_ms_AnyTimeInterrogationArg,
&ett_gsm_map_ms_AnyTimeInterrogationRes,
&ett_gsm_map_ms_AnyTimeSubscriptionInterrogationArg,
&ett_gsm_map_ms_AnyTimeSubscriptionInterrogationRes,
&ett_gsm_map_ms_CallWaitingData,
&ett_gsm_map_ms_Ext_CwFeatureList,
&ett_gsm_map_ms_Ext_CwFeature,
&ett_gsm_map_ms_ClipData,
&ett_gsm_map_ms_ClirData,
&ett_gsm_map_ms_CallHoldData,
&ett_gsm_map_ms_EctData,
&ett_gsm_map_ms_RequestedSubscriptionInfo,
&ett_gsm_map_ms_MSISDN_BS_List,
&ett_gsm_map_ms_MSISDN_BS,
&ett_gsm_map_ms_CallForwardingData,
&ett_gsm_map_ms_CallBarringData,
&ett_gsm_map_ms_ODB_Info,
&ett_gsm_map_ms_CAMEL_SubscriptionInfo,
&ett_gsm_map_ms_AnyTimeModificationArg,
&ett_gsm_map_ms_ModificationRequestFor_CW_Info,
&ett_gsm_map_ms_ModificationRequestFor_CH_Info,
&ett_gsm_map_ms_ModificationRequestFor_ECT_Info,
&ett_gsm_map_ms_ModificationRequestFor_CLIR_Info,
&ett_gsm_map_ms_ModificationRequestFor_CLIP_Info,
&ett_gsm_map_ms_ModificationRequestFor_CSG,
&ett_gsm_map_ms_RequestedServingNode,
&ett_gsm_map_ms_ServingNode,
&ett_gsm_map_ms_AnyTimeModificationRes,
&ett_gsm_map_ms_ModificationRequestFor_CF_Info,
&ett_gsm_map_ms_ModificationRequestFor_CB_Info,
&ett_gsm_map_ms_ModificationRequestFor_ODB_data,
&ett_gsm_map_ms_ModificationRequestFor_CSI,
&ett_gsm_map_ms_ModificationRequestFor_IP_SM_GW_Data,
&ett_gsm_map_ms_NoteSubscriberDataModifiedArg,
&ett_gsm_map_ms_NoteSubscriberDataModifiedRes,
&ett_gsm_map_ms_NoteMM_EventArg,
&ett_gsm_map_ms_NoteMM_EventRes,
&ett_gsm_map_ms_Ext_SS_InfoFor_CSE,
&ett_gsm_map_ms_Ext_ForwardingInfoFor_CSE,
&ett_gsm_map_ms_Ext_CallBarringInfoFor_CSE,
&ett_gsm_map_ms_UpdateVcsgLocationArg,
&ett_gsm_map_ms_UpdateVcsgLocationRes,
&ett_gsm_map_ms_CancelVcsgLocationArg,
&ett_gsm_map_ms_CancelVcsgLocationRes,
&ett_gsm_map_ch_CUG_CheckInfo,
&ett_gsm_map_ch_SendRoutingInfoArg,
&ett_gsm_map_ch_SuppressMTSS,
&ett_gsm_map_ch_SendRoutingInfoRes_U,
&ett_gsm_map_ch_AllowedServices,
&ett_gsm_map_ch_CCBS_Indicators,
&ett_gsm_map_ch_RoutingInfo,
&ett_gsm_map_ch_ForwardingData,
&ett_gsm_map_ch_ProvideRoamingNumberArg,
&ett_gsm_map_ch_ProvideRoamingNumberRes,
&ett_gsm_map_ch_ResumeCallHandlingArg,
&ett_gsm_map_ch_UU_Data,
&ett_gsm_map_ch_ResumeCallHandlingRes,
&ett_gsm_map_ch_CamelInfo,
&ett_gsm_map_ch_ExtendedRoutingInfo,
&ett_gsm_map_ch_CamelRoutingInfo,
&ett_gsm_map_ch_GmscCamelSubscriptionInfo,
&ett_gsm_map_ch_SetReportingStateArg,
&ett_gsm_map_ch_SetReportingStateRes,
&ett_gsm_map_ch_StatusReportArg,
&ett_gsm_map_ch_EventReportData,
&ett_gsm_map_ch_CallReportData,
&ett_gsm_map_ch_StatusReportRes,
&ett_gsm_map_ch_RemoteUserFreeArg,
&ett_gsm_map_ch_RemoteUserFreeRes,
&ett_gsm_map_ch_IST_AlertArg,
&ett_gsm_map_ch_IST_AlertRes,
&ett_gsm_map_ch_IST_CommandArg,
&ett_gsm_map_ch_IST_CommandRes,
&ett_gsm_map_ch_ReleaseResourcesArg,
&ett_gsm_map_ch_ReleaseResourcesRes,
&ett_gsm_map_lcs_RoutingInfoForLCS_Arg,
&ett_gsm_map_lcs_RoutingInfoForLCS_Res,
&ett_gsm_map_lcs_LCSLocationInfo,
&ett_gsm_map_lcs_ProvideSubscriberLocation_Arg,
&ett_gsm_map_lcs_LocationType,
&ett_gsm_map_lcs_DeferredLocationEventType,
&ett_gsm_map_lcs_LCS_ClientID,
&ett_gsm_map_lcs_LCSClientName,
&ett_gsm_map_lcs_LCSRequestorID,
&ett_gsm_map_lcs_LCS_QoS,
&ett_gsm_map_lcs_ResponseTime,
&ett_gsm_map_lcs_SupportedGADShapes,
&ett_gsm_map_lcs_LCSCodeword,
&ett_gsm_map_lcs_LCS_PrivacyCheck,
&ett_gsm_map_lcs_AreaEventInfo,
&ett_gsm_map_lcs_AreaDefinition,
&ett_gsm_map_lcs_AreaList,
&ett_gsm_map_lcs_Area,
&ett_gsm_map_lcs_PeriodicLDRInfo,
&ett_gsm_map_lcs_ReportingPLMNList,
&ett_gsm_map_lcs_PLMNList,
&ett_gsm_map_lcs_ReportingPLMN,
&ett_gsm_map_lcs_ProvideSubscriberLocation_Res,
&ett_gsm_map_lcs_SubscriberLocationReport_Arg,
&ett_gsm_map_lcs_Deferredmt_lrData,
&ett_gsm_map_lcs_ServingNodeAddress,
&ett_gsm_map_lcs_SubscriberLocationReport_Res,
&ett_gsm_map_gr_PrepareGroupCallArg,
&ett_gsm_map_gr_PrepareGroupCallRes,
&ett_gsm_map_gr_SendGroupCallEndSignalArg,
&ett_gsm_map_gr_SendGroupCallEndSignalRes,
&ett_gsm_map_gr_ForwardGroupCallSignallingArg,
&ett_gsm_map_gr_ProcessGroupCallSignallingArg,
&ett_gsm_map_gr_StateAttributes,
&ett_gsm_map_gr_SendGroupCallInfoArg,
&ett_gsm_map_gr_SendGroupCallInfoRes,
&ett_gsm_map_dialogue_MAP_DialoguePDU,
&ett_gsm_map_dialogue_MAP_OpenInfo,
&ett_gsm_map_dialogue_MAP_AcceptInfo,
&ett_gsm_map_dialogue_MAP_CloseInfo,
&ett_gsm_map_dialogue_MAP_RefuseInfo,
&ett_gsm_map_dialogue_MAP_UserAbortInfo,
&ett_gsm_map_dialogue_MAP_UserAbortChoice,
&ett_gsm_map_dialogue_MAP_ProviderAbortInfo,
&ett_gsm_old_Component,
&ett_gsm_old_Invoke,
&ett_gsm_old_ReturnResult,
&ett_gsm_old_T_resultretres,
&ett_gsm_old_ReturnError,
&ett_gsm_old_Reject,
&ett_gsm_old_T_invokeIDRej,
&ett_gsm_old_T_problem,
&ett_gsm_old_MAP_OPERATION,
&ett_gsm_old_MAP_ERROR,
&ett_gsm_old_Bss_APDU,
&ett_gsm_old_ProvideSIWFSNumberArg,
&ett_gsm_old_ProvideSIWFSNumberRes,
&ett_gsm_old_PurgeMSArgV2,
&ett_gsm_old_PrepareHO_ArgOld,
&ett_gsm_old_PrepareHO_ResOld,
&ett_gsm_old_SendAuthenticationInfoResOld,
&ett_gsm_old_SendAuthenticationInfoResOld_item,
&ett_gsm_old_SendIdentificationResV2,
&ett_gsm_old_TripletListold,
&ett_gsm_old_AuthenticationTriplet_v2,
&ett_gsm_old_SIWFSSignallingModifyArg,
&ett_gsm_old_SIWFSSignallingModifyRes,
&ett_gsm_old_SecureTransportArg,
&ett_gsm_old_SecureTransportErrorParam,
&ett_gsm_old_SecureTransportRes,
&ett_gsm_old_SecurityHeader,
&ett_gsm_old_OriginalComponentIdentifier,
&ett_gsm_old_OperationCode,
&ett_gsm_old_ErrorCode,
&ett_gsm_old_PlmnContainer_U,
&ett_gsm_old_T_operatorSS_Code,
&ett_gsm_old_ForwardSM_Arg,
&ett_gsm_old_SM_RP_DAold,
&ett_gsm_old_SM_RP_OAold,
&ett_gsm_old_SendRoutingInfoArgV2,
&ett_gsm_old_SendRoutingInfoResV2,
&ett_gsm_old_BeginSubscriberActivityArg,
&ett_gsm_old_RoutingInfoForSM_ArgV1,
&ett_gsm_old_SendParametersArg,
&ett_gsm_old_RequestParameterList,
&ett_gsm_old_SentParameter,
&ett_gsm_old_SentParameterList,
&ett_gsm_ss_NotifySS_Arg,
&ett_gsm_ss_ForwardChargeAdviceArg,
&ett_gsm_ss_ChargingInformation,
&ett_gsm_ss_ForwardCUG_InfoArg,
&ett_gsm_ss_ECT_Indicator,
&ett_gsm_ss_NameIndicator,
&ett_gsm_ss_Name,
&ett_gsm_ss_NameSet,
&ett_gsm_ss_RDN,
&ett_gsm_ss_RemotePartyNumber,
&ett_gsm_ss_AccessRegisterCCEntryArg,
&ett_gsm_ss_CallDeflectionArg,
&ett_gsm_ss_UserUserServiceArg,
&ett_gsm_ss_LocationNotificationArg,
&ett_gsm_ss_LocationNotificationRes,
&ett_gsm_ss_LCS_MOLRArg,
&ett_gsm_ss_MultiplePositioningProtocolPDUs,
&ett_gsm_ss_LCS_MOLRRes,
&ett_gsm_ss_LCS_AreaEventRequestArg,
&ett_gsm_ss_LCS_AreaEventReportArg,
&ett_gsm_ss_LCS_AreaEventCancellationArg,
&ett_gsm_ss_LCS_PeriodicLocationRequestArg,
&ett_gsm_ss_LCS_PeriodicLocationRequestRes,
&ett_gsm_ss_LCS_LocationUpdateArg,
&ett_gsm_ss_LCS_LocationUpdateRes,
&ett_gsm_ss_LCS_PeriodicLocationCancellationArg,
&ett_gsm_map_ericsson_EnhancedCheckIMEI_Arg,
&ett_NokiaMAP_Extensions_IsdArgExt_U,
&ett_NokiaMAP_Extensions_DsdArgExt_U,
&ett_NokiaMAP_Extensions_UlResExt_U,
&ett_NokiaMAP_Extensions_ChargingAreaList,
&ett_NokiaMAP_Extensions_RegionalChargingData,
&ett_NokiaMAP_Extensions_SS_DataExtension_U,
&ett_NokiaMAP_Extensions_SriExtension_U,
&ett_NokiaMAP_Extensions_ExtraSignalInfo_U,
&ett_NokiaMAP_Extensions_Nokia_CUG_Data,
&ett_NokiaMAP_Extensions_SriResExtension_U,
&ett_NokiaMAP_Extensions_RgData,
&ett_NokiaMAP_Extensions_MemberList,
&ett_NokiaMAP_Extensions_CanLocArgExt_U,
&ett_NokiaMAP_Extensions_ATMargExt_U,
&ett_NokiaMAP_Extensions_OlcmInfoTable,
&ett_NokiaMAP_Extensions_OlcmInfo,
&ett_NokiaMAP_Extensions_ATMresExt_U,
&ett_NokiaMAP_Extensions_DTMargExt_U,
&ett_NokiaMAP_Extensions_FraudInfo,
&ett_NokiaMAP_Extensions_FraudData,
&ett_NokiaMAP_Extensions_ServiceWithInfo,
&ett_NokiaMAP_Extensions_ServiceListWithInfo,
&ett_NokiaMAP_Extensions_INKey,
&ett_NokiaMAP_Extensions_MKey,
&ett_NokiaMAP_Extensions_SMSKey,
&ett_NokiaMAP_Extensions_HO_Ext_U,
&ett_NokiaMAP_Extensions_CodecListExt,
&ett_NokiaMAP_Extensions_SelectedCodec,
&ett_NokiaMAP_Extensions_AbsentSubscriberExt_U,
&ett_NokiaMAP_Extensions_ErrOlcmInfoTableExt_U,
&ett_NokiaMAP_Extensions_RoutingCategoryExt_U,
&ett_NokiaMAP_Extensions_ExtensionType,
&ett_NokiaMAP_Extensions_IsdArgType,
&ett_NokiaMAP_Extensions_IsdArgData,
&ett_NokiaMAP_Extensions_PrivateFeatureData,
&ett_NokiaMAP_Extensions_OickInfo,
&ett_NokiaMAP_Extensions_SubscriptionTypeInfo,
&ett_NokiaMAP_Extensions_IsdResType,
&ett_NokiaMAP_Extensions_IsdResData,
&ett_NokiaMAP_Extensions_DsdArgType,
&ett_NokiaMAP_Extensions_DsdArgData,
&ett_NokiaMAP_Extensions_SriArgType,
&ett_NokiaMAP_Extensions_SriArgData,
&ett_NokiaMAP_Extensions_SriResType,
&ett_NokiaMAP_Extensions_SriResData,
&ett_NokiaMAP_Extensions_PrnArgType,
&ett_NokiaMAP_Extensions_PrnArgData,
&ett_NokiaMAP_Extensions_UlArgType,
&ett_NokiaMAP_Extensions_UlArgData,
&ett_NokiaMAP_Extensions_PrivateFeatureUlArgData,
&ett_NokiaMAP_Extensions_SriForSMArgExt_U,
&ett_NokiaMAP_Extensions_ReportSMDelStatArgExt_U,
&ett_NokiaMAP_Extensions_MO_ForwardSM_ArgExt_U,
&ett_NokiaMAP_Extensions_UdlArgExt_U,
&ett_NokiaMAP_Extensions_RoamNotAllowedExt_U,
&ett_NokiaMAP_Extensions_AnyTimeModArgExt_U,
&ett_NokiaMAP_Extensions_AccessTypeExt,
&ett_NokiaMAP_Extensions_AccessSubscriptionListExt,
&ett_NokiaMAP_Extensions_AllowedServiceData,
#line 3085 "../../asn1/gsm_map/packet-gsm_map-template.c"
};
static ei_register_info ei[] = {
{ &ei_gsm_map_unknown_sequence3, { "gsm_map.unknown.sequence3", PI_UNDECODED, PI_ERROR, "Unknown or not implemented [3] sequence", EXPFILL }},
{ &ei_gsm_map_unknown_sequence, { "gsm_map.unknown.sequence", PI_UNDECODED, PI_ERROR, "Unknown or not implemented sequence", EXPFILL }},
{ &ei_gsm_map_unknown_parameter, { "gsm_map.unknown.parameter", PI_UNDECODED, PI_ERROR, "Unknown or not implemented parameter", EXPFILL }},
{ &ei_gsm_map_unknown_invokeData, { "gsm_map.unknown.invokeData", PI_MALFORMED, PI_WARN, "Unknown invokeData", EXPFILL }},
{ &ei_gsm_map_undecoded, { "gsm_map.undecoded", PI_UNDECODED, PI_WARN, "If you want this decoded send the packet to Wireshark-dev", EXPFILL }},
};
static const enum_val_t application_context_modes[] = {
{"Use Application Context from the trace", "Use application context from the trace", APPLICATON_CONTEXT_FROM_TRACE},
{"Treat as AC 1", "Treat as AC 1", 1},
{"Treat as AC 2", "Treat as AC 2", 2},
{"Treat as AC 3", "Treat as AC 3", 3},
{NULL, NULL, -1}
};
static tap_param gsm_map_stat_params[] = {
{ PARAM_FILTER, "filter", "Filter", NULL, TRUE }
};
static new_stat_tap_ui gsm_map_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"MAP Operation",
"gsm_map",
"gsm_map,operation",
gsm_map_stat_init,
gsm_map_stat_packet,
gsm_map_stat_reset,
gsm_map_stat_free_table_item,
NULL,
sizeof(gsm_map_stat_fields)/sizeof(stat_tap_table_item), gsm_map_stat_fields,
sizeof(gsm_map_stat_params)/sizeof(tap_param), gsm_map_stat_params,
NULL
};
proto_gsm_map_dialogue =proto_gsm_map = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("gsm_map", dissect_gsm_map, proto_gsm_map);
new_register_dissector("gsm_map_sccp", dissect_gsm_map_sccp, proto_gsm_map);
proto_register_field_array(proto_gsm_map, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_map = expert_register_protocol(proto_gsm_map);
expert_register_field_array(expert_gsm_map, ei, array_length(ei));
map_prop_arg_opcode_table = register_dissector_table("gsm_map.prop.arg.opcode", "GSM_MAP Proprietary Arg Opcodes", FT_UINT8, BASE_DEC);
map_prop_res_opcode_table = register_dissector_table("gsm_map.prop.res.opcode", "GSM_MAP Proprietary Res Opcodes", FT_UINT8, BASE_DEC);
map_prop_err_opcode_table = register_dissector_table("gsm_map.prop.err.opcode", "GSM_MAP Proprietary Err Opcodes", FT_UINT8, BASE_DEC);
gsm_map_tap = register_tap("gsm_map");
#line 1 "../../asn1/gsm_map/packet-gsm_map-dis-tab.c"
new_register_ber_oid_dissector("0.4.0.0.1.1.1.1", dissect_gsm_map_dialogue_MAP_DialoguePDU_PDU, proto_gsm_map_dialogue, "map-DialogueAS");
#line 3141 "../../asn1/gsm_map/packet-gsm_map-template.c"
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
register_new_stat_tap_ui(&gsm_map_stat_table);
}
