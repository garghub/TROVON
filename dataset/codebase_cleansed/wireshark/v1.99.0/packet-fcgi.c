static void
dissect_nv_pairs(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
gint end_offset = offset + len;
while (offset < end_offset) {
gint start_offset = offset;
guint32 namelen;
guint32 valuelen;
char *name;
char *value;
namelen = tvb_get_guint8(tvb, offset);
if ((namelen & 0x80) == 0) {
offset += 1;
} else {
namelen = tvb_get_ntohl(tvb, offset) & 0x7FFFFFFF;
offset += 4;
}
valuelen = tvb_get_guint8(tvb, offset);
if ((valuelen & 0x80) == 0) {
offset += 1;
} else {
valuelen = tvb_get_ntohl(tvb, offset) & 0x7FFFFFFF;
offset += 4;
}
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, namelen, ENC_ASCII);
offset += namelen;
if (valuelen > 0) {
value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, valuelen, ENC_ASCII);
offset += valuelen;
proto_tree_add_string_format(fcgi_tree, hf_fcgi_nv_name, tvb, start_offset, offset - start_offset,
name, "%s = %s", name, value);
} else {
proto_tree_add_string_format(fcgi_tree, hf_fcgi_nv_name, tvb, start_offset, offset - start_offset,
name, "%s", name);
}
}
}
static int
dissect_begin_request(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree *br_tree;
br_tree = proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_begin_request, NULL, "Begin Request:");
proto_tree_add_item(br_tree, hf_fcgi_begin_request_role, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(br_tree, hf_fcgi_begin_request_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(br_tree, hf_fcgi_begin_request_keep_conn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 5;
return offset;
}
static void
dissect_abort_request(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_abort_request, NULL, "Abort Request:");
return;
}
static int
dissect_end_request(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree *er_tree;
er_tree = proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_end_request, NULL, "End Request:");
proto_tree_add_item(er_tree, hf_fcgi_end_request_app_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(er_tree, hf_fcgi_end_request_protocol_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 3;
return offset;
}
static void
dissect_params(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree *p_tree;
p_tree = proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_params, NULL, "Params:");
dissect_nv_pairs(tvb, p_tree, offset, len);
return;
}
static void
dissect_get_values(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree *gv_tree;
gv_tree = proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_params, NULL, "Get Values:");
dissect_nv_pairs(tvb, gv_tree, offset, len);
return;
}
static void
dissect_get_values_result(tvbuff_t *tvb, proto_tree *fcgi_tree, gint offset, guint16 len)
{
proto_tree *gvr_tree;
gvr_tree = proto_tree_add_subtree(fcgi_tree, tvb, offset, len, ett_fcgi_params, NULL, "Get Values:");
dissect_nv_pairs(tvb, gvr_tree, offset, len);
return;
}
static int
dissect_fcgi_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
guint8 type;
type = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FCGI");
col_clear(pinfo->cinfo, COL_INFO);
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL,
val_to_str(type, record_types, "Unknown (%u)"));
col_set_fence(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item *ti;
proto_tree *fcgi_tree;
guint16 clen;
guint8 plen;
ti = proto_tree_add_item(tree, proto_fcgi, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " (%s)",
val_to_str(type, record_types, "Unknown (%u)"));
fcgi_tree = proto_item_add_subtree(ti, ett_fcgi);
proto_tree_add_item(fcgi_tree, hf_fcgi_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fcgi_tree, hf_fcgi_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(fcgi_tree, hf_fcgi_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
clen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(fcgi_tree, hf_fcgi_content_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
plen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(fcgi_tree, hf_fcgi_padding_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 1;
switch (type)
{
case FCGI_BEGIN_REQUEST:
dissect_begin_request(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
case FCGI_ABORT_REQUEST:
dissect_abort_request(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
case FCGI_END_REQUEST:
dissect_end_request(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
case FCGI_PARAMS:
dissect_params(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
case FCGI_GET_VALUES:
dissect_get_values(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
case FCGI_GET_VALUES_RESULT:
dissect_get_values_result(tvb, fcgi_tree, offset, clen);
offset += clen;
break;
default:
if (clen > 0) {
proto_tree_add_item(fcgi_tree, hf_fcgi_content_data, tvb, offset, clen, ENC_NA);
offset += clen;
}
break;
}
if (plen > 0) {
proto_tree_add_item(fcgi_tree, hf_fcgi_padding_data, tvb, offset, plen, ENC_NA);
}
}
return tvb_length(tvb);
}
static guint
get_fcgi_record_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return 8 + tvb_get_ntohs(tvb, offset + 4) + tvb_get_guint8(tvb, offset + 6);
}
static int
dissect_fcgi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 8, get_fcgi_record_len, dissect_fcgi_record, data);
return tvb_length(tvb);
}
void
proto_register_fcgi(void)
{
static hf_register_info hf[] = {
{ &hf_fcgi_version,
{ "Version", "fcgi.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_type,
{ "Type", "fcgi.type",
FT_UINT8, BASE_DEC, VALS(record_types), 0x0, NULL, HFILL } },
{ &hf_fcgi_id,
{ "Request ID", "fcgi.id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_content_length,
{ "Content Length", "fcgi.content.length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_padding_length,
{ "Padding Length", "fcgi.padding.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_content_data,
{ "Content Data", "fcgi.content.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_padding_data,
{ "Padding Data", "fcgi.padding.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_begin_request_role,
{ "Role", "fcgi.begin_request.role",
FT_UINT16, BASE_DEC, VALS(application_roles), 0x0, NULL, HFILL } },
{ &hf_fcgi_begin_request_flags,
{ "Flags", "fcgi.begin_request.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_begin_request_keep_conn,
{ "FCGI_KEEP_CONN", "fcgi.begin_request.keep_conn",
FT_BOOLEAN, 8, NULL, FCGI_KEEP_CONN, NULL, HFILL } },
{ &hf_fcgi_end_request_app_status,
{ "Application Status", "fcgi.end_request.app_status",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_fcgi_end_request_protocol_status,
{ "Protocol Status", "fcgi.end_request.protocol_status",
FT_UINT32, BASE_DEC, VALS(protocol_statuses), 0x0, NULL, HFILL } },
{ &hf_fcgi_nv_name,
{ "NV Pair name", "fcgi.nv_name",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_fcgi,
&ett_fcgi_begin_request,
&ett_fcgi_abort_request,
&ett_fcgi_end_request,
&ett_fcgi_params
};
module_t *fcgi_module;
proto_fcgi = proto_register_protocol("FastCGI", "FCGI", "fcgi");
proto_register_field_array(proto_fcgi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fcgi_module = prefs_register_protocol(proto_fcgi, proto_reg_handoff_fcgi);
prefs_register_uint_preference(fcgi_module,
"tcp.port",
"TCP port for FCGI",
"Set the TCP port for FastCGI traffic",
10,
&tcp_port);
fcgi_handle = new_register_dissector("fcgi", dissect_fcgi, proto_fcgi);
}
void
proto_reg_handoff_fcgi(void)
{
static gboolean initialized = FALSE;
static guint saved_tcp_port;
if (!initialized) {
dissector_add_for_decode_as("tcp.port", fcgi_handle);
initialized = TRUE;
} else if (saved_tcp_port != 0) {
dissector_delete_uint("tcp.port", saved_tcp_port, fcgi_handle);
}
if (tcp_port != 0) {
dissector_add_uint("tcp.port", tcp_port, fcgi_handle);
}
saved_tcp_port = tcp_port;
}
