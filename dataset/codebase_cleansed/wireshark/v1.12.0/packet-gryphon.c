static guint
get_gryphon_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
int padded_len;
plen = tvb_get_ntohs(tvb, offset + 4);
padded_len = plen + 3 - (plen + 3) % 4;
return padded_len + FRAME_HEADER_LEN;
}
static int
dissect_gryphon_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_gryphon_message(tvb, pinfo, tree, FALSE);
return tvb_length(tvb);
}
static int
dissect_gryphon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, gryphon_desegment, FRAME_HEADER_LEN,
get_gryphon_pdu_len, dissect_gryphon_pdu, data);
return tvb_length(tvb);
}
static void
dissect_gryphon_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_msgresp_add)
{
int offset = 0;
proto_tree *gryphon_tree;
proto_item *ti;
proto_tree *header_tree, *body_tree, *local_tree;
proto_item *header_item, *body_item, *local_item;
int msgend;
int msglen, msgpad;
unsigned int src, dest, i, frmtyp;
guint8 flags;
if (!is_msgresp_add) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Gryphon");
col_clear(pinfo->cinfo, COL_INFO);
}
if (!is_msgresp_add) {
ti = proto_tree_add_item(tree, proto_gryphon, tvb, 0, -1, ENC_NA);
gryphon_tree = proto_item_add_subtree(ti, ett_gryphon);
} else
gryphon_tree = tree;
src = tvb_get_guint8(tvb, offset + 0);
dest = tvb_get_guint8(tvb, offset + 2);
msglen = tvb_get_ntohs(tvb, offset + 4);
flags = tvb_get_guint8(tvb, offset + 6);
frmtyp = flags & ~RESPONSE_FLAGS;
if (!is_msgresp_add) {
set_actual_length(tvb, msglen + FRAME_HEADER_LEN);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str(frmtyp, frame_type, "- Invalid -"));
}
if (tree == NULL)
return;
if (try_val_to_str(frmtyp, frame_type) == NULL) {
proto_tree_add_item(gryphon_tree, hf_gryphon_data, tvb, offset, msglen, ENC_NA);
return;
}
header_item = proto_tree_add_text(gryphon_tree, tvb, offset, MSG_HDR_SZ, "Header");
header_tree = proto_item_add_subtree(header_item, ett_gryphon_header);
proto_tree_add_item(header_tree, hf_gryphon_src, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_gryphon_srcchan, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_gryphon_dest, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_gryphon_destchan, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_gryphon_data_length, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(header_tree, hf_gryphon_type, tvb, offset+6, 1, ENC_BIG_ENDIAN);
if (is_msgresp_add) {
local_item = proto_tree_add_text(header_tree, tvb, offset+6, 1, "Flags");
local_tree = proto_item_add_subtree (local_item, ett_gryphon_flags);
proto_tree_add_item(local_tree, hf_gryphon_wait_resp, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(local_tree, hf_gryphon_wait_prev_resp, tvb, offset+6, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(header_tree, hf_gryphon_reserved1, tvb, offset+7, 1, ENC_BIG_ENDIAN);
msgpad = 3 - (msglen + 3) % 4;
msgend = offset + msglen + msgpad + MSG_HDR_SZ;
body_item = proto_tree_add_text(gryphon_tree, tvb, offset + MSG_HDR_SZ,
msglen + msgpad, "Body");
body_tree = proto_item_add_subtree(body_item, ett_gryphon_body);
offset += MSG_HDR_SZ;
switch (frmtyp) {
case GY_FT_CMD:
offset = decode_command(tvb, offset, dest, body_tree);
break;
case GY_FT_RESP:
offset = decode_response(tvb, offset, src, body_tree);
break;
case GY_FT_DATA:
offset = decode_data(tvb, offset, body_tree);
break;
case GY_FT_EVENT:
offset = decode_event(tvb, offset, body_tree);
break;
case GY_FT_MISC:
offset = decode_misc (tvb, offset, body_tree);
break;
case GY_FT_TEXT:
break;
default:
break;
}
if (offset < msgend - msgpad) {
i = msgend - msgpad - offset;
proto_tree_add_item(gryphon_tree, hf_gryphon_data, tvb, offset, i, ENC_NA);
offset += i;
}
if (offset < msgend) {
i = msgend - offset;
proto_tree_add_item(gryphon_tree, hf_gryphon_padding, tvb, offset, i, ENC_NA);
}
}
static int
decode_command(tvbuff_t *tvb, int offset, int dst, proto_tree *pt)
{
int cmd, msglen;
unsigned int i;
proto_tree *ft;
proto_item *ti;
proto_item *hi;
msglen = tvb_reported_length_remaining(tvb, offset);
cmd = tvb_get_guint8(tvb, offset);
hi = proto_tree_add_uint(pt, hf_gryphon_cmd, tvb, offset, 1, cmd);
PROTO_ITEM_SET_HIDDEN(hi);
if (cmd > 0x3F)
cmd += dst * 256;
for (i = 0; i < SIZEOF(cmds); i++) {
if (cmds[i].value == cmd)
break;
}
if (i >= SIZEOF(cmds) && dst >= SD_KNOWN) {
cmd = (cmd & 0xFF) + SD_CARD * 256;
for (i = 0; i < SIZEOF(cmds); i++) {
if (cmds[i].value == cmd)
break;
}
}
if (i >= SIZEOF(cmds))
i = SIZEOF(cmds) - 1;
proto_tree_add_text (pt, tvb, offset, 4, "Command: %s", cmds[i].strptr);
offset += 4;
msglen -= 4;
if (cmds[i].cmd_fnct && msglen > 0) {
ti = proto_tree_add_text(pt, tvb, offset, -1, "Data: (%d byte%s)",
msglen, msglen == 1 ? "" : "s");
ft = proto_item_add_subtree(ti, ett_gryphon_command_data);
offset = (*(cmds[i].cmd_fnct)) (tvb, offset, ft);
}
return offset;
}
static int
decode_response(tvbuff_t *tvb, int offset, int src, proto_tree *pt)
{
int cmd, msglen;
unsigned int i;
proto_tree *ft;
proto_item *ti;
msglen = tvb_reported_length_remaining(tvb, offset);
cmd = tvb_get_guint8(tvb, offset);
if (cmd > 0x3F)
cmd += src * 256;
for (i = 0; i < SIZEOF(cmds); i++) {
if (cmds[i].value == cmd)
break;
}
if (i >= SIZEOF(cmds) && src >= SD_KNOWN) {
cmd = (cmd & 0xFF) + SD_CARD * 256;
for (i = 0; i < SIZEOF(cmds); i++) {
if (cmds[i].value == cmd)
break;
}
}
if (i >= SIZEOF(cmds))
i = SIZEOF(cmds) - 1;
proto_tree_add_text (pt, tvb, offset, 4, "Command: %s", cmds[i].strptr);
offset += 4;
msglen -= 4;
proto_tree_add_item(pt, hf_gryphon_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
if (cmds[i].rsp_fnct && msglen > 0) {
ti = proto_tree_add_text(pt, tvb, offset, msglen, "Data: (%d byte%s)",
msglen, msglen == 1 ? "" : "s");
ft = proto_item_add_subtree(ti, ett_gryphon_response_data);
offset = (*(cmds[i].rsp_fnct)) (tvb, offset, ft);
}
return offset;
}
static int
decode_data(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item, *item1;
proto_tree *tree, *tree1;
int hdrsize, datasize, extrasize, msgsize, padding, mode;
nstime_t timestamp;
hdrsize = tvb_get_guint8(tvb, offset+0);
datasize = tvb_get_ntohs(tvb, offset+2);
extrasize = tvb_get_guint8(tvb, offset+4);
padding = 3 - (hdrsize + datasize + extrasize + 3) % 4;
msgsize = hdrsize + datasize + extrasize + padding + 16;
item = proto_tree_add_text(pt, tvb, offset, 16, "Message header");
tree = proto_item_add_subtree (item, ett_gryphon_data_header);
proto_tree_add_item(tree, hf_gryphon_data_header_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_data_data_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_data_extra_data_length, tvb, offset+4, 1, ENC_BIG_ENDIAN);
mode = tvb_get_guint8(tvb, offset+5);
item1 = proto_tree_add_item(tree, hf_gryphon_data_mode, tvb, offset+5, 1, ENC_BIG_ENDIAN);
if (mode) {
tree1 = proto_item_add_subtree (item1, ett_gryphon_flags);
proto_tree_add_item(tree1, hf_gryphon_data_mode_transmitted, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree1, hf_gryphon_data_mode_receive, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree1, hf_gryphon_data_mode_local, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree1, hf_gryphon_data_mode_remote, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree1, hf_gryphon_data_mode_internal, tvb, offset+5, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_gryphon_data_priority, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_data_error_status, tvb, offset+7, 1, ENC_BIG_ENDIAN);
timestamp.secs = tvb_get_ntohl(tvb, offset+8)/100000;
timestamp.nsecs = (tvb_get_ntohl(tvb, offset+8)%100000)*1000;
proto_tree_add_time(tree, hf_gryphon_data_time, tvb, offset+8, 4, &timestamp);
proto_tree_add_item(tree, hf_gryphon_data_context, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_reserved3, tvb, offset+13, 3, ENC_BIG_ENDIAN);
offset += 16;
item = proto_tree_add_text(pt, tvb, offset, msgsize-16-padding, "Message Body");
tree = proto_item_add_subtree (item, ett_gryphon_data_body);
if (hdrsize) {
proto_tree_add_item(tree, hf_gryphon_data_header_data, tvb, offset, hdrsize, ENC_NA);
offset += hdrsize;
}
if (datasize) {
proto_tree_add_item(tree, hf_gryphon_data_data, tvb, offset, datasize, ENC_NA);
offset += datasize;
}
if (extrasize) {
proto_tree_add_item(tree, hf_gryphon_data_extra_data, tvb, offset, extrasize, ENC_NA);
offset += extrasize;
}
if (padding) {
proto_tree_add_item(tree, hf_gryphon_data_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int
decode_event(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen, msgend, padding, length;
nstime_t timestamp;
msglen = tvb_reported_length_remaining(tvb, offset);
padding = 3 - (msglen + 3) % 4;
msgend = offset + msglen;
proto_tree_add_item(pt, hf_gryphon_event_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_event_context, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
timestamp.secs = tvb_get_ntohl(tvb, offset)/100000;
timestamp.nsecs = (tvb_get_ntohl(tvb, offset)%100000)*1000;
proto_tree_add_time(pt, hf_gryphon_event_time, tvb, offset, 4, &timestamp);
offset += 4;
if (offset < msgend) {
length = msgend - offset;
proto_tree_add_item(pt, hf_gryphon_event_data, tvb, offset, length, ENC_NA);
offset += length;
}
if (padding) {
proto_tree_add_item(pt, hf_gryphon_event_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int
decode_misc (tvbuff_t *tvb, int offset, proto_tree *pt)
{
int padding, msglen;
gint length = 120;
msglen = tvb_reported_length_remaining(tvb, offset);
padding = 3 - (msglen + 3) % 4;
proto_tree_add_item(pt, hf_gryphon_misc_data, tvb, offset, length, ENC_NA|ENC_ASCII);
offset += msglen;
if (padding) {
proto_tree_add_item(pt, hf_gryphon_misc_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int
cmd_init(tvbuff_t *tvb, int offset, proto_tree *pt)
{
const char *ptr;
if (tvb_get_guint8(tvb, offset) == 0)
ptr = "Always initialize";
else
ptr = "Initialize if not previously initialized";
proto_tree_add_text(pt, tvb, offset, 1, "Mode: %s", ptr);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
eventnum(tvbuff_t *tvb, int offset, proto_tree *pt)
{
guint8 event = tvb_get_guint8(tvb, offset);
if (event)
proto_tree_add_item(pt, hf_gryphon_eventnum, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_uint_format_value(pt, hf_gryphon_eventnum, tvb, offset, 1,
0, "Event numbers: All");
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_time(tvbuff_t *tvb, int offset, proto_tree *pt)
{
guint64 val;
nstime_t timestamp;
val = tvb_get_ntoh64(tvb, offset);
timestamp.secs = (time_t)(val/100000);
timestamp.nsecs = (int)((val%100000)*1000);
proto_tree_add_time(pt, hf_gryphon_resp_time, tvb, offset, 8, &timestamp);
offset += 8;
return offset;
}
static int
cmd_setfilt(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int flag = tvb_get_ntohl(tvb, offset);
int length, padding;
length = tvb_get_guint8(tvb, offset+4) + tvb_get_guint8(tvb, offset+5)
+ tvb_get_ntohs(tvb, offset+6);
proto_tree_add_uint_format_value(pt, hf_gryphon_setfilt, tvb, offset, 4,
flag, "%s%s", ((flag) ? "Pass" : "Block"), ((length == 0) ? " all" : ""));
proto_tree_add_uint(pt, hf_gryphon_setfilt_length, tvb, offset+4, 4, length);
offset += 8;
if (length) {
proto_tree_add_item(pt, hf_gryphon_setfilt_discard_data, tvb, offset, length * 2, ENC_NA);
offset += length * 2;
}
padding = 3 - (length * 2 + 3) % 4;
if (padding) {
proto_tree_add_item(pt, hf_gryphon_setfilt_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int
cmd_ioctl(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_ioctl, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
if (msglen > 0) {
proto_tree_add_item(pt, hf_gryphon_ioctl_data, tvb, offset, msglen, ENC_NA);
offset += msglen;
}
return offset;
}
static int
cmd_addfilt(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
int blocks, i, length;
item = proto_tree_add_text(pt, tvb, offset, 1, "Flags");
tree = proto_item_add_subtree (item, ett_gryphon_flags);
proto_tree_add_item(tree, hf_gryphon_addfilt_pass, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_addfilt_active, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_addfilt_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved_bytes, tvb, offset+1, 6, ENC_BIG_ENDIAN);
offset += 7;
for (i = 1; i <= blocks; i++) {
length = tvb_get_ntohs(tvb, offset+2) * 2 + 8;
length += 3 - (length + 3) % 4;
item = proto_tree_add_text(pt, tvb, offset, length, "Filter block %d", i);
tree = proto_item_add_subtree (item, ett_gryphon_cmd_filter_block);
offset = filter_block(tvb, offset, tree);
}
return offset;
}
static int
resp_addfilt(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_addfilt_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
cmd_modfilt(tvbuff_t *tvb, int offset, proto_tree *pt)
{
guint8 filter_handle = tvb_get_guint8(tvb, offset);
if (filter_handle)
proto_tree_add_item(pt, hf_gryphon_modfilt, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_uint_format_value(pt, hf_gryphon_modfilt, tvb, offset, 1,
0, "Filter handles: all");
proto_tree_add_item(pt, hf_gryphon_modfilt_action, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_filthan(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int handles = tvb_get_guint8(tvb, offset);
int i, padding, handle;
proto_tree_add_item(pt, hf_gryphon_filthan, tvb, offset, 1, ENC_BIG_ENDIAN);
for (i = 1; i <= handles; i++){
handle = tvb_get_guint8(tvb, offset+i);
proto_tree_add_uint_format_value(pt, hf_gryphon_filthan_id, tvb, offset+i, 1,
handle, "Handle %d: %u", i, handle);
}
padding = 3 - (handles + 1 + 3) % 4;
if (padding)
proto_tree_add_item(pt, hf_gryphon_filthan_padding, tvb, offset+1+handles, padding, ENC_NA);
offset += 1+handles+padding;
return offset;
}
static int
dfiltmode(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_dfiltmode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
filtmode(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_filtmode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_events(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
unsigned int i;
proto_tree *tree;
proto_item *item;
msglen = tvb_reported_length_remaining(tvb, offset);
i = 1;
while (msglen != 0) {
item = proto_tree_add_text(pt, tvb, offset, 20, "Event %d:", i);
tree = proto_item_add_subtree (item, ett_gryphon_cmd_events_data);
proto_tree_add_item(tree, hf_gryphon_event_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_event_name, tvb, offset+1, 19, ENC_NA|ENC_ASCII);
offset += 20;
msglen -= 20;
i++;
}
return offset;
}
static int
cmd_register(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_register_username, tvb, offset, 16, ENC_NA|ENC_ASCII);
offset += 16;
proto_tree_add_item(pt, hf_gryphon_register_password, tvb, offset, 32, ENC_NA|ENC_ASCII);
offset += 32;
return offset;
}
static int
resp_register(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_register_client_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_register_privileges, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_getspeeds(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int indx,
size = tvb_get_guint8(tvb, offset+8),
number = tvb_get_guint8(tvb, offset+9);
proto_tree_add_item(pt, hf_gryphon_getspeeds_set_ioctl, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_getspeeds_get_ioctl, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_getspeeds_size, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_getspeeds_preset, tvb, offset+9, 1, ENC_BIG_ENDIAN);
offset += 10;
for (indx = 1; indx <= number; indx++) {
proto_tree_add_bytes_format(pt, hf_gryphon_getspeeds_data, tvb, offset, size,
tvb_get_ptr(tvb, offset, size), "Data for preset %d", indx);
offset += size;
}
return offset;
}
static int
cmd_sort(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_cmd_sort, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1);
}
static int
cmd_optimize(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_cmd_optimize, tvb, offset, 1, ENC_BIG_ENDIAN);
return (offset+1);
}
static int
resp_config(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *ti, *item;
proto_tree *ft, *tree;
int devices;
int i;
unsigned int j, x;
proto_tree_add_item(pt, hf_gryphon_config_device_name, tvb, offset, 20, ENC_NA|ENC_ASCII);
offset += 20;
proto_tree_add_item(pt, hf_gryphon_config_device_version, tvb, offset, 8, ENC_NA|ENC_ASCII);
offset += 8;
proto_tree_add_item(pt, hf_gryphon_config_device_serial_number, tvb, offset, 20, ENC_NA|ENC_ASCII);
offset += 20;
devices = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_config_num_channels, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_config_name_version_ext, tvb, offset+1, 11, ENC_NA|ENC_ASCII);
proto_tree_add_item(pt, hf_gryphon_reserved4, tvb, offset+12, 4, ENC_BIG_ENDIAN);
offset += 16;
for (i = 1; i <= devices; i++) {
ti = proto_tree_add_text(pt, tvb, offset, 80, "Channel %d:", i);
ft = proto_item_add_subtree(ti, ett_gryphon_cmd_config_device);
proto_tree_add_item(ft, hf_gryphon_config_driver_name, tvb, offset, 20, ENC_NA|ENC_ASCII);
offset += 20;
proto_tree_add_item(ft, hf_gryphon_config_driver_version, tvb, offset, 8, ENC_NA|ENC_ASCII);
offset += 8;
proto_tree_add_item(ft, hf_gryphon_config_device_security, tvb, offset, 16, ENC_NA|ENC_ASCII);
offset += 16;
x = tvb_get_ntohl (tvb, offset);
if (x) {
item = proto_tree_add_text(ft, tvb, offset, 4, "Valid Header lengths");
tree = proto_item_add_subtree (item, ett_gryphon_valid_headers);
for (j = 0; ; j++) {
if (x & 1) {
proto_tree_add_text(tree, tvb, offset, 4, "%d byte%s", j,
j == 1 ? "" : "s");
}
if ((x >>= 1) == 0)
break;
}
}
offset += 4;
proto_tree_add_item(ft, hf_gryphon_config_max_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ft, hf_gryphon_config_min_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ft, hf_gryphon_config_hardware_serial_number, tvb, offset, 20, ENC_NA|ENC_ASCII);
offset += 20;
proto_tree_add_item(ft, hf_gryphon_config_protocol_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ft, hf_gryphon_config_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ft, hf_gryphon_config_card_slot_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(ft, hf_gryphon_config_max_extra_data, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ft, hf_gryphon_config_min_extra_data, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return offset;
}
static int
cmd_sched(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
proto_item *item, *item1;
proto_tree *tree, *tree1;
int save_offset;
unsigned int i, x, length;
unsigned char def_chan = tvb_get_guint8(tvb, offset-9);
msglen = tvb_reported_length_remaining(tvb, offset);
if (tvb_get_ntohl(tvb, offset) == 0xFFFFFFFF)
proto_tree_add_uint_format_value(pt, hf_gryphon_sched_num_iterations, tvb, offset, 4,
0, "Number of iterations: \"infinite\"");
else
proto_tree_add_item(pt, hf_gryphon_sched_num_iterations, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
item = proto_tree_add_item(pt, hf_gryphon_sched_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree (item, ett_gryphon_flags);
proto_tree_add_item(tree, hf_gryphon_sched_flags_scheduler, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
i = 1;
while (msglen > 0) {
length = 16 + tvb_get_guint8(tvb, offset+16) +
tvb_get_ntohs(tvb, offset+18) + tvb_get_guint8(tvb, offset+20) + 16;
length += 3 - (length + 3) % 4;
item = proto_tree_add_text(pt, tvb, offset, length, "Message %d", i);
tree = proto_item_add_subtree (item, ett_gryphon_cmd_sched_data);
proto_tree_add_item(tree, hf_gryphon_sched_sleep, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
proto_tree_add_item(tree, hf_gryphon_sched_transmit_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
proto_tree_add_item(tree, hf_gryphon_sched_transmit_period, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
item1 = proto_tree_add_item(tree, hf_gryphon_sched_transmit_flags, tvb, offset, 2, ENC_BIG_ENDIAN);
tree1 = proto_item_add_subtree (item1, ett_gryphon_flags);
proto_tree_add_item(tree1, hf_gryphon_sched_skip_transmit_period, tvb, offset, 2, ENC_BIG_ENDIAN);
if (i == 1) {
proto_tree_add_item(tree1, hf_gryphon_sched_skip_sleep, tvb, offset, 2, ENC_BIG_ENDIAN);
}
x = tvb_get_guint8(tvb, offset+2);
if (x == 0)
x = def_chan;
proto_tree_add_uint(tree, hf_gryphon_sched_channel, tvb, offset+2, 1, x);
proto_tree_add_item(tree, hf_gryphon_reserved1, tvb, offset+3, 1, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
item1 = proto_tree_add_text(tree, tvb, offset, length, "Message");
tree1 = proto_item_add_subtree (item1, ett_gryphon_cmd_sched_cmd);
save_offset = offset;
offset = decode_data(tvb, offset, tree1);
msglen -= offset - save_offset;
i++;
}
return offset;
}
static int
cmd_sched_rep(tvbuff_t *tvb, int offset, proto_tree *pt)
{
unsigned int x;
const char *type;
x = tvb_get_ntohl(tvb, offset);
if (x & 0x80000000)
type = "Critical";
else
type = "Normal";
proto_tree_add_uint_format_value(pt, hf_gryphon_sched_rep_id, tvb,
offset, 4, x, "%s schedule ID: %u", type, x);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_sched_rep_message_index, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
offset = decode_data(tvb, offset, pt);
return offset;
}
static int
resp_blm_data(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int x;
nstime_t timestamp;
timestamp.secs = tvb_get_ntohl(tvb, offset)/100000;
timestamp.nsecs = (tvb_get_ntohl(tvb, offset)%100000)*1000;
proto_tree_add_time(pt, hf_gryphon_blm_data_time, tvb, offset, 4, &timestamp);
offset += 4;
x = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(pt, hf_gryphon_blm_data_bus_load, tvb,
offset, 2, x, "%d.%02d%%", x / 100, x % 100);
offset += 2;
x = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(pt, hf_gryphon_blm_data_current_bus_load, tvb,
offset, 2, x, "%d.%02d%%", x / 100, x % 100);
offset += 2;
x = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(pt, hf_gryphon_blm_data_peak_bus_load, tvb,
offset, 2, x, "%d.%02d%%", x / 100, x % 100);
offset += 2;
x = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format_value(pt, hf_gryphon_blm_data_historic_peak_bus_load, tvb,
offset, 2, x, "%d.%02d%%", x / 100, x % 100);
offset += 2;
return offset;
}
static int
resp_blm_stat(tvbuff_t *tvb, int offset, proto_tree *pt)
{
offset = resp_blm_data(tvb, offset, pt);
proto_tree_add_item(pt, hf_gryphon_blm_stat_receive_frame_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_blm_stat_transmit_frame_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_blm_stat_receive_dropped_frame_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_blm_stat_transmit_dropped_frame_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_blm_stat_receive_error_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_blm_stat_transmit_error_count, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
cmd_addresp(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
int blocks, responses, i, msglen, length;
int action, actionType, actionValue;
tvbuff_t *next_tvb;
actionType = 0;
item = proto_tree_add_item(pt, hf_gryphon_addresp_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree (item, ett_gryphon_flags);
proto_tree_add_item(tree, hf_gryphon_addresp_flags_active, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
blocks = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gryphon_addresp_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
responses = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_gryphon_addresp_responses, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_gryphon_addresp_old_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
action = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, hf_gryphon_addresp_action, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree (item, ett_gryphon_flags);
actionValue = tvb_get_ntohs(tvb, offset+2);
if (actionValue) {
if (action & FR_PERIOD_MSGS) {
actionType = 1;
} else {
actionType = 0;
}
proto_tree_add_item(tree, hf_gryphon_addresp_action_period, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_gryphon_addresp_action_deact_on_event, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_addresp_action_deact_after_period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pt, hf_gryphon_reserved1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (actionValue) {
if (actionType == 1) {
proto_tree_add_uint_format_value(tree, hf_gryphon_addresp_action_period_type, tvb,
offset, 2, actionValue, "Period: %d messages", actionValue);
} else {
proto_tree_add_uint_format_value(tree, hf_gryphon_addresp_action_period_type, tvb,
offset, 2, actionValue, "Period: %d.%02d seconds", actionValue/100, actionValue%100);
}
}
offset += 2;
for (i = 1; i <= blocks; i++) {
length = tvb_get_ntohs(tvb, offset+2) * 2 + 8;
length += 3 - (length + 3) % 4;
item = proto_tree_add_text(pt, tvb, offset, length, "Filter block %d", i);
tree = proto_item_add_subtree (item, ett_gryphon_cmd_filter_block);
offset = filter_block(tvb, offset, tree);
}
for (i = 1; i <= responses; i++) {
msglen = tvb_get_ntohs(tvb, offset+4) + 8;
length = msglen + 3 - (msglen + 3) % 4;
item = proto_tree_add_text(pt, tvb, offset, length, "Response block %d", i);
tree = proto_item_add_subtree (item, ett_gryphon_cmd_response_block);
next_tvb = tvb_new_subset(tvb, offset, msglen, msglen);
dissect_gryphon_message(next_tvb, NULL, tree, TRUE);
offset += length;
}
return offset;
}
static int
resp_addresp(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_addresp_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
cmd_modresp(tvbuff_t *tvb, int offset, proto_tree *pt)
{
guint8 dest = tvb_get_guint8(tvb, offset-5),
resp_handle = tvb_get_guint8(tvb, offset);
if (resp_handle)
proto_tree_add_item(pt, hf_gryphon_modresp_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
else if (dest)
proto_tree_add_uint_format_value(pt, hf_gryphon_modresp_handle, tvb,
offset, 1, dest, "Response handles: all on channel %c", dest);
else
proto_tree_add_uint_format_value(pt, hf_gryphon_modresp_handle, tvb, offset, 1,
0, "Response handles: all");
proto_tree_add_item(pt, hf_gryphon_modresp_action, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_resphan(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int handles = tvb_get_guint8(tvb, offset);
int i, padding;
proto_tree_add_item(pt, hf_gryphon_num_resphan, tvb, offset, 1, ENC_BIG_ENDIAN);
for (i = 1; i <= handles; i++){
proto_tree_add_text(pt, tvb, offset+i, 1, "Handle %d: %u", i,
tvb_get_guint8(tvb, offset+i));
}
padding = 3 - (handles + 1 + 3) % 4;
if (padding)
proto_tree_add_item(pt, hf_gryphon_padding, tvb, offset+1+handles, padding, ENC_NA);
offset += 1+handles+padding;
return offset;
}
static int
resp_sched(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_transmit_sched_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
cmd_desc(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_desc_program_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pt, hf_gryphon_desc_program_name, tvb, offset, 32, ENC_NA|ENC_ASCII);
offset += 32;
proto_tree_add_item(pt, hf_gryphon_desc_program_description, tvb, offset, 80, ENC_NA|ENC_ASCII);
offset += 80;
return offset;
}
static int
resp_desc(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(pt, hf_gryphon_desc_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree (item, ett_gryphon_flags);
proto_tree_add_item(tree, hf_gryphon_desc_flags_program, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_desc_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
cmd_upload(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
unsigned int length;
msglen = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_upload_block_number, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_upload_handle, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += 3;
msglen -= 3;
length = msglen;
proto_tree_add_item(pt, hf_gryphon_upload_data, tvb, offset, length, ENC_NA);
offset += length;
length = 3 - (length + 3) % 4;
if (length) {
proto_tree_add_item(pt, hf_gryphon_padding, tvb, offset, length, ENC_NA);
offset += length;
}
return offset;
}
static int
cmd_delete(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_delete, tvb, offset, 32, ENC_NA|ENC_ASCII);
offset += 32;
return offset;
}
static int
cmd_list(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_list_block_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
resp_list(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
unsigned int i, count;
count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_list_num_programs, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved1, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pt, hf_gryphon_list_num_remain_programs, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (i = 1; i <= count; i++) {
item = proto_tree_add_text(pt, tvb, offset, 112, "Program %u", i);
tree = proto_item_add_subtree (item, ett_gryphon_pgm_list);
proto_tree_add_item(tree, hf_gryphon_list_name, tvb, offset, 32, ENC_NA|ENC_ASCII);
offset += 32;
proto_tree_add_item(tree, hf_gryphon_list_description, tvb, offset, 80, ENC_NA|ENC_ASCII);
offset += 80;
}
return offset;
}
static int
cmd_start(tvbuff_t *tvb, int offset, proto_tree *pt)
{
char *string;
gint length;
int msglen;
int hdr_stuff = offset;
msglen = tvb_reported_length_remaining(tvb, offset);
offset = cmd_delete(tvb, offset, pt);
if (offset < msglen + hdr_stuff) {
string = tvb_get_stringz(wmem_packet_scope(), tvb, offset, &length);
if (length > 1) {
proto_tree_add_string(pt, hf_gryphon_start_arguments, tvb, offset,
length, string);
offset += length;
length = 3 - (length + 3) % 4;
if (length) {
proto_tree_add_item(pt, hf_gryphon_padding, tvb, offset, length, ENC_NA);
offset += length;
}
}
}
return offset;
}
static int
resp_start(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
msglen = tvb_reported_length_remaining(tvb, offset);
if (msglen > 0) {
proto_tree_add_item(pt, hf_gryphon_start_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
resp_status(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
unsigned int i, copies, length;
copies = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(pt, hf_gryphon_status_num_running_copies, tvb, offset, 1, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree (item, ett_gryphon_pgm_status);
offset += 1;
if (copies) {
for (i = 1; i <= copies; i++) {
proto_tree_add_text(tree, tvb, offset, 1, "Program %u channel (client) number %u",
i, tvb_get_guint8(tvb, offset));
offset += 1;
}
}
length = 3 - (copies + 1 + 3) % 4;
if (length) {
proto_tree_add_item(pt, hf_gryphon_padding, tvb, offset, length, ENC_NA);
offset += length;
}
return offset;
}
static int
cmd_options(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
proto_item *item;
proto_tree *tree;
unsigned int i, size, padding, option, option_length, option_value;
const char *string, *string1;
msglen = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_options_handle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
msglen -= 4;
for (i = 1; msglen > 0; i++) {
option_length = tvb_get_guint8(tvb, offset+1);
size = option_length + 2;
padding = 3 - ((size + 3) %4);
item = proto_tree_add_text(pt, tvb, offset, size + padding, "Option number %u", i);
tree = proto_item_add_subtree (item, ett_gryphon_pgm_options);
option = tvb_get_guint8(tvb, offset);
switch (option_length) {
case 1:
option_value = tvb_get_guint8(tvb, offset+2);
break;
case 2:
option_value = tvb_get_ntohs(tvb, offset+2);
break;
case 4:
option_value = tvb_get_ntohl(tvb, offset+2);
break;
default:
option_value = 0;
}
string = "unknown option";
string1 = "unknown option data";
switch (option) {
case PGM_CONV:
string = "Type of data in the file";
switch (option_value) {
case PGM_BIN:
string1 = "Binary - Don't modify";
break;
case PGM_ASCII:
string1 = "ASCII - Remove CR's";
break;
}
break;
case PGM_TYPE:
string = "Type of file";
switch (option_value) {
case PGM_PGM:
string1 = "Executable";
break;
case PGM_DATA:
string1 = "Data";
break;
}
break;
}
proto_tree_add_text(tree, tvb, offset, 1, "%s", string);
proto_tree_add_text(tree, tvb, offset+2, option_length, "%s", string1);
if (padding)
proto_tree_add_item(tree, hf_gryphon_padding, tvb, offset+option_length+2, padding, ENC_NA);
offset += size + padding;
msglen -= size + padding;
}
return offset;
}
static int
cmd_files(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
const gchar *which;
msglen = tvb_reported_length_remaining(tvb, offset);
if (tvb_get_guint8(tvb, offset) == 0)
which = "First group of names";
else
which = "Subsequent group of names";
proto_tree_add_text(pt, tvb, offset, 1, "%s", which);
proto_tree_add_item(pt, hf_gryphon_files, tvb, offset+1, msglen-1, ENC_NA|ENC_ASCII);
offset += msglen;
return offset;
}
static int
resp_files(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int msglen;
const gchar *flag;
msglen = tvb_reported_length_remaining(tvb, offset);
flag = tvb_get_guint8(tvb, offset) ? "Yes": "No";
proto_tree_add_text(pt, tvb, offset, 1, "More filenames to return: %s", flag);
proto_tree_add_text(pt, tvb, offset+1, msglen-1, "File and directory names");
offset += msglen;
return offset;
}
static int
cmd_usdt(tvbuff_t *tvb, int offset, proto_tree *pt)
{
int ids, id, remain, size, i, j, bytes;
guint8 flags;
proto_tree *localTree;
proto_item *localItem;
static const gchar *block_desc[] = {"USDT request", "USDT response", "UUDT response"};
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pt, hf_gryphon_usdt_flags_register, tvb, offset, 1, ENC_BIG_ENDIAN);
if (flags & 1) {
localItem = proto_tree_add_item(pt, hf_gryphon_usdt_action_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
localTree = proto_item_add_subtree (localItem, ett_gryphon_flags);
proto_tree_add_item(localTree, hf_gryphon_usdt_action_flags_register, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(localTree, hf_gryphon_usdt_action_flags_action, tvb, offset, 1, ENC_BIG_ENDIAN);
localItem = proto_tree_add_item(pt, hf_gryphon_usdt_transmit_options_flags, tvb, offset+1, 1, ENC_BIG_ENDIAN);
localTree = proto_item_add_subtree (localItem, ett_gryphon_flags);
proto_tree_add_item(localTree, hf_gryphon_usdt_transmit_options_flags_echo, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(localTree, hf_gryphon_usdt_transmit_options_action, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(localTree, hf_gryphon_usdt_transmit_options_send_done, tvb, offset+1, 1, ENC_BIG_ENDIAN);
localItem = proto_tree_add_item(pt, hf_gryphon_usdt_receive_options_flags, tvb, offset+2, 1, ENC_BIG_ENDIAN);
localTree = proto_item_add_subtree (localItem, ett_gryphon_flags);
proto_tree_add_item(localTree, hf_gryphon_usdt_receive_options_action, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(localTree, hf_gryphon_usdt_receive_options_firstframe, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(localTree, hf_gryphon_usdt_receive_options_lastframe, tvb, offset+2, 1, ENC_BIG_ENDIAN);
if ((ids = tvb_get_guint8(tvb, offset+3))) {
localItem = proto_tree_add_item(pt, hf_gryphon_usdt_ext_address, tvb, offset+3, 1, ENC_BIG_ENDIAN);
offset += 4;
localTree = proto_item_add_subtree (localItem, ett_gryphon_usdt_data);
while (ids) {
proto_tree_add_item(localTree, hf_gryphon_usdt_ext_address_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ids--;
}
} else {
proto_tree_add_uint_format_value(pt, hf_gryphon_usdt_ext_address, tvb, offset+3, 1,
0, "Using extended addressing for the single, internally defined, ID");
offset += 4;
}
for (i = 0; i < 2; i++) {
bytes = tvb_reported_length_remaining (tvb, offset);
if (bytes <= 0)
break;
localItem = proto_tree_add_text(pt, tvb, offset, 16, "%s block of USDT/UUDT IDs", i==0?"First":"Second");
localTree = proto_item_add_subtree (localItem, ett_gryphon_usdt_data);
size = tvb_get_ntohl (tvb, offset);
localItem = proto_tree_add_item(localTree, hf_gryphon_usdt_block_size, tvb, offset, 4, ENC_BIG_ENDIAN);
localTree = proto_item_add_subtree (localItem, ett_gryphon_usdt_data_block);
if (size == 0) {
proto_item_set_len(localItem, 16);
} else {
offset += 4;
for (j = 0; j < 3; j++){
id = tvb_get_ntohl (tvb, offset);
proto_tree_add_text (localTree, tvb, offset, 4,
"%s IDs from %04X through %04X", block_desc[j], id, id+size-1);
offset += 4;
}
}
}
} else {
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
}
if ((remain = tvb_reported_length_remaining(tvb, offset))) {
proto_tree_add_item(pt, hf_gryphon_ignored, tvb, offset, remain, ENC_NA);
offset += remain;
}
return offset;
}
static int
cmd_bits_in (tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
int msglen, value;
msglen = tvb_reported_length_remaining(tvb, offset);
value = tvb_get_guint8(tvb, offset);
if (value) {
item = proto_tree_add_text(pt, tvb, offset, 1, "Digital values set");
tree = proto_item_add_subtree (item, ett_gryphon_digital_data);
proto_tree_add_item(tree, hf_gryphon_bits_in_input1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_bits_in_input2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_bits_in_input3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_bits_in_pushbutton, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_text(pt, tvb, offset, 1, "No digital values are set");
}
offset++;
msglen--;
return offset;
}
static int
cmd_bits_out (tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
int msglen, value;
msglen = tvb_reported_length_remaining(tvb, offset);
value = tvb_get_guint8(tvb, offset);
if (value) {
item = proto_tree_add_text(pt, tvb, offset, 1, "Digital values set");
tree = proto_item_add_subtree (item, ett_gryphon_digital_data);
proto_tree_add_item(tree, hf_gryphon_bits_out_output1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gryphon_bits_out_output2, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_text(pt, tvb, offset, 1, "No digital values are set");
}
offset++;
msglen--;
return offset;
}
static int
cmd_init_strat (tvbuff_t *tvb, int offset, proto_tree *pt)
{
guint32 reset_limit;
int msglen, indx;
float value;
msglen = tvb_reported_length_remaining(tvb, offset);
reset_limit = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(pt, hf_gryphon_init_strat_reset_limit, tvb, offset, 4,
reset_limit, "Reset Limit = %u messages", reset_limit);
offset += 4;
msglen -= 4;
for (indx = 1; msglen; indx++, offset++, msglen--) {
value = tvb_get_guint8(tvb, offset);
if (value)
proto_tree_add_float_format_value(pt, hf_gryphon_init_strat_delay, tvb, offset, 1,
value/4, "Delay %d = %.2f seconds", indx, value/4);
else
proto_tree_add_float_format_value(pt, hf_gryphon_init_strat_delay, tvb, offset, 1,
0, "Delay %d = infinite", indx);
}
return offset;
}
static int
speed(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_tree_add_item(pt, hf_gryphon_speed_baud_rate_index, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_reserved3, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
filter_block(tvbuff_t *tvb, int offset, proto_tree *pt)
{
unsigned int op;
int length, padding;
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_start, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_type, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_operator, tvb, offset+5, 1, ENC_BIG_ENDIAN);
op = tvb_get_guint8(tvb, offset+5);
proto_tree_add_item(pt, hf_gryphon_reserved2, tvb, offset+6, 2, ENC_BIG_ENDIAN);
offset += 8;
if (op == BIT_FIELD_CHECK) {
proto_tree_add_text(pt, tvb, offset, length, "Pattern");
proto_tree_add_text(pt, tvb, offset+length, length, "Mask");
} else {
switch (length) {
case 1:
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_value1, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_value2, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 4:
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_value4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(pt, hf_gryphon_filter_block_filter_value_bytes, tvb, offset, length, ENC_NA);
}
}
offset += length * 2;
padding = 3 - (length * 2 + 3) % 4;
if (padding) {
proto_tree_add_item(pt, hf_gryphon_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
return offset;
}
static int
blm_mode(tvbuff_t *tvb, int offset, proto_tree *pt)
{
proto_item *item;
proto_tree *tree;
int mode, milliseconds;
mode = tvb_get_ntohl(tvb, offset);
item = proto_tree_add_item(pt, hf_gryphon_blm_mode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch (mode) {
case 1:
tree = proto_item_add_subtree (item, ett_gryphon_blm_mode);
milliseconds = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_gryphon_blm_mode_avg_period, tvb, offset, 4,
milliseconds, "Averaging period: %d.%03d seconds", milliseconds/1000, milliseconds%1000);
break;
case 2:
tree = proto_item_add_subtree (item, ett_gryphon_blm_mode);
proto_tree_add_item(tree, hf_gryphon_blm_mode_avg_frames, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_text(pt, tvb, offset, 4, "Reserved");
break;
}
offset += 4;
return offset;
}
void
proto_register_gryphon(void)
{
static hf_register_info hf[] = {
{ &hf_gryphon_src,
{ "Source", "gryphon.src", FT_UINT8, BASE_HEX, VALS(src_dest), 0x0,
NULL, HFILL }},
{ &hf_gryphon_srcchan,
{ "Source channel", "gryphon.srcchan", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_dest,
{ "Destination", "gryphon.dest", FT_UINT8, BASE_HEX, VALS(src_dest), 0x0,
NULL, HFILL }},
{ &hf_gryphon_destchan,
{ "Destination channel", "gryphon.destchan", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_type,
{ "Frame type", "gryphon.type", FT_UINT8, BASE_DEC, VALS(frame_type), 0x0,
NULL, HFILL }},
{ &hf_gryphon_cmd,
{ "Command", "gryphon.cmd", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data,
{ "Data", "gryphon.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_padding,
{ "Padding", "gryphon.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_ignored,
{ "Ignored", "gryphon.ignored", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_length,
{ "Data length (bytes)", "gryphon.data_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_reserved1,
{ "Reserved", "gryphon.reserved", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_reserved2,
{ "Reserved", "gryphon.reserved", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_reserved3,
{ "Reserved", "gryphon.reserved", FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_reserved4,
{ "Reserved", "gryphon.reserved", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_reserved_bytes,
{ "Reserved", "gryphon.reserved", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_wait_resp,
{ "Wait for response", "gryphon.wait_resp", FT_BOOLEAN, 8, TFS(&tfs_wait_response), DONT_WAIT_FOR_RESP,
NULL, HFILL }},
{ &hf_gryphon_wait_prev_resp,
{ "Wait for previous response", "gryphon.wait_prev_resp", FT_BOOLEAN, 8, TFS(&tfs_wait_response), WAIT_FOR_PREV_RESP,
NULL, HFILL }},
{ &hf_gryphon_status,
{ "Status", "gryphon.status", FT_UINT32, BASE_HEX, VALS(responses_vs), 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_header_length,
{ "Header length (bytes)", "gryphon.data.header_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_data_length,
{ "Data length (bytes)", "gryphon.data.data_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_extra_data_length,
{ "Extra data length (bytes)", "gryphon.data.extra_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_mode,
{ "Mode", "gryphon.data.mode", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_mode_transmitted,
{ "Transmitted message", "gryphon.data.mode.transmitted", FT_BOOLEAN, 8, TFS(&true_false), 0x80,
NULL, HFILL }},
{ &hf_gryphon_data_mode_receive,
{ "Received message", "gryphon.data.mode.receive", FT_BOOLEAN, 8, TFS(&true_false), 0x40,
NULL, HFILL }},
{ &hf_gryphon_data_mode_local,
{ "Local message", "gryphon.data.mode.local", FT_BOOLEAN, 8, TFS(&true_false), 0x20,
NULL, HFILL }},
{ &hf_gryphon_data_mode_remote,
{ "Remote message", "gryphon.data.mode.remote", FT_BOOLEAN, 8, TFS(&true_false), 0x10,
NULL, HFILL }},
{ &hf_gryphon_data_mode_internal,
{ "Internal message", "gryphon.data.mode.internal", FT_BOOLEAN, 8, TFS(&true_false), 0x01,
NULL, HFILL }},
{ &hf_gryphon_data_priority,
{ "Priority", "gryphon.data.priority", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_error_status,
{ "Error status", "gryphon.data.error_status", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_time,
{ "Timestamp", "gryphon.data.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_context,
{ "Context", "gryphon.data.context", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_header_data,
{ "Header", "gryphon.data.header_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_data,
{ "Data", "gryphon.data.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_extra_data,
{ "Extra data", "gryphon.data.extra_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_data_padding,
{ "Padding", "gryphon.data.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_id,
{ "Event ID", "gryphon.event.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_name,
{ "Event name", "gryphon.event.name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_context,
{ "Event context", "gryphon.event.context", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_time,
{ "Timestamp", "gryphon.event.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_data,
{ "Data", "gryphon.event.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_event_padding,
{ "Padding", "gryphon.event.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_misc_data,
{ "Data", "gryphon.misc.data", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_misc_padding,
{ "Padding", "gryphon.misc.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_eventnum,
{ "Event numbers", "gryphon.eventnum", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_resp_time,
{ "Date/Time", "gryphon.resp_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_setfilt,
{ "Pass/Block flag", "gryphon.setfilt.flag", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_setfilt_length,
{ "Length of Pattern & Mask", "gryphon.setfilt.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_setfilt_discard_data,
{ "Discarded data", "gryphon.setfilt.discard_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_setfilt_padding,
{ "Padding", "gryphon.setfilt.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_ioctl,
{ "IOCTL", "gryphon.ioctl", FT_UINT32, BASE_HEX, VALS(ioctls), 0x0,
NULL, HFILL }},
{ &hf_gryphon_ioctl_data,
{ "Data", "gryphon.ioctl.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addfilt_pass,
{ "Conforming messages", "gryphon.addfilt.pass", FT_BOOLEAN, 8, TFS(&tfs_passed_blocked), FILTER_PASS_FLAG,
NULL, HFILL }},
{ &hf_gryphon_addfilt_active,
{ "Filter", "gryphon.addfilt.active", FT_BOOLEAN, 8, TFS(&active_inactive), FILTER_ACTIVE_FLAG,
NULL, HFILL }},
{ &hf_gryphon_addfilt_blocks,
{ "Number of filter blocks", "gryphon.addfilt.blocks", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addfilt_handle,
{ "Filter handle", "gryphon.addfilt.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_modfilt,
{ "Filter handle", "gryphon.modfilt", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_modfilt_action,
{ "Action", "gryphon.modfilt.action", FT_UINT8, BASE_DEC, VALS(filtacts), 0x0,
NULL, HFILL }},
{ &hf_gryphon_filthan,
{ "Number of filter handles", "gryphon.filthan", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filthan_id,
{ "Filter handle ID", "gryphon.filthan.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filthan_padding,
{ "Padding", "gryphon.filthan.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_dfiltmode,
{ "Filter mode", "gryphon.dfiltmode", FT_UINT8, BASE_DEC, VALS(dmodes), 0x0,
NULL, HFILL }},
{ &hf_gryphon_filtmode,
{ "Filter mode", "gryphon.filtmode", FT_UINT8, BASE_DEC, VALS(modes), 0x0,
NULL, HFILL }},
{ &hf_gryphon_register_username,
{ "Username", "gryphon.register.username", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_register_password,
{ "Password", "gryphon.register.password", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_register_client_id,
{ "Client ID", "gryphon.register.client_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_register_privileges,
{ "Privileges", "gryphon.register.privileges", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_getspeeds_set_ioctl,
{ "Set Speed IOCTL", "gryphon.getspeeds.set_ioctl", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_getspeeds_get_ioctl,
{ "Get Speed IOCTL", "gryphon.getspeeds.get_ioctl", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_getspeeds_size,
{ "Speed data size (bytes)", "gryphon.getspeeds.size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_getspeeds_preset,
{ "Preset speed numbers", "gryphon.getspeeds.preset", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_getspeeds_data,
{ "Data for preset", "gryphon.getspeeds.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_cmd_sort,
{ "Set sorting", "gryphon.cmd_sort", FT_UINT8, BASE_DEC, VALS(cmd_sort_type), 0x0,
NULL, HFILL }},
{ &hf_gryphon_cmd_optimize,
{ "Set optimization", "gryphon.cmd_optimize", FT_UINT8, BASE_DEC, VALS(cmd_optimize_type), 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_device_name,
{ "Device name", "gryphon.config.device_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_device_version,
{ "Device version", "gryphon.config.device_version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_device_serial_number,
{ "Device serial number", "gryphon.config.device_serial_number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_num_channels,
{ "Number of channels", "gryphon.config.num_channels", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_name_version_ext,
{ "Name & version extension", "gryphon.config.name_version_ext", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_driver_name,
{ "Driver name", "gryphon.config.driver_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_driver_version,
{ "Driver version", "gryphon.config.driver_version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_device_security,
{ "Device security string", "gryphon.config.device_security", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_max_data_length,
{ "Maximum data length (bytes)", "gryphon.config.max_data_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_min_data_length,
{ "Minimum data length (bytes)", "gryphon.config.min_data_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_hardware_serial_number,
{ "Hardware serial number", "gryphon.config.hardware_serial_number", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_protocol_type,
{ "Protocol type & subtype", "gryphon.config.protocol_type", FT_UINT16, BASE_HEX, VALS(protocol_types), 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_channel_id,
{ "Channel ID", "gryphon.config.channel_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_card_slot_number,
{ "Card slot number", "gryphon.config.card_slot_number", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_max_extra_data,
{ "Maximum extra data (bytes)", "gryphon.config.max_extra_data", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_config_min_extra_data,
{ "Minimum extra data (bytes)", "gryphon.config.min_extra_data", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_num_iterations,
{ "Number of iterations", "gryphon.sched.num_iterations", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_flags,
{ "Flags", "gryphon.sched.flags", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_flags_scheduler,
{ "Scheduler", "gryphon.sched.flags.scheduler", FT_BOOLEAN, 32, TFS(&critical_normal), 0x01,
NULL, HFILL }},
{ &hf_gryphon_sched_sleep,
{ "Sleep (milliseconds)", "gryphon.sched.sleep", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_transmit_count,
{ "Transmit count", "gryphon.sched.transmit_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_transmit_period,
{ "Transmit period (milliseconds)", "gryphon.sched.transmit_period", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_transmit_flags,
{ "Flags", "gryphon.sched.transmit_flags", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_skip_transmit_period,
{ "Last transmit period", "gryphon.sched.skip_transmit_period", FT_BOOLEAN, 16, TFS(&skip_not_skip), 0x01,
NULL, HFILL }},
{ &hf_gryphon_sched_skip_sleep,
{ "Last transmit period", "gryphon.sched.skip_transmit_period", FT_BOOLEAN, 16, TFS(&skip_not_skip), 0x01,
NULL, HFILL }},
{ &hf_gryphon_sched_channel,
{ "Channel", "gryphon.sched.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_rep_id,
{ "Schedule ID", "gryphon.sched.rep_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_sched_rep_message_index,
{ "Message index", "gryphon.sched.rep_message_index", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_data_time,
{ "Timestamp", "gryphon.blm_data.time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_data_bus_load,
{ "Bus load average (%)", "gryphon.blm_data.bus_load", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_data_current_bus_load,
{ "Current bus load (%)", "gryphon.blm_data.current_bus_load", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_data_peak_bus_load,
{ "Peak bus load (%)", "gryphon.blm_data.peak_bus_load", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_data_historic_peak_bus_load,
{ "Historic peak bus load (%)", "gryphon.blm_data.historic_peak_bus_load", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_receive_frame_count,
{ "Receive frame count", "gryphon.blm_stat.receive_frame_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_transmit_frame_count,
{ "Transmit frame count", "gryphon.blm_stat.transmit_frame_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_receive_dropped_frame_count,
{ "Receive dropped frame count", "gryphon.blm_stat.receive_dropped_frame_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_transmit_dropped_frame_count,
{ "Transmit dropped frame count", "gryphon.blm_stat.transmit_dropped_frame_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_receive_error_count,
{ "Receive error count", "gryphon.blm_stat.receive_error_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_stat_transmit_error_count,
{ "Transmit error count", "gryphon.blm_stat.transmit_error_count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_flags,
{ "Flags", "gryphon.addresp.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_flags_active,
{ "Response", "gryphon.addresp.flags.active", FT_BOOLEAN, 8, TFS(&active_inactive), FILTER_ACTIVE_FLAG,
NULL, HFILL }},
{ &hf_gryphon_addresp_blocks,
{ "Number of filter blocks", "gryphon.addresp.blocks", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_responses,
{ "Number of response blocks", "gryphon.addresp.responses", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_old_handle,
{ "Old handle", "gryphon.addresp.old_handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_action,
{ "Old handle", "gryphon.addresp.action", FT_UINT8, BASE_DEC, VALS(action_vals), 0x07,
NULL, HFILL }},
{ &hf_gryphon_addresp_action_period,
{ "Period", "gryphon.addresp.action_period", FT_BOOLEAN, 8, TFS(&frames_01seconds), FR_PERIOD_MSGS,
NULL, HFILL }},
{ &hf_gryphon_addresp_action_deact_on_event,
{ "Deact on event", "gryphon.addresp.action.deact_on_event", FT_UINT8, BASE_DEC, VALS(deact_on_event_vals), FR_DELETE|FR_DEACT_ON_EVENT,
NULL, HFILL }},
{ &hf_gryphon_addresp_action_deact_after_period,
{ "Deact on Period", "gryphon.addresp.action.deact_after_period", FT_UINT8, BASE_DEC, VALS(deact_after_per_vals), FR_DELETE|FR_DEACT_AFTER_PER,
NULL, HFILL }},
{ &hf_gryphon_addresp_action_period_type,
{ "Period", "gryphon.addresp.action_period_type", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_addresp_handle,
{ "Response handle", "gryphon.addresp.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_modresp_handle,
{ "Response handle", "gryphon.modresp.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_modresp_action,
{ "Action response", "gryphon.modresp.action", FT_UINT8, BASE_DEC, VALS(filtacts), 0x0,
NULL, HFILL }},
{ &hf_gryphon_num_resphan,
{ "Number of response handles", "gryphon.num_resphan", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_transmit_sched_id,
{ "Transmit schedule ID", "gryphon.transmit_sched_id", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_desc_program_size,
{ "Program size", "gryphon.desc.program_size", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_desc_program_name,
{ "Program name", "gryphon.desc.program_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_desc_program_description,
{ "Program description", "gryphon.desc.program_description", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_desc_flags,
{ "Flags", "gryphon.desc.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_desc_flags_program,
{ "Period", "gryphon.desc.flags.program", FT_BOOLEAN, 8, TFS(&present_not_present), 0x01,
NULL, HFILL }},
{ &hf_gryphon_desc_handle,
{ "Handle", "gryphon.desc.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_upload_block_number,
{ "Block number", "gryphon.upload.block_number", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_upload_handle,
{ "Handle", "gryphon.upload.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_upload_data,
{ "Data", "gryphon.upload.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_delete,
{ "Program name", "gryphon.delete", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_list_block_number,
{ "Block number", "gryphon.list.block_number", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_list_num_programs,
{ "Number of programs in this response", "gryphon.list.num_programs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_list_num_remain_programs,
{ "Number of remaining programs", "gryphon.list.num_remain_programs", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_list_name,
{ "Name", "gryphon.list.name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_list_description,
{ "Description", "gryphon.list.description", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_start_arguments,
{ "Arguments", "gryphon.start.arguments", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_start_channel,
{ "Channel (Client) number", "gryphon.start.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_status_num_running_copies,
{ "Number of running copies", "gryphon.status.num_running_copies", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_options_handle,
{ "Handle", "gryphon.options.handle", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_files,
{ "Directory", "gryphon.files", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_flags_register,
{ "USDT", "gryphon.usdt.flags_register", FT_UINT8, BASE_DEC, VALS(register_unregister), 0x01,
NULL, HFILL }},
{ &hf_gryphon_usdt_action_flags,
{ "Action Flags", "gryphon.usdt.action_flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_action_flags_register,
{ "Register", "gryphon.usdt.action_flags.register", FT_UINT8, BASE_DEC, VALS(register_unregister), 0x01,
NULL, HFILL }},
{ &hf_gryphon_usdt_action_flags_action,
{ "Action", "gryphon.usdt.action_flags.action", FT_UINT8, BASE_DEC, VALS(usdt_action_vals), 0x06,
NULL, HFILL }},
{ &hf_gryphon_usdt_transmit_options_flags,
{ "Transmit options", "gryphon.usdt.transmit_options_flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_transmit_options_flags_echo,
{ "Echo long transmit messages back to the client", "gryphon.usdt.transmit_options_flags.echo",
FT_BOOLEAN, 8, TFS(&yes_no), 0x01, NULL, HFILL }},
{ &hf_gryphon_usdt_transmit_options_action,
{ "Transmit Action", "gryphon.usdt.transmit_options_flags.action", FT_UINT8, BASE_DEC, VALS(xmit_opt_vals), 0x06,
NULL, HFILL }},
{ &hf_gryphon_usdt_transmit_options_send_done,
{ "Send a USDT_DONE event when the last frame of a multi-frame USDT message is transmitted",
"gryphon.usdt.transmit_options_flags.send_done", FT_BOOLEAN, 8, TFS(&yes_no), 0x08, NULL, HFILL }},
{ &hf_gryphon_usdt_receive_options_flags,
{ "Receive options", "gryphon.usdt.receive_options_flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_receive_options_action,
{ "Receive Action", "gryphon.usdt.receive_options_flags.action", FT_UINT8, BASE_DEC, VALS(recv_opt_vals), 0x03,
NULL, HFILL }},
{ &hf_gryphon_usdt_receive_options_firstframe,
{ "Send a USDT_FIRSTFRAME event when the first frame of a multi-frame USDT message is received",
"gryphon.usdt.receive_options_flags.firstframe", FT_BOOLEAN, 8, TFS(&yes_no), 0x04, NULL, HFILL }},
{ &hf_gryphon_usdt_receive_options_lastframe,
{ "Send a USDT_LASTFRAME event when the first frame of a multi-frame USDT message is received",
"gryphon.usdt.receive_options_flags.lastframe", FT_BOOLEAN, 8, TFS(&yes_no), 0x08, NULL, HFILL }},
{ &hf_gryphon_usdt_ext_address,
{ "Using extended addressing for", "gryphon.usdt.ext_address", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_ext_address_id,
{ "ID", "gryphon.usdt.ext_address.id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_usdt_block_size,
{ "Number of IDs in the block", "gryphon.usdt.block_size", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_bits_in_input1,
{ "Input 1", "gryphon.bits_in.input1", FT_BOOLEAN, 8, TFS(&set_not_set), 0x01,
NULL, HFILL }},
{ &hf_gryphon_bits_in_input2,
{ "Input 2", "gryphon.bits_in.input2", FT_BOOLEAN, 8, TFS(&set_not_set), 0x02,
NULL, HFILL }},
{ &hf_gryphon_bits_in_input3,
{ "Input 3", "gryphon.bits_in.input3", FT_BOOLEAN, 8, TFS(&set_not_set), 0x04,
NULL, HFILL }},
{ &hf_gryphon_bits_in_pushbutton,
{ "Pushbutton", "gryphon.bits_in.pushbutton", FT_BOOLEAN, 8, TFS(&set_not_set), 0x08,
NULL, HFILL }},
{ &hf_gryphon_bits_out_output1,
{ "Input 1", "gryphon.bits_out.output1", FT_BOOLEAN, 8, TFS(&set_not_set), 0x01,
NULL, HFILL }},
{ &hf_gryphon_bits_out_output2,
{ "Input 2", "gryphon.bits_out.output2", FT_BOOLEAN, 8, TFS(&set_not_set), 0x02,
NULL, HFILL }},
{ &hf_gryphon_init_strat_reset_limit,
{ "Reset Limit", "gryphon.init_strat.reset_limit", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_init_strat_delay,
{ "Delay", "gryphon.init_strat.strat_delay", FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_speed_baud_rate_index,
{ "Baud rate index", "gryphon.speed.baud_rate_index", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_start,
{ "Filter field starts at byte", "gryphon.filter_block.filter_start", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_length,
{ "Filter field length", "gryphon.filter_block.filter_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_type,
{ "Filtering on", "gryphon.filter_block.filter_type", FT_UINT8, BASE_DEC, VALS(filter_data_types), 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_operator,
{ "Type of comparison", "gryphon.filter_block.filter_operator", FT_UINT8, BASE_DEC, VALS(operators), 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_value1,
{ "Value", "gryphon.filter_block.filter_value", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_value2,
{ "Value", "gryphon.filter_block.filter_value", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_value4,
{ "Value", "gryphon.filter_block.filter_value", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_filter_block_filter_value_bytes,
{ "Value", "gryphon.filter_block.filter_value_bytes", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_mode,
{ "Mode", "gryphon.blm_mode", FT_UINT32, BASE_DEC, VALS(blm_mode_vals), 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_mode_avg_period,
{ "Averaging period (seconds)", "gryphon.blm_mode.avg_period", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_gryphon_blm_mode_avg_frames,
{ "Averaging period (frames)", "gryphon.blm_mode.avg_frames", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_gryphon,
&ett_gryphon_header,
&ett_gryphon_body,
&ett_gryphon_command_data,
&ett_gryphon_response_data,
&ett_gryphon_data_header,
&ett_gryphon_flags,
&ett_gryphon_data_body,
&ett_gryphon_cmd_filter_block,
&ett_gryphon_cmd_events_data,
&ett_gryphon_cmd_config_device,
&ett_gryphon_cmd_sched_data,
&ett_gryphon_cmd_sched_cmd,
&ett_gryphon_cmd_response_block,
&ett_gryphon_pgm_list,
&ett_gryphon_pgm_status,
&ett_gryphon_pgm_options,
&ett_gryphon_valid_headers,
&ett_gryphon_usdt_data,
&ett_gryphon_usdt_data_block,
&ett_gryphon_digital_data,
&ett_gryphon_blm_mode
};
module_t *gryphon_module;
proto_gryphon = proto_register_protocol("DG Gryphon Protocol",
"Gryphon",
"gryphon");
proto_register_field_array(proto_gryphon, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
gryphon_module = prefs_register_protocol(proto_gryphon, NULL);
prefs_register_bool_preference(gryphon_module, "desegment",
"Desegment all Gryphon messages spanning multiple TCP segments",
"Whether the Gryphon dissector should desegment all messages spanning multiple TCP segments",
&gryphon_desegment);
}
void
proto_reg_handoff_gryphon(void)
{
dissector_handle_t gryphon_handle;
gryphon_handle = new_create_dissector_handle(dissect_gryphon, proto_gryphon);
dissector_add_uint("tcp.port", 7000, gryphon_handle);
}
