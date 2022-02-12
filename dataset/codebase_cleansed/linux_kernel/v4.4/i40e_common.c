i40e_status i40e_set_mac_type(struct i40e_hw *hw)
{
i40e_status status = 0;
if (hw->vendor_id == PCI_VENDOR_ID_INTEL) {
switch (hw->device_id) {
case I40E_DEV_ID_SFP_XL710:
case I40E_DEV_ID_QEMU:
case I40E_DEV_ID_KX_A:
case I40E_DEV_ID_KX_B:
case I40E_DEV_ID_KX_C:
case I40E_DEV_ID_QSFP_A:
case I40E_DEV_ID_QSFP_B:
case I40E_DEV_ID_QSFP_C:
case I40E_DEV_ID_10G_BASE_T:
case I40E_DEV_ID_10G_BASE_T4:
case I40E_DEV_ID_20G_KR2:
case I40E_DEV_ID_20G_KR2_A:
hw->mac.type = I40E_MAC_XL710;
break;
case I40E_DEV_ID_SFP_X722:
case I40E_DEV_ID_1G_BASE_T_X722:
case I40E_DEV_ID_10G_BASE_T_X722:
hw->mac.type = I40E_MAC_X722;
break;
case I40E_DEV_ID_X722_VF:
case I40E_DEV_ID_X722_VF_HV:
hw->mac.type = I40E_MAC_X722_VF;
break;
case I40E_DEV_ID_VF:
case I40E_DEV_ID_VF_HV:
hw->mac.type = I40E_MAC_VF;
break;
default:
hw->mac.type = I40E_MAC_GENERIC;
break;
}
} else {
status = I40E_ERR_DEVICE_NOT_SUPPORTED;
}
hw_dbg(hw, "i40e_set_mac_type found mac: %d, returns: %d\n",
hw->mac.type, status);
return status;
}
const char *i40evf_aq_str(struct i40e_hw *hw, enum i40e_admin_queue_err aq_err)
{
switch (aq_err) {
case I40E_AQ_RC_OK:
return "OK";
case I40E_AQ_RC_EPERM:
return "I40E_AQ_RC_EPERM";
case I40E_AQ_RC_ENOENT:
return "I40E_AQ_RC_ENOENT";
case I40E_AQ_RC_ESRCH:
return "I40E_AQ_RC_ESRCH";
case I40E_AQ_RC_EINTR:
return "I40E_AQ_RC_EINTR";
case I40E_AQ_RC_EIO:
return "I40E_AQ_RC_EIO";
case I40E_AQ_RC_ENXIO:
return "I40E_AQ_RC_ENXIO";
case I40E_AQ_RC_E2BIG:
return "I40E_AQ_RC_E2BIG";
case I40E_AQ_RC_EAGAIN:
return "I40E_AQ_RC_EAGAIN";
case I40E_AQ_RC_ENOMEM:
return "I40E_AQ_RC_ENOMEM";
case I40E_AQ_RC_EACCES:
return "I40E_AQ_RC_EACCES";
case I40E_AQ_RC_EFAULT:
return "I40E_AQ_RC_EFAULT";
case I40E_AQ_RC_EBUSY:
return "I40E_AQ_RC_EBUSY";
case I40E_AQ_RC_EEXIST:
return "I40E_AQ_RC_EEXIST";
case I40E_AQ_RC_EINVAL:
return "I40E_AQ_RC_EINVAL";
case I40E_AQ_RC_ENOTTY:
return "I40E_AQ_RC_ENOTTY";
case I40E_AQ_RC_ENOSPC:
return "I40E_AQ_RC_ENOSPC";
case I40E_AQ_RC_ENOSYS:
return "I40E_AQ_RC_ENOSYS";
case I40E_AQ_RC_ERANGE:
return "I40E_AQ_RC_ERANGE";
case I40E_AQ_RC_EFLUSHED:
return "I40E_AQ_RC_EFLUSHED";
case I40E_AQ_RC_BAD_ADDR:
return "I40E_AQ_RC_BAD_ADDR";
case I40E_AQ_RC_EMODE:
return "I40E_AQ_RC_EMODE";
case I40E_AQ_RC_EFBIG:
return "I40E_AQ_RC_EFBIG";
}
snprintf(hw->err_str, sizeof(hw->err_str), "%d", aq_err);
return hw->err_str;
}
const char *i40evf_stat_str(struct i40e_hw *hw, i40e_status stat_err)
{
switch (stat_err) {
case 0:
return "OK";
case I40E_ERR_NVM:
return "I40E_ERR_NVM";
case I40E_ERR_NVM_CHECKSUM:
return "I40E_ERR_NVM_CHECKSUM";
case I40E_ERR_PHY:
return "I40E_ERR_PHY";
case I40E_ERR_CONFIG:
return "I40E_ERR_CONFIG";
case I40E_ERR_PARAM:
return "I40E_ERR_PARAM";
case I40E_ERR_MAC_TYPE:
return "I40E_ERR_MAC_TYPE";
case I40E_ERR_UNKNOWN_PHY:
return "I40E_ERR_UNKNOWN_PHY";
case I40E_ERR_LINK_SETUP:
return "I40E_ERR_LINK_SETUP";
case I40E_ERR_ADAPTER_STOPPED:
return "I40E_ERR_ADAPTER_STOPPED";
case I40E_ERR_INVALID_MAC_ADDR:
return "I40E_ERR_INVALID_MAC_ADDR";
case I40E_ERR_DEVICE_NOT_SUPPORTED:
return "I40E_ERR_DEVICE_NOT_SUPPORTED";
case I40E_ERR_MASTER_REQUESTS_PENDING:
return "I40E_ERR_MASTER_REQUESTS_PENDING";
case I40E_ERR_INVALID_LINK_SETTINGS:
return "I40E_ERR_INVALID_LINK_SETTINGS";
case I40E_ERR_AUTONEG_NOT_COMPLETE:
return "I40E_ERR_AUTONEG_NOT_COMPLETE";
case I40E_ERR_RESET_FAILED:
return "I40E_ERR_RESET_FAILED";
case I40E_ERR_SWFW_SYNC:
return "I40E_ERR_SWFW_SYNC";
case I40E_ERR_NO_AVAILABLE_VSI:
return "I40E_ERR_NO_AVAILABLE_VSI";
case I40E_ERR_NO_MEMORY:
return "I40E_ERR_NO_MEMORY";
case I40E_ERR_BAD_PTR:
return "I40E_ERR_BAD_PTR";
case I40E_ERR_RING_FULL:
return "I40E_ERR_RING_FULL";
case I40E_ERR_INVALID_PD_ID:
return "I40E_ERR_INVALID_PD_ID";
case I40E_ERR_INVALID_QP_ID:
return "I40E_ERR_INVALID_QP_ID";
case I40E_ERR_INVALID_CQ_ID:
return "I40E_ERR_INVALID_CQ_ID";
case I40E_ERR_INVALID_CEQ_ID:
return "I40E_ERR_INVALID_CEQ_ID";
case I40E_ERR_INVALID_AEQ_ID:
return "I40E_ERR_INVALID_AEQ_ID";
case I40E_ERR_INVALID_SIZE:
return "I40E_ERR_INVALID_SIZE";
case I40E_ERR_INVALID_ARP_INDEX:
return "I40E_ERR_INVALID_ARP_INDEX";
case I40E_ERR_INVALID_FPM_FUNC_ID:
return "I40E_ERR_INVALID_FPM_FUNC_ID";
case I40E_ERR_QP_INVALID_MSG_SIZE:
return "I40E_ERR_QP_INVALID_MSG_SIZE";
case I40E_ERR_QP_TOOMANY_WRS_POSTED:
return "I40E_ERR_QP_TOOMANY_WRS_POSTED";
case I40E_ERR_INVALID_FRAG_COUNT:
return "I40E_ERR_INVALID_FRAG_COUNT";
case I40E_ERR_QUEUE_EMPTY:
return "I40E_ERR_QUEUE_EMPTY";
case I40E_ERR_INVALID_ALIGNMENT:
return "I40E_ERR_INVALID_ALIGNMENT";
case I40E_ERR_FLUSHED_QUEUE:
return "I40E_ERR_FLUSHED_QUEUE";
case I40E_ERR_INVALID_PUSH_PAGE_INDEX:
return "I40E_ERR_INVALID_PUSH_PAGE_INDEX";
case I40E_ERR_INVALID_IMM_DATA_SIZE:
return "I40E_ERR_INVALID_IMM_DATA_SIZE";
case I40E_ERR_TIMEOUT:
return "I40E_ERR_TIMEOUT";
case I40E_ERR_OPCODE_MISMATCH:
return "I40E_ERR_OPCODE_MISMATCH";
case I40E_ERR_CQP_COMPL_ERROR:
return "I40E_ERR_CQP_COMPL_ERROR";
case I40E_ERR_INVALID_VF_ID:
return "I40E_ERR_INVALID_VF_ID";
case I40E_ERR_INVALID_HMCFN_ID:
return "I40E_ERR_INVALID_HMCFN_ID";
case I40E_ERR_BACKING_PAGE_ERROR:
return "I40E_ERR_BACKING_PAGE_ERROR";
case I40E_ERR_NO_PBLCHUNKS_AVAILABLE:
return "I40E_ERR_NO_PBLCHUNKS_AVAILABLE";
case I40E_ERR_INVALID_PBLE_INDEX:
return "I40E_ERR_INVALID_PBLE_INDEX";
case I40E_ERR_INVALID_SD_INDEX:
return "I40E_ERR_INVALID_SD_INDEX";
case I40E_ERR_INVALID_PAGE_DESC_INDEX:
return "I40E_ERR_INVALID_PAGE_DESC_INDEX";
case I40E_ERR_INVALID_SD_TYPE:
return "I40E_ERR_INVALID_SD_TYPE";
case I40E_ERR_MEMCPY_FAILED:
return "I40E_ERR_MEMCPY_FAILED";
case I40E_ERR_INVALID_HMC_OBJ_INDEX:
return "I40E_ERR_INVALID_HMC_OBJ_INDEX";
case I40E_ERR_INVALID_HMC_OBJ_COUNT:
return "I40E_ERR_INVALID_HMC_OBJ_COUNT";
case I40E_ERR_INVALID_SRQ_ARM_LIMIT:
return "I40E_ERR_INVALID_SRQ_ARM_LIMIT";
case I40E_ERR_SRQ_ENABLED:
return "I40E_ERR_SRQ_ENABLED";
case I40E_ERR_ADMIN_QUEUE_ERROR:
return "I40E_ERR_ADMIN_QUEUE_ERROR";
case I40E_ERR_ADMIN_QUEUE_TIMEOUT:
return "I40E_ERR_ADMIN_QUEUE_TIMEOUT";
case I40E_ERR_BUF_TOO_SHORT:
return "I40E_ERR_BUF_TOO_SHORT";
case I40E_ERR_ADMIN_QUEUE_FULL:
return "I40E_ERR_ADMIN_QUEUE_FULL";
case I40E_ERR_ADMIN_QUEUE_NO_WORK:
return "I40E_ERR_ADMIN_QUEUE_NO_WORK";
case I40E_ERR_BAD_IWARP_CQE:
return "I40E_ERR_BAD_IWARP_CQE";
case I40E_ERR_NVM_BLANK_MODE:
return "I40E_ERR_NVM_BLANK_MODE";
case I40E_ERR_NOT_IMPLEMENTED:
return "I40E_ERR_NOT_IMPLEMENTED";
case I40E_ERR_PE_DOORBELL_NOT_ENABLED:
return "I40E_ERR_PE_DOORBELL_NOT_ENABLED";
case I40E_ERR_DIAG_TEST_FAILED:
return "I40E_ERR_DIAG_TEST_FAILED";
case I40E_ERR_NOT_READY:
return "I40E_ERR_NOT_READY";
case I40E_NOT_SUPPORTED:
return "I40E_NOT_SUPPORTED";
case I40E_ERR_FIRMWARE_API_VERSION:
return "I40E_ERR_FIRMWARE_API_VERSION";
}
snprintf(hw->err_str, sizeof(hw->err_str), "%d", stat_err);
return hw->err_str;
}
void i40evf_debug_aq(struct i40e_hw *hw, enum i40e_debug_mask mask, void *desc,
void *buffer, u16 buf_len)
{
struct i40e_aq_desc *aq_desc = (struct i40e_aq_desc *)desc;
u16 len = le16_to_cpu(aq_desc->datalen);
u8 *buf = (u8 *)buffer;
u16 i = 0;
if ((!(mask & hw->debug_mask)) || (desc == NULL))
return;
i40e_debug(hw, mask,
"AQ CMD: opcode 0x%04X, flags 0x%04X, datalen 0x%04X, retval 0x%04X\n",
le16_to_cpu(aq_desc->opcode),
le16_to_cpu(aq_desc->flags),
le16_to_cpu(aq_desc->datalen),
le16_to_cpu(aq_desc->retval));
i40e_debug(hw, mask, "\tcookie (h,l) 0x%08X 0x%08X\n",
le32_to_cpu(aq_desc->cookie_high),
le32_to_cpu(aq_desc->cookie_low));
i40e_debug(hw, mask, "\tparam (0,1) 0x%08X 0x%08X\n",
le32_to_cpu(aq_desc->params.internal.param0),
le32_to_cpu(aq_desc->params.internal.param1));
i40e_debug(hw, mask, "\taddr (h,l) 0x%08X 0x%08X\n",
le32_to_cpu(aq_desc->params.external.addr_high),
le32_to_cpu(aq_desc->params.external.addr_low));
if ((buffer != NULL) && (aq_desc->datalen != 0)) {
i40e_debug(hw, mask, "AQ CMD Buffer:\n");
if (buf_len < len)
len = buf_len;
for (i = 0; i < (len - 16); i += 16)
i40e_debug(hw, mask, "\t0x%04X %16ph\n", i, buf + i);
if (i < len)
i40e_debug(hw, mask, "\t0x%04X %*ph\n",
i, len - i, buf + i);
}
}
bool i40evf_check_asq_alive(struct i40e_hw *hw)
{
if (hw->aq.asq.len)
return !!(rd32(hw, hw->aq.asq.len) &
I40E_VF_ATQLEN1_ATQENABLE_MASK);
else
return false;
}
i40e_status i40evf_aq_queue_shutdown(struct i40e_hw *hw,
bool unloading)
{
struct i40e_aq_desc desc;
struct i40e_aqc_queue_shutdown *cmd =
(struct i40e_aqc_queue_shutdown *)&desc.params.raw;
i40e_status status;
i40evf_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_queue_shutdown);
if (unloading)
cmd->driver_unloading = cpu_to_le32(I40E_AQ_DRIVER_UNLOADING);
status = i40evf_asq_send_command(hw, &desc, NULL, 0, NULL);
return status;
}
static i40e_status i40e_aq_get_set_rss_lut(struct i40e_hw *hw,
u16 vsi_id, bool pf_lut,
u8 *lut, u16 lut_size,
bool set)
{
i40e_status status;
struct i40e_aq_desc desc;
struct i40e_aqc_get_set_rss_lut *cmd_resp =
(struct i40e_aqc_get_set_rss_lut *)&desc.params.raw;
if (set)
i40evf_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_rss_lut);
else
i40evf_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_get_rss_lut);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_RD);
cmd_resp->vsi_id =
cpu_to_le16((u16)((vsi_id <<
I40E_AQC_SET_RSS_LUT_VSI_ID_SHIFT) &
I40E_AQC_SET_RSS_LUT_VSI_ID_MASK));
cmd_resp->vsi_id |= cpu_to_le16((u16)I40E_AQC_SET_RSS_LUT_VSI_VALID);
if (pf_lut)
cmd_resp->flags |= cpu_to_le16((u16)
((I40E_AQC_SET_RSS_LUT_TABLE_TYPE_PF <<
I40E_AQC_SET_RSS_LUT_TABLE_TYPE_SHIFT) &
I40E_AQC_SET_RSS_LUT_TABLE_TYPE_MASK));
else
cmd_resp->flags |= cpu_to_le16((u16)
((I40E_AQC_SET_RSS_LUT_TABLE_TYPE_VSI <<
I40E_AQC_SET_RSS_LUT_TABLE_TYPE_SHIFT) &
I40E_AQC_SET_RSS_LUT_TABLE_TYPE_MASK));
status = i40evf_asq_send_command(hw, &desc, lut, lut_size, NULL);
return status;
}
i40e_status i40evf_aq_get_rss_lut(struct i40e_hw *hw, u16 vsi_id,
bool pf_lut, u8 *lut, u16 lut_size)
{
return i40e_aq_get_set_rss_lut(hw, vsi_id, pf_lut, lut, lut_size,
false);
}
i40e_status i40evf_aq_set_rss_lut(struct i40e_hw *hw, u16 vsi_id,
bool pf_lut, u8 *lut, u16 lut_size)
{
return i40e_aq_get_set_rss_lut(hw, vsi_id, pf_lut, lut, lut_size, true);
}
static i40e_status i40e_aq_get_set_rss_key(struct i40e_hw *hw,
u16 vsi_id,
struct i40e_aqc_get_set_rss_key_data *key,
bool set)
{
i40e_status status;
struct i40e_aq_desc desc;
struct i40e_aqc_get_set_rss_key *cmd_resp =
(struct i40e_aqc_get_set_rss_key *)&desc.params.raw;
u16 key_size = sizeof(struct i40e_aqc_get_set_rss_key_data);
if (set)
i40evf_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_rss_key);
else
i40evf_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_get_rss_key);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_RD);
cmd_resp->vsi_id =
cpu_to_le16((u16)((vsi_id <<
I40E_AQC_SET_RSS_KEY_VSI_ID_SHIFT) &
I40E_AQC_SET_RSS_KEY_VSI_ID_MASK));
cmd_resp->vsi_id |= cpu_to_le16((u16)I40E_AQC_SET_RSS_KEY_VSI_VALID);
status = i40evf_asq_send_command(hw, &desc, key, key_size, NULL);
return status;
}
i40e_status i40evf_aq_get_rss_key(struct i40e_hw *hw,
u16 vsi_id,
struct i40e_aqc_get_set_rss_key_data *key)
{
return i40e_aq_get_set_rss_key(hw, vsi_id, key, false);
}
i40e_status i40evf_aq_set_rss_key(struct i40e_hw *hw,
u16 vsi_id,
struct i40e_aqc_get_set_rss_key_data *key)
{
return i40e_aq_get_set_rss_key(hw, vsi_id, key, true);
}
i40e_status i40e_aq_send_msg_to_pf(struct i40e_hw *hw,
enum i40e_virtchnl_ops v_opcode,
i40e_status v_retval,
u8 *msg, u16 msglen,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_asq_cmd_details details;
i40e_status status;
i40evf_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_send_msg_to_pf);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_SI);
desc.cookie_high = cpu_to_le32(v_opcode);
desc.cookie_low = cpu_to_le32(v_retval);
if (msglen) {
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF
| I40E_AQ_FLAG_RD));
if (msglen > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
desc.datalen = cpu_to_le16(msglen);
}
if (!cmd_details) {
memset(&details, 0, sizeof(details));
details.async = true;
cmd_details = &details;
}
status = i40evf_asq_send_command(hw, &desc, msg, msglen, cmd_details);
return status;
}
void i40e_vf_parse_hw_config(struct i40e_hw *hw,
struct i40e_virtchnl_vf_resource *msg)
{
struct i40e_virtchnl_vsi_resource *vsi_res;
int i;
vsi_res = &msg->vsi_res[0];
hw->dev_caps.num_vsis = msg->num_vsis;
hw->dev_caps.num_rx_qp = msg->num_queue_pairs;
hw->dev_caps.num_tx_qp = msg->num_queue_pairs;
hw->dev_caps.num_msix_vectors_vf = msg->max_vectors;
hw->dev_caps.dcb = msg->vf_offload_flags &
I40E_VIRTCHNL_VF_OFFLOAD_L2;
hw->dev_caps.fcoe = (msg->vf_offload_flags &
I40E_VIRTCHNL_VF_OFFLOAD_FCOE) ? 1 : 0;
for (i = 0; i < msg->num_vsis; i++) {
if (vsi_res->vsi_type == I40E_VSI_SRIOV) {
ether_addr_copy(hw->mac.perm_addr,
vsi_res->default_mac_addr);
ether_addr_copy(hw->mac.addr,
vsi_res->default_mac_addr);
}
vsi_res++;
}
}
i40e_status i40e_vf_reset(struct i40e_hw *hw)
{
return i40e_aq_send_msg_to_pf(hw, I40E_VIRTCHNL_OP_RESET_VF,
0, NULL, 0, NULL);
}
