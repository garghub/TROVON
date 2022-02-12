static gboolean
parse_port_pasv(const guchar *line, int linelen, guint32 *ftp_ip, guint16 *ftp_port)
{
char *args;
char *p;
guchar c;
int i;
int ip_address[4], port[2];
gboolean ret = FALSE;
args = ep_strndup(line, linelen);
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
ret = TRUE;
break;
}
while ((c = *p) != '\0' && isdigit(c))
p++;
}
return ret;
}
static gboolean
parse_extended_pasv_response(const guchar *line, int linelen, guint16 *ftp_port)
{
int n;
char *args;
char *p;
guchar c;
gboolean ret = FALSE;
gboolean delimiters_seen = FALSE;
args = ep_strndup(line, linelen);
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
if (delimiter == '\0') {
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
ret = TRUE;
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
gint offset = 0;
const guchar *line;
guint32 code;
gchar code_str[4];
gboolean is_port_request = FALSE;
gboolean is_pasv_response = FALSE;
gboolean is_epasv_response = FALSE;
gint next_offset;
int linelen;
int tokenlen;
const guchar *next_token;
guint32 pasv_ip;
guint32 ftp_ip;
guint16 ftp_port;
address ftp_ip_address;
gboolean ftp_nat;
conversation_t *conversation;
ftp_ip_address = pinfo->src;
if (pinfo->match_uint == pinfo->destport)
is_request = TRUE;
else
is_request = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FTP");
linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
line = tvb_get_ptr(tvb, offset, linelen);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s",
is_request ? "Request" : "Response",
format_text(line, linelen));
if (tree) {
ti = proto_tree_add_item(tree, proto_ftp, tvb, offset, -1, ENC_NA);
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
ti = proto_tree_add_text(ftp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
reqresp_tree = proto_item_add_subtree(ti, ett_ftp_reqresp);
}
if (is_request) {
tokenlen = get_token_len(line, line + linelen, &next_token);
if (tokenlen != 0) {
if (tree) {
proto_tree_add_item(reqresp_tree,
hf_ftp_request_command, tvb, offset,
tokenlen, ENC_ASCII|ENC_NA);
}
if (strncmp(line, "PORT", tokenlen) == 0)
is_port_request = TRUE;
}
} else {
if (linelen >= 3 && isdigit(line[0]) && isdigit(line[1])
&& isdigit(line[2])) {
tvb_get_nstringz0(tvb, offset, sizeof(code_str), code_str);
code = strtoul(code_str, NULL, 10);
if (tree) {
proto_tree_add_uint(reqresp_tree,
hf_ftp_response_code, tvb, offset, 3, code);
}
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
offset += (gint) (next_token - line);
linelen -= (int) (next_token - line);
line = next_token;
if (tree) {
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
}
if (is_port_request) {
if (parse_port_pasv(line, linelen, &ftp_ip, &ftp_port)) {
if (tree) {
proto_tree_add_ipv4(reqresp_tree,
hf_ftp_active_ip, tvb, 0, 0,
ftp_ip);
proto_tree_add_uint(reqresp_tree,
hf_ftp_active_port, tvb, 0, 0,
ftp_port);
}
SET_ADDRESS(&ftp_ip_address, AT_IPv4, 4, (const guint8 *)&ftp_ip);
ftp_nat = !ADDRESSES_EQUAL(&pinfo->src, &ftp_ip_address);
if (ftp_nat) {
if (tree) {
proto_tree_add_boolean(
reqresp_tree,
hf_ftp_active_nat, tvb,
0, 0, ftp_nat);
}
}
}
}
if (is_pasv_response) {
if (linelen != 0) {
if (parse_port_pasv(line, linelen, &pasv_ip, &ftp_port)) {
if (tree) {
proto_tree_add_ipv4(reqresp_tree,
hf_ftp_pasv_ip, tvb, 0, 0, pasv_ip);
proto_tree_add_uint(reqresp_tree,
hf_ftp_pasv_port, tvb, 0, 0,
ftp_port);
}
SET_ADDRESS(&ftp_ip_address, AT_IPv4, 4,
(const guint8 *)&pasv_ip);
ftp_nat = !ADDRESSES_EQUAL(&pinfo->src, &ftp_ip_address);
if (ftp_nat) {
if (tree) {
proto_tree_add_boolean(reqresp_tree,
hf_ftp_pasv_nat, tvb, 0, 0,
ftp_nat);
}
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
if (is_epasv_response) {
if (linelen != 0) {
if (parse_extended_pasv_response(line, linelen, &ftp_port)) {
if (tree) {
proto_tree_add_uint(reqresp_tree,
hf_ftp_pasv_port, tvb, 0, 0,
ftp_port);
}
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, PT_TCP, ftp_port, 0,
NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(
pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_TCP, ftp_port, 0, NO_PORT2);
conversation_set_dissector(conversation,
ftpdata_handle);
}
}
}
}
if (tree) {
while (tvb_offset_exists(tvb, offset)) {
tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE);
proto_tree_add_text(ftp_tree, tvb, offset,
next_offset - offset, "%s",
tvb_format_text(tvb, offset, next_offset - offset));
offset = next_offset;
}
}
}
static void
dissect_ftpdata(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ti, *ftp_data_tree;
int data_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FTP-DATA");
col_add_fstr(pinfo->cinfo, COL_INFO, "FTP Data: %u bytes",
tvb_reported_length(tvb));
if (tree) {
data_length = tvb_length(tvb);
ti = proto_tree_add_item(tree, proto_ftp_data, tvb, 0, -1,
ENC_NA);
ftp_data_tree = proto_item_add_subtree(ti, ett_ftp_data);
proto_tree_add_text(ftp_data_tree, tvb, 0, data_length,
"FTP Data: %s", tvb_format_text(tvb, 0, data_length));
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
"NAT is active", HFILL}}
};
static gint *ett[] = {
&ett_ftp,
&ett_ftp_reqresp,
&ett_ftp_data,
};
proto_ftp = proto_register_protocol("File Transfer Protocol (FTP)", "FTP",
"ftp");
register_dissector("ftp", dissect_ftp, proto_ftp);
proto_ftp_data = proto_register_protocol("FTP Data", "FTP-DATA", "ftp-data");
register_dissector("ftp-data", dissect_ftpdata, proto_ftp_data);
proto_register_field_array(proto_ftp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
