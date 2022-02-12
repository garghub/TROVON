static void
s7comm_get_timestring_from_s7time(tvbuff_t *tvb, guint offset, char *str, gint max)
{
guint16 days;
guint32 day_msec;
struct tm *mt;
time_t t;
day_msec = tvb_get_ntohl(tvb, offset);
days = tvb_get_ntohs(tvb, offset + 4);
t = 441763200L;
t += days * (24*60*60);
t += day_msec / 1000;
mt = gmtime(&t);
str[0] = '\0';
if (mt != NULL) {
g_snprintf(str, max, "%s %2d, %d %02d:%02d:%02d.%03d", mon_names[mt->tm_mon], mt->tm_mday,
mt->tm_year + 1900, mt->tm_hour, mt->tm_min, mt->tm_sec, day_msec % 1000);
}
}
static guint8
s7comm_guint8_from_bcd(guint8 i)
{
return 10 * (i /16) + (i % 16);
}
static guint32
s7comm_add_timestamp_to_tree(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset,
gboolean append_text)
{
guint8 timestamp[10];
guint8 i;
guint8 tmp;
guint8 year_org;
guint16 msec;
nstime_t tv;
proto_item *item = NULL;
proto_item *time_tree = NULL;
struct tm mt;
for (i = 0;i < 9; i++) {
timestamp[i] = s7comm_guint8_from_bcd(tvb_get_guint8(tvb, offset + i));
}
tmp = tvb_get_guint8(tvb, offset + 9) >> 4;
timestamp[9] = s7comm_guint8_from_bcd(tmp);
msec = (guint16)timestamp[8] * 10 + (guint16)timestamp[9];
year_org = timestamp[1];
if (timestamp[2] < 89) {
timestamp[1] = 20;
}
mt.tm_year = (timestamp[1] * 100 + timestamp[2]) - 1900;
mt.tm_mon = timestamp[3] - 1;
mt.tm_mday = timestamp[4];
mt.tm_hour = timestamp[5];
mt.tm_min = timestamp[6];
mt.tm_sec = timestamp[7];
mt.tm_isdst = -1;
tv.secs = mktime(&mt);
tv.nsecs = msec * 1000000;
item = proto_tree_add_time_format(tree, hf_s7comm_data_ts, tvb, offset, 10, &tv,
"S7 Timestamp: %s %2d, %d %02d:%02d:%02d.%03d", mon_names[mt.tm_mon], mt.tm_mday,
mt.tm_year + 1900, mt.tm_hour, mt.tm_min, mt.tm_sec,
msec);
time_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_reserved, tvb, offset, 1, timestamp[0]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_year1, tvb, offset, 1, year_org);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_year2, tvb, offset, 1, timestamp[2]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_month, tvb, offset, 1, timestamp[3]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_day, tvb, offset, 1, timestamp[4]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_hour, tvb, offset, 1, timestamp[5]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_minute, tvb, offset, 1, timestamp[6]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_second, tvb, offset, 1, timestamp[7]);
offset += 1;
proto_tree_add_uint(time_tree, hf_s7comm_data_ts_millisecond, tvb, offset, 2, msec);
proto_tree_add_item(time_tree, hf_s7comm_data_ts_weekday, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (append_text == TRUE) {
proto_item_append_text(tree, "(Timestamp: %s %2d, %d %02d:%02d:%02d.%03d)", mon_names[mt.tm_mon], mt.tm_mday,
mt.tm_year + 1900, mt.tm_hour, mt.tm_min, mt.tm_sec,
msec);
}
return offset;
}
static void
make_registerflag_string(gchar *str, guint8 flags, gint max)
{
g_strlcpy(str, "", max);
if (flags & 0x01) g_strlcat(str, "STW, ", max);
if (flags & 0x02) g_strlcat(str, "ACCU1, ", max);
if (flags & 0x04) g_strlcat(str, "ACCU2, ", max);
if (flags & 0x08) g_strlcat(str, "AR1, ", max);
if (flags & 0x10) g_strlcat(str, "AR2, ", max);
if (flags & 0x20) g_strlcat(str, "DB1, ", max);
if (flags & 0x40) g_strlcat(str, "DB2, ", max);
if (strlen(str) > 2)
str[strlen(str) - 2 ] = '\0';
}
static guint32
s7comm_decode_param_item(tvbuff_t *tvb,
guint32 offset,
proto_tree *sub_tree,
guint8 item_no)
{
guint32 a_address = 0;
guint32 bytepos = 0;
guint32 bitpos = 0;
guint8 t_size = 0;
guint16 len = 0;
guint16 db = 0;
guint16 i;
guint8 area = 0;
proto_item *item = NULL;
proto_tree *item_tree = NULL;
proto_tree *sub_item_tree = NULL;
proto_item *address_item = NULL;
proto_tree *address_item_tree = NULL;
guint8 number_of_areas = 0;
guint8 var_spec_type = 0;
guint8 var_spec_length = 0;
guint8 var_spec_syntax_id = 0;
proto_item *sub_item = NULL;
guint16 tia_var_area1 = 0;
guint16 tia_var_area2 = 0;
guint8 tia_lid_flags = 0;
guint32 tia_value = 0;
guint8 nck_area = 0;
guint8 nck_unit = 0;
guint16 nck_column = 0;
guint16 nck_line = 0;
guint8 nck_module = 0;
var_spec_type = tvb_get_guint8(tvb, offset);
var_spec_length = tvb_get_guint8(tvb, offset + 1);
var_spec_syntax_id = tvb_get_guint8(tvb, offset + 2);
item = proto_tree_add_item(sub_tree, hf_s7comm_param_item, tvb, offset, var_spec_length + 2, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_param_item);
proto_item_append_text(item, " [%d]:", item_no + 1);
proto_tree_add_item(item_tree, hf_s7comm_item_varspec, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_s7comm_item_varspec_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_s7comm_item_syntax_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (var_spec_type == 0x12 && var_spec_length == 10 && var_spec_syntax_id == S7COMM_SYNTAXID_S7ANY) {
t_size = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_item_transport_size, tvb, offset, 1, t_size);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_item_length, tvb, offset, 2, len);
offset += 2;
db = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_item_db, tvb, offset, 2, db);
offset += 2;
area = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_item_area, tvb, offset, 1, area);
offset += 1;
a_address = tvb_get_ntoh24(tvb, offset);
address_item = proto_tree_add_uint(item_tree, hf_s7comm_item_address, tvb, offset, 3, a_address);
address_item_tree = proto_item_add_subtree(address_item, ett_s7comm_item_address);
bytepos = a_address / 8;
bitpos = a_address % 8;
switch (area) {
case (S7COMM_AREA_P):
proto_item_append_text(item_tree, " (P");
break;
case (S7COMM_AREA_INPUTS):
proto_item_append_text(item_tree, " (I");
break;
case (S7COMM_AREA_OUTPUTS):
proto_item_append_text(item_tree, " (Q");
break;
case (S7COMM_AREA_FLAGS):
proto_item_append_text(item_tree, " (M");
break;
case (S7COMM_AREA_DB):
proto_item_append_text(item_tree, " (DB%d.DBX", db);
break;
case (S7COMM_AREA_DI):
proto_item_append_text(item_tree, " (DI%d.DIX", db);
break;
case (S7COMM_AREA_LOCAL):
proto_item_append_text(item_tree, " (L");
break;
case (S7COMM_AREA_COUNTER):
proto_item_append_text(item_tree, " (C");
break;
case (S7COMM_AREA_TIMER):
proto_item_append_text(item_tree, " (T");
break;
default:
proto_item_append_text(item_tree, " (unknown area");
break;
}
if (area == S7COMM_AREA_TIMER || area == S7COMM_AREA_COUNTER) {
proto_item_append_text(item_tree, " %d)", a_address);
proto_tree_add_uint(address_item_tree, hf_s7comm_item_address_nr, tvb, offset, 3, a_address);
} else {
proto_tree_add_uint(address_item_tree, hf_s7comm_item_address_byte, tvb, offset, 3, a_address);
proto_tree_add_uint(address_item_tree, hf_s7comm_item_address_bit, tvb, offset, 3, a_address);
proto_item_append_text(item_tree, " %d.%d %s %d)",
bytepos, bitpos, val_to_str(t_size, item_transportsizenames, "Unknown transport size: 0x%02x"), len);
}
offset += 3;
} else if (var_spec_type == 0x12 && var_spec_length >= 7 && var_spec_syntax_id == S7COMM_SYNTAXID_DBREAD) {
number_of_areas = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_item_dbread_numareas, tvb, offset, 1, number_of_areas);
proto_item_append_text(item_tree, " (%d Data-Areas of Syntax-Id DBREAD)", number_of_areas);
offset += 1;
for (i = 1; i <= number_of_areas; i++) {
sub_item = proto_tree_add_item(item_tree, hf_s7comm_param_subitem, tvb, offset, 5, ENC_NA);
sub_item_tree = proto_item_add_subtree(sub_item, ett_s7comm_param_subitem);
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_item_tree, hf_s7comm_item_dbread_length, tvb, offset, 1, len);
offset += 1;
db = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(sub_item_tree, hf_s7comm_item_dbread_db, tvb, offset, 2, db);
offset += 2;
bytepos = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(sub_item_tree, hf_s7comm_item_dbread_startadr, tvb, offset, 2, bytepos);
offset += 2;
proto_item_append_text(sub_item, " [%d]: (DB%d.DBB %d BYTE %d)", i, db, bytepos, len);
}
} else if (var_spec_type == 0x12 && var_spec_length >= 14 && var_spec_syntax_id == S7COMM_SYNTAXID_1200SYM) {
proto_item_append_text(item_tree, " 1200 symbolic address");
proto_tree_add_item(item_tree, hf_s7comm_tia1200_item_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tia_var_area1 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(item_tree, hf_s7comm_tia1200_item_area1, tvb, offset, 2, tia_var_area1);
offset += 2;
tia_var_area2 = tvb_get_ntohs(tvb, offset);
if (tia_var_area1 == S7COMM_TIA1200_VAR_ITEM_AREA1_IQMCT) {
proto_tree_add_uint(item_tree, hf_s7comm_tia1200_item_area2, tvb, offset, 2, tia_var_area2);
proto_item_append_text(item_tree, " - Accessing %s", val_to_str(tia_var_area2, tia1200_var_item_area2_names, "Unknown IQMCT Area: 0x%04x"));
offset += 2;
} else if (tia_var_area1 == S7COMM_TIA1200_VAR_ITEM_AREA1_DB) {
proto_tree_add_uint(item_tree, hf_s7comm_tia1200_item_dbnumber, tvb, offset, 2, tia_var_area2);
proto_item_append_text(item_tree, " - Accessing DB%d", tia_var_area2);
offset += 2;
} else {
proto_tree_add_uint(item_tree, hf_s7comm_tia1200_item_area2unknown, tvb, offset, 2, tia_var_area2);
proto_item_append_text(item_tree, " - Unknown area specification");
offset += 2;
}
proto_tree_add_item(item_tree, hf_s7comm_tia1200_item_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < (var_spec_length - 10) / 4; i++) {
sub_item = proto_tree_add_item(item_tree, hf_s7comm_tia1200_substructure_item, tvb, offset, 4, ENC_NA);
sub_item_tree = proto_item_add_subtree(sub_item, ett_s7comm_param_subitem);
tia_lid_flags = tvb_get_guint8(tvb, offset) >> 4;
proto_tree_add_item(sub_item_tree, hf_s7comm_tia1200_var_lid_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
tia_value = tvb_get_ntohl(tvb, offset) & 0x0fffffff;
proto_item_append_text(sub_item, " [%d]: %s, Value: %u", i + 1,
val_to_str(tia_lid_flags, tia1200_var_lid_flag_names, "Unknown flags: 0x%02x"),
tia_value
);
proto_tree_add_item(sub_item_tree, hf_s7comm_tia1200_item_value, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
} else if (var_spec_type == 0x12 && var_spec_length == 8 && var_spec_syntax_id == S7COMM_SYNTAXID_NCK) {
area = tvb_get_guint8(tvb, offset);
nck_area = area >> 5;
nck_unit = area & 0x1f;
proto_tree_add_item(item_tree, hf_s7comm_item_nck_areaunit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(item_tree, hf_s7comm_item_nck_area, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(item_tree, hf_s7comm_item_nck_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
nck_column = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(item_tree, hf_s7comm_item_nck_column, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
nck_line = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(item_tree, hf_s7comm_item_nck_line, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
nck_module = tvb_get_guint8(tvb, offset);
proto_tree_add_item(item_tree, hf_s7comm_item_nck_module, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_s7comm_item_nck_linecount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_item_append_text(item_tree, " (NCK Area:%d Unit:%d Column:%d Line:%d Module:0x%02x)",
nck_area, nck_unit, nck_column, nck_line, nck_module);
}
else {
offset += var_spec_length - 1;
proto_item_append_text(item_tree, " Unknown variable specification");
}
return offset;
}
static guint32
s7comm_decode_pdu_setup_communication(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_param_setup_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_param_maxamq_calling, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_param_maxamq_called, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_param_neg_pdu_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static guint32
s7comm_decode_response_write_data(tvbuff_t *tvb,
proto_tree *tree,
guint8 item_count,
guint32 offset)
{
guint8 ret_val = 0;
guint8 i = 0;
proto_item *item = NULL;
proto_tree *item_tree = NULL;
for (i = 1; i <= item_count; i++) {
ret_val = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_s7comm_data_item, tvb, offset, 1, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
proto_item_append_text(item, " [%d]: (%s)", i, val_to_str(ret_val, s7comm_item_return_valuenames, "Unknown code: 0x%02x"));
proto_tree_add_uint(item_tree, hf_s7comm_data_returncode, tvb, offset, 1, ret_val);
offset += 1;
}
return offset;
}
static guint32
s7comm_decode_response_read_data(tvbuff_t *tvb,
proto_tree *tree,
guint8 item_count,
guint32 offset)
{
guint8 ret_val = 0;
guint8 tsize = 0;
guint16 len = 0, len2 = 0;
guint16 head_len = 4;
guint8 i = 0;
proto_item *item = NULL;
proto_tree *item_tree = NULL;
for (i = 1; i <= item_count; i++) {
ret_val = tvb_get_guint8(tvb, offset);
if (ret_val == S7COMM_ITEM_RETVAL_RESERVED ||
ret_val == S7COMM_ITEM_RETVAL_DATA_OK ||
ret_val == S7COMM_ITEM_RETVAL_DATA_ERR
) {
tsize = tvb_get_guint8(tvb, offset + 1);
len = tvb_get_ntohs(tvb, offset + 2);
if (tsize == S7COMM_DATA_TRANSPORT_SIZE_BBIT ||
tsize == S7COMM_DATA_TRANSPORT_SIZE_BBYTE ||
tsize == S7COMM_DATA_TRANSPORT_SIZE_BINT
) {
if (len % 8) {
len /= 8;
len = len + 1;
} else {
len /= 8;
}
}
if ((len % 2) && (i < item_count)) {
len2 = len + 1;
} else {
len2 = len;
}
}
item = proto_tree_add_item(tree, hf_s7comm_data_item, tvb, offset, len + head_len, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
proto_item_append_text(item, " [%d]: (%s)", i, val_to_str(ret_val, s7comm_item_return_valuenames, "Unknown code: 0x%02x"));
proto_tree_add_uint(item_tree, hf_s7comm_data_returncode, tvb, offset, 1, ret_val);
proto_tree_add_uint(item_tree, hf_s7comm_data_transport_size, tvb, offset + 1, 1, tsize);
proto_tree_add_uint(item_tree, hf_s7comm_data_length, tvb, offset + 2, 2, len);
offset += head_len;
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK || ret_val == S7COMM_ITEM_RETVAL_RESERVED) {
proto_tree_add_item(item_tree, hf_s7comm_readresponse_data, tvb, offset, len, ENC_NA);
offset += len;
if (len != len2) {
proto_tree_add_item(item_tree, hf_s7comm_data_fillbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
}
return offset;
}
static guint32
s7comm_decode_plc_controls_param_hex28(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
guint32 offset)
{
guint16 len;
guint8 count;
guint8 i;
guint8 *str;
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_part1_unknown, tvb, offset, 7, ENC_NA);
offset += 7;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_plccontrol_part1_len, tvb, offset, 2, len);
offset += 2;
if (len == 2) {
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_argument, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset +=2;
} else if (len > 2) {
count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_plccontrol_block_cnt, tvb, offset, 1, count);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_part1_unknown2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 0; i < count; i++) {
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_block_unknown, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset +=1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type:[%s]", val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_block_num, tvb, offset, 5, ENC_ASCII|ENC_NA);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 5, ENC_ASCII);
col_append_fstr(pinfo->cinfo, COL_INFO, " No.:[%s]", str);
offset += 5;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_dest_filesys, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
}
}
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_plccontrol_part2_len, tvb, offset, 1, len);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_pi_service, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
return offset;
}
static guint32
s7comm_decode_plc_controls_param_hex29(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
guint8 len;
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_part1_unknown, tvb, offset, 5, ENC_NA);
offset += 5;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_plccontrol_part2_len, tvb, offset, 1, len);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_plccontrol_pi_service, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
return offset;
}
static guint32
s7comm_decode_plc_controls_param_hex1x(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
guint16 plength,
guint32 offset)
{
guint8 len;
guint8 function;
guint8 *str;
function = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_unknown1, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_errorcode, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_unknown1, tvb, offset, 4, ENC_NA);
offset += 4;
if (plength <= 8) {
return offset;
}
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_blockcontrol_part1_len, tvb, offset, 1, len);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_file_ident, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_block_unknown, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type:[%s]", val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
offset += 1;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 5, ENC_ASCII);
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_block_num, tvb, offset, 5, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " No.:[%s]", str);
offset += 5;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_dest_filesys, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
if (function == S7COMM_FUNCREQUESTDOWNLOAD && plength > 18) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_s7comm_data_blockcontrol_part2_len, tvb, offset, 1, len);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_part2_unknown, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_loadmem_len, tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_s7comm_data_blockcontrol_mc7code_len, tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
}
return offset;
}
static guint32
s7comm_decode_ud_prog_reqdiagdata(tvbuff_t *tvb,
proto_tree *data_tree,
guint8 subfunc,
guint32 offset)
{
proto_item *item = NULL;
proto_tree *item_tree = NULL;
guint16 line_nr;
guint16 line_cnt;
guint16 ask_size;
guint16 item_size = 4;
guint8 registerflags;
gchar str_flags[80];
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_askheadersize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ask_size = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_diagdata_req_asksize, tvb, offset, 2, ask_size);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_unknown, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_answersize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_unknown, tvb, offset, 13, ENC_NA);
offset += 13;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_block_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_startaddr_awl, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_saz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
if (subfunc == 0x13) {
line_cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_diagdata_req_number_of_lines, tvb, offset, 2, line_cnt);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_diagdata_req_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
} else {
line_cnt = (ask_size - 2) / 2;
}
proto_tree_add_bitmask(data_tree, tvb, offset, hf_s7comm_diagdata_registerflag,
ett_s7comm_diagdata_registerflag, s7comm_diagdata_registerflag_fields, ENC_BIG_ENDIAN);
offset += 1;
if (subfunc == 0x13) {
item_size = 4;
} else {
item_size = 2;
}
for (line_nr = 0; line_nr < line_cnt; line_nr++) {
item = proto_tree_add_item(data_tree, hf_s7comm_data_item, tvb, offset, item_size, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
if (subfunc == 0x13) {
proto_tree_add_item(item_tree, hf_s7comm_diagdata_req_line_address, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_tree_add_item(item_tree, hf_s7comm_diagdata_req_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
registerflags = tvb_get_guint8(tvb, offset);
make_registerflag_string(str_flags, registerflags, sizeof(str_flags));
proto_item_append_text(item, " [%d]: (%s)", line_nr+1, str_flags);
proto_tree_add_bitmask(item_tree, tvb, offset, hf_s7comm_diagdata_registerflag,
ett_s7comm_diagdata_registerflag, s7comm_diagdata_registerflag_fields, ENC_BIG_ENDIAN);
offset += 1;
}
return offset;
}
static guint32
s7comm_decode_ud_prog_vartab_req_item(tvbuff_t *tvb,
guint32 offset,
proto_tree *sub_tree,
guint16 item_no)
{
guint32 bytepos = 0;
guint16 len = 0;
guint16 db = 0;
guint8 area = 0;
proto_item *item = NULL;
item = proto_tree_add_item(sub_tree, hf_s7comm_param_item, tvb, offset, 6, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_s7comm_param_item);
proto_item_append_text(item, " [%d]:", item_no + 1);
area = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree, hf_s7comm_vartab_req_memory_area, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_tree, hf_s7comm_vartab_req_repetition_factor, tvb, offset, 1, len);
offset += 1;
db = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(sub_tree, hf_s7comm_vartab_req_db_number, tvb, offset, 2, db);
offset += 2;
bytepos = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(sub_tree, hf_s7comm_vartab_req_startaddress, tvb, offset, 2, bytepos);
offset += 2;
switch (area) {
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_MB:
proto_item_append_text(sub_tree, " (M%d.0 BYTE %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_MW:
proto_item_append_text(sub_tree, " (M%d.0 WORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_MD:
proto_item_append_text(sub_tree, " (M%d.0 DWORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_EB:
proto_item_append_text(sub_tree, " (I%d.0 BYTE %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_EW:
proto_item_append_text(sub_tree, " (I%d.0 WORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_ED:
proto_item_append_text(sub_tree, " (I%d.0 DWORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_AB:
proto_item_append_text(sub_tree, " (Q%d.0 BYTE %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_AW:
proto_item_append_text(sub_tree, " (Q%d.0 WORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_AD:
proto_item_append_text(sub_tree, " (Q%d.0 DWORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_PEB:
proto_item_append_text(sub_tree, " (PI%d.0 BYTE %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_PEW:
proto_item_append_text(sub_tree, " (PI%d.0 WORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_PED:
proto_item_append_text(sub_tree, " (PI%d.0 DWORD %d)", bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_DBB:
proto_item_append_text(sub_tree, " (DB%d.DX%d.0 BYTE %d)", db, bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_DBW:
proto_item_append_text(sub_tree, " (DB%d.DX%d.0 WORD %d)", db, bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_DBD:
proto_item_append_text(sub_tree, " (DB%d.DX%d.0 DWORD %d)", db, bytepos, len);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_T:
if (len >1)
proto_item_append_text(sub_tree, " (T %d..%d)", bytepos, bytepos + len - 1);
else
proto_item_append_text(sub_tree, " (T %d)", bytepos);
break;
case S7COMM_UD_SUBF_PROG_VARTAB_AREA_C:
if (len >1)
proto_item_append_text(sub_tree, " (C %d..%d)", bytepos, bytepos + len - 1);
else
proto_item_append_text(sub_tree, " (C %d)", bytepos);
break;
}
return offset;
}
static guint32
s7comm_decode_ud_prog_vartab_res_item(tvbuff_t *tvb,
guint32 offset,
proto_tree *sub_tree,
guint16 item_no)
{
guint16 len = 0, len2 = 0;
guint8 ret_val = 0;
guint8 tsize = 0;
guint8 head_len = 4;
proto_item *item = NULL;
ret_val = tvb_get_guint8(tvb, offset);
if (ret_val == S7COMM_ITEM_RETVAL_RESERVED ||
ret_val == S7COMM_ITEM_RETVAL_DATA_OK ||
ret_val == S7COMM_ITEM_RETVAL_DATA_ERR
) {
tsize = tvb_get_guint8(tvb, offset + 1);
len = tvb_get_ntohs(tvb, offset + 2);
if (tsize == S7COMM_DATA_TRANSPORT_SIZE_BBYTE || tsize == S7COMM_DATA_TRANSPORT_SIZE_BINT) {
len /= 8;
}
if (len % 2) {
len2 = len + 1;
}else {
len2 = len;
}
}
item = proto_tree_add_item(sub_tree, hf_s7comm_data_item, tvb, offset, len + head_len, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
proto_item_append_text(item, " [%d]: (%s)", item_no + 1, val_to_str(ret_val, s7comm_item_return_valuenames, "Unknown code: 0x%02x"));
proto_tree_add_uint(sub_tree, hf_s7comm_data_returncode, tvb, offset, 1, ret_val);
proto_tree_add_uint(sub_tree, hf_s7comm_data_transport_size, tvb, offset + 1, 1, tsize);
proto_tree_add_uint(sub_tree, hf_s7comm_data_length, tvb, offset + 2, 2, len);
offset += head_len;
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK || ret_val == S7COMM_ITEM_RETVAL_RESERVED) {
proto_tree_add_item(sub_tree, hf_s7comm_readresponse_data, tvb, offset, len, ENC_NA);
offset += len;
if (len != len2) {
proto_tree_add_item(sub_tree, hf_s7comm_data_fillbyte, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
return offset;
}
static guint32
s7comm_decode_ud_security_subfunc(tvbuff_t *tvb,
proto_tree *data_tree,
guint16 dlength,
guint32 offset)
{
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
offset += dlength;
return offset;
}
static guint32
s7comm_decode_ud_pbc_subfunc(tvbuff_t *tvb,
proto_tree *data_tree,
guint16 dlength,
guint32 offset)
{
proto_tree_add_item(data_tree, hf_s7comm_item_varspec, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_item_varspec_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_item_syntax_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_pbc_unknown, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_pbc_r_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dlength = dlength - 4 - 8;
if (dlength > 0) {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength, ENC_NA);
offset += dlength;
}
return offset;
}
static guint32
s7comm_decode_ud_time_subfunc(tvbuff_t *tvb,
proto_tree *data_tree,
guint8 type,
guint8 subfunc,
guint8 ret_val,
guint16 dlength,
guint32 offset)
{
gboolean know_data = FALSE;
switch (subfunc) {
case S7COMM_UD_SUBF_TIME_READ:
case S7COMM_UD_SUBF_TIME_READF:
if (type == S7COMM_UD_TYPE_RES) {
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK) {
proto_item_append_text(data_tree, ": ");
offset = s7comm_add_timestamp_to_tree(tvb, data_tree, offset, TRUE);
}
know_data = TRUE;
}
break;
case S7COMM_UD_SUBF_TIME_SET:
case S7COMM_UD_SUBF_TIME_SET2:
if (type == S7COMM_UD_TYPE_REQ) {
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK) {
proto_item_append_text(data_tree, ": ");
offset = s7comm_add_timestamp_to_tree(tvb, data_tree, offset, TRUE);
}
know_data = TRUE;
}
break;
default:
break;
}
if (know_data == FALSE && dlength > 4) {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
offset += dlength;
}
return offset;
}
static guint32
s7comm_decode_ud_block_subfunc(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *data_tree,
guint8 type,
guint8 subfunc,
guint8 ret_val,
guint8 tsize,
guint16 len,
guint16 dlength,
guint32 offset)
{
guint16 count;
guint16 i;
guint8 *pBlocknumber;
guint16 blocknumber;
guint8 blocktype;
gboolean know_data = FALSE;
proto_item *item = NULL;
proto_tree *item_tree = NULL;
char str_timestamp[30];
char str_number[10];
char str_version[10];
switch (subfunc) {
case S7COMM_UD_SUBF_BLOCK_LIST:
if (type == S7COMM_UD_TYPE_REQ) {
} else if (type == S7COMM_UD_TYPE_RES) {
count = len / 4;
for(i = 0; i < count; i++) {
item = proto_tree_add_item(data_tree, hf_s7comm_data_item, tvb, offset, 4, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
offset += 1;
proto_item_append_text(item, " [%d]: (Block type %s)", i+1, val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
proto_tree_add_item(item_tree, hf_s7comm_ud_blockinfo_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_s7comm_ud_blockinfo_block_cnt, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
know_data = TRUE;
}
break;
case S7COMM_UD_SUBF_BLOCK_LISTTYPE:
if (type == S7COMM_UD_TYPE_REQ) {
if (tsize != S7COMM_DATA_TRANSPORT_SIZE_NULL) {
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type:[%s]",
val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
proto_item_append_text(data_tree, ": (%s)",
val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
offset += 1;
}
know_data = TRUE;
}else if (type == S7COMM_UD_TYPE_RES) {
if (tsize != S7COMM_DATA_TRANSPORT_SIZE_NULL) {
count = len / 4;
for(i = 0; i < count; i++) {
item = proto_tree_add_item(data_tree, hf_s7comm_data_item, tvb, offset, 4, ENC_NA);
item_tree = proto_item_add_subtree(item, ett_s7comm_data_item);
proto_item_append_text(item, " [%d]: (Block number %d)", i+1, tvb_get_ntohs(tvb, offset));
proto_tree_add_item(item_tree, hf_s7comm_ud_blockinfo_block_num, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(item_tree, hf_s7comm_ud_blockinfo_block_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(item_tree, hf_s7comm_ud_blockinfo_block_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
know_data = TRUE;
}
break;
case S7COMM_UD_SUBF_BLOCK_BLOCKINFO:
if (type == S7COMM_UD_TYPE_REQ) {
if (tsize != S7COMM_DATA_TRANSPORT_SIZE_NULL) {
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(data_tree, ": (Block type: %s",
val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
col_append_fstr(pinfo->cinfo, COL_INFO, " Type:[%s]",
val_to_str(tvb_get_guint8(tvb, offset), blocktype_names, "Unknown Block type: 0x%02x"));
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_block_num_ascii, tvb, offset, 5, ENC_ASCII|ENC_NA);
pBlocknumber = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 5, ENC_ASCII);
col_append_fstr(pinfo->cinfo, COL_INFO, " No.:[%s]", pBlocknumber);
proto_item_append_text(data_tree, ", Number: %s)", pBlocknumber);
offset += 5;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_filesys, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
}
know_data = TRUE;
}else if (type == S7COMM_UD_TYPE_RES) {
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK) {
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_const1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_infolength, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_unknown2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_const3, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_bitmask(data_tree, tvb, offset, hf_s7comm_userdata_blockinfo_flags,
ett_s7comm_userdata_blockinfo_flags, s7comm_userdata_blockinfo_flags_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_block_lang, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
blocktype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_subblk_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Type:[%s]",
val_to_str(blocktype, subblktype_names, "Unknown Subblk type: 0x%02x"));
proto_item_append_text(data_tree, ": (Subblk type: %s",
val_to_str(blocktype, subblktype_names, "Unknown Subblk type: 0x%02x"));
offset += 1;
blocknumber = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_ud_blockinfo_block_num, tvb, offset, 2, blocknumber);
g_snprintf(str_number, sizeof(str_number), "%05d", blocknumber);
col_append_fstr(pinfo->cinfo, COL_INFO, " No.:[%s]", str_number);
proto_item_append_text(data_tree, ", Number: %05d)", blocknumber);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_load_mem_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_blocksecurity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
s7comm_get_timestring_from_s7time(tvb, offset, str_timestamp, sizeof(str_timestamp));
proto_tree_add_string(data_tree, hf_s7comm_ud_blockinfo_code_timestamp, tvb, offset, 6, str_timestamp);
offset += 6;
s7comm_get_timestring_from_s7time(tvb, offset, str_timestamp, sizeof(str_timestamp));
proto_tree_add_string(data_tree, hf_s7comm_ud_blockinfo_interface_timestamp, tvb, offset, 6, str_timestamp);
offset += 6;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_ssb_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_add_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_localdata_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_mc7_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_author, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_family, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_headername, tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
g_snprintf(str_version, sizeof(str_version), "%d.%d", ((tvb_get_guint8(tvb, offset) & 0xf0) >> 4), tvb_get_guint8(tvb, offset) & 0x0f);
proto_tree_add_string(data_tree, hf_s7comm_ud_blockinfo_headerversion, tvb, offset, 1, str_version);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_res_unknown, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_reserved1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(data_tree, hf_s7comm_ud_blockinfo_reserved2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
know_data = TRUE;
}
break;
default:
break;
}
if (know_data == FALSE && dlength > 4) {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
offset += dlength;
}
return offset;
}
static guint32
s7comm_decode_ud_cyclic_subfunc(tvbuff_t *tvb,
proto_tree *data_tree,
guint8 type,
guint8 subfunc,
guint16 dlength,
guint32 offset)
{
gboolean know_data = FALSE;
guint32 offset_old;
guint32 len_item;
guint8 item_count;
guint8 i;
switch (subfunc)
{
case S7COMM_UD_SUBF_CYCLIC_MEM:
item_count = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_uint(data_tree, hf_s7comm_param_itemcount, tvb, offset, 2, item_count);
offset += 2;
if (type == S7COMM_UD_TYPE_REQ) {
proto_tree_add_item(data_tree, hf_s7comm_cycl_interval_timebase, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(data_tree, hf_s7comm_cycl_interval_time, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 0; i < item_count; i++) {
offset_old = offset;
offset = s7comm_decode_param_item(tvb, offset, data_tree, i);
len_item = offset - offset_old;
if ((len_item % 2) && (i < item_count)) {
offset += 1;
}
}
} else if (type == S7COMM_UD_TYPE_RES || type == S7COMM_UD_TYPE_PUSH) {
offset = s7comm_decode_response_read_data(tvb, data_tree, item_count, offset);
}
know_data = TRUE;
break;
}
if (know_data == FALSE && dlength > 4) {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
offset += dlength;
}
return offset;
}
static guint32
s7comm_decode_ud_prog_subfunc(tvbuff_t *tvb,
proto_tree *data_tree,
guint8 type,
guint8 subfunc,
guint16 dlength,
guint32 offset)
{
gboolean know_data = FALSE;
guint8 data_type;
guint16 byte_count;
guint16 item_count;
guint16 i;
switch(subfunc)
{
case S7COMM_UD_SUBF_PROG_REQDIAGDATA1:
case S7COMM_UD_SUBF_PROG_REQDIAGDATA2:
if (type != S7COMM_UD_TYPE_PUSH) {
offset = s7comm_decode_ud_prog_reqdiagdata(tvb, data_tree, subfunc, offset);
know_data = TRUE;
}
break;
case S7COMM_UD_SUBF_PROG_VARTAB1:
offset += 1;
data_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_vartab_data_type, tvb, offset, 1, data_type);
offset += 1;
byte_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_vartab_byte_count, tvb, offset, 2, byte_count);
offset += 2;
switch (data_type)
{
case S7COMM_UD_SUBF_PROG_VARTAB_TYPE_REQ:
proto_tree_add_item(data_tree, hf_s7comm_vartab_unknown, tvb, offset, 20, ENC_NA);
offset += 20;
item_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_vartab_item_count, tvb, offset, 2, item_count);
offset += 2;
for (i = 0; i < item_count; i++) {
offset = s7comm_decode_ud_prog_vartab_req_item(tvb, offset, data_tree, i);
}
know_data = TRUE;
break;
case S7COMM_UD_SUBF_PROG_VARTAB_TYPE_RES:
proto_tree_add_item(data_tree, hf_s7comm_vartab_unknown, tvb, offset, 4, ENC_NA);
offset += 4;
item_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_vartab_item_count, tvb, offset, 2, item_count);
offset += 2;
for (i = 0; i < item_count; i++) {
offset = s7comm_decode_ud_prog_vartab_res_item(tvb, offset, data_tree, i);
}
know_data = TRUE;
break;
}
}
if (know_data == FALSE && dlength > 4) {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
offset += dlength;
}
return offset;
}
static guint32
s7comm_decode_ud(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
guint16 plength,
guint16 dlength,
guint32 offset)
{
proto_item *item = NULL;
proto_tree *param_tree = NULL;
proto_tree *data_tree = NULL;
guint8 ret_val;
guint8 tsize;
guint16 len;
guint32 offset_temp;
guint8 type;
guint8 funcgroup;
guint8 subfunc;
guint8 data_unit_ref = 0;
guint8 last_data_unit = 0;
item = proto_tree_add_item(tree, hf_s7comm_param, tvb, offset, plength, ENC_NA);
param_tree = proto_item_add_subtree(item, ett_s7comm_param);
offset_temp = offset;
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_head, tvb, offset_temp, 3, ENC_BIG_ENDIAN);
offset_temp += 3;
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_len, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_reqres2, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
type = (tvb_get_guint8(tvb, offset_temp) & 0xf0) >> 4;
funcgroup = (tvb_get_guint8(tvb, offset_temp) & 0x0f);
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_type, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " Function:[%s] -> [%s]",
val_to_str(type, userdata_type_names, "Unknown type: 0x%02x"),
val_to_str(funcgroup, userdata_functiongroup_names, "Unknown function: 0x%02x")
);
proto_item_append_text(param_tree, ": (%s)", val_to_str(type, userdata_type_names, "Unknown type: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(funcgroup, userdata_functiongroup_names, "Unknown function: 0x%02x"));
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_funcgroup, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
subfunc = tvb_get_guint8(tvb, offset_temp);
switch (funcgroup){
case S7COMM_UD_FUNCGROUP_PROG:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_prog, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_prog_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_prog_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
case S7COMM_UD_FUNCGROUP_CYCLIC:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_cyclic, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_cyclic_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_cyclic_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
case S7COMM_UD_FUNCGROUP_BLOCK:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_block, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_block_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_block_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
case S7COMM_UD_FUNCGROUP_CPU:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_cpu, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_cpu_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_cpu_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
case S7COMM_UD_FUNCGROUP_SEC:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_sec, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_sec_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_sec_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
case S7COMM_UD_FUNCGROUP_TIME:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc_time, tvb, offset_temp, 1, subfunc);
col_append_fstr(pinfo->cinfo, COL_INFO, " -> [%s]",
val_to_str(subfunc, userdata_time_subfunc_names, "Unknown subfunc: 0x%02x"));
proto_item_append_text(param_tree, " ->(%s)", val_to_str(subfunc, userdata_time_subfunc_names, "Unknown subfunc: 0x%02x"));
break;
default:
proto_tree_add_uint(param_tree, hf_s7comm_userdata_param_subfunc, tvb, offset_temp, 1, subfunc);
break;
}
offset_temp += 1;
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_seq_num, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
if (plength >= 12) {
data_unit_ref = tvb_get_guint8(tvb, offset_temp);
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_dataunitref, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
last_data_unit = tvb_get_guint8(tvb, offset_temp);
proto_tree_add_item(param_tree, hf_s7comm_userdata_param_dataunit, tvb, offset_temp, 1, ENC_BIG_ENDIAN);
offset_temp += 1;
proto_tree_add_item(param_tree, hf_s7comm_param_errcod, tvb, offset_temp, 2, ENC_BIG_ENDIAN);
}
offset += plength;
item = proto_tree_add_item(tree, hf_s7comm_data, tvb, offset, dlength, ENC_NA);
data_tree = proto_item_add_subtree(item, ett_s7comm_data);
if (dlength >= 4) {
ret_val = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_data_returncode, tvb, offset, 1, ret_val);
offset += 1;
tsize = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_data_transport_size, tvb, offset, 1, tsize);
offset += 1;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_data_length, tvb, offset, 2, len);
offset += 2;
if (dlength > 4) {
switch (funcgroup){
case S7COMM_UD_FUNCGROUP_PROG:
offset = s7comm_decode_ud_prog_subfunc(tvb, data_tree, type, subfunc, dlength, offset);
break;
case S7COMM_UD_FUNCGROUP_CYCLIC:
offset = s7comm_decode_ud_cyclic_subfunc(tvb, data_tree, type, subfunc, dlength, offset);
break;
case S7COMM_UD_FUNCGROUP_BLOCK:
offset = s7comm_decode_ud_block_subfunc(tvb, pinfo, data_tree, type, subfunc, ret_val, tsize, len, dlength, offset);
break;
case S7COMM_UD_FUNCGROUP_CPU:
if (subfunc == S7COMM_UD_SUBF_CPU_READSZL) {
offset = s7comm_decode_ud_cpu_szl_subfunc(tvb, pinfo, data_tree, type, ret_val, len, dlength, data_unit_ref, last_data_unit, offset);
} else {
proto_tree_add_item(data_tree, hf_s7comm_userdata_data, tvb, offset, dlength - 4, ENC_NA);
}
break;
case S7COMM_UD_FUNCGROUP_SEC:
offset = s7comm_decode_ud_security_subfunc(tvb, data_tree, dlength, offset);
break;
case S7COMM_UD_FUNCGROUP_PBC:
offset = s7comm_decode_ud_pbc_subfunc(tvb, data_tree, dlength, offset);
break;
case S7COMM_UD_FUNCGROUP_TIME:
offset = s7comm_decode_ud_time_subfunc(tvb, data_tree, type, subfunc, ret_val, dlength, offset);
break;
default:
break;
}
}
}
return offset;
}
static guint32
s7comm_decode_req_resp(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
guint16 plength,
guint16 dlength,
guint32 offset,
guint8 rosctr)
{
proto_item *item = NULL;
proto_tree *param_tree = NULL;
proto_tree *data_tree = NULL;
guint8 function = 0;
guint8 item_count = 0;
guint8 i;
guint32 offset_old;
guint32 len;
if (plength > 0) {
item = proto_tree_add_item(tree, hf_s7comm_param, tvb, offset, plength, ENC_NA);
param_tree = proto_item_add_subtree(item, ett_s7comm_param);
function = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " Function:[%s]", val_to_str(function, param_functionnames, "Unknown function: 0x%02x"));
proto_tree_add_uint(param_tree, hf_s7comm_param_service, tvb, offset, 1, function);
proto_item_append_text(param_tree, ": (%s)", val_to_str(function, param_functionnames, "Unknown function: 0x%02x"));
offset += 1;
if (rosctr == S7COMM_ROSCTR_JOB) {
switch (function){
case S7COMM_SERV_READVAR:
case S7COMM_SERV_WRITEVAR:
item_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(param_tree, hf_s7comm_param_itemcount, tvb, offset, 1, item_count);
offset += 1;
for (i = 0; i < item_count; i++) {
offset_old = offset;
offset = s7comm_decode_param_item(tvb, offset, param_tree, i);
len = offset - offset_old;
if ((len % 2) && (i < item_count)) {
offset += 1;
}
}
if ((function == S7COMM_SERV_WRITEVAR) && (dlength > 0)) {
item = proto_tree_add_item(tree, hf_s7comm_data, tvb, offset, dlength, ENC_NA);
data_tree = proto_item_add_subtree(item, ett_s7comm_data);
offset = s7comm_decode_response_read_data(tvb, data_tree, item_count, offset);
}
break;
case S7COMM_SERV_SETUPCOMM:
offset = s7comm_decode_pdu_setup_communication(tvb, param_tree, offset);
break;
case S7COMM_FUNCREQUESTDOWNLOAD:
case S7COMM_FUNCDOWNLOADBLOCK:
case S7COMM_FUNCDOWNLOADENDED:
case S7COMM_FUNCSTARTUPLOAD:
case S7COMM_FUNCUPLOAD:
case S7COMM_FUNCENDUPLOAD:
offset = s7comm_decode_plc_controls_param_hex1x(tvb, pinfo, param_tree, plength, offset -1);
break;
case S7COMM_FUNC_PLC_CONTROL:
offset = s7comm_decode_plc_controls_param_hex28(tvb, pinfo, param_tree, offset -1);
break;
case S7COMM_FUNC_PLC_STOP:
offset = s7comm_decode_plc_controls_param_hex29(tvb, param_tree, offset -1);
break;
default:
if (plength > 1) {
proto_tree_add_item(param_tree, hf_s7comm_param_data, tvb, offset, plength - 1, ENC_NA);
}
offset += plength - 1;
if (dlength > 0) {
item = proto_tree_add_item(tree, hf_s7comm_data, tvb, offset, dlength, ENC_NA);
data_tree = proto_item_add_subtree(item, ett_s7comm_data);
proto_tree_add_item(data_tree, hf_s7comm_readresponse_data, tvb, offset, dlength, ENC_NA);
offset += dlength;
}
break;
}
} else if (rosctr == S7COMM_ROSCTR_ACK_DATA) {
switch (function){
case S7COMM_SERV_READVAR:
case S7COMM_SERV_WRITEVAR:
item_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(param_tree, hf_s7comm_param_itemcount, tvb, offset, 1, item_count);
offset += 1;
item = proto_tree_add_item(tree, hf_s7comm_data, tvb, offset, dlength, ENC_NA);
data_tree = proto_item_add_subtree(item, ett_s7comm_data);
if ((function == S7COMM_SERV_READVAR) && (dlength > 0)) {
offset = s7comm_decode_response_read_data(tvb, data_tree, item_count, offset);
} else if ((function == S7COMM_SERV_WRITEVAR) && (dlength > 0)) {
offset = s7comm_decode_response_write_data(tvb, data_tree, item_count, offset);
}
break;
case S7COMM_SERV_SETUPCOMM:
offset = s7comm_decode_pdu_setup_communication(tvb, param_tree, offset);
break;
default:
if (plength > 1) {
proto_tree_add_item(param_tree, hf_s7comm_param_data, tvb, offset, plength - 1, ENC_NA);
}
offset += plength - 1;
if (dlength > 0) {
item = proto_tree_add_item(tree, hf_s7comm_data, tvb, offset, dlength, ENC_NA);
data_tree = proto_item_add_subtree(item, ett_s7comm_data);
proto_tree_add_item(data_tree, hf_s7comm_readresponse_data, tvb, offset, dlength, ENC_NA);
offset += dlength;
}
break;
}
}
}
return offset;
}
static gboolean
dissect_s7comm(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
proto_item *s7comm_item = NULL;
proto_item *s7comm_sub_item = NULL;
proto_tree *s7comm_tree = NULL;
proto_tree *s7comm_header_tree = NULL;
guint32 offset = 0;
guint8 rosctr = 0;
guint8 hlength = 10;
guint16 plength = 0;
guint16 dlength = 0;
if(tvb_captured_length(tvb) < S7COMM_MIN_TELEGRAM_LENGTH)
return FALSE;
if (tvb_get_guint8(tvb, 0) != S7COMM_PROT_ID)
return FALSE;
if (tvb_get_guint8(tvb, 1) < 0x01 || tvb_get_guint8(tvb, 1) > 0x07)
return FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_S7COMM);
col_clear(pinfo->cinfo, COL_INFO);
rosctr = tvb_get_guint8(tvb, 1);
if (rosctr == 2 || rosctr == 3) hlength = 12;
col_add_fstr(pinfo->cinfo, COL_INFO, "ROSCTR:[%-8s]", val_to_str(rosctr, rosctr_names, "Unknown: 0x%02x"));
s7comm_item = proto_tree_add_item(tree, proto_s7comm, tvb, 0, -1, ENC_NA);
s7comm_tree = proto_item_add_subtree(s7comm_item, ett_s7comm);
s7comm_sub_item = proto_tree_add_item(s7comm_tree, hf_s7comm_header,
tvb, offset, hlength, ENC_NA);
s7comm_header_tree = proto_item_add_subtree(s7comm_sub_item, ett_s7comm_header);
proto_tree_add_item(s7comm_header_tree, hf_s7comm_header_protid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(s7comm_header_tree, hf_s7comm_header_rosctr, tvb, offset, 1, rosctr);
proto_item_append_text(s7comm_header_tree, ": (%s)", val_to_str(rosctr, rosctr_names, "Unknown ROSCTR: 0x%02x"));
offset += 1;
proto_tree_add_item(s7comm_header_tree, hf_s7comm_header_redid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(s7comm_header_tree, hf_s7comm_header_pduref, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
plength = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(s7comm_header_tree, hf_s7comm_header_parlg, tvb, offset, 2, plength);
offset += 2;
dlength = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(s7comm_header_tree, hf_s7comm_header_datlg, tvb, offset, 2, dlength);
offset += 2;
if (hlength == 12) {
proto_tree_add_item(s7comm_header_tree, hf_s7comm_header_errcls, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(s7comm_header_tree, hf_s7comm_header_errcod, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
switch (rosctr) {
case S7COMM_ROSCTR_JOB:
case S7COMM_ROSCTR_ACK_DATA:
s7comm_decode_req_resp(tvb, pinfo, s7comm_tree, plength, dlength, offset, rosctr);
break;
case S7COMM_ROSCTR_USERDATA:
s7comm_decode_ud(tvb, pinfo, s7comm_tree, plength, dlength, offset);
break;
}
return TRUE;
}
void
proto_register_s7comm (void)
{
static hf_register_info hf[] = {
{ &hf_s7comm_header,
{ "Header", "s7comm.header", FT_NONE, BASE_NONE, NULL, 0x0,
"This is the header of S7 communication", HFILL }},
{ &hf_s7comm_header_protid,
{ "Protocol Id", "s7comm.header.protid", FT_UINT8, BASE_HEX, NULL, 0x0,
"Protocol Identification, 0x32 for S7", HFILL }},
{ &hf_s7comm_header_rosctr,
{ "ROSCTR", "s7comm.header.rosctr", FT_UINT8, BASE_DEC, VALS(rosctr_names), 0x0,
"Remote Operating Service Control", HFILL }},
{ &hf_s7comm_header_redid,
{ "Redundancy Identification (Reserved)", "s7comm.header.redid", FT_UINT16, BASE_HEX, NULL, 0x0,
"Redundancy Identification (Reserved), should be always 0x0000", HFILL }},
{ &hf_s7comm_header_pduref,
{ "Protocol Data Unit Reference", "s7comm.header.pduref", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_header_parlg,
{ "Parameter length", "s7comm.header.parlg", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entire length of the parameter block in bytes", HFILL }},
{ &hf_s7comm_header_datlg,
{ "Data length", "s7comm.header.datlg", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entire length of the data block in bytes", HFILL }},
{ &hf_s7comm_header_errcls,
{ "Error class", "s7comm.header.errcls", FT_UINT8, BASE_HEX, VALS(errcls_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_header_errcod,
{ "Error code", "s7comm.header.errcod", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param,
{ "Parameter", "s7comm.param", FT_NONE, BASE_NONE, NULL, 0x0,
"This is the parameter part of S7 communication", HFILL }},
{ &hf_s7comm_param_errcod,
{ "Error code", "s7comm.param.errcod", FT_UINT16, BASE_HEX, VALS(param_errcode_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_service,
{ "Function", "s7comm.param.func", FT_UINT8, BASE_HEX, VALS(param_functionnames), 0x0,
"Indicates the function of parameter/data", HFILL }},
{ &hf_s7comm_param_maxamq_calling,
{ "Max AmQ (parallel jobs with ack) calling", "s7comm.param.maxamq_calling", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_maxamq_called,
{ "Max AmQ (parallel jobs with ack) called", "s7comm.param.maxamq_called", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_setup_reserved1,
{ "Reserved", "s7comm.param.setup_reserved1", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_neg_pdu_length,
{ "PDU length", "s7comm.param.pdu_length", FT_UINT16, BASE_DEC, NULL, 0x0,
"Negotiated PDU length", HFILL }},
{ &hf_s7comm_param_itemcount,
{ "Item count", "s7comm.param.itemcount", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of Items in parameter/data part", HFILL }},
{ &hf_s7comm_param_data,
{ "Parameter data", "s7comm.param.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_item,
{ "Item", "s7comm.param.item", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_param_subitem,
{ "Subitem", "s7comm.param.subitem", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_varspec,
{ "Variable specification", "s7comm.param.item.varspec", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_varspec_length,
{ "Length of following address specification", "s7comm.param.item.varspec_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_syntax_id,
{ "Syntax Id", "s7comm.param.item.syntaxid", FT_UINT8, BASE_HEX, VALS(item_syntaxid_names), 0x0,
"Syntax Id, format type of following address specification", HFILL }},
{ &hf_s7comm_item_transport_size,
{ "Transport size", "s7comm.param.item.transp_size", FT_UINT8, BASE_DEC, VALS(item_transportsizenames), 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_length,
{ "Length", "s7comm.param.item.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_db,
{ "DB number", "s7comm.param.item.db", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_area,
{ "Area", "s7comm.param.item.area", FT_UINT8, BASE_HEX, VALS(item_areanames), 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_address,
{ "Address", "s7comm.param.item.address", FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_address_byte,
{ "Byte Address", "s7comm.param.item.address.byte", FT_UINT24, BASE_DEC, NULL, 0x7fff8,
NULL, HFILL }},
{ &hf_s7comm_item_address_bit,
{ "Bit Address", "s7comm.param.item.address.bit", FT_UINT24, BASE_DEC, NULL, 0x000007,
NULL, HFILL }},
{ &hf_s7comm_item_address_nr,
{ "Number (T/C/BLOCK)", "s7comm.param.item.address.number", FT_UINT24, BASE_DEC, NULL, 0x00ffff,
NULL, HFILL }},
{ &hf_s7comm_item_dbread_numareas,
{ "Number of areas", "s7comm.param.item.dbread.numareas", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of area specifications following", HFILL }},
{ &hf_s7comm_item_dbread_length,
{ "Bytes to read", "s7comm.param.item.dbread.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of bytes to read", HFILL }},
{ &hf_s7comm_item_dbread_db,
{ "DB number", "s7comm.param.item.dbread.db", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_dbread_startadr,
{ "Start address", "s7comm.param.item.dbread.startaddress", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_nck_areaunit,
{ "NCK Area/Unit", "s7comm.param.item.nck.area_unit", FT_UINT8, BASE_HEX, NULL, 0x0,
"NCK Area/Unit: Bitmask aaauuuuu: a=area, u=unit", HFILL }},
{ &hf_s7comm_item_nck_area,
{ "NCK Area", "s7comm.param.item.nck.area", FT_UINT8, BASE_DEC, VALS(nck_area_names), 0xe0,
NULL, HFILL }},
{ &hf_s7comm_item_nck_unit,
{ "NCK Unit", "s7comm.param.item.nck.unit", FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }},
{ &hf_s7comm_item_nck_column,
{ "NCK Column number", "s7comm.param.item.nck.column", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_nck_line,
{ "NCK Line number", "s7comm.param.item.nck.line", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_nck_module,
{ "NCK Module", "s7comm.param.item.nck.module", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &nck_module_names_ext, 0x0,
NULL, HFILL }},
{ &hf_s7comm_item_nck_linecount,
{ "NCK Linecount", "s7comm.param.item.nck.linecount", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data,
{ "Data", "s7comm.data", FT_NONE, BASE_NONE, NULL, 0x0,
"This is the data part of S7 communication", HFILL }},
{ &hf_s7comm_data_returncode,
{ "Return code", "s7comm.data.returncode", FT_UINT8, BASE_HEX, VALS(s7comm_item_return_valuenames), 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_transport_size,
{ "Transport size", "s7comm.data.transportsize", FT_UINT8, BASE_HEX, VALS(data_transportsizenames), 0x0,
"Data type / Transport size. If 3, 4 or 5 the following length gives the number of bits, otherwise the number of bytes.", HFILL }},
{ &hf_s7comm_data_length,
{ "Length", "s7comm.data.length", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of data", HFILL }},
{ &hf_s7comm_data_item,
{ "Item", "s7comm.data.item", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_readresponse_data,
{ "Data", "s7comm.resp.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_fillbyte,
{ "Fill byte", "s7comm.data.fillbyte", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_data,
{ "Data", "s7comm.data.userdata", FT_BYTES, BASE_NONE, NULL, 0x0,
"Userdata data", HFILL }},
{ &hf_s7comm_userdata_param_head,
{ "Parameter head", "s7comm.param.userdata.head", FT_UINT24, BASE_HEX, NULL, 0x0,
"Header before parameter (constant 0x000112)", HFILL }},
{ &hf_s7comm_userdata_param_len,
{ "Parameter length", "s7comm.param.userdata.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of following parameter data (without head)", HFILL }},
{ &hf_s7comm_userdata_param_reqres2,
{ "Unknown (Request/Response)", "s7comm.param.userdata.reqres1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Unknown part, possible request/response (0x11, 0x12), but not in programmer commands", HFILL }},
{ &hf_s7comm_userdata_param_type,
{ "Type", "s7comm.param.userdata.type", FT_UINT8, BASE_DEC, VALS(userdata_type_names), 0xf0,
"Type of parameter", HFILL }},
{ &hf_s7comm_userdata_param_funcgroup,
{ "Function group", "s7comm.param.userdata.funcgroup", FT_UINT8, BASE_DEC, VALS(userdata_functiongroup_names), 0x0f,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_prog,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_prog_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_cyclic,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_cyclic_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_block,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_block_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_cpu,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_cpu_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_sec,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_sec_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc_time,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_DEC, VALS(userdata_time_subfunc_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_subfunc,
{ "Subfunction", "s7comm.param.userdata.subfunc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_seq_num,
{ "Sequence number", "s7comm.param.userdata.seq_num", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_param_dataunitref,
{ "Data unit reference number", "s7comm.param.userdata.dataunitref", FT_UINT8, BASE_DEC, NULL, 0x0,
"Data unit reference number if PDU is fragmented", HFILL }},
{ &hf_s7comm_userdata_param_dataunit,
{ "Last data unit", "s7comm.param.userdata.lastdataunit", FT_UINT8, BASE_HEX, VALS(userdata_lastdataunit_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_type,
{ "Block type", "s7comm.blockinfo.blocktype", FT_UINT8, BASE_DEC, VALS(blocktype_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_cnt,
{ "Block count", "s7comm.blockinfo.block_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_num,
{ "Block number", "s7comm.blockinfo.block_num", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_flags,
{ "Block flags (unknown)", "s7comm.blockinfo.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_lang,
{ "Block language", "s7comm.blockinfo.block_lang", FT_UINT8, BASE_DEC, VALS(blocklanguage_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_block_num_ascii,
{ "Block number", "s7comm.data.blockinfo.block_number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_filesys,
{ "Filesystem", "s7comm.data.blockinfo.filesys", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_res_const1,
{ "Constant 1", "s7comm.blockinfo.res_const1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Possible constant 1", HFILL }},
{ &hf_s7comm_ud_blockinfo_res_infolength,
{ "Length of Info", "s7comm.blockinfo.res_infolength", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of Info in bytes", HFILL }},
{ &hf_s7comm_ud_blockinfo_res_unknown2,
{ "Unknown blockinfo 2", "s7comm.blockinfo.res_unknown2", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_res_const3,
{ "Constant 3", "s7comm.blockinfo.res_const3", FT_STRING, BASE_NONE, NULL, 0x0,
"Possible constant 3, seems to be always 'pp'", HFILL }},
{ &hf_s7comm_ud_blockinfo_res_unknown,
{ "Unknown byte(s) blockinfo", "s7comm.blockinfo.res_unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_subblk_type,
{ "Subblk type", "s7comm.blockinfo.subblk_type", FT_UINT8, BASE_DEC, VALS(subblktype_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_load_mem_len,
{ "Length load memory", "s7comm.blockinfo.load_mem_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"Length of load memory in bytes", HFILL }},
{ &hf_s7comm_ud_blockinfo_blocksecurity,
{ "Block Security", "s7comm.blockinfo.blocksecurity", FT_UINT32, BASE_DEC, VALS(blocksecurity_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_interface_timestamp,
{ "Interface timestamp", "s7comm.blockinfo.interface_timestamp", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_code_timestamp,
{ "Code timestamp", "s7comm.blockinfo.code_timestamp", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_ssb_len,
{ "SSB length", "s7comm.blockinfo.ssb_len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_add_len,
{ "ADD length", "s7comm.blockinfo.add_len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_localdata_len,
{ "Localdata length", "s7comm.blockinfo.localdata_len", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of localdata in bytes", HFILL }},
{ &hf_s7comm_ud_blockinfo_mc7_len,
{ "MC7 code length", "s7comm.blockinfo.mc7_len", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of MC7 code in bytes", HFILL }},
{ &hf_s7comm_ud_blockinfo_author,
{ "Author", "s7comm.blockinfo.author", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_family,
{ "Family", "s7comm.blockinfo.family", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_headername,
{ "Name (Header)", "s7comm.blockinfo.headername", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_headerversion,
{ "Version (Header)", "s7comm.blockinfo.headerversion", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_checksum,
{ "Block checksum", "s7comm.blockinfo.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_reserved1,
{ "Reserved 1", "s7comm.blockinfo.reserved1", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_ud_blockinfo_reserved2,
{ "Reserved 2", "s7comm.blockinfo.reserved2", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_blockinfo_flags,
{ "Block flags", "s7comm.param.userdata.blockinfo.flags", FT_UINT8, BASE_HEX, NULL, 0xff,
"Some block configuration flags", HFILL }},
{ &hf_s7comm_userdata_blockinfo_linked,
{ "Linked", "s7comm.param.userdata.blockinfo.linked", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
NULL, HFILL }},
{ &hf_s7comm_userdata_blockinfo_standard_block,
{ "Standard block", "s7comm.param.userdata.blockinfo.standard_block", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
NULL, HFILL }},
{ &hf_s7comm_userdata_blockinfo_nonretain,
{ "Non Retain", "s7comm.param.userdata.blockinfo.nonretain", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_askheadersize,
{ "Ask header size", "s7comm.diagdata.req.askheadersize", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_asksize,
{ "Ask size", "s7comm.diagdata.req.asksize", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_unknown,
{ "Unknown byte(s) diagdata", "s7comm.diagdata.req.unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_answersize,
{ "Answer size", "s7comm.diagdata.req.answersize", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_block_type,
{ "Block type", "s7comm.diagdata.req.blocktype", FT_UINT8, BASE_DEC, VALS(subblktype_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_block_num,
{ "Block number", "s7comm.diagdata.req.blocknumber", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_startaddr_awl,
{ "Start address AWL", "s7comm.diagdata.req.startaddr_awl", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_saz,
{ "Step address counter (SAZ)", "s7comm.diagdata.req.saz", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_number_of_lines,
{ "Number of lines", "s7comm.diagdata.req.number_of_lines", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_req_line_address,
{ "Address", "s7comm.diagdata.req.line_address", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_diagdata_registerflag,
{ "Registers", "s7comm.diagdata.register", FT_UINT8, BASE_HEX, NULL, 0x00,
"Requested registers", HFILL }},
{ &hf_s7comm_diagdata_registerflag_stw,
{ "STW", "s7comm.diagdata.register.stw", FT_BOOLEAN, 8, NULL, 0x01,
"STW / Status word", HFILL }},
{ &hf_s7comm_diagdata_registerflag_accu1,
{ "ACCU1", "s7comm.diagdata.register.accu1", FT_BOOLEAN, 8, NULL, 0x02,
"ACCU1 / Accumulator 1", HFILL }},
{ &hf_s7comm_diagdata_registerflag_accu2,
{ "ACCU2", "s7comm.diagdata.register.accu2", FT_BOOLEAN, 8, NULL, 0x04,
"ACCU2 / Accumulator 2", HFILL }},
{ &hf_s7comm_diagdata_registerflag_ar1,
{ "AR1", "s7comm.diagdata.register.ar1", FT_BOOLEAN, 8, NULL, 0x08,
"AR1 / Addressregister 1", HFILL }},
{ &hf_s7comm_diagdata_registerflag_ar2,
{ "AR2", "s7comm.diagdata.register.ar2", FT_BOOLEAN, 8, NULL, 0x10,
"AR2 / Addressregister 2", HFILL }},
{ &hf_s7comm_diagdata_registerflag_db1,
{ "DB1", "s7comm.diagdata.register.db1", FT_BOOLEAN, 8, NULL, 0x20,
"DB1 (global)/ Datablock register 1", HFILL }},
{ &hf_s7comm_diagdata_registerflag_db2,
{ "DB2", "s7comm.diagdata.register.db2", FT_BOOLEAN, 8, NULL, 0x40,
"DB2 (instance) / Datablock register 2", HFILL }},
{ &hf_s7comm_data_ts,
{ "S7 Timestamp", "s7comm.data.ts", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
"S7 Timestamp, BCD coded", HFILL }},
{ &hf_s7comm_data_ts_reserved,
{ "S7 Timestamp - Reserved", "s7comm.data.ts_reserved", FT_UINT8, BASE_HEX, NULL, 0x00,
"S7 Timestamp: Reserved byte", HFILL }},
{ &hf_s7comm_data_ts_year1,
{ "S7 Timestamp - Year 1", "s7comm.data.ts_year1", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded year thousands/hundreds, should be ignored (19 or 20)", HFILL }},
{ &hf_s7comm_data_ts_year2,
{ "S7 Timestamp - Year 2", "s7comm.data.ts_year2", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded year, if 00...89 then it's 2000...2089, else 1990...1999", HFILL }},
{ &hf_s7comm_data_ts_month,
{ "S7 Timestamp - Month", "s7comm.data.ts_month", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded month", HFILL }},
{ &hf_s7comm_data_ts_day,
{ "S7 Timestamp - Day", "s7comm.data.ts_day", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded day", HFILL }},
{ &hf_s7comm_data_ts_hour,
{ "S7 Timestamp - Hour", "s7comm.data.ts_hour", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded hour", HFILL }},
{ &hf_s7comm_data_ts_minute,
{ "S7 Timestamp - Minute", "s7comm.data.ts_minute", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded minute", HFILL }},
{ &hf_s7comm_data_ts_second,
{ "S7 Timestamp - Second", "s7comm.data.ts_second", FT_UINT8, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded second", HFILL }},
{ &hf_s7comm_data_ts_millisecond,
{ "S7 Timestamp - Milliseconds", "s7comm.data.ts_millisecond", FT_UINT16, BASE_DEC, NULL, 0x00,
"S7 Timestamp: BCD coded milliseconds (left 3 nibbles)", HFILL }},
{ &hf_s7comm_data_ts_weekday,
{ "S7 Timestamp - Weekday", "s7comm.data.ts_weekday", FT_UINT16, BASE_DEC, VALS(weekdaynames), 0x000f,
"S7 Timestamp: Weekday number (right nibble, 1=Su,2=Mo,..)", HFILL }},
{ &hf_s7comm_data_plccontrol_part1_unknown,
{ "Part 1 unknown bytes", "s7comm.data.plccontrol.part1_unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_part1_len,
{ "Length part 1", "s7comm.data.plccontrol.part1_len", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of part 1 in bytes", HFILL }},
{ &hf_s7comm_data_plccontrol_argument,
{ "Argument", "s7comm.data.plccontrol.argument", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_block_cnt,
{ "Number of blocks", "s7comm.data.plccontrol.block_cnt", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_part1_unknown2,
{ "Unknown byte", "s7comm.data.plccontrol.part1_unknown2", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_block_unknown,
{ "Unknown char before Block type", "s7comm.data.plccontrol.block_unknown", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_block_type,
{ "Block type", "s7comm.data.plccontrol.block_type", FT_UINT8, BASE_DEC, VALS(blocktype_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_block_num,
{ "Block number", "s7comm.data.plccontrol.block_number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_dest_filesys,
{ "Destination filesystem", "s7comm.data.plccontrol.dest_filesys", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_plccontrol_part2_len,
{ "Length part 2", "s7comm.data.plccontrol.part2_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of part 2 in bytes", HFILL }},
{ &hf_s7comm_data_plccontrol_pi_service,
{ "PI (program invocation) Service", "s7comm.data.plccontrol.pi_service", FT_STRING, BASE_NONE, NULL, 0x0,
"Known: _INSE = Activate a module, _DELE = Delete a passive module, _PROGRAM = Start/Stop the PLC, _PLC_MEMORYRESET = Reset the PLC memory" , HFILL }},
{ &hf_s7comm_data_blockcontrol_unknown1,
{ "Unknown byte(s) in blockcontrol", "s7comm.data.blockcontrol.unknown1", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_errorcode,
{ "Errorcode", "s7comm.data.blockcontrol.errorcode", FT_UINT16, BASE_HEX, NULL, 0x0,
"Errorcode, 0 on success", HFILL }},
{ &hf_s7comm_data_blockcontrol_part1_len,
{ "Length part 1", "s7comm.data.blockcontrol.part1_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of part 1 in bytes", HFILL }},
{ &hf_s7comm_data_blockcontrol_file_ident,
{ "File identifier", "s7comm.data.blockcontrol.file_identifier", FT_STRING, BASE_NONE, NULL, 0x0,
"File identifier: '_'=complete module; '$'=Module header for up-loading", HFILL }},
{ &hf_s7comm_data_blockcontrol_block_unknown,
{ "Unknown char before Block type", "s7comm.data.blockcontrol.block_unknown", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_block_type,
{ "Block type", "s7comm.data.blockcontrol.block_type", FT_UINT8, BASE_DEC, VALS(blocktype_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_block_num,
{ "Block number", "s7comm.data.blockcontrol.block_number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_dest_filesys,
{ "Destination filesystem", "s7comm.data.blockcontrol.dest_filesys", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_part2_len,
{ "Length part 2", "s7comm.data.blockcontrol.part2_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of part 2 in bytes", HFILL }},
{ &hf_s7comm_data_blockcontrol_part2_unknown,
{ "Unknown char before load mem", "s7comm.data.blockcontrol.part2_unknown", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_data_blockcontrol_loadmem_len,
{ "Length of load memory", "s7comm.data.blockcontrol.loadmem_len", FT_STRING, BASE_NONE, NULL, 0x0,
"Length of load memory in bytes", HFILL }},
{ &hf_s7comm_data_blockcontrol_mc7code_len,
{ "Length of MC7 code", "s7comm.data.blockcontrol.mc7code_len", FT_STRING, BASE_NONE, NULL, 0x0,
"Length of MC7 code in bytes", HFILL }},
{ &hf_s7comm_vartab_data_type,
{ "Type of data", "s7comm.vartab.data_type", FT_UINT8, BASE_DEC, VALS(userdata_prog_vartab_type_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_byte_count,
{ "Byte count", "s7comm.vartab.byte_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_unknown,
{ "Unknown byte(s) vartab", "s7comm.vartab.unknown", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_item_count,
{ "Item count", "s7comm.vartab.item_count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_req_memory_area,
{ "Memory area", "s7comm.vartab.req.memory_area", FT_UINT8, BASE_DEC, VALS(userdata_prog_vartab_area_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_req_repetition_factor,
{ "Repetition factor", "s7comm.vartab.req.repetition_factor", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_vartab_req_db_number,
{ "DB number", "s7comm.vartab.req.db_number", FT_UINT16, BASE_DEC, NULL, 0x0,
"DB number, when area is DB", HFILL }},
{ &hf_s7comm_vartab_req_startaddress,
{ "Startaddress", "s7comm.vartab.req.startaddress", FT_UINT16, BASE_DEC, NULL, 0x0,
"Startaddress / byteoffset", HFILL }},
{ &hf_s7comm_cycl_interval_timebase,
{ "Interval timebase", "s7comm.cyclic.interval_timebase", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_cycl_interval_time,
{ "Interval time", "s7comm.cyclic.interval_time", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_pbc_unknown,
{ "PBC BSEND/BRECV unknown", "s7comm.pbc.bsend.unknown", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_pbc_r_id,
{ "PBC BSEND/BRECV R_ID", "s7comm.pbc.req.bsend.r_id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_tia1200_item_reserved1,
{ "1200 sym Reserved", "s7comm.tiap.item.reserved1", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_tia1200_item_area1,
{ "1200 sym root area 1", "s7comm.tiap.item.area1", FT_UINT16, BASE_HEX, VALS(tia1200_var_item_area1_names), 0x0,
"Area from where to read: DB or Inputs, Outputs, etc.", HFILL }},
{ &hf_s7comm_tia1200_item_area2,
{ "1200 sym root area 2", "s7comm.tiap.item.area2", FT_UINT16, BASE_HEX, VALS(tia1200_var_item_area2_names), 0x0,
"Specifies the area from where to read", HFILL }},
{ &hf_s7comm_tia1200_item_area2unknown,
{ "1200 sym root area 2 unknown", "s7comm.tiap.item.area2unknown", FT_UINT16, BASE_HEX, NULL, 0x0,
"For current unknown areas", HFILL }},
{ &hf_s7comm_tia1200_item_dbnumber,
{ "1200 sym root DB number", "s7comm.tiap.item.dbnumber", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_tia1200_item_crc,
{ "1200 sym CRC", "s7comm.tiap.item.crc", FT_UINT32, BASE_HEX, NULL, 0x0,
"CRC generated out of symbolic name with (x^32+x^31+x^30+x^29+x^28+x^26+x^23+x^21+x^19+x^18+x^15+x^14+x^13+x^12+x^9+x^8+x^4+x+1)", HFILL }},
{ &hf_s7comm_tia1200_var_lid_flags,
{ "LID flags", "s7comm.tiap.item.lid_flags", FT_UINT8, BASE_DEC, VALS(tia1200_var_lid_flag_names), 0xf0,
NULL, HFILL }},
{ &hf_s7comm_tia1200_substructure_item,
{ "Substructure", "s7comm.tiap.item.substructure", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_tia1200_item_value,
{ "Value", "s7comm.tiap.item.value", FT_UINT32, BASE_DEC, NULL, 0x0fffffff,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_s7comm,
&ett_s7comm_header,
&ett_s7comm_param,
&ett_s7comm_param_item,
&ett_s7comm_param_subitem,
&ett_s7comm_data,
&ett_s7comm_data_item,
&ett_s7comm_item_address,
&ett_s7comm_diagdata_registerflag,
&ett_s7comm_userdata_blockinfo_flags,
};
proto_s7comm = proto_register_protocol (
"S7 Communication",
"S7COMM",
"s7comm"
);
proto_register_field_array(proto_s7comm, hf, array_length (hf));
s7comm_register_szl_types(proto_s7comm);
proto_register_subtree_array(ett, array_length (ett));
}
void
proto_reg_handoff_s7comm(void)
{
heur_dissector_add("cotp", dissect_s7comm, "S7 Communication over COTP", "s7comm_cotp", proto_s7comm, HEURISTIC_ENABLE);
heur_dissector_add("cotp_is", dissect_s7comm, "S7 Communication over COTP", "s7comm_cotp_is", proto_s7comm, HEURISTIC_ENABLE);
}
