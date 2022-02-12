static guint16 utilCrcCalculate (const void *ptr, guint16 len, guint16 crc)
{
const guint8 *p = (guint8 *) ptr;
while (len--)
crc = (guint16) ((crc << 8) ^ ccitt_16 [(crc >> 8) ^ *p++]);
return crc;
}
static void dissect_serialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree, int hf_index)
{
proto_item *sn_item = NULL;
proto_tree *sn_tree = NULL;
const gchar *s = NULL;
tvb_ensure_bytes_exist (tvb, start_offset, 16);
sn_item = proto_tree_add_item (tree, hf_index, tvb, start_offset, 16, ENC_ASCII|ENC_NA);
sn_tree = proto_item_add_subtree (sn_item, ett_r3serialnumber);
s = tvb_get_ephemeral_string (tvb, start_offset + 0, 2);
proto_tree_add_text (sn_tree, tvb, start_offset + 0, 2, "Manufacturer .. : %s (%s)", s, str_to_str (s, r3_snmanufacturernames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 2, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 2, 1, "Year .......... : %s (%s)", s, str_to_str (s, r3_snyearnames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 3, 2);
proto_tree_add_text (sn_tree, tvb, start_offset + 3, 2, "Week .......... : %s", s);
s = tvb_get_ephemeral_string (tvb, start_offset + 5, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 5, 1, "Model ......... : %s (%s)", s, str_to_str (s, r3_snmodelnames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 6, 4);
proto_tree_add_text (sn_tree, tvb, start_offset + 6, 4, "Sequence ...... : %s", s);
s = tvb_get_ephemeral_string (tvb, start_offset + 10, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 10, 1, "Group ......... : %s (%s)", s, str_to_str (s, r3_sngroupnames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 11, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 11, 1, "NID ........... : %s (%s)", s, str_to_str (s, r3_snnidnames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 12, 2);
proto_tree_add_text (sn_tree, tvb, start_offset + 12, 2, "HID ........... : %s (%s)", s, str_to_str (s, r3_snhidnames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 14, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 14, 1, "Power Supply .. : %s (%s)", s, str_to_str (s, r3_snpowersupplynames, "[Unknown]"));
s = tvb_get_ephemeral_string (tvb, start_offset + 15, 1);
proto_tree_add_text (sn_tree, tvb, start_offset + 15, 1, "Mortise ....... : %s (%s)", s, str_to_str (s, r3_snmortisenames, "[Unknown]"));
}
static void dissect_r3_upstreamfields (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length, packet_info *pinfo, proto_tree *tree)
{
guint32 offset = 0;
while (offset < tvb_reported_length (tvb))
{
guint32 fieldLength = tvb_get_guint8 (tvb, offset + 0);
guint32 fieldType = tvb_get_guint8 (tvb, offset + 1);
guint32 dataLength = fieldLength - 2;
proto_item *upstreamfield_item = NULL;
proto_item *upstreamfield_length = NULL;
proto_tree *upstreamfield_tree = NULL;
const gchar *usfn = NULL;
usfn = val_to_str_ext_const (fieldType, &r3_upstreamfieldnames_ext, "[Unknown Field]");
upstreamfield_item = proto_tree_add_none_format (tree, hf_r3_upstreamfield, tvb, offset + 0, fieldLength, "Upstream Field: %s (%u)", usfn, fieldType);
upstreamfield_tree = proto_item_add_subtree (upstreamfield_item, ett_r3upstreamfield);
upstreamfield_length = proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldlength, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldtype, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
if (fieldLength < 2)
{
dataLength = 0;
expert_add_info_format (pinfo, upstreamfield_length, PI_UNDECODED, PI_WARN, "Malformed length value -- all fields are at least 2 octets.");
}
offset += 2;
switch (fieldType)
{
case UPSTREAMFIELD_NOTUSED :
case UPSTREAMFIELD_PRIMARYPIN :
case UPSTREAMFIELD_AUXPIN :
case UPSTREAMFIELD_ACCESSALWAYS :
case UPSTREAMFIELD_CACHED :
case UPSTREAMFIELD_ENTRYDEVICE :
case UPSTREAMFIELD_PPMIFIELDTYPE :
case UPSTREAMFIELD_RESPONSEWINDOW :
case UPSTREAMFIELD_USERTYPE :
case UPSTREAMFIELD_PRIMARYFIELDTYPE :
case UPSTREAMFIELD_AUXFIELDTYPE :
case UPSTREAMFIELD_ACCESSMODE :
case UPSTREAMFIELD_USECOUNT :
case UPSTREAMFIELD_EXCEPTIONGROUP :
case UPSTREAMFIELD_NAR :
case UPSTREAMFIELD_SEQUENCENUMBER :
case UPSTREAMFIELD_USERNUMBER :
case UPSTREAMFIELD_EVENTLOGRECORDCOUNT :
case UPSTREAMFIELD_DECLINEDRECORDCOUNT :
case UPSTREAMFIELD_ALARMRECORDCOUNT :
proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldarray [fieldType], tvb, offset, dataLength, ENC_LITTLE_ENDIAN);
break;
case UPSTREAMFIELD_PIN :
case UPSTREAMFIELD_VERSION :
case UPSTREAMFIELD_AUXCTLRVERSION :
proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldarray [fieldType], tvb, offset, dataLength, ENC_ASCII|ENC_NA);
break;
case UPSTREAMFIELD_SERIALNUMBER :
{
tvbuff_t *sn_tvb = tvb_new_subset (tvb, offset, dataLength, dataLength);
dissect_serialnumber (sn_tvb, 0, length, pinfo, upstreamfield_tree, hf_r3_upstreamfieldarray [fieldType]);
}
break;
case UPSTREAMFIELD_EVENTLOGRECORD :
{
proto_item *eventlog_item = NULL;
proto_tree *eventlog_tree = NULL;
if (dataLength != 9)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed event log field -- expected 9 octets");
else
{
eventlog_item = proto_tree_add_text (upstreamfield_tree, tvb, offset, 9, "Event Log Record");
eventlog_tree = proto_item_add_subtree (eventlog_item, ett_r3eventlogrecord);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_year, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_month, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_day, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_hour, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_minute, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_second, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_usernumber, tvb, offset + 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_event, tvb, offset + 8, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case UPSTREAMFIELD_DATETIME :
{
proto_item *datetime_item = NULL;
proto_tree *datetime_tree = NULL;
if (dataLength != 8)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed date/time field -- expected 8 octets");
else
{
datetime_item = proto_tree_add_text (upstreamfield_tree, tvb, offset, 8, "Date/Time: %02u/%02u/%02u-%u %02u:%02u:%02u %u",
tvb_get_guint8 (tvb, offset + 0), tvb_get_guint8 (tvb, offset + 1), tvb_get_guint8 (tvb, offset + 2), tvb_get_guint8 (tvb, offset + 3),
tvb_get_guint8 (tvb, offset + 4), tvb_get_guint8 (tvb, offset + 5), tvb_get_guint8 (tvb, offset + 6), tvb_get_guint8 (tvb, offset + 7));
datetime_tree = proto_item_add_subtree (datetime_item, ett_r3datetime);
proto_tree_add_item (datetime_tree, hf_r3_datetime_year, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_month, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_day, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_dow, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_hours, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_minutes, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_seconds, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (datetime_tree, hf_r3_datetime_dst, tvb, offset + 7, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case UPSTREAMFIELD_DECLINEDRECORD :
{
proto_item *declinedlog_item = NULL;
proto_tree *declinedlog_tree = NULL;
guint8 cred1type = 0;
guint8 cred2type = 0;
if (dataLength != 49)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed declined log field -- expected 49 octets");
else
{
declinedlog_item = proto_tree_add_text (upstreamfield_tree, tvb, offset, 49, "Declined Log Record");
declinedlog_tree = proto_item_add_subtree (declinedlog_item, ett_r3declinedlogrecord);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_year, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_month, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_day, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_hour, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_minute, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_second, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_usernumber, tvb, offset + 6, 2, ENC_LITTLE_ENDIAN);
cred1type = tvb_get_guint8 (tvb, offset + 8) & 0x07;
cred2type = (tvb_get_guint8 (tvb, offset + 8) & 0x38) >> 3;
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred1type, tvb, offset, 1, cred1type);
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred2type, tvb, offset, 1, cred2type);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred1, tvb, offset + 9, 19, ENC_NA);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred2, tvb, offset + 28, 19, ENC_NA);
}
}
break;
case UPSTREAMFIELD_EXPIREON :
{
proto_item *expireon_item = NULL;
proto_tree *expireon_tree = NULL;
if (dataLength != 3)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed expiration field -- expected 3 octets");
else
{
expireon_item = proto_tree_add_text (upstreamfield_tree, tvb, offset, 3, "Expire YY/MM/DD: %02u/%02u/%02u",
tvb_get_guint8 (tvb, offset + 2), tvb_get_guint8 (tvb, offset + 0), tvb_get_guint8 (tvb, offset + 1));
expireon_tree = proto_item_add_subtree (expireon_item, ett_r3expireon);
proto_tree_add_item (expireon_tree, hf_r3_expireon_month, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_day, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_year, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case UPSTREAMFIELD_TIMEZONE :
{
guint32 i;
guint32 tz;
proto_item *timezone_item = NULL;
proto_tree *timezone_tree = NULL;
if (dataLength != 4)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed timezone field -- expected 4 octets");
else
{
tz = tvb_get_letohl (tvb, offset);
timezone_item = proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldarray [fieldType], tvb, offset, 4, ENC_LITTLE_ENDIAN);
timezone_tree = proto_item_add_subtree (timezone_item, ett_r3timezone);
for (i = 0; i < 32; i++)
proto_tree_add_boolean (timezone_tree, hf_r3_timezonearray [i], tvb, offset, 4, tz);
}
}
break;
case UPSTREAMFIELD_ALARMRECORD :
{
proto_item *alarmlog_item = NULL;
proto_tree *alarmlog_tree = NULL;
alarmlog_item = proto_tree_add_text (upstreamfield_tree, tvb, offset, 9, "Alarm Record");
alarmlog_tree = proto_item_add_subtree (alarmlog_item, ett_r3alarmlogrecord);
if (dataLength != 9)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed alarm log field -- expected 9 octets");
else
{
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_year, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_month, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_day, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_hour, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_minute, tvb, offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_second, tvb, offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_id, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_usernumber, tvb, offset + 7, 2, ENC_LITTLE_ENDIAN);
}
}
break;
default :
proto_tree_add_none_format (upstreamfield_tree, hf_r3_upstreamfielderror, tvb, offset, dataLength, "Unknown Field Type");
break;
}
offset += dataLength;
}
}
static void dissect_r3_upstreamcommand_reserved (tvbuff_t *tvb _U_, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
DISSECTOR_ASSERT (0);
}
static void dissect_r3_upstreamcommand_debugmsg (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *debugmsg_item = NULL;
proto_tree *debugmsg_tree = NULL;
debugmsg_item = proto_tree_add_text (tree, tvb, start_offset, -1, "Debug message");
debugmsg_tree = proto_item_add_subtree (debugmsg_item, ett_r3debugmsg);
proto_tree_add_item (debugmsg_tree, hf_r3_debugmsg, tvb, start_offset + 1, -1, ENC_ASCII|ENC_NA);
}
static void dissect_r3_upstreamcommand_queryversion (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_querydatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_queryserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dumpeventlog (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
proto_item *eventlog_item = NULL;
proto_tree *eventlog_tree = NULL;
const gchar *en = NULL;
tvb_ensure_bytes_exist (tvb, start_offset, 11);
if (length != 11)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Malformed event log record -- expected 10 octets");
else
{
en = val_to_str_ext_const (tvb_get_guint8 (tvb, start_offset + 10), &r3_eventnames_ext, "[Unknown Event]");
eventlog_item = proto_tree_add_text (tree, tvb, start_offset, 10, "Event Log Record %u (%s)", tvb_get_letohs (tvb, start_offset + 0), en);
eventlog_tree = proto_item_add_subtree (eventlog_item, ett_r3eventlogrecord);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_recordnumber, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_year, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_month, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_day, tvb, start_offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_hour, tvb, start_offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_minute, tvb, start_offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_second, tvb, start_offset + 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_usernumber, tvb, start_offset + 8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_event, tvb, start_offset + 10, 1, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreamcommand_dumpnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
tvb_ensure_bytes_exist (tvb, start_offset, 3);
proto_tree_add_item (tree, hf_r3_nvramdump_record, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdump_length, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdump_data, tvb, start_offset + 3, tvb_get_guint8 (tvb, start_offset + 2), ENC_NA);
}
static void dissect_r3_upstreamcommand_rmtquthrequest (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_retrieveuser (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_queryconfig (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 offset = 0;
while (offset < tvb_reported_length (tvb))
{
proto_item *upstreamfield_item = NULL;
proto_tree *upstreamfield_tree = NULL;
const gchar *ci = NULL;
ci = val_to_str_ext_const (tvb_get_guint8 (tvb, offset + 1), &r3_configitemnames_ext, "[Unknown Configuration Item]");
upstreamfield_item = proto_tree_add_text (tree, tvb, offset + 0, tvb_get_guint8 (tvb, offset + 0), "Config Field: %s (%u)", ci, tvb_get_guint8 (tvb, offset + 1));
upstreamfield_tree = proto_item_add_subtree (upstreamfield_item, ett_r3upstreamfield);
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemlength, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (upstreamfield_tree, hf_r3_configitem, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemtype, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, offset + 2))
{
case CONFIGTYPE_NONE :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata, tvb, offset + 3, tvb_get_guint8 (tvb, offset + 0) - 3, ENC_NA);
break;
case CONFIGTYPE_BOOL :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_bool, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_8 :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_8, tvb, offset + 3, 1, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_16 :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_16, tvb, offset + 3, 2, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_32 :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_32, tvb, offset + 3, 4, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_STRING :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_string, tvb, offset + 3, tvb_get_guint8 (tvb, offset + 0) - 3, ENC_ASCII|ENC_NA);
break;
default :
proto_tree_add_none_format (upstreamfield_tree, hf_r3_upstreamfielderror, tvb, offset + 3, tvb_get_guint8 (tvb, offset + 0) - 3, "Unknown Field Type");
break;
}
offset += tvb_get_guint8 (tvb, offset + 0);
}
}
static void dissect_r3_upstreamcommand_rmteventlogrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dpac (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_dpacreply_stuff, tvb, start_offset + 2, 1, ENC_NA);
proto_tree_add_item (tree, hf_r3_dpacreply_length, tvb, start_offset + 3, 1, ENC_NA);
proto_tree_add_item (tree, hf_r3_dpacreply_reply, tvb, start_offset + 4, -1, ENC_NA);
}
static void dissect_r3_upstreamcommand_notify (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_mfg (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length, packet_info *pinfo, proto_tree *tree)
{
proto_item *mfg_item = NULL;
proto_tree *mfg_tree = NULL;
tvbuff_t *mfg_tvb = NULL;
const gchar *cn;
mfg_tvb = tvb_new_subset (tvb, 2, tvb_reported_length (tvb) - 2, tvb_reported_length (tvb) - 2);
cn = val_to_str_ext_const (tvb_get_guint8 (tvb, 1), &r3_mfgfieldnames_ext, "[Unknown Mfg Field]");
proto_tree_add_item (tree, hf_r3_mfgfield_length, tvb, 0, 1, ENC_LITTLE_ENDIAN);
mfg_item = proto_tree_add_text (tree, tvb, 1, -1, "Upstream Manufacturing Field: %s (%u)", cn, tvb_get_guint8 (tvb, 1));
mfg_tree = proto_item_add_subtree (mfg_item, ett_r3commandmfg);
proto_tree_add_item (mfg_tree, hf_r3_mfgfield, tvb, 1, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_guint8 (tvb, 1) >= MFGFIELD_LAST)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Unknown manufacturing command value");
else if (r3upstreammfgfield_dissect [tvb_get_guint8 (tvb, 1)].dissector)
(*r3upstreammfgfield_dissect [tvb_get_guint8 (tvb, 1)].dissector) (mfg_tvb, 0, length, pinfo, mfg_tree);
}
static void dissect_r3_upstreamcommand_eventlogwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dumpnvramrle (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_nvramdumprle_record, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdumprle_length, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdumprle_data, tvb, start_offset + 4, tvb_get_guint8 (tvb, start_offset + 3), ENC_NA);
}
static void dissect_r3_upstreamcommand_rmtdeclinedrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_declinedwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dumpdeclinedlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *declinedlog_item = NULL;
proto_tree *declinedlog_tree = NULL;
guint8 cred1type = 0;
guint8 cred2type = 0;
declinedlog_item = proto_tree_add_text (tree, tvb, start_offset, 49, "Declined Log Record %u", tvb_get_letohs (tvb, start_offset + 0));
declinedlog_tree = proto_item_add_subtree (declinedlog_item, ett_r3declinedlogrecord);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_recordnumber, tvb, start_offset, 2, ENC_LITTLE_ENDIAN); start_offset += 2;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_year, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_month, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_day, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_hour, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_minute, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_second, tvb, start_offset, 1, ENC_LITTLE_ENDIAN); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_usernumber, tvb, start_offset, 2, ENC_LITTLE_ENDIAN); start_offset += 2;
cred1type = tvb_get_guint8 (tvb, start_offset) & 0x07;
cred2type = (tvb_get_guint8 (tvb, start_offset) & 0x38) >> 3;
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred1type, tvb, start_offset, 1, cred1type); start_offset += 0;
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred2type, tvb, start_offset, 1, cred2type); start_offset += 1;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred1, tvb, start_offset, 19, ENC_NA); start_offset += 19;
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred2, tvb, start_offset, 19, ENC_NA);
}
static void dissect_r3_upstreamcommand_rmtalarmrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_alarmwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dumpalarmlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *alarmlog_item = proto_tree_add_text (tree, tvb, start_offset, 9, "Alarm Log Record %u", tvb_get_letohs (tvb, start_offset + 0));
proto_tree *alarmlog_tree = proto_item_add_subtree (alarmlog_item, ett_r3alarmlogrecord);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_recordnumber, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_year, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_month, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_day, tvb, start_offset + 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_hour, tvb, start_offset + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_minute, tvb, start_offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_second, tvb, start_offset + 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_id, tvb, start_offset + 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_usernumber, tvb, start_offset + 9, 2, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_upstreamcommand_connectscheduler (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_connectcommuser (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_commandalarm (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void dissect_r3_upstreamcommand_dumpdebuglog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *debuglog_item = proto_tree_add_text (tree, tvb, start_offset, 8, "Debug Log Record %u", tvb_get_letohs (tvb, start_offset + 0));
proto_tree *debuglog_tree = proto_item_add_subtree (debuglog_item, ett_r3debuglogrecord);
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_recordnumber, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_flags, tvb, start_offset + 2, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_tick, tvb, start_offset + 6, 2, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_upstreammfgfield_iopins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint32 i;
guint32 l = tvb_length_remaining (tvb, start_offset);
char portname = 'A';
if (l % 3 != 0)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "IOPINS data length not modulo 3 == 0");
else
{
for (i = 0; i < l; i += 3, portname++)
{
proto_item *port_item = proto_tree_add_text (tree, tvb, start_offset + i, 3, "Port %c Configuration", (portname == 'I') ? ++portname : portname);
proto_tree *port_tree = proto_item_add_subtree (port_item, ett_r3iopins);
proto_tree_add_item (port_tree, hf_r3_iopins_lat, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (port_tree, hf_r3_iopins_port, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (port_tree, hf_r3_iopins_tris, tvb, start_offset + i + 2, 1, ENC_LITTLE_ENDIAN);
}
}
}
static void dissect_r3_upstreammfgfield_adcs (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 i;
for (i = 0; i < tvb_reported_length (tvb); i++)
{
proto_item *item = proto_tree_add_item (tree, hf_r3_adc [i], tvb, start_offset + i, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text (item, " (%.2f Volts)", (float) tvb_get_guint8 (tvb, start_offset + i) * 0.04154);
}
}
static void dissect_r3_upstreammfgfield_hardwareid (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_hardwareid_board, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_hardwareid_cpuid, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_hardwareid_cpurev, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_upstreammfgfield_checkpointlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *cpl_item = NULL;
proto_tree *cpl_tree = NULL;
guint counter = 0;
guint l = tvb_length_remaining (tvb, start_offset + 1);
guint i;
proto_tree_add_item (tree, hf_r3_checkpointlog_entryptr, tvb, start_offset, 1, ENC_LITTLE_ENDIAN);
cpl_item = proto_tree_add_text (tree, tvb, start_offset + 1, -1, "Checkpoint Log");
cpl_tree = proto_item_add_subtree (cpl_item, ett_r3checkpointlog);
for (start_offset++, i = 0; i < l; i += 2, counter++)
{
guint rcon = tvb_get_guint8 (tvb, start_offset + i + 0);
guint cp = tvb_get_guint8 (tvb, start_offset + i + 1);
guint resettype = 0;
proto_item *cpe_item = proto_tree_add_text (cpl_tree, tvb, start_offset + i + 0, 2, "Checkpoint Log Entry %u", counter);
proto_tree *cpe_tree = proto_item_add_subtree (cpe_item, ett_r3checkpointlogentry);
const gchar *resets [] = { "Stack underflow", "Stack overflow", "Power-On", "Software", "Brown-out", "MCLR in sleep", "WDT", "Normal", "[Unknown Reset Type]" };
const gchar *desc;
desc = val_to_str_ext_const (cp, &r3_checkpointnames_ext, "[Unknown Checkpoint]");
if (rcon == 0xff)
resettype = 8;
else
{
rcon &= 0x1f;
if (rcon == 0x1c)
resettype = 2;
else if ((rcon & 0x10) == 0x00)
resettype = 3;
else if ((rcon & 0x1d) == 0x1c)
resettype = 4;
else if ((rcon & 0x0c) == 0x08)
resettype = 5;
else if ((rcon & 0x0c) == 0x04)
resettype = 6;
else
resettype = 7;
}
proto_item_append_text (cpe_item, " (%s, %s)", resets [resettype], desc);
proto_item_append_text (proto_tree_add_item (cpe_tree, hf_r3_checkpointlog_rcon, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN), " (%s)", resets [resettype]);
proto_item_append_text (proto_tree_add_item (cpe_tree, hf_r3_checkpointlog_checkpoint, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN), " (%s)", desc);
}
}
static void dissect_r3_upstreammfgfield_cpuregisters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *tmp_tree [19];
proto_item *cr_item = proto_tree_add_text (tree, tvb, start_offset, -1, "CPU Registers");
proto_tree *cr_tree = proto_item_add_subtree (cr_item, ett_r3cpuregisters);
tmp_tree [ 0] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 1] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon2, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 2] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon3, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 3] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir1, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 4] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir2, tvb, start_offset + 4, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 5] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir3, tvb, start_offset + 5, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 6] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie1, tvb, start_offset + 6, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 7] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie2, tvb, start_offset + 7, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 8] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie3, tvb, start_offset + 8, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 9] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr1, tvb, start_offset + 9, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [10] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr2, tvb, start_offset + 10, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [11] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr3, tvb, start_offset + 11, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [12] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcon, tvb, start_offset + 12, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [13] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_osccon, tvb, start_offset + 13, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [14] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcsta, tvb, start_offset + 14, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [15] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_txsta, tvb, start_offset + 15, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [16] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcsta2, tvb, start_offset + 16, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [17] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_txsta2, tvb, start_offset + 17, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [18] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_wdtcon, tvb, start_offset + 18, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_rbif, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_int0if, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_tmr0if, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_rbie, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_int0ie, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_tmr0ie, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_giel, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 0], hf_r3_cpuregisters_intcon_gieh, tvb, start_offset + 0, 1, tvb_get_guint8 (tvb, start_offset + 0));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_rbip, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_int3ip, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_tmr0ip, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg3, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg2, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg1, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg0, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_rbpu, tvb, start_offset + 1, 1, tvb_get_guint8 (tvb, start_offset + 1));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1if, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2if, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int3if, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1ie, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2ie, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int3ie, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1ip, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2ip, tvb, start_offset + 2, 1, tvb_get_guint8 (tvb, start_offset + 2));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tmr1if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tmr2if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_ccp1if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_ssp1if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tx1if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_rc1if, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_adif, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 3], hf_r3_cpuregisters_pir1_pspif, tvb, start_offset + 3, 1, tvb_get_guint8 (tvb, start_offset + 3));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_ccp2if, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_tmr3if, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_hlvdif, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_bcl1if, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_eeif, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_unused5, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_cmif, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 4], hf_r3_cpuregisters_pir2_oscfif, tvb, start_offset + 4, 1, tvb_get_guint8 (tvb, start_offset + 4));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp3if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp4if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp5if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_tmr4if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_tx2if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_rc2if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_bcl2if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ssp2if, tvb, start_offset + 5, 1, tvb_get_guint8 (tvb, start_offset + 5));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tmr1ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tmr2ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_ccp1ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_ssp1ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tx1ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_rc1ie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_adie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 6], hf_r3_cpuregisters_pie1_pspie, tvb, start_offset + 6, 1, tvb_get_guint8 (tvb, start_offset + 6));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_oscfie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_cmie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_unused2, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_eeie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_bcl1ie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_hlvdie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_tmr3ie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 7], hf_r3_cpuregisters_pie2_ccp2ie, tvb, start_offset + 7, 1, tvb_get_guint8 (tvb, start_offset + 7));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp3ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp4ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp5ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_tmr4ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_tx2ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_rc2ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_bcl2ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ssp2ie, tvb, start_offset + 8, 1, tvb_get_guint8 (tvb, start_offset + 8));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tmr1ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tmr2ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_ccp1ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_ssp1ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tx1ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_rc1ip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_adip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_pspip, tvb, start_offset + 9, 1, tvb_get_guint8 (tvb, start_offset + 9));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_ccp2ip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_tmr3ip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_hlvdip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_bcl1ip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_eeip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_unused5, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_cmip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [10], hf_r3_cpuregisters_ipr2_oscfip, tvb, start_offset + 10, 1, tvb_get_guint8 (tvb, start_offset + 10));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp2ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp4ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp5ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_tmr4ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_tx2ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_rc2ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_bcl2ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [11], hf_r3_cpuregisters_ipr3_ssp2ip, tvb, start_offset + 11, 1, tvb_get_guint8 (tvb, start_offset + 11));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_bor, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_por, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_pd, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_to, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_unused4, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_ri, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_sboren, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [12], hf_r3_cpuregisters_rcon_ipen, tvb, start_offset + 12, 1, tvb_get_guint8 (tvb, start_offset + 12));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_scs0, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_scs1, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_iofs, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_osts, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf0, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf1, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf2, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [13], hf_r3_cpuregisters_osccon_idlen, tvb, start_offset + 13, 1, tvb_get_guint8 (tvb, start_offset + 13));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_rx9d, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_oerr, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_ferr, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_adden, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_cren, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_sren, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_rx9, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [14], hf_r3_cpuregisters_rcsta_spen, tvb, start_offset + 14, 1, tvb_get_guint8 (tvb, start_offset + 14));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_tx9d, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_trmt, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_brgh, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_sendb, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_sync, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_txen, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_tx9, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [15], hf_r3_cpuregisters_txsta_csrc, tvb, start_offset + 15, 1, tvb_get_guint8 (tvb, start_offset + 15));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_rx9d, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_oerr, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_ferr, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_adden, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_cren, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_sren, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_rx9, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [16], hf_r3_cpuregisters_rcsta2_spen, tvb, start_offset + 16, 1, tvb_get_guint8 (tvb, start_offset + 16));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_tx9d, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_trmt, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_brgh, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_sendb, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_sync, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_txen, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_tx9, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [17], hf_r3_cpuregisters_txsta2_csrc, tvb, start_offset + 17, 1, tvb_get_guint8 (tvb, start_offset + 17));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_swdten, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused1, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused2, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused3, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused4, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused5, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused6, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
proto_tree_add_boolean (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused7, tvb, start_offset + 18, 1, tvb_get_guint8 (tvb, start_offset + 18));
}
static void dissect_r3_upstreammfgfield_taskflags (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint l = tvb_length_remaining (tvb, start_offset);
guint i;
proto_item *tfg_item = proto_tree_add_text (tree, tvb, start_offset, -1, "Task Flags (%u tasks)", l / 5);
proto_tree *tfg_tree = proto_item_add_subtree (tfg_item, ett_r3taskflags);
for (i = 0; i < l; i += 5)
{
proto_item *tf_item = proto_tree_add_text (tfg_tree, tvb, start_offset + i, 5, "Task Flags (%2d: 0x%06x)", tvb_get_guint8 (tvb, start_offset + i + 0), tvb_get_letohl (tvb, start_offset + i + 1));
proto_tree *tf_tree = proto_item_add_subtree (tf_item, ett_r3taskflagsentry);
proto_tree_add_item (tf_tree, hf_r3_taskflags_taskid, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tf_tree, hf_r3_taskflags_flags, tvb, start_offset + i + 1, 4, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreammfgfield_timerchain (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint l = tvb_length_remaining (tvb, start_offset + 3);
guint i;
proto_tree_add_item (tree, hf_r3_timerchain_newtick, tvb, start_offset + 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_timerchain_currentboundary, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
for (start_offset += 3, i = 0; i < l; i += 12)
{
proto_item *tc_item = proto_tree_add_text (tree, tvb, start_offset + i, 12, "Timer Chain Entry");
proto_tree *tc_tree = proto_item_add_subtree (tc_item, ett_r3timerchain);
proto_tree_add_item (tc_tree, hf_r3_timerchain_tasktag, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_address, tvb, start_offset + i + 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_reload, tvb, start_offset + i + 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_boundary, tvb, start_offset + i + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_count, tvb, start_offset + i + 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_flags, tvb, start_offset + i + 8, 4, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreammfgfield_peekpoke (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint i;
guint l = tvb_length_remaining (tvb, start_offset);
for (i = 0; i < l; i += 3)
{
proto_item *peekpoke_item = proto_tree_add_text (tree, tvb, start_offset + i, 3, "%s", "");
proto_tree *peekpoke_tree = proto_item_add_subtree (peekpoke_item, ett_r3peekpoke);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_operation, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_address, tvb, start_offset + i + 1, 2, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, start_offset + i + 0))
{
case PEEKPOKE_READU8 :
proto_item_append_text (peekpoke_item, "Read (8 Bits @ 0x%04x = 0x%02x)", tvb_get_letohs (tvb, start_offset + i + 1), tvb_get_guint8 (tvb, start_offset + i + 3));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke8, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
i += 1;
break;
case PEEKPOKE_READU16 :
proto_item_append_text (peekpoke_item, "Read (16 Bits @ 0x%04x = 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 1), tvb_get_letohs (tvb, start_offset + i + 3));
proto_item_set_len (peekpoke_item, 5);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke16, tvb, start_offset + i + 3, 2, ENC_LITTLE_ENDIAN);
i += 2;
break;
case PEEKPOKE_READU24 :
proto_item_append_text (peekpoke_item, "Read (24 Bits @ 0x%04x = 0x%06x)", tvb_get_letohs (tvb, start_offset + i + 1), tvb_get_letoh24 (tvb, start_offset + i + 3));
proto_item_set_len (peekpoke_item, 6);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke24, tvb, start_offset + i + 3, 3, ENC_LITTLE_ENDIAN);
i += 3;
break;
case PEEKPOKE_READU32 :
proto_item_append_text (peekpoke_item, "Read (32 Bits @ 0x%04x = 0x%08x)", tvb_get_letohs (tvb, start_offset + i + 1), tvb_get_letohl (tvb, start_offset + i + 3));
proto_item_set_len (peekpoke_item, 7);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke32, tvb, start_offset + i + 3, 4, ENC_LITTLE_ENDIAN);
i += 4;
break;
case PEEKPOKE_READSTRING :
proto_item_append_text (peekpoke_item, "Read (%u Bytes @ 0x%04x)", tvb_get_guint8 (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 3 + 1 + tvb_get_guint8 (tvb, start_offset + i + 3));
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_pokestring, tvb, start_offset + i + 4, tvb_get_guint8 (tvb, start_offset + i + 3), ENC_NA);
i += tvb_get_guint8 (tvb, start_offset + i + 3) + 1;
break;
default :
DISSECTOR_ASSERT (0);
}
}
}
static void dissect_r3_upstreammfgfield_lockstate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ls_item = proto_tree_add_text (tree, tvb, start_offset, tvb_length_remaining (tvb, start_offset), "Lock State (0x%06x)", tvb_get_letoh24 (tvb, start_offset));
proto_tree *ls_tree = proto_item_add_subtree (ls_item, ett_r3lockstate);
guint ls = tvb_get_letoh24 (tvb, start_offset);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_passage, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_panic, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_lockout, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_relock, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autoopen, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nextauto, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_lockstate, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_wantstate, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_remote, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_update, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_exceptionspresent, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_exceptionsactive, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_timezonespresent, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_timezonesactive, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autounlockspresent, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autounlocksactive, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmspresent, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmsactive, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmrelockspresent, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmreslocksactive, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nvramprotect, tvb, start_offset, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nvramchecksum, tvb, start_offset, 3, ls);
}
static void dissect_r3_upstreammfgfield_capabilities (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *cf_item = NULL;
proto_tree *cf_tree= NULL;
guint l = tvb_length_remaining (tvb, start_offset);
guint items = 0;
guint octets;
guint i;
i = start_offset;
while (i < l)
{
items++;
octets = tvb_get_guint8 (tvb, start_offset + i);
if(!octets)
{
cf_item = proto_tree_add_text (tree, tvb, start_offset, l, "Capabilities (unknown items)");
expert_add_info_format(pinfo, cf_item, PI_MALFORMED, PI_WARN, "Capabilities could not be decoded because length of 0 encountered");
return;
}
i += octets;
}
cf_item = proto_tree_add_text (tree, tvb, start_offset, l, "Capabilities (%u items)", items);
cf_tree = proto_item_add_subtree (cf_item, ett_r3capabilities);
for (i = start_offset; i < l; i += tvb_get_guint8 (tvb, start_offset + i))
{
proto_item *tmp_item = proto_tree_add_item (cf_tree, hf_r3_capabilities, tvb, start_offset + i, tvb_get_guint8 (tvb, start_offset + i), ENC_NA);
proto_tree *tmp_tree = proto_item_add_subtree (tmp_item, ett_r3capabilities);
const gchar *fn;
fn = val_to_str_ext_const (tvb_get_guint8 (tvb, start_offset + i + 1), &r3_capabilitiesnames_ext, "[Unknown Field Name]");
proto_item_append_text (tmp_item, " (%s, %u)", fn, tvb_get_letohs (tvb, start_offset + i + 2));
proto_tree_add_item (tmp_tree, hf_r3_capabilities_length, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree, hf_r3_capabilities_type, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree, hf_r3_capabilities_value, tvb, start_offset + i + 2, 2, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreammfgfield_dumpm41t81 (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
proto_item *rtc_item = proto_tree_add_text (tree, tvb, start_offset, -1, "M41T81 RTC Registers");
proto_tree *rtc_tree = proto_item_add_subtree (rtc_item, ett_r3m41t81registers);
proto_tree *tmp_tree [20];
guint offset_in_bits = start_offset * 8;
if (tvb_length_remaining (tvb, start_offset) != 20)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Length of M41T81 RTC register dump not 20 octets");
else
{
tmp_tree [ 0] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg00, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 1] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg01, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 2] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg02, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 3] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg03, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 4] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg04, tvb, start_offset + 4, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 5] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg05, tvb, start_offset + 5, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 6] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg06, tvb, start_offset + 6, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 7] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg07, tvb, start_offset + 7, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 8] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg08, tvb, start_offset + 8, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 9] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg09, tvb, start_offset + 9, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [10] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0a, tvb, start_offset + 10, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [11] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0b, tvb, start_offset + 11, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [12] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0c, tvb, start_offset + 12, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [13] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0d, tvb, start_offset + 13, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [14] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0e, tvb, start_offset + 14, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [15] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0f, tvb, start_offset + 15, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [16] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg10, tvb, start_offset + 16, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [17] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg11, tvb, start_offset + 17, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [18] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg12, tvb, start_offset + 18, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [19] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg13, tvb, start_offset + 19, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
proto_tree_add_bits_item (tmp_tree [ 0], hf_r3_dumpm41t81_reg00_sec1, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 0], hf_r3_dumpm41t81_reg00_sec01, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 1], hf_r3_dumpm41t81_reg01_st, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 1], hf_r3_dumpm41t81_reg01_10sec, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [ 1], hf_r3_dumpm41t81_reg01_1sec, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 2], hf_r3_dumpm41t81_reg02_notused, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 2], hf_r3_dumpm41t81_reg02_10min, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [ 2], hf_r3_dumpm41t81_reg02_1min, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 3], hf_r3_dumpm41t81_reg03_cbe, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 3], hf_r3_dumpm41t81_reg03_cb, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 3], hf_r3_dumpm41t81_reg03_10hour, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [ 3], hf_r3_dumpm41t81_reg03_1hour, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 4], hf_r3_dumpm41t81_reg04_notused, tvb, offset_in_bits, 5, ENC_LITTLE_ENDIAN); offset_in_bits += 5;
proto_tree_add_bits_item (tmp_tree [ 4], hf_r3_dumpm41t81_reg04_dow, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [ 5], hf_r3_dumpm41t81_reg05_notused, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [ 5], hf_r3_dumpm41t81_reg05_10day, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [ 5], hf_r3_dumpm41t81_reg05_1day, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 6], hf_r3_dumpm41t81_reg06_notused, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [ 6], hf_r3_dumpm41t81_reg06_10month, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 6], hf_r3_dumpm41t81_reg06_1month, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 7], hf_r3_dumpm41t81_reg07_10year, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 7], hf_r3_dumpm41t81_reg07_1year, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [ 8], hf_r3_dumpm41t81_reg08_out, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 8], hf_r3_dumpm41t81_reg08_ft, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 8], hf_r3_dumpm41t81_reg08_s, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 8], hf_r3_dumpm41t81_reg08_cal, tvb, offset_in_bits, 5, ENC_LITTLE_ENDIAN); offset_in_bits += 5;
proto_tree_add_bits_item (tmp_tree [ 9], hf_r3_dumpm41t81_reg09_notused, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [ 9], hf_r3_dumpm41t81_reg09_bmb, tvb, offset_in_bits, 5, ENC_LITTLE_ENDIAN); offset_in_bits += 5;
proto_tree_add_bits_item (tmp_tree [ 9], hf_r3_dumpm41t81_reg09_rb, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [10], hf_r3_dumpm41t81_reg0a_afe, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [10], hf_r3_dumpm41t81_reg0a_sqwe, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [10], hf_r3_dumpm41t81_reg0a_abe, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [10], hf_r3_dumpm41t81_reg0a_10monthalm, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [10], hf_r3_dumpm41t81_reg0a_1monthalm, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [11], hf_r3_dumpm41t81_reg0b_rpt5, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [11], hf_r3_dumpm41t81_reg0b_rpt4, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [11], hf_r3_dumpm41t81_reg0b_10dayalm, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [11], hf_r3_dumpm41t81_reg0b_1dayalm, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [12], hf_r3_dumpm41t81_reg0c_rpt3, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [12], hf_r3_dumpm41t81_reg0c_ht, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [12], hf_r3_dumpm41t81_reg0c_10houralm, tvb, offset_in_bits, 2, ENC_LITTLE_ENDIAN); offset_in_bits += 2;
proto_tree_add_bits_item (tmp_tree [12], hf_r3_dumpm41t81_reg0c_1houralm, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [13], hf_r3_dumpm41t81_reg0d_rpt2, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [13], hf_r3_dumpm41t81_reg0d_10minalm, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [13], hf_r3_dumpm41t81_reg0d_1minalm, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [14], hf_r3_dumpm41t81_reg0e_rpt1, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [14], hf_r3_dumpm41t81_reg0e_10secalm, tvb, offset_in_bits, 3, ENC_LITTLE_ENDIAN); offset_in_bits += 3;
proto_tree_add_bits_item (tmp_tree [14], hf_r3_dumpm41t81_reg0e_1secalm, tvb, offset_in_bits, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [15], hf_r3_dumpm41t81_reg0f_wdf, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [15], hf_r3_dumpm41t81_reg0f_af, tvb, offset_in_bits, 1, ENC_LITTLE_ENDIAN); offset_in_bits += 1;
proto_tree_add_bits_item (tmp_tree [15], hf_r3_dumpm41t81_reg0f_notused, tvb, offset_in_bits, 6, ENC_LITTLE_ENDIAN); offset_in_bits += 6;
proto_tree_add_bits_item (tmp_tree [16], hf_r3_dumpm41t81_reg10_notused, tvb, offset_in_bits, 8, ENC_LITTLE_ENDIAN); offset_in_bits += 8;
proto_tree_add_bits_item (tmp_tree [17], hf_r3_dumpm41t81_reg11_notused, tvb, offset_in_bits, 8, ENC_LITTLE_ENDIAN); offset_in_bits += 8;
proto_tree_add_bits_item (tmp_tree [18], hf_r3_dumpm41t81_reg12_notused, tvb, offset_in_bits, 8, ENC_LITTLE_ENDIAN); offset_in_bits += 8;
proto_tree_add_bits_item (tmp_tree [19], hf_r3_dumpm41t81_reg13_rs, tvb, offset_in_bits - 8, 4, ENC_LITTLE_ENDIAN); offset_in_bits += 4;
proto_tree_add_bits_item (tmp_tree [19], hf_r3_dumpm41t81_reg13_notused, tvb, offset_in_bits - 8, 4, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreammfgfield_nvramchecksumvalue (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_nvramchecksumvalue, tvb, start_offset + 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramchecksumvalue_fixup, tvb, start_offset + 4, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_upstreammfgfield_checksumresults (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
proto_item *cksum_item = NULL;
proto_tree *cksum_tree= NULL;
guint32 l = tvb_length_remaining (tvb, start_offset);
guint32 error = FALSE;
guint32 i;
if (l % 3 != 0)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Checksum results data length not modulo 3 == 0");
else
{
for (i = start_offset; i < l; i += tvb_get_guint8 (tvb, start_offset + i))
error |= tvb_get_guint8 (tvb, start_offset + i + 2);
cksum_item = proto_tree_add_text (tree, tvb, start_offset, l, "Checksum Results (%s)", error ? "Error" : "No Errors");
cksum_tree = proto_item_add_subtree (cksum_item, ett_r3checksumresults);
for (i = 0; i < l; i += tvb_get_guint8 (tvb, start_offset + i))
{
proto_item *res_item = proto_tree_add_item (cksum_tree, hf_r3_checksumresults, tvb, start_offset + i, tvb_get_guint8 (tvb, start_offset + i), ENC_NA);
proto_tree *res_tree = proto_item_add_subtree (res_item, ett_r3checksumresultsfield);
const gchar *fn;
fn = val_to_str_ext_const (tvb_get_guint8 (tvb, start_offset + i + 1), &r3_checksumresultnames_ext, "[Unknown Field Name]");
proto_item_append_text (res_item, " %s (%s)", fn, tvb_get_guint8 (tvb, start_offset + i + 2) ? "Error" : "No Error");
proto_tree_add_item (res_tree, hf_r3_checksumresults_length, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (res_tree, hf_r3_checksumresults_field, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (res_tree, hf_r3_checksumresults_state, tvb, start_offset + i + 2, 1, ENC_LITTLE_ENDIAN);
}
}
}
static void dissect_r3_upstreammfgfield_mortisestatelog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint l = tvb_length_remaining (tvb, start_offset + 3);
guint i = 0;
proto_tree_add_item (tree, hf_r3_mortisestatelog_pointer, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mortisestatelog_mortisetype, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mortisestatelog_waiting, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
for (start_offset += 3, i = 0; i < l; i += 3)
{
guint state = tvb_get_guint8 (tvb, start_offset + i + 0);
guint last = tvb_get_guint8 (tvb, start_offset + i + 1);
guint event = tvb_get_guint8 (tvb, start_offset + i + 2);
proto_item *ms_item = proto_tree_add_text (tree, tvb, start_offset + i, 3, "State Log Entry %2d (State=0x%02x, Last=0x%02x, Event=%s (0x%02x))", i / 3, state, last, val_to_str_ext_const (event, &r3_mortiseeventnames_ext, "[Unknown]"), event);
proto_tree *ms_tree = proto_item_add_subtree (ms_item, ett_r3mortisestatelog);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_state, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_last, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_event, tvb, start_offset + i + 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void dissect_r3_upstreammfgfield_mortisepins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *iopins_item = proto_tree_add_text (tree, tvb, start_offset, 1, "Mortise Pin States (0x%02x)", tvb_get_guint8 (tvb, start_offset));
proto_tree *iopins_tree = proto_item_add_subtree (iopins_item, ett_r3iopins);
proto_tree_add_boolean (iopins_tree, hf_r3_mortisepins_s1, tvb, start_offset, 1, tvb_get_guint8 (tvb, start_offset));
proto_tree_add_boolean (iopins_tree, hf_r3_mortisepins_s2, tvb, start_offset, 1, tvb_get_guint8 (tvb, start_offset));
proto_tree_add_boolean (iopins_tree, hf_r3_mortisepins_s3, tvb, start_offset, 1, tvb_get_guint8 (tvb, start_offset));
proto_tree_add_boolean (iopins_tree, hf_r3_mortisepins_s4, tvb, start_offset, 1, tvb_get_guint8 (tvb, start_offset));
}
static void dissect_r3_upstreammfgfield_keypadchar (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item_append_text (proto_tree_add_item (tree, hf_r3_testkeypad, tvb, 0, 1, ENC_LITTLE_ENDIAN), " ('%c')", tvb_get_guint8 (tvb, 0));
}
static void dissect_r3_upstreammfgfield_magcard (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_testmagcard, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
static void dissect_r3_upstreammfgfield_proxcard (tvbuff_t *tvb, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_testproxcard, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
static void dissect_r3_response_singlebyte (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_responsetype, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_responsetocommand, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_response_hasdata (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
proto_item *upstreamcommand_item = NULL;
proto_tree *upstreamcommand_tree = NULL;
tvbuff_t *upstreamcommand_tvb;
guint32 commandPacketLen;
const gchar *ct = NULL;
tvb_ensure_bytes_exist (tvb, start_offset, 4);
commandPacketLen = tvb_get_guint8 (tvb, 0);
upstreamcommand_tvb = tvb_new_subset (tvb, 4, commandPacketLen - 4, commandPacketLen - 4);
if (tvb_get_guint8 (tvb, 1) != CMD_RESPONSE)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Octet 1 not CMD_RESPONSE");
else if (tvb_get_guint8 (tvb, 2) != RESPONSETYPE_HASDATA)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Octet 2 not RESPONSE_HASDATA");
else if (tvb_get_guint8 (tvb, 3) >= UPSTREAMCOMMAND_LAST)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Octet 3 >= UPSTREAMCOMMAND_LAST");
else
{
ct = val_to_str_ext_const (tvb_get_guint8 (tvb, 3), &r3_upstreamcommandnames_ext, "[Unknown Command Type]");
proto_tree_add_item (tree, hf_r3_responsetype, tvb, 2, 1, ENC_LITTLE_ENDIAN);
upstreamcommand_item = proto_tree_add_text (tree, tvb, 3, -1, "Upstream Command: %s (%u)", ct, tvb_get_guint8 (tvb, 3));
upstreamcommand_tree = proto_item_add_subtree (upstreamcommand_item, ett_r3upstreamcommand);
proto_tree_add_item (upstreamcommand_tree, hf_r3_upstreamcommand, tvb, 3, 1, ENC_LITTLE_ENDIAN);
tvb_ensure_bytes_exist (tvb, start_offset, commandPacketLen - 4);
if (r3upstreamcommand_dissect [tvb_get_guint8 (tvb, 3)].dissector)
(*r3upstreamcommand_dissect [tvb_get_guint8 (tvb, 3)].dissector) (upstreamcommand_tvb, 0, commandPacketLen - 4, pinfo, upstreamcommand_tree);
}
}
static void dissect_r3_cmd_response (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
guint8 responseLen = tvb_get_guint8 (tvb, start_offset + 0);
responseType_e responseType = tvb_get_guint8 (tvb, start_offset + 2);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset, responseLen, responseLen);
const gchar *rt = NULL;
rt = val_to_str_ext_const (responseType, &r3_responsetypenames_ext, "[Unknown Response Type]");
proto_item_set_text (proto_tree_get_parent (tree), "Response Packet: %s (%u)", rt, responseType);
proto_tree_add_item (tree, hf_r3_responselength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_responsecommand, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_guint8 (tvb, start_offset + 2) >= RESPONSETYPE_LAST)
expert_add_info_format (pinfo, tree, PI_UNDECODED, PI_WARN, "Octet 3 >= UPSTREAMCOMMAND_LAST");
else if (r3response_dissect [responseType].dissector)
(*r3response_dissect [responseType].dissector) (payload_tvb, 0, length, pinfo, tree);
}
static void dissect_r3_cmd_handshake (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_killsession (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_queryserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_queryversion (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_setdatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *dt_tree = NULL;
proto_item *dt_item = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
dt_item = proto_tree_add_text (tree, payload_tvb, 0, -1, "Set Date/Time (%02u/%02u/%02u-%u %02u:%02u:%02u)", tvb_get_guint8 (payload_tvb, 0), tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2), tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4), tvb_get_guint8 (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 6));
dt_tree = proto_item_add_subtree (dt_item, ett_r3setdatetime);
proto_tree_add_item (dt_tree, hf_r3_setdate_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_dow, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_hours, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_minutes, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_seconds, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_querydatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_setconfig (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 offset = 0;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
while (offset < tvb_reported_length (payload_tvb))
{
proto_item *sc_item = NULL;
proto_tree *sc_tree = NULL;
const gchar *ci = NULL;
ci = val_to_str_ext_const (tvb_get_guint8 (payload_tvb, offset + 1), &r3_configitemnames_ext, "[Unknown Configuration Item]");
sc_item = proto_tree_add_text (tree, payload_tvb, offset + 0, tvb_get_guint8 (payload_tvb, offset + 0), "Config Field: %s (%u)", ci, tvb_get_guint8 (payload_tvb, offset + 1));
sc_tree = proto_item_add_subtree (sc_item, ett_r3upstreamfield);
proto_tree_add_item (sc_tree, hf_r3_configitemlength, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (sc_tree, hf_r3_configitem, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_guint8 (payload_tvb, offset + 1) < array_length (configMap))
{
switch (configMap [tvb_get_guint8 (payload_tvb, offset + 1)].configType)
{
case CONFIGTYPE_NONE :
proto_tree_add_item (sc_tree, hf_r3_configitemdata, payload_tvb, offset + 2, tvb_get_guint8 (payload_tvb, offset + 0) - 3, ENC_NA);
break;
case CONFIGTYPE_BOOL :
proto_tree_add_item (sc_tree, hf_r3_configitemdata_bool, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_8 :
proto_tree_add_item (sc_tree, hf_r3_configitemdata_8, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_16 :
proto_tree_add_item (sc_tree, hf_r3_configitemdata_16, payload_tvb, offset + 2, 2, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_32 :
proto_tree_add_item (sc_tree, hf_r3_configitemdata_32, payload_tvb, offset + 2, 4, ENC_LITTLE_ENDIAN);
break;
case CONFIGTYPE_STRING :
proto_tree_add_item (sc_tree, hf_r3_configitemdata_string, payload_tvb, offset + 2, tvb_get_guint8 (payload_tvb, offset + 0) - 2, ENC_ASCII|ENC_NA);
break;
default :
proto_tree_add_none_format (sc_tree, hf_r3_upstreamfielderror, payload_tvb, offset + 2, tvb_get_guint8 (payload_tvb, offset + 0) - 2, "Unknown Field Type");
break;
}
}
else
proto_tree_add_text (sc_tree, payload_tvb, offset + 2, tvb_get_guint8 (payload_tvb, offset + 0) - 2, "[Unknown Field Type]");
offset += tvb_get_guint8 (payload_tvb, offset + 0);
}
}
static void dissect_r3_cmd_getconfig (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *config_item = NULL;
proto_tree *config_tree = NULL;
guint32 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
guint32 i;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
config_item = proto_tree_add_item (tree, hf_r3_configitems, tvb, start_offset + 2, cmdLen - 2, ENC_NA);
config_tree = proto_item_add_subtree (config_item, ett_r3configitem);
for (i = 2; i < cmdLen; i++)
proto_tree_add_item (config_tree, hf_r3_configitem, tvb, start_offset + i, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_manageuser (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 offset = 0;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
while (offset < tvb_reported_length (payload_tvb))
{
guint32 paramLength = tvb_get_guint8 (payload_tvb, offset + 0);
guint32 paramType = tvb_get_guint8 (payload_tvb, offset + 1);
guint32 dataLength = paramLength - 2;
proto_tree *mu_tree = NULL;
proto_item *len_field = NULL;
const gchar *auptn = NULL;
auptn = val_to_str_ext_const (paramType, &r3_adduserparamtypenames_ext, "[Unknown Field]");
mu_tree = proto_item_add_subtree (proto_tree_add_none_format (tree, hf_r3_adduserparamtype, payload_tvb, offset + 0, paramLength, "Manage User Field: %s (%u)", auptn, paramType), ett_r3manageuser);
len_field = proto_tree_add_item (mu_tree, hf_r3_adduserparamtypelength, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypetype, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
if (paramLength < 2)
{
dataLength = 0;
expert_add_info_format (pinfo, len_field, PI_UNDECODED, PI_WARN, "Malformed length value -- all fields are at least 2 octets.");
}
offset += 2;
switch (paramType)
{
case ADDUSERPARAMTYPE_DISPOSITION :
case ADDUSERPARAMTYPE_ACCESSALWAYS :
case ADDUSERPARAMTYPE_ACCESSMODE :
case ADDUSERPARAMTYPE_CACHED :
case ADDUSERPARAMTYPE_USERTYPE :
case ADDUSERPARAMTYPE_PRIMARYFIELDTYPE :
case ADDUSERPARAMTYPE_AUXFIELDTYPE :
case ADDUSERPARAMTYPE_USECOUNT :
case ADDUSERPARAMTYPE_EXCEPTIONGROUP :
if (dataLength != 1)
expert_add_info_format (pinfo, mu_tree, PI_UNDECODED, PI_WARN, "Malformed field -- expected 1 octet");
else
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_LITTLE_ENDIAN);
break;
case ADDUSERPARAMTYPE_USERNO :
if (dataLength != 2)
expert_add_info_format (pinfo, mu_tree, PI_UNDECODED, PI_WARN, "Malformed field -- expected 2 octets");
else
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_LITTLE_ENDIAN);
break;
case ADDUSERPARAMTYPE_PRIMARYFIELD :
case ADDUSERPARAMTYPE_AUXFIELD :
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_NA);
break;
case ADDUSERPARAMTYPE_EXPIREON :
{
proto_item *expireon_item = NULL;
proto_tree *expireon_tree = NULL;
if (dataLength != 3)
expert_add_info_format (pinfo, mu_tree, PI_UNDECODED, PI_WARN, "Malformed expiration field -- expected 3 octets");
else
{
expireon_item = proto_tree_add_text (mu_tree, payload_tvb, offset, 3, "Expire YY/MM/DD: %02u/%02u/%02u",
tvb_get_guint8 (payload_tvb, offset + 2), tvb_get_guint8 (payload_tvb, offset + 0), tvb_get_guint8 (payload_tvb, offset + 1));
expireon_tree = proto_item_add_subtree (expireon_item, ett_r3expireon);
proto_tree_add_item (expireon_tree, hf_r3_expireon_month, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_day, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_year, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case ADDUSERPARAMTYPE_TIMEZONE :
{
guint32 i;
guint32 tz;
proto_item *timezone_item = NULL;
proto_tree *timezone_tree = NULL;
if (dataLength != 4)
expert_add_info_format (pinfo, mu_tree, PI_UNDECODED, PI_WARN, "Malformed timezone field -- expected 4 octets");
else
{
tz = tvb_get_letohl (payload_tvb, offset);
timezone_item = proto_tree_add_item (mu_tree, hf_r3_upstreamfieldarray [paramType], payload_tvb, offset, 4, ENC_LITTLE_ENDIAN);
timezone_tree = proto_item_add_subtree (timezone_item, ett_r3timezone);
for (i = 0; i < 32; i++)
proto_tree_add_boolean (timezone_tree, hf_r3_timezonearray [i], payload_tvb, offset, 4, tz);
}
}
break;
default :
proto_tree_add_string (mu_tree, hf_r3_upstreamfielderror, payload_tvb, offset, dataLength, "Unknown Field Type");
break;
}
offset += dataLength;
}
}
static void dissect_r3_cmd_deleteusers (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_deleteusers, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_defineexception (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *startdate_item = NULL;
proto_tree *startdate_tree = NULL;
proto_item *enddate_item = NULL;
proto_tree *enddate_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_defineexception_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
startdate_item = proto_tree_add_text (tree, payload_tvb, 1, 4, "Start MM/DD HH:MM (%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2), tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4));
startdate_tree = proto_item_add_subtree (startdate_item, ett_r3defineexceptionstartdate);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
enddate_item = proto_tree_add_text (tree, payload_tvb, 5, 4, "End MM/DD HH:MM (%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 6), tvb_get_guint8 (payload_tvb, 7), tvb_get_guint8 (payload_tvb, 8));
enddate_tree = proto_item_add_subtree (enddate_item, ett_r3defineexceptionenddate);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_month, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_day, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_hours, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_minutes, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_defineexceptiongroup (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *bits_item = NULL;
proto_tree *bits_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 i = 0;
guint32 bit = 0;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_defineexceptiongroup_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
bits_item = proto_tree_add_text (tree, payload_tvb, 1, -1, "Exception Group Bit Field");
bits_tree = proto_item_add_subtree (bits_item, ett_r3defineexceptiongroupbits);
for (i = 1; i < tvb_reported_length (payload_tvb); i++)
{
guint32 j;
guint8 byte = tvb_get_guint8 (payload_tvb, i);
for (j = 0; j < 8; j++)
proto_tree_add_none_format (bits_tree, hf_r3_defineexceptiongroup_bits, payload_tvb, i, 1, "Exception Group %2d: %s", bit++, (byte & (1 << j)) ? "Enabled" : "Disabled");
}
}
static void dissect_r3_cmd_definecalendar (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
const gchar *mn;
guint32 i;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_definecalendar_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
for (i = 0; i < 12; i++)
{
guint32 daymap = tvb_get_letohl (payload_tvb, (i * 4) + 1);
proto_item *calendar_item = proto_tree_add_text (tree, payload_tvb, (i * 4) + 1, 4, "Calendar Bit Field - %s (0x%08x)", (mn = val_to_str_ext_const (i + 1, &r3_monthnames_ext, "[Unknown Month]")), daymap);
proto_tree *calendar_tree = proto_item_add_subtree (calendar_item, ett_r3definecalendarmonth [i + 1]);
guint32 j;
for (j = 0; j < 31; j++)
proto_tree_add_none_format (calendar_tree, hf_r3_definecalendar_bits, payload_tvb, (i * 4) + 1, 4, "%s Of %s: %s", val_to_str_ext_const (j + 1, &r3_monthdaynames_ext, "[Unknown Day]"), mn, (daymap & (1 << j)) ? "Enabled" : "Disabled");
}
}
static void dissect_r3_cmd_definetimezone (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *starttime_item = NULL;
proto_tree *starttime_tree = NULL;
proto_item *endtime_item = NULL;
proto_tree *endtime_tree = NULL;
proto_item *daymap_item = NULL;
proto_tree *daymap_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 i;
guint8 tzmode;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_definetimezone_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
starttime_item = proto_tree_add_text (tree, payload_tvb, 1, 2, "Start HH:MM (%02u:%02u)", tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2));
starttime_tree = proto_item_add_subtree (starttime_item, ett_r3definetimezonestarttime);
proto_tree_add_item (starttime_tree, hf_r3_definetimezone_starttime_hours, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_definetimezone_starttime_minutes, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
endtime_item = proto_tree_add_text (tree, payload_tvb, 3, 2, "End HH:MM (%02u:%02u)", tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4));
endtime_tree = proto_item_add_subtree (endtime_item, ett_r3definetimezoneendtime);
proto_tree_add_item (endtime_tree, hf_r3_definetimezone_endtime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_definetimezone_endtime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
daymap_item = proto_tree_add_text (tree, payload_tvb, 5, 1, "Day Map (0x%02x)", tvb_get_guint8 (payload_tvb, 5));
daymap_tree = proto_item_add_subtree (daymap_item, ett_r3definetimezonedaymap);
for (i = 0; i < 7; i++)
proto_tree_add_boolean (daymap_tree, hf_r3_definetimezone_daymap [i], payload_tvb, 5, 1, tvb_get_guint8 (payload_tvb, 5));
proto_tree_add_item (tree, hf_r3_definetimezone_exceptiongroup, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint (tree, hf_r3_definetimezone_mode, payload_tvb, 7, 1, (tzmode = tvb_get_guint8 (payload_tvb, 7)) & 0x0f);
proto_tree_add_none_format (tree, hf_r3_definetimezone_calendar, payload_tvb, 7, 1, "Access Always: %s", (tzmode & 0x10) ? "True" : "False");
}
static void dissect_r3_cmd_rmtauthretry (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_rmtauthretry_sequence, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_rmtauthretry_retry, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_filters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *filter_item = NULL;
proto_tree *filter_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 i;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_filter_type, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
filter_item = proto_tree_add_text (tree, payload_tvb, 2, -1, "Filters (%u specified)", tvb_get_guint8 (payload_tvb, 0));
filter_tree = proto_item_add_subtree (filter_item, ett_r3filters);
for (i = 0; i < tvb_get_guint8 (payload_tvb, 0); i++)
proto_tree_add_item (filter_tree, hf_r3_filter_list, payload_tvb, i + 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_alarmconfigure (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *alarm_item = NULL;
proto_tree *alarm_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 offset = 0;
guint32 alarms = 0;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
alarm_item = proto_tree_add_text (tree, payload_tvb, 0, -1, "Alarm List (0 items)");
alarm_tree = proto_item_add_subtree (alarm_item, ett_r3alarmlist);
while (offset < tvb_reported_length (payload_tvb))
{
proto_item *alarmcfg_item = NULL;
proto_tree *alarmcfg_tree = NULL;
const gchar *ai;
const gchar *as;
if (!(ai = match_strval_ext (tvb_get_guint8 (payload_tvb, offset + 1), &r3_alarmidnames_ext)))
{
ai = "[Unknown Alarm ID]";
as = "N/A";
}
else
as = (tvb_get_guint8 (payload_tvb, offset + 2) & 0xfe) ? "Error" : (tvb_get_guint8 (payload_tvb, offset + 2) & 0x01) ? "Enabled" : "Disabled";
alarmcfg_item = proto_tree_add_text (alarm_tree, payload_tvb, offset, tvb_get_guint8 (payload_tvb, offset), "Alarm Item (%s, %s)", ai, as);
alarmcfg_tree = proto_item_add_subtree (alarmcfg_item, ett_r3alarmcfg);
proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_length, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_id, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_state, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
alarms++;
offset += tvb_get_guint8 (payload_tvb, offset);
}
if (alarms)
proto_item_set_text (alarm_item, "Alarm List (%d items)", alarms);
}
static void dissect_r3_cmd_eventlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *starttime_item = NULL;
proto_tree *starttime_tree = NULL;
proto_item *endtime_item = NULL;
proto_tree *endtime_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_item = proto_tree_add_text (tree, payload_tvb, 0, 5, "Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 0), tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2), tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4));
starttime_tree = proto_item_add_subtree (starttime_item, ett_r3eventlogdumpstarttime);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_item = proto_tree_add_text (tree, payload_tvb, 5, 5, "End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 6), tvb_get_guint8 (payload_tvb, 7), tvb_get_guint8 (payload_tvb, 8), tvb_get_guint8 (payload_tvb, 9));
endtime_tree = proto_item_add_subtree (endtime_item, ett_r3eventlogdumpendtime);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_eventlogdump_user, payload_tvb, 10, 2, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_declinedlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *starttime_item = NULL;
proto_tree *starttime_tree = NULL;
proto_item *endtime_item = NULL;
proto_tree *endtime_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_item = proto_tree_add_text (tree, payload_tvb, 0, 5, "Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 0), tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2), tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4));
starttime_tree = proto_item_add_subtree (starttime_item, ett_r3declinedlogdumpstarttime);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_item = proto_tree_add_text (tree, payload_tvb, 5, 5, "End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 6), tvb_get_guint8 (payload_tvb, 7), tvb_get_guint8 (payload_tvb, 8), tvb_get_guint8 (payload_tvb, 9));
endtime_tree = proto_item_add_subtree (endtime_item, ett_r3declinedlogdumpendtime);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_alarmlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *starttime_item = NULL;
proto_tree *starttime_tree = NULL;
proto_item *endtime_item = NULL;
proto_tree *endtime_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_item = proto_tree_add_text (tree, payload_tvb, 0, 5, "Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 0), tvb_get_guint8 (payload_tvb, 1), tvb_get_guint8 (payload_tvb, 2), tvb_get_guint8 (payload_tvb, 3), tvb_get_guint8 (payload_tvb, 4));
starttime_tree = proto_item_add_subtree (starttime_item, ett_r3alarmlogdumpstarttime);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_item = proto_tree_add_text (tree, payload_tvb, 5, 5, "End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)", tvb_get_guint8 (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 6), tvb_get_guint8 (payload_tvb, 7), tvb_get_guint8 (payload_tvb, 8), tvb_get_guint8 (payload_tvb, 9));
endtime_tree = proto_item_add_subtree (endtime_item, ett_r3alarmlogdumpendtime);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_downloadfirmware (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *dlfw_item = NULL;
proto_tree *dlfw_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 packetCRC = 0;
guint32 calculatedCRC = 0;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
dlfw_item = proto_tree_add_text (tree, payload_tvb, 0, -1, "Download Record (Record #%u, ", tvb_get_letohs (payload_tvb, 2));
dlfw_tree = proto_item_add_subtree (dlfw_item, ett_r3downloadfirmware);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_length, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_record, payload_tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_action, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (payload_tvb, 4))
{
case DOWNLOADFIRMWARE_START :
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_START)");
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_timeout, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_nvram, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
break;
case DOWNLOADFIRMWARE_DATA :
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_DATA, Address 0x%08x, %u Bytes)", tvb_get_letohl (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 9));
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_address, payload_tvb, 5, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_bytes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_data, payload_tvb, 10, tvb_get_guint8 (payload_tvb, 9), ENC_NA);
break;
case DOWNLOADFIRMWARE_COMPLETE :
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_COMPLETE)");
break;
case DOWNLOADFIRMWARE_ABORT :
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_ABORT)");
break;
case DOWNLOADFIRMWARE_RESET :
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_RESET)");
break;
default :
DISSECTOR_ASSERT (0);
}
packetCRC = tvb_get_letohs (payload_tvb, tvb_reported_length (payload_tvb) - 2);
if ((calculatedCRC = utilCrcCalculate (tvb_get_ptr (payload_tvb, 0, tvb_reported_length (payload_tvb) - 2), tvb_reported_length (payload_tvb) - 2, 0x0000)) == packetCRC)
proto_tree_add_uint_format (dlfw_tree, hf_r3_firmwaredownload_crc, payload_tvb, tvb_reported_length (payload_tvb) - 2, 2, packetCRC, "CRC: 0x%04x (correct)", packetCRC);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format (dlfw_tree, hf_r3_firmwaredownload_crc, payload_tvb, tvb_reported_length (payload_tvb) - 2, 2, packetCRC, "CRC: 0x%04x (incorrect, should be 0x%04x)", calculatedCRC, packetCRC);
tmp_item = proto_tree_add_boolean (dlfw_tree, hf_r3_firmwaredownload_crc_bad, payload_tvb, tvb_reported_length (payload_tvb) - 2, 2, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
}
static void dissect_r3_cmd_downloadfirmwaretimeout (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commanddata, payload_tvb, 0, -1, ENC_NA);
DISSECTOR_ASSERT (0);
}
static void dissect_r3_cmd_powertableselection (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_powertableselection, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_clearnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *nvram_item = NULL;
proto_tree *nvram_tree = NULL;
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
guint32 nvramclearoptions = tvb_get_letohs (payload_tvb, 0);
guint32 i;
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
nvram_item = proto_tree_add_text (tree, payload_tvb, 0, 2, "NVRAM Clean Options (0x%04x)", nvramclearoptions);
nvram_tree = proto_item_add_subtree (nvram_item, ett_r3clearnvram);
for (i = 0; i < 16; i++)
proto_tree_add_boolean (nvram_tree, hf_r3_nvramclearoptions [i], payload_tvb, 0, 2, nvramclearoptions);
}
static void dissect_r3_cmd_dpac (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_action, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_waittime, payload_tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_command, payload_tvb, 3, -1, ENC_NA);
}
static void dissect_r3_cmd_selftest (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_reset (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_logwrite (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 2, cmdLen - 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_writeeventlog_user, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_writeeventlog_event, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_mfgcommand (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
mfgCommandFlag = TRUE;
}
static void dissect_r3_cmd_nvrambackup (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmd_extendedresponse (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_setserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
tvbuff_t *sn_tvb = tvb_new_subset (tvb, start_offset + 2, 16, 16);
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
dissect_serialnumber (sn_tvb, 0, length, pinfo, tree, hf_r3_mfgsetserialnumber);
}
static void dissect_r3_cmdmfg_setcryptkey (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgsetcryptkey, tvb, start_offset + 2, -1, ENC_NA);
}
static void dissect_r3_cmdmfg_dumpnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgdumpnvram, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_terminal (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_remoteunlock (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgremoteunlock, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_auxctlrversion (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_iopins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_adcs (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_hardwareid (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_checkpointlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_checkpointlogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_readregisters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_forceoptions (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint i = 0;
guint l = 0;
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
start_offset += 2;
l = tvb_length_remaining (tvb, start_offset);
for (i = 0; i < l; i += tvb_get_guint8 (tvb, start_offset + i))
{
proto_item *force_item = proto_tree_add_text (tree, tvb, start_offset + i, tvb_get_guint8 (tvb, start_offset + i), "Force Option %s (%u)", val_to_str_ext_const (tvb_get_guint8 (tvb, start_offset + i + 1), &r3_forceitemnames_ext, "[Unknown]"), tvb_get_guint8 (tvb, start_offset + i + 1));
proto_tree *force_tree = proto_item_add_subtree (force_item, ett_r3forceoptions);
proto_tree_add_item (force_tree, hf_r3_forceoptions_length, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (force_tree, hf_r3_forceoptions_item, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, start_offset + i) - 2)
{
case 1 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_8, tvb, start_offset + i + 2, 1, ENC_LITTLE_ENDIAN); break;
case 2 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_16, tvb, start_offset + i + 2, 2, ENC_LITTLE_ENDIAN); break;
case 3 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_24, tvb, start_offset + i + 2, 3, ENC_LITTLE_ENDIAN); break;
case 4 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_32, tvb, start_offset + i + 2, 4, ENC_LITTLE_ENDIAN); break;
default : DISSECTOR_ASSERT (0);
}
}
}
static void dissect_r3_cmdmfg_commuser (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_dumpkeypad (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_batterycheck (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_ramrefresh (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_taskflags (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_timerchain (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_peekpoke (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint i = 0;
guint l = 0;
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
start_offset += 2;
l = tvb_length_remaining (tvb, start_offset);
for (i = 0; i < l; i += 3)
{
proto_item *peekpoke_item = proto_tree_add_text (tree, tvb, start_offset + i, 3, "%s", "");
proto_tree *peekpoke_tree = proto_item_add_subtree (peekpoke_item, ett_r3peekpoke);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_operation, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_address, tvb, start_offset + i + 1, 2, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, start_offset + i + 0))
{
case PEEKPOKE_READU8 :
proto_item_append_text (peekpoke_item, "Read (8 Bits @ 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 1));
break;
case PEEKPOKE_READU16 :
proto_item_append_text (peekpoke_item, "Read (16 Bits @ 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 1));
break;
case PEEKPOKE_READU24 :
proto_item_append_text (peekpoke_item, "Read (24 Bits @ 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 1));
break;
case PEEKPOKE_READU32 :
proto_item_append_text (peekpoke_item, "Read (32 Bits @ 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 1));
break;
case PEEKPOKE_READSTRING :
proto_item_append_text (peekpoke_item, "Read (%d Bytes @ 0x%04x)", tvb_get_guint8 (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
i += 1;
break;
case PEEKPOKE_WRITEU8 :
proto_item_append_text (peekpoke_item, "Write (8 Bits: 0x%02x @ 0x%04x)", tvb_get_guint8 (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke8, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
i += 1;
break;
case PEEKPOKE_WRITEU16 :
proto_item_append_text (peekpoke_item, "Write (16 Bits: 0x%04x @ 0x%04x)", tvb_get_letohs (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 5);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke16, tvb, start_offset + i + 3, 2, ENC_LITTLE_ENDIAN);
i += 2;
break;
case PEEKPOKE_WRITEU24 :
proto_item_append_text (peekpoke_item, "Write (24 Bits: 0x%06x @ 0x%04x)", tvb_get_letoh24 (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 6);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke24, tvb, start_offset + i + 3, 3, ENC_LITTLE_ENDIAN);
i += 3;
break;
case PEEKPOKE_WRITEU32 :
proto_item_append_text (peekpoke_item, "Write (32 Bits: 0x%08x @ 0x%04x)", tvb_get_letohl (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 7);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke32, tvb, start_offset + i + 3, 4, ENC_LITTLE_ENDIAN);
i += 4;
break;
case PEEKPOKE_WRITESTRING :
proto_item_append_text (peekpoke_item, "Write (%d Bytes @ 0x%04x)", tvb_get_guint8 (tvb, start_offset + i + 3), tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 3 + 1 + tvb_get_guint8 (tvb, start_offset + i + 3));
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_pokestring, tvb, start_offset + i + 4, tvb_get_guint8 (tvb, start_offset + i + 3), ENC_NA);
i += tvb_get_guint8 (tvb, start_offset + i + 3) + 1;
break;
default :
DISSECTOR_ASSERT (0);
}
}
}
static void dissect_r3_cmdmfg_lockstate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_capabilities (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_dumpm41t81 (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_debuglogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_debuglogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_testwdt (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_querycksum (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_validatechecksums (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_rebuildlrucache (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_tzupdate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_testpreserve (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgtestpreserve, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_mortisestatelogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_mortisestatelogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_mortisepins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void dissect_r3_cmdmfg_haltandcatchfire (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static gint dissect_r3_command (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *r3_tree)
{
if (r3_tree)
{
proto_item *cmd_item = NULL;
proto_tree *cmd_tree = NULL;
const gchar *cn = NULL;
guint8 cmdLen;
guint8 cmd;
tvb_ensure_bytes_exist (tvb, start_offset, 2);
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
cmd = tvb_get_guint8 (tvb, start_offset + 1);
if (!mfgCommandFlag)
cn = val_to_str_ext_const (cmd, &r3_cmdnames_ext, "[Unknown Command]");
else
cn = val_to_str_ext_const (cmd, &r3_cmdmfgnames_ext, "[Unknown Mfg Command]");
cmd_item = proto_tree_add_text (r3_tree, tvb, start_offset, cmdLen, "Command Packet: %s (%d)", cn, cmd);
cmd_tree = proto_item_add_subtree (cmd_item, ett_r3cmd);
if (cmd_tree)
{
if (!mfgCommandFlag)
{
if (cmd >= CMD_LAST)
expert_add_info_format (pinfo, cmd_tree, PI_UNDECODED, PI_WARN, "Unknown command value");
else if (r3command_dissect [cmd].dissector)
(*r3command_dissect [cmd].dissector) (tvb, start_offset, length, pinfo, cmd_tree);
}
else
{
mfgCommandFlag = FALSE;
if (cmd >= CMDMFG_LAST)
expert_add_info_format (pinfo, cmd_tree, PI_UNDECODED, PI_WARN, "Unknown manufacturing command value");
else if (r3commandmfg_dissect [cmd].dissector)
(*r3commandmfg_dissect [cmd].dissector) (tvb, start_offset, length, pinfo, cmd_tree);
}
}
}
return tvb_get_guint8 (tvb, start_offset);
}
static gint dissect_r3_packet (tvbuff_t *tvb, guint start_offset, packet_info *pinfo, proto_tree *r3_tree)
{
guint offset = 0;
guint octConsumed;
gint available = tvb_length_remaining (tvb, start_offset);
if (!(tvb_strneql (tvb, start_offset, "~~~ds", 5)))
{
if (r3_tree)
proto_tree_add_item (r3_tree, hf_r3_tildex3ds, tvb, start_offset + 0, -1, ENC_ASCII|ENC_NA);
offset = start_offset + 5;
}
else
{
gint packetLen = 0;
if (available < 4)
return available - 4;
else
{
packetLen = tvb_get_guint8 (tvb, start_offset + 3) + 1;
if (packetLen > available)
return available - packetLen;
}
--packetLen;
if (r3_tree)
{
proto_item *header_item = proto_tree_add_item (r3_tree, hf_r3_header, tvb, start_offset + 0, 5, ENC_NA);
proto_tree *header_tree = proto_item_add_subtree (header_item, ett_r3header);
proto_tree_add_item (header_tree, hf_r3_sigil, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_address, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_packetnumber, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_packetlength, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_encryption, tvb, start_offset + 4, 1, ENC_LITTLE_ENDIAN);
}
if (available > 8)
{
proto_item *payload_item = NULL;
proto_tree *payload_tree = NULL;
tvbuff_t *payload_tvb = tvb_new_subset (tvb, start_offset + 5, packetLen - 7, packetLen - 7);
if (r3_tree)
{
payload_item = proto_tree_add_item (r3_tree, hf_r3_payload, payload_tvb, 0, -1, ENC_NA);
payload_tree = proto_item_add_subtree (payload_item, ett_r3payload);
}
while (offset < tvb_reported_length (payload_tvb))
{
octConsumed = dissect_r3_command (payload_tvb, offset, 0, pinfo, payload_tree);
if(!octConsumed)
{
expert_add_info_format (pinfo, payload_tree, PI_MALFORMED, PI_WARN, "Command length equal to 0; payload could be partially decoded");
offset = tvb_reported_length (payload_tvb);
break;
}
offset += octConsumed;
}
}
offset += start_offset;
if (r3_tree)
{
proto_item *tail_item = proto_tree_add_item (r3_tree, hf_r3_tail, tvb, offset + 5, 3, ENC_NA);
proto_tree *tail_tree = proto_item_add_subtree (tail_item, ett_r3tail);
guint32 packetCRC = tvb_get_letohs (tvb, offset + 5);
guint32 packetXor = tvb_get_guint8 (tvb, offset + 7);
guint32 calculatedCRC = 0;
if ((calculatedCRC = utilCrcCalculate (tvb_get_ptr (tvb, start_offset + 1, packetLen - 3), packetLen - 3, 0x0000)) == packetCRC)
proto_tree_add_uint_format (tail_tree, hf_r3_crc, tvb, offset + 5, 2, packetCRC, "CRC: 0x%04x (correct)", packetCRC);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format (tail_tree, hf_r3_crc, tvb, offset + 5, 2, packetCRC, "CRC: 0x%04x (incorrect, should be 0x%04x)", calculatedCRC, packetCRC);
tmp_item = proto_tree_add_boolean (tail_tree, hf_r3_crc_bad, tvb, offset + 5, 2, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
if ((packetLen ^ 0xff) == (int)packetXor)
proto_tree_add_uint_format (tail_tree, hf_r3_xor, tvb, offset + 7, 1, packetXor, "XOR: 0x%02x (correct)", packetXor);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format (tail_tree, hf_r3_xor, tvb, offset + 7, 1, packetXor, "XOR: 0x%02x (incorrect, should be 0x%02x)", packetXor, packetLen ^ 0xff);
tmp_item = proto_tree_add_boolean (tail_tree, hf_r3_xor_bad, tvb, offset + 7, 1, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
}
offset += 8;
}
return offset - start_offset;
}
static void dissect_r3_message (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *r3_item = NULL;
proto_tree *r3_tree = NULL;
guint offset = 0;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "R3");
col_clear (pinfo->cinfo, COL_INFO);
if (tree)
{
r3_item = proto_tree_add_item (tree, proto_r3, tvb, 0, -1, ENC_NA);
r3_tree = proto_item_add_subtree (r3_item, ett_r3);
}
while (offset < tvb_reported_length (tvb))
{
gint res = dissect_r3_packet (tvb, offset, pinfo, r3_tree);
if (res <= 0)
{
if (r3_item)
proto_item_set_len (r3_item, offset);
return;
}
offset += res;
}
return;
}
static guint get_r3_message_len (packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return (guint) tvb_get_guint8 (tvb, offset + 3) + 1;
}
static void dissect_r3 (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus (tvb, pinfo, tree, TRUE, 4, get_r3_message_len, dissect_r3_message);
}
void proto_register_r3 (void)
{
proto_r3 = proto_register_protocol ("Assa Abloy R3", "R3", "r3");
register_dissector ("r3", dissect_r3, proto_r3);
proto_register_field_array (proto_r3, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void proto_reg_handoff_r3 (void)
{
dissector_handle_t r3_handle = find_dissector ("r3");
dissector_add_uint ("tcp.port", 2571, r3_handle);
dissector_add_uint ("tcp.port", 8023, r3_handle);
}
