static int
dissect_lcsap_Criticality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_ProcedureCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &ProcedureCode, FALSE);
#line 98 "../../asn1/lcsap/lcsap.cnf"
{
guint8 tmp = tvb_get_guint8(tvb, 0);
if(tmp == 0)
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%sReq",
val_to_str(ProcedureCode, lcsap_ProcedureCode_vals,
"unknown message"));
else if(tmp == 32)
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%sResp",
val_to_str(ProcedureCode, lcsap_ProcedureCode_vals,
"unknown message"));
else
col_add_fstr(actx->pinfo->cinfo, COL_INFO, "%s",
val_to_str(ProcedureCode, lcsap_ProcedureCode_vals,
"unknown message"));
}
if (ProcedureCode != 0)
{
_pro_code.code = ProcedureCode;
actx->pinfo->private_data = &_pro_code;
}
return offset;
}
static int
dissect_lcsap_ProtocolExtensionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolExtensionID, FALSE);
return offset;
}
static int
dissect_lcsap_ProtocolIE_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, &ProtocolIE_ID, FALSE);
#line 50 "../../asn1/lcsap/lcsap.cnf"
if (tree) {
proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s", val_to_str(ProtocolIE_ID, VALS(lcsap_ProtocolIE_ID_vals), "unknown (%d)"));
}
return offset;
}
static int
dissect_lcsap_T_ie_field_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolIEFieldValue);
return offset;
}
static int
dissect_lcsap_ProtocolIE_Field(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_ProtocolIE_Field, ProtocolIE_Field_sequence);
return offset;
}
static int
dissect_lcsap_ProtocolIE_Container(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
0, maxProtocolIEs, FALSE);
return offset;
}
static int
dissect_lcsap_T_extensionValue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_ProtocolExtensionFieldExtensionValue);
return offset;
}
static int
dissect_lcsap_ProtocolExtensionField(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_ProtocolExtensionField, ProtocolExtensionField_sequence);
return offset;
}
static int
dissect_lcsap_ProtocolExtensionContainer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
1, maxProtocolExtensions, FALSE);
return offset;
}
static int
dissect_lcsap_APDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 71 "../../asn1/lcsap/lcsap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);
if (parameter_tvb) {
switch (PayloadType) {
case 0:
if (lpp_handle) {
call_dissector(lpp_handle, parameter_tvb, actx->pinfo, tree);
}
break;
case 1:
if (lppa_handle) {
call_dissector(lppa_handle, parameter_tvb, actx->pinfo, tree);
}
break;
default:
break;
}
}
PayloadType = -1;
return offset;
}
static int
dissect_lcsap_Accuracy_Fulfillment_Indicator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Altitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Direction_Of_Altitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Altitude_And_Direction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Altitude_And_Direction, Altitude_And_Direction_sequence);
return offset;
}
static int
dissect_lcsap_Angle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_CellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lcsap_Confidence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Correlation_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_lcsap_DegreesLatitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 210 "../../asn1/lcsap/lcsap.cnf"
guint32 degrees;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, &degrees, FALSE);
proto_item_append_text(actx->created_item, " (%.5f degrees)", (((double)degrees/8388607) * 90));
return offset;
}
static int
dissect_lcsap_DegreesLongitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 218 "../../asn1/lcsap/lcsap.cnf"
guint32 degrees;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, &degrees, FALSE);
proto_item_append_text(actx->created_item, " (%.5f degrees)", (((double)degrees/16777215) * 360));
return offset;
}
static int
dissect_lcsap_PLMN_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 164 "../../asn1/lcsap/lcsap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, &parameter_tvb);
if(tvb_length(tvb)==0)
return offset;
if (!parameter_tvb)
return offset;
dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, TRUE);
return offset;
}
static int
dissect_lcsap_E_CGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_E_CGI, E_CGI_sequence);
return offset;
}
static int
dissect_lcsap_LatitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Geographical_Coordinates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Geographical_Coordinates, Geographical_Coordinates_sequence);
return offset;
}
static int
dissect_lcsap_Uncertainty_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 202 "../../asn1/lcsap/lcsap.cnf"
guint32 uncertainty_code;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, &uncertainty_code, FALSE);
proto_item_append_text(actx->created_item, " (%.1f m)", 10 * (pow(1.1, (double)uncertainty_code) - 1));
return offset;
}
static int
dissect_lcsap_Orientation_Major_Axis(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 89U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Uncertainty_Ellipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Uncertainty_Ellipse, Uncertainty_Ellipse_sequence);
return offset;
}
static int
dissect_lcsap_Ellipsoid_Point_With_Uncertainty_Ellipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Ellipsoid_Point_With_Uncertainty_Ellipse, Ellipsoid_Point_With_Uncertainty_Ellipse_sequence);
return offset;
}
static int
dissect_lcsap_Ellipsoid_Point_With_Altitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Ellipsoid_Point_With_Altitude, Ellipsoid_Point_With_Altitude_sequence);
return offset;
}
static int
dissect_lcsap_Uncertainty_Altitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid, Ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid_sequence);
return offset;
}
static int
dissect_lcsap_Inner_Radius(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Ellipsoid_Arc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Ellipsoid_Arc, Ellipsoid_Arc_sequence);
return offset;
}
static int
dissect_lcsap_Macro_eNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
20, 20, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lcsap_Home_eNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lcsap_ENB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_ENB_ID, ENB_ID_choice,
NULL);
return offset;
}
static int
dissect_lcsap_E_SMLC_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Point(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Point, Point_sequence);
return offset;
}
static int
dissect_lcsap_Point_With_Uncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Point_With_Uncertainty, Point_With_Uncertainty_sequence);
return offset;
}
static int
dissect_lcsap_Polygon_Point(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Polygon_Point, Polygon_Point_sequence);
return offset;
}
static int
dissect_lcsap_Polygon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_Polygon, Polygon_sequence_of,
1, max_No_Of_Points, FALSE);
return offset;
}
static int
dissect_lcsap_Geographical_Area(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_Geographical_Area, Geographical_Area_choice,
NULL);
return offset;
}
static int
dissect_lcsap_Global_eNB_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Global_eNB_ID, Global_eNB_ID_sequence);
return offset;
}
static int
dissect_lcsap_GNSS_Positioning_Method_And_Usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 188 "../../asn1/lcsap/lcsap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
proto_tree_add_item(tree, hf_lcsap_gnss_pos_method, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lcsap_gnss_id, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lcsap_gnss_pos_usage, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_lcsap_GNSS_Positioning_Data_Set(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_GNSS_Positioning_Data_Set, GNSS_Positioning_Data_Set_sequence_of,
1, max_GNSS_Set, FALSE);
return offset;
}
static int
dissect_lcsap_Horizontal_Accuracy(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_INTEGER_0_359(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 359U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Horizontal_Speed_And_Bearing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Horizontal_Speed_And_Bearing, Horizontal_Speed_And_Bearing_sequence);
return offset;
}
static int
dissect_lcsap_Horizontal_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Horizontal_Velocity, Horizontal_Velocity_sequence);
return offset;
}
static int
dissect_lcsap_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Vertical_Speed_Direction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Vertical_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Vertical_Velocity, Vertical_Velocity_sequence);
return offset;
}
static int
dissect_lcsap_Horizontal_With_Vertical_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Horizontal_With_Vertical_Velocity, Horizontal_With_Vertical_Velocity_sequence);
return offset;
}
static int
dissect_lcsap_Horizontal_Velocity_With_Uncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Horizontal_Velocity_With_Uncertainty, Horizontal_Velocity_With_Uncertainty_sequence);
return offset;
}
static int
dissect_lcsap_Horizontal_With_Vertical_Velocity_And_Uncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Horizontal_With_Vertical_Velocity_And_Uncertainty, Horizontal_With_Vertical_Velocity_And_Uncertainty_sequence);
return offset;
}
static int
dissect_lcsap_IMSI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 8, FALSE, NULL);
return offset;
}
static int
dissect_lcsap_IMEI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL);
return offset;
}
static int
dissect_lcsap_Include_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Location_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Radio_Network_Layer_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Transport_Layer_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Protocol_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Misc_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_LCS_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_LCS_Cause, LCS_Cause_choice,
NULL);
return offset;
}
static int
dissect_lcsap_LCS_Client_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_LCS_Priority(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, NULL);
return offset;
}
static int
dissect_lcsap_Vertical_Requested(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Vertical_Accuracy(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_Response_Time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_LCS_QoS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_LCS_QoS, LCS_QoS_sequence);
return offset;
}
static int
dissect_lcsap_LCS_Service_Type_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lcsap_MultipleAPDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_MultipleAPDUs, MultipleAPDUs_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_lcsap_Network_Element(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_Network_Element, Network_Element_choice,
NULL);
return offset;
}
static int
dissect_lcsap_Payload_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, &PayloadType, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Positioning_Method_And_Usage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 176 "../../asn1/lcsap/lcsap.cnf"
tvbuff_t *parameter_tvb=NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
1, 1, FALSE, &parameter_tvb);
if (!parameter_tvb)
return offset;
proto_tree_add_item(tree, hf_lcsap_pos_method, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_lcsap_pos_usage, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
return offset;
}
static int
dissect_lcsap_Positioning_Data_Set(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lcsap_Positioning_Data_Set, Positioning_Data_Set_sequence_of,
1, max_Set, FALSE);
return offset;
}
static int
dissect_lcsap_Positioning_Data(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Positioning_Data, Positioning_Data_sequence);
return offset;
}
static int
dissect_lcsap_Return_Error_Type(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lcsap_Return_Error_Cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lcsap_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lcsap_UE_Positioning_Capability(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_UE_Positioning_Capability, UE_Positioning_Capability_sequence);
return offset;
}
static int
dissect_lcsap_Velocity_Estimate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_Velocity_Estimate, Velocity_Estimate_choice,
NULL);
return offset;
}
static int
dissect_lcsap_Location_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Location_Request, Location_Request_sequence);
return offset;
}
static int
dissect_lcsap_Location_Response(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Location_Response, Location_Response_sequence);
return offset;
}
static int
dissect_lcsap_Location_Abort_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Location_Abort_Request, Location_Abort_Request_sequence);
return offset;
}
static int
dissect_lcsap_Connection_Oriented_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Connection_Oriented_Information, Connection_Oriented_Information_sequence);
return offset;
}
static int
dissect_lcsap_Connectionless_Information(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 67 "../../asn1/lcsap/lcsap.cnf"
PayloadType = 1;
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Connectionless_Information, Connectionless_Information_sequence);
return offset;
}
static int
dissect_lcsap_Reset_Request(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Reset_Request, Reset_Request_sequence);
return offset;
}
static int
dissect_lcsap_Reset_Acknowledge(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_Reset_Acknowledge, Reset_Acknowledge_sequence);
return offset;
}
static int
dissect_lcsap_InitiatingMessage_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_InitiatingMessageValue);
return offset;
}
static int
dissect_lcsap_InitiatingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_InitiatingMessage, InitiatingMessage_sequence);
return offset;
}
static int
dissect_lcsap_SuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_SuccessfulOutcomeValue);
return offset;
}
static int
dissect_lcsap_SuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_SuccessfulOutcome, SuccessfulOutcome_sequence);
return offset;
}
static int
dissect_lcsap_UnsuccessfulOutcome_value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_open_type_pdu_new(tvb, offset, actx, tree, hf_index, dissect_UnsuccessfulOutcomeValue);
return offset;
}
static int
dissect_lcsap_UnsuccessfulOutcome(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lcsap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);
return offset;
}
static int
dissect_lcsap_LCS_AP_PDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lcsap_LCS_AP_PDU, LCS_AP_PDU_choice,
NULL);
return offset;
}
static int dissect_APDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_APDU(tvb, offset, &asn1_ctx, tree, hf_lcsap_APDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Accuracy_Fulfillment_Indicator_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Accuracy_Fulfillment_Indicator(tvb, offset, &asn1_ctx, tree, hf_lcsap_Accuracy_Fulfillment_Indicator_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lcsap_Correlation_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_lcsap_lcsap_Correlation_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_E_CGI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_E_CGI(tvb, offset, &asn1_ctx, tree, hf_lcsap_E_CGI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Geographical_Area_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Geographical_Area(tvb, offset, &asn1_ctx, tree, hf_lcsap_Geographical_Area_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IMSI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_IMSI(tvb, offset, &asn1_ctx, tree, hf_lcsap_IMSI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_IMEI_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_IMEI(tvb, offset, &asn1_ctx, tree, hf_lcsap_IMEI_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Include_Velocity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Include_Velocity(tvb, offset, &asn1_ctx, tree, hf_lcsap_Include_Velocity_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Location_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Location_Type(tvb, offset, &asn1_ctx, tree, hf_lcsap_Location_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_Cause(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_Client_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_Client_Type(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_Client_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_Priority_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_Priority(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_Priority_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_QoS_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_QoS(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_QoS_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_Service_Type_ID_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_Service_Type_ID(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_Service_Type_ID_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_MultipleAPDUs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_MultipleAPDUs(tvb, offset, &asn1_ctx, tree, hf_lcsap_MultipleAPDUs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Network_Element_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Network_Element(tvb, offset, &asn1_ctx, tree, hf_lcsap_Network_Element_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Payload_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Payload_Type(tvb, offset, &asn1_ctx, tree, hf_lcsap_Payload_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Positioning_Data_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Positioning_Data(tvb, offset, &asn1_ctx, tree, hf_lcsap_Positioning_Data_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Return_Error_Type_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Return_Error_Type(tvb, offset, &asn1_ctx, tree, hf_lcsap_Return_Error_Type_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Return_Error_Cause_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Return_Error_Cause(tvb, offset, &asn1_ctx, tree, hf_lcsap_Return_Error_Cause_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_UE_Positioning_Capability_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_UE_Positioning_Capability(tvb, offset, &asn1_ctx, tree, hf_lcsap_UE_Positioning_Capability_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Velocity_Estimate_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Velocity_Estimate(tvb, offset, &asn1_ctx, tree, hf_lcsap_Velocity_Estimate_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Location_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Location_Request(tvb, offset, &asn1_ctx, tree, hf_lcsap_Location_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Location_Response_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Location_Response(tvb, offset, &asn1_ctx, tree, hf_lcsap_Location_Response_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Location_Abort_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Location_Abort_Request(tvb, offset, &asn1_ctx, tree, hf_lcsap_Location_Abort_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Connection_Oriented_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Connection_Oriented_Information(tvb, offset, &asn1_ctx, tree, hf_lcsap_Connection_Oriented_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Connectionless_Information_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Connectionless_Information(tvb, offset, &asn1_ctx, tree, hf_lcsap_Connectionless_Information_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_Request_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Reset_Request(tvb, offset, &asn1_ctx, tree, hf_lcsap_Reset_Request_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_Reset_Acknowledge_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_Reset_Acknowledge(tvb, offset, &asn1_ctx, tree, hf_lcsap_Reset_Acknowledge_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_LCS_AP_PDU_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_lcsap_LCS_AP_PDU(tvb, offset, &asn1_ctx, tree, hf_lcsap_LCS_AP_PDU_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtocolIEFieldValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_ies_dissector_table, ProtocolIE_ID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_ProtocolExtensionFieldExtensionValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_extension_dissector_table, ProtocolExtensionID, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_InitiatingMessageValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_imsg_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_SuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_sout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static int dissect_UnsuccessfulOutcomeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return (dissector_try_uint(lcsap_proc_uout_dissector_table, ProcedureCode, tvb, pinfo, tree)) ? tvb_captured_length(tvb) : 0;
}
static void
dissect_lcsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *lcsap_item = NULL;
proto_tree *lcsap_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LCSAP");
lcsap_item = proto_tree_add_item(tree, proto_lcsap, tvb, 0, -1, ENC_NA);
lcsap_tree = proto_item_add_subtree(lcsap_item, ett_lcsap);
dissect_LCS_AP_PDU_PDU(tvb, pinfo, lcsap_tree, NULL);
}
void
proto_reg_handoff_lcsap(void)
{
static gboolean Initialized=FALSE;
static dissector_handle_t lcsap_handle;
static guint SctpPort;
if (!Initialized) {
lcsap_handle = find_dissector("lcsap");
lpp_handle = find_dissector("lpp");
lppa_handle = find_dissector("lppa");
dissector_add_for_decode_as("sctp.port", lcsap_handle);
dissector_add_uint("sctp.ppi", LCS_AP_PAYLOAD_PROTOCOL_ID, lcsap_handle);
Initialized=TRUE;
#line 1 "../../asn1/lcsap/packet-lcsap-dis-tab.c"
dissector_add_uint("lcsap.ies", id_Accuracy_Fulfillment_Indicator, new_create_dissector_handle(dissect_Accuracy_Fulfillment_Indicator_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_APDU, new_create_dissector_handle(dissect_APDU_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Correlation_ID, new_create_dissector_handle(dissect_lcsap_Correlation_ID_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Destination_ID, new_create_dissector_handle(dissect_Network_Element_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_E_UTRAN_Cell_Identifier, new_create_dissector_handle(dissect_E_CGI_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Include_Velocity, new_create_dissector_handle(dissect_Include_Velocity_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_IMEI, new_create_dissector_handle(dissect_IMEI_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_IMSI, new_create_dissector_handle(dissect_IMSI_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_LCS_Client_Type, new_create_dissector_handle(dissect_LCS_Client_Type_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_LCS_Priority, new_create_dissector_handle(dissect_LCS_Priority_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_LCS_QOS, new_create_dissector_handle(dissect_LCS_QoS_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_LCS_Cause, new_create_dissector_handle(dissect_LCS_Cause_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Location_Estimate, new_create_dissector_handle(dissect_Geographical_Area_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Location_Type, new_create_dissector_handle(dissect_Location_Type_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_MultipleAPDUs, new_create_dissector_handle(dissect_MultipleAPDUs_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Payload_Type, new_create_dissector_handle(dissect_Payload_Type_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Positioning_Data, new_create_dissector_handle(dissect_Positioning_Data_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Return_Error_Request, new_create_dissector_handle(dissect_Return_Error_Type_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Return_Error_Cause, new_create_dissector_handle(dissect_Return_Error_Cause_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Source_Identity, new_create_dissector_handle(dissect_Network_Element_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_UE_Positioning_Capability, new_create_dissector_handle(dissect_UE_Positioning_Capability_PDU, proto_lcsap));
dissector_add_uint("lcsap.ies", id_Velocity_Estimate, new_create_dissector_handle(dissect_Velocity_Estimate_PDU, proto_lcsap));
dissector_add_uint("lcsap.extension", id_LCS_Service_Type_ID, new_create_dissector_handle(dissect_LCS_Service_Type_ID_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.imsg", id_Location_Service_Request, new_create_dissector_handle(dissect_Location_Request_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.sout", id_Location_Service_Request, new_create_dissector_handle(dissect_Location_Response_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.uout", id_Location_Service_Request, new_create_dissector_handle(dissect_Location_Response_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.imsg", id_Connection_Oriented_Information_Transfer, new_create_dissector_handle(dissect_Connection_Oriented_Information_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.imsg", id_Connectionless_Information_Transfer, new_create_dissector_handle(dissect_Connectionless_Information_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.uout", id_Connectionless_Information_Transfer, new_create_dissector_handle(dissect_Connectionless_Information_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.imsg", id_Location_Abort, new_create_dissector_handle(dissect_Location_Abort_Request_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.sout", id_Location_Abort, new_create_dissector_handle(dissect_Location_Response_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.imsg", id_Reset, new_create_dissector_handle(dissect_Reset_Request_PDU, proto_lcsap));
dissector_add_uint("lcsap.proc.sout", id_Reset, new_create_dissector_handle(dissect_Reset_Acknowledge_PDU, proto_lcsap));
#line 257 "../../asn1/lcsap/packet-lcsap-template.c"
} else {
if (SctpPort != 0) {
dissector_delete_uint("sctp.port", SctpPort, lcsap_handle);
}
}
SctpPort=gbl_lcsapSctpPort;
if (SctpPort != 0) {
dissector_add_uint("sctp.port", SctpPort, lcsap_handle);
}
}
void proto_register_lcsap(void) {
static hf_register_info hf[] = {
{ &hf_lcsap_pos_method,
{ "Positioning Method", "lcsap.pos_method",
FT_UINT8, BASE_DEC, VALS(lcsap_pos_method_vals), 0xf8,
NULL, HFILL }
},
{ &hf_lcsap_pos_usage,
{ "Positioning usage", "lcsap.pos_usage",
FT_UINT8, BASE_DEC, VALS(lcsap_pos_usage_vals), 0x07,
NULL, HFILL }
},
{ &hf_lcsap_gnss_pos_method,
{ "GNSS Positioning Method", "lcsap.gnss_pos_method",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_pos_method_vals), 0xc0,
NULL, HFILL }
},
{ &hf_lcsap_gnss_id,
{ "GNSS ID", "lcsap.gnss_id",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_id_vals), 0x38,
NULL, HFILL }
},
{ &hf_lcsap_gnss_pos_usage,
{ "GNSS Positioning usage", "lcsap.gnss_pos_usage",
FT_UINT8, BASE_DEC, VALS(lcsap_gnss_pos_usage_vals), 0x07,
NULL, HFILL }
},
#line 1 "../../asn1/lcsap/packet-lcsap-hfarr.c"
{ &hf_lcsap_APDU_PDU,
{ "APDU", "lcsap.APDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Accuracy_Fulfillment_Indicator_PDU,
{ "Accuracy-Fulfillment-Indicator", "lcsap.Accuracy_Fulfillment_Indicator",
FT_UINT32, BASE_DEC, VALS(lcsap_Accuracy_Fulfillment_Indicator_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_lcsap_Correlation_ID_PDU,
{ "Correlation-ID", "lcsap.Correlation_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_E_CGI_PDU,
{ "E-CGI", "lcsap.E_CGI_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Geographical_Area_PDU,
{ "Geographical-Area", "lcsap.Geographical_Area",
FT_UINT32, BASE_DEC, VALS(lcsap_Geographical_Area_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_IMSI_PDU,
{ "IMSI", "lcsap.IMSI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_IMEI_PDU,
{ "IMEI", "lcsap.IMEI",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Include_Velocity_PDU,
{ "Include-Velocity", "lcsap.Include_Velocity",
FT_UINT32, BASE_DEC, VALS(lcsap_Include_Velocity_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_Location_Type_PDU,
{ "Location-Type", "lcsap.Location_Type",
FT_UINT32, BASE_DEC, VALS(lcsap_Location_Type_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_Cause_PDU,
{ "LCS-Cause", "lcsap.LCS_Cause",
FT_UINT32, BASE_DEC, VALS(lcsap_LCS_Cause_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_Client_Type_PDU,
{ "LCS-Client-Type", "lcsap.LCS_Client_Type",
FT_UINT32, BASE_DEC, VALS(lcsap_LCS_Client_Type_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_Priority_PDU,
{ "LCS-Priority", "lcsap.LCS_Priority",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_QoS_PDU,
{ "LCS-QoS", "lcsap.LCS_QoS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_Service_Type_ID_PDU,
{ "LCS-Service-Type-ID", "lcsap.LCS_Service_Type_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_MultipleAPDUs_PDU,
{ "MultipleAPDUs", "lcsap.MultipleAPDUs",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Network_Element_PDU,
{ "Network-Element", "lcsap.Network_Element",
FT_UINT32, BASE_DEC, VALS(lcsap_Network_Element_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_Payload_Type_PDU,
{ "Payload-Type", "lcsap.Payload_Type",
FT_UINT32, BASE_DEC, VALS(lcsap_Payload_Type_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_Positioning_Data_PDU,
{ "Positioning-Data", "lcsap.Positioning_Data_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Return_Error_Type_PDU,
{ "Return-Error-Type", "lcsap.Return_Error_Type",
FT_UINT32, BASE_DEC, VALS(lcsap_Return_Error_Type_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_Return_Error_Cause_PDU,
{ "Return-Error-Cause", "lcsap.Return_Error_Cause",
FT_UINT32, BASE_DEC, VALS(lcsap_Return_Error_Cause_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_UE_Positioning_Capability_PDU,
{ "UE-Positioning-Capability", "lcsap.UE_Positioning_Capability_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Velocity_Estimate_PDU,
{ "Velocity-Estimate", "lcsap.Velocity_Estimate",
FT_UINT32, BASE_DEC, VALS(lcsap_Velocity_Estimate_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_Location_Request_PDU,
{ "Location-Request", "lcsap.Location_Request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Location_Response_PDU,
{ "Location-Response", "lcsap.Location_Response_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Location_Abort_Request_PDU,
{ "Location-Abort-Request", "lcsap.Location_Abort_Request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Connection_Oriented_Information_PDU,
{ "Connection-Oriented-Information", "lcsap.Connection_Oriented_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Connectionless_Information_PDU,
{ "Connectionless-Information", "lcsap.Connectionless_Information_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Reset_Request_PDU,
{ "Reset-Request", "lcsap.Reset_Request_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Reset_Acknowledge_PDU,
{ "Reset-Acknowledge", "lcsap.Reset_Acknowledge_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_LCS_AP_PDU_PDU,
{ "LCS-AP-PDU", "lcsap.LCS_AP_PDU",
FT_UINT32, BASE_DEC, VALS(lcsap_LCS_AP_PDU_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_ProtocolIE_Container_item,
{ "ProtocolIE-Field", "lcsap.ProtocolIE_Field_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_id,
{ "id", "lcsap.id",
FT_UINT32, BASE_DEC, VALS(lcsap_ProtocolIE_ID_vals), 0,
"ProtocolIE_ID", HFILL }},
{ &hf_lcsap_criticality,
{ "criticality", "lcsap.criticality",
FT_UINT32, BASE_DEC, VALS(lcsap_Criticality_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_ie_field_value,
{ "value", "lcsap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ie_field_value", HFILL }},
{ &hf_lcsap_ProtocolExtensionContainer_item,
{ "ProtocolExtensionField", "lcsap.ProtocolExtensionField_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_ext_id,
{ "id", "lcsap.id",
FT_UINT8, BASE_DEC, VALS(lcsap_ProtocolIE_ID_vals), 0,
"ProtocolExtensionID", HFILL }},
{ &hf_lcsap_extensionValue,
{ "extensionValue", "lcsap.extensionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_direction_Of_Altitude,
{ "direction-Of-Altitude", "lcsap.direction_Of_Altitude",
FT_UINT32, BASE_DEC, VALS(lcsap_Direction_Of_Altitude_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_altitude,
{ "altitude", "lcsap.altitude",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_pLMNidentity,
{ "pLMNidentity", "lcsap.pLMNidentity",
FT_BYTES, BASE_NONE, NULL, 0,
"PLMN_ID", HFILL }},
{ &hf_lcsap_cell_ID,
{ "cell-ID", "lcsap.cell_ID",
FT_BYTES, BASE_NONE, NULL, 0,
"CellIdentity", HFILL }},
{ &hf_lcsap_iE_Extensions,
{ "iE-Extensions", "lcsap.iE_Extensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_lcsap_geographical_Coordinates,
{ "geographical-Coordinates", "lcsap.geographical_Coordinates_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_Ellipse,
{ "uncertainty-Ellipse", "lcsap.uncertainty_Ellipse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_confidence,
{ "confidence", "lcsap.confidence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_altitude_And_Direction,
{ "altitude-And-Direction", "lcsap.altitude_And_Direction_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_Altitude,
{ "uncertainty-Altitude", "lcsap.uncertainty_Altitude",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_inner_Radius,
{ "inner-Radius", "lcsap.inner_Radius",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_Radius,
{ "uncertainty-Radius", "lcsap.uncertainty_Radius",
FT_UINT32, BASE_DEC, NULL, 0,
"Uncertainty_Code", HFILL }},
{ &hf_lcsap_offset_Angle,
{ "offset-Angle", "lcsap.offset_Angle",
FT_UINT32, BASE_DEC, NULL, 0,
"Angle", HFILL }},
{ &hf_lcsap_included_Angle,
{ "included-Angle", "lcsap.included_Angle",
FT_UINT32, BASE_DEC, NULL, 0,
"Angle", HFILL }},
{ &hf_lcsap_macro_eNB_ID,
{ "macro-eNB-ID", "lcsap.macro_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_home_eNB_ID,
{ "home-eNB-ID", "lcsap.home_eNB_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_point,
{ "point", "lcsap.point_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_point_With_Uncertainty,
{ "point-With-Uncertainty", "lcsap.point_With_Uncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_ellipsoidPoint_With_Uncertainty_Ellipse,
{ "ellipsoidPoint-With-Uncertainty-Ellipse", "lcsap.ellipsoidPoint_With_Uncertainty_Ellipse_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_Point_With_Uncertainty_Ellipse", HFILL }},
{ &hf_lcsap_polygon,
{ "polygon", "lcsap.polygon",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_ellipsoid_Point_With_Altitude,
{ "ellipsoid-Point-With-Altitude", "lcsap.ellipsoid_Point_With_Altitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid,
{ "ellipsoid-Point-With-Altitude-And-Uncertainty-Ellipsoid", "lcsap.ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_ellipsoid_Arc,
{ "ellipsoid-Arc", "lcsap.ellipsoid_Arc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_latitudeSign,
{ "latitudeSign", "lcsap.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lcsap_LatitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_degreesLatitude,
{ "degreesLatitude", "lcsap.degreesLatitude",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_degreesLongitude,
{ "degreesLongitude", "lcsap.degreesLongitude",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_pLMN_ID,
{ "pLMN-ID", "lcsap.pLMN_ID",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_eNB_ID,
{ "eNB-ID", "lcsap.eNB_ID",
FT_UINT32, BASE_DEC, VALS(lcsap_ENB_ID_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_GNSS_Positioning_Data_Set_item,
{ "GNSS-Positioning-Method-And-Usage", "lcsap.GNSS_Positioning_Method_And_Usage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_bearing,
{ "bearing", "lcsap.bearing",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lcsap_horizontal_Speed,
{ "horizontal-Speed", "lcsap.horizontal_Speed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lcsap_horizontal_Speed_And_Bearing,
{ "horizontal-Speed-And-Bearing", "lcsap.horizontal_Speed_And_Bearing_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_vertical_Velocity,
{ "vertical-Velocity", "lcsap.vertical_Velocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_Speed,
{ "uncertainty-Speed", "lcsap.uncertainty_Speed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lcsap_horizontal_Uncertainty_Speed,
{ "horizontal-Uncertainty-Speed", "lcsap.horizontal_Uncertainty_Speed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lcsap_vertical_Uncertainty_Speed,
{ "vertical-Uncertainty-Speed", "lcsap.vertical_Uncertainty_Speed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lcsap_radio_Network_Layer,
{ "radio-Network-Layer", "lcsap.radio_Network_Layer",
FT_UINT32, BASE_DEC, VALS(lcsap_Radio_Network_Layer_Cause_vals), 0,
"Radio_Network_Layer_Cause", HFILL }},
{ &hf_lcsap_transport_Layer,
{ "transport-Layer", "lcsap.transport_Layer",
FT_UINT32, BASE_DEC, VALS(lcsap_Transport_Layer_Cause_vals), 0,
"Transport_Layer_Cause", HFILL }},
{ &hf_lcsap_protocol,
{ "protocol", "lcsap.protocol",
FT_UINT32, BASE_DEC, VALS(lcsap_Protocol_Cause_vals), 0,
"Protocol_Cause", HFILL }},
{ &hf_lcsap_misc,
{ "misc", "lcsap.misc",
FT_UINT32, BASE_DEC, VALS(lcsap_Misc_Cause_vals), 0,
"Misc_Cause", HFILL }},
{ &hf_lcsap_horizontal_Accuracy,
{ "horizontal-Accuracy", "lcsap.horizontal_Accuracy",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_vertical_Requested,
{ "vertical-Requested", "lcsap.vertical_Requested",
FT_UINT32, BASE_DEC, VALS(lcsap_Vertical_Requested_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_vertical_Accuracy,
{ "vertical-Accuracy", "lcsap.vertical_Accuracy",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_response_Time,
{ "response-Time", "lcsap.response_Time",
FT_UINT32, BASE_DEC, VALS(lcsap_Response_Time_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_MultipleAPDUs_item,
{ "APDU", "lcsap.APDU",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_global_eNB_ID,
{ "global-eNB-ID", "lcsap.global_eNB_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_e_SMLC_ID,
{ "e-SMLC-ID", "lcsap.e_SMLC_ID",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_Code,
{ "uncertainty-Code", "lcsap.uncertainty_Code",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Polygon_item,
{ "Polygon-Point", "lcsap.Polygon_Point_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_positioning_Data_Set,
{ "positioning-Data-Set", "lcsap.positioning_Data_Set",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_gNSS_Positioning_Data_Set,
{ "gNSS-Positioning-Data-Set", "lcsap.gNSS_Positioning_Data_Set",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_Positioning_Data_Set_item,
{ "Positioning-Method-And-Usage", "lcsap.Positioning_Method_And_Usage",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_uncertainty_SemiMajor,
{ "uncertainty-SemiMajor", "lcsap.uncertainty_SemiMajor",
FT_UINT32, BASE_DEC, NULL, 0,
"Uncertainty_Code", HFILL }},
{ &hf_lcsap_uncertainty_SemiMinor,
{ "uncertainty-SemiMinor", "lcsap.uncertainty_SemiMinor",
FT_UINT32, BASE_DEC, NULL, 0,
"Uncertainty_Code", HFILL }},
{ &hf_lcsap_orientation_Major_Axis,
{ "orientation-Major-Axis", "lcsap.orientation_Major_Axis",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_lPP,
{ "lPP", "lcsap.lPP",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lcsap_horizontal_Velocity,
{ "horizontal-Velocity", "lcsap.horizontal_Velocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_horizontal_With_Vertical_Velocity,
{ "horizontal-With-Vertical-Velocity", "lcsap.horizontal_With_Vertical_Velocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_horizontal_Velocity_With_Uncertainty,
{ "horizontal-Velocity-With-Uncertainty", "lcsap.horizontal_Velocity_With_Uncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_horizontal_With_Vertical_Velocity_And_Uncertainty,
{ "horizontal-With-Vertical-Velocity-And-Uncertainty", "lcsap.horizontal_With_Vertical_Velocity_And_Uncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_vertical_Speed,
{ "vertical-Speed", "lcsap.vertical_Speed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lcsap_vertical_Speed_Direction,
{ "vertical-Speed-Direction", "lcsap.vertical_Speed_Direction",
FT_UINT32, BASE_DEC, VALS(lcsap_Vertical_Speed_Direction_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_protocolIEs,
{ "protocolIEs", "lcsap.protocolIEs",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolIE_Container", HFILL }},
{ &hf_lcsap_protocolExtensions,
{ "protocolExtensions", "lcsap.protocolExtensions",
FT_UINT32, BASE_DEC, NULL, 0,
"ProtocolExtensionContainer", HFILL }},
{ &hf_lcsap_initiatingMessage,
{ "initiatingMessage", "lcsap.initiatingMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_successfulOutcome,
{ "successfulOutcome", "lcsap.successfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_unsuccessfulOutcome,
{ "unsuccessfulOutcome", "lcsap.unsuccessfulOutcome_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lcsap_procedureCode,
{ "procedureCode", "lcsap.procedureCode",
FT_UINT32, BASE_DEC, VALS(lcsap_ProcedureCode_vals), 0,
NULL, HFILL }},
{ &hf_lcsap_initiatingMessagevalue,
{ "value", "lcsap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"InitiatingMessage_value", HFILL }},
{ &hf_lcsap_successfulOutcome_value,
{ "value", "lcsap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"SuccessfulOutcome_value", HFILL }},
{ &hf_lcsap_unsuccessfulOutcome_value,
{ "value", "lcsap.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnsuccessfulOutcome_value", HFILL }},
#line 302 "../../asn1/lcsap/packet-lcsap-template.c"
};
static gint *ett[] = {
&ett_lcsap,
#line 1 "../../asn1/lcsap/packet-lcsap-ettarr.c"
&ett_lcsap_ProtocolIE_Container,
&ett_lcsap_ProtocolIE_Field,
&ett_lcsap_ProtocolExtensionContainer,
&ett_lcsap_ProtocolExtensionField,
&ett_lcsap_Altitude_And_Direction,
&ett_lcsap_E_CGI,
&ett_lcsap_Ellipsoid_Point_With_Uncertainty_Ellipse,
&ett_lcsap_Ellipsoid_Point_With_Altitude,
&ett_lcsap_Ellipsoid_Point_With_Altitude_And_Uncertainty_Ellipsoid,
&ett_lcsap_Ellipsoid_Arc,
&ett_lcsap_ENB_ID,
&ett_lcsap_Geographical_Area,
&ett_lcsap_Geographical_Coordinates,
&ett_lcsap_Global_eNB_ID,
&ett_lcsap_GNSS_Positioning_Data_Set,
&ett_lcsap_Horizontal_Speed_And_Bearing,
&ett_lcsap_Horizontal_Velocity,
&ett_lcsap_Horizontal_With_Vertical_Velocity,
&ett_lcsap_Horizontal_Velocity_With_Uncertainty,
&ett_lcsap_Horizontal_With_Vertical_Velocity_And_Uncertainty,
&ett_lcsap_LCS_Cause,
&ett_lcsap_LCS_QoS,
&ett_lcsap_MultipleAPDUs,
&ett_lcsap_Network_Element,
&ett_lcsap_Point,
&ett_lcsap_Point_With_Uncertainty,
&ett_lcsap_Polygon,
&ett_lcsap_Polygon_Point,
&ett_lcsap_Positioning_Data,
&ett_lcsap_Positioning_Data_Set,
&ett_lcsap_Uncertainty_Ellipse,
&ett_lcsap_UE_Positioning_Capability,
&ett_lcsap_Velocity_Estimate,
&ett_lcsap_Vertical_Velocity,
&ett_lcsap_Location_Request,
&ett_lcsap_Location_Response,
&ett_lcsap_Location_Abort_Request,
&ett_lcsap_Connection_Oriented_Information,
&ett_lcsap_Connectionless_Information,
&ett_lcsap_Reset_Request,
&ett_lcsap_Reset_Acknowledge,
&ett_lcsap_LCS_AP_PDU,
&ett_lcsap_InitiatingMessage,
&ett_lcsap_SuccessfulOutcome,
&ett_lcsap_UnsuccessfulOutcome,
#line 308 "../../asn1/lcsap/packet-lcsap-template.c"
};
module_t *lcsap_module;
proto_lcsap = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_lcsap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("lcsap", dissect_lcsap, proto_lcsap);
lcsap_ies_dissector_table = register_dissector_table("lcsap.ies", "LCS-AP-PROTOCOL-IES", FT_UINT32, BASE_DEC);
lcsap_extension_dissector_table = register_dissector_table("lcsap.extension", "LCS-AP-PROTOCOL-EXTENSION", FT_UINT32, BASE_DEC);
lcsap_proc_imsg_dissector_table = register_dissector_table("lcsap.proc.imsg", "LCS-AP-ELEMENTARY-PROCEDURE InitiatingMessage", FT_UINT32, BASE_DEC);
lcsap_proc_sout_dissector_table = register_dissector_table("lcsap.proc.sout", "LCS-AP-ELEMENTARY-PROCEDURE SuccessfulOutcome", FT_UINT32, BASE_DEC);
lcsap_proc_uout_dissector_table = register_dissector_table("lcsap.proc.uout", "LCS-AP-ELEMENTARY-PROCEDURE UnsuccessfulOutcome", FT_UINT32, BASE_DEC);
lcsap_module = prefs_register_protocol(proto_lcsap, proto_reg_handoff_lcsap);
prefs_register_uint_preference(lcsap_module, "sctp.port",
"LCSAP SCTP Port",
"Set the SCTP port for LCSAP messages",
10,
&gbl_lcsapSctpPort);
}
