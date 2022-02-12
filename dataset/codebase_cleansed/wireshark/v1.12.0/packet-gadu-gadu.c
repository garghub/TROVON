static struct gadu_gadu_conv_data *
gadu_gadu_create_conversation(packet_info *pinfo, guint32 uin)
{
conversation_t *conv;
struct gadu_gadu_conv_data *gg_conv;
conv = find_or_create_conversation(pinfo);
gg_conv = (struct gadu_gadu_conv_data *)conversation_get_proto_data(conv, hfi_gadu_gadu->id);
if (!gg_conv) {
gg_conv = wmem_new(wmem_file_scope(), struct gadu_gadu_conv_data);
gg_conv->uin = uin;
conversation_add_proto_data(conv, hfi_gadu_gadu->id, gg_conv);
}
return gg_conv;
}
static struct gadu_gadu_conv_data *
gadu_gadu_get_conversation_data(packet_info *pinfo)
{
conversation_t *conv;
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conv)
return (struct gadu_gadu_conv_data *)conversation_get_proto_data(conv, hfi_gadu_gadu->id);
return NULL;
}
static gboolean
gadu_gadu_status_has_descr(int status)
{
return
(status == GG_STATUS_NOT_AVAIL_DESCR) ||
(status == GG_STATUS_FFC_DESCR) ||
(status == GG_STATUS_AVAIL_DESCR) ||
(status == GG_STATUS_BUSY_DESCR) ||
(status == GG_STATUS_DND_DESCR) ||
(status == GG_STATUS_INVISIBLE_DESCR);
}
static int
gadu_gadu_strsize(tvbuff_t *tvb, const gint abs_offset)
{
int nul_offset;
nul_offset = tvb_find_guint8(tvb, abs_offset, -1, 0);
if (nul_offset == -1)
nul_offset = tvb_length(tvb) - 1;
return (nul_offset - abs_offset) + 1;
}
static int
dissect_gadu_gadu_stringz_cp1250(tvbuff_t *tvb, header_field_info *hfi, proto_tree *tree, const int offset)
{
int len = gadu_gadu_strsize(tvb, offset);
proto_tree_add_item(tree, hfi, tvb, offset, len, ENC_WINDOWS_1250 | ENC_NA);
return offset + len;
}
static int
dissect_gadu_gadu_uint32_string_utf8(tvbuff_t *tvb, header_field_info *hfi, proto_tree *tree, int offset)
{
const int org_offset = offset;
guint32 len;
len = tvb_get_letohl(tvb, offset);
offset += 4;
offset += len;
proto_tree_add_item(tree, hfi, tvb, org_offset, offset - org_offset, ENC_UTF_8 | ENC_NA);
return offset;
}
static int
dissect_gadu_gadu_disconnecting(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Disconnecting");
return offset;
}
static int
dissect_gadu_gadu_disconnect_ack(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Disconnect acknowledge (< 10.0)");
return offset;
}
static void *
_tvb_memcpy_reverse(tvbuff_t *tvb, void *target, gint offset, size_t length)
{
guint8 *t = (guint8 *) target;
while (length > 0) {
length--;
t[length] = tvb_get_guint8(tvb, offset);
offset++;
}
return target;
}
static int
dissect_gadu_gadu_login_protocol(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *ti;
guint32 protocol;
protocol = tvb_get_letohl(tvb, offset) & 0xff;
proto_tree_add_item(tree, &hfi_gadu_gadu_login_protocol, tvb, offset, 4, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_string(tree, &hfi_gadu_gadu_login_version, tvb, offset, 4, val_to_str(protocol, gadu_gadu_version_vals, "Unknown (0x%x)"));
PROTO_ITEM_SET_GENERATED(ti);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_login(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *ti;
guint32 uin;
guint8 hash[4];
col_set_str(pinfo->cinfo, COL_INFO, "Login request (< 6.0)");
uin = tvb_get_letohl(tvb, offset);
gadu_gadu_create_conversation(pinfo, uin);
proto_tree_add_uint(tree, &hfi_gadu_gadu_login_uin, tvb, offset, 4, uin);
offset += 4;
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_login_hash_type, tvb, 0, 0, GG_LOGIN_HASH_GG32);
PROTO_ITEM_SET_GENERATED(ti);
_tvb_memcpy_reverse(tvb, hash, offset, 4);
proto_tree_add_bytes_format_value(tree, hfi_gadu_gadu_login_hash.id, tvb, offset, 4, hash, "0x%.8x", tvb_get_letohl(tvb, offset));
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_login_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_gadu_gadu_login_protocol(tvb, tree, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_login_local_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_login_local_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_gadu_gadu_login_hash(tvbuff_t *tvb, proto_tree *tree, int offset)
{
guint8 hash_type;
guint8 hash[4];
int i;
hash_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_login_hash_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (hash_type) {
case GG_LOGIN_HASH_GG32:
_tvb_memcpy_reverse(tvb, hash, offset, 4);
proto_tree_add_bytes_format_value(tree, hfi_gadu_gadu_login_hash.id, tvb, offset, 4, hash, "0x%.8x", tvb_get_letohl(tvb, offset));
for (i = 4; i < 64; i++) {
if (tvb_get_guint8(tvb, offset+i)) {
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset + 4, 64-4, ENC_NA);
break;
}
}
break;
case GG_LOGIN_HASH_SHA1:
proto_tree_add_item(tree, &hfi_gadu_gadu_login_hash, tvb, offset, 20, ENC_NA);
for (i = 20; i < 64; i++) {
if (tvb_get_guint8(tvb, offset+i)) {
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset + 20, 64-20, ENC_NA);
break;
}
}
break;
default:
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 64, ENC_NA);
break;
}
offset += 64;
return offset;
}
static int
dissect_gadu_gadu_login70(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 uin;
col_set_str(pinfo->cinfo, COL_INFO, "Login request (7.0)");
uin = tvb_get_letohl(tvb, offset) & ~(GG_ERA_OMNIX_MASK | GG_HAS_AUDIO_MASK);
gadu_gadu_create_conversation(pinfo, uin);
proto_tree_add_uint(tree, &hfi_gadu_gadu_login_uin, tvb, offset, 4, uin);
offset += 4;
offset = dissect_gadu_gadu_login_hash(tvb, tree, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_login_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_gadu_gadu_login_protocol(tvb, tree, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_login_local_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_login_local_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_gadu_gadu_login80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 uin;
col_set_str(pinfo->cinfo, COL_INFO, "Login request (8.0)");
uin = tvb_get_letohl(tvb, offset);
gadu_gadu_create_conversation(pinfo, uin);
proto_tree_add_item(tree, &hfi_gadu_gadu_login_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_login80_lang, tvb, offset, 2, ENC_ASCII | ENC_NA);
offset += 2;
offset = dissect_gadu_gadu_login_hash(tvb, tree, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_login_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_login_ok(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Login success (< 8.0)");
return offset;
}
static int
dissect_gadu_gadu_login_failed(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Login fail (< 8.0)");
return offset;
}
static int
dissect_gadu_gadu_login_ok80(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Login success (8.0)");
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_login80_failed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Login fail (8.0)");
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_user_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 users_num;
col_set_str(pinfo->cinfo, COL_INFO, "Contact details");
offset += 4;
users_num = tvb_get_letohl(tvb, offset);
offset += 4;
while (users_num--) {
guint32 attr_num;
proto_tree_add_item(tree, &hfi_gadu_gadu_userdata_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
attr_num = tvb_get_letohl(tvb, offset);
offset += 4;
while (attr_num--) {
guint32 name_size, val_size;
char *name, *val;
name_size = tvb_get_letohl(tvb, offset);
offset += 4;
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, name_size, ENC_ASCII | ENC_NA);
proto_tree_add_string(tree, &hfi_gadu_gadu_userdata_attr_name, tvb, offset - 4, 4 + name_size, name);
offset += name_size;
proto_tree_add_item(tree, &hfi_gadu_gadu_userdata_attr_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
val_size = tvb_get_letohl(tvb, offset);
offset += 4;
val = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, val_size, ENC_ASCII | ENC_NA);
proto_tree_add_string(tree, &hfi_gadu_gadu_userdata_attr_value, tvb, offset - 4, 4 + val_size, val);
offset += val_size;
}
}
return offset;
}
static int
dissect_gadu_gadu_typing_notify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Typing notify");
proto_tree_add_item(tree, &hfi_gadu_gadu_typing_notify_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, &hfi_gadu_gadu_typing_notify_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_msg_attr(tvbuff_t *tvb _U_, proto_tree *tree _U_, int offset)
{
return offset;
}
static int
dissect_gadu_gadu_recv_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
struct gadu_gadu_conv_data *conv;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Receive message (< 8.0)");
if ((conv = gadu_gadu_get_conversation_data(pinfo))) {
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_recipient, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_uin, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
ti = proto_tree_add_item(tree, &hfi_gadu_gadu_msg_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_sender, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_gadu_gadu_stringz_cp1250(tvb, &hfi_gadu_gadu_msg_text, tree, offset);
offset = dissect_gadu_gadu_msg_attr(tvb, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_send_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
struct gadu_gadu_conv_data *conv;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Send message (< 8.0)");
ti = proto_tree_add_item(tree, &hfi_gadu_gadu_msg_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_recipient, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if ((conv = gadu_gadu_get_conversation_data(pinfo))) {
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_sender, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_uin, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_time(tree, &hfi_gadu_gadu_msg_time, tvb, 0, 0, &(pinfo->fd->abs_ts));
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_gadu_gadu_stringz_cp1250(tvb, &hfi_gadu_gadu_msg_text, tree, offset);
offset = dissect_gadu_gadu_msg_attr(tvb, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_recv_msg80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
struct gadu_gadu_conv_data *conv;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Receive message (8.0)");
if ((conv = gadu_gadu_get_conversation_data(pinfo))) {
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_recipient, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_uin, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
ti = proto_tree_add_item(tree, &hfi_gadu_gadu_msg_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_sender, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg80_offset_plain, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg80_offset_attr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_send_msg80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
struct gadu_gadu_conv_data *conv;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Send message (8.0)");
ti = proto_tree_add_item(tree, &hfi_gadu_gadu_msg_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_recipient, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if ((conv = gadu_gadu_get_conversation_data(pinfo))) {
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_sender, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_msg_uin, tvb, 0, 0, conv->uin);
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_time(tree, &hfi_gadu_gadu_msg_time, tvb, 0, 0, &(pinfo->fd->abs_ts));
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_class, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg80_offset_plain, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg80_offset_attr, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_send_msg_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Message acknowledge (server)");
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_ack_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_ack_recipient, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_ack_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_recv_msg_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Message acknowledge (client)");
proto_tree_add_item(tree, &hfi_gadu_gadu_msg_ack_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_status60(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 uin;
guint8 status;
col_set_str(pinfo->cinfo, COL_INFO, "Receive status (6.0)");
uin = tvb_get_letohl(tvb, offset) & ~(GG_ERA_OMNIX_MASK | GG_HAS_AUDIO_MASK);
proto_tree_add_uint(tree, &hfi_gadu_gadu_status_uin, tvb, offset, 4, uin);
offset += 4;
status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_status_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_img_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
if (gadu_gadu_status_has_descr(status))
offset = dissect_gadu_gadu_stringz_cp1250(tvb, &hfi_gadu_gadu_status_descr, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_status77(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 uin;
guint8 status;
col_set_str(pinfo->cinfo, COL_INFO, "Receive status (7.7)");
uin = tvb_get_letohl(tvb, offset) & ~(GG_ERA_OMNIX_MASK | GG_HAS_AUDIO_MASK);
proto_tree_add_uint(tree, &hfi_gadu_gadu_status_uin, tvb, offset, 4, uin);
offset += 4;
status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_status_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_img_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
if (gadu_gadu_status_has_descr(status))
offset = dissect_gadu_gadu_stringz_cp1250(tvb, &hfi_gadu_gadu_status_descr, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_status80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Receive status (8.0)");
proto_tree_add_item(tree, &hfi_gadu_gadu_status_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, &hfi_gadu_gadu_status_img_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_gadu_gadu_uint32_string_utf8(tvb, &hfi_gadu_gadu_status_descr, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_notify_reply80(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Receive status list (8.0)");
return offset;
}
static int
dissect_gadu_gadu_new_status(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint32 status;
col_set_str(pinfo->cinfo, COL_INFO, "New status (< 8.0)");
status = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_new_status_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (gadu_gadu_status_has_descr(status & 0xff))
offset = dissect_gadu_gadu_stringz_cp1250(tvb, &hfi_gadu_gadu_status_descr, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_new_status80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "New status (8.0)");
proto_tree_add_item(tree, &hfi_gadu_gadu_new_status_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_gadu_gadu_uint32_string_utf8(tvb, &hfi_gadu_gadu_new_status_desc, tree, offset);
return offset;
}
static int
dissect_gadu_gadu_list_empty(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list (empty)");
return offset;
}
static int
dissect_gadu_gadu_add_notify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list add");
proto_tree_add_item(tree, &hfi_gadu_gadu_contact_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_contact_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_gadu_gadu_notify105_common(tvbuff_t *tvb, proto_tree *tree, int offset, char **puin)
{
guint16 uin_len;
char *uin;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
uin_len = tvb_get_guint8(tvb, offset);
offset += 1;
uin = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, uin_len, ENC_ASCII | ENC_NA);
proto_tree_add_string(tree, &hfi_gadu_gadu_contact_uin_str, tvb, offset - 1, 1 + uin_len, uin);
offset += uin_len;
if (puin)
*puin = uin;
proto_tree_add_item(tree, &hfi_gadu_gadu_contact_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_gadu_gadu_add_notify105(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list add (10.5)");
return dissect_gadu_gadu_notify105_common(tvb, tree, offset, NULL);
}
static int
dissect_gadu_gadu_remove_notify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list remove");
proto_tree_add_item(tree, &hfi_gadu_gadu_contact_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_gadu_gadu_contact_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_gadu_gadu_remove_notify105(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list remove (10.5)");
return dissect_gadu_gadu_notify105_common(tvb, tree, offset, NULL);
}
static int
dissect_gadu_gadu_notify_common(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *contact_tree;
proto_item *ti;
while (tvb_reported_length_remaining(tvb, offset) >= 4+1) {
guint32 uin = tvb_get_letohl(tvb, offset);
ti = proto_tree_add_text(tree, tvb, offset, 5, "Contact: %u", uin);
contact_tree = proto_item_add_subtree(ti, ett_gadu_gadu_contact);
proto_tree_add_item(contact_tree, &hfi_gadu_gadu_contact_uin, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(contact_tree, &hfi_gadu_gadu_contact_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
return offset;
}
static int
dissect_gadu_gadu_notify_first(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list");
return dissect_gadu_gadu_notify_common(tvb, pinfo, tree, offset);
}
static int
dissect_gadu_gadu_notify_last(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list (last)");
return dissect_gadu_gadu_notify_common(tvb, pinfo, tree, offset);
}
static int
dissect_gadu_gadu_notify105(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Notify list (10.5)");
while (tvb_reported_length_remaining(tvb, offset) >= 2) {
const int org_offset = offset;
proto_tree *contact_tree;
proto_item *ti;
char *uin;
ti = proto_tree_add_text(tree, tvb, offset, 0, "Contact: ");
contact_tree = proto_item_add_subtree(ti, ett_gadu_gadu_contact);
offset = dissect_gadu_gadu_notify105_common(tvb, contact_tree, offset, &uin);
proto_item_append_text(ti, "%s", uin);
proto_item_set_len(ti, offset - org_offset);
}
return offset;
}
static int
dissect_gadu_gadu_ping(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree _U_, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Ping");
return offset;
}
static int
dissect_gadu_gadu_welcome(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Welcome");
proto_tree_add_item(tree, &hfi_gadu_gadu_welcome_seed, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_userlist_xml_compressed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
int remain = tvb_reported_length_remaining(tvb, offset);
tvbuff_t *uncomp_tvb;
if (remain <= 0)
return offset;
if ((uncomp_tvb = tvb_child_uncompress(tvb, tvb, offset, remain))) {
proto_tree_add_text(tree, tvb, offset, remain, "Userlist XML data: [Decompression succeeded]");
add_new_data_source(pinfo, uncomp_tvb, "Uncompressed userlist");
call_dissector_only(xml_handle, uncomp_tvb, pinfo, tree, NULL);
} else
proto_tree_add_text(tree, tvb, offset, remain, "Userlist XML data: [Error: Decompression failed] (or no libz)");
offset += remain;
return offset;
}
static int
dissect_gadu_gadu_userlist_request80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 type;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "Userlist request (8.0)");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_request_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
ti = proto_tree_add_uint(tree, &hfi_gadu_gadu_userlist_format, tvb, 0, 0, GG_USERLIST100_FORMAT_TYPE_GG100);
PROTO_ITEM_SET_GENERATED(ti);
switch (type) {
case GG_USERLIST_PUT:
offset = dissect_gadu_gadu_userlist_xml_compressed(tvb, pinfo, tree, offset);
break;
}
return offset;
}
static int
dissect_gadu_gadu_userlist_request100(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 type, format;
col_set_str(pinfo->cinfo, COL_INFO, "Userlist request (10.0)");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_request_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
format = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
switch (type) {
case GG_USERLIST_PUT:
if (format == GG_USERLIST100_FORMAT_TYPE_GG100)
offset = dissect_gadu_gadu_userlist_xml_compressed(tvb, pinfo, tree, offset);
break;
}
return offset;
}
static int
dissect_gadu_gadu_userlist_reply80(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 type;
col_set_str(pinfo->cinfo, COL_INFO, "Userlist reply (8.0)");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_reply_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch (type) {
case GG_USERLIST_GET_REPLY:
offset = dissect_gadu_gadu_userlist_xml_compressed(tvb, pinfo, tree, offset);
break;
}
return offset;
}
static int
dissect_gadu_gadu_userlist_reply100(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
guint8 type, format;
col_set_str(pinfo->cinfo, COL_INFO, "Userlist reply (10.0)");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_reply_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
format = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_format, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_data, tvb, offset, 1, ENC_NA);
offset += 1;
switch (type) {
case GG_USERLIST_GET_REPLY:
if (format == GG_USERLIST100_FORMAT_TYPE_GG100)
offset = dissect_gadu_gadu_userlist_xml_compressed(tvb, pinfo, tree, offset);
break;
}
return offset;
}
static int
dissect_gadu_gadu_userlist_version100(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Userlist version (10.0)");
proto_tree_add_item(tree, &hfi_gadu_gadu_userlist_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_dcc7_id_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Direct connection id request");
proto_tree_add_item(tree, &hfi_dcc_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_dcc7_id_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Direct connection id reply");
proto_tree_add_item(tree, &hfi_dcc_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_dcc_id, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
static int
dissect_gadu_gadu_dcc7_new(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Direct connection new");
proto_tree_add_item(tree, &hfi_dcc_id, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, &hfi_dcc_uin_from, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_dcc_uin_to, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_dcc_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_dcc_filename, tvb, offset, 255, ENC_ASCII | ENC_NA);
offset += 255;
return offset;
}
static int
dissect_gadu_gadu_dcc7_id_abort(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
col_set_str(pinfo->cinfo, COL_INFO, "Direct connection abort");
proto_tree_add_item(tree, &hfi_dcc_id, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(tree, &hfi_dcc_uin_from, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_dcc_uin_to, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_gadu_gadu_pubdir50_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
int pos;
col_set_str(pinfo->cinfo, COL_INFO, "Public directory request");
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_request_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_request_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
while ((pos = tvb_find_guint8(tvb, offset, -1, '\0')) > 0) {
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_request_str, tvb, offset, (pos - offset) + 1, ENC_NA | ENC_WINDOWS_1250);
offset = pos + 1;
}
return offset;
}
static int
dissect_gadu_gadu_pubdir50_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
int pos;
col_set_str(pinfo->cinfo, COL_INFO, "Public directory reply");
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_reply_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_reply_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
while ((pos = tvb_find_guint8(tvb, offset, -1, '\0')) > 0) {
proto_tree_add_item(tree, &hfi_gadu_gadu_pubdir_reply_str, tvb, offset, (pos - offset) + 1, ENC_NA | ENC_WINDOWS_1250);
offset = pos + 1;
}
return offset;
}
static int
dissect_gadu_gadu_xml_action(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
tvbuff_t *xml_tvb;
int ret;
col_set_str(pinfo->cinfo, COL_INFO, "XML action message");
xml_tvb = tvb_new_subset_remaining(tvb, offset);
ret = call_dissector_only(xml_handle, xml_tvb, pinfo, tree, NULL);
return offset + ret;
}
static int
dissect_gadu_gadu_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *gadu_gadu_tree = NULL;
int offset = 0;
guint32 pkt_type;
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti = proto_tree_add_item(tree, hfi_gadu_gadu, tvb, 0, -1, ENC_NA);
gadu_gadu_tree = proto_item_add_subtree(ti, ett_gadu_gadu);
}
pkt_type = tvb_get_letohl(tvb, offset);
proto_tree_add_item(gadu_gadu_tree, (pinfo->p2p_dir == P2P_DIR_RECV) ? &hfi_gadu_gadu_header_type_recv : &hfi_gadu_gadu_header_type_send, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(gadu_gadu_tree, &hfi_gadu_gadu_header_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (pinfo->p2p_dir == P2P_DIR_RECV) {
switch (pkt_type) {
case GG_DISCONNECTING:
offset = dissect_gadu_gadu_disconnecting(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_DISCONNECT_ACK:
offset = dissect_gadu_gadu_disconnect_ack(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN_OK:
offset = dissect_gadu_gadu_login_ok(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN_OK80:
offset = dissect_gadu_gadu_login_ok80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN_FAILED:
offset = dissect_gadu_gadu_login_failed(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN80_FAILED:
offset = dissect_gadu_gadu_login80_failed(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USER_DATA:
offset = dissect_gadu_gadu_user_data(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_TYPING_NOTIFY:
offset = dissect_gadu_gadu_typing_notify(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_RECV_MSG:
offset = dissect_gadu_gadu_recv_msg(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_RECV_MSG80:
offset = dissect_gadu_gadu_recv_msg80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_SEND_MSG_ACK:
offset = dissect_gadu_gadu_send_msg_ack(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_STATUS60:
offset = dissect_gadu_gadu_status60(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_STATUS77:
offset = dissect_gadu_gadu_status77(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_STATUS80:
offset = dissect_gadu_gadu_status80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NOTIFY_REPLY80:
offset = dissect_gadu_gadu_notify_reply80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_DCC7_ID_REPLY:
offset = dissect_gadu_gadu_dcc7_id_reply(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_WELCOME:
offset = dissect_gadu_gadu_welcome(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USERLIST_REPLY80:
offset = dissect_gadu_gadu_userlist_reply80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USERLIST100_REPLY:
offset = dissect_gadu_gadu_userlist_reply100(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USERLIST100_VERSION:
offset = dissect_gadu_gadu_userlist_version100(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_PUBDIR50_REPLY:
offset = dissect_gadu_gadu_pubdir50_reply(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_XML_ACTION:
offset = dissect_gadu_gadu_xml_action(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_STATUS:
case GG_PONG:
case GG_PING:
case GG_NOTIFY_REPLY:
case GG_USERLIST_REPLY:
case GG_NOTIFY_REPLY60:
case GG_NEED_EMAIL:
case GG_LOGIN_HASH_TYPE_INVALID:
case GG_NOTIFY_REPLY77:
case GG_DCC7_INFO:
case GG_DCC7_NEW:
case GG_DCC7_ACCEPT:
case GG_DCC7_REJECT:
case GG_DCC7_ID_ABORTED:
case GG_XML_EVENT:
case GG_STATUS80BETA:
case GG_NOTIFY_REPLY80BETA:
case GG_OWN_MESSAGE:
case GG_OWN_RESOURCE_INFO:
default:
{
const char *pkt_name = try_val_to_str(pkt_type, gadu_gadu_packets_type_recv);
if (pkt_name)
col_set_str(pinfo->cinfo, COL_INFO, pkt_name);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown recv packet: %.2x", pkt_type);
break;
}
}
} else {
switch (pkt_type) {
case GG_LOGIN:
offset = dissect_gadu_gadu_login(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN70:
offset = dissect_gadu_gadu_login70(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LOGIN80:
offset = dissect_gadu_gadu_login80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_LIST_EMPTY:
offset = dissect_gadu_gadu_list_empty(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NOTIFY_FIRST:
offset = dissect_gadu_gadu_notify_first(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NOTIFY_LAST:
offset = dissect_gadu_gadu_notify_last(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NOTIFY105:
offset = dissect_gadu_gadu_notify105(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_ADD_NOTIFY:
offset = dissect_gadu_gadu_add_notify(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_ADD_NOTIFY105:
offset = dissect_gadu_gadu_add_notify105(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_REMOVE_NOTIFY:
offset = dissect_gadu_gadu_remove_notify(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_REMOVE_NOTIFY105:
offset = dissect_gadu_gadu_remove_notify105(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_PING:
offset = dissect_gadu_gadu_ping(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_TYPING_NOTIFY:
offset = dissect_gadu_gadu_typing_notify(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_SEND_MSG:
offset = dissect_gadu_gadu_send_msg(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_SEND_MSG80:
offset = dissect_gadu_gadu_send_msg80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_RECV_MSG_ACK:
offset = dissect_gadu_gadu_recv_msg_ack(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NEW_STATUS:
offset = dissect_gadu_gadu_new_status(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_NEW_STATUS80:
offset = dissect_gadu_gadu_new_status80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_DCC7_ID_REQUEST:
offset = dissect_gadu_gadu_dcc7_id_request(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_DCC7_NEW:
offset = dissect_gadu_gadu_dcc7_new(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_DCC7_ID_ABORT:
offset = dissect_gadu_gadu_dcc7_id_abort(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USERLIST_REQUEST80:
offset = dissect_gadu_gadu_userlist_request80(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_USERLIST100_REQUEST:
offset = dissect_gadu_gadu_userlist_request100(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_PUBDIR50_REQUEST:
offset = dissect_gadu_gadu_pubdir50_request(tvb, pinfo, gadu_gadu_tree, offset);
break;
case GG_PONG:
case GG_LOGIN_EXT:
case GG_LOGIN60:
case GG_USERLIST_REQUEST:
case GG_DCC7_INFO:
case GG_DCC7_ACCEPT:
case GG_DCC7_REJECT:
case GG_DCC7_ID_DUNNO1:
case GG_NEW_STATUS80BETA:
case GG_LOGIN80BETA:
case GG_OWN_DISCONNECT:
case GG_NEW_STATUS105:
case GG_LOGIN105:
default:
{
const char *pkt_name = try_val_to_str(pkt_type, gadu_gadu_packets_type_send);
if (pkt_name)
col_set_str(pinfo->cinfo, COL_INFO, pkt_name);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown send packet: %.2x", pkt_type);
break;
}
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(gadu_gadu_tree, &hfi_gadu_gadu_data, tvb, offset, -1, ENC_NA);
}
return tvb_length(tvb);
}
static guint
get_gadu_gadu_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 len = tvb_get_letohl(tvb, offset + 4);
return len + 8;
}
static int
dissect_gadu_gadu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (pinfo->srcport == pinfo->match_uint && pinfo->destport != pinfo->match_uint)
pinfo->p2p_dir = P2P_DIR_RECV;
else if (pinfo->srcport != pinfo->match_uint && pinfo->destport == pinfo->match_uint)
pinfo->p2p_dir = P2P_DIR_SENT;
else
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Gadu-Gadu");
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, gadu_gadu_desegment, 8, get_gadu_gadu_pdu_len, dissect_gadu_gadu_pdu, data);
return tvb_length(tvb);
}
void
proto_register_gadu_gadu(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_gadu_gadu_header_type_recv,
&hfi_gadu_gadu_header_type_send,
&hfi_gadu_gadu_header_length,
&hfi_gadu_gadu_login_uin,
&hfi_gadu_gadu_login_hash_type,
&hfi_gadu_gadu_login_hash,
&hfi_gadu_gadu_login_status,
&hfi_gadu_gadu_login_protocol,
&hfi_gadu_gadu_login_version,
&hfi_gadu_gadu_login_local_ip,
&hfi_gadu_gadu_login_local_port,
&hfi_gadu_gadu_login80_lang,
&hfi_gadu_gadu_userdata_uin,
&hfi_gadu_gadu_userdata_attr_name,
&hfi_gadu_gadu_userdata_attr_type,
&hfi_gadu_gadu_userdata_attr_value,
&hfi_gadu_gadu_typing_notify_type,
&hfi_gadu_gadu_typing_notify_uin,
&hfi_gadu_gadu_msg_uin,
&hfi_gadu_gadu_msg_sender,
&hfi_gadu_gadu_msg_recipient,
&hfi_gadu_gadu_msg_seq,
&hfi_gadu_gadu_msg_time,
&hfi_gadu_gadu_msg_class,
&hfi_gadu_gadu_msg_text,
&hfi_gadu_gadu_msg80_offset_plain,
&hfi_gadu_gadu_msg80_offset_attr,
&hfi_gadu_gadu_contact_uin,
&hfi_gadu_gadu_contact_uin_str,
&hfi_gadu_gadu_contact_type,
&hfi_gadu_gadu_status_uin,
&hfi_gadu_gadu_status_status,
&hfi_gadu_gadu_status_ip,
&hfi_gadu_gadu_status_port,
&hfi_gadu_gadu_status_version,
&hfi_gadu_gadu_status_img_size,
&hfi_gadu_gadu_status_descr,
&hfi_gadu_gadu_new_status_status,
&hfi_gadu_gadu_new_status_desc,
&hfi_gadu_gadu_userlist_request_type,
&hfi_gadu_gadu_userlist_version,
&hfi_gadu_gadu_userlist_format,
&hfi_gadu_gadu_userlist_reply_type,
&hfi_dcc_type,
&hfi_dcc_id,
&hfi_dcc_uin_to,
&hfi_dcc_uin_from,
&hfi_dcc_filename,
&hfi_gadu_gadu_pubdir_request_type,
&hfi_gadu_gadu_pubdir_request_seq,
&hfi_gadu_gadu_pubdir_request_str,
&hfi_gadu_gadu_pubdir_reply_type,
&hfi_gadu_gadu_pubdir_reply_seq,
&hfi_gadu_gadu_pubdir_reply_str,
&hfi_gadu_gadu_welcome_seed,
&hfi_gadu_gadu_msg_ack_status,
&hfi_gadu_gadu_msg_ack_recipient,
&hfi_gadu_gadu_msg_ack_seq,
&hfi_gadu_gadu_data,
};
#endif
static gint *ett[] = {
&ett_gadu_gadu,
&ett_gadu_gadu_contact
};
module_t *gadu_gadu_module;
int proto_gadu_gadu;
proto_gadu_gadu = proto_register_protocol("Gadu-Gadu Protocol", "Gadu-Gadu", "gadu-gadu");
hfi_gadu_gadu = proto_registrar_get_nth(proto_gadu_gadu);
gadu_gadu_module = prefs_register_protocol(proto_gadu_gadu, NULL);
prefs_register_bool_preference(gadu_gadu_module, "desegment",
"Reassemble Gadu-Gadu messages spanning multiple TCP segments",
"Whether the Gadu-Gadu dissector should reassemble messages spanning multiple TCP segments."
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&gadu_gadu_desegment);
proto_register_fields(proto_gadu_gadu, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
gadu_gadu_handle = new_create_dissector_handle(dissect_gadu_gadu, proto_gadu_gadu);
}
void
proto_reg_handoff_gadu_gadu(void)
{
dissector_add_uint("tcp.port", TCP_PORT_GADU_GADU, gadu_gadu_handle);
xml_handle = find_dissector("xml");
}
