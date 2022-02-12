static void delay(int ms)
{
unsigned long timeout = jiffies + ((ms * HZ) / 1000);
while (time_before(jiffies, timeout))
cpu_relax();
}
static void fpga_reset(int iobase)
{
outb(0, IER(iobase));
outb(LCR_DLAB | LCR_BIT5, LCR(iobase));
outb(1, DLL(iobase));
outb(0, DLM(iobase));
outb(LCR_BIT5, LCR(iobase));
inb(LSR(iobase));
inb(MSR(iobase));
outb(MCR_OUT1 | MCR_OUT2, MCR(iobase));
delay(100);
outb(MCR_DTR | MCR_RTS | MCR_OUT1 | MCR_OUT2, MCR(iobase));
delay(100);
}
static int fpga_write(int iobase, unsigned char wrd)
{
unsigned char bit;
int k;
unsigned long timeout = jiffies + HZ / 10;
for (k = 0; k < 8; k++) {
bit = (wrd & 0x80) ? (MCR_RTS | MCR_DTR) : MCR_DTR;
outb(bit | MCR_OUT1 | MCR_OUT2, MCR(iobase));
wrd <<= 1;
outb(0xfc, THR(iobase));
while ((inb(LSR(iobase)) & LSR_TSRE) == 0)
if (time_after(jiffies, timeout))
return -1;
}
return 0;
}
static unsigned char *add_mcs(unsigned char *bits, int bitrate,
unsigned int predef)
{
const char *fw_name[2] = {FIRMWARE_9600, FIRMWARE_1200};
const struct firmware *fw;
struct platform_device *pdev;
struct yam_mcs *p;
int err;
switch (predef) {
case 0:
fw = NULL;
break;
case YAM_1200:
case YAM_9600:
predef--;
pdev = platform_device_register_simple("yam", 0, NULL, 0);
if (IS_ERR(pdev)) {
printk(KERN_ERR "yam: Failed to register firmware\n");
return NULL;
}
err = request_firmware(&fw, fw_name[predef], &pdev->dev);
platform_device_unregister(pdev);
if (err) {
printk(KERN_ERR "Failed to load firmware \"%s\"\n",
fw_name[predef]);
return NULL;
}
if (fw->size != YAM_FPGA_SIZE) {
printk(KERN_ERR "Bogus length %zu in firmware \"%s\"\n",
fw->size, fw_name[predef]);
release_firmware(fw);
return NULL;
}
bits = (unsigned char *)fw->data;
break;
default:
printk(KERN_ERR "yam: Invalid predef number %u\n", predef);
return NULL;
}
p = yam_data;
while (p) {
if (p->bitrate == bitrate) {
memcpy(p->bits, bits, YAM_FPGA_SIZE);
goto out;
}
p = p->next;
}
if ((p = kmalloc(sizeof(struct yam_mcs), GFP_KERNEL)) == NULL) {
release_firmware(fw);
return NULL;
}
memcpy(p->bits, bits, YAM_FPGA_SIZE);
p->bitrate = bitrate;
p->next = yam_data;
yam_data = p;
out:
release_firmware(fw);
return p->bits;
}
static unsigned char *get_mcs(int bitrate)
{
struct yam_mcs *p;
p = yam_data;
while (p) {
if (p->bitrate == bitrate)
return p->bits;
p = p->next;
}
switch (bitrate) {
case 1200:
return add_mcs(NULL, bitrate, YAM_1200);
default:
return add_mcs(NULL, bitrate, YAM_9600);
}
}
static int fpga_download(int iobase, int bitrate)
{
int i, rc;
unsigned char *pbits;
pbits = get_mcs(bitrate);
if (pbits == NULL)
return -1;
fpga_reset(iobase);
for (i = 0; i < YAM_FPGA_SIZE; i++) {
if (fpga_write(iobase, pbits[i])) {
printk(KERN_ERR "yam: error in write cycle\n");
return -1;
}
}
fpga_write(iobase, 0xFF);
rc = inb(MSR(iobase));
delay(50);
return (rc & MSR_DSR) ? 0 : -1;
}
static void yam_set_uart(struct net_device *dev)
{
struct yam_port *yp = netdev_priv(dev);
int divisor = 115200 / yp->baudrate;
outb(0, IER(dev->base_addr));
outb(LCR_DLAB | LCR_BIT8, LCR(dev->base_addr));
outb(divisor, DLL(dev->base_addr));
outb(0, DLM(dev->base_addr));
outb(LCR_BIT8, LCR(dev->base_addr));
outb(PTT_OFF, MCR(dev->base_addr));
outb(0x00, FCR(dev->base_addr));
inb(RBR(dev->base_addr));
inb(MSR(dev->base_addr));
outb(ENABLE_RTXINT, IER(dev->base_addr));
}
static enum uart yam_check_uart(unsigned int iobase)
{
unsigned char b1, b2, b3;
enum uart u;
enum uart uart_tab[] =
{c_uart_16450, c_uart_unknown, c_uart_16550, c_uart_16550A};
b1 = inb(MCR(iobase));
outb(b1 | 0x10, MCR(iobase));
b2 = inb(MSR(iobase));
outb(0x1a, MCR(iobase));
b3 = inb(MSR(iobase)) & 0xf0;
outb(b1, MCR(iobase));
outb(b2, MSR(iobase));
if (b3 != 0x90)
return c_uart_unknown;
inb(RBR(iobase));
inb(RBR(iobase));
outb(0x01, FCR(iobase));
u = uart_tab[(inb(IIR(iobase)) >> 6) & 3];
if (u == c_uart_16450) {
outb(0x5a, SCR(iobase));
b1 = inb(SCR(iobase));
outb(0xa5, SCR(iobase));
b2 = inb(SCR(iobase));
if ((b1 != 0x5a) || (b2 != 0xa5))
u = c_uart_8250;
}
return u;
}
static inline void yam_rx_flag(struct net_device *dev, struct yam_port *yp)
{
if (yp->dcd && yp->rx_len >= 3 && yp->rx_len < YAM_MAX_FRAME) {
int pkt_len = yp->rx_len - 2 + 1;
struct sk_buff *skb;
if ((yp->rx_crch & yp->rx_crcl) != 0xFF) {
} else {
if (!(skb = dev_alloc_skb(pkt_len))) {
printk(KERN_WARNING "%s: memory squeeze, dropping packet\n", dev->name);
++dev->stats.rx_dropped;
} else {
unsigned char *cp;
cp = skb_put(skb, pkt_len);
*cp++ = 0;
memcpy(cp, yp->rx_buf, pkt_len - 1);
skb->protocol = ax25_type_trans(skb, dev);
netif_rx(skb);
++dev->stats.rx_packets;
}
}
}
yp->rx_len = 0;
yp->rx_crcl = 0x21;
yp->rx_crch = 0xf3;
}
static inline void yam_rx_byte(struct net_device *dev, struct yam_port *yp, unsigned char rxb)
{
if (yp->rx_len < YAM_MAX_FRAME) {
unsigned char c = yp->rx_crcl;
yp->rx_crcl = (chktabl[c] ^ yp->rx_crch);
yp->rx_crch = (chktabh[c] ^ rxb);
yp->rx_buf[yp->rx_len++] = rxb;
}
}
static void ptt_on(struct net_device *dev)
{
outb(PTT_ON, MCR(dev->base_addr));
}
static void ptt_off(struct net_device *dev)
{
outb(PTT_OFF, MCR(dev->base_addr));
}
static netdev_tx_t yam_send_packet(struct sk_buff *skb,
struct net_device *dev)
{
struct yam_port *yp = netdev_priv(dev);
if (skb->protocol == htons(ETH_P_IP))
return ax25_ip_xmit(skb);
skb_queue_tail(&yp->send_queue, skb);
netif_trans_update(dev);
return NETDEV_TX_OK;
}
static void yam_start_tx(struct net_device *dev, struct yam_port *yp)
{
if ((yp->tx_state == TX_TAIL) || (yp->txd == 0))
yp->tx_count = 1;
else
yp->tx_count = (yp->bitrate * yp->txd) / 8000;
yp->tx_state = TX_HEAD;
ptt_on(dev);
}
static void yam_arbitrate(struct net_device *dev)
{
struct yam_port *yp = netdev_priv(dev);
if (yp->magic != YAM_MAGIC || yp->tx_state != TX_OFF ||
skb_queue_empty(&yp->send_queue))
return;
if (yp->dupmode) {
yam_start_tx(dev, yp);
return;
}
if (yp->dcd) {
yp->slotcnt = yp->slot / 10;
return;
}
if ((--yp->slotcnt) > 0)
return;
yp->slotcnt = yp->slot / 10;
if ((prandom_u32() % 256) > yp->pers)
return;
yam_start_tx(dev, yp);
}
static void yam_dotimer(unsigned long dummy)
{
int i;
for (i = 0; i < NR_PORTS; i++) {
struct net_device *dev = yam_devs[i];
if (dev && netif_running(dev))
yam_arbitrate(dev);
}
yam_timer.expires = jiffies + HZ / 100;
add_timer(&yam_timer);
}
static void yam_tx_byte(struct net_device *dev, struct yam_port *yp)
{
struct sk_buff *skb;
unsigned char b, temp;
switch (yp->tx_state) {
case TX_OFF:
break;
case TX_HEAD:
if (--yp->tx_count <= 0) {
if (!(skb = skb_dequeue(&yp->send_queue))) {
ptt_off(dev);
yp->tx_state = TX_OFF;
break;
}
yp->tx_state = TX_DATA;
if (skb->data[0] != 0) {
dev_kfree_skb_any(skb);
break;
}
yp->tx_len = skb->len - 1;
if (yp->tx_len >= YAM_MAX_FRAME || yp->tx_len < 2) {
dev_kfree_skb_any(skb);
break;
}
skb_copy_from_linear_data_offset(skb, 1,
yp->tx_buf,
yp->tx_len);
dev_kfree_skb_any(skb);
yp->tx_count = 0;
yp->tx_crcl = 0x21;
yp->tx_crch = 0xf3;
yp->tx_state = TX_DATA;
}
break;
case TX_DATA:
b = yp->tx_buf[yp->tx_count++];
outb(b, THR(dev->base_addr));
temp = yp->tx_crcl;
yp->tx_crcl = chktabl[temp] ^ yp->tx_crch;
yp->tx_crch = chktabh[temp] ^ b;
if (yp->tx_count >= yp->tx_len) {
yp->tx_state = TX_CRC1;
}
break;
case TX_CRC1:
yp->tx_crch = chktabl[yp->tx_crcl] ^ yp->tx_crch;
yp->tx_crcl = chktabh[yp->tx_crcl] ^ chktabl[yp->tx_crch] ^ 0xff;
outb(yp->tx_crcl, THR(dev->base_addr));
yp->tx_state = TX_CRC2;
break;
case TX_CRC2:
outb(chktabh[yp->tx_crch] ^ 0xFF, THR(dev->base_addr));
if (skb_queue_empty(&yp->send_queue)) {
yp->tx_count = (yp->bitrate * yp->txtail) / 8000;
if (yp->dupmode == 2)
yp->tx_count += (yp->bitrate * yp->holdd) / 8;
if (yp->tx_count == 0)
yp->tx_count = 1;
yp->tx_state = TX_TAIL;
} else {
yp->tx_count = 1;
yp->tx_state = TX_HEAD;
}
++dev->stats.tx_packets;
break;
case TX_TAIL:
if (--yp->tx_count <= 0) {
yp->tx_state = TX_OFF;
ptt_off(dev);
}
break;
}
}
static irqreturn_t yam_interrupt(int irq, void *dev_id)
{
struct net_device *dev;
struct yam_port *yp;
unsigned char iir;
int counter = 100;
int i;
int handled = 0;
for (i = 0; i < NR_PORTS; i++) {
dev = yam_devs[i];
yp = netdev_priv(dev);
if (!netif_running(dev))
continue;
while ((iir = IIR_MASK & inb(IIR(dev->base_addr))) != IIR_NOPEND) {
unsigned char msr = inb(MSR(dev->base_addr));
unsigned char lsr = inb(LSR(dev->base_addr));
unsigned char rxb;
handled = 1;
if (lsr & LSR_OE)
++dev->stats.rx_fifo_errors;
yp->dcd = (msr & RX_DCD) ? 1 : 0;
if (--counter <= 0) {
printk(KERN_ERR "%s: too many irq iir=%d\n",
dev->name, iir);
goto out;
}
if (msr & TX_RDY) {
++yp->nb_mdint;
yam_tx_byte(dev, yp);
}
if (lsr & LSR_RXC) {
++yp->nb_rxint;
rxb = inb(RBR(dev->base_addr));
if (msr & RX_FLAG)
yam_rx_flag(dev, yp);
else
yam_rx_byte(dev, yp, rxb);
}
}
}
out:
return IRQ_RETVAL(handled);
}
static void *yam_seq_start(struct seq_file *seq, loff_t *pos)
{
return (*pos < NR_PORTS) ? yam_devs[*pos] : NULL;
}
static void *yam_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return (*pos < NR_PORTS) ? yam_devs[*pos] : NULL;
}
static void yam_seq_stop(struct seq_file *seq, void *v)
{
}
static int yam_seq_show(struct seq_file *seq, void *v)
{
struct net_device *dev = v;
const struct yam_port *yp = netdev_priv(dev);
seq_printf(seq, "Device %s\n", dev->name);
seq_printf(seq, " Up %d\n", netif_running(dev));
seq_printf(seq, " Speed %u\n", yp->bitrate);
seq_printf(seq, " IoBase 0x%x\n", yp->iobase);
seq_printf(seq, " BaudRate %u\n", yp->baudrate);
seq_printf(seq, " IRQ %u\n", yp->irq);
seq_printf(seq, " TxState %u\n", yp->tx_state);
seq_printf(seq, " Duplex %u\n", yp->dupmode);
seq_printf(seq, " HoldDly %u\n", yp->holdd);
seq_printf(seq, " TxDelay %u\n", yp->txd);
seq_printf(seq, " TxTail %u\n", yp->txtail);
seq_printf(seq, " SlotTime %u\n", yp->slot);
seq_printf(seq, " Persist %u\n", yp->pers);
seq_printf(seq, " TxFrames %lu\n", dev->stats.tx_packets);
seq_printf(seq, " RxFrames %lu\n", dev->stats.rx_packets);
seq_printf(seq, " TxInt %u\n", yp->nb_mdint);
seq_printf(seq, " RxInt %u\n", yp->nb_rxint);
seq_printf(seq, " RxOver %lu\n", dev->stats.rx_fifo_errors);
seq_printf(seq, "\n");
return 0;
}
static int yam_info_open(struct inode *inode, struct file *file)
{
return seq_open(file, &yam_seqops);
}
static int yam_open(struct net_device *dev)
{
struct yam_port *yp = netdev_priv(dev);
enum uart u;
int i;
int ret=0;
printk(KERN_INFO "Trying %s at iobase 0x%lx irq %u\n", dev->name, dev->base_addr, dev->irq);
if (!yp->bitrate)
return -ENXIO;
if (!dev->base_addr || dev->base_addr > 0x1000 - YAM_EXTENT ||
dev->irq < 2 || dev->irq > 15) {
return -ENXIO;
}
if (!request_region(dev->base_addr, YAM_EXTENT, dev->name))
{
printk(KERN_ERR "%s: cannot 0x%lx busy\n", dev->name, dev->base_addr);
return -EACCES;
}
if ((u = yam_check_uart(dev->base_addr)) == c_uart_unknown) {
printk(KERN_ERR "%s: cannot find uart type\n", dev->name);
ret = -EIO;
goto out_release_base;
}
if (fpga_download(dev->base_addr, yp->bitrate)) {
printk(KERN_ERR "%s: cannot init FPGA\n", dev->name);
ret = -EIO;
goto out_release_base;
}
outb(0, IER(dev->base_addr));
if (request_irq(dev->irq, yam_interrupt, IRQF_SHARED, dev->name, dev)) {
printk(KERN_ERR "%s: irq %d busy\n", dev->name, dev->irq);
ret = -EBUSY;
goto out_release_base;
}
yam_set_uart(dev);
netif_start_queue(dev);
yp->slotcnt = yp->slot / 10;
for (i = 0; i < NR_PORTS; i++) {
struct net_device *yam_dev = yam_devs[i];
inb(LSR(yam_dev->base_addr));
yam_dev->stats.rx_fifo_errors = 0;
}
printk(KERN_INFO "%s at iobase 0x%lx irq %u uart %s\n", dev->name, dev->base_addr, dev->irq,
uart_str[u]);
return 0;
out_release_base:
release_region(dev->base_addr, YAM_EXTENT);
return ret;
}
static int yam_close(struct net_device *dev)
{
struct sk_buff *skb;
struct yam_port *yp = netdev_priv(dev);
if (!dev)
return -EINVAL;
outb(0, IER(dev->base_addr));
outb(1, MCR(dev->base_addr));
free_irq(dev->irq,dev);
release_region(dev->base_addr, YAM_EXTENT);
netif_stop_queue(dev);
while ((skb = skb_dequeue(&yp->send_queue)))
dev_kfree_skb(skb);
printk(KERN_INFO "%s: close yam at iobase 0x%lx irq %u\n",
yam_drvname, dev->base_addr, dev->irq);
return 0;
}
static int yam_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct yam_port *yp = netdev_priv(dev);
struct yamdrv_ioctl_cfg yi;
struct yamdrv_ioctl_mcs *ym;
int ioctl_cmd;
if (copy_from_user(&ioctl_cmd, ifr->ifr_data, sizeof(int)))
return -EFAULT;
if (yp->magic != YAM_MAGIC)
return -EINVAL;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (cmd != SIOCDEVPRIVATE)
return -EINVAL;
switch (ioctl_cmd) {
case SIOCYAMRESERVED:
return -EINVAL;
case SIOCYAMSMCS:
if (netif_running(dev))
return -EINVAL;
ym = memdup_user(ifr->ifr_data,
sizeof(struct yamdrv_ioctl_mcs));
if (IS_ERR(ym))
return PTR_ERR(ym);
if (ym->bitrate > YAM_MAXBITRATE) {
kfree(ym);
return -EINVAL;
}
add_mcs(ym->bits, ym->bitrate, 0);
kfree(ym);
break;
case SIOCYAMSCFG:
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (copy_from_user(&yi, ifr->ifr_data, sizeof(struct yamdrv_ioctl_cfg)))
return -EFAULT;
if ((yi.cfg.mask & YAM_IOBASE) && netif_running(dev))
return -EINVAL;
if ((yi.cfg.mask & YAM_IRQ) && netif_running(dev))
return -EINVAL;
if ((yi.cfg.mask & YAM_BITRATE) && netif_running(dev))
return -EINVAL;
if ((yi.cfg.mask & YAM_BAUDRATE) && netif_running(dev))
return -EINVAL;
if (yi.cfg.mask & YAM_IOBASE) {
yp->iobase = yi.cfg.iobase;
dev->base_addr = yi.cfg.iobase;
}
if (yi.cfg.mask & YAM_IRQ) {
if (yi.cfg.irq > 15)
return -EINVAL;
yp->irq = yi.cfg.irq;
dev->irq = yi.cfg.irq;
}
if (yi.cfg.mask & YAM_BITRATE) {
if (yi.cfg.bitrate > YAM_MAXBITRATE)
return -EINVAL;
yp->bitrate = yi.cfg.bitrate;
}
if (yi.cfg.mask & YAM_BAUDRATE) {
if (yi.cfg.baudrate > YAM_MAXBAUDRATE)
return -EINVAL;
yp->baudrate = yi.cfg.baudrate;
}
if (yi.cfg.mask & YAM_MODE) {
if (yi.cfg.mode > YAM_MAXMODE)
return -EINVAL;
yp->dupmode = yi.cfg.mode;
}
if (yi.cfg.mask & YAM_HOLDDLY) {
if (yi.cfg.holddly > YAM_MAXHOLDDLY)
return -EINVAL;
yp->holdd = yi.cfg.holddly;
}
if (yi.cfg.mask & YAM_TXDELAY) {
if (yi.cfg.txdelay > YAM_MAXTXDELAY)
return -EINVAL;
yp->txd = yi.cfg.txdelay;
}
if (yi.cfg.mask & YAM_TXTAIL) {
if (yi.cfg.txtail > YAM_MAXTXTAIL)
return -EINVAL;
yp->txtail = yi.cfg.txtail;
}
if (yi.cfg.mask & YAM_PERSIST) {
if (yi.cfg.persist > YAM_MAXPERSIST)
return -EINVAL;
yp->pers = yi.cfg.persist;
}
if (yi.cfg.mask & YAM_SLOTTIME) {
if (yi.cfg.slottime > YAM_MAXSLOTTIME)
return -EINVAL;
yp->slot = yi.cfg.slottime;
yp->slotcnt = yp->slot / 10;
}
break;
case SIOCYAMGCFG:
memset(&yi, 0, sizeof(yi));
yi.cfg.mask = 0xffffffff;
yi.cfg.iobase = yp->iobase;
yi.cfg.irq = yp->irq;
yi.cfg.bitrate = yp->bitrate;
yi.cfg.baudrate = yp->baudrate;
yi.cfg.mode = yp->dupmode;
yi.cfg.txdelay = yp->txd;
yi.cfg.holddly = yp->holdd;
yi.cfg.txtail = yp->txtail;
yi.cfg.persist = yp->pers;
yi.cfg.slottime = yp->slot;
if (copy_to_user(ifr->ifr_data, &yi, sizeof(struct yamdrv_ioctl_cfg)))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
static int yam_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = (struct sockaddr *) addr;
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static void yam_setup(struct net_device *dev)
{
struct yam_port *yp = netdev_priv(dev);
yp->magic = YAM_MAGIC;
yp->bitrate = DEFAULT_BITRATE;
yp->baudrate = DEFAULT_BITRATE * 2;
yp->iobase = 0;
yp->irq = 0;
yp->dupmode = 0;
yp->holdd = DEFAULT_HOLDD;
yp->txd = DEFAULT_TXD;
yp->txtail = DEFAULT_TXTAIL;
yp->slot = DEFAULT_SLOT;
yp->pers = DEFAULT_PERS;
yp->dev = dev;
dev->base_addr = yp->iobase;
dev->irq = yp->irq;
skb_queue_head_init(&yp->send_queue);
dev->netdev_ops = &yam_netdev_ops;
dev->header_ops = &ax25_header_ops;
dev->type = ARPHRD_AX25;
dev->hard_header_len = AX25_MAX_HEADER_LEN;
dev->mtu = AX25_MTU;
dev->addr_len = AX25_ADDR_LEN;
memcpy(dev->broadcast, &ax25_bcast, AX25_ADDR_LEN);
memcpy(dev->dev_addr, &ax25_defaddr, AX25_ADDR_LEN);
}
static int __init yam_init_driver(void)
{
struct net_device *dev;
int i, err;
char name[IFNAMSIZ];
printk(yam_drvinfo);
for (i = 0; i < NR_PORTS; i++) {
sprintf(name, "yam%d", i);
dev = alloc_netdev(sizeof(struct yam_port), name,
NET_NAME_UNKNOWN, yam_setup);
if (!dev) {
pr_err("yam: cannot allocate net device\n");
err = -ENOMEM;
goto error;
}
err = register_netdev(dev);
if (err) {
printk(KERN_WARNING "yam: cannot register net device %s\n", dev->name);
goto error;
}
yam_devs[i] = dev;
}
yam_timer.function = yam_dotimer;
yam_timer.expires = jiffies + HZ / 100;
add_timer(&yam_timer);
proc_create("yam", S_IRUGO, init_net.proc_net, &yam_info_fops);
return 0;
error:
while (--i >= 0) {
unregister_netdev(yam_devs[i]);
free_netdev(yam_devs[i]);
}
return err;
}
static void __exit yam_cleanup_driver(void)
{
struct yam_mcs *p;
int i;
del_timer_sync(&yam_timer);
for (i = 0; i < NR_PORTS; i++) {
struct net_device *dev = yam_devs[i];
if (dev) {
unregister_netdev(dev);
free_netdev(dev);
}
}
while (yam_data) {
p = yam_data;
yam_data = yam_data->next;
kfree(p);
}
remove_proc_entry("yam", init_net.proc_net);
}
