static void ansi_tcap_ctx_init(struct ansi_tcap_private_t *a_tcap_ctx) {
memset(a_tcap_ctx, '\0', sizeof(*a_tcap_ctx));
a_tcap_ctx->signature = ANSI_TCAP_CTX_SIGNATURE;
a_tcap_ctx->oid_is_present = FALSE;
a_tcap_ctx->TransactionID_str = NULL;
}
static void
ansi_tcap_init_transaction_table(void){
if (TransactionId_table){
g_hash_table_destroy(TransactionId_table);
TransactionId_table = NULL;
}
TransactionId_table = g_hash_table_new(g_str_hash, g_str_equal);
}
static void
ansi_tcap_init_protocol(void)
{
ansi_tcap_init_transaction_table();
}
static void
save_invoke_data(packet_info *pinfo, proto_tree *tree _U_, tvbuff_t *tvb _U_){
struct ansi_tcap_invokedata_t *ansi_tcap_saved_invokedata;
gchar *src, *dst;
char *buf;
src = address_to_str(wmem_packet_scope(), &(pinfo->src));
dst = address_to_str(wmem_packet_scope(), &(pinfo->dst));
if ((!pinfo->fd->flags.visited)&&(ansi_tcap_private.TransactionID_str)){
switch(ansi_tcap_response_matching_type){
case 0:
buf = wmem_strdup(wmem_packet_scope(), ansi_tcap_private.TransactionID_str);
break;
case 1:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s",ansi_tcap_private.TransactionID_str,src);
break;
default:
buf = wmem_strdup_printf(wmem_packet_scope(), "%s%s%s",ansi_tcap_private.TransactionID_str,src,dst);
break;
}
ansi_tcap_saved_invokedata = (struct ansi_tcap_invokedata_t *)g_hash_table_lookup(TransactionId_table,buf);
if(ansi_tcap_saved_invokedata)
return;
ansi_tcap_saved_invokedata = wmem_new(wmem_file_scope(), struct ansi_tcap_invokedata_t);
ansi_tcap_saved_invokedata->OperationCode = ansi_tcap_private.d.OperationCode;
ansi_tcap_saved_invokedata->OperationCode_national = ansi_tcap_private.d.OperationCode_national;
ansi_tcap_saved_invokedata->OperationCode_private = ansi_tcap_private.d.OperationCode_private;
g_hash_table_insert(TransactionId_table,
wmem_strdup(wmem_file_scope(), buf),
ansi_tcap_saved_invokedata);
}
}
static gboolean
find_saved_invokedata(packet_info *pinfo, proto_tree *tree _U_, tvbuff_t *tvb _U_){
struct ansi_tcap_invokedata_t *ansi_tcap_saved_invokedata;
gchar *src, *dst;
char *buf;
if (!ansi_tcap_private.TransactionID_str) {
return FALSE;
}
src = address_to_str(wmem_packet_scope(), &(pinfo->src));
dst = address_to_str(wmem_packet_scope(), &(pinfo->dst));
buf = (char *)wmem_alloc(wmem_packet_scope(), MAX_TID_STR_LEN);
buf[0] = '\0';
switch(ansi_tcap_response_matching_type){
case 0:
g_snprintf(buf,MAX_TID_STR_LEN,"%s",ansi_tcap_private.TransactionID_str);
break;
case 1:
g_snprintf(buf,MAX_TID_STR_LEN,"%s%s",ansi_tcap_private.TransactionID_str,dst);
break;
default:
g_snprintf(buf,MAX_TID_STR_LEN,"%s%s%s",ansi_tcap_private.TransactionID_str,dst,src);
break;
}
ansi_tcap_saved_invokedata = (struct ansi_tcap_invokedata_t *)g_hash_table_lookup(TransactionId_table, buf);
if(ansi_tcap_saved_invokedata){
ansi_tcap_private.d.OperationCode = ansi_tcap_saved_invokedata->OperationCode;
ansi_tcap_private.d.OperationCode_national = ansi_tcap_saved_invokedata->OperationCode_national;
ansi_tcap_private.d.OperationCode_private = ansi_tcap_saved_invokedata->OperationCode_private;
return TRUE;
}
return FALSE;
}
static gboolean
find_tcap_subdissector(tvbuff_t *tvb, asn1_ctx_t *actx, proto_tree *tree){
proto_item *item;
if(ansi_tcap_private.d.pdu == 1){
save_invoke_data(actx->pinfo, tree, tvb);
}else{
if(find_saved_invokedata(actx->pinfo, tree, tvb)){
if(ansi_tcap_private.d.OperationCode == 0){
item = proto_tree_add_int(tree, hf_ansi_tcap_national, tvb, 0, 0, ansi_tcap_private.d.OperationCode_national);
}else{
item = proto_tree_add_int(tree, hf_ansi_tcap_private, tvb, 0, 0, ansi_tcap_private.d.OperationCode_private);
}
PROTO_ITEM_SET_GENERATED(item);
ansi_tcap_private.d.OperationCode_item = item;
}
}
if(ansi_tcap_private.d.OperationCode == 0){
guint8 family = (ansi_tcap_private.d.OperationCode_national & 0x7f00)>>8;
guint8 specifier = (guint8)(ansi_tcap_private.d.OperationCode_national & 0xff);
if(!dissector_try_uint(ansi_tcap_national_opcode_table, ansi_tcap_private.d.OperationCode_national, tvb, actx->pinfo, tcap_top_tree)){
item = proto_tree_add_text(tree, tvb, 0, -1,
"Dissector for ANSI TCAP NATIONAL code:0x%x(Family %u, Specifier %u) \n"
"not implemented. Contact Wireshark developers if you want this supported(Spec required)",
ansi_tcap_private.d.OperationCode_national, family, specifier);
PROTO_ITEM_SET_GENERATED(item);
return FALSE;
}
return TRUE;
}else if(ansi_tcap_private.d.OperationCode == 1){
if((ansi_tcap_private.d.OperationCode_private & 0x0900) != 0x0900){
item = proto_tree_add_text(tree, tvb, 0, -1,
"Dissector for ANSI TCAP PRIVATE code:%u not implemented.\n"
"Contact Wireshark developers if you want this supported(Spec required)",
ansi_tcap_private.d.OperationCode_private);
PROTO_ITEM_SET_GENERATED(item);
return FALSE;
}
}
call_dissector_with_data(ansi_map_handle, tvb, actx->pinfo, tcap_top_tree, &ansi_tcap_private);
return TRUE;
}
static int
dissect_ansi_tcap_T_national(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 22 "../../asn1/ansi_tcap/ansi_tcap.cnf"
proto_tree *subtree;
proto_item *spcifier_item;
int start_offset = offset;
guint8 family;
guint8 specifier;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&ansi_tcap_private.d.OperationCode_national);
ansi_tcap_private.d.OperationCode_national = (ansi_tcap_private.d.OperationCode_national&0x7fff);
subtree = proto_item_add_subtree(actx->created_item, ett_ansi_tcap_op_code_nat);
family = (ansi_tcap_private.d.OperationCode_national & 0x7f00)>>8;
specifier = (guint8)(ansi_tcap_private.d.OperationCode_national & 0xff);
proto_tree_add_item(subtree, hf_ansi_tcap_bit_h, tvb, start_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ansi_tcap_op_family, tvb, start_offset, 2, ENC_BIG_ENDIAN);
spcifier_item = proto_tree_add_item(subtree, hf_ansi_tcap_op_specifier, tvb, start_offset, 2, ENC_BIG_ENDIAN);
switch(family){
case 0:
break;
case 1:
if(specifier== 1){
proto_item_append_text(spcifier_item, " Provide Value");
}else if (specifier== 2){
proto_item_append_text(spcifier_item, " Set Value");
}
break;
case 2:
if (specifier== 1){
proto_item_append_text(spcifier_item, " Bill Call");
}
break;
case 3:
if (specifier== 1){
proto_item_append_text(spcifier_item, " Start");
}else if (specifier== 2){
proto_item_append_text(spcifier_item, " Assist");
}
break;
case 4:
if (specifier== 1){
proto_item_append_text(spcifier_item, " Connect");
}else if (specifier== 2){
proto_item_append_text(spcifier_item, " Temporary Connect");
}else if (specifier== 3){
proto_item_append_text(spcifier_item, " Disconnect");
}else if (specifier== 4){
proto_item_append_text(spcifier_item, " Forward Disconnect");
}
break;
default:
break;
}
return offset;
}
static int
dissect_ansi_tcap_T_private(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&ansi_tcap_private.d.OperationCode_private);
return offset;
}
static int
dissect_ansi_tcap_OperationCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
OperationCode_choice, hf_index, ett_ansi_tcap_OperationCode,
&ansi_tcap_private.d.OperationCode);
#line 18 "../../asn1/ansi_tcap/ansi_tcap.cnf"
ansi_tcap_private.d.OperationCode_item = actx->created_item;
return offset;
}
static int
dissect_ansi_tcap_INTEGER_M128_127(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_ErrorCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ErrorCode_choice, hf_index, ett_ansi_tcap_ErrorCode,
NULL);
return offset;
}
static int
dissect_ansi_tcap_TransactionID_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 154 "../../asn1/ansi_tcap/ansi_tcap.cnf"
tvbuff_t *next_tvb;
guint8 len;
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
&next_tvb);
if(next_tvb) {
len = tvb_length_remaining(next_tvb, 0);
if(len !=0){
if (len > 4){
ansi_tcap_private.TransactionID_str = tvb_bytes_to_ep_str(next_tvb, 4,len-4);
}else{
ansi_tcap_private.TransactionID_str = tvb_bytes_to_ep_str(next_tvb, 0,len);
}
}
switch(len) {
case 1:
gp_tcapsrt_info->src_tid=tvb_get_guint8(next_tvb, 0);
break;
case 2:
gp_tcapsrt_info->src_tid=tvb_get_ntohs(next_tvb, 0);
break;
case 4:
gp_tcapsrt_info->src_tid=tvb_get_ntohl(next_tvb, 0);
break;
default:
gp_tcapsrt_info->src_tid=0;
break;
}
}
return offset;
}
static int
dissect_ansi_tcap_TransactionID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 7, TRUE, dissect_ansi_tcap_TransactionID_U);
return offset;
}
static int
dissect_ansi_tcap_OCTET_STRING_SIZE_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_ProtocolVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 26, TRUE, dissect_ansi_tcap_OCTET_STRING_SIZE_1);
return offset;
}
static int
dissect_ansi_tcap_IntegerApplicationContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 27, TRUE, dissect_ansi_tcap_INTEGER);
return offset;
}
static int
dissect_ansi_tcap_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_ansi_tcap_ObjectIDApplicationContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 118 "../../asn1/ansi_tcap/ansi_tcap.cnf"
static const char * oid_str;
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 28, TRUE, dissect_ansi_tcap_OBJECT_IDENTIFIER);
ansi_tcap_private.objectApplicationId_oid= (const void*) oid_str;
ansi_tcap_private.oid_is_present=TRUE;
return offset;
}
static int
dissect_ansi_tcap_T_applicationContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_applicationContext_choice, hf_index, ett_ansi_tcap_T_applicationContext,
NULL);
return offset;
}
static int
dissect_ansi_tcap_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_ansi_tcap_UserInformation_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
UserInformation_U_sequence_of, hf_index, ett_ansi_tcap_UserInformation_U);
return offset;
}
static int
dissect_ansi_tcap_UserInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 29, TRUE, dissect_ansi_tcap_UserInformation_U);
return offset;
}
static int
dissect_ansi_tcap_T_securityContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_securityContext_choice, hf_index, ett_ansi_tcap_T_securityContext,
NULL);
return offset;
}
static int
dissect_ansi_tcap_T_confidentialityId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_confidentialityId_choice, hf_index, ett_ansi_tcap_T_confidentialityId,
NULL);
return offset;
}
static int
dissect_ansi_tcap_Confidentiality(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Confidentiality_sequence, hf_index, ett_ansi_tcap_Confidentiality);
return offset;
}
static int
dissect_ansi_tcap_DialoguePortion_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DialoguePortion_U_sequence, hf_index, ett_ansi_tcap_DialoguePortion_U);
return offset;
}
static int
dissect_ansi_tcap_DialoguePortion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 25, TRUE, dissect_ansi_tcap_DialoguePortion_U);
return offset;
}
static int
dissect_ansi_tcap_T_componentIDs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 87 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if(find_tcap_subdissector(tvb, actx, tree))
offset = tvb_length(tvb);
return offset;
}
static int
dissect_ansi_tcap_Invoke(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 93 "../../asn1/ansi_tcap/ansi_tcap.cnf"
ansi_tcap_private.d.pdu = 1;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Invoke_sequence, hf_index, ett_ansi_tcap_Invoke);
return offset;
}
static int
dissect_ansi_tcap_T_componentID(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_T_parameter_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 100 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if(find_tcap_subdissector(tvb, actx, tree))
offset = tvb_length(tvb);
return offset;
}
static int
dissect_ansi_tcap_ReturnResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 104 "../../asn1/ansi_tcap/ansi_tcap.cnf"
ansi_tcap_private.d.pdu = 2;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnResult_sequence, hf_index, ett_ansi_tcap_ReturnResult);
return offset;
}
static int
dissect_ansi_tcap_T_componentID_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_T_parameter_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 110 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if(find_tcap_subdissector(tvb, actx, tree))
offset = tvb_length(tvb);
return offset;
}
static int
dissect_ansi_tcap_ReturnError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 114 "../../asn1/ansi_tcap/ansi_tcap.cnf"
ansi_tcap_private.d.pdu = 3;
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReturnError_sequence, hf_index, ett_ansi_tcap_ReturnError);
return offset;
}
static int
dissect_ansi_tcap_OCTET_STRING_SIZE_0_1(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_Problem(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_T_paramSequence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_paramSequence_sequence, hf_index, ett_ansi_tcap_T_paramSequence);
return offset;
}
static int
dissect_ansi_tcap_T_paramSet(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_paramSet_set, hf_index, ett_ansi_tcap_T_paramSet);
return offset;
}
static int
dissect_ansi_tcap_T_parameter_03(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_parameter_03_choice, hf_index, ett_ansi_tcap_T_parameter_03,
NULL);
return offset;
}
static int
dissect_ansi_tcap_Reject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reject_sequence, hf_index, ett_ansi_tcap_Reject);
return offset;
}
static int
dissect_ansi_tcap_ComponentPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ComponentPDU_choice, hf_index, ett_ansi_tcap_ComponentPDU,
NULL);
return offset;
}
static int
dissect_ansi_tcap_SEQUENCE_OF_ComponentPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ComponentPDU_sequence_of, hf_index, ett_ansi_tcap_SEQUENCE_OF_ComponentPDU);
return offset;
}
static int
dissect_ansi_tcap_ComponentSequence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 8, TRUE, dissect_ansi_tcap_SEQUENCE_OF_ComponentPDU);
return offset;
}
static int
dissect_ansi_tcap_UniTransactionPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UniTransactionPDU_sequence, hf_index, ett_ansi_tcap_UniTransactionPDU);
return offset;
}
static int
dissect_ansi_tcap_T_unidirectional(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 126 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "unidirectional ");
offset = dissect_ansi_tcap_UniTransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_TransactionPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransactionPDU_sequence, hf_index, ett_ansi_tcap_TransactionPDU);
return offset;
}
static int
dissect_ansi_tcap_T_queryWithPerm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 130 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "queryWithPerm ");
offset = dissect_ansi_tcap_TransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_T_queryWithoutPerm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 134 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "queryWithoutPerm ");
offset = dissect_ansi_tcap_TransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_T_response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 138 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "response ");
offset = dissect_ansi_tcap_TransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_T_conversationWithPerm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 142 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "conversationWithPerm ");
offset = dissect_ansi_tcap_TransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_T_conversationWithoutPerm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 146 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ALL;
col_set_str(actx->pinfo->cinfo, COL_INFO, "conversationWithoutPerm ");
offset = dissect_ansi_tcap_TransactionPDU(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_P_Abort_cause_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_ansi_tcap_P_Abort_cause(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 23, TRUE, dissect_ansi_tcap_P_Abort_cause_U);
return offset;
}
static int
dissect_ansi_tcap_UserAbortInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_PRI, 24, FALSE, dissect_ansi_tcap_EXTERNAL);
return offset;
}
static int
dissect_ansi_tcap_T_causeInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_causeInformation_choice, hf_index, ett_ansi_tcap_T_causeInformation,
NULL);
return offset;
}
static int
dissect_ansi_tcap_Abort(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Abort_sequence, hf_index, ett_ansi_tcap_Abort);
return offset;
}
static int
dissect_ansi_tcap_T_abort(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 150 "../../asn1/ansi_tcap/ansi_tcap.cnf"
gp_tcapsrt_info->ope=TC_ANSI_ABORT;
col_set_str(actx->pinfo->cinfo, COL_INFO, "Abort ");
offset = dissect_ansi_tcap_Abort(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_ansi_tcap_PackageType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
PackageType_choice, hf_index, ett_ansi_tcap_PackageType,
NULL);
return offset;
}
static void
dissect_ansi_tcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
ansi_tcap_ctx_init(&ansi_tcap_private);
tcap_top_tree = parent_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ANSI TCAP");
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_ansi_tcap, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tcap);
tcap_stat_item=item;
tcap_stat_tree=tree;
}
cur_oid = NULL;
tcapext_oid = NULL;
gp_tcapsrt_info=tcapsrt_razinfo();
tcap_subdissector_used=FALSE;
gp_tcap_context=NULL;
dissect_ansi_tcap_PackageType(FALSE, tvb, 0, &asn1_ctx, tree, -1);
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
stat_tree = proto_item_add_subtree(stat_item, ett_ansi_tcap_stat);
}
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, stat_tree, gp_tcapsrt_info);
ansi_tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->oid_present=TRUE;
}
}
if (g_ansi_tcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, stat_tree, p_tcap_context);
}
}
#endif
}
void
proto_reg_handoff_ansi_tcap(void)
{
ansi_map_handle = find_dissector("ansi_map");
ber_oid_dissector_table = find_dissector_table("ber.oid");
}
void
proto_register_ansi_tcap(void)
{
module_t *ansi_tcap_module;
static hf_register_info hf[] = {
{ &hf_ansi_tcapsrt_SessionId,
{ "Session Id",
"ansi_tcap.srt.session_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_tcapsrt_BeginSession,
{ "Begin Session",
"ansi_tcap.srt.begin",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT Begin of Session", HFILL }
},
{ &hf_ansi_tcapsrt_EndSession,
{ "End Session",
"ansi_tcap.srt.end",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"SRT End of Session", HFILL }
},
{ &hf_ansi_tcapsrt_SessionTime,
{ "Session duration",
"ansi_tcap.srt.sessiontime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of the TCAP session", HFILL }
},
{ &hf_ansi_tcapsrt_Duplicate,
{ "Request Duplicate",
"ansi_tcap.srt.duplicate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ansi_tcap_bit_h,
{ "Require Reply", "ansi_tcap.req_rep",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_ansi_tcap_op_family,
{ "Family",
"ansi_tcap.op_family",
FT_UINT16, BASE_DEC, VALS(ansi_tcap_national_op_code_family_vals), 0x7f00,
NULL, HFILL }
},
{ &hf_ansi_tcap_op_specifier,
{ "Specifier",
"ansi_tcap.op_specifier",
FT_UINT16, BASE_DEC, NULL, 0x00ff,
NULL, HFILL }
},
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-hfarr.c"
{ &hf_ansi_tcap_national,
{ "national", "ansi_tcap.national",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_private,
{ "private", "ansi_tcap.private",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_national_01,
{ "national", "ansi_tcap.national",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_ansi_tcap_private_01,
{ "private", "ansi_tcap.private",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ansi_tcap_unidirectional,
{ "unidirectional", "ansi_tcap.unidirectional_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_queryWithPerm,
{ "queryWithPerm", "ansi_tcap.queryWithPerm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_queryWithoutPerm,
{ "queryWithoutPerm", "ansi_tcap.queryWithoutPerm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_response,
{ "response", "ansi_tcap.response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_conversationWithPerm,
{ "conversationWithPerm", "ansi_tcap.conversationWithPerm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_conversationWithoutPerm,
{ "conversationWithoutPerm", "ansi_tcap.conversationWithoutPerm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_abort,
{ "abort", "ansi_tcap.abort_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_identifier,
{ "identifier", "ansi_tcap.identifier",
FT_BYTES, BASE_NONE, NULL, 0,
"TransactionID", HFILL }},
{ &hf_ansi_tcap_dialoguePortion,
{ "dialoguePortion", "ansi_tcap.dialoguePortion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_componentPortion,
{ "componentPortion", "ansi_tcap.componentPortion",
FT_UINT32, BASE_DEC, NULL, 0,
"ComponentSequence", HFILL }},
{ &hf_ansi_tcap_dialogPortion,
{ "dialogPortion", "ansi_tcap.dialogPortion_element",
FT_NONE, BASE_NONE, NULL, 0,
"DialoguePortion", HFILL }},
{ &hf_ansi_tcap_causeInformation,
{ "causeInformation", "ansi_tcap.causeInformation",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_T_causeInformation_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_abortCause,
{ "abortCause", "ansi_tcap.abortCause",
FT_INT32, BASE_DEC, VALS(ansi_tcap_P_Abort_cause_U_vals), 0,
"P_Abort_cause", HFILL }},
{ &hf_ansi_tcap_userInformation,
{ "userInformation", "ansi_tcap.userInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"UserAbortInformation", HFILL }},
{ &hf_ansi_tcap_version,
{ "version", "ansi_tcap.version",
FT_BYTES, BASE_NONE, NULL, 0,
"ProtocolVersion", HFILL }},
{ &hf_ansi_tcap_applicationContext,
{ "applicationContext", "ansi_tcap.applicationContext",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_T_applicationContext_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_integerApplicationId,
{ "integerApplicationId", "ansi_tcap.integerApplicationId",
FT_INT32, BASE_DEC, NULL, 0,
"IntegerApplicationContext", HFILL }},
{ &hf_ansi_tcap_objectApplicationId,
{ "objectApplicationId", "ansi_tcap.objectApplicationId",
FT_OID, BASE_NONE, NULL, 0,
"ObjectIDApplicationContext", HFILL }},
{ &hf_ansi_tcap_userInformation_01,
{ "userInformation", "ansi_tcap.userInformation",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_securityContext,
{ "securityContext", "ansi_tcap.securityContext",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_T_securityContext_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_integerSecurityId,
{ "integerSecurityId", "ansi_tcap.integerSecurityId",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ansi_tcap_objectSecurityId,
{ "objectSecurityId", "ansi_tcap.objectSecurityId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_ansi_tcap_confidentiality,
{ "confidentiality", "ansi_tcap.confidentiality_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap__untag_item,
{ "_untag item", "ansi_tcap._untag_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_ansi_tcap_confidentialityId,
{ "confidentialityId", "ansi_tcap.confidentialityId",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_T_confidentialityId_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_integerConfidentialityId,
{ "integerConfidentialityId", "ansi_tcap.integerConfidentialityId",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_ansi_tcap_objectConfidentialityId,
{ "objectConfidentialityId", "ansi_tcap.objectConfidentialityId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_ansi_tcap__untag_item_01,
{ "ComponentPDU", "ansi_tcap.ComponentPDU",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_ComponentPDU_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_invokeLast,
{ "invokeLast", "ansi_tcap.invokeLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"Invoke", HFILL }},
{ &hf_ansi_tcap_returnResultLast,
{ "returnResultLast", "ansi_tcap.returnResultLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_ansi_tcap_returnError,
{ "returnError", "ansi_tcap.returnError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_reject,
{ "reject", "ansi_tcap.reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_invokeNotLast,
{ "invokeNotLast", "ansi_tcap.invokeNotLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"Invoke", HFILL }},
{ &hf_ansi_tcap_returnResultNotLast,
{ "returnResultNotLast", "ansi_tcap.returnResultNotLast_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnResult", HFILL }},
{ &hf_ansi_tcap_componentIDs,
{ "componentIDs", "ansi_tcap.componentIDs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_operationCode,
{ "operationCode", "ansi_tcap.operationCode",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_OperationCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_parameter,
{ "parameter", "ansi_tcap.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_componentID,
{ "componentID", "ansi_tcap.componentID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_parameter_01,
{ "parameter", "ansi_tcap.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_parameter_01", HFILL }},
{ &hf_ansi_tcap_componentID_01,
{ "componentID", "ansi_tcap.componentID",
FT_BYTES, BASE_NONE, NULL, 0,
"T_componentID_01", HFILL }},
{ &hf_ansi_tcap_errorCode,
{ "errorCode", "ansi_tcap.errorCode",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_ErrorCode_vals), 0,
NULL, HFILL }},
{ &hf_ansi_tcap_parameter_02,
{ "parameter", "ansi_tcap.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_parameter_02", HFILL }},
{ &hf_ansi_tcap_componentID_02,
{ "componentID", "ansi_tcap.componentID",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_0_1", HFILL }},
{ &hf_ansi_tcap_rejectProblem,
{ "rejectProblem", "ansi_tcap.rejectProblem",
FT_INT32, BASE_DEC, VALS(ansi_tcap_Problem_vals), 0,
"Problem", HFILL }},
{ &hf_ansi_tcap_parameter_03,
{ "parameter", "ansi_tcap.parameter",
FT_UINT32, BASE_DEC, VALS(ansi_tcap_T_parameter_03_vals), 0,
"T_parameter_03", HFILL }},
{ &hf_ansi_tcap_paramSequence,
{ "paramSequence", "ansi_tcap.paramSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_tcap_paramSet,
{ "paramSet", "ansi_tcap.paramSet_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#line 494 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
};
static gint *ett[] = {
&ett_tcap,
&ett_param,
&ett_otid,
&ett_dtid,
&ett_ansi_tcap_stat,
&ett_ansi_tcap_op_code_nat,
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-ettarr.c"
&ett_ansi_tcap_OperationCode,
&ett_ansi_tcap_ErrorCode,
&ett_ansi_tcap_PackageType,
&ett_ansi_tcap_UniTransactionPDU,
&ett_ansi_tcap_TransactionPDU,
&ett_ansi_tcap_Abort,
&ett_ansi_tcap_T_causeInformation,
&ett_ansi_tcap_DialoguePortion_U,
&ett_ansi_tcap_T_applicationContext,
&ett_ansi_tcap_T_securityContext,
&ett_ansi_tcap_UserInformation_U,
&ett_ansi_tcap_Confidentiality,
&ett_ansi_tcap_T_confidentialityId,
&ett_ansi_tcap_SEQUENCE_OF_ComponentPDU,
&ett_ansi_tcap_ComponentPDU,
&ett_ansi_tcap_Invoke,
&ett_ansi_tcap_ReturnResult,
&ett_ansi_tcap_ReturnError,
&ett_ansi_tcap_Reject,
&ett_ansi_tcap_T_parameter_03,
&ett_ansi_tcap_T_paramSequence,
&ett_ansi_tcap_T_paramSet,
#line 505 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
};
static const enum_val_t ansi_tcap_response_matching_type_values[] = {
{"Only Transaction ID will be used in Invoke/response matching", "Transaction ID only", 0},
{"Transaction ID and Source will be used in Invoke/response matching", "Transaction ID and Source", 1},
{"Transaction ID Source and Destination will be used in Invoke/response matching", "Transaction ID Source and Destination", 2},
{NULL, NULL, -1}
};
proto_ansi_tcap = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("ansi_tcap", dissect_ansi_tcap, proto_ansi_tcap);
ansi_tcap_national_opcode_table = register_dissector_table("ansi_tcap.nat.opcode", "ANSI TCAP National Opcodes", FT_UINT16, BASE_DEC);
proto_register_field_array(proto_ansi_tcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ansi_tcap_module = prefs_register_protocol(proto_ansi_tcap, proto_reg_handoff_ansi_tcap);
prefs_register_enum_preference(ansi_tcap_module, "transaction.matchtype",
"Type of matching invoke/response",
"Type of matching invoke/response, risk of missmatch if loose matching choosen",
&ansi_tcap_response_matching_type, ansi_tcap_response_matching_type_values, FALSE);
register_init_routine(&ansi_tcap_init_protocol);
}
