static void sh_sir_write(struct sh_sir_self *self, u32 offset, u16 data)
{
iowrite16(data, self->membase + offset);
}
static u16 sh_sir_read(struct sh_sir_self *self, u32 offset)
{
return ioread16(self->membase + offset);
}
static void sh_sir_update_bits(struct sh_sir_self *self, u32 offset,
u16 mask, u16 data)
{
u16 old, new;
old = sh_sir_read(self, offset);
new = (old & ~mask) | data;
if (old != new)
sh_sir_write(self, offset, new);
}
static void sh_sir_crc_reset(struct sh_sir_self *self)
{
sh_sir_write(self, IRIF_CRC0, CRC_RST);
}
static void sh_sir_crc_add(struct sh_sir_self *self, u8 data)
{
sh_sir_write(self, IRIF_CRC1, (u16)data);
}
static u16 sh_sir_crc_cnt(struct sh_sir_self *self)
{
return CRC_CT_MASK & sh_sir_read(self, IRIF_CRC0);
}
static u16 sh_sir_crc_out(struct sh_sir_self *self)
{
return sh_sir_read(self, IRIF_CRC4);
}
static int sh_sir_crc_init(struct sh_sir_self *self)
{
struct device *dev = &self->ndev->dev;
int ret = -EIO;
u16 val;
sh_sir_crc_reset(self);
sh_sir_crc_add(self, 0xCC);
sh_sir_crc_add(self, 0xF5);
sh_sir_crc_add(self, 0xF1);
sh_sir_crc_add(self, 0xA7);
val = sh_sir_crc_cnt(self);
if (4 != val) {
dev_err(dev, "CRC count error %x\n", val);
goto crc_init_out;
}
val = sh_sir_crc_out(self);
if (0x51DF != val) {
dev_err(dev, "CRC result error%x\n", val);
goto crc_init_out;
}
ret = 0;
crc_init_out:
sh_sir_crc_reset(self);
return ret;
}
static u32 sh_sir_find_sclk(struct clk *irda_clk)
{
struct cpufreq_frequency_table *freq_table = irda_clk->freq_table;
struct clk *pclk = clk_get(NULL, "peripheral_clk");
u32 limit, min = 0xffffffff, tmp;
int i, index = 0;
limit = clk_get_rate(pclk);
clk_put(pclk);
for (i = 0;
freq_table[i].frequency != CPUFREQ_TABLE_END;
i++) {
u32 freq = freq_table[i].frequency;
if (freq == CPUFREQ_ENTRY_INVALID)
continue;
if (freq > limit)
continue;
tmp = freq % SCLK_BASE;
if (tmp < min) {
min = tmp;
index = i;
}
}
return freq_table[index].frequency;
}
static int sh_sir_set_baudrate(struct sh_sir_self *self, u32 baudrate)
{
struct clk *clk;
struct device *dev = &self->ndev->dev;
u32 rate;
u16 uabca, uabc;
u16 irbca, irbc;
u32 min, rerr, tmp;
int i;
u32 rate_err_array[] = {
0, 625, 1250, 1875,
2500, 3125, 3750, 4375,
5000, 5625, 6250, 6875,
7500, 8125, 8750, 9375,
};
switch (baudrate) {
case 9600:
break;
default:
dev_err(dev, "un-supported baudrate %d\n", baudrate);
return -EIO;
}
clk = clk_get(NULL, "irda_clk");
if (!clk) {
dev_err(dev, "can not get irda_clk\n");
return -EIO;
}
clk_set_rate(clk, sh_sir_find_sclk(clk));
rate = clk_get_rate(clk);
clk_put(clk);
dev_dbg(dev, "selected sclk = %d\n", rate);
irbc = rate / SCLK_BASE;
tmp = rate - (SCLK_BASE * irbc);
tmp *= 10000;
rerr = tmp / SCLK_BASE;
min = 0xffffffff;
irbca = 0;
for (i = 0; i < ARRAY_SIZE(rate_err_array); i++) {
tmp = abs(rate_err_array[i] - rerr);
if (min > tmp) {
min = tmp;
irbca = i;
}
}
tmp = rate / (irbc + ERR_ROUNDING(rate_err_array[irbca]));
if ((SCLK_BASE / 100) < abs(tmp - SCLK_BASE))
dev_warn(dev, "IrDA freq error margin over %d\n", tmp);
dev_dbg(dev, "target = %d, result = %d, infrared = %d.%d\n",
SCLK_BASE, tmp, irbc, rate_err_array[irbca]);
irbca = (irbca & 0xF) << 4;
irbc = (irbc - 1) & 0xF;
if (!irbc) {
dev_err(dev, "sh_sir can not set 0 in IRIF_SIR2\n");
return -EIO;
}
sh_sir_write(self, IRIF_SIR0, IRTPW | IRERRC);
sh_sir_write(self, IRIF_SIR1, irbca);
sh_sir_write(self, IRIF_SIR2, irbc);
uabc = rate / baudrate;
uabc = (uabc / 16) - 1;
uabc = (uabc + 1) * 16;
tmp = rate - (uabc * baudrate);
tmp *= 10000;
rerr = tmp / baudrate;
min = 0xffffffff;
uabca = 0;
for (i = 0; i < ARRAY_SIZE(rate_err_array); i++) {
tmp = abs(rate_err_array[i] - rerr);
if (min > tmp) {
min = tmp;
uabca = i;
}
}
tmp = rate / (uabc + ERR_ROUNDING(rate_err_array[uabca]));
if ((baudrate / 100) < abs(tmp - baudrate))
dev_warn(dev, "UART freq error margin over %d\n", tmp);
dev_dbg(dev, "target = %d, result = %d, uart = %d.%d\n",
baudrate, tmp,
uabc, rate_err_array[uabca]);
uabca = (uabca & 0xF) << 4;
uabc = (uabc / 16) - 1;
sh_sir_write(self, IRIF_UART6, uabca);
sh_sir_write(self, IRIF_UART7, uabc);
return 0;
}
static int __sh_sir_init_iobuf(iobuff_t *io, int size)
{
io->head = kmalloc(size, GFP_KERNEL);
if (!io->head)
return -ENOMEM;
io->truesize = size;
io->in_frame = FALSE;
io->state = OUTSIDE_FRAME;
io->data = io->head;
return 0;
}
static void sh_sir_remove_iobuf(struct sh_sir_self *self)
{
kfree(self->rx_buff.head);
kfree(self->tx_buff.head);
self->rx_buff.head = NULL;
self->tx_buff.head = NULL;
}
static int sh_sir_init_iobuf(struct sh_sir_self *self, int rxsize, int txsize)
{
int err = -ENOMEM;
if (self->rx_buff.head ||
self->tx_buff.head) {
dev_err(&self->ndev->dev, "iobuff has already existed.");
return err;
}
err = __sh_sir_init_iobuf(&self->rx_buff, rxsize);
if (err)
goto iobuf_err;
err = __sh_sir_init_iobuf(&self->tx_buff, txsize);
iobuf_err:
if (err)
sh_sir_remove_iobuf(self);
return err;
}
static void sh_sir_clear_all_err(struct sh_sir_self *self)
{
sh_sir_update_bits(self, IRIF_SIR0, IRERRC, IRERRC);
sh_sir_write(self, IRIF_SIR_FLG, 0xffff);
sh_sir_write(self, IRIF_UART_STS2, 0);
}
static void sh_sir_set_phase(struct sh_sir_self *self, int phase)
{
u16 uart5 = 0;
u16 uart0 = 0;
switch (phase) {
case TX_PHASE:
uart5 = TBEIM;
uart0 = TBEC | TIE;
break;
case TX_COMP_PHASE:
uart5 = TSBEIM;
uart0 = TIE;
break;
case RX_PHASE:
uart5 = RX_MASK;
uart0 = RIE;
break;
default:
break;
}
sh_sir_write(self, IRIF_UART5, uart5);
sh_sir_write(self, IRIF_UART0, uart0);
}
static int sh_sir_is_which_phase(struct sh_sir_self *self)
{
u16 val = sh_sir_read(self, IRIF_UART5);
if (val & TBEIM)
return TX_PHASE;
if (val & TSBEIM)
return TX_COMP_PHASE;
if (val & RX_MASK)
return RX_PHASE;
return NONE_PHASE;
}
static void sh_sir_tx(struct sh_sir_self *self, int phase)
{
switch (phase) {
case TX_PHASE:
if (0 >= self->tx_buff.len) {
sh_sir_set_phase(self, TX_COMP_PHASE);
} else {
sh_sir_write(self, IRIF_UART3, self->tx_buff.data[0]);
self->tx_buff.len--;
self->tx_buff.data++;
}
break;
case TX_COMP_PHASE:
sh_sir_set_phase(self, RX_PHASE);
netif_wake_queue(self->ndev);
break;
default:
dev_err(&self->ndev->dev, "should not happen\n");
break;
}
}
static int sh_sir_read_data(struct sh_sir_self *self)
{
u16 val = 0;
int timeout = 1024;
while (timeout--) {
val = sh_sir_read(self, IRIF_UART1);
if (val & RBF) {
if (val & (URSME | UROVE | URFRE | URPRE))
break;
return (int)sh_sir_read(self, IRIF_UART4);
}
udelay(1);
}
dev_err(&self->ndev->dev, "UART1 %04x : STATUS %04x\n",
val, sh_sir_read(self, IRIF_UART_STS2));
sh_sir_read(self, IRIF_UART4);
return -1;
}
static void sh_sir_rx(struct sh_sir_self *self)
{
int timeout = 1024;
int data;
while (timeout--) {
data = sh_sir_read_data(self);
if (data < 0)
break;
async_unwrap_char(self->ndev, &self->ndev->stats,
&self->rx_buff, (u8)data);
self->ndev->last_rx = jiffies;
if (EOFD & sh_sir_read(self, IRIF_SIR_FRM))
continue;
break;
}
}
static irqreturn_t sh_sir_irq(int irq, void *dev_id)
{
struct sh_sir_self *self = dev_id;
struct device *dev = &self->ndev->dev;
int phase = sh_sir_is_which_phase(self);
switch (phase) {
case TX_COMP_PHASE:
case TX_PHASE:
sh_sir_tx(self, phase);
break;
case RX_PHASE:
if (sh_sir_read(self, IRIF_SIR3))
dev_err(dev, "rcv pulse width error occurred\n");
sh_sir_rx(self);
sh_sir_clear_all_err(self);
break;
default:
dev_err(dev, "unknown interrupt\n");
}
return IRQ_HANDLED;
}
static int sh_sir_hard_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct sh_sir_self *self = netdev_priv(ndev);
int speed = irda_get_next_speed(skb);
if ((0 < speed) &&
(9600 != speed)) {
dev_err(&ndev->dev, "support 9600 only (%d)\n", speed);
return -EIO;
}
netif_stop_queue(ndev);
self->tx_buff.data = self->tx_buff.head;
self->tx_buff.len = 0;
if (skb->len)
self->tx_buff.len = async_wrap_skb(skb, self->tx_buff.data,
self->tx_buff.truesize);
sh_sir_set_phase(self, TX_PHASE);
dev_kfree_skb(skb);
return 0;
}
static int sh_sir_ioctl(struct net_device *ndev, struct ifreq *ifreq, int cmd)
{
return 0;
}
static struct net_device_stats *sh_sir_stats(struct net_device *ndev)
{
struct sh_sir_self *self = netdev_priv(ndev);
return &self->ndev->stats;
}
static int sh_sir_open(struct net_device *ndev)
{
struct sh_sir_self *self = netdev_priv(ndev);
int err;
clk_enable(self->clk);
err = sh_sir_crc_init(self);
if (err)
goto open_err;
sh_sir_set_baudrate(self, 9600);
self->irlap = irlap_open(ndev, &self->qos, DRIVER_NAME);
if (!self->irlap) {
err = -ENODEV;
goto open_err;
}
sh_sir_update_bits(self, IRIF_SIR_FRM, FRP, FRP);
sh_sir_read(self, IRIF_UART1);
sh_sir_read(self, IRIF_UART4);
sh_sir_set_phase(self, RX_PHASE);
netif_start_queue(ndev);
dev_info(&self->ndev->dev, "opened\n");
return 0;
open_err:
clk_disable(self->clk);
return err;
}
static int sh_sir_stop(struct net_device *ndev)
{
struct sh_sir_self *self = netdev_priv(ndev);
if (self->irlap) {
irlap_close(self->irlap);
self->irlap = NULL;
}
netif_stop_queue(ndev);
dev_info(&ndev->dev, "stopped\n");
return 0;
}
static int __devinit sh_sir_probe(struct platform_device *pdev)
{
struct net_device *ndev;
struct sh_sir_self *self;
struct resource *res;
char clk_name[8];
int irq;
int err = -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || irq < 0) {
dev_err(&pdev->dev, "Not enough platform resources.\n");
goto exit;
}
ndev = alloc_irdadev(sizeof(*self));
if (!ndev)
goto exit;
self = netdev_priv(ndev);
self->membase = ioremap_nocache(res->start, resource_size(res));
if (!self->membase) {
err = -ENXIO;
dev_err(&pdev->dev, "Unable to ioremap.\n");
goto err_mem_1;
}
err = sh_sir_init_iobuf(self, IRDA_SKB_MAX_MTU, IRDA_SIR_MAX_FRAME);
if (err)
goto err_mem_2;
snprintf(clk_name, sizeof(clk_name), "irda%d", pdev->id);
self->clk = clk_get(&pdev->dev, clk_name);
if (IS_ERR(self->clk)) {
dev_err(&pdev->dev, "cannot get clock \"%s\"\n", clk_name);
goto err_mem_3;
}
irda_init_max_qos_capabilies(&self->qos);
ndev->netdev_ops = &sh_sir_ndo;
ndev->irq = irq;
self->ndev = ndev;
self->qos.baud_rate.bits &= IR_9600;
self->qos.min_turn_time.bits = 1;
irda_qos_bits_to_value(&self->qos);
err = register_netdev(ndev);
if (err)
goto err_mem_4;
platform_set_drvdata(pdev, ndev);
if (request_irq(irq, sh_sir_irq, IRQF_DISABLED, "sh_sir", self)) {
dev_warn(&pdev->dev, "Unable to attach sh_sir interrupt\n");
goto err_mem_4;
}
dev_info(&pdev->dev, "SuperH IrDA probed\n");
goto exit;
err_mem_4:
clk_put(self->clk);
err_mem_3:
sh_sir_remove_iobuf(self);
err_mem_2:
iounmap(self->membase);
err_mem_1:
free_netdev(ndev);
exit:
return err;
}
static int __devexit sh_sir_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct sh_sir_self *self = netdev_priv(ndev);
if (!self)
return 0;
unregister_netdev(ndev);
clk_put(self->clk);
sh_sir_remove_iobuf(self);
iounmap(self->membase);
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
return 0;
}
