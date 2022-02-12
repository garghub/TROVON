static int
dissect_p22_Time(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_UTCTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_LocalIPMIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
0, ub_local_ipm_identifier, hf_index, NULL);
return offset;
}
static int
dissect_p22_IPMIdentifier_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
IPMIdentifier_U_set, hf_index, ett_p22_IPMIdentifier_U);
return offset;
}
static int
dissect_p22_IPMIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 11, TRUE, dissect_p22_IPMIdentifier_U);
return offset;
}
static int
dissect_p22_ThisIPMField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPMIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_FreeFormName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset,
0, ub_free_form_name, hf_index, NULL);
return offset;
}
static int
dissect_p22_TelephoneNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
0, ub_telephone_number, hf_index, NULL);
return offset;
}
int
dissect_p22_ORDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ORDescriptor_set, hf_index, ett_p22_ORDescriptor);
return offset;
}
static int
dissect_p22_OriginatorField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_AuthorizingUsersSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_AuthorizingUsersField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AuthorizingUsersField_sequence_of, hf_index, ett_p22_AuthorizingUsersField);
return offset;
}
static int
dissect_p22_NotificationRequests(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NotificationRequests_bits, hf_index, ett_p22_NotificationRequests,
NULL);
return offset;
}
static int
dissect_p22_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_T_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 220 "./asn1/p22/p22.cnf"
const char *name = NULL;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
name = oid_resolved_from_string(wmem_packet_scope(), actx->external.direct_reference);
proto_item_append_text(tree, " (%s)", name ? name : actx->external.direct_reference);
return offset;
}
static int
dissect_p22_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 228 "./asn1/p22/p22.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_p22_IPMSExtension(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPMSExtension_sequence, hf_index, ett_p22_IPMSExtension);
return offset;
}
static int
dissect_p22_RecipientExtensionsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RecipientExtensionsField_set_of, hf_index, ett_p22_RecipientExtensionsField);
return offset;
}
static int
dissect_p22_RecipientSpecifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
RecipientSpecifier_set, hf_index, ett_p22_RecipientSpecifier);
return offset;
}
static int
dissect_p22_PrimaryRecipientsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_RecipientSpecifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_PrimaryRecipientsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
PrimaryRecipientsField_sequence_of, hf_index, ett_p22_PrimaryRecipientsField);
return offset;
}
static int
dissect_p22_CopyRecipientsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_RecipientSpecifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_CopyRecipientsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
CopyRecipientsField_sequence_of, hf_index, ett_p22_CopyRecipientsField);
return offset;
}
static int
dissect_p22_BlindCopyRecipientsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_RecipientSpecifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_BlindCopyRecipientsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
BlindCopyRecipientsField_sequence_of, hf_index, ett_p22_BlindCopyRecipientsField);
return offset;
}
static int
dissect_p22_RepliedToIPMField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPMIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ObsoletedIPMsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPMIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ObsoletedIPMsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ObsoletedIPMsField_sequence_of, hf_index, ett_p22_ObsoletedIPMsField);
return offset;
}
static int
dissect_p22_RelatedIPMsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPMIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_RelatedIPMsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RelatedIPMsField_sequence_of, hf_index, ett_p22_RelatedIPMsField);
return offset;
}
static int
dissect_p22_SubjectField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 248 "./asn1/p22/p22.cnf"
tvbuff_t *subject=NULL;
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset,
0, ub_subject_field, hf_index, &subject);
if(subject)
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " (%s)", tvb_get_string_enc(wmem_packet_scope(), subject, 0,
tvb_reported_length(subject), ENC_T61));
return offset;
}
static int
dissect_p22_ExpiryTimeField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_Time(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ReplyTimeField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_Time(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ReplyRecipientsSubfield(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ReplyRecipientsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ReplyRecipientsField_sequence_of, hf_index, ett_p22_ReplyRecipientsField);
return offset;
}
static int
dissect_p22_ImportanceField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_SensitivityField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_AutoForwardedField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_p22_ExtensionsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ExtensionsField_set_of, hf_index, ett_p22_ExtensionsField);
return offset;
}
static int
dissect_p22_Heading(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
Heading_set, hf_index, ett_p22_Heading);
return offset;
}
static int
dissect_p22_Repertoire(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_IA5TextParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
IA5TextParameters_set, hf_index, ett_p22_IA5TextParameters);
return offset;
}
static int
dissect_p22_IA5TextData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_IA5TextBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IA5TextBodyPart_sequence, hf_index, ett_p22_IA5TextBodyPart);
return offset;
}
static int
dissect_p22_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_G3FacsimileParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
G3FacsimileParameters_set, hf_index, ett_p22_G3FacsimileParameters);
return offset;
}
static int
dissect_p22_BIT_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_p22_G3FacsimileData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
G3FacsimileData_sequence_of, hf_index, ett_p22_G3FacsimileData);
return offset;
}
static int
dissect_p22_G3FacsimileBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
G3FacsimileBodyPart_sequence, hf_index, ett_p22_G3FacsimileBodyPart);
return offset;
}
static int
dissect_p22_Interchange_Data_Element(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 279 "./asn1/p22/p22.cnf"
return offset;
}
static int
dissect_p22_G4Class1BodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
G4Class1BodyPart_sequence_of, hf_index, ett_p22_G4Class1BodyPart);
return offset;
}
static int
dissect_p22_TeletexParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
TeletexParameters_set, hf_index, ett_p22_TeletexParameters);
return offset;
}
static int
dissect_p22_TeletexString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_TeletexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_TeletexData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
TeletexData_sequence_of, hf_index, ett_p22_TeletexData);
return offset;
}
static int
dissect_p22_TeletexBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TeletexBodyPart_sequence, hf_index, ett_p22_TeletexBodyPart);
return offset;
}
static int
dissect_p22_VideotexSyntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_VideotexParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
VideotexParameters_set, hf_index, ett_p22_VideotexParameters);
return offset;
}
static int
dissect_p22_VideotexData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_VideotexString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_VideotexBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
VideotexBodyPart_sequence, hf_index, ett_p22_VideotexBodyPart);
return offset;
}
static int
dissect_p22_EncryptedParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EncryptedParameters_set, hf_index, ett_p22_EncryptedParameters);
return offset;
}
static int
dissect_p22_EncryptedData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
NULL, hf_index, -1,
NULL);
return offset;
}
static int
dissect_p22_EncryptedBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedBodyPart_sequence, hf_index, ett_p22_EncryptedBodyPart);
return offset;
}
int
dissect_p22_MessageParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageParameters_set, hf_index, ett_p22_MessageParameters);
return offset;
}
static int
dissect_p22_MessageData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPM(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_MessageBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MessageBodyPart_sequence, hf_index, ett_p22_MessageBodyPart);
return offset;
}
static int
dissect_p22_MixedModeBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
MixedModeBodyPart_sequence_of, hf_index, ett_p22_MixedModeBodyPart);
return offset;
}
static int
dissect_p22_BilaterallyDefinedBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_NationallyDefinedBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 282 "./asn1/p22/p22.cnf"
return offset;
}
static int
dissect_p22_T_basic(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_basic_choice, hf_index, ett_p22_T_basic,
NULL);
return offset;
}
static int
dissect_p22_INSTANCE_OF(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_p22_ExtendedBodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ExtendedBodyPart_sequence, hf_index, ett_p22_ExtendedBodyPart);
return offset;
}
static int
dissect_p22_BodyPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BodyPart_choice, hf_index, ett_p22_BodyPart,
NULL);
return offset;
}
static int
dissect_p22_Body(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Body_sequence_of, hf_index, ett_p22_Body);
return offset;
}
int
dissect_p22_IPM(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 232 "./asn1/p22/p22.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, " Message");
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPM_sequence, hf_index, ett_p22_IPM);
return offset;
}
static int
dissect_p22_SubjectIPMField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPMIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_IPNOriginatorField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_IPMIntendedRecipientField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_ORDescriptor(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ConversionEITsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_EncodedInformationTypes(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_NotificationExtensionsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
NotificationExtensionsField_set_of, hf_index, ett_p22_NotificationExtensionsField);
return offset;
}
int
dissect_p22_NonReceiptReasonField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_p22_DiscardReasonField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_AutoForwardComment(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
0, ub_auto_forward_comment, hf_index, NULL);
return offset;
}
static int
dissect_p22_AutoForwardCommentField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_AutoForwardComment(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ReturnedIPMField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_IPM(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_NRNExtensionsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
NRNExtensionsField_set_of, hf_index, ett_p22_NRNExtensionsField);
return offset;
}
static int
dissect_p22_NonReceiptFields(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
NonReceiptFields_set, hf_index, ett_p22_NonReceiptFields);
return offset;
}
int
dissect_p22_ReceiptTimeField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_Time(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_AcknowledgmentModeField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_SupplReceiptInfoField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_SupplementaryInformation(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_RNExtensionsField(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RNExtensionsField_set_of, hf_index, ett_p22_RNExtensionsField);
return offset;
}
static int
dissect_p22_ReceiptFields(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ReceiptFields_set, hf_index, ett_p22_ReceiptFields);
return offset;
}
static int
dissect_p22_OtherNotificationTypeFields(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
OtherNotificationTypeFields_set_of, hf_index, ett_p22_OtherNotificationTypeFields);
return offset;
}
static int
dissect_p22_T_choice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_choice_choice, hf_index, ett_p22_T_choice,
NULL);
return offset;
}
int
dissect_p22_IPN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 239 "./asn1/p22/p22.cnf"
col_append_str(actx->pinfo->cinfo, COL_INFO, " Notification");
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
IPN_set, hf_index, ett_p22_IPN);
return offset;
}
int
dissect_p22_InformationObject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
InformationObject_choice, hf_index, ett_p22_InformationObject,
NULL);
return offset;
}
static int
dissect_p22_AbsenceAdvice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AbsenceAdvice_sequence, hf_index, ett_p22_AbsenceAdvice);
return offset;
}
static int
dissect_p22_ChangeOfAddressAdvice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangeOfAddressAdvice_sequence, hf_index, ett_p22_ChangeOfAddressAdvice);
return offset;
}
static int
dissect_p22_INTEGER_1_MAX(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, NO_BOUND, hf_index, NULL);
return offset;
}
static int
dissect_p22_BodyPartNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, NO_BOUND, hf_index, NULL);
return offset;
}
static int
dissect_p22_T_stored_body_part(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_stored_body_part_sequence, hf_index, ett_p22_T_stored_body_part);
return offset;
}
static int
dissect_p22_BodyPartReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BodyPartReference_choice, hf_index, ett_p22_BodyPartReference,
NULL);
return offset;
}
static int
dissect_p22_BodyPartReferences(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
BodyPartReferences_sequence_of, hf_index, ett_p22_BodyPartReferences);
return offset;
}
static int
dissect_p22_IPMAssemblyInstructions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
IPMAssemblyInstructions_set, hf_index, ett_p22_IPMAssemblyInstructions);
return offset;
}
static int
dissect_p22_IncompleteCopy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_Language(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset,
2, 5, hf_index, NULL);
return offset;
}
static int
dissect_p22_Languages(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
Languages_set_of, hf_index, ett_p22_Languages);
return offset;
}
static int
dissect_p22_AutoSubmitted(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_Signature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Signature_sequence, hf_index, ett_p22_Signature);
return offset;
}
static int
dissect_p22_BodyPartSignature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_Signature(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_BodyPartSignatures_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BodyPartSignatures_item_set, hf_index, ett_p22_BodyPartSignatures_item);
return offset;
}
static int
dissect_p22_BodyPartSignatures(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
BodyPartSignatures_set_of, hf_index, ett_p22_BodyPartSignatures);
return offset;
}
static int
dissect_p22_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_BodyPartSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BodyPartSecurityLabel_choice, hf_index, ett_p22_BodyPartSecurityLabel,
NULL);
return offset;
}
static int
dissect_p22_SEQUENCE_OF_BodyPartSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_BodyPartSecurityLabel_sequence_of, hf_index, ett_p22_SEQUENCE_OF_BodyPartSecurityLabel);
return offset;
}
static int
dissect_p22_IPMSecurityLabel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
IPMSecurityLabel_sequence, hf_index, ett_p22_IPMSecurityLabel);
return offset;
}
static int
dissect_p22_AuthorizationTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_CirculationTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_CirculationSignatureAlgorithmIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_CirculationSignatureData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CirculationSignatureData_sequence, hf_index, ett_p22_CirculationSignatureData);
return offset;
}
static int
dissect_p22_CirculationSignature(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CirculationSignature_sequence, hf_index, ett_p22_CirculationSignature);
return offset;
}
static int
dissect_p22_Checkmark(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Checkmark_choice, hf_index, ett_p22_Checkmark,
NULL);
return offset;
}
static int
dissect_p22_CirculationMember(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
CirculationMember_set, hf_index, ett_p22_CirculationMember);
return offset;
}
static int
dissect_p22_CirculationList(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
2, ub_circulation_list_members, CirculationList_sequence_of, hf_index, ett_p22_CirculationList);
return offset;
}
static int
dissect_p22_CirculationListIndicator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_p22_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_AlphaCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_UniversalOrBMPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_DistributionCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DistributionCode_sequence, hf_index, ett_p22_DistributionCode);
return offset;
}
static int
dissect_p22_DistributionCodes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_distribution_codes, DistributionCodes_sequence_of, hf_index, ett_p22_DistributionCodes);
return offset;
}
static int
dissect_p22_ExtendedSubject(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_UniversalOrBMPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_DescriptionString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_UniversalOrBMPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_InformationCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
InformationCategory_sequence, hf_index, ett_p22_InformationCategory);
return offset;
}
static int
dissect_p22_InformationCategories(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_information_categories, InformationCategories_sequence_of, hf_index, ett_p22_InformationCategories);
return offset;
}
static int
dissect_p22_ManualHandlingInstruction(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_UniversalOrBMPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_ManualHandlingInstructions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_sequence_of(implicit_tag, actx, tree, tvb, offset,
1, ub_manual_handling_instructions, ManualHandlingInstructions_sequence_of, hf_index, ett_p22_ManualHandlingInstructions);
return offset;
}
static int
dissect_p22_OriginatorsReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_UniversalOrBMPString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_PrecedencePolicyIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_Precedence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
0U, ub_precedence, hf_index, NULL);
return offset;
}
static int
dissect_p22_CharacterSetRegistration(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 272 "./asn1/p22/p22.cnf"
guint32 crs;
offset = dissect_ber_constrained_integer(implicit_tag, actx, tree, tvb, offset,
1U, 32767U, hf_index, &crs);
if(actx->created_item)
proto_item_append_text(actx->created_item, " (%s)", val_to_str(crs, charsetreg_vals, "unknown"));
return offset;
}
static int
dissect_p22_GeneralTextParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
GeneralTextParameters_set_of, hf_index, ett_p22_GeneralTextParameters);
return offset;
}
static int
dissect_p22_GeneralTextData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_Pathname_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Pathname_Attribute_choice, hf_index, ett_p22_Pathname_Attribute,
NULL);
return offset;
}
static int
dissect_p22_GraphicString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_PathnameandVersion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PathnameandVersion_sequence, hf_index, ett_p22_PathnameandVersion);
return offset;
}
static int
dissect_p22_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_PrintableString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_PrintableString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_MessageReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
MessageReference_set, hf_index, ett_p22_MessageReference);
return offset;
}
static int
dissect_p22_CrossReference(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CrossReference_sequence, hf_index, ett_p22_CrossReference);
return offset;
}
static int
dissect_p22_FileIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
FileIdentifier_choice, hf_index, ett_p22_FileIdentifier,
NULL);
return offset;
}
static int
dissect_p22_ExplicitRelationship(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_Relationship(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Relationship_choice, hf_index, ett_p22_Relationship,
NULL);
return offset;
}
static int
dissect_p22_RelatedStoredFile_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RelatedStoredFile_item_sequence, hf_index, ett_p22_RelatedStoredFile_item);
return offset;
}
static int
dissect_p22_RelatedStoredFile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RelatedStoredFile_set_of, hf_index, ett_p22_RelatedStoredFile);
return offset;
}
static int
dissect_p22_Document_Type_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_T_parameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 285 "./asn1/p22/p22.cnf"
return offset;
}
static int
dissect_p22_T_document_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_document_type_sequence, hf_index, ett_p22_T_document_type);
return offset;
}
static int
dissect_p22_Constraint_Set_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_Abstract_Syntax_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_p22_T_constraint_set_and_abstract_syntax(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_constraint_set_and_abstract_syntax_sequence, hf_index, ett_p22_T_constraint_set_and_abstract_syntax);
return offset;
}
static int
dissect_p22_Contents_Type_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Contents_Type_Attribute_choice, hf_index, ett_p22_Contents_Type_Attribute,
NULL);
return offset;
}
static int
dissect_p22_ContentsTypeParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p22_Contents_Type_Attribute(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_T_descriptive_identifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_descriptive_identifier_sequence_of, hf_index, ett_p22_T_descriptive_identifier);
return offset;
}
static int
dissect_p22_GeneralIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
GeneralIdentifier_choice, hf_index, ett_p22_GeneralIdentifier,
NULL);
return offset;
}
static int
dissect_p22_T_user_visible_string(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_user_visible_string_sequence_of, hf_index, ett_p22_T_user_visible_string);
return offset;
}
static int
dissect_p22_EnvironmentParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EnvironmentParameter_sequence, hf_index, ett_p22_EnvironmentParameter);
return offset;
}
static int
dissect_p22_T_compression_algorithm_id(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 288 "./asn1/p22/p22.cnf"
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);
return offset;
}
static int
dissect_p22_T_compression_algorithm_param(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 291 "./asn1/p22/p22.cnf"
return offset;
}
static int
dissect_p22_CompressionParameter(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
CompressionParameter_sequence, hf_index, ett_p22_CompressionParameter);
return offset;
}
static int
dissect_p22_Account(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_Account_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Account_Attribute_choice, hf_index, ett_p22_Account_Attribute,
NULL);
return offset;
}
static int
dissect_p22_User_Identity(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GraphicString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_User_Identity_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
User_Identity_Attribute_choice, hf_index, ett_p22_User_Identity_Attribute,
NULL);
return offset;
}
static int
dissect_p22_Access_Request(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
Access_Request_bits, hf_index, ett_p22_Access_Request,
NULL);
return offset;
}
static int
dissect_p22_Password(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Password_choice, hf_index, ett_p22_Password,
NULL);
return offset;
}
static int
dissect_p22_Pass_Passwords(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
Pass_Passwords_sequence_of, hf_index, ett_p22_Pass_Passwords);
return offset;
}
static int
dissect_p22_Access_Passwords(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Access_Passwords_sequence, hf_index, ett_p22_Access_Passwords);
return offset;
}
static int
dissect_p22_Application_Entity_Title(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Application_Entity_Title_sequence, hf_index, ett_p22_Application_Entity_Title);
return offset;
}
static int
dissect_p22_Access_Control_Element(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Access_Control_Element_sequence, hf_index, ett_p22_Access_Control_Element);
return offset;
}
static int
dissect_p22_SET_OF_Access_Control_Element(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Access_Control_Element_set_of, hf_index, ett_p22_SET_OF_Access_Control_Element);
return offset;
}
static int
dissect_p22_Access_Control_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Access_Control_Attribute_choice, hf_index, ett_p22_Access_Control_Attribute,
NULL);
return offset;
}
static int
dissect_p22_FileAttributes(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileAttributes_sequence, hf_index, ett_p22_FileAttributes);
return offset;
}
static int
dissect_p22_FileTransferParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
FileTransferParameters_sequence, hf_index, ett_p22_FileTransferParameters);
return offset;
}
static int
dissect_p22_EXTERNAL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_external_type(implicit_tag, tree, tvb, offset, actx, hf_index, NULL);
return offset;
}
static int
dissect_p22_FileTransferData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
FileTransferData_sequence_of, hf_index, ett_p22_FileTransferData);
return offset;
}
static int
dissect_p22_IA5String(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_IA5String,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_VoiceParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
VoiceParameters_sequence, hf_index, ett_p22_VoiceParameters);
return offset;
}
static int
dissect_p22_VoiceData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_SubmissionProof(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
SubmissionProof_set, hf_index, ett_p22_SubmissionProof);
return offset;
}
static int
dissect_p22_ForwardedContentParameters(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ForwardedContentParameters_set, hf_index, ett_p22_ForwardedContentParameters);
return offset;
}
static int
dissect_p22_IPMEntryType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_MessageBodyPartSynopsis(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MessageBodyPartSynopsis_sequence, hf_index, ett_p22_MessageBodyPartSynopsis);
return offset;
}
static int
dissect_p22_NonMessageBodyPartSynopsis(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
NonMessageBodyPartSynopsis_sequence, hf_index, ett_p22_NonMessageBodyPartSynopsis);
return offset;
}
static int
dissect_p22_BodyPartSynopsis(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
BodyPartSynopsis_choice, hf_index, ett_p22_BodyPartSynopsis,
NULL);
return offset;
}
static int
dissect_p22_IPMSynopsis(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
IPMSynopsis_sequence_of, hf_index, ett_p22_IPMSynopsis);
return offset;
}
static int
dissect_p22_BodyPartDescriptor(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
BodyPartDescriptor_sequence, hf_index, ett_p22_BodyPartDescriptor);
return offset;
}
static int
dissect_p22_BodyPartSignatureVerification_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BodyPartSignatureVerification_item_set, hf_index, ett_p22_BodyPartSignatureVerification_item);
return offset;
}
static int
dissect_p22_BodyPartSignatureVerification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
BodyPartSignatureVerification_set_of, hf_index, ett_p22_BodyPartSignatureVerification);
return offset;
}
static int
dissect_p22_SET_OF_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_SequenceNumber_set_of, hf_index, ett_p22_SET_OF_SequenceNumber);
return offset;
}
static int
dissect_p22_IPMLocation(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
IPMLocation_choice, hf_index, ett_p22_IPMLocation,
NULL);
return offset;
}
static int
dissect_p22_DeliveredReplyStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_SEQUENCE_OF_SequenceNumber(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_SequenceNumber_sequence_of, hf_index, ett_p22_SEQUENCE_OF_SequenceNumber);
return offset;
}
static int
dissect_p22_CorrelatedDeliveredReplies(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CorrelatedDeliveredReplies_choice, hf_index, ett_p22_CorrelatedDeliveredReplies,
NULL);
return offset;
}
static int
dissect_p22_DeliveredIPNStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_CorrelatedDeliveredIPNs(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
CorrelatedDeliveredIPNs_choice, hf_index, ett_p22_CorrelatedDeliveredIPNs,
NULL);
return offset;
}
static int
dissect_p22_SubmittedReplyStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_SubmittedIPNStatus(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_RecipientCategory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_RecipientSecurityRequest(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
RecipientSecurityRequest_bits, hf_index, ett_p22_RecipientSecurityRequest,
NULL);
return offset;
}
static int
dissect_p22_OriginalContent(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_Content(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_OriginalContentIntegrityCheck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_ContentIntegrityCheck(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_OriginalMessageOriginAuthenticationCheck(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_MessageOriginAuthenticationCheck(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_OriginalMessageToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_p1_MessageToken(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_p22_T_original_security_arguments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
T_original_security_arguments_set, hf_index, ett_p22_T_original_security_arguments);
return offset;
}
static int
dissect_p22_T_content_or_arguments(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_content_or_arguments_choice, hf_index, ett_p22_T_content_or_arguments,
NULL);
return offset;
}
static int
dissect_p22_SecurityDiagnosticCode(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_p22_IpnSecurityResponse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
IpnSecurityResponse_set, hf_index, ett_p22_IpnSecurityResponse);
return offset;
}
static int
dissect_p22_EncryptionToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
EncryptionToken_set, hf_index, ett_p22_EncryptionToken);
return offset;
}
static int
dissect_p22_T_body_part_choice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_body_part_choice_choice, hf_index, ett_p22_T_body_part_choice,
NULL);
return offset;
}
static int
dissect_p22_BodyPartTokens_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
BodyPartTokens_item_set, hf_index, ett_p22_BodyPartTokens_item);
return offset;
}
static int
dissect_p22_BodyPartTokens(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
BodyPartTokens_set_of, hf_index, ett_p22_BodyPartTokens);
return offset;
}
static int
dissect_p22_T_body_part_token_choice(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_body_part_token_choice_choice, hf_index, ett_p22_T_body_part_token_choice,
NULL);
return offset;
}
static int
dissect_p22_ForwardedContentToken_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
ForwardedContentToken_item_set, hf_index, ett_p22_ForwardedContentToken_item);
return offset;
}
static int
dissect_p22_ForwardedContentToken(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
ForwardedContentToken_set_of, hf_index, ett_p22_ForwardedContentToken);
return offset;
}
static int dissect_InformationObject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_InformationObject(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_InformationObject_PDU);
return offset;
}
static int dissect_Heading_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_Heading(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_Heading_PDU);
return offset;
}
static int dissect_ORDescriptor_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ORDescriptor(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ORDescriptor_PDU);
return offset;
}
static int dissect_ThisIPMField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ThisIPMField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ThisIPMField_PDU);
return offset;
}
static int dissect_OriginatorField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_OriginatorField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_OriginatorField_PDU);
return offset;
}
static int dissect_AuthorizingUsersSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_AuthorizingUsersSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_AuthorizingUsersSubfield_PDU);
return offset;
}
static int dissect_PrimaryRecipientsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_PrimaryRecipientsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_PrimaryRecipientsSubfield_PDU);
return offset;
}
static int dissect_CopyRecipientsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CopyRecipientsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CopyRecipientsSubfield_PDU);
return offset;
}
static int dissect_BlindCopyRecipientsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BlindCopyRecipientsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BlindCopyRecipientsSubfield_PDU);
return offset;
}
static int dissect_RepliedToIPMField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_RepliedToIPMField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_RepliedToIPMField_PDU);
return offset;
}
static int dissect_ObsoletedIPMsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ObsoletedIPMsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ObsoletedIPMsSubfield_PDU);
return offset;
}
static int dissect_RelatedIPMsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_RelatedIPMsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_RelatedIPMsSubfield_PDU);
return offset;
}
static int dissect_SubjectField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_SubjectField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_SubjectField_PDU);
return offset;
}
static int dissect_ExpiryTimeField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ExpiryTimeField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ExpiryTimeField_PDU);
return offset;
}
static int dissect_ReplyTimeField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ReplyTimeField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ReplyTimeField_PDU);
return offset;
}
static int dissect_ReplyRecipientsSubfield_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ReplyRecipientsSubfield(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ReplyRecipientsSubfield_PDU);
return offset;
}
static int dissect_ImportanceField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ImportanceField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ImportanceField_PDU);
return offset;
}
static int dissect_SensitivityField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_SensitivityField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_SensitivityField_PDU);
return offset;
}
static int dissect_AutoForwardedField_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_AutoForwardedField(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_AutoForwardedField_PDU);
return offset;
}
static int dissect_Body_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_Body(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_Body_PDU);
return offset;
}
static int dissect_IA5TextParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IA5TextParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IA5TextParameters_PDU);
return offset;
}
static int dissect_IA5TextData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IA5TextData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IA5TextData_PDU);
return offset;
}
static int dissect_G3FacsimileParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_G3FacsimileParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_G3FacsimileParameters_PDU);
return offset;
}
static int dissect_G3FacsimileData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_G3FacsimileData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_G3FacsimileData_PDU);
return offset;
}
static int dissect_G4Class1BodyPart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_G4Class1BodyPart(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_G4Class1BodyPart_PDU);
return offset;
}
static int dissect_MixedModeBodyPart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_MixedModeBodyPart(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_MixedModeBodyPart_PDU);
return offset;
}
static int dissect_TeletexParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_TeletexParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_TeletexParameters_PDU);
return offset;
}
static int dissect_TeletexData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_TeletexData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_TeletexData_PDU);
return offset;
}
static int dissect_VideotexParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_VideotexParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_VideotexParameters_PDU);
return offset;
}
static int dissect_VideotexData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_VideotexData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_VideotexData_PDU);
return offset;
}
static int dissect_EncryptedParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_EncryptedParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_EncryptedParameters_PDU);
return offset;
}
static int dissect_EncryptedData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_EncryptedData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_EncryptedData_PDU);
return offset;
}
static int dissect_MessageParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_MessageParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_MessageParameters_PDU);
return offset;
}
static int dissect_MessageData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_MessageData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_MessageData_PDU);
return offset;
}
static int dissect_BilaterallyDefinedBodyPart_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BilaterallyDefinedBodyPart(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BilaterallyDefinedBodyPart_PDU);
return offset;
}
static int dissect_IPN_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPN(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPN_PDU);
return offset;
}
static int dissect_AbsenceAdvice_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_AbsenceAdvice(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_AbsenceAdvice_PDU);
return offset;
}
static int dissect_ChangeOfAddressAdvice_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ChangeOfAddressAdvice(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ChangeOfAddressAdvice_PDU);
return offset;
}
static int dissect_IPMAssemblyInstructions_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPMAssemblyInstructions(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPMAssemblyInstructions_PDU);
return offset;
}
static int dissect_IncompleteCopy_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IncompleteCopy(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IncompleteCopy_PDU);
return offset;
}
static int dissect_Languages_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_Languages(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_Languages_PDU);
return offset;
}
static int dissect_Language_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_Language(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_Language_PDU);
return offset;
}
static int dissect_AutoSubmitted_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_AutoSubmitted(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_AutoSubmitted_PDU);
return offset;
}
static int dissect_BodyPartSignatures_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BodyPartSignatures(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BodyPartSignatures_PDU);
return offset;
}
static int dissect_IPMSecurityLabel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPMSecurityLabel(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPMSecurityLabel_PDU);
return offset;
}
static int dissect_BodyPartSecurityLabel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BodyPartSecurityLabel(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BodyPartSecurityLabel_PDU);
return offset;
}
static int dissect_AuthorizationTime_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_AuthorizationTime(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_AuthorizationTime_PDU);
return offset;
}
static int dissect_CirculationList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CirculationList(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CirculationList_PDU);
return offset;
}
static int dissect_CirculationMember_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CirculationMember(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CirculationMember_PDU);
return offset;
}
static int dissect_CirculationListIndicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CirculationListIndicator(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CirculationListIndicator_PDU);
return offset;
}
static int dissect_DistributionCodes_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_DistributionCodes(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_DistributionCodes_PDU);
return offset;
}
static int dissect_DistributionCode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_DistributionCode(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_DistributionCode_PDU);
return offset;
}
static int dissect_ExtendedSubject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ExtendedSubject(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ExtendedSubject_PDU);
return offset;
}
static int dissect_InformationCategories_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_InformationCategories(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_InformationCategories_PDU);
return offset;
}
static int dissect_InformationCategory_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_InformationCategory(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_InformationCategory_PDU);
return offset;
}
static int dissect_ManualHandlingInstructions_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ManualHandlingInstructions(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ManualHandlingInstructions_PDU);
return offset;
}
static int dissect_ManualHandlingInstruction_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ManualHandlingInstruction(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ManualHandlingInstruction_PDU);
return offset;
}
static int dissect_OriginatorsReference_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_OriginatorsReference(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_OriginatorsReference_PDU);
return offset;
}
static int dissect_PrecedencePolicyIdentifier_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_PrecedencePolicyIdentifier(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_PrecedencePolicyIdentifier_PDU);
return offset;
}
static int dissect_Precedence_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_Precedence(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_Precedence_PDU);
return offset;
}
static int dissect_GeneralTextParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_GeneralTextParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_GeneralTextParameters_PDU);
return offset;
}
static int dissect_GeneralTextData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_GeneralTextData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_GeneralTextData_PDU);
return offset;
}
static int dissect_FileTransferParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_FileTransferParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_FileTransferParameters_PDU);
return offset;
}
static int dissect_FileTransferData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_FileTransferData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_FileTransferData_PDU);
return offset;
}
static int dissect_VoiceParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_VoiceParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_VoiceParameters_PDU);
return offset;
}
static int dissect_VoiceData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_VoiceData(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_VoiceData_PDU);
return offset;
}
static int dissect_ForwardedContentParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ForwardedContentParameters(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ForwardedContentParameters_PDU);
return offset;
}
static int dissect_IPMEntryType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPMEntryType(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPMEntryType_PDU);
return offset;
}
static int dissect_IPMSynopsis_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPMSynopsis(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPMSynopsis_PDU);
return offset;
}
static int dissect_BodyPartDescriptor_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BodyPartDescriptor(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BodyPartDescriptor_PDU);
return offset;
}
static int dissect_BodyPartSignatureVerification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BodyPartSignatureVerification(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BodyPartSignatureVerification_PDU);
return offset;
}
static int dissect_IPMLocation_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IPMLocation(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IPMLocation_PDU);
return offset;
}
static int dissect_DeliveredReplyStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_DeliveredReplyStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_DeliveredReplyStatus_PDU);
return offset;
}
static int dissect_CorrelatedDeliveredReplies_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CorrelatedDeliveredReplies(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CorrelatedDeliveredReplies_PDU);
return offset;
}
static int dissect_DeliveredIPNStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_DeliveredIPNStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_DeliveredIPNStatus_PDU);
return offset;
}
static int dissect_CorrelatedDeliveredIPNs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_CorrelatedDeliveredIPNs(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_CorrelatedDeliveredIPNs_PDU);
return offset;
}
static int dissect_SubmittedReplyStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_SubmittedReplyStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_SubmittedReplyStatus_PDU);
return offset;
}
static int dissect_SubmittedIPNStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_SubmittedIPNStatus(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_SubmittedIPNStatus_PDU);
return offset;
}
static int dissect_RecipientCategory_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_RecipientCategory(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_RecipientCategory_PDU);
return offset;
}
static int dissect_RecipientSecurityRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_RecipientSecurityRequest(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_RecipientSecurityRequest_PDU);
return offset;
}
static int dissect_IpnSecurityResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_IpnSecurityResponse(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_IpnSecurityResponse_PDU);
return offset;
}
static int dissect_BodyPartTokens_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_BodyPartTokens(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_BodyPartTokens_PDU);
return offset;
}
static int dissect_ForwardedContentToken_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_p22_ForwardedContentToken(FALSE, tvb, offset, &asn1_ctx, tree, hf_p22_ForwardedContentToken_PDU);
return offset;
}
static int
dissect_p22(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
int offset = 0;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (parent_tree) {
item = proto_tree_add_item(parent_tree, proto_p22, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_p22);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "P22");
col_set_str(pinfo->cinfo, COL_INFO, "InterPersonal");
dissect_p22_InformationObject(TRUE, tvb, offset, &asn1_ctx , tree, -1);
return tvb_captured_length(tvb);
}
void proto_register_p22(void) {
static hf_register_info hf[] =
{
#line 1 "./asn1/p22/packet-p22-hfarr.c"
{ &hf_p22_InformationObject_PDU,
{ "InformationObject", "p22.InformationObject",
FT_UINT32, BASE_DEC, VALS(p22_InformationObject_vals), 0,
NULL, HFILL }},
{ &hf_p22_Heading_PDU,
{ "Heading", "p22.Heading_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ORDescriptor_PDU,
{ "ORDescriptor", "p22.ORDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ThisIPMField_PDU,
{ "ThisIPMField", "p22.ThisIPMField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_OriginatorField_PDU,
{ "OriginatorField", "p22.OriginatorField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_AuthorizingUsersSubfield_PDU,
{ "AuthorizingUsersSubfield", "p22.AuthorizingUsersSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_PrimaryRecipientsSubfield_PDU,
{ "PrimaryRecipientsSubfield", "p22.PrimaryRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_CopyRecipientsSubfield_PDU,
{ "CopyRecipientsSubfield", "p22.CopyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BlindCopyRecipientsSubfield_PDU,
{ "BlindCopyRecipientsSubfield", "p22.BlindCopyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_RepliedToIPMField_PDU,
{ "RepliedToIPMField", "p22.RepliedToIPMField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ObsoletedIPMsSubfield_PDU,
{ "ObsoletedIPMsSubfield", "p22.ObsoletedIPMsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_RelatedIPMsSubfield_PDU,
{ "RelatedIPMsSubfield", "p22.RelatedIPMsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_SubjectField_PDU,
{ "SubjectField", "p22.SubjectField",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ExpiryTimeField_PDU,
{ "ExpiryTimeField", "p22.ExpiryTimeField",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ReplyTimeField_PDU,
{ "ReplyTimeField", "p22.ReplyTimeField",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ReplyRecipientsSubfield_PDU,
{ "ReplyRecipientsSubfield", "p22.ReplyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ImportanceField_PDU,
{ "ImportanceField", "p22.ImportanceField",
FT_UINT32, BASE_DEC, VALS(p22_ImportanceField_vals), 0,
NULL, HFILL }},
{ &hf_p22_SensitivityField_PDU,
{ "SensitivityField", "p22.SensitivityField",
FT_UINT32, BASE_DEC, VALS(p22_SensitivityField_vals), 0,
NULL, HFILL }},
{ &hf_p22_AutoForwardedField_PDU,
{ "AutoForwardedField", "p22.AutoForwardedField",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Body_PDU,
{ "Body", "p22.Body",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IA5TextParameters_PDU,
{ "IA5TextParameters", "p22.IA5TextParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IA5TextData_PDU,
{ "IA5TextData", "p22.IA5TextData",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_G3FacsimileParameters_PDU,
{ "G3FacsimileParameters", "p22.G3FacsimileParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_G3FacsimileData_PDU,
{ "G3FacsimileData", "p22.G3FacsimileData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_G4Class1BodyPart_PDU,
{ "G4Class1BodyPart", "p22.G4Class1BodyPart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_MixedModeBodyPart_PDU,
{ "MixedModeBodyPart", "p22.MixedModeBodyPart",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_TeletexParameters_PDU,
{ "TeletexParameters", "p22.TeletexParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_TeletexData_PDU,
{ "TeletexData", "p22.TeletexData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_VideotexParameters_PDU,
{ "VideotexParameters", "p22.VideotexParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_VideotexData_PDU,
{ "VideotexData", "p22.VideotexData",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_EncryptedParameters_PDU,
{ "EncryptedParameters", "p22.EncryptedParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_EncryptedData_PDU,
{ "EncryptedData", "p22.EncryptedData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_MessageParameters_PDU,
{ "MessageParameters", "p22.MessageParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_MessageData_PDU,
{ "MessageData", "p22.MessageData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BilaterallyDefinedBodyPart_PDU,
{ "BilaterallyDefinedBodyPart", "p22.BilaterallyDefinedBodyPart",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IPN_PDU,
{ "IPN", "p22.IPN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_AbsenceAdvice_PDU,
{ "AbsenceAdvice", "p22.AbsenceAdvice_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ChangeOfAddressAdvice_PDU,
{ "ChangeOfAddressAdvice", "p22.ChangeOfAddressAdvice_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IPMAssemblyInstructions_PDU,
{ "IPMAssemblyInstructions", "p22.IPMAssemblyInstructions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IncompleteCopy_PDU,
{ "IncompleteCopy", "p22.IncompleteCopy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Languages_PDU,
{ "Languages", "p22.Languages",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Language_PDU,
{ "Language", "p22.Language",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_AutoSubmitted_PDU,
{ "AutoSubmitted", "p22.AutoSubmitted",
FT_UINT32, BASE_DEC, VALS(p22_AutoSubmitted_vals), 0,
NULL, HFILL }},
{ &hf_p22_BodyPartSignatures_PDU,
{ "BodyPartSignatures", "p22.BodyPartSignatures",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IPMSecurityLabel_PDU,
{ "IPMSecurityLabel", "p22.IPMSecurityLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BodyPartSecurityLabel_PDU,
{ "BodyPartSecurityLabel", "p22.BodyPartSecurityLabel",
FT_UINT32, BASE_DEC, VALS(p22_BodyPartSecurityLabel_vals), 0,
NULL, HFILL }},
{ &hf_p22_AuthorizationTime_PDU,
{ "AuthorizationTime", "p22.AuthorizationTime",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_CirculationList_PDU,
{ "CirculationList", "p22.CirculationList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_CirculationMember_PDU,
{ "CirculationMember", "p22.CirculationMember_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_CirculationListIndicator_PDU,
{ "CirculationListIndicator", "p22.CirculationListIndicator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_DistributionCodes_PDU,
{ "DistributionCodes", "p22.DistributionCodes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_DistributionCode_PDU,
{ "DistributionCode", "p22.DistributionCode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ExtendedSubject_PDU,
{ "ExtendedSubject", "p22.ExtendedSubject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_InformationCategories_PDU,
{ "InformationCategories", "p22.InformationCategories",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_InformationCategory_PDU,
{ "InformationCategory", "p22.InformationCategory_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ManualHandlingInstructions_PDU,
{ "ManualHandlingInstructions", "p22.ManualHandlingInstructions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ManualHandlingInstruction_PDU,
{ "ManualHandlingInstruction", "p22.ManualHandlingInstruction_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_OriginatorsReference_PDU,
{ "OriginatorsReference", "p22.OriginatorsReference_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_PrecedencePolicyIdentifier_PDU,
{ "PrecedencePolicyIdentifier", "p22.PrecedencePolicyIdentifier",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Precedence_PDU,
{ "Precedence", "p22.Precedence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_GeneralTextParameters_PDU,
{ "GeneralTextParameters", "p22.GeneralTextParameters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_GeneralTextData_PDU,
{ "GeneralTextData", "p22.GeneralTextData",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_FileTransferParameters_PDU,
{ "FileTransferParameters", "p22.FileTransferParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_FileTransferData_PDU,
{ "FileTransferData", "p22.FileTransferData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_VoiceParameters_PDU,
{ "VoiceParameters", "p22.VoiceParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_VoiceData_PDU,
{ "VoiceData", "p22.VoiceData",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ForwardedContentParameters_PDU,
{ "ForwardedContentParameters", "p22.ForwardedContentParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IPMEntryType_PDU,
{ "IPMEntryType", "p22.IPMEntryType",
FT_UINT32, BASE_DEC, VALS(p22_IPMEntryType_vals), 0,
NULL, HFILL }},
{ &hf_p22_IPMSynopsis_PDU,
{ "IPMSynopsis", "p22.IPMSynopsis",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BodyPartDescriptor_PDU,
{ "BodyPartDescriptor", "p22.BodyPartDescriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BodyPartSignatureVerification_PDU,
{ "BodyPartSignatureVerification", "p22.BodyPartSignatureVerification",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IPMLocation_PDU,
{ "IPMLocation", "p22.IPMLocation",
FT_UINT32, BASE_DEC, VALS(p22_IPMLocation_vals), 0,
NULL, HFILL }},
{ &hf_p22_DeliveredReplyStatus_PDU,
{ "DeliveredReplyStatus", "p22.DeliveredReplyStatus",
FT_INT32, BASE_DEC, VALS(p22_DeliveredReplyStatus_vals), 0,
NULL, HFILL }},
{ &hf_p22_CorrelatedDeliveredReplies_PDU,
{ "CorrelatedDeliveredReplies", "p22.CorrelatedDeliveredReplies",
FT_UINT32, BASE_DEC, VALS(p22_CorrelatedDeliveredReplies_vals), 0,
NULL, HFILL }},
{ &hf_p22_DeliveredIPNStatus_PDU,
{ "DeliveredIPNStatus", "p22.DeliveredIPNStatus",
FT_INT32, BASE_DEC, VALS(p22_DeliveredIPNStatus_vals), 0,
NULL, HFILL }},
{ &hf_p22_CorrelatedDeliveredIPNs_PDU,
{ "CorrelatedDeliveredIPNs", "p22.CorrelatedDeliveredIPNs",
FT_UINT32, BASE_DEC, VALS(p22_CorrelatedDeliveredIPNs_vals), 0,
NULL, HFILL }},
{ &hf_p22_SubmittedReplyStatus_PDU,
{ "SubmittedReplyStatus", "p22.SubmittedReplyStatus",
FT_INT32, BASE_DEC, VALS(p22_SubmittedReplyStatus_vals), 0,
NULL, HFILL }},
{ &hf_p22_SubmittedIPNStatus_PDU,
{ "SubmittedIPNStatus", "p22.SubmittedIPNStatus",
FT_INT32, BASE_DEC, VALS(p22_SubmittedIPNStatus_vals), 0,
NULL, HFILL }},
{ &hf_p22_RecipientCategory_PDU,
{ "RecipientCategory", "p22.RecipientCategory",
FT_INT32, BASE_DEC, VALS(p22_RecipientCategory_vals), 0,
NULL, HFILL }},
{ &hf_p22_RecipientSecurityRequest_PDU,
{ "RecipientSecurityRequest", "p22.RecipientSecurityRequest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_IpnSecurityResponse_PDU,
{ "IpnSecurityResponse", "p22.IpnSecurityResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BodyPartTokens_PDU,
{ "BodyPartTokens", "p22.BodyPartTokens",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ForwardedContentToken_PDU,
{ "ForwardedContentToken", "p22.ForwardedContentToken",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ipm,
{ "ipm", "p22.ipm_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ipn,
{ "ipn", "p22.ipn_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_heading,
{ "heading", "p22.heading_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body,
{ "body", "p22.body",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_type,
{ "type", "p22.type",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_value,
{ "value", "p22.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_this_IPM,
{ "this-IPM", "p22.this_IPM_element",
FT_NONE, BASE_NONE, NULL, 0,
"ThisIPMField", HFILL }},
{ &hf_p22_originator,
{ "originator", "p22.originator_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginatorField", HFILL }},
{ &hf_p22_authorizing_users,
{ "authorizing-users", "p22.authorizing_users",
FT_UINT32, BASE_DEC, NULL, 0,
"AuthorizingUsersField", HFILL }},
{ &hf_p22_primary_recipients,
{ "primary-recipients", "p22.primary_recipients",
FT_UINT32, BASE_DEC, NULL, 0,
"PrimaryRecipientsField", HFILL }},
{ &hf_p22_copy_recipients,
{ "copy-recipients", "p22.copy_recipients",
FT_UINT32, BASE_DEC, NULL, 0,
"CopyRecipientsField", HFILL }},
{ &hf_p22_blind_copy_recipients,
{ "blind-copy-recipients", "p22.blind_copy_recipients",
FT_UINT32, BASE_DEC, NULL, 0,
"BlindCopyRecipientsField", HFILL }},
{ &hf_p22_replied_to_IPM,
{ "replied-to-IPM", "p22.replied_to_IPM_element",
FT_NONE, BASE_NONE, NULL, 0,
"RepliedToIPMField", HFILL }},
{ &hf_p22_obsoleted_IPMs,
{ "obsoleted-IPMs", "p22.obsoleted_IPMs",
FT_UINT32, BASE_DEC, NULL, 0,
"ObsoletedIPMsField", HFILL }},
{ &hf_p22_related_IPMs,
{ "related-IPMs", "p22.related_IPMs",
FT_UINT32, BASE_DEC, NULL, 0,
"RelatedIPMsField", HFILL }},
{ &hf_p22_subject,
{ "subject", "p22.subject",
FT_STRING, STR_UNICODE, NULL, 0,
"SubjectField", HFILL }},
{ &hf_p22_expiry_time,
{ "expiry-time", "p22.expiry_time",
FT_STRING, BASE_NONE, NULL, 0,
"ExpiryTimeField", HFILL }},
{ &hf_p22_reply_time,
{ "reply-time", "p22.reply_time",
FT_STRING, BASE_NONE, NULL, 0,
"ReplyTimeField", HFILL }},
{ &hf_p22_reply_recipients,
{ "reply-recipients", "p22.reply_recipients",
FT_UINT32, BASE_DEC, NULL, 0,
"ReplyRecipientsField", HFILL }},
{ &hf_p22_importance,
{ "importance", "p22.importance",
FT_UINT32, BASE_DEC, VALS(p22_ImportanceField_vals), 0,
"ImportanceField", HFILL }},
{ &hf_p22_sensitivity,
{ "sensitivity", "p22.sensitivity",
FT_UINT32, BASE_DEC, VALS(p22_SensitivityField_vals), 0,
"SensitivityField", HFILL }},
{ &hf_p22_auto_forwarded,
{ "auto-forwarded", "p22.auto_forwarded",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"AutoForwardedField", HFILL }},
{ &hf_p22_extensions,
{ "extensions", "p22.extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ExtensionsField", HFILL }},
{ &hf_p22_user,
{ "user", "p22.user_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORName", HFILL }},
{ &hf_p22_user_relative_identifier,
{ "user-relative-identifier", "p22.user_relative_identifier",
FT_STRING, BASE_NONE, NULL, 0,
"LocalIPMIdentifier", HFILL }},
{ &hf_p22_recipient,
{ "recipient", "p22.recipient_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORDescriptor", HFILL }},
{ &hf_p22_notification_requests,
{ "notification-requests", "p22.notification_requests",
FT_BYTES, BASE_NONE, NULL, 0,
"NotificationRequests", HFILL }},
{ &hf_p22_reply_requested,
{ "reply-requested", "p22.reply_requested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p22_recipient_extensions,
{ "recipient-extensions", "p22.recipient_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"RecipientExtensionsField", HFILL }},
{ &hf_p22_formal_name,
{ "formal-name", "p22.formal_name_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORName", HFILL }},
{ &hf_p22_free_form_name,
{ "free-form-name", "p22.free_form_name",
FT_STRING, STR_UNICODE, NULL, 0,
"FreeFormName", HFILL }},
{ &hf_p22_telephone_number,
{ "telephone-number", "p22.telephone_number",
FT_STRING, BASE_NONE, NULL, 0,
"TelephoneNumber", HFILL }},
{ &hf_p22_RecipientExtensionsField_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_AuthorizingUsersField_item,
{ "AuthorizingUsersSubfield", "p22.AuthorizingUsersSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_PrimaryRecipientsField_item,
{ "PrimaryRecipientsSubfield", "p22.PrimaryRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_CopyRecipientsField_item,
{ "CopyRecipientsSubfield", "p22.CopyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BlindCopyRecipientsField_item,
{ "BlindCopyRecipientsSubfield", "p22.BlindCopyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ObsoletedIPMsField_item,
{ "ObsoletedIPMsSubfield", "p22.ObsoletedIPMsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_RelatedIPMsField_item,
{ "RelatedIPMsSubfield", "p22.RelatedIPMsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ReplyRecipientsField_item,
{ "ReplyRecipientsSubfield", "p22.ReplyRecipientsSubfield_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ExtensionsField_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Body_item,
{ "BodyPart", "p22.BodyPart",
FT_UINT32, BASE_DEC, VALS(p22_BodyPart_vals), 0,
NULL, HFILL }},
{ &hf_p22_basic,
{ "basic", "p22.basic",
FT_UINT32, BASE_DEC, VALS(p22_T_basic_vals), 0,
NULL, HFILL }},
{ &hf_p22_ia5_text,
{ "ia5-text", "p22.ia5_text_element",
FT_NONE, BASE_NONE, NULL, 0,
"IA5TextBodyPart", HFILL }},
{ &hf_p22_g3_facsimile,
{ "g3-facsimile", "p22.g3_facsimile_element",
FT_NONE, BASE_NONE, NULL, 0,
"G3FacsimileBodyPart", HFILL }},
{ &hf_p22_g4_class1,
{ "g4-class1", "p22.g4_class1",
FT_UINT32, BASE_DEC, NULL, 0,
"G4Class1BodyPart", HFILL }},
{ &hf_p22_teletex,
{ "teletex", "p22.teletex_element",
FT_NONE, BASE_NONE, NULL, 0,
"TeletexBodyPart", HFILL }},
{ &hf_p22_videotex,
{ "videotex", "p22.videotex_element",
FT_NONE, BASE_NONE, NULL, 0,
"VideotexBodyPart", HFILL }},
{ &hf_p22_encrypted_bp,
{ "encrypted", "p22.encrypted_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedBodyPart", HFILL }},
{ &hf_p22_message,
{ "message", "p22.message_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageBodyPart", HFILL }},
{ &hf_p22_mixed_mode,
{ "mixed-mode", "p22.mixed_mode",
FT_UINT32, BASE_DEC, NULL, 0,
"MixedModeBodyPart", HFILL }},
{ &hf_p22_bilaterally_defined,
{ "bilaterally-defined", "p22.bilaterally_defined",
FT_BYTES, BASE_NONE, NULL, 0,
"BilaterallyDefinedBodyPart", HFILL }},
{ &hf_p22_nationally_defined,
{ "nationally-defined", "p22.nationally_defined_element",
FT_NONE, BASE_NONE, NULL, 0,
"NationallyDefinedBodyPart", HFILL }},
{ &hf_p22_extended,
{ "extended", "p22.extended_element",
FT_NONE, BASE_NONE, NULL, 0,
"ExtendedBodyPart", HFILL }},
{ &hf_p22_extended_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"INSTANCE_OF", HFILL }},
{ &hf_p22_extended_data,
{ "data", "p22.data_element",
FT_NONE, BASE_NONE, NULL, 0,
"INSTANCE_OF", HFILL }},
{ &hf_p22_ia5text_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"IA5TextParameters", HFILL }},
{ &hf_p22_ia5text_data,
{ "data", "p22.data",
FT_STRING, BASE_NONE, NULL, 0,
"IA5TextData", HFILL }},
{ &hf_p22_repertoire,
{ "repertoire", "p22.repertoire",
FT_UINT32, BASE_DEC, VALS(p22_Repertoire_vals), 0,
NULL, HFILL }},
{ &hf_p22_g3facsimile_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"G3FacsimileParameters", HFILL }},
{ &hf_p22_g3facsimile_data,
{ "data", "p22.data",
FT_UINT32, BASE_DEC, NULL, 0,
"G3FacsimileData", HFILL }},
{ &hf_p22_number_of_pages,
{ "number-of-pages", "p22.number_of_pages",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p22_g3facsimile_non_basic_parameters,
{ "non-basic-parameters", "p22.non_basic_parameters",
FT_BYTES, BASE_NONE, NULL, 0,
"G3FacsimileNonBasicParameters", HFILL }},
{ &hf_p22_G3FacsimileData_item,
{ "G3FacsimileData item", "p22.G3FacsimileData_item",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_p22_G4Class1BodyPart_item,
{ "Interchange-Data-Element", "p22.Interchange_Data_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_MixedModeBodyPart_item,
{ "Interchange-Data-Element", "p22.Interchange_Data_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_teletex_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"TeletexParameters", HFILL }},
{ &hf_p22_teletex_data,
{ "data", "p22.data",
FT_UINT32, BASE_DEC, NULL, 0,
"TeletexData", HFILL }},
{ &hf_p22_telex_compatible,
{ "telex-compatible", "p22.telex_compatible",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p22_teletex_non_basic_parameters,
{ "non-basic-parameters", "p22.non_basic_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"TeletexNonBasicParameters", HFILL }},
{ &hf_p22_TeletexData_item,
{ "TeletexData item", "p22.TeletexData_item",
FT_STRING, STR_UNICODE, NULL, 0,
"TeletexString", HFILL }},
{ &hf_p22_videotex_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"VideotexParameters", HFILL }},
{ &hf_p22_videotex_data,
{ "data", "p22.data",
FT_STRING, STR_UNICODE, NULL, 0,
"VideotexData", HFILL }},
{ &hf_p22_syntax,
{ "syntax", "p22.syntax",
FT_INT32, BASE_DEC, VALS(p22_VideotexSyntax_vals), 0,
"VideotexSyntax", HFILL }},
{ &hf_p22_encrypted_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedParameters", HFILL }},
{ &hf_p22_encrypted_data,
{ "data", "p22.data",
FT_BYTES, BASE_NONE, NULL, 0,
"EncryptedData", HFILL }},
{ &hf_p22_algorithm_identifier,
{ "algorithm-identifier", "p22.algorithm_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_p22_originator_certificates,
{ "originator-certificates", "p22.originator_certificates",
FT_UINT32, BASE_DEC, NULL, 0,
"ExtendedCertificates", HFILL }},
{ &hf_p22_message_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageParameters", HFILL }},
{ &hf_p22_message_data,
{ "data", "p22.data_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageData", HFILL }},
{ &hf_p22_delivery_time,
{ "delivery-time", "p22.delivery_time",
FT_STRING, BASE_NONE, NULL, 0,
"MessageDeliveryTime", HFILL }},
{ &hf_p22_delivery_envelope,
{ "delivery-envelope", "p22.delivery_envelope_element",
FT_NONE, BASE_NONE, NULL, 0,
"OtherMessageDeliveryFields", HFILL }},
{ &hf_p22_subject_ipm,
{ "subject-ipm", "p22.subject_ipm_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubjectIPMField", HFILL }},
{ &hf_p22_ipn_originator,
{ "ipn-originator", "p22.ipn_originator_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPNOriginatorField", HFILL }},
{ &hf_p22_ipm_intended_recipient,
{ "ipm-intended-recipient", "p22.ipm_intended_recipient_element",
FT_NONE, BASE_NONE, NULL, 0,
"IPMIntendedRecipientField", HFILL }},
{ &hf_p22_conversion_eits,
{ "conversion-eits", "p22.conversion_eits_element",
FT_NONE, BASE_NONE, NULL, 0,
"ConversionEITsField", HFILL }},
{ &hf_p22_notification_extensions,
{ "notification-extensions", "p22.notification_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"NotificationExtensionsField", HFILL }},
{ &hf_p22_non_receipt_reason,
{ "non-receipt-reason", "p22.non_receipt_reason",
FT_UINT32, BASE_DEC, VALS(p22_NonReceiptReasonField_vals), 0,
"NonReceiptReasonField", HFILL }},
{ &hf_p22_discard_reason,
{ "discard-reason", "p22.discard_reason",
FT_UINT32, BASE_DEC, VALS(p22_DiscardReasonField_vals), 0,
"DiscardReasonField", HFILL }},
{ &hf_p22_auto_forward_comment,
{ "auto-forward-comment", "p22.auto_forward_comment",
FT_STRING, BASE_NONE, NULL, 0,
"AutoForwardCommentField", HFILL }},
{ &hf_p22_returned_ipm,
{ "returned-ipm", "p22.returned_ipm_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReturnedIPMField", HFILL }},
{ &hf_p22_nrn_extensions,
{ "nrn-extensions", "p22.nrn_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"NRNExtensionsField", HFILL }},
{ &hf_p22_receipt_time,
{ "receipt-time", "p22.receipt_time",
FT_STRING, BASE_NONE, NULL, 0,
"ReceiptTimeField", HFILL }},
{ &hf_p22_acknowledgment_mode,
{ "acknowledgment-mode", "p22.acknowledgment_mode",
FT_UINT32, BASE_DEC, VALS(p22_AcknowledgmentModeField_vals), 0,
"AcknowledgmentModeField", HFILL }},
{ &hf_p22_suppl_receipt_info,
{ "suppl-receipt-info", "p22.suppl_receipt_info",
FT_STRING, BASE_NONE, NULL, 0,
"SupplReceiptInfoField", HFILL }},
{ &hf_p22_rn_extensions,
{ "rn-extensions", "p22.rn_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"RNExtensionsField", HFILL }},
{ &hf_p22_NotificationExtensionsField_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_NRNExtensionsField_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_RNExtensionsField_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_OtherNotificationTypeFields_item,
{ "IPMSExtension", "p22.IPMSExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_advice,
{ "advice", "p22.advice",
FT_UINT32, BASE_DEC, VALS(p22_BodyPart_vals), 0,
"BodyPart", HFILL }},
{ &hf_p22_next_available,
{ "next-available", "p22.next_available",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_p22_new_address,
{ "new-address", "p22.new_address_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORDescriptor", HFILL }},
{ &hf_p22_effective_from,
{ "effective-from", "p22.effective_from",
FT_STRING, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_p22_assembly_instructions,
{ "assembly-instructions", "p22.assembly_instructions",
FT_UINT32, BASE_DEC, NULL, 0,
"BodyPartReferences", HFILL }},
{ &hf_p22_BodyPartReferences_item,
{ "BodyPartReference", "p22.BodyPartReference",
FT_UINT32, BASE_DEC, VALS(p22_BodyPartReference_vals), 0,
NULL, HFILL }},
{ &hf_p22_stored_entry,
{ "stored-entry", "p22.stored_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p22_stored_content,
{ "stored-content", "p22.stored_content",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p22_submitted_body_part,
{ "submitted-body-part", "p22.submitted_body_part",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_MAX", HFILL }},
{ &hf_p22_stored_body_part,
{ "stored-body-part", "p22.stored_body_part_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_message_entry,
{ "message-entry", "p22.message_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p22_body_part_number,
{ "body-part-number", "p22.body_part_number",
FT_UINT32, BASE_DEC, NULL, 0,
"BodyPartNumber", HFILL }},
{ &hf_p22_Languages_item,
{ "Language", "p22.Language",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_BodyPartSignatures_item,
{ "BodyPartSignatures item", "p22.BodyPartSignatures_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body_part_signature,
{ "body-part-signature", "p22.body_part_signature_element",
FT_NONE, BASE_NONE, NULL, 0,
"BodyPartSignature", HFILL }},
{ &hf_p22_originator_certificate_selector,
{ "originator-certificate-selector", "p22.originator_certificate_selector_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificateAssertion", HFILL }},
{ &hf_p22_algorithmIdentifier,
{ "algorithmIdentifier", "p22.algorithmIdentifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_encrypted,
{ "encrypted", "p22.encrypted",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_p22_content_security_label,
{ "content-security-label", "p22.content_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p22_heading_security_label,
{ "heading-security-label", "p22.heading_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p22_body_part_security_labels,
{ "body-part-security-labels", "p22.body_part_security_labels",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_BodyPartSecurityLabel", HFILL }},
{ &hf_p22_body_part_security_labels_item,
{ "BodyPartSecurityLabel", "p22.BodyPartSecurityLabel",
FT_UINT32, BASE_DEC, VALS(p22_BodyPartSecurityLabel_vals), 0,
NULL, HFILL }},
{ &hf_p22_body_part_unlabelled,
{ "body-part-unlabelled", "p22.body_part_unlabelled_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body_part_security_label,
{ "body-part-security-label", "p22.body_part_security_label_element",
FT_NONE, BASE_NONE, NULL, 0,
"SecurityLabel", HFILL }},
{ &hf_p22_CirculationList_item,
{ "CirculationMember", "p22.CirculationMember_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_circulation_recipient,
{ "circulation-recipient", "p22.circulation_recipient_element",
FT_NONE, BASE_NONE, NULL, 0,
"RecipientSpecifier", HFILL }},
{ &hf_p22_checked,
{ "checked", "p22.checked",
FT_UINT32, BASE_DEC, VALS(p22_Checkmark_vals), 0,
"Checkmark", HFILL }},
{ &hf_p22_simple,
{ "simple", "p22.simple_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_timestamped,
{ "timestamped", "p22.timestamped",
FT_STRING, BASE_NONE, NULL, 0,
"CirculationTime", HFILL }},
{ &hf_p22_signed,
{ "signed", "p22.signed_element",
FT_NONE, BASE_NONE, NULL, 0,
"CirculationSignature", HFILL }},
{ &hf_p22_circulation_signature_algorithm_identifier,
{ "algorithm-identifier", "p22.algorithm_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"CirculationSignatureAlgorithmIdentifier", HFILL }},
{ &hf_p22_timestamp,
{ "timestamp", "p22.timestamp",
FT_STRING, BASE_NONE, NULL, 0,
"CirculationTime", HFILL }},
{ &hf_p22_circulation_signature_data,
{ "circulation-signature-data", "p22.circulation_signature_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"CirculationSignatureData", HFILL }},
{ &hf_p22_DistributionCodes_item,
{ "DistributionCode", "p22.DistributionCode_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_oid_code,
{ "oid-code", "p22.oid_code",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_alphanumeric_code,
{ "alphanumeric-code", "p22.alphanumeric_code_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlphaCode", HFILL }},
{ &hf_p22_or_descriptor,
{ "or-descriptor", "p22.or_descriptor_element",
FT_NONE, BASE_NONE, NULL, 0,
"ORDescriptor", HFILL }},
{ &hf_p22_InformationCategories_item,
{ "InformationCategory", "p22.InformationCategory_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_reference,
{ "reference", "p22.reference",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_description,
{ "description", "p22.description_element",
FT_NONE, BASE_NONE, NULL, 0,
"DescriptionString", HFILL }},
{ &hf_p22_ManualHandlingInstructions_item,
{ "ManualHandlingInstruction", "p22.ManualHandlingInstruction_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_GeneralTextParameters_item,
{ "CharacterSetRegistration", "p22.CharacterSetRegistration",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_related_stored_file,
{ "related-stored-file", "p22.related_stored_file",
FT_UINT32, BASE_DEC, NULL, 0,
"RelatedStoredFile", HFILL }},
{ &hf_p22_contents_type,
{ "contents-type", "p22.contents_type",
FT_UINT32, BASE_DEC, VALS(p22_Contents_Type_Attribute_vals), 0,
"ContentsTypeParameter", HFILL }},
{ &hf_p22_environment,
{ "environment", "p22.environment_element",
FT_NONE, BASE_NONE, NULL, 0,
"EnvironmentParameter", HFILL }},
{ &hf_p22_compression,
{ "compression", "p22.compression_element",
FT_NONE, BASE_NONE, NULL, 0,
"CompressionParameter", HFILL }},
{ &hf_p22_file_attributes,
{ "file-attributes", "p22.file_attributes_element",
FT_NONE, BASE_NONE, NULL, 0,
"FileAttributes", HFILL }},
{ &hf_p22_FileTransferData_item,
{ "FileTransferData item", "p22.FileTransferData_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"EXTERNAL", HFILL }},
{ &hf_p22_RelatedStoredFile_item,
{ "RelatedStoredFile item", "p22.RelatedStoredFile_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_file_identifier,
{ "file-identifier", "p22.file_identifier",
FT_UINT32, BASE_DEC, VALS(p22_FileIdentifier_vals), 0,
"FileIdentifier", HFILL }},
{ &hf_p22_relationship,
{ "relationship", "p22.relationship",
FT_UINT32, BASE_DEC, VALS(p22_Relationship_vals), 0,
NULL, HFILL }},
{ &hf_p22_pathname_and_version,
{ "pathname-and-version", "p22.pathname_and_version_element",
FT_NONE, BASE_NONE, NULL, 0,
"PathnameandVersion", HFILL }},
{ &hf_p22_cross_reference,
{ "cross-reference", "p22.cross_reference_element",
FT_NONE, BASE_NONE, NULL, 0,
"CrossReference", HFILL }},
{ &hf_p22_pathname,
{ "pathname", "p22.pathname",
FT_UINT32, BASE_DEC, VALS(p22_Pathname_Attribute_vals), 0,
"Pathname_Attribute", HFILL }},
{ &hf_p22_file_version,
{ "file-version", "p22.file_version",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_p22_application_cross_reference,
{ "application-cross-reference", "p22.application_cross_reference",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_p22_message_reference,
{ "message-reference", "p22.message_reference_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageReference", HFILL }},
{ &hf_p22_body_part_reference,
{ "body-part-reference", "p22.body_part_reference",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p22_user_relative_identifier_ref,
{ "user-relative-identifier", "p22.user_relative_identifier",
FT_STRING, BASE_NONE, NULL, 0,
"PrintableString", HFILL }},
{ &hf_p22_explicit_relationship,
{ "explicit-relationship", "p22.explicit_relationship",
FT_INT32, BASE_DEC, VALS(p22_ExplicitRelationship_vals), 0,
"ExplicitRelationship", HFILL }},
{ &hf_p22_descriptive_relationship,
{ "descriptive-relationship", "p22.descriptive_relationship",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_p22_document_type,
{ "document-type", "p22.document_type_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_document_type", HFILL }},
{ &hf_p22_document_type_name,
{ "document-type-name", "p22.document_type_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_parameter,
{ "parameter", "p22.parameter_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_constraint_set_and_abstract_syntax,
{ "constraint-set-and-abstract-syntax", "p22.constraint_set_and_abstract_syntax_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_constraint_set_and_abstract_syntax", HFILL }},
{ &hf_p22_constraint_set_name,
{ "constraint-set-name", "p22.constraint_set_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_abstract_syntax_name,
{ "abstract-syntax-name", "p22.abstract_syntax_name",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_application_reference,
{ "application-reference", "p22.application_reference",
FT_UINT32, BASE_DEC, VALS(p22_GeneralIdentifier_vals), 0,
"GeneralIdentifier", HFILL }},
{ &hf_p22_machine,
{ "machine", "p22.machine",
FT_UINT32, BASE_DEC, VALS(p22_GeneralIdentifier_vals), 0,
"GeneralIdentifier", HFILL }},
{ &hf_p22_operating_system,
{ "operating-system", "p22.operating_system",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_user_visible_string,
{ "user-visible-string", "p22.user_visible_string",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_user_visible_string_item,
{ "user-visible-string item", "p22.user_visible_string_item",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_p22_registered_identifier,
{ "registered-identifier", "p22.registered_identifier",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_descriptive_identifier,
{ "descriptive-identifier", "p22.descriptive_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_descriptive_identifier_item,
{ "descriptive-identifier item", "p22.descriptive_identifier_item",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_p22_compression_algorithm_id,
{ "compression-algorithm-id", "p22.compression_algorithm_id",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_compression_algorithm_param,
{ "compression-algorithm-param", "p22.compression_algorithm_param_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_permitted_actions,
{ "permitted-actions", "p22.permitted_actions",
FT_BYTES, BASE_NONE, NULL, 0,
"Permitted_Actions_Attribute", HFILL }},
{ &hf_p22_storage_account,
{ "storage-account", "p22.storage_account",
FT_UINT32, BASE_DEC, VALS(p22_Account_Attribute_vals), 0,
"Account_Attribute", HFILL }},
{ &hf_p22_date_and_time_of_creation,
{ "date-and-time-of-creation", "p22.date_and_time_of_creation",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_p22_date_and_time_of_last_modification,
{ "date-and-time-of-last-modification", "p22.date_and_time_of_last_modification",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_p22_date_and_time_of_last_read_access,
{ "date-and-time-of-last-read-access", "p22.date_and_time_of_last_read_access",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_p22_date_and_time_of_last_attribute_modification,
{ "date-and-time-of-last-attribute-modification", "p22.date_and_time_of_last_attribute_modification",
FT_UINT32, BASE_DEC, VALS(ftam_Date_and_Time_Attribute_vals), 0,
"Date_and_Time_Attribute", HFILL }},
{ &hf_p22_identity_of_creator,
{ "identity-of-creator", "p22.identity_of_creator",
FT_UINT32, BASE_DEC, VALS(p22_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_p22_identity_of_last_modifier,
{ "identity-of-last-modifier", "p22.identity_of_last_modifier",
FT_UINT32, BASE_DEC, VALS(p22_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_p22_identity_of_last_reader,
{ "identity-of-last-reader", "p22.identity_of_last_reader",
FT_UINT32, BASE_DEC, VALS(p22_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_p22_identity_of_last_attribute_modifier,
{ "identity-of-last-attribute-modifier", "p22.identity_of_last_attribute_modifier",
FT_UINT32, BASE_DEC, VALS(p22_User_Identity_Attribute_vals), 0,
"User_Identity_Attribute", HFILL }},
{ &hf_p22_object_availability,
{ "object-availability", "p22.object_availability",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Availability_Attribute_vals), 0,
"Object_Availability_Attribute", HFILL }},
{ &hf_p22_object_size,
{ "object-size", "p22.object_size",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Size_Attribute_vals), 0,
"Object_Size_Attribute", HFILL }},
{ &hf_p22_future_object_size,
{ "future-object-size", "p22.future_object_size",
FT_UINT32, BASE_DEC, VALS(ftam_Object_Size_Attribute_vals), 0,
"Object_Size_Attribute", HFILL }},
{ &hf_p22_access_control,
{ "access-control", "p22.access_control",
FT_UINT32, BASE_DEC, VALS(p22_Access_Control_Attribute_vals), 0,
"Access_Control_Attribute", HFILL }},
{ &hf_p22_legal_qualifications,
{ "legal-qualifications", "p22.legal_qualifications",
FT_UINT32, BASE_DEC, VALS(ftam_Legal_Qualification_Attribute_vals), 0,
"Legal_Qualification_Attribute", HFILL }},
{ &hf_p22_private_use,
{ "private-use", "p22.private_use",
FT_UINT32, BASE_DEC, VALS(ftam_Private_Use_Attribute_vals), 0,
"Private_Use_Attribute", HFILL }},
{ &hf_p22_attribute_extensions,
{ "attribute-extensions", "p22.attribute_extensions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_incomplete_pathname,
{ "incomplete-pathname", "p22.incomplete_pathname",
FT_UINT32, BASE_DEC, NULL, 0,
"Pathname", HFILL }},
{ &hf_p22_complete_pathname,
{ "complete-pathname", "p22.complete_pathname",
FT_UINT32, BASE_DEC, NULL, 0,
"Pathname", HFILL }},
{ &hf_p22_no_value_available,
{ "no-value-available", "p22.no_value_available_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_account_actual_values,
{ "actual-values", "p22.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"Account", HFILL }},
{ &hf_p22_identity_actual_values,
{ "actual-values", "p22.actual_values",
FT_STRING, BASE_NONE, NULL, 0,
"User_Identity", HFILL }},
{ &hf_p22_actual_values,
{ "actual-values", "p22.actual_values",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Access_Control_Element", HFILL }},
{ &hf_p22_actual_values_item,
{ "Access-Control-Element", "p22.Access_Control_Element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_action_list,
{ "action-list", "p22.action_list",
FT_BYTES, BASE_NONE, NULL, 0,
"Access_Request", HFILL }},
{ &hf_p22_concurrency_access,
{ "concurrency-access", "p22.concurrency_access_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_identity,
{ "identity", "p22.identity",
FT_STRING, BASE_NONE, NULL, 0,
"User_Identity", HFILL }},
{ &hf_p22_passwords,
{ "passwords", "p22.passwords_element",
FT_NONE, BASE_NONE, NULL, 0,
"Access_Passwords", HFILL }},
{ &hf_p22_location,
{ "location", "p22.location_element",
FT_NONE, BASE_NONE, NULL, 0,
"Application_Entity_Title", HFILL }},
{ &hf_p22_read_password,
{ "read-password", "p22.read_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_insert_password,
{ "insert-password", "p22.insert_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_replace_password,
{ "replace-password", "p22.replace_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_extend_password,
{ "extend-password", "p22.extend_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_erase_password,
{ "erase-password", "p22.erase_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_read_attribute_password,
{ "read-attribute-password", "p22.read_attribute_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_change_attribute_password,
{ "change-attribute-password", "p22.change_attribute_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_delete_password,
{ "delete-password", "p22.delete_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_pass_passwords,
{ "pass-passwords", "p22.pass_passwords",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_link_password,
{ "link-password", "p22.link_password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
"Password", HFILL }},
{ &hf_p22_graphic_string,
{ "graphic-string", "p22.graphic_string",
FT_STRING, BASE_NONE, NULL, 0,
"GraphicString", HFILL }},
{ &hf_p22_octet_string,
{ "octet-string", "p22.octet_string",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_Pass_Passwords_item,
{ "Password", "p22.Password",
FT_UINT32, BASE_DEC, VALS(p22_Password_vals), 0,
NULL, HFILL }},
{ &hf_p22_ap_title,
{ "ap-title", "p22.ap_title",
FT_UINT32, BASE_DEC, VALS(acse_AP_title_vals), 0,
NULL, HFILL }},
{ &hf_p22_ae_qualifier,
{ "ae-qualifier", "p22.ae_qualifier",
FT_UINT32, BASE_DEC, VALS(acse_ASO_qualifier_vals), 0,
NULL, HFILL }},
{ &hf_p22_voice_message_duration,
{ "voice-message-duration", "p22.voice_message_duration",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p22_voice_encoding_type,
{ "voice-encoding-type", "p22.voice_encoding_type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_supplementary_information,
{ "supplementary-information", "p22.supplementary_information",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String", HFILL }},
{ &hf_p22_mts_identifier,
{ "mts-identifier", "p22.mts_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageDeliveryIdentifier", HFILL }},
{ &hf_p22_submission_proof,
{ "submission-proof", "p22.submission_proof_element",
FT_NONE, BASE_NONE, NULL, 0,
"SubmissionProof", HFILL }},
{ &hf_p22_proof_of_submission,
{ "proof-of-submission", "p22.proof_of_submission_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProofOfSubmission", HFILL }},
{ &hf_p22_originating_MTA_certificate,
{ "originating-MTA-certificate", "p22.originating_MTA_certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginatingMTACertificate", HFILL }},
{ &hf_p22_message_submission_envelope,
{ "message-submission-envelope", "p22.message_submission_envelope_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageSubmissionEnvelope", HFILL }},
{ &hf_p22_IPMSynopsis_item,
{ "BodyPartSynopsis", "p22.BodyPartSynopsis",
FT_UINT32, BASE_DEC, VALS(p22_BodyPartSynopsis_vals), 0,
NULL, HFILL }},
{ &hf_p22_message_synopsis,
{ "message", "p22.message_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageBodyPartSynopsis", HFILL }},
{ &hf_p22_non_message,
{ "non-message", "p22.non_message_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonMessageBodyPartSynopsis", HFILL }},
{ &hf_p22_number,
{ "number", "p22.number",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p22_synopsis,
{ "synopsis", "p22.synopsis",
FT_UINT32, BASE_DEC, NULL, 0,
"IPMSynopsis", HFILL }},
{ &hf_p22_bp_type,
{ "type", "p22.type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_bp_parameters,
{ "parameters", "p22.parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"INSTANCE_OF", HFILL }},
{ &hf_p22_size,
{ "size", "p22.size",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p22_processed,
{ "processed", "p22.processed",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_p22_data,
{ "data", "p22.data",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_parameters,
{ "parameters", "p22.parameters",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_p22_this_child_entry,
{ "this-child-entry", "p22.this_child_entry",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_p22_position,
{ "position", "p22.position",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_p22_BodyPartSignatureVerification_item,
{ "BodyPartSignatureVerification item", "p22.BodyPartSignatureVerification_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body_part_sequence_number,
{ "body-part-sequence-number", "p22.body_part_sequence_number",
FT_UINT32, BASE_DEC, NULL, 0,
"BodyPartNumber", HFILL }},
{ &hf_p22_body_part_signature_status,
{ "body-part-signature", "p22.body_part_signature",
FT_INT32, BASE_DEC, VALS(p7_SignatureStatus_vals), 0,
"SignatureStatus", HFILL }},
{ &hf_p22_stored,
{ "stored", "p22.stored",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_SequenceNumber", HFILL }},
{ &hf_p22_stored_item,
{ "SequenceNumber", "p22.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_absent,
{ "absent", "p22.absent_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_no_reply_received,
{ "no-reply-received", "p22.no_reply_received_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_received_replies,
{ "received-replies", "p22.received_replies",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SequenceNumber", HFILL }},
{ &hf_p22_received_replies_item,
{ "SequenceNumber", "p22.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_no_ipn_received,
{ "no-ipn-received", "p22.no_ipn_received_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_ipns_received,
{ "ipns-received", "p22.ipns_received",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SequenceNumber", HFILL }},
{ &hf_p22_ipns_received_item,
{ "SequenceNumber", "p22.SequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_p22_content_or_arguments,
{ "content-or-arguments", "p22.content_or_arguments",
FT_UINT32, BASE_DEC, VALS(p22_T_content_or_arguments_vals), 0,
"T_content_or_arguments", HFILL }},
{ &hf_p22_original_content,
{ "original-content", "p22.original_content",
FT_BYTES, BASE_NONE, NULL, 0,
"OriginalContent", HFILL }},
{ &hf_p22_original_security_arguments,
{ "original-security-arguments", "p22.original_security_arguments_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_original_content_integrity_check,
{ "original-content-integrity-check", "p22.original_content_integrity_check_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginalContentIntegrityCheck", HFILL }},
{ &hf_p22_original_message_origin_authentication_check,
{ "original-message-origin-authentication-check", "p22.original_message_origin_authentication_check_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginalMessageOriginAuthenticationCheck", HFILL }},
{ &hf_p22_original_message_token,
{ "original-message-token", "p22.original_message_token_element",
FT_NONE, BASE_NONE, NULL, 0,
"OriginalMessageToken", HFILL }},
{ &hf_p22_security_diagnostic_code,
{ "security-diagnostic-code", "p22.security_diagnostic_code",
FT_INT32, BASE_DEC, VALS(p22_SecurityDiagnosticCode_vals), 0,
"SecurityDiagnosticCode", HFILL }},
{ &hf_p22_BodyPartTokens_item,
{ "BodyPartTokens item", "p22.BodyPartTokens_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body_part_choice,
{ "body-part-choice", "p22.body_part_choice",
FT_UINT32, BASE_DEC, VALS(p22_T_body_part_choice_vals), 0,
"T_body_part_choice", HFILL }},
{ &hf_p22_encryption_token,
{ "encryption-token", "p22.encryption_token_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptionToken", HFILL }},
{ &hf_p22_message_or_content_body_part,
{ "message-or-content-body-part", "p22.message_or_content_body_part",
FT_UINT32, BASE_DEC, NULL, 0,
"BodyPartTokens", HFILL }},
{ &hf_p22_encryption_algorithm_identifier,
{ "encryption-algorithm-identifier", "p22.encryption_algorithm_identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlgorithmIdentifier", HFILL }},
{ &hf_p22_encrypted_key,
{ "encrypted-key", "p22.encrypted_key",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_p22_recipient_certificate_selector,
{ "recipient-certificate-selector", "p22.recipient_certificate_selector_element",
FT_NONE, BASE_NONE, NULL, 0,
"CertificateAssertion", HFILL }},
{ &hf_p22_recipient_certificate,
{ "recipient-certificate", "p22.recipient_certificate_element",
FT_NONE, BASE_NONE, NULL, 0,
"Certificates", HFILL }},
{ &hf_p22_ForwardedContentToken_item,
{ "ForwardedContentToken item", "p22.ForwardedContentToken_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_p22_body_part_token_choice,
{ "body-part-choice", "p22.body_part_choice",
FT_UINT32, BASE_DEC, VALS(p22_T_body_part_token_choice_vals), 0,
"T_body_part_token_choice", HFILL }},
{ &hf_p22_forwarding_token,
{ "forwarding-token", "p22.forwarding_token_element",
FT_NONE, BASE_NONE, NULL, 0,
"MessageToken", HFILL }},
{ &hf_p22_forwarded_content_token,
{ "message-or-content-body-part", "p22.message_or_content_body_part",
FT_UINT32, BASE_DEC, NULL, 0,
"ForwardedContentToken", HFILL }},
{ &hf_p22_choice,
{ "choice", "p22.choice",
FT_UINT32, BASE_DEC, VALS(p22_T_choice_vals), 0,
NULL, HFILL }},
{ &hf_p22_non_receipt_fields,
{ "non-receipt-fields", "p22.non_receipt_fields_element",
FT_NONE, BASE_NONE, NULL, 0,
"NonReceiptFields", HFILL }},
{ &hf_p22_receipt_fields,
{ "receipt-fields", "p22.receipt_fields_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReceiptFields", HFILL }},
{ &hf_p22_other_notification_type_fields,
{ "other-notification-type-fields", "p22.other_notification_type_fields",
FT_UINT32, BASE_DEC, NULL, 0,
"OtherNotificationTypeFields", HFILL }},
{ &hf_p22_NotificationRequests_rn,
{ "rn", "p22.rn",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p22_NotificationRequests_nrn,
{ "nrn", "p22.nrn",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p22_NotificationRequests_ipm_return,
{ "ipm-return", "p22.ipm-return",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_p22_NotificationRequests_an_supported,
{ "an-supported", "p22.an-supported",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_p22_NotificationRequests_suppress_an,
{ "suppress-an", "p22.suppress-an",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_p22_Access_Request_read,
{ "read", "p22.read",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p22_Access_Request_insert,
{ "insert", "p22.insert",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p22_Access_Request_replace,
{ "replace", "p22.replace",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_p22_Access_Request_extend,
{ "extend", "p22.extend",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_p22_Access_Request_erase,
{ "erase", "p22.erase",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_p22_Access_Request_read_attribute,
{ "read-attribute", "p22.read-attribute",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_p22_Access_Request_change_attribute,
{ "change-attribute", "p22.change-attribute",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_p22_Access_Request_delete_object,
{ "delete-object", "p22.delete-object",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_p22_RecipientSecurityRequest_content_non_repudiation,
{ "content-non-repudiation", "p22.content-non-repudiation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_p22_RecipientSecurityRequest_content_proof,
{ "content-proof", "p22.content-proof",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_p22_RecipientSecurityRequest_ipn_non_repudiation,
{ "ipn-non-repudiation", "p22.ipn-non-repudiation",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_p22_RecipientSecurityRequest_ipn_proof,
{ "ipn-proof", "p22.ipn-proof",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
#line 120 "./asn1/p22/packet-p22-template.c"
};
static gint *ett[] = {
&ett_p22,
#line 1 "./asn1/p22/packet-p22-ettarr.c"
&ett_p22_InformationObject,
&ett_p22_IPM,
&ett_p22_IPMSExtension,
&ett_p22_Heading,
&ett_p22_IPMIdentifier_U,
&ett_p22_RecipientSpecifier,
&ett_p22_ORDescriptor,
&ett_p22_NotificationRequests,
&ett_p22_RecipientExtensionsField,
&ett_p22_AuthorizingUsersField,
&ett_p22_PrimaryRecipientsField,
&ett_p22_CopyRecipientsField,
&ett_p22_BlindCopyRecipientsField,
&ett_p22_ObsoletedIPMsField,
&ett_p22_RelatedIPMsField,
&ett_p22_ReplyRecipientsField,
&ett_p22_ExtensionsField,
&ett_p22_Body,
&ett_p22_BodyPart,
&ett_p22_T_basic,
&ett_p22_ExtendedBodyPart,
&ett_p22_IA5TextBodyPart,
&ett_p22_IA5TextParameters,
&ett_p22_G3FacsimileBodyPart,
&ett_p22_G3FacsimileParameters,
&ett_p22_G3FacsimileData,
&ett_p22_G4Class1BodyPart,
&ett_p22_MixedModeBodyPart,
&ett_p22_TeletexBodyPart,
&ett_p22_TeletexParameters,
&ett_p22_TeletexData,
&ett_p22_VideotexBodyPart,
&ett_p22_VideotexParameters,
&ett_p22_EncryptedBodyPart,
&ett_p22_EncryptedParameters,
&ett_p22_MessageBodyPart,
&ett_p22_MessageParameters,
&ett_p22_IPN,
&ett_p22_CommonFields,
&ett_p22_NonReceiptFields,
&ett_p22_ReceiptFields,
&ett_p22_NotificationExtensionsField,
&ett_p22_NRNExtensionsField,
&ett_p22_RNExtensionsField,
&ett_p22_OtherNotificationTypeFields,
&ett_p22_AbsenceAdvice,
&ett_p22_ChangeOfAddressAdvice,
&ett_p22_IPMAssemblyInstructions,
&ett_p22_BodyPartReferences,
&ett_p22_BodyPartReference,
&ett_p22_T_stored_body_part,
&ett_p22_Languages,
&ett_p22_BodyPartSignatures,
&ett_p22_BodyPartSignatures_item,
&ett_p22_Signature,
&ett_p22_IPMSecurityLabel,
&ett_p22_SEQUENCE_OF_BodyPartSecurityLabel,
&ett_p22_BodyPartSecurityLabel,
&ett_p22_CirculationList,
&ett_p22_CirculationMember,
&ett_p22_Checkmark,
&ett_p22_CirculationSignatureData,
&ett_p22_CirculationSignature,
&ett_p22_DistributionCodes,
&ett_p22_DistributionCode,
&ett_p22_InformationCategories,
&ett_p22_InformationCategory,
&ett_p22_ManualHandlingInstructions,
&ett_p22_GeneralTextParameters,
&ett_p22_FileTransferParameters,
&ett_p22_FileTransferData,
&ett_p22_RelatedStoredFile,
&ett_p22_RelatedStoredFile_item,
&ett_p22_FileIdentifier,
&ett_p22_PathnameandVersion,
&ett_p22_CrossReference,
&ett_p22_MessageReference,
&ett_p22_Relationship,
&ett_p22_Contents_Type_Attribute,
&ett_p22_T_document_type,
&ett_p22_T_constraint_set_and_abstract_syntax,
&ett_p22_EnvironmentParameter,
&ett_p22_T_user_visible_string,
&ett_p22_GeneralIdentifier,
&ett_p22_T_descriptive_identifier,
&ett_p22_CompressionParameter,
&ett_p22_FileAttributes,
&ett_p22_Pathname_Attribute,
&ett_p22_Account_Attribute,
&ett_p22_User_Identity_Attribute,
&ett_p22_Access_Control_Attribute,
&ett_p22_SET_OF_Access_Control_Element,
&ett_p22_Access_Control_Element,
&ett_p22_Access_Request,
&ett_p22_Access_Passwords,
&ett_p22_Password,
&ett_p22_Pass_Passwords,
&ett_p22_Application_Entity_Title,
&ett_p22_VoiceParameters,
&ett_p22_ForwardedContentParameters,
&ett_p22_SubmissionProof,
&ett_p22_IPMSynopsis,
&ett_p22_BodyPartSynopsis,
&ett_p22_MessageBodyPartSynopsis,
&ett_p22_NonMessageBodyPartSynopsis,
&ett_p22_BodyPartDescriptor,
&ett_p22_BodyPartSignatureVerification,
&ett_p22_BodyPartSignatureVerification_item,
&ett_p22_IPMLocation,
&ett_p22_SET_OF_SequenceNumber,
&ett_p22_CorrelatedDeliveredReplies,
&ett_p22_SEQUENCE_OF_SequenceNumber,
&ett_p22_CorrelatedDeliveredIPNs,
&ett_p22_RecipientSecurityRequest,
&ett_p22_IpnSecurityResponse,
&ett_p22_T_content_or_arguments,
&ett_p22_T_original_security_arguments,
&ett_p22_BodyPartTokens,
&ett_p22_BodyPartTokens_item,
&ett_p22_T_body_part_choice,
&ett_p22_EncryptionToken,
&ett_p22_ForwardedContentToken,
&ett_p22_ForwardedContentToken_item,
&ett_p22_T_body_part_token_choice,
&ett_p22_T_choice,
#line 126 "./asn1/p22/packet-p22-template.c"
};
proto_p22 = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("p22", dissect_p22, proto_p22);
proto_register_field_array(proto_p22, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_p22(void) {
#line 1 "./asn1/p22/packet-p22-dis-tab.c"
register_ber_oid_dissector("2.6.1.19.0", dissect_AbsenceAdvice_PDU, proto_p22, "id-on-absence-advice");
register_ber_oid_dissector("2.6.1.19.1", dissect_ChangeOfAddressAdvice_PDU, proto_p22, "id-on-change-of-address-advice");
register_ber_oid_dissector("2.6.1.17.2", dissect_IPMAssemblyInstructions_PDU, proto_p22, "id-mst-assembly-instructions");
register_ber_oid_dissector("2.6.1.5.0", dissect_IncompleteCopy_PDU, proto_p22, "id-hex-incomplete-copy");
register_ber_oid_dissector("2.6.1.5.1", dissect_Languages_PDU, proto_p22, "id-hex-languages");
register_ber_oid_dissector("2.6.1.5.2", dissect_AutoSubmitted_PDU, proto_p22, "id-hex-auto-submitted");
register_ber_oid_dissector("2.6.1.5.3", dissect_BodyPartSignatures_PDU, proto_p22, "id-hex-body-part-signatures");
register_ber_oid_dissector("2.6.1.5.4", dissect_IPMSecurityLabel_PDU, proto_p22, "id-hex-ipm-security-label");
register_ber_oid_dissector("2.6.1.5.5", dissect_AuthorizationTime_PDU, proto_p22, "id-hex-authorization-time");
register_ber_oid_dissector("2.6.1.5.6", dissect_CirculationList_PDU, proto_p22, "id-hex-circulation-list-recipients");
register_ber_oid_dissector("2.6.1.20.0", dissect_CirculationListIndicator_PDU, proto_p22, "id-rex-circulation-list-indicator");
register_ber_oid_dissector("2.6.1.5.7", dissect_DistributionCodes_PDU, proto_p22, "id-hex-distribution-codes");
register_ber_oid_dissector("2.6.1.5.8", dissect_ExtendedSubject_PDU, proto_p22, "id-hex-extended-subject");
register_ber_oid_dissector("2.6.1.5.9", dissect_InformationCategories_PDU, proto_p22, "id-hex-information-categories");
register_ber_oid_dissector("2.6.1.5.10", dissect_ManualHandlingInstructions_PDU, proto_p22, "id-hex-manual-handling-instructions");
register_ber_oid_dissector("2.6.1.5.11", dissect_OriginatorsReference_PDU, proto_p22, "id-hex-originators-reference");
register_ber_oid_dissector("2.6.1.5.12", dissect_PrecedencePolicyIdentifier_PDU, proto_p22, "id-hex-precedence-policy-id");
register_ber_oid_dissector("2.6.1.20.1", dissect_Precedence_PDU, proto_p22, "id-rex-precedence");
register_ber_oid_dissector("2.6.1.4.0", dissect_IA5TextData_PDU, proto_p22, "id-et-ia5-text");
register_ber_oid_dissector("2.6.1.11.0", dissect_IA5TextParameters_PDU, proto_p22, "id-ep-ia5-text");
register_ber_oid_dissector("2.6.1.4.2", dissect_G3FacsimileData_PDU, proto_p22, "id-et-g3-facsimile");
register_ber_oid_dissector("2.6.1.11.2", dissect_G3FacsimileParameters_PDU, proto_p22, "id-ep-g3-facsimile");
register_ber_oid_dissector("2.6.1.4.3", dissect_G4Class1BodyPart_PDU, proto_p22, "id-et-g4-class1");
register_ber_oid_dissector("2.6.1.4.4", dissect_TeletexData_PDU, proto_p22, "id-et-teletex");
register_ber_oid_dissector("2.6.1.11.4", dissect_TeletexParameters_PDU, proto_p22, "id-ep-teletex");
register_ber_oid_dissector("2.6.1.4.5", dissect_VideotexData_PDU, proto_p22, "id-et-videotex");
register_ber_oid_dissector("2.6.1.11.5", dissect_VideotexParameters_PDU, proto_p22, "id-ep-videotex");
register_ber_oid_dissector("2.6.1.4.6", dissect_EncryptedData_PDU, proto_p22, "id-et-encrypted");
register_ber_oid_dissector("2.6.1.11.6", dissect_EncryptedParameters_PDU, proto_p22, "id-ep-encrypted");
register_ber_oid_dissector("2.6.1.4.7", dissect_MessageData_PDU, proto_p22, "id-et-message");
register_ber_oid_dissector("2.6.1.11.7", dissect_MessageParameters_PDU, proto_p22, "id-ep-message");
register_ber_oid_dissector("2.6.1.4.8", dissect_MixedModeBodyPart_PDU, proto_p22, "id-et-mixed-mode");
register_ber_oid_dissector("2.6.1.4.9", dissect_BilaterallyDefinedBodyPart_PDU, proto_p22, "id-et-bilaterally-defined");
register_ber_oid_dissector("2.6.1.11.11", dissect_GeneralTextParameters_PDU, proto_p22, "id-ep-general-text");
register_ber_oid_dissector("2.6.1.4.11", dissect_GeneralTextData_PDU, proto_p22, "id-et-general-text");
register_ber_oid_dissector("2.6.1.11.12", dissect_FileTransferParameters_PDU, proto_p22, "id-ep-file-transfer");
register_ber_oid_dissector("2.6.1.4.12", dissect_FileTransferData_PDU, proto_p22, "id-et-file-transfer");
register_ber_oid_dissector("2.6.1.11.15", dissect_MessageParameters_PDU, proto_p22, "id-ep-notification");
register_ber_oid_dissector("2.6.1.4.15", dissect_IPN_PDU, proto_p22, "id-et-notification");
register_ber_oid_dissector("2.6.1.11.16", dissect_VoiceParameters_PDU, proto_p22, "id-ep-voice");
register_ber_oid_dissector("2.6.1.4.16", dissect_VoiceData_PDU, proto_p22, "id-et-voice");
register_ber_oid_dissector("2.6.1.11.17.2.6.1.10.1", dissect_ForwardedContentParameters_PDU, proto_p22, "id-ep-content-p22");
register_ber_oid_dissector("2.6.1.4.17.2.6.1.10.1", dissect_InformationObject_PDU, proto_p22, "id-et-content-p22");
register_ber_oid_dissector("2.6.1.11.17.2.6.1.10.0", dissect_ForwardedContentParameters_PDU, proto_p22, "id-ep-content-p2");
register_ber_oid_dissector("2.6.1.4.17.2.6.1.10.0", dissect_InformationObject_PDU, proto_p22, "id-et-content-p2");
register_ber_oid_dissector("2.6.1.11.17.1.3.26.0.4406.0.4.1", dissect_ForwardedContentParameters_PDU, proto_p22, "id-ep-content-p772");
register_ber_oid_dissector("2.6.1.6.0", dissect_IPMEntryType_PDU, proto_p22, "id-sat-ipm-entry-type");
register_ber_oid_dissector("2.6.1.6.1", dissect_IPMSynopsis_PDU, proto_p22, "id-sat-ipm-synopsis");
register_ber_oid_dissector("2.6.1.6.2", dissect_BodyPartDescriptor_PDU, proto_p22, "id-sat-body-parts-summary");
register_ber_oid_dissector("2.6.1.7.0", dissect_Heading_PDU, proto_p22, "id-hat-heading");
register_ber_oid_dissector("2.6.1.7.1", dissect_ThisIPMField_PDU, proto_p22, "id-hat-this-ipm");
register_ber_oid_dissector("2.6.1.7.2", dissect_OriginatorField_PDU, proto_p22, "id-hat-originator");
register_ber_oid_dissector("2.6.1.7.3", dissect_RepliedToIPMField_PDU, proto_p22, "id-hat-replied-to-IPM");
register_ber_oid_dissector("2.6.1.7.4", dissect_SubjectField_PDU, proto_p22, "id-hat-subject");
register_ber_oid_dissector("2.6.1.7.5", dissect_ExpiryTimeField_PDU, proto_p22, "id-hat-expiry-time");
register_ber_oid_dissector("2.6.1.7.6", dissect_ReplyTimeField_PDU, proto_p22, "id-hat-reply-time");
register_ber_oid_dissector("2.6.1.7.7", dissect_ImportanceField_PDU, proto_p22, "id-hat-importance");
register_ber_oid_dissector("2.6.1.7.8", dissect_SensitivityField_PDU, proto_p22, "id-hat-sensitivity");
register_ber_oid_dissector("2.6.1.7.9", dissect_AutoForwardedField_PDU, proto_p22, "id-hat-auto-forwarded");
register_ber_oid_dissector("2.6.1.7.10", dissect_AuthorizingUsersSubfield_PDU, proto_p22, "id-hat-authorizing-users");
register_ber_oid_dissector("2.6.1.7.11", dissect_PrimaryRecipientsSubfield_PDU, proto_p22, "id-hat-primary-recipients");
register_ber_oid_dissector("2.6.1.7.12", dissect_CopyRecipientsSubfield_PDU, proto_p22, "id-hat-copy-recipients");
register_ber_oid_dissector("2.6.1.7.13", dissect_BlindCopyRecipientsSubfield_PDU, proto_p22, "id-hat-blind-copy-recipients");
register_ber_oid_dissector("2.6.1.7.14", dissect_ObsoletedIPMsSubfield_PDU, proto_p22, "id-hat-obsoleted-IPMs");
register_ber_oid_dissector("2.6.1.7.15", dissect_RelatedIPMsSubfield_PDU, proto_p22, "id-hat-related-IPMs");
register_ber_oid_dissector("2.6.1.7.16", dissect_ReplyRecipientsSubfield_PDU, proto_p22, "id-hat-reply-recipients");
register_ber_oid_dissector("2.6.1.7.17", dissect_IncompleteCopy_PDU, proto_p22, "id-hat-incomplete-copy");
register_ber_oid_dissector("2.6.1.7.18", dissect_Language_PDU, proto_p22, "id-hat-languages");
register_ber_oid_dissector("2.6.1.7.19", dissect_ORDescriptor_PDU, proto_p22, "id-hat-rn-requestors");
register_ber_oid_dissector("2.6.1.7.20", dissect_ORDescriptor_PDU, proto_p22, "id-hat-nrn-requestors");
register_ber_oid_dissector("2.6.1.7.21", dissect_ORDescriptor_PDU, proto_p22, "id-hat-reply-requestors");
register_ber_oid_dissector("2.6.1.7.22", dissect_AutoSubmitted_PDU, proto_p22, "id-hat-auto-submitted");
register_ber_oid_dissector("2.6.1.7.23", dissect_BodyPartSignatures_PDU, proto_p22, "id-hat-body-part-signatures");
register_ber_oid_dissector("2.6.1.7.24", dissect_IPMSecurityLabel_PDU, proto_p22, "id-hat-ipm-security-label");
register_ber_oid_dissector("2.6.1.7.25", dissect_BodyPartSecurityLabel_PDU, proto_p22, "id-hat-body-part-security-label");
register_ber_oid_dissector("2.6.1.7.26", dissect_BodyPartTokens_PDU, proto_p22, "id-hat-body-part-encryption-token");
register_ber_oid_dissector("2.6.1.7.27", dissect_AuthorizationTime_PDU, proto_p22, "id-hat-authorization-time");
register_ber_oid_dissector("2.6.1.7.28", dissect_CirculationMember_PDU, proto_p22, "id-hat-circulation-list-recipients");
register_ber_oid_dissector("2.6.1.7.29", dissect_DistributionCode_PDU, proto_p22, "id-hat-distribution-codes");
register_ber_oid_dissector("2.6.1.7.30", dissect_ExtendedSubject_PDU, proto_p22, "id-hat-extended-subject");
register_ber_oid_dissector("2.6.1.7.31", dissect_InformationCategory_PDU, proto_p22, "id-hat-information-category");
register_ber_oid_dissector("2.6.1.7.32", dissect_ManualHandlingInstruction_PDU, proto_p22, "id-hat-manual-handling-instructions");
register_ber_oid_dissector("2.6.1.7.33", dissect_OriginatorsReference_PDU, proto_p22, "id-hat-originators-reference");
register_ber_oid_dissector("2.6.1.7.34", dissect_PrecedencePolicyIdentifier_PDU, proto_p22, "id-hat-precedence-policy-id");
register_ber_oid_dissector("2.6.1.7.35", dissect_ForwardedContentToken_PDU, proto_p22, "id-hat-forwarded-content-token");
register_ber_oid_dissector("2.6.1.7.37", dissect_Precedence_PDU, proto_p22, "id-hat-precedence");
register_ber_oid_dissector("2.6.1.7.38", dissect_BodyPartSignatureVerification_PDU, proto_p22, "id-hat-body-part-signature-verification-status");
register_ber_oid_dissector("2.6.1.8.0", dissect_Body_PDU, proto_p22, "id-bat-body");
register_ber_oid_dissector("2.6.1.13.0", dissect_CorrelatedDeliveredIPNs_PDU, proto_p22, "id-cat-correlated-delivered-ipns");
register_ber_oid_dissector("2.6.1.13.1", dissect_CorrelatedDeliveredReplies_PDU, proto_p22, "id-cat-correlated-delivered-replies");
register_ber_oid_dissector("2.6.1.13.2", dissect_DeliveredIPNStatus_PDU, proto_p22, "id-cat-delivered-ipn-summary");
register_ber_oid_dissector("2.6.1.13.3", dissect_DeliveredReplyStatus_PDU, proto_p22, "id-cat-delivered-replies-summary");
register_ber_oid_dissector("2.6.1.13.7", dissect_IPMLocation_PDU, proto_p22, "id-cat-obsoleted-ipms");
register_ber_oid_dissector("2.6.1.13.14", dissect_SubmittedIPNStatus_PDU, proto_p22, "id-cat-submitted-ipn-status");
register_ber_oid_dissector("2.6.1.13.16", dissect_SubmittedReplyStatus_PDU, proto_p22, "id-cat-submitted-reply-status");
register_ber_oid_dissector("2.6.1.13.18", dissect_RecipientCategory_PDU, proto_p22, "id-cat-recipient-category");
register_ber_oid_dissector("2.6.1.18.0", dissect_RecipientSecurityRequest_PDU, proto_p22, "id-sec-ipm-security-request");
register_ber_oid_dissector("2.6.1.18.1", dissect_IpnSecurityResponse_PDU, proto_p22, "id-sec-security-common-fields");
#line 142 "./asn1/p22/packet-p22-template.c"
register_ber_oid_dissector("2.6.1.10.0", dissect_p22, proto_p22, "InterPersonal Message (1984)");
register_ber_oid_dissector("2.6.1.10.1", dissect_p22, proto_p22, "InterPersonal Message (1988)");
}
