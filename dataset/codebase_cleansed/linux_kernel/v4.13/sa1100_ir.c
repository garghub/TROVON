static unsigned sa1100_irda_dma_xferred(struct sa1100_buf *buf)
{
struct dma_chan *chan = buf->chan;
struct dma_tx_state state;
enum dma_status status;
status = chan->device->device_tx_status(chan, buf->cookie, &state);
if (status != DMA_PAUSED)
return 0;
return sg_dma_len(&buf->sg) - state.residue;
}
static int sa1100_irda_dma_request(struct device *dev, struct sa1100_buf *buf,
const char *name, struct dma_slave_config *cfg)
{
dma_cap_mask_t m;
int ret;
dma_cap_zero(m);
dma_cap_set(DMA_SLAVE, m);
buf->chan = dma_request_channel(m, sa11x0_dma_filter_fn, (void *)name);
if (!buf->chan) {
dev_err(dev, "unable to request DMA channel for %s\n",
name);
return -ENOENT;
}
ret = dmaengine_slave_config(buf->chan, cfg);
if (ret)
dev_warn(dev, "DMA slave_config for %s returned %d\n",
name, ret);
buf->dev = buf->chan->device->dev;
return 0;
}
static void sa1100_irda_dma_start(struct sa1100_buf *buf,
enum dma_transfer_direction dir, dma_async_tx_callback cb, void *cb_p)
{
struct dma_async_tx_descriptor *desc;
struct dma_chan *chan = buf->chan;
desc = dmaengine_prep_slave_sg(chan, &buf->sg, 1, dir,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (desc) {
desc->callback = cb;
desc->callback_param = cb_p;
buf->cookie = dmaengine_submit(desc);
dma_async_issue_pending(chan);
}
}
static int sa1100_irda_rx_alloc(struct sa1100_irda *si)
{
if (si->dma_rx.skb)
return 0;
si->dma_rx.skb = alloc_skb(HPSIR_MAX_RXLEN + 1, GFP_ATOMIC);
if (!si->dma_rx.skb) {
printk(KERN_ERR "sa1100_ir: out of memory for RX SKB\n");
return -ENOMEM;
}
skb_reserve(si->dma_rx.skb, 1);
sg_set_buf(&si->dma_rx.sg, si->dma_rx.skb->data, HPSIR_MAX_RXLEN);
if (dma_map_sg(si->dma_rx.dev, &si->dma_rx.sg, 1, DMA_FROM_DEVICE) == 0) {
dev_kfree_skb_any(si->dma_rx.skb);
return -ENOMEM;
}
return 0;
}
static void sa1100_irda_rx_dma_start(struct sa1100_irda *si)
{
if (!si->dma_rx.skb) {
printk(KERN_ERR "sa1100_ir: rx buffer went missing\n");
return;
}
Ser2HSCR0 = HSCR0_HSSP;
dmaengine_terminate_all(si->dma_rx.chan);
sa1100_irda_dma_start(&si->dma_rx, DMA_DEV_TO_MEM, NULL, NULL);
Ser2HSCR0 = HSCR0_HSSP | HSCR0_RXE;
}
static void sa1100_irda_check_speed(struct sa1100_irda *si)
{
if (si->newspeed) {
sa1100_irda_set_speed(si, si->newspeed);
si->newspeed = 0;
}
}
static void sa1100_irda_sirtxdma_irq(void *id)
{
struct net_device *dev = id;
struct sa1100_irda *si = netdev_priv(dev);
dma_unmap_sg(si->dma_tx.dev, &si->dma_tx.sg, 1, DMA_TO_DEVICE);
dev_kfree_skb(si->dma_tx.skb);
si->dma_tx.skb = NULL;
dev->stats.tx_packets++;
dev->stats.tx_bytes += sg_dma_len(&si->dma_tx.sg);
do
rmb();
while (Ser2UTSR1 & UTSR1_TBY);
Ser2UTSR0 = UTSR0_REB | UTSR0_RBB | UTSR0_RID;
Ser2UTCR3 = UTCR3_RIE | UTCR3_RXE | UTCR3_TXE;
sa1100_irda_check_speed(si);
netif_wake_queue(dev);
}
static int sa1100_irda_sir_tx_start(struct sk_buff *skb, struct net_device *dev,
struct sa1100_irda *si)
{
si->tx_buff.data = si->tx_buff.head;
si->tx_buff.len = async_wrap_skb(skb, si->tx_buff.data,
si->tx_buff.truesize);
si->dma_tx.skb = skb;
sg_set_buf(&si->dma_tx.sg, si->tx_buff.data, si->tx_buff.len);
if (dma_map_sg(si->dma_tx.dev, &si->dma_tx.sg, 1, DMA_TO_DEVICE) == 0) {
si->dma_tx.skb = NULL;
netif_wake_queue(dev);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
sa1100_irda_dma_start(&si->dma_tx, DMA_MEM_TO_DEV, sa1100_irda_sirtxdma_irq, dev);
Ser2UTCR3 = UTCR3_TXE;
return NETDEV_TX_OK;
}
static irqreturn_t sa1100_irda_sir_irq(struct net_device *dev, struct sa1100_irda *si)
{
int status;
status = Ser2UTSR0;
while (status & UTSR0_EIF) {
int stat, data;
stat = Ser2UTSR1;
data = Ser2UTDR;
if (stat & (UTSR1_FRE | UTSR1_ROR)) {
dev->stats.rx_errors++;
if (stat & UTSR1_FRE)
dev->stats.rx_frame_errors++;
if (stat & UTSR1_ROR)
dev->stats.rx_fifo_errors++;
} else
async_unwrap_char(dev, &dev->stats, &si->rx_buff, data);
status = Ser2UTSR0;
}
Ser2UTSR0 = status & (UTSR0_RID | UTSR0_RBB | UTSR0_REB);
if (status & UTSR0_RFS) {
async_unwrap_char(dev, &dev->stats, &si->rx_buff, Ser2UTDR);
async_unwrap_char(dev, &dev->stats, &si->rx_buff, Ser2UTDR);
async_unwrap_char(dev, &dev->stats, &si->rx_buff, Ser2UTDR);
}
if (status & (UTSR0_RFS | UTSR0_RID)) {
do {
async_unwrap_char(dev, &dev->stats, &si->rx_buff,
Ser2UTDR);
} while (Ser2UTSR1 & UTSR1_RNE);
}
return IRQ_HANDLED;
}
static void sa1100_irda_firtxdma_irq(void *id)
{
struct net_device *dev = id;
struct sa1100_irda *si = netdev_priv(dev);
struct sk_buff *skb;
do
rmb();
while (!(Ser2HSSR0 & HSSR0_TUR) || Ser2HSSR1 & HSSR1_TBY);
Ser2HSSR0 = HSSR0_TUR;
sa1100_irda_check_speed(si);
sa1100_irda_rx_dma_start(si);
skb = si->dma_tx.skb;
if (skb) {
dma_unmap_sg(si->dma_tx.dev, &si->dma_tx.sg, 1,
DMA_TO_DEVICE);
dev->stats.tx_packets ++;
dev->stats.tx_bytes += skb->len;
dev_kfree_skb_irq(skb);
si->dma_tx.skb = NULL;
}
netif_wake_queue(dev);
}
static int sa1100_irda_fir_tx_start(struct sk_buff *skb, struct net_device *dev,
struct sa1100_irda *si)
{
int mtt = irda_get_mtt(skb);
si->dma_tx.skb = skb;
sg_set_buf(&si->dma_tx.sg, skb->data, skb->len);
if (dma_map_sg(si->dma_tx.dev, &si->dma_tx.sg, 1, DMA_TO_DEVICE) == 0) {
si->dma_tx.skb = NULL;
netif_wake_queue(dev);
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
sa1100_irda_dma_start(&si->dma_tx, DMA_MEM_TO_DEV, sa1100_irda_firtxdma_irq, dev);
if (mtt)
udelay(mtt);
Ser2HSCR0 = HSCR0_HSSP | HSCR0_TXE;
return NETDEV_TX_OK;
}
static void sa1100_irda_fir_error(struct sa1100_irda *si, struct net_device *dev)
{
struct sk_buff *skb = si->dma_rx.skb;
unsigned int len, stat, data;
if (!skb) {
printk(KERN_ERR "sa1100_ir: SKB is NULL!\n");
return;
}
len = sa1100_irda_dma_xferred(&si->dma_rx);
if (len > HPSIR_MAX_RXLEN)
len = HPSIR_MAX_RXLEN;
dma_unmap_sg(si->dma_rx.dev, &si->dma_rx.sg, 1, DMA_FROM_DEVICE);
do {
stat = Ser2HSSR1;
rmb();
data = Ser2HSDR;
if (stat & (HSSR1_CRE | HSSR1_ROR)) {
dev->stats.rx_errors++;
if (stat & HSSR1_CRE)
dev->stats.rx_crc_errors++;
if (stat & HSSR1_ROR)
dev->stats.rx_frame_errors++;
} else
skb->data[len++] = data;
if (stat & HSSR1_EOF)
break;
} while (Ser2HSSR0 & HSSR0_EIF);
if (stat & HSSR1_EOF) {
si->dma_rx.skb = NULL;
skb_put(skb, len);
skb->dev = dev;
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
sa1100_irda_rx_alloc(si);
netif_rx(skb);
} else {
dma_map_sg(si->dma_rx.dev, &si->dma_rx.sg, 1, DMA_FROM_DEVICE);
}
}
static irqreturn_t sa1100_irda_fir_irq(struct net_device *dev, struct sa1100_irda *si)
{
dmaengine_pause(si->dma_rx.chan);
if (Ser2HSSR0 & (HSSR0_FRE | HSSR0_RAB)) {
dev->stats.rx_errors++;
if (Ser2HSSR0 & HSSR0_FRE)
dev->stats.rx_frame_errors++;
Ser2HSCR0 = HSCR0_HSSP;
Ser2HSSR0 = HSSR0_FRE | HSSR0_RAB;
}
if (Ser2HSSR0 & HSSR0_EIF)
sa1100_irda_fir_error(si, dev);
sa1100_irda_rx_dma_start(si);
return IRQ_HANDLED;
}
static int sa1100_irda_set_speed(struct sa1100_irda *si, int speed)
{
unsigned long flags;
int brd, ret = -EINVAL;
switch (speed) {
case 9600: case 19200: case 38400:
case 57600: case 115200:
brd = 3686400 / (16 * speed) - 1;
if (IS_FIR(si)) {
dmaengine_terminate_all(si->dma_rx.chan);
dmaengine_slave_config(si->dma_tx.chan,
&sa1100_irda_sir_tx);
}
local_irq_save(flags);
Ser2UTCR3 = 0;
Ser2HSCR0 = HSCR0_UART;
Ser2UTCR1 = brd >> 8;
Ser2UTCR2 = brd;
Ser2UTSR0 = UTSR0_REB | UTSR0_RBB | UTSR0_RID;
Ser2UTCR3 = UTCR3_RIE | UTCR3_RXE | UTCR3_TXE;
if (si->pdata->set_speed)
si->pdata->set_speed(si->dev, speed);
si->speed = speed;
si->tx_start = sa1100_irda_sir_tx_start;
si->irq = sa1100_irda_sir_irq;
local_irq_restore(flags);
ret = 0;
break;
case 4000000:
if (!IS_FIR(si))
dmaengine_slave_config(si->dma_tx.chan,
&sa1100_irda_fir_tx);
local_irq_save(flags);
Ser2HSSR0 = 0xff;
Ser2HSCR0 = HSCR0_HSSP;
Ser2UTCR3 = 0;
si->speed = speed;
si->tx_start = sa1100_irda_fir_tx_start;
si->irq = sa1100_irda_fir_irq;
if (si->pdata->set_speed)
si->pdata->set_speed(si->dev, speed);
sa1100_irda_rx_alloc(si);
sa1100_irda_rx_dma_start(si);
local_irq_restore(flags);
break;
default:
break;
}
return ret;
}
static int
__sa1100_irda_set_power(struct sa1100_irda *si, unsigned int state)
{
int ret = 0;
if (si->pdata->set_power)
ret = si->pdata->set_power(si->dev, state);
return ret;
}
static inline int
sa1100_set_power(struct sa1100_irda *si, unsigned int state)
{
int ret;
ret = __sa1100_irda_set_power(si, state);
if (ret == 0)
si->power = state;
return ret;
}
static irqreturn_t sa1100_irda_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct sa1100_irda *si = netdev_priv(dev);
return si->irq(dev, si);
}
static int sa1100_irda_hard_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct sa1100_irda *si = netdev_priv(dev);
int speed = irda_get_next_speed(skb);
if (speed != si->speed && speed != -1)
si->newspeed = speed;
if (skb->len == 0) {
sa1100_irda_check_speed(si);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
BUG_ON(si->dma_tx.skb);
return si->tx_start(skb, dev, si);
}
static int
sa1100_irda_ioctl(struct net_device *dev, struct ifreq *ifreq, int cmd)
{
struct if_irda_req *rq = (struct if_irda_req *)ifreq;
struct sa1100_irda *si = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd) {
case SIOCSBANDWIDTH:
if (capable(CAP_NET_ADMIN)) {
if (si->open) {
ret = sa1100_irda_set_speed(si,
rq->ifr_baudrate);
} else {
printk("sa1100_irda_ioctl: SIOCSBANDWIDTH: !netif_running\n");
ret = 0;
}
}
break;
case SIOCSMEDIABUSY:
ret = -EPERM;
if (capable(CAP_NET_ADMIN)) {
irda_device_set_media_busy(dev, TRUE);
ret = 0;
}
break;
case SIOCGRECEIVING:
rq->ifr_receiving = IS_FIR(si) ? 0
: si->rx_buff.state != OUTSIDE_FRAME;
break;
default:
break;
}
return ret;
}
static int sa1100_irda_startup(struct sa1100_irda *si)
{
int ret;
if (si->pdata->startup) {
ret = si->pdata->startup(si->dev);
if (ret)
return ret;
}
PPSR &= ~PPC_TXD2;
PSDR &= ~PPC_TXD2;
PPDR |= PPC_TXD2;
Ser2UTCR3 = 0;
Ser2HSCR0 = HSCR0_UART;
Ser2UTCR4 = si->utcr4;
Ser2UTCR0 = UTCR0_8BitData;
Ser2HSCR2 = HSCR2_TrDataH | HSCR2_RcDataL;
Ser2UTSR0 = UTSR0_REB | UTSR0_RBB | UTSR0_RID;
ret = sa1100_irda_set_speed(si, si->speed = 9600);
if (ret) {
Ser2UTCR3 = 0;
Ser2HSCR0 = 0;
if (si->pdata->shutdown)
si->pdata->shutdown(si->dev);
}
return ret;
}
static void sa1100_irda_shutdown(struct sa1100_irda *si)
{
dmaengine_terminate_all(si->dma_rx.chan);
dmaengine_terminate_all(si->dma_tx.chan);
Ser2UTCR3 = 0;
Ser2HSCR0 = 0;
if (si->pdata->shutdown)
si->pdata->shutdown(si->dev);
}
static int sa1100_irda_start(struct net_device *dev)
{
struct sa1100_irda *si = netdev_priv(dev);
int err;
si->speed = 9600;
err = sa1100_irda_dma_request(si->dev, &si->dma_rx, "Ser2ICPRc",
&sa1100_irda_fir_rx);
if (err)
goto err_rx_dma;
err = sa1100_irda_dma_request(si->dev, &si->dma_tx, "Ser2ICPTr",
&sa1100_irda_sir_tx);
if (err)
goto err_tx_dma;
err = sa1100_irda_startup(si);
if (err)
goto err_startup;
si->irlap = irlap_open(dev, &si->qos, "sa1100");
err = -ENOMEM;
if (!si->irlap)
goto err_irlap;
err = request_irq(dev->irq, sa1100_irda_irq, 0, dev->name, dev);
if (err)
goto err_irq;
si->open = 1;
sa1100_set_power(si, power_level);
netif_start_queue(dev);
return 0;
err_irq:
irlap_close(si->irlap);
err_irlap:
si->open = 0;
sa1100_irda_shutdown(si);
err_startup:
dma_release_channel(si->dma_tx.chan);
err_tx_dma:
dma_release_channel(si->dma_rx.chan);
err_rx_dma:
return err;
}
static int sa1100_irda_stop(struct net_device *dev)
{
struct sa1100_irda *si = netdev_priv(dev);
struct sk_buff *skb;
netif_stop_queue(dev);
si->open = 0;
sa1100_irda_shutdown(si);
skb = si->dma_rx.skb;
if (skb) {
dma_unmap_sg(si->dma_rx.dev, &si->dma_rx.sg, 1,
DMA_FROM_DEVICE);
dev_kfree_skb(skb);
si->dma_rx.skb = NULL;
}
skb = si->dma_tx.skb;
if (skb) {
dma_unmap_sg(si->dma_tx.dev, &si->dma_tx.sg, 1,
DMA_TO_DEVICE);
dev_kfree_skb(skb);
si->dma_tx.skb = NULL;
}
if (si->irlap) {
irlap_close(si->irlap);
si->irlap = NULL;
}
dma_release_channel(si->dma_tx.chan);
dma_release_channel(si->dma_rx.chan);
free_irq(dev->irq, dev);
sa1100_set_power(si, 0);
return 0;
}
static int sa1100_irda_init_iobuf(iobuff_t *io, int size)
{
io->head = kmalloc(size, GFP_KERNEL | GFP_DMA);
if (io->head != NULL) {
io->truesize = size;
io->in_frame = FALSE;
io->state = OUTSIDE_FRAME;
io->data = io->head;
}
return io->head ? 0 : -ENOMEM;
}
static int sa1100_irda_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct sa1100_irda *si;
unsigned int baudrate_mask;
int err, irq;
if (!pdev->dev.platform_data)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return irq < 0 ? irq : -ENXIO;
err = request_mem_region(__PREG(Ser2UTCR0), 0x24, "IrDA") ? 0 : -EBUSY;
if (err)
goto err_mem_1;
err = request_mem_region(__PREG(Ser2HSCR0), 0x1c, "IrDA") ? 0 : -EBUSY;
if (err)
goto err_mem_2;
err = request_mem_region(__PREG(Ser2HSCR2), 0x04, "IrDA") ? 0 : -EBUSY;
if (err)
goto err_mem_3;
dev = alloc_irdadev(sizeof(struct sa1100_irda));
if (!dev) {
err = -ENOMEM;
goto err_mem_4;
}
SET_NETDEV_DEV(dev, &pdev->dev);
si = netdev_priv(dev);
si->dev = &pdev->dev;
si->pdata = pdev->dev.platform_data;
sg_init_table(&si->dma_rx.sg, 1);
sg_init_table(&si->dma_tx.sg, 1);
err = sa1100_irda_init_iobuf(&si->rx_buff, 14384);
if (err)
goto err_mem_5;
err = sa1100_irda_init_iobuf(&si->tx_buff, IRDA_SIR_MAX_FRAME);
if (err)
goto err_mem_5;
dev->netdev_ops = &sa1100_irda_netdev_ops;
dev->irq = irq;
irda_init_max_qos_capabilies(&si->qos);
baudrate_mask = IR_9600;
switch (max_rate) {
case 4000000: baudrate_mask |= IR_4000000 << 8;
case 115200: baudrate_mask |= IR_115200;
case 57600: baudrate_mask |= IR_57600;
case 38400: baudrate_mask |= IR_38400;
case 19200: baudrate_mask |= IR_19200;
}
si->qos.baud_rate.bits &= baudrate_mask;
si->qos.min_turn_time.bits = 7;
irda_qos_bits_to_value(&si->qos);
si->utcr4 = UTCR4_HPSIR;
if (tx_lpm)
si->utcr4 |= UTCR4_Z1_6us;
Ser2UTCR3 = 0;
Ser2UTCR4 = si->utcr4;
Ser2HSCR0 = HSCR0_UART;
err = register_netdev(dev);
if (err == 0)
platform_set_drvdata(pdev, dev);
if (err) {
err_mem_5:
kfree(si->tx_buff.head);
kfree(si->rx_buff.head);
free_netdev(dev);
err_mem_4:
release_mem_region(__PREG(Ser2HSCR2), 0x04);
err_mem_3:
release_mem_region(__PREG(Ser2HSCR0), 0x1c);
err_mem_2:
release_mem_region(__PREG(Ser2UTCR0), 0x24);
}
err_mem_1:
return err;
}
static int sa1100_irda_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (dev) {
struct sa1100_irda *si = netdev_priv(dev);
unregister_netdev(dev);
kfree(si->tx_buff.head);
kfree(si->rx_buff.head);
free_netdev(dev);
}
release_mem_region(__PREG(Ser2HSCR2), 0x04);
release_mem_region(__PREG(Ser2HSCR0), 0x1c);
release_mem_region(__PREG(Ser2UTCR0), 0x24);
return 0;
}
static int sa1100_irda_suspend(struct platform_device *pdev, pm_message_t state)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct sa1100_irda *si;
if (!dev)
return 0;
si = netdev_priv(dev);
if (si->open) {
netif_device_detach(dev);
disable_irq(dev->irq);
sa1100_irda_shutdown(si);
__sa1100_irda_set_power(si, 0);
}
return 0;
}
static int sa1100_irda_resume(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct sa1100_irda *si;
if (!dev)
return 0;
si = netdev_priv(dev);
if (si->open) {
if (si->newspeed) {
si->speed = si->newspeed;
si->newspeed = 0;
}
sa1100_irda_startup(si);
__sa1100_irda_set_power(si, si->power);
enable_irq(dev->irq);
netif_device_attach(dev);
}
return 0;
}
static int __init sa1100_irda_init(void)
{
if (power_level < 1)
power_level = 1;
if (power_level > 3)
power_level = 3;
return platform_driver_register(&sa1100ir_driver);
}
static void __exit sa1100_irda_exit(void)
{
platform_driver_unregister(&sa1100ir_driver);
}
