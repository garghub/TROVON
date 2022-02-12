static int
dissect_mms_Unsigned32(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_domain_specific(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_domain_specific_sequence, hf_index, ett_mms_T_domain_specific);
return offset;
}
static int
dissect_mms_ObjectName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ObjectName_choice, hf_index, ett_mms_ObjectName,
NULL);
return offset;
}
static int
dissect_mms_Transitions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Transitions_bits, hf_index, ett_mms_Transitions,
NULL);
return offset;
}
static int
dissect_mms_AttachToEventCondition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttachToEventCondition_sequence, hf_index, ett_mms_AttachToEventCondition);
return offset;
}
static int
dissect_mms_Unsigned8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Priority(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned8(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_mms_AttachToSemaphore(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttachToSemaphore_sequence, hf_index, ett_mms_AttachToSemaphore);
return offset;
}
static int
dissect_mms_Modifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Modifier_choice, hf_index, ett_mms_Modifier,
NULL);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_Modifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Modifier_sequence_of, hf_index, ett_mms_SEQUENCE_OF_Modifier);
return offset;
}
static int
dissect_mms_Status_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_mms_T_objectClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_extendedObjectClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_extendedObjectClass_choice, hf_index, ett_mms_T_extendedObjectClass,
NULL);
return offset;
}
static int
dissect_mms_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_objectScope(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_objectScope_choice, hf_index, ett_mms_T_objectScope,
NULL);
return offset;
}
static int
dissect_mms_GetNameList_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetNameList_Request_sequence, hf_index, ett_mms_GetNameList_Request);
return offset;
}
static int
dissect_mms_Identify_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_objectClass_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_extendedObjectClass_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_extendedObjectClass_01_choice, hf_index, ett_mms_T_extendedObjectClass_01,
NULL);
return offset;
}
static int
dissect_mms_Rename_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Rename_Request_sequence, hf_index, ett_mms_Rename_Request);
return offset;
}
static int
dissect_mms_VisibleString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Address_choice, hf_index, ett_mms_Address,
NULL);
return offset;
}
static int
dissect_mms_T_array(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_array_sequence, hf_index, ett_mms_T_array);
return offset;
}
static int
dissect_mms_T_components_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_components_item_sequence, hf_index, ett_mms_T_components_item);
return offset;
}
static int
dissect_mms_T_components(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_components_sequence_of, hf_index, ett_mms_T_components);
return offset;
}
static int
dissect_mms_T_structure(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_structure_sequence, hf_index, ett_mms_T_structure);
return offset;
}
static int
dissect_mms_Integer32(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_TypeSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TypeSpecification_choice, hf_index, ett_mms_TypeSpecification,
NULL);
return offset;
}
static int
dissect_mms_T_variableDescription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_variableDescription_sequence, hf_index, ett_mms_T_variableDescription);
return offset;
}
static int
dissect_mms_T_indexRange(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_indexRange_sequence, hf_index, ett_mms_T_indexRange);
return offset;
}
static int
dissect_mms_T_accessSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_accessSelection_choice, hf_index, ett_mms_T_accessSelection,
NULL);
return offset;
}
static int
dissect_mms_T_selectAlternateAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_selectAlternateAccess_sequence, hf_index, ett_mms_T_selectAlternateAccess);
return offset;
}
static int
dissect_mms_T_indexRange_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_indexRange_01_sequence, hf_index, ett_mms_T_indexRange_01);
return offset;
}
static int
dissect_mms_T_selectAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_selectAccess_choice, hf_index, ett_mms_T_selectAccess,
NULL);
return offset;
}
static int
dissect_mms_AlternateAccessSelection(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AlternateAccessSelection_choice, hf_index, ett_mms_AlternateAccessSelection,
NULL);
return offset;
}
static int
dissect_mms_T_named(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_named_sequence, hf_index, ett_mms_T_named);
return offset;
}
static int
dissect_mms_AlternateAccess_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AlternateAccess_item_choice, hf_index, ett_mms_AlternateAccess_item,
NULL);
return offset;
}
static int
dissect_mms_AlternateAccess(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AlternateAccess_sequence_of, hf_index, ett_mms_AlternateAccess);
return offset;
}
static int
dissect_mms_ScatteredAccessDescription_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ScatteredAccessDescription_item_sequence, hf_index, ett_mms_ScatteredAccessDescription_item);
return offset;
}
static int
dissect_mms_ScatteredAccessDescription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ScatteredAccessDescription_sequence_of, hf_index, ett_mms_ScatteredAccessDescription);
return offset;
}
static int
dissect_mms_VariableSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
VariableSpecification_choice, hf_index, ett_mms_VariableSpecification,
NULL);
return offset;
}
static int
dissect_mms_T_listOfVariable_item_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_item_02_sequence, hf_index, ett_mms_T_listOfVariable_item_02);
return offset;
}
static int
dissect_mms_T_listOfVariable_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_02_sequence_of, hf_index, ett_mms_T_listOfVariable_02);
return offset;
}
static int
dissect_mms_VariableAccessSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
VariableAccessSpecification_choice, hf_index, ett_mms_VariableAccessSpecification,
NULL);
return offset;
}
static int
dissect_mms_Read_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Read_Request_sequence, hf_index, ett_mms_Read_Request);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Data_sequence_of, hf_index, ett_mms_SEQUENCE_OF_Data);
return offset;
}
static int
dissect_mms_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_mms_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_FloatingPoint(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_TimeOfDay(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 48 "../../asn1/mms/mms.cnf"
guint32 len;
guint32 milliseconds;
guint16 days;
gchar * ptime;
nstime_t ts;
len = tvb_length_remaining(tvb, offset);
if(len == 4)
{
milliseconds = tvb_get_ntohl(tvb, offset);
ptime = time_msecs_to_ep_str(milliseconds);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, ptime);
}
return offset;
}
if(len == 6)
{
milliseconds = tvb_get_ntohl(tvb, offset);
days = tvb_get_ntohs(tvb, offset+4);
ts.secs = (days + 5113) * 86400 + milliseconds / 1000;
ts.nsecs = (milliseconds % 1000) * 1000000U;
ptime = abs_time_to_ep_str(&ts, ABSOLUTE_TIME_UTC, TRUE);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, ptime);
}
return offset;
}
proto_tree_add_expert_format(tree, actx->pinfo, &ei_mms_mal_timeofday_encoding,
tvb, offset, len, "BER Error: malformed TimeOfDay encoding, length must be 4 or 6 bytes");
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, "????");
}
return offset;
return offset;
}
static int
dissect_mms_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_mms_MMSString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_UTF8String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_UtcTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 99 "../../asn1/mms/mms.cnf"
guint32 len;
guint32 seconds;
guint32 fraction;
guint32 nanoseconds;
nstime_t ts;
gchar * ptime;
len = tvb_length_remaining(tvb, offset);
if(len != 8)
{
proto_tree_add_expert_format(tree, actx->pinfo, &ei_mms_mal_utctime_encoding,
tvb, offset, len, "BER Error: malformed IEC61850 UTCTime encoding, length must be 8 bytes");
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, "????");
}
return offset;
}
seconds = tvb_get_ntohl(tvb, offset);
fraction = tvb_get_ntoh24(tvb, offset+4) * 0x100;
nanoseconds = (guint32)( ((guint64)fraction * G_GUINT64_CONSTANT(1000000000)) / G_GUINT64_CONSTANT(0x100000000) ) ;
ts.secs = seconds;
ts.nsecs = nanoseconds;
ptime = abs_time_to_ep_str(&ts, ABSOLUTE_TIME_UTC, TRUE);
if(hf_index >= 0)
{
proto_tree_add_string(tree, hf_index, tvb, offset, len, ptime);
}
return offset;
return offset;
}
static int
dissect_mms_Data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Data_choice, hf_index, ett_mms_Data,
NULL);
return offset;
}
static int
dissect_mms_Write_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Write_Request_sequence, hf_index, ett_mms_Write_Request);
return offset;
}
static int
dissect_mms_GetVariableAccessAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GetVariableAccessAttributes_Request_choice, hf_index, ett_mms_GetVariableAccessAttributes_Request,
NULL);
return offset;
}
static int
dissect_mms_DefineNamedVariable_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineNamedVariable_Request_sequence, hf_index, ett_mms_DefineNamedVariable_Request);
return offset;
}
static int
dissect_mms_DefineScatteredAccess_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineScatteredAccess_Request_sequence, hf_index, ett_mms_DefineScatteredAccess_Request);
return offset;
}
static int
dissect_mms_GetScatteredAccessAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_scopeOfDelete(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_ObjectName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ObjectName_sequence_of, hf_index, ett_mms_SEQUENCE_OF_ObjectName);
return offset;
}
static int
dissect_mms_DeleteVariableAccess_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteVariableAccess_Request_sequence, hf_index, ett_mms_DeleteVariableAccess_Request);
return offset;
}
static int
dissect_mms_T_listOfVariable_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_item_sequence, hf_index, ett_mms_T_listOfVariable_item);
return offset;
}
static int
dissect_mms_T_listOfVariable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_sequence_of, hf_index, ett_mms_T_listOfVariable);
return offset;
}
static int
dissect_mms_DefineNamedVariableList_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineNamedVariableList_Request_sequence, hf_index, ett_mms_DefineNamedVariableList_Request);
return offset;
}
static int
dissect_mms_GetNamedVariableListAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_scopeOfDelete_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_DeleteNamedVariableList_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteNamedVariableList_Request_sequence, hf_index, ett_mms_DeleteNamedVariableList_Request);
return offset;
}
static int
dissect_mms_DefineNamedType_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineNamedType_Request_sequence, hf_index, ett_mms_DefineNamedType_Request);
return offset;
}
static int
dissect_mms_GetNamedTypeAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_scopeOfDelete_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_DeleteNamedType_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteNamedType_Request_sequence, hf_index, ett_mms_DeleteNamedType_Request);
return offset;
}
static int
dissect_mms_T_listOfPromptData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfPromptData_sequence_of, hf_index, ett_mms_T_listOfPromptData);
return offset;
}
static int
dissect_mms_Input_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Input_Request_sequence, hf_index, ett_mms_Input_Request);
return offset;
}
static int
dissect_mms_T_listOfOutputData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfOutputData_sequence_of, hf_index, ett_mms_T_listOfOutputData);
return offset;
}
static int
dissect_mms_Output_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Output_Request_sequence, hf_index, ett_mms_Output_Request);
return offset;
}
static int
dissect_mms_T_ap_title(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 25 "../../asn1/mms/mms.cnf"
offset=dissect_acse_AP_title(FALSE, tvb, offset, actx, tree, hf_mms_ap_title);
return offset;
}
static int
dissect_mms_T_ap_invocation_id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 28 "../../asn1/mms/mms.cnf"
offset=dissect_acse_AP_invocation_identifier(FALSE, tvb, offset, actx, tree, hf_mms_ap_invocation_id);
return offset;
}
static int
dissect_mms_T_ae_qualifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 31 "../../asn1/mms/mms.cnf"
offset=dissect_acse_AE_qualifier(FALSE, tvb, offset, actx, tree, hf_mms_ae_qualifier);
return offset;
}
static int
dissect_mms_T_ae_invocation_id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 34 "../../asn1/mms/mms.cnf"
offset=dissect_acse_AE_invocation_identifier(FALSE, tvb, offset, actx, tree, hf_mms_ae_invocation_id);
return offset;
}
static int
dissect_mms_ApplicationReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ApplicationReference_sequence, hf_index, ett_mms_ApplicationReference);
return offset;
}
static int
dissect_mms_TakeControl_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TakeControl_Request_sequence, hf_index, ett_mms_TakeControl_Request);
return offset;
}
static int
dissect_mms_RelinquishControl_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RelinquishControl_Request_sequence, hf_index, ett_mms_RelinquishControl_Request);
return offset;
}
static int
dissect_mms_Unsigned16(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_DefineSemaphore_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineSemaphore_Request_sequence, hf_index, ett_mms_DefineSemaphore_Request);
return offset;
}
static int
dissect_mms_DeleteSemaphore_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ReportSemaphoreStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ReportPoolSemaphoreStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportPoolSemaphoreStatus_Request_sequence, hf_index, ett_mms_ReportPoolSemaphoreStatus_Request);
return offset;
}
static int
dissect_mms_T_state(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_ReportSemaphoreEntryStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportSemaphoreEntryStatus_Request_sequence, hf_index, ett_mms_ReportSemaphoreEntryStatus_Request);
return offset;
}
static int
dissect_mms_T_listOfCapabilities_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_01_sequence_of, hf_index, ett_mms_T_listOfCapabilities_01);
return offset;
}
static int
dissect_mms_InitiateDownloadSequence_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitiateDownloadSequence_Request_sequence, hf_index, ett_mms_InitiateDownloadSequence_Request);
return offset;
}
static int
dissect_mms_DownloadSegment_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_vmd_state(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_application_reference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_definition(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_resource(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_service(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_service_preempt(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_time_resolution(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_access(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_initiate(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_conclude(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_cancel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_file(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_errorClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_errorClass_choice, hf_index, ett_mms_T_errorClass,
NULL);
return offset;
}
static int
dissect_mms_ObtainFile_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_ProgramInvocationState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Start_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ProgramInvocationState(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Stop_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ProgramInvocationState(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Resume_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ProgramInvocationState(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Reset_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ProgramInvocationState(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_DeleteVariableAccess_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_DeleteNamedVariableList_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_DeleteNamedType_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_DefineEventEnrollment_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_FileRename_Error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_serviceSpecificInformation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_serviceSpecificInformation_choice, hf_index, ett_mms_T_serviceSpecificInformation,
NULL);
return offset;
}
static int
dissect_mms_ServiceError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ServiceError_sequence, hf_index, ett_mms_ServiceError);
return offset;
}
static int
dissect_mms_TerminateDownloadSequence_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TerminateDownloadSequence_Request_sequence, hf_index, ett_mms_TerminateDownloadSequence_Request);
return offset;
}
static int
dissect_mms_InitiateUploadSequence_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_UploadSegment_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Integer32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_TerminateUploadSequence_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Integer32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_listOfCapabilities_03(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_03_sequence_of, hf_index, ett_mms_T_listOfCapabilities_03);
return offset;
}
static int
dissect_mms_GraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_FileName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
FileName_sequence_of, hf_index, ett_mms_FileName);
return offset;
}
static int
dissect_mms_RequestDomainDownload_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestDomainDownload_Request_sequence, hf_index, ett_mms_RequestDomainDownload_Request);
return offset;
}
static int
dissect_mms_RequestDomainUpload_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestDomainUpload_Request_sequence, hf_index, ett_mms_RequestDomainUpload_Request);
return offset;
}
static int
dissect_mms_T_listOfCapabilities_04(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_04_sequence_of, hf_index, ett_mms_T_listOfCapabilities_04);
return offset;
}
static int
dissect_mms_LoadDomainContent_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LoadDomainContent_Request_sequence, hf_index, ett_mms_LoadDomainContent_Request);
return offset;
}
static int
dissect_mms_StoreDomainContent_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
StoreDomainContent_Request_sequence, hf_index, ett_mms_StoreDomainContent_Request);
return offset;
}
static int
dissect_mms_DeleteDomain_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_GetDomainAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_Identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Identifier_sequence_of, hf_index, ett_mms_SEQUENCE_OF_Identifier);
return offset;
}
static int
dissect_mms_CreateProgramInvocation_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateProgramInvocation_Request_sequence, hf_index, ett_mms_CreateProgramInvocation_Request);
return offset;
}
static int
dissect_mms_DeleteProgramInvocation_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_executionArgument(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_executionArgument_choice, hf_index, ett_mms_T_executionArgument,
NULL);
return offset;
}
static int
dissect_mms_Start_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Start_Request_sequence, hf_index, ett_mms_Start_Request);
return offset;
}
static int
dissect_mms_Stop_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Stop_Request_sequence, hf_index, ett_mms_Stop_Request);
return offset;
}
static int
dissect_mms_T_executionArgument_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_executionArgument_01_choice, hf_index, ett_mms_T_executionArgument_01,
NULL);
return offset;
}
static int
dissect_mms_Resume_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Resume_Request_sequence, hf_index, ett_mms_Resume_Request);
return offset;
}
static int
dissect_mms_Reset_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Reset_Request_sequence, hf_index, ett_mms_Reset_Request);
return offset;
}
static int
dissect_mms_Kill_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Kill_Request_sequence, hf_index, ett_mms_Kill_Request);
return offset;
}
static int
dissect_mms_GetProgramInvocationAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Identifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ObtainFile_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ObtainFile_Request_sequence, hf_index, ett_mms_ObtainFile_Request);
return offset;
}
static int
dissect_mms_EC_Class(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_DefineEventCondition_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineEventCondition_Request_sequence, hf_index, ett_mms_DefineEventCondition_Request);
return offset;
}
static int
dissect_mms_DeleteEventCondition_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DeleteEventCondition_Request_choice, hf_index, ett_mms_DeleteEventCondition_Request,
NULL);
return offset;
}
static int
dissect_mms_GetEventConditionAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ReportEventConditionStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_AlterEventConditionMonitoring_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlterEventConditionMonitoring_Request_sequence, hf_index, ett_mms_AlterEventConditionMonitoring_Request);
return offset;
}
static int
dissect_mms_TriggerEvent_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TriggerEvent_Request_sequence, hf_index, ett_mms_TriggerEvent_Request);
return offset;
}
static int
dissect_mms_DefineEventAction_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineEventAction_Request_sequence, hf_index, ett_mms_DefineEventAction_Request);
return offset;
}
static int
dissect_mms_DeleteEventAction_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DeleteEventAction_Request_choice, hf_index, ett_mms_DeleteEventAction_Request,
NULL);
return offset;
}
static int
dissect_mms_GetEventActionAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ReportEventActionStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_AlarmAckRule(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_DefineEventEnrollment_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DefineEventEnrollment_Request_sequence, hf_index, ett_mms_DefineEventEnrollment_Request);
return offset;
}
static int
dissect_mms_DeleteEventEnrollment_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
DeleteEventEnrollment_Request_choice, hf_index, ett_mms_DeleteEventEnrollment_Request,
NULL);
return offset;
}
static int
dissect_mms_AlterEventEnrollment_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlterEventEnrollment_Request_sequence, hf_index, ett_mms_AlterEventEnrollment_Request);
return offset;
}
static int
dissect_mms_ReportEventEnrollmentStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_scopeOfRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_GetEventEnrollmentAttributes_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetEventEnrollmentAttributes_Request_sequence, hf_index, ett_mms_GetEventEnrollmentAttributes_Request);
return offset;
}
static int
dissect_mms_EC_State(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_EventTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
EventTime_choice, hf_index, ett_mms_EventTime,
NULL);
return offset;
}
static int
dissect_mms_AcknowledgeEventNotification_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AcknowledgeEventNotification_Request_sequence, hf_index, ett_mms_AcknowledgeEventNotification_Request);
return offset;
}
static int
dissect_mms_T_acknowledgmentFilter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_severityFilter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_severityFilter_sequence, hf_index, ett_mms_T_severityFilter);
return offset;
}
static int
dissect_mms_GetAlarmSummary_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetAlarmSummary_Request_sequence, hf_index, ett_mms_GetAlarmSummary_Request);
return offset;
}
static int
dissect_mms_T_acknowledgmentFilter_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_severityFilter_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_severityFilter_01_sequence, hf_index, ett_mms_T_severityFilter_01);
return offset;
}
static int
dissect_mms_GetAlarmEnrollmentSummary_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetAlarmEnrollmentSummary_Request_sequence, hf_index, ett_mms_GetAlarmEnrollmentSummary_Request);
return offset;
}
static int
dissect_mms_T_rangeStartSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_rangeStartSpecification_choice, hf_index, ett_mms_T_rangeStartSpecification,
NULL);
return offset;
}
static int
dissect_mms_T_rangeStopSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_rangeStopSpecification_choice, hf_index, ett_mms_T_rangeStopSpecification,
NULL);
return offset;
}
static int
dissect_mms_T_listOfVariables(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfVariables_sequence_of, hf_index, ett_mms_T_listOfVariables);
return offset;
}
static int
dissect_mms_T_entryToStartAfter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_entryToStartAfter_sequence, hf_index, ett_mms_T_entryToStartAfter);
return offset;
}
static int
dissect_mms_ReadJournal_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReadJournal_Request_sequence, hf_index, ett_mms_ReadJournal_Request);
return offset;
}
static int
dissect_mms_JOU_Additional_Detail(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_event(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_event_sequence, hf_index, ett_mms_T_event);
return offset;
}
static int
dissect_mms_T_listOfVariables_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_listOfVariables_item_sequence, hf_index, ett_mms_T_listOfVariables_item);
return offset;
}
static int
dissect_mms_T_listOfVariables_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfVariables_01_sequence_of, hf_index, ett_mms_T_listOfVariables_01);
return offset;
}
static int
dissect_mms_T_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_data_sequence, hf_index, ett_mms_T_data);
return offset;
}
static int
dissect_mms_T_entryForm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_entryForm_choice, hf_index, ett_mms_T_entryForm,
NULL);
return offset;
}
static int
dissect_mms_EntryContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EntryContent_sequence, hf_index, ett_mms_EntryContent);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_EntryContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_EntryContent_sequence_of, hf_index, ett_mms_SEQUENCE_OF_EntryContent);
return offset;
}
static int
dissect_mms_WriteJournal_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
WriteJournal_Request_sequence, hf_index, ett_mms_WriteJournal_Request);
return offset;
}
static int
dissect_mms_T_limitSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_limitSpecification_sequence, hf_index, ett_mms_T_limitSpecification);
return offset;
}
static int
dissect_mms_InitializeJournal_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitializeJournal_Request_sequence, hf_index, ett_mms_InitializeJournal_Request);
return offset;
}
static int
dissect_mms_ReportJournalStatus_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ObjectName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_CreateJournal_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CreateJournal_Request_sequence, hf_index, ett_mms_CreateJournal_Request);
return offset;
}
static int
dissect_mms_DeleteJournal_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteJournal_Request_sequence, hf_index, ett_mms_DeleteJournal_Request);
return offset;
}
static int
dissect_mms_GetCapabilityList_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetCapabilityList_Request_sequence, hf_index, ett_mms_GetCapabilityList_Request);
return offset;
}
static int
dissect_mms_FileOpen_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileOpen_Request_sequence, hf_index, ett_mms_FileOpen_Request);
return offset;
}
static int
dissect_mms_FileRead_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Integer32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_FileClose_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Integer32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_FileRename_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileRename_Request_sequence, hf_index, ett_mms_FileRename_Request);
return offset;
}
static int
dissect_mms_FileDelete_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_FileName(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_FileDirectory_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileDirectory_Request_sequence, hf_index, ett_mms_FileDirectory_Request);
return offset;
}
static int
dissect_mms_ConfirmedServiceRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConfirmedServiceRequest_choice, hf_index, ett_mms_ConfirmedServiceRequest,
NULL);
return offset;
}
static int
dissect_mms_CS_Request_Detail(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CS_Request_Detail_choice, hf_index, ett_mms_CS_Request_Detail,
NULL);
return offset;
}
static int
dissect_mms_Confirmed_RequestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Confirmed_RequestPDU_sequence, hf_index, ett_mms_Confirmed_RequestPDU);
return offset;
}
static int
dissect_mms_T_vmdLogicalStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_vmdPhysicalStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_BIT_STRING_SIZE_0_128(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_mms_Status_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Status_Response_sequence, hf_index, ett_mms_Status_Response);
return offset;
}
static int
dissect_mms_GetNameList_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetNameList_Response_sequence, hf_index, ett_mms_GetNameList_Response);
return offset;
}
static int
dissect_mms_T_listOfAbstractSyntaxes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfAbstractSyntaxes_sequence_of, hf_index, ett_mms_T_listOfAbstractSyntaxes);
return offset;
}
static int
dissect_mms_Identify_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Identify_Response_sequence, hf_index, ett_mms_Identify_Response);
return offset;
}
static int
dissect_mms_Rename_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DataAccessError(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_AccessResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AccessResult_choice, hf_index, ett_mms_AccessResult,
NULL);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_AccessResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AccessResult_sequence_of, hf_index, ett_mms_SEQUENCE_OF_AccessResult);
return offset;
}
static int
dissect_mms_Read_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Read_Response_sequence, hf_index, ett_mms_Read_Response);
return offset;
}
static int
dissect_mms_Write_Response_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Write_Response_item_choice, hf_index, ett_mms_Write_Response_item,
NULL);
return offset;
}
static int
dissect_mms_Write_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Write_Response_sequence_of, hf_index, ett_mms_Write_Response);
return offset;
}
static int
dissect_mms_GetVariableAccessAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetVariableAccessAttributes_Response_sequence, hf_index, ett_mms_GetVariableAccessAttributes_Response);
return offset;
}
static int
dissect_mms_DefineNamedVariable_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DefineScatteredAccess_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_GetScatteredAccessAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetScatteredAccessAttributes_Response_sequence, hf_index, ett_mms_GetScatteredAccessAttributes_Response);
return offset;
}
static int
dissect_mms_DeleteVariableAccess_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteVariableAccess_Response_sequence, hf_index, ett_mms_DeleteVariableAccess_Response);
return offset;
}
static int
dissect_mms_DefineNamedVariableList_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_listOfVariable_item_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_item_01_sequence, hf_index, ett_mms_T_listOfVariable_item_01);
return offset;
}
static int
dissect_mms_T_listOfVariable_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfVariable_01_sequence_of, hf_index, ett_mms_T_listOfVariable_01);
return offset;
}
static int
dissect_mms_GetNamedVariableListAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetNamedVariableListAttributes_Response_sequence, hf_index, ett_mms_GetNamedVariableListAttributes_Response);
return offset;
}
static int
dissect_mms_DeleteNamedVariableList_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteNamedVariableList_Response_sequence, hf_index, ett_mms_DeleteNamedVariableList_Response);
return offset;
}
static int
dissect_mms_DefineNamedType_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_GetNamedTypeAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetNamedTypeAttributes_Response_sequence, hf_index, ett_mms_GetNamedTypeAttributes_Response);
return offset;
}
static int
dissect_mms_DeleteNamedType_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DeleteNamedType_Response_sequence, hf_index, ett_mms_DeleteNamedType_Response);
return offset;
}
static int
dissect_mms_Input_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VisibleString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Output_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_TakeControl_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
TakeControl_Response_choice, hf_index, ett_mms_TakeControl_Response,
NULL);
return offset;
}
static int
dissect_mms_RelinquishControl_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DefineSemaphore_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteSemaphore_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_class(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_ReportSemaphoreStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportSemaphoreStatus_Response_sequence, hf_index, ett_mms_ReportSemaphoreStatus_Response);
return offset;
}
static int
dissect_mms_T_listOfNamedTokens_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_listOfNamedTokens_item_choice, hf_index, ett_mms_T_listOfNamedTokens_item,
NULL);
return offset;
}
static int
dissect_mms_T_listOfNamedTokens(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfNamedTokens_sequence_of, hf_index, ett_mms_T_listOfNamedTokens);
return offset;
}
static int
dissect_mms_ReportPoolSemaphoreStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportPoolSemaphoreStatus_Response_sequence, hf_index, ett_mms_ReportPoolSemaphoreStatus_Response);
return offset;
}
static int
dissect_mms_T_entryClass(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_SemaphoreEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SemaphoreEntry_sequence, hf_index, ett_mms_SemaphoreEntry);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_SemaphoreEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_SemaphoreEntry_sequence_of, hf_index, ett_mms_SEQUENCE_OF_SemaphoreEntry);
return offset;
}
static int
dissect_mms_ReportSemaphoreEntryStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportSemaphoreEntryStatus_Response_sequence, hf_index, ett_mms_ReportSemaphoreEntryStatus_Response);
return offset;
}
static int
dissect_mms_InitiateDownloadSequence_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_loadData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_loadData_choice, hf_index, ett_mms_T_loadData,
NULL);
return offset;
}
static int
dissect_mms_DownloadSegment_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DownloadSegment_Response_sequence, hf_index, ett_mms_DownloadSegment_Response);
return offset;
}
static int
dissect_mms_TerminateDownloadSequence_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_listOfCapabilities_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_02_sequence_of, hf_index, ett_mms_T_listOfCapabilities_02);
return offset;
}
static int
dissect_mms_InitiateUploadSequence_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitiateUploadSequence_Response_sequence, hf_index, ett_mms_InitiateUploadSequence_Response);
return offset;
}
static int
dissect_mms_T_loadData_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_loadData_01_choice, hf_index, ett_mms_T_loadData_01,
NULL);
return offset;
}
static int
dissect_mms_UploadSegment_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
UploadSegment_Response_sequence, hf_index, ett_mms_UploadSegment_Response);
return offset;
}
static int
dissect_mms_TerminateUploadSequence_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_RequestDomainDownload_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_RequestDomainUpload_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_LoadDomainContent_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_StoreDomainContent_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteDomain_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_listOfCapabilities_05(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_05_sequence_of, hf_index, ett_mms_T_listOfCapabilities_05);
return offset;
}
static int
dissect_mms_DomainState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_Integer8(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_GetDomainAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetDomainAttributes_Response_sequence, hf_index, ett_mms_GetDomainAttributes_Response);
return offset;
}
static int
dissect_mms_CreateProgramInvocation_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteProgramInvocation_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Start_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Stop_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Resume_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Reset_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Kill_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_executionArgument_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_executionArgument_02_choice, hf_index, ett_mms_T_executionArgument_02,
NULL);
return offset;
}
static int
dissect_mms_GetProgramInvocationAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetProgramInvocationAttributes_Response_sequence, hf_index, ett_mms_GetProgramInvocationAttributes_Response);
return offset;
}
static int
dissect_mms_ObtainFile_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_GeneralizedTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_FileAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileAttributes_sequence, hf_index, ett_mms_FileAttributes);
return offset;
}
static int
dissect_mms_FileOpen_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileOpen_Response_sequence, hf_index, ett_mms_FileOpen_Response);
return offset;
}
static int
dissect_mms_DefineEventCondition_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteEventCondition_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_monitoredVariable(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_monitoredVariable_choice, hf_index, ett_mms_T_monitoredVariable,
NULL);
return offset;
}
static int
dissect_mms_GetEventConditionAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetEventConditionAttributes_Response_sequence, hf_index, ett_mms_GetEventConditionAttributes_Response);
return offset;
}
static int
dissect_mms_ReportEventConditionStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportEventConditionStatus_Response_sequence, hf_index, ett_mms_ReportEventConditionStatus_Response);
return offset;
}
static int
dissect_mms_AlterEventConditionMonitoring_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_TriggerEvent_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DefineEventAction_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteEventAction_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_GetEventActionAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetEventActionAttributes_Response_sequence, hf_index, ett_mms_GetEventActionAttributes_Response);
return offset;
}
static int
dissect_mms_ReportEventActionStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_DefineEventEnrollment_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteEventEnrollment_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_EE_State(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_currentState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_currentState_choice, hf_index, ett_mms_T_currentState,
NULL);
return offset;
}
static int
dissect_mms_AlterEventEnrollment_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlterEventEnrollment_Response_sequence, hf_index, ett_mms_AlterEventEnrollment_Response);
return offset;
}
static int
dissect_mms_EE_Duration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_ReportEventEnrollmentStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportEventEnrollmentStatus_Response_sequence, hf_index, ett_mms_ReportEventEnrollmentStatus_Response);
return offset;
}
static int
dissect_mms_T_eventConditionName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_eventConditionName_choice, hf_index, ett_mms_T_eventConditionName,
NULL);
return offset;
}
static int
dissect_mms_T_eventActionName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_eventActionName_choice, hf_index, ett_mms_T_eventActionName,
NULL);
return offset;
}
static int
dissect_mms_EE_Class(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_EventEnrollment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventEnrollment_sequence, hf_index, ett_mms_EventEnrollment);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_EventEnrollment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_EventEnrollment_sequence_of, hf_index, ett_mms_SEQUENCE_OF_EventEnrollment);
return offset;
}
static int
dissect_mms_GetEventEnrollmentAttributes_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetEventEnrollmentAttributes_Response_sequence, hf_index, ett_mms_GetEventEnrollmentAttributes_Response);
return offset;
}
static int
dissect_mms_AcknowledgeEventNotification_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_unacknowledgedState(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_AlarmSummary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlarmSummary_sequence, hf_index, ett_mms_AlarmSummary);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_AlarmSummary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AlarmSummary_sequence_of, hf_index, ett_mms_SEQUENCE_OF_AlarmSummary);
return offset;
}
static int
dissect_mms_GetAlarmSummary_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetAlarmSummary_Response_sequence, hf_index, ett_mms_GetAlarmSummary_Response);
return offset;
}
static int
dissect_mms_AlarmEnrollmentSummary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AlarmEnrollmentSummary_sequence, hf_index, ett_mms_AlarmEnrollmentSummary);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_AlarmEnrollmentSummary(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AlarmEnrollmentSummary_sequence_of, hf_index, ett_mms_SEQUENCE_OF_AlarmEnrollmentSummary);
return offset;
}
static int
dissect_mms_GetAlarmEnrollmentSummary_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetAlarmEnrollmentSummary_Response_sequence, hf_index, ett_mms_GetAlarmEnrollmentSummary_Response);
return offset;
}
static int
dissect_mms_JournalEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
JournalEntry_sequence, hf_index, ett_mms_JournalEntry);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_JournalEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_JournalEntry_sequence_of, hf_index, ett_mms_SEQUENCE_OF_JournalEntry);
return offset;
}
static int
dissect_mms_ReadJournal_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReadJournal_Response_sequence, hf_index, ett_mms_ReadJournal_Response);
return offset;
}
static int
dissect_mms_WriteJournal_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_InitializeJournal_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_ReportJournalStatus_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ReportJournalStatus_Response_sequence, hf_index, ett_mms_ReportJournalStatus_Response);
return offset;
}
static int
dissect_mms_CreateJournal_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DeleteJournal_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_T_listOfCapabilities(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_listOfCapabilities_sequence_of, hf_index, ett_mms_T_listOfCapabilities);
return offset;
}
static int
dissect_mms_GetCapabilityList_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
GetCapabilityList_Response_sequence, hf_index, ett_mms_GetCapabilityList_Response);
return offset;
}
static int
dissect_mms_FileRead_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileRead_Response_sequence, hf_index, ett_mms_FileRead_Response);
return offset;
}
static int
dissect_mms_FileClose_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_FileRename_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_FileDelete_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_DirectoryEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DirectoryEntry_sequence, hf_index, ett_mms_DirectoryEntry);
return offset;
}
static int
dissect_mms_SEQUENCE_OF_DirectoryEntry(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_DirectoryEntry_sequence_of, hf_index, ett_mms_SEQUENCE_OF_DirectoryEntry);
return offset;
}
static int
dissect_mms_FileDirectory_Response(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileDirectory_Response_sequence, hf_index, ett_mms_FileDirectory_Response);
return offset;
}
static int
dissect_mms_ConfirmedServiceResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ConfirmedServiceResponse_choice, hf_index, ett_mms_ConfirmedServiceResponse,
NULL);
return offset;
}
static int
dissect_mms_Confirmed_ResponsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Confirmed_ResponsePDU_sequence, hf_index, ett_mms_Confirmed_ResponsePDU);
return offset;
}
static int
dissect_mms_Confirmed_ErrorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Confirmed_ErrorPDU_sequence, hf_index, ett_mms_Confirmed_ErrorPDU);
return offset;
}
static int
dissect_mms_InformationReport(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InformationReport_sequence, hf_index, ett_mms_InformationReport);
return offset;
}
static int
dissect_mms_UnsolicitedStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Status_Response(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_T_eventConditionName_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_eventConditionName_01_choice, hf_index, ett_mms_T_eventConditionName_01,
NULL);
return offset;
}
static int
dissect_mms_T_eventActionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_eventActionResult_choice, hf_index, ett_mms_T_eventActionResult,
NULL);
return offset;
}
static int
dissect_mms_T_actionResult(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_actionResult_sequence, hf_index, ett_mms_T_actionResult);
return offset;
}
static int
dissect_mms_EventNotification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EventNotification_sequence, hf_index, ett_mms_EventNotification);
return offset;
}
static int
dissect_mms_UnconfirmedService(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
UnconfirmedService_choice, hf_index, ett_mms_UnconfirmedService,
NULL);
return offset;
}
static int
dissect_mms_Unconfirmed_PDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Unconfirmed_PDU_sequence, hf_index, ett_mms_Unconfirmed_PDU);
return offset;
}
static int
dissect_mms_T_confirmed_requestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_confirmed_responsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_confirmed_errorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_unconfirmedPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_pdu_error(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_cancel_requestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_cancel_responsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_cancel_errorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_conclude_requestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_conclude_responsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_conclude_errorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_T_rejectReason(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_rejectReason_choice, hf_index, ett_mms_T_rejectReason,
NULL);
return offset;
}
static int
dissect_mms_RejectPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RejectPDU_sequence, hf_index, ett_mms_RejectPDU);
return offset;
}
static int
dissect_mms_Cancel_RequestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Cancel_ResponsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_Unsigned32(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Cancel_ErrorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Cancel_ErrorPDU_sequence, hf_index, ett_mms_Cancel_ErrorPDU);
return offset;
}
static int
dissect_mms_Integer16(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_mms_ParameterSupportOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ParameterSupportOptions_bits, hf_index, ett_mms_ParameterSupportOptions,
NULL);
return offset;
}
static int
dissect_mms_ServiceSupportOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
ServiceSupportOptions_bits, hf_index, ett_mms_ServiceSupportOptions,
NULL);
return offset;
}
static int
dissect_mms_InitRequestDetail(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitRequestDetail_sequence, hf_index, ett_mms_InitRequestDetail);
return offset;
}
static int
dissect_mms_Initiate_RequestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Initiate_RequestPDU_sequence, hf_index, ett_mms_Initiate_RequestPDU);
return offset;
}
static int
dissect_mms_InitResponseDetail(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InitResponseDetail_sequence, hf_index, ett_mms_InitResponseDetail);
return offset;
}
static int
dissect_mms_Initiate_ResponsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Initiate_ResponsePDU_sequence, hf_index, ett_mms_Initiate_ResponsePDU);
return offset;
}
static int
dissect_mms_Initiate_ErrorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ServiceError(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_mms_Conclude_RequestPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Conclude_ResponsePDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_mms_Conclude_ErrorPDU(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_mms_ServiceError(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_mms_MMSpdu(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 37 "../../asn1/mms/mms.cnf"
gint branch_taken;
offset = dissect_ber_choice(actx, tree, tvb, offset,
MMSpdu_choice, hf_index, ett_mms_MMSpdu,
&branch_taken);
if( (branch_taken!=-1) && mms_MMSpdu_vals[branch_taken].strptr ){
col_append_fstr(actx->pinfo->cinfo, COL_INFO, "%s ", mms_MMSpdu_vals[branch_taken].strptr);
}
return offset;
}
static void
dissect_mms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_mms, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mms);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MMS");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_mms_MMSpdu(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte MMS PDU");
break;
}
}
}
void proto_register_mms(void) {
static hf_register_info hf[] =
{
#line 1 "../../asn1/mms/packet-mms-hfarr.c"
{ &hf_mms_confirmed_RequestPDU,
{ "confirmed-RequestPDU", "mms.confirmed_RequestPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_confirmed_ResponsePDU,
{ "confirmed-ResponsePDU", "mms.confirmed_ResponsePDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_confirmed_ErrorPDU,
{ "confirmed-ErrorPDU", "mms.confirmed_ErrorPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_unconfirmed_PDU,
{ "unconfirmed-PDU", "mms.unconfirmed_PDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_rejectPDU,
{ "rejectPDU", "mms.rejectPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_cancel_RequestPDU,
{ "cancel-RequestPDU", "mms.cancel_RequestPDU",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_cancel_ResponsePDU,
{ "cancel-ResponsePDU", "mms.cancel_ResponsePDU",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_cancel_ErrorPDU,
{ "cancel-ErrorPDU", "mms.cancel_ErrorPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_initiate_RequestPDU,
{ "initiate-RequestPDU", "mms.initiate_RequestPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_initiate_ResponsePDU,
{ "initiate-ResponsePDU", "mms.initiate_ResponsePDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_initiate_ErrorPDU,
{ "initiate-ErrorPDU", "mms.initiate_ErrorPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_conclude_RequestPDU,
{ "conclude-RequestPDU", "mms.conclude_RequestPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_conclude_ResponsePDU,
{ "conclude-ResponsePDU", "mms.conclude_ResponsePDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_conclude_ErrorPDU,
{ "conclude-ErrorPDU", "mms.conclude_ErrorPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_invokeID,
{ "invokeID", "mms.invokeID",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_listOfModifier,
{ "listOfModifier", "mms.listOfModifier",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Modifier", HFILL }},
{ &hf_mms_listOfModifier_item,
{ "Modifier", "mms.Modifier",
FT_UINT32, BASE_DEC, VALS(mms_Modifier_vals), 0,
NULL, HFILL }},
{ &hf_mms_confirmedServiceRequest,
{ "confirmedServiceRequest", "mms.confirmedServiceRequest",
FT_UINT32, BASE_DEC, VALS(mms_ConfirmedServiceRequest_vals), 0,
NULL, HFILL }},
{ &hf_mms_cs_request_detail,
{ "cs-request-detail", "mms.cs_request_detail",
FT_UINT32, BASE_DEC, VALS(mms_CS_Request_Detail_vals), 0,
NULL, HFILL }},
{ &hf_mms_unconfirmedService,
{ "unconfirmedService", "mms.unconfirmedService",
FT_UINT32, BASE_DEC, VALS(mms_UnconfirmedService_vals), 0,
NULL, HFILL }},
{ &hf_mms_confirmedServiceResponse,
{ "confirmedServiceResponse", "mms.confirmedServiceResponse",
FT_UINT32, BASE_DEC, VALS(mms_ConfirmedServiceResponse_vals), 0,
NULL, HFILL }},
{ &hf_mms_modifierPosition,
{ "modifierPosition", "mms.modifierPosition",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_serviceError,
{ "serviceError", "mms.serviceError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_informationReport,
{ "informationReport", "mms.informationReport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_unsolicitedStatus,
{ "unsolicitedStatus", "mms.unsolicitedStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_eventNotification,
{ "eventNotification", "mms.eventNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_attach_To_Event_Condition,
{ "attach-To-Event-Condition", "mms.attach_To_Event_Condition_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttachToEventCondition", HFILL }},
{ &hf_mms_attach_To_Semaphore,
{ "attach-To-Semaphore", "mms.attach_To_Semaphore_element",
FT_NONE, BASE_NONE, NULL, 0,
"AttachToSemaphore", HFILL }},
{ &hf_mms_status,
{ "status", "mms.status",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"Status_Request", HFILL }},
{ &hf_mms_getNameList,
{ "getNameList", "mms.getNameList_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetNameList_Request", HFILL }},
{ &hf_mms_identify,
{ "identify", "mms.identify_element",
FT_NONE, BASE_NONE, NULL, 0,
"Identify_Request", HFILL }},
{ &hf_mms_rename,
{ "rename", "mms.rename_element",
FT_NONE, BASE_NONE, NULL, 0,
"Rename_Request", HFILL }},
{ &hf_mms_read,
{ "read", "mms.read_element",
FT_NONE, BASE_NONE, NULL, 0,
"Read_Request", HFILL }},
{ &hf_mms_write,
{ "write", "mms.write_element",
FT_NONE, BASE_NONE, NULL, 0,
"Write_Request", HFILL }},
{ &hf_mms_getVariableAccessAttributes,
{ "getVariableAccessAttributes", "mms.getVariableAccessAttributes",
FT_UINT32, BASE_DEC, VALS(mms_GetVariableAccessAttributes_Request_vals), 0,
"GetVariableAccessAttributes_Request", HFILL }},
{ &hf_mms_defineNamedVariable,
{ "defineNamedVariable", "mms.defineNamedVariable_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedVariable_Request", HFILL }},
{ &hf_mms_defineScatteredAccess,
{ "defineScatteredAccess", "mms.defineScatteredAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineScatteredAccess_Request", HFILL }},
{ &hf_mms_getScatteredAccessAttributes,
{ "getScatteredAccessAttributes", "mms.getScatteredAccessAttributes",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"GetScatteredAccessAttributes_Request", HFILL }},
{ &hf_mms_deleteVariableAccess,
{ "deleteVariableAccess", "mms.deleteVariableAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteVariableAccess_Request", HFILL }},
{ &hf_mms_defineNamedVariableList,
{ "defineNamedVariableList", "mms.defineNamedVariableList_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedVariableList_Request", HFILL }},
{ &hf_mms_getNamedVariableListAttributes,
{ "getNamedVariableListAttributes", "mms.getNamedVariableListAttributes",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"GetNamedVariableListAttributes_Request", HFILL }},
{ &hf_mms_deleteNamedVariableList,
{ "deleteNamedVariableList", "mms.deleteNamedVariableList_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteNamedVariableList_Request", HFILL }},
{ &hf_mms_defineNamedType,
{ "defineNamedType", "mms.defineNamedType_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedType_Request", HFILL }},
{ &hf_mms_getNamedTypeAttributes,
{ "getNamedTypeAttributes", "mms.getNamedTypeAttributes",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"GetNamedTypeAttributes_Request", HFILL }},
{ &hf_mms_deleteNamedType,
{ "deleteNamedType", "mms.deleteNamedType_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteNamedType_Request", HFILL }},
{ &hf_mms_input,
{ "input", "mms.input_element",
FT_NONE, BASE_NONE, NULL, 0,
"Input_Request", HFILL }},
{ &hf_mms_output,
{ "output", "mms.output_element",
FT_NONE, BASE_NONE, NULL, 0,
"Output_Request", HFILL }},
{ &hf_mms_takeControl,
{ "takeControl", "mms.takeControl_element",
FT_NONE, BASE_NONE, NULL, 0,
"TakeControl_Request", HFILL }},
{ &hf_mms_relinquishControl,
{ "relinquishControl", "mms.relinquishControl_element",
FT_NONE, BASE_NONE, NULL, 0,
"RelinquishControl_Request", HFILL }},
{ &hf_mms_defineSemaphore,
{ "defineSemaphore", "mms.defineSemaphore_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineSemaphore_Request", HFILL }},
{ &hf_mms_deleteSemaphore,
{ "deleteSemaphore", "mms.deleteSemaphore",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"DeleteSemaphore_Request", HFILL }},
{ &hf_mms_reportSemaphoreStatus,
{ "reportSemaphoreStatus", "mms.reportSemaphoreStatus",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ReportSemaphoreStatus_Request", HFILL }},
{ &hf_mms_reportPoolSemaphoreStatus,
{ "reportPoolSemaphoreStatus", "mms.reportPoolSemaphoreStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportPoolSemaphoreStatus_Request", HFILL }},
{ &hf_mms_reportSemaphoreEntryStatus,
{ "reportSemaphoreEntryStatus", "mms.reportSemaphoreEntryStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportSemaphoreEntryStatus_Request", HFILL }},
{ &hf_mms_initiateDownloadSequence,
{ "initiateDownloadSequence", "mms.initiateDownloadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiateDownloadSequence_Request", HFILL }},
{ &hf_mms_downloadSegment,
{ "downloadSegment", "mms.downloadSegment",
FT_STRING, BASE_NONE, NULL, 0,
"DownloadSegment_Request", HFILL }},
{ &hf_mms_terminateDownloadSequence,
{ "terminateDownloadSequence", "mms.terminateDownloadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateDownloadSequence_Request", HFILL }},
{ &hf_mms_initiateUploadSequence,
{ "initiateUploadSequence", "mms.initiateUploadSequence",
FT_STRING, BASE_NONE, NULL, 0,
"InitiateUploadSequence_Request", HFILL }},
{ &hf_mms_uploadSegment,
{ "uploadSegment", "mms.uploadSegment",
FT_INT32, BASE_DEC, NULL, 0,
"UploadSegment_Request", HFILL }},
{ &hf_mms_terminateUploadSequence,
{ "terminateUploadSequence", "mms.terminateUploadSequence",
FT_INT32, BASE_DEC, NULL, 0,
"TerminateUploadSequence_Request", HFILL }},
{ &hf_mms_requestDomainDownload,
{ "requestDomainDownload", "mms.requestDomainDownload_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestDomainDownload_Request", HFILL }},
{ &hf_mms_requestDomainUpload,
{ "requestDomainUpload", "mms.requestDomainUpload_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestDomainUpload_Request", HFILL }},
{ &hf_mms_loadDomainContent,
{ "loadDomainContent", "mms.loadDomainContent_element",
FT_NONE, BASE_NONE, NULL, 0,
"LoadDomainContent_Request", HFILL }},
{ &hf_mms_storeDomainContent,
{ "storeDomainContent", "mms.storeDomainContent_element",
FT_NONE, BASE_NONE, NULL, 0,
"StoreDomainContent_Request", HFILL }},
{ &hf_mms_deleteDomain,
{ "deleteDomain", "mms.deleteDomain",
FT_STRING, BASE_NONE, NULL, 0,
"DeleteDomain_Request", HFILL }},
{ &hf_mms_getDomainAttributes,
{ "getDomainAttributes", "mms.getDomainAttributes",
FT_STRING, BASE_NONE, NULL, 0,
"GetDomainAttributes_Request", HFILL }},
{ &hf_mms_createProgramInvocation,
{ "createProgramInvocation", "mms.createProgramInvocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CreateProgramInvocation_Request", HFILL }},
{ &hf_mms_deleteProgramInvocation,
{ "deleteProgramInvocation", "mms.deleteProgramInvocation",
FT_STRING, BASE_NONE, NULL, 0,
"DeleteProgramInvocation_Request", HFILL }},
{ &hf_mms_start,
{ "start", "mms.start_element",
FT_NONE, BASE_NONE, NULL, 0,
"Start_Request", HFILL }},
{ &hf_mms_stop,
{ "stop", "mms.stop_element",
FT_NONE, BASE_NONE, NULL, 0,
"Stop_Request", HFILL }},
{ &hf_mms_resume,
{ "resume", "mms.resume_element",
FT_NONE, BASE_NONE, NULL, 0,
"Resume_Request", HFILL }},
{ &hf_mms_reset,
{ "reset", "mms.reset_element",
FT_NONE, BASE_NONE, NULL, 0,
"Reset_Request", HFILL }},
{ &hf_mms_kill,
{ "kill", "mms.kill_element",
FT_NONE, BASE_NONE, NULL, 0,
"Kill_Request", HFILL }},
{ &hf_mms_getProgramInvocationAttributes,
{ "getProgramInvocationAttributes", "mms.getProgramInvocationAttributes",
FT_STRING, BASE_NONE, NULL, 0,
"GetProgramInvocationAttributes_Request", HFILL }},
{ &hf_mms_obtainFile,
{ "obtainFile", "mms.obtainFile_element",
FT_NONE, BASE_NONE, NULL, 0,
"ObtainFile_Request", HFILL }},
{ &hf_mms_defineEventCondition,
{ "defineEventCondition", "mms.defineEventCondition_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventCondition_Request", HFILL }},
{ &hf_mms_deleteEventCondition,
{ "deleteEventCondition", "mms.deleteEventCondition",
FT_UINT32, BASE_DEC, VALS(mms_DeleteEventCondition_Request_vals), 0,
"DeleteEventCondition_Request", HFILL }},
{ &hf_mms_getEventConditionAttributes,
{ "getEventConditionAttributes", "mms.getEventConditionAttributes",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"GetEventConditionAttributes_Request", HFILL }},
{ &hf_mms_reportEventConditionStatus,
{ "reportEventConditionStatus", "mms.reportEventConditionStatus",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ReportEventConditionStatus_Request", HFILL }},
{ &hf_mms_alterEventConditionMonitoring,
{ "alterEventConditionMonitoring", "mms.alterEventConditionMonitoring_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlterEventConditionMonitoring_Request", HFILL }},
{ &hf_mms_triggerEvent,
{ "triggerEvent", "mms.triggerEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
"TriggerEvent_Request", HFILL }},
{ &hf_mms_defineEventAction,
{ "defineEventAction", "mms.defineEventAction_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventAction_Request", HFILL }},
{ &hf_mms_deleteEventAction,
{ "deleteEventAction", "mms.deleteEventAction",
FT_UINT32, BASE_DEC, VALS(mms_DeleteEventAction_Request_vals), 0,
"DeleteEventAction_Request", HFILL }},
{ &hf_mms_getEventActionAttributes,
{ "getEventActionAttributes", "mms.getEventActionAttributes",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"GetEventActionAttributes_Request", HFILL }},
{ &hf_mms_reportEventActionStatus,
{ "reportEventActionStatus", "mms.reportEventActionStatus",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ReportEventActionStatus_Request", HFILL }},
{ &hf_mms_defineEventEnrollment,
{ "defineEventEnrollment", "mms.defineEventEnrollment_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventEnrollment_Request", HFILL }},
{ &hf_mms_deleteEventEnrollment,
{ "deleteEventEnrollment", "mms.deleteEventEnrollment",
FT_UINT32, BASE_DEC, VALS(mms_DeleteEventEnrollment_Request_vals), 0,
"DeleteEventEnrollment_Request", HFILL }},
{ &hf_mms_alterEventEnrollment,
{ "alterEventEnrollment", "mms.alterEventEnrollment_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlterEventEnrollment_Request", HFILL }},
{ &hf_mms_reportEventEnrollmentStatus,
{ "reportEventEnrollmentStatus", "mms.reportEventEnrollmentStatus",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ReportEventEnrollmentStatus_Request", HFILL }},
{ &hf_mms_getEventEnrollmentAttributes,
{ "getEventEnrollmentAttributes", "mms.getEventEnrollmentAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetEventEnrollmentAttributes_Request", HFILL }},
{ &hf_mms_acknowledgeEventNotification,
{ "acknowledgeEventNotification", "mms.acknowledgeEventNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
"AcknowledgeEventNotification_Request", HFILL }},
{ &hf_mms_getAlarmSummary,
{ "getAlarmSummary", "mms.getAlarmSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetAlarmSummary_Request", HFILL }},
{ &hf_mms_getAlarmEnrollmentSummary,
{ "getAlarmEnrollmentSummary", "mms.getAlarmEnrollmentSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetAlarmEnrollmentSummary_Request", HFILL }},
{ &hf_mms_readJournal,
{ "readJournal", "mms.readJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadJournal_Request", HFILL }},
{ &hf_mms_writeJournal,
{ "writeJournal", "mms.writeJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"WriteJournal_Request", HFILL }},
{ &hf_mms_initializeJournal,
{ "initializeJournal", "mms.initializeJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitializeJournal_Request", HFILL }},
{ &hf_mms_reportJournalStatus,
{ "reportJournalStatus", "mms.reportJournalStatus",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ReportJournalStatus_Request", HFILL }},
{ &hf_mms_createJournal,
{ "createJournal", "mms.createJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"CreateJournal_Request", HFILL }},
{ &hf_mms_deleteJournal,
{ "deleteJournal", "mms.deleteJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteJournal_Request", HFILL }},
{ &hf_mms_getCapabilityList,
{ "getCapabilityList", "mms.getCapabilityList_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetCapabilityList_Request", HFILL }},
{ &hf_mms_fileOpen,
{ "fileOpen", "mms.fileOpen_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileOpen_Request", HFILL }},
{ &hf_mms_fileRead,
{ "fileRead", "mms.fileRead",
FT_INT32, BASE_DEC, NULL, 0,
"FileRead_Request", HFILL }},
{ &hf_mms_fileClose,
{ "fileClose", "mms.fileClose",
FT_INT32, BASE_DEC, NULL, 0,
"FileClose_Request", HFILL }},
{ &hf_mms_fileRename,
{ "fileRename", "mms.fileRename_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileRename_Request", HFILL }},
{ &hf_mms_fileDelete,
{ "fileDelete", "mms.fileDelete",
FT_UINT32, BASE_DEC, NULL, 0,
"FileDelete_Request", HFILL }},
{ &hf_mms_fileDirectory,
{ "fileDirectory", "mms.fileDirectory_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileDirectory_Request", HFILL }},
{ &hf_mms_foo,
{ "foo", "mms.foo",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_mms_status_01,
{ "status", "mms.status_element",
FT_NONE, BASE_NONE, NULL, 0,
"Status_Response", HFILL }},
{ &hf_mms_getNameList_01,
{ "getNameList", "mms.getNameList_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetNameList_Response", HFILL }},
{ &hf_mms_identify_01,
{ "identify", "mms.identify_element",
FT_NONE, BASE_NONE, NULL, 0,
"Identify_Response", HFILL }},
{ &hf_mms_rename_01,
{ "rename", "mms.rename_element",
FT_NONE, BASE_NONE, NULL, 0,
"Rename_Response", HFILL }},
{ &hf_mms_read_01,
{ "read", "mms.read_element",
FT_NONE, BASE_NONE, NULL, 0,
"Read_Response", HFILL }},
{ &hf_mms_write_01,
{ "write", "mms.write",
FT_UINT32, BASE_DEC, NULL, 0,
"Write_Response", HFILL }},
{ &hf_mms_getVariableAccessAttributes_01,
{ "getVariableAccessAttributes", "mms.getVariableAccessAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetVariableAccessAttributes_Response", HFILL }},
{ &hf_mms_defineNamedVariable_01,
{ "defineNamedVariable", "mms.defineNamedVariable_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedVariable_Response", HFILL }},
{ &hf_mms_defineScatteredAccess_01,
{ "defineScatteredAccess", "mms.defineScatteredAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineScatteredAccess_Response", HFILL }},
{ &hf_mms_getScatteredAccessAttributes_01,
{ "getScatteredAccessAttributes", "mms.getScatteredAccessAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetScatteredAccessAttributes_Response", HFILL }},
{ &hf_mms_deleteVariableAccess_01,
{ "deleteVariableAccess", "mms.deleteVariableAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteVariableAccess_Response", HFILL }},
{ &hf_mms_defineNamedVariableList_01,
{ "defineNamedVariableList", "mms.defineNamedVariableList_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedVariableList_Response", HFILL }},
{ &hf_mms_getNamedVariableListAttributes_01,
{ "getNamedVariableListAttributes", "mms.getNamedVariableListAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetNamedVariableListAttributes_Response", HFILL }},
{ &hf_mms_deleteNamedVariableList_01,
{ "deleteNamedVariableList", "mms.deleteNamedVariableList_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteNamedVariableList_Response", HFILL }},
{ &hf_mms_defineNamedType_01,
{ "defineNamedType", "mms.defineNamedType_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineNamedType_Response", HFILL }},
{ &hf_mms_getNamedTypeAttributes_01,
{ "getNamedTypeAttributes", "mms.getNamedTypeAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetNamedTypeAttributes_Response", HFILL }},
{ &hf_mms_deleteNamedType_01,
{ "deleteNamedType", "mms.deleteNamedType_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteNamedType_Response", HFILL }},
{ &hf_mms_input_01,
{ "input", "mms.input",
FT_STRING, BASE_NONE, NULL, 0,
"Input_Response", HFILL }},
{ &hf_mms_output_01,
{ "output", "mms.output_element",
FT_NONE, BASE_NONE, NULL, 0,
"Output_Response", HFILL }},
{ &hf_mms_takeControl_01,
{ "takeControl", "mms.takeControl",
FT_UINT32, BASE_DEC, VALS(mms_TakeControl_Response_vals), 0,
"TakeControl_Response", HFILL }},
{ &hf_mms_relinquishControl_01,
{ "relinquishControl", "mms.relinquishControl_element",
FT_NONE, BASE_NONE, NULL, 0,
"RelinquishControl_Response", HFILL }},
{ &hf_mms_defineSemaphore_01,
{ "defineSemaphore", "mms.defineSemaphore_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineSemaphore_Response", HFILL }},
{ &hf_mms_deleteSemaphore_01,
{ "deleteSemaphore", "mms.deleteSemaphore_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteSemaphore_Response", HFILL }},
{ &hf_mms_reportSemaphoreStatus_01,
{ "reportSemaphoreStatus", "mms.reportSemaphoreStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportSemaphoreStatus_Response", HFILL }},
{ &hf_mms_reportPoolSemaphoreStatus_01,
{ "reportPoolSemaphoreStatus", "mms.reportPoolSemaphoreStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportPoolSemaphoreStatus_Response", HFILL }},
{ &hf_mms_reportSemaphoreEntryStatus_01,
{ "reportSemaphoreEntryStatus", "mms.reportSemaphoreEntryStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportSemaphoreEntryStatus_Response", HFILL }},
{ &hf_mms_initiateDownloadSequence_01,
{ "initiateDownloadSequence", "mms.initiateDownloadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiateDownloadSequence_Response", HFILL }},
{ &hf_mms_downloadSegment_01,
{ "downloadSegment", "mms.downloadSegment_element",
FT_NONE, BASE_NONE, NULL, 0,
"DownloadSegment_Response", HFILL }},
{ &hf_mms_terminateDownloadSequence_01,
{ "terminateDownloadSequence", "mms.terminateDownloadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateDownloadSequence_Response", HFILL }},
{ &hf_mms_initiateUploadSequence_01,
{ "initiateUploadSequence", "mms.initiateUploadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiateUploadSequence_Response", HFILL }},
{ &hf_mms_uploadSegment_01,
{ "uploadSegment", "mms.uploadSegment_element",
FT_NONE, BASE_NONE, NULL, 0,
"UploadSegment_Response", HFILL }},
{ &hf_mms_terminateUploadSequence_01,
{ "terminateUploadSequence", "mms.terminateUploadSequence_element",
FT_NONE, BASE_NONE, NULL, 0,
"TerminateUploadSequence_Response", HFILL }},
{ &hf_mms_requestDomainDownLoad,
{ "requestDomainDownLoad", "mms.requestDomainDownLoad_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestDomainDownload_Response", HFILL }},
{ &hf_mms_requestDomainUpload_01,
{ "requestDomainUpload", "mms.requestDomainUpload_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestDomainUpload_Response", HFILL }},
{ &hf_mms_loadDomainContent_01,
{ "loadDomainContent", "mms.loadDomainContent_element",
FT_NONE, BASE_NONE, NULL, 0,
"LoadDomainContent_Response", HFILL }},
{ &hf_mms_storeDomainContent_01,
{ "storeDomainContent", "mms.storeDomainContent_element",
FT_NONE, BASE_NONE, NULL, 0,
"StoreDomainContent_Response", HFILL }},
{ &hf_mms_deleteDomain_01,
{ "deleteDomain", "mms.deleteDomain_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteDomain_Response", HFILL }},
{ &hf_mms_getDomainAttributes_01,
{ "getDomainAttributes", "mms.getDomainAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetDomainAttributes_Response", HFILL }},
{ &hf_mms_createProgramInvocation_01,
{ "createProgramInvocation", "mms.createProgramInvocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"CreateProgramInvocation_Response", HFILL }},
{ &hf_mms_deleteProgramInvocation_01,
{ "deleteProgramInvocation", "mms.deleteProgramInvocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteProgramInvocation_Response", HFILL }},
{ &hf_mms_start_01,
{ "start", "mms.start_element",
FT_NONE, BASE_NONE, NULL, 0,
"Start_Response", HFILL }},
{ &hf_mms_stop_01,
{ "stop", "mms.stop_element",
FT_NONE, BASE_NONE, NULL, 0,
"Stop_Response", HFILL }},
{ &hf_mms_resume_01,
{ "resume", "mms.resume_element",
FT_NONE, BASE_NONE, NULL, 0,
"Resume_Response", HFILL }},
{ &hf_mms_reset_01,
{ "reset", "mms.reset_element",
FT_NONE, BASE_NONE, NULL, 0,
"Reset_Response", HFILL }},
{ &hf_mms_kill_01,
{ "kill", "mms.kill_element",
FT_NONE, BASE_NONE, NULL, 0,
"Kill_Response", HFILL }},
{ &hf_mms_getProgramInvocationAttributes_01,
{ "getProgramInvocationAttributes", "mms.getProgramInvocationAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetProgramInvocationAttributes_Response", HFILL }},
{ &hf_mms_obtainFile_01,
{ "obtainFile", "mms.obtainFile_element",
FT_NONE, BASE_NONE, NULL, 0,
"ObtainFile_Response", HFILL }},
{ &hf_mms_fileOpen_01,
{ "fileOpen", "mms.fileOpen_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileOpen_Response", HFILL }},
{ &hf_mms_defineEventCondition_01,
{ "defineEventCondition", "mms.defineEventCondition_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventCondition_Response", HFILL }},
{ &hf_mms_deleteEventCondition_01,
{ "deleteEventCondition", "mms.deleteEventCondition",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteEventCondition_Response", HFILL }},
{ &hf_mms_getEventConditionAttributes_01,
{ "getEventConditionAttributes", "mms.getEventConditionAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetEventConditionAttributes_Response", HFILL }},
{ &hf_mms_reportEventConditionStatus_01,
{ "reportEventConditionStatus", "mms.reportEventConditionStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportEventConditionStatus_Response", HFILL }},
{ &hf_mms_alterEventConditionMonitoring_01,
{ "alterEventConditionMonitoring", "mms.alterEventConditionMonitoring_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlterEventConditionMonitoring_Response", HFILL }},
{ &hf_mms_triggerEvent_01,
{ "triggerEvent", "mms.triggerEvent_element",
FT_NONE, BASE_NONE, NULL, 0,
"TriggerEvent_Response", HFILL }},
{ &hf_mms_defineEventAction_01,
{ "defineEventAction", "mms.defineEventAction_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventAction_Response", HFILL }},
{ &hf_mms_deleteEventAction_01,
{ "deleteEventAction", "mms.deleteEventAction",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteEventAction_Response", HFILL }},
{ &hf_mms_getEventActionAttributes_01,
{ "getEventActionAttributes", "mms.getEventActionAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetEventActionAttributes_Response", HFILL }},
{ &hf_mms_reportActionStatus,
{ "reportActionStatus", "mms.reportActionStatus",
FT_INT32, BASE_DEC, NULL, 0,
"ReportEventActionStatus_Response", HFILL }},
{ &hf_mms_defineEventEnrollment_01,
{ "defineEventEnrollment", "mms.defineEventEnrollment_element",
FT_NONE, BASE_NONE, NULL, 0,
"DefineEventEnrollment_Response", HFILL }},
{ &hf_mms_deleteEventEnrollment_01,
{ "deleteEventEnrollment", "mms.deleteEventEnrollment",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteEventEnrollment_Response", HFILL }},
{ &hf_mms_alterEventEnrollment_01,
{ "alterEventEnrollment", "mms.alterEventEnrollment_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlterEventEnrollment_Response", HFILL }},
{ &hf_mms_reportEventEnrollmentStatus_01,
{ "reportEventEnrollmentStatus", "mms.reportEventEnrollmentStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportEventEnrollmentStatus_Response", HFILL }},
{ &hf_mms_getEventEnrollmentAttributes_01,
{ "getEventEnrollmentAttributes", "mms.getEventEnrollmentAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetEventEnrollmentAttributes_Response", HFILL }},
{ &hf_mms_acknowledgeEventNotification_01,
{ "acknowledgeEventNotification", "mms.acknowledgeEventNotification_element",
FT_NONE, BASE_NONE, NULL, 0,
"AcknowledgeEventNotification_Response", HFILL }},
{ &hf_mms_getAlarmSummary_01,
{ "getAlarmSummary", "mms.getAlarmSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetAlarmSummary_Response", HFILL }},
{ &hf_mms_getAlarmEnrollmentSummary_01,
{ "getAlarmEnrollmentSummary", "mms.getAlarmEnrollmentSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetAlarmEnrollmentSummary_Response", HFILL }},
{ &hf_mms_readJournal_01,
{ "readJournal", "mms.readJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReadJournal_Response", HFILL }},
{ &hf_mms_writeJournal_01,
{ "writeJournal", "mms.writeJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"WriteJournal_Response", HFILL }},
{ &hf_mms_initializeJournal_01,
{ "initializeJournal", "mms.initializeJournal",
FT_INT32, BASE_DEC, NULL, 0,
"InitializeJournal_Response", HFILL }},
{ &hf_mms_reportJournalStatus_01,
{ "reportJournalStatus", "mms.reportJournalStatus_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReportJournalStatus_Response", HFILL }},
{ &hf_mms_createJournal_01,
{ "createJournal", "mms.createJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"CreateJournal_Response", HFILL }},
{ &hf_mms_deleteJournal_01,
{ "deleteJournal", "mms.deleteJournal_element",
FT_NONE, BASE_NONE, NULL, 0,
"DeleteJournal_Response", HFILL }},
{ &hf_mms_getCapabilityList_01,
{ "getCapabilityList", "mms.getCapabilityList_element",
FT_NONE, BASE_NONE, NULL, 0,
"GetCapabilityList_Response", HFILL }},
{ &hf_mms_fileRead_01,
{ "fileRead", "mms.fileRead_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileRead_Response", HFILL }},
{ &hf_mms_fileClose_01,
{ "fileClose", "mms.fileClose_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileClose_Response", HFILL }},
{ &hf_mms_fileRename_01,
{ "fileRename", "mms.fileRename_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileRename_Response", HFILL }},
{ &hf_mms_fileDelete_01,
{ "fileDelete", "mms.fileDelete_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileDelete_Response", HFILL }},
{ &hf_mms_fileDirectory_01,
{ "fileDirectory", "mms.fileDirectory_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileDirectory_Response", HFILL }},
{ &hf_mms_FileName_item,
{ "FileName item", "mms.FileName_item",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_mms_vmd_specific,
{ "vmd-specific", "mms.vmd_specific",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_domain_specific,
{ "domain-specific", "mms.domain_specific_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_domainId,
{ "domainId", "mms.domainId",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_itemId,
{ "itemId", "mms.itemId",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_aa_specific,
{ "aa-specific", "mms.aa_specific",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_ap_title,
{ "ap-title", "mms.ap_title",
FT_UINT32, BASE_DEC, VALS(acse_AP_title_vals), 0,
NULL, HFILL }},
{ &hf_mms_ap_invocation_id,
{ "ap-invocation-id", "mms.ap_invocation_id",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_ae_qualifier,
{ "ae-qualifier", "mms.ae_qualifier",
FT_UINT32, BASE_DEC, VALS(acse_ASO_qualifier_vals), 0,
NULL, HFILL }},
{ &hf_mms_ae_invocation_id,
{ "ae-invocation-id", "mms.ae_invocation_id",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_localDetailCalling,
{ "localDetailCalling", "mms.localDetailCalling",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_proposedMaxServOutstandingCalling,
{ "proposedMaxServOutstandingCalling", "mms.proposedMaxServOutstandingCalling",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_proposedMaxServOutstandingCalled,
{ "proposedMaxServOutstandingCalled", "mms.proposedMaxServOutstandingCalled",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_proposedDataStructureNestingLevel,
{ "proposedDataStructureNestingLevel", "mms.proposedDataStructureNestingLevel",
FT_INT32, BASE_DEC, NULL, 0,
"Integer8", HFILL }},
{ &hf_mms_mmsInitRequestDetail,
{ "mmsInitRequestDetail", "mms.mmsInitRequestDetail_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitRequestDetail", HFILL }},
{ &hf_mms_proposedVersionNumber,
{ "proposedVersionNumber", "mms.proposedVersionNumber",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_proposedParameterCBB,
{ "proposedParameterCBB", "mms.proposedParameterCBB",
FT_BYTES, BASE_NONE, NULL, 0,
"ParameterSupportOptions", HFILL }},
{ &hf_mms_servicesSupportedCalling,
{ "servicesSupportedCalling", "mms.servicesSupportedCalling",
FT_BYTES, BASE_NONE, NULL, 0,
"ServiceSupportOptions", HFILL }},
{ &hf_mms_localDetailCalled,
{ "localDetailCalled", "mms.localDetailCalled",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_negociatedMaxServOutstandingCalling,
{ "negociatedMaxServOutstandingCalling", "mms.negociatedMaxServOutstandingCalling",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_negociatedMaxServOutstandingCalled,
{ "negociatedMaxServOutstandingCalled", "mms.negociatedMaxServOutstandingCalled",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_negociatedDataStructureNestingLevel,
{ "negociatedDataStructureNestingLevel", "mms.negociatedDataStructureNestingLevel",
FT_INT32, BASE_DEC, NULL, 0,
"Integer8", HFILL }},
{ &hf_mms_mmsInitResponseDetail,
{ "mmsInitResponseDetail", "mms.mmsInitResponseDetail_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitResponseDetail", HFILL }},
{ &hf_mms_negociatedVersionNumber,
{ "negociatedVersionNumber", "mms.negociatedVersionNumber",
FT_INT32, BASE_DEC, NULL, 0,
"Integer16", HFILL }},
{ &hf_mms_negociatedParameterCBB,
{ "negociatedParameterCBB", "mms.negociatedParameterCBB",
FT_BYTES, BASE_NONE, NULL, 0,
"ParameterSupportOptions", HFILL }},
{ &hf_mms_servicesSupportedCalled,
{ "servicesSupportedCalled", "mms.servicesSupportedCalled",
FT_BYTES, BASE_NONE, NULL, 0,
"ServiceSupportOptions", HFILL }},
{ &hf_mms_originalInvokeID,
{ "originalInvokeID", "mms.originalInvokeID",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_errorClass,
{ "errorClass", "mms.errorClass",
FT_UINT32, BASE_DEC, VALS(mms_T_errorClass_vals), 0,
NULL, HFILL }},
{ &hf_mms_vmd_state,
{ "vmd-state", "mms.vmd_state",
FT_INT32, BASE_DEC, VALS(mms_T_vmd_state_vals), 0,
NULL, HFILL }},
{ &hf_mms_application_reference,
{ "application-reference", "mms.application_reference",
FT_INT32, BASE_DEC, VALS(mms_T_application_reference_vals), 0,
NULL, HFILL }},
{ &hf_mms_definition,
{ "definition", "mms.definition",
FT_INT32, BASE_DEC, VALS(mms_T_definition_vals), 0,
NULL, HFILL }},
{ &hf_mms_resource,
{ "resource", "mms.resource",
FT_INT32, BASE_DEC, VALS(mms_T_resource_vals), 0,
NULL, HFILL }},
{ &hf_mms_service,
{ "service", "mms.service",
FT_INT32, BASE_DEC, VALS(mms_T_service_vals), 0,
NULL, HFILL }},
{ &hf_mms_service_preempt,
{ "service-preempt", "mms.service_preempt",
FT_INT32, BASE_DEC, VALS(mms_T_service_preempt_vals), 0,
NULL, HFILL }},
{ &hf_mms_time_resolution,
{ "time-resolution", "mms.time_resolution",
FT_INT32, BASE_DEC, VALS(mms_T_time_resolution_vals), 0,
NULL, HFILL }},
{ &hf_mms_access,
{ "access", "mms.access",
FT_INT32, BASE_DEC, VALS(mms_T_access_vals), 0,
NULL, HFILL }},
{ &hf_mms_initiate,
{ "initiate", "mms.initiate",
FT_INT32, BASE_DEC, VALS(mms_T_initiate_vals), 0,
NULL, HFILL }},
{ &hf_mms_conclude,
{ "conclude", "mms.conclude",
FT_INT32, BASE_DEC, VALS(mms_T_conclude_vals), 0,
NULL, HFILL }},
{ &hf_mms_cancel,
{ "cancel", "mms.cancel",
FT_INT32, BASE_DEC, VALS(mms_T_cancel_vals), 0,
NULL, HFILL }},
{ &hf_mms_file,
{ "file", "mms.file",
FT_INT32, BASE_DEC, VALS(mms_T_file_vals), 0,
NULL, HFILL }},
{ &hf_mms_others,
{ "others", "mms.others",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_mms_additionalCode,
{ "additionalCode", "mms.additionalCode",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_mms_additionalDescription,
{ "additionalDescription", "mms.additionalDescription",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_serviceSpecificInformation,
{ "serviceSpecificInformation", "mms.serviceSpecificInformation",
FT_UINT32, BASE_DEC, VALS(mms_T_serviceSpecificInformation_vals), 0,
NULL, HFILL }},
{ &hf_mms_obtainFile_02,
{ "obtainFile", "mms.obtainFile",
FT_INT32, BASE_DEC, VALS(mms_ObtainFile_Error_vals), 0,
"ObtainFile_Error", HFILL }},
{ &hf_mms_start_02,
{ "start", "mms.start",
FT_INT32, BASE_DEC, VALS(mms_ProgramInvocationState_vals), 0,
"Start_Error", HFILL }},
{ &hf_mms_stop_02,
{ "stop", "mms.stop",
FT_INT32, BASE_DEC, VALS(mms_ProgramInvocationState_vals), 0,
"Stop_Error", HFILL }},
{ &hf_mms_resume_02,
{ "resume", "mms.resume",
FT_INT32, BASE_DEC, VALS(mms_ProgramInvocationState_vals), 0,
"Resume_Error", HFILL }},
{ &hf_mms_reset_02,
{ "reset", "mms.reset",
FT_INT32, BASE_DEC, VALS(mms_ProgramInvocationState_vals), 0,
"Reset_Error", HFILL }},
{ &hf_mms_deleteVariableAccess_02,
{ "deleteVariableAccess", "mms.deleteVariableAccess",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteVariableAccess_Error", HFILL }},
{ &hf_mms_deleteNamedVariableList_02,
{ "deleteNamedVariableList", "mms.deleteNamedVariableList",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteNamedVariableList_Error", HFILL }},
{ &hf_mms_deleteNamedType_02,
{ "deleteNamedType", "mms.deleteNamedType",
FT_INT32, BASE_DEC, NULL, 0,
"DeleteNamedType_Error", HFILL }},
{ &hf_mms_defineEventEnrollment_Error,
{ "defineEventEnrollment-Error", "mms.defineEventEnrollment_Error",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_fileRename_02,
{ "fileRename", "mms.fileRename",
FT_INT32, BASE_DEC, VALS(mms_FileRename_Error_vals), 0,
"FileRename_Error", HFILL }},
{ &hf_mms_rejectReason,
{ "rejectReason", "mms.rejectReason",
FT_UINT32, BASE_DEC, VALS(mms_T_rejectReason_vals), 0,
NULL, HFILL }},
{ &hf_mms_confirmed_requestPDU,
{ "confirmed-requestPDU", "mms.confirmed_requestPDU",
FT_INT32, BASE_DEC, VALS(mms_T_confirmed_requestPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_confirmed_responsePDU,
{ "confirmed-responsePDU", "mms.confirmed_responsePDU",
FT_INT32, BASE_DEC, VALS(mms_T_confirmed_responsePDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_confirmed_errorPDU,
{ "confirmed-errorPDU", "mms.confirmed_errorPDU",
FT_INT32, BASE_DEC, VALS(mms_T_confirmed_errorPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_unconfirmedPDU,
{ "unconfirmedPDU", "mms.unconfirmedPDU",
FT_INT32, BASE_DEC, VALS(mms_T_unconfirmedPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_pdu_error,
{ "pdu-error", "mms.pdu_error",
FT_INT32, BASE_DEC, VALS(mms_T_pdu_error_vals), 0,
NULL, HFILL }},
{ &hf_mms_cancel_requestPDU,
{ "cancel-requestPDU", "mms.cancel_requestPDU",
FT_INT32, BASE_DEC, VALS(mms_T_cancel_requestPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_cancel_responsePDU,
{ "cancel-responsePDU", "mms.cancel_responsePDU",
FT_INT32, BASE_DEC, VALS(mms_T_cancel_responsePDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_cancel_errorPDU,
{ "cancel-errorPDU", "mms.cancel_errorPDU",
FT_INT32, BASE_DEC, VALS(mms_T_cancel_errorPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_conclude_requestPDU,
{ "conclude-requestPDU", "mms.conclude_requestPDU",
FT_INT32, BASE_DEC, VALS(mms_T_conclude_requestPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_conclude_responsePDU,
{ "conclude-responsePDU", "mms.conclude_responsePDU",
FT_INT32, BASE_DEC, VALS(mms_T_conclude_responsePDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_conclude_errorPDU,
{ "conclude-errorPDU", "mms.conclude_errorPDU",
FT_INT32, BASE_DEC, VALS(mms_T_conclude_errorPDU_vals), 0,
NULL, HFILL }},
{ &hf_mms_vmdLogicalStatus,
{ "vmdLogicalStatus", "mms.vmdLogicalStatus",
FT_INT32, BASE_DEC, VALS(mms_T_vmdLogicalStatus_vals), 0,
NULL, HFILL }},
{ &hf_mms_vmdPhysicalStatus,
{ "vmdPhysicalStatus", "mms.vmdPhysicalStatus",
FT_INT32, BASE_DEC, VALS(mms_T_vmdPhysicalStatus_vals), 0,
NULL, HFILL }},
{ &hf_mms_localDetail,
{ "localDetail", "mms.localDetail",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_0_128", HFILL }},
{ &hf_mms_extendedObjectClass,
{ "extendedObjectClass", "mms.extendedObjectClass",
FT_UINT32, BASE_DEC, VALS(mms_T_extendedObjectClass_vals), 0,
NULL, HFILL }},
{ &hf_mms_objectClass,
{ "objectClass", "mms.objectClass",
FT_INT32, BASE_DEC, VALS(mms_T_objectClass_vals), 0,
NULL, HFILL }},
{ &hf_mms_objectScope,
{ "objectScope", "mms.objectScope",
FT_UINT32, BASE_DEC, VALS(mms_T_objectScope_vals), 0,
NULL, HFILL }},
{ &hf_mms_vmdSpecific,
{ "vmdSpecific", "mms.vmdSpecific_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_domainSpecific,
{ "domainSpecific", "mms.domainSpecific",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_aaSpecific,
{ "aaSpecific", "mms.aaSpecific_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_continueAfter,
{ "continueAfter", "mms.continueAfter",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_listOfIdentifier,
{ "listOfIdentifier", "mms.listOfIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Identifier", HFILL }},
{ &hf_mms_listOfIdentifier_item,
{ "Identifier", "mms.Identifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_moreFollows,
{ "moreFollows", "mms.moreFollows",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_vendorName,
{ "vendorName", "mms.vendorName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_modelName,
{ "modelName", "mms.modelName",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_revision,
{ "revision", "mms.revision",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_listOfAbstractSyntaxes,
{ "listOfAbstractSyntaxes", "mms.listOfAbstractSyntaxes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfAbstractSyntaxes_item,
{ "listOfAbstractSyntaxes item", "mms.listOfAbstractSyntaxes_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_mms_extendedObjectClass_01,
{ "extendedObjectClass", "mms.extendedObjectClass",
FT_UINT32, BASE_DEC, VALS(mms_T_extendedObjectClass_01_vals), 0,
"T_extendedObjectClass_01", HFILL }},
{ &hf_mms_objectClass_01,
{ "objectClass", "mms.objectClass",
FT_INT32, BASE_DEC, VALS(mms_T_objectClass_01_vals), 0,
"T_objectClass_01", HFILL }},
{ &hf_mms_currentName,
{ "currentName", "mms.currentName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_newIdentifier,
{ "newIdentifier", "mms.newIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_continueAfter_01,
{ "continueAfter", "mms.continueAfter",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_listOfCapabilities,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfCapabilities_item,
{ "listOfCapabilities item", "mms.listOfCapabilities_item",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_domainName,
{ "domainName", "mms.domainName",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_listOfCapabilities_01,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfCapabilities_01", HFILL }},
{ &hf_mms_sharable,
{ "sharable", "mms.sharable",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_loadData,
{ "loadData", "mms.loadData",
FT_UINT32, BASE_DEC, VALS(mms_T_loadData_vals), 0,
NULL, HFILL }},
{ &hf_mms_non_coded,
{ "non-coded", "mms.non_coded",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_coded,
{ "coded", "mms.coded_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNALt", HFILL }},
{ &hf_mms_discard,
{ "discard", "mms.discard_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceError", HFILL }},
{ &hf_mms_ulsmID,
{ "ulsmID", "mms.ulsmID",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_listOfCapabilities_02,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfCapabilities_02", HFILL }},
{ &hf_mms_loadData_01,
{ "loadData", "mms.loadData",
FT_UINT32, BASE_DEC, VALS(mms_T_loadData_01_vals), 0,
"T_loadData_01", HFILL }},
{ &hf_mms_listOfCapabilities_03,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfCapabilities_03", HFILL }},
{ &hf_mms_fileName,
{ "fileName", "mms.fileName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfCapabilities_04,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfCapabilities_04", HFILL }},
{ &hf_mms_thirdParty,
{ "thirdParty", "mms.thirdParty_element",
FT_NONE, BASE_NONE, NULL, 0,
"ApplicationReference", HFILL }},
{ &hf_mms_filenName,
{ "filenName", "mms.filenName",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_listOfCapabilities_05,
{ "listOfCapabilities", "mms.listOfCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfCapabilities_05", HFILL }},
{ &hf_mms_state,
{ "state", "mms.state",
FT_INT32, BASE_DEC, VALS(mms_DomainState_vals), 0,
"DomainState", HFILL }},
{ &hf_mms_mmsDeletable,
{ "mmsDeletable", "mms.mmsDeletable",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_listOfProgramInvocations,
{ "listOfProgramInvocations", "mms.listOfProgramInvocations",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Identifier", HFILL }},
{ &hf_mms_listOfProgramInvocations_item,
{ "Identifier", "mms.Identifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_uploadInProgress,
{ "uploadInProgress", "mms.uploadInProgress",
FT_INT32, BASE_DEC, NULL, 0,
"Integer8", HFILL }},
{ &hf_mms_programInvocationName,
{ "programInvocationName", "mms.programInvocationName",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_listOfDomainName,
{ "listOfDomainName", "mms.listOfDomainName",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Identifier", HFILL }},
{ &hf_mms_listOfDomainName_item,
{ "Identifier", "mms.Identifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_reusable,
{ "reusable", "mms.reusable",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_monitorType,
{ "monitorType", "mms.monitorType",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_executionArgument,
{ "executionArgument", "mms.executionArgument",
FT_UINT32, BASE_DEC, VALS(mms_T_executionArgument_vals), 0,
NULL, HFILL }},
{ &hf_mms_simpleString,
{ "simpleString", "mms.simpleString",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_encodedString,
{ "encodedString", "mms.encodedString_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNALt", HFILL }},
{ &hf_mms_executionArgument_01,
{ "executionArgument", "mms.executionArgument",
FT_UINT32, BASE_DEC, VALS(mms_T_executionArgument_01_vals), 0,
"T_executionArgument_01", HFILL }},
{ &hf_mms_state_01,
{ "state", "mms.state",
FT_INT32, BASE_DEC, VALS(mms_ProgramInvocationState_vals), 0,
"ProgramInvocationState", HFILL }},
{ &hf_mms_listOfDomainNames,
{ "listOfDomainNames", "mms.listOfDomainNames",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Identifier", HFILL }},
{ &hf_mms_listOfDomainNames_item,
{ "Identifier", "mms.Identifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_monitor,
{ "monitor", "mms.monitor",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_startArgument,
{ "startArgument", "mms.startArgument",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_executionArgument_02,
{ "executionArgument", "mms.executionArgument",
FT_UINT32, BASE_DEC, VALS(mms_T_executionArgument_02_vals), 0,
"T_executionArgument_02", HFILL }},
{ &hf_mms_typeName,
{ "typeName", "mms.typeName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_array,
{ "array", "mms.array_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_packed,
{ "packed", "mms.packed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_numberOfElements,
{ "numberOfElements", "mms.numberOfElements",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_elementType,
{ "elementType", "mms.elementType",
FT_UINT32, BASE_DEC, VALS(mms_TypeSpecification_vals), 0,
"TypeSpecification", HFILL }},
{ &hf_mms_structure,
{ "structure", "mms.structure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_components,
{ "components", "mms.components",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_components_item,
{ "components item", "mms.components_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_componentName,
{ "componentName", "mms.componentName",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_componentType,
{ "componentType", "mms.componentType",
FT_UINT32, BASE_DEC, VALS(mms_TypeSpecification_vals), 0,
"TypeSpecification", HFILL }},
{ &hf_mms_boolean,
{ "boolean", "mms.boolean_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_bit_string,
{ "bit-string", "mms.bit_string",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_integer,
{ "integer", "mms.integer",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_unsigned,
{ "unsigned", "mms.unsigned",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_octet_string,
{ "octet-string", "mms.octet_string",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_visible_string,
{ "visible-string", "mms.visible_string",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_generalized_time,
{ "generalized-time", "mms.generalized_time_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_binary_time,
{ "binary-time", "mms.binary_time",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_bcd,
{ "bcd", "mms.bcd",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_objId,
{ "objId", "mms.objId_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_AlternateAccess_item,
{ "AlternateAccess item", "mms.AlternateAccess_item",
FT_UINT32, BASE_DEC, VALS(mms_AlternateAccess_item_vals), 0,
NULL, HFILL }},
{ &hf_mms_unnamed,
{ "unnamed", "mms.unnamed",
FT_UINT32, BASE_DEC, VALS(mms_AlternateAccessSelection_vals), 0,
"AlternateAccessSelection", HFILL }},
{ &hf_mms_named,
{ "named", "mms.named_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_accesst,
{ "accesst", "mms.accesst",
FT_UINT32, BASE_DEC, VALS(mms_AlternateAccessSelection_vals), 0,
"AlternateAccessSelection", HFILL }},
{ &hf_mms_selectAlternateAccess,
{ "selectAlternateAccess", "mms.selectAlternateAccess_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_accessSelection,
{ "accessSelection", "mms.accessSelection",
FT_UINT32, BASE_DEC, VALS(mms_T_accessSelection_vals), 0,
NULL, HFILL }},
{ &hf_mms_component,
{ "component", "mms.component",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_index,
{ "index", "mms.index",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_indexRange,
{ "indexRange", "mms.indexRange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_lowIndex,
{ "lowIndex", "mms.lowIndex",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_allElements,
{ "allElements", "mms.allElements_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_alternateAccess,
{ "alternateAccess", "mms.alternateAccess",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_selectAccess,
{ "selectAccess", "mms.selectAccess",
FT_UINT32, BASE_DEC, VALS(mms_T_selectAccess_vals), 0,
NULL, HFILL }},
{ &hf_mms_indexRange_01,
{ "indexRange", "mms.indexRange_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_indexRange_01", HFILL }},
{ &hf_mms_nmberOfElements,
{ "nmberOfElements", "mms.nmberOfElements",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_specificationWithResult,
{ "specificationWithResult", "mms.specificationWithResult",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_variableAccessSpecificatn,
{ "variableAccessSpecificatn", "mms.variableAccessSpecificatn",
FT_UINT32, BASE_DEC, VALS(mms_VariableAccessSpecification_vals), 0,
"VariableAccessSpecification", HFILL }},
{ &hf_mms_listOfAccessResult,
{ "listOfAccessResult", "mms.listOfAccessResult",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AccessResult", HFILL }},
{ &hf_mms_listOfAccessResult_item,
{ "AccessResult", "mms.AccessResult",
FT_UINT32, BASE_DEC, VALS(mms_AccessResult_vals), 0,
NULL, HFILL }},
{ &hf_mms_listOfData,
{ "listOfData", "mms.listOfData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_mms_listOfData_item,
{ "Data", "mms.Data",
FT_UINT32, BASE_DEC, VALS(mms_Data_vals), 0,
NULL, HFILL }},
{ &hf_mms_Write_Response_item,
{ "Write-Response item", "mms.Write_Response_item",
FT_UINT32, BASE_DEC, VALS(mms_Write_Response_item_vals), 0,
NULL, HFILL }},
{ &hf_mms_failure,
{ "failure", "mms.failure",
FT_INT32, BASE_DEC, VALS(mms_DataAccessError_vals), 0,
"DataAccessError", HFILL }},
{ &hf_mms_success,
{ "success", "mms.success_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_variableAccessSpecification,
{ "variableAccessSpecification", "mms.variableAccessSpecification",
FT_UINT32, BASE_DEC, VALS(mms_VariableAccessSpecification_vals), 0,
NULL, HFILL }},
{ &hf_mms_name,
{ "name", "mms.name",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_address,
{ "address", "mms.address",
FT_UINT32, BASE_DEC, VALS(mms_Address_vals), 0,
NULL, HFILL }},
{ &hf_mms_typeSpecification,
{ "typeSpecification", "mms.typeSpecification",
FT_UINT32, BASE_DEC, VALS(mms_TypeSpecification_vals), 0,
NULL, HFILL }},
{ &hf_mms_variableName,
{ "variableName", "mms.variableName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_scatteredAccessName,
{ "scatteredAccessName", "mms.scatteredAccessName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_scatteredAccessDescription,
{ "scatteredAccessDescription", "mms.scatteredAccessDescription",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_scopeOfDelete,
{ "scopeOfDelete", "mms.scopeOfDelete",
FT_INT32, BASE_DEC, VALS(mms_T_scopeOfDelete_vals), 0,
NULL, HFILL }},
{ &hf_mms_listOfName,
{ "listOfName", "mms.listOfName",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectName", HFILL }},
{ &hf_mms_listOfName_item,
{ "ObjectName", "mms.ObjectName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_numberMatched,
{ "numberMatched", "mms.numberMatched",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_numberDeleted,
{ "numberDeleted", "mms.numberDeleted",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_variableListName,
{ "variableListName", "mms.variableListName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_listOfVariable,
{ "listOfVariable", "mms.listOfVariable",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfVariable_item,
{ "listOfVariable item", "mms.listOfVariable_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_variableSpecification,
{ "variableSpecification", "mms.variableSpecification",
FT_UINT32, BASE_DEC, VALS(mms_VariableSpecification_vals), 0,
NULL, HFILL }},
{ &hf_mms_listOfVariable_01,
{ "listOfVariable", "mms.listOfVariable",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfVariable_01", HFILL }},
{ &hf_mms_listOfVariable_item_01,
{ "listOfVariable item", "mms.listOfVariable_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_listOfVariable_item_01", HFILL }},
{ &hf_mms_scopeOfDelete_01,
{ "scopeOfDelete", "mms.scopeOfDelete",
FT_INT32, BASE_DEC, VALS(mms_T_scopeOfDelete_01_vals), 0,
"T_scopeOfDelete_01", HFILL }},
{ &hf_mms_listOfVariableListName,
{ "listOfVariableListName", "mms.listOfVariableListName",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectName", HFILL }},
{ &hf_mms_listOfVariableListName_item,
{ "ObjectName", "mms.ObjectName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_scopeOfDelete_02,
{ "scopeOfDelete", "mms.scopeOfDelete",
FT_INT32, BASE_DEC, VALS(mms_T_scopeOfDelete_02_vals), 0,
"T_scopeOfDelete_02", HFILL }},
{ &hf_mms_listOfTypeName,
{ "listOfTypeName", "mms.listOfTypeName",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectName", HFILL }},
{ &hf_mms_listOfTypeName_item,
{ "ObjectName", "mms.ObjectName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_success_01,
{ "success", "mms.success",
FT_UINT32, BASE_DEC, VALS(mms_Data_vals), 0,
"Data", HFILL }},
{ &hf_mms_array_01,
{ "array", "mms.array",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_mms_array_item,
{ "Data", "mms.Data",
FT_UINT32, BASE_DEC, VALS(mms_Data_vals), 0,
NULL, HFILL }},
{ &hf_mms_structure_01,
{ "structure", "mms.structure",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Data", HFILL }},
{ &hf_mms_structure_item,
{ "Data", "mms.Data",
FT_UINT32, BASE_DEC, VALS(mms_Data_vals), 0,
NULL, HFILL }},
{ &hf_mms_boolean_01,
{ "boolean", "mms.boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_bit_string_01,
{ "bit-string", "mms.bit_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_integer_01,
{ "integer", "mms.integer",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_unsigned_01,
{ "unsigned", "mms.unsigned",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_mms_floating_point,
{ "floating-point", "mms.floating_point",
FT_BYTES, BASE_NONE, NULL, 0,
"FloatingPoint", HFILL }},
{ &hf_mms_octet_string_01,
{ "octet-string", "mms.octet_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_visible_string_01,
{ "visible-string", "mms.visible_string",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_binary_time_01,
{ "binary-time", "mms.binary_time",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_bcd_01,
{ "bcd", "mms.bcd",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_mms_booleanArray,
{ "booleanArray", "mms.booleanArray",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_mms_objId_01,
{ "objId", "mms.objId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_mms_mMSString,
{ "mMSString", "mms.mMSString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_utc_time,
{ "utc-time", "mms.utc_time",
FT_STRING, BASE_NONE, NULL, 0,
"UtcTime", HFILL }},
{ &hf_mms_listOfVariable_02,
{ "listOfVariable", "mms.listOfVariable",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfVariable_02", HFILL }},
{ &hf_mms_listOfVariable_item_02,
{ "listOfVariable item", "mms.listOfVariable_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_listOfVariable_item_02", HFILL }},
{ &hf_mms_ScatteredAccessDescription_item,
{ "ScatteredAccessDescription item", "mms.ScatteredAccessDescription_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_variableDescription,
{ "variableDescription", "mms.variableDescription_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_invalidated,
{ "invalidated", "mms.invalidated_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_numericAddress,
{ "numericAddress", "mms.numericAddress",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_symbolicAddress,
{ "symbolicAddress", "mms.symbolicAddress",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_unconstrainedAddress,
{ "unconstrainedAddress", "mms.unconstrainedAddress",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_semaphoreName,
{ "semaphoreName", "mms.semaphoreName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_namedToken,
{ "namedToken", "mms.namedToken",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_priority,
{ "priority", "mms.priority",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_acceptableDelay,
{ "acceptableDelay", "mms.acceptableDelay",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_controlTimeOut,
{ "controlTimeOut", "mms.controlTimeOut",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_abortOnTimeOut,
{ "abortOnTimeOut", "mms.abortOnTimeOut",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_relinquishIfConnectionLost,
{ "relinquishIfConnectionLost", "mms.relinquishIfConnectionLost",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_applicationToPreempt,
{ "applicationToPreempt", "mms.applicationToPreempt_element",
FT_NONE, BASE_NONE, NULL, 0,
"ApplicationReference", HFILL }},
{ &hf_mms_noResult,
{ "noResult", "mms.noResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_numbersOfTokens,
{ "numbersOfTokens", "mms.numbersOfTokens",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned16", HFILL }},
{ &hf_mms_class,
{ "class", "mms.class",
FT_INT32, BASE_DEC, VALS(mms_T_class_vals), 0,
NULL, HFILL }},
{ &hf_mms_numberOfTokens,
{ "numberOfTokens", "mms.numberOfTokens",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned16", HFILL }},
{ &hf_mms_numberOfOwnedTokens,
{ "numberOfOwnedTokens", "mms.numberOfOwnedTokens",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned16", HFILL }},
{ &hf_mms_numberOfHungTokens,
{ "numberOfHungTokens", "mms.numberOfHungTokens",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned16", HFILL }},
{ &hf_mms_nameToStartAfter,
{ "nameToStartAfter", "mms.nameToStartAfter",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_listOfNamedTokens,
{ "listOfNamedTokens", "mms.listOfNamedTokens",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfNamedTokens_item,
{ "listOfNamedTokens item", "mms.listOfNamedTokens_item",
FT_UINT32, BASE_DEC, VALS(mms_T_listOfNamedTokens_item_vals), 0,
NULL, HFILL }},
{ &hf_mms_freeNamedToken,
{ "freeNamedToken", "mms.freeNamedToken",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_ownedNamedToken,
{ "ownedNamedToken", "mms.ownedNamedToken",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_hungNamedToken,
{ "hungNamedToken", "mms.hungNamedToken",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_state_02,
{ "state", "mms.state",
FT_INT32, BASE_DEC, VALS(mms_T_state_vals), 0,
NULL, HFILL }},
{ &hf_mms_entryIdToStartAfter,
{ "entryIdToStartAfter", "mms.entryIdToStartAfter",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_listOfSemaphoreEntry,
{ "listOfSemaphoreEntry", "mms.listOfSemaphoreEntry",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SemaphoreEntry", HFILL }},
{ &hf_mms_listOfSemaphoreEntry_item,
{ "SemaphoreEntry", "mms.SemaphoreEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_entryId,
{ "entryId", "mms.entryId",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_entryClass,
{ "entryClass", "mms.entryClass",
FT_INT32, BASE_DEC, VALS(mms_T_entryClass_vals), 0,
NULL, HFILL }},
{ &hf_mms_applicationReference,
{ "applicationReference", "mms.applicationReference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_remainingTimeOut,
{ "remainingTimeOut", "mms.remainingTimeOut",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_operatorStationName,
{ "operatorStationName", "mms.operatorStationName",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_echo,
{ "echo", "mms.echo",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_listOfPromptData,
{ "listOfPromptData", "mms.listOfPromptData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfPromptData_item,
{ "listOfPromptData item", "mms.listOfPromptData_item",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_inputTimeOut,
{ "inputTimeOut", "mms.inputTimeOut",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_listOfOutputData,
{ "listOfOutputData", "mms.listOfOutputData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfOutputData_item,
{ "listOfOutputData item", "mms.listOfOutputData_item",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_eventConditionName,
{ "eventConditionName", "mms.eventConditionName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_class_01,
{ "class", "mms.class",
FT_INT32, BASE_DEC, VALS(mms_EC_Class_vals), 0,
"EC_Class", HFILL }},
{ &hf_mms_prio_rity,
{ "prio-rity", "mms.prio_rity",
FT_INT32, BASE_DEC, NULL, 0,
"Priority", HFILL }},
{ &hf_mms_severity,
{ "severity", "mms.severity",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_alarmSummaryReports,
{ "alarmSummaryReports", "mms.alarmSummaryReports",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_monitoredVariable,
{ "monitoredVariable", "mms.monitoredVariable",
FT_UINT32, BASE_DEC, VALS(mms_VariableSpecification_vals), 0,
"VariableSpecification", HFILL }},
{ &hf_mms_evaluationInterval,
{ "evaluationInterval", "mms.evaluationInterval",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_specific,
{ "specific", "mms.specific",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectName", HFILL }},
{ &hf_mms_specific_item,
{ "ObjectName", "mms.ObjectName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_aa_specific_01,
{ "aa-specific", "mms.aa_specific_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_domain,
{ "domain", "mms.domain",
FT_STRING, BASE_NONE, NULL, 0,
"Identifier", HFILL }},
{ &hf_mms_vmd,
{ "vmd", "mms.vmd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_monitoredVariable_01,
{ "monitoredVariable", "mms.monitoredVariable",
FT_UINT32, BASE_DEC, VALS(mms_T_monitoredVariable_vals), 0,
NULL, HFILL }},
{ &hf_mms_variableReference,
{ "variableReference", "mms.variableReference",
FT_UINT32, BASE_DEC, VALS(mms_VariableSpecification_vals), 0,
"VariableSpecification", HFILL }},
{ &hf_mms_undefined,
{ "undefined", "mms.undefined_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_currentState,
{ "currentState", "mms.currentState",
FT_INT32, BASE_DEC, VALS(mms_EC_State_vals), 0,
"EC_State", HFILL }},
{ &hf_mms_numberOfEventEnrollments,
{ "numberOfEventEnrollments", "mms.numberOfEventEnrollments",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_enabled,
{ "enabled", "mms.enabled",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_timeOfLastTransitionToActive,
{ "timeOfLastTransitionToActive", "mms.timeOfLastTransitionToActive",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_timeOfLastTransitionToIdle,
{ "timeOfLastTransitionToIdle", "mms.timeOfLastTransitionToIdle",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_eventActionName,
{ "eventActionName", "mms.eventActionName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_eventEnrollmentName,
{ "eventEnrollmentName", "mms.eventEnrollmentName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_eventConditionTransition,
{ "eventConditionTransition", "mms.eventConditionTransition",
FT_BYTES, BASE_NONE, NULL, 0,
"Transitions", HFILL }},
{ &hf_mms_alarmAcknowledgementRule,
{ "alarmAcknowledgementRule", "mms.alarmAcknowledgementRule",
FT_INT32, BASE_DEC, VALS(mms_AlarmAckRule_vals), 0,
"AlarmAckRule", HFILL }},
{ &hf_mms_clientApplication,
{ "clientApplication", "mms.clientApplication_element",
FT_NONE, BASE_NONE, NULL, 0,
"ApplicationReference", HFILL }},
{ &hf_mms_ec,
{ "ec", "mms.ec",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_ea,
{ "ea", "mms.ea",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_scopeOfRequest,
{ "scopeOfRequest", "mms.scopeOfRequest",
FT_INT32, BASE_DEC, VALS(mms_T_scopeOfRequest_vals), 0,
NULL, HFILL }},
{ &hf_mms_eventEnrollmentNames,
{ "eventEnrollmentNames", "mms.eventEnrollmentNames",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ObjectName", HFILL }},
{ &hf_mms_eventEnrollmentNames_item,
{ "ObjectName", "mms.ObjectName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
NULL, HFILL }},
{ &hf_mms_continueAfter_02,
{ "continueAfter", "mms.continueAfter",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_eventConditionName_01,
{ "eventConditionName", "mms.eventConditionName",
FT_UINT32, BASE_DEC, VALS(mms_T_eventConditionName_vals), 0,
NULL, HFILL }},
{ &hf_mms_eventCondition,
{ "eventCondition", "mms.eventCondition",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_eventActionName_01,
{ "eventActionName", "mms.eventActionName",
FT_UINT32, BASE_DEC, VALS(mms_T_eventActionName_vals), 0,
NULL, HFILL }},
{ &hf_mms_eventAction,
{ "eventAction", "mms.eventAction",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_enrollmentClass,
{ "enrollmentClass", "mms.enrollmentClass",
FT_INT32, BASE_DEC, VALS(mms_EE_Class_vals), 0,
"EE_Class", HFILL }},
{ &hf_mms_duration,
{ "duration", "mms.duration",
FT_INT32, BASE_DEC, VALS(mms_EE_Duration_vals), 0,
"EE_Duration", HFILL }},
{ &hf_mms_remainingAcceptableDelay,
{ "remainingAcceptableDelay", "mms.remainingAcceptableDelay",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_listOfEventEnrollment,
{ "listOfEventEnrollment", "mms.listOfEventEnrollment",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EventEnrollment", HFILL }},
{ &hf_mms_listOfEventEnrollment_item,
{ "EventEnrollment", "mms.EventEnrollment_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_eventConditionTransitions,
{ "eventConditionTransitions", "mms.eventConditionTransitions",
FT_BYTES, BASE_NONE, NULL, 0,
"Transitions", HFILL }},
{ &hf_mms_notificationLost,
{ "notificationLost", "mms.notificationLost",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_alarmAcknowledgmentRule,
{ "alarmAcknowledgmentRule", "mms.alarmAcknowledgmentRule",
FT_INT32, BASE_DEC, VALS(mms_AlarmAckRule_vals), 0,
"AlarmAckRule", HFILL }},
{ &hf_mms_currentState_01,
{ "currentState", "mms.currentState",
FT_INT32, BASE_DEC, VALS(mms_EE_State_vals), 0,
"EE_State", HFILL }},
{ &hf_mms_currentState_02,
{ "currentState", "mms.currentState",
FT_UINT32, BASE_DEC, VALS(mms_T_currentState_vals), 0,
NULL, HFILL }},
{ &hf_mms_state_03,
{ "state", "mms.state",
FT_INT32, BASE_DEC, VALS(mms_EE_State_vals), 0,
"EE_State", HFILL }},
{ &hf_mms_transitionTime,
{ "transitionTime", "mms.transitionTime",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_acknowledgedState,
{ "acknowledgedState", "mms.acknowledgedState",
FT_INT32, BASE_DEC, VALS(mms_EC_State_vals), 0,
"EC_State", HFILL }},
{ &hf_mms_timeOfAcknowledgedTransition,
{ "timeOfAcknowledgedTransition", "mms.timeOfAcknowledgedTransition",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_enrollmentsOnly,
{ "enrollmentsOnly", "mms.enrollmentsOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_activeAlarmsOnly,
{ "activeAlarmsOnly", "mms.activeAlarmsOnly",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mms_acknowledgmentFilter,
{ "acknowledgmentFilter", "mms.acknowledgmentFilter",
FT_INT32, BASE_DEC, VALS(mms_T_acknowledgmentFilter_vals), 0,
NULL, HFILL }},
{ &hf_mms_severityFilter,
{ "severityFilter", "mms.severityFilter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_mostSevere,
{ "mostSevere", "mms.mostSevere",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_leastSevere,
{ "leastSevere", "mms.leastSevere",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned8", HFILL }},
{ &hf_mms_listOfAlarmSummary,
{ "listOfAlarmSummary", "mms.listOfAlarmSummary",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlarmSummary", HFILL }},
{ &hf_mms_listOfAlarmSummary_item,
{ "AlarmSummary", "mms.AlarmSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_unacknowledgedState,
{ "unacknowledgedState", "mms.unacknowledgedState",
FT_INT32, BASE_DEC, VALS(mms_T_unacknowledgedState_vals), 0,
NULL, HFILL }},
{ &hf_mms_acknowledgmentFilter_01,
{ "acknowledgmentFilter", "mms.acknowledgmentFilter",
FT_INT32, BASE_DEC, VALS(mms_T_acknowledgmentFilter_01_vals), 0,
"T_acknowledgmentFilter_01", HFILL }},
{ &hf_mms_severityFilter_01,
{ "severityFilter", "mms.severityFilter_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_severityFilter_01", HFILL }},
{ &hf_mms_listOfAlarmEnrollmentSummary,
{ "listOfAlarmEnrollmentSummary", "mms.listOfAlarmEnrollmentSummary",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlarmEnrollmentSummary", HFILL }},
{ &hf_mms_listOfAlarmEnrollmentSummary_item,
{ "AlarmEnrollmentSummary", "mms.AlarmEnrollmentSummary_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_enrollementState,
{ "enrollementState", "mms.enrollementState",
FT_INT32, BASE_DEC, VALS(mms_EE_State_vals), 0,
"EE_State", HFILL }},
{ &hf_mms_timeActiveAcknowledged,
{ "timeActiveAcknowledged", "mms.timeActiveAcknowledged",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_timeIdleAcknowledged,
{ "timeIdleAcknowledged", "mms.timeIdleAcknowledged",
FT_UINT32, BASE_DEC, VALS(mms_EventTime_vals), 0,
"EventTime", HFILL }},
{ &hf_mms_eventConditionName_02,
{ "eventConditionName", "mms.eventConditionName",
FT_UINT32, BASE_DEC, VALS(mms_T_eventConditionName_01_vals), 0,
"T_eventConditionName_01", HFILL }},
{ &hf_mms_actionResult,
{ "actionResult", "mms.actionResult_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_eventActioName,
{ "eventActioName", "mms.eventActioName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_eventActionResult,
{ "eventActionResult", "mms.eventActionResult",
FT_UINT32, BASE_DEC, VALS(mms_T_eventActionResult_vals), 0,
NULL, HFILL }},
{ &hf_mms_success_02,
{ "success", "mms.success",
FT_UINT32, BASE_DEC, VALS(mms_ConfirmedServiceResponse_vals), 0,
"ConfirmedServiceResponse", HFILL }},
{ &hf_mms_failure_01,
{ "failure", "mms.failure_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceError", HFILL }},
{ &hf_mms_causingTransitions,
{ "causingTransitions", "mms.causingTransitions",
FT_BYTES, BASE_NONE, NULL, 0,
"Transitions", HFILL }},
{ &hf_mms_timeOfDayT,
{ "timeOfDayT", "mms.timeOfDayT",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_timeSequenceIdentifier,
{ "timeSequenceIdentifier", "mms.timeSequenceIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_journalName,
{ "journalName", "mms.journalName",
FT_UINT32, BASE_DEC, VALS(mms_ObjectName_vals), 0,
"ObjectName", HFILL }},
{ &hf_mms_rangeStartSpecification,
{ "rangeStartSpecification", "mms.rangeStartSpecification",
FT_UINT32, BASE_DEC, VALS(mms_T_rangeStartSpecification_vals), 0,
NULL, HFILL }},
{ &hf_mms_startingTime,
{ "startingTime", "mms.startingTime",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_startingEntry,
{ "startingEntry", "mms.startingEntry",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_rangeStopSpecification,
{ "rangeStopSpecification", "mms.rangeStopSpecification",
FT_UINT32, BASE_DEC, VALS(mms_T_rangeStopSpecification_vals), 0,
NULL, HFILL }},
{ &hf_mms_endingTime,
{ "endingTime", "mms.endingTime",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_numberOfEntries,
{ "numberOfEntries", "mms.numberOfEntries",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_listOfVariables,
{ "listOfVariables", "mms.listOfVariables",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfVariables_item,
{ "listOfVariables item", "mms.listOfVariables_item",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_entryToStartAfter,
{ "entryToStartAfter", "mms.entryToStartAfter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_timeSpecification,
{ "timeSpecification", "mms.timeSpecification",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_entrySpecification,
{ "entrySpecification", "mms.entrySpecification",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_listOfJournalEntry,
{ "listOfJournalEntry", "mms.listOfJournalEntry",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_JournalEntry", HFILL }},
{ &hf_mms_listOfJournalEntry_item,
{ "JournalEntry", "mms.JournalEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_entryIdentifier,
{ "entryIdentifier", "mms.entryIdentifier",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_originatingApplication,
{ "originatingApplication", "mms.originatingApplication_element",
FT_NONE, BASE_NONE, NULL, 0,
"ApplicationReference", HFILL }},
{ &hf_mms_entryContent,
{ "entryContent", "mms.entryContent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfJournalEntry_01,
{ "listOfJournalEntry", "mms.listOfJournalEntry",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_EntryContent", HFILL }},
{ &hf_mms_listOfJournalEntry_item_01,
{ "EntryContent", "mms.EntryContent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_limitSpecification,
{ "limitSpecification", "mms.limitSpecification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_limitingTime,
{ "limitingTime", "mms.limitingTime",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_limitingEntry,
{ "limitingEntry", "mms.limitingEntry",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_currentEntries,
{ "currentEntries", "mms.currentEntries",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_occurenceTime,
{ "occurenceTime", "mms.occurenceTime",
FT_STRING, BASE_NONE, NULL, 0,
"TimeOfDay", HFILL }},
{ &hf_mms_additionalDetail,
{ "additionalDetail", "mms.additionalDetail_element",
FT_NONE, BASE_NONE, NULL, 0,
"JOU_Additional_Detail", HFILL }},
{ &hf_mms_entryForm,
{ "entryForm", "mms.entryForm",
FT_UINT32, BASE_DEC, VALS(mms_T_entryForm_vals), 0,
NULL, HFILL }},
{ &hf_mms_data,
{ "data", "mms.data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_event,
{ "event", "mms.event_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_listOfVariables_01,
{ "listOfVariables", "mms.listOfVariables",
FT_UINT32, BASE_DEC, NULL, 0,
"T_listOfVariables_01", HFILL }},
{ &hf_mms_listOfVariables_item_01,
{ "listOfVariables item", "mms.listOfVariables_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_variableTag,
{ "variableTag", "mms.variableTag",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_valueSpecification,
{ "valueSpecification", "mms.valueSpecification",
FT_UINT32, BASE_DEC, VALS(mms_Data_vals), 0,
"Data", HFILL }},
{ &hf_mms_annotation,
{ "annotation", "mms.annotation",
FT_STRING, BASE_NONE, NULL, 0,
"VisibleString", HFILL }},
{ &hf_mms_sourceFileServer,
{ "sourceFileServer", "mms.sourceFileServer_element",
FT_NONE, BASE_NONE, NULL, 0,
"ApplicationReference", HFILL }},
{ &hf_mms_sourceFile,
{ "sourceFile", "mms.sourceFile",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_destinationFile,
{ "destinationFile", "mms.destinationFile",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_initialPosition,
{ "initialPosition", "mms.initialPosition",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_frsmID,
{ "frsmID", "mms.frsmID",
FT_INT32, BASE_DEC, NULL, 0,
"Integer32", HFILL }},
{ &hf_mms_fileAttributes,
{ "fileAttributes", "mms.fileAttributes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_fileData,
{ "fileData", "mms.fileData",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_mms_currentFileName,
{ "currentFileName", "mms.currentFileName",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_newFileName,
{ "newFileName", "mms.newFileName",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_fileSpecification,
{ "fileSpecification", "mms.fileSpecification",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_continueAfter_03,
{ "continueAfter", "mms.continueAfter",
FT_UINT32, BASE_DEC, NULL, 0,
"FileName", HFILL }},
{ &hf_mms_listOfDirectoryEntry,
{ "listOfDirectoryEntry", "mms.listOfDirectoryEntry",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DirectoryEntry", HFILL }},
{ &hf_mms_listOfDirectoryEntry_item,
{ "DirectoryEntry", "mms.DirectoryEntry_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mms_filename,
{ "filename", "mms.filename",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mms_sizeOfFile,
{ "sizeOfFile", "mms.sizeOfFile",
FT_INT32, BASE_DEC, NULL, 0,
"Unsigned32", HFILL }},
{ &hf_mms_lastModified,
{ "lastModified", "mms.lastModified",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralizedTime", HFILL }},
{ &hf_mms_ParameterSupportOptions_str1,
{ "str1", "mms.str1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_str2,
{ "str2", "mms.str2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_vnam,
{ "vnam", "mms.vnam",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_valt,
{ "valt", "mms.valt",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_vadr,
{ "vadr", "mms.vadr",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_vsca,
{ "vsca", "mms.vsca",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_tpy,
{ "tpy", "mms.tpy",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_vlis,
{ "vlis", "mms.vlis",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_real,
{ "real", "mms.real",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ParameterSupportOptions_cei,
{ "cei", "mms.cei",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_status,
{ "status", "mms.status",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getNameList,
{ "getNameList", "mms.getNameList",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_identify,
{ "identify", "mms.identify",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_rename,
{ "rename", "mms.rename",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_read,
{ "read", "mms.read",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_write,
{ "write", "mms.write",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getVariableAccessAttributes,
{ "getVariableAccessAttributes", "mms.getVariableAccessAttributes",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineNamedVariable,
{ "defineNamedVariable", "mms.defineNamedVariable",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineScatteredAccess,
{ "defineScatteredAccess", "mms.defineScatteredAccess",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getScatteredAccessAttributes,
{ "getScatteredAccessAttributes", "mms.getScatteredAccessAttributes",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteVariableAccess,
{ "deleteVariableAccess", "mms.deleteVariableAccess",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineNamedVariableList,
{ "defineNamedVariableList", "mms.defineNamedVariableList",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getNamedVariableListAttributes,
{ "getNamedVariableListAttributes", "mms.getNamedVariableListAttributes",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteNamedVariableList,
{ "deleteNamedVariableList", "mms.deleteNamedVariableList",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineNamedType,
{ "defineNamedType", "mms.defineNamedType",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getNamedTypeAttributes,
{ "getNamedTypeAttributes", "mms.getNamedTypeAttributes",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteNamedType,
{ "deleteNamedType", "mms.deleteNamedType",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_input,
{ "input", "mms.input",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_output,
{ "output", "mms.output",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_takeControl,
{ "takeControl", "mms.takeControl",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_relinquishControl,
{ "relinquishControl", "mms.relinquishControl",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineSemaphore,
{ "defineSemaphore", "mms.defineSemaphore",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteSemaphore,
{ "deleteSemaphore", "mms.deleteSemaphore",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportSemaphoreStatus,
{ "reportSemaphoreStatus", "mms.reportSemaphoreStatus",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportPoolSemaphoreStatus,
{ "reportPoolSemaphoreStatus", "mms.reportPoolSemaphoreStatus",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportSemaphoreEntryStatus,
{ "reportSemaphoreEntryStatus", "mms.reportSemaphoreEntryStatus",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_initiateDownloadSequence,
{ "initiateDownloadSequence", "mms.initiateDownloadSequence",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_downloadSegment,
{ "downloadSegment", "mms.downloadSegment",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_terminateDownloadSequence,
{ "terminateDownloadSequence", "mms.terminateDownloadSequence",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_initiateUploadSequence,
{ "initiateUploadSequence", "mms.initiateUploadSequence",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_uploadSegment,
{ "uploadSegment", "mms.uploadSegment",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_terminateUploadSequence,
{ "terminateUploadSequence", "mms.terminateUploadSequence",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_requestDomainDownload,
{ "requestDomainDownload", "mms.requestDomainDownload",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_requestDomainUpload,
{ "requestDomainUpload", "mms.requestDomainUpload",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_loadDomainContent,
{ "loadDomainContent", "mms.loadDomainContent",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_storeDomainContent,
{ "storeDomainContent", "mms.storeDomainContent",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteDomain,
{ "deleteDomain", "mms.deleteDomain",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getDomainAttributes,
{ "getDomainAttributes", "mms.getDomainAttributes",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_createProgramInvocation,
{ "createProgramInvocation", "mms.createProgramInvocation",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteProgramInvocation,
{ "deleteProgramInvocation", "mms.deleteProgramInvocation",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_start,
{ "start", "mms.start",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_stop,
{ "stop", "mms.stop",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_resume,
{ "resume", "mms.resume",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reset,
{ "reset", "mms.reset",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_kill,
{ "kill", "mms.kill",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getProgramInvocationAttributes,
{ "getProgramInvocationAttributes", "mms.getProgramInvocationAttributes",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_obtainFile,
{ "obtainFile", "mms.obtainFile",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineEventCondition,
{ "defineEventCondition", "mms.defineEventCondition",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteEventCondition,
{ "deleteEventCondition", "mms.deleteEventCondition",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getEventConditionAttributes,
{ "getEventConditionAttributes", "mms.getEventConditionAttributes",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportEventConditionStatus,
{ "reportEventConditionStatus", "mms.reportEventConditionStatus",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_alterEventConditionMonitoring,
{ "alterEventConditionMonitoring", "mms.alterEventConditionMonitoring",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_triggerEvent,
{ "triggerEvent", "mms.triggerEvent",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineEventAction,
{ "defineEventAction", "mms.defineEventAction",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteEventAction,
{ "deleteEventAction", "mms.deleteEventAction",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getEventActionAttributes,
{ "getEventActionAttributes", "mms.getEventActionAttributes",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportActionStatus,
{ "reportActionStatus", "mms.reportActionStatus",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_defineEventEnrollment,
{ "defineEventEnrollment", "mms.defineEventEnrollment",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteEventEnrollment,
{ "deleteEventEnrollment", "mms.deleteEventEnrollment",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_alterEventEnrollment,
{ "alterEventEnrollment", "mms.alterEventEnrollment",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportEventEnrollmentStatus,
{ "reportEventEnrollmentStatus", "mms.reportEventEnrollmentStatus",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getEventEnrollmentAttributes,
{ "getEventEnrollmentAttributes", "mms.getEventEnrollmentAttributes",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_acknowledgeEventNotification,
{ "acknowledgeEventNotification", "mms.acknowledgeEventNotification",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getAlarmSummary,
{ "getAlarmSummary", "mms.getAlarmSummary",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getAlarmEnrollmentSummary,
{ "getAlarmEnrollmentSummary", "mms.getAlarmEnrollmentSummary",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_readJournal,
{ "readJournal", "mms.readJournal",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_writeJournal,
{ "writeJournal", "mms.writeJournal",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_initializeJournal,
{ "initializeJournal", "mms.initializeJournal",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_reportJournalStatus,
{ "reportJournalStatus", "mms.reportJournalStatus",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_createJournal,
{ "createJournal", "mms.createJournal",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_deleteJournal,
{ "deleteJournal", "mms.deleteJournal",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_getCapabilityList,
{ "getCapabilityList", "mms.getCapabilityList",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileOpen,
{ "fileOpen", "mms.fileOpen",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileRead,
{ "fileRead", "mms.fileRead",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileClose,
{ "fileClose", "mms.fileClose",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileRename,
{ "fileRename", "mms.fileRename",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileDelete,
{ "fileDelete", "mms.fileDelete",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_fileDirectory,
{ "fileDirectory", "mms.fileDirectory",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_unsolicitedStatus,
{ "unsolicitedStatus", "mms.unsolicitedStatus",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_informationReport,
{ "informationReport", "mms.informationReport",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_eventNotification,
{ "eventNotification", "mms.eventNotification",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_attachToEventCondition,
{ "attachToEventCondition", "mms.attachToEventCondition",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_attachToSemaphore,
{ "attachToSemaphore", "mms.attachToSemaphore",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_conclude,
{ "conclude", "mms.conclude",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_ServiceSupportOptions_cancel,
{ "cancel", "mms.cancel",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_Transitions_idle_to_disabled,
{ "idle-to-disabled", "mms.idle-to-disabled",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_mms_Transitions_active_to_disabled,
{ "active-to-disabled", "mms.active-to-disabled",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_mms_Transitions_disabled_to_idle,
{ "disabled-to-idle", "mms.disabled-to-idle",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_mms_Transitions_active_to_idle,
{ "active-to-idle", "mms.active-to-idle",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_mms_Transitions_disabled_to_active,
{ "disabled-to-active", "mms.disabled-to-active",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_mms_Transitions_idle_to_active,
{ "idle-to-active", "mms.idle-to-active",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_mms_Transitions_any_to_deleted,
{ "any-to-deleted", "mms.any-to-deleted",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
#line 95 "../../asn1/mms/packet-mms-template.c"
};
static gint *ett[] = {
&ett_mms,
#line 1 "../../asn1/mms/packet-mms-ettarr.c"
&ett_mms_MMSpdu,
&ett_mms_Confirmed_RequestPDU,
&ett_mms_SEQUENCE_OF_Modifier,
&ett_mms_Unconfirmed_PDU,
&ett_mms_Confirmed_ResponsePDU,
&ett_mms_Confirmed_ErrorPDU,
&ett_mms_UnconfirmedService,
&ett_mms_Modifier,
&ett_mms_ConfirmedServiceRequest,
&ett_mms_CS_Request_Detail,
&ett_mms_ConfirmedServiceResponse,
&ett_mms_FileName,
&ett_mms_ObjectName,
&ett_mms_T_domain_specific,
&ett_mms_ApplicationReference,
&ett_mms_Initiate_RequestPDU,
&ett_mms_InitRequestDetail,
&ett_mms_Initiate_ResponsePDU,
&ett_mms_InitResponseDetail,
&ett_mms_ParameterSupportOptions,
&ett_mms_ServiceSupportOptions,
&ett_mms_Cancel_ErrorPDU,
&ett_mms_ServiceError,
&ett_mms_T_errorClass,
&ett_mms_T_serviceSpecificInformation,
&ett_mms_RejectPDU,
&ett_mms_T_rejectReason,
&ett_mms_Status_Response,
&ett_mms_GetNameList_Request,
&ett_mms_T_extendedObjectClass,
&ett_mms_T_objectScope,
&ett_mms_GetNameList_Response,
&ett_mms_SEQUENCE_OF_Identifier,
&ett_mms_Identify_Response,
&ett_mms_T_listOfAbstractSyntaxes,
&ett_mms_Rename_Request,
&ett_mms_T_extendedObjectClass_01,
&ett_mms_GetCapabilityList_Request,
&ett_mms_GetCapabilityList_Response,
&ett_mms_T_listOfCapabilities,
&ett_mms_InitiateDownloadSequence_Request,
&ett_mms_T_listOfCapabilities_01,
&ett_mms_DownloadSegment_Response,
&ett_mms_T_loadData,
&ett_mms_TerminateDownloadSequence_Request,
&ett_mms_InitiateUploadSequence_Response,
&ett_mms_T_listOfCapabilities_02,
&ett_mms_UploadSegment_Response,
&ett_mms_T_loadData_01,
&ett_mms_RequestDomainDownload_Request,
&ett_mms_T_listOfCapabilities_03,
&ett_mms_RequestDomainUpload_Request,
&ett_mms_LoadDomainContent_Request,
&ett_mms_T_listOfCapabilities_04,
&ett_mms_StoreDomainContent_Request,
&ett_mms_GetDomainAttributes_Response,
&ett_mms_T_listOfCapabilities_05,
&ett_mms_CreateProgramInvocation_Request,
&ett_mms_Start_Request,
&ett_mms_T_executionArgument,
&ett_mms_Stop_Request,
&ett_mms_Resume_Request,
&ett_mms_T_executionArgument_01,
&ett_mms_Reset_Request,
&ett_mms_Kill_Request,
&ett_mms_GetProgramInvocationAttributes_Response,
&ett_mms_T_executionArgument_02,
&ett_mms_TypeSpecification,
&ett_mms_T_array,
&ett_mms_T_structure,
&ett_mms_T_components,
&ett_mms_T_components_item,
&ett_mms_AlternateAccess,
&ett_mms_AlternateAccess_item,
&ett_mms_T_named,
&ett_mms_AlternateAccessSelection,
&ett_mms_T_selectAlternateAccess,
&ett_mms_T_accessSelection,
&ett_mms_T_indexRange,
&ett_mms_T_selectAccess,
&ett_mms_T_indexRange_01,
&ett_mms_Read_Request,
&ett_mms_Read_Response,
&ett_mms_SEQUENCE_OF_AccessResult,
&ett_mms_Write_Request,
&ett_mms_SEQUENCE_OF_Data,
&ett_mms_Write_Response,
&ett_mms_Write_Response_item,
&ett_mms_InformationReport,
&ett_mms_GetVariableAccessAttributes_Request,
&ett_mms_GetVariableAccessAttributes_Response,
&ett_mms_DefineNamedVariable_Request,
&ett_mms_DefineScatteredAccess_Request,
&ett_mms_GetScatteredAccessAttributes_Response,
&ett_mms_DeleteVariableAccess_Request,
&ett_mms_SEQUENCE_OF_ObjectName,
&ett_mms_DeleteVariableAccess_Response,
&ett_mms_DefineNamedVariableList_Request,
&ett_mms_T_listOfVariable,
&ett_mms_T_listOfVariable_item,
&ett_mms_GetNamedVariableListAttributes_Response,
&ett_mms_T_listOfVariable_01,
&ett_mms_T_listOfVariable_item_01,
&ett_mms_DeleteNamedVariableList_Request,
&ett_mms_DeleteNamedVariableList_Response,
&ett_mms_DefineNamedType_Request,
&ett_mms_GetNamedTypeAttributes_Response,
&ett_mms_DeleteNamedType_Request,
&ett_mms_DeleteNamedType_Response,
&ett_mms_AccessResult,
&ett_mms_Data,
&ett_mms_VariableAccessSpecification,
&ett_mms_T_listOfVariable_02,
&ett_mms_T_listOfVariable_item_02,
&ett_mms_ScatteredAccessDescription,
&ett_mms_ScatteredAccessDescription_item,
&ett_mms_VariableSpecification,
&ett_mms_T_variableDescription,
&ett_mms_Address,
&ett_mms_TakeControl_Request,
&ett_mms_TakeControl_Response,
&ett_mms_RelinquishControl_Request,
&ett_mms_DefineSemaphore_Request,
&ett_mms_ReportSemaphoreStatus_Response,
&ett_mms_ReportPoolSemaphoreStatus_Request,
&ett_mms_ReportPoolSemaphoreStatus_Response,
&ett_mms_T_listOfNamedTokens,
&ett_mms_T_listOfNamedTokens_item,
&ett_mms_ReportSemaphoreEntryStatus_Request,
&ett_mms_ReportSemaphoreEntryStatus_Response,
&ett_mms_SEQUENCE_OF_SemaphoreEntry,
&ett_mms_AttachToSemaphore,
&ett_mms_SemaphoreEntry,
&ett_mms_Input_Request,
&ett_mms_T_listOfPromptData,
&ett_mms_Output_Request,
&ett_mms_T_listOfOutputData,
&ett_mms_DefineEventCondition_Request,
&ett_mms_DeleteEventCondition_Request,
&ett_mms_GetEventConditionAttributes_Response,
&ett_mms_T_monitoredVariable,
&ett_mms_ReportEventConditionStatus_Response,
&ett_mms_AlterEventConditionMonitoring_Request,
&ett_mms_TriggerEvent_Request,
&ett_mms_DefineEventAction_Request,
&ett_mms_DeleteEventAction_Request,
&ett_mms_GetEventActionAttributes_Response,
&ett_mms_DefineEventEnrollment_Request,
&ett_mms_DeleteEventEnrollment_Request,
&ett_mms_GetEventEnrollmentAttributes_Request,
&ett_mms_EventEnrollment,
&ett_mms_T_eventConditionName,
&ett_mms_T_eventActionName,
&ett_mms_GetEventEnrollmentAttributes_Response,
&ett_mms_SEQUENCE_OF_EventEnrollment,
&ett_mms_ReportEventEnrollmentStatus_Response,
&ett_mms_AlterEventEnrollment_Request,
&ett_mms_AlterEventEnrollment_Response,
&ett_mms_T_currentState,
&ett_mms_AcknowledgeEventNotification_Request,
&ett_mms_GetAlarmSummary_Request,
&ett_mms_T_severityFilter,
&ett_mms_GetAlarmSummary_Response,
&ett_mms_SEQUENCE_OF_AlarmSummary,
&ett_mms_AlarmSummary,
&ett_mms_GetAlarmEnrollmentSummary_Request,
&ett_mms_T_severityFilter_01,
&ett_mms_GetAlarmEnrollmentSummary_Response,
&ett_mms_SEQUENCE_OF_AlarmEnrollmentSummary,
&ett_mms_AlarmEnrollmentSummary,
&ett_mms_EventNotification,
&ett_mms_T_eventConditionName_01,
&ett_mms_T_actionResult,
&ett_mms_T_eventActionResult,
&ett_mms_AttachToEventCondition,
&ett_mms_EventTime,
&ett_mms_Transitions,
&ett_mms_ReadJournal_Request,
&ett_mms_T_rangeStartSpecification,
&ett_mms_T_rangeStopSpecification,
&ett_mms_T_listOfVariables,
&ett_mms_T_entryToStartAfter,
&ett_mms_ReadJournal_Response,
&ett_mms_SEQUENCE_OF_JournalEntry,
&ett_mms_JournalEntry,
&ett_mms_WriteJournal_Request,
&ett_mms_SEQUENCE_OF_EntryContent,
&ett_mms_InitializeJournal_Request,
&ett_mms_T_limitSpecification,
&ett_mms_ReportJournalStatus_Response,
&ett_mms_CreateJournal_Request,
&ett_mms_DeleteJournal_Request,
&ett_mms_EntryContent,
&ett_mms_T_entryForm,
&ett_mms_T_data,
&ett_mms_T_event,
&ett_mms_T_listOfVariables_01,
&ett_mms_T_listOfVariables_item,
&ett_mms_ObtainFile_Request,
&ett_mms_FileOpen_Request,
&ett_mms_FileOpen_Response,
&ett_mms_FileRead_Response,
&ett_mms_FileRename_Request,
&ett_mms_FileDirectory_Request,
&ett_mms_FileDirectory_Response,
&ett_mms_SEQUENCE_OF_DirectoryEntry,
&ett_mms_DirectoryEntry,
&ett_mms_FileAttributes,
#line 101 "../../asn1/mms/packet-mms-template.c"
};
static ei_register_info ei[] = {
{ &ei_mms_mal_timeofday_encoding, { "mms.malformed.timeofday_encoding", PI_MALFORMED, PI_WARN, "BER Error: malformed TimeOfDay encoding", EXPFILL }},
{ &ei_mms_mal_utctime_encoding, { "mms.malformed.utctime", PI_MALFORMED, PI_WARN, "BER Error: malformed IEC61850 UTCTime encoding", EXPFILL }},
};
expert_module_t* expert_mms;
proto_mms = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("mms", dissect_mms, proto_mms);
proto_register_field_array(proto_mms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mms = expert_register_protocol(proto_mms);
expert_register_field_array(expert_mms, ei, array_length(ei));
}
static gboolean
dissect_mms_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
int offset = 0;
guint32 length = 0 ;
guint32 oct;
gint idx = 0 ;
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
if (!tvb_bytes_exist(tvb, 0, 2))
return FALSE;
offset = get_ber_identifier(tvb, offset, &tmp_class, &tmp_pc, &tmp_tag);
if (tmp_class!=BER_CLASS_CON)
return FALSE;
try_val_to_str_idx(tmp_tag, mms_MMSpdu_vals, &idx);
if (idx == -1) {
return FALSE;
}
oct = tvb_get_guint8(tvb, offset)& 0x7F;
if (oct==0)
return FALSE;
offset = get_ber_length(tvb, offset, &length, NULL);
if (!tvb_bytes_exist(tvb, offset, length))
return FALSE;
dissect_mms(tvb, pinfo, parent_tree);
return TRUE;
}
void proto_reg_handoff_mms(void) {
register_ber_oid_dissector("1.0.9506.2.3", dissect_mms, proto_mms,"MMS");
register_ber_oid_dissector("1.0.9506.2.1", dissect_mms, proto_mms,"mms-abstract-syntax-version1(1)");
heur_dissector_add("cotp", dissect_mms_heur, proto_mms);
heur_dissector_add("cotp_is", dissect_mms_heur, proto_mms);
}
