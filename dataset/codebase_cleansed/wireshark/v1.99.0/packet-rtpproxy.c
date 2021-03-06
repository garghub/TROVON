static gint
rtpproxy_add_tag(proto_tree *rtpproxy_tree, tvbuff_t *tvb, guint begin, guint realsize)
{
proto_item *ti = NULL;
proto_tree *another_tree = NULL;
gint new_offset;
guint end;
new_offset = tvb_find_guint8(tvb, begin, -1, ' ');
if(new_offset < 0)
end = realsize;
else
end = new_offset;
new_offset = tvb_find_guint8(tvb, begin, end, ';');
if(new_offset == -1){
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_tag, tvb, begin, end - begin, ENC_ASCII | ENC_NA);
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_tag);
ti = proto_tree_add_item(another_tree, hf_rtpproxy_mediaid, tvb, new_offset+1, 0, ENC_ASCII | ENC_NA);
proto_item_append_text(ti, "<skipped>");
PROTO_ITEM_SET_GENERATED(ti);
}
else{
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_tag, tvb, begin, new_offset - begin, ENC_ASCII | ENC_NA);
if ((guint)new_offset == begin){
proto_item_append_text(ti, "<skipped>");
PROTO_ITEM_SET_GENERATED(ti);
}
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_tag);
proto_tree_add_item(another_tree, hf_rtpproxy_mediaid, tvb, new_offset+1, end - (new_offset+1), ENC_ASCII | ENC_NA);
}
return (end == realsize ? -1 : (gint)end);
}
static void
rtpproxy_add_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtpproxy_tree, guint begin, guint realsize)
{
proto_item *ti;
proto_tree *another_tree = NULL;
guint offset = 0;
guint new_offset = 0;
gint i;
guint pt = 0;
gchar** codecs = NULL;
guint codec_len;
guint8* rawstr = NULL;
guint32 ipaddr[4];
rawstr = tvb_get_string_enc(wmem_packet_scope(), tvb, begin, realsize, ENC_ASCII);
while(offset < realsize){
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_command_parameter, tvb, begin + offset, 1, ENC_NA);
offset++;
switch (g_ascii_tolower(tvb_get_guint8(tvb, begin+offset-1)))
{
case 'c':
new_offset = (gint)strspn(rawstr+offset, "0123456789,");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_codecs);
codecs = g_strsplit(tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), ",", 0);
i = 0;
while(codecs[i]){
codec_len = (guint)strlen(codecs[i]);
ti = proto_tree_add_uint(another_tree, hf_rtpproxy_command_parameter_codec, tvb, begin+offset, codec_len,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, codec_len, ENC_ASCII), NULL, 10));
proto_item_append_text(ti, " (%s)", val_to_str_ext((guint)strtoul(tvb_format_text(tvb,begin+offset,codec_len),NULL,10), &rtp_payload_type_vals_ext, "Unknown"));
offset += codec_len;
if(codecs[i+1])
offset++;
i++;
};
g_strfreev(codecs);
break;
case 'l':
new_offset = (gint)strspn(rawstr+offset, "0123456789.");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_local);
if(str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), ipaddr))
proto_tree_add_ipv4(another_tree, hf_rtpproxy_command_parameter_local_ipv4, tvb, begin+offset, new_offset, ipaddr[0]);
else
proto_tree_add_expert(another_tree, pinfo, &ei_rtpproxy_bad_ipv4, tvb, begin+offset, new_offset);
offset += new_offset;
break;
case 'r':
new_offset = (gint)strspn(rawstr+offset, "0123456789.");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_remote);
if(str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), ipaddr))
proto_tree_add_ipv4(another_tree, hf_rtpproxy_command_parameter_remote_ipv4, tvb, begin+offset, new_offset, ipaddr[0]);
else
proto_tree_add_expert(another_tree, pinfo, &ei_rtpproxy_bad_ipv4, tvb, begin+offset, new_offset);
offset += new_offset;
break;
case 'z':
new_offset = (gint)strspn(rawstr+offset, "0123456789");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_repacketize);
proto_tree_add_uint(another_tree, hf_rtpproxy_command_parameter_repacketize, tvb, begin+offset, new_offset,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), NULL, 10));
offset += new_offset;
break;
case 'd':
new_offset = (gint)strspn(rawstr+offset, "0123456789");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_dtmf);
proto_tree_add_uint(another_tree, hf_rtpproxy_command_parameter_dtmf, tvb, begin+offset, new_offset,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), NULL, 10));
if(rtpproxy_establish_conversation){
pt = (guint)strtoul(tvb_format_text(tvb,begin+offset,new_offset),NULL,10);
dissector_add_uint("rtp.pt", pt, rtp_events_handle);
}
offset += new_offset;
break;
case 'm':
new_offset = (gint)strspn(rawstr+offset, "0123456789=,");
offset += new_offset;
break;
case 'p':
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_proto);
proto_tree_add_item(another_tree, hf_rtpproxy_command_parameter_proto, tvb, begin+offset, 1, ENC_NA);
offset++;
break;
case 't':
new_offset = (gint)strspn(rawstr+offset, "0123456789");
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_transcode);
ti = proto_tree_add_uint(another_tree, hf_rtpproxy_command_parameter_transcode, tvb, begin+offset, new_offset,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin+offset, new_offset, ENC_ASCII), NULL, 10));
proto_item_append_text(ti, " (%s)", val_to_str_ext((guint)strtoul(tvb_format_text(tvb,begin+offset, new_offset),NULL,10), &rtp_payload_type_vals_ext, "Unknown"));
offset += new_offset;
break;
case 'v':
another_tree = proto_item_add_subtree(ti, ett_rtpproxy_command_parameters_acc);
proto_tree_add_item(another_tree, hf_rtpproxy_command_parameter_acc, tvb, begin+offset, 1, ENC_NA);
offset++;
break;
default:
break;
}
}
}
static rtpproxy_info_t *
rtpproxy_add_tid(gboolean is_request, tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtpproxy_tree, rtpproxy_conv_info_t *rtpproxy_conv, gchar* cookie)
{
rtpproxy_info_t *rtpproxy_info;
proto_item *pi;
if (!PINFO_FD_VISITED(pinfo)) {
if (is_request){
rtpproxy_info = wmem_new(wmem_file_scope(), rtpproxy_info_t);
rtpproxy_info->req_frame = PINFO_FD_NUM(pinfo);
rtpproxy_info->resp_frame = 0;
rtpproxy_info->req_time = pinfo->fd->abs_ts;
rtpproxy_info->callid = NULL;
wmem_tree_insert_string(rtpproxy_conv->trans, cookie, rtpproxy_info, 0);
} else {
rtpproxy_info = (rtpproxy_info_t *)wmem_tree_lookup_string(rtpproxy_conv->trans, cookie, 0);
if (rtpproxy_info) {
rtpproxy_info->resp_frame = PINFO_FD_NUM(pinfo);
}
}
} else {
rtpproxy_info = (rtpproxy_info_t *)wmem_tree_lookup_string(rtpproxy_conv->trans, cookie, 0);
if (rtpproxy_info && (is_request ? rtpproxy_info->resp_frame : rtpproxy_info->req_frame)) {
nstime_t ns;
pi = proto_tree_add_uint(rtpproxy_tree, is_request ? hf_rtpproxy_response_in : hf_rtpproxy_request_in, tvb, 0, 0, is_request ? rtpproxy_info->resp_frame : rtpproxy_info->req_frame);
PROTO_ITEM_SET_GENERATED(pi);
if (!is_request){
nstime_delta(&ns, &pinfo->fd->abs_ts, &rtpproxy_info->req_time);
pi = proto_tree_add_time(rtpproxy_tree, hf_rtpproxy_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(pi);
if (nstime_cmp(&rtpproxy_timeout_ns, &ns) < 0)
expert_add_info_format(pinfo, rtpproxy_tree, &ei_rtpproxy_timeout, "Response timeout %.3f seconds", nstime_to_sec(&ns));
}
}
}
return rtpproxy_info;
}
static void
rtpproxy_add_notify_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtpproxy_tree, guint begin, guint end)
{
gint offset = 0;
gint tmp = 0;
gboolean ipv6 = FALSE;
guint32 ipaddr[4];
proto_item *ti;
offset = tvb_find_guint8(tvb, begin, end, ':');
if(offset != -1){
while((tmp = tvb_find_guint8(tvb, offset+1, end, ':')) != -1){
ipv6 = TRUE;
offset = tmp;
}
if(ipv6){
if(str_to_ip6((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin, offset - begin, ENC_ASCII), ipaddr))
proto_tree_add_ipv6(rtpproxy_tree, hf_rtpproxy_notify_ipv6, tvb, begin, offset - begin, (const guint8 *)ipaddr);
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv6, tvb, begin, offset - begin);
}
else{
if(str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin, offset - begin, ENC_ASCII), ipaddr))
proto_tree_add_ipv4(rtpproxy_tree, hf_rtpproxy_notify_ipv4, tvb, begin, offset - begin, ipaddr[0]);
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv4, tvb, begin, offset - begin);
}
proto_tree_add_uint(rtpproxy_tree, hf_rtpproxy_notify_port, tvb, offset+1, end - (offset+1),
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset+1, end - (offset+1), ENC_ASCII), NULL, 10));
}
else{
expert_add_info(pinfo, rtpproxy_tree, &ei_rtpproxy_notify_no_ip);
if (pinfo->src.type == AT_IPv4)
ti = proto_tree_add_ipv4(rtpproxy_tree, hf_rtpproxy_notify_ipv4, tvb, begin, 0, ((guint32*)(pinfo->src.data))[0]);
else
ti = proto_tree_add_ipv6(rtpproxy_tree, hf_rtpproxy_notify_ipv6, tvb, begin, 0, (const guint8 *)(pinfo->src.data));
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_uint(rtpproxy_tree, hf_rtpproxy_notify_port, tvb, begin, end - begin,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, begin, end - begin, ENC_ASCII), NULL, 10));
}
}
static int
dissect_rtpproxy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean has_lf = FALSE;
gint offset = 0;
gint new_offset = 0;
guint tmp;
guint tmp2;
gint realsize = 0;
guint8* rawstr;
guint8* tmpstr;
proto_item *ti;
proto_item *ti2;
proto_tree *rtpproxy_tree;
conversation_t *conversation;
rtpproxy_conv_info_t *rtpproxy_conv;
gchar* cookie = NULL;
address addr;
guint16 port;
guint32 ipaddr[4];
rtpproxy_info_t *rtpproxy_info = NULL;
tvbuff_t *subtvb;
if(!isprint(tvb_get_guint8(tvb, 0)))
return 0;
offset = tvb_find_guint8(tvb, offset, -1, ' ');
if(offset == -1)
return 0;
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_rtpproxy, tvb, 0, -1, ENC_NA);
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy);
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_cookie, tvb, 0, offset, ENC_ASCII | ENC_NA);
cookie = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, offset, ENC_ASCII);
offset = tvb_skip_wsp(tvb, offset+1, -1);
realsize = tvb_reported_length(tvb);
if (tvb_get_guint8(tvb, realsize - 1) == '\n'){
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPproxy");
realsize -= 1;
has_lf = TRUE;
}
else
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTPproxy (no LF)");
conversation = find_or_create_conversation(pinfo);
rtpproxy_conv = (rtpproxy_conv_info_t *)conversation_get_proto_data(conversation, proto_rtpproxy);
if (!rtpproxy_conv) {
rtpproxy_conv = wmem_new(wmem_file_scope(), rtpproxy_conv_info_t);
rtpproxy_conv->trans = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_rtpproxy, rtpproxy_conv);
}
rawstr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, realsize - offset, ENC_ASCII);
tmp = g_ascii_tolower(tvb_get_guint8(tvb, offset));
switch (tmp)
{
case 's':
rtpproxy_add_tid(FALSE, tvb, pinfo, rtpproxy_tree, rtpproxy_conv, cookie);
if ('e' == tvb_get_guint8(tvb, offset+1)){
col_add_fstr(pinfo->cinfo, COL_INFO, "Reply: %s", rawstr);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_reply, tvb, offset, -1, ENC_NA);
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_reply);
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_status, tvb, offset, realsize - offset, ENC_ASCII | ENC_NA);
break;
}
case 'i':
case 'x':
case 'u':
case 'l':
case 'd':
tmp2 = tvb_get_guint8(tvb, offset+1);
if(('1' <= tmp2) && (tmp2 <= '9') && (tvb_get_guint8(tvb, offset+2) == ':')){
col_add_fstr(pinfo->cinfo, COL_INFO, "RTPproxy-ng: %s", rawstr);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_ng_bencode, tvb, offset, -1, ENC_ASCII | ENC_NA);
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_ng_bencode);
subtvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(bencode_handle, subtvb, pinfo, rtpproxy_tree);
break;
}
case 'p':
case 'v':
case 'r':
case 'c':
case 'q':
rtpproxy_info = rtpproxy_add_tid(TRUE, tvb, pinfo, rtpproxy_tree, rtpproxy_conv, cookie);
col_add_fstr(pinfo->cinfo, COL_INFO, "Request: %s", rawstr);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_request, tvb, offset, -1, ENC_NA);
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_request);
if ((tmp == 'v') && (offset + (gint)strlen("VF YYYMMDD") + 1 == realsize)){
new_offset = tvb_skip_wsp(tvb, offset + ((guint)strlen("VF") + 1), -1);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_version_request, tvb, new_offset, (gint)strlen("YYYYMMDD"), ENC_ASCII | ENC_NA);
tmpstr = tvb_get_string_enc(wmem_packet_scope(), tvb, new_offset, (gint)strlen("YYYYMMDD"), ENC_ASCII);
proto_item_append_text(ti, " (%s)", str_to_str(tmpstr, versiontypenames, "Unknown"));
break;
}
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_command, tvb, offset, 1, ENC_NA);
if (tmp == 'v')
break;
if (tmp == 'x')
break;
new_offset = (tmp == 'i' ? (realsize - 1 > offset ? offset + (gint)strlen("Ib") : offset + (gint)strlen("I")) : tvb_find_guint8(tvb, offset, -1, ' '));
if (new_offset != offset + 1){
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_command);
ti2 = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_command_parameters, tvb, offset+1, new_offset - (offset+1), ENC_ASCII | ENC_NA);
rtpproxy_add_parameter(tvb, pinfo, proto_item_add_subtree(ti2, ett_rtpproxy_command_parameters), offset+1, new_offset - (offset+1));
rtpproxy_tree = proto_item_get_parent(ti);
}
if (tmp == 'i')
break;
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_callid, tvb, offset, new_offset - offset, ENC_ASCII | ENC_NA);
if(rtpproxy_info && !rtpproxy_info->callid)
rtpproxy_info->callid = tvb_get_string_enc(wmem_file_scope(), tvb, offset, new_offset - offset, ENC_ASCII);
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
if ((tmp == 'u') || (tmp == 'l')){
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if (tvb_find_guint8(tvb, offset, new_offset - offset, ':') == -1){
if(str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, new_offset - offset, ENC_ASCII), ipaddr))
proto_tree_add_ipv4(rtpproxy_tree, hf_rtpproxy_ipv4, tvb, offset, new_offset - offset, ipaddr[0]);
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv4, tvb, offset, new_offset - offset);
}
else{
if(str_to_ip6((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, new_offset - offset, ENC_ASCII), ipaddr))
proto_tree_add_ipv6(rtpproxy_tree, hf_rtpproxy_ipv6, tvb, offset, new_offset - offset, (const guint8 *)ipaddr);
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv6, tvb, offset, new_offset - offset);
}
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
proto_tree_add_uint(rtpproxy_tree, hf_rtpproxy_port, tvb, offset, new_offset - offset,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, new_offset - offset, ENC_ASCII), NULL, 10));
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
}
if (tmp == 'c'){
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_copy_target, tvb, offset, new_offset - offset, ENC_ASCII | ENC_NA);
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
}
if (tmp == 'p'){
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_playback_filename, tvb, offset, new_offset - offset, ENC_ASCII | ENC_NA);
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
proto_tree_add_uint(rtpproxy_tree, hf_rtpproxy_playback_codec, tvb, offset, new_offset - offset,
(guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, new_offset - offset, ENC_ASCII), NULL, 10));
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
}
new_offset = rtpproxy_add_tag(rtpproxy_tree, tvb, offset, realsize);
if(new_offset == -1)
break;
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
new_offset = rtpproxy_add_tag(rtpproxy_tree, tvb, offset, realsize);
if(new_offset == -1)
break;
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
if (tmp == 'u'){
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_notify, tvb, offset, realsize - offset, ENC_ASCII | ENC_NA);
proto_item_set_text(ti, "Notify");
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_notify);
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
if(new_offset == -1){
rtpproxy_add_notify_addr(tvb, pinfo, rtpproxy_tree, offset, realsize);
break;
}
rtpproxy_add_notify_addr(tvb, pinfo, rtpproxy_tree, offset, new_offset);
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_notify_tag, tvb, offset, realsize - offset, ENC_ASCII | ENC_NA);
}
break;
case 'a':
case 'e':
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
rtpproxy_info = rtpproxy_add_tid(FALSE, tvb, pinfo, rtpproxy_tree, rtpproxy_conv, cookie);
if (tmp == 'e')
col_add_fstr(pinfo->cinfo, COL_INFO, "Error reply: %s", rawstr);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Reply: %s", rawstr);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_reply, tvb, offset, -1, ENC_NA);
rtpproxy_tree = proto_item_add_subtree(ti, ett_rtpproxy_reply);
if(rtpproxy_info && rtpproxy_info->callid){
ti = proto_tree_add_string(rtpproxy_tree, hf_rtpproxy_callid, tvb, offset, 0, rtpproxy_info->callid);
PROTO_ITEM_SET_GENERATED(ti);
}
if (tmp == 'e'){
tmp = tvb_find_line_end(tvb, offset, -1, &new_offset, FALSE);
tmpstr = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tmp, ENC_ASCII);
ti = proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_error, tvb, offset, (gint)strlen(tmpstr), ENC_ASCII | ENC_NA);
proto_item_append_text(ti, " (%s)", str_to_str(tmpstr, errortypenames, "Unknown"));
break;
}
if (tmp == 'a'){
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_status, tvb, offset, realsize - offset, ENC_ASCII | ENC_NA);
break;
}
if ((tmp == '0')&& ((tvb_reported_length(tvb) == (guint)(offset+1))||(tvb_reported_length(tvb) == (guint)(offset+2)))){
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_ok, tvb, offset, 1, ENC_ASCII | ENC_NA);
break;
}
if ((tmp == '1') && ((tvb_reported_length(tvb) == (guint)(offset+1))||(tvb_reported_length(tvb) == (guint)(offset+2)))){
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_ok, tvb, offset, 1, ENC_ASCII | ENC_NA);
break;
}
if (tvb_reported_length(tvb) == (guint)(offset+9)){
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_version_supported, tvb, offset, 8, ENC_ASCII | ENC_NA);
break;
}
new_offset = tvb_find_guint8(tvb, offset, -1, ' ');
port = (guint16) g_ascii_strtoull((gchar*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, new_offset - offset, ENC_ASCII), NULL, 10);
proto_tree_add_uint(rtpproxy_tree, hf_rtpproxy_port, tvb, offset, new_offset - offset, port);
offset = tvb_skip_wsp(tvb, new_offset+1, -1);
memset(&addr, 0, sizeof(address));
tmp = tvb_find_guint8(tvb, offset, -1, ' ');
if(tmp == (guint)(-1)){
tmp = tvb_find_line_end(tvb, offset, -1, &new_offset, FALSE);
}
else {
tmp -= offset;
}
if (tvb_find_guint8(tvb, offset, -1, ':') == -1){
if (str_to_ip((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tmp, ENC_ASCII), ipaddr)){
addr.type = AT_IPv4;
addr.len = 4;
addr.data = wmem_memdup(wmem_packet_scope(), ipaddr, 4);
proto_tree_add_ipv4(rtpproxy_tree, hf_rtpproxy_ipv4, tvb, offset, tmp, ipaddr[0]);
}
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv4, tvb, offset, tmp);
}
else{
if (str_to_ip6((char*)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, tmp, ENC_ASCII), ipaddr)){
addr.type = AT_IPv6;
addr.len = 16;
addr.data = wmem_memdup(wmem_packet_scope(), ipaddr, 16);
proto_tree_add_ipv6(rtpproxy_tree, hf_rtpproxy_ipv6, tvb, offset, tmp, (const guint8 *)ipaddr);
}
else
proto_tree_add_expert(rtpproxy_tree, pinfo, &ei_rtpproxy_bad_ipv6, tvb, offset, tmp);
}
if(rtpproxy_establish_conversation){
if (rtp_handle) {
if (addr.len)
rtp_add_address(pinfo, &addr, port, 0, "RTPproxy", pinfo->fd->num, 0, NULL);
}
if (rtcp_handle) {
if (addr.len)
rtcp_add_address(pinfo, &addr, port+1, 0, "RTPproxy", pinfo->fd->num);
}
}
break;
default:
break;
}
if (has_lf)
proto_tree_add_item(rtpproxy_tree, hf_rtpproxy_lf, tvb, realsize, 1, ENC_NA);
return tvb_length(tvb);
}
void
proto_register_rtpproxy(void)
{
module_t *rtpproxy_module;
expert_module_t* expert_rtpproxy_module;
static hf_register_info hf[] = {
{
&hf_rtpproxy_cookie,
{
"Cookie",
"rtpproxy.cookie",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_version_request,
{
"Version Request",
"rtpproxy.version",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_version_supported,
{
"Version Supported",
"rtpproxy.version_supported",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_error,
{
"Error",
"rtpproxy.error",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_ok,
{
"Ok",
"rtpproxy.ok",
FT_UINT8,
BASE_DEC,
VALS(oktypenames),
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_status,
{
"Status",
"rtpproxy.status",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_ipv4,
{
"IPv4",
"rtpproxy.ipv4",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_ipv6,
{
"IPv6",
"rtpproxy.ipv6",
FT_IPv6,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_port,
{
"Port",
"rtpproxy.port",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_request,
{
"Request",
"rtpproxy.request",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command,
{
"Command",
"rtpproxy.command",
FT_UINT8,
BASE_DEC,
VALS(commandtypenames),
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameters,
{
"Command parameters",
"rtpproxy.command_parameters",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter,
{
"Parameter",
"rtpproxy.command_parameter",
FT_UINT8,
BASE_DEC,
VALS(paramtypenames),
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_codec,
{
"Allowed codec",
"rtpproxy.command_parameter_codec",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_local_ipv4,
{
"Local IPv4 address",
"rtpproxy.command_parameter_local_ipv4",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_remote_ipv4,
{
"Remote IPv4 address",
"rtpproxy.command_parameter_remote_ipv4",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_repacketize,
{
"Repacketize (ms)",
"rtpproxy.command_parameter_repacketize",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_dtmf,
{
"DTMF payload ID",
"rtpproxy.command_parameter_dtmf",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_proto,
{
"RTP tramsission protocol",
"rtpproxy.command_parameter_proto",
FT_UINT8,
BASE_DEC,
VALS(prototypenames),
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_transcode,
{
"Transcode to",
"rtpproxy.command_parameter_transcode",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_command_parameter_acc,
{
"Accounting",
"rtpproxy.command_parameter_acc",
FT_UINT8,
BASE_DEC,
VALS(acctypenames),
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_copy_target,
{
"Copy target",
"rtpproxy.copy_target",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_playback_filename,
{
"Playback filename",
"rtpproxy.playback_filename",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_playback_codec,
{
"Playback codec",
"rtpproxy.playback_codec",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_callid,
{
"Call-ID",
"rtpproxy.callid",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_notify,
{
"Notify",
"rtpproxy.notify",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_tag,
{
"Tag",
"rtpproxy.tag",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_mediaid,
{
"Media-ID",
"rtpproxy.mediaid",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_notify_ipv4,
{
"Notification IPv4",
"rtpproxy.notify_ipv4",
FT_IPv4,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_notify_ipv6,
{
"Notification IPv6",
"rtpproxy.notify_ipv6",
FT_IPv6,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_notify_port,
{
"Notification Port",
"rtpproxy.notify_port",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_notify_tag,
{
"Notification Tag",
"rtpproxy.notify_tag",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_reply,
{
"Reply",
"rtpproxy.reply",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_lf,
{
"LF",
"rtpproxy.lf",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_request_in,
{
"Request In",
"rtpproxy.request_in",
FT_FRAMENUM,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_response_in,
{
"Response In",
"rtpproxy.response_in",
FT_FRAMENUM,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{
&hf_rtpproxy_response_time,
{
"Response Time",
"rtpproxy.response_time",
FT_RELATIVE_TIME,
BASE_NONE,
NULL,
0x0,
"The time between the Request and the Reply",
HFILL
}
},
{
&hf_rtpproxy_ng_bencode,
{
"RTPproxy-ng bencode packet",
"rtpproxy.ng.bencode",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"Serialized structure of integers, dictionaries, strings and lists.",
HFILL
}
}
};
static ei_register_info ei[] = {
{ &ei_rtpproxy_timeout,
{ "rtpproxy.response_timeout", PI_RESPONSE_CODE, PI_WARN,
"TIMEOUT", EXPFILL }},
{ &ei_rtpproxy_notify_no_ip,
{ "rtpproxy.notify_no_ip", PI_RESPONSE_CODE, PI_COMMENT,
"No notification IP address provided. Using ip.src or ipv6.src as a value.", EXPFILL }},
{ &ei_rtpproxy_bad_ipv4,
{ "rtpproxy.bad_ipv4", PI_MALFORMED, PI_ERROR,
"Bad IPv4", EXPFILL }},
{ &ei_rtpproxy_bad_ipv6,
{ "rtpproxy.bad_ipv6", PI_MALFORMED, PI_ERROR,
"Bad IPv6", EXPFILL }},
};
static gint *ett[] = {
&ett_rtpproxy,
&ett_rtpproxy_request,
&ett_rtpproxy_command,
&ett_rtpproxy_command_parameters,
&ett_rtpproxy_command_parameters_codecs,
&ett_rtpproxy_command_parameters_local,
&ett_rtpproxy_command_parameters_remote,
&ett_rtpproxy_command_parameters_repacketize,
&ett_rtpproxy_command_parameters_dtmf,
&ett_rtpproxy_command_parameters_cmap,
&ett_rtpproxy_command_parameters_proto,
&ett_rtpproxy_command_parameters_transcode,
&ett_rtpproxy_command_parameters_acc,
&ett_rtpproxy_tag,
&ett_rtpproxy_notify,
&ett_rtpproxy_reply,
&ett_rtpproxy_ng_bencode
};
proto_rtpproxy = proto_register_protocol (
"Sippy RTPproxy Protocol",
"RTPproxy",
"rtpproxy"
);
proto_register_field_array(proto_rtpproxy, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rtpproxy_module = expert_register_protocol(proto_rtpproxy);
expert_register_field_array(expert_rtpproxy_module, ei, array_length(ei));
rtpproxy_module = prefs_register_protocol(proto_rtpproxy, proto_reg_handoff_rtpproxy);
prefs_register_uint_preference(rtpproxy_module, "tcp.port",
"RTPproxy TCP Port",
"RTPproxy TCP Port",
10,
&rtpproxy_tcp_port);
prefs_register_uint_preference(rtpproxy_module, "udp.port",
"RTPproxy UDP Port",
"RTPproxy UDP Port",
10,
&rtpproxy_udp_port);
prefs_register_bool_preference(rtpproxy_module, "establish_conversation",
"Establish Media Conversation",
"Specifies that RTP/RTCP/T.38/MSRP/etc streams are decoded based "
"upon port numbers found in RTPproxy answers",
&rtpproxy_establish_conversation);
prefs_register_uint_preference(rtpproxy_module, "reply.timeout",
"RTPproxy reply timeout",
"Maximum timeout value in waiting for reply from RTPProxy (in milliseconds).",
10,
&rtpproxy_timeout);
}
void
proto_reg_handoff_rtpproxy(void)
{
static guint old_rtpproxy_tcp_port = 0;
static guint old_rtpproxy_udp_port = 0;
static gboolean rtpproxy_initialized = FALSE;
static dissector_handle_t rtpproxy_tcp_handle, rtpproxy_udp_handle;
if(!rtpproxy_initialized){
rtpproxy_tcp_handle = new_create_dissector_handle(dissect_rtpproxy, proto_rtpproxy);
rtpproxy_udp_handle = new_create_dissector_handle(dissect_rtpproxy, proto_rtpproxy);
rtpproxy_initialized = TRUE;
}
if(old_rtpproxy_tcp_port != 0 && old_rtpproxy_tcp_port != rtpproxy_tcp_port)
dissector_delete_uint("tcp.port", old_rtpproxy_tcp_port, rtpproxy_tcp_handle);
if(rtpproxy_tcp_port != 0 && old_rtpproxy_tcp_port != rtpproxy_tcp_port)
dissector_add_uint("tcp.port", rtpproxy_tcp_port, rtpproxy_tcp_handle);
old_rtpproxy_tcp_port = rtpproxy_tcp_port;
if(old_rtpproxy_udp_port != 0 && old_rtpproxy_udp_port != rtpproxy_udp_port)
dissector_delete_uint("udp.port", old_rtpproxy_udp_port, rtpproxy_udp_handle);
if(rtpproxy_udp_port != 0 && old_rtpproxy_udp_port != rtpproxy_udp_port)
dissector_add_uint("udp.port", rtpproxy_udp_port, rtpproxy_udp_handle);
old_rtpproxy_udp_port = rtpproxy_udp_port;
rtcp_handle = find_dissector("rtcp");
rtp_events_handle = find_dissector("rtpevent");
rtp_handle = find_dissector("rtp");
bencode_handle = find_dissector("bencode");
rtpproxy_timeout_ns.secs = (rtpproxy_timeout - rtpproxy_timeout % 1000) / 1000;
rtpproxy_timeout_ns.nsecs = (rtpproxy_timeout % 1000) * 1000;
}
