static void
check_tn3270_model(packet_info *pinfo _U_, const char *terminaltype)
{
int model;
char str_model[2];
if ((strcmp(terminaltype,"IBM-3278-2-E") == 0) || (strcmp(terminaltype,"IBM-3278-2") == 0) ||
(strcmp(terminaltype,"IBM-3278-3") == 0) || (strcmp(terminaltype,"IBM-3278-4") == 0) ||
(strcmp(terminaltype,"IBM-3278-5") == 0) || (strcmp(terminaltype,"IBM-3277-2") == 0) ||
(strcmp(terminaltype,"IBM-3279-3") == 0) || (strcmp(terminaltype,"IBM-3279-4") == 0) ||
(strcmp(terminaltype,"IBM-3279-2-E") == 0) || (strcmp(terminaltype,"IBM-3279-2") == 0) ||
(strcmp(terminaltype,"IBM-3279-4-E") == 0)) {
str_model[0] = terminaltype[9];
str_model[1] = '\0';
model = atoi(str_model);
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
static void
dissect_string_subopt(packet_info *pinfo _U_, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 cmd;
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case 0:
proto_tree_add_text(tree, tvb, offset, 1, "Here's my %s", optname);
offset++;
len--;
if (len > 0) {
proto_tree_add_text(tree, tvb, offset, len, "Value: %s",
tvb_format_text(tvb, offset, len));
}
check_for_tn3270(pinfo, optname, tvb_format_text(tvb, offset, len));
break;
case 1:
proto_tree_add_text(tree, tvb, offset, 1, "Send your %s", optname);
offset++;
len--;
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Extra data");
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Invalid %s subcommand %u",
optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Subcommand data");
break;
}
}
static void
dissect_tn3270_regime_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree)
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
proto_tree_add_text(tree, tvb, offset, 1, "ARE");
add_tn3270_conversation(pinfo, 0, 0);
} else {
proto_tree_add_text(tree, tvb, offset, 1, "IS");
}
proto_tree_add_text(tree, tvb, offset + 1, len - 1, "%s",
tvb_format_text(tvb, offset + 1, len - 1));
offset += len;
len -= len;
return;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Bogus value: %u", cmd);
break;
}
offset++;
len --;
}
}
static void
dissect_tn3270e_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree)
{
guint8 cmd;
int datalen;
int connect_offset = 0;
int device_type = 0;
int rsn = 0;
while (len > 0) {
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case TN3270_ASSOCIATE:
proto_tree_add_text(tree, tvb, offset, 1, "ASSOCIATE");
break;
case TN3270_CONNECT:
proto_tree_add_text(tree, tvb, offset, 1, "CONNECT");
proto_tree_add_text(tree, tvb, offset + 1, len, "%s",
tvb_format_text(tvb, offset + 1, len - 1));
offset += (len - 1);
len -= (len - 1);
break;
case TN3270_DEVICE_TYPE:
proto_tree_add_text(tree, tvb, offset, 1, "DEVICE-TYPE");
break;
case TN3270_FUNCTIONS:
proto_tree_add_text(tree, tvb, offset, 1, "FUNCTIONS");
break;
case TN3270_IS:
proto_tree_add_text(tree, tvb, offset, 1, "IS");
device_type = tvb_get_guint8(tvb, offset-1);
if (device_type == TN3270_DEVICE_TYPE) {
connect_offset = tvb_find_guint8(tvb, offset + 1, len, TN3270_CONNECT);
if (connect_offset != -1) {
datalen = connect_offset - (offset + 1);
if (datalen > 0) {
proto_tree_add_text(tree, tvb, offset + 1, datalen, "%s",
tvb_format_text(tvb, offset + 1, datalen));
check_tn3270_model(pinfo, tvb_format_text(tvb, offset + 1, datalen));
offset += datalen;
len -= datalen;
}
}
}
break;
case TN3270_REASON:
proto_tree_add_text(tree, tvb, offset, 1, "REASON");
offset++;
len--;
rsn = tvb_get_guint8(tvb, offset);
switch (rsn) {
case TN3270_CONN_PARTNER:
proto_tree_add_text(tree, tvb, offset, 1, "CONN-PARTNER");
break;
case TN3270_DEVICE_IN_USE:
proto_tree_add_text(tree, tvb, offset, 1, "DEVICE-IN-USE");
break;
case TN3270_INV_ASSOCIATE:
proto_tree_add_text(tree, tvb, offset, 1, "INV-ASSOCIATE");
break;
case TN3270_INV_DEVICE_NAME:
proto_tree_add_text(tree, tvb, offset, 1, "INV-DEVICE-NAME");
break;
case TN3270_INV_DEVICE_TYPE:
proto_tree_add_text(tree, tvb, offset, 1, "INV-DEVICE-TYPE");
break;
case TN3270_TYPE_NAME_ERROR:
proto_tree_add_text(tree, tvb, offset, 1, "TYPE-NAME-ERROR");
break;
case TN3270_UNKNOWN_ERROR:
proto_tree_add_text(tree, tvb, offset, 1, "UNKNOWN-ERROR");
break;
case TN3270_UNSUPPORTED_REQ:
proto_tree_add_text(tree, tvb, offset, 1, "UNSUPPORTED-REQ");
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Bogus value: %u", rsn);
break;
}
break;
case TN3270_REJECT:
proto_tree_add_text(tree, tvb, offset, 1, "REJECT");
break;
case TN3270_REQUEST:
add_tn3270_conversation(pinfo, 1, 0);
proto_tree_add_text(tree, tvb, offset, 1, "REQUEST");
device_type = tvb_get_guint8(tvb, offset-1);
if (device_type == TN3270_DEVICE_TYPE) {
proto_tree_add_text(tree, tvb, offset + 1, len, "%s",
tvb_format_text(tvb, offset + 1, len - 1));
offset += (len - 1);
len -= (len - 1);
}else if (device_type == TN3270_FUNCTIONS) {
int fn = 0;
while (len > 0 && fn < 5) {
rsn = tvb_get_guint8(tvb, offset);
switch (rsn) {
case TN3270_BIND_IMAGE:
proto_tree_add_text(tree, tvb, offset, 1, "BIND-IMAGE");
break;
case TN3270_DATA_STREAM_CTL:
proto_tree_add_text(tree, tvb, offset, 1, "DATA-STREAM-CTL");
break;
case TN3270_RESPONSES:
proto_tree_add_text(tree, tvb, offset, 1, "RESPONSES");
break;
case TN3270_SCS_CTL_CODES:
proto_tree_add_text(tree, tvb, offset, 1, "SCS-CTL-CODES");
break;
case TN3270_SYSREQ:
proto_tree_add_text(tree, tvb, offset, 1, "SYSREQ");
break;
default:
fn = 5;
break;
}
offset++;
len--;
}
}
break;
case TN3270_SEND:
proto_tree_add_text(tree, tvb, offset, 1, "SEND");
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Bogus value: %u", cmd);
break;
}
offset++;
len--;
}
}
static void
dissect_outmark_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len, proto_tree *tree)
{
guint8 cmd;
int gs_offset, datalen;
while (len > 0) {
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case 6:
proto_tree_add_text(tree, tvb, offset, 1, "ACK");
break;
case 21:
proto_tree_add_text(tree, tvb, offset, 1, "NAK");
break;
case 'D':
proto_tree_add_text(tree, tvb, offset, 1, "Default");
break;
case 'T':
proto_tree_add_text(tree, tvb, offset, 1, "Top");
break;
case 'B':
proto_tree_add_text(tree, tvb, offset, 1, "Bottom");
break;
case 'L':
proto_tree_add_text(tree, tvb, offset, 1, "Left");
break;
case 'R':
proto_tree_add_text(tree, tvb, offset, 1, "Right");
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Bogus value: %u", cmd);
break;
}
offset++;
len--;
gs_offset = tvb_find_guint8(tvb, offset, len, 29);
if (gs_offset == -1) {
gs_offset = offset + len;
}
datalen = gs_offset - offset;
if (datalen > 0) {
proto_tree_add_text(tree, tvb, offset, datalen, "Banner: %s",
tvb_format_text(tvb, offset, datalen));
offset += datalen;
len -= datalen;
}
}
}
static void
dissect_htstops_subopt(packet_info *pinfo _U_, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 cmd;
guint8 tabval;
cmd = tvb_get_guint8(tvb, offset);
switch (cmd) {
case 0:
proto_tree_add_text(tree, tvb, offset, 1, "Here's my %s", optname);
offset++;
len--;
break;
case 1:
proto_tree_add_text(tree, tvb, offset, 1, "Send your %s", optname);
offset++;
len--;
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Invalid %s subcommand %u",
optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Subcommand data");
return;
}
while (len > 0) {
tabval = tvb_get_guint8(tvb, offset);
switch (tabval) {
case 0:
proto_tree_add_text(tree, tvb, offset, 1,
"Sender wants to handle tab stops");
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Sender wants receiver to handle tab stop at %u",
tabval);
break;
case 251:
case 252:
case 253:
case 254:
proto_tree_add_text(tree, tvb, offset, 1,
"Invalid value: %u", tabval);
break;
case 255:
proto_tree_add_text(tree, tvb, offset, 1,
"Sender wants receiver to handle tab stops");
break;
}
offset++;
len--;
}
}
static void
dissect_naws_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len _U_, proto_tree *tree)
{
proto_tree_add_text(tree, tvb, offset, 2, "Width: %u",
tvb_get_ntohs(tvb, offset));
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Height: %u",
tvb_get_ntohs(tvb, offset));
}
static void
dissect_comport_subopt(packet_info *pinfo _U_, const char *optname, tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
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
proto_tree_add_text(tree, tvb, offset, 1, "%s Requests Signature",source);
} else {
guint8 *sig = tvb_get_ephemeral_string(tvb, offset + 1, len);
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s Signature: %s",source, sig);
}
break;
case TNCOMPORT_SETBAUDRATE:
len--;
if (len >= 4) {
guint32 baud = tvb_get_ntohl(tvb, offset+1);
if (baud == 0) {
proto_tree_add_text(tree, tvb, offset, 5, "%s Requests Baud Rate",source);
} else {
proto_tree_add_text(tree, tvb, offset, 5, "%s Baud Rate: %d",source,baud);
}
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Baud Rate Packet>",source);
}
break;
case TNCOMPORT_SETDATASIZE:
len--;
if (len >= 1) {
guint8 datasize = tvb_get_guint8(tvb, offset+1);
const char *ds = (datasize > 8) ? "<invalid>" : datasizes[datasize];
proto_tree_add_text(tree, tvb, offset, 2, "%s Data Size: %s",source,ds);
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Data Size Packet>",source);
}
break;
case TNCOMPORT_SETPARITY:
len--;
if (len >= 1) {
guint8 parity = tvb_get_guint8(tvb, offset+1);
const char *pr = (parity > 5) ? "<invalid>" : parities[parity];
proto_tree_add_text(tree, tvb, offset, 2, "%s Parity: %s",source,pr);
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Parity Packet>",source);
}
break;
case TNCOMPORT_SETSTOPSIZE:
len--;
if (len >= 1) {
guint8 stop = tvb_get_guint8(tvb, offset+1);
const char *st = (stop > 3) ? "<invalid>" : stops[stop];
proto_tree_add_text(tree, tvb, offset, 2, "%s Stop: %s",source,st);
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Stop Packet>",source);
}
break;
case TNCOMPORT_SETCONTROL:
len--;
if (len >= 1) {
guint8 crt = tvb_get_guint8(tvb, offset+1);
const char *c = (crt > 19) ? "Control: <invalid>" : control[crt];
proto_tree_add_text(tree, tvb, offset, 2, "%s %s",source,c);
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Control Packet>",source);
}
break;
case TNCOMPORT_SETLINESTATEMASK:
case TNCOMPORT_NOTIFYLINESTATE:
len--;
if (len >= 1) {
const char *print_pattern = (cmd == TNCOMPORT_SETLINESTATEMASK) ?
"%s Set Linestate Mask: %s" : "%s Linestate: %s";
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
proto_tree_add_text(tree, tvb, offset, 2, print_pattern, source, ls_buffer);
} else {
const char *print_pattern = (cmd == TNCOMPORT_SETLINESTATEMASK) ?
"%s <Invalid Linestate Mask>" : "%s <Invalid Linestate Packet>";
proto_tree_add_text(tree, tvb, offset, 1 + len, print_pattern, source);
}
break;
case TNCOMPORT_SETMODEMSTATEMASK:
case TNCOMPORT_NOTIFYMODEMSTATE:
len--;
if (len >= 1) {
const char *print_pattern = (cmd == TNCOMPORT_SETMODEMSTATEMASK) ?
"%s Set Modemstate Mask: %s" : "%s Modemstate: %s";
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
proto_tree_add_text(tree, tvb, offset, 2, print_pattern, source, ms_buffer);
} else {
const char *print_pattern = (cmd == TNCOMPORT_SETMODEMSTATEMASK) ?
"%s <Invalid Modemstate Mask>" : "%s <Invalid Modemstate Packet>";
proto_tree_add_text(tree, tvb, offset, 1 + len, print_pattern, source);
}
break;
case TNCOMPORT_FLOWCONTROLSUSPEND:
len--;
proto_tree_add_text(tree, tvb, offset, 1, "%s Flow Control Suspend",source);
break;
case TNCOMPORT_FLOWCONTROLRESUME:
len--;
proto_tree_add_text(tree, tvb, offset, 1, "%s Flow Control Resume",source);
break;
case TNCOMPORT_PURGEDATA:
len--;
if (len >= 1) {
guint8 purge = tvb_get_guint8(tvb, offset+1);
const char *p = (purge > 3) ? "<Purge invalid>" : purges[purge];
proto_tree_add_text(tree, tvb, offset, 2, "%s %s",source,p);
} else {
proto_tree_add_text(tree, tvb, offset, 1 + len, "%s <Invalid Purge Packet>",source);
}
break;
default:
proto_tree_add_text(tree, tvb, offset, 1, "Invalid %s subcommand %u",
optname, cmd);
offset++;
len--;
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Subcommand data");
return;
}
}
static void
dissect_rfc_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset,
int len _U_, proto_tree *tree)
{
guint8 cmd;
cmd = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "%s",
val_to_str(cmd, rfc_opt_vals, "Unknown (%u)"));
}
static void
dissect_authentication_type_pair(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 type, mod;
type=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_auth_type, tvb, offset, 1, type);
mod=tvb_get_guint8(tvb, offset+1);
proto_tree_add_uint(tree, hf_telnet_auth_mod_enc, tvb, offset+1, 1, mod);
proto_tree_add_boolean(tree, hf_telnet_auth_mod_cred_fwd, tvb, offset+1, 1, mod);
proto_tree_add_boolean(tree, hf_telnet_auth_mod_how, tvb, offset+1, 1, mod);
proto_tree_add_boolean(tree, hf_telnet_auth_mod_who, tvb, offset+1, 1, mod);
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
buf=g_malloc(len);
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
tvb_set_free_cb(krb5_tvb, g_free);
add_new_data_source(pinfo, krb5_tvb, "Unpacked Telnet Option");
return krb5_tvb;
}
static void
dissect_krb5_authentication_data(packet_info *pinfo, tvbuff_t *tvb, int offset, int len, proto_tree *tree, guint8 acmd)
{
tvbuff_t *krb5_tvb;
guint8 krb5_cmd;
dissect_authentication_type_pair(pinfo, tvb, offset, tree);
offset+=2;
len-=2;
krb5_cmd=tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_auth_krb5_type, tvb, offset, 1, krb5_cmd);
offset++;
len--;
if((acmd==TN_AC_IS)&&(krb5_cmd==TN_KRB5_TYPE_AUTH)){
if(len){
krb5_tvb=unescape_and_tvbuffify_telnet_option(pinfo, tvb, offset, len);
if(krb5_tvb)
dissect_kerberos_main(krb5_tvb, pinfo, tree, FALSE, NULL);
else
proto_tree_add_text(tree, tvb, offset, len, "Kerberos blob (too long to dissect - length %u > %u",
len, MAX_KRB5_BLOB_LEN);
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
dissect_authentication_subopt(packet_info *pinfo, const char *optname _U_, tvbuff_t *tvb, int offset, int len, proto_tree *tree)
{
guint8 acmd;
char *name;
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
if(len<255){
name=ep_alloc(256);
tvb_memcpy(tvb, (guint8*)name, offset, len);
name[len]=0;
} else {
name="<...name too long...>";
}
proto_tree_add_string(tree, hf_telnet_auth_name, tvb, offset, len, name);
break;
}
}
static void dissect_encryption_type(tvbuff_t *tvb, int offset, proto_tree *tree) {
guint8 etype;
etype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_telnet_enc_type, tvb, offset, 1, etype);
}
static void
dissect_encryption_subopt(packet_info *pinfo _U_, const char *optname _U_, tvbuff_t *tvb, int offset, int len, proto_tree *tree)
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
proto_tree_add_text(tree, tvb, offset, len, "Type-specific data");
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
proto_tree_add_text(tree, tvb, offset, len, (key_first_octet == 0) ? "Default key" : "Key ID");
}
break;
case TN_ENC_END:
break;
case TN_ENC_REQUEST_START:
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Key ID (advisory)");
break;
case TN_ENC_REQUEST_END:
break;
case TN_ENC_ENC_KEYID:
case TN_ENC_DEC_KEYID:
if (len > 0)
proto_tree_add_text(tree, tvb, offset, len, "Key ID");
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "Unknown command");
}
}
static int
telnet_sub_option(packet_info *pinfo, proto_tree *telnet_tree, tvbuff_t *tvb, int start_offset)
{
proto_tree *ti, *option_tree;
int offset = start_offset;
guint8 opt_byte;
int subneg_len;
const char *opt;
gint ett = ett_telnet_subopt;
int iac_offset;
guint len;
tvbuff_t *unescaped_tvb;
void (*dissect)(packet_info *, const char *, tvbuff_t *, int, int, proto_tree *);
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
if (options[opt_byte].subtree_index != NULL)
ett = *(options[opt_byte].subtree_index);
dissect = options[opt_byte].dissect;
}
offset++;
cur_offset = offset;
iac_found = FALSE;
len = tvb_length_remaining(tvb, offset);
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
ti = proto_tree_add_text(telnet_tree, tvb, start_offset, subneg_len,
"Suboption Begin: %s", opt);
option_tree = proto_item_add_subtree(ti, ett);
start_offset += 3;
subneg_len -= 3;
if (subneg_len > 0) {
if (dissect != NULL) {
switch (options[opt_byte].len_type) {
case NO_LENGTH:
proto_tree_add_text(option_tree, tvb, start_offset, subneg_len,
"Bogus suboption data");
return offset;
case FIXED_LENGTH:
if (subneg_len - iac_data != options[opt_byte].optlen) {
proto_tree_add_text(option_tree, tvb, start_offset, subneg_len,
"Suboption parameter length is %d, should be %d",
subneg_len, options[opt_byte].optlen);
return offset;
}
break;
case VARIABLE_LENGTH:
if (subneg_len - iac_data < options[opt_byte].optlen) {
proto_tree_add_text(option_tree, tvb, start_offset, subneg_len,
"Suboption parameter length is %d, should be at least %d",
subneg_len, options[opt_byte].optlen);
return offset;
}
break;
}
if (iac_data > 0) {
unescaped_tvb = unescape_and_tvbuffify_telnet_option(pinfo, tvb, start_offset, subneg_len);
(*dissect)(pinfo, opt, unescaped_tvb, 0, subneg_len - iac_data, option_tree);
} else {
(*dissect)(pinfo, opt, tvb, start_offset, subneg_len, option_tree);
}
} else {
if (iac_data > 0) {
unescaped_tvb = unescape_and_tvbuffify_telnet_option(pinfo, tvb, start_offset, subneg_len);
proto_tree_add_text(option_tree, unescaped_tvb, 0, subneg_len - iac_data,
"Option data");
} else {
proto_tree_add_text(option_tree, tvb, start_offset, subneg_len,
"Option data");
}
}
}
return offset;
}
static int
telnet_will_wont_do_dont(proto_tree *telnet_tree, tvbuff_t *tvb,
int start_offset, const char *type)
{
int offset = start_offset;
guint8 opt_byte;
const char *opt;
offset += 2;
opt_byte = tvb_get_guint8(tvb, offset);
if (opt_byte >= NOPTIONS)
opt = "<unknown option>";
else
opt = options[opt_byte].name;
offset++;
proto_tree_add_text(telnet_tree, tvb, start_offset, 3,
"Command: %s %s", type, opt);
return offset;
}
static int
telnet_command(packet_info *pinfo, proto_tree *telnet_tree, tvbuff_t *tvb, int start_offset)
{
int offset = start_offset;
guchar optcode;
offset += 1;
optcode = tvb_get_guint8(tvb, offset);
offset++;
switch(optcode) {
case TN_EOF:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: End of File");
break;
case TN_SUSP:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Suspend Current Process");
break;
case TN_ABORT:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Abort Process");
break;
case TN_EOR:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: End of Record");
break;
case TN_SE:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Suboption End");
break;
case TN_NOP:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: No Operation");
break;
case TN_DM:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Data Mark");
break;
case TN_BRK:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Break");
break;
case TN_IP:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Interrupt Process");
break;
case TN_AO:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Abort Output");
break;
case TN_AYT:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Are You There?");
break;
case TN_EC:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Escape Character");
break;
case TN_EL:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Erase Line");
break;
case TN_GA:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Go Ahead");
break;
case TN_SB:
offset = telnet_sub_option(pinfo, telnet_tree, tvb, start_offset);
break;
case TN_WILL:
offset = telnet_will_wont_do_dont(telnet_tree, tvb, start_offset,
"Will");
break;
case TN_WONT:
offset = telnet_will_wont_do_dont(telnet_tree, tvb, start_offset,
"Won't");
break;
case TN_DO:
offset = telnet_will_wont_do_dont(telnet_tree, tvb, start_offset,
"Do");
break;
case TN_DONT:
offset = telnet_will_wont_do_dont(telnet_tree, tvb, start_offset,
"Don't");
break;
default:
proto_tree_add_text(telnet_tree, tvb, start_offset, 2,
"Command: Unknown (0x%02x)", optcode);
break;
}
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
len = tvb_length_remaining(tvb, iac_offset);
}
return iac_offset;
}
static void
dissect_telnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
while ((len = tvb_length_remaining(tvb, offset)) > 0) {
iac_offset = find_unescaped_iac(tvb, offset, len);
if (iac_offset != -1) {
data_len = iac_offset - offset;
if (data_len > 0) {
if (is_tn3270) {
next_tvb = tvb_new_subset(tvb, offset, data_len, data_len);
call_dissector(tn3270_handle, next_tvb, pinfo, telnet_tree);
} else if (is_tn5250) {
next_tvb = tvb_new_subset(tvb, offset, data_len, data_len);
call_dissector(tn5250_handle, next_tvb, pinfo, telnet_tree);
} else
telnet_add_text(telnet_tree, tvb, offset, data_len);
}
offset = telnet_command(pinfo, telnet_tree, tvb, iac_offset);
} else {
if (is_tn3270 || is_tn5250) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
telnet_add_text(telnet_tree, tvb, offset, len);
break;
}
}
}
void
proto_register_telnet(void)
{
static hf_register_info hf[] = {
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
{ &hf_telnet_enc_cmd,
{ "Enc Cmd", "telnet.enc.cmd", FT_UINT8, BASE_DEC,
VALS(enc_cmd_vals), 0, "Encryption command", HFILL }
},
{ &hf_telnet_enc_type,
{ "Enc Type", "telnet.enc.type", FT_UINT8, BASE_DEC,
VALS(enc_type_vals), 0, "Encryption type", HFILL }
},
{ &hf_telnet_data,
{ "Data", "telnet.data", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_telnet,
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
&ett_comport_subopt
};
proto_telnet = proto_register_protocol("Telnet", "TELNET", "telnet");
proto_register_field_array(proto_telnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_telnet(void)
{
dissector_handle_t telnet_handle;
telnet_handle = create_dissector_handle(dissect_telnet, proto_telnet);
dissector_add_uint("tcp.port", TCP_PORT_TELNET, telnet_handle);
tn3270_handle = find_dissector("tn3270");
tn5250_handle = find_dissector("tn5250");
}
