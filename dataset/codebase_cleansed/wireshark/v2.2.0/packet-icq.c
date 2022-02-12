static guint32
get_v5key(guint32 code, int len)
{
guint32 a1, a2, a3, a4, a5;
guint32 check, key;
a1 = code & 0x0001f000;
a2 = code & 0x07c007c0;
a3 = code & 0x003e0001;
a4 = code & 0xf8000000;
a5 = code & 0x0000083e;
a1 = a1 >> 0x0c;
a2 = a2 >> 0x01;
a3 = a3 << 0x0a;
a4 = a4 >> 0x10;
a5 = a5 << 0x0f;
check = a5 + a1 + a2 + a3 + a4;
key = len * 0x68656C6C;
key += check;
return key;
}
static void
decrypt_v5(guchar *bfr, guint32 size,guint32 key)
{
guint32 i;
guint32 k;
for (i=ICQ5_CL_SESSIONID; i < size; i+=4 ) {
k = key+table_v5[i&0xff];
if ( i != 0x16 ) {
bfr[i] ^= (guchar)(k & 0xff);
bfr[i+1] ^= (guchar)((k & 0xff00)>>8);
}
if ( i != 0x12 ) {
bfr[i+2] ^= (guchar)((k & 0xff0000)>>16);
bfr[i+3] ^= (guchar)((k & 0xff000000)>>24);
}
}
}
static guint16
proto_add_icq_attr(proto_tree *tree,
tvbuff_t *tvb,
const int offset,
const int* hf)
{
guint16 len;
len = tvb_get_letohs(tvb, offset);
if (len > tvb_reported_length_remaining(tvb, offset))
return -1;
proto_tree_add_string(tree, *hf, tvb, offset, len+2,
tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, len, ENC_ASCII));
return len + 2;
}
static void
icqv5_decode_msgType(proto_tree *tree, tvbuff_t *tvb, int offset, int size,
packet_info *pinfo)
{
proto_item *msg_item;
proto_tree *subtree;
int left = size;
guint16 msgType;
gint sep_offset;
int sz;
unsigned int n;
static const int *url_field_descr[] = {
&hf_icq_description,
&hf_icq_url,
};
#define N_URL_FIELDS (sizeof url_field_descr / sizeof url_field_descr[0])
static const int *email_field_descr[] = {
&hf_icq_nickname,
&hf_icq_first_name,
&hf_icq_last_name,
&hf_icq_email,
&hf_icq_unknown,
&hf_icq_text,
};
#define N_EMAIL_FIELDS (sizeof email_field_descr / sizeof email_field_descr[0])
static const int *auth_req_field_descr[] = {
&hf_icq_nickname,
&hf_icq_first_name,
&hf_icq_last_name,
&hf_icq_email,
&hf_icq_unknown,
&hf_icq_reason,
};
#define N_AUTH_REQ_FIELDS (sizeof auth_req_field_descr / sizeof auth_req_field_descr[0])
static const int *user_added_field_descr[] = {
&hf_icq_nickname,
&hf_icq_first_name,
&hf_icq_last_name,
&hf_icq_email,
};
#define N_USER_ADDED_FIELDS (sizeof user_added_field_descr / sizeof user_added_field_descr[0])
msgType = tvb_get_letohs(tvb, offset);
subtree = proto_tree_add_subtree_format(tree, tvb, offset, size, ett_icq_body_parts, NULL,
"%s Message", val_to_str_const(msgType, msgTypeCode, "Unknown"));
msg_item = proto_tree_add_item(subtree, hf_icq_msg_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
left -= 2;
if (msgType != MSG_AUTH) {
proto_tree_add_item(subtree, hf_icq_msg_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
left -= 2;
}
switch(msgType) {
case 0xffff:
break;
default:
expert_add_info_format(pinfo, msg_item, &ei_icq_unknown_command,
"Unknown msgType: %u (0x%x)", msgType, msgType);
break;
case MSG_TEXT:
proto_tree_add_item(subtree, hf_icq_msg, tvb, offset, left, ENC_ASCII|ENC_NA);
break;
case MSG_URL:
for (n = 0; n < N_URL_FIELDS; n++) {
if (n != N_URL_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else {
sz = left;
}
if (sz != 0) {
proto_tree_add_item(subtree, *url_field_descr[n], tvb, offset, sz, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format_value(subtree, *url_field_descr[n], tvb, offset, 0,
"", "(empty)");
}
offset += sz;
left -= sz;
}
break;
case MSG_EMAIL:
for (n = 0; n < N_EMAIL_FIELDS; n++) {
if (n != N_EMAIL_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else {
sz = left;
}
if (sz != 0) {
proto_tree_add_item(subtree, *email_field_descr[n], tvb, offset, sz, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format_value(subtree, *email_field_descr[n], tvb, offset, 0,
"", "(empty)");
}
offset += sz;
left -= sz;
}
break;
case MSG_AUTH:
{
unsigned char auth_suc;
auth_suc = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(subtree, hf_icq_msg_authorization, tvb, offset, 1,
auth_suc, "(%u) %s",auth_suc,
(auth_suc==0)?"Denied":"Allowed");
offset++;
proto_tree_add_item(subtree, hf_icq_x1, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
case MSG_AUTH_REQ:
for (n = 0; n < N_AUTH_REQ_FIELDS; n++) {
if (n != N_AUTH_REQ_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else {
sz = left;
}
if (sz != 0) {
proto_tree_add_item(subtree, *auth_req_field_descr[n], tvb, offset, sz, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format_value(subtree, *auth_req_field_descr[n], tvb, offset, 0,
"", "(empty)");
}
offset += sz;
left -= sz;
}
break;
case MSG_USER_ADDED:
for (n = 0; n < N_USER_ADDED_FIELDS; n++) {
if (n != N_USER_ADDED_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else {
sz = left;
}
if (sz != 0) {
proto_tree_add_item(subtree, *user_added_field_descr[n], tvb, offset, sz, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_string_format_value(subtree, *user_added_field_descr[n], tvb, offset, 0,
"", "(empty)");
}
offset += sz;
left -= sz;
}
break;
case MSG_CONTACTS:
{
gint sep_offset_prev;
int sz_local = 0;
int n_local = 0;
gboolean last = FALSE;
while (!last) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
if (sep_offset != -1) {
sz_local = sep_offset - offset + 1;
}
else {
sz_local = left;
last = TRUE;
}
if (n_local == 0) {
proto_tree_add_item(subtree, hf_icq_num_uin_pairs, tvb, offset, sz_local, ENC_ASCII|ENC_NA);
n_local++;
} else if (!last) {
int svsz = sz_local;
char* contact;
left -= sz_local;
sep_offset_prev = sep_offset;
sep_offset = tvb_find_guint8(tvb, sep_offset_prev, left, 0xfe);
if (sep_offset != -1)
sz_local = sep_offset - offset + 1;
else {
sz_local = left;
last = TRUE;
}
contact = tvb_get_string_enc(wmem_packet_scope(), tvb, sep_offset_prev + 1, sz_local, ENC_ASCII);
proto_tree_add_string_format(subtree, hf_icq_msg_contact, tvb, offset, sz_local + svsz,
contact, "%.*s: %.*s", svsz - 1,
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, svsz, ENC_ASCII), sz_local - 1,
contact);
n_local += 2;
}
left -= (sz_local+1);
offset = sep_offset + 1;
}
break;
}
}
}
static void
icqv5_cmd_send_text_code(proto_tree *tree,
tvbuff_t *tvb,
int offset)
{
proto_tree *subtree = tree;
guint16 len;
len = tvb_get_letohs(tvb, offset+CMD_SEND_TEXT_CODE_LEN);
proto_tree_add_item(subtree, hf_icq_text_code_length, tvb, offset + CMD_SEND_TEXT_CODE_LEN, 2, ENC_LITTLE_ENDIAN);
if (len>0) {
proto_tree_add_item(subtree, hf_icq_text_code, tvb, offset + CMD_SEND_TEXT_CODE_TEXT, len, ENC_ASCII|ENC_NA);
}
proto_tree_add_item(subtree, hf_icq_x1, tvb, offset + CMD_SEND_TEXT_CODE_TEXT + len, 2, ENC_LITTLE_ENDIAN);
}
static void
icqv5_cmd_send_msg(proto_tree *tree, tvbuff_t *tvb, int offset, int size,
packet_info *pinfo)
{
proto_tree_add_item(tree, hf_icq_receiver_uin, tvb, offset + CMD_SEND_MSG_RECV_UIN, 4, ENC_LITTLE_ENDIAN);
size -= 4;
icqv5_decode_msgType(tree, tvb, offset + CMD_SEND_MSG_MSG_TYPE,
size, pinfo);
}
static void
icqv5_cmd_login(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree *subtree = tree;
time_t theTime;
char *aTime;
guint32 passwdLen;
if (tree) {
theTime = tvb_get_letohl(tvb, offset + CMD_LOGIN_TIME);
aTime = abs_time_secs_to_str(wmem_packet_scope(), theTime, ABSOLUTE_TIME_LOCAL, TRUE);
proto_tree_add_uint_format_value(subtree, hf_icq_login_time, tvb, offset + CMD_LOGIN_TIME, 4,
(guint32)theTime, "%u = %s", (guint32)theTime, aTime);
proto_tree_add_item(subtree, hf_icq_login_port, tvb, offset + CMD_LOGIN_PORT, 4, ENC_LITTLE_ENDIAN);
passwdLen = tvb_get_letohs(tvb, offset + CMD_LOGIN_PASSLEN);
proto_tree_add_item(subtree, hf_icq_login_password, tvb, offset + CMD_LOGIN_PASSLEN, 2 + passwdLen, ENC_ASCII|ENC_NA);
proto_tree_add_item(subtree, hf_icq_login_ip, tvb, offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_IP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_icq_status, tvb, offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_STATUS, 4, ENC_LITTLE_ENDIAN);
}
}
static void
icqv5_cmd_contact_list(proto_tree *tree, tvbuff_t *tvb, int offset)
{
unsigned char num;
int i;
guint32 uin;
if (tree) {
num = tvb_get_guint8(tvb, offset + CMD_CONTACT_LIST_NUM);
proto_tree_add_item(tree, hf_icq_number_of_uins, tvb, offset + CMD_CONTACT_LIST, 1, ENC_NA);
offset += (CMD_CONTACT_LIST_NUM + 1);
for (i = 0; i < num; i++) {
uin = tvb_get_letohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_icq_uin, tvb, offset, 4,
uin, "UIN[%d]: %u", i, uin);
offset += 4;
}
}
}
static void
icqv5_srv_user_online(proto_tree *tree,
tvbuff_t *tvb,
int offset)
{
proto_tree *subtree = tree;
if (tree) {
proto_tree_add_item(subtree, hf_icq_uin, tvb, offset + SRV_USER_ONL_UIN, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_user_online_ip, tvb, offset + SRV_USER_ONL_IP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_icq_user_online_port, tvb, offset + SRV_USER_ONL_PORT, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_user_online_realip, tvb, offset + SRV_USER_ONL_REALIP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_icq_status, tvb, offset + SRV_USER_ONL_STATUS, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_user_online_version, tvb, offset + SRV_USER_ONL_X2, 4, ENC_LITTLE_ENDIAN);
}
}
static void
icqv5_srv_multi(proto_tree *tree,
tvbuff_t *tvb,
int offset,
packet_info *pinfo)
{
guint8 num;
guint16 pktSz;
int i;
num = tvb_get_guint8(tvb, offset + SRV_MULTI_NUM);
proto_tree_add_item(tree, hf_icq_multi_num_packets, tvb, offset + SRV_MULTI_NUM, 1, ENC_NA);
offset += (SRV_MULTI_NUM + 1);
for (i = 0; i < num; i++) {
pktSz = tvb_get_letohs(tvb, offset);
offset += 2;
dissect_icqv5Server(tvb, offset, pinfo, tree, pktSz);
offset += pktSz;
}
}
static void
icqv5_srv_meta_user(proto_tree *tree,
tvbuff_t *tvb,
int offset,
int size _U_,
packet_info *pinfo)
{
proto_tree *sstree;
proto_item *ti;
guint16 subcmd;
unsigned char result;
subcmd = tvb_get_letohs(tvb, offset + SRV_META_USER_SUBCMD);
ti = proto_tree_add_item(tree, hf_icq_meta_user_subcmd, tvb, offset + SRV_META_USER_SUBCMD, 2, ENC_LITTLE_ENDIAN);
sstree = proto_item_add_subtree(ti, ett_icq_body_parts);
result = tvb_get_guint8(tvb, offset + SRV_META_USER_RESULT);
proto_tree_add_uint_format_value(sstree, hf_icq_meta_user_result, tvb, offset + SRV_META_USER_RESULT,
result, 1, "%s", (result==0x0a)?"Success":"Failure");
offset += 3;
switch(subcmd) {
case META_EX_USER_FOUND:
{
proto_tree_add_item(sstree, hf_icq_meta_user_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
case META_USER_FOUND:
{
int len = 0;
static const int *hf_descr[] = {
&hf_icq_nickname,
&hf_icq_first_name,
&hf_icq_last_name,
&hf_icq_email,
NULL
};
const int **hf = hf_descr;
unsigned char auth;
proto_tree_add_item(sstree, hf_icq_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
for ( ; *hf!=NULL; hf++) {
len = proto_add_icq_attr(sstree, tvb, offset, *hf);
if (len == -1)
return;
offset += len;
}
auth = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(sstree, hf_icq_meta_user_found_authorization, tvb, offset, 1,
auth, "%s", (auth==0x01)?"Necessary":"Who needs it");
offset++;
proto_tree_add_item(sstree, hf_icq_meta_user_x2, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(sstree, hf_icq_meta_user_x3, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
}
case META_ABOUT:
{
int len;
len = tvb_get_letohs(tvb, offset);
offset+=2;
proto_tree_add_string(sstree, hf_icq_meta_user_about, tvb, offset - 2,
len+2, tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII));
break;
}
case META_USER_INFO:
{
static const int *hf_descr[] = {
&hf_icq_nickname,
&hf_icq_first_name,
&hf_icq_last_name,
&hf_icq_primary_email,
&hf_icq_secondary_email,
&hf_icq_old_email,
&hf_icq_city,
&hf_icq_state,
&hf_icq_phone,
&hf_icq_fax,
&hf_icq_street,
&hf_icq_cellphone,
&hf_icq_zip,
NULL
};
const int **hf = hf_descr;
int len = 0;
#if 0
proto_tree_add_item(sstree, hf_icq_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
#endif
for ( ; *hf!=NULL; hf++) {
len = proto_add_icq_attr(sstree, tvb, offset, *hf);
if (len < 0) {
offset+=2;
continue;
}
offset+=len;
}
proto_tree_add_item(sstree, hf_icq_meta_user_countrycode, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(sstree, hf_icq_meta_user_timezone, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(sstree, hf_icq_meta_user_info_authorization, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(sstree, hf_icq_meta_user_webaware, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(sstree, hf_icq_meta_user_hideip, tvb, offset, 1, ENC_NA);
break;
}
default:
expert_add_info_format(pinfo, ti, &ei_icq_unknown_meta_subcmd,
"Unknown Meta subcmd: 0x%x", subcmd);
break;
}
}
static void
icqv5_srv_recv_message(proto_tree *tree,
tvbuff_t *tvb,
int offset,
int size,
packet_info *pinfo)
{
guint16 year;
guint8 month;
guint8 day;
guint8 hour;
guint8 minute;
proto_tree_add_item(tree, hf_icq_uin, tvb, offset + SRV_RECV_MSG_UIN,
4, ENC_LITTLE_ENDIAN);
year = tvb_get_letohs(tvb, offset + SRV_RECV_MSG_YEAR);
month = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_MONTH);
day = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_DAY);
hour = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_HOUR);
minute = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_MINUTE);
proto_tree_add_bytes_format_value(tree, hf_icq_recv_time, tvb, offset + SRV_RECV_MSG_YEAR,
2 + 4, NULL, "%u-%u-%u %02u:%02u",
day, month, year, hour, minute);
icqv5_decode_msgType(tree, tvb, offset + SRV_RECV_MSG_MSG_TYPE,
size-10, pinfo);
}
static void
icqv5_srv_rand_user(proto_tree *tree,
tvbuff_t *tvb,
int offset)
{
proto_tree *subtree = tree;
guint8 commClass;
if (tree) {
proto_tree_add_item(subtree, hf_icq_uin, tvb, offset + SRV_RAND_USER_UIN,
4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_rand_user_ip, tvb, offset + SRV_RAND_USER_IP, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_icq_rand_user_port, tvb, offset + SRV_RAND_USER_PORT, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_rand_user_realip, tvb, offset + SRV_RAND_USER_REAL_IP, 4, ENC_BIG_ENDIAN);
commClass = tvb_get_guint8(tvb, offset + SRV_RAND_USER_CLASS);
proto_tree_add_uint_format_value(subtree, hf_icq_rand_user_class, tvb, offset + SRV_RAND_USER_CLASS,
1, commClass, "%s", (commClass!=4)?"User to User":"Through Server");
proto_tree_add_item(subtree, hf_icq_status, tvb, offset + SRV_RAND_USER_STATUS, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_icq_rand_user_tcpversion, tvb, offset + SRV_RAND_USER_TCP_VER, 2, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_icqv5Client(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icq_header_tree, *icq_body_tree;
proto_item *ti, *cmd_item;
int pktsize;
int capturedsize;
guint32 rounded_size;
guint32 code, key;
guint16 cmd;
guint8 *decr_pd;
tvbuff_t *decr_tvb;
pktsize = tvb_reported_length(tvb);
capturedsize = tvb_captured_length(tvb);
code = tvb_get_letohl(tvb, ICQ5_CL_CHECKCODE);
key = get_v5key(code, pktsize);
rounded_size = ((((capturedsize - ICQ5_CL_SESSIONID) + 3)/4)*4) + ICQ5_CL_SESSIONID;
decr_pd = (guint8 *)wmem_alloc(pinfo->pool, rounded_size);
tvb_memcpy(tvb, decr_pd, 0, capturedsize);
decrypt_v5(decr_pd, rounded_size, key);
decr_tvb = tvb_new_child_real_data(tvb, decr_pd, capturedsize, pktsize);
add_new_data_source(pinfo, decr_tvb, "Decrypted");
cmd = tvb_get_letohs(decr_tvb, ICQ5_CL_CMD);
col_add_fstr(pinfo->cinfo, COL_INFO, "ICQv5 %s", val_to_str_const(cmd, clientCmdCode, "Unknown"));
icq_header_tree = proto_tree_add_subtree(tree, tvb, 0, ICQ5_CL_HDRSIZE, ett_icq_header, NULL, "Header");
ti = proto_tree_add_boolean(icq_header_tree, hf_icq_type, tvb, 0, 0, ICQ5_CLIENT);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(icq_header_tree, hf_icq_version, tvb, ICQ_VERSION, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_uin, tvb, ICQ5_CL_UIN, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_sessionid, decr_tvb, ICQ5_CL_SESSIONID, 4, ENC_LITTLE_ENDIAN);
cmd_item = proto_tree_add_item(icq_header_tree, hf_icq_client_cmd, decr_tvb, ICQ5_CL_CMD, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_seqnum1, decr_tvb, ICQ5_CL_SEQNUM1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_seqnum2, decr_tvb, ICQ5_CL_SEQNUM2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_checkcode, tvb, ICQ5_CL_CHECKCODE, 4, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_uint(icq_header_tree, hf_icq_checkcode_key, tvb, ICQ5_CL_CHECKCODE, 4, key);
PROTO_ITEM_SET_GENERATED(ti);
icq_body_tree = proto_tree_add_subtree(tree, decr_tvb, ICQ5_CL_HDRSIZE, pktsize - ICQ5_CL_HDRSIZE, ett_icq_body, NULL, "Body");
switch(cmd) {
case CMD_ACK:
proto_tree_add_item(icq_body_tree, hf_icq_ack_random, decr_tvb, ICQ5_CL_HDRSIZE + CMD_ACK_RANDOM, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_SEND_MSG:
case CMD_MSG_TO_NEW_USER:
icqv5_cmd_send_msg(icq_body_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE, pinfo);
break;
case CMD_RAND_SEARCH:
proto_tree_add_item(icq_body_tree, hf_icq_group, decr_tvb, ICQ5_CL_HDRSIZE + CMD_RAND_SEARCH_GROUP, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_LOGIN:
icqv5_cmd_login(icq_body_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_SEND_TEXT_CODE:
icqv5_cmd_send_text_code(icq_body_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_STATUS_CHANGE:
proto_tree_add_item(icq_body_tree, hf_icq_status, decr_tvb, ICQ5_CL_HDRSIZE + CMD_STATUS_CHANGE_STATUS, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_ACK_MESSAGES:
proto_tree_add_item(icq_body_tree, hf_icq_ack_random, decr_tvb, ICQ5_CL_HDRSIZE + CMD_ACK_MESSAGES_RANDOM, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_KEEP_ALIVE:
proto_tree_add_item(icq_body_tree, hf_icq_keep_alive_random, decr_tvb, ICQ5_CL_HDRSIZE + CMD_KEEP_ALIVE_RANDOM, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_ADD_TO_LIST:
proto_tree_add_item(icq_body_tree, hf_icq_uin, decr_tvb, ICQ5_CL_HDRSIZE + CMD_ADD_TO_LIST_UIN, 4, ENC_LITTLE_ENDIAN);
break;
case CMD_CONTACT_LIST:
icqv5_cmd_contact_list(icq_body_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_META_USER:
case CMD_REG_NEW_USER:
case CMD_QUERY_SERVERS:
case CMD_QUERY_ADDONS:
proto_tree_add_item(icq_body_tree, hf_icq_no_parameters, tvb, ICQ5_CL_HDRSIZE, 0, ENC_NA);
break;
default:
expert_add_info(pinfo, cmd_item, &ei_icq_unknown_command);
break;
}
}
static void
dissect_icqv5Server(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int pktsize)
{
proto_tree *icq_header_tree, *icq_body_tree;
proto_item *ti, *cmd_item;
guint16 cmd = tvb_get_letohs(tvb, offset + ICQ5_SRV_CMD);
if (pktsize == -1) {
col_add_fstr(pinfo->cinfo, COL_INFO, "ICQv5 %s", val_to_str_const(cmd, serverCmdCode, "Unknown"));
pktsize = tvb_reported_length(tvb);
}
icq_header_tree = proto_tree_add_subtree(tree, tvb, offset, ICQ5_SRV_HDRSIZE, ett_icq_header, NULL, "Header");
ti = proto_tree_add_boolean(icq_header_tree, hf_icq_type, tvb, 0, 0, ICQ5_SERVER);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(icq_header_tree, hf_icq_version, tvb, offset + ICQ_VERSION, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_sessionid, tvb, offset + ICQ5_SRV_SESSIONID, 4, ENC_LITTLE_ENDIAN);
cmd_item = proto_tree_add_item(icq_header_tree, hf_icq_server_cmd, tvb, offset + ICQ5_SRV_CMD, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_seqnum1, tvb, offset + ICQ5_SRV_SEQNUM1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_seqnum2, tvb, offset + ICQ5_SRV_SEQNUM2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_uin, tvb, offset + ICQ5_SRV_UIN, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_checkcode, tvb, offset + ICQ5_SRV_CHECKCODE, 4, ENC_LITTLE_ENDIAN);
icq_body_tree = proto_tree_add_subtree(tree, tvb, ICQ5_CL_HDRSIZE, pktsize - ICQ5_SRV_HDRSIZE, ett_icq_body, NULL, "Body");
switch (cmd) {
case SRV_RAND_USER:
icqv5_srv_rand_user(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE);
break;
case SRV_SYS_DELIVERED_MESS:
icqv5_cmd_send_msg(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_USER_ONLINE:
icqv5_srv_user_online(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE);
break;
case SRV_USER_OFFLINE:
proto_tree_add_item(icq_body_tree, hf_icq_uin, tvb, offset + ICQ5_SRV_HDRSIZE + SRV_USER_OFFLINE_UIN, 4, ENC_LITTLE_ENDIAN);
break;
case SRV_LOGIN_REPLY:
proto_tree_add_item(tree, hf_icq_login_reply_ip, tvb, offset + ICQ5_SRV_HDRSIZE + SRV_LOGIN_REPLY_IP, 4, ENC_BIG_ENDIAN);
break;
case SRV_META_USER:
icqv5_srv_meta_user(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_RECV_MESSAGE:
icqv5_srv_recv_message(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_MULTI:
icqv5_srv_multi(icq_body_tree, tvb, offset + ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_ACK:
case SRV_SILENT_TOO_LONG:
case SRV_GO_AWAY:
case SRV_NEW_UIN:
case SRV_BAD_PASS:
case SRV_UPDATE_SUCCESS:
proto_tree_add_item(icq_body_tree, hf_icq_no_parameters, tvb, offset + ICQ5_SRV_HDRSIZE, 0, ENC_NA);
break;
default:
expert_add_info(pinfo, cmd_item, &ei_icq_unknown_command);
break;
}
}
static void dissect_icqv5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_get_letohl(tvb, ICQ5_UNKNOWN) == 0) {
dissect_icqv5Client(tvb, pinfo, tree);
} else {
dissect_icqv5Server(tvb, 0, pinfo, tree, -1);
}
}
static int
dissect_icq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int version;
proto_item *ti;
proto_tree *icq_tree;
version = tvb_get_letohs(tvb, ICQ_VERSION);
if (version < 2 || version > 5)
return 0;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "ICQv%d", version);
col_add_fstr(pinfo->cinfo, COL_INFO, "ICQ Version %d protocol", version);
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, 0, -1, "ICQv%d", version);
icq_tree = proto_item_add_subtree(ti, ett_icq);
if (version == 5)
{
dissect_icqv5(tvb, pinfo, icq_tree);
}
else
{
proto_tree_add_item(icq_tree, hf_icq_version, tvb, ICQ_VERSION, 2, ENC_LITTLE_ENDIAN);
}
return (tvb_captured_length(tvb));
}
void
proto_register_icq(void)
{
static hf_register_info hf[] = {
{ &hf_icq_version,
{"Version", "icq.version", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_type,
{"Client/Server", "icq.client", FT_BOOLEAN, BASE_NONE, TFS(&tfs_client_server), 0x0, NULL, HFILL }},
{ &hf_icq_msg_type,
{"Type", "icq.msg_type", FT_UINT16, BASE_DEC, VALS(msgTypeCode), 0x0, NULL, HFILL }},
{ &hf_icq_uin,
{"UIN", "icq.uin", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_sessionid,
{"Session ID", "icq.sessionid", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_client_cmd,
{"Client command", "icq.client_cmd", FT_UINT16, BASE_DEC, VALS(clientCmdCode), 0x0, NULL, HFILL }},
{ &hf_icq_server_cmd,
{"Server command", "icq.server_cmd", FT_UINT16, BASE_DEC, VALS(serverCmdCode), 0x0, NULL, HFILL }},
{ &hf_icq_checkcode,
{"Checkcode", "icq.checkcode", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_checkcode_key,
{"Key", "icq.checkcode_key", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_seqnum1,
{"Seq Number 1", "icq.seqnum1", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_seqnum2,
{"Seq Number 2", "icq.seqnum2", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_group,
{"Group", "icq.group", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_ack_random,
{"Random", "icq.ack.random", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_keep_alive_random,
{"Random", "icq.keep_alive.random", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_status,
{"Client command", "icq.status", FT_UINT32, BASE_DEC, VALS(statusCode), 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_subcmd,
{"Subcommand", "icq.meta_user.subcmd", FT_UINT16, BASE_DEC, VALS(serverMetaSubCmdCode), 0x0, NULL, HFILL }},
{ &hf_icq_msg_length, { "Length", "icq.msg_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_msg, { "Msg", "icq.msg", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_msg_authorization, { "Authorization", "icq.msg_authorization", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_x1, { "X1", "icq.x1", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_num_uin_pairs, { "Number of pairs", "icq.num_uin_pairs", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_text_code_length, { "Length", "icq.text_code_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_text_code, { "Text", "icq.text_code", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_receiver_uin, { "Receiver UIN", "icq.receiver_uin", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_login_time, { "Time", "icq.login.time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_login_port, { "Port", "icq.login.port", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_login_password, { "Password", "icq.login.password", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_login_ip, { "IP", "icq.login.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_number_of_uins, { "Number of uins", "icq.number_of_uins", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_user_online_ip, { "IP", "icq.user_online.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_user_online_port, { "Port", "icq.user_online.port", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_user_online_realip, { "RealIP", "icq.user_online.realip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_user_online_version, { "Version", "icq.user_online.version", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_multi_num_packets, { "Number of pkts", "icq.multi.num_packets", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_result, { "Result", "icq.meta_user.result", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_length, { "Length", "icq.meta_user.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_found_authorization, { "Authorization", "icq.meta_user.found_authorization", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_x2, { "x2", "icq.meta_user.x2", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_x3, { "x3", "icq.meta_user.x3", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_about, { "About", "icq.meta_user.about", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_countrycode, { "Countrycode", "icq.meta_user.countrycode", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_timezone, { "Timezone", "icq.meta_user.timezone", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_info_authorization, { "Authorization", "icq.meta_user.info_authorization", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_webaware, { "Webaware", "icq.meta_user.webaware", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_icq_meta_user_hideip, { "HideIP", "icq.meta_user.hideip", FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x0, NULL, HFILL }},
{ &hf_icq_rand_user_ip, { "IP", "icq.rand_user.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_rand_user_port, { "Port", "icq.rand_user.port", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_rand_user_realip, { "RealIP", "icq.rand_user.realip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_rand_user_class, { "Class", "icq.rand_user.class", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_rand_user_tcpversion, { "TCPVersion", "icq.rand_user.tcpversion", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_no_parameters, { "No parameters", "icq.no_parameters", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_login_reply_ip, { "IP", "icq.login_reply.ip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_nickname, { "Nickname", "icq.nickname", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_first_name, { "First name", "icq.first_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_last_name, { "Last name", "icq.last_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_email, { "Email", "icq.email", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_primary_email, { "Primary email", "icq.primary_email", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_secondary_email, { "Secondary email", "icq.secondary_email", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_old_email, { "Old email", "icq.old_email", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_city, { "City", "icq.city", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_state, { "State", "icq.state", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_phone, { "Phone", "icq.phone", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_fax, { "Fax", "icq.fax", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_street, { "Street", "icq.street", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_cellphone, { "Cellphone", "icq.cellphone", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_zip, { "Zip", "icq.zip", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_description, { "Description", "icq.description", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_url, { "URL", "icq.url", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_text, { "Text", "icq.text", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_unknown, { "Unknown", "icq.unknown", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_reason, { "Reason", "icq.reason", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_msg_contact, { "Contact", "icq.msg_contact", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_recv_time, { "Time", "icq.recv_time", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_icq,
&ett_icq_header,
&ett_icq_body,
&ett_icq_body_parts,
};
static ei_register_info ei[] = {
{ &ei_icq_unknown_meta_subcmd, { "icq.unknown_meta_subcmd", PI_UNDECODED, PI_WARN, "Unknown meta subcmd", EXPFILL }},
{ &ei_icq_unknown_command, { "icq.unknown_command", PI_UNDECODED, PI_WARN, "Unknown command", EXPFILL }},
};
expert_module_t *expert_icq;
proto_icq = proto_register_protocol("ICQ Protocol", "ICQ", "icq");
proto_register_field_array(proto_icq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_icq = expert_register_protocol(proto_icq);
expert_register_field_array(expert_icq, ei, array_length(ei));
}
void
proto_reg_handoff_icq(void)
{
dissector_handle_t icq_handle;
icq_handle = create_dissector_handle(dissect_icq, proto_icq);
dissector_add_uint("udp.port", UDP_PORT_ICQ, icq_handle);
}
