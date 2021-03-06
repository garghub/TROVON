static int iwlagn_load_section(struct iwl_priv *priv, const char *name,
struct fw_desc *image, u32 dst_addr)
{
dma_addr_t phy_addr = image->p_addr;
u32 byte_cnt = image->len;
int ret;
priv->ucode_write_complete = 0;
iwl_write_direct32(priv,
FH_TCSR_CHNL_TX_CONFIG_REG(FH_SRVC_CHNL),
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_PAUSE);
iwl_write_direct32(priv,
FH_SRVC_CHNL_SRAM_ADDR_REG(FH_SRVC_CHNL), dst_addr);
iwl_write_direct32(priv,
FH_TFDIB_CTRL0_REG(FH_SRVC_CHNL),
phy_addr & FH_MEM_TFDIB_DRAM_ADDR_LSB_MSK);
iwl_write_direct32(priv,
FH_TFDIB_CTRL1_REG(FH_SRVC_CHNL),
(iwl_get_dma_hi_addr(phy_addr)
<< FH_MEM_TFDIB_REG1_ADDR_BITSHIFT) | byte_cnt);
iwl_write_direct32(priv,
FH_TCSR_CHNL_TX_BUF_STS_REG(FH_SRVC_CHNL),
1 << FH_TCSR_CHNL_TX_BUF_STS_REG_POS_TB_NUM |
1 << FH_TCSR_CHNL_TX_BUF_STS_REG_POS_TB_IDX |
FH_TCSR_CHNL_TX_BUF_STS_REG_VAL_TFDB_VALID);
iwl_write_direct32(priv,
FH_TCSR_CHNL_TX_CONFIG_REG(FH_SRVC_CHNL),
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_ENABLE |
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_DISABLE |
FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_HOST_ENDTFD);
IWL_DEBUG_FW(priv, "%s uCode section being loaded...\n", name);
ret = wait_event_interruptible_timeout(priv->wait_command_queue,
priv->ucode_write_complete, 5 * HZ);
if (ret == -ERESTARTSYS) {
IWL_ERR(priv, "Could not load the %s uCode section due "
"to interrupt\n", name);
return ret;
}
if (!ret) {
IWL_ERR(priv, "Could not load the %s uCode section\n",
name);
return -ETIMEDOUT;
}
return 0;
}
static int iwlagn_load_given_ucode(struct iwl_priv *priv,
struct fw_img *image)
{
int ret = 0;
ret = iwlagn_load_section(priv, "INST", &image->code,
IWLAGN_RTC_INST_LOWER_BOUND);
if (ret)
return ret;
return iwlagn_load_section(priv, "DATA", &image->data,
IWLAGN_RTC_DATA_LOWER_BOUND);
}
static int iwlagn_set_Xtal_calib(struct iwl_priv *priv)
{
struct iwl_calib_xtal_freq_cmd cmd;
__le16 *xtal_calib =
(__le16 *)iwl_eeprom_query_addr(priv, EEPROM_XTAL);
iwl_set_calib_hdr(&cmd.hdr, IWL_PHY_CALIBRATE_CRYSTAL_FRQ_CMD);
cmd.cap_pin1 = le16_to_cpu(xtal_calib[0]);
cmd.cap_pin2 = le16_to_cpu(xtal_calib[1]);
return iwl_calib_set(&priv->calib_results[IWL_CALIB_XTAL],
(u8 *)&cmd, sizeof(cmd));
}
static int iwlagn_set_temperature_offset_calib(struct iwl_priv *priv)
{
struct iwl_calib_temperature_offset_cmd cmd;
__le16 *offset_calib =
(__le16 *)iwl_eeprom_query_addr(priv, EEPROM_TEMPERATURE);
memset(&cmd, 0, sizeof(cmd));
iwl_set_calib_hdr(&cmd.hdr, IWL_PHY_CALIBRATE_TEMP_OFFSET_CMD);
memcpy(&cmd.radio_sensor_offset, offset_calib, sizeof(*offset_calib));
if (!(cmd.radio_sensor_offset))
cmd.radio_sensor_offset = DEFAULT_RADIO_SENSOR_OFFSET;
IWL_DEBUG_CALIB(priv, "Radio sensor offset: %d\n",
le16_to_cpu(cmd.radio_sensor_offset));
return iwl_calib_set(&priv->calib_results[IWL_CALIB_TEMP_OFFSET],
(u8 *)&cmd, sizeof(cmd));
}
static int iwlagn_send_calib_cfg(struct iwl_priv *priv)
{
struct iwl_calib_cfg_cmd calib_cfg_cmd;
struct iwl_host_cmd cmd = {
.id = CALIBRATION_CFG_CMD,
.len = { sizeof(struct iwl_calib_cfg_cmd), },
.data = { &calib_cfg_cmd, },
};
memset(&calib_cfg_cmd, 0, sizeof(calib_cfg_cmd));
calib_cfg_cmd.ucd_calib_cfg.once.is_enable = IWL_CALIB_INIT_CFG_ALL;
calib_cfg_cmd.ucd_calib_cfg.once.start = IWL_CALIB_INIT_CFG_ALL;
calib_cfg_cmd.ucd_calib_cfg.once.send_res = IWL_CALIB_INIT_CFG_ALL;
calib_cfg_cmd.ucd_calib_cfg.flags =
IWL_CALIB_CFG_FLAG_SEND_COMPLETE_NTFY_MSK;
return trans_send_cmd(&priv->trans, &cmd);
}
void iwlagn_rx_calib_result(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_calib_hdr *hdr = (struct iwl_calib_hdr *)pkt->u.raw;
int len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
int index;
len -= 4;
switch (hdr->op_code) {
case IWL_PHY_CALIBRATE_DC_CMD:
index = IWL_CALIB_DC;
break;
case IWL_PHY_CALIBRATE_LO_CMD:
index = IWL_CALIB_LO;
break;
case IWL_PHY_CALIBRATE_TX_IQ_CMD:
index = IWL_CALIB_TX_IQ;
break;
case IWL_PHY_CALIBRATE_TX_IQ_PERD_CMD:
index = IWL_CALIB_TX_IQ_PERD;
break;
case IWL_PHY_CALIBRATE_BASE_BAND_CMD:
index = IWL_CALIB_BASE_BAND;
break;
default:
IWL_ERR(priv, "Unknown calibration notification %d\n",
hdr->op_code);
return;
}
iwl_calib_set(&priv->calib_results[index], pkt->u.raw, len);
}
int iwlagn_init_alive_start(struct iwl_priv *priv)
{
int ret;
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
ret = iwlagn_send_bt_env(priv, IWL_BT_COEX_ENV_OPEN,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
}
ret = iwlagn_send_calib_cfg(priv);
if (ret)
return ret;
if (priv->cfg->need_temp_offset_calib)
return iwlagn_set_temperature_offset_calib(priv);
return 0;
}
static int iwlagn_send_wimax_coex(struct iwl_priv *priv)
{
struct iwl_wimax_coex_cmd coex_cmd;
if (priv->cfg->base_params->support_wimax_coexist) {
coex_cmd.flags = COEX_FLAGS_ASSOC_WA_UNMASK_MSK;
coex_cmd.flags |= COEX_FLAGS_UNASSOC_WA_UNMASK_MSK;
memcpy(coex_cmd.sta_prio, cu_priorities,
sizeof(struct iwl_wimax_coex_event_entry) *
COEX_NUM_OF_EVENTS);
coex_cmd.flags |= COEX_FLAGS_COEX_ENABLE_MSK;
coex_cmd.flags |= COEX_FLAGS_STA_TABLE_VALID_MSK;
} else {
memset(&coex_cmd, 0, sizeof(coex_cmd));
}
return trans_send_cmd_pdu(&priv->trans,
COEX_PRIORITY_TABLE_CMD, CMD_SYNC,
sizeof(coex_cmd), &coex_cmd);
}
void iwlagn_send_prio_tbl(struct iwl_priv *priv)
{
struct iwl_bt_coex_prio_table_cmd prio_tbl_cmd;
memcpy(prio_tbl_cmd.prio_tbl, iwlagn_bt_prio_tbl,
sizeof(iwlagn_bt_prio_tbl));
if (trans_send_cmd_pdu(&priv->trans,
REPLY_BT_COEX_PRIO_TABLE, CMD_SYNC,
sizeof(prio_tbl_cmd), &prio_tbl_cmd))
IWL_ERR(priv, "failed to send BT prio tbl command\n");
}
int iwlagn_send_bt_env(struct iwl_priv *priv, u8 action, u8 type)
{
struct iwl_bt_coex_prot_env_cmd env_cmd;
int ret;
env_cmd.action = action;
env_cmd.type = type;
ret = trans_send_cmd_pdu(&priv->trans,
REPLY_BT_COEX_PROT_ENV, CMD_SYNC,
sizeof(env_cmd), &env_cmd);
if (ret)
IWL_ERR(priv, "failed to send BT env command\n");
return ret;
}
static int iwlagn_alive_notify(struct iwl_priv *priv)
{
int ret;
trans_tx_start(&priv->trans);
ret = iwlagn_send_wimax_coex(priv);
if (ret)
return ret;
ret = iwlagn_set_Xtal_calib(priv);
if (ret)
return ret;
return iwl_send_calib_results(priv);
}
static int iwlcore_verify_inst_sparse(struct iwl_priv *priv,
struct fw_desc *fw_desc)
{
__le32 *image = (__le32 *)fw_desc->v_addr;
u32 len = fw_desc->len;
u32 val;
u32 i;
IWL_DEBUG_FW(priv, "ucode inst image size is %u\n", len);
for (i = 0; i < len; i += 100, image += 100/sizeof(u32)) {
iwl_write_direct32(priv, HBUS_TARG_MEM_RADDR,
i + IWLAGN_RTC_INST_LOWER_BOUND);
val = iwl_read32(priv, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image))
return -EIO;
}
return 0;
}
static void iwl_print_mismatch_inst(struct iwl_priv *priv,
struct fw_desc *fw_desc)
{
__le32 *image = (__le32 *)fw_desc->v_addr;
u32 len = fw_desc->len;
u32 val;
u32 offs;
int errors = 0;
IWL_DEBUG_FW(priv, "ucode inst image size is %u\n", len);
iwl_write_direct32(priv, HBUS_TARG_MEM_RADDR,
IWLAGN_RTC_INST_LOWER_BOUND);
for (offs = 0;
offs < len && errors < 20;
offs += sizeof(u32), image++) {
val = iwl_read32(priv, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image)) {
IWL_ERR(priv, "uCode INST section at "
"offset 0x%x, is 0x%x, s/b 0x%x\n",
offs, val, le32_to_cpu(*image));
errors++;
}
}
}
static int iwl_verify_ucode(struct iwl_priv *priv, struct fw_img *img)
{
if (!iwlcore_verify_inst_sparse(priv, &img->code)) {
IWL_DEBUG_FW(priv, "uCode is good in inst SRAM\n");
return 0;
}
IWL_ERR(priv, "UCODE IMAGE IN INSTRUCTION SRAM NOT VALID!!\n");
iwl_print_mismatch_inst(priv, &img->code);
return -EIO;
}
static void iwlagn_alive_fn(struct iwl_priv *priv,
struct iwl_rx_packet *pkt,
void *data)
{
struct iwlagn_alive_data *alive_data = data;
struct iwl_alive_resp *palive;
palive = &pkt->u.alive_frame;
IWL_DEBUG_FW(priv, "Alive ucode status 0x%08X revision "
"0x%01X 0x%01X\n",
palive->is_valid, palive->ver_type,
palive->ver_subtype);
priv->device_pointers.error_event_table =
le32_to_cpu(palive->error_event_table_ptr);
priv->device_pointers.log_event_table =
le32_to_cpu(palive->log_event_table_ptr);
alive_data->subtype = palive->ver_subtype;
alive_data->valid = palive->is_valid == UCODE_VALID_OK;
}
int iwlagn_load_ucode_wait_alive(struct iwl_priv *priv,
struct fw_img *image,
enum iwlagn_ucode_type ucode_type)
{
struct iwl_notification_wait alive_wait;
struct iwlagn_alive_data alive_data;
int ret;
enum iwlagn_ucode_type old_type;
ret = trans_start_device(&priv->trans);
if (ret)
return ret;
iwlagn_init_notification_wait(priv, &alive_wait, REPLY_ALIVE,
iwlagn_alive_fn, &alive_data);
old_type = priv->ucode_type;
priv->ucode_type = ucode_type;
ret = iwlagn_load_given_ucode(priv, image);
if (ret) {
priv->ucode_type = old_type;
iwlagn_remove_notification(priv, &alive_wait);
return ret;
}
trans_kick_nic(&priv->trans);
ret = iwlagn_wait_notification(priv, &alive_wait, UCODE_ALIVE_TIMEOUT);
if (ret) {
priv->ucode_type = old_type;
return ret;
}
if (!alive_data.valid) {
IWL_ERR(priv, "Loaded ucode is not valid!\n");
priv->ucode_type = old_type;
return -EIO;
}
if (ucode_type != IWL_UCODE_WOWLAN) {
ret = iwl_verify_ucode(priv, image);
if (ret) {
priv->ucode_type = old_type;
return ret;
}
msleep(5);
}
ret = iwlagn_alive_notify(priv);
if (ret) {
IWL_WARN(priv,
"Could not complete ALIVE transition: %d\n", ret);
priv->ucode_type = old_type;
return ret;
}
return 0;
}
int iwlagn_run_init_ucode(struct iwl_priv *priv)
{
struct iwl_notification_wait calib_wait;
int ret;
lockdep_assert_held(&priv->mutex);
if (!priv->ucode_init.code.len)
return 0;
if (priv->ucode_type != IWL_UCODE_NONE)
return 0;
iwlagn_init_notification_wait(priv, &calib_wait,
CALIBRATION_COMPLETE_NOTIFICATION,
NULL, NULL);
ret = iwlagn_load_ucode_wait_alive(priv, &priv->ucode_init,
IWL_UCODE_INIT);
if (ret)
goto error;
ret = iwlagn_init_alive_start(priv);
if (ret)
goto error;
ret = iwlagn_wait_notification(priv, &calib_wait, UCODE_CALIB_TIMEOUT);
goto out;
error:
iwlagn_remove_notification(priv, &calib_wait);
out:
trans_stop_device(&priv->trans);
return ret;
}
