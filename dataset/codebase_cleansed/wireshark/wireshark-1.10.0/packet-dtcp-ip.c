static gboolean
dtcp_ip_check_packet(tvbuff_t *tvb)
{
guint offset = 0;
guint8 type;
guint16 length;
if (tvb_reported_length(tvb) < 1+2+CTRL_LEN)
return FALSE;
type = tvb_get_guint8(tvb, offset);
if (type != 1)
return FALSE;
offset++;
length = tvb_get_ntohs(tvb, offset);
if (length < CTRL_LEN)
return FALSE;
return TRUE;
}
static int
dissect_dtcp_ip(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
guint offset = 0;
guint16 length;
proto_item *pi, *pi_ctrl;
proto_tree *dtcp_ip_tree = NULL, *dtcp_ip_ctrl_tree = NULL;
guint8 subfct_val;
const gchar *subfct_str;
gint ake_info_len;
if (!dtcp_ip_check_packet(tvb))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTCP-IP");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_protocol_format(tree, proto_dtcp_ip,
tvb, 0, -1, "DTCP-IP");
dtcp_ip_tree = proto_item_add_subtree(pi, ett_dtcp_ip);
proto_tree_add_item(dtcp_ip_tree, hf_dtcp_ip_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_get_ntohs(tvb, 1);
proto_item_set_len(pi, 1+2+length);
proto_tree_add_item(dtcp_ip_tree, hf_dtcp_ip_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
pi_ctrl = proto_tree_add_text(dtcp_ip_tree,
tvb, offset, CTRL_LEN, "Control");
dtcp_ip_ctrl_tree = proto_item_add_subtree(pi_ctrl, ett_dtcp_ip_ctrl);
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_ctype,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_category,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_ake_id,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
subfct_val = tvb_get_guint8(tvb, offset);
subfct_str = val_to_str_const(subfct_val, subfct, "unknown");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"%s (0x%x)", subfct_str, subfct_val);
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_subfct,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask(dtcp_ip_ctrl_tree, tvb, offset,
hf_dtcp_ip_ake_procedure, ett_dtcp_ip_ake_procedure,
ake_procedure_fields, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_ake_xchg_key,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_subfct_dep,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_ake_label,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_number,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dtcp_ip_ctrl_tree, hf_dtcp_ip_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ake_info_len = length-CTRL_LEN;
if (ake_info_len > 0) {
proto_tree_add_item(dtcp_ip_tree, hf_dtcp_ip_ake_info,
tvb, offset, ake_info_len, ENC_NA);
offset += (guint)ake_info_len;
}
return offset;
}
void
proto_register_dtcp_ip(void)
{
static hf_register_info hf[] = {
{ &hf_dtcp_ip_type,
{ "Type", "dtcp-ip.type", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_dtcp_ip_length,
{ "Length", "dtcp-ip.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL } },
{ &hf_dtcp_ip_ctype,
{ "ctype/response", "dtcp-ip.ctrl.ctype_response", FT_UINT8,
BASE_HEX, NULL, 0x0F, NULL, HFILL } },
{ &hf_dtcp_ip_category,
{ "Category", "dtcp-ip.ctrl.category", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL } },
{ &hf_dtcp_ip_ake_id,
{ "AKE_ID", "dtcp-ip.ctrl.ake_id", FT_UINT8, BASE_HEX,
NULL, 0x0F, NULL, HFILL } },
{ &hf_dtcp_ip_subfct,
{ "Subfunction", "dtcp-ip.ctrl.subfunction", FT_UINT8, BASE_HEX,
VALS(subfct), 0, NULL, HFILL } },
{ &hf_dtcp_ip_ake_procedure,
{ "AKE_procedure", "dtcp-ip.ctrl.ake_procedure", FT_UINT8,
BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dtcp_ip_ake_proc_full,
{ "Full Authentication procedure",
"dtcp-ip.ctrl.ake_procedure.full_auth", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL } },
{ &hf_dtcp_ip_ake_proc_ex_full,
{ "Extended Full Authentication procedure",
"dtcp-ip.ctrl.ake_procedure.ex_full_auth", FT_BOOLEAN, 8,
NULL, 0x08, NULL, HFILL } },
{ &hf_dtcp_ip_ake_xchg_key,
{ "exchange_key", "dtcp-ip.ctrl.exchange_key", FT_UINT8, BASE_HEX,
VALS(xchg_key), 0, NULL, HFILL } },
{ &hf_dtcp_ip_subfct_dep,
{ "subfunction_dependent", "dtcp-ip.ctrl.subfunction_dependent",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dtcp_ip_ake_label,
{ "AKE_label", "dtcp-ip.ctrl.ake_label", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_dtcp_ip_number,
{ "number", "dtcp-ip.ctrl.number", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL } },
{ &hf_dtcp_ip_status,
{ "Status", "dtcp-ip.ctrl.status", FT_UINT8, BASE_HEX,
VALS(ctrl_status), 0x0F, NULL, HFILL } },
{ &hf_dtcp_ip_ake_info,
{ "AKE_Info", "dtcp-ip.ake_info", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_dtcp_ip,
&ett_dtcp_ip_ctrl,
&ett_dtcp_ip_ake_procedure
};
module_t *dtcp_ip_module;
proto_dtcp_ip = proto_register_protocol(
"Digital Transmission Content Protection over IP",
"DTCP-IP", "dtcp-ip");
proto_register_field_array(proto_dtcp_ip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dtcp_ip_module = prefs_register_protocol(
proto_dtcp_ip, proto_reg_handoff_dtcp_ip);
prefs_register_uint_preference(dtcp_ip_module, "tcp.port",
"TCP port", "TCP port number for DTCP-IP", 10, &pref_tcp_port);
}
void
proto_reg_handoff_dtcp_ip(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t dtcp_ip_handle = NULL;
static guint current_tcp_port = 0;
if (!initialized) {
dtcp_ip_handle =
new_create_dissector_handle(dissect_dtcp_ip, proto_dtcp_ip);
initialized = TRUE;
}
else
dissector_delete_uint("tcp.port", current_tcp_port, dtcp_ip_handle);
current_tcp_port = pref_tcp_port;
dissector_add_uint("tcp.port", current_tcp_port, dtcp_ip_handle);
}
