static int
dissect_h282_H221NonStandardIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 255, FALSE, NULL);
return offset;
}
static int
dissect_h282_OBJECT_IDENTIFIER(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_object_identifier(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h282_Key(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_Key, Key_choice,
NULL);
return offset;
}
static int
dissect_h282_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL);
return offset;
}
static int
dissect_h282_NonStandardParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_NonStandardParameter, NonStandardParameter_sequence);
return offset;
}
static int
dissect_h282_Handle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_h282_NonStandardIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_NonStandardIdentifier, NonStandardIdentifier_choice,
NULL);
return offset;
}
static int
dissect_h282_TextString(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_BMPString(tvb, offset, actx, tree, hf_index,
0, 255, FALSE);
return offset;
}
static int
dissect_h282_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_h282_DeviceClass(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceClass, DeviceClass_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h282_StreamID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h282_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_h282_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_DeviceProfile(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceProfile, DeviceProfile_sequence);
return offset;
}
static int
dissect_h282_StreamProfile(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_StreamProfile, StreamProfile_sequence);
return offset;
}
static int
dissect_h282_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_h282_CapabilityID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CapabilityID, CapabilityID_choice,
NULL);
return offset;
}
static int
dissect_h282_SET_SIZE_0_127_OF_DeviceProfile(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_0_127_OF_DeviceProfile, SET_SIZE_0_127_OF_DeviceProfile_set_of,
0, 127, FALSE);
return offset;
}
static int
dissect_h282_SET_SIZE_0_127_OF_StreamProfile(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_0_127_OF_StreamProfile, SET_SIZE_0_127_OF_StreamProfile_set_of,
0, 127, FALSE);
return offset;
}
static int
dissect_h282_T_applicationData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_applicationData, T_applicationData_choice,
NULL);
return offset;
}
static int
dissect_h282_NonCollapsingCapabilities_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_NonCollapsingCapabilities_item, NonCollapsingCapabilities_item_sequence);
return offset;
}
static int
dissect_h282_NonCollapsingCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_NonCollapsingCapabilities, NonCollapsingCapabilities_set_of);
return offset;
}
static int
dissect_h282_Day(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_h282_Month(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 12U, NULL, FALSE);
return offset;
}
static int
dissect_h282_Year(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1980U, 2999U, NULL, FALSE);
return offset;
}
static int
dissect_h282_Hour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 23U, NULL, FALSE);
return offset;
}
static int
dissect_h282_Minute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_h282_DeviceText(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
0, 32, FALSE, NULL);
return offset;
}
static int
dissect_h282_PanPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-18000, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_TiltPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-18000, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_ZoomPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1023, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_h282_IrisPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h282_FocusPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h282_CameraPanSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_CameraTiltSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_BackLight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_WhiteBalance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_PresetNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_StreamPlayerState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_StreamPlayerState, StreamPlayerState_choice,
NULL);
return offset;
}
static int
dissect_h282_T_presetCapability_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_presetCapability_item, T_presetCapability_item_sequence);
return offset;
}
static int
dissect_h282_T_presetCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_presetCapability, T_presetCapability_set_of,
0, 255, FALSE);
return offset;
}
static int
dissect_h282_DevicePresetCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DevicePresetCapability, DevicePresetCapability_sequence);
return offset;
}
static int
dissect_h282_INTEGER_2_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_1_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_T_filterTextLabel_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_filterTextLabel_item, T_filterTextLabel_item_sequence);
return offset;
}
static int
dissect_h282_T_filterTextLabel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_filterTextLabel, T_filterTextLabel_set_of,
0, 255, FALSE);
return offset;
}
static int
dissect_h282_CameraFilterCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CameraFilterCapability, CameraFilterCapability_sequence);
return offset;
}
static int
dissect_h282_T_accessoryTextLabel_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_accessoryTextLabel_item, T_accessoryTextLabel_item_sequence);
return offset;
}
static int
dissect_h282_T_accessoryTextLabel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_accessoryTextLabel, T_accessoryTextLabel_set_of,
0, 255, FALSE);
return offset;
}
static int
dissect_h282_CameraLensCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CameraLensCapability, CameraLensCapability_sequence);
return offset;
}
static int
dissect_h282_INTEGER_1_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 10U, NULL, FALSE);
return offset;
}
static int
dissect_h282_T_lightTextLabel_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_lightTextLabel_item, T_lightTextLabel_item_sequence);
return offset;
}
static int
dissect_h282_T_lightTextLabel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_lightTextLabel, T_lightTextLabel_set_of,
0, 10, FALSE);
return offset;
}
static int
dissect_h282_ExternalCameraLightCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_ExternalCameraLightCapability, ExternalCameraLightCapability_sequence);
return offset;
}
static int
dissect_h282_CameraPanSpeedCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CameraPanSpeedCapability, CameraPanSpeedCapability_sequence);
return offset;
}
static int
dissect_h282_CameraTiltSpeedCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CameraTiltSpeedCapability, CameraTiltSpeedCapability_sequence);
return offset;
}
static int
dissect_h282_MaxBacklight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MaxWhiteBalance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MinZoomPositionSetSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MinFocusPositionStepSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MinIrisPositionStepSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_M18000_0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-18000, 0U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_0_18000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_1_18000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 18000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_PanPositionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_PanPositionCapability, PanPositionCapability_sequence);
return offset;
}
static int
dissect_h282_TiltPositionCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_TiltPositionCapability, TiltPositionCapability_sequence);
return offset;
}
static int
dissect_h282_MinZoomMagnificationStepSize(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MaxNumberOfSlides(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MaxSlideDisplayTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_MaxNumberOfPrograms(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_10_1000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
10U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_T_multiplierFactors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_multiplierFactors, T_multiplierFactors_set_of,
1, 64, FALSE);
return offset;
}
static int
dissect_h282_T_divisorFactors(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_divisorFactors, T_divisorFactors_set_of,
1, 64, FALSE);
return offset;
}
static int
dissect_h282_PlayBackSpeedCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_PlayBackSpeedCapability, PlayBackSpeedCapability_sequence);
return offset;
}
static int
dissect_h282_INTEGER_2_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_h282_T_availableDevices_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_availableDevices_item, T_availableDevices_item_sequence);
return offset;
}
static int
dissect_h282_T_availableDevices(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_availableDevices, T_availableDevices_set_of,
2, 64, FALSE);
return offset;
}
static int
dissect_h282_VideoInputsCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_VideoInputsCapability, VideoInputsCapability_sequence);
return offset;
}
static int
dissect_h282_T_availableDevices_item_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_availableDevices_item_01, T_availableDevices_item_01_sequence);
return offset;
}
static int
dissect_h282_T_availableDevices_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_availableDevices_01, T_availableDevices_01_set_of,
2, 64, FALSE);
return offset;
}
static int
dissect_h282_AudioInputsCapability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_AudioInputsCapability, AudioInputsCapability_sequence);
return offset;
}
static int
dissect_h282_DeviceAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceAttribute, DeviceAttribute_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceState, DeviceState_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceDate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceDate, DeviceDate_sequence);
return offset;
}
static int
dissect_h282_DeviceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceTime, DeviceTime_sequence);
return offset;
}
static int
dissect_h282_T_mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_mode, T_mode_choice,
NULL);
return offset;
}
static int
dissect_h282_DevicePreset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DevicePreset, DevicePreset_sequence);
return offset;
}
static int
dissect_h282_Mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_Mode, Mode_choice,
NULL);
return offset;
}
static int
dissect_h282_PointingToggle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_PointingToggle, PointingToggle_choice,
NULL);
return offset;
}
static int
dissect_h282_SelectExternalLight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_SelectExternalLight, SelectExternalLight_choice,
NULL);
return offset;
}
static int
dissect_h282_T_panDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_panDirection, T_panDirection_choice,
NULL);
return offset;
}
static int
dissect_h282_INTEGER_50_1000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
50U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_PanContinuous(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_PanContinuous, PanContinuous_sequence);
return offset;
}
static int
dissect_h282_T_tiltDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_tiltDirection, T_tiltDirection_choice,
NULL);
return offset;
}
static int
dissect_h282_TiltContinuous(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_TiltContinuous, TiltContinuous_sequence);
return offset;
}
static int
dissect_h282_T_zoomDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_zoomDirection, T_zoomDirection_choice,
NULL);
return offset;
}
static int
dissect_h282_ZoomContinuous(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_ZoomContinuous, ZoomContinuous_sequence);
return offset;
}
static int
dissect_h282_T_focusDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_focusDirection, T_focusDirection_choice,
NULL);
return offset;
}
static int
dissect_h282_FocusContinuous(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_FocusContinuous, FocusContinuous_sequence);
return offset;
}
static int
dissect_h282_PositioningMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_PositioningMode, PositioningMode_choice,
NULL);
return offset;
}
static int
dissect_h282_CameraLensNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_CameraFilterNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_SetZoomPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SetZoomPosition, SetZoomPosition_sequence);
return offset;
}
static int
dissect_h282_SetFocusPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SetFocusPosition, SetFocusPosition_sequence);
return offset;
}
static int
dissect_h282_SetIrisPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SetIrisPosition, SetIrisPosition_sequence);
return offset;
}
static int
dissect_h282_SetPanPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SetPanPosition, SetPanPosition_sequence);
return offset;
}
static int
dissect_h282_SetTiltPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SetTiltPosition, SetTiltPosition_sequence);
return offset;
}
static int
dissect_h282_ZoomMagnification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
10U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_PanView(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1000, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_TiltView(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1000, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_h282_SlideNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_h282_SelectDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_SelectDirection, SelectDirection_choice,
NULL);
return offset;
}
static int
dissect_h282_AutoSlideShowControl(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_AutoSlideShowControl, AutoSlideShowControl_choice,
NULL);
return offset;
}
static int
dissect_h282_AutoSlideDisplayTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_h282_ProgramNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_0_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 24U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_0_59(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_h282_INTEGER_0_99999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 99999U, NULL, FALSE);
return offset;
}
static int
dissect_h282_ProgramDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_ProgramDuration, ProgramDuration_sequence);
return offset;
}
static int
dissect_h282_PlaybackSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_PlaybackSpeed, PlaybackSpeed_sequence);
return offset;
}
static int
dissect_h282_RecordForDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_RecordForDuration, RecordForDuration_sequence);
return offset;
}
static int
dissect_h282_T_inputDevices_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_T_inputDevices_item, T_inputDevices_item_sequence);
return offset;
}
static int
dissect_h282_T_inputDevices(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_T_inputDevices, T_inputDevices_set_of,
2, 64, FALSE);
return offset;
}
static int
dissect_h282_DeviceInputs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceInputs, DeviceInputs_sequence);
return offset;
}
static int
dissect_h282_ControlAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_ControlAttribute, ControlAttribute_choice,
NULL);
return offset;
}
static int
dissect_h282_StatusAttributeIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_StatusAttributeIdentifier, StatusAttributeIdentifier_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentDeviceState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentDeviceState, CurrentDeviceState_choice,
NULL);
return offset;
}
static int
dissect_h282_T_currentDay(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_currentDay, T_currentDay_choice,
NULL);
return offset;
}
static int
dissect_h282_T_currentMonth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_currentMonth, T_currentMonth_choice,
NULL);
return offset;
}
static int
dissect_h282_T_currentYear(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_currentYear, T_currentYear_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentDeviceDate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentDeviceDate, CurrentDeviceDate_sequence);
return offset;
}
static int
dissect_h282_T_currentHour(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_currentHour, T_currentHour_choice,
NULL);
return offset;
}
static int
dissect_h282_T_currentMinute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_currentMinute, T_currentMinute_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentDeviceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentDeviceTime, CurrentDeviceTime_sequence);
return offset;
}
static int
dissect_h282_CurrentDevicePreset(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentDevicePreset, CurrentDevicePreset_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentMode, CurrentMode_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentPointingMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentPointingMode, CurrentPointingMode_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentCameraLensNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentCameraLensNumber, CurrentCameraLensNumber_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentCameraFilterNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentCameraFilterNumber, CurrentCameraFilterNumber_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentExternalLight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentExternalLight, CurrentExternalLight_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentCameraPanSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentCameraPanSpeed, CurrentCameraPanSpeed_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentCameraTiltSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentCameraTiltSpeed, CurrentCameraTiltSpeed_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentBackLight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentBackLight, CurrentBackLight_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentWhiteBalance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentWhiteBalance, CurrentWhiteBalance_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentZoomPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentZoomPosition, CurrentZoomPosition_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentFocusPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentFocusPosition, CurrentFocusPosition_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentIrisPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentIrisPosition, CurrentIrisPosition_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentPanPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentPanPosition, CurrentPanPosition_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentTiltPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentTiltPosition, CurrentTiltPosition_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentSlide(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentSlide, CurrentSlide_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentAutoSlideDisplayTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentAutoSlideDisplayTime, CurrentAutoSlideDisplayTime_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentSelectedProgram(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentSelectedProgram, CurrentSelectedProgram_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentStreamPlayerState(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentStreamPlayerState, CurrentStreamPlayerState_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentPlaybackSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentPlaybackSpeed, CurrentPlaybackSpeed_choice,
NULL);
return offset;
}
static int
dissect_h282_CurrentAudioOutputMute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CurrentAudioOutputMute, CurrentAudioOutputMute_choice,
NULL);
return offset;
}
static int
dissect_h282_StatusAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_StatusAttribute, StatusAttribute_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceEventIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceEventIdentifier, DeviceEventIdentifier_choice,
NULL);
return offset;
}
static int
dissect_h282_CameraPannedToLimit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CameraPannedToLimit, CameraPannedToLimit_choice,
NULL);
return offset;
}
static int
dissect_h282_CameraTiltedToLimit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CameraTiltedToLimit, CameraTiltedToLimit_choice,
NULL);
return offset;
}
static int
dissect_h282_CameraZoomedToLimit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CameraZoomedToLimit, CameraZoomedToLimit_choice,
NULL);
return offset;
}
static int
dissect_h282_CameraFocusedToLimit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_CameraFocusedToLimit, CameraFocusedToLimit_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceEvent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceEvent, DeviceEvent_choice,
NULL);
return offset;
}
static int
dissect_h282_SourceSelectRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SourceSelectRequest, SourceSelectRequest_sequence);
return offset;
}
static int
dissect_h282_T_result(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result, T_result_choice,
NULL);
return offset;
}
static int
dissect_h282_SourceSelectResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SourceSelectResponse, SourceSelectResponse_sequence);
return offset;
}
static int
dissect_h282_SourceEventsRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SourceEventsRequest, SourceEventsRequest_sequence);
return offset;
}
static int
dissect_h282_T_result_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_01, T_result_01_choice,
NULL);
return offset;
}
static int
dissect_h282_SourceEventsResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SourceEventsResponse, SourceEventsResponse_sequence);
return offset;
}
static int
dissect_h282_SourceChangeEventIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_SourceChangeEventIndication, SourceChangeEventIndication_sequence);
return offset;
}
static int
dissect_h282_DeviceAttributeRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceAttributeRequest, DeviceAttributeRequest_sequence);
return offset;
}
static int
dissect_h282_SET_OF_DeviceAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_OF_DeviceAttribute, SET_OF_DeviceAttribute_set_of);
return offset;
}
static int
dissect_h282_T_result_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_02, T_result_02_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceAttributeResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceAttributeResponse, DeviceAttributeResponse_sequence);
return offset;
}
static int
dissect_h282_DeviceLockRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceLockRequest, DeviceLockRequest_sequence);
return offset;
}
static int
dissect_h282_T_result_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_03, T_result_03_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceLockResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceLockResponse, DeviceLockResponse_sequence);
return offset;
}
static int
dissect_h282_DeviceLockEnquireRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceLockEnquireRequest, DeviceLockEnquireRequest_sequence);
return offset;
}
static int
dissect_h282_T_result_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_04, T_result_04_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceLockEnquireResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceLockEnquireResponse, DeviceLockEnquireResponse_sequence);
return offset;
}
static int
dissect_h282_DeviceLockTerminatedIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceLockTerminatedIndication, DeviceLockTerminatedIndication_sequence);
return offset;
}
static int
dissect_h282_SET_SIZE_1_8_OF_ControlAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_1_8_OF_ControlAttribute, SET_SIZE_1_8_OF_ControlAttribute_set_of,
1, 8, FALSE);
return offset;
}
static int
dissect_h282_DeviceControlRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceControlRequest, DeviceControlRequest_sequence);
return offset;
}
static int
dissect_h282_SET_SIZE_1_16_OF_StatusAttributeIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_1_16_OF_StatusAttributeIdentifier, SET_SIZE_1_16_OF_StatusAttributeIdentifier_set_of,
1, 16, FALSE);
return offset;
}
static int
dissect_h282_DeviceStatusEnquireRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceStatusEnquireRequest, DeviceStatusEnquireRequest_sequence);
return offset;
}
static int
dissect_h282_SET_SIZE_1_16_OF_StatusAttribute(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_1_16_OF_StatusAttribute, SET_SIZE_1_16_OF_StatusAttribute_set_of,
1, 16, FALSE);
return offset;
}
static int
dissect_h282_T_result_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_05, T_result_05_choice,
NULL);
return offset;
}
static int
dissect_h282_DeviceStatusEnquireResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceStatusEnquireResponse, DeviceStatusEnquireResponse_sequence);
return offset;
}
static int
dissect_h282_SET_OF_DeviceEventIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_OF_DeviceEventIdentifier, SET_OF_DeviceEventIdentifier_set_of);
return offset;
}
static int
dissect_h282_ConfigureDeviceEventsRequest(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_ConfigureDeviceEventsRequest, ConfigureDeviceEventsRequest_sequence);
return offset;
}
static int
dissect_h282_T_result_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_T_result_06, T_result_06_choice,
NULL);
return offset;
}
static int
dissect_h282_ConfigureDeviceEventsResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_ConfigureDeviceEventsResponse, ConfigureDeviceEventsResponse_sequence);
return offset;
}
static int
dissect_h282_SET_SIZE_1_8_OF_DeviceEvent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_set_of(tvb, offset, actx, tree, hf_index,
ett_h282_SET_SIZE_1_8_OF_DeviceEvent, SET_SIZE_1_8_OF_DeviceEvent_set_of,
1, 8, FALSE);
return offset;
}
static int
dissect_h282_DeviceEventNotifyIndication(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_DeviceEventNotifyIndication, DeviceEventNotifyIndication_sequence);
return offset;
}
static int
dissect_h282_NonStandardPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_h282_NonStandardPDU, NonStandardPDU_sequence);
return offset;
}
static int
dissect_h282_RequestPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 24 "../../asn1/h282/h282.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_RequestPDU, RequestPDU_choice,
&msg_type);
#line 27 "../../asn1/h282/h282.cnf"
p = try_val_to_str(msg_type, VALS(h282_RequestPDU_vals));
if (p)
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "RequestPDU/%s", p);
return offset;
}
static int
dissect_h282_ResponsePDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 35 "../../asn1/h282/h282.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_ResponsePDU, ResponsePDU_choice,
&msg_type);
#line 38 "../../asn1/h282/h282.cnf"
p = try_val_to_str(msg_type, VALS(h282_ResponsePDU_vals));
if (p)
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "ResponsePDU/%s", p);
return offset;
}
static int
dissect_h282_IndicationPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 46 "../../asn1/h282/h282.cnf"
gint32 msg_type = -1;
const gchar *p = NULL;
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_IndicationPDU, IndicationPDU_choice,
&msg_type);
#line 49 "../../asn1/h282/h282.cnf"
p = try_val_to_str(msg_type, VALS(h282_IndicationPDU_vals));
if (p)
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "IndicationPDU/%s", p);
return offset;
}
static int
dissect_h282_RDCPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_h282_RDCPDU, RDCPDU_choice,
NULL);
return offset;
}
static int dissect_NonCollapsingCapabilities_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h282_NonCollapsingCapabilities(tvb, offset, &asn1_ctx, tree, hf_h282_NonCollapsingCapabilities_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_RDCPDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_h282_RDCPDU(tvb, offset, &asn1_ctx, tree, hf_h282_RDCPDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_h282(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
proto_tree *h282_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
ti = proto_tree_add_item(tree, proto_h282, tvb, 0, -1, ENC_NA);
h282_tree = proto_item_add_subtree(ti, ett_h282);
return dissect_RDCPDU_PDU(tvb, pinfo, h282_tree, NULL);
}
void proto_register_h282(void) {
static hf_register_info hf[] = {
#line 1 "../../asn1/h282/packet-h282-hfarr.c"
{ &hf_h282_NonCollapsingCapabilities_PDU,
{ "NonCollapsingCapabilities", "h282.NonCollapsingCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_RDCPDU_PDU,
{ "RDCPDU", "h282.RDCPDU",
FT_UINT32, BASE_DEC, VALS(h282_RDCPDU_vals), 0,
NULL, HFILL }},
{ &hf_h282_object,
{ "object", "h282.object",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_h282_h221NonStandard,
{ "h221NonStandard", "h282.h221NonStandard",
FT_BYTES, BASE_NONE, NULL, 0,
"H221NonStandardIdentifier", HFILL }},
{ &hf_h282_key,
{ "key", "h282.key",
FT_UINT32, BASE_DEC, VALS(h282_Key_vals), 0,
NULL, HFILL }},
{ &hf_h282_data,
{ "data", "h282.data",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_h282_h221nonStandard,
{ "h221nonStandard", "h282.h221nonStandard",
FT_BYTES, BASE_NONE, NULL, 0,
"H221NonStandardIdentifier", HFILL }},
{ &hf_h282_camera,
{ "camera", "h282.camera",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_microphone,
{ "microphone", "h282.microphone",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_streamPlayerRecorder,
{ "streamPlayerRecorder", "h282.streamPlayerRecorder",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_slideProjector,
{ "slideProjector", "h282.slideProjector",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lightSource,
{ "lightSource", "h282.lightSource",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_sourceCombiner,
{ "sourceCombiner", "h282.sourceCombiner",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_nonStandardDevice,
{ "nonStandardDevice", "h282.nonStandardDevice",
FT_UINT32, BASE_DEC, VALS(h282_NonStandardIdentifier_vals), 0,
"NonStandardIdentifier", HFILL }},
{ &hf_h282_deviceID,
{ "deviceID", "h282.deviceID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_audioSourceFlag,
{ "audioSourceFlag", "h282.audioSourceFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_audioSinkFlag,
{ "audioSinkFlag", "h282.audioSinkFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_videoSourceFlag,
{ "videoSourceFlag", "h282.videoSourceFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_videoSinkFlag,
{ "videoSinkFlag", "h282.videoSinkFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_remoteControlFlag,
{ "remoteControlFlag", "h282.remoteControlFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_instanceNumber,
{ "instanceNumber", "h282.instanceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_h282_deviceName,
{ "deviceName", "h282.deviceName",
FT_STRING, BASE_NONE, NULL, 0,
"TextString", HFILL }},
{ &hf_h282_streamID,
{ "streamID", "h282.streamID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_videoStreamFlag,
{ "videoStreamFlag", "h282.videoStreamFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_sourceChangeFlag,
{ "sourceChangeFlag", "h282.sourceChangeFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_streamName,
{ "streamName", "h282.streamName",
FT_STRING, BASE_NONE, NULL, 0,
"TextString", HFILL }},
{ &hf_h282_standard,
{ "standard", "h282.standard",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_h282_nonStandard,
{ "nonStandard", "h282.nonStandard",
FT_UINT32, BASE_DEC, VALS(h282_Key_vals), 0,
"Key", HFILL }},
{ &hf_h282_NonCollapsingCapabilities_item,
{ "NonCollapsingCapabilities item", "h282.NonCollapsingCapabilities_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_capabilityID,
{ "capabilityID", "h282.capabilityID",
FT_UINT32, BASE_DEC, VALS(h282_CapabilityID_vals), 0,
NULL, HFILL }},
{ &hf_h282_applicationData,
{ "applicationData", "h282.applicationData",
FT_UINT32, BASE_DEC, VALS(h282_T_applicationData_vals), 0,
NULL, HFILL }},
{ &hf_h282_deviceList,
{ "deviceList", "h282.deviceList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_127_OF_DeviceProfile", HFILL }},
{ &hf_h282_deviceList_item,
{ "DeviceProfile", "h282.DeviceProfile",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_streamList,
{ "streamList", "h282.streamList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_0_127_OF_StreamProfile", HFILL }},
{ &hf_h282_streamList_item,
{ "StreamProfile", "h282.StreamProfile",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_playing,
{ "playing", "h282.playing",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_recording,
{ "recording", "h282.recording",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_pausedOnRecord,
{ "pausedOnRecord", "h282.pausedOnRecord",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_pausedOnPlay,
{ "pausedOnPlay", "h282.pausedOnPlay",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_rewinding,
{ "rewinding", "h282.rewinding",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_fastForwarding,
{ "fastForwarding", "h282.fastForwarding",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_searchingForwards,
{ "searchingForwards", "h282.searchingForwards",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_searchingBackwards,
{ "searchingBackwards", "h282.searchingBackwards",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_stopped,
{ "stopped", "h282.stopped",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_programUnavailable,
{ "programUnavailable", "h282.programUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_maxNumber,
{ "maxNumber", "h282.maxNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"PresetNumber", HFILL }},
{ &hf_h282_presetCapability,
{ "presetCapability", "h282.presetCapability",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_presetCapability_item,
{ "presetCapability item", "h282.presetCapability_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_presetNumber,
{ "presetNumber", "h282.presetNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_storeModeSupported,
{ "storeModeSupported", "h282.storeModeSupported",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_presetTextLabel,
{ "presetTextLabel", "h282.presetTextLabel",
FT_BYTES, BASE_NONE, NULL, 0,
"DeviceText", HFILL }},
{ &hf_h282_maxNumberOfFilters,
{ "maxNumberOfFilters", "h282.maxNumberOfFilters",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_255", HFILL }},
{ &hf_h282_filterTextLabel,
{ "filterTextLabel", "h282.filterTextLabel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_filterTextLabel_item,
{ "filterTextLabel item", "h282.filterTextLabel_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_filterNumber,
{ "filterNumber", "h282.filterNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h282_filterTextLabel_01,
{ "filterTextLabel", "h282.filterTextLabel",
FT_BYTES, BASE_NONE, NULL, 0,
"DeviceText", HFILL }},
{ &hf_h282_maxNumberOfLens,
{ "maxNumberOfLens", "h282.maxNumberOfLens",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_255", HFILL }},
{ &hf_h282_accessoryTextLabel,
{ "accessoryTextLabel", "h282.accessoryTextLabel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_accessoryTextLabel_item,
{ "accessoryTextLabel item", "h282.accessoryTextLabel_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lensNumber,
{ "lensNumber", "h282.lensNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_255", HFILL }},
{ &hf_h282_lensTextLabel,
{ "lensTextLabel", "h282.lensTextLabel",
FT_BYTES, BASE_NONE, NULL, 0,
"DeviceText", HFILL }},
{ &hf_h282_maxNumber_01,
{ "maxNumber", "h282.maxNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_10", HFILL }},
{ &hf_h282_lightTextLabel,
{ "lightTextLabel", "h282.lightTextLabel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lightTextLabel_item,
{ "lightTextLabel item", "h282.lightTextLabel_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lightNumber,
{ "lightNumber", "h282.lightNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_10", HFILL }},
{ &hf_h282_lightLabel,
{ "lightLabel", "h282.lightLabel",
FT_BYTES, BASE_NONE, NULL, 0,
"DeviceText", HFILL }},
{ &hf_h282_maxSpeed,
{ "maxSpeed", "h282.maxSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraPanSpeed", HFILL }},
{ &hf_h282_minSpeed,
{ "minSpeed", "h282.minSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraPanSpeed", HFILL }},
{ &hf_h282_speedStepSize,
{ "speedStepSize", "h282.speedStepSize",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraPanSpeed", HFILL }},
{ &hf_h282_maxSpeed_01,
{ "maxSpeed", "h282.maxSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraTiltSpeed", HFILL }},
{ &hf_h282_minSpeed_01,
{ "minSpeed", "h282.minSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraTiltSpeed", HFILL }},
{ &hf_h282_speedStepSize_01,
{ "speedStepSize", "h282.speedStepSize",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraTiltSpeed", HFILL }},
{ &hf_h282_maxLeft,
{ "maxLeft", "h282.maxLeft",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M18000_0", HFILL }},
{ &hf_h282_maxRight,
{ "maxRight", "h282.maxRight",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_18000", HFILL }},
{ &hf_h282_minStepSize,
{ "minStepSize", "h282.minStepSize",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_18000", HFILL }},
{ &hf_h282_maxDown,
{ "maxDown", "h282.maxDown",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M18000_0", HFILL }},
{ &hf_h282_maxUp,
{ "maxUp", "h282.maxUp",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_18000", HFILL }},
{ &hf_h282_multiplierFactors,
{ "multiplierFactors", "h282.multiplierFactors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_multiplierFactors_item,
{ "multiplierFactors item", "h282.multiplierFactors_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_1000", HFILL }},
{ &hf_h282_divisorFactors,
{ "divisorFactors", "h282.divisorFactors",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_divisorFactors_item,
{ "divisorFactors item", "h282.divisorFactors_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_1000", HFILL }},
{ &hf_h282_numberOfDeviceInputs,
{ "numberOfDeviceInputs", "h282.numberOfDeviceInputs",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_2_64", HFILL }},
{ &hf_h282_numberOfDeviceRows,
{ "numberOfDeviceRows", "h282.numberOfDeviceRows",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_64", HFILL }},
{ &hf_h282_availableDevices,
{ "availableDevices", "h282.availableDevices",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_availableDevices_item,
{ "availableDevices item", "h282.availableDevices_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceClass,
{ "deviceClass", "h282.deviceClass",
FT_UINT32, BASE_DEC, VALS(h282_DeviceClass_vals), 0,
NULL, HFILL }},
{ &hf_h282_deviceIdentifier,
{ "deviceIdentifier", "h282.deviceIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
"DeviceID", HFILL }},
{ &hf_h282_availableDevices_01,
{ "availableDevices", "h282.availableDevices",
FT_UINT32, BASE_DEC, NULL, 0,
"T_availableDevices_01", HFILL }},
{ &hf_h282_availableDevices_item_01,
{ "availableDevices item", "h282.availableDevices_item",
FT_NONE, BASE_NONE, NULL, 0,
"T_availableDevices_item_01", HFILL }},
{ &hf_h282_deviceStateSupported,
{ "deviceStateSupported", "h282.deviceStateSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceDateSupported,
{ "deviceDateSupported", "h282.deviceDateSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceTimeSupported,
{ "deviceTimeSupported", "h282.deviceTimeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_devicePresetSupported,
{ "devicePresetSupported", "h282.devicePresetSupported",
FT_NONE, BASE_NONE, NULL, 0,
"DevicePresetCapability", HFILL }},
{ &hf_h282_irisModeSupported,
{ "irisModeSupported", "h282.irisModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusModeSupported,
{ "focusModeSupported", "h282.focusModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_pointingModeSupported,
{ "pointingModeSupported", "h282.pointingModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraLensSupported,
{ "cameraLensSupported", "h282.cameraLensSupported",
FT_NONE, BASE_NONE, NULL, 0,
"CameraLensCapability", HFILL }},
{ &hf_h282_cameraFilterSupported,
{ "cameraFilterSupported", "h282.cameraFilterSupported",
FT_NONE, BASE_NONE, NULL, 0,
"CameraFilterCapability", HFILL }},
{ &hf_h282_homePositionSupported,
{ "homePositionSupported", "h282.homePositionSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_externalCameraLightSupported,
{ "externalCameraLightSupported", "h282.externalCameraLightSupported",
FT_NONE, BASE_NONE, NULL, 0,
"ExternalCameraLightCapability", HFILL }},
{ &hf_h282_clearCameraLensSupported,
{ "clearCameraLensSupported", "h282.clearCameraLensSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraPanSpeedSupported,
{ "cameraPanSpeedSupported", "h282.cameraPanSpeedSupported",
FT_NONE, BASE_NONE, NULL, 0,
"CameraPanSpeedCapability", HFILL }},
{ &hf_h282_cameraTiltSpeedSupported,
{ "cameraTiltSpeedSupported", "h282.cameraTiltSpeedSupported",
FT_NONE, BASE_NONE, NULL, 0,
"CameraTiltSpeedCapability", HFILL }},
{ &hf_h282_backLightModeSupported,
{ "backLightModeSupported", "h282.backLightModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_backLightSettingSupported,
{ "backLightSettingSupported", "h282.backLightSettingSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxBacklight", HFILL }},
{ &hf_h282_whiteBalanceSettingSupported,
{ "whiteBalanceSettingSupported", "h282.whiteBalanceSettingSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxWhiteBalance", HFILL }},
{ &hf_h282_whiteBalanceModeSupported,
{ "whiteBalanceModeSupported", "h282.whiteBalanceModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_calibrateWhiteBalanceSupported,
{ "calibrateWhiteBalanceSupported", "h282.calibrateWhiteBalanceSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusImageSupported,
{ "focusImageSupported", "h282.focusImageSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_captureImageSupported,
{ "captureImageSupported", "h282.captureImageSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_panContinuousSupported,
{ "panContinuousSupported", "h282.panContinuousSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_tiltContinuousSupported,
{ "tiltContinuousSupported", "h282.tiltContinuousSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_zoomContinuousSupported,
{ "zoomContinuousSupported", "h282.zoomContinuousSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusContinuousSupported,
{ "focusContinuousSupported", "h282.focusContinuousSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_irisContinuousSupported,
{ "irisContinuousSupported", "h282.irisContinuousSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_zoomPositionSupported,
{ "zoomPositionSupported", "h282.zoomPositionSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MinZoomPositionSetSize", HFILL }},
{ &hf_h282_focusPositionSupported,
{ "focusPositionSupported", "h282.focusPositionSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MinFocusPositionStepSize", HFILL }},
{ &hf_h282_irisPositionSupported,
{ "irisPositionSupported", "h282.irisPositionSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MinIrisPositionStepSize", HFILL }},
{ &hf_h282_panPositionSupported,
{ "panPositionSupported", "h282.panPositionSupported",
FT_NONE, BASE_NONE, NULL, 0,
"PanPositionCapability", HFILL }},
{ &hf_h282_tiltPositionSupported,
{ "tiltPositionSupported", "h282.tiltPositionSupported",
FT_NONE, BASE_NONE, NULL, 0,
"TiltPositionCapability", HFILL }},
{ &hf_h282_zoomMagnificationSupported,
{ "zoomMagnificationSupported", "h282.zoomMagnificationSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MinZoomMagnificationStepSize", HFILL }},
{ &hf_h282_panViewSupported,
{ "panViewSupported", "h282.panViewSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_tiltViewSupported,
{ "tiltViewSupported", "h282.tiltViewSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_selectSlideSupported,
{ "selectSlideSupported", "h282.selectSlideSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxNumberOfSlides", HFILL }},
{ &hf_h282_selectNextSlideSupported,
{ "selectNextSlideSupported", "h282.selectNextSlideSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_slideShowModeSupported,
{ "slideShowModeSupported", "h282.slideShowModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_playSlideShowSupported,
{ "playSlideShowSupported", "h282.playSlideShowSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setSlideDisplayTimeSupported,
{ "setSlideDisplayTimeSupported", "h282.setSlideDisplayTimeSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxSlideDisplayTime", HFILL }},
{ &hf_h282_continuousRewindSupported,
{ "continuousRewindSupported", "h282.continuousRewindSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_continuousFastForwardSupported,
{ "continuousFastForwardSupported", "h282.continuousFastForwardSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_searchBackwardsSupported,
{ "searchBackwardsSupported", "h282.searchBackwardsSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_searchForwardsSupported,
{ "searchForwardsSupported", "h282.searchForwardsSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_pauseSupported,
{ "pauseSupported", "h282.pauseSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_selectProgramSupported,
{ "selectProgramSupported", "h282.selectProgramSupported",
FT_UINT32, BASE_DEC, NULL, 0,
"MaxNumberOfPrograms", HFILL }},
{ &hf_h282_nextProgramSupported,
{ "nextProgramSupported", "h282.nextProgramSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_gotoNormalPlayTimePointSupported,
{ "gotoNormalPlayTimePointSupported", "h282.gotoNormalPlayTimePointSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_readStreamPlayerStateSupported,
{ "readStreamPlayerStateSupported", "h282.readStreamPlayerStateSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_readProgramDurationSupported,
{ "readProgramDurationSupported", "h282.readProgramDurationSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_continuousPlayBackModeSupported,
{ "continuousPlayBackModeSupported", "h282.continuousPlayBackModeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_playbackSpeedSupported,
{ "playbackSpeedSupported", "h282.playbackSpeedSupported",
FT_NONE, BASE_NONE, NULL, 0,
"PlayBackSpeedCapability", HFILL }},
{ &hf_h282_playSupported,
{ "playSupported", "h282.playSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setAudioOutputStateSupported,
{ "setAudioOutputStateSupported", "h282.setAudioOutputStateSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_playToNormalPlayTimePointSupported,
{ "playToNormalPlayTimePointSupported", "h282.playToNormalPlayTimePointSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_recordSupported,
{ "recordSupported", "h282.recordSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_recordForDurationSupported,
{ "recordForDurationSupported", "h282.recordForDurationSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_configurableVideoInputsSupported,
{ "configurableVideoInputsSupported", "h282.configurableVideoInputsSupported",
FT_NONE, BASE_NONE, NULL, 0,
"VideoInputsCapability", HFILL }},
{ &hf_h282_videoInputsSupported,
{ "videoInputsSupported", "h282.videoInputsSupported",
FT_NONE, BASE_NONE, NULL, 0,
"VideoInputsCapability", HFILL }},
{ &hf_h282_configurableAudioInputsSupported,
{ "configurableAudioInputsSupported", "h282.configurableAudioInputsSupported",
FT_NONE, BASE_NONE, NULL, 0,
"AudioInputsCapability", HFILL }},
{ &hf_h282_audioInputsSupported,
{ "audioInputsSupported", "h282.audioInputsSupported",
FT_NONE, BASE_NONE, NULL, 0,
"AudioInputsCapability", HFILL }},
{ &hf_h282_deviceLockStateChangedSupported,
{ "deviceLockStateChangedSupported", "h282.deviceLockStateChangedSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceAvailabilityChangedSupported,
{ "deviceAvailabilityChangedSupported", "h282.deviceAvailabilityChangedSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraPannedToLimitSupported,
{ "cameraPannedToLimitSupported", "h282.cameraPannedToLimitSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraTiltedToLimitSupported,
{ "cameraTiltedToLimitSupported", "h282.cameraTiltedToLimitSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraZoomedToLimitSupported,
{ "cameraZoomedToLimitSupported", "h282.cameraZoomedToLimitSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_cameraFocusedToLimitSupported,
{ "cameraFocusedToLimitSupported", "h282.cameraFocusedToLimitSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_autoSlideShowFinishedSupported,
{ "autoSlideShowFinishedSupported", "h282.autoSlideShowFinishedSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_streamPlayerStateChangeSupported,
{ "streamPlayerStateChangeSupported", "h282.streamPlayerStateChangeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_streamPlayerProgramChangeSupported,
{ "streamPlayerProgramChangeSupported", "h282.streamPlayerProgramChangeSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_nonStandardAttributeSupported,
{ "nonStandardAttributeSupported", "h282.nonStandardAttributeSupported",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h282_active,
{ "active", "h282.active",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_inactive,
{ "inactive", "h282.inactive",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_day,
{ "day", "h282.day",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_month,
{ "month", "h282.month",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_year,
{ "year", "h282.year",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_hour,
{ "hour", "h282.hour",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_minute,
{ "minute", "h282.minute",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_mode,
{ "mode", "h282.mode",
FT_UINT32, BASE_DEC, VALS(h282_T_mode_vals), 0,
NULL, HFILL }},
{ &hf_h282_store,
{ "store", "h282.store",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_activate,
{ "activate", "h282.activate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_manual,
{ "manual", "h282.manual",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_auto,
{ "auto", "h282.auto",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_toggle,
{ "toggle", "h282.toggle",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_none,
{ "none", "h282.none",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_panDirection,
{ "panDirection", "h282.panDirection",
FT_UINT32, BASE_DEC, VALS(h282_T_panDirection_vals), 0,
NULL, HFILL }},
{ &hf_h282_left,
{ "left", "h282.left",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_right,
{ "right", "h282.right",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_stop,
{ "stop", "h282.stop",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_continue,
{ "continue", "h282.continue",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_timeOut,
{ "timeOut", "h282.timeOut",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_50_1000", HFILL }},
{ &hf_h282_tiltDirection,
{ "tiltDirection", "h282.tiltDirection",
FT_UINT32, BASE_DEC, VALS(h282_T_tiltDirection_vals), 0,
NULL, HFILL }},
{ &hf_h282_up,
{ "up", "h282.up",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_down,
{ "down", "h282.down",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_zoomDirection,
{ "zoomDirection", "h282.zoomDirection",
FT_UINT32, BASE_DEC, VALS(h282_T_zoomDirection_vals), 0,
NULL, HFILL }},
{ &hf_h282_telescopic,
{ "telescopic", "h282.telescopic",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_wide,
{ "wide", "h282.wide",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusDirection,
{ "focusDirection", "h282.focusDirection",
FT_UINT32, BASE_DEC, VALS(h282_T_focusDirection_vals), 0,
NULL, HFILL }},
{ &hf_h282_near,
{ "near", "h282.near",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_far,
{ "far", "h282.far",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_relative,
{ "relative", "h282.relative",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_absolute,
{ "absolute", "h282.absolute",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_zoomPosition,
{ "zoomPosition", "h282.zoomPosition",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_positioningMode,
{ "positioningMode", "h282.positioningMode",
FT_UINT32, BASE_DEC, VALS(h282_PositioningMode_vals), 0,
NULL, HFILL }},
{ &hf_h282_focusPosition,
{ "focusPosition", "h282.focusPosition",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_irisPosition,
{ "irisPosition", "h282.irisPosition",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_panPosition,
{ "panPosition", "h282.panPosition",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_tiltPosition,
{ "tiltPosition", "h282.tiltPosition",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_next,
{ "next", "h282.next",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_previous,
{ "previous", "h282.previous",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_start,
{ "start", "h282.start",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_pause,
{ "pause", "h282.pause",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_hours,
{ "hours", "h282.hours",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_24", HFILL }},
{ &hf_h282_minutes,
{ "minutes", "h282.minutes",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_59", HFILL }},
{ &hf_h282_seconds,
{ "seconds", "h282.seconds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_59", HFILL }},
{ &hf_h282_microseconds,
{ "microseconds", "h282.microseconds",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_99999", HFILL }},
{ &hf_h282_scaleFactor,
{ "scaleFactor", "h282.scaleFactor",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_10_1000", HFILL }},
{ &hf_h282_multiplyFactor,
{ "multiplyFactor", "h282.multiplyFactor",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_inputDevices,
{ "inputDevices", "h282.inputDevices",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_inputDevices_item,
{ "inputDevices item", "h282.inputDevices_item",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setDeviceState,
{ "setDeviceState", "h282.setDeviceState",
FT_UINT32, BASE_DEC, VALS(h282_DeviceState_vals), 0,
"DeviceState", HFILL }},
{ &hf_h282_setDeviceDate,
{ "setDeviceDate", "h282.setDeviceDate",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceDate", HFILL }},
{ &hf_h282_setDeviceTime,
{ "setDeviceTime", "h282.setDeviceTime",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceTime", HFILL }},
{ &hf_h282_setDevicePreset,
{ "setDevicePreset", "h282.setDevicePreset",
FT_NONE, BASE_NONE, NULL, 0,
"DevicePreset", HFILL }},
{ &hf_h282_setIrisMode,
{ "setIrisMode", "h282.setIrisMode",
FT_UINT32, BASE_DEC, VALS(h282_Mode_vals), 0,
"Mode", HFILL }},
{ &hf_h282_setFocusMode,
{ "setFocusMode", "h282.setFocusMode",
FT_UINT32, BASE_DEC, VALS(h282_Mode_vals), 0,
"Mode", HFILL }},
{ &hf_h282_setBackLightMode,
{ "setBackLightMode", "h282.setBackLightMode",
FT_UINT32, BASE_DEC, VALS(h282_Mode_vals), 0,
"Mode", HFILL }},
{ &hf_h282_setPointingMode,
{ "setPointingMode", "h282.setPointingMode",
FT_UINT32, BASE_DEC, VALS(h282_PointingToggle_vals), 0,
"PointingToggle", HFILL }},
{ &hf_h282_selectCameraLens,
{ "selectCameraLens", "h282.selectCameraLens",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraLensNumber", HFILL }},
{ &hf_h282_selectCameraFilter,
{ "selectCameraFilter", "h282.selectCameraFilter",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraFilterNumber", HFILL }},
{ &hf_h282_gotoHomePosition,
{ "gotoHomePosition", "h282.gotoHomePosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_selectExternalLight,
{ "selectExternalLight", "h282.selectExternalLight",
FT_UINT32, BASE_DEC, VALS(h282_SelectExternalLight_vals), 0,
NULL, HFILL }},
{ &hf_h282_clearCameraLens,
{ "clearCameraLens", "h282.clearCameraLens",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setCameraPanSpeed,
{ "setCameraPanSpeed", "h282.setCameraPanSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraPanSpeed", HFILL }},
{ &hf_h282_setCameraTiltSpeed,
{ "setCameraTiltSpeed", "h282.setCameraTiltSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraTiltSpeed", HFILL }},
{ &hf_h282_setBackLight,
{ "setBackLight", "h282.setBackLight",
FT_UINT32, BASE_DEC, NULL, 0,
"BackLight", HFILL }},
{ &hf_h282_setWhiteBalance,
{ "setWhiteBalance", "h282.setWhiteBalance",
FT_UINT32, BASE_DEC, NULL, 0,
"WhiteBalance", HFILL }},
{ &hf_h282_setWhiteBalanceMode,
{ "setWhiteBalanceMode", "h282.setWhiteBalanceMode",
FT_UINT32, BASE_DEC, VALS(h282_Mode_vals), 0,
"Mode", HFILL }},
{ &hf_h282_calibrateWhiteBalance,
{ "calibrateWhiteBalance", "h282.calibrateWhiteBalance",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusImage,
{ "focusImage", "h282.focusImage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_captureImage,
{ "captureImage", "h282.captureImage",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_panContinuous,
{ "panContinuous", "h282.panContinuous",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_tiltContinuous,
{ "tiltContinuous", "h282.tiltContinuous",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_zoomContinuous,
{ "zoomContinuous", "h282.zoomContinuous",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_focusContinuous,
{ "focusContinuous", "h282.focusContinuous",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setZoomPosition,
{ "setZoomPosition", "h282.setZoomPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setFocusPosition,
{ "setFocusPosition", "h282.setFocusPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setIrisPosition,
{ "setIrisPosition", "h282.setIrisPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setPanPosition,
{ "setPanPosition", "h282.setPanPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setTiltPosition,
{ "setTiltPosition", "h282.setTiltPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_setZoomMagnification,
{ "setZoomMagnification", "h282.setZoomMagnification",
FT_UINT32, BASE_DEC, NULL, 0,
"ZoomMagnification", HFILL }},
{ &hf_h282_setPanView,
{ "setPanView", "h282.setPanView",
FT_INT32, BASE_DEC, NULL, 0,
"PanView", HFILL }},
{ &hf_h282_setTiltView,
{ "setTiltView", "h282.setTiltView",
FT_INT32, BASE_DEC, NULL, 0,
"TiltView", HFILL }},
{ &hf_h282_selectSlide,
{ "selectSlide", "h282.selectSlide",
FT_UINT32, BASE_DEC, NULL, 0,
"SlideNumber", HFILL }},
{ &hf_h282_selectNextSlide,
{ "selectNextSlide", "h282.selectNextSlide",
FT_UINT32, BASE_DEC, VALS(h282_SelectDirection_vals), 0,
"SelectDirection", HFILL }},
{ &hf_h282_playAutoSlideShow,
{ "playAutoSlideShow", "h282.playAutoSlideShow",
FT_UINT32, BASE_DEC, VALS(h282_AutoSlideShowControl_vals), 0,
"AutoSlideShowControl", HFILL }},
{ &hf_h282_setAutoSlideDisplayTime,
{ "setAutoSlideDisplayTime", "h282.setAutoSlideDisplayTime",
FT_UINT32, BASE_DEC, NULL, 0,
"AutoSlideDisplayTime", HFILL }},
{ &hf_h282_continuousRewindControl,
{ "continuousRewindControl", "h282.continuousRewindControl",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_continuousFastForwardControl,
{ "continuousFastForwardControl", "h282.continuousFastForwardControl",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_searchBackwardsControl,
{ "searchBackwardsControl", "h282.searchBackwardsControl",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_searchForwardsControl,
{ "searchForwardsControl", "h282.searchForwardsControl",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_pause_01,
{ "pause", "h282.pause",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_selectProgram,
{ "selectProgram", "h282.selectProgram",
FT_UINT32, BASE_DEC, NULL, 0,
"ProgramNumber", HFILL }},
{ &hf_h282_nextProgramSelect,
{ "nextProgramSelect", "h282.nextProgramSelect",
FT_UINT32, BASE_DEC, VALS(h282_SelectDirection_vals), 0,
"SelectDirection", HFILL }},
{ &hf_h282_gotoNormalPlayTimePoint,
{ "gotoNormalPlayTimePoint", "h282.gotoNormalPlayTimePoint",
FT_NONE, BASE_NONE, NULL, 0,
"ProgramDuration", HFILL }},
{ &hf_h282_continuousPlayBackMode,
{ "continuousPlayBackMode", "h282.continuousPlayBackMode",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_setPlaybackSpeed,
{ "setPlaybackSpeed", "h282.setPlaybackSpeed",
FT_NONE, BASE_NONE, NULL, 0,
"PlaybackSpeed", HFILL }},
{ &hf_h282_play,
{ "play", "h282.play",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_setAudioOutputMute,
{ "setAudioOutputMute", "h282.setAudioOutputMute",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_playToNormalPlayTimePoint,
{ "playToNormalPlayTimePoint", "h282.playToNormalPlayTimePoint",
FT_NONE, BASE_NONE, NULL, 0,
"ProgramDuration", HFILL }},
{ &hf_h282_record,
{ "record", "h282.record",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_recordForDuration,
{ "recordForDuration", "h282.recordForDuration",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_configureVideoInputs,
{ "configureVideoInputs", "h282.configureVideoInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_configureAudioInputs,
{ "configureAudioInputs", "h282.configureAudioInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_nonStandardControl,
{ "nonStandardControl", "h282.nonStandardControl",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h282_getDeviceState,
{ "getDeviceState", "h282.getDeviceState",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getDeviceDate,
{ "getDeviceDate", "h282.getDeviceDate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getDeviceTime,
{ "getDeviceTime", "h282.getDeviceTime",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getdevicePreset,
{ "getdevicePreset", "h282.getdevicePreset",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getIrisMode,
{ "getIrisMode", "h282.getIrisMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getFocusMode,
{ "getFocusMode", "h282.getFocusMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getBacklightMode,
{ "getBacklightMode", "h282.getBacklightMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getPointingMode,
{ "getPointingMode", "h282.getPointingMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getCameraLens,
{ "getCameraLens", "h282.getCameraLens",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getCameraFilter,
{ "getCameraFilter", "h282.getCameraFilter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getExternalLight,
{ "getExternalLight", "h282.getExternalLight",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getCameraPanSpeed,
{ "getCameraPanSpeed", "h282.getCameraPanSpeed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getCameraTiltSpeed,
{ "getCameraTiltSpeed", "h282.getCameraTiltSpeed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getBackLightMode,
{ "getBackLightMode", "h282.getBackLightMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getBackLight,
{ "getBackLight", "h282.getBackLight",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getWhiteBalance,
{ "getWhiteBalance", "h282.getWhiteBalance",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getWhiteBalanceMode,
{ "getWhiteBalanceMode", "h282.getWhiteBalanceMode",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getZoomPosition,
{ "getZoomPosition", "h282.getZoomPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getFocusPosition,
{ "getFocusPosition", "h282.getFocusPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getIrisPosition,
{ "getIrisPosition", "h282.getIrisPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getPanPosition,
{ "getPanPosition", "h282.getPanPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getTiltPosition,
{ "getTiltPosition", "h282.getTiltPosition",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getSelectedSlide,
{ "getSelectedSlide", "h282.getSelectedSlide",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getAutoSlideDisplayTime,
{ "getAutoSlideDisplayTime", "h282.getAutoSlideDisplayTime",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getSelectedProgram,
{ "getSelectedProgram", "h282.getSelectedProgram",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getStreamPlayerState,
{ "getStreamPlayerState", "h282.getStreamPlayerState",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getCurrentProgramDuration,
{ "getCurrentProgramDuration", "h282.getCurrentProgramDuration",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getPlaybackSpeed,
{ "getPlaybackSpeed", "h282.getPlaybackSpeed",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getAudioOutputState,
{ "getAudioOutputState", "h282.getAudioOutputState",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getConfigurableVideoInputs,
{ "getConfigurableVideoInputs", "h282.getConfigurableVideoInputs",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getVideoInputs,
{ "getVideoInputs", "h282.getVideoInputs",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getConfigurableAudioInputs,
{ "getConfigurableAudioInputs", "h282.getConfigurableAudioInputs",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getAudioInputs,
{ "getAudioInputs", "h282.getAudioInputs",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_getNonStandardStatus,
{ "getNonStandardStatus", "h282.getNonStandardStatus",
FT_UINT32, BASE_DEC, VALS(h282_NonStandardIdentifier_vals), 0,
"NonStandardIdentifier", HFILL }},
{ &hf_h282_deviceState,
{ "deviceState", "h282.deviceState",
FT_UINT32, BASE_DEC, VALS(h282_DeviceState_vals), 0,
NULL, HFILL }},
{ &hf_h282_unknown,
{ "unknown", "h282.unknown",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_currentDay,
{ "currentDay", "h282.currentDay",
FT_UINT32, BASE_DEC, VALS(h282_T_currentDay_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentMonth,
{ "currentMonth", "h282.currentMonth",
FT_UINT32, BASE_DEC, VALS(h282_T_currentMonth_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentYear,
{ "currentYear", "h282.currentYear",
FT_UINT32, BASE_DEC, VALS(h282_T_currentYear_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentHour,
{ "currentHour", "h282.currentHour",
FT_UINT32, BASE_DEC, VALS(h282_T_currentHour_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentMinute,
{ "currentMinute", "h282.currentMinute",
FT_UINT32, BASE_DEC, VALS(h282_T_currentMinute_vals), 0,
NULL, HFILL }},
{ &hf_h282_preset,
{ "preset", "h282.preset",
FT_UINT32, BASE_DEC, NULL, 0,
"PresetNumber", HFILL }},
{ &hf_h282_mode_01,
{ "mode", "h282.mode",
FT_UINT32, BASE_DEC, VALS(h282_Mode_vals), 0,
NULL, HFILL }},
{ &hf_h282_automatic,
{ "automatic", "h282.automatic",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lensNumber_01,
{ "lensNumber", "h282.lensNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraLensNumber", HFILL }},
{ &hf_h282_lensNumber_02,
{ "lensNumber", "h282.lensNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraFilterNumber", HFILL }},
{ &hf_h282_speed,
{ "speed", "h282.speed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraPanSpeed", HFILL }},
{ &hf_h282_speed_01,
{ "speed", "h282.speed",
FT_UINT32, BASE_DEC, NULL, 0,
"CameraTiltSpeed", HFILL }},
{ &hf_h282_backLight,
{ "backLight", "h282.backLight",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_whiteBalance,
{ "whiteBalance", "h282.whiteBalance",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_h282_slide,
{ "slide", "h282.slide",
FT_UINT32, BASE_DEC, NULL, 0,
"SlideNumber", HFILL }},
{ &hf_h282_time,
{ "time", "h282.time",
FT_UINT32, BASE_DEC, NULL, 0,
"AutoSlideDisplayTime", HFILL }},
{ &hf_h282_program,
{ "program", "h282.program",
FT_UINT32, BASE_DEC, NULL, 0,
"ProgramNumber", HFILL }},
{ &hf_h282_state,
{ "state", "h282.state",
FT_UINT32, BASE_DEC, VALS(h282_StreamPlayerState_vals), 0,
"StreamPlayerState", HFILL }},
{ &hf_h282_speed_02,
{ "speed", "h282.speed",
FT_NONE, BASE_NONE, NULL, 0,
"PlaybackSpeed", HFILL }},
{ &hf_h282_mute,
{ "mute", "h282.mute",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_currentdeviceState,
{ "currentdeviceState", "h282.currentdeviceState",
FT_UINT32, BASE_DEC, VALS(h282_CurrentDeviceState_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentDeviceDate,
{ "currentDeviceDate", "h282.currentDeviceDate",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_currentDeviceTime,
{ "currentDeviceTime", "h282.currentDeviceTime",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_currentDevicePreset,
{ "currentDevicePreset", "h282.currentDevicePreset",
FT_UINT32, BASE_DEC, VALS(h282_CurrentDevicePreset_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentIrisMode,
{ "currentIrisMode", "h282.currentIrisMode",
FT_UINT32, BASE_DEC, VALS(h282_CurrentMode_vals), 0,
"CurrentMode", HFILL }},
{ &hf_h282_currentFocusMode,
{ "currentFocusMode", "h282.currentFocusMode",
FT_UINT32, BASE_DEC, VALS(h282_CurrentMode_vals), 0,
"CurrentMode", HFILL }},
{ &hf_h282_currentBackLightMode,
{ "currentBackLightMode", "h282.currentBackLightMode",
FT_UINT32, BASE_DEC, VALS(h282_CurrentMode_vals), 0,
"CurrentMode", HFILL }},
{ &hf_h282_currentPointingMode,
{ "currentPointingMode", "h282.currentPointingMode",
FT_UINT32, BASE_DEC, VALS(h282_CurrentPointingMode_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentCameraLens,
{ "currentCameraLens", "h282.currentCameraLens",
FT_UINT32, BASE_DEC, VALS(h282_CurrentCameraLensNumber_vals), 0,
"CurrentCameraLensNumber", HFILL }},
{ &hf_h282_currentCameraFilter,
{ "currentCameraFilter", "h282.currentCameraFilter",
FT_UINT32, BASE_DEC, VALS(h282_CurrentCameraFilterNumber_vals), 0,
"CurrentCameraFilterNumber", HFILL }},
{ &hf_h282_currentExternalLight,
{ "currentExternalLight", "h282.currentExternalLight",
FT_UINT32, BASE_DEC, VALS(h282_CurrentExternalLight_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentCameraPanSpeed,
{ "currentCameraPanSpeed", "h282.currentCameraPanSpeed",
FT_UINT32, BASE_DEC, VALS(h282_CurrentCameraPanSpeed_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentCameraTiltSpeed,
{ "currentCameraTiltSpeed", "h282.currentCameraTiltSpeed",
FT_UINT32, BASE_DEC, VALS(h282_CurrentCameraTiltSpeed_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentBackLight,
{ "currentBackLight", "h282.currentBackLight",
FT_UINT32, BASE_DEC, VALS(h282_CurrentBackLight_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentWhiteBalance,
{ "currentWhiteBalance", "h282.currentWhiteBalance",
FT_UINT32, BASE_DEC, VALS(h282_CurrentWhiteBalance_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentWhiteBalanceMode,
{ "currentWhiteBalanceMode", "h282.currentWhiteBalanceMode",
FT_UINT32, BASE_DEC, VALS(h282_CurrentMode_vals), 0,
"CurrentMode", HFILL }},
{ &hf_h282_currentZoomPosition,
{ "currentZoomPosition", "h282.currentZoomPosition",
FT_UINT32, BASE_DEC, VALS(h282_CurrentZoomPosition_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentFocusPosition,
{ "currentFocusPosition", "h282.currentFocusPosition",
FT_UINT32, BASE_DEC, VALS(h282_CurrentFocusPosition_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentIrisPosition,
{ "currentIrisPosition", "h282.currentIrisPosition",
FT_UINT32, BASE_DEC, VALS(h282_CurrentIrisPosition_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentPanPosition,
{ "currentPanPosition", "h282.currentPanPosition",
FT_UINT32, BASE_DEC, VALS(h282_CurrentPanPosition_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentTiltPosition,
{ "currentTiltPosition", "h282.currentTiltPosition",
FT_UINT32, BASE_DEC, VALS(h282_CurrentTiltPosition_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentSlide,
{ "currentSlide", "h282.currentSlide",
FT_UINT32, BASE_DEC, VALS(h282_CurrentSlide_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentAutoSlideDisplayTime,
{ "currentAutoSlideDisplayTime", "h282.currentAutoSlideDisplayTime",
FT_UINT32, BASE_DEC, VALS(h282_CurrentAutoSlideDisplayTime_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentSelectedProgram,
{ "currentSelectedProgram", "h282.currentSelectedProgram",
FT_UINT32, BASE_DEC, VALS(h282_CurrentSelectedProgram_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentstreamPlayerState,
{ "currentstreamPlayerState", "h282.currentstreamPlayerState",
FT_UINT32, BASE_DEC, VALS(h282_CurrentStreamPlayerState_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentProgramDuration,
{ "currentProgramDuration", "h282.currentProgramDuration",
FT_NONE, BASE_NONE, NULL, 0,
"ProgramDuration", HFILL }},
{ &hf_h282_currentPlaybackSpeed,
{ "currentPlaybackSpeed", "h282.currentPlaybackSpeed",
FT_UINT32, BASE_DEC, VALS(h282_CurrentPlaybackSpeed_vals), 0,
NULL, HFILL }},
{ &hf_h282_currentAudioOutputMute,
{ "currentAudioOutputMute", "h282.currentAudioOutputMute",
FT_UINT32, BASE_DEC, VALS(h282_CurrentAudioOutputMute_vals), 0,
NULL, HFILL }},
{ &hf_h282_configurableVideoInputs,
{ "configurableVideoInputs", "h282.configurableVideoInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_videoInputs,
{ "videoInputs", "h282.videoInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_configurableAudioInputs,
{ "configurableAudioInputs", "h282.configurableAudioInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_audioInputs,
{ "audioInputs", "h282.audioInputs",
FT_NONE, BASE_NONE, NULL, 0,
"DeviceInputs", HFILL }},
{ &hf_h282_nonStandardStatus,
{ "nonStandardStatus", "h282.nonStandardStatus",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h282_requestDeviceLockChanged,
{ "requestDeviceLockChanged", "h282.requestDeviceLockChanged",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestDeviceAvailabilityChanged,
{ "requestDeviceAvailabilityChanged", "h282.requestDeviceAvailabilityChanged",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestCameraPannedToLimit,
{ "requestCameraPannedToLimit", "h282.requestCameraPannedToLimit",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestCameraTiltedToLimit,
{ "requestCameraTiltedToLimit", "h282.requestCameraTiltedToLimit",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestCameraZoomedToLimit,
{ "requestCameraZoomedToLimit", "h282.requestCameraZoomedToLimit",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestCameraFocusedToLimit,
{ "requestCameraFocusedToLimit", "h282.requestCameraFocusedToLimit",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestAutoSlideShowFinished,
{ "requestAutoSlideShowFinished", "h282.requestAutoSlideShowFinished",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestStreamPlayerStateChange,
{ "requestStreamPlayerStateChange", "h282.requestStreamPlayerStateChange",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestStreamPlayerProgramChange,
{ "requestStreamPlayerProgramChange", "h282.requestStreamPlayerProgramChange",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestNonStandardEvent,
{ "requestNonStandardEvent", "h282.requestNonStandardEvent",
FT_UINT32, BASE_DEC, VALS(h282_NonStandardIdentifier_vals), 0,
"NonStandardIdentifier", HFILL }},
{ &hf_h282_deviceLockChanged,
{ "deviceLockChanged", "h282.deviceLockChanged",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_deviceAvailabilityChanged,
{ "deviceAvailabilityChanged", "h282.deviceAvailabilityChanged",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_cameraPannedToLimit,
{ "cameraPannedToLimit", "h282.cameraPannedToLimit",
FT_UINT32, BASE_DEC, VALS(h282_CameraPannedToLimit_vals), 0,
NULL, HFILL }},
{ &hf_h282_cameraTiltedToLimit,
{ "cameraTiltedToLimit", "h282.cameraTiltedToLimit",
FT_UINT32, BASE_DEC, VALS(h282_CameraTiltedToLimit_vals), 0,
NULL, HFILL }},
{ &hf_h282_cameraZoomedToLimit,
{ "cameraZoomedToLimit", "h282.cameraZoomedToLimit",
FT_UINT32, BASE_DEC, VALS(h282_CameraZoomedToLimit_vals), 0,
NULL, HFILL }},
{ &hf_h282_cameraFocusedToLimit,
{ "cameraFocusedToLimit", "h282.cameraFocusedToLimit",
FT_UINT32, BASE_DEC, VALS(h282_CameraFocusedToLimit_vals), 0,
NULL, HFILL }},
{ &hf_h282_autoSlideShowFinished,
{ "autoSlideShowFinished", "h282.autoSlideShowFinished",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_streamPlayerStateChange,
{ "streamPlayerStateChange", "h282.streamPlayerStateChange",
FT_UINT32, BASE_DEC, VALS(h282_StreamPlayerState_vals), 0,
"StreamPlayerState", HFILL }},
{ &hf_h282_streamPlayerProgramChange,
{ "streamPlayerProgramChange", "h282.streamPlayerProgramChange",
FT_UINT32, BASE_DEC, NULL, 0,
"ProgramNumber", HFILL }},
{ &hf_h282_nonStandardEvent,
{ "nonStandardEvent", "h282.nonStandardEvent",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h282_requestHandle,
{ "requestHandle", "h282.requestHandle",
FT_UINT32, BASE_DEC, NULL, 0,
"Handle", HFILL }},
{ &hf_h282_streamIdentifier,
{ "streamIdentifier", "h282.streamIdentifier",
FT_UINT32, BASE_DEC, NULL, 0,
"StreamID", HFILL }},
{ &hf_h282_result,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_vals), 0,
NULL, HFILL }},
{ &hf_h282_successful,
{ "successful", "h282.successful",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_requestDenied,
{ "requestDenied", "h282.requestDenied",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceUnavailable,
{ "deviceUnavailable", "h282.deviceUnavailable",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_invalidStreamID,
{ "invalidStreamID", "h282.invalidStreamID",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_currentDeviceIsLocked,
{ "currentDeviceIsLocked", "h282.currentDeviceIsLocked",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceIncompatible,
{ "deviceIncompatible", "h282.deviceIncompatible",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_sourceEventNotify,
{ "sourceEventNotify", "h282.sourceEventNotify",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_result_01,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_01_vals), 0,
"T_result_01", HFILL }},
{ &hf_h282_eventsNotSupported,
{ "eventsNotSupported", "h282.eventsNotSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceAttributeList,
{ "deviceAttributeList", "h282.deviceAttributeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_DeviceAttribute", HFILL }},
{ &hf_h282_deviceAttributeList_item,
{ "DeviceAttribute", "h282.DeviceAttribute",
FT_UINT32, BASE_DEC, VALS(h282_DeviceAttribute_vals), 0,
NULL, HFILL }},
{ &hf_h282_result_02,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_02_vals), 0,
"T_result_02", HFILL }},
{ &hf_h282_unknownDevice,
{ "unknownDevice", "h282.unknownDevice",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lockFlag,
{ "lockFlag", "h282.lockFlag",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_h282_result_03,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_03_vals), 0,
"T_result_03", HFILL }},
{ &hf_h282_lockingNotSupported,
{ "lockingNotSupported", "h282.lockingNotSupported",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceAlreadyLocked,
{ "deviceAlreadyLocked", "h282.deviceAlreadyLocked",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_result_04,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_04_vals), 0,
"T_result_04", HFILL }},
{ &hf_h282_lockRequired,
{ "lockRequired", "h282.lockRequired",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_lockNotRequired,
{ "lockNotRequired", "h282.lockNotRequired",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_controlAttributeList,
{ "controlAttributeList", "h282.controlAttributeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_8_OF_ControlAttribute", HFILL }},
{ &hf_h282_controlAttributeList_item,
{ "ControlAttribute", "h282.ControlAttribute",
FT_UINT32, BASE_DEC, VALS(h282_ControlAttribute_vals), 0,
NULL, HFILL }},
{ &hf_h282_statusAttributeIdentifierList,
{ "statusAttributeIdentifierList", "h282.statusAttributeIdentifierList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_16_OF_StatusAttributeIdentifier", HFILL }},
{ &hf_h282_statusAttributeIdentifierList_item,
{ "StatusAttributeIdentifier", "h282.StatusAttributeIdentifier",
FT_UINT32, BASE_DEC, VALS(h282_StatusAttributeIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h282_statusAttributeList,
{ "statusAttributeList", "h282.statusAttributeList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_16_OF_StatusAttribute", HFILL }},
{ &hf_h282_statusAttributeList_item,
{ "StatusAttribute", "h282.StatusAttribute",
FT_UINT32, BASE_DEC, VALS(h282_StatusAttribute_vals), 0,
NULL, HFILL }},
{ &hf_h282_result_05,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_05_vals), 0,
"T_result_05", HFILL }},
{ &hf_h282_deviceAttributeError,
{ "deviceAttributeError", "h282.deviceAttributeError",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceEventIdentifierList,
{ "deviceEventIdentifierList", "h282.deviceEventIdentifierList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_DeviceEventIdentifier", HFILL }},
{ &hf_h282_deviceEventIdentifierList_item,
{ "DeviceEventIdentifier", "h282.DeviceEventIdentifier",
FT_UINT32, BASE_DEC, VALS(h282_DeviceEventIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_h282_result_06,
{ "result", "h282.result",
FT_UINT32, BASE_DEC, VALS(h282_T_result_06_vals), 0,
"T_result_06", HFILL }},
{ &hf_h282_deviceEventList,
{ "deviceEventList", "h282.deviceEventList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_8_OF_DeviceEvent", HFILL }},
{ &hf_h282_deviceEventList_item,
{ "DeviceEvent", "h282.DeviceEvent",
FT_UINT32, BASE_DEC, VALS(h282_DeviceEvent_vals), 0,
NULL, HFILL }},
{ &hf_h282_nonStandardData,
{ "nonStandardData", "h282.nonStandardData",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardParameter", HFILL }},
{ &hf_h282_request,
{ "request", "h282.request",
FT_UINT32, BASE_DEC, VALS(h282_RequestPDU_vals), 0,
"RequestPDU", HFILL }},
{ &hf_h282_response,
{ "response", "h282.response",
FT_UINT32, BASE_DEC, VALS(h282_ResponsePDU_vals), 0,
"ResponsePDU", HFILL }},
{ &hf_h282_indication,
{ "indication", "h282.indication",
FT_UINT32, BASE_DEC, VALS(h282_IndicationPDU_vals), 0,
"IndicationPDU", HFILL }},
{ &hf_h282_sourceSelectRequest,
{ "sourceSelectRequest", "h282.sourceSelectRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_sourceEventsRequest,
{ "sourceEventsRequest", "h282.sourceEventsRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceAttributeRequest,
{ "deviceAttributeRequest", "h282.deviceAttributeRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceLockRequest,
{ "deviceLockRequest", "h282.deviceLockRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceLockEnquireRequest,
{ "deviceLockEnquireRequest", "h282.deviceLockEnquireRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceControlRequest,
{ "deviceControlRequest", "h282.deviceControlRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceStatusEnquireRequest,
{ "deviceStatusEnquireRequest", "h282.deviceStatusEnquireRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_configureDeviceEventsRequest,
{ "configureDeviceEventsRequest", "h282.configureDeviceEventsRequest",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_nonStandardRequest,
{ "nonStandardRequest", "h282.nonStandardRequest",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardPDU", HFILL }},
{ &hf_h282_sourceSelectResponse,
{ "sourceSelectResponse", "h282.sourceSelectResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_sourceEventsResponse,
{ "sourceEventsResponse", "h282.sourceEventsResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceAttributeResponse,
{ "deviceAttributeResponse", "h282.deviceAttributeResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceLockResponse,
{ "deviceLockResponse", "h282.deviceLockResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceLockEnquireResponse,
{ "deviceLockEnquireResponse", "h282.deviceLockEnquireResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceStatusEnquireResponse,
{ "deviceStatusEnquireResponse", "h282.deviceStatusEnquireResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_configureDeviceEventsResponse,
{ "configureDeviceEventsResponse", "h282.configureDeviceEventsResponse",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_nonStandardResponse,
{ "nonStandardResponse", "h282.nonStandardResponse",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardPDU", HFILL }},
{ &hf_h282_sourceChangeEventIndication,
{ "sourceChangeEventIndication", "h282.sourceChangeEventIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceLockTerminatedIndication,
{ "deviceLockTerminatedIndication", "h282.deviceLockTerminatedIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_deviceEventNotifyIndication,
{ "deviceEventNotifyIndication", "h282.deviceEventNotifyIndication",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_h282_nonStandardIndication,
{ "nonStandardIndication", "h282.nonStandardIndication",
FT_NONE, BASE_NONE, NULL, 0,
"NonStandardPDU", HFILL }},
#line 73 "../../asn1/h282/packet-h282-template.c"
};
static gint *ett[] = {
&ett_h282,
#line 1 "../../asn1/h282/packet-h282-ettarr.c"
&ett_h282_Key,
&ett_h282_NonStandardParameter,
&ett_h282_NonStandardIdentifier,
&ett_h282_DeviceClass,
&ett_h282_DeviceProfile,
&ett_h282_StreamProfile,
&ett_h282_CapabilityID,
&ett_h282_NonCollapsingCapabilities,
&ett_h282_NonCollapsingCapabilities_item,
&ett_h282_T_applicationData,
&ett_h282_SET_SIZE_0_127_OF_DeviceProfile,
&ett_h282_SET_SIZE_0_127_OF_StreamProfile,
&ett_h282_StreamPlayerState,
&ett_h282_DevicePresetCapability,
&ett_h282_T_presetCapability,
&ett_h282_T_presetCapability_item,
&ett_h282_CameraFilterCapability,
&ett_h282_T_filterTextLabel,
&ett_h282_T_filterTextLabel_item,
&ett_h282_CameraLensCapability,
&ett_h282_T_accessoryTextLabel,
&ett_h282_T_accessoryTextLabel_item,
&ett_h282_ExternalCameraLightCapability,
&ett_h282_T_lightTextLabel,
&ett_h282_T_lightTextLabel_item,
&ett_h282_CameraPanSpeedCapability,
&ett_h282_CameraTiltSpeedCapability,
&ett_h282_PanPositionCapability,
&ett_h282_TiltPositionCapability,
&ett_h282_PlayBackSpeedCapability,
&ett_h282_T_multiplierFactors,
&ett_h282_T_divisorFactors,
&ett_h282_VideoInputsCapability,
&ett_h282_T_availableDevices,
&ett_h282_T_availableDevices_item,
&ett_h282_AudioInputsCapability,
&ett_h282_T_availableDevices_01,
&ett_h282_T_availableDevices_item_01,
&ett_h282_DeviceAttribute,
&ett_h282_DeviceState,
&ett_h282_DeviceDate,
&ett_h282_DeviceTime,
&ett_h282_DevicePreset,
&ett_h282_T_mode,
&ett_h282_Mode,
&ett_h282_PointingToggle,
&ett_h282_SelectExternalLight,
&ett_h282_PanContinuous,
&ett_h282_T_panDirection,
&ett_h282_TiltContinuous,
&ett_h282_T_tiltDirection,
&ett_h282_ZoomContinuous,
&ett_h282_T_zoomDirection,
&ett_h282_FocusContinuous,
&ett_h282_T_focusDirection,
&ett_h282_PositioningMode,
&ett_h282_SetZoomPosition,
&ett_h282_SetFocusPosition,
&ett_h282_SetIrisPosition,
&ett_h282_SetPanPosition,
&ett_h282_SetTiltPosition,
&ett_h282_SelectDirection,
&ett_h282_AutoSlideShowControl,
&ett_h282_ProgramDuration,
&ett_h282_PlaybackSpeed,
&ett_h282_RecordForDuration,
&ett_h282_DeviceInputs,
&ett_h282_T_inputDevices,
&ett_h282_T_inputDevices_item,
&ett_h282_ControlAttribute,
&ett_h282_StatusAttributeIdentifier,
&ett_h282_CurrentDeviceState,
&ett_h282_CurrentDeviceDate,
&ett_h282_T_currentDay,
&ett_h282_T_currentMonth,
&ett_h282_T_currentYear,
&ett_h282_CurrentDeviceTime,
&ett_h282_T_currentHour,
&ett_h282_T_currentMinute,
&ett_h282_CurrentDevicePreset,
&ett_h282_CurrentMode,
&ett_h282_CurrentPointingMode,
&ett_h282_CurrentCameraLensNumber,
&ett_h282_CurrentCameraFilterNumber,
&ett_h282_CurrentExternalLight,
&ett_h282_CurrentCameraPanSpeed,
&ett_h282_CurrentCameraTiltSpeed,
&ett_h282_CurrentBackLight,
&ett_h282_CurrentWhiteBalance,
&ett_h282_CurrentZoomPosition,
&ett_h282_CurrentFocusPosition,
&ett_h282_CurrentIrisPosition,
&ett_h282_CurrentPanPosition,
&ett_h282_CurrentTiltPosition,
&ett_h282_CurrentSlide,
&ett_h282_CurrentAutoSlideDisplayTime,
&ett_h282_CurrentSelectedProgram,
&ett_h282_CurrentStreamPlayerState,
&ett_h282_CurrentPlaybackSpeed,
&ett_h282_CurrentAudioOutputMute,
&ett_h282_StatusAttribute,
&ett_h282_DeviceEventIdentifier,
&ett_h282_CameraPannedToLimit,
&ett_h282_CameraTiltedToLimit,
&ett_h282_CameraZoomedToLimit,
&ett_h282_CameraFocusedToLimit,
&ett_h282_DeviceEvent,
&ett_h282_SourceSelectRequest,
&ett_h282_SourceSelectResponse,
&ett_h282_T_result,
&ett_h282_SourceEventsRequest,
&ett_h282_SourceEventsResponse,
&ett_h282_T_result_01,
&ett_h282_SourceChangeEventIndication,
&ett_h282_DeviceAttributeRequest,
&ett_h282_DeviceAttributeResponse,
&ett_h282_SET_OF_DeviceAttribute,
&ett_h282_T_result_02,
&ett_h282_DeviceLockRequest,
&ett_h282_DeviceLockResponse,
&ett_h282_T_result_03,
&ett_h282_DeviceLockEnquireRequest,
&ett_h282_DeviceLockEnquireResponse,
&ett_h282_T_result_04,
&ett_h282_DeviceLockTerminatedIndication,
&ett_h282_DeviceControlRequest,
&ett_h282_SET_SIZE_1_8_OF_ControlAttribute,
&ett_h282_DeviceStatusEnquireRequest,
&ett_h282_SET_SIZE_1_16_OF_StatusAttributeIdentifier,
&ett_h282_DeviceStatusEnquireResponse,
&ett_h282_SET_SIZE_1_16_OF_StatusAttribute,
&ett_h282_T_result_05,
&ett_h282_ConfigureDeviceEventsRequest,
&ett_h282_SET_OF_DeviceEventIdentifier,
&ett_h282_ConfigureDeviceEventsResponse,
&ett_h282_T_result_06,
&ett_h282_DeviceEventNotifyIndication,
&ett_h282_SET_SIZE_1_8_OF_DeviceEvent,
&ett_h282_NonStandardPDU,
&ett_h282_RDCPDU,
&ett_h282_RequestPDU,
&ett_h282_ResponsePDU,
&ett_h282_IndicationPDU,
#line 79 "../../asn1/h282/packet-h282-template.c"
};
proto_h282 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h282, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_h282, proto_h282);
new_register_dissector(PFNAME".device_list", dissect_NonCollapsingCapabilities_PDU, proto_h282);
}
void proto_reg_handoff_h282(void)
{
}
