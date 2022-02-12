static void wl1251_debugfs_update_stats(struct wl1251 *wl)
{
int ret;
mutex_lock(&wl->mutex);
ret = wl1251_ps_elp_wakeup(wl);
if (ret < 0)
goto out;
if (wl->state == WL1251_STATE_ON &&
time_after(jiffies, wl->stats.fw_stats_update +
msecs_to_jiffies(WL1251_DEBUGFS_STATS_LIFETIME))) {
wl1251_acx_statistics(wl, wl->stats.fw_stats);
wl->stats.fw_stats_update = jiffies;
}
wl1251_ps_elp_sleep(wl);
out:
mutex_unlock(&wl->mutex);
}
static int wl1251_open_file_generic(struct inode *inode, struct file *file)
{
file->private_data = inode->i_private;
return 0;
}
static ssize_t tx_queue_len_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct wl1251 *wl = file->private_data;
u32 queue_len;
char buf[20];
int res;
queue_len = skb_queue_len(&wl->tx_queue);
res = scnprintf(buf, sizeof(buf), "%u\n", queue_len);
return simple_read_from_buffer(userbuf, count, ppos, buf, res);
}
static ssize_t tx_queue_status_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct wl1251 *wl = file->private_data;
char buf[3], status;
int len;
if (wl->tx_queue_stopped)
status = 's';
else
status = 'r';
len = scnprintf(buf, sizeof(buf), "%c\n", status);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static void wl1251_debugfs_delete_files(struct wl1251 *wl)
{
DEBUGFS_FWSTATS_DEL(tx, internal_desc_overflow);
DEBUGFS_FWSTATS_DEL(rx, out_of_mem);
DEBUGFS_FWSTATS_DEL(rx, hdr_overflow);
DEBUGFS_FWSTATS_DEL(rx, hw_stuck);
DEBUGFS_FWSTATS_DEL(rx, dropped);
DEBUGFS_FWSTATS_DEL(rx, fcs_err);
DEBUGFS_FWSTATS_DEL(rx, xfr_hint_trig);
DEBUGFS_FWSTATS_DEL(rx, path_reset);
DEBUGFS_FWSTATS_DEL(rx, reset_counter);
DEBUGFS_FWSTATS_DEL(dma, rx_requested);
DEBUGFS_FWSTATS_DEL(dma, rx_errors);
DEBUGFS_FWSTATS_DEL(dma, tx_requested);
DEBUGFS_FWSTATS_DEL(dma, tx_errors);
DEBUGFS_FWSTATS_DEL(isr, cmd_cmplt);
DEBUGFS_FWSTATS_DEL(isr, fiqs);
DEBUGFS_FWSTATS_DEL(isr, rx_headers);
DEBUGFS_FWSTATS_DEL(isr, rx_mem_overflow);
DEBUGFS_FWSTATS_DEL(isr, rx_rdys);
DEBUGFS_FWSTATS_DEL(isr, irqs);
DEBUGFS_FWSTATS_DEL(isr, tx_procs);
DEBUGFS_FWSTATS_DEL(isr, decrypt_done);
DEBUGFS_FWSTATS_DEL(isr, dma0_done);
DEBUGFS_FWSTATS_DEL(isr, dma1_done);
DEBUGFS_FWSTATS_DEL(isr, tx_exch_complete);
DEBUGFS_FWSTATS_DEL(isr, commands);
DEBUGFS_FWSTATS_DEL(isr, rx_procs);
DEBUGFS_FWSTATS_DEL(isr, hw_pm_mode_changes);
DEBUGFS_FWSTATS_DEL(isr, host_acknowledges);
DEBUGFS_FWSTATS_DEL(isr, pci_pm);
DEBUGFS_FWSTATS_DEL(isr, wakeups);
DEBUGFS_FWSTATS_DEL(isr, low_rssi);
DEBUGFS_FWSTATS_DEL(wep, addr_key_count);
DEBUGFS_FWSTATS_DEL(wep, default_key_count);
DEBUGFS_FWSTATS_DEL(wep, key_not_found);
DEBUGFS_FWSTATS_DEL(wep, decrypt_fail);
DEBUGFS_FWSTATS_DEL(wep, packets);
DEBUGFS_FWSTATS_DEL(wep, interrupt);
DEBUGFS_FWSTATS_DEL(pwr, ps_enter);
DEBUGFS_FWSTATS_DEL(pwr, elp_enter);
DEBUGFS_FWSTATS_DEL(pwr, missing_bcns);
DEBUGFS_FWSTATS_DEL(pwr, wake_on_host);
DEBUGFS_FWSTATS_DEL(pwr, wake_on_timer_exp);
DEBUGFS_FWSTATS_DEL(pwr, tx_with_ps);
DEBUGFS_FWSTATS_DEL(pwr, tx_without_ps);
DEBUGFS_FWSTATS_DEL(pwr, rcvd_beacons);
DEBUGFS_FWSTATS_DEL(pwr, power_save_off);
DEBUGFS_FWSTATS_DEL(pwr, enable_ps);
DEBUGFS_FWSTATS_DEL(pwr, disable_ps);
DEBUGFS_FWSTATS_DEL(pwr, fix_tsf_ps);
DEBUGFS_FWSTATS_DEL(pwr, rcvd_awake_beacons);
DEBUGFS_FWSTATS_DEL(mic, rx_pkts);
DEBUGFS_FWSTATS_DEL(mic, calc_failure);
DEBUGFS_FWSTATS_DEL(aes, encrypt_fail);
DEBUGFS_FWSTATS_DEL(aes, decrypt_fail);
DEBUGFS_FWSTATS_DEL(aes, encrypt_packets);
DEBUGFS_FWSTATS_DEL(aes, decrypt_packets);
DEBUGFS_FWSTATS_DEL(aes, encrypt_interrupt);
DEBUGFS_FWSTATS_DEL(aes, decrypt_interrupt);
DEBUGFS_FWSTATS_DEL(event, heart_beat);
DEBUGFS_FWSTATS_DEL(event, calibration);
DEBUGFS_FWSTATS_DEL(event, rx_mismatch);
DEBUGFS_FWSTATS_DEL(event, rx_mem_empty);
DEBUGFS_FWSTATS_DEL(event, rx_pool);
DEBUGFS_FWSTATS_DEL(event, oom_late);
DEBUGFS_FWSTATS_DEL(event, phy_transmit_error);
DEBUGFS_FWSTATS_DEL(event, tx_stuck);
DEBUGFS_FWSTATS_DEL(ps, pspoll_timeouts);
DEBUGFS_FWSTATS_DEL(ps, upsd_timeouts);
DEBUGFS_FWSTATS_DEL(ps, upsd_max_sptime);
DEBUGFS_FWSTATS_DEL(ps, upsd_max_apturn);
DEBUGFS_FWSTATS_DEL(ps, pspoll_max_apturn);
DEBUGFS_FWSTATS_DEL(ps, pspoll_utilization);
DEBUGFS_FWSTATS_DEL(ps, upsd_utilization);
DEBUGFS_FWSTATS_DEL(rxpipe, rx_prep_beacon_drop);
DEBUGFS_FWSTATS_DEL(rxpipe, descr_host_int_trig_rx_data);
DEBUGFS_FWSTATS_DEL(rxpipe, beacon_buffer_thres_host_int_trig_rx_data);
DEBUGFS_FWSTATS_DEL(rxpipe, missed_beacon_host_int_trig_rx_data);
DEBUGFS_FWSTATS_DEL(rxpipe, tx_xfr_host_int_trig_rx_data);
DEBUGFS_DEL(tx_queue_len);
DEBUGFS_DEL(tx_queue_status);
DEBUGFS_DEL(retry_count);
DEBUGFS_DEL(excessive_retries);
}
static int wl1251_debugfs_add_files(struct wl1251 *wl)
{
int ret = 0;
DEBUGFS_FWSTATS_ADD(tx, internal_desc_overflow);
DEBUGFS_FWSTATS_ADD(rx, out_of_mem);
DEBUGFS_FWSTATS_ADD(rx, hdr_overflow);
DEBUGFS_FWSTATS_ADD(rx, hw_stuck);
DEBUGFS_FWSTATS_ADD(rx, dropped);
DEBUGFS_FWSTATS_ADD(rx, fcs_err);
DEBUGFS_FWSTATS_ADD(rx, xfr_hint_trig);
DEBUGFS_FWSTATS_ADD(rx, path_reset);
DEBUGFS_FWSTATS_ADD(rx, reset_counter);
DEBUGFS_FWSTATS_ADD(dma, rx_requested);
DEBUGFS_FWSTATS_ADD(dma, rx_errors);
DEBUGFS_FWSTATS_ADD(dma, tx_requested);
DEBUGFS_FWSTATS_ADD(dma, tx_errors);
DEBUGFS_FWSTATS_ADD(isr, cmd_cmplt);
DEBUGFS_FWSTATS_ADD(isr, fiqs);
DEBUGFS_FWSTATS_ADD(isr, rx_headers);
DEBUGFS_FWSTATS_ADD(isr, rx_mem_overflow);
DEBUGFS_FWSTATS_ADD(isr, rx_rdys);
DEBUGFS_FWSTATS_ADD(isr, irqs);
DEBUGFS_FWSTATS_ADD(isr, tx_procs);
DEBUGFS_FWSTATS_ADD(isr, decrypt_done);
DEBUGFS_FWSTATS_ADD(isr, dma0_done);
DEBUGFS_FWSTATS_ADD(isr, dma1_done);
DEBUGFS_FWSTATS_ADD(isr, tx_exch_complete);
DEBUGFS_FWSTATS_ADD(isr, commands);
DEBUGFS_FWSTATS_ADD(isr, rx_procs);
DEBUGFS_FWSTATS_ADD(isr, hw_pm_mode_changes);
DEBUGFS_FWSTATS_ADD(isr, host_acknowledges);
DEBUGFS_FWSTATS_ADD(isr, pci_pm);
DEBUGFS_FWSTATS_ADD(isr, wakeups);
DEBUGFS_FWSTATS_ADD(isr, low_rssi);
DEBUGFS_FWSTATS_ADD(wep, addr_key_count);
DEBUGFS_FWSTATS_ADD(wep, default_key_count);
DEBUGFS_FWSTATS_ADD(wep, key_not_found);
DEBUGFS_FWSTATS_ADD(wep, decrypt_fail);
DEBUGFS_FWSTATS_ADD(wep, packets);
DEBUGFS_FWSTATS_ADD(wep, interrupt);
DEBUGFS_FWSTATS_ADD(pwr, ps_enter);
DEBUGFS_FWSTATS_ADD(pwr, elp_enter);
DEBUGFS_FWSTATS_ADD(pwr, missing_bcns);
DEBUGFS_FWSTATS_ADD(pwr, wake_on_host);
DEBUGFS_FWSTATS_ADD(pwr, wake_on_timer_exp);
DEBUGFS_FWSTATS_ADD(pwr, tx_with_ps);
DEBUGFS_FWSTATS_ADD(pwr, tx_without_ps);
DEBUGFS_FWSTATS_ADD(pwr, rcvd_beacons);
DEBUGFS_FWSTATS_ADD(pwr, power_save_off);
DEBUGFS_FWSTATS_ADD(pwr, enable_ps);
DEBUGFS_FWSTATS_ADD(pwr, disable_ps);
DEBUGFS_FWSTATS_ADD(pwr, fix_tsf_ps);
DEBUGFS_FWSTATS_ADD(pwr, rcvd_awake_beacons);
DEBUGFS_FWSTATS_ADD(mic, rx_pkts);
DEBUGFS_FWSTATS_ADD(mic, calc_failure);
DEBUGFS_FWSTATS_ADD(aes, encrypt_fail);
DEBUGFS_FWSTATS_ADD(aes, decrypt_fail);
DEBUGFS_FWSTATS_ADD(aes, encrypt_packets);
DEBUGFS_FWSTATS_ADD(aes, decrypt_packets);
DEBUGFS_FWSTATS_ADD(aes, encrypt_interrupt);
DEBUGFS_FWSTATS_ADD(aes, decrypt_interrupt);
DEBUGFS_FWSTATS_ADD(event, heart_beat);
DEBUGFS_FWSTATS_ADD(event, calibration);
DEBUGFS_FWSTATS_ADD(event, rx_mismatch);
DEBUGFS_FWSTATS_ADD(event, rx_mem_empty);
DEBUGFS_FWSTATS_ADD(event, rx_pool);
DEBUGFS_FWSTATS_ADD(event, oom_late);
DEBUGFS_FWSTATS_ADD(event, phy_transmit_error);
DEBUGFS_FWSTATS_ADD(event, tx_stuck);
DEBUGFS_FWSTATS_ADD(ps, pspoll_timeouts);
DEBUGFS_FWSTATS_ADD(ps, upsd_timeouts);
DEBUGFS_FWSTATS_ADD(ps, upsd_max_sptime);
DEBUGFS_FWSTATS_ADD(ps, upsd_max_apturn);
DEBUGFS_FWSTATS_ADD(ps, pspoll_max_apturn);
DEBUGFS_FWSTATS_ADD(ps, pspoll_utilization);
DEBUGFS_FWSTATS_ADD(ps, upsd_utilization);
DEBUGFS_FWSTATS_ADD(rxpipe, rx_prep_beacon_drop);
DEBUGFS_FWSTATS_ADD(rxpipe, descr_host_int_trig_rx_data);
DEBUGFS_FWSTATS_ADD(rxpipe, beacon_buffer_thres_host_int_trig_rx_data);
DEBUGFS_FWSTATS_ADD(rxpipe, missed_beacon_host_int_trig_rx_data);
DEBUGFS_FWSTATS_ADD(rxpipe, tx_xfr_host_int_trig_rx_data);
DEBUGFS_ADD(tx_queue_len, wl->debugfs.rootdir);
DEBUGFS_ADD(tx_queue_status, wl->debugfs.rootdir);
DEBUGFS_ADD(retry_count, wl->debugfs.rootdir);
DEBUGFS_ADD(excessive_retries, wl->debugfs.rootdir);
out:
if (ret < 0)
wl1251_debugfs_delete_files(wl);
return ret;
}
void wl1251_debugfs_reset(struct wl1251 *wl)
{
if (wl->stats.fw_stats != NULL)
memset(wl->stats.fw_stats, 0, sizeof(*wl->stats.fw_stats));
wl->stats.retry_count = 0;
wl->stats.excessive_retries = 0;
}
int wl1251_debugfs_init(struct wl1251 *wl)
{
int ret;
wl->debugfs.rootdir = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (IS_ERR(wl->debugfs.rootdir)) {
ret = PTR_ERR(wl->debugfs.rootdir);
wl->debugfs.rootdir = NULL;
goto err;
}
wl->debugfs.fw_statistics = debugfs_create_dir("fw-statistics",
wl->debugfs.rootdir);
if (IS_ERR(wl->debugfs.fw_statistics)) {
ret = PTR_ERR(wl->debugfs.fw_statistics);
wl->debugfs.fw_statistics = NULL;
goto err_root;
}
wl->stats.fw_stats = kzalloc(sizeof(*wl->stats.fw_stats),
GFP_KERNEL);
if (!wl->stats.fw_stats) {
ret = -ENOMEM;
goto err_fw;
}
wl->stats.fw_stats_update = jiffies;
ret = wl1251_debugfs_add_files(wl);
if (ret < 0)
goto err_file;
return 0;
err_file:
kfree(wl->stats.fw_stats);
wl->stats.fw_stats = NULL;
err_fw:
debugfs_remove(wl->debugfs.fw_statistics);
wl->debugfs.fw_statistics = NULL;
err_root:
debugfs_remove(wl->debugfs.rootdir);
wl->debugfs.rootdir = NULL;
err:
return ret;
}
void wl1251_debugfs_exit(struct wl1251 *wl)
{
wl1251_debugfs_delete_files(wl);
kfree(wl->stats.fw_stats);
wl->stats.fw_stats = NULL;
debugfs_remove(wl->debugfs.fw_statistics);
wl->debugfs.fw_statistics = NULL;
debugfs_remove(wl->debugfs.rootdir);
wl->debugfs.rootdir = NULL;
}
