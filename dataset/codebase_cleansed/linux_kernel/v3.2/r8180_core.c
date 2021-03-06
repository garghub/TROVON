static void rtl8180_shutdown(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (dev->netdev_ops->ndo_stop)
dev->netdev_ops->ndo_stop(dev);
pci_disable_device(pdev);
}
static int rtl8180_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
if (!netif_running(dev))
goto out_pci_suspend;
if (dev->netdev_ops->ndo_stop)
dev->netdev_ops->ndo_stop(dev);
netif_device_detach(dev);
out_pci_suspend:
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int rtl8180_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
int err;
u32 val;
pci_set_power_state(pdev, PCI_D0);
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR "%s: pci_enable_device failed on resume\n",
dev->name);
return err;
}
pci_restore_state(pdev);
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
if (!netif_running(dev))
goto out;
if (dev->netdev_ops->ndo_open)
dev->netdev_ops->ndo_open(dev);
netif_device_attach(dev);
out:
return 0;
}
u8 read_nic_byte(struct net_device *dev, int x)
{
return 0xff&readb((u8 *)dev->mem_start + x);
}
u32 read_nic_dword(struct net_device *dev, int x)
{
return readl((u8 *)dev->mem_start + x);
}
u16 read_nic_word(struct net_device *dev, int x)
{
return readw((u8 *)dev->mem_start + x);
}
void write_nic_byte(struct net_device *dev, int x, u8 y)
{
writeb(y, (u8 *)dev->mem_start + x);
udelay(20);
}
void write_nic_dword(struct net_device *dev, int x, u32 y)
{
writel(y, (u8 *)dev->mem_start + x);
udelay(20);
}
void write_nic_word(struct net_device *dev, int x, u16 y)
{
writew(y, (u8 *)dev->mem_start + x);
udelay(20);
}
inline void force_pci_posting(struct net_device *dev)
{
read_nic_byte(dev, EPROM_CMD);
mb();
}
static int proc_get_registers(char *page, char **start,
off_t offset, int count,
int *eof, void *data)
{
struct net_device *dev = data;
int len = 0;
int i, n;
int max = 0xff;
for (n = 0; n <= max;) {
len += snprintf(page + len, count - len, "\nD: %2x > ", n);
for (i = 0; i < 16 && n <= max; i++, n++)
len += snprintf(page + len, count - len, "%2x ",
read_nic_byte(dev, n));
}
len += snprintf(page + len, count - len, "\n");
*eof = 1;
return len;
}
static int proc_get_stats_hw(char *page, char **start,
off_t offset, int count,
int *eof, void *data)
{
int len = 0;
*eof = 1;
return len;
}
static int proc_get_stats_rx(char *page, char **start,
off_t offset, int count,
int *eof, void *data)
{
struct net_device *dev = data;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
int len = 0;
len += snprintf(page + len, count - len,
"RX OK: %lu\n"
"RX Retry: %lu\n"
"RX CRC Error(0-500): %lu\n"
"RX CRC Error(500-1000): %lu\n"
"RX CRC Error(>1000): %lu\n"
"RX ICV Error: %lu\n",
priv->stats.rxint,
priv->stats.rxerr,
priv->stats.rxcrcerrmin,
priv->stats.rxcrcerrmid,
priv->stats.rxcrcerrmax,
priv->stats.rxicverr
);
*eof = 1;
return len;
}
static int proc_get_stats_tx(char *page, char **start,
off_t offset, int count,
int *eof, void *data)
{
struct net_device *dev = data;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
int len = 0;
unsigned long totalOK;
totalOK = priv->stats.txnpokint+priv->stats.txhpokint+priv->stats.txlpokint;
len += snprintf(page + len, count - len,
"TX OK: %lu\n"
"TX Error: %lu\n"
"TX Retry: %lu\n"
"TX beacon OK: %lu\n"
"TX beacon error: %lu\n",
totalOK,
priv->stats.txnperr+priv->stats.txhperr+priv->stats.txlperr,
priv->stats.txretry,
priv->stats.txbeacon,
priv->stats.txbeaconerr
);
*eof = 1;
return len;
}
void rtl8180_proc_module_init(void)
{
DMESG("Initializing proc filesystem");
rtl8180_proc = proc_mkdir(RTL8180_MODULE_NAME, init_net.proc_net);
}
void rtl8180_proc_module_remove(void)
{
remove_proc_entry(RTL8180_MODULE_NAME, init_net.proc_net);
}
void rtl8180_proc_remove_one(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
if (priv->dir_dev) {
remove_proc_entry("stats-hw", priv->dir_dev);
remove_proc_entry("stats-tx", priv->dir_dev);
remove_proc_entry("stats-rx", priv->dir_dev);
remove_proc_entry("registers", priv->dir_dev);
remove_proc_entry(dev->name, rtl8180_proc);
priv->dir_dev = NULL;
}
}
void rtl8180_proc_init_one(struct net_device *dev)
{
struct proc_dir_entry *e;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
priv->dir_dev = rtl8180_proc;
if (!priv->dir_dev) {
DMESGE("Unable to initialize /proc/net/r8180/%s\n",
dev->name);
return;
}
e = create_proc_read_entry("stats-hw", S_IFREG | S_IRUGO,
priv->dir_dev, proc_get_stats_hw, dev);
if (!e) {
DMESGE("Unable to initialize "
"/proc/net/r8180/%s/stats-hw\n",
dev->name);
}
e = create_proc_read_entry("stats-rx", S_IFREG | S_IRUGO,
priv->dir_dev, proc_get_stats_rx, dev);
if (!e) {
DMESGE("Unable to initialize "
"/proc/net/r8180/%s/stats-rx\n",
dev->name);
}
e = create_proc_read_entry("stats-tx", S_IFREG | S_IRUGO,
priv->dir_dev, proc_get_stats_tx, dev);
if (!e) {
DMESGE("Unable to initialize "
"/proc/net/r8180/%s/stats-tx\n",
dev->name);
}
e = create_proc_read_entry("registers", S_IFREG | S_IRUGO,
priv->dir_dev, proc_get_registers, dev);
if (!e) {
DMESGE("Unable to initialize "
"/proc/net/r8180/%s/registers\n",
dev->name);
}
}
short buffer_add(struct buffer **buffer, u32 *buf, dma_addr_t dma,
struct buffer **bufferhead)
{
struct buffer *tmp;
if (!*buffer) {
*buffer = kmalloc(sizeof(struct buffer), GFP_KERNEL);
if (*buffer == NULL) {
DMESGE("Failed to kmalloc head of TX/RX struct");
return -1;
}
(*buffer)->next = *buffer;
(*buffer)->buf = buf;
(*buffer)->dma = dma;
if (bufferhead != NULL)
(*bufferhead) = (*buffer);
return 0;
}
tmp = *buffer;
while (tmp->next != (*buffer))
tmp = tmp->next;
tmp->next = kmalloc(sizeof(struct buffer), GFP_KERNEL);
if (tmp->next == NULL) {
DMESGE("Failed to kmalloc TX/RX struct");
return -1;
}
tmp->next->buf = buf;
tmp->next->dma = dma;
tmp->next->next = *buffer;
return 0;
}
void buffer_free(struct net_device *dev, struct buffer **buffer, int len, short consistent)
{
struct buffer *tmp, *next;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct pci_dev *pdev = priv->pdev;
if (!*buffer)
return;
tmp = *buffer;
do {
next = tmp->next;
if (consistent) {
pci_free_consistent(pdev, len,
tmp->buf, tmp->dma);
} else {
pci_unmap_single(pdev, tmp->dma,
len, PCI_DMA_FROMDEVICE);
kfree(tmp->buf);
}
kfree(tmp);
tmp = next;
}
while (next != *buffer);
*buffer = NULL;
}
void print_buffer(u32 *buffer, int len)
{
int i;
u8 *buf = (u8 *)buffer;
printk("ASCII BUFFER DUMP (len: %x):\n", len);
for (i = 0; i < len; i++)
printk("%c", buf[i]);
printk("\nBINARY BUFFER DUMP (len: %x):\n", len);
for (i = 0; i < len; i++)
printk("%02x", buf[i]);
printk("\n");
}
int get_curr_tx_free_desc(struct net_device *dev, int priority)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u32 *tail;
u32 *head;
int ret;
switch (priority) {
case MANAGE_PRIORITY:
head = priv->txmapringhead;
tail = priv->txmapringtail;
break;
case BK_PRIORITY:
head = priv->txbkpringhead;
tail = priv->txbkpringtail;
break;
case BE_PRIORITY:
head = priv->txbepringhead;
tail = priv->txbepringtail;
break;
case VI_PRIORITY:
head = priv->txvipringhead;
tail = priv->txvipringtail;
break;
case VO_PRIORITY:
head = priv->txvopringhead;
tail = priv->txvopringtail;
break;
case HI_PRIORITY:
head = priv->txhpringhead;
tail = priv->txhpringtail;
break;
default:
return -1;
}
if (head <= tail)
ret = priv->txringcount - (tail - head)/8;
else
ret = (head - tail)/8;
if (ret > priv->txringcount)
DMESG("BUG");
return ret;
}
short check_nic_enought_desc(struct net_device *dev, int priority)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = netdev_priv(dev);
int requiredbyte, required;
requiredbyte = priv->ieee80211->fts + sizeof(struct ieee80211_header_data);
if (ieee->current_network.QoS_Enable)
requiredbyte += 2;
required = requiredbyte / (priv->txbuffsize-4);
if (requiredbyte % priv->txbuffsize)
required++;
return (required+2 < get_curr_tx_free_desc(dev, priority));
}
void fix_tx_fifo(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
u32 *tmp;
int i;
for (tmp = priv->txmapring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txbkpring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txbepring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txvipring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txvopring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txhpring, i = 0;
i < priv->txringcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
for (tmp = priv->txbeaconring, i = 0;
i < priv->txbeaconcount;
tmp += 8, i++) {
*tmp = *tmp & ~(1<<31);
}
priv->txmapringtail = priv->txmapring;
priv->txmapringhead = priv->txmapring;
priv->txmapbufstail = priv->txmapbufs;
priv->txbkpringtail = priv->txbkpring;
priv->txbkpringhead = priv->txbkpring;
priv->txbkpbufstail = priv->txbkpbufs;
priv->txbepringtail = priv->txbepring;
priv->txbepringhead = priv->txbepring;
priv->txbepbufstail = priv->txbepbufs;
priv->txvipringtail = priv->txvipring;
priv->txvipringhead = priv->txvipring;
priv->txvipbufstail = priv->txvipbufs;
priv->txvopringtail = priv->txvopring;
priv->txvopringhead = priv->txvopring;
priv->txvopbufstail = priv->txvopbufs;
priv->txhpringtail = priv->txhpring;
priv->txhpringhead = priv->txhpring;
priv->txhpbufstail = priv->txhpbufs;
priv->txbeaconringtail = priv->txbeaconring;
priv->txbeaconbufstail = priv->txbeaconbufs;
set_nic_txring(dev);
ieee80211_reset_queue(priv->ieee80211);
priv->ack_tx_to_ieee = 0;
}
void fix_rx_fifo(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
u32 *tmp;
struct buffer *rxbuf;
u8 rx_desc_size;
rx_desc_size = 8;
for (tmp = priv->rxring, rxbuf = priv->rxbufferhead;
(tmp < (priv->rxring)+(priv->rxringcount)*rx_desc_size);
tmp += rx_desc_size, rxbuf = rxbuf->next) {
*(tmp+2) = rxbuf->dma;
*tmp = *tmp & ~0xfff;
*tmp = *tmp | priv->rxbuffersize;
*tmp |= (1<<31);
}
priv->rxringtail = priv->rxring;
priv->rxbuffer = priv->rxbufferhead;
priv->rx_skb_complete = 1;
set_nic_rxring(dev);
}
void rtl8180_RSSI_calc(struct net_device *dev, u8 *rssi, u8 *qual)
{
u32 temp;
u32 temp2;
u32 q;
u32 orig_qual;
u8 _rssi;
q = *qual;
orig_qual = *qual;
_rssi = 0;
if (q <= 0x4e) {
temp = QUALITY_MAP[q];
} else {
if (q & 0x80)
temp = 0x32;
else
temp = 1;
}
*qual = temp;
temp2 = *rssi;
if (_rssi < 0x64) {
if (_rssi == 0)
*rssi = 1;
} else {
*rssi = 0x64;
}
return;
}
void rtl8180_irq_enable(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
priv->irq_enabled = 1;
write_nic_word(dev, INTA_MASK, priv->irq_mask);
}
void rtl8180_irq_disable(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
write_nic_dword(dev, IMR, 0);
force_pci_posting(dev);
priv->irq_enabled = 0;
}
void rtl8180_set_mode(struct net_device *dev, int mode)
{
u8 ecmd;
ecmd = read_nic_byte(dev, EPROM_CMD);
ecmd = ecmd & ~EPROM_CMD_OPERATING_MODE_MASK;
ecmd = ecmd | (mode<<EPROM_CMD_OPERATING_MODE_SHIFT);
ecmd = ecmd & ~(1<<EPROM_CS_SHIFT);
ecmd = ecmd & ~(1<<EPROM_CK_SHIFT);
write_nic_byte(dev, EPROM_CMD, ecmd);
}
void rtl8180_update_msr(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u8 msr;
u32 rxconf;
msr = read_nic_byte(dev, MSR);
msr &= ~MSR_LINK_MASK;
rxconf = read_nic_dword(dev, RX_CONF);
if (priv->ieee80211->state == IEEE80211_LINKED) {
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
msr |= (MSR_LINK_ADHOC<<MSR_LINK_SHIFT);
else if (priv->ieee80211->iw_mode == IW_MODE_MASTER)
msr |= (MSR_LINK_MASTER<<MSR_LINK_SHIFT);
else if (priv->ieee80211->iw_mode == IW_MODE_INFRA)
msr |= (MSR_LINK_MANAGED<<MSR_LINK_SHIFT);
else
msr |= (MSR_LINK_NONE<<MSR_LINK_SHIFT);
rxconf |= (1<<RX_CHECK_BSSID_SHIFT);
} else {
msr |= (MSR_LINK_NONE<<MSR_LINK_SHIFT);
rxconf &= ~(1<<RX_CHECK_BSSID_SHIFT);
}
write_nic_byte(dev, MSR, msr);
write_nic_dword(dev, RX_CONF, rxconf);
}
void rtl8180_set_chan(struct net_device *dev, short ch)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
if ((ch > 14) || (ch < 1)) {
printk("In %s: Invalid chnanel %d\n", __func__, ch);
return;
}
priv->chan = ch;
priv->rf_set_chan(dev, priv->chan);
}
void rtl8180_rx_enable(struct net_device *dev)
{
u8 cmd;
u32 rxconf;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rxconf = read_nic_dword(dev, RX_CONF);
rxconf = rxconf & ~MAC_FILTER_MASK;
rxconf = rxconf | (1<<ACCEPT_MNG_FRAME_SHIFT);
rxconf = rxconf | (1<<ACCEPT_DATA_FRAME_SHIFT);
rxconf = rxconf | (1<<ACCEPT_BCAST_FRAME_SHIFT);
rxconf = rxconf | (1<<ACCEPT_MCAST_FRAME_SHIFT);
if (dev->flags & IFF_PROMISC)
DMESG("NIC in promisc mode");
if (priv->ieee80211->iw_mode == IW_MODE_MONITOR || \
dev->flags & IFF_PROMISC) {
rxconf = rxconf | (1<<ACCEPT_ALLMAC_FRAME_SHIFT);
} else {
rxconf = rxconf | (1<<ACCEPT_NICMAC_FRAME_SHIFT);
}
if (priv->ieee80211->iw_mode == IW_MODE_MONITOR) {
rxconf = rxconf | (1<<ACCEPT_CTL_FRAME_SHIFT);
rxconf = rxconf | (1<<ACCEPT_ICVERR_FRAME_SHIFT);
rxconf = rxconf | (1<<ACCEPT_PWR_FRAME_SHIFT);
}
if (priv->crcmon == 1 && priv->ieee80211->iw_mode == IW_MODE_MONITOR)
rxconf = rxconf | (1<<ACCEPT_CRCERR_FRAME_SHIFT);
rxconf = rxconf & ~RX_FIFO_THRESHOLD_MASK;
rxconf = rxconf | (RX_FIFO_THRESHOLD_NONE << RX_FIFO_THRESHOLD_SHIFT);
rxconf = rxconf | (1<<RX_AUTORESETPHY_SHIFT);
rxconf = rxconf & ~MAX_RX_DMA_MASK;
rxconf = rxconf | (MAX_RX_DMA_2048<<MAX_RX_DMA_SHIFT);
rxconf = rxconf | RCR_ONLYERLPKT;
rxconf = rxconf & ~RCR_CS_MASK;
write_nic_dword(dev, RX_CONF, rxconf);
fix_rx_fifo(dev);
cmd = read_nic_byte(dev, CMD);
write_nic_byte(dev, CMD, cmd | (1<<CMD_RX_ENABLE_SHIFT));
}
void set_nic_txring(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
write_nic_dword(dev, TX_MANAGEPRIORITY_RING_ADDR, priv->txmapringdma);
write_nic_dword(dev, TX_BKPRIORITY_RING_ADDR, priv->txbkpringdma);
write_nic_dword(dev, TX_BEPRIORITY_RING_ADDR, priv->txbepringdma);
write_nic_dword(dev, TX_VIPRIORITY_RING_ADDR, priv->txvipringdma);
write_nic_dword(dev, TX_VOPRIORITY_RING_ADDR, priv->txvopringdma);
write_nic_dword(dev, TX_HIGHPRIORITY_RING_ADDR, priv->txhpringdma);
write_nic_dword(dev, TX_BEACON_RING_ADDR, priv->txbeaconringdma);
}
void rtl8180_conttx_enable(struct net_device *dev)
{
u32 txconf;
txconf = read_nic_dword(dev, TX_CONF);
txconf = txconf & ~TX_LOOPBACK_MASK;
txconf = txconf | (TX_LOOPBACK_CONTINUE<<TX_LOOPBACK_SHIFT);
write_nic_dword(dev, TX_CONF, txconf);
}
void rtl8180_conttx_disable(struct net_device *dev)
{
u32 txconf;
txconf = read_nic_dword(dev, TX_CONF);
txconf = txconf & ~TX_LOOPBACK_MASK;
txconf = txconf | (TX_LOOPBACK_NONE<<TX_LOOPBACK_SHIFT);
write_nic_dword(dev, TX_CONF, txconf);
}
void rtl8180_tx_enable(struct net_device *dev)
{
u8 cmd;
u8 tx_agc_ctl;
u8 byte;
u32 txconf;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
txconf = read_nic_dword(dev, TX_CONF);
byte = read_nic_byte(dev, CW_CONF);
byte &= ~(1<<CW_CONF_PERPACKET_CW_SHIFT);
byte &= ~(1<<CW_CONF_PERPACKET_RETRY_SHIFT);
write_nic_byte(dev, CW_CONF, byte);
tx_agc_ctl = read_nic_byte(dev, TX_AGC_CTL);
tx_agc_ctl &= ~(1<<TX_AGC_CTL_PERPACKET_GAIN_SHIFT);
tx_agc_ctl &= ~(1<<TX_AGC_CTL_PERPACKET_ANTSEL_SHIFT);
tx_agc_ctl |= (1<<TX_AGC_CTL_FEEDBACK_ANT);
write_nic_byte(dev, TX_AGC_CTL, tx_agc_ctl);
write_nic_byte(dev, 0xec, 0x3f);
txconf = txconf & ~(1<<TCR_PROBE_NOTIMESTAMP_SHIFT);
txconf = txconf & ~TX_LOOPBACK_MASK;
txconf = txconf | (TX_LOOPBACK_NONE<<TX_LOOPBACK_SHIFT);
txconf = txconf & ~TCR_DPRETRY_MASK;
txconf = txconf & ~TCR_RTSRETRY_MASK;
txconf = txconf | (priv->retry_data<<TX_DPRETRY_SHIFT);
txconf = txconf | (priv->retry_rts<<TX_RTSRETRY_SHIFT);
txconf = txconf & ~(1<<TX_NOCRC_SHIFT);
if (priv->hw_plcp_len)
txconf = txconf & ~TCR_PLCP_LEN;
else
txconf = txconf | TCR_PLCP_LEN;
txconf = txconf & ~TCR_MXDMA_MASK;
txconf = txconf | (TCR_MXDMA_2048<<TCR_MXDMA_SHIFT);
txconf = txconf | TCR_CWMIN;
txconf = txconf | TCR_DISCW;
txconf = txconf | (1 << TX_NOICV_SHIFT);
write_nic_dword(dev, TX_CONF, txconf);
fix_tx_fifo(dev);
cmd = read_nic_byte(dev, CMD);
write_nic_byte(dev, CMD, cmd | (1<<CMD_TX_ENABLE_SHIFT));
write_nic_dword(dev, TX_CONF, txconf);
}
void rtl8180_beacon_tx_enable(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
priv->dma_poll_stop_mask &= ~(TPPOLLSTOP_BQ);
write_nic_byte(dev, TPPollStop, priv->dma_poll_mask);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8180_beacon_tx_disable(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
priv->dma_poll_stop_mask |= TPPOLLSTOP_BQ;
write_nic_byte(dev, TPPollStop, priv->dma_poll_stop_mask);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8180_rtx_disable(struct net_device *dev)
{
u8 cmd;
struct r8180_priv *priv = ieee80211_priv(dev);
cmd = read_nic_byte(dev, CMD);
write_nic_byte(dev, CMD, cmd & ~\
((1<<CMD_RX_ENABLE_SHIFT)|(1<<CMD_TX_ENABLE_SHIFT)));
force_pci_posting(dev);
mdelay(10);
if (!priv->rx_skb_complete)
dev_kfree_skb_any(priv->rx_skb);
}
short alloc_tx_desc_ring(struct net_device *dev, int bufsize, int count,
int addr)
{
int i;
u32 *desc;
u32 *tmp;
dma_addr_t dma_desc, dma_tmp;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct pci_dev *pdev = priv->pdev;
void *buf;
if ((bufsize & 0xfff) != bufsize) {
DMESGE("TX buffer allocation too large");
return 0;
}
desc = (u32 *)pci_alloc_consistent(pdev,
sizeof(u32)*8*count+256, &dma_desc);
if (desc == NULL)
return -1;
if (dma_desc & 0xff)
WARN(1, "DMA buffer is not aligned\n");
tmp = desc;
for (i = 0; i < count; i++) {
buf = (void *)pci_alloc_consistent(pdev, bufsize, &dma_tmp);
if (buf == NULL)
return -ENOMEM;
switch (addr) {
case TX_MANAGEPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txmapbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer NP");
return -ENOMEM;
}
break;
case TX_BKPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txbkpbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer LP");
return -ENOMEM;
}
break;
case TX_BEPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txbepbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer NP");
return -ENOMEM;
}
break;
case TX_VIPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txvipbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer LP");
return -ENOMEM;
}
break;
case TX_VOPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txvopbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer NP");
return -ENOMEM;
}
break;
case TX_HIGHPRIORITY_RING_ADDR:
if (-1 == buffer_add(&(priv->txhpbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer HP");
return -ENOMEM;
}
break;
case TX_BEACON_RING_ADDR:
if (-1 == buffer_add(&(priv->txbeaconbufs), buf, dma_tmp, NULL)) {
DMESGE("Unable to allocate mem for buffer BP");
return -ENOMEM;
}
break;
}
*tmp = *tmp & ~(1<<31);
*(tmp+2) = (u32)dma_tmp;
*(tmp+3) = bufsize;
if (i+1 < count)
*(tmp+4) = (u32)dma_desc+((i+1)*8*4);
else
*(tmp+4) = (u32)dma_desc;
tmp = tmp+8;
}
switch (addr) {
case TX_MANAGEPRIORITY_RING_ADDR:
priv->txmapringdma = dma_desc;
priv->txmapring = desc;
break;
case TX_BKPRIORITY_RING_ADDR:
priv->txbkpringdma = dma_desc;
priv->txbkpring = desc;
break;
case TX_BEPRIORITY_RING_ADDR:
priv->txbepringdma = dma_desc;
priv->txbepring = desc;
break;
case TX_VIPRIORITY_RING_ADDR:
priv->txvipringdma = dma_desc;
priv->txvipring = desc;
break;
case TX_VOPRIORITY_RING_ADDR:
priv->txvopringdma = dma_desc;
priv->txvopring = desc;
break;
case TX_HIGHPRIORITY_RING_ADDR:
priv->txhpringdma = dma_desc;
priv->txhpring = desc;
break;
case TX_BEACON_RING_ADDR:
priv->txbeaconringdma = dma_desc;
priv->txbeaconring = desc;
break;
}
return 0;
}
void free_tx_desc_rings(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct pci_dev *pdev = priv->pdev;
int count = priv->txringcount;
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txmapring, priv->txmapringdma);
buffer_free(dev, &(priv->txmapbufs), priv->txbuffsize, 1);
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txbkpring, priv->txbkpringdma);
buffer_free(dev, &(priv->txbkpbufs), priv->txbuffsize, 1);
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txbepring, priv->txbepringdma);
buffer_free(dev, &(priv->txbepbufs), priv->txbuffsize, 1);
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txvipring, priv->txvipringdma);
buffer_free(dev, &(priv->txvipbufs), priv->txbuffsize, 1);
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txvopring, priv->txvopringdma);
buffer_free(dev, &(priv->txvopbufs), priv->txbuffsize, 1);
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txhpring, priv->txhpringdma);
buffer_free(dev, &(priv->txhpbufs), priv->txbuffsize, 1);
count = priv->txbeaconcount;
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->txbeaconring, priv->txbeaconringdma);
buffer_free(dev, &(priv->txbeaconbufs), priv->txbuffsize, 1);
}
void free_rx_desc_ring(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct pci_dev *pdev = priv->pdev;
int count = priv->rxringcount;
pci_free_consistent(pdev, sizeof(u32)*8*count+256,
priv->rxring, priv->rxringdma);
buffer_free(dev, &(priv->rxbuffer), priv->rxbuffersize, 0);
}
short alloc_rx_desc_ring(struct net_device *dev, u16 bufsize, int count)
{
int i;
u32 *desc;
u32 *tmp;
dma_addr_t dma_desc, dma_tmp;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct pci_dev *pdev = priv->pdev;
void *buf;
u8 rx_desc_size;
rx_desc_size = 8;
if ((bufsize & 0xfff) != bufsize) {
DMESGE("RX buffer allocation too large");
return -1;
}
desc = (u32 *)pci_alloc_consistent(pdev, sizeof(u32)*rx_desc_size*count+256,
&dma_desc);
if (dma_desc & 0xff)
WARN(1, "DMA buffer is not aligned\n");
priv->rxring = desc;
priv->rxringdma = dma_desc;
tmp = desc;
for (i = 0; i < count; i++) {
buf = kmalloc(bufsize * sizeof(u8), GFP_ATOMIC);
if (buf == NULL) {
DMESGE("Failed to kmalloc RX buffer");
return -1;
}
dma_tmp = pci_map_single(pdev, buf, bufsize * sizeof(u8),
PCI_DMA_FROMDEVICE);
if (-1 == buffer_add(&(priv->rxbuffer), buf, dma_tmp,
&(priv->rxbufferhead))) {
DMESGE("Unable to allocate mem RX buf");
return -1;
}
*tmp = 0;
*tmp = *tmp | (bufsize&0xfff);
*(tmp+2) = (u32)dma_tmp;
*tmp = *tmp | (1<<31);
tmp = tmp+rx_desc_size;
}
*(tmp-rx_desc_size) = *(tmp-rx_desc_size) | (1<<30);
return 0;
}
void set_nic_rxring(struct net_device *dev)
{
u8 pgreg;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
pgreg = read_nic_byte(dev, PGSELECT);
write_nic_byte(dev, PGSELECT, pgreg & ~(1<<PGSELECT_PG_SHIFT));
write_nic_dword(dev, RXRING_ADDR, priv->rxringdma);
}
void rtl8180_reset(struct net_device *dev)
{
u8 cr;
rtl8180_irq_disable(dev);
cr = read_nic_byte(dev, CMD);
cr = cr & 2;
cr = cr | (1<<CMD_RST_SHIFT);
write_nic_byte(dev, CMD, cr);
force_pci_posting(dev);
mdelay(200);
if (read_nic_byte(dev, CMD) & (1<<CMD_RST_SHIFT))
DMESGW("Card reset timeout!");
else
DMESG("Card successfully reset");
rtl8180_set_mode(dev, EPROM_CMD_LOAD);
force_pci_posting(dev);
mdelay(200);
}
inline u16 ieeerate2rtlrate(int rate)
{
switch (rate) {
case 10:
return 0;
case 20:
return 1;
case 55:
return 2;
case 110:
return 3;
case 60:
return 4;
case 90:
return 5;
case 120:
return 6;
case 180:
return 7;
case 240:
return 8;
case 360:
return 9;
case 480:
return 10;
case 540:
return 11;
default:
return 3;
}
}
inline u16 rtl8180_rate2rate(short rate)
{
if (rate > 12)
return 10;
return rtl_rate[rate];
}
inline u8 rtl8180_IsWirelessBMode(u16 rate)
{
if (((rate <= 110) && (rate != 60) && (rate != 90)) || (rate == 220))
return 1;
else
return 0;
}
u16 ComputeTxTime(u16 FrameLength, u16 DataRate, u8 bManagementFrame,
u8 bShortPreamble)
{
u16 FrameTime;
u16 N_DBPS;
u16 Ceiling;
if (rtl8180_IsWirelessBMode(DataRate)) {
if (bManagementFrame || !bShortPreamble || DataRate == 10)
FrameTime = (u16)(144+48+(FrameLength*8/(DataRate/10)));
else
FrameTime = (u16)(72+24+(FrameLength*8/(DataRate/10)));
if ((FrameLength*8 % (DataRate/10)) != 0)
FrameTime++;
} else {
N_DBPS = N_DBPSOfRate(DataRate);
Ceiling = (16 + 8*FrameLength + 6) / N_DBPS
+ (((16 + 8*FrameLength + 6) % N_DBPS) ? 1 : 0);
FrameTime = (u16)(16 + 4 + 4*Ceiling + 6);
}
return FrameTime;
}
u16 N_DBPSOfRate(u16 DataRate)
{
u16 N_DBPS = 24;
switch (DataRate) {
case 60:
N_DBPS = 24;
break;
case 90:
N_DBPS = 36;
break;
case 120:
N_DBPS = 48;
break;
case 180:
N_DBPS = 72;
break;
case 240:
N_DBPS = 96;
break;
case 360:
N_DBPS = 144;
break;
case 480:
N_DBPS = 192;
break;
case 540:
N_DBPS = 216;
break;
default:
break;
}
return N_DBPS;
}
long NetgearSignalStrengthTranslate(long LastSS, long CurrSS)
{
long RetSS;
if (CurrSS >= 71 && CurrSS <= 100)
RetSS = 90 + ((CurrSS - 70) / 3);
else if (CurrSS >= 41 && CurrSS <= 70)
RetSS = 78 + ((CurrSS - 40) / 3);
else if (CurrSS >= 31 && CurrSS <= 40)
RetSS = 66 + (CurrSS - 30);
else if (CurrSS >= 21 && CurrSS <= 30)
RetSS = 54 + (CurrSS - 20);
else if (CurrSS >= 5 && CurrSS <= 20)
RetSS = 42 + (((CurrSS - 5) * 2) / 3);
else if (CurrSS == 4)
RetSS = 36;
else if (CurrSS == 3)
RetSS = 27;
else if (CurrSS == 2)
RetSS = 18;
else if (CurrSS == 1)
RetSS = 9;
else
RetSS = CurrSS;
if (LastSS > 0)
RetSS = ((LastSS * 5) + (RetSS) + 5) / 6;
return RetSS;
}
long TranslateToDbm8185(u8 SignalStrengthIndex)
{
long SignalPower;
SignalPower = (long)((SignalStrengthIndex + 1) >> 1);
SignalPower -= 95;
return SignalPower;
}
void PerformUndecoratedSignalSmoothing8185(struct r8180_priv *priv,
bool bCckRate)
{
priv->bCurCCKPkt = bCckRate;
if (priv->UndecoratedSmoothedSS >= 0)
priv->UndecoratedSmoothedSS = ((priv->UndecoratedSmoothedSS * 5) + (priv->SignalStrength * 10)) / 6;
else
priv->UndecoratedSmoothedSS = priv->SignalStrength * 10;
priv->UndercorateSmoothedRxPower = ((priv->UndercorateSmoothedRxPower * 50) + (priv->RxPower * 11)) / 60;
if (bCckRate)
priv->CurCCKRSSI = priv->RSSI;
else
priv->CurCCKRSSI = 0;
}
void rtl8180_rx(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct sk_buff *tmp_skb;
short first, last;
u32 len;
int lastlen;
unsigned char quality, signal;
u8 rate;
u32 *tmp, *tmp2;
u8 rx_desc_size;
u8 padding;
char rxpower = 0;
u32 RXAGC = 0;
long RxAGC_dBm = 0;
u8 LNA = 0, BB = 0;
u8 LNA_gain[4] = {02, 17, 29, 39};
u8 Antenna = 0;
struct ieee80211_hdr_4addr *hdr;
u16 fc, type;
u8 bHwError = 0, bCRC = 0, bICV = 0;
bool bCckRate = false;
u8 RSSI = 0;
long SignalStrengthIndex = 0;
struct ieee80211_rx_stats stats = {
.signal = 0,
.noise = -98,
.rate = 0,
.freq = IEEE80211_24GHZ_BAND,
};
stats.nic_type = NIC_8185B;
rx_desc_size = 8;
if ((*(priv->rxringtail)) & (1<<31)) {
priv->stats.rxnodata++;
priv->ieee80211->stats.rx_errors++;
tmp2 = NULL;
tmp = priv->rxringtail;
do {
if (tmp == priv->rxring)
tmp = priv->rxring + (priv->rxringcount - 1)*rx_desc_size;
else
tmp -= rx_desc_size;
if (!(*tmp & (1<<31)))
tmp2 = tmp;
} while (tmp != priv->rxring);
if (tmp2)
priv->rxringtail = tmp2;
}
while (!(*(priv->rxringtail) & (1<<31))) {
if (*(priv->rxringtail) & (1<<26))
DMESGW("RX buffer overflow");
if (*(priv->rxringtail) & (1<<12))
priv->stats.rxicverr++;
if (*(priv->rxringtail) & (1<<27)) {
priv->stats.rxdmafail++;
goto drop;
}
pci_dma_sync_single_for_cpu(priv->pdev,
priv->rxbuffer->dma,
priv->rxbuffersize * \
sizeof(u8),
PCI_DMA_FROMDEVICE);
first = *(priv->rxringtail) & (1<<29) ? 1 : 0;
if (first)
priv->rx_prevlen = 0;
last = *(priv->rxringtail) & (1<<28) ? 1 : 0;
if (last) {
lastlen = ((*priv->rxringtail) & 0xfff);
if (lastlen < priv->rx_prevlen)
len = 0;
else
len = lastlen-priv->rx_prevlen;
if (*(priv->rxringtail) & (1<<13)) {
if ((*(priv->rxringtail) & 0xfff) < 500)
priv->stats.rxcrcerrmin++;
else if ((*(priv->rxringtail) & 0x0fff) > 1000)
priv->stats.rxcrcerrmax++;
else
priv->stats.rxcrcerrmid++;
}
} else {
len = priv->rxbuffersize;
}
if (first && last) {
padding = ((*(priv->rxringtail+3))&(0x04000000))>>26;
} else if (first) {
padding = ((*(priv->rxringtail+3))&(0x04000000))>>26;
if (padding)
len -= 2;
} else {
padding = 0;
}
padding = 0;
priv->rx_prevlen += len;
if (priv->rx_prevlen > MAX_FRAG_THRESHOLD + 100) {
if (!priv->rx_skb_complete)
dev_kfree_skb_any(priv->rx_skb);
priv->rx_skb_complete = 1;
}
signal = (unsigned char)(((*(priv->rxringtail+3)) & (0x00ff0000))>>16);
signal = (signal & 0xfe) >> 1;
quality = (unsigned char)((*(priv->rxringtail+3)) & (0xff));
stats.mac_time[0] = *(priv->rxringtail+1);
stats.mac_time[1] = *(priv->rxringtail+2);
rxpower = ((char)(((*(priv->rxringtail+4)) & (0x00ff0000))>>16))/2 - 42;
RSSI = ((u8)(((*(priv->rxringtail+3)) & (0x0000ff00))>>8)) & (0x7f);
rate = ((*(priv->rxringtail)) &
((1<<23)|(1<<22)|(1<<21)|(1<<20)))>>20;
stats.rate = rtl8180_rate2rate(rate);
Antenna = (((*(priv->rxringtail+3)) & (0x00008000)) == 0) ? 0 : 1;
if (!rtl8180_IsWirelessBMode(stats.rate)) {
RxAGC_dBm = rxpower+1;
} else {
RxAGC_dBm = signal;
LNA = (u8) (RxAGC_dBm & 0x60) >> 5;
BB = (u8) (RxAGC_dBm & 0x1F);
RxAGC_dBm = -(LNA_gain[LNA] + (BB*2));
RxAGC_dBm += 4;
}
if (RxAGC_dBm & 0x80)
RXAGC = ~(RxAGC_dBm)+1;
bCckRate = rtl8180_IsWirelessBMode(stats.rate);
if (!rtl8180_IsWirelessBMode(stats.rate)) {
if (RXAGC > 90)
RXAGC = 90;
else if (RXAGC < 25)
RXAGC = 25;
RXAGC = (90-RXAGC)*100/65;
} else {
if (RXAGC > 95)
RXAGC = 95;
else if (RXAGC < 30)
RXAGC = 30;
RXAGC = (95-RXAGC)*100/65;
}
priv->SignalStrength = (u8)RXAGC;
priv->RecvSignalPower = RxAGC_dBm;
priv->RxPower = rxpower;
priv->RSSI = RSSI;
if (quality >= 127)
quality = 1;
else if (quality < 27)
quality = 100;
else
quality = 127 - quality;
priv->SignalQuality = quality;
stats.signal = (u8)quality;
stats.signalstrength = RXAGC;
if (stats.signalstrength > 100)
stats.signalstrength = 100;
stats.signalstrength = (stats.signalstrength * 70)/100 + 30;
stats.rssi = priv->wstats.qual.qual = priv->SignalQuality;
stats.noise = priv->wstats.qual.noise = 100 - priv->wstats.qual.qual;
bHwError = (((*(priv->rxringtail)) & (0x00000fff)) == 4080) | (((*(priv->rxringtail)) & (0x04000000)) != 0)
| (((*(priv->rxringtail)) & (0x08000000)) != 0) | (((~(*(priv->rxringtail))) & (0x10000000)) != 0) | (((~(*(priv->rxringtail))) & (0x20000000)) != 0);
bCRC = ((*(priv->rxringtail)) & (0x00002000)) >> 13;
bICV = ((*(priv->rxringtail)) & (0x00001000)) >> 12;
hdr = (struct ieee80211_hdr_4addr *)priv->rxbuffer->buf;
fc = le16_to_cpu(hdr->frame_ctl);
type = WLAN_FC_GET_TYPE(fc);
if ((IEEE80211_FTYPE_CTL != type) &&
(eqMacAddr(priv->ieee80211->current_network.bssid, (fc & IEEE80211_FCTL_TODS) ? hdr->addr1 : (fc & IEEE80211_FCTL_FROMDS) ? hdr->addr2 : hdr->addr3))
&& (!bHwError) && (!bCRC) && (!bICV)) {
PerformUndecoratedSignalSmoothing8185(priv, bCckRate);
SignalStrengthIndex = NetgearSignalStrengthTranslate(
priv->LastSignalStrengthInPercent,
priv->SignalStrength);
priv->LastSignalStrengthInPercent = SignalStrengthIndex;
priv->Stats_SignalStrength = TranslateToDbm8185((u8)SignalStrengthIndex);
priv->Stats_SignalQuality = (long)(priv->Stats_SignalQuality * 5 + (long)priv->SignalQuality + 5) / 6;
priv->Stats_RecvSignalPower = (long)(priv->Stats_RecvSignalPower * 5 + priv->RecvSignalPower - 1) / 6;
priv->LastRxPktAntenna = Antenna ? 1 : 0;
SwAntennaDiversityRxOk8185(dev, priv->SignalStrength);
}
if (first) {
if (!priv->rx_skb_complete) {
dev_kfree_skb_any(priv->rx_skb);
priv->stats.rxnolast++;
}
if (priv->prism_hdr && priv->ieee80211->iw_mode == IW_MODE_MONITOR) {
} else {
priv->rx_skb = dev_alloc_skb(len+2);
if (!priv->rx_skb)
goto drop;
}
priv->rx_skb_complete = 0;
priv->rx_skb->dev = dev;
} else {
if (!priv->rx_skb_complete) {
tmp_skb = dev_alloc_skb(priv->rx_skb->len+len+2);
if (!tmp_skb)
goto drop;
tmp_skb->dev = dev;
memcpy(skb_put(tmp_skb, priv->rx_skb->len),
priv->rx_skb->data,
priv->rx_skb->len);
dev_kfree_skb_any(priv->rx_skb);
priv->rx_skb = tmp_skb;
}
}
if (!priv->rx_skb_complete) {
if (padding) {
memcpy(skb_put(priv->rx_skb, len),
(((unsigned char *)priv->rxbuffer->buf) + 2), len);
} else {
memcpy(skb_put(priv->rx_skb, len),
priv->rxbuffer->buf, len);
}
}
if (last && !priv->rx_skb_complete) {
if (priv->rx_skb->len > 4)
skb_trim(priv->rx_skb, priv->rx_skb->len-4);
if (!ieee80211_rtl_rx(priv->ieee80211,
priv->rx_skb, &stats))
dev_kfree_skb_any(priv->rx_skb);
priv->rx_skb_complete = 1;
}
pci_dma_sync_single_for_device(priv->pdev,
priv->rxbuffer->dma,
priv->rxbuffersize * \
sizeof(u8),
PCI_DMA_FROMDEVICE);
drop:
*(priv->rxringtail+2) = priv->rxbuffer->dma;
*(priv->rxringtail) = *(priv->rxringtail) & ~0xfff;
*(priv->rxringtail) =
*(priv->rxringtail) | priv->rxbuffersize;
*(priv->rxringtail) =
*(priv->rxringtail) | (1<<31);
priv->rxringtail += rx_desc_size;
if (priv->rxringtail >=
(priv->rxring)+(priv->rxringcount)*rx_desc_size)
priv->rxringtail = priv->rxring;
priv->rxbuffer = (priv->rxbuffer->next);
}
}
void rtl8180_dma_kick(struct net_device *dev, int priority)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_byte(dev, TX_DMA_POLLING,
(1 << (priority + 1)) | priv->dma_poll_mask);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
force_pci_posting(dev);
}
void rtl8180_data_hard_stop(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
priv->dma_poll_stop_mask |= TPPOLLSTOP_AC_VIQ;
write_nic_byte(dev, TPPollStop, priv->dma_poll_stop_mask);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8180_data_hard_resume(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
priv->dma_poll_stop_mask &= ~(TPPOLLSTOP_AC_VIQ);
write_nic_byte(dev, TPPollStop, priv->dma_poll_stop_mask);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8180_hard_data_xmit(struct sk_buff *skb, struct net_device *dev, int
rate) {
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
int mode;
struct ieee80211_hdr_3addr *h = (struct ieee80211_hdr_3addr *) skb->data;
short morefrag = (h->frame_control) & IEEE80211_FCTL_MOREFRAGS;
unsigned long flags;
int priority;
mode = priv->ieee80211->iw_mode;
rate = ieeerate2rtlrate(rate);
priority = AC2Q(skb->priority);
spin_lock_irqsave(&priv->tx_lock, flags);
if (priv->ieee80211->bHwRadioOff) {
spin_unlock_irqrestore(&priv->tx_lock, flags);
return;
}
if (!check_nic_enought_desc(dev, priority)) {
DMESGW("Error: no descriptor left by previous TX (avail %d) ",
get_curr_tx_free_desc(dev, priority));
ieee80211_rtl_stop_queue(priv->ieee80211);
}
rtl8180_tx(dev, skb->data, skb->len, priority, morefrag, 0, rate);
if (!check_nic_enought_desc(dev, priority))
ieee80211_rtl_stop_queue(priv->ieee80211);
spin_unlock_irqrestore(&priv->tx_lock, flags);
}
int rtl8180_hard_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
unsigned long flags;
int priority;
priority = MANAGE_PRIORITY;
spin_lock_irqsave(&priv->tx_lock, flags);
if (priv->ieee80211->bHwRadioOff) {
spin_unlock_irqrestore(&priv->tx_lock, flags);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
rtl8180_tx(dev, skb->data, skb->len, priority,
0, 0, ieeerate2rtlrate(priv->ieee80211->basic_rate));
priv->ieee80211->stats.tx_bytes += skb->len;
priv->ieee80211->stats.tx_packets++;
spin_unlock_irqrestore(&priv->tx_lock, flags);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
u16 rtl8180_len2duration(u32 len, short rate, short *ext)
{
u16 duration;
u16 drift;
*ext = 0;
switch (rate) {
case 0:
*ext = 0;
duration = ((len+4)<<4) / 0x2;
drift = ((len+4)<<4) % 0x2;
if (drift == 0)
break;
duration++;
break;
case 1:
*ext = 0;
duration = ((len+4)<<4) / 0x4;
drift = ((len+4)<<4) % 0x4;
if (drift == 0)
break;
duration++;
break;
case 2:
*ext = 0;
duration = ((len+4)<<4) / 0xb;
drift = ((len+4)<<4) % 0xb;
if (drift == 0)
break;
duration++;
break;
default:
case 3:
*ext = 0;
duration = ((len+4)<<4) / 0x16;
drift = ((len+4)<<4) % 0x16;
if (drift == 0)
break;
duration++;
if (drift > 6)
break;
*ext = 1;
break;
}
return duration;
}
void rtl8180_prepare_beacon(struct net_device *dev)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct sk_buff *skb;
u16 word = read_nic_word(dev, BcnItv);
word &= ~BcnItv_BcnItv;
word |= cpu_to_le16(priv->ieee80211->current_network.beacon_interval);
write_nic_word(dev, BcnItv, word);
skb = ieee80211_get_beacon(priv->ieee80211);
if (skb) {
rtl8180_tx(dev, skb->data, skb->len, BEACON_PRIORITY,
0, 0, ieeerate2rtlrate(priv->ieee80211->basic_rate));
dev_kfree_skb_any(skb);
}
}
short rtl8180_tx(struct net_device *dev, u8* txbuf, int len, int priority,
short morefrag, short descfrag, int rate)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u32 *tail, *temp_tail;
u32 *begin;
u32 *buf;
int i;
int remain;
int buflen;
int count;
u16 duration;
short ext;
struct buffer *buflist;
struct ieee80211_hdr_3addr *frag_hdr = (struct ieee80211_hdr_3addr *)txbuf;
u8 dest[ETH_ALEN];
u8 bUseShortPreamble = 0;
u8 bCTSEnable = 0;
u8 bRTSEnable = 0;
u16 Duration = 0;
u16 RtsDur = 0;
u16 ThisFrameTime = 0;
u16 TxDescDuration = 0;
u8 ownbit_flag = false;
switch (priority) {
case MANAGE_PRIORITY:
tail = priv->txmapringtail;
begin = priv->txmapring;
buflist = priv->txmapbufstail;
count = priv->txringcount;
break;
case BK_PRIORITY:
tail = priv->txbkpringtail;
begin = priv->txbkpring;
buflist = priv->txbkpbufstail;
count = priv->txringcount;
break;
case BE_PRIORITY:
tail = priv->txbepringtail;
begin = priv->txbepring;
buflist = priv->txbepbufstail;
count = priv->txringcount;
break;
case VI_PRIORITY:
tail = priv->txvipringtail;
begin = priv->txvipring;
buflist = priv->txvipbufstail;
count = priv->txringcount;
break;
case VO_PRIORITY:
tail = priv->txvopringtail;
begin = priv->txvopring;
buflist = priv->txvopbufstail;
count = priv->txringcount;
break;
case HI_PRIORITY:
tail = priv->txhpringtail;
begin = priv->txhpring;
buflist = priv->txhpbufstail;
count = priv->txringcount;
break;
case BEACON_PRIORITY:
tail = priv->txbeaconringtail;
begin = priv->txbeaconring;
buflist = priv->txbeaconbufstail;
count = priv->txbeaconcount;
break;
default:
return -1;
break;
}
memcpy(&dest, frag_hdr->addr1, ETH_ALEN);
if (is_multicast_ether_addr(dest) ||
is_broadcast_ether_addr(dest)) {
Duration = 0;
RtsDur = 0;
bRTSEnable = 0;
bCTSEnable = 0;
ThisFrameTime = ComputeTxTime(len + sCrcLng, rtl8180_rate2rate(rate), 0, bUseShortPreamble);
TxDescDuration = ThisFrameTime;
} else {
u16 AckTime;
priv->NumTxUnicast++;
AckTime = ComputeTxTime(14, 10, 0, 0);
if (((len + sCrcLng) > priv->rts) && priv->rts) {
u16 RtsTime, CtsTime;
bRTSEnable = 1;
bCTSEnable = 0;
RtsTime = ComputeTxTime(sAckCtsLng/8, priv->ieee80211->basic_rate, 0, 0);
CtsTime = ComputeTxTime(14, 10, 0, 0);
ThisFrameTime = ComputeTxTime(len + sCrcLng,
rtl8180_rate2rate(rate),
0,
bUseShortPreamble);
RtsDur = CtsTime + ThisFrameTime + AckTime + 3*aSifsTime;
TxDescDuration = RtsTime + RtsDur;
} else {
bCTSEnable = 0;
bRTSEnable = 0;
RtsDur = 0;
ThisFrameTime = ComputeTxTime(len + sCrcLng, rtl8180_rate2rate(rate), 0, bUseShortPreamble);
TxDescDuration = ThisFrameTime + aSifsTime + AckTime;
}
if (!(frag_hdr->frame_control & IEEE80211_FCTL_MOREFRAGS)) {
Duration = aSifsTime + AckTime;
} else {
u16 NextFragTime;
NextFragTime = ComputeTxTime(len + sCrcLng,
rtl8180_rate2rate(rate),
0,
bUseShortPreamble);
Duration = NextFragTime + 3*aSifsTime + 2*AckTime;
}
}
frag_hdr->duration_id = Duration;
buflen = priv->txbuffsize;
remain = len;
temp_tail = tail;
while (remain != 0) {
mb();
if (!buflist) {
DMESGE("TX buffer error, cannot TX frames. pri %d.", priority);
return -1;
}
buf = buflist->buf;
if ((*tail & (1 << 31)) && (priority != BEACON_PRIORITY)) {
DMESGW("No more TX desc, returning %x of %x",
remain, len);
priv->stats.txrdu++;
return remain;
}
*tail = 0;
*(tail+1) = 0;
*(tail+3) = 0;
*(tail+5) = 0;
*(tail+6) = 0;
*(tail+7) = 0;
*tail |= (1<<15);
if (remain == len && !descfrag) {
ownbit_flag = false;
*tail = *tail | (1<<29) ;
*tail = *tail | (len);
} else {
ownbit_flag = true;
}
for (i = 0; i < buflen && remain > 0; i++, remain--) {
((u8 *)buf)[i] = txbuf[i];
if (remain == 4 && i+4 >= buflen)
break;
}
txbuf = txbuf + i;
*(tail+3) = *(tail+3) & ~0xfff;
*(tail+3) = *(tail+3) | i;
if (priv->ieee80211->current_network.capability&WLAN_CAPABILITY_SHORT_PREAMBLE)
if (priv->plcp_preamble_mode == 1 && rate != 0)
;
if (bCTSEnable)
*tail |= (1<<18);
if (bRTSEnable) {
*tail |= ((ieeerate2rtlrate(priv->ieee80211->basic_rate))<<19);
*tail |= (1<<23);
*(tail+1) |= (RtsDur&0xffff);
}
*(tail+3) |= ((TxDescDuration&0xffff)<<16);
*(tail+5) |= (11<<8);
*tail = *tail | ((rate&0xf) << 24);
if (!priv->hw_plcp_len) {
duration = rtl8180_len2duration(len, rate, &ext);
*(tail+1) = *(tail+1) | ((duration & 0x7fff)<<16);
if (ext)
*(tail+1) = *(tail+1) | (1<<31);
}
if (morefrag)
*tail = (*tail) | (1<<17);
if (!remain)
*tail = (*tail) | (1<<28);
*(tail+5) = *(tail+5)|(2<<27);
*(tail+7) = *(tail+7)|(1<<4);
wmb();
if (ownbit_flag)
*tail = *tail | (1<<31);
if ((tail - begin)/8 == count-1)
tail = begin;
else
tail = tail+8;
buflist = buflist->next;
mb();
switch (priority) {
case MANAGE_PRIORITY:
priv->txmapringtail = tail;
priv->txmapbufstail = buflist;
break;
case BK_PRIORITY:
priv->txbkpringtail = tail;
priv->txbkpbufstail = buflist;
break;
case BE_PRIORITY:
priv->txbepringtail = tail;
priv->txbepbufstail = buflist;
break;
case VI_PRIORITY:
priv->txvipringtail = tail;
priv->txvipbufstail = buflist;
break;
case VO_PRIORITY:
priv->txvopringtail = tail;
priv->txvopbufstail = buflist;
break;
case HI_PRIORITY:
priv->txhpringtail = tail;
priv->txhpbufstail = buflist;
break;
case BEACON_PRIORITY:
break;
}
}
*temp_tail = *temp_tail | (1<<31);
rtl8180_dma_kick(dev, priority);
return 0;
}
void rtl8180_link_change(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u16 beacon_interval;
struct ieee80211_network *net = &priv->ieee80211->current_network;
rtl8180_update_msr(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_dword(dev, BSSID, ((u32 *)net->bssid)[0]);
write_nic_word(dev, BSSID+4, ((u16 *)net->bssid)[2]);
beacon_interval = read_nic_dword(dev, BEACON_INTERVAL);
beacon_interval &= ~BEACON_INTERVAL_MASK;
beacon_interval |= net->beacon_interval;
write_nic_dword(dev, BEACON_INTERVAL, beacon_interval);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
rtl8180_set_chan(dev, priv->chan);
}
void rtl8180_rq_tx_ack(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
write_nic_byte(dev, CONFIG4, read_nic_byte(dev, CONFIG4) | CONFIG4_PWRMGT);
priv->ack_tx_to_ieee = 1;
}
short rtl8180_is_tx_queue_empty(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u32 *d;
for (d = priv->txmapring;
d < priv->txmapring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
for (d = priv->txbkpring;
d < priv->txbkpring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
for (d = priv->txbepring;
d < priv->txbepring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
for (d = priv->txvipring;
d < priv->txvipring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
for (d = priv->txvopring;
d < priv->txvopring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
for (d = priv->txhpring;
d < priv->txhpring + priv->txringcount; d += 8)
if (*d & (1<<31))
return 0;
return 1;
}
void rtl8180_hw_wakeup(struct net_device *dev)
{
unsigned long flags;
struct r8180_priv *priv = ieee80211_priv(dev);
spin_lock_irqsave(&priv->ps_lock, flags);
write_nic_byte(dev, CONFIG4, read_nic_byte(dev, CONFIG4) & ~CONFIG4_PWRMGT);
if (priv->rf_wakeup)
priv->rf_wakeup(dev);
spin_unlock_irqrestore(&priv->ps_lock, flags);
}
void rtl8180_hw_sleep_down(struct net_device *dev)
{
unsigned long flags;
struct r8180_priv *priv = ieee80211_priv(dev);
spin_lock_irqsave(&priv->ps_lock, flags);
if (priv->rf_sleep)
priv->rf_sleep(dev);
spin_unlock_irqrestore(&priv->ps_lock, flags);
}
void rtl8180_hw_sleep(struct net_device *dev, u32 th, u32 tl)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u32 rb = jiffies;
unsigned long flags;
spin_lock_irqsave(&priv->ps_lock, flags);
tl -= MSECS(4+16+7);
if (((tl >= rb) && (tl-rb) <= MSECS(MIN_SLEEP_TIME))
|| ((rb > tl) && (rb-tl) < MSECS(MIN_SLEEP_TIME))) {
spin_unlock_irqrestore(&priv->ps_lock, flags);
printk("too short to sleep\n");
return;
}
{
u32 tmp = (tl > rb) ? (tl-rb) : (rb-tl);
priv->DozePeriodInPast2Sec += jiffies_to_msecs(tmp);
queue_delayed_work(priv->ieee80211->wq, &priv->ieee80211->hw_wakeup_wq, tmp);
}
if (((tl > rb) && ((tl-rb) > MSECS(MAX_SLEEP_TIME))) ||
((tl < rb) && ((rb-tl) > MSECS(MAX_SLEEP_TIME)))) {
spin_unlock_irqrestore(&priv->ps_lock, flags);
return;
}
queue_work(priv->ieee80211->wq, (void *)&priv->ieee80211->hw_sleep_wq);
spin_unlock_irqrestore(&priv->ps_lock, flags);
}
void rtl8180_wmm_param_update(struct work_struct *work)
{
struct ieee80211_device *ieee = container_of(work, struct ieee80211_device, wmm_param_update_wq);
struct net_device *dev = ieee->dev;
u8 *ac_param = (u8 *)(ieee->current_network.wmm_param);
u8 mode = ieee->current_network.mode;
AC_CODING eACI;
AC_PARAM AcParam;
PAC_PARAM pAcParam;
u8 i;
if (!ieee->current_network.QoS_Enable) {
AcParam.longData = 0;
AcParam.f.AciAifsn.f.AIFSN = 2;
AcParam.f.AciAifsn.f.ACM = 0;
AcParam.f.Ecw.f.ECWmin = 3;
AcParam.f.Ecw.f.ECWmax = 7;
AcParam.f.TXOPLimit = 0;
for (eACI = 0; eACI < AC_MAX; eACI++) {
AcParam.f.AciAifsn.f.ACI = (u8)eACI;
{
u8 u1bAIFS;
u32 u4bAcParam;
pAcParam = (PAC_PARAM)(&AcParam);
u1bAIFS = pAcParam->f.AciAifsn.f.AIFSN * (((mode&IEEE_G) == IEEE_G) ? 9 : 20) + aSifsTime;
u4bAcParam = ((((u32)(pAcParam->f.TXOPLimit))<<AC_PARAM_TXOP_LIMIT_OFFSET)|
(((u32)(pAcParam->f.Ecw.f.ECWmax))<<AC_PARAM_ECW_MAX_OFFSET)|
(((u32)(pAcParam->f.Ecw.f.ECWmin))<<AC_PARAM_ECW_MIN_OFFSET)|
(((u32)u1bAIFS) << AC_PARAM_AIFS_OFFSET));
switch (eACI) {
case AC1_BK:
write_nic_dword(dev, AC_BK_PARAM, u4bAcParam);
break;
case AC0_BE:
write_nic_dword(dev, AC_BE_PARAM, u4bAcParam);
break;
case AC2_VI:
write_nic_dword(dev, AC_VI_PARAM, u4bAcParam);
break;
case AC3_VO:
write_nic_dword(dev, AC_VO_PARAM, u4bAcParam);
break;
default:
printk(KERN_WARNING "SetHwReg8185():invalid ACI: %d!\n", eACI);
break;
}
}
}
return;
}
for (i = 0; i < AC_MAX; i++) {
pAcParam = (AC_PARAM *)ac_param;
{
AC_CODING eACI;
u8 u1bAIFS;
u32 u4bAcParam;
eACI = pAcParam->f.AciAifsn.f.ACI;
u1bAIFS = pAcParam->f.AciAifsn.f.AIFSN * (((mode&IEEE_G) == IEEE_G) ? 9 : 20) + aSifsTime;
u4bAcParam = ((((u32)(pAcParam->f.TXOPLimit)) << AC_PARAM_TXOP_LIMIT_OFFSET) |
(((u32)(pAcParam->f.Ecw.f.ECWmax)) << AC_PARAM_ECW_MAX_OFFSET) |
(((u32)(pAcParam->f.Ecw.f.ECWmin)) << AC_PARAM_ECW_MIN_OFFSET) |
(((u32)u1bAIFS) << AC_PARAM_AIFS_OFFSET));
switch (eACI) {
case AC1_BK:
write_nic_dword(dev, AC_BK_PARAM, u4bAcParam);
break;
case AC0_BE:
write_nic_dword(dev, AC_BE_PARAM, u4bAcParam);
break;
case AC2_VI:
write_nic_dword(dev, AC_VI_PARAM, u4bAcParam);
break;
case AC3_VO:
write_nic_dword(dev, AC_VO_PARAM, u4bAcParam);
break;
default:
printk(KERN_WARNING "SetHwReg8185(): invalid ACI: %d !\n", eACI);
break;
}
}
ac_param += (sizeof(AC_PARAM));
}
}
void watch_dog_adaptive(unsigned long data)
{
struct r8180_priv* priv = ieee80211_priv((struct net_device *)data);
if (!priv->up) {
DMESG("<----watch_dog_adaptive():driver is not up!\n");
return;
}
if (CheckHighPower((struct net_device *)data))
queue_work(priv->ieee80211->wq, (void *)&priv->ieee80211->tx_pw_wq);
if (CheckTxPwrTracking((struct net_device *)data))
TxPwrTracking87SE((struct net_device *)data);
if (CheckDig((struct net_device *)data) == true)
queue_work(priv->ieee80211->wq, (void *)&priv->ieee80211->hw_dig_wq);
rtl8180_watch_dog((struct net_device *)data);
queue_work(priv->ieee80211->wq, (void *)&priv->ieee80211->GPIOChangeRFWorkItem);
priv->watch_dog_timer.expires = jiffies + MSECS(IEEE80211_WATCH_DOG_TIME);
add_timer(&priv->watch_dog_timer);
}
static void rtl8180_set_channel_map(u8 channel_plan, struct ieee80211_device *ieee)
{
int i;
ieee->MinPassiveChnlNum = MAX_CHANNEL_NUMBER+1;
ieee->IbssStartChnl = 0;
switch (channel_plan) {
case COUNTRY_CODE_FCC:
case COUNTRY_CODE_IC:
case COUNTRY_CODE_ETSI:
case COUNTRY_CODE_SPAIN:
case COUNTRY_CODE_FRANCE:
case COUNTRY_CODE_MKK:
case COUNTRY_CODE_MKK1:
case COUNTRY_CODE_ISRAEL:
case COUNTRY_CODE_TELEC:
{
Dot11d_Init(ieee);
ieee->bGlobalDomain = false;
if (ChannelPlan[channel_plan].Len != 0) {
memset(GET_DOT11D_INFO(ieee)->channel_map, 0, sizeof(GET_DOT11D_INFO(ieee)->channel_map));
for (i = 0; i < ChannelPlan[channel_plan].Len; i++) {
if (ChannelPlan[channel_plan].Channel[i] <= 14)
GET_DOT11D_INFO(ieee)->channel_map[ChannelPlan[channel_plan].Channel[i]] = 1;
}
}
break;
}
case COUNTRY_CODE_GLOBAL_DOMAIN:
{
GET_DOT11D_INFO(ieee)->bEnabled = 0;
Dot11d_Reset(ieee);
ieee->bGlobalDomain = true;
break;
}
case COUNTRY_CODE_WORLD_WIDE_13_INDEX:
{
ieee->MinPassiveChnlNum = 12;
ieee->IbssStartChnl = 10;
break;
}
default:
{
Dot11d_Init(ieee);
ieee->bGlobalDomain = false;
memset(GET_DOT11D_INFO(ieee)->channel_map, 0, sizeof(GET_DOT11D_INFO(ieee)->channel_map));
for (i = 1; i <= 14; i++)
GET_DOT11D_INFO(ieee)->channel_map[i] = 1;
break;
}
}
}
static void rtl8180_statistics_init(struct Stats *pstats)
{
memset(pstats, 0, sizeof(struct Stats));
}
static void rtl8180_link_detect_init(plink_detect_t plink_detect)
{
memset(plink_detect, 0, sizeof(link_detect_t));
plink_detect->SlotNum = DEFAULT_SLOT_NUM;
}
static void rtl8187se_eeprom_register_read(struct eeprom_93cx6 *eeprom)
{
struct net_device *dev = eeprom->data;
u8 reg = read_nic_byte(dev, EPROM_CMD);
eeprom->reg_data_in = reg & RTL818X_EEPROM_CMD_WRITE;
eeprom->reg_data_out = reg & RTL818X_EEPROM_CMD_READ;
eeprom->reg_data_clock = reg & RTL818X_EEPROM_CMD_CK;
eeprom->reg_chip_select = reg & RTL818X_EEPROM_CMD_CS;
}
static void rtl8187se_eeprom_register_write(struct eeprom_93cx6 *eeprom)
{
struct net_device *dev = eeprom->data;
u8 reg = 2 << 6;
if (eeprom->reg_data_in)
reg |= RTL818X_EEPROM_CMD_WRITE;
if (eeprom->reg_data_out)
reg |= RTL818X_EEPROM_CMD_READ;
if (eeprom->reg_data_clock)
reg |= RTL818X_EEPROM_CMD_CK;
if (eeprom->reg_chip_select)
reg |= RTL818X_EEPROM_CMD_CS;
write_nic_byte(dev, EPROM_CMD, reg);
read_nic_byte(dev, EPROM_CMD);
udelay(10);
}
short rtl8180_init(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u16 word;
u16 version;
u32 usValue;
u16 tmpu16;
int i, j;
struct eeprom_93cx6 eeprom;
u16 eeprom_val;
eeprom.data = dev;
eeprom.register_read = rtl8187se_eeprom_register_read;
eeprom.register_write = rtl8187se_eeprom_register_write;
eeprom.width = PCI_EEPROM_WIDTH_93C46;
eeprom_93cx6_read(&eeprom, EEPROM_COUNTRY_CODE>>1, &eeprom_val);
priv->channel_plan = eeprom_val & 0xFF;
if (priv->channel_plan > COUNTRY_CODE_GLOBAL_DOMAIN) {
printk("rtl8180_init:Error channel plan! Set to default.\n");
priv->channel_plan = 0;
}
DMESG("Channel plan is %d\n", priv->channel_plan);
rtl8180_set_channel_map(priv->channel_plan, priv->ieee80211);
priv->txbuffsize = 2048;
priv->txringcount = 32;
priv->rxbuffersize = 2048;
priv->rxringcount = 64;
priv->txbeaconcount = 2;
priv->rx_skb_complete = 1;
priv->RFChangeInProgress = false;
priv->SetRFPowerStateInProgress = false;
priv->RFProgType = 0;
priv->bInHctTest = false;
priv->irq_enabled = 0;
rtl8180_statistics_init(&priv->stats);
rtl8180_link_detect_init(&priv->link_detect);
priv->ack_tx_to_ieee = 0;
priv->ieee80211->current_network.beacon_interval = DEFAULT_BEACONINTERVAL;
priv->ieee80211->iw_mode = IW_MODE_INFRA;
priv->ieee80211->softmac_features = IEEE_SOFTMAC_SCAN |
IEEE_SOFTMAC_ASSOCIATE | IEEE_SOFTMAC_PROBERQ |
IEEE_SOFTMAC_PROBERS | IEEE_SOFTMAC_TX_QUEUE;
priv->ieee80211->active_scan = 1;
priv->ieee80211->rate = 110;
priv->ieee80211->modulation = IEEE80211_CCK_MODULATION;
priv->ieee80211->host_encrypt = 1;
priv->ieee80211->host_decrypt = 1;
priv->ieee80211->sta_wake_up = rtl8180_hw_wakeup;
priv->ieee80211->ps_request_tx_ack = rtl8180_rq_tx_ack;
priv->ieee80211->enter_sleep_state = rtl8180_hw_sleep;
priv->ieee80211->ps_is_queue_empty = rtl8180_is_tx_queue_empty;
priv->hw_wep = hwwep;
priv->prism_hdr = 0;
priv->dev = dev;
priv->retry_rts = DEFAULT_RETRY_RTS;
priv->retry_data = DEFAULT_RETRY_DATA;
priv->RFChangeInProgress = false;
priv->SetRFPowerStateInProgress = false;
priv->RFProgType = 0;
priv->bInHctTest = false;
priv->bInactivePs = true;
priv->ieee80211->bInactivePs = priv->bInactivePs;
priv->bSwRfProcessing = false;
priv->eRFPowerState = eRfOff;
priv->RfOffReason = 0;
priv->LedStrategy = SW_LED_MODE0;
priv->TxPollingTimes = 0;
priv->bLeisurePs = true;
priv->dot11PowerSaveMode = eActive;
priv->AdMinCheckPeriod = 5;
priv->AdMaxCheckPeriod = 10;
priv->AdMaxRxSsThreshold = 30;
priv->AdRxSsThreshold = 20;
priv->AdCheckPeriod = priv->AdMinCheckPeriod;
priv->AdTickCount = 0;
priv->AdRxSignalStrength = -1;
priv->RegSwAntennaDiversityMechanism = 0;
priv->RegDefaultAntenna = 0;
priv->SignalStrength = 0;
priv->AdRxOkCnt = 0;
priv->CurrAntennaIndex = 0;
priv->AdRxSsBeforeSwitched = 0;
init_timer(&priv->SwAntennaDiversityTimer);
priv->SwAntennaDiversityTimer.data = (unsigned long)dev;
priv->SwAntennaDiversityTimer.function = (void *)SwAntennaDiversityTimerCallback;
priv->bDigMechanism = 1;
priv->InitialGain = 6;
priv->bXtalCalibration = false;
priv->XtalCal_Xin = 0;
priv->XtalCal_Xout = 0;
priv->bTxPowerTrack = false;
priv->ThermalMeter = 0;
priv->FalseAlarmRegValue = 0;
priv->RegDigOfdmFaUpTh = 0xc;
priv->DIG_NumberFallbackVote = 0;
priv->DIG_NumberUpgradeVote = 0;
priv->LastSignalStrengthInPercent = 0;
priv->Stats_SignalStrength = 0;
priv->LastRxPktAntenna = 0;
priv->SignalQuality = 0;
priv->Stats_SignalQuality = 0;
priv->RecvSignalPower = 0;
priv->Stats_RecvSignalPower = 0;
priv->AdMainAntennaRxOkCnt = 0;
priv->AdAuxAntennaRxOkCnt = 0;
priv->bHWAdSwitched = false;
priv->bRegHighPowerMechanism = true;
priv->RegHiPwrUpperTh = 77;
priv->RegHiPwrLowerTh = 75;
priv->RegRSSIHiPwrUpperTh = 70;
priv->RegRSSIHiPwrLowerTh = 20;
priv->bCurCCKPkt = false;
priv->UndecoratedSmoothedSS = -1;
priv->bToUpdateTxPwr = false;
priv->CurCCKRSSI = 0;
priv->RxPower = 0;
priv->RSSI = 0;
priv->NumTxOkTotal = 0;
priv->NumTxUnicast = 0;
priv->keepAliveLevel = DEFAULT_KEEP_ALIVE_LEVEL;
priv->PowerProfile = POWER_PROFILE_AC;
priv->CurrRetryCnt = 0;
priv->LastRetryCnt = 0;
priv->LastTxokCnt = 0;
priv->LastRxokCnt = 0;
priv->LastRetryRate = 0;
priv->bTryuping = 0;
priv->CurrTxRate = 0;
priv->CurrRetryRate = 0;
priv->TryupingCount = 0;
priv->TryupingCountNoData = 0;
priv->TryDownCountLowData = 0;
priv->LastTxOKBytes = 0;
priv->LastFailTxRate = 0;
priv->LastFailTxRateSS = 0;
priv->FailTxRateCount = 0;
priv->LastTxThroughput = 0;
priv->NumTxOkBytesTotal = 0;
priv->ForcedDataRate = 0;
priv->RegBModeGainStage = 1;
priv->promisc = (dev->flags & IFF_PROMISC) ? 1 : 0;
spin_lock_init(&priv->irq_lock);
spin_lock_init(&priv->irq_th_lock);
spin_lock_init(&priv->tx_lock);
spin_lock_init(&priv->ps_lock);
spin_lock_init(&priv->rf_ps_lock);
sema_init(&priv->wx_sem, 1);
sema_init(&priv->rf_state, 1);
INIT_WORK(&priv->reset_wq, (void *)rtl8180_restart_wq);
INIT_WORK(&priv->tx_irq_wq, (void *)rtl8180_tx_irq_wq);
INIT_DELAYED_WORK(&priv->ieee80211->hw_wakeup_wq,
(void *)rtl8180_hw_wakeup_wq);
INIT_DELAYED_WORK(&priv->ieee80211->hw_sleep_wq,
(void *)rtl8180_hw_sleep_wq);
INIT_WORK(&priv->ieee80211->wmm_param_update_wq,
(void *)rtl8180_wmm_param_update);
INIT_DELAYED_WORK(&priv->ieee80211->rate_adapter_wq,
(void *)rtl8180_rate_adapter);
INIT_DELAYED_WORK(&priv->ieee80211->hw_dig_wq,
(void *)rtl8180_hw_dig_wq);
INIT_DELAYED_WORK(&priv->ieee80211->tx_pw_wq,
(void *)rtl8180_tx_pw_wq);
INIT_DELAYED_WORK(&priv->ieee80211->GPIOChangeRFWorkItem,
(void *) GPIOChangeRFWorkItemCallBack);
tasklet_init(&priv->irq_rx_tasklet,
(void(*)(unsigned long)) rtl8180_irq_rx_tasklet,
(unsigned long)priv);
init_timer(&priv->watch_dog_timer);
priv->watch_dog_timer.data = (unsigned long)dev;
priv->watch_dog_timer.function = watch_dog_adaptive;
init_timer(&priv->rateadapter_timer);
priv->rateadapter_timer.data = (unsigned long)dev;
priv->rateadapter_timer.function = timer_rate_adaptive;
priv->RateAdaptivePeriod = RATE_ADAPTIVE_TIMER_PERIOD;
priv->bEnhanceTxPwr = false;
priv->ieee80211->softmac_hard_start_xmit = rtl8180_hard_start_xmit;
priv->ieee80211->set_chan = rtl8180_set_chan;
priv->ieee80211->link_change = rtl8180_link_change;
priv->ieee80211->softmac_data_hard_start_xmit = rtl8180_hard_data_xmit;
priv->ieee80211->data_hard_stop = rtl8180_data_hard_stop;
priv->ieee80211->data_hard_resume = rtl8180_data_hard_resume;
priv->ieee80211->init_wmmparam_flag = 0;
priv->ieee80211->start_send_beacons = rtl8180_start_tx_beacon;
priv->ieee80211->stop_send_beacons = rtl8180_beacon_tx_disable;
priv->ieee80211->fts = DEFAULT_FRAG_THRESHOLD;
priv->MWIEnable = 0;
priv->ShortRetryLimit = 7;
priv->LongRetryLimit = 7;
priv->EarlyRxThreshold = 7;
priv->CSMethod = (0x01 << 29);
priv->TransmitConfig = TCR_DurProcMode_OFFSET |
(7<<TCR_MXDMA_OFFSET) |
(priv->ShortRetryLimit<<TCR_SRL_OFFSET) |
(priv->LongRetryLimit<<TCR_LRL_OFFSET) |
(0 ? TCR_SAT : 0);
priv->ReceiveConfig = RCR_AMF | RCR_ADF | RCR_ACF |
RCR_AB | RCR_AM | RCR_APM |
(7<<RCR_MXDMA_OFFSET) |
(priv->EarlyRxThreshold<<RCR_FIFO_OFFSET) |
(priv->EarlyRxThreshold == 7 ?
RCR_ONLYERLPKT : 0);
priv->IntrMask = IMR_TMGDOK | IMR_TBDER | IMR_THPDER |
IMR_THPDER | IMR_THPDOK |
IMR_TVODER | IMR_TVODOK |
IMR_TVIDER | IMR_TVIDOK |
IMR_TBEDER | IMR_TBEDOK |
IMR_TBKDER | IMR_TBKDOK |
IMR_RDU |
IMR_RER | IMR_ROK |
IMR_RQoSOK;
priv->InitialGain = 6;
DMESG("MAC controller is a RTL8187SE b/g");
priv->phy_ver = 2;
priv->ieee80211->modulation |= IEEE80211_OFDM_MODULATION;
priv->ieee80211->short_slot = 1;
priv->enable_gpio0 = 0;
eeprom_93cx6_read(&eeprom, EEPROM_SW_REVD_OFFSET, &eeprom_val);
usValue = eeprom_val;
DMESG("usValue is 0x%x\n", usValue);
if ((usValue & EEPROM_SW_AD_MASK) != EEPROM_SW_AD_ENABLE)
priv->EEPROMSwAntennaDiversity = false;
else
priv->EEPROMSwAntennaDiversity = true;
if ((usValue & EEPROM_DEF_ANT_MASK) != EEPROM_DEF_ANT_1)
priv->EEPROMDefaultAntenna1 = false;
else
priv->EEPROMDefaultAntenna1 = true;
if (priv->RegSwAntennaDiversityMechanism == 0)
priv->bSwAntennaDiverity = priv->EEPROMSwAntennaDiversity;
else
priv->bSwAntennaDiverity = ((priv->RegSwAntennaDiversityMechanism == 1) ? false : true);
if (priv->RegDefaultAntenna == 0)
priv->bDefaultAntenna1 = priv->EEPROMDefaultAntenna1;
else
priv->bDefaultAntenna1 = ((priv->RegDefaultAntenna == 2) ? true : false);
priv->hw_plcp_len = 1;
priv->plcp_preamble_mode = 2;
if (RCR_9356SEL & read_nic_dword(dev, RCR))
priv->epromtype = EPROM_93c56;
else
priv->epromtype = EPROM_93c46;
eeprom_93cx6_multiread(&eeprom, 0x7, (__le16 *)
dev->dev_addr, 3);
for (i = 1, j = 0; i < 14; i += 2, j++) {
eeprom_93cx6_read(&eeprom, EPROM_TXPW_CH1_2 + j, &word);
priv->chtxpwr[i] = word & 0xff;
priv->chtxpwr[i+1] = (word & 0xff00)>>8;
}
for (i = 1, j = 0; i < 14; i += 2, j++) {
eeprom_93cx6_read(&eeprom, EPROM_TXPW_OFDM_CH1_2 + j, &word);
priv->chtxpwr_ofdm[i] = word & 0xff;
priv->chtxpwr_ofdm[i+1] = (word & 0xff00) >> 8;
}
eeprom_93cx6_read(&eeprom, EEPROM_RSV>>1, &tmpu16);
priv->XtalCal_Xout = tmpu16 & EEPROM_XTAL_CAL_XOUT_MASK;
priv->XtalCal_Xin = (tmpu16 & EEPROM_XTAL_CAL_XIN_MASK) >> 4;
if ((tmpu16 & EEPROM_XTAL_CAL_ENABLE) >> 12)
priv->bXtalCalibration = true;
priv->ThermalMeter = (u8)((tmpu16 & EEPROM_THERMAL_METER_MASK) >> 8);
if ((tmpu16 & EEPROM_THERMAL_METER_ENABLE) >> 13)
priv->bTxPowerTrack = true;
eeprom_93cx6_read(&eeprom, EPROM_TXPW_BASE, &word);
priv->cck_txpwr_base = word & 0xf;
priv->ofdm_txpwr_base = (word>>4) & 0xf;
eeprom_93cx6_read(&eeprom, EPROM_VERSION, &version);
DMESG("EEPROM version %x", version);
priv->rcr_csense = 3;
eeprom_93cx6_read(&eeprom, ENERGY_TRESHOLD, &eeprom_val);
priv->cs_treshold = (eeprom_val & 0xff00) >> 8;
eeprom_93cx6_read(&eeprom, RFCHIPID, &eeprom_val);
priv->rf_sleep = rtl8225z4_rf_sleep;
priv->rf_wakeup = rtl8225z4_rf_wakeup;
DMESGW("**PLEASE** REPORT SUCCESSFUL/UNSUCCESSFUL TO Realtek!");
priv->rf_close = rtl8225z2_rf_close;
priv->rf_init = rtl8225z2_rf_init;
priv->rf_set_chan = rtl8225z2_rf_set_chan;
priv->rf_set_sens = NULL;
if (0 != alloc_rx_desc_ring(dev, priv->rxbuffersize, priv->rxringcount))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_MANAGEPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_BKPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_BEPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_VIPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_VOPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txringcount,
TX_HIGHPRIORITY_RING_ADDR))
return -ENOMEM;
if (0 != alloc_tx_desc_ring(dev, priv->txbuffsize, priv->txbeaconcount,
TX_BEACON_RING_ADDR))
return -ENOMEM;
if (request_irq(dev->irq, (void *)rtl8180_interrupt, IRQF_SHARED, dev->name, dev)) {
DMESGE("Error allocating IRQ %d", dev->irq);
return -1;
} else {
priv->irq = dev->irq;
DMESG("IRQ %d", dev->irq);
}
return 0;
}
void rtl8180_no_hw_wep(struct net_device *dev)
{
}
void rtl8180_set_hw_wep(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u8 pgreg;
u8 security;
u32 key0_word4;
pgreg = read_nic_byte(dev, PGSELECT);
write_nic_byte(dev, PGSELECT, pgreg & ~(1<<PGSELECT_PG_SHIFT));
key0_word4 = read_nic_dword(dev, KEY0+4+4+4);
key0_word4 &= ~0xff;
key0_word4 |= priv->key0[3] & 0xff;
write_nic_dword(dev, KEY0, (priv->key0[0]));
write_nic_dword(dev, KEY0+4, (priv->key0[1]));
write_nic_dword(dev, KEY0+4+4, (priv->key0[2]));
write_nic_dword(dev, KEY0+4+4+4, (key0_word4));
security = read_nic_byte(dev, SECURITY);
security |= (1<<SECURITY_WEP_TX_ENABLE_SHIFT);
security |= (1<<SECURITY_WEP_RX_ENABLE_SHIFT);
security &= ~SECURITY_ENCRYP_MASK;
security |= (SECURITY_ENCRYP_104<<SECURITY_ENCRYP_SHIFT);
write_nic_byte(dev, SECURITY, security);
DMESG("key %x %x %x %x", read_nic_dword(dev, KEY0+4+4+4),
read_nic_dword(dev, KEY0+4+4), read_nic_dword(dev, KEY0+4),
read_nic_dword(dev, KEY0));
}
void rtl8185_rf_pins_enable(struct net_device *dev)
{
write_nic_word(dev, RFPinsEnable, 0x1fff);
}
void rtl8185_set_anaparam2(struct net_device *dev, u32 a)
{
u8 conf3;
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
conf3 = read_nic_byte(dev, CONFIG3);
write_nic_byte(dev, CONFIG3, conf3 | (1<<CONFIG3_ANAPARAM_W_SHIFT));
write_nic_dword(dev, ANAPARAM2, a);
conf3 = read_nic_byte(dev, CONFIG3);
write_nic_byte(dev, CONFIG3, conf3 & ~(1<<CONFIG3_ANAPARAM_W_SHIFT));
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8180_set_anaparam(struct net_device *dev, u32 a)
{
u8 conf3;
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
conf3 = read_nic_byte(dev, CONFIG3);
write_nic_byte(dev, CONFIG3, conf3 | (1<<CONFIG3_ANAPARAM_W_SHIFT));
write_nic_dword(dev, ANAPARAM, a);
conf3 = read_nic_byte(dev, CONFIG3);
write_nic_byte(dev, CONFIG3, conf3 & ~(1<<CONFIG3_ANAPARAM_W_SHIFT));
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
}
void rtl8185_tx_antenna(struct net_device *dev, u8 ant)
{
write_nic_byte(dev, TX_ANTENNA, ant);
force_pci_posting(dev);
mdelay(1);
}
void rtl8185_write_phy(struct net_device *dev, u8 adr, u32 data)
{
u32 phyw;
adr |= 0x80;
phyw = ((data<<8) | adr);
write_nic_byte(dev, 0x7f, ((phyw & 0xff000000) >> 24));
write_nic_byte(dev, 0x7e, ((phyw & 0x00ff0000) >> 16));
write_nic_byte(dev, 0x7d, ((phyw & 0x0000ff00) >> 8));
write_nic_byte(dev, 0x7c, ((phyw & 0x000000ff)));
}
inline void write_phy_ofdm(struct net_device *dev, u8 adr, u32 data)
{
data = data & 0xff;
rtl8185_write_phy(dev, adr, data);
}
void write_phy_cck(struct net_device *dev, u8 adr, u32 data)
{
data = data & 0xff;
rtl8185_write_phy(dev, adr, data | 0x10000);
}
void rtl8185_set_rate(struct net_device *dev)
{
int i;
u16 word;
int basic_rate, min_rr_rate, max_rr_rate;
basic_rate = ieeerate2rtlrate(240);
min_rr_rate = ieeerate2rtlrate(60);
max_rr_rate = ieeerate2rtlrate(240);
write_nic_byte(dev, RESP_RATE,
max_rr_rate<<MAX_RESP_RATE_SHIFT | min_rr_rate<<MIN_RESP_RATE_SHIFT);
word = read_nic_word(dev, BRSR);
word &= ~BRSR_MBR_8185;
for (i = 0; i <= basic_rate; i++)
word |= (1<<i);
write_nic_word(dev, BRSR, word);
}
void rtl8180_adapter_start(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
rtl8180_rtx_disable(dev);
rtl8180_reset(dev);
priv->irq_mask = 0x6fcf;
priv->dma_poll_mask = 0;
rtl8180_beacon_tx_disable(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_dword(dev, MAC0, ((u32 *)dev->dev_addr)[0]);
write_nic_word(dev, MAC4, ((u32 *)dev->dev_addr)[1] & 0xffff);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
rtl8180_update_msr(dev);
fix_rx_fifo(dev);
fix_tx_fifo(dev);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_byte(dev,
CONFIG2, read_nic_byte(dev, CONFIG2) & ~\
(1<<CONFIG2_DMA_POLLING_MODE_SHIFT));
write_nic_byte(dev,
CONFIG2, read_nic_byte(dev, CONFIG2)|(1<<4));
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
write_nic_dword(dev, INT_TIMEOUT, 0);
write_nic_byte(dev, WPA_CONFIG, 0);
rtl8180_no_hw_wep(dev);
rtl8185_set_rate(dev);
write_nic_byte(dev, RATE_FALLBACK, 0x81);
write_nic_byte(dev, GP_ENABLE, read_nic_byte(dev, GP_ENABLE) & ~(1<<6));
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_byte(dev, CONFIG3, read_nic_byte(dev, CONFIG3)
| (1 << CONFIG3_CLKRUN_SHIFT));
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
priv->rf_init(dev);
if (priv->rf_set_sens != NULL)
priv->rf_set_sens(dev, priv->sens);
rtl8180_irq_enable(dev);
netif_start_queue(dev);
}
void rtl8180_start_tx_beacon(struct net_device *dev)
{
u16 word;
DMESG("Enabling beacon TX");
rtl8180_prepare_beacon(dev);
rtl8180_irq_disable(dev);
rtl8180_beacon_tx_enable(dev);
word = read_nic_word(dev, AtimWnd) & ~AtimWnd_AtimWnd;
write_nic_word(dev, AtimWnd, word);
word = read_nic_word(dev, BintrItv);
word &= ~BintrItv_BintrItv;
word |= 1000;
write_nic_word(dev, BintrItv, word);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
rtl8185b_irq_enable(dev);
}
static struct net_device_stats *rtl8180_stats(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return &priv->ieee80211->stats;
}
bool
MgntActSet_802_11_PowerSaveMode(
struct r8180_priv *priv,
RT_PS_MODE rtPsMode
)
{
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
return false;
priv->ieee80211->ps = rtPsMode;
return true;
}
void LeisurePSEnter(struct r8180_priv *priv)
{
if (priv->bLeisurePs) {
if (priv->ieee80211->ps == IEEE80211_PS_DISABLED)
MgntActSet_802_11_PowerSaveMode(priv, IEEE80211_PS_MBCAST|IEEE80211_PS_UNICAST);
}
}
void LeisurePSLeave(struct r8180_priv *priv)
{
if (priv->bLeisurePs) {
if (priv->ieee80211->ps != IEEE80211_PS_DISABLED)
MgntActSet_802_11_PowerSaveMode(priv, IEEE80211_PS_DISABLED);
}
}
void rtl8180_hw_wakeup_wq(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct ieee80211_device *ieee = container_of(dwork, struct ieee80211_device, hw_wakeup_wq);
struct net_device *dev = ieee->dev;
rtl8180_hw_wakeup(dev);
}
void rtl8180_hw_sleep_wq(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct ieee80211_device *ieee = container_of(dwork, struct ieee80211_device, hw_sleep_wq);
struct net_device *dev = ieee->dev;
rtl8180_hw_sleep_down(dev);
}
static void MgntLinkKeepAlive(struct r8180_priv *priv)
{
if (priv->keepAliveLevel == 0)
return;
if (priv->ieee80211->state == IEEE80211_LINKED) {
if ((priv->keepAliveLevel == 2) ||
(priv->link_detect.LastNumTxUnicast == priv->NumTxUnicast &&
priv->link_detect.LastNumRxUnicast == priv->ieee80211->NumRxUnicast)
) {
priv->link_detect.IdleCount++;
if (priv->link_detect.IdleCount >= ((KEEP_ALIVE_INTERVAL / CHECK_FOR_HANG_PERIOD)-1)) {
priv->link_detect.IdleCount = 0;
ieee80211_sta_ps_send_null_frame(priv->ieee80211, false);
}
} else {
priv->link_detect.IdleCount = 0;
}
priv->link_detect.LastNumTxUnicast = priv->NumTxUnicast;
priv->link_detect.LastNumRxUnicast = priv->ieee80211->NumRxUnicast;
}
}
void rtl8180_watch_dog(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
bool bEnterPS = false;
bool bBusyTraffic = false;
u32 TotalRxNum = 0;
u16 SlotIndex = 0;
u16 i = 0;
if (priv->ieee80211->actscanning == false) {
if ((priv->ieee80211->iw_mode != IW_MODE_ADHOC) && (priv->ieee80211->state == IEEE80211_NOLINK) && (priv->ieee80211->beinretry == false) && (priv->eRFPowerState == eRfOn))
IPSEnter(dev);
}
if ((priv->ieee80211->state == IEEE80211_LINKED) && (priv->ieee80211->iw_mode == IW_MODE_INFRA)) {
SlotIndex = (priv->link_detect.SlotIndex++) % priv->link_detect.SlotNum;
priv->link_detect.RxFrameNum[SlotIndex] = priv->ieee80211->NumRxDataInPeriod + priv->ieee80211->NumRxBcnInPeriod;
for (i = 0; i < priv->link_detect.SlotNum; i++)
TotalRxNum += priv->link_detect.RxFrameNum[i];
if (TotalRxNum == 0) {
priv->ieee80211->state = IEEE80211_ASSOCIATING;
queue_work(priv->ieee80211->wq, &priv->ieee80211->associate_procedure_wq);
}
}
MgntLinkKeepAlive(priv);
if (priv->PowerProfile == POWER_PROFILE_BATTERY)
priv->bLeisurePs = true;
else if (priv->PowerProfile == POWER_PROFILE_AC) {
LeisurePSLeave(priv);
priv->bLeisurePs = false;
}
if (priv->ieee80211->state == IEEE80211_LINKED) {
priv->link_detect.NumRxOkInPeriod = priv->ieee80211->NumRxDataInPeriod;
if (priv->link_detect.NumRxOkInPeriod > 666 ||
priv->link_detect.NumTxOkInPeriod > 666) {
bBusyTraffic = true;
}
if (((priv->link_detect.NumRxOkInPeriod + priv->link_detect.NumTxOkInPeriod) > 8)
|| (priv->link_detect.NumRxOkInPeriod > 2)) {
bEnterPS = false;
} else
bEnterPS = true;
if (bEnterPS)
LeisurePSEnter(priv);
else
LeisurePSLeave(priv);
} else
LeisurePSLeave(priv);
priv->link_detect.bBusyTraffic = bBusyTraffic;
priv->link_detect.NumRxOkInPeriod = 0;
priv->link_detect.NumTxOkInPeriod = 0;
priv->ieee80211->NumRxDataInPeriod = 0;
priv->ieee80211->NumRxBcnInPeriod = 0;
}
int _rtl8180_up(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
priv->up = 1;
DMESG("Bringing up iface");
rtl8185b_adapter_start(dev);
rtl8185b_rx_enable(dev);
rtl8185b_tx_enable(dev);
if (priv->bInactivePs) {
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
IPSLeave(dev);
}
timer_rate_adaptive((unsigned long)dev);
watch_dog_adaptive((unsigned long)dev);
if (priv->bSwAntennaDiverity)
SwAntennaDiversityTimerCallback(dev);
ieee80211_softmac_start_protocol(priv->ieee80211);
return 0;
}
int rtl8180_open(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
down(&priv->wx_sem);
ret = rtl8180_up(dev);
up(&priv->wx_sem);
return ret;
}
int rtl8180_up(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->up == 1)
return -1;
return _rtl8180_up(dev);
}
int rtl8180_close(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
down(&priv->wx_sem);
ret = rtl8180_down(dev);
up(&priv->wx_sem);
return ret;
}
int rtl8180_down(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->up == 0)
return -1;
priv->up = 0;
ieee80211_softmac_stop_protocol(priv->ieee80211);
if (!netif_queue_stopped(dev))
netif_stop_queue(dev);
rtl8180_rtx_disable(dev);
rtl8180_irq_disable(dev);
del_timer_sync(&priv->watch_dog_timer);
del_timer_sync(&priv->rateadapter_timer);
cancel_delayed_work(&priv->ieee80211->rate_adapter_wq);
cancel_delayed_work(&priv->ieee80211->hw_wakeup_wq);
cancel_delayed_work(&priv->ieee80211->hw_sleep_wq);
cancel_delayed_work(&priv->ieee80211->hw_dig_wq);
cancel_delayed_work(&priv->ieee80211->tx_pw_wq);
del_timer_sync(&priv->SwAntennaDiversityTimer);
SetZebraRFPowerState8185(dev, eRfOff);
memset(&(priv->ieee80211->current_network), 0, sizeof(struct ieee80211_network));
priv->ieee80211->state = IEEE80211_NOLINK;
return 0;
}
void rtl8180_restart_wq(struct work_struct *work)
{
struct r8180_priv *priv = container_of(work, struct r8180_priv, reset_wq);
struct net_device *dev = priv->dev;
down(&priv->wx_sem);
rtl8180_commit(dev);
up(&priv->wx_sem);
}
void rtl8180_restart(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
schedule_work(&priv->reset_wq);
}
void rtl8180_commit(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->up == 0)
return ;
del_timer_sync(&priv->watch_dog_timer);
del_timer_sync(&priv->rateadapter_timer);
cancel_delayed_work(&priv->ieee80211->rate_adapter_wq);
cancel_delayed_work(&priv->ieee80211->hw_wakeup_wq);
cancel_delayed_work(&priv->ieee80211->hw_sleep_wq);
cancel_delayed_work(&priv->ieee80211->hw_dig_wq);
cancel_delayed_work(&priv->ieee80211->tx_pw_wq);
del_timer_sync(&priv->SwAntennaDiversityTimer);
ieee80211_softmac_stop_protocol(priv->ieee80211);
rtl8180_irq_disable(dev);
rtl8180_rtx_disable(dev);
_rtl8180_up(dev);
}
static void r8180_set_multicast(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
short promisc;
promisc = (dev->flags & IFF_PROMISC) ? 1 : 0;
if (promisc != priv->promisc)
rtl8180_restart(dev);
priv->promisc = promisc;
}
int r8180_set_mac_adr(struct net_device *dev, void *mac)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct sockaddr *addr = mac;
down(&priv->wx_sem);
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
if (priv->ieee80211->iw_mode == IW_MODE_MASTER)
memcpy(priv->ieee80211->current_network.bssid, dev->dev_addr, ETH_ALEN);
if (priv->up) {
rtl8180_down(dev);
rtl8180_up(dev);
}
up(&priv->wx_sem);
return 0;
}
int rtl8180_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
struct iwreq *wrq = (struct iwreq *) rq;
int ret = -1;
switch (cmd) {
case RTL_IOCTL_WPA_SUPPLICANT:
ret = ieee80211_wpa_supplicant_ioctl(priv->ieee80211, &wrq->u.data);
return ret;
default:
return -EOPNOTSUPP;
}
return -EOPNOTSUPP;
}
static int __devinit rtl8180_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned long ioaddr = 0;
struct net_device *dev = NULL;
struct r8180_priv *priv = NULL;
u8 unit = 0;
int ret = -ENODEV;
unsigned long pmem_start, pmem_len, pmem_flags;
DMESG("Configuring chip resources");
if (pci_enable_device(pdev)) {
DMESG("Failed to enable PCI device");
return -EIO;
}
pci_set_master(pdev);
pci_set_dma_mask(pdev, 0xffffff00ULL);
pci_set_consistent_dma_mask(pdev, 0xffffff00ULL);
dev = alloc_ieee80211(sizeof(struct r8180_priv));
if (!dev) {
ret = -ENOMEM;
goto fail_free;
}
priv = ieee80211_priv(dev);
priv->ieee80211 = netdev_priv(dev);
pci_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
priv = ieee80211_priv(dev);
priv->pdev = pdev;
pmem_start = pci_resource_start(pdev, 1);
pmem_len = pci_resource_len(pdev, 1);
pmem_flags = pci_resource_flags(pdev, 1);
if (!(pmem_flags & IORESOURCE_MEM)) {
DMESG("region #1 not a MMIO resource, aborting");
goto fail;
}
if (!request_mem_region(pmem_start, pmem_len, RTL8180_MODULE_NAME)) {
DMESG("request_mem_region failed!");
goto fail;
}
ioaddr = (unsigned long)ioremap_nocache(pmem_start, pmem_len);
if (ioaddr == (unsigned long)NULL) {
DMESG("ioremap failed!");
goto fail1;
}
dev->mem_start = ioaddr;
dev->mem_end = ioaddr + pci_resource_len(pdev, 0);
pci_read_config_byte(pdev, 0x05, &unit);
pci_write_config_byte(pdev, 0x05, unit & (~0x04));
dev->irq = pdev->irq;
priv->irq = 0;
dev->netdev_ops = &rtl8180_netdev_ops;
dev->wireless_handlers = &r8180_wx_handlers_def;
dev->type = ARPHRD_ETHER;
dev->watchdog_timeo = HZ*3;
if (dev_alloc_name(dev, ifname) < 0) {
DMESG("Oops: devname already taken! Trying wlan%%d...\n");
strcpy(ifname, "wlan%d");
dev_alloc_name(dev, ifname);
}
if (rtl8180_init(dev) != 0) {
DMESG("Initialization failed");
goto fail1;
}
netif_carrier_off(dev);
register_netdev(dev);
rtl8180_proc_init_one(dev);
DMESG("Driver probe completed\n");
return 0;
fail1:
if (dev->mem_start != (unsigned long)NULL) {
iounmap((void *)dev->mem_start);
release_mem_region(pci_resource_start(pdev, 1),
pci_resource_len(pdev, 1));
}
fail:
if (dev) {
if (priv->irq) {
free_irq(dev->irq, dev);
dev->irq = 0;
}
free_ieee80211(dev);
}
fail_free:
pci_disable_device(pdev);
DMESG("wlan driver load failed\n");
pci_set_drvdata(pdev, NULL);
return ret;
}
static void __devexit rtl8180_pci_remove(struct pci_dev *pdev)
{
struct r8180_priv *priv;
struct net_device *dev = pci_get_drvdata(pdev);
if (dev) {
unregister_netdev(dev);
priv = ieee80211_priv(dev);
rtl8180_proc_remove_one(dev);
rtl8180_down(dev);
priv->rf_close(dev);
rtl8180_reset(dev);
mdelay(10);
if (priv->irq) {
DMESG("Freeing irq %d", dev->irq);
free_irq(dev->irq, dev);
priv->irq = 0;
}
free_rx_desc_ring(dev);
free_tx_desc_rings(dev);
if (dev->mem_start != (unsigned long)NULL) {
iounmap((void *)dev->mem_start);
release_mem_region(pci_resource_start(pdev, 1),
pci_resource_len(pdev, 1));
}
free_ieee80211(dev);
}
pci_disable_device(pdev);
DMESG("wlan driver removed\n");
}
static int __init rtl8180_pci_module_init(void)
{
int ret;
ret = ieee80211_crypto_init();
if (ret) {
printk(KERN_ERR "ieee80211_crypto_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_tkip_init();
if (ret) {
printk(KERN_ERR "ieee80211_crypto_tkip_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_ccmp_init();
if (ret) {
printk(KERN_ERR "ieee80211_crypto_ccmp_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_wep_init();
if (ret) {
printk(KERN_ERR "ieee80211_crypto_wep_init() failed %d\n", ret);
return ret;
}
printk(KERN_INFO "\nLinux kernel driver for RTL8180 / RTL8185 based WLAN cards\n");
printk(KERN_INFO "Copyright (c) 2004-2005, Andrea Merello\n");
DMESG("Initializing module");
DMESG("Wireless extensions version %d", WIRELESS_EXT);
rtl8180_proc_module_init();
if (pci_register_driver(&rtl8180_pci_driver)) {
DMESG("No device found");
return -ENODEV;
}
return 0;
}
static void __exit rtl8180_pci_module_exit(void)
{
pci_unregister_driver(&rtl8180_pci_driver);
rtl8180_proc_module_remove();
ieee80211_crypto_tkip_exit();
ieee80211_crypto_ccmp_exit();
ieee80211_crypto_wep_exit();
ieee80211_crypto_deinit();
DMESG("Exiting");
}
void rtl8180_try_wake_queue(struct net_device *dev, int pri)
{
unsigned long flags;
short enough_desc;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
spin_lock_irqsave(&priv->tx_lock, flags);
enough_desc = check_nic_enought_desc(dev, pri);
spin_unlock_irqrestore(&priv->tx_lock, flags);
if (enough_desc)
ieee80211_rtl_wake_queue(priv->ieee80211);
}
void rtl8180_tx_isr(struct net_device *dev, int pri, short error)
{
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
u32 *tail;
u32 *head;
u32 *begin;
u32 *nicv;
u32 nic;
u32 nicbegin;
unsigned long flag;
int offs;
int j, i;
int hd;
if (error)
priv->stats.txretry++;
spin_lock_irqsave(&priv->tx_lock, flag);
switch (pri) {
case MANAGE_PRIORITY:
tail = priv->txmapringtail;
begin = priv->txmapring;
head = priv->txmapringhead;
nic = read_nic_dword(dev, TX_MANAGEPRIORITY_RING_ADDR);
nicbegin = priv->txmapringdma;
break;
case BK_PRIORITY:
tail = priv->txbkpringtail;
begin = priv->txbkpring;
head = priv->txbkpringhead;
nic = read_nic_dword(dev, TX_BKPRIORITY_RING_ADDR);
nicbegin = priv->txbkpringdma;
break;
case BE_PRIORITY:
tail = priv->txbepringtail;
begin = priv->txbepring;
head = priv->txbepringhead;
nic = read_nic_dword(dev, TX_BEPRIORITY_RING_ADDR);
nicbegin = priv->txbepringdma;
break;
case VI_PRIORITY:
tail = priv->txvipringtail;
begin = priv->txvipring;
head = priv->txvipringhead;
nic = read_nic_dword(dev, TX_VIPRIORITY_RING_ADDR);
nicbegin = priv->txvipringdma;
break;
case VO_PRIORITY:
tail = priv->txvopringtail;
begin = priv->txvopring;
head = priv->txvopringhead;
nic = read_nic_dword(dev, TX_VOPRIORITY_RING_ADDR);
nicbegin = priv->txvopringdma;
break;
case HI_PRIORITY:
tail = priv->txhpringtail;
begin = priv->txhpring;
head = priv->txhpringhead;
nic = read_nic_dword(dev, TX_HIGHPRIORITY_RING_ADDR);
nicbegin = priv->txhpringdma;
break;
default:
spin_unlock_irqrestore(&priv->tx_lock, flag);
return ;
}
nicv = (u32 *)((nic - nicbegin) + (u8*)begin);
if ((head <= tail && (nicv > tail || nicv < head)) ||
(head > tail && (nicv > tail && nicv < head))) {
DMESGW("nic has lost pointer");
spin_unlock_irqrestore(&priv->tx_lock, flag);
rtl8180_restart(dev);
return;
}
offs = (nic - nicbegin);
offs = offs / 8 / 4;
hd = (head - begin) / 8;
if (offs >= hd)
j = offs - hd;
else
j = offs + (priv->txringcount-1-hd);
j -= 2;
if (j < 0)
j = 0;
for (i = 0; i < j; i++) {
if ((*head) & (1<<31))
break;
if (((*head)&(0x10000000)) != 0) {
priv->CurrRetryCnt += (u16)((*head) & (0x000000ff));
if (!error)
priv->NumTxOkTotal++;
}
if (!error)
priv->NumTxOkBytesTotal += (*(head+3)) & (0x00000fff);
*head = *head & ~(1<<31);
if ((head - begin)/8 == priv->txringcount-1)
head = begin;
else
head += 8;
}
switch (pri) {
case MANAGE_PRIORITY:
priv->txmapringhead = head;
if (priv->ack_tx_to_ieee) {
if (rtl8180_is_tx_queue_empty(dev)) {
priv->ack_tx_to_ieee = 0;
ieee80211_ps_tx_ack(priv->ieee80211, !error);
}
}
break;
case BK_PRIORITY:
priv->txbkpringhead = head;
break;
case BE_PRIORITY:
priv->txbepringhead = head;
break;
case VI_PRIORITY:
priv->txvipringhead = head;
break;
case VO_PRIORITY:
priv->txvopringhead = head;
break;
case HI_PRIORITY:
priv->txhpringhead = head;
break;
}
spin_unlock_irqrestore(&priv->tx_lock, flag);
}
void rtl8180_tx_irq_wq(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct ieee80211_device * ieee = (struct ieee80211_device *)
container_of(dwork, struct ieee80211_device, watch_dog_wq);
struct net_device *dev = ieee->dev;
rtl8180_tx_isr(dev, MANAGE_PRIORITY, 0);
}
irqreturn_t rtl8180_interrupt(int irq, void *netdev, struct pt_regs *regs)
{
struct net_device *dev = (struct net_device *) netdev;
struct r8180_priv *priv = (struct r8180_priv *)ieee80211_priv(dev);
unsigned long flags;
u32 inta;
if (priv->irq_enabled == 0)
return IRQ_HANDLED;
spin_lock_irqsave(&priv->irq_th_lock, flags);
inta = read_nic_dword(dev, ISR);
write_nic_dword(dev, ISR, inta);
priv->stats.shints++;
if (!inta) {
spin_unlock_irqrestore(&priv->irq_th_lock, flags);
return IRQ_HANDLED;
}
if (inta == 0xffff) {
spin_unlock_irqrestore(&priv->irq_th_lock, flags);
return IRQ_HANDLED;
}
priv->stats.ints++;
if (!netif_running(dev)) {
spin_unlock_irqrestore(&priv->irq_th_lock, flags);
return IRQ_HANDLED;
}
if (inta & ISR_TimeOut)
write_nic_dword(dev, TimerInt, 0);
if (inta & ISR_TBDOK)
priv->stats.txbeacon++;
if (inta & ISR_TBDER)
priv->stats.txbeaconerr++;
if (inta & IMR_TMGDOK)
rtl8180_tx_isr(dev, MANAGE_PRIORITY, 0);
if (inta & ISR_THPDER) {
priv->stats.txhperr++;
rtl8180_tx_isr(dev, HI_PRIORITY, 1);
priv->ieee80211->stats.tx_errors++;
}
if (inta & ISR_THPDOK) {
priv->link_detect.NumTxOkInPeriod++;
priv->stats.txhpokint++;
rtl8180_tx_isr(dev, HI_PRIORITY, 0);
}
if (inta & ISR_RER)
priv->stats.rxerr++;
if (inta & ISR_TBKDER) {
priv->stats.txbkperr++;
priv->ieee80211->stats.tx_errors++;
rtl8180_tx_isr(dev, BK_PRIORITY, 1);
rtl8180_try_wake_queue(dev, BE_PRIORITY);
}
if (inta & ISR_TBEDER) {
priv->stats.txbeperr++;
priv->ieee80211->stats.tx_errors++;
rtl8180_tx_isr(dev, BE_PRIORITY, 1);
rtl8180_try_wake_queue(dev, BE_PRIORITY);
}
if (inta & ISR_TNPDER) {
priv->stats.txnperr++;
priv->ieee80211->stats.tx_errors++;
rtl8180_tx_isr(dev, NORM_PRIORITY, 1);
rtl8180_try_wake_queue(dev, NORM_PRIORITY);
}
if (inta & ISR_TLPDER) {
priv->stats.txlperr++;
priv->ieee80211->stats.tx_errors++;
rtl8180_tx_isr(dev, LOW_PRIORITY, 1);
rtl8180_try_wake_queue(dev, LOW_PRIORITY);
}
if (inta & ISR_ROK) {
priv->stats.rxint++;
tasklet_schedule(&priv->irq_rx_tasklet);
}
if (inta & ISR_RQoSOK) {
priv->stats.rxint++;
tasklet_schedule(&priv->irq_rx_tasklet);
}
if (inta & ISR_BcnInt)
rtl8180_prepare_beacon(dev);
if (inta & ISR_RDU) {
DMESGW("No RX descriptor available");
priv->stats.rxrdu++;
tasklet_schedule(&priv->irq_rx_tasklet);
}
if (inta & ISR_RXFOVW) {
priv->stats.rxoverflow++;
tasklet_schedule(&priv->irq_rx_tasklet);
}
if (inta & ISR_TXFOVW)
priv->stats.txoverflow++;
if (inta & ISR_TNPDOK) {
priv->link_detect.NumTxOkInPeriod++;
priv->stats.txnpokint++;
rtl8180_tx_isr(dev, NORM_PRIORITY, 0);
}
if (inta & ISR_TLPDOK) {
priv->link_detect.NumTxOkInPeriod++;
priv->stats.txlpokint++;
rtl8180_tx_isr(dev, LOW_PRIORITY, 0);
rtl8180_try_wake_queue(dev, LOW_PRIORITY);
}
if (inta & ISR_TBKDOK) {
priv->stats.txbkpokint++;
priv->link_detect.NumTxOkInPeriod++;
rtl8180_tx_isr(dev, BK_PRIORITY, 0);
rtl8180_try_wake_queue(dev, BE_PRIORITY);
}
if (inta & ISR_TBEDOK) {
priv->stats.txbeperr++;
priv->link_detect.NumTxOkInPeriod++;
rtl8180_tx_isr(dev, BE_PRIORITY, 0);
rtl8180_try_wake_queue(dev, BE_PRIORITY);
}
force_pci_posting(dev);
spin_unlock_irqrestore(&priv->irq_th_lock, flags);
return IRQ_HANDLED;
}
void rtl8180_irq_rx_tasklet(struct r8180_priv *priv)
{
rtl8180_rx(priv->dev);
}
void GPIOChangeRFWorkItemCallBack(struct work_struct *work)
{
struct ieee80211_device *ieee = container_of(work, struct ieee80211_device, GPIOChangeRFWorkItem.work);
struct net_device *dev = ieee->dev;
struct r8180_priv *priv = ieee80211_priv(dev);
u8 btPSR;
u8 btConfig0;
RT_RF_POWER_STATE eRfPowerStateToSet;
bool bActuallySet = false;
char *argv[3];
static char *RadioPowerPath = "/etc/acpi/events/RadioPower.sh";
static char *envp[] = {"HOME=/", "TERM=linux", "PATH=/usr/bin:/bin", NULL};
static int readf_count = 0;
if (readf_count % 10 == 0)
priv->PowerProfile = read_acadapter_file("/proc/acpi/ac_adapter/AC0/state");
readf_count = (readf_count+1)%0xffff;
btPSR = read_nic_byte(dev, PSR);
write_nic_byte(dev, PSR, (btPSR & ~BIT3));
udelay(4);
btConfig0 = btPSR = read_nic_byte(dev, CONFIG0);
eRfPowerStateToSet = (btConfig0 & BIT4) ? eRfOn : eRfOff;
if (eRfPowerStateToSet == eRfOn)
write_nic_byte(dev, PSR, btPSR | BIT3);
if ((priv->ieee80211->bHwRadioOff == true) &&
(eRfPowerStateToSet == eRfOn)) {
priv->ieee80211->bHwRadioOff = false;
bActuallySet = true;
} else if ((priv->ieee80211->bHwRadioOff == false) &&
(eRfPowerStateToSet == eRfOff)) {
priv->ieee80211->bHwRadioOff = true;
bActuallySet = true;
}
if (bActuallySet) {
MgntActSet_RF_State(dev, eRfPowerStateToSet, RF_CHANGE_BY_HW);
if (priv->ieee80211->bHwRadioOff == true)
argv[1] = "RFOFF";
else
argv[1] = "RFON";
argv[0] = RadioPowerPath;
argv[2] = NULL;
call_usermodehelper(RadioPowerPath, argv, envp, 1);
}
}
static u8 read_acadapter_file(char *filename)
{
return 0;
}
