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
base = priv->shrd->device_pointers.error_event_table;
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
const char *name_pre = cfg(priv)->fw_name_pre;
char tag[8];
if (first) {
#ifdef CONFIG_IWLWIFI_DEBUG_EXPERIMENTAL_UCODE
priv->fw_index = UCODE_EXPERIMENTAL_INDEX;
strcpy(tag, UCODE_EXPERIMENTAL_TAG);
} else if (priv->fw_index == UCODE_EXPERIMENTAL_INDEX) {
#endif
priv->fw_index = cfg(priv)->ucode_api_max;
sprintf(tag, "%d", priv->fw_index);
} else {
priv->fw_index--;
sprintf(tag, "%d", priv->fw_index);
}
if (priv->fw_index < cfg(priv)->ucode_api_min) {
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
const unsigned int api_max = cfg(priv)->ucode_api_max;
unsigned int api_ok = cfg(priv)->ucode_api_ok;
const unsigned int api_min = cfg(priv)->ucode_api_min;
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
if (iwl_alloc_fw_desc(bus(priv), &trans(priv)->ucode_rt.code,
pieces.inst, pieces.inst_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(bus(priv), &trans(priv)->ucode_rt.data,
pieces.data, pieces.data_size))
goto err_pci_alloc;
if (pieces.init_size && pieces.init_data_size) {
if (iwl_alloc_fw_desc(bus(priv), &trans(priv)->ucode_init.code,
pieces.init, pieces.init_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(bus(priv), &trans(priv)->ucode_init.data,
pieces.init_data, pieces.init_data_size))
goto err_pci_alloc;
}
if (pieces.wowlan_inst_size && pieces.wowlan_data_size) {
if (iwl_alloc_fw_desc(bus(priv),
&trans(priv)->ucode_wowlan.code,
pieces.wowlan_inst,
pieces.wowlan_inst_size))
goto err_pci_alloc;
if (iwl_alloc_fw_desc(bus(priv),
&trans(priv)->ucode_wowlan.data,
pieces.wowlan_data,
pieces.wowlan_data_size))
goto err_pci_alloc;
}
priv->init_evtlog_ptr = pieces.init_evtlog_ptr;
if (pieces.init_evtlog_size)
priv->init_evtlog_size = (pieces.init_evtlog_size - 16)/12;
else
priv->init_evtlog_size =
cfg(priv)->base_params->max_event_log_size;
priv->init_errlog_ptr = pieces.init_errlog_ptr;
priv->inst_evtlog_ptr = pieces.inst_evtlog_ptr;
if (pieces.inst_evtlog_size)
priv->inst_evtlog_size = (pieces.inst_evtlog_size - 16)/12;
else
priv->inst_evtlog_size =
cfg(priv)->base_params->max_event_log_size;
priv->inst_errlog_ptr = pieces.inst_errlog_ptr;
#ifndef CONFIG_IWLWIFI_P2P
ucode_capa.flags &= ~IWL_UCODE_TLV_FLAGS_PAN;
#endif
priv->new_scan_threshold_behaviour =
!!(ucode_capa.flags & IWL_UCODE_TLV_FLAGS_NEWSCAN);
if (!(cfg(priv)->sku & EEPROM_SKU_CAP_IPAN_ENABLE))
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
iwl_dealloc_ucode(trans(priv));
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
if (cfg(priv)->base_params->support_ct_kill_exit) {
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
if (cfg(priv)->bt_params &&
cfg(priv)->bt_params->advanced_bt_coexist) {
if (cfg(priv)->bt_params->bt_sco_disable)
priv->bt_enable_pspoll = false;
else
priv->bt_enable_pspoll = true;
priv->bt_valid = IWLAGN_BT_ALL_VALID_MSK;
priv->kill_ack_mask = IWLAGN_BT_KILL_ACK_MASK_DEFAULT;
priv->kill_cts_mask = IWLAGN_BT_KILL_CTS_MASK_DEFAULT;
iwlagn_send_advance_bt_config(priv);
priv->bt_valid = IWLAGN_BT_VALID_ENABLE_FLAGS;
priv->cur_rssi_ctx = NULL;
iwl_send_prio_tbl(trans(priv));
ret = iwl_send_bt_env(trans(priv), IWL_BT_COEX_ENV_OPEN,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
ret = iwl_send_bt_env(trans(priv), IWL_BT_COEX_ENV_CLOSE,
BT_COEX_PRIO_TBL_EVT_INIT_CALIB2);
if (ret)
return ret;
} else {
iwl_send_bt_config(priv);
}
iwlagn_send_calib_cfg_rt(priv, IWL_CALIB_CFG_DC_IDX);
ieee80211_wake_queues(priv->hw);
priv->active_rate = IWL_RATES_MASK;
iwlagn_send_tx_ant_config(priv, cfg(priv)->valid_tx_ant);
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
void __iwl_down(struct iwl_priv *priv)
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
if (cfg(priv)->bt_params)
priv->bt_traffic_load =
cfg(priv)->bt_params->bt_init_traffic_load;
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
void iwl_down(struct iwl_priv *priv)
{
mutex_lock(&priv->shrd->mutex);
__iwl_down(priv);
mutex_unlock(&priv->shrd->mutex);
iwl_cancel_deferred_work(priv);
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
void iwlagn_prepare_restart(struct iwl_priv *priv)
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
if (cfg(priv)->lib->bt_setup_deferred_work)
cfg(priv)->lib->bt_setup_deferred_work(priv);
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
if (cfg(priv)->lib->cancel_deferred_work)
cfg(priv)->lib->cancel_deferred_work(priv);
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
INIT_LIST_HEAD(&trans(priv)->calib_results);
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
if (cfg(priv)->bt_params &&
cfg(priv)->bt_params->advanced_bt_coexist) {
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
iwl_free_geos(priv);
iwl_free_channel_map(priv);
if (priv->tx_cmd_pool)
kmem_cache_destroy(priv->tx_cmd_pool);
kfree(priv->scan_cmd);
kfree(priv->beacon_cmd);
kfree(rcu_dereference_raw(priv->noa_data));
#ifdef CONFIG_IWLWIFI_DEBUGFS
kfree(priv->wowlan_sram);
#endif
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
if (iwlagn_mod_params.disable_11n & IWL_DISABLE_HT_ALL)
cfg(priv)->sku &= ~EEPROM_SKU_CAP_11N_ENABLE;
hw_params(priv).num_ampdu_queues =
cfg(priv)->base_params->num_of_ampdu_queues;
hw_params(priv).shadow_reg_enable =
cfg(priv)->base_params->shadow_reg_enable;
hw_params(priv).sku = cfg(priv)->sku;
hw_params(priv).wd_timeout = cfg(priv)->base_params->wd_timeout;
return cfg(priv)->lib->set_hw_params(priv);
}
static void iwl_debug_config(struct iwl_priv *priv)
{
dev_printk(KERN_INFO, bus(priv)->dev, "CONFIG_IWLWIFI_DEBUG "
#ifdef CONFIG_IWLWIFI_DEBUG
"enabled\n");
#else
"disabled\n");
void __devexit iwl_remove(struct iwl_priv * priv)
{
wait_for_completion(&priv->firmware_loading_complete);
IWL_DEBUG_INFO(priv, "*** UNLOAD DRIVER ***\n");
iwl_dbgfs_unregister(priv);
set_bit(STATUS_EXIT_PENDING, &priv->shrd->status);
iwl_testmode_cleanup(priv);
iwlagn_mac_unregister(priv);
iwl_tt_exit(priv);
iwl_trans_stop_device(trans(priv));
iwl_dealloc_ucode(trans(priv));
iwl_eeprom_free(priv->shrd);
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
