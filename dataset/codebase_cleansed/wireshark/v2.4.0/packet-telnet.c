static void
check_tn3270_model(packet_info *pinfo _U_, const char *terminaltype)
{
int model;
if ((strcmp(terminaltype,"IBM-3278-2-E") == 0) || (strcmp(terminaltype,"IBM-3278-2") == 0) ||
(strcmp(terminaltype,"IBM-3278-3") == 0) || (strcmp(terminaltype,"IBM-3278-4") == 0) ||
(strcmp(terminaltype,"IBM-3278-5") == 0) || (strcmp(terminaltype,"IBM-3277-2") == 0) ||
(strcmp(terminaltype,"IBM-3279-3") == 0) || (strcmp(terminaltype,"IBM-3279-4") == 0) ||
(strcmp(terminaltype,"IBM-3279-2-E") == 0) || (strcmp(terminaltype,"IBM-3279-2") == 0) ||
(strcmp(terminaltype,"IBM-3279-4-E") == 0)) {
model = terminaltype[9] - '0';
add_tn3270_conversation(pinfo, 0, model);
}
}
static void
check_for_tn3270(packet_info *pinfo _U_, const char *optname, const char *terminaltype)
{
if (strcmp(optname,"Terminal Type") != 0) {
return;
}
check_tn3270_model(pinfo, terminaltype);
if ((strcmp(terminaltype,"IBM-5555-C01") == 0) ||
(strcmp(terminaltype,"IBM-5555-B01") == 0) ||
(strcmp(terminaltype,"IBM-3477-FC") == 0) ||
(strcmp(terminaltype,"IBM-3477-FG") == 0) ||
(strcmp(terminaltype,"IBM-3180-2") == 0) ||
(strcmp(terminaltype,"IBM-3179-2") == 0) ||
(strcmp(terminaltype,"IBM-3196-A1") == 0) ||
(strcmp(terminaltype,"IBM-5292-2") == 0) ||
(strcmp(terminaltype,"IBM-5291-1") == 0) ||
(strcmp(terminaltype,"IBM-5251-11") == 0))
add_tn5250_conversation(pinfo, 0);
}
static telnet_conv_info_t *
telnet_get_session(packet_info *pinfo)
{
conversation_t *conversation = find_or_create_conversation(pinfo);
telnet_conv_info_t *telnet_info;
telnet_info = (telnet_conv_info_t*)conversation_get_proto_data(conversation, proto_telnet);
if (!telnet_info) {
telnet_info = wmem_new0(wmem_file_scope(), telnet_conv_info_t);
conversation_add_proto_data(conversation, proto_telnet, telnet_info);
}
return telnet_info;
}
static void
dissect_string_subopt(packet_info *pinfo, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree, proto_item *item)
{
guint8 cmd;
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case 0:
proto_tree_add_uint_format(tree, hf_telnet_subcmd, tvb, offset, 1, cmd, "Here's my %s", optname);
offset++;
len--;
if (len > 0) {
proto_tree_add_item(tree, hf_telnet_string_subopt_value, tvb, offset, len, ENC_NA|ENC_ASCII);
}
check_for_tn3270(pinfo, optname, tvb_format_text(tvb, offset, len));
break;
case 1:
proto_tree_add_uint_format(tree, hf_telnet_subcmd, tvb, offset, 1, cmd, "Send your %s", optname);
offset++;
len--;
if (len > 0)
proto_tree_add_bytes_format(tree, hf_telnet_subcommand_data, tvb, offset, len, NULL, "Extra data");
break;
default:
expert_add_info_format(pinfo, item, &ei_telnet_invalid_subcommand, "Invalid %s subcommand %u", optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_item(tree, hf_telnet_subcommand_data, tvb, offset, len, ENC_NA);
break;
}
}
static void
dissect_tn3270_regime_subopt(packet_info *pinfo, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree, proto_item *item _U_)
{
#define TN3270_REGIME_ARE 0x01
#define TN3270_REGIME_IS 0x00
guint8 cmd;
while (len > 0) {
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case TN3270_REGIME_ARE:
case TN3270_REGIME_IS:
if (cmd == TN3270_REGIME_ARE) {
proto_tree_add_uint_format(tree, hf_tn3270_regime_cmd, tvb, offset, 1, cmd, "ARE");
add_tn3270_conversation(pinfo, 0, 0);
} else {
proto_tree_add_uint_format(tree, hf_tn3270_regime_cmd, tvb, offset, 1, cmd, "IS");
}
proto_tree_add_item(tree, hf_tn3270_regime_subopt_value, tvb, offset + 1, len - 1, ENC_NA|ENC_ASCII);
return;
default:
proto_tree_add_uint_format(tree, hf_tn3270_regime_cmd, tvb, offset, 1, cmd, "Bogus value: %u", cmd);
break;
}
offset++;
len --;
}
}
static void
dissect_tn3270e_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree, proto_item *item _U_)
{
guint8 cmd;
int datalen;
int connect_offset = 0;
int device_type = 0;
int rsn = 0;
while (len > 0) {
cmd = tvb_get_guint8(tvb, offset);
proto_tree_add_item( tree, hf_tn3270_subopt, tvb, offset, 1, ENC_BIG_ENDIAN );
switch (cmd) {
case TN3270_CONNECT:
proto_tree_add_item( tree, hf_tn3270_connect, tvb, offset + 1, len, ENC_NA|ENC_ASCII );
offset += (len - 1);
len -= (len - 1);
break;
case TN3270_IS:
device_type = tvb_get_guint8(tvb, offset-1);
if (device_type == TN3270_DEVICE_TYPE) {
connect_offset = tvb_find_guint8(tvb, offset + 1, len, TN3270_CONNECT);
if (connect_offset != -1) {
datalen = connect_offset - (offset + 1);
if (datalen > 0) {
proto_tree_add_item( tree, hf_tn3270_is, tvb, offset + 1, datalen, ENC_NA|ENC_ASCII );
check_tn3270_model(pinfo, tvb_format_text(tvb, offset + 1, datalen));
offset += datalen;
len -= datalen;
}
}
}
break;
case TN3270_REASON:
offset++;
len--;
proto_tree_add_item( tree, hf_tn3270_reason, tvb, offset, 1, ENC_BIG_ENDIAN );
break;
case TN3270_REQUEST:
add_tn3270_conversation(pinfo, 1, 0);
device_type = tvb_get_guint8(tvb, offset-1);
if (device_type == TN3270_DEVICE_TYPE) {
proto_tree_add_item( tree, hf_tn3270_request_string, tvb, offset + 1, len-1, ENC_NA|ENC_ASCII );
offset += (len - 1);
len -= (len - 1);
}else if (device_type == TN3270_FUNCTIONS) {
while (len > 0) {
rsn = tvb_get_guint8(tvb, offset);
proto_tree_add_item( tree, hf_tn3270_request, tvb, offset, 1, ENC_BIG_ENDIAN );
if (try_val_to_str(rsn, tn3270_request_vals) == NULL)
break;
offset++;
len--;
}
}
break;
}
offset++;
len--;
}
}
static void
dissect_starttls_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len _U_, proto_tree *tree, proto_item *item _U_)
{
telnet_conv_info_t *session = telnet_get_session(pinfo);
proto_tree_add_item(tree, hf_telnet_starttls, tvb, offset, 1, ENC_BIG_ENDIAN);
if (session->starttls_requested_in == 0) {
session->starttls_requested_in = pinfo->num;
session->starttls_port = pinfo->srcport;
} else if (session->starttls_requested_in < pinfo->num &&
session->starttls_port != pinfo->srcport) {
ssl_starttls_ack(ssl_handle, pinfo, telnet_handle);
}
}
static void
dissect_outmark_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree, proto_item *item _U_)
{
int gs_offset, datalen;
while (len > 0) {
proto_tree_add_item(tree, hf_telnet_outmark_subopt_cmd, tvb, offset, 1, ENC_ASCII | ENC_NA);
offset++;
len--;
gs_offset = tvb_find_guint8(tvb, offset, len, 29);
if (gs_offset == -1) {
gs_offset = offset + len;
}
datalen = gs_offset - offset;
if (datalen > 0) {
proto_tree_add_item(tree, hf_telnet_outmark_subopt_banner, tvb, offset, datalen, ENC_NA|ENC_ASCII);
offset += datalen;
len -= datalen;
}
}
}
static void
dissect_htstops_subopt(packet_info *pinfo, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree, proto_item *item)
{
guint8 cmd;
guint8 tabval;
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case 0:
proto_tree_add_uint_format(tree, hf_telnet_subcmd, tvb, offset, 1, cmd, "Here's my %s", optname);
offset++;
len--;
break;
case 1:
proto_tree_add_uint_format(tree, hf_telnet_subcmd, tvb, offset, 1, cmd, "Send your %s", optname);
offset++;
len--;
break;
default:
expert_add_info_format(pinfo, item, &ei_telnet_invalid_subcommand, "Invalid %s subcommand %u", optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_item(tree, hf_telnet_subcommand_data, tvb, offset, len, ENC_NA);
return;
}
while (len > 0) {
tabval = tvb_get_guint8(tvb, offset);
switch (tabval) {
case 0:
proto_tree_add_uint_format(tree, hf_telnet_tabstop, tvb, offset, 1,
tabval, "Sender wants to handle tab stops");
break;
default:
proto_tree_add_uint_format(tree, hf_telnet_tabstop, tvb, offset, 1,
tabval, "Sender wants receiver to handle tab stop at %u",
tabval);
break;
case 251:
case 252:
case 253:
case 254:
proto_tree_add_uint_format(tree, hf_telnet_tabstop, tvb, offset, 1,
tabval, "Invalid value: %u", tabval);
break;
case 255:
proto_tree_add_uint_format(tree, hf_telnet_tabstop, tvb, offset, 1,
tabval, "Sender wants receiver to handle tab stops");
break;
}
offset++;
len--;
}
}
static void
dissect_naws_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len _U_, proto_tree *tree, proto_item *item _U_)
{
proto_tree_add_item(tree, hf_telnet_naws_subopt_width, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_telnet_naws_subopt_height, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_comport_subopt(packet_info *pinfo, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree, proto_item *item)
{
static const char *datasizes[] = {
"Request",
"<invalid>",
"<invalid>",
"<invalid>",
"<invalid>",
"5",
"6",
"7",
"8"
};
static const char *parities[] = {
"Request",
"None",
"Odd",
"Even",
"Mark",
"Space"
};
static const char *stops[] = {
"Request",
"1",
"2",
"1.5"
};
static const char *control[] = {
"Output Flow Control Request",
"Output Flow: None",
"Output Flow: XON/XOFF",
"Output Flow: CTS/RTS",
"Break Request",
"Break: ON",
"Break: OFF",
"DTR Request",
"DTR: ON",
"DTR: OFF",
"RTS Request",
"RTS: ON",
"RTS: OFF",
"Input Flow Control Request",
"Input Flow: None",
"Input Flow: XON/XOFF",
"Input Flow: CTS/RTS",
"Output Flow: DCD",
"Input Flow: DTR",
"Output Flow: DSR"
};
static const char *linestate_bits[] = {
"Data Ready",
"Overrun Error",
"Parity Error",
"Framing Error",
"Break Detected",
"Transfer Holding Register Empty",
"Transfer Shift Register Empty",
"Timeout Error"
};
static const char *modemstate_bits[] = {
"DCTS",
"DDSR",
"TERI",
"DDCD",
"CTS",
"DSR",
"RI",
"DCD"
};
static const char *purges[] = {
"Purge None",
"Purge RX",
"Purge TX",
"Purge RX/TX"
};
guint8 cmd;
guint8 isservercmd;
const char *source;
cmd = tvb_get_guint8(tvb, offset);
isservercmd = cmd > 99;
cmd = (isservercmd) ? (cmd - 100) : cmd;
source = (isservercmd) ? "Server" : "Client";
switch (cmd) {
case TNCOMPORT_SIGNATURE:
len--;
if (len == 0) {
proto_tree_add_string_format(tree, hf_telnet_comport_subopt_signature, tvb, offset, 1, "", "%s Requests Signature", source);
} else {
guint8 *sig = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, len, ENC_ASCII);
proto_tree_add_string_format(tree, hf_telnet_comport_subopt_signature, tvb, offset, 1 + len, sig,
"%s Signature: %s",source, sig);
}
break;
case TNCOMPORT_SETBAUDRATE:
len--;
if (len >= 4) {
guint32 baud = tvb_get_ntohl(tvb, offset+1);
if (baud == 0) {
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_baud_rate, tvb, offset, 5, 0, "%s Requests Baud Rate",source);
} else {
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_baud_rate, tvb, offset, 5, baud, "%s Baud Rate: %d",source,baud);
}
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_baud_rate, "%s <Invalid Baud Rate Packet>", source);
}
break;
case TNCOMPORT_SETDATASIZE:
len--;
if (len >= 1) {
guint8 datasize = tvb_get_guint8(tvb, offset+1);
const char *ds = (datasize > 8) ? "<invalid>" : datasizes[datasize];
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_data_size, tvb, offset, 2, datasize,
"%s Data Size: %s",source,ds);
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_data_size, "%s <Invalid Data Size Packet>", source);
}
break;
case TNCOMPORT_SETPARITY:
len--;
if (len >= 1) {
guint8 parity = tvb_get_guint8(tvb, offset+1);
const char *pr = (parity > 5) ? "<invalid>" : parities[parity];
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_parity, tvb, offset, 2, parity,
"%s Parity: %s",source,pr);
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_parity, "%s <Invalid Parity Packet>", source);
}
break;
case TNCOMPORT_SETSTOPSIZE:
len--;
if (len >= 1) {
guint8 stop = tvb_get_guint8(tvb, offset+1);
const char *st = (stop > 3) ? "<invalid>" : stops[stop];
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_stop, tvb, offset, 2, stop,
"%s Stop: %s",source,st);
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_stop, "%s <Invalid Stop Packet>", source);
}
break;
case TNCOMPORT_SETCONTROL:
len--;
if (len >= 1) {
guint8 crt = tvb_get_guint8(tvb, offset+1);
const char *c = (crt > 19) ? "Control: <invalid>" : control[crt];
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_control, tvb, offset, 2, crt,
"%s Stop: %s",source,c);
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_control, "%s <Invalid Control Packet>", source);
}
break;
case TNCOMPORT_SETLINESTATEMASK:
case TNCOMPORT_NOTIFYLINESTATE:
len--;
if (len >= 1) {
const char *print_pattern = (cmd == TNCOMPORT_SETLINESTATEMASK) ?
"%s Set Linestate Mask: %s" : "%s Linestate: %s";
int hf_line = (cmd == TNCOMPORT_SETLINESTATEMASK) ?
hf_telnet_comport_set_linestate_mask : hf_telnet_comport_linestate;
char ls_buffer[512];
guint8 ls = tvb_get_guint8(tvb, offset+1);
int print_count = 0;
int idx;
ls_buffer[0] = '\0';
for (idx = 0; idx < 8; idx++) {
int bit = ls & 1;
if (bit) {
if (print_count != 0) {
g_strlcat(ls_buffer,", ",512);
}
g_strlcat(ls_buffer,linestate_bits[idx], 512);
print_count++;
}
ls = ls >> 1;
}
proto_tree_add_string_format(tree, hf_line, tvb, offset, 2, ls_buffer, print_pattern, source, ls_buffer);
} else {
const char *print_pattern = (cmd == TNCOMPORT_SETLINESTATEMASK) ?
"%s <Invalid Linestate Mask>" : "%s <Invalid Linestate Packet>";
expert_add_info_format(pinfo, item, &ei_telnet_invalid_linestate, print_pattern, source);
}
break;
case TNCOMPORT_SETMODEMSTATEMASK:
case TNCOMPORT_NOTIFYMODEMSTATE:
len--;
if (len >= 1) {
const char *print_pattern = (cmd == TNCOMPORT_SETMODEMSTATEMASK) ?
"%s Set Modemstate Mask: %s" : "%s Modemstate: %s";
int hf_modem = (cmd == TNCOMPORT_SETMODEMSTATEMASK) ?
hf_telnet_comport_set_modemstate_mask : hf_telnet_comport_modemstate;
char ms_buffer[256];
guint8 ms = tvb_get_guint8(tvb, offset+1);
int print_count = 0;
int idx;
ms_buffer[0] = '\0';
for (idx = 0; idx < 8; idx++) {
int bit = ms & 1;
if (bit) {
if (print_count != 0) {
g_strlcat(ms_buffer,", ",256);
}
g_strlcat(ms_buffer,modemstate_bits[idx],256);
print_count++;
}
ms = ms >> 1;
}
proto_tree_add_string_format(tree, hf_modem, tvb, offset, 2, ms_buffer, print_pattern, source, ms_buffer);
} else {
const char *print_pattern = (cmd == TNCOMPORT_SETMODEMSTATEMASK) ?
"%s <Invalid Modemstate Mask>" : "%s <Invalid Modemstate Packet>";
expert_add_info_format(pinfo, item, &ei_telnet_invalid_modemstate, print_pattern, source);
}
break;
case TNCOMPORT_FLOWCONTROLSUSPEND:
len--;
proto_tree_add_none_format(tree, hf_telnet_comport_subopt_flow_control_suspend, tvb, offset, 1, "%s Flow Control Suspend",source);
break;
case TNCOMPORT_FLOWCONTROLRESUME:
len--;
proto_tree_add_none_format(tree, hf_telnet_comport_subopt_flow_control_resume, tvb, offset, 1, "%s Flow Control Resume",source);
break;
case TNCOMPORT_PURGEDATA:
len--;
if (len >= 1) {
guint8 purge = tvb_get_guint8(tvb, offset+1);
const char *p = (purge > 3) ? "<Purge invalid>" : purges[purge];
proto_tree_add_uint_format_value(tree, hf_telnet_comport_subopt_purge, tvb, offset, 2, purge,
"%s %s",source,p);
} else {
expert_add_info_format(pinfo, item, &ei_telnet_invalid_purge, "%s <Invalid Purge Packet>", source);
}
break;
default:
expert_add_info_format(pinfo, item, &ei_telnet_invalid_subcommand, "Invalid %s subcommand %u", optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_item(tree, hf_telnet_subcommand_data, tvb, offset, len, ENC_NA);
return;
}
}
static void
dissect_rfc_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len _U_, proto_tree *tree, proto_item *item _U_)
{
proto_tree_add_item(tree, hf_telnet_rfc_subopt_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_authentication_type_pair(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, proto_tree *tree)
{
static const int * auth_mods[] = {
&hf_telnet_auth_mod_enc,
&hf_telnet_auth_mod_cred_fwd,
&hf_telnet_auth_mod_how,
&hf_telnet_auth_mod_who,
NULL
};
proto_tree_add_item(tree, hf_telnet_auth_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_list(tree, tvb, offset+1, 1, auth_mods, ENC_BIG_ENDIAN);
}
static tvbuff_t *
unescape_and_tvbuffify_telnet_option(packet_info *pinfo, tvbuff_t *tvb, int offset, int len)
{
tvbuff_t *krb5_tvb;
guint8 *buf;
const guint8 *spos;
guint8 *dpos;
int skip, l;
if(len>=MAX_KRB5_BLOB_LEN)
return NULL;
spos=tvb_get_ptr(tvb, offset, len);
buf=(guint8 *)wmem_alloc(pinfo->pool, len);
dpos=buf;
skip=0;
l=len;
while(l>0){
if((spos[0]==0xff) && (spos[1]==0xff)){
skip++;
l-=2;
*(dpos++)=0xff;
spos+=2;
continue;
}
*(dpos++)=*(spos++);
l--;
}
krb5_tvb = tvb_new_child_real_data(tvb, buf, len-skip, len-skip);
add_new_data_source(pinfo, krb5_tvb, "Unpacked Telnet Option");
return krb5_tvb;
}
static void
dissect_krb5_authentication_data(packet_info *pinfo, tvbuff_t *tvb, int offset, int len, proto_tree *tree, guint8 acmd)
{
tvbuff_t *krb5_tvb;
guint8 krb5_cmd;
proto_item* ti;
dissect_authentication_type_pair(pinfo, tvb, offset, tree);
offset+=2;
len-=2;
krb5_cmd=tvb_get_guint8(tvb, offset);
ti = proto_tree_add_uint(tree, hf_telnet_auth_krb5_type, tvb, offset, 1, krb5_cmd);
offset++;
len--;
if((acmd==TN_AC_IS)&&(krb5_cmd==TN_KRB5_TYPE_AUTH)){
if(len){
krb5_tvb=unescape_and_tvbuffify_telnet_option(pinfo, tvb, offset, len);
if(krb5_tvb)
dissect_kerberos_main(krb5_tvb, pinfo, tree, FALSE, NULL);
else
expert_add_info_format(pinfo, ti, &ei_telnet_kerberos_blob_too_long, "Kerberos blob (too long to dissect - length %u > %u)", len, MAX_KRB5_BLOB_LEN);
}
}
if((acmd==TN_AC_REPLY)&&(krb5_cmd==TN_KRB5_TYPE_RESPONSE)){
if(len){
krb5_tvb=unescape_and_tvbuffify_telnet_option(pinfo, tvb, offset, len);
dissect_kerberos_main(krb5_tvb, pinfo, tree, FALSE, NULL);
}
}
}
static void
dissect_authentication_subopt(packet_info *pinfo, const char *optname _U_, tvbuff_t *tvb, int offset, int len,
proto_tree *tree, proto_item *item _U_)
{
guint8 acmd;
acmd=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_auth_cmd, tvb, offset, 1, acmd);
offset++;
len--;
switch(acmd){
case TN_AC_REPLY:
case TN_AC_IS:
dissect_krb5_authentication_data(pinfo, tvb, offset, len, tree, acmd);
break;
case TN_AC_SEND:
while(len>0){
dissect_authentication_type_pair(pinfo, tvb, offset, tree);
offset+=2;
len-=2;
}
break;
case TN_AC_NAME:
proto_tree_add_item(tree, hf_telnet_auth_name, tvb, offset, len, ENC_ASCII|ENC_NA);
break;
}
}
static void dissect_encryption_type(tvbuff_t *tvb, int offset, proto_tree *tree) {
guint8 etype;
etype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_enc_type, tvb, offset, 1, etype);
}
static void
dissect_encryption_subopt(packet_info *pinfo, const char *optname _U_, tvbuff_t *tvb, int offset, int len,
proto_tree *tree, proto_item *item)
{
guint8 ecmd, key_first_octet;
ecmd = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_enc_cmd, tvb, offset, 1, ecmd);
offset++;
len--;
switch(ecmd) {
case TN_ENC_IS:
case TN_ENC_REPLY:
if (len > 0) {
dissect_encryption_type(tvb, offset, tree);
offset++;
len--;
proto_tree_add_item(tree, hf_telnet_enc_type_data, tvb, offset, len, ENC_NA);
}
break;
case TN_ENC_SUPPORT:
while (len > 0) {
dissect_encryption_type(tvb, offset, tree);
offset++;
len--;
}
break;
case TN_ENC_START:
if (len > 0) {
key_first_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_bytes_format(tree, hf_telnet_enc_key_id, tvb, offset, len, NULL, (key_first_octet == 0) ? "Default key" : "Key ID");
}
break;
case TN_ENC_END:
break;
case TN_ENC_REQUEST_START:
if (len > 0)
proto_tree_add_bytes_format(tree, hf_telnet_enc_key_id, tvb, offset, len, NULL, "Key ID (advisory)");
break;
case TN_ENC_REQUEST_END:
break;
case TN_ENC_ENC_KEYID:
case TN_ENC_DEC_KEYID:
if (len > 0)
proto_tree_add_item(tree, hf_telnet_enc_key_id, tvb, offset, len, ENC_NA);
break;
default:
expert_add_info(pinfo, item, &ei_telnet_enc_cmd_unknown);
}
}
static int
telnet_sub_option(packet_info *pinfo, proto_tree *option_tree, proto_item *option_item, tvbuff_t *tvb, int start_offset)
{
int offset = start_offset;
guint8 opt_byte;
int subneg_len;
const char *opt;
int iac_offset;
guint len;
tvbuff_t *unescaped_tvb;
void (*dissect)(packet_info *, const char *, tvbuff_t *, int, int, proto_tree *, proto_item*);
gint cur_offset;
gboolean iac_found;
int iac_data = 0;
offset += 2;
opt_byte = tvb_get_guint8(tvb, offset);
if (opt_byte >= NOPTIONS) {
opt = "<unknown option>";
dissect = NULL;
} else {
opt = options[opt_byte].name;
dissect = options[opt_byte].dissect;
}
offset++;
cur_offset = offset;
len = tvb_reported_length_remaining(tvb, offset);
do {
iac_offset = tvb_find_guint8(tvb, cur_offset, len, TN_IAC);
iac_found = TRUE;
if (iac_offset == -1) {
offset += len;
} else {
if (((guint)(iac_offset + 1) >= len) ||
(tvb_get_guint8(tvb, iac_offset + 1) != TN_IAC)) {
offset = iac_offset;
} else {
iac_found = FALSE;
cur_offset = iac_offset + 2;
iac_data += 1;
}
}
} while (!iac_found);
subneg_len = offset - start_offset;
start_offset += 3;
subneg_len -= 3;
if (subneg_len > 0) {
if (dissect != NULL) {
switch (options[opt_byte].len_type) {
case NO_LENGTH:
expert_add_info_format(pinfo, option_item, &ei_telnet_suboption_length, "Bogus suboption data");
return offset;
case FIXED_LENGTH:
if (subneg_len - iac_data != options[opt_byte].optlen) {
expert_add_info_format(pinfo, option_item, &ei_telnet_suboption_length, "Suboption parameter length is %d, should be %d", subneg_len, options[opt_byte].optlen);
return offset;
}
break;
case VARIABLE_LENGTH:
if (subneg_len - iac_data < options[opt_byte].optlen) {
expert_add_info_format(pinfo, option_item, &ei_telnet_suboption_length, "Suboption parameter length is %d, should be at least %d", subneg_len, options[opt_byte].optlen);
return offset;
}
break;
}
if (iac_data > 0) {
unescaped_tvb = unescape_and_tvbuffify_telnet_option(pinfo, tvb, start_offset, subneg_len);
(*dissect)(pinfo, opt, unescaped_tvb, 0, subneg_len - iac_data, option_tree, option_item);
} else {
(*dissect)(pinfo, opt, tvb, start_offset, subneg_len, option_tree, option_item);
}
} else {
if (iac_data > 0) {
unescaped_tvb = unescape_and_tvbuffify_telnet_option(pinfo, tvb, start_offset, subneg_len);
proto_tree_add_item(option_tree, hf_telnet_option_data, unescaped_tvb, 0, subneg_len - iac_data, ENC_NA);
} else {
proto_tree_add_item(option_tree, hf_telnet_option_data, tvb, start_offset, subneg_len, ENC_NA);
}
}
}
return offset;
}
static void
telnet_suboption_name(proto_tree *tree, tvbuff_t *tvb, int* offset, const gchar** optname,
proto_tree **opt_tree, proto_item **opt_item, const char *type)
{
guint8 opt_byte;
const char *opt;
gint ett = ett_telnet_subopt;
opt_byte = tvb_get_guint8(tvb, *offset);
if (opt_byte >= NOPTIONS) {
opt = "<unknown option>";
}
else {
opt = options[opt_byte].name;
if (options[opt_byte].subtree_index != NULL)
ett = *(options[opt_byte].subtree_index);
}
*opt_item = proto_tree_add_uint_format_value(tree, hf_telnet_subcmd, tvb, *offset, 1, opt_byte, "%s", opt);
*opt_tree = proto_item_add_subtree(*opt_item, ett);
(*offset)++;
(*optname) = wmem_strdup_printf(wmem_packet_scope(), "%s %s", type, opt);
}
static int
telnet_command(packet_info *pinfo, proto_tree *telnet_tree, tvbuff_t *tvb, int start_offset)
{
int offset = start_offset;
guchar optcode;
const gchar* optname;
proto_item *cmd_item, *subopt_item = NULL;
proto_tree *cmd_tree, *subopt_tree = NULL;
offset += 1;
optcode = tvb_get_guint8(tvb, offset);
cmd_tree = proto_tree_add_subtree(telnet_tree, tvb, start_offset, 2, ett_telnet_cmd, &cmd_item, "Command header");
proto_tree_add_item(cmd_tree, hf_telnet_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(optcode) {
case TN_WILL:
telnet_suboption_name(cmd_tree, tvb, &offset, &optname, &subopt_tree, &subopt_item, "Will");
break;
case TN_WONT:
telnet_suboption_name(cmd_tree, tvb, &offset, &optname, &subopt_tree, &subopt_item, "Won't");
break;
case TN_DO:
telnet_suboption_name(cmd_tree, tvb, &offset, &optname, &subopt_tree, &subopt_item, "Do");
break;
case TN_DONT:
telnet_suboption_name(cmd_tree, tvb, &offset, &optname, &subopt_tree, &subopt_item, "Don't");
break;
case TN_SB:
telnet_suboption_name(cmd_tree, tvb, &offset, &optname, &subopt_tree, &subopt_item, "Suboption");
break;
default:
optname = val_to_str_const(optcode, cmd_vals, "<unknown option>");
break;
}
proto_item_set_text(cmd_item, "%s", optname);
if (optcode == TN_SB) {
offset = telnet_sub_option(pinfo, subopt_tree, subopt_item, tvb, start_offset);
}
proto_item_set_len(cmd_item, offset-start_offset);
return offset;
}
static void
telnet_add_text(proto_tree *tree, tvbuff_t *tvb, int offset, int len)
{
gint next_offset;
int linelen;
guint8 c;
gboolean last_char_was_cr;
while (len != 0 && tvb_offset_exists(tvb, offset)) {
linelen = tvb_find_line_end(tvb, offset, len, &next_offset, FALSE);
len -= next_offset - offset;
if (next_offset == offset + linelen + 1 && len >= 1) {
if (tvb_get_guint8(tvb, offset + linelen) == '\r') {
last_char_was_cr = TRUE;
while (len != 0 && tvb_offset_exists(tvb, next_offset)) {
c = tvb_get_guint8(tvb, next_offset);
next_offset++;
len--;
if (c == '\n' || (c == '\0' && last_char_was_cr)) {
break;
}
last_char_was_cr = (c == '\r');
}
}
}
linelen = next_offset - offset;
proto_tree_add_item(tree, hf_telnet_data, tvb, offset, linelen, ENC_ASCII|ENC_NA);
offset = next_offset;
}
}
static int find_unescaped_iac(tvbuff_t *tvb, int offset, int len)
{
int iac_offset = offset;
while ((iac_offset = tvb_find_guint8(tvb, iac_offset, len, TN_IAC)) != -1 &&
(tvb_get_guint8(tvb, iac_offset + 1) == TN_IAC))
{
iac_offset+=2;
len = tvb_reported_length_remaining(tvb, iac_offset);
}
return iac_offset;
}
static int
dissect_telnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *telnet_tree, *ti;
tvbuff_t *next_tvb;
gint offset = 0;
guint len = 0;
guint is_tn3270 = 0;
guint is_tn5250 = 0;
int data_len;
gint iac_offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TELNET");
col_set_str(pinfo->cinfo, COL_INFO, "Telnet Data ...");
is_tn3270 = find_tn3270_conversation(pinfo);
is_tn5250 = find_tn5250_conversation(pinfo);
ti = proto_tree_add_item(tree, proto_telnet, tvb, offset, -1, ENC_NA);
telnet_tree = proto_item_add_subtree(ti, ett_telnet);
while ((len = tvb_reported_length_remaining(tvb, offset)) > 0) {
iac_offset = find_unescaped_iac(tvb, offset, len);
if (iac_offset != -1) {
data_len = iac_offset - offset;
if (data_len > 0) {
if (is_tn3270) {
next_tvb = tvb_new_subset_length(tvb, offset, data_len);
call_dissector(tn3270_handle, next_tvb, pinfo, telnet_tree);
} else if (is_tn5250) {
next_tvb = tvb_new_subset_length(tvb, offset, data_len);
call_dissector(tn5250_handle, next_tvb, pinfo, telnet_tree);
} else
telnet_add_text(telnet_tree, tvb, offset, data_len);
}
offset = telnet_command(pinfo, telnet_tree, tvb, iac_offset);
} else {
if (is_tn3270 || is_tn5250) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return tvb_captured_length(tvb);
}
telnet_add_text(telnet_tree, tvb, offset, len);
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_telnet(void)
{
static hf_register_info hf[] = {
{ &hf_telnet_cmd,
{ "Command", "telnet.cmd", FT_UINT8, BASE_DEC,
VALS(cmd_vals), 0, NULL, HFILL }
},
{ &hf_telnet_subcmd,
{ "Subcommand", "telnet.subcmd", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_auth_name,
{ "Name", "telnet.auth.name", FT_STRING, BASE_NONE,
NULL, 0, "Name of user being authenticated", HFILL }
},
{ &hf_telnet_auth_cmd,
{ "Auth Cmd", "telnet.auth.cmd", FT_UINT8, BASE_DEC,
VALS(auth_cmd_vals), 0, "Authentication Command", HFILL }
},
{ &hf_telnet_auth_type,
{ "Auth Type", "telnet.auth.type", FT_UINT8, BASE_DEC,
VALS(auth_type_vals), 0, "Authentication Type", HFILL }
},
{ &hf_telnet_auth_mod_cred_fwd,
{ "Cred Fwd", "telnet.auth.mod.cred_fwd", FT_BOOLEAN, 8,
TFS(&auth_mod_cred_fwd), 0x08, "Modifier: Whether client will forward creds or not", HFILL }
},
{ &hf_telnet_auth_mod_who,
{ "Who", "telnet.auth.mod.who", FT_BOOLEAN, 8,
TFS(&auth_mod_who), 0x01, "Modifier: Who to mask", HFILL }
},
{ &hf_telnet_auth_mod_how,
{ "How", "telnet.auth.mod.how", FT_BOOLEAN, 8,
TFS(&auth_mod_how), 0x02, "Modifier: How to mask", HFILL }
},
{ &hf_telnet_auth_mod_enc,
{ "Encrypt", "telnet.auth.mod.enc", FT_UINT8, BASE_DEC,
VALS(auth_mod_enc), 0x14, "Modifier: How to enable Encryption", HFILL }
},
{ &hf_telnet_auth_krb5_type,
{ "Command", "telnet.auth.krb5.cmd", FT_UINT8, BASE_DEC,
VALS(auth_krb5_types), 0, "Krb5 Authentication sub-command", HFILL }
},
{ &hf_telnet_string_subopt_value,
{ "Value", "telnet.string_subopt.value", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_naws_subopt_width,
{ "Width", "telnet.naws_subopt.width", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_naws_subopt_height,
{ "Height", "telnet.naws_subopt.height", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_outmark_subopt_cmd,
{ "Command", "telnet.outmark_subopt.cmd", FT_CHAR, BASE_HEX,
VALS(telnet_outmark_subopt_cmd_vals), 0, NULL, HFILL }
},
{ &hf_telnet_outmark_subopt_banner,
{ "Banner", "telnet.outmark_subopt.banner", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_signature,
{ "Signature", "telnet.comport_subopt.signature", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_baud_rate,
{ "Baud Rate", "telnet.comport_subopt.baud_rate", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_data_size,
{ "Data Size", "telnet.comport_subopt.data_size", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_parity,
{ "Parity", "telnet.comport_subopt.parity", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_stop,
{ "Stop Bits", "telnet.comport_subopt.stop", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_control,
{ "Control", "telnet.comport_subopt.control", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_linestate,
{ "Linestate", "telnet.comport_subopt.linestate", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_set_linestate_mask,
{ "Set Linestate Mask", "telnet.comport_subopt.set_linestate_mask", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_modemstate,
{ "Modemstate", "telnet.comport_subopt.modemstate", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_set_modemstate_mask,
{ "Set Modemstate Mask", "telnet.comport_subopt.set_modemstate_mask", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_flow_control_suspend,
{ "Flow Control Suspend", "telnet.comport_subopt.flow_control_suspend", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_flow_control_resume,
{ "Flow Control Resume", "telnet.comport_subopt.flow_control_resume", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_comport_subopt_purge,
{ "Purge", "telnet.comport_subopt.purge", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_rfc_subopt_cmd,
{ "Command", "telnet.rfc_subopt.cmd", FT_UINT8, BASE_DEC,
VALS(rfc_opt_vals), 0, NULL, HFILL }
},
{ &hf_telnet_tabstop,
{ "Tabstop value", "telnet.tabstop", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_enc_cmd,
{ "Enc Cmd", "telnet.enc.cmd", FT_UINT8, BASE_DEC,
VALS(enc_cmd_vals), 0, "Encryption command", HFILL }
},
{ &hf_telnet_enc_type,
{ "Enc Type", "telnet.enc.type", FT_UINT8, BASE_DEC,
VALS(enc_type_vals), 0, "Encryption type", HFILL }
},
{ &hf_telnet_enc_type_data,
{ "Type-specific data", "telnet.enc.type_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_enc_key_id,
{ "Key ID", "telnet.enc.key_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_data,
{ "Data", "telnet.data", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_option_data,
{ "Option data", "telnet.option_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_subcommand_data,
{ "Subcommand data", "telnet.subcommand_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_tn3270_subopt,
{ "Suboption", "telnet.tn3270.subopt", FT_UINT8, BASE_DEC,
VALS(tn3270_subopt_vals), 0, NULL, HFILL }
},
{ &hf_tn3270_connect,
{ "Connect", "telnet.tn3270.connect", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_tn3270_is,
{ "Is", "telnet.tn3270.is", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_tn3270_request_string,
{ "Request", "telnet.tn3270.request_string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_tn3270_reason,
{ "Reason", "telnet.tn3270.reason", FT_UINT8, BASE_DEC,
VALS(tn3270_reason_vals), 0, NULL, HFILL }
},
{ &hf_tn3270_request,
{ "Request", "telnet.tn3270.request", FT_UINT8, BASE_DEC,
VALS(tn3270_request_vals), 0, NULL, HFILL }
},
{ &hf_tn3270_regime_subopt_value,
{ "Value", "telnet.tn3270.regime_subopt.value", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_tn3270_regime_cmd,
{ "Cmd", "telnet.regime_cmd", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_telnet_starttls,
{ "Follows", "telnet.starttls", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_telnet,
&ett_telnet_cmd,
&ett_telnet_subopt,
&ett_status_subopt,
&ett_rcte_subopt,
&ett_olw_subopt,
&ett_ops_subopt,
&ett_crdisp_subopt,
&ett_htstops_subopt,
&ett_htdisp_subopt,
&ett_ffdisp_subopt,
&ett_vtstops_subopt,
&ett_vtdisp_subopt,
&ett_lfdisp_subopt,
&ett_extasc_subopt,
&ett_bytemacro_subopt,
&ett_det_subopt,
&ett_supdupout_subopt,
&ett_sendloc_subopt,
&ett_termtype_subopt,
&ett_tacacsui_subopt,
&ett_outmark_subopt,
&ett_tlocnum_subopt,
&ett_tn3270reg_subopt,
&ett_x3pad_subopt,
&ett_naws_subopt,
&ett_tspeed_subopt,
&ett_rfc_subopt,
&ett_linemode_subopt,
&ett_xdpyloc_subopt,
&ett_env_subopt,
&ett_auth_subopt,
&ett_enc_subopt,
&ett_newenv_subopt,
&ett_tn3270e_subopt,
&ett_xauth_subopt,
&ett_charset_subopt,
&ett_rsp_subopt,
&ett_comport_subopt,
&ett_starttls_subopt,
};
static ei_register_info ei[] = {
{ &ei_telnet_invalid_subcommand, { "telnet.invalid_subcommand", PI_PROTOCOL, PI_WARN, "Invalid subcommand", EXPFILL }},
{ &ei_telnet_invalid_baud_rate, { "telnet.invalid_baud_rate", PI_PROTOCOL, PI_WARN, "Invalid Baud Rate", EXPFILL }},
{ &ei_telnet_invalid_data_size, { "telnet.invalid_data_size", PI_PROTOCOL, PI_WARN, "Invalid Data Size", EXPFILL }},
{ &ei_telnet_invalid_parity, { "telnet.invalid_parity", PI_PROTOCOL, PI_WARN, "Invalid Parity Packet", EXPFILL }},
{ &ei_telnet_invalid_stop, { "telnet.invalid_stop", PI_PROTOCOL, PI_WARN, "Invalid Stop Packet", EXPFILL }},
{ &ei_telnet_invalid_control, { "telnet.invalid_control", PI_PROTOCOL, PI_WARN, "Invalid Control Packet", EXPFILL }},
{ &ei_telnet_invalid_linestate, { "telnet.invalid_linestate", PI_PROTOCOL, PI_WARN, "Invalid linestate", EXPFILL }},
{ &ei_telnet_invalid_modemstate, { "telnet.invalid_modemstate", PI_PROTOCOL, PI_WARN, "Invalid Modemstate", EXPFILL }},
{ &ei_telnet_invalid_purge, { "telnet.invalid_purge", PI_PROTOCOL, PI_WARN, "Invalid Purge Packet", EXPFILL }},
{ &ei_telnet_kerberos_blob_too_long, { "telnet.kerberos_blob_too_long", PI_PROTOCOL, PI_NOTE, "Kerberos blob too long to dissect", EXPFILL }},
{ &ei_telnet_enc_cmd_unknown, { "telnet.enc.cmd.unknown", PI_PROTOCOL, PI_WARN, "Unknown encryption command", EXPFILL }},
{ &ei_telnet_suboption_length, { "telnet.suboption_length.invalid", PI_PROTOCOL, PI_WARN, "Bogus suboption data", EXPFILL }},
};
expert_module_t* expert_telnet;
proto_telnet = proto_register_protocol("Telnet", "TELNET", "telnet");
proto_register_field_array(proto_telnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_telnet = expert_register_protocol(proto_telnet);
expert_register_field_array(expert_telnet, ei, array_length(ei));
telnet_handle = register_dissector("telnet", dissect_telnet, proto_telnet);
}
void
proto_reg_handoff_telnet(void)
{
dissector_add_uint_with_preference("tcp.port", TCP_PORT_TELNET, telnet_handle);
tn3270_handle = find_dissector_add_dependency("tn3270", proto_telnet);
tn5250_handle = find_dissector_add_dependency("tn5250", proto_telnet);
ssl_handle = find_dissector("ssl");
}
