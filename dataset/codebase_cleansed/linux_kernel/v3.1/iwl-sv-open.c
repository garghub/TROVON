static inline int get_event_length(struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
if (pkt)
return le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
else
return 0;
}
static void iwl_testmode_ucode_rx_pkt(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct ieee80211_hw *hw = priv->hw;
struct sk_buff *skb;
void *data;
int length;
data = (void *)rxb_addr(rxb);
length = get_event_length(rxb);
if (!data || length == 0)
return;
skb = cfg80211_testmode_alloc_event_skb(hw->wiphy, 20 + length,
GFP_ATOMIC);
if (skb == NULL) {
IWL_DEBUG_INFO(priv,
"Run out of memory for messages to user space ?\n");
return;
}
NLA_PUT_U32(skb, IWL_TM_ATTR_COMMAND, IWL_TM_CMD_DEV2APP_UCODE_RX_PKT);
NLA_PUT(skb, IWL_TM_ATTR_UCODE_RX_PKT, length, data);
cfg80211_testmode_event(skb, GFP_ATOMIC);
return;
nla_put_failure:
kfree_skb(skb);
IWL_DEBUG_INFO(priv, "Ouch, overran buffer, check allocation!\n");
}
void iwl_testmode_init(struct iwl_priv *priv)
{
priv->pre_rx_handler = iwl_testmode_ucode_rx_pkt;
priv->testmode_trace.trace_enabled = false;
}
static void iwl_trace_cleanup(struct iwl_priv *priv)
{
if (priv->testmode_trace.trace_enabled) {
if (priv->testmode_trace.cpu_addr &&
priv->testmode_trace.dma_addr)
dma_free_coherent(priv->bus->dev,
priv->testmode_trace.total_size,
priv->testmode_trace.cpu_addr,
priv->testmode_trace.dma_addr);
priv->testmode_trace.trace_enabled = false;
priv->testmode_trace.cpu_addr = NULL;
priv->testmode_trace.trace_addr = NULL;
priv->testmode_trace.dma_addr = 0;
priv->testmode_trace.buff_size = 0;
priv->testmode_trace.total_size = 0;
}
}
void iwl_testmode_cleanup(struct iwl_priv *priv)
{
iwl_trace_cleanup(priv);
}
static int iwl_testmode_ucode(struct ieee80211_hw *hw, struct nlattr **tb)
{
struct iwl_priv *priv = hw->priv;
struct iwl_host_cmd cmd;
memset(&cmd, 0, sizeof(struct iwl_host_cmd));
if (!tb[IWL_TM_ATTR_UCODE_CMD_ID] ||
!tb[IWL_TM_ATTR_UCODE_CMD_DATA]) {
IWL_DEBUG_INFO(priv,
"Error finding ucode command mandatory fields\n");
return -ENOMSG;
}
cmd.flags = CMD_ON_DEMAND;
cmd.id = nla_get_u8(tb[IWL_TM_ATTR_UCODE_CMD_ID]);
cmd.data[0] = nla_data(tb[IWL_TM_ATTR_UCODE_CMD_DATA]);
cmd.len[0] = nla_len(tb[IWL_TM_ATTR_UCODE_CMD_DATA]);
cmd.dataflags[0] = IWL_HCMD_DFL_NOCOPY;
IWL_INFO(priv, "testmode ucode command ID 0x%x, flags 0x%x,"
" len %d\n", cmd.id, cmd.flags, cmd.len[0]);
return trans_send_cmd(&priv->trans, &cmd);
}
static int iwl_testmode_reg(struct ieee80211_hw *hw, struct nlattr **tb)
{
struct iwl_priv *priv = hw->priv;
u32 ofs, val32;
u8 val8;
struct sk_buff *skb;
int status = 0;
if (!tb[IWL_TM_ATTR_REG_OFFSET]) {
IWL_DEBUG_INFO(priv, "Error finding register offset\n");
return -ENOMSG;
}
ofs = nla_get_u32(tb[IWL_TM_ATTR_REG_OFFSET]);
IWL_INFO(priv, "testmode register access command offset 0x%x\n", ofs);
switch (nla_get_u32(tb[IWL_TM_ATTR_COMMAND])) {
case IWL_TM_CMD_APP2DEV_REG_READ32:
val32 = iwl_read32(priv, ofs);
IWL_INFO(priv, "32bit value to read 0x%x\n", val32);
skb = cfg80211_testmode_alloc_reply_skb(hw->wiphy, 20);
if (!skb) {
IWL_DEBUG_INFO(priv, "Error allocating memory\n");
return -ENOMEM;
}
NLA_PUT_U32(skb, IWL_TM_ATTR_REG_VALUE32, val32);
status = cfg80211_testmode_reply(skb);
if (status < 0)
IWL_DEBUG_INFO(priv,
"Error sending msg : %d\n", status);
break;
case IWL_TM_CMD_APP2DEV_REG_WRITE32:
if (!tb[IWL_TM_ATTR_REG_VALUE32]) {
IWL_DEBUG_INFO(priv,
"Error finding value to write\n");
return -ENOMSG;
} else {
val32 = nla_get_u32(tb[IWL_TM_ATTR_REG_VALUE32]);
IWL_INFO(priv, "32bit value to write 0x%x\n", val32);
iwl_write32(priv, ofs, val32);
}
break;
case IWL_TM_CMD_APP2DEV_REG_WRITE8:
if (!tb[IWL_TM_ATTR_REG_VALUE8]) {
IWL_DEBUG_INFO(priv, "Error finding value to write\n");
return -ENOMSG;
} else {
val8 = nla_get_u8(tb[IWL_TM_ATTR_REG_VALUE8]);
IWL_INFO(priv, "8bit value to write 0x%x\n", val8);
iwl_write8(priv, ofs, val8);
}
break;
default:
IWL_DEBUG_INFO(priv, "Unknown testmode register command ID\n");
return -ENOSYS;
}
return status;
nla_put_failure:
kfree_skb(skb);
return -EMSGSIZE;
}
static int iwl_testmode_cfg_init_calib(struct iwl_priv *priv)
{
struct iwl_notification_wait calib_wait;
int ret;
iwlagn_init_notification_wait(priv, &calib_wait,
CALIBRATION_COMPLETE_NOTIFICATION,
NULL, NULL);
ret = iwlagn_init_alive_start(priv);
if (ret) {
IWL_DEBUG_INFO(priv,
"Error configuring init calibration: %d\n", ret);
goto cfg_init_calib_error;
}
ret = iwlagn_wait_notification(priv, &calib_wait, 2 * HZ);
if (ret)
IWL_DEBUG_INFO(priv, "Error detecting"
" CALIBRATION_COMPLETE_NOTIFICATION: %d\n", ret);
return ret;
cfg_init_calib_error:
iwlagn_remove_notification(priv, &calib_wait);
return ret;
}
static int iwl_testmode_driver(struct ieee80211_hw *hw, struct nlattr **tb)
{
struct iwl_priv *priv = hw->priv;
struct sk_buff *skb;
unsigned char *rsp_data_ptr = NULL;
int status = 0, rsp_data_len = 0;
switch (nla_get_u32(tb[IWL_TM_ATTR_COMMAND])) {
case IWL_TM_CMD_APP2DEV_GET_DEVICENAME:
rsp_data_ptr = (unsigned char *)priv->cfg->name;
rsp_data_len = strlen(priv->cfg->name);
skb = cfg80211_testmode_alloc_reply_skb(hw->wiphy,
rsp_data_len + 20);
if (!skb) {
IWL_DEBUG_INFO(priv,
"Error allocating memory\n");
return -ENOMEM;
}
NLA_PUT_U32(skb, IWL_TM_ATTR_COMMAND,
IWL_TM_CMD_DEV2APP_SYNC_RSP);
NLA_PUT(skb, IWL_TM_ATTR_SYNC_RSP,
rsp_data_len, rsp_data_ptr);
status = cfg80211_testmode_reply(skb);
if (status < 0)
IWL_DEBUG_INFO(priv, "Error sending msg : %d\n",
status);
break;
case IWL_TM_CMD_APP2DEV_LOAD_INIT_FW:
status = iwlagn_load_ucode_wait_alive(priv, &priv->ucode_init,
IWL_UCODE_INIT);
if (status)
IWL_DEBUG_INFO(priv,
"Error loading init ucode: %d\n", status);
break;
case IWL_TM_CMD_APP2DEV_CFG_INIT_CALIB:
iwl_testmode_cfg_init_calib(priv);
trans_stop_device(&priv->trans);
break;
case IWL_TM_CMD_APP2DEV_LOAD_RUNTIME_FW:
status = iwlagn_load_ucode_wait_alive(priv,
&priv->ucode_rt,
IWL_UCODE_REGULAR);
if (status) {
IWL_DEBUG_INFO(priv,
"Error loading runtime ucode: %d\n", status);
break;
}
status = iwl_alive_start(priv);
if (status)
IWL_DEBUG_INFO(priv,
"Error starting the device: %d\n", status);
break;
case IWL_TM_CMD_APP2DEV_GET_EEPROM:
if (priv->eeprom) {
skb = cfg80211_testmode_alloc_reply_skb(hw->wiphy,
priv->cfg->base_params->eeprom_size + 20);
if (!skb) {
IWL_DEBUG_INFO(priv,
"Error allocating memory\n");
return -ENOMEM;
}
NLA_PUT_U32(skb, IWL_TM_ATTR_COMMAND,
IWL_TM_CMD_DEV2APP_EEPROM_RSP);
NLA_PUT(skb, IWL_TM_ATTR_EEPROM,
priv->cfg->base_params->eeprom_size,
priv->eeprom);
status = cfg80211_testmode_reply(skb);
if (status < 0)
IWL_DEBUG_INFO(priv,
"Error sending msg : %d\n",
status);
} else
return -EFAULT;
break;
case IWL_TM_CMD_APP2DEV_FIXRATE_REQ:
if (!tb[IWL_TM_ATTR_FIXRATE]) {
IWL_DEBUG_INFO(priv,
"Error finding fixrate setting\n");
return -ENOMSG;
}
priv->tm_fixed_rate = nla_get_u32(tb[IWL_TM_ATTR_FIXRATE]);
break;
default:
IWL_DEBUG_INFO(priv, "Unknown testmode driver command ID\n");
return -ENOSYS;
}
return status;
nla_put_failure:
kfree_skb(skb);
return -EMSGSIZE;
}
static int iwl_testmode_trace(struct ieee80211_hw *hw, struct nlattr **tb)
{
struct iwl_priv *priv = hw->priv;
struct sk_buff *skb;
int status = 0;
struct device *dev = priv->bus->dev;
switch (nla_get_u32(tb[IWL_TM_ATTR_COMMAND])) {
case IWL_TM_CMD_APP2DEV_BEGIN_TRACE:
if (priv->testmode_trace.trace_enabled)
return -EBUSY;
if (!tb[IWL_TM_ATTR_TRACE_SIZE])
priv->testmode_trace.buff_size = TRACE_BUFF_SIZE_DEF;
else
priv->testmode_trace.buff_size =
nla_get_u32(tb[IWL_TM_ATTR_TRACE_SIZE]);
if (!priv->testmode_trace.buff_size)
return -EINVAL;
if (priv->testmode_trace.buff_size < TRACE_BUFF_SIZE_MIN ||
priv->testmode_trace.buff_size > TRACE_BUFF_SIZE_MAX)
return -EINVAL;
priv->testmode_trace.total_size =
priv->testmode_trace.buff_size + TRACE_BUFF_PADD;
priv->testmode_trace.cpu_addr =
dma_alloc_coherent(dev,
priv->testmode_trace.total_size,
&priv->testmode_trace.dma_addr,
GFP_KERNEL);
if (!priv->testmode_trace.cpu_addr)
return -ENOMEM;
priv->testmode_trace.trace_enabled = true;
priv->testmode_trace.trace_addr = (u8 *)PTR_ALIGN(
priv->testmode_trace.cpu_addr, 0x100);
memset(priv->testmode_trace.trace_addr, 0x03B,
priv->testmode_trace.buff_size);
skb = cfg80211_testmode_alloc_reply_skb(hw->wiphy,
sizeof(priv->testmode_trace.dma_addr) + 20);
if (!skb) {
IWL_DEBUG_INFO(priv,
"Error allocating memory\n");
iwl_trace_cleanup(priv);
return -ENOMEM;
}
NLA_PUT(skb, IWL_TM_ATTR_TRACE_ADDR,
sizeof(priv->testmode_trace.dma_addr),
(u64 *)&priv->testmode_trace.dma_addr);
status = cfg80211_testmode_reply(skb);
if (status < 0) {
IWL_DEBUG_INFO(priv,
"Error sending msg : %d\n",
status);
}
priv->testmode_trace.num_chunks =
DIV_ROUND_UP(priv->testmode_trace.buff_size,
TRACE_CHUNK_SIZE);
break;
case IWL_TM_CMD_APP2DEV_END_TRACE:
iwl_trace_cleanup(priv);
break;
default:
IWL_DEBUG_INFO(priv, "Unknown testmode mem command ID\n");
return -ENOSYS;
}
return status;
nla_put_failure:
kfree_skb(skb);
if (nla_get_u32(tb[IWL_TM_ATTR_COMMAND]) ==
IWL_TM_CMD_APP2DEV_BEGIN_TRACE)
iwl_trace_cleanup(priv);
return -EMSGSIZE;
}
static int iwl_testmode_trace_dump(struct ieee80211_hw *hw, struct nlattr **tb,
struct sk_buff *skb,
struct netlink_callback *cb)
{
struct iwl_priv *priv = hw->priv;
int idx, length;
if (priv->testmode_trace.trace_enabled &&
priv->testmode_trace.trace_addr) {
idx = cb->args[4];
if (idx >= priv->testmode_trace.num_chunks)
return -ENOENT;
length = TRACE_CHUNK_SIZE;
if (((idx + 1) == priv->testmode_trace.num_chunks) &&
(priv->testmode_trace.buff_size % TRACE_CHUNK_SIZE))
length = priv->testmode_trace.buff_size %
TRACE_CHUNK_SIZE;
NLA_PUT(skb, IWL_TM_ATTR_TRACE_DUMP, length,
priv->testmode_trace.trace_addr +
(TRACE_CHUNK_SIZE * idx));
idx++;
cb->args[4] = idx;
return 0;
} else
return -EFAULT;
nla_put_failure:
return -ENOBUFS;
}
static int iwl_testmode_ownership(struct ieee80211_hw *hw, struct nlattr **tb)
{
struct iwl_priv *priv = hw->priv;
u8 owner;
if (!tb[IWL_TM_ATTR_UCODE_OWNER]) {
IWL_DEBUG_INFO(priv, "Error finding ucode owner\n");
return -ENOMSG;
}
owner = nla_get_u8(tb[IWL_TM_ATTR_UCODE_OWNER]);
if ((owner == IWL_OWNERSHIP_DRIVER) || (owner == IWL_OWNERSHIP_TM))
priv->ucode_owner = owner;
else {
IWL_DEBUG_INFO(priv, "Invalid owner\n");
return -EINVAL;
}
return 0;
}
int iwl_testmode_cmd(struct ieee80211_hw *hw, void *data, int len)
{
struct nlattr *tb[IWL_TM_ATTR_MAX];
struct iwl_priv *priv = hw->priv;
int result;
result = nla_parse(tb, IWL_TM_ATTR_MAX - 1, data, len,
iwl_testmode_gnl_msg_policy);
if (result != 0) {
IWL_DEBUG_INFO(priv,
"Error parsing the gnl message : %d\n", result);
return result;
}
if (!tb[IWL_TM_ATTR_COMMAND]) {
IWL_DEBUG_INFO(priv, "Error finding testmode command type\n");
return -ENOMSG;
}
mutex_lock(&priv->mutex);
switch (nla_get_u32(tb[IWL_TM_ATTR_COMMAND])) {
case IWL_TM_CMD_APP2DEV_UCODE:
IWL_DEBUG_INFO(priv, "testmode cmd to uCode\n");
result = iwl_testmode_ucode(hw, tb);
break;
case IWL_TM_CMD_APP2DEV_REG_READ32:
case IWL_TM_CMD_APP2DEV_REG_WRITE32:
case IWL_TM_CMD_APP2DEV_REG_WRITE8:
IWL_DEBUG_INFO(priv, "testmode cmd to register\n");
result = iwl_testmode_reg(hw, tb);
break;
case IWL_TM_CMD_APP2DEV_GET_DEVICENAME:
case IWL_TM_CMD_APP2DEV_LOAD_INIT_FW:
case IWL_TM_CMD_APP2DEV_CFG_INIT_CALIB:
case IWL_TM_CMD_APP2DEV_LOAD_RUNTIME_FW:
case IWL_TM_CMD_APP2DEV_GET_EEPROM:
case IWL_TM_CMD_APP2DEV_FIXRATE_REQ:
IWL_DEBUG_INFO(priv, "testmode cmd to driver\n");
result = iwl_testmode_driver(hw, tb);
break;
case IWL_TM_CMD_APP2DEV_BEGIN_TRACE:
case IWL_TM_CMD_APP2DEV_END_TRACE:
case IWL_TM_CMD_APP2DEV_READ_TRACE:
IWL_DEBUG_INFO(priv, "testmode uCode trace cmd to driver\n");
result = iwl_testmode_trace(hw, tb);
break;
case IWL_TM_CMD_APP2DEV_OWNERSHIP:
IWL_DEBUG_INFO(priv, "testmode change uCode ownership\n");
result = iwl_testmode_ownership(hw, tb);
break;
default:
IWL_DEBUG_INFO(priv, "Unknown testmode command\n");
result = -ENOSYS;
break;
}
mutex_unlock(&priv->mutex);
return result;
}
int iwl_testmode_dump(struct ieee80211_hw *hw, struct sk_buff *skb,
struct netlink_callback *cb,
void *data, int len)
{
struct nlattr *tb[IWL_TM_ATTR_MAX];
struct iwl_priv *priv = hw->priv;
int result;
u32 cmd;
if (cb->args[3]) {
cmd = cb->args[3] - 1;
} else {
result = nla_parse(tb, IWL_TM_ATTR_MAX - 1, data, len,
iwl_testmode_gnl_msg_policy);
if (result) {
IWL_DEBUG_INFO(priv,
"Error parsing the gnl message : %d\n", result);
return result;
}
if (!tb[IWL_TM_ATTR_COMMAND]) {
IWL_DEBUG_INFO(priv,
"Error finding testmode command type\n");
return -ENOMSG;
}
cmd = nla_get_u32(tb[IWL_TM_ATTR_COMMAND]);
cb->args[3] = cmd + 1;
}
mutex_lock(&priv->mutex);
switch (cmd) {
case IWL_TM_CMD_APP2DEV_READ_TRACE:
IWL_DEBUG_INFO(priv, "uCode trace cmd to driver\n");
result = iwl_testmode_trace_dump(hw, tb, skb, cb);
break;
default:
result = -EINVAL;
break;
}
mutex_unlock(&priv->mutex);
return result;
}
