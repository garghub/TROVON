static ssize_t read_file_tgt_int_stats(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
struct ath9k_htc_target_int_stats cmd_rsp;
char buf[512];
unsigned int len = 0;
int ret = 0;
memset(&cmd_rsp, 0, sizeof(cmd_rsp));
ath9k_htc_ps_wakeup(priv);
WMI_CMD(WMI_INT_STATS_CMDID);
if (ret) {
ath9k_htc_ps_restore(priv);
return -EINVAL;
}
ath9k_htc_ps_restore(priv);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "RX",
be32_to_cpu(cmd_rsp.rx));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "RXORN",
be32_to_cpu(cmd_rsp.rxorn));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "RXEOL",
be32_to_cpu(cmd_rsp.rxeol));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "TXURN",
be32_to_cpu(cmd_rsp.txurn));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "TXTO",
be32_to_cpu(cmd_rsp.txto));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "CST",
be32_to_cpu(cmd_rsp.cst));
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t read_file_tgt_tx_stats(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
struct ath9k_htc_target_tx_stats cmd_rsp;
char buf[512];
unsigned int len = 0;
int ret = 0;
memset(&cmd_rsp, 0, sizeof(cmd_rsp));
ath9k_htc_ps_wakeup(priv);
WMI_CMD(WMI_TX_STATS_CMDID);
if (ret) {
ath9k_htc_ps_restore(priv);
return -EINVAL;
}
ath9k_htc_ps_restore(priv);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "Xretries",
be32_to_cpu(cmd_rsp.xretries));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "FifoErr",
be32_to_cpu(cmd_rsp.fifoerr));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "Filtered",
be32_to_cpu(cmd_rsp.filtered));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "TimerExp",
be32_to_cpu(cmd_rsp.timer_exp));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "ShortRetries",
be32_to_cpu(cmd_rsp.shortretries));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "LongRetries",
be32_to_cpu(cmd_rsp.longretries));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "QueueNull",
be32_to_cpu(cmd_rsp.qnull));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "EncapFail",
be32_to_cpu(cmd_rsp.encap_fail));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "NoBuf",
be32_to_cpu(cmd_rsp.nobuf));
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t read_file_tgt_rx_stats(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
struct ath9k_htc_target_rx_stats cmd_rsp;
char buf[512];
unsigned int len = 0;
int ret = 0;
memset(&cmd_rsp, 0, sizeof(cmd_rsp));
ath9k_htc_ps_wakeup(priv);
WMI_CMD(WMI_RX_STATS_CMDID);
if (ret) {
ath9k_htc_ps_restore(priv);
return -EINVAL;
}
ath9k_htc_ps_restore(priv);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "NoBuf",
be32_to_cpu(cmd_rsp.nobuf));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "HostSend",
be32_to_cpu(cmd_rsp.host_send));
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "HostDone",
be32_to_cpu(cmd_rsp.host_done));
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t read_file_xmit(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
char buf[512];
unsigned int len = 0;
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "Buffers queued",
priv->debug.tx_stats.buf_queued);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "Buffers completed",
priv->debug.tx_stats.buf_completed);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "SKBs queued",
priv->debug.tx_stats.skb_queued);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "SKBs success",
priv->debug.tx_stats.skb_success);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "SKBs failed",
priv->debug.tx_stats.skb_failed);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "CAB queued",
priv->debug.tx_stats.cab_queued);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "BE queued",
priv->debug.tx_stats.queue_stats[IEEE80211_AC_BE]);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "BK queued",
priv->debug.tx_stats.queue_stats[IEEE80211_AC_BK]);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "VI queued",
priv->debug.tx_stats.queue_stats[IEEE80211_AC_VI]);
len += scnprintf(buf + len, sizeof(buf) - len,
"%20s : %10u\n", "VO queued",
priv->debug.tx_stats.queue_stats[IEEE80211_AC_VO]);
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
void ath9k_htc_err_stat_rx(struct ath9k_htc_priv *priv,
struct ath_rx_status *rs)
{
ath9k_cmn_debug_stat_rx(&priv->debug.rx_stats, rs);
}
static ssize_t read_file_skb_rx(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
char *buf;
unsigned int len = 0, size = 1500;
ssize_t retval = 0;
buf = kzalloc(size, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
len += scnprintf(buf + len, size - len,
"%20s : %10u\n", "SKBs allocated",
priv->debug.skbrx_stats.skb_allocated);
len += scnprintf(buf + len, size - len,
"%20s : %10u\n", "SKBs completed",
priv->debug.skbrx_stats.skb_completed);
len += scnprintf(buf + len, size - len,
"%20s : %10u\n", "SKBs Dropped",
priv->debug.skbrx_stats.skb_dropped);
if (len > size)
len = size;
retval = simple_read_from_buffer(user_buf, count, ppos, buf, len);
kfree(buf);
return retval;
}
static ssize_t read_file_slot(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
char buf[512];
unsigned int len = 0;
spin_lock_bh(&priv->tx.tx_lock);
len += scnprintf(buf + len, sizeof(buf) - len, "TX slot bitmap : ");
len += bitmap_scnprintf(buf + len, sizeof(buf) - len,
priv->tx.tx_slot, MAX_TX_BUF_NUM);
len += scnprintf(buf + len, sizeof(buf) - len, "\n");
len += scnprintf(buf + len, sizeof(buf) - len,
"Used slots : %d\n",
bitmap_weight(priv->tx.tx_slot, MAX_TX_BUF_NUM));
spin_unlock_bh(&priv->tx.tx_lock);
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t read_file_queue(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
char buf[512];
unsigned int len = 0;
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Mgmt endpoint", skb_queue_len(&priv->tx.mgmt_ep_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Cab endpoint", skb_queue_len(&priv->tx.cab_ep_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Data BE endpoint", skb_queue_len(&priv->tx.data_be_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Data BK endpoint", skb_queue_len(&priv->tx.data_bk_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Data VI endpoint", skb_queue_len(&priv->tx.data_vi_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Data VO endpoint", skb_queue_len(&priv->tx.data_vo_queue));
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Failed queue", skb_queue_len(&priv->tx.tx_failed));
spin_lock_bh(&priv->tx.tx_lock);
len += scnprintf(buf + len, sizeof(buf) - len, "%20s : %10u\n",
"Queued count", priv->tx.queued_cnt);
spin_unlock_bh(&priv->tx.tx_lock);
if (len > sizeof(buf))
len = sizeof(buf);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t read_file_debug(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
struct ath_common *common = ath9k_hw_common(priv->ah);
char buf[32];
unsigned int len;
len = sprintf(buf, "0x%08x\n", common->debug_mask);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t write_file_debug(struct file *file, const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath9k_htc_priv *priv = file->private_data;
struct ath_common *common = ath9k_hw_common(priv->ah);
unsigned long mask;
char buf[32];
ssize_t len;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoul(buf, 0, &mask))
return -EINVAL;
common->debug_mask = mask;
return count;
}
void ath9k_htc_get_et_strings(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
u32 sset, u8 *data)
{
if (sset == ETH_SS_STATS)
memcpy(data, *ath9k_htc_gstrings_stats,
sizeof(ath9k_htc_gstrings_stats));
}
int ath9k_htc_get_et_sset_count(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, int sset)
{
if (sset == ETH_SS_STATS)
return ATH9K_HTC_SSTATS_LEN;
return 0;
}
void ath9k_htc_get_et_stats(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ethtool_stats *stats, u64 *data)
{
struct ath9k_htc_priv *priv = hw->priv;
int i = 0;
data[i++] = SKBTXBASE.skb_success;
data[i++] = SKBTXBASE.skb_success_bytes;
data[i++] = SKBRXBASE.skb_completed;
data[i++] = SKBRXBASE.skb_completed_bytes;
ASTXQ(queue_stats);
data[i++] = SRXBASE.crc_err;
data[i++] = SRXBASE.decrypt_crc_err;
data[i++] = SRXBASE.phy_err;
data[i++] = SRXBASE.mic_err;
data[i++] = SRXBASE.pre_delim_crc_err;
data[i++] = SRXBASE.post_delim_crc_err;
data[i++] = SRXBASE.decrypt_busy_err;
data[i++] = SRXBASE.phy_err_stats[ATH9K_PHYERR_RADAR];
data[i++] = SRXBASE.phy_err_stats[ATH9K_PHYERR_OFDM_TIMING];
data[i++] = SRXBASE.phy_err_stats[ATH9K_PHYERR_CCK_TIMING];
WARN_ON(i != ATH9K_HTC_SSTATS_LEN);
}
void ath9k_htc_deinit_debug(struct ath9k_htc_priv *priv)
{
ath9k_cmn_spectral_deinit_debug(&priv->spec_priv);
}
int ath9k_htc_init_debug(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_htc_priv *priv = (struct ath9k_htc_priv *) common->priv;
priv->debug.debugfs_phy = debugfs_create_dir(KBUILD_MODNAME,
priv->hw->wiphy->debugfsdir);
if (!priv->debug.debugfs_phy)
return -ENOMEM;
ath9k_cmn_spectral_init_debug(&priv->spec_priv, priv->debug.debugfs_phy);
debugfs_create_file("tgt_int_stats", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_tgt_int_stats);
debugfs_create_file("tgt_tx_stats", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_tgt_tx_stats);
debugfs_create_file("tgt_rx_stats", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_tgt_rx_stats);
debugfs_create_file("xmit", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_xmit);
debugfs_create_file("skb_rx", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_skb_rx);
ath9k_cmn_debug_recv(priv->debug.debugfs_phy, &priv->debug.rx_stats);
ath9k_cmn_debug_phy_err(priv->debug.debugfs_phy, &priv->debug.rx_stats);
debugfs_create_file("slot", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_slot);
debugfs_create_file("queue", S_IRUSR, priv->debug.debugfs_phy,
priv, &fops_queue);
debugfs_create_file("debug", S_IRUSR | S_IWUSR, priv->debug.debugfs_phy,
priv, &fops_debug);
ath9k_cmn_debug_base_eeprom(priv->debug.debugfs_phy, priv->ah);
ath9k_cmn_debug_modal_eeprom(priv->debug.debugfs_phy, priv->ah);
return 0;
}
