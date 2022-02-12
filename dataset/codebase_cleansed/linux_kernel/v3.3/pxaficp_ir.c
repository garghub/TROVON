static inline void pxa_irda_disable_clk(struct pxa_irda *si)
{
if (si->cur_clk)
clk_disable(si->cur_clk);
si->cur_clk = NULL;
}
static inline void pxa_irda_enable_firclk(struct pxa_irda *si)
{
si->cur_clk = si->fir_clk;
clk_enable(si->fir_clk);
}
static inline void pxa_irda_enable_sirclk(struct pxa_irda *si)
{
si->cur_clk = si->sir_clk;
clk_enable(si->sir_clk);
}
inline static void pxa_irda_fir_dma_rx_start(struct pxa_irda *si)
{
DCSR(si->rxdma) = DCSR_NODESC;
DSADR(si->rxdma) = __PREG(ICDR);
DTADR(si->rxdma) = si->dma_rx_buff_phy;
DCMD(si->rxdma) = DCMD_INCTRGADDR | DCMD_FLOWSRC | DCMD_WIDTH1 | DCMD_BURST32 | IRDA_FRAME_SIZE_LIMIT;
DCSR(si->rxdma) |= DCSR_RUN;
}
inline static void pxa_irda_fir_dma_tx_start(struct pxa_irda *si)
{
DCSR(si->txdma) = DCSR_NODESC;
DSADR(si->txdma) = si->dma_tx_buff_phy;
DTADR(si->txdma) = __PREG(ICDR);
DCMD(si->txdma) = DCMD_INCSRCADDR | DCMD_FLOWTRG | DCMD_ENDIRQEN | DCMD_WIDTH1 | DCMD_BURST32 | si->dma_tx_buff_len;
DCSR(si->txdma) |= DCSR_RUN;
}
static void pxa_irda_set_mode(struct pxa_irda *si, int mode)
{
if (si->pdata->transceiver_mode)
si->pdata->transceiver_mode(si->dev, mode);
else {
if (gpio_is_valid(si->pdata->gpio_pwdown))
gpio_set_value(si->pdata->gpio_pwdown,
!(mode & IR_OFF) ^
!si->pdata->gpio_pwdown_inverted);
pxa2xx_transceiver_mode(si->dev, mode);
}
}
static int pxa_irda_set_speed(struct pxa_irda *si, int speed)
{
unsigned long flags;
unsigned int divisor;
switch (speed) {
case 9600: case 19200: case 38400:
case 57600: case 115200:
divisor = 14745600 / (16 * speed);
local_irq_save(flags);
if (IS_FIR(si)) {
DCSR(si->rxdma) &= ~DCSR_RUN;
ICCR0 = 0;
pxa_irda_disable_clk(si);
pxa_irda_set_mode(si, IR_SIRMODE);
pxa_irda_enable_sirclk(si);
}
STIER = 0;
STLCR |= LCR_DLAB;
STDLL = divisor & 0xff;
STDLH = divisor >> 8;
STLCR &= ~LCR_DLAB;
si->speed = speed;
STISR = IrSR_IR_RECEIVE_ON | IrSR_XMODE_PULSE_1_6;
STIER = IER_UUE | IER_RLSE | IER_RAVIE | IER_RTIOE;
local_irq_restore(flags);
break;
case 4000000:
local_irq_save(flags);
STIER = 0;
STISR = 0;
pxa_irda_disable_clk(si);
ICCR0 = 0;
pxa_irda_set_mode(si, IR_FIRMODE);
pxa_irda_enable_firclk(si);
si->speed = speed;
pxa_irda_fir_dma_rx_start(si);
ICCR0 = ICCR0_ITR | ICCR0_RXE;
local_irq_restore(flags);
break;
default:
return -EINVAL;
}
return 0;
}
static irqreturn_t pxa_irda_sir_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct pxa_irda *si = netdev_priv(dev);
int iir, lsr, data;
iir = STIIR;
switch (iir & 0x0F) {
case 0x06:
lsr = STLSR;
while (lsr & LSR_FIFOE) {
data = STRBR;
if (lsr & (LSR_OE | LSR_PE | LSR_FE | LSR_BI)) {
printk(KERN_DEBUG "pxa_ir: sir receiving error\n");
dev->stats.rx_errors++;
if (lsr & LSR_FE)
dev->stats.rx_frame_errors++;
if (lsr & LSR_OE)
dev->stats.rx_fifo_errors++;
} else {
dev->stats.rx_bytes++;
async_unwrap_char(dev, &dev->stats,
&si->rx_buff, data);
}
lsr = STLSR;
}
si->last_oscr = OSCR;
break;
case 0x04:
case 0x0C:
do {
dev->stats.rx_bytes++;
async_unwrap_char(dev, &dev->stats, &si->rx_buff, STRBR);
} while (STLSR & LSR_DR);
si->last_oscr = OSCR;
break;
case 0x02:
while ((si->tx_buff.len) && (STLSR & LSR_TDRQ)) {
STTHR = *si->tx_buff.data++;
si->tx_buff.len -= 1;
}
if (si->tx_buff.len == 0) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += si->tx_buff.data - si->tx_buff.head;
while ((STLSR & LSR_TEMT) == 0)
cpu_relax();
si->last_oscr = OSCR;
if (si->newspeed) {
pxa_irda_set_speed(si, si->newspeed);
si->newspeed = 0;
} else {
STISR = IrSR_IR_RECEIVE_ON | IrSR_XMODE_PULSE_1_6;
STIER = IER_UUE | IER_RLSE | IER_RAVIE | IER_RTIOE;
}
netif_wake_queue(dev);
}
break;
}
return IRQ_HANDLED;
}
static void pxa_irda_fir_dma_rx_irq(int channel, void *data)
{
int dcsr = DCSR(channel);
DCSR(channel) = dcsr & ~DCSR_RUN;
printk(KERN_DEBUG "pxa_ir: fir rx dma bus error %#x\n", dcsr);
}
static void pxa_irda_fir_dma_tx_irq(int channel, void *data)
{
struct net_device *dev = data;
struct pxa_irda *si = netdev_priv(dev);
int dcsr;
dcsr = DCSR(channel);
DCSR(channel) = dcsr & ~DCSR_RUN;
if (dcsr & DCSR_ENDINTR) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += si->dma_tx_buff_len;
} else {
dev->stats.tx_errors++;
}
while (ICSR1 & ICSR1_TBY)
cpu_relax();
si->last_oscr = OSCR;
udelay(120);
if (si->newspeed) {
pxa_irda_set_speed(si, si->newspeed);
si->newspeed = 0;
} else {
int i = 64;
ICCR0 = 0;
pxa_irda_fir_dma_rx_start(si);
while ((ICSR1 & ICSR1_RNE) && i--)
(void)ICDR;
ICCR0 = ICCR0_ITR | ICCR0_RXE;
if (i < 0)
printk(KERN_ERR "pxa_ir: cannot clear Rx FIFO!\n");
}
netif_wake_queue(dev);
}
static void pxa_irda_fir_irq_eif(struct pxa_irda *si, struct net_device *dev, int icsr0)
{
unsigned int len, stat, data;
len = DTADR(si->rxdma) - si->dma_rx_buff_phy;
do {
stat = ICSR1;
rmb();
data = ICDR;
if (stat & (ICSR1_CRE | ICSR1_ROR)) {
dev->stats.rx_errors++;
if (stat & ICSR1_CRE) {
printk(KERN_DEBUG "pxa_ir: fir receive CRC error\n");
dev->stats.rx_crc_errors++;
}
if (stat & ICSR1_ROR) {
printk(KERN_DEBUG "pxa_ir: fir receive overrun\n");
dev->stats.rx_over_errors++;
}
} else {
si->dma_rx_buff[len++] = data;
}
if (stat & ICSR1_EOF)
break;
} while (ICSR0 & ICSR0_EIF);
if (stat & ICSR1_EOF) {
struct sk_buff *skb;
if (icsr0 & ICSR0_FRE) {
printk(KERN_ERR "pxa_ir: dropping erroneous frame\n");
dev->stats.rx_dropped++;
return;
}
skb = alloc_skb(len+1,GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "pxa_ir: fir out of memory for receive skb\n");
dev->stats.rx_dropped++;
return;
}
skb_reserve(skb, 1);
skb_copy_to_linear_data(skb, si->dma_rx_buff, len);
skb_put(skb, len);
skb->dev = dev;
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
}
}
static irqreturn_t pxa_irda_fir_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct pxa_irda *si = netdev_priv(dev);
int icsr0, i = 64;
DCSR(si->rxdma) &= ~DCSR_RUN;
si->last_oscr = OSCR;
icsr0 = ICSR0;
if (icsr0 & (ICSR0_FRE | ICSR0_RAB)) {
if (icsr0 & ICSR0_FRE) {
printk(KERN_DEBUG "pxa_ir: fir receive frame error\n");
dev->stats.rx_frame_errors++;
} else {
printk(KERN_DEBUG "pxa_ir: fir receive abort\n");
dev->stats.rx_errors++;
}
ICSR0 = icsr0 & (ICSR0_FRE | ICSR0_RAB);
}
if (icsr0 & ICSR0_EIF) {
pxa_irda_fir_irq_eif(si, dev, icsr0);
}
ICCR0 = 0;
pxa_irda_fir_dma_rx_start(si);
while ((ICSR1 & ICSR1_RNE) && i--)
(void)ICDR;
ICCR0 = ICCR0_ITR | ICCR0_RXE;
if (i < 0)
printk(KERN_ERR "pxa_ir: cannot clear Rx FIFO!\n");
return IRQ_HANDLED;
}
static int pxa_irda_hard_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct pxa_irda *si = netdev_priv(dev);
int speed = irda_get_next_speed(skb);
if (speed != si->speed && speed != -1)
si->newspeed = speed;
if (skb->len == 0) {
if (si->newspeed) {
si->newspeed = 0;
pxa_irda_set_speed(si, speed);
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
if (!IS_FIR(si)) {
si->tx_buff.data = si->tx_buff.head;
si->tx_buff.len = async_wrap_skb(skb, si->tx_buff.data, si->tx_buff.truesize);
STIER = 0;
STISR = IrSR_IR_TRANSMIT_ON | IrSR_XMODE_PULSE_1_6;
STIER = IER_UUE | IER_TIE;
} else {
unsigned long mtt = irda_get_mtt(skb);
si->dma_tx_buff_len = skb->len;
skb_copy_from_linear_data(skb, si->dma_tx_buff, skb->len);
if (mtt)
while ((unsigned)(OSCR - si->last_oscr)/4 < mtt)
cpu_relax();
DCSR(si->rxdma) &= ~DCSR_RUN;
ICCR0 = 0;
pxa_irda_fir_dma_tx_start(si);
ICCR0 = ICCR0_ITR | ICCR0_TXE;
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int pxa_irda_ioctl(struct net_device *dev, struct ifreq *ifreq, int cmd)
{
struct if_irda_req *rq = (struct if_irda_req *)ifreq;
struct pxa_irda *si = netdev_priv(dev);
int ret;
switch (cmd) {
case SIOCSBANDWIDTH:
ret = -EPERM;
if (capable(CAP_NET_ADMIN)) {
if (netif_running(dev)) {
ret = pxa_irda_set_speed(si,
rq->ifr_baudrate);
} else {
printk(KERN_INFO "pxa_ir: SIOCSBANDWIDTH: !netif_running\n");
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
ret = 0;
rq->ifr_receiving = IS_FIR(si) ? 0
: si->rx_buff.state != OUTSIDE_FRAME;
break;
default:
ret = -EOPNOTSUPP;
break;
}
return ret;
}
static void pxa_irda_startup(struct pxa_irda *si)
{
STIER = 0;
STMCR = MCR_OUT2;
STLCR = LCR_WLS0 | LCR_WLS1;
STFCR = FCR_TRFIFOE | FCR_ITL_32;
ICCR0 = 0;
ICCR2 = ICCR2_TXP | ICCR2_TRIG_32;
DRCMR(17) = si->rxdma | DRCMR_MAPVLD;
DRCMR(18) = si->txdma | DRCMR_MAPVLD;
si->speed = 4000000;
pxa_irda_set_speed(si, 9600);
printk(KERN_DEBUG "pxa_ir: irda startup\n");
}
static void pxa_irda_shutdown(struct pxa_irda *si)
{
unsigned long flags;
local_irq_save(flags);
STIER = 0;
STISR = 0;
DCSR(si->txdma) &= ~DCSR_RUN;
DCSR(si->rxdma) &= ~DCSR_RUN;
ICCR0 = 0;
pxa_irda_disable_clk(si);
DRCMR(17) = 0;
DRCMR(18) = 0;
local_irq_restore(flags);
pxa_irda_set_mode(si, IR_OFF);
printk(KERN_DEBUG "pxa_ir: irda shutdown\n");
}
static int pxa_irda_start(struct net_device *dev)
{
struct pxa_irda *si = netdev_priv(dev);
int err;
si->speed = 9600;
err = request_irq(IRQ_STUART, pxa_irda_sir_irq, 0, dev->name, dev);
if (err)
goto err_irq1;
err = request_irq(IRQ_ICP, pxa_irda_fir_irq, 0, dev->name, dev);
if (err)
goto err_irq2;
disable_irq(IRQ_STUART);
disable_irq(IRQ_ICP);
err = -EBUSY;
si->rxdma = pxa_request_dma("FICP_RX",DMA_PRIO_LOW, pxa_irda_fir_dma_rx_irq, dev);
if (si->rxdma < 0)
goto err_rx_dma;
si->txdma = pxa_request_dma("FICP_TX",DMA_PRIO_LOW, pxa_irda_fir_dma_tx_irq, dev);
if (si->txdma < 0)
goto err_tx_dma;
err = -ENOMEM;
si->dma_rx_buff = dma_alloc_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT,
&si->dma_rx_buff_phy, GFP_KERNEL );
if (!si->dma_rx_buff)
goto err_dma_rx_buff;
si->dma_tx_buff = dma_alloc_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT,
&si->dma_tx_buff_phy, GFP_KERNEL );
if (!si->dma_tx_buff)
goto err_dma_tx_buff;
pxa_irda_startup(si);
si->irlap = irlap_open(dev, &si->qos, "pxa");
err = -ENOMEM;
if (!si->irlap)
goto err_irlap;
enable_irq(IRQ_STUART);
enable_irq(IRQ_ICP);
netif_start_queue(dev);
printk(KERN_DEBUG "pxa_ir: irda driver opened\n");
return 0;
err_irlap:
pxa_irda_shutdown(si);
dma_free_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT, si->dma_tx_buff, si->dma_tx_buff_phy);
err_dma_tx_buff:
dma_free_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT, si->dma_rx_buff, si->dma_rx_buff_phy);
err_dma_rx_buff:
pxa_free_dma(si->txdma);
err_tx_dma:
pxa_free_dma(si->rxdma);
err_rx_dma:
free_irq(IRQ_ICP, dev);
err_irq2:
free_irq(IRQ_STUART, dev);
err_irq1:
return err;
}
static int pxa_irda_stop(struct net_device *dev)
{
struct pxa_irda *si = netdev_priv(dev);
netif_stop_queue(dev);
pxa_irda_shutdown(si);
if (si->irlap) {
irlap_close(si->irlap);
si->irlap = NULL;
}
free_irq(IRQ_STUART, dev);
free_irq(IRQ_ICP, dev);
pxa_free_dma(si->rxdma);
pxa_free_dma(si->txdma);
if (si->dma_rx_buff)
dma_free_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT, si->dma_tx_buff, si->dma_tx_buff_phy);
if (si->dma_tx_buff)
dma_free_coherent(si->dev, IRDA_FRAME_SIZE_LIMIT, si->dma_rx_buff, si->dma_rx_buff_phy);
printk(KERN_DEBUG "pxa_ir: irda driver closed\n");
return 0;
}
static int pxa_irda_suspend(struct platform_device *_dev, pm_message_t state)
{
struct net_device *dev = platform_get_drvdata(_dev);
struct pxa_irda *si;
if (dev && netif_running(dev)) {
si = netdev_priv(dev);
netif_device_detach(dev);
pxa_irda_shutdown(si);
}
return 0;
}
static int pxa_irda_resume(struct platform_device *_dev)
{
struct net_device *dev = platform_get_drvdata(_dev);
struct pxa_irda *si;
if (dev && netif_running(dev)) {
si = netdev_priv(dev);
pxa_irda_startup(si);
netif_device_attach(dev);
netif_wake_queue(dev);
}
return 0;
}
static int pxa_irda_init_iobuf(iobuff_t *io, int size)
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
static int pxa_irda_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct pxa_irda *si;
unsigned int baudrate_mask;
int err;
if (!pdev->dev.platform_data)
return -ENODEV;
err = request_mem_region(__PREG(STUART), 0x24, "IrDA") ? 0 : -EBUSY;
if (err)
goto err_mem_1;
err = request_mem_region(__PREG(FICP), 0x1c, "IrDA") ? 0 : -EBUSY;
if (err)
goto err_mem_2;
dev = alloc_irdadev(sizeof(struct pxa_irda));
if (!dev)
goto err_mem_3;
SET_NETDEV_DEV(dev, &pdev->dev);
si = netdev_priv(dev);
si->dev = &pdev->dev;
si->pdata = pdev->dev.platform_data;
si->sir_clk = clk_get(&pdev->dev, "UARTCLK");
si->fir_clk = clk_get(&pdev->dev, "FICPCLK");
if (IS_ERR(si->sir_clk) || IS_ERR(si->fir_clk)) {
err = PTR_ERR(IS_ERR(si->sir_clk) ? si->sir_clk : si->fir_clk);
goto err_mem_4;
}
err = pxa_irda_init_iobuf(&si->rx_buff, 14384);
if (err)
goto err_mem_4;
err = pxa_irda_init_iobuf(&si->tx_buff, 4000);
if (err)
goto err_mem_5;
if (gpio_is_valid(si->pdata->gpio_pwdown)) {
err = gpio_request(si->pdata->gpio_pwdown, "IrDA switch");
if (err)
goto err_startup;
err = gpio_direction_output(si->pdata->gpio_pwdown,
!si->pdata->gpio_pwdown_inverted);
if (err) {
gpio_free(si->pdata->gpio_pwdown);
goto err_startup;
}
}
if (si->pdata->startup) {
err = si->pdata->startup(si->dev);
if (err)
goto err_startup;
}
if (gpio_is_valid(si->pdata->gpio_pwdown) && si->pdata->startup)
dev_warn(si->dev, "gpio_pwdown and startup() both defined!\n");
dev->netdev_ops = &pxa_irda_netdev_ops;
irda_init_max_qos_capabilies(&si->qos);
baudrate_mask = 0;
if (si->pdata->transceiver_cap & IR_SIRMODE)
baudrate_mask |= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
if (si->pdata->transceiver_cap & IR_FIRMODE)
baudrate_mask |= IR_4000000 << 8;
si->qos.baud_rate.bits &= baudrate_mask;
si->qos.min_turn_time.bits = 7;
irda_qos_bits_to_value(&si->qos);
err = register_netdev(dev);
if (err == 0)
dev_set_drvdata(&pdev->dev, dev);
if (err) {
if (si->pdata->shutdown)
si->pdata->shutdown(si->dev);
err_startup:
kfree(si->tx_buff.head);
err_mem_5:
kfree(si->rx_buff.head);
err_mem_4:
if (si->sir_clk && !IS_ERR(si->sir_clk))
clk_put(si->sir_clk);
if (si->fir_clk && !IS_ERR(si->fir_clk))
clk_put(si->fir_clk);
free_netdev(dev);
err_mem_3:
release_mem_region(__PREG(FICP), 0x1c);
err_mem_2:
release_mem_region(__PREG(STUART), 0x24);
}
err_mem_1:
return err;
}
static int pxa_irda_remove(struct platform_device *_dev)
{
struct net_device *dev = platform_get_drvdata(_dev);
if (dev) {
struct pxa_irda *si = netdev_priv(dev);
unregister_netdev(dev);
if (gpio_is_valid(si->pdata->gpio_pwdown))
gpio_free(si->pdata->gpio_pwdown);
if (si->pdata->shutdown)
si->pdata->shutdown(si->dev);
kfree(si->tx_buff.head);
kfree(si->rx_buff.head);
clk_put(si->fir_clk);
clk_put(si->sir_clk);
free_netdev(dev);
}
release_mem_region(__PREG(STUART), 0x24);
release_mem_region(__PREG(FICP), 0x1c);
return 0;
}
