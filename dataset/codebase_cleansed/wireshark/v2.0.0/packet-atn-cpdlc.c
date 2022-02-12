static int
dissect_atn_cpdlc_CPDLCUserAbortReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
7, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_CPDLCProviderAbortReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_cpdlc_MsgIdentificationNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_MsgReferenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Year(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1996U, 2095U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Month(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 12U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Day(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Date(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Date, Date_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeHours(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 23U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_TimeMinutes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Time(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Time, Time_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeSeconds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Timehhmmss(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Timehhmmss, Timehhmmss_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DateTimeGroup(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DateTimeGroup, DateTimeGroup_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LogicalAck(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ATCMessageHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCMessageHeader, ATCMessageHeader_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelFeet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-60, 7000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LevelMeters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-30, 25000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LevelFlightLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
30U, 700U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LevelFlightLevelMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
100U, 2500U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LevelType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelType, LevelType_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_2_OF_LevelType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_2_OF_LevelType, SEQUENCE_SIZE_2_OF_LevelType_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Level(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Level, Level_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_Fix(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 5, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 90000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeWholeDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 89U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_MinutesLatLon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 5999U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeDegreesMinutes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatitudeDegreesMinutes, LatitudeDegreesMinutes_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LatLonWholeMinutes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SecondsLatLon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 59U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeDegreesMinutesSeconds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatitudeDegreesMinutesSeconds, LatitudeDegreesMinutesSeconds_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatitudeType, LatitudeType_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Latitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Latitude, Latitude_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 180000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeWholeDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeDegreesMinutes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LongitudeDegreesMinutes, LongitudeDegreesMinutes_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeDegreesMinutesSeconds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LongitudeDegreesMinutesSeconds, LongitudeDegreesMinutesSeconds_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LongitudeType, LongitudeType_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Longitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Longitude, Longitude_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeLongitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatitudeLongitude, LatitudeLongitude_sequence);
return offset;
}
static int
dissect_atn_cpdlc_FixName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_FixName, FixName_sequence);
return offset;
}
static int
dissect_atn_cpdlc_NavaidName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 4, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Navaid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Navaid, Navaid_sequence);
return offset;
}
static int
dissect_atn_cpdlc_Airport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,4, 4, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_PublishedIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PublishedIdentifier, PublishedIdentifier_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_DegreesMagnetic(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 360U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_DegreesTrue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 360U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Degrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Degrees, Degrees_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_DistanceNm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9999U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_DistanceKm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Distance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Distance, Distance_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_PlaceBearingDistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PlaceBearingDistance, PlaceBearingDistance_sequence);
return offset;
}
static int
dissect_atn_cpdlc_Position(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Position, Position_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_TimeLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeLevel, TimeLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionLevel, PositionLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelTime, LevelTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelPosition, LevelPosition_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelLevel, LevelLevel_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_PositionLevelLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionLevelLevel, PositionLevelLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionTime, PositionTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeTime, TimeTime_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_PositionTimeTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionTimeTime, PositionTimeTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SpeedIndicated(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 400U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedIndicatedMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 800U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedTrue(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedTrueMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedGround(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-50, 2000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedGroundMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-100, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SpeedMach(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
500U, 4000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Speed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Speed, Speed_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_PositionSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionSpeed, PositionSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionTimeLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionTimeLevel, PositionTimeLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionLevelSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionLevelSpeed, PositionLevelSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimePosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimePosition, TimePosition_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimePositionLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimePositionLevel, TimePositionLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SpeedSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SpeedSpeed, SpeedSpeed_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LevelSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelSpeed, LevelSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimePositionLevelSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimePositionLevelSpeed, TimePositionLevelSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DistanceSpecifiedNm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 250U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_DistanceSpecifiedKm(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 500U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_DistanceSpecified(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DistanceSpecified, DistanceSpecified_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_Direction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
11, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_DistanceSpecifiedDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DistanceSpecifiedDirection, DistanceSpecifiedDirection_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionDistanceSpecifiedDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionDistanceSpecifiedDirection, PositionDistanceSpecifiedDirection_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeDistanceSpecifiedDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeDistanceSpecifiedDirection, TimeDistanceSpecifiedDirection_sequence);
return offset;
}
static int
dissect_atn_cpdlc_AircraftFlightIdentification(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,2, 8, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_PlaceBearing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PlaceBearing, PlaceBearing_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PlaceBearingPlaceBearing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PlaceBearingPlaceBearing, PlaceBearingPlaceBearing_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_ATSRouteDesignator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,2, 7, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_RouteInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RouteInformation, RouteInformation_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_ProcedureType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Procedure(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 20, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ProcedureTransition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 5, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ProcedureName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProcedureName, ProcedureName_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelProcedureName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelProcedureName, LevelProcedureName_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelsOfFlight(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelsOfFlight, LevelsOfFlight_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_RouteAndLevels(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RouteAndLevels, RouteAndLevels_sequence);
return offset;
}
static int
dissect_atn_cpdlc_FlightInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_FlightInformation, FlightInformation_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_CodeOctalDigit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Code(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Code, Code_sequence_of,
4, 4, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_FacilityDesignation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,4, 8, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_FacilityName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,3, 18, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_FacilityFunction(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_UnitName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_UnitName, UnitName_sequence);
return offset;
}
static int
dissect_atn_cpdlc_Frequencyhf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2850U, 28000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Frequencyvhf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
23600U, 27398U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Frequencyuhf(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
9000U, 15999U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Frequencysatchannel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_NumericString(tvb, offset, actx, tree, hf_index,
12, 12, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Frequency(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Frequency, Frequency_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_UnitNameFrequency(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_UnitNameFrequency, UnitNameFrequency_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeTolerance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ControlledTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ControlledTime, ControlledTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DepartureMinimumInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 150U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_TimeDeparture(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeDeparture, TimeDeparture_sequence);
return offset;
}
static int
dissect_atn_cpdlc_RunwayDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 36U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RunwayConfiguration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Runway(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Runway, Runway_sequence);
return offset;
}
static int
dissect_atn_cpdlc_RevisionNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 16U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_ATISCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 1, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_FurtherInstructions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_FurtherInstructions, FurtherInstructions_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DepartureClearance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DepartureClearance, DepartureClearance_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionPosition, PositionPosition_sequence_of,
2, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RouteClearanceIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 2U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_PositionRouteClearanceIndex(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionRouteClearanceIndex, PositionRouteClearanceIndex_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionProcedureName(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionProcedureName, PositionProcedureName_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LegDistanceEnglish(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 50U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LegDistanceMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LegDistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LegDistance, LegDistance_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_LegTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 10U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LegType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LegType, LegType_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_HoldClearance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_HoldClearance, HoldClearance_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DirectionDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DirectionDegrees, DirectionDegrees_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionDegrees(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionDegrees, PositionDegrees_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeSpeed, TimeSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeSpeedSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeSpeedSpeed, TimeSpeedSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionSpeedSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionSpeedSpeed, PositionSpeedSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LevelSpeedSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LevelSpeedSpeed, LevelSpeedSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PositionUnitNameFrequency(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionUnitNameFrequency, PositionUnitNameFrequency_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeUnitNameFrequency(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeUnitNameFrequency, TimeUnitNameFrequency_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SpeedType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
9, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_SpeedTypeSpeedTypeSpeedType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SpeedTypeSpeedTypeSpeedType, SpeedTypeSpeedTypeSpeedType_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_AltimeterEnglish(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
2200U, 3200U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_AltimeterMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
7500U, 12500U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Altimeter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Altimeter, Altimeter_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_ErrorInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Facility(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Facility, Facility_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_TrafficType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_FreeText(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_restricted_character_string(tvb, offset, actx, tree, hf_index,1, 256, FALSE, ia5alpha , 127, NULL);
return offset;
}
static int
dissect_atn_cpdlc_VerticalRateEnglish(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_VerticalRateMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1000U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_VerticalRate(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_VerticalRate, VerticalRate_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_ToFrom(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ToFromPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ToFromPosition, ToFromPosition_sequence);
return offset;
}
static int
dissect_atn_cpdlc_TimeToFromPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeToFromPosition, TimeToFromPosition_sequence);
return offset;
}
static int
dissect_atn_cpdlc_FacilityDesignationATISCode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_FacilityDesignationATISCode, FacilityDesignationATISCode_sequence);
return offset;
}
static int
dissect_atn_cpdlc_FacilityDesignationAltimeter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_FacilityDesignationAltimeter, FacilityDesignationAltimeter_sequence);
return offset;
}
static int
dissect_atn_cpdlc_RVRFeet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 6100U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RVRMeters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1500U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RVR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RVR, RVR_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_RunwayRVR(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RunwayRVR, RunwayRVR_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCUplinkMsgElementId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCUplinkMsgElementId, ATCUplinkMsgElementId_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCUplinkMsgElementId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCUplinkMsgElementId, SEQUENCE_SIZE_1_5_OF_ATCUplinkMsgElementId_sequence_of,
1, 5, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_128_OF_RouteInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_128_OF_RouteInformation, SEQUENCE_SIZE_1_128_OF_RouteInformation_sequence_of,
1, 128, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_ATWDistanceTolerance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ATWDistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATWDistance, ATWDistance_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATWLevelTolerance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ATWLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATWLevel, ATWLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATWLevelSequence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATWLevelSequence, ATWLevelSequence_sequence_of,
1, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_ATWAlongTrackWaypoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATWAlongTrackWaypoint, ATWAlongTrackWaypoint_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_ATWAlongTrackWaypoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_ATWAlongTrackWaypoint, SEQUENCE_SIZE_1_8_OF_ATWAlongTrackWaypoint_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_LatitudeReportingPoints(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatitudeReportingPoints, LatitudeReportingPoints_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LongitudeReportingPoints(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LongitudeReportingPoints, LongitudeReportingPoints_sequence);
return offset;
}
static int
dissect_atn_cpdlc_LatLonReportingPoints(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_LatLonReportingPoints, LatLonReportingPoints_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_DegreeIncrement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 20U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_ReportingPoints(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ReportingPoints, ReportingPoints_sequence);
return offset;
}
static int
dissect_atn_cpdlc_InterceptCourseFromSelection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_InterceptCourseFromSelection, InterceptCourseFromSelection_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_InterceptCourseFrom(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_InterceptCourseFrom, InterceptCourseFrom_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_4_OF_InterceptCourseFrom(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_4_OF_InterceptCourseFrom, SEQUENCE_SIZE_1_4_OF_InterceptCourseFrom_sequence_of,
1, 4, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_Holdatwaypoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Holdatwaypoint, Holdatwaypoint_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_Holdatwaypoint(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_Holdatwaypoint, SEQUENCE_SIZE_1_8_OF_Holdatwaypoint_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_WaypointSpeedLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_WaypointSpeedLevel, WaypointSpeedLevel_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_WaypointSpeedLevel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_WaypointSpeedLevel, SEQUENCE_SIZE_1_32_OF_WaypointSpeedLevel_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RTATime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RTATime, RTATime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_RTATolerance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 150U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RTARequiredTimeArrival(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RTARequiredTimeArrival, RTARequiredTimeArrival_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_RTARequiredTimeArrival(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_RTARequiredTimeArrival, SEQUENCE_SIZE_1_32_OF_RTARequiredTimeArrival_sequence_of,
1, 32, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RouteInformationAdditional(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RouteInformationAdditional, RouteInformationAdditional_sequence);
return offset;
}
static int
dissect_atn_cpdlc_RouteClearance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RouteClearance, RouteClearance_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_2_OF_RouteClearance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_2_OF_RouteClearance, SEQUENCE_SIZE_1_2_OF_RouteClearance_sequence_of,
1, 2, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_T_atcuplinkmessagedata_constraineddata(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_T_atcuplinkmessagedata_constraineddata, T_atcuplinkmessagedata_constraineddata_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCUplinkMessageData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCUplinkMessageData, ATCUplinkMessageData_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCUplinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCUplinkMessage, ATCUplinkMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_UplinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_UplinkMessage, UplinkMessage_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_AircraftAddress(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
24, 24, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ForwardHeader(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ForwardHeader, ForwardHeader_sequence);
return offset;
}
static int
dissect_atn_cpdlc_BIT_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, NULL, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ForwardMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ForwardMessage, ForwardMessage_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_ATCForwardMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCForwardMessage, ATCForwardMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCForwardResponse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_GroundPDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_GroundPDUs, GroundPDUs_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_Mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ClearanceType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
12, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_RemainingFuel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_atn_cpdlc_Time(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_atn_cpdlc_Temperature(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-100, 100U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_WindDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 360U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_WindSpeedEnglish(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_WindSpeedMetric(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_WindSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_WindSpeed, WindSpeed_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_Winds(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_Winds, Winds_sequence);
return offset;
}
static int
dissect_atn_cpdlc_Turbulence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_Icing(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_VerticalDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_VerticalChange(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_VerticalChange, VerticalChange_sequence);
return offset;
}
static int
dissect_atn_cpdlc_Humidity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_PositionReport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_PositionReport, PositionReport_sequence);
return offset;
}
static int
dissect_atn_cpdlc_PersonsOnBoard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1024U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_RemainingFuelPersonsOnBoard(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_RemainingFuelPersonsOnBoard, RemainingFuelPersonsOnBoard_sequence);
return offset;
}
static int
dissect_atn_cpdlc_VersionNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_TimeDistanceToFromPosition(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_TimeDistanceToFromPosition, TimeDistanceToFromPosition_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SpeedTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SpeedTime, SpeedTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DistanceSpecifiedDirectionTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DistanceSpecifiedDirectionTime, DistanceSpecifiedDirectionTime_sequence);
return offset;
}
static int
dissect_atn_cpdlc_SpeedTypeSpeedTypeSpeedTypeSpeed(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SpeedTypeSpeedTypeSpeedTypeSpeed, SpeedTypeSpeedTypeSpeedTypeSpeed_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCDownlinkMsgElementId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCDownlinkMsgElementId, ATCDownlinkMsgElementId_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCDownlinkMsgElementId(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCDownlinkMsgElementId, SEQUENCE_SIZE_1_5_OF_ATCDownlinkMsgElementId_sequence_of,
1, 5, FALSE);
return offset;
}
static int
dissect_atn_cpdlc_T_atcdownlinkmessagedata_constraineddata(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_T_atcdownlinkmessagedata_constraineddata, T_atcdownlinkmessagedata_constraineddata_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCDownlinkMessageData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCDownlinkMessageData, ATCDownlinkMessageData_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ATCDownlinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ATCDownlinkMessage, ATCDownlinkMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_DownlinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_DownlinkMessage, DownlinkMessage_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_StartDownMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_StartDownMessage, StartDownMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_AircraftPDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_AircraftPDUs, AircraftPDUs_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_PMCPDLCUserAbortReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
13, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_PMCPDLCProviderAbortReason(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_AlgorithmIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
proto_tree *top_tree=NULL;
offset=call_ber_oid_callback(object_identifier_id, tvb, offset, actx->pinfo, top_tree, NULL);
return offset;
}
static int
dissect_atn_cpdlc_CPDLCMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
tvbuff_t *tvb_usr = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index, NO_BOUND, NO_BOUND, FALSE, &tvb_usr, NULL);
if (tvb_usr) {
switch(check_heur_msg_type(actx->pinfo)){
case dm:
dissect_atn_cpdlc_ATCDownlinkMessage(tvb_new_subset_remaining(tvb_usr, 0), 0, actx, tree, hf_index);
break;
case um:
dissect_atn_cpdlc_ATCUplinkMessage(tvb_new_subset_remaining(tvb_usr, 0), 0, actx , tree, hf_index);
break;
default:
break;
}
}
return offset;
}
static int
dissect_atn_cpdlc_ProtectedUplinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProtectedUplinkMessage, ProtectedUplinkMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ProtectedGroundPDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProtectedGroundPDUs, ProtectedGroundPDUs_choice,
NULL);
return offset;
}
static int
dissect_atn_cpdlc_ProtectedMode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_atn_cpdlc_ProtectedDownlinkMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProtectedDownlinkMessage, ProtectedDownlinkMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ProtectedStartDownMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProtectedStartDownMessage, ProtectedStartDownMessage_sequence);
return offset;
}
static int
dissect_atn_cpdlc_ProtectedAircraftPDUs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_atn_cpdlc_ProtectedAircraftPDUs, ProtectedAircraftPDUs_choice,
NULL);
return offset;
}
static int dissect_GroundPDUs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_atn_cpdlc_GroundPDUs(tvb, offset, &asn1_ctx, tree, hf_atn_cpdlc_GroundPDUs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_AircraftPDUs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_atn_cpdlc_AircraftPDUs(tvb, offset, &asn1_ctx, tree, hf_atn_cpdlc_AircraftPDUs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtectedGroundPDUs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_atn_cpdlc_ProtectedGroundPDUs(tvb, offset, &asn1_ctx, tree, hf_atn_cpdlc_ProtectedGroundPDUs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_ProtectedAircraftPDUs_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_atn_cpdlc_ProtectedAircraftPDUs(tvb, offset, &asn1_ctx, tree, hf_atn_cpdlc_ProtectedAircraftPDUs_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int
dissect_atn_cpdlc(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
proto_tree *atn_cpdlc_tree = NULL;
atn_conversation_t *atn_cv = NULL;
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(
&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(!atn_cv){
return 0; }
atn_cpdlc_tree = proto_tree_add_subtree(
tree, tvb, 0, -1, ett_atn_cpdlc, NULL,
ATN_CPDLC_PROTO );
switch(atn_cv->ae_qualifier){
case pmcpdlc:
if( check_heur_msg_type(pinfo) == um ) {
dissect_ProtectedGroundPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}else {
dissect_ProtectedAircraftPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}
break;
case cpdlc:
if( check_heur_msg_type(pinfo) == um ) {
dissect_GroundPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}else {
dissect_AircraftPDUs_PDU(
tvb,
pinfo,
atn_cpdlc_tree, NULL);
}
break;
default:
break;
}
return tvb_reported_length_remaining(tvb, 0);
}
static gboolean
dissect_atn_cpdlc_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
atn_conversation_t *atn_cv = NULL;
volatile gboolean is_atn_cpdlc = FALSE;
volatile gboolean is_pm = FALSE;
int type;
type = check_heur_msg_type(pinfo);
switch(type){
case um:
TRY {
dissect_ProtectedGroundPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = TRUE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
if (is_atn_cpdlc) {
break;
}
TRY {
dissect_GroundPDUs_PDU(tvb, pinfo, NULL, NULL);
is_pm = FALSE;
is_atn_cpdlc = TRUE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
break;
case dm:
TRY {
dissect_ProtectedAircraftPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = TRUE;}
CATCH_ALL {
is_atn_cpdlc = FALSE;
is_pm = FALSE; }
ENDTRY;
if (is_atn_cpdlc) {
break;
}
TRY{
dissect_AircraftPDUs_PDU(tvb, pinfo, NULL, NULL);
is_atn_cpdlc = TRUE;
is_pm = FALSE;}
CATCH_ALL{
is_atn_cpdlc = FALSE;
is_pm = FALSE;}
ENDTRY;
break;
default:
break;
}
if(is_atn_cpdlc){
if((pinfo->clnp_dstref) && (!pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->dst,
pinfo->clnp_dstref,
&pinfo->src );
}
if((!pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if((pinfo->clnp_dstref) && (pinfo->clnp_srcref)){
atn_cv = find_atn_conversation(&pinfo->src,
pinfo->clnp_srcref,
&pinfo->dst );
}
if(atn_cv){
if(is_pm == TRUE) {
atn_cv->ae_qualifier = pmcpdlc; }
else {
atn_cv->ae_qualifier = cpdlc; }
dissect_atn_cpdlc(tvb, pinfo, tree, NULL);
}
}else {
is_atn_cpdlc = FALSE;
}
return is_atn_cpdlc;
}
void proto_register_atn_cpdlc (void)
{
static hf_register_info hf_atn_cpdlc[] = {
#line 1 "../../asn1/atn-cpdlc/packet-atn-cpdlc-hfarr.c"
{ &hf_atn_cpdlc_GroundPDUs_PDU,
{ "GroundPDUs", "atn-cpdlc.GroundPDUs",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_GroundPDUs_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_AircraftPDUs_PDU,
{ "AircraftPDUs", "atn-cpdlc.AircraftPDUs",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_AircraftPDUs_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_ProtectedGroundPDUs_PDU,
{ "ProtectedGroundPDUs", "atn-cpdlc.ProtectedGroundPDUs",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ProtectedGroundPDUs_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_ProtectedAircraftPDUs_PDU,
{ "ProtectedAircraftPDUs", "atn-cpdlc.ProtectedAircraftPDUs",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ProtectedAircraftPDUs_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_abortUser,
{ "abortUser", "atn-cpdlc.abortUser",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_CPDLCUserAbortReason_vals), 0,
"CPDLCUserAbortReason", HFILL }},
{ &hf_atn_cpdlc_abortProvider,
{ "abortProvider", "atn-cpdlc.abortProvider",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_CPDLCProviderAbortReason_vals), 0,
"CPDLCProviderAbortReason", HFILL }},
{ &hf_atn_cpdlc_startup,
{ "startup", "atn-cpdlc.startup",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_UplinkMessage_vals), 0,
"UplinkMessage", HFILL }},
{ &hf_atn_cpdlc_groundpdus_send,
{ "send", "atn-cpdlc.send_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCUplinkMessage", HFILL }},
{ &hf_atn_cpdlc_forward,
{ "forward", "atn-cpdlc.forward_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCForwardMessage", HFILL }},
{ &hf_atn_cpdlc_forwardresponse,
{ "forwardresponse", "atn-cpdlc.forwardresponse",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ATCForwardResponse_vals), 0,
"ATCForwardResponse", HFILL }},
{ &hf_atn_cpdlc_noMessage,
{ "noMessage", "atn-cpdlc.noMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTCUplinkMessage,
{ "aTCUplinkMessage", "atn-cpdlc.aTCUplinkMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_startdown,
{ "startdown", "atn-cpdlc.startdown_element",
FT_NONE, BASE_NONE, NULL, 0,
"StartDownMessage", HFILL }},
{ &hf_atn_cpdlc_aircraftpdus_send,
{ "send", "atn-cpdlc.send_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCDownlinkMessage", HFILL }},
{ &hf_atn_cpdlc_mode,
{ "mode", "atn-cpdlc.mode",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Mode_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_startDownlinkMessage,
{ "startDownlinkMessage", "atn-cpdlc.startDownlinkMessage",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_DownlinkMessage_vals), 0,
"DownlinkMessage", HFILL }},
{ &hf_atn_cpdlc_aTCDownlinkMessage,
{ "aTCDownlinkMessage", "atn-cpdlc.aTCDownlinkMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_pmcpdlcuserabortreason,
{ "abortUser", "atn-cpdlc.abortUser",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_PMCPDLCUserAbortReason_vals), 0,
"PMCPDLCUserAbortReason", HFILL }},
{ &hf_atn_cpdlc_pmcpdlcproviderabortreason,
{ "abortProvider", "atn-cpdlc.abortProvider",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_PMCPDLCProviderAbortReason_vals), 0,
"PMCPDLCProviderAbortReason", HFILL }},
{ &hf_atn_cpdlc_protecteduplinkmessage,
{ "startup", "atn-cpdlc.startup_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedUplinkMessage", HFILL }},
{ &hf_atn_cpdlc_algorithmIdentifier,
{ "algorithmIdentifier", "atn-cpdlc.algorithmIdentifier",
FT_REL_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_protectedMessage,
{ "protectedMessage", "atn-cpdlc.protectedMessage",
FT_BYTES, BASE_NONE, NULL, 0,
"CPDLCMessage", HFILL }},
{ &hf_atn_cpdlc_integrityCheck,
{ "integrityCheck", "atn-cpdlc.integrityCheck",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_atn_cpdlc_forwardHeader,
{ "forwardHeader", "atn-cpdlc.forwardHeader_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_forwardMessage,
{ "forwardMessage", "atn-cpdlc.forwardMessage",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ForwardMessage_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dateTime,
{ "dateTime", "atn-cpdlc.dateTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"DateTimeGroup", HFILL }},
{ &hf_atn_cpdlc_aircraftID,
{ "aircraftID", "atn-cpdlc.aircraftID",
FT_STRING, BASE_NONE, NULL, 0,
"AircraftFlightIdentification", HFILL }},
{ &hf_atn_cpdlc_aircraftAddress,
{ "aircraftAddress", "atn-cpdlc.aircraftAddress",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_upElementIDs,
{ "upElementIDs", "atn-cpdlc.upElementIDs",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_atn_cpdlc_downElementIDs,
{ "downElementIDs", "atn-cpdlc.downElementIDs",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING", HFILL }},
{ &hf_atn_cpdlc_protectedstartDownmessage,
{ "startdown", "atn-cpdlc.startdown_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedStartDownMessage", HFILL }},
{ &hf_atn_cpdlc_send,
{ "send", "atn-cpdlc.send_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedDownlinkMessage", HFILL }},
{ &hf_atn_cpdlc_protectedmode,
{ "mode", "atn-cpdlc.mode",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ProtectedMode_vals), 0,
"ProtectedMode", HFILL }},
{ &hf_atn_cpdlc_protecteddownlinkmessage,
{ "startDownlinkMessage", "atn-cpdlc.startDownlinkMessage_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProtectedDownlinkMessage", HFILL }},
{ &hf_atn_cpdlc_header,
{ "header", "atn-cpdlc.header_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCMessageHeader", HFILL }},
{ &hf_atn_cpdlc_atcuplinkmessage_messagedata,
{ "messageData", "atn-cpdlc.messageData_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCUplinkMessageData", HFILL }},
{ &hf_atn_cpdlc_atcuplinkmessagedata_elementids,
{ "elementIds", "atn-cpdlc.elementIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_5_OF_ATCUplinkMsgElementId", HFILL }},
{ &hf_atn_cpdlc_atcuplinkmessagedata_elementids_item,
{ "ATCUplinkMsgElementId", "atn-cpdlc.ATCUplinkMsgElementId",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ATCUplinkMsgElementId_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_atcuplinkmessagedata_constraineddata,
{ "constrainedData", "atn-cpdlc.constrainedData_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_atcuplinkmessagedata_constraineddata", HFILL }},
{ &hf_atn_cpdlc_routeClearanceData,
{ "routeClearanceData", "atn-cpdlc.routeClearanceData",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_2_OF_RouteClearance", HFILL }},
{ &hf_atn_cpdlc_routeClearanceData_item,
{ "RouteClearance", "atn-cpdlc.RouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_atcdownlinkmessage_messagedata,
{ "messageData", "atn-cpdlc.messageData_element",
FT_NONE, BASE_NONE, NULL, 0,
"ATCDownlinkMessageData", HFILL }},
{ &hf_atn_cpdlc_atcdownlinkmessagedata_elementids,
{ "elementIds", "atn-cpdlc.elementIds",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_5_OF_ATCDownlinkMsgElementId", HFILL }},
{ &hf_atn_cpdlc_atcdownlinkmessagedata_elementids_item,
{ "ATCDownlinkMsgElementId", "atn-cpdlc.ATCDownlinkMsgElementId",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ATCDownlinkMsgElementId_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_atcdownlinkmessagedata_constraineddata,
{ "constrainedData", "atn-cpdlc.constrainedData_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_atcdownlinkmessagedata_constraineddata", HFILL }},
{ &hf_atn_cpdlc_messageIdNumber,
{ "messageIdNumber", "atn-cpdlc.messageIdNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"MsgIdentificationNumber", HFILL }},
{ &hf_atn_cpdlc_messageRefNumber,
{ "messageRefNumber", "atn-cpdlc.messageRefNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"MsgReferenceNumber", HFILL }},
{ &hf_atn_cpdlc_logicalAck,
{ "logicalAck", "atn-cpdlc.logicalAck",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LogicalAck_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM0NULL,
{ "uM0NULL", "atn-cpdlc.uM0NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM1NULL,
{ "uM1NULL", "atn-cpdlc.uM1NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM2NULL,
{ "uM2NULL", "atn-cpdlc.uM2NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM3NULL,
{ "uM3NULL", "atn-cpdlc.uM3NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM4NULL,
{ "uM4NULL", "atn-cpdlc.uM4NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM5NULL,
{ "uM5NULL", "atn-cpdlc.uM5NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM6Level,
{ "uM6Level", "atn-cpdlc.uM6Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM7Time,
{ "uM7Time", "atn-cpdlc.uM7Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM8Position,
{ "uM8Position", "atn-cpdlc.uM8Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM9Time,
{ "uM9Time", "atn-cpdlc.uM9Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM10Position,
{ "uM10Position", "atn-cpdlc.uM10Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM11Time,
{ "uM11Time", "atn-cpdlc.uM11Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM12Position,
{ "uM12Position", "atn-cpdlc.uM12Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM13TimeLevel,
{ "uM13TimeLevel", "atn-cpdlc.uM13TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM14PositionLevel,
{ "uM14PositionLevel", "atn-cpdlc.uM14PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM15TimeLevel,
{ "uM15TimeLevel", "atn-cpdlc.uM15TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM16PositionLevel,
{ "uM16PositionLevel", "atn-cpdlc.uM16PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM17TimeLevel,
{ "uM17TimeLevel", "atn-cpdlc.uM17TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM18PositionLevel,
{ "uM18PositionLevel", "atn-cpdlc.uM18PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM19Level,
{ "uM19Level", "atn-cpdlc.uM19Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM20Level,
{ "uM20Level", "atn-cpdlc.uM20Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM21TimeLevel,
{ "uM21TimeLevel", "atn-cpdlc.uM21TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM22PositionLevel,
{ "uM22PositionLevel", "atn-cpdlc.uM22PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM23Level,
{ "uM23Level", "atn-cpdlc.uM23Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM24TimeLevel,
{ "uM24TimeLevel", "atn-cpdlc.uM24TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM25PositionLevel,
{ "uM25PositionLevel", "atn-cpdlc.uM25PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM26LevelTime,
{ "uM26LevelTime", "atn-cpdlc.uM26LevelTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelTime", HFILL }},
{ &hf_atn_cpdlc_uM27LevelPosition,
{ "uM27LevelPosition", "atn-cpdlc.uM27LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM28LevelTime,
{ "uM28LevelTime", "atn-cpdlc.uM28LevelTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelTime", HFILL }},
{ &hf_atn_cpdlc_uM29LevelPosition,
{ "uM29LevelPosition", "atn-cpdlc.uM29LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM30LevelLevel,
{ "uM30LevelLevel", "atn-cpdlc.uM30LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_uM31LevelLevel,
{ "uM31LevelLevel", "atn-cpdlc.uM31LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_uM32LevelLevel,
{ "uM32LevelLevel", "atn-cpdlc.uM32LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_uM33NULL,
{ "uM33NULL", "atn-cpdlc.uM33NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM34Level,
{ "uM34Level", "atn-cpdlc.uM34Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM35Level,
{ "uM35Level", "atn-cpdlc.uM35Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM36Level,
{ "uM36Level", "atn-cpdlc.uM36Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM37Level,
{ "uM37Level", "atn-cpdlc.uM37Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM38Level,
{ "uM38Level", "atn-cpdlc.uM38Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM39Level,
{ "uM39Level", "atn-cpdlc.uM39Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM40NULL,
{ "uM40NULL", "atn-cpdlc.uM40NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM41NULL,
{ "uM41NULL", "atn-cpdlc.uM41NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM42PositionLevel,
{ "uM42PositionLevel", "atn-cpdlc.uM42PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM43PositionLevel,
{ "uM43PositionLevel", "atn-cpdlc.uM43PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM44PositionLevel,
{ "uM44PositionLevel", "atn-cpdlc.uM44PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM45PositionLevel,
{ "uM45PositionLevel", "atn-cpdlc.uM45PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM46PositionLevel,
{ "uM46PositionLevel", "atn-cpdlc.uM46PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM47PositionLevel,
{ "uM47PositionLevel", "atn-cpdlc.uM47PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM48PositionLevel,
{ "uM48PositionLevel", "atn-cpdlc.uM48PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM49PositionLevel,
{ "uM49PositionLevel", "atn-cpdlc.uM49PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM50PositionLevelLevel,
{ "uM50PositionLevelLevel", "atn-cpdlc.uM50PositionLevelLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevelLevel", HFILL }},
{ &hf_atn_cpdlc_uM51PositionTime,
{ "uM51PositionTime", "atn-cpdlc.uM51PositionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTime", HFILL }},
{ &hf_atn_cpdlc_uM52PositionTime,
{ "uM52PositionTime", "atn-cpdlc.uM52PositionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTime", HFILL }},
{ &hf_atn_cpdlc_uM53PositionTime,
{ "uM53PositionTime", "atn-cpdlc.uM53PositionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTime", HFILL }},
{ &hf_atn_cpdlc_uM54PositionTimeTime,
{ "uM54PositionTimeTime", "atn-cpdlc.uM54PositionTimeTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTimeTime", HFILL }},
{ &hf_atn_cpdlc_uM55PositionSpeed,
{ "uM55PositionSpeed", "atn-cpdlc.uM55PositionSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeed", HFILL }},
{ &hf_atn_cpdlc_uM56PositionSpeed,
{ "uM56PositionSpeed", "atn-cpdlc.uM56PositionSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeed", HFILL }},
{ &hf_atn_cpdlc_uM57PositionSpeed,
{ "uM57PositionSpeed", "atn-cpdlc.uM57PositionSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeed", HFILL }},
{ &hf_atn_cpdlc_uM58PositionTimeLevel,
{ "uM58PositionTimeLevel", "atn-cpdlc.uM58PositionTimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM59PositionTimeLevel,
{ "uM59PositionTimeLevel", "atn-cpdlc.uM59PositionTimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM60PositionTimeLevel,
{ "uM60PositionTimeLevel", "atn-cpdlc.uM60PositionTimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTimeLevel", HFILL }},
{ &hf_atn_cpdlc_uM61PositionLevelSpeed,
{ "uM61PositionLevelSpeed", "atn-cpdlc.uM61PositionLevelSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevelSpeed", HFILL }},
{ &hf_atn_cpdlc_uM62TimePositionLevel,
{ "uM62TimePositionLevel", "atn-cpdlc.uM62TimePositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimePositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM63TimePositionLevelSpeed,
{ "uM63TimePositionLevelSpeed", "atn-cpdlc.uM63TimePositionLevelSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimePositionLevelSpeed", HFILL }},
{ &hf_atn_cpdlc_uM64DistanceSpecifiedDirection,
{ "uM64DistanceSpecifiedDirection", "atn-cpdlc.uM64DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_uM65PositionDistanceSpecifiedDirection,
{ "uM65PositionDistanceSpecifiedDirection", "atn-cpdlc.uM65PositionDistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionDistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_uM66TimeDistanceSpecifiedDirection,
{ "uM66TimeDistanceSpecifiedDirection", "atn-cpdlc.uM66TimeDistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeDistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_uM67NULL,
{ "uM67NULL", "atn-cpdlc.uM67NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM68Position,
{ "uM68Position", "atn-cpdlc.uM68Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM69Time,
{ "uM69Time", "atn-cpdlc.uM69Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM70Position,
{ "uM70Position", "atn-cpdlc.uM70Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM71Time,
{ "uM71Time", "atn-cpdlc.uM71Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM72NULL,
{ "uM72NULL", "atn-cpdlc.uM72NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM73DepartureClearance,
{ "uM73DepartureClearance", "atn-cpdlc.uM73DepartureClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"DepartureClearance", HFILL }},
{ &hf_atn_cpdlc_uM74Position,
{ "uM74Position", "atn-cpdlc.uM74Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM75Position,
{ "uM75Position", "atn-cpdlc.uM75Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM76TimePosition,
{ "uM76TimePosition", "atn-cpdlc.uM76TimePosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimePosition", HFILL }},
{ &hf_atn_cpdlc_uM77PositionPosition,
{ "uM77PositionPosition", "atn-cpdlc.uM77PositionPosition",
FT_UINT32, BASE_DEC, NULL, 0,
"PositionPosition", HFILL }},
{ &hf_atn_cpdlc_uM78LevelPosition,
{ "uM78LevelPosition", "atn-cpdlc.uM78LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM79PositionRouteClearance,
{ "uM79PositionRouteClearance", "atn-cpdlc.uM79PositionRouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionRouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_uM80RouteClearance,
{ "uM80RouteClearance", "atn-cpdlc.uM80RouteClearance",
FT_UINT32, BASE_DEC, NULL, 0,
"RouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_uM81ProcedureName,
{ "uM81ProcedureName", "atn-cpdlc.uM81ProcedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_uM82DistanceSpecifiedDirection,
{ "uM82DistanceSpecifiedDirection", "atn-cpdlc.uM82DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_uM83PositionRouteClearance,
{ "uM83PositionRouteClearance", "atn-cpdlc.uM83PositionRouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionRouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_uM84PositionProcedureName,
{ "uM84PositionProcedureName", "atn-cpdlc.uM84PositionProcedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionProcedureName", HFILL }},
{ &hf_atn_cpdlc_uM85RouteClearance,
{ "uM85RouteClearance", "atn-cpdlc.uM85RouteClearance",
FT_UINT32, BASE_DEC, NULL, 0,
"RouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_uM86PositionRouteClearance,
{ "uM86PositionRouteClearance", "atn-cpdlc.uM86PositionRouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionRouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_uM87Position,
{ "uM87Position", "atn-cpdlc.uM87Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM88PositionPosition,
{ "uM88PositionPosition", "atn-cpdlc.uM88PositionPosition",
FT_UINT32, BASE_DEC, NULL, 0,
"PositionPosition", HFILL }},
{ &hf_atn_cpdlc_uM89TimePosition,
{ "uM89TimePosition", "atn-cpdlc.uM89TimePosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimePosition", HFILL }},
{ &hf_atn_cpdlc_uM90LevelPosition,
{ "uM90LevelPosition", "atn-cpdlc.uM90LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM91HoldClearance,
{ "uM91HoldClearance", "atn-cpdlc.uM91HoldClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"HoldClearance", HFILL }},
{ &hf_atn_cpdlc_uM92PositionLevel,
{ "uM92PositionLevel", "atn-cpdlc.uM92PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM93Time,
{ "uM93Time", "atn-cpdlc.uM93Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM94DirectionDegrees,
{ "uM94DirectionDegrees", "atn-cpdlc.uM94DirectionDegrees_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectionDegrees", HFILL }},
{ &hf_atn_cpdlc_uM95DirectionDegrees,
{ "uM95DirectionDegrees", "atn-cpdlc.uM95DirectionDegrees_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectionDegrees", HFILL }},
{ &hf_atn_cpdlc_uM96NULL,
{ "uM96NULL", "atn-cpdlc.uM96NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM97PositionDegrees,
{ "uM97PositionDegrees", "atn-cpdlc.uM97PositionDegrees_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionDegrees", HFILL }},
{ &hf_atn_cpdlc_uM98DirectionDegrees,
{ "uM98DirectionDegrees", "atn-cpdlc.uM98DirectionDegrees_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectionDegrees", HFILL }},
{ &hf_atn_cpdlc_uM99ProcedureName,
{ "uM99ProcedureName", "atn-cpdlc.uM99ProcedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_uM100TimeSpeed,
{ "uM100TimeSpeed", "atn-cpdlc.uM100TimeSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeSpeed", HFILL }},
{ &hf_atn_cpdlc_uM101PositionSpeed,
{ "uM101PositionSpeed", "atn-cpdlc.uM101PositionSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeed", HFILL }},
{ &hf_atn_cpdlc_uM102LevelSpeed,
{ "uM102LevelSpeed", "atn-cpdlc.uM102LevelSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelSpeed", HFILL }},
{ &hf_atn_cpdlc_uM103TimeSpeedSpeed,
{ "uM103TimeSpeedSpeed", "atn-cpdlc.uM103TimeSpeedSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeSpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_uM104PositionSpeedSpeed,
{ "uM104PositionSpeedSpeed", "atn-cpdlc.uM104PositionSpeedSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_uM105LevelSpeedSpeed,
{ "uM105LevelSpeedSpeed", "atn-cpdlc.uM105LevelSpeedSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelSpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_uM106Speed,
{ "uM106Speed", "atn-cpdlc.uM106Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM107NULL,
{ "uM107NULL", "atn-cpdlc.uM107NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM108Speed,
{ "uM108Speed", "atn-cpdlc.uM108Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM109Speed,
{ "uM109Speed", "atn-cpdlc.uM109Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM110SpeedSpeed,
{ "uM110SpeedSpeed", "atn-cpdlc.uM110SpeedSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_uM111Speed,
{ "uM111Speed", "atn-cpdlc.uM111Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM112Speed,
{ "uM112Speed", "atn-cpdlc.uM112Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM113Speed,
{ "uM113Speed", "atn-cpdlc.uM113Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM114Speed,
{ "uM114Speed", "atn-cpdlc.uM114Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM115Speed,
{ "uM115Speed", "atn-cpdlc.uM115Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM116NULL,
{ "uM116NULL", "atn-cpdlc.uM116NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM117UnitNameFrequency,
{ "uM117UnitNameFrequency", "atn-cpdlc.uM117UnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM118PositionUnitNameFrequency,
{ "uM118PositionUnitNameFrequency", "atn-cpdlc.uM118PositionUnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionUnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM119TimeUnitNameFrequency,
{ "uM119TimeUnitNameFrequency", "atn-cpdlc.uM119TimeUnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeUnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM120UnitNameFrequency,
{ "uM120UnitNameFrequency", "atn-cpdlc.uM120UnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM121PositionUnitNameFrequency,
{ "uM121PositionUnitNameFrequency", "atn-cpdlc.uM121PositionUnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionUnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM122TimeUnitNameFrequency,
{ "uM122TimeUnitNameFrequency", "atn-cpdlc.uM122TimeUnitNameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeUnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_uM123Code,
{ "uM123Code", "atn-cpdlc.uM123Code",
FT_UINT32, BASE_DEC, NULL, 0,
"Code", HFILL }},
{ &hf_atn_cpdlc_uM124NULL,
{ "uM124NULL", "atn-cpdlc.uM124NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM125NULL,
{ "uM125NULL", "atn-cpdlc.uM125NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM126NULL,
{ "uM126NULL", "atn-cpdlc.uM126NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM127NULL,
{ "uM127NULL", "atn-cpdlc.uM127NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM128Level,
{ "uM128Level", "atn-cpdlc.uM128Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM129Level,
{ "uM129Level", "atn-cpdlc.uM129Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM130Position,
{ "uM130Position", "atn-cpdlc.uM130Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM131NULL,
{ "uM131NULL", "atn-cpdlc.uM131NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM132NULL,
{ "uM132NULL", "atn-cpdlc.uM132NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM133NULL,
{ "uM133NULL", "atn-cpdlc.uM133NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM134SpeedTypeSpeedTypeSpeedType,
{ "uM134SpeedTypeSpeedTypeSpeedType", "atn-cpdlc.uM134SpeedTypeSpeedTypeSpeedType",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedTypeSpeedTypeSpeedType", HFILL }},
{ &hf_atn_cpdlc_uM135NULL,
{ "uM135NULL", "atn-cpdlc.uM135NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM136NULL,
{ "uM136NULL", "atn-cpdlc.uM136NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM137NULL,
{ "uM137NULL", "atn-cpdlc.uM137NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM138NULL,
{ "uM138NULL", "atn-cpdlc.uM138NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM139NULL,
{ "uM139NULL", "atn-cpdlc.uM139NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM140NULL,
{ "uM140NULL", "atn-cpdlc.uM140NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM141NULL,
{ "uM141NULL", "atn-cpdlc.uM141NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM142NULL,
{ "uM142NULL", "atn-cpdlc.uM142NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM143NULL,
{ "uM143NULL", "atn-cpdlc.uM143NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM144NULL,
{ "uM144NULL", "atn-cpdlc.uM144NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM145NULL,
{ "uM145NULL", "atn-cpdlc.uM145NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM146NULL,
{ "uM146NULL", "atn-cpdlc.uM146NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM147NULL,
{ "uM147NULL", "atn-cpdlc.uM147NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM148Level,
{ "uM148Level", "atn-cpdlc.uM148Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM149LevelPosition,
{ "uM149LevelPosition", "atn-cpdlc.uM149LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM150LevelTime,
{ "uM150LevelTime", "atn-cpdlc.uM150LevelTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelTime", HFILL }},
{ &hf_atn_cpdlc_uM151Speed,
{ "uM151Speed", "atn-cpdlc.uM151Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM152DistanceSpecifiedDirection,
{ "uM152DistanceSpecifiedDirection", "atn-cpdlc.uM152DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_uM153Altimeter,
{ "uM153Altimeter", "atn-cpdlc.uM153Altimeter",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Altimeter_vals), 0,
"Altimeter", HFILL }},
{ &hf_atn_cpdlc_uM154NULL,
{ "uM154NULL", "atn-cpdlc.uM154NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM155Position,
{ "uM155Position", "atn-cpdlc.uM155Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM156NULL,
{ "uM156NULL", "atn-cpdlc.uM156NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM157Frequency,
{ "uM157Frequency", "atn-cpdlc.uM157Frequency",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Frequency_vals), 0,
"Frequency", HFILL }},
{ &hf_atn_cpdlc_uM158AtisCode,
{ "uM158AtisCode", "atn-cpdlc.uM158AtisCode",
FT_STRING, BASE_NONE, NULL, 0,
"ATISCode", HFILL }},
{ &hf_atn_cpdlc_uM159ErrorInformation,
{ "uM159ErrorInformation", "atn-cpdlc.uM159ErrorInformation",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ErrorInformation_vals), 0,
"ErrorInformation", HFILL }},
{ &hf_atn_cpdlc_uM160Facility,
{ "uM160Facility", "atn-cpdlc.uM160Facility",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Facility_vals), 0,
"Facility", HFILL }},
{ &hf_atn_cpdlc_uM161NULL,
{ "uM161NULL", "atn-cpdlc.uM161NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM162NULL,
{ "uM162NULL", "atn-cpdlc.uM162NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM163FacilityDesignation,
{ "uM163FacilityDesignation", "atn-cpdlc.uM163FacilityDesignation",
FT_STRING, BASE_NONE, NULL, 0,
"FacilityDesignation", HFILL }},
{ &hf_atn_cpdlc_uM164NULL,
{ "uM164NULL", "atn-cpdlc.uM164NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM165NULL,
{ "uM165NULL", "atn-cpdlc.uM165NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM166TrafficType,
{ "uM166TrafficType", "atn-cpdlc.uM166TrafficType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_TrafficType_vals), 0,
"TrafficType", HFILL }},
{ &hf_atn_cpdlc_uM167NULL,
{ "uM167NULL", "atn-cpdlc.uM167NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM168NULL,
{ "uM168NULL", "atn-cpdlc.uM168NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM169FreeText,
{ "uM169FreeText", "atn-cpdlc.uM169FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM170FreeText,
{ "uM170FreeText", "atn-cpdlc.uM170FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM171VerticalRate,
{ "uM171VerticalRate", "atn-cpdlc.uM171VerticalRate",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalRate_vals), 0,
"VerticalRate", HFILL }},
{ &hf_atn_cpdlc_uM172VerticalRate,
{ "uM172VerticalRate", "atn-cpdlc.uM172VerticalRate",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalRate_vals), 0,
"VerticalRate", HFILL }},
{ &hf_atn_cpdlc_uM173VerticalRate,
{ "uM173VerticalRate", "atn-cpdlc.uM173VerticalRate",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalRate_vals), 0,
"VerticalRate", HFILL }},
{ &hf_atn_cpdlc_uM174VerticalRate,
{ "uM174VerticalRate", "atn-cpdlc.uM174VerticalRate",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalRate_vals), 0,
"VerticalRate", HFILL }},
{ &hf_atn_cpdlc_uM175Level,
{ "uM175Level", "atn-cpdlc.uM175Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM176NULL,
{ "uM176NULL", "atn-cpdlc.uM176NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM177NULL,
{ "uM177NULL", "atn-cpdlc.uM177NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM178NULL,
{ "uM178NULL", "atn-cpdlc.uM178NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM179NULL,
{ "uM179NULL", "atn-cpdlc.uM179NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM180LevelLevel,
{ "uM180LevelLevel", "atn-cpdlc.uM180LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_uM181ToFromPosition,
{ "uM181ToFromPosition", "atn-cpdlc.uM181ToFromPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"ToFromPosition", HFILL }},
{ &hf_atn_cpdlc_uM182NULL,
{ "uM182NULL", "atn-cpdlc.uM182NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM183FreeText,
{ "uM183FreeText", "atn-cpdlc.uM183FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM184TimeToFromPosition,
{ "uM184TimeToFromPosition", "atn-cpdlc.uM184TimeToFromPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeToFromPosition", HFILL }},
{ &hf_atn_cpdlc_uM185PositionLevel,
{ "uM185PositionLevel", "atn-cpdlc.uM185PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM186PositionLevel,
{ "uM186PositionLevel", "atn-cpdlc.uM186PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_uM187FreeText,
{ "uM187FreeText", "atn-cpdlc.uM187FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM188PositionSpeed,
{ "uM188PositionSpeed", "atn-cpdlc.uM188PositionSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionSpeed", HFILL }},
{ &hf_atn_cpdlc_uM189Speed,
{ "uM189Speed", "atn-cpdlc.uM189Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_uM190Degrees,
{ "uM190Degrees", "atn-cpdlc.uM190Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_uM191NULL,
{ "uM191NULL", "atn-cpdlc.uM191NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM192LevelTime,
{ "uM192LevelTime", "atn-cpdlc.uM192LevelTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelTime", HFILL }},
{ &hf_atn_cpdlc_uM193NULL,
{ "uM193NULL", "atn-cpdlc.uM193NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM194FreeText,
{ "uM194FreeText", "atn-cpdlc.uM194FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM195FreeText,
{ "uM195FreeText", "atn-cpdlc.uM195FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM196FreeText,
{ "uM196FreeText", "atn-cpdlc.uM196FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM197FreeText,
{ "uM197FreeText", "atn-cpdlc.uM197FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM198FreeText,
{ "uM198FreeText", "atn-cpdlc.uM198FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM199FreeText,
{ "uM199FreeText", "atn-cpdlc.uM199FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM200NULL,
{ "uM200NULL", "atn-cpdlc.uM200NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM201NULL,
{ "uM201NULL", "atn-cpdlc.uM201NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM202NULL,
{ "uM202NULL", "atn-cpdlc.uM202NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM203FreeText,
{ "uM203FreeText", "atn-cpdlc.uM203FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM204FreeText,
{ "uM204FreeText", "atn-cpdlc.uM204FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM205FreeText,
{ "uM205FreeText", "atn-cpdlc.uM205FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM206FreeText,
{ "uM206FreeText", "atn-cpdlc.uM206FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM207FreeText,
{ "uM207FreeText", "atn-cpdlc.uM207FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM208FreeText,
{ "uM208FreeText", "atn-cpdlc.uM208FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_uM209LevelPosition,
{ "uM209LevelPosition", "atn-cpdlc.uM209LevelPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelPosition", HFILL }},
{ &hf_atn_cpdlc_uM210Position,
{ "uM210Position", "atn-cpdlc.uM210Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM211NULL,
{ "uM211NULL", "atn-cpdlc.uM211NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM212FacilityDesignationATISCode,
{ "uM212FacilityDesignationATISCode", "atn-cpdlc.uM212FacilityDesignationATISCode_element",
FT_NONE, BASE_NONE, NULL, 0,
"FacilityDesignationATISCode", HFILL }},
{ &hf_atn_cpdlc_uM213FacilityDesignationAltimeter,
{ "uM213FacilityDesignationAltimeter", "atn-cpdlc.uM213FacilityDesignationAltimeter_element",
FT_NONE, BASE_NONE, NULL, 0,
"FacilityDesignationAltimeter", HFILL }},
{ &hf_atn_cpdlc_uM214RunwayRVR,
{ "uM214RunwayRVR", "atn-cpdlc.uM214RunwayRVR_element",
FT_NONE, BASE_NONE, NULL, 0,
"RunwayRVR", HFILL }},
{ &hf_atn_cpdlc_uM215DirectionDegrees,
{ "uM215DirectionDegrees", "atn-cpdlc.uM215DirectionDegrees_element",
FT_NONE, BASE_NONE, NULL, 0,
"DirectionDegrees", HFILL }},
{ &hf_atn_cpdlc_uM216NULL,
{ "uM216NULL", "atn-cpdlc.uM216NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM217NULL,
{ "uM217NULL", "atn-cpdlc.uM217NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM218NULL,
{ "uM218NULL", "atn-cpdlc.uM218NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM219Level,
{ "uM219Level", "atn-cpdlc.uM219Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM220Level,
{ "uM220Level", "atn-cpdlc.uM220Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_uM221Degrees,
{ "uM221Degrees", "atn-cpdlc.uM221Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_uM222NULL,
{ "uM222NULL", "atn-cpdlc.uM222NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM223NULL,
{ "uM223NULL", "atn-cpdlc.uM223NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM224NULL,
{ "uM224NULL", "atn-cpdlc.uM224NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM225NULL,
{ "uM225NULL", "atn-cpdlc.uM225NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM226Time,
{ "uM226Time", "atn-cpdlc.uM226Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_uM227NULL,
{ "uM227NULL", "atn-cpdlc.uM227NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM228Position,
{ "uM228Position", "atn-cpdlc.uM228Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_uM229NULL,
{ "uM229NULL", "atn-cpdlc.uM229NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM230NULL,
{ "uM230NULL", "atn-cpdlc.uM230NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM231NULL,
{ "uM231NULL", "atn-cpdlc.uM231NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM232NULL,
{ "uM232NULL", "atn-cpdlc.uM232NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM233NULL,
{ "uM233NULL", "atn-cpdlc.uM233NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM234NULL,
{ "uM234NULL", "atn-cpdlc.uM234NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM235NULL,
{ "uM235NULL", "atn-cpdlc.uM235NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM236NULL,
{ "uM236NULL", "atn-cpdlc.uM236NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_uM237NULL,
{ "uM237NULL", "atn-cpdlc.uM237NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM0NULL,
{ "dM0NULL", "atn-cpdlc.dM0NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM1NULL,
{ "dM1NULL", "atn-cpdlc.dM1NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM2NULL,
{ "dM2NULL", "atn-cpdlc.dM2NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM3NULL,
{ "dM3NULL", "atn-cpdlc.dM3NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM4NULL,
{ "dM4NULL", "atn-cpdlc.dM4NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM5NULL,
{ "dM5NULL", "atn-cpdlc.dM5NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM6Level,
{ "dM6Level", "atn-cpdlc.dM6Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM7LevelLevel,
{ "dM7LevelLevel", "atn-cpdlc.dM7LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_dM8Level,
{ "dM8Level", "atn-cpdlc.dM8Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM9Level,
{ "dM9Level", "atn-cpdlc.dM9Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM10Level,
{ "dM10Level", "atn-cpdlc.dM10Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM11PositionLevel,
{ "dM11PositionLevel", "atn-cpdlc.dM11PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_dM12PositionLevel,
{ "dM12PositionLevel", "atn-cpdlc.dM12PositionLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionLevel", HFILL }},
{ &hf_atn_cpdlc_dM13TimeLevel,
{ "dM13TimeLevel", "atn-cpdlc.dM13TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_dM14TimeLevel,
{ "dM14TimeLevel", "atn-cpdlc.dM14TimeLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeLevel", HFILL }},
{ &hf_atn_cpdlc_dM15DistanceSpecifiedDirection,
{ "dM15DistanceSpecifiedDirection", "atn-cpdlc.dM15DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM16PositionDistanceSpecifiedDirection,
{ "dM16PositionDistanceSpecifiedDirection", "atn-cpdlc.dM16PositionDistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionDistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM17TimeDistanceSpecifiedDirection,
{ "dM17TimeDistanceSpecifiedDirection", "atn-cpdlc.dM17TimeDistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeDistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM18Speed,
{ "dM18Speed", "atn-cpdlc.dM18Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_dM19SpeedSpeed,
{ "dM19SpeedSpeed", "atn-cpdlc.dM19SpeedSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_dM20NULL,
{ "dM20NULL", "atn-cpdlc.dM20NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM21Frequency,
{ "dM21Frequency", "atn-cpdlc.dM21Frequency",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Frequency_vals), 0,
"Frequency", HFILL }},
{ &hf_atn_cpdlc_dM22Position,
{ "dM22Position", "atn-cpdlc.dM22Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM23ProcedureName,
{ "dM23ProcedureName", "atn-cpdlc.dM23ProcedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_dM24RouteClearance,
{ "dM24RouteClearance", "atn-cpdlc.dM24RouteClearance",
FT_UINT32, BASE_DEC, NULL, 0,
"RouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_dM25ClearanceType,
{ "dM25ClearanceType", "atn-cpdlc.dM25ClearanceType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ClearanceType_vals), 0,
"ClearanceType", HFILL }},
{ &hf_atn_cpdlc_dM26PositionRouteClearance,
{ "dM26PositionRouteClearance", "atn-cpdlc.dM26PositionRouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionRouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_dM27DistanceSpecifiedDirection,
{ "dM27DistanceSpecifiedDirection", "atn-cpdlc.dM27DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM28Level,
{ "dM28Level", "atn-cpdlc.dM28Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM29Level,
{ "dM29Level", "atn-cpdlc.dM29Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM30Level,
{ "dM30Level", "atn-cpdlc.dM30Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM31Position,
{ "dM31Position", "atn-cpdlc.dM31Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM32Level,
{ "dM32Level", "atn-cpdlc.dM32Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM33Position,
{ "dM33Position", "atn-cpdlc.dM33Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM34Speed,
{ "dM34Speed", "atn-cpdlc.dM34Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_dM35Degrees,
{ "dM35Degrees", "atn-cpdlc.dM35Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_dM36Degrees,
{ "dM36Degrees", "atn-cpdlc.dM36Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_dM37Level,
{ "dM37Level", "atn-cpdlc.dM37Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM38Level,
{ "dM38Level", "atn-cpdlc.dM38Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM39Speed,
{ "dM39Speed", "atn-cpdlc.dM39Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_dM40RouteClearance,
{ "dM40RouteClearance", "atn-cpdlc.dM40RouteClearance",
FT_UINT32, BASE_DEC, NULL, 0,
"RouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_dM41NULL,
{ "dM41NULL", "atn-cpdlc.dM41NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM42Position,
{ "dM42Position", "atn-cpdlc.dM42Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM43Time,
{ "dM43Time", "atn-cpdlc.dM43Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_dM44Position,
{ "dM44Position", "atn-cpdlc.dM44Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM45Position,
{ "dM45Position", "atn-cpdlc.dM45Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM46Time,
{ "dM46Time", "atn-cpdlc.dM46Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_dM47Code,
{ "dM47Code", "atn-cpdlc.dM47Code",
FT_UINT32, BASE_DEC, NULL, 0,
"Code", HFILL }},
{ &hf_atn_cpdlc_dM48PositionReport,
{ "dM48PositionReport", "atn-cpdlc.dM48PositionReport_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionReport", HFILL }},
{ &hf_atn_cpdlc_dM49Speed,
{ "dM49Speed", "atn-cpdlc.dM49Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_dM50SpeedSpeed,
{ "dM50SpeedSpeed", "atn-cpdlc.dM50SpeedSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_dM51NULL,
{ "dM51NULL", "atn-cpdlc.dM51NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM52NULL,
{ "dM52NULL", "atn-cpdlc.dM52NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM53NULL,
{ "dM53NULL", "atn-cpdlc.dM53NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM54Level,
{ "dM54Level", "atn-cpdlc.dM54Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM55NULL,
{ "dM55NULL", "atn-cpdlc.dM55NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM56NULL,
{ "dM56NULL", "atn-cpdlc.dM56NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM57RemainingFuelPersonsOnBoard,
{ "dM57RemainingFuelPersonsOnBoard", "atn-cpdlc.dM57RemainingFuelPersonsOnBoard_element",
FT_NONE, BASE_NONE, NULL, 0,
"RemainingFuelPersonsOnBoard", HFILL }},
{ &hf_atn_cpdlc_dM58NULL,
{ "dM58NULL", "atn-cpdlc.dM58NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM59PositionRouteClearance,
{ "dM59PositionRouteClearance", "atn-cpdlc.dM59PositionRouteClearance_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionRouteClearanceIndex", HFILL }},
{ &hf_atn_cpdlc_dM60DistanceSpecifiedDirection,
{ "dM60DistanceSpecifiedDirection", "atn-cpdlc.dM60DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM61Level,
{ "dM61Level", "atn-cpdlc.dM61Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM62ErrorInformation,
{ "dM62ErrorInformation", "atn-cpdlc.dM62ErrorInformation",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ErrorInformation_vals), 0,
"ErrorInformation", HFILL }},
{ &hf_atn_cpdlc_dM63NULL,
{ "dM63NULL", "atn-cpdlc.dM63NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM64FacilityDesignation,
{ "dM64FacilityDesignation", "atn-cpdlc.dM64FacilityDesignation",
FT_STRING, BASE_NONE, NULL, 0,
"FacilityDesignation", HFILL }},
{ &hf_atn_cpdlc_dM65NULL,
{ "dM65NULL", "atn-cpdlc.dM65NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM66NULL,
{ "dM66NULL", "atn-cpdlc.dM66NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM67FreeText,
{ "dM67FreeText", "atn-cpdlc.dM67FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM68FreeText,
{ "dM68FreeText", "atn-cpdlc.dM68FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM69NULL,
{ "dM69NULL", "atn-cpdlc.dM69NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM70Degrees,
{ "dM70Degrees", "atn-cpdlc.dM70Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_dM71Degrees,
{ "dM71Degrees", "atn-cpdlc.dM71Degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_dM72Level,
{ "dM72Level", "atn-cpdlc.dM72Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM73Versionnumber,
{ "dM73Versionnumber", "atn-cpdlc.dM73Versionnumber",
FT_UINT32, BASE_DEC, NULL, 0,
"VersionNumber", HFILL }},
{ &hf_atn_cpdlc_dM74NULL,
{ "dM74NULL", "atn-cpdlc.dM74NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM75NULL,
{ "dM75NULL", "atn-cpdlc.dM75NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM76LevelLevel,
{ "dM76LevelLevel", "atn-cpdlc.dM76LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_dM77LevelLevel,
{ "dM77LevelLevel", "atn-cpdlc.dM77LevelLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_dM78TimeDistanceToFromPosition,
{ "dM78TimeDistanceToFromPosition", "atn-cpdlc.dM78TimeDistanceToFromPosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimeDistanceToFromPosition", HFILL }},
{ &hf_atn_cpdlc_dM79AtisCode,
{ "dM79AtisCode", "atn-cpdlc.dM79AtisCode",
FT_STRING, BASE_NONE, NULL, 0,
"ATISCode", HFILL }},
{ &hf_atn_cpdlc_dM80DistanceSpecifiedDirection,
{ "dM80DistanceSpecifiedDirection", "atn-cpdlc.dM80DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM81LevelTime,
{ "dM81LevelTime", "atn-cpdlc.dM81LevelTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"LevelTime", HFILL }},
{ &hf_atn_cpdlc_dM82Level,
{ "dM82Level", "atn-cpdlc.dM82Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM83SpeedTime,
{ "dM83SpeedTime", "atn-cpdlc.dM83SpeedTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"SpeedTime", HFILL }},
{ &hf_atn_cpdlc_dM84Speed,
{ "dM84Speed", "atn-cpdlc.dM84Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_dM85DistanceSpecifiedDirectionTime,
{ "dM85DistanceSpecifiedDirectionTime", "atn-cpdlc.dM85DistanceSpecifiedDirectionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirectionTime", HFILL }},
{ &hf_atn_cpdlc_dM86DistanceSpecifiedDirection,
{ "dM86DistanceSpecifiedDirection", "atn-cpdlc.dM86DistanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
"DistanceSpecifiedDirection", HFILL }},
{ &hf_atn_cpdlc_dM87Level,
{ "dM87Level", "atn-cpdlc.dM87Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM88Level,
{ "dM88Level", "atn-cpdlc.dM88Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM89UnitnameFrequency,
{ "dM89UnitnameFrequency", "atn-cpdlc.dM89UnitnameFrequency_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_dM90FreeText,
{ "dM90FreeText", "atn-cpdlc.dM90FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM91FreeText,
{ "dM91FreeText", "atn-cpdlc.dM91FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM92FreeText,
{ "dM92FreeText", "atn-cpdlc.dM92FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM93FreeText,
{ "dM93FreeText", "atn-cpdlc.dM93FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM94FreeText,
{ "dM94FreeText", "atn-cpdlc.dM94FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM95FreeText,
{ "dM95FreeText", "atn-cpdlc.dM95FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM96FreeText,
{ "dM96FreeText", "atn-cpdlc.dM96FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM97FreeText,
{ "dM97FreeText", "atn-cpdlc.dM97FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM98FreeText,
{ "dM98FreeText", "atn-cpdlc.dM98FreeText",
FT_STRING, BASE_NONE, NULL, 0,
"FreeText", HFILL }},
{ &hf_atn_cpdlc_dM99NULL,
{ "dM99NULL", "atn-cpdlc.dM99NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM100NULL,
{ "dM100NULL", "atn-cpdlc.dM100NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM101NULL,
{ "dM101NULL", "atn-cpdlc.dM101NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM102NULL,
{ "dM102NULL", "atn-cpdlc.dM102NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM103NULL,
{ "dM103NULL", "atn-cpdlc.dM103NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM104PositionTime,
{ "dM104PositionTime", "atn-cpdlc.dM104PositionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositionTime", HFILL }},
{ &hf_atn_cpdlc_dM105Airport,
{ "dM105Airport", "atn-cpdlc.dM105Airport",
FT_STRING, BASE_NONE, NULL, 0,
"Airport", HFILL }},
{ &hf_atn_cpdlc_dM106Level,
{ "dM106Level", "atn-cpdlc.dM106Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_dM107NULL,
{ "dM107NULL", "atn-cpdlc.dM107NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM108NULL,
{ "dM108NULL", "atn-cpdlc.dM108NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM109Time,
{ "dM109Time", "atn-cpdlc.dM109Time_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_dM110Position,
{ "dM110Position", "atn-cpdlc.dM110Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_dM111TimePosition,
{ "dM111TimePosition", "atn-cpdlc.dM111TimePosition_element",
FT_NONE, BASE_NONE, NULL, 0,
"TimePosition", HFILL }},
{ &hf_atn_cpdlc_dM112NULL,
{ "dM112NULL", "atn-cpdlc.dM112NULL_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_dM113SpeedTypeSpeedTypeSpeedTypeSpeed,
{ "dM113SpeedTypeSpeedTypeSpeedTypeSpeed", "atn-cpdlc.dM113SpeedTypeSpeedTypeSpeedTypeSpeed_element",
FT_NONE, BASE_NONE, NULL, 0,
"SpeedTypeSpeedTypeSpeedTypeSpeed", HFILL }},
{ &hf_atn_cpdlc_altimeterEnglish,
{ "altimeterEnglish", "atn-cpdlc.altimeterEnglish",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_altimeterMetric,
{ "altimeterMetric", "atn-cpdlc.altimeterMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_position,
{ "position", "atn-cpdlc.position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTWDistance,
{ "aTWDistance", "atn-cpdlc.aTWDistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speed,
{ "speed", "atn-cpdlc.speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTWLevels,
{ "aTWLevels", "atn-cpdlc.aTWLevels",
FT_UINT32, BASE_DEC, NULL, 0,
"ATWLevelSequence", HFILL }},
{ &hf_atn_cpdlc_atw,
{ "atw", "atn-cpdlc.atw",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ATWLevelTolerance_vals), 0,
"ATWLevelTolerance", HFILL }},
{ &hf_atn_cpdlc_level,
{ "level", "atn-cpdlc.level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_ATWLevelSequence_item,
{ "ATWLevel", "atn-cpdlc.ATWLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_atwDistanceTolerance,
{ "atwDistanceTolerance", "atn-cpdlc.atwDistanceTolerance",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ATWDistanceTolerance_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distance,
{ "distance", "atn-cpdlc.distance",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Distance_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_Code_item,
{ "CodeOctalDigit", "atn-cpdlc.CodeOctalDigit",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_time,
{ "time", "atn-cpdlc.time_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_timeTolerance,
{ "timeTolerance", "atn-cpdlc.timeTolerance",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_TimeTolerance_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_year,
{ "year", "atn-cpdlc.year",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_month,
{ "month", "atn-cpdlc.month",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_day,
{ "day", "atn-cpdlc.day",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_date,
{ "date", "atn-cpdlc.date_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_timehhmmss,
{ "timehhmmss", "atn-cpdlc.timehhmmss_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_degreesMagnetic,
{ "degreesMagnetic", "atn-cpdlc.degreesMagnetic",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_degreesTrue,
{ "degreesTrue", "atn-cpdlc.degreesTrue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aircraftFlightIdentification,
{ "aircraftFlightIdentification", "atn-cpdlc.aircraftFlightIdentification",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_clearanceLimit,
{ "clearanceLimit", "atn-cpdlc.clearanceLimit",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_flightInformation,
{ "flightInformation", "atn-cpdlc.flightInformation",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_FlightInformation_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_furtherInstructions,
{ "furtherInstructions", "atn-cpdlc.furtherInstructions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_direction,
{ "direction", "atn-cpdlc.direction",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Direction_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_degrees,
{ "degrees", "atn-cpdlc.degrees",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceNm,
{ "distanceNm", "atn-cpdlc.distanceNm",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceKm,
{ "distanceKm", "atn-cpdlc.distanceKm",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceSpecifiedNm,
{ "distanceSpecifiedNm", "atn-cpdlc.distanceSpecifiedNm",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceSpecifiedKm,
{ "distanceSpecifiedKm", "atn-cpdlc.distanceSpecifiedKm",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceSpecified,
{ "distanceSpecified", "atn-cpdlc.distanceSpecified",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_DistanceSpecified_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_distanceSpecifiedDirection,
{ "distanceSpecifiedDirection", "atn-cpdlc.distanceSpecifiedDirection_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_noFacility,
{ "noFacility", "atn-cpdlc.noFacility_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_facilityDesignation,
{ "facilityDesignation", "atn-cpdlc.facilityDesignation",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_altimeter,
{ "altimeter", "atn-cpdlc.altimeter",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Altimeter_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTISCode,
{ "aTISCode", "atn-cpdlc.aTISCode",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_fixname_name,
{ "name", "atn-cpdlc.name",
FT_STRING, BASE_NONE, NULL, 0,
"Fix", HFILL }},
{ &hf_atn_cpdlc_latlon,
{ "latlon", "atn-cpdlc.latlon_element",
FT_NONE, BASE_NONE, NULL, 0,
"LatitudeLongitude", HFILL }},
{ &hf_atn_cpdlc_routeOfFlight,
{ "routeOfFlight", "atn-cpdlc.routeOfFlight",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_RouteInformation_vals), 0,
"RouteInformation", HFILL }},
{ &hf_atn_cpdlc_levelsOfFlight,
{ "levelsOfFlight", "atn-cpdlc.levelsOfFlight",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LevelsOfFlight_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_routeAndLevels,
{ "routeAndLevels", "atn-cpdlc.routeAndLevels_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequencyhf,
{ "frequencyhf", "atn-cpdlc.frequencyhf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequencyvhf,
{ "frequencyvhf", "atn-cpdlc.frequencyvhf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequencyuhf,
{ "frequencyuhf", "atn-cpdlc.frequencyuhf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequencysatchannel,
{ "frequencysatchannel", "atn-cpdlc.frequencysatchannel",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_code,
{ "code", "atn-cpdlc.code",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequencyDeparture,
{ "frequencyDeparture", "atn-cpdlc.frequencyDeparture_element",
FT_NONE, BASE_NONE, NULL, 0,
"UnitNameFrequency", HFILL }},
{ &hf_atn_cpdlc_clearanceExpiryTime,
{ "clearanceExpiryTime", "atn-cpdlc.clearanceExpiryTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_airportDeparture,
{ "airportDeparture", "atn-cpdlc.airportDeparture",
FT_STRING, BASE_NONE, NULL, 0,
"Airport", HFILL }},
{ &hf_atn_cpdlc_airportDestination,
{ "airportDestination", "atn-cpdlc.airportDestination",
FT_STRING, BASE_NONE, NULL, 0,
"Airport", HFILL }},
{ &hf_atn_cpdlc_timeDeparture,
{ "timeDeparture", "atn-cpdlc.timeDeparture_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_runwayDeparture,
{ "runwayDeparture", "atn-cpdlc.runwayDeparture_element",
FT_NONE, BASE_NONE, NULL, 0,
"Runway", HFILL }},
{ &hf_atn_cpdlc_revisionNumber,
{ "revisionNumber", "atn-cpdlc.revisionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_holdatwaypointspeedlow,
{ "holdatwaypointspeedlow", "atn-cpdlc.holdatwaypointspeedlow",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_aTWlevel,
{ "aTWlevel", "atn-cpdlc.aTWlevel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_holdatwaypointspeedhigh,
{ "holdatwaypointspeedhigh", "atn-cpdlc.holdatwaypointspeedhigh",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
"Speed", HFILL }},
{ &hf_atn_cpdlc_eFCtime,
{ "eFCtime", "atn-cpdlc.eFCtime_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_legtype,
{ "legtype", "atn-cpdlc.legtype",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LegType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_legType,
{ "legType", "atn-cpdlc.legType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LegType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_fromSelection,
{ "fromSelection", "atn-cpdlc.fromSelection",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_InterceptCourseFromSelection_vals), 0,
"InterceptCourseFromSelection", HFILL }},
{ &hf_atn_cpdlc_publishedIdentifier,
{ "publishedIdentifier", "atn-cpdlc.publishedIdentifier",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_PublishedIdentifier_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeLongitude,
{ "latitudeLongitude", "atn-cpdlc.latitudeLongitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_placeBearingPlaceBearing,
{ "placeBearingPlaceBearing", "atn-cpdlc.placeBearingPlaceBearing",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_placeBearingDistance,
{ "placeBearingDistance", "atn-cpdlc.placeBearingDistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeType,
{ "latitudeType", "atn-cpdlc.latitudeType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LatitudeType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeDirection,
{ "latitudeDirection", "atn-cpdlc.latitudeDirection",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LatitudeDirection_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeWholeDegrees,
{ "latitudeWholeDegrees", "atn-cpdlc.latitudeWholeDegrees",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_minutesLatLon,
{ "minutesLatLon", "atn-cpdlc.minutesLatLon",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latlonWholeMinutes,
{ "latlonWholeMinutes", "atn-cpdlc.latlonWholeMinutes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_secondsLatLon,
{ "secondsLatLon", "atn-cpdlc.secondsLatLon",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitude,
{ "latitude", "atn-cpdlc.latitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitude,
{ "longitude", "atn-cpdlc.longitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeDegrees,
{ "latitudeDegrees", "atn-cpdlc.latitudeDegrees",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeDegreesMinutes,
{ "latitudeDegreesMinutes", "atn-cpdlc.latitudeDegreesMinutes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latitudeDMS,
{ "latitudeDMS", "atn-cpdlc.latitudeDMS_element",
FT_NONE, BASE_NONE, NULL, 0,
"LatitudeDegreesMinutesSeconds", HFILL }},
{ &hf_atn_cpdlc_latitudeReportingPoints,
{ "latitudeReportingPoints", "atn-cpdlc.latitudeReportingPoints_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeReportingPoints,
{ "longitudeReportingPoints", "atn-cpdlc.longitudeReportingPoints_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_legDistanceEnglish,
{ "legDistanceEnglish", "atn-cpdlc.legDistanceEnglish",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_legDistanceMetric,
{ "legDistanceMetric", "atn-cpdlc.legDistanceMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_legDistance,
{ "legDistance", "atn-cpdlc.legDistance",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LegDistance_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_legTime,
{ "legTime", "atn-cpdlc.legTime",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_singleLevel,
{ "singleLevel", "atn-cpdlc.singleLevel",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LevelType_vals), 0,
"LevelType", HFILL }},
{ &hf_atn_cpdlc_blockLevel,
{ "blockLevel", "atn-cpdlc.blockLevel",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_2_OF_LevelType", HFILL }},
{ &hf_atn_cpdlc_blockLevel_item,
{ "LevelType", "atn-cpdlc.LevelType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LevelType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_LevelLevel_item,
{ "Level", "atn-cpdlc.Level",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_procedureName,
{ "procedureName", "atn-cpdlc.procedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelProcedureName,
{ "levelProcedureName", "atn-cpdlc.levelProcedureName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelspeed_speed,
{ "speed", "atn-cpdlc.speed",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_speeds,
{ "speeds", "atn-cpdlc.speeds",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedSpeed", HFILL }},
{ &hf_atn_cpdlc_levelFeet,
{ "levelFeet", "atn-cpdlc.levelFeet",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelMeters,
{ "levelMeters", "atn-cpdlc.levelMeters",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelFlightLevel,
{ "levelFlightLevel", "atn-cpdlc.levelFlightLevel",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelFlightLevelMetric,
{ "levelFlightLevelMetric", "atn-cpdlc.levelFlightLevelMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeType,
{ "longitudeType", "atn-cpdlc.longitudeType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LongitudeType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeDirection,
{ "longitudeDirection", "atn-cpdlc.longitudeDirection",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LongitudeDirection_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeWholeDegrees,
{ "longitudeWholeDegrees", "atn-cpdlc.longitudeWholeDegrees",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latLonWholeMinutes,
{ "latLonWholeMinutes", "atn-cpdlc.latLonWholeMinutes",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeDegrees,
{ "longitudeDegrees", "atn-cpdlc.longitudeDegrees",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeDegreesMinutes,
{ "longitudeDegreesMinutes", "atn-cpdlc.longitudeDegreesMinutes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_longitudeDMS,
{ "longitudeDMS", "atn-cpdlc.longitudeDMS_element",
FT_NONE, BASE_NONE, NULL, 0,
"LongitudeDegreesMinutesSeconds", HFILL }},
{ &hf_atn_cpdlc_navaid_name,
{ "name", "atn-cpdlc.name",
FT_STRING, BASE_NONE, NULL, 0,
"NavaidName", HFILL }},
{ &hf_atn_cpdlc_PlaceBearingPlaceBearing_item,
{ "PlaceBearing", "atn-cpdlc.PlaceBearing_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_fixName,
{ "fixName", "atn-cpdlc.fixName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_navaid,
{ "navaid", "atn-cpdlc.navaid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_airport,
{ "airport", "atn-cpdlc.airport",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levels,
{ "levels", "atn-cpdlc.levels",
FT_UINT32, BASE_DEC, NULL, 0,
"LevelLevel", HFILL }},
{ &hf_atn_cpdlc_positionlevel,
{ "positionlevel", "atn-cpdlc.positionlevel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_PositionPosition_item,
{ "Position", "atn-cpdlc.Position",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_positioncurrent,
{ "positioncurrent", "atn-cpdlc.positioncurrent",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_timeatpositioncurrent,
{ "timeatpositioncurrent", "atn-cpdlc.timeatpositioncurrent_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_fixnext,
{ "fixnext", "atn-cpdlc.fixnext",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_timeetaatfixnext,
{ "timeetaatfixnext", "atn-cpdlc.timeetaatfixnext_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_fixnextplusone,
{ "fixnextplusone", "atn-cpdlc.fixnextplusone",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_timeetaatdestination,
{ "timeetaatdestination", "atn-cpdlc.timeetaatdestination_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_remainingFuel,
{ "remainingFuel", "atn-cpdlc.remainingFuel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_temperature,
{ "temperature", "atn-cpdlc.temperature",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_winds,
{ "winds", "atn-cpdlc.winds_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_turbulence,
{ "turbulence", "atn-cpdlc.turbulence",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Turbulence_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_icing,
{ "icing", "atn-cpdlc.icing",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Icing_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedground,
{ "speedground", "atn-cpdlc.speedground",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_verticalChange,
{ "verticalChange", "atn-cpdlc.verticalChange_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_trackAngle,
{ "trackAngle", "atn-cpdlc.trackAngle",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_heading,
{ "heading", "atn-cpdlc.heading",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Degrees_vals), 0,
"Degrees", HFILL }},
{ &hf_atn_cpdlc_humidity,
{ "humidity", "atn-cpdlc.humidity",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_reportedWaypointPosition,
{ "reportedWaypointPosition", "atn-cpdlc.reportedWaypointPosition",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Position_vals), 0,
"Position", HFILL }},
{ &hf_atn_cpdlc_reportedWaypointTime,
{ "reportedWaypointTime", "atn-cpdlc.reportedWaypointTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_reportedWaypointLevel,
{ "reportedWaypointLevel", "atn-cpdlc.reportedWaypointLevel",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Level_vals), 0,
"Level", HFILL }},
{ &hf_atn_cpdlc_routeClearanceIndex,
{ "routeClearanceIndex", "atn-cpdlc.routeClearanceIndex",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_positionTime,
{ "positionTime", "atn-cpdlc.positionTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_times,
{ "times", "atn-cpdlc.times",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeTime", HFILL }},
{ &hf_atn_cpdlc_unitname,
{ "unitname", "atn-cpdlc.unitname_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_frequency,
{ "frequency", "atn-cpdlc.frequency",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Frequency_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_type,
{ "type", "atn-cpdlc.type",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ProcedureType_vals), 0,
"ProcedureType", HFILL }},
{ &hf_atn_cpdlc_procedure,
{ "procedure", "atn-cpdlc.procedure",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_transition,
{ "transition", "atn-cpdlc.transition",
FT_STRING, BASE_NONE, NULL, 0,
"ProcedureTransition", HFILL }},
{ &hf_atn_cpdlc_personsOnBoard,
{ "personsOnBoard", "atn-cpdlc.personsOnBoard",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_latLonReportingPoints,
{ "latLonReportingPoints", "atn-cpdlc.latLonReportingPoints",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_LatLonReportingPoints_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_degreeIncrement,
{ "degreeIncrement", "atn-cpdlc.degreeIncrement",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_procedureDeparture,
{ "procedureDeparture", "atn-cpdlc.procedureDeparture_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_runwayArrival,
{ "runwayArrival", "atn-cpdlc.runwayArrival_element",
FT_NONE, BASE_NONE, NULL, 0,
"Runway", HFILL }},
{ &hf_atn_cpdlc_procedureApproach,
{ "procedureApproach", "atn-cpdlc.procedureApproach_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_procedureArrival,
{ "procedureArrival", "atn-cpdlc.procedureArrival_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProcedureName", HFILL }},
{ &hf_atn_cpdlc_routeInformations,
{ "routeInformations", "atn-cpdlc.routeInformations",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_128_OF_RouteInformation", HFILL }},
{ &hf_atn_cpdlc_routeInformations_item,
{ "RouteInformation", "atn-cpdlc.RouteInformation",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_RouteInformation_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_routeInformationAdditional,
{ "routeInformationAdditional", "atn-cpdlc.routeInformationAdditional_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTSRouteDesignator,
{ "aTSRouteDesignator", "atn-cpdlc.aTSRouteDesignator",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_aTWAlongTrackWaypoints,
{ "aTWAlongTrackWaypoints", "atn-cpdlc.aTWAlongTrackWaypoints",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_ATWAlongTrackWaypoint", HFILL }},
{ &hf_atn_cpdlc_aTWAlongTrackWaypoints_item,
{ "ATWAlongTrackWaypoint", "atn-cpdlc.ATWAlongTrackWaypoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_reportingpoints,
{ "reportingpoints", "atn-cpdlc.reportingpoints_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_interceptCourseFroms,
{ "interceptCourseFroms", "atn-cpdlc.interceptCourseFroms",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_4_OF_InterceptCourseFrom", HFILL }},
{ &hf_atn_cpdlc_interceptCourseFroms_item,
{ "InterceptCourseFrom", "atn-cpdlc.InterceptCourseFrom_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_holdAtWaypoints,
{ "holdAtWaypoints", "atn-cpdlc.holdAtWaypoints",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_Holdatwaypoint", HFILL }},
{ &hf_atn_cpdlc_holdAtWaypoints_item,
{ "Holdatwaypoint", "atn-cpdlc.Holdatwaypoint_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_waypointSpeedLevels,
{ "waypointSpeedLevels", "atn-cpdlc.waypointSpeedLevels",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_32_OF_WaypointSpeedLevel", HFILL }},
{ &hf_atn_cpdlc_waypointSpeedLevels_item,
{ "WaypointSpeedLevel", "atn-cpdlc.WaypointSpeedLevel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rTARequiredTimeArrivals,
{ "rTARequiredTimeArrivals", "atn-cpdlc.rTARequiredTimeArrivals",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_32_OF_RTARequiredTimeArrival", HFILL }},
{ &hf_atn_cpdlc_rTARequiredTimeArrivals_item,
{ "RTARequiredTimeArrival", "atn-cpdlc.RTARequiredTimeArrival_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rTATime,
{ "rTATime", "atn-cpdlc.rTATime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rTATolerance,
{ "rTATolerance", "atn-cpdlc.rTATolerance",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_runway_direction,
{ "direction", "atn-cpdlc.direction",
FT_UINT32, BASE_DEC, NULL, 0,
"RunwayDirection", HFILL }},
{ &hf_atn_cpdlc_configuration,
{ "configuration", "atn-cpdlc.configuration",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_RunwayConfiguration_vals), 0,
"RunwayConfiguration", HFILL }},
{ &hf_atn_cpdlc_runway,
{ "runway", "atn-cpdlc.runway_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rVR,
{ "rVR", "atn-cpdlc.rVR",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_RVR_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rVRFeet,
{ "rVRFeet", "atn-cpdlc.rVRFeet",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_rVRMeters,
{ "rVRMeters", "atn-cpdlc.rVRMeters",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedIndicated,
{ "speedIndicated", "atn-cpdlc.speedIndicated",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedIndicatedMetric,
{ "speedIndicatedMetric", "atn-cpdlc.speedIndicatedMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedTrue,
{ "speedTrue", "atn-cpdlc.speedTrue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedTrueMetric,
{ "speedTrueMetric", "atn-cpdlc.speedTrueMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedGround,
{ "speedGround", "atn-cpdlc.speedGround",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedGroundMetric,
{ "speedGroundMetric", "atn-cpdlc.speedGroundMetric",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedMach,
{ "speedMach", "atn-cpdlc.speedMach",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_SpeedSpeed_item,
{ "Speed", "atn-cpdlc.Speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_Speed_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_SpeedTypeSpeedTypeSpeedType_item,
{ "SpeedType", "atn-cpdlc.SpeedType",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_SpeedType_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedTypes,
{ "speedTypes", "atn-cpdlc.speedTypes",
FT_UINT32, BASE_DEC, NULL, 0,
"SpeedTypeSpeedTypeSpeedType", HFILL }},
{ &hf_atn_cpdlc_hours,
{ "hours", "atn-cpdlc.hours",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeHours", HFILL }},
{ &hf_atn_cpdlc_minutes,
{ "minutes", "atn-cpdlc.minutes",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeMinutes", HFILL }},
{ &hf_atn_cpdlc_timeDepartureAllocated,
{ "timeDepartureAllocated", "atn-cpdlc.timeDepartureAllocated_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_timeDepartureControlled,
{ "timeDepartureControlled", "atn-cpdlc.timeDepartureControlled_element",
FT_NONE, BASE_NONE, NULL, 0,
"ControlledTime", HFILL }},
{ &hf_atn_cpdlc_timeDepartureClearanceExpected,
{ "timeDepartureClearanceExpected", "atn-cpdlc.timeDepartureClearanceExpected_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_departureMinimumInterval,
{ "departureMinimumInterval", "atn-cpdlc.departureMinimumInterval",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_tofrom,
{ "tofrom", "atn-cpdlc.tofrom",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ToFrom_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_hoursminutes,
{ "hoursminutes", "atn-cpdlc.hoursminutes_element",
FT_NONE, BASE_NONE, NULL, 0,
"Time", HFILL }},
{ &hf_atn_cpdlc_seconds,
{ "seconds", "atn-cpdlc.seconds",
FT_UINT32, BASE_DEC, NULL, 0,
"TimeSeconds", HFILL }},
{ &hf_atn_cpdlc_unitName,
{ "unitName", "atn-cpdlc.unitName_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_timeposition,
{ "timeposition", "atn-cpdlc.timeposition_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_levelspeed,
{ "levelspeed", "atn-cpdlc.levelspeed_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_speedspeed,
{ "speedspeed", "atn-cpdlc.speedspeed",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_TimeTime_item,
{ "Time", "atn-cpdlc.Time_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_toFrom,
{ "toFrom", "atn-cpdlc.toFrom",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_ToFrom_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_facilityName,
{ "facilityName", "atn-cpdlc.facilityName",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_facilityFunction,
{ "facilityFunction", "atn-cpdlc.facilityFunction",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_FacilityFunction_vals), 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_vertical_direction,
{ "direction", "atn-cpdlc.direction",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalDirection_vals), 0,
"VerticalDirection", HFILL }},
{ &hf_atn_cpdlc_rate,
{ "rate", "atn-cpdlc.rate",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_VerticalRate_vals), 0,
"VerticalRate", HFILL }},
{ &hf_atn_cpdlc_verticalRateEnglish,
{ "verticalRateEnglish", "atn-cpdlc.verticalRateEnglish",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_verticalRateMetric,
{ "verticalRateMetric", "atn-cpdlc.verticalRateMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_winds_direction,
{ "direction", "atn-cpdlc.direction",
FT_UINT32, BASE_DEC, NULL, 0,
"WindDirection", HFILL }},
{ &hf_atn_cpdlc_winds_speed,
{ "speed", "atn-cpdlc.speed",
FT_UINT32, BASE_DEC, VALS(atn_cpdlc_WindSpeed_vals), 0,
"WindSpeed", HFILL }},
{ &hf_atn_cpdlc_windSpeedEnglish,
{ "windSpeedEnglish", "atn-cpdlc.windSpeedEnglish",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_atn_cpdlc_windSpeedMetric,
{ "windSpeedMetric", "atn-cpdlc.windSpeedMetric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
#line 304 "../../asn1/atn-cpdlc/packet-atn-cpdlc-template.c"
};
static gint *ett[] = {
#line 1 "../../asn1/atn-cpdlc/packet-atn-cpdlc-ettarr.c"
&ett_atn_cpdlc_GroundPDUs,
&ett_atn_cpdlc_UplinkMessage,
&ett_atn_cpdlc_AircraftPDUs,
&ett_atn_cpdlc_StartDownMessage,
&ett_atn_cpdlc_DownlinkMessage,
&ett_atn_cpdlc_ProtectedGroundPDUs,
&ett_atn_cpdlc_ProtectedUplinkMessage,
&ett_atn_cpdlc_ATCForwardMessage,
&ett_atn_cpdlc_ForwardHeader,
&ett_atn_cpdlc_ForwardMessage,
&ett_atn_cpdlc_ProtectedAircraftPDUs,
&ett_atn_cpdlc_ProtectedStartDownMessage,
&ett_atn_cpdlc_ProtectedDownlinkMessage,
&ett_atn_cpdlc_ATCUplinkMessage,
&ett_atn_cpdlc_ATCUplinkMessageData,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCUplinkMsgElementId,
&ett_atn_cpdlc_T_atcuplinkmessagedata_constraineddata,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_2_OF_RouteClearance,
&ett_atn_cpdlc_ATCDownlinkMessage,
&ett_atn_cpdlc_ATCDownlinkMessageData,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_5_OF_ATCDownlinkMsgElementId,
&ett_atn_cpdlc_T_atcdownlinkmessagedata_constraineddata,
&ett_atn_cpdlc_ATCMessageHeader,
&ett_atn_cpdlc_ATCUplinkMsgElementId,
&ett_atn_cpdlc_ATCDownlinkMsgElementId,
&ett_atn_cpdlc_Altimeter,
&ett_atn_cpdlc_ATWAlongTrackWaypoint,
&ett_atn_cpdlc_ATWLevel,
&ett_atn_cpdlc_ATWLevelSequence,
&ett_atn_cpdlc_ATWDistance,
&ett_atn_cpdlc_Code,
&ett_atn_cpdlc_ControlledTime,
&ett_atn_cpdlc_Date,
&ett_atn_cpdlc_DateTimeGroup,
&ett_atn_cpdlc_Degrees,
&ett_atn_cpdlc_DepartureClearance,
&ett_atn_cpdlc_DirectionDegrees,
&ett_atn_cpdlc_Distance,
&ett_atn_cpdlc_DistanceSpecified,
&ett_atn_cpdlc_DistanceSpecifiedDirection,
&ett_atn_cpdlc_DistanceSpecifiedDirectionTime,
&ett_atn_cpdlc_Facility,
&ett_atn_cpdlc_FacilityDesignationAltimeter,
&ett_atn_cpdlc_FacilityDesignationATISCode,
&ett_atn_cpdlc_FixName,
&ett_atn_cpdlc_FlightInformation,
&ett_atn_cpdlc_Frequency,
&ett_atn_cpdlc_FurtherInstructions,
&ett_atn_cpdlc_Holdatwaypoint,
&ett_atn_cpdlc_HoldClearance,
&ett_atn_cpdlc_InterceptCourseFrom,
&ett_atn_cpdlc_InterceptCourseFromSelection,
&ett_atn_cpdlc_Latitude,
&ett_atn_cpdlc_LatitudeDegreesMinutes,
&ett_atn_cpdlc_LatitudeDegreesMinutesSeconds,
&ett_atn_cpdlc_LatitudeLongitude,
&ett_atn_cpdlc_LatitudeReportingPoints,
&ett_atn_cpdlc_LatitudeType,
&ett_atn_cpdlc_LatLonReportingPoints,
&ett_atn_cpdlc_LegDistance,
&ett_atn_cpdlc_LegType,
&ett_atn_cpdlc_Level,
&ett_atn_cpdlc_SEQUENCE_SIZE_2_OF_LevelType,
&ett_atn_cpdlc_LevelLevel,
&ett_atn_cpdlc_LevelPosition,
&ett_atn_cpdlc_LevelProcedureName,
&ett_atn_cpdlc_LevelsOfFlight,
&ett_atn_cpdlc_LevelSpeed,
&ett_atn_cpdlc_LevelSpeedSpeed,
&ett_atn_cpdlc_LevelTime,
&ett_atn_cpdlc_LevelType,
&ett_atn_cpdlc_Longitude,
&ett_atn_cpdlc_LongitudeDegreesMinutes,
&ett_atn_cpdlc_LongitudeDegreesMinutesSeconds,
&ett_atn_cpdlc_LongitudeReportingPoints,
&ett_atn_cpdlc_LongitudeType,
&ett_atn_cpdlc_Navaid,
&ett_atn_cpdlc_PlaceBearing,
&ett_atn_cpdlc_PlaceBearingDistance,
&ett_atn_cpdlc_PlaceBearingPlaceBearing,
&ett_atn_cpdlc_Position,
&ett_atn_cpdlc_PositionDegrees,
&ett_atn_cpdlc_PositionDistanceSpecifiedDirection,
&ett_atn_cpdlc_PositionLevel,
&ett_atn_cpdlc_PositionLevelLevel,
&ett_atn_cpdlc_PositionLevelSpeed,
&ett_atn_cpdlc_PositionPosition,
&ett_atn_cpdlc_PositionProcedureName,
&ett_atn_cpdlc_PositionReport,
&ett_atn_cpdlc_PositionRouteClearanceIndex,
&ett_atn_cpdlc_PositionSpeed,
&ett_atn_cpdlc_PositionSpeedSpeed,
&ett_atn_cpdlc_PositionTime,
&ett_atn_cpdlc_PositionTimeLevel,
&ett_atn_cpdlc_PositionTimeTime,
&ett_atn_cpdlc_PositionUnitNameFrequency,
&ett_atn_cpdlc_ProcedureName,
&ett_atn_cpdlc_PublishedIdentifier,
&ett_atn_cpdlc_RemainingFuelPersonsOnBoard,
&ett_atn_cpdlc_ReportingPoints,
&ett_atn_cpdlc_RouteAndLevels,
&ett_atn_cpdlc_RouteClearance,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_128_OF_RouteInformation,
&ett_atn_cpdlc_RouteInformation,
&ett_atn_cpdlc_RouteInformationAdditional,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_ATWAlongTrackWaypoint,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_4_OF_InterceptCourseFrom,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_8_OF_Holdatwaypoint,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_WaypointSpeedLevel,
&ett_atn_cpdlc_SEQUENCE_SIZE_1_32_OF_RTARequiredTimeArrival,
&ett_atn_cpdlc_RTARequiredTimeArrival,
&ett_atn_cpdlc_RTATime,
&ett_atn_cpdlc_Runway,
&ett_atn_cpdlc_RunwayRVR,
&ett_atn_cpdlc_RVR,
&ett_atn_cpdlc_Speed,
&ett_atn_cpdlc_SpeedSpeed,
&ett_atn_cpdlc_SpeedTime,
&ett_atn_cpdlc_SpeedTypeSpeedTypeSpeedType,
&ett_atn_cpdlc_SpeedTypeSpeedTypeSpeedTypeSpeed,
&ett_atn_cpdlc_Time,
&ett_atn_cpdlc_TimeLevel,
&ett_atn_cpdlc_TimeDeparture,
&ett_atn_cpdlc_TimeDistanceSpecifiedDirection,
&ett_atn_cpdlc_TimeDistanceToFromPosition,
&ett_atn_cpdlc_Timehhmmss,
&ett_atn_cpdlc_TimeUnitNameFrequency,
&ett_atn_cpdlc_TimePosition,
&ett_atn_cpdlc_TimePositionLevel,
&ett_atn_cpdlc_TimePositionLevelSpeed,
&ett_atn_cpdlc_TimeSpeed,
&ett_atn_cpdlc_TimeSpeedSpeed,
&ett_atn_cpdlc_TimeTime,
&ett_atn_cpdlc_TimeToFromPosition,
&ett_atn_cpdlc_ToFromPosition,
&ett_atn_cpdlc_UnitName,
&ett_atn_cpdlc_UnitNameFrequency,
&ett_atn_cpdlc_VerticalChange,
&ett_atn_cpdlc_VerticalRate,
&ett_atn_cpdlc_WaypointSpeedLevel,
&ett_atn_cpdlc_Winds,
&ett_atn_cpdlc_WindSpeed,
#line 308 "../../asn1/atn-cpdlc/packet-atn-cpdlc-template.c"
&ett_atn_cpdlc
};
proto_atn_cpdlc = proto_register_protocol(
ATN_CPDLC_PROTO ,
"ATN-CPDLC",
"atn-cpdlc");
proto_register_field_array(
proto_atn_cpdlc,
hf_atn_cpdlc,
array_length(hf_atn_cpdlc));
proto_register_subtree_array(
ett,
array_length(ett));
new_register_dissector(
"atn-cpdlc",
dissect_atn_cpdlc,
proto_atn_cpdlc);
}
void proto_reg_handoff_atn_cpdlc(void)
{
heur_dissector_add(
"atn-ulcs",
dissect_atn_cpdlc_heur,
"ATN-CPDLC over ATN-ULCS",
"atn-cpdlc-ulcs",
proto_atn_cpdlc, HEURISTIC_ENABLE);
}
