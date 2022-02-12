static const char*
findMsgType(int num)
{
return val_to_str_const(num, msgTypeCode, "Unknown");
}
static const char*
findSubCmd(int num)
{
return val_to_str(num, serverMetaSubCmdCode, "Unknown (0x%04x)");
}
static const char*
findClientCmd(int num)
{
return val_to_str(num, clientCmdCode, "Unknown (%u)");
}
static const char*
findServerCmd(int num)
{
return val_to_str(num, serverCmdCode, "Unknown (%u)");
}
static const char*
findStatus(int num)
{
return val_to_str(num, statusCode, "Unknown (0x%08x)");
}
static guint32
get_v5key(tvbuff_t *tvb, int len)
{
guint32 a1, a2, a3, a4, a5;
guint32 code, check, key;
code = tvb_get_letohl(tvb, ICQ5_CL_CHECKCODE);
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
static void
dissect_icqv4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icq_tree = NULL;
proto_item *ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICQv4 (UDP)");
col_set_str(pinfo->cinfo, COL_INFO, "ICQ Version 4 protocol");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, 0, -1,
"ICQv4");
icq_tree = proto_item_add_subtree(ti, ett_icq);
proto_tree_add_text(icq_tree, tvb, ICQ_VERSION, 2, "Version: %u",
tvb_get_letohs(tvb, ICQ_VERSION));
}
}
static void
dissect_icqv3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icq_tree = NULL;
proto_item *ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICQv3 (UDP)");
col_set_str(pinfo->cinfo, COL_INFO, "ICQ Version 3 protocol");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, 0, -1,
"ICQv3");
icq_tree = proto_item_add_subtree(ti, ett_icq);
proto_tree_add_text(icq_tree, tvb, ICQ_VERSION, 2, "Version: %u",
tvb_get_letohs(tvb, ICQ_VERSION));
}
}
static void
dissect_icqv2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icq_tree = NULL;
proto_item *ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICQv2 (UDP)");
col_set_str(pinfo->cinfo, COL_INFO, "ICQ Version 2 protocol");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, 0, -1,
"ICQv2");
icq_tree = proto_item_add_subtree(ti, ett_icq);
proto_tree_add_text(icq_tree, tvb, ICQ_VERSION, 2, "Version: %u",
tvb_get_letohs(tvb, ICQ_VERSION));
}
}
static guint16
proto_add_icq_attr(proto_tree* tree,
tvbuff_t *tvb,
const int offset,
const char* descr)
{
guint16 len;
len = tvb_get_letohs(tvb, offset);
if (len > tvb_reported_length_remaining(tvb, offset))
return -1;
proto_tree_add_text(tree, tvb, offset, (int)sizeof(guint16) + len,
"%s[%u]: %.*s", descr, len, len,
tvb_get_ephemeral_string(tvb, offset + (int)sizeof(guint16), len));
return len + (int)sizeof(guint16);
}
static void
icqv5_decode_msgType(proto_tree* tree, tvbuff_t *tvb, int offset, int size,
packet_info *pinfo)
{
proto_item* ti = NULL;
proto_tree* subtree = NULL;
int left = size;
guint16 msgType;
gint sep_offset;
int sz;
unsigned int n;
static const char* url_field_descr[] = {
"Description",
"URL",
};
#define N_URL_FIELDS (sizeof url_field_descr / sizeof url_field_descr[0])
static const char* email_field_descr[] = {
"Nickname",
"First name",
"Last name",
"Email address",
"Unknown",
"Text"
};
#define N_EMAIL_FIELDS (sizeof email_field_descr / sizeof email_field_descr[0])
static const char* auth_req_field_descr[] = {
"Nickname",
"First name",
"Last name",
"Email address",
"Unknown",
"Reason"
};
#define N_AUTH_REQ_FIELDS (sizeof auth_req_field_descr / sizeof auth_req_field_descr[0])
static const char* user_added_field_descr[] = {
"Nickname",
"First name",
"Last name",
"Email address",
};
#define N_USER_ADDED_FIELDS (sizeof user_added_field_descr / sizeof user_added_field_descr[0])
msgType = tvb_get_letohs(tvb, offset);
ti = proto_tree_add_text(tree, tvb, offset, size,
"Message: Type = %u (%s)", msgType, findMsgType(msgType));
subtree = proto_item_add_subtree(ti, ett_icq_body_parts);
proto_tree_add_text(subtree, tvb, offset, 2,
"Type: %u (%s)", msgType, findMsgType(msgType));
offset += 2;
left -= 2;
if (msgType != MSG_AUTH) {
proto_tree_add_text(subtree, tvb, offset, 2, "Length: %u",
tvb_get_letohs(tvb, offset));
offset += 2;
left -= 2;
}
switch(msgType) {
case 0xffff:
break;
default:
expert_add_info_format(pinfo, NULL, PI_UNDECODED, PI_WARN,
"Unknown msgType: %u (0x%x)", msgType,
msgType);
break;
case MSG_TEXT:
proto_tree_add_text(subtree, tvb, offset, left, "Msg: %.*s", left-1,
tvb_get_ephemeral_string(tvb, offset, left));
break;
case MSG_URL:
for (n = 0; n < N_URL_FIELDS; n++) {
if (n != N_URL_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else
sz = left;
if (sz != 0) {
proto_tree_add_text(subtree, tvb, offset, sz, "%s: %.*s",
url_field_descr[n],
sz - 1,
tvb_get_ephemeral_string(tvb, offset, sz));
} else {
proto_tree_add_text(subtree, tvb, offset, 0,
"%s: %s", url_field_descr[n], "(empty)");
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
} else
sz = left;
if (sz != 0) {
proto_tree_add_text(subtree, tvb, offset, sz, "%s: %.*s",
email_field_descr[n],
sz - 1,
tvb_get_ephemeral_string(tvb, offset, sz));
} else {
proto_tree_add_text(subtree, tvb, offset, 0, "%s: %s",
email_field_descr[n], "(empty)");
}
offset += sz;
left -= sz;
}
break;
case MSG_AUTH:
{
unsigned char auth_suc;
auth_suc = tvb_get_guint8(tvb, offset);
proto_tree_add_text(subtree, tvb, offset, 1,
"Authorization: (%u) %s",auth_suc,
(auth_suc==0)?"Denied":"Allowed");
offset++;
proto_tree_add_text(subtree, tvb, offset, (int)sizeof(guint16), "x1: 0x%04x",
tvb_get_letohs(tvb, offset));
break;
}
case MSG_AUTH_REQ:
for (n = 0; n < N_AUTH_REQ_FIELDS; n++) {
if (n != N_AUTH_REQ_FIELDS - 1) {
sep_offset = tvb_find_guint8(tvb, offset, left, 0xfe);
sz = sep_offset - offset + 1;
} else
sz = left;
if (sz != 0) {
proto_tree_add_text(subtree, tvb, offset, sz, "%s: %.*s",
auth_req_field_descr[n], sz - 1,
tvb_get_ephemeral_string(tvb, offset, sz));
} else {
proto_tree_add_text(subtree, tvb, offset, 0, "%s: %s",
auth_req_field_descr[n], "(empty)");
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
} else
sz = left;
if (sz != 0) {
proto_tree_add_text(subtree, tvb, offset, sz, "%s: %.*s",
user_added_field_descr[n], sz - 1,
tvb_get_ephemeral_string(tvb, offset, sz));
} else {
proto_tree_add_text(subtree, tvb, offset, 0, "%s: %s",
user_added_field_descr[n], "(empty)");
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
if (sep_offset != -1)
sz_local = sep_offset - offset + 1;
else {
sz_local = left;
last = TRUE;
}
if (n_local == 0) {
proto_tree_add_text(subtree, tvb, offset, sz_local,
"Number of pairs: %.*s", sz_local - 1,
tvb_get_ephemeral_string(tvb, offset, sz_local));
n_local++;
} else if (!last) {
int svsz = sz_local;
left -= sz_local;
sep_offset_prev = sep_offset;
sep_offset = tvb_find_guint8(tvb, sep_offset_prev, left, 0xfe);
if (sep_offset != -1)
sz_local = sep_offset - offset + 1;
else {
sz_local = left;
last = TRUE;
}
proto_tree_add_text(subtree, tvb, offset, sz_local + svsz,
"%.*s: %.*s", svsz - 1,
tvb_get_ephemeral_string(tvb, offset, svsz), sz_local - 1,
tvb_get_ephemeral_string(tvb, sep_offset_prev + 1, sz_local));
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
icqv5_cmd_ack(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + CMD_ACK_RANDOM, 4,
"Random: 0x%08x",
tvb_get_letohl(tvb, offset + CMD_ACK_RANDOM));
}
}
static void
icqv5_cmd_rand_search(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size)
{
guint16 group;
proto_tree* subtree;
proto_item* ti;
static const char* groups[] = {
"Name",
"General",
"Romance",
"Games",
"Students",
"20 Something",
"30 Something",
"40 Something",
"50 or worse",
"Man want women",
"Women want men"
};
if (tree){
if (size < 4) {
proto_tree_add_text(tree, tvb, offset, size,
"Body (%d bytes, should be 4)", size);
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
group = tvb_get_letohs(tvb, offset + CMD_RAND_SEARCH_GROUP);
if (group>0 && (group<=sizeof(groups)/sizeof(const char*)))
proto_tree_add_text(subtree, tvb, offset + CMD_RAND_SEARCH_GROUP,
4, "Group: (%u) %s", group, groups[group-1]);
else
proto_tree_add_text(subtree, tvb, offset + CMD_RAND_SEARCH_GROUP,
4, "Group: (%u)", group);
}
}
static void
icqv5_cmd_ack_messages(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + CMD_ACK_MESSAGES_RANDOM,
4, "Random: 0x%08x",
tvb_get_letohl(tvb, offset + CMD_ACK_MESSAGES_RANDOM));
}
}
static void
icqv5_cmd_keep_alive(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
guint32 randomx;
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
randomx = tvb_get_letohl(tvb, offset + CMD_KEEP_ALIVE_RANDOM);
proto_tree_add_text(subtree, tvb, offset + CMD_KEEP_ALIVE_RANDOM,
4, "Random: 0x%08x", randomx);
}
}
static void
icqv5_cmd_send_text_code(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size)
{
proto_tree* subtree = NULL;
proto_item* ti = NULL;
guint16 len;
guint16 x1;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
}
len = tvb_get_letohs(tvb, offset+CMD_SEND_TEXT_CODE_LEN);
if (tree){
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + CMD_SEND_TEXT_CODE_LEN,
2, "Length: %d", len);
}
if (len>0) {
if (tree){
proto_tree_add_text(subtree, tvb, offset + CMD_SEND_TEXT_CODE_TEXT,
len, "Text: %.*s", len,
tvb_get_ephemeral_string(tvb, offset + CMD_SEND_TEXT_CODE_TEXT,
len));
}
}
x1 = tvb_get_letohs(tvb, offset + CMD_SEND_TEXT_CODE_TEXT + len);
if (tree){
proto_tree_add_text(subtree, tvb,
offset + CMD_SEND_TEXT_CODE_TEXT + len,
2, "X1: 0x%04x", x1);
}
}
static void
icqv5_cmd_add_to_list(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
guint32 uin;
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
uin = tvb_get_letohl(tvb, offset + CMD_ADD_TO_LIST);
proto_tree_add_text(subtree, tvb, offset + CMD_ADD_TO_LIST_UIN, 4,
"UIN: %u", uin);
}
}
static void
icqv5_cmd_status_change(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
guint32 status;
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
status = tvb_get_letohl(tvb, offset + CMD_STATUS_CHANGE_STATUS);
proto_tree_add_text(subtree, tvb, offset + CMD_STATUS_CHANGE_STATUS,
4, "Status: %s", findStatus(status));
}
}
static void
icqv5_cmd_send_msg(proto_tree* tree, tvbuff_t *tvb, int offset, int size,
packet_info *pinfo)
{
proto_tree* subtree;
proto_item* ti;
int left = size;
if (tree) {
if (size < 4) {
proto_tree_add_text(tree, tvb, offset, size,
"Body (%d bytes, should be >= 4)", size);
return;
}
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + CMD_SEND_MSG_RECV_UIN, 4,
"Receiver UIN: %u",
tvb_get_letohl(tvb, offset + CMD_SEND_MSG_RECV_UIN));
left -= 4;
icqv5_decode_msgType(subtree, tvb, offset + CMD_SEND_MSG_MSG_TYPE,
left, pinfo);
}
}
static void
icqv5_cmd_login(proto_tree* tree, tvbuff_t *tvb, int offset, int size)
{
proto_item* ti;
proto_tree* subtree;
time_t theTime;
char *aTime;
guint32 port;
guint32 passwdLen;
guint32 status;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
theTime = tvb_get_letohl(tvb, offset + CMD_LOGIN_TIME);
aTime = abs_time_secs_to_str(theTime, ABSOLUTE_TIME_LOCAL, TRUE);
proto_tree_add_text(subtree, tvb, offset + CMD_LOGIN_TIME, 4,
"Time: %ld = %s", (long)theTime, aTime);
port = tvb_get_letohl(tvb, offset + CMD_LOGIN_PORT);
proto_tree_add_text(subtree, tvb, offset + CMD_LOGIN_PORT, 4,
"Port: %u", port);
passwdLen = tvb_get_letohs(tvb, offset + CMD_LOGIN_PASSLEN);
proto_tree_add_text(subtree, tvb, offset + CMD_LOGIN_PASSLEN,
2 + passwdLen, "Passwd: %.*s", (int)passwdLen,
tvb_get_ephemeral_string(tvb, offset + CMD_LOGIN_PASSWD,
passwdLen));
proto_tree_add_text(subtree, tvb,
offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_IP,
4, "IP: %s", tvb_ip_to_str(tvb, offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_IP));
status = tvb_get_letohs(tvb,
offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_STATUS);
proto_tree_add_text(subtree, tvb,
offset + CMD_LOGIN_PASSWD + passwdLen + CMD_LOGIN_STATUS,
4, "Status: %s", findStatus(status));
}
}
static void
icqv5_cmd_contact_list(proto_tree* tree, tvbuff_t *tvb, int offset, int size)
{
proto_tree* subtree;
proto_item* ti;
unsigned char num;
int i;
guint32 uin;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
num = tvb_get_guint8(tvb, offset + CMD_CONTACT_LIST_NUM);
proto_tree_add_text(subtree, tvb, offset + CMD_CONTACT_LIST,
1, "Number of uins: %u", num);
offset += (CMD_CONTACT_LIST_NUM + 1);
for (i = 0; i < num; i++) {
uin = tvb_get_letohl(tvb, offset);
proto_tree_add_text(subtree, tvb, offset, 4,
"UIN[%d]: %u", i ,uin);
offset += 4;
}
}
}
static void
icqv5_cmd_no_params(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 0, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset, 0, "No parameters");
}
}
static void
icqv5_srv_no_params(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
proto_tree* subtree;
proto_item* ti;
if (tree){
ti = proto_tree_add_text(tree, tvb, offset, 0, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset, 0, "No Parameters");
}
}
static void
icqv5_srv_login_reply(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size)
{
proto_tree* subtree;
proto_item* ti;
if (tree) {
if (size < SRV_LOGIN_REPLY_IP + 8) {
proto_tree_add_text(tree, tvb, offset, size,
"Body (%d bytes, should be %d)", size,
SRV_LOGIN_REPLY_IP + 8);
return;
}
ti = proto_tree_add_text(tree, tvb, offset, SRV_LOGIN_REPLY_IP + 8,
"Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + SRV_LOGIN_REPLY_IP, 4,
"IP: %s", tvb_ip_to_str(tvb, offset + SRV_LOGIN_REPLY_IP));
}
}
static void
icqv5_srv_user_online(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size)
{
proto_tree* subtree;
proto_item* ti;
guint32 status;
if (tree) {
if (size < SRV_LOGIN_REPLY_IP + 8) {
proto_tree_add_text(tree, tvb, offset, size,
"Body (%d bytes, should be %d)", size,
SRV_LOGIN_REPLY_IP + 8);
return;
}
ti = proto_tree_add_text(tree, tvb, offset, SRV_LOGIN_REPLY_IP + 8,
"Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_UIN, 4,
"UIN: %u",
tvb_get_letohl(tvb, offset + SRV_USER_ONL_UIN));
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_IP, 4,
"IP: %s", tvb_ip_to_str(tvb, offset + SRV_USER_ONL_IP));
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_PORT, 4,
"Port: %u",
tvb_get_letohl(tvb, offset + SRV_USER_ONL_PORT));
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_REALIP, 4,
"RealIP: %s", tvb_ip_to_str(tvb, offset + SRV_USER_ONL_REALIP));
status = tvb_get_letohs(tvb, offset + SRV_USER_ONL_STATUS);
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_STATUS, 2,
"Status: %s", findStatus(status));
proto_tree_add_text(subtree, tvb, offset + SRV_USER_ONL_X2, 4,
"Version: %08x",
tvb_get_letohl(tvb, offset + SRV_USER_ONL_X2));
}
}
static void
icqv5_srv_user_offline(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size)
{
proto_tree* subtree;
proto_item* ti;
if (tree) {
if (size < SRV_USER_OFFLINE_UIN + 4) {
proto_tree_add_text(tree, tvb, offset, size,
"Body (%d bytes, should be %d)", size,
SRV_USER_OFFLINE_UIN + 4);
return;
}
ti = proto_tree_add_text(tree, tvb, offset, SRV_USER_OFFLINE_UIN + 4,
"Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_text(subtree, tvb, offset + SRV_USER_OFFLINE_UIN, 4,
"UIN: %u",
tvb_get_letohl(tvb, offset + SRV_USER_OFFLINE));
}
}
static void
icqv5_srv_multi(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size,
packet_info* pinfo)
{
proto_tree* subtree;
proto_item* ti;
guint8 num;
guint16 pktSz;
int i;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
num = tvb_get_guint8(tvb, offset + SRV_MULTI_NUM);
proto_tree_add_text(subtree, tvb, offset + SRV_MULTI_NUM, 1,
"Number of pkts: %u", num);
offset += (SRV_MULTI_NUM + 1);
for (i = 0; i < num; i++) {
pktSz = tvb_get_letohs(tvb, offset);
offset += 2;
dissect_icqv5Server(tvb, offset, pinfo, subtree, pktSz);
offset += pktSz;
}
}
}
static void
icqv5_srv_meta_user(proto_tree* tree,
tvbuff_t *tvb,
int offset,
int size _U_,
packet_info *pinfo)
{
#if 0
proto_tree* subtree = NULL;
#endif
proto_tree* sstree = NULL;
proto_item* ti = NULL;
guint16 subcmd;
unsigned char result;
if (tree) {
#if 0
ti = proto_tree_add_text(tree, tvb, offset, size, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
subcmd = tvb_get_letohs(tvb, offset + SRV_META_USER_SUBCMD);
ti = proto_tree_add_text(subtree, tvb, offset + SRV_META_USER_SUBCMD,
2, "%s", findSubCmd(subcmd));
result = tvb_get_guint8(tvb, offset + SRV_META_USER_RESULT);
proto_tree_add_text(subtree, tvb, offset + SRV_META_USER_RESULT, 1,
"%s", (result==0x0a)?"Success":"Failure");
sstree = proto_item_add_subtree(ti, ett_icq_body_parts);
#else
subcmd = tvb_get_letohs(tvb, offset + SRV_META_USER_SUBCMD);
ti = proto_tree_add_text(tree, tvb, offset + SRV_META_USER_SUBCMD,
2, "%s", findSubCmd(subcmd));
sstree = proto_item_add_subtree(ti, ett_icq_body_parts);
result = tvb_get_guint8(tvb, offset + SRV_META_USER_RESULT);
proto_tree_add_text(sstree, tvb, offset + SRV_META_USER_RESULT,
1, "%s", (result==0x0a)?"Success":"Failure");
#endif
offset += 3;
switch(subcmd) {
case META_EX_USER_FOUND:
{
guint16 pktLen;
pktLen = tvb_get_letohs(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint16),
"Length: %u", pktLen);
offset += (int)sizeof(guint16);
}
case META_USER_FOUND:
{
int len = 0;
const char *descr[] = {
"Nick",
"First name",
"Last name",
"Email",
NULL};
const char** d = descr;
unsigned char auth;
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint32),
"UIN: %u", tvb_get_letohl(tvb, offset));
offset+=(int)sizeof(guint32);
for ( ; *d!=NULL; d++) {
len = proto_add_icq_attr(sstree, tvb, offset, *d);
if (len == -1)
return;
offset += len;
}
auth = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, 1,
"authorization: %s", (auth==0x01)?"Necessary":"Who needs it");
offset++;
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint16),
"x2: 0x%04x", tvb_get_letohs(tvb, offset));
offset+=(int)sizeof(guint16);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint32),
"x3: 0x%08x", tvb_get_letohl(tvb, offset));
break;
}
case META_ABOUT:
{
int len;
len = tvb_get_letohs(tvb, offset);
offset+=(int)sizeof(guint16);
proto_tree_add_text(sstree, tvb, offset - (int)sizeof(guint16),
(int)sizeof(guint16)+len, "About(%d): %.*s", len,
len, tvb_get_ephemeral_string(tvb, offset, len));
break;
}
case META_USER_INFO:
{
static const char* descr[] = {
"Nick",
"First name",
"Last name",
"Primary email",
"Secondary email",
"Old email",
"City",
"State",
"Phone",
"Fax",
"Street",
"Cellphone",
"Zip",
NULL};
const char** d = descr;
guint16 country;
guint8 user_timezone;
guint8 auth;
int len = 0;
#if 0
uin = tvb_get_letohl(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint32),
"UIN: %u", uin);
offset+=(int)sizeof(guint32);
#endif
while ((*d)!=NULL) {
len = tvb_get_letohs(tvb, offset);
offset+=(int)sizeof(guint16);
if (len>0) {
proto_tree_add_text(sstree, tvb, offset - (int)sizeof(guint16),
(int)sizeof(guint16)+len, "%s(%d): %.*s",
*d, len, len - 1,
tvb_get_ephemeral_string(tvb, offset, len - 1));
offset+=len;
}
d++;
}
country = tvb_get_letohs(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(guint16),
"Countrycode: %u", country);
offset+=(int)sizeof(guint16);
user_timezone = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(unsigned char),
"Timezone: %u", user_timezone);
offset++;
auth = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(unsigned char),
"Authorization: (%u) %s", auth,
(auth==0)?"No":"Yes");
offset++;
auth = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(unsigned char),
"Webaware: (%u) %s", auth,
(auth==0)?"No":"Yes");
offset++;
auth = tvb_get_guint8(tvb, offset);
proto_tree_add_text(sstree, tvb, offset, (int)sizeof(unsigned char),
"HideIP: (%u) %s", auth, (auth==0)?"No":"Yes");
break;
}
default:
expert_add_info_format(pinfo, NULL, PI_UNDECODED, PI_WARN,
"Meta subcmd: 0x%x", subcmd);
break;
}
}
}
static void
icqv5_srv_recv_message(proto_tree* tree,
tvbuff_t* tvb,
int offset,
int size,
packet_info *pinfo)
{
proto_tree* subtree = NULL;
proto_item* ti = NULL;
int left = size;
guint16 year;
guint8 month;
guint8 day;
guint8 hour;
guint8 minute;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 4, "Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
proto_tree_add_item(subtree, hf_icq_uin, tvb, offset + SRV_RECV_MSG_UIN,
(int)sizeof(guint32), ENC_LITTLE_ENDIAN);
year = tvb_get_letohs(tvb, offset + SRV_RECV_MSG_YEAR);
month = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_MONTH);
day = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_DAY);
hour = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_HOUR);
minute = tvb_get_guint8(tvb, offset + SRV_RECV_MSG_MINUTE);
proto_tree_add_text(subtree, tvb, offset + SRV_RECV_MSG_YEAR,
(int)sizeof(guint16) + 4*(int)sizeof(unsigned char),
"Time: %u-%u-%u %02u:%02u",
day, month, year, hour, minute);
icqv5_decode_msgType(subtree, tvb, offset + SRV_RECV_MSG_MSG_TYPE,
left, pinfo);
}
}
static void
icqv5_srv_rand_user(proto_tree* tree,
tvbuff_t *tvb,
int offset)
{
proto_tree* subtree = NULL;
proto_item* ti = NULL;
guint32 uin;
guint32 port;
guint8 commClass;
guint32 status;
guint16 tcpVer;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, SRV_RAND_USER_TCP_VER + 2,
"Body");
subtree = proto_item_add_subtree(ti, ett_icq_body);
uin = tvb_get_letohl(tvb, offset + SRV_RAND_USER_UIN);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_UIN,
(int)sizeof(guint32), "UIN: %u", uin);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_IP,
(int)sizeof(guint32), "IP: %s", tvb_ip_to_str(tvb, offset + SRV_RAND_USER_IP));
port = tvb_get_letohs(tvb, offset + SRV_RAND_USER_PORT);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_UIN,
(int)sizeof(guint32), "Port: %u", port);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_REAL_IP,
(int)sizeof(guint32), "RealIP: %s", tvb_ip_to_str(tvb, offset + SRV_RAND_USER_REAL_IP));
commClass = tvb_get_guint8(tvb, offset + SRV_RAND_USER_CLASS);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_CLASS,
(int)sizeof(guint8), "Class: %s",
(commClass!=4)?"User to User":"Through Server");
status = tvb_get_letohs(tvb, offset + SRV_RAND_USER_STATUS);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_STATUS,
(int)sizeof(guint32), "Status: %s", findStatus(status));
tcpVer = tvb_get_letohs(tvb, offset + SRV_RAND_USER_TCP_VER);
proto_tree_add_text(subtree, tvb, offset + SRV_RAND_USER_TCP_VER,
(int)sizeof(guint16), "TCPVersion: %u", tcpVer);
}
}
static void
dissect_icqv5Client(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icq_tree = NULL;
proto_tree *icq_header_tree = NULL;
proto_item *ti = NULL;
int pktsize;
int capturedsize;
guint32 rounded_size;
guint32 key;
guint16 cmd;
guint8 *decr_pd;
tvbuff_t *decr_tvb;
pktsize = tvb_reported_length(tvb);
capturedsize = tvb_length(tvb);
key = get_v5key(tvb, pktsize);
rounded_size = ((((capturedsize - ICQ5_CL_SESSIONID) + 3)/4)*4) + ICQ5_CL_SESSIONID;
decr_pd = (guint8 *)g_malloc(rounded_size);
tvb_memcpy(tvb, decr_pd, 0, capturedsize);
decrypt_v5(decr_pd, rounded_size, key);
decr_tvb = tvb_new_child_real_data(tvb, decr_pd, capturedsize, pktsize);
tvb_set_free_cb(decr_tvb, g_free);
add_new_data_source(pinfo, decr_tvb, "Decrypted");
cmd = tvb_get_letohs(decr_tvb, ICQ5_CL_CMD);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "ICQv5 %s", findClientCmd(cmd));
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, 0, -1,
"ICQv5 %s (len %u)",
findClientCmd(cmd), pktsize);
icq_tree = proto_item_add_subtree(ti, ett_icq);
ti = proto_tree_add_uint_format(icq_tree, hf_icq_type, tvb, 0,
ICQ5_CL_HDRSIZE, ICQ5_client, "Header");
icq_header_tree = proto_item_add_subtree(ti, ett_icq_header);
proto_tree_add_text(icq_header_tree, tvb, ICQ_VERSION, 2, "Version: %u",
tvb_get_letohs(tvb, ICQ_VERSION));
proto_tree_add_item(icq_header_tree, hf_icq_uin, tvb, ICQ5_CL_UIN, 4,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_sessionid, decr_tvb,
ICQ5_CL_SESSIONID, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format(icq_header_tree, hf_icq_client_cmd,
decr_tvb, ICQ5_CL_CMD, 2, cmd,
"Command: %s (%u)",
val_to_str_const(cmd, clientCmdCode, "Unknown"), cmd);
proto_tree_add_text(icq_header_tree, decr_tvb, ICQ5_CL_SEQNUM1, 2,
"Seq Number 1: 0x%04x",
tvb_get_letohs(decr_tvb, ICQ5_CL_SEQNUM1));
proto_tree_add_text(icq_header_tree, decr_tvb, ICQ5_CL_SEQNUM2, 2,
"Seq Number 2: 0x%04x",
tvb_get_letohs(decr_tvb, ICQ5_CL_SEQNUM2));
proto_tree_add_uint_format(icq_header_tree, hf_icq_checkcode, tvb,
ICQ5_CL_CHECKCODE, 4, key, "Key: 0x%08x",
key);
switch(cmd) {
case CMD_ACK:
icqv5_cmd_ack(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_SEND_MSG:
case CMD_MSG_TO_NEW_USER:
icqv5_cmd_send_msg(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE, pinfo);
break;
case CMD_RAND_SEARCH:
icqv5_cmd_rand_search(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE);
break;
case CMD_LOGIN:
icqv5_cmd_login(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE);
break;
case CMD_SEND_TEXT_CODE:
icqv5_cmd_send_text_code(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE);
break;
case CMD_STATUS_CHANGE:
icqv5_cmd_status_change(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_ACK_MESSAGES:
icqv5_cmd_ack_messages(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_KEEP_ALIVE:
icqv5_cmd_keep_alive(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_ADD_TO_LIST:
icqv5_cmd_add_to_list(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
case CMD_CONTACT_LIST:
icqv5_cmd_contact_list(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE);
break;
case CMD_META_USER:
case CMD_REG_NEW_USER:
case CMD_QUERY_SERVERS:
case CMD_QUERY_ADDONS:
icqv5_cmd_no_params(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE);
break;
default:
proto_tree_add_text(icq_tree, decr_tvb, ICQ5_CL_HDRSIZE,
pktsize - ICQ5_CL_HDRSIZE, "Body");
expert_add_info_format(pinfo, NULL, PI_UNDECODED, PI_WARN,
"Missing: %s", findClientCmd(cmd));
break;
}
}
}
static void
dissect_icqv5Server(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int pktsize)
{
proto_tree *icq_tree = NULL;
proto_tree *icq_header_tree = NULL;
proto_item *ti = NULL;
int changeCol = (pktsize==-1);
guint16 cmd;
cmd = tvb_get_letohs(tvb, offset + ICQ5_SRV_CMD);
if (changeCol && check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "ICQv5 %s", findServerCmd(cmd));
if (pktsize == -1)
pktsize = tvb_reported_length(tvb);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_icq, tvb, offset,
pktsize, "ICQv5 %s (len %u)",
findServerCmd(cmd), pktsize);
icq_tree = proto_item_add_subtree(ti, ett_icq);
ti = proto_tree_add_uint_format(icq_tree, hf_icq_type, tvb, offset,
ICQ5_SRV_HDRSIZE, ICQ5_server,
"Header");
icq_header_tree = proto_item_add_subtree(ti, ett_icq_header);
proto_tree_add_text(icq_header_tree, tvb, offset + ICQ_VERSION, 2,
"Version: %u", tvb_get_letohs(tvb, ICQ_VERSION));
proto_tree_add_item(icq_header_tree, hf_icq_sessionid, tvb,
offset + ICQ5_SRV_SESSIONID, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format(icq_header_tree, hf_icq_server_cmd, tvb,
offset + ICQ5_SRV_CMD, 2, cmd, "Command: %s (%u)",
val_to_str_const(cmd, serverCmdCode, "Unknown"), cmd);
proto_tree_add_text(icq_header_tree, tvb, offset + ICQ5_SRV_SEQNUM1, 2,
"Seq Number 1: 0x%04x",
tvb_get_letohs(tvb, offset + ICQ5_SRV_SEQNUM1));
proto_tree_add_text(icq_header_tree, tvb, offset + ICQ5_SRV_SEQNUM2, 2,
"Seq Number 2: 0x%04x",
tvb_get_letohs(tvb, offset + ICQ5_SRV_SEQNUM2));
proto_tree_add_item(icq_header_tree, hf_icq_uin, tvb,
offset + ICQ5_SRV_UIN, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(icq_header_tree, hf_icq_checkcode, tvb,
offset + ICQ5_SRV_CHECKCODE, 4, ENC_LITTLE_ENDIAN);
switch (cmd) {
case SRV_RAND_USER:
icqv5_srv_rand_user(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE);
break;
case SRV_SYS_DELIVERED_MESS:
icqv5_cmd_send_msg(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_USER_ONLINE:
icqv5_srv_user_online(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE);
break;
case SRV_USER_OFFLINE:
icqv5_srv_user_offline(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE);
break;
case SRV_LOGIN_REPLY:
icqv5_srv_login_reply(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE);
break;
case SRV_META_USER:
icqv5_srv_meta_user(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_RECV_MESSAGE:
icqv5_srv_recv_message(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_MULTI:
icqv5_srv_multi(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, pinfo);
break;
case SRV_ACK:
case SRV_SILENT_TOO_LONG:
case SRV_GO_AWAY:
case SRV_NEW_UIN:
case SRV_BAD_PASS:
case SRV_UPDATE_SUCCESS:
icqv5_srv_no_params(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE);
break;
default:
proto_tree_add_text(icq_tree, tvb, offset + ICQ5_SRV_HDRSIZE,
pktsize - ICQ5_SRV_HDRSIZE, "Body");
expert_add_info_format(pinfo, NULL, PI_UNDECODED, PI_WARN,
"Missing: %s", findClientCmd(cmd));
break;
}
}
}
static void dissect_icqv5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 unknown;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICQv5 (UDP)");
col_set_str(pinfo->cinfo, COL_INFO, "ICQv5 packet");
unknown = tvb_get_letohl(tvb, ICQ5_UNKNOWN);
if (unknown == 0x0L) {
dissect_icqv5Client(tvb, pinfo, tree);
} else {
dissect_icqv5Server(tvb, 0, pinfo, tree, -1);
}
}
static int
dissect_icq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int version;
version = tvb_get_letohs(tvb, ICQ_VERSION);
if (version < 2 || version > 5)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICQ");
col_clear(pinfo->cinfo, COL_INFO);
version = tvb_get_letohs(tvb, ICQ_VERSION);
switch (version) {
case 0x0005:
dissect_icqv5(tvb, pinfo, tree);
break;
case 0x0004:
dissect_icqv4(tvb, pinfo, tree);
break;
case 0x0003:
dissect_icqv3(tvb, pinfo, tree);
break;
case 0x0002:
dissect_icqv2(tvb, pinfo, tree);
break;
default:
expert_add_info_format(pinfo, NULL, PI_UNDECODED, PI_WARN,
"Unknown version (0x%x)", version);
break;
}
return (tvb_length(tvb));
}
void
proto_register_icq(void)
{
static hf_register_info hf[] = {
{ &hf_icq_type,
{"Type", "icq.type", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_uin,
{"UIN", "icq.uin", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_sessionid,
{"Session ID", "icq.sessionid", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_icq_client_cmd,
{"Client command", "icq.client_cmd", FT_UINT16, BASE_HEX, VALS(clientCmdCode), 0x0, NULL, HFILL }},
{ &hf_icq_server_cmd,
{"Server command", "icq.server_cmd", FT_UINT16, BASE_DEC, VALS(serverCmdCode), 0x0, NULL, HFILL }},
{ &hf_icq_checkcode,
{"Checkcode", "icq.checkcode", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_icq_decode,
{"Decode", "icq.decode", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }}
#endif
};
static gint *ett[] = {
&ett_icq,
&ett_icq_header,
&ett_icq_decode,
&ett_icq_body,
&ett_icq_body_parts,
};
proto_icq = proto_register_protocol("ICQ Protocol", "ICQ", "icq");
proto_register_field_array(proto_icq, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_icq(void)
{
dissector_handle_t icq_handle;
icq_handle = new_create_dissector_handle(dissect_icq, proto_icq);
dissector_add_uint("udp.port", UDP_PORT_ICQ, icq_handle);
}
