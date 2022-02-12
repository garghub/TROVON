void srtcp_add_address( packet_info *pinfo,
address *addr, int port,
int other_port,
const gchar *setup_method, guint32 setup_frame_number,
struct srtp_info *srtcp_info)
{
address null_addr;
conversation_t *p_conv;
struct _rtcp_conversation_info *p_conv_data;
if (pinfo->fd->flags.visited)
{
return;
}
#ifdef DEBUG
printf("#%u: %srtcp_add_address(%s, %u, %u, %s, %u\n", pinfo->fd->num, (srtcp_info)?"s":"", ep_address_to_str(addr), port, other_port, setup_method, setup_frame_number);
#endif
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
p_conv = find_conversation( pinfo->fd->num, addr, &null_addr, PT_UDP, port, other_port,
NO_ADDR_B | (!other_port ? NO_PORT_B : 0));
if ( ! p_conv ) {
p_conv = conversation_new( pinfo->fd->num, addr, &null_addr, PT_UDP,
(guint32)port, (guint32)other_port,
NO_ADDR2 | (!other_port ? NO_PORT2 : 0));
}
conversation_set_dissector(p_conv, rtcp_handle);
p_conv_data = conversation_get_proto_data(p_conv, proto_rtcp);
if ( ! p_conv_data ) {
p_conv_data = se_alloc0(sizeof(struct _rtcp_conversation_info));
conversation_add_proto_data(p_conv, proto_rtcp, p_conv_data);
}
p_conv_data->setup_method_set = TRUE;
g_strlcpy(p_conv_data->setup_method, setup_method, MAX_RTCP_SETUP_METHOD_SIZE);
p_conv_data->setup_frame_number = setup_frame_number;
p_conv_data->srtcp_info = srtcp_info;
}
void rtcp_add_address( packet_info *pinfo,
address *addr, int port,
int other_port,
const gchar *setup_method, guint32 setup_frame_number)
{
srtcp_add_address(pinfo, addr, port, other_port, setup_method, setup_frame_number, NULL);
}
static gboolean
dissect_rtcp_heur( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
unsigned int offset = 0;
unsigned int first_byte;
unsigned int packet_type;
if (!global_rtcp_heur)
{
return FALSE;
}
if ((pinfo->destport % 2) == 0)
{
return FALSE;
}
first_byte = tvb_get_guint8(tvb, offset);
if (((first_byte & 0xC0) >> 6) != 2)
{
return FALSE;
}
packet_type = tvb_get_guint8(tvb, offset + 1);
if (!((packet_type == RTCP_SR) || (packet_type == RTCP_RR) ||
(packet_type == RTCP_BYE) || (packet_type == RTCP_APP)))
{
return FALSE;
}
if (tvb_reported_length(tvb) % 4)
{
return FALSE;
}
dissect_rtcp(tvb, pinfo, tree);
return TRUE;
}
int dissect_rtcp_length_field( proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_item *ti;
unsigned short raw_length = tvb_get_ntohs( tvb, offset );
ti = proto_tree_add_item( tree, hf_rtcp_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%u bytes)", (raw_length+1)*4);
offset += 2;
return offset;
}
static int
dissect_rtcp_nack( tvbuff_t *tvb, int offset, proto_tree *tree )
{
proto_tree_add_item( tree, hf_rtcp_rc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(tree, tvb, offset);
proto_tree_add_item( tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( tree, hf_rtcp_fsn, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
proto_tree_add_item( tree, hf_rtcp_blp, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
return offset;
}
static int
dissect_rtcp_rtpfb_tmmbr( tvbuff_t *tvb, int offset, proto_tree *rtcp_tree, proto_item *top_item, int num_fci, int is_notification)
{
int bitrate;
int exp;
guint32 mantissa;
proto_item *ti;
proto_tree *fci_tree;
if (is_notification == 1) {
ti = proto_tree_add_text( rtcp_tree, tvb, offset, 8, "TMMBN %d", num_fci );
} else {
ti = proto_tree_add_text( rtcp_tree, tvb, offset, 8, "TMMBR %d", num_fci );
}
fci_tree = proto_item_add_subtree( ti, ett_ssrc );
proto_tree_add_item( fci_tree, hf_rtcp_rtpfb_tmbbr_fci_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( fci_tree, hf_rtcp_rtpfb_tmbbr_fci_exp, tvb, offset, 1, ENC_BIG_ENDIAN );
exp = (tvb_get_guint8(tvb, offset) & 0xfc) >> 2;
proto_tree_add_item( fci_tree, hf_rtcp_rtpfb_tmbbr_fci_mantissa, tvb, offset, 3, ENC_BIG_ENDIAN );
mantissa = (tvb_get_ntohl( tvb, offset) & 0x3fffe00) >> 9;
bitrate = mantissa << exp;
proto_tree_add_string_format_value( fci_tree, hf_rtcp_rtpfb_tmbbr_fci_bitrate, tvb, offset, 3, "", "%u", bitrate);
offset += 3;
proto_tree_add_item( fci_tree, hf_rtcp_rtpfb_tmbbr_fci_measuredoverhead, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
if (top_item != NULL) {
proto_item_append_text(top_item, ": TMMBR: %u", bitrate);
}
return offset;
}
static int
dissect_rtcp_rtpfb_nack( tvbuff_t *tvb, int offset, proto_tree *rtcp_tree, proto_item *top_item)
{
int i;
char strbuf[64];
int nack_num_frames_lost;
proto_tree *bitfield_tree;
unsigned int rtcp_rtpfb_nack_pid;
unsigned int rtcp_rtpfb_nack_blp;
proto_item *ti;
proto_tree_add_item(rtcp_tree, hf_rtcp_rtpfb_nack_pid, tvb, offset, 2, ENC_BIG_ENDIAN);
rtcp_rtpfb_nack_pid = tvb_get_ntohs(tvb, offset);
offset += 2;
ti = proto_tree_add_item(rtcp_tree, hf_rtcp_rtpfb_nack_blp, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_set_text(ti, "RTCP Transport Feedback NACK BLP: ");
rtcp_rtpfb_nack_blp = tvb_get_ntohs(tvb, offset);
bitfield_tree = proto_item_add_subtree( ti, ett_rtcp_nack_blp);
nack_num_frames_lost = 1;
if (rtcp_rtpfb_nack_blp) {
for (i = 0; i < 16; i ++) {
g_snprintf(strbuf, 64, "Frame %d also lost", rtcp_rtpfb_nack_pid + i + 1);
proto_tree_add_text(bitfield_tree, tvb, offset, 2, "%s",
decode_boolean_bitfield(rtcp_rtpfb_nack_blp, (1<<i), 16, strbuf, ""));
if (rtcp_rtpfb_nack_blp & (1<<i)) {
proto_item *hidden_ti;
hidden_ti = proto_tree_add_uint(bitfield_tree, hf_rtcp_rtpfb_nack_pid, tvb, offset, 2, rtcp_rtpfb_nack_pid + i + 1);
PROTO_ITEM_SET_HIDDEN(hidden_ti);
proto_item_append_text(ti, "%d ", rtcp_rtpfb_nack_pid + i + 1);
nack_num_frames_lost ++;
}
}
} else {
proto_item_set_text(ti, "0 (No additional frames lost)");
}
offset += 2;
if (top_item != NULL) {
proto_item_append_text(top_item, ": NACK: %d frames lost", nack_num_frames_lost);
}
return offset;
}
static int
dissect_rtcp_rtpfb( tvbuff_t *tvb, int offset, proto_tree *rtcp_tree, proto_item *top_item)
{
unsigned int counter;
unsigned int rtcp_rtpfb_fmt;
int packet_length;
int start_offset = offset;
proto_tree_add_item( rtcp_tree, hf_rtcp_rtpfb_fmt, tvb, offset, 1, ENC_BIG_ENDIAN );
rtcp_rtpfb_fmt = (tvb_get_guint8(tvb, offset) & 0x1f);
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
packet_length = (tvb_get_ntohs(tvb, offset) + 1) * 4;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
proto_tree_add_item( rtcp_tree, hf_rtcp_ssrc_sender, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( rtcp_tree, hf_rtcp_ssrc_media_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
counter = 0;
while ((offset - start_offset) < packet_length) {
counter++;
if (rtcp_rtpfb_fmt == 1) {
offset = dissect_rtcp_rtpfb_nack(tvb, offset, rtcp_tree, top_item);
} else if (rtcp_rtpfb_fmt == 3) {
offset = dissect_rtcp_rtpfb_tmmbr(tvb, offset, rtcp_tree, top_item, counter, 0);
} else if (rtcp_rtpfb_fmt == 4) {
offset = dissect_rtcp_rtpfb_tmmbr(tvb, offset, rtcp_tree, top_item, counter, 1);
} else {
proto_tree_add_item(rtcp_tree, hf_rtcp_fci, tvb, offset, start_offset + packet_length - offset, ENC_NA );
offset = start_offset + packet_length;
}
}
return offset;
}
static int
dissect_rtcp_psfb( tvbuff_t *tvb, int offset, proto_tree *rtcp_tree,
int packet_length )
{
unsigned int counter;
unsigned int num_fci;
unsigned int read_fci;
proto_tree *fci_tree;
proto_item *ti;
unsigned int rtcp_psfb_fmt;
int base_offset = offset;
proto_tree_add_item( rtcp_tree, hf_rtcp_psfb_fmt, tvb, offset, 1, ENC_BIG_ENDIAN );
rtcp_psfb_fmt = (tvb_get_guint8(tvb, offset) & 0x1f);
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
num_fci = (tvb_get_ntohs(tvb, offset) - 2);
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
proto_tree_add_item( rtcp_tree, hf_rtcp_ssrc_sender, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( rtcp_tree, hf_rtcp_ssrc_media_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
counter = 0;
read_fci = 0;
while ( read_fci < num_fci ) {
if (rtcp_psfb_fmt == 4) {
ti = proto_tree_add_text( rtcp_tree, tvb, offset, 8, "FIR %u", ++counter );
fci_tree = proto_item_add_subtree( ti, ett_ssrc );
proto_tree_add_item( fci_tree, hf_rtcp_psfb_fir_fci_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( fci_tree, hf_rtcp_psfb_fir_fci_csn, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
proto_tree_add_item( fci_tree, hf_rtcp_psfb_fir_fci_reserved, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
read_fci += 2;
} else {
break;
}
}
if ((packet_length - (offset - base_offset)) > 0) {
proto_tree_add_item( rtcp_tree, hf_rtcp_fci, tvb, offset, packet_length - (offset - base_offset), ENC_NA );
offset = base_offset + packet_length;
}
return offset;
}
static int
dissect_rtcp_fir( tvbuff_t *tvb, int offset, proto_tree *tree )
{
proto_tree_add_item( tree, hf_rtcp_rc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(tree, tvb, offset);
proto_tree_add_item( tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
return offset;
}
static int
dissect_rtcp_app( tvbuff_t *tvb,packet_info *pinfo, int offset, proto_tree *tree,
unsigned int padding, unsigned int packet_len, guint rtcp_subtype,
guint32 app_length )
{
unsigned int counter;
char ascii_name[5];
guint sdes_type;
guint item_len;
proto_tree *PoC1_tree;
proto_item *PoC1_item;
static const char poc1_app_name_str[] = "PoC1";
static const char mux_app_name_str[] = "3GPP";
proto_tree_add_item( tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
packet_len -= 4;
for( counter = 0; counter < 4; counter++ )
ascii_name[ counter ] = tvb_get_guint8( tvb, offset + counter );
ascii_name[4] = '\0';
proto_tree_add_string( tree, hf_rtcp_name_ascii, tvb, offset, 4,
ascii_name );
if ( g_ascii_strncasecmp(ascii_name, poc1_app_name_str,4 ) == 0 )
{
guint8 t2timer_code, participants_code;
proto_item *item;
item = proto_tree_add_uint( tree, hf_rtcp_app_poc1_subtype, tvb, offset - 8, 1, rtcp_subtype );
PROTO_ITEM_SET_GENERATED(item);
col_add_fstr(pinfo->cinfo, COL_INFO,"(%s) %s",ascii_name,
val_to_str(rtcp_subtype,rtcp_app_poc1_floor_cnt_type_vals,"unknown (%u)") );
offset += 4;
packet_len -= 4;
app_length = app_length -8;
if ( packet_len == 0 )
return offset;
if ( padding ) {
packet_len -= tvb_get_guint8( tvb, offset + packet_len - 1 );
}
PoC1_item = proto_tree_add_item(tree, hf_rtcp_app_poc1, tvb, offset, packet_len, ENC_NA);
PoC1_tree = proto_item_add_subtree( PoC1_item, ett_PoC1 );
switch ( rtcp_subtype ) {
case TBCP_BURST_REQUEST:
{
guint8 code;
guint16 priority;
if (tvb_reported_length_remaining( tvb, offset) == 0)
{
return offset;
}
code = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (code == 102)
{
item_len = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (item_len != 2)
return offset;
priority = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_priority, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
packet_len -= 2;
col_append_fstr(pinfo->cinfo, COL_INFO,
" \"%s\"",
val_to_str_const(priority,
rtcp_app_poc1_qsresp_priority_vals,
"Unknown"));
if (tvb_reported_length_remaining( tvb, offset) == 0)
{
return offset;
}
code = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
}
if (code == 103)
{
const gchar *buff;
item_len = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (item_len != 8)
return offset;
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_request_ts,
tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
buff = tvb_ntp_fmt_ts(tvb, offset);
offset += 8;
packet_len -= 8;
col_append_fstr(pinfo->cinfo, COL_INFO, " ts=\"%s\"", buff);
}
}
break;
case TBCP_BURST_GRANTED:
{
proto_item *ti;
guint16 stop_talking_time;
guint16 participants;
t2timer_code = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (t2timer_code != 101)
return offset;
item_len = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (item_len != 2)
return offset;
stop_talking_time = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_stt, tvb, offset, 2, ENC_BIG_ENDIAN );
switch (stop_talking_time)
{
case 0:
proto_item_append_text(ti, " unknown");
break;
case 65535:
proto_item_append_text(ti, " infinity");
break;
default:
proto_item_append_text(ti, " seconds");
break;
}
offset += item_len;
packet_len -= item_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " stop-talking-time=%u",
stop_talking_time);
if (tvb_reported_length_remaining( tvb, offset) == 0)
{
return offset;
}
participants_code = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (participants_code != 100)
return offset;
item_len = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (item_len != 2)
return offset;
participants = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_partic, tvb, offset, 2, ENC_BIG_ENDIAN );
switch (participants)
{
case 0:
proto_item_append_text(ti, " (not known)");
break;
case 65535:
proto_item_append_text(ti, " (or more)");
break;
default:
break;
}
offset += item_len;
packet_len -= item_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " participants=%u",
participants);
}
break;
case TBCP_BURST_TAKEN_EXPECT_NO_REPLY:
case TBCP_BURST_TAKEN_EXPECT_REPLY:
{
guint16 participants;
proto_item *ti;
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_ssrc_granted, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
packet_len -= 4;
sdes_type = tvb_get_guint8( tvb, offset );
proto_tree_add_item( PoC1_tree, hf_rtcp_sdes_type, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
packet_len--;
if (sdes_type != RTCP_SDES_CNAME)
{
return offset;
}
item_len = tvb_get_guint8( tvb, offset );
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_sip_uri,
tvb, offset, 1, ENC_ASCII|ENC_NA );
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " CNAME=\"%s\"",
tvb_get_ephemeral_string(tvb, offset, item_len));
offset += item_len;
packet_len = packet_len - item_len - 1;
if ( packet_len == 0 )
return offset;
sdes_type = tvb_get_guint8( tvb, offset );
if (sdes_type == RTCP_SDES_NAME) {
proto_tree_add_item( PoC1_tree, hf_rtcp_sdes_type, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
packet_len--;
item_len = tvb_get_guint8( tvb, offset );
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_disp_name,
tvb, offset, 1, ENC_ASCII|ENC_NA);
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " DISPLAY-NAME=\"%s\"",
tvb_get_ephemeral_string(tvb, offset, item_len));
offset += item_len;
packet_len = packet_len - item_len - 1;
if (packet_len == 0) {
return offset;
}
if (offset % 4) {
int padding2 = (4-(offset%4));
offset += padding2;
packet_len -= padding2;
}
}
if (tvb_reported_length_remaining( tvb, offset) == 0) {
return offset;
}
participants_code = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (participants_code != 100) {
return offset;
}
item_len = tvb_get_guint8(tvb, offset);
offset += 1;
packet_len -= 1;
if (item_len != 2) {
return offset;
}
participants = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_partic, tvb, offset, 2, ENC_BIG_ENDIAN );
switch (participants) {
case 0:
proto_item_append_text(ti, " (not known)");
break;
case 65535:
proto_item_append_text(ti, " (or more)");
break;
default:
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " Participants=%u",
participants);
offset += item_len;
packet_len -= item_len;
}
break;
case TBCP_BURST_DENY:
{
guint8 reason_code;
reason_code = tvb_get_guint8(tvb, offset);
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_reason_code1, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
packet_len--;
col_append_fstr(pinfo->cinfo, COL_INFO, " reason-code=\"%s\"",
val_to_str_const(reason_code,
rtcp_app_poc1_reason_code1_vals,
"Unknown"));
item_len = tvb_get_guint8( tvb, offset );
if ( item_len != 0 )
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_reason1_phrase, tvb, offset, 1, ENC_ASCII|ENC_NA );
offset += (item_len+1);
packet_len -= (item_len+1);
}
break;
case TBCP_BURST_RELEASE:
{
guint16 last_seq_no;
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_last_pkt_seq_no, tvb, offset, 2, ENC_BIG_ENDIAN );
last_seq_no = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(PoC1_tree, hf_rtcp_app_poc1_ignore_seq_no, tvb, offset, 2, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " last_rtp_seq_no=%u",
last_seq_no);
offset += 2;
packet_len -= 4;
}
break;
case TBCP_BURST_IDLE:
break;
case TBCP_BURST_REVOKE:
{
guint16 reason_code = tvb_get_ntohs(tvb, offset);
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_reason_code2, tvb, offset, 2, ENC_BIG_ENDIAN );
switch (reason_code)
{
case 1:
break;
case 2:
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_new_time_request, tvb, offset + 2, 2, ENC_BIG_ENDIAN );
break;
case 3:
break;
case 4:
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " reason-code=\"%s\"",
val_to_str_const(reason_code,
rtcp_app_poc1_reason_code2_vals,
"Unknown"));
offset += 4;
packet_len -= 4;
}
break;
case TBCP_BURST_ACKNOWLEDGMENT:
{
guint8 subtype;
subtype = (tvb_get_guint8(tvb, offset) & 0xf8) >> 3;
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_ack_subtype, tvb, offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " (for %s)",
val_to_str_const(subtype,
rtcp_app_poc1_floor_cnt_type_vals,
"Unknown"));
if (subtype == TBCP_CONNECT)
{
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_ack_reason_code, tvb, offset, 2, ENC_BIG_ENDIAN );
}
offset += 4;
packet_len -= 4;
}
break;
case TBCP_QUEUE_STATUS_REQUEST:
break;
case TBCP_QUEUE_STATUS_RESPONSE:
{
guint16 position;
proto_item *ti;
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_qsresp_priority, tvb, offset, 1, ENC_BIG_ENDIAN );
position = tvb_get_ntohs(tvb, offset+1);
ti = proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_qsresp_position, tvb, offset+1, 2, ENC_BIG_ENDIAN );
if (position == 0)
{
proto_item_append_text(ti, " (client is un-queued)");
}
if (position == 65535)
{
proto_item_append_text(ti, " (position not available)");
}
col_append_fstr(pinfo->cinfo, COL_INFO, " position=%u", position);
offset += 4;
packet_len -= 4;
}
break;
case TBCP_DISCONNECT:
break;
case TBCP_CONNECT:
{
proto_item *content = proto_tree_add_text(PoC1_tree, tvb, offset, 2, "SDES item content");
gboolean contents[5];
unsigned int i;
guint8 items_set = 0;
proto_tree *content_tree = proto_item_add_subtree(content, ett_poc1_conn_contents);
guint16 items_field = tvb_get_ntohs(tvb, offset );
for ( i = 0; i < 5; i++)
{
proto_tree_add_item( content_tree, hf_rtcp_app_poc1_conn_content[i], tvb, offset, 2, ENC_BIG_ENDIAN );
contents[i] = items_field & (1 << (15-i));
if (contents[i]) ++items_set;
}
proto_item_append_text(content, " (%u items)", items_set);
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_conn_session_type, tvb, offset + 2, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_conn_add_ind_mao, tvb, offset + 3, 1, ENC_BIG_ENDIAN );
offset += 4;
packet_len -= 4;
for ( i = 0; i < array_length(contents); ++i ) {
if ( contents[i] ) {
guint sdes_len2;
offset += 1;
sdes_len2 = tvb_get_guint8( tvb, offset );
proto_tree_add_item( PoC1_tree, hf_rtcp_app_poc1_conn_sdes_items[i], tvb, offset, 1, ENC_BIG_ENDIAN );
offset += sdes_len2 + 1;
packet_len -= (sdes_len2 + 2);
}
}
break;
}
default:
break;
}
offset += packet_len;
return offset;
}
else if ( g_ascii_strncasecmp(ascii_name, mux_app_name_str,4 ) == 0 )
{
col_append_fstr(pinfo->cinfo, COL_INFO,"( %s ) subtype=%u",ascii_name, rtcp_subtype);
offset += 4;
packet_len -= 4;
if ( padding ) {
packet_len -= tvb_get_guint8( tvb, offset + packet_len - 1 );
}
if (packet_len == 4)
{
guint16 local_port = 0;
proto_item *mux_item = proto_tree_add_item(tree, hf_rtcp_app_mux, tvb, offset, packet_len, ENC_NA);
proto_tree *mux_tree = proto_item_add_subtree( mux_item, ett_mux );
proto_tree_add_item( mux_tree, hf_rtcp_app_mux_mux, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( mux_tree, hf_rtcp_app_mux_cp, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( mux_tree, hf_rtcp_app_mux_selection, tvb, offset, 1, ENC_BIG_ENDIAN );
local_port = tvb_get_ntohs( tvb, offset+2 );
proto_tree_add_uint( mux_tree, hf_rtcp_app_mux_localmuxport, tvb, offset+2, 2, local_port*2 );
}
else
{
proto_tree_add_item( tree, hf_rtcp_app_data, tvb, offset, packet_len, ENC_NA );
}
offset += packet_len;
return offset;
}
else
{
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset(tvb, offset-8, app_length+4, app_length+4);
if (dissector_try_string(rtcp_dissector_table, ascii_name, next_tvb, pinfo, tree)) {
offset += 4;
packet_len -= 4;
if ( padding ) {
packet_len -= tvb_get_guint8( tvb, offset + packet_len - 1 );
}
offset += packet_len;
return offset;
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO,"( %s ) subtype=%u",ascii_name, rtcp_subtype);
offset += 4;
packet_len -= 4;
if ( padding ) {
packet_len -= tvb_get_guint8( tvb, offset + packet_len - 1 );
}
proto_tree_add_item( tree, hf_rtcp_app_data, tvb, offset, packet_len, ENC_NA );
offset += packet_len;
return offset;
}
}
}
static int
dissect_rtcp_bye( tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
unsigned int count )
{
unsigned int chunk;
unsigned int reason_length = 0;
gint reason_offset = 0;
chunk = 1;
while ( chunk <= count ) {
proto_tree_add_item( tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
chunk++;
}
if ( tvb_reported_length_remaining( tvb, offset ) > 0 ) {
char *reason_text;
reason_length = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtcp_sdes_length, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
reason_offset = offset;
reason_text = (char*)tvb_get_ephemeral_string(tvb, offset, reason_length);
proto_tree_add_string( tree, hf_rtcp_sdes_text, tvb, offset, reason_length, reason_text );
offset += reason_length;
}
if (offset % 4)
{
gint pad_size = (4 - (offset % 4));
int i;
for (i = 0; i < pad_size; i++)
{
if ((!(tvb_offset_exists(tvb, offset + i))) ||
(tvb_get_guint8(tvb, offset + i) != 0))
{
proto_item *ti;
ti = proto_tree_add_none_format(tree, hf_rtcp_bye_reason_not_padded,
tvb, reason_offset, reason_length,
"Reason string is not NULL padded (see RFC3550, section 6.6)");
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_WARN,
"Reason string is not NULL padded (see RFC3550, section 6.6)");
PROTO_ITEM_SET_GENERATED(ti);
}
}
offset += pad_size;
}
return offset;
}
static int
dissect_rtcp_sdes( tvbuff_t *tvb, int offset, proto_tree *tree,
unsigned int count )
{
unsigned int chunk;
proto_item *sdes_item;
proto_tree *sdes_tree;
proto_tree *sdes_item_tree;
proto_item *ti;
int start_offset;
int items_start_offset;
guint32 ssrc;
unsigned int item_len;
unsigned int sdes_type;
unsigned int prefix_len;
chunk = 1;
while ( chunk <= count ) {
start_offset = offset;
ssrc = tvb_get_ntohl( tvb, offset );
sdes_item = proto_tree_add_text(tree, tvb, offset, -1,
"Chunk %u, SSRC/CSRC 0x%X", chunk, ssrc);
sdes_tree = proto_item_add_subtree( sdes_item, ett_sdes );
proto_tree_add_item( sdes_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
items_start_offset = offset;
ti = proto_tree_add_text(sdes_tree, tvb, offset, -1,
"SDES items" );
sdes_item_tree = proto_item_add_subtree( ti, ett_sdes_item );
while ( tvb_reported_length_remaining( tvb, offset ) > 0 ) {
sdes_type = tvb_get_guint8( tvb, offset );
proto_tree_add_item( sdes_item_tree, hf_rtcp_sdes_type, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
if ( sdes_type == RTCP_SDES_END ) {
break;
}
item_len = tvb_get_guint8( tvb, offset );
proto_tree_add_item( sdes_item_tree, hf_rtcp_sdes_length, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
if ( item_len != 0 ) {
if ( sdes_type == RTCP_SDES_PRIV ) {
prefix_len = tvb_get_guint8( tvb, offset );
if ( prefix_len + 1 > item_len ) {
proto_tree_add_uint_format( sdes_item_tree,
hf_rtcp_sdes_prefix_len, tvb,
offset, 1, prefix_len,
"Prefix length: %u (bogus, must be <= %u)",
prefix_len, item_len - 1);
offset += item_len;
continue;
}
proto_tree_add_item( sdes_item_tree, hf_rtcp_sdes_prefix_len, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
proto_tree_add_item( sdes_item_tree, hf_rtcp_sdes_prefix_string, tvb, offset, prefix_len, ENC_ASCII|ENC_NA );
offset += prefix_len;
item_len -= prefix_len +1;
if ( item_len == 0 )
continue;
}
proto_tree_add_item( sdes_item_tree, hf_rtcp_sdes_text, tvb, offset, item_len, ENC_ASCII|ENC_NA );
offset += item_len;
}
}
proto_item_set_len(ti, offset - items_start_offset);
if ( offset % 4 != 0 )
offset = ((offset / 4) + 1 ) * 4;
proto_item_set_len(sdes_item, offset - start_offset);
chunk++;
}
return offset;
}
static void parse_xr_type_specific_field(tvbuff_t *tvb, gint offset, guint block_type, proto_tree *tree)
{
guint8 flags = tvb_get_guint8(tvb, offset);
switch (block_type) {
case RTCP_XR_LOSS_RLE:
case RTCP_XR_DUP_RLE:
case RTCP_XR_PKT_RXTIMES:
proto_tree_add_item(tree, hf_rtcp_xr_thinning, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case RTCP_XR_STATS_SUMRY:
proto_tree_add_boolean(tree, hf_rtcp_xr_stats_loss_flag, tvb, offset, 1, flags);
proto_tree_add_boolean(tree, hf_rtcp_xr_stats_dup_flag, tvb, offset, 1, flags);
proto_tree_add_boolean(tree, hf_rtcp_xr_stats_jitter_flag, tvb, offset, 1, flags);
proto_tree_add_item(tree, hf_rtcp_xr_stats_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_rtcp_xr_block_specific, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
}
static gboolean validate_xr_block_length(tvbuff_t *tvb, packet_info *pinfo, int offset, guint block_type, guint block_len, proto_tree *tree)
{
proto_item *ti;
ti = proto_tree_add_uint(tree, hf_rtcp_xr_block_length, tvb, offset, 2, block_len);
switch (block_type) {
case RTCP_XR_REF_TIME:
if (block_len != 2)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN,
"Invalid block length, should be 2");
return FALSE;
case RTCP_XR_STATS_SUMRY:
if (block_len != 9)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN,
"Invalid block length, should be 9");
return FALSE;
case RTCP_XR_VOIP_METRCS:
case RTCP_XR_BT_XNQ:
if (block_len != 8)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN,
"Invalid block length, should be 8");
return FALSE;
case RTCP_XR_IDMS:
if (block_len != 7)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN,
"Invalid block length, should be 7");
return FALSE;
default:
break;
}
return TRUE;
}
static int
dissect_rtcp_xr(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, gint packet_len)
{
guint block_num;
if (packet_len < 4) {
proto_tree_add_text(tree, tvb, offset, packet_len, "Missing Sender SSRC");
return offset + packet_len;
}
proto_tree_add_item( tree, hf_rtcp_ssrc_sender, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
packet_len -= 4;
for( block_num = 1; packet_len > 0; block_num++) {
guint block_type = tvb_get_guint8(tvb, offset), block_length = 0;
gint content_length = 0;
proto_item *block = proto_tree_add_text(tree, tvb, offset, -1, "Block %u", block_num);
proto_tree *xr_block_tree = proto_item_add_subtree(block, ett_xr_block);
proto_item *contents;
proto_tree *content_tree;
proto_tree_add_item(xr_block_tree, hf_rtcp_xr_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (packet_len >= 2) {
parse_xr_type_specific_field(tvb, offset + 1, block_type, xr_block_tree);
if (packet_len >= 4) {
block_length = tvb_get_ntohs(tvb, offset + 2);
validate_xr_block_length(tvb, pinfo, offset + 2, block_type, block_length, xr_block_tree);
}
} else {
proto_tree_add_text(xr_block_tree, tvb, offset + 1, packet_len, "Missing Required Block Headers");
return offset + packet_len;
}
content_length = block_length * 4;
proto_item_set_len(block, content_length + 4);
if (content_length > packet_len) {
proto_tree_add_text(xr_block_tree, tvb, offset + 2, 2, "Block length is greater than packet length");
}
offset += 4;
packet_len -= 4;
contents = proto_tree_add_text(xr_block_tree, tvb, offset, content_length, "Contents");
content_tree = proto_item_add_subtree(contents, ett_xr_block_contents);
switch (block_type) {
case RTCP_XR_VOIP_METRCS: {
guint fraction_rate;
proto_tree_add_item(content_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
fraction_rate = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(content_tree, hf_rtcp_ssrc_fraction, tvb, offset, 1,
fraction_rate, "Fraction lost: %u / 256", fraction_rate);
offset++;
fraction_rate = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(content_tree, hf_rtcp_ssrc_discarded, tvb, offset, 1,
fraction_rate, "Fraction Discarded: %u / 256", fraction_rate);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_burst_density, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_gap_density, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_burst_duration, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_gap_duration, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_rtdelay, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_esdelay, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_siglevel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_noiselevel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_rerl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_gmin, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_rfactor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_extrfactor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_float(content_tree, hf_rtcp_xr_voip_metrics_moslq, tvb, offset, 1,
(float) (tvb_get_guint8(tvb, offset) / 10.0));
offset++;
proto_tree_add_float(content_tree, hf_rtcp_xr_voip_metrics_moscq, tvb, offset, 1,
(float) (tvb_get_guint8(tvb, offset) / 10.0));
offset++;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_plc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_jbadaptive, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_jbrate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_jbnominal, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_jbmax, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_voip_metrics_jbabsmax, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
case RTCP_XR_STATS_SUMRY: {
proto_tree_add_item(content_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_beginseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_endseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_lost, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_dups, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_minjitter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_maxjitter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_meanjitter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_devjitter, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_minttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_maxttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_meanttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(content_tree, hf_rtcp_xr_stats_devttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
break;
}
case RTCP_XR_REF_TIME: {
guint32 ts_msw, ts_lsw;
ts_msw = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(content_tree, tvb, offset, 4, "Timestamp, MSW: %u", ts_msw);
offset += 4;
ts_lsw = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(content_tree, tvb, offset, 4, "Timestamp, LSW: %u", ts_lsw);
offset += 4;
break;
}
case RTCP_XR_DLRR: {
gint sources = content_length / 12;
gint counter = 0;
for(counter = 0; counter < sources; counter++) {
proto_tree *ti = proto_tree_add_text(content_tree, tvb, offset, 12, "Source %u", counter + 1);
proto_tree *ssrc_tree = proto_item_add_subtree(ti, ett_xr_ssrc);
proto_tree_add_item(ssrc_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ssrc_tree, hf_rtcp_xr_lrr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ssrc_tree, hf_rtcp_xr_dlrr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (content_length % 12 != 0)
offset += content_length % 12;
break;
}
case RTCP_XR_PKT_RXTIMES: {
gint count = 0, skip = 8;
guint16 begin = 0;
proto_tree_add_item(content_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
begin = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(content_tree, hf_rtcp_xr_beginseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_endseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(count = 0; skip < content_length; skip += 4, count++) {
proto_tree_add_text(content_tree, tvb, offset, 4, "Seq: %u, Timestamp: %u",
(begin + count) % 65536, ENC_BIG_ENDIAN);
offset += 4;
}
break;
}
case RTCP_XR_LOSS_RLE:
case RTCP_XR_DUP_RLE: {
gint count = 0, skip = 8;
proto_item *chunks_item;
proto_tree *chunks_tree;
proto_tree_add_item(content_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_beginseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(content_tree, hf_rtcp_xr_endseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
chunks_item = proto_tree_add_text(content_tree, tvb, offset, content_length,"Report Chunks");
chunks_tree = proto_item_add_subtree(chunks_item, ett_xr_loss_chunk);
for(count = 1; skip < content_length; skip += 2, count++) {
guint value = tvb_get_ntohs(tvb, offset);
if (value == 0) {
proto_tree_add_text(chunks_tree, tvb, offset, 2,
"Chunk: %u -- Null Terminator ",
count);
} else if ( ! ( value & 0x8000 )) {
const gchar *run_type = (value & 0x4000) ? "1s" : "0s";
value &= 0x3FFF;
proto_tree_add_text(chunks_tree, tvb, offset, 2,
"Chunk: %u -- Length Run %s, length: %u",
count, run_type, value);
} else {
char bits[20+1];
other_decode_bitfield_value(bits, value, 0x00007FFF, 16);
proto_tree_add_text(chunks_tree, tvb, offset, 2,
"Chunk: %u -- Bit Vector, bits: %s",
count, bits );
}
offset += 2;
}
break;
}
case RTCP_XR_BT_XNQ: {
guint temp_value;
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_begseq, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_endseq, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_vmaxdiff, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_vrange, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_vsum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_cycles, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(content_tree, hf_rtcp_xr_btxnq_jbevents, tvb, offset+2, 2, ENC_BIG_ENDIAN);
offset += 4;
temp_value = tvb_get_ntohl(tvb, offset);
if ((temp_value & 0x0ff000000) != 0)
proto_tree_add_string(content_tree, hf_rtcp_xr_btxnq_spare, tvb, offset, 1, "Warning - spare bits not 0");
proto_tree_add_uint(content_tree, hf_rtcp_xr_btxnq_tdegnet, tvb, offset+1, 3, temp_value & 0x0ffffff);
offset += 4;
temp_value = tvb_get_ntohl(tvb, offset);
if ((temp_value & 0x0ff000000) != 0)
proto_tree_add_string(content_tree, hf_rtcp_xr_btxnq_spare, tvb, offset, 1, "Warning - spare bits not 0");
proto_tree_add_uint(content_tree, hf_rtcp_xr_btxnq_tdegjit, tvb, offset+1, 3, temp_value & 0x0ffffff);
offset += 4;
temp_value = tvb_get_ntohl(tvb, offset);
if ((temp_value & 0x0ff000000) != 0)
proto_tree_add_string(content_tree, hf_rtcp_xr_btxnq_spare, tvb, offset, 1, "Warning - spare bits not 0");
proto_tree_add_uint(content_tree, hf_rtcp_xr_btxnq_es, tvb, offset+1, 3, temp_value & 0x0ffffff);
offset += 4;
temp_value = tvb_get_ntohl(tvb, offset);
if ((temp_value & 0x0ff000000) != 0)
proto_tree_add_string(content_tree, hf_rtcp_xr_btxnq_spare, tvb, offset, 1, "Warning - spare bits not 0");
proto_tree_add_uint(content_tree, hf_rtcp_xr_btxnq_ses, tvb, offset+1, 3, temp_value & 0x0ffffff);
offset += 4;
break;
}
case RTCP_XR_IDMS: {
proto_item *item;
int hour,min,sec,msec;
guint32 tmp_ts;
offset -= 3;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_spst, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=3;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_pt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_msci, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_source_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_ntp_rcv_ts_msw, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_ntp_rcv_ts_lsw, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
item = proto_tree_add_item(content_tree, hf_rtcp_ntp, tvb, offset-8, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_rtp_ts, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(content_tree, hf_rtcp_xr_idms_ntp_pres_ts, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
tmp_ts = tvb_get_ntohl(tvb,offset-4);
hour = ( (int) ( tmp_ts >> 16 ) ) / 3600;
min = (( (int) ( tmp_ts >> 16 ) ) - hour * 3600) / 60;
sec = (( (int) ( tmp_ts >> 16 ) ) - hour * 3600 - min * 60);
msec = ( (int) ( tmp_ts & 0x0000FFFF ) ) / 66;
item = proto_tree_add_text( content_tree, tvb, offset-4, 4,
"short NTP timestamp of presentation: %d:%02d:%02d:%03d [h:m:s:ms] ",
hour,min,sec,msec);
PROTO_ITEM_SET_GENERATED(item);
}
break;
default:
offset += content_length;
break;
}
packet_len -= content_length;
}
return offset;
}
static int
dissect_rtcp_rr( packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree,
unsigned int count, unsigned int packet_length )
{
unsigned int counter;
proto_tree *ssrc_tree;
proto_tree *ssrc_sub_tree;
proto_tree *high_sec_tree;
proto_item *ti;
guint8 rr_flt;
int rr_offset = offset;
counter = 1;
while ( counter <= count ) {
guint32 lsr, dlsr;
ti = proto_tree_add_text(tree, tvb, offset, 24,
"Source %u", counter );
ssrc_tree = proto_item_add_subtree( ti, ett_ssrc );
proto_tree_add_item( ssrc_tree, hf_rtcp_ssrc_source, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
ti = proto_tree_add_text(ssrc_tree, tvb, offset, 20, "SSRC contents" );
ssrc_sub_tree = proto_item_add_subtree( ti, ett_ssrc_item );
rr_flt = tvb_get_guint8( tvb, offset );
proto_tree_add_uint_format( ssrc_sub_tree, hf_rtcp_ssrc_fraction, tvb,
offset, 1, rr_flt, "Fraction lost: %u / 256", rr_flt );
offset++;
proto_tree_add_item( ssrc_sub_tree, hf_rtcp_ssrc_cum_nr, tvb,
offset, 3, ENC_BIG_ENDIAN );
offset += 3;
ti = proto_tree_add_item( ssrc_tree, hf_rtcp_ssrc_ext_high_seq,
tvb, offset, 4, ENC_BIG_ENDIAN );
high_sec_tree = proto_item_add_subtree( ti, ett_ssrc_ext_high );
proto_tree_add_item( high_sec_tree, hf_rtcp_ssrc_high_cycles,
tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
proto_tree_add_item( high_sec_tree, hf_rtcp_ssrc_high_seq,
tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
proto_tree_add_item( ssrc_tree, hf_rtcp_ssrc_jitter, tvb,
offset, 4, ENC_BIG_ENDIAN );
offset += 4;
lsr = tvb_get_ntohl( tvb, offset );
proto_tree_add_item( ssrc_tree, hf_rtcp_ssrc_lsr, tvb,
offset, 4, ENC_BIG_ENDIAN );
offset += 4;
dlsr = tvb_get_ntohl( tvb, offset );
ti = proto_tree_add_item( ssrc_tree, hf_rtcp_ssrc_dlsr, tvb,
offset, 4, ENC_BIG_ENDIAN );
proto_item_append_text(ti, " (%d milliseconds)",
(int)(((double)dlsr/(double)65536) * 1000.0));
offset += 4;
if (global_rtcp_show_roundtrip_calculation)
{
calculate_roundtrip_delay(tvb, pinfo, ssrc_tree, lsr, dlsr);
}
counter++;
}
if ((offset-rr_offset) < (int)packet_length)
{
proto_tree_add_item(tree, hf_rtcp_profile_specific_extension, tvb, offset,
packet_length - (offset - rr_offset), ENC_NA);
offset = rr_offset + packet_length;
}
return offset;
}
static int
dissect_rtcp_sr( packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree,
unsigned int count, unsigned int packet_length )
{
proto_item *item;
guint32 ts_msw, ts_lsw;
int sr_offset = offset;
ts_msw = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_rtcp_ntp_msw, tvb, offset, 4, ENC_BIG_ENDIAN);
ts_lsw = tvb_get_ntohl(tvb, offset+4);
proto_tree_add_item(tree, hf_rtcp_ntp_lsw, tvb, offset+4, 4, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tree, hf_rtcp_ntp, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
PROTO_ITEM_SET_GENERATED(item);
offset += 8;
proto_tree_add_item( tree, hf_rtcp_rtp_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( tree, hf_rtcp_sender_pkt_cnt, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( tree, hf_rtcp_sender_oct_cnt, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
if (global_rtcp_show_roundtrip_calculation)
{
guint32 lsr = ((ts_msw & 0x0000ffff) << 16 | (ts_lsw & 0xffff0000) >> 16);
remember_outgoing_sr(pinfo, lsr);
}
if ( count != 0 )
offset = dissect_rtcp_rr( pinfo, tvb, offset, tree, count, packet_length-(offset-sr_offset) );
else
{
if ((offset-sr_offset) < (int)packet_length)
{
proto_tree_add_item(tree, hf_rtcp_profile_specific_extension, tvb, offset,
packet_length - (offset - sr_offset), ENC_NA);
offset = sr_offset + packet_length;
}
}
return offset;
}
void show_setup_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct _rtcp_conversation_info *p_conv_data;
p_conv_data = p_get_proto_data(pinfo->fd, proto_rtcp);
if (!p_conv_data)
{
conversation_t *p_conv;
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src,
pinfo->ptype,
pinfo->destport, pinfo->srcport, NO_ADDR_B);
if (p_conv)
{
struct _rtcp_conversation_info *p_conv_packet_data;
p_conv_data = conversation_get_proto_data(p_conv, proto_rtcp);
if (p_conv_data)
{
p_conv_packet_data = se_memdup(p_conv_data,
sizeof(struct _rtcp_conversation_info));
p_add_proto_data(pinfo->fd, proto_rtcp, p_conv_packet_data);
}
}
}
if (p_conv_data && p_conv_data->setup_method_set)
{
proto_tree *rtcp_setup_tree;
proto_item *ti = proto_tree_add_string_format(tree, hf_rtcp_setup, tvb, 0, 0,
"",
"Stream setup by %s (frame %u)",
p_conv_data->setup_method,
p_conv_data->setup_frame_number);
PROTO_ITEM_SET_GENERATED(ti);
rtcp_setup_tree = proto_item_add_subtree(ti, ett_rtcp_setup);
if (rtcp_setup_tree)
{
proto_item *item = proto_tree_add_uint(rtcp_setup_tree, hf_rtcp_setup_frame,
tvb, 0, 0, p_conv_data->setup_frame_number);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(rtcp_setup_tree, hf_rtcp_setup_method,
tvb, 0, 0, p_conv_data->setup_method);
PROTO_ITEM_SET_GENERATED(item);
}
}
}
static void remember_outgoing_sr(packet_info *pinfo, long lsr)
{
conversation_t *p_conv;
struct _rtcp_conversation_info *p_conv_data;
struct _rtcp_conversation_info *p_packet_data;
p_packet_data = p_get_proto_data(pinfo->fd, proto_rtcp);
if (p_packet_data && p_packet_data->last_received_set &&
(p_packet_data->last_received_frame_number >= pinfo->fd->num))
{
return;
}
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src,
pinfo->ptype,
pinfo->destport, pinfo->srcport, NO_ADDR_B);
if (!p_conv)
{
p_conv = conversation_new(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src, PT_UDP,
pinfo->destport, pinfo->srcport,
NO_ADDR2);
if (!p_conv)
{
return;
}
}
p_conv_data = conversation_get_proto_data(p_conv, proto_rtcp);
if (!p_conv_data)
{
p_conv_data = se_alloc0(sizeof(struct _rtcp_conversation_info));
conversation_add_proto_data(p_conv, proto_rtcp, p_conv_data);
}
p_conv_data->last_received_set = TRUE;
p_conv_data->last_received_frame_number = pinfo->fd->num;
p_conv_data->last_received_timestamp = pinfo->fd->abs_ts;
p_conv_data->last_received_ts = lsr;
if (!p_packet_data)
{
p_packet_data = se_alloc0(sizeof(struct _rtcp_conversation_info));
p_add_proto_data(pinfo->fd, proto_rtcp, p_packet_data);
}
p_packet_data->last_received_set = TRUE;
p_packet_data->last_received_frame_number = p_conv_data->last_received_frame_number;
}
static void calculate_roundtrip_delay(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 lsr, guint32 dlsr)
{
conversation_t *p_conv;
struct _rtcp_conversation_info *p_conv_data;
struct _rtcp_conversation_info *p_packet_data;
p_packet_data = p_get_proto_data(pinfo->fd, proto_rtcp);
if (p_packet_data && p_packet_data->lsr_matched)
{
add_roundtrip_delay_info(tvb, pinfo, tree,
p_packet_data->calculated_delay_used_frame,
p_packet_data->calculated_delay_report_gap,
p_packet_data->calculated_delay);
return;
}
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_src, &pinfo->net_dst,
pinfo->ptype,
pinfo->srcport, pinfo->destport, NO_ADDR_B);
if (!p_conv)
{
return;
}
p_conv_data = conversation_get_proto_data(p_conv, proto_rtcp);
if (!p_conv_data)
{
return;
}
if (p_conv_data->last_received_set)
{
if (!p_packet_data)
{
p_packet_data = se_alloc0(sizeof(struct _rtcp_conversation_info));
p_add_proto_data(pinfo->fd, proto_rtcp, p_packet_data);
}
if (pinfo->fd->num <= p_conv_data->last_received_frame_number)
{
return;
}
if (p_conv_data->last_received_ts == lsr)
{
gint seconds_between_packets = (gint)
(pinfo->fd->abs_ts.secs - p_conv_data->last_received_timestamp.secs);
gint nseconds_between_packets =
pinfo->fd->abs_ts.nsecs - p_conv_data->last_received_timestamp.nsecs;
gint total_gap = (seconds_between_packets*1000) +
(nseconds_between_packets / 1000000);
gint dlsr_ms = (int)(((double)dlsr/(double)65536) * 1000.0);
gint delay;
delay = total_gap - dlsr_ms;
p_packet_data->lsr_matched = TRUE;
if (dlsr)
{
p_packet_data->calculated_delay = delay;
p_packet_data->calculated_delay_report_gap = total_gap;
p_packet_data->calculated_delay_used_frame = p_conv_data->last_received_frame_number;
}
add_roundtrip_delay_info(tvb, pinfo, tree,
p_conv_data->last_received_frame_number,
total_gap,
delay);
}
}
}
static void add_roundtrip_delay_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint frame, guint gap_between_reports,
gint delay)
{
proto_item *item = proto_tree_add_uint(tree,
hf_rtcp_last_sr_timestamp_frame,
tvb, 0, 0, frame);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint(tree,
hf_rtcp_time_since_last_sr,
tvb, 0, 0, gap_between_reports);
PROTO_ITEM_SET_GENERATED(item);
if (abs(delay) < (int)global_rtcp_show_roundtrip_calculation_minimum)
{
return;
}
item = proto_tree_add_int(tree, hf_rtcp_roundtrip_delay, tvb, 0, 0, delay);
PROTO_ITEM_SET_GENERATED(item);
if (delay >= 0)
{
expert_add_info_format(pinfo, item,
PI_SEQUENCE, PI_NOTE,
"RTCP round-trip delay detected (%d ms)",
delay);
}
else
{
expert_add_info_format(pinfo, item,
PI_SEQUENCE, PI_ERROR,
"Negative RTCP round-trip delay detected (%d ms)",
delay);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" (roundtrip delay <-> %s = %dms, using frame %u) ",
ep_address_to_str(&pinfo->net_src), delay, frame);
}
static int
rtcp_packet_type_to_tree( int rtcp_packet_type)
{
int tree;
switch(rtcp_packet_type) {
case RTCP_SR: tree = ett_rtcp_sr; break;
case RTCP_RR: tree = ett_rtcp_rr; break;
case RTCP_SDES: tree = ett_rtcp_sdes; break;
case RTCP_BYE: tree = ett_rtcp_bye; break;
case RTCP_APP: tree = ett_rtcp_app; break;
case RTCP_RTPFB: tree = ett_rtcp_rtpfb; break;
case RTCP_PSFB: tree = ett_rtcp_psfb; break;
case RTCP_XR: tree = ett_rtcp_xr; break;
case RTCP_FIR: tree = ett_rtcp_fir; break;
case RTCP_NACK: tree = ett_rtcp_nack; break;
default: tree = ett_rtcp;
}
return tree;
}
static void
dissect_rtcp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti;
proto_tree *rtcp_tree = NULL;
guint padding_set = 0;
guint offset = 0;
guint total_packet_length = 0;
guint padding_offset = 0;
gboolean srtcp_encrypted = FALSE;
gboolean srtcp_now_encrypted = FALSE;
conversation_t *p_conv;
struct srtp_info *srtcp_info = NULL;
guint32 srtcp_offset = 0;
guint32 srtcp_index = 0;
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_src, &pinfo->net_dst,
pinfo->ptype,
pinfo->srcport, pinfo->destport, NO_ADDR_B);
if (p_conv)
{
struct _rtcp_conversation_info *p_conv_data;
p_conv_data = conversation_get_proto_data(p_conv, proto_rtcp);
if (p_conv_data && p_conv_data->srtcp_info)
{
gboolean e_bit;
srtcp_info = p_conv_data->srtcp_info;
srtcp_offset = tvb_length_remaining(tvb, offset) - srtcp_info->auth_tag_len - srtcp_info->mki_len - 4;
srtcp_index = tvb_get_ntohl(tvb,srtcp_offset);
e_bit = (srtcp_index & 0x80000000) ? TRUE : FALSE;
srtcp_index &= 0x7fffffff;
if (srtcp_info->encryption_algorithm!=SRTP_ENC_ALG_NULL) {
if (e_bit)
srtcp_encrypted = TRUE;
}
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, (srtcp_info) ? "SRTCP" : "RTCP");
while ( !srtcp_now_encrypted && tvb_bytes_exist( tvb, offset, 4) ) {
guint temp_byte;
guint elem_count;
guint packet_type;
guint packet_length;
packet_type = tvb_get_guint8( tvb, offset + 1 );
if ( ( packet_type < 192 ) || ( packet_type > 207 ) )
break;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_const(packet_type, rtcp_packet_type_vals, "Unknown"));
packet_length = ( tvb_get_ntohs( tvb, offset + 2 ) + 1 ) * 4;
total_packet_length += packet_length;
ti = proto_tree_add_item(tree, proto_rtcp, tvb, offset, packet_length, ENC_NA );
proto_item_append_text(ti, " (%s)",
val_to_str_const(packet_type,
rtcp_packet_type_vals,
"Unknown"));
rtcp_tree = proto_item_add_subtree( ti, rtcp_packet_type_to_tree(packet_type) );
if (global_rtcp_show_setup_info)
{
show_setup_info(tvb, pinfo, rtcp_tree);
}
temp_byte = tvb_get_guint8( tvb, offset );
proto_tree_add_item( rtcp_tree, hf_rtcp_version, tvb,
offset, 1, ENC_BIG_ENDIAN);
padding_set = RTCP_PADDING( temp_byte );
padding_offset = offset + packet_length - 1;
proto_tree_add_boolean( rtcp_tree, hf_rtcp_padding, tvb,
offset, 1, temp_byte );
elem_count = RTCP_COUNT( temp_byte );
switch ( packet_type ) {
case RTCP_SR:
case RTCP_RR:
proto_tree_add_uint( rtcp_tree, hf_rtcp_rc, tvb, offset, 1, temp_byte );
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
proto_tree_add_item( rtcp_tree, hf_rtcp_ssrc_sender, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
if (srtcp_encrypted) {
srtcp_now_encrypted = TRUE;
break;
}
if ( packet_type == RTCP_SR )
offset = dissect_rtcp_sr( pinfo, tvb, offset, rtcp_tree, elem_count, packet_length-8 );
else
offset = dissect_rtcp_rr( pinfo, tvb, offset, rtcp_tree, elem_count, packet_length-8 );
break;
case RTCP_SDES:
proto_tree_add_uint( rtcp_tree, hf_rtcp_sc, tvb, offset, 1, temp_byte );
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
offset = dissect_rtcp_sdes( tvb, offset, rtcp_tree, elem_count );
break;
case RTCP_BYE:
proto_tree_add_uint( rtcp_tree, hf_rtcp_sc, tvb, offset, 1, temp_byte );
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
offset = dissect_rtcp_bye( tvb, pinfo, offset, rtcp_tree, elem_count );
break;
case RTCP_APP: {
guint rtcp_subtype;
guint app_length;
rtcp_subtype = elem_count;
proto_tree_add_uint( rtcp_tree, hf_rtcp_subtype, tvb, offset, 1, elem_count );
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
app_length = tvb_get_ntohs( tvb, offset ) <<2;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
offset = dissect_rtcp_app( tvb, pinfo, offset,rtcp_tree, padding_set, packet_length - 4, rtcp_subtype, app_length);
}
break;
case RTCP_XR:
offset++;
proto_tree_add_item( rtcp_tree, hf_rtcp_pt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
offset = dissect_rtcp_length_field(rtcp_tree, tvb, offset);
offset = dissect_rtcp_xr( tvb, pinfo, offset, rtcp_tree, packet_length - 4 );
break;
case RTCP_FIR:
offset = dissect_rtcp_fir( tvb, offset, rtcp_tree );
break;
case RTCP_NACK:
offset = dissect_rtcp_nack( tvb, offset, rtcp_tree );
break;
case RTCP_RTPFB:
offset = dissect_rtcp_rtpfb( tvb, offset, rtcp_tree, ti );
break;
case RTCP_PSFB:
offset = dissect_rtcp_psfb( tvb, offset, rtcp_tree, packet_length );
break;
default:
offset++;
break;
}
col_set_fence(pinfo->cinfo, COL_INFO);
}
if ( padding_set ) {
guint padding_length;
padding_length = tvb_get_guint8( tvb, padding_offset);
if (padding_length != 0) {
proto_tree_add_item( rtcp_tree, hf_rtcp_padding_data, tvb, offset, padding_length - 1, ENC_NA );
offset += padding_length - 1;
}
proto_tree_add_item( rtcp_tree, hf_rtcp_padding_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
}
if (srtcp_encrypted == TRUE) {
proto_tree_add_text(rtcp_tree, tvb, offset, srtcp_offset-offset, "Encrypted RTCP Payload - not dissected");
proto_tree_add_item(rtcp_tree, hf_srtcp_e, tvb, srtcp_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint(rtcp_tree, hf_srtcp_index, tvb, srtcp_offset, 4, srtcp_index);
srtcp_offset += 4;
if (srtcp_info->mki_len) {
proto_tree_add_item(rtcp_tree, hf_srtcp_mki, tvb, srtcp_offset, srtcp_info->mki_len, ENC_NA);
srtcp_offset += srtcp_info->mki_len;
}
if (srtcp_info->auth_tag_len) {
proto_tree_add_item(rtcp_tree, hf_srtcp_auth_tag, tvb, srtcp_offset, srtcp_info->auth_tag_len, ENC_NA);
srtcp_offset += srtcp_info->auth_tag_len;
}
}
else if (offset == total_packet_length)
{
ti = proto_tree_add_boolean_format_value(tree, hf_rtcp_length_check, tvb,
0, 0, TRUE, "OK - %u bytes",
offset);
PROTO_ITEM_SET_GENERATED(ti);
}
else
{
ti = proto_tree_add_boolean_format_value(tree, hf_rtcp_length_check, tvb,
0, 0, FALSE,
"Wrong (expected %u bytes, found %d)",
total_packet_length, offset);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti,
PI_MALFORMED, PI_WARN,
"Incorrect RTCP packet length information (expected %u bytes, found %d)",
total_packet_length, offset);
}
}
void
proto_register_rtcp(void)
{
static hf_register_info hf[] = {
{
&hf_rtcp_version,
{
"Version",
"rtcp.version",
FT_UINT8,
BASE_DEC,
VALS(rtcp_version_vals),
0xC0,
NULL, HFILL
}
},
{
&hf_rtcp_padding,
{
"Padding",
"rtcp.padding",
FT_BOOLEAN,
8,
NULL,
0x20,
NULL, HFILL
}
},
{
&hf_rtcp_rc,
{
"Reception report count",
"rtcp.rc",
FT_UINT8,
BASE_DEC,
NULL,
0x1F,
NULL, HFILL
}
},
{
&hf_rtcp_sc,
{
"Source count",
"rtcp.sc",
FT_UINT8,
BASE_DEC,
NULL,
0x1F,
NULL, HFILL
}
},
{
&hf_rtcp_pt,
{
"Packet type",
"rtcp.pt",
FT_UINT8,
BASE_DEC,
VALS( rtcp_packet_type_vals ),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_length,
{
"Length",
"rtcp.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"32-bit words (-1) in packet", HFILL
}
},
{
&hf_rtcp_ssrc_sender,
{
"Sender SSRC",
"rtcp.senderssrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_media_source,
{
"Media source SSRC",
"rtcp.mediassrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ntp_msw,
{
"Timestamp, MSW",
"rtcp.timestamp.ntp.msw",
FT_UINT32,
BASE_DEC_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ntp_lsw,
{
"Timestamp, LSW",
"rtcp.timestamp.ntp.lsw",
FT_UINT32,
BASE_DEC_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ntp,
{
"MSW and LSW as NTP timestamp",
"rtcp.timestamp.ntp",
FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_UTC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_rtp_timestamp,
{
"RTP timestamp",
"rtcp.timestamp.rtp",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sender_pkt_cnt,
{
"Sender's packet count",
"rtcp.sender.packetcount",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sender_oct_cnt,
{
"Sender's octet count",
"rtcp.sender.octetcount",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_source,
{
"Identifier",
"rtcp.ssrc.identifier",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_fraction,
{
"Fraction lost",
"rtcp.ssrc.fraction",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_cum_nr,
{
"Cumulative number of packets lost",
"rtcp.ssrc.cum_nr",
FT_INT24,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_ext_high_seq,
{
"Extended highest sequence number received",
"rtcp.ssrc.ext_high",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_high_seq,
{
"Highest sequence number received",
"rtcp.ssrc.high_seq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_high_cycles,
{
"Sequence number cycles count",
"rtcp.ssrc.high_cycles",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_jitter,
{
"Interarrival jitter",
"rtcp.ssrc.jitter",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_lsr,
{
"Last SR timestamp",
"rtcp.ssrc.lsr",
FT_UINT32,
BASE_DEC_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_dlsr,
{
"Delay since last SR timestamp",
"rtcp.ssrc.dlsr",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_ssrc_csrc,
{
"SSRC / CSRC identifier",
"rtcp.sdes.ssrc_csrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sdes_type,
{
"Type",
"rtcp.sdes.type",
FT_UINT8,
BASE_DEC,
VALS( rtcp_sdes_type_vals ),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sdes_length,
{
"Length",
"rtcp.sdes.length",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sdes_text,
{
"Text",
"rtcp.sdes.text",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sdes_prefix_len,
{
"Prefix length",
"rtcp.sdes.prefix.length",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_sdes_prefix_string,
{
"Prefix string",
"rtcp.sdes.prefix.string",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_subtype,
{
"Subtype",
"rtcp.app.subtype",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_name_ascii,
{
"Name (ASCII)",
"rtcp.app.name",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_data,
{
"Application specific data",
"rtcp.app.data",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1,
{
"PoC1 Application specific data",
"rtcp.app.poc1",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_subtype,
{
"Subtype",
"rtcp.app.PoC1.subtype",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_floor_cnt_type_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_sip_uri,
{
"SIP URI",
"rtcp.app.poc1.sip.uri",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_disp_name,
{
"Display Name",
"rtcp.app.poc1.disp.name",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_priority,
{
"Priority",
"rtcp.app.poc1.priority",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_qsresp_priority_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_request_ts,
{
"Talk Burst Request Timestamp",
"rtcp.app.poc1.request.ts",
FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_UTC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_stt,
{
"Stop talking timer",
"rtcp.app.poc1.stt",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_partic,
{
"Number of participants",
"rtcp.app.poc1.participants",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_ssrc_granted,
{
"SSRC of client granted permission to talk",
"rtcp.app.poc1.ssrc.granted",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_last_pkt_seq_no,
{
"Sequence number of last RTP packet",
"rtcp.app.poc1.last.pkt.seq.no",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_ignore_seq_no,
{
"Ignore sequence number field",
"rtcp.app.poc1.ignore.seq.no",
FT_UINT16,
BASE_HEX,
NULL,
0x8000,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_reason_code1,
{
"Reason code",
"rtcp.app.poc1.reason.code",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_reason_code1_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_reason1_phrase,
{
"Reason Phrase",
"rtcp.app.poc1.reason.phrase",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_reason_code2,
{
"Reason code",
"rtcp.app.poc1.reason.code",
FT_UINT16,
BASE_DEC,
VALS(rtcp_app_poc1_reason_code2_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_new_time_request,
{
"New time client can request (seconds)",
"rtcp.app.poc1.new.time.request",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Time in seconds client can request for", HFILL
}
},
{
&hf_rtcp_app_poc1_ack_subtype,
{
"Subtype",
"rtcp.app.poc1.ack.subtype",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_floor_cnt_type_vals),
0xf8,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_ack_reason_code,
{
"Reason code",
"rtcp.app.poc1.ack.reason.code",
FT_UINT16,
BASE_DEC,
VALS(rtcp_app_poc1_reason_code_ack_vals),
0x07ff,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_qsresp_priority,
{
"Priority",
"rtcp.app.poc1.qsresp.priority",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_qsresp_priority_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_qsresp_position,
{
"Position (number of clients ahead)",
"rtcp.app.poc1.qsresp.position",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_content[0],
{
"Identity of inviting client",
"rtcp.app.poc1.conn.content.a.id",
FT_BOOLEAN,
16,
NULL,
0x8000,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_content[1],
{
"Nick name of inviting client",
"rtcp.app.poc1.conn.content.a.dn",
FT_BOOLEAN,
16,
NULL,
0x4000,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_content[2],
{
"Session identity",
"rtcp.app.poc1.conn.content.sess.id",
FT_BOOLEAN,
16,
NULL,
0x2000,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_content[3],
{
"Group name",
"rtcp.app.poc1.conn.content.grp.dn",
FT_BOOLEAN,
16,
NULL,
0x1000,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_content[4],
{
"Group identity",
"rtcp.app.poc1.conn.content.grp.id",
FT_BOOLEAN,
16,
NULL,
0x0800,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_session_type,
{
"Session type",
"rtcp.app.poc1.conn.session.type",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_poc1_conn_sess_type_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_add_ind_mao,
{
"Manual answer override",
"rtcp.app.poc1.conn.add.ind.mao",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_sdes_items[0],
{
"Identity of inviting client",
"rtcp.app.poc1.conn.sdes.a.id",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_sdes_items[1],
{
"Nick name of inviting client",
"rtcp.app.poc1.conn.sdes.a.dn",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_sdes_items[2],
{
"Session identity",
"rtcp.app.poc1.conn.sdes.sess.id",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_sdes_items[3],
{
"Group Name",
"rtcp.app.poc1.conn.sdes.grp.dn",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_poc1_conn_sdes_items[4],
{
"Group identity",
"rtcp.app.poc1.conn.sdes.grp.id",
FT_UINT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_mux,
{
"RtpMux Application specific data",
"rtcp.app.mux",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_app_mux_mux,
{
"Multiplexing supported",
"rtcp.app.mux.mux",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtcp_app_mux_cp,
{
"Header compression supported",
"rtcp.app.mux.cp",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_rtcp_app_mux_selection,
{
"Multiplexing selection",
"rtcp.app.mux.selection",
FT_UINT8,
BASE_DEC,
VALS(rtcp_app_mux_selection_vals),
0x30,
NULL, HFILL
}
},
{
&hf_rtcp_app_mux_localmuxport,
{
"Local Mux Port",
"rtcp.app.mux.muxport",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_fsn,
{
"First sequence number",
"rtcp.nack.fsn",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_blp,
{
"Bitmask of following lost packets",
"rtcp.nack.blp",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_padding_count,
{
"Padding count",
"rtcp.padding.count",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_padding_data,
{
"Padding data",
"rtcp.padding.data",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_profile_specific_extension,
{
"Profile-specific extension",
"rtcp.profile-specific-extension",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_setup,
{
"Stream setup",
"rtcp.setup",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"Stream setup, method and frame number", HFILL
}
},
{
&hf_rtcp_setup_frame,
{
"Setup frame",
"rtcp.setup-frame",
FT_FRAMENUM,
BASE_NONE,
NULL,
0x0,
"Frame that set up this stream", HFILL
}
},
{
&hf_rtcp_setup_method,
{
"Setup Method",
"rtcp.setup-method",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"Method used to set up this stream", HFILL
}
},
{
&hf_rtcp_last_sr_timestamp_frame,
{
"Frame matching Last SR timestamp",
"rtcp.lsr-frame",
FT_FRAMENUM,
BASE_NONE,
NULL,
0x0,
"Frame matching LSR field (used to calculate roundtrip delay)", HFILL
}
},
{
&hf_rtcp_time_since_last_sr,
{
"Time since Last SR captured",
"rtcp.lsr-frame-captured",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
"Time since frame matching LSR field was captured", HFILL
}
},
{
&hf_rtcp_roundtrip_delay,
{
"Roundtrip Delay(ms)",
"rtcp.roundtrip-delay",
FT_INT32,
BASE_DEC,
NULL,
0x0,
"Calculated roundtrip delay in ms", HFILL
}
},
{
&hf_rtcp_xr_block_type,
{
"Type",
"rtcp.xr.bt",
FT_UINT8,
BASE_DEC,
VALS(rtcp_xr_type_vals),
0x0,
"Block Type", HFILL
}
},
{
&hf_rtcp_xr_block_specific,
{
"Type Specific",
"rtcp.xr.bs",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Reserved", HFILL
}
},
{
&hf_rtcp_xr_block_length,
{
"Length",
"rtcp.xr.bl",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Block Length", HFILL
}
},
{
&hf_rtcp_ssrc_discarded,
{
"Fraction discarded",
"rtcp.ssrc.discarded",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Discard Rate", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_burst_density,
{
"Burst Density",
"rtcp.xr.voipmetrics.burstdensity",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_gap_density,
{
"Gap Density",
"rtcp.xr.voipmetrics.gapdensity",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_burst_duration,
{
"Burst Duration(ms)",
"rtcp.xr.voipmetrics.burstduration",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_gap_duration,
{
"Gap Duration(ms)",
"rtcp.xr.voipmetrics.gapduration",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_rtdelay,
{
"Round Trip Delay(ms)",
"rtcp.xr.voipmetrics.rtdelay",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_esdelay,
{
"End System Delay(ms)",
"rtcp.xr.voipmetrics.esdelay",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_siglevel,
{
"Signal Level",
"rtcp.xr.voipmetrics.signallevel",
FT_INT8,
BASE_DEC,
NULL,
0x0,
"Signal level of 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_noiselevel,
{
"Noise Level",
"rtcp.xr.voipmetrics.noiselevel",
FT_INT8,
BASE_DEC,
NULL,
0x0,
"Noise level of 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_rerl,
{
"Residual Echo Return Loss",
"rtcp.xr.voipmetrics.rerl",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_gmin,
{
"Gmin",
"rtcp.xr.voipmetrics.gmin",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_rfactor,
{
"R Factor",
"rtcp.xr.voipmetrics.rfactor",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"R Factor is in the range of 0 to 100; 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_extrfactor,
{
"External R Factor",
"rtcp.xr.voipmetrics.extrfactor",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"R Factor is in the range of 0 to 100; 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_moslq,
{
"MOS - Listening Quality",
"rtcp.xr.voipmetrics.moslq",
FT_FLOAT,
BASE_NONE,
NULL,
0x0,
"MOS is in the range of 1 to 5; 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_moscq,
{
"MOS - Conversational Quality",
"rtcp.xr.voipmetrics.moscq",
FT_FLOAT,
BASE_NONE,
NULL,
0x0,
"MOS is in the range of 1 to 5; 127 indicates this parameter is unavailable", HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_plc,
{
"Packet Loss Concealment Algorithm",
"rtcp.xr.voipmetrics.plc",
FT_UINT8,
BASE_DEC,
VALS(rtcp_xr_plc_algo_vals),
0xC0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_jbadaptive,
{
"Adaptive Jitter Buffer Algorithm",
"rtcp.xr.voipmetrics.jba",
FT_UINT8,
BASE_DEC,
VALS(rtcp_xr_jb_adaptive_vals),
0x30,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_jbrate,
{
"Jitter Buffer Rate",
"rtcp.xr.voipmetrics.jbrate",
FT_UINT8,
BASE_DEC,
NULL,
0x0F,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_jbnominal,
{
"Nominal Jitter Buffer Size",
"rtcp.xr.voipmetrics.jbnominal",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_jbmax,
{
"Maximum Jitter Buffer Size",
"rtcp.xr.voipmetrics.jbmax",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_voip_metrics_jbabsmax,
{
"Absolute Maximum Jitter Buffer Size",
"rtcp.xr.voipmetrics.jbabsmax",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_thinning,
{
"Thinning factor",
"rtcp.xr.tf",
FT_UINT8,
BASE_DEC,
NULL,
0x0F,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_loss_flag,
{
"Loss Report Flag",
"rtcp.xr.stats.lrflag",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_dup_flag,
{
"Duplicates Report Flag",
"rtcp.xr.stats.dupflag",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_jitter_flag,
{
"Jitter Report Flag",
"rtcp.xr.stats.jitterflag",
FT_BOOLEAN,
8,
NULL,
0x20,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_ttl,
{
"TTL or Hop Limit Flag",
"rtcp.xr.stats.ttl",
FT_UINT8,
BASE_DEC,
VALS(rtcp_xr_ip_ttl_vals),
0x18,
NULL, HFILL
}
},
{
&hf_rtcp_xr_endseq,
{
"End Sequence Number",
"rtcp.xr.endseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_beginseq,
{
"Begin Sequence Number",
"rtcp.xr.beginseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_lost,
{
"Lost Packets",
"rtcp.xr.stats.lost",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_dups,
{
"Duplicate Packets",
"rtcp.xr.stats.dups",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_minjitter,
{
"Minimum Jitter",
"rtcp.xr.stats.minjitter",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_maxjitter,
{
"Maximum Jitter",
"rtcp.xr.stats.maxjitter",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_meanjitter,
{
"Mean Jitter",
"rtcp.xr.stats.meanjitter",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_devjitter,
{
"Standard Deviation of Jitter",
"rtcp.xr.stats.devjitter",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_minttl,
{
"Minimum TTL or Hop Limit",
"rtcp.xr.stats.minttl",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_maxttl,
{
"Maximum TTL or Hop Limit",
"rtcp.xr.stats.maxttl",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_meanttl,
{
"Mean TTL or Hop Limit",
"rtcp.xr.stats.meanttl",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_stats_devttl,
{
"Standard Deviation of TTL",
"rtcp.xr.stats.devttl",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_lrr,
{
"Last RR timestamp",
"rtcp.xr.lrr",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_dlrr,
{
"Delay since last RR timestamp",
"rtcp.xr.dlrr",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_length_check,
{
"RTCP frame length check",
"rtcp.length_check",
FT_BOOLEAN,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_bye_reason_not_padded,
{
"BYE reason string not NULL padded",
"rtcp.bye_reason_not_padded",
FT_NONE,
BASE_NONE,
NULL,
0x0,
"RTCP BYE reason string not padded", HFILL
}
},
{
&hf_rtcp_rtpfb_fmt,
{
"RTCP Feedback message type (FMT)",
"rtcp.rtpfb.fmt",
FT_UINT8,
BASE_DEC,
VALS(rtcp_rtpfb_fmt_vals),
0x1f,
NULL, HFILL
}
},
{
&hf_rtcp_psfb_fmt,
{
"RTCP Feedback message type (FMT)",
"rtcp.psfb.fmt",
FT_UINT8,
BASE_DEC,
VALS(rtcp_psfb_fmt_vals),
0x1f,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_nack_pid,
{
"RTCP Transport Feedback NACK",
"rtcp.rtpfb.nack",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_nack_blp,
{
"RTCP Transport Feedback NACK BLP",
"rtcp.rtpfb.nack.blp",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_fci,
{
"Feedback Control Information (FCI)",
"rtcp.fci",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_spst,
{
"Syncronization Packet Sender Type",
"rtcp.xr.idms.spst",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_pt,
{
"Payload Type",
"rtcp.xr.idms.pt",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_msci,
{
"Media Stream Correlation Identifier",
"rtcp.xr.idms.msci",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_source_ssrc,
{
"Source SSRC",
"rtcp.xr.idms.source_ssrc",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_ntp_rcv_ts_msw,
{
"NTP Timestamp of packet reception (msw)",
"rtcp.xr.idms.ntp_rcv_ts_msw",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_ntp_rcv_ts_lsw,
{
"NTP Timestamp of packet reception (lsw)",
"rtcp.xr.idms.ntp_rcv_ts_lsw",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_rtp_ts,
{
"RTP Timestamp of packet",
"rtcp.xr.idms.rtp_ts",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_idms_ntp_pres_ts,
{
"NTP Timestamp of presentation",
"rtcp.xr.idms.ntp_pres_ts",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_psfb_fir_fci_ssrc,
{
"SSRC",
"rtcp.psfb.fir.fci.ssrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_psfb_fir_fci_csn,
{
"Command Sequence Number",
"rtcp.psfb.fir.fci.csn",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_psfb_fir_fci_reserved,
{
"Reserved",
"rtcp.psfb.fir.fci.reserved",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_tmbbr_fci_ssrc,
{
"SSRC",
"rtcp.rtpfb.tmmbr.fci.ssrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_tmbbr_fci_exp,
{
"MxTBR Exp",
"rtcp.rtpfb.tmmbr.fci.exp",
FT_UINT8,
BASE_DEC,
NULL,
0xfc,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_tmbbr_fci_mantissa,
{
"MxTBR Mantissa",
"rtcp.rtpfb.tmmbr.fci.mantissa",
FT_UINT32,
BASE_DEC,
NULL,
0x3fffe,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_tmbbr_fci_bitrate,
{
"Maximum total media bit rate",
"rtcp.rtpfb.tmmbr.fci.bitrate",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_rtpfb_tmbbr_fci_measuredoverhead,
{
"Measured Overhead",
"rtcp.rtpfb.tmmbr.fci.measuredoverhead",
FT_UINT16,
BASE_DEC,
NULL,
0x1ff,
NULL, HFILL
}
},
{
&hf_srtcp_e,
{
"SRTCP E flag",
"srtcp.e",
FT_BOOLEAN,
32,
NULL,
0x80000000,
"SRTCP Encryption Flag", HFILL
}
},
{
&hf_srtcp_index,
{
"SRTCP Index",
"srtcp.index",
FT_UINT32,
BASE_DEC_HEX,
NULL,
0x7fffffff,
NULL, HFILL
}
},
{
&hf_srtcp_mki,
{
"SRTCP MKI",
"srtcp.mki",
FT_BYTES,
BASE_NONE,
NULL,
0,
"SRTCP Master Key Index", HFILL
}
},
{
&hf_srtcp_auth_tag,
{
"SRTCP Auth Tag",
"srtcp.auth_tag",
FT_BYTES,
BASE_NONE,
NULL,
0,
"SRTCP Authentication Tag", HFILL
}
},
{
&hf_rtcp_xr_btxnq_begseq,
{
"Starting sequence number",
"rtcp.xr.btxnq.begseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_endseq,
{
"Last sequence number",
"rtcp.xr.btxnq.endseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_vmaxdiff,
{
"Maximum IPDV difference in 1 cycle",
"rtcp.xr.btxnq.vmaxdiff",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_vrange,
{
"Maximum IPDV difference seen to date",
"rtcp.xr.btxnq.vrange",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_vsum,
{
"Sum of peak IPDV differences to date",
"rtcp.xr.btxnq.vsum",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_cycles,
{
"Number of cycles in calculation",
"rtcp.xr.btxnq.cycles",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_jbevents,
{
"Number of jitter buffer adaptations to date",
"rtcp.xr.btxnq.jbevents",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_spare,
{
"Spare/reserved bits",
"rtcp.xr.btxnq.spare",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_tdegnet,
{
"Time degraded by packet loss or late delivery",
"rtcp.xr.btxnq.tdegnet",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_tdegjit,
{
"Time degraded by jitter buffer adaptation events",
"rtcp.xr.btxnq.tdegjit",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_es,
{
"ES due to unavailable packet events",
"rtcp.xr.btxnq.es",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtcp_xr_btxnq_ses,
{
"SES due to unavailable packet events",
"rtcp.xr.btxnq.ses",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_rtcp,
&ett_rtcp_sr,
&ett_rtcp_rr,
&ett_rtcp_sdes,
&ett_rtcp_bye,
&ett_rtcp_app,
&ett_rtcp_rtpfb,
&ett_rtcp_psfb,
&ett_rtcp_xr,
&ett_rtcp_fir,
&ett_rtcp_nack,
&ett_ssrc,
&ett_ssrc_item,
&ett_ssrc_ext_high,
&ett_sdes,
&ett_sdes_item,
&ett_PoC1,
&ett_mux,
&ett_rtcp_setup,
&ett_rtcp_roundtrip_delay,
&ett_xr_block,
&ett_xr_block_contents,
&ett_xr_ssrc,
&ett_xr_loss_chunk,
&ett_poc1_conn_contents,
&ett_rtcp_nack_blp,
};
module_t *rtcp_module;
proto_rtcp = proto_register_protocol("Real-time Transport Control Protocol",
"RTCP", "rtcp");
proto_register_field_array(proto_rtcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rtcp", dissect_rtcp, proto_rtcp);
rtcp_module = prefs_register_protocol(proto_rtcp, NULL);
prefs_register_bool_preference(rtcp_module, "show_setup_info",
"Show stream setup information",
"Where available, show which protocol and frame caused "
"this RTCP stream to be created",
&global_rtcp_show_setup_info);
prefs_register_bool_preference(rtcp_module, "heuristic_rtcp",
"Try to decode RTCP outside of conversations",
"If call control SIP/H.323/RTSP/.. messages are missing in the trace, "
"RTCP isn't decoded without this",
&global_rtcp_heur);
prefs_register_bool_preference(rtcp_module, "show_roundtrip_calculation",
"Show relative roundtrip calculations",
"Try to work out network delay by comparing time between packets "
"as captured and delays as seen by endpoint",
&global_rtcp_show_roundtrip_calculation);
prefs_register_uint_preference(rtcp_module, "roundtrip_min_threshhold",
"Minimum roundtrip calculation to report (ms)",
"Minimum (absolute) calculated roundtrip delay time in milliseconds that "
"should be reported",
10, &global_rtcp_show_roundtrip_calculation_minimum);
rtcp_dissector_table = register_dissector_table("rtcp.app.name", "RTCP Application Name", FT_STRING, BASE_NONE);
}
void
proto_reg_handoff_rtcp(void)
{
rtcp_handle = find_dissector("rtcp");
dissector_add_handle("udp.port", rtcp_handle);
heur_dissector_add( "udp", dissect_rtcp_heur, proto_rtcp);
heur_dissector_add("stun", dissect_rtcp_heur, proto_rtcp);
}
