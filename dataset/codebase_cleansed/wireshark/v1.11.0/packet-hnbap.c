static int
dissect_hnbap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_hnbap_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_hnbap_PrivateIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_PrivateIE_ID, PrivateIE_ID_choice,
NULL);
return offset;
}
static int
dissect_hnbap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 62 "../../asn1/hnbap/hnbap.cnf"
if (strcmp(val_to_str(ProcedureCode, hnbap_ProcedureCode_vals, "Unknown"), "Unknown") == 0) {
col_set_str(actx->pinfo->cinfo, COL_INFO,
"Unknown Message");
}
return offset;
}
static int
dissect_hnbap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxProtocolIEs, &ProtocolIE_ID, FALSE);
#line 51 "../../asn1/hnbap/hnbap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(hnbap_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_hnbap_TriggeringMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_hnbap_ProtocolIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_hnbap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_hnbap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_hnbap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_hnbap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_hnbap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_hnbap_PrivateIE_Field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_hnbap_PrivateIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_PrivateIE_Field, PrivateIE_Field_sequence);
return offset;
}
static int
dissect_hnbap_PrivateIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_PrivateIE_Container, PrivateIE_Container_sequence_of,
1, maxPrivateIEs, FALSE);
return offset;
}
static int
dissect_hnbap_Access_stratum_release_indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_T_directionOfAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_hnbap_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_AltitudeAndDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_AltitudeAndDirection, AltitudeAndDirection_sequence);
return offset;
}
static int
dissect_hnbap_BackoffTimer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3600U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_BindingID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 4, TRUE, NULL);
return offset;
}
static int
dissect_hnbap_CauseRadioNetwork(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
14, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_CauseTransport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_CauseProtocol(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_CauseMisc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_Cause, Cause_choice,
NULL);
return offset;
}
static int
dissect_hnbap_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_Context_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_TypeOfError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_CriticalityDiagnostics_IE_List_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_CriticalityDiagnostics_IE_List_item, CriticalityDiagnostics_IE_List_item_sequence);
return offset;
}
static int
dissect_hnbap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
1, maxNrOfErrors, FALSE);
return offset;
}
static int
dissect_hnbap_CriticalityDiagnostics(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);
return offset;
}
static int
dissect_hnbap_CSG_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
27, 27, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_CSG_Capability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_CSGMembershipStatus(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_PLMNidentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_LAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_CI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_CGI, CGI_sequence);
return offset;
}
static int
dissect_hnbap_CN_DomainIndicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_hnbap_ESN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_T_latitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_hnbap_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_GeographicalCoordinates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_GeographicalCoordinates, GeographicalCoordinates_sequence);
return offset;
}
static int
dissect_hnbap_GeographicalLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_GeographicalLocation, GeographicalLocation_sequence);
return offset;
}
static int
dissect_hnbap_GTP_TEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_HNB_Cell_Access_Mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_HNB_Cell_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNB_Cell_Identifier, HNB_Cell_Identifier_sequence);
return offset;
}
static int
dissect_hnbap_HNB_RNL_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNB_RNL_Identity, HNB_RNL_Identity_choice,
NULL);
return offset;
}
static int
dissect_hnbap_PSC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
9, 9, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_Ipv4Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_Ipv6Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_T_ipaddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_T_ipaddress, T_ipaddress_choice,
NULL);
return offset;
}
static int
dissect_hnbap_IP_Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_IP_Address, IP_Address_sequence);
return offset;
}
static int
dissect_hnbap_Iurh_Signalling_TNL_AddressList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_Iurh_Signalling_TNL_AddressList, Iurh_Signalling_TNL_AddressList_sequence_of,
1, maxnoofIurhAddresses, FALSE);
return offset;
}
static int
dissect_hnbap_HNBConfigurationInformationProvided(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBConfigurationInformationProvided, HNBConfigurationInformationProvided_sequence);
return offset;
}
static int
dissect_hnbap_HNBConfigurationInformationMissing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBConfigurationInformationMissing, HNBConfigurationInformationMissing_sequence);
return offset;
}
static int
dissect_hnbap_ConfigurationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_ConfigurationInformation, ConfigurationInformation_choice,
NULL);
return offset;
}
static int
dissect_hnbap_HNBConfigInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBConfigInfo, HNBConfigInfo_sequence);
return offset;
}
static int
dissect_hnbap_RAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_UTRANCellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UTRANCellID, UTRANCellID_sequence);
return offset;
}
static int
dissect_hnbap_MacroCellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_MacroCellID, MacroCellID_choice,
NULL);
return offset;
}
static int
dissect_hnbap_MacroCoverageInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_MacroCoverageInformation, MacroCoverageInformation_sequence);
return offset;
}
static int
dissect_hnbap_HNB_Location_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNB_Location_Information, HNB_Location_Information_sequence);
return offset;
}
static int
dissect_hnbap_HNB_Identity_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 255, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_HNB_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNB_Identity, HNB_Identity_sequence);
return offset;
}
static int
dissect_hnbap_IMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
60, 60, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_IMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 8, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_IMSIDS41(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
5, 7, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_IMSIESN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_IMSIESN, IMSIESN_sequence);
return offset;
}
static int
dissect_hnbap_LAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_LAI, LAI_sequence);
return offset;
}
static int
dissect_hnbap_MuxPortNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1024U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_NeighbourInfoList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_NeighbourInfoList, NeighbourInfoList_sequence_of,
1, maxnoofNeighbours, FALSE);
return offset;
}
static int
dissect_hnbap_NeighbourInfoRequestItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_NeighbourInfoRequestItem, NeighbourInfoRequestItem_sequence);
return offset;
}
static int
dissect_hnbap_NeighbourInfoRequestList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_NeighbourInfoRequestList, NeighbourInfoRequestList_sequence_of,
1, maxnoofNeighbours, FALSE);
return offset;
}
static int
dissect_hnbap_PTMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_RAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_RAI, RAI_sequence);
return offset;
}
static int
dissect_hnbap_PTMSIRAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_PTMSIRAI, PTMSIRAI_sequence);
return offset;
}
static int
dissect_hnbap_RAB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_TransportLayerAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 160, TRUE, NULL);
return offset;
}
static int
dissect_hnbap_T_transportAssociation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_T_transportAssociation, T_transportAssociation_choice,
NULL);
return offset;
}
static int
dissect_hnbap_TransportInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_TransportInfo, TransportInfo_sequence);
return offset;
}
static int
dissect_hnbap_RABListItem(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_RABListItem, RABListItem_sequence);
return offset;
}
static int
dissect_hnbap_RABList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_hnbap_RABList, RABList_sequence_of,
1, maxnoofRABs, FALSE);
return offset;
}
static int
dissect_hnbap_Registration_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 1, NULL);
return offset;
}
static int
dissect_hnbap_RNC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_hnbap_SAC(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_TMSILAI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_TMSILAI, TMSILAI_sequence);
return offset;
}
static int
dissect_hnbap_TMSIDS41(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
2, 17, FALSE, NULL);
return offset;
}
static int
dissect_hnbap_UE_Capabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UE_Capabilities, UE_Capabilities_sequence);
return offset;
}
static int
dissect_hnbap_UE_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_UE_Identity, UE_Identity_choice,
NULL);
return offset;
}
static int
dissect_hnbap_Update_cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_hnbap_HNBRegisterRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 75 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_REGISTER_REQUEST ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBRegisterRequest, HNBRegisterRequest_sequence);
return offset;
}
static int
dissect_hnbap_HNBRegisterAccept(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 80 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_REGISTER_ACCEPT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBRegisterAccept, HNBRegisterAccept_sequence);
return offset;
}
static int
dissect_hnbap_HNBRegisterReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 85 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_REGISTER_REJECT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBRegisterReject, HNBRegisterReject_sequence);
return offset;
}
static int
dissect_hnbap_HNBDe_Register(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 110 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_DE-REGISTER ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBDe_Register, HNBDe_Register_sequence);
return offset;
}
static int
dissect_hnbap_UERegisterRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 90 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"UE_REGISTER_REQUEST ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UERegisterRequest, UERegisterRequest_sequence);
return offset;
}
static int
dissect_hnbap_UERegisterAccept(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 95 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"UE_REGISTER_ACCEPT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UERegisterAccept, UERegisterAccept_sequence);
return offset;
}
static int
dissect_hnbap_UERegisterReject(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 100 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"UE_REGISTER_REJECT ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UERegisterReject, UERegisterReject_sequence);
return offset;
}
static int
dissect_hnbap_UEDe_Register(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 105 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"UE_DE-REGISTER ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UEDe_Register, UEDe_Register_sequence);
return offset;
}
static int
dissect_hnbap_CSGMembershipUpdate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 121 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"CSG_MEMBERSHIP_UPDATE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_CSGMembershipUpdate, CSGMembershipUpdate_sequence);
return offset;
}
static int
dissect_hnbap_TNLUpdateRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 131 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"TNL_UPDATE_REQUEST_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_TNLUpdateRequest, TNLUpdateRequest_sequence);
return offset;
}
static int
dissect_hnbap_TNLUpdateResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 135 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"TNL_UPDATE_RESPONSE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_TNLUpdateResponse, TNLUpdateResponse_sequence);
return offset;
}
static int
dissect_hnbap_TNLUpdateFailure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 139 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"TNL_UPDATE_FAILURE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_TNLUpdateFailure, TNLUpdateFailure_sequence);
return offset;
}
static int
dissect_hnbap_HNBConfigTransferRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 143 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_CONFIG_TRANSFER_REQUEST_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBConfigTransferRequest, HNBConfigTransferRequest_sequence);
return offset;
}
static int
dissect_hnbap_HNBConfigTransferResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 147 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"HNB_CONFIG_TRANSFER_RESPONSE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBConfigTransferResponse, HNBConfigTransferResponse_sequence);
return offset;
}
static int
dissect_hnbap_RelocationComplete(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 151 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"RELOCATION_COMPLETE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_RelocationComplete, RelocationComplete_sequence);
return offset;
}
static int
dissect_hnbap_ErrorIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 115 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"ERROR_INDICATION ");
col_set_fence(actx->pinfo->cinfo, COL_INFO);
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_ErrorIndication, ErrorIndication_sequence);
return offset;
}
static int
dissect_hnbap_PrivateMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 126 "../../asn1/hnbap/hnbap.cnf"
col_set_str(actx->pinfo->cinfo, COL_INFO,
"PRIVATE_MESSAGE ");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_PrivateMessage, PrivateMessage_sequence);
return offset;
}
static int
dissect_hnbap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_hnbap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_hnbap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_hnbap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_hnbap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_hnbap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_hnbap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_hnbap_HNBAP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_hnbap_HNBAP_PDU, HNBAP_PDU_choice,
NULL);
return offset;
}
static int dissect_BackoffTimer_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_BackoffTimer(tvb, offset, &asn1_ctx, tree, hf_hnbap_BackoffTimer_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_Cause(tvb, offset, &asn1_ctx, tree, hf_hnbap_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CellIdentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_CellIdentity(tvb, offset, &asn1_ctx, tree, hf_hnbap_CellIdentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Context_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_Context_ID(tvb, offset, &asn1_ctx, tree, hf_hnbap_Context_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_hnbap_CriticalityDiagnostics_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSG_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_CSG_ID(tvb, offset, &asn1_ctx, tree, hf_hnbap_CSG_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_hnbap_CSGMembershipStatus_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNB_Cell_Access_Mode_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNB_Cell_Access_Mode(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNB_Cell_Access_Mode_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNB_Location_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNB_Location_Information(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNB_Location_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNB_Identity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNB_Identity(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNB_Identity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IP_Address_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_IP_Address(tvb, offset, &asn1_ctx, tree, hf_hnbap_IP_Address_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LAC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_LAC(tvb, offset, &asn1_ctx, tree, hf_hnbap_LAC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MuxPortNumber_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_MuxPortNumber(tvb, offset, &asn1_ctx, tree, hf_hnbap_MuxPortNumber_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NeighbourInfoList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_NeighbourInfoList(tvb, offset, &asn1_ctx, tree, hf_hnbap_NeighbourInfoList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_NeighbourInfoRequestList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_NeighbourInfoRequestList(tvb, offset, &asn1_ctx, tree, hf_hnbap_NeighbourInfoRequestList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PLMNidentity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_PLMNidentity(tvb, offset, &asn1_ctx, tree, hf_hnbap_PLMNidentity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PSC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_PSC(tvb, offset, &asn1_ctx, tree, hf_hnbap_PSC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RABList_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_RABList(tvb, offset, &asn1_ctx, tree, hf_hnbap_RABList_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RAC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_RAC(tvb, offset, &asn1_ctx, tree, hf_hnbap_RAC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Registration_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_Registration_Cause(tvb, offset, &asn1_ctx, tree, hf_hnbap_Registration_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RNC_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_RNC_ID(tvb, offset, &asn1_ctx, tree, hf_hnbap_RNC_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_SAC_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_SAC(tvb, offset, &asn1_ctx, tree, hf_hnbap_SAC_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Capabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UE_Capabilities(tvb, offset, &asn1_ctx, tree, hf_hnbap_UE_Capabilities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Identity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UE_Identity(tvb, offset, &asn1_ctx, tree, hf_hnbap_UE_Identity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Update_cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_Update_cause(tvb, offset, &asn1_ctx, tree, hf_hnbap_Update_cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBRegisterRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBRegisterRequest(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBRegisterRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBRegisterAccept_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBRegisterAccept(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBRegisterAccept_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBRegisterReject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBRegisterReject(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBRegisterReject_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBDe_Register_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBDe_Register(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBDe_Register_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERegisterRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UERegisterRequest(tvb, offset, &asn1_ctx, tree, hf_hnbap_UERegisterRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERegisterAccept_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UERegisterAccept(tvb, offset, &asn1_ctx, tree, hf_hnbap_UERegisterAccept_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UERegisterReject_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UERegisterReject(tvb, offset, &asn1_ctx, tree, hf_hnbap_UERegisterReject_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UEDe_Register_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_UEDe_Register(tvb, offset, &asn1_ctx, tree, hf_hnbap_UEDe_Register_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_CSGMembershipUpdate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_CSGMembershipUpdate(tvb, offset, &asn1_ctx, tree, hf_hnbap_CSGMembershipUpdate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TNLUpdateRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_TNLUpdateRequest(tvb, offset, &asn1_ctx, tree, hf_hnbap_TNLUpdateRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TNLUpdateResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_TNLUpdateResponse(tvb, offset, &asn1_ctx, tree, hf_hnbap_TNLUpdateResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_TNLUpdateFailure_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_TNLUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_hnbap_TNLUpdateFailure_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBConfigTransferRequest_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBConfigTransferRequest(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBConfigTransferRequest_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_HNBConfigTransferResponse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_HNBConfigTransferResponse(tvb, offset, &asn1_ctx, tree, hf_hnbap_HNBConfigTransferResponse_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RelocationComplete_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_RelocationComplete(tvb, offset, &asn1_ctx, tree, hf_hnbap_RelocationComplete_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_hnbap_ErrorIndication_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_hnbap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_hnbap_PrivateMessage_PDU);
offset += 7; offset >>= 3;
return offset;
}
static void dissect_HNBAP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_hnbap_HNBAP_PDU(tvb, 0, &asn1_ctx, tree, hf_hnbap_HNBAP_PDU_PDU);
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_extension_dissector_table, ProtocolIE_ID, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint_new(hnbap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree, FALSE, NULL)) ? tvb_length(tvb) : 0;
}
static void
dissect_hnbap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *hnbap_item = NULL;
proto_tree *hnbap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HNBAP");
hnbap_item = proto_tree_add_item(tree, proto_hnbap, tvb, 0, -1, ENC_NA);
hnbap_tree = proto_item_add_subtree(hnbap_item, ett_hnbap);
dissect_HNBAP_PDU_PDU(tvb, pinfo, hnbap_tree);
}
void proto_register_hnbap(void) {
module_t *hnbap_module;
static hf_register_info hf[] = {
#line 1 "../../asn1/hnbap/packet-hnbap-hfarr.c"
{ &hf_hnbap_BackoffTimer_PDU,
{ "BackoffTimer", "hnbap.BackoffTimer",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_Cause_PDU,
{ "Cause", "hnbap.Cause",
FT_UINT32, BASE_DEC, VALS(hnbap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_CellIdentity_PDU,
{ "CellIdentity", "hnbap.CellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_Context_ID_PDU,
{ "Context-ID", "hnbap.Context_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_CriticalityDiagnostics_PDU,
{ "CriticalityDiagnostics", "hnbap.CriticalityDiagnostics_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_CSG_ID_PDU,
{ "CSG-ID", "hnbap.CSG_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_CSGMembershipStatus_PDU,
{ "CSGMembershipStatus", "hnbap.CSGMembershipStatus",
FT_UINT32, BASE_DEC, VALS(hnbap_CSGMembershipStatus_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_HNB_Cell_Access_Mode_PDU,
{ "HNB-Cell-Access-Mode", "hnbap.HNB_Cell_Access_Mode",
FT_UINT32, BASE_DEC, VALS(hnbap_HNB_Cell_Access_Mode_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_HNB_Location_Information_PDU,
{ "HNB-Location-Information", "hnbap.HNB_Location_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNB_Identity_PDU,
{ "HNB-Identity", "hnbap.HNB_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_IP_Address_PDU,
{ "IP-Address", "hnbap.IP_Address_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_LAC_PDU,
{ "LAC", "hnbap.LAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_MuxPortNumber_PDU,
{ "MuxPortNumber", "hnbap.MuxPortNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_NeighbourInfoList_PDU,
{ "NeighbourInfoList", "hnbap.NeighbourInfoList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_NeighbourInfoRequestList_PDU,
{ "NeighbourInfoRequestList", "hnbap.NeighbourInfoRequestList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_PLMNidentity_PDU,
{ "PLMNidentity", "hnbap.PLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_PSC_PDU,
{ "PSC", "hnbap.PSC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_RABList_PDU,
{ "RABList", "hnbap.RABList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_RAC_PDU,
{ "RAC", "hnbap.RAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_Registration_Cause_PDU,
{ "Registration-Cause", "hnbap.Registration_Cause",
FT_UINT32, BASE_DEC, VALS(hnbap_Registration_Cause_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_RNC_ID_PDU,
{ "RNC-ID", "hnbap.RNC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_SAC_PDU,
{ "SAC", "hnbap.SAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UE_Capabilities_PDU,
{ "UE-Capabilities", "hnbap.UE_Capabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UE_Identity_PDU,
{ "UE-Identity", "hnbap.UE_Identity",
FT_UINT32, BASE_DEC, VALS(hnbap_UE_Identity_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_Update_cause_PDU,
{ "Update-cause", "hnbap.Update_cause",
FT_UINT32, BASE_DEC, VALS(hnbap_Update_cause_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_HNBRegisterRequest_PDU,
{ "HNBRegisterRequest", "hnbap.HNBRegisterRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBRegisterAccept_PDU,
{ "HNBRegisterAccept", "hnbap.HNBRegisterAccept_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBRegisterReject_PDU,
{ "HNBRegisterReject", "hnbap.HNBRegisterReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBDe_Register_PDU,
{ "HNBDe-Register", "hnbap.HNBDe_Register_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UERegisterRequest_PDU,
{ "UERegisterRequest", "hnbap.UERegisterRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UERegisterAccept_PDU,
{ "UERegisterAccept", "hnbap.UERegisterAccept_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UERegisterReject_PDU,
{ "UERegisterReject", "hnbap.UERegisterReject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_UEDe_Register_PDU,
{ "UEDe-Register", "hnbap.UEDe_Register_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_CSGMembershipUpdate_PDU,
{ "CSGMembershipUpdate", "hnbap.CSGMembershipUpdate_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_TNLUpdateRequest_PDU,
{ "TNLUpdateRequest", "hnbap.TNLUpdateRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_TNLUpdateResponse_PDU,
{ "TNLUpdateResponse", "hnbap.TNLUpdateResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_TNLUpdateFailure_PDU,
{ "TNLUpdateFailure", "hnbap.TNLUpdateFailure_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBConfigTransferRequest_PDU,
{ "HNBConfigTransferRequest", "hnbap.HNBConfigTransferRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBConfigTransferResponse_PDU,
{ "HNBConfigTransferResponse", "hnbap.HNBConfigTransferResponse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_RelocationComplete_PDU,
{ "RelocationComplete", "hnbap.RelocationComplete_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_ErrorIndication_PDU,
{ "ErrorIndication", "hnbap.ErrorIndication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_PrivateMessage_PDU,
{ "PrivateMessage", "hnbap.PrivateMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_HNBAP_PDU_PDU,
{ "HNBAP-PDU", "hnbap.HNBAP_PDU",
FT_UINT32, BASE_DEC, VALS(hnbap_HNBAP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_local,
{ "local", "hnbap.local",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_hnbap_global,
{ "global", "hnbap.global",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_hnbap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "hnbap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_protocol_ie_field_id,
{ "id", "hnbap.id",
FT_UINT32, BASE_DEC, VALS(hnbap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_hnbap_criticality,
{ "criticality", "hnbap.criticality",
FT_UINT32, BASE_DEC, VALS(hnbap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_ie_field_value,
{ "value", "hnbap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtocolIE_Field_value", HFILL }},
{ &hf_hnbap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "hnbap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_id,
{ "id", "hnbap.id",
FT_UINT32, BASE_DEC, VALS(hnbap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_hnbap_extensionValue,
{ "extensionValue", "hnbap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_PrivateIE_Container_item,
{ "PrivateIE-Field", "hnbap.PrivateIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_private_ie_field_id,
{ "id", "hnbap.id",
FT_UINT32, BASE_DEC, VALS(hnbap_PrivateIE_ID_vals), 0,
"PrivateIE_ID", HFILL }},
{ &hf_hnbap_private_value,
{ "value", "hnbap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrivateIE_Field_value", HFILL }},
{ &hf_hnbap_directionOfAltitude,
{ "directionOfAltitude", "hnbap.directionOfAltitude",
FT_UINT32, BASE_DEC, VALS(hnbap_T_directionOfAltitude_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_altitude,
{ "altitude", "hnbap.altitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_hnbap_radioNetwork,
{ "radioNetwork", "hnbap.radioNetwork",
FT_UINT32, BASE_DEC, VALS(hnbap_CauseRadioNetwork_vals), 0,
"CauseRadioNetwork", HFILL }},
{ &hf_hnbap_transport,
{ "transport", "hnbap.transport",
FT_UINT32, BASE_DEC, VALS(hnbap_CauseTransport_vals), 0,
"CauseTransport", HFILL }},
{ &hf_hnbap_protocol,
{ "protocol", "hnbap.protocol",
FT_UINT32, BASE_DEC, VALS(hnbap_CauseProtocol_vals), 0,
"CauseProtocol", HFILL }},
{ &hf_hnbap_misc,
{ "misc", "hnbap.misc",
FT_UINT32, BASE_DEC, VALS(hnbap_CauseMisc_vals), 0,
"CauseMisc", HFILL }},
{ &hf_hnbap_procedureCode,
{ "procedureCode", "hnbap.procedureCode",
FT_UINT32, BASE_DEC, VALS(hnbap_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_triggeringMessage,
{ "triggeringMessage", "hnbap.triggeringMessage",
FT_UINT32, BASE_DEC, VALS(hnbap_TriggeringMessage_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_procedureCriticality,
{ "procedureCriticality", "hnbap.procedureCriticality",
FT_UINT32, BASE_DEC, VALS(hnbap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_hnbap_iEsCriticalityDiagnostics,
{ "iEsCriticalityDiagnostics", "hnbap.iEsCriticalityDiagnostics",
FT_UINT32, BASE_DEC, NULL, 0,
"CriticalityDiagnostics_IE_List", HFILL }},
{ &hf_hnbap_iE_Extensions,
{ "iE-Extensions", "hnbap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_hnbap_CriticalityDiagnostics_IE_List_item,
{ "CriticalityDiagnostics-IE-List item", "hnbap.CriticalityDiagnostics_IE_List_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_iECriticality,
{ "iECriticality", "hnbap.iECriticality",
FT_UINT32, BASE_DEC, VALS(hnbap_Criticality_vals), 0,
"Criticality", HFILL }},
{ &hf_hnbap_iE_ID,
{ "iE-ID", "hnbap.iE_ID",
FT_UINT32, BASE_DEC, VALS(hnbap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_hnbap_typeOfError,
{ "typeOfError", "hnbap.typeOfError",
FT_UINT32, BASE_DEC, VALS(hnbap_TypeOfError_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_pLMNidentity,
{ "pLMNidentity", "hnbap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_lAC,
{ "lAC", "hnbap.lAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_cI,
{ "cI", "hnbap.cI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_geographical_location_geographical_coordinates,
{ "geographicalCoordinates", "hnbap.geographicalCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_altitudeAndDirection,
{ "altitudeAndDirection", "hnbap.altitudeAndDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_latitudeSign,
{ "latitudeSign", "hnbap.latitudeSign",
FT_UINT32, BASE_DEC, VALS(hnbap_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_latitude,
{ "latitude", "hnbap.latitude",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_hnbap_longitude,
{ "longitude", "hnbap.longitude",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_hnbap_cellIdentity,
{ "cellIdentity", "hnbap.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_hNB_Identity_as_Cell_Identifier,
{ "hNB-Identity-as-Cell-Identifier", "hnbap.hNB_Identity_as_Cell_Identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
"HNB_Cell_Identifier", HFILL }},
{ &hf_hnbap_hnb_RNL_Identity,
{ "hnb-RNL-Identity", "hnbap.hnb_RNL_Identity",
FT_UINT32, BASE_DEC, VALS(hnbap_HNB_RNL_Identity_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_configurationInformation,
{ "configurationInformation", "hnbap.configurationInformation",
FT_UINT32, BASE_DEC, VALS(hnbap_ConfigurationInformation_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_provided,
{ "provided", "hnbap.provided_element",
FT_NONE, BASE_NONE, NULL, 0,
"HNBConfigurationInformationProvided", HFILL }},
{ &hf_hnbap_missing,
{ "missing", "hnbap.missing_element",
FT_NONE, BASE_NONE, NULL, 0,
"HNBConfigurationInformationMissing", HFILL }},
{ &hf_hnbap_psc,
{ "psc", "hnbap.psc",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_cSG_ID,
{ "cSG-ID", "hnbap.cSG_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_hNB_Cell_Access_Mode,
{ "hNB-Cell-Access-Mode", "hnbap.hNB_Cell_Access_Mode",
FT_UINT32, BASE_DEC, VALS(hnbap_HNB_Cell_Access_Mode_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_iurh_Signalling_TNL_AddressList,
{ "iurh-Signalling-TNL-AddressList", "hnbap.iurh_Signalling_TNL_AddressList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_cause,
{ "cause", "hnbap.cause",
FT_UINT32, BASE_DEC, VALS(hnbap_Cause_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_macroCoverageInfo,
{ "macroCoverageInfo", "hnbap.macroCoverageInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"MacroCoverageInformation", HFILL }},
{ &hf_hnbap_hnb_location_information_geographical_coordinates,
{ "geographicalCoordinates", "hnbap.geographicalCoordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
"GeographicalLocation", HFILL }},
{ &hf_hnbap_hNB_Identity_Info,
{ "hNB-Identity-Info", "hnbap.hNB_Identity_Info",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_iMSIDS41,
{ "iMSIDS41", "hnbap.iMSIDS41",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_eSN,
{ "eSN", "hnbap.eSN",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_ipaddress,
{ "ipaddress", "hnbap.ipaddress",
FT_UINT32, BASE_DEC, VALS(hnbap_T_ipaddress_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_ipv4info,
{ "ipv4info", "hnbap.ipv4info",
FT_BYTES, BASE_NONE, NULL, 0,
"Ipv4Address", HFILL }},
{ &hf_hnbap_ipv6info,
{ "ipv6info", "hnbap.ipv6info",
FT_BYTES, BASE_NONE, NULL, 0,
"Ipv6Address", HFILL }},
{ &hf_hnbap_Iurh_Signalling_TNL_AddressList_item,
{ "IP-Address", "hnbap.IP_Address_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_pLMNID,
{ "pLMNID", "hnbap.pLMNID",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMNidentity", HFILL }},
{ &hf_hnbap_cellIdentity_01,
{ "cellIdentity", "hnbap.cellIdentity",
FT_UINT32, BASE_DEC, VALS(hnbap_MacroCellID_vals), 0,
"MacroCellID", HFILL }},
{ &hf_hnbap_uTRANCellID,
{ "uTRANCellID", "hnbap.uTRANCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_gERANCellID,
{ "gERANCellID", "hnbap.gERANCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
"CGI", HFILL }},
{ &hf_hnbap_NeighbourInfoList_item,
{ "HNBConfigInfo", "hnbap.HNBConfigInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_NeighbourInfoRequestList_item,
{ "NeighbourInfoRequestItem", "hnbap.NeighbourInfoRequestItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_pTMSI,
{ "pTMSI", "hnbap.pTMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_rAI,
{ "rAI", "hnbap.rAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_RABList_item,
{ "RABListItem", "hnbap.RABListItem_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_rAB_ID,
{ "rAB-ID", "hnbap.rAB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_old_transport_Info,
{ "old-transport-Info", "hnbap.old_transport_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportInfo", HFILL }},
{ &hf_hnbap_new_transport_Info,
{ "new-transport-Info", "hnbap.new_transport_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransportInfo", HFILL }},
{ &hf_hnbap_cn_domain_indicator,
{ "cn-domain-indicator", "hnbap.cn_domain_indicator",
FT_UINT32, BASE_DEC, VALS(hnbap_CN_DomainIndicator_vals), 0,
"CN_DomainIndicator", HFILL }},
{ &hf_hnbap_lAI,
{ "lAI", "hnbap.lAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_rAC,
{ "rAC", "hnbap.rAC",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_tMSI,
{ "tMSI", "hnbap.tMSI",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_hnbap_transportLayerAddress,
{ "transportLayerAddress", "hnbap.transportLayerAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_transportAssociation,
{ "transportAssociation", "hnbap.transportAssociation",
FT_UINT32, BASE_DEC, VALS(hnbap_T_transportAssociation_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_gtp_TEI,
{ "gtp-TEI", "hnbap.gtp_TEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_bindingID,
{ "bindingID", "hnbap.bindingID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_access_stratum_release_indicator,
{ "access-stratum-release-indicator", "hnbap.access_stratum_release_indicator",
FT_UINT32, BASE_DEC, VALS(hnbap_Access_stratum_release_indicator_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_csg_capability,
{ "csg-capability", "hnbap.csg_capability",
FT_UINT32, BASE_DEC, VALS(hnbap_CSG_Capability_vals), 0,
NULL, HFILL }},
{ &hf_hnbap_uTRANcellID,
{ "uTRANcellID", "hnbap.uTRANcellID",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdentity", HFILL }},
{ &hf_hnbap_iMSI,
{ "iMSI", "hnbap.iMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_tMSILAI,
{ "tMSILAI", "hnbap.tMSILAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_pTMSIRAI,
{ "pTMSIRAI", "hnbap.pTMSIRAI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_iMEI,
{ "iMEI", "hnbap.iMEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_iMSIESN,
{ "iMSIESN", "hnbap.iMSIESN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_tMSIDS41,
{ "tMSIDS41", "hnbap.tMSIDS41",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_protocolIEs,
{ "protocolIEs", "hnbap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_hnbap_protocolExtensions,
{ "protocolExtensions", "hnbap.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_hnbap_privateIEs,
{ "privateIEs", "hnbap.privateIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"PrivateIE_Container", HFILL }},
{ &hf_hnbap_initiatingMessage,
{ "initiatingMessage", "hnbap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_successfulOutcome,
{ "successfulOutcome", "hnbap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "hnbap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_hnbap_initiatingMessagevalue,
{ "value", "hnbap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_hnbap_successfulOutcome_value,
{ "value", "hnbap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_hnbap_unsuccessfulOutcome_value,
{ "value", "hnbap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 153 "../../asn1/hnbap/packet-hnbap-template.c"
};
static gint *ett[] = {
&ett_hnbap,
#line 1 "../../asn1/hnbap/packet-hnbap-ettarr.c"
&ett_hnbap_PrivateIE_ID,
&ett_hnbap_ProtocolIE_Container,
&ett_hnbap_ProtocolIE_Field,
&ett_hnbap_ProtocolExtensionContainer,
&ett_hnbap_ProtocolExtensionField,
&ett_hnbap_PrivateIE_Container,
&ett_hnbap_PrivateIE_Field,
&ett_hnbap_AltitudeAndDirection,
&ett_hnbap_Cause,
&ett_hnbap_CriticalityDiagnostics,
&ett_hnbap_CriticalityDiagnostics_IE_List,
&ett_hnbap_CriticalityDiagnostics_IE_List_item,
&ett_hnbap_CGI,
&ett_hnbap_GeographicalLocation,
&ett_hnbap_GeographicalCoordinates,
&ett_hnbap_HNB_Cell_Identifier,
&ett_hnbap_HNB_RNL_Identity,
&ett_hnbap_HNBConfigInfo,
&ett_hnbap_ConfigurationInformation,
&ett_hnbap_HNBConfigurationInformationProvided,
&ett_hnbap_HNBConfigurationInformationMissing,
&ett_hnbap_HNB_Location_Information,
&ett_hnbap_HNB_Identity,
&ett_hnbap_IMSIESN,
&ett_hnbap_IP_Address,
&ett_hnbap_T_ipaddress,
&ett_hnbap_Iurh_Signalling_TNL_AddressList,
&ett_hnbap_LAI,
&ett_hnbap_MacroCoverageInformation,
&ett_hnbap_MacroCellID,
&ett_hnbap_NeighbourInfoList,
&ett_hnbap_NeighbourInfoRequestList,
&ett_hnbap_NeighbourInfoRequestItem,
&ett_hnbap_PTMSIRAI,
&ett_hnbap_RABList,
&ett_hnbap_RABListItem,
&ett_hnbap_RAI,
&ett_hnbap_TMSILAI,
&ett_hnbap_TransportInfo,
&ett_hnbap_T_transportAssociation,
&ett_hnbap_UE_Capabilities,
&ett_hnbap_UTRANCellID,
&ett_hnbap_UE_Identity,
&ett_hnbap_HNBRegisterRequest,
&ett_hnbap_HNBRegisterAccept,
&ett_hnbap_HNBRegisterReject,
&ett_hnbap_HNBDe_Register,
&ett_hnbap_UERegisterRequest,
&ett_hnbap_UERegisterAccept,
&ett_hnbap_UERegisterReject,
&ett_hnbap_UEDe_Register,
&ett_hnbap_CSGMembershipUpdate,
&ett_hnbap_TNLUpdateRequest,
&ett_hnbap_TNLUpdateResponse,
&ett_hnbap_TNLUpdateFailure,
&ett_hnbap_HNBConfigTransferRequest,
&ett_hnbap_HNBConfigTransferResponse,
&ett_hnbap_RelocationComplete,
&ett_hnbap_ErrorIndication,
&ett_hnbap_PrivateMessage,
&ett_hnbap_HNBAP_PDU,
&ett_hnbap_InitiatingMessage,
&ett_hnbap_SuccessfulOutcome,
&ett_hnbap_UnsuccessfulOutcome,
#line 159 "../../asn1/hnbap/packet-hnbap-template.c"
};
proto_hnbap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_hnbap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("hnbap", dissect_hnbap, proto_hnbap);
hnbap_ies_dissector_table = register_dissector_table("hnbap.ies", "HNBAP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
hnbap_extension_dissector_table = register_dissector_table("hnbap.extension", "HNBAP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
hnbap_proc_imsg_dissector_table = register_dissector_table("hnbap.proc.imsg", "HNBAP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
hnbap_proc_sout_dissector_table = register_dissector_table("hnbap.proc.sout", "HNBAP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
hnbap_proc_uout_dissector_table = register_dissector_table("hnbap.proc.uout", "HNBAP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
hnbap_module = prefs_register_protocol(proto_hnbap, proto_reg_handoff_hnbap);
prefs_register_uint_preference(hnbap_module, "port", "HNBAP SCTP Port", "Set the port for HNBAP messages (Default of 29169)", 10, &global_sctp_port);
}
void
proto_reg_handoff_hnbap(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t hnbap_handle;
static guint sctp_port;
if (!initialized) {
hnbap_handle = find_dissector("hnbap");
dissector_add_uint("sctp.ppi", HNBAP_PAYLOAD_PROTOCOL_ID, hnbap_handle);
initialized = TRUE;
#line 1 "../../asn1/hnbap/packet-hnbap-dis-tab.c"
dissector_add_uint("hnbap.ies", id_Cause, new_create_dissector_handle(dissect_Cause_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_CriticalityDiagnostics, new_create_dissector_handle(dissect_CriticalityDiagnostics_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_HNB_Identity, new_create_dissector_handle(dissect_HNB_Identity_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_Context_ID, new_create_dissector_handle(dissect_Context_ID_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_UE_Identity, new_create_dissector_handle(dissect_UE_Identity_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_LAC, new_create_dissector_handle(dissect_LAC_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_RAC, new_create_dissector_handle(dissect_RAC_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_HNB_Location_Information, new_create_dissector_handle(dissect_HNB_Location_Information_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_PLMNidentity, new_create_dissector_handle(dissect_PLMNidentity_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_SAC, new_create_dissector_handle(dissect_SAC_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_CellIdentity, new_create_dissector_handle(dissect_CellIdentity_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_Registration_Cause, new_create_dissector_handle(dissect_Registration_Cause_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_UE_Capabilities, new_create_dissector_handle(dissect_UE_Capabilities_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_RNC_ID, new_create_dissector_handle(dissect_RNC_ID_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_CSG_ID, new_create_dissector_handle(dissect_CSG_ID_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_BackoffTimer, new_create_dissector_handle(dissect_BackoffTimer_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_CSGMembershipStatus, new_create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_RABList, new_create_dissector_handle(dissect_RABList_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_Update_cause, new_create_dissector_handle(dissect_Update_cause_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_NeighbourInfoList, new_create_dissector_handle(dissect_NeighbourInfoList_PDU, proto_hnbap));
dissector_add_uint("hnbap.ies", id_NeighbourInfoRequestList, new_create_dissector_handle(dissect_NeighbourInfoRequestList_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_HNB_Internet_Information, new_create_dissector_handle(dissect_IP_Address_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_HNB_Cell_Access_Mode, new_create_dissector_handle(dissect_HNB_Cell_Access_Mode_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_MuxPortNumber, new_create_dissector_handle(dissect_MuxPortNumber_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_CSGMembershipStatus, new_create_dissector_handle(dissect_CSGMembershipStatus_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_Iurh_Signalling_TNL_Address, new_create_dissector_handle(dissect_IP_Address_PDU, proto_hnbap));
dissector_add_uint("hnbap.extension", id_PSC, new_create_dissector_handle(dissect_PSC_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_HNBRegister, new_create_dissector_handle(dissect_HNBRegisterRequest_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.sout", id_HNBRegister, new_create_dissector_handle(dissect_HNBRegisterAccept_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.uout", id_HNBRegister, new_create_dissector_handle(dissect_HNBRegisterReject_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_UERegister, new_create_dissector_handle(dissect_UERegisterRequest_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.sout", id_UERegister, new_create_dissector_handle(dissect_UERegisterAccept_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.uout", id_UERegister, new_create_dissector_handle(dissect_UERegisterReject_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_TNLUpdate, new_create_dissector_handle(dissect_TNLUpdateRequest_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.sout", id_TNLUpdate, new_create_dissector_handle(dissect_TNLUpdateResponse_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.uout", id_TNLUpdate, new_create_dissector_handle(dissect_TNLUpdateFailure_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_HNBConfigTransfer, new_create_dissector_handle(dissect_HNBConfigTransferRequest_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.sout", id_HNBConfigTransfer, new_create_dissector_handle(dissect_HNBConfigTransferResponse_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_RelocationComplete, new_create_dissector_handle(dissect_RelocationComplete_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_UEDe_Register, new_create_dissector_handle(dissect_UEDe_Register_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_HNBDe_Register, new_create_dissector_handle(dissect_HNBDe_Register_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_ErrorIndication, new_create_dissector_handle(dissect_ErrorIndication_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_CSGMembershipUpdate, new_create_dissector_handle(dissect_CSGMembershipUpdate_PDU, proto_hnbap));
dissector_add_uint("hnbap.proc.imsg", id_privateMessage, new_create_dissector_handle(dissect_PrivateMessage_PDU, proto_hnbap));
#line 196 "../../asn1/hnbap/packet-hnbap-template.c"
} else {
dissector_delete_uint("sctp.port", sctp_port, hnbap_handle);
}
sctp_port = global_sctp_port;
dissector_add_uint("sctp.port", sctp_port, hnbap_handle);
}
