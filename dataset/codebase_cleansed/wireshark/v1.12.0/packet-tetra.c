static int
dissect_tetra_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_AACH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_AACH, AACH_sequence);
return offset;
}
static int
dissect_tetra_System_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Colour_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Timeslot_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Frame_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
32, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Multiple_Frame_Number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Sharing_Mod(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_TS_Reserved_Frames(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_U_Plane_DTX(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Frame_18_Extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Reserved(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_INTEGER_0_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_INTEGER_0_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_MLE_Sync(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MLE_Sync, MLE_Sync_sequence);
return offset;
}
static int
dissect_tetra_BSCH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_BSCH, BSCH_sequence);
return offset;
}
static int
dissect_tetra_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_Offset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_Reverse_Operation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Sencond_Ctl_Carrier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_MS_TXPWR_MAX_CELL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_RXLEV_ACCESS_MIN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_ACCESS_PARAMETER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_RADIO_DOWNLINK_TIMEOUT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_hyperframe_or_cck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_hyperframe_or_cck, T_hyperframe_or_cck_choice,
NULL);
return offset;
}
static int
dissect_tetra_FRAME(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_TS_COMMON_FRAMES(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_TS_COMMON_FRAMES, TS_COMMON_FRAMES_sequence);
return offset;
}
static int
dissect_tetra_IMM(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_WT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_NU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Frame_Len_Factor(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Timeslot_Pointer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Min_Pdu_Priority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Default_Code_A(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Default_Code_A, Default_Code_A_sequence);
return offset;
}
static int
dissect_tetra_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_SDS_TL_Addressing_Method(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Data_Priority_Supported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Section_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_PRESENT1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_PRESENT1, PRESENT1_sequence);
return offset;
}
static int
dissect_tetra_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_section(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_section, T_section_choice,
NULL);
return offset;
}
static int
dissect_tetra_Extended_Services_Broadcast(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Extended_Services_Broadcast, Extended_Services_Broadcast_sequence);
return offset;
}
static int
dissect_tetra_T_optional_params(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_params, T_optional_params_choice,
NULL);
return offset;
}
static int
dissect_tetra_Subscriber_class(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_BNCH(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_BNCH, BNCH_sequence);
return offset;
}
static int
dissect_tetra_Fill_Bit_Indication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Encrypted_Flag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_INTEGER_0_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_Address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_Address, Address_choice,
NULL);
return offset;
}
static int
dissect_tetra_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_tetra_UPDATE_TYPE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_tetra_T_cipher_control(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_cipher_control, T_cipher_control_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_class_of_MS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_class_of_MS, T_class_of_MS_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_energy_saving_mode_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_energy_saving_mode_01, T_energy_saving_mode_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_la_information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_la_information, T_la_information_choice,
NULL);
return offset;
}
static int
dissect_tetra_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_tetra_T_ssi_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_ssi_01, T_ssi_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_address_extension_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_address_extension_01, T_address_extension_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_TYPE3_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_group_identity_location_demand(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_identity_location_demand, T_group_identity_location_demand_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_group_report_response(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_report_response, T_group_report_response_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_group_identity_uplink(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_identity_uplink, T_group_identity_uplink_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_proprietary_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_proprietary_01, T_proprietary_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type3_elements_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements_01, T_type3_elements_01_sequence);
return offset;
}
static int
dissect_tetra_T_type3_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_01, T_type3_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_04, T_type2_parameters_04_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_06, T_optional_elements_06_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_LOCATION_UPDATE_DEMAND(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 98 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_LOCATION_UPDATE_DEMAND, U_LOCATION_UPDATE_DEMAND_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-LOCATION-UPDATE-DEMAND");
return offset;
}
static int
dissect_tetra_T_scanning_on_off(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_U_MM_STATUS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 229 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_MM_STATUS, U_MM_STATUS_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-MM-STATUS");
return offset;
}
static int
dissect_tetra_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_attach_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_attach_01, T_attach_01_sequence);
return offset;
}
static int
dissect_tetra_T_detach_uplike(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_detach_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_detach_01, T_detach_01_sequence);
return offset;
}
static int
dissect_tetra_T_attach_detach_identifiet_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_attach_detach_identifiet_01, T_attach_detach_identifiet_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_gssi_extension_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_gssi_extension_01, T_gssi_extension_01_sequence);
return offset;
}
static int
dissect_tetra_T_address_type_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_address_type_01, T_address_type_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_GROUP_IDENTITY_UPLINK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_GROUP_IDENTITY_UPLINK, GROUP_IDENTITY_UPLINK_sequence);
return offset;
}
static int
dissect_tetra_T_type3_elements_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements_02, T_type3_elements_02_sequence);
return offset;
}
static int
dissect_tetra_T_type3_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_02, T_type3_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_element, T_type2_element_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_07, T_optional_elements_07_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_ATTACH_DETACH_GROUP_IDENTITY(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 239 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_ATTACH_DETACH_GROUP_IDENTITY, U_ATTACH_DETACH_GROUP_IDENTITY_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-ATTACH-DETACH-GROUP-IDENTITY");
return offset;
}
static int
dissect_tetra_T_type3_elements_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements_03, T_type3_elements_03_sequence);
return offset;
}
static int
dissect_tetra_T_type3_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_03, T_type3_03_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_element_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_element_01, T_type2_element_01_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_08(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_08, T_optional_elements_08_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_ATTACH_DETACH_GROUP_IDENTITY_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 244 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_ATTACH_DETACH_GROUP_IDENTITY_ACK, U_ATTACH_DETACH_GROUP_IDENTITY_ACK_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-ATTACH-DETACH-GROUP-IDENTITY-ACK");
return offset;
}
static int
dissect_tetra_U_MM_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_U_MM_PDU, U_MM_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_CIRCUIT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Basic_service_information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Basic_service_information, Basic_service_information_sequence);
return offset;
}
static int
dissect_tetra_T_basic_service_information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_basic_service_information, T_basic_service_information_choice,
NULL);
return offset;
}
static int
dissect_tetra_Proprietary_element_owner(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_BIT_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_Type1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Type1, Type1_sequence);
return offset;
}
static int
dissect_tetra_Type2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Type2, Type2_sequence);
return offset;
}
static int
dissect_tetra_T_data_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_data_01, T_data_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_Proprietary(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Proprietary, Proprietary_sequence);
return offset;
}
static int
dissect_tetra_T_prop_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_01, T_prop_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_06, T_type2_parameters_06_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_10, T_optional_elements_10_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_ALERT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 178 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_ALERT, U_ALERT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-ALERT");
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_basic_service_information_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_basic_service_information_01, T_basic_service_information_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_02, T_prop_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_07, T_type2_parameters_07_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_11, T_optional_elements_11_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_CONNECT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 183 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_CONNECT, U_CONNECT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-CONNECT");
return offset;
}
static int
dissect_tetra_INTEGER_0_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_prop_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_05, T_prop_05_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_10, T_type2_parameters_10_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_14, T_optional_elements_14_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_DISCONNECT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 188 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_DISCONNECT, U_DISCONNECT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-DISCONNECT");
return offset;
}
static int
dissect_tetra_U_INFO(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_INFO, U_INFO_sequence);
return offset;
}
static int
dissect_tetra_U_RELEASE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 75 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_RELEASE, U_RELEASE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-RELEASE");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_RELEASE, U_RELEASE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-RELEASE");
return offset;
}
static int
dissect_tetra_T_simple_duplex_selection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_called_party_ssi_extention(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_called_party_ssi_extention, T_called_party_ssi_extention_sequence);
return offset;
}
static int
dissect_tetra_Calling_party_address_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_Calling_party_address_type, Calling_party_address_type_choice,
NULL);
return offset;
}
static int
dissect_tetra_Called_party_address_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_tetra_Calling_party_address_type(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_tetra_T_external_subscriber_number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_external_subscriber_number, T_external_subscriber_number_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop, T_prop_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_05, T_type2_parameters_05_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_09(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_09, T_optional_elements_09_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_SETUP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 198 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_SETUP, U_SETUP_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-SETUP");
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_48(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
48, 48, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_T_called_party_type_identifier_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_called_party_type_identifier_01, T_called_party_type_identifier_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_STATUS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 203 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_STATUS, U_STATUS_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-STATUS");
return offset;
}
static int
dissect_tetra_T_prop_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_03, T_prop_03_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_08(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_08, T_type2_parameters_08_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_12, T_optional_elements_12_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_TX_CEASED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 223 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_TX_CEASED, U_TX_CEASED_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-TX-CEASED");
return offset;
}
static int
dissect_tetra_T_prop_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_04, T_prop_04_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_09(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_09, T_type2_parameters_09_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_13, T_optional_elements_13_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_TX_DEMAND(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 218 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_TX_DEMAND, U_TX_DEMAND_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-TX-DEMAND");
return offset;
}
static int
dissect_tetra_Other_party_address_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_tetra_Calling_party_address_type(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_tetra_T_prop_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_06, T_prop_06_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_11, T_type2_parameters_11_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_15, T_optional_elements_15_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_CALL_RESTORE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 213 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_CALL_RESTORE, U_CALL_RESTORE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-CALL-RESTORE");
return offset;
}
static int
dissect_tetra_T_called_party_type_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_called_party_type_identifier, T_called_party_type_identifier_choice,
NULL);
return offset;
}
static int
dissect_tetra_OCTET_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_INTEGER_0_4194304(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4194304U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_short_data_type_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_short_data_type_identifier, T_short_data_type_identifier_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_SDS_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 208 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_SDS_DATA, U_SDS_DATA_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-SDS-DATA");
return offset;
}
static int
dissect_tetra_U_CMCE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_U_CMCE_PDU, U_CMCE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_cell_number(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_cell_number, T_cell_number_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters, T_type2_parameters_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements, T_optional_elements_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_PREPARE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_PREPARE, U_PREPARE_sequence);
return offset;
}
static int
dissect_tetra_T_mcc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_mcc, T_mcc_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_mnc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_mnc, T_mnc_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_la(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_la, T_la_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_01, T_type2_parameters_01_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_01, T_optional_elements_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_RESTORE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_RESTORE, U_RESTORE_sequence);
return offset;
}
static int
dissect_tetra_UMLE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_UMLE_PDU, UMLE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_MLE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_U_MLE_PDU, U_MLE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_U_BL_ADATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_ADATA, U_BL_ADATA_sequence);
return offset;
}
static int
dissect_tetra_U_BL_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_DATA, U_BL_DATA_sequence);
return offset;
}
static int
dissect_tetra_U_BL_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_ACK, U_BL_ACK_sequence);
return offset;
}
static int
dissect_tetra_U_BL_ADATA_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_ADATA_FCS, U_BL_ADATA_FCS_sequence);
return offset;
}
static int
dissect_tetra_U_BL_DATA_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_DATA_FCS, U_BL_DATA_FCS_sequence);
return offset;
}
static int
dissect_tetra_U_MLE_PDU_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_MLE_PDU_FCS, U_MLE_PDU_FCS_sequence);
return offset;
}
static int
dissect_tetra_U_BL_ACK_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_U_BL_ACK_FCS, U_BL_ACK_FCS_sequence);
return offset;
}
static int
dissect_tetra_U_LLC_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_U_LLC_PDU, U_LLC_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_LengthIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
32, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Frag1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_SLOT_APPLY(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_FRAG(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_FRAG, FRAG_sequence);
return offset;
}
static int
dissect_tetra_T_lengthIndicationOrCapacityRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_lengthIndicationOrCapacityRequest, T_lengthIndicationOrCapacityRequest_choice,
NULL);
return offset;
}
static int
dissect_tetra_ComplexSDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_ComplexSDU, ComplexSDU_sequence);
return offset;
}
static int
dissect_tetra_T_data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_data, T_data_choice,
NULL);
return offset;
}
static int
dissect_tetra_MAC_ACCESS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_ACCESS, MAC_ACCESS_sequence);
return offset;
}
static int
dissect_tetra_LengthIndicationMacData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_FRAG6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_FRAG6, FRAG6_sequence);
return offset;
}
static int
dissect_tetra_T_lengthIndicationOrCapacityRequest_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_lengthIndicationOrCapacityRequest_01, T_lengthIndicationOrCapacityRequest_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_MAC_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_DATA, MAC_DATA_sequence);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_264(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
264, 264, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_FRAG(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_FRAG, MAC_FRAG_sequence);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_120(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
120, 120, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_FRAG120(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_FRAG120, MAC_FRAG120_sequence);
return offset;
}
static int
dissect_tetra_LengthIndOrReservationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_258(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
258, 258, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_END_UPLINK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_END_UPLINK, MAC_END_UPLINK_sequence);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_114(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
114, 114, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_END_UP114(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_END_UP114, MAC_END_UP114_sequence);
return offset;
}
static int
dissect_tetra_LengthIndMacHu(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_lengthInd_ReservationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_lengthInd_ReservationReq, T_lengthInd_ReservationReq_choice,
NULL);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_85(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
85, 85, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_END_HU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_END_HU, MAC_END_HU_sequence);
return offset;
}
static int
dissect_tetra_Position_Of_Grant(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_LengthIndicationMacEndDl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Capacity_Allocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Granting_delay(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_SlotGranting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SlotGranting, SlotGranting_sequence);
return offset;
}
static int
dissect_tetra_T_slot_granting(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_slot_granting, T_slot_granting_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_allocation_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Timeslot_Assigned(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_up_down_assigned(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_CLCH_permission(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Cell_change_flag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_reverse_operation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Extended_carrier_flag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Extended_carrier_flag, Extended_carrier_flag_sequence);
return offset;
}
static int
dissect_tetra_T_extend_carrier_flag(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_extend_carrier_flag, T_extend_carrier_flag_choice,
NULL);
return offset;
}
static int
dissect_tetra_Monitoring_pattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_monitoring_pattern(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_monitoring_pattern, T_monitoring_pattern_choice,
NULL);
return offset;
}
static int
dissect_tetra_ChannelAllocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_ChannelAllocation, ChannelAllocation_sequence);
return offset;
}
static int
dissect_tetra_T_channel_allocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_channel_allocation, T_channel_allocation_choice,
NULL);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
255, 255, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_END_DOWNLINK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_END_DOWNLINK, MAC_END_DOWNLINK_sequence);
return offset;
}
static int
dissect_tetra_T_slot_granting_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_slot_granting_01, T_slot_granting_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_channel_allocation_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_channel_allocation_01, T_channel_allocation_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_111(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
111, 111, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_MAC_END_DOWN111(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_END_DOWN111, MAC_END_DOWN111_sequence);
return offset;
}
static int
dissect_tetra_T_access_ack(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_LengthIndicationMacResource(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
64, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_PowerControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
16, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_power_control(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_power_control, T_power_control_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_slot_granting_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_slot_granting_02, T_slot_granting_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_channel_allocation_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_channel_allocation_02, T_channel_allocation_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_ssi(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_ssi, T_ssi_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_address_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_address_extension, T_address_extension_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_subscriber_class(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_subscriber_class, T_subscriber_class_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_energy_saving_mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_energy_saving_mode, T_energy_saving_mode_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_scch_info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_scch_info, T_scch_info_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_new_ra(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_new_ra, T_new_ra_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_group_identity_location_accept(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_identity_location_accept, T_group_identity_location_accept_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_group_predefined_lifetime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_predefined_lifetime, T_group_predefined_lifetime_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_group_identity_downlink(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_group_identity_downlink, T_group_identity_downlink_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_proprietary(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_proprietary, T_proprietary_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type3_elements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements, T_type3_elements_sequence);
return offset;
}
static int
dissect_tetra_T_type3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3, T_type3_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_03, T_type2_parameters_03_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_05, T_optional_elements_05_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_LOCATION_UPDATE_ACCEPT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 104 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_LOCATION_UPDATE_ACCEPT, D_LOCATION_UPDATE_ACCEPT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-LOCATION-UPDATE-ACCEPT");
return offset;
}
static int
dissect_tetra_D_LOCATION_UPDATE_REJECT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 249 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_LOCATION_UPDATE_REJECT, D_LOCATION_UPDATE_REJECT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-LOCATION-UPDATE-REJECT");
return offset;
}
static int
dissect_tetra_T_attach(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_attach, T_attach_sequence);
return offset;
}
static int
dissect_tetra_T_detach_downlike(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_detach(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_detach, T_detach_sequence);
return offset;
}
static int
dissect_tetra_T_attach_detach_identifiet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_attach_detach_identifiet, T_attach_detach_identifiet_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_gssi_extension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_gssi_extension, T_gssi_extension_sequence);
return offset;
}
static int
dissect_tetra_T_address_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_address_type, T_address_type_choice,
NULL);
return offset;
}
static int
dissect_tetra_GROUP_IDENTITY_DOWNLINK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_GROUP_IDENTITY_DOWNLINK, GROUP_IDENTITY_DOWNLINK_sequence);
return offset;
}
static int
dissect_tetra_T_type3_elements_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements_04, T_type3_elements_04_sequence);
return offset;
}
static int
dissect_tetra_T_type3_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_04, T_type3_04_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_element_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_element_02, T_type2_element_02_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_24, T_optional_elements_24_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_ATTACH_DETACH_GROUP_IDENTITY(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 254 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_ATTACH_DETACH_GROUP_IDENTITY, D_ATTACH_DETACH_GROUP_IDENTITY_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-ATTACH-DETACH-GROUP-IDENTITY");
return offset;
}
static int
dissect_tetra_T_type3_elements_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_elements_05, T_type3_elements_05_sequence);
return offset;
}
static int
dissect_tetra_T_type3_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type3_05, T_type3_05_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_element_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_element_03, T_type2_element_03_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_25(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_25, T_optional_elements_25_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_ATTACH_DETACH_GROUP_IDENTITY_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 259 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_ATTACH_DETACH_GROUP_IDENTITY_ACK, D_ATTACH_DETACH_GROUP_IDENTITY_ACK_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-ATTACH-DETACH-GROUP-IDENTITY-ACK");
return offset;
}
static int
dissect_tetra_D_MM_STATUS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 234 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_MM_STATUS, D_MM_STATUS_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "U-MM-STATUS");
return offset;
}
static int
dissect_tetra_D_MM_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_D_MM_PDU, D_MM_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_basic_service_infomation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_basic_service_infomation, T_basic_service_infomation_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_notification_indicator_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_01, T_notification_indicator_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_09(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_09, T_prop_09_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_14, T_type2_parameters_14_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_18, T_optional_elements_18_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_ALERT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 130 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_ALERT, D_ALERT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-ALERT");
return offset;
}
static int
dissect_tetra_T_basic_service_information_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_basic_service_information_02, T_basic_service_information_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_call_status(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_call_status, T_call_status_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_notification_indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator, T_notification_indicator_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_08(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_08, T_prop_08_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_13, T_type2_parameters_13_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_17(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_17, T_optional_elements_17_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_CALL_PROCEEDING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 87 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_CALL_PROCEEDING, D_CALL_PROCEEDING_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-CALL-PROCEEDING");
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_call_priority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_call_priority, T_call_priority_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_basic_service_information_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_basic_service_information_03, T_basic_service_information_03_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_temporary_address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_temporary_address, T_temporary_address_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_notification_indicator_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_02, T_notification_indicator_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_10, T_prop_10_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_15, T_type2_parameters_15_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_19(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_19, T_optional_elements_19_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_CONNECT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 110 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_CONNECT, D_CONNECT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-CONNECT");
return offset;
}
static int
dissect_tetra_T_notification_indicator_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_03, T_notification_indicator_03_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_11, T_prop_11_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_16, T_type2_parameters_16_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_20(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_20, T_optional_elements_20_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_CONNECT_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 115 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_CONNECT_ACK, D_CONNECT_ACK_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-CONNECT-ACK");
return offset;
}
static int
dissect_tetra_D_DISCONNECT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 125 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_DISCONNECT, D_DISCONNECT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-DISCONNECT");
return offset;
}
static int
dissect_tetra_D_INFO(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 120 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_INFO, D_INFO_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-INFO");
return offset;
}
static int
dissect_tetra_T_notification_indicator_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_04, T_notification_indicator_04_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_12, T_prop_12_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_17(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_17, T_type2_parameters_17_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_21(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_21, T_optional_elements_21_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_RELEASE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 80 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_RELEASE, D_RELEASE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-RELEASE");
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_T_calling_party_address(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_calling_party_address, T_calling_party_address_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_external_subscriber_number_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_external_subscriber_number_01, T_external_subscriber_number_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_07, T_prop_07_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_12, T_type2_parameters_12_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_16, T_optional_elements_16_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_SETUP(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 92 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_SETUP, D_SETUP_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-SETUP");
return offset;
}
static int
dissect_tetra_OCTET_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL);
return offset;
}
static int
dissect_tetra_T_calling_party_type_identifier_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_calling_party_type_identifier_01, T_calling_party_type_identifier_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_STATUS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 141 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_STATUS, D_STATUS_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-STATUS");
return offset;
}
static int
dissect_tetra_T_notification_indicator_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_06, T_notification_indicator_06_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_14(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_14, T_prop_14_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_19(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_19, T_type2_parameters_19_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_23(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_23, T_optional_elements_23_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_TX_CEASED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 135 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_TX_CEASED, D_TX_CEASED_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-TX-CEASED");
return offset;
}
static int
dissect_tetra_D_TX_CONTINUE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 146 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_TX_CONTINUE, D_TX_CONTINUE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-TX-CONTINUE");
return offset;
}
static int
dissect_tetra_D_TX_GRANTED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 151 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_TX_GRANTED, D_TX_GRANTED_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-TX-GRANTED");
return offset;
}
static int
dissect_tetra_D_TX_WAIT(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 157 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_TX_WAIT, D_TX_WAIT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-TX-WAIT");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_TX_WAIT, D_TX_WAIT_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-TX-WAIT");
return offset;
}
static int
dissect_tetra_T_new_call_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_new_call_identifier, T_new_call_identifier_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_call_time_out(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_call_time_out, T_call_time_out_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_call_status_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_call_status_01, T_call_status_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_simplex_duplex_selection_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_tetra_Modify_type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_Modify_type, Modify_type_sequence);
return offset;
}
static int
dissect_tetra_T_modify(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_modify, T_modify_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_notification_indicator_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_notification_indicator_05, T_notification_indicator_05_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_prop_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_prop_13, T_prop_13_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_18(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_18, T_type2_parameters_18_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_22(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_22, T_optional_elements_22_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_CALL_RESTORE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 162 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_CALL_RESTORE, D_CALL_RESTORE_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-CALL-RESTORE");
return offset;
}
static int
dissect_tetra_T_calling_party_type_identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_calling_party_type_identifier, T_calling_party_type_identifier_choice,
NULL);
return offset;
}
static int
dissect_tetra_OCTET_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_tetra_T_short_data_type_identifier_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_short_data_type_identifier_01, T_short_data_type_identifier_01_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_SDS_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 167 "../../asn1/tetra/tetra.cnf"
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_SDS_DATA, D_SDS_DATA_sequence);
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "D-SDS-DATA");
return offset;
}
static int
dissect_tetra_D_CMCE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_D_CMCE_PDU, D_CMCE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_optional_elements_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_02, T_optional_elements_02_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_NEW_CELL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_NEW_CELL, D_NEW_CELL_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_03, T_optional_elements_03_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_PREPARE_FAIL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_PREPARE_FAIL, D_PREPARE_FAIL_sequence);
return offset;
}
static int
dissect_tetra_T_network_time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_tetra_T_reserved(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_integer(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_tetra_TETRA_NETWORK_TIME(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_TETRA_NETWORK_TIME, TETRA_NETWORK_TIME_sequence);
return offset;
}
static int
dissect_tetra_T_tetra_network_time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_tetra_network_time, T_tetra_network_time_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_number_of_neighbour_cells(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_number_of_neighbour_cells, T_number_of_neighbour_cells_choice,
NULL);
return offset;
}
static int
dissect_tetra_T_type2_parameters_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_T_type2_parameters_02, T_type2_parameters_02_sequence);
return offset;
}
static int
dissect_tetra_T_optional_elements_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_elements_04, T_optional_elements_04_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_NWRK_BRDADCAST(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_NWRK_BRDADCAST, D_NWRK_BRDADCAST_sequence);
return offset;
}
static int
dissect_tetra_D_RESTORE_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_RESTORE_ACK, D_RESTORE_ACK_sequence);
return offset;
}
static int
dissect_tetra_D_RESTORE_FAIL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_RESTORE_FAIL, D_RESTORE_FAIL_sequence);
return offset;
}
static int
dissect_tetra_DMLE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_DMLE_PDU, DMLE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_MLE_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_D_MLE_PDU, D_MLE_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_D_BL_ADATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_ADATA, D_BL_ADATA_sequence);
return offset;
}
static int
dissect_tetra_D_BL_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_DATA, D_BL_DATA_sequence);
return offset;
}
static int
dissect_tetra_D_BL_ACK(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_ACK, D_BL_ACK_sequence);
return offset;
}
static int
dissect_tetra_D_BL_ADATA_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_ADATA_FCS, D_BL_ADATA_FCS_sequence);
return offset;
}
static int
dissect_tetra_D_BL_DATA_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_DATA_FCS, D_BL_DATA_FCS_sequence);
return offset;
}
static int
dissect_tetra_D_MLE_PDU_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_MLE_PDU_FCS, D_MLE_PDU_FCS_sequence);
return offset;
}
static int
dissect_tetra_D_BL_ACK_FCS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_D_BL_ACK_FCS, D_BL_ACK_FCS_sequence);
return offset;
}
static int
dissect_tetra_D_LLC_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_D_LLC_PDU, D_LLC_PDU_choice,
NULL);
return offset;
}
static int
dissect_tetra_OTHER_DATA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_OTHER_DATA, OTHER_DATA_sequence);
return offset;
}
static int
dissect_tetra_SSI_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SSI_NEED, SSI_NEED_sequence);
return offset;
}
static int
dissect_tetra_EVENT_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_EVENT_NEED, EVENT_NEED_sequence);
return offset;
}
static int
dissect_tetra_USSI_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_USSI_NEED, USSI_NEED_sequence);
return offset;
}
static int
dissect_tetra_SMI_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SMI_NEED, SMI_NEED_sequence);
return offset;
}
static int
dissect_tetra_SSI_EVENT_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SSI_EVENT_NEED, SSI_EVENT_NEED_sequence);
return offset;
}
static int
dissect_tetra_SSI_USAGE_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SSI_USAGE_NEED, SSI_USAGE_NEED_sequence);
return offset;
}
static int
dissect_tetra_BIT_STRING_SIZE_34(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
34, 34, FALSE, NULL, NULL);
return offset;
}
static int
dissect_tetra_SMI_EVENT_NEED(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_SMI_EVENT_NEED, SMI_EVENT_NEED_sequence);
return offset;
}
static int
dissect_tetra_AddressMacResource(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_AddressMacResource, AddressMacResource_choice,
NULL);
return offset;
}
static int
dissect_tetra_MAC_RESOURCE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_RESOURCE, MAC_RESOURCE_sequence);
return offset;
}
static int
dissect_tetra_INTEGER_0_33554431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 33554431U, NULL, FALSE);
return offset;
}
static int
dissect_tetra_T_optional_field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_tetra_T_optional_field, T_optional_field_choice,
NULL);
return offset;
}
static int
dissect_tetra_MAC_ACCESS_DEFINE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_tetra_MAC_ACCESS_DEFINE, MAC_ACCESS_DEFINE_sequence);
return offset;
}
static void dissect_AACH_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_AACH(tvb, 0, &asn1_ctx, tree, hf_tetra_AACH_PDU);
}
static void dissect_BSCH_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_BSCH(tvb, 0, &asn1_ctx, tree, hf_tetra_BSCH_PDU);
}
static void dissect_BNCH_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_BNCH(tvb, 0, &asn1_ctx, tree, hf_tetra_BNCH_PDU);
}
static void dissect_MAC_ACCESS_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_ACCESS(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_ACCESS_PDU);
}
static void dissect_MAC_DATA_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_DATA(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_DATA_PDU);
}
static void dissect_MAC_FRAG_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_FRAG(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_FRAG_PDU);
}
static void dissect_MAC_FRAG120_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_FRAG120(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_FRAG120_PDU);
}
static void dissect_MAC_END_UPLINK_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_END_UPLINK(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_END_UPLINK_PDU);
}
static void dissect_MAC_END_UP114_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_END_UP114(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_END_UP114_PDU);
}
static void dissect_MAC_END_HU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_END_HU(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_END_HU_PDU);
}
static void dissect_MAC_END_DOWNLINK_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_END_DOWNLINK(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_END_DOWNLINK_PDU);
}
static void dissect_MAC_END_DOWN111_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_END_DOWN111(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_END_DOWN111_PDU);
}
static void dissect_MAC_RESOURCE_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_RESOURCE(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_RESOURCE_PDU);
}
static void dissect_MAC_ACCESS_DEFINE_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
dissect_tetra_MAC_ACCESS_DEFINE(tvb, 0, &asn1_ctx, tree, hf_tetra_MAC_ACCESS_DEFINE_PDU);
}
static gint get_rx_pdu_length(guint32 channel_type)
{
gint len = 0;
switch(channel_type) {
case TETRA_CHAN_AACH:
len = 14;
break;
case TETRA_CHAN_SCH_F:
len = 268;
break;
case TETRA_CHAN_SCH_D:
len = 124; ;
break;
case TETRA_CHAN_BSCH:
len = 60;
break;
case TETRA_CHAN_BNCH:
len = 124;
break;
case TETRA_CHAN_TCH_F:
len = 274;
break;
case TETRA_CHAN_TCH_H:
len = 137;
break;
case TETRA_CHAN_TCH_2_4:
len = 144;
break;
case TETRA_CHAN_TCH_4_8:
len = 288;
break;
case TETRA_CHAN_STCH:
len = 124;
break;
case TETRA_CHAN_SCH_HU:
len = 92;
break;
default:
len = 0;
break;
}
return len;
}
static gint get_tx_pdu_length(guint32 channel_type)
{
gint len = 0;
switch(channel_type) {
case TETRA_CHAN_AACH:
len = 14;
break;
case TETRA_CHAN_SCH_F:
len = 268;
break;
case TETRA_CHAN_SCH_D:
len = 124;
break;
case TETRA_CHAN_BSCH:
len = 60;
break;
case TETRA_CHAN_BNCH:
len = 124;
break;
case TETRA_CHAN_TCH_F:
len = 274;
break;
case TETRA_CHAN_TCH_H:
len = 137;
break;
case TETRA_CHAN_TCH_2_4:
len = 144;
break;
case TETRA_CHAN_TCH_4_8:
len = 288;
break;
case TETRA_CHAN_STCH:
len = 124;
break;
}
return len;
}
void tetra_dissect_pdu(int channel_type, int dir, tvbuff_t *pdu, proto_tree *tree, packet_info *pinfo)
{
proto_item *tetra_sub_item;
proto_tree *tetra_sub_tree;
guint8 p;
tetra_sub_item = proto_tree_add_item(tree, hf_tetra_pdu,
pdu, 0, tvb_length(pdu), ENC_NA);
tetra_sub_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
switch(channel_type) {
case TETRA_CHAN_AACH:
dissect_AACH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_SCH_F:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
if (dir == TETRA_DOWNLINK)
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_DATA_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3) {
if (dir == TETRA_DOWNLINK)
dissect_MAC_END_DOWNLINK_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_END_UPLINK_PDU(pdu, pinfo, tetra_sub_tree);
} else
dissect_MAC_FRAG_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
case TETRA_CHAN_SCH_D:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3)
dissect_MAC_END_DOWN111_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_FRAG120_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
case TETRA_CHAN_SCH_HU:
p = tvb_get_guint8(pdu, 0);
switch(p >> 7) {
case 0:
dissect_MAC_ACCESS_PDU(pdu, pinfo, tetra_sub_tree);
break;
case 1:
dissect_MAC_END_HU_PDU(pdu, pinfo, tetra_sub_tree);
break;
}
break;
case TETRA_CHAN_BSCH:
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "BSCH");
dissect_BSCH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_BNCH:
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "BNCH");
dissect_BNCH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_STCH:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3) {
if (dir == TETRA_DOWNLINK)
dissect_MAC_END_DOWN111_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_END_UP114_PDU(pdu, pinfo, tetra_sub_tree);
} else
dissect_MAC_FRAG120_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
case TETRA_CHAN_TCH_F:
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Voice");
break;
}
}
static void dissect_tetra_UNITDATA_IND(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tetra_tree, int offset)
{
guint32 rxreg = 0;
guint32 channels = 0, i;
guint32 channel_type;
gint pdu_offset = 0;
proto_item *tetra_sub_item;
proto_tree *tetra_header_tree = NULL;
tvbuff_t *payload_tvb;
rxreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_len0, tvb, offset, 4, rxreg);
offset += 4;
rxreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_rvstr, tvb, offset, 4, rxreg);
channels = rxreg & 0x3;
tetra_sub_item = proto_tree_add_uint( tetra_tree, hf_tetra_channels, tvb, offset, 4, channels );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
if (channels > 3) {
expert_add_info(pinfo, tetra_sub_item, &ei_tetra_channels_incorrect);
channels = 3;
}
pdu_offset = offset + 4;
for(i = 0; i < channels; i++) {
gint byte_len, bits_len, remaining_bits;
gint hf_channel[3];
hf_channel[0] = hf_tetra_rxchannel1;
hf_channel[1] = hf_tetra_rxchannel2;
hf_channel[2] = hf_tetra_rxchannel3;
channel_type = (rxreg >> ((i + 1) * 4) ) & 0xf;
proto_tree_add_uint( tetra_header_tree, hf_channel[i], tvb, offset, 4, channel_type);
proto_tree_add_boolean( tetra_header_tree, hf_tetra_crc, tvb, offset, 4, !(rxreg >> (i + 2) & 0x01));
bits_len = get_rx_pdu_length(channel_type);
byte_len = bits_len >> 3;
remaining_bits = bits_len % 8;
if ((remaining_bits)!=0)
byte_len++;
payload_tvb = tvb_new_subset(tvb, pdu_offset, byte_len, byte_len);
tetra_dissect_pdu(channel_type, TETRA_UPLINK, payload_tvb, tetra_header_tree, pinfo);
if ((remaining_bits)!=0)
byte_len--;
pdu_offset += byte_len;
}
}
static void dissect_tetra_UNITDATA_REQ(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tetra_tree, int offset)
{
guint32 txreg = 0;
guint32 channels = 0, i;
guint32 channel_type;
gint pdu_offset = 0;
proto_item *tetra_sub_item = NULL;
proto_tree *tetra_header_tree = NULL;
tvbuff_t *payload_tvb;
txreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_txreg, tvb, offset, 4, txreg);
channels = (txreg & 0x3) + 1;
tetra_sub_item = proto_tree_add_uint( tetra_tree, hf_tetra_channels, tvb, offset, 4, channels );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
txreg >>= 2;
if(channels == 2)
txreg >>= 4;
if (channels > 3) {
expert_add_info(pinfo, tetra_sub_item, &ei_tetra_channels_incorrect);
channels = 3;
}
pdu_offset = offset + 4;
for(i = 0; i < channels; i++) {
gint byte_len, bits_len, remaining_bits;
gint hf_channel[3];
hf_channel[0] = hf_tetra_channel1;
hf_channel[1] = hf_tetra_channel2;
hf_channel[2] = hf_tetra_channel3;
channel_type = txreg & 0xf;
proto_tree_add_uint( tetra_header_tree, hf_channel[i], tvb, offset, 4, channel_type);
txreg >>= 4;
bits_len = get_tx_pdu_length(channel_type);
byte_len = bits_len >> 3;
remaining_bits = bits_len % 8;
if ((remaining_bits)!=0)
byte_len++;
payload_tvb = tvb_new_subset(tvb, pdu_offset, byte_len, byte_len);
tetra_dissect_pdu(channel_type, TETRA_DOWNLINK, payload_tvb, tetra_header_tree, pinfo);
pdu_offset += byte_len;
}
}
static void
dissect_tetra(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *tetra_item = NULL;
proto_item *tetra_sub_item = NULL;
proto_tree *tetra_tree = NULL;
proto_tree *tetra_header_tree = NULL;
guint16 type = 0;
guint8 carriernumber = -1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_tetra);
col_clear(pinfo->cinfo,COL_INFO);
type = tvb_get_guint8(tvb, 0);
if(include_carrier_number) {
carriernumber = tvb_get_guint8(tvb, 1);
}
switch(type) {
case 1:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-REQ, Carrier: %d",
carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-REQ");
break;
case 2:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-IND, Carrier: %d",
carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-IND");
break;
case 3:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "MAC-Timer, Carrier: %d",
carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "MAC-Timer");
break;
case 127:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-IND Done, Carrier: %d",
carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-IND Done");
break;
case 128:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-REQ Done, Carrier: %d",
carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Tetra-UNITDATA-REQ Done");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown command: %d", type);
break;
}
if (tree) {
guint32 offset = 0;
guint32 txtimer = 0;
guint32 tslot = 0;
tetra_item = proto_tree_add_item(tree, proto_tetra, tvb, 0, -1, ENC_NA);
tetra_tree = proto_item_add_subtree(tetra_item, ett_tetra);
offset ++;
if(include_carrier_number) {
proto_tree_add_uint(tetra_tree, hf_tetra_carriernumber, tvb, offset, 1, carriernumber);
offset ++;
}
tetra_sub_item = proto_tree_add_item( tetra_tree, hf_tetra_header, tvb, offset, -1, ENC_NA );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
txtimer = tvb_get_letohl(tvb, offset);
tetra_sub_item = proto_tree_add_item(tetra_header_tree, hf_tetra_timer, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tslot = ((txtimer & 0x7800) >> 11);
if(tslot==4)
tslot = 3;
if(tslot==8)
tslot = 4;
proto_item_append_text(tetra_sub_item, " (Multiple frame: %d, Frame: %d, Slot: %d)",
txtimer & 0x3F, (txtimer & 0x7c0) >> 6,
tslot);
offset += 4;
switch(type) {
case 1:
case 128:
dissect_tetra_UNITDATA_REQ(tvb, pinfo, tetra_header_tree, offset);
break;
case 2:
case 127:
dissect_tetra_UNITDATA_IND(tvb, pinfo, tetra_header_tree, offset);
break;
case 3:
break;
default:
break;
}
}
}
void proto_reg_handoff_tetra(void)
{
static gboolean initialized=FALSE;
if (!initialized) {
data_handle = find_dissector("data");
tetra_handle = create_dissector_handle(dissect_tetra, proto_tetra);
dissector_add_uint("udp.port", global_tetra_port, tetra_handle);
}
}
void proto_register_tetra (void)
{
module_t *tetra_module;
expert_module_t* expert_tetra;
static hf_register_info hf[] = {
{ &hf_tetra,
{ "Data", "tetra.data", FT_NONE, BASE_NONE, NULL, 0x0,
"tetra PDU", HFILL }},
{ &hf_tetra_header,
{ "Registers", "tetra.header", FT_NONE, BASE_NONE, NULL, 0x0,
"TETRA Registers", HFILL }},
{ &hf_tetra_channels,
{ "Logical Channels", "tetra.channels", FT_UINT8, BASE_DEC, NULL, 0x0,
"The amount of logical channels", HFILL }},
{ &hf_tetra_channel1,
{ "Channel 1", "tetra.txchannel1", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_channel2,
{ "Channel 2", "tetra.txchannel2", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_channel3,
{ "Channel 3", "tetra.txchannel3", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_txreg,
{ "TxR", "tetra.txreg", FT_UINT16, BASE_HEX, NULL, 0x0,
"TX Register", HFILL }},
{ &hf_tetra_rvstr,
{ "RvSteR", "tetra.rvster", FT_UINT16, BASE_HEX, NULL, 0x0,
"Receive Status Register", HFILL }},
{ &hf_tetra_carriernumber,
{ "Carrier Number", "tetra.carrier", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tetra_rxchannel1,
{ "Channel 1", "tetra.rxchannel1", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_rxchannel2,
{ "Channel 2", "tetra.rxchannel2", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_rxchannel3,
{ "Channel 3", "tetra.rxchannel3", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_timer,
{ "Timer", "tetra.timer", FT_UINT16, BASE_HEX, NULL, 0x0,
"Timer Register", HFILL }},
{ &hf_tetra_crc,
{ "CRC", "tetra.crc", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"CRC result", HFILL }},
{ &hf_tetra_len0,
{ "Length", "tetra.len0", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of the PDU", HFILL }},
{ &hf_tetra_pdu,
{ "PDU", "tetra.pdu", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }} ,
#line 1 "../../asn1/tetra/packet-tetra-hfarr.c"
{ &hf_tetra_AACH_PDU,
{ "AACH", "tetra.AACH_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_BSCH_PDU,
{ "BSCH", "tetra.BSCH_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_BNCH_PDU,
{ "BNCH", "tetra.BNCH_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_ACCESS_PDU,
{ "MAC-ACCESS", "tetra.MAC_ACCESS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_DATA_PDU,
{ "MAC-DATA", "tetra.MAC_DATA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_FRAG_PDU,
{ "MAC-FRAG", "tetra.MAC_FRAG_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_FRAG120_PDU,
{ "MAC-FRAG120", "tetra.MAC_FRAG120_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_END_UPLINK_PDU,
{ "MAC-END-UPLINK", "tetra.MAC_END_UPLINK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_END_UP114_PDU,
{ "MAC-END-UP114", "tetra.MAC_END_UP114_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_END_HU_PDU,
{ "MAC-END-HU", "tetra.MAC_END_HU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_END_DOWNLINK_PDU,
{ "MAC-END-DOWNLINK", "tetra.MAC_END_DOWNLINK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_END_DOWN111_PDU,
{ "MAC-END-DOWN111", "tetra.MAC_END_DOWN111_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_RESOURCE_PDU,
{ "MAC-RESOURCE", "tetra.MAC_RESOURCE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_MAC_ACCESS_DEFINE_PDU,
{ "MAC-ACCESS-DEFINE", "tetra.MAC_ACCESS_DEFINE_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_function,
{ "function", "tetra.function",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_field1,
{ "field1", "tetra.field1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_field2,
{ "field2", "tetra.field2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_system_code,
{ "system-code", "tetra.system_code",
FT_UINT32, BASE_DEC, VALS(tetra_System_Code_vals), 0,
NULL, HFILL }},
{ &hf_tetra_colour_code,
{ "colour-code", "tetra.colour_code",
FT_UINT32, BASE_DEC, VALS(tetra_Colour_Code_vals), 0,
NULL, HFILL }},
{ &hf_tetra_timeslot_number,
{ "timeslot-number", "tetra.timeslot_number",
FT_UINT32, BASE_DEC, VALS(tetra_Timeslot_Number_vals), 0,
NULL, HFILL }},
{ &hf_tetra_frame_number,
{ "frame-number", "tetra.frame_number",
FT_UINT32, BASE_DEC, VALS(tetra_Frame_Number_vals), 0,
NULL, HFILL }},
{ &hf_tetra_multiple_frame_number,
{ "multiple-frame-number", "tetra.multiple_frame_number",
FT_UINT32, BASE_DEC, VALS(tetra_Multiple_Frame_Number_vals), 0,
NULL, HFILL }},
{ &hf_tetra_sharing_mod,
{ "sharing-mod", "tetra.sharing_mod",
FT_UINT32, BASE_DEC, VALS(tetra_Sharing_Mod_vals), 0,
NULL, HFILL }},
{ &hf_tetra_ts_reserved_frames,
{ "ts-reserved-frames", "tetra.ts_reserved_frames",
FT_UINT32, BASE_DEC, VALS(tetra_TS_Reserved_Frames_vals), 0,
NULL, HFILL }},
{ &hf_tetra_u_plane_dtx,
{ "u-plane-dtx", "tetra.u_plane_dtx",
FT_UINT32, BASE_DEC, VALS(tetra_U_Plane_DTX_vals), 0,
NULL, HFILL }},
{ &hf_tetra_frame_18_extension,
{ "frame-18-extension", "tetra.frame_18_extension",
FT_UINT32, BASE_DEC, VALS(tetra_Frame_18_Extension_vals), 0,
NULL, HFILL }},
{ &hf_tetra_reserved,
{ "reserved", "tetra.reserved",
FT_UINT32, BASE_DEC, VALS(tetra_Reserved_vals), 0,
NULL, HFILL }},
{ &hf_tetra_tm_sdu,
{ "tm-sdu", "tetra.tm_sdu_element",
FT_NONE, BASE_NONE, NULL, 0,
"MLE_Sync", HFILL }},
{ &hf_tetra_mcc,
{ "mcc", "tetra.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_mnc,
{ "mnc", "tetra.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_neighbour_cell_broadcast,
{ "neighbour-cell-broadcast", "tetra.neighbour_cell_broadcast",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_cell_service_level,
{ "cell-service-level", "tetra.cell_service_level",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_late_entry_information,
{ "late-entry-information", "tetra.late_entry_information",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_pdu_type,
{ "pdu-type", "tetra.pdu_type",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_broadcast_type,
{ "broadcast-type", "tetra.broadcast_type",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_main_carrier,
{ "main-carrier", "tetra.main_carrier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_tetra_frequency_band,
{ "frequency-band", "tetra.frequency_band",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_offset,
{ "offset", "tetra.offset",
FT_UINT32, BASE_DEC, VALS(tetra_Offset_vals), 0,
NULL, HFILL }},
{ &hf_tetra_duplex_spacing,
{ "duplex-spacing", "tetra.duplex_spacing",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_reverse_operation,
{ "reverse-operation", "tetra.reverse_operation",
FT_UINT32, BASE_DEC, VALS(tetra_Reverse_Operation_vals), 0,
NULL, HFILL }},
{ &hf_tetra_sencond_ctl_carrier,
{ "sencond-ctl-carrier", "tetra.sencond_ctl_carrier",
FT_UINT32, BASE_DEC, VALS(tetra_Sencond_Ctl_Carrier_vals), 0,
NULL, HFILL }},
{ &hf_tetra_ms_txpwr_max_cell,
{ "ms-txpwr-max-cell", "tetra.ms_txpwr_max_cell",
FT_UINT32, BASE_DEC, VALS(tetra_MS_TXPWR_MAX_CELL_vals), 0,
NULL, HFILL }},
{ &hf_tetra_rxlev_access_min,
{ "rxlev-access-min", "tetra.rxlev_access_min",
FT_UINT32, BASE_DEC, VALS(tetra_RXLEV_ACCESS_MIN_vals), 0,
NULL, HFILL }},
{ &hf_tetra_access_parameter,
{ "access-parameter", "tetra.access_parameter",
FT_UINT32, BASE_DEC, VALS(tetra_ACCESS_PARAMETER_vals), 0,
NULL, HFILL }},
{ &hf_tetra_radio_downlink_timeout,
{ "radio-downlink-timeout", "tetra.radio_downlink_timeout",
FT_UINT32, BASE_DEC, VALS(tetra_RADIO_DOWNLINK_TIMEOUT_vals), 0,
NULL, HFILL }},
{ &hf_tetra_hyperframe_or_cck,
{ "hyperframe-or-cck", "tetra.hyperframe_or_cck",
FT_UINT32, BASE_DEC, VALS(tetra_T_hyperframe_or_cck_vals), 0,
NULL, HFILL }},
{ &hf_tetra_hyperframe,
{ "hyperframe", "tetra.hyperframe",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_cckid,
{ "cckid", "tetra.cckid",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_optional_params,
{ "optional-params", "tetra.optional_params",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_params_vals), 0,
NULL, HFILL }},
{ &hf_tetra_even_multiframe,
{ "even-multiframe", "tetra.even_multiframe_element",
FT_NONE, BASE_NONE, NULL, 0,
"TS_COMMON_FRAMES", HFILL }},
{ &hf_tetra_odd_multiframe,
{ "odd-multiframe", "tetra.odd_multiframe_element",
FT_NONE, BASE_NONE, NULL, 0,
"TS_COMMON_FRAMES", HFILL }},
{ &hf_tetra_access_a_code,
{ "access-a-code", "tetra.access_a_code_element",
FT_NONE, BASE_NONE, NULL, 0,
"Default_Code_A", HFILL }},
{ &hf_tetra_extend_service,
{ "extend-service", "tetra.extend_service_element",
FT_NONE, BASE_NONE, NULL, 0,
"Extended_Services_Broadcast", HFILL }},
{ &hf_tetra_la,
{ "la", "tetra.la",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_subscriber_class,
{ "subscriber-class", "tetra.subscriber_class",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_registriation,
{ "registriation", "tetra.registriation",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_de_registration,
{ "de-registration", "tetra.de_registration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_priority_cell,
{ "priority-cell", "tetra.priority_cell",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_minimum_mode_service,
{ "minimum-mode-service", "tetra.minimum_mode_service",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_migration,
{ "migration", "tetra.migration",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_system_wide_service,
{ "system-wide-service", "tetra.system_wide_service",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_tetra_voice_service,
{ "tetra-voice-service", "tetra.tetra_voice_service",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_circuit_mode_data_service,
{ "circuit-mode-data-service", "tetra.circuit_mode_data_service",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_reserved_01,
{ "reserved", "tetra.reserved",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_sndcp_service,
{ "sndcp-service", "tetra.sndcp_service",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_air_interface_encryption,
{ "air-interface-encryption", "tetra.air_interface_encryption",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_advanced_link_support,
{ "advanced-link-support", "tetra.advanced_link_support",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_frame1,
{ "frame1", "tetra.frame1",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame2,
{ "frame2", "tetra.frame2",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame3,
{ "frame3", "tetra.frame3",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame4,
{ "frame4", "tetra.frame4",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame5,
{ "frame5", "tetra.frame5",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame6,
{ "frame6", "tetra.frame6",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame7,
{ "frame7", "tetra.frame7",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame8,
{ "frame8", "tetra.frame8",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame9,
{ "frame9", "tetra.frame9",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame10,
{ "frame10", "tetra.frame10",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame11,
{ "frame11", "tetra.frame11",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame12,
{ "frame12", "tetra.frame12",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame13,
{ "frame13", "tetra.frame13",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame14,
{ "frame14", "tetra.frame14",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame15,
{ "frame15", "tetra.frame15",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame16,
{ "frame16", "tetra.frame16",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame17,
{ "frame17", "tetra.frame17",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_frame18,
{ "frame18", "tetra.frame18",
FT_UINT32, BASE_DEC, VALS(tetra_FRAME_vals), 0,
"FRAME", HFILL }},
{ &hf_tetra_imm,
{ "imm", "tetra.imm",
FT_UINT32, BASE_DEC, VALS(tetra_IMM_vals), 0,
NULL, HFILL }},
{ &hf_tetra_wt,
{ "wt", "tetra.wt",
FT_UINT32, BASE_DEC, VALS(tetra_WT_vals), 0,
NULL, HFILL }},
{ &hf_tetra_nu,
{ "nu", "tetra.nu",
FT_UINT32, BASE_DEC, VALS(tetra_NU_vals), 0,
NULL, HFILL }},
{ &hf_tetra_frame_len_factor,
{ "frame-len-factor", "tetra.frame_len_factor",
FT_UINT32, BASE_DEC, VALS(tetra_Frame_Len_Factor_vals), 0,
NULL, HFILL }},
{ &hf_tetra_timeslot_pointer,
{ "timeslot-pointer", "tetra.timeslot_pointer",
FT_UINT32, BASE_DEC, VALS(tetra_Timeslot_Pointer_vals), 0,
NULL, HFILL }},
{ &hf_tetra_min_pdu_priority,
{ "min-pdu-priority", "tetra.min_pdu_priority",
FT_UINT32, BASE_DEC, VALS(tetra_Min_Pdu_Priority_vals), 0,
NULL, HFILL }},
{ &hf_tetra_security_information,
{ "security-information", "tetra.security_information",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_tetra_sds_tl_addressing_method,
{ "sds-tl-addressing-method", "tetra.sds_tl_addressing_method",
FT_UINT32, BASE_DEC, VALS(tetra_SDS_TL_Addressing_Method_vals), 0,
NULL, HFILL }},
{ &hf_tetra_gck_supported,
{ "gck-supported", "tetra.gck_supported",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_section,
{ "section", "tetra.section",
FT_UINT32, BASE_DEC, VALS(tetra_T_section_vals), 0,
NULL, HFILL }},
{ &hf_tetra_present_1,
{ "present-1", "tetra.present_1_element",
FT_NONE, BASE_NONE, NULL, 0,
"PRESENT1", HFILL }},
{ &hf_tetra_present_2,
{ "present-2", "tetra.present_2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_tetra_present_3,
{ "present-3", "tetra.present_3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_tetra_present_4,
{ "present-4", "tetra.present_4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_tetra_data_priority_supported,
{ "data-priority-supported", "tetra.data_priority_supported",
FT_UINT32, BASE_DEC, VALS(tetra_Data_Priority_Supported_vals), 0,
NULL, HFILL }},
{ &hf_tetra_reserved_02,
{ "reserved", "tetra.reserved",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_section_2_information,
{ "section-2-information", "tetra.section_2_information",
FT_UINT32, BASE_DEC, VALS(tetra_Section_Information_vals), 0,
"Section_Information", HFILL }},
{ &hf_tetra_section_3_information,
{ "section-3-information", "tetra.section_3_information",
FT_UINT32, BASE_DEC, VALS(tetra_Section_Information_vals), 0,
"Section_Information", HFILL }},
{ &hf_tetra_section_4_information,
{ "section-4-information", "tetra.section_4_information",
FT_UINT32, BASE_DEC, VALS(tetra_Section_Information_vals), 0,
"Section_Information", HFILL }},
{ &hf_tetra_pdu_type_01,
{ "pdu-type", "tetra.pdu_type",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_fill_bit_indication,
{ "fill-bit-indication", "tetra.fill_bit_indication",
FT_UINT32, BASE_DEC, VALS(tetra_Fill_Bit_Indication_vals), 0,
NULL, HFILL }},
{ &hf_tetra_encrypted_flag,
{ "encrypted-flag", "tetra.encrypted_flag",
FT_UINT32, BASE_DEC, VALS(tetra_Encrypted_Flag_vals), 0,
NULL, HFILL }},
{ &hf_tetra_address,
{ "address", "tetra.address",
FT_UINT32, BASE_DEC, VALS(tetra_Address_vals), 0,
NULL, HFILL }},
{ &hf_tetra_data,
{ "data", "tetra.data",
FT_UINT32, BASE_DEC, VALS(tetra_T_data_vals), 0,
NULL, HFILL }},
{ &hf_tetra_sdu1,
{ "sdu1", "tetra.sdu1",
FT_UINT32, BASE_DEC, VALS(tetra_U_LLC_PDU_vals), 0,
"U_LLC_PDU", HFILL }},
{ &hf_tetra_sdu2,
{ "sdu2", "tetra.sdu2_element",
FT_NONE, BASE_NONE, NULL, 0,
"ComplexSDU", HFILL }},
{ &hf_tetra_ssi,
{ "ssi", "tetra.ssi",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_eventLabel,
{ "eventLabel", "tetra.eventLabel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_ussi,
{ "ussi", "tetra.ussi",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_smi,
{ "smi", "tetra.smi",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_bl_adata,
{ "bl-adata", "tetra.bl_adata_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_ADATA", HFILL }},
{ &hf_tetra_bl_data,
{ "bl-data", "tetra.bl_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_DATA", HFILL }},
{ &hf_tetra_bl_udata,
{ "bl-udata", "tetra.bl_udata",
FT_UINT32, BASE_DEC, VALS(tetra_U_MLE_PDU_vals), 0,
"U_MLE_PDU", HFILL }},
{ &hf_tetra_bl_ack,
{ "bl-ack", "tetra.bl_ack_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_ACK", HFILL }},
{ &hf_tetra_bl_adata_fcs,
{ "bl-adata-fcs", "tetra.bl_adata_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_ADATA_FCS", HFILL }},
{ &hf_tetra_bl_data_fcs,
{ "bl-data-fcs", "tetra.bl_data_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_DATA_FCS", HFILL }},
{ &hf_tetra_bl_udata_fcs,
{ "bl-udata-fcs", "tetra.bl_udata_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_MLE_PDU_FCS", HFILL }},
{ &hf_tetra_bl_ack_fcs,
{ "bl-ack-fcs", "tetra.bl_ack_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"U_BL_ACK_FCS", HFILL }},
{ &hf_tetra_al_setup,
{ "al-setup", "tetra.al_setup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_al_data,
{ "al-data", "tetra.al_data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_al_udata,
{ "al-udata", "tetra.al_udata_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_al_ack,
{ "al-ack", "tetra.al_ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_al_reconnect,
{ "al-reconnect", "tetra.al_reconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserve1,
{ "reserve1", "tetra.reserve1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserve2,
{ "reserve2", "tetra.reserve2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_al_disc,
{ "al-disc", "tetra.al_disc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_nr,
{ "nr", "tetra.nr",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_tl_sdu,
{ "tl-sdu", "tetra.tl_sdu",
FT_UINT32, BASE_DEC, VALS(tetra_U_MLE_PDU_vals), 0,
"U_MLE_PDU", HFILL }},
{ &hf_tetra_fcs,
{ "fcs", "tetra.fcs",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_tetra_u_mle_pdu,
{ "u-mle-pdu", "tetra.u_mle_pdu",
FT_UINT32, BASE_DEC, VALS(tetra_U_MLE_PDU_vals), 0,
NULL, HFILL }},
{ &hf_tetra_ns,
{ "ns", "tetra.ns",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_u_mle_reserved1,
{ "u-mle-reserved1", "tetra.u_mle_reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_mm,
{ "mm", "tetra.mm",
FT_UINT32, BASE_DEC, VALS(tetra_U_MM_PDU_vals), 0,
"U_MM_PDU", HFILL }},
{ &hf_tetra_cmce,
{ "cmce", "tetra.cmce",
FT_UINT32, BASE_DEC, VALS(tetra_U_CMCE_PDU_vals), 0,
"U_CMCE_PDU", HFILL }},
{ &hf_tetra_u_mle_reserved2,
{ "u-mle-reserved2", "tetra.u_mle_reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_sndcp,
{ "sndcp", "tetra.sndcp_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_mle,
{ "mle", "tetra.mle",
FT_UINT32, BASE_DEC, VALS(tetra_UMLE_PDU_vals), 0,
"UMLE_PDU", HFILL }},
{ &hf_tetra_tetra_management_entity_protocol,
{ "tetra-management-entity-protocol", "tetra.tetra_management_entity_protocol_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_mle_reserved3,
{ "u-mle-reserved3", "tetra.u_mle_reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_lengthIndicationOrCapacityRequest,
{ "lengthIndicationOrCapacityRequest", "tetra.lengthIndicationOrCapacityRequest",
FT_UINT32, BASE_DEC, VALS(tetra_T_lengthIndicationOrCapacityRequest_vals), 0,
NULL, HFILL }},
{ &hf_tetra_lengthIndication,
{ "lengthIndication", "tetra.lengthIndication",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndication_vals), 0,
NULL, HFILL }},
{ &hf_tetra_capacityRequest,
{ "capacityRequest", "tetra.capacityRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
"FRAG", HFILL }},
{ &hf_tetra_tm_sdu_01,
{ "tm-sdu", "tetra.tm_sdu",
FT_UINT32, BASE_DEC, VALS(tetra_U_LLC_PDU_vals), 0,
"U_LLC_PDU", HFILL }},
{ &hf_tetra_frag,
{ "frag", "tetra.frag",
FT_UINT32, BASE_DEC, VALS(tetra_Frag1_vals), 0,
"Frag1", HFILL }},
{ &hf_tetra_reservation_requirement,
{ "reservation-requirement", "tetra.reservation_requirement",
FT_UINT32, BASE_DEC, VALS(tetra_SLOT_APPLY_vals), 0,
"SLOT_APPLY", HFILL }},
{ &hf_tetra_lengthIndicationOrCapacityRequest_01,
{ "lengthIndicationOrCapacityRequest", "tetra.lengthIndicationOrCapacityRequest",
FT_UINT32, BASE_DEC, VALS(tetra_T_lengthIndicationOrCapacityRequest_01_vals), 0,
"T_lengthIndicationOrCapacityRequest_01", HFILL }},
{ &hf_tetra_lengthIndication_01,
{ "lengthIndication", "tetra.lengthIndication",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndicationMacData_vals), 0,
"LengthIndicationMacData", HFILL }},
{ &hf_tetra_capacityRequest_01,
{ "capacityRequest", "tetra.capacityRequest_element",
FT_NONE, BASE_NONE, NULL, 0,
"FRAG6", HFILL }},
{ &hf_tetra_sub_type,
{ "sub-type", "tetra.sub_type",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_tm_sdu_02,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_264", HFILL }},
{ &hf_tetra_tm_sdu_03,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_120", HFILL }},
{ &hf_tetra_lengthInd_ReservationReq,
{ "lengthInd-ReservationReq", "tetra.lengthInd_ReservationReq",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndOrReservationReq_vals), 0,
"LengthIndOrReservationReq", HFILL }},
{ &hf_tetra_tm_sdu_04,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_258", HFILL }},
{ &hf_tetra_pdu_subtype,
{ "pdu-subtype", "tetra.pdu_subtype",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_tm_sdu_05,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_114", HFILL }},
{ &hf_tetra_lengthInd_ReservationReq_01,
{ "lengthInd-ReservationReq", "tetra.lengthInd_ReservationReq",
FT_UINT32, BASE_DEC, VALS(tetra_T_lengthInd_ReservationReq_vals), 0,
NULL, HFILL }},
{ &hf_tetra_lengthInd,
{ "lengthInd", "tetra.lengthInd",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndMacHu_vals), 0,
"LengthIndMacHu", HFILL }},
{ &hf_tetra_tm_sdu_06,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_85", HFILL }},
{ &hf_tetra_position_of_grant,
{ "position-of-grant", "tetra.position_of_grant",
FT_UINT32, BASE_DEC, VALS(tetra_Position_Of_Grant_vals), 0,
NULL, HFILL }},
{ &hf_tetra_lengthIndication_02,
{ "lengthIndication", "tetra.lengthIndication",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndicationMacEndDl_vals), 0,
"LengthIndicationMacEndDl", HFILL }},
{ &hf_tetra_slot_granting,
{ "slot-granting", "tetra.slot_granting",
FT_UINT32, BASE_DEC, VALS(tetra_T_slot_granting_vals), 0,
"T_slot_granting", HFILL }},
{ &hf_tetra_none,
{ "none", "tetra.none_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_slot_granting_param,
{ "slot-granting-param", "tetra.slot_granting_param_element",
FT_NONE, BASE_NONE, NULL, 0,
"SlotGranting", HFILL }},
{ &hf_tetra_channel_allocation,
{ "channel-allocation", "tetra.channel_allocation",
FT_UINT32, BASE_DEC, VALS(tetra_T_channel_allocation_vals), 0,
NULL, HFILL }},
{ &hf_tetra_channel_allocation_element,
{ "channel-allocation-element", "tetra.channel_allocation_element_element",
FT_NONE, BASE_NONE, NULL, 0,
"ChannelAllocation", HFILL }},
{ &hf_tetra_tm_sdu_07,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_255", HFILL }},
{ &hf_tetra_capacity_allocation,
{ "capacity-allocation", "tetra.capacity_allocation",
FT_UINT32, BASE_DEC, VALS(tetra_Capacity_Allocation_vals), 0,
NULL, HFILL }},
{ &hf_tetra_granting_delay,
{ "granting-delay", "tetra.granting_delay",
FT_UINT32, BASE_DEC, VALS(tetra_Granting_delay_vals), 0,
NULL, HFILL }},
{ &hf_tetra_allocation_type,
{ "allocation-type", "tetra.allocation_type",
FT_UINT32, BASE_DEC, VALS(tetra_T_allocation_type_vals), 0,
NULL, HFILL }},
{ &hf_tetra_timeslot_assigned,
{ "timeslot-assigned", "tetra.timeslot_assigned",
FT_UINT32, BASE_DEC, VALS(tetra_Timeslot_Assigned_vals), 0,
NULL, HFILL }},
{ &hf_tetra_up_down_assigned,
{ "up-down-assigned", "tetra.up_down_assigned",
FT_UINT32, BASE_DEC, VALS(tetra_T_up_down_assigned_vals), 0,
NULL, HFILL }},
{ &hf_tetra_clch_permission,
{ "clch-permission", "tetra.clch_permission",
FT_UINT32, BASE_DEC, VALS(tetra_CLCH_permission_vals), 0,
NULL, HFILL }},
{ &hf_tetra_cell_change,
{ "cell-change", "tetra.cell_change",
FT_UINT32, BASE_DEC, VALS(tetra_Cell_change_flag_vals), 0,
"Cell_change_flag", HFILL }},
{ &hf_tetra_carrier_number,
{ "carrier-number", "tetra.carrier_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_tetra_extend_carrier_flag,
{ "extend-carrier-flag", "tetra.extend_carrier_flag",
FT_UINT32, BASE_DEC, VALS(tetra_T_extend_carrier_flag_vals), 0,
NULL, HFILL }},
{ &hf_tetra_extended,
{ "extended", "tetra.extended_element",
FT_NONE, BASE_NONE, NULL, 0,
"Extended_carrier_flag", HFILL }},
{ &hf_tetra_monitoring_pattern,
{ "monitoring-pattern", "tetra.monitoring_pattern",
FT_UINT32, BASE_DEC, VALS(tetra_T_monitoring_pattern_vals), 0,
NULL, HFILL }},
{ &hf_tetra_one,
{ "one", "tetra.one",
FT_UINT32, BASE_DEC, VALS(tetra_Monitoring_pattern_vals), 0,
"Monitoring_pattern", HFILL }},
{ &hf_tetra_none1,
{ "none1", "tetra.none1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_none2,
{ "none2", "tetra.none2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_none3,
{ "none3", "tetra.none3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_offset_01,
{ "offset", "tetra.offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_reverse_operation_01,
{ "reverse-operation", "tetra.reverse_operation",
FT_UINT32, BASE_DEC, VALS(tetra_T_reverse_operation_vals), 0,
NULL, HFILL }},
{ &hf_tetra_pdu_type_02,
{ "pdu-type", "tetra.pdu_type",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_fill_bit_ind,
{ "fill-bit-ind", "tetra.fill_bit_ind",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_position_of_grant_01,
{ "position-of-grant", "tetra.position_of_grant",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_slot_granting_01,
{ "slot-granting", "tetra.slot_granting",
FT_UINT32, BASE_DEC, VALS(tetra_T_slot_granting_01_vals), 0,
"T_slot_granting_01", HFILL }},
{ &hf_tetra_channel_allocation_01,
{ "channel-allocation", "tetra.channel_allocation",
FT_UINT32, BASE_DEC, VALS(tetra_T_channel_allocation_01_vals), 0,
"T_channel_allocation_01", HFILL }},
{ &hf_tetra_tm_sdu_08,
{ "tm-sdu", "tetra.tm_sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_111", HFILL }},
{ &hf_tetra_encryption_mode,
{ "encryption-mode", "tetra.encryption_mode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_access_ack,
{ "access-ack", "tetra.access_ack",
FT_UINT32, BASE_DEC, VALS(tetra_T_access_ack_vals), 0,
NULL, HFILL }},
{ &hf_tetra_lengthIndication_03,
{ "lengthIndication", "tetra.lengthIndication",
FT_UINT32, BASE_DEC, VALS(tetra_LengthIndicationMacResource_vals), 0,
"LengthIndicationMacResource", HFILL }},
{ &hf_tetra_address_01,
{ "address", "tetra.address",
FT_UINT32, BASE_DEC, VALS(tetra_AddressMacResource_vals), 0,
"AddressMacResource", HFILL }},
{ &hf_tetra_power_control,
{ "power-control", "tetra.power_control",
FT_UINT32, BASE_DEC, VALS(tetra_T_power_control_vals), 0,
NULL, HFILL }},
{ &hf_tetra_powerParameters,
{ "powerParameters", "tetra.powerParameters",
FT_UINT32, BASE_DEC, VALS(tetra_PowerControl_vals), 0,
"PowerControl", HFILL }},
{ &hf_tetra_slot_granting_02,
{ "slot-granting", "tetra.slot_granting",
FT_UINT32, BASE_DEC, VALS(tetra_T_slot_granting_02_vals), 0,
"T_slot_granting_02", HFILL }},
{ &hf_tetra_channel_allocation_02,
{ "channel-allocation", "tetra.channel_allocation",
FT_UINT32, BASE_DEC, VALS(tetra_T_channel_allocation_02_vals), 0,
"T_channel_allocation_02", HFILL }},
{ &hf_tetra_tm_sdu_09,
{ "tm-sdu", "tetra.tm_sdu",
FT_UINT32, BASE_DEC, VALS(tetra_D_LLC_PDU_vals), 0,
"D_LLC_PDU", HFILL }},
{ &hf_tetra_null_pdu,
{ "null-pdu", "tetra.null_pdu_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_ssi_01,
{ "ssi", "tetra.ssi_element",
FT_NONE, BASE_NONE, NULL, 0,
"SSI_NEED", HFILL }},
{ &hf_tetra_eventLabel_01,
{ "eventLabel", "tetra.eventLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
"EVENT_NEED", HFILL }},
{ &hf_tetra_ussi_01,
{ "ussi", "tetra.ussi_element",
FT_NONE, BASE_NONE, NULL, 0,
"USSI_NEED", HFILL }},
{ &hf_tetra_smi_01,
{ "smi", "tetra.smi_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMI_NEED", HFILL }},
{ &hf_tetra_ssi_eventLabel,
{ "ssi-eventLabel", "tetra.ssi_eventLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
"SSI_EVENT_NEED", HFILL }},
{ &hf_tetra_ssi_usage_maker,
{ "ssi-usage-maker", "tetra.ssi_usage_maker_element",
FT_NONE, BASE_NONE, NULL, 0,
"SSI_USAGE_NEED", HFILL }},
{ &hf_tetra_smi_eventLabel,
{ "smi-eventLabel", "tetra.smi_eventLabel_element",
FT_NONE, BASE_NONE, NULL, 0,
"SMI_EVENT_NEED", HFILL }},
{ &hf_tetra_other,
{ "other", "tetra.other_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTHER_DATA", HFILL }},
{ &hf_tetra_eventlabel,
{ "eventlabel", "tetra.eventlabel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_ventlabel,
{ "ventlabel", "tetra.ventlabel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_usage_maker,
{ "usage-maker", "tetra.usage_maker",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_smi_eventlabel,
{ "smi-eventlabel", "tetra.smi_eventlabel",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_34", HFILL }},
{ &hf_tetra_broadcast_channel,
{ "broadcast-channel", "tetra.broadcast_channel",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_access_code,
{ "access-code", "tetra.access_code",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_imm_01,
{ "imm", "tetra.imm",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_wt_01,
{ "wt", "tetra.wt",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_nu_01,
{ "nu", "tetra.nu",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_frame_len_factor_01,
{ "frame-len-factor", "tetra.frame_len_factor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_timeslot_pointer_01,
{ "timeslot-pointer", "tetra.timeslot_pointer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_min_priority,
{ "min-priority", "tetra.min_priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_optional_field,
{ "optional-field", "tetra.optional_field",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_field_vals), 0,
NULL, HFILL }},
{ &hf_tetra_class_bitmap,
{ "class-bitmap", "tetra.class_bitmap",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_gssi,
{ "gssi", "tetra.gssi",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_33554431", HFILL }},
{ &hf_tetra_reserved_03,
{ "reserved", "tetra.reserved_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_filler_bits,
{ "filler-bits", "tetra.filler_bits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_bl_adata_01,
{ "bl-adata", "tetra.bl_adata_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_ADATA", HFILL }},
{ &hf_tetra_bl_data_01,
{ "bl-data", "tetra.bl_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_DATA", HFILL }},
{ &hf_tetra_bl_udata_01,
{ "bl-udata", "tetra.bl_udata",
FT_UINT32, BASE_DEC, VALS(tetra_D_MLE_PDU_vals), 0,
"D_MLE_PDU", HFILL }},
{ &hf_tetra_bl_ack_01,
{ "bl-ack", "tetra.bl_ack_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_ACK", HFILL }},
{ &hf_tetra_bl_adata_fcs_01,
{ "bl-adata-fcs", "tetra.bl_adata_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_ADATA_FCS", HFILL }},
{ &hf_tetra_bl_data_fcs_01,
{ "bl-data-fcs", "tetra.bl_data_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_DATA_FCS", HFILL }},
{ &hf_tetra_bl_udata_fcs_01,
{ "bl-udata-fcs", "tetra.bl_udata_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_MLE_PDU_FCS", HFILL }},
{ &hf_tetra_bl_ack_fcs_01,
{ "bl-ack-fcs", "tetra.bl_ack_fcs_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_BL_ACK_FCS", HFILL }},
{ &hf_tetra_tl_sdu_01,
{ "tl-sdu", "tetra.tl_sdu",
FT_UINT32, BASE_DEC, VALS(tetra_D_MLE_PDU_vals), 0,
"D_MLE_PDU", HFILL }},
{ &hf_tetra_d_mle_pdu,
{ "d-mle-pdu", "tetra.d_mle_pdu",
FT_UINT32, BASE_DEC, VALS(tetra_D_MLE_PDU_vals), 0,
NULL, HFILL }},
{ &hf_tetra_mm_01,
{ "mm", "tetra.mm",
FT_UINT32, BASE_DEC, VALS(tetra_D_MM_PDU_vals), 0,
"D_MM_PDU", HFILL }},
{ &hf_tetra_cmce_01,
{ "cmce", "tetra.cmce",
FT_UINT32, BASE_DEC, VALS(tetra_D_CMCE_PDU_vals), 0,
"D_CMCE_PDU", HFILL }},
{ &hf_tetra_mle_01,
{ "mle", "tetra.mle",
FT_UINT32, BASE_DEC, VALS(tetra_DMLE_PDU_vals), 0,
"DMLE_PDU", HFILL }},
{ &hf_tetra_u_prepare,
{ "u-prepare", "tetra.u_prepare_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved1,
{ "umle-reserved1", "tetra.umle_reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved2,
{ "umle-reserved2", "tetra.umle_reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved3,
{ "umle-reserved3", "tetra.umle_reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_restore,
{ "u-restore", "tetra.u_restore_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved4,
{ "umle-reserved4", "tetra.umle_reserved4_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved5,
{ "umle-reserved5", "tetra.umle_reserved5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_umle_reserved6,
{ "umle-reserved6", "tetra.umle_reserved6_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_new_cell,
{ "d-new-cell", "tetra.d_new_cell_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_prepare_fail,
{ "d-prepare-fail", "tetra.d_prepare_fail_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_nwrk_broadcast,
{ "d-nwrk-broadcast", "tetra.d_nwrk_broadcast_element",
FT_NONE, BASE_NONE, NULL, 0,
"D_NWRK_BRDADCAST", HFILL }},
{ &hf_tetra_dmle_reserved1,
{ "dmle-reserved1", "tetra.dmle_reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_restore_ack,
{ "d-restore-ack", "tetra.d_restore_ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_restore_fail,
{ "d-restore-fail", "tetra.d_restore_fail_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_dmle_reserved2,
{ "dmle-reserved2", "tetra.dmle_reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_dmle_reserved3,
{ "dmle-reserved3", "tetra.dmle_reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_optional_elements,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_vals), 0,
NULL, HFILL }},
{ &hf_tetra_no_type2,
{ "no-type2", "tetra.no_type2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_type2_parameters,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_cell_number,
{ "cell-number", "tetra.cell_number",
FT_UINT32, BASE_DEC, VALS(tetra_T_cell_number_vals), 0,
NULL, HFILL }},
{ &hf_tetra_cell_number_01,
{ "cell-number", "tetra.cell_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_sdu,
{ "sdu", "tetra.sdu",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_tetra_optional_elements_01,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_01_vals), 0,
"T_optional_elements_01", HFILL }},
{ &hf_tetra_type2_parameters_01,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_01", HFILL }},
{ &hf_tetra_mcc_01,
{ "mcc", "tetra.mcc",
FT_UINT32, BASE_DEC, VALS(tetra_T_mcc_vals), 0,
NULL, HFILL }},
{ &hf_tetra_mnc_01,
{ "mnc", "tetra.mnc",
FT_UINT32, BASE_DEC, VALS(tetra_T_mnc_vals), 0,
NULL, HFILL }},
{ &hf_tetra_la_01,
{ "la", "tetra.la",
FT_UINT32, BASE_DEC, VALS(tetra_T_la_vals), 0,
NULL, HFILL }},
{ &hf_tetra_channel_command_valid,
{ "channel-command-valid", "tetra.channel_command_valid",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_optional_elements_02,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_02_vals), 0,
"T_optional_elements_02", HFILL }},
{ &hf_tetra_fail_cause,
{ "fail-cause", "tetra.fail_cause",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_optional_elements_03,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_03_vals), 0,
"T_optional_elements_03", HFILL }},
{ &hf_tetra_cell_re_select_parameters,
{ "cell-re-select-parameters", "tetra.cell_re_select_parameters",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_optional_elements_04,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_04_vals), 0,
"T_optional_elements_04", HFILL }},
{ &hf_tetra_type2_parameters_02,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_02", HFILL }},
{ &hf_tetra_tetra_network_time,
{ "tetra-network-time", "tetra.tetra_network_time",
FT_UINT32, BASE_DEC, VALS(tetra_T_tetra_network_time_vals), 0,
NULL, HFILL }},
{ &hf_tetra_tetra_network_time_01,
{ "tetra-network-time", "tetra.tetra_network_time_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_number_of_neighbour_cells,
{ "number-of-neighbour-cells", "tetra.number_of_neighbour_cells",
FT_UINT32, BASE_DEC, VALS(tetra_T_number_of_neighbour_cells_vals), 0,
NULL, HFILL }},
{ &hf_tetra_number_of_neighbour_cells_01,
{ "number-of-neighbour-cells", "tetra.number_of_neighbour_cells",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_network_time,
{ "network-time", "tetra.network_time",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_local_time_offset_sign,
{ "local-time-offset-sign", "tetra.local_time_offset_sign",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_local_time_offset,
{ "local-time-offset", "tetra.local_time_offset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_year,
{ "year", "tetra.year",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_reserved_04,
{ "reserved", "tetra.reserved",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Authentication,
{ "u-Authentication", "tetra.u_Authentication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Itsi_Detach,
{ "u-Itsi-Detach", "tetra.u_Itsi_Detach_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Location_Update_Demand,
{ "u-Location-Update-Demand", "tetra.u_Location_Update_Demand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_Status,
{ "u-MM-Status", "tetra.u_MM_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved1,
{ "u-MM-reserved1", "tetra.u_MM_reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_WK,
{ "u-WK", "tetra.u_WK_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved3,
{ "u-MM-reserved3", "tetra.u_MM_reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Attach_Detach_Group_Identity,
{ "u-Attach-Detach-Group-Identity", "tetra.u_Attach_Detach_Group_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Attach_Detach_Group_Identity_Ack,
{ "u-Attach-Detach-Group-Identity-Ack", "tetra.u_Attach_Detach_Group_Identity_Ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_TEI_Provide,
{ "u-TEI-Provide", "tetra.u_TEI_Provide_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved6,
{ "u-MM-reserved6", "tetra.u_MM_reserved6_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Disabled_Status,
{ "u-Disabled-Status", "tetra.u_Disabled_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved7,
{ "u-MM-reserved7", "tetra.u_MM_reserved7_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved8,
{ "u-MM-reserved8", "tetra.u_MM_reserved8_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_reserved9,
{ "u-MM-reserved9", "tetra.u_MM_reserved9_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_MM_Function_Not_Support,
{ "u-MM-Function-Not-Support", "tetra.u_MM_Function_Not_Support_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Otar,
{ "d-Otar", "tetra.d_Otar_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Authentication,
{ "d-Authentication", "tetra.d_Authentication_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Authentication_Reject,
{ "d-Authentication-Reject", "tetra.d_Authentication_Reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Disable,
{ "d-Disable", "tetra.d_Disable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Enable,
{ "d-Enable", "tetra.d_Enable_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Location_Update_Accept,
{ "d-Location-Update-Accept", "tetra.d_Location_Update_Accept_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Location_Update_Command,
{ "d-Location-Update-Command", "tetra.d_Location_Update_Command_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Location_Update_Reject,
{ "d-Location-Update-Reject", "tetra.d_Location_Update_Reject_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_MM_reserved2,
{ "d-MM-reserved2", "tetra.d_MM_reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Location_Update_Proceeding,
{ "d-Location-Update-Proceeding", "tetra.d_Location_Update_Proceeding_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Attach_Detach_Group_Identity,
{ "d-Attach-Detach-Group-Identity", "tetra.d_Attach_Detach_Group_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Attach_Detach_Group_Identity_Ack,
{ "d-Attach-Detach-Group-Identity-Ack", "tetra.d_Attach_Detach_Group_Identity_Ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_MM_Status,
{ "d-MM-Status", "tetra.d_MM_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_MM_reserved5,
{ "d-MM-reserved5", "tetra.d_MM_reserved5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_MM_reserved6,
{ "d-MM-reserved6", "tetra.d_MM_reserved6_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_MM_Function_Not_Support,
{ "d-MM-Function-Not-Support", "tetra.d_MM_Function_Not_Support_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_attach_detach_identifiet,
{ "attach-detach-identifiet", "tetra.attach_detach_identifiet",
FT_UINT32, BASE_DEC, VALS(tetra_T_attach_detach_identifiet_vals), 0,
NULL, HFILL }},
{ &hf_tetra_attach,
{ "attach", "tetra.attach_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_lifetime,
{ "lifetime", "tetra.lifetime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_class_of_usage,
{ "class-of-usage", "tetra.class_of_usage",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_detach,
{ "detach", "tetra.detach_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_detach_downlike,
{ "detach-downlike", "tetra.detach_downlike",
FT_UINT32, BASE_DEC, VALS(tetra_T_detach_downlike_vals), 0,
NULL, HFILL }},
{ &hf_tetra_address_type,
{ "address-type", "tetra.address_type",
FT_UINT32, BASE_DEC, VALS(tetra_T_address_type_vals), 0,
NULL, HFILL }},
{ &hf_tetra_gssi_01,
{ "gssi", "tetra.gssi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_tetra_gssi_extension,
{ "gssi-extension", "tetra.gssi_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_extension,
{ "extension", "tetra.extension",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_tetra_vgssi,
{ "vgssi", "tetra.vgssi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_tetra_attach_detach_identifiet_01,
{ "attach-detach-identifiet", "tetra.attach_detach_identifiet",
FT_UINT32, BASE_DEC, VALS(tetra_T_attach_detach_identifiet_01_vals), 0,
"T_attach_detach_identifiet_01", HFILL }},
{ &hf_tetra_attach_01,
{ "attach", "tetra.attach_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_attach_01", HFILL }},
{ &hf_tetra_detach_01,
{ "detach", "tetra.detach_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_detach_01", HFILL }},
{ &hf_tetra_detach_uplike,
{ "detach-uplike", "tetra.detach_uplike",
FT_UINT32, BASE_DEC, VALS(tetra_T_detach_uplike_vals), 0,
NULL, HFILL }},
{ &hf_tetra_address_type_01,
{ "address-type", "tetra.address_type",
FT_UINT32, BASE_DEC, VALS(tetra_T_address_type_01_vals), 0,
"T_address_type_01", HFILL }},
{ &hf_tetra_gssi_extension_01,
{ "gssi-extension", "tetra.gssi_extension_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_gssi_extension_01", HFILL }},
{ &hf_tetra_location_update_type,
{ "location-update-type", "tetra.location_update_type",
FT_UINT32, BASE_DEC, VALS(tetra_UPDATE_TYPE_vals), 0,
"UPDATE_TYPE", HFILL }},
{ &hf_tetra_optional_elements_05,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_05_vals), 0,
"T_optional_elements_05", HFILL }},
{ &hf_tetra_type2_parameters_03,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_03", HFILL }},
{ &hf_tetra_ssi_02,
{ "ssi", "tetra.ssi",
FT_UINT32, BASE_DEC, VALS(tetra_T_ssi_vals), 0,
NULL, HFILL }},
{ &hf_tetra_ssi_03,
{ "ssi", "tetra.ssi",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_tetra_address_extension,
{ "address-extension", "tetra.address_extension",
FT_UINT32, BASE_DEC, VALS(tetra_T_address_extension_vals), 0,
NULL, HFILL }},
{ &hf_tetra_address_extension_01,
{ "address-extension", "tetra.address_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_tetra_subscriber_class_01,
{ "subscriber-class", "tetra.subscriber_class",
FT_UINT32, BASE_DEC, VALS(tetra_T_subscriber_class_vals), 0,
NULL, HFILL }},
{ &hf_tetra_energy_saving_mode,
{ "energy-saving-mode", "tetra.energy_saving_mode",
FT_UINT32, BASE_DEC, VALS(tetra_T_energy_saving_mode_vals), 0,
NULL, HFILL }},
{ &hf_tetra_energy_saving_mode_01,
{ "energy-saving-mode", "tetra.energy_saving_mode",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_scch_info,
{ "scch-info", "tetra.scch_info",
FT_UINT32, BASE_DEC, VALS(tetra_T_scch_info_vals), 0,
NULL, HFILL }},
{ &hf_tetra_scch_info_01,
{ "scch-info", "tetra.scch_info",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_type3,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_vals), 0,
NULL, HFILL }},
{ &hf_tetra_no_type3,
{ "no-type3", "tetra.no_type3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_type3_elements,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_type2_existance,
{ "type2-existance", "tetra.type2_existance",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_type3_identifier,
{ "type3-identifier", "tetra.type3_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_TYPE3_IDENTIFIER_vals), 0,
NULL, HFILL }},
{ &hf_tetra_new_ra,
{ "new-ra", "tetra.new_ra",
FT_UINT32, BASE_DEC, VALS(tetra_T_new_ra_vals), 0,
NULL, HFILL }},
{ &hf_tetra_new_ra_01,
{ "new-ra", "tetra.new_ra",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_group_identity_location_accept,
{ "group-identity-location-accept", "tetra.group_identity_location_accept",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_identity_location_accept_vals), 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_location_accept_01,
{ "group-identity-location-accept", "tetra.group_identity_location_accept",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_group_predefined_lifetime,
{ "group-predefined-lifetime", "tetra.group_predefined_lifetime",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_predefined_lifetime_vals), 0,
NULL, HFILL }},
{ &hf_tetra_group_predefined_lifetime_01,
{ "group-predefined-lifetime", "tetra.group_predefined_lifetime",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_group_identity_downlink,
{ "group-identity-downlink", "tetra.group_identity_downlink",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_identity_downlink_vals), 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_downlink_01,
{ "group-identity-downlink", "tetra.group_identity_downlink",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_proprietary,
{ "proprietary", "tetra.proprietary",
FT_UINT32, BASE_DEC, VALS(tetra_T_proprietary_vals), 0,
NULL, HFILL }},
{ &hf_tetra_proprietary_01,
{ "proprietary", "tetra.proprietary",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_reject_cause,
{ "reject-cause", "tetra.reject_cause",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_tetra_cipher_control,
{ "cipher-control", "tetra.cipher_control",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_status_uplink,
{ "status-uplink", "tetra.status_uplink",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_scanning_on_off,
{ "scanning-on-off", "tetra.scanning_on_off",
FT_UINT32, BASE_DEC, VALS(tetra_T_scanning_on_off_vals), 0,
NULL, HFILL }},
{ &hf_tetra_status_downlink,
{ "status-downlink", "tetra.status_downlink",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_u_Alert,
{ "u-Alert", "tetra.u_Alert_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserved1,
{ "reserved1", "tetra.reserved1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Connect,
{ "u-Connect", "tetra.u_Connect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserved2,
{ "reserved2", "tetra.reserved2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Disconnect,
{ "u-Disconnect", "tetra.u_Disconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Info,
{ "u-Info", "tetra.u_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Release,
{ "u-Release", "tetra.u_Release_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Setup,
{ "u-Setup", "tetra.u_Setup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Status,
{ "u-Status", "tetra.u_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Tx_Ceased,
{ "u-Tx-Ceased", "tetra.u_Tx_Ceased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Tx_Demand,
{ "u-Tx-Demand", "tetra.u_Tx_Demand_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserved3,
{ "reserved3", "tetra.reserved3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserved4,
{ "reserved4", "tetra.reserved4_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_reserved5,
{ "reserved5", "tetra.reserved5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Call_Restore,
{ "u-Call-Restore", "tetra.u_Call_Restore_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_SDS_Data,
{ "u-SDS-Data", "tetra.u_SDS_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_u_Facility,
{ "u-Facility", "tetra.u_Facility_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_call_identifier,
{ "call-identifier", "tetra.call_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_disconnect_cause,
{ "disconnect-cause", "tetra.disconnect_cause",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_tetra_area_selection,
{ "area-selection", "tetra.area_selection",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_called_party_type_identifier,
{ "called-party-type-identifier", "tetra.called_party_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_called_party_type_identifier_vals), 0,
NULL, HFILL }},
{ &hf_tetra_sna,
{ "sna", "tetra.sna",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_tetra_ssi_extension,
{ "ssi-extension", "tetra.ssi_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_tetra_short_data_type_identifier,
{ "short-data-type-identifier", "tetra.short_data_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_short_data_type_identifier_vals), 0,
"T_short_data_type_identifier", HFILL }},
{ &hf_tetra_data_1,
{ "data-1", "tetra.data_1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_data_2,
{ "data-2", "tetra.data_2",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_tetra_data_3,
{ "data-3", "tetra.data_3",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_64", HFILL }},
{ &hf_tetra_length_indicator_data_4,
{ "length-indicator-data-4", "tetra.length_indicator_data_4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4194304", HFILL }},
{ &hf_tetra_called_party_type_identifier_01,
{ "called-party-type-identifier", "tetra.called_party_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_called_party_type_identifier_01_vals), 0,
"T_called_party_type_identifier_01", HFILL }},
{ &hf_tetra_short_number_address,
{ "short-number-address", "tetra.short_number_address",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_tetra_called_ssi_called_extension,
{ "called-ssi-called-extension", "tetra.called_ssi_called_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_48", HFILL }},
{ &hf_tetra_pre_coded_status,
{ "pre-coded-status", "tetra.pre_coded_status",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_tetra_call_id,
{ "call-id", "tetra.call_id",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_poll_response,
{ "poll-response", "tetra.poll_response",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_d_Alert,
{ "d-Alert", "tetra.d_Alert_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Call_Proceeding,
{ "d-Call-Proceeding", "tetra.d_Call_Proceeding_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Connect,
{ "d-Connect", "tetra.d_Connect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Connect_Ack,
{ "d-Connect-Ack", "tetra.d_Connect_Ack_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Disconnect,
{ "d-Disconnect", "tetra.d_Disconnect_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Info,
{ "d-Info", "tetra.d_Info_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Release,
{ "d-Release", "tetra.d_Release_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Setup,
{ "d-Setup", "tetra.d_Setup_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Status,
{ "d-Status", "tetra.d_Status_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Tx_Ceased,
{ "d-Tx-Ceased", "tetra.d_Tx_Ceased_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Tx_Continue,
{ "d-Tx-Continue", "tetra.d_Tx_Continue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Tx_Granted,
{ "d-Tx-Granted", "tetra.d_Tx_Granted_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Tx_Wait,
{ "d-Tx-Wait", "tetra.d_Tx_Wait_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Tx_Interrupt,
{ "d-Tx-Interrupt", "tetra.d_Tx_Interrupt_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Call_Restore,
{ "d-Call-Restore", "tetra.d_Call_Restore_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_SDS_Data,
{ "d-SDS-Data", "tetra.d_SDS_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_d_Facility,
{ "d-Facility", "tetra.d_Facility_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_calling_party_type_identifier,
{ "calling-party-type-identifier", "tetra.calling_party_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_calling_party_type_identifier_vals), 0,
NULL, HFILL }},
{ &hf_tetra_ssi_extension_01,
{ "ssi-extension", "tetra.ssi_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_6", HFILL }},
{ &hf_tetra_short_data_type_identifier_01,
{ "short-data-type-identifier", "tetra.short_data_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_short_data_type_identifier_01_vals), 0,
"T_short_data_type_identifier_01", HFILL }},
{ &hf_tetra_data_3_01,
{ "data-3", "tetra.data_3",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_8", HFILL }},
{ &hf_tetra_calling_party_type_identifier_01,
{ "calling-party-type-identifier", "tetra.calling_party_type_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_calling_party_type_identifier_01_vals), 0,
"T_calling_party_type_identifier_01", HFILL }},
{ &hf_tetra_calling_party_address_SSI,
{ "calling-party-address-SSI", "tetra.calling_party_address_SSI",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_reset_call_time_out_timer,
{ "reset-call-time-out-timer", "tetra.reset_call_time_out_timer",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_poll_request,
{ "poll-request", "tetra.poll_request",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_transmission_request_permission,
{ "transmission-request-permission", "tetra.transmission_request_permission",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_continue,
{ "continue", "tetra.continue",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_request_to_append_LA,
{ "request-to-append-LA", "tetra.request_to_append_LA",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_cipher_control_01,
{ "cipher-control", "tetra.cipher_control",
FT_UINT32, BASE_DEC, VALS(tetra_T_cipher_control_vals), 0,
NULL, HFILL }},
{ &hf_tetra_no_cipher,
{ "no-cipher", "tetra.no_cipher_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_ciphering_parameters,
{ "ciphering-parameters", "tetra.ciphering_parameters",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_optional_elements_06,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_06_vals), 0,
"T_optional_elements_06", HFILL }},
{ &hf_tetra_type2_parameters_04,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_04", HFILL }},
{ &hf_tetra_class_of_MS,
{ "class-of-MS", "tetra.class_of_MS",
FT_UINT32, BASE_DEC, VALS(tetra_T_class_of_MS_vals), 0,
NULL, HFILL }},
{ &hf_tetra_class_of_MS_01,
{ "class-of-MS", "tetra.class_of_MS",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_energy_saving_mode_02,
{ "energy-saving-mode", "tetra.energy_saving_mode",
FT_UINT32, BASE_DEC, VALS(tetra_T_energy_saving_mode_01_vals), 0,
"T_energy_saving_mode_01", HFILL }},
{ &hf_tetra_la_information,
{ "la-information", "tetra.la_information",
FT_UINT32, BASE_DEC, VALS(tetra_T_la_information_vals), 0,
NULL, HFILL }},
{ &hf_tetra_la_information_01,
{ "la-information", "tetra.la_information",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_tetra_ssi_04,
{ "ssi", "tetra.ssi",
FT_UINT32, BASE_DEC, VALS(tetra_T_ssi_01_vals), 0,
"T_ssi_01", HFILL }},
{ &hf_tetra_address_extension_02,
{ "address-extension", "tetra.address_extension",
FT_UINT32, BASE_DEC, VALS(tetra_T_address_extension_01_vals), 0,
"T_address_extension_01", HFILL }},
{ &hf_tetra_type3_01,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_01_vals), 0,
"T_type3_01", HFILL }},
{ &hf_tetra_type3_elements_01,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type3_elements_01", HFILL }},
{ &hf_tetra_group_identity_location_demand,
{ "group-identity-location-demand", "tetra.group_identity_location_demand",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_identity_location_demand_vals), 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_location_demand_01,
{ "group-identity-location-demand", "tetra.group_identity_location_demand",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_group_report_response,
{ "group-report-response", "tetra.group_report_response",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_report_response_vals), 0,
"T_group_report_response", HFILL }},
{ &hf_tetra_group_report_response_01,
{ "group-report-response", "tetra.group_report_response",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_group_identity_uplink,
{ "group-identity-uplink", "tetra.group_identity_uplink",
FT_UINT32, BASE_DEC, VALS(tetra_T_group_identity_uplink_vals), 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_uplink_01,
{ "group-identity-uplink", "tetra.group_identity_uplink",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_proprietary_02,
{ "proprietary", "tetra.proprietary",
FT_UINT32, BASE_DEC, VALS(tetra_T_proprietary_01_vals), 0,
"T_proprietary_01", HFILL }},
{ &hf_tetra_group_identity_report,
{ "group-identity-report", "tetra.group_identity_report",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_group_identity_attach_detach_mode,
{ "group-identity-attach-detach-mode", "tetra.group_identity_attach_detach_mode",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_optional_elements_07,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_07_vals), 0,
"T_optional_elements_07", HFILL }},
{ &hf_tetra_type2_element,
{ "type2-element", "tetra.type2_element_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_type3_02,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_02_vals), 0,
"T_type3_02", HFILL }},
{ &hf_tetra_type3_elements_02,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type3_elements_02", HFILL }},
{ &hf_tetra_length,
{ "length", "tetra.length",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_tetra_repeat_num,
{ "repeat-num", "tetra.repeat_num",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_group_identity_uplink_02,
{ "group-identity-uplink", "tetra.group_identity_uplink_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_ack_type,
{ "group-identity-ack-type", "tetra.group_identity_ack_type",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_optional_elements_08,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_08_vals), 0,
"T_optional_elements_08", HFILL }},
{ &hf_tetra_type2_element_01,
{ "type2-element", "tetra.type2_element_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_element_01", HFILL }},
{ &hf_tetra_type3_03,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_03_vals), 0,
"T_type3_03", HFILL }},
{ &hf_tetra_type3_elements_03,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type3_elements_03", HFILL }},
{ &hf_tetra_hook_method_selection,
{ "hook-method-selection", "tetra.hook_method_selection",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_simple_duplex_selection,
{ "simple-duplex-selection", "tetra.simple_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simple_duplex_selection_vals), 0,
NULL, HFILL }},
{ &hf_tetra_basic_service_information,
{ "basic-service-information", "tetra.basic_service_information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_request_transmit_send_data,
{ "request-transmit-send-data", "tetra.request_transmit_send_data",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_call_priority,
{ "call-priority", "tetra.call_priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_clir_control,
{ "clir-control", "tetra.clir_control",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_called_party_address,
{ "called-party-address", "tetra.called_party_address",
FT_UINT32, BASE_DEC, VALS(tetra_Calling_party_address_type_vals), 0,
"Called_party_address_type", HFILL }},
{ &hf_tetra_optional_elements_09,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_09_vals), 0,
"T_optional_elements_09", HFILL }},
{ &hf_tetra_type2_parameters_05,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_05", HFILL }},
{ &hf_tetra_external_subscriber_number,
{ "external-subscriber-number", "tetra.external_subscriber_number",
FT_UINT32, BASE_DEC, VALS(tetra_T_external_subscriber_number_vals), 0,
NULL, HFILL }},
{ &hf_tetra_external_subscriber_number_01,
{ "external-subscriber-number", "tetra.external_subscriber_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_tetra_prop,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_vals), 0,
NULL, HFILL }},
{ &hf_tetra_prop_01,
{ "prop", "tetra.prop_element",
FT_NONE, BASE_NONE, NULL, 0,
"Proprietary", HFILL }},
{ &hf_tetra_circuit_mode,
{ "circuit-mode", "tetra.circuit_mode",
FT_UINT32, BASE_DEC, VALS(tetra_CIRCUIT_vals), 0,
"CIRCUIT", HFILL }},
{ &hf_tetra_encryption,
{ "encryption", "tetra.encryption",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_communication,
{ "communication", "tetra.communication",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_slots_or_speech,
{ "slots-or-speech", "tetra.slots_or_speech",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_call_identifier_01,
{ "call-identifier", "tetra.call_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_simplex_duplex_selection,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_vals), 0,
NULL, HFILL }},
{ &hf_tetra_optional_elements_10,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_10_vals), 0,
"T_optional_elements_10", HFILL }},
{ &hf_tetra_type2_parameters_06,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_06", HFILL }},
{ &hf_tetra_basic_service_information_01,
{ "basic-service-information", "tetra.basic_service_information",
FT_UINT32, BASE_DEC, VALS(tetra_T_basic_service_information_vals), 0,
NULL, HFILL }},
{ &hf_tetra_prop_02,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_01_vals), 0,
"T_prop_01", HFILL }},
{ &hf_tetra_simplex_duplex_selection_01,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_01_vals), 0,
"T_simplex_duplex_selection_01", HFILL }},
{ &hf_tetra_optional_elements_11,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_11_vals), 0,
"T_optional_elements_11", HFILL }},
{ &hf_tetra_type2_parameters_07,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_07", HFILL }},
{ &hf_tetra_basic_service_information_02,
{ "basic-service-information", "tetra.basic_service_information",
FT_UINT32, BASE_DEC, VALS(tetra_T_basic_service_information_01_vals), 0,
"T_basic_service_information_01", HFILL }},
{ &hf_tetra_prop_03,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_02_vals), 0,
"T_prop_02", HFILL }},
{ &hf_tetra_optional_elements_12,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_12_vals), 0,
"T_optional_elements_12", HFILL }},
{ &hf_tetra_type2_parameters_08,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_08", HFILL }},
{ &hf_tetra_prop_04,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_03_vals), 0,
"T_prop_03", HFILL }},
{ &hf_tetra_tx_demand_priority,
{ "tx-demand-priority", "tetra.tx_demand_priority",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_encryption_control,
{ "encryption-control", "tetra.encryption_control",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_optional_elements_13,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_13_vals), 0,
"T_optional_elements_13", HFILL }},
{ &hf_tetra_type2_parameters_09,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_09", HFILL }},
{ &hf_tetra_prop_05,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_04_vals), 0,
"T_prop_04", HFILL }},
{ &hf_tetra_optional_elements_14,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_14_vals), 0,
"T_optional_elements_14", HFILL }},
{ &hf_tetra_type2_parameters_10,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_10", HFILL }},
{ &hf_tetra_prop_06,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_05_vals), 0,
"T_prop_05", HFILL }},
{ &hf_tetra_request_to_transmit_send_data,
{ "request-to-transmit-send-data", "tetra.request_to_transmit_send_data",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_other_party_address,
{ "other-party-address", "tetra.other_party_address",
FT_UINT32, BASE_DEC, VALS(tetra_Calling_party_address_type_vals), 0,
"Other_party_address_type", HFILL }},
{ &hf_tetra_optional_elements_15,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_15_vals), 0,
"T_optional_elements_15", HFILL }},
{ &hf_tetra_type2_parameters_11,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_11", HFILL }},
{ &hf_tetra_prop_07,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_06_vals), 0,
"T_prop_06", HFILL }},
{ &hf_tetra_call_time_out,
{ "call-time-out", "tetra.call_time_out",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_hook_method_selection_01,
{ "hook-method-selection", "tetra.hook_method_selection",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_simplex_duplex_selection_02,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_02_vals), 0,
"T_simplex_duplex_selection_02", HFILL }},
{ &hf_tetra_transmission_grant,
{ "transmission-grant", "tetra.transmission_grant",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_tetra_optional_elements_16,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_16_vals), 0,
"T_optional_elements_16", HFILL }},
{ &hf_tetra_type2_parameters_12,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_12", HFILL }},
{ &hf_tetra_calling_party_address,
{ "calling-party-address", "tetra.calling_party_address",
FT_UINT32, BASE_DEC, VALS(tetra_T_calling_party_address_vals), 0,
NULL, HFILL }},
{ &hf_tetra_calling_party_address_01,
{ "calling-party-address", "tetra.calling_party_address",
FT_UINT32, BASE_DEC, VALS(tetra_Calling_party_address_type_vals), 0,
"Calling_party_address_type", HFILL }},
{ &hf_tetra_external_subscriber_number_02,
{ "external-subscriber-number", "tetra.external_subscriber_number",
FT_UINT32, BASE_DEC, VALS(tetra_T_external_subscriber_number_01_vals), 0,
"T_external_subscriber_number_01", HFILL }},
{ &hf_tetra_external_subscriber_number_03,
{ "external-subscriber-number", "tetra.external_subscriber_number",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_tetra_prop_08,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_07_vals), 0,
"T_prop_07", HFILL }},
{ &hf_tetra_call_time_out_setup_phase,
{ "call-time-out-setup-phase", "tetra.call_time_out_setup_phase",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_simplex_duplex_selection_03,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_optional_elements_17,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_17_vals), 0,
"T_optional_elements_17", HFILL }},
{ &hf_tetra_type2_parameters_13,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_13", HFILL }},
{ &hf_tetra_basic_service_information_03,
{ "basic-service-information", "tetra.basic_service_information",
FT_UINT32, BASE_DEC, VALS(tetra_T_basic_service_information_02_vals), 0,
"T_basic_service_information_02", HFILL }},
{ &hf_tetra_call_status,
{ "call-status", "tetra.call_status",
FT_UINT32, BASE_DEC, VALS(tetra_T_call_status_vals), 0,
NULL, HFILL }},
{ &hf_tetra_call_status_01,
{ "call-status", "tetra.call_status",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_notification_indicator,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_vals), 0,
NULL, HFILL }},
{ &hf_tetra_notification_indicator_01,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_tetra_prop_09,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_08_vals), 0,
"T_prop_08", HFILL }},
{ &hf_tetra_simplex_duplex_selection_04,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_03_vals), 0,
"T_simplex_duplex_selection_03", HFILL }},
{ &hf_tetra_call_queued,
{ "call-queued", "tetra.call_queued",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_optional_elements_18,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_18_vals), 0,
"T_optional_elements_18", HFILL }},
{ &hf_tetra_type2_parameters_14,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_14", HFILL }},
{ &hf_tetra_basic_service_infomation,
{ "basic-service-infomation", "tetra.basic_service_infomation",
FT_UINT32, BASE_DEC, VALS(tetra_T_basic_service_infomation_vals), 0,
NULL, HFILL }},
{ &hf_tetra_basic_service_infomation_01,
{ "basic-service-infomation", "tetra.basic_service_infomation_element",
FT_NONE, BASE_NONE, NULL, 0,
"Basic_service_information", HFILL }},
{ &hf_tetra_notification_indicator_02,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_01_vals), 0,
"T_notification_indicator_01", HFILL }},
{ &hf_tetra_prop_10,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_09_vals), 0,
"T_prop_09", HFILL }},
{ &hf_tetra_call_time_out_01,
{ "call-time-out", "tetra.call_time_out",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_tetra_simplex_duplex_selection_05,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_04_vals), 0,
"T_simplex_duplex_selection_04", HFILL }},
{ &hf_tetra_call_ownership,
{ "call-ownership", "tetra.call_ownership",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_optional_elements_19,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_19_vals), 0,
"T_optional_elements_19", HFILL }},
{ &hf_tetra_type2_parameters_15,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_15", HFILL }},
{ &hf_tetra_call_priority_01,
{ "call-priority", "tetra.call_priority",
FT_UINT32, BASE_DEC, VALS(tetra_T_call_priority_vals), 0,
NULL, HFILL }},
{ &hf_tetra_basic_service_information_04,
{ "basic-service-information", "tetra.basic_service_information",
FT_UINT32, BASE_DEC, VALS(tetra_T_basic_service_information_03_vals), 0,
"T_basic_service_information_03", HFILL }},
{ &hf_tetra_temporary_address,
{ "temporary-address", "tetra.temporary_address",
FT_UINT32, BASE_DEC, VALS(tetra_T_temporary_address_vals), 0,
NULL, HFILL }},
{ &hf_tetra_temporary_address_01,
{ "temporary-address", "tetra.temporary_address",
FT_UINT32, BASE_DEC, VALS(tetra_Calling_party_address_type_vals), 0,
"Calling_party_address_type", HFILL }},
{ &hf_tetra_notification_indicator_03,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_02_vals), 0,
"T_notification_indicator_02", HFILL }},
{ &hf_tetra_prop_11,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_10_vals), 0,
"T_prop_10", HFILL }},
{ &hf_tetra_optional_elements_20,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_20_vals), 0,
"T_optional_elements_20", HFILL }},
{ &hf_tetra_type2_parameters_16,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_16", HFILL }},
{ &hf_tetra_notification_indicator_04,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_03_vals), 0,
"T_notification_indicator_03", HFILL }},
{ &hf_tetra_prop_12,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_11_vals), 0,
"T_prop_11", HFILL }},
{ &hf_tetra_optional_elements_21,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_21_vals), 0,
"T_optional_elements_21", HFILL }},
{ &hf_tetra_type2_parameters_17,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_17", HFILL }},
{ &hf_tetra_notification_indicator_05,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_04_vals), 0,
"T_notification_indicator_04", HFILL }},
{ &hf_tetra_prop_13,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_12_vals), 0,
"T_prop_12", HFILL }},
{ &hf_tetra_reset_call_time_out,
{ "reset-call-time-out", "tetra.reset_call_time_out",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_tetra_optional_elements_22,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_22_vals), 0,
"T_optional_elements_22", HFILL }},
{ &hf_tetra_type2_parameters_18,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_18", HFILL }},
{ &hf_tetra_new_call_identifier,
{ "new-call-identifier", "tetra.new_call_identifier",
FT_UINT32, BASE_DEC, VALS(tetra_T_new_call_identifier_vals), 0,
NULL, HFILL }},
{ &hf_tetra_new_call_identifier_01,
{ "new-call-identifier", "tetra.new_call_identifier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_tetra_call_time_out_02,
{ "call-time-out", "tetra.call_time_out",
FT_UINT32, BASE_DEC, VALS(tetra_T_call_time_out_vals), 0,
NULL, HFILL }},
{ &hf_tetra_call_time_out_03,
{ "call-time-out", "tetra.call_time_out",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_tetra_call_status_02,
{ "call-status", "tetra.call_status",
FT_UINT32, BASE_DEC, VALS(tetra_T_call_status_01_vals), 0,
"T_call_status_01", HFILL }},
{ &hf_tetra_modify,
{ "modify", "tetra.modify",
FT_UINT32, BASE_DEC, VALS(tetra_T_modify_vals), 0,
NULL, HFILL }},
{ &hf_tetra_modify_01,
{ "modify", "tetra.modify_element",
FT_NONE, BASE_NONE, NULL, 0,
"Modify_type", HFILL }},
{ &hf_tetra_notification_indicator_06,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_05_vals), 0,
"T_notification_indicator_05", HFILL }},
{ &hf_tetra_prop_14,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_13_vals), 0,
"T_prop_13", HFILL }},
{ &hf_tetra_optional_elements_23,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_23_vals), 0,
"T_optional_elements_23", HFILL }},
{ &hf_tetra_type2_parameters_19,
{ "type2-parameters", "tetra.type2_parameters_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_parameters_19", HFILL }},
{ &hf_tetra_notification_indicator_07,
{ "notification-indicator", "tetra.notification_indicator",
FT_UINT32, BASE_DEC, VALS(tetra_T_notification_indicator_06_vals), 0,
"T_notification_indicator_06", HFILL }},
{ &hf_tetra_prop_15,
{ "prop", "tetra.prop",
FT_UINT32, BASE_DEC, VALS(tetra_T_prop_14_vals), 0,
"T_prop_14", HFILL }},
{ &hf_tetra_group_identity_ack_request,
{ "group-identity-ack-request", "tetra.group_identity_ack_request",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_optional_elements_24,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_24_vals), 0,
"T_optional_elements_24", HFILL }},
{ &hf_tetra_type2_element_02,
{ "type2-element", "tetra.type2_element_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_element_02", HFILL }},
{ &hf_tetra_type3_04,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_04_vals), 0,
"T_type3_04", HFILL }},
{ &hf_tetra_type3_elements_04,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type3_elements_04", HFILL }},
{ &hf_tetra_group_identity_downlink_02,
{ "group-identity-downlink", "tetra.group_identity_downlink_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_group_identity_attach_detach_accept,
{ "group-identity-attach-detach-accept", "tetra.group_identity_attach_detach_accept",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_tetra_optional_elements_25,
{ "optional-elements", "tetra.optional_elements",
FT_UINT32, BASE_DEC, VALS(tetra_T_optional_elements_25_vals), 0,
"T_optional_elements_25", HFILL }},
{ &hf_tetra_type2_element_03,
{ "type2-element", "tetra.type2_element_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type2_element_03", HFILL }},
{ &hf_tetra_type3_05,
{ "type3", "tetra.type3",
FT_UINT32, BASE_DEC, VALS(tetra_T_type3_05_vals), 0,
"T_type3_05", HFILL }},
{ &hf_tetra_type3_elements_05,
{ "type3-elements", "tetra.type3_elements_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_type3_elements_05", HFILL }},
{ &hf_tetra_called_party_sna,
{ "called-party-sna", "tetra.called_party_sna",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_tetra_called_party_ssi,
{ "called-party-ssi", "tetra.called_party_ssi",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_called_party_ssi_extention,
{ "called-party-ssi-extention", "tetra.called_party_ssi_extention_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_called_party_extention,
{ "called-party-extention", "tetra.called_party_extention",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_tetra_data_01,
{ "data", "tetra.data",
FT_UINT32, BASE_DEC, VALS(tetra_T_data_01_vals), 0,
"T_data_01", HFILL }},
{ &hf_tetra_element1,
{ "element1", "tetra.element1_element",
FT_NONE, BASE_NONE, NULL, 0,
"Type1", HFILL }},
{ &hf_tetra_element,
{ "element", "tetra.element_element",
FT_NONE, BASE_NONE, NULL, 0,
"Type2", HFILL }},
{ &hf_tetra_proprietary_element_owner,
{ "proprietary-element-owner", "tetra.proprietary_element_owner",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_tetra_proprietary_element_owner_extension,
{ "proprietary-element-owner-extension", "tetra.proprietary_element_owner_extension",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_tetra_simplex_duplex_selection_06,
{ "simplex-duplex-selection", "tetra.simplex_duplex_selection",
FT_UINT32, BASE_DEC, VALS(tetra_T_simplex_duplex_selection_05_vals), 0,
"T_simplex_duplex_selection_05", HFILL }},
#line 631 "../../asn1/tetra/packet-tetra-template.c"
};
static gint *ett[] = {
&ett_tetra,
&ett_tetra_header,
&ett_tetra_length,
&ett_tetra_txreg,
&ett_tetra_text,
#line 1 "../../asn1/tetra/packet-tetra-ettarr.c"
&ett_tetra_AACH,
&ett_tetra_BSCH,
&ett_tetra_MLE_Sync,
&ett_tetra_BNCH,
&ett_tetra_T_hyperframe_or_cck,
&ett_tetra_T_optional_params,
&ett_tetra_TS_COMMON_FRAMES,
&ett_tetra_Default_Code_A,
&ett_tetra_Extended_Services_Broadcast,
&ett_tetra_T_section,
&ett_tetra_PRESENT1,
&ett_tetra_MAC_ACCESS,
&ett_tetra_T_data,
&ett_tetra_Address,
&ett_tetra_U_LLC_PDU,
&ett_tetra_U_BL_ACK_FCS,
&ett_tetra_U_MLE_PDU_FCS,
&ett_tetra_U_BL_DATA_FCS,
&ett_tetra_U_BL_ADATA_FCS,
&ett_tetra_U_MLE_PDU,
&ett_tetra_ComplexSDU,
&ett_tetra_T_lengthIndicationOrCapacityRequest,
&ett_tetra_FRAG,
&ett_tetra_MAC_DATA,
&ett_tetra_T_lengthIndicationOrCapacityRequest_01,
&ett_tetra_FRAG6,
&ett_tetra_MAC_FRAG,
&ett_tetra_MAC_FRAG120,
&ett_tetra_MAC_END_UPLINK,
&ett_tetra_MAC_END_UP114,
&ett_tetra_MAC_END_HU,
&ett_tetra_T_lengthInd_ReservationReq,
&ett_tetra_MAC_END_DOWNLINK,
&ett_tetra_T_slot_granting,
&ett_tetra_T_channel_allocation,
&ett_tetra_SlotGranting,
&ett_tetra_ChannelAllocation,
&ett_tetra_T_extend_carrier_flag,
&ett_tetra_T_monitoring_pattern,
&ett_tetra_Extended_carrier_flag,
&ett_tetra_MAC_END_DOWN111,
&ett_tetra_T_slot_granting_01,
&ett_tetra_T_channel_allocation_01,
&ett_tetra_MAC_RESOURCE,
&ett_tetra_OTHER_DATA,
&ett_tetra_T_power_control,
&ett_tetra_T_slot_granting_02,
&ett_tetra_T_channel_allocation_02,
&ett_tetra_AddressMacResource,
&ett_tetra_SSI_NEED,
&ett_tetra_EVENT_NEED,
&ett_tetra_USSI_NEED,
&ett_tetra_SMI_NEED,
&ett_tetra_SSI_EVENT_NEED,
&ett_tetra_SSI_USAGE_NEED,
&ett_tetra_SMI_EVENT_NEED,
&ett_tetra_MAC_ACCESS_DEFINE,
&ett_tetra_T_optional_field,
&ett_tetra_D_LLC_PDU,
&ett_tetra_D_BL_ACK_FCS,
&ett_tetra_D_MLE_PDU_FCS,
&ett_tetra_D_BL_ADATA_FCS,
&ett_tetra_D_BL_DATA_FCS,
&ett_tetra_U_BL_ACK,
&ett_tetra_D_BL_ACK,
&ett_tetra_U_BL_DATA,
&ett_tetra_D_BL_DATA,
&ett_tetra_U_BL_ADATA,
&ett_tetra_D_BL_ADATA,
&ett_tetra_D_MLE_PDU,
&ett_tetra_UMLE_PDU,
&ett_tetra_DMLE_PDU,
&ett_tetra_U_PREPARE,
&ett_tetra_T_optional_elements,
&ett_tetra_T_type2_parameters,
&ett_tetra_T_cell_number,
&ett_tetra_U_RESTORE,
&ett_tetra_T_optional_elements_01,
&ett_tetra_T_type2_parameters_01,
&ett_tetra_T_mcc,
&ett_tetra_T_mnc,
&ett_tetra_T_la,
&ett_tetra_D_NEW_CELL,
&ett_tetra_T_optional_elements_02,
&ett_tetra_D_PREPARE_FAIL,
&ett_tetra_T_optional_elements_03,
&ett_tetra_D_NWRK_BRDADCAST,
&ett_tetra_T_optional_elements_04,
&ett_tetra_T_type2_parameters_02,
&ett_tetra_T_tetra_network_time,
&ett_tetra_T_number_of_neighbour_cells,
&ett_tetra_TETRA_NETWORK_TIME,
&ett_tetra_D_RESTORE_ACK,
&ett_tetra_D_RESTORE_FAIL,
&ett_tetra_U_MM_PDU,
&ett_tetra_D_MM_PDU,
&ett_tetra_GROUP_IDENTITY_DOWNLINK,
&ett_tetra_T_attach_detach_identifiet,
&ett_tetra_T_attach,
&ett_tetra_T_detach,
&ett_tetra_T_address_type,
&ett_tetra_T_gssi_extension,
&ett_tetra_GROUP_IDENTITY_UPLINK,
&ett_tetra_T_attach_detach_identifiet_01,
&ett_tetra_T_attach_01,
&ett_tetra_T_detach_01,
&ett_tetra_T_address_type_01,
&ett_tetra_T_gssi_extension_01,
&ett_tetra_D_LOCATION_UPDATE_ACCEPT,
&ett_tetra_T_optional_elements_05,
&ett_tetra_T_type2_parameters_03,
&ett_tetra_T_ssi,
&ett_tetra_T_address_extension,
&ett_tetra_T_subscriber_class,
&ett_tetra_T_energy_saving_mode,
&ett_tetra_T_scch_info,
&ett_tetra_T_type3,
&ett_tetra_T_type3_elements,
&ett_tetra_T_new_ra,
&ett_tetra_T_group_identity_location_accept,
&ett_tetra_T_group_predefined_lifetime,
&ett_tetra_T_group_identity_downlink,
&ett_tetra_T_proprietary,
&ett_tetra_D_LOCATION_UPDATE_REJECT,
&ett_tetra_U_MM_STATUS,
&ett_tetra_D_MM_STATUS,
&ett_tetra_U_CMCE_PDU,
&ett_tetra_U_RELEASE,
&ett_tetra_U_SDS_DATA,
&ett_tetra_T_called_party_type_identifier,
&ett_tetra_T_short_data_type_identifier,
&ett_tetra_U_STATUS,
&ett_tetra_T_called_party_type_identifier_01,
&ett_tetra_U_INFO,
&ett_tetra_D_CMCE_PDU,
&ett_tetra_D_SDS_DATA,
&ett_tetra_T_calling_party_type_identifier,
&ett_tetra_T_short_data_type_identifier_01,
&ett_tetra_D_STATUS,
&ett_tetra_T_calling_party_type_identifier_01,
&ett_tetra_D_DISCONNECT,
&ett_tetra_D_INFO,
&ett_tetra_D_TX_WAIT,
&ett_tetra_D_TX_CONTINUE,
&ett_tetra_U_LOCATION_UPDATE_DEMAND,
&ett_tetra_T_cipher_control,
&ett_tetra_T_optional_elements_06,
&ett_tetra_T_type2_parameters_04,
&ett_tetra_T_class_of_MS,
&ett_tetra_T_energy_saving_mode_01,
&ett_tetra_T_la_information,
&ett_tetra_T_ssi_01,
&ett_tetra_T_address_extension_01,
&ett_tetra_T_type3_01,
&ett_tetra_T_type3_elements_01,
&ett_tetra_T_group_identity_location_demand,
&ett_tetra_T_group_report_response,
&ett_tetra_T_group_identity_uplink,
&ett_tetra_T_proprietary_01,
&ett_tetra_U_ATTACH_DETACH_GROUP_IDENTITY,
&ett_tetra_T_optional_elements_07,
&ett_tetra_T_type2_element,
&ett_tetra_T_type3_02,
&ett_tetra_T_type3_elements_02,
&ett_tetra_U_ATTACH_DETACH_GROUP_IDENTITY_ACK,
&ett_tetra_T_optional_elements_08,
&ett_tetra_T_type2_element_01,
&ett_tetra_T_type3_03,
&ett_tetra_T_type3_elements_03,
&ett_tetra_U_SETUP,
&ett_tetra_T_optional_elements_09,
&ett_tetra_T_type2_parameters_05,
&ett_tetra_T_external_subscriber_number,
&ett_tetra_T_prop,
&ett_tetra_Basic_service_information,
&ett_tetra_U_ALERT,
&ett_tetra_T_optional_elements_10,
&ett_tetra_T_type2_parameters_06,
&ett_tetra_T_basic_service_information,
&ett_tetra_T_prop_01,
&ett_tetra_U_CONNECT,
&ett_tetra_T_optional_elements_11,
&ett_tetra_T_type2_parameters_07,
&ett_tetra_T_basic_service_information_01,
&ett_tetra_T_prop_02,
&ett_tetra_U_TX_CEASED,
&ett_tetra_T_optional_elements_12,
&ett_tetra_T_type2_parameters_08,
&ett_tetra_T_prop_03,
&ett_tetra_U_TX_DEMAND,
&ett_tetra_T_optional_elements_13,
&ett_tetra_T_type2_parameters_09,
&ett_tetra_T_prop_04,
&ett_tetra_U_DISCONNECT,
&ett_tetra_T_optional_elements_14,
&ett_tetra_T_type2_parameters_10,
&ett_tetra_T_prop_05,
&ett_tetra_U_CALL_RESTORE,
&ett_tetra_T_optional_elements_15,
&ett_tetra_T_type2_parameters_11,
&ett_tetra_T_prop_06,
&ett_tetra_D_SETUP,
&ett_tetra_T_optional_elements_16,
&ett_tetra_T_type2_parameters_12,
&ett_tetra_T_calling_party_address,
&ett_tetra_T_external_subscriber_number_01,
&ett_tetra_T_prop_07,
&ett_tetra_D_CALL_PROCEEDING,
&ett_tetra_T_optional_elements_17,
&ett_tetra_T_type2_parameters_13,
&ett_tetra_T_basic_service_information_02,
&ett_tetra_T_call_status,
&ett_tetra_T_notification_indicator,
&ett_tetra_T_prop_08,
&ett_tetra_D_ALERT,
&ett_tetra_T_optional_elements_18,
&ett_tetra_T_type2_parameters_14,
&ett_tetra_T_basic_service_infomation,
&ett_tetra_T_notification_indicator_01,
&ett_tetra_T_prop_09,
&ett_tetra_D_CONNECT,
&ett_tetra_T_optional_elements_19,
&ett_tetra_T_type2_parameters_15,
&ett_tetra_T_call_priority,
&ett_tetra_T_basic_service_information_03,
&ett_tetra_T_temporary_address,
&ett_tetra_T_notification_indicator_02,
&ett_tetra_T_prop_10,
&ett_tetra_D_CONNECT_ACK,
&ett_tetra_T_optional_elements_20,
&ett_tetra_T_type2_parameters_16,
&ett_tetra_T_notification_indicator_03,
&ett_tetra_T_prop_11,
&ett_tetra_D_RELEASE,
&ett_tetra_T_optional_elements_21,
&ett_tetra_T_type2_parameters_17,
&ett_tetra_T_notification_indicator_04,
&ett_tetra_T_prop_12,
&ett_tetra_D_CALL_RESTORE,
&ett_tetra_T_optional_elements_22,
&ett_tetra_T_type2_parameters_18,
&ett_tetra_T_new_call_identifier,
&ett_tetra_T_call_time_out,
&ett_tetra_T_call_status_01,
&ett_tetra_T_modify,
&ett_tetra_T_notification_indicator_05,
&ett_tetra_T_prop_13,
&ett_tetra_D_TX_CEASED,
&ett_tetra_T_optional_elements_23,
&ett_tetra_T_type2_parameters_19,
&ett_tetra_T_notification_indicator_06,
&ett_tetra_T_prop_14,
&ett_tetra_D_TX_GRANTED,
&ett_tetra_D_ATTACH_DETACH_GROUP_IDENTITY,
&ett_tetra_T_optional_elements_24,
&ett_tetra_T_type2_element_02,
&ett_tetra_T_type3_04,
&ett_tetra_T_type3_elements_04,
&ett_tetra_D_ATTACH_DETACH_GROUP_IDENTITY_ACK,
&ett_tetra_T_optional_elements_25,
&ett_tetra_T_type2_element_03,
&ett_tetra_T_type3_05,
&ett_tetra_T_type3_elements_05,
&ett_tetra_Calling_party_address_type,
&ett_tetra_T_called_party_ssi_extention,
&ett_tetra_Proprietary,
&ett_tetra_T_data_01,
&ett_tetra_Type1,
&ett_tetra_Type2,
&ett_tetra_Modify_type,
#line 641 "../../asn1/tetra/packet-tetra-template.c"
};
static ei_register_info ei[] = {
{ &ei_tetra_channels_incorrect, { "tetra.channels.incorrect", PI_MALFORMED, PI_WARN, "Channel count incorrect, must be <= 3", EXPFILL }},
};
proto_tetra = proto_register_protocol("TETRA Protocol", "tetra", "tetra");
proto_register_field_array (proto_tetra, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("tetra", dissect_tetra, proto_tetra);
expert_tetra = expert_register_protocol(proto_tetra);
expert_register_field_array(expert_tetra, ei, array_length(ei));
tetra_module = prefs_register_protocol(proto_tetra, NULL);
prefs_register_bool_preference(tetra_module, "include_carrier_number",
"The data include carrier numbers",
"Whether the captured data include carrier number",
&include_carrier_number);
}
