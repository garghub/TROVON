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
IWL_DEBUG_INFO(priv, "%s uCode section being loaded...\n", name);
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
cmd.hdr.op_code = IWL_PHY_CALIBRATE_CRYSTAL_FRQ_CMD;
cmd.hdr.first_group = 0;
cmd.hdr.groups_num = 1;
cmd.hdr.data_valid = 1;
cmd.cap_pin1 = le16_to_cpu(xtal_calib[0]);
cmd.cap_pin2 = le16_to_cpu(xtal_calib[1]);
return iwl_calib_set(&priv->calib_results[IWL_CALIB_XTAL],
(u8 *)&cmd, sizeof(cmd));
}
static int iwlagn_set_temperature_offset_calib(struct iwl_priv *priv)
{
struct iwl_calib_temperature_offset_cmd cmd;
__le16 *offset_calib =
(__le16 *)iwl_eeprom_query_addr(priv, EEPROM_5000_TEMPERATURE);
cmd.hdr.op_code = IWL_PHY_CALIBRATE_TEMP_OFFSET_CMD;
cmd.hdr.first_group = 0;
cmd.hdr.groups_num = 1;
cmd.hdr.data_valid = 1;
cmd.radio_sensor_offset = le16_to_cpu(offset_calib[1]);
if (!(cmd.radio_sensor_offset))
cmd.radio_sensor_offset = DEFAULT_RADIO_SENSOR_OFFSET;
cmd.reserved = 0;
IWL_DEBUG_CALIB(priv, "Radio sensor offset: %d\n",
cmd.radio_sensor_offset);
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
calib_cfg_cmd.ucd_calib_cfg.flags = IWL_CALIB_INIT_CFG_ALL;
return iwl_send_cmd(priv, &cmd);
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
return iwl_send_cmd_pdu(priv, COEX_PRIORITY_TABLE_CMD,
sizeof(coex_cmd), &coex_cmd);
}
void iwlagn_send_prio_tbl(struct iwl_priv *priv)
{
struct iwl_bt_coex_prio_table_cmd prio_tbl_cmd;
memcpy(prio_tbl_cmd.prio_tbl, iwlagn_bt_prio_tbl,
sizeof(iwlagn_bt_prio_tbl));
if (iwl_send_cmd_pdu(priv, REPLY_BT_COEX_PRIO_TABLE,
sizeof(prio_tbl_cmd), &prio_tbl_cmd))
IWL_ERR(priv, "failed to send BT prio tbl command\n");
}
int iwlagn_send_bt_env(struct iwl_priv *priv, u8 action, u8 type)
{
struct iwl_bt_coex_prot_env_cmd env_cmd;
int ret;
env_cmd.action = action;
env_cmd.type = type;
ret = iwl_send_cmd_pdu(priv, REPLY_BT_COEX_PROT_ENV,
sizeof(env_cmd), &env_cmd);
if (ret)
IWL_ERR(priv, "failed to send BT env command\n");
return ret;
}
static int iwlagn_alive_notify(struct iwl_priv *priv)
{
const struct queue_to_fifo_ac *queue_to_fifo;
struct iwl_rxon_context *ctx;
u32 a;
unsigned long flags;
int i, chan;
u32 reg_val;
int ret;
spin_lock_irqsave(&priv->lock, flags);
priv->scd_base_addr = iwl_read_prph(priv, IWLAGN_SCD_SRAM_BASE_ADDR);
a = priv->scd_base_addr + IWLAGN_SCD_CONTEXT_DATA_OFFSET;
for (; a < priv->scd_base_addr + IWLAGN_SCD_TX_STTS_BITMAP_OFFSET;
a += 4)
iwl_write_targ_mem(priv, a, 0);
for (; a < priv->scd_base_addr + IWLAGN_SCD_TRANSLATE_TBL_OFFSET;
a += 4)
iwl_write_targ_mem(priv, a, 0);
for (; a < priv->scd_base_addr +
IWLAGN_SCD_TRANSLATE_TBL_OFFSET_QUEUE(priv->hw_params.max_txq_num); a += 4)
iwl_write_targ_mem(priv, a, 0);
iwl_write_prph(priv, IWLAGN_SCD_DRAM_BASE_ADDR,
priv->scd_bc_tbls.dma >> 10);
for (chan = 0; chan < FH50_TCSR_CHNL_NUM ; chan++)
iwl_write_direct32(priv, FH_TCSR_CHNL_TX_CONFIG_REG(chan),
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_ENABLE |
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_ENABLE);
reg_val = iwl_read_direct32(priv, FH_TX_CHICKEN_BITS_REG);
iwl_write_direct32(priv, FH_TX_CHICKEN_BITS_REG,
reg_val | FH_TX_CHICKEN_BITS_SCD_AUTO_RETRY_EN);
iwl_write_prph(priv, IWLAGN_SCD_QUEUECHAIN_SEL,
IWLAGN_SCD_QUEUECHAIN_SEL_ALL(priv));
iwl_write_prph(priv, IWLAGN_SCD_AGGR_SEL, 0);
for (i = 0; i < priv->hw_params.max_txq_num; i++) {
iwl_write_prph(priv, IWLAGN_SCD_QUEUE_RDPTR(i), 0);
iwl_write_direct32(priv, HBUS_TARG_WRPTR, 0 | (i << 8));
iwl_write_targ_mem(priv, priv->scd_base_addr +
IWLAGN_SCD_CONTEXT_QUEUE_OFFSET(i), 0);
iwl_write_targ_mem(priv, priv->scd_base_addr +
IWLAGN_SCD_CONTEXT_QUEUE_OFFSET(i) +
sizeof(u32),
((SCD_WIN_SIZE <<
IWLAGN_SCD_QUEUE_CTX_REG2_WIN_SIZE_POS) &
IWLAGN_SCD_QUEUE_CTX_REG2_WIN_SIZE_MSK) |
((SCD_FRAME_LIMIT <<
IWLAGN_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_POS) &
IWLAGN_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_MSK));
}
iwl_write_prph(priv, IWLAGN_SCD_INTERRUPT_MASK,
IWL_MASK(0, priv->hw_params.max_txq_num));
iwlagn_txq_set_sched(priv, IWL_MASK(0, 7));
if (priv->valid_contexts != BIT(IWL_RXON_CTX_BSS))
queue_to_fifo = iwlagn_ipan_queue_to_tx_fifo;
else
queue_to_fifo = iwlagn_default_queue_to_tx_fifo;
iwlagn_set_wr_ptrs(priv, priv->cmd_queue, 0);
memset(&priv->queue_stopped[0], 0, sizeof(priv->queue_stopped));
for (i = 0; i < 4; i++)
atomic_set(&priv->queue_stop_count[i], 0);
for_each_context(priv, ctx)
ctx->last_tx_rejected = false;
priv->txq_ctx_active_msk = 0;
BUILD_BUG_ON(ARRAY_SIZE(iwlagn_default_queue_to_tx_fifo) != 10);
BUILD_BUG_ON(ARRAY_SIZE(iwlagn_ipan_queue_to_tx_fifo) != 10);
for (i = 0; i < 10; i++) {
int fifo = queue_to_fifo[i].fifo;
int ac = queue_to_fifo[i].ac;
iwl_txq_ctx_activate(priv, i);
if (fifo == IWL_TX_FIFO_UNUSED)
continue;
if (ac != IWL_AC_UNSET)
iwl_set_swq_id(&priv->txq[i], ac, i);
iwlagn_tx_queue_set_status(priv, &priv->txq[i], fifo, 0);
}
spin_unlock_irqrestore(&priv->lock, flags);
iwl_clear_bits_prph(priv, APMG_PCIDEV_STT_REG,
APMG_PCIDEV_STT_VAL_L1_ACT_DIS);
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
IWL_DEBUG_INFO(priv, "ucode inst image size is %u\n", len);
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
IWL_DEBUG_INFO(priv, "ucode inst image size is %u\n", len);
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
IWL_DEBUG_INFO(priv, "uCode is good in inst SRAM\n");
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
IWL_DEBUG_INFO(priv, "Alive ucode status 0x%08X revision "
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
int subtype, int alternate_subtype)
{
struct iwl_notification_wait alive_wait;
struct iwlagn_alive_data alive_data;
int ret;
enum iwlagn_ucode_subtype old_type;
ret = iwlagn_start_device(priv);
if (ret)
return ret;
iwlagn_init_notification_wait(priv, &alive_wait, REPLY_ALIVE,
iwlagn_alive_fn, &alive_data);
old_type = priv->ucode_type;
priv->ucode_type = subtype;
ret = iwlagn_load_given_ucode(priv, image);
if (ret) {
priv->ucode_type = old_type;
iwlagn_remove_notification(priv, &alive_wait);
return ret;
}
iwl_write32(priv, CSR_RESET, 0);
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
if (alive_data.subtype != subtype &&
alive_data.subtype != alternate_subtype) {
IWL_ERR(priv,
"Loaded ucode is not expected type (got %d, expected %d)!\n",
alive_data.subtype, subtype);
priv->ucode_type = old_type;
return -EIO;
}
ret = iwl_verify_ucode(priv, image);
if (ret) {
priv->ucode_type = old_type;
return ret;
}
msleep(5);
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
if (priv->ucode_type != UCODE_SUBTYPE_NONE_LOADED)
return 0;
iwlagn_init_notification_wait(priv, &calib_wait,
CALIBRATION_COMPLETE_NOTIFICATION,
NULL, NULL);
ret = iwlagn_load_ucode_wait_alive(priv, &priv->ucode_init,
UCODE_SUBTYPE_INIT, -1);
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
iwlagn_stop_device(priv);
return ret;
}
