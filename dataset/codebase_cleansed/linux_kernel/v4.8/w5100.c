static inline struct w5100_mmio_priv *w5100_mmio_priv(struct net_device *dev)
{
return w5100_ops_priv(dev);
}
static inline void __iomem *w5100_mmio(struct net_device *ndev)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
return mmio_priv->base;
}
static inline int w5100_read_direct(struct net_device *ndev, u32 addr)
{
return ioread8(w5100_mmio(ndev) + (addr << CONFIG_WIZNET_BUS_SHIFT));
}
static inline int __w5100_write_direct(struct net_device *ndev, u32 addr,
u8 data)
{
iowrite8(data, w5100_mmio(ndev) + (addr << CONFIG_WIZNET_BUS_SHIFT));
return 0;
}
static inline int w5100_write_direct(struct net_device *ndev, u32 addr, u8 data)
{
__w5100_write_direct(ndev, addr, data);
mmiowb();
return 0;
}
static int w5100_read16_direct(struct net_device *ndev, u32 addr)
{
u16 data;
data = w5100_read_direct(ndev, addr) << 8;
data |= w5100_read_direct(ndev, addr + 1);
return data;
}
static int w5100_write16_direct(struct net_device *ndev, u32 addr, u16 data)
{
__w5100_write_direct(ndev, addr, data >> 8);
__w5100_write_direct(ndev, addr + 1, data);
mmiowb();
return 0;
}
static int w5100_readbulk_direct(struct net_device *ndev, u32 addr, u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++, addr++)
*buf++ = w5100_read_direct(ndev, addr);
return 0;
}
static int w5100_writebulk_direct(struct net_device *ndev, u32 addr,
const u8 *buf, int len)
{
int i;
for (i = 0; i < len; i++, addr++)
__w5100_write_direct(ndev, addr, *buf++);
mmiowb();
return 0;
}
static int w5100_mmio_init(struct net_device *ndev)
{
struct platform_device *pdev = to_platform_device(ndev->dev.parent);
struct w5100_priv *priv = netdev_priv(ndev);
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
struct resource *mem;
spin_lock_init(&mmio_priv->reg_lock);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio_priv->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(mmio_priv->base))
return PTR_ERR(mmio_priv->base);
netdev_info(ndev, "at 0x%llx irq %d\n", (u64)mem->start, priv->irq);
return 0;
}
static int w5100_read_indirect(struct net_device *ndev, u32 addr)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
u8 data;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
data = w5100_read_direct(ndev, W5100_IDM_DR);
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return data;
}
static int w5100_write_indirect(struct net_device *ndev, u32 addr, u8 data)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
w5100_write_direct(ndev, W5100_IDM_DR, data);
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return 0;
}
static int w5100_read16_indirect(struct net_device *ndev, u32 addr)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
u16 data;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
data = w5100_read_direct(ndev, W5100_IDM_DR) << 8;
data |= w5100_read_direct(ndev, W5100_IDM_DR);
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return data;
}
static int w5100_write16_indirect(struct net_device *ndev, u32 addr, u16 data)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
__w5100_write_direct(ndev, W5100_IDM_DR, data >> 8);
w5100_write_direct(ndev, W5100_IDM_DR, data);
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return 0;
}
static int w5100_readbulk_indirect(struct net_device *ndev, u32 addr, u8 *buf,
int len)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
int i;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
for (i = 0; i < len; i++)
*buf++ = w5100_read_direct(ndev, W5100_IDM_DR);
mmiowb();
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return 0;
}
static int w5100_writebulk_indirect(struct net_device *ndev, u32 addr,
const u8 *buf, int len)
{
struct w5100_mmio_priv *mmio_priv = w5100_mmio_priv(ndev);
unsigned long flags;
int i;
spin_lock_irqsave(&mmio_priv->reg_lock, flags);
w5100_write16_direct(ndev, W5100_IDM_AR, addr);
for (i = 0; i < len; i++)
__w5100_write_direct(ndev, W5100_IDM_DR, *buf++);
mmiowb();
spin_unlock_irqrestore(&mmio_priv->reg_lock, flags);
return 0;
}
static int w5100_reset_indirect(struct net_device *ndev)
{
w5100_write_direct(ndev, W5100_MR, MR_RST);
mdelay(5);
w5100_write_direct(ndev, W5100_MR, MR_PB | MR_AI | MR_IND);
return 0;
}
static int w5100_read(struct w5100_priv *priv, u32 addr)
{
return w5100_read_direct(priv->ndev, addr);
}
static int w5100_write(struct w5100_priv *priv, u32 addr, u8 data)
{
return w5100_write_direct(priv->ndev, addr, data);
}
static int w5100_read16(struct w5100_priv *priv, u32 addr)
{
return w5100_read16_direct(priv->ndev, addr);
}
static int w5100_write16(struct w5100_priv *priv, u32 addr, u16 data)
{
return w5100_write16_direct(priv->ndev, addr, data);
}
static int w5100_readbulk(struct w5100_priv *priv, u32 addr, u8 *buf, int len)
{
return w5100_readbulk_direct(priv->ndev, addr, buf, len);
}
static int w5100_writebulk(struct w5100_priv *priv, u32 addr, const u8 *buf,
int len)
{
return w5100_writebulk_direct(priv->ndev, addr, buf, len);
}
static int w5100_read(struct w5100_priv *priv, u32 addr)
{
return w5100_read_indirect(priv->ndev, addr);
}
static int w5100_write(struct w5100_priv *priv, u32 addr, u8 data)
{
return w5100_write_indirect(priv->ndev, addr, data);
}
static int w5100_read16(struct w5100_priv *priv, u32 addr)
{
return w5100_read16_indirect(priv->ndev, addr);
}
static int w5100_write16(struct w5100_priv *priv, u32 addr, u16 data)
{
return w5100_write16_indirect(priv->ndev, addr, data);
}
static int w5100_readbulk(struct w5100_priv *priv, u32 addr, u8 *buf, int len)
{
return w5100_readbulk_indirect(priv->ndev, addr, buf, len);
}
static int w5100_writebulk(struct w5100_priv *priv, u32 addr, const u8 *buf,
int len)
{
return w5100_writebulk_indirect(priv->ndev, addr, buf, len);
}
static int w5100_read(struct w5100_priv *priv, u32 addr)
{
return priv->ops->read(priv->ndev, addr);
}
static int w5100_write(struct w5100_priv *priv, u32 addr, u8 data)
{
return priv->ops->write(priv->ndev, addr, data);
}
static int w5100_read16(struct w5100_priv *priv, u32 addr)
{
return priv->ops->read16(priv->ndev, addr);
}
static int w5100_write16(struct w5100_priv *priv, u32 addr, u16 data)
{
return priv->ops->write16(priv->ndev, addr, data);
}
static int w5100_readbulk(struct w5100_priv *priv, u32 addr, u8 *buf, int len)
{
return priv->ops->readbulk(priv->ndev, addr, buf, len);
}
static int w5100_writebulk(struct w5100_priv *priv, u32 addr, const u8 *buf,
int len)
{
return priv->ops->writebulk(priv->ndev, addr, buf, len);
}
static int w5100_readbuf(struct w5100_priv *priv, u16 offset, u8 *buf, int len)
{
u32 addr;
int remain = 0;
int ret;
const u32 mem_start = priv->s0_rx_buf;
const u16 mem_size = priv->s0_rx_buf_size;
offset %= mem_size;
addr = mem_start + offset;
if (offset + len > mem_size) {
remain = (offset + len) % mem_size;
len = mem_size - offset;
}
ret = w5100_readbulk(priv, addr, buf, len);
if (ret || !remain)
return ret;
return w5100_readbulk(priv, mem_start, buf + len, remain);
}
static int w5100_writebuf(struct w5100_priv *priv, u16 offset, const u8 *buf,
int len)
{
u32 addr;
int ret;
int remain = 0;
const u32 mem_start = priv->s0_tx_buf;
const u16 mem_size = priv->s0_tx_buf_size;
offset %= mem_size;
addr = mem_start + offset;
if (offset + len > mem_size) {
remain = (offset + len) % mem_size;
len = mem_size - offset;
}
ret = w5100_writebulk(priv, addr, buf, len);
if (ret || !remain)
return ret;
return w5100_writebulk(priv, mem_start, buf + len, remain);
}
static int w5100_reset(struct w5100_priv *priv)
{
if (priv->ops->reset)
return priv->ops->reset(priv->ndev);
w5100_write(priv, W5100_MR, MR_RST);
mdelay(5);
w5100_write(priv, W5100_MR, MR_PB);
return 0;
}
static int w5100_command(struct w5100_priv *priv, u16 cmd)
{
unsigned long timeout;
w5100_write(priv, W5100_S0_CR(priv), cmd);
timeout = jiffies + msecs_to_jiffies(100);
while (w5100_read(priv, W5100_S0_CR(priv)) != 0) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
return 0;
}
static void w5100_write_macaddr(struct w5100_priv *priv)
{
struct net_device *ndev = priv->ndev;
w5100_writebulk(priv, W5100_SHAR, ndev->dev_addr, ETH_ALEN);
}
static void w5100_socket_intr_mask(struct w5100_priv *priv, u8 mask)
{
u32 imr;
if (priv->ops->chip_id == W5500)
imr = W5500_SIMR;
else
imr = W5100_IMR;
w5100_write(priv, imr, mask);
}
static void w5100_enable_intr(struct w5100_priv *priv)
{
w5100_socket_intr_mask(priv, IR_S0);
}
static void w5100_disable_intr(struct w5100_priv *priv)
{
w5100_socket_intr_mask(priv, 0);
}
static void w5100_memory_configure(struct w5100_priv *priv)
{
w5100_write(priv, W5100_RMSR, 0x03);
w5100_write(priv, W5100_TMSR, 0x03);
}
static void w5200_memory_configure(struct w5100_priv *priv)
{
int i;
w5100_write(priv, W5200_Sn_RXMEM_SIZE(0), 0x10);
w5100_write(priv, W5200_Sn_TXMEM_SIZE(0), 0x10);
for (i = 1; i < 8; i++) {
w5100_write(priv, W5200_Sn_RXMEM_SIZE(i), 0);
w5100_write(priv, W5200_Sn_TXMEM_SIZE(i), 0);
}
}
static void w5500_memory_configure(struct w5100_priv *priv)
{
int i;
w5100_write(priv, W5500_Sn_RXMEM_SIZE(0), 0x10);
w5100_write(priv, W5500_Sn_TXMEM_SIZE(0), 0x10);
for (i = 1; i < 8; i++) {
w5100_write(priv, W5500_Sn_RXMEM_SIZE(i), 0);
w5100_write(priv, W5500_Sn_TXMEM_SIZE(i), 0);
}
}
static int w5100_hw_reset(struct w5100_priv *priv)
{
u32 rtr;
w5100_reset(priv);
w5100_disable_intr(priv);
w5100_write_macaddr(priv);
switch (priv->ops->chip_id) {
case W5100:
w5100_memory_configure(priv);
rtr = W5100_RTR;
break;
case W5200:
w5200_memory_configure(priv);
rtr = W5100_RTR;
break;
case W5500:
w5500_memory_configure(priv);
rtr = W5500_RTR;
break;
default:
return -EINVAL;
}
if (w5100_read16(priv, rtr) != RTR_DEFAULT)
return -ENODEV;
return 0;
}
static void w5100_hw_start(struct w5100_priv *priv)
{
u8 mode = S0_MR_MACRAW;
if (!priv->promisc) {
if (priv->ops->chip_id == W5500)
mode |= W5500_S0_MR_MF;
else
mode |= S0_MR_MF;
}
w5100_write(priv, W5100_S0_MR(priv), mode);
w5100_command(priv, S0_CR_OPEN);
w5100_enable_intr(priv);
}
static void w5100_hw_close(struct w5100_priv *priv)
{
w5100_disable_intr(priv);
w5100_command(priv, S0_CR_CLOSE);
}
static void w5100_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, dev_name(ndev->dev.parent),
sizeof(info->bus_info));
}
static u32 w5100_get_link(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
if (gpio_is_valid(priv->link_gpio))
return !!gpio_get_value(priv->link_gpio);
return 1;
}
static u32 w5100_get_msglevel(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
return priv->msg_enable;
}
static void w5100_set_msglevel(struct net_device *ndev, u32 value)
{
struct w5100_priv *priv = netdev_priv(ndev);
priv->msg_enable = value;
}
static int w5100_get_regs_len(struct net_device *ndev)
{
return W5100_COMMON_REGS_LEN + W5100_S0_REGS_LEN;
}
static void w5100_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *buf)
{
struct w5100_priv *priv = netdev_priv(ndev);
regs->version = 1;
w5100_readbulk(priv, W5100_COMMON_REGS, buf, W5100_COMMON_REGS_LEN);
buf += W5100_COMMON_REGS_LEN;
w5100_readbulk(priv, S0_REGS(priv), buf, W5100_S0_REGS_LEN);
}
static void w5100_restart(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
w5100_hw_reset(priv);
w5100_hw_start(priv);
ndev->stats.tx_errors++;
netif_trans_update(ndev);
netif_wake_queue(ndev);
}
static void w5100_restart_work(struct work_struct *work)
{
struct w5100_priv *priv = container_of(work, struct w5100_priv,
restart_work);
w5100_restart(priv->ndev);
}
static void w5100_tx_timeout(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
if (priv->ops->may_sleep)
schedule_work(&priv->restart_work);
else
w5100_restart(ndev);
}
static void w5100_tx_skb(struct net_device *ndev, struct sk_buff *skb)
{
struct w5100_priv *priv = netdev_priv(ndev);
u16 offset;
offset = w5100_read16(priv, W5100_S0_TX_WR(priv));
w5100_writebuf(priv, offset, skb->data, skb->len);
w5100_write16(priv, W5100_S0_TX_WR(priv), offset + skb->len);
ndev->stats.tx_bytes += skb->len;
ndev->stats.tx_packets++;
dev_kfree_skb(skb);
w5100_command(priv, S0_CR_SEND);
}
static void w5100_tx_work(struct work_struct *work)
{
struct w5100_priv *priv = container_of(work, struct w5100_priv,
tx_work);
struct sk_buff *skb = priv->tx_skb;
priv->tx_skb = NULL;
if (WARN_ON(!skb))
return;
w5100_tx_skb(priv->ndev, skb);
}
static int w5100_start_tx(struct sk_buff *skb, struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
if (priv->ops->may_sleep) {
WARN_ON(priv->tx_skb);
priv->tx_skb = skb;
queue_work(priv->xfer_wq, &priv->tx_work);
} else {
w5100_tx_skb(ndev, skb);
}
return NETDEV_TX_OK;
}
static struct sk_buff *w5100_rx_skb(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
struct sk_buff *skb;
u16 rx_len;
u16 offset;
u8 header[2];
u16 rx_buf_len = w5100_read16(priv, W5100_S0_RX_RSR(priv));
if (rx_buf_len == 0)
return NULL;
offset = w5100_read16(priv, W5100_S0_RX_RD(priv));
w5100_readbuf(priv, offset, header, 2);
rx_len = get_unaligned_be16(header) - 2;
skb = netdev_alloc_skb_ip_align(ndev, rx_len);
if (unlikely(!skb)) {
w5100_write16(priv, W5100_S0_RX_RD(priv), offset + rx_buf_len);
w5100_command(priv, S0_CR_RECV);
ndev->stats.rx_dropped++;
return NULL;
}
skb_put(skb, rx_len);
w5100_readbuf(priv, offset + 2, skb->data, rx_len);
w5100_write16(priv, W5100_S0_RX_RD(priv), offset + 2 + rx_len);
w5100_command(priv, S0_CR_RECV);
skb->protocol = eth_type_trans(skb, ndev);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += rx_len;
return skb;
}
static void w5100_rx_work(struct work_struct *work)
{
struct w5100_priv *priv = container_of(work, struct w5100_priv,
rx_work);
struct sk_buff *skb;
while ((skb = w5100_rx_skb(priv->ndev)))
netif_rx_ni(skb);
w5100_enable_intr(priv);
}
static int w5100_napi_poll(struct napi_struct *napi, int budget)
{
struct w5100_priv *priv = container_of(napi, struct w5100_priv, napi);
int rx_count;
for (rx_count = 0; rx_count < budget; rx_count++) {
struct sk_buff *skb = w5100_rx_skb(priv->ndev);
if (skb)
netif_receive_skb(skb);
else
break;
}
if (rx_count < budget) {
napi_complete(napi);
w5100_enable_intr(priv);
}
return rx_count;
}
static irqreturn_t w5100_interrupt(int irq, void *ndev_instance)
{
struct net_device *ndev = ndev_instance;
struct w5100_priv *priv = netdev_priv(ndev);
int ir = w5100_read(priv, W5100_S0_IR(priv));
if (!ir)
return IRQ_NONE;
w5100_write(priv, W5100_S0_IR(priv), ir);
if (ir & S0_IR_SENDOK) {
netif_dbg(priv, tx_done, ndev, "tx done\n");
netif_wake_queue(ndev);
}
if (ir & S0_IR_RECV) {
w5100_disable_intr(priv);
if (priv->ops->may_sleep)
queue_work(priv->xfer_wq, &priv->rx_work);
else if (napi_schedule_prep(&priv->napi))
__napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
static irqreturn_t w5100_detect_link(int irq, void *ndev_instance)
{
struct net_device *ndev = ndev_instance;
struct w5100_priv *priv = netdev_priv(ndev);
if (netif_running(ndev)) {
if (gpio_get_value(priv->link_gpio) != 0) {
netif_info(priv, link, ndev, "link is up\n");
netif_carrier_on(ndev);
} else {
netif_info(priv, link, ndev, "link is down\n");
netif_carrier_off(ndev);
}
}
return IRQ_HANDLED;
}
static void w5100_setrx_work(struct work_struct *work)
{
struct w5100_priv *priv = container_of(work, struct w5100_priv,
setrx_work);
w5100_hw_start(priv);
}
static void w5100_set_rx_mode(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
bool set_promisc = (ndev->flags & IFF_PROMISC) != 0;
if (priv->promisc != set_promisc) {
priv->promisc = set_promisc;
if (priv->ops->may_sleep)
schedule_work(&priv->setrx_work);
else
w5100_hw_start(priv);
}
}
static int w5100_set_macaddr(struct net_device *ndev, void *addr)
{
struct w5100_priv *priv = netdev_priv(ndev);
struct sockaddr *sock_addr = addr;
if (!is_valid_ether_addr(sock_addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, sock_addr->sa_data, ETH_ALEN);
w5100_write_macaddr(priv);
return 0;
}
static int w5100_open(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
netif_info(priv, ifup, ndev, "enabling\n");
w5100_hw_start(priv);
napi_enable(&priv->napi);
netif_start_queue(ndev);
if (!gpio_is_valid(priv->link_gpio) ||
gpio_get_value(priv->link_gpio) != 0)
netif_carrier_on(ndev);
return 0;
}
static int w5100_stop(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
netif_info(priv, ifdown, ndev, "shutting down\n");
w5100_hw_close(priv);
netif_carrier_off(ndev);
netif_stop_queue(ndev);
napi_disable(&priv->napi);
return 0;
}
static int w5100_mmio_probe(struct platform_device *pdev)
{
struct wiznet_platform_data *data = dev_get_platdata(&pdev->dev);
const void *mac_addr = NULL;
struct resource *mem;
const struct w5100_ops *ops;
int irq;
if (data && is_valid_ether_addr(data->mac_addr))
mac_addr = data->mac_addr;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (resource_size(mem) < W5100_BUS_DIRECT_SIZE)
ops = &w5100_mmio_indirect_ops;
else
ops = &w5100_mmio_direct_ops;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
return w5100_probe(&pdev->dev, ops, sizeof(struct w5100_mmio_priv),
mac_addr, irq, data ? data->link_gpio : -EINVAL);
}
static int w5100_mmio_remove(struct platform_device *pdev)
{
return w5100_remove(&pdev->dev);
}
void *w5100_ops_priv(const struct net_device *ndev)
{
return netdev_priv(ndev) +
ALIGN(sizeof(struct w5100_priv), NETDEV_ALIGN);
}
int w5100_probe(struct device *dev, const struct w5100_ops *ops,
int sizeof_ops_priv, const void *mac_addr, int irq,
int link_gpio)
{
struct w5100_priv *priv;
struct net_device *ndev;
int err;
size_t alloc_size;
alloc_size = sizeof(*priv);
if (sizeof_ops_priv) {
alloc_size = ALIGN(alloc_size, NETDEV_ALIGN);
alloc_size += sizeof_ops_priv;
}
alloc_size += NETDEV_ALIGN - 1;
ndev = alloc_etherdev(alloc_size);
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, dev);
dev_set_drvdata(dev, ndev);
priv = netdev_priv(ndev);
switch (ops->chip_id) {
case W5100:
priv->s0_regs = W5100_S0_REGS;
priv->s0_tx_buf = W5100_TX_MEM_START;
priv->s0_tx_buf_size = W5100_TX_MEM_SIZE;
priv->s0_rx_buf = W5100_RX_MEM_START;
priv->s0_rx_buf_size = W5100_RX_MEM_SIZE;
break;
case W5200:
priv->s0_regs = W5200_S0_REGS;
priv->s0_tx_buf = W5200_TX_MEM_START;
priv->s0_tx_buf_size = W5200_TX_MEM_SIZE;
priv->s0_rx_buf = W5200_RX_MEM_START;
priv->s0_rx_buf_size = W5200_RX_MEM_SIZE;
break;
case W5500:
priv->s0_regs = W5500_S0_REGS;
priv->s0_tx_buf = W5500_TX_MEM_START;
priv->s0_tx_buf_size = W5500_TX_MEM_SIZE;
priv->s0_rx_buf = W5500_RX_MEM_START;
priv->s0_rx_buf_size = W5500_RX_MEM_SIZE;
break;
default:
err = -EINVAL;
goto err_register;
}
priv->ndev = ndev;
priv->ops = ops;
priv->irq = irq;
priv->link_gpio = link_gpio;
ndev->netdev_ops = &w5100_netdev_ops;
ndev->ethtool_ops = &w5100_ethtool_ops;
netif_napi_add(ndev, &priv->napi, w5100_napi_poll, 16);
ndev->features |= NETIF_F_VLAN_CHALLENGED;
err = register_netdev(ndev);
if (err < 0)
goto err_register;
priv->xfer_wq = alloc_workqueue(netdev_name(ndev), WQ_MEM_RECLAIM, 0);
if (!priv->xfer_wq) {
err = -ENOMEM;
goto err_wq;
}
INIT_WORK(&priv->rx_work, w5100_rx_work);
INIT_WORK(&priv->tx_work, w5100_tx_work);
INIT_WORK(&priv->setrx_work, w5100_setrx_work);
INIT_WORK(&priv->restart_work, w5100_restart_work);
if (mac_addr)
memcpy(ndev->dev_addr, mac_addr, ETH_ALEN);
else
eth_hw_addr_random(ndev);
if (priv->ops->init) {
err = priv->ops->init(priv->ndev);
if (err)
goto err_hw;
}
err = w5100_hw_reset(priv);
if (err)
goto err_hw;
if (ops->may_sleep) {
err = request_threaded_irq(priv->irq, NULL, w5100_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
netdev_name(ndev), ndev);
} else {
err = request_irq(priv->irq, w5100_interrupt,
IRQF_TRIGGER_LOW, netdev_name(ndev), ndev);
}
if (err)
goto err_hw;
if (gpio_is_valid(priv->link_gpio)) {
char *link_name = devm_kzalloc(dev, 16, GFP_KERNEL);
if (!link_name) {
err = -ENOMEM;
goto err_gpio;
}
snprintf(link_name, 16, "%s-link", netdev_name(ndev));
priv->link_irq = gpio_to_irq(priv->link_gpio);
if (request_any_context_irq(priv->link_irq, w5100_detect_link,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
link_name, priv->ndev) < 0)
priv->link_gpio = -EINVAL;
}
return 0;
err_gpio:
free_irq(priv->irq, ndev);
err_hw:
destroy_workqueue(priv->xfer_wq);
err_wq:
unregister_netdev(ndev);
err_register:
free_netdev(ndev);
return err;
}
int w5100_remove(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct w5100_priv *priv = netdev_priv(ndev);
w5100_hw_reset(priv);
free_irq(priv->irq, ndev);
if (gpio_is_valid(priv->link_gpio))
free_irq(priv->link_irq, ndev);
flush_work(&priv->setrx_work);
flush_work(&priv->restart_work);
destroy_workqueue(priv->xfer_wq);
unregister_netdev(ndev);
free_netdev(ndev);
return 0;
}
static int w5100_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct w5100_priv *priv = netdev_priv(ndev);
if (netif_running(ndev)) {
netif_carrier_off(ndev);
netif_device_detach(ndev);
w5100_hw_close(priv);
}
return 0;
}
static int w5100_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct w5100_priv *priv = netdev_priv(ndev);
if (netif_running(ndev)) {
w5100_hw_reset(priv);
w5100_hw_start(priv);
netif_device_attach(ndev);
if (!gpio_is_valid(priv->link_gpio) ||
gpio_get_value(priv->link_gpio) != 0)
netif_carrier_on(ndev);
}
return 0;
}
