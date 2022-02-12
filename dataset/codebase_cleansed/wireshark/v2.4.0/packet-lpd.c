static int
dissect_lpd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *lpd_tree;
proto_item *ti, *hidden_item;
enum lpr_type lpr_packet_type;
guint8 code;
gint printer_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LPD");
col_clear(pinfo->cinfo, COL_INFO);
code = tvb_get_guint8(tvb, 0);
if (tvb_reported_length(tvb) == 1) {
lpr_packet_type = response;
}
else if (code <= 9) {
lpr_packet_type = request;
}
else {
lpr_packet_type = unknown;
}
if (lpr_packet_type == request && code !=0) {
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(code, lpd_client_code, "Unknown client code: %u"));
}
else if (lpr_packet_type == response) {
col_set_str(pinfo->cinfo, COL_INFO, "LPD response");
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "LPD continuation");
}
ti = proto_tree_add_item(tree, proto_lpd, tvb, 0, -1, ENC_NA);
lpd_tree = proto_item_add_subtree(ti, ett_lpd);
if (lpr_packet_type == response) {
hidden_item = proto_tree_add_boolean(lpd_tree, hf_lpd_response,
tvb, 0, 0, TRUE);
} else {
hidden_item = proto_tree_add_boolean(lpd_tree, hf_lpd_request,
tvb, 0, 0, TRUE);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
if (lpr_packet_type == request) {
printer_len = find_printer_string(tvb, 1);
if (code <= 9 && printer_len != -1) {
proto_tree_add_uint_format(lpd_tree, hf_lpd_client_code, tvb, 0, 1, code,
"%s", val_to_str(code, lpd_client_code, "Unknown client code: %u"));
proto_tree_add_item(lpd_tree, hf_lpd_printer_option, tvb, 1, printer_len, ENC_ASCII|ENC_NA);
}
else {
call_data_dissector(tvb, pinfo, lpd_tree);
}
}
else if (lpr_packet_type == response) {
if (code <= 3) {
proto_tree_add_item(lpd_tree, hf_lpd_response_code, tvb, 0, 1, ENC_BIG_ENDIAN);
}
else {
call_data_dissector(tvb, pinfo, lpd_tree);
}
}
else {
call_data_dissector(tvb, pinfo, lpd_tree);
}
return tvb_captured_length(tvb);
}
static gint
find_printer_string(tvbuff_t *tvb, int offset)
{
int i;
i = tvb_find_guint8(tvb, offset, -1, '\0');
if (i == -1)
i = tvb_find_guint8(tvb, offset, -1, '\n');
if (i == -1)
return -1;
return i - offset;
}
void
proto_register_lpd(void)
{
static hf_register_info hf[] = {
{ &hf_lpd_response,
{ "Response", "lpd.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if LPD response", HFILL }},
{ &hf_lpd_request,
{ "Request", "lpd.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if LPD request", HFILL }},
{ &hf_lpd_client_code,
{ "Client code", "lpd.client_code",
FT_UINT8, BASE_DEC, VALS(lpd_client_code), 0x0,
NULL, HFILL }},
{ &hf_lpd_printer_option,
{ "Printer/options", "lpd.printer_option",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lpd_response_code,
{ "Response", "lpd.response_code",
FT_UINT8, BASE_DEC, VALS(lpd_server_code), 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_lpd,
};
proto_lpd = proto_register_protocol("Line Printer Daemon Protocol", "LPD", "lpd");
proto_register_field_array(proto_lpd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lpd(void)
{
dissector_handle_t lpd_handle;
lpd_handle = create_dissector_handle(dissect_lpd, proto_lpd);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_PRINTER, lpd_handle);
}
