static int
get_le_multi_byte_value(tvbuff_t *tvb, int offset, proto_tree *tree, guint32 *val_ptr, int hf_index)
{
guint8 byte, bc = 0;
guint32 val = 0;
int start_offset = offset;
do {
byte = tvb_get_guint8(tvb, offset);
offset += 1;
val |= ((byte>>1)&0xff) << (bc++ * 7);
} while ((byte & 0x1) == 0);
*val_ptr = val;
if (hf_index > 0) {
proto_tree_add_uint(tree, hf_index, tvb, start_offset, offset-start_offset, val);
}
return offset;
}
static int
dissect_ctrl_pn(packet_info *pinfo, proto_tree *t, tvbuff_t *tvb, int offset, int cr_flag)
{
proto_tree *st;
proto_item *ti;
int dlci;
int cl;
dlci_state_t *dlci_state;
guint8 flags;
dlci = tvb_get_guint8(tvb, offset) & 0x3f;
proto_tree_add_uint(t, hf_dlci, tvb, offset, 1, dlci);
offset += 1;
flags = tvb_get_guint8(tvb, offset);
cl = flags&0xf0;
ti = proto_tree_add_text(t, tvb, offset, 1, "I1-I4: 0x%x, C1-C4: 0x%x", flags&0xf, (flags>>4)&0xf);
st = proto_item_add_subtree(ti, ett_ctrl_pn_ci);
proto_tree_add_item(st, hf_pn_c14, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st, hf_pn_i14, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(t, hf_priority, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_text(t, tvb, offset, 1, "Acknowledgement timer (T1): %d ms", (guint32)tvb_get_guint8(tvb, offset) * 100);
offset += 1;
proto_tree_add_item(t, hf_max_frame_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(t, hf_max_retrans, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(t, hf_error_recovery_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (!pinfo->fd->flags.visited) {
guint32 token;
if (pinfo->p2p_dir == cr_flag)
token = dlci | 0x01;
else
token = dlci;
dlci_state = se_tree_lookup32(dlci_table, token);
if (!dlci_state) {
dlci_state = se_alloc0(sizeof(dlci_state_t));
se_tree_insert32(dlci_table, token, dlci_state);
}
if (!cl) {
dlci_state->do_credit_fc = 0;
} else if (cr_flag && (cl == 0xf0)) {
dlci_state->do_credit_fc |= 1;
} else if ((!cr_flag) && (cl == 0xe0)) {
dlci_state->do_credit_fc |= 2;
}
}
return offset;
}
static int
dissect_ctrl_msc(proto_tree *t, tvbuff_t *tvb, int offset, int length)
{
proto_tree *st;
proto_item *it;
guint8 status;
int start_offset;
proto_tree_add_uint(t, hf_dlci, tvb, offset, 1, tvb_get_guint8(tvb, offset)&0x3f);
offset += 1;
start_offset = offset;
status = tvb_get_guint8(tvb, offset);
it = proto_tree_add_text(t, tvb, offset, 1, "V.24 Signals: FC = %d, RTC = %d, RTR = %d, IC = %d, DV = %d", (status >> 1) & 1,
(status >> 2) & 1, (status >> 3) & 1,
(status >> 6) & 1, (status >> 7) & 1);
st = proto_item_add_subtree(it, ett_ctrl_pn_v24);
proto_tree_add_item(st, hf_msc_fc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st, hf_msc_rtc, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st, hf_msc_rtr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st, hf_msc_ic, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(st, hf_msc_dv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (length == 3) {
proto_tree_add_text(t, tvb, offset, 1, "Break bits B1-B3: 0x%x", (tvb_get_guint8(tvb, offset) & 0xf) >> 1);
proto_tree_add_item(t, hf_msc_l, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
proto_item_set_len(it, offset-start_offset);
return offset;
}
static int
dissect_btrfcomm_Address(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 *ea_flagp, guint8 *cr_flagp, guint8 *dlcip)
{
proto_item *ti;
proto_tree *addr_tree;
guint8 dlci, cr_flag, ea_flag, flags;
flags = tvb_get_guint8(tvb, offset);
ea_flag = flags&0x01;
if (ea_flagp) {
*ea_flagp = ea_flag;
}
cr_flag = (flags&0x02) ? 1 : 0;
if (cr_flagp) {
*cr_flagp = cr_flag;
}
dlci = flags>>2;
if (dlcip) {
*dlcip = dlci;
}
ti = proto_tree_add_text(tree, tvb, offset, 1, "Address: E/A flag: %d, C/R flag: %d, DLCI: 0x%02x", ea_flag, cr_flag, dlci);
addr_tree = proto_item_add_subtree(ti, ett_addr);
proto_tree_add_uint(addr_tree, hf_dlci, tvb, offset, 1, dlci);
proto_tree_add_item(addr_tree, hf_cr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(addr_tree, hf_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_btrfcomm_Control(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 *pf_flagp, guint8 *frame_typep)
{
proto_item *ti;
proto_tree *hctl_tree;
guint8 frame_type, pf_flag, flags;
flags = tvb_get_guint8(tvb, offset);
pf_flag = (flags&0x10) ? 1 : 0;
if (pf_flagp) {
*pf_flagp = pf_flag;
}
frame_type = flags&0xef;
if (frame_typep) {
*frame_typep = frame_type;
}
ti = proto_tree_add_text(tree, tvb, offset, 1, "Control: Frame type: %s (0x%x), P/F flag: %d",
val_to_str_const(frame_type, vs_frame_type, "Unknown"), frame_type, pf_flag);
hctl_tree = proto_item_add_subtree(ti, ett_control);
proto_tree_add_item(hctl_tree, hf_pf, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(hctl_tree, hf_frame_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_btrfcomm_PayloadLen(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *frame_lenp)
{
guint16 frame_len;
int start_offset = offset;
frame_len = tvb_get_guint8(tvb, offset);
offset += 1;
if (frame_len&0x01) {
frame_len >>= 1;
} else {
frame_len >>= 1;
frame_len |= (tvb_get_guint8(tvb, offset)) << 7;
offset += 1;
}
proto_tree_add_uint(tree, hf_len, tvb, start_offset, offset-start_offset, frame_len);
if (frame_lenp) {
*frame_lenp = frame_len;
}
return offset;
}
static int
dissect_btrfcomm_MccType(tvbuff_t *tvb, int offset, proto_tree *tree, packet_info *pinfo, guint8 *mcc_cr_flagp, guint8 *mcc_ea_flagp, guint32 *mcc_typep)
{
int start_offset = offset;
proto_item *ti;
proto_tree *mcc_tree;
guint8 flags, mcc_cr_flag, mcc_ea_flag;
guint32 mcc_type;
flags = tvb_get_guint8(tvb, offset);
mcc_cr_flag = (flags&0x2) ? 1 : 0;
if (mcc_cr_flagp) {
*mcc_cr_flagp = mcc_cr_flag;
}
mcc_ea_flag = flags & 0x1;
if (mcc_ea_flagp) {
*mcc_ea_flagp = mcc_ea_flag;
}
offset = get_le_multi_byte_value(tvb, offset, tree, &mcc_type, -1);
mcc_type = (mcc_type>>1) & 0x3f;
if (mcc_typep) {
*mcc_typep = mcc_type;
}
if (mcc_type) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(mcc_type, vs_ctl, "Unknown"));
}
ti = proto_tree_add_text(tree, tvb, start_offset, offset-start_offset,
"Type: %s (0x%x), C/R flag = %d, E/A flag = %d",
val_to_str_const(mcc_type, vs_ctl, "Unknown"),
mcc_type, mcc_cr_flag, mcc_ea_flag);
mcc_tree = proto_item_add_subtree(ti, ett_mcc);
proto_tree_add_item(mcc_tree, hf_mcc_cmd, tvb, start_offset, offset-start_offset, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcc_tree, hf_mcc_cr, tvb, start_offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcc_tree, hf_mcc_ea, tvb, start_offset, 1, ENC_LITTLE_ENDIAN);
return offset;
}
static void
dissect_btrfcomm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *rfcomm_tree;
proto_tree *ctrl_tree;
int offset = 0;
int fcs_offset;
guint8 dlci, cr_flag, ea_flag;
guint8 frame_type, pf_flag;
guint16 frame_len;
dlci_state_t *dlci_state = NULL;
ti = proto_tree_add_item(tree, proto_btrfcomm, tvb, offset, -1, ENC_NA);
rfcomm_tree = proto_item_add_subtree(ti, ett_btrfcomm);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RFCOMM");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
case P2P_DIR_UNKNOWN:
col_clear(pinfo->cinfo, COL_INFO);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
offset = dissect_btrfcomm_Address(tvb, offset, rfcomm_tree, &ea_flag, &cr_flag, &dlci);
offset = dissect_btrfcomm_Control(tvb, offset, rfcomm_tree, &pf_flag, &frame_type);
offset = dissect_btrfcomm_PayloadLen(tvb, offset, rfcomm_tree, &frame_len);
if (dlci && (frame_len || (frame_type == 0xef) || (frame_type == 0x2f))) {
guint32 token;
if (pinfo->p2p_dir == cr_flag)
token = dlci | 0x01;
else
token = dlci;
dlci_state = se_tree_lookup32(dlci_table, token);
if (!dlci_state) {
dlci_state = se_alloc0(sizeof(dlci_state_t));
se_tree_insert32(dlci_table, token, dlci_state);
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s DLCI=%d ",
val_to_str_const(frame_type, vs_frame_type_short, "Unknown"), dlci);
if (dlci && (frame_type == 0x2f))
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",
val_to_str_ext_const(dlci_state->service, &vs_service_classes_ext, "Unknown"));
if ((frame_type == 0xef) && dlci && pf_flag) {
col_append_str(pinfo->cinfo, COL_INFO, "UID ");
if ((dlci_state->do_credit_fc & 0x03) == 0x03) {
proto_tree_add_item(rfcomm_tree, hf_fc_credits, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
}
fcs_offset = offset + frame_len;
if (!dlci && frame_len) {
proto_item *mcc_ti;
guint32 mcc_type, length;
guint8 mcc_cr_flag, mcc_ea_flag;
int start_offset = offset;
col_append_str(pinfo->cinfo, COL_INFO, "MPX_CTRL ");
mcc_ti = proto_tree_add_text(rfcomm_tree, tvb, offset, 1, "Multiplexer Control Command");
ctrl_tree = proto_item_add_subtree(mcc_ti, ett_btrfcomm_ctrl);
offset = dissect_btrfcomm_MccType(tvb, offset, ctrl_tree, pinfo, &mcc_cr_flag, &mcc_ea_flag, &mcc_type);
offset = get_le_multi_byte_value(tvb, offset, ctrl_tree, &length, hf_mcc_len);
if (length > (guint32) tvb_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, ctrl_tree, PI_MALFORMED, PI_ERROR, "Huge MCC length: %u", length);
return;
}
switch(mcc_type) {
case 0x20:
col_append_str(pinfo->cinfo, COL_INFO, "Parameter Negotiation ");
dissect_ctrl_pn(pinfo, ctrl_tree, tvb, offset, mcc_cr_flag);
break;
case 0x38:
col_append_str(pinfo->cinfo, COL_INFO, "Model Status Command ");
dissect_ctrl_msc(ctrl_tree, tvb, offset, length);
break;
}
offset += length;
proto_item_set_len(mcc_ti, offset-start_offset);
}
if (dlci && frame_len) {
tvbuff_t *next_tvb;
btl2cap_data_t *l2cap_data;
btrfcomm_data_t rfcomm_data;
next_tvb = tvb_new_subset(tvb, offset, frame_len, frame_len);
l2cap_data = pinfo->private_data;
pinfo->private_data = &rfcomm_data;
rfcomm_data.chandle = l2cap_data->chandle;
rfcomm_data.cid = l2cap_data->cid;
rfcomm_data.dlci = dlci;
if (!dissector_try_uint(rfcomm_service_dissector_table, dlci_state->service,
next_tvb, pinfo, tree)) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
proto_tree_add_item(rfcomm_tree, hf_fcs, tvb, fcs_offset, 1, ENC_LITTLE_ENDIAN);
}
void
proto_register_btrfcomm(void)
{
static hf_register_info hf[] = {
{ &hf_dlci,
{ "DLCI", "btrfcomm.dlci",
FT_UINT8, BASE_HEX, NULL, 0,
"RFCOMM DLCI", HFILL}
},
{ &hf_priority,
{ "Priority", "btrfcomm.priority",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL}
},
{ &hf_max_frame_size,
{ "Max Frame Size", "btrfcomm.max_frame_size",
FT_UINT16, BASE_DEC, NULL, 0,
"Maximum Frame Size", HFILL}
},
{ &hf_max_retrans,
{ "Max Retrans", "btrfcomm.max_retrans",
FT_UINT8, BASE_DEC, NULL, 0,
"Maximum number of retransmissions", HFILL}
},
{ &hf_error_recovery_mode,
{ "Error Recovery Mode", "btrfcomm.error_recovery_mode",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_ea,
{ "EA Flag", "btrfcomm.ea",
FT_UINT8, BASE_HEX, VALS(vs_ea), 0x1,
"EA flag (should be always 1)", HFILL}
},
{ &hf_cr,
{ "C/R Flag", "btrfcomm.cr",
FT_UINT8, BASE_HEX, VALS(vs_cr), 0x2,
"Command/Response flag", HFILL}
},
{ &hf_mcc_ea,
{ "EA Flag", "btrfcomm.mcc.ea",
FT_UINT8, BASE_HEX, VALS(vs_ea), 0x1,
"EA flag (should be always 1)", HFILL}
},
{ &hf_mcc_cr,
{ "C/R Flag", "btrfcomm.mcc.cr",
FT_UINT8, BASE_HEX, VALS(vs_cr), 0x2,
"Command/Response flag", HFILL}
},
{ &hf_mcc_cmd,
{ "C/R Flag", "btrfcomm.mcc.cmd",
FT_UINT8, BASE_HEX, VALS(vs_ctl), 0xfc,
"Command/Response flag", HFILL}
},
{ &hf_frame_type,
{ "Frame type", "btrfcomm.frame_type",
FT_UINT8, BASE_HEX, VALS(vs_frame_type), 0xef,
"Command/Response flag", HFILL}
},
{ &hf_pf,
{ "P/F flag", "btrfcomm.pf",
FT_UINT8, BASE_HEX, NULL, 0x10,
"Poll/Final bit", HFILL}
},
{ &hf_pn_i14,
{ "Type of frame", "btrfcomm.pn.i",
FT_UINT8, BASE_HEX, VALS(vs_ctl_pn_i), 0x0f,
"Type of information frames used for that particular DLCI",
HFILL}
},
{ &hf_pn_c14,
{ "Convergence layer", "btrfcomm.pn.cl",
FT_UINT8, BASE_HEX, VALS(vs_ctl_pn_cl), 0xf0,
"Convergence layer used for that particular DLCI", HFILL}
},
{ &hf_len,
{ "Payload length", "btrfcomm.len",
FT_UINT16, BASE_DEC, NULL, 0,
"Frame length", HFILL}
},
{ &hf_mcc_len,
{ "MCC Length", "btrfcomm.mcc.len",
FT_UINT16, BASE_DEC, NULL, 0,
"Length of MCC data", HFILL}
},
{ &hf_fcs,
{ "Frame Check Sequence", "btrfcomm.fcs",
FT_UINT8, BASE_HEX, NULL, 0,
"Checksum over frame", HFILL}
},
{ &hf_msc_fc,
{ "Flow Control (FC)", "btrfcomm.msc.fc",
FT_UINT8, BASE_HEX, NULL, 0x2,
"Flow Control", HFILL}
},
{ &hf_msc_rtc,
{ "Ready To Communicate (RTC)", "btrfcomm.msc.rtc",
FT_UINT8, BASE_HEX, NULL, 0x4,
"Ready To Communicate", HFILL}
},
{ &hf_msc_rtr,
{ "Ready To Receive (RTR)", "btrfcomm.msc.rtr",
FT_UINT8, BASE_HEX, NULL, 0x8,
"Ready To Receive", HFILL}
},
{ &hf_msc_ic,
{ "Incoming Call Indicator (IC)", "btrfcomm.msc.ic",
FT_UINT8, BASE_HEX, NULL, 0x40,
"Incoming Call Indicator", HFILL}
},
{ &hf_msc_dv,
{ "Data Valid (DV)", "btrfcomm.msc.dv",
FT_UINT8, BASE_HEX, NULL, 0x80,
"Data Valid", HFILL}
},
{ &hf_msc_l,
{ "Length of break in units of 200ms", "btrfcomm.msc.bl",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL}
},
{ &hf_fc_credits,
{ "Credits", "btrfcomm.credits",
FT_UINT8, BASE_DEC, NULL, 0,
"Flow control: number of UIH frames allowed to send", HFILL}
}
};
static gint *ett[] = {
&ett_btrfcomm,
&ett_btrfcomm_ctrl,
&ett_addr,
&ett_control,
&ett_mcc,
&ett_ctrl_pn_ci,
&ett_ctrl_pn_v24
};
proto_btrfcomm = proto_register_protocol("Bluetooth RFCOMM Protocol", "RFCOMM", "btrfcomm");
register_dissector("btrfcomm", dissect_btrfcomm, proto_btrfcomm);
proto_register_field_array(proto_btrfcomm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rfcomm_service_dissector_table = register_dissector_table("btrfcomm.service", "RFCOMM SERVICE", FT_UINT16, BASE_HEX);
dlci_table = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "RFCOMM dlci table");
}
static int
btrfcomm_sdp_tap_packet(void *arg _U_, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *arg2)
{
btsdp_data_t *sdp_data = (btsdp_data_t *) arg2;
if (sdp_data->protocol == BTSDP_RFCOMM_PROTOCOL_UUID) {
guint32 token;
dlci_state_t *dlci_state;
token = (sdp_data->channel<<1) | (sdp_data->flags & BTSDP_LOCAL_SERVICE_FLAG_MASK);
dlci_state = se_tree_lookup32(dlci_table, token);
if (!dlci_state) {
dlci_state = se_alloc0(sizeof(dlci_state_t));
se_tree_insert32(dlci_table, token, dlci_state);
}
dlci_state->service = sdp_data->service;
}
return 0;
}
void
proto_reg_handoff_btrfcomm(void)
{
dissector_handle_t btrfcomm_handle;
btrfcomm_handle = find_dissector("btrfcomm");
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_RFCOMM, btrfcomm_handle);
data_handle = find_dissector("data");
register_tap_listener("btsdp", NULL, NULL, TL_IS_DISSECTOR_HELPER, NULL, btrfcomm_sdp_tap_packet, NULL);
}
static void
dissect_bthf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *st;
guint length = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HANDSFREE");
ti = proto_tree_add_item(tree, proto_bthf, tvb, 0, -1, ENC_NA);
st = proto_item_add_subtree(ti, ett_bthf);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s \"%s\"",
(pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd",
tvb_format_text(tvb, 0, length));
proto_tree_add_item(st, hf_at_cmd, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
void
proto_register_bthf(void)
{
static hf_register_info hf[] = {
{ &hf_at_cmd,
{ "AT Cmd", "bthf.atcmd",
FT_STRING, BASE_NONE, NULL, 0,
"AT Command", HFILL}
},
};
static gint *ett[] = {
&ett_bthf,
};
proto_bthf = proto_register_protocol("Bluetooth Handsfree Packet", "BTHF", "bthf");
proto_register_field_array(proto_bthf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bthf(void)
{
dissector_handle_t bthf_handle;
bthf_handle = create_dissector_handle(dissect_bthf, proto_bthf);
dissector_add_uint("btrfcomm.service", BTSDP_HFP_SERVICE_UUID, bthf_handle);
dissector_add_uint("btrfcomm.service", BTSDP_HFP_GW_SERVICE_UUID, bthf_handle);
}
static void
dissect_btdun(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *st;
gboolean is_at_cmd;
guint i, length;
length = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DUN");
ti = proto_tree_add_item(tree, proto_btdun, tvb, 0, -1, ENC_NA);
st = proto_item_add_subtree(ti, ett_btdun);
is_at_cmd = TRUE;
for(i=0; i<length && is_at_cmd; i++) {
is_at_cmd = tvb_get_guint8(tvb, i) < 0x7d;
}
if (is_at_cmd) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s \"%s\"",
(pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd",
tvb_format_text(tvb, 0, length));
proto_tree_add_item(st, hf_dun_at_cmd, tvb, 0, -1, ENC_ASCII|ENC_NA);
}
else {
if (ppp_handle)
call_dissector(ppp_handle, tvb, pinfo, tree);
else {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s <PPP frame>", (pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd");
call_dissector(data_handle, tvb, pinfo, tree);
}
}
}
void
proto_register_btdun(void)
{
static hf_register_info hf[] = {
{ &hf_dun_at_cmd,
{ "AT Cmd", "btdun.atcmd",
FT_STRING, BASE_NONE, NULL, 0,
"AT Command", HFILL}
},
};
static gint *ett[] = {
&ett_btdun,
};
proto_btdun = proto_register_protocol("Bluetooth DUN Packet", "BTDUN", "btdun");
proto_register_field_array(proto_bthf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btdun(void)
{
dissector_handle_t btdun_handle;
btdun_handle = create_dissector_handle(dissect_btdun, proto_btdun);
dissector_add_uint("btrfcomm.service", BTSDP_DUN_SERVICE_UUID, btdun_handle);
ppp_handle = find_dissector("ppp_raw_hdlc");
}
static void
dissect_btspp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *st;
gboolean ascii_only;
guint i, length = tvb_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SPP");
ti = proto_tree_add_item(tree, proto_btspp, tvb, 0, -1, ENC_NA);
st = proto_item_add_subtree(ti, ett_btspp);
length = MIN(length,60);
ascii_only = TRUE;
for(i=0; i<length && ascii_only; i++) {
ascii_only = tvb_get_guint8(tvb, i) < 0x80;
}
if (ascii_only) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s \"%s%s\"",
(pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd",
tvb_format_text(tvb, 0, length),
(tvb_length(tvb) > length) ? "..." : "");
}
proto_tree_add_item(st, hf_data, tvb, 0, -1, ENC_NA);
}
void
proto_register_btspp(void)
{
static hf_register_info hf[] = {
{ &hf_data,
{ "Data", "btspp.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_btspp,
};
proto_btspp = proto_register_protocol("Bluetooth SPP Packet", "BTSPP", "btspp");
proto_register_field_array(proto_bthf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btspp(void)
{
dissector_handle_t btspp_handle;
btspp_handle = create_dissector_handle(dissect_btspp, proto_btspp);
dissector_add_uint("btrfcomm.service", BTSDP_SPP_SERVICE_UUID, btspp_handle);
}
