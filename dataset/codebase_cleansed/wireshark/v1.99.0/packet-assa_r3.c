static guint16
utilCrcCalculate (const void *ptr, guint16 len, guint16 crc)
{
const guint8 *p = (const guint8 *) ptr;
while (len--)
crc = (guint16) ((crc << 8) ^ ccitt_16 [(crc >> 8) ^ *p++]);
return crc;
}
static void
dissect_serialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree, int hf_index)
{
proto_item *sn_item;
proto_tree *sn_tree;
const gchar *s;
tvb_ensure_bytes_exist (tvb, start_offset, 16);
if (!tree)
return;
sn_item = proto_tree_add_item (tree, hf_index, tvb, start_offset, 16, ENC_ASCII|ENC_NA);
sn_tree = proto_item_add_subtree (sn_item, ett_r3serialnumber);
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 0, 2, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 0, 2, "Manufacturer .. : %s (%s)", s, str_to_str (s, r3_snmanufacturernames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 2, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 2, 1, "Year .......... : %s (%s)", s, str_to_str (s, r3_snyearnames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 3, 2, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 3, 2, "Week .......... : %s", s);
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 5, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 5, 1, "Model ......... : %s (%s)", s, str_to_str (s, r3_snmodelnames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 6, 4, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 6, 4, "Sequence ...... : %s", s);
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 10, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 10, 1, "Group ......... : %s (%s)", s, str_to_str (s, r3_sngroupnames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 11, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 11, 1, "NID ........... : %s (%s)", s, str_to_str (s, r3_snnidnames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 12, 2, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 12, 2, "HID ........... : %s (%s)", s, str_to_str (s, r3_snhidnames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 14, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 14, 1, "Power Supply .. : %s (%s)", s, str_to_str (s, r3_snpowersupplynames, "[Unknown]"));
s = tvb_get_string_enc (wmem_packet_scope(), tvb, start_offset + 15, 1, ENC_ASCII|ENC_NA);
proto_tree_add_text (sn_tree, tvb, start_offset + 15, 1, "Mortise ....... : %s (%s)", s, str_to_str (s, r3_snmortisenames, "[Unknown]"));
}
static void
dissect_r3_upstreamfields (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
guint32 offset = 0;
DISSECTOR_ASSERT(start_offset == 0);
while (offset < tvb_reported_length (tvb))
{
guint32 fieldLength = tvb_get_guint8 (tvb, offset + 0);
guint32 fieldType = tvb_get_guint8 (tvb, offset + 1);
guint32 dataLength = fieldLength - 2;
proto_item *upstreamfield_item;
proto_item *upstreamfield_length;
proto_tree *upstreamfield_tree;
const gchar *usfn;
usfn = val_to_str_ext_const (fieldType, &r3_upstreamfieldnames_ext, "[Unknown Field]");
upstreamfield_item = proto_tree_add_none_format (tree, hf_r3_upstreamfield, tvb, offset + 0, fieldLength, "Upstream Field: %s (%u)", usfn, fieldType);
upstreamfield_tree = proto_item_add_subtree (upstreamfield_item, ett_r3upstreamfield);
upstreamfield_length = proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldlength, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (upstreamfield_tree, hf_r3_upstreamfieldtype, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
if (fieldLength < 2)
{
dataLength = 0;
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed length value -- all fields are at least 2 octets.");
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
tvbuff_t *sn_tvb = tvb_new_subset_length (tvb, offset, dataLength);
dissect_serialnumber (sn_tvb, 0, length, pinfo, upstreamfield_tree, hf_r3_upstreamfieldarray [fieldType]);
}
break;
case UPSTREAMFIELD_EVENTLOGRECORD :
{
if (dataLength != 9)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed event log field -- expected 9 octets");
}
else
{
proto_tree *eventlog_tree;
if (!upstreamfield_tree)
break;
eventlog_tree = proto_tree_add_subtree(upstreamfield_tree, tvb, offset, 9, ett_r3eventlogrecord, NULL, "Event Log Record");
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
if (dataLength != 8)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed date/time field -- expected 8 octets");
}
else
{
proto_tree *datetime_tree;
if (!upstreamfield_tree)
break;
datetime_tree = proto_tree_add_subtree_format(upstreamfield_tree, tvb, offset, 8, ett_r3datetime, NULL,
"Date/Time: %02u/%02u/%02u-%u %02u:%02u:%02u %u",
tvb_get_guint8 (tvb, offset + 0), tvb_get_guint8 (tvb, offset + 1), tvb_get_guint8 (tvb, offset + 2), tvb_get_guint8 (tvb, offset + 3),
tvb_get_guint8 (tvb, offset + 4), tvb_get_guint8 (tvb, offset + 5), tvb_get_guint8 (tvb, offset + 6), tvb_get_guint8 (tvb, offset + 7));
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
if (dataLength != 49)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed declined log field -- expected 49 octets");
}
else
{
proto_tree *declinedlog_tree;
guint8 cred1type;
guint8 cred2type;
if (!upstreamfield_tree)
break;
declinedlog_tree = proto_tree_add_subtree(upstreamfield_tree, tvb, offset, 49, ett_r3declinedlogrecord, NULL, "Declined Log Record");
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
if (dataLength != 3)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed expiration field -- expected 3 octets");
}
else
{
proto_tree *expireon_tree;
if (!upstreamfield_tree)
break;
expireon_tree = proto_tree_add_subtree_format(upstreamfield_tree, tvb, offset, 3, ett_r3expireon, NULL,
"Expire YY/MM/DD: %02u/%02u/%02u",
tvb_get_guint8 (tvb, offset + 2), tvb_get_guint8 (tvb, offset + 0), tvb_get_guint8 (tvb, offset + 1));
proto_tree_add_item (expireon_tree, hf_r3_expireon_month, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_day, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_year, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case UPSTREAMFIELD_TIMEZONE :
{
if (dataLength != 4)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed timezone field -- expected 4 octets");
}
else
{
proto_item *timezone_item;
proto_tree *timezone_tree;
guint32 i;
guint32 tz;
if (!upstreamfield_tree)
break;
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
if (dataLength != 9)
{
expert_add_info_format(pinfo, upstreamfield_length, &ei_r3_malformed_length, "Malformed alarm log field -- expected 9 octets");
}
else
{
proto_tree *alarmlog_tree;
if (!upstreamfield_tree)
break;
alarmlog_tree = proto_tree_add_subtree(upstreamfield_tree, tvb, offset, 9, ett_r3alarmlogrecord, NULL, "Alarm Record");
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
static void
dissect_r3_upstreamcommand_reserved (tvbuff_t *tvb _U_, guint32 start_offset _U_, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
proto_tree_add_expert(tree, pinfo, &ei_r3_reserved_upstream_command_value, tvb, start_offset, length);
}
static void
dissect_r3_upstreamcommand_debugmsg (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *debugmsg_tree;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
debugmsg_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_r3debugmsg, NULL, "Debug message");
proto_tree_add_item (debugmsg_tree, hf_r3_debugmsg, tvb, 1, -1, ENC_ASCII|ENC_NA);
}
static void
dissect_r3_upstreamcommand_queryversion (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_querydatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_queryserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dumpeventlog (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
DISSECTOR_ASSERT(start_offset == 0);
tvb_ensure_bytes_exist (tvb, 0, 11);
if (length != 11)
{
expert_add_info_format(pinfo, proto_tree_get_parent (tree), &ei_r3_malformed_length, "Malformed event log record -- expected 10 octets");
}
else
{
proto_tree *eventlog_tree;
const gchar *en;
if (!tree)
return;
en = val_to_str_ext_const (tvb_get_guint8 (tvb, 10), &r3_eventnames_ext, "[Unknown Event]");
eventlog_tree = proto_tree_add_subtree_format(tree, tvb, start_offset, 10, ett_r3eventlogrecord, NULL,
"Event Log Record %u (%s)", tvb_get_letohs (tvb, 0), en);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_recordnumber, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_year, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_month, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_day, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_hour, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_minute, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_second, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_usernumber, tvb, 8, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (eventlog_tree, hf_r3_eventlog_event, tvb, 10, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_upstreamcommand_dumpnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
DISSECTOR_ASSERT(start_offset == 0);
tvb_ensure_bytes_exist (tvb, 0, 3);
if (!tree)
return;
proto_tree_add_item (tree, hf_r3_nvramdump_record, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdump_length, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdump_data, tvb, 3, tvb_get_guint8 (tvb, 2), ENC_NA);
}
static void
dissect_r3_upstreamcommand_rmtquthrequest (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_retrieveuser (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_queryconfig (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 offset = 0;
DISSECTOR_ASSERT(start_offset == 0);
if (!tree)
return;
while (offset < tvb_reported_length (tvb))
{
proto_item *pi;
proto_tree *upstreamfield_tree;
const gchar *ci;
guint8 item_length;
ci = val_to_str_ext_const (tvb_get_guint8 (tvb, offset + 1), &r3_configitemnames_ext, "[Unknown Configuration Item]");
item_length = tvb_get_guint8 (tvb, offset + 0);
upstreamfield_tree = proto_tree_add_subtree_format(tree, tvb, offset + 0, item_length, ett_r3upstreamfield, NULL,
"Config Field: %s (%u)", ci, tvb_get_guint8 (tvb, offset + 1));
pi = proto_tree_add_item (upstreamfield_tree, hf_r3_configitemlength, tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
if (item_length == 0) {
expert_add_info_format(pinfo, pi, &ei_r3_malformed_length, "Invalid item length");
return;
}
proto_tree_add_item (upstreamfield_tree, hf_r3_configitem, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemtype, tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, offset + 2))
{
case CONFIGTYPE_NONE :
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata, tvb, offset + 3, item_length - 3, ENC_NA);
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
proto_tree_add_item (upstreamfield_tree, hf_r3_configitemdata_string, tvb, offset + 3, item_length - 3, ENC_ASCII|ENC_NA);
break;
default :
proto_tree_add_none_format (upstreamfield_tree, hf_r3_upstreamfielderror, tvb, offset + 3, item_length - 3, "Unknown Field Type");
break;
}
offset += item_length;
}
}
static void
dissect_r3_upstreamcommand_rmteventlogrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dpac (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_dpacreply_stuff, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpacreply_length, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpacreply_reply, tvb, 4, -1, ENC_NA);
}
}
static void
dissect_r3_upstreamcommand_notify (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_mfg (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mfg_tree = NULL;
guint8 mfg_fld;
tvbuff_t *mfg_tvb;
proto_item *mfg_item;
const gchar *cn;
DISSECTOR_ASSERT(start_offset == 0);
mfg_tvb = tvb_new_subset_remaining (tvb, 2);
mfg_fld = tvb_get_guint8 (tvb, 1);
cn = val_to_str_ext_const (mfg_fld, &r3_mfgfieldnames_ext, "[Unknown Mfg Field]");
proto_tree_add_item (tree, hf_r3_mfgfield_length, tvb, 0, 1, ENC_LITTLE_ENDIAN);
mfg_tree = proto_tree_add_subtree_format(tree, tvb, 1, -1, ett_r3commandmfg, &mfg_item,
"Upstream Manufacturing Field: %s (%u)", cn, mfg_fld);
proto_tree_add_item (mfg_tree, hf_r3_mfgfield, tvb, 1, 1, ENC_LITTLE_ENDIAN);
if (mfg_fld >= MFGFIELD_LAST)
{
expert_add_info(pinfo, mfg_item, &ei_r3_mfgfield);
}
else if (r3upstreammfgfield_dissect [mfg_fld])
(*r3upstreammfgfield_dissect [mfg_fld]) (mfg_tvb, 0, length, pinfo, mfg_tree);
}
static void
dissect_r3_upstreamcommand_eventlogwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dumpnvramrle (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_nvramdumprle_record, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdumprle_length, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramdumprle_data, tvb, 4, tvb_get_guint8 (tvb, 3), ENC_NA);
}
static void
dissect_r3_upstreamcommand_rmtdeclinedrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_declinedwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dumpdeclinedlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *declinedlog_tree;
guint8 cred1type;
guint8 cred2type;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
declinedlog_tree = proto_tree_add_subtree_format(tree, tvb, start_offset, 49,
ett_r3declinedlogrecord, NULL, "Declined Log Record %u", tvb_get_letohs (tvb, 0));
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_recordnumber, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_year, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_month, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_day, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_hour, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_minute, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_second, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_usernumber, tvb, 8, 2, ENC_LITTLE_ENDIAN);
cred1type = tvb_get_guint8 (tvb, 10) & 0x07;
cred2type = (tvb_get_guint8 (tvb, 10) & 0x38) >> 3;
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred1type, tvb, 10, 1, cred1type);
proto_tree_add_uint (declinedlog_tree, hf_r3_declinedlog_cred2type, tvb, 10, 1, cred2type);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred1, tvb, 11, 19, ENC_NA);
proto_tree_add_item (declinedlog_tree, hf_r3_declinedlog_cred2, tvb, 30, 19, ENC_NA);
}
static void
dissect_r3_upstreamcommand_rmtalarmrecord (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_alarmwarning (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dumpalarmlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *alarmlog_tree;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
alarmlog_tree = proto_tree_add_subtree_format(tree, tvb, start_offset, 9,
ett_r3alarmlogrecord, NULL, "Alarm Log Record %u", tvb_get_letohs (tvb, 0));
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_recordnumber, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_year, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_month, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_day, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_hour, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_minute, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_second, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_id, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmlog_tree, hf_r3_alarmlog_usernumber, tvb, 9, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_upstreamcommand_connectscheduler (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_connectcommuser (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_commandalarm (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
dissect_r3_upstreamfields (tvb, start_offset, length, pinfo, tree);
}
static void
dissect_r3_upstreamcommand_dumpdebuglog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *debuglog_tree;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
debuglog_tree = proto_tree_add_subtree_format(tree, tvb, start_offset, 8,
ett_r3debuglogrecord, NULL, "Debug Log Record %u", tvb_get_letohs (tvb, 0));
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_recordnumber, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_flags, tvb, 2, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (debuglog_tree, hf_r3_debuglog_tick, tvb, 6, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_upstreammfgfield_iopins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
gint len;
DISSECTOR_ASSERT(start_offset == 0);
len = MAX(0, tvb_length_remaining(tvb, start_offset));
if (len % 3 != 0)
{
expert_add_info_format(pinfo, proto_tree_get_parent (tree), &ei_r3_malformed_length, "IOPINS data length not modulo 3 == 0");
}
else
{
char portname = 'A';
gint i;
if (!tree)
return;
for (i = 0; i < len; i += 3, portname++)
{
proto_tree *port_tree = proto_tree_add_subtree_format(tree, tvb, i, 3, ett_r3iopins, NULL,
"Port %c Configuration", (portname == 'I') ? ++portname : portname);
proto_tree_add_item (port_tree, hf_r3_iopins_lat, tvb, i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (port_tree, hf_r3_iopins_port, tvb, i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (port_tree, hf_r3_iopins_tris, tvb, i + 2, 1, ENC_LITTLE_ENDIAN);
}
}
}
static void
dissect_r3_upstreammfgfield_adcs (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint len;
guint32 i;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
len = tvb_reported_length(tvb);
for (i = 0; i < MIN(len,8); i++)
{
proto_item *item = proto_tree_add_item (tree, hf_r3_adc [i], tvb, i, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text (item, " (%.2f Volts)", (float) tvb_get_guint8 (tvb, i) * 0.04154);
}
if (len > 8)
{
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_mfgfield_too_many_adc_values);
}
}
static void
dissect_r3_upstreammfgfield_hardwareid (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_hardwareid_board, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_hardwareid_cpuid, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_hardwareid_cpurev, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_upstreammfgfield_checkpointlog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *cpl_tree;
guint counter;
gint len;
gint i;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
len = tvb_length_remaining (tvb, 1);
proto_tree_add_item (tree, hf_r3_checkpointlog_entryptr, tvb, 0, 1, ENC_LITTLE_ENDIAN);
cpl_tree = proto_tree_add_subtree(tree, tvb, 1, -1, ett_r3checkpointlog, NULL, "Checkpoint Log");
counter = 0;
for (i = 0; i < len; i += 2, counter++)
{
guint rcon = tvb_get_guint8 (tvb, i + 0);
guint cp = tvb_get_guint8 (tvb, i + 1);
proto_item *cpe_item;
proto_tree *cpe_tree;
guint resettype;
const gchar *desc;
static const gchar *resets [] = { "Stack underflow", "Stack overflow", "Power-On",
"Software", "Brown-out", "MCLR in sleep", "WDT",
"Normal", "[Unknown Reset Type]" };
cpe_tree = proto_tree_add_subtree_format(cpl_tree, tvb, i + 0, 2, ett_r3checkpointlogentry, &cpe_item,
"Checkpoint Log Entry %u", counter);
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
proto_item_append_text (
proto_tree_add_item (cpe_tree, hf_r3_checkpointlog_rcon, tvb, i + 0, 1, ENC_LITTLE_ENDIAN),
" (%s)", resets [resettype]);
proto_item_append_text (
proto_tree_add_item (cpe_tree, hf_r3_checkpointlog_checkpoint, tvb, i + 1, 1, ENC_LITTLE_ENDIAN),
" (%s)", desc);
}
}
static void
dissect_r3_upstreammfgfield_cpuregisters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *tmp_tree [19];
proto_tree *cr_tree;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
cr_tree = proto_tree_add_subtree(tree, tvb, start_offset, -1, ett_r3cpuregisters, NULL, "CPU Registers");
tmp_tree [ 0] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon, tvb, 0, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 1] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon2, tvb, 1, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 2] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_intcon3, tvb, 2, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 3] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir1, tvb, 3, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 4] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir2, tvb, 4, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 5] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pir3, tvb, 5, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 6] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie1, tvb, 6, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 7] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie2, tvb, 7, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 8] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_pie3, tvb, 8, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [ 9] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr1, tvb, 9, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [10] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr2, tvb, 10, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [11] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_ipr3, tvb, 11, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [12] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcon, tvb, 12, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [13] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_osccon, tvb, 13, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [14] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcsta, tvb, 14, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [15] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_txsta, tvb, 15, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [16] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_rcsta2, tvb, 16, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [17] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_txsta2, tvb, 17, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
tmp_tree [18] = proto_item_add_subtree (proto_tree_add_item (cr_tree, hf_r3_cpuregisters_wdtcon, tvb, 18, 1, ENC_LITTLE_ENDIAN), ett_r3cpuregister);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_rbif, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_int0if, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_tmr0if, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_rbie, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_int0ie, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_tmr0ie, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_giel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 0], hf_r3_cpuregisters_intcon_gieh, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_rbip, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_int3ip, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_tmr0ip, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg3, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg2, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg1, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_intedg0, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 1], hf_r3_cpuregisters_intcon2_rbpu, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1if, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2if, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int3if, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1ie, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2ie, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int3ie, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int1ip, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 2], hf_r3_cpuregisters_intcon3_int2ip, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tmr1if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tmr2if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_ccp1if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_ssp1if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_tx1if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_rc1if, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_adif, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 3], hf_r3_cpuregisters_pir1_pspif, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_ccp2if, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_tmr3if, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_hlvdif, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_bcl1if, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_eeif, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_unused5, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_cmif, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 4], hf_r3_cpuregisters_pir2_oscfif, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp3if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp4if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ccp5if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_tmr4if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_tx2if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_rc2if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_bcl2if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 5], hf_r3_cpuregisters_pir3_ssp2if, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tmr1ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tmr2ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_ccp1ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_ssp1ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_tx1ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_rc1ie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_adie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 6], hf_r3_cpuregisters_pie1_pspie, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_oscfie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_cmie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_unused2, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_eeie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_bcl1ie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_hlvdie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_tmr3ie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 7], hf_r3_cpuregisters_pie2_ccp2ie, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp3ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp4ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ccp5ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_tmr4ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_tx2ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_rc2ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_bcl2ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 8], hf_r3_cpuregisters_pie3_ssp2ie, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tmr1ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tmr2ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_ccp1ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_ssp1ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_tx1ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_rc1ip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_adip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [ 9], hf_r3_cpuregisters_ipr1_pspip, tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_ccp2ip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_tmr3ip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_hlvdip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_bcl1ip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_eeip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_unused5, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_cmip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [10], hf_r3_cpuregisters_ipr2_oscfip, tvb, 10, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp2ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp4ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_ccp5ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_tmr4ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_tx2ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_rc2ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_bcl2ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [11], hf_r3_cpuregisters_ipr3_ssp2ip, tvb, 11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_bor, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_por, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_pd, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_to, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_unused4, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_ri, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_sboren, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [12], hf_r3_cpuregisters_rcon_ipen, tvb, 12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_scs0, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_scs1, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_iofs, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_osts, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf0, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf1, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_ircf2, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [13], hf_r3_cpuregisters_osccon_idlen, tvb, 13, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_rx9d, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_oerr, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_ferr, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_adden, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_cren, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_sren, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_rx9, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [14], hf_r3_cpuregisters_rcsta_spen, tvb, 14, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_tx9d, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_trmt, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_brgh, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_sendb, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_sync, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_txen, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_tx9, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [15], hf_r3_cpuregisters_txsta_csrc, tvb, 15, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_rx9d, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_oerr, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_ferr, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_adden, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_cren, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_sren, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_rx9, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [16], hf_r3_cpuregisters_rcsta2_spen, tvb, 16, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_tx9d, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_trmt, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_brgh, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_sendb, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_sync, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_txen, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_tx9, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [17], hf_r3_cpuregisters_txsta2_csrc, tvb, 17, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_swdten, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused1, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused2, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused3, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused4, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused5, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused6, tvb, 18, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree [18], hf_r3_cpuregisters_wdtcon_unused7, tvb, 18, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_upstreammfgfield_taskflags (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint len;
gint i;
proto_tree *tfg_tree;
DISSECTOR_ASSERT(start_offset == 0);
len = MAX(0, tvb_length_remaining (tvb, 0));
tfg_tree = proto_tree_add_subtree_format(tree, tvb, 0, -1, ett_r3taskflags, NULL,
"Task Flags (%u tasks)", len / 5);
for (i = 0; i < len; i += 5)
{
proto_tree *tf_tree = proto_tree_add_subtree_format(tfg_tree, tvb, i, 5,
ett_r3taskflagsentry, NULL,
"Task Flags (%2d: 0x%06x)",
tvb_get_guint8 (tvb, i + 0),
tvb_get_letohl (tvb, i + 1));
proto_tree_add_item (tf_tree, hf_r3_taskflags_taskid, tvb, i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tf_tree, hf_r3_taskflags_flags, tvb, i + 1, 4, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_upstreammfgfield_timerchain (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint len;
gint i;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
len = tvb_length_remaining (tvb, 3);
proto_tree_add_item (tree, hf_r3_timerchain_newtick, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_timerchain_currentboundary, tvb, 2, 1, ENC_LITTLE_ENDIAN);
for (i = 0; i < len; i += 12)
{
proto_tree *tc_tree = proto_tree_add_subtree(tree, tvb, 3 + i, 12, ett_r3timerchain, NULL, "Timer Chain Entry");
proto_tree_add_item (tc_tree, hf_r3_timerchain_tasktag, tvb, 3 + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_address, tvb, 3 + i + 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_reload, tvb, 3 + i + 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_boundary, tvb, 3 + i + 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_count, tvb, 3 + i + 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tc_tree, hf_r3_timerchain_flags, tvb, 3 + i + 8, 4, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_upstreammfgfield_peekpoke (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint i;
gint len;
DISSECTOR_ASSERT(start_offset == 0);
len = tvb_length_remaining (tvb, 0);
for (i = 0; i < len; i += 3)
{
proto_item *peekpoke_item;
proto_item *peekpoke_op_item;
proto_tree *peekpoke_tree;
peekpoke_tree = proto_tree_add_subtree(tree, tvb, i, 3, ett_r3peekpoke, &peekpoke_item, "");
peekpoke_op_item = proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_operation, tvb, i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_address, tvb, i + 1, 2, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, i + 0))
{
case PEEKPOKE_READU8 :
if (peekpoke_tree)
{
proto_item_append_text (peekpoke_item, "Read (8 Bits @ 0x%04x = 0x%02x)",
tvb_get_letohs (tvb, i + 1),
tvb_get_guint8 (tvb, i + 3));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke8, tvb, i + 3, 1, ENC_LITTLE_ENDIAN);
}
i += 1;
break;
case PEEKPOKE_READU16 :
if (peekpoke_tree)
{
proto_item_append_text (peekpoke_item, "Read (16 Bits @ 0x%04x = 0x%04x)",
tvb_get_letohs (tvb, i + 1),
tvb_get_letohs (tvb, i + 3));
proto_item_set_len (peekpoke_item, 5);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke16, tvb, i + 3, 2, ENC_LITTLE_ENDIAN);
}
i += 2;
break;
case PEEKPOKE_READU24 :
if (peekpoke_tree)
{
proto_item_append_text (peekpoke_item, "Read (24 Bits @ 0x%04x = 0x%06x)",
tvb_get_letohs (tvb, i + 1),
tvb_get_letoh24 (tvb, i + 3));
proto_item_set_len (peekpoke_item, 6);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke24, tvb, i + 3, 3, ENC_LITTLE_ENDIAN);
}
i += 3;
break;
case PEEKPOKE_READU32 :
if (peekpoke_tree)
{
proto_item_append_text (peekpoke_item, "Read (32 Bits @ 0x%04x = 0x%08x)",
tvb_get_letohs (tvb, i + 1),
tvb_get_letohl (tvb, i + 3));
proto_item_set_len (peekpoke_item, 7);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke32, tvb, i + 3, 4, ENC_LITTLE_ENDIAN);
}
i += 4;
break;
case PEEKPOKE_READSTRING :
if (peekpoke_tree)
{
proto_item_append_text (peekpoke_item, "Read (%u Bytes @ 0x%04x)",
tvb_get_guint8 (tvb, i + 3),
tvb_get_letohs (tvb, i + 1));
proto_item_set_len (peekpoke_item, 3 + 1 + tvb_get_guint8 (tvb, i + 3));
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, i + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_pokestring, tvb, i + 4, tvb_get_guint8 (tvb, i + 3), ENC_NA);
}
i += tvb_get_guint8 (tvb, i + 3) + 1;
break;
default :
expert_add_info(pinfo, peekpoke_op_item, &ei_r3_peekpoke_operation);
return;
}
}
}
static void
dissect_r3_upstreammfgfield_lockstate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *ls_tree;
guint ls;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
ls = tvb_get_letoh24 (tvb, 0);
ls_tree = proto_tree_add_subtree_format(tree, tvb, 0, -1, ett_r3lockstate, NULL, "Lock State (0x%06x)", ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_passage, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_panic, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_lockout, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_relock, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autoopen, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nextauto, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_lockstate, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_wantstate, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_remote, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_update, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_exceptionspresent, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_exceptionsactive, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_timezonespresent, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_timezonesactive, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autounlockspresent, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_autounlocksactive, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmspresent, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmsactive, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmrelockspresent, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_uapmreslocksactive, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nvramprotect, tvb, 0, 3, ls);
proto_tree_add_boolean (ls_tree, hf_r3_lockstate_nvramchecksum, tvb, 0, 3, ls);
}
static void
dissect_r3_upstreammfgfield_capabilities (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *cf_tree;
gint len;
guint items;
guint octets;
gint i;
guint8 step;
DISSECTOR_ASSERT(start_offset == 0);
len = MAX(0, tvb_length_remaining (tvb, 0));
items = 0;
i = 0;
while (i < len)
{
items++;
octets = tvb_get_guint8 (tvb, i);
if (!octets)
{
proto_tree_add_expert_format(tree, pinfo, &ei_r3_malformed_length, tvb, 0, len, "Capabilities could not be decoded because length of 0 encountered");
return;
}
i += octets;
}
if (!tree)
return;
cf_tree = proto_tree_add_subtree_format(tree, tvb, 0, len, ett_r3capabilities, NULL, "Capabilities (%u items)", items);
i = 0;
while (i<len && (step=tvb_get_guint8(tvb, i))>0)
{
proto_item *tmp_item = proto_tree_add_item (cf_tree, hf_r3_capabilities, tvb, i, tvb_get_guint8 (tvb, i), ENC_NA);
proto_tree *tmp_tree = proto_item_add_subtree (tmp_item, ett_r3capabilities);
const gchar *fn;
fn = val_to_str_ext_const (tvb_get_guint8 (tvb, i + 1), &r3_capabilitiesnames_ext, "[Unknown Field Name]");
proto_item_append_text (tmp_item, " (%s, %u)", fn, tvb_get_letohs (tvb, i + 2));
proto_tree_add_item (tmp_tree, hf_r3_capabilities_length, tvb, i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree, hf_r3_capabilities_type, tvb, i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tmp_tree, hf_r3_capabilities_value, tvb, i + 2, 2, ENC_LITTLE_ENDIAN);
i += step;
}
}
static void
dissect_r3_upstreammfgfield_dumpm41t81 (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
DISSECTOR_ASSERT(start_offset == 0);
if (tvb_length_remaining (tvb, 0) != 20)
{
expert_add_info_format(pinfo, proto_tree_get_parent (tree), &ei_r3_malformed_length, "Length of M41T81 RTC register dump not 20 octets");
}
else
{
proto_tree *rtc_tree;
proto_tree *tmp_tree [20];
guint offset_in_bits;
if (!tree)
return;
rtc_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_r3m41t81registers, NULL, "M41T81 RTC Registers");
tmp_tree [ 0] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg00, tvb, 0, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 1] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg01, tvb, 1, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 2] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg02, tvb, 2, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 3] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg03, tvb, 3, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 4] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg04, tvb, 4, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 5] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg05, tvb, 5, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 6] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg06, tvb, 6, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 7] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg07, tvb, 7, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 8] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg08, tvb, 8, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [ 9] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg09, tvb, 9, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [10] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0a, tvb, 10, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [11] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0b, tvb, 11, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [12] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0c, tvb, 12, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [13] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0d, tvb, 13, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [14] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0e, tvb, 14, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [15] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg0f, tvb, 15, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [16] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg10, tvb, 16, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [17] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg11, tvb, 17, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [18] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg12, tvb, 18, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
tmp_tree [19] = proto_item_add_subtree (proto_tree_add_item (rtc_tree, hf_r3_dumpm41t81_reg13, tvb, 19, 1, ENC_LITTLE_ENDIAN), ett_r3m41t81register);
offset_in_bits = 0 * 8;
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
static void
dissect_r3_upstreammfgfield_nvramchecksumvalue (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_nvramchecksumvalue, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_nvramchecksumvalue_fixup, tvb, 4, 4, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_upstreammfgfield_checksumresults (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
gint len;
DISSECTOR_ASSERT(start_offset == 0);
len = MAX(0, tvb_length_remaining(tvb, 0));
if (len % 3 != 0)
{
expert_add_info_format(pinfo, proto_tree_get_parent (tree), &ei_r3_malformed_length, "Checksum results data length not modulo 3 == 0");
}
else
{
proto_tree *cksum_tree;
guint32 error = FALSE;
gint i;
guint8 step;
if (!tree)
return;
i = 0;
while (i<len && (step=tvb_get_guint8(tvb, i))>0)
{
error |= tvb_get_guint8 (tvb, i + 2);
i += step;
}
cksum_tree = proto_tree_add_subtree_format(tree, tvb, 0, len, ett_r3checksumresults, NULL,
"Checksum Results (%s)", error ? "Error" : "No Errors");
i = 0;
while (i<len && (step=tvb_get_guint8(tvb, i))>0)
{
proto_item *res_item = proto_tree_add_item (cksum_tree, hf_r3_checksumresults,
tvb,
i,
tvb_get_guint8 (tvb, i),
ENC_NA);
proto_tree *res_tree = proto_item_add_subtree (res_item, ett_r3checksumresultsfield);
const gchar *fn;
fn = val_to_str_ext_const (tvb_get_guint8 (tvb, i + 1), &r3_checksumresultnames_ext, "[Unknown Field Name]");
proto_item_append_text (res_item, " %s (%s)", fn, tvb_get_guint8 (tvb, i + 2) ? "Error" : "No Error");
proto_tree_add_item (res_tree, hf_r3_checksumresults_length, tvb, i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (res_tree, hf_r3_checksumresults_field, tvb, i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (res_tree, hf_r3_checksumresults_state, tvb, i + 2, 1, ENC_LITTLE_ENDIAN);
i += step;
}
}
}
static void
dissect_r3_upstreammfgfield_mortisestatelog (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint len;
gint i;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
len = tvb_length_remaining (tvb, 3);
proto_tree_add_item (tree, hf_r3_mortisestatelog_pointer, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mortisestatelog_mortisetype, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mortisestatelog_waiting, tvb, 2, 1, ENC_LITTLE_ENDIAN);
for (i = 0; i < len; i += 3)
{
guint state = tvb_get_guint8 (tvb, 3 + i + 0);
guint last = tvb_get_guint8 (tvb, 3 + i + 1);
guint event = tvb_get_guint8 (tvb, 3 + i + 2);
proto_tree *ms_tree = proto_tree_add_subtree_format(tree, tvb, 3 + i, 3, ett_r3mortisestatelog, NULL,
"State Log Entry %2d (State=0x%02x, Last=0x%02x, Event=%s (0x%02x))",
i / 3,
state,
last,
val_to_str_ext_const (event, &r3_mortiseeventnames_ext, "[Unknown]"),
event);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_state, tvb, 3 + i + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_last, tvb, 3 + i + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (ms_tree, hf_r3_mortisestatelog_event, tvb, 3 + i + 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_upstreammfgfield_mortisepins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *iopins_tree;
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
iopins_tree = proto_tree_add_subtree_format(tree, tvb, 0, 1, ett_r3iopins, NULL,
"Mortise Pin States (0x%02x)", tvb_get_guint8 (tvb, 0));
proto_tree_add_item (iopins_tree, hf_r3_mortisepins_s1, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (iopins_tree, hf_r3_mortisepins_s2, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (iopins_tree, hf_r3_mortisepins_s3, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (iopins_tree, hf_r3_mortisepins_s4, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_upstreammfgfield_keypadchar (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (!tree)
return;
DISSECTOR_ASSERT(start_offset == 0);
proto_item_append_text (
proto_tree_add_item (tree, hf_r3_testkeypad, tvb, 0, 1, ENC_LITTLE_ENDIAN),
" ('%c')", tvb_get_guint8 (tvb, 0));
}
static void
dissect_r3_upstreammfgfield_magcard (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_testmagcard, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
static void
dissect_r3_upstreammfgfield_proxcard (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
DISSECTOR_ASSERT(start_offset == 0);
proto_tree_add_item (tree, hf_r3_testproxcard, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
static void
dissect_r3_response_singlebyte (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_responsetype, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_responsetocommand, tvb, start_offset + 3, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_response_hasdata (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint32 commandPacketLen;
guint8 upstreamCmd;
DISSECTOR_ASSERT(start_offset == 0);
tvb_ensure_bytes_exist (tvb, 0, 4);
commandPacketLen = tvb_get_guint8 (tvb, 0);
upstreamCmd = tvb_get_guint8 (tvb, 3);
if (tvb_get_guint8 (tvb, 1) != CMD_RESPONSE)
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_response_hasdata_octet_1);
else if (tvb_get_guint8 (tvb, 2) != RESPONSETYPE_HASDATA)
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_response_hasdata_octet_2);
else if (upstreamCmd >= UPSTREAMCOMMAND_LAST)
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_response_hasdata_octet_3);
else
{
proto_tree *upstreamcommand_tree = NULL;
tvbuff_t *upstreamcommand_tvb;
if (tree)
{
const gchar *ct;
ct = val_to_str_ext_const (upstreamCmd, &r3_upstreamcommandnames_ext, "[Unknown Command Type]");
proto_tree_add_item (tree, hf_r3_responsetype, tvb, 2, 1, ENC_LITTLE_ENDIAN);
upstreamcommand_tree = proto_tree_add_subtree_format(tree, tvb, 3, -1, ett_r3upstreamcommand, NULL,
"Upstream Command: %s (%u)", ct, upstreamCmd);
proto_tree_add_item (upstreamcommand_tree, hf_r3_upstreamcommand, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
tvb_ensure_bytes_exist (tvb, 0, commandPacketLen - 4);
upstreamcommand_tvb = tvb_new_subset_length (tvb, 4, commandPacketLen - 4);
if (r3upstreamcommand_dissect [upstreamCmd])
(*r3upstreamcommand_dissect [upstreamCmd]) (upstreamcommand_tvb, 0, commandPacketLen - 4, pinfo, upstreamcommand_tree);
}
}
static void
dissect_r3_cmd_response (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *tree)
{
guint8 responseLen = tvb_get_guint8 (tvb, start_offset + 0);
responseType_e responseType = (responseType_e)tvb_get_guint8 (tvb, start_offset + 2);
tvbuff_t *payload_tvb = tvb_new_subset_length (tvb, start_offset, responseLen);
if (tree)
{
const gchar *rt;
rt = val_to_str_ext_const (responseType, &r3_responsetypenames_ext, "[Unknown Response Type]");
proto_item_set_text (proto_tree_get_parent (tree), "Response Packet: %s (%u)", rt, responseType);
proto_tree_add_item (tree, hf_r3_responselength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_responsecommand, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
if (responseType >= RESPONSETYPE_LAST)
{
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_response_hasdata_octet_3);
}
else if (r3response_dissect [responseType])
(*r3response_dissect [responseType]) (payload_tvb, 0, length, pinfo, tree);
}
static void
dissect_r3_cmd_handshake (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_killsession (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_queryserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_queryversion (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_setdatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *dt_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
dt_tree = proto_tree_add_subtree_format (tree, payload_tvb, 0, -1, ett_r3setdatetime, NULL,
"Set Date/Time (%02u/%02u/%02u-%u %02u:%02u:%02u)",
tvb_get_guint8 (payload_tvb, 0),
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2),
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4),
tvb_get_guint8 (payload_tvb, 5),
tvb_get_guint8 (payload_tvb, 6));
proto_tree_add_item (dt_tree, hf_r3_setdate_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_dow, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_hours, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_minutes, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dt_tree, hf_r3_setdate_seconds, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_querydatetime (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_setconfig (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint cmdLen;
tvbuff_t *payload_tvb;
guint32 offset = 0;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
while (offset < (cmdLen - 2))
{
proto_item *sc_item;
proto_tree *sc_tree;
const gchar *ci;
guint8 configItem;
guint8 item_length;
configItem = tvb_get_guint8 (payload_tvb, offset + 1);
ci = val_to_str_ext_const (
configItem,
&r3_configitemnames_ext,
"[Unknown Configuration Item]");
item_length = tvb_get_guint8 (payload_tvb, offset + 0);
sc_tree = proto_tree_add_subtree_format(tree, payload_tvb, offset + 0, item_length,
ett_r3upstreamfield, NULL, "Config Field: %s (%u)", ci, configItem);
sc_item = proto_tree_add_item (sc_tree, hf_r3_configitemlength, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (sc_tree, hf_r3_configitem, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
if (item_length == 0) {
expert_add_info_format(pinfo, sc_item, &ei_r3_malformed_length, "Invalid item length");
return;
}
if (configItem < array_length (configMap))
{
switch (configMap [configItem])
{
case CONFIGTYPE_NONE :
proto_tree_add_item (sc_tree, hf_r3_configitemdata, payload_tvb, offset + 2, item_length - 3, ENC_NA);
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
proto_tree_add_item (sc_tree, hf_r3_configitemdata_string, payload_tvb, offset + 2,
item_length - 2, ENC_ASCII|ENC_NA);
break;
default :
proto_tree_add_none_format (sc_tree, hf_r3_upstreamfielderror, payload_tvb, offset + 2,
item_length - 2, "Unknown Field Type");
break;
}
}
else {
proto_tree_add_text (sc_tree, payload_tvb, offset + 2, item_length - 2, "[Unknown Field Type]");
}
offset += item_length;
}
}
static void
dissect_r3_cmd_getconfig (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *config_item;
proto_tree *config_tree;
guint32 cmdLen;
guint32 i;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
config_item = proto_tree_add_item (tree, hf_r3_configitems, tvb, start_offset + 2, cmdLen - 2, ENC_NA);
config_tree = proto_item_add_subtree (config_item, ett_r3configitem);
for (i = 2; i < cmdLen; i++)
proto_tree_add_item (config_tree, hf_r3_configitem, tvb, start_offset + i, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_manageuser (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint8 cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
tvbuff_t *payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
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
if (tree)
{
const gchar *auptn;
auptn = val_to_str_ext_const (paramType, &r3_adduserparamtypenames_ext, "[Unknown Field]");
mu_tree = proto_item_add_subtree (
proto_tree_add_none_format (tree, hf_r3_adduserparamtype, payload_tvb, offset + 0, paramLength,
"Manage User Field: %s (%u)", auptn, paramType), ett_r3manageuser);
len_field = proto_tree_add_item (mu_tree, hf_r3_adduserparamtypelength, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypetype, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
}
if (paramLength < 2)
{
dataLength = 0;
expert_add_info_format(pinfo, len_field, &ei_r3_malformed_length, "Malformed length value -- all fields are at least 2 octets.");
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
{
expert_add_info_format(pinfo, proto_tree_get_parent (mu_tree), &ei_r3_malformed_length, "Malformed field -- expected 1 octet");
}
else
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_LITTLE_ENDIAN);
break;
case ADDUSERPARAMTYPE_USERNO :
if (dataLength != 2)
{
expert_add_info_format(pinfo, proto_tree_get_parent (mu_tree), &ei_r3_malformed_length, "Malformed field -- expected 2 octets");
}
else
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_LITTLE_ENDIAN);
break;
case ADDUSERPARAMTYPE_PRIMARYFIELD :
case ADDUSERPARAMTYPE_AUXFIELD :
proto_tree_add_item (mu_tree, hf_r3_adduserparamtypearray [paramType], payload_tvb, offset, dataLength, ENC_NA);
break;
case ADDUSERPARAMTYPE_EXPIREON :
{
if (dataLength != 3)
{
expert_add_info_format(pinfo, proto_tree_get_parent (mu_tree), &ei_r3_malformed_length, "Malformed expiration field -- expected 3 octets");
}
else
{
proto_tree *expireon_tree;
if (!tree)
break;
expireon_tree = proto_tree_add_subtree_format(mu_tree, payload_tvb, offset, 3,
ett_r3expireon, NULL,
"Expire YY/MM/DD: %02u/%02u/%02u",
tvb_get_guint8 (payload_tvb, offset + 2),
tvb_get_guint8 (payload_tvb, offset + 0),
tvb_get_guint8 (payload_tvb, offset + 1));
proto_tree_add_item (expireon_tree, hf_r3_expireon_month, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_day, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (expireon_tree, hf_r3_expireon_year, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
break;
case ADDUSERPARAMTYPE_TIMEZONE :
{
if (dataLength != 4)
{
expert_add_info_format(pinfo, proto_tree_get_parent (mu_tree), &ei_r3_malformed_length, "Malformed timezone field -- expected 4 octets");
}
else
{
proto_item *timezone_item;
proto_tree *timezone_tree;
guint32 i;
guint32 tz;
if (!tree)
break;
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
static void
dissect_r3_cmd_deleteusers (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_deleteusers, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_defineexception (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *startdate_tree;
proto_tree *enddate_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_defineexception_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
startdate_tree = proto_tree_add_subtree_format(tree, payload_tvb, 1, 4,
ett_r3defineexceptionstartdate, NULL,
"Start MM/DD HH:MM (%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2),
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4));
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (startdate_tree, hf_r3_defineexception_startdate_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
enddate_tree = proto_tree_add_subtree_format(tree, payload_tvb, 5, 4,
ett_r3defineexceptionenddate, NULL,
"End MM/DD HH:MM (%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 5),
tvb_get_guint8 (payload_tvb, 6),
tvb_get_guint8 (payload_tvb, 7),
tvb_get_guint8 (payload_tvb, 8));
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_month, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_day, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_hours, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (enddate_tree, hf_r3_defineexception_enddate_minutes, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_defineexceptiongroup (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *bits_tree;
guint cmdLen;
tvbuff_t *payload_tvb;
guint32 i;
guint32 bit = 0;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_defineexceptiongroup_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
bits_tree = proto_tree_add_subtree(tree, payload_tvb, 1, -1, ett_r3defineexceptiongroupbits, NULL, "Exception Group Bit Field");
for (i = 1; i < (cmdLen - 2); i++)
{
guint32 j;
guint8 byte = tvb_get_guint8 (payload_tvb, i);
for (j = 0; j < 8; j++)
proto_tree_add_none_format (bits_tree, hf_r3_defineexceptiongroup_bits, payload_tvb, i, 1,
"Exception Group %2d: %s", bit++, (byte & (1 << j)) ? "Enabled" : "Disabled");
}
}
static void
dissect_r3_cmd_definecalendar (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
const gchar *mn;
guint32 i;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_definecalendar_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
for (i = 0; i < 12; i++)
{
guint32 daymap = tvb_get_letohl (payload_tvb, (i * 4) + 1);
proto_tree *calendar_tree = proto_tree_add_subtree_format(tree, payload_tvb, (i * 4) + 1, 4,
ett_r3definecalendarmonth [i + 1], NULL,
"Calendar Bit Field - %s (0x%08x)",
(mn = val_to_str_ext_const (i + 1, &r3_monthnames_ext, "[Unknown Month]")),
daymap);
guint32 j;
for (j = 0; j < 31; j++)
proto_tree_add_none_format (calendar_tree, hf_r3_definecalendar_bits, payload_tvb, (i * 4) + 1, 4,
"%s Of %s: %s",
val_to_str_ext_const (j + 1, &r3_monthdaynames_ext, "[Unknown Day]"),
mn,
(daymap & (1 << j)) ? "Enabled" : "Disabled");
}
}
static void
dissect_r3_cmd_definetimezone (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *starttime_tree;
proto_tree *endtime_tree;
proto_tree *daymap_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
guint32 i;
guint8 tzmode;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_definetimezone_number, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
starttime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 1, 2,
ett_r3definetimezonestarttime, NULL,
"Start HH:MM (%02u:%02u)",
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2));
proto_tree_add_item (starttime_tree, hf_r3_definetimezone_starttime_hours, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_definetimezone_starttime_minutes, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
endtime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 3, 2,
ett_r3definetimezoneendtime, NULL,
"End HH:MM (%02u:%02u)",
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4));
proto_tree_add_item (endtime_tree, hf_r3_definetimezone_endtime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_definetimezone_endtime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
daymap_tree = proto_tree_add_subtree_format(tree, payload_tvb, 5, 1, ett_r3definetimezonedaymap, NULL,
"Day Map (0x%02x)", tvb_get_guint8 (payload_tvb, 5));
for (i = 0; i < 7; i++)
proto_tree_add_boolean (daymap_tree, hf_r3_definetimezone_daymap [i], payload_tvb, 5, 1,
tvb_get_guint8 (payload_tvb, 5));
proto_tree_add_item (tree, hf_r3_definetimezone_exceptiongroup, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint (tree, hf_r3_definetimezone_mode, payload_tvb, 7, 1,
(tzmode = tvb_get_guint8 (payload_tvb, 7)) & 0x0f);
proto_tree_add_none_format (tree, hf_r3_definetimezone_calendar, payload_tvb, 7, 1,
"Access Always: %s", (tzmode & 0x10) ? "True" : "False");
}
static void
dissect_r3_cmd_rmtauthretry (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_rmtauthretry_sequence, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_rmtauthretry_retry, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_filters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *filter_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
guint32 i;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_filter_type, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
filter_tree = proto_tree_add_subtree_format(tree, payload_tvb, 2, -1, ett_r3filters, NULL,
"Filters (%u specified)", tvb_get_guint8 (payload_tvb, 0));
for (i = 0; i < tvb_get_guint8 (payload_tvb, 0); i++)
proto_tree_add_item (filter_tree, hf_r3_filter_list, payload_tvb, i + 2, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_alarmconfigure (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
proto_item *alarm_item;
proto_tree *alarm_tree;
guint cmdLen;
tvbuff_t *payload_tvb;
guint32 offset = 0;
guint32 alarms = 0;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
alarm_tree = proto_tree_add_subtree(tree, payload_tvb, 0, -1, ett_r3alarmlist, &alarm_item, "Alarm List (0 items)");
while (offset < (cmdLen - 2))
{
proto_item *pi;
proto_tree *alarmcfg_tree;
const gchar *ai;
const gchar *as;
guint32 alarm_len;
if (!(ai = try_val_to_str_ext (tvb_get_guint8 (payload_tvb, offset + 1), &r3_alarmidnames_ext)))
{
ai = "[Unknown Alarm ID]";
as = "N/A";
}
else
as = (tvb_get_guint8 (payload_tvb, offset + 2) & 0xfe) ?
"Error" : (tvb_get_guint8 (payload_tvb, offset + 2) & 0x01) ? "Enabled" : "Disabled";
alarmcfg_tree = proto_tree_add_subtree_format(alarm_tree, payload_tvb, offset, tvb_get_guint8 (payload_tvb, offset),
ett_r3alarmcfg, NULL, "Alarm Item (%s, %s)", ai, as);
alarm_len = tvb_get_guint8 (payload_tvb, offset + 0);
pi = proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_length, payload_tvb, offset + 0, 1, ENC_LITTLE_ENDIAN);
if (alarm_len == 0) {
expert_add_info_format (pinfo, pi, &ei_r3_malformed_length,
"Alarm length equal to 0. Payload could be partially decoded");
break;
}
proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_id, payload_tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (alarmcfg_tree, hf_r3_alarm_state, payload_tvb, offset + 2, 1, ENC_LITTLE_ENDIAN);
alarms++;
offset += alarm_len;
}
if (alarms)
proto_item_set_text (alarm_item, "Alarm List (%d items)", alarms);
}
static void
dissect_r3_cmd_eventlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *starttime_tree;
proto_tree *endtime_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 0, 5,
ett_r3eventlogdumpstarttime, NULL,
"Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 0),
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2),
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4));
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_eventlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 5, 5,
ett_r3eventlogdumpendtime, NULL,
"End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 5),
tvb_get_guint8 (payload_tvb, 6),
tvb_get_guint8 (payload_tvb, 7),
tvb_get_guint8 (payload_tvb, 8),
tvb_get_guint8 (payload_tvb, 9));
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_eventlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_eventlogdump_user, payload_tvb, 10, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_declinedlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *starttime_tree;
proto_tree *endtime_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 0, 5,
ett_r3declinedlogdumpstarttime, NULL,
"Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 0),
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2),
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4));
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_declinedlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 5, 5,
ett_r3declinedlogdumpendtime, NULL,
"End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 5),
tvb_get_guint8 (payload_tvb, 6),
tvb_get_guint8 (payload_tvb, 7),
tvb_get_guint8 (payload_tvb, 8),
tvb_get_guint8 (payload_tvb, 9));
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_declinedlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_alarmlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *starttime_tree;
proto_tree *endtime_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
starttime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 0, 5,
ett_r3alarmlogdumpstarttime, NULL,
"Start YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 0),
tvb_get_guint8 (payload_tvb, 1),
tvb_get_guint8 (payload_tvb, 2),
tvb_get_guint8 (payload_tvb, 3),
tvb_get_guint8 (payload_tvb, 4));
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_year, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_month, payload_tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_day, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_hours, payload_tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (starttime_tree, hf_r3_alarmlogdump_starttime_minutes, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
endtime_tree = proto_tree_add_subtree_format(tree, payload_tvb, 5, 5,
ett_r3alarmlogdumpendtime, NULL,
"End YY/MM/DD HH:MM (%02u/%02u/%02u %02u:%02u)",
tvb_get_guint8 (payload_tvb, 5),
tvb_get_guint8 (payload_tvb, 6),
tvb_get_guint8 (payload_tvb, 7),
tvb_get_guint8 (payload_tvb, 8),
tvb_get_guint8 (payload_tvb, 9));
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_year, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_month, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_day, payload_tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_hours, payload_tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (endtime_tree, hf_r3_alarmlogdump_endtime_minutes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_downloadfirmware (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *dlfw_item = NULL;
proto_item *dlfw_action_item = NULL;
proto_tree *dlfw_tree = NULL;
guint8 cmdLen;
tvbuff_t *payload_tvb;
guint32 packetCRC;
guint32 calculatedCRC;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
dlfw_tree = proto_tree_add_subtree_format(tree, payload_tvb, 0, -1, ett_r3downloadfirmware, &dlfw_item,
"Download Record (Record #%u, ", tvb_get_letohs (payload_tvb, 2));
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_length, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_record, payload_tvb, 2, 2, ENC_LITTLE_ENDIAN);
dlfw_action_item = proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_action, payload_tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
switch (tvb_get_guint8 (payload_tvb, 4))
{
case DOWNLOADFIRMWARE_START :
if (!dlfw_tree)
break;
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_START)");
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_timeout, payload_tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_nvram, payload_tvb, 6, 1, ENC_LITTLE_ENDIAN);
break;
case DOWNLOADFIRMWARE_DATA :
if (!dlfw_tree)
break;
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_DATA, Address 0x%08x, %u Bytes)",
tvb_get_letohl (payload_tvb, 5), tvb_get_guint8 (payload_tvb, 9));
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_address, payload_tvb, 5, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_bytes, payload_tvb, 9, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (dlfw_tree, hf_r3_firmwaredownload_data, payload_tvb, 10,
tvb_get_guint8 (payload_tvb, 9), ENC_NA);
break;
case DOWNLOADFIRMWARE_COMPLETE :
if (!dlfw_tree)
break;
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_COMPLETE)");
break;
case DOWNLOADFIRMWARE_ABORT :
if (!dlfw_tree)
break;
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_ABORT)");
break;
case DOWNLOADFIRMWARE_RESET :
if (!dlfw_tree)
break;
proto_item_append_text (dlfw_item, "DOWNLOADFIRMWARE_RESET)");
break;
default :
expert_add_info(pinfo, dlfw_action_item, &ei_r3_firmwaredownload_action);
return;
}
if (!dlfw_tree)
return;
packetCRC = tvb_get_letohs (payload_tvb, cmdLen - 2 - 2);
if ((calculatedCRC = utilCrcCalculate (tvb_get_ptr (payload_tvb, 0, cmdLen - 2 - 2),
cmdLen - 2,
0x0000))
== packetCRC)
proto_tree_add_uint_format_value(dlfw_tree, hf_r3_firmwaredownload_crc, payload_tvb,
cmdLen - 2 - 2, 2,
packetCRC, "0x%04x (correct)", packetCRC);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format_value(dlfw_tree, hf_r3_firmwaredownload_crc, payload_tvb,
cmdLen - 2 - 2, 2,
packetCRC, "0x%04x (incorrect, should be 0x%04x)", calculatedCRC, packetCRC);
tmp_item = proto_tree_add_boolean (dlfw_tree, hf_r3_firmwaredownload_crc_bad, payload_tvb,
cmdLen - 2 - 2, 2, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
}
static void
dissect_r3_cmd_downloadfirmwaretimeout (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (tree)
{
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commanddata, payload_tvb, 0, -1, ENC_NA);
}
expert_add_info(pinfo, proto_tree_get_parent (tree), &ei_r3_cmd_downloadfirmwaretimeout);
}
static void
dissect_r3_cmd_powertableselection (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_powertableselection, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_clearnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *nvram_tree;
guint8 cmdLen;
tvbuff_t *payload_tvb;
guint32 nvramclearoptions;
guint32 i;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
nvramclearoptions = tvb_get_letohs (payload_tvb, 0);
nvram_tree = proto_tree_add_subtree_format(tree, payload_tvb, 0, 2, ett_r3clearnvram, NULL,
"NVRAM Clean Options (0x%04x)", nvramclearoptions);
for (i = 0; i < 16; i++)
proto_tree_add_boolean (nvram_tree, hf_r3_nvramclearoptions [i], payload_tvb, 0, 2, nvramclearoptions);
}
static void
dissect_r3_cmd_dpac (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_action, payload_tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_waittime, payload_tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_dpac_command, payload_tvb, 3, -1, ENC_NA);
}
static void
dissect_r3_cmd_selftest (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_reset (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_logwrite (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
guint8 cmdLen;
tvbuff_t *payload_tvb;
if (!tree)
return;
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
payload_tvb = tvb_new_subset_length (tvb, start_offset + 2, cmdLen - 2);
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_writeeventlog_user, payload_tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_writeeventlog_event, payload_tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmd_mfgcommand (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
mfgCommandFlag = TRUE;
}
static void
dissect_r3_cmd_nvrambackup (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmd_extendedresponse (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandlength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_command, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_setserialnumber (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
tvbuff_t *sn_tvb = tvb_new_subset_length (tvb, start_offset + 2, 16);
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
dissect_serialnumber (sn_tvb, 0, length, pinfo, tree, hf_r3_mfgsetserialnumber);
}
static void
dissect_r3_cmdmfg_setcryptkey (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgsetcryptkey, tvb, start_offset + 2, -1, ENC_NA);
}
}
static void
dissect_r3_cmdmfg_dumpnvram (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgdumpnvram, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_terminal (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_remoteunlock (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgremoteunlock, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_auxctlrversion (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_iopins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_adcs (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_hardwareid (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_checkpointlogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_checkpointlogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_readregisters (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_forceoptions (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint i;
gint len;
guint8 step;
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
start_offset += 2;
len = tvb_length_remaining (tvb, start_offset);
i = 0;
while (i<len && (step=tvb_get_guint8(tvb, start_offset + i))>0)
{
proto_tree *force_tree = proto_tree_add_subtree_format(tree, tvb, start_offset + i, tvb_get_guint8 (tvb, start_offset + i),
ett_r3forceoptions, NULL,
"Force Option %s (%u)",
val_to_str_ext_const (
tvb_get_guint8 (tvb, start_offset + i + 1),
&r3_forceitemnames_ext, "[Unknown]"),
tvb_get_guint8 (tvb, start_offset + i + 1));
proto_item *force_item_item;
proto_tree_add_item (force_tree, hf_r3_forceoptions_length, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
force_item_item = proto_tree_add_item (force_tree, hf_r3_forceoptions_item, tvb, start_offset + i + 1, 1, ENC_LITTLE_ENDIAN);
switch (tvb_get_guint8 (tvb, start_offset + i) - 2)
{
case 1 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_8, tvb, start_offset + i + 2, 1, ENC_LITTLE_ENDIAN);
break;
case 2 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_16, tvb, start_offset + i + 2, 2, ENC_LITTLE_ENDIAN);
break;
case 3 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_24, tvb, start_offset + i + 2, 3, ENC_LITTLE_ENDIAN);
break;
case 4 : proto_tree_add_item (force_tree, hf_r3_forceoptions_state_32, tvb, start_offset + i + 2, 4, ENC_LITTLE_ENDIAN);
break;
default :
expert_add_info_format(pinfo, force_item_item, &ei_r3_malformed_length, "Invalid length for Forceoptions State entry");
return;
break;
}
i += step;
}
}
static void
dissect_r3_cmdmfg_commuser (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_dumpkeypad (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_batterycheck (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_ramrefresh (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_taskflags (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_timerchain (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
if (tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_r3_cmdmfg_peekpoke (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
gint i;
gint len;
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
start_offset += 2;
len = tvb_length_remaining (tvb, start_offset);
for (i = 0; i < len; i += 3)
{
proto_item *peekpoke_item;
proto_item *peekpoke_op_item;
proto_tree *peekpoke_tree;
peekpoke_tree = proto_tree_add_subtree(tree, tvb, start_offset + i, 3, ett_r3peekpoke, &peekpoke_item, "");
peekpoke_op_item = proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_operation, tvb, start_offset + i + 0, 1, ENC_LITTLE_ENDIAN);
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
proto_item_append_text (peekpoke_item,
"Read (%d Bytes @ 0x%04x)",
tvb_get_guint8 (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
i += 1;
break;
case PEEKPOKE_WRITEU8 :
proto_item_append_text (peekpoke_item,
"Write (8 Bits: 0x%02x @ 0x%04x)",
tvb_get_guint8 (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 4);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke8, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
i += 1;
break;
case PEEKPOKE_WRITEU16 :
proto_item_append_text (peekpoke_item,
"Write (16 Bits: 0x%04x @ 0x%04x)",
tvb_get_letohs (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 5);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke16, tvb, start_offset + i + 3, 2, ENC_LITTLE_ENDIAN);
i += 2;
break;
case PEEKPOKE_WRITEU24 :
proto_item_append_text (peekpoke_item,
"Write (24 Bits: 0x%06x @ 0x%04x)",
tvb_get_letoh24 (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 6);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke24, tvb, start_offset + i + 3, 3, ENC_LITTLE_ENDIAN);
i += 3;
break;
case PEEKPOKE_WRITEU32 :
proto_item_append_text (peekpoke_item,
"Write (32 Bits: 0x%08x @ 0x%04x)",
tvb_get_letohl (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 7);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_poke32, tvb, start_offset + i + 3, 4, ENC_LITTLE_ENDIAN);
i += 4;
break;
case PEEKPOKE_WRITESTRING :
proto_item_append_text (peekpoke_item,
"Write (%d Bytes @ 0x%04x)",
tvb_get_guint8 (tvb, start_offset + i + 3),
tvb_get_letohs (tvb, start_offset + i + 1));
proto_item_set_len (peekpoke_item, 3 + 1 + tvb_get_guint8 (tvb, start_offset + i + 3));
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_length, tvb, start_offset + i + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (peekpoke_tree, hf_r3_peekpoke_pokestring, tvb, start_offset + i + 4,
tvb_get_guint8 (tvb, start_offset + i + 3), ENC_NA);
i += tvb_get_guint8 (tvb, start_offset + i + 3) + 1;
break;
default :
expert_add_info_format(pinfo, peekpoke_op_item, &ei_r3_peekpoke_operation, "Unknown Mfg peekpoke operation value");
return;
}
}
}
static void
dissect_r3_cmdmfg_lockstate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_capabilities (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_dumpm41t81 (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_debuglogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_debuglogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_testwdt (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_querycksum (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_validatechecksums (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_rebuildlrucache (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_tzupdate (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_testpreserve (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_mfgtestpreserve, tvb, start_offset + 2, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_mortisestatelogdump (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_mortisestatelogclear (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_mortisepins (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_r3_cmdmfg_haltandcatchfire (tvbuff_t *tvb, guint32 start_offset, guint32 length _U_, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item (tree, hf_r3_commandmfglength, tvb, start_offset + 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (tree, hf_r3_commandmfg, tvb, start_offset + 1, 1, ENC_LITTLE_ENDIAN);
}
static gint
dissect_r3_command (tvbuff_t *tvb, guint32 start_offset, guint32 length, packet_info *pinfo, proto_tree *r3_tree)
{
proto_item *cmd_item;
proto_tree *cmd_tree;
const gchar *cn;
guint8 cmdLen;
guint8 cmd;
tvb_ensure_bytes_exist (tvb, start_offset, 2);
cmdLen = tvb_get_guint8 (tvb, start_offset + 0);
cmd = tvb_get_guint8 (tvb, start_offset + 1);
if (!mfgCommandFlag)
cn = val_to_str_ext_const (cmd, &r3_cmdnames_ext, "[Unknown Command]");
else
cn = val_to_str_ext_const (cmd, &r3_cmdmfgnames_ext, "[Unknown Mfg Command]");
cmd_tree = proto_tree_add_subtree_format(r3_tree, tvb, start_offset, cmdLen,
ett_r3cmd, &cmd_item, "Command Packet: %s (%d)", cn, cmd);
if (!mfgCommandFlag)
{
if (cmd >= CMD_LAST)
expert_add_info(pinfo, cmd_item, &ei_r3_unknown_command_value);
else if (r3command_dissect [cmd])
(*r3command_dissect [cmd]) (tvb, start_offset, length, pinfo, cmd_tree);
}
else
{
mfgCommandFlag = FALSE;
if (cmd >= CMDMFG_LAST)
{
expert_add_info_format(pinfo, proto_tree_get_parent (cmd_tree), &ei_r3_unknown_command_value, "Unknown manufacturing command value");
}
else if (r3commandmfg_dissect [cmd])
(*r3commandmfg_dissect [cmd]) (tvb, start_offset, length, pinfo, cmd_tree);
}
return tvb_get_guint8 (tvb, start_offset + 0);
}
static int
dissect_r3_packet (tvbuff_t *tvb, packet_info *pinfo, proto_tree *r3_tree)
{
proto_item *payload_item = NULL;
proto_tree *payload_tree = NULL;
guint offset = 0;
guint32 packetLen;
guint octConsumed;
if (tvb_strneql (tvb, 0, "~~~ds", 5) == 0)
{
if (r3_tree)
proto_tree_add_item (r3_tree, hf_r3_tildex3ds, tvb, 0, -1, ENC_ASCII|ENC_NA);
return 5;
}
if (r3_tree)
{
proto_item *header_item = proto_tree_add_item (r3_tree, hf_r3_header, tvb, 0, 5, ENC_NA);
proto_tree *header_tree = proto_item_add_subtree (header_item, ett_r3header);
proto_tree_add_item (header_tree, hf_r3_sigil, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_address, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_packetnumber, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_packetlength, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item (header_tree, hf_r3_encryption, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
packetLen = tvb_get_guint8 (tvb, 3);
if (r3_tree)
{
payload_item = proto_tree_add_item (r3_tree, hf_r3_payload, tvb, 5, -1, ENC_NA);
payload_tree = proto_item_add_subtree (payload_item, ett_r3payload);
}
offset = 5;
mfgCommandFlag = FALSE;
while (offset < (packetLen - 3))
{
octConsumed = dissect_r3_command (tvb, offset, 0, pinfo, payload_tree);
if(octConsumed == 0)
{
expert_add_info_format(pinfo, proto_tree_get_parent (payload_tree), &ei_r3_malformed_length,
"Command length equal to 0. Payload could be partially decoded");
offset = tvb_reported_length (tvb) - 3;
break;
}
offset += octConsumed;
}
if (r3_tree)
{
proto_item *tail_item = proto_tree_add_item (r3_tree, hf_r3_tail, tvb, offset, 3, ENC_NA);
proto_tree *tail_tree = proto_item_add_subtree (tail_item, ett_r3tail);
guint32 packetCRC = tvb_get_letohs (tvb, offset);
guint32 packetXor = tvb_get_guint8 (tvb, offset + 2);
guint32 calculatedCRC;
if ((calculatedCRC = utilCrcCalculate (tvb_get_ptr (tvb, 1, packetLen - 3), packetLen - 3, 0x0000)) == packetCRC)
proto_tree_add_uint_format_value(tail_tree, hf_r3_crc, tvb, offset, 2, packetCRC, "0x%04x (correct)", packetCRC);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format_value(tail_tree, hf_r3_crc, tvb, offset, 2, packetCRC,
"0x%04x (incorrect, should be 0x%04x)", calculatedCRC, packetCRC);
tmp_item = proto_tree_add_boolean (tail_tree, hf_r3_crc_bad, tvb, offset, 2, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
if ((packetLen ^ 0xff) == packetXor)
proto_tree_add_uint_format_value(tail_tree, hf_r3_xor, tvb, offset + 2, 1, packetXor,
"0x%02x (correct)", packetXor);
else
{
proto_item *tmp_item;
proto_tree_add_uint_format_value(tail_tree, hf_r3_xor, tvb, offset + 7, 1, packetXor,
"0x%02x (incorrect, should be 0x%02x)", packetXor, packetLen ^ 0xff);
tmp_item = proto_tree_add_boolean (tail_tree, hf_r3_xor_bad, tvb, offset + 7, 1, TRUE);
PROTO_ITEM_SET_GENERATED (tmp_item);
}
}
offset += 3;
return offset;
}
static int
dissect_r3_message (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *r3_tree = NULL;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "R3");
col_clear (pinfo->cinfo, COL_INFO);
if (tree)
{
proto_item *r3_item;
r3_item = proto_tree_add_item (tree, proto_r3, tvb, 0, -1, ENC_NA);
r3_tree = proto_item_add_subtree (r3_item, ett_r3);
}
dissect_r3_packet (tvb, pinfo, r3_tree);
return tvb_length(tvb);
}
static guint
get_r3_message_len (packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return (guint) tvb_get_guint8 (tvb, offset + 3) + 1;
}
static int
dissect_r3 (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus (tvb, pinfo, tree, TRUE, 4, get_r3_message_len, dissect_r3_message, data);
return tvb_length(tvb);
}
void proto_register_r3 (void)
{
static hf_register_info hf [] =
{
{ &hf_r3_tildex3ds,
{ "DPAC Attention", "r3.dpac_attention",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_header,
{ "Header", "r3.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_payload,
{ "Payload", "r3.payload",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_tail,
{ "Tail", "r3.tail",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_sigil,
{ "Sigil", "r3.sigil",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_address,
{ "Address", "r3.address",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_packetnumber,
{ "Packet Number", "r3.packetnumber",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_packetlength,
{ "Packet Length", "r3.packetlength",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_encryption,
{ "Crypt Type", "r3.encryption",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_encryptionschemenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_crc,
{ "CRC", "r3.crc",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_crc_bad,
{ "Bad CRC", "r3.crc_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_xor,
{ "XOR", "r3.xor",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_xor_bad,
{ "Bad XOR", "r3.xor_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_commandlength,
{ "Command Length", "r3.command.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_command,
{ "Command", "r3.command.command",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_cmdnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_commanddata,
{ "Command Data", "r3.command.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_commandmfglength,
{ "Mfg Command Length", "r3.commandmfg.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_commandmfg,
{ "Mfg Command", "r3.commandmfg.command",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_cmdmfgnames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_commandmfgdata,
{ "Mfg Command Data", "r3.commandmfg.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_responselength,
{ "Response Length", "r3.response.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_responsecommand,
{ "Response Command", "r3.response.command",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_cmdnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_responsetype,
{ "Response Type", "r3.response.responsetype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_responsetypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_responsetocommand,
{ "Response To Command", "r3.response.to_command",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_cmdnames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_responsedata,
{ "Response Data", "r3.response.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_upstreamcommand,
{ "Upstream Command", "r3.upstreamcommand.command",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_upstreamcommandnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfield,
{ "Upstream Field", "r3.upstreamfield",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldlength,
{ "Field Length", "r3.upstreamfield.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldtype,
{ "Field Type", "r3.upstreamfield.type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_upstreamfieldnames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_upstreamfielddatalen,
{ "Data Length", "r3.upstreamfield.datalen",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_upstreamfielderror,
{ "Error", "r3.upstreamfield.error",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_SERIALNUMBER],
{ "Serial Number", "r3.upstreamfield.serialnumber",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_NAR],
{ "Next Available Record", "r3.upstreamfield.nar",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_ENTRYDEVICE],
{ "Entry Device", "r3.upstreamfield.entrydevice",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_PPMIFIELDTYPE],
{ "PPMI Field Type", "r3.upstreamfield.ppmifieldtype",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_PIN],
{ "PIN", "r3.upstreamfield.pin",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_SEQUENCENUMBER],
{ "Sequence Number", "r3.upstreamfield.sequencenumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_RESPONSEWINDOW],
{ "Response Window", "r3.upstreamfield.responsewindow",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_USERNUMBER],
{ "User Number", "r3.upstreamfield.usernumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_VERSION],
{ "Version", "r3.upstreamfield.version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_EVENTLOGRECORD],
{ "Event Log Record", "r3.upstreamfield.eventlogrecord",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_DATETIME],
{ "Date/Time", "r3.upstreamfield.datetime",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_EVENTLOGRECORDCOUNT],
{ "Event Log Record Count", "r3.upstreamfield.eventlogrecordcount",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_DECLINEDRECORDCOUNT],
{ "Declined Log Record", "r3.upstreamfield.declinedlogrecord",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_DECLINEDRECORD],
{ "Declined Log", "r3.upstreamfield.declinedlog",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_USERTYPE],
{ "User Type", "r3.upstreamfield.usertype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_usertypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_ACCESSALWAYS],
{ "Access Always", "r3.upstreamfield.accessalways",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_CACHED],
{ "Cached", "r3.upstreamfield.cached",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_PRIMARYFIELDTYPE],
{ "Primary Field Type", "r3.upstreamfield.primaryfieldtype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_AUXFIELDTYPE],
{ "Aux Field Type", "r3.upstreamfield.auxfieldtype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_ACCESSMODE],
{ "Access Mode", "r3.upstreamfield.accessmode",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_accessmodenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_EXPIREON],
{ "Expire On", "r3.upstreamfield.expireon",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_USECOUNT],
{ "Use Count", "r3.upstreamfield.usecount",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_TIMEZONE],
{ "Timezone", "r3.upstreamfield.timezone",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_EXCEPTIONGROUP],
{ "Exception Group", "r3.upstreamfield.exceptiongroup",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_PRIMARYPIN],
{ "Primary PIN", "r3.upstreamfield.primarypin",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_AUXPIN],
{ "Aux PIN", "r3.upstreamfield.auxpin",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_ALARMRECORDCOUNT],
{ "Alarm Record Count", "r3.upstreamfield.alarmrecordcount",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_ALARMRECORD],
{ "Alarm Record", "r3.upstreamfield.alarmrecord",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_upstreamfieldarray [UPSTREAMFIELD_AUXCTLRVERSION],
{ "Aux Controller Version", "r3.upstreamfield.auxctlrversion",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitems,
{ "Configuration Item List", "r3.configitems",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitem,
{ "Configuration Item", "r3.configitem",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_configitemnames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_configfield,
{ "Config Field", "r3.configfield",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_configitemlength,
{ "Configuration Item Length", "r3.configitem.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemtype,
{ "Configuration Item Type", "r3.configitem.type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_configtypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata,
{ "Configuration Item Data", "r3.configitem.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata_bool,
{ "Configuration Item Boolean", "r3.configitem.data_boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata_8,
{ "Configuration Item 8-bit", "r3.configitem.data_8",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata_16,
{ "Configuration Item 16-bit", "r3.configitem.data_16",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata_32,
{ "Configuration Item 32-bit", "r3.configitem.data_32",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_configitemdata_string,
{ "Configuration Item String", "r3.configitem.data_string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 0],
{ "Timezone 0", "r3.timezone.0",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000001,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 1],
{ "Timezone 1", "r3.timezone.1",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000002,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 2],
{ "Timezone 2", "r3.timezone.2",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000004,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 3],
{ "Timezone 3", "r3.timezone.3",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000008,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 4],
{ "Timezone 4", "r3.timezone.4",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000010,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 5],
{ "Timezone 5", "r3.timezone.5",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000020,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 6],
{ "Timezone 6", "r3.timezone.6",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000040,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 7],
{ "Timezone 7", "r3.timezone.7",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000080,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 8],
{ "Timezone 8", "r3.timezone.8",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000100,
NULL, HFILL }
},
{ &hf_r3_timezonearray [ 9],
{ "Timezone 9", "r3.timezone.9",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000200,
NULL, HFILL }
},
{ &hf_r3_timezonearray [10],
{ "Timezone 10", "r3.timezone.10",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000400,
NULL, HFILL }
},
{ &hf_r3_timezonearray [11],
{ "Timezone 11", "r3.timezone.11",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00000800,
NULL, HFILL }
},
{ &hf_r3_timezonearray [12],
{ "Timezone 12", "r3.timezone.12",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00001000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [13],
{ "Timezone 13", "r3.timezone.13",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00002000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [14],
{ "Timezone 14", "r3.timezone.14",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00004000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [15],
{ "Timezone 15", "r3.timezone.15",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00008000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [16],
{ "Timezone 16", "r3.timezone.16",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00010000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [17],
{ "Timezone 17", "r3.timezone.17",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00020000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [18],
{ "Timezone 18", "r3.timezone.18",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00040000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [19],
{ "Timezone 19", "r3.timezone.19",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00080000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [20],
{ "Timezone 20", "r3.timezone.20",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00100000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [21],
{ "Timezone 21", "r3.timezone.21",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00200000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [22],
{ "Timezone 22", "r3.timezone.22",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00400000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [23],
{ "Timezone 23", "r3.timezone.23",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x00800000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [24],
{ "Timezone 24", "r3.timezone.24",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x01000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [25],
{ "Timezone 25", "r3.timezone.25",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x02000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [26],
{ "Timezone 26", "r3.timezone.26",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x04000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [27],
{ "Timezone 27", "r3.timezone.27",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x08000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [28],
{ "Timezone 28", "r3.timezone.28",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x10000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [29],
{ "Timezone 29", "r3.timezone.29",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x20000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [30],
{ "Timezone 30", "r3.timezone.30",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x40000000,
NULL, HFILL }
},
{ &hf_r3_timezonearray [31],
{ "Timezone 31", "r3.timezone.31",
FT_BOOLEAN, 32, TFS (&tfs_enabled_disabled), 0x80000000,
NULL, HFILL }
},
{ &hf_r3_expireon_year,
{ "Expiration Year", "r3.expireon.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_expireon_month,
{ "Expiration Month", "r3.expireon.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_expireon_day,
{ "Expiration Day", "r3.expireon.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_year,
{ "Date/Time Year", "r3.datetime.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_month,
{ "Date/Time Month", "r3.datetime.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_day,
{ "Date/Time Day", "r3.datetime.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_dow,
{ "Date/Time DOW", "r3.datetime.dow",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_daynames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_hours,
{ "Date/Time Hours", "r3.datetime.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_minutes,
{ "Date/Time Minutes", "r3.datetime.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_seconds,
{ "Date/Time Seconds", "r3.datetime.seconds",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_datetime_dst,
{ "Date/Time DST", "r3.datetime.dst",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_recordnumber,
{ "Record Number", "r3.eventlog.recordnumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_year,
{ "Year", "r3.eventlog.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_month,
{ "Month", "r3.eventlog.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_day,
{ "Day", "r3.eventlog.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_hour,
{ "Hours", "r3.eventlog.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_minute,
{ "Minutes", "r3.eventlog.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_second,
{ "Seconds", "r3.eventlog.seconds",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_usernumber,
{ "User Number", "r3.eventlog.usernumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlog_event,
{ "ID", "r3.eventlog.id",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_eventnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_recordnumber,
{ "Record Number", "r3.declinedlog.recordnumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_year,
{ "Year", "r3.declinedlog.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_month,
{ "Month", "r3.declinedlog.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_day,
{ "Day", "r3.declinedlog.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_hour,
{ "Hours", "r3.declinedlog.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_minute,
{ "Minutes", "r3.declinedlog.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_second,
{ "Seconds", "r3.declinedlog.seconds",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_usernumber,
{ "User Number", "r3.declinedlog.usernumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_cred1type,
{ "Credential 1 Type", "r3.declinedlog.cred1type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_fieldtypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_cred2type,
{ "Credential 2 Type", "r3.declinedlog.cred2type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_fieldtypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_cred1,
{ "Credential 1", "r3.declinedlog.cred1",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlog_cred2,
{ "Credential 2", "r3.declinedlog.cred2",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_recordnumber,
{ "Record Number", "r3.alarmlog.recordnumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_year,
{ "Year", "r3.alarmlog.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_month,
{ "Month", "r3.alarmlog.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_day,
{ "Day", "r3.alarmlog.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_hour,
{ "Hours", "r3.alarmlog.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_minute,
{ "Minutes", "r3.alarmlog.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_second,
{ "Seconds", "r3.alarmlog.seconds",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_id,
{ "ID", "r3.alarmlog.id",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_alarmidnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlog_usernumber,
{ "User Number", "r3.alarmlog.usernumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_debugmsg,
{ "Debug Message", "r3.debug",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_year,
{ "Year", "r3.setdate.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_month,
{ "Month", "r3.setdate.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_day,
{ "Day", "r3.setdate.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_dow,
{ "Day-Of-Week", "r3.setdate.dow",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_daynames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_hours,
{ "Hours", "r3.setdate.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_minutes,
{ "Minutes", "r3.setdate.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_setdate_seconds,
{ "Seconds", "r3.setdate.seconds",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_deleteusers,
{ "Delete Users", "r3.deleteusers",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_deleteusersnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_number,
{ "Exception Number", "r3.defineexception.number",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_startdate_month,
{ "Start Month", "r3.defineexception.start.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_startdate_day,
{ "Start Day", "r3.defineexception.start.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_startdate_hours,
{ "Start Hours", "r3.defineexception.start.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_startdate_minutes,
{ "Start Minutes", "r3.defineexception.start.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_enddate_month,
{ "End Month", "r3.defineexception.end.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_enddate_day,
{ "End Day", "r3.defineexception.end.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_enddate_hours,
{ "End Hours", "r3.defineexception.end.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexception_enddate_minutes,
{ "End Minutes", "r3.defineexception.end.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexceptiongroup_number,
{ "Define Exception Group Number", "r3.defineexceptiongroup.number",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_defineexceptiongroup_bits,
{ "Define Exception Group Bit Field", "r3.defineexceptiongroup.field",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definecalendar_number,
{ "Define Calendar Number", "r3.definecalendar.number",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definecalendar_bits,
{ "Define Calendar Bit Field", "r3.definecalendar.field",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_number,
{ "Timezone Number", "r3.definetimezone.number",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_starttime_hours,
{ "Start Hours", "r3.definetimezone.start.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_starttime_minutes,
{ "Start Minutes", "r3.definetimezone.start.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_endtime_hours,
{ "End Hours", "r3.definetimezone.end.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_endtime_minutes,
{ "End Minutes", "r3.definetimezone.end.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [0],
{ "Sunday", "r3.definetimezone.daymap.sunday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000001,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [1],
{ "Monday", "r3.definetimezone.daymap.monday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000002,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [2],
{ "Tuesday", "r3.definetimezone.daymap.tuesday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000004,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [3],
{ "Wednesday", "r3.definetimezone.daymap.wednesday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000008,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [4],
{ "Thursday", "r3.definetimezone.daymap.thursday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000010,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [5],
{ "Friday", "r3.definetimezone.daymap.friday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000020,
NULL, HFILL }
},
{ &hf_r3_definetimezone_daymap [6],
{ "Saturday", "r3.definetimezone.daymap.saturday",
FT_BOOLEAN, 8, TFS (&tfs_enabled_disabled), 0x00000040,
NULL, HFILL }
},
{ &hf_r3_definetimezone_exceptiongroup,
{ "Exception Group", "r3.definetimezone.exceptiongroup",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_mode,
{ "Mode", "r3.definetimezone.mode",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_timezonemodenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_definetimezone_calendar,
{ "Calendar", "r3.definetimezone.calendar",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_rmtauthretry_sequence,
{ "Remote Auth Retry Sequence", "r3.rmtauthretry.sequence",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_rmtauthretry_retry,
{ "Remote Auth Retry Mode", "r3.rmtauthretry.mode",
FT_BOOLEAN, BASE_NONE, TFS (&tfs_rmtauthretry_flags), 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_starttime_year,
{ "Start Year", "r3.eventlogdump.start.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_starttime_month,
{ "Start Month", "r3.eventlogdump.start.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_starttime_day,
{ "Start Day", "r3.eventlogdump.start.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_starttime_hours,
{ "Start Hours", "r3.eventlogdump.start.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_starttime_minutes,
{ "Start Minutes", "r3.eventlogdump.start.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_endtime_year,
{ "End Year", "r3.eventlogdump.end.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_endtime_month,
{ "End Month", "r3.eventlogdump.end.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_endtime_day,
{ "End Day", "r3.eventlogdump.end.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_endtime_hours,
{ "End Hours", "r3.eventlogdump.end.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_endtime_minutes,
{ "End Minutes", "r3.eventlogdump.end.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_eventlogdump_user,
{ "Filter User", "r3.eventlogdump.user",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_starttime_year,
{ "Start Year", "r3.declinedlogdump.start.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_starttime_month,
{ "Start Month", "r3.declinedlogdump.start.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_starttime_day,
{ "Start Day", "r3.declinedlogdump.start.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_starttime_hours,
{ "Start Hours", "r3.declinedlogdump.start.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_starttime_minutes,
{ "Start Minutes", "r3.declinedlogdump.start.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_endtime_year,
{ "End Year", "r3.declinedlogdump.end.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_endtime_month,
{ "End Month", "r3.declinedlogdump.end.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_endtime_day,
{ "End Day", "r3.declinedlogdump.end.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_endtime_hours,
{ "End Hours", "r3.declinedlogdump.end.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_declinedlogdump_endtime_minutes,
{ "End Minutes", "r3.declinedlogdump.end.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_starttime_year,
{ "Start Year", "r3.alarmlogdump.start.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_starttime_month,
{ "Start Month", "r3.alarmlogdump.start.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_starttime_day,
{ "Start Day", "r3.alarmlogdump.start.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_starttime_hours,
{ "Start Hours", "r3.alarmlogdump.start.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_starttime_minutes,
{ "Start Minutes", "r3.alarmlogdump.start.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_endtime_year,
{ "End Year", "r3.alarmlogdump.end.year",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_endtime_month,
{ "End Month", "r3.alarmlogdump.end.month",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_monthnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_endtime_day,
{ "End Day", "r3.alarmlogdump.end.day",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_endtime_hours,
{ "End Hours", "r3.alarmlogdump.end.hours",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarmlogdump_endtime_minutes,
{ "End Minutes", "r3.alarmlogdump.end.minutes",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 0],
{ "NVRAMCLEAROPTIONS_CFGINSTALLER", "r3.nvramclear.cfginstaller",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000001,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 1],
{ "NVRAMCLEAROPTIONS_CFGADMIN", "r3.nvramclear.cfgadmin",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000002,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 2],
{ "NVRAMCLEAROPTIONS_EXCEPTIONS", "r3.nvramclear.exceptions",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000004,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 3],
{ "NVRAMCLEAROPTIONS_EXCEPTIONGROUPS", "r3.nvramclear.exceptiongroups",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000008,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 4],
{ "NVRAMCLEAROPTIONS_CALENDARS", "r3.nvramclear.calendars",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000010,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 5],
{ "NVRAMCLEAROPTIONS_TIMEZONES", "r3.nvramclear.timezones",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000020,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 6],
{ "NVRAMCLEAROPTIONS_FILTERS", "r3.nvramclear.filters",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000040,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 7],
{ "NVRAMCLEAROPTIONS_EVENTLOG", "r3.nvramclear.eventlog",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000080,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 8],
{ "NVRAMCLEAROPTIONS_USERDATA", "r3.nvramclear.userdata",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000100,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [ 9],
{ "NVRAMCLEAROPTIONS_DECLINEDLOG", "r3.nvramclear.declinedlog",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000200,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [10],
{ "NVRAMCLEAROPTIONS_ALARMLOG", "r3.nvramclear.alarmlog",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000400,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [11],
{ "NVRAMCLEAROPTIONS_LRUCACHE", "r3.nvramclear.lrucache",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00000800,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [12],
{ "NVRAMCLEAROPTIONS_DBHASH", "r3.nvramclear.dbhash",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00001000,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [13],
{ "NVRAMCLEAROPTIONS_CFGSYSTEM", "r3.nvramclear.cfgsystem",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00002000,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [14],
{ "NVRAMCLEAROPTIONS_UNUSED", "r3.nvramclear.unused",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00004000,
NULL, HFILL }
},
{ &hf_r3_nvramclearoptions [15],
{ "NVRAMCLEAROPTIONS_USEBACKUP", "r3.nvramclear.usebackup",
FT_BOOLEAN, 16, TFS (&tfs_enabled_disabled), 0x00008000,
NULL, HFILL }
},
{ &hf_r3_writeeventlog_user,
{ "User", "r3.writeeventlog.user",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_writeeventlog_event,
{ "Event", "r3.writeeventlog.event",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_eventnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_powertableselection,
{ "Table", "r3.powertableselection",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_powertablenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_filter_type,
{ "Type", "r3.filter.type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_filtertypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_filter_list,
{ "Event", "r3.filter.event",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_filtereventnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarm_length,
{ "Length", "r3.alarm.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarm_id,
{ "ID", "r3.alarm.id",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_alarmidnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_alarm_state,
{ "State", "r3.alarm.state",
FT_BOOLEAN, BASE_NONE, TFS (&tfs_enabled_disabled), 0x0,
NULL, HFILL }
},
{ &hf_r3_dpac_action,
{ "Dpac Action", "r3.dpac.action",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dpac_waittime,
{ "Dpac Waittime", "r3.dpac.waittime",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dpac_command,
{ "Dpac Command", "r3.dpac.command",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dpacreply_stuff,
{ "Dpac Reply Stuff", "r3.dpacreply.stuff",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dpacreply_length,
{ "Dpac Reply Length", "r3.dpacreply.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dpacreply_reply,
{ "Dpac Reply", "r3.dpacreply.reply",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgfield_length,
{ "Field Length", "r3.mfgfield.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgfield,
{ "Field", "r3.mfgfield.field",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_mfgfieldnames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_mfgfield_data,
{ "Field Data", "r3.mfgfield.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_mfgsetserialnumber,
{ "Serial Number", "r3.mfgsetserialnumber",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgsetcryptkey,
{ "Crypt Key", "r3.mfgsetcryptkey",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgdumpnvram,
{ "NVRAM Section", "r3.mfgnvramdump",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_mfgnvramdumpnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgremoteunlock,
{ "Remote Unlock", "r3.mfgremoteunlock",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_mfgremoteunlocknames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_mfgtestpreserve,
{ "Preserve Mode", "r3.mfgtestpreserve",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_mfgtestpreservenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [0],
{ "ADC 0", "r3.adc.0",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [1],
{ "ADC 1", "r3.adc.1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [2],
{ "ADC 2", "r3.adc.2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [3],
{ "ADC 3", "r3.adc.3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [4],
{ "ADC 4", "r3.adc.4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [5],
{ "ADC 5", "r3.adc.5",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [6],
{ "ADC 6", "r3.adc.6",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adc [7],
{ "ADC 7", "r3.adc.7",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_hardwareid_board,
{ "Board ID", "r3.hardwareid.board",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_hardwareid_cpuid,
{ "CPU ID", "r3.hardwareid.cpuid",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_hardwareid_cpurev,
{ "CPU Rev", "r3.hardwareid.cpurev",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_testkeypad,
{ "Keypad Char", "r3.test.keypad",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_testmagcard,
{ "Mag Card", "r3.test.magcard",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_testproxcard,
{ "Prox Card", "r3.test.proxcard",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdump_record,
{ "Record Number", "r3.nvramdump.record",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdump_length,
{ "Record Length", "r3.nvramdump.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdump_data,
{ "Record Data", "r3.nvramdump.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdumprle_record,
{ "Record Number", "r3.nvramdumprle.record",
FT_UINT24, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdumprle_length,
{ "Record Length", "r3.nvramdumprle.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramdumprle_data,
{ "Record Data", "r3.nvramdumprle.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_iopins_lat,
{ "LAT", "r3.iopins.lat",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_iopins_port,
{ "PORT", "r3.iopins.port",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_iopins_tris,
{ "TRIS", "r3.iopins.tris",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mortisepins_s1,
{ "Mortise Pin S1", "r3.mortisepins.s1",
FT_BOOLEAN, 8, TFS (&tfs_mortisepins_flags), 0x00000001,
NULL, HFILL }
},
{ &hf_r3_mortisepins_s2,
{ "Mortise Pin S2", "r3.mortisepins.s2",
FT_BOOLEAN, 8, TFS (&tfs_mortisepins_flags), 0x00000002,
NULL, HFILL }
},
{ &hf_r3_mortisepins_s3,
{ "Mortise Pin S3", "r3.mortisepins.s3",
FT_BOOLEAN, 8, TFS (&tfs_mortisepins_flags), 0x00000004,
NULL, HFILL }
},
{ &hf_r3_mortisepins_s4,
{ "Mortise Pin S4", "r3.mortisepins.s4",
FT_BOOLEAN, 8, TFS (&tfs_mortisepins_flags), 0x00000008,
NULL, HFILL }
},
{ &hf_r3_checksumresults ,
{ "Checksum Results", "r3.checksumresults",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_checksumresults_field,
{ "Field", "r3.checksumresults.field",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, & r3_checksumresultnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_checksumresults_length,
{ "Length", "r3.checksumresults.length",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_checksumresults_state,
{ "State", "r3.checksumresults.state",
FT_BOOLEAN, BASE_NONE, TFS (&tfs_errornoerror_flags), 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_item,
{ "Item", "r3.forceoptions.item",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_forceitemnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_length,
{ "Length", "r3.forceoptions.length",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_state_8,
{ "State", "r3.forceoptions.state",
FT_BOOLEAN, BASE_NONE, TFS (&tfs_enabled_disabled), 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_state_16,
{ "State", "r3.forceoptions.state",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_state_24,
{ "State", "r3.forceoptions.state",
FT_UINT24, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_forceoptions_state_32,
{ "State", "r3.forceoptions.state",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_operation,
{ "Operation", "r3.peekpoke.operation",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_peekpokenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_address,
{ "Address", "r3.peekpoke.address",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_length,
{ "Length", "r3.peekpoke.length",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_poke8,
{ "8 Bit Value", "r3.peekpoke.poke8",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_poke16,
{ "16 Bit Value", "r3.peekpoke.poke16",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_poke24,
{ "24 Bit Value", "r3.peekpoke.poke24",
FT_UINT24, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_poke32,
{ "32 Bit Value", "r3.peekpoke.poke32",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_peekpoke_pokestring,
{ "String Value", "r3.peekpoke.pokestring",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_length,
{ "Length", "r3.firmwaredownload.length",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_record,
{ "Record Number", "r3.firmwaredownload.record",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_action,
{ "Action", "r3.firmwaredownload.action",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_downloadfirmwarenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_timeout,
{ "Timeout", "r3.firmwaredownload.timeout",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_nvram,
{ "NVRAM", "r3.firmwaredownload.nvram",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_address,
{ "Address", "r3.firmwaredownload.address",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_bytes,
{ "Bytes", "r3.firmwaredownload.bytes",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_data,
{ "Data", "r3.firmwaredownload.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_crc,
{ "CRC", "r3.firmwaredownload.crc",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_firmwaredownload_crc_bad,
{ "Bad CRC", "r3.firmwaredownload.crc_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramchecksumvalue,
{ "Value", "r3.nvramchecksum.value",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_nvramchecksumvalue_fixup,
{ "Fixup", "r3.nvramchecksum.fixup",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_capabilities,
{ "Capability", "r3.capabilities",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_capabilities_length,
{ "Length", "r3.capabilities.length",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_capabilities_type,
{ "Type", "r3.capabilities.type",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_capabilitiesnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_capabilities_value,
{ "Value", "r3.capabilities.value",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_lockstate_passage,
{ "Passage", "r3.lockstate.passage",
FT_BOOLEAN, 24, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_r3_lockstate_panic,
{ "Panic", "r3.lockstate.panic",
FT_BOOLEAN, 24, NULL, 0x00000002,
NULL, HFILL }
},
{ &hf_r3_lockstate_lockout,
{ "Lockout", "r3.lockstate.lockout",
FT_BOOLEAN, 24, NULL, 0x00000004,
NULL, HFILL }
},
{ &hf_r3_lockstate_relock,
{ "Relock", "r3.lockstate.relock",
FT_BOOLEAN, 24, NULL, 0x00000008,
NULL, HFILL }
},
{ &hf_r3_lockstate_autoopen,
{ "Auto Open", "r3.lockstate.autoopen",
FT_BOOLEAN, 24, NULL, 0x00000010,
NULL, HFILL }
},
{ &hf_r3_lockstate_nextauto,
{ "Next Auto", "r3.lockstate.nextauto",
FT_BOOLEAN, 24, NULL, 0x00000020,
NULL, HFILL }
},
{ &hf_r3_lockstate_lockstate,
{ "Lock State", "r3.lockstate.lockstate",
FT_BOOLEAN, 24, NULL, 0x00000040,
NULL, HFILL }
},
{ &hf_r3_lockstate_wantstate,
{ "Want State", "r3.lockstate.wantstate",
FT_BOOLEAN, 24, NULL, 0x00000080,
NULL, HFILL }
},
{ &hf_r3_lockstate_remote,
{ "Remote", "r3.lockstate.remote",
FT_BOOLEAN, 24, NULL, 0x00000100,
NULL, HFILL }
},
{ &hf_r3_lockstate_update,
{ "Update", "r3.lockstate.update",
FT_BOOLEAN, 24, NULL, 0x00000200,
NULL, HFILL }
},
{ &hf_r3_lockstate_exceptionspresent,
{ "Exceptions Present", "r3.lockstate.exceptionspresent",
FT_BOOLEAN, 24, NULL, 0x00000400,
NULL, HFILL }
},
{ &hf_r3_lockstate_exceptionsactive,
{ "Exceptions Active", "r3.lockstate.exceptionsactive",
FT_BOOLEAN, 24, NULL, 0x00000800,
NULL, HFILL }
},
{ &hf_r3_lockstate_timezonespresent,
{ "Timezones Presents", "r3.lockstate.timezonespresent",
FT_BOOLEAN, 24, NULL, 0x00001000,
NULL, HFILL }
},
{ &hf_r3_lockstate_timezonesactive,
{ "Timezones Active", "r3.lockstate.timezonesactive",
FT_BOOLEAN, 24, NULL, 0x00002000,
NULL, HFILL }
},
{ &hf_r3_lockstate_autounlockspresent,
{ "Auto Unlocks Present", "r3.lockstate.autounlockspresent",
FT_BOOLEAN, 24, NULL, 0x00004000,
NULL, HFILL }
},
{ &hf_r3_lockstate_autounlocksactive,
{ "Auto Unlocks Active", "r3.lockstate.autounlocksactive",
FT_BOOLEAN, 24, NULL, 0x00008000,
NULL, HFILL }
},
{ &hf_r3_lockstate_uapmspresent,
{ "UAPMs Present", "r3.lockstate.uapmspresent",
FT_BOOLEAN, 24, NULL, 0x00010000,
NULL, HFILL }
},
{ &hf_r3_lockstate_uapmsactive,
{ "UAPMs Active", "r3.lockstate.uapmsactive",
FT_BOOLEAN, 24, NULL, 0x00020000,
NULL, HFILL }
},
{ &hf_r3_lockstate_uapmrelockspresent,
{ "UAPM Relocks Present", "r3.lockstate.uapmrelockspresent",
FT_BOOLEAN, 24, NULL, 0x00040000,
NULL, HFILL }
},
{ &hf_r3_lockstate_uapmreslocksactive,
{ "UAPM Relocks Active", "r3.lockstate.uapmreslocksactive",
FT_BOOLEAN, 24, NULL, 0x00080000,
NULL, HFILL }
},
{ &hf_r3_lockstate_nvramprotect,
{ "NVRAM Protect", "r3.lockstate.nvramprotect",
FT_BOOLEAN, 24, NULL, 0x00100000,
NULL, HFILL }
},
{ &hf_r3_lockstate_nvramchecksum,
{ "MVRAM Checksum", "r3.lockstate.nvramchecksum",
FT_BOOLEAN, 24, NULL, 0x00200000,
NULL, HFILL }
},
#if 0
{ &hf_r3_mortisestatelog,
{ "Mortise State Log", "r3.mortisestatelog",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_mortisestatelog_pointer,
{ "Event Pointer", "r3.mortisestatelog.pointer",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mortisestatelog_mortisetype,
{ "Mortise Type", "r3.mortisestatelog.mortisetype",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_mortisetypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_mortisestatelog_waiting,
{ "Waiting For Door Closed", "r3.mortisestatelog.waiting",
FT_BOOLEAN, BASE_NONE, TFS (&tfs_true_false ), 0x00,
NULL, HFILL }
},
{ &hf_r3_mortisestatelog_state,
{ "State", "r3.mortisestatelog.state",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mortisestatelog_last,
{ "Last State", "r3.mortisestatelog.laststate",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_mortisestatelog_event,
{ "Event", "r3.mortisestatelog.event",
FT_UINT8, BASE_HEX_DEC|BASE_EXT_STRING, &r3_mortiseeventnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_newtick,
{ "New Tick", "r3.timerchain.newtick",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_currentboundary,
{ "Current Boundary", "r3.timerchain.currentboundary",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_tasktag,
{ "Task Tag", "r3.timerchain.tasktag",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_address,
{ "Address", "r3.timerchain.address",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_reload,
{ "Reload", "r3.timerchain.reload",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_boundary,
{ "Boundary", "r3.timerchain.boundary",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_count,
{ "Count", "r3.timerchain.count",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_timerchain_flags,
{ "Flags", "r3.timerchain.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_taskflags_taskid,
{ "Task ID", "r3.taskflags.taskid",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_taskflags_flags,
{ "Flags", "r3.taskflags.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_checkpointlog_entryptr,
{ "Entry Pointer", "r3.checkpointlog.entrypointer",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_checkpointlog_rcon,
{ "RCON", "r3.checkpointlog.rcon",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_checkpointlog_checkpoint,
{ "Checkpoint", "r3.checkpointlog.checkpoint",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon,
{ "INTCON", "r3.cpuregisters.intcon",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2,
{ "INTCON2", "r3.cpuregisters.intcon2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3,
{ "INTCON3", "r3.cpuregisters.intcon3",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1,
{ "PIR1", "r3.cpuregisters.pir1",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2,
{ "PIR2", "r3.cpuregisters.pir2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3,
{ "PIR3", "r3.cpuregisters.pir3",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1,
{ "PIE1", "r3.cpuregisters.pie1",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2,
{ "PIE2", "r3.cpuregisters.pie2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3,
{ "PIE3", "r3.cpuregisters.pie3",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1,
{ "IPR1", "r3.cpuregisters.ipr1",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2,
{ "IPR2", "r3.cpuregisters.ipr2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3,
{ "IPR3", "r3.cpuregisters.ipr3",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon,
{ "RCON", "r3.cpuregisters.rcon",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon,
{ "OSCCON", "r3.cpuregisters.osccon",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta,
{ "RCSTA", "r3.cpuregisters.rcsta",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta,
{ "TXSTA", "r3.cpuregisters.txsta",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2,
{ "RCSTA2", "r3.cpuregisters.rcsta2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2,
{ "TXSTA2", "r3.cpuregisters.txsta2",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon,
{ "WDTCON", "r3.cpuregisters.wdtcon",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_rbif,
{ "INTCON.RBIF", "r3.cpuregisters.intcon.rbif",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_int0if,
{ "INTCON.INT0IF", "r3.cpuregisters.intcon.int0if",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_tmr0if,
{ "INTCON.TMR0IF", "r3.cpuregisters.intcon.tmr0if",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_rbie,
{ "INTCON.RBIE", "r3.cpuregisters.intcon.rbie",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_int0ie,
{ "INTCON.INT0IE", "r3.cpuregisters.intcon.int0ie",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_tmr0ie,
{ "INTCON.TMR0IE", "r3.cpuregisters.intcon.tmr0ie",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_giel,
{ "INTCON.GIEL", "r3.cpuregisters.intcon.giel",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon_gieh,
{ "INTCON.GIEH", "r3.cpuregisters.intcon.gieh",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_rbip,
{ "INTCON2.RBIP", "r3_cpuregisters_intcon2_rbip",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_int3ip,
{ "INTCON2.INT3IP", "r3_cpuregisters_intcon2_int3ip",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_tmr0ip,
{ "INTCON2.TMR0IP", "r3_cpuregisters_intcon2_tmr0ip",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_intedg3,
{ "INTCON2.INTEDG3", "r3_cpuregisters_intcon2_intedg3",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_intedg2,
{ "INTCON2.INTEDG2", "r3_cpuregisters_intcon2_intedg2",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_intedg1,
{ "INTCON2.INTEDG1", "r3_cpuregisters_intcon2_intedg1",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_intedg0,
{ "INTCON2.INTEDG0", "r3_cpuregisters_intcon2_intedg0",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon2_rbpu,
{ "INTCON2.RBPU", "r3_cpuregisters_intcon2_rbpu",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int1if,
{ "INTCON3.INT1IF", "r3.cpuregisters.intcon3.int1if",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int2if,
{ "INTCON3.INT2IF", "r3.cpuregisters.intcon3.int2if",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int3if,
{ "INTCON3.INT3IF", "r3.cpuregisters.intcon3.int3if",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int1ie,
{ "INTCON3.INT1IE", "r3.cpuregisters.intcon3.int1ie",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int2ie,
{ "INTCON3.INT2IE", "r3.cpuregisters.intcon3.int2ie",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int3ie,
{ "INTCON3.INT3IE", "r3.cpuregisters.intcon3.int3ie",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int1ip,
{ "INTCON3.INT1IP", "r3.cpuregisters.intcon3.int1ip",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_intcon3_int2ip,
{ "INTCON3.INT2IP", "r3.cpuregisters.intcon3.int2ip",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_tmr1if,
{ "PIR1.TMR1IF", "r3.cpuregisters.pir1.tmr1if",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_tmr2if,
{ "PIR1.TMR2IF", "r3.cpuregisters.pir1.tmr2if",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_ccp1if,
{ "PIR1.CCP1IF", "r3.cpuregisters.pir1.ccp1if",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_ssp1if,
{ "PIR1.SSP1IF", "r3.cpuregisters.pir1.ssp1if",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_tx1if,
{ "PIR1.TX1IF", "r3.cpuregisters.pir1.tx1if",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_rc1if,
{ "PIR1.RC1IF", "r3.cpuregisters.pir1.rc1if",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_adif,
{ "PIR1.ADIF", "r3.cpuregisters.pir1.adif",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir1_pspif,
{ "PIR1.PSPIF", "r3.cpuregisters.pir1.pspif",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_ccp2if,
{ "PIR2.CCP2IF", "r3.cpuregisters.pir2.ccp2if",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_tmr3if,
{ "PIR2.TMR3IF", "r3.cpuregisters.pir2.tmr3if",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_hlvdif,
{ "PIR2.HLVDIF", "r3.cpuregisters.pir2.hlvdif",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_bcl1if,
{ "PIR2.BCL1IF", "r3.cpuregisters.pir2.bcl1if",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_eeif,
{ "PIR2.EEIF", "r3.cpuregisters.pir2.eeif",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_unused5,
{ "PIR2.UNUSED5", "r3.cpuregisters.pir2.unused5",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_cmif,
{ "PIR2.CMIF", "r3.cpuregisters.pir2.cmif",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir2_oscfif,
{ "PIR2.OSCFIF", "r3.cpuregisters.pir2.oscfif",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_ccp3if,
{ "PIR3.CCP3IF", "r3.cpuregisters.pir3.ccp3if",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_ccp4if,
{ "PIR3.CCP4IF", "r3.cpuregisters.pir3.ccp4if",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_ccp5if,
{ "PIR3.CCP5IF", "r3.cpuregisters.pir3.ccp5if",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_tmr4if,
{ "PIR3.TMR4IF", "r3.cpuregisters.pir3.tmr4if",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_tx2if,
{ "PIR3.TX2IF", "r3.cpuregisters.pir3.tx2if",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_rc2if,
{ "PIR3.RC2IF", "r3.cpuregisters.pir3.rc2if",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_bcl2if,
{ "PIR3.BCL2IF", "r3.cpuregisters.pir3.bcl2if",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pir3_ssp2if,
{ "PIR3.SSP2IF", "r3.cpuregisters.pir3.ssp2if",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_tmr1ie,
{ "PIE1.TMR1IE", "r3.cpuregisters.pie1.tmr1ie",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_tmr2ie,
{ "PIE1.TMR2IE", "r3.cpuregisters.pie1.tmr2ie",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_ccp1ie,
{ "PIE1.CCP1IE", "r3.cpuregisters.pie1.ccp1ie",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_ssp1ie,
{ "PIE1.SSP1IE", "r3.cpuregisters.pie1.ssp1ie",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_tx1ie,
{ "PIE1.TX1IE", "r3.cpuregisters.pie1.tx1ie",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_rc1ie,
{ "PIE1.RC1IE", "r3.cpuregisters.pie1.rc1ie",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_adie,
{ "PIE1.ADIE", "r3.cpuregisters.pie1.adie",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie1_pspie,
{ "PIE1.PSPIE", "r3.cpuregisters.pie1.pspie",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_oscfie,
{ "PIE2.OSCFIE", "r3.cpuregisters.pie2.oscfie",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_cmie,
{ "PIE2.CMIE", "r3.cpuregisters.pie2.cmie",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_unused2,
{ "PIE2.UNUSED2", "r3.cpuregisters.pie2.unused2",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_eeie,
{ "PIE2.EEIE", "r3.cpuregisters.pie2.eeie",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_bcl1ie,
{ "PIE2.BCL1IE", "r3.cpuregisters.pie2.bcl1ie",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_hlvdie,
{ "PIE2.HLVDIE", "r3.cpuregisters.pie2.hlvdie",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_tmr3ie,
{ "PIE2.TMR3IE", "r3.cpuregisters.pie2.tmr3ie",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie2_ccp2ie,
{ "PIE2.CCP2IE", "r3.cpuregisters.pie2.ccp2ie",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_ccp3ie,
{ "PIE3.CCP3IE", "r3.cpuregisters.pie3.ccp3ie",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_ccp4ie,
{ "PIE3.CCP4IE", "r3.cpuregisters.pie3.ccp4ie",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_ccp5ie,
{ "PIE3.CCP5IE", "r3.cpuregisters.pie3.ccp5ie",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_tmr4ie,
{ "PIE3.TMR4IE", "r3.cpuregisters.pie3.tmr4ie",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_tx2ie,
{ "PIE3.TX2IE", "r3.cpuregisters.pie3.tx2ie",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_rc2ie,
{ "PIE3.RC2IE", "r3.cpuregisters.pie3.rc2ie",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_bcl2ie,
{ "PIE3.BCL2IE", "r3.cpuregisters.pie3.bcl2ie",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_pie3_ssp2ie,
{ "PIE3.SSP2IE", "r3.cpuregisters.pie3.ssp2ie",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_tmr1ip,
{ "IPR1.TMR1IP", "r3.cpuregisters.ipr1.tmr1ip",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_tmr2ip,
{ "IPR1.TMR2IP", "r3.cpuregisters.ipr1.tmr2ip",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_ccp1ip,
{ "IPR1.CCP1IP", "r3.cpuregisters.ipr1.ccp1ip",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_ssp1ip,
{ "IPR1.SSP1IP", "r3.cpuregisters.ipr1.ssp1ip",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_tx1ip,
{ "IPR1.TX1IP", "r3.cpuregisters.ipr1.tx1ip",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_rc1ip,
{ "IPR1.RC1IP", "r3.cpuregisters.ipr1.rc1ip",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_adip,
{ "IPR1.ADIP", "r3.cpuregisters.ipr1.adip",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr1_pspip,
{ "IPR1.PSPIP", "r3.cpuregisters.ipr1.pspip",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_ccp2ip,
{ "IPR2.CCP2IP", "r3.cpuregisters.ipr2.ccp2ip",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_tmr3ip,
{ "IPR2.TMR3IP", "r3.cpuregisters.ipr2.tmr3ip",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_hlvdip,
{ "IPR2.HLVDIP", "r3.cpuregisters.ipr2.hlvdip",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_bcl1ip,
{ "IPR2.BCL1IP", "r3.cpuregisters.ipr2.bcl1ip",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_eeip,
{ "IPR2.EEIP", "r3.cpuregisters.ipr2.eeip",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_unused5,
{ "IPR2.UNUSED5", "r3.cpuregisters.ipr2.unused5",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_cmip,
{ "IPR2.CMIP", "r3.cpuregisters.ipr2.cmip",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr2_oscfip,
{ "IPR2.OSCFIP", "r3.cpuregisters.ipr2.oscfip",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_ccp2ip,
{ "IPR3.CCP2IP", "r3.cpuregisters.ipr3.ccp2ip",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_ccp4ip,
{ "IPR3.CCP4IP", "r3.cpuregisters.ipr3.ccp4ip",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_ccp5ip,
{ "IPR3.CCP5IP", "r3.cpuregisters.ipr3.ccp5ip",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_tmr4ip,
{ "IPR3.TMR4IP", "r3.cpuregisters.ipr3.tmr4ip",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_tx2ip,
{ "IPR3.TX2IP", "r3.cpuregisters.ipr3.tx2ip",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_rc2ip,
{ "IPR3.RC2IP", "r3.cpuregisters.ipr3.rc2ip",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_bcl2ip,
{ "IPR3.BCL2IP", "r3.cpuregisters.ipr3.bcl2ip",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_ipr3_ssp2ip,
{ "IPR3.SSP2IP", "r3.cpuregisters.ipr3.ssp2ip",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_bor,
{ "RCON./BOR", "r3.cpuregisters.rcon.bor",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_por,
{ "RCON./POR", "r3.cpuregisters.rcon.por",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_pd,
{ "RCON./PD", "r3.cpuregisters.rcon.pd",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_to,
{ "RCON./TO", "r3.cpuregisters.rcon.to",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_unused4,
{ "RCON.UNUSED4", "r3.cpuregisters.rcon.unused4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_ri,
{ "RCON./RI", "r3.cpuregisters.rcon.ri",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_sboren,
{ "RCON.SBOREN", "r3.cpuregisters.rcon.sboren",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcon_ipen,
{ "RCON.IPEN", "r3.cpuregisters.rcon.ipen",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_scs0,
{ "OSCCON.SCS0", "r3.cpuregisters.osccon.scs0",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_scs1,
{ "OSCCON.SCS1", "r3.cpuregisters.osccon.scs1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_iofs,
{ "OSCCON.IOFS", "r3.cpuregisters.osccon.iofs",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_osts,
{ "OSCCON.OSTS", "r3.cpuregisters.osccon.osts",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_ircf0,
{ "OSCCON.IRCF0", "r3.cpuregisters.osccon.ircf0",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_ircf1,
{ "OSCCON.IRCF1", "r3.cpuregisters.osccon.ircf1",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_ircf2,
{ "OSCCON.IRCF2", "r3.cpuregisters.osccon.ircf2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_osccon_idlen,
{ "OSCCON.IDLEN", "r3.cpuregisters.osccon.idlen",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_rx9d,
{ "RCSTA.RX9D", "r3.cpuregisters.rcsta.rx9d",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_oerr,
{ "RCSTA.OERR", "r3.cpuregisters.rcsta.oerr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_ferr,
{ "RCSTA.FERR", "r3.cpuregisters.rcsta.ferr",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_adden,
{ "RCSTA.ADDEN", "r3.cpuregisters.rcsta.adden",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_cren,
{ "RCSTA.CREN", "r3.cpuregisters.rcsta.cren",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_sren,
{ "RCSTA.SREN", "r3.cpuregisters.rcsta.sren",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_rx9,
{ "RCSTA.RX9", "r3.cpuregisters.rcsta.rx9",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta_spen,
{ "RCSTA.SPEN", "r3.cpuregisters.rcsta.spen",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_tx9d,
{ "TXSTA.TX9D", "r3.cpuregisters.txsta.tx9d",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_trmt,
{ "TXSTA.TRMT", "r3.cpuregisters.txsta.trmt",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_brgh,
{ "TXSTA.BRGH", "r3.cpuregisters.txsta.brgh",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_sendb,
{ "TXSTA.SENDB", "r3.cpuregisters.txsta.sendb",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_sync,
{ "TXSTA.SYNC", "r3.cpuregisters.txsta.sync",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_txen,
{ "TXSTA.TXEN", "r3.cpuregisters.txsta.txen",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_tx9,
{ "TXSTA.TX9", "r3.cpuregisters.txsta.tx9",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta_csrc,
{ "TXSTA.CSRC", "r3.cpuregisters.txsta.csrc",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_rx9d,
{ "RCSTA2.RX9D", "r3.cpuregisters.rcsta2.rx9d",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_oerr,
{ "RCSTA2.OERR", "r3.cpuregisters.rcsta2.oerr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_ferr,
{ "RCSTA2.FERR", "r3.cpuregisters.rcsta2.ferr",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_adden,
{ "RCSTA2.ADDEN", "r3.cpuregisters.rcsta2.adden",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_cren,
{ "RCSTA2.CREN", "r3.cpuregisters.rcsta2.cren",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_sren,
{ "RCSTA2.SREN", "r3.cpuregisters.rcsta2.sren",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_rx9,
{ "RCSTA2.RX9", "r3.cpuregisters.rcsta2.rx9",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_rcsta2_spen,
{ "RCSTA2.SPEN", "r3.cpuregisters.rcsta2.spen",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_tx9d,
{ "TXSTA2.TX9D", "r3.cpuregisters.txsta2.tx9d",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_trmt,
{ "TXSTA2.TRMT", "r3.cpuregisters.txsta2.trmt",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_brgh,
{ "TXSTA2.BRGH", "r3.cpuregisters.txsta2.brgh",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_sendb,
{ "TXSTA2.SENDB", "r3.cpuregisters.txsta2.sendb",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_sync,
{ "TXSTA2.SYNC", "r3.cpuregisters.txsta2.sync",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_txen,
{ "TXSTA2.TXEN", "r3.cpuregisters.txsta2.txen",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_tx9,
{ "TXSTA2.TX9", "r3.cpuregisters.txsta2.tx9",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_txsta2_csrc,
{ "TXSTA2.CSRC", "r3.cpuregisters.txsta2.csrc",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_swdten,
{ "WDTCON.SWDTEN", "r3.cpuregisters.wdtcon.swdten",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused1,
{ "WDTCON.UNUSED1", "r3.cpuregisters.wdtcon.unused1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused2,
{ "WDTCON.UNUSED2", "r3.cpuregisters.wdtcon.unused2",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused3,
{ "WDTCON.UNUSED3", "r3.cpuregisters.wdtcon.unused3",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused4,
{ "WDTCON.UNUSED4", "r3.cpuregisters.wdtcon.unused4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused5,
{ "WDTCON.UNUSED5", "r3.cpuregisters.wdtcon.unused5",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused6,
{ "WDTCON.UNUSED6", "r3.cpuregisters.wdtcon.unused6",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_r3_cpuregisters_wdtcon_unused7,
{ "WDTCON.UNUSED7", "r3.cpuregisters.wdtcon.unused7",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg00,
{ "REG 0x00", "r3.m41t81.reg00",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg01,
{ "REG 0x01", "r3.m41t81.reg01",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg02,
{ "REG 0x02", "r3.m41t81.reg02",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg03,
{ "REG 0x03", "r3.m41t81.reg03",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg04,
{ "REG 0x04", "r3.m41t81.reg04",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg05,
{ "REG 0x05", "r3.m41t81.reg05",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg06,
{ "REG 0x06", "r3.m41t81.reg06",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg07,
{ "REG 0x07", "r3.m41t81.reg07",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg08,
{ "REG 0x08", "r3.m41t81.reg08",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg09,
{ "REG 0x09", "r3.m41t81.reg09",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a,
{ "REG 0x0a", "r3.m41t81.reg0a",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0b,
{ "REG 0x0b", "r3.m41t81.reg0b",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0c,
{ "REG 0x0c", "r3.m41t81.reg0c",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0d,
{ "REG 0x0d", "r3.m41t81.reg0d",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0e,
{ "REG 0x0e", "r3.m41t81.reg0e",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0f,
{ "REG 0x0f", "r3.m41t81.reg0f",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg10,
{ "REG 0x10", "r3.m41t81.reg10",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg11,
{ "REG 0x11", "r3.m41t81.reg11",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg12,
{ "REG 0x12", "r3.m41t81.reg12",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg13,
{ "REG 0x13", "r3.m41t81.reg13",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg00_sec1,
{ ".1 Seconds", "r3.m41t81.reg00.sec1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg00_sec01,
{ ".01 Seconds", "r3.m41t81.reg00.sec01",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg01_st,
{ "ST", "r3.m41t81.reg01.st",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg01_10sec,
{ "10 Seconds", "r3.m41t81.reg01.10sec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg01_1sec,
{ "1 Seconds", "r3.m41t81.reg01.1sec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg02_notused,
{ "(not used)", "r3.m41t81.reg02.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg02_10min,
{ "10 Minutes", "r3.m41t81.reg02.10min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg02_1min,
{ "1 Minutes", "r3.m41t81.reg02.1min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg03_cbe,
{ "CBE", "r3.m41t81.reg03.cbe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg03_cb,
{ "CB", "r3.m41t81.reg03.cb",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg03_10hour,
{ "10 Hours", "r3.m41t81.reg03.10hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg03_1hour,
{ "1 Hours", "r3.m41t81.reg03.1hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg04_notused,
{ "(not used)", "r3.m41t81.reg04.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg04_dow,
{ "DOW", "r3.m41t81.reg04.dow",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg05_notused,
{ "(not used)", "r3.m41t81.reg05.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg05_10day,
{ "10 Day", "r3.m41t81.reg05.10day",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg05_1day,
{ "1 Day", "r3.m41t81.reg05.1day",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg06_notused,
{ "(not used)", "r3.m41t81.reg06.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg06_10month,
{ "10 Month", "r3.m41t81.reg06.10month",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg06_1month,
{ "1 Month", "r3.m41t81.reg06.1month",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg07_10year,
{ "10 Year", "r3.m41t81.reg07.10year",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg07_1year,
{ "1 Year", "r3.m41t81.reg07.1year",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg08_out,
{ "OUT", "r3.m41t81.reg08.out",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg08_ft,
{ "FT", "r3.m41t81.reg08.ft",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg08_s,
{ "S", "r3.m41t81.reg08.s",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg08_cal,
{ "CAL", "r3.m41t81.reg08.cal",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg09_notused,
{ "(not used)", "r3.m41t81.reg09.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg09_bmb,
{ "BMB", "r3.m41t81.reg09.bmb",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg09_rb,
{ "RB", "r3.m41t81.reg09.rb",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a_afe,
{ "AFE", "r3.m41t81.reg0a.afe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a_sqwe,
{ "SQWE", "r3.m41t81.reg0a.sqwe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a_abe,
{ "ABE", "r3.m41t81.reg0a.abe",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a_10monthalm,
{ "10 Month Alarm", "r3.m41t81.reg0a.10monthalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0a_1monthalm,
{ "1 Month Alarm", "r3.m41t81.reg0a.1monthalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0b_rpt5,
{ "RPT5", "r3.m41t81.reg0b.rpt5",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0b_rpt4,
{ "RPT4", "r3.m41t81.reg0b.rpt4",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0b_10dayalm,
{ "10 Day Alarm", "r3.m41t81.reg0b.10dayalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0b_1dayalm,
{ "1 Day Alarm", "r3.m41t81.reg0b.1dayalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0c_rpt3,
{ "RPT3", "r3.m41t81.reg0c.rpt3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0c_ht,
{ "HT", "r3.m41t81.reg0c.ht",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0c_10houralm,
{ "10 Hour Alarm", "r3.m41t81.reg0c.10houralm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0c_1houralm,
{ "1 Hour Alarm", "r3.m41t81.reg0c.1houralm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0d_rpt2,
{ "RPT2", "r3.m41t81.reg0d.rpt2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0d_10minalm,
{ "10 Min Alarm", "r3.m41t81.reg0d.10minalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0d_1minalm,
{ "1 Min Alarm", "r3.m41t81.reg0d.1minalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0e_rpt1,
{ "RPT1", "r3.m41t81.reg0e.rpt1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0e_10secalm,
{ "10 Sec Alarm", "r3.m41t81.reg0e.10secalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0e_1secalm,
{ "1 Sec Alarm", "r3.m41t81.reg0e.1secalm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0f_wdf,
{ "WDF", "r3.m41t81.reg0f.wdf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0f_af,
{ "AF", "r3.m41t81.reg0f.af",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg0f_notused,
{ "(not used)", "r3.m41t81.reg0f.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg10_notused,
{ "(not used)", "r3.m41t81.reg10.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg11_notused,
{ "(not used)", "r3.m41t81.reg11.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg12_notused,
{ "(not used)", "r3.m41t81.reg12.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg13_rs,
{ "RS", "r3.m41t81.reg13.rs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_dumpm41t81_reg13_notused,
{ "(not used)", "r3.m41t81.reg13.notused",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_debuglog_recordnumber,
{ "Record Number", "r3.debuglog.recordnumber",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_debuglog_flags,
{ "Flags", "r3.debuglog.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_debuglog_tick,
{ "Tick", "r3.debuglog.tick",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtype,
{ "Upstream Field", "r3.manageuser",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypelength,
{ "Field Length", "r3.manageuser.length",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypetype,
{ "Field Type", "r3.manageuser.type",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_adduserparamtypenames_ext, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_r3_adduserparamtypedatalen,
{ "Data Length", "r3.manageuser.datalen",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypeerror,
{ "Error", "r3.manageuser.error",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_DISPOSITION],
{ "Disposition", "r3.manageuser.disposition",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_dispositionnames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_USERNO],
{ "User Number", "r3.manageuser.usernumber",
FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_ACCESSALWAYS],
{ "Access Always", "r3.manageuser.accessalways",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_ACCESSMODE],
{ "Access Mode", "r3.manageuser.accessmode",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_accessmodenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_CACHED],
{ "Cached", "r3.manageuser.cached",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_USERTYPE],
{ "User Type", "r3.manageuser.usertype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_usertypenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_PRIMARYFIELD],
{ "Primary Field", "r3.manageuser.primaryfield",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_PRIMARYFIELDTYPE],
{ "Primary Field Type", "r3.manageuser.primaryfieldtype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_AUXFIELD],
{ "Aux Field", "r3.manageuser.auxfield",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_AUXFIELDTYPE],
{ "Aux Field Type", "r3.manageuser.auxfieldtype",
FT_UINT8, BASE_DEC_HEX|BASE_EXT_STRING, &r3_ppmisourcenames_ext, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_USECOUNT],
{ "Use Count", "r3.manageuser.usecount",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_EXCEPTIONGROUP],
{ "Exception Group", "r3.manageuser.exceptiongroup",
FT_UINT8, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_EXPIREON],
{ "Expire On", "r3.manageuser.expireon",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_r3_adduserparamtypearray [ADDUSERPARAMTYPE_TIMEZONE],
{ "Timezone", "r3.manageuser.timezone",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett [] =
{
&ett_r3,
&ett_r3header,
&ett_r3tail,
&ett_r3payload,
&ett_r3cmd,
&ett_r3configitem,
&ett_r3upstreamcommand,
&ett_r3upstreamfield,
&ett_r3timezone,
&ett_r3expireon,
&ett_r3datetime,
&ett_r3eventlogrecord,
&ett_r3declinedlogrecord,
&ett_r3alarmlogrecord,
&ett_r3debugmsg,
&ett_r3defineexceptionstartdate,
&ett_r3defineexceptionenddate,
&ett_r3defineexceptiongroupbits,
&ett_r3definecalendarmonth [1],
&ett_r3definecalendarmonth [2],
&ett_r3definecalendarmonth [3],
&ett_r3definecalendarmonth [4],
&ett_r3definecalendarmonth [5],
&ett_r3definecalendarmonth [6],
&ett_r3definecalendarmonth [7],
&ett_r3definecalendarmonth [8],
&ett_r3definecalendarmonth [9],
&ett_r3definecalendarmonth [10],
&ett_r3definecalendarmonth [11],
&ett_r3definecalendarmonth [12],
&ett_r3definetimezonestarttime,
&ett_r3definetimezoneendtime,
&ett_r3definetimezonedaymap,
&ett_r3eventlogdumpstarttime,
&ett_r3eventlogdumpendtime,
&ett_r3declinedlogdumpstarttime,
&ett_r3declinedlogdumpendtime,
&ett_r3alarmlogdumpstarttime,
&ett_r3alarmlogdumpendtime,
&ett_r3clearnvram,
&ett_r3filters,
&ett_r3alarmlist,
&ett_r3alarmcfg,
&ett_r3commandmfg,
&ett_r3serialnumber,
&ett_r3iopins,
&ett_r3checksumresults,
&ett_r3checksumresultsfield,
&ett_r3forceoptions,
&ett_r3peekpoke,
&ett_r3downloadfirmware,
&ett_r3capabilities,
&ett_r3lockstate,
&ett_r3mortisestatelog,
&ett_r3timerchain,
&ett_r3taskflags,
&ett_r3taskflagsentry,
&ett_r3checkpointlog,
&ett_r3checkpointlogentry,
&ett_r3cpuregisters,
&ett_r3cpuregister,
&ett_r3m41t81registers,
&ett_r3m41t81register,
&ett_r3debuglogrecord,
&ett_r3setdatetime,
&ett_r3manageuser
};
static ei_register_info ei[] = {
{ &ei_r3_malformed_length, { "r3.malformed_length", PI_MALFORMED, PI_ERROR, "Malformed length", EXPFILL }},
{ &ei_r3_reserved_upstream_command_value, { "r3.reserved_upstream_command_value", PI_UNDECODED, PI_WARN, "\"Reserved\" Upstream Command value", EXPFILL }},
{ &ei_r3_mfgfield, { "r3.mfgfield.field.unknown", PI_UNDECODED, PI_WARN, "Unknown manufacturing command value", EXPFILL }},
{ &ei_r3_mfgfield_too_many_adc_values, { "r3.mfgfield.too_many_adc_values", PI_PROTOCOL, PI_WARN, "MFG Field: too many adc values", EXPFILL }},
{ &ei_r3_peekpoke_operation, { "r3.peekpoke.operation.unknown", PI_UNDECODED, PI_WARN, "Unknown peekpoke operation value", EXPFILL }},
{ &ei_r3_response_hasdata_octet_1, { "r3.response_hasdata.octet_1_not_cmd_response", PI_PROTOCOL, PI_WARN, "Octet 1 not CMD_RESPONSE", EXPFILL }},
{ &ei_r3_response_hasdata_octet_2, { "r3.response_hasdata.octet_2_not_response_hasdata", PI_PROTOCOL, PI_WARN, "Octet 2 not RESPONSE_HASDATA", EXPFILL }},
{ &ei_r3_response_hasdata_octet_3, { "r3.response_hasdata.octet_3_ge_upstreamcommand_last", PI_PROTOCOL, PI_WARN, "Octet 3 >= UPSTREAMCOMMAND_LAST", EXPFILL }},
{ &ei_r3_firmwaredownload_action, { "r3.firmwaredownload.action.unknown", PI_PROTOCOL, PI_WARN, "Unknown Firmware download action", EXPFILL }},
{ &ei_r3_cmd_downloadfirmwaretimeout, { "r3.command.downloadfirmwaretimeout", PI_UNDECODED, PI_WARN, "Download Firmware Timeout", EXPFILL }},
{ &ei_r3_unknown_command_value, { "r3.command.unknown", PI_UNDECODED, PI_WARN, "Unknown command value", EXPFILL }},
};
expert_module_t* expert_r3;
proto_r3 = proto_register_protocol ("Assa Abloy R3", "R3", "r3");
new_register_dissector ("r3", dissect_r3, proto_r3);
proto_register_field_array (proto_r3, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_r3 = expert_register_protocol(proto_r3);
expert_register_field_array(expert_r3, ei, array_length(ei));
}
void proto_reg_handoff_r3 (void)
{
dissector_handle_t r3_handle = find_dissector ("r3");
dissector_add_uint ("tcp.port", 2571, r3_handle);
dissector_add_uint ("tcp.port", 8023, r3_handle);
}
