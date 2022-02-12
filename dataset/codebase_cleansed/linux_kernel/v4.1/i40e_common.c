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
case I40E_DEV_ID_20G_KR2:
hw->mac.type = I40E_MAC_XL710;
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
i40e_debug(hw, mask,
"\t0x%04X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
i, buf[i], buf[i + 1], buf[i + 2],
buf[i + 3], buf[i + 4], buf[i + 5],
buf[i + 6], buf[i + 7], buf[i + 8],
buf[i + 9], buf[i + 10], buf[i + 11],
buf[i + 12], buf[i + 13], buf[i + 14],
buf[i + 15]);
if (i < len) {
char d_buf[80];
int j = 0;
memset(d_buf, 0, sizeof(d_buf));
j += sprintf(d_buf, "\t0x%04X ", i);
while (i < len)
j += sprintf(&d_buf[j], " %02X", buf[i++]);
i40e_debug(hw, mask, "%s\n", d_buf);
}
}
}
bool i40evf_check_asq_alive(struct i40e_hw *hw)
{
if (hw->aq.asq.len)
return !!(rd32(hw, hw->aq.asq.len) &
I40E_PF_ATQLEN_ATQENABLE_MASK);
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
memcpy(hw->mac.perm_addr, vsi_res->default_mac_addr,
ETH_ALEN);
memcpy(hw->mac.addr, vsi_res->default_mac_addr,
ETH_ALEN);
}
vsi_res++;
}
}
i40e_status i40e_vf_reset(struct i40e_hw *hw)
{
return i40e_aq_send_msg_to_pf(hw, I40E_VIRTCHNL_OP_RESET_VF,
0, NULL, 0, NULL);
}
