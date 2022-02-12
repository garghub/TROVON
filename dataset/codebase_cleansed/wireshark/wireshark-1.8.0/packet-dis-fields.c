void initializeFieldParsers(void)
{
initializeParser(DIS_FIELDS_VP_GENERIC);
initializeParser(DIS_FIELDS_VP_ARTICULATED_PART);
initializeParser(DIS_FIELDS_VP_ATTACHED_PART);
initializeParser(DIS_FIELDS_VP_ENTITY_OFFSET);
initializeParser(DIS_FIELDS_VR_APPLICATION_HEALTH_STATUS);
initializeParser(DIS_FIELDS_VR_APPLICATION_INITIALIZATION);
initializeParser(DIS_FIELDS_VR_DATA_QUERY);
initializeParser(DIS_FIELDS_VR_ELECTROMAGNETIC_EMISSION_SYSTEM_BEAM);
initializeParser(DIS_FIELDS_VR_ELECTROMAGNETIC_EMISSION_SYSTEM);
initializeParser(DIS_FIELDS_MOD_PARAMS_CCTT_SINCGARS);
initializeParser(DIS_FIELDS_MOD_PARAMS_JTIDS_MIDS);
}
static gint alignOffset(gint offset, guint fieldLength)
{
gint remainder = offset % fieldLength;
if (remainder != 0)
{
offset += fieldLength - remainder;
}
return offset;
}
gint parseField_Bytes(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode, guint numBytes)
{
proto_tree_add_text(tree, tvb, offset, numBytes, "%s (%d bytes)",
parserNode.fieldLabel, numBytes);
offset += numBytes;
return offset;
}
gint parseField_Bitmask(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode, guint numBytes)
{
DIS_BitMask *bitMask = 0;
guint64 uintVal = 0;
offset = alignOffset(offset, numBytes);
switch(numBytes)
{
case 1:
uintVal = tvb_get_guint8(tvb, offset);
break;
case 2:
uintVal = tvb_get_ntohs(tvb, offset);
break;
case 4:
uintVal = tvb_get_ntohl(tvb, offset);
break;
case 8:
uintVal = tvb_get_ntoh64(tvb, offset);
break;
default:
break;
}
switch(parserNode.fieldType)
{
case DIS_FIELDTYPE_APPEARANCE:
if ((entityKind == DIS_ENTITYKIND_PLATFORM) &&
(entityDomain == DIS_DOMAIN_LAND))
{
bitMask = DIS_APPEARANCE_LANDPLATFORM;
}
else if (entityKind == DIS_ENTITYKIND_LIFE_FORM)
{
bitMask = DIS_APPEARANCE_LIFEFORM;
}
break;
default:
break;
}
if (bitMask != 0)
{
int maskIndex = 0;
while (bitMask[maskIndex].maskBits != 0)
{
int mapIndex = 0;
DIS_BitMaskMapping *bitMaskMap = bitMask[maskIndex].bitMappings;
while (bitMaskMap[mapIndex].label != 0)
{
if (((bitMask[maskIndex].maskBits & uintVal) >> bitMask[maskIndex].shiftBits) ==
bitMaskMap[mapIndex].value)
{
proto_tree_add_text(tree, tvb, offset, numBytes,
"%s = %s", bitMask[maskIndex].label,
bitMaskMap[mapIndex].label);
break;
}
++mapIndex;
}
++maskIndex;
}
}
else
{
proto_tree_add_text(tree, tvb, offset, numBytes,
"Unknown Appearance Type (%" G_GINT64_MODIFIER "u)", uintVal);
}
offset += numBytes;
return offset;
}
gint parseField_UInt(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode, guint numBytes)
{
guint64 uintVal = 0;
offset = alignOffset(offset, numBytes);
switch(numBytes)
{
case 1:
uintVal = tvb_get_guint8(tvb, offset);
break;
case 2:
uintVal = tvb_get_ntohs(tvb, offset);
break;
case 4:
uintVal = tvb_get_ntohl(tvb, offset);
break;
case 8:
uintVal = tvb_get_ntoh64(tvb, offset);
break;
default:
break;
}
proto_tree_add_text(tree, tvb, offset, numBytes, "%s = %" G_GINT64_MODIFIER "u",
parserNode.fieldLabel, uintVal);
if (parserNode.outputVar != 0)
{
*(parserNode.outputVar) = (guint32)uintVal;
}
offset += numBytes;
return offset;
}
gint parseField_Int(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode, guint numBytes)
{
guint64 uintVal = 0;
offset = alignOffset(offset, numBytes);
switch(numBytes)
{
case 1:
uintVal = tvb_get_guint8(tvb, offset);
break;
case 2:
uintVal = tvb_get_ntohs(tvb, offset);
break;
case 4:
uintVal = tvb_get_ntohl(tvb, offset);
break;
case 8:
uintVal = tvb_get_ntoh64(tvb, offset);
break;
default:
break;
}
proto_tree_add_text(tree, tvb, offset, numBytes, "%s = %" G_GINT64_MODIFIER "d",
parserNode.fieldLabel, uintVal);
offset += numBytes;
return offset;
}
gint parseField_Pad(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode _U_, guint numBytes)
{
proto_tree_add_text(tree, tvb, offset, numBytes,
"Explicit Padding (%d bytes)", numBytes);
offset += numBytes;
return offset;
}
gint parseField_Enum(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode, guint numBytes)
{
const value_string *enumStrings = 0;
guint32 enumVal = 0;
const gchar *enumStr = 0;
#if 0
proto_item *pi;
#endif
int dis_hf_id = -1;
offset = alignOffset(offset, numBytes);
switch(parserNode.fieldType)
{
case DIS_FIELDTYPE_ACKNOWLEDGE_FLAG:
enumStrings = DIS_PDU_AcknowledgeFlag_Strings;
break;
case DIS_FIELDTYPE_ACTION_ID:
enumStrings = DIS_PDU_ActionId_Strings;
break;
case DIS_FIELDTYPE_APPLICATION_GENERAL_STATUS:
enumStrings = DIS_PDU_ApplicationGeneralStatus_Strings;
break;
case DIS_FIELDTYPE_APPLICATION_STATUS_TYPE:
enumStrings = DIS_PDU_ApplicationStatusType_Strings;
break;
case DIS_FIELDTYPE_APPLICATION_TYPE:
enumStrings = DIS_PDU_ApplicationType_Strings;
break;
case DIS_FIELDTYPE_CONTROL_ID:
enumStrings = DIS_PDU_ControlId_Strings;
break;
case DIS_FIELDTYPE_PROTOCOL_VERSION:
enumStrings = DIS_PDU_ProtocolVersion_Strings;
dis_hf_id = hf_dis_proto_ver;
break;
case DIS_FIELDTYPE_PROTOCOL_FAMILY:
enumStrings = DIS_PDU_ProtocolFamily_Strings;
dis_hf_id = hf_dis_proto_fam;
break;
case DIS_FIELDTYPE_PDU_TYPE:
enumStrings = DIS_PDU_Type_Strings;
dis_hf_id = hf_dis_pdu_type;
break;
case DIS_FIELDTYPE_ENTITY_KIND:
enumStrings = DIS_PDU_EntityKind_Strings;
dis_hf_id = hf_dis_entityKind;
break;
case DIS_FIELDTYPE_DOMAIN:
enumStrings = DIS_PDU_Domain_Strings;
dis_hf_id = hf_dis_entityDomain;
break;
case DIS_FIELDTYPE_DETONATION_RESULT:
enumStrings = DIS_PDU_DetonationResult_Strings;
break;
case DIS_FIELDTYPE_FROZEN_BEHAVIOR:
enumStrings = DIS_PDU_FrozenBehavior_Strings;
break;
case DIS_FIELDTYPE_RADIO_CATEGORY:
enumStrings = DIS_PDU_RadioCategory_Strings;
dis_hf_id = hf_dis_category_radio;
break;
case DIS_FIELDTYPE_NOMENCLATURE_VERSION:
enumStrings = DIS_PDU_NomenclatureVersion_Strings;
break;
case DIS_FIELDTYPE_NOMENCLATURE:
enumStrings = DIS_PDU_Nomenclature_Strings;
break;
case DIS_FIELDTYPE_CATEGORY:
if (entityKind == DIS_ENTITYKIND_PLATFORM)
{
switch(entityDomain)
{
case DIS_DOMAIN_LAND:
enumStrings = DIS_PDU_Category_LandPlatform_Strings;
dis_hf_id = hf_dis_category_land;
break;
case DIS_DOMAIN_AIR:
enumStrings = DIS_PDU_Category_AirPlatform_Strings;
dis_hf_id = hf_dis_category_air;
break;
case DIS_DOMAIN_SURFACE:
enumStrings = DIS_PDU_Category_SurfacePlatform_Strings;
dis_hf_id = hf_dis_category_surface;
break;
case DIS_DOMAIN_SUBSURFACE:
enumStrings = DIS_PDU_Category_SubsurfacePlatform_Strings;
dis_hf_id = hf_dis_category_subsurface;
break;
case DIS_DOMAIN_SPACE:
enumStrings = DIS_PDU_Category_SpacePlatform_Strings;
dis_hf_id = hf_dis_category_space;
break;
default:
enumStrings = 0;
break;
}
}
break;
case DIS_FIELDTYPE_EMITTER_NAME:
enumStrings = DIS_PDU_EmitterName_Strings;
dis_hf_id = hf_dis_emitter_name;
break;
case DIS_FIELDTYPE_EMISSION_FUNCTION:
enumStrings = DIS_PDU_EmissionFunction_Strings;
dis_hf_id = hf_dis_emission_function;
break;
case DIS_FIELDTYPE_BEAM_FUNCTION:
enumStrings = DIS_PDU_BeamFunction_Strings;
dis_hf_id = hf_dis_beam_function;
break;
case DIS_FIELDTYPE_PARAMETER_TYPE_DESIGNATOR:
enumStrings = DIS_PDU_ParameterTypeDesignator_Strings;
break;
case DIS_FIELDTYPE_PERSISTENT_OBJECT_TYPE:
enumStrings = DIS_PDU_PersistentObjectType_Strings;
break;
case DIS_FIELDTYPE_PERSISTENT_OBJECT_CLASS:
enumStrings = DIS_PDU_PO_ObjectClass_Strings;
break;
case DIS_FIELDTYPE_REASON:
enumStrings = DIS_PDU_Reason_Strings;
break;
case DIS_FIELDTYPE_REQUEST_STATUS:
enumStrings = DIS_PDU_RequestStatus_Strings;
break;
case DIS_FIELDTYPE_REQUIRED_RELIABILITY_SERVICE:
enumStrings = DIS_PDU_RequiredReliabilityService_Strings;
break;
case DIS_FIELDTYPE_RESPONSE_FLAG:
enumStrings = DIS_PDU_DisResponseFlag_Strings;
break;
case DIS_FIELDTYPE_MODULATION_DETAIL:
switch (majorModulation) {
case DIS_MAJOR_MOD_AMPLITUDE:
enumStrings = DIS_PDU_DetailModulationAmplitude_Strings;
break;
case DIS_MAJOR_MOD_AMPLITUDE_AND_ANGLE:
enumStrings = DIS_PDU_DetailModulationAmpAndAngle_Strings;
break;
case DIS_MAJOR_MOD_ANGLE:
enumStrings = DIS_PDU_DetailModulationAngle_Strings;
break;
case DIS_MAJOR_MOD_COMBINATION:
enumStrings = DIS_PDU_DetailModulationCombination_Strings;
break;
case DIS_MAJOR_MOD_PULSE:
enumStrings = DIS_PDU_DetailModulationPulse_Strings;
break;
case DIS_MAJOR_MOD_UNMODULATED:
enumStrings = DIS_PDU_DetailModulationUnmodulated_Strings;
break;
case DIS_MAJOR_MOD_CPSM:
case DIS_MAJOR_MOD_OTHER:
default:
enumStrings = DIS_PDU_DetailModulationCPSM_Strings;
break;
}
break;
default:
enumStrings = 0;
break;
}
switch(numBytes)
{
case 1:
enumVal = tvb_get_guint8(tvb, offset);
break;
case 2:
enumVal = tvb_get_ntohs(tvb, offset);
break;
case 4:
enumVal = tvb_get_ntohl(tvb, offset);
break;
default:
break;
}
enumStr = val_to_str(enumVal, enumStrings, "Unknown Enumeration (%d)");
if (dis_hf_id != -1) {
#if 0
pi = proto_tree_add_item(tree, dis_hf_id, tvb, offset, numBytes, ENC_BIG_ENDIAN);
proto_item_set_text(pi, "%s = %s", parserNode.fieldLabel, enumStr);
#else
proto_tree_add_item(tree, dis_hf_id, tvb, offset, numBytes, ENC_BIG_ENDIAN);
#endif
}
else {
proto_tree_add_text(tree, tvb, offset, numBytes, "%s = %s",
parserNode.fieldLabel, enumStr);
}
if (parserNode.outputVar != 0)
{
*(parserNode.outputVar) = enumVal;
}
offset += numBytes;
return offset;
}
gint parseField_Float(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode)
{
gfloat floatVal;
offset = alignOffset(offset, 4);
floatVal = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "%s = %f",
parserNode.fieldLabel, floatVal);
offset += 4;
return offset;
}
gint parseField_Float_Text(tvbuff_t *tvb, proto_tree *tree, gint offset, gchar *charStr)
{
gfloat floatVal;
offset = alignOffset(offset, 4);
floatVal = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 4, "%s = %f",
charStr, floatVal);
offset += 4;
return offset;
}
gint parseField_Double(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode)
{
gdouble doubleVal;
offset = alignOffset(offset, 8);
doubleVal = tvb_get_ntohieee_double(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 8, "%s = %f",
parserNode.fieldLabel, doubleVal);
offset += 8;
return offset;
}
gint parseField_Timestamp(tvbuff_t *tvb, proto_tree *tree, gint offset, DIS_ParserNode parserNode)
{
static double MSEC_PER_SECOND = 1000.0;
static double MSEC_PER_MINUTE = 60.0 * 1000.0 ;
static double MSEC_PER_HOUR = 60.0 * 60.0 * 1000.0;
static double FSV = 0x7fffffff;
guint isAbsolute = 0;
guint32 uintVal;
guint minutes;
guint seconds;
guint milliseconds;
double ms;
offset = alignOffset(offset, 4);
uintVal = tvb_get_ntohl(tvb, offset);
if( uintVal & 1 )
isAbsolute = 1;
ms = (uintVal >> 1) * MSEC_PER_HOUR / FSV;
ms += 0.5;
minutes = (guint) (ms / MSEC_PER_MINUTE);
ms -= (minutes * MSEC_PER_MINUTE);
seconds = (guint) (ms / MSEC_PER_SECOND);
ms -= (seconds * MSEC_PER_SECOND);
milliseconds = (guint) ms;
if( isAbsolute )
{
proto_tree_add_text(tree, tvb, offset, 4, "%s = %02d:%02d %03d absolute (UTM)",
parserNode.fieldLabel, minutes, seconds, milliseconds);
}
else
{
proto_tree_add_text(tree, tvb, offset, 4, "%s = %02d:%02d %03d relative",
parserNode.fieldLabel, minutes, seconds, milliseconds);
}
offset += 4;
return offset;
}
gint parseField_VariableParameter(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
DIS_ParserNode *paramParser = 0;
switch (variableParameterType) {
case DIS_PARAM_TYPE_DESIG_ARTICULATED_PART:
paramParser = DIS_FIELDS_VP_ARTICULATED_PART;
break;
case DIS_PARAM_TYPE_DESIG_ATTACHED_PART:
paramParser = DIS_FIELDS_VP_ATTACHED_PART;
break;
case DIS_PARAM_TYPE_DESIG_ENTITY_OFFSET:
paramParser = DIS_FIELDS_VP_ENTITY_OFFSET;
break;
default:
paramParser = DIS_FIELDS_VP_GENERIC;
break;
}
if (paramParser)
{
offset = parseFields(tvb, tree, offset, paramParser);
}
return offset;
}
gint parseField_VariableRecord(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
DIS_ParserNode *paramParser = 0;
switch (variableRecordType) {
case 47200:
paramParser = DIS_FIELDS_VR_APPLICATION_HEALTH_STATUS;
break;
case 47300:
paramParser = DIS_FIELDS_VR_APPLICATION_INITIALIZATION;
break;
case 47600:
paramParser = DIS_FIELDS_VR_DATA_QUERY;
break;
default:
{
guint32 dataLength = variableRecordLength - 6;
if (dataLength > 0)
{
proto_tree_add_text(tree, tvb, offset, dataLength,
"Record Data (%d bytes)", dataLength);
offset += dataLength;
}
}
break;
}
if (paramParser)
{
offset = parseFields(tvb, tree, offset, paramParser);
}
if (variableRecordLength % 8)
{
guint32 alignmentPadding = (8 - (variableRecordLength % 8));
proto_tree_add_text(tree, tvb, offset, alignmentPadding,
"Alignment Padding (%d bytes)", alignmentPadding);
offset += alignmentPadding;
}
return offset;
}
gint parseField_ElectromagneticEmissionSystemBeam(
tvbuff_t *tvb, proto_tree *tree, gint offset)
{
DIS_ParserNode *paramParser = 0;
if (pduType == DIS_PDUTYPE_ELECTROMAGNETIC_EMISSION)
paramParser = DIS_FIELDS_VR_ELECTROMAGNETIC_EMISSION_SYSTEM_BEAM;
if (paramParser)
{
offset = parseFields(tvb, tree, offset, paramParser);
}
return offset;
}
