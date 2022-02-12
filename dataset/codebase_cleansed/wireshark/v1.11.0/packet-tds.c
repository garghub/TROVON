static void
dissect_tds_nt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint length)
{
tvbuff_t *nt_tvb;
nt_tvb = tvb_new_subset(tvb, offset, -1, length);
if(tvb_strneql(tvb, offset, "NTLMSSP", 7) == 0)
call_dissector(ntlmssp_handle, nt_tvb, pinfo, tree);
else
call_dissector(gssapi_handle, nt_tvb, pinfo, tree);
}
static guint16
tds_tvb_get_xxtohs(tvbuff_t *tvb, gint offset, gboolean tds_little_endian_flag) {
if (tds_little_endian_flag)
return tvb_get_letohs(tvb, offset);
else
return tvb_get_ntohs(tvb, offset);
}
static guint32
tds_tvb_get_xxtohl(tvbuff_t *tvb, gint offset, gboolean tds_little_endian_flag) {
if (tds_little_endian_flag)
return tvb_get_letohl(tvb, offset);
else
return tvb_get_ntohl(tvb, offset);
}
static guint64
tds_tvb_get_xxtoh64(tvbuff_t *tvb, gint offset, gboolean tds_little_endian_flag) {
if (tds_little_endian_flag)
return tvb_get_letoh64(tvb, offset);
else
return tvb_get_ntoh64(tvb, offset);
}
static int
tds_token_is_fixed_size(guint8 token)
{
switch (token) {
case TDS_DONE_TOKEN:
case TDS_DONEPROC_TOKEN:
case TDS_DONEINPROC_TOKEN:
case TDS_RET_STAT_TOKEN:
case TDS7_RESULT_TOKEN:
case TDS_PROCID_TOKEN:
case TDS_LOGOUT_TOKEN:
return 1;
default:
return 0;
}
}
static int
tds_get_fixed_token_size(guint8 token, tds_conv_info_t *tds_info)
{
switch(token) {
case TDS_DONE_TOKEN:
case TDS_DONEPROC_TOKEN:
case TDS_DONEINPROC_TOKEN:
if (TDS_PROTO_TDS7_2_OR_GREATER) {
return 12;
} else {
return 8;
}
case TDS_PROCID_TOKEN:
return 8;
case TDS_RET_STAT_TOKEN:
return 4;
case TDS_LOGOUT_TOKEN:
return 1;
case TDS7_RESULT_TOKEN:
default:
return 0;
}
}
static guint
tds_get_variable_token_size(tvbuff_t *tvb, gint offset, guint8 token,
guint *len_field_size_p, guint *len_field_val_p)
{
switch(token) {
case TDS5_PARAMFMT2_TOKEN:
case TDS_LANG_TOKEN:
case TDS5_ORDERBY2_TOKEN:
case TDS5_CURDECLARE2_TOKEN:
case TDS5_ROWFMT2_TOKEN:
case TDS5_DYNAMIC2_TOKEN:
*len_field_size_p = 4;
*len_field_val_p = tds_tvb_get_xxtohl(tvb, offset, tds_little_endian);
break;
case TDS5_MSG_TOKEN:
*len_field_size_p = 1;
*len_field_val_p = tvb_get_guint8(tvb, offset);
break;
default:
*len_field_size_p = 2;
*len_field_val_p = tds_tvb_get_xxtohs(tvb, offset, tds_little_endian);
break;
}
return *len_field_val_p + *len_field_size_p + 1;
}
static void
dissect_tds_all_headers(tvbuff_t *tvb, guint *offset, packet_info *pinfo, proto_tree *tree)
{
proto_item *item = NULL, *total_length_item = NULL;
proto_tree *sub_tree = NULL;
guint32 total_length;
guint final_offset;
total_length = tvb_get_letohl(tvb, *offset);
if(total_length >= 0x100)
return;
item = proto_tree_add_item(tree, hf_tds_all_headers, tvb, *offset, total_length, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_tds_all_headers);
total_length_item = proto_tree_add_item(sub_tree, hf_tds_all_headers_total_length, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
final_offset = *offset + total_length;
*offset += 4;
do {
proto_tree *header_sub_tree = NULL;
proto_item *length_item = NULL, *type_item = NULL;
guint32 header_length;
guint16 header_type;
header_length = tvb_get_letohl(tvb, *offset);
item = proto_tree_add_text(sub_tree, tvb, *offset, header_length, "Header");
header_sub_tree = proto_item_add_subtree(item, ett_tds_all_headers_header);
length_item = proto_tree_add_item(header_sub_tree, hf_tds_all_headers_header_length, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
if(header_length == 0 ) {
expert_add_info_format(pinfo, length_item, &ei_tds_invalid_length, "Empty header");
break;
}
header_type = tvb_get_letohs(tvb, *offset + 4);
type_item = proto_tree_add_item(header_sub_tree, hf_tds_all_headers_header_type, tvb, *offset + 4, 2, ENC_LITTLE_ENDIAN);
switch(header_type) {
case TDS_HEADER_QUERY_NOTIF:
break;
case TDS_HEADER_TRANS_DESCR:
if(header_length != 18)
expert_add_info_format(pinfo, length_item, &ei_tds_invalid_length, "Length should equal 18");
proto_tree_add_item(header_sub_tree, hf_tds_all_headers_trans_descr, tvb, *offset + 6, 8, ENC_LITTLE_ENDIAN);
proto_tree_add_item(header_sub_tree, hf_tds_all_headers_request_cnt, tvb, *offset + 14, 4, ENC_LITTLE_ENDIAN);
break;
default:
expert_add_info(pinfo, type_item, &ei_tds_all_headers_header_type);
}
*offset += header_length;
} while(*offset < final_offset);
if(*offset != final_offset) {
expert_add_info_format(pinfo, total_length_item, &ei_tds_invalid_length, "Sum of headers' lengths (%d) differs from total headers length (%d)", total_length + *offset - final_offset, total_length);
return;
}
}
static void
dissect_tds_query_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, tds_conv_info_t *tds_info)
{
guint offset, len;
gboolean is_unicode = TRUE;
char *msg;
proto_item *query_hdr;
proto_tree *query_tree;
offset = 0;
query_hdr = proto_tree_add_text(tree, tvb, offset, -1, "TDS Query Packet");
query_tree = proto_item_add_subtree(query_hdr, ett_tds7_query);
dissect_tds_all_headers(tvb, &offset, pinfo, query_tree);
len = tvb_reported_length_remaining(tvb, offset);
if (TDS_PROTO_TDS4 ||
(!TDS_PROTO_TDS7 &&
((len < 2) || tvb_get_guint8(tvb, offset+1) != 0)))
is_unicode = FALSE;
if (is_unicode)
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, len, ENC_LITTLE_ENDIAN);
else
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, len);
proto_tree_add_text(query_tree, tvb, offset, len, "Query: %s", msg);
offset += len;
}
static void
dissect_tds5_lang_token(tvbuff_t *tvb, guint offset, guint len, proto_tree *tree) {
char *msg;
proto_tree_add_text(tree, tvb, offset, 1 , "Status: %u", tvb_get_guint8(tvb, offset));
offset += 1;
len -= 1;
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, len);
proto_tree_add_text(tree, tvb, offset, len, "Language text: %s", msg);
}
static void
dissect_tds_query5_packet(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, tds_conv_info_t *tds_info)
{
guint offset;
guint pos;
guint token_len_field_size = 2;
guint token_len_field_val = 0;
guint8 token;
guint token_sz;
proto_item *query_hdr;
proto_tree *query_tree;
proto_item *token_item;
proto_tree *token_tree;
offset = 0;
query_hdr = proto_tree_add_text(tree, tvb, offset, -1, "TDS5 Query Packet");
query_tree = proto_item_add_subtree(query_hdr, ett_tds7_query);
pos = offset;
while (tvb_reported_length_remaining(tvb, pos) > 0) {
token = tvb_get_guint8(tvb, pos);
if (tds_token_is_fixed_size(token))
token_sz = tds_get_fixed_token_size(token, tds_info) + 1;
else
token_sz = tds_get_variable_token_size(tvb, pos+1, token, &token_len_field_size,
&token_len_field_val);
if ((int) token_sz < 0) {
proto_tree_add_text(query_tree, tvb, 0, 0, "Bogus token size: %u",
token_sz);
break;
}
token_item = proto_tree_add_text(query_tree, tvb, pos, token_sz,
"Token 0x%02x %s", token,
val_to_str_const(token, token_names, "Unknown Token Type"));
token_tree = proto_item_add_subtree(token_item, ett_tds_token);
if (!tds_token_is_fixed_size(token))
proto_tree_add_text(token_tree, tvb, pos+1, token_len_field_size, "Length: %u", token_len_field_val);
switch (token) {
case TDS_LANG_TOKEN:
dissect_tds5_lang_token(tvb, pos + 5, token_sz -5, token_tree);
break;
default:
break;
}
pos += token_sz;
}
}
static void
dissect_tds7_login(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset, i, j, k, offset2, len;
char *val, *val2;
proto_item *login_hdr;
proto_tree *login_tree;
proto_item *header_hdr;
proto_tree *header_tree;
proto_item *length_hdr;
proto_tree *length_tree;
struct tds7_login_packet_hdr td7hdr;
gint length_remaining;
offset = 0;
login_hdr = proto_tree_add_text(tree, tvb, offset, -1, "TDS7 Login Packet");
login_tree = proto_item_add_subtree(login_hdr, ett_tds7_login);
header_hdr = proto_tree_add_text(login_tree, tvb, offset, 36, "Login Packet Header");
header_tree = proto_item_add_subtree(header_hdr, ett_tds7_hdr);
td7hdr.total_packet_size = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_login_total_size, tvb, offset,
sizeof(td7hdr.total_packet_size), td7hdr.total_packet_size);
offset += (int)sizeof(td7hdr.total_packet_size);
td7hdr.tds_version = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_version, tvb, offset, sizeof(td7hdr.tds_version), td7hdr.tds_version);
offset += (int)sizeof(td7hdr.tds_version);
td7hdr.packet_size = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_packet_size, tvb, offset, sizeof(td7hdr.packet_size), td7hdr.packet_size);
offset += (int)sizeof(td7hdr.packet_size);
td7hdr.client_version = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_client_version, tvb, offset, sizeof(td7hdr.client_version), td7hdr.client_version);
offset += (int)sizeof(td7hdr.client_version);
td7hdr.client_pid = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_client_pid, tvb, offset, sizeof(td7hdr.client_pid), td7hdr.client_pid);
offset += (int)sizeof(td7hdr.client_pid);
td7hdr.connection_id= tvb_get_letohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_connection_id, tvb, offset, sizeof(td7hdr.connection_id), td7hdr.connection_id);
offset += (int)sizeof(td7hdr.connection_id);
td7hdr.option_flags1 = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_option_flags1, tvb, offset, sizeof(td7hdr.option_flags1), td7hdr.option_flags1);
offset += (int)sizeof(td7hdr.option_flags1);
td7hdr.option_flags2 = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_option_flags2, tvb, offset, sizeof(td7hdr.option_flags2), td7hdr.option_flags2);
offset += (int)sizeof(td7hdr.option_flags2);
td7hdr.sql_type_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_sql_type_flags, tvb, offset, sizeof(td7hdr.sql_type_flags), td7hdr.sql_type_flags);
offset += (int)sizeof(td7hdr.sql_type_flags);
td7hdr.reserved_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_reserved_flags, tvb, offset, sizeof(td7hdr.reserved_flags), td7hdr.reserved_flags);
offset += (int)sizeof(td7hdr.reserved_flags);
td7hdr.time_zone = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_time_zone, tvb, offset, sizeof(td7hdr.time_zone), td7hdr.time_zone);
offset += (int)sizeof(td7hdr.time_zone);
td7hdr.collation = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(header_tree, hf_tds7_collation, tvb, offset, sizeof(td7hdr.collation), td7hdr.collation);
offset += (int)sizeof(td7hdr.collation);
length_hdr = proto_tree_add_text(login_tree, tvb, offset, 50, "Lengths and offsets");
length_tree = proto_item_add_subtree(length_hdr, ett_tds7_hdr);
for (i = 0; i < 9; i++) {
offset2 = tvb_get_letohs(tvb, offset + i*4);
len = tvb_get_letohs(tvb, offset + i*4 + 2);
proto_tree_add_text(length_tree, tvb, offset + i*4, 2,
"%s offset: %u",
val_to_str_const(i, login_field_names, "Unknown"),
offset2);
proto_tree_add_text(length_tree, tvb, offset + i*4 + 2, 2,
"%s length: %u",
val_to_str_const(i, login_field_names, "Unknown"),
len);
if (len != 0) {
if( i != 2) {
len *= 2;
val = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset2, len, ENC_LITTLE_ENDIAN);
proto_tree_add_text(login_tree, tvb, offset2, len, "%s: %s", val_to_str_const(i, login_field_names, "Unknown"), val);
} else {
len *= 2;
val = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset2, len);
val2 = (char *)wmem_alloc(wmem_packet_scope(), len/2+1);
for(j = 0, k = 0; j < len; j += 2, k++) {
val[j] ^= 0xA5;
val[j] = ((val[j] & 0x0F) << 4) | ((val[j] & 0xF0) >> 4);
val2[k] = val[j];
}
val2[k] = '\0';
proto_tree_add_text(login_tree, tvb, offset2, len, "%s: %s", val_to_str_const(i, login_field_names, "Unknown"), val2);
}
}
}
length_remaining = tvb_reported_length_remaining(tvb, offset2 + len);
if (length_remaining > 0) {
dissect_tds_nt(tvb, pinfo, login_tree, offset2 + len,
length_remaining);
}
}
static int
get_size_by_coltype(int servertype)
{
switch(servertype)
{
case SYBINT1: return 1;
case SYBINT2: return 2;
case SYBINT4: return 4;
case SYBINT8: return 8;
case SYBREAL: return 4;
case SYBFLT8: return 8;
case SYBDATETIME: return 8;
case SYBDATETIME4: return 4;
case SYBBIT: return 1;
case SYBBITN: return 1;
case SYBMONEY: return 8;
case SYBMONEY4: return 4;
case SYBUNIQUE: return 16;
default: return -1;
}
}
static guint
tds_get_row_size(tvbuff_t *tvb, struct _netlib_data *nl_data, guint offset)
{
guint cur, i, csize;
cur = offset;
for (i = 0; i < nl_data->num_cols; i++) {
if (!is_fixed_coltype(nl_data->columns[i]->ctype)) {
csize = tvb_get_guint8(tvb, cur);
cur++;
} else
csize = get_size_by_coltype(nl_data->columns[i]->ctype);
cur += csize;
}
return (cur - offset + 1);
}
static gboolean
dissect_tds_col_info_token(tvbuff_t *tvb, struct _netlib_data *nl_data, guint offset)
{
guint next, cur;
guint col;
next = offset + tds_tvb_get_xxtohs(tvb, offset+1, tds_little_endian) + 3;
cur = offset + 3;
col = 0;
while (cur < next) {
if (col >= MAX_COLUMNS) {
nl_data->num_cols = 0;
return FALSE;
}
nl_data->columns[col] = wmem_new(wmem_packet_scope(), struct _tds_col);
nl_data->columns[col]->name[0] ='\0';
nl_data->columns[col]->utype = tds_tvb_get_xxtohs(tvb, cur, tds_little_endian);
cur += 2;
cur += 2;
nl_data->columns[col]->ctype = tvb_get_guint8(tvb,cur);
cur++;
if (!is_fixed_coltype(nl_data->columns[col]->ctype)) {
nl_data->columns[col]->csize = tvb_get_guint8(tvb,cur);
cur ++;
} else {
nl_data->columns[col]->csize =
get_size_by_coltype(nl_data->columns[col]->ctype);
}
col += 1;
}
nl_data->num_cols = col;
return TRUE;
}
static gboolean
read_results_tds5(tvbuff_t *tvb, struct _netlib_data *nl_data, guint offset, guint len _U_)
{
guint name_len;
guint cur;
guint i;
cur = offset;
nl_data->num_cols = tds_tvb_get_xxtohs(tvb, cur, tds_little_endian);
if (nl_data->num_cols > MAX_COLUMNS) {
nl_data->num_cols = 0;
return FALSE;
}
cur += 2;
for (i = 0; i < nl_data->num_cols; i++) {
nl_data->columns[i] = wmem_new(wmem_packet_scope(), struct _tds_col);
name_len = tvb_get_guint8(tvb,cur);
cur ++;
cur += name_len;
cur++;
nl_data->columns[i]->utype = tds_tvb_get_xxtohs(tvb, cur, tds_little_endian);
cur += 2;
cur += 2;
nl_data->columns[i]->ctype = tvb_get_guint8(tvb,cur);
cur++;
if (!is_fixed_coltype(nl_data->columns[i]->ctype)) {
nl_data->columns[i]->csize = tvb_get_guint8(tvb,cur);
cur ++;
} else {
nl_data->columns[i]->csize =
get_size_by_coltype(nl_data->columns[i]->ctype);
}
cur++;
}
return TRUE;
}
static gboolean
netlib_check_login_pkt(tvbuff_t *tvb, guint offset, packet_info *pinfo, guint8 type)
{
guint tds_major, bytes_avail;
bytes_avail = tvb_length(tvb) - offset;
if (type==TDS_LOGIN_PKT) {
if (bytes_avail < 467) return FALSE;
tds_major = tvb_get_guint8(tvb, 466);
if (tds_major != 4 && tds_major != 5) {
return FALSE;
}
} else if (type==TDS_LOGIN7_PKT) {
if (bytes_avail < 16) return FALSE;
tds_major = tvb_get_guint8(tvb, 15);
if (tds_major != 0x70 && tds_major != 0x80) {
return FALSE;
}
} else if (type==TDS_QUERY5_PKT) {
if (bytes_avail < 9) return FALSE;
if (tvb_get_guint8(tvb, 8) != TDS_LANG_TOKEN) {
return FALSE;
}
}
else if (!value_is_in_range(tds_tcp_ports, pinfo->srcport) &&
!value_is_in_range(tds_tcp_ports, pinfo->destport)) {
return FALSE;
}
return TRUE;
}
static void
dissect_tds_env_chg(tvbuff_t *tvb, guint offset, guint token_sz,
proto_tree *tree)
{
guint8 env_type;
guint old_len, new_len, old_len_offset;
char *new_val = NULL, *old_val = NULL;
guint32 string_offset;
gboolean is_unicode = FALSE;
env_type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Type: %u (%s)", env_type,
val_to_str_const(env_type, env_chg_names, "Unknown"));
new_len = tvb_get_guint8(tvb, offset+1);
old_len_offset = offset + new_len + 2;
old_len = tvb_get_guint8(tvb, old_len_offset);
if (old_len + new_len + 3 != token_sz) {
is_unicode = TRUE;
old_len_offset = offset + (new_len * 2) + 2;
old_len = tvb_get_guint8(tvb, old_len_offset);
}
proto_tree_add_text(tree, tvb, offset + 1, 1, "New Value Length: %u",
new_len);
if (new_len) {
if (env_type != 7) {
string_offset = offset + 2;
if (is_unicode == TRUE) {
new_len *= 2;
new_val = tvb_get_unicode_string(wmem_packet_scope(), tvb, string_offset,
new_len, ENC_LITTLE_ENDIAN);
} else
new_val = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, string_offset, new_len);
proto_tree_add_text(tree, tvb, string_offset, new_len,
"New Value: %s", new_val);
}
else {
offset +=2;
proto_tree_add_item(tree, hf_tds_collate_codepage, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_charset_id, tvb, offset, 1, ENC_LITTLE_ENDIAN );
}
}
proto_tree_add_text(tree, tvb, old_len_offset, 1, "Old Value Length: %u",
old_len);
if (old_len) {
string_offset = old_len_offset + 1;
if (is_unicode == TRUE) {
old_len *= 2;
old_val = tvb_get_unicode_string(wmem_packet_scope(), tvb, string_offset,
old_len, ENC_LITTLE_ENDIAN);
} else
old_val = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, string_offset, old_len);
proto_tree_add_text(tree, tvb, string_offset, old_len,
"Old Value: %s", old_val);
}
}
static void
dissect_tds_err_token(tvbuff_t *tvb, guint offset, guint token_sz _U_, proto_tree *tree, tds_conv_info_t *tds_info)
{
guint16 msg_len;
guint8 srvr_len, proc_len;
char *msg;
gboolean is_unicode = FALSE;
proto_tree_add_text(tree, tvb, offset, 4, "SQL Error Number: %d", tds_tvb_get_xxtohl(tvb, offset, tds_little_endian));
offset += 4;
proto_tree_add_text(tree, tvb, offset, 1, "State: %u", tvb_get_guint8(tvb, offset));
offset +=1;
proto_tree_add_text(tree, tvb, offset, 1, "Severity Level: %u", tvb_get_guint8(tvb, offset));
offset +=1;
msg_len = tds_tvb_get_xxtohs(tvb, offset, tds_little_endian);
proto_tree_add_text(tree, tvb, offset, 1, "Error message length: %u characters", msg_len);
offset +=2;
if(tvb_get_guint8(tvb, offset+1) == 0)
is_unicode = TRUE;
if(is_unicode) {
msg_len *= 2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, msg_len, ENC_LITTLE_ENDIAN);
} else {
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, msg_len);
}
proto_tree_add_text(tree, tvb, offset, msg_len, "Error: %s", format_text((guchar*)msg, strlen(msg)));
offset += msg_len;
srvr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Server name length: %u characters", srvr_len);
offset +=1;
if(srvr_len) {
if (is_unicode) {
srvr_len *=2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, srvr_len, ENC_LITTLE_ENDIAN);
} else {
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, srvr_len);
}
proto_tree_add_text(tree, tvb, offset, srvr_len, "Server name: %s", msg);
offset += srvr_len;
}
proc_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Process name length: %u characters", proc_len);
offset +=1;
if(proc_len) {
if (is_unicode) {
proc_len *=2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, proc_len, ENC_LITTLE_ENDIAN);
} else {
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, proc_len);
}
proto_tree_add_text(tree, tvb, offset, proc_len, "Process name: %s", msg);
offset += proc_len;
}
if (TDS_PROTO_TDS7_2_OR_GREATER) {
proto_tree_add_text(tree, tvb, offset, 4, "line number: %d", tds_tvb_get_xxtohl(tvb, offset, tds_little_endian));
} else {
proto_tree_add_text(tree, tvb, offset, 2, "line number: %d", tds_tvb_get_xxtohs(tvb, offset, tds_little_endian));
}
}
static int
dissect_tds_login_ack_token(tvbuff_t *tvb, guint offset, guint token_sz, proto_tree *tree, tds_conv_info_t *tds_info)
{
guint8 msg_len;
guint32 tds_version;
char *msg;
gboolean is_unicode = FALSE;
proto_tree_add_text(tree, tvb, offset, 1, "Ack: %u", tvb_get_guint8(tvb, offset));
offset +=1;
tds_version = tvb_get_ntohl(tvb, offset);
switch (tds_version) {
case 0x07000000:
tds_info->tds7_version = TDS_PROTOCOL_7_0;
break;
case 0x07010000:
case 0x71000001:
tds_info->tds7_version = TDS_PROTOCOL_7_1;
break;
case 0x72090002:
tds_info->tds7_version = TDS_PROTOCOL_7_2;
break;
case 0x730A0003:
case 0x730B0003:
default:
tds_info->tds7_version = TDS_PROTOCOL_7_3;
break;
}
proto_tree_add_uint(tree, hf_tds7_loginack_version, tvb, offset, 4, tds_version);
offset += 4;
msg_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Text length: %u characters", msg_len);
offset +=1;
if(msg_len + 6U + 3U != token_sz - 1)
is_unicode = TRUE;
proto_tree_add_text(tree, tvb, offset, 0, "msg_len: %d, token_sz: %d, total: %d",msg_len, token_sz, msg_len + 6U + 3U);
if(is_unicode) {
msg_len *= 2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, msg_len, ENC_LITTLE_ENDIAN);
} else {
msg = (gchar*)tvb_get_string(wmem_packet_scope(), tvb, offset, msg_len);
}
proto_tree_add_text(tree, tvb, offset, msg_len, "Text: %s", format_text((guchar*)msg, strlen(msg)));
offset += msg_len;
proto_tree_add_text(tree, tvb, offset, 4, "Server Version");
offset += 4;
return offset;
}
static int
dissect_tds7_results_token(tvbuff_t *tvb, guint offset, proto_tree *tree, tds_conv_info_t *tds_info)
{
guint16 num_columns, table_len;
guint8 type, msg_len;
int i;
char *msg;
num_columns = tvb_get_letohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Columns: %u", tvb_get_letohs(tvb, offset));
offset +=2;
for(i=0; i != num_columns; i++) {
proto_tree_add_text(tree, tvb, offset, 0, "Column %d", i + 1);
if (TDS_PROTO_TDS7_2_OR_GREATER) {
proto_tree_add_text(tree, tvb, offset, 4, "usertype: %d", tvb_get_letohl(tvb, offset));
offset +=4;
} else {
proto_tree_add_text(tree, tvb, offset, 2, "usertype: %d", tvb_get_letohs(tvb, offset));
offset +=2;
}
proto_tree_add_text(tree, tvb, offset, 2, "flags: %d", tvb_get_letohs(tvb, offset));
offset +=2;
type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Type: %d", type);
offset +=1;
if(type == 38 || type == 104 || type == 109 || type == 111) {
proto_tree_add_text(tree, tvb, offset, 1, "unknown 1 byte (%x)", tvb_get_guint8(tvb, offset));
offset +=1;
}
else if (type == 35) {
proto_tree_add_text(tree, tvb, offset, 4, "unknown 4 bytes (%x)", tvb_get_letohl(tvb, offset));
offset += 4;
proto_tree_add_item(tree, hf_tds_collate_codepage, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_charset_id, tvb, offset, 1, ENC_LITTLE_ENDIAN );
offset +=1;
table_len = tvb_get_letohs(tvb, offset);
offset +=2;
if(table_len != 0) {
table_len *= 2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, table_len, ENC_LITTLE_ENDIAN);
proto_tree_add_text(tree, tvb, offset, table_len, "Table name: %s", msg);
offset += table_len;
}
}
else if (type == 106 || type == 108) {
proto_tree_add_text(tree, tvb, offset, 3, "unknown 3 bytes");
offset +=3;
}
else if(type > 128) {
proto_tree_add_text(tree, tvb, offset, 2, "Large type size: 0x%x", tvb_get_letohs(tvb, offset));
offset += 2;
if (type != 165) {
proto_tree_add_item(tree, hf_tds_collate_codepage, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN );
offset += 2;
proto_tree_add_item(tree, hf_tds_collate_charset_id, tvb, offset, 1, ENC_LITTLE_ENDIAN );
offset +=1;
}
}
msg_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "message length: %d",msg_len);
offset += 1;
if(msg_len != 0) {
msg_len *= 2;
msg = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, msg_len, ENC_LITTLE_ENDIAN);
proto_tree_add_text(tree, tvb, offset, msg_len, "Text: %s", msg);
offset += msg_len;
}
}
return offset;
}
static void
dissect_tds_done_token(tvbuff_t *tvb, guint offset, proto_tree *tree, tds_conv_info_t *tds_info)
{
proto_tree_add_text(tree, tvb, offset, 2, "Status flags");
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Operation");
offset += 2;
if (TDS_PROTO_TDS7_2_OR_GREATER) {
proto_tree_add_text(tree, tvb, offset, 8, "row count: %" G_GINT64_MODIFIER "u",
tds_tvb_get_xxtoh64(tvb, offset, tds_little_endian));
} else {
proto_tree_add_text(tree, tvb, offset, 4, "row count: %u",
tds_tvb_get_xxtohl(tvb, offset, tds_little_endian));
}
}
static guint8
dissect_tds_type_info(tvbuff_t *tvb, guint *offset, packet_info *pinfo, proto_tree *tree, gboolean *plp)
{
proto_item *item = NULL, *item1 = NULL, *data_type_item = NULL;
proto_tree *sub_tree = NULL, *collation_tree;
guint32 varlen, varlen_len = 0;
guint8 data_type;
*plp = FALSE;
item = proto_tree_add_item(tree, hf_tds_type_info, tvb, *offset, 0, ENC_NA);
data_type = tvb_get_guint8(tvb, *offset);
proto_item_append_text(item, " (%s)", val_to_str(data_type, tds_data_type_names, "Invalid data type: %02X"));
sub_tree = proto_item_add_subtree(item, ett_tds_type_info);
data_type_item = proto_tree_add_item(sub_tree, hf_tds_type_info_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
switch(data_type) {
case TDS_DATA_TYPE_NULL:
case TDS_DATA_TYPE_INT1:
case TDS_DATA_TYPE_BIT:
case TDS_DATA_TYPE_INT2:
case TDS_DATA_TYPE_INT4:
case TDS_DATA_TYPE_FLT4:
case TDS_DATA_TYPE_DATETIM4:
case TDS_DATA_TYPE_MONEY4:
case TDS_DATA_TYPE_INT8:
case TDS_DATA_TYPE_FLT8:
case TDS_DATA_TYPE_MONEY:
case TDS_DATA_TYPE_DATETIME:
case TDS_DATA_TYPE_TIMEN:
case TDS_DATA_TYPE_DATETIME2N:
case TDS_DATA_TYPE_DATETIMEOFFSETN:
varlen_len = 0;
break;
case TDS_DATA_TYPE_GUID:
case TDS_DATA_TYPE_INTN:
case TDS_DATA_TYPE_DECIMAL:
case TDS_DATA_TYPE_NUMERIC:
case TDS_DATA_TYPE_BITN:
case TDS_DATA_TYPE_DECIMALN:
case TDS_DATA_TYPE_NUMERICN:
case TDS_DATA_TYPE_FLTN:
case TDS_DATA_TYPE_MONEYN:
case TDS_DATA_TYPE_DATETIMN:
case TDS_DATA_TYPE_DATEN:
case TDS_DATA_TYPE_CHAR:
case TDS_DATA_TYPE_VARCHAR:
case TDS_DATA_TYPE_BINARY:
case TDS_DATA_TYPE_VARBINARY:
varlen_len = 1;
varlen = tvb_get_guint8(tvb, *offset);
break;
case TDS_DATA_TYPE_BIGVARCHR:
case TDS_DATA_TYPE_BIGVARBIN:
case TDS_DATA_TYPE_NVARCHAR:
varlen_len = 2;
varlen = tvb_get_letohs(tvb, *offset);
if(varlen == 0xFFFF)
*plp = TRUE;
break;
case TDS_DATA_TYPE_BIGBINARY:
case TDS_DATA_TYPE_BIGCHAR:
case TDS_DATA_TYPE_NCHAR:
varlen_len = 2;
varlen = tvb_get_letohs(tvb, *offset);
break;
case TDS_DATA_TYPE_XML:
case TDS_DATA_TYPE_UDT:
*plp = TRUE;
case TDS_DATA_TYPE_TEXT:
case TDS_DATA_TYPE_IMAGE:
case TDS_DATA_TYPE_NTEXT:
case TDS_DATA_TYPE_SSVARIANT:
varlen_len = 4;
varlen = tvb_get_letohl(tvb, *offset);
break;
default:
expert_add_info(pinfo, data_type_item, &ei_tds_type_info_type);
THROW(ReportedBoundsError);
}
if(varlen_len)
item1 = proto_tree_add_uint(sub_tree, hf_tds_type_info_varlen, tvb, *offset, varlen_len, varlen);
if(*plp)
proto_item_append_text(item1, " (PLP - Partially Length-Prefixed data type)");
*offset += varlen_len;
switch(data_type) {
case TDS_DATA_TYPE_DECIMAL:
case TDS_DATA_TYPE_NUMERIC:
case TDS_DATA_TYPE_DECIMALN:
case TDS_DATA_TYPE_NUMERICN:
proto_tree_add_item(sub_tree, hf_tds_type_info_precision, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
case TDS_DATA_TYPE_TIMEN:
case TDS_DATA_TYPE_DATETIME2N:
case TDS_DATA_TYPE_DATETIMEOFFSETN:
proto_tree_add_item(sub_tree, hf_tds_type_info_scale, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case TDS_DATA_TYPE_BIGCHAR:
case TDS_DATA_TYPE_BIGVARCHR:
case TDS_DATA_TYPE_TEXT:
case TDS_DATA_TYPE_NTEXT:
case TDS_DATA_TYPE_NCHAR:
case TDS_DATA_TYPE_NVARCHAR:
item1 = proto_tree_add_item(sub_tree, hf_tds_type_info_collation, tvb, *offset, 5, ENC_NA);
collation_tree = proto_item_add_subtree(item1, ett_tds_type_info_collation);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_lcid, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_ign_case, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_ign_accent, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_ign_kana, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_ign_width, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_binary, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_version, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(collation_tree, hf_tds_type_info_collation_sortid, tvb, *offset + 4, 1, ENC_LITTLE_ENDIAN);
*offset += 5;
break;
}
proto_item_set_end(item, tvb, *offset);
return data_type;
}
static void
dissect_tds_type_varbyte(tvbuff_t *tvb, guint *offset, packet_info *pinfo, proto_tree *tree, int hf, guint8 data_type, gboolean plp)
{
#define GEN_NULL 0x00U
#define CHARBIN_NULL 0xFFFFU
#define CHARBIN_NULL32 0xFFFFFFFFU
guint32 length;
char *string_value;
proto_tree *sub_tree = NULL;
proto_item *item = NULL, *length_item = NULL;
item = proto_tree_add_item(tree, hf, tvb, *offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_tds_type_varbyte);
if(plp) {
#define PLP_TERMINATOR G_GINT64_CONSTANT(0x0000000000000000U)
#define UNKNOWN_PLP_LEN G_GINT64_CONSTANT(0xFFFFFFFFFFFFFFFEU)
#define PLP_NULL G_GINT64_CONSTANT(0xFFFFFFFFFFFFFFFFU)
guint64 plp_length = tvb_get_letoh64(tvb, *offset);
length_item = proto_tree_add_item(sub_tree, hf_tds_type_varbyte_plp_len, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
if(plp_length == PLP_NULL)
proto_item_append_text(length_item, " (PLP_NULL)");
else {
if(plp_length == UNKNOWN_PLP_LEN)
proto_item_append_text(length_item, " (UNKNOWN_PLP_LEN)");
while(TRUE) {
length = tvb_get_letohl(tvb, *offset);
length_item = proto_tree_add_item(sub_tree, hf_tds_type_varbyte_plp_chunk_len, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
if(length == PLP_TERMINATOR) {
proto_item_append_text(length_item, " (PLP_TERMINATOR)");
break;
}
switch(data_type) {
case TDS_DATA_TYPE_BIGVARBIN:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_bytes, tvb, *offset, length, ENC_NA);
break;
case TDS_DATA_TYPE_BIGVARCHR:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_string, tvb, *offset, length, ENC_ASCII|ENC_NA);
break;
case TDS_DATA_TYPE_NVARCHAR:
string_value = tvb_get_unicode_string(wmem_packet_scope(), tvb, *offset, length, ENC_LITTLE_ENDIAN);
proto_tree_add_string(sub_tree, hf_tds_type_varbyte_data_string, tvb, *offset, length, string_value);
break;
case TDS_DATA_TYPE_XML:
case TDS_DATA_TYPE_UDT:
proto_tree_add_expert_format(sub_tree, pinfo, &ei_tds_type_info_type_undecoded, tvb, *offset, length, "Data type %d not supported yet", data_type);
THROW(ReportedBoundsError);
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
*offset += length;
}
}
}
else switch(data_type) {
case TDS_DATA_TYPE_NULL:
break;
case TDS_DATA_TYPE_BIT:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_boolean, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case TDS_DATA_TYPE_INT1:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int1, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case TDS_DATA_TYPE_INT2:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int2, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case TDS_DATA_TYPE_INT4:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int4, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
break;
case TDS_DATA_TYPE_INT8:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int8, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
break;
case TDS_DATA_TYPE_FLT4:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_float, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
break;
case TDS_DATA_TYPE_FLT8:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_double, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
*offset += 8;
break;
case TDS_DATA_TYPE_MONEY4:
case TDS_DATA_TYPE_DATETIM4:
*offset += 4;
break;
case TDS_DATA_TYPE_MONEY:
case TDS_DATA_TYPE_DATETIME:
*offset += 8;
break;
case TDS_DATA_TYPE_GUID:
length = tvb_get_guint8(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 1, length);
switch(length) {
case GEN_NULL: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA); break;
case 16: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_guid, tvb, *offset + 1, length, ENC_LITTLE_ENDIAN); break;
default: expert_add_info(pinfo, length_item, &ei_tds_invalid_length);
}
*offset += 1 + length;
break;
case TDS_DATA_TYPE_BITN:
length = tvb_get_guint8(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 1, length);
switch(length) {
case GEN_NULL: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA); break;
case 1: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_boolean, tvb, *offset + 1, 1, ENC_LITTLE_ENDIAN); break;
default: expert_add_info(pinfo, length_item, &ei_tds_invalid_length);
}
*offset += 1 + length;
break;
case TDS_DATA_TYPE_INTN:
length = tvb_get_guint8(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 1, length);
switch(length) {
case GEN_NULL: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA); break;
case 1: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int1, tvb, *offset + 1, 1, ENC_LITTLE_ENDIAN); break;
case 2: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int2, tvb, *offset + 1, 2, ENC_LITTLE_ENDIAN); break;
case 4: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int4, tvb, *offset + 1, 4, ENC_LITTLE_ENDIAN); break;
case 8: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_int8, tvb, *offset + 1, 8, ENC_LITTLE_ENDIAN); break;
default: expert_add_info(pinfo, length_item, &ei_tds_invalid_length);
}
*offset += 1 + length;
break;
case TDS_DATA_TYPE_FLTN:
length = tvb_get_guint8(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 1, length);
switch(length) {
case GEN_NULL: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA); break;
case 4: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_float, tvb, *offset + 1, 4, ENC_LITTLE_ENDIAN); break;
case 8: proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_double, tvb, *offset + 1, 8, ENC_LITTLE_ENDIAN); break;
default: expert_add_info(pinfo, length_item, &ei_tds_invalid_length);
}
*offset += 1 + length;
break;
case TDS_DATA_TYPE_DECIMAL:
case TDS_DATA_TYPE_NUMERIC:
case TDS_DATA_TYPE_DECIMALN:
case TDS_DATA_TYPE_NUMERICN:
case TDS_DATA_TYPE_MONEYN:
case TDS_DATA_TYPE_DATETIMN:
case TDS_DATA_TYPE_DATEN:
case TDS_DATA_TYPE_TIMEN:
case TDS_DATA_TYPE_DATETIME2N:
case TDS_DATA_TYPE_DATETIMEOFFSETN:
case TDS_DATA_TYPE_CHAR:
case TDS_DATA_TYPE_VARCHAR:
case TDS_DATA_TYPE_BINARY:
case TDS_DATA_TYPE_VARBINARY:
length = tvb_get_guint8(tvb, *offset);
proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 1, length);
*offset += 1;
if(length > 0) {
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_bytes, tvb, *offset, length, ENC_NA);
*offset += length;
}
break;
case TDS_DATA_TYPE_BIGVARBIN:
case TDS_DATA_TYPE_BIGBINARY:
case TDS_DATA_TYPE_BIGVARCHR:
case TDS_DATA_TYPE_BIGCHAR:
case TDS_DATA_TYPE_NVARCHAR:
case TDS_DATA_TYPE_NCHAR:
length = tvb_get_letohs(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 2, length);
*offset += 2;
if(length == CHARBIN_NULL) {
proto_item_append_text(length_item, " (CHARBIN_NULL)");
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA);
}
else {
switch(data_type) {
case TDS_DATA_TYPE_BIGVARBIN:
case TDS_DATA_TYPE_BIGBINARY:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_bytes, tvb, *offset, length, ENC_NA);
break;
case TDS_DATA_TYPE_BIGVARCHR:
case TDS_DATA_TYPE_BIGCHAR:
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_string, tvb, *offset, length, ENC_ASCII|ENC_NA);
break;
case TDS_DATA_TYPE_NVARCHAR:
case TDS_DATA_TYPE_NCHAR:
string_value = tvb_get_unicode_string(wmem_packet_scope(), tvb, *offset, length, ENC_LITTLE_ENDIAN);
proto_tree_add_string(sub_tree, hf_tds_type_varbyte_data_string, tvb, *offset, length, string_value);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
*offset += length;
}
break;
case TDS_DATA_TYPE_NTEXT:
case TDS_DATA_TYPE_XML:
case TDS_DATA_TYPE_UDT:
case TDS_DATA_TYPE_TEXT:
case TDS_DATA_TYPE_IMAGE:
case TDS_DATA_TYPE_SSVARIANT:
length = tvb_get_letohl(tvb, *offset);
length_item = proto_tree_add_uint(sub_tree, hf_tds_type_varbyte_length, tvb, *offset, 4, length);
*offset += 4;
if(length == CHARBIN_NULL32) {
proto_item_append_text(length_item, " (CHARBIN_NULL)");
proto_tree_add_item(sub_tree, hf_tds_type_varbyte_data_null, tvb, *offset, 0, ENC_NA);
}
else {
switch(data_type) {
case TDS_DATA_TYPE_NTEXT:
string_value = tvb_get_unicode_string(wmem_packet_scope(), tvb, *offset, length, ENC_LITTLE_ENDIAN);
proto_tree_add_string(sub_tree, hf_tds_type_varbyte_data_string, tvb, *offset, length, string_value);
break;
default:
proto_tree_add_expert_format(sub_tree, pinfo, &ei_tds_type_info_type_undecoded, tvb, *offset, length, "Data type %d not supported yet", data_type);
THROW(ReportedBoundsError);
}
*offset += length;
}
break;
}
proto_item_set_end(item, tvb, *offset);
}
static void
dissect_tds_rpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item = NULL, *param_item = NULL;
proto_tree *sub_tree = NULL, *status_sub_tree = NULL;
int offset = 0;
guint len;
char *val;
guint8 data_type;
item = proto_tree_add_item(tree, hf_tds_rpc, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tds_message);
dissect_tds_all_headers(tvb, &offset, pinfo, tree);
while(tvb_length_remaining(tvb, offset) > 0) {
switch(tds_protocol_type) {
case TDS_PROTOCOL_4:
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_tds_rpc_name_length8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_tds_rpc_name, tvb, offset + 1, len, ENC_ASCII|ENC_NA);
offset += 1 + len;
break;
case TDS_PROTOCOL_7_0:
case TDS_PROTOCOL_7_1:
case TDS_PROTOCOL_7_2:
case TDS_PROTOCOL_7_3:
default:
len = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_tds_rpc_name_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (len == 0xFFFF) {
proto_tree_add_item(tree, hf_tds_rpc_proc_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
else if (len != 0) {
len *= 2;
val = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, len, ENC_LITTLE_ENDIAN);
proto_tree_add_string(tree, hf_tds_rpc_name, tvb, offset, len, val);
offset += len;
}
break;
}
item = proto_tree_add_item(tree, hf_tds_rpc_options, tvb, offset, 2, ENC_LITTLE_ENDIAN);
sub_tree = proto_item_add_subtree(item, ett_tds_rpc_options);
proto_tree_add_item(sub_tree, hf_tds_rpc_options_with_recomp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_tds_rpc_options_no_metadata, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(sub_tree, hf_tds_rpc_options_reuse_metadata, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
while(tvb_length_remaining(tvb, offset) > 0) {
gboolean plp;
len = tvb_get_guint8(tvb, offset);
if((gint8)len < 0) {
proto_tree_add_item(tree, hf_tds_rpc_separator, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
break;
}
param_item = proto_tree_add_item(tree, hf_tds_rpc_parameter, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(param_item, ett_tds_rpc_parameter);
proto_tree_add_item(sub_tree, hf_tds_rpc_parameter_name_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
if(len) {
len *= 2;
val = tvb_get_unicode_string(wmem_packet_scope(), tvb, offset, len, ENC_LITTLE_ENDIAN);
proto_tree_add_string(sub_tree, hf_tds_rpc_parameter_name, tvb, offset, len, val);
offset += len;
}
item = proto_tree_add_item(sub_tree, hf_tds_rpc_parameter_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
status_sub_tree = proto_item_add_subtree(item, ett_tds_rpc_parameter_status);
proto_tree_add_item(status_sub_tree, hf_tds_rpc_parameter_status_by_ref, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(status_sub_tree, hf_tds_rpc_parameter_status_default, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
data_type = dissect_tds_type_info(tvb, &offset, pinfo, sub_tree, &plp);
dissect_tds_type_varbyte(tvb, &offset, pinfo, sub_tree, hf_tds_rpc_parameter_value, data_type, plp);
proto_item_set_end(param_item, tvb, offset);
}
}
}
static void
dissect_tds_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, tds_conv_info_t *tds_info)
{
int offset = 0;
proto_item *token_item;
proto_tree *token_tree;
guint pos, token_sz = 0;
guint token_len_field_size = 2;
guint token_len_field_val = 0;
guint8 token;
struct _netlib_data nl_data;
gint length_remaining;
memset(&nl_data, '\0', sizeof nl_data);
pos = offset;
while (tvb_reported_length_remaining(tvb, pos) > 0) {
token = tvb_get_guint8(tvb, pos);
if (tds_token_is_fixed_size(token)) {
token_sz = tds_get_fixed_token_size(token, tds_info) + 1;
} else if (token == TDS_ROW_TOKEN) {
token_sz = tds_get_row_size(tvb, &nl_data, pos + 1);
} else
token_sz = tds_get_variable_token_size(tvb, pos + 1,
token, &token_len_field_size, &token_len_field_val);
length_remaining = tvb_ensure_length_remaining(tvb, pos);
if ((int) token_sz < 0) {
token_item = proto_tree_add_text(tree, tvb, pos, 0, "Token");
expert_add_info_format(pinfo, token_item, &ei_tds_token_length_invalid, "Bogus token size: %u", token_sz);
break;
}
token_item = proto_tree_add_text(tree, tvb, pos, token_sz,
"Token 0x%02x %s", token,
val_to_str_const(token, token_names, "Unknown Token Type"));
if ((int) token_len_field_size < 0) {
expert_add_info_format(pinfo, token_item, &ei_tds_token_length_invalid, "Bogus token length field size: %u", token_len_field_size);
break;
}
token_tree = proto_item_add_subtree(token_item, ett_tds_token);
if (!tds_token_is_fixed_size(token) && token != TDS_ROW_TOKEN) {
proto_tree_add_text(token_tree, tvb, pos + 1,
token_len_field_size, "Length: %u",
token_len_field_val);
}
if (token_sz > (guint)length_remaining)
token_sz = (guint)length_remaining;
switch (token) {
case TDS_COL_NAME_TOKEN:
break;
case TDS_COL_INFO_TOKEN:
dissect_tds_col_info_token(tvb, &nl_data, pos);
break;
case TDS_RESULT_TOKEN:
read_results_tds5(tvb, &nl_data, pos + 3, token_sz - 3);
break;
case TDS_ENV_CHG_TOKEN:
dissect_tds_env_chg(tvb, pos + 3, token_sz - 3, token_tree);
break;
case TDS_AUTH_TOKEN:
dissect_tds_nt(tvb, pinfo, token_tree, pos + 3, token_sz - 3);
break;
case TDS_ERR_TOKEN:
case TDS_MSG_TOKEN:
dissect_tds_err_token(tvb, pos + 3, token_sz - 3, token_tree, tds_info);
break;
case TDS_DONE_TOKEN:
case TDS_DONEPROC_TOKEN:
case TDS_DONEINPROC_TOKEN:
dissect_tds_done_token(tvb, pos + 1, token_tree, tds_info);
break;
case TDS_LOGIN_ACK_TOKEN:
dissect_tds_login_ack_token(tvb, pos + 3, token_sz - 3, token_tree, tds_info);
break;
case TDS7_RESULT_TOKEN:
pos = (dissect_tds7_results_token(tvb, pos + 1, token_tree, tds_info)-1);
break;
}
pos += token_sz;
}
}
static void
dissect_netlib_buffer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_item *tds_item = NULL;
proto_tree *tds_tree = NULL;
proto_tree *tds_status_tree = NULL;
guint8 type;
guint8 status;
guint16 channel;
guint8 packet_number;
gboolean save_fragmented;
int len;
fragment_head *fd_head;
tvbuff_t *next_tvb;
conversation_t *conv;
tds_conv_info_t *tds_info;
conv = find_or_create_conversation(pinfo);
tds_info = (tds_conv_info_t*)conversation_get_proto_data(conv, proto_tds);
if (!tds_info) {
tds_info = wmem_new(wmem_file_scope(), tds_conv_info_t);
tds_info->tds7_version = TDS_PROTOCOL_NOT_SPECIFIED;
conversation_add_proto_data(conv, proto_tds, tds_info);
}
type = tvb_get_guint8(tvb, offset);
status = tvb_get_guint8(tvb, offset + 1);
channel = tvb_get_ntohs(tvb, offset + 4);
packet_number = tvb_get_guint8(tvb, offset + 6);
tds_item = proto_tree_add_item(tree, proto_tds, tvb, offset, -1, ENC_NA);
tds_tree = proto_item_add_subtree(tds_item, ett_tds);
proto_tree_add_item(tds_tree, hf_tds_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tds_item = proto_tree_add_item(tds_tree, hf_tds_status, tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
tds_status_tree = proto_item_add_subtree(tds_item, ett_tds_status);
proto_tree_add_item(tds_status_tree, hf_tds_status_eom, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_status_tree, hf_tds_status_ignore, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_status_tree, hf_tds_status_event_notif, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_status_tree, hf_tds_status_reset_conn, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_status_tree, hf_tds_status_reset_conn_skip_tran,tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_tree, hf_tds_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_tree, hf_tds_channel, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tds_tree, hf_tds_packet_number, tvb, offset + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tds_tree, hf_tds_window, tvb, offset + 7, 1, ENC_LITTLE_ENDIAN);
offset += 8;
save_fragmented = pinfo->fragmented;
if (tds_defragment &&
(packet_number > 1 || (status & STATUS_LAST_BUFFER) == 0)) {
if ((status & STATUS_LAST_BUFFER) == 0) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Not last buffer)");
}
len = tvb_reported_length_remaining(tvb, offset);
fd_head = fragment_add_seq_check(&tds_reassembly_table, tvb, offset,
pinfo, channel, NULL,
packet_number - 1, len, (status & STATUS_LAST_BUFFER) == 0);
next_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled TDS", fd_head, &tds_frag_items, NULL,
tds_tree);
} else {
if ((status & STATUS_LAST_BUFFER) == 0)
next_tvb = NULL;
else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
}
if (next_tvb != NULL) {
switch (type) {
case TDS_RPC_PKT:
dissect_tds_rpc(next_tvb, pinfo, tds_tree);
break;
case TDS_RESP_PKT:
dissect_tds_resp(next_tvb, pinfo, tds_tree, tds_info);
break;
case TDS_LOGIN7_PKT:
dissect_tds7_login(next_tvb, pinfo, tds_tree);
break;
case TDS_QUERY_PKT:
dissect_tds_query_packet(next_tvb, pinfo, tds_tree, tds_info);
break;
case TDS_QUERY5_PKT:
dissect_tds_query5_packet(next_tvb, pinfo, tds_tree, tds_info);
break;
case TDS_SSPI_PKT:
dissect_tds_nt(next_tvb, pinfo, tds_tree, offset - 8, -1);
break;
default:
proto_tree_add_text(tds_tree, next_tvb, 0, -1,
"TDS Packet");
break;
}
} else {
next_tvb = tvb_new_subset_remaining (tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tds_tree);
}
pinfo->fragmented = save_fragmented;
}
static void
dissect_tds_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
volatile gboolean first_time = TRUE;
volatile int offset = 0;
guint length_remaining;
guint8 type;
guint16 plen;
guint length;
tvbuff_t *volatile next_tvb;
proto_item *tds_item = NULL;
proto_tree *tds_tree = NULL;
void *pd_save;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (tds_desegment && pinfo->can_desegment) {
if (length_remaining < 8) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
type = tvb_get_guint8(tvb, offset);
plen = tvb_get_ntohs(tvb, offset + 2);
if (plen < 8) {
if (tree) {
tds_item = proto_tree_add_item(tree, proto_tds,
tvb, offset, -1, ENC_NA);
tds_tree = proto_item_add_subtree(tds_item,
ett_tds);
proto_tree_add_uint(tds_tree, hf_tds_type, tvb,
offset, 1, type);
proto_tree_add_item(tds_tree, hf_tds_status,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
tds_item = proto_tree_add_uint(tds_tree, hf_tds_length, tvb, offset + 2, 2, plen);
expert_add_info_format(pinfo, tds_item, &ei_tds_invalid_length, "bogus, should be >= 8");
}
break;
}
if (tds_desegment && pinfo->can_desegment) {
if (length_remaining < plen) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = plen - length_remaining;
return;
}
}
if (first_time) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TDS");
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(type, packet_type_names,
"Unknown Packet Type: %u"));
first_time = FALSE;
}
length = length_remaining;
if (length > plen)
length = plen;
next_tvb = tvb_new_subset(tvb, offset, length, plen);
pd_save = pinfo->private_data;
TRY {
dissect_netlib_buffer(next_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
pinfo->private_data = pd_save;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset += plen;
}
}
static gboolean
dissect_tds_tcp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint8 type;
guint8 status;
guint16 plen;
conversation_t *conv;
if (tvb_length(tvb) < 8)
return FALSE;
while (tvb_bytes_exist(tvb, offset, 1)) {
type = tvb_get_guint8(tvb, offset);
if (!is_valid_tds_type(type))
return FALSE;
if (!tvb_bytes_exist(tvb, offset + 1, 1))
break;
status = tvb_get_guint8(tvb, offset + 1);
if (!is_valid_tds_status(status))
return FALSE;
if (!tvb_bytes_exist(tvb, offset + 2, 2))
break;
plen = tvb_get_ntohs(tvb, offset + 2);
if (plen < 8) {
return FALSE;
}
if (offset == 0) {
if (!netlib_check_login_pkt(tvb, offset, pinfo, type))
return FALSE;
}
offset += plen;
}
conv = find_or_create_conversation(pinfo);
conversation_set_dissector(conv, tds_tcp_handle);
dissect_tds_tcp(tvb, pinfo, tree);
return TRUE;
}
static void
tds_init(void)
{
reassembly_table_init(&tds_reassembly_table,
&addresses_ports_reassembly_table_functions);
}
void
proto_register_tds(void)
{
static hf_register_info hf[] = {
{ &hf_tds_type,
{ "Type", "tds.type",
FT_UINT8, BASE_DEC, VALS(packet_type_names), 0x0,
"Packet type", HFILL }
},
{ &hf_tds_status,
{ "Status", "tds.status",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Packet status", HFILL }
},
{ &hf_tds_status_eom,
{ "End of message", "tds.status.eom",
FT_BOOLEAN, 8, NULL, STATUS_LAST_BUFFER,
"The packet is the last packet in the whole request", HFILL }
},
{ &hf_tds_status_ignore,
{ "Ignore this event", "tds.status.ignore",
FT_BOOLEAN, 8, NULL, STATUS_IGNORE_EVENT,
"(From client to server) Ignore this event (EOM MUST also be set)", HFILL }
},
{ &hf_tds_status_event_notif,
{ "Event notification", "tds.status.event_notif",
FT_BOOLEAN, 8, NULL, STATUS_EVENT_NOTIFICATION,
NULL, HFILL }
},
{ &hf_tds_status_reset_conn,
{ "Reset connection", "tds.status.reset_conn",
FT_BOOLEAN, 8, NULL, STATUS_RESETCONNECTION,
"(From client to server) Reset this connection before processing event", HFILL }
},
{ &hf_tds_status_reset_conn_skip_tran,
{ "Reset connection keeping transaction state", "tds.status.reset_conn_skip_tran",
FT_BOOLEAN, 8, NULL, STATUS_RESETCONNECTIONSKIPTRAN,
"(From client to server) Reset the connection before processing event but do not modify the transaction state", HFILL }
},
{ &hf_tds_length,
{ "Length", "tds.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Packet length", HFILL }
},
{ &hf_tds_channel,
{ "Channel", "tds.channel",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Channel Number", HFILL }
},
{ &hf_tds_packet_number,
{ "Packet Number", "tds.packet_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_window,
{ "Window", "tds.window",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_collate_codepage,
{ "Codepage", "tds.collate_codepage",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_collate_flags,
{ "Flags", "tds.collate_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_collate_charset_id,
{ "Charset ID", "tds.collate_charset_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_fragment_overlap,
{ "Segment overlap", "tds.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }
},
{ &hf_tds_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "tds.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{ &hf_tds_fragment_multiple_tails,
{ "Multiple tail fragments found", "tds.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{ &hf_tds_fragment_too_long_fragment,
{ "Segment too long", "tds.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of packet", HFILL }
},
{ &hf_tds_fragment_error,
{ "Defragmentation error", "tds.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{ &hf_tds_fragment_count,
{ "Segment count", "tds.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_fragment,
{ "TDS Fragment", "tds.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_fragments,
{ "TDS Fragments", "tds.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_reassembled_in,
{ "Reassembled TDS in frame", "tds.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This TDS packet is reassembled in this frame", HFILL }
},
{ &hf_tds_reassembled_length,
{ "Reassembled TDS length", "tds.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
},
{ &hf_tds7_login_total_size,
{ "Total Packet Length", "tds.7login.total_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"TDS7 Login Packet total packet length", HFILL }
},
{ &hf_tds7_version,
{ "TDS version", "tds.7login.version",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_packet_size,
{ "Packet Size", "tds.7login.packet_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_client_version,
{ "Client version", "tds.7login.client_version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_client_pid,
{ "Client PID", "tds.7login.client_pid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_connection_id,
{ "Connection ID", "tds.7login.connection_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_option_flags1,
{ "Option Flags 1", "tds.7login.option_flags1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_option_flags2,
{ "Option Flags 2", "tds.7login.option_flags2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_sql_type_flags,
{ "SQL Type Flags", "tds.7login.sql_type_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_reserved_flags,
{ "Reserved Flags", "tds.7login.reserved_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_time_zone,
{ "Time Zone", "tds.7login.time_zone",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_collation,
{ "Collation", "tds.7login.collation",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds7_loginack_version,
{ "TDS version", "tds.7loginack.version",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_all_headers,
{ "Packet data stream headers", "tds.all_headers",
FT_NONE, BASE_NONE, NULL, 0x0,
"The ALL_HEADERS rule", HFILL }
},
{ &hf_tds_all_headers_total_length,
{ "Total length", "tds.all_headers.total_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of ALL_HEADERS stream", HFILL }
},
{ &hf_tds_all_headers_header_length,
{ "Length", "tds.all_headers.header.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of an individual header", HFILL }
},
{ &hf_tds_all_headers_header_type,
{ "Type", "tds.all_headers.header.type",
FT_UINT16, BASE_HEX, VALS(header_type_names), 0x0,
NULL, HFILL }
},
{ &hf_tds_all_headers_trans_descr,
{ "Transaction descriptor", "tds.all_headers.header.trans_descr",
FT_UINT64, BASE_DEC, NULL, 0x0,
"For each connection, a number that uniquely identifies the transaction the request is associated with. Initially generated by the server when a new transaction is created and returned to the client as part of the ENVCHANGE token stream.", HFILL }
},
{ &hf_tds_all_headers_request_cnt,
{ "Outstanding request count", "tds.all_headers.header.request_cnt",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of requests currently active on the connection", HFILL }
},
{ &hf_tds_type_info,
{ "Type info", "tds.type_info",
FT_NONE, BASE_NONE, NULL, 0x0,
"The TYPE_INFO rule applies to several messages used to describe column information", HFILL }
},
{ &hf_tds_type_info_type,
{ "Type", "tds.type_info.type",
FT_UINT8, BASE_HEX, VALS(tds_data_type_names), 0x0,
NULL, HFILL }
},
{ &hf_tds_type_info_varlen,
{ "Maximal length", "tds.type_info.varlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Defines the length of the data contained within the column", HFILL }
},
{ &hf_tds_type_info_precision,
{ "Precision", "tds.type_info.precision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_info_scale,
{ "Scale", "tds.type_info.scale",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_info_collation,
{ "Collation", "tds.type_info.collation",
FT_NONE, BASE_NONE, NULL, 0x0,
"Specifies collation information for character data or metadata describing character data", HFILL }
},
{ &hf_tds_type_info_collation_lcid,
{ "LCID", "tds.type_info.collation.lcid",
FT_UINT32, BASE_HEX, NULL, 0x000FFFFF,
"For a SortId==0 collation, the LCID bits correspond to a LocaleId as defined by the National Language Support (NLS) functions", HFILL }
},
{ &hf_tds_type_info_collation_ign_case,
{ "Ignore case", "tds.type_info.collation.ignore_case",
FT_BOOLEAN, 32, NULL, 0x00100000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_ign_accent,
{ "Ignore accent", "tds.type_info.collation.ignore_accent",
FT_BOOLEAN, 32, NULL, 0x00200000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_ign_kana,
{ "Ignore kana", "tds.type_info.collation.ignore_kana",
FT_BOOLEAN, 32, NULL, 0x00400000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_ign_width,
{ "Ignore width", "tds.type_info.collation.ignore_width",
FT_BOOLEAN, 32, NULL, 0x00800000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_binary,
{ "Binary", "tds.type_info.collation.binary",
FT_BOOLEAN, 32, NULL, 0x01000000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_version,
{ "Version", "tds.type_info.collation.version",
FT_UINT32, BASE_DEC, NULL, 0xF0000000,
NULL, HFILL }
},
{ &hf_tds_type_info_collation_sortid,
{ "SortId", "tds.type_info.collation.sortid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_length,
{ "Length", "tds.type_varbyte.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_null,
{ "Data: NULL", "tds.type_varbyte.data.null",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_boolean,
{ "Data", "tds.type_varbyte.data.bool",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_int1,
{ "Data", "tds.type_varbyte.data.int",
FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_int2,
{ "Data", "tds.type_varbyte.data.int",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_int4,
{ "Data", "tds.type_varbyte.data.int",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_int8,
{ "Data", "tds.type_varbyte.data.int64",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_float,
{ "Data", "tds.type_varbyte.data.float",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_double,
{ "Data", "tds.type_varbyte.data.float",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_bytes,
{ "Data", "tds.type_varbyte.data.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_guid,
{ "Data", "tds.type_varbyte.data.guid",
FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_data_string,
{ "Data", "tds.type_varbyte.data.string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_plp_len,
{ "PLP length", "tds.type_varbyte.plp_len",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_type_varbyte_plp_chunk_len,
{ "PLP chunk length", "tds.type_varbyte.plp_chunk_len",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc,
{ "Remote Procedure Call", "tds.rpc",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_name_length8,
{ "Procedure name length", "tds.rpc.name_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_name_length,
{ "Procedure name length", "tds.rpc.name_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_name,
{ "Procedure name", "tds.rpc.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_proc_id,
{ "Stored procedure ID", "tds.rpc.proc_id",
FT_UINT16, BASE_DEC, VALS(internal_stored_proc_id_names), 0x0,
"The number identifying the special stored procedure to be executed", HFILL }
},
{ &hf_tds_rpc_options,
{ "Option flags", "tds.rpc.options",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The number identifying the special stored procedure to be executed", HFILL }
},
{ &hf_tds_rpc_options_with_recomp,
{ "With recompile", "tds.rpc.options.with_recomp",
FT_BOOLEAN, 16, NULL, TDS_RPC_OPT_WITH_RECOMP,
"The number identifying the special stored procedure to be executed", HFILL }
},
{ &hf_tds_rpc_options_no_metadata,
{ "No metadata", "tds.rpc.options.no_metadata",
FT_BOOLEAN, 16, NULL, TDS_RPC_OPT_NO_METADATA,
"The number identifying the special stored procedure to be executed", HFILL }
},
{ &hf_tds_rpc_options_reuse_metadata,
{ "Reuse metadata", "tds.rpc.options.reuse_metadata",
FT_BOOLEAN, 16, NULL, TDS_RPC_OPT_REUSE_METADATA,
"The number identifying the special stored procedure to be executed", HFILL }
},
{ &hf_tds_rpc_separator,
{ "RPC batch separator", "tds.rpc.separator",
FT_UINT8, BASE_DEC, VALS(tds_rpc_separators), 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter,
{ "Parameter", "tds.rpc.parameter",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter_name_length,
{ "Name length", "tds.rpc.parameter.name_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter_name,
{ "Name", "tds.rpc.parameter.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter_status,
{ "Status flags", "tds.rpc.parameter.status",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Information on how the parameter is passed", HFILL }
},
{ &hf_tds_rpc_parameter_status_by_ref,
{ "By reference", "tds.rpc.parameter.status.by_ref",
FT_BOOLEAN, 16, NULL, TDS_RPC_PARAMETER_STATUS_BY_REF,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter_status_default,
{ "Default value", "tds.rpc.parameter.status.default",
FT_BOOLEAN, 16, NULL, TDS_RPC_PARAMETER_STATUS_DEFAULT,
NULL, HFILL }
},
{ &hf_tds_rpc_parameter_value,
{ "Value", "tds.rpc.parameter.value",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_tds,
&ett_tds_status,
&ett_tds_fragments,
&ett_tds_fragment,
&ett_tds_all_headers,
&ett_tds_all_headers_header,
&ett_tds_type_info,
&ett_tds_type_info_collation,
&ett_tds_type_varbyte,
&ett_tds_message,
&ett_tds_rpc_options,
&ett_tds_rpc_parameter,
&ett_tds_rpc_parameter_status,
&ett_tds_token,
&ett_tds7_query,
&ett_tds7_login,
&ett_tds7_hdr,
};
static ei_register_info ei[] = {
{ &ei_tds_all_headers_header_type, { "tds.all_headers.header.type.invalid", PI_PROTOCOL, PI_WARN, "Invalid header type", EXPFILL }},
{ &ei_tds_type_info_type, { "tds.type_info.type.invalid", PI_PROTOCOL, PI_WARN, "Invalid data type", EXPFILL }},
{ &ei_tds_type_info_type_undecoded, { "tds.type_info.type.undecoded", PI_UNDECODED, PI_ERROR, "Data type not supported yet", EXPFILL }},
{ &ei_tds_invalid_length, { "tds.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_tds_token_length_invalid, { "tds.token.length.invalid", PI_PROTOCOL, PI_WARN, "Bogus token size", EXPFILL }},
};
module_t *tds_module;
expert_module_t* expert_tds;
proto_tds = proto_register_protocol("Tabular Data Stream", "TDS", "tds");
proto_register_field_array(proto_tds, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_tds = expert_register_protocol(proto_tds);
expert_register_field_array(expert_tds, ei, array_length(ei));
tds_tcp_handle = register_dissector("tds", dissect_tds_tcp, proto_tds);
tds_module = prefs_register_protocol(proto_tds, NULL);
prefs_register_bool_preference(tds_module, "desegment_buffers",
"Reassemble TDS buffers spanning multiple TCP segments",
"Whether the TDS dissector should reassemble TDS buffers spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&tds_desegment);
prefs_register_bool_preference(tds_module, "defragment",
"Reassemble fragmented TDS messages with multiple buffers",
"Whether the TDS dissector should defragment messages spanning multiple Netlib buffers",
&tds_defragment);
prefs_register_enum_preference(tds_module, "protocol_type",
"TDS Protocol Type",
"Hint as to version of TDS protocol being decoded",
&tds_protocol_type, tds_protocol_type_options, FALSE);
prefs_register_enum_preference(tds_module, "endian_type",
"TDS decode as",
"Hint as to whether to decode TDS protocol as little-endian or big-endian. (TDS7/8 always decoded as little-endian)",
&tds_little_endian, tds_endian_type_options, FALSE);
prefs_register_range_preference(tds_module, "tcp_ports",
"TDS TCP ports",
"Additional TCP ports to decode as TDS",
&tds_tcp_ports, 0xFFFF);
register_init_routine(tds_init);
}
void
proto_reg_handoff_tds(void)
{
dissector_add_uint("tcp.port", 1433, tds_tcp_handle);
dissector_add_uint("tcp.port", 2433, tds_tcp_handle);
heur_dissector_add("tcp", dissect_tds_tcp_heur, proto_tds);
ntlmssp_handle = find_dissector("ntlmssp");
gssapi_handle = find_dissector("gssapi");
data_handle = find_dissector("data");
}
