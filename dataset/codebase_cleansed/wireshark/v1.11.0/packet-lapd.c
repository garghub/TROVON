static void
fill_lapd_byte_state(lapd_byte_state_t *ptr, enum lapd_bitstream_states state, char full_byte, char bit_offset, int ones, char *data, int data_len)
{
ptr->state = state;
ptr->full_byte = full_byte;
ptr->bit_offset = bit_offset;
ptr->ones = ones;
memcpy(ptr->data, data, data_len);
ptr->data_len = data_len;
}
static void new_byte(char full_byte, char data[], int *data_len) {
if (*data_len < MAX_LAPD_PACKET_LEN) {
data[*data_len] = full_byte;
(*data_len)++;
} else {
}
}
static void
lapd_log_abort(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char *msg)
{
proto_item *ti;
ti = proto_tree_add_item(tree, proto_lapd, tvb, offset, 1, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_lapd_abort, "%s", msg);
}
static void
dissect_lapd_bitstream(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 byte, full_byte = 0x00, bit_offset = 0;
gboolean bit;
guint8 i, ones = 0, data[MAX_LAPD_PACKET_LEN];
int data_len = 0;
gint offset = 0, available;
guint8 *buff;
tvbuff_t *new_tvb;
enum lapd_bitstream_states state = OUT_OF_SYNC;
lapd_ppi_t *lapd_ppi;
conversation_t *conversation = NULL;
lapd_convo_data_t *convo_data = NULL;
lapd_byte_state_t *lapd_byte_state, *prev_byte_state = NULL;
gboolean forward_stream = TRUE;
conversation = find_or_create_conversation(pinfo);
lapd_ppi = (lapd_ppi_t*)p_get_proto_data(pinfo->fd, proto_lapd, 0);
if (lapd_ppi) {
prev_byte_state = &lapd_ppi->start_byte_state;
if (prev_byte_state) {
state = prev_byte_state->state;
full_byte = prev_byte_state->full_byte;
bit_offset = prev_byte_state->bit_offset;
ones = prev_byte_state->ones;
memcpy(data, prev_byte_state->data, prev_byte_state->data_len);
data_len = prev_byte_state->data_len;
}
} else if (conversation) {
convo_data = (lapd_convo_data_t*)conversation_get_proto_data(conversation, proto_lapd);
if (NULL != convo_data) {
if (ADDRESSES_EQUAL(&convo_data->addr_a, &pinfo->src)
&& ADDRESSES_EQUAL(&convo_data->addr_b, &pinfo->dst)
&& convo_data-> port_a == pinfo->srcport
&& convo_data-> port_b == pinfo->destport) {
forward_stream = TRUE;
prev_byte_state = convo_data->byte_state_a;
} else if (ADDRESSES_EQUAL(&convo_data-> addr_b, &pinfo->src)
&& ADDRESSES_EQUAL(&convo_data->addr_a, &pinfo->dst)
&& convo_data-> port_b == pinfo->srcport
&& convo_data-> port_a == pinfo->destport) {
forward_stream = FALSE;
prev_byte_state = convo_data->byte_state_b;
}
}
if (prev_byte_state) {
state = prev_byte_state->state;
full_byte = prev_byte_state->full_byte;
bit_offset = prev_byte_state->bit_offset;
ones = prev_byte_state->ones;
memcpy(data, prev_byte_state->data, prev_byte_state->data_len);
data_len = prev_byte_state->data_len;
}
}
available = tvb_length_remaining(tvb, offset);
while (offset < available) {
byte = tvb_get_guint8(tvb,offset);
offset++;
for (i=0; i < 8; i++) {
bit = byte & (0x80 >> i) ? TRUE : FALSE;
if (bit) {
ones++;
full_byte |= (1 << bit_offset++);
} else {
if (ones == 5 && state == DATA) {
} else if (ones == 6 && state == DATA) {
buff = (guint8 *)g_memdup(data, data_len);
new_tvb = tvb_new_child_real_data(tvb, buff, data_len, data_len);
tvb_set_free_cb(new_tvb, g_free);
add_new_data_source(pinfo, new_tvb, "Decoded LAPD bitstream");
data_len = 0;
state = FLAGS;
bit_offset++;
if (full_byte != 0x7E) {
data_len = 0;
state = OUT_OF_SYNC;
lapd_log_abort(tvb, pinfo, tree, offset, "Abort! 6 ones that don't match 0x7e!");
}
dissect_lapd_full(new_tvb, pinfo, tree, TRUE);
} else if (ones >= 7) {
data_len = 0;
state = OUT_OF_SYNC;
bit_offset++;
lapd_log_abort(tvb, pinfo, tree, offset, "Abort! 7 ones!");
} else {
bit_offset++;
}
ones = 0;
}
if (bit_offset == 8) {
switch (state) {
case OUT_OF_SYNC:
if (full_byte == 0x7E) {
state = FLAGS;
full_byte = 0x00;
bit_offset = 0;
} else {
full_byte = (full_byte >> 1) & 0x7F;
bit_offset--;
}
break;
case FLAGS:
if (full_byte == 0x7E) {
full_byte = 0x00;
bit_offset = 0;
} else {
state = DATA;
new_byte(full_byte, data, &data_len);
full_byte = 0x00;
bit_offset = 0;
}
break;
case DATA:
new_byte(full_byte, data, &data_len);
full_byte = 0x00;
bit_offset = 0;
break;
}
}
}
}
{
if (NULL == p_get_proto_data(pinfo->fd, proto_lapd, 0)) {
lapd_ppi = wmem_new(wmem_file_scope(), lapd_ppi_t);
lapd_ppi->has_crc = TRUE;
if (prev_byte_state)
fill_lapd_byte_state(&lapd_ppi->start_byte_state, prev_byte_state->state,
prev_byte_state->full_byte, prev_byte_state->bit_offset,
prev_byte_state->ones, prev_byte_state->data, prev_byte_state->data_len);
else
fill_lapd_byte_state(&lapd_ppi->start_byte_state, OUT_OF_SYNC, 0x00, 0, 0, data, 0);
p_add_proto_data(pinfo->fd, proto_lapd, 0, lapd_ppi);
if (conversation) {
if (convo_data) {
if (forward_stream)
fill_lapd_byte_state(convo_data->byte_state_a, state, full_byte, bit_offset, ones, data, data_len);
else {
if (!convo_data->byte_state_b)
convo_data->byte_state_b = wmem_new(wmem_file_scope(), lapd_byte_state_t);
fill_lapd_byte_state(convo_data->byte_state_b, state, full_byte, bit_offset, ones, data, data_len);
}
} else {
lapd_byte_state = wmem_new(wmem_file_scope(), lapd_byte_state_t);
fill_lapd_byte_state(lapd_byte_state, state, full_byte, bit_offset, ones, data, data_len);
convo_data = wmem_new(wmem_file_scope(), lapd_convo_data_t);
COPY_ADDRESS(&convo_data->addr_a, &pinfo->src);
COPY_ADDRESS(&convo_data->addr_b, &pinfo->dst);
convo_data->port_a = pinfo->srcport;
convo_data->port_b = pinfo->destport;
convo_data->byte_state_a = lapd_byte_state;
convo_data->byte_state_b = NULL;
conversation_add_proto_data(conversation, proto_lapd, convo_data);
}
}
}
}
}
static void
dissect_lapd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_lapd_full(tvb, pinfo, tree, FALSE);
}
static void
dissect_lapd_full(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean has_crc)
{
proto_tree *lapd_tree, *addr_tree, *checksum_tree;
proto_item *lapd_ti, *addr_ti, *checksum_ti;
int direction;
guint16 control, checksum, checksum_calculated;
int lapd_header_len, checksum_offset;
guint16 addr, cr, sapi, tei;
gboolean is_response = 0;
tvbuff_t *next_tvb;
const char *srcname = "?";
const char *dstname = "?";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LAPD");
col_clear(pinfo->cinfo, COL_INFO);
addr = tvb_get_ntohs(tvb, 0);
cr = addr & LAPD_CR;
tei = (addr & LAPD_TEI) >> LAPD_TEI_SHIFT;
sapi = (addr & LAPD_SAPI) >> LAPD_SAPI_SHIFT;
lapd_header_len = 2;
col_add_fstr(pinfo->cinfo, COL_TEI, "%u", tei);
col_append_fstr(pinfo->cinfo, COL_INFO, "TEI:%02u ", tei);
col_set_fence(pinfo->cinfo, COL_INFO);
if (pinfo->fd->lnk_t == WTAP_ENCAP_LINUX_LAPD) {
if (pinfo->pseudo_header->lapd.pkttype == 4 ) {
if (pinfo->pseudo_header->lapd.we_network) {
is_response = cr ? FALSE : TRUE;
srcname = "Local Network";
dstname = "Remote User";
direction = P2P_DIR_RECV;
} else {
srcname = "Local User";
dstname = "Remote Network";
direction = P2P_DIR_SENT;
}
}
else if (pinfo->pseudo_header->lapd.pkttype == 3 ) {
is_response = cr ? TRUE : FALSE;
srcname = "Remote User";
dstname = "Remote Network";
direction = P2P_DIR_SENT;
}
else {
if (pinfo->pseudo_header->lapd.we_network) {
is_response = cr ? TRUE : FALSE;
srcname = "Remote User";
dstname = "Local Network";
direction = P2P_DIR_SENT;
} else {
is_response = cr ? FALSE : TRUE;
srcname = "Remote Network";
dstname = "Local User";
direction = P2P_DIR_RECV;
}
}
} else {
direction = pinfo->p2p_dir;
if (pinfo->p2p_dir == P2P_DIR_RECV) {
is_response = cr ? FALSE : TRUE;
srcname = "Network";
dstname = "User";
}
else if (pinfo->p2p_dir == P2P_DIR_SENT) {
is_response = cr ? TRUE : FALSE;
srcname = "User";
dstname = "Network";
}
}
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, srcname);
col_set_str(pinfo->cinfo, COL_RES_DL_DST, dstname);
if (tree) {
proto_item *direction_ti;
lapd_ti = proto_tree_add_item(tree, proto_lapd, tvb, 0, -1,
ENC_NA);
lapd_tree = proto_item_add_subtree(lapd_ti, ett_lapd);
if (direction != P2P_DIR_UNKNOWN) {
direction_ti = proto_tree_add_uint(lapd_tree, hf_lapd_direction,
tvb, 0, 0, pinfo->p2p_dir);
PROTO_ITEM_SET_GENERATED(direction_ti);
}
addr_ti = proto_tree_add_uint(lapd_tree, hf_lapd_address, tvb,
0, 2, addr);
addr_tree = proto_item_add_subtree(addr_ti, ett_lapd_address);
if(global_lapd_gsm_sapis){
proto_tree_add_uint(addr_tree, hf_lapd_gsm_sapi,tvb, 0, 1, addr);
}else{
proto_tree_add_uint(addr_tree, hf_lapd_sapi,tvb, 0, 1, addr);
}
proto_tree_add_uint(addr_tree, hf_lapd_cr, tvb, 0, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapd_ea1, tvb, 0, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapd_tei, tvb, 1, 1, addr);
proto_tree_add_uint(addr_tree, hf_lapd_ea2, tvb, 1, 1, addr);
}
else {
lapd_ti = NULL;
lapd_tree = NULL;
}
control = dissect_xdlc_control(tvb, 2, pinfo, lapd_tree, hf_lapd_control,
ett_lapd_control, &lapd_cf_items, &lapd_cf_items_ext, NULL, NULL,
is_response, TRUE, FALSE);
lapd_header_len += XDLC_CONTROL_LEN(control, TRUE);
if (tree)
proto_item_set_len(lapd_ti, lapd_header_len);
if (has_crc) {
checksum_offset = tvb_length(tvb) - 2;
checksum = tvb_get_guint8(tvb, checksum_offset);
checksum <<= 8;
checksum |= tvb_get_guint8(tvb, checksum_offset+1) & 0x00FF;
checksum_calculated = crc16_ccitt_tvb(tvb, tvb_length(tvb) - 2);
checksum_calculated = g_htons(checksum_calculated);
if (checksum == checksum_calculated) {
checksum_ti = proto_tree_add_uint_format_value(lapd_tree, hf_lapd_checksum, tvb, checksum_offset, 2, 0,"0x%04x [correct]", checksum);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_lapd_checksum);
proto_tree_add_boolean(checksum_tree, hf_lapd_checksum_good, tvb, checksum_offset, 2, TRUE);
proto_tree_add_boolean(checksum_tree, hf_lapd_checksum_bad, tvb, checksum_offset, 2, FALSE);
} else {
proto_item *pi;
checksum_ti = proto_tree_add_uint_format_value(lapd_tree, hf_lapd_checksum, tvb, checksum_offset, 2, 0,"0x%04x [incorrect, should be 0x%04x]", checksum, checksum_calculated);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_lapd_checksum);
proto_tree_add_boolean(checksum_tree, hf_lapd_checksum_good, tvb, checksum_offset, 2, FALSE);
pi = proto_tree_add_boolean(checksum_tree, hf_lapd_checksum_bad, tvb, checksum_offset, 2, TRUE);
expert_add_info(pinfo, pi, &ei_lapd_checksum_bad);
}
next_tvb = tvb_new_subset(tvb, lapd_header_len, tvb_length_remaining(tvb,lapd_header_len) - 2, tvb_length_remaining(tvb,lapd_header_len) - 2);
} else
next_tvb = tvb_new_subset_remaining(tvb, lapd_header_len);
col_append_fstr(pinfo->cinfo, COL_INFO, " | ");
col_set_fence(pinfo->cinfo, COL_INFO);
if (XDLC_IS_INFORMATION(control)) {
if(global_lapd_gsm_sapis){
if (!dissector_try_uint(lapd_gsm_sapi_dissector_table, sapi,
next_tvb, pinfo, tree))
call_dissector(data_handle,next_tvb, pinfo, tree);
}else{
if (!dissector_try_uint(lapd_sapi_dissector_table, sapi,
next_tvb, pinfo, tree))
call_dissector(data_handle,next_tvb, pinfo, tree);
}
} else
call_dissector(data_handle,next_tvb, pinfo, tree);
}
void
proto_register_lapd(void)
{
static hf_register_info hf[] = {
{ &hf_lapd_direction,
{ "Direction", "lapd.direction", FT_UINT8, BASE_DEC, VALS(lapd_direction_vals), 0x0,
NULL, HFILL }},
{ &hf_lapd_address,
{ "Address Field", "lapd.address", FT_UINT16, BASE_HEX, NULL, 0x0,
"Address", HFILL }},
{ &hf_lapd_sapi,
{ "SAPI", "lapd.sapi", FT_UINT16, BASE_DEC, VALS(lapd_sapi_vals), LAPD_SAPI,
"Service Access Point Identifier", HFILL }},
{ &hf_lapd_gsm_sapi,
{ "SAPI", "lapd.sapi", FT_UINT16, BASE_DEC, VALS(lapd_gsm_sapi_vals), LAPD_SAPI,
"Service Access Point Identifier", HFILL }},
{ &hf_lapd_cr,
{ "C/R", "lapd.cr", FT_UINT16, BASE_DEC, NULL, LAPD_CR,
"Command/Response bit", HFILL }},
{ &hf_lapd_ea1,
{ "EA1", "lapd.ea1", FT_UINT16, BASE_DEC, NULL, LAPD_EA1,
"First Address Extension bit", HFILL }},
{ &hf_lapd_tei,
{ "TEI", "lapd.tei", FT_UINT16, BASE_DEC, NULL, LAPD_TEI,
"Terminal Endpoint Identifier", HFILL }},
{ &hf_lapd_ea2,
{ "EA2", "lapd.ea2", FT_UINT16, BASE_DEC, NULL, LAPD_EA2,
"Second Address Extension bit", HFILL }},
{ &hf_lapd_control,
{ "Control Field", "lapd.control", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_lapd_n_r,
{ "N(R)", "lapd.control.n_r", FT_UINT16, BASE_DEC,
NULL, XDLC_N_R_EXT_MASK, NULL, HFILL }},
{ &hf_lapd_n_s,
{ "N(S)", "lapd.control.n_s", FT_UINT16, BASE_DEC,
NULL, XDLC_N_S_EXT_MASK, NULL, HFILL }},
{ &hf_lapd_p,
{ "Poll", "lapd.control.p", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_lapd_p_ext,
{ "Poll", "lapd.control.p", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), XDLC_P_F_EXT, NULL, HFILL }},
{ &hf_lapd_f,
{ "Final", "lapd.control.f", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), XDLC_P_F, NULL, HFILL }},
{ &hf_lapd_f_ext,
{ "Final", "lapd.control.f", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), XDLC_P_F_EXT, NULL, HFILL }},
{ &hf_lapd_s_ftype,
{ "Supervisory frame type", "lapd.control.s_ftype", FT_UINT16, BASE_HEX,
VALS(stype_vals), XDLC_S_FTYPE_MASK, NULL, HFILL }},
{ &hf_lapd_u_modifier_cmd,
{ "Command", "lapd.control.u_modifier_cmd", FT_UINT8, BASE_HEX,
VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_lapd_u_modifier_resp,
{ "Response", "lapd.control.u_modifier_resp", FT_UINT8, BASE_HEX,
VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK, NULL, HFILL }},
{ &hf_lapd_ftype_i,
{ "Frame type", "lapd.control.ftype", FT_UINT16, BASE_HEX,
VALS(ftype_vals), XDLC_I_MASK, NULL, HFILL }},
{ &hf_lapd_ftype_s_u,
{ "Frame type", "lapd.control.ftype", FT_UINT8, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
{ &hf_lapd_ftype_s_u_ext,
{ "Frame type", "lapd.control.ftype", FT_UINT16, BASE_HEX,
VALS(ftype_vals), XDLC_S_U_MASK, NULL, HFILL }},
{ &hf_lapd_checksum,
{ "Checksum", "lapd.checksum", FT_UINT16, BASE_HEX,
NULL, 0x0, "Details at: http://www.wireshark.org/docs/wsug_html_chunked/ChAdvChecksums.html", HFILL }},
{ &hf_lapd_checksum_good,
{ "Good Checksum", "lapd.checksum_good", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_lapd_checksum_bad,
{ "Bad Checksum", "lapd.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
};
static gint *ett[] = {
&ett_lapd,
&ett_lapd_address,
&ett_lapd_control,
&ett_lapd_checksum
};
static ei_register_info ei[] = {
{ &ei_lapd_abort, { "lapd.abort.expert", PI_PROTOCOL, PI_ERROR, "Formatted message", EXPFILL }},
{ &ei_lapd_checksum_bad, { "lapd.checksum_bad.expert", PI_CHECKSUM, PI_WARN, "Bad FCS", EXPFILL }},
};
module_t *lapd_module;
expert_module_t* expert_lapd;
proto_lapd = proto_register_protocol("Link Access Procedure, Channel D (LAPD)",
"LAPD", "lapd");
proto_register_field_array (proto_lapd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_lapd = expert_register_protocol(proto_lapd);
expert_register_field_array(expert_lapd, ei, array_length(ei));
register_dissector("lapd", dissect_lapd, proto_lapd);
lapd_sapi_dissector_table = register_dissector_table("lapd.sapi",
"LAPD SAPI", FT_UINT16, BASE_DEC);
lapd_gsm_sapi_dissector_table = register_dissector_table("lapd.gsm.sapi",
"LAPD GSM SAPI", FT_UINT16, BASE_DEC);
lapd_module = prefs_register_protocol(proto_lapd, proto_reg_handoff_lapd);
prefs_register_bool_preference(lapd_module, "use_gsm_sapi_values",
"Use GSM SAPI values",
"Use SAPI values as specified in TS 48 056",
&global_lapd_gsm_sapis);
prefs_register_uint_preference(lapd_module, "rtp_payload_type",
"RTP payload type for embedded LAPD",
"RTP payload type for embedded LAPD. It must be one of the dynamic types "
"from 96 to 127. Set it to 0 to disable.",
10, &pref_lapd_rtp_payload_type);
}
void
proto_reg_handoff_lapd(void)
{
static gboolean init = FALSE;
static dissector_handle_t lapd_bitstream_handle;
static gint lapd_rtp_payload_type;
if (!init) {
dissector_handle_t lapd_handle;
lapd_handle = find_dissector("lapd");
dissector_add_uint("wtap_encap", WTAP_ENCAP_LINUX_LAPD, lapd_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_LAPD, lapd_handle);
register_dissector("lapd-bitstream", dissect_lapd_bitstream, proto_lapd);
lapd_bitstream_handle = find_dissector("lapd-bitstream");
data_handle = find_dissector("data");
init = TRUE;
} else {
if ((lapd_rtp_payload_type > 95) && (lapd_rtp_payload_type < 128))
dissector_delete_uint("rtp.pt", lapd_rtp_payload_type, lapd_bitstream_handle);
}
lapd_rtp_payload_type = pref_lapd_rtp_payload_type;
if ((lapd_rtp_payload_type > 95) && (lapd_rtp_payload_type < 128))
dissector_add_uint("rtp.pt", lapd_rtp_payload_type, lapd_bitstream_handle);
}
