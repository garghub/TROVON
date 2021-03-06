static int ath9k_htc_wait_for_target(struct ath9k_htc_priv *priv)
{
int time_left;
if (atomic_read(&priv->htc->tgt_ready) > 0) {
atomic_dec(&priv->htc->tgt_ready);
return 0;
}
time_left = wait_for_completion_timeout(&priv->htc->target_wait, HZ);
if (!time_left) {
dev_err(priv->dev, "ath9k_htc: Target is unresponsive\n");
return -ETIMEDOUT;
}
atomic_dec(&priv->htc->tgt_ready);
return 0;
}
static void ath9k_deinit_priv(struct ath9k_htc_priv *priv)
{
ath9k_hw_deinit(priv->ah);
kfree(priv->ah);
priv->ah = NULL;
}
static void ath9k_deinit_device(struct ath9k_htc_priv *priv)
{
struct ieee80211_hw *hw = priv->hw;
wiphy_rfkill_stop_polling(hw->wiphy);
ath9k_deinit_leds(priv);
ieee80211_unregister_hw(hw);
ath9k_rx_cleanup(priv);
ath9k_tx_cleanup(priv);
ath9k_deinit_priv(priv);
}
static inline int ath9k_htc_connect_svc(struct ath9k_htc_priv *priv,
u16 service_id,
void (*tx) (void *,
struct sk_buff *,
enum htc_endpoint_id,
bool txok),
enum htc_endpoint_id *ep_id)
{
struct htc_service_connreq req;
memset(&req, 0, sizeof(struct htc_service_connreq));
req.service_id = service_id;
req.ep_callbacks.priv = priv;
req.ep_callbacks.rx = ath9k_htc_rxep;
req.ep_callbacks.tx = tx;
return htc_connect_service(priv->htc, &req, ep_id);
}
static int ath9k_init_htc_services(struct ath9k_htc_priv *priv, u16 devid,
u32 drv_info)
{
int ret;
ret = ath9k_wmi_connect(priv->htc, priv->wmi, &priv->wmi_cmd_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_BEACON_SVC, ath9k_htc_beaconep,
&priv->beacon_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_CAB_SVC, ath9k_htc_txep,
&priv->cab_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_UAPSD_SVC, ath9k_htc_txep,
&priv->uapsd_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_MGMT_SVC, ath9k_htc_txep,
&priv->mgmt_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_DATA_BE_SVC, ath9k_htc_txep,
&priv->data_be_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_DATA_BK_SVC, ath9k_htc_txep,
&priv->data_bk_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_DATA_VI_SVC, ath9k_htc_txep,
&priv->data_vi_ep);
if (ret)
goto err;
ret = ath9k_htc_connect_svc(priv, WMI_DATA_VO_SVC, ath9k_htc_txep,
&priv->data_vo_ep);
if (ret)
goto err;
if (IS_AR7010_DEVICE(drv_info))
priv->htc->credits = 45;
else
priv->htc->credits = 33;
ret = htc_init(priv->htc);
if (ret)
goto err;
dev_info(priv->dev, "ath9k_htc: HTC initialized with %d credits\n",
priv->htc->credits);
return 0;
err:
dev_err(priv->dev, "ath9k_htc: Unable to initialize HTC services\n");
return ret;
}
static int ath9k_reg_notifier(struct wiphy *wiphy,
struct regulatory_request *request)
{
struct ieee80211_hw *hw = wiphy_to_ieee80211_hw(wiphy);
struct ath9k_htc_priv *priv = hw->priv;
return ath_reg_notifier_apply(wiphy, request,
ath9k_hw_regulatory(priv->ah));
}
static unsigned int ath9k_regread(void *hw_priv, u32 reg_offset)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
__be32 val, reg = cpu_to_be32(reg_offset);
int r;
r = ath9k_wmi_cmd(priv->wmi, WMI_REG_READ_CMDID,
(u8 *) &reg, sizeof(reg),
(u8 *) &val, sizeof(val),
100);
if (unlikely(r)) {
ath_dbg(common, WMI, "REGISTER READ FAILED: (0x%04x, %d)\n",
reg_offset, r);
return -EIO;
}
return be32_to_cpu(val);
}
static void ath9k_multi_regread(void *hw_priv, u32 *addr,
u32 *val, u16 count)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
__be32 tmpaddr[8];
__be32 tmpval[8];
int i, ret;
for (i = 0; i < count; i++) {
tmpaddr[i] = cpu_to_be32(addr[i]);
}
ret = ath9k_wmi_cmd(priv->wmi, WMI_REG_READ_CMDID,
(u8 *)tmpaddr , sizeof(u32) * count,
(u8 *)tmpval, sizeof(u32) * count,
100);
if (unlikely(ret)) {
ath_dbg(common, WMI,
"Multiple REGISTER READ FAILED (count: %d)\n", count);
}
for (i = 0; i < count; i++) {
val[i] = be32_to_cpu(tmpval[i]);
}
}
static void ath9k_regwrite_single(void *hw_priv, u32 val, u32 reg_offset)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
const __be32 buf[2] = {
cpu_to_be32(reg_offset),
cpu_to_be32(val),
};
int r;
r = ath9k_wmi_cmd(priv->wmi, WMI_REG_WRITE_CMDID,
(u8 *) &buf, sizeof(buf),
(u8 *) &val, sizeof(val),
100);
if (unlikely(r)) {
ath_dbg(common, WMI, "REGISTER WRITE FAILED:(0x%04x, %d)\n",
reg_offset, r);
}
}
static void ath9k_regwrite_buffer(void *hw_priv, u32 val, u32 reg_offset)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
u32 rsp_status;
int r;
mutex_lock(&priv->wmi->multi_write_mutex);
priv->wmi->multi_write[priv->wmi->multi_write_idx].reg =
cpu_to_be32(reg_offset);
priv->wmi->multi_write[priv->wmi->multi_write_idx].val =
cpu_to_be32(val);
priv->wmi->multi_write_idx++;
if (priv->wmi->multi_write_idx == MAX_CMD_NUMBER) {
r = ath9k_wmi_cmd(priv->wmi, WMI_REG_WRITE_CMDID,
(u8 *) &priv->wmi->multi_write,
sizeof(struct register_write) * priv->wmi->multi_write_idx,
(u8 *) &rsp_status, sizeof(rsp_status),
100);
if (unlikely(r)) {
ath_dbg(common, WMI,
"REGISTER WRITE FAILED, multi len: %d\n",
priv->wmi->multi_write_idx);
}
priv->wmi->multi_write_idx = 0;
}
mutex_unlock(&priv->wmi->multi_write_mutex);
}
static void ath9k_regwrite(void *hw_priv, u32 val, u32 reg_offset)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
if (atomic_read(&priv->wmi->mwrite_cnt))
ath9k_regwrite_buffer(hw_priv, val, reg_offset);
else
ath9k_regwrite_single(hw_priv, val, reg_offset);
}
static void ath9k_enable_regwrite_buffer(void *hw_priv)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
atomic_inc(&priv->wmi->mwrite_cnt);
}
static void ath9k_regwrite_flush(void *hw_priv)
{
struct ath_hw *ah = (struct ath_hw *) hw_priv;
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
u32 rsp_status;
int r;
atomic_dec(&priv->wmi->mwrite_cnt);
mutex_lock(&priv->wmi->multi_write_mutex);
if (priv->wmi->multi_write_idx) {
r = ath9k_wmi_cmd(priv->wmi, WMI_REG_WRITE_CMDID,
(u8 *) &priv->wmi->multi_write,
sizeof(struct register_write) * priv->wmi->multi_write_idx,
(u8 *) &rsp_status, sizeof(rsp_status),
100);
if (unlikely(r)) {
ath_dbg(common, WMI,
"REGISTER WRITE FAILED, multi len: %d\n",
priv->wmi->multi_write_idx);
}
priv->wmi->multi_write_idx = 0;
}
mutex_unlock(&priv->wmi->multi_write_mutex);
}
static u32 ath9k_reg_rmw(void *hw_priv, u32 reg_offset, u32 set, u32 clr)
{
u32 val;
val = ath9k_regread(hw_priv, reg_offset);
val &= ~clr;
val |= set;
ath9k_regwrite(hw_priv, val, reg_offset);
return val;
}
static void ath_usb_read_cachesize(struct ath_common *common, int *csz)
{
*csz = L1_CACHE_BYTES >> 2;
}
static bool ath_usb_eeprom_read(struct ath_common *common, u32 off, u16 *data)
{
struct ath_hw *ah = (struct ath_hw *) common->ah;
(void)REG_READ(ah, AR5416_EEPROM_OFFSET + (off << AR5416_EEPROM_S));
if (!ath9k_hw_wait(ah,
AR_EEPROM_STATUS_DATA,
AR_EEPROM_STATUS_DATA_BUSY |
AR_EEPROM_STATUS_DATA_PROT_ACCESS, 0,
AH_WAIT_TIMEOUT))
return false;
*data = MS(REG_READ(ah, AR_EEPROM_STATUS_DATA),
AR_EEPROM_STATUS_DATA_VAL);
return true;
}
static void setup_ht_cap(struct ath9k_htc_priv *priv,
struct ieee80211_sta_ht_cap *ht_info)
{
struct ath_common *common = ath9k_hw_common(priv->ah);
u8 tx_streams, rx_streams;
int i;
ht_info->ht_supported = true;
ht_info->cap = IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
IEEE80211_HT_CAP_SM_PS |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_DSSSCCK40;
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_SGI_20)
ht_info->cap |= IEEE80211_HT_CAP_SGI_20;
ht_info->cap |= (1 << IEEE80211_HT_CAP_RX_STBC_SHIFT);
ht_info->ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
ht_info->ampdu_density = IEEE80211_HT_MPDU_DENSITY_8;
memset(&ht_info->mcs, 0, sizeof(ht_info->mcs));
tx_streams = ath9k_cmn_count_streams(priv->ah->txchainmask, 2);
rx_streams = ath9k_cmn_count_streams(priv->ah->rxchainmask, 2);
ath_dbg(common, CONFIG, "TX streams %d, RX streams: %d\n",
tx_streams, rx_streams);
if (tx_streams != rx_streams) {
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
ht_info->mcs.tx_params |= ((tx_streams - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
}
for (i = 0; i < rx_streams; i++)
ht_info->mcs.rx_mask[i] = 0xff;
ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_DEFINED;
}
static int ath9k_init_queues(struct ath9k_htc_priv *priv)
{
struct ath_common *common = ath9k_hw_common(priv->ah);
int i;
for (i = 0; i < ARRAY_SIZE(priv->hwq_map); i++)
priv->hwq_map[i] = -1;
priv->beaconq = ath9k_hw_beaconq_setup(priv->ah);
if (priv->beaconq == -1) {
ath_err(common, "Unable to setup BEACON xmit queue\n");
goto err;
}
priv->cabq = ath9k_htc_cabq_setup(priv);
if (priv->cabq == -1) {
ath_err(common, "Unable to setup CAB xmit queue\n");
goto err;
}
if (!ath9k_htc_txq_setup(priv, IEEE80211_AC_BE)) {
ath_err(common, "Unable to setup xmit queue for BE traffic\n");
goto err;
}
if (!ath9k_htc_txq_setup(priv, IEEE80211_AC_BK)) {
ath_err(common, "Unable to setup xmit queue for BK traffic\n");
goto err;
}
if (!ath9k_htc_txq_setup(priv, IEEE80211_AC_VI)) {
ath_err(common, "Unable to setup xmit queue for VI traffic\n");
goto err;
}
if (!ath9k_htc_txq_setup(priv, IEEE80211_AC_VO)) {
ath_err(common, "Unable to setup xmit queue for VO traffic\n");
goto err;
}
return 0;
err:
return -EINVAL;
}
static void ath9k_init_channels_rates(struct ath9k_htc_priv *priv)
{
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ) {
priv->sbands[IEEE80211_BAND_2GHZ].channels =
ath9k_2ghz_channels;
priv->sbands[IEEE80211_BAND_2GHZ].band = IEEE80211_BAND_2GHZ;
priv->sbands[IEEE80211_BAND_2GHZ].n_channels =
ARRAY_SIZE(ath9k_2ghz_channels);
priv->sbands[IEEE80211_BAND_2GHZ].bitrates = ath9k_legacy_rates;
priv->sbands[IEEE80211_BAND_2GHZ].n_bitrates =
ARRAY_SIZE(ath9k_legacy_rates);
}
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ) {
priv->sbands[IEEE80211_BAND_5GHZ].channels = ath9k_5ghz_channels;
priv->sbands[IEEE80211_BAND_5GHZ].band = IEEE80211_BAND_5GHZ;
priv->sbands[IEEE80211_BAND_5GHZ].n_channels =
ARRAY_SIZE(ath9k_5ghz_channels);
priv->sbands[IEEE80211_BAND_5GHZ].bitrates =
ath9k_legacy_rates + 4;
priv->sbands[IEEE80211_BAND_5GHZ].n_bitrates =
ARRAY_SIZE(ath9k_legacy_rates) - 4;
}
}
static void ath9k_init_misc(struct ath9k_htc_priv *priv)
{
struct ath_common *common = ath9k_hw_common(priv->ah);
memcpy(common->bssidmask, ath_bcast_mac, ETH_ALEN);
priv->ah->opmode = NL80211_IFTYPE_STATION;
}
static int ath9k_init_priv(struct ath9k_htc_priv *priv,
u16 devid, char *product,
u32 drv_info)
{
struct ath_hw *ah = NULL;
struct ath_common *common;
int i, ret = 0, csz = 0;
set_bit(OP_INVALID, &priv->op_flags);
ah = kzalloc(sizeof(struct ath_hw), GFP_KERNEL);
if (!ah)
return -ENOMEM;
ah->hw_version.devid = devid;
ah->hw_version.usbdev = drv_info;
ah->ah_flags |= AH_USE_EEPROM;
ah->reg_ops.read = ath9k_regread;
ah->reg_ops.multi_read = ath9k_multi_regread;
ah->reg_ops.write = ath9k_regwrite;
ah->reg_ops.enable_write_buffer = ath9k_enable_regwrite_buffer;
ah->reg_ops.write_flush = ath9k_regwrite_flush;
ah->reg_ops.rmw = ath9k_reg_rmw;
priv->ah = ah;
common = ath9k_hw_common(ah);
common->ops = &ah->reg_ops;
common->bus_ops = &ath9k_usb_bus_ops;
common->ah = ah;
common->hw = priv->hw;
common->priv = priv;
common->debug_mask = ath9k_debug;
common->btcoex_enabled = ath9k_htc_btcoex_enable == 1;
spin_lock_init(&priv->beacon_lock);
spin_lock_init(&priv->tx.tx_lock);
mutex_init(&priv->mutex);
mutex_init(&priv->htc_pm_lock);
tasklet_init(&priv->rx_tasklet, ath9k_rx_tasklet,
(unsigned long)priv);
tasklet_init(&priv->tx_failed_tasklet, ath9k_tx_failed_tasklet,
(unsigned long)priv);
INIT_DELAYED_WORK(&priv->ani_work, ath9k_htc_ani_work);
INIT_WORK(&priv->ps_work, ath9k_ps_work);
INIT_WORK(&priv->fatal_work, ath9k_fatal_work);
setup_timer(&priv->tx.cleanup_timer, ath9k_htc_tx_cleanup_timer,
(unsigned long)priv);
ath_read_cachesize(common, &csz);
common->cachelsz = csz << 2;
ret = ath9k_hw_init(ah);
if (ret) {
ath_err(common,
"Unable to initialize hardware; initialization status: %d\n",
ret);
goto err_hw;
}
ret = ath9k_init_queues(priv);
if (ret)
goto err_queues;
for (i = 0; i < ATH9K_HTC_MAX_BCN_VIF; i++)
priv->cur_beacon_conf.bslot[i] = NULL;
ath9k_cmn_init_crypto(ah);
ath9k_init_channels_rates(priv);
ath9k_init_misc(priv);
ath9k_htc_init_btcoex(priv, product);
return 0;
err_queues:
ath9k_hw_deinit(ah);
err_hw:
kfree(ah);
priv->ah = NULL;
return ret;
}
static void ath9k_set_hw_capab(struct ath9k_htc_priv *priv,
struct ieee80211_hw *hw)
{
struct ath_common *common = ath9k_hw_common(priv->ah);
hw->flags = IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_SPECTRUM_MGMT |
IEEE80211_HW_HAS_RATE_CONTROL |
IEEE80211_HW_RX_INCLUDES_FCS |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK |
IEEE80211_HW_REPORTS_TX_ACK_STATUS |
IEEE80211_HW_HOST_BROADCAST_PS_BUFFERING;
hw->wiphy->interface_modes =
BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_ADHOC) |
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_P2P_GO) |
BIT(NL80211_IFTYPE_P2P_CLIENT);
hw->wiphy->iface_combinations = &if_comb;
hw->wiphy->n_iface_combinations = 1;
hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
hw->wiphy->flags |= WIPHY_FLAG_IBSS_RSN |
WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL;
hw->queues = 4;
hw->channel_change_time = 5000;
hw->max_listen_interval = 1;
hw->vif_data_size = sizeof(struct ath9k_htc_vif);
hw->sta_data_size = sizeof(struct ath9k_htc_sta);
hw->extra_tx_headroom = sizeof(struct tx_frame_hdr) +
sizeof(struct htc_frame_hdr) + 4;
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ)
hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&priv->sbands[IEEE80211_BAND_2GHZ];
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ)
hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&priv->sbands[IEEE80211_BAND_5GHZ];
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_HT) {
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ)
setup_ht_cap(priv,
&priv->sbands[IEEE80211_BAND_2GHZ].ht_cap);
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ)
setup_ht_cap(priv,
&priv->sbands[IEEE80211_BAND_5GHZ].ht_cap);
}
SET_IEEE80211_PERM_ADDR(hw, common->macaddr);
}
static int ath9k_init_firmware_version(struct ath9k_htc_priv *priv)
{
struct ieee80211_hw *hw = priv->hw;
struct wmi_fw_version cmd_rsp;
int ret;
memset(&cmd_rsp, 0, sizeof(cmd_rsp));
WMI_CMD(WMI_GET_FW_VERSION);
if (ret)
return -EINVAL;
priv->fw_version_major = be16_to_cpu(cmd_rsp.major);
priv->fw_version_minor = be16_to_cpu(cmd_rsp.minor);
snprintf(hw->wiphy->fw_version, ETHTOOL_BUSINFO_LEN, "%d.%d",
priv->fw_version_major,
priv->fw_version_minor);
dev_info(priv->dev, "ath9k_htc: FW Version: %d.%d\n",
priv->fw_version_major,
priv->fw_version_minor);
if (priv->fw_version_major != MAJOR_VERSION_REQ ||
priv->fw_version_minor != MINOR_VERSION_REQ) {
dev_err(priv->dev, "ath9k_htc: Please upgrade to FW version %d.%d\n",
MAJOR_VERSION_REQ, MINOR_VERSION_REQ);
return -EINVAL;
}
return 0;
}
static int ath9k_init_device(struct ath9k_htc_priv *priv,
u16 devid, char *product, u32 drv_info)
{
struct ieee80211_hw *hw = priv->hw;
struct ath_common *common;
struct ath_hw *ah;
int error = 0;
struct ath_regulatory *reg;
char hw_name[64];
error = ath9k_init_priv(priv, devid, product, drv_info);
if (error != 0)
goto err_init;
ah = priv->ah;
common = ath9k_hw_common(ah);
ath9k_set_hw_capab(priv, hw);
error = ath9k_init_firmware_version(priv);
if (error != 0)
goto err_fw;
error = ath_regd_init(&common->regulatory, priv->hw->wiphy,
ath9k_reg_notifier);
if (error)
goto err_regd;
reg = &common->regulatory;
error = ath9k_tx_init(priv);
if (error != 0)
goto err_tx;
error = ath9k_rx_init(priv);
if (error != 0)
goto err_rx;
#ifdef CONFIG_MAC80211_LEDS
priv->led_cdev.default_trigger = ieee80211_create_tpt_led_trigger(priv->hw,
IEEE80211_TPT_LEDTRIG_FL_RADIO, ath9k_htc_tpt_blink,
ARRAY_SIZE(ath9k_htc_tpt_blink));
#endif
error = ieee80211_register_hw(hw);
if (error)
goto err_register;
if (!ath_is_world_regd(reg)) {
error = regulatory_hint(hw->wiphy, reg->alpha2);
if (error)
goto err_world;
}
error = ath9k_htc_init_debug(priv->ah);
if (error) {
ath_err(common, "Unable to create debugfs files\n");
goto err_world;
}
ath_dbg(common, CONFIG,
"WMI:%d, BCN:%d, CAB:%d, UAPSD:%d, MGMT:%d, BE:%d, BK:%d, VI:%d, VO:%d\n",
priv->wmi_cmd_ep,
priv->beacon_ep,
priv->cab_ep,
priv->uapsd_ep,
priv->mgmt_ep,
priv->data_be_ep,
priv->data_bk_ep,
priv->data_vi_ep,
priv->data_vo_ep);
ath9k_hw_name(priv->ah, hw_name, sizeof(hw_name));
wiphy_info(hw->wiphy, "%s\n", hw_name);
ath9k_init_leds(priv);
ath9k_start_rfkill_poll(priv);
return 0;
err_world:
ieee80211_unregister_hw(hw);
err_register:
ath9k_rx_cleanup(priv);
err_rx:
ath9k_tx_cleanup(priv);
err_tx:
err_regd:
err_fw:
ath9k_deinit_priv(priv);
err_init:
return error;
}
int ath9k_htc_probe_device(struct htc_target *htc_handle, struct device *dev,
u16 devid, char *product, u32 drv_info)
{
struct ieee80211_hw *hw;
struct ath9k_htc_priv *priv;
int ret;
hw = ieee80211_alloc_hw(sizeof(struct ath9k_htc_priv), &ath9k_htc_ops);
if (!hw)
return -ENOMEM;
priv = hw->priv;
priv->hw = hw;
priv->htc = htc_handle;
priv->dev = dev;
htc_handle->drv_priv = priv;
SET_IEEE80211_DEV(hw, priv->dev);
ret = ath9k_htc_wait_for_target(priv);
if (ret)
goto err_free;
priv->wmi = ath9k_init_wmi(priv);
if (!priv->wmi) {
ret = -EINVAL;
goto err_free;
}
ret = ath9k_init_htc_services(priv, devid, drv_info);
if (ret)
goto err_init;
ret = ath9k_init_device(priv, devid, product, drv_info);
if (ret)
goto err_init;
return 0;
err_init:
ath9k_deinit_wmi(priv);
err_free:
ieee80211_free_hw(hw);
return ret;
}
void ath9k_htc_disconnect_device(struct htc_target *htc_handle, bool hotunplug)
{
if (htc_handle->drv_priv) {
if (hotunplug)
htc_handle->drv_priv->ah->ah_flags |= AH_UNPLUGGED;
ath9k_deinit_device(htc_handle->drv_priv);
ath9k_deinit_wmi(htc_handle->drv_priv);
ieee80211_free_hw(htc_handle->drv_priv->hw);
}
}
void ath9k_htc_suspend(struct htc_target *htc_handle)
{
ath9k_htc_setpower(htc_handle->drv_priv, ATH9K_PM_FULL_SLEEP);
}
int ath9k_htc_resume(struct htc_target *htc_handle)
{
struct ath9k_htc_priv *priv = htc_handle->drv_priv;
int ret;
ret = ath9k_htc_wait_for_target(priv);
if (ret)
return ret;
ret = ath9k_init_htc_services(priv, priv->ah->hw_version.devid,
priv->ah->hw_version.usbdev);
return ret;
}
static int __init ath9k_htc_init(void)
{
if (ath9k_hif_usb_init() < 0) {
pr_err("No USB devices found, driver not installed\n");
return -ENODEV;
}
return 0;
}
static void __exit ath9k_htc_exit(void)
{
ath9k_hif_usb_exit();
pr_info("Driver unloaded\n");
}
