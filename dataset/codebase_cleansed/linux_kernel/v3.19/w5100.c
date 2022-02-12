static inline u8 w5100_read_direct(struct w5100_priv *priv, u16 addr)
{
return ioread8(priv->base + (addr << CONFIG_WIZNET_BUS_SHIFT));
}
static inline void w5100_write_direct(struct w5100_priv *priv,
u16 addr, u8 data)
{
iowrite8(data, priv->base + (addr << CONFIG_WIZNET_BUS_SHIFT));
}
static u16 w5100_read16_direct(struct w5100_priv *priv, u16 addr)
{
u16 data;
data = w5100_read_direct(priv, addr) << 8;
data |= w5100_read_direct(priv, addr + 1);
return data;
}
static void w5100_write16_direct(struct w5100_priv *priv, u16 addr, u16 data)
{
w5100_write_direct(priv, addr, data >> 8);
w5100_write_direct(priv, addr + 1, data);
}
static void w5100_readbuf_direct(struct w5100_priv *priv,
u16 offset, u8 *buf, int len)
{
u16 addr = W5100_RX_MEM_START + (offset & W5100_RX_MEM_MASK);
int i;
for (i = 0; i < len; i++, addr++) {
if (unlikely(addr > W5100_RX_MEM_END))
addr = W5100_RX_MEM_START;
*buf++ = w5100_read_direct(priv, addr);
}
}
static void w5100_writebuf_direct(struct w5100_priv *priv,
u16 offset, u8 *buf, int len)
{
u16 addr = W5100_TX_MEM_START + (offset & W5100_TX_MEM_MASK);
int i;
for (i = 0; i < len; i++, addr++) {
if (unlikely(addr > W5100_TX_MEM_END))
addr = W5100_TX_MEM_START;
w5100_write_direct(priv, addr, *buf++);
}
}
static u8 w5100_read_indirect(struct w5100_priv *priv, u16 addr)
{
unsigned long flags;
u8 data;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
data = w5100_read_direct(priv, W5100_IDM_DR);
spin_unlock_irqrestore(&priv->reg_lock, flags);
return data;
}
static void w5100_write_indirect(struct w5100_priv *priv, u16 addr, u8 data)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
w5100_write_direct(priv, W5100_IDM_DR, data);
mmiowb();
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
static u16 w5100_read16_indirect(struct w5100_priv *priv, u16 addr)
{
unsigned long flags;
u16 data;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
data = w5100_read_direct(priv, W5100_IDM_DR) << 8;
data |= w5100_read_direct(priv, W5100_IDM_DR);
spin_unlock_irqrestore(&priv->reg_lock, flags);
return data;
}
static void w5100_write16_indirect(struct w5100_priv *priv, u16 addr, u16 data)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
w5100_write_direct(priv, W5100_IDM_DR, data >> 8);
w5100_write_direct(priv, W5100_IDM_DR, data);
mmiowb();
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
static void w5100_readbuf_indirect(struct w5100_priv *priv,
u16 offset, u8 *buf, int len)
{
u16 addr = W5100_RX_MEM_START + (offset & W5100_RX_MEM_MASK);
unsigned long flags;
int i;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
for (i = 0; i < len; i++, addr++) {
if (unlikely(addr > W5100_RX_MEM_END)) {
addr = W5100_RX_MEM_START;
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
}
*buf++ = w5100_read_direct(priv, W5100_IDM_DR);
}
mmiowb();
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
static void w5100_writebuf_indirect(struct w5100_priv *priv,
u16 offset, u8 *buf, int len)
{
u16 addr = W5100_TX_MEM_START + (offset & W5100_TX_MEM_MASK);
unsigned long flags;
int i;
spin_lock_irqsave(&priv->reg_lock, flags);
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
for (i = 0; i < len; i++, addr++) {
if (unlikely(addr > W5100_TX_MEM_END)) {
addr = W5100_TX_MEM_START;
w5100_write16_direct(priv, W5100_IDM_AR, addr);
mmiowb();
}
w5100_write_direct(priv, W5100_IDM_DR, *buf++);
}
mmiowb();
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
static int w5100_command(struct w5100_priv *priv, u16 cmd)
{
unsigned long timeout = jiffies + msecs_to_jiffies(100);
w5100_write(priv, W5100_S0_CR, cmd);
mmiowb();
while (w5100_read(priv, W5100_S0_CR) != 0) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
return 0;
}
static void w5100_write_macaddr(struct w5100_priv *priv)
{
struct net_device *ndev = priv->ndev;
int i;
for (i = 0; i < ETH_ALEN; i++)
w5100_write(priv, W5100_SHAR + i, ndev->dev_addr[i]);
mmiowb();
}
static void w5100_hw_reset(struct w5100_priv *priv)
{
w5100_write_direct(priv, W5100_MR, MR_RST);
mmiowb();
mdelay(5);
w5100_write_direct(priv, W5100_MR, priv->indirect ?
MR_PB | MR_AI | MR_IND :
MR_PB);
mmiowb();
w5100_write(priv, W5100_IMR, 0);
w5100_write_macaddr(priv);
w5100_write(priv, W5100_RMSR, 0x03);
w5100_write(priv, W5100_TMSR, 0x03);
mmiowb();
}
static void w5100_hw_start(struct w5100_priv *priv)
{
w5100_write(priv, W5100_S0_MR, priv->promisc ?
S0_MR_MACRAW : S0_MR_MACRAW_MF);
mmiowb();
w5100_command(priv, S0_CR_OPEN);
w5100_write(priv, W5100_IMR, IR_S0);
mmiowb();
}
static void w5100_hw_close(struct w5100_priv *priv)
{
w5100_write(priv, W5100_IMR, 0);
mmiowb();
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
struct ethtool_regs *regs, void *_buf)
{
struct w5100_priv *priv = netdev_priv(ndev);
u8 *buf = _buf;
u16 i;
regs->version = 1;
for (i = 0; i < W5100_COMMON_REGS_LEN; i++)
*buf++ = w5100_read(priv, W5100_COMMON_REGS + i);
for (i = 0; i < W5100_S0_REGS_LEN; i++)
*buf++ = w5100_read(priv, W5100_S0_REGS + i);
}
static void w5100_tx_timeout(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
w5100_hw_reset(priv);
w5100_hw_start(priv);
ndev->stats.tx_errors++;
ndev->trans_start = jiffies;
netif_wake_queue(ndev);
}
static int w5100_start_tx(struct sk_buff *skb, struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
u16 offset;
netif_stop_queue(ndev);
offset = w5100_read16(priv, W5100_S0_TX_WR);
w5100_writebuf(priv, offset, skb->data, skb->len);
w5100_write16(priv, W5100_S0_TX_WR, offset + skb->len);
mmiowb();
ndev->stats.tx_bytes += skb->len;
ndev->stats.tx_packets++;
dev_kfree_skb(skb);
w5100_command(priv, S0_CR_SEND);
return NETDEV_TX_OK;
}
static int w5100_napi_poll(struct napi_struct *napi, int budget)
{
struct w5100_priv *priv = container_of(napi, struct w5100_priv, napi);
struct net_device *ndev = priv->ndev;
struct sk_buff *skb;
int rx_count;
u16 rx_len;
u16 offset;
u8 header[2];
for (rx_count = 0; rx_count < budget; rx_count++) {
u16 rx_buf_len = w5100_read16(priv, W5100_S0_RX_RSR);
if (rx_buf_len == 0)
break;
offset = w5100_read16(priv, W5100_S0_RX_RD);
w5100_readbuf(priv, offset, header, 2);
rx_len = get_unaligned_be16(header) - 2;
skb = netdev_alloc_skb_ip_align(ndev, rx_len);
if (unlikely(!skb)) {
w5100_write16(priv, W5100_S0_RX_RD,
offset + rx_buf_len);
w5100_command(priv, S0_CR_RECV);
ndev->stats.rx_dropped++;
return -ENOMEM;
}
skb_put(skb, rx_len);
w5100_readbuf(priv, offset + 2, skb->data, rx_len);
w5100_write16(priv, W5100_S0_RX_RD, offset + 2 + rx_len);
mmiowb();
w5100_command(priv, S0_CR_RECV);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += rx_len;
}
if (rx_count < budget) {
w5100_write(priv, W5100_IMR, IR_S0);
mmiowb();
napi_complete(napi);
}
return rx_count;
}
static irqreturn_t w5100_interrupt(int irq, void *ndev_instance)
{
struct net_device *ndev = ndev_instance;
struct w5100_priv *priv = netdev_priv(ndev);
int ir = w5100_read(priv, W5100_S0_IR);
if (!ir)
return IRQ_NONE;
w5100_write(priv, W5100_S0_IR, ir);
mmiowb();
if (ir & S0_IR_SENDOK) {
netif_dbg(priv, tx_done, ndev, "tx done\n");
netif_wake_queue(ndev);
}
if (ir & S0_IR_RECV) {
if (napi_schedule_prep(&priv->napi)) {
w5100_write(priv, W5100_IMR, 0);
mmiowb();
__napi_schedule(&priv->napi);
}
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
static void w5100_set_rx_mode(struct net_device *ndev)
{
struct w5100_priv *priv = netdev_priv(ndev);
bool set_promisc = (ndev->flags & IFF_PROMISC) != 0;
if (priv->promisc != set_promisc) {
priv->promisc = set_promisc;
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
static int w5100_hw_probe(struct platform_device *pdev)
{
struct wiznet_platform_data *data = dev_get_platdata(&pdev->dev);
struct net_device *ndev = platform_get_drvdata(pdev);
struct w5100_priv *priv = netdev_priv(ndev);
const char *name = netdev_name(ndev);
struct resource *mem;
int mem_size;
int irq;
int ret;
if (data && is_valid_ether_addr(data->mac_addr)) {
memcpy(ndev->dev_addr, data->mac_addr, ETH_ALEN);
} else {
eth_hw_addr_random(ndev);
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
mem_size = resource_size(mem);
spin_lock_init(&priv->reg_lock);
priv->indirect = mem_size < W5100_BUS_DIRECT_SIZE;
if (priv->indirect) {
priv->read = w5100_read_indirect;
priv->write = w5100_write_indirect;
priv->read16 = w5100_read16_indirect;
priv->write16 = w5100_write16_indirect;
priv->readbuf = w5100_readbuf_indirect;
priv->writebuf = w5100_writebuf_indirect;
} else {
priv->read = w5100_read_direct;
priv->write = w5100_write_direct;
priv->read16 = w5100_read16_direct;
priv->write16 = w5100_write16_direct;
priv->readbuf = w5100_readbuf_direct;
priv->writebuf = w5100_writebuf_direct;
}
w5100_hw_reset(priv);
if (w5100_read16(priv, W5100_RTR) != RTR_DEFAULT)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
ret = request_irq(irq, w5100_interrupt,
IRQ_TYPE_LEVEL_LOW, name, ndev);
if (ret < 0)
return ret;
priv->irq = irq;
priv->link_gpio = data ? data->link_gpio : -EINVAL;
if (gpio_is_valid(priv->link_gpio)) {
char *link_name = devm_kzalloc(&pdev->dev, 16, GFP_KERNEL);
if (!link_name)
return -ENOMEM;
snprintf(link_name, 16, "%s-link", name);
priv->link_irq = gpio_to_irq(priv->link_gpio);
if (request_any_context_irq(priv->link_irq, w5100_detect_link,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
link_name, priv->ndev) < 0)
priv->link_gpio = -EINVAL;
}
netdev_info(ndev, "at 0x%llx irq %d\n", (u64)mem->start, irq);
return 0;
}
static int w5100_probe(struct platform_device *pdev)
{
struct w5100_priv *priv;
struct net_device *ndev;
int err;
ndev = alloc_etherdev(sizeof(*priv));
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, &pdev->dev);
platform_set_drvdata(pdev, ndev);
priv = netdev_priv(ndev);
priv->ndev = ndev;
ndev->netdev_ops = &w5100_netdev_ops;
ndev->ethtool_ops = &w5100_ethtool_ops;
ndev->watchdog_timeo = HZ;
netif_napi_add(ndev, &priv->napi, w5100_napi_poll, 16);
ndev->features |= NETIF_F_VLAN_CHALLENGED;
err = register_netdev(ndev);
if (err < 0)
goto err_register;
err = w5100_hw_probe(pdev);
if (err < 0)
goto err_hw_probe;
return 0;
err_hw_probe:
unregister_netdev(ndev);
err_register:
free_netdev(ndev);
return err;
}
static int w5100_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct w5100_priv *priv = netdev_priv(ndev);
w5100_hw_reset(priv);
free_irq(priv->irq, ndev);
if (gpio_is_valid(priv->link_gpio))
free_irq(priv->link_irq, ndev);
unregister_netdev(ndev);
free_netdev(ndev);
return 0;
}
static int w5100_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
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
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
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
