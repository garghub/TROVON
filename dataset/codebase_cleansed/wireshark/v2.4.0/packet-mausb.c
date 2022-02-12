gboolean mausb_is_from_host(struct mausb_header *header)
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
static gboolean mausb_is_transfer_req(struct mausb_header *header)
{
return TransferReq == header->type;
}
static gboolean mausb_is_transfer_ack(struct mausb_header *header)
{
return TransferAck == header->type;
}
static gint8 mausb_tx_type(struct mausb_header *header)
{
return (header->u.s.eps_tflags >> MAUSB_TFLAG_OFFSET) & MAUSB_TFLAG_TRANSFER_TYPE;
}
static gboolean mausb_is_iso_pkt(struct mausb_header *header)
{
return MAUSB_TX_TYPE_ISOC == mausb_tx_type(header);
}
static gboolean mausb_has_timestamp(struct mausb_header *header)
{
return (MAUSB_FLAG_TIMESTAMP << MAUSB_FLAG_OFFSET) & header->ver_flags;
}
static gboolean mausb_has_mtd(struct mausb_header *header)
{
return (MAUSB_IFLAG_MTD << MAUSB_IFLAG_OFFSET) & header->u.s.u1.num_headers_iflags;
}
static gboolean mausb_has_setup_data(struct mausb_header *header)
{
if ((TransferReq == header->type ) &&
(mausb_is_from_host(header)) &&
(0 == header->u.s.seq_num) &&
(MAUSB_TX_TYPE_CTRL == mausb_tx_type(header))) {
return TRUE;
}
return FALSE;
}
static gboolean mausb_is_setup_response(struct mausb_header *header)
{
if ((TransferResp == header->type) &&
(!mausb_is_from_host(header)) &&
(MAUSB_TX_TYPE_CTRL == mausb_tx_type(header))) {
return TRUE;
}
return FALSE;
}
guint8 mausb_ep_handle_ep_num(guint16 handle) {
return (handle & MAUSB_EP_HANDLE_EP_NUM) >> MAUSB_EP_HANDLE_EP_NUM_OFFSET;
}
guint8 mausb_ep_handle_dev_addr(guint16 handle) {
return (handle & MAUSB_EP_HANDLE_DEV_ADDR) >> MAUSB_EP_HANDLE_DEV_ADDR_OFFSET;
}
guint8 mausb_ep_handle_bus_num(guint16 handle) {
return (handle & MAUSB_EP_HANDLE_BUS_NUM) >> MAUSB_EP_HANDLE_BUS_NUM_OFFSET;
}
static guint mausb_get_pkt_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
return tvb_get_letohs(tvb, offset + 2);
}
static guint16 dissect_mausb_dev_cap_desc(proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, gint16 offset)
{
guint8 desc_len;
guint8 cap_type;
gint16 desc_offset;
proto_item *len_field;
proto_tree *dev_cap_tree;
desc_offset = offset;
desc_len = tvb_get_guint8(tvb, desc_offset);
cap_type = tvb_get_guint8(tvb, desc_offset + 1);
dev_cap_tree = proto_tree_add_subtree(tree, tvb, desc_offset, desc_len,
ett_dev_cap, NULL,
val_to_str_const(cap_type, mausb_dev_cap_string, "Unknown Capability"));
len_field = proto_tree_add_item(dev_cap_tree, hf_mausb_dev_cap_len,
tvb, desc_offset, 1, ENC_LITTLE_ENDIAN);
desc_offset += 1;
proto_tree_add_item(dev_cap_tree, hf_mausb_dev_cap_type,
tvb, desc_offset, 1, ENC_LITTLE_ENDIAN);
desc_offset += 1;
if (desc_len > 2) {
switch (cap_type) {
case SpeedCap:
case PmanCap:
case IsoCap:
case SyncCap:
case ContainerIDCap:
case LinkSleepCap:
default:
proto_tree_add_item(dev_cap_tree, hf_mausb_dev_cap_generic,
tvb, desc_offset, (desc_len - 2), ENC_NA);
desc_offset += (desc_len - 2);
break;
}
}
if (desc_offset != offset + desc_len) {
expert_add_info(pinfo, len_field, &ei_dev_cap_len);
}
return offset + desc_len;
}
static guint16 dissect_mausb_mgmt_pkt_cap_resp(struct mausb_header *header,
proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint16 offset)
{
guint desc_len;
guint8 desc_count;
proto_item *len_field;
guint16 loop_offset;
int i;
proto_tree_add_item(tree, hf_mausb_cap_resp_num_ep,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mausb_cap_resp_num_dev,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mausb_cap_resp_num_stream,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_cap_resp_dev_type,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mausb_cap_resp_desc_count,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
desc_count = tvb_get_guint8(tvb, offset);
offset += 1;
len_field = proto_tree_add_item(tree, hf_mausb_cap_resp_desc_len,
tvb, offset, 3, ENC_LITTLE_ENDIAN);
desc_len = tvb_get_letoh24(tvb, offset);
offset += 3;
proto_tree_add_item(tree, hf_mausb_cap_resp_transfer_req,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mausb_cap_resp_mgmt_req,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_cap_resp_rsvd,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (offset + desc_len > header->length) {
expert_add_info(pinfo, len_field, &ei_cap_resp_desc_len);
desc_len = header->length - offset;
}
loop_offset = offset;
for (i = 0; i < desc_count; i++) {
loop_offset = dissect_mausb_dev_cap_desc(tree, tvb, pinfo, loop_offset);
}
if (loop_offset != offset + desc_len) {
expert_add_info(pinfo, len_field, &ei_dev_cap_resp_desc_len);
desc_len = header->length - offset;
}
return offset + desc_len;
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
static void dissect_mausb_present_time(proto_tree *tree, tvbuff_t *tvb,
gint offset)
{
proto_item *ti;
proto_tree *present_time_tree;
ti = proto_tree_add_item(tree, hf_mausb_present_time, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
present_time_tree = proto_item_add_subtree(ti, ett_mausb_present_time);
proto_tree_add_item(present_time_tree, hf_mausb_uframe, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_time_tree, hf_mausb_frame, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
}
static void dissect_mausb_timestamp(proto_tree *tree, tvbuff_t *tvb,
gint offset)
{
proto_item *ti;
proto_tree *timestamp_tree;
ti = proto_tree_add_item(tree, hf_mausb_timestamp, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
timestamp_tree = proto_item_add_subtree(ti, ett_mausb_timestamp);
proto_tree_add_item(timestamp_tree, hf_mausb_delta, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(timestamp_tree, hf_mausb_nom_interval, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
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
static guint16 dissect_clear_transfers_block(proto_tree *tree,
tvbuff_t *tvb, gint16 offset, gboolean req)
{
proto_item *ti;
proto_tree *block_tree;
if (req) {
ti = proto_tree_add_item(tree, hf_mausb_clear_transfers_info_block,
tvb, offset, 8, ENC_NA);
} else {
ti = proto_tree_add_item(tree, hf_mausb_clear_transfers_status_block,
tvb, offset, 16, ENC_NA);
}
block_tree = proto_item_add_subtree(ti, ett_clear_transfers_block);
offset += dissect_ep_handle(block_tree, tvb, offset);
proto_tree_add_item(block_tree, hf_mausb_stream_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
if (req) {
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_start_req_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_req_block_rsvd,
tvb, offset, 3, ENC_NA);
offset += 3;
} else {
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_status,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_partial,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_resp_block_rsvd,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(block_tree, hf_mausb_clear_transfers_last_req_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(block_tree, hf_mausb_cancel_transfer_seq_num, tvb,
offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(block_tree, hf_mausb_cancel_transfer_byte_offset,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
return offset;
}
static guint16 dissect_mausb_mgmt_pkt_clear_transfers(proto_tree *tree,
tvbuff_t *tvb, gint16 offset, gboolean req)
{
guint8 num_block;
int i;
num_block = tvb_get_guint8(tvb, offset);
if (req) {
proto_tree_add_item(tree, hf_mausb_clear_transfers_req_num, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_mausb_clear_transfers_req_rsvd, tvb,
offset, 3, ENC_NA);
offset += 3;
} else {
num_block &= MAUSB_MGMT_CLEAR_TRANSFER_RESP_NUM_MASK;
proto_tree_add_item(tree, hf_mausb_clear_transfers_resp_num, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_clear_transfers_resp_rsvd, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 4;
}
for (i = 0; i < num_block; i++) {
offset = dissect_clear_transfers_block(tree, tvb, offset, req);
}
return offset;
}
static guint16 dissect_mausb_mgmt_pkt_ep_handle( proto_tree *tree, tvbuff_t *tvb,
packet_info *pinfo, gint16 start, gboolean req, gboolean del)
{
usb_conv_info_t usb_conv_info;
proto_item *size_field = NULL;
guint16 offset = start;
guint16 loop_offset;
guint8 num_ep;
guint8 size_ep_des;
int i;
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
} else if (req) {
dissect_usb_endpoint_descriptor(pinfo, tree, tvb, loop_offset,
&usb_conv_info);
loop_offset += USB_DT_EP_SIZE;
if (MAUSB_EP_DES_SIZE < size_ep_des) {
dissect_usb_unknown_descriptor(pinfo, tree,
tvb, loop_offset, &usb_conv_info);
loop_offset += USB_DT_SS_EP_COMP_SIZE;
if (MAUSB_SS_EP_DES_SIZE < size_ep_des) {
loop_offset += dissect_usb_unknown_descriptor(pinfo, tree,
tvb, loop_offset, &usb_conv_info);
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
static guint16 dissect_mausb_mgmt_pkt_cancel_transfer( proto_tree *tree,
tvbuff_t *tvb, gint offset, gboolean req)
{
guint8 status;
offset += dissect_ep_handle(tree, tvb, offset);
proto_tree_add_item(tree, hf_mausb_stream_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_mausb_req_id, tvb, offset, 1,
ENC_LITTLE_ENDIAN);
offset += 1;
if (req) {
proto_tree_add_item(tree, hf_mausb_cancel_transfer_rsvd, tvb, offset, 3,
ENC_NA);
offset += 3;
return offset;
}
status = tvb_get_guint8(tvb, offset) |
MAUSB_CANCEL_TRANSFER_STATUS_MASK;
proto_tree_add_item(tree, hf_mausb_cancel_transfer_status, tvb, offset, 3,
ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_mausb_cancel_transfer_rsvd_2, tvb, offset, 3,
ENC_LITTLE_ENDIAN);
offset += 3;
if (2 == status) {
proto_tree_add_item(tree, hf_mausb_cancel_transfer_seq_num, tvb, offset,
3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_mausb_cancel_transfer_rsvd, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_mausb_cancel_transfer_byte_offset, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(tree, hf_mausb_cancel_transfer_rsvd, tvb, offset, 8,
ENC_NA);
offset += 8;
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
case CapResp:
offset = dissect_mausb_mgmt_pkt_cap_resp(header, mgmt_tree, tvb, pinfo, offset);
break;
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
case EPResetReq:
case EPResetResp:
proto_tree_add_item(mgmt_tree, hf_mausb_mgmt_type_spec_generic,
tvb, offset, type_spec_len, ENC_NA);
offset += type_spec_len;
break;
case ClearTransfersReq:
offset = dissect_mausb_mgmt_pkt_clear_transfers(mgmt_tree, tvb, offset, TRUE);
break;
case ClearTransfersResp:
offset = dissect_mausb_mgmt_pkt_clear_transfers(mgmt_tree, tvb, offset, FALSE);
break;
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
case USBDevHandleReq:
case USBDevHandleResp:
case ModifyEP0Req:
case SetUSBDevAddrReq:
case SetUSBDevAddrResp:
case UpdateDevReq:
case SynchReq:
case EPCloseStreamReq:
proto_tree_add_item(mgmt_tree, hf_mausb_mgmt_type_spec_generic,
tvb, offset, type_spec_len, ENC_NA);
offset += type_spec_len;
break;
case CancelTransferReq:
offset = dissect_mausb_mgmt_pkt_cancel_transfer(mgmt_tree, tvb, offset,
TRUE);
break;
case CancelTransferResp:
offset = dissect_mausb_mgmt_pkt_cancel_transfer(mgmt_tree, tvb, offset,
FALSE);
break;
case EPOpenStreamReq:
proto_tree_add_item(mgmt_tree, hf_mausb_mgmt_type_spec_generic,
tvb, offset, type_spec_len, ENC_NA);
offset += type_spec_len;
break;
case DevResetReq:
case DevResetResp:
case UpdateDevResp:
case USBDevDisconnectReq:
case USBDevDisconnectResp:
case SleepReq:
case SleepResp:
case WakeReq:
case WakeResp:
case PingReq:
case PingResp:
case DevDisconnectReq:
case DevDisconnectResp:
case DevInitDisconnectReq:
case DevInitDisconnectResp:
case SynchResp:
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
void mausb_set_usb_conv_info(usb_conv_info_t *usb_conv_info,
struct mausb_header *header)
{
usb_conv_info->is_request = mausb_is_transfer_req(header);
usb_conv_info->bus_id = mausb_ep_handle_bus_num(header->handle);
usb_conv_info->device_address = mausb_ep_handle_dev_addr(header->handle);
usb_conv_info->direction = mausb_is_from_host(header);
usb_conv_info->endpoint = mausb_ep_handle_ep_num(header->handle);
usb_conv_info->is_setup = mausb_has_setup_data(header) ||
mausb_is_setup_response(header);
switch (mausb_tx_type(header)) {
case MAUSB_TX_TYPE_CTRL:
usb_conv_info->transfer_type = URB_CONTROL;
break;
case MAUSB_TX_TYPE_ISOC:
usb_conv_info->transfer_type = URB_ISOCHRONOUS;
break;
case MAUSB_TX_TYPE_BULK:
usb_conv_info->transfer_type = URB_BULK;
break;
case MAUSB_TX_TYPE_INTR:
usb_conv_info->transfer_type = URB_INTERRUPT;
break;
default:
usb_conv_info->transfer_type = URB_UNKNOWN;
break;
}
}
static int
dissect_mausb_pkt_common(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *mausb_tree, struct mausb_header *header)
{
proto_item *len_field;
header->ver_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_version, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(mausb_tree, tvb, offset, hf_mausb_flags,
ett_mausb_flags, mausb_flag_fields, ENC_LITTLE_ENDIAN);
offset += 1;
header->type = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(header->type, mausb_type_string, "%d"));
proto_tree_add_item(mausb_tree, hf_mausb_type, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header->length = tvb_get_letohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " Length=%u", header->length);
len_field = proto_tree_add_item(mausb_tree, hf_mausb_length, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (tvb_reported_length(tvb) != header->length) {
expert_add_info(pinfo, len_field, &ei_len);
}
header->handle = tvb_get_letohs(tvb, offset);
if (mausb_is_mgmt_pkt(header)) {
proto_tree_add_item(mausb_tree, hf_mausb_dev_handle, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
} else {
offset += dissect_ep_handle(mausb_tree, tvb, offset);
}
header->ma_dev_addr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_ma_dev_addr, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header->mass_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_ssid, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
header->status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_status, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_mausb_pkt_data(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *mausb_tree, struct mausb_header *header)
{
header->u.s.eps_tflags = tvb_get_guint8(tvb, offset);
if (mausb_is_from_host(header)) {
proto_tree_add_item(mausb_tree, hf_mausb_eps_rsvd, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(mausb_tree, hf_mausb_eps, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_bitmask(mausb_tree, tvb, offset, hf_mausb_tflags,
ett_mausb_tflags, mausb_tflag_fields, ENC_LITTLE_ENDIAN);
offset += 1;
if (mausb_is_iso_pkt(header)) {
header->u.s.u1.num_headers_iflags = tvb_get_letohs(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_num_iso_hdr, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(mausb_tree, tvb, offset, hf_mausb_iflags,
ett_mausb_iflags, mausb_iflag_fields, ENC_LITTLE_ENDIAN);
} else {
header->u.s.u1.stream_id = tvb_get_letohs(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_stream_id, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
header->u.s.seq_num = tvb_get_letoh24(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " SeqNum=%u", header->u.s.seq_num);
proto_tree_add_item(mausb_tree, hf_mausb_seq_num, tvb,
offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
header->u.s.req_id = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " ReqID=%u", header->u.s.req_id);
proto_tree_add_item(mausb_tree, hf_mausb_req_id, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (mausb_is_iso_pkt(header)) {
header->u.s.u2.present_time_num_seg = tvb_get_letohl(tvb, offset);
dissect_mausb_present_time(mausb_tree, tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_num_segs, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if (mausb_has_timestamp(header)) {
header->u.s.timestamp = tvb_get_letohl(tvb, offset);
dissect_mausb_timestamp(mausb_tree, tvb, offset);
offset += 4;
}
if (mausb_has_mtd(header)) {
header->u.s.tx_dly = tvb_get_letohl(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_mtd, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
} else {
header->u.s.u2.credit = tvb_get_letohl(tvb, offset);
proto_tree_add_item(mausb_tree, hf_mausb_rem_size_credit, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
return offset;
}
static int
dissect_mausb_pkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti;
proto_tree *mausb_tree;
struct mausb_header header;
gint offset = 0;
memset(&header, 0, sizeof(struct mausb_header));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MAUSB");
mausb_num_pdus++;
col_add_str(pinfo->cinfo, COL_INFO, "[");
col_set_fence(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_mausb, tvb, 0,
mausb_get_pkt_len(pinfo, tvb, offset, NULL), ENC_NA);
mausb_tree = proto_item_add_subtree(ti, ett_mausb);
offset = dissect_mausb_pkt_common(tvb, offset, pinfo, mausb_tree, &header);
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
dissect_mausb_mgmt_pkt_flds(&header, mausb_tree, tvb, pinfo, offset);
}
}
else if (mausb_is_data_pkt(&header)) {
dissect_mausb_pkt_data(tvb, offset, pinfo, mausb_tree, &header);
if (!mausb_is_transfer_ack(&header)) {
dissect_usb_common(tvb, pinfo, tree, USB_HEADER_MAUSB, &header);
}
}
col_append_str(pinfo->cinfo, COL_INFO, "]");
col_set_fence(pinfo->cinfo, COL_INFO);
return header.length;
}
static int
dissect_mausb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
mausb_num_pdus = 0;
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, MAUSB_MIN_LENGTH,
mausb_get_pkt_len, dissect_mausb_pkt, data);
if (1 < mausb_num_pdus) {
col_clear_fence(pinfo->cinfo, COL_INFO);
col_prepend_fstr(pinfo->cinfo, COL_INFO, "[%i packets] ", mausb_num_pdus);
}
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
NULL, MAUSB_FLAG_MASK, NULL, HFILL
}
},
{ &hf_mausb_flag_host,
{ "Host", "mausb.flags.host", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), (MAUSB_FLAG_HOST << MAUSB_FLAG_OFFSET),
NULL, HFILL
}
},
{ &hf_mausb_flag_retry,
{ "Retry", "mausb.flags.retry", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), (MAUSB_FLAG_RETRY << MAUSB_FLAG_OFFSET),
NULL, HFILL
}
},
{ &hf_mausb_flag_timestamp,
{ "Timestamp", "mausb.flags.timestamp", FT_BOOLEAN, 8,
TFS(&tfs_present_not_present),
(MAUSB_FLAG_TIMESTAMP << MAUSB_FLAG_OFFSET),
NULL, HFILL
}
},
{ &hf_mausb_flag_reserved,
{ "Reserved", "mausb.flags.reserved", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), (MAUSB_FLAG_RESERVED << MAUSB_FLAG_OFFSET),
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
TFS(&tfs_endpoint_direction), MAUSB_EP_HANDLE_D, NULL, HFILL
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
{ "Type-specific management packet fields", "mausb.mgmt_flds",
FT_NONE, 0, NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_mgmt_type_spec_generic,
{ "Type-specific management packet fields", "mausb.mgmt_flds.generic",
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
NULL, MAUSB_TFLAG_MASK, NULL, HFILL
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
{ &hf_mausb_num_iso_hdr,
{ "Number of Iso Headers", "mausb.numisohdr", FT_UINT16, BASE_DEC,
NULL, MAUSB_NUM_ISO_HDR_MASK, NULL, HFILL
}
},
{ &hf_mausb_iflags,
{ "Isochronous Flags", "mausb.iflag", FT_UINT16, BASE_HEX,
NULL, MAUSB_IFLAG_MASK, NULL, HFILL
}
},
{ &hf_mausb_iflag_mtd,
{ "MTD Valid", "mausb.iflag.mtd", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_IFLAG_MTD << MAUSB_IFLAG_OFFSET,
NULL, HFILL
}
},
{ &hf_mausb_iflag_hdr_format,
{ "Isochronous Header Format", "mausb.iflag.ihf", FT_UINT8, BASE_HEX,
NULL, MAUSB_IFLAG_HDR_FORMAT << MAUSB_IFLAG_OFFSET, NULL, HFILL
}
},
{ &hf_mausb_iflag_asap,
{ "ASAP", "mausb.iflag.asap", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), MAUSB_IFLAG_ASAP << MAUSB_IFLAG_OFFSET,
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
{ &hf_mausb_present_time,
{ "Presentation Time", "mausb.presenttime", FT_UINT32, BASE_DEC,
NULL, MAUSB_PRESENT_TIME_MASK, NULL, HFILL
}
},
{ &hf_mausb_uframe,
{ "Microframe Number", "mausb.uframe", FT_UINT32, BASE_DEC,
NULL, MAUSB_UFRAME_MASK, NULL, HFILL
}
},
{ &hf_mausb_frame,
{ "Frame Number", "mausb.frame", FT_UINT32, BASE_DEC,
NULL, MAUSB_FRAME_MASK, NULL, HFILL
}
},
{ &hf_mausb_num_segs,
{ "Number of Segments", "mausb.numseg", FT_UINT32, BASE_DEC,
NULL, MAUSB_NUM_SEGS_MASK, NULL, HFILL
}
},
{ &hf_mausb_timestamp,
{ "Timestamp", "mausb.timestamp", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_delta,
{ "Delta", "mausb.delta", FT_UINT32, BASE_DEC,
NULL, MAUSB_DELTA_MASK, NULL, HFILL
}
},
{ &hf_mausb_nom_interval,
{ "Nominal Bus Interval", "mausb.nomitvl", FT_UINT32, BASE_DEC,
NULL, MAUSB_INTERVAL_MASK, NULL, HFILL
}
},
{ &hf_mausb_mtd,
{ "Media Time/Transmission Delay", "mausb.mtd", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_rem_size_credit,
{ "Remaining Size/Credit", "mausb.remsize_credit", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
};
static hf_register_info hf_cap[] = {
{ &hf_mausb_cap_resp_num_ep,
{ "Number of Endpoints", "mausb.cap_resp.num_ep",
FT_UINT8, BASE_DEC, NULL, 0,
"the maximum number of endpoints for this device",
HFILL
}
},
{ &hf_mausb_cap_resp_num_dev,
{ "Number of Devices", "mausb.cap_resp.num_dev",
FT_UINT8, BASE_DEC, NULL, 0,
"the maximum number of USB devices the MA USB device can manage",
HFILL
}
},
{ &hf_mausb_cap_resp_num_stream,
{ "Number of Streams", "mausb.cap_resp.num_stream",
FT_UINT8, BASE_DEC, NULL, MAUSB_CAP_RESP_NUM_STREAM_MASK,
"2 to the power of this value is the max number of streams supported",
HFILL
}
},
{ &hf_mausb_cap_resp_dev_type,
{ "Device Type", "mausb.cap_resp.dev_type", FT_UINT8, BASE_HEX,
VALS(mausb_cap_resp_dev_type), MAUSB_CAP_RESP_DEV_TYPE_MASK,
NULL, HFILL
}
},
{ &hf_mausb_cap_resp_desc_count,
{ "Descriptors Count", "mausb.cap_resp.desc_count",
FT_UINT8, BASE_DEC,
NULL, 0, "The total number of MA Device Capabilities descriptors",
HFILL
}
},
{ &hf_mausb_cap_resp_desc_len,
{ "Descriptors Length", "mausb.cap_resp.desc_len",
FT_UINT24, BASE_DEC,
NULL, 0, "The total size of MA Device Capabilities descriptors",
HFILL
}
},
{ &hf_mausb_cap_resp_transfer_req,
{ "Number of Outstanding Transfer Requests",
"mausb.cap_resp.transfer_req",
FT_UINT16, BASE_DEC, NULL, 0,
"The maximum number of total outstanding transfer requests", HFILL
}
},
{ &hf_mausb_cap_resp_mgmt_req,
{ "Number of Outstanding Management Requests", "mausb.cap_resp.mgmt_req",
FT_UINT16, BASE_DEC, NULL,
MAUSB_CAP_RESP_MGMT_REQ_MASK,
"The maximum number of host initiated outstanding management requests",
HFILL
}
},
{ &hf_mausb_cap_resp_rsvd,
{ "Reserved", "mausb.cap_resp.rsvd", FT_UINT16, BASE_HEX,
NULL, MAUSB_CAP_RESP_RSVD_MASK, NULL, HFILL
}
},
{ &hf_mausb_dev_cap_len,
{ "Length", "mausb.cap_resp.dev_cap.length",
FT_UINT8, BASE_DEC, NULL,
0, NULL, HFILL
}
},
{ &hf_mausb_dev_cap_type,
{ "Type", "mausb.cap_resp.dev_cap.type",
FT_UINT8, BASE_DEC, VALS(mausb_dev_cap_string),
0, NULL, HFILL
}
},
{ &hf_mausb_dev_cap_generic,
{ "Type-specific device capability descriptor fields",
"mausb.cap_resp.dev_cap.generic",
FT_NONE, 0, NULL, 0, NULL, HFILL
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
NULL, 0x0, NULL, HFILL
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
0x0,
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
static hf_register_info hf_cancel_transfer[] = {
{ &hf_mausb_clear_transfers_info_block,
{ "Clear Transfers Information Block", "mausb.clear_transfers.info", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_status_block,
{ "Cancel Transfers Status Block", "mausb.clear_transfers.status_block", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_cancel_transfer_rsvd,
{ "Reserved", "mausb.cancel_transfer.rsvd", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_req_num,
{ "Number of Blocks", "mausb.clear_transfers_req.num", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_req_rsvd,
{ "Reserved", "mausb.clear_transfers_req.rsvd", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_resp_num,
{ "Number of Blocks", "mausb.clear_transfers_resp.num", FT_UINT32, BASE_DEC,
NULL, MAUSB_CLEAR_TRANSFERS_RESP_NUM_MASK , NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_resp_rsvd,
{ "Reserved", "mausb.clear_transfers_resp.rsvd", FT_UINT32, BASE_HEX,
NULL, ~MAUSB_CLEAR_TRANSFERS_RESP_NUM_MASK, NULL, HFILL
}
},
{ &hf_mausb_cancel_transfer_status,
{ "Status", "mausb.cancel_transfer.status", FT_UINT24, BASE_HEX,
VALS(mausb_cancel_transfer_status_string),
MAUSB_CANCEL_TRANSFER_STATUS_MASK, NULL, HFILL
}
},
{ &hf_mausb_cancel_transfer_rsvd_2,
{ "Reserved", "mausb.cancel_transfer.rsvd_2", FT_UINT24, BASE_HEX,
NULL, ~MAUSB_CANCEL_TRANSFER_STATUS_MASK, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_status,
{ "Cancellation Status", "mausb.clear_transfers.status", FT_BOOLEAN, 6,
TFS(&tfs_success_fail), MAUSB_CLEAR_TRANSFERS_STATUS_MASK,
NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_partial,
{ "Partial Delivery", "mausb.clear_transfers.partial", FT_BOOLEAN, 6,
TFS(&tfs_true_false), MAUSB_CLEAR_TRANSFERS_PARTIAL_MASK,
NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_start_req_id,
{ "Start Request ID", "mausb.clear_transfers.start_reqid", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_last_req_id,
{ "Last Request ID", "mausb.clear_transfers.last_reqid", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_req_block_rsvd,
{ "Reserved", "mausb.clear_transfers_req.block_rsvd", FT_NONE, 0,
NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_clear_transfers_resp_block_rsvd,
{ "Reserved", "mausb.clear_transfers_resp.block_rsvd", FT_UINT32, BASE_HEX,
NULL, MAUSB_CLEAR_TRANSFERS_RESP_BLOCK_RSVD_MASK, NULL, HFILL
}
},
{ &hf_mausb_cancel_transfer_seq_num,
{ "Delivered Sequence Number", "mausb.cancel_transfer.seqnum",
FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL
}
},
{ &hf_mausb_cancel_transfer_byte_offset,
{ "Delivered Byte Offset", "mausb.cancel_transfer.byte_offset",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
}
},
};
static hf_register_info oui_hf[] = {
{ &hf_llc_mausb_pid,
{ "PID", "mausb.pid", FT_UINT16, BASE_HEX,
VALS(mausb_pid_string), 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_mausb,
&ett_mausb_flags,
&ett_mausb_ep_handle,
&ett_mausb_tflags,
&ett_mausb_iflags,
&ett_mausb_present_time,
&ett_mausb_timestamp,
&ett_mgmt,
&ett_dev_cap,
&ett_clear_transfers_block
};
static ei_register_info ei[] = {
{ &ei_ep_handle_len,
{ "mausb.ei.ep_handle.length", PI_PROTOCOL, PI_WARN,
"Invalid Endpoint handle length field", EXPFILL }
},
{ &ei_len,
{ "mausb.ei.length", PI_MALFORMED, PI_ERROR,
"Packet length field does not match size of packet", EXPFILL }
},
{ &ei_mgmt_type_undef,
{ "mausb.ei.type", PI_PROTOCOL, PI_WARN,
"Undefined management packet type", EXPFILL }
},
{ &ei_mgmt_type_spec_len_long,
{ "mausb.ei.type_spec.len", PI_PROTOCOL, PI_WARN,
"Data exists after type-specific management packet field", EXPFILL }
},
{ &ei_mgmt_type_spec_len_short,
{ "mausb.ei.type_spec.len", PI_PROTOCOL, PI_WARN,
"Expected type-specific management packet data", EXPFILL }
},
{ &ei_dev_cap_len,
{ "mausb.ei.cap_resp.dev_cap.length", PI_PROTOCOL, PI_WARN,
"Incorrect length value for this device capability descriptor",
EXPFILL }
},
{ &ei_dev_cap_resp_desc_len,
{ "mausb.ei.dev_cap_resp.desc_len", PI_PROTOCOL, PI_WARN,
"Incorrect value in Device Descriptors Length field", EXPFILL }
},
{ &ei_cap_resp_desc_len,
{ "mausb.ei.cap_resp.desc_len", PI_PROTOCOL, PI_WARN,
"Value in Descriptors Length field exceeds actual space in packet", EXPFILL }
},
};
expert_module_t* expert_mausb;
proto_mausb = proto_register_protocol("Media Agnostic USB", "MAUSB", "mausb");
proto_register_field_array(proto_mausb, hf, array_length(hf));
proto_register_field_array(proto_mausb, hf_cap, array_length(hf_cap));
proto_register_field_array(proto_mausb, hf_ep_handle, array_length(hf_ep_handle));
proto_register_field_array(proto_mausb, hf_cancel_transfer, array_length(hf_cancel_transfer));
proto_register_subtree_array(ett, array_length(ett));
expert_mausb = expert_register_protocol(proto_mausb);
expert_register_field_array(expert_mausb, ei, array_length(ei));
llc_add_oui(OUI_WFA, "llc.wfa_pid", "LLC WFA OUI PID", oui_hf, proto_mausb);
}
void
proto_reg_handoff_mausb(void)
{
dissector_handle_t mausb_tcp_handle;
dissector_handle_t mausb_pkt_handle;
mausb_tcp_handle = create_dissector_handle(dissect_mausb, proto_mausb);
mausb_pkt_handle = create_dissector_handle(dissect_mausb_pkt, proto_mausb);
dissector_add_uint("llc.wfa_pid", PID_MAUSB, mausb_pkt_handle);
dissector_add_uint_range_with_preference("tcp.port", "", mausb_tcp_handle);
dissector_add_for_decode_as_with_preference("udp.port", mausb_pkt_handle);
}
