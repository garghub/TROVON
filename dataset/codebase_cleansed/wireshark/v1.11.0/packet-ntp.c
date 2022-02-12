const char *
tvb_mip6_fmt_ts(tvbuff_t *tvb, gint offset)
{
guint64 tempstmp;
guint32 tempfrac;
time_t temptime;
struct tm *bd;
double fractime;
char *buff;
tempstmp = tvb_get_ntoh48(tvb, offset);
tempfrac = tvb_get_ntohs(tvb, offset+6);
tempfrac <<= 16;
if ((tempstmp == 0) && (tempfrac == 0)) {
return "NULL";
}
temptime = (time_t)(tempstmp );
bd = gmtime(&temptime);
if(!bd){
return "Not representable";
}
fractime = bd->tm_sec + tempfrac / NTP_FLOAT_DENOM;
buff=(char *)wmem_alloc(wmem_packet_scope(), NTP_TS_SIZE);
g_snprintf(buff, NTP_TS_SIZE,
"%s %2d, %d %02d:%02d:%07.4f UTC",
mon_names[bd->tm_mon],
bd->tm_mday,
bd->tm_year + 1900,
bd->tm_hour,
bd->tm_min,
fractime);
return buff;
}
const char *
tvb_ntp_fmt_ts(tvbuff_t *tvb, gint offset)
{
guint32 tempstmp, tempfrac;
time_t temptime;
struct tm *bd;
double fractime;
char *buff;
tempstmp = tvb_get_ntohl(tvb, offset);
tempfrac = tvb_get_ntohl(tvb, offset+4);
if ((tempstmp == 0) && (tempfrac == 0)) {
return "NULL";
}
temptime = tempstmp - (guint32) NTP_BASETIME;
bd = gmtime(&temptime);
if(!bd){
return "Not representable";
}
fractime = bd->tm_sec + tempfrac / NTP_FLOAT_DENOM;
buff=(char *)wmem_alloc(wmem_packet_scope(), NTP_TS_SIZE);
g_snprintf(buff, NTP_TS_SIZE,
"%s %2d, %d %02d:%02d:%09.6f UTC",
mon_names[bd->tm_mon],
bd->tm_mday,
bd->tm_year + 1900,
bd->tm_hour,
bd->tm_min,
fractime);
return buff;
}
void
ntp_to_nstime(tvbuff_t *tvb, gint offset, nstime_t *nstime)
{
guint32 tempstmp;
tempstmp = tvb_get_ntohl(tvb, offset);
if (tempstmp)
nstime->secs = tempstmp - (guint32)NTP_BASETIME;
else
nstime->secs = tempstmp;
nstime->nsecs = (int)(tvb_get_ntohl(tvb, offset+4)/(NTP_FLOAT_DENOM/1000000000.0));
}
static void
dissect_ntp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ntp_tree;
proto_item *ti = NULL;
guint8 flags;
void (*dissector)(tvbuff_t *, proto_item *, guint8);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NTP");
col_clear(pinfo->cinfo, COL_INFO);
flags = tvb_get_guint8(tvb, 0);
switch (flags & NTP_MODE_MASK) {
default:
dissector = dissect_ntp_std;
break;
case NTP_MODE_CTRL:
dissector = dissect_ntp_ctrl;
break;
case NTP_MODE_PRIV:
dissector = dissect_ntp_priv;
break;
}
ti = proto_tree_add_item(tree, proto_ntp, tvb, 0, -1, ENC_NA);
ntp_tree = proto_item_add_subtree(ti, ett_ntp);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, %s",
val_to_str_const((flags & NTP_VN_MASK) >> 3, ver_nums,
"Unknown version"),
val_to_str_const(flags & NTP_MODE_MASK, info_mode_types, "Unknown"));
proto_item_append_text(ti, " (%s, %s)",
val_to_str_const((flags & NTP_VN_MASK) >> 3, ver_nums,
"Unknown version"),
val_to_str_const(flags & NTP_MODE_MASK, info_mode_types, "Unknown"));
(*dissector)(tvb, ntp_tree, flags);
}
static void
dissect_ntp_std(tvbuff_t *tvb, proto_tree *ntp_tree, guint8 flags)
{
proto_tree *flags_tree;
proto_item *tf;
guint8 stratum;
guint8 ppoll;
gint8 precision;
double rootdelay;
double rootdispersion;
guint32 refid_addr;
const gchar *buffc;
gchar *buff;
int i;
int macofs;
gint maclen;
tf = proto_tree_add_uint(ntp_tree, hf_ntp_flags, tvb, 0, 1, flags);
flags_tree = proto_item_add_subtree(tf, ett_ntp_flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_li, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_vn, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_mode, tvb, 0, 1, flags);
stratum = tvb_get_guint8(tvb, 1);
if (stratum == 0) {
buffc="unspecified or invalid (%u)";
} else if (stratum == 1) {
buffc="primary reference (%u)";
} else if ((stratum >= 2) && (stratum <= 15)) {
buffc="secondary reference (%u)";
} else if (stratum == 16) {
buffc="unsynchronized (%u)";
} else {
buffc="reserved: %u";
}
proto_tree_add_uint_format_value(ntp_tree, hf_ntp_stratum, tvb, 1, 1,
stratum, buffc, stratum);
ppoll = tvb_get_guint8(tvb, 2);
if ((ppoll >= 4) && (ppoll <= 17)) {
proto_tree_add_uint_format_value(ntp_tree, hf_ntp_ppoll, tvb, 2, 1,
ppoll,
"%u (%u sec)",
ppoll,
1 << ppoll);
} else {
proto_tree_add_uint_format_value(ntp_tree, hf_ntp_ppoll, tvb, 2, 1,
ppoll,
"invalid (%u)",
ppoll);
}
precision = tvb_get_guint8(tvb, 3);
proto_tree_add_int_format_value(ntp_tree, hf_ntp_precision, tvb, 3, 1,
precision,
"%8.6f sec",
pow(2, precision));
rootdelay = ((gint16)tvb_get_ntohs(tvb, 4)) +
(tvb_get_ntohs(tvb, 6) / 65536.0);
proto_tree_add_double_format_value(ntp_tree, hf_ntp_rootdelay, tvb, 4, 4,
rootdelay,
"%9.4f sec",
rootdelay);
rootdispersion = ((gint16)tvb_get_ntohs(tvb, 8)) +
(tvb_get_ntohs(tvb, 10) / 65536.0);
proto_tree_add_double_format_value(ntp_tree, hf_ntp_rootdispersion, tvb, 8, 4,
rootdispersion,
"%9.4f sec",
rootdispersion);
buff = (gchar *)wmem_alloc(wmem_packet_scope(), NTP_TS_SIZE);
if (stratum <= 1) {
g_snprintf (buff, NTP_TS_SIZE, "Unidentified reference source '%.4s'",
tvb_get_string(wmem_packet_scope(), tvb, 12, 4));
for (i = 0; primary_sources[i].id; i++) {
if (tvb_memeql(tvb, 12, primary_sources[i].id, 4) == 0) {
g_snprintf(buff, NTP_TS_SIZE, "%s",
primary_sources[i].data);
break;
}
}
} else {
int buffpos;
refid_addr = tvb_get_ipv4(tvb, 12);
buffpos = g_snprintf(buff, NTP_TS_SIZE, "%s", get_hostname (refid_addr));
if (buffpos >= NTP_TS_SIZE) {
buff[NTP_TS_SIZE-4]='.';
buff[NTP_TS_SIZE-3]='.';
buff[NTP_TS_SIZE-2]='.';
buff[NTP_TS_SIZE-1]=0;
}
}
proto_tree_add_bytes_format_value(ntp_tree, hf_ntp_refid, tvb, 12, 4,
NULL, "%s", buff);
proto_tree_add_item(ntp_tree, hf_ntp_reftime, tvb, 16, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
proto_tree_add_item(ntp_tree, hf_ntp_org, tvb, 24, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
proto_tree_add_item(ntp_tree, hf_ntp_rec, tvb, 32, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
proto_tree_add_item(ntp_tree, hf_ntp_xmt, tvb, 40, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
macofs = 48;
while (tvb_reported_length_remaining(tvb, macofs) > (gint)MAX_MAC_LEN)
macofs = dissect_ntp_ext(tvb, ntp_tree, macofs);
if (tvb_reported_length_remaining(tvb, macofs) >= 4)
proto_tree_add_item(ntp_tree, hf_ntp_keyid, tvb, macofs, 4,
ENC_NA);
macofs += 4;
maclen = tvb_reported_length_remaining(tvb, macofs);
if (maclen > 0)
proto_tree_add_item(ntp_tree, hf_ntp_mac, tvb, macofs,
maclen, ENC_NA);
}
static int
dissect_ntp_ext(tvbuff_t *tvb, proto_tree *ntp_tree, int offset)
{
proto_tree *ext_tree, *flags_tree;
proto_item *tf;
guint16 extlen;
int endoffset;
guint8 flags;
guint32 vallen, vallen_round, siglen;
extlen = tvb_get_ntohs(tvb, offset+2);
if (extlen < 8) {
proto_tree_add_text(ntp_tree, tvb, offset+2, 2,
"Extension length %u < 8", extlen);
offset += tvb_length_remaining(tvb, offset);
return offset;
}
if (extlen % 4) {
proto_tree_add_text(ntp_tree, tvb, offset+2, 2,
"Extension length %u isn't a multiple of 4",
extlen);
offset += tvb_length_remaining(tvb, offset);
return offset;
}
endoffset = offset + extlen;
tf = proto_tree_add_item(ntp_tree, hf_ntp_ext, tvb, offset, extlen,
ENC_NA);
ext_tree = proto_item_add_subtree(tf, ett_ntp_ext);
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(ext_tree, hf_ntp_ext_flags, tvb, offset, 1,
flags);
flags_tree = proto_item_add_subtree(tf, ett_ntp_ext_flags);
proto_tree_add_uint(flags_tree, hf_ntp_ext_flags_r, tvb, offset, 1,
flags);
proto_tree_add_uint(flags_tree, hf_ntp_ext_flags_error, tvb, offset, 1,
flags);
proto_tree_add_uint(flags_tree, hf_ntp_ext_flags_vn, tvb, offset, 1,
flags);
offset++;
proto_tree_add_item(ext_tree, hf_ntp_ext_op, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_uint(ext_tree, hf_ntp_ext_len, tvb, offset, 2, extlen);
offset += 2;
if ((flags & NTP_EXT_VN_MASK) != 2) {
return endoffset;
}
proto_tree_add_item(ext_tree, hf_ntp_ext_associd, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
if (extlen < MAX_MAC_LEN) {
return endoffset;
}
proto_tree_add_item(ext_tree, hf_ntp_ext_tstamp, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ext_tree, hf_ntp_ext_fstamp, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
vallen = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(ext_tree, hf_ntp_ext_vallen, tvb, offset, 4,
vallen);
offset += 4;
vallen_round = (vallen + 3) & (-4);
if (vallen != 0) {
if ((guint32)(endoffset - offset) < vallen_round) {
proto_tree_add_text(ext_tree, tvb, offset,
endoffset - offset,
"Value length makes value go past the end of the extension field");
return endoffset;
}
proto_tree_add_item(ext_tree, hf_ntp_ext_val, tvb, offset,
vallen, ENC_NA);
}
offset += vallen_round;
siglen = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(ext_tree, hf_ntp_ext_siglen, tvb, offset, 4,
siglen);
offset += 4;
if (siglen != 0) {
if (offset + (int)siglen > endoffset) {
proto_tree_add_text(ext_tree, tvb, offset,
endoffset - offset,
"Signature length makes value go past the end of the extension field");
return endoffset;
}
proto_tree_add_item(ext_tree, hf_ntp_ext_sig, tvb,
offset, siglen, ENC_NA);
}
return endoffset;
}
static void
dissect_ntp_ctrl_peerstatus(tvbuff_t *tvb, proto_tree *status_tree, guint16 offset, guint16 status)
{
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_b0, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_b1, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_b2, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_b3, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_b4, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_selection, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_count, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_peer_status_code, tvb, offset, 2, status);
}
static void
dissect_ntp_ctrl_systemstatus(tvbuff_t *tvb, proto_tree *status_tree, guint16 offset, guint16 status)
{
proto_tree_add_uint(status_tree, hf_ntpctrl_sys_status_li, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_sys_status_clksrc, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_sys_status_count, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_sys_status_code, tvb, offset, 2, status);
}
static void
dissect_ntp_ctrl_errorstatus(tvbuff_t *tvb, proto_tree *status_tree, guint16 offset, guint16 status)
{
proto_tree_add_uint(status_tree, hf_ntpctrl_error_status_word, tvb, offset, 2, status);
}
static void
dissect_ntp_ctrl_clockstatus(tvbuff_t *tvb, proto_tree *status_tree, guint16 offset, guint16 status)
{
proto_tree_add_uint(status_tree, hf_ntpctrl_clk_status, tvb, offset, 2, status);
proto_tree_add_uint(status_tree, hf_ntpctrl_clk_status_code, tvb, offset, 2, status);
}
static void
dissect_ntp_ctrl(tvbuff_t *tvb, proto_tree *ntp_tree, guint8 flags)
{
proto_tree *flags_tree;
proto_item *tf;
guint8 flags2;
proto_tree *status_tree, *data_tree, *item_tree;
proto_item *ts, *td, *ti;
guint16 status;
guint16 associd;
guint16 datalen;
guint16 data_offset;
tvbparse_t *tt;
tvbparse_elem_t *element;
tf = proto_tree_add_uint(ntp_tree, hf_ntp_flags, tvb, 0, 1, flags);
flags_tree = proto_item_add_subtree(tf, ett_ntp_flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_li, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_vn, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_mode, tvb, 0, 1, flags);
flags2 = tvb_get_guint8(tvb, 1);
tf = proto_tree_add_uint(ntp_tree, hf_ntpctrl_flags2, tvb, 1, 1, flags2);
flags_tree = proto_item_add_subtree(tf, ett_ntpctrl_flags2);
proto_tree_add_uint(flags_tree, hf_ntpctrl_flags2_r, tvb, 1, 1, flags2);
proto_tree_add_uint(flags_tree, hf_ntpctrl_flags2_error, tvb, 1, 1, flags2);
proto_tree_add_uint(flags_tree, hf_ntpctrl_flags2_more, tvb, 1, 1, flags2);
proto_tree_add_uint(flags_tree, hf_ntpctrl_flags2_opcode, tvb, 1, 1, flags2);
proto_tree_add_uint(ntp_tree, hf_ntpctrl_sequence, tvb, 2, 2, tvb_get_ntohs(tvb, 2));
status = tvb_get_ntohs(tvb, 4);
associd = tvb_get_ntohs(tvb, 6);
ts = proto_tree_add_uint(ntp_tree, hf_ntpctrl_status, tvb, 4, 2, status);
status_tree = proto_item_add_subtree(ts, ett_ntpctrl_status);
if (flags2 & NTPCTRL_R_MASK) {
if (flags2 & NTPCTRL_ERROR_MASK) {
dissect_ntp_ctrl_errorstatus(tvb, status_tree, 4, status);
} else {
switch (flags2 & NTPCTRL_OP_MASK) {
case NTPCTRL_OP_READSTAT:
case NTPCTRL_OP_READVAR:
case NTPCTRL_OP_WRITEVAR:
case NTPCTRL_OP_ASYNCMSG:
if (associd)
dissect_ntp_ctrl_peerstatus(tvb, status_tree, 4, status);
else
dissect_ntp_ctrl_systemstatus(tvb, status_tree, 4, status);
break;
case NTPCTRL_OP_READCLOCK:
case NTPCTRL_OP_WRITECLOCK:
dissect_ntp_ctrl_clockstatus(tvb, status_tree, 4, status);
break;
case NTPCTRL_OP_SETTRAP:
case NTPCTRL_OP_UNSETTRAP:
break;
}
}
}
proto_tree_add_uint(ntp_tree, hf_ntpctrl_associd, tvb, 6, 2, associd);
proto_tree_add_uint(ntp_tree, hf_ntpctrl_offset, tvb, 8, 2, tvb_get_ntohs(tvb, 8));
datalen = tvb_get_ntohs(tvb, 10);
proto_tree_add_uint(ntp_tree, hf_ntpctrl_count, tvb, 10, 2, datalen);
if (datalen) {
data_offset = 12;
td = proto_tree_add_item(ntp_tree, hf_ntpctrl_data, tvb, data_offset, datalen, ENC_NA);
data_tree = proto_item_add_subtree(td, ett_ntpctrl_data);
switch(flags2 & NTPCTRL_OP_MASK) {
case NTPCTRL_OP_READSTAT:
if (!associd) {
while(datalen) {
ti = proto_tree_add_item(data_tree, hf_ntpctrl_item, tvb, data_offset, 4, ENC_NA);
item_tree = proto_item_add_subtree(ti, ett_ntpctrl_item);
proto_tree_add_uint(item_tree, hf_ntpctrl_associd, tvb, data_offset, 2, tvb_get_ntohs(tvb, data_offset));
data_offset += 2;
status = tvb_get_ntohs(tvb, data_offset);
ts = proto_tree_add_uint(item_tree, hf_ntpctrl_status, tvb, data_offset, 2, status);
status_tree = proto_item_add_subtree(ts, ett_ntpctrl_status);
dissect_ntp_ctrl_peerstatus( tvb, status_tree, 4, status );
data_offset += 2;
datalen -= 4;
}
break;
}
case NTPCTRL_OP_READVAR:
case NTPCTRL_OP_WRITEVAR:
case NTPCTRL_OP_READCLOCK:
case NTPCTRL_OP_WRITECLOCK:
tt = tvbparse_init(tvb, data_offset, datalen, NULL, want_ignore);
while( (element = tvbparse_get(tt, want)) != NULL ) {
tvbparse_tree_add_elem(data_tree, element);
}
break;
case NTPCTRL_OP_ASYNCMSG:
proto_tree_add_item(data_tree, hf_ntpctrl_trapmsg, tvb, data_offset, datalen, ENC_ASCII|ENC_NA);
break;
}
}
}
static void
init_parser(void)
{
tvbparse_wanted_t* want_identifier = tvbparse_chars(-1, 1, 0,
"abcdefghijklmnopqrstuvwxyz-_ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789", NULL, NULL, NULL);
tvbparse_wanted_t* want_equalsign = tvbparse_chars(-1, 1, 0, "=", NULL, NULL, NULL);
tvbparse_wanted_t* want_value = tvbparse_set_oneof(0, NULL, NULL, NULL,
tvbparse_quoted(-1, NULL, NULL, tvbparse_shrink_token_cb, '\"', '\\'),
tvbparse_quoted(-1, NULL, NULL, tvbparse_shrink_token_cb, '\'', '\\'),
tvbparse_chars(-1, 1, 0, "abcdefghijklmnopqrstuvwxyz-_ABCDEFGHIJKLMNOPQRSTUVWXYZ.0123456789 ", NULL, NULL, NULL),
NULL);
tvbparse_wanted_t* want_assignment = tvbparse_set_seq(-1, NULL, NULL, NULL,
want_identifier,
want_equalsign,
want_value,
NULL);
want_ignore = tvbparse_chars(-1, 1, 0, ", \t\r\n", NULL, NULL, NULL);
want = tvbparse_set_oneof(-1, NULL, NULL, NULL,
want_assignment,
want_identifier,
NULL);
}
static void
dissect_ntp_priv(tvbuff_t *tvb, proto_tree *ntp_tree, guint8 flags)
{
proto_tree *flags_tree;
proto_item *tf;
guint8 auth_seq, impl, reqcode;
tf = proto_tree_add_uint(ntp_tree, hf_ntp_flags, tvb, 0, 1, flags);
flags_tree = proto_item_add_subtree(tf, ett_ntp_flags);
proto_tree_add_uint(flags_tree, hf_ntppriv_flags_r, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntppriv_flags_more, tvb, 0, 1,
flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_vn, tvb, 0, 1, flags);
proto_tree_add_uint(flags_tree, hf_ntp_flags_mode, tvb, 0, 1, flags);
auth_seq = tvb_get_guint8(tvb, 1);
tf = proto_tree_add_uint(ntp_tree, hf_ntppriv_auth_seq, tvb, 1, 1,
auth_seq);
flags_tree = proto_item_add_subtree(tf, ett_ntppriv_auth_seq);
proto_tree_add_uint(flags_tree, hf_ntppriv_auth, tvb, 1, 1, auth_seq);
proto_tree_add_uint(flags_tree, hf_ntppriv_seq, tvb, 1, 1, auth_seq);
impl = tvb_get_guint8(tvb, 2);
proto_tree_add_uint(ntp_tree, hf_ntppriv_impl, tvb, 2, 1, impl);
reqcode = tvb_get_guint8(tvb, 3);
proto_tree_add_uint(ntp_tree, hf_ntppriv_reqcode, tvb, 3, 1, reqcode);
}
void
proto_register_ntp(void)
{
static hf_register_info hf[] = {
{ &hf_ntp_flags, {
"Flags", "ntp.flags", FT_UINT8, BASE_HEX,
NULL, 0, "Flags (Leap/Version/Mode)", HFILL }},
{ &hf_ntp_flags_li, {
"Leap Indicator", "ntp.flags.li", FT_UINT8, BASE_DEC,
VALS(li_types), NTP_LI_MASK, "Warning of an impending leap second to be inserted or deleted in the last minute of the current month", HFILL }},
{ &hf_ntp_flags_vn, {
"Version number", "ntp.flags.vn", FT_UINT8, BASE_DEC,
VALS(ver_nums), NTP_VN_MASK, NULL, HFILL }},
{ &hf_ntp_flags_mode, {
"Mode", "ntp.flags.mode", FT_UINT8, BASE_DEC,
VALS(mode_types), NTP_MODE_MASK, NULL, HFILL }},
{ &hf_ntp_stratum, {
"Peer Clock Stratum", "ntp.stratum", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ppoll, {
"Peer Polling Interval", "ntp.ppoll", FT_UINT8, BASE_DEC,
NULL, 0, "Maximum interval between successive messages", HFILL }},
{ &hf_ntp_precision, {
"Peer Clock Precision", "ntp.precision", FT_INT8, BASE_DEC,
NULL, 0, "The precision of the system clock", HFILL }},
{ &hf_ntp_rootdelay, {
"Root Delay", "ntp.rootdelay", FT_DOUBLE, BASE_NONE,
NULL, 0, "Total round-trip delay to the reference clock", HFILL }},
{ &hf_ntp_rootdispersion, {
"Root Dispersion", "ntp.rootdispersion", FT_DOUBLE, BASE_NONE,
NULL, 0, "Total dispersion to the reference clock", HFILL }},
{ &hf_ntp_refid, {
"Reference ID", "ntp.refid", FT_BYTES, BASE_NONE,
NULL, 0, "Particular server or reference clock being used", HFILL }},
{ &hf_ntp_reftime, {
"Reference Timestamp", "ntp.reftime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0, "Time when the system clock was last set or corrected", HFILL }},
{ &hf_ntp_org, {
"Origin Timestamp", "ntp.org", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0, "Time at the client when the request departed for the server", HFILL }},
{ &hf_ntp_rec, {
"Receive Timestamp", "ntp.rec", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0, "Time at the server when the request arrived from the client", HFILL }},
{ &hf_ntp_xmt, {
"Transmit Timestamp", "ntp.xmt", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0, "Time at the server when the response left for the client", HFILL }},
{ &hf_ntp_keyid, {
"Key ID", "ntp.keyid", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_mac, {
"Message Authentication Code", "ntp.mac", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext, {
"Extension", "ntp.ext", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_flags, {
"Flags", "ntp.ext.flags", FT_UINT8, BASE_HEX,
NULL, 0, "Flags (Response/Error/Version)", HFILL }},
{ &hf_ntp_ext_flags_r, {
"Response bit", "ntp.ext.flags.r", FT_UINT8, BASE_DEC,
VALS(ext_r_types), NTP_EXT_R_MASK, NULL, HFILL }},
{ &hf_ntp_ext_flags_error, {
"Error bit", "ntp.ext.flags.error", FT_UINT8, BASE_DEC,
NULL, NTP_EXT_ERROR_MASK, NULL, HFILL }},
{ &hf_ntp_ext_flags_vn, {
"Version", "ntp.ext.flags.vn", FT_UINT8, BASE_DEC,
NULL, NTP_EXT_VN_MASK, NULL, HFILL }},
{ &hf_ntp_ext_op, {
"Opcode", "ntp.ext.op", FT_UINT8, BASE_DEC,
VALS(ext_op_types), 0, NULL, HFILL }},
{ &hf_ntp_ext_len, {
"Extension length", "ntp.ext.len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_associd, {
"Association ID", "ntp.ext.associd", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_tstamp, {
"Timestamp", "ntp.ext.tstamp", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_fstamp, {
"File Timestamp", "ntp.ext.fstamp", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_vallen, {
"Value length", "ntp.ext.vallen", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_val, {
"Value", "ntp.ext.val", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_siglen, {
"Signature length", "ntp.ext.siglen", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntp_ext_sig, {
"Signature", "ntp.ext.sig", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_flags2, {
"Flags 2", "ntp.ctrl.flags2", FT_UINT8, BASE_HEX,
NULL, 0, "Flags (Response/Error/More/Opcode)", HFILL }},
{ &hf_ntpctrl_flags2_r, {
"Response bit", "ntp.ctrl.flags2.r", FT_UINT8, BASE_DEC,
VALS(ctrl_r_types), NTPCTRL_R_MASK, NULL, HFILL }},
{ &hf_ntpctrl_flags2_error, {
"Error bit", "ntp.ctrl.flags2.error", FT_UINT8, BASE_DEC,
NULL, NTPCTRL_ERROR_MASK, NULL, HFILL }},
{ &hf_ntpctrl_flags2_more, {
"More bit", "ntp.ctrl.flags2.more", FT_UINT8, BASE_DEC,
NULL, NTPCTRL_MORE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_flags2_opcode, {
"Opcode", "ntp.ctrl.flags2.opcode", FT_UINT8, BASE_DEC,
VALS(ctrl_op_types), NTPCTRL_OP_MASK, NULL, HFILL }},
{ &hf_ntpctrl_sequence, {
"Sequence", "ntp.ctrl.sequence", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_status, {
"Status", "ntp.ctrl.status", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_error_status_word, {
"Error Status Word", "ntp.ctrl.err_status", FT_UINT16, BASE_DEC,
VALS(ctrl_err_status_types), NTP_CTRL_ERRSTATUS_CODE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_sys_status_li, {
"Leap Indicator", "ntp.ctrl.sys_status.li", FT_UINT16, BASE_DEC,
VALS(li_types), NTPCTRL_SYSSTATUS_LI_MASK, "Warning of an impending leap second to be inserted or deleted in the last minute of the current month", HFILL }},
{ &hf_ntpctrl_sys_status_clksrc, {
"Clock Source", "ntp.ctrl.sys_status.clksrc", FT_UINT16, BASE_DEC,
VALS(ctrl_sys_status_clksource_types), NTPCTRL_SYSSTATUS_CLK_MASK, NULL, HFILL }},
{ &hf_ntpctrl_sys_status_count, {
"System Event Counter", "ntp.ctrl.sys_status.count", FT_UINT16, BASE_DEC,
NULL, NTPCTRL_SYSSTATUS_COUNT_MASK, NULL, HFILL }},
{ &hf_ntpctrl_sys_status_code, {
"System Event Code", "ntp.ctrl.sys_status.code", FT_UINT16, BASE_DEC,
VALS(ctrl_sys_status_event_types), NTPCTRL_SYSSTATUS_CODE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_b0, {
"Peer Status", "ntp.ctrl.peer_status.config", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_config_types), NTPCTRL_PEERSTATUS_CONFIG_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_b1, {
"Peer Status", "ntp.ctrl.peer_status.authenable", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_authenable_types), NTPCTRL_PEERSTATUS_AUTHENABLE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_b2, {
"Peer Status", "ntp.ctrl.peer_status.authentic", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_authentic_types), NTPCTRL_PEERSTATUS_AUTHENTIC_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_b3, {
"Peer Status", "ntp.ctrl.peer_status.reach", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_reach_types), NTPCTRL_PEERSTATUS_REACH_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_b4, {
"Peer Status: reserved", "ntp.ctrl.peer_status.reserved", FT_UINT16, BASE_DEC,
NULL, NTPCTRL_PEERSTATUS_RESERVED_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_selection, {
"Peer Selection", "ntp.ctrl.peer_status.selection", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_selection_types), NTPCTRL_PEERSTATUS_SEL_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_count, {
"Peer Event Counter", "ntp.ctrl.peer_status.count", FT_UINT16, BASE_DEC,
NULL, NTPCTRL_PEERSTATUS_COUNT_MASK, NULL, HFILL }},
{ &hf_ntpctrl_peer_status_code, {
"Peer Event Code", "ntp.ctrl.peer_status.code", FT_UINT16, BASE_DEC,
VALS(ctrl_peer_status_event_types), NTPCTRL_PEERSTATUS_CODE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_clk_status, {
"Clock Status", "ntp.ctrl.clock_status.status", FT_UINT16, BASE_DEC,
VALS(ctrl_clk_status_types), NTPCTRL_CLKSTATUS_STATUS_MASK, NULL, HFILL }},
{ &hf_ntpctrl_clk_status_code, {
"Clock Event Code", "ntp.ctrl.clock_status.code", FT_UINT16, BASE_DEC,
NULL, NTPCTRL_CLKSTATUS_CODE_MASK, NULL, HFILL }},
{ &hf_ntpctrl_data, {
"Data", "ntp.ctrl.data", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_item, {
"Item", "ntp.ctrl.item", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_associd, {
"AssociationID", "ntp.ctrl.associd", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_offset, {
"Offset", "ntp.ctrl.offset", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_count, {
"Count", "ntp.ctrl.count", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_ntpctrl_trapmsg, {
"Trap message", "ntp.ctrl.trapmsg", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_ntppriv_flags_r, {
"Response bit", "ntp.priv.flags.r", FT_UINT8, BASE_DEC,
VALS(priv_r_types), NTPPRIV_R_MASK, NULL, HFILL }},
{ &hf_ntppriv_flags_more, {
"More bit", "ntp.priv.flags.more", FT_UINT8, BASE_DEC,
NULL, NTPPRIV_MORE_MASK, NULL, HFILL }},
{ &hf_ntppriv_auth_seq, {
"Auth, sequence", "ntp.priv.auth_seq", FT_UINT8, BASE_DEC,
NULL, 0, "Auth bit, sequence number", HFILL }},
{ &hf_ntppriv_auth, {
"Auth bit", "ntp.priv.auth", FT_UINT8, BASE_DEC,
NULL, NTPPRIV_AUTH_MASK, NULL, HFILL }},
{ &hf_ntppriv_seq, {
"Sequence number", "ntp.priv.seq", FT_UINT8, BASE_DEC,
NULL, NTPPRIV_SEQ_MASK, NULL, HFILL }},
{ &hf_ntppriv_impl, {
"Implementation", "ntp.priv.impl", FT_UINT8, BASE_DEC,
VALS(priv_impl_types), 0, NULL, HFILL }},
{ &hf_ntppriv_reqcode, {
"Request code", "ntp.priv.reqcode", FT_UINT8, BASE_DEC,
VALS(priv_rc_types), 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ntp,
&ett_ntp_flags,
&ett_ntp_ext,
&ett_ntp_ext_flags,
&ett_ntpctrl_flags2,
&ett_ntpctrl_status,
&ett_ntpctrl_data,
&ett_ntpctrl_item,
&ett_ntppriv_auth_seq
};
proto_ntp = proto_register_protocol("Network Time Protocol", "NTP",
"ntp");
proto_register_field_array(proto_ntp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
init_parser();
}
void
proto_reg_handoff_ntp(void)
{
dissector_handle_t ntp_handle;
ntp_handle = create_dissector_handle(dissect_ntp, proto_ntp);
dissector_add_uint("udp.port", UDP_PORT_NTP, ntp_handle);
dissector_add_uint("tcp.port", TCP_PORT_NTP, ntp_handle);
}
