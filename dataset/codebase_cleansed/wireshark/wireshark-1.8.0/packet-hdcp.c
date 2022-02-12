gboolean
sub_check_hdcp(packet_info *pinfo _U_)
{
return TRUE;
}
static void
hdcp_init(void)
{
transactions = se_tree_create_non_persistent(
EMEM_TREE_TYPE_RED_BLACK, "hdcp_transactions");
}
static int
dissect_hdcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 addr, reg;
proto_item *pi;
ptvcursor_t *cursor;
proto_tree *hdcp_tree = NULL;
hdcp_transaction_t *hdcp_trans;
proto_item *it;
guint64 a_ksv, b_ksv;
addr = tvb_get_guint8(tvb, 0);
if (!HDCP_ADDR8(addr))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HDCP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
pi = proto_tree_add_protocol_format(tree, proto_hdcp,
tvb, 0, tvb_reported_length(tvb), "HDCP");
hdcp_tree = proto_item_add_subtree(pi, ett_hdcp);
}
cursor = ptvcursor_new(hdcp_tree, tvb, 0);
ptvcursor_add(cursor, hf_hdcp_addr, 1, ENC_LITTLE_ENDIAN);
if (addr==ADDR8_HDCP_WRITE) {
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(ADDR8_TRX)+1, ADDR8_TRX);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(ADDR8_RCV)+1, ADDR8_RCV);
reg = tvb_get_guint8(tvb, ptvcursor_current_offset(cursor));
ptvcursor_add(cursor, hf_hdcp_reg, 1, ENC_LITTLE_ENDIAN);
if (tvb_reported_length_remaining(tvb,
ptvcursor_current_offset(cursor)) == 0) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "request %s",
val_to_str(reg, hdcp_reg, "unknown (0x%x)"));
if (PINFO_FD_VISITED(pinfo)) {
hdcp_trans = (hdcp_transaction_t *)se_tree_lookup32(
transactions, PINFO_FD_NUM(pinfo));
if (hdcp_trans && hdcp_trans->rqst_frame==PINFO_FD_NUM(pinfo) &&
hdcp_trans->resp_frame!=0) {
it = proto_tree_add_uint_format(hdcp_tree, hf_hdcp_resp_in,
NULL, 0, 0, hdcp_trans->resp_frame,
"Request to get the content of register %s, "
"response in frame %d",
val_to_str_const(hdcp_trans->rqst_type,
hdcp_reg, "unknown (0x%x)"),
hdcp_trans->resp_frame);
PROTO_ITEM_SET_GENERATED(it);
}
}
else {
if (transactions) {
hdcp_trans = (hdcp_transaction_t *)se_alloc(
sizeof(hdcp_transaction_t));
hdcp_trans->rqst_frame = PINFO_FD_NUM(pinfo);
hdcp_trans->resp_frame = 0;
hdcp_trans->rqst_type = reg;
se_tree_insert32(transactions,
hdcp_trans->rqst_frame, (void *)hdcp_trans);
}
}
}
else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "send %s",
val_to_str(reg, hdcp_reg, "unknown (0x%x)"));
switch (reg) {
case REG_AKSV:
a_ksv = tvb_get_letoh40(tvb,
ptvcursor_current_offset(cursor));
proto_tree_add_uint64_format(hdcp_tree, hf_hdcp_a_ksv,
tvb, ptvcursor_current_offset(cursor), 5,
a_ksv, "A_ksv 0x%010" G_GINT64_MODIFIER "x", a_ksv);
ptvcursor_advance(cursor, 5);
break;
case REG_AN:
ptvcursor_add(cursor, hf_hdcp_an, 8, ENC_LITTLE_ENDIAN);
break;
default:
break;
}
}
}
else {
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(ADDR8_RCV)+1, ADDR8_RCV);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(ADDR8_TRX)+1, ADDR8_TRX);
if (transactions) {
hdcp_trans = (hdcp_transaction_t *)se_tree_lookup32_le(
transactions, PINFO_FD_NUM(pinfo));
if (hdcp_trans) {
if (hdcp_trans->resp_frame==0) {
hdcp_trans->resp_frame = PINFO_FD_NUM(pinfo);
}
if (hdcp_trans->resp_frame== PINFO_FD_NUM(pinfo)) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "send %s",
val_to_str_const(hdcp_trans->rqst_type,
hdcp_reg, "unknown (0x%x)"));
it = proto_tree_add_uint_format(hdcp_tree, hf_hdcp_resp_to,
NULL, 0, 0, hdcp_trans->rqst_frame,
"Response to frame %d (content of register %s)",
hdcp_trans->rqst_frame,
val_to_str_const(hdcp_trans->rqst_type,
hdcp_reg, "unknown (0x%x)"));
PROTO_ITEM_SET_GENERATED(it);
switch (hdcp_trans->rqst_type) {
case REG_BKSV:
b_ksv = tvb_get_letoh40(tvb,
ptvcursor_current_offset(cursor));
proto_tree_add_uint64_format(hdcp_tree, hf_hdcp_b_ksv,
tvb, ptvcursor_current_offset(cursor), 5,
b_ksv, "B_ksv 0x%010" G_GINT64_MODIFIER "x",
b_ksv);
ptvcursor_advance(cursor, 5);
break;
case REG_BCAPS:
ptvcursor_add_no_advance(cursor,
hf_hdcp_hdmi_reserved, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_repeater, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_ksv_fifo, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_fast_trans, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_features, 1, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_fast_reauth, 1, ENC_LITTLE_ENDIAN);
break;
case REG_BSTATUS:
ptvcursor_add_no_advance(cursor,
hf_hdcp_hdmi_mode, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_max_casc_exc, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_depth, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_max_devs_exc, 2, ENC_LITTLE_ENDIAN);
ptvcursor_add_no_advance(cursor,
hf_hdcp_downstream, 2, ENC_LITTLE_ENDIAN);
break;
}
}
}
if (!hdcp_trans || hdcp_trans->resp_frame!=PINFO_FD_NUM(pinfo)) {
if (tvb_reported_length_remaining(
tvb, ptvcursor_current_offset(cursor)) == 2) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL,
"send link verification Ri'");
ptvcursor_add_no_advance(cursor,
hf_hdcp_link_vfy, 2, ENC_LITTLE_ENDIAN);
}
}
}
}
ptvcursor_free(cursor);
return tvb_reported_length(tvb);
}
static int
dissect_hdcp2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
msg_info_t *mi;
proto_item *pi;
proto_tree *hdcp_tree = NULL, *cert_tree = NULL;
guint8 msg_id;
gboolean repeater;
guint16 reserved;
ptvcursor_t *cursor;
msg_id = tvb_get_guint8(tvb, 0);
if (msg_id > ID_MAX)
return 0;
mi = (msg_info_t *)g_hash_table_lookup(msg_table,
GUINT_TO_POINTER((guint)msg_id));
if (!mi || mi->len!=tvb_reported_length_remaining(tvb, 1))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HDCP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
pi = proto_tree_add_protocol_format(tree, proto_hdcp,
tvb, 0, tvb_reported_length(tvb), "HDCPv2");
hdcp_tree = proto_item_add_subtree(pi, ett_hdcp);
}
cursor = ptvcursor_new(hdcp_tree, tvb, 0);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(msg_id, hdcp_msg_id, "unknown (0x%x)"));
ptvcursor_add(cursor, hf_hdcp2_msg_id, 1, ENC_BIG_ENDIAN);
switch (msg_id) {
case ID_AKE_INIT:
ptvcursor_add(cursor, hf_hdcp2_r_tx, 8, ENC_BIG_ENDIAN);
break;
case ID_AKE_SEND_CERT:
repeater = ((tvb_get_guint8(tvb, ptvcursor_current_offset(cursor))
& 0x01) == 0x01);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, NULL, "%s",
repeater ? "repeater" : "no repeater");
ptvcursor_add(cursor, hf_hdcp2_repeater, 1, ENC_BIG_ENDIAN);
if (hdcp_tree) {
cert_tree = ptvcursor_add_text_with_subtree(cursor, CERT_RX_LEN,
ett_hdcp_cert, "%s", "HDCP Certificate");
}
ptvcursor_add(cursor, hf_hdcp2_cert_rcv_id, RCV_ID_LEN, ENC_NA);
ptvcursor_add(cursor, hf_hdcp2_cert_n, N_LEN, ENC_NA);
ptvcursor_add(cursor, hf_hdcp2_cert_e, E_LEN, ENC_BIG_ENDIAN);
reserved = tvb_get_ntohs(tvb, ptvcursor_current_offset(cursor));
proto_tree_add_text(cert_tree, tvb,
ptvcursor_current_offset(cursor), 2, "reserved bytes");
if (reserved != 0) {
pi = proto_tree_add_text(cert_tree, tvb,
ptvcursor_current_offset(cursor), 2, "invalid value");
expert_add_info_format(pinfo, pi, PI_PROTOCOL, PI_WARN,
"reserved bytes must be set to 0x0");
}
ptvcursor_advance(cursor, 2);
ptvcursor_add(cursor, hf_hdcp2_cert_rcv_sig, RCV_SIG_LEN, ENC_NA);
if (cert_tree)
ptvcursor_pop_subtree(cursor);
break;
case ID_AKE_STORED_KM:
ptvcursor_add(cursor, hf_hdcp2_e_kh_km, 16, ENC_NA);
ptvcursor_add(cursor, hf_hdcp2_m, 16, ENC_NA);
break;
case ID_AKE_SEND_RRX:
ptvcursor_add(cursor, hf_hdcp2_r_rx, 8, ENC_BIG_ENDIAN);
break;
case ID_AKE_SEND_H_PRIME:
ptvcursor_add(cursor, hf_hdcp2_h_prime, 32, ENC_NA);
break;
case ID_LC_INIT:
ptvcursor_add(cursor, hf_hdcp2_r_n, 8, ENC_BIG_ENDIAN);
break;
case ID_LC_SEND_L_PRIME:
ptvcursor_add(cursor, hf_hdcp2_l_prime, 32, ENC_NA);
break;
case ID_SKE_SEND_EKS:
ptvcursor_add(cursor, hf_hdcp2_e_dkey_ks, 16, ENC_NA);
ptvcursor_add(cursor, hf_hdcp2_r_iv, 8, ENC_BIG_ENDIAN);
break;
default:
break;
}
ptvcursor_free(cursor);
return tvb_reported_length(tvb);
}
void
proto_register_hdcp(void)
{
guint i;
static hf_register_info hf[] = {
{ &hf_hdcp_addr,
{ "8bit I2C address", "hdcp.addr", FT_UINT8, BASE_HEX,
VALS(hdcp_addr), 0, NULL, HFILL } },
{ &hf_hdcp_reg,
{ "Register offset", "hdcp.reg", FT_UINT8, BASE_HEX,
VALS(hdcp_reg), 0, NULL, HFILL } },
{ &hf_hdcp_resp_in,
{ "Response In", "hdcp.resp_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this request is in this frame", HFILL }},
{ &hf_hdcp_resp_to,
{ "Response To", "hdcp.resp_to", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is the response to the request in this frame", HFILL }},
{ &hf_hdcp_a_ksv,
{ "Transmitter's key selection vector", "hdcp.a_ksv", FT_UINT64,
BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdcp_b_ksv,
{ "Receiver's key selection vector", "hdcp.b_ksv", FT_UINT64,
BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdcp_an,
{ "Random number for the session", "hdcp.an", FT_UINT64,
BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdcp_hdmi_reserved,
{ "HDMI reserved", "hdcp.hdmi_reserved", FT_UINT8, BASE_DEC,
NULL, 0x80, NULL, HFILL } },
{ &hf_hdcp_repeater,
{ "Repeater", "hdcp.repeater", FT_UINT8, BASE_DEC,
NULL, 0x40, NULL, HFILL } },
{ &hf_hdcp_ksv_fifo,
{ "KSV fifo ready", "hdcp.ksv_fifo", FT_UINT8, BASE_DEC,
NULL, 0x20, NULL, HFILL } },
{ &hf_hdcp_fast_trans,
{ "Support for 400KHz transfers", "hdcp.fast_trans",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL } },
{ &hf_hdcp_features,
{ "Support for additional features", "hdcp.features",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL } },
{ &hf_hdcp_fast_reauth,
{ "Support for fast re-authentication", "hdcp.fast_reauth",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL } },
{ &hf_hdcp_hdmi_mode,
{ "HDMI mode", "hdcp.hdmi_mode",
FT_UINT16, BASE_DEC, NULL, 0x1000, NULL, HFILL } },
{ &hf_hdcp_max_casc_exc,
{ "Maximum cascading depth exceeded", "hdcp.max_casc_exc",
FT_UINT16, BASE_DEC, NULL, 0x0800, NULL, HFILL } },
{ &hf_hdcp_depth,
{ "Repeater cascade depth", "hdcp.depth",
FT_UINT16, BASE_DEC, NULL, 0x0700, NULL, HFILL } },
{ &hf_hdcp_max_devs_exc,
{ "Maximum number of devices exceeded", "hdcp.max_devs_exc",
FT_UINT16, BASE_DEC, NULL, 0x0080, NULL, HFILL } },
{ &hf_hdcp_downstream,
{ "Number of downstream receivers", "hdcp.downstream",
FT_UINT16, BASE_DEC, NULL, 0x007F, NULL, HFILL } },
{ &hf_hdcp_link_vfy,
{ "Link verification response Ri'", "hdcp.link_vfy",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_msg_id,
{ "Message ID", "hdcp2.msg_id", FT_UINT8, BASE_HEX,
VALS(hdcp_msg_id), 0, NULL, HFILL } },
{ &hf_hdcp2_r_tx,
{ "r_tx", "hdcp2.r_tx", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_repeater,
{ "Repeater", "hdcp2.repeater", FT_BOOLEAN, 8,
NULL, 0x1, NULL, HFILL } },
{ &hf_hdcp2_cert_rcv_id,
{ "Receiver ID", "hdcp2.cert.rcv_id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_cert_n,
{ "Receiver RSA key n", "hdcp2.cert.n", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_cert_e,
{ "Receiver RSA key e", "hdcp2.cert.e", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_cert_rcv_sig,
{ "Receiver signature", "hdcp2.cert.rcv_sig", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_e_kh_km,
{ "E_kh_km", "hdcp2.e_kh_km", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_m,
{ "m", "hdcp2.m", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_r_rx,
{ "r_rx", "hdcp2.r_rx", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_h_prime,
{ "H'", "hdcp2.h_prime", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_r_n,
{ "r_n", "hdcp2.r_n", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_l_prime,
{ "L'", "hdcp2.l_prime", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_e_dkey_ks,
{ "E_dkey_ks", "hdcp2.e_dkey_ks", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_hdcp2_r_iv,
{ "r_iv", "hdcp2.r_iv", FT_UINT64, BASE_HEX,
NULL, 0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_hdcp,
&ett_hdcp_cert
};
module_t *hdcp2_module;
msg_table = g_hash_table_new(g_direct_hash, g_direct_equal);
for(i=0; i<array_length(msg_info); i++) {
g_hash_table_insert(msg_table,
GUINT_TO_POINTER((guint)msg_info[i].id),
(const gpointer)(&msg_info[i]));
}
proto_hdcp = proto_register_protocol(
"High bandwidth Digital Content Protection", "HDCP", "hdcp");
proto_hdcp2 = proto_register_protocol(
"High bandwidth Digital Content Protection version 2",
"HDCPv2", "hdcp2");
hdcp2_module = prefs_register_protocol(proto_hdcp2, proto_reg_handoff_hdcp2);
prefs_register_bool_preference(hdcp2_module, "enable", "Enable dissector",
"Enable heuristic HDCPv2 dissector (default is false)",
&hdcp2_enable_dissector);
proto_register_field_array(proto_hdcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("hdcp", dissect_hdcp, proto_hdcp);
new_register_dissector("hdcp2", dissect_hdcp2, proto_hdcp2);
register_init_routine(hdcp_init);
}
void
proto_reg_handoff_hdcp2(void)
{
static gboolean prefs_initialized = FALSE;
if (!prefs_initialized) {
heur_dissector_add ("tcp", dissect_hdcp2, proto_hdcp2);
prefs_initialized = TRUE;
}
proto_set_decoding(proto_hdcp2, hdcp2_enable_dissector);
}
