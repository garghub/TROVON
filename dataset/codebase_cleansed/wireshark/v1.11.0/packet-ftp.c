static gboolean
parse_port_pasv(const guchar *line, int linelen, guint32 *ftp_ip, guint16 *ftp_port,
guint32 *pasv_offset, guint *ftp_ip_len, guint *ftp_port_len)
{
char *args;
char *p;
guchar c;
int i;
int ip_address[4], port[2];
gboolean ret = FALSE;
args = wmem_strndup(wmem_packet_scope(), line, linelen);
p = args;
for (;;) {
while ((c = *p) != '\0' && !isdigit(c))
p++;
if (*p == '\0') {
break;
}
i = sscanf(p, "%d,%d,%d,%d,%d,%d",
&ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3],
&port[0], &port[1]);
if (i == 6) {
*ftp_port = ((port[0] & 0xFF)<<8) | (port[1] & 0xFF);
*ftp_ip = g_htonl((ip_address[0] << 24) | (ip_address[1] <<16) | (ip_address[2] <<8) | ip_address[3]);
*pasv_offset = (guint32)(p - args);
*ftp_port_len = (port[0] < 10 ? 1 : (port[0] < 100 ? 2 : 3 )) + 1 +
(port[1] < 10 ? 1 : (port[1] < 100 ? 2 : 3 ));
*ftp_ip_len = (ip_address[0] < 10 ? 1 : (ip_address[0] < 100 ? 2 : 3)) + 1 +
(ip_address[1] < 10 ? 1 : (ip_address[1] < 100 ? 2 : 3)) + 1 +
(ip_address[2] < 10 ? 1 : (ip_address[2] < 100 ? 2 : 3)) + 1 +
(ip_address[3] < 10 ? 1 : (ip_address[3] < 100 ? 2 : 3));
ret = TRUE;
break;
}
while ((c = *p) != '\0' && isdigit(c))
p++;
}
return ret;
}
static gboolean
isvalid_rfc2428_delimiter(const guchar c)
{
static const gchar forbidden[] = {"0123456789abcdef.:"};
if (c < 33 || c > 126)
return FALSE;
else if (strchr(forbidden, tolower(c)))
return FALSE;
else
return TRUE;
}
static gboolean
parse_eprt_request(const guchar* line, gint linelen, guint32 *eprt_af,
guint32 *eprt_ip, guint16 *eprt_ipv6, guint16 *ftp_port,
guint32 *eprt_ip_len, guint32 *ftp_port_len)
{
gint delimiters_seen = 0;
gchar delimiter;
gint fieldlen;
gchar *field;
gint n;
gint lastn;
char *args, *p;
gboolean ret = TRUE;
if (!line || linelen<4)
return FALSE;
args = wmem_strndup(wmem_packet_scope(), line, linelen);
p = args;
if (!isvalid_rfc2428_delimiter(*p))
return FALSE;
delimiter = *p;
for (n = 0; n < linelen; n++) {
if (*(p+n) == delimiter)
delimiters_seen++;
}
if (delimiters_seen != 4)
return FALSE;
delimiters_seen = 1;
lastn = 0;
for (n=1; n < linelen; n++) {
if (*(p+n) != delimiter)
continue;
delimiters_seen++;
fieldlen = n - lastn - 1;
if (fieldlen<=0)
return FALSE;
field = p + lastn + 1;
if (delimiters_seen == 2) {
gchar *af_str;
af_str = wmem_strndup(wmem_packet_scope(), field, fieldlen);
*eprt_af = atoi(af_str);
}
else if (delimiters_seen == 3) {
gchar *ip_str;
ip_str = wmem_strndup(wmem_packet_scope(), field, fieldlen);
if (*eprt_af == EPRT_AF_IPv4) {
if (inet_pton(AF_INET, ip_str, eprt_ip) > 0)
ret = TRUE;
else
ret = FALSE;
}
else if (*eprt_af == EPRT_AF_IPv6) {
if (inet_pton(AF_INET6, ip_str, eprt_ipv6) > 0)
ret = TRUE;
else
ret = FALSE;
}
else
return FALSE;
*eprt_ip_len = fieldlen;
}
else if (delimiters_seen == 4) {
gchar *pt_str;
pt_str = wmem_strndup(wmem_packet_scope(), field, fieldlen);
*ftp_port = atoi(pt_str);
*ftp_port_len = fieldlen;
}
lastn = n;
}
return ret;
}
static gboolean
parse_extended_pasv_response(const guchar *line, gint linelen, guint16 *ftp_port,
guint *pasv_offset, guint *ftp_port_len)
{
gint n;
gchar *args;
gchar *p;
gchar *e;
guchar c;
gboolean ret = FALSE;
gboolean delimiters_seen = FALSE;
args = wmem_strndup(wmem_packet_scope(), line, linelen);
p = args;
for (; !delimiters_seen;) {
guchar delimiter = '\0';
while ((c = *p) != '\0' && (c != '('))
p++;
if (*p == '\0') {
return FALSE;
}
p++;
for (n=0; n<3; n++) {
if ((c = *p) != '\0') {
if (delimiter == '\0' && isvalid_rfc2428_delimiter(c)) {
delimiter = c;
}
if (c != delimiter) {
break;
}
p++;
}
else {
break;
}
}
delimiters_seen = TRUE;
}
if (*p != '\0') {
*ftp_port = atoi(p);
*pasv_offset = (guint32)(p - args);
ret = TRUE;
if ((e=strchr(p,')')) == NULL) {
ret = FALSE;
}
else {
*ftp_port_len = (guint)(--e - p);
}
}
return ret;
}
static void
dissect_ftp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean is_request;
proto_tree *ftp_tree = NULL;
proto_tree *reqresp_tree = NULL;
proto_item *ti, *hidden_item;
gint offset;
const guchar *line;
guint32 code;
gchar code_str[4];
gboolean is_port_request = FALSE;
gboolean is_eprt_request = FALSE;
gboolean is_pasv_response = FALSE;
gboolean is_epasv_response = FALSE;
gint next_offset;
int linelen;
int tokenlen = 0;
const guchar *next_token;
guint32 pasv_ip;
guint32 pasv_offset;
guint32 ftp_ip;
guint32 ftp_ip_len;
guint32 eprt_offset;
guint32 eprt_af = 0;
guint32 eprt_ip;
guint16 eprt_ipv6[8];
guint32 eprt_ip_len = 0;
guint16 ftp_port;
guint32 ftp_port_len;
address ftp_ip_address;
gboolean ftp_nat;
conversation_t *conversation;
ftp_ip_address = pinfo->src;
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FTP");
linelen = tvb_find_line_end(tvb, 0, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, 0, linelen);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(line, linelen));
ti = proto_tree_add_item(tree, proto_ftp, tvb, 0, -1, ENC_NA);
ftp_tree = proto_item_add_subtree(ti, ett_ftp);
if (is_request) {
hidden_item = proto_tree_add_boolean(ftp_tree,
hf_ftp_request, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_boolean(ftp_tree,
hf_ftp_response, tvb, 0, 0, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
hidden_item = proto_tree_add_boolean(ftp_tree,
hf_ftp_request, tvb, 0, 0, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_boolean(ftp_tree,
hf_ftp_response, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
ti = proto_tree_add_text(ftp_tree, tvb, 0, next_offset, "%s",
tvb_format_text(tvb, 0, next_offset));
reqresp_tree = proto_item_add_subtree(ti, ett_ftp_reqresp);
if (is_request) {
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
proto_tree_add_item(reqresp_tree, hf_ftp_request_command,
tvb, 0, tokenlen, ENC_ASCII|ENC_NA);
if (strncmp(line, "PORT", tokenlen) == 0)
is_port_request = TRUE;
else if (strncmp(line, "EPRT", tokenlen) == 0)
is_eprt_request = TRUE;
}
} else {
if (linelen >= 3 && isdigit(line[0]) && isdigit(line[1])
&& isdigit(line[2])) {
tvb_get_nstringz0(tvb, 0, sizeof(code_str), code_str);
code = (guint32)strtoul(code_str, NULL, 10);
proto_tree_add_uint(reqresp_tree,
hf_ftp_response_code, tvb, 0, 3, code);
if (code == 227)
is_pasv_response = TRUE;
if (code == 229)
is_epasv_response = TRUE;
if (linelen >= 4)
next_token = line + 4;
else
next_token = line + linelen;
} else {
next_token = line;
}
}
offset = (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
if (linelen != 0) {
if (is_request) {
proto_tree_add_item(reqresp_tree,
hf_ftp_request_arg, tvb, offset,
linelen, ENC_ASCII|ENC_NA);
} else {
proto_tree_add_item(reqresp_tree,
hf_ftp_response_arg, tvb, offset,
linelen, ENC_ASCII|ENC_NA);
}
}
offset = next_offset;
if (is_port_request) {
if (parse_port_pasv(line, linelen, &ftp_ip, &ftp_port, &pasv_offset, &ftp_ip_len, &ftp_port_len)) {
proto_tree_add_ipv4(reqresp_tree, hf_ftp_active_ip,
tvb, pasv_offset + (tokenlen+1) , ftp_ip_len, ftp_ip);
proto_tree_add_uint(reqresp_tree, hf_ftp_active_port,
tvb, pasv_offset + 1 + (tokenlen+1) + ftp_ip_len, ftp_port_len, ftp_port);
SET_ADDRESS(&ftp_ip_address, AT_IPv4, 4, (const guint8 *)&ftp_ip);
ftp_nat = !ADDRESSES_EQUAL(&pinfo->src, &ftp_ip_address);
if (ftp_nat) {
proto_tree_add_boolean(reqresp_tree, hf_ftp_active_nat,
tvb, 0, 0, ftp_nat);
}
}
}
if (is_pasv_response) {
if (linelen != 0) {
if (parse_port_pasv(line, linelen, &pasv_ip, &ftp_port, &pasv_offset, &ftp_ip_len, &ftp_port_len)) {
proto_tree_add_ipv4(reqresp_tree, hf_ftp_pasv_ip,
tvb, pasv_offset + 4, ftp_ip_len, pasv_ip);
proto_tree_add_uint(reqresp_tree, hf_ftp_pasv_port,
tvb, pasv_offset + 4 + 1 + ftp_ip_len, ftp_port_len, ftp_port);
SET_ADDRESS(&ftp_ip_address, AT_IPv4, 4,
(const guint8 *)&pasv_ip);
ftp_nat = !ADDRESSES_EQUAL(&pinfo->src, &ftp_ip_address);
if (ftp_nat) {
proto_tree_add_boolean(reqresp_tree, hf_ftp_pasv_nat,
tvb, 0, 0, ftp_nat);
}
conversation = find_conversation(pinfo->fd->num, &ftp_ip_address,
&pinfo->dst, PT_TCP, ftp_port, 0,
NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(
pinfo->fd->num, &ftp_ip_address, &pinfo->dst,
PT_TCP, ftp_port, 0, NO_PORT2);
conversation_set_dissector(conversation, ftpdata_handle);
}
}
}
}
if (is_eprt_request) {
if (parse_eprt_request(line, linelen,
&eprt_af, &eprt_ip, eprt_ipv6, &ftp_port,
&eprt_ip_len, &ftp_port_len)) {
eprt_offset = tokenlen + 1 + 1;
proto_tree_add_uint(reqresp_tree, hf_ftp_eprt_af, tvb,
eprt_offset, 1, eprt_af);
eprt_offset += 1 + 1;
if (eprt_af == EPRT_AF_IPv4) {
proto_tree_add_ipv4(reqresp_tree, hf_ftp_eprt_ip,
tvb, eprt_offset, eprt_ip_len, eprt_ip);
SET_ADDRESS(&ftp_ip_address, AT_IPv4, 4,
(const guint8 *)&eprt_ip);
}
else if (eprt_af == EPRT_AF_IPv6) {
proto_tree_add_ipv6(reqresp_tree, hf_ftp_eprt_ipv6,
tvb, eprt_offset, eprt_ip_len, (const guint8 *)eprt_ipv6);
SET_ADDRESS(&ftp_ip_address, AT_IPv6, 16,
(const guint8 *)&eprt_ipv6);
}
eprt_offset += eprt_ip_len + 1;
proto_tree_add_uint(reqresp_tree, hf_ftp_eprt_port,
tvb, eprt_offset, ftp_port_len, ftp_port);
conversation = find_conversation(pinfo->fd->num,
&pinfo->src, &ftp_ip_address,
PT_TCP, ftp_port, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(
pinfo->fd->num, &pinfo->src, &ftp_ip_address,
PT_TCP, ftp_port, 0, NO_PORT2);
conversation_set_dissector(conversation,
ftpdata_handle);
}
}
else {
proto_item *item;
item = proto_tree_add_text(reqresp_tree,
tvb, offset - linelen - 1, linelen, "Invalid EPRT arguments");
expert_add_info(pinfo, item, &ei_ftp_eprt_args_invalid);
}
}
if (is_epasv_response) {
if (linelen != 0) {
proto_item *addr_it;
if (parse_extended_pasv_response(line, linelen,
&ftp_port, &pasv_offset, &ftp_port_len)) {
if (ftp_ip_address.type == AT_IPv4) {
guint32 addr;
memcpy(&addr, ftp_ip_address.data, 4);
addr_it = proto_tree_add_ipv4(reqresp_tree,
hf_ftp_epsv_ip, tvb, 0, 0, addr);
PROTO_ITEM_SET_GENERATED(addr_it);
}
else if (ftp_ip_address.type == AT_IPv6) {
addr_it = proto_tree_add_ipv6(reqresp_tree,
hf_ftp_epsv_ipv6, tvb, 0, 0,
(guint8*)ftp_ip_address.data);
PROTO_ITEM_SET_GENERATED(addr_it);
}
proto_tree_add_uint(reqresp_tree,
hf_ftp_epsv_port, tvb, pasv_offset + 4,
ftp_port_len, ftp_port);
conversation = find_conversation(pinfo->fd->num, &ftp_ip_address,
&pinfo->dst, PT_TCP, ftp_port, 0,
NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(
pinfo->fd->num, &ftp_ip_address, &pinfo->dst,
PT_TCP, ftp_port, 0, NO_PORT2);
conversation_set_dissector(conversation,
ftpdata_handle);
}
}
else {
proto_item *item;
item = proto_tree_add_text(reqresp_tree,
tvb, offset - linelen - 1, linelen, "Invalid EPSV arguments");
expert_add_info(pinfo, item, &ei_ftp_epsv_args_invalid);
}
}
}
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
proto_tree_add_text(ftp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
offset = next_offset;
}
}
static void
dissect_ftpdata(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
int data_length;
gboolean is_text = TRUE;
gint check_chars, i;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FTP-DATA");
col_add_fstr(pinfo->cinfo, COL_INFO, "FTP Data: %u bytes",
tvb_reported_length(tvb));
data_length = tvb_length(tvb);
ti = proto_tree_add_item(tree, proto_ftp_data, tvb, 0, -1, ENC_NA);
check_chars = MIN(10, data_length);
for (i=0; i < check_chars; i++) {
if (!isprint(tvb_get_guint8(tvb, i))) {
is_text = FALSE;
break;
}
}
if (is_text) {
proto_item_append_text(ti, " (%s)", tvb_format_text(tvb, 0, MIN(data_length, ITEM_LABEL_LENGTH)));
}
else {
proto_item_append_text(ti, " (%u bytes data)", data_length);
}
}
void
proto_register_ftp(void)
{
static hf_register_info hf[] = {
{ &hf_ftp_response,
{ "Response", "ftp.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if FTP response", HFILL }},
{ &hf_ftp_request,
{ "Request", "ftp.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if FTP request", HFILL }},
{ &hf_ftp_request_command,
{ "Request command", "ftp.request.command",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ftp_request_arg,
{ "Request arg", "ftp.request.arg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ftp_response_code,
{ "Response code", "ftp.response.code",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &response_table_ext, 0x0,
NULL, HFILL }},
{ &hf_ftp_response_arg,
{ "Response arg", "ftp.response.arg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ftp_pasv_ip,
{ "Passive IP address", "ftp.passive.ip",
FT_IPv4, BASE_NONE, NULL,0x0,
"Passive IP address (check NAT)", HFILL}},
{ &hf_ftp_pasv_port,
{ "Passive port", "ftp.passive.port",
FT_UINT16, BASE_DEC, NULL,0x0,
"Passive FTP server port", HFILL }},
{ &hf_ftp_pasv_nat,
{"Passive IP NAT", "ftp.passive.nat",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"NAT is active SIP and passive IP different", HFILL }},
{ &hf_ftp_active_ip,
{ "Active IP address", "ftp.active.cip",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Active FTP client IP address", HFILL }},
{ &hf_ftp_active_port,
{"Active port", "ftp.active.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Active FTP client port", HFILL }},
{ &hf_ftp_active_nat,
{ "Active IP NAT", "ftp.active.nat",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"NAT is active", HFILL}},
{ &hf_ftp_eprt_af,
{ "Extended active address family", "ftp.eprt.af",
FT_UINT8, BASE_DEC, VALS(eprt_af_vals), 0,
NULL, HFILL }},
{ &hf_ftp_eprt_ip,
{ "Extended active IP address", "ftp.eprt.ip",
FT_IPv4, BASE_NONE, NULL, 0,
"Extended active FTP client IPv4 address", HFILL }},
{ &hf_ftp_eprt_ipv6,
{ "Extended active IPv6 address", "ftp.eprt.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"Extended active FTP client IPv6 address", HFILL }},
{ &hf_ftp_eprt_port,
{ "Extended active port", "ftp.eprt.port",
FT_UINT16, BASE_DEC, NULL, 0,
"Extended active FTP client listener port", HFILL }},
{ &hf_ftp_epsv_ip,
{ "Extended passive IPv4 address", "ftp.epsv.ip",
FT_IPv4, BASE_NONE, NULL, 0,
"Extended passive FTP server IPv4 address", HFILL }},
{ &hf_ftp_epsv_ipv6,
{ "Extended passive IPv6 address", "ftp.epsv.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"Extended passive FTP server IPv6 address", HFILL }},
{ &hf_ftp_epsv_port,
{ "Extended passive port", "ftp.epsv.port",
FT_UINT16, BASE_DEC, NULL, 0,
"Extended passive FTP server port", HFILL }}
};
static gint *ett[] = {
&ett_ftp,
&ett_ftp_reqresp
};
static ei_register_info ei[] = {
{ &ei_ftp_eprt_args_invalid, { "ftp.eprt.args_invalid", PI_MALFORMED, PI_WARN, "EPRT arguments must have the form: |<family>|<addr>|<port>|", EXPFILL }},
{ &ei_ftp_epsv_args_invalid, { "ftp.epsv.args_invalid", PI_MALFORMED, PI_WARN, "EPSV arguments must have the form (|||<port>|)", EXPFILL }},
};
expert_module_t* expert_ftp;
proto_ftp = proto_register_protocol("File Transfer Protocol (FTP)", "FTP", "ftp");
register_dissector("ftp", dissect_ftp, proto_ftp);
proto_ftp_data = proto_register_protocol("FTP Data", "FTP-DATA", "ftp-data");
register_dissector("ftp-data", dissect_ftpdata, proto_ftp_data);
proto_register_field_array(proto_ftp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ftp = expert_register_protocol(proto_ftp);
expert_register_field_array(expert_ftp, ei, array_length(ei));
}
void
proto_reg_handoff_ftp(void)
{
dissector_handle_t ftp_handle;
ftpdata_handle = find_dissector("ftp-data");
dissector_add_uint("tcp.port", TCP_PORT_FTPDATA, ftpdata_handle);
ftp_handle = find_dissector("ftp");
dissector_add_uint("tcp.port", TCP_PORT_FTP, ftp_handle);
}
