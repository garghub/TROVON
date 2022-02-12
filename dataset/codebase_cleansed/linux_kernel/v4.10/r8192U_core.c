double __floatsidf(int i)
{
return i;
}
unsigned int __fixunsdfsi(double d)
{
return d;
}
double __adddf3(double a, double b)
{
return a + b;
}
double __addsf3(float a, float b)
{
return a + b;
}
double __subdf3(double a, double b)
{
return a - b;
}
double __extendsfdf2(float a)
{
return a;
}
static void rtl819x_set_channel_map(u8 channel_plan, struct r8192_priv *priv)
{
int i, max_chan = -1, min_chan = -1;
struct ieee80211_device *ieee = priv->ieee80211;
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
case COUNTRY_CODE_MIC:
Dot11d_Init(ieee);
ieee->bGlobalDomain = false;
if ((priv->rf_chip == RF_8225) || (priv->rf_chip == RF_8256)) {
min_chan = 1;
max_chan = 14;
} else {
RT_TRACE(COMP_ERR,
"unknown rf chip, can't set channel map in function:%s()\n",
__func__);
}
if (ChannelPlan[channel_plan].Len != 0) {
memset(GET_DOT11D_INFO(ieee)->channel_map, 0,
sizeof(GET_DOT11D_INFO(ieee)->channel_map));
for (i = 0; i < ChannelPlan[channel_plan].Len; i++) {
if (ChannelPlan[channel_plan].Channel[i] < min_chan || ChannelPlan[channel_plan].Channel[i] > max_chan)
break;
GET_DOT11D_INFO(ieee)->channel_map[ChannelPlan[channel_plan].Channel[i]] = 1;
}
}
break;
case COUNTRY_CODE_GLOBAL_DOMAIN:
GET_DOT11D_INFO(ieee)->bEnabled = 0;
Dot11d_Reset(ieee);
ieee->bGlobalDomain = true;
break;
default:
break;
}
}
static void CamResetAllEntry(struct net_device *dev)
{
u32 ulcommand = 0;
ulcommand |= BIT(31) | BIT(30);
write_nic_dword(dev, RWCAM, ulcommand);
}
void write_cam(struct net_device *dev, u8 addr, u32 data)
{
write_nic_dword(dev, WCAMI, data);
write_nic_dword(dev, RWCAM, BIT(31) | BIT(16) | (addr & 0xff));
}
u32 read_cam(struct net_device *dev, u8 addr)
{
u32 data;
write_nic_dword(dev, RWCAM, 0x80000000 | (addr & 0xff));
read_nic_dword(dev, 0xa8, &data);
return data;
}
int write_nic_byte_E(struct net_device *dev, int indx, u8 data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u8 *usbdata = kzalloc(sizeof(data), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
*usbdata = data;
status = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
RTL8187_REQ_SET_REGS, RTL8187_REQT_WRITE,
indx | 0xfe00, 0, usbdata, 1, HZ / 2);
kfree(usbdata);
if (status < 0){
netdev_err(dev, "write_nic_byte_E TimeOut! status: %d\n",
status);
return status;
}
return 0;
}
int read_nic_byte_E(struct net_device *dev, int indx, u8 *data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u8 *usbdata = kzalloc(sizeof(u8), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
status = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
RTL8187_REQ_GET_REGS, RTL8187_REQT_READ,
indx | 0xfe00, 0, usbdata, 1, HZ / 2);
*data = *usbdata;
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "%s failure status: %d\n", __func__, status);
return status;
}
return 0;
}
int write_nic_byte(struct net_device *dev, int indx, u8 data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u8 *usbdata = kzalloc(sizeof(data), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
*usbdata = data;
status = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
RTL8187_REQ_SET_REGS, RTL8187_REQT_WRITE,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 1, HZ / 2);
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "write_nic_byte TimeOut! status: %d\n", status);
return status;
}
return 0;
}
int write_nic_word(struct net_device *dev, int indx, u16 data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u16 *usbdata = kzalloc(sizeof(data), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
*usbdata = data;
status = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
RTL8187_REQ_SET_REGS, RTL8187_REQT_WRITE,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 2, HZ / 2);
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "write_nic_word TimeOut! status: %d\n", status);
return status;
}
return 0;
}
int write_nic_dword(struct net_device *dev, int indx, u32 data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u32 *usbdata = kzalloc(sizeof(data), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
*usbdata = data;
status = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
RTL8187_REQ_SET_REGS, RTL8187_REQT_WRITE,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 4, HZ / 2);
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "write_nic_dword TimeOut! status: %d\n",
status);
return status;
}
return 0;
}
int read_nic_byte(struct net_device *dev, int indx, u8 *data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u8 *usbdata = kzalloc(sizeof(u8), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
status = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
RTL8187_REQ_GET_REGS, RTL8187_REQT_READ,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 1, HZ / 2);
*data = *usbdata;
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "%s failure status: %d\n", __func__, status);
return status;
}
return 0;
}
int read_nic_word(struct net_device *dev, int indx, u16 *data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u16 *usbdata = kzalloc(sizeof(u16), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
status = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
RTL8187_REQ_GET_REGS, RTL8187_REQT_READ,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 2, HZ / 2);
*data = *usbdata;
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "%s failure status: %d\n", __func__, status);
return status;
}
return 0;
}
static int read_nic_word_E(struct net_device *dev, int indx, u16 *data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u16 *usbdata = kzalloc(sizeof(u16), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
status = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
RTL8187_REQ_GET_REGS, RTL8187_REQT_READ,
indx | 0xfe00, 0, usbdata, 2, HZ / 2);
*data = *usbdata;
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "%s failure status: %d\n", __func__, status);
return status;
}
return 0;
}
int read_nic_dword(struct net_device *dev, int indx, u32 *data)
{
int status;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct usb_device *udev = priv->udev;
u32 *usbdata = kzalloc(sizeof(u32), GFP_KERNEL);
if (!usbdata)
return -ENOMEM;
status = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
RTL8187_REQ_GET_REGS, RTL8187_REQT_READ,
(indx & 0xff) | 0xff00, (indx >> 8) & 0x0f,
usbdata, 4, HZ / 2);
*data = *usbdata;
kfree(usbdata);
if (status < 0) {
netdev_err(dev, "%s failure status: %d\n", __func__, status);
return status;
}
return 0;
}
inline void force_pci_posting(struct net_device *dev)
{
}
static int proc_get_stats_ap(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
struct ieee80211_network *target;
list_for_each_entry(target, &ieee->network_list, list) {
const char *wpa = "non_WPA";
if (target->wpa_ie_len > 0 || target->rsn_ie_len > 0)
wpa = "WPA";
seq_printf(m, "%s %s\n", target->ssid, wpa);
}
return 0;
}
static int proc_get_registers(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
int i, n, max = 0xff;
u8 byte_rd;
seq_puts(m, "\n####################page 0##################\n ");
for (n = 0; n <= max;) {
seq_printf(m, "\nD: %2x > ", n);
for (i = 0; i < 16 && n <= max; i++, n++) {
read_nic_byte(dev, 0x000 | n, &byte_rd);
seq_printf(m, "%2x ", byte_rd);
}
}
seq_puts(m, "\n####################page 1##################\n ");
for (n = 0; n <= max;) {
seq_printf(m, "\nD: %2x > ", n);
for (i = 0; i < 16 && n <= max; i++, n++) {
read_nic_byte(dev, 0x100 | n, &byte_rd);
seq_printf(m, "%2x ", byte_rd);
}
}
seq_puts(m, "\n####################page 3##################\n ");
for (n = 0; n <= max;) {
seq_printf(m, "\nD: %2x > ", n);
for (i = 0; i < 16 && n <= max; i++, n++) {
read_nic_byte(dev, 0x300 | n, &byte_rd);
seq_printf(m, "%2x ", byte_rd);
}
}
seq_putc(m, '\n');
return 0;
}
static int proc_get_stats_tx(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
seq_printf(m,
"TX VI priority ok int: %lu\n"
"TX VI priority error int: %lu\n"
"TX VO priority ok int: %lu\n"
"TX VO priority error int: %lu\n"
"TX BE priority ok int: %lu\n"
"TX BE priority error int: %lu\n"
"TX BK priority ok int: %lu\n"
"TX BK priority error int: %lu\n"
"TX MANAGE priority ok int: %lu\n"
"TX MANAGE priority error int: %lu\n"
"TX BEACON priority ok int: %lu\n"
"TX BEACON priority error int: %lu\n"
"TX queue resume: %lu\n"
"TX queue stopped?: %d\n"
"TX fifo overflow: %lu\n"
"TX VI queue: %d\n"
"TX VO queue: %d\n"
"TX BE queue: %d\n"
"TX BK queue: %d\n"
"TX VI dropped: %lu\n"
"TX VO dropped: %lu\n"
"TX BE dropped: %lu\n"
"TX BK dropped: %lu\n"
"TX total data packets %lu\n",
priv->stats.txviokint,
priv->stats.txvierr,
priv->stats.txvookint,
priv->stats.txvoerr,
priv->stats.txbeokint,
priv->stats.txbeerr,
priv->stats.txbkokint,
priv->stats.txbkerr,
priv->stats.txmanageokint,
priv->stats.txmanageerr,
priv->stats.txbeaconokint,
priv->stats.txbeaconerr,
priv->stats.txresumed,
netif_queue_stopped(dev),
priv->stats.txoverflow,
atomic_read(&(priv->tx_pending[VI_PRIORITY])),
atomic_read(&(priv->tx_pending[VO_PRIORITY])),
atomic_read(&(priv->tx_pending[BE_PRIORITY])),
atomic_read(&(priv->tx_pending[BK_PRIORITY])),
priv->stats.txvidrop,
priv->stats.txvodrop,
priv->stats.txbedrop,
priv->stats.txbkdrop,
priv->stats.txdatapkt
);
return 0;
}
static int proc_get_stats_rx(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
seq_printf(m,
"RX packets: %lu\n"
"RX urb status error: %lu\n"
"RX invalid urb error: %lu\n",
priv->stats.rxoktotal,
priv->stats.rxstaterr,
priv->stats.rxurberr);
return 0;
}
static void rtl8192_proc_module_init(void)
{
RT_TRACE(COMP_INIT, "Initializing proc filesystem");
rtl8192_proc = proc_mkdir(RTL819xU_MODULE_NAME, init_net.proc_net);
}
static int rtl8192_proc_open(struct inode *inode, struct file *file)
{
struct net_device *dev = proc_get_parent_data(inode);
int (*show)(struct seq_file *, void *) = PDE_DATA(inode);
return single_open(file, show, dev);
}
static void rtl8192_proc_init_one(struct net_device *dev)
{
const struct rtl8192_proc_file *f;
struct proc_dir_entry *dir;
if (rtl8192_proc) {
dir = proc_mkdir_data(dev->name, 0, rtl8192_proc, dev);
if (!dir) {
RT_TRACE(COMP_ERR,
"Unable to initialize /proc/net/rtl8192/%s\n",
dev->name);
return;
}
for (f = rtl8192_proc_files; f->name[0]; f++) {
if (!proc_create_data(f->name, S_IFREG | S_IRUGO, dir,
&rtl8192_proc_fops, f->show)) {
RT_TRACE(COMP_ERR,
"Unable to initialize /proc/net/rtl8192/%s/%s\n",
dev->name, f->name);
return;
}
}
}
}
static void rtl8192_proc_remove_one(struct net_device *dev)
{
remove_proc_subtree(dev->name, rtl8192_proc);
}
short check_nic_enough_desc(struct net_device *dev, int queue_index)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int used = atomic_read(&priv->tx_pending[queue_index]);
return (used < MAX_TX_URB);
}
static void tx_timeout(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
schedule_work(&priv->reset_wq);
}
void rtl8192_update_msr(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 msr;
read_nic_byte(dev, MSR, &msr);
msr &= ~MSR_LINK_MASK;
if (priv->ieee80211->state == IEEE80211_LINKED) {
if (priv->ieee80211->iw_mode == IW_MODE_INFRA)
msr |= (MSR_LINK_MANAGED << MSR_LINK_SHIFT);
else if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
msr |= (MSR_LINK_ADHOC << MSR_LINK_SHIFT);
else if (priv->ieee80211->iw_mode == IW_MODE_MASTER)
msr |= (MSR_LINK_MASTER << MSR_LINK_SHIFT);
} else {
msr |= (MSR_LINK_NONE << MSR_LINK_SHIFT);
}
write_nic_byte(dev, MSR, msr);
}
void rtl8192_set_chan(struct net_device *dev, short ch)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
RT_TRACE(COMP_CH, "=====>%s()====ch:%d\n", __func__, ch);
priv->chan = ch;
if (priv->rf_set_chan)
priv->rf_set_chan(dev, priv->chan);
mdelay(10);
}
static u32 get_rxpacket_shiftbytes_819xusb(struct ieee80211_rx_stats *pstats)
{
return (sizeof(rx_desc_819x_usb) + pstats->RxDrvInfoSize
+ pstats->RxBufShift);
}
static int rtl8192_rx_initiate(struct net_device *dev)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct urb *entry;
struct sk_buff *skb;
struct rtl8192_rx_info *info;
while (skb_queue_len(&priv->rx_queue) < MAX_RX_URB) {
skb = __dev_alloc_skb(RX_URB_SIZE, GFP_KERNEL);
if (!skb)
break;
entry = usb_alloc_urb(0, GFP_KERNEL);
if (!entry) {
kfree_skb(skb);
break;
}
usb_fill_bulk_urb(entry, priv->udev,
usb_rcvbulkpipe(priv->udev, 3),
skb_tail_pointer(skb),
RX_URB_SIZE, rtl8192_rx_isr, skb);
info = (struct rtl8192_rx_info *)skb->cb;
info->urb = entry;
info->dev = dev;
info->out_pipe = 3;
skb_queue_tail(&priv->rx_queue, skb);
usb_submit_urb(entry, GFP_KERNEL);
}
while (skb_queue_len(&priv->rx_queue) < MAX_RX_URB + 3) {
skb = __dev_alloc_skb(RX_URB_SIZE, GFP_KERNEL);
if (!skb)
break;
entry = usb_alloc_urb(0, GFP_KERNEL);
if (!entry) {
kfree_skb(skb);
break;
}
usb_fill_bulk_urb(entry, priv->udev,
usb_rcvbulkpipe(priv->udev, 9),
skb_tail_pointer(skb),
RX_URB_SIZE, rtl8192_rx_isr, skb);
info = (struct rtl8192_rx_info *)skb->cb;
info->urb = entry;
info->dev = dev;
info->out_pipe = 9;
skb_queue_tail(&priv->rx_queue, skb);
usb_submit_urb(entry, GFP_KERNEL);
}
return 0;
}
void rtl8192_set_rxconf(struct net_device *dev)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
u32 rxconf;
read_nic_dword(dev, RCR, &rxconf);
rxconf = rxconf & ~MAC_FILTER_MASK;
rxconf = rxconf | RCR_AMF;
rxconf = rxconf | RCR_ADF;
rxconf = rxconf | RCR_AB;
rxconf = rxconf | RCR_AM;
if (dev->flags & IFF_PROMISC)
DMESG("NIC in promisc mode");
if (priv->ieee80211->iw_mode == IW_MODE_MONITOR ||
dev->flags & IFF_PROMISC) {
rxconf = rxconf | RCR_AAP;
} else {
rxconf = rxconf | RCR_APM;
rxconf = rxconf | RCR_CBSSID;
}
if (priv->ieee80211->iw_mode == IW_MODE_MONITOR) {
rxconf = rxconf | RCR_AICV;
rxconf = rxconf | RCR_APWRMGT;
}
if (priv->crcmon == 1 && priv->ieee80211->iw_mode == IW_MODE_MONITOR)
rxconf = rxconf | RCR_ACRC32;
rxconf = rxconf & ~RX_FIFO_THRESHOLD_MASK;
rxconf = rxconf | (RX_FIFO_THRESHOLD_NONE << RX_FIFO_THRESHOLD_SHIFT);
rxconf = rxconf & ~MAX_RX_DMA_MASK;
rxconf = rxconf | ((u32)7 << RCR_MXDMA_OFFSET);
rxconf = rxconf | RCR_ONLYERLPKT;
write_nic_dword(dev, RCR, rxconf);
}
void rtl8192_rx_enable(struct net_device *dev)
{
rtl8192_rx_initiate(dev);
}
void rtl8192_tx_enable(struct net_device *dev)
{
}
void rtl8192_rtx_disable(struct net_device *dev)
{
u8 cmd;
struct r8192_priv *priv = ieee80211_priv(dev);
struct sk_buff *skb;
struct rtl8192_rx_info *info;
read_nic_byte(dev, CMDR, &cmd);
write_nic_byte(dev, CMDR, cmd & ~(CR_TE | CR_RE));
force_pci_posting(dev);
mdelay(10);
while ((skb = __skb_dequeue(&priv->rx_queue))) {
info = (struct rtl8192_rx_info *)skb->cb;
if (!info->urb)
continue;
usb_kill_urb(info->urb);
kfree_skb(skb);
}
if (skb_queue_len(&priv->skb_queue))
netdev_warn(dev, "skb_queue not empty\n");
skb_queue_purge(&priv->skb_queue);
}
static void rtl8192_rx_isr(struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *)urb->context;
struct rtl8192_rx_info *info = (struct rtl8192_rx_info *)skb->cb;
struct net_device *dev = info->dev;
struct r8192_priv *priv = ieee80211_priv(dev);
int out_pipe = info->out_pipe;
int err;
if (!priv->up)
return;
if (unlikely(urb->status)) {
info->urb = NULL;
priv->stats.rxstaterr++;
priv->ieee80211->stats.rx_errors++;
usb_free_urb(urb);
return;
}
skb_unlink(skb, &priv->rx_queue);
skb_put(skb, urb->actual_length);
skb_queue_tail(&priv->skb_queue, skb);
tasklet_schedule(&priv->irq_rx_tasklet);
skb = dev_alloc_skb(RX_URB_SIZE);
if (unlikely(!skb)) {
usb_free_urb(urb);
netdev_err(dev, "%s(): can't alloc skb\n", __func__);
return;
}
usb_fill_bulk_urb(urb, priv->udev,
usb_rcvbulkpipe(priv->udev, out_pipe),
skb_tail_pointer(skb),
RX_URB_SIZE, rtl8192_rx_isr, skb);
info = (struct rtl8192_rx_info *)skb->cb;
info->urb = urb;
info->dev = dev;
info->out_pipe = out_pipe;
urb->transfer_buffer = skb_tail_pointer(skb);
urb->context = skb;
skb_queue_tail(&priv->rx_queue, skb);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err && err != EPERM)
netdev_err(dev,
"can not submit rxurb, err is %x, URB status is %x\n",
err, urb->status);
}
static u32 rtl819xusb_rx_command_packet(struct net_device *dev,
struct ieee80211_rx_stats *pstats)
{
u32 status;
status = cmpk_message_handle_rx(dev, pstats);
if (status)
DMESG("rxcommandpackethandle819xusb: It is a command packet\n");
return status;
}
static void rtl8192_data_hard_stop(struct net_device *dev)
{
}
static void rtl8192_data_hard_resume(struct net_device *dev)
{
}
static void rtl8192_hard_data_xmit(struct sk_buff *skb, struct net_device *dev,
int rate)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
int ret;
unsigned long flags;
cb_desc *tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
u8 queue_index = tcb_desc->queue_index;
RTL8192U_ASSERT(queue_index != TXCMD_QUEUE);
spin_lock_irqsave(&priv->tx_lock, flags);
*(struct net_device **)(skb->cb) = dev;
tcb_desc->bTxEnableFwCalcDur = 1;
skb_push(skb, priv->ieee80211->tx_headroom);
ret = rtl8192_tx(dev, skb);
spin_unlock_irqrestore(&priv->tx_lock, flags);
}
static int rtl8192_hard_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
int ret;
unsigned long flags;
cb_desc *tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
u8 queue_index = tcb_desc->queue_index;
spin_lock_irqsave(&priv->tx_lock, flags);
memcpy((unsigned char *)(skb->cb), &dev, sizeof(dev));
if (queue_index == TXCMD_QUEUE) {
skb_push(skb, USB_HWDESC_HEADER_LEN);
rtl819xU_tx_cmd(dev, skb);
ret = 1;
} else {
skb_push(skb, priv->ieee80211->tx_headroom);
ret = rtl8192_tx(dev, skb);
}
spin_unlock_irqrestore(&priv->tx_lock, flags);
return ret;
}
static void rtl8192_tx_isr(struct urb *tx_urb)
{
struct sk_buff *skb = (struct sk_buff *)tx_urb->context;
struct net_device *dev;
struct r8192_priv *priv = NULL;
cb_desc *tcb_desc;
u8 queue_index;
if (!skb)
return;
dev = *(struct net_device **)(skb->cb);
tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
queue_index = tcb_desc->queue_index;
priv = ieee80211_priv(dev);
if (tcb_desc->queue_index != TXCMD_QUEUE) {
if (tx_urb->status == 0) {
netif_trans_update(dev);
priv->stats.txoktotal++;
priv->ieee80211->LinkDetectInfo.NumTxOkInPeriod++;
priv->stats.txbytesunicast +=
(skb->len - priv->ieee80211->tx_headroom);
} else {
priv->ieee80211->stats.tx_errors++;
}
}
dev_kfree_skb_any(skb);
usb_free_urb(tx_urb);
atomic_dec(&priv->tx_pending[queue_index]);
if (queue_index != BEACON_QUEUE) {
if ((skb_queue_len(&priv->ieee80211->skb_waitQ[queue_index]) != 0) &&
(!(priv->ieee80211->queue_stop))) {
skb = skb_dequeue(&(priv->ieee80211->skb_waitQ[queue_index]));
if (skb)
priv->ieee80211->softmac_hard_start_xmit(skb,
dev);
return;
}
}
}
static void rtl8192_config_rate(struct net_device *dev, u16 *rate_config)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_network *net;
u8 i = 0, basic_rate = 0;
net = &priv->ieee80211->current_network;
for (i = 0; i < net->rates_len; i++) {
basic_rate = net->rates[i] & 0x7f;
switch (basic_rate) {
case MGN_1M:
*rate_config |= RRSR_1M;
break;
case MGN_2M:
*rate_config |= RRSR_2M;
break;
case MGN_5_5M:
*rate_config |= RRSR_5_5M;
break;
case MGN_11M:
*rate_config |= RRSR_11M;
break;
case MGN_6M:
*rate_config |= RRSR_6M;
break;
case MGN_9M:
*rate_config |= RRSR_9M;
break;
case MGN_12M:
*rate_config |= RRSR_12M;
break;
case MGN_18M:
*rate_config |= RRSR_18M;
break;
case MGN_24M:
*rate_config |= RRSR_24M;
break;
case MGN_36M:
*rate_config |= RRSR_36M;
break;
case MGN_48M:
*rate_config |= RRSR_48M;
break;
case MGN_54M:
*rate_config |= RRSR_54M;
break;
}
}
for (i = 0; i < net->rates_ex_len; i++) {
basic_rate = net->rates_ex[i] & 0x7f;
switch (basic_rate) {
case MGN_1M:
*rate_config |= RRSR_1M;
break;
case MGN_2M:
*rate_config |= RRSR_2M;
break;
case MGN_5_5M:
*rate_config |= RRSR_5_5M;
break;
case MGN_11M:
*rate_config |= RRSR_11M;
break;
case MGN_6M:
*rate_config |= RRSR_6M;
break;
case MGN_9M:
*rate_config |= RRSR_9M;
break;
case MGN_12M:
*rate_config |= RRSR_12M;
break;
case MGN_18M:
*rate_config |= RRSR_18M;
break;
case MGN_24M:
*rate_config |= RRSR_24M;
break;
case MGN_36M:
*rate_config |= RRSR_36M;
break;
case MGN_48M:
*rate_config |= RRSR_48M;
break;
case MGN_54M:
*rate_config |= RRSR_54M;
break;
}
}
}
static void rtl8192_update_cap(struct net_device *dev, u16 cap)
{
u32 tmp = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_network *net = &priv->ieee80211->current_network;
priv->short_preamble = cap & WLAN_CAPABILITY_SHORT_PREAMBLE;
tmp = priv->basic_rate;
if (priv->short_preamble)
tmp |= BRSR_AckShortPmb;
write_nic_dword(dev, RRSR, tmp);
if (net->mode & (IEEE_G | IEEE_N_24G)) {
u8 slot_time = 0;
if ((cap & WLAN_CAPABILITY_SHORT_SLOT) &&
(!priv->ieee80211->pHTInfo->bCurrentRT2RTLongSlotTime))
slot_time = SHORT_SLOT_TIME;
else
slot_time = NON_SHORT_SLOT_TIME;
priv->slot_time = slot_time;
write_nic_byte(dev, SLOT_TIME, slot_time);
}
}
static void rtl8192_net_update(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_network *net;
u16 BcnTimeCfg = 0, BcnCW = 6, BcnIFS = 0xf;
u16 rate_config = 0;
net = &priv->ieee80211->current_network;
rtl8192_config_rate(dev, &rate_config);
priv->basic_rate = rate_config & 0x15f;
write_nic_dword(dev, BSSIDR, ((u32 *)net->bssid)[0]);
write_nic_word(dev, BSSIDR + 4, ((u16 *)net->bssid)[2]);
rtl8192_update_msr(dev);
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC) {
write_nic_word(dev, ATIMWND, 2);
write_nic_word(dev, BCN_DMATIME, 1023);
write_nic_word(dev, BCN_INTERVAL, net->beacon_interval);
write_nic_word(dev, BCN_DRV_EARLY_INT, 1);
write_nic_byte(dev, BCN_ERR_THRESH, 100);
BcnTimeCfg |= (BcnCW << BCN_TCFG_CW_SHIFT);
BcnTimeCfg |= BcnIFS << BCN_TCFG_IFS;
write_nic_word(dev, BCN_TCFG, BcnTimeCfg);
}
}
void rtl819xusb_beacon_tx(struct net_device *dev, u16 tx_rate)
{
}
short rtl819xU_tx_cmd(struct net_device *dev, struct sk_buff *skb)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int status;
struct urb *tx_urb;
unsigned int idx_pipe;
tx_desc_cmd_819x_usb *pdesc = (tx_desc_cmd_819x_usb *)skb->data;
cb_desc *tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
u8 queue_index = tcb_desc->queue_index;
atomic_inc(&priv->tx_pending[queue_index]);
tx_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!tx_urb) {
dev_kfree_skb(skb);
return -ENOMEM;
}
memset(pdesc, 0, USB_HWDESC_HEADER_LEN);
pdesc->FirstSeg = 1;
pdesc->LastSeg = 1;
pdesc->CmdInit = tcb_desc->bCmdOrInit;
pdesc->TxBufferSize = tcb_desc->txbuf_size;
pdesc->OWN = 1;
pdesc->LINIP = tcb_desc->bLastIniPkt;
idx_pipe = 0x04;
usb_fill_bulk_urb(tx_urb, priv->udev,
usb_sndbulkpipe(priv->udev, idx_pipe),
skb->data, skb->len, rtl8192_tx_isr, skb);
status = usb_submit_urb(tx_urb, GFP_ATOMIC);
if (!status)
return 0;
DMESGE("Error TX CMD URB, error %d", status);
return -1;
}
static u8 MapHwQueueToFirmwareQueue(u8 QueueID)
{
u8 QueueSelect = 0x0;
switch (QueueID) {
case BE_QUEUE:
QueueSelect = QSLT_BE;
break;
case BK_QUEUE:
QueueSelect = QSLT_BK;
break;
case VO_QUEUE:
QueueSelect = QSLT_VO;
break;
case VI_QUEUE:
QueueSelect = QSLT_VI;
break;
case MGNT_QUEUE:
QueueSelect = QSLT_MGNT;
break;
case BEACON_QUEUE:
QueueSelect = QSLT_BEACON;
break;
case TXCMD_QUEUE:
QueueSelect = QSLT_CMD;
break;
case HIGH_QUEUE:
QueueSelect = QSLT_HIGH;
break;
default:
RT_TRACE(COMP_ERR,
"TransmitTCB(): Impossible Queue Selection: %d\n",
QueueID);
break;
}
return QueueSelect;
}
static u8 MRateToHwRate8190Pci(u8 rate)
{
u8 ret = DESC90_RATE1M;
switch (rate) {
case MGN_1M:
ret = DESC90_RATE1M;
break;
case MGN_2M:
ret = DESC90_RATE2M;
break;
case MGN_5_5M:
ret = DESC90_RATE5_5M;
break;
case MGN_11M:
ret = DESC90_RATE11M;
break;
case MGN_6M:
ret = DESC90_RATE6M;
break;
case MGN_9M:
ret = DESC90_RATE9M;
break;
case MGN_12M:
ret = DESC90_RATE12M;
break;
case MGN_18M:
ret = DESC90_RATE18M;
break;
case MGN_24M:
ret = DESC90_RATE24M;
break;
case MGN_36M:
ret = DESC90_RATE36M;
break;
case MGN_48M:
ret = DESC90_RATE48M;
break;
case MGN_54M:
ret = DESC90_RATE54M;
break;
case MGN_MCS0:
ret = DESC90_RATEMCS0;
break;
case MGN_MCS1:
ret = DESC90_RATEMCS1;
break;
case MGN_MCS2:
ret = DESC90_RATEMCS2;
break;
case MGN_MCS3:
ret = DESC90_RATEMCS3;
break;
case MGN_MCS4:
ret = DESC90_RATEMCS4;
break;
case MGN_MCS5:
ret = DESC90_RATEMCS5;
break;
case MGN_MCS6:
ret = DESC90_RATEMCS6;
break;
case MGN_MCS7:
ret = DESC90_RATEMCS7;
break;
case MGN_MCS8:
ret = DESC90_RATEMCS8;
break;
case MGN_MCS9:
ret = DESC90_RATEMCS9;
break;
case MGN_MCS10:
ret = DESC90_RATEMCS10;
break;
case MGN_MCS11:
ret = DESC90_RATEMCS11;
break;
case MGN_MCS12:
ret = DESC90_RATEMCS12;
break;
case MGN_MCS13:
ret = DESC90_RATEMCS13;
break;
case MGN_MCS14:
ret = DESC90_RATEMCS14;
break;
case MGN_MCS15:
ret = DESC90_RATEMCS15;
break;
case (0x80 | 0x20):
ret = DESC90_RATEMCS32;
break;
default:
break;
}
return ret;
}
static u8 QueryIsShort(u8 TxHT, u8 TxRate, cb_desc *tcb_desc)
{
u8 tmp_Short;
tmp_Short = (TxHT == 1) ?
((tcb_desc->bUseShortGI) ? 1 : 0) :
((tcb_desc->bUseShortPreamble) ? 1 : 0);
if (TxHT == 1 && TxRate != DESC90_RATEMCS15)
tmp_Short = 0;
return tmp_Short;
}
static void tx_zero_isr(struct urb *tx_urb)
{
}
short rtl8192_tx(struct net_device *dev, struct sk_buff *skb)
{
struct r8192_priv *priv = ieee80211_priv(dev);
cb_desc *tcb_desc = (cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
tx_desc_819x_usb *tx_desc = (tx_desc_819x_usb *)skb->data;
tx_fwinfo_819x_usb *tx_fwinfo =
(tx_fwinfo_819x_usb *)(skb->data + USB_HWDESC_HEADER_LEN);
struct usb_device *udev = priv->udev;
int pend;
int status;
struct urb *tx_urb = NULL, *tx_urb_zero = NULL;
unsigned int idx_pipe;
pend = atomic_read(&priv->tx_pending[tcb_desc->queue_index]);
if (pend > MAX_TX_URB) {
netdev_dbg(dev, "To discard skb packet!\n");
dev_kfree_skb_any(skb);
return -1;
}
tx_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!tx_urb) {
dev_kfree_skb_any(skb);
return -ENOMEM;
}
memset(tx_fwinfo, 0, sizeof(tx_fwinfo_819x_usb));
tx_fwinfo->TxHT = (tcb_desc->data_rate & 0x80) ? 1 : 0;
tx_fwinfo->TxRate = MRateToHwRate8190Pci(tcb_desc->data_rate);
tx_fwinfo->EnableCPUDur = tcb_desc->bTxEnableFwCalcDur;
tx_fwinfo->Short = QueryIsShort(tx_fwinfo->TxHT, tx_fwinfo->TxRate,
tcb_desc);
if (tcb_desc->bAMPDUEnable) {
tx_fwinfo->AllowAggregation = 1;
tx_fwinfo->RxMF = tcb_desc->ampdu_factor;
tx_fwinfo->RxAMD = tcb_desc->ampdu_density & 0x07;
} else {
tx_fwinfo->AllowAggregation = 0;
tx_fwinfo->RxMF = 0;
tx_fwinfo->RxAMD = 0;
}
tx_fwinfo->RtsEnable = (tcb_desc->bRTSEnable) ? 1 : 0;
tx_fwinfo->CtsEnable = (tcb_desc->bCTSEnable) ? 1 : 0;
tx_fwinfo->RtsSTBC = (tcb_desc->bRTSSTBC) ? 1 : 0;
tx_fwinfo->RtsHT = (tcb_desc->rts_rate & 0x80) ? 1 : 0;
tx_fwinfo->RtsRate = MRateToHwRate8190Pci((u8)tcb_desc->rts_rate);
tx_fwinfo->RtsSubcarrier = (tx_fwinfo->RtsHT == 0) ? (tcb_desc->RTSSC) : 0;
tx_fwinfo->RtsBandwidth = (tx_fwinfo->RtsHT == 1) ? ((tcb_desc->bRTSBW) ? 1 : 0) : 0;
tx_fwinfo->RtsShort = (tx_fwinfo->RtsHT == 0) ? (tcb_desc->bRTSUseShortPreamble ? 1 : 0) :
(tcb_desc->bRTSUseShortGI ? 1 : 0);
if (priv->CurrentChannelBW == HT_CHANNEL_WIDTH_20_40) {
if (tcb_desc->bPacketBW) {
tx_fwinfo->TxBandwidth = 1;
tx_fwinfo->TxSubCarrier = 0;
} else {
tx_fwinfo->TxBandwidth = 0;
tx_fwinfo->TxSubCarrier = priv->nCur40MhzPrimeSC;
}
} else {
tx_fwinfo->TxBandwidth = 0;
tx_fwinfo->TxSubCarrier = 0;
}
memset(tx_desc, 0, sizeof(tx_desc_819x_usb));
tx_desc->LINIP = 0;
tx_desc->CmdInit = 1;
tx_desc->Offset = sizeof(tx_fwinfo_819x_usb) + 8;
tx_desc->PktSize = (skb->len - TX_PACKET_SHIFT_BYTES) & 0xffff;
tx_desc->SecCAMID = 0;
tx_desc->RATid = tcb_desc->RATRIndex;
tx_desc->NoEnc = 1;
tx_desc->SecType = 0x0;
if (tcb_desc->bHwSec) {
switch (priv->ieee80211->pairwise_key_type) {
case KEY_TYPE_WEP40:
case KEY_TYPE_WEP104:
tx_desc->SecType = 0x1;
tx_desc->NoEnc = 0;
break;
case KEY_TYPE_TKIP:
tx_desc->SecType = 0x2;
tx_desc->NoEnc = 0;
break;
case KEY_TYPE_CCMP:
tx_desc->SecType = 0x3;
tx_desc->NoEnc = 0;
break;
case KEY_TYPE_NA:
tx_desc->SecType = 0x0;
tx_desc->NoEnc = 1;
break;
}
}
tx_desc->QueueSelect = MapHwQueueToFirmwareQueue(tcb_desc->queue_index);
tx_desc->TxFWInfoSize = sizeof(tx_fwinfo_819x_usb);
tx_desc->DISFB = tcb_desc->bTxDisableRateFallBack;
tx_desc->USERATE = tcb_desc->bTxUseDriverAssingedRate;
tx_desc->FirstSeg = 1;
tx_desc->LastSeg = 1;
tx_desc->OWN = 1;
tx_desc->TxBufferSize = (u32)(skb->len - USB_HWDESC_HEADER_LEN);
idx_pipe = 0x5;
usb_fill_bulk_urb(tx_urb, udev,
usb_sndbulkpipe(udev, idx_pipe), skb->data,
skb->len, rtl8192_tx_isr, skb);
status = usb_submit_urb(tx_urb, GFP_ATOMIC);
if (!status) {
bool bSend0Byte = false;
u8 zero = 0;
if (udev->speed == USB_SPEED_HIGH) {
if (skb->len > 0 && skb->len % 512 == 0)
bSend0Byte = true;
} else {
if (skb->len > 0 && skb->len % 64 == 0)
bSend0Byte = true;
}
if (bSend0Byte) {
tx_urb_zero = usb_alloc_urb(0, GFP_ATOMIC);
if (!tx_urb_zero)
return -ENOMEM;
usb_fill_bulk_urb(tx_urb_zero, udev,
usb_sndbulkpipe(udev, idx_pipe),
&zero, 0, tx_zero_isr, dev);
status = usb_submit_urb(tx_urb_zero, GFP_ATOMIC);
if (status) {
RT_TRACE(COMP_ERR,
"Error TX URB for zero byte %d, error %d",
atomic_read(&priv->tx_pending[tcb_desc->queue_index]),
status);
return -1;
}
}
netif_trans_update(dev);
atomic_inc(&priv->tx_pending[tcb_desc->queue_index]);
return 0;
}
RT_TRACE(COMP_ERR, "Error TX URB %d, error %d",
atomic_read(&priv->tx_pending[tcb_desc->queue_index]),
status);
return -1;
}
static short rtl8192_usb_initendpoints(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
priv->rx_urb = kmalloc(sizeof(struct urb *) * (MAX_RX_URB + 1),
GFP_KERNEL);
if (!priv->rx_urb)
return -ENOMEM;
#ifndef JACKSON_NEW_RX
for (i = 0; i < (MAX_RX_URB + 1); i++) {
priv->rx_urb[i] = usb_alloc_urb(0, GFP_KERNEL);
priv->rx_urb[i]->transfer_buffer =
kmalloc(RX_URB_SIZE, GFP_KERNEL);
priv->rx_urb[i]->transfer_buffer_length = RX_URB_SIZE;
}
#endif
#ifdef THOMAS_BEACON
{
long align = 0;
void *oldaddr, *newaddr;
priv->rx_urb[16] = usb_alloc_urb(0, GFP_KERNEL);
priv->oldaddr = kmalloc(16, GFP_KERNEL);
oldaddr = priv->oldaddr;
align = ((long)oldaddr) & 3;
if (align) {
newaddr = oldaddr + 4 - align;
priv->rx_urb[16]->transfer_buffer_length = 16 - 4 + align;
} else {
newaddr = oldaddr;
priv->rx_urb[16]->transfer_buffer_length = 16;
}
priv->rx_urb[16]->transfer_buffer = newaddr;
}
#endif
memset(priv->rx_urb, 0, sizeof(struct urb *) * MAX_RX_URB);
priv->pp_rxskb = kcalloc(MAX_RX_URB, sizeof(struct sk_buff *),
GFP_KERNEL);
if (!priv->pp_rxskb) {
kfree(priv->rx_urb);
priv->pp_rxskb = NULL;
priv->rx_urb = NULL;
DMESGE("Endpoint Alloc Failure");
return -ENOMEM;
}
netdev_dbg(dev, "End of initendpoints\n");
return 0;
}
static void rtl8192_usb_deleteendpoints(struct net_device *dev)
{
int i;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->rx_urb) {
for (i = 0; i < (MAX_RX_URB + 1); i++) {
usb_kill_urb(priv->rx_urb[i]);
usb_free_urb(priv->rx_urb[i]);
}
kfree(priv->rx_urb);
priv->rx_urb = NULL;
}
kfree(priv->oldaddr);
priv->oldaddr = NULL;
kfree(priv->pp_rxskb);
priv->pp_rxskb = NULL;
}
void rtl8192_usb_deleteendpoints(struct net_device *dev)
{
int i;
struct r8192_priv *priv = ieee80211_priv(dev);
#ifndef JACKSON_NEW_RX
if (priv->rx_urb) {
for (i = 0; i < (MAX_RX_URB + 1); i++) {
usb_kill_urb(priv->rx_urb[i]);
kfree(priv->rx_urb[i]->transfer_buffer);
usb_free_urb(priv->rx_urb[i]);
}
kfree(priv->rx_urb);
priv->rx_urb = NULL;
}
#else
kfree(priv->rx_urb);
priv->rx_urb = NULL;
kfree(priv->oldaddr);
priv->oldaddr = NULL;
kfree(priv->pp_rxskb);
priv->pp_rxskb = 0;
#endif
}
static void rtl8192_link_change(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
if (ieee->state == IEEE80211_LINKED) {
rtl8192_net_update(dev);
rtl8192_update_ratr_table(dev);
if (KEY_TYPE_WEP40 == ieee->pairwise_key_type ||
KEY_TYPE_WEP104 == ieee->pairwise_key_type)
EnableHWSecurityConfig8192(dev);
}
if (ieee->iw_mode == IW_MODE_INFRA || ieee->iw_mode == IW_MODE_ADHOC) {
u32 reg = 0;
read_nic_dword(dev, RCR, &reg);
if (priv->ieee80211->state == IEEE80211_LINKED)
priv->ReceiveConfig = reg |= RCR_CBSSID;
else
priv->ReceiveConfig = reg &= ~RCR_CBSSID;
write_nic_dword(dev, RCR, reg);
}
}
static void rtl8192_update_beacon(struct work_struct *work)
{
struct r8192_priv *priv = container_of(work, struct r8192_priv,
update_beacon_wq.work);
struct net_device *dev = priv->ieee80211->dev;
struct ieee80211_device *ieee = priv->ieee80211;
struct ieee80211_network *net = &ieee->current_network;
if (ieee->pHTInfo->bCurrentHTSupport)
HTUpdateSelfAndPeerSetting(ieee, net);
ieee->pHTInfo->bCurrentRT2RTLongSlotTime =
net->bssht.bdRT2RTLongSlotTime;
rtl8192_update_cap(dev, net->capability);
}
static void rtl8192_qos_activate(struct work_struct *work)
{
struct r8192_priv *priv = container_of(work, struct r8192_priv,
qos_activate);
struct net_device *dev = priv->ieee80211->dev;
struct ieee80211_qos_parameters *qos_parameters =
&priv->ieee80211->current_network.qos_data.parameters;
u8 mode = priv->ieee80211->current_network.mode;
u32 u1bAIFS;
u32 u4bAcParam;
u32 op_limit;
u32 cw_max;
u32 cw_min;
int i;
mutex_lock(&priv->mutex);
if (priv->ieee80211->state != IEEE80211_LINKED)
goto success;
RT_TRACE(COMP_QOS,
"qos active process with associate response received\n");
for (i = 0; i < QOS_QUEUE_NUM; i++) {
u1bAIFS = qos_parameters->aifs[i] * ((mode & (IEEE_G | IEEE_N_24G)) ? 9 : 20) + aSifsTime;
u1bAIFS <<= AC_PARAM_AIFS_OFFSET;
op_limit = (u32)le16_to_cpu(qos_parameters->tx_op_limit[i]);
op_limit <<= AC_PARAM_TXOP_LIMIT_OFFSET;
cw_max = (u32)le16_to_cpu(qos_parameters->cw_max[i]);
cw_max <<= AC_PARAM_ECW_MAX_OFFSET;
cw_min = (u32)le16_to_cpu(qos_parameters->cw_min[i]);
cw_min <<= AC_PARAM_ECW_MIN_OFFSET;
u4bAcParam = op_limit | cw_max | cw_min | u1bAIFS;
write_nic_dword(dev, WDCAPARA_ADD[i], u4bAcParam);
}
success:
mutex_unlock(&priv->mutex);
}
static int rtl8192_qos_handle_probe_response(struct r8192_priv *priv,
int active_network,
struct ieee80211_network *network)
{
int ret = 0;
u32 size = sizeof(struct ieee80211_qos_parameters);
if (priv->ieee80211->state != IEEE80211_LINKED)
return ret;
if (priv->ieee80211->iw_mode != IW_MODE_INFRA)
return ret;
if (network->flags & NETWORK_HAS_QOS_MASK) {
if (active_network &&
(network->flags & NETWORK_HAS_QOS_PARAMETERS))
network->qos_data.active = network->qos_data.supported;
if ((network->qos_data.active == 1) && (active_network == 1) &&
(network->flags & NETWORK_HAS_QOS_PARAMETERS) &&
(network->qos_data.old_param_count !=
network->qos_data.param_count)) {
network->qos_data.old_param_count =
network->qos_data.param_count;
schedule_work(&priv->qos_activate);
RT_TRACE(COMP_QOS,
"QoS parameters change call qos_activate\n");
}
} else {
memcpy(&priv->ieee80211->current_network.qos_data.parameters,
&def_qos_parameters, size);
if ((network->qos_data.active == 1) && (active_network == 1)) {
schedule_work(&priv->qos_activate);
RT_TRACE(COMP_QOS,
"QoS was disabled call qos_activate\n");
}
network->qos_data.active = 0;
network->qos_data.supported = 0;
}
return 0;
}
static int rtl8192_handle_beacon(struct net_device *dev,
struct ieee80211_beacon *beacon,
struct ieee80211_network *network)
{
struct r8192_priv *priv = ieee80211_priv(dev);
rtl8192_qos_handle_probe_response(priv, 1, network);
schedule_delayed_work(&priv->update_beacon_wq, 0);
return 0;
}
static int rtl8192_qos_association_resp(struct r8192_priv *priv,
struct ieee80211_network *network)
{
unsigned long flags;
u32 size = sizeof(struct ieee80211_qos_parameters);
int set_qos_param = 0;
if (!priv || !network)
return 0;
if (priv->ieee80211->state != IEEE80211_LINKED)
return 0;
if (priv->ieee80211->iw_mode != IW_MODE_INFRA)
return 0;
spin_lock_irqsave(&priv->ieee80211->lock, flags);
if (network->flags & NETWORK_HAS_QOS_PARAMETERS) {
memcpy(&priv->ieee80211->current_network.qos_data.parameters,
&network->qos_data.parameters,
sizeof(struct ieee80211_qos_parameters));
priv->ieee80211->current_network.qos_data.active = 1;
set_qos_param = 1;
priv->ieee80211->current_network.qos_data.old_param_count =
priv->ieee80211->current_network.qos_data.param_count;
priv->ieee80211->current_network.qos_data.param_count =
network->qos_data.param_count;
} else {
memcpy(&priv->ieee80211->current_network.qos_data.parameters,
&def_qos_parameters, size);
priv->ieee80211->current_network.qos_data.active = 0;
priv->ieee80211->current_network.qos_data.supported = 0;
set_qos_param = 1;
}
spin_unlock_irqrestore(&priv->ieee80211->lock, flags);
RT_TRACE(COMP_QOS, "%s: network->flags = %d,%d\n", __func__,
network->flags,
priv->ieee80211->current_network.qos_data.active);
if (set_qos_param == 1)
schedule_work(&priv->qos_activate);
return 0;
}
static int rtl8192_handle_assoc_response(
struct net_device *dev,
struct ieee80211_assoc_response_frame *resp,
struct ieee80211_network *network)
{
struct r8192_priv *priv = ieee80211_priv(dev);
rtl8192_qos_association_resp(priv, network);
return 0;
}
static void rtl8192_update_ratr_table(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
u8 *pMcsRate = ieee->dot11HTOperationalRateSet;
u32 ratr_value = 0;
u8 rate_index = 0;
rtl8192_config_rate(dev, (u16 *)(&ratr_value));
ratr_value |= (*(u16 *)(pMcsRate)) << 12;
switch (ieee->mode) {
case IEEE_A:
ratr_value &= 0x00000FF0;
break;
case IEEE_B:
ratr_value &= 0x0000000F;
break;
case IEEE_G:
ratr_value &= 0x00000FF7;
break;
case IEEE_N_24G:
case IEEE_N_5G:
if (ieee->pHTInfo->PeerMimoPs == 0) {
ratr_value &= 0x0007F007;
} else {
if (priv->rf_type == RF_1T2R)
ratr_value &= 0x000FF007;
else
ratr_value &= 0x0F81F007;
}
break;
default:
break;
}
ratr_value &= 0x0FFFFFFF;
if (ieee->pHTInfo->bCurTxBW40MHz && ieee->pHTInfo->bCurShortGI40MHz)
ratr_value |= 0x80000000;
else if (!ieee->pHTInfo->bCurTxBW40MHz &&
ieee->pHTInfo->bCurShortGI20MHz)
ratr_value |= 0x80000000;
write_nic_dword(dev, RATR0 + rate_index * 4, ratr_value);
write_nic_byte(dev, UFWP, 1);
}
static bool GetNmodeSupportBySecCfg8192(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
struct ieee80211_network *network = &ieee->current_network;
int wpa_ie_len = ieee->wpa_ie_len;
struct ieee80211_crypt_data *crypt;
int encrypt;
crypt = ieee->crypt[ieee->tx_keyidx];
encrypt = (network->capability & WLAN_CAPABILITY_PRIVACY) ||
(ieee->host_encrypt && crypt && crypt->ops &&
(0 == strcmp(crypt->ops->name, "WEP")));
if (encrypt && (wpa_ie_len == 0)) {
return false;
} else if ((wpa_ie_len != 0)) {
if (((ieee->wpa_ie[0] == 0xdd) && (!memcmp(&(ieee->wpa_ie[14]), ccmp_ie, 4))) || ((ieee->wpa_ie[0] == 0x30) && (!memcmp(&ieee->wpa_ie[10], ccmp_rsn_ie, 4))))
return true;
else
return false;
} else {
return true;
}
return true;
}
static bool GetHalfNmodeSupportByAPs819xUsb(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return priv->ieee80211->bHalfWirelessN24GMode;
}
static void rtl8192_refresh_supportrate(struct r8192_priv *priv)
{
struct ieee80211_device *ieee = priv->ieee80211;
if (ieee->mode == WIRELESS_MODE_N_24G ||
ieee->mode == WIRELESS_MODE_N_5G)
memcpy(ieee->Regdot11HTOperationalRateSet,
ieee->RegHTSuppRateSet, 16);
else
memset(ieee->Regdot11HTOperationalRateSet, 0, 16);
}
static u8 rtl8192_getSupportedWireleeMode(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 ret = 0;
switch (priv->rf_chip) {
case RF_8225:
case RF_8256:
case RF_PSEUDO_11N:
ret = WIRELESS_MODE_N_24G | WIRELESS_MODE_G | WIRELESS_MODE_B;
break;
case RF_8258:
ret = WIRELESS_MODE_A | WIRELESS_MODE_N_5G;
break;
default:
ret = WIRELESS_MODE_B;
break;
}
return ret;
}
static void rtl8192_SetWirelessMode(struct net_device *dev, u8 wireless_mode)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 bSupportMode = rtl8192_getSupportedWireleeMode(dev);
if (wireless_mode == WIRELESS_MODE_AUTO ||
(wireless_mode & bSupportMode) == 0) {
if (bSupportMode & WIRELESS_MODE_N_24G) {
wireless_mode = WIRELESS_MODE_N_24G;
} else if (bSupportMode & WIRELESS_MODE_N_5G) {
wireless_mode = WIRELESS_MODE_N_5G;
} else if ((bSupportMode & WIRELESS_MODE_A)) {
wireless_mode = WIRELESS_MODE_A;
} else if ((bSupportMode & WIRELESS_MODE_G)) {
wireless_mode = WIRELESS_MODE_G;
} else if ((bSupportMode & WIRELESS_MODE_B)) {
wireless_mode = WIRELESS_MODE_B;
} else {
RT_TRACE(COMP_ERR,
"%s(), No valid wireless mode supported, SupportedWirelessMode(%x)!!!\n",
__func__, bSupportMode);
wireless_mode = WIRELESS_MODE_B;
}
}
#ifdef TO_DO_LIST
ActUpdateChannelAccessSetting(
pAdapter, pHalData->CurrentWirelessMode,
&pAdapter->MgntInfo.Info8185.ChannelAccessSetting);
#endif
priv->ieee80211->mode = wireless_mode;
if (wireless_mode == WIRELESS_MODE_N_24G ||
wireless_mode == WIRELESS_MODE_N_5G)
priv->ieee80211->pHTInfo->bEnableHT = 1;
else
priv->ieee80211->pHTInfo->bEnableHT = 0;
RT_TRACE(COMP_INIT, "Current Wireless Mode is %x\n", wireless_mode);
rtl8192_refresh_supportrate(priv);
}
static void rtl8192_init_priv_variable(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 i;
priv->card_8192 = NIC_8192U;
priv->chan = 1;
priv->ieee80211->mode = WIRELESS_MODE_AUTO;
priv->ieee80211->iw_mode = IW_MODE_INFRA;
priv->ieee80211->ieee_up = 0;
priv->retry_rts = DEFAULT_RETRY_RTS;
priv->retry_data = DEFAULT_RETRY_DATA;
priv->ieee80211->rts = DEFAULT_RTS_THRESHOLD;
priv->ieee80211->rate = 110;
priv->ieee80211->short_slot = 1;
priv->promisc = (dev->flags & IFF_PROMISC) ? 1 : 0;
priv->CckPwEnl = 6;
priv->IrpPendingCount = 1;
priv->ResetProgress = RESET_TYPE_NORESET;
priv->bForcedSilentReset = false;
priv->bDisableNormalResetCheck = false;
priv->force_reset = false;
priv->ieee80211->FwRWRF = 0;
priv->ieee80211->current_network.beacon_interval =
DEFAULT_BEACONINTERVAL;
priv->ieee80211->softmac_features = IEEE_SOFTMAC_SCAN |
IEEE_SOFTMAC_ASSOCIATE | IEEE_SOFTMAC_PROBERQ |
IEEE_SOFTMAC_PROBERS | IEEE_SOFTMAC_TX_QUEUE |
IEEE_SOFTMAC_BEACONS;
priv->ieee80211->active_scan = 1;
priv->ieee80211->modulation =
IEEE80211_CCK_MODULATION | IEEE80211_OFDM_MODULATION;
priv->ieee80211->host_encrypt = 1;
priv->ieee80211->host_decrypt = 1;
priv->ieee80211->start_send_beacons = NULL;
priv->ieee80211->stop_send_beacons = NULL;
priv->ieee80211->softmac_hard_start_xmit = rtl8192_hard_start_xmit;
priv->ieee80211->set_chan = rtl8192_set_chan;
priv->ieee80211->link_change = rtl8192_link_change;
priv->ieee80211->softmac_data_hard_start_xmit = rtl8192_hard_data_xmit;
priv->ieee80211->data_hard_stop = rtl8192_data_hard_stop;
priv->ieee80211->data_hard_resume = rtl8192_data_hard_resume;
priv->ieee80211->init_wmmparam_flag = 0;
priv->ieee80211->fts = DEFAULT_FRAG_THRESHOLD;
priv->ieee80211->check_nic_enough_desc = check_nic_enough_desc;
priv->ieee80211->tx_headroom = TX_PACKET_SHIFT_BYTES;
priv->ieee80211->qos_support = 1;
priv->ieee80211->SetBWModeHandler = rtl8192_SetBWMode;
priv->ieee80211->handle_assoc_response = rtl8192_handle_assoc_response;
priv->ieee80211->handle_beacon = rtl8192_handle_beacon;
priv->ieee80211->GetNmodeSupportBySecCfg = GetNmodeSupportBySecCfg8192;
priv->ieee80211->GetHalfNmodeSupportByAPsHandler =
GetHalfNmodeSupportByAPs819xUsb;
priv->ieee80211->SetWirelessMode = rtl8192_SetWirelessMode;
priv->ieee80211->InitialGainHandler = InitialGain819xUsb;
priv->card_type = USB;
#ifdef TO_DO_LIST
if (Adapter->bInHctTest) {
pHalData->ShortRetryLimit = 7;
pHalData->LongRetryLimit = 7;
}
#endif
priv->ShortRetryLimit = 0x30;
priv->LongRetryLimit = 0x30;
priv->EarlyRxThreshold = 7;
priv->enable_gpio0 = 0;
priv->TransmitConfig =
(TCR_MXDMA_2048 << TCR_MXDMA_OFFSET) |
(priv->ShortRetryLimit << TCR_SRL_OFFSET) |
(priv->LongRetryLimit << TCR_LRL_OFFSET) |
(false ? TCR_SAT : 0);
#ifdef TO_DO_LIST
if (Adapter->bInHctTest)
pHalData->ReceiveConfig =
pHalData->CSMethod |
RCR_AMF | RCR_ADF |
RCR_ACF |
RCR_AB | RCR_AM | RCR_APM |
RCR_AICV | RCR_ACRC32 |
((u32)7 << RCR_MXDMA_OFFSET) |
(pHalData->EarlyRxThreshold << RCR_FIFO_OFFSET) |
(pHalData->EarlyRxThreshold == 7 ? RCR_OnlyErlPkt : 0);
else
#endif
priv->ReceiveConfig =
RCR_AMF | RCR_ADF |
RCR_ACF |
RCR_AB | RCR_AM | RCR_APM |
((u32)7 << RCR_MXDMA_OFFSET) |
(priv->EarlyRxThreshold << RX_FIFO_THRESHOLD_SHIFT) |
(priv->EarlyRxThreshold == 7 ? RCR_ONLYERLPKT : 0);
priv->AcmControl = 0;
priv->pFirmware = kzalloc(sizeof(rt_firmware), GFP_KERNEL);
skb_queue_head_init(&priv->rx_queue);
skb_queue_head_init(&priv->skb_queue);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_head_init(&priv->ieee80211->skb_waitQ[i]);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_head_init(&priv->ieee80211->skb_aggQ[i]);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_head_init(&priv->ieee80211->skb_drv_aggQ[i]);
priv->rf_set_chan = rtl8192_phy_SwChnl;
}
static void rtl8192_init_priv_lock(struct r8192_priv *priv)
{
spin_lock_init(&priv->tx_lock);
spin_lock_init(&priv->irq_lock);
mutex_init(&priv->wx_mutex);
mutex_init(&priv->mutex);
}
static void rtl8192_init_priv_task(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
INIT_WORK(&priv->reset_wq, rtl8192_restart);
INIT_DELAYED_WORK(&priv->watch_dog_wq,
rtl819x_watchdog_wqcallback);
INIT_DELAYED_WORK(&priv->txpower_tracking_wq,
dm_txpower_trackingcallback);
INIT_DELAYED_WORK(&priv->rfpath_check_wq,
dm_rf_pathcheck_workitemcallback);
INIT_DELAYED_WORK(&priv->update_beacon_wq,
rtl8192_update_beacon);
INIT_DELAYED_WORK(&priv->initialgain_operate_wq,
InitialGainOperateWorkItemCallBack);
INIT_WORK(&priv->qos_activate, rtl8192_qos_activate);
tasklet_init(&priv->irq_rx_tasklet,
(void(*)(unsigned long))rtl8192_irq_rx_tasklet,
(unsigned long)priv);
}
static void rtl8192_get_eeprom_size(struct net_device *dev)
{
u16 curCR = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
RT_TRACE(COMP_EPROM, "===========>%s()\n", __func__);
read_nic_word_E(dev, EPROM_CMD, &curCR);
RT_TRACE(COMP_EPROM,
"read from Reg EPROM_CMD(%x):%x\n", EPROM_CMD, curCR);
priv->epromtype =
(curCR & Cmd9346CR_9356SEL) ? EPROM_93c56 : EPROM_93c46;
RT_TRACE(COMP_EPROM,
"<===========%s(), epromtype:%d\n", __func__, priv->epromtype);
}
static inline u16 endian_swap(u16 *data)
{
u16 tmp = *data;
*data = (tmp >> 8) | (tmp << 8);
return *data;
}
static int rtl8192_read_eeprom_info(struct net_device *dev)
{
u16 wEPROM_ID = 0;
u8 bMac_Tmp_Addr[6] = {0x00, 0xe0, 0x4c, 0x00, 0x00, 0x02};
u8 bLoad_From_EEPOM = false;
struct r8192_priv *priv = ieee80211_priv(dev);
u16 tmpValue = 0;
int i;
int ret;
RT_TRACE(COMP_EPROM, "===========>%s()\n", __func__);
ret = eprom_read(dev, 0);
if (ret < 0)
return ret;
wEPROM_ID = (u16)ret;
RT_TRACE(COMP_EPROM, "EEPROM ID is 0x%x\n", wEPROM_ID);
if (wEPROM_ID != RTL8190_EEPROM_ID)
RT_TRACE(COMP_ERR,
"EEPROM ID is invalid(is 0x%x(should be 0x%x)\n",
wEPROM_ID, RTL8190_EEPROM_ID);
else
bLoad_From_EEPOM = true;
if (bLoad_From_EEPOM) {
tmpValue = eprom_read(dev, EEPROM_VID >> 1);
ret = eprom_read(dev, EEPROM_VID >> 1);
if (ret < 0)
return ret;
tmpValue = (u16)ret;
priv->eeprom_vid = endian_swap(&tmpValue);
ret = eprom_read(dev, EEPROM_PID >> 1);
if (ret < 0)
return ret;
priv->eeprom_pid = (u16)ret;
ret = eprom_read(dev, EEPROM_ChannelPlan >> 1);
if (ret < 0)
return ret;
tmpValue = (u16)ret;
priv->eeprom_ChannelPlan = (tmpValue & 0xff00) >> 8;
priv->btxpowerdata_readfromEEPORM = true;
ret = eprom_read(dev, (EEPROM_Customer_ID >> 1)) >> 8;
if (ret < 0)
return ret;
priv->eeprom_CustomerID = (u16)ret;
} else {
priv->eeprom_vid = 0;
priv->eeprom_pid = 0;
priv->card_8192_version = VERSION_819xU_B;
priv->eeprom_ChannelPlan = 0;
priv->eeprom_CustomerID = 0;
}
RT_TRACE(COMP_EPROM,
"vid:0x%4x, pid:0x%4x, CustomID:0x%2x, ChanPlan:0x%x\n",
priv->eeprom_vid, priv->eeprom_pid, priv->eeprom_CustomerID,
priv->eeprom_ChannelPlan);
priv->ChannelPlan = priv->eeprom_ChannelPlan;
if (bLoad_From_EEPOM) {
int i;
for (i = 0; i < 6; i += 2) {
ret = eprom_read(dev, (u16)((EEPROM_NODE_ADDRESS_BYTE_0 + i) >> 1));
if (ret < 0)
return ret;
*(u16 *)(&dev->dev_addr[i]) = (u16)ret;
}
} else {
memcpy(dev->dev_addr, bMac_Tmp_Addr, 6);
}
RT_TRACE(COMP_EPROM, "MAC addr:%pM\n", dev->dev_addr);
priv->rf_type = RTL819X_DEFAULT_RF_TYPE;
priv->rf_chip = RF_8256;
if (priv->card_8192_version == (u8)VERSION_819xU_A) {
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_TxPowerDiff >> 1));
if (ret < 0)
return ret;
priv->EEPROMTxPowerDiff = ((u16)ret & 0xff00) >> 8;
} else
priv->EEPROMTxPowerDiff = EEPROM_Default_TxPower;
RT_TRACE(COMP_EPROM, "TxPowerDiff:%d\n", priv->EEPROMTxPowerDiff);
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_ThermalMeter >> 1));
if (ret < 0)
return ret;
priv->EEPROMThermalMeter = (u8)((u16)ret & 0x00ff);
} else
priv->EEPROMThermalMeter = EEPROM_Default_ThermalMeter;
RT_TRACE(COMP_EPROM, "ThermalMeter:%d\n", priv->EEPROMThermalMeter);
priv->TSSI_13dBm = priv->EEPROMThermalMeter * 100;
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_PwDiff >> 1));
if (ret < 0)
return ret;
priv->EEPROMPwDiff = ((u16)ret & 0x0f00) >> 8;
} else
priv->EEPROMPwDiff = EEPROM_Default_PwDiff;
RT_TRACE(COMP_EPROM, "TxPwDiff:%d\n", priv->EEPROMPwDiff);
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_CrystalCap >> 1));
if (ret < 0)
return ret;
priv->EEPROMCrystalCap = (u16)ret & 0x0f;
} else
priv->EEPROMCrystalCap = EEPROM_Default_CrystalCap;
RT_TRACE(COMP_EPROM, "CrystalCap = %d\n", priv->EEPROMCrystalCap);
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_TxPwIndex_Ver >> 1));
if (ret < 0)
return ret;
priv->EEPROM_Def_Ver = ((u16)ret & 0xff00) >> 8;
} else
priv->EEPROM_Def_Ver = 1;
RT_TRACE(COMP_EPROM, "EEPROM_DEF_VER:%d\n", priv->EEPROM_Def_Ver);
if (priv->EEPROM_Def_Ver == 0) {
int i;
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_TxPwIndex_CCK >> 1));
if (ret < 0)
return ret;
priv->EEPROMTxPowerLevelCCK = ((u16)ret & 0xff) >> 8;
} else
priv->EEPROMTxPowerLevelCCK = 0x10;
RT_TRACE(COMP_EPROM, "CCK Tx Power Levl: 0x%02x\n", priv->EEPROMTxPowerLevelCCK);
for (i = 0; i < 3; i++) {
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_TxPwIndex_OFDM_24G + i) >> 1);
if ( ret < 0)
return ret;
if (((EEPROM_TxPwIndex_OFDM_24G + i) % 2) == 0)
tmpValue = (u16)ret & 0x00ff;
else
tmpValue = ((u16)ret & 0xff00) >> 8;
} else {
tmpValue = 0x10;
}
priv->EEPROMTxPowerLevelOFDM24G[i] = (u8)tmpValue;
RT_TRACE(COMP_EPROM, "OFDM 2.4G Tx Power Level, Index %d = 0x%02x\n", i, priv->EEPROMTxPowerLevelCCK);
}
} else if (priv->EEPROM_Def_Ver == 1) {
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, EEPROM_TxPwIndex_CCK_V1 >> 1);
if (ret < 0)
return ret;
tmpValue = ((u16)ret & 0xff00) >> 8;
} else {
tmpValue = 0x10;
}
priv->EEPROMTxPowerLevelCCK_V1[0] = (u8)tmpValue;
if (bLoad_From_EEPOM) {
ret = eprom_read(dev, (EEPROM_TxPwIndex_CCK_V1 + 2) >> 1);
if (ret < 0)
return ret;
tmpValue = (u16)ret;
} else
tmpValue = 0x1010;
*((u16 *)(&priv->EEPROMTxPowerLevelCCK_V1[1])) = tmpValue;
if (bLoad_From_EEPOM)
tmpValue = eprom_read(dev,
EEPROM_TxPwIndex_OFDM_24G_V1 >> 1);
else
tmpValue = 0x1010;
*((u16 *)(&priv->EEPROMTxPowerLevelOFDM24G[0])) = tmpValue;
if (bLoad_From_EEPOM)
tmpValue = eprom_read(dev, (EEPROM_TxPwIndex_OFDM_24G_V1 + 2) >> 1);
else
tmpValue = 0x10;
priv->EEPROMTxPowerLevelOFDM24G[2] = (u8)tmpValue;
}
for (i = 0; i < 14; i++) {
if (i <= 3)
priv->TxPowerLevelOFDM24G[i] = priv->EEPROMTxPowerLevelOFDM24G[0];
else if (i >= 4 && i <= 9)
priv->TxPowerLevelOFDM24G[i] = priv->EEPROMTxPowerLevelOFDM24G[1];
else
priv->TxPowerLevelOFDM24G[i] = priv->EEPROMTxPowerLevelOFDM24G[2];
}
for (i = 0; i < 14; i++) {
if (priv->EEPROM_Def_Ver == 0) {
if (i <= 3)
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelOFDM24G[0] + (priv->EEPROMTxPowerLevelCCK - priv->EEPROMTxPowerLevelOFDM24G[1]);
else if (i >= 4 && i <= 9)
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelCCK;
else
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelOFDM24G[2] + (priv->EEPROMTxPowerLevelCCK - priv->EEPROMTxPowerLevelOFDM24G[1]);
} else if (priv->EEPROM_Def_Ver == 1) {
if (i <= 3)
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelCCK_V1[0];
else if (i >= 4 && i <= 9)
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelCCK_V1[1];
else
priv->TxPowerLevelCCK[i] = priv->EEPROMTxPowerLevelCCK_V1[2];
}
}
priv->TxPowerDiff = priv->EEPROMPwDiff;
priv->AntennaTxPwDiff[0] = (priv->EEPROMTxPowerDiff & 0xf);
priv->AntennaTxPwDiff[1] =
(priv->EEPROMTxPowerDiff & 0xf0) >> 4;
priv->CrystalCap = priv->EEPROMCrystalCap;
priv->ThermalMeter[0] = priv->EEPROMThermalMeter;
}
switch (priv->eeprom_CustomerID) {
case EEPROM_CID_RUNTOP:
priv->CustomerID = RT_CID_819x_RUNTOP;
break;
case EEPROM_CID_DLINK:
priv->CustomerID = RT_CID_DLINK;
break;
default:
priv->CustomerID = RT_CID_DEFAULT;
break;
}
switch (priv->CustomerID) {
case RT_CID_819x_RUNTOP:
priv->LedStrategy = SW_LED_MODE2;
break;
case RT_CID_DLINK:
priv->LedStrategy = SW_LED_MODE4;
break;
default:
priv->LedStrategy = SW_LED_MODE0;
break;
}
if (priv->rf_type == RF_1T2R)
RT_TRACE(COMP_EPROM, "\n1T2R config\n");
else
RT_TRACE(COMP_EPROM, "\n2T4R config\n");
init_rate_adaptive(dev);
RT_TRACE(COMP_EPROM, "<===========%s()\n", __func__);
return 0;
}
static short rtl8192_get_channel_map(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->ChannelPlan > COUNTRY_CODE_GLOBAL_DOMAIN) {
netdev_err(dev,
"rtl8180_init: Error channel plan! Set to default.\n");
priv->ChannelPlan = 0;
}
RT_TRACE(COMP_INIT, "Channel plan is %d\n", priv->ChannelPlan);
rtl819x_set_channel_map(priv->ChannelPlan, priv);
return 0;
}
static short rtl8192_init(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int err;
memset(&(priv->stats), 0, sizeof(struct Stats));
memset(priv->txqueue_to_outpipemap, 0, 9);
#ifdef PIPE12
{
int i = 0;
u8 queuetopipe[] = {3, 2, 1, 0, 4, 8, 7, 6, 5};
memcpy(priv->txqueue_to_outpipemap, queuetopipe, 9);
}
#else
{
u8 queuetopipe[] = {3, 2, 1, 0, 4, 4, 0, 4, 4};
memcpy(priv->txqueue_to_outpipemap, queuetopipe, 9);
}
#endif
rtl8192_init_priv_variable(dev);
rtl8192_init_priv_lock(priv);
rtl8192_init_priv_task(dev);
rtl8192_get_eeprom_size(dev);
err = rtl8192_read_eeprom_info(dev);
if (err) {
DMESG("Reading EEPROM info failed");
kfree(priv->pFirmware);
priv->pFirmware = NULL;
free_ieee80211(dev);
return err;
}
rtl8192_get_channel_map(dev);
init_hal_dm(dev);
setup_timer(&priv->watch_dog_timer, watch_dog_timer_callback,
(unsigned long)dev);
if (rtl8192_usb_initendpoints(dev) != 0) {
DMESG("Endopoints initialization failed");
return -ENOMEM;
}
return 0;
}
static void rtl8192_hwconfig(struct net_device *dev)
{
u32 regRATR = 0, regRRSR = 0;
u8 regBwOpMode = 0, regTmp = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
u32 ratr_value = 0;
switch (priv->ieee80211->mode) {
case WIRELESS_MODE_B:
regBwOpMode = BW_OPMODE_20MHZ;
regRATR = RATE_ALL_CCK;
regRRSR = RATE_ALL_CCK;
break;
case WIRELESS_MODE_A:
regBwOpMode = BW_OPMODE_5G | BW_OPMODE_20MHZ;
regRATR = RATE_ALL_OFDM_AG;
regRRSR = RATE_ALL_OFDM_AG;
break;
case WIRELESS_MODE_G:
regBwOpMode = BW_OPMODE_20MHZ;
regRATR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
regRRSR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
break;
case WIRELESS_MODE_AUTO:
#ifdef TO_DO_LIST
if (Adapter->bInHctTest) {
regBwOpMode = BW_OPMODE_20MHZ;
regRATR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
regRRSR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
} else
#endif
{
regBwOpMode = BW_OPMODE_20MHZ;
regRATR = RATE_ALL_CCK | RATE_ALL_OFDM_AG |
RATE_ALL_OFDM_1SS | RATE_ALL_OFDM_2SS;
regRRSR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
}
break;
case WIRELESS_MODE_N_24G:
regBwOpMode = BW_OPMODE_20MHZ;
regRATR = RATE_ALL_CCK | RATE_ALL_OFDM_AG |
RATE_ALL_OFDM_1SS | RATE_ALL_OFDM_2SS;
regRRSR = RATE_ALL_CCK | RATE_ALL_OFDM_AG;
break;
case WIRELESS_MODE_N_5G:
regBwOpMode = BW_OPMODE_5G;
regRATR = RATE_ALL_OFDM_AG | RATE_ALL_OFDM_1SS |
RATE_ALL_OFDM_2SS;
regRRSR = RATE_ALL_OFDM_AG;
break;
}
write_nic_byte(dev, BW_OPMODE, regBwOpMode);
ratr_value = regRATR;
if (priv->rf_type == RF_1T2R)
ratr_value &= ~(RATE_ALL_OFDM_2SS);
write_nic_dword(dev, RATR0, ratr_value);
write_nic_byte(dev, UFWP, 1);
read_nic_byte(dev, 0x313, &regTmp);
regRRSR = ((regTmp) << 24) | (regRRSR & 0x00ffffff);
write_nic_dword(dev, RRSR, regRRSR);
write_nic_word(dev, RETRY_LIMIT,
priv->ShortRetryLimit << RETRY_LIMIT_SHORT_SHIFT |
priv->LongRetryLimit << RETRY_LIMIT_LONG_SHIFT);
}
static bool rtl8192_adapter_start(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u32 dwRegRead = 0;
bool init_status = true;
u8 SECR_value = 0x0;
u8 tmp;
RT_TRACE(COMP_INIT, "====>%s()\n", __func__);
priv->Rf_Mode = RF_OP_By_SW_3wire;
write_nic_byte_E(dev, 0x5f, 0x80);
mdelay(50);
write_nic_byte_E(dev, 0x5f, 0xf0);
write_nic_byte_E(dev, 0x5d, 0x00);
write_nic_byte_E(dev, 0x5e, 0x80);
write_nic_byte(dev, 0x17, 0x37);
mdelay(10);
priv->pFirmware->firmware_status = FW_STATUS_0_INIT;
read_nic_dword(dev, CPU_GEN, &dwRegRead);
if (priv->pFirmware->firmware_status == FW_STATUS_0_INIT)
dwRegRead |= CPU_GEN_SYSTEM_RESET;
else if (priv->pFirmware->firmware_status == FW_STATUS_5_READY)
dwRegRead |= CPU_GEN_FIRMWARE_RESET;
else
RT_TRACE(COMP_ERR,
"ERROR in %s(): undefined firmware state(%d)\n",
__func__, priv->pFirmware->firmware_status);
write_nic_dword(dev, CPU_GEN, dwRegRead);
rtl8192_BBConfig(dev);
priv->LoopbackMode = RTL819xU_NO_LOOPBACK;
read_nic_dword(dev, CPU_GEN, &dwRegRead);
if (priv->LoopbackMode == RTL819xU_NO_LOOPBACK)
dwRegRead = (dwRegRead & CPU_GEN_NO_LOOPBACK_MSK) |
CPU_GEN_NO_LOOPBACK_SET;
else if (priv->LoopbackMode == RTL819xU_MAC_LOOPBACK)
dwRegRead |= CPU_CCK_LOOPBACK;
else
RT_TRACE(COMP_ERR,
"Serious error in %s(): wrong loopback mode setting(%d)\n",
__func__, priv->LoopbackMode);
write_nic_dword(dev, CPU_GEN, dwRegRead);
udelay(500);
read_nic_byte_E(dev, 0x5f, &tmp);
write_nic_byte_E(dev, 0x5f, tmp | 0x20);
rtl8192_hwconfig(dev);
write_nic_byte(dev, CMDR, CR_RE | CR_TE);
write_nic_dword(dev, MAC0, ((u32 *)dev->dev_addr)[0]);
write_nic_word(dev, MAC4, ((u16 *)(dev->dev_addr + 4))[0]);
write_nic_dword(dev, RCR, priv->ReceiveConfig);
write_nic_dword(dev, RQPN1,
NUM_OF_PAGE_IN_FW_QUEUE_BK << RSVD_FW_QUEUE_PAGE_BK_SHIFT |
NUM_OF_PAGE_IN_FW_QUEUE_BE << RSVD_FW_QUEUE_PAGE_BE_SHIFT |
NUM_OF_PAGE_IN_FW_QUEUE_VI << RSVD_FW_QUEUE_PAGE_VI_SHIFT |
NUM_OF_PAGE_IN_FW_QUEUE_VO << RSVD_FW_QUEUE_PAGE_VO_SHIFT);
write_nic_dword(dev, RQPN2,
NUM_OF_PAGE_IN_FW_QUEUE_MGNT << RSVD_FW_QUEUE_PAGE_MGNT_SHIFT |
NUM_OF_PAGE_IN_FW_QUEUE_CMD << RSVD_FW_QUEUE_PAGE_CMD_SHIFT);
write_nic_dword(dev, RQPN3,
APPLIED_RESERVED_QUEUE_IN_FW |
NUM_OF_PAGE_IN_FW_QUEUE_BCN << RSVD_FW_QUEUE_PAGE_BCN_SHIFT);
write_nic_dword(dev, RATR0 + 4 * 7, (RATE_ALL_OFDM_AG | RATE_ALL_CCK));
write_nic_byte(dev, ACK_TIMEOUT, 0x30);
if (priv->ResetProgress == RESET_TYPE_NORESET)
rtl8192_SetWirelessMode(dev, priv->ieee80211->mode);
if (priv->ResetProgress == RESET_TYPE_NORESET) {
CamResetAllEntry(dev);
SECR_value |= SCR_TxEncEnable;
SECR_value |= SCR_RxDecEnable;
SECR_value |= SCR_NoSKMC;
write_nic_byte(dev, SECR, SECR_value);
}
write_nic_word(dev, ATIMWND, 2);
write_nic_word(dev, BCN_INTERVAL, 100);
#define DEFAULT_EDCA 0x005e4332
{
int i;
for (i = 0; i < QOS_QUEUE_NUM; i++)
write_nic_dword(dev, WDCAPARA_ADD[i], DEFAULT_EDCA);
}
rtl8192_phy_configmac(dev);
if (priv->card_8192_version == (u8)VERSION_819xU_A) {
rtl8192_phy_getTxPower(dev);
rtl8192_phy_setTxPower(dev, priv->chan);
}
init_status = init_firmware(dev);
if (!init_status) {
RT_TRACE(COMP_ERR, "ERR!!! %s(): Firmware download is failed\n",
__func__);
return init_status;
}
RT_TRACE(COMP_INIT, "%s():after firmware download\n", __func__);
#ifdef TO_DO_LIST
if (Adapter->ResetProgress == RESET_TYPE_NORESET) {
if (pMgntInfo->RegRfOff) {
RT_TRACE((COMP_INIT | COMP_RF), DBG_LOUD,
("InitializeAdapter819xUsb(): Turn off RF for RegRfOff ----------\n"));
MgntActSet_RF_State(Adapter, eRfOff, RF_CHANGE_BY_SW);
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++)
PHY_SetRFReg(Adapter,
(RF90_RADIO_PATH_E)eRFPath,
0x4, 0xC00, 0x0);
} else if (pMgntInfo->RfOffReason > RF_CHANGE_BY_PS) {
RT_TRACE((COMP_INIT | COMP_RF), DBG_LOUD,
("InitializeAdapter819xUsb(): Turn off RF for RfOffReason(%d) ----------\n",
pMgntInfo->RfOffReason));
MgntActSet_RF_State(Adapter,
eRfOff,
pMgntInfo->RfOffReason);
} else {
pHalData->eRFPowerState = eRfOn;
pMgntInfo->RfOffReason = 0;
RT_TRACE((COMP_INIT | COMP_RF), DBG_LOUD,
("InitializeAdapter819xUsb(): RF is on ----------\n"));
}
} else {
if (pHalData->eRFPowerState == eRfOff) {
MgntActSet_RF_State(Adapter,
eRfOff,
pMgntInfo->RfOffReason);
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++)
PHY_SetRFReg(Adapter,
(RF90_RADIO_PATH_E)eRFPath,
0x4, 0xC00, 0x0);
}
}
#endif
if (priv->ResetProgress == RESET_TYPE_NORESET) {
rtl8192_phy_RFConfig(dev);
RT_TRACE(COMP_INIT, "%s():after phy RF config\n", __func__);
}
if (priv->ieee80211->FwRWRF)
priv->Rf_Mode = RF_OP_By_FW;
else
priv->Rf_Mode = RF_OP_By_SW_3wire;
rtl8192_phy_updateInitGain(dev);
rtl8192_setBBreg(dev, rFPGA0_RFMOD, bCCKEn, 0x1);
rtl8192_setBBreg(dev, rFPGA0_RFMOD, bOFDMEn, 0x1);
if (priv->ResetProgress == RESET_TYPE_NORESET) {
u8 tmpvalue;
read_nic_byte(dev, 0x301, &tmpvalue);
if (tmpvalue == 0x03) {
priv->bDcut = true;
RT_TRACE(COMP_POWER_TRACKING, "D-cut\n");
} else {
priv->bDcut = false;
RT_TRACE(COMP_POWER_TRACKING, "C-cut\n");
}
dm_initialize_txpower_tracking(dev);
if (priv->bDcut) {
u32 i, TempCCk;
u32 tmpRegA = rtl8192_QueryBBReg(dev,
rOFDM0_XATxIQImbalance,
bMaskDWord);
for (i = 0; i < TxBBGainTableLength; i++) {
if (tmpRegA == priv->txbbgain_table[i].txbbgain_value) {
priv->rfa_txpowertrackingindex = (u8)i;
priv->rfa_txpowertrackingindex_real =
(u8)i;
priv->rfa_txpowertracking_default =
priv->rfa_txpowertrackingindex;
break;
}
}
TempCCk = rtl8192_QueryBBReg(dev,
rCCK0_TxFilter1,
bMaskByte2);
for (i = 0; i < CCKTxBBGainTableLength; i++) {
if (TempCCk == priv->cck_txbbgain_table[i].ccktxbb_valuearray[0]) {
priv->cck_present_attentuation_20Mdefault = (u8)i;
break;
}
}
priv->cck_present_attentuation_40Mdefault = 0;
priv->cck_present_attentuation_difference = 0;
priv->cck_present_attentuation =
priv->cck_present_attentuation_20Mdefault;
}
}
write_nic_byte(dev, 0x87, 0x0);
return init_status;
}
static struct net_device_stats *rtl8192_stats(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return &priv->ieee80211->stats;
}
static bool HalTxCheckStuck819xUsb(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u16 RegTxCounter;
bool bStuck = false;
read_nic_word(dev, 0x128, &RegTxCounter);
RT_TRACE(COMP_RESET,
"%s():RegTxCounter is %d,TxCounter is %d\n", __func__,
RegTxCounter, priv->TxCounter);
if (priv->TxCounter == RegTxCounter)
bStuck = true;
priv->TxCounter = RegTxCounter;
return bStuck;
}
static RESET_TYPE TxCheckStuck(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 QueueID;
bool bCheckFwTxCnt = false;
for (QueueID = 0; QueueID <= BEACON_QUEUE; QueueID++) {
if (QueueID == TXCMD_QUEUE)
continue;
if ((skb_queue_len(&priv->ieee80211->skb_waitQ[QueueID]) == 0) && (skb_queue_len(&priv->ieee80211->skb_aggQ[QueueID]) == 0))
continue;
bCheckFwTxCnt = true;
}
if (bCheckFwTxCnt) {
if (HalTxCheckStuck819xUsb(dev)) {
RT_TRACE(COMP_RESET,
"TxCheckStuck(): Fw indicates no Tx condition!\n");
return RESET_TYPE_SILENT;
}
}
return RESET_TYPE_NORESET;
}
static bool HalRxCheckStuck819xUsb(struct net_device *dev)
{
u16 RegRxCounter;
struct r8192_priv *priv = ieee80211_priv(dev);
bool bStuck = false;
static u8 rx_chk_cnt;
read_nic_word(dev, 0x130, &RegRxCounter);
RT_TRACE(COMP_RESET,
"%s(): RegRxCounter is %d,RxCounter is %d\n", __func__,
RegRxCounter, priv->RxCounter);
rx_chk_cnt++;
if (priv->undecorated_smoothed_pwdb >= (RateAdaptiveTH_High + 5)) {
rx_chk_cnt = 0;
} else if (priv->undecorated_smoothed_pwdb < (RateAdaptiveTH_High + 5) &&
((priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20 && priv->undecorated_smoothed_pwdb >= RateAdaptiveTH_Low_40M) ||
(priv->CurrentChannelBW == HT_CHANNEL_WIDTH_20 && priv->undecorated_smoothed_pwdb >= RateAdaptiveTH_Low_20M))) {
if (rx_chk_cnt < 2)
return bStuck;
rx_chk_cnt = 0;
} else if (((priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20 && priv->undecorated_smoothed_pwdb < RateAdaptiveTH_Low_40M) ||
(priv->CurrentChannelBW == HT_CHANNEL_WIDTH_20 && priv->undecorated_smoothed_pwdb < RateAdaptiveTH_Low_20M)) &&
priv->undecorated_smoothed_pwdb >= VeryLowRSSI) {
if (rx_chk_cnt < 4)
return bStuck;
rx_chk_cnt = 0;
} else {
if (rx_chk_cnt < 8)
return bStuck;
rx_chk_cnt = 0;
}
if (priv->RxCounter == RegRxCounter)
bStuck = true;
priv->RxCounter = RegRxCounter;
return bStuck;
}
static RESET_TYPE RxCheckStuck(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
bool bRxCheck = false;
if (priv->IrpPendingCount > 1)
bRxCheck = true;
if (bRxCheck) {
if (HalRxCheckStuck819xUsb(dev)) {
RT_TRACE(COMP_RESET, "RxStuck Condition\n");
return RESET_TYPE_SILENT;
}
}
return RESET_TYPE_NORESET;
}
static RESET_TYPE rtl819x_ifcheck_resetornot(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
RESET_TYPE TxResetType = RESET_TYPE_NORESET;
RESET_TYPE RxResetType = RESET_TYPE_NORESET;
RT_RF_POWER_STATE rfState;
rfState = priv->ieee80211->eRFPowerState;
TxResetType = TxCheckStuck(dev);
if (rfState != eRfOff ||
(priv->ieee80211->iw_mode != IW_MODE_ADHOC)) {
RxResetType = RxCheckStuck(dev);
}
if (TxResetType == RESET_TYPE_NORMAL ||
RxResetType == RESET_TYPE_NORMAL) {
return RESET_TYPE_NORMAL;
} else if (TxResetType == RESET_TYPE_SILENT ||
RxResetType == RESET_TYPE_SILENT) {
RT_TRACE(COMP_RESET, "%s():silent reset\n", __func__);
return RESET_TYPE_SILENT;
} else {
return RESET_TYPE_NORESET;
}
}
static void CamRestoreAllEntry(struct net_device *dev)
{
u8 EntryId = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
u8 *MacAddr = priv->ieee80211->current_network.bssid;
static u8 CAM_CONST_ADDR[4][6] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x02},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x03} };
static u8 CAM_CONST_BROAD[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
RT_TRACE(COMP_SEC, "CamRestoreAllEntry:\n");
if ((priv->ieee80211->pairwise_key_type == KEY_TYPE_WEP40) ||
(priv->ieee80211->pairwise_key_type == KEY_TYPE_WEP104)) {
for (EntryId = 0; EntryId < 4; EntryId++) {
MacAddr = CAM_CONST_ADDR[EntryId];
setKey(dev, EntryId, EntryId,
priv->ieee80211->pairwise_key_type,
MacAddr, 0, NULL);
}
} else if (priv->ieee80211->pairwise_key_type == KEY_TYPE_TKIP) {
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
setKey(dev, 4, 0, priv->ieee80211->pairwise_key_type,
(u8 *)dev->dev_addr, 0, NULL);
else
setKey(dev, 4, 0, priv->ieee80211->pairwise_key_type,
MacAddr, 0, NULL);
} else if (priv->ieee80211->pairwise_key_type == KEY_TYPE_CCMP) {
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
setKey(dev, 4, 0, priv->ieee80211->pairwise_key_type,
(u8 *)dev->dev_addr, 0, NULL);
else
setKey(dev, 4, 0, priv->ieee80211->pairwise_key_type,
MacAddr, 0, NULL);
}
if (priv->ieee80211->group_key_type == KEY_TYPE_TKIP) {
MacAddr = CAM_CONST_BROAD;
for (EntryId = 1; EntryId < 4; EntryId++) {
setKey(dev, EntryId, EntryId,
priv->ieee80211->group_key_type,
MacAddr, 0, NULL);
}
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
setKey(dev, 0, 0, priv->ieee80211->group_key_type,
CAM_CONST_ADDR[0], 0, NULL);
} else if (priv->ieee80211->group_key_type == KEY_TYPE_CCMP) {
MacAddr = CAM_CONST_BROAD;
for (EntryId = 1; EntryId < 4; EntryId++) {
setKey(dev, EntryId, EntryId,
priv->ieee80211->group_key_type,
MacAddr, 0, NULL);
}
if (priv->ieee80211->iw_mode == IW_MODE_ADHOC)
setKey(dev, 0, 0, priv->ieee80211->group_key_type,
CAM_CONST_ADDR[0], 0, NULL);
}
}
static void rtl819x_ifsilentreset(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
u8 reset_times = 0;
int reset_status = 0;
struct ieee80211_device *ieee = priv->ieee80211;
if (priv->ResetProgress == RESET_TYPE_NORESET) {
RESET_START:
RT_TRACE(COMP_RESET, "=========>Reset progress!!\n");
priv->ResetProgress = RESET_TYPE_SILENT;
mutex_lock(&priv->wx_mutex);
if (priv->up == 0) {
RT_TRACE(COMP_ERR,
"%s():the driver is not up! return\n",
__func__);
mutex_unlock(&priv->wx_mutex);
return;
}
priv->up = 0;
RT_TRACE(COMP_RESET,
"%s():======>start to down the driver\n",
__func__);
rtl8192_rtx_disable(dev);
rtl8192_cancel_deferred_work(priv);
deinit_hal_dm(dev);
del_timer_sync(&priv->watch_dog_timer);
ieee->sync_scan_hurryup = 1;
if (ieee->state == IEEE80211_LINKED) {
mutex_lock(&ieee->wx_mutex);
netdev_dbg(dev, "ieee->state is IEEE80211_LINKED\n");
ieee80211_stop_send_beacons(priv->ieee80211);
del_timer_sync(&ieee->associate_timer);
cancel_delayed_work(&ieee->associate_retry_wq);
ieee80211_stop_scan(ieee);
netif_carrier_off(dev);
mutex_unlock(&ieee->wx_mutex);
} else {
netdev_dbg(dev, "ieee->state is NOT LINKED\n");
ieee80211_softmac_stop_protocol(priv->ieee80211);
}
mutex_unlock(&priv->wx_mutex);
RT_TRACE(COMP_RESET,
"%s():<==========down process is finished\n",
__func__);
RT_TRACE(COMP_RESET,
"%s():===========>start up the driver\n",
__func__);
reset_status = _rtl8192_up(dev);
RT_TRACE(COMP_RESET,
"%s():<===========up process is finished\n",
__func__);
if (reset_status == -EAGAIN) {
if (reset_times < 3) {
reset_times++;
goto RESET_START;
} else {
RT_TRACE(COMP_ERR,
" ERR!!! %s(): Reset Failed!!\n",
__func__);
}
}
ieee->is_silent_reset = 1;
EnableHWSecurityConfig8192(dev);
if (ieee->state == IEEE80211_LINKED &&
ieee->iw_mode == IW_MODE_INFRA) {
ieee->set_chan(ieee->dev,
ieee->current_network.channel);
queue_work(ieee->wq, &ieee->associate_complete_wq);
} else if (ieee->state == IEEE80211_LINKED &&
ieee->iw_mode == IW_MODE_ADHOC) {
ieee->set_chan(ieee->dev,
ieee->current_network.channel);
ieee->link_change(ieee->dev);
ieee80211_start_send_beacons(ieee);
if (ieee->data_hard_resume)
ieee->data_hard_resume(ieee->dev);
netif_carrier_on(ieee->dev);
}
CamRestoreAllEntry(dev);
priv->ResetProgress = RESET_TYPE_NORESET;
priv->reset_count++;
priv->bForcedSilentReset = false;
priv->bResetInProgress = false;
write_nic_byte(dev, UFWP, 1);
RT_TRACE(COMP_RESET,
"Reset finished!! ====>[%d]\n",
priv->reset_count);
}
}
static void rtl819x_update_rxcounts(struct r8192_priv *priv, u32 *TotalRxBcnNum,
u32 *TotalRxDataNum)
{
u16 SlotIndex;
u8 i;
*TotalRxBcnNum = 0;
*TotalRxDataNum = 0;
SlotIndex = (priv->ieee80211->LinkDetectInfo.SlotIndex++) %
(priv->ieee80211->LinkDetectInfo.SlotNum);
priv->ieee80211->LinkDetectInfo.RxBcnNum[SlotIndex] =
priv->ieee80211->LinkDetectInfo.NumRecvBcnInPeriod;
priv->ieee80211->LinkDetectInfo.RxDataNum[SlotIndex] =
priv->ieee80211->LinkDetectInfo.NumRecvDataInPeriod;
for (i = 0; i < priv->ieee80211->LinkDetectInfo.SlotNum; i++) {
*TotalRxBcnNum += priv->ieee80211->LinkDetectInfo.RxBcnNum[i];
*TotalRxDataNum += priv->ieee80211->LinkDetectInfo.RxDataNum[i];
}
}
static void rtl819x_watchdog_wqcallback(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct r8192_priv *priv = container_of(dwork,
struct r8192_priv, watch_dog_wq);
struct net_device *dev = priv->ieee80211->dev;
struct ieee80211_device *ieee = priv->ieee80211;
RESET_TYPE ResetType = RESET_TYPE_NORESET;
static u8 check_reset_cnt;
bool bBusyTraffic = false;
u32 TotalRxBcnNum = 0;
u32 TotalRxDataNum = 0;
if (!priv->up)
return;
hal_dm_watchdog(dev);
if (ieee->state == IEEE80211_LINKED) {
if (ieee->LinkDetectInfo.NumRxOkInPeriod > 666 ||
ieee->LinkDetectInfo.NumTxOkInPeriod > 666) {
bBusyTraffic = true;
}
ieee->LinkDetectInfo.NumRxOkInPeriod = 0;
ieee->LinkDetectInfo.NumTxOkInPeriod = 0;
ieee->LinkDetectInfo.bBusyTraffic = bBusyTraffic;
}
if (priv->ieee80211->state == IEEE80211_LINKED &&
priv->ieee80211->iw_mode == IW_MODE_INFRA) {
rtl819x_update_rxcounts(priv, &TotalRxBcnNum, &TotalRxDataNum);
if ((TotalRxBcnNum + TotalRxDataNum) == 0) {
#ifdef TODO
if (rfState == eRfOff)
RT_TRACE(COMP_ERR, "========>%s()\n", __func__);
#endif
netdev_dbg(dev,
"===>%s(): AP is power off, connect another one\n",
__func__);
priv->ieee80211->state = IEEE80211_ASSOCIATING;
notify_wx_assoc_event(priv->ieee80211);
RemovePeerTS(priv->ieee80211,
priv->ieee80211->current_network.bssid);
priv->ieee80211->link_change(dev);
queue_work(priv->ieee80211->wq,
&priv->ieee80211->associate_procedure_wq);
}
}
priv->ieee80211->LinkDetectInfo.NumRecvBcnInPeriod = 0;
priv->ieee80211->LinkDetectInfo.NumRecvDataInPeriod = 0;
if (check_reset_cnt++ >= 3) {
ResetType = rtl819x_ifcheck_resetornot(dev);
check_reset_cnt = 3;
}
if ((priv->force_reset) || (priv->ResetProgress == RESET_TYPE_NORESET &&
(priv->bForcedSilentReset ||
(!priv->bDisableNormalResetCheck && ResetType == RESET_TYPE_SILENT)))) {
RT_TRACE(COMP_RESET,
"%s():priv->force_reset is %d,priv->ResetProgress is %d, priv->bForcedSilentReset is %d,priv->bDisableNormalResetCheck is %d,ResetType is %d\n",
__func__, priv->force_reset, priv->ResetProgress,
priv->bForcedSilentReset,
priv->bDisableNormalResetCheck, ResetType);
rtl819x_ifsilentreset(dev);
}
priv->force_reset = false;
priv->bForcedSilentReset = false;
priv->bResetInProgress = false;
RT_TRACE(COMP_TRACE, " <==RtUsbCheckForHangWorkItemCallback()\n");
}
static void watch_dog_timer_callback(unsigned long data)
{
struct r8192_priv *priv = ieee80211_priv((struct net_device *)data);
schedule_delayed_work(&priv->watch_dog_wq, 0);
mod_timer(&priv->watch_dog_timer,
jiffies + msecs_to_jiffies(IEEE80211_WATCH_DOG_TIME));
}
static int _rtl8192_up(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int init_status = 0;
priv->up = 1;
priv->ieee80211->ieee_up = 1;
RT_TRACE(COMP_INIT, "Bringing up iface");
init_status = rtl8192_adapter_start(dev);
if (!init_status) {
RT_TRACE(COMP_ERR, "ERR!!! %s(): initialization failed!\n",
__func__);
priv->up = priv->ieee80211->ieee_up = 0;
return -EAGAIN;
}
RT_TRACE(COMP_INIT, "start adapter finished\n");
rtl8192_rx_enable(dev);
if (priv->ieee80211->state != IEEE80211_LINKED)
ieee80211_softmac_start_protocol(priv->ieee80211);
ieee80211_reset_queue(priv->ieee80211);
watch_dog_timer_callback((unsigned long)dev);
if (!netif_queue_stopped(dev))
netif_start_queue(dev);
else
netif_wake_queue(dev);
return 0;
}
static int rtl8192_open(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
mutex_lock(&priv->wx_mutex);
ret = rtl8192_up(dev);
mutex_unlock(&priv->wx_mutex);
return ret;
}
int rtl8192_up(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->up == 1)
return -1;
return _rtl8192_up(dev);
}
static int rtl8192_close(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
mutex_lock(&priv->wx_mutex);
ret = rtl8192_down(dev);
mutex_unlock(&priv->wx_mutex);
return ret;
}
int rtl8192_down(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int i;
if (priv->up == 0)
return -1;
priv->up = 0;
priv->ieee80211->ieee_up = 0;
RT_TRACE(COMP_DOWN, "==========>%s()\n", __func__);
if (!netif_queue_stopped(dev))
netif_stop_queue(dev);
rtl8192_rtx_disable(dev);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_purge(&priv->ieee80211->skb_waitQ[i]);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_purge(&priv->ieee80211->skb_aggQ[i]);
for (i = 0; i < MAX_QUEUE_SIZE; i++)
skb_queue_purge(&priv->ieee80211->skb_drv_aggQ[i]);
rtl8192_cancel_deferred_work(priv);
deinit_hal_dm(dev);
del_timer_sync(&priv->watch_dog_timer);
ieee80211_softmac_stop_protocol(priv->ieee80211);
memset(&priv->ieee80211->current_network, 0,
offsetof(struct ieee80211_network, list));
RT_TRACE(COMP_DOWN, "<==========%s()\n", __func__);
return 0;
}
void rtl8192_commit(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int reset_status = 0;
if (priv->up == 0)
return;
priv->up = 0;
rtl8192_cancel_deferred_work(priv);
del_timer_sync(&priv->watch_dog_timer);
ieee80211_softmac_stop_protocol(priv->ieee80211);
rtl8192_rtx_disable(dev);
reset_status = _rtl8192_up(dev);
}
static void rtl8192_restart(struct work_struct *work)
{
struct r8192_priv *priv = container_of(work, struct r8192_priv,
reset_wq);
struct net_device *dev = priv->ieee80211->dev;
mutex_lock(&priv->wx_mutex);
rtl8192_commit(dev);
mutex_unlock(&priv->wx_mutex);
}
static void r8192_set_multicast(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
short promisc;
promisc = (dev->flags & IFF_PROMISC) ? 1 : 0;
if (promisc != priv->promisc)
priv->promisc = promisc;
}
static int r8192_set_mac_adr(struct net_device *dev, void *mac)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct sockaddr *addr = mac;
mutex_lock(&priv->wx_mutex);
ether_addr_copy(dev->dev_addr, addr->sa_data);
schedule_work(&priv->reset_wq);
mutex_unlock(&priv->wx_mutex);
return 0;
}
static int rtl8192_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct iwreq *wrq = (struct iwreq *)rq;
int ret = -1;
struct ieee80211_device *ieee = priv->ieee80211;
u32 key[4];
u8 broadcast_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
struct iw_point *p = &wrq->u.data;
struct ieee_param *ipw = NULL;
mutex_lock(&priv->wx_mutex);
if (p->length < sizeof(struct ieee_param) || !p->pointer) {
ret = -EINVAL;
goto out;
}
ipw = memdup_user(p->pointer, p->length);
if (IS_ERR(ipw)) {
ret = PTR_ERR(ipw);
goto out;
}
switch (cmd) {
case RTL_IOCTL_WPA_SUPPLICANT:
if (ipw->cmd == IEEE_CMD_SET_ENCRYPTION) {
if (ipw->u.crypt.set_tx) {
if (strcmp(ipw->u.crypt.alg, "CCMP") == 0) {
ieee->pairwise_key_type = KEY_TYPE_CCMP;
} else if (strcmp(ipw->u.crypt.alg, "TKIP") == 0) {
ieee->pairwise_key_type = KEY_TYPE_TKIP;
} else if (strcmp(ipw->u.crypt.alg, "WEP") == 0) {
if (ipw->u.crypt.key_len == 13)
ieee->pairwise_key_type = KEY_TYPE_WEP104;
else if (ipw->u.crypt.key_len == 5)
ieee->pairwise_key_type = KEY_TYPE_WEP40;
} else {
ieee->pairwise_key_type = KEY_TYPE_NA;
}
if (ieee->pairwise_key_type) {
memcpy((u8 *)key, ipw->u.crypt.key, 16);
EnableHWSecurityConfig8192(dev);
setKey(dev, 4, ipw->u.crypt.idx,
ieee->pairwise_key_type,
(u8 *)ieee->ap_mac_addr,
0, key);
if (ieee->auth_mode != 2)
setKey(dev, ipw->u.crypt.idx,
ipw->u.crypt.idx,
ieee->pairwise_key_type,
(u8 *)ieee->ap_mac_addr,
0, key);
}
} else {
memcpy((u8 *)key, ipw->u.crypt.key, 16);
if (strcmp(ipw->u.crypt.alg, "CCMP") == 0) {
ieee->group_key_type = KEY_TYPE_CCMP;
} else if (strcmp(ipw->u.crypt.alg, "TKIP") == 0) {
ieee->group_key_type = KEY_TYPE_TKIP;
} else if (strcmp(ipw->u.crypt.alg, "WEP") == 0) {
if (ipw->u.crypt.key_len == 13)
ieee->group_key_type = KEY_TYPE_WEP104;
else if (ipw->u.crypt.key_len == 5)
ieee->group_key_type = KEY_TYPE_WEP40;
} else {
ieee->group_key_type = KEY_TYPE_NA;
}
if (ieee->group_key_type) {
setKey(dev, ipw->u.crypt.idx,
ipw->u.crypt.idx,
ieee->group_key_type,
broadcast_addr,
0,
key);
}
}
}
ret = ieee80211_wpa_supplicant_ioctl(priv->ieee80211,
&wrq->u.data);
break;
default:
ret = -EOPNOTSUPP;
break;
}
kfree(ipw);
ipw = NULL;
out:
mutex_unlock(&priv->wx_mutex);
return ret;
}
static u8 HwRateToMRate90(bool bIsHT, u8 rate)
{
u8 ret_rate = 0xff;
if (!bIsHT) {
switch (rate) {
case DESC90_RATE1M:
ret_rate = MGN_1M;
break;
case DESC90_RATE2M:
ret_rate = MGN_2M;
break;
case DESC90_RATE5_5M:
ret_rate = MGN_5_5M;
break;
case DESC90_RATE11M:
ret_rate = MGN_11M;
break;
case DESC90_RATE6M:
ret_rate = MGN_6M;
break;
case DESC90_RATE9M:
ret_rate = MGN_9M;
break;
case DESC90_RATE12M:
ret_rate = MGN_12M;
break;
case DESC90_RATE18M:
ret_rate = MGN_18M;
break;
case DESC90_RATE24M:
ret_rate = MGN_24M;
break;
case DESC90_RATE36M:
ret_rate = MGN_36M;
break;
case DESC90_RATE48M:
ret_rate = MGN_48M;
break;
case DESC90_RATE54M:
ret_rate = MGN_54M;
break;
default:
ret_rate = 0xff;
RT_TRACE(COMP_RECV,
"HwRateToMRate90(): Non supported Rate [%x], bIsHT = %d!!!\n",
rate, bIsHT);
break;
}
} else {
switch (rate) {
case DESC90_RATEMCS0:
ret_rate = MGN_MCS0;
break;
case DESC90_RATEMCS1:
ret_rate = MGN_MCS1;
break;
case DESC90_RATEMCS2:
ret_rate = MGN_MCS2;
break;
case DESC90_RATEMCS3:
ret_rate = MGN_MCS3;
break;
case DESC90_RATEMCS4:
ret_rate = MGN_MCS4;
break;
case DESC90_RATEMCS5:
ret_rate = MGN_MCS5;
break;
case DESC90_RATEMCS6:
ret_rate = MGN_MCS6;
break;
case DESC90_RATEMCS7:
ret_rate = MGN_MCS7;
break;
case DESC90_RATEMCS8:
ret_rate = MGN_MCS8;
break;
case DESC90_RATEMCS9:
ret_rate = MGN_MCS9;
break;
case DESC90_RATEMCS10:
ret_rate = MGN_MCS10;
break;
case DESC90_RATEMCS11:
ret_rate = MGN_MCS11;
break;
case DESC90_RATEMCS12:
ret_rate = MGN_MCS12;
break;
case DESC90_RATEMCS13:
ret_rate = MGN_MCS13;
break;
case DESC90_RATEMCS14:
ret_rate = MGN_MCS14;
break;
case DESC90_RATEMCS15:
ret_rate = MGN_MCS15;
break;
case DESC90_RATEMCS32:
ret_rate = 0x80 | 0x20;
break;
default:
ret_rate = 0xff;
RT_TRACE(COMP_RECV,
"HwRateToMRate90(): Non supported Rate [%x], bIsHT = %d!!!\n",
rate, bIsHT);
break;
}
}
return ret_rate;
}
static void UpdateRxPktTimeStamp8190(struct net_device *dev,
struct ieee80211_rx_stats *stats)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
if (stats->bIsAMPDU && !stats->bFirstMPDU) {
stats->mac_time[0] = priv->LastRxDescTSFLow;
stats->mac_time[1] = priv->LastRxDescTSFHigh;
} else {
priv->LastRxDescTSFLow = stats->mac_time[0];
priv->LastRxDescTSFHigh = stats->mac_time[1];
}
}
static long rtl819x_translate_todbm(u8 signal_strength_index)
{
long signal_power;
signal_power = (long)((signal_strength_index + 1) >> 1);
signal_power -= 95;
return signal_power;
}
static void rtl8192_process_phyinfo(struct r8192_priv *priv, u8 *buffer,
struct ieee80211_rx_stats *pprevious_stats,
struct ieee80211_rx_stats *pcurrent_stats)
{
bool bcheck = false;
u8 rfpath;
u32 nspatial_stream, tmp_val;
static u32 slide_rssi_index, slide_rssi_statistics;
static u32 slide_evm_index, slide_evm_statistics;
static u32 last_rssi, last_evm;
static u32 slide_beacon_adc_pwdb_index;
static u32 slide_beacon_adc_pwdb_statistics;
static u32 last_beacon_adc_pwdb;
struct rtl_80211_hdr_3addr *hdr;
u16 sc;
unsigned int frag, seq;
hdr = (struct rtl_80211_hdr_3addr *)buffer;
sc = le16_to_cpu(hdr->seq_ctl);
frag = WLAN_GET_SEQ_FRAG(sc);
seq = WLAN_GET_SEQ_SEQ(sc);
pcurrent_stats->Seq_Num = seq;
if (!pprevious_stats->bIsAMPDU) {
bcheck = true;
}
if (slide_rssi_statistics++ >= PHY_RSSI_SLID_WIN_MAX) {
slide_rssi_statistics = PHY_RSSI_SLID_WIN_MAX;
last_rssi = priv->stats.slide_signal_strength[slide_rssi_index];
priv->stats.slide_rssi_total -= last_rssi;
}
priv->stats.slide_rssi_total += pprevious_stats->SignalStrength;
priv->stats.slide_signal_strength[slide_rssi_index++] =
pprevious_stats->SignalStrength;
if (slide_rssi_index >= PHY_RSSI_SLID_WIN_MAX)
slide_rssi_index = 0;
tmp_val = priv->stats.slide_rssi_total / slide_rssi_statistics;
priv->stats.signal_strength = rtl819x_translate_todbm((u8)tmp_val);
pcurrent_stats->rssi = priv->stats.signal_strength;
if (!pprevious_stats->bPacketMatchBSSID) {
if (!pprevious_stats->bToSelfBA)
return;
}
if (!bcheck)
return;
priv->stats.num_process_phyinfo++;
if (!pprevious_stats->bIsCCK &&
(pprevious_stats->bPacketToSelf || pprevious_stats->bToSelfBA)) {
for (rfpath = RF90_PATH_A; rfpath < priv->NumTotalRFPath; rfpath++) {
if (!rtl8192_phy_CheckIsLegalRFPath(
priv->ieee80211->dev, rfpath))
continue;
if (priv->stats.rx_rssi_percentage[rfpath] == 0)
priv->stats.rx_rssi_percentage[rfpath] =
pprevious_stats->RxMIMOSignalStrength[rfpath];
if (pprevious_stats->RxMIMOSignalStrength[rfpath] > priv->stats.rx_rssi_percentage[rfpath]) {
priv->stats.rx_rssi_percentage[rfpath] =
((priv->stats.rx_rssi_percentage[rfpath] * (Rx_Smooth_Factor - 1)) +
(pprevious_stats->RxMIMOSignalStrength[rfpath])) / (Rx_Smooth_Factor);
priv->stats.rx_rssi_percentage[rfpath] = priv->stats.rx_rssi_percentage[rfpath] + 1;
} else {
priv->stats.rx_rssi_percentage[rfpath] =
((priv->stats.rx_rssi_percentage[rfpath] * (Rx_Smooth_Factor - 1)) +
(pprevious_stats->RxMIMOSignalStrength[rfpath])) / (Rx_Smooth_Factor);
}
RT_TRACE(COMP_DBG,
"priv->stats.rx_rssi_percentage[rfPath] = %d\n",
priv->stats.rx_rssi_percentage[rfpath]);
}
}
RT_TRACE(COMP_RXDESC, "Smooth %s PWDB = %d\n",
pprevious_stats->bIsCCK ? "CCK" : "OFDM",
pprevious_stats->RxPWDBAll);
if (pprevious_stats->bPacketBeacon) {
if (slide_beacon_adc_pwdb_statistics++ >= PHY_Beacon_RSSI_SLID_WIN_MAX) {
slide_beacon_adc_pwdb_statistics = PHY_Beacon_RSSI_SLID_WIN_MAX;
last_beacon_adc_pwdb = priv->stats.Slide_Beacon_pwdb[slide_beacon_adc_pwdb_index];
priv->stats.Slide_Beacon_Total -= last_beacon_adc_pwdb;
}
priv->stats.Slide_Beacon_Total += pprevious_stats->RxPWDBAll;
priv->stats.Slide_Beacon_pwdb[slide_beacon_adc_pwdb_index] = pprevious_stats->RxPWDBAll;
slide_beacon_adc_pwdb_index++;
if (slide_beacon_adc_pwdb_index >= PHY_Beacon_RSSI_SLID_WIN_MAX)
slide_beacon_adc_pwdb_index = 0;
pprevious_stats->RxPWDBAll = priv->stats.Slide_Beacon_Total / slide_beacon_adc_pwdb_statistics;
if (pprevious_stats->RxPWDBAll >= 3)
pprevious_stats->RxPWDBAll -= 3;
}
RT_TRACE(COMP_RXDESC, "Smooth %s PWDB = %d\n",
pprevious_stats->bIsCCK ? "CCK" : "OFDM",
pprevious_stats->RxPWDBAll);
if (pprevious_stats->bPacketToSelf ||
pprevious_stats->bPacketBeacon ||
pprevious_stats->bToSelfBA) {
if (priv->undecorated_smoothed_pwdb < 0)
priv->undecorated_smoothed_pwdb =
pprevious_stats->RxPWDBAll;
if (pprevious_stats->RxPWDBAll > (u32)priv->undecorated_smoothed_pwdb) {
priv->undecorated_smoothed_pwdb =
(((priv->undecorated_smoothed_pwdb) * (Rx_Smooth_Factor - 1)) +
(pprevious_stats->RxPWDBAll)) / (Rx_Smooth_Factor);
priv->undecorated_smoothed_pwdb = priv->undecorated_smoothed_pwdb + 1;
} else {
priv->undecorated_smoothed_pwdb =
(((priv->undecorated_smoothed_pwdb) * (Rx_Smooth_Factor - 1)) +
(pprevious_stats->RxPWDBAll)) / (Rx_Smooth_Factor);
}
}
if (pprevious_stats->SignalQuality) {
if (pprevious_stats->bPacketToSelf ||
pprevious_stats->bPacketBeacon ||
pprevious_stats->bToSelfBA) {
if (slide_evm_statistics++ >= PHY_RSSI_SLID_WIN_MAX) {
slide_evm_statistics = PHY_RSSI_SLID_WIN_MAX;
last_evm = priv->stats.slide_evm[slide_evm_index];
priv->stats.slide_evm_total -= last_evm;
}
priv->stats.slide_evm_total +=
pprevious_stats->SignalQuality;
priv->stats.slide_evm[slide_evm_index++] =
pprevious_stats->SignalQuality;
if (slide_evm_index >= PHY_RSSI_SLID_WIN_MAX)
slide_evm_index = 0;
tmp_val = priv->stats.slide_evm_total /
slide_evm_statistics;
priv->stats.signal_quality = tmp_val;
priv->stats.last_signal_strength_inpercent = tmp_val;
}
if (pprevious_stats->bPacketToSelf ||
pprevious_stats->bPacketBeacon ||
pprevious_stats->bToSelfBA) {
for (nspatial_stream = 0; nspatial_stream < 2; nspatial_stream++) {
if (pprevious_stats->RxMIMOSignalQuality[nspatial_stream] != -1) {
if (priv->stats.rx_evm_percentage[nspatial_stream] == 0)
priv->stats.rx_evm_percentage[nspatial_stream] = pprevious_stats->RxMIMOSignalQuality[nspatial_stream];
priv->stats.rx_evm_percentage[nspatial_stream] =
((priv->stats.rx_evm_percentage[nspatial_stream] * (Rx_Smooth_Factor - 1)) +
(pprevious_stats->RxMIMOSignalQuality[nspatial_stream] * 1)) / (Rx_Smooth_Factor);
}
}
}
}
}
static u8 rtl819x_query_rxpwrpercentage(s8 antpower)
{
if ((antpower <= -100) || (antpower >= 20))
return 0;
else if (antpower >= 0)
return 100;
else
return 100 + antpower;
}
static u8 rtl819x_evm_dbtopercentage(s8 value)
{
s8 ret_val;
ret_val = value;
if (ret_val >= 0)
ret_val = 0;
if (ret_val <= -33)
ret_val = -33;
ret_val = 0 - ret_val;
ret_val *= 3;
if (ret_val == 99)
ret_val = 100;
return ret_val;
}
static long rtl819x_signal_scale_mapping(long currsig)
{
long retsig;
if (currsig >= 61 && currsig <= 100)
retsig = 90 + ((currsig - 60) / 4);
else if (currsig >= 41 && currsig <= 60)
retsig = 78 + ((currsig - 40) / 2);
else if (currsig >= 31 && currsig <= 40)
retsig = 66 + (currsig - 30);
else if (currsig >= 21 && currsig <= 30)
retsig = 54 + (currsig - 20);
else if (currsig >= 5 && currsig <= 20)
retsig = 42 + (((currsig - 5) * 2) / 3);
else if (currsig == 4)
retsig = 36;
else if (currsig == 3)
retsig = 27;
else if (currsig == 2)
retsig = 18;
else if (currsig == 1)
retsig = 9;
else
retsig = currsig;
return retsig;
}
static inline bool rx_hal_is_cck_rate(struct rx_drvinfo_819x_usb *pdrvinfo)
{
if (pdrvinfo->RxHT)
return false;
switch (pdrvinfo->RxRate) {
case DESC90_RATE1M:
case DESC90_RATE2M:
case DESC90_RATE5_5M:
case DESC90_RATE11M:
return true;
default:
return false;
}
}
static void rtl8192_query_rxphystatus(struct r8192_priv *priv,
struct ieee80211_rx_stats *pstats,
rx_drvinfo_819x_usb *pdrvinfo,
struct ieee80211_rx_stats *precord_stats,
bool bpacket_match_bssid,
bool bpacket_toself,
bool bPacketBeacon,
bool bToSelfBA)
{
phy_sts_ofdm_819xusb_t *pofdm_buf;
phy_sts_cck_819xusb_t *pcck_buf;
phy_ofdm_rx_status_rxsc_sgien_exintfflag *prxsc;
u8 *prxpkt;
u8 i, max_spatial_stream, tmp_rxsnr, tmp_rxevm, rxsc_sgien_exflg;
s8 rx_pwr[4], rx_pwr_all = 0;
s8 rx_snrX, rx_evmX;
u8 evm, pwdb_all;
u32 RSSI, total_rssi = 0;
u8 is_cck_rate = 0;
u8 rf_rx_num = 0;
u8 sq;
priv->stats.numqry_phystatus++;
is_cck_rate = rx_hal_is_cck_rate(pdrvinfo);
memset(precord_stats, 0, sizeof(struct ieee80211_rx_stats));
pstats->bPacketMatchBSSID =
precord_stats->bPacketMatchBSSID = bpacket_match_bssid;
pstats->bPacketToSelf = precord_stats->bPacketToSelf = bpacket_toself;
pstats->bIsCCK = precord_stats->bIsCCK = is_cck_rate;
pstats->bPacketBeacon = precord_stats->bPacketBeacon = bPacketBeacon;
pstats->bToSelfBA = precord_stats->bToSelfBA = bToSelfBA;
prxpkt = (u8 *)pdrvinfo;
prxpkt += sizeof(rx_drvinfo_819x_usb);
pcck_buf = (phy_sts_cck_819xusb_t *)prxpkt;
pofdm_buf = (phy_sts_ofdm_819xusb_t *)prxpkt;
pstats->RxMIMOSignalQuality[0] = -1;
pstats->RxMIMOSignalQuality[1] = -1;
precord_stats->RxMIMOSignalQuality[0] = -1;
precord_stats->RxMIMOSignalQuality[1] = -1;
if (is_cck_rate) {
u8 report;
priv->stats.numqry_phystatusCCK++;
if (!priv->bCckHighPower) {
report = pcck_buf->cck_agc_rpt & 0xc0;
report >>= 6;
switch (report) {
case 0x3:
rx_pwr_all = -35 - (pcck_buf->cck_agc_rpt & 0x3e);
break;
case 0x2:
rx_pwr_all = -23 - (pcck_buf->cck_agc_rpt & 0x3e);
break;
case 0x1:
rx_pwr_all = -11 - (pcck_buf->cck_agc_rpt & 0x3e);
break;
case 0x0:
rx_pwr_all = 6 - (pcck_buf->cck_agc_rpt & 0x3e);
break;
}
} else {
report = pcck_buf->cck_agc_rpt & 0x60;
report >>= 5;
switch (report) {
case 0x3:
rx_pwr_all = -35 - ((pcck_buf->cck_agc_rpt & 0x1f) << 1);
break;
case 0x2:
rx_pwr_all = -23 - ((pcck_buf->cck_agc_rpt & 0x1f) << 1);
break;
case 0x1:
rx_pwr_all = -11 - ((pcck_buf->cck_agc_rpt & 0x1f) << 1);
break;
case 0x0:
rx_pwr_all = 6 - ((pcck_buf->cck_agc_rpt & 0x1f) << 1);
break;
}
}
pwdb_all = rtl819x_query_rxpwrpercentage(rx_pwr_all);
pstats->RxPWDBAll = precord_stats->RxPWDBAll = pwdb_all;
pstats->RecvSignalPower = pwdb_all;
if (pstats->RxPWDBAll > 40) {
sq = 100;
} else {
sq = pcck_buf->sq_rpt;
if (pcck_buf->sq_rpt > 64)
sq = 0;
else if (pcck_buf->sq_rpt < 20)
sq = 100;
else
sq = ((64 - sq) * 100) / 44;
}
pstats->SignalQuality = precord_stats->SignalQuality = sq;
pstats->RxMIMOSignalQuality[0] =
precord_stats->RxMIMOSignalQuality[0] = sq;
pstats->RxMIMOSignalQuality[1] =
precord_stats->RxMIMOSignalQuality[1] = -1;
} else {
priv->stats.numqry_phystatusHT++;
for (i = RF90_PATH_A; i < priv->NumTotalRFPath; i++) {
if (priv->brfpath_rxenable[i])
rf_rx_num++;
else
continue;
if (!rtl8192_phy_CheckIsLegalRFPath(
priv->ieee80211->dev, i))
continue;
rx_pwr[i] =
((pofdm_buf->trsw_gain_X[i] & 0x3F) * 2) - 106;
tmp_rxsnr = pofdm_buf->rxsnr_X[i];
rx_snrX = (s8)(tmp_rxsnr);
rx_snrX /= 2;
priv->stats.rxSNRdB[i] = (long)rx_snrX;
RSSI = rtl819x_query_rxpwrpercentage(rx_pwr[i]);
total_rssi += RSSI;
pstats->RxMIMOSignalStrength[i] = (u8)RSSI;
precord_stats->RxMIMOSignalStrength[i] = (u8)RSSI;
}
rx_pwr_all = (((pofdm_buf->pwdb_all) >> 1) & 0x7f) - 106;
pwdb_all = rtl819x_query_rxpwrpercentage(rx_pwr_all);
pstats->RxPWDBAll = precord_stats->RxPWDBAll = pwdb_all;
pstats->RxPower = precord_stats->RxPower = rx_pwr_all;
if (pdrvinfo->RxHT && pdrvinfo->RxRate >= DESC90_RATEMCS8 &&
pdrvinfo->RxRate <= DESC90_RATEMCS15)
max_spatial_stream = 2;
else
max_spatial_stream = 1;
for (i = 0; i < max_spatial_stream; i++) {
tmp_rxevm = pofdm_buf->rxevm_X[i];
rx_evmX = (s8)(tmp_rxevm);
rx_evmX /= 2;
evm = rtl819x_evm_dbtopercentage(rx_evmX);
if (i == 0)
pstats->SignalQuality =
precord_stats->SignalQuality =
evm & 0xff;
pstats->RxMIMOSignalQuality[i] =
precord_stats->RxMIMOSignalQuality[i] =
evm & 0xff;
}
rxsc_sgien_exflg = pofdm_buf->rxsc_sgien_exflg;
prxsc = (phy_ofdm_rx_status_rxsc_sgien_exintfflag *)
&rxsc_sgien_exflg;
if (pdrvinfo->BW)
priv->stats.received_bwtype[1 + prxsc->rxsc]++;
else
priv->stats.received_bwtype[0]++;
}
if (is_cck_rate) {
pstats->SignalStrength =
precord_stats->SignalStrength =
(u8)(rtl819x_signal_scale_mapping((long)pwdb_all));
} else {
if (rf_rx_num != 0) {
pstats->SignalStrength =
precord_stats->SignalStrength =
(u8)(rtl819x_signal_scale_mapping((long)(total_rssi /= rf_rx_num)));
}
}
}
static void rtl8192_record_rxdesc_forlateruse(
struct ieee80211_rx_stats *psrc_stats,
struct ieee80211_rx_stats *ptarget_stats)
{
ptarget_stats->bIsAMPDU = psrc_stats->bIsAMPDU;
ptarget_stats->bFirstMPDU = psrc_stats->bFirstMPDU;
ptarget_stats->Seq_Num = psrc_stats->Seq_Num;
}
static void TranslateRxSignalStuff819xUsb(struct sk_buff *skb,
struct ieee80211_rx_stats *pstats,
rx_drvinfo_819x_usb *pdrvinfo)
{
struct rtl8192_rx_info *info = (struct rtl8192_rx_info *)skb->cb;
struct net_device *dev = info->dev;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
bool bpacket_match_bssid, bpacket_toself;
bool bPacketBeacon = false, bToSelfBA = false;
static struct ieee80211_rx_stats previous_stats;
struct rtl_80211_hdr_3addr *hdr;
u16 fc, type;
u8 *tmp_buf;
u8 *praddr;
tmp_buf = (u8 *)skb->data;
hdr = (struct rtl_80211_hdr_3addr *)tmp_buf;
fc = le16_to_cpu(hdr->frame_ctl);
type = WLAN_FC_GET_TYPE(fc);
praddr = hdr->addr1;
bpacket_match_bssid = (IEEE80211_FTYPE_CTL != type) &&
(eqMacAddr(priv->ieee80211->current_network.bssid, (fc & IEEE80211_FCTL_TODS) ? hdr->addr1 : (fc & IEEE80211_FCTL_FROMDS) ? hdr->addr2 : hdr->addr3))
&& (!pstats->bHwError) && (!pstats->bCRC) && (!pstats->bICV);
bpacket_toself = bpacket_match_bssid &
(eqMacAddr(praddr, priv->ieee80211->dev->dev_addr));
if (WLAN_FC_GET_FRAMETYPE(fc) == IEEE80211_STYPE_BEACON)
bPacketBeacon = true;
if (WLAN_FC_GET_FRAMETYPE(fc) == IEEE80211_STYPE_BLOCKACK) {
if ((eqMacAddr(praddr, dev->dev_addr)))
bToSelfBA = true;
}
if (bpacket_match_bssid)
priv->stats.numpacket_matchbssid++;
if (bpacket_toself)
priv->stats.numpacket_toself++;
rtl8192_process_phyinfo(priv, tmp_buf, &previous_stats, pstats);
rtl8192_query_rxphystatus(priv, pstats, pdrvinfo, &previous_stats,
bpacket_match_bssid, bpacket_toself,
bPacketBeacon, bToSelfBA);
rtl8192_record_rxdesc_forlateruse(pstats, &previous_stats);
}
static void
UpdateReceivedRateHistogramStatistics8190(struct net_device *dev,
struct ieee80211_rx_stats *stats)
{
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
u32 rcvType = 1;
u32 rateIndex;
u32 preamble_guardinterval;
if (stats->bCRC)
rcvType = 2;
else if (stats->bICV)
rcvType = 3;
if (stats->bShortPreamble)
preamble_guardinterval = 1;
else
preamble_guardinterval = 0;
switch (stats->rate) {
case MGN_1M:
rateIndex = 0;
break;
case MGN_2M:
rateIndex = 1;
break;
case MGN_5_5M:
rateIndex = 2;
break;
case MGN_11M:
rateIndex = 3;
break;
case MGN_6M:
rateIndex = 4;
break;
case MGN_9M:
rateIndex = 5;
break;
case MGN_12M:
rateIndex = 6;
break;
case MGN_18M:
rateIndex = 7;
break;
case MGN_24M:
rateIndex = 8;
break;
case MGN_36M:
rateIndex = 9;
break;
case MGN_48M:
rateIndex = 10;
break;
case MGN_54M:
rateIndex = 11;
break;
case MGN_MCS0:
rateIndex = 12;
break;
case MGN_MCS1:
rateIndex = 13;
break;
case MGN_MCS2:
rateIndex = 14;
break;
case MGN_MCS3:
rateIndex = 15;
break;
case MGN_MCS4:
rateIndex = 16;
break;
case MGN_MCS5:
rateIndex = 17;
break;
case MGN_MCS6:
rateIndex = 18;
break;
case MGN_MCS7:
rateIndex = 19;
break;
case MGN_MCS8:
rateIndex = 20;
break;
case MGN_MCS9:
rateIndex = 21;
break;
case MGN_MCS10:
rateIndex = 22;
break;
case MGN_MCS11:
rateIndex = 23;
break;
case MGN_MCS12:
rateIndex = 24;
break;
case MGN_MCS13:
rateIndex = 25;
break;
case MGN_MCS14:
rateIndex = 26;
break;
case MGN_MCS15:
rateIndex = 27;
break;
default:
rateIndex = 28;
break;
}
priv->stats.received_preamble_GI[preamble_guardinterval][rateIndex]++;
priv->stats.received_rate_histogram[0][rateIndex]++;
priv->stats.received_rate_histogram[rcvType][rateIndex]++;
}
static void query_rxdesc_status(struct sk_buff *skb,
struct ieee80211_rx_stats *stats,
bool bIsRxAggrSubframe)
{
struct rtl8192_rx_info *info = (struct rtl8192_rx_info *)skb->cb;
struct net_device *dev = info->dev;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
rx_drvinfo_819x_usb *driver_info = NULL;
rx_desc_819x_usb *desc = (rx_desc_819x_usb *)skb->data;
stats->Length = desc->Length;
stats->RxDrvInfoSize = desc->RxDrvInfoSize;
stats->RxBufShift = 0;
stats->bICV = desc->ICV;
stats->bCRC = desc->CRC32;
stats->bHwError = stats->bCRC | stats->bICV;
stats->Decrypted = !desc->SWDec;
if ((priv->ieee80211->pHTInfo->bCurrentHTSupport) &&
(priv->ieee80211->pairwise_key_type == KEY_TYPE_CCMP))
stats->bHwError = false;
else
stats->bHwError = stats->bCRC | stats->bICV;
if (stats->Length < 24 || stats->Length > MAX_8192U_RX_SIZE)
stats->bHwError |= 1;
if (stats->RxDrvInfoSize != 0) {
driver_info = (rx_drvinfo_819x_usb *)(
skb->data
+ sizeof(rx_desc_819x_usb)
+ stats->RxBufShift
);
if (!stats->bHwError) {
u8 ret_rate;
ret_rate = HwRateToMRate90(driver_info->RxHT,
driver_info->RxRate);
if (ret_rate == 0xff) {
stats->bHwError = 1;
stats->rate = MGN_1M;
} else {
stats->rate = ret_rate;
}
} else {
stats->rate = 0x02;
}
stats->bShortPreamble = driver_info->SPLCP;
UpdateReceivedRateHistogramStatistics8190(dev, stats);
stats->bIsAMPDU = (driver_info->PartAggr == 1);
stats->bFirstMPDU = (driver_info->PartAggr == 1) &&
(driver_info->FirstAGGR == 1);
stats->TimeStampLow = driver_info->TSFL;
UpdateRxPktTimeStamp8190(dev, stats);
if (driver_info->FirstAGGR == 1 || driver_info->PartAggr == 1)
RT_TRACE(COMP_RXDESC,
"driver_info->FirstAGGR = %d, driver_info->PartAggr = %d\n",
driver_info->FirstAGGR, driver_info->PartAggr);
}
skb_pull(skb, sizeof(rx_desc_819x_usb));
if ((stats->RxBufShift + stats->RxDrvInfoSize) > 0) {
stats->bShift = 1;
skb_pull(skb, stats->RxBufShift + stats->RxDrvInfoSize);
}
if (driver_info) {
stats->RxIs40MHzPacket = driver_info->BW;
TranslateRxSignalStuff819xUsb(skb, stats, driver_info);
}
}
static void rtl8192_rx_nomal(struct sk_buff *skb)
{
struct rtl8192_rx_info *info = (struct rtl8192_rx_info *)skb->cb;
struct net_device *dev = info->dev;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct ieee80211_rx_stats stats = {
.signal = 0,
.noise = 0x100 - 98,
.rate = 0,
.freq = IEEE80211_24GHZ_BAND,
};
u32 rx_pkt_len = 0;
struct rtl_80211_hdr_1addr *ieee80211_hdr = NULL;
bool unicast_packet = false;
if ((skb->len >= (20 + sizeof(rx_desc_819x_usb))) && (skb->len < RX_URB_SIZE)) {
query_rxdesc_status(skb, &stats, false);
skb_trim(skb, skb->len - 4);
rx_pkt_len = skb->len;
ieee80211_hdr = (struct rtl_80211_hdr_1addr *)skb->data;
unicast_packet = false;
if (is_broadcast_ether_addr(ieee80211_hdr->addr1)) {
} else if (is_multicast_ether_addr(ieee80211_hdr->addr1)) {
} else {
unicast_packet = true;
}
if (!ieee80211_rx(priv->ieee80211, skb, &stats)) {
dev_kfree_skb_any(skb);
} else {
priv->stats.rxoktotal++;
if (unicast_packet)
priv->stats.rxbytesunicast += rx_pkt_len;
}
} else {
priv->stats.rxurberr++;
netdev_dbg(dev, "actual_length: %d\n", skb->len);
dev_kfree_skb_any(skb);
}
}
static void rtl819xusb_process_received_packet(
struct net_device *dev,
struct ieee80211_rx_stats *pstats)
{
u8 *frame;
u16 frame_len = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
pstats->virtual_address += get_rxpacket_shiftbytes_819xusb(pstats);
frame = pstats->virtual_address;
frame_len = pstats->packetlength;
#ifdef TODO
if (!Adapter->bInHctTest)
CountRxErrStatistics(Adapter, pRfd);
#endif
#ifdef ENABLE_PS
RT_RF_POWER_STATE rtState;
Adapter->HalFunc.GetHwRegHandler(Adapter, HW_VAR_RF_STATE,
(u8 *)(&rtState));
if (rtState == eRfOff)
return;
#endif
priv->stats.rxframgment++;
#ifdef TODO
RmMonitorSignalStrength(Adapter, pRfd);
#endif
if (rtl819xusb_rx_command_packet(dev, pstats))
return;
#ifdef SW_CRC_CHECK
SwCrcCheck();
#endif
}
static void query_rx_cmdpkt_desc_status(struct sk_buff *skb,
struct ieee80211_rx_stats *stats)
{
rx_desc_819x_usb *desc = (rx_desc_819x_usb *)skb->data;
stats->virtual_address = (u8 *)skb->data;
stats->Length = desc->Length;
stats->RxDrvInfoSize = 0;
stats->RxBufShift = 0;
stats->packetlength = stats->Length - scrclng;
stats->fraglength = stats->packetlength;
stats->fragoffset = 0;
stats->ntotalfrag = 1;
}
static void rtl8192_rx_cmd(struct sk_buff *skb)
{
struct rtl8192_rx_info *info = (struct rtl8192_rx_info *)skb->cb;
struct net_device *dev = info->dev;
struct ieee80211_rx_stats stats = {
.signal = 0,
.noise = 0x100 - 98,
.rate = 0,
.freq = IEEE80211_24GHZ_BAND,
};
if ((skb->len >= (20 + sizeof(rx_desc_819x_usb))) && (skb->len < RX_URB_SIZE)) {
query_rx_cmdpkt_desc_status(skb, &stats);
rtl819xusb_process_received_packet(dev, &stats);
dev_kfree_skb_any(skb);
}
}
static void rtl8192_irq_rx_tasklet(struct r8192_priv *priv)
{
struct sk_buff *skb;
struct rtl8192_rx_info *info;
while (NULL != (skb = skb_dequeue(&priv->skb_queue))) {
info = (struct rtl8192_rx_info *)skb->cb;
switch (info->out_pipe) {
case 3:
priv->IrpPendingCount--;
rtl8192_rx_nomal(skb);
break;
case 9:
RT_TRACE(COMP_RECV, "command in-pipe index(%d)\n",
info->out_pipe);
rtl8192_rx_cmd(skb);
break;
default:
RT_TRACE(COMP_ERR, "Unknown in-pipe index(%d)\n",
info->out_pipe);
dev_kfree_skb(skb);
break;
}
}
}
static int rtl8192_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct net_device *dev = NULL;
struct r8192_priv *priv = NULL;
struct usb_device *udev = interface_to_usbdev(intf);
int ret;
RT_TRACE(COMP_INIT, "Oops: i'm coming\n");
dev = alloc_ieee80211(sizeof(struct r8192_priv));
if (!dev)
return -ENOMEM;
usb_set_intfdata(intf, dev);
SET_NETDEV_DEV(dev, &intf->dev);
priv = ieee80211_priv(dev);
priv->ieee80211 = netdev_priv(dev);
priv->udev = udev;
dev->netdev_ops = &rtl8192_netdev_ops;
dev->wireless_handlers = &r8192_wx_handlers_def;
dev->type = ARPHRD_ETHER;
dev->watchdog_timeo = HZ * 3;
if (dev_alloc_name(dev, ifname) < 0) {
RT_TRACE(COMP_INIT,
"Oops: devname already taken! Trying wlan%%d...\n");
ifname = "wlan%d";
dev_alloc_name(dev, ifname);
}
RT_TRACE(COMP_INIT, "Driver probe completed1\n");
if (rtl8192_init(dev) != 0) {
RT_TRACE(COMP_ERR, "Initialization failed");
ret = -ENODEV;
goto fail;
}
netif_carrier_off(dev);
netif_stop_queue(dev);
ret = register_netdev(dev);
if (ret)
goto fail2;
RT_TRACE(COMP_INIT, "dev name=======> %s\n", dev->name);
rtl8192_proc_init_one(dev);
RT_TRACE(COMP_INIT, "Driver probe completed\n");
return 0;
fail2:
rtl8192_down(dev);
kfree(priv->pFirmware);
priv->pFirmware = NULL;
rtl8192_usb_deleteendpoints(dev);
mdelay(10);
fail:
free_ieee80211(dev);
RT_TRACE(COMP_ERR, "wlan driver load failed\n");
return ret;
}
static void rtl8192_cancel_deferred_work(struct r8192_priv *priv)
{
cancel_work_sync(&priv->reset_wq);
cancel_delayed_work(&priv->watch_dog_wq);
cancel_delayed_work(&priv->update_beacon_wq);
cancel_work_sync(&priv->qos_activate);
}
static void rtl8192_usb_disconnect(struct usb_interface *intf)
{
struct net_device *dev = usb_get_intfdata(intf);
struct r8192_priv *priv = ieee80211_priv(dev);
if (dev) {
unregister_netdev(dev);
RT_TRACE(COMP_DOWN,
"=============>wlan driver to be removed\n");
rtl8192_proc_remove_one(dev);
rtl8192_down(dev);
kfree(priv->pFirmware);
priv->pFirmware = NULL;
rtl8192_usb_deleteendpoints(dev);
mdelay(10);
}
free_ieee80211(dev);
RT_TRACE(COMP_DOWN, "wlan driver removed\n");
}
static int __init rtl8192_usb_module_init(void)
{
int ret;
#ifdef CONFIG_IEEE80211_DEBUG
ret = ieee80211_debug_init();
if (ret) {
pr_err("ieee80211_debug_init() failed %d\n", ret);
return ret;
}
#endif
ret = ieee80211_crypto_init();
if (ret) {
pr_err("ieee80211_crypto_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_tkip_init();
if (ret) {
pr_err("ieee80211_crypto_tkip_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_ccmp_init();
if (ret) {
pr_err("ieee80211_crypto_ccmp_init() failed %d\n", ret);
return ret;
}
ret = ieee80211_crypto_wep_init();
if (ret) {
pr_err("ieee80211_crypto_wep_init() failed %d\n", ret);
return ret;
}
pr_info("\nLinux kernel driver for RTL8192 based WLAN cards\n");
pr_info("Copyright (c) 2007-2008, Realsil Wlan\n");
RT_TRACE(COMP_INIT, "Initializing module");
RT_TRACE(COMP_INIT, "Wireless extensions version %d", WIRELESS_EXT);
rtl8192_proc_module_init();
return usb_register(&rtl8192_usb_driver);
}
static void __exit rtl8192_usb_module_exit(void)
{
usb_deregister(&rtl8192_usb_driver);
RT_TRACE(COMP_DOWN, "Exiting");
}
void EnableHWSecurityConfig8192(struct net_device *dev)
{
u8 SECR_value = 0x0;
struct r8192_priv *priv = (struct r8192_priv *)ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
SECR_value = SCR_TxEncEnable | SCR_RxDecEnable;
if (((KEY_TYPE_WEP40 == ieee->pairwise_key_type) || (KEY_TYPE_WEP104 == ieee->pairwise_key_type)) && (priv->ieee80211->auth_mode != 2)) {
SECR_value |= SCR_RxUseDK;
SECR_value |= SCR_TxUseDK;
} else if ((ieee->iw_mode == IW_MODE_ADHOC) && (ieee->pairwise_key_type & (KEY_TYPE_CCMP | KEY_TYPE_TKIP))) {
SECR_value |= SCR_RxUseDK;
SECR_value |= SCR_TxUseDK;
}
ieee->hwsec_active = 1;
if ((ieee->pHTInfo->IOTAction & HT_IOT_ACT_PURE_N_MODE) || !hwwep) {
ieee->hwsec_active = 0;
SECR_value &= ~SCR_RxDecEnable;
}
RT_TRACE(COMP_SEC, "%s:, hwsec:%d, pairwise_key:%d, SECR_value:%x\n",
__func__, ieee->hwsec_active, ieee->pairwise_key_type,
SECR_value);
write_nic_byte(dev, SECR, SECR_value);
}
void setKey(struct net_device *dev, u8 EntryNo, u8 KeyIndex, u16 KeyType,
u8 *MacAddr, u8 DefaultKey, u32 *KeyContent)
{
u32 TargetCommand = 0;
u32 TargetContent = 0;
u16 usConfig = 0;
u8 i;
if (EntryNo >= TOTAL_CAM_ENTRY)
RT_TRACE(COMP_ERR, "cam entry exceeds in setKey()\n");
RT_TRACE(COMP_SEC,
"====>to setKey(), dev:%p, EntryNo:%d, KeyIndex:%d, KeyType:%d, MacAddr%pM\n",
dev, EntryNo, KeyIndex, KeyType, MacAddr);
if (DefaultKey)
usConfig |= BIT(15) | (KeyType << 2);
else
usConfig |= BIT(15) | (KeyType << 2) | KeyIndex;
for (i = 0; i < CAM_CONTENT_COUNT; i++) {
TargetCommand = i + CAM_CONTENT_COUNT * EntryNo;
TargetCommand |= BIT(31) | BIT(16);
if (i == 0) {
TargetContent = (u32)(*(MacAddr + 0)) << 16 |
(u32)(*(MacAddr + 1)) << 24 |
(u32)usConfig;
write_nic_dword(dev, WCAMI, TargetContent);
write_nic_dword(dev, RWCAM, TargetCommand);
} else if (i == 1) {
TargetContent = (u32)(*(MacAddr + 2)) |
(u32)(*(MacAddr + 3)) << 8 |
(u32)(*(MacAddr + 4)) << 16 |
(u32)(*(MacAddr + 5)) << 24;
write_nic_dword(dev, WCAMI, TargetContent);
write_nic_dword(dev, RWCAM, TargetCommand);
} else {
if (KeyContent) {
write_nic_dword(dev, WCAMI,
*(KeyContent + i - 2));
write_nic_dword(dev, RWCAM, TargetCommand);
}
}
}
}
