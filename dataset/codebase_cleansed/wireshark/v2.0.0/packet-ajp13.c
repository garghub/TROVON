static const gchar *
ajp13_get_nstring(tvbuff_t *tvb, gint offset, guint16* ret_len)
{
guint16 len;
len = tvb_get_ntohs(tvb, offset);
if (ret_len)
*ret_len = len+1;
if (len == 0xFFFF)
len = 0;
return tvb_format_text(tvb, offset+2, MIN(len, ITEM_LABEL_LENGTH));
}
static void
display_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ajp13_tree, ajp13_conv_data* cd)
{
int pos = 0;
guint8 mcode = 0;
int i;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_magic, tvb, pos, 2, ENC_NA);
pos+=2;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_len, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
mcode = tvb_get_guint8(tvb, pos);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(mcode, mtype_codes, "Unknown message code %u"));
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_code, tvb, pos, 1, ENC_BIG_ENDIAN);
pos+=1;
switch (mcode) {
case MTYPE_END_RESPONSE:
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_reusep, tvb, pos, 1, ENC_BIG_ENDIAN);
break;
case MTYPE_SEND_HEADERS:
{
const gchar *rsmsg;
guint16 rsmsg_len;
guint16 nhdr;
guint16 rcode_num;
rcode_num = tvb_get_ntohs(tvb, pos);
col_append_fstr(pinfo->cinfo, COL_INFO, ":%d", rcode_num);
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_rstatus, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
rsmsg = ajp13_get_nstring(tvb, pos, &rsmsg_len);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", rsmsg);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_rsmsg, tvb, pos, rsmsg_len+2, rsmsg);
pos+=rsmsg_len+2;
nhdr = tvb_get_ntohs(tvb, pos);
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_nhdr, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
for(i=0; i<nhdr; i++) {
guint8 hcd;
guint8 hid;
const gchar *hval;
guint16 hval_len, hname_len;
const gchar* hname = NULL;
int hpos = pos;
hcd = tvb_get_guint8(tvb, pos);
if (hcd == 0xA0) {
pos+=1;
hid = tvb_get_guint8(tvb, pos);
pos+=1;
if (hid >= array_length(rsp_headers))
hid = 0;
hval = ajp13_get_nstring(tvb, pos, &hval_len);
proto_tree_add_string_format_value(ajp13_tree, *rsp_headers[hid],
tvb, hpos, 2+hval_len+2, hval,
"%s", hval);
pos+=hval_len+2;
#if 0
if (hid == 0x08)
cl = 1;
#endif
} else {
hname = ajp13_get_nstring(tvb, pos, &hname_len);
pos+=hname_len+2;
hval = ajp13_get_nstring(tvb, pos, &hval_len);
proto_tree_add_string_format(ajp13_tree, hf_ajp13_additional_header,
tvb, hpos, hname_len+2+hval_len+2,
wmem_strdup_printf(wmem_packet_scope(), "%s: %s", hname, hval),
"%s: %s", hname, hval);
pos+=hval_len+2;
}
}
break;
}
case MTYPE_GET_BODY_CHUNK:
{
guint16 rlen;
rlen = tvb_get_ntohs(tvb, pos);
cd->content_length = rlen;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_rlen, tvb, pos, 2, ENC_BIG_ENDIAN);
break;
}
case MTYPE_CPONG:
break;
default:
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_data, tvb, pos+2, -1, ENC_UTF_8|ENC_NA);
break;
}
}
static void
display_req_body(tvbuff_t *tvb, proto_tree *ajp13_tree, ajp13_conv_data* cd)
{
guint16 content_length;
guint16 packet_length;
int pos = 0;
proto_tree_add_item(ajp13_tree, hf_ajp13_magic, tvb, pos, 2, ENC_NA);
pos+=2;
packet_length = tvb_get_ntohs(tvb, pos);
proto_tree_add_item(ajp13_tree, hf_ajp13_len, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
if (packet_length == 0)
{
cd->content_length = 0;
return;
}
content_length = tvb_get_ntohs( tvb, pos);
if (content_length == 0) {
cd->content_length = 0;
return;
}
cd->content_length -= content_length;
proto_tree_add_item(ajp13_tree, hf_ajp13_data, tvb, pos+2, content_length, ENC_UTF_8|ENC_NA);
}
static void
display_req_forward(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *ajp13_tree,
ajp13_conv_data* cd)
{
int pos = 0;
guint8 meth;
guint8 cod;
const gchar *ver;
guint16 ver_len;
const gchar *uri;
guint16 uri_len;
const gchar *raddr;
guint16 raddr_len;
const gchar *rhost;
guint16 rhost_len;
const gchar *srv;
guint16 srv_len;
guint nhdr;
guint i;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_magic, tvb, pos, 2, ENC_NA);
pos+=2;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_len, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
cod = tvb_get_guint8(tvb, 4);
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_code, tvb, pos, 1, ENC_BIG_ENDIAN);
pos+=1;
if ( cod == MTYPE_CPING ) {
col_append_str(pinfo->cinfo, COL_INFO, "CPING" );
return;
}
meth = tvb_get_guint8(tvb, pos);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(meth, http_method_codes, "Unknown method %u"));
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_method, tvb, pos, 1, ENC_BIG_ENDIAN);
pos+=1;
ver = ajp13_get_nstring(tvb, pos, &ver_len);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_ver, tvb, pos, ver_len+2, ver);
pos=pos+ver_len+2;
uri = ajp13_get_nstring(tvb, pos, &uri_len);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_uri, tvb, pos, uri_len+2, uri);
pos=pos+uri_len+2;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s %s", uri, ver);
raddr = ajp13_get_nstring(tvb, pos, &raddr_len);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_raddr, tvb, pos, raddr_len+2, raddr);
pos=pos+raddr_len+2;
rhost = ajp13_get_nstring(tvb, pos, &rhost_len);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_rhost, tvb, pos, rhost_len+2, rhost);
pos=pos+rhost_len+2;
srv = ajp13_get_nstring(tvb, pos, &srv_len);
if (ajp13_tree)
proto_tree_add_string(ajp13_tree, hf_ajp13_srv, tvb, pos, srv_len+2, srv);
pos=pos+srv_len+2;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_port, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_sslp, tvb, pos, 1, ENC_NA);
pos+=1;
nhdr = tvb_get_ntohs(tvb, pos);
if (ajp13_tree)
proto_tree_add_item(ajp13_tree, hf_ajp13_nhdr, tvb, pos, 2, ENC_BIG_ENDIAN);
pos+=2;
cd->content_length = 0;
for(i=0; i<nhdr; i++) {
guint8 hcd;
guint8 hid;
const gchar* hname = NULL;
int hpos = pos;
int cl = 0;
const gchar *hval;
guint16 hval_len, hname_len;
hcd = tvb_get_guint8(tvb, pos);
if (hcd == 0xA0) {
pos+=1;
hid = tvb_get_guint8(tvb, pos);
pos+=1;
if (hid >= array_length(req_headers))
hid = 0;
hval = ajp13_get_nstring(tvb, pos, &hval_len);
proto_tree_add_string_format(ajp13_tree, *req_headers[hid],
tvb, hpos, 2+hval_len+2, hval,
"%s", hval);
pos+=hval_len+2;
if (hid == 0x08)
cl = 1;
} else {
hname = ajp13_get_nstring(tvb, pos, &hname_len);
pos+=hname_len+2;
hval = ajp13_get_nstring(tvb, pos, &hval_len);
proto_tree_add_string_format(ajp13_tree, hf_ajp13_additional_header,
tvb, hpos, hname_len+2+hval_len+2,
wmem_strdup_printf(wmem_packet_scope(), "%s: %s", hname, hval),
"%s: %s", hname, hval);
pos+=hval_len+2;
}
if (cl) {
cl = atoi(hval);
cd->content_length = cl;
}
}
while(tvb_reported_length_remaining(tvb, pos) > 0) {
guint8 aid;
const gchar* aname = NULL;
const gchar* aval;
guint16 aval_len, aname_len;
int apos = pos;
aid = tvb_get_guint8(tvb, pos);
pos+=1;
if (aid == 0xFF) {
break;
}
if (aid == 0x0A) {
aname = ajp13_get_nstring(tvb, pos, &aname_len);
pos+=aname_len+2;
aval = ajp13_get_nstring(tvb, pos, &aval_len);
pos+=aval_len+2;
proto_tree_add_string_format(ajp13_tree, hf_ajp13_req_attribute,
tvb, apos, 1+aname_len+2+aval_len+2,
wmem_strdup_printf(wmem_packet_scope(), "%s: %s", aname, aval),
"%s: %s", aname, aval);
} else if (aid == 0x0B ) {
if (ajp13_tree) {
proto_tree_add_uint(ajp13_tree, hf_ajp13_ssl_key_size,
tvb, apos, 1+2, tvb_get_ntohs(tvb, pos));
}
pos+=2;
} else {
if (aid >= array_length(req_attributes))
aid = 0;
aval = ajp13_get_nstring(tvb, pos, &aval_len);
pos+=aval_len+2;
proto_tree_add_string_format(ajp13_tree, *req_attributes[aid],
tvb, apos, 1+aval_len+2, aval,
"%s", aval);
}
}
}
static int
dissect_ajp13_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint16 mag;
conversation_t *conv = NULL;
ajp13_conv_data *cd = NULL;
proto_tree *ajp13_tree = NULL;
ajp13_frame_data* fd = NULL;
conv = find_or_create_conversation(pinfo);
cd = (ajp13_conv_data*)conversation_get_proto_data(conv, proto_ajp13);
if (!cd) {
cd = wmem_new(wmem_file_scope(), ajp13_conv_data);
cd->content_length = 0;
cd->was_get_body_chunk = FALSE;
conversation_add_proto_data(conv, proto_ajp13, cd);
}
fd = (ajp13_frame_data*)p_get_proto_data(wmem_file_scope(), pinfo, proto_ajp13, 0);
if (!fd) {
fd = wmem_new(wmem_file_scope(), ajp13_frame_data);
p_add_proto_data(wmem_file_scope(), pinfo, proto_ajp13, 0, fd);
fd->is_request_body = FALSE;
if (cd->content_length) {
fd->is_request_body = TRUE;
}
}
col_clear(pinfo->cinfo, COL_INFO);
mag = tvb_get_ntohs(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AJP13");
if (mag == 0x1234 && !fd->is_request_body)
col_append_fstr(pinfo->cinfo, COL_INFO, "%d:REQ:", conv->index);
else if (mag == 0x1234 && fd->is_request_body)
col_append_fstr(pinfo->cinfo, COL_INFO, "%d:REQ:Body", conv->index);
else if (mag == 0x4142)
col_append_fstr(pinfo->cinfo, COL_INFO, "%d:RSP:", conv->index);
else
col_set_str(pinfo->cinfo, COL_INFO, "AJP13 Error?");
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_ajp13, tvb, 0, -1, ENC_NA);
ajp13_tree = proto_item_add_subtree(ti, ett_ajp13);
}
if (mag == 0x1234) {
if (fd->is_request_body)
display_req_body(tvb, ajp13_tree, cd);
else
display_req_forward(tvb, pinfo, ajp13_tree, cd);
} else if (mag == 0x4142) {
display_rsp(tvb, pinfo, ajp13_tree, cd);
}
return tvb_reported_length(tvb);
}
static guint
get_ajp13_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset+2);
plen += 4;
return plen;
}
static int
dissect_ajp13(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree,
TRUE,
4,
get_ajp13_pdu_len,
dissect_ajp13_tcp_pdu, data);
return tvb_reported_length(tvb);
}
void
proto_register_ajp13(void)
{
static hf_register_info hf[] = {
{ &hf_ajp13_magic,
{ "Magic", "ajp13.magic", FT_BYTES, BASE_NONE, NULL, 0x0, "Magic Number",
HFILL }
},
{ &hf_ajp13_len,
{ "Length", "ajp13.len", FT_UINT16, BASE_DEC, NULL, 0x0, "Data Length",
HFILL }
},
{ &hf_ajp13_code,
{ "Code", "ajp13.code", FT_UINT32, BASE_DEC, VALS(mtype_codes), 0x0, "Type Code",
HFILL }
},
{ &hf_ajp13_method,
{ "Method", "ajp13.method", FT_UINT8, BASE_DEC, VALS(http_method_codes), 0x0, "HTTP Method",
HFILL }
},
{ &hf_ajp13_ver,
{ "Version", "ajp13.ver", FT_STRING, BASE_NONE, NULL, 0x0, "HTTP Version",
HFILL }
},
{ &hf_ajp13_uri,
{ "URI", "ajp13.uri", FT_STRING, BASE_NONE, NULL, 0x0, "HTTP URI",
HFILL }
},
{ &hf_ajp13_raddr,
{ "RADDR", "ajp13.raddr", FT_STRING, BASE_NONE, NULL, 0x0, "Remote Address",
HFILL }
},
{ &hf_ajp13_rhost,
{ "RHOST", "ajp13.rhost", FT_STRING, BASE_NONE, NULL, 0x0, "Remote Host",
HFILL }
},
{ &hf_ajp13_srv,
{ "SRV", "ajp13.srv", FT_STRING, BASE_NONE, NULL, 0x0, "Server",
HFILL }
},
{ &hf_ajp13_port,
{ "PORT", "ajp13.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL }
},
{ &hf_ajp13_sslp,
{ "SSLP", "ajp13.sslp", FT_BOOLEAN, BASE_NONE, NULL, 0x0, "Is SSL?",
HFILL }
},
{ &hf_ajp13_nhdr,
{ "NHDR", "ajp13.nhdr", FT_UINT16, BASE_DEC, NULL, 0x0, "Num Headers",
HFILL }
},
{ &hf_ajp13_unknown_header,
{ "unknown_header", "ajp13.unknown_header", FT_STRING, BASE_NONE, NULL, 0x0, "Unknown Header Type",
HFILL }
},
{ &hf_ajp13_additional_header,
{ "additional_header", "ajp13.additional_header", FT_STRING, BASE_NONE, NULL, 0x0, "Additional Header Type",
HFILL }
},
{ &hf_ajp13_content_type,
{ "Content-Type", "ajp13.content_type", FT_STRING, BASE_NONE, NULL, 0x0, "Content-Type Header",
HFILL }
},
{ &hf_ajp13_content_language,
{ "Content-Language", "ajp13.content_language", FT_STRING, BASE_NONE, NULL, 0x0, "Content-Language Header",
HFILL }
},
{ &hf_ajp13_content_length,
{ "Content-Length", "ajp13.content_length", FT_STRING, BASE_NONE, NULL, 0x0, "Content-Length header",
HFILL }
},
{ &hf_ajp13_date,
{ "Date", "ajp13.date", FT_STRING, BASE_NONE, NULL, 0x0, "Date Header",
HFILL }
},
{ &hf_ajp13_last_modified,
{ "Last-Modified", "ajp13.last_modified", FT_STRING, BASE_NONE, NULL, 0x0, "Last Modified Header",
HFILL }
},
{ &hf_ajp13_location,
{ "Location", "ajp13.location", FT_STRING, BASE_NONE, NULL, 0x0, "Location Header",
HFILL }
},
{ &hf_ajp13_set_cookie,
{ "Set-Cookie", "ajp13.set_cookie", FT_STRING, BASE_NONE, NULL, 0x0, "Set-Cookie Header",
HFILL }
},
{ &hf_ajp13_set_cookie2,
{ "Set-Cookie2", "ajp13.set_cookie2", FT_STRING, BASE_NONE, NULL, 0x0, "Set-Cookie2 Header",
HFILL }
},
{ &hf_ajp13_servlet_engine,
{ "Servlet-Engine", "ajp13.servlet_engine", FT_STRING, BASE_NONE, NULL, 0x0, "Servlet-Engine Header",
HFILL }
},
{ &hf_ajp13_status,
{ "Status", "ajp13.status", FT_STRING, BASE_NONE, NULL, 0x0, "Status Header",
HFILL }
},
{ &hf_ajp13_www_authenticate,
{ "WWW-Authenticate", "ajp13.www_authenticate", FT_STRING, BASE_NONE, NULL, 0x0, "WWW-Authenticate Header",
HFILL }
},
{ &hf_ajp13_accept,
{ "Accept", "ajp13.accept", FT_STRING, BASE_NONE, NULL, 0x0, "Accept Header",
HFILL }
},
{ &hf_ajp13_accept_charset,
{ "Accept-Charset", "ajp13.accept_charset", FT_STRING, BASE_NONE, NULL, 0x0, "Accept-Charset Header",
HFILL }
},
{ &hf_ajp13_accept_encoding,
{ "Accept-Encoding", "ajp13.accept_encoding", FT_STRING, BASE_NONE, NULL, 0x0, "Accept-Encoding Header",
HFILL }
},
{ &hf_ajp13_accept_language,
{ "Accept-Language", "ajp13.accept_language", FT_STRING, BASE_NONE, NULL, 0x0, "Accept-Language Header",
HFILL }
},
{ &hf_ajp13_authorization,
{ "Authorization", "ajp13.authorization", FT_STRING, BASE_NONE, NULL, 0x0, "Authorization Header",
HFILL }
},
{ &hf_ajp13_connection,
{ "Connection", "ajp13.connection", FT_STRING, BASE_NONE, NULL, 0x0, "Connection Header",
HFILL }
},
{ &hf_ajp13_cookie,
{ "Cookie", "ajp13.cookie", FT_STRING, BASE_NONE, NULL, 0x0, "Cookie Header",
HFILL }
},
{ &hf_ajp13_cookie2,
{ "Cookie2", "ajp13.cookie2", FT_STRING, BASE_NONE, NULL, 0x0, "Cookie2 Header",
HFILL }
},
{ &hf_ajp13_host,
{ "Host", "ajp13.host", FT_STRING, BASE_NONE, NULL, 0x0, "Host Header",
HFILL }
},
{ &hf_ajp13_pragma,
{ "Pragma", "ajp13.pragma", FT_STRING, BASE_NONE, NULL, 0x0, "Pragma Header",
HFILL }
},
{ &hf_ajp13_referer,
{ "Referer", "ajp13.referer", FT_STRING, BASE_NONE, NULL, 0x0, "Referer Header",
HFILL }
},
{ &hf_ajp13_user_agent,
{ "User-Agent", "ajp13.user_agent", FT_STRING, BASE_NONE, NULL, 0x0, "User-Agent Header",
HFILL }
},
{ &hf_ajp13_unknown_attribute,
{ "unknown_attribute", "ajp13.unknown_attribute", FT_STRING, BASE_NONE, NULL, 0x0, "Unknown Attribute Type",
HFILL }
},
{ &hf_ajp13_req_attribute,
{ "req_attribute", "ajp13.req_attribute", FT_STRING, BASE_NONE, NULL, 0x0, "Additional Attribute Type",
HFILL }
},
{ &hf_ajp13_context,
{ "Context", "ajp13.context", FT_STRING, BASE_NONE, NULL, 0x0, "Context Attribute",
HFILL }
},
{ &hf_ajp13_servlet_path,
{ "Servlet-Path", "ajp13.servlet_path", FT_STRING, BASE_NONE, NULL, 0x0, "Servlet-Path Attribute",
HFILL }
},
{ &hf_ajp13_remote_user,
{ "Remote-User", "ajp13.remote_user", FT_STRING, BASE_NONE, NULL, 0x0, "Remote-User Attribute",
HFILL }
},
{ &hf_ajp13_auth_type,
{ "Auth-Type", "ajp13.auth_type", FT_STRING, BASE_NONE, NULL, 0x0, "Auth-Type Attribute",
HFILL }
},
{ &hf_ajp13_query_string,
{ "Query-String", "ajp13.query_string", FT_STRING, BASE_NONE, NULL, 0x0, "Query-String Attribute",
HFILL }
},
{ &hf_ajp13_route,
{ "Route", "ajp13.route", FT_STRING, BASE_NONE, NULL, 0x0, "Route Attribute",
HFILL }
},
{ &hf_ajp13_ssl_cert,
{ "SSL-Cert", "ajp13.ssl_cert", FT_STRING, BASE_NONE, NULL, 0x0, "SSL-Cert Attribute",
HFILL }
},
{ &hf_ajp13_ssl_cipher,
{ "SSL-Cipher", "ajp13.ssl_cipher", FT_STRING, BASE_NONE, NULL, 0x0, "SSL-Cipher Attribute",
HFILL }
},
{ &hf_ajp13_ssl_session,
{ "SSL-Session", "ajp13.ssl_session", FT_STRING, BASE_NONE, NULL, 0x0, "SSL-Session Attribute",
HFILL }
},
{ &hf_ajp13_ssl_key_size,
{ "SSL-Key-Size", "ajp13.ssl_key_size", FT_UINT16, BASE_DEC, NULL, 0x0, "SSL-Key-Size Attribute",
HFILL }
},
{ &hf_ajp13_secret,
{ "Secret", "ajp13.secret", FT_STRING, BASE_NONE, NULL, 0x0, "Secret Attribute",
HFILL }
},
{ &hf_ajp13_stored_method,
{ "Stored-Method", "ajp13.stored_method", FT_STRING, BASE_NONE, NULL, 0x0, "Stored-Method Attribute",
HFILL }
},
{ &hf_ajp13_rlen,
{ "RLEN", "ajp13.rlen", FT_UINT16, BASE_DEC, NULL, 0x0, "Requested Length",
HFILL }
},
{ &hf_ajp13_reusep,
{ "REUSEP", "ajp13.reusep", FT_UINT8, BASE_DEC, NULL, 0x0, "Reuse Connection?",
HFILL }
},
{ &hf_ajp13_rstatus,
{ "RSTATUS", "ajp13.rstatus", FT_UINT16, BASE_DEC, NULL, 0x0, "HTTP Status Code",
HFILL }
},
{ &hf_ajp13_rsmsg,
{ "RSMSG", "ajp13.rmsg", FT_STRING, BASE_NONE, NULL, 0x0, "HTTP Status Message",
HFILL }
},
{ &hf_ajp13_data,
{ "Data", "ajp13.data", FT_STRING, BASE_NONE, NULL, 0x0, NULL,
HFILL }
},
};
static gint *ett[] = {
&ett_ajp13,
};
proto_ajp13 = proto_register_protocol("Apache JServ Protocol v1.3", "AJP13", "ajp13");
proto_register_field_array(proto_ajp13, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_ajp13(void)
{
dissector_handle_t ajp13_handle;
ajp13_handle = new_create_dissector_handle(dissect_ajp13, proto_ajp13);
dissector_add_uint("tcp.port", 8009, ajp13_handle);
}
