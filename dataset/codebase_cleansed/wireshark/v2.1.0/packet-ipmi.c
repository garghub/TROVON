static ipmi_packet_data_t *
get_packet_data(packet_info * pinfo)
{
ipmi_packet_data_t * data;
conversation_t * conv = find_or_create_conversation(pinfo);
data = (ipmi_packet_data_t *)
conversation_get_proto_data(conv, proto_ipmi);
if (!data) {
data = wmem_new0(wmem_file_scope(), ipmi_packet_data_t);
data->frame_tree = wmem_tree_new(wmem_file_scope());
data->request_list = wmem_list_new(wmem_file_scope());
conversation_add_proto_data(conv, proto_ipmi, data);
}
if (pinfo->num != data->curr_frame_num) {
data->curr_level = 0;
data->next_level = 0;
}
return data;
}
static ipmi_frame_data_t *
get_frame_data(ipmi_packet_data_t * data, guint32 frame_num)
{
ipmi_frame_data_t * frame = (ipmi_frame_data_t *)
wmem_tree_lookup32(data->frame_tree, frame_num);
if (frame == NULL) {
frame = wmem_new0(wmem_file_scope(), ipmi_frame_data_t);
wmem_tree_insert32(data->frame_tree, frame_num, frame);
}
return frame;
}
static ipmi_request_t *
get_matched_request(ipmi_packet_data_t * data, const ipmi_header_t * rs_hdr,
guint flags)
{
wmem_list_frame_t * iter = wmem_list_head(data->request_list);
ipmi_header_t rq_hdr;
rq_hdr.context = 0;
rq_hdr.channel = data->curr_channel;
rq_hdr.dir = rs_hdr->dir ^ 1;
rq_hdr.session = rs_hdr->session;
rq_hdr.rs_sa = rs_hdr->rq_sa;
rq_hdr.rs_lun = rs_hdr->rq_lun;
rq_hdr.netfn = rs_hdr->netfn & ~1;
rq_hdr.rq_sa = rs_hdr->rs_sa;
rq_hdr.rq_lun = rs_hdr->rs_lun;
rq_hdr.rq_seq = rs_hdr->rq_seq;
rq_hdr.cmd = rs_hdr->cmd;
#ifdef DEBUG
fprintf(stderr, "%d, %d: rq_hdr : {\n"
"\tchannel=%d\n"
"\tdir=%d\n"
"\trs_sa=%x\n"
"\trs_lun=%d\n"
"\tnetfn=%x\n"
"\trq_sa=%x\n"
"\trq_lun=%d\n"
"\trq_seq=%x\n"
"\tcmd=%x\n}\n",
data->curr_frame_num, data->curr_level,
rq_hdr.channel, rq_hdr.dir, rq_hdr.rs_sa, rq_hdr.rs_lun,
rq_hdr.netfn, rq_hdr.rq_sa, rq_hdr.rq_lun, rq_hdr.rq_seq,
rq_hdr.cmd);
#endif
while (iter) {
ipmi_request_t * rq = (ipmi_request_t *) wmem_list_frame_data(iter);
if (rs_hdr->context == IPMI_E_GETMSG && !(flags & IPMI_D_TRG_SA)) {
rq_hdr.rq_sa = rq->hdr.rq_sa;
}
if (!memcmp(&rq_hdr, &rq->hdr, sizeof(rq_hdr))) {
return rq;
}
iter = wmem_list_frame_next(iter);
}
return NULL;
}
static void
remove_old_requests(ipmi_packet_data_t * data, const nstime_t * curr_time)
{
wmem_list_frame_t * iter = wmem_list_head(data->request_list);
while (iter) {
ipmi_request_t * rq = (ipmi_request_t *) wmem_list_frame_data(iter);
ipmi_frame_data_t * frame = get_frame_data(data, rq->frame_num);
nstime_t delta;
nstime_delta(&delta, curr_time, &frame->ts);
if (nstime_to_msec(&delta) > response_after_req) {
wmem_list_frame_t * del = iter;
iter = wmem_list_frame_next(iter);
wmem_free(wmem_file_scope(), rq);
wmem_list_remove_frame(data->request_list, del);
} else {
break;
}
}
}
static void
match_request_response(ipmi_packet_data_t * data, const ipmi_header_t * hdr,
guint flags)
{
ipmi_frame_data_t * rs_frame = data->curr_frame;
ipmi_cmd_data_t * rs_data = rs_frame->cmd_data[data->curr_level];
if (!rs_data) {
ipmi_request_t * rq;
rs_data = wmem_new0(wmem_file_scope(), ipmi_cmd_data_t);
rq = get_matched_request(data, hdr, flags);
if (rq) {
ipmi_frame_data_t * rq_frame =
get_frame_data(data, rq->frame_num);
ipmi_cmd_data_t * rq_data = rq_frame->cmd_data[rq->nest_level];
rq_data->matched_frame_num = data->curr_frame_num;
rs_data->matched_frame_num = rq->frame_num;
rs_data->saved_data[0] = rq_data->saved_data[0];
rs_data->saved_data[1] = rq_data->saved_data[1];
wmem_list_remove(data->request_list, rq);
wmem_free(wmem_file_scope(), rq);
}
rs_frame->cmd_data[data->curr_level] = rs_data;
}
}
static void
add_request(ipmi_packet_data_t * data, const ipmi_header_t * hdr)
{
ipmi_frame_data_t * rq_frame = data->curr_frame;
ipmi_cmd_data_t * rq_data = rq_frame->cmd_data[data->curr_level];
if (!rq_data) {
ipmi_request_t * rq;
rq_data = wmem_new0(wmem_file_scope(), ipmi_cmd_data_t);
rq_frame->cmd_data[data->curr_level] = rq_data;
rq = wmem_new0(wmem_file_scope(), ipmi_request_t);
memcpy(&rq->hdr, hdr, sizeof(rq->hdr));
rq->hdr.context = 0;
rq->hdr.channel = data->curr_channel;
rq->hdr.dir = data->curr_dir;
rq->frame_num = data->curr_frame_num;
rq->nest_level = data->curr_level;
wmem_list_append(data->request_list, rq);
#ifdef DEBUG
fprintf(stderr, "%d, %d: hdr : {\n"
"\tchannel=%d\n"
"\tdir=%d\n"
"\trs_sa=%x\n"
"\trs_lun=%d\n"
"\tnetfn=%x\n"
"\trq_sa=%x\n"
"\trq_lun=%d\n"
"\trq_seq=%x\n"
"\tcmd=%x\n}\n",
data->curr_frame_num, data->curr_level,
rq->hdr.channel, rq->hdr.dir, rq->hdr.rs_sa, rq->hdr.rs_lun,
rq->hdr.netfn, rq->hdr.rq_sa, rq->hdr.rq_lun, rq->hdr.rq_seq,
rq->hdr.cmd);
#endif
}
}
static void
add_command_info(packet_info *pinfo, ipmi_cmd_t * cmd,
gboolean resp, guint8 cc_val, const char * cc_str, gboolean broadcast)
{
if (resp) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Rsp, %s, %s (%02xh)",
cmd->desc, cc_str, cc_val);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "Req, %s%s",
broadcast ? "Broadcast " : "", cmd->desc);
}
}
static int
dissect_ipmi_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint hf_parent_item, gint ett_tree, const ipmi_context_t * ctx)
{
ipmi_packet_data_t * data;
ipmi_netfn_t * cmd_list;
ipmi_cmd_t * cmd;
proto_item * ti;
proto_tree * cmd_tree = NULL, * tmp_tree;
guint8 prev_level, cc_val;
guint offset, siglen, is_resp;
const char * cc_str, * netfn_str;
data = get_packet_data(pinfo);
if (!data) {
return 0;
}
siglen = ipmi_getsiglen(ctx->hdr.netfn);
is_resp = ctx->hdr.netfn & 1;
if (tvb_captured_length(tvb) < ctx->hdr_len + siglen + is_resp
+ !(ctx->flags & IPMI_D_NO_CKS)) {
return call_data_dissector(tvb, pinfo, tree);
}
prev_level = data->curr_level;
data->curr_level = data->next_level;
data->next_level++;
if (!data->curr_level) {
data->curr_frame = get_frame_data(data, pinfo->num);
data->curr_frame_num = pinfo->num;
memcpy(&data->curr_frame->ts, &pinfo->abs_ts, sizeof(nstime_t));
data->curr_channel = ctx->hdr.channel;
data->curr_dir = ctx->hdr.dir;
remove_old_requests(data, &pinfo->abs_ts);
}
if (data->curr_level < MAX_NEST_LEVEL) {
if (ctx->hdr.netfn & 1) {
match_request_response(data, &ctx->hdr, ctx->flags);
} else {
add_request(data, &ctx->hdr);
}
}
cmd_list = ipmi_getnetfn(ctx->hdr.netfn,
tvb_get_ptr(tvb, ctx->hdr_len + is_resp, siglen));
cmd = ipmi_getcmd(cmd_list, ctx->hdr.cmd);
if (is_resp) {
cc_val = tvb_get_guint8(tvb, ctx->hdr_len);
cc_str = ipmi_get_completion_code(cc_val, cmd);
} else {
cc_val = 0;
cc_str = NULL;
}
if (!data->curr_level) {
add_command_info(pinfo, cmd, is_resp, cc_val, cc_str,
ctx->flags & IPMI_D_BROADCAST ? TRUE : FALSE);
}
if (tree) {
if (!data->curr_level) {
ti = proto_tree_add_item(tree, hf_parent_item, tvb, 0, -1, ENC_NA);
cmd_tree = proto_item_add_subtree(ti, ett_tree);
} else {
char str[ITEM_LABEL_LENGTH];
if (is_resp) {
g_snprintf(str, ITEM_LABEL_LENGTH, "Rsp, %s, %s",
cmd->desc, cc_str);
} else {
g_snprintf(str, ITEM_LABEL_LENGTH, "Req, %s", cmd->desc);
}
if (proto_registrar_get_ftype(hf_parent_item) == FT_STRING) {
ti = proto_tree_add_string(tree, hf_parent_item, tvb, 0, -1, str);
cmd_tree = proto_item_add_subtree(ti, ett_tree);
}
else
cmd_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_tree, NULL, str);
}
if (data->curr_level < MAX_NEST_LEVEL) {
if (ctx->hdr.netfn & 1) {
ipmi_cmd_data_t * rs_data =
data->curr_frame->cmd_data[data->curr_level];
if (rs_data->matched_frame_num) {
nstime_t ns;
ti = proto_tree_add_uint(cmd_tree, hf_ipmi_response_to,
tvb, 0, 0, rs_data->matched_frame_num);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&ns, &pinfo->abs_ts,
&get_frame_data(data,
rs_data->matched_frame_num)->ts);
ti = proto_tree_add_time(cmd_tree, hf_ipmi_response_time,
tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(ti);
}
} else {
ipmi_cmd_data_t * rq_data =
data->curr_frame->cmd_data[data->curr_level];
if (rq_data->matched_frame_num) {
ti = proto_tree_add_uint(cmd_tree, hf_ipmi_response_in,
tvb, 0, 0, rq_data->matched_frame_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
offset = 0;
if (ctx->flags & IPMI_D_BROADCAST) {
offset++;
}
if (ctx->flags & IPMI_D_SESSION_HANDLE) {
proto_tree_add_item(cmd_tree, hf_ipmi_session_handle,
tvb, offset++, 1, ENC_LITTLE_ENDIAN);
}
if (ctx->flags & IPMI_D_TRG_SA) {
proto_tree_add_item(cmd_tree, hf_ipmi_header_trg, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
}
netfn_str = ipmi_getnetfnname(ctx->hdr.netfn, cmd_list);
tmp_tree = proto_tree_add_subtree_format(cmd_tree, tvb, offset, 1,
ett_header_byte_1, NULL, "Target LUN: 0x%02x, NetFN: %s %s (0x%02x)",
ctx->hdr.rs_lun, netfn_str,
is_resp ? "Response" : "Request", ctx->hdr.netfn);
proto_tree_add_uint_format(tmp_tree, hf_ipmi_header_netfn, tvb,
offset, 1, ctx->hdr.netfn << 2,
"NetFn: %s %s (0x%02x)", netfn_str,
is_resp ? "Response" : "Request", ctx->hdr.netfn);
proto_tree_add_item(tmp_tree, hf_ipmi_header_trg_lun, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
if (!(ctx->flags & IPMI_D_NO_CKS)) {
guint8 cks = tvb_get_guint8(tvb, offset);
if (ctx->cks1) {
guint8 correct = cks - ctx->cks1;
proto_tree_add_uint_format_value(cmd_tree, hf_ipmi_header_crc,
tvb, offset++, 1, cks,
"0x%02x (incorrect, expected 0x%02x)", cks, correct);
} else {
proto_tree_add_uint_format_value(cmd_tree, hf_ipmi_header_crc,
tvb, offset++, 1, cks,
"0x%02x (correct)", cks);
}
}
if (!(ctx->flags & IPMI_D_NO_RQ_SA)) {
proto_tree_add_item(cmd_tree, hf_ipmi_header_src, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
}
if (!(ctx->flags & IPMI_D_NO_SEQ)) {
tmp_tree = proto_tree_add_subtree_format(cmd_tree, tvb, offset, 1,
ett_header_byte_4, NULL, "%s: 0x%02x, SeqNo: 0x%02x",
(ctx->flags & IPMI_D_TMODE) ? "Bridged" : "Source LUN",
ctx->hdr.rq_lun, ctx->hdr.rq_seq);
if (ctx->flags & IPMI_D_TMODE) {
proto_tree_add_item(tmp_tree, hf_ipmi_header_bridged,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tmp_tree, hf_ipmi_header_src_lun,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(tmp_tree, hf_ipmi_header_sequence, tvb,
offset++, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_uint_format_value(cmd_tree, hf_ipmi_header_command,
tvb, offset++, 1, ctx->hdr.cmd, "%s (0x%02x)",
cmd->desc, ctx->hdr.cmd);
if (is_resp) {
proto_tree_add_uint_format_value(cmd_tree,
hf_ipmi_header_completion, tvb, offset++, 1,
cc_val, "%s (0x%02x)", cc_str, cc_val);
}
if (siglen) {
ti = proto_tree_add_item(cmd_tree, hf_ipmi_header_sig, tvb,
offset, siglen, ENC_NA);
proto_item_append_text(ti, " (%s)", netfn_str);
}
}
if (tree || (cmd->flags & CMD_CALLRQ)) {
guint data_len = tvb_captured_length(tvb)
- ctx->hdr_len
- siglen
- (is_resp ? 1 : 0)
- !(ctx->flags & IPMI_D_NO_CKS);
tvbuff_t * data_tvb = tvb_new_subset_length(tvb,
ctx->hdr_len + siglen + (is_resp ? 1 : 0), data_len);
ipmi_cmd_handler_t hnd = is_resp ? cmd->parse_resp : cmd->parse_req;
if (hnd && tvb_captured_length(data_tvb)) {
tmp_tree = proto_tree_add_subtree(cmd_tree, data_tvb, 0, -1, ett_data, NULL, "Data");
data->curr_hdr = &ctx->hdr;
data->curr_ccode = cc_val;
hnd(data_tvb, pinfo, tmp_tree);
}
}
if (tree && !(ctx->flags & IPMI_D_NO_CKS)) {
guint8 cks;
offset = tvb_captured_length(tvb) - 1;
cks = tvb_get_guint8(tvb, offset);
if (ctx->cks2) {
guint8 correct = cks - ctx->cks2;
proto_tree_add_uint_format_value(cmd_tree, hf_ipmi_data_crc,
tvb, offset, 1, cks,
"0x%02x (incorrect, expected 0x%02x)", cks, correct);
} else {
proto_tree_add_uint_format_value(cmd_tree, hf_ipmi_data_crc,
tvb, offset, 1, cks,
"0x%02x (correct)", cks);
}
}
data->next_level = data->curr_level;
data->curr_level = prev_level;
return tvb_captured_length(tvb);
}
const ipmi_header_t * ipmi_get_hdr(packet_info * pinfo)
{
ipmi_packet_data_t * data = get_packet_data(pinfo);
return data->curr_hdr;
}
guint8 ipmi_get_ccode(packet_info * pinfo)
{
ipmi_packet_data_t * data = get_packet_data(pinfo);
return data->curr_ccode;
}
void ipmi_set_data(packet_info *pinfo, guint idx, guint32 value)
{
ipmi_packet_data_t * data = get_packet_data(pinfo);
if (data->curr_level >= MAX_NEST_LEVEL || idx >= NSAVED_DATA ) {
return;
}
data->curr_frame->cmd_data[data->curr_level]->saved_data[idx] = value;
}
gboolean ipmi_get_data(packet_info *pinfo, guint idx, guint32 * value)
{
ipmi_packet_data_t * data = get_packet_data(pinfo);
if (data->curr_level >= MAX_NEST_LEVEL || idx >= NSAVED_DATA ) {
return FALSE;
}
*value = data->curr_frame->cmd_data[data->curr_level]->saved_data[idx];
return TRUE;
}
static void
get_len_binary(guint *clen, guint *blen, tvbuff_t *tvb _U_, guint offs _U_,
guint len, gboolean len_is_bytes _U_)
{
*clen = len * 3;
*blen = len;
}
static void
parse_binary(char *p, tvbuff_t *tvb, guint offs, guint len)
{
static const char hex[] = "0123456789ABCDEF";
guint8 v;
guint i;
for (i = 0; i < len / 3; i++) {
v = tvb_get_guint8(tvb, offs + i);
*p++ = hex[v >> 4];
*p++ = hex[v & 0xf];
*p++ = ' ';
}
if (i) {
*--p = '\0';
}
}
static void
get_len_bcdplus(guint *clen, guint *blen, tvbuff_t *tvb _U_, guint offs _U_,
guint len, gboolean len_is_bytes)
{
if (len_is_bytes) {
*clen = len * 2;
*blen = len;
} else {
*blen = (len + 1) / 2;
*clen = len;
}
}
static void
parse_bcdplus(char *p, tvbuff_t *tvb, guint offs, guint len)
{
static const char bcd[] = "0123456789 -.:,_";
guint i, msk = 0xf0, shft = 4;
guint8 v;
for (i = 0; i < len; i++) {
v = (tvb_get_guint8(tvb, offs + i / 2) & msk) >> shft;
*p++ = bcd[v];
msk ^= 0xff;
shft = 4 - shft;
}
}
static void
get_len_6bit_ascii(guint *clen, guint *blen, tvbuff_t *tvb _U_, guint offs _U_,
guint len, gboolean len_is_bytes)
{
if (len_is_bytes) {
*clen = len * 4 / 3;
*blen = len;
} else {
*blen = (len * 3 + 3) / 4;
*clen = len;
}
}
static void
parse_6bit_ascii(char *p, tvbuff_t *tvb, guint offs, guint len)
{
guint32 v;
guint i;
for (i = 0; i < len / 4; i++) {
v = tvb_get_letoh24(tvb, offs + i * 3);
p[0] = ' ' + (v & 0x3f);
p[1] = ' ' + ((v >> 6) & 0x3f);
p[2] = ' ' + ((v >> 12) & 0x3f);
p[3] = ' ' + ((v >> 18) & 0x3f);
p += 4;
}
offs += len / 4;
len &= 0x3;
switch (len) {
case 3:
v = (tvb_get_guint8(tvb, offs + 2) << 4) | (tvb_get_guint8(tvb, offs + 1) >> 4);
p[2] = ' ' + (v & 0x3f);
case 2:
v = (tvb_get_guint8(tvb, offs + 1) << 2) | (tvb_get_guint8(tvb, offs) >> 6);
p[1] = ' ' + (v & 0x3f);
case 1:
v = tvb_get_guint8(tvb, offs) & 0x3f;
p[0] = ' ' + (v & 0x3f);
}
}
static void
get_len_8bit_ascii(guint *clen, guint *blen, tvbuff_t *tvb, guint offs,
guint len, gboolean len_is_bytes _U_)
{
guint i;
guint8 ch;
*blen = len;
*clen = 0;
for (i = 0; i < len; i++) {
ch = tvb_get_guint8(tvb, offs + i);
*clen += (ch >= 0x20 && ch <= 0x7f) ? 1 : 4;
}
}
static void
parse_8bit_ascii(char *p, tvbuff_t *tvb, guint offs, guint len)
{
guint8 ch;
char *pmax;
pmax = p + len;
while (p < pmax) {
ch = tvb_get_guint8(tvb, offs++);
if (ch >= 0x20 && ch <= 0x7f) {
*p++ = ch;
} else {
g_snprintf(p, 5, "\\x%02x", ch);
p += 4;
}
}
}
static void
get_len_unicode(guint *clen, guint *blen, tvbuff_t *tvb _U_, guint offs _U_,
guint len _U_, gboolean len_is_bytes)
{
if (len_is_bytes) {
*clen = len * 3;
*blen = len;
} else {
*clen = len * 6;
*blen = len * 2;
}
}
static void
parse_unicode(char *p, tvbuff_t *tvb, guint offs, guint len)
{
char *pmax = p + len;
guint8 ch0, ch1;
while (p < pmax) {
ch0 = tvb_get_guint8(tvb, offs++);
ch1 = tvb_get_guint8(tvb, offs++);
g_snprintf(p, 7, "\\U%02x%02x", ch0, ch1);
p += 6;
}
}
void
ipmi_add_typelen(proto_tree *tree, int hf_string, int hf_type, int hf_length, tvbuff_t *tvb,
guint offs, gboolean is_fru)
{
static struct ipmi_parse_typelen *fru_eng[4] = {
&ptl_binary, &ptl_bcdplus, &ptl_6bit_ascii, &ptl_8bit_ascii
};
static struct ipmi_parse_typelen *fru_noneng[4] = {
&ptl_binary, &ptl_bcdplus, &ptl_6bit_ascii, &ptl_unicode
};
static struct ipmi_parse_typelen *ipmi[4] = {
&ptl_unicode, &ptl_bcdplus, &ptl_6bit_ascii, &ptl_8bit_ascii
};
struct ipmi_parse_typelen *ptr;
proto_tree *s_tree;
guint type, msk, clen, blen, len;
const char *unit;
char *str;
guint8 typelen;
typelen = tvb_get_guint8(tvb, offs);
type = typelen >> 6;
if (is_fru) {
msk = 0x3f;
ptr = (fru_langcode_is_english ? fru_eng : fru_noneng)[type];
unit = "bytes";
} else {
msk = 0x1f;
ptr = ipmi[type];
unit = "characters";
}
len = typelen & msk;
ptr->get_len(&clen, &blen, tvb, offs + 1, len, is_fru);
str = (char *)wmem_alloc(wmem_packet_scope(), clen + 1);
ptr->parse(str, tvb, offs + 1, clen);
str[clen] = '\0';
s_tree = proto_tree_add_subtree_format(tree, tvb, offs, 1, ett_typelen, NULL,
"%s Type/Length byte: %s, %d %s", (proto_registrar_get_nth(hf_string))->name, ptr->desc, len, unit);
proto_tree_add_uint_format_value(s_tree, hf_type, tvb, offs, 1, type, "%s (0x%02x)",
ptr->desc, type);
proto_tree_add_uint_format_value(s_tree, hf_length, tvb, offs, 1, len, "%d %s",
len, unit);
proto_tree_add_string_format_value(tree, hf_string, tvb, offs + 1, blen, str,
"[%s] '%s'", ptr->desc, str);
}
void
ipmi_add_timestamp(proto_tree *tree, gint hf, tvbuff_t *tvb, guint offset)
{
guint32 ts = tvb_get_letohl(tvb, offset);
if (ts == 0xffffffff) {
proto_tree_add_uint_format_value(tree, hf, tvb, offset, 4,
ts, "Unspecified/Invalid");
} else if (ts <= 0x20000000) {
proto_tree_add_uint_format_value(tree, hf, tvb, offset, 4,
ts, "%s since SEL device's initialization",
unsigned_time_secs_to_str(wmem_packet_scope(), ts));
} else {
proto_tree_add_uint_format_value(tree, hf, tvb, offset, 4,
ts, "%s", abs_time_secs_to_str(wmem_packet_scope(), ts, ABSOLUTE_TIME_UTC, TRUE));
}
}
void
ipmi_add_guid(proto_tree *tree, gint hf, tvbuff_t *tvb, guint offset)
{
e_guid_t guid;
int i;
guid.data1 = tvb_get_letohl(tvb, offset + 12);
guid.data2 = tvb_get_letohs(tvb, offset + 10);
guid.data3 = tvb_get_letohs(tvb, offset + 8);
for (i = 0; i < 8; i++) {
guid.data4[i] = tvb_get_guint8(tvb, offset + 7 - i);
}
proto_tree_add_guid(tree, hf, tvb, offset, 16, &guid);
}
static void
ipmi_netfn_setdesc(guint32 netfn, const char *desc, guint32 siglen)
{
struct ipmi_netfn_root *inr;
inr = &ipmi_cmd_tab[netfn >> 1];
inr->desc = desc;
inr->siglen = siglen;
}
void
ipmi_register_netfn_cmdtab(guint32 netfn, guint oem_selector,
const guint8 *sig, guint32 siglen, const char *desc,
ipmi_cmd_t *cmdtab, guint32 cmdtablen)
{
struct ipmi_netfn_root *inr;
ipmi_netfn_t *inh;
netfn >>= 1;
if (netfn >= IPMI_NETFN_MAX) {
return;
}
inr = &ipmi_cmd_tab[netfn];
if (inr->siglen != siglen) {
return;
}
inh = (struct ipmi_netfn_handler *)g_malloc(sizeof(struct ipmi_netfn_handler));
inh->desc = desc;
inh->oem_selector = oem_selector;
inh->sig = sig;
inh->cmdtab = cmdtab;
inh->cmdtablen = cmdtablen;
inh->next = inr->list;
inr->list = inh;
}
guint32
ipmi_getsiglen(guint32 netfn)
{
return ipmi_cmd_tab[netfn >> 1].siglen;
}
const char *
ipmi_getnetfnname(guint32 netfn, ipmi_netfn_t *nf)
{
const char *dn, *db;
dn = ipmi_cmd_tab[netfn >> 1].desc ?
ipmi_cmd_tab[netfn >> 1].desc : "Reserved";
db = nf ? nf->desc : NULL;
if (db) {
return wmem_strdup_printf(wmem_packet_scope(), "%s (%s)", db, dn);
} else {
return dn;
}
}
ipmi_netfn_t *
ipmi_getnetfn(guint32 netfn, const guint8 *sig)
{
struct ipmi_netfn_root *inr;
ipmi_netfn_t *inh;
inr = &ipmi_cmd_tab[netfn >> 1];
for (inh = inr->list; inh; inh = inh->next) {
if ((inh->oem_selector == selected_oem || inh->oem_selector == IPMI_OEM_NONE)
&& (!inr->siglen || !memcmp(sig, inh->sig, inr->siglen))) {
return inh;
}
}
return NULL;
}
ipmi_cmd_t *
ipmi_getcmd(ipmi_netfn_t *nf, guint32 cmd)
{
static ipmi_cmd_t ipmi_cmd_unknown = {
0x00,
ipmi_notimpl,
ipmi_notimpl,
NULL,
NULL,
"Unknown command",
0
};
ipmi_cmd_t *ic;
size_t i, len;
if (nf) {
len = nf->cmdtablen;
for (ic = nf->cmdtab, i = 0; i < len; i++, ic++) {
if (ic->cmd == cmd) {
return ic;
}
}
}
return &ipmi_cmd_unknown;
}
void
ipmi_notimpl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_expert(tree, pinfo, &ei_impi_parser_not_implemented, tvb, 0, -1);
}
void
ipmi_fmt_10ms_1based(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%03d seconds", v / 100, (v % 100) * 10);
}
void
ipmi_fmt_500ms_0based(gchar *s, guint32 v)
{
ipmi_fmt_500ms_1based(s, ++v);
}
void
ipmi_fmt_500ms_1based(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%03d seconds", v / 2, (v % 2) * 500);
}
void
ipmi_fmt_1s_0based(gchar *s, guint32 v)
{
ipmi_fmt_1s_1based(s, ++v);
}
void
ipmi_fmt_1s_1based(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d seconds", v);
}
void
ipmi_fmt_2s_0based(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d seconds", (v + 1) * 2);
}
void
ipmi_fmt_5s_1based(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d seconds", v * 5);
}
void
ipmi_fmt_version(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d", v & 0x0f, (v >> 4) & 0x0f);
}
void
ipmi_fmt_channel(gchar *s, guint32 v)
{
static const value_string chan_vals[] = {
{ 0x00, "Primary IPMB (IPMB-0)" },
{ 0x07, "IPMB-L" },
{ 0x0e, "Current channel" },
{ 0x0f, "System Interface" },
{ 0, NULL }
};
gchar* tmp_str;
tmp_str = val_to_str_wmem(NULL, v, chan_vals, "Channel #%d");
g_snprintf(s, ITEM_LABEL_LENGTH, "%s (0x%02x)", tmp_str, v);
wmem_free(NULL, tmp_str);
}
void
ipmi_fmt_udpport(gchar *s, guint32 v)
{
gchar* port_str = udp_port_to_display(NULL, v);
g_snprintf(s, ITEM_LABEL_LENGTH, "%s (%d)", port_str, v);
wmem_free(NULL, port_str);
}
void
ipmi_fmt_percent(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d%%", v);
}
const char *
ipmi_get_completion_code(guint8 completion, ipmi_cmd_t *cmd)
{
static const value_string std_completion_codes[] = {
{ 0x00, "Command Completed Normally" },
{ 0xc0, "Node Busy" },
{ 0xc1, "Invalid Command" },
{ 0xc2, "Command invalid for given LUN" },
{ 0xc3, "Timeout while processing command, response unavailable" },
{ 0xc4, "Out of space" },
{ 0xc5, "Reservation Canceled or Invalid Reservation ID" },
{ 0xc6, "Request data truncated" },
{ 0xc7, "Request data length invalid" },
{ 0xc8, "Request data field length limit exceeded" },
{ 0xc9, "Parameter out of range" },
{ 0xca, "Cannot return number of requested data bytes" },
{ 0xcb, "Requested Sensor, data, or record not present" },
{ 0xcc, "Invalid data field in Request" },
{ 0xcd, "Command illegal for specified sensor or record type" },
{ 0xce, "Command response could not be provided" },
{ 0xcf, "Cannot execute duplicated request" },
{ 0xd0, "Command response could not be provided: SDR Repository in update mode" },
{ 0xd1, "Command response could not be provided: device in firmware update mode" },
{ 0xd2, "Command response could not be provided: BMC initialization or initialization agent in progress" },
{ 0xd3, "Destination unavailable" },
{ 0xd4, "Cannot execute command: insufficient privilege level or other security-based restriction" },
{ 0xd5, "Cannot execute command: command, or request parameter(s), not supported in present state" },
{ 0xd6, "Cannot execute command: parameter is illegal because subfunction is disabled or unavailable" },
{ 0xff, "Unspecified error" },
{ 0, NULL }
};
const char *res;
if (completion >= 0x01 && completion <= 0x7e) {
return "Device specific (OEM) completion code";
}
if (completion >= 0x80 && completion <= 0xbe) {
if (cmd && cmd->cs_cc && (res = try_val_to_str(completion, cmd->cs_cc)) != NULL) {
return res;
}
return "Standard command-specific code";
}
return val_to_str_const(completion, std_completion_codes, "Unknown");
}
static int
dissect_tmode(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ipmi_dissect_arg_t * arg = (ipmi_dissect_arg_t *) data;
ipmi_context_t ctx;
guint tvb_len = tvb_captured_length(tvb);
guint8 tmp;
if (tvb_len < 3) {
return 0;
}
memset(&ctx, 0, sizeof(ctx));
tmp = tvb_get_guint8(tvb, 0);
ctx.hdr.netfn = tmp >> 2;
ctx.hdr.rq_lun = tmp & 3;
ctx.hdr.rs_lun = tmp & 3;
ctx.hdr.rq_seq = tvb_get_guint8(tvb, 1) >> 2;
ctx.hdr.cmd = tvb_get_guint8(tvb, 2);
ctx.flags = IPMI_D_TMODE|IPMI_D_NO_CKS|IPMI_D_NO_RQ_SA;
ctx.hdr_len = 3;
ctx.hdr.context = arg ? arg->context : IPMI_E_NONE;
ctx.hdr.channel = arg ? arg->channel : 0;
ctx.hdr.dir = arg ? arg->flags >> 7 : ctx.hdr.netfn & 1;
if (ctx.hdr.context == IPMI_E_NONE) {
col_set_str(pinfo->cinfo, COL_DEF_SRC,
ctx.hdr.dir ? "Console" : "BMC");
col_set_str(pinfo->cinfo, COL_DEF_DST,
ctx.hdr.dir ? "BMC" : "Console");
}
return dissect_ipmi_cmd(tvb, pinfo, tree, proto_tmode, ett_ipmi, &ctx);
}
static int
dissect_kcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ipmi_dissect_arg_t * arg = (ipmi_dissect_arg_t *) data;
ipmi_context_t ctx;
guint tvb_len = tvb_captured_length(tvb);
guint8 tmp;
if (tvb_len < 2) {
return 0;
}
memset(&ctx, 0, sizeof(ctx));
tmp = tvb_get_guint8(tvb, 0);
ctx.hdr.netfn = tmp >> 2;
ctx.hdr.rq_lun = tmp & 3;
ctx.hdr.rs_lun = tmp & 3;
ctx.hdr.cmd = tvb_get_guint8(tvb, 1);
ctx.flags = IPMI_D_NO_CKS|IPMI_D_NO_RQ_SA|IPMI_D_NO_SEQ;
ctx.hdr_len = 2;
ctx.hdr.context = arg ? arg->context : 0;
ctx.hdr.channel = arg ? arg->channel : 0;
ctx.hdr.dir = arg ? arg->flags >> 7 : ctx.hdr.netfn & 1;
if (ctx.hdr.context == IPMI_E_NONE) {
col_set_str(pinfo->cinfo, COL_DEF_SRC, ctx.hdr.dir ? "HOST" : "BMC");
col_set_str(pinfo->cinfo, COL_DEF_DST, ctx.hdr.dir ? "BMC" : "HOST");
}
return dissect_ipmi_cmd(tvb, pinfo, tree, proto_kcs, ett_ipmi, &ctx);
}
static guint8 calc_cks(guint8 start, tvbuff_t * tvb, guint off, guint len)
{
while (len--) {
start += tvb_get_guint8(tvb, off++);
}
return start;
}
static gboolean guess_imb_format(tvbuff_t *tvb, guint8 env,
guint8 channel, guint * imb_flags, guint8 * cks1, guint8 * cks2)
{
gboolean check_bc = FALSE;
gboolean check_sh = FALSE;
gboolean check_sa = FALSE;
guint tvb_len;
guint sh_len;
guint sa_len;
guint rs_sa;
if (message_format == MSGFMT_NONE) {
return FALSE;
} else if (message_format == MSGFMT_IPMB) {
*imb_flags = IPMI_D_TRG_SA;
} else if (message_format == MSGFMT_LAN) {
*imb_flags = IPMI_D_TRG_SA|IPMI_D_SESSION_HANDLE;
} else if (!channel) {
if (env == IPMI_E_NONE) {
check_bc = 1;
*imb_flags = IPMI_D_TRG_SA;
} else if (env != IPMI_E_GETMSG) {
*imb_flags = IPMI_D_TRG_SA;
} else {
*imb_flags = 0;
}
} else if (channel == 15) {
*imb_flags = IPMI_D_TRG_SA;
if (env == IPMI_E_GETMSG) {
*imb_flags |= IPMI_D_SESSION_HANDLE;
}
} else {
if (env == IPMI_E_NONE) {
check_bc = 1;
*imb_flags = IPMI_D_TRG_SA;
} else if (env == IPMI_E_SENDMSG_RQ) {
check_sh = 1;
*imb_flags = IPMI_D_TRG_SA;
} else if (env == IPMI_E_SENDMSG_RS) {
*imb_flags = IPMI_D_TRG_SA;
} else {
check_sh = 1;
check_sa = 1;
*imb_flags = 0;
}
}
tvb_len = tvb_captured_length(tvb);
if (check_bc
&& tvb_len >= 8
&& !tvb_get_guint8(tvb, 0)
&& !calc_cks(0, tvb, 1, 3)
&& !calc_cks(0, tvb, 4, tvb_len - 4)) {
*imb_flags = IPMI_D_BROADCAST|IPMI_D_TRG_SA;
*cks1 = 0;
*cks2 = 0;
return TRUE;
}
if (check_sh
&& tvb_len >= 8
&& !calc_cks(0, tvb, 1, 3)
&& !calc_cks(0, tvb, 4, tvb_len - 4)) {
*imb_flags = IPMI_D_SESSION_HANDLE|IPMI_D_TRG_SA;
*cks1 = 0;
*cks2 = 0;
return TRUE;
}
if (check_sa
&& tvb_len >= 7
&& !calc_cks(0, tvb, 0, 3)
&& !calc_cks(0, tvb, 3, tvb_len - 3)) {
*imb_flags = IPMI_D_TRG_SA;
*cks1 = 0;
*cks2 = 0;
return TRUE;
}
if (*imb_flags & IPMI_D_SESSION_HANDLE) {
sh_len = 1;
sa_len = 1;
rs_sa = 0;
} else if (*imb_flags & IPMI_D_TRG_SA) {
sh_len = 0;
sa_len = 1;
rs_sa = 0;
} else {
sh_len = 0;
sa_len = 0;
rs_sa = 0x20;
}
if (tvb_len < 6 + sh_len + sa_len) {
return FALSE;
}
*cks1 = calc_cks(rs_sa, tvb, sh_len, sa_len + 2);
*cks2 = calc_cks(0, tvb, sh_len + sa_len + 2,
tvb_len - sh_len - sa_len - 2);
return TRUE;
}
int
do_dissect_ipmb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint hf_parent_item, gint ett_tree, ipmi_dissect_arg_t * arg)
{
ipmi_context_t ctx;
guint offset = 0;
guint8 tmp;
memset(&ctx, 0, sizeof(ctx));
ctx.hdr.context = arg ? arg->context : 0;
ctx.hdr.channel = arg ? arg->channel : 0;
if (!guess_imb_format(tvb, ctx.hdr.context, ctx.hdr.channel,
&ctx.flags, &ctx.cks1, &ctx.cks2)) {
return 0;
}
if (ctx.flags & IPMI_D_BROADCAST) {
offset++;
}
if (ctx.flags & IPMI_D_SESSION_HANDLE) {
ctx.hdr.session = tvb_get_guint8(tvb, offset++);
}
if (ctx.flags & IPMI_D_TRG_SA) {
ctx.hdr.rs_sa = tvb_get_guint8(tvb, offset++);
} else {
ctx.hdr.rs_sa = 0x20;
}
tmp = tvb_get_guint8(tvb, offset++);
ctx.hdr.netfn = tmp >> 2;
ctx.hdr.rs_lun = tmp & 3;
offset++;
ctx.hdr.rq_sa = tvb_get_guint8(tvb, offset++);
tmp = tvb_get_guint8(tvb, offset++);
ctx.hdr.rq_seq = tmp >> 2;
ctx.hdr.rq_lun = tmp & 3;
ctx.hdr.cmd = tvb_get_guint8(tvb, offset++);
ctx.hdr_len = offset;
ctx.hdr.dir = arg ? arg->flags >> 7 : ctx.hdr.netfn & 1;
if (ctx.hdr.context == IPMI_E_NONE) {
guint red = arg ? (arg->flags & 0x40) : 0;
if (!ctx.hdr.channel) {
col_add_fstr(pinfo->cinfo, COL_DEF_SRC,
"0x%02x(%s)", ctx.hdr.rq_sa, red ? "IPMB-B" : "IPMB-A");
} else {
col_add_fstr(pinfo->cinfo, COL_DEF_SRC,
"0x%02x", ctx.hdr.rq_sa);
}
col_add_fstr(pinfo->cinfo, COL_DEF_DST, "0x%02x", ctx.hdr.rs_sa);
}
return dissect_ipmi_cmd(tvb, pinfo, tree, hf_parent_item, ett_tree, &ctx);
}
static int
dissect_ipmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
return do_dissect_ipmb(tvb, pinfo, tree, proto_ipmb, ett_ipmi,
(ipmi_dissect_arg_t *) data);
}
static int
dissect_i2c_ipmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (pinfo->pseudo_header->i2c.flags & 0x00000001) {
return 0;
}
return do_dissect_ipmb(tvb, pinfo, tree, proto_ipmb, ett_ipmi,
(ipmi_dissect_arg_t *) data);
}
void
proto_register_ipmi(void)
{
static hf_register_info hf[] = {
{ &hf_ipmi_session_handle, { "Session handle", "ipmi.session_handle", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_header_trg, { "Target Address", "ipmi.header.target", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ipmi_header_trg_lun, { "Target LUN", "ipmi.header.trg_lun", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }},
{ &hf_ipmi_header_netfn, { "NetFN", "ipmi.header.netfn", FT_UINT8, BASE_HEX, NULL, 0xfc, NULL, HFILL }},
{ &hf_ipmi_header_crc, { "Header Checksum", "ipmi.header.crc", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_header_src, { "Source Address", "ipmi.header.source", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_header_src_lun, { "Source LUN", "ipmi.header.src_lun", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }},
{ &hf_ipmi_header_bridged, { "Bridged", "ipmi.header.bridged", FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }},
{ &hf_ipmi_header_sequence, { "Sequence Number", "ipmi.header.sequence", FT_UINT8, BASE_HEX, NULL, 0xfc, NULL, HFILL }},
{ &hf_ipmi_header_command, { "Command", "ipmi.header.command", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_header_completion, { "Completion Code", "ipmi.header.completion", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_header_sig, { "Signature", "ipmi.header.signature", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_data_crc, { "Data checksum", "ipmi.data.crc", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_response_to, { "Response to", "ipmi.response_to", FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_response_in, { "Response in", "ipmi.response_in", FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_response_time, { "Responded in", "ipmi.response_time", FT_RELATIVE_TIME, BASE_NONE, NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ipmi,
&ett_header,
&ett_header_byte_1,
&ett_header_byte_4,
&ett_data,
&ett_typelen
};
static const enum_val_t msgfmt_vals[] = {
{ "none", "None", MSGFMT_NONE },
{ "ipmb", "IPMB", MSGFMT_IPMB },
{ "lan", "Session-based (LAN, ...)", MSGFMT_LAN },
{ "guess", "Use heuristics", MSGFMT_GUESS },
{ NULL, NULL, 0 }
};
static const enum_val_t oemsel_vals[] = {
{ "none", "None", IPMI_OEM_NONE },
{ "pps", "Pigeon Point Systems", IPMI_OEM_PPS },
{ NULL, NULL, 0 }
};
static ei_register_info ei[] = {
{ &ei_impi_parser_not_implemented, { "ipmi.parser_not_implemented", PI_UNDECODED, PI_WARN, "[PARSER NOT IMPLEMENTED]", EXPFILL }},
};
module_t *m;
expert_module_t* expert_ipmi;
guint32 i;
proto_ipmi = proto_register_protocol("Intelligent Platform Management Interface",
"IPMI",
"ipmi");
proto_ipmb = proto_register_protocol("Intelligent Platform Management Bus",
"IPMB",
"ipmb");
proto_kcs = proto_register_protocol("Keyboard Controller Style Interface",
"KCS",
"kcs");
proto_tmode = proto_register_protocol("Serial Terminal Mode Interface",
"TMode",
"tmode");
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ipmi = expert_register_protocol(proto_ipmi);
expert_register_field_array(expert_ipmi, ei, array_length(ei));
ipmi_netfn_setdesc(IPMI_CHASSIS_REQ, "Chassis", 0);
ipmi_netfn_setdesc(IPMI_BRIDGE_REQ, "Bridge", 0);
ipmi_netfn_setdesc(IPMI_SE_REQ, "Sensor/Event", 0);
ipmi_netfn_setdesc(IPMI_APP_REQ, "Application", 0);
ipmi_netfn_setdesc(IPMI_UPDATE_REQ, "Firmware Update", 0);
ipmi_netfn_setdesc(IPMI_STORAGE_REQ, "Storage", 0);
ipmi_netfn_setdesc(IPMI_TRANSPORT_REQ, "Transport", 0);
ipmi_netfn_setdesc(IPMI_GROUP_REQ, "Group", 1);
ipmi_netfn_setdesc(IPMI_OEM_REQ, "OEM/Group", 3);
for (i = 0x30; i < 0x40; i += 2) {
ipmi_netfn_setdesc(i, "OEM", 0);
}
register_dissector("ipmi", dissect_ipmi, proto_ipmi);
register_dissector("ipmb", dissect_ipmi, proto_ipmb);
register_dissector("kcs", dissect_kcs, proto_kcs);
register_dissector("tmode", dissect_tmode, proto_tmode);
m = prefs_register_protocol(proto_ipmi, NULL);
prefs_register_bool_preference(m, "fru_langcode_is_english", "FRU Language Code is English",
"FRU Language Code is English; strings are ASCII+LATIN1 (vs. Unicode)",
&fru_langcode_is_english);
prefs_register_uint_preference(m, "response_after_req", "Maximum delay of response message",
"Do not search for responses coming after this timeout (milliseconds)",
10, &response_after_req);
prefs_register_uint_preference(m, "response_before_req", "Response ahead of request",
"Allow for responses before requests (milliseconds)",
10, &response_before_req);
prefs_register_enum_preference(m, "msgfmt", "Format of embedded messages",
"Format of messages embedded into Send/Get/Forward Message",
&message_format, msgfmt_vals, FALSE);
prefs_register_enum_preference(m, "selected_oem", "OEM commands parsed as",
"Selects which OEM format is used for commands that IPMI does not define",
&selected_oem, oemsel_vals, FALSE);
}
void proto_reg_handoff_ipmi(void)
{
dissector_handle_t ipmi_handle;
ipmi_handle = create_dissector_handle( dissect_i2c_ipmi, proto_ipmi );
dissector_add_for_decode_as("i2c.message", ipmi_handle );
}
