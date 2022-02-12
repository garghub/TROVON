static int
add_word_param(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
proto_tree_add_item(tree, hf_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
add_dword_param(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
proto_tree_add_item(tree, hf_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
add_bytes_param(tvbuff_t *tvb, int offset, int count, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
header_field_info *hfinfo;
if (hf_index != -1) {
hfinfo = proto_registrar_get_nth(hf_index);
if ((hfinfo == NULL) ||
((hfinfo->type == FT_INT8 || hfinfo->type == FT_UINT8)
&& (count != 1))) {
THROW(ReportedBoundsError);
}
switch (hfinfo->type) {
case FT_INT8:
case FT_UINT8:
proto_tree_add_item(tree, hf_index, tvb, offset, count,
ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
proto_tree_add_item(tree, hf_index, tvb, offset, count,
ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_index, tvb, offset, count,
ENC_NA);
break;
}
} else {
if (count == 1) {
proto_tree_add_item(tree, hf_smb_pipe_byte_param, tvb, offset, count, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_smb_pipe_bytes_param, tvb, offset, count, ENC_NA);
}
}
offset += count;
return offset;
}
static int
add_string_param_update_parent(tvbuff_t *tvb, int offset, int count, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
proto_item *ti, *parent_ti;
const guint8 *str;
DISSECTOR_ASSERT(hf_index != -1);
ti = proto_tree_add_item_ret_string(tree, hf_index, tvb, offset,
count, ENC_ASCII|ENC_NA, wmem_packet_scope(), &str);
parent_ti = proto_item_get_parent(ti);
proto_item_append_text(parent_ti, ": %s",
format_text(wmem_packet_scope(), str, strlen(str)));
offset += count;
return offset;
}
static int
add_pad_param(tvbuff_t *tvb _U_, int offset, int count, packet_info *pinfo _U_,
proto_tree *tree _U_, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
offset += count;
return offset;
}
static void
add_null_pointer_param(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
if (hf_index != -1) {
proto_tree_add_string_format_value(tree, hf_index, tvb, offset, 0, "", "(Null pointer)");
} else {
proto_tree_add_string_format_value(tree, hf_smb_pipe_string_param, tvb, offset, 0, "", "(Null pointer)");
}
}
static int
add_string_param(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
guint string_len;
string_len = tvb_strsize(tvb, offset);
if (hf_index != -1) {
proto_tree_add_item(tree, hf_index, tvb, offset, string_len,
ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(tree, hf_smb_pipe_string_param, tvb, offset, string_len, ENC_NA|ENC_ASCII);
}
offset += string_len;
return offset;
}
static const char *
get_stringz_pointer_value(tvbuff_t *tvb, int offset, int convert, int *cptrp,
int *lenp)
{
int cptr;
gint string_len;
cptr = (tvb_get_letohl(tvb, offset)&0xffff)-convert;
*cptrp = cptr;
if (tvb_offset_exists(tvb, cptr) &&
(string_len = tvb_strnlen(tvb, cptr, -1)) != -1) {
string_len++;
*lenp = string_len;
return tvb_format_text(tvb, cptr, string_len - 1);
} else
return NULL;
}
static int
add_stringz_pointer_param(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert, int hf_index, smb_info_t *smb_info _U_)
{
int cptr;
const char *string;
gint string_len;
string = get_stringz_pointer_value(tvb, offset, convert, &cptr,
&string_len);
offset += 4;
if (string != NULL) {
if (hf_index != -1) {
proto_tree_add_item(tree, hf_index, tvb, cptr,
string_len, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(tree, hf_smb_pipe_stringz_param, tvb, cptr, string_len, ENC_NA|ENC_ASCII);
}
} else {
if (hf_index != -1) {
proto_tree_add_string(tree, hf_index, tvb, 0, 0,
"<String goes past end of frame>");
} else {
proto_tree_add_string(tree, hf_smb_pipe_stringz_param, tvb, 0, 0,
"<String goes past end of frame>");
}
}
return offset;
}
static int
add_bytes_pointer_param(tvbuff_t *tvb, int offset, int count,
packet_info *pinfo _U_, proto_tree *tree, int convert, int hf_index, smb_info_t *smb_info _U_)
{
int cptr;
cptr = (tvb_get_letohl(tvb, offset)&0xffff)-convert;
offset += 4;
if (tvb_bytes_exist(tvb, cptr, count)) {
if (hf_index != -1) {
proto_tree_add_item(tree, hf_index, tvb, cptr,
count, ENC_NA);
} else {
proto_tree_add_item(tree, hf_smb_pipe_bytes_param, tvb, cptr, count, ENC_NA);
}
} else {
if (hf_index != -1) {
proto_tree_add_bytes_format_value(tree, hf_index, tvb, 0, 0,
NULL, "<Bytes go past end of frame>");
} else {
proto_tree_add_bytes_format_value(tree, hf_smb_pipe_bytes_param, tvb, 0, 0,
NULL, "<Bytes go past end of frame>");
}
}
return offset;
}
static int
add_detail_level(tvbuff_t *tvb, int offset, int count _U_, packet_info *pinfo,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info)
{
smb_transact_info_t *trp = NULL;
guint16 level;
if (smb_info->sip->extra_info_type == SMB_EI_TRI)
trp = (smb_transact_info_t *)smb_info->sip->extra_info;
level = tvb_get_letohs(tvb, offset);
if (!pinfo->fd->flags.visited)
if (trp)
trp->info_level = level;
proto_tree_add_uint(tree, hf_index, tvb, offset, 2, level);
offset += 2;
return offset;
}
static int
add_max_uses(tvbuff_t *tvb, int offset, int count _U_, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
guint16 WParam;
WParam = tvb_get_letohs(tvb, offset);
if (WParam == 0xffff) {
proto_tree_add_uint_format_value(tree, hf_index, tvb,
offset, 2, WParam,
"No limit");
} else {
proto_tree_add_uint(tree, hf_index, tvb,
offset, 2, WParam);
}
offset += 2;
return offset;
}
static int
add_server_type(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo, proto_tree *tree, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
offset = dissect_smb_server_type_flags(
tvb, offset, pinfo, tree, NULL, FALSE);
return offset;
}
static int
add_server_type_info(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo, proto_tree *tree, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
offset = dissect_smb_server_type_flags(
tvb, offset, pinfo, tree, NULL, TRUE);
return offset;
}
static int
add_reltime(tvbuff_t *tvb, int offset, int count _U_, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
nstime_t nstime;
nstime.secs = tvb_get_letohl(tvb, offset);
nstime.nsecs = 0;
proto_tree_add_time_format_value(tree, hf_index, tvb, offset, 4,
&nstime, "%s",
signed_time_secs_to_str(wmem_packet_scope(), (gint32) nstime.secs));
offset += 4;
return offset;
}
static int
add_abstime_common(tvbuff_t *tvb, int offset, proto_tree *tree, int hf_index,
const char *absent_name)
{
nstime_t nstime;
struct tm *tmp;
nstime.secs = tvb_get_letohl(tvb, offset);
nstime.nsecs = 0;
if (nstime.secs == -1 || nstime.secs == 0) {
proto_tree_add_time_format_value(tree, hf_index, tvb, offset, 4,
&nstime, "%s",
absent_name);
} else {
tmp = gmtime(&nstime.secs);
if (tmp == NULL) {
proto_tree_add_time_format_value(tree, hf_index, tvb,
offset, 4, &nstime, "Not representable");
} else {
tmp->tm_isdst = -1;
nstime.secs = mktime(tmp);
proto_tree_add_time(tree, hf_index, tvb, offset, 4,
&nstime);
}
}
offset += 4;
return offset;
}
static int
add_abstime_absent_never(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
return add_abstime_common(tvb, offset, tree, hf_index, "Never");
}
static int
add_abstime_absent_unknown(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
return add_abstime_common(tvb, offset, tree, hf_index, "Unknown");
}
static int
add_nlogons(tvbuff_t *tvb, int offset, int count _U_, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
guint16 nlogons;
nlogons = tvb_get_letohs(tvb, offset);
if (nlogons == 0xffff)
proto_tree_add_uint_format_value(tree, hf_index, tvb, offset, 2,
nlogons, "Unknown");
else
proto_tree_add_uint(tree, hf_index, tvb, offset, 2, nlogons);
offset += 2;
return offset;
}
static int
add_max_storage(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index, smb_info_t *smb_info _U_)
{
guint32 max_storage;
max_storage = tvb_get_letohl(tvb, offset);
if (max_storage == 0xffffffff)
proto_tree_add_uint_format(tree, hf_index, tvb, offset, 4,
max_storage, "No limit");
else
proto_tree_add_uint(tree, hf_index, tvb, offset, 4, max_storage);
offset += 4;
return offset;
}
static int
add_logon_hours(tvbuff_t *tvb, int offset, int count, packet_info *pinfo _U_,
proto_tree *tree, int convert, int hf_index, smb_info_t *smb_info _U_)
{
int cptr;
cptr = (tvb_get_letohl(tvb, offset)&0xffff)-convert;
offset += 4;
if (tvb_bytes_exist(tvb, cptr, count)) {
if (count == 21) {
proto_tree_add_item(tree, hf_index, tvb, cptr, count,
ENC_NA);
} else {
proto_tree_add_bytes_format_value(tree, hf_index, tvb,
cptr, count, NULL,
"%s (wrong length, should be 21, is %d",
tvb_bytes_to_str(wmem_packet_scope(), tvb, cptr, count), count);
}
} else {
proto_tree_add_bytes_format_value(tree, hf_index, tvb, 0, 0,
NULL, "<Bytes go past end of frame>");
}
return offset;
}
static int
add_tzoffset(tvbuff_t *tvb, int offset, int count _U_, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
gint16 tzoffset;
tzoffset = tvb_get_letohs(tvb, offset);
if (tzoffset < 0) {
proto_tree_add_int_format_value(tree, hf_tzoffset, tvb, offset, 2,
tzoffset, "%s east of UTC",
signed_time_secs_to_str(wmem_packet_scope(), -tzoffset*60));
} else if (tzoffset > 0) {
proto_tree_add_int_format_value(tree, hf_tzoffset, tvb, offset, 2,
tzoffset, "%s west of UTC",
signed_time_secs_to_str(wmem_packet_scope(), tzoffset*60));
} else {
proto_tree_add_int_format_value(tree, hf_tzoffset, tvb, offset, 2,
tzoffset, "at UTC");
}
offset += 2;
return offset;
}
static int
add_timeinterval(tvbuff_t *tvb, int offset, int count _U_,
packet_info *pinfo _U_, proto_tree *tree, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
guint16 timeinterval;
timeinterval = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_timeinterval, tvb, offset, 2,
timeinterval, "%f seconds", timeinterval*.0001);
offset += 2;
return offset;
}
static int
add_logon_args(tvbuff_t *tvb, int offset, int count, packet_info *pinfo _U_,
proto_tree *tree, int convert _U_, int hf_index _U_, smb_info_t *smb_info _U_)
{
if (count != 54) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bogus_netwkstauserlogon, tvb, offset, count, "Bogus NetWkstaUserLogon parameters: length is %d, should be 54", count);
offset += count;
return offset;
}
proto_tree_add_item(tree, hf_user_name, tvb, offset, 21, ENC_ASCII|ENC_NA);
offset += 21;
offset += 1;
proto_tree_add_item(tree, hf_password, tvb, offset, 15, ENC_ASCII|ENC_NA);
offset += 15;
offset += 1;
proto_tree_add_item(tree, hf_workstation_name, tvb, offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
return offset;
}
static proto_item *
netshareenum_share_entry(tvbuff_t *tvb, proto_tree *tree, int offset)
{
return proto_tree_add_item(tree, hf_share, tvb, offset, -1, ENC_NA);
}
static proto_item *
netserverenum2_server_entry(tvbuff_t *tvb, proto_tree *tree, int offset)
{
return proto_tree_add_item(tree, hf_server, tvb, offset, -1, ENC_NA);
}
static const struct lanman_desc *
find_lanman(int lanman_num)
{
int i;
for (i = 0; lmd[i].lanman_num != -1; i++) {
if (lmd[i].lanman_num == lanman_num)
break;
}
return &lmd[i];
}
static const guchar *
get_count(const guchar *desc, int *countp)
{
int count = 0;
guchar c;
if (!g_ascii_isdigit(*desc)) {
*countp = 1;
return desc;
}
while ((c = *desc) != '\0' && g_ascii_isdigit(c)) {
count = (count * 10) + c - '0';
desc++;
}
*countp = count;
return desc;
}
static int
dissect_request_parameters(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, const guchar *desc, const item_t *items,
gboolean *has_data_p, smb_info_t *smb_info)
{
guint c;
guint16 WParam;
guint32 LParam;
guint string_len;
int count;
*has_data_p = FALSE;
while ((c = *desc++) != '\0') {
switch (c) {
case 'W':
if (items->func == NULL) {
offset = add_word_param(tvb, offset, 0, pinfo,
tree, 0, hf_smb_pipe_word_param, smb_info);
} else if (items->type != PARAM_WORD) {
WParam = tvb_get_letohs(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%04X), type is wrong (W)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_word_param : *items->hf_index),
WParam, WParam);
offset += 2;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'D':
if (items->func == NULL) {
offset = add_dword_param(tvb, offset, 0, pinfo,
tree, 0, hf_smb_pipe_doubleword_param, smb_info);
} else if (items->type != PARAM_DWORD) {
LParam = tvb_get_letohl(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%08X), type is wrong (D)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_doubleword_param : *items->hf_index),
LParam, LParam);
offset += 4;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'b':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_bytes_param(tvb, offset, count,
pinfo, tree, 0, -1, smb_info);
} else if (items->type != PARAM_BYTES) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, count,
"%s: Value is %s, type is wrong (b)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_bytes_param : *items->hf_index),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, count));
offset += count;
items++;
} else {
offset = (*items->func)(tvb, offset, count,
pinfo, tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'O':
if (items->func == NULL) {
add_null_pointer_param(tvb, offset, 0,
pinfo, tree, 0, -1, smb_info);
} else {
if (*items->hf_index != -1) {
add_null_pointer_param(tvb,
offset, 0, pinfo, tree, 0,
*items->hf_index, smb_info);
}
items++;
}
break;
case 'z':
if (items->func == NULL) {
offset = add_string_param(tvb, offset, 0,
pinfo, tree, 0, -1, smb_info);
} else if (items->type != PARAM_STRINGZ) {
string_len = tvb_strsize(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, string_len,
"%s: Value is %s, type is wrong (z)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_string_param : *items->hf_index),
tvb_format_text(tvb, offset, string_len));
offset += string_len;
items++;
} else {
offset = (*items->func)(tvb, offset, 0,
pinfo, tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'F':
desc = get_count(desc, &count);
proto_tree_add_item(tree, hf_padding, tvb, offset, count, ENC_NA);
offset += count;
break;
case 'L':
proto_tree_add_item(tree, hf_recv_buf_len, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case 's':
*has_data_p = TRUE;
break;
case 'T':
proto_tree_add_item(tree, hf_send_buf_len, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
default:
break;
}
}
return offset;
}
static int
dissect_response_parameters(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, const guchar *desc, const item_t *items,
gboolean *has_data_p, gboolean *has_ent_count_p, guint16 *ent_count_p, smb_info_t *smb_info)
{
guint c;
guint16 WParam;
guint32 LParam;
int count;
*has_data_p = FALSE;
*has_ent_count_p = FALSE;
while ((c = *desc++) != '\0') {
switch (c) {
case 'r':
*has_data_p = TRUE;
break;
case 'g':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_bytes_param(tvb, offset, count,
pinfo, tree, 0, -1, smb_info);
} else if (items->type != PARAM_BYTES) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, count,
"%s: Value is %s, type is wrong (g)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_bytes_param : *items->hf_index),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, count));
offset += count;
items++;
} else {
offset = (*items->func)(tvb, offset, count,
pinfo, tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'h':
if (items->func == NULL) {
offset = add_word_param(tvb, offset, 0, pinfo,
tree, 0, hf_smb_pipe_word_param, smb_info);
} else if (items->type != PARAM_WORD) {
WParam = tvb_get_letohs(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%04X), type is wrong (W)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_word_param : *items->hf_index),
WParam, WParam);
offset += 2;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'i':
if (items->func == NULL) {
offset = add_dword_param(tvb, offset, 0, pinfo,
tree, 0, hf_smb_pipe_doubleword_param, smb_info);
} else if (items->type != PARAM_DWORD) {
LParam = tvb_get_letohl(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%08X), type is wrong (i)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_doubleword_param : *items->hf_index),
LParam, LParam);
offset += 4;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, 0, *items->hf_index, smb_info);
items++;
}
break;
case 'e':
WParam = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_ecount, tvb, offset, 2,
WParam);
offset += 2;
*has_ent_count_p = TRUE;
*ent_count_p = WParam;
break;
default:
break;
}
}
return offset;
}
static int
dissect_transact_data(tvbuff_t *tvb, int offset, int convert,
packet_info *pinfo, proto_tree *tree, const guchar *desc,
const item_t *items, guint16 *aux_count_p, smb_info_t *smb_info)
{
guint c;
guint16 WParam;
guint32 LParam;
int count;
int cptr;
const char *string;
gint string_len = 0;
if (aux_count_p != NULL)
*aux_count_p = 0;
while ((c = *desc++) != '\0') {
switch (c) {
case 'W':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_word_param(tvb, offset, 0, pinfo,
tree, convert, hf_smb_pipe_word_param, smb_info);
} else if (items->type != PARAM_WORD) {
WParam = tvb_get_letohs(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%04X), type is wrong (W)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_word_param : *items->hf_index),
WParam, WParam);
offset += 2;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, convert, *items->hf_index, smb_info);
items++;
}
break;
case 'D':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_dword_param(tvb, offset, 0, pinfo,
tree, convert, hf_smb_pipe_doubleword_param, smb_info);
} else if (items->type != PARAM_DWORD) {
LParam = tvb_get_letohl(tvb, offset);
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, 2,
"%s: Value is %u (0x%08X), type is wrong (D)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_doubleword_param : *items->hf_index),
LParam, LParam);
offset += 4;
items++;
} else {
offset = (*items->func)(tvb, offset, 0, pinfo,
tree, convert, *items->hf_index, smb_info);
items++;
}
break;
case 'B':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_bytes_param(tvb, offset, count,
pinfo, tree, convert, -1, smb_info);
} else if (items->type != PARAM_BYTES) {
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, count,
"%s: Value is %s, type is wrong (B)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_bytes_param : *items->hf_index),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, count));
offset += count;
items++;
} else {
offset = (*items->func)(tvb, offset, count,
pinfo, tree, convert, *items->hf_index, smb_info);
items++;
}
break;
case 'O':
if (items->func == NULL) {
add_null_pointer_param(tvb, offset, 0,
pinfo, tree, convert, -1, smb_info);
} else {
if (*items->hf_index != -1) {
add_null_pointer_param(tvb,
offset, 0, pinfo, tree, convert,
*items->hf_index, smb_info);
}
items++;
}
break;
case 'z':
if (items->func == NULL) {
offset = add_stringz_pointer_param(tvb, offset,
0, pinfo, tree, convert, -1, smb_info);
} else if (items->type != PARAM_STRINGZ) {
string = get_stringz_pointer_value(tvb, offset,
convert, &cptr, &string_len);
offset += 4;
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, cptr, string_len,
"%s: Value is %s, type is wrong (z)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_string_param : *items->hf_index),
string ? string : "(null)");
items++;
} else {
offset = (*items->func)(tvb, offset, 0,
pinfo, tree, convert, *items->hf_index, smb_info);
items++;
}
break;
case 'b':
desc = get_count(desc, &count);
if (items->func == NULL) {
offset = add_bytes_pointer_param(tvb, offset,
count, pinfo, tree, convert, -1, smb_info);
} else if (items->type != PARAM_BYTES) {
cptr = (tvb_get_letohl(tvb, offset)&0xffff)-convert;
offset += 4;
proto_tree_add_expert_format(tree, pinfo, &ei_smb_pipe_bad_type, tvb, offset, count,
"%s: Value is %s, type is wrong (b)",
proto_registrar_get_name((*items->hf_index == -1) ?
hf_smb_pipe_bytes_param : *items->hf_index),
tvb_bytes_to_str(wmem_packet_scope(), tvb, cptr, count));
items++;
} else {
offset = (*items->func)(tvb, offset, count,
pinfo, tree, convert, *items->hf_index, smb_info);
items++;
}
break;
case 'N':
WParam = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_aux_data_struct_count, tvb, offset, 2, WParam);
offset += 2;
if (aux_count_p != NULL)
*aux_count_p = WParam;
break;
default:
break;
}
}
return offset;
}
static void
dissect_response_data(tvbuff_t *tvb, packet_info *pinfo, int convert,
proto_tree *tree, smb_info_t *smb_info,
const struct lanman_desc *lanman, gboolean has_ent_count,
guint16 ent_count)
{
smb_transact_info_t *trp;
const item_list_t *resp_data_list;
int offset, start_offset;
const char *label;
gint ett;
const item_t *resp_data;
proto_item *data_item = NULL;
proto_tree *data_tree = NULL;
proto_item *entry_item;
proto_tree *entry_tree;
guint i, j;
guint16 aux_count;
trp = (smb_transact_info_t *)smb_info->sip->extra_info;
for (resp_data_list = lanman->resp_data_list;
resp_data_list->level != -1; resp_data_list++) {
if (resp_data_list->level == trp->info_level)
break;
}
resp_data = resp_data_list->item_list;
offset = 0;
if (has_ent_count) {
if (tree) {
label = lanman->resp_data_entry_list_label;
if (label == NULL)
label = "Entries";
if (lanman->ett_data_entry_list != NULL)
ett = *lanman->ett_data_entry_list;
else
ett = ett_lanman_unknown_entries;
data_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett, &data_item, label);
}
}
if (trp->data_descrip == NULL) {
if (has_ent_count) {
if (data_item != NULL) {
proto_item_append_text(data_item,
" (No descriptor available)");
}
} else {
proto_tree_add_item(data_tree, hf_data_no_descriptor, tvb, offset, -1, ENC_NA);
}
offset += tvb_captured_length_remaining(tvb, offset);
} else {
if (!has_ent_count)
ent_count = 1;
for (i = 0; i < ent_count; i++) {
start_offset = offset;
if (has_ent_count &&
lanman->resp_data_element_item != NULL) {
entry_item =
(*lanman->resp_data_element_item)
(tvb, data_tree, offset);
entry_tree = proto_item_add_subtree(
entry_item,
*lanman->ett_resp_data_element_item);
} else {
entry_item = NULL;
entry_tree = data_tree;
}
offset = dissect_transact_data(tvb, offset,
convert, pinfo, entry_tree,
trp->data_descrip, resp_data, &aux_count, smb_info);
if (trp->aux_data_descrip != NULL) {
for (j = 0; j < aux_count; j++) {
offset = dissect_transact_data(
tvb, offset, convert,
pinfo, entry_tree,
trp->data_descrip,
lanman->resp_aux_data, NULL, smb_info);
}
}
if (entry_item != NULL) {
proto_item_set_len(entry_item,
offset - start_offset);
}
}
}
if (data_item != NULL) {
proto_item_set_len(data_item, offset);
}
}
static gboolean
dissect_pipe_lanman(tvbuff_t *pd_tvb, tvbuff_t *p_tvb, tvbuff_t *d_tvb,
packet_info *pinfo, proto_tree *parent_tree, smb_info_t *smb_info)
{
smb_transact_info_t *trp = NULL;
int offset = 0;
guint16 cmd;
guint16 status;
int convert;
const struct lanman_desc *lanman;
proto_item *item = NULL;
proto_tree *tree = NULL;
guint descriptor_len;
const gchar *param_descrip, *data_descrip, *aux_data_descrip = NULL;
gboolean has_data;
gboolean has_ent_count;
guint16 ent_count = 0, aux_count;
guint i;
proto_item *data_item;
proto_tree *data_tree;
if (smb_info->sip->extra_info_type == SMB_EI_TRI)
trp = (smb_transact_info_t *)smb_info->sip->extra_info;
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_smb_lanman)))
return FALSE;
if (p_tvb == NULL) {
return FALSE;
}
pinfo->current_proto = "LANMAN";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LANMAN");
if (parent_tree) {
item = proto_tree_add_item(parent_tree, proto_smb_lanman,
pd_tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_lanman);
}
if (smb_info->request) {
cmd = tvb_get_letohs(p_tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Request", val_to_str_ext(cmd, &commands_ext, "Unknown Command (%u)"));
proto_tree_add_uint(tree, hf_function_code, p_tvb, offset, 2,
cmd);
offset += 2;
if(!trp){
return FALSE;
}
if (!pinfo->fd->flags.visited) {
trp->lanman_cmd = cmd;
trp->info_level = -1;
trp->param_descrip=NULL;
trp->data_descrip=NULL;
trp->aux_data_descrip=NULL;
}
param_descrip = tvb_get_const_stringz(p_tvb, offset, &descriptor_len);
proto_tree_add_item(tree, hf_param_desc, p_tvb, offset,
descriptor_len, ENC_ASCII|ENC_NA);
if (!pinfo->fd->flags.visited) {
DISSECTOR_ASSERT(trp->param_descrip == NULL);
trp->param_descrip = wmem_strdup(wmem_file_scope(), param_descrip);
}
offset += descriptor_len;
data_descrip = tvb_get_const_stringz(p_tvb, offset, &descriptor_len);
proto_tree_add_item(tree, hf_return_desc, p_tvb, offset,
descriptor_len, ENC_ASCII|ENC_NA);
if (!pinfo->fd->flags.visited) {
DISSECTOR_ASSERT(trp->data_descrip == NULL);
trp->data_descrip = wmem_strdup(wmem_file_scope(), data_descrip);
}
offset += descriptor_len;
lanman = find_lanman(cmd);
offset = dissect_request_parameters(p_tvb, offset, pinfo, tree,
param_descrip, lanman->req, &has_data, smb_info);
if (tvb_reported_length_remaining(p_tvb, offset) > 0){
aux_data_descrip = tvb_get_const_stringz(p_tvb, offset, &descriptor_len);
proto_tree_add_item(tree, hf_aux_data_desc, p_tvb, offset,
descriptor_len, ENC_ASCII|ENC_NA);
if (!pinfo->fd->flags.visited) {
DISSECTOR_ASSERT(trp->aux_data_descrip == NULL);
trp->aux_data_descrip =
wmem_strdup(wmem_file_scope(), aux_data_descrip);
}
}
offset = 0;
if (has_data && d_tvb && tvb_reported_length(d_tvb) != 0) {
if (lanman->req_data_item != NULL) {
data_item = (*lanman->req_data_item)(d_tvb,
pinfo, tree, offset);
data_tree = proto_item_add_subtree(data_item,
*lanman->ett_req_data);
} else {
data_item = NULL;
data_tree = tree;
}
offset = dissect_transact_data(d_tvb, offset, -1,
pinfo, data_tree, data_descrip, lanman->req_data,
&aux_count, smb_info);
if (aux_data_descrip != NULL) {
for (i = 0; i < aux_count; i++) {
offset = dissect_transact_data(d_tvb,
offset, -1, pinfo, data_tree,
aux_data_descrip,
lanman->req_aux_data, NULL, smb_info);
}
}
if (data_item != NULL) {
proto_item_set_len(data_item, offset);
}
}
} else {
if (trp == NULL)
return FALSE;
if( ( (p_tvb==NULL) || (tvb_reported_length(p_tvb)==0) )
&& ( (d_tvb==NULL) || (tvb_reported_length(d_tvb)==0) ) ){
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Interim Response",
val_to_str_ext(trp->lanman_cmd, &commands_ext, "Unknown Command (%u)"));
proto_tree_add_uint(tree, hf_function_code, p_tvb, 0, 0, trp->lanman_cmd);
return TRUE;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s Response",
val_to_str_ext(trp->lanman_cmd, &commands_ext, "Unknown Command (%u)"));
proto_tree_add_uint(tree, hf_function_code, p_tvb, 0, 0,
trp->lanman_cmd);
lanman = find_lanman(trp->lanman_cmd);
status = tvb_get_letohs(p_tvb, offset);
proto_tree_add_uint(tree, hf_status, p_tvb, offset, 2, status);
offset += 2;
convert = tvb_get_letohs(p_tvb, offset);
proto_tree_add_uint(tree, hf_convert, p_tvb, offset, 2, convert);
offset += 2;
if (trp->param_descrip == NULL) {
proto_tree_add_item(tree, hf_param_no_descriptor, p_tvb, offset, -1, ENC_NA);
if (d_tvb && tvb_reported_length(d_tvb) > 0) {
proto_tree_add_item(tree, hf_data_no_descriptor, d_tvb, 0, -1, ENC_NA);
}
} else {
dissect_response_parameters(p_tvb, offset,
pinfo, tree, trp->param_descrip, lanman->resp,
&has_data, &has_ent_count, &ent_count, smb_info);
if (d_tvb && tvb_reported_length(d_tvb) > 0) {
if (has_data) {
dissect_response_data(d_tvb, pinfo,
convert, tree, smb_info, lanman,
has_ent_count, ent_count);
} else {
proto_tree_add_item(tree, hf_data_no_recv_buffer, d_tvb, 0, -1, ENC_NA);
}
}
}
}
return TRUE;
}
void
proto_register_pipe_lanman(void)
{
static hf_register_info hf[] = {
{ &hf_function_code,
{ "Function Code", "lanman.function_code", FT_UINT16, BASE_DEC|BASE_EXT_STRING,
&commands_ext, 0, "LANMAN Function Code/Command", HFILL }},
{ &hf_param_desc,
{ "Parameter Descriptor", "lanman.param_desc", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Parameter Descriptor", HFILL }},
{ &hf_return_desc,
{ "Return Descriptor", "lanman.ret_desc", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Return Descriptor", HFILL }},
{ &hf_aux_data_desc,
{ "Auxiliary Data Descriptor", "lanman.aux_data_desc", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Auxiliary Data Descriptor", HFILL }},
{ &hf_detail_level,
{ "Detail Level", "lanman.level", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Detail Level", HFILL }},
{ &hf_padding,
{ "Padding", "lanman.padding", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_recv_buf_len,
{ "Receive Buffer Length", "lanman.recv_buf_len", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Receive Buffer Length", HFILL }},
{ &hf_send_buf_len,
{ "Send Buffer Length", "lanman.send_buf_len", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Send Buffer Length", HFILL }},
#if 0
{ &hf_continuation_from,
{ "Continuation from message in frame", "lanman.continuation_from", FT_UINT32, BASE_DEC,
NULL, 0, "This is a LANMAN continuation from the message in the frame in question", HFILL }},
#endif
{ &hf_status,
{ "Status", "lanman.status", FT_UINT16, BASE_DEC,
VALS(status_vals), 0, "LANMAN Return status", HFILL }},
{ &hf_convert,
{ "Convert", "lanman.convert", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Convert", HFILL }},
{ &hf_param_no_descriptor,
{ "Parameters (no descriptor available)", "lanman.param_no_descriptor", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_data_no_descriptor,
{ "Data (no descriptor available)", "lanman.data_no_descriptor", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_data_no_recv_buffer,
{ "Data (no receive buffer)", "lanman.data_no_recv_buffer", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ecount,
{ "Entry Count", "lanman.entry_count", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Number of Entries", HFILL }},
{ &hf_acount,
{ "Available Entries", "lanman.available_count", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Number of Available Entries", HFILL }},
{ &hf_share,
{ "Share", "lanman.share", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_share_name,
{ "Share Name", "lanman.share.name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Name of Share", HFILL }},
{ &hf_share_type,
{ "Share Type", "lanman.share.type", FT_UINT16, BASE_DEC,
VALS(share_type_vals), 0, "LANMAN Type of Share", HFILL }},
{ &hf_share_comment,
{ "Share Comment", "lanman.share.comment", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Share Comment", HFILL }},
{ &hf_share_permissions,
{ "Share Permissions", "lanman.share.permissions", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Permissions on share", HFILL }},
{ &hf_share_max_uses,
{ "Share Max Uses", "lanman.share.max_uses", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Max connections allowed to share", HFILL }},
{ &hf_share_current_uses,
{ "Share Current Uses", "lanman.share.current_uses", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Current connections to share", HFILL }},
{ &hf_share_path,
{ "Share Path", "lanman.share.path", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Share Path", HFILL }},
{ &hf_share_password,
{ "Share Password", "lanman.share.password", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Share Password", HFILL }},
{ &hf_server,
{ "Server", "lanman.server", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_server_name,
{ "Server Name", "lanman.server.name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Name of Server", HFILL }},
{ &hf_server_major,
{ "Major Version", "lanman.server.major", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Server Major Version", HFILL }},
{ &hf_server_minor,
{ "Minor Version", "lanman.server.minor", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Server Minor Version", HFILL }},
{ &hf_server_comment,
{ "Server Comment", "lanman.server.comment", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Server Comment", HFILL }},
{ &hf_abytes,
{ "Available Bytes", "lanman.available_bytes", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Number of Available Bytes", HFILL }},
{ &hf_current_time,
{ "Current Date/Time", "lanman.current_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Current date and time, in seconds since 00:00:00, January 1, 1970", HFILL }},
{ &hf_msecs,
{ "Milliseconds", "lanman.msecs", FT_UINT32, BASE_DEC,
NULL, 0, "LANMAN Milliseconds since arbitrary time in the past (typically boot time)", HFILL }},
{ &hf_hour,
{ "Hour", "lanman.hour", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current hour", HFILL }},
{ &hf_minute,
{ "Minute", "lanman.minute", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current minute", HFILL }},
{ &hf_second,
{ "Second", "lanman.second", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current second", HFILL }},
{ &hf_hundredths,
{ "Hundredths of a second", "lanman.hundredths", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current hundredths of a second", HFILL }},
{ &hf_tzoffset,
{ "Time Zone Offset", "lanman.tzoffset", FT_INT16, BASE_DEC,
NULL, 0, "LANMAN Offset of time zone from GMT, in minutes", HFILL }},
{ &hf_timeinterval,
{ "Time Interval", "lanman.timeinterval", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN .0001 second units per clock tick", HFILL }},
{ &hf_day,
{ "Day", "lanman.day", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current day", HFILL }},
{ &hf_month,
{ "Month", "lanman.month", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Current month", HFILL }},
{ &hf_year,
{ "Year", "lanman.year", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Current year", HFILL }},
{ &hf_weekday,
{ "Weekday", "lanman.weekday", FT_UINT8, BASE_DEC,
VALS(weekday_vals), 0, "LANMAN Current day of the week", HFILL }},
{ &hf_enumeration_domain,
{ "Enumeration Domain", "lanman.enumeration_domain", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Domain in which to enumerate servers", HFILL }},
{ &hf_last_entry,
{ "Last Entry", "lanman.last_entry", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN last reported entry of the enumerated servers", HFILL }},
{ &hf_computer_name,
{ "Computer Name", "lanman.computer_name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Computer Name", HFILL }},
{ &hf_user_name,
{ "User Name", "lanman.user_name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN User Name", HFILL }},
{ &hf_group_name,
{ "Group Name", "lanman.group_name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Group Name", HFILL }},
{ &hf_workstation_domain,
{ "Workstation Domain", "lanman.workstation_domain", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Workstation Domain", HFILL }},
{ &hf_workstation_major,
{ "Workstation Major Version", "lanman.workstation_major", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Workstation Major Version", HFILL }},
{ &hf_workstation_minor,
{ "Workstation Minor Version", "lanman.workstation_minor", FT_UINT8, BASE_DEC,
NULL, 0, "LANMAN Workstation Minor Version", HFILL }},
{ &hf_logon_domain,
{ "Logon Domain", "lanman.logon_domain", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Logon Domain", HFILL }},
{ &hf_other_domains,
{ "Other Domains", "lanman.other_domains", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Other Domains", HFILL }},
{ &hf_password,
{ "Password", "lanman.password", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Password", HFILL }},
{ &hf_workstation_name,
{ "Workstation Name", "lanman.workstation_name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Workstation Name", HFILL }},
{ &hf_ustruct_size,
{ "Length of UStruct", "lanman.ustruct_size", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN UStruct Length", HFILL }},
{ &hf_logon_code,
{ "Logon Code", "lanman.logon_code", FT_UINT16, BASE_DEC,
VALS(status_vals), 0, "LANMAN Logon Code", HFILL }},
{ &hf_privilege_level,
{ "Privilege Level", "lanman.privilege_level", FT_UINT16, BASE_DEC,
VALS(privilege_vals), 0, "LANMAN Privilege Level", HFILL }},
{ &hf_operator_privileges,
{ "Operator Privileges", "lanman.operator_privileges", FT_UINT32, BASE_DEC,
VALS(op_privilege_vals), 0, "LANMAN Operator Privileges", HFILL }},
{ &hf_num_logons,
{ "Number of Logons", "lanman.num_logons", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Number of Logons", HFILL }},
{ &hf_bad_pw_count,
{ "Bad Password Count", "lanman.bad_pw_count", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Number of incorrect passwords entered since last successful login", HFILL }},
{ &hf_last_logon,
{ "Last Logon Date/Time", "lanman.last_logon", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time of last logon", HFILL }},
{ &hf_last_logoff,
{ "Last Logoff Date/Time", "lanman.last_logoff", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time of last logoff", HFILL }},
{ &hf_logoff_time,
{ "Logoff Date/Time", "lanman.logoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time when user should log off", HFILL }},
{ &hf_kickoff_time,
{ "Kickoff Date/Time", "lanman.kickoff_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time when user will be logged off", HFILL }},
{ &hf_password_age,
{ "Password Age", "lanman.password_age", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "LANMAN Time since user last changed his/her password", HFILL }},
{ &hf_password_can_change,
{ "Password Can Change", "lanman.password_can_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time when user can change their password", HFILL }},
{ &hf_password_must_change,
{ "Password Must Change", "lanman.password_must_change", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "LANMAN Date and time when user must change their password", HFILL }},
{ &hf_script_path,
{ "Script Path", "lanman.script_path", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Pathname of user's logon script", HFILL }},
{ &hf_logoff_code,
{ "Logoff Code", "lanman.logoff_code", FT_UINT16, BASE_DEC,
VALS(status_vals), 0, "LANMAN Logoff Code", HFILL }},
{ &hf_duration,
{ "Duration of Session", "lanman.duration", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "LANMAN Number of seconds the user was logged on", HFILL }},
{ &hf_comment,
{ "Comment", "lanman.comment", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Comment", HFILL }},
{ &hf_user_comment,
{ "User Comment", "lanman.user_comment", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN User Comment", HFILL }},
{ &hf_full_name,
{ "Full Name", "lanman.full_name", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Full Name", HFILL }},
{ &hf_homedir,
{ "Home Directory", "lanman.homedir", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Home Directory", HFILL }},
{ &hf_parameters,
{ "Parameters", "lanman.parameters", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Parameters", HFILL }},
{ &hf_logon_server,
{ "Logon Server", "lanman.logon_server", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Logon Server", HFILL }},
{ &hf_country_code,
{ "Country Code", "lanman.country_code", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&ms_country_codes_ext, 0, "LANMAN Country Code", HFILL }},
{ &hf_workstations,
{ "Workstations", "lanman.workstations", FT_STRING, BASE_NONE,
NULL, 0, "LANMAN Workstations", HFILL }},
{ &hf_max_storage,
{ "Max Storage", "lanman.max_storage", FT_UINT32, BASE_DEC,
NULL, 0, "LANMAN Max Storage", HFILL }},
{ &hf_units_per_week,
{ "Units Per Week", "lanman.units_per_week", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Units Per Week", HFILL }},
{ &hf_logon_hours,
{ "Logon Hours", "lanman.logon_hours", FT_BYTES, BASE_NONE,
NULL, 0, "LANMAN Logon Hours", HFILL }},
{ &hf_code_page,
{ "Code Page", "lanman.code_page", FT_UINT16, BASE_DEC,
NULL, 0, "LANMAN Code Page", HFILL }},
{ &hf_new_password,
{ "New Password", "lanman.new_password", FT_BYTES, BASE_NONE,
NULL, 0, "LANMAN New Password (encrypted)", HFILL }},
{ &hf_old_password,
{ "Old Password", "lanman.old_password", FT_BYTES, BASE_NONE,
NULL, 0, "LANMAN Old Password (encrypted)", HFILL }},
{ &hf_reserved,
{ "Reserved", "lanman.reserved", FT_UINT32, BASE_HEX,
NULL, 0, "LANMAN Reserved", HFILL }},
{ &hf_aux_data_struct_count,
{ "Auxiliary data structure count", "lanman.aux_data_struct_count", FT_UINT16, BASE_DEC_HEX,
NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_lanman,
&ett_lanman_unknown_entries,
&ett_lanman_unknown_entry,
&ett_lanman_servers,
&ett_lanman_server,
&ett_lanman_groups,
&ett_lanman_shares,
&ett_lanman_share,
};
proto_smb_lanman = proto_register_protocol(
"Microsoft Windows Lanman Remote API Protocol", "LANMAN", "lanman");
proto_register_field_array(proto_smb_lanman, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
gboolean
dissect_pipe_dcerpc(tvbuff_t *d_tvb, packet_info *pinfo, proto_tree *parent_tree,
proto_tree *tree, guint32 fid, void *data)
{
gboolean result=0;
gboolean save_fragmented;
guint reported_len;
fragment_head *fd_head;
tvbuff_t *new_tvb;
proto_item *frag_tree_item;
heur_dtbl_entry_t *hdtbl_entry;
dcerpc_set_transport_salt(fid, pinfo);
pinfo->can_desegment=0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
reported_len = tvb_reported_length(d_tvb);
if(smb_dcerpc_reassembly && tvb_captured_length(d_tvb) >= reported_len){
pinfo->can_desegment=2;
}
save_fragmented = pinfo->fragmented;
if(!pinfo->can_desegment){
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
goto clean_up_and_exit;
}
if(!pinfo->fd->flags.visited){
fd_head=fragment_get(&dcerpc_reassembly_table, pinfo, fid, NULL);
if(!fd_head){
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
if(!result){
goto clean_up_and_exit;
}
if(pinfo->desegment_len){
fragment_add_check(&dcerpc_reassembly_table,
d_tvb, 0, pinfo, fid, NULL,
0, reported_len, TRUE);
fragment_set_tot_len(&dcerpc_reassembly_table,
pinfo, fid, NULL,
pinfo->desegment_len+reported_len);
}
goto clean_up_and_exit;
}
while(fd_head->next){
fd_head=fd_head->next;
}
fd_head=fragment_add_check(&dcerpc_reassembly_table,
d_tvb, 0, pinfo, fid, NULL,
fd_head->offset+fd_head->len,
reported_len, TRUE);
if(fd_head){
new_tvb = tvb_new_chain(d_tvb, fd_head->tvb_data);
add_new_data_source(pinfo, new_tvb,
"DCERPC over SMB");
pinfo->fragmented=FALSE;
d_tvb=new_tvb;
show_fragment_tree(fd_head, &smb_pipe_frag_items,
tree, pinfo, d_tvb, &frag_tree_item);
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
}
goto clean_up_and_exit;
}
fd_head=fragment_add_check(&dcerpc_reassembly_table,
d_tvb, 0, pinfo, fid, NULL, 0, 0, TRUE);
if(!fd_head){
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
goto clean_up_and_exit;
}
if(!(fd_head->flags&FD_DEFRAGMENTED)){
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
goto clean_up_and_exit;
}
if(pinfo->num!=fd_head->reassembled_in){
proto_tree_add_uint(parent_tree, hf_smb_pipe_reassembled_in, d_tvb, 0, 0, fd_head->reassembled_in);
goto clean_up_and_exit;
}
new_tvb = tvb_new_chain(d_tvb, fd_head->tvb_data);
add_new_data_source(pinfo, new_tvb,
"DCERPC over SMB");
pinfo->fragmented=FALSE;
d_tvb=new_tvb;
show_fragment_tree(fd_head, &smb_pipe_frag_items,
tree, pinfo, d_tvb, &frag_tree_item);
result = dissector_try_heuristic(smb_transact_heur_subdissector_list, d_tvb, pinfo, parent_tree, &hdtbl_entry, data);
clean_up_and_exit:
pinfo->can_desegment=0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
if (!result)
call_data_dissector(d_tvb, pinfo, parent_tree);
pinfo->fragmented = save_fragmented;
return TRUE;
}
gboolean
dissect_pipe_smb(tvbuff_t *sp_tvb, tvbuff_t *s_tvb, tvbuff_t *pd_tvb,
tvbuff_t *p_tvb, tvbuff_t *d_tvb, const char *pipe,
packet_info *pinfo, proto_tree *tree, smb_info_t *smb_info)
{
smb_transact_info_t *tri;
guint sp_len;
proto_item *pipe_item = NULL;
proto_tree *pipe_tree = NULL;
int offset;
int trans_subcmd=0;
int function;
int fid = -1;
guint16 info_level;
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_smb_pipe)))
return FALSE;
pinfo->current_proto = "SMB Pipe";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMB Pipe");
col_set_str(pinfo->cinfo, COL_INFO,
smb_info->request ? "Request" : "Response");
if (smb_info->sip != NULL && smb_info->sip->extra_info_type == SMB_EI_TRI)
tri = (smb_transact_info_t *)smb_info->sip->extra_info;
else
tri = NULL;
if (sp_tvb != NULL)
sp_len = tvb_captured_length(sp_tvb);
else
sp_len = 0;
if (tree) {
pipe_item = proto_tree_add_item(tree, proto_smb_pipe,
sp_tvb, 0, sp_len, ENC_NA);
pipe_tree = proto_item_add_subtree(pipe_item, ett_smb_pipe);
}
offset = 0;
if (s_tvb != NULL && tvb_reported_length(s_tvb) != 0) {
function = tvb_get_letohs(s_tvb, offset);
proto_tree_add_uint(pipe_tree, hf_smb_pipe_function, s_tvb,
offset, 2, function);
offset += 2;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(function, functions, "Unknown function (0x%04x)"),
smb_info->request ? "Request" : "Response");
if (tri != NULL)
tri->function = function;
switch (function) {
case CALL_NAMED_PIPE:
case WAIT_NAMED_PIPE:
proto_tree_add_item(pipe_tree, hf_smb_pipe_priority, s_tvb,
offset, 2, ENC_LITTLE_ENDIAN);
break;
case PEEK_NAMED_PIPE:
case Q_NM_P_HAND_STATE:
case SET_NM_P_HAND_STATE:
case Q_NM_PIPE_INFO:
case TRANSACT_NM_PIPE:
case RAW_READ_NM_PIPE:
case RAW_WRITE_NM_PIPE:
fid = tvb_get_letohs(s_tvb, 2);
dissect_smb_fid(s_tvb, pinfo, pipe_tree, offset, 2, (guint16) fid, FALSE, FALSE, FALSE, smb_info);
if (tri != NULL)
tri->fid = fid;
break;
default:
break;
}
} else {
if (tri != NULL && tri->function != -1) {
function = tri->function;
proto_tree_add_uint(pipe_tree, hf_smb_pipe_function, NULL,
0, 0, function);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(function, functions, "Unknown function (0x%04x)"),
smb_info->request ? "Request" : "Response");
fid = tri->fid;
if (fid != -1)
dissect_smb_fid(d_tvb, pinfo, pipe_tree, 0, 0, (guint16) fid, FALSE, FALSE, TRUE, smb_info);
} else {
function = -1;
fid = -1;
}
}
if(smb_info->request){
if(strncmp(pipe,"LANMAN",6) == 0){
trans_subcmd=PIPE_LANMAN;
} else {
trans_subcmd=PIPE_DCERPC;
}
if (!pinfo->fd->flags.visited) {
if (tri == NULL)
return FALSE;
tri->trans_subcmd = trans_subcmd;
}
} else {
if(tri == NULL)
return FALSE;
trans_subcmd = tri->trans_subcmd;
}
if (tri == NULL) {
return FALSE;
}
switch (function) {
case CALL_NAMED_PIPE:
case TRANSACT_NM_PIPE:
switch(trans_subcmd){
case PIPE_LANMAN:
return dissect_pipe_lanman(pd_tvb, p_tvb, d_tvb, pinfo, tree, smb_info);
case PIPE_DCERPC:
if (fid != -1) {
if (d_tvb == NULL)
return FALSE;
return dissect_pipe_dcerpc(d_tvb, pinfo, tree, pipe_tree, fid, smb_info);
}
break;
}
break;
case -1:
switch(trans_subcmd){
case PIPE_LANMAN:
return dissect_pipe_lanman(pd_tvb, p_tvb, d_tvb, pinfo, tree, smb_info);
}
break;
case WAIT_NAMED_PIPE:
break;
case PEEK_NAMED_PIPE:
if (!smb_info->request) {
if (p_tvb == NULL)
return FALSE;
offset = 0;
proto_tree_add_item(pipe_tree, hf_smb_pipe_peek_available,
p_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pipe_tree, hf_smb_pipe_peek_remaining,
p_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pipe_tree, hf_smb_pipe_peek_status,
p_tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
break;
case Q_NM_P_HAND_STATE:
if (!smb_info->request) {
if (p_tvb == NULL)
return FALSE;
dissect_ipc_state(p_tvb, pipe_tree, 0, FALSE);
}
break;
case SET_NM_P_HAND_STATE:
if (smb_info->request) {
if (p_tvb == NULL)
return FALSE;
dissect_ipc_state(p_tvb, pipe_tree, 0, TRUE);
}
break;
case Q_NM_PIPE_INFO:
offset = 0;
if (smb_info->request) {
if (p_tvb == NULL)
return FALSE;
info_level = tvb_get_letohs(p_tvb, offset);
proto_tree_add_uint(pipe_tree, hf_smb_pipe_getinfo_info_level,
p_tvb, offset, 2, info_level);
if (!pinfo->fd->flags.visited)
tri->info_level = info_level;
} else {
guint8 pipe_namelen;
if (d_tvb == NULL)
return FALSE;
switch (tri->info_level) {
case 1:
proto_tree_add_item(pipe_tree,
hf_smb_pipe_getinfo_output_buffer_size,
d_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pipe_tree,
hf_smb_pipe_getinfo_input_buffer_size,
d_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(pipe_tree,
hf_smb_pipe_getinfo_maximum_instances,
d_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(pipe_tree,
hf_smb_pipe_getinfo_current_instances,
d_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
pipe_namelen = tvb_get_guint8(d_tvb, offset);
proto_tree_add_uint(pipe_tree,
hf_smb_pipe_getinfo_pipe_name_length,
d_tvb, offset, 1, pipe_namelen);
offset += 1;
proto_tree_add_item(pipe_tree,
hf_smb_pipe_getinfo_pipe_name,
d_tvb, offset, pipe_namelen, ENC_ASCII|ENC_NA);
break;
}
}
break;
case RAW_READ_NM_PIPE:
if (!smb_info->request) {
if (d_tvb == NULL)
return FALSE;
dissect_file_data(d_tvb, pipe_tree, 0,
(guint16) tvb_reported_length(d_tvb),
(guint16) tvb_reported_length(d_tvb));
}
break;
case RAW_WRITE_NM_PIPE:
offset = 0;
if (smb_info->request) {
if (d_tvb == NULL)
return FALSE;
dissect_file_data(d_tvb, pipe_tree,
offset, (guint16) tvb_reported_length(d_tvb),
(guint16) tvb_reported_length(d_tvb));
} else {
if (p_tvb == NULL)
return FALSE;
proto_tree_add_item(pipe_tree,
hf_smb_pipe_write_raw_bytes_written,
p_tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
break;
}
return TRUE;
}
void
proto_register_smb_pipe(void)
{
static hf_register_info hf[] = {
{ &hf_smb_pipe_function,
{ "Function", "smb_pipe.function", FT_UINT16, BASE_HEX,
VALS(functions), 0, "SMB Pipe Function Code", HFILL }},
{ &hf_smb_pipe_priority,
{ "Priority", "smb_pipe.priority", FT_UINT16, BASE_DEC,
NULL, 0, "SMB Pipe Priority", HFILL }},
{ &hf_smb_pipe_peek_available,
{ "Available Bytes", "smb_pipe.peek.available_bytes", FT_UINT16, BASE_DEC,
NULL, 0, "Total number of bytes available to be read from the pipe", HFILL }},
{ &hf_smb_pipe_peek_remaining,
{ "Bytes Remaining", "smb_pipe.peek.remaining_bytes", FT_UINT16, BASE_DEC,
NULL, 0, "Total number of bytes remaining in the message at the head of the pipe", HFILL }},
{ &hf_smb_pipe_peek_status,
{ "Pipe Status", "smb_pipe.peek.status", FT_UINT16, BASE_DEC,
VALS(pipe_status), 0, NULL, HFILL }},
{ &hf_smb_pipe_getinfo_info_level,
{ "Information Level", "smb_pipe.getinfo.info_level", FT_UINT16, BASE_DEC,
NULL, 0, "Information level of information to return", HFILL }},
{ &hf_smb_pipe_getinfo_output_buffer_size,
{ "Output Buffer Size", "smb_pipe.getinfo.output_buffer_size", FT_UINT16, BASE_DEC,
NULL, 0, "Actual size of buffer for outgoing (server) I/O", HFILL }},
{ &hf_smb_pipe_getinfo_input_buffer_size,
{ "Input Buffer Size", "smb_pipe.getinfo.input_buffer_size", FT_UINT16, BASE_DEC,
NULL, 0, "Actual size of buffer for incoming (client) I/O", HFILL }},
{ &hf_smb_pipe_getinfo_maximum_instances,
{ "Maximum Instances", "smb_pipe.getinfo.maximum_instances", FT_UINT8, BASE_DEC,
NULL, 0, "Maximum allowed number of instances", HFILL }},
{ &hf_smb_pipe_getinfo_current_instances,
{ "Current Instances", "smb_pipe.getinfo.current_instances", FT_UINT8, BASE_DEC,
NULL, 0, "Current number of instances", HFILL }},
{ &hf_smb_pipe_getinfo_pipe_name_length,
{ "Pipe Name Length", "smb_pipe.getinfo.pipe_name_length", FT_UINT8, BASE_DEC,
NULL, 0, "Length of pipe name", HFILL }},
{ &hf_smb_pipe_getinfo_pipe_name,
{ "Pipe Name", "smb_pipe.getinfo.pipe_name", FT_STRING, BASE_NONE,
NULL, 0, "Name of pipe", HFILL }},
{ &hf_smb_pipe_write_raw_bytes_written,
{ "Bytes Written", "smb_pipe.write_raw.bytes_written", FT_UINT16, BASE_DEC,
NULL, 0, "Number of bytes written to the pipe", HFILL }},
{ &hf_smb_pipe_fragment_overlap,
{ "Fragment overlap", "smb_pipe.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_smb_pipe_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "smb_pipe.fragment.overlap.conflict", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Overlapping fragments contained conflicting data", HFILL }},
{ &hf_smb_pipe_fragment_multiple_tails,
{ "Multiple tail fragments found", "smb_pipe.fragment.multipletails", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Several tails were found when defragmenting the packet", HFILL }},
{ &hf_smb_pipe_fragment_too_long_fragment,
{ "Fragment too long", "smb_pipe.fragment.toolongfragment", FT_BOOLEAN,
BASE_NONE, NULL, 0x0, "Fragment contained data past end of packet", HFILL }},
{ &hf_smb_pipe_fragment_error,
{ "Defragmentation error", "smb_pipe.fragment.error", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_smb_pipe_fragment_count,
{ "Fragment count", "smb_pipe.fragment.count", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_fragment,
{ "Fragment", "smb_pipe.fragment", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "Pipe Fragment", HFILL }},
{ &hf_smb_pipe_fragments,
{ "Fragments", "smb_pipe.fragments", FT_NONE,
BASE_NONE, NULL, 0x0, "Pipe Fragments", HFILL }},
{ &hf_smb_pipe_reassembled_in,
{ "This PDU is reassembled in", "smb_pipe.reassembled_in", FT_FRAMENUM,
BASE_NONE, NULL, 0x0, "The DCE/RPC PDU is completely reassembled in this frame", HFILL }},
{ &hf_smb_pipe_reassembled_length,
{ "Reassembled SMB Pipe length", "smb_pipe.reassembled.length", FT_UINT32,
BASE_DEC, NULL, 0x0, "The total length of the reassembled payload", HFILL }},
{ &hf_smb_pipe_word_param,
{ "Word Param", "smb_pipe.word_param", FT_UINT16,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_doubleword_param,
{ "Doubleword Param", "smb_pipe.doubleword_param", FT_UINT32,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_byte_param,
{ "Byte Param", "smb_pipe.byte_param", FT_UINT8,
BASE_DEC_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_bytes_param,
{ "Bytes Param", "smb_pipe.bytes_param", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_string_param,
{ "String Param", "smb_pipe.string_param", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_smb_pipe_stringz_param,
{ "String Param", "smb_pipe.string_param", FT_STRINGZ,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_smb_pipe,
&ett_smb_pipe_fragment,
&ett_smb_pipe_fragments,
};
static ei_register_info ei[] = {
{ &ei_smb_pipe_bogus_netwkstauserlogon, { "smb_pipe.bogus_netwkstauserlogon_parameters", PI_PROTOCOL, PI_WARN, "Bogus NetWkstaUserLogon parameters", EXPFILL }},
{ &ei_smb_pipe_bad_type, { "smb_pipe.bad_type", PI_PROTOCOL, PI_ERROR, "Bad type field", EXPFILL }},
};
expert_module_t* expert_smb_pipe;
proto_smb_pipe = proto_register_protocol("SMB Pipe Protocol", "SMB Pipe", "smb_pipe");
proto_register_field_array(proto_smb_pipe, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_smb_pipe = expert_register_protocol(proto_smb_pipe);
expert_register_field_array(expert_smb_pipe, ei, array_length(ei));
smb_transact_heur_subdissector_list = register_heur_dissector_list("smb_transact", proto_smb_pipe);
reassembly_table_register(&dcerpc_reassembly_table,
&addresses_reassembly_table_functions);
}
