static int
dissect_h501_ElementIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
1, 128, FALSE);
return offset;
}
static int
dissect_h501_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h501_T_algorithmOIDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_T_algorithmOIDs, T_algorithmOIDs_sequence_of);
return offset;
}
static int
dissect_h501_SecurityMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_SecurityMode, SecurityMode_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_SecurityMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_SecurityMode, SEQUENCE_OF_SecurityMode_sequence_of);
return offset;
}
static int
dissect_h501_INTEGER_1_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h501_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h501_INTEGER_1_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h501_T_when(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_T_when, T_when_sequence);
return offset;
}
static int
dissect_h501_T_required(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_T_required, T_required_sequence_of);
return offset;
}
static int
dissect_h501_T_preferred(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_T_preferred, T_preferred_sequence_of);
return offset;
}
static int
dissect_h501_UsageSpecification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageSpecification, UsageSpecification_sequence);
return offset;
}
static int
dissect_h501_ServiceRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceRequest, ServiceRequest_sequence);
return offset;
}
static int
dissect_h501_INTEGER_1_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h501_AlternatePE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AlternatePE, AlternatePE_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_AlternatePE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_AlternatePE, SEQUENCE_OF_AlternatePE_sequence_of);
return offset;
}
static int
dissect_h501_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h501_AlternatePEInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AlternatePEInfo, AlternatePEInfo_sequence);
return offset;
}
static int
dissect_h501_ServiceConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceConfirmation, ServiceConfirmation_sequence);
return offset;
}
static int
dissect_h501_ServiceRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceRejectionReason, ServiceRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_ServiceRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceRejection, ServiceRejection_sequence);
return offset;
}
static int
dissect_h501_ServiceReleaseReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceReleaseReason, ServiceReleaseReason_choice,
NULL);
return offset;
}
static int
dissect_h501_ServiceRelease(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ServiceRelease, ServiceRelease_sequence);
return offset;
}
static int
dissect_h501_DescriptorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h225_GloballyUniqueID(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_DescriptorID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_DescriptorID, SEQUENCE_OF_DescriptorID_sequence_of);
return offset;
}
static int
dissect_h501_DescriptorRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorRequest, DescriptorRequest_sequence);
return offset;
}
static int
dissect_h501_GlobalTimeStamp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
14, 14, FALSE);
return offset;
}
static int
dissect_h501_DescriptorInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorInfo, DescriptorInfo_sequence);
return offset;
}
static int
dissect_h501_T_range(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_T_range, T_range_sequence);
return offset;
}
static int
dissect_h501_Pattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_Pattern, Pattern_choice,
NULL);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_Pattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_Pattern, SEQUENCE_OF_Pattern_sequence_of);
return offset;
}
static int
dissect_h501_T_messageType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_T_messageType, T_messageType_choice,
NULL);
return offset;
}
static int
dissect_h501_IA5String_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
3, 3, FALSE);
return offset;
}
static int
dissect_h501_INTEGER_M127_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h501_IA5String_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
6, 6, FALSE);
return offset;
}
static int
dissect_h501_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h501_T_units(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_T_units, T_units_choice,
NULL);
return offset;
}
static int
dissect_h501_PriceElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_PriceElement, PriceElement_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_PriceElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_PriceElement, SEQUENCE_OF_PriceElement_sequence_of);
return offset;
}
static int
dissect_h501_IA5String_SIZE_1_2048(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_IA5String(tvb, offset, actx, tree, hf_index,
1, 2048, FALSE);
return offset;
}
static int
dissect_h501_PriceInfoSpec(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_PriceInfoSpec, PriceInfoSpec_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_PriceInfoSpec(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_PriceInfoSpec, SEQUENCE_OF_PriceInfoSpec_sequence_of);
return offset;
}
static int
dissect_h501_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h501_AccessToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_AccessToken, AccessToken_choice,
NULL);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_AccessToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_AccessToken, SEQUENCE_OF_AccessToken_sequence_of);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_CircuitIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_CircuitIdentifier, SEQUENCE_OF_CircuitIdentifier_sequence_of);
return offset;
}
static int
dissect_h501_ContactInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ContactInformation, ContactInformation_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_ContactInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_ContactInformation, SEQUENCE_OF_ContactInformation_sequence_of);
return offset;
}
static int
dissect_h501_RouteInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_RouteInformation, RouteInformation_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_RouteInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_RouteInformation, SEQUENCE_OF_RouteInformation_sequence_of);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_SupportedProtocols(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_SupportedProtocols, SEQUENCE_OF_SupportedProtocols_sequence_of);
return offset;
}
static int
dissect_h501_AddressTemplate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AddressTemplate, AddressTemplate_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_AddressTemplate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_AddressTemplate, SEQUENCE_OF_AddressTemplate_sequence_of);
return offset;
}
static int
dissect_h501_Descriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_Descriptor, Descriptor_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_Descriptor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_Descriptor, SEQUENCE_OF_Descriptor_sequence_of);
return offset;
}
static int
dissect_h501_DescriptorConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorConfirmation, DescriptorConfirmation_sequence);
return offset;
}
static int
dissect_h501_DescriptorRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorRejectionReason, DescriptorRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_DescriptorRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorRejection, DescriptorRejection_sequence);
return offset;
}
static int
dissect_h501_DescriptorIDRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorIDRequest, DescriptorIDRequest_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_DescriptorInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_DescriptorInfo, SEQUENCE_OF_DescriptorInfo_sequence_of);
return offset;
}
static int
dissect_h501_DescriptorIDConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorIDConfirmation, DescriptorIDConfirmation_sequence);
return offset;
}
static int
dissect_h501_DescriptorIDRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorIDRejectionReason, DescriptorIDRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_DescriptorIDRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorIDRejection, DescriptorIDRejection_sequence);
return offset;
}
static int
dissect_h501_T_descriptorInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_T_descriptorInfo, T_descriptorInfo_choice,
NULL);
return offset;
}
static int
dissect_h501_T_updateType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_T_updateType, T_updateType_choice,
NULL);
return offset;
}
static int
dissect_h501_UpdateInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UpdateInformation, UpdateInformation_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_UpdateInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_UpdateInformation, SEQUENCE_OF_UpdateInformation_sequence_of);
return offset;
}
static int
dissect_h501_DescriptorUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorUpdate, DescriptorUpdate_sequence);
return offset;
}
static int
dissect_h501_DescriptorUpdateAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_DescriptorUpdateAck, DescriptorUpdateAck_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_AliasAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_AliasAddress, SEQUENCE_OF_AliasAddress_sequence_of);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_CryptoH323Token(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_CryptoH323Token, SEQUENCE_OF_CryptoH323Token_sequence_of);
return offset;
}
static int
dissect_h501_UserInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UserInformation, UserInformation_sequence);
return offset;
}
static int
dissect_h501_TimeZone(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-43200, 43200U, NULL, FALSE);
return offset;
}
static int
dissect_h501_PartyInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_PartyInformation, PartyInformation_sequence);
return offset;
}
static int
dissect_h501_CallInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_CallInformation, CallInformation_sequence);
return offset;
}
static int
dissect_h501_AccessRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AccessRequest, AccessRequest_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_ServiceControlSession(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_ServiceControlSession, SEQUENCE_OF_ServiceControlSession_sequence_of);
return offset;
}
static int
dissect_h501_AccessConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AccessConfirmation, AccessConfirmation_sequence);
return offset;
}
static int
dissect_h501_AccessRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_AccessRejectionReason, AccessRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_AccessRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AccessRejection, AccessRejection_sequence);
return offset;
}
static int
dissect_h501_RequestInProgress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_RequestInProgress, RequestInProgress_sequence);
return offset;
}
static int
dissect_h501_NonStandardRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_NonStandardRequest, NonStandardRequest_sequence);
return offset;
}
static int
dissect_h501_NonStandardConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_NonStandardConfirmation, NonStandardConfirmation_sequence);
return offset;
}
static int
dissect_h501_NonStandardRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_NonStandardRejectionReason, NonStandardRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_NonStandardRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_NonStandardRejection, NonStandardRejection_sequence);
return offset;
}
static int
dissect_h501_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h501_UnknownMessageReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_UnknownMessageReason, UnknownMessageReason_choice,
NULL);
return offset;
}
static int
dissect_h501_UnknownMessageResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UnknownMessageResponse, UnknownMessageResponse_sequence);
return offset;
}
static int
dissect_h501_UsageRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageRequest, UsageRequest_sequence);
return offset;
}
static int
dissect_h501_UsageConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageConfirmation, UsageConfirmation_sequence);
return offset;
}
static int
dissect_h501_Role(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_Role, Role_choice,
NULL);
return offset;
}
static int
dissect_h501_UsageCallStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_UsageCallStatus, UsageCallStatus_choice,
NULL);
return offset;
}
static int
dissect_h501_TerminationCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_TerminationCause, TerminationCause_sequence);
return offset;
}
static int
dissect_h501_UsageField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageField, UsageField_sequence);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_UsageField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_UsageField, SEQUENCE_OF_UsageField_sequence_of);
return offset;
}
static int
dissect_h501_UsageIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageIndication, UsageIndication_sequence);
return offset;
}
static int
dissect_h501_UsageIndicationConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageIndicationConfirmation, UsageIndicationConfirmation_sequence);
return offset;
}
static int
dissect_h501_UsageIndicationRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_UsageIndicationRejectionReason, UsageIndicationRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_UsageIndicationRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageIndicationRejection, UsageIndicationRejection_sequence);
return offset;
}
static int
dissect_h501_UsageRejectReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_UsageRejectReason, UsageRejectReason_choice,
NULL);
return offset;
}
static int
dissect_h501_UsageRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_UsageRejection, UsageRejection_sequence);
return offset;
}
static int
dissect_h501_ValidationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ValidationRequest, ValidationRequest_sequence);
return offset;
}
static int
dissect_h501_ValidationConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ValidationConfirmation, ValidationConfirmation_sequence);
return offset;
}
static int
dissect_h501_ValidationRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_ValidationRejectionReason, ValidationRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_ValidationRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_ValidationRejection, ValidationRejection_sequence);
return offset;
}
static int
dissect_h501_ApplicationMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h501_AuthenticationRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AuthenticationRequest, AuthenticationRequest_sequence);
return offset;
}
static int
dissect_h501_AuthenticationConfirmation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AuthenticationConfirmation, AuthenticationConfirmation_sequence);
return offset;
}
static int
dissect_h501_AuthenticationRejectionReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_AuthenticationRejectionReason, AuthenticationRejectionReason_choice,
NULL);
return offset;
}
static int
dissect_h501_AuthenticationRejection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_AuthenticationRejection, AuthenticationRejection_sequence);
return offset;
}
static int
dissect_h501_MessageBody(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 22 "../../asn1/h501/h501.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h501_MessageBody, MessageBody_choice,
&msg_type);
#line 25 "../../asn1/h501/h501.cnf"
p = match_strval(msg_type, VALS(h501_MessageBody_vals));
if (p )
col_set_str(actx->pinfo->cinfo, COL_INFO, p);
return offset;
}
static int
dissect_h501_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h501_ProtocolVersion(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h501_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_TransportAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_TransportAddress, SEQUENCE_OF_TransportAddress_sequence_of);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_ClearToken(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_ClearToken, SEQUENCE_OF_ClearToken_sequence_of);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_NonStandardParameter, SEQUENCE_OF_NonStandardParameter_sequence_of);
return offset;
}
static int
dissect_h501_ServiceID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_h225_GloballyUniqueID(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h501_SEQUENCE_OF_GenericData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
ett_h501_SEQUENCE_OF_GenericData, SEQUENCE_OF_GenericData_sequence_of);
return offset;
}
static int
dissect_h501_MessageCommonInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_MessageCommonInfo, MessageCommonInfo_sequence);
return offset;
}
static int
dissect_h501_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h501_Message, Message_sequence);
return offset;
}
static int dissect_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h501_Message(tvb, offset, &asn1_ctx, tree, hf_h501_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h501_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *h501_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
ti = proto_tree_add_item(tree, proto_h501, tvb, 0, -1, ENC_NA);
h501_tree = proto_item_add_subtree(ti, ett_h501);
return dissect_Message_PDU(tvb, pinfo, h501_tree);
}
static int
dissect_h501_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_tpkt_encap(tvb, pinfo, tree, FALSE, h501_pdu_handle);
return tvb_length(tvb);
}
static int
dissect_h501_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_tpkt_encap(tvb, pinfo, tree, h501_desegment_tcp, h501_pdu_handle);
return tvb_length(tvb);
}
void proto_register_h501(void) {
module_t *h501_module;
static hf_register_info hf[] = {
#line 1 "../../asn1/h501/packet-h501-hfarr.c"
{ &hf_h501_Message_PDU,
{ "Message", "h501.Message",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_body,
{ "body", "h501.body",
FT_UINT32, BASE_DEC, VALS(h501_MessageBody_vals), 0,
"MessageBody", HFILL }},
{ &hf_h501_common,
{ "common", "h501.common",
FT_NONE, BASE_NONE, NULL, 0,
"MessageCommonInfo", HFILL }},
{ &hf_h501_serviceRequest,
{ "serviceRequest", "h501.serviceRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_serviceConfirmation,
{ "serviceConfirmation", "h501.serviceConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_serviceRejection,
{ "serviceRejection", "h501.serviceRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_serviceRelease,
{ "serviceRelease", "h501.serviceRelease",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorRequest,
{ "descriptorRequest", "h501.descriptorRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorConfirmation,
{ "descriptorConfirmation", "h501.descriptorConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorRejection,
{ "descriptorRejection", "h501.descriptorRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorIDRequest,
{ "descriptorIDRequest", "h501.descriptorIDRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorIDConfirmation,
{ "descriptorIDConfirmation", "h501.descriptorIDConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorIDRejection,
{ "descriptorIDRejection", "h501.descriptorIDRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorUpdate,
{ "descriptorUpdate", "h501.descriptorUpdate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorUpdateAck,
{ "descriptorUpdateAck", "h501.descriptorUpdateAck",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_accessRequest,
{ "accessRequest", "h501.accessRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_accessConfirmation,
{ "accessConfirmation", "h501.accessConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_accessRejection,
{ "accessRejection", "h501.accessRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_requestInProgress,
{ "requestInProgress", "h501.requestInProgress",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_nonStandardRequest,
{ "nonStandardRequest", "h501.nonStandardRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_nonStandardConfirmation,
{ "nonStandardConfirmation", "h501.nonStandardConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_nonStandardRejection,
{ "nonStandardRejection", "h501.nonStandardRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_unknownMessageResponse,
{ "unknownMessageResponse", "h501.unknownMessageResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageRequest,
{ "usageRequest", "h501.usageRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageConfirmation,
{ "usageConfirmation", "h501.usageConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageIndication,
{ "usageIndication", "h501.usageIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageIndicationConfirmation,
{ "usageIndicationConfirmation", "h501.usageIndicationConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageIndicationRejection,
{ "usageIndicationRejection", "h501.usageIndicationRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageRejection,
{ "usageRejection", "h501.usageRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_validationRequest,
{ "validationRequest", "h501.validationRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_validationConfirmation,
{ "validationConfirmation", "h501.validationConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_validationRejection,
{ "validationRejection", "h501.validationRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_authenticationRequest,
{ "authenticationRequest", "h501.authenticationRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_authenticationConfirmation,
{ "authenticationConfirmation", "h501.authenticationConfirmation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_authenticationRejection,
{ "authenticationRejection", "h501.authenticationRejection",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_sequenceNumber,
{ "sequenceNumber", "h501.sequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h501_annexGversion,
{ "annexGversion", "h501.annexGversion",
FT_OID, BASE_NONE, NULL, 0,
"ProtocolVersion", HFILL }},
{ &hf_h501_hopCount,
{ "hopCount", "h501.hopCount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h501_replyAddress,
{ "replyAddress", "h501.replyAddress",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_TransportAddress", HFILL }},
{ &hf_h501_replyAddress_item,
{ "TransportAddress", "h501.TransportAddress",
FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
NULL, HFILL }},
{ &hf_h501_integrityCheckValue,
{ "integrityCheckValue", "h501.integrityCheckValue",
FT_NONE, BASE_NONE, NULL, 0,
"ICV", HFILL }},
{ &hf_h501_tokens,
{ "tokens", "h501.tokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ClearToken", HFILL }},
{ &hf_h501_tokens_item,
{ "ClearToken", "h501.ClearToken",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_cryptoTokens,
{ "cryptoTokens", "h501.cryptoTokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CryptoH323Token", HFILL }},
{ &hf_h501_cryptoTokens_item,
{ "CryptoH323Token", "h501.CryptoH323Token",
FT_UINT32, BASE_DEC, VALS(h225_CryptoH323Token_vals), 0,
NULL, HFILL }},
{ &hf_h501_nonStandard,
{ "nonStandard", "h501.nonStandard",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_NonStandardParameter", HFILL }},
{ &hf_h501_nonStandard_item,
{ "NonStandardParameter", "h501.NonStandardParameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_serviceID,
{ "serviceID", "h501.serviceID",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_genericData,
{ "genericData", "h501.genericData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_GenericData", HFILL }},
{ &hf_h501_genericData_item,
{ "GenericData", "h501.GenericData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_featureSet,
{ "featureSet", "h501.featureSet",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_version,
{ "version", "h501.version",
FT_OID, BASE_NONE, NULL, 0,
"ProtocolVersion", HFILL }},
{ &hf_h501_elementIdentifier,
{ "elementIdentifier", "h501.elementIdentifier",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_domainIdentifier,
{ "domainIdentifier", "h501.domainIdentifier",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_securityMode,
{ "securityMode", "h501.securityMode",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SecurityMode", HFILL }},
{ &hf_h501_securityMode_item,
{ "SecurityMode", "h501.SecurityMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_timeToLive,
{ "timeToLive", "h501.timeToLive",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_4294967295", HFILL }},
{ &hf_h501_usageSpec,
{ "usageSpec", "h501.usageSpec",
FT_NONE, BASE_NONE, NULL, 0,
"UsageSpecification", HFILL }},
{ &hf_h501_authentication,
{ "authentication", "h501.authentication",
FT_UINT32, BASE_DEC, VALS(h235_AuthenticationMechanism_vals), 0,
"AuthenticationMechanism", HFILL }},
{ &hf_h501_integrity,
{ "integrity", "h501.integrity",
FT_UINT32, BASE_DEC, VALS(h225_IntegrityMechanism_vals), 0,
"IntegrityMechanism", HFILL }},
{ &hf_h501_algorithmOIDs,
{ "algorithmOIDs", "h501.algorithmOIDs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h501_algorithmOIDs_item,
{ "algorithmOIDs item", "h501.algorithmOIDs_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h501_alternates,
{ "alternates", "h501.alternates",
FT_NONE, BASE_NONE, NULL, 0,
"AlternatePEInfo", HFILL }},
{ &hf_h501_securityMode_01,
{ "securityMode", "h501.securityMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_ServiceRejectionReason_vals), 0,
"ServiceRejectionReason", HFILL }},
{ &hf_h501_serviceUnavailable,
{ "serviceUnavailable", "h501.serviceUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_serviceRedirected,
{ "serviceRedirected", "h501.serviceRedirected",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_security,
{ "security", "h501.security",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_continue,
{ "continue", "h501.continue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_undefined,
{ "undefined", "h501.undefined",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_unknownServiceID,
{ "unknownServiceID", "h501.unknownServiceID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_cannotSupportUsageSpec,
{ "cannotSupportUsageSpec", "h501.cannotSupportUsageSpec",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_neededFeature,
{ "neededFeature", "h501.neededFeature",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_genericDataReason,
{ "genericDataReason", "h501.genericDataReason",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageUnavailable,
{ "usageUnavailable", "h501.usageUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_unknownUsageSendTo,
{ "unknownUsageSendTo", "h501.unknownUsageSendTo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_01,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_ServiceReleaseReason_vals), 0,
"ServiceReleaseReason", HFILL }},
{ &hf_h501_outOfService,
{ "outOfService", "h501.outOfService",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_maintenance,
{ "maintenance", "h501.maintenance",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_terminated,
{ "terminated", "h501.terminated",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_expired,
{ "expired", "h501.expired",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorID,
{ "descriptorID", "h501.descriptorID",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DescriptorID", HFILL }},
{ &hf_h501_descriptorID_item,
{ "DescriptorID", "h501.DescriptorID",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptor,
{ "descriptor", "h501.descriptor",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Descriptor", HFILL }},
{ &hf_h501_descriptor_item,
{ "Descriptor", "h501.Descriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_02,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_DescriptorRejectionReason_vals), 0,
"DescriptorRejectionReason", HFILL }},
{ &hf_h501_descriptorID_01,
{ "descriptorID", "h501.descriptorID",
FT_GUID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_packetSizeExceeded,
{ "packetSizeExceeded", "h501.packetSizeExceeded",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_illegalID,
{ "illegalID", "h501.illegalID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_hopCountExceeded,
{ "hopCountExceeded", "h501.hopCountExceeded",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_noServiceRelationship,
{ "noServiceRelationship", "h501.noServiceRelationship",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorInfo,
{ "descriptorInfo", "h501.descriptorInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_DescriptorInfo", HFILL }},
{ &hf_h501_descriptorInfo_item,
{ "DescriptorInfo", "h501.DescriptorInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_03,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_DescriptorIDRejectionReason_vals), 0,
"DescriptorIDRejectionReason", HFILL }},
{ &hf_h501_noDescriptors,
{ "noDescriptors", "h501.noDescriptors",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_sender,
{ "sender", "h501.sender",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_updateInfo,
{ "updateInfo", "h501.updateInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_UpdateInformation", HFILL }},
{ &hf_h501_updateInfo_item,
{ "UpdateInformation", "h501.UpdateInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorInfo_01,
{ "descriptorInfo", "h501.descriptorInfo",
FT_UINT32, BASE_DEC, VALS(h501_T_descriptorInfo_vals), 0,
NULL, HFILL }},
{ &hf_h501_descriptor_01,
{ "descriptor", "h501.descriptor",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_updateType,
{ "updateType", "h501.updateType",
FT_UINT32, BASE_DEC, VALS(h501_T_updateType_vals), 0,
NULL, HFILL }},
{ &hf_h501_added,
{ "added", "h501.added",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_deleted,
{ "deleted", "h501.deleted",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_changed,
{ "changed", "h501.changed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_destinationInfo,
{ "destinationInfo", "h501.destinationInfo",
FT_NONE, BASE_NONE, NULL, 0,
"PartyInformation", HFILL }},
{ &hf_h501_sourceInfo,
{ "sourceInfo", "h501.sourceInfo",
FT_NONE, BASE_NONE, NULL, 0,
"PartyInformation", HFILL }},
{ &hf_h501_callInfo,
{ "callInfo", "h501.callInfo",
FT_NONE, BASE_NONE, NULL, 0,
"CallInformation", HFILL }},
{ &hf_h501_desiredProtocols,
{ "desiredProtocols", "h501.desiredProtocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h501_desiredProtocols_item,
{ "SupportedProtocols", "h501.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h501_templates,
{ "templates", "h501.templates",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AddressTemplate", HFILL }},
{ &hf_h501_templates_item,
{ "AddressTemplate", "h501.AddressTemplate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_partialResponse,
{ "partialResponse", "h501.partialResponse",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h501_supportedProtocols,
{ "supportedProtocols", "h501.supportedProtocols",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SupportedProtocols", HFILL }},
{ &hf_h501_supportedProtocols_item,
{ "SupportedProtocols", "h501.SupportedProtocols",
FT_UINT32, BASE_DEC, VALS(h225_SupportedProtocols_vals), 0,
NULL, HFILL }},
{ &hf_h501_serviceControl,
{ "serviceControl", "h501.serviceControl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ServiceControlSession", HFILL }},
{ &hf_h501_serviceControl_item,
{ "ServiceControlSession", "h501.ServiceControlSession",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_04,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_AccessRejectionReason_vals), 0,
"AccessRejectionReason", HFILL }},
{ &hf_h501_noMatch,
{ "noMatch", "h501.noMatch",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_needCallInformation,
{ "needCallInformation", "h501.needCallInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_destinationUnavailable,
{ "destinationUnavailable", "h501.destinationUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_aliasesInconsistent,
{ "aliasesInconsistent", "h501.aliasesInconsistent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_resourceUnavailable,
{ "resourceUnavailable", "h501.resourceUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_incompleteAddress,
{ "incompleteAddress", "h501.incompleteAddress",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_05,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_UsageRejectReason_vals), 0,
"UsageRejectReason", HFILL }},
{ &hf_h501_accessTokens,
{ "accessTokens", "h501.accessTokens",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AccessToken", HFILL }},
{ &hf_h501_accessTokens_item,
{ "AccessToken", "h501.AccessToken",
FT_UINT32, BASE_DEC, VALS(h501_AccessToken_vals), 0,
NULL, HFILL }},
{ &hf_h501_senderRole,
{ "senderRole", "h501.senderRole",
FT_UINT32, BASE_DEC, VALS(h501_Role_vals), 0,
"Role", HFILL }},
{ &hf_h501_usageCallStatus,
{ "usageCallStatus", "h501.usageCallStatus",
FT_UINT32, BASE_DEC, VALS(h501_UsageCallStatus_vals), 0,
NULL, HFILL }},
{ &hf_h501_srcInfo,
{ "srcInfo", "h501.srcInfo",
FT_NONE, BASE_NONE, NULL, 0,
"PartyInformation", HFILL }},
{ &hf_h501_destAddress,
{ "destAddress", "h501.destAddress",
FT_NONE, BASE_NONE, NULL, 0,
"PartyInformation", HFILL }},
{ &hf_h501_startTime,
{ "startTime", "h501.startTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_h501_endTime,
{ "endTime", "h501.endTime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
"TimeStamp", HFILL }},
{ &hf_h501_terminationCause,
{ "terminationCause", "h501.terminationCause",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_usageFields,
{ "usageFields", "h501.usageFields",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_UsageField", HFILL }},
{ &hf_h501_usageFields_item,
{ "UsageField", "h501.UsageField",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_id,
{ "id", "h501.id",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h501_value,
{ "value", "h501.value",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h501_invalidCall,
{ "invalidCall", "h501.invalidCall",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_unavailable,
{ "unavailable", "h501.unavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_06,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_UsageIndicationRejectionReason_vals), 0,
"UsageIndicationRejectionReason", HFILL }},
{ &hf_h501_unknownCall,
{ "unknownCall", "h501.unknownCall",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_incomplete,
{ "incomplete", "h501.incomplete",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_accessToken,
{ "accessToken", "h501.accessToken",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AccessToken", HFILL }},
{ &hf_h501_accessToken_item,
{ "AccessToken", "h501.AccessToken",
FT_UINT32, BASE_DEC, VALS(h501_AccessToken_vals), 0,
NULL, HFILL }},
{ &hf_h501_reason_07,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_ValidationRejectionReason_vals), 0,
"ValidationRejectionReason", HFILL }},
{ &hf_h501_tokenNotValid,
{ "tokenNotValid", "h501.tokenNotValid",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_missingSourceInfo,
{ "missingSourceInfo", "h501.missingSourceInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_missingDestInfo,
{ "missingDestInfo", "h501.missingDestInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_delay,
{ "delay", "h501.delay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h501_reason_08,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_NonStandardRejectionReason_vals), 0,
"NonStandardRejectionReason", HFILL }},
{ &hf_h501_notSupported,
{ "notSupported", "h501.notSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_unknownMessage,
{ "unknownMessage", "h501.unknownMessage",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h501_reason_09,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_UnknownMessageReason_vals), 0,
"UnknownMessageReason", HFILL }},
{ &hf_h501_notUnderstood,
{ "notUnderstood", "h501.notUnderstood",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_applicationMessage,
{ "applicationMessage", "h501.applicationMessage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_reason_10,
{ "reason", "h501.reason",
FT_UINT32, BASE_DEC, VALS(h501_AuthenticationRejectionReason_vals), 0,
"AuthenticationRejectionReason", HFILL }},
{ &hf_h501_securityWrongSyncTime,
{ "securityWrongSyncTime", "h501.securityWrongSyncTime",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_securityReplay,
{ "securityReplay", "h501.securityReplay",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_securityWrongGeneralID,
{ "securityWrongGeneralID", "h501.securityWrongGeneralID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_securityWrongSendersID,
{ "securityWrongSendersID", "h501.securityWrongSendersID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_securityIntegrityFailed,
{ "securityIntegrityFailed", "h501.securityIntegrityFailed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_securityWrongOID,
{ "securityWrongOID", "h501.securityWrongOID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_pattern,
{ "pattern", "h501.pattern",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Pattern", HFILL }},
{ &hf_h501_pattern_item,
{ "Pattern", "h501.Pattern",
FT_UINT32, BASE_DEC, VALS(h501_Pattern_vals), 0,
NULL, HFILL }},
{ &hf_h501_routeInfo,
{ "routeInfo", "h501.routeInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_RouteInformation", HFILL }},
{ &hf_h501_routeInfo_item,
{ "RouteInformation", "h501.RouteInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_specific,
{ "specific", "h501.specific",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_wildcard,
{ "wildcard", "h501.wildcard",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_range,
{ "range", "h501.range",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_startOfRange,
{ "startOfRange", "h501.startOfRange",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_h501_endOfRange,
{ "endOfRange", "h501.endOfRange",
FT_UINT32, BASE_DEC, VALS(h225_PartyNumber_vals), 0,
"PartyNumber", HFILL }},
{ &hf_h501_messageType,
{ "messageType", "h501.messageType",
FT_UINT32, BASE_DEC, VALS(h501_T_messageType_vals), 0,
NULL, HFILL }},
{ &hf_h501_sendAccessRequest,
{ "sendAccessRequest", "h501.sendAccessRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_sendSetup,
{ "sendSetup", "h501.sendSetup",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_nonExistent,
{ "nonExistent", "h501.nonExistent",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_callSpecific,
{ "callSpecific", "h501.callSpecific",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h501_priceInfo,
{ "priceInfo", "h501.priceInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PriceInfoSpec", HFILL }},
{ &hf_h501_priceInfo_item,
{ "PriceInfoSpec", "h501.PriceInfoSpec",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_contacts,
{ "contacts", "h501.contacts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ContactInformation", HFILL }},
{ &hf_h501_contacts_item,
{ "ContactInformation", "h501.ContactInformation",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_type,
{ "type", "h501.type",
FT_NONE, BASE_NONE, NULL, 0,
"EndpointType", HFILL }},
{ &hf_h501_circuitID,
{ "circuitID", "h501.circuitID",
FT_NONE, BASE_NONE, NULL, 0,
"CircuitInfo", HFILL }},
{ &hf_h501_supportedCircuits,
{ "supportedCircuits", "h501.supportedCircuits",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CircuitIdentifier", HFILL }},
{ &hf_h501_supportedCircuits_item,
{ "CircuitIdentifier", "h501.CircuitIdentifier",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_transportAddress,
{ "transportAddress", "h501.transportAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_priority,
{ "priority", "h501.priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_h501_transportQoS,
{ "transportQoS", "h501.transportQoS",
FT_UINT32, BASE_DEC, VALS(h225_TransportQOS_vals), 0,
NULL, HFILL }},
{ &hf_h501_security_01,
{ "security", "h501.security",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_SecurityMode", HFILL }},
{ &hf_h501_security_item,
{ "SecurityMode", "h501.SecurityMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_multipleCalls,
{ "multipleCalls", "h501.multipleCalls",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h501_currency,
{ "currency", "h501.currency",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_3", HFILL }},
{ &hf_h501_currencyScale,
{ "currencyScale", "h501.currencyScale",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M127_127", HFILL }},
{ &hf_h501_validFrom,
{ "validFrom", "h501.validFrom",
FT_STRING, BASE_NONE, NULL, 0,
"GlobalTimeStamp", HFILL }},
{ &hf_h501_validUntil,
{ "validUntil", "h501.validUntil",
FT_STRING, BASE_NONE, NULL, 0,
"GlobalTimeStamp", HFILL }},
{ &hf_h501_hoursFrom,
{ "hoursFrom", "h501.hoursFrom",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_6", HFILL }},
{ &hf_h501_hoursUntil,
{ "hoursUntil", "h501.hoursUntil",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_6", HFILL }},
{ &hf_h501_priceElement,
{ "priceElement", "h501.priceElement",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PriceElement", HFILL }},
{ &hf_h501_priceElement_item,
{ "PriceElement", "h501.PriceElement",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_priceFormula,
{ "priceFormula", "h501.priceFormula",
FT_STRING, BASE_NONE, NULL, 0,
"IA5String_SIZE_1_2048", HFILL }},
{ &hf_h501_amount,
{ "amount", "h501.amount",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h501_quantum,
{ "quantum", "h501.quantum",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_h501_units,
{ "units", "h501.units",
FT_UINT32, BASE_DEC, VALS(h501_T_units_vals), 0,
NULL, HFILL }},
{ &hf_h501_seconds,
{ "seconds", "h501.seconds",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_packets,
{ "packets", "h501.packets",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_bytes,
{ "bytes", "h501.bytes",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_initial,
{ "initial", "h501.initial",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_minimum,
{ "minimum", "h501.minimum",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_maximum,
{ "maximum", "h501.maximum",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_descriptorInfo_02,
{ "descriptorInfo", "h501.descriptorInfo",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_gatekeeperID,
{ "gatekeeperID", "h501.gatekeeperID",
FT_STRING, BASE_NONE, NULL, 0,
"GatekeeperIdentifier", HFILL }},
{ &hf_h501_lastChanged,
{ "lastChanged", "h501.lastChanged",
FT_STRING, BASE_NONE, NULL, 0,
"GlobalTimeStamp", HFILL }},
{ &hf_h501_alternatePE,
{ "alternatePE", "h501.alternatePE",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AlternatePE", HFILL }},
{ &hf_h501_alternatePE_item,
{ "AlternatePE", "h501.AlternatePE",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_alternateIsPermanent,
{ "alternateIsPermanent", "h501.alternateIsPermanent",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h501_contactAddress,
{ "contactAddress", "h501.contactAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_priority_01,
{ "priority", "h501.priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_127", HFILL }},
{ &hf_h501_token,
{ "token", "h501.token",
FT_NONE, BASE_NONE, NULL, 0,
"ClearToken", HFILL }},
{ &hf_h501_cryptoToken,
{ "cryptoToken", "h501.cryptoToken",
FT_UINT32, BASE_DEC, VALS(h225_CryptoH323Token_vals), 0,
"CryptoH323Token", HFILL }},
{ &hf_h501_genericData_01,
{ "genericData", "h501.genericData",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_callIdentifier,
{ "callIdentifier", "h501.callIdentifier",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_conferenceID,
{ "conferenceID", "h501.conferenceID",
FT_GUID, BASE_NONE, NULL, 0,
"ConferenceIdentifier", HFILL }},
{ &hf_h501_preConnect,
{ "preConnect", "h501.preConnect",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_callInProgress,
{ "callInProgress", "h501.callInProgress",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_callEnded,
{ "callEnded", "h501.callEnded",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_registrationLost,
{ "registrationLost", "h501.registrationLost",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_userIdentifier,
{ "userIdentifier", "h501.userIdentifier",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_userAuthenticator,
{ "userAuthenticator", "h501.userAuthenticator",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_CryptoH323Token", HFILL }},
{ &hf_h501_userAuthenticator_item,
{ "CryptoH323Token", "h501.CryptoH323Token",
FT_UINT32, BASE_DEC, VALS(h225_CryptoH323Token_vals), 0,
NULL, HFILL }},
{ &hf_h501_sendTo,
{ "sendTo", "h501.sendTo",
FT_STRING, BASE_NONE, NULL, 0,
"ElementIdentifier", HFILL }},
{ &hf_h501_when,
{ "when", "h501.when",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_never,
{ "never", "h501.never",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_start,
{ "start", "h501.start",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_end,
{ "end", "h501.end",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_period,
{ "period", "h501.period",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
{ &hf_h501_failures,
{ "failures", "h501.failures",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_required,
{ "required", "h501.required",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h501_required_item,
{ "required item", "h501.required_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h501_preferred,
{ "preferred", "h501.preferred",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h501_preferred_item,
{ "preferred item", "h501.preferred_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h501_sendToPEAddress,
{ "sendToPEAddress", "h501.sendToPEAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
"AliasAddress", HFILL }},
{ &hf_h501_logicalAddresses,
{ "logicalAddresses", "h501.logicalAddresses",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AliasAddress", HFILL }},
{ &hf_h501_logicalAddresses_item,
{ "AliasAddress", "h501.AliasAddress",
FT_UINT32, BASE_DEC, VALS(AliasAddress_vals), 0,
NULL, HFILL }},
{ &hf_h501_endpointType,
{ "endpointType", "h501.endpointType",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_userInfo,
{ "userInfo", "h501.userInfo",
FT_NONE, BASE_NONE, NULL, 0,
"UserInformation", HFILL }},
{ &hf_h501_timeZone,
{ "timeZone", "h501.timeZone",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h501_originator,
{ "originator", "h501.originator",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_destination,
{ "destination", "h501.destination",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h501_nonStandardData,
{ "nonStandardData", "h501.nonStandardData",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h501_releaseCompleteReason,
{ "releaseCompleteReason", "h501.releaseCompleteReason",
FT_UINT32, BASE_DEC, VALS(h225_ReleaseCompleteReason_vals), 0,
NULL, HFILL }},
{ &hf_h501_causeIE,
{ "causeIE", "h501.causeIE",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_65535", HFILL }},
#line 100 "../../asn1/h501/packet-h501-template.c"
};
static gint *ett[] = {
&ett_h501,
#line 1 "../../asn1/h501/packet-h501-ettarr.c"
&ett_h501_Message,
&ett_h501_MessageBody,
&ett_h501_MessageCommonInfo,
&ett_h501_SEQUENCE_OF_TransportAddress,
&ett_h501_SEQUENCE_OF_ClearToken,
&ett_h501_SEQUENCE_OF_CryptoH323Token,
&ett_h501_SEQUENCE_OF_NonStandardParameter,
&ett_h501_SEQUENCE_OF_GenericData,
&ett_h501_ServiceRequest,
&ett_h501_SEQUENCE_OF_SecurityMode,
&ett_h501_SecurityMode,
&ett_h501_T_algorithmOIDs,
&ett_h501_ServiceConfirmation,
&ett_h501_ServiceRejection,
&ett_h501_ServiceRejectionReason,
&ett_h501_ServiceRelease,
&ett_h501_ServiceReleaseReason,
&ett_h501_DescriptorRequest,
&ett_h501_SEQUENCE_OF_DescriptorID,
&ett_h501_DescriptorConfirmation,
&ett_h501_SEQUENCE_OF_Descriptor,
&ett_h501_DescriptorRejection,
&ett_h501_DescriptorRejectionReason,
&ett_h501_DescriptorIDRequest,
&ett_h501_DescriptorIDConfirmation,
&ett_h501_SEQUENCE_OF_DescriptorInfo,
&ett_h501_DescriptorIDRejection,
&ett_h501_DescriptorIDRejectionReason,
&ett_h501_DescriptorUpdate,
&ett_h501_SEQUENCE_OF_UpdateInformation,
&ett_h501_UpdateInformation,
&ett_h501_T_descriptorInfo,
&ett_h501_T_updateType,
&ett_h501_DescriptorUpdateAck,
&ett_h501_AccessRequest,
&ett_h501_SEQUENCE_OF_SupportedProtocols,
&ett_h501_AccessConfirmation,
&ett_h501_SEQUENCE_OF_AddressTemplate,
&ett_h501_SEQUENCE_OF_ServiceControlSession,
&ett_h501_AccessRejection,
&ett_h501_AccessRejectionReason,
&ett_h501_UsageRequest,
&ett_h501_UsageConfirmation,
&ett_h501_UsageRejection,
&ett_h501_UsageIndication,
&ett_h501_SEQUENCE_OF_AccessToken,
&ett_h501_SEQUENCE_OF_UsageField,
&ett_h501_UsageField,
&ett_h501_UsageRejectReason,
&ett_h501_UsageIndicationConfirmation,
&ett_h501_UsageIndicationRejection,
&ett_h501_UsageIndicationRejectionReason,
&ett_h501_ValidationRequest,
&ett_h501_ValidationConfirmation,
&ett_h501_ValidationRejection,
&ett_h501_ValidationRejectionReason,
&ett_h501_RequestInProgress,
&ett_h501_NonStandardRequest,
&ett_h501_NonStandardConfirmation,
&ett_h501_NonStandardRejection,
&ett_h501_NonStandardRejectionReason,
&ett_h501_UnknownMessageResponse,
&ett_h501_UnknownMessageReason,
&ett_h501_AuthenticationRequest,
&ett_h501_AuthenticationConfirmation,
&ett_h501_AuthenticationRejection,
&ett_h501_AuthenticationRejectionReason,
&ett_h501_AddressTemplate,
&ett_h501_SEQUENCE_OF_Pattern,
&ett_h501_SEQUENCE_OF_RouteInformation,
&ett_h501_Pattern,
&ett_h501_T_range,
&ett_h501_RouteInformation,
&ett_h501_T_messageType,
&ett_h501_SEQUENCE_OF_PriceInfoSpec,
&ett_h501_SEQUENCE_OF_ContactInformation,
&ett_h501_SEQUENCE_OF_CircuitIdentifier,
&ett_h501_ContactInformation,
&ett_h501_PriceInfoSpec,
&ett_h501_SEQUENCE_OF_PriceElement,
&ett_h501_PriceElement,
&ett_h501_T_units,
&ett_h501_Descriptor,
&ett_h501_DescriptorInfo,
&ett_h501_AlternatePEInfo,
&ett_h501_SEQUENCE_OF_AlternatePE,
&ett_h501_AlternatePE,
&ett_h501_AccessToken,
&ett_h501_CallInformation,
&ett_h501_UsageCallStatus,
&ett_h501_UserInformation,
&ett_h501_UsageSpecification,
&ett_h501_T_when,
&ett_h501_T_required,
&ett_h501_T_preferred,
&ett_h501_PartyInformation,
&ett_h501_SEQUENCE_OF_AliasAddress,
&ett_h501_Role,
&ett_h501_TerminationCause,
#line 106 "../../asn1/h501/packet-h501-template.c"
};
proto_h501 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h501, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_h501_pdu, proto_h501);
h501_module = prefs_register_protocol(proto_h501, proto_reg_handoff_h501);
prefs_register_uint_preference(h501_module, "udp.port",
"UDP port",
"Port to be decoded as h501",
10, &h501_udp_port);
prefs_register_uint_preference(h501_module, "tcp.port",
"TCP port",
"Port to be decoded as h501",
10, &h501_tcp_port);
prefs_register_bool_preference(h501_module, "desegment",
"Desegment H.501 over TCP",
"Desegment H.501 messages that span more TCP segments",
&h501_desegment_tcp);
}
void proto_reg_handoff_h501(void)
{
static gboolean h501_prefs_initialized = FALSE;
static dissector_handle_t h501_udp_handle;
static dissector_handle_t h501_tcp_handle;
static guint saved_h501_udp_port;
static guint saved_h501_tcp_port;
if (!h501_prefs_initialized) {
h501_pdu_handle = find_dissector(PFNAME);
h501_udp_handle = new_create_dissector_handle(dissect_h501_udp, proto_h501);
h501_tcp_handle = new_create_dissector_handle(dissect_h501_tcp, proto_h501);
h501_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", saved_h501_udp_port, h501_udp_handle);
dissector_delete_uint("tcp.port", saved_h501_tcp_port, h501_tcp_handle);
}
saved_h501_udp_port = h501_udp_port;
dissector_add_uint("udp.port", saved_h501_udp_port, h501_udp_handle);
saved_h501_tcp_port = h501_tcp_port;
dissector_add_uint("tcp.port", saved_h501_tcp_port, h501_tcp_handle);
}
