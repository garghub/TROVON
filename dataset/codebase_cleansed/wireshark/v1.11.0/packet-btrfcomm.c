static dissector_handle_t
find_proto_by_channel(guint channel) {
guint i_channel;
for (i_channel = 0; i_channel < num_rfcomm_channels; ++i_channel) {
if (rfcomm_channels[i_channel].channel == channel) {
return rfcomm_channels[i_channel].payload_proto;
}
}
return NULL;
}
static int
get_le_multi_byte_value(tvbuff_t *tvb, int offset, proto_tree *tree, guint32 *val_ptr, int hf_index)
{
guint8 byte, bc = 0;
guint32 val = 0;
int start_offset = offset;
do {
byte = tvb_get_guint8(tvb, offset);
offset += 1;
val |= ((byte >> 1) & 0xff) << (bc++ * 7);
} while ((byte & 0x1) == 0);
*val_ptr = val;
if (hf_index > 0) {
proto_tree_add_uint(tree, hf_index, tvb, start_offset, offset - start_offset, val);
}
return offset;
}
static int
dissect_ctrl_pn(proto_tree *t, tvbuff_t *tvb, int offset, guint8 *mcc_channel)
{
proto_tree *st;
proto_item *ti;
proto_tree *dlci_tree;
proto_item *dlci_item;
int mcc_dlci;
guint8 flags;
proto_tree_add_item(t, hf_mcc_pn_zeros_padding, tvb, offset, 1, ENC_LITTLE_ENDIAN);
mcc_dlci = tvb_get_guint8(tvb, offset) & 0x3f;
*mcc_channel = mcc_dlci >> 1;
dlci_item = proto_tree_add_item(t, hf_mcc_pn_dlci, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(dlci_item, " (Direction: %d, Channel: %u)", mcc_dlci & 0x01, *mcc_channel);
dlci_tree = proto_item_add_subtree(dlci_item, ett_mcc_dlci);
proto_tree_add_item(dlci_tree, hf_mcc_pn_channel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dlci_tree, hf_mcc_pn_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
flags = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(t, tvb, offset, 1, "I1-I4: 0x%x, C1-C4: 0x%x", flags & 0xf, (flags >> 4) & 0xf);
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
return offset;
}
static int
dissect_ctrl_msc(proto_tree *t, tvbuff_t *tvb, int offset, int length, guint8 *mcc_channel)
{
proto_tree *st;
proto_item *it;
proto_tree *dlci_tree;
proto_item *dlci_item;
guint8 mcc_dlci;
guint8 status;
int start_offset;
mcc_dlci = tvb_get_guint8(tvb, offset) >> 2;
*mcc_channel = mcc_dlci >> 1;
dlci_item = proto_tree_add_item(t, hf_mcc_dlci, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(dlci_item, " (Direction: %d, Channel: %u)", mcc_dlci & 0x01, *mcc_channel);
dlci_tree = proto_item_add_subtree(dlci_item, ett_mcc_dlci);
proto_tree_add_item(dlci_tree, hf_mcc_channel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dlci_tree, hf_mcc_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(t, hf_mcc_const_1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(t, hf_mcc_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
proto_item_set_len(it, offset - start_offset);
return offset;
}
static int
dissect_btrfcomm_address(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 *ea_flagp, guint8 *cr_flagp, guint8 *dlcip)
{
proto_item *ti;
proto_tree *addr_tree;
proto_tree *dlci_tree = NULL;
proto_item *dlci_item = NULL;
guint8 dlci, cr_flag, ea_flag, flags;
flags = tvb_get_guint8(tvb, offset);
ea_flag = flags & 0x01;
if (ea_flagp) {
*ea_flagp = ea_flag;
}
cr_flag = (flags & 0x02) ? 1 : 0;
if (cr_flagp) {
*cr_flagp = cr_flag;
}
dlci = flags >> 2;
if (dlcip) {
*dlcip = dlci;
}
ti = proto_tree_add_text(tree, tvb, offset, 1, "Address: E/A flag: %d, C/R flag: %d, Direction: %d, Channel: %u", ea_flag, cr_flag, dlci & 0x01, dlci >> 1);
addr_tree = proto_item_add_subtree(ti, ett_addr);
dlci_item = proto_tree_add_item(addr_tree, hf_dlci, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(dlci_item, " (Direction: %d, Channel: %u)", dlci & 0x01, dlci >> 1);
dlci_tree = proto_item_add_subtree(dlci_item, ett_dlci);
proto_tree_add_item(dlci_tree, hf_channel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dlci_tree, hf_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(addr_tree, hf_cr, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(addr_tree, hf_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_btrfcomm_control(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 *pf_flagp, guint8 *frame_typep)
{
proto_item *ti;
proto_tree *hctl_tree;
guint8 frame_type, pf_flag, flags;
flags = tvb_get_guint8(tvb, offset);
pf_flag = (flags & 0x10) ? 1 : 0;
if (pf_flagp) {
*pf_flagp = pf_flag;
}
frame_type = flags & 0xef;
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
dissect_btrfcomm_payload_length(tvbuff_t *tvb, int offset, proto_tree *tree, guint16 *frame_lenp)
{
guint16 frame_len;
int start_offset = offset;
frame_len = tvb_get_guint8(tvb, offset);
offset += 1;
if (frame_len & 0x01) {
frame_len >>= 1;
} else {
frame_len >>= 1;
frame_len |= (tvb_get_guint8(tvb, offset)) << 7;
offset += 1;
}
proto_tree_add_uint(tree, hf_len, tvb, start_offset, offset - start_offset, frame_len);
if (frame_lenp) {
*frame_lenp = frame_len;
}
return offset;
}
static int
dissect_btrfcomm_MccType(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 *mcc_cr_flagp, guint8 *mcc_ea_flagp, guint32 *mcc_typep)
{
int start_offset = offset;
proto_item *ti;
proto_tree *mcc_tree;
guint8 flags, mcc_cr_flag, mcc_ea_flag;
guint32 mcc_type;
flags = tvb_get_guint8(tvb, offset);
mcc_cr_flag = (flags & 0x2) ? 1 : 0;
if (mcc_cr_flagp) {
*mcc_cr_flagp = mcc_cr_flag;
}
mcc_ea_flag = flags & 0x1;
if (mcc_ea_flagp) {
*mcc_ea_flagp = mcc_ea_flag;
}
offset = get_le_multi_byte_value(tvb, offset, tree, &mcc_type, -1);
mcc_type = (mcc_type >> 1) & 0x3f;
if (mcc_typep) {
*mcc_typep = mcc_type;
}
ti = proto_tree_add_text(tree, tvb, start_offset, offset - start_offset,
"Type: %s (0x%x), C/R flag = %d, E/A flag = %d",
val_to_str_const(mcc_type, vs_ctl, "Unknown"),
mcc_type, mcc_cr_flag, mcc_ea_flag);
mcc_tree = proto_item_add_subtree(ti, ett_mcc);
proto_tree_add_item(mcc_tree, hf_mcc_cmd, tvb, start_offset, offset - start_offset, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcc_tree, hf_mcc_cr, tvb, start_offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcc_tree, hf_mcc_ea, tvb, start_offset, 1, ENC_LITTLE_ENDIAN);
return offset;
}
static void
dissect_btrfcomm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *rfcomm_tree;
int offset = 0;
int fcs_offset;
guint8 dlci, cr_flag, ea_flag;
guint8 frame_type, pf_flag;
guint16 frame_len;
btl2cap_data_t *l2cap_data;
service_info_t *service_info = NULL;
ti = proto_tree_add_item(tree, proto_btrfcomm, tvb, offset, -1, ENC_NA);
rfcomm_tree = proto_item_add_subtree(ti, ett_btrfcomm);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RFCOMM");
l2cap_data = (btl2cap_data_t *) pinfo->private_data;
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
offset = dissect_btrfcomm_address(tvb, offset, rfcomm_tree, &ea_flag, &cr_flag, &dlci);
offset = dissect_btrfcomm_control(tvb, offset, rfcomm_tree, &pf_flag, &frame_type);
offset = dissect_btrfcomm_payload_length(tvb, offset, rfcomm_tree, &frame_len);
if (dlci && (frame_len || (frame_type == 0xef) || (frame_type == 0x2f))) {
wmem_tree_key_t key[10];
guint32 k_interface_id;
guint32 k_adapter_id;
guint32 k_sdp_psm;
guint32 k_direction;
guint32 k_bd_addr_oui;
guint32 k_bd_addr_id;
guint32 k_service_type;
guint32 k_service_channel;
guint32 k_frame_number;
k_interface_id = l2cap_data->interface_id;
k_adapter_id = l2cap_data->adapter_id;
k_sdp_psm = SDP_PSM_DEFAULT;
k_direction = (dlci & 0x01) ? P2P_DIR_SENT : P2P_DIR_RECV;
if (k_direction == P2P_DIR_RECV) {
k_bd_addr_oui = l2cap_data->remote_bd_addr_oui;
k_bd_addr_id = l2cap_data->remote_bd_addr_id;
} else {
k_bd_addr_oui = 0;
k_bd_addr_id = 0;
}
k_service_type = BTSDP_RFCOMM_PROTOCOL_UUID;
k_service_channel = dlci >> 1;
k_frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_sdp_psm;
key[3].length = 1;
key[3].key = &k_direction;
key[4].length = 1;
key[4].key = &k_bd_addr_oui;
key[5].length = 1;
key[5].key = &k_bd_addr_id;
key[6].length = 1;
key[6].key = &k_service_type;
key[7].length = 1;
key[7].key = &k_service_channel;
key[8].length = 1;
key[8].key = &k_frame_number;
key[9].length = 0;
key[9].key = NULL;
if (sdp_service_infos) {
service_info = (service_info_t *) wmem_tree_lookup32_array_le(sdp_service_infos, key);
}
if (service_info && service_info->interface_id == l2cap_data->interface_id &&
service_info->adapter_id == l2cap_data->adapter_id &&
service_info->sdp_psm == SDP_PSM_DEFAULT &&
((service_info->direction == P2P_DIR_RECV &&
service_info->bd_addr_oui == l2cap_data->remote_bd_addr_oui &&
service_info->bd_addr_id == l2cap_data->remote_bd_addr_id) ||
(service_info->direction != P2P_DIR_RECV &&
service_info->bd_addr_oui == 0 &&
service_info->bd_addr_id == 0)) &&
service_info->type == BTSDP_RFCOMM_PROTOCOL_UUID &&
service_info->channel == (dlci >> 1)) {
} else {
service_info = wmem_new0(wmem_packet_scope(), service_info_t);
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s Channel=%u ",
val_to_str_const(frame_type, vs_frame_type_short, "Unknown"), dlci >> 1);
if (dlci && (frame_type == 0x2f))
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",
val_to_str_ext_const(service_info->uuid, &vs_service_classes_ext, "Unknown"));
if ((frame_type == 0xef) && dlci && pf_flag) {
col_append_str(pinfo->cinfo, COL_INFO, "UID ");
proto_tree_add_item(rfcomm_tree, hf_fc_credits, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
fcs_offset = offset + frame_len;
if (!dlci && frame_len) {
proto_item *mcc_ti;
proto_tree *ctrl_tree;
proto_tree *dlci_tree;
proto_item *dlci_item;
guint32 mcc_type, length;
guint8 mcc_cr_flag, mcc_ea_flag;
guint8 mcc_channel;
guint8 mcc_dlci;
int start_offset = offset;
mcc_ti = proto_tree_add_text(rfcomm_tree, tvb, offset, 1, "Multiplexer Control Command");
ctrl_tree = proto_item_add_subtree(mcc_ti, ett_btrfcomm_ctrl);
offset = dissect_btrfcomm_MccType(tvb, offset, ctrl_tree, &mcc_cr_flag, &mcc_ea_flag, &mcc_type);
offset = get_le_multi_byte_value(tvb, offset, ctrl_tree, &length, hf_mcc_len);
if (length > (guint32) tvb_length_remaining(tvb, offset)) {
expert_add_info_format(pinfo, ctrl_tree, &ei_btrfcomm_mcc_length_bad, "Huge MCC length: %u", length);
return;
}
switch(mcc_type) {
case 0x20:
dissect_ctrl_pn(ctrl_tree, tvb, offset, &mcc_channel);
break;
case 0x24:
mcc_dlci = tvb_get_guint8(tvb, offset) >> 2;
mcc_channel = mcc_dlci >> 1;
dlci_item = proto_tree_add_item(ctrl_tree, hf_mcc_dlci, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(dlci_item, " (Direction: %d, Channel: %u)", mcc_dlci & 0x01, mcc_channel);
dlci_tree = proto_item_add_subtree(dlci_item, ett_mcc_dlci);
proto_tree_add_item(dlci_tree, hf_mcc_channel, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(dlci_tree, hf_mcc_direction, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ctrl_tree, hf_mcc_const_1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ctrl_tree, hf_mcc_ea, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 0x38:
dissect_ctrl_msc(ctrl_tree, tvb, offset, length, &mcc_channel);
break;
default:
mcc_channel = -1;
}
if (mcc_channel > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, "-> %d ", mcc_channel);
}
col_append_str(pinfo->cinfo, COL_INFO, "MPX_CTRL ");
if(mcc_type){
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(mcc_type, vs_ctl, "Unknown"));
}
offset += length;
proto_item_set_len(mcc_ti, offset - start_offset);
}
if (dlci && frame_len) {
dissector_handle_t decode_by_dissector;
tvbuff_t *next_tvb;
btrfcomm_data_t *rfcomm_data;
next_tvb = tvb_new_subset(tvb, offset, frame_len, frame_len);
rfcomm_data = (btrfcomm_data_t *) wmem_new(wmem_packet_scope(), btrfcomm_data_t);
rfcomm_data->interface_id = l2cap_data->interface_id;
rfcomm_data->adapter_id = l2cap_data->adapter_id;
rfcomm_data->chandle = l2cap_data->chandle;
rfcomm_data->cid = l2cap_data->cid;
rfcomm_data->dlci = dlci;
rfcomm_data->remote_bd_addr_oui = l2cap_data->remote_bd_addr_oui;
rfcomm_data->remote_bd_addr_id = l2cap_data->remote_bd_addr_id;
pinfo->private_data = rfcomm_data;
if (!dissector_try_uint(rfcomm_channel_dissector_table, (guint32) dlci >> 1,
next_tvb, pinfo, tree)) {
if (!dissector_try_uint(rfcomm_service_dissector_table, service_info->uuid,
next_tvb, pinfo, tree)) {
decode_by_dissector = find_proto_by_channel(dlci >> 1);
if (rfcomm_channels_enabled && decode_by_dissector) {
call_dissector(decode_by_dissector, next_tvb, pinfo, tree);
} else {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
}
}
proto_tree_add_item(rfcomm_tree, hf_fcs, tvb, fcs_offset, 1, ENC_LITTLE_ENDIAN);
}
void
proto_register_btrfcomm(void)
{
module_t *module;
expert_module_t* expert_btrfcomm;
static hf_register_info hf[] = {
{ &hf_dlci,
{ "DLCI", "btrfcomm.dlci",
FT_UINT8, BASE_HEX, NULL, 0xFC,
"RFCOMM Data Link Connection Identifier", HFILL}
},
{ &hf_channel,
{ "Channel", "btrfcomm.channel",
FT_UINT8, BASE_DEC, NULL, 0xF8,
"RFCOMM Channel", HFILL}
},
{ &hf_direction,
{"Direction", "btrfcomm.direction",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL}
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
{ "Maximum number of retransmissions", "btrfcomm.max_retrans",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_error_recovery_mode,
{ "Error Recovery Mode", "btrfcomm.error_recovery_mode",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL}
},
{ &hf_ea,
{ "EA Flag", "btrfcomm.ea",
FT_UINT8, BASE_HEX, VALS(vs_ea), 0x01,
"EA flag (should be always 1)", HFILL}
},
{ &hf_cr,
{ "C/R Flag", "btrfcomm.cr",
FT_UINT8, BASE_HEX, VALS(vs_cr), 0x02,
"Command/Response flag", HFILL}
},
{ &hf_mcc_ea,
{ "EA Flag", "btrfcomm.mcc.ea",
FT_UINT8, BASE_HEX, VALS(vs_ea), 0x01,
"RFCOMM MCC EA flag", HFILL}
},
{ &hf_mcc_cr,
{ "C/R Flag", "btrfcomm.mcc.cr",
FT_UINT8, BASE_HEX, VALS(vs_cr), 0x02,
"Command/Response flag", HFILL}
},
{ &hf_mcc_const_1,
{ "Ones padding", "btrfcomm.mcc.padding",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL}
},
{ &hf_mcc_dlci,
{ "MCC DLCI", "btrfcomm.mcc.dlci",
FT_UINT8, BASE_HEX, NULL, 0xFC,
"RFCOMM MCC Data Link Connection Identifier", HFILL}
},
{ &hf_mcc_channel,
{ "MCC Channel", "btrfcomm.mcc.channel",
FT_UINT8, BASE_DEC, NULL, 0xF8,
"RFCOMM MCC Channel", HFILL}
},
{ &hf_mcc_direction,
{ "MCC Direction", "btrfcomm.mcc.direction",
FT_UINT8, BASE_HEX, NULL, 0x04,
"RFCOMM MCC Direction", HFILL}
},
{ &hf_mcc_pn_dlci,
{ "MCC DLCI", "btrfcomm.mcc.dlci",
FT_UINT8, BASE_HEX, NULL, 0x3F,
"RFCOMM MCC Data Link Connection Identifier", HFILL}
},
{ &hf_mcc_pn_channel,
{ "MCC Channel", "btrfcomm.mcc.channel",
FT_UINT8, BASE_DEC, NULL, 0x3E,
"RFCOMM MCC Channel", HFILL}
},
{ &hf_mcc_pn_direction,
{ "MCC Direction", "btrfcomm.mcc.direction",
FT_UINT8, BASE_HEX, NULL, 0x01,
"RFCOMM MCC Direction", HFILL}
},
{ &hf_mcc_pn_zeros_padding,
{ "Zeros padding", "btrfcomm.mcc.padding",
FT_UINT8, BASE_HEX, NULL, 0xC0,
"RFCOMM MSC Zeros padding", HFILL}
},
{ &hf_mcc_cmd,
{ "MCC Command Type", "btrfcomm.mcc.cmd",
FT_UINT8, BASE_HEX, VALS(vs_ctl), 0xFC,
"Command Type", HFILL}
},
{ &hf_frame_type,
{ "Frame type", "btrfcomm.frame_type",
FT_UINT8, BASE_HEX, VALS(vs_frame_type), 0xEF,
"Command/Response flag", HFILL}
},
{ &hf_pf,
{ "P/F flag", "btrfcomm.pf",
FT_UINT8, BASE_HEX, NULL, 0x10,
"Poll/Final bit", HFILL}
},
{ &hf_pn_i14,
{ "Type of frame", "btrfcomm.pn.i",
FT_UINT8, BASE_HEX, VALS(vs_ctl_pn_i), 0x0F,
"Type of information frames used for that particular DLCI",
HFILL}
},
{ &hf_pn_c14,
{ "Convergence layer", "btrfcomm.pn.cl",
FT_UINT8, BASE_HEX, VALS(vs_ctl_pn_cl), 0xF0,
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
FT_UINT8, BASE_HEX, NULL, 0x02,
"Flow Control", HFILL}
},
{ &hf_msc_rtc,
{ "Ready To Communicate (RTC)", "btrfcomm.msc.rtc",
FT_UINT8, BASE_HEX, NULL, 0x04,
"Ready To Communicate", HFILL}
},
{ &hf_msc_rtr,
{ "Ready To Receive (RTR)", "btrfcomm.msc.rtr",
FT_UINT8, BASE_HEX, NULL, 0x08,
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
FT_UINT8, BASE_DEC, NULL, 0xF0,
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
&ett_ctrl_pn_v24,
&ett_dlci,
&ett_mcc_dlci
};
static ei_register_info ei[] = {
{ &ei_btrfcomm_mcc_length_bad, { "btrfcomm.mcc_length_bad", PI_MALFORMED, PI_ERROR, "Huge MCC length", EXPFILL }},
};
proto_btrfcomm = proto_register_protocol("Bluetooth RFCOMM Protocol", "BT RFCOMM", "btrfcomm");
register_dissector("btrfcomm", dissect_btrfcomm, proto_btrfcomm);
proto_register_field_array(proto_btrfcomm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_btrfcomm = expert_register_protocol(proto_btrfcomm);
expert_register_field_array(expert_btrfcomm, ei, array_length(ei));
rfcomm_service_dissector_table = register_dissector_table("btrfcomm.service", "BT RFCOMM Service", FT_UINT16, BASE_HEX);
rfcomm_channel_dissector_table = register_dissector_table("btrfcomm.channel", "BT RFCOMM Channel", FT_UINT16, BASE_DEC);
module = prefs_register_protocol(proto_btrfcomm, NULL);
prefs_register_static_text_preference(module, "rfcomm.version",
"Bluetooth Protocol RFCOMM version: 1.1", "Version of protocol supported by this dissector.");
prefs_register_bool_preference(module, "rfcomm.decode_by.enabled",
"Enable Force Decode by Channel",
"Turn on/off decode by next rules",
&rfcomm_channels_enabled);
uat_rfcomm_channels = uat_new("Force Decode by Channel",
sizeof(uat_rfcomm_channels_t),
"rfcomm_channels",
TRUE,
(void**) &rfcomm_channels,
&num_rfcomm_channels,
UAT_AFFECTS_DISSECTION,
NULL,
NULL,
NULL,
NULL,
NULL,
uat_rfcomm_channels_fields);
prefs_register_uat_preference(module, "rfcomm.channels",
"Force Decode by channel",
"Decode by channel",
uat_rfcomm_channels);
}
static int
btrfcomm_sdp_tap_packet(void *arg _U_, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *arg2)
{
const sdp_package_t *sdp_package = (const sdp_package_t *) arg2;
if (sdp_service_infos == NULL) {
sdp_service_infos = sdp_package->service_infos;
}
return 0;
}
void
proto_reg_handoff_btrfcomm(void)
{
dissector_handle_t btrfcomm_handle;
btrfcomm_handle = find_dissector("btrfcomm");
dissector_add_uint("btl2cap.psm", BTL2CAP_PSM_RFCOMM, btrfcomm_handle);
dissector_add_handle("btl2cap.cid", btrfcomm_handle);
data_handle = find_dissector("data");
register_tap_listener("btsdp", NULL, NULL, TL_IS_DISSECTOR_HELPER, NULL, btrfcomm_sdp_tap_packet, NULL);
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
for(i = 0; i < length && is_at_cmd; i++) {
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
&ett_btdun
};
proto_btdun = proto_register_protocol("Bluetooth DUN Packet", "BT DUN", "btdun");
register_dissector("btdun", dissect_btdun, proto_btdun);
proto_register_field_array(proto_btdun, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btdun(void)
{
dissector_handle_t btdun_handle;
btdun_handle = find_dissector("btdun");
dissector_add_uint("btrfcomm.service", BTSDP_DUN_SERVICE_UUID, btdun_handle);
dissector_add_handle("btrfcomm.channel", btdun_handle);
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
length = MIN(length, 60);
ascii_only = TRUE;
for(i = 0; i < length && ascii_only; i++) {
ascii_only = tvb_get_guint8(tvb, i) < 0x80;
}
if (ascii_only) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s \"%s%s\"",
(pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd",
tvb_format_text(tvb, 0, length),
(tvb_length(tvb) > length) ? "..." : "");
}
proto_tree_add_item(st, hf_spp_data, tvb, 0, -1, ENC_NA);
}
void
proto_register_btspp(void)
{
static hf_register_info hf[] = {
{ &hf_spp_data,
{ "Data", "btspp.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btspp
};
proto_btspp = proto_register_protocol("Bluetooth SPP Packet", "BT SPP", "btspp");
register_dissector("btspp", dissect_btspp, proto_btspp);
proto_register_field_array(proto_btspp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btspp(void)
{
dissector_handle_t btspp_handle;
btspp_handle = find_dissector("btspp");
dissector_add_uint("btrfcomm.service", BTSDP_SPP_SERVICE_UUID, btspp_handle);
dissector_add_handle("btrfcomm.channel", btspp_handle);
}
static void
dissect_btgnss(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *main_item;
proto_tree *main_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GNSS");
main_item = proto_tree_add_item(tree, proto_btgnss, tvb, 0, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_btgnss);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
(pinfo->p2p_dir == P2P_DIR_SENT) ? "Sent" : "Rcvd",
tvb_format_text(tvb, 0, tvb_length(tvb)));
proto_tree_add_item(main_tree, hf_gnss_data, tvb, 0, -1, ENC_NA | ENC_ASCII);
}
void
proto_register_btgnss(void)
{
static hf_register_info hf[] = {
{ &hf_gnss_data,
{ "Data", "btgnss.data",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_btgnss
};
proto_btgnss = proto_register_protocol("Bluetooth GNSS Profile", "BT GNSS", "btgnss");
register_dissector("btgnss", dissect_btgnss, proto_btgnss);
proto_register_field_array(proto_btgnss, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_btgnss(void)
{
dissector_handle_t btgnss_handle;
btgnss_handle = find_dissector("btgnss");
dissector_add_uint("btrfcomm.service", BTSDP_GNSS_UUID, btgnss_handle);
dissector_add_uint("btrfcomm.service", BTSDP_GNSS_SERVER_UUID, btgnss_handle);
dissector_add_handle("btrfcomm.channel", btgnss_handle);
}
