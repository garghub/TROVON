static int rsi_sdio_stats_read(struct seq_file *seq, void *data)
{
struct rsi_common *common = seq->private;
struct rsi_hw *adapter = common->priv;
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
seq_printf(seq, "total_sdio_interrupts: %d\n",
dev->rx_info.sdio_int_counter);
seq_printf(seq, "sdio_msdu_pending_intr_count: %d\n",
dev->rx_info.total_sdio_msdu_pending_intr);
seq_printf(seq, "sdio_buff_full_count : %d\n",
dev->rx_info.buf_full_counter);
seq_printf(seq, "sdio_buf_semi_full_count %d\n",
dev->rx_info.buf_semi_full_counter);
seq_printf(seq, "sdio_unknown_intr_count: %d\n",
dev->rx_info.total_sdio_unknown_intr);
seq_printf(seq, "BUFFER FULL STATUS : %d\n",
dev->rx_info.buffer_full);
seq_printf(seq, "SEMI BUFFER FULL STATUS : %d\n",
dev->rx_info.semi_buffer_full);
seq_printf(seq, "MGMT BUFFER FULL STATUS : %d\n",
dev->rx_info.mgmt_buffer_full);
seq_printf(seq, "BUFFER FULL COUNTER : %d\n",
dev->rx_info.buf_full_counter);
seq_printf(seq, "BUFFER SEMI FULL COUNTER : %d\n",
dev->rx_info.buf_semi_full_counter);
seq_printf(seq, "MGMT BUFFER FULL COUNTER : %d\n",
dev->rx_info.mgmt_buf_full_counter);
return 0;
}
static int rsi_sdio_stats_open(struct inode *inode,
struct file *file)
{
return single_open(file, rsi_sdio_stats_read, inode->i_private);
}
static int rsi_version_read(struct seq_file *seq, void *data)
{
struct rsi_common *common = seq->private;
common->driver_ver.major = 0;
common->driver_ver.minor = 1;
common->driver_ver.release_num = 0;
common->driver_ver.patch_num = 0;
seq_printf(seq, "Driver : %x.%d.%d.%d\nLMAC : %d.%d.%d.%d\n",
common->driver_ver.major,
common->driver_ver.minor,
common->driver_ver.release_num,
common->driver_ver.patch_num,
common->fw_ver.major,
common->fw_ver.minor,
common->fw_ver.release_num,
common->fw_ver.patch_num);
return 0;
}
static int rsi_version_open(struct inode *inode,
struct file *file)
{
return single_open(file, rsi_version_read, inode->i_private);
}
static int rsi_stats_read(struct seq_file *seq, void *data)
{
struct rsi_common *common = seq->private;
unsigned char fsm_state[][32] = {
"FSM_CARD_NOT_READY",
"FSM_BOOT_PARAMS_SENT",
"FSM_EEPROM_READ_MAC_ADDR",
"FSM_RESET_MAC_SENT",
"FSM_RADIO_CAPS_SENT",
"FSM_BB_RF_PROG_SENT",
"FSM_MAC_INIT_DONE"
};
seq_puts(seq, "==> RSI STA DRIVER STATUS <==\n");
seq_puts(seq, "DRIVER_FSM_STATE: ");
if (common->fsm_state <= FSM_MAC_INIT_DONE)
seq_printf(seq, "%s", fsm_state[common->fsm_state]);
seq_printf(seq, "(%d)\n\n", common->fsm_state);
seq_printf(seq, "total_mgmt_pkt_send : %d\n",
common->tx_stats.total_tx_pkt_send[MGMT_SOFT_Q]);
seq_printf(seq, "total_mgmt_pkt_queued : %d\n",
skb_queue_len(&common->tx_queue[4]));
seq_printf(seq, "total_mgmt_pkt_freed : %d\n",
common->tx_stats.total_tx_pkt_freed[MGMT_SOFT_Q]);
seq_printf(seq, "total_data_vo_pkt_send: %8d\t",
common->tx_stats.total_tx_pkt_send[VO_Q]);
seq_printf(seq, "total_data_vo_pkt_queued: %8d\t",
skb_queue_len(&common->tx_queue[0]));
seq_printf(seq, "total_vo_pkt_freed: %8d\n",
common->tx_stats.total_tx_pkt_freed[VO_Q]);
seq_printf(seq, "total_data_vi_pkt_send: %8d\t",
common->tx_stats.total_tx_pkt_send[VI_Q]);
seq_printf(seq, "total_data_vi_pkt_queued: %8d\t",
skb_queue_len(&common->tx_queue[1]));
seq_printf(seq, "total_vi_pkt_freed: %8d\n",
common->tx_stats.total_tx_pkt_freed[VI_Q]);
seq_printf(seq, "total_data_be_pkt_send: %8d\t",
common->tx_stats.total_tx_pkt_send[BE_Q]);
seq_printf(seq, "total_data_be_pkt_queued: %8d\t",
skb_queue_len(&common->tx_queue[2]));
seq_printf(seq, "total_be_pkt_freed: %8d\n",
common->tx_stats.total_tx_pkt_freed[BE_Q]);
seq_printf(seq, "total_data_bk_pkt_send: %8d\t",
common->tx_stats.total_tx_pkt_send[BK_Q]);
seq_printf(seq, "total_data_bk_pkt_queued: %8d\t",
skb_queue_len(&common->tx_queue[3]));
seq_printf(seq, "total_bk_pkt_freed: %8d\n",
common->tx_stats.total_tx_pkt_freed[BK_Q]);
seq_puts(seq, "\n");
return 0;
}
static int rsi_stats_open(struct inode *inode,
struct file *file)
{
return single_open(file, rsi_stats_read, inode->i_private);
}
static int rsi_debug_zone_read(struct seq_file *seq, void *data)
{
rsi_dbg(FSM_ZONE, "%x: rsi_enabled zone", rsi_zone_enabled);
seq_printf(seq, "The zones available are %#x\n",
rsi_zone_enabled);
return 0;
}
static int rsi_debug_read(struct inode *inode,
struct file *file)
{
return single_open(file, rsi_debug_zone_read, inode->i_private);
}
static ssize_t rsi_debug_zone_write(struct file *filp,
const char __user *buff,
size_t len,
loff_t *data)
{
unsigned long dbg_zone;
int ret;
if (!len)
return 0;
ret = kstrtoul_from_user(buff, len, 16, &dbg_zone);
if (ret)
return ret;
rsi_zone_enabled = dbg_zone;
return len;
}
int rsi_init_dbgfs(struct rsi_hw *adapter)
{
struct rsi_common *common = adapter->priv;
struct rsi_debugfs *dev_dbgfs;
char devdir[6];
int ii;
const struct rsi_dbg_files *files;
dev_dbgfs = kzalloc(sizeof(*dev_dbgfs), GFP_KERNEL);
if (!dev_dbgfs)
return -ENOMEM;
adapter->dfsentry = dev_dbgfs;
snprintf(devdir, sizeof(devdir), "%s",
wiphy_name(adapter->hw->wiphy));
dev_dbgfs->subdir = debugfs_create_dir(devdir, NULL);
if (!dev_dbgfs->subdir) {
kfree(dev_dbgfs);
return -ENOMEM;
}
for (ii = 0; ii < adapter->num_debugfs_entries; ii++) {
files = &dev_debugfs_files[ii];
dev_dbgfs->rsi_files[ii] =
debugfs_create_file(files->name,
files->perms,
dev_dbgfs->subdir,
common,
&files->fops);
}
return 0;
}
void rsi_remove_dbgfs(struct rsi_hw *adapter)
{
struct rsi_debugfs *dev_dbgfs = adapter->dfsentry;
if (!dev_dbgfs)
return;
debugfs_remove_recursive(dev_dbgfs->subdir);
}
