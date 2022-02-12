static gboolean mausb_is_from_host(struct mausb_header *header)
{
return (MAUSB_FLAG_HOST << MAUSB_FLAG_OFFSET) & header->ver_flags;
}
static gboolean mausb_is_mgmt_pkt(struct mausb_header *header)
{
return MAUSB_PKT_TYPE_MGMT == (header->type & MAUSB_PKT_TYPE_MASK);
}
static gboolean mausb_is_data_pkt(struct mausb_header *header)
{
return MAUSB_PKT_TYPE_DATA == (header->type & MAUSB_PKT_TYPE_MASK);
}
static guint mausb_get_pkt_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_letohs(tvb, offset + 2);
}
static gint dissect_ep_handle(proto_tree *tree, tvbuff_t *tvb, gint offset)
{
proto_item *ti;
proto_tree *ep_handle_tree;
ti = proto_tree_add_item(tree, hf_mausb_ep_handle, tvb,
offset, MAUSB_SIZE_EP_HANDLE, ENC_LITTLE_ENDIAN);
ep_handle_tree = proto_item_add_subtree(ti, ett_mausb_ep_handle);
proto_tree_add_item(ep_handle_tree, hf_mausb_ep_handle_d, tvb,
offset, MAUSB_SIZE_EP_HANDLE, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_handle_tree, hf_mausb_ep_handle_ep_num, tvb,
offset, MAUSB_SIZE_EP_HANDLE, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_handle_tree, hf_mausb_ep_handle_dev_addr, tvb,
offset, MAUSB_SIZE_EP_HANDLE, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ep_handle_tree, hf_mausb_ep_handle_bus_num, tvb,
offset, MAUSB_SIZE_EP_HANDLE, ENC_LITTLE_ENDIAN);
return MAUSB_SIZE_EP_HANDLE;
}
static guint8 mausb_get_size_ep_des(tvbuff_t *tvb, gint offset)
{
guint8 size_ep_des = 0;
guint16 temp_buffer = 0;
temp_buffer = tvb_get_letohs(tvb, offset);
temp_buffer = temp_buffer & MAUSB_MGMT_SIZE_EP_DES_MASK;
size_ep_des = (temp_buffer >> MAUSB_MGMT_SIZE_EP_DES_OFFSET);
return size_ep_des;
}
static guint16 dissect_mausb_mgmt_pkt_ep_handle( proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, gint16 start, gboolean req, gboolean del)
{
usb_trans_info_t usb_trans_info;
usb_conv_info_t usb_conv_info;
proto_item *size_field = NULL;
guint16 offset = start;
guint16 loop_offset;
guint8 num_ep;
guint8 size_ep_des;
int i;
memset(&usb_trans_info, 0, sizeof(usb_trans_info_t));
memset(&usb_conv_info, 0, sizeof(usb_conv_info_t));
num_ep = tvb_get_guint8(tvb, offset) & MAUSB_MGMT_NUM_EP_DES_MASK;
if (!del) {
proto_tree_add_item(tree, hf_mausb_mgmt_ep_des_num, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mausb_mgmt_ep_handle_num, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
if (req && !del) {
size_ep_des = mausb_get_size_ep_des(tvb, offset);
size_field = proto_tree_add_item(tree, hf_mausb_mgmt_ep_des_size, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mausb_mgmt_ep_des_pad, tvb,
offset, 3, ENC_NA);
offset += 3;
} else if (!req && !del) {
size_ep_des = MAUSB_SIZE_MAUSB_EP_DES;
proto_tree_add_item(tree, hf_mausb_mgmt_ep_handle_pad, tvb,
offset, 4, ENC_NA);
offset += 4;
} else {
size_ep_des = MAUSB_SIZE_EP_HANDLE;
proto_tree_add_item(tree, hf_mausb_mgmt_ep_handle_pad, tvb,
offset, 4, ENC_NA);
offset += 4;
}
for (i = 0; i < num_ep; ++i) {
loop_offset = offset;
if (del) {
loop_offset += dissect_ep_handle(tree, tvb, loop_offset);
} else if (req && !del) {
dissect_usb_endpoint_descriptor(pinfo, tree, tvb, loop_offset,
&usb_trans_info, &usb_conv_info);
loop_offset += USB_DT_EP_SIZE;
if (MAUSB_EP_DES_SIZE < size_ep_des) {
dissect_usb_unknown_descriptor(pinfo, tree,
tvb, loop_offset, &usb_trans_info, &usb_conv_info);
loop_offset += USB_DT_SS_EP_COMP_SIZE;
if (MAUSB_SS_EP_DES_SIZE < size_ep_des) {
loop_offset += dissect_usb_unknown_descriptor(pinfo, tree,
tvb, loop_offset, &usb_trans_info, &usb_conv_info);
proto_tree_add_item(tree, hf_mausb_ep_handle_req_pad, tvb,
loop_offset, MAUSB_ISO_SSP_EP_DES_PAD, ENC_NA);
loop_offset += MAUSB_ISO_SSP_EP_DES_PAD;
} else {
proto_tree_add_item(tree, hf_mausb_ep_handle_req_pad, tvb,
loop_offset, MAUSB_SS_EP_DES_PAD, ENC_NA);
loop_offset += MAUSB_SS_EP_DES_PAD;
}
} else {
proto_tree_add_item(tree, hf_mausb_ep_handle_req_pad, tvb,
loop_offset, MAUSB_EP_DES_PAD, ENC_NA);
loop_offset += MAUSB_EP_DES_PAD;
}
} else {
loop_offset += dissect_ep_handle(tree, tvb, loop_offset);
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_dir, tvb,
loop_offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_iso, tvb,
loop_offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_lman, tvb,
loop_offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_valid, tvb,
loop_offset, 1, ENC_LITTLE_ENDIAN);
loop_offset += 2;
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_ccu, tvb,
loop_offset, 2, ENC_LITTLE_ENDIAN);
loop_offset += 2;
loop_offset += 2;
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_buf_size, tvb,
loop_offset, 4, ENC_LITTLE_ENDIAN);
loop_offset += 4;
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_iso_prog_dly, tvb,
loop_offset, 2, ENC_LITTLE_ENDIAN);
loop_offset += 2;
proto_tree_add_item(tree, hf_mausb_ep_handle_resp_iso_resp_dly, tvb,
loop_offset, 2, ENC_LITTLE_ENDIAN);
loop_offset += 2;
}
offset += size_ep_des;
if (req && !del && loop_offset != offset){
expert_add_info(pinfo, size_field, &ei_ep_handle_len);
}
}
return offset;
}
static guint16 dissect_mausb_mgmt_pkt_flds(struct mausb_header *header,
proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, gint16 start)
{
proto_item *ti;
proto_tree *mgmt_tree;
guint16 offset = start;
gint type_spec_len = tvb_reported_length(tvb) - start;
if (0 > type_spec_len) {
expert_add_info(pinfo, tree, &ei_mgmt_type_spec_len_short);
return offset;
}
ti = proto_tree_add_item(tree, hf_mausb_mgmt_type_spec, tvb,
offset, type_spec_len, ENC_NA);
mgmt_tree = proto_item_add_subtree(ti, ett_mgmt);
switch (header->type) {
case EPHandleReq:
offset = dissect_mausb_mgmt_pkt_ep_handle(mgmt_tree, tvb, pinfo,
offset, TRUE, FALSE);
break;
case EPHandleResp:
offset = dissect_mausb_mgmt_pkt_ep_handle(mgmt_tree, tvb, pinfo,
offset, FALSE, FALSE);
break;
case EPActivateReq:
case EPActivateResp:
case EPInactivateReq:
case EPInactivateResp:
case EPRestartReq:
case EPRestartResp:
case EPClearTransferReq:
case EPClearTransferResp:
case EPHandleDeleteReq:
offset = dissect_mausb_mgmt_pkt_ep_handle(mgmt_tree, tvb, pinfo,
offset, TRUE, TRUE);
break;
case EPHandleDeleteResp:
offset = dissect_mausb_mgmt_pkt_ep_handle(mgmt_tree, tvb, pinfo,
offset, FALSE, TRUE);
break;
case ModifyEP0Resp:
case EPCloseStreamResp:
case USBDevResetReq:
case USBDevResetResp:
case EPOpenStreamResp:
case VendorSpecificReq:
case VendorSpecificResp:
case CapReq:
case CapResp:
case USBDevHandleReq:
case USBDevHandleResp:
case ModifyEP0Req:
case SetDevAddrResp:
case UpdateDevReq:
case MAUSBSyncReq:
case EPCloseStreamReq:
case CancelTransferReq:
case CancelTransferResp:
case EPOpenStreamReq:
proto_tree_add_item(mgmt_tree, hf_mausb_mgmt_type_spec_generic,
tvb, offset, type_spec_len, ENC_NA);
offset += type_spec_len;
break;
case MAUSBDevResetReq:
case MAUSBDevResetResp:
case SetDevAddrReq:
case UpdateDevResp:
case DisconnectDevReq:
case DisconnectDevResp:
case MAUSBDevSleepReq:
case MAUSBDevSleepResp:
case MAUSBDevWakeReq:
case MAUSBDevWakeResp:
case MAUSBDevInitSleepReq:
case MAUSBDevInitSleepResp:
case MAUSBDevRemoteWakeReq:
case MAUSBDevRemoteWakeResp:
case PingReq:
case PingResp:
case MAUSBDevDisconnectReq:
case MAUSBDevDisconnectResp:
case MAUSBDevInitDisconReq:
case MAUSBDevInitDisconResp:
case MAUSBSyncResp:
break;
default:
expert_add_info(pinfo, mgmt_tree, &ei_mgmt_type_undef);
break;
}
if (offset < tvb_reported_length(tvb)) {
expert_add_info(pinfo, mgmt_tree, &ei_mgmt_type_spec_len_long);
}
return offset;
}
static int
dissect_mausb_pkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti;
proto_item *len_field;
proto_tree *mausb_tree;
proto_tree *flags_tree;
proto_tree *tflags_tree;
struct mausb_header header;
gint offset = 0;
gint payload_len;
memset(&header, 0, sizeof(struct mausb_header));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAUSB");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_mausb, tvb, 0,
mausb_get_pkt_len(pinfo, tvb, offset), ENC_NA);
mausb_tree = proto_item_add_subtree(ti, ett_mausb);
header.ver_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_version, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_item(mausb_tree, hf_mausb_flags, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
flags_tree = proto_item_add_subtree(ti, ett_mausb_flags);
proto_tree_add_item(flags_tree, hf_mausb_flag_host, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mausb_flag_retry, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mausb_flag_timestamp, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(flags_tree, hf_mausb_flag_reserved, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(header.type, mausb_type_string, "%d"));
proto_tree_add_item(mausb_tree, hf_mausb_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.length = tvb_get_letohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " Length=%u", header.length);
len_field = proto_tree_add_item(mausb_tree, hf_mausb_length, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (tvb_reported_length(tvb) != header.length) {
expert_add_info(pinfo, len_field, &ei_len);
}
if (0 != header.length % 4) {
expert_add_info(pinfo, len_field, &ei_len_dword);
}
header.handle = tvb_get_letohs(tvb, offset);
if (mausb_is_mgmt_pkt(&header)) {
proto_tree_add_item(mausb_tree, hf_mausb_dev_handle, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
offset += dissect_ep_handle(mausb_tree, tvb, offset);
}
header.ma_dev_addr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_ma_dev_addr, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.mass_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_ssid, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_status, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (mausb_is_mgmt_pkt(&header)) {
header.u.token = tvb_get_letohs(tvb, 9) & MAUSB_TOKEN_MASK;
col_append_fstr(pinfo->cinfo, COL_INFO, " Token=%u", header.u.token);
proto_tree_add_item(mausb_tree, hf_mausb_token, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(mausb_tree, hf_mausb_mgmt_pad, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset < header.length) {
offset = dissect_mausb_mgmt_pkt_flds(&header, mausb_tree, tvb,
pinfo, offset);
}
}
else if (mausb_is_data_pkt(&header)) {
header.u.s.eps_tflags = tvb_get_guint8(tvb, offset);
if (mausb_is_from_host(&header)) {
proto_tree_add_item(mausb_tree, hf_mausb_eps_rsvd, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(mausb_tree, hf_mausb_eps, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
ti = proto_tree_add_item(mausb_tree, hf_mausb_tflags, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
tflags_tree = proto_item_add_subtree(ti, ett_mausb_tflags);
proto_tree_add_item(tflags_tree, hf_mausb_tflag_arq, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tflags_tree, hf_mausb_tflag_neg, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tflags_tree, hf_mausb_tflag_eot, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tflags_tree, hf_mausb_tflag_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tflags_tree, hf_mausb_tflag_rsvd, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.u.s.stream_id = tvb_get_letohs(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_stream_id, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
header.u.s.seq_num = tvb_get_letoh24(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " SeqNum=%u", header.u.s.seq_num);
proto_tree_add_item(mausb_tree, hf_mausb_seq_num, tvb,
offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
header.u.s.req_id = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " ReqID=%u", header.u.s.req_id);
proto_tree_add_item(mausb_tree, hf_mausb_req_id, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header.u.s.credit = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_rem_size_credit, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
payload_len = header.length - offset;
if (0 < payload_len) {
proto_tree_add_item(mausb_tree, hf_mausb_payload, tvb,
offset, payload_len, ENC_NA);
offset += payload_len;
}
}
return offset;
}
static int
dissect_mausb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, MAUSB_MIN_LENGTH,
mausb_get_pkt_len, dissect_mausb_pkt, data);
return tvb_reported_length(tvb);
}
void
proto_register_mausb(void)
{
static hf_register_info hf[] = {
{ &hf_mausb_version,
{ "Version", "mausb.version", FT_UINT8, BASE_DEC,
VALS(mausb_version_string), MAUSB_VERSION_MASK, NULL, HFILL
}
},
{ &hf_mausb_flags,
{ "Flags", "mausb.flags", FT_UINT8, BASE_HEX,
VALS(mausb_flag_string), MAUSB_FLAG_MASK, NULL, HFILL
}
},
{ &hf_mausb_flag_host,
{ "Host", "mausb.flags.host", FT_BOOLEAN, 4,
TFS(&tfs_set_notset), MAUSB_FLAG_HOST,
NULL, HFILL
}
},
{ &hf_mausb_flag_retry,
{ "Retry", "mausb.flags.retry", FT_BOOLEAN, 4,
TFS(&tfs_yes_no), MAUSB_FLAG_RETRY,
NULL, HFILL
}
},
{ &hf_mausb_flag_timestamp,
{ "Timestamp", "mausb.flags.timestamp", FT_BOOLEAN, 4,
TFS(&tfs_present_not_present),
MAUSB_FLAG_TIMESTAMP,
NULL, HFILL
}
},
{ &hf_mausb_flag_reserved,
{ "Reserved", "mausb.flags.reserved", FT_BOOLEAN, 4,
TFS(&tfs_set_notset), MAUSB_FLAG_RESERVED,
NULL, HFILL
}
},
{ &hf_mausb_type,
{ "Type", "mausb.type", FT_UINT8, BASE_HEX,
VALS(mausb_type_string), 0, NULL, HFILL
}
},
{ &hf_mausb_length,
{ "Length", "mausb.length", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_dev_handle,
{ "Device Handle", "mausb.dev_handle", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle,
{ "Endpoint Handle", "mausb.ep_handle", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_d,
{ "Direction", "mausb.ep_handle.d", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), MAUSB_EP_HANDLE_D, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_ep_num,
{ "Endpoint Number", "mausb.ep_handle.ep_num", FT_UINT16, BASE_DEC,
NULL, MAUSB_EP_HANDLE_EP_NUM, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_dev_addr,
{ "USB Device Address", "mausb.ep_handle.dev_addr", FT_UINT16, BASE_DEC,
NULL, MAUSB_EP_HANDLE_DEV_ADDR, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_bus_num,
{ "USB Bus Number", "mausb.ep_handle.bus_num", FT_UINT16, BASE_DEC,
NULL, MAUSB_EP_HANDLE_BUS_NUM, NULL, HFILL
}
},
{ &hf_mausb_ma_dev_addr,
{ "MA Device Address", "mausb.ma_dev_addr", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ssid,
{ "Service Set ID", "mausb.ssid", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_status,
{ "Status", "mausb.status", FT_UINT8, BASE_DEC,
VALS(mausb_status_string), 0, NULL, HFILL
}
},
{ &hf_mausb_token,
{ "Token", "mausb.token", FT_UINT16, BASE_DEC,
NULL, MAUSB_TOKEN_MASK, NULL, HFILL
}
},
{ &hf_mausb_mgmt_pad,
{ "Padding to a DWORD", "mausb.mgmt_pad",
FT_UINT16, BASE_HEX, NULL, MAUSB_MGMT_PAD_MASK,
NULL, HFILL
}
},
{ &hf_mausb_mgmt_type_spec,
{ "Type-specific managment packet fields", "mausb.mgmt_flds",
FT_NONE, 0, NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_mgmt_type_spec_generic,
{ "Type-specific managment packet fields", "mausb.mgmt_flds.generic",
FT_NONE, 0, NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_eps,
{ "EP Status", "mausb.eps", FT_UINT8, BASE_HEX,
VALS(mausb_eps_string), MAUSB_EPS_MASK, NULL, HFILL
}
},
{ &hf_mausb_eps_rsvd,
{ "EP Status", "mausb.eps.reserved", FT_UINT8, BASE_HEX,
NULL, MAUSB_EPS_MASK, NULL, HFILL
}
},
{ &hf_mausb_tflags,
{ "Transfer Flags", "mausb.tflag", FT_UINT8, BASE_HEX,
VALS(mausb_tflag_string), MAUSB_TFLAG_MASK, NULL, HFILL
}
},
{ &hf_mausb_tflag_arq,
{ "ARQ", "mausb.tflag.arq", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_TFLAG_ARQ << MAUSB_TFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_tflag_neg,
{ "NEG", "mausb.tflag.neg", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_TFLAG_NEG << MAUSB_TFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_tflag_eot,
{ "EoT", "mausb.tflag.eot", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_TFLAG_EOT << MAUSB_TFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_tflag_type,
{ "Transfer Type", "mausb.tflag.type", FT_UINT8, BASE_HEX,
VALS(mausb_transfer_type_string),
MAUSB_TFLAG_TRANSFER_TYPE << MAUSB_TFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_tflag_rsvd,
{ "Reserved", "mausb.tflag.rsvd", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_TFLAG_RSVD << MAUSB_TFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_stream_id,
{ "Stream ID", "mausb.streamid", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_seq_num,
{ "Sequence Number", "mausb.seqnum", FT_UINT24, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_req_id,
{ "Request ID", "mausb.reqid", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_rem_size_credit,
{ "Remaining Size/Credit", "mausb.remsize_credit", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_payload,
{ "USB Data Payload", "mausb.payload", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
}
};
static hf_register_info hf_ep_handle[] = {
{ &hf_mausb_mgmt_ep_handle_num,
{ "Number of Endpoint Handles", "mausb.ep_handle_num",
FT_UINT8, BASE_DEC,
NULL, MAUSB_MGMT_NUM_EP_DES_MASK, NULL, HFILL
}
},
{ &hf_mausb_mgmt_ep_handle_pad,
{ "Padding to a DWORD", "mausb.ep_handle_pad",
FT_NONE, 0,
NULL, MAUSB_MGMT_NUM_EP_HANDLE_PAD_MASK, NULL, HFILL
}
},
{ &hf_mausb_mgmt_ep_des_num,
{ "Number of Endpoint Descriptors", "mausb.ep_des_num",
FT_UINT8, BASE_DEC,
NULL, MAUSB_MGMT_NUM_EP_DES_MASK, NULL, HFILL
}
},
{ &hf_mausb_mgmt_ep_des_size,
{ "Size of Endpoint Descriptors", "mausb.ep_des_size",
FT_UINT16, BASE_DEC,
NULL, MAUSB_MGMT_SIZE_EP_DES_MASK, NULL, HFILL
}
},
{ &hf_mausb_mgmt_ep_des_pad,
{ "Padding to a DWORD", "mausb.ep_des_pad",
FT_NONE, 0, NULL,
MAUSB_MGMT_EP_DES_PAD_MASK,
NULL, HFILL
}
},
{ &hf_mausb_ep_handle_req_pad,
{ "Padding to a DWORD", "mausb.ep_handle_req.pad",
FT_NONE, 0, NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_dir,
{ "Direction", "mausb.ep_dir", FT_BOOLEAN, 6,
TFS(&tfs_ep_handle_resp_dir), MAUSB_EP_HANDLE_RESP_DIR_MASK,
NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_iso,
{ "Isochronous", "mausb.ep_iso", FT_BOOLEAN, 6,
TFS(&tfs_yes_no), MAUSB_EP_HANDLE_RESP_ISO_MASK, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_lman,
{ "L-Managed", "mausb.ep_lman", FT_BOOLEAN, 6,
TFS(&tfs_supported_not_supported), MAUSB_EP_HANDLE_RESP_LMAN_MASK,
NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_valid,
{ "Valid", "mausb.ep_valid", FT_BOOLEAN, 6,
TFS(&tfs_invalid_valid), MAUSB_EP_HANDLE_RESP_VALID_MASK,
NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_ccu,
{ "CCU", "mausb.ep_ccu", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_buf_size,
{ "Buffer Size", "mausb.ep_buf_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_iso_prog_dly,
{ "Iso Programming Delay", "mausb.ep_iso_prog_dly", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_ep_handle_resp_iso_resp_dly,
{ "Iso Response Delay", "mausb.ep_iso_resp_dly", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_mausb,
&ett_mausb_flags,
&ett_mausb_ep_handle,
&ett_mausb_tflags,
&ett_mgmt
};
static ei_register_info ei[] = {
{ &ei_ep_handle_len,
{ "mausb.ep_handle.length", PI_PROTOCOL, PI_WARN,
"Invalid Endpoint handle length field", EXPFILL }
},
{ &ei_len,
{ "mausb.length", PI_MALFORMED, PI_ERROR,
"Packet length field does not match size of packet", EXPFILL }
},
{ &ei_len_dword,
{ "mausb.length", PI_PROTOCOL, PI_WARN,
"Packet contains partial DWORD", EXPFILL }
},
{ &ei_mgmt_type_undef,
{ "mausb.type", PI_PROTOCOL, PI_WARN,
"Undefined managment packet type", EXPFILL }
},
{ &ei_mgmt_type_spec_len_long,
{ "mausb.type_spec.len", PI_PROTOCOL, PI_WARN,
"Data exists after type-specific managment packet field", EXPFILL }
},
{ &ei_mgmt_type_spec_len_short,
{ "mausb.type_spec.len", PI_PROTOCOL, PI_WARN,
"Expected type-specific managment packet data", EXPFILL }
},
};
module_t *mausb_module;
expert_module_t* expert_mausb;
proto_mausb = proto_register_protocol("Media Agnostic USB",
"MAUSB", "mausb");
proto_register_field_array(proto_mausb, hf, array_length(hf));
proto_register_field_array(proto_mausb, hf_ep_handle, array_length(hf_ep_handle));
proto_register_subtree_array(ett, array_length(ett));
expert_mausb = expert_register_protocol(proto_mausb);
expert_register_field_array(expert_mausb, ei, array_length(ei));
mausb_module = prefs_register_protocol(proto_mausb, proto_reg_handoff_mausb);
prefs_register_uint_preference(mausb_module, "tcp.port", "MAUSB TCP Port",
"Set the port for Media Agnostic Packets",
10, &gPORT_PREF);
}
void
proto_reg_handoff_mausb(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t mausb_tcp_handle;
static dissector_handle_t mausb_snap_handle;
if (!initialized) {
mausb_tcp_handle = new_create_dissector_handle(dissect_mausb,
proto_mausb);
mausb_snap_handle = new_create_dissector_handle(dissect_mausb_pkt,
proto_mausb);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", gPORT_PREF, mausb_tcp_handle);
}
dissector_add_uint("llc.mausb_pid", PID_MAUSB, mausb_snap_handle);
dissector_add_uint("tcp.port", gPORT_PREF, mausb_tcp_handle);
}
void
proto_register_mausb_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_mausb_pid,
{ "PID", "mausb.pid", FT_UINT16, BASE_HEX,
VALS(mausb_pid_string), 0x0, NULL, HFILL }
}
};
llc_add_oui(OUI_MAUSB, "llc.mausb_pid", "LLC MA USB OUI PID", hf);
}
