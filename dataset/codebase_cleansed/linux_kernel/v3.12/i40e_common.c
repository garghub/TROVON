static i40e_status i40e_set_mac_type(struct i40e_hw *hw)
{
i40e_status status = 0;
if (hw->vendor_id == PCI_VENDOR_ID_INTEL) {
switch (hw->device_id) {
case I40E_SFP_XL710_DEVICE_ID:
case I40E_SFP_X710_DEVICE_ID:
case I40E_QEMU_DEVICE_ID:
case I40E_KX_A_DEVICE_ID:
case I40E_KX_B_DEVICE_ID:
case I40E_KX_C_DEVICE_ID:
case I40E_KX_D_DEVICE_ID:
case I40E_QSFP_A_DEVICE_ID:
case I40E_QSFP_B_DEVICE_ID:
case I40E_QSFP_C_DEVICE_ID:
hw->mac.type = I40E_MAC_XL710;
break;
case I40E_VF_DEVICE_ID:
case I40E_VF_HV_DEVICE_ID:
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
void i40e_debug_aq(struct i40e_hw *hw, enum i40e_debug_mask mask, void *desc,
void *buffer)
{
struct i40e_aq_desc *aq_desc = (struct i40e_aq_desc *)desc;
u8 *aq_buffer = (u8 *)buffer;
u32 data[4];
u32 i = 0;
if ((!(mask & hw->debug_mask)) || (desc == NULL))
return;
i40e_debug(hw, mask,
"AQ CMD: opcode 0x%04X, flags 0x%04X, datalen 0x%04X, retval 0x%04X\n",
aq_desc->opcode, aq_desc->flags, aq_desc->datalen,
aq_desc->retval);
i40e_debug(hw, mask, "\tcookie (h,l) 0x%08X 0x%08X\n",
aq_desc->cookie_high, aq_desc->cookie_low);
i40e_debug(hw, mask, "\tparam (0,1) 0x%08X 0x%08X\n",
aq_desc->params.internal.param0,
aq_desc->params.internal.param1);
i40e_debug(hw, mask, "\taddr (h,l) 0x%08X 0x%08X\n",
aq_desc->params.external.addr_high,
aq_desc->params.external.addr_low);
if ((buffer != NULL) && (aq_desc->datalen != 0)) {
memset(data, 0, sizeof(data));
i40e_debug(hw, mask, "AQ CMD Buffer:\n");
for (i = 0; i < le16_to_cpu(aq_desc->datalen); i++) {
data[((i % 16) / 4)] |=
((u32)aq_buffer[i]) << (8 * (i % 4));
if ((i % 16) == 15) {
i40e_debug(hw, mask,
"\t0x%04X %08X %08X %08X %08X\n",
i - 15, data[0], data[1], data[2],
data[3]);
memset(data, 0, sizeof(data));
}
}
if ((i % 16) != 0)
i40e_debug(hw, mask, "\t0x%04X %08X %08X %08X %08X\n",
i - (i % 16), data[0], data[1], data[2],
data[3]);
}
}
i40e_status i40e_init_shared_code(struct i40e_hw *hw)
{
i40e_status status = 0;
u32 reg;
hw->phy.get_link_info = true;
reg = rd32(hw, I40E_PFGEN_PORTNUM);
reg = ((reg & I40E_PFGEN_PORTNUM_PORT_NUM_MASK) >>
I40E_PFGEN_PORTNUM_PORT_NUM_SHIFT);
hw->port = (u8)reg;
i40e_set_mac_type(hw);
switch (hw->mac.type) {
case I40E_MAC_XL710:
break;
default:
return I40E_ERR_DEVICE_NOT_SUPPORTED;
break;
}
status = i40e_init_nvm(hw);
return status;
}
static i40e_status i40e_aq_mac_address_read(struct i40e_hw *hw,
u16 *flags,
struct i40e_aqc_mac_address_read_data *addrs,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_mac_address_read *cmd_data =
(struct i40e_aqc_mac_address_read *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_mac_address_read);
desc.flags |= cpu_to_le16(I40E_AQ_FLAG_BUF);
status = i40e_asq_send_command(hw, &desc, addrs,
sizeof(*addrs), cmd_details);
*flags = le16_to_cpu(cmd_data->command_flags);
return status;
}
i40e_status i40e_aq_mac_address_write(struct i40e_hw *hw,
u16 flags, u8 *mac_addr,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_mac_address_write *cmd_data =
(struct i40e_aqc_mac_address_write *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_mac_address_write);
cmd_data->command_flags = cpu_to_le16(flags);
memcpy(&cmd_data->mac_sal, &mac_addr[0], 4);
memcpy(&cmd_data->mac_sah, &mac_addr[4], 2);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_get_mac_addr(struct i40e_hw *hw, u8 *mac_addr)
{
struct i40e_aqc_mac_address_read_data addrs;
i40e_status status;
u16 flags = 0;
status = i40e_aq_mac_address_read(hw, &flags, &addrs, NULL);
if (flags & I40E_AQC_LAN_ADDR_VALID)
memcpy(mac_addr, &addrs.pf_lan_mac, sizeof(addrs.pf_lan_mac));
return status;
}
i40e_status i40e_validate_mac_addr(u8 *mac_addr)
{
i40e_status status = 0;
if (I40E_IS_MULTICAST(mac_addr)) {
hw_dbg(hw, "MAC address is multicast\n");
status = I40E_ERR_INVALID_MAC_ADDR;
} else if (I40E_IS_BROADCAST(mac_addr)) {
hw_dbg(hw, "MAC address is broadcast\n");
status = I40E_ERR_INVALID_MAC_ADDR;
} else if (mac_addr[0] == 0 && mac_addr[1] == 0 && mac_addr[2] == 0 &&
mac_addr[3] == 0 && mac_addr[4] == 0 && mac_addr[5] == 0) {
hw_dbg(hw, "MAC address is all zeros\n");
status = I40E_ERR_INVALID_MAC_ADDR;
}
return status;
}
i40e_status i40e_pf_reset(struct i40e_hw *hw)
{
u32 wait_cnt = 0;
u32 reg = 0;
u32 grst_del;
grst_del = rd32(hw, I40E_GLGEN_RSTCTL) & I40E_GLGEN_RSTCTL_GRSTDEL_MASK
>> I40E_GLGEN_RSTCTL_GRSTDEL_SHIFT;
for (wait_cnt = 0; wait_cnt < grst_del + 2; wait_cnt++) {
reg = rd32(hw, I40E_GLGEN_RSTAT);
if (!(reg & I40E_GLGEN_RSTAT_DEVSTATE_MASK))
break;
msleep(100);
}
if (reg & I40E_GLGEN_RSTAT_DEVSTATE_MASK) {
hw_dbg(hw, "Global reset polling failed to complete.\n");
return I40E_ERR_RESET_FAILED;
}
hw->pf_id = (u8)hw->bus.func;
if (!wait_cnt) {
reg = rd32(hw, I40E_PFGEN_CTRL);
wr32(hw, I40E_PFGEN_CTRL,
(reg | I40E_PFGEN_CTRL_PFSWR_MASK));
for (wait_cnt = 0; wait_cnt < 10; wait_cnt++) {
reg = rd32(hw, I40E_PFGEN_CTRL);
if (!(reg & I40E_PFGEN_CTRL_PFSWR_MASK))
break;
usleep_range(1000, 2000);
}
if (reg & I40E_PFGEN_CTRL_PFSWR_MASK) {
hw_dbg(hw, "PF reset polling failed to complete.\n");
return I40E_ERR_RESET_FAILED;
}
}
i40e_clear_pxe_mode(hw);
return 0;
}
void i40e_clear_pxe_mode(struct i40e_hw *hw)
{
u32 reg;
reg = rd32(hw, I40E_GLLAN_RCTL_0);
wr32(hw, I40E_GLLAN_RCTL_0, (reg | I40E_GLLAN_RCTL_0_PXE_MODE_MASK));
}
u32 i40e_led_get(struct i40e_hw *hw)
{
u32 gpio_val = 0;
u32 mode = 0;
u32 port;
int i;
for (i = 0; i < I40E_HW_CAP_MAX_GPIO; i++) {
if (!hw->func_caps.led[i])
continue;
gpio_val = rd32(hw, I40E_GLGEN_GPIO_CTL(i));
port = (gpio_val & I40E_GLGEN_GPIO_CTL_PRT_NUM_MASK)
>> I40E_GLGEN_GPIO_CTL_PRT_NUM_SHIFT;
if (port != hw->port)
continue;
mode = (gpio_val & I40E_GLGEN_GPIO_CTL_LED_MODE_MASK)
>> I40E_GLGEN_GPIO_CTL_INT_MODE_SHIFT;
break;
}
return mode;
}
void i40e_led_set(struct i40e_hw *hw, u32 mode)
{
u32 gpio_val = 0;
u32 led_mode = 0;
u32 port;
int i;
for (i = 0; i < I40E_HW_CAP_MAX_GPIO; i++) {
if (!hw->func_caps.led[i])
continue;
gpio_val = rd32(hw, I40E_GLGEN_GPIO_CTL(i));
port = (gpio_val & I40E_GLGEN_GPIO_CTL_PRT_NUM_MASK)
>> I40E_GLGEN_GPIO_CTL_PRT_NUM_SHIFT;
if (port != hw->port)
continue;
led_mode = (mode << I40E_GLGEN_GPIO_CTL_LED_MODE_SHIFT) &
I40E_GLGEN_GPIO_CTL_LED_MODE_MASK;
gpio_val &= ~I40E_GLGEN_GPIO_CTL_LED_MODE_MASK;
gpio_val |= led_mode;
wr32(hw, I40E_GLGEN_GPIO_CTL(i), gpio_val);
}
}
i40e_status i40e_aq_queue_shutdown(struct i40e_hw *hw,
bool unloading)
{
struct i40e_aq_desc desc;
struct i40e_aqc_queue_shutdown *cmd =
(struct i40e_aqc_queue_shutdown *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_queue_shutdown);
if (unloading)
cmd->driver_unloading = cpu_to_le32(I40E_AQ_DRIVER_UNLOADING);
status = i40e_asq_send_command(hw, &desc, NULL, 0, NULL);
return status;
}
i40e_status i40e_aq_set_link_restart_an(struct i40e_hw *hw,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_set_link_restart_an *cmd =
(struct i40e_aqc_set_link_restart_an *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_link_restart_an);
cmd->command = I40E_AQ_PHY_RESTART_AN;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_get_link_info(struct i40e_hw *hw,
bool enable_lse, struct i40e_link_status *link,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_get_link_status *resp =
(struct i40e_aqc_get_link_status *)&desc.params.raw;
struct i40e_link_status *hw_link_info = &hw->phy.link_info;
i40e_status status;
u16 command_flags;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_get_link_status);
if (enable_lse)
command_flags = I40E_AQ_LSE_ENABLE;
else
command_flags = I40E_AQ_LSE_DISABLE;
resp->command_flags = cpu_to_le16(command_flags);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
if (status)
goto aq_get_link_info_exit;
memcpy(&hw->phy.link_info_old, hw_link_info,
sizeof(struct i40e_link_status));
hw_link_info->phy_type = (enum i40e_aq_phy_type)resp->phy_type;
hw_link_info->link_speed = (enum i40e_aq_link_speed)resp->link_speed;
hw_link_info->link_info = resp->link_info;
hw_link_info->an_info = resp->an_info;
hw_link_info->ext_info = resp->ext_info;
if (resp->command_flags & cpu_to_le16(I40E_AQ_LSE_ENABLE))
hw_link_info->lse_enable = true;
else
hw_link_info->lse_enable = false;
if (link)
*link = *hw_link_info;
hw->phy.get_link_info = false;
aq_get_link_info_exit:
return status;
}
i40e_status i40e_aq_add_vsi(struct i40e_hw *hw,
struct i40e_vsi_context *vsi_ctx,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_add_get_update_vsi *cmd =
(struct i40e_aqc_add_get_update_vsi *)&desc.params.raw;
struct i40e_aqc_add_get_update_vsi_completion *resp =
(struct i40e_aqc_add_get_update_vsi_completion *)
&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_add_vsi);
cmd->uplink_seid = cpu_to_le16(vsi_ctx->uplink_seid);
cmd->connection_type = vsi_ctx->connection_type;
cmd->vf_id = vsi_ctx->vf_num;
cmd->vsi_flags = cpu_to_le16(vsi_ctx->flags);
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (sizeof(vsi_ctx->info) > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, &vsi_ctx->info,
sizeof(vsi_ctx->info), cmd_details);
if (status)
goto aq_add_vsi_exit;
vsi_ctx->seid = le16_to_cpu(resp->seid);
vsi_ctx->vsi_number = le16_to_cpu(resp->vsi_number);
vsi_ctx->vsis_allocated = le16_to_cpu(resp->vsi_used);
vsi_ctx->vsis_unallocated = le16_to_cpu(resp->vsi_free);
aq_add_vsi_exit:
return status;
}
i40e_status i40e_aq_set_vsi_unicast_promiscuous(struct i40e_hw *hw,
u16 seid, bool set, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_set_vsi_promiscuous_modes *cmd =
(struct i40e_aqc_set_vsi_promiscuous_modes *)&desc.params.raw;
i40e_status status;
u16 flags = 0;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_vsi_promiscuous_modes);
if (set)
flags |= I40E_AQC_SET_VSI_PROMISC_UNICAST;
cmd->promiscuous_flags = cpu_to_le16(flags);
cmd->valid_flags = cpu_to_le16(I40E_AQC_SET_VSI_PROMISC_UNICAST);
cmd->seid = cpu_to_le16(seid);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_set_vsi_multicast_promiscuous(struct i40e_hw *hw,
u16 seid, bool set, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_set_vsi_promiscuous_modes *cmd =
(struct i40e_aqc_set_vsi_promiscuous_modes *)&desc.params.raw;
i40e_status status;
u16 flags = 0;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_vsi_promiscuous_modes);
if (set)
flags |= I40E_AQC_SET_VSI_PROMISC_MULTICAST;
cmd->promiscuous_flags = cpu_to_le16(flags);
cmd->valid_flags = cpu_to_le16(I40E_AQC_SET_VSI_PROMISC_MULTICAST);
cmd->seid = cpu_to_le16(seid);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_set_vsi_broadcast(struct i40e_hw *hw,
u16 seid, bool set_filter,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_set_vsi_promiscuous_modes *cmd =
(struct i40e_aqc_set_vsi_promiscuous_modes *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_vsi_promiscuous_modes);
if (set_filter)
cmd->promiscuous_flags
|= cpu_to_le16(I40E_AQC_SET_VSI_PROMISC_BROADCAST);
else
cmd->promiscuous_flags
&= cpu_to_le16(~I40E_AQC_SET_VSI_PROMISC_BROADCAST);
cmd->valid_flags = cpu_to_le16(I40E_AQC_SET_VSI_PROMISC_BROADCAST);
cmd->seid = cpu_to_le16(seid);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_get_vsi_params(struct i40e_hw *hw,
struct i40e_vsi_context *vsi_ctx,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_switch_seid *cmd =
(struct i40e_aqc_switch_seid *)&desc.params.raw;
struct i40e_aqc_add_get_update_vsi_completion *resp =
(struct i40e_aqc_add_get_update_vsi_completion *)
&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_get_vsi_parameters);
cmd->seid = cpu_to_le16(vsi_ctx->seid);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (sizeof(vsi_ctx->info) > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, &vsi_ctx->info,
sizeof(vsi_ctx->info), NULL);
if (status)
goto aq_get_vsi_params_exit;
vsi_ctx->seid = le16_to_cpu(resp->seid);
vsi_ctx->vsi_number = le16_to_cpu(resp->vsi_number);
vsi_ctx->vsis_allocated = le16_to_cpu(resp->vsi_used);
vsi_ctx->vsis_unallocated = le16_to_cpu(resp->vsi_free);
aq_get_vsi_params_exit:
return status;
}
i40e_status i40e_aq_update_vsi_params(struct i40e_hw *hw,
struct i40e_vsi_context *vsi_ctx,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_switch_seid *cmd =
(struct i40e_aqc_switch_seid *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_update_vsi_parameters);
cmd->seid = cpu_to_le16(vsi_ctx->seid);
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (sizeof(vsi_ctx->info) > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, &vsi_ctx->info,
sizeof(vsi_ctx->info), cmd_details);
return status;
}
i40e_status i40e_aq_get_switch_config(struct i40e_hw *hw,
struct i40e_aqc_get_switch_config_resp *buf,
u16 buf_size, u16 *start_seid,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_switch_seid *scfg =
(struct i40e_aqc_switch_seid *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_get_switch_config);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (buf_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
scfg->seid = cpu_to_le16(*start_seid);
status = i40e_asq_send_command(hw, &desc, buf, buf_size, cmd_details);
*start_seid = le16_to_cpu(scfg->seid);
return status;
}
i40e_status i40e_aq_get_firmware_version(struct i40e_hw *hw,
u16 *fw_major_version, u16 *fw_minor_version,
u16 *api_major_version, u16 *api_minor_version,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_get_version *resp =
(struct i40e_aqc_get_version *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_get_version);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
if (!status) {
if (fw_major_version != NULL)
*fw_major_version = le16_to_cpu(resp->fw_major);
if (fw_minor_version != NULL)
*fw_minor_version = le16_to_cpu(resp->fw_minor);
if (api_major_version != NULL)
*api_major_version = le16_to_cpu(resp->api_major);
if (api_minor_version != NULL)
*api_minor_version = le16_to_cpu(resp->api_minor);
}
return status;
}
i40e_status i40e_aq_send_driver_version(struct i40e_hw *hw,
struct i40e_driver_version *dv,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_driver_version *cmd =
(struct i40e_aqc_driver_version *)&desc.params.raw;
i40e_status status;
if (dv == NULL)
return I40E_ERR_PARAM;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_driver_version);
desc.flags |= cpu_to_le16(I40E_AQ_FLAG_SI);
cmd->driver_major_ver = dv->major_version;
cmd->driver_minor_ver = dv->minor_version;
cmd->driver_build_ver = dv->build_version;
cmd->driver_subbuild_ver = dv->subbuild_version;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
bool i40e_get_link_status(struct i40e_hw *hw)
{
i40e_status status = 0;
bool link_status = false;
if (hw->phy.get_link_info) {
status = i40e_aq_get_link_info(hw, true, NULL, NULL);
if (status)
goto i40e_get_link_status_exit;
}
link_status = hw->phy.link_info.link_info & I40E_AQ_LINK_UP;
i40e_get_link_status_exit:
return link_status;
}
i40e_status i40e_aq_add_veb(struct i40e_hw *hw, u16 uplink_seid,
u16 downlink_seid, u8 enabled_tc,
bool default_port, u16 *veb_seid,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_add_veb *cmd =
(struct i40e_aqc_add_veb *)&desc.params.raw;
struct i40e_aqc_add_veb_completion *resp =
(struct i40e_aqc_add_veb_completion *)&desc.params.raw;
i40e_status status;
u16 veb_flags = 0;
if (!!uplink_seid != !!downlink_seid)
return I40E_ERR_PARAM;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_add_veb);
cmd->uplink_seid = cpu_to_le16(uplink_seid);
cmd->downlink_seid = cpu_to_le16(downlink_seid);
cmd->enable_tcs = enabled_tc;
if (!uplink_seid)
veb_flags |= I40E_AQC_ADD_VEB_FLOATING;
if (default_port)
veb_flags |= I40E_AQC_ADD_VEB_PORT_TYPE_DEFAULT;
else
veb_flags |= I40E_AQC_ADD_VEB_PORT_TYPE_DATA;
cmd->veb_flags = cpu_to_le16(veb_flags);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
if (!status && veb_seid)
*veb_seid = le16_to_cpu(resp->veb_seid);
return status;
}
i40e_status i40e_aq_get_veb_parameters(struct i40e_hw *hw,
u16 veb_seid, u16 *switch_id,
bool *floating, u16 *statistic_index,
u16 *vebs_used, u16 *vebs_free,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_get_veb_parameters_completion *cmd_resp =
(struct i40e_aqc_get_veb_parameters_completion *)
&desc.params.raw;
i40e_status status;
if (veb_seid == 0)
return I40E_ERR_PARAM;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_get_veb_parameters);
cmd_resp->seid = cpu_to_le16(veb_seid);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
if (status)
goto get_veb_exit;
if (switch_id)
*switch_id = le16_to_cpu(cmd_resp->switch_id);
if (statistic_index)
*statistic_index = le16_to_cpu(cmd_resp->statistic_index);
if (vebs_used)
*vebs_used = le16_to_cpu(cmd_resp->vebs_used);
if (vebs_free)
*vebs_free = le16_to_cpu(cmd_resp->vebs_free);
if (floating) {
u16 flags = le16_to_cpu(cmd_resp->veb_flags);
if (flags & I40E_AQC_ADD_VEB_FLOATING)
*floating = true;
else
*floating = false;
}
get_veb_exit:
return status;
}
i40e_status i40e_aq_add_macvlan(struct i40e_hw *hw, u16 seid,
struct i40e_aqc_add_macvlan_element_data *mv_list,
u16 count, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_macvlan *cmd =
(struct i40e_aqc_macvlan *)&desc.params.raw;
i40e_status status;
u16 buf_size;
if (count == 0 || !mv_list || !hw)
return I40E_ERR_PARAM;
buf_size = count * sizeof(struct i40e_aqc_add_macvlan_element_data);
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_add_macvlan);
cmd->num_addresses = cpu_to_le16(count);
cmd->seid[0] = cpu_to_le16(I40E_AQC_MACVLAN_CMD_SEID_VALID | seid);
cmd->seid[1] = 0;
cmd->seid[2] = 0;
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (buf_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, mv_list, buf_size,
cmd_details);
return status;
}
i40e_status i40e_aq_remove_macvlan(struct i40e_hw *hw, u16 seid,
struct i40e_aqc_remove_macvlan_element_data *mv_list,
u16 count, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_macvlan *cmd =
(struct i40e_aqc_macvlan *)&desc.params.raw;
i40e_status status;
u16 buf_size;
if (count == 0 || !mv_list || !hw)
return I40E_ERR_PARAM;
buf_size = count * sizeof(struct i40e_aqc_remove_macvlan_element_data);
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_remove_macvlan);
cmd->num_addresses = cpu_to_le16(count);
cmd->seid[0] = cpu_to_le16(I40E_AQC_MACVLAN_CMD_SEID_VALID | seid);
cmd->seid[1] = 0;
cmd->seid[2] = 0;
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (buf_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, mv_list, buf_size,
cmd_details);
return status;
}
i40e_status i40e_aq_add_vlan(struct i40e_hw *hw, u16 seid,
struct i40e_aqc_add_remove_vlan_element_data *v_list,
u8 count, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_macvlan *cmd =
(struct i40e_aqc_macvlan *)&desc.params.raw;
i40e_status status;
u16 buf_size;
if (count == 0 || !v_list || !hw)
return I40E_ERR_PARAM;
buf_size = count * sizeof(struct i40e_aqc_add_remove_vlan_element_data);
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_add_vlan);
cmd->num_addresses = cpu_to_le16(count);
cmd->seid[0] = cpu_to_le16(seid | I40E_AQC_MACVLAN_CMD_SEID_VALID);
cmd->seid[1] = 0;
cmd->seid[2] = 0;
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (buf_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, v_list, buf_size,
cmd_details);
return status;
}
i40e_status i40e_aq_remove_vlan(struct i40e_hw *hw, u16 seid,
struct i40e_aqc_add_remove_vlan_element_data *v_list,
u8 count, struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_macvlan *cmd =
(struct i40e_aqc_macvlan *)&desc.params.raw;
i40e_status status;
u16 buf_size;
if (count == 0 || !v_list || !hw)
return I40E_ERR_PARAM;
buf_size = count * sizeof(struct i40e_aqc_add_remove_vlan_element_data);
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_remove_vlan);
cmd->num_addresses = cpu_to_le16(count);
cmd->seid[0] = cpu_to_le16(seid | I40E_AQC_MACVLAN_CMD_SEID_VALID);
cmd->seid[1] = 0;
cmd->seid[2] = 0;
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF | I40E_AQ_FLAG_RD));
if (buf_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, v_list, buf_size,
cmd_details);
return status;
}
i40e_status i40e_aq_send_msg_to_vf(struct i40e_hw *hw, u16 vfid,
u32 v_opcode, u32 v_retval, u8 *msg, u16 msglen,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_pf_vf_message *cmd =
(struct i40e_aqc_pf_vf_message *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_send_msg_to_vf);
cmd->id = cpu_to_le32(vfid);
desc.cookie_high = cpu_to_le32(v_opcode);
desc.cookie_low = cpu_to_le32(v_retval);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_SI);
if (msglen) {
desc.flags |= cpu_to_le16((u16)(I40E_AQ_FLAG_BUF |
I40E_AQ_FLAG_RD));
if (msglen > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
desc.datalen = cpu_to_le16(msglen);
}
status = i40e_asq_send_command(hw, &desc, msg, msglen, cmd_details);
return status;
}
i40e_status i40e_aq_set_hmc_resource_profile(struct i40e_hw *hw,
enum i40e_aq_hmc_profile profile,
u8 pe_vf_enabled_count,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aq_get_set_hmc_resource_profile *cmd =
(struct i40e_aq_get_set_hmc_resource_profile *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc,
i40e_aqc_opc_set_hmc_resource_profile);
cmd->pm_profile = (u8)profile;
cmd->pe_vf_enabled = pe_vf_enabled_count;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_request_resource(struct i40e_hw *hw,
enum i40e_aq_resources_ids resource,
enum i40e_aq_resource_access_type access,
u8 sdp_number, u64 *timeout,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_request_resource *cmd_resp =
(struct i40e_aqc_request_resource *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_request_resource);
cmd_resp->resource_id = cpu_to_le16(resource);
cmd_resp->access_type = cpu_to_le16(access);
cmd_resp->resource_number = cpu_to_le32(sdp_number);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
if (!status || hw->aq.asq_last_status == I40E_AQ_RC_EBUSY)
*timeout = le32_to_cpu(cmd_resp->timeout);
return status;
}
i40e_status i40e_aq_release_resource(struct i40e_hw *hw,
enum i40e_aq_resources_ids resource,
u8 sdp_number,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_request_resource *cmd =
(struct i40e_aqc_request_resource *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_release_resource);
cmd->resource_id = cpu_to_le16(resource);
cmd->resource_number = cpu_to_le32(sdp_number);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_read_nvm(struct i40e_hw *hw, u8 module_pointer,
u32 offset, u16 length, void *data,
bool last_command,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_nvm_update *cmd =
(struct i40e_aqc_nvm_update *)&desc.params.raw;
i40e_status status;
if (offset & 0xFF000000) {
status = I40E_ERR_PARAM;
goto i40e_aq_read_nvm_exit;
}
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_nvm_read);
if (last_command)
cmd->command_flags |= I40E_AQ_NVM_LAST_CMD;
cmd->module_pointer = module_pointer;
cmd->offset = cpu_to_le32(offset);
cmd->length = cpu_to_le16(length);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (length > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, data, length, cmd_details);
i40e_aq_read_nvm_exit:
return status;
}
static void i40e_parse_discover_capabilities(struct i40e_hw *hw, void *buff,
u32 cap_count,
enum i40e_admin_queue_opc list_type_opc)
{
struct i40e_aqc_list_capabilities_element_resp *cap;
u32 number, logical_id, phys_id;
struct i40e_hw_capabilities *p;
u32 reg_val;
u32 i = 0;
u16 id;
cap = (struct i40e_aqc_list_capabilities_element_resp *) buff;
if (list_type_opc == i40e_aqc_opc_list_dev_capabilities)
p = (struct i40e_hw_capabilities *)&hw->dev_caps;
else if (list_type_opc == i40e_aqc_opc_list_func_capabilities)
p = (struct i40e_hw_capabilities *)&hw->func_caps;
else
return;
for (i = 0; i < cap_count; i++, cap++) {
id = le16_to_cpu(cap->id);
number = le32_to_cpu(cap->number);
logical_id = le32_to_cpu(cap->logical_id);
phys_id = le32_to_cpu(cap->phys_id);
switch (id) {
case I40E_DEV_FUNC_CAP_SWITCH_MODE:
p->switch_mode = number;
break;
case I40E_DEV_FUNC_CAP_MGMT_MODE:
p->management_mode = number;
break;
case I40E_DEV_FUNC_CAP_NPAR:
p->npar_enable = number;
break;
case I40E_DEV_FUNC_CAP_OS2BMC:
p->os2bmc = number;
break;
case I40E_DEV_FUNC_CAP_VALID_FUNC:
p->valid_functions = number;
break;
case I40E_DEV_FUNC_CAP_SRIOV_1_1:
if (number == 1)
p->sr_iov_1_1 = true;
break;
case I40E_DEV_FUNC_CAP_VF:
p->num_vfs = number;
p->vf_base_id = logical_id;
break;
case I40E_DEV_FUNC_CAP_VMDQ:
if (number == 1)
p->vmdq = true;
break;
case I40E_DEV_FUNC_CAP_802_1_QBG:
if (number == 1)
p->evb_802_1_qbg = true;
break;
case I40E_DEV_FUNC_CAP_802_1_QBH:
if (number == 1)
p->evb_802_1_qbh = true;
break;
case I40E_DEV_FUNC_CAP_VSI:
p->num_vsis = number;
break;
case I40E_DEV_FUNC_CAP_DCB:
if (number == 1) {
p->dcb = true;
p->enabled_tcmap = logical_id;
p->maxtc = phys_id;
}
break;
case I40E_DEV_FUNC_CAP_FCOE:
if (number == 1)
p->fcoe = true;
break;
case I40E_DEV_FUNC_CAP_RSS:
p->rss = true;
reg_val = rd32(hw, I40E_PFQF_CTL_0);
if (reg_val & I40E_PFQF_CTL_0_HASHLUTSIZE_MASK)
p->rss_table_size = number;
else
p->rss_table_size = 128;
p->rss_table_entry_width = logical_id;
break;
case I40E_DEV_FUNC_CAP_RX_QUEUES:
p->num_rx_qp = number;
p->base_queue = phys_id;
break;
case I40E_DEV_FUNC_CAP_TX_QUEUES:
p->num_tx_qp = number;
p->base_queue = phys_id;
break;
case I40E_DEV_FUNC_CAP_MSIX:
p->num_msix_vectors = number;
break;
case I40E_DEV_FUNC_CAP_MSIX_VF:
p->num_msix_vectors_vf = number;
break;
case I40E_DEV_FUNC_CAP_MFP_MODE_1:
if (number == 1)
p->mfp_mode_1 = true;
break;
case I40E_DEV_FUNC_CAP_CEM:
if (number == 1)
p->mgmt_cem = true;
break;
case I40E_DEV_FUNC_CAP_IWARP:
if (number == 1)
p->iwarp = true;
break;
case I40E_DEV_FUNC_CAP_LED:
if (phys_id < I40E_HW_CAP_MAX_GPIO)
p->led[phys_id] = true;
break;
case I40E_DEV_FUNC_CAP_SDP:
if (phys_id < I40E_HW_CAP_MAX_GPIO)
p->sdp[phys_id] = true;
break;
case I40E_DEV_FUNC_CAP_MDIO:
if (number == 1) {
p->mdio_port_num = phys_id;
p->mdio_port_mode = logical_id;
}
break;
case I40E_DEV_FUNC_CAP_IEEE_1588:
if (number == 1)
p->ieee_1588 = true;
break;
case I40E_DEV_FUNC_CAP_FLOW_DIRECTOR:
p->fd = true;
p->fd_filters_guaranteed = number;
p->fd_filters_best_effort = logical_id;
break;
default:
break;
}
}
p->rx_buf_chain_len = I40E_MAX_CHAINED_RX_BUFFERS;
}
i40e_status i40e_aq_discover_capabilities(struct i40e_hw *hw,
void *buff, u16 buff_size, u16 *data_size,
enum i40e_admin_queue_opc list_type_opc,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aqc_list_capabilites *cmd;
i40e_status status = 0;
struct i40e_aq_desc desc;
cmd = (struct i40e_aqc_list_capabilites *)&desc.params.raw;
if (list_type_opc != i40e_aqc_opc_list_func_capabilities &&
list_type_opc != i40e_aqc_opc_list_dev_capabilities) {
status = I40E_ERR_PARAM;
goto exit;
}
i40e_fill_default_direct_cmd_desc(&desc, list_type_opc);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (buff_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, buff, buff_size, cmd_details);
*data_size = le16_to_cpu(desc.datalen);
if (status)
goto exit;
i40e_parse_discover_capabilities(hw, buff, le32_to_cpu(cmd->count),
list_type_opc);
exit:
return status;
}
i40e_status i40e_aq_get_lldp_mib(struct i40e_hw *hw, u8 bridge_type,
u8 mib_type, void *buff, u16 buff_size,
u16 *local_len, u16 *remote_len,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_lldp_get_mib *cmd =
(struct i40e_aqc_lldp_get_mib *)&desc.params.raw;
struct i40e_aqc_lldp_get_mib *resp =
(struct i40e_aqc_lldp_get_mib *)&desc.params.raw;
i40e_status status;
if (buff_size == 0 || !buff)
return I40E_ERR_PARAM;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_lldp_get_mib);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
cmd->type = mib_type & I40E_AQ_LLDP_MIB_TYPE_MASK;
cmd->type |= ((bridge_type << I40E_AQ_LLDP_BRIDGE_TYPE_SHIFT) &
I40E_AQ_LLDP_BRIDGE_TYPE_MASK);
desc.datalen = cpu_to_le16(buff_size);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (buff_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
status = i40e_asq_send_command(hw, &desc, buff, buff_size, cmd_details);
if (!status) {
if (local_len != NULL)
*local_len = le16_to_cpu(resp->local_len);
if (remote_len != NULL)
*remote_len = le16_to_cpu(resp->remote_len);
}
return status;
}
i40e_status i40e_aq_cfg_lldp_mib_change_event(struct i40e_hw *hw,
bool enable_update,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_lldp_update_mib *cmd =
(struct i40e_aqc_lldp_update_mib *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_lldp_update_mib);
if (!enable_update)
cmd->command |= I40E_AQ_LLDP_MIB_UPDATE_DISABLE;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_stop_lldp(struct i40e_hw *hw, bool shutdown_agent,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_lldp_stop *cmd =
(struct i40e_aqc_lldp_stop *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_lldp_stop);
if (shutdown_agent)
cmd->command |= I40E_AQ_LLDP_AGENT_SHUTDOWN;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_start_lldp(struct i40e_hw *hw,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_lldp_start *cmd =
(struct i40e_aqc_lldp_start *)&desc.params.raw;
i40e_status status;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_lldp_start);
cmd->command = I40E_AQ_LLDP_AGENT_START;
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
i40e_status i40e_aq_delete_element(struct i40e_hw *hw, u16 seid,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_switch_seid *cmd =
(struct i40e_aqc_switch_seid *)&desc.params.raw;
i40e_status status;
if (seid == 0)
return I40E_ERR_PARAM;
i40e_fill_default_direct_cmd_desc(&desc, i40e_aqc_opc_delete_element);
cmd->seid = cpu_to_le16(seid);
status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);
return status;
}
static i40e_status i40e_aq_tx_sched_cmd(struct i40e_hw *hw, u16 seid,
void *buff, u16 buff_size,
enum i40e_admin_queue_opc opcode,
struct i40e_asq_cmd_details *cmd_details)
{
struct i40e_aq_desc desc;
struct i40e_aqc_tx_sched_ind *cmd =
(struct i40e_aqc_tx_sched_ind *)&desc.params.raw;
i40e_status status;
bool cmd_param_flag = false;
switch (opcode) {
case i40e_aqc_opc_configure_vsi_ets_sla_bw_limit:
case i40e_aqc_opc_configure_vsi_tc_bw:
case i40e_aqc_opc_enable_switching_comp_ets:
case i40e_aqc_opc_modify_switching_comp_ets:
case i40e_aqc_opc_disable_switching_comp_ets:
case i40e_aqc_opc_configure_switching_comp_ets_bw_limit:
case i40e_aqc_opc_configure_switching_comp_bw_config:
cmd_param_flag = true;
break;
case i40e_aqc_opc_query_vsi_bw_config:
case i40e_aqc_opc_query_vsi_ets_sla_config:
case i40e_aqc_opc_query_switching_comp_ets_config:
case i40e_aqc_opc_query_port_ets_config:
case i40e_aqc_opc_query_switching_comp_bw_config:
cmd_param_flag = false;
break;
default:
return I40E_ERR_PARAM;
}
i40e_fill_default_direct_cmd_desc(&desc, opcode);
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_BUF);
if (cmd_param_flag)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_RD);
if (buff_size > I40E_AQ_LARGE_BUF)
desc.flags |= cpu_to_le16((u16)I40E_AQ_FLAG_LB);
desc.datalen = cpu_to_le16(buff_size);
cmd->vsi_seid = cpu_to_le16(seid);
status = i40e_asq_send_command(hw, &desc, buff, buff_size, cmd_details);
return status;
}
i40e_status i40e_aq_config_vsi_tc_bw(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_configure_vsi_tc_bw_data *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_configure_vsi_tc_bw,
cmd_details);
}
i40e_status i40e_aq_query_vsi_bw_config(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_query_vsi_bw_config_resp *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_query_vsi_bw_config,
cmd_details);
}
i40e_status i40e_aq_query_vsi_ets_sla_config(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_query_vsi_ets_sla_config_resp *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_query_vsi_ets_sla_config,
cmd_details);
}
i40e_status i40e_aq_query_switch_comp_ets_config(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_query_switching_comp_ets_config_resp *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_query_switching_comp_ets_config,
cmd_details);
}
i40e_status i40e_aq_query_port_ets_config(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_query_port_ets_config_resp *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_query_port_ets_config,
cmd_details);
}
i40e_status i40e_aq_query_switch_comp_bw_config(struct i40e_hw *hw,
u16 seid,
struct i40e_aqc_query_switching_comp_bw_config_resp *bw_data,
struct i40e_asq_cmd_details *cmd_details)
{
return i40e_aq_tx_sched_cmd(hw, seid, (void *)bw_data, sizeof(*bw_data),
i40e_aqc_opc_query_switching_comp_bw_config,
cmd_details);
}
static i40e_status i40e_validate_filter_settings(struct i40e_hw *hw,
struct i40e_filter_control_settings *settings)
{
u32 fcoe_cntx_size, fcoe_filt_size;
u32 pe_cntx_size, pe_filt_size;
u32 fcoe_fmax, pe_fmax;
u32 val;
switch (settings->fcoe_filt_num) {
case I40E_HASH_FILTER_SIZE_1K:
case I40E_HASH_FILTER_SIZE_2K:
case I40E_HASH_FILTER_SIZE_4K:
case I40E_HASH_FILTER_SIZE_8K:
case I40E_HASH_FILTER_SIZE_16K:
case I40E_HASH_FILTER_SIZE_32K:
fcoe_filt_size = I40E_HASH_FILTER_BASE_SIZE;
fcoe_filt_size <<= (u32)settings->fcoe_filt_num;
break;
default:
return I40E_ERR_PARAM;
}
switch (settings->fcoe_cntx_num) {
case I40E_DMA_CNTX_SIZE_512:
case I40E_DMA_CNTX_SIZE_1K:
case I40E_DMA_CNTX_SIZE_2K:
case I40E_DMA_CNTX_SIZE_4K:
fcoe_cntx_size = I40E_DMA_CNTX_BASE_SIZE;
fcoe_cntx_size <<= (u32)settings->fcoe_cntx_num;
break;
default:
return I40E_ERR_PARAM;
}
switch (settings->pe_filt_num) {
case I40E_HASH_FILTER_SIZE_1K:
case I40E_HASH_FILTER_SIZE_2K:
case I40E_HASH_FILTER_SIZE_4K:
case I40E_HASH_FILTER_SIZE_8K:
case I40E_HASH_FILTER_SIZE_16K:
case I40E_HASH_FILTER_SIZE_32K:
case I40E_HASH_FILTER_SIZE_64K:
case I40E_HASH_FILTER_SIZE_128K:
case I40E_HASH_FILTER_SIZE_256K:
case I40E_HASH_FILTER_SIZE_512K:
case I40E_HASH_FILTER_SIZE_1M:
pe_filt_size = I40E_HASH_FILTER_BASE_SIZE;
pe_filt_size <<= (u32)settings->pe_filt_num;
break;
default:
return I40E_ERR_PARAM;
}
switch (settings->pe_cntx_num) {
case I40E_DMA_CNTX_SIZE_512:
case I40E_DMA_CNTX_SIZE_1K:
case I40E_DMA_CNTX_SIZE_2K:
case I40E_DMA_CNTX_SIZE_4K:
case I40E_DMA_CNTX_SIZE_8K:
case I40E_DMA_CNTX_SIZE_16K:
case I40E_DMA_CNTX_SIZE_32K:
case I40E_DMA_CNTX_SIZE_64K:
case I40E_DMA_CNTX_SIZE_128K:
case I40E_DMA_CNTX_SIZE_256K:
pe_cntx_size = I40E_DMA_CNTX_BASE_SIZE;
pe_cntx_size <<= (u32)settings->pe_cntx_num;
break;
default:
return I40E_ERR_PARAM;
}
val = rd32(hw, I40E_GLHMC_FCOEFMAX);
fcoe_fmax = (val & I40E_GLHMC_FCOEFMAX_PMFCOEFMAX_MASK)
>> I40E_GLHMC_FCOEFMAX_PMFCOEFMAX_SHIFT;
if (fcoe_filt_size + fcoe_cntx_size > fcoe_fmax)
return I40E_ERR_INVALID_SIZE;
val = rd32(hw, I40E_GLHMC_PEXFMAX);
pe_fmax = (val & I40E_GLHMC_PEXFMAX_PMPEXFMAX_MASK)
>> I40E_GLHMC_PEXFMAX_PMPEXFMAX_SHIFT;
if (pe_filt_size + pe_cntx_size > pe_fmax)
return I40E_ERR_INVALID_SIZE;
return 0;
}
i40e_status i40e_set_filter_control(struct i40e_hw *hw,
struct i40e_filter_control_settings *settings)
{
i40e_status ret = 0;
u32 hash_lut_size = 0;
u32 val;
if (!settings)
return I40E_ERR_PARAM;
ret = i40e_validate_filter_settings(hw, settings);
if (ret)
return ret;
val = rd32(hw, I40E_PFQF_CTL_0);
val &= ~I40E_PFQF_CTL_0_PEHSIZE_MASK;
val |= ((u32)settings->pe_filt_num << I40E_PFQF_CTL_0_PEHSIZE_SHIFT) &
I40E_PFQF_CTL_0_PEHSIZE_MASK;
val &= ~I40E_PFQF_CTL_0_PEDSIZE_MASK;
val |= ((u32)settings->pe_cntx_num << I40E_PFQF_CTL_0_PEDSIZE_SHIFT) &
I40E_PFQF_CTL_0_PEDSIZE_MASK;
val &= ~I40E_PFQF_CTL_0_PFFCHSIZE_MASK;
val |= ((u32)settings->fcoe_filt_num <<
I40E_PFQF_CTL_0_PFFCHSIZE_SHIFT) &
I40E_PFQF_CTL_0_PFFCHSIZE_MASK;
val &= ~I40E_PFQF_CTL_0_PFFCDSIZE_MASK;
val |= ((u32)settings->fcoe_cntx_num <<
I40E_PFQF_CTL_0_PFFCDSIZE_SHIFT) &
I40E_PFQF_CTL_0_PFFCDSIZE_MASK;
val &= ~I40E_PFQF_CTL_0_HASHLUTSIZE_MASK;
if (settings->hash_lut_size == I40E_HASH_LUT_SIZE_512)
hash_lut_size = 1;
val |= (hash_lut_size << I40E_PFQF_CTL_0_HASHLUTSIZE_SHIFT) &
I40E_PFQF_CTL_0_HASHLUTSIZE_MASK;
if (settings->enable_fdir)
val |= I40E_PFQF_CTL_0_FD_ENA_MASK;
if (settings->enable_ethtype)
val |= I40E_PFQF_CTL_0_ETYPE_ENA_MASK;
if (settings->enable_macvlan)
val |= I40E_PFQF_CTL_0_MACVLAN_ENA_MASK;
wr32(hw, I40E_PFQF_CTL_0, val);
return 0;
}
