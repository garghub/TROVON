static int ft1000ReadProc(struct seq_file *m, void *v)
{
static const char *status[] = {
"Idle (Disconnect)", "Searching", "Active (Connected)",
"Waiting for L2", "Sleep", "No Coverage", "", ""
};
static const char *signal[] = { "", "*", "**", "***", "****" };
struct net_device *dev = m->private;
struct ft1000_info *info = netdev_priv(dev);
int i;
int strength;
int quality;
struct timeval tv;
time_t delta;
if (info->AsicID == ELECTRABUZZ_ID) {
if (info->ProgConStat != 0xFF) {
info->LedStat =
ft1000_read_dpram(dev, FT1000_DSP_LED);
info->ConStat =
ft1000_read_dpram(dev, FT1000_DSP_CON_STATE);
} else {
info->ConStat = 0xf;
}
} else {
if (info->ProgConStat != 0xFF) {
info->LedStat =
ntohs(ft1000_read_dpram_mag_16(
dev, FT1000_MAG_DSP_LED,
FT1000_MAG_DSP_LED_INDX));
info->ConStat =
ntohs(ft1000_read_dpram_mag_16(
dev, FT1000_MAG_DSP_CON_STATE,
FT1000_MAG_DSP_CON_STATE_INDX));
} else {
info->ConStat = 0xf;
}
}
i = (info->LedStat) & 0xf;
switch (i) {
case 0x1:
strength = 1;
break;
case 0x3:
strength = 2;
break;
case 0x7:
strength = 3;
break;
case 0xf:
strength = 4;
break;
default:
strength = 0;
}
i = (info->LedStat >> 8) & 0xf;
switch (i) {
case 0x1:
quality = 1;
break;
case 0x3:
quality = 2;
break;
case 0x7:
quality = 3;
break;
case 0xf:
quality = 4;
break;
default:
quality = 0;
}
do_gettimeofday(&tv);
delta = tv.tv_sec - info->ConTm;
seq_printf(m, "Connection Time: %02ld:%02ld:%02ld\n",
((delta / 3600) % 24), ((delta / 60) % 60), (delta % 60));
seq_printf(m, "Connection Time[s]: %ld\n", delta);
seq_printf(m, "Asic ID: %s\n",
info->AsicID ==
ELECTRABUZZ_ID ? "ELECTRABUZZ ASIC" : "MAGNEMITE ASIC");
seq_putx(m, "SKU: ", SKUSZ, info->Sku);
seq_putx(m, "EUI64: ", EUISZ, info->eui64);
seq_putd(m, "DSP version number: ", DSPVERSZ, info->DspVer);
seq_putx(m, "Hardware Serial Number: ", HWSERNUMSZ, info->HwSerNum);
seq_putx(m, "Caliberation Version: ", CALVERSZ, info->RfCalVer);
seq_putd(m, "Caliberation Date: ", CALDATESZ, info->RfCalDate);
seq_printf(m, "Media State: %s\n",
(info->mediastate) ? "link" : "no link");
seq_printf(m, "Connection Status: %s\n", status[info->ConStat & 0x7]);
seq_printf(m, "RX packets: %ld\n", info->stats.rx_packets);
seq_printf(m, "TX packets: %ld\n", info->stats.tx_packets);
seq_printf(m, "RX bytes: %ld\n", info->stats.rx_bytes);
seq_printf(m, "TX bytes: %ld\n", info->stats.tx_bytes);
seq_printf(m, "Signal Strength: %s\n", signal[strength]);
seq_printf(m, "Signal Quality: %s\n", signal[quality]);
return 0;
}
static int ft1000_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ft1000ReadProc, PDE_DATA(inode));
}
static int ft1000NotifyProc(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = ptr;
struct ft1000_info *info;
info = netdev_priv(dev);
switch (event) {
case NETDEV_CHANGENAME:
remove_proc_entry(info->netdevname, info->ft1000_proc_dir);
proc_create_data(dev->name, 0644, info->ft1000_proc_dir,
&ft1000_proc_fops, dev);
snprintf(info->netdevname, IFNAMSIZ, "%s", dev->name);
break;
}
return NOTIFY_DONE;
}
void ft1000InitProc(struct net_device *dev)
{
struct ft1000_info *info;
info = netdev_priv(dev);
info->ft1000_proc_dir = proc_mkdir(FT1000_PROC, init_net.proc_net);
proc_create_data(dev->name, 0644, info->ft1000_proc_dir,
&ft1000_proc_fops, dev);
snprintf(info->netdevname, IFNAMSIZ, "%s", dev->name);
register_netdevice_notifier(&ft1000_netdev_notifier);
}
void ft1000CleanupProc(struct net_device *dev)
{
struct ft1000_info *info;
info = netdev_priv(dev);
remove_proc_entry(dev->name, info->ft1000_proc_dir);
remove_proc_entry(FT1000_PROC, init_net.proc_net);
unregister_netdevice_notifier(&ft1000_netdev_notifier);
}
