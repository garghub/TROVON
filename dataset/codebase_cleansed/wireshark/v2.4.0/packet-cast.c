static int
dissect_cast_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint32 hdr_data_length;
guint32 hdr_marker;
guint32 data_messageid;
const gchar *messageid_str;
guint i = 0;
guint t = 0;
int count;
int val;
proto_item *ti;
proto_tree *cast_tree = NULL;
proto_tree *cast_sub_tree;
proto_tree *cast_sub_tree_sav;
proto_tree *cast_sub_tree_sav_sav;
hdr_data_length = tvb_get_letohl(tvb, offset);
hdr_marker = tvb_get_letohl(tvb, offset+4);
data_messageid = tvb_get_letohl(tvb, offset+8);
if (tree) {
ti = proto_tree_add_item(tree, proto_cast, tvb, offset, hdr_data_length+8, ENC_NA);
cast_tree = proto_item_add_subtree(ti, ett_cast);
proto_tree_add_uint(cast_tree, hf_cast_data_length, tvb, offset, 4, hdr_data_length);
proto_tree_add_uint(cast_tree, hf_cast_reserved, tvb, offset+4, 4, hdr_marker);
}
messageid_str = val_to_str(data_messageid, message_id, "0x%08X (Unknown)");
col_add_str(pinfo->cinfo, COL_INFO, messageid_str);
if (tree) {
proto_tree_add_uint(cast_tree, hf_cast_messageid, tvb,offset+8, 4, data_messageid );
}
if (tree) {
switch(data_messageid) {
case 0x0 :
break;
case 0x1 :
proto_tree_add_item(cast_tree, hf_cast_version, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x2 :
proto_tree_add_item(cast_tree, hf_cast_version, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x3 :
proto_tree_add_item(cast_tree, hf_cast_videoCapCount, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_dataCapCount, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_RTPPayloadFormat, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_customPictureFormatCount, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
count = offset+28;
for ( i = 0; i < MAX_CUSTOM_PICTURES; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_tree, tvb, offset, 20, ett_cast_tree, NULL, "customPictureFormat[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_pictureWidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_pictureHeight, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_pixelAspectRatio, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_clockConversionCode, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_clockDivisor, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "confResources");
proto_tree_add_item(cast_sub_tree, hf_cast_activeStreamsOnRegistration, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_maxBW, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_serviceResourceCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
cast_sub_tree_sav = cast_sub_tree;
for ( i = 0; i < MAX_SERVICE_TYPE; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 20, ett_cast_tree, NULL, "serviceResource[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_layoutCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
cast_sub_tree_sav_sav = cast_sub_tree_sav;
for ( t = 0; t < MAX_LAYOUT_WITH_SAME_SERVICE; t++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 20, ett_cast_tree, NULL, "layouts[%d]", t);
proto_tree_add_item(cast_sub_tree, hf_cast_layout, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
cast_sub_tree = cast_sub_tree_sav_sav;
proto_tree_add_item(cast_sub_tree, hf_cast_serviceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_maxStreams, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_maxConferences, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_activeConferenceOnRegistration, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
for ( i = 0; i < StationMaxVideoCapabilities; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_tree, tvb, offset, 20, ett_cast_tree, NULL, "vidCaps[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_payloadCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_transmitOrReceive, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_levelPreferenceCount, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
cast_sub_tree_sav = cast_sub_tree;
for ( t = 0; t < MAX_LEVEL_PREFERENCE; t++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 20, ett_cast_tree, NULL, "levelPreference[%d]", t);
proto_tree_add_item(cast_sub_tree, hf_cast_transmitPreference, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_maxBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_minBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_serviceNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h261VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_stillImageTransmission, tvb, count+4, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h263VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_annexNandWFutureUse, tvb, count+4, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "vieoVideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
for ( i = 0; i < StationMaxDataCapabilities; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_tree, tvb, offset, 20, ett_cast_tree, NULL, "dataCaps[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_payloadCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_transmitOrReceive, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_protocolDependentData, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
proto_tree_add_item(cast_sub_tree, hf_cast_maxBitRate, tvb, count, 4, ENC_LITTLE_ENDIAN);
count+= 4;
}
break;
case 0x4 :
break;
case 0x5 :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payloadCapability, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payload_rfc_number, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payloadType, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_isConferenceCreator, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 12, ett_cast_tree, NULL, "audioParameters");
proto_tree_add_item(cast_sub_tree, hf_cast_millisecondPacketSize, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_echoCancelType, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_g723BitRate, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 30, ett_cast_tree, NULL, "videoParameters");
proto_tree_add_item(cast_sub_tree, hf_cast_bitRate, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_pictureFormatCount, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree_sav = cast_sub_tree;
count = offset+52;
for ( i = 0; i < MAX_PICTURE_FORMAT; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 8 * MAX_PICTURE_FORMAT, ett_cast_tree, NULL, "pictureFormat[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
cast_sub_tree = cast_sub_tree_sav;
proto_tree_add_item(cast_sub_tree, hf_cast_confServiceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h261VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_stillImageTransmission, tvb, count+4, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h263VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_annexNandWFutureUse, tvb, count+4, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "vieoVideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "dataParameters");
proto_tree_add_item(cast_sub_tree, hf_cast_protocolDependentData, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_maxBitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
break;
case 0x6 :
proto_tree_add_item(cast_tree, hf_cast_ORCStatus, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_ipAddress, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_portNumber, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
break;
case 0x7 :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
break;
case 0x8 :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payloadCapability, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_ipAddress, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_portNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payload_rfc_number, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_payloadType, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_DSCPValue, tvb, offset+44, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 30, ett_cast_tree, NULL, "videoParameters");
proto_tree_add_item(cast_sub_tree, hf_cast_bitRate, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_pictureFormatCount, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree_sav = cast_sub_tree;
count = offset+56;
for ( i = 0; i < MAX_PICTURE_FORMAT; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 8 * MAX_PICTURE_FORMAT,
ett_cast_tree, NULL, "pictureFormat[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_format, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_MPI, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
}
cast_sub_tree = cast_sub_tree_sav;
proto_tree_add_item(cast_sub_tree, hf_cast_confServiceNum, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
val = count;
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h261VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_temporalSpatialTradeOffCapability, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_stillImageTransmission, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "h263VideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_h263_capability_bitfield, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_annexNandWFutureUse, tvb, count, 4, ENC_LITTLE_ENDIAN);
count = val;
cast_sub_tree = proto_tree_add_subtree(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "vieoVideoCapability");
proto_tree_add_item(cast_sub_tree, hf_cast_modelNumber, tvb, count, 4, ENC_LITTLE_ENDIAN);
count += 4;
proto_tree_add_item(cast_sub_tree, hf_cast_bandwidth, tvb, count, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "dataParameters");
proto_tree_add_item(cast_sub_tree, hf_cast_protocolDependentData, tvb, offset+48, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_maxBitRate, tvb, offset+52, 4, ENC_LITTLE_ENDIAN);
break;
case 0x9 :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
break;
case 0xA :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_miscCommandType, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "videoFastUpdateGOB");
proto_tree_add_item(cast_sub_tree, hf_cast_firstGOB, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_numberOfGOBs, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "videoFastUpdateGOB");
proto_tree_add_item(cast_sub_tree, hf_cast_firstGOB, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_firstMB, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_numberOfMBs, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "lostPicture");
proto_tree_add_item(cast_sub_tree, hf_cast_pictureNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_longTermPictureIndex, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "lostPartialPicture");
proto_tree_add_item(cast_sub_tree, hf_cast_pictureNumber, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_longTermPictureIndex, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_firstMB, tvb, offset+36, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_numberOfMBs, tvb, offset+40, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "recoveryReferencePicture");
proto_tree_add_item(cast_sub_tree, hf_cast_recoveryReferencePictureCount, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
cast_sub_tree_sav = cast_sub_tree;
for ( i = 0; i < MAX_REFERENCE_PICTURE; i++ ) {
cast_sub_tree = proto_tree_add_subtree_format(cast_sub_tree_sav, tvb, offset, 8, ett_cast_tree, NULL, "recoveryReferencePicture[%d]", i);
proto_tree_add_item(cast_sub_tree, hf_cast_pictureNumber, tvb, offset+32+(i*8), 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_longTermPictureIndex, tvb, offset+36+(i*8), 4, ENC_LITTLE_ENDIAN);
}
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 4, ett_cast_tree, NULL, "temporalSpatialTradeOff");
proto_tree_add_item(cast_sub_tree, hf_cast_temporalSpatialTradeOff, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
break;
case 0xB :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_passThruPartyID, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_maxBitRate, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
break;
case 0xC :
proto_tree_add_item(cast_tree, hf_cast_conferenceID, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_serviceNum, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0xD :
proto_tree_add_item(cast_tree, hf_cast_callState, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+20, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_privacy, tvb, offset+24, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_precedenceLv, tvb, offset+28, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_precedenceDm, tvb, offset+32, 4, ENC_LITTLE_ENDIAN);
break;
case 0xE :
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0xF :
break;
case 0x10 :
i = offset+12;
proto_tree_add_item(cast_tree, hf_cast_callingPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_callingParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_calledPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_calledParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_callType, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_originalCalledPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_originalCalledParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_lastRedirectingPartyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_lastRedirectingParty, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_originalCdpnRedirectReason, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_lastRedirectingReason, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_cgpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_cdpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_originalCdpnVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_lastRedirectingVoiceMailbox, tvb, i, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
i += StationMaxDirnumSize;
proto_tree_add_item(cast_tree, hf_cast_callInstance, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_callSecurityStatus, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
cast_sub_tree = proto_tree_add_subtree(cast_tree, tvb, offset, 8, ett_cast_tree, NULL, "partyPIRestrictionBits");
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_CallingPartyName, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_CallingPartyNumber, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_CalledPartyName, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_CalledPartyNumber, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_OriginalCalledPartyName, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_OriginalCalledPartyNumber, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_LastRedirectPartyName, tvb, i, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_sub_tree, hf_cast_partyPIRestrictionBits_LastRedirectPartyNumber, tvb, i, 4, ENC_LITTLE_ENDIAN);
break;
case 0x11 :
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x12 :
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cast_tree, hf_cast_callIdentifier, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x13 :
proto_tree_add_item(cast_tree, hf_cast_calledParty, tvb, offset+12, StationMaxDirnumSize, ENC_ASCII|ENC_NA);
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+16, 4, ENC_LITTLE_ENDIAN);
break;
case 0x14 :
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x15 :
proto_tree_add_item(cast_tree, hf_cast_lineInstance, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x40 :
break;
case 0x41 :
break;
case 0x42 :
break;
case 0x43 :
break;
case 0x44 :
break;
case 0x45 :
break;
case 0x46 :
break;
case 0x47 :
proto_tree_add_item(cast_tree, hf_cast_audio, tvb, offset+12, 4, ENC_LITTLE_ENDIAN);
break;
case 0x50 :
break;
case 0x51 :
break;
case 0x60 :
break;
case 0x61 :
break;
case 0x62 :
break;
case 0x70 :
break;
case 0x71 :
break;
case 0x74 :
break;
case 0x75 :
break;
case 0x80 :
break;
case 0x90 :
i = offset+12;
proto_tree_add_item(cast_tree, hf_cast_stationFriendlyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_stationGUID, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_requestorIpAddress, tvb, i, 4, ENC_LITTLE_ENDIAN);
break;
case 0x91 :
i = offset+12;
proto_tree_add_item(cast_tree, hf_cast_stationFriendlyName, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_stationGUID, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
i += StationMaxNameSize;
proto_tree_add_item(cast_tree, hf_cast_stationIpAddress, tvb, i, 4, ENC_LITTLE_ENDIAN);
i += 4;
proto_tree_add_item(cast_tree, hf_cast_directoryNumber, tvb, i, StationMaxNameSize, ENC_ASCII|ENC_NA);
break;
case 0xA0 :
break;
case 0xA1 :
break;
case 0xA4 :
break;
case 0xA5 :
break;
case 0xB0 :
break;
case 0xB1 :
break;
case 0xB4 :
break;
case 0xB5 :
break;
case 0xC0 :
break;
case 0xC1 :
break;
case 0xC4 :
break;
case 0xC5 :
break;
case 0xCC :
break;
case 0xD0 :
break;
case 0xD1 :
break;
default:
break;
}
}
return tvb_reported_length(tvb);
}
static guint
get_cast_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint32 hdr_data_length;
hdr_data_length = tvb_get_letohl(tvb, offset);
return hdr_data_length + 8;
}
static int
dissect_cast(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint32 hdr_data_length;
guint32 hdr_marker;
hdr_data_length = tvb_get_letohl(tvb, 0);
hdr_marker = tvb_get_letohl(tvb, 4);
if (hdr_data_length < 4 || hdr_marker != 0) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CAST");
col_set_str(pinfo->cinfo, COL_INFO, "Cast Client Control Protocol");
tcp_dissect_pdus(tvb, pinfo, tree, cast_desegment, 4, get_cast_pdu_len, dissect_cast_pdu, data);
return tvb_reported_length(tvb);
}
void
proto_register_cast(void)
{
static hf_register_info hf[] = {
{ &hf_cast_data_length,
{ "Data Length", "cast.data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of bytes in the data portion.",
HFILL }
},
{ &hf_cast_reserved,
{ "Marker", "cast.marker",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Marker value should ne zero.",
HFILL }
},
{ &hf_cast_messageid,
{ "Message ID", "cast.messageid",
FT_UINT32, BASE_HEX, VALS(message_id), 0x0,
"The function requested/done with this message.",
HFILL }
},
{ &hf_cast_version,
{ "Version", "cast.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The version in the keepalive version messages.",
HFILL }
},
{ &hf_cast_ORCStatus,
{ "ORCStatus", "cast.ORCStatus",
FT_UINT32, BASE_DEC, VALS(orcStatus), 0x0,
"The status of the opened receive channel.",
HFILL }
},
{ &hf_cast_ipAddress,
{ "IP Address", "cast.ipAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_portNumber,
{ "Port Number", "cast.portNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_passThruPartyID,
{ "PassThruPartyID", "cast.passThruPartyID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_callIdentifier,
{ "Call Identifier", "cast.callIdentifier",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Call identifier for this call.",
HFILL }
},
{ &hf_cast_conferenceID,
{ "Conference ID", "cast.conferenceID",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_payloadType,
{ "PayloadType", "cast.payloadType",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_lineInstance,
{ "Line Instance", "cast.lineInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The display call plane associated with this call.",
HFILL }
},
{ &hf_cast_payloadCapability,
{ "PayloadCapability", "cast.payloadCapability",
FT_UINT32, BASE_DEC, VALS(mediaPayloads), 0x0,
"The payload capability for this media capability structure.",
HFILL }
},
{ &hf_cast_isConferenceCreator,
{ "IsConferenceCreator", "cast.isConferenceCreator",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_payload_rfc_number,
{ "Payload_rfc_number", "cast.payload_rfc_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_videoCapCount,
{ "VideoCapCount", "cast.videoCapCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_dataCapCount,
{ "DataCapCount", "cast.dataCapCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_RTPPayloadFormat,
{ "RTPPayloadFormat", "cast.RTPPayloadFormat",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_customPictureFormatCount,
{ "CustomPictureFormatCount", "cast.customPictureFormatCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_pictureWidth,
{ "PictureWidth", "cast.pictureWidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_pictureHeight,
{ "PictureHeight", "cast.pictureHeight",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_pixelAspectRatio,
{ "PixelAspectRatio", "cast.pixelAspectRatio",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_clockConversionCode,
{ "ClockConversionCode", "cast.clockConversionCode",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_clockDivisor,
{ "ClockDivisor", "cast.clockDivisor",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_activeStreamsOnRegistration,
{ "ActiveStreamsOnRegistration", "cast.activeStreamsOnRegistration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_maxBW,
{ "MaxBW", "cast.maxBW",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_serviceResourceCount,
{ "ServiceResourceCount", "cast.serviceResourceCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_layoutCount,
{ "LayoutCount", "cast.layoutCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_layout,
{ "Layout", "cast.layout",
FT_UINT32, BASE_DEC, VALS(cast_Layouts), 0x0,
NULL, HFILL }
},
{ &hf_cast_maxConferences,
{ "MaxConferences", "cast.maxConferences",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_activeConferenceOnRegistration,
{ "ActiveConferenceOnRegistration", "cast.activeConferenceOnRegistration",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_transmitOrReceive,
{ "TransmitOrReceive", "cast.transmitOrReceive",
FT_UINT32, BASE_DEC, VALS(cast_transmitOrReceive), 0x0,
NULL, HFILL }
},
{ &hf_cast_levelPreferenceCount,
{ "LevelPreferenceCount", "cast.levelPreferenceCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_transmitPreference,
{ "TransmitPreference", "cast.transmitPreference",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_format,
{ "Format", "cast.format",
FT_UINT32, BASE_DEC, VALS(cast_formatTypes), 0x0,
NULL, HFILL }
},
{ &hf_cast_maxBitRate,
{ "MaxBitRate", "cast.maxBitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_minBitRate,
{ "MinBitRate", "cast.minBitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_MPI,
{ "MPI", "cast.MPI",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_serviceNumber,
{ "ServiceNumber", "cast.serviceNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_temporalSpatialTradeOffCapability,
{ "TemporalSpatialTradeOffCapability", "cast.temporalSpatialTradeOffCapability",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_stillImageTransmission,
{ "StillImageTransmission", "cast.stillImageTransmission",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_h263_capability_bitfield,
{ "H263_capability_bitfield", "cast.h263_capability_bitfield",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_annexNandWFutureUse,
{ "AnnexNandWFutureUse", "cast.annexNandWFutureUse",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_modelNumber,
{ "ModelNumber", "cast.modelNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_bandwidth,
{ "Bandwidth", "cast.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_protocolDependentData,
{ "ProtocolDependentData", "cast.protocolDependentData",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_DSCPValue,
{ "DSCPValue", "cast.DSCPValue",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_serviceNum,
{ "ServiceNum", "cast.serviceNum",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_cast_precedenceValue,
{ "Precedence", "cast.precedenceValue",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_cast_maxStreams,
{ "MaxStreams", "cast.maxStreams",
FT_UINT32, BASE_DEC, NULL, 0x0,
"32 bit unsigned integer indicating the maximum number of simultansous RTP duplex streams that the client can handle.",
HFILL }
},
{ &hf_cast_millisecondPacketSize,
{ "MS/Packet", "cast.millisecondPacketSize",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of milliseconds of conversation in each packet",
HFILL }
},
{ &hf_cast_echoCancelType,
{ "Echo Cancel Type", "cast.echoCancelType",
FT_UINT32, BASE_DEC, VALS(cast_echoCancelTypes), 0x0,
"Is echo cancelling enabled or not",
HFILL }
},
{ &hf_cast_g723BitRate,
{ "G723 BitRate", "cast.g723BitRate",
FT_UINT32, BASE_DEC, VALS(cast_g723BitRates), 0x0,
"The G723 bit rate for this stream/JUNK if not g723 stream",
HFILL }
},
{ &hf_cast_pictureFormatCount,
{ "PictureFormatCount", "cast.pictureFormatCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_confServiceNum,
{ "ConfServiceNum", "cast.confServiceNum",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_miscCommandType,
{ "MiscCommandType", "cast.miscCommandType",
FT_UINT32, BASE_DEC, VALS(cast_miscCommandType), 0x0,
NULL, HFILL }
},
{ &hf_cast_temporalSpatialTradeOff,
{ "TemporalSpatialTradeOff", "cast.temporalSpatialTradeOff",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_firstGOB,
{ "FirstGOB", "cast.firstGOB",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_numberOfGOBs,
{ "NumberOfGOBs", "cast.numberOfGOBs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_firstMB,
{ "FirstMB", "cast.firstMB",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_numberOfMBs,
{ "NumberOfMBs", "cast.numberOfMBs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_pictureNumber,
{ "PictureNumber", "cast.pictureNumber",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_longTermPictureIndex,
{ "LongTermPictureIndex", "cast.longTermPictureIndex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"LongTermPictureIndex.",
HFILL }
},
{ &hf_cast_recoveryReferencePictureCount,
{ "RecoveryReferencePictureCount", "cast.recoveryReferencePictureCount",
FT_UINT32, BASE_DEC, NULL, 0x0,
"RecoveryReferencePictureCount.",
HFILL }
},
{ &hf_cast_calledParty,
{ "CalledParty", "cast.calledParty",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number called.",
HFILL }
},
{ &hf_cast_privacy,
{ "Privacy", "cast.privacy",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_precedenceLv,
{ "PrecedenceLv", "cast.precedenceLv",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_precedenceDm,
{ "PrecedenceDm", "cast.precedenceDm",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_callState,
{ "CallState", "cast.callState",
FT_UINT32, BASE_DEC, VALS(cast_callStateTypes), 0x0,
NULL, HFILL }
},
{ &hf_cast_callingPartyName,
{ "Calling Party Name", "cast.callingPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The passed name of the calling party.",
HFILL }
},
{ &hf_cast_callingParty,
{ "Calling Party", "cast.callingParty",
FT_STRING, BASE_NONE, NULL, 0x0,
"The passed number of the calling party.",
HFILL }
},
{ &hf_cast_calledPartyName,
{ "Called Party Name", "cast.calledPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
"The name of the party we are calling.",
HFILL }
},
{ &hf_cast_callType,
{ "Call Type", "cast.callType",
FT_UINT32, BASE_DEC, VALS(cast_callTypes), 0x0,
"What type of call, in/out/etc",
HFILL }
},
{ &hf_cast_originalCalledPartyName,
{ "Original Called Party Name", "cast.originalCalledPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
"name of the original person who placed the call.",
HFILL }
},
{ &hf_cast_originalCalledParty,
{ "Original Called Party", "cast.originalCalledParty",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number of the original calling party.",
HFILL }
},
{ &hf_cast_lastRedirectingPartyName,
{ "LastRedirectingPartyName", "cast.lastRedirectingPartyName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_lastRedirectingParty,
{ "LastRedirectingParty", "cast.lastRedirectingParty",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_cgpnVoiceMailbox,
{ "CgpnVoiceMailbox", "cast.cgpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_cdpnVoiceMailbox,
{ "CdpnVoiceMailbox", "cast.cdpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_originalCdpnVoiceMailbox,
{ "OriginalCdpnVoiceMailbox", "cast.originalCdpnVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_lastRedirectingVoiceMailbox,
{ "LastRedirectingVoiceMailbox", "cast.lastRedirectingVoiceMailbox",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_originalCdpnRedirectReason,
{ "OriginalCdpnRedirectReason", "cast.originalCdpnRedirectReason",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_lastRedirectingReason,
{ "LastRedirectingReason", "cast.lastRedirectingReason",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_callInstance,
{ "CallInstance", "cast.callInstance",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_callSecurityStatus,
{ "CallSecurityStatus", "cast.callSecurityStatus",
FT_UINT32, BASE_DEC, VALS(cast_callSecurityStatusTypes), 0x0,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_CallingPartyName,
{ "RestrictCallingPartyName", "cast.partyPIRestrictionBits.CallingPartyName",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_CallingPartyNumber,
{ "RestrictCallingPartyNumber", "cast.partyPIRestrictionBits.CallingPartyNumber",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_CalledPartyName,
{ "RestrictCalledPartyName", "cast.partyPIRestrictionBits.CalledPartyName",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x04,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_CalledPartyNumber,
{ "RestrictCalledPartyNumber", "cast.partyPIRestrictionBits.CalledPartyNumber",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_OriginalCalledPartyName,
{ "RestrictOriginalCalledPartyName", "cast.partyPIRestrictionBits.OriginalCalledPartyName",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x10,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_OriginalCalledPartyNumber,
{ "RestrictOriginalCalledPartyNumber", "cast.partyPIRestrictionBits.OriginalCalledPartyNumber",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x20,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_LastRedirectPartyName,
{ "RestrictLastRedirectPartyName", "cast.partyPIRestrictionBits.LastRedirectPartyName",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x40,
NULL, HFILL }
},
{ &hf_cast_partyPIRestrictionBits_LastRedirectPartyNumber,
{ "RestrictLastRedirectPartyNumber", "cast.partyPIRestrictionBits.LastRedirectPartyNumber",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x80,
NULL, HFILL }
},
{ &hf_cast_directoryNumber,
{ "Directory Number", "cast.directoryNumber",
FT_STRING, BASE_NONE, NULL, 0x0,
"The number we are reporting statistics for.",
HFILL }
},
{ &hf_cast_requestorIpAddress,
{ "RequestorIpAddress", "cast.requestorIpAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_stationIpAddress,
{ "StationIpAddress", "cast.stationIpAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_stationFriendlyName,
{ "StationFriendlyName", "cast.stationFriendlyName",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_stationGUID,
{ "stationGUID", "cast.stationGUID",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cast_audio,
{ "AudioCodec", "cast.audio",
FT_UINT32, BASE_DEC, VALS(audioCodecTypes), 0x0,
"The audio codec that is in use.",
HFILL }
},
{ &hf_cast_bitRate,
{ "BitRate", "cast.bitRate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_cast,
&ett_cast_tree,
};
module_t *cast_module;
proto_cast = proto_register_protocol("Cast Client Control Protocol",
"CAST", "cast");
proto_register_field_array(proto_cast, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cast_module = prefs_register_protocol(proto_cast, NULL);
prefs_register_bool_preference(cast_module, "reassembly",
"Reassemble CAST messages spanning multiple TCP segments",
"Whether the CAST dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&cast_desegment);
}
void
proto_reg_handoff_cast(void)
{
dissector_handle_t cast_handle;
cast_handle = create_dissector_handle(dissect_cast, proto_cast);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_CAST, cast_handle);
}
