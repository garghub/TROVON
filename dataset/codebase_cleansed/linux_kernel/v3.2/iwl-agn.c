void iwl_update_chain_flags(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
for_each_context(priv, ctx) {
iwlagn_set_rxon_chain(priv, ctx);
if (ctx->active.rx_chain != ctx->staging.rx_chain)
iwlagn_commit_rxon(priv, ctx);
}
}
static void iwl_set_beacon_tim(struct iwl_priv *priv,
struct iwl_tx_beacon_cmd *tx_beacon_cmd,
u8 *beacon, u32 frame_size)
{
u16 tim_idx;
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)beacon;
tim_idx = mgmt->u.beacon.variable - beacon;
while ((tim_idx < (frame_size - 2)) &&
(beacon[tim_idx] != WLAN_EID_TIM))
tim_idx += beacon[tim_idx+1] + 2;
if ((tim_idx < (frame_size - 1)) && (beacon[tim_idx] == WLAN_EID_TIM)) {
tx_beacon_cmd->tim_idx = cpu_to_le16(tim_idx);
tx_beacon_cmd->tim_size = beacon[tim_idx+1];
} else
IWL_WARN(priv, "Unable to find TIM Element in beacon\n");
}
int iwlagn_send_beacon_cmd(struct iwl_priv *priv)
{
struct iwl_tx_beacon_cmd *tx_beacon_cmd;
struct iwl_host_cmd cmd = {
.id = REPLY_TX_BEACON,
.flags = CMD_SYNC,
};
struct ieee80211_tx_info *info;
u32 frame_size;
u32 rate_flags;
u32 rate;
lockdep_assert_held(&priv->shrd->mutex);
if (!priv->beacon_ctx) {
IWL_ERR(priv, "trying to build beacon w/o beacon context!\n");
return 0;
}
if (WARN_ON(!priv->beacon_skb))
return -EINVAL;
if (!priv->beacon_cmd)
priv->beacon_cmd = kzalloc(sizeof(*tx_beacon_cmd), GFP_KERNEL);
tx_beacon_cmd = priv->beacon_cmd;
if (!tx_beacon_cmd)
return -ENOMEM;
frame_size = priv->beacon_skb->len;
tx_beacon_cmd->tx.len = cpu_to_le16((u16)frame_size);
tx_beacon_cmd->tx.sta_id = priv->beacon_ctx->bcast_sta_id;
tx_beacon_cmd->tx.stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
tx_beacon_cmd->tx.tx_flags = TX_CMD_FLG_SEQ_CTL_MSK |
TX_CMD_FLG_TSF_MSK | TX_CMD_FLG_STA_RATE_MSK;
iwl_set_beacon_tim(priv, tx_beacon_cmd, priv->beacon_skb->data,
frame_size);
info = IEEE80211_SKB_CB(priv->beacon_skb);
if (info->control.rates[0].idx < 0 ||
info->control.rates[0].flags & IEEE80211_TX_RC_MCS)
rate = 0;
else
rate = info->control.rates[0].idx;
priv->mgmt_tx_ant = iwl_toggle_tx_ant(priv, priv->mgmt_tx_ant,
hw_params(priv).valid_tx_ant);
rate_flags = iwl_ant_idx_to_flags(priv->mgmt_tx_ant);
if (info->band == IEEE80211_BAND_5GHZ)
rate += IWL_FIRST_OFDM_RATE;
else if (rate >= IWL_FIRST_CCK_RATE && rate <= IWL_LAST_CCK_RATE)
rate_flags |= RATE_MCS_CCK_MSK;
tx_beacon_cmd->tx.rate_n_flags =
iwl_hw_set_rate_n_flags(rate, rate_flags);
cmd.len[0] = sizeof(*tx_beacon_cmd);
cmd.data[0] = tx_beacon_cmd;
cmd.dataflags[0] = IWL_HCMD_DFL_NOCOPY;
cmd.len[1] = frame_size;
cmd.data[1] = priv->beacon_skb->data;
cmd.dataflags[1] = IWL_HCMD_DFL_NOCOPY;
return iwl_trans_send_cmd(trans(priv), &cmd);
}
static void iwl_bg_beacon_update(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, beacon_update);
struct sk_buff *beacon;
mutex_lock(&priv->shrd->mutex);
if (!priv->beacon_ctx) {
IWL_ERR(priv, "updating beacon w/o beacon context!\n");
goto out;
}
if (priv->beacon_ctx->vif->type != NL80211_IFTYPE_AP) {
goto out;
}
beacon = ieee80211_beacon_get(priv->hw, priv->beacon_ctx->vif);
if (!beacon) {
IWL_ERR(priv, "update beacon failed -- keeping old\n");
goto out;
}
dev_kfree_skb(priv->beacon_skb);
priv->beacon_skb = beacon;
iwlagn_send_beacon_cmd(priv);
out:
mutex_unlock(&priv->shrd->mutex);
}
static void iwl_bg_bt_runtime_config(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, bt_runtime_config);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
return;
if (!iwl_is_ready_rf(priv->shrd))
return;
iwlagn_send_advance_bt_config(priv);
}
static void iwl_bg_bt_full_concurrency(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, bt_full_concurrency);
struct iwl_rxon_context *ctx;
mutex_lock(&priv->shrd->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
goto out;
if (!iwl_is_ready_rf(priv->shrd))
goto out;
IWL_DEBUG_INFO(priv, "BT coex in %s mode\n",
priv->bt_full_concurrent ?
"full concurrency" : "3-wire");
for_each_context(priv, ctx) {
iwlagn_set_rxon_chain(priv, ctx);
iwlagn_commit_rxon(priv, ctx);
}
iwlagn_send_advance_bt_config(priv);
out:
mutex_unlock(&priv->shrd->mutex);
}
static void iwl_bg_statistics_periodic(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
return;
if (!iwl_is_ready_rf(priv->shrd))
return;
iwl_send_statistics_request(priv, CMD_ASYNC, false);
}
static void iwl_print_cont_event_trace(struct iwl_priv *priv, u32 base,
u32 start_idx, u32 num_events,
u32 mode)
{
u32 i;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
if (mode == 0)
ptr = base + (4 * sizeof(u32)) + (start_idx * 2 * sizeof(u32));
else
ptr = base + (4 * sizeof(u32)) + (start_idx * 3 * sizeof(u32));
spin_lock_irqsave(&bus(priv)->reg_lock, reg_flags);
if (iwl_grab_nic_access(bus(priv))) {
spin_unlock_irqrestore(&bus(priv)->reg_lock, reg_flags);
return;
}
iwl_write32(bus(priv), HBUS_TARG_MEM_RADDR, ptr);
rmb();
for (i = 0; i < num_events; i++) {
ev = iwl_read32(bus(priv), HBUS_TARG_MEM_RDAT);
time = iwl_read32(bus(priv), HBUS_TARG_MEM_RDAT);
if (mode == 0) {
trace_iwlwifi_dev_ucode_cont_event(priv,
0, time, ev);
} else {
data = iwl_read32(bus(priv), HBUS_TARG_MEM_RDAT);
trace_iwlwifi_dev_ucode_cont_event(priv,
time, data, ev);
}
}
iwl_release_nic_access(bus(priv));
spin_unlock_irqrestore(&bus(priv)->reg_lock, reg_flags);
}
static void iwl_continuous_event_trace(struct iwl_priv *priv)
{
u32 capacity;
u32 base;
u32 mode;
u32 num_wraps;
u32 next_entry;
base = priv->device_pointers.error_event_table;
if (iwlagn_hw_valid_rtc_data_addr(base)) {
capacity = iwl_read_targ_mem(bus(priv), base);
num_wraps = iwl_read_targ_mem(bus(priv),
base + (2 * sizeof(u32)));
mode = iwl_read_targ_mem(bus(priv), base + (1 * sizeof(u32)));
next_entry = iwl_read_targ_mem(bus(priv),
base + (3 * sizeof(u32)));
} else
return;
if (num_wraps == priv->event_log.num_wraps) {
iwl_print_cont_event_trace(priv,
base, priv->event_log.next_entry,
next_entry - priv->event_log.next_entry,
mode);
priv->event_log.non_wraps_count++;
} else {
if ((num_wraps - priv->event_log.num_wraps) > 1)
priv->event_log.wraps_more_count++;
else
priv->event_log.wraps_once_count++;
trace_iwlwifi_dev_ucode_wrap_event(priv,
num_wraps - priv->event_log.num_wraps,
next_entry, priv->event_log.next_entry);
if (next_entry < priv->event_log.next_entry) {
iwl_print_cont_event_trace(priv, base,
priv->event_log.next_entry,
capacity - priv->event_log.next_entry,
mode);
iwl_print_cont_event_trace(priv, base, 0,
next_entry, mode);
} else {
iwl_print_cont_event_trace(priv, base,
next_entry, capacity - next_entry,
mode);
iwl_print_cont_event_trace(priv, base, 0,
next_entry, mode);
}
}
priv->event_log.num_wraps = num_wraps;
priv->event_log.next_entry = next_entry;
}
static void iwl_bg_ucode_trace(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
return;
if (priv->event_log.ucode_trace) {
iwl_continuous_event_trace(priv);
mod_timer(&priv->ucode_trace,
jiffies + msecs_to_jiffies(UCODE_TRACE_PERIOD));
}
}
static void iwl_bg_tx_flush(struct work_struct *work)
{
struct iwl_priv *priv =
container_of(work, struct iwl_priv, tx_flush);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
return;
if (!iwl_is_ready_rf(priv->shrd))
return;
IWL_DEBUG_INFO(priv, "device request: flush all tx frames\n");
iwlagn_dev_txfifo_flush(priv, IWL_DROP_ALL);
}
static void iwl_free_fw_desc(struct iwl_priv *priv, struct fw_desc *desc)
{
if (desc->v_addr)
dma_free_coherent(bus(priv)->dev, desc->len,
desc->v_addr, desc->p_addr);
desc->v_addr = NULL;
desc->len = 0;
}
static void iwl_free_fw_img(struct iwl_priv *priv, struct fw_img *img)
{
iwl_free_fw_desc(priv, &img->code);
iwl_free_fw_desc(priv, &img->data);
}
static void iwl_dealloc_ucode(struct iwl_priv *priv)
{
iwl_free_fw_img(priv, &priv->ucode_rt);
iwl_free_fw_img(priv, &priv->ucode_init);
iwl_free_fw_img(priv, &priv->ucode_wowlan);
}
static int iwl_alloc_fw_desc(struct iwl_priv *priv, struct fw_desc *desc,
const void *data, size_t len)
{
if (!len) {
desc->v_addr = NULL;
return -EINVAL;
}
desc->v_addr = dma_alloc_coherent(bus(priv)->dev, len,
&desc->p_addr, GFP_KERNEL);
if (!desc->v_addr)
return -ENOMEM;
desc->len = len;
memcpy(desc->v_addr, data, len);
return 0;
}
static void iwl_init_context(struct iwl_priv *priv, u32 ucode_flags)
{
int i;
priv->shrd->valid_contexts = BIT(IWL_RXON_CTX_BSS);
if (ucode_flags & IWL_UCODE_TLV_FLAGS_PAN)
priv->shrd->valid_contexts |= BIT(IWL_RXON_CTX_PAN);
for (i = 0; i < NUM_IWL_RXON_CTX; i++)
priv->contexts[i].ctxid = i;
priv->contexts[IWL_RXON_CTX_BSS].always_active = true;
priv->contexts[IWL_RXON_CTX_BSS].is_active = true;
priv->contexts[IWL_RXON_CTX_BSS].rxon_cmd = REPLY_RXON;
priv->contexts[IWL_RXON_CTX_BSS].rxon_timing_cmd = REPLY_RXON_TIMING;
priv->contexts[IWL_RXON_CTX_BSS].rxon_assoc_cmd = REPLY_RXON_ASSOC;
priv->contexts[IWL_RXON_CTX_BSS].qos_cmd = REPLY_QOS_PARAM;
priv->contexts[IWL_RXON_CTX_BSS].ap_sta_id = IWL_AP_ID;
priv->contexts[IWL_RXON_CTX_BSS].wep_key_cmd = REPLY_WEPKEY;
priv->contexts[IWL_RXON_CTX_BSS].exclusive_interface_modes =
BIT(NL80211_IFTYPE_ADHOC);
priv->contexts[IWL_RXON_CTX_BSS].interface_modes =
BIT(NL80211_IFTYPE_STATION);
priv->contexts[IWL_RXON_CTX_BSS].ap_devtype = RXON_DEV_TYPE_AP;
priv->contexts[IWL_RXON_CTX_BSS].ibss_devtype = RXON_DEV_TYPE_IBSS;
priv->contexts[IWL_RXON_CTX_BSS].station_devtype = RXON_DEV_TYPE_ESS;
priv->contexts[IWL_RXON_CTX_BSS].unused_devtype = RXON_DEV_TYPE_ESS;
priv->contexts[IWL_RXON_CTX_PAN].rxon_cmd = REPLY_WIPAN_RXON;
priv->contexts[IWL_RXON_CTX_PAN].rxon_timing_cmd =
REPLY_WIPAN_RXON_TIMING;
priv->contexts[IWL_RXON_CTX_PAN].rxon_assoc_cmd =
REPLY_WIPAN_RXON_ASSOC;
priv->contexts[IWL_RXON_CTX_PAN].qos_cmd = REPLY_WIPAN_QOS_PARAM;
priv->contexts[IWL_RXON_CTX_PAN].ap_sta_id = IWL_AP_ID_PAN;
priv->contexts[IWL_RXON_CTX_PAN].wep_key_cmd = REPLY_WIPAN_WEPKEY;
priv->contexts[IWL_RXON_CTX_PAN].bcast_sta_id = IWLAGN_PAN_BCAST_ID;
priv->contexts[IWL_RXON_CTX_PAN].station_flags = STA_FLG_PAN_STATION;
priv->contexts[IWL_RXON_CTX_PAN].interface_modes =
BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_AP);
if (ucode_flags & IWL_UCODE_TLV_FLAGS_P2P)
priv->contexts[IWL_RXON_CTX_PAN].interface_modes |=
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_P2P_GO);
priv->contexts[IWL_RXON_CTX_PAN].ap_devtype = RXON_DEV_TYPE_CP;
priv->contexts[IWL_RXON_CTX_PAN].station_devtype = RXON_DEV_TYPE_2STA;
priv->contexts[IWL_RXON_CTX_PAN].unused_devtype = RXON_DEV_TYPE_P2P;
BUILD_BUG_ON(NUM_IWL_RXON_CTX != 2);
}
static int __must_check iwl_request_firmware(struct iwl_priv *priv, bool first)
{
const char *name_pre = priv->cfg->fw_name_pre;
char tag[8];
if (first) {
#ifdef CONFIG_IWLWIFI_DEBUG_EXPERIMENTAL_UCODE
priv->fw_index = UCODE_EXPERIMENTAL_INDEX;
strcpy(tag, UCODE_EXPERIMENTAL_TAG);
} else if (priv->fw_index == UCODE_EXPERIMENTAL_INDEX) {
#endif
priv->fw_index = priv->cfg->ucode_api_max;
sprintf(tag, "%d", priv->fw_index);
} else {
priv->fw_index--;
sprintf(tag, "%d", priv->fw_index);
}
if (priv->fw_index < priv->cfg->ucode_api_min) {
IWL_ERR(priv, "no suitable firmware found!\n");
return -ENOENT;
}
sprintf(priv->firmware_name, "%s%s%s", name_pre, tag, ".ucode");
IWL_DEBUG_INFO(priv, "attempting to load firmware %s'%s'\n",
(priv->fw_index == UCODE_EXPERIMENTAL_INDEX)
? "EXPERIMENTAL " : "",
priv->firmware_name);
return request_firmware_nowait(THIS_MODULE, 1, priv->firmware_name,
bus(priv)->dev,
GFP_KERNEL, priv, iwl_ucode_callback);
}
static int iwlagn_load_legacy_firmware(struct iwl_priv *priv,
const struct firmware *ucode_raw,
struct iwlagn_firmware_pieces *pieces)
{
struct iwl_ucode_header *ucode = (void *)ucode_raw->data;
u32 api_ver, hdr_size;
const u8 *src;
priv->ucode_ver = le32_to_cpu(ucode->ver);
api_ver = IWL_UCODE_API(priv->ucode_ver);
switch (api_ver) {
default:
hdr_size = 28;
if (ucode_raw->size < hdr_size) {
IWL_ERR(priv, "File size too small!\n");
return -EINVAL;
}
pieces->build = le32_to_cpu(ucode->u.v2.build);
pieces->inst_size = le32_to_cpu(ucode->u.v2.inst_size);
pieces->data_size = le32_to_cpu(ucode->u.v2.data_size);
pieces->init_size = le32_to_cpu(ucode->u.v2.init_size);
pieces->init_data_size = le32_to_cpu(ucode->u.v2.init_data_size);
src = ucode->u.v2.data;
break;
case 0:
case 1:
case 2:
hdr_size = 24;
if (ucode_raw->size < hdr_size) {
IWL_ERR(priv, "File size too small!\n");
return -EINVAL;
}
pieces->build = 0;
pieces->inst_size = le32_to_cpu(ucode->u.v1.inst_size);
pieces->data_size = le32_to_cpu(ucode->u.v1.data_size);
pieces->init_size = le32_to_cpu(ucode->u.v1.init_size);
pieces->init_data_size = le32_to_cpu(ucode->u.v1.init_data_size);
src = ucode->u.v1.data;
break;
}
if (ucode_raw->size != hdr_size + pieces->inst_size +
pieces->data_size + pieces->init_size +
pieces->init_data_size) {
IWL_ERR(priv,
"uCode file size %d does not match expected size\n",
(int)ucode_raw->size);
return -EINVAL;
}
pieces->inst = src;
src += pieces->inst_size;
pieces->data = src;
src += pieces->data_size;
pieces->init = src;
src += pieces->init_size;
pieces->init_data = src;
src += pieces->init_data_size;
return 0;
}
static int iwlagn_load_firmware(struct iwl_priv *priv,
const struct firmware *ucode_raw,
struct iwlagn_firmware_pieces *pieces,
struct iwlagn_ucode_capabilities *capa)
{
struct iwl_tlv_ucode_header *ucode = (void *)ucode_raw->data;
struct iwl_ucode_tlv *tlv;
size_t len = ucode_raw->size;
const u8 *data;
int wanted_alternative = iwlagn_mod_params.wanted_ucode_alternative;
int tmp;
u64 alternatives;
u32 tlv_len;
enum iwl_ucode_tlv_type tlv_type;
const u8 *tlv_data;
if (len < sizeof(*ucode)) {
IWL_ERR(priv, "uCode has invalid length: %zd\n", len);
return -EINVAL;
}
if (ucode->magic != cpu_to_le32(IWL_TLV_UCODE_MAGIC)) {
IWL_ERR(priv, "invalid uCode magic: 0X%x\n",
le32_to_cpu(ucode->magic));
return -EINVAL;
}
alternatives = le64_to_cpu(ucode->alternatives);
tmp = wanted_alternative;
if (wanted_alternative > 63)
wanted_alternative = 63;
while (wanted_alternative && !(alternatives & BIT(wanted_alternative)))
wanted_alternative--;
if (wanted_alternative && wanted_alternative != tmp)
IWL_WARN(priv,
"uCode alternative %d not available, choosing %d\n",
tmp, wanted_alternative);
priv->ucode_ver = le32_to_cpu(ucode->ver);
pieces->build = le32_to_cpu(ucode->build);
data = ucode->data;
len -= sizeof(*ucode);
while (len >= sizeof(*tlv)) {
u16 tlv_alt;
len -= sizeof(*tlv);
tlv = (void *)data;
tlv_len = le32_to_cpu(tlv->length);
tlv_type = le16_to_cpu(tlv->type);
tlv_alt = le16_to_cpu(tlv->alternative);
tlv_data = tlv->data;
if (len < tlv_len) {
IWL_ERR(priv, "invalid TLV len: %zd/%u\n",
len, tlv_len);
return -EINVAL;
}
len -= ALIGN(tlv_len, 4);
data += sizeof(*tlv) + ALIGN(tlv_len, 4);
if (tlv_alt != 0 && tlv_alt != wanted_alternative)
continue;
switch (tlv_type) {
case IWL_UCODE_TLV_INST:
pieces->inst = tlv_data;
pieces->inst_size = tlv_len;
break;
case IWL_UCODE_TLV_DATA:
pieces->data = tlv_data;
pieces->data_size = tlv_len;
break;
case IWL_UCODE_TLV_INIT:
pieces->init = tlv_data;
pieces->init_size = tlv_len;
break;
case IWL_UCODE_TLV_INIT_DATA:
pieces->init_data = tlv_data;
pieces->init_data_size = tlv_len;
break;
case IWL_UCODE_TLV_BOOT:
IWL_ERR(priv, "Found unexpected BOOT ucode\n");
break;
case IWL_UCODE_TLV_PROBE_MAX_LEN:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
capa->max_probe_length =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_PAN:
if (tlv_len)
goto invalid_tlv_len;
capa->flags |= IWL_UCODE_TLV_FLAGS_PAN;
break;
case IWL_UCODE_TLV_FLAGS:
if (tlv_len < sizeof(u32))
goto invalid_tlv_len;
if (tlv_len % sizeof(u32))
goto invalid_tlv_len;
capa->flags = le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_EVTLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_evtlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_EVTLOG_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_evtlog_size =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_ERRLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_errlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_EVTLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_evtlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_EVTLOG_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_evtlog_size =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_ERRLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_errlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_ENHANCE_SENS_TBL:
if (tlv_len)
goto invalid_tlv_len;
priv->enhance_sensitivity_table = true;
break;
case IWL_UCODE_TLV_WOWLAN_INST:
pieces->wowlan_inst = tlv_data;
pieces->wowlan_inst_size = tlv_len;
break;
case IWL_UCODE_TLV_WOWLAN_DATA:
pieces->wowlan_data = tlv_data;
pieces->wowlan_data_size = tlv_len;
break;
case IWL_UCODE_TLV_PHY_CALIBRATION_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
capa->standard_phy_calibration_size =
le32_to_cpup((__le32 *)tlv_data);
break;
default:
IWL_DEBUG_INFO(priv, "unknown TLV: %d\n", tlv_type);
break;
}
}
if (len) {
IWL_ERR(priv, "invalid TLV after parsing: %zd\n", len);
iwl_print_hex_dump(priv, IWL_DL_FW, (u8 *)data, len);
return -EINVAL;
}
return 0;
invalid_tlv_len:
IWL_ERR(priv, "TLV %d has invalid size: %u\n", tlv_type, tlv_len);
iwl_print_hex_dump(priv, IWL_DL_FW, tlv_data, tlv_len);
return -EINVAL;
}
static void iwl_ucode_callback(const struct firmware *ucode_raw, void *context)
{
struct iwl_priv *priv = context;
struct iwl_ucode_header *ucode;
int err;
struct iwlagn_firmware_pieces pieces;
const unsigned int api_max = priv->cfg->ucode_api_max;
unsigned int api_ok = priv->cfg->ucode_api_ok;
const unsigned int api_min = priv->cfg->ucode_api_min;
u32 api_ver;
char buildstr[25];
u32 build;
struct iwlagn_ucode_capabilities ucode_capa = {
.max_probe_length = 200,
.standard_phy_calibration_size =
IWL_DEFAULT_STANDARD_PHY_CALIBRATE_TBL_SIZE,
};
if (!api_ok)
api_ok = api_max;
memset(&pieces, 0, sizeof(pieces));
if (!ucode_raw) {
if (priv->fw_index <= api_ok)
IWL_ERR(priv,
"request for firmware file '%s' failed.\n",
priv->firmware_name);
goto try_again;
}
IWL_DEBUG_INFO(priv, "Loaded firmware file '%s' (%zd bytes).\n",
priv->firmware_name, ucode_raw->size);
if (ucode_raw->size < 4) {
IWL_ERR(priv, "File size way too small!\n");
goto try_again;
}
ucode = (struct iwl_ucode_header *)ucode_raw->data;
if (ucode->ver)
err = iwlagn_load_legacy_firmware(priv, ucode_raw, &pieces);
else
err = iwlagn_load_firmware(priv, ucode_raw, &pieces,
&ucode_capa);
if (err)
goto try_again;
api_ver = IWL_UCODE_API(priv->ucode_ver);
build = pieces.build;
if (priv->fw_index != UCODE_EXPERIMENTAL_INDEX) {
if (api_ver < api_min || api_ver > api_max) {
IWL_ERR(priv,
"Driver unable to support your firmware API. "
"Driver supports v%u, firmware is v%u.\n",
api_max, api_ver);
goto try_again;
}
if (api_ver < api_ok) {
if (api_ok != api_max)
IWL_ERR(priv, "Firmware has old API version, "
"expected v%u through v%u, got v%u.\n",
api_ok, api_max, api_ver);
else
IWL_ERR(priv, "Firmware has old API version, "
"expected v%u, got v%u.\n",
api_max, api_ver);
IWL_ERR(priv, "New firmware can be obtained from "
"http://www.intellinuxwireless.org/.\n");
}
}
if (build)
sprintf(buildstr, " build %u%s", build,
(priv->fw_index == UCODE_EXPERIMENTAL_INDEX)
? " (EXP)" : "");
else
buildstr[0] = '\0';
IWL_INFO(priv, "loaded firmware version %u.%u.%u.%u%s\n",
IWL_UCODE_MAJOR(priv->ucode_ver),
IWL_UCODE_MINOR(priv->ucode_ver),
IWL_UCODE_API(priv->ucode_ver),
IWL_UCODE_SERIAL(priv->ucode_ver),
buildstr);
snprintf(priv->hw->wiphy->fw_version,
sizeof(priv->hw->wiphy->fw_version),
"%u.%u.%u.%u%s",
IWL_UCODE_MAJOR(priv->ucode_ver),
IWL_UCODE_MINOR(priv->ucode_ver),
IWL_UCODE_API(priv->ucode_ver),
IWL_UCODE_SERIAL(priv->ucode_ver),
buildstr);
IWL_DEBUG_INFO(priv, "f/w package hdr ucode version raw = 0x%x\n",
priv->ucode_ver);
IWL_DEBUG_INFO(priv, "f/w package hdr runtime inst size = %Zd\n",
pieces.inst_size);
IWL_DEBUG_INFO(priv, "f/w package hdr runtime data size = %Zd\n",
pieces.data_size);
IWL_DEBUG_INFO(priv, "f/w package hdr init inst size = %Zd\n",
pieces.init_size);
IWL_DEBUG_INFO(priv, "f/w package hdr init data size = %Zd\n",
pieces.init_data_size);
if (pieces.inst_size > hw_params(priv).max_inst_size) {
IWL_ERR(priv, "uCode instr len %Zd too large to fit in\n",
pieces.inst_size);
goto try_again;
}
if (pieces.data_size > hw_params(priv).max_data_size) {
IWL_ERR(priv, "uCode data len %Zd too large to fit in\n",
pieces.data_size);
goto try_again;
}
if (pieces.init_size > hw_params(priv).max_inst_size) {
IWL_ERR(priv, "uCode init instr len %Zd too large to fit in\n",
pieces.init_size);
goto try_again;
}
if (pieces.init_data_size > hw_params(priv).max_data_size) {
IWL_ERR(priv, "uCode init data len %Zd too large to fit in\n",
pieces.init_data_size);
goto try_again;
}
if (iwl_alloc_fw_desc(priv, &priv->ucode_rt.code,
pieces.inst, pieces.inst_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(priv, &priv->ucode_rt.data,
pieces.data, pieces.data_size))
goto err_pci_alloc;
if (pieces.init_size && pieces.init_data_size) {
if (iwl_alloc_fw_desc(priv, &priv->ucode_init.code,
pieces.init, pieces.init_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(priv, &priv->ucode_init.data,
pieces.init_data, pieces.init_data_size))
goto err_pci_alloc;
}
if (pieces.wowlan_inst_size && pieces.wowlan_data_size) {
if (iwl_alloc_fw_desc(priv, &priv->ucode_wowlan.code,
pieces.wowlan_inst,
pieces.wowlan_inst_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(priv, &priv->ucode_wowlan.data,
pieces.wowlan_data,
pieces.wowlan_data_size))
goto err_pci_alloc;
}
priv->init_evtlog_ptr = pieces.init_evtlog_ptr;
if (pieces.init_evtlog_size)
priv->init_evtlog_size = (pieces.init_evtlog_size - 16)/12;
else
priv->init_evtlog_size =
priv->cfg->base_params->max_event_log_size;
priv->init_errlog_ptr = pieces.init_errlog_ptr;
priv->inst_evtlog_ptr = pieces.inst_evtlog_ptr;
if (pieces.inst_evtlog_size)
priv->inst_evtlog_size = (pieces.inst_evtlog_size - 16)/12;
else
priv->inst_evtlog_size =
priv->cfg->base_params->max_event_log_size;
priv->inst_errlog_ptr = pieces.inst_errlog_ptr;
priv->new_scan_threshold_behaviour =
!!(ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NEWSCAN);
if (!(priv->cfg->sku & EEPROM_SKU_CAP_IPAN_ENABLE))
ucode_capa.flags &= ~IWL_UCODE_TLV_FLAGS_PAN;
if (!(ucode_capa.flags & IWL_UCODE_TLV_FLAGS_PAN))
ucode_capa.flags &= ~IWL_UCODE_TLV_FLAGS_P2P;
if (ucode_capa.flags & IWL_UCODE_TLV_FLAGS_PAN) {
priv->sta_key_max_num = STA_KEY_MAX_NUM_PAN;
priv->shrd->cmd_queue = IWL_IPAN_CMD_QUEUE_NUM;
} else {
priv->sta_key_max_num = STA_KEY_MAX_NUM;
priv->shrd->cmd_queue = IWL_DEFAULT_CMD_QUEUE_NUM;
}
if (ucode_capa.standard_phy_calibration_size >
IWL_MAX_PHY_CALIBRATE_TBL_SIZE)
ucode_capa.standard_phy_calibration_size =
IWL_MAX_STANDARD_PHY_CALIBRATE_TBL_SIZE;
priv->phy_calib_chain_noise_reset_cmd =
ucode_capa.standard_phy_calibration_size;
priv->phy_calib_chain_noise_gain_cmd =
ucode_capa.standard_phy_calibration_size + 1;
iwl_init_context(priv, ucode_capa.flags);
err = iwlagn_mac_setup_register(priv, &ucode_capa);
if (err)
goto out_unbind;
err = iwl_dbgfs_register(priv, DRV_NAME);
if (err)
IWL_ERR(priv, "failed to create debugfs files. Ignoring error: %d\n", err);
release_firmware(ucode_raw);
complete(&priv->firmware_loading_complete);
return;
try_again:
if (iwl_request_firmware(priv, false))
goto out_unbind;
release_firmware(ucode_raw);
return;
err_pci_alloc:
IWL_ERR(priv, "failed to allocate pci memory\n");
iwl_dealloc_ucode(priv);
out_unbind:
complete(&priv->firmware_loading_complete);
device_release_driver(bus(priv)->dev);
release_firmware(ucode_raw);
}
static void iwl_rf_kill_ct_config(struct iwl_priv *priv)
{
struct iwl_ct_kill_config cmd;
struct iwl_ct_kill_throttling_config adv_cmd;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&priv->shrd->lock, flags);
iwl_write32(bus(priv), CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_REG_BIT_CT_KILL_EXIT);
spin_unlock_irqrestore(&priv->shrd->lock, flags);
priv->thermal_throttle.ct_kill_toggle = false;
if (priv->cfg->base_params->support_ct_kill_exit) {
adv_cmd.critical_temperature_enter =
cpu_to_le32(hw_params(priv).ct_kill_threshold);
adv_cmd.critical_temperature_exit =
cpu_to_le32(hw_params(priv).ct_kill_exit_threshold);
ret = iwl_trans_send_cmd_pdu(trans(priv),
REPLY_CT_KILL_CONFIG_CMD,
CMD_SYNC, sizeof(adv_cmd), &adv_cmd);
if (ret)
IWL_ERR(priv, "REPLY_CT_KILL_CONFIG_CMD failed\n");
else
IWL_DEBUG_INFO(priv, "REPLY_CT_KILL_CONFIG_CMD "
"succeeded, critical temperature enter is %d,"
"exit is %d\n",
hw_params(priv).ct_kill_threshold,
hw_params(priv).ct_kill_exit_threshold);
} else {
cmd.critical_temperature_R =
cpu_to_le32(hw_params(priv).ct_kill_threshold);
ret = iwl_trans_send_cmd_pdu(trans(priv),
REPLY_CT_KILL_CONFIG_CMD,
CMD_SYNC, sizeof(cmd), &cmd);
if (ret)
IWL_ERR(priv, "REPLY_CT_KILL_CONFIG_CMD failed\n");
else
IWL_DEBUG_INFO(priv, "REPLY_CT_KILL_CONFIG_CMD "
"succeeded, "
"critical temperature is %d\n",
hw_params(priv).ct_kill_threshold);
}
}
static int iwlagn_send_calib_cfg_rt(struct iwl_priv *priv, u32 cfg)
{
struct iwl_calib_cfg_cmd calib_cfg_cmd;
struct iwl_host_cmd cmd = {
.id = CALIBRATION_CFG_CMD,
.len = { sizeof(struct iwl_calib_cfg_cmd), },
.data = { &calib_cfg_cmd, },
};
memset(&calib_cfg_cmd, 0, sizeof(calib_cfg_cmd));
calib_cfg_cmd.ucd_calib_cfg.once.is_enable = IWL_CALIB_RT_CFG_ALL;
calib_cfg_cmd.ucd_calib_cfg.once.start = cpu_to_le32(cfg);
return iwl_trans_send_cmd(trans(priv), &cmd);
}
static int iwlagn_send_tx_ant_config(struct iwl_priv *priv, u8 valid_tx_ant)
{
struct iwl_tx_ant_config_cmd tx_ant_cmd = {
.valid = cpu_to_le32(valid_tx_ant),
};
if (IWL_UCODE_API(priv->ucode_ver) > 1) {
IWL_DEBUG_HC(priv, "select valid tx ant: %u\n", valid_tx_ant);
return iwl_trans_send_cmd_pdu(trans(priv),
TX_ANT_CONFIGURATION_CMD,
CMD_SYNC,
sizeof(struct iwl_tx_ant_config_cmd),
&tx_ant_cmd);
} else {
IWL_DEBUG_HC(priv, "TX_ANT_CONFIGURATION_CMD not supported\n");
return -EOPNOTSUPP;
}
}
int iwl_alive_start(struct iwl_priv *priv)
{
int ret = 0;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
iwl_reset_ict(trans(priv));
IWL_DEBUG_INFO(priv, "Runtime Alive received.\n");
set_bit(STATUS_ALIVE, &priv->shrd->status);
iwl_setup_watchdog(priv);
if (iwl_is_rfkill(priv->shrd))
return -ERFKILL;
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
if (priv->cfg->bt_params->bt_sco_disable)
priv->bt_enable_pspoll = false;
else
priv->bt_enable_pspoll = true;
priv->bt_valid = IWLAGN_BT_ALL_VALID_MSK;
priv->kill_ack_mask = IWLAGN_BT_KILL_ACK_MASK_DEFAULT;
priv->kill_cts_mask = IWLAGN_BT_KILL_CTS_MASK_DEFAULT;
iwlagn_send_advance_bt_config(priv);
priv->bt_valid = IWLAGN_BT_VALID_ENABLE_FLAGS;
priv->cur_rssi_ctx = NULL;
iwlagn_send_prio_tbl(priv);
ret = iwlagn_send_bt_env(priv, IWL_BT_COEX_ENV_OPEN,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
ret = iwlagn_send_bt_env(priv, IWL_BT_COEX_ENV_CLOSE,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
} else {
iwl_send_bt_config(priv);
}
if (hw_params(priv).calib_rt_cfg)
iwlagn_send_calib_cfg_rt(priv,
hw_params(priv).calib_rt_cfg);
ieee80211_wake_queues(priv->hw);
priv->active_rate = IWL_RATES_MASK;
iwlagn_send_tx_ant_config(priv, priv->cfg->valid_tx_ant);
if (iwl_is_associated_ctx(ctx) && !priv->shrd->wowlan) {
struct iwl_rxon_cmd *active_rxon =
(struct iwl_rxon_cmd *)&ctx->active;
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
active_rxon->filter_flags &= ~RXON_FILTER_ASSOC_MSK;
} else {
struct iwl_rxon_context *tmp;
for_each_context(priv, tmp)
iwl_connection_init_rx_config(priv, tmp);
iwlagn_set_rxon_chain(priv, ctx);
}
if (!priv->shrd->wowlan) {
iwl_reset_run_time_calib(priv);
}
set_bit(STATUS_READY, &priv->shrd->status);
ret = iwlagn_commit_rxon(priv, ctx);
if (ret)
return ret;
iwl_rf_kill_ct_config(priv);
IWL_DEBUG_INFO(priv, "ALIVE processing complete.\n");
return iwl_power_update_mode(priv, true);
}
static void __iwl_down(struct iwl_priv *priv)
{
int exit_pending;
IWL_DEBUG_INFO(priv, DRV_NAME " is going down\n");
iwl_scan_cancel_timeout(priv, 200);
ieee80211_remain_on_channel_expired(priv->hw);
exit_pending =
test_and_set_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
del_timer_sync(&priv->watchdog);
iwl_clear_ucode_stations(priv, NULL);
iwl_dealloc_bcast_stations(priv);
iwl_clear_driver_stations(priv);
priv->bt_status = 0;
priv->cur_rssi_ctx = NULL;
priv->bt_is_sco = 0;
if (priv->cfg->bt_params)
priv->bt_traffic_load =
priv->cfg->bt_params->bt_init_traffic_load;
else
priv->bt_traffic_load = 0;
priv->bt_full_concurrent = false;
priv->bt_ci_compliance = 0;
if (!exit_pending)
clear_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
if (priv->mac80211_registered)
ieee80211_stop_queues(priv->hw);
iwl_trans_stop_device(trans(priv));
priv->shrd->status &=
test_bit(STATUS_RF_KILL_HW, &priv->shrd->status) <<
STATUS_RF_KILL_HW |
test_bit(STATUS_GEO_CONFIGURED, &priv->shrd->status) <<
STATUS_GEO_CONFIGURED |
test_bit(STATUS_FW_ERROR, &priv->shrd->status) <<
STATUS_FW_ERROR |
test_bit(STATUS_EXIT_PENDING, &priv->shrd->status) <<
STATUS_EXIT_PENDING;
dev_kfree_skb(priv->beacon_skb);
priv->beacon_skb = NULL;
}
static void iwl_down(struct iwl_priv *priv)
{
mutex_lock(&priv->shrd->mutex);
__iwl_down(priv);
mutex_unlock(&priv->shrd->mutex);
iwl_cancel_deferred_work(priv);
}
static int __iwl_up(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
int ret;
lockdep_assert_held(&priv->shrd->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status)) {
IWL_WARN(priv, "Exit pending; will not bring the NIC up\n");
return -EIO;
}
for_each_context(priv, ctx) {
ret = iwlagn_alloc_bcast_station(priv, ctx);
if (ret) {
iwl_dealloc_bcast_stations(priv);
return ret;
}
}
ret = iwlagn_run_init_ucode(priv);
if (ret) {
IWL_ERR(priv, "Failed to run INIT ucode: %d\n", ret);
goto error;
}
ret = iwlagn_load_ucode_wait_alive(priv,
&priv->ucode_rt,
IWL_UCODE_REGULAR);
if (ret) {
IWL_ERR(priv, "Failed to start RT ucode: %d\n", ret);
goto error;
}
ret = iwl_alive_start(priv);
if (ret)
goto error;
return 0;
error:
set_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
__iwl_down(priv);
clear_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
IWL_ERR(priv, "Unable to initialize device.\n");
return ret;
}
static void iwl_bg_run_time_calib_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
run_time_calib_work);
mutex_lock(&priv->shrd->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status) ||
test_bit(STATUS_SCANNING, &priv->shrd->status)) {
mutex_unlock(&priv->shrd->mutex);
return;
}
if (priv->start_calib) {
iwl_chain_noise_calibration(priv);
iwl_sensitivity_calibration(priv);
}
mutex_unlock(&priv->shrd->mutex);
}
static void iwlagn_prepare_restart(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
bool bt_full_concurrent;
u8 bt_ci_compliance;
u8 bt_load;
u8 bt_status;
bool bt_is_sco;
lockdep_assert_held(&priv->shrd->mutex);
for_each_context(priv, ctx)
ctx->vif = NULL;
priv->is_open = 0;
bt_full_concurrent = priv->bt_full_concurrent;
bt_ci_compliance = priv->bt_ci_compliance;
bt_load = priv->bt_traffic_load;
bt_status = priv->bt_status;
bt_is_sco = priv->bt_is_sco;
__iwl_down(priv);
priv->bt_full_concurrent = bt_full_concurrent;
priv->bt_ci_compliance = bt_ci_compliance;
priv->bt_traffic_load = bt_load;
priv->bt_status = bt_status;
priv->bt_is_sco = bt_is_sco;
}
static void iwl_bg_restart(struct work_struct *data)
{
struct iwl_priv *priv = container_of(data, struct iwl_priv, restart);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
return;
if (test_and_clear_bit(STATUS_FW_ERROR, &priv->shrd->status)) {
mutex_lock(&priv->shrd->mutex);
iwlagn_prepare_restart(priv);
mutex_unlock(&priv->shrd->mutex);
iwl_cancel_deferred_work(priv);
ieee80211_restart_hw(priv->hw);
} else {
WARN_ON(1);
}
}
static int iwlagn_mac_setup_register(struct iwl_priv *priv,
struct iwlagn_ucode_capabilities *capa)
{
int ret;
struct ieee80211_hw *hw = priv->hw;
struct iwl_rxon_context *ctx;
hw->rate_control_algorithm = "iwl-agn-rs";
hw->flags = IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_NEED_DTIM_PERIOD |
IEEE80211_HW_SPECTRUM_MGMT |
IEEE80211_HW_REPORTS_TX_ACK_STATUS;
hw->flags |= IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_SUPPORTS_DYNAMIC_PS;
if (priv->cfg->sku & EEPROM_SKU_CAP_11N_ENABLE)
hw->flags |= IEEE80211_HW_SUPPORTS_DYNAMIC_SMPS |
IEEE80211_HW_SUPPORTS_STATIC_SMPS;
if (capa->flags & IWL_UCODE_TLV_FLAGS_MFP)
hw->flags |= IEEE80211_HW_MFP_CAPABLE;
hw->sta_data_size = sizeof(struct iwl_station_priv);
hw->vif_data_size = sizeof(struct iwl_vif_priv);
for_each_context(priv, ctx) {
hw->wiphy->interface_modes |= ctx->interface_modes;
hw->wiphy->interface_modes |= ctx->exclusive_interface_modes;
}
BUILD_BUG_ON(NUM_IWL_RXON_CTX != 2);
if (hw->wiphy->interface_modes & BIT(NL80211_IFTYPE_P2P_CLIENT)) {
hw->wiphy->iface_combinations = iwlagn_iface_combinations_p2p;
hw->wiphy->n_iface_combinations =
ARRAY_SIZE(iwlagn_iface_combinations_p2p);
} else if (hw->wiphy->interface_modes & BIT(NL80211_IFTYPE_AP)) {
hw->wiphy->iface_combinations = iwlagn_iface_combinations_dualmode;
hw->wiphy->n_iface_combinations =
ARRAY_SIZE(iwlagn_iface_combinations_dualmode);
}
hw->wiphy->max_remain_on_channel_duration = 1000;
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY |
WIPHY_FLAG_DISABLE_BEACON_HINTS |
WIPHY_FLAG_IBSS_RSN;
if (priv->ucode_wowlan.code.len && device_can_wakeup(bus(priv)->dev)) {
hw->wiphy->wowlan.flags = WIPHY_WOWLAN_MAGIC_PKT |
WIPHY_WOWLAN_DISCONNECT |
WIPHY_WOWLAN_EAP_IDENTITY_REQ |
WIPHY_WOWLAN_RFKILL_RELEASE;
if (!iwlagn_mod_params.sw_crypto)
hw->wiphy->wowlan.flags |=
WIPHY_WOWLAN_SUPPORTS_GTK_REKEY |
WIPHY_WOWLAN_GTK_REKEY_FAILURE;
hw->wiphy->wowlan.n_patterns = IWLAGN_WOWLAN_MAX_PATTERNS;
hw->wiphy->wowlan.pattern_min_len =
IWLAGN_WOWLAN_MIN_PATTERN_LEN;
hw->wiphy->wowlan.pattern_max_len =
IWLAGN_WOWLAN_MAX_PATTERN_LEN;
}
if (iwlagn_mod_params.power_save)
hw->wiphy->flags |= WIPHY_FLAG_PS_ON_BY_DEFAULT;
else
hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
hw->wiphy->max_scan_ssids = PROBE_OPTION_MAX;
hw->wiphy->max_scan_ie_len = capa->max_probe_length - 24 - 2;
hw->queues = 4;
hw->max_listen_interval = IWL_CONN_MAX_LISTEN_INTERVAL;
if (priv->bands[IEEE80211_BAND_2GHZ].n_channels)
priv->hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&priv->bands[IEEE80211_BAND_2GHZ];
if (priv->bands[IEEE80211_BAND_5GHZ].n_channels)
priv->hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&priv->bands[IEEE80211_BAND_5GHZ];
iwl_leds_init(priv);
ret = ieee80211_register_hw(priv->hw);
if (ret) {
IWL_ERR(priv, "Failed to register hw (error %d)\n", ret);
return ret;
}
priv->mac80211_registered = 1;
return 0;
}
static int iwlagn_mac_start(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
int ret;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
ret = __iwl_up(priv);
mutex_unlock(&priv->shrd->mutex);
if (ret)
return ret;
IWL_DEBUG_INFO(priv, "Start UP work done.\n");
if (WARN_ON(!test_bit(STATUS_READY, &priv->shrd->status)))
ret = -EIO;
iwlagn_led_enable(priv);
priv->is_open = 1;
IWL_DEBUG_MAC80211(priv, "leave\n");
return 0;
}
static void iwlagn_mac_stop(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
IWL_DEBUG_MAC80211(priv, "enter\n");
if (!priv->is_open)
return;
priv->is_open = 0;
iwl_down(priv);
flush_workqueue(priv->shrd->workqueue);
iwl_write32(bus(priv), CSR_INT, 0xFFFFFFFF);
iwl_enable_rfkill_int(priv);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
static int iwlagn_send_patterns(struct iwl_priv *priv,
struct cfg80211_wowlan *wowlan)
{
struct iwlagn_wowlan_patterns_cmd *pattern_cmd;
struct iwl_host_cmd cmd = {
.id = REPLY_WOWLAN_PATTERNS,
.dataflags[0] = IWL_HCMD_DFL_NOCOPY,
.flags = CMD_SYNC,
};
int i, err;
if (!wowlan->n_patterns)
return 0;
cmd.len[0] = sizeof(*pattern_cmd) +
wowlan->n_patterns * sizeof(struct iwlagn_wowlan_pattern);
pattern_cmd = kmalloc(cmd.len[0], GFP_KERNEL);
if (!pattern_cmd)
return -ENOMEM;
pattern_cmd->n_patterns = cpu_to_le32(wowlan->n_patterns);
for (i = 0; i < wowlan->n_patterns; i++) {
int mask_len = DIV_ROUND_UP(wowlan->patterns[i].pattern_len, 8);
memcpy(&pattern_cmd->patterns[i].mask,
wowlan->patterns[i].mask, mask_len);
memcpy(&pattern_cmd->patterns[i].pattern,
wowlan->patterns[i].pattern,
wowlan->patterns[i].pattern_len);
pattern_cmd->patterns[i].mask_size = mask_len;
pattern_cmd->patterns[i].pattern_size =
wowlan->patterns[i].pattern_len;
}
cmd.data[0] = pattern_cmd;
err = iwl_trans_send_cmd(trans(priv), &cmd);
kfree(pattern_cmd);
return err;
}
static void iwlagn_mac_set_rekey_data(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_gtk_rekey_data *data)
{
struct iwl_priv *priv = hw->priv;
if (iwlagn_mod_params.sw_crypto)
return;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (priv->contexts[IWL_RXON_CTX_BSS].vif != vif)
goto out;
memcpy(priv->kek, data->kek, NL80211_KEK_LEN);
memcpy(priv->kck, data->kck, NL80211_KCK_LEN);
priv->replay_ctr = cpu_to_le64(be64_to_cpup((__be64 *)&data->replay_ctr));
priv->have_rekey_data = true;
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
static void iwlagn_convert_p1k(u16 *p1k, __le16 *out)
{
int i;
for (i = 0; i < IWLAGN_P1K_SIZE; i++)
out[i] = cpu_to_le16(p1k[i]);
}
static void iwlagn_wowlan_program_keys(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key,
void *_data)
{
struct iwl_priv *priv = hw->priv;
struct wowlan_key_data *data = _data;
struct iwl_rxon_context *ctx = data->ctx;
struct aes_sc *aes_sc, *aes_tx_sc = NULL;
struct tkip_sc *tkip_sc, *tkip_tx_sc = NULL;
struct iwlagn_p1k_cache *rx_p1ks;
u8 *rx_mic_key;
struct ieee80211_key_seq seq;
u32 cur_rx_iv32 = 0;
u16 p1k[IWLAGN_P1K_SIZE];
int ret, i;
mutex_lock(&priv->shrd->mutex);
if ((key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
key->cipher == WLAN_CIPHER_SUITE_WEP104) &&
!sta && !ctx->key_mapping_keys)
ret = iwl_set_default_wep_key(priv, ctx, key);
else
ret = iwl_set_dynamic_key(priv, ctx, key, sta);
if (ret) {
IWL_ERR(priv, "Error setting key during suspend!\n");
data->error = true;
}
switch (key->cipher) {
case WLAN_CIPHER_SUITE_TKIP:
if (sta) {
tkip_sc = data->rsc_tsc->all_tsc_rsc.tkip.unicast_rsc;
tkip_tx_sc = &data->rsc_tsc->all_tsc_rsc.tkip.tsc;
rx_p1ks = data->tkip->rx_uni;
ieee80211_get_key_tx_seq(key, &seq);
tkip_tx_sc->iv16 = cpu_to_le16(seq.tkip.iv16);
tkip_tx_sc->iv32 = cpu_to_le32(seq.tkip.iv32);
ieee80211_get_tkip_p1k_iv(key, seq.tkip.iv32, p1k);
iwlagn_convert_p1k(p1k, data->tkip->tx.p1k);
memcpy(data->tkip->mic_keys.tx,
&key->key[NL80211_TKIP_DATA_OFFSET_TX_MIC_KEY],
IWLAGN_MIC_KEY_SIZE);
rx_mic_key = data->tkip->mic_keys.rx_unicast;
} else {
tkip_sc = data->rsc_tsc->all_tsc_rsc.tkip.multicast_rsc;
rx_p1ks = data->tkip->rx_multi;
rx_mic_key = data->tkip->mic_keys.rx_mcast;
}
for (i = 0; i < IWLAGN_NUM_RSC; i++) {
ieee80211_get_key_rx_seq(key, i, &seq);
tkip_sc[i].iv16 = cpu_to_le16(seq.tkip.iv16);
tkip_sc[i].iv32 = cpu_to_le32(seq.tkip.iv32);
if (seq.tkip.iv32 > cur_rx_iv32)
cur_rx_iv32 = seq.tkip.iv32;
}
ieee80211_get_tkip_rx_p1k(key, data->bssid, cur_rx_iv32, p1k);
iwlagn_convert_p1k(p1k, rx_p1ks[0].p1k);
ieee80211_get_tkip_rx_p1k(key, data->bssid,
cur_rx_iv32 + 1, p1k);
iwlagn_convert_p1k(p1k, rx_p1ks[1].p1k);
memcpy(rx_mic_key,
&key->key[NL80211_TKIP_DATA_OFFSET_RX_MIC_KEY],
IWLAGN_MIC_KEY_SIZE);
data->use_tkip = true;
data->use_rsc_tsc = true;
break;
case WLAN_CIPHER_SUITE_CCMP:
if (sta) {
u8 *pn = seq.ccmp.pn;
aes_sc = data->rsc_tsc->all_tsc_rsc.aes.unicast_rsc;
aes_tx_sc = &data->rsc_tsc->all_tsc_rsc.aes.tsc;
ieee80211_get_key_tx_seq(key, &seq);
aes_tx_sc->pn = cpu_to_le64(
(u64)pn[5] |
((u64)pn[4] << 8) |
((u64)pn[3] << 16) |
((u64)pn[2] << 24) |
((u64)pn[1] << 32) |
((u64)pn[0] << 40));
} else
aes_sc = data->rsc_tsc->all_tsc_rsc.aes.multicast_rsc;
for (i = 0; i < IWLAGN_NUM_RSC; i++) {
u8 *pn = seq.ccmp.pn;
ieee80211_get_key_rx_seq(key, i, &seq);
aes_sc->pn = cpu_to_le64(
(u64)pn[5] |
((u64)pn[4] << 8) |
((u64)pn[3] << 16) |
((u64)pn[2] << 24) |
((u64)pn[1] << 32) |
((u64)pn[0] << 40));
}
data->use_rsc_tsc = true;
break;
}
mutex_unlock(&priv->shrd->mutex);
}
static int iwlagn_mac_suspend(struct ieee80211_hw *hw,
struct cfg80211_wowlan *wowlan)
{
struct iwl_priv *priv = hw->priv;
struct iwlagn_wowlan_wakeup_filter_cmd wakeup_filter_cmd;
struct iwl_rxon_cmd rxon;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct iwlagn_wowlan_kek_kck_material_cmd kek_kck_cmd;
struct iwlagn_wowlan_tkip_params_cmd tkip_cmd = {};
struct wowlan_key_data key_data = {
.ctx = ctx,
.bssid = ctx->active.bssid_addr,
.use_rsc_tsc = false,
.tkip = &tkip_cmd,
.use_tkip = false,
};
int ret, i;
u16 seq;
if (WARN_ON(!wowlan))
return -EINVAL;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (!ctx->vif || ctx->vif->type != NL80211_IFTYPE_STATION ||
!iwl_is_associated_ctx(ctx)) {
ret = 1;
goto out;
}
key_data.rsc_tsc = kzalloc(sizeof(*key_data.rsc_tsc), GFP_KERNEL);
if (!key_data.rsc_tsc) {
ret = -ENOMEM;
goto out;
}
memset(&wakeup_filter_cmd, 0, sizeof(wakeup_filter_cmd));
seq = le16_to_cpu(priv->last_seq_ctl) & IEEE80211_SCTL_SEQ;
wakeup_filter_cmd.non_qos_seq = cpu_to_le16(seq);
for (i = 0; i < 8; i++) {
seq = priv->shrd->tid_data[IWL_AP_ID][i].seq_number;
seq -= 0x10;
wakeup_filter_cmd.qos_seq[i] = cpu_to_le16(seq);
}
if (wowlan->disconnect)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_BEACON_MISS |
IWLAGN_WOWLAN_WAKEUP_LINK_CHANGE);
if (wowlan->magic_pkt)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_MAGIC_PACKET);
if (wowlan->gtk_rekey_failure)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_GTK_REKEY_FAIL);
if (wowlan->eap_identity_req)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_EAP_IDENT_REQ);
if (wowlan->four_way_handshake)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_4WAY_HANDSHAKE);
if (wowlan->rfkill_release)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_RFKILL);
if (wowlan->n_patterns)
wakeup_filter_cmd.enabled |=
cpu_to_le32(IWLAGN_WOWLAN_WAKEUP_PATTERN_MATCH);
iwl_scan_cancel_timeout(priv, 200);
memcpy(&rxon, &ctx->active, sizeof(rxon));
iwl_trans_stop_device(trans(priv));
priv->shrd->wowlan = true;
ret = iwlagn_load_ucode_wait_alive(priv, &priv->ucode_wowlan,
IWL_UCODE_WOWLAN);
if (ret)
goto error;
ret = iwl_alive_start(priv);
if (ret)
goto error;
memcpy(&ctx->staging, &rxon, sizeof(rxon));
ret = iwlagn_commit_rxon(priv, ctx);
if (ret)
goto error;
ret = iwl_power_update_mode(priv, true);
if (ret)
goto error;
if (!iwlagn_mod_params.sw_crypto) {
priv->ucode_key_table = 0;
ctx->key_mapping_keys = 0;
mutex_unlock(&priv->shrd->mutex);
ieee80211_iter_keys(priv->hw, ctx->vif,
iwlagn_wowlan_program_keys,
&key_data);
mutex_lock(&priv->shrd->mutex);
if (key_data.error) {
ret = -EIO;
goto error;
}
if (key_data.use_rsc_tsc) {
struct iwl_host_cmd rsc_tsc_cmd = {
.id = REPLY_WOWLAN_TSC_RSC_PARAMS,
.flags = CMD_SYNC,
.data[0] = key_data.rsc_tsc,
.dataflags[0] = IWL_HCMD_DFL_NOCOPY,
.len[0] = sizeof(*key_data.rsc_tsc),
};
ret = iwl_trans_send_cmd(trans(priv), &rsc_tsc_cmd);
if (ret)
goto error;
}
if (key_data.use_tkip) {
ret = iwl_trans_send_cmd_pdu(trans(priv),
REPLY_WOWLAN_TKIP_PARAMS,
CMD_SYNC, sizeof(tkip_cmd),
&tkip_cmd);
if (ret)
goto error;
}
if (priv->have_rekey_data) {
memset(&kek_kck_cmd, 0, sizeof(kek_kck_cmd));
memcpy(kek_kck_cmd.kck, priv->kck, NL80211_KCK_LEN);
kek_kck_cmd.kck_len = cpu_to_le16(NL80211_KCK_LEN);
memcpy(kek_kck_cmd.kek, priv->kek, NL80211_KEK_LEN);
kek_kck_cmd.kek_len = cpu_to_le16(NL80211_KEK_LEN);
kek_kck_cmd.replay_ctr = priv->replay_ctr;
ret = iwl_trans_send_cmd_pdu(trans(priv),
REPLY_WOWLAN_KEK_KCK_MATERIAL,
CMD_SYNC, sizeof(kek_kck_cmd),
&kek_kck_cmd);
if (ret)
goto error;
}
}
ret = iwl_trans_send_cmd_pdu(trans(priv), REPLY_WOWLAN_WAKEUP_FILTER,
CMD_SYNC, sizeof(wakeup_filter_cmd),
&wakeup_filter_cmd);
if (ret)
goto error;
ret = iwlagn_send_patterns(priv, wowlan);
if (ret)
goto error;
device_set_wakeup_enable(bus(priv)->dev, true);
iwl_write32(bus(priv), CSR_UCODE_DRV_GP1_SET,
CSR_UCODE_DRV_GP1_BIT_D3_CFG_COMPLETE);
goto out;
error:
priv->shrd->wowlan = false;
iwlagn_prepare_restart(priv);
ieee80211_restart_hw(priv->hw);
out:
mutex_unlock(&priv->shrd->mutex);
kfree(key_data.rsc_tsc);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
static int iwlagn_mac_resume(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
struct ieee80211_vif *vif;
unsigned long flags;
u32 base, status = 0xffffffff;
int ret = -EIO;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
iwl_write32(bus(priv), CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_BIT_D3_CFG_COMPLETE);
base = priv->device_pointers.error_event_table;
if (iwlagn_hw_valid_rtc_data_addr(base)) {
spin_lock_irqsave(&bus(priv)->reg_lock, flags);
ret = iwl_grab_nic_access_silent(bus(priv));
if (ret == 0) {
iwl_write32(bus(priv), HBUS_TARG_MEM_RADDR, base);
status = iwl_read32(bus(priv), HBUS_TARG_MEM_RDAT);
iwl_release_nic_access(bus(priv));
}
spin_unlock_irqrestore(&bus(priv)->reg_lock, flags);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (ret == 0) {
if (!priv->wowlan_sram)
priv->wowlan_sram =
kzalloc(priv->ucode_wowlan.data.len,
GFP_KERNEL);
if (priv->wowlan_sram)
_iwl_read_targ_mem_words(
bus(priv), 0x800000, priv->wowlan_sram,
priv->ucode_wowlan.data.len / 4);
}
#endif
}
vif = ctx->vif;
priv->shrd->wowlan = false;
device_set_wakeup_enable(bus(priv)->dev, false);
iwlagn_prepare_restart(priv);
memset((void *)&ctx->active, 0, sizeof(ctx->active));
iwl_connection_init_rx_config(priv, ctx);
iwlagn_set_rxon_chain(priv, ctx);
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
ieee80211_resume_disconnect(vif);
return 1;
}
static void iwlagn_mac_tx(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct iwl_priv *priv = hw->priv;
IWL_DEBUG_MACDUMP(priv, "enter\n");
IWL_DEBUG_TX(priv, "dev->xmit(%d bytes) at rate 0x%02x\n", skb->len,
ieee80211_get_tx_rate(hw, IEEE80211_SKB_CB(skb))->bitrate);
if (iwlagn_tx_skb(priv, skb))
dev_kfree_skb_any(skb);
IWL_DEBUG_MACDUMP(priv, "leave\n");
}
static void iwlagn_mac_update_tkip_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_key_conf *keyconf,
struct ieee80211_sta *sta,
u32 iv32, u16 *phase1key)
{
struct iwl_priv *priv = hw->priv;
iwl_update_tkip_key(priv, vif, keyconf, sta, iv32, phase1key);
}
static int iwlagn_mac_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct iwl_priv *priv = hw->priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
struct iwl_rxon_context *ctx = vif_priv->ctx;
int ret;
bool is_default_wep_key = false;
IWL_DEBUG_MAC80211(priv, "enter\n");
if (iwlagn_mod_params.sw_crypto) {
IWL_DEBUG_MAC80211(priv, "leave - hwcrypto disabled\n");
return -EOPNOTSUPP;
}
switch (key->cipher) {
case WLAN_CIPHER_SUITE_TKIP:
key->flags |= IEEE80211_KEY_FLAG_GENERATE_MMIC;
case WLAN_CIPHER_SUITE_CCMP:
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
break;
default:
break;
}
if (vif->type == NL80211_IFTYPE_ADHOC &&
!(key->flags & IEEE80211_KEY_FLAG_PAIRWISE)) {
key->hw_key_idx = WEP_INVALID_OFFSET;
return 0;
}
if (cmd == DISABLE_KEY && key->hw_key_idx == WEP_INVALID_OFFSET)
return 0;
mutex_lock(&priv->shrd->mutex);
iwl_scan_cancel_timeout(priv, 100);
BUILD_BUG_ON(WEP_INVALID_OFFSET == IWLAGN_HW_KEY_DEFAULT);
if ((key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
key->cipher == WLAN_CIPHER_SUITE_WEP104) && !sta) {
if (cmd == SET_KEY)
is_default_wep_key = !ctx->key_mapping_keys;
else
is_default_wep_key =
key->hw_key_idx == IWLAGN_HW_KEY_DEFAULT;
}
switch (cmd) {
case SET_KEY:
if (is_default_wep_key) {
ret = iwl_set_default_wep_key(priv, vif_priv->ctx, key);
break;
}
ret = iwl_set_dynamic_key(priv, vif_priv->ctx, key, sta);
if (ret) {
ret = 0;
key->hw_key_idx = WEP_INVALID_OFFSET;
}
IWL_DEBUG_MAC80211(priv, "enable hwcrypto key\n");
break;
case DISABLE_KEY:
if (is_default_wep_key)
ret = iwl_remove_default_wep_key(priv, ctx, key);
else
ret = iwl_remove_dynamic_key(priv, ctx, key, sta);
IWL_DEBUG_MAC80211(priv, "disable hwcrypto key\n");
break;
default:
ret = -EINVAL;
}
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
static int iwlagn_mac_ampdu_action(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
struct iwl_priv *priv = hw->priv;
int ret = -EINVAL;
struct iwl_station_priv *sta_priv = (void *) sta->drv_priv;
struct iwl_rxon_context *ctx = iwl_rxon_ctx_from_vif(vif);
IWL_DEBUG_HT(priv, "A-MPDU action on addr %pM tid %d\n",
sta->addr, tid);
if (!(priv->cfg->sku & EEPROM_SKU_CAP_11N_ENABLE))
return -EACCES;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
switch (action) {
case IEEE80211_AMPDU_RX_START:
IWL_DEBUG_HT(priv, "start Rx\n");
ret = iwl_sta_rx_agg_start(priv, sta, tid, *ssn);
break;
case IEEE80211_AMPDU_RX_STOP:
IWL_DEBUG_HT(priv, "stop Rx\n");
ret = iwl_sta_rx_agg_stop(priv, sta, tid);
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
ret = 0;
break;
case IEEE80211_AMPDU_TX_START:
IWL_DEBUG_HT(priv, "start Tx\n");
ret = iwlagn_tx_agg_start(priv, vif, sta, tid, ssn);
break;
case IEEE80211_AMPDU_TX_STOP:
IWL_DEBUG_HT(priv, "stop Tx\n");
ret = iwlagn_tx_agg_stop(priv, vif, sta, tid);
if ((ret == 0) && (priv->agg_tids_count > 0)) {
priv->agg_tids_count--;
IWL_DEBUG_HT(priv, "priv->agg_tids_count = %u\n",
priv->agg_tids_count);
}
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status))
ret = 0;
if (!priv->agg_tids_count && priv->cfg->ht_params &&
priv->cfg->ht_params->use_rts_for_aggregation) {
sta_priv->lq_sta.lq.general_params.flags &=
~LINK_QUAL_FLAGS_SET_STA_TLC_RTS_MSK;
iwl_send_lq_cmd(priv, iwl_rxon_ctx_from_vif(vif),
&sta_priv->lq_sta.lq, CMD_ASYNC, false);
}
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
buf_size = min_t(int, buf_size, LINK_QUAL_AGG_FRAME_LIMIT_DEF);
iwl_trans_tx_agg_setup(trans(priv), ctx->ctxid, iwl_sta_id(sta),
tid, buf_size);
if (sta_priv->max_agg_bufsize == 0)
sta_priv->max_agg_bufsize =
LINK_QUAL_AGG_FRAME_LIMIT_DEF;
sta_priv->max_agg_bufsize =
min(sta_priv->max_agg_bufsize, buf_size);
if (priv->cfg->ht_params &&
priv->cfg->ht_params->use_rts_for_aggregation) {
sta_priv->lq_sta.lq.general_params.flags |=
LINK_QUAL_FLAGS_SET_STA_TLC_RTS_MSK;
}
priv->agg_tids_count++;
IWL_DEBUG_HT(priv, "priv->agg_tids_count = %u\n",
priv->agg_tids_count);
sta_priv->lq_sta.lq.agg_params.agg_frame_cnt_limit =
sta_priv->max_agg_bufsize;
iwl_send_lq_cmd(priv, iwl_rxon_ctx_from_vif(vif),
&sta_priv->lq_sta.lq, CMD_ASYNC, false);
IWL_INFO(priv, "Tx aggregation enabled on ra = %pM tid = %d\n",
sta->addr, tid);
ret = 0;
break;
}
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
static int iwlagn_mac_sta_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct iwl_priv *priv = hw->priv;
struct iwl_station_priv *sta_priv = (void *)sta->drv_priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
bool is_ap = vif->type == NL80211_IFTYPE_STATION;
int ret = 0;
u8 sta_id;
IWL_DEBUG_MAC80211(priv, "received request to add station %pM\n",
sta->addr);
mutex_lock(&priv->shrd->mutex);
IWL_DEBUG_INFO(priv, "proceeding to add station %pM\n",
sta->addr);
sta_priv->sta_id = IWL_INVALID_STATION;
atomic_set(&sta_priv->pending_frames, 0);
if (vif->type == NL80211_IFTYPE_AP)
sta_priv->client = true;
ret = iwl_add_station_common(priv, vif_priv->ctx, sta->addr,
is_ap, sta, &sta_id);
if (ret) {
IWL_ERR(priv, "Unable to add station %pM (%d)\n",
sta->addr, ret);
goto out;
}
sta_priv->sta_id = sta_id;
IWL_DEBUG_INFO(priv, "Initializing rate scaling for station %pM\n",
sta->addr);
iwl_rs_rate_init(priv, sta, sta_id);
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
static void iwlagn_mac_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_channel_switch *ch_switch)
{
struct iwl_priv *priv = hw->priv;
const struct iwl_channel_info *ch_info;
struct ieee80211_conf *conf = &hw->conf;
struct ieee80211_channel *channel = ch_switch->channel;
struct iwl_ht_config *ht_conf = &priv->current_ht_config;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
u16 ch;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (iwl_is_rfkill(priv->shrd))
goto out;
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status) ||
test_bit(STATUS_SCANNING, &priv->shrd->status) ||
test_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->shrd->status))
goto out;
if (!iwl_is_associated_ctx(ctx))
goto out;
if (!priv->cfg->lib->set_channel_switch)
goto out;
ch = channel->hw_value;
if (le16_to_cpu(ctx->active.channel) == ch)
goto out;
ch_info = iwl_get_channel_info(priv, channel->band, ch);
if (!is_channel_valid(ch_info)) {
IWL_DEBUG_MAC80211(priv, "invalid channel\n");
goto out;
}
spin_lock_irq(&priv->shrd->lock);
priv->current_ht_config.smps = conf->smps_mode;
ctx->ht.enabled = conf_is_ht(conf);
if (ctx->ht.enabled)
iwlagn_config_ht40(conf, ctx);
else
ctx->ht.is_40mhz = false;
if ((le16_to_cpu(ctx->staging.channel) != ch))
ctx->staging.flags = 0;
iwl_set_rxon_channel(priv, channel, ctx);
iwl_set_rxon_ht(priv, ht_conf);
iwl_set_flags_for_band(priv, ctx, channel->band, ctx->vif);
spin_unlock_irq(&priv->shrd->lock);
iwl_set_rate(priv);
set_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->shrd->status);
priv->switch_channel = cpu_to_le16(ch);
if (priv->cfg->lib->set_channel_switch(priv, ch_switch)) {
clear_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->shrd->status);
priv->switch_channel = 0;
ieee80211_chswitch_done(ctx->vif, false);
}
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
static void iwlagn_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags,
u64 multicast)
{
struct iwl_priv *priv = hw->priv;
__le32 filter_or = 0, filter_nand = 0;
struct iwl_rxon_context *ctx;
#define CHK(test, flag) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
IWL_DEBUG_MAC80211(priv, "Enter: changed: 0x%x, total: 0x%x\n",
changed_flags, *total_flags);
CHK(FIF_OTHER_BSS | FIF_PROMISC_IN_BSS, RXON_FILTER_PROMISC_MSK);
CHK(FIF_CONTROL, RXON_FILTER_CTL2HOST_MSK | RXON_FILTER_PROMISC_MSK);
CHK(FIF_BCN_PRBRESP_PROMISC, RXON_FILTER_BCON_AWARE_MSK);
#undef CHK
mutex_lock(&priv->shrd->mutex);
for_each_context(priv, ctx) {
ctx->staging.filter_flags &= ~filter_nand;
ctx->staging.filter_flags |= filter_or;
}
mutex_unlock(&priv->shrd->mutex);
*total_flags &= FIF_OTHER_BSS | FIF_ALLMULTI | FIF_PROMISC_IN_BSS |
FIF_BCN_PRBRESP_PROMISC | FIF_CONTROL;
}
static void iwlagn_mac_flush(struct ieee80211_hw *hw, bool drop)
{
struct iwl_priv *priv = hw->priv;
mutex_lock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "enter\n");
if (test_bit(STATUS_EXIT_PENDING, &priv->shrd->status)) {
IWL_DEBUG_TX(priv, "Aborting flush due to device shutdown\n");
goto done;
}
if (iwl_is_rfkill(priv->shrd)) {
IWL_DEBUG_TX(priv, "Aborting flush due to RF Kill\n");
goto done;
}
if (drop) {
IWL_DEBUG_MAC80211(priv, "send flush command\n");
if (iwlagn_txfifo_flush(priv, IWL_DROP_ALL)) {
IWL_ERR(priv, "flush request fail\n");
goto done;
}
}
IWL_DEBUG_MAC80211(priv, "wait transmit/flush all frames\n");
iwl_trans_wait_tx_queue_empty(trans(priv));
done:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
void iwlagn_disable_roc(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_PAN];
lockdep_assert_held(&priv->shrd->mutex);
if (!priv->hw_roc_setup)
return;
ctx->staging.dev_type = RXON_DEV_TYPE_P2P;
ctx->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
priv->hw_roc_channel = NULL;
memset(ctx->staging.node_addr, 0, ETH_ALEN);
iwlagn_commit_rxon(priv, ctx);
ctx->is_active = false;
priv->hw_roc_setup = false;
}
static void iwlagn_disable_roc_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
hw_roc_disable_work.work);
mutex_lock(&priv->shrd->mutex);
iwlagn_disable_roc(priv);
mutex_unlock(&priv->shrd->mutex);
}
static int iwlagn_mac_remain_on_channel(struct ieee80211_hw *hw,
struct ieee80211_channel *channel,
enum nl80211_channel_type channel_type,
int duration)
{
struct iwl_priv *priv = hw->priv;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_PAN];
int err = 0;
if (!(priv->shrd->valid_contexts & BIT(IWL_RXON_CTX_PAN)))
return -EOPNOTSUPP;
if (!(ctx->interface_modes & BIT(NL80211_IFTYPE_P2P_CLIENT)))
return -EOPNOTSUPP;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (test_bit(STATUS_SCAN_HW, &priv->shrd->status)) {
err = -EBUSY;
goto out;
}
priv->hw_roc_channel = channel;
priv->hw_roc_chantype = channel_type;
priv->hw_roc_duration = duration;
priv->hw_roc_start_notified = false;
cancel_delayed_work(&priv->hw_roc_disable_work);
if (!ctx->is_active) {
ctx->is_active = true;
ctx->staging.dev_type = RXON_DEV_TYPE_P2P;
memcpy(ctx->staging.node_addr,
priv->contexts[IWL_RXON_CTX_BSS].staging.node_addr,
ETH_ALEN);
memcpy(ctx->staging.bssid_addr,
priv->contexts[IWL_RXON_CTX_BSS].staging.node_addr,
ETH_ALEN);
err = iwlagn_commit_rxon(priv, ctx);
if (err)
goto out;
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK |
RXON_FILTER_PROMISC_MSK |
RXON_FILTER_CTL2HOST_MSK;
err = iwlagn_commit_rxon(priv, ctx);
if (err) {
iwlagn_disable_roc(priv);
goto out;
}
priv->hw_roc_setup = true;
}
err = iwl_scan_initiate(priv, ctx->vif, IWL_SCAN_ROC, channel->band);
if (err)
iwlagn_disable_roc(priv);
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return err;
}
static int iwlagn_mac_cancel_remain_on_channel(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
if (!(priv->shrd->valid_contexts & BIT(IWL_RXON_CTX_PAN)))
return -EOPNOTSUPP;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
iwl_scan_cancel_timeout(priv, priv->hw_roc_duration);
iwlagn_disable_roc(priv);
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return 0;
}
static int iwlagn_mac_tx_sync(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
const u8 *bssid,
enum ieee80211_tx_sync_type type)
{
struct iwl_priv *priv = hw->priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
struct iwl_rxon_context *ctx = vif_priv->ctx;
int ret;
u8 sta_id;
if (ctx->ctxid != IWL_RXON_CTX_PAN)
return 0;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (iwl_is_associated_ctx(ctx)) {
ret = 0;
goto out;
}
if (ctx->preauth_bssid || test_bit(STATUS_SCAN_HW, &priv->shrd->status)) {
ret = -EBUSY;
goto out;
}
ret = iwl_add_station_common(priv, ctx, bssid, true, NULL, &sta_id);
if (ret)
goto out;
if (WARN_ON(sta_id != ctx->ap_sta_id)) {
ret = -EIO;
goto out_remove_sta;
}
memcpy(ctx->bssid, bssid, ETH_ALEN);
ctx->preauth_bssid = true;
ret = iwlagn_commit_rxon(priv, ctx);
if (ret == 0)
goto out;
out_remove_sta:
iwl_remove_station(priv, sta_id, bssid);
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
static void iwlagn_mac_finish_tx_sync(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
const u8 *bssid,
enum ieee80211_tx_sync_type type)
{
struct iwl_priv *priv = hw->priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
struct iwl_rxon_context *ctx = vif_priv->ctx;
if (ctx->ctxid != IWL_RXON_CTX_PAN)
return;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (iwl_is_associated_ctx(ctx))
goto out;
iwl_remove_station(priv, ctx->ap_sta_id, bssid);
ctx->preauth_bssid = false;
out:
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
static void iwl_setup_deferred_work(struct iwl_priv *priv)
{
priv->shrd->workqueue = create_singlethread_workqueue(DRV_NAME);
init_waitqueue_head(&priv->shrd->wait_command_queue);
INIT_WORK(&priv->restart, iwl_bg_restart);
INIT_WORK(&priv->beacon_update, iwl_bg_beacon_update);
INIT_WORK(&priv->run_time_calib_work, iwl_bg_run_time_calib_work);
INIT_WORK(&priv->tx_flush, iwl_bg_tx_flush);
INIT_WORK(&priv->bt_full_concurrency, iwl_bg_bt_full_concurrency);
INIT_WORK(&priv->bt_runtime_config, iwl_bg_bt_runtime_config);
INIT_DELAYED_WORK(&priv->hw_roc_disable_work,
iwlagn_disable_roc_work);
iwl_setup_scan_deferred_work(priv);
if (priv->cfg->lib->bt_setup_deferred_work)
priv->cfg->lib->bt_setup_deferred_work(priv);
init_timer(&priv->statistics_periodic);
priv->statistics_periodic.data = (unsigned long)priv;
priv->statistics_periodic.function = iwl_bg_statistics_periodic;
init_timer(&priv->ucode_trace);
priv->ucode_trace.data = (unsigned long)priv;
priv->ucode_trace.function = iwl_bg_ucode_trace;
init_timer(&priv->watchdog);
priv->watchdog.data = (unsigned long)priv;
priv->watchdog.function = iwl_bg_watchdog;
}
static void iwl_cancel_deferred_work(struct iwl_priv *priv)
{
if (priv->cfg->lib->cancel_deferred_work)
priv->cfg->lib->cancel_deferred_work(priv);
cancel_work_sync(&priv->run_time_calib_work);
cancel_work_sync(&priv->beacon_update);
iwl_cancel_scan_deferred_work(priv);
cancel_work_sync(&priv->bt_full_concurrency);
cancel_work_sync(&priv->bt_runtime_config);
cancel_delayed_work_sync(&priv->hw_roc_disable_work);
del_timer_sync(&priv->statistics_periodic);
del_timer_sync(&priv->ucode_trace);
}
static void iwl_init_hw_rates(struct iwl_priv *priv,
struct ieee80211_rate *rates)
{
int i;
for (i = 0; i < IWL_RATE_COUNT_LEGACY; i++) {
rates[i].bitrate = iwl_rates[i].ieee * 5;
rates[i].hw_value = i;
rates[i].hw_value_short = i;
rates[i].flags = 0;
if ((i >= IWL_FIRST_CCK_RATE) && (i <= IWL_LAST_CCK_RATE)) {
rates[i].flags |=
(iwl_rates[i].plcp == IWL_RATE_1M_PLCP) ?
0 : IEEE80211_RATE_SHORT_PREAMBLE;
}
}
}
static int iwl_init_drv(struct iwl_priv *priv)
{
int ret;
spin_lock_init(&priv->shrd->sta_lock);
mutex_init(&priv->shrd->mutex);
priv->ieee_channels = NULL;
priv->ieee_rates = NULL;
priv->band = IEEE80211_BAND_2GHZ;
priv->iw_mode = NL80211_IFTYPE_STATION;
priv->current_ht_config.smps = IEEE80211_SMPS_STATIC;
priv->missed_beacon_threshold = IWL_MISSED_BEACON_THRESHOLD_DEF;
priv->agg_tids_count = 0;
priv->force_reset[IWL_RF_RESET].reset_duration =
IWL_DELAY_NEXT_FORCE_RF_RESET;
priv->force_reset[IWL_FW_RESET].reset_duration =
IWL_DELAY_NEXT_FORCE_FW_RELOAD;
priv->rx_statistics_jiffies = jiffies;
iwlagn_set_rxon_chain(priv, &priv->contexts[IWL_RXON_CTX_BSS]);
iwl_init_scan_params(priv);
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
priv->kill_ack_mask = IWLAGN_BT_KILL_ACK_MASK_DEFAULT;
priv->kill_cts_mask = IWLAGN_BT_KILL_CTS_MASK_DEFAULT;
priv->bt_valid = IWLAGN_BT_ALL_VALID_MSK;
priv->bt_on_thresh = BT_ON_THRESHOLD_DEF;
priv->bt_duration = BT_DURATION_LIMIT_DEF;
priv->dynamic_frag_thresh = BT_FRAG_THRESHOLD_DEF;
}
ret = iwl_init_channel_map(priv);
if (ret) {
IWL_ERR(priv, "initializing regulatory failed: %d\n", ret);
goto err;
}
ret = iwl_init_geos(priv);
if (ret) {
IWL_ERR(priv, "initializing geos failed: %d\n", ret);
goto err_free_channel_map;
}
iwl_init_hw_rates(priv, priv->ieee_rates);
return 0;
err_free_channel_map:
iwl_free_channel_map(priv);
err:
return ret;
}
static void iwl_uninit_drv(struct iwl_priv *priv)
{
iwl_calib_free_results(priv);
iwl_free_geos(priv);
iwl_free_channel_map(priv);
if (priv->tx_cmd_pool)
kmem_cache_destroy(priv->tx_cmd_pool);
kfree(priv->scan_cmd);
kfree(priv->beacon_cmd);
#ifdef CONFIG_IWLWIFI_DEBUGFS
kfree(priv->wowlan_sram);
#endif
}
static void iwlagn_mac_rssi_callback(struct ieee80211_hw *hw,
enum ieee80211_rssi_event rssi_event)
{
struct iwl_priv *priv = hw->priv;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->shrd->mutex);
if (priv->cfg->bt_params &&
priv->cfg->bt_params->advanced_bt_coexist) {
if (rssi_event == RSSI_EVENT_LOW)
priv->bt_enable_pspoll = true;
else if (rssi_event == RSSI_EVENT_HIGH)
priv->bt_enable_pspoll = false;
iwlagn_send_advance_bt_config(priv);
} else {
IWL_DEBUG_MAC80211(priv, "Advanced BT coex disabled,"
"ignoring RSSI callback\n");
}
mutex_unlock(&priv->shrd->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
static int iwlagn_mac_set_tim(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, bool set)
{
struct iwl_priv *priv = hw->priv;
queue_work(priv->shrd->workqueue, &priv->beacon_update);
return 0;
}
static u32 iwl_hw_detect(struct iwl_priv *priv)
{
return iwl_read32(bus(priv), CSR_HW_REV);
}
static int iwl_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.amsdu_size_8K)
hw_params(priv).rx_page_order =
get_order(IWL_RX_BUF_SIZE_8K);
else
hw_params(priv).rx_page_order =
get_order(IWL_RX_BUF_SIZE_4K);
if (iwlagn_mod_params.disable_11n)
priv->cfg->sku &= ~EEPROM_SKU_CAP_11N_ENABLE;
hw_params(priv).num_ampdu_queues =
priv->cfg->base_params->num_of_ampdu_queues;
hw_params(priv).shadow_reg_enable =
priv->cfg->base_params->shadow_reg_enable;
hw_params(priv).sku = priv->cfg->sku;
hw_params(priv).wd_timeout = priv->cfg->base_params->wd_timeout;
return priv->cfg->lib->set_hw_params(priv);
}
static struct ieee80211_hw *iwl_alloc_all(struct iwl_cfg *cfg)
{
struct iwl_priv *priv;
struct ieee80211_hw *hw;
hw = ieee80211_alloc_hw(sizeof(struct iwl_priv), &iwlagn_hw_ops);
if (hw == NULL) {
pr_err("%s: Can not allocate network device\n",
cfg->name);
goto out;
}
priv = hw->priv;
priv->hw = hw;
out:
return hw;
}
int iwl_probe(struct iwl_bus *bus, const struct iwl_trans_ops *trans_ops,
struct iwl_cfg *cfg)
{
int err = 0;
struct iwl_priv *priv;
struct ieee80211_hw *hw;
u16 num_mac;
u32 hw_rev;
hw = iwl_alloc_all(cfg);
if (!hw) {
err = -ENOMEM;
goto out;
}
priv = hw->priv;
priv->shrd = &priv->_shrd;
bus->shrd = priv->shrd;
priv->shrd->bus = bus;
priv->shrd->priv = priv;
priv->shrd->trans = trans_ops->alloc(priv->shrd);
if (priv->shrd->trans == NULL) {
err = -ENOMEM;
goto out_free_traffic_mem;
}
SET_IEEE80211_DEV(hw, bus(priv)->dev);
IWL_DEBUG_INFO(priv, "*** LOAD DRIVER ***\n");
priv->cfg = cfg;
priv->bt_ant_couple_ok =
(iwlagn_mod_params.ant_coupling >
IWL_BT_ANTENNA_COUPLING_THRESHOLD) ?
true : false;
priv->bt_ch_announce = iwlagn_mod_params.bt_ch_announce;
IWL_DEBUG_INFO(priv, "BT channel inhibition is %s\n",
(priv->bt_ch_announce) ? "On" : "Off");
if (iwl_alloc_traffic_mem(priv))
IWL_ERR(priv, "Not enough memory to generate traffic log\n");
spin_lock_init(&bus(priv)->reg_lock);
spin_lock_init(&priv->shrd->lock);
iwl_write32(bus(priv), CSR_RESET, CSR_RESET_REG_FLAG_NEVO_RESET);
hw_rev = iwl_hw_detect(priv);
IWL_INFO(priv, "Detected %s, REV=0x%X\n",
priv->cfg->name, hw_rev);
err = iwl_trans_request_irq(trans(priv));
if (err)
goto out_free_trans;
if (iwl_trans_prepare_card_hw(trans(priv))) {
err = -EIO;
IWL_WARN(priv, "Failed, HW not ready\n");
goto out_free_trans;
}
err = iwl_eeprom_init(priv, hw_rev);
if (err) {
IWL_ERR(priv, "Unable to init EEPROM\n");
goto out_free_trans;
}
err = iwl_eeprom_check_version(priv);
if (err)
goto out_free_eeprom;
err = iwl_eeprom_check_sku(priv);
if (err)
goto out_free_eeprom;
iwl_eeprom_get_mac(priv, priv->addresses[0].addr);
IWL_DEBUG_INFO(priv, "MAC address: %pM\n", priv->addresses[0].addr);
priv->hw->wiphy->addresses = priv->addresses;
priv->hw->wiphy->n_addresses = 1;
num_mac = iwl_eeprom_query16(priv, EEPROM_NUM_MAC_ADDRESS);
if (num_mac > 1) {
memcpy(priv->addresses[1].addr, priv->addresses[0].addr,
ETH_ALEN);
priv->addresses[1].addr[5]++;
priv->hw->wiphy->n_addresses++;
}
if (iwl_set_hw_params(priv)) {
err = -ENOENT;
IWL_ERR(priv, "failed to set hw parameters\n");
goto out_free_eeprom;
}
err = iwl_init_drv(priv);
if (err)
goto out_free_eeprom;
iwl_setup_deferred_work(priv);
iwl_setup_rx_handlers(priv);
iwl_testmode_init(priv);
iwl_enable_rfkill_int(priv);
if (iwl_read32(bus(priv),
CSR_GP_CNTRL) & CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW)
clear_bit(STATUS_RF_KILL_HW, &priv->shrd->status);
else
set_bit(STATUS_RF_KILL_HW, &priv->shrd->status);
wiphy_rfkill_set_hw_state(priv->hw->wiphy,
test_bit(STATUS_RF_KILL_HW, &priv->shrd->status));
iwl_power_initialize(priv);
iwl_tt_initialize(priv);
init_completion(&priv->firmware_loading_complete);
err = iwl_request_firmware(priv, true);
if (err)
goto out_destroy_workqueue;
return 0;
out_destroy_workqueue:
destroy_workqueue(priv->shrd->workqueue);
priv->shrd->workqueue = NULL;
iwl_uninit_drv(priv);
out_free_eeprom:
iwl_eeprom_free(priv);
out_free_trans:
iwl_trans_free(trans(priv));
out_free_traffic_mem:
iwl_free_traffic_mem(priv);
ieee80211_free_hw(priv->hw);
out:
return err;
}
void __devexit iwl_remove(struct iwl_priv * priv)
{
wait_for_completion(&priv->firmware_loading_complete);
IWL_DEBUG_INFO(priv, "*** UNLOAD DRIVER ***\n");
iwl_dbgfs_unregister(priv);
set_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
iwl_testmode_cleanup(priv);
iwl_leds_exit(priv);
if (priv->mac80211_registered) {
ieee80211_unregister_hw(priv->hw);
priv->mac80211_registered = 0;
}
iwl_tt_exit(priv);
iwl_trans_stop_device(trans(priv));
iwl_dealloc_ucode(priv);
iwl_eeprom_free(priv);
flush_workqueue(priv->shrd->workqueue);
destroy_workqueue(priv->shrd->workqueue);
priv->shrd->workqueue = NULL;
iwl_free_traffic_mem(priv);
iwl_trans_free(trans(priv));
iwl_uninit_drv(priv);
dev_kfree_skb(priv->beacon_skb);
ieee80211_free_hw(priv->hw);
}
static int __init iwl_init(void)
{
int ret;
pr_info(DRV_DESCRIPTION ", " DRV_VERSION "\n");
pr_info(DRV_COPYRIGHT "\n");
ret = iwlagn_rate_control_register();
if (ret) {
pr_err("Unable to register rate control algorithm: %d\n", ret);
return ret;
}
ret = iwl_pci_register_driver();
if (ret)
goto error_register;
return ret;
error_register:
iwlagn_rate_control_unregister();
return ret;
}
static void __exit iwl_exit(void)
{
iwl_pci_unregister_driver();
iwlagn_rate_control_unregister();
}
