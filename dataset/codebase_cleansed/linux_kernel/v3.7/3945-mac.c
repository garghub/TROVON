__le32
il3945_get_antenna_flags(const struct il_priv *il)
{
struct il3945_eeprom *eeprom = (struct il3945_eeprom *)il->eeprom;
switch (il3945_mod_params.antenna) {
case IL_ANTENNA_DIVERSITY:
return 0;
case IL_ANTENNA_MAIN:
if (eeprom->antenna_switch_type)
return RXON_FLG_DIS_DIV_MSK | RXON_FLG_ANT_B_MSK;
return RXON_FLG_DIS_DIV_MSK | RXON_FLG_ANT_A_MSK;
case IL_ANTENNA_AUX:
if (eeprom->antenna_switch_type)
return RXON_FLG_DIS_DIV_MSK | RXON_FLG_ANT_A_MSK;
return RXON_FLG_DIS_DIV_MSK | RXON_FLG_ANT_B_MSK;
}
IL_ERR("Bad antenna selector value (0x%x)\n",
il3945_mod_params.antenna);
return 0;
}
static int
il3945_set_ccmp_dynamic_key_info(struct il_priv *il,
struct ieee80211_key_conf *keyconf, u8 sta_id)
{
unsigned long flags;
__le16 key_flags = 0;
int ret;
key_flags |= (STA_KEY_FLG_CCMP | STA_KEY_FLG_MAP_KEY_MSK);
key_flags |= cpu_to_le16(keyconf->keyidx << STA_KEY_FLG_KEYID_POS);
if (sta_id == il->hw_params.bcast_id)
key_flags |= STA_KEY_MULTICAST_MSK;
keyconf->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
keyconf->hw_key_idx = keyconf->keyidx;
key_flags &= ~STA_KEY_FLG_INVALID;
spin_lock_irqsave(&il->sta_lock, flags);
il->stations[sta_id].keyinfo.cipher = keyconf->cipher;
il->stations[sta_id].keyinfo.keylen = keyconf->keylen;
memcpy(il->stations[sta_id].keyinfo.key, keyconf->key, keyconf->keylen);
memcpy(il->stations[sta_id].sta.key.key, keyconf->key, keyconf->keylen);
if ((il->stations[sta_id].sta.key.
key_flags & STA_KEY_FLG_ENCRYPT_MSK) == STA_KEY_FLG_NO_ENC)
il->stations[sta_id].sta.key.key_offset =
il_get_free_ucode_key_idx(il);
WARN(il->stations[sta_id].sta.key.key_offset == WEP_INVALID_OFFSET,
"no space for a new key");
il->stations[sta_id].sta.key.key_flags = key_flags;
il->stations[sta_id].sta.sta.modify_mask = STA_MODIFY_KEY_MASK;
il->stations[sta_id].sta.mode = STA_CONTROL_MODIFY_MSK;
D_INFO("hwcrypto: modify ucode station key info\n");
ret = il_send_add_sta(il, &il->stations[sta_id].sta, CMD_ASYNC);
spin_unlock_irqrestore(&il->sta_lock, flags);
return ret;
}
static int
il3945_set_tkip_dynamic_key_info(struct il_priv *il,
struct ieee80211_key_conf *keyconf, u8 sta_id)
{
return -EOPNOTSUPP;
}
static int
il3945_set_wep_dynamic_key_info(struct il_priv *il,
struct ieee80211_key_conf *keyconf, u8 sta_id)
{
return -EOPNOTSUPP;
}
static int
il3945_clear_sta_key_info(struct il_priv *il, u8 sta_id)
{
unsigned long flags;
struct il_addsta_cmd sta_cmd;
spin_lock_irqsave(&il->sta_lock, flags);
memset(&il->stations[sta_id].keyinfo, 0, sizeof(struct il_hw_key));
memset(&il->stations[sta_id].sta.key, 0, sizeof(struct il4965_keyinfo));
il->stations[sta_id].sta.key.key_flags = STA_KEY_FLG_NO_ENC;
il->stations[sta_id].sta.sta.modify_mask = STA_MODIFY_KEY_MASK;
il->stations[sta_id].sta.mode = STA_CONTROL_MODIFY_MSK;
memcpy(&sta_cmd, &il->stations[sta_id].sta,
sizeof(struct il_addsta_cmd));
spin_unlock_irqrestore(&il->sta_lock, flags);
D_INFO("hwcrypto: clear ucode station key info\n");
return il_send_add_sta(il, &sta_cmd, CMD_SYNC);
}
static int
il3945_set_dynamic_key(struct il_priv *il, struct ieee80211_key_conf *keyconf,
u8 sta_id)
{
int ret = 0;
keyconf->hw_key_idx = HW_KEY_DYNAMIC;
switch (keyconf->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
ret = il3945_set_ccmp_dynamic_key_info(il, keyconf, sta_id);
break;
case WLAN_CIPHER_SUITE_TKIP:
ret = il3945_set_tkip_dynamic_key_info(il, keyconf, sta_id);
break;
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
ret = il3945_set_wep_dynamic_key_info(il, keyconf, sta_id);
break;
default:
IL_ERR("Unknown alg: %s alg=%x\n", __func__, keyconf->cipher);
ret = -EINVAL;
}
D_WEP("Set dynamic key: alg=%x len=%d idx=%d sta=%d ret=%d\n",
keyconf->cipher, keyconf->keylen, keyconf->keyidx, sta_id, ret);
return ret;
}
static int
il3945_remove_static_key(struct il_priv *il)
{
int ret = -EOPNOTSUPP;
return ret;
}
static int
il3945_set_static_key(struct il_priv *il, struct ieee80211_key_conf *key)
{
if (key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
key->cipher == WLAN_CIPHER_SUITE_WEP104)
return -EOPNOTSUPP;
IL_ERR("Static key invalid: cipher %x\n", key->cipher);
return -EINVAL;
}
static void
il3945_clear_free_frames(struct il_priv *il)
{
struct list_head *element;
D_INFO("%d frames on pre-allocated heap on clear.\n", il->frames_count);
while (!list_empty(&il->free_frames)) {
element = il->free_frames.next;
list_del(element);
kfree(list_entry(element, struct il3945_frame, list));
il->frames_count--;
}
if (il->frames_count) {
IL_WARN("%d frames still in use. Did we lose one?\n",
il->frames_count);
il->frames_count = 0;
}
}
static struct il3945_frame *
il3945_get_free_frame(struct il_priv *il)
{
struct il3945_frame *frame;
struct list_head *element;
if (list_empty(&il->free_frames)) {
frame = kzalloc(sizeof(*frame), GFP_KERNEL);
if (!frame) {
IL_ERR("Could not allocate frame!\n");
return NULL;
}
il->frames_count++;
return frame;
}
element = il->free_frames.next;
list_del(element);
return list_entry(element, struct il3945_frame, list);
}
static void
il3945_free_frame(struct il_priv *il, struct il3945_frame *frame)
{
memset(frame, 0, sizeof(*frame));
list_add(&frame->list, &il->free_frames);
}
unsigned int
il3945_fill_beacon_frame(struct il_priv *il, struct ieee80211_hdr *hdr,
int left)
{
if (!il_is_associated(il) || !il->beacon_skb)
return 0;
if (il->beacon_skb->len > left)
return 0;
memcpy(hdr, il->beacon_skb->data, il->beacon_skb->len);
return il->beacon_skb->len;
}
static int
il3945_send_beacon_cmd(struct il_priv *il)
{
struct il3945_frame *frame;
unsigned int frame_size;
int rc;
u8 rate;
frame = il3945_get_free_frame(il);
if (!frame) {
IL_ERR("Could not obtain free frame buffer for beacon "
"command.\n");
return -ENOMEM;
}
rate = il_get_lowest_plcp(il);
frame_size = il3945_hw_get_beacon_cmd(il, frame, rate);
rc = il_send_cmd_pdu(il, C_TX_BEACON, frame_size, &frame->u.cmd[0]);
il3945_free_frame(il, frame);
return rc;
}
static void
il3945_unset_hw_params(struct il_priv *il)
{
if (il->_3945.shared_virt)
dma_free_coherent(&il->pci_dev->dev,
sizeof(struct il3945_shared),
il->_3945.shared_virt, il->_3945.shared_phys);
}
static void
il3945_build_tx_cmd_hwcrypto(struct il_priv *il, struct ieee80211_tx_info *info,
struct il_device_cmd *cmd,
struct sk_buff *skb_frag, int sta_id)
{
struct il3945_tx_cmd *tx_cmd = (struct il3945_tx_cmd *)cmd->cmd.payload;
struct il_hw_key *keyinfo = &il->stations[sta_id].keyinfo;
tx_cmd->sec_ctl = 0;
switch (keyinfo->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
tx_cmd->sec_ctl = TX_CMD_SEC_CCM;
memcpy(tx_cmd->key, keyinfo->key, keyinfo->keylen);
D_TX("tx_cmd with AES hwcrypto\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
break;
case WLAN_CIPHER_SUITE_WEP104:
tx_cmd->sec_ctl |= TX_CMD_SEC_KEY128;
case WLAN_CIPHER_SUITE_WEP40:
tx_cmd->sec_ctl |=
TX_CMD_SEC_WEP | (info->control.hw_key->
hw_key_idx & TX_CMD_SEC_MSK) <<
TX_CMD_SEC_SHIFT;
memcpy(&tx_cmd->key[3], keyinfo->key, keyinfo->keylen);
D_TX("Configuring packet for WEP encryption " "with key %d\n",
info->control.hw_key->hw_key_idx);
break;
default:
IL_ERR("Unknown encode cipher %x\n", keyinfo->cipher);
break;
}
}
static void
il3945_build_tx_cmd_basic(struct il_priv *il, struct il_device_cmd *cmd,
struct ieee80211_tx_info *info,
struct ieee80211_hdr *hdr, u8 std_id)
{
struct il3945_tx_cmd *tx_cmd = (struct il3945_tx_cmd *)cmd->cmd.payload;
__le32 tx_flags = tx_cmd->tx_flags;
__le16 fc = hdr->frame_control;
tx_cmd->stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
if (!(info->flags & IEEE80211_TX_CTL_NO_ACK)) {
tx_flags |= TX_CMD_FLG_ACK_MSK;
if (ieee80211_is_mgmt(fc))
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
if (ieee80211_is_probe_resp(fc) &&
!(le16_to_cpu(hdr->seq_ctrl) & 0xf))
tx_flags |= TX_CMD_FLG_TSF_MSK;
} else {
tx_flags &= (~TX_CMD_FLG_ACK_MSK);
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
}
tx_cmd->sta_id = std_id;
if (ieee80211_has_morefrags(fc))
tx_flags |= TX_CMD_FLG_MORE_FRAG_MSK;
if (ieee80211_is_data_qos(fc)) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
tx_cmd->tid_tspec = qc[0] & 0xf;
tx_flags &= ~TX_CMD_FLG_SEQ_CTL_MSK;
} else {
tx_flags |= TX_CMD_FLG_SEQ_CTL_MSK;
}
il_tx_cmd_protection(il, info, fc, &tx_flags);
tx_flags &= ~(TX_CMD_FLG_ANT_SEL_MSK);
if (ieee80211_is_mgmt(fc)) {
if (ieee80211_is_assoc_req(fc) || ieee80211_is_reassoc_req(fc))
tx_cmd->timeout.pm_frame_timeout = cpu_to_le16(3);
else
tx_cmd->timeout.pm_frame_timeout = cpu_to_le16(2);
} else {
tx_cmd->timeout.pm_frame_timeout = 0;
}
tx_cmd->driver_txop = 0;
tx_cmd->tx_flags = tx_flags;
tx_cmd->next_frame_len = 0;
}
static int
il3945_tx_skb(struct il_priv *il,
struct ieee80211_sta *sta,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct il3945_tx_cmd *tx_cmd;
struct il_tx_queue *txq = NULL;
struct il_queue *q = NULL;
struct il_device_cmd *out_cmd;
struct il_cmd_meta *out_meta;
dma_addr_t phys_addr;
dma_addr_t txcmd_phys;
int txq_id = skb_get_queue_mapping(skb);
u16 len, idx, hdr_len;
u8 id;
u8 unicast;
u8 sta_id;
u8 tid = 0;
__le16 fc;
u8 wait_write_ptr = 0;
unsigned long flags;
spin_lock_irqsave(&il->lock, flags);
if (il_is_rfkill(il)) {
D_DROP("Dropping - RF KILL\n");
goto drop_unlock;
}
if ((ieee80211_get_tx_rate(il->hw, info)->hw_value & 0xFF) ==
IL_INVALID_RATE) {
IL_ERR("ERROR: No TX rate available.\n");
goto drop_unlock;
}
unicast = !is_multicast_ether_addr(hdr->addr1);
id = 0;
fc = hdr->frame_control;
#ifdef CONFIG_IWLEGACY_DEBUG
if (ieee80211_is_auth(fc))
D_TX("Sending AUTH frame\n");
else if (ieee80211_is_assoc_req(fc))
D_TX("Sending ASSOC frame\n");
else if (ieee80211_is_reassoc_req(fc))
D_TX("Sending REASSOC frame\n");
#endif
spin_unlock_irqrestore(&il->lock, flags);
hdr_len = ieee80211_hdrlen(fc);
sta_id = il_sta_id_or_broadcast(il, sta);
if (sta_id == IL_INVALID_STATION) {
D_DROP("Dropping - INVALID STATION: %pM\n", hdr->addr1);
goto drop;
}
D_RATE("station Id %d\n", sta_id);
if (ieee80211_is_data_qos(fc)) {
u8 *qc = ieee80211_get_qos_ctl(hdr);
tid = qc[0] & IEEE80211_QOS_CTL_TID_MASK;
if (unlikely(tid >= MAX_TID_COUNT))
goto drop;
}
txq = &il->txq[txq_id];
q = &txq->q;
if ((il_queue_space(q) < q->high_mark))
goto drop;
spin_lock_irqsave(&il->lock, flags);
idx = il_get_cmd_idx(q, q->write_ptr, 0);
txq->skbs[q->write_ptr] = skb;
out_cmd = txq->cmd[idx];
out_meta = &txq->meta[idx];
tx_cmd = (struct il3945_tx_cmd *)out_cmd->cmd.payload;
memset(&out_cmd->hdr, 0, sizeof(out_cmd->hdr));
memset(tx_cmd, 0, sizeof(*tx_cmd));
out_cmd->hdr.cmd = C_TX;
out_cmd->hdr.sequence =
cpu_to_le16((u16)
(QUEUE_TO_SEQ(txq_id) | IDX_TO_SEQ(q->write_ptr)));
memcpy(tx_cmd->hdr, hdr, hdr_len);
if (info->control.hw_key)
il3945_build_tx_cmd_hwcrypto(il, info, out_cmd, skb, sta_id);
il3945_build_tx_cmd_basic(il, out_cmd, info, hdr, sta_id);
il3945_hw_build_tx_cmd_rate(il, out_cmd, info, hdr, sta_id);
len = (u16) skb->len;
tx_cmd->len = cpu_to_le16(len);
il_update_stats(il, true, fc, len);
tx_cmd->tx_flags &= ~TX_CMD_FLG_ANT_A_MSK;
tx_cmd->tx_flags &= ~TX_CMD_FLG_ANT_B_MSK;
if (!ieee80211_has_morefrags(hdr->frame_control)) {
txq->need_update = 1;
} else {
wait_write_ptr = 1;
txq->need_update = 0;
}
D_TX("sequence nr = 0X%x\n", le16_to_cpu(out_cmd->hdr.sequence));
D_TX("tx_flags = 0X%x\n", le32_to_cpu(tx_cmd->tx_flags));
il_print_hex_dump(il, IL_DL_TX, tx_cmd, sizeof(*tx_cmd));
il_print_hex_dump(il, IL_DL_TX, (u8 *) tx_cmd->hdr,
ieee80211_hdrlen(fc));
len =
sizeof(struct il3945_tx_cmd) + sizeof(struct il_cmd_header) +
hdr_len;
len = (len + 3) & ~3;
txcmd_phys =
pci_map_single(il->pci_dev, &out_cmd->hdr, len, PCI_DMA_TODEVICE);
dma_unmap_addr_set(out_meta, mapping, txcmd_phys);
dma_unmap_len_set(out_meta, len, len);
il->ops->txq_attach_buf_to_tfd(il, txq, txcmd_phys, len, 1, 0);
len = skb->len - hdr_len;
if (len) {
phys_addr =
pci_map_single(il->pci_dev, skb->data + hdr_len, len,
PCI_DMA_TODEVICE);
il->ops->txq_attach_buf_to_tfd(il, txq, phys_addr, len, 0,
U32_PAD(len));
}
q->write_ptr = il_queue_inc_wrap(q->write_ptr, q->n_bd);
il_txq_update_write_ptr(il, txq);
spin_unlock_irqrestore(&il->lock, flags);
if (il_queue_space(q) < q->high_mark && il->mac80211_registered) {
if (wait_write_ptr) {
spin_lock_irqsave(&il->lock, flags);
txq->need_update = 1;
il_txq_update_write_ptr(il, txq);
spin_unlock_irqrestore(&il->lock, flags);
}
il_stop_queue(il, txq);
}
return 0;
drop_unlock:
spin_unlock_irqrestore(&il->lock, flags);
drop:
return -1;
}
static int
il3945_get_measurement(struct il_priv *il,
struct ieee80211_measurement_params *params, u8 type)
{
struct il_spectrum_cmd spectrum;
struct il_rx_pkt *pkt;
struct il_host_cmd cmd = {
.id = C_SPECTRUM_MEASUREMENT,
.data = (void *)&spectrum,
.flags = CMD_WANT_SKB,
};
u32 add_time = le64_to_cpu(params->start_time);
int rc;
int spectrum_resp_status;
int duration = le16_to_cpu(params->duration);
if (il_is_associated(il))
add_time =
il_usecs_to_beacons(il,
le64_to_cpu(params->start_time) -
il->_3945.last_tsf,
le16_to_cpu(il->timing.beacon_interval));
memset(&spectrum, 0, sizeof(spectrum));
spectrum.channel_count = cpu_to_le16(1);
spectrum.flags =
RXON_FLG_TSF2HOST_MSK | RXON_FLG_ANT_A_MSK | RXON_FLG_DIS_DIV_MSK;
spectrum.filter_flags = MEASUREMENT_FILTER_FLAG;
cmd.len = sizeof(spectrum);
spectrum.len = cpu_to_le16(cmd.len - sizeof(spectrum.len));
if (il_is_associated(il))
spectrum.start_time =
il_add_beacon_time(il, il->_3945.last_beacon_time, add_time,
le16_to_cpu(il->timing.beacon_interval));
else
spectrum.start_time = 0;
spectrum.channels[0].duration = cpu_to_le32(duration * TIME_UNIT);
spectrum.channels[0].channel = params->channel;
spectrum.channels[0].type = type;
if (il->active.flags & RXON_FLG_BAND_24G_MSK)
spectrum.flags |=
RXON_FLG_BAND_24G_MSK | RXON_FLG_AUTO_DETECT_MSK |
RXON_FLG_TGG_PROTECT_MSK;
rc = il_send_cmd_sync(il, &cmd);
if (rc)
return rc;
pkt = (struct il_rx_pkt *)cmd.reply_page;
if (pkt->hdr.flags & IL_CMD_FAILED_MSK) {
IL_ERR("Bad return from N_RX_ON_ASSOC command\n");
rc = -EIO;
}
spectrum_resp_status = le16_to_cpu(pkt->u.spectrum.status);
switch (spectrum_resp_status) {
case 0:
if (pkt->u.spectrum.id != 0xff) {
D_INFO("Replaced existing measurement: %d\n",
pkt->u.spectrum.id);
il->measurement_status &= ~MEASUREMENT_READY;
}
il->measurement_status |= MEASUREMENT_ACTIVE;
rc = 0;
break;
case 1:
rc = -EAGAIN;
break;
}
il_free_pages(il, cmd.reply_page);
return rc;
}
static void
il3945_hdl_alive(struct il_priv *il, struct il_rx_buf *rxb)
{
struct il_rx_pkt *pkt = rxb_addr(rxb);
struct il_alive_resp *palive;
struct delayed_work *pwork;
palive = &pkt->u.alive_frame;
D_INFO("Alive ucode status 0x%08X revision " "0x%01X 0x%01X\n",
palive->is_valid, palive->ver_type, palive->ver_subtype);
if (palive->ver_subtype == INITIALIZE_SUBTYPE) {
D_INFO("Initialization Alive received.\n");
memcpy(&il->card_alive_init, &pkt->u.alive_frame,
sizeof(struct il_alive_resp));
pwork = &il->init_alive_start;
} else {
D_INFO("Runtime Alive received.\n");
memcpy(&il->card_alive, &pkt->u.alive_frame,
sizeof(struct il_alive_resp));
pwork = &il->alive_start;
il3945_disable_events(il);
}
if (palive->is_valid == UCODE_VALID_OK)
queue_delayed_work(il->workqueue, pwork, msecs_to_jiffies(5));
else
IL_WARN("uCode did not respond OK.\n");
}
static void
il3945_hdl_add_sta(struct il_priv *il, struct il_rx_buf *rxb)
{
#ifdef CONFIG_IWLEGACY_DEBUG
struct il_rx_pkt *pkt = rxb_addr(rxb);
#endif
D_RX("Received C_ADD_STA: 0x%02X\n", pkt->u.status);
}
static void
il3945_hdl_beacon(struct il_priv *il, struct il_rx_buf *rxb)
{
struct il_rx_pkt *pkt = rxb_addr(rxb);
struct il3945_beacon_notif *beacon = &(pkt->u.beacon_status);
#ifdef CONFIG_IWLEGACY_DEBUG
u8 rate = beacon->beacon_notify_hdr.rate;
D_RX("beacon status %x retries %d iss %d " "tsf %d %d rate %d\n",
le32_to_cpu(beacon->beacon_notify_hdr.status) & TX_STATUS_MSK,
beacon->beacon_notify_hdr.failure_frame,
le32_to_cpu(beacon->ibss_mgr_status),
le32_to_cpu(beacon->high_tsf), le32_to_cpu(beacon->low_tsf), rate);
#endif
il->ibss_manager = le32_to_cpu(beacon->ibss_mgr_status);
}
static void
il3945_hdl_card_state(struct il_priv *il, struct il_rx_buf *rxb)
{
struct il_rx_pkt *pkt = rxb_addr(rxb);
u32 flags = le32_to_cpu(pkt->u.card_state_notif.flags);
unsigned long status = il->status;
IL_WARN("Card state received: HW:%s SW:%s\n",
(flags & HW_CARD_DISABLED) ? "Kill" : "On",
(flags & SW_CARD_DISABLED) ? "Kill" : "On");
_il_wr(il, CSR_UCODE_DRV_GP1_SET, CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
if (flags & HW_CARD_DISABLED)
set_bit(S_RFKILL, &il->status);
else
clear_bit(S_RFKILL, &il->status);
il_scan_cancel(il);
if ((test_bit(S_RFKILL, &status) !=
test_bit(S_RFKILL, &il->status)))
wiphy_rfkill_set_hw_state(il->hw->wiphy,
test_bit(S_RFKILL, &il->status));
else
wake_up(&il->wait_command_queue);
}
static void
il3945_setup_handlers(struct il_priv *il)
{
il->handlers[N_ALIVE] = il3945_hdl_alive;
il->handlers[C_ADD_STA] = il3945_hdl_add_sta;
il->handlers[N_ERROR] = il_hdl_error;
il->handlers[N_CHANNEL_SWITCH] = il_hdl_csa;
il->handlers[N_SPECTRUM_MEASUREMENT] = il_hdl_spectrum_measurement;
il->handlers[N_PM_SLEEP] = il_hdl_pm_sleep;
il->handlers[N_PM_DEBUG_STATS] = il_hdl_pm_debug_stats;
il->handlers[N_BEACON] = il3945_hdl_beacon;
il->handlers[C_STATS] = il3945_hdl_c_stats;
il->handlers[N_STATS] = il3945_hdl_stats;
il_setup_rx_scan_handlers(il);
il->handlers[N_CARD_STATE] = il3945_hdl_card_state;
il3945_hw_handler_setup(il);
}
static inline __le32
il3945_dma_addr2rbd_ptr(struct il_priv *il, dma_addr_t dma_addr)
{
return cpu_to_le32((u32) dma_addr);
}
static void
il3945_rx_queue_restock(struct il_priv *il)
{
struct il_rx_queue *rxq = &il->rxq;
struct list_head *element;
struct il_rx_buf *rxb;
unsigned long flags;
int write;
spin_lock_irqsave(&rxq->lock, flags);
write = rxq->write & ~0x7;
while (il_rx_queue_space(rxq) > 0 && rxq->free_count) {
element = rxq->rx_free.next;
rxb = list_entry(element, struct il_rx_buf, list);
list_del(element);
rxq->bd[rxq->write] =
il3945_dma_addr2rbd_ptr(il, rxb->page_dma);
rxq->queue[rxq->write] = rxb;
rxq->write = (rxq->write + 1) & RX_QUEUE_MASK;
rxq->free_count--;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count <= RX_LOW_WATERMARK)
queue_work(il->workqueue, &il->rx_replenish);
if (rxq->write_actual != (rxq->write & ~0x7) ||
abs(rxq->write - rxq->read) > 7) {
spin_lock_irqsave(&rxq->lock, flags);
rxq->need_update = 1;
spin_unlock_irqrestore(&rxq->lock, flags);
il_rx_queue_update_write_ptr(il, rxq);
}
}
static void
il3945_rx_allocate(struct il_priv *il, gfp_t priority)
{
struct il_rx_queue *rxq = &il->rxq;
struct list_head *element;
struct il_rx_buf *rxb;
struct page *page;
unsigned long flags;
gfp_t gfp_mask = priority;
while (1) {
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
return;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count > RX_LOW_WATERMARK)
gfp_mask |= __GFP_NOWARN;
if (il->hw_params.rx_page_order > 0)
gfp_mask |= __GFP_COMP;
page = alloc_pages(gfp_mask, il->hw_params.rx_page_order);
if (!page) {
if (net_ratelimit())
D_INFO("Failed to allocate SKB buffer.\n");
if (rxq->free_count <= RX_LOW_WATERMARK &&
net_ratelimit())
IL_ERR("Failed to allocate SKB buffer with %0x."
"Only %u free buffers remaining.\n",
priority, rxq->free_count);
break;
}
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
__free_pages(page, il->hw_params.rx_page_order);
return;
}
element = rxq->rx_used.next;
rxb = list_entry(element, struct il_rx_buf, list);
list_del(element);
spin_unlock_irqrestore(&rxq->lock, flags);
rxb->page = page;
rxb->page_dma =
pci_map_page(il->pci_dev, page, 0,
PAGE_SIZE << il->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
spin_lock_irqsave(&rxq->lock, flags);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
il->alloc_rxb_page++;
spin_unlock_irqrestore(&rxq->lock, flags);
}
}
void
il3945_rx_queue_reset(struct il_priv *il, struct il_rx_queue *rxq)
{
unsigned long flags;
int i;
spin_lock_irqsave(&rxq->lock, flags);
INIT_LIST_HEAD(&rxq->rx_free);
INIT_LIST_HEAD(&rxq->rx_used);
for (i = 0; i < RX_FREE_BUFFERS + RX_QUEUE_SIZE; i++) {
if (rxq->pool[i].page != NULL) {
pci_unmap_page(il->pci_dev, rxq->pool[i].page_dma,
PAGE_SIZE << il->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
__il_free_pages(il, rxq->pool[i].page);
rxq->pool[i].page = NULL;
}
list_add_tail(&rxq->pool[i].list, &rxq->rx_used);
}
rxq->read = rxq->write = 0;
rxq->write_actual = 0;
rxq->free_count = 0;
spin_unlock_irqrestore(&rxq->lock, flags);
}
void
il3945_rx_replenish(void *data)
{
struct il_priv *il = data;
unsigned long flags;
il3945_rx_allocate(il, GFP_KERNEL);
spin_lock_irqsave(&il->lock, flags);
il3945_rx_queue_restock(il);
spin_unlock_irqrestore(&il->lock, flags);
}
static void
il3945_rx_replenish_now(struct il_priv *il)
{
il3945_rx_allocate(il, GFP_ATOMIC);
il3945_rx_queue_restock(il);
}
static void
il3945_rx_queue_free(struct il_priv *il, struct il_rx_queue *rxq)
{
int i;
for (i = 0; i < RX_QUEUE_SIZE + RX_FREE_BUFFERS; i++) {
if (rxq->pool[i].page != NULL) {
pci_unmap_page(il->pci_dev, rxq->pool[i].page_dma,
PAGE_SIZE << il->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
__il_free_pages(il, rxq->pool[i].page);
rxq->pool[i].page = NULL;
}
}
dma_free_coherent(&il->pci_dev->dev, 4 * RX_QUEUE_SIZE, rxq->bd,
rxq->bd_dma);
dma_free_coherent(&il->pci_dev->dev, sizeof(struct il_rb_status),
rxq->rb_stts, rxq->rb_stts_dma);
rxq->bd = NULL;
rxq->rb_stts = NULL;
}
int
il3945_calc_db_from_ratio(int sig_ratio)
{
if (sig_ratio >= 1000)
return 60;
if (sig_ratio >= 100)
return 20 + (int)ratio2dB[sig_ratio / 10];
if (sig_ratio < 1)
return 0;
return (int)ratio2dB[sig_ratio];
}
static void
il3945_rx_handle(struct il_priv *il)
{
struct il_rx_buf *rxb;
struct il_rx_pkt *pkt;
struct il_rx_queue *rxq = &il->rxq;
u32 r, i;
int reclaim;
unsigned long flags;
u8 fill_rx = 0;
u32 count = 8;
int total_empty = 0;
r = le16_to_cpu(rxq->rb_stts->closed_rb_num) & 0x0FFF;
i = rxq->read;
total_empty = r - rxq->write_actual;
if (total_empty < 0)
total_empty += RX_QUEUE_SIZE;
if (total_empty > (RX_QUEUE_SIZE / 2))
fill_rx = 1;
if (i == r)
D_RX("r = %d, i = %d\n", r, i);
while (i != r) {
int len;
rxb = rxq->queue[i];
BUG_ON(rxb == NULL);
rxq->queue[i] = NULL;
pci_unmap_page(il->pci_dev, rxb->page_dma,
PAGE_SIZE << il->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
pkt = rxb_addr(rxb);
len = le32_to_cpu(pkt->len_n_flags) & IL_RX_FRAME_SIZE_MSK;
len += sizeof(u32);
reclaim = !(pkt->hdr.sequence & SEQ_RX_FRAME) &&
pkt->hdr.cmd != N_STATS && pkt->hdr.cmd != C_TX;
if (il->handlers[pkt->hdr.cmd]) {
D_RX("r = %d, i = %d, %s, 0x%02x\n", r, i,
il_get_cmd_string(pkt->hdr.cmd), pkt->hdr.cmd);
il->isr_stats.handlers[pkt->hdr.cmd]++;
il->handlers[pkt->hdr.cmd] (il, rxb);
} else {
D_RX("r %d i %d No handler needed for %s, 0x%02x\n", r,
i, il_get_cmd_string(pkt->hdr.cmd), pkt->hdr.cmd);
}
if (reclaim) {
if (rxb->page)
il_tx_cmd_complete(il, rxb);
else
IL_WARN("Claim null rxb?\n");
}
spin_lock_irqsave(&rxq->lock, flags);
if (rxb->page != NULL) {
rxb->page_dma =
pci_map_page(il->pci_dev, rxb->page, 0,
PAGE_SIZE << il->hw_params.
rx_page_order, PCI_DMA_FROMDEVICE);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
} else
list_add_tail(&rxb->list, &rxq->rx_used);
spin_unlock_irqrestore(&rxq->lock, flags);
i = (i + 1) & RX_QUEUE_MASK;
if (fill_rx) {
count++;
if (count >= 8) {
rxq->read = i;
il3945_rx_replenish_now(il);
count = 0;
}
}
}
rxq->read = i;
if (fill_rx)
il3945_rx_replenish_now(il);
else
il3945_rx_queue_restock(il);
}
static inline void
il3945_synchronize_irq(struct il_priv *il)
{
synchronize_irq(il->pci_dev->irq);
tasklet_kill(&il->irq_tasklet);
}
static const char *
il3945_desc_lookup(int i)
{
switch (i) {
case 1:
return "FAIL";
case 2:
return "BAD_PARAM";
case 3:
return "BAD_CHECKSUM";
case 4:
return "NMI_INTERRUPT";
case 5:
return "SYSASSERT";
case 6:
return "FATAL_ERROR";
}
return "UNKNOWN";
}
void
il3945_dump_nic_error_log(struct il_priv *il)
{
u32 i;
u32 desc, time, count, base, data1;
u32 blink1, blink2, ilink1, ilink2;
base = le32_to_cpu(il->card_alive.error_event_table_ptr);
if (!il3945_hw_valid_rtc_data_addr(base)) {
IL_ERR("Not valid error log pointer 0x%08X\n", base);
return;
}
count = il_read_targ_mem(il, base);
if (ERROR_START_OFFSET <= count * ERROR_ELEM_SIZE) {
IL_ERR("Start IWL Error Log Dump:\n");
IL_ERR("Status: 0x%08lX, count: %d\n", il->status, count);
}
IL_ERR("Desc Time asrtPC blink2 "
"ilink1 nmiPC Line\n");
for (i = ERROR_START_OFFSET;
i < (count * ERROR_ELEM_SIZE) + ERROR_START_OFFSET;
i += ERROR_ELEM_SIZE) {
desc = il_read_targ_mem(il, base + i);
time = il_read_targ_mem(il, base + i + 1 * sizeof(u32));
blink1 = il_read_targ_mem(il, base + i + 2 * sizeof(u32));
blink2 = il_read_targ_mem(il, base + i + 3 * sizeof(u32));
ilink1 = il_read_targ_mem(il, base + i + 4 * sizeof(u32));
ilink2 = il_read_targ_mem(il, base + i + 5 * sizeof(u32));
data1 = il_read_targ_mem(il, base + i + 6 * sizeof(u32));
IL_ERR("%-13s (0x%X) %010u 0x%05X 0x%05X 0x%05X 0x%05X %u\n\n",
il3945_desc_lookup(desc), desc, time, blink1, blink2,
ilink1, ilink2, data1);
}
}
static void
il3945_irq_tasklet(struct il_priv *il)
{
u32 inta, handled = 0;
u32 inta_fh;
unsigned long flags;
#ifdef CONFIG_IWLEGACY_DEBUG
u32 inta_mask;
#endif
spin_lock_irqsave(&il->lock, flags);
inta = _il_rd(il, CSR_INT);
_il_wr(il, CSR_INT, inta);
inta_fh = _il_rd(il, CSR_FH_INT_STATUS);
_il_wr(il, CSR_FH_INT_STATUS, inta_fh);
#ifdef CONFIG_IWLEGACY_DEBUG
if (il_get_debug_level(il) & IL_DL_ISR) {
inta_mask = _il_rd(il, CSR_INT_MASK);
D_ISR("inta 0x%08x, enabled 0x%08x, fh 0x%08x\n", inta,
inta_mask, inta_fh);
}
#endif
spin_unlock_irqrestore(&il->lock, flags);
if (inta_fh & CSR39_FH_INT_RX_MASK)
inta |= CSR_INT_BIT_FH_RX;
if (inta_fh & CSR39_FH_INT_TX_MASK)
inta |= CSR_INT_BIT_FH_TX;
if (inta & CSR_INT_BIT_HW_ERR) {
IL_ERR("Hardware error detected. Restarting.\n");
il_disable_interrupts(il);
il->isr_stats.hw++;
il_irq_handle_error(il);
handled |= CSR_INT_BIT_HW_ERR;
return;
}
#ifdef CONFIG_IWLEGACY_DEBUG
if (il_get_debug_level(il) & (IL_DL_ISR)) {
if (inta & CSR_INT_BIT_SCD) {
D_ISR("Scheduler finished to transmit "
"the frame/frames.\n");
il->isr_stats.sch++;
}
if (inta & CSR_INT_BIT_ALIVE) {
D_ISR("Alive interrupt\n");
il->isr_stats.alive++;
}
}
#endif
inta &= ~(CSR_INT_BIT_SCD | CSR_INT_BIT_ALIVE);
if (inta & CSR_INT_BIT_SW_ERR) {
IL_ERR("Microcode SW error detected. " "Restarting 0x%X.\n",
inta);
il->isr_stats.sw++;
il_irq_handle_error(il);
handled |= CSR_INT_BIT_SW_ERR;
}
if (inta & CSR_INT_BIT_WAKEUP) {
D_ISR("Wakeup interrupt\n");
il_rx_queue_update_write_ptr(il, &il->rxq);
il_txq_update_write_ptr(il, &il->txq[0]);
il_txq_update_write_ptr(il, &il->txq[1]);
il_txq_update_write_ptr(il, &il->txq[2]);
il_txq_update_write_ptr(il, &il->txq[3]);
il_txq_update_write_ptr(il, &il->txq[4]);
il_txq_update_write_ptr(il, &il->txq[5]);
il->isr_stats.wakeup++;
handled |= CSR_INT_BIT_WAKEUP;
}
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX)) {
il3945_rx_handle(il);
il->isr_stats.rx++;
handled |= (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX);
}
if (inta & CSR_INT_BIT_FH_TX) {
D_ISR("Tx interrupt\n");
il->isr_stats.tx++;
_il_wr(il, CSR_FH_INT_STATUS, (1 << 6));
il_wr(il, FH39_TCSR_CREDIT(FH39_SRVC_CHNL), 0x0);
handled |= CSR_INT_BIT_FH_TX;
}
if (inta & ~handled) {
IL_ERR("Unhandled INTA bits 0x%08x\n", inta & ~handled);
il->isr_stats.unhandled++;
}
if (inta & ~il->inta_mask) {
IL_WARN("Disabled INTA bits 0x%08x were pending\n",
inta & ~il->inta_mask);
IL_WARN(" with inta_fh = 0x%08x\n", inta_fh);
}
if (test_bit(S_INT_ENABLED, &il->status))
il_enable_interrupts(il);
#ifdef CONFIG_IWLEGACY_DEBUG
if (il_get_debug_level(il) & (IL_DL_ISR)) {
inta = _il_rd(il, CSR_INT);
inta_mask = _il_rd(il, CSR_INT_MASK);
inta_fh = _il_rd(il, CSR_FH_INT_STATUS);
D_ISR("End inta 0x%08x, enabled 0x%08x, fh 0x%08x, "
"flags 0x%08lx\n", inta, inta_mask, inta_fh, flags);
}
#endif
}
static int
il3945_get_channels_for_scan(struct il_priv *il, enum ieee80211_band band,
u8 is_active, u8 n_probes,
struct il3945_scan_channel *scan_ch,
struct ieee80211_vif *vif)
{
struct ieee80211_channel *chan;
const struct ieee80211_supported_band *sband;
const struct il_channel_info *ch_info;
u16 passive_dwell = 0;
u16 active_dwell = 0;
int added, i;
sband = il_get_hw_mode(il, band);
if (!sband)
return 0;
active_dwell = il_get_active_dwell_time(il, band, n_probes);
passive_dwell = il_get_passive_dwell_time(il, band, vif);
if (passive_dwell <= active_dwell)
passive_dwell = active_dwell + 1;
for (i = 0, added = 0; i < il->scan_request->n_channels; i++) {
chan = il->scan_request->channels[i];
if (chan->band != band)
continue;
scan_ch->channel = chan->hw_value;
ch_info = il_get_channel_info(il, band, scan_ch->channel);
if (!il_is_channel_valid(ch_info)) {
D_SCAN("Channel %d is INVALID for this band.\n",
scan_ch->channel);
continue;
}
scan_ch->active_dwell = cpu_to_le16(active_dwell);
scan_ch->passive_dwell = cpu_to_le16(passive_dwell);
if (!is_active || il_is_channel_passive(ch_info) ||
(chan->flags & IEEE80211_CHAN_PASSIVE_SCAN)) {
scan_ch->type = 0;
if (IL_UCODE_API(il->ucode_ver) == 1)
scan_ch->active_dwell =
cpu_to_le16(passive_dwell - 1);
} else {
scan_ch->type = 1;
}
if (IL_UCODE_API(il->ucode_ver) >= 2) {
if (n_probes)
scan_ch->type |= IL39_SCAN_PROBE_MASK(n_probes);
} else {
if ((scan_ch->type & 1) && n_probes)
scan_ch->type |= IL39_SCAN_PROBE_MASK(n_probes);
}
scan_ch->tpc.dsp_atten = 110;
if (band == IEEE80211_BAND_5GHZ)
scan_ch->tpc.tx_gain = ((1 << 5) | (3 << 3)) | 3;
else {
scan_ch->tpc.tx_gain = ((1 << 5) | (5 << 3));
}
D_SCAN("Scanning %d [%s %d]\n", scan_ch->channel,
(scan_ch->type & 1) ? "ACTIVE" : "PASSIVE",
(scan_ch->type & 1) ? active_dwell : passive_dwell);
scan_ch++;
added++;
}
D_SCAN("total channels to scan %d\n", added);
return added;
}
static void
il3945_init_hw_rates(struct il_priv *il, struct ieee80211_rate *rates)
{
int i;
for (i = 0; i < RATE_COUNT_LEGACY; i++) {
rates[i].bitrate = il3945_rates[i].ieee * 5;
rates[i].hw_value = i;
rates[i].hw_value_short = i;
rates[i].flags = 0;
if (i > IL39_LAST_OFDM_RATE || i < IL_FIRST_OFDM_RATE) {
rates[i].flags |=
(il3945_rates[i].plcp ==
10) ? 0 : IEEE80211_RATE_SHORT_PREAMBLE;
}
}
}
static void
il3945_dealloc_ucode_pci(struct il_priv *il)
{
il_free_fw_desc(il->pci_dev, &il->ucode_code);
il_free_fw_desc(il->pci_dev, &il->ucode_data);
il_free_fw_desc(il->pci_dev, &il->ucode_data_backup);
il_free_fw_desc(il->pci_dev, &il->ucode_init);
il_free_fw_desc(il->pci_dev, &il->ucode_init_data);
il_free_fw_desc(il->pci_dev, &il->ucode_boot);
}
static int
il3945_verify_inst_full(struct il_priv *il, __le32 * image, u32 len)
{
u32 val;
u32 save_len = len;
int rc = 0;
u32 errcnt;
D_INFO("ucode inst image size is %u\n", len);
il_wr(il, HBUS_TARG_MEM_RADDR, IL39_RTC_INST_LOWER_BOUND);
errcnt = 0;
for (; len > 0; len -= sizeof(u32), image++) {
val = _il_rd(il, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image)) {
IL_ERR("uCode INST section is invalid at "
"offset 0x%x, is 0x%x, s/b 0x%x\n",
save_len - len, val, le32_to_cpu(*image));
rc = -EIO;
errcnt++;
if (errcnt >= 20)
break;
}
}
if (!errcnt)
D_INFO("ucode image in INSTRUCTION memory is good\n");
return rc;
}
static int
il3945_verify_inst_sparse(struct il_priv *il, __le32 * image, u32 len)
{
u32 val;
int rc = 0;
u32 errcnt = 0;
u32 i;
D_INFO("ucode inst image size is %u\n", len);
for (i = 0; i < len; i += 100, image += 100 / sizeof(u32)) {
il_wr(il, HBUS_TARG_MEM_RADDR, i + IL39_RTC_INST_LOWER_BOUND);
val = _il_rd(il, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image)) {
#if 0
IL_ERR("uCode INST section is invalid at "
"offset 0x%x, is 0x%x, s/b 0x%x\n", i, val,
*image);
#endif
rc = -EIO;
errcnt++;
if (errcnt >= 3)
break;
}
}
return rc;
}
static int
il3945_verify_ucode(struct il_priv *il)
{
__le32 *image;
u32 len;
int rc = 0;
image = (__le32 *) il->ucode_boot.v_addr;
len = il->ucode_boot.len;
rc = il3945_verify_inst_sparse(il, image, len);
if (rc == 0) {
D_INFO("Bootstrap uCode is good in inst SRAM\n");
return 0;
}
image = (__le32 *) il->ucode_init.v_addr;
len = il->ucode_init.len;
rc = il3945_verify_inst_sparse(il, image, len);
if (rc == 0) {
D_INFO("Initialize uCode is good in inst SRAM\n");
return 0;
}
image = (__le32 *) il->ucode_code.v_addr;
len = il->ucode_code.len;
rc = il3945_verify_inst_sparse(il, image, len);
if (rc == 0) {
D_INFO("Runtime uCode is good in inst SRAM\n");
return 0;
}
IL_ERR("NO VALID UCODE IMAGE IN INSTRUCTION SRAM!!\n");
image = (__le32 *) il->ucode_boot.v_addr;
len = il->ucode_boot.len;
rc = il3945_verify_inst_full(il, image, len);
return rc;
}
static void
il3945_nic_start(struct il_priv *il)
{
_il_wr(il, CSR_RESET, 0);
}
static u32
il3945_ucode_get_header_size(u32 api_ver)
{
return 24;
}
static u8 *
il3945_ucode_get_data(const struct il_ucode_header *ucode)
{
return (u8 *) ucode->v1.data;
}
static int
il3945_read_ucode(struct il_priv *il)
{
const struct il_ucode_header *ucode;
int ret = -EINVAL, idx;
const struct firmware *ucode_raw;
const char *name_pre = il->cfg->fw_name_pre;
const unsigned int api_max = il->cfg->ucode_api_max;
const unsigned int api_min = il->cfg->ucode_api_min;
char buf[25];
u8 *src;
size_t len;
u32 api_ver, inst_size, data_size, init_size, init_data_size, boot_size;
for (idx = api_max; idx >= api_min; idx--) {
sprintf(buf, "%s%u%s", name_pre, idx, ".ucode");
ret = request_firmware(&ucode_raw, buf, &il->pci_dev->dev);
if (ret < 0) {
IL_ERR("%s firmware file req failed: %d\n", buf, ret);
if (ret == -ENOENT)
continue;
else
goto error;
} else {
if (idx < api_max)
IL_ERR("Loaded firmware %s, "
"which is deprecated. "
" Please use API v%u instead.\n", buf,
api_max);
D_INFO("Got firmware '%s' file "
"(%zd bytes) from disk\n", buf, ucode_raw->size);
break;
}
}
if (ret < 0)
goto error;
if (ucode_raw->size < il3945_ucode_get_header_size(1)) {
IL_ERR("File size way too small!\n");
ret = -EINVAL;
goto err_release;
}
ucode = (struct il_ucode_header *)ucode_raw->data;
il->ucode_ver = le32_to_cpu(ucode->ver);
api_ver = IL_UCODE_API(il->ucode_ver);
inst_size = il3945_ucode_get_inst_size(ucode);
data_size = il3945_ucode_get_data_size(ucode);
init_size = il3945_ucode_get_init_size(ucode);
init_data_size = il3945_ucode_get_init_data_size(ucode);
boot_size = il3945_ucode_get_boot_size(ucode);
src = il3945_ucode_get_data(ucode);
if (api_ver < api_min || api_ver > api_max) {
IL_ERR("Driver unable to support your firmware API. "
"Driver supports v%u, firmware is v%u.\n", api_max,
api_ver);
il->ucode_ver = 0;
ret = -EINVAL;
goto err_release;
}
if (api_ver != api_max)
IL_ERR("Firmware has old API version. Expected %u, "
"got %u. New firmware can be obtained "
"from http://www.intellinuxwireless.org.\n", api_max,
api_ver);
IL_INFO("loaded firmware version %u.%u.%u.%u\n",
IL_UCODE_MAJOR(il->ucode_ver), IL_UCODE_MINOR(il->ucode_ver),
IL_UCODE_API(il->ucode_ver), IL_UCODE_SERIAL(il->ucode_ver));
snprintf(il->hw->wiphy->fw_version, sizeof(il->hw->wiphy->fw_version),
"%u.%u.%u.%u", IL_UCODE_MAJOR(il->ucode_ver),
IL_UCODE_MINOR(il->ucode_ver), IL_UCODE_API(il->ucode_ver),
IL_UCODE_SERIAL(il->ucode_ver));
D_INFO("f/w package hdr ucode version raw = 0x%x\n", il->ucode_ver);
D_INFO("f/w package hdr runtime inst size = %u\n", inst_size);
D_INFO("f/w package hdr runtime data size = %u\n", data_size);
D_INFO("f/w package hdr init inst size = %u\n", init_size);
D_INFO("f/w package hdr init data size = %u\n", init_data_size);
D_INFO("f/w package hdr boot inst size = %u\n", boot_size);
if (ucode_raw->size !=
il3945_ucode_get_header_size(api_ver) + inst_size + data_size +
init_size + init_data_size + boot_size) {
D_INFO("uCode file size %zd does not match expected size\n",
ucode_raw->size);
ret = -EINVAL;
goto err_release;
}
if (inst_size > IL39_MAX_INST_SIZE) {
D_INFO("uCode instr len %d too large to fit in\n", inst_size);
ret = -EINVAL;
goto err_release;
}
if (data_size > IL39_MAX_DATA_SIZE) {
D_INFO("uCode data len %d too large to fit in\n", data_size);
ret = -EINVAL;
goto err_release;
}
if (init_size > IL39_MAX_INST_SIZE) {
D_INFO("uCode init instr len %d too large to fit in\n",
init_size);
ret = -EINVAL;
goto err_release;
}
if (init_data_size > IL39_MAX_DATA_SIZE) {
D_INFO("uCode init data len %d too large to fit in\n",
init_data_size);
ret = -EINVAL;
goto err_release;
}
if (boot_size > IL39_MAX_BSM_SIZE) {
D_INFO("uCode boot instr len %d too large to fit in\n",
boot_size);
ret = -EINVAL;
goto err_release;
}
il->ucode_code.len = inst_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_code);
il->ucode_data.len = data_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_data);
il->ucode_data_backup.len = data_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_data_backup);
if (!il->ucode_code.v_addr || !il->ucode_data.v_addr ||
!il->ucode_data_backup.v_addr)
goto err_pci_alloc;
if (init_size && init_data_size) {
il->ucode_init.len = init_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_init);
il->ucode_init_data.len = init_data_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_init_data);
if (!il->ucode_init.v_addr || !il->ucode_init_data.v_addr)
goto err_pci_alloc;
}
if (boot_size) {
il->ucode_boot.len = boot_size;
il_alloc_fw_desc(il->pci_dev, &il->ucode_boot);
if (!il->ucode_boot.v_addr)
goto err_pci_alloc;
}
len = inst_size;
D_INFO("Copying (but not loading) uCode instr len %zd\n", len);
memcpy(il->ucode_code.v_addr, src, len);
src += len;
D_INFO("uCode instr buf vaddr = 0x%p, paddr = 0x%08x\n",
il->ucode_code.v_addr, (u32) il->ucode_code.p_addr);
len = data_size;
D_INFO("Copying (but not loading) uCode data len %zd\n", len);
memcpy(il->ucode_data.v_addr, src, len);
memcpy(il->ucode_data_backup.v_addr, src, len);
src += len;
if (init_size) {
len = init_size;
D_INFO("Copying (but not loading) init instr len %zd\n", len);
memcpy(il->ucode_init.v_addr, src, len);
src += len;
}
if (init_data_size) {
len = init_data_size;
D_INFO("Copying (but not loading) init data len %zd\n", len);
memcpy(il->ucode_init_data.v_addr, src, len);
src += len;
}
len = boot_size;
D_INFO("Copying (but not loading) boot instr len %zd\n", len);
memcpy(il->ucode_boot.v_addr, src, len);
release_firmware(ucode_raw);
return 0;
err_pci_alloc:
IL_ERR("failed to allocate pci memory\n");
ret = -ENOMEM;
il3945_dealloc_ucode_pci(il);
err_release:
release_firmware(ucode_raw);
error:
return ret;
}
static int
il3945_set_ucode_ptrs(struct il_priv *il)
{
dma_addr_t pinst;
dma_addr_t pdata;
pinst = il->ucode_code.p_addr;
pdata = il->ucode_data_backup.p_addr;
il_wr_prph(il, BSM_DRAM_INST_PTR_REG, pinst);
il_wr_prph(il, BSM_DRAM_DATA_PTR_REG, pdata);
il_wr_prph(il, BSM_DRAM_DATA_BYTECOUNT_REG, il->ucode_data.len);
il_wr_prph(il, BSM_DRAM_INST_BYTECOUNT_REG,
il->ucode_code.len | BSM_DRAM_INST_LOAD);
D_INFO("Runtime uCode pointers are set.\n");
return 0;
}
static void
il3945_init_alive_start(struct il_priv *il)
{
if (il->card_alive_init.is_valid != UCODE_VALID_OK) {
D_INFO("Initialize Alive failed.\n");
goto restart;
}
if (il3945_verify_ucode(il)) {
D_INFO("Bad \"initialize\" uCode load.\n");
goto restart;
}
D_INFO("Initialization Alive received.\n");
if (il3945_set_ucode_ptrs(il)) {
D_INFO("Couldn't set up uCode pointers.\n");
goto restart;
}
return;
restart:
queue_work(il->workqueue, &il->restart);
}
static void
il3945_alive_start(struct il_priv *il)
{
int thermal_spin = 0;
u32 rfkill;
D_INFO("Runtime Alive received.\n");
if (il->card_alive.is_valid != UCODE_VALID_OK) {
D_INFO("Alive failed.\n");
goto restart;
}
if (il3945_verify_ucode(il)) {
D_INFO("Bad runtime uCode load.\n");
goto restart;
}
rfkill = il_rd_prph(il, APMG_RFKILL_REG);
D_INFO("RFKILL status: 0x%x\n", rfkill);
if (rfkill & 0x1) {
clear_bit(S_RFKILL, &il->status);
while (il3945_hw_get_temperature(il) == 0) {
thermal_spin++;
udelay(10);
}
if (thermal_spin)
D_INFO("Thermal calibration took %dus\n",
thermal_spin * 10);
} else
set_bit(S_RFKILL, &il->status);
set_bit(S_ALIVE, &il->status);
il_setup_watchdog(il);
if (il_is_rfkill(il))
return;
ieee80211_wake_queues(il->hw);
il->active_rate = RATES_MASK_3945;
il_power_update_mode(il, true);
if (il_is_associated(il)) {
struct il3945_rxon_cmd *active_rxon =
(struct il3945_rxon_cmd *)(&il->active);
il->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
active_rxon->filter_flags &= ~RXON_FILTER_ASSOC_MSK;
} else {
il_connection_init_rx_config(il);
}
il_send_bt_config(il);
set_bit(S_READY, &il->status);
il3945_commit_rxon(il);
il3945_reg_txpower_periodic(il);
D_INFO("ALIVE processing complete.\n");
wake_up(&il->wait_command_queue);
return;
restart:
queue_work(il->workqueue, &il->restart);
}
static void
__il3945_down(struct il_priv *il)
{
unsigned long flags;
int exit_pending;
D_INFO(DRV_NAME " is going down\n");
il_scan_cancel_timeout(il, 200);
exit_pending = test_and_set_bit(S_EXIT_PENDING, &il->status);
del_timer_sync(&il->watchdog);
il_clear_ucode_stations(il);
il_dealloc_bcast_stations(il);
il_clear_driver_stations(il);
wake_up_all(&il->wait_command_queue);
if (!exit_pending)
clear_bit(S_EXIT_PENDING, &il->status);
_il_wr(il, CSR_RESET, CSR_RESET_REG_FLAG_NEVO_RESET);
spin_lock_irqsave(&il->lock, flags);
il_disable_interrupts(il);
spin_unlock_irqrestore(&il->lock, flags);
il3945_synchronize_irq(il);
if (il->mac80211_registered)
ieee80211_stop_queues(il->hw);
if (!il_is_init(il)) {
il->status =
test_bit(S_RFKILL, &il->status) << S_RFKILL |
test_bit(S_GEO_CONFIGURED, &il->status) << S_GEO_CONFIGURED |
test_bit(S_EXIT_PENDING, &il->status) << S_EXIT_PENDING;
goto exit;
}
il->status &=
test_bit(S_RFKILL, &il->status) << S_RFKILL |
test_bit(S_GEO_CONFIGURED, &il->status) << S_GEO_CONFIGURED |
test_bit(S_FW_ERROR, &il->status) << S_FW_ERROR |
test_bit(S_EXIT_PENDING, &il->status) << S_EXIT_PENDING;
spin_lock_irq(&il->reg_lock);
il3945_hw_txq_ctx_stop(il);
il3945_hw_rxq_stop(il);
_il_wr_prph(il, APMG_CLK_DIS_REG, APMG_CLK_VAL_DMA_CLK_RQT);
udelay(5);
_il_apm_stop(il);
spin_unlock_irq(&il->reg_lock);
il3945_hw_txq_ctx_free(il);
exit:
memset(&il->card_alive, 0, sizeof(struct il_alive_resp));
if (il->beacon_skb)
dev_kfree_skb(il->beacon_skb);
il->beacon_skb = NULL;
il3945_clear_free_frames(il);
}
static void
il3945_down(struct il_priv *il)
{
mutex_lock(&il->mutex);
__il3945_down(il);
mutex_unlock(&il->mutex);
il3945_cancel_deferred_work(il);
}
static int
il3945_alloc_bcast_station(struct il_priv *il)
{
unsigned long flags;
u8 sta_id;
spin_lock_irqsave(&il->sta_lock, flags);
sta_id = il_prep_station(il, il_bcast_addr, false, NULL);
if (sta_id == IL_INVALID_STATION) {
IL_ERR("Unable to prepare broadcast station\n");
spin_unlock_irqrestore(&il->sta_lock, flags);
return -EINVAL;
}
il->stations[sta_id].used |= IL_STA_DRIVER_ACTIVE;
il->stations[sta_id].used |= IL_STA_BCAST;
spin_unlock_irqrestore(&il->sta_lock, flags);
return 0;
}
static int
__il3945_up(struct il_priv *il)
{
int rc, i;
rc = il3945_alloc_bcast_station(il);
if (rc)
return rc;
if (test_bit(S_EXIT_PENDING, &il->status)) {
IL_WARN("Exit pending; will not bring the NIC up\n");
return -EIO;
}
if (!il->ucode_data_backup.v_addr || !il->ucode_data.v_addr) {
IL_ERR("ucode not available for device bring up\n");
return -EIO;
}
if (_il_rd(il, CSR_GP_CNTRL) & CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW)
clear_bit(S_RFKILL, &il->status);
else {
set_bit(S_RFKILL, &il->status);
IL_WARN("Radio disabled by HW RF Kill switch\n");
return -ENODEV;
}
_il_wr(il, CSR_INT, 0xFFFFFFFF);
rc = il3945_hw_nic_init(il);
if (rc) {
IL_ERR("Unable to int nic\n");
return rc;
}
_il_wr(il, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
_il_wr(il, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
_il_wr(il, CSR_INT, 0xFFFFFFFF);
il_enable_interrupts(il);
_il_wr(il, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
_il_wr(il, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
memcpy(il->ucode_data_backup.v_addr, il->ucode_data.v_addr,
il->ucode_data.len);
if (test_bit(S_RFKILL, &il->status))
return 0;
for (i = 0; i < MAX_HW_RESTARTS; i++) {
rc = il->ops->load_ucode(il);
if (rc) {
IL_ERR("Unable to set up bootstrap uCode: %d\n", rc);
continue;
}
il3945_nic_start(il);
D_INFO(DRV_NAME " is coming up\n");
return 0;
}
set_bit(S_EXIT_PENDING, &il->status);
__il3945_down(il);
clear_bit(S_EXIT_PENDING, &il->status);
IL_ERR("Unable to initialize device after %d attempts.\n", i);
return -EIO;
}
static void
il3945_bg_init_alive_start(struct work_struct *data)
{
struct il_priv *il =
container_of(data, struct il_priv, init_alive_start.work);
mutex_lock(&il->mutex);
if (test_bit(S_EXIT_PENDING, &il->status))
goto out;
il3945_init_alive_start(il);
out:
mutex_unlock(&il->mutex);
}
static void
il3945_bg_alive_start(struct work_struct *data)
{
struct il_priv *il =
container_of(data, struct il_priv, alive_start.work);
mutex_lock(&il->mutex);
if (test_bit(S_EXIT_PENDING, &il->status) || il->txq == NULL)
goto out;
il3945_alive_start(il);
out:
mutex_unlock(&il->mutex);
}
static void
il3945_rfkill_poll(struct work_struct *data)
{
struct il_priv *il =
container_of(data, struct il_priv, _3945.rfkill_poll.work);
bool old_rfkill = test_bit(S_RFKILL, &il->status);
bool new_rfkill =
!(_il_rd(il, CSR_GP_CNTRL) & CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW);
if (new_rfkill != old_rfkill) {
if (new_rfkill)
set_bit(S_RFKILL, &il->status);
else
clear_bit(S_RFKILL, &il->status);
wiphy_rfkill_set_hw_state(il->hw->wiphy, new_rfkill);
D_RF_KILL("RF_KILL bit toggled to %s.\n",
new_rfkill ? "disable radio" : "enable radio");
}
queue_delayed_work(il->workqueue, &il->_3945.rfkill_poll,
round_jiffies_relative(2 * HZ));
}
int
il3945_request_scan(struct il_priv *il, struct ieee80211_vif *vif)
{
struct il_host_cmd cmd = {
.id = C_SCAN,
.len = sizeof(struct il3945_scan_cmd),
.flags = CMD_SIZE_HUGE,
};
struct il3945_scan_cmd *scan;
u8 n_probes = 0;
enum ieee80211_band band;
bool is_active = false;
int ret;
u16 len;
lockdep_assert_held(&il->mutex);
if (!il->scan_cmd) {
il->scan_cmd =
kmalloc(sizeof(struct il3945_scan_cmd) + IL_MAX_SCAN_SIZE,
GFP_KERNEL);
if (!il->scan_cmd) {
D_SCAN("Fail to allocate scan memory\n");
return -ENOMEM;
}
}
scan = il->scan_cmd;
memset(scan, 0, sizeof(struct il3945_scan_cmd) + IL_MAX_SCAN_SIZE);
scan->quiet_plcp_th = IL_PLCP_QUIET_THRESH;
scan->quiet_time = IL_ACTIVE_QUIET_TIME;
if (il_is_associated(il)) {
u16 interval;
u32 extra;
u32 suspend_time = 100;
u32 scan_suspend_time = 100;
D_INFO("Scanning while associated...\n");
interval = vif->bss_conf.beacon_int;
scan->suspend_time = 0;
scan->max_out_time = cpu_to_le32(200 * 1024);
if (!interval)
interval = suspend_time;
extra = (suspend_time / interval) << 24;
scan_suspend_time =
0xFF0FFFFF & (extra | ((suspend_time % interval) * 1024));
scan->suspend_time = cpu_to_le32(scan_suspend_time);
D_SCAN("suspend_time 0x%X beacon interval %d\n",
scan_suspend_time, interval);
}
if (il->scan_request->n_ssids) {
int i, p = 0;
D_SCAN("Kicking off active scan\n");
for (i = 0; i < il->scan_request->n_ssids; i++) {
if (!il->scan_request->ssids[i].ssid_len)
continue;
scan->direct_scan[p].id = WLAN_EID_SSID;
scan->direct_scan[p].len =
il->scan_request->ssids[i].ssid_len;
memcpy(scan->direct_scan[p].ssid,
il->scan_request->ssids[i].ssid,
il->scan_request->ssids[i].ssid_len);
n_probes++;
p++;
}
is_active = true;
} else
D_SCAN("Kicking off passive scan.\n");
scan->tx_cmd.tx_flags = TX_CMD_FLG_SEQ_CTL_MSK;
scan->tx_cmd.sta_id = il->hw_params.bcast_id;
scan->tx_cmd.stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
switch (il->scan_band) {
case IEEE80211_BAND_2GHZ:
scan->flags = RXON_FLG_BAND_24G_MSK | RXON_FLG_AUTO_DETECT_MSK;
scan->tx_cmd.rate = RATE_1M_PLCP;
band = IEEE80211_BAND_2GHZ;
break;
case IEEE80211_BAND_5GHZ:
scan->tx_cmd.rate = RATE_6M_PLCP;
band = IEEE80211_BAND_5GHZ;
break;
default:
IL_WARN("Invalid scan band\n");
return -EIO;
}
scan->good_CRC_th =
is_active ? IL_GOOD_CRC_TH_DEFAULT : IL_GOOD_CRC_TH_NEVER;
len =
il_fill_probe_req(il, (struct ieee80211_mgmt *)scan->data,
vif->addr, il->scan_request->ie,
il->scan_request->ie_len,
IL_MAX_SCAN_SIZE - sizeof(*scan));
scan->tx_cmd.len = cpu_to_le16(len);
scan->flags |= il3945_get_antenna_flags(il);
scan->channel_count =
il3945_get_channels_for_scan(il, band, is_active, n_probes,
(void *)&scan->data[len], vif);
if (scan->channel_count == 0) {
D_SCAN("channel count %d\n", scan->channel_count);
return -EIO;
}
cmd.len +=
le16_to_cpu(scan->tx_cmd.len) +
scan->channel_count * sizeof(struct il3945_scan_channel);
cmd.data = scan;
scan->len = cpu_to_le16(cmd.len);
set_bit(S_SCAN_HW, &il->status);
ret = il_send_cmd_sync(il, &cmd);
if (ret)
clear_bit(S_SCAN_HW, &il->status);
return ret;
}
void
il3945_post_scan(struct il_priv *il)
{
if (memcmp(&il->staging, &il->active, sizeof(il->staging)))
il3945_commit_rxon(il);
}
static void
il3945_bg_restart(struct work_struct *data)
{
struct il_priv *il = container_of(data, struct il_priv, restart);
if (test_bit(S_EXIT_PENDING, &il->status))
return;
if (test_and_clear_bit(S_FW_ERROR, &il->status)) {
mutex_lock(&il->mutex);
il->is_open = 0;
mutex_unlock(&il->mutex);
il3945_down(il);
ieee80211_restart_hw(il->hw);
} else {
il3945_down(il);
mutex_lock(&il->mutex);
if (test_bit(S_EXIT_PENDING, &il->status)) {
mutex_unlock(&il->mutex);
return;
}
__il3945_up(il);
mutex_unlock(&il->mutex);
}
}
static void
il3945_bg_rx_replenish(struct work_struct *data)
{
struct il_priv *il = container_of(data, struct il_priv, rx_replenish);
mutex_lock(&il->mutex);
if (test_bit(S_EXIT_PENDING, &il->status))
goto out;
il3945_rx_replenish(il);
out:
mutex_unlock(&il->mutex);
}
void
il3945_post_associate(struct il_priv *il)
{
int rc = 0;
struct ieee80211_conf *conf = NULL;
if (!il->vif || !il->is_open)
return;
D_ASSOC("Associated as %d to: %pM\n", il->vif->bss_conf.aid,
il->active.bssid_addr);
if (test_bit(S_EXIT_PENDING, &il->status))
return;
il_scan_cancel_timeout(il, 200);
conf = &il->hw->conf;
il->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
il3945_commit_rxon(il);
rc = il_send_rxon_timing(il);
if (rc)
IL_WARN("C_RXON_TIMING failed - " "Attempting to continue.\n");
il->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
il->staging.assoc_id = cpu_to_le16(il->vif->bss_conf.aid);
D_ASSOC("assoc id %d beacon interval %d\n", il->vif->bss_conf.aid,
il->vif->bss_conf.beacon_int);
if (il->vif->bss_conf.use_short_preamble)
il->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
else
il->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
if (il->staging.flags & RXON_FLG_BAND_24G_MSK) {
if (il->vif->bss_conf.use_short_slot)
il->staging.flags |= RXON_FLG_SHORT_SLOT_MSK;
else
il->staging.flags &= ~RXON_FLG_SHORT_SLOT_MSK;
}
il3945_commit_rxon(il);
switch (il->vif->type) {
case NL80211_IFTYPE_STATION:
il3945_rate_scale_init(il->hw, IL_AP_ID);
break;
case NL80211_IFTYPE_ADHOC:
il3945_send_beacon_cmd(il);
break;
default:
IL_ERR("%s Should not be called in %d mode\n", __func__,
il->vif->type);
break;
}
}
static int
il3945_mac_start(struct ieee80211_hw *hw)
{
struct il_priv *il = hw->priv;
int ret;
mutex_lock(&il->mutex);
D_MAC80211("enter\n");
if (!il->ucode_code.len) {
ret = il3945_read_ucode(il);
if (ret) {
IL_ERR("Could not read microcode: %d\n", ret);
mutex_unlock(&il->mutex);
goto out_release_irq;
}
}
ret = __il3945_up(il);
mutex_unlock(&il->mutex);
if (ret)
goto out_release_irq;
D_INFO("Start UP work.\n");
ret = wait_event_timeout(il->wait_command_queue,
test_bit(S_READY, &il->status),
UCODE_READY_TIMEOUT);
if (!ret) {
if (!test_bit(S_READY, &il->status)) {
IL_ERR("Wait for START_ALIVE timeout after %dms.\n",
jiffies_to_msecs(UCODE_READY_TIMEOUT));
ret = -ETIMEDOUT;
goto out_release_irq;
}
}
cancel_delayed_work(&il->_3945.rfkill_poll);
il->is_open = 1;
D_MAC80211("leave\n");
return 0;
out_release_irq:
il->is_open = 0;
D_MAC80211("leave - failed\n");
return ret;
}
static void
il3945_mac_stop(struct ieee80211_hw *hw)
{
struct il_priv *il = hw->priv;
D_MAC80211("enter\n");
if (!il->is_open) {
D_MAC80211("leave - skip\n");
return;
}
il->is_open = 0;
il3945_down(il);
flush_workqueue(il->workqueue);
queue_delayed_work(il->workqueue, &il->_3945.rfkill_poll,
round_jiffies_relative(2 * HZ));
D_MAC80211("leave\n");
}
static void
il3945_mac_tx(struct ieee80211_hw *hw,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct il_priv *il = hw->priv;
D_MAC80211("enter\n");
D_TX("dev->xmit(%d bytes) at rate 0x%02x\n", skb->len,
ieee80211_get_tx_rate(hw, IEEE80211_SKB_CB(skb))->bitrate);
if (il3945_tx_skb(il, control->sta, skb))
dev_kfree_skb_any(skb);
D_MAC80211("leave\n");
}
void
il3945_config_ap(struct il_priv *il)
{
struct ieee80211_vif *vif = il->vif;
int rc = 0;
if (test_bit(S_EXIT_PENDING, &il->status))
return;
if (!(il_is_associated(il))) {
il->staging.filter_flags &= ~RXON_FILTER_ASSOC_MSK;
il3945_commit_rxon(il);
rc = il_send_rxon_timing(il);
if (rc)
IL_WARN("C_RXON_TIMING failed - "
"Attempting to continue.\n");
il->staging.assoc_id = 0;
if (vif->bss_conf.use_short_preamble)
il->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
else
il->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
if (il->staging.flags & RXON_FLG_BAND_24G_MSK) {
if (vif->bss_conf.use_short_slot)
il->staging.flags |= RXON_FLG_SHORT_SLOT_MSK;
else
il->staging.flags &= ~RXON_FLG_SHORT_SLOT_MSK;
}
il->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
il3945_commit_rxon(il);
}
il3945_send_beacon_cmd(il);
}
static int
il3945_mac_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif, struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct il_priv *il = hw->priv;
int ret = 0;
u8 sta_id = IL_INVALID_STATION;
u8 static_key;
D_MAC80211("enter\n");
if (il3945_mod_params.sw_crypto) {
D_MAC80211("leave - hwcrypto disabled\n");
return -EOPNOTSUPP;
}
if (vif->type == NL80211_IFTYPE_ADHOC &&
!(key->flags & IEEE80211_KEY_FLAG_PAIRWISE)) {
D_MAC80211("leave - IBSS RSN\n");
return -EOPNOTSUPP;
}
static_key = !il_is_associated(il);
if (!static_key) {
sta_id = il_sta_id_or_broadcast(il, sta);
if (sta_id == IL_INVALID_STATION) {
D_MAC80211("leave - station not found\n");
return -EINVAL;
}
}
mutex_lock(&il->mutex);
il_scan_cancel_timeout(il, 100);
switch (cmd) {
case SET_KEY:
if (static_key)
ret = il3945_set_static_key(il, key);
else
ret = il3945_set_dynamic_key(il, key, sta_id);
D_MAC80211("enable hwcrypto key\n");
break;
case DISABLE_KEY:
if (static_key)
ret = il3945_remove_static_key(il);
else
ret = il3945_clear_sta_key_info(il, sta_id);
D_MAC80211("disable hwcrypto key\n");
break;
default:
ret = -EINVAL;
}
D_MAC80211("leave ret %d\n", ret);
mutex_unlock(&il->mutex);
return ret;
}
static int
il3945_mac_sta_add(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct il_priv *il = hw->priv;
struct il3945_sta_priv *sta_priv = (void *)sta->drv_priv;
int ret;
bool is_ap = vif->type == NL80211_IFTYPE_STATION;
u8 sta_id;
mutex_lock(&il->mutex);
D_INFO("station %pM\n", sta->addr);
sta_priv->common.sta_id = IL_INVALID_STATION;
ret = il_add_station_common(il, sta->addr, is_ap, sta, &sta_id);
if (ret) {
IL_ERR("Unable to add station %pM (%d)\n", sta->addr, ret);
mutex_unlock(&il->mutex);
return ret;
}
sta_priv->common.sta_id = sta_id;
D_INFO("Initializing rate scaling for station %pM\n", sta->addr);
il3945_rs_rate_init(il, sta, sta_id);
mutex_unlock(&il->mutex);
return 0;
}
static void
il3945_configure_filter(struct ieee80211_hw *hw, unsigned int changed_flags,
unsigned int *total_flags, u64 multicast)
{
struct il_priv *il = hw->priv;
__le32 filter_or = 0, filter_nand = 0;
#define CHK(test, flag) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
D_MAC80211("Enter: changed: 0x%x, total: 0x%x\n", changed_flags,
*total_flags);
CHK(FIF_OTHER_BSS | FIF_PROMISC_IN_BSS, RXON_FILTER_PROMISC_MSK);
CHK(FIF_CONTROL, RXON_FILTER_CTL2HOST_MSK);
CHK(FIF_BCN_PRBRESP_PROMISC, RXON_FILTER_BCON_AWARE_MSK);
#undef CHK
mutex_lock(&il->mutex);
il->staging.filter_flags &= ~filter_nand;
il->staging.filter_flags |= filter_or;
mutex_unlock(&il->mutex);
*total_flags &=
FIF_OTHER_BSS | FIF_ALLMULTI | FIF_PROMISC_IN_BSS |
FIF_BCN_PRBRESP_PROMISC | FIF_CONTROL;
}
static ssize_t
il3945_show_debug_level(struct device *d, struct device_attribute *attr,
char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
return sprintf(buf, "0x%08X\n", il_get_debug_level(il));
}
static ssize_t
il3945_store_debug_level(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
unsigned long val;
int ret;
ret = strict_strtoul(buf, 0, &val);
if (ret)
IL_INFO("%s is not in hex or decimal form.\n", buf);
else
il->debug_level = val;
return strnlen(buf, count);
}
static ssize_t
il3945_show_temperature(struct device *d, struct device_attribute *attr,
char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
if (!il_is_alive(il))
return -EAGAIN;
return sprintf(buf, "%d\n", il3945_hw_get_temperature(il));
}
static ssize_t
il3945_show_tx_power(struct device *d, struct device_attribute *attr, char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
return sprintf(buf, "%d\n", il->tx_power_user_lmt);
}
static ssize_t
il3945_store_tx_power(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
char *p = (char *)buf;
u32 val;
val = simple_strtoul(p, &p, 10);
if (p == buf)
IL_INFO(": %s is not in decimal form.\n", buf);
else
il3945_hw_reg_set_txpower(il, val);
return count;
}
static ssize_t
il3945_show_flags(struct device *d, struct device_attribute *attr, char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
return sprintf(buf, "0x%04X\n", il->active.flags);
}
static ssize_t
il3945_store_flags(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
u32 flags = simple_strtoul(buf, NULL, 0);
mutex_lock(&il->mutex);
if (le32_to_cpu(il->staging.flags) != flags) {
if (il_scan_cancel_timeout(il, 100))
IL_WARN("Could not cancel scan.\n");
else {
D_INFO("Committing rxon.flags = 0x%04X\n", flags);
il->staging.flags = cpu_to_le32(flags);
il3945_commit_rxon(il);
}
}
mutex_unlock(&il->mutex);
return count;
}
static ssize_t
il3945_show_filter_flags(struct device *d, struct device_attribute *attr,
char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
return sprintf(buf, "0x%04X\n", le32_to_cpu(il->active.filter_flags));
}
static ssize_t
il3945_store_filter_flags(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
u32 filter_flags = simple_strtoul(buf, NULL, 0);
mutex_lock(&il->mutex);
if (le32_to_cpu(il->staging.filter_flags) != filter_flags) {
if (il_scan_cancel_timeout(il, 100))
IL_WARN("Could not cancel scan.\n");
else {
D_INFO("Committing rxon.filter_flags = " "0x%04X\n",
filter_flags);
il->staging.filter_flags = cpu_to_le32(filter_flags);
il3945_commit_rxon(il);
}
}
mutex_unlock(&il->mutex);
return count;
}
static ssize_t
il3945_show_measurement(struct device *d, struct device_attribute *attr,
char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
struct il_spectrum_notification measure_report;
u32 size = sizeof(measure_report), len = 0, ofs = 0;
u8 *data = (u8 *) &measure_report;
unsigned long flags;
spin_lock_irqsave(&il->lock, flags);
if (!(il->measurement_status & MEASUREMENT_READY)) {
spin_unlock_irqrestore(&il->lock, flags);
return 0;
}
memcpy(&measure_report, &il->measure_report, size);
il->measurement_status = 0;
spin_unlock_irqrestore(&il->lock, flags);
while (size && PAGE_SIZE - len) {
hex_dump_to_buffer(data + ofs, size, 16, 1, buf + len,
PAGE_SIZE - len, 1);
len = strlen(buf);
if (PAGE_SIZE - len)
buf[len++] = '\n';
ofs += 16;
size -= min(size, 16U);
}
return len;
}
static ssize_t
il3945_store_measurement(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
struct ieee80211_measurement_params params = {
.channel = le16_to_cpu(il->active.channel),
.start_time = cpu_to_le64(il->_3945.last_tsf),
.duration = cpu_to_le16(1),
};
u8 type = IL_MEASURE_BASIC;
u8 buffer[32];
u8 channel;
if (count) {
char *p = buffer;
strncpy(buffer, buf, min(sizeof(buffer), count));
channel = simple_strtoul(p, NULL, 0);
if (channel)
params.channel = channel;
p = buffer;
while (*p && *p != ' ')
p++;
if (*p)
type = simple_strtoul(p + 1, NULL, 0);
}
D_INFO("Invoking measurement of type %d on " "channel %d (for '%s')\n",
type, params.channel, buf);
il3945_get_measurement(il, &params, type);
return count;
}
static ssize_t
il3945_store_retry_rate(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
il->retry_rate = simple_strtoul(buf, NULL, 0);
if (il->retry_rate <= 0)
il->retry_rate = 1;
return count;
}
static ssize_t
il3945_show_retry_rate(struct device *d, struct device_attribute *attr,
char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
return sprintf(buf, "%d", il->retry_rate);
}
static ssize_t
il3945_show_channels(struct device *d, struct device_attribute *attr, char *buf)
{
return 0;
}
static ssize_t
il3945_show_antenna(struct device *d, struct device_attribute *attr, char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
if (!il_is_alive(il))
return -EAGAIN;
return sprintf(buf, "%d\n", il3945_mod_params.antenna);
}
static ssize_t
il3945_store_antenna(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il __maybe_unused = dev_get_drvdata(d);
int ant;
if (count == 0)
return 0;
if (sscanf(buf, "%1i", &ant) != 1) {
D_INFO("not in hex or decimal form.\n");
return count;
}
if (ant >= 0 && ant <= 2) {
D_INFO("Setting antenna select to %d.\n", ant);
il3945_mod_params.antenna = (enum il3945_antenna)ant;
} else
D_INFO("Bad antenna select value %d.\n", ant);
return count;
}
static ssize_t
il3945_show_status(struct device *d, struct device_attribute *attr, char *buf)
{
struct il_priv *il = dev_get_drvdata(d);
if (!il_is_alive(il))
return -EAGAIN;
return sprintf(buf, "0x%08x\n", (int)il->status);
}
static ssize_t
il3945_dump_error_log(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct il_priv *il = dev_get_drvdata(d);
char *p = (char *)buf;
if (p[0] == '1')
il3945_dump_nic_error_log(il);
return strnlen(buf, count);
}
static void
il3945_setup_deferred_work(struct il_priv *il)
{
il->workqueue = create_singlethread_workqueue(DRV_NAME);
init_waitqueue_head(&il->wait_command_queue);
INIT_WORK(&il->restart, il3945_bg_restart);
INIT_WORK(&il->rx_replenish, il3945_bg_rx_replenish);
INIT_DELAYED_WORK(&il->init_alive_start, il3945_bg_init_alive_start);
INIT_DELAYED_WORK(&il->alive_start, il3945_bg_alive_start);
INIT_DELAYED_WORK(&il->_3945.rfkill_poll, il3945_rfkill_poll);
il_setup_scan_deferred_work(il);
il3945_hw_setup_deferred_work(il);
init_timer(&il->watchdog);
il->watchdog.data = (unsigned long)il;
il->watchdog.function = il_bg_watchdog;
tasklet_init(&il->irq_tasklet,
(void (*)(unsigned long))il3945_irq_tasklet,
(unsigned long)il);
}
static void
il3945_cancel_deferred_work(struct il_priv *il)
{
il3945_hw_cancel_deferred_work(il);
cancel_delayed_work_sync(&il->init_alive_start);
cancel_delayed_work(&il->alive_start);
il_cancel_scan_deferred_work(il);
}
static int
il3945_init_drv(struct il_priv *il)
{
int ret;
struct il3945_eeprom *eeprom = (struct il3945_eeprom *)il->eeprom;
il->retry_rate = 1;
il->beacon_skb = NULL;
spin_lock_init(&il->sta_lock);
spin_lock_init(&il->hcmd_lock);
INIT_LIST_HEAD(&il->free_frames);
mutex_init(&il->mutex);
il->ieee_channels = NULL;
il->ieee_rates = NULL;
il->band = IEEE80211_BAND_2GHZ;
il->iw_mode = NL80211_IFTYPE_STATION;
il->missed_beacon_threshold = IL_MISSED_BEACON_THRESHOLD_DEF;
il->force_reset.reset_duration = IL_DELAY_NEXT_FORCE_FW_RELOAD;
if (eeprom->version < EEPROM_3945_EEPROM_VERSION) {
IL_WARN("Unsupported EEPROM version: 0x%04X\n",
eeprom->version);
ret = -EINVAL;
goto err;
}
ret = il_init_channel_map(il);
if (ret) {
IL_ERR("initializing regulatory failed: %d\n", ret);
goto err;
}
if (il3945_txpower_set_from_eeprom(il)) {
ret = -EIO;
goto err_free_channel_map;
}
ret = il_init_geos(il);
if (ret) {
IL_ERR("initializing geos failed: %d\n", ret);
goto err_free_channel_map;
}
il3945_init_hw_rates(il, il->ieee_rates);
return 0;
err_free_channel_map:
il_free_channel_map(il);
err:
return ret;
}
static int
il3945_setup_mac(struct il_priv *il)
{
int ret;
struct ieee80211_hw *hw = il->hw;
hw->rate_control_algorithm = "iwl-3945-rs";
hw->sta_data_size = sizeof(struct il3945_sta_priv);
hw->vif_data_size = sizeof(struct il_vif_priv);
hw->flags = IEEE80211_HW_SIGNAL_DBM | IEEE80211_HW_SPECTRUM_MGMT;
hw->wiphy->interface_modes =
BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_ADHOC);
hw->wiphy->flags |=
WIPHY_FLAG_CUSTOM_REGULATORY | WIPHY_FLAG_DISABLE_BEACON_HINTS |
WIPHY_FLAG_IBSS_RSN;
hw->wiphy->max_scan_ssids = PROBE_OPTION_MAX_3945;
hw->wiphy->max_scan_ie_len = IL3945_MAX_PROBE_REQUEST - 24 - 2;
hw->queues = 4;
if (il->bands[IEEE80211_BAND_2GHZ].n_channels)
il->hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&il->bands[IEEE80211_BAND_2GHZ];
if (il->bands[IEEE80211_BAND_5GHZ].n_channels)
il->hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&il->bands[IEEE80211_BAND_5GHZ];
il_leds_init(il);
ret = ieee80211_register_hw(il->hw);
if (ret) {
IL_ERR("Failed to register hw (error %d)\n", ret);
return ret;
}
il->mac80211_registered = 1;
return 0;
}
static int
il3945_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int err = 0;
struct il_priv *il;
struct ieee80211_hw *hw;
struct il_cfg *cfg = (struct il_cfg *)(ent->driver_data);
struct il3945_eeprom *eeprom;
unsigned long flags;
hw = ieee80211_alloc_hw(sizeof(struct il_priv), &il3945_mac_ops);
if (!hw) {
err = -ENOMEM;
goto out;
}
il = hw->priv;
il->hw = hw;
SET_IEEE80211_DEV(hw, &pdev->dev);
il->cmd_queue = IL39_CMD_QUEUE_NUM;
if (il3945_mod_params.disable_hw_scan) {
D_INFO("Disabling hw_scan\n");
il3945_mac_ops.hw_scan = NULL;
}
D_INFO("*** LOAD DRIVER ***\n");
il->cfg = cfg;
il->ops = &il3945_ops;
#ifdef CONFIG_IWLEGACY_DEBUGFS
il->debugfs_ops = &il3945_debugfs_ops;
#endif
il->pci_dev = pdev;
il->inta_mask = CSR_INI_SET_MASK;
pci_disable_link_state(pdev,
PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
PCIE_LINK_STATE_CLKPM);
if (pci_enable_device(pdev)) {
err = -ENODEV;
goto out_ieee80211_free_hw;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (!err)
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
IL_WARN("No suitable DMA available.\n");
goto out_pci_disable_device;
}
pci_set_drvdata(pdev, il);
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto out_pci_disable_device;
il->hw_base = pci_ioremap_bar(pdev, 0);
if (!il->hw_base) {
err = -ENODEV;
goto out_pci_release_regions;
}
D_INFO("pci_resource_len = 0x%08llx\n",
(unsigned long long)pci_resource_len(pdev, 0));
D_INFO("pci_resource_base = %p\n", il->hw_base);
pci_write_config_byte(pdev, 0x41, 0x00);
spin_lock_init(&il->reg_lock);
spin_lock_init(&il->lock);
_il_wr(il, CSR_RESET, CSR_RESET_REG_FLAG_NEVO_RESET);
err = il_eeprom_init(il);
if (err) {
IL_ERR("Unable to init EEPROM\n");
goto out_iounmap;
}
eeprom = (struct il3945_eeprom *)il->eeprom;
D_INFO("MAC address: %pM\n", eeprom->mac_address);
SET_IEEE80211_PERM_ADDR(il->hw, eeprom->mac_address);
if (il3945_hw_set_hw_params(il)) {
IL_ERR("failed to set hw settings\n");
goto out_eeprom_free;
}
err = il3945_init_drv(il);
if (err) {
IL_ERR("initializing driver failed\n");
goto out_unset_hw_params;
}
IL_INFO("Detected Intel Wireless WiFi Link %s\n", il->cfg->name);
spin_lock_irqsave(&il->lock, flags);
il_disable_interrupts(il);
spin_unlock_irqrestore(&il->lock, flags);
pci_enable_msi(il->pci_dev);
err = request_irq(il->pci_dev->irq, il_isr, IRQF_SHARED, DRV_NAME, il);
if (err) {
IL_ERR("Error allocating IRQ %d\n", il->pci_dev->irq);
goto out_disable_msi;
}
err = sysfs_create_group(&pdev->dev.kobj, &il3945_attribute_group);
if (err) {
IL_ERR("failed to create sysfs device attributes\n");
goto out_release_irq;
}
il_set_rxon_channel(il, &il->bands[IEEE80211_BAND_2GHZ].channels[5]);
il3945_setup_deferred_work(il);
il3945_setup_handlers(il);
il_power_initialize(il);
il_enable_interrupts(il);
err = il3945_setup_mac(il);
if (err)
goto out_remove_sysfs;
err = il_dbgfs_register(il, DRV_NAME);
if (err)
IL_ERR("failed to create debugfs files. Ignoring error: %d\n",
err);
queue_delayed_work(il->workqueue, &il->_3945.rfkill_poll, 2 * HZ);
return 0;
out_remove_sysfs:
destroy_workqueue(il->workqueue);
il->workqueue = NULL;
sysfs_remove_group(&pdev->dev.kobj, &il3945_attribute_group);
out_release_irq:
free_irq(il->pci_dev->irq, il);
out_disable_msi:
pci_disable_msi(il->pci_dev);
il_free_geos(il);
il_free_channel_map(il);
out_unset_hw_params:
il3945_unset_hw_params(il);
out_eeprom_free:
il_eeprom_free(il);
out_iounmap:
iounmap(il->hw_base);
out_pci_release_regions:
pci_release_regions(pdev);
out_pci_disable_device:
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
out_ieee80211_free_hw:
ieee80211_free_hw(il->hw);
out:
return err;
}
static void __devexit
il3945_pci_remove(struct pci_dev *pdev)
{
struct il_priv *il = pci_get_drvdata(pdev);
unsigned long flags;
if (!il)
return;
D_INFO("*** UNLOAD DRIVER ***\n");
il_dbgfs_unregister(il);
set_bit(S_EXIT_PENDING, &il->status);
il_leds_exit(il);
if (il->mac80211_registered) {
ieee80211_unregister_hw(il->hw);
il->mac80211_registered = 0;
} else {
il3945_down(il);
}
il_apm_stop(il);
spin_lock_irqsave(&il->lock, flags);
il_disable_interrupts(il);
spin_unlock_irqrestore(&il->lock, flags);
il3945_synchronize_irq(il);
sysfs_remove_group(&pdev->dev.kobj, &il3945_attribute_group);
cancel_delayed_work_sync(&il->_3945.rfkill_poll);
il3945_dealloc_ucode_pci(il);
if (il->rxq.bd)
il3945_rx_queue_free(il, &il->rxq);
il3945_hw_txq_ctx_free(il);
il3945_unset_hw_params(il);
flush_workqueue(il->workqueue);
destroy_workqueue(il->workqueue);
il->workqueue = NULL;
free_irq(pdev->irq, il);
pci_disable_msi(pdev);
iounmap(il->hw_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
il_free_channel_map(il);
il_free_geos(il);
kfree(il->scan_cmd);
if (il->beacon_skb)
dev_kfree_skb(il->beacon_skb);
ieee80211_free_hw(il->hw);
}
static int __init
il3945_init(void)
{
int ret;
pr_info(DRV_DESCRIPTION ", " DRV_VERSION "\n");
pr_info(DRV_COPYRIGHT "\n");
ret = il3945_rate_control_register();
if (ret) {
pr_err("Unable to register rate control algorithm: %d\n", ret);
return ret;
}
ret = pci_register_driver(&il3945_driver);
if (ret) {
pr_err("Unable to initialize PCI module\n");
goto error_register;
}
return ret;
error_register:
il3945_rate_control_unregister();
return ret;
}
static void __exit
il3945_exit(void)
{
pci_unregister_driver(&il3945_driver);
il3945_rate_control_unregister();
}
