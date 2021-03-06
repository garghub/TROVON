static inline u32 ethoc_read(struct ethoc *dev, loff_t offset)
{
return ioread32(dev->iobase + offset);
}
static inline void ethoc_write(struct ethoc *dev, loff_t offset, u32 data)
{
iowrite32(data, dev->iobase + offset);
}
static inline void ethoc_read_bd(struct ethoc *dev, int index,
struct ethoc_bd *bd)
{
loff_t offset = ETHOC_BD_BASE + (index * sizeof(struct ethoc_bd));
bd->stat = ethoc_read(dev, offset + 0);
bd->addr = ethoc_read(dev, offset + 4);
}
static inline void ethoc_write_bd(struct ethoc *dev, int index,
const struct ethoc_bd *bd)
{
loff_t offset = ETHOC_BD_BASE + (index * sizeof(struct ethoc_bd));
ethoc_write(dev, offset + 0, bd->stat);
ethoc_write(dev, offset + 4, bd->addr);
}
static inline void ethoc_enable_irq(struct ethoc *dev, u32 mask)
{
u32 imask = ethoc_read(dev, INT_MASK);
imask |= mask;
ethoc_write(dev, INT_MASK, imask);
}
static inline void ethoc_disable_irq(struct ethoc *dev, u32 mask)
{
u32 imask = ethoc_read(dev, INT_MASK);
imask &= ~mask;
ethoc_write(dev, INT_MASK, imask);
}
static inline void ethoc_ack_irq(struct ethoc *dev, u32 mask)
{
ethoc_write(dev, INT_SOURCE, mask);
}
static inline void ethoc_enable_rx_and_tx(struct ethoc *dev)
{
u32 mode = ethoc_read(dev, MODER);
mode |= MODER_RXEN | MODER_TXEN;
ethoc_write(dev, MODER, mode);
}
static inline void ethoc_disable_rx_and_tx(struct ethoc *dev)
{
u32 mode = ethoc_read(dev, MODER);
mode &= ~(MODER_RXEN | MODER_TXEN);
ethoc_write(dev, MODER, mode);
}
static int ethoc_init_ring(struct ethoc *dev, unsigned long mem_start)
{
struct ethoc_bd bd;
int i;
void *vma;
dev->cur_tx = 0;
dev->dty_tx = 0;
dev->cur_rx = 0;
ethoc_write(dev, TX_BD_NUM, dev->num_tx);
bd.addr = mem_start;
bd.stat = TX_BD_IRQ | TX_BD_CRC;
vma = dev->membase;
for (i = 0; i < dev->num_tx; i++) {
if (i == dev->num_tx - 1)
bd.stat |= TX_BD_WRAP;
ethoc_write_bd(dev, i, &bd);
bd.addr += ETHOC_BUFSIZ;
dev->vma[i] = vma;
vma += ETHOC_BUFSIZ;
}
bd.stat = RX_BD_EMPTY | RX_BD_IRQ;
for (i = 0; i < dev->num_rx; i++) {
if (i == dev->num_rx - 1)
bd.stat |= RX_BD_WRAP;
ethoc_write_bd(dev, dev->num_tx + i, &bd);
bd.addr += ETHOC_BUFSIZ;
dev->vma[dev->num_tx + i] = vma;
vma += ETHOC_BUFSIZ;
}
return 0;
}
static int ethoc_reset(struct ethoc *dev)
{
u32 mode;
ethoc_disable_rx_and_tx(dev);
mode = ethoc_read(dev, MODER);
mode |= MODER_CRC | MODER_PAD;
ethoc_write(dev, MODER, mode);
mode = ethoc_read(dev, MODER);
mode |= MODER_FULLD;
ethoc_write(dev, MODER, mode);
ethoc_write(dev, IPGT, 0x15);
ethoc_ack_irq(dev, INT_MASK_ALL);
ethoc_enable_irq(dev, INT_MASK_ALL);
ethoc_enable_rx_and_tx(dev);
return 0;
}
static unsigned int ethoc_update_rx_stats(struct ethoc *dev,
struct ethoc_bd *bd)
{
struct net_device *netdev = dev->netdev;
unsigned int ret = 0;
if (bd->stat & RX_BD_TL) {
dev_err(&netdev->dev, "RX: frame too long\n");
netdev->stats.rx_length_errors++;
ret++;
}
if (bd->stat & RX_BD_SF) {
dev_err(&netdev->dev, "RX: frame too short\n");
netdev->stats.rx_length_errors++;
ret++;
}
if (bd->stat & RX_BD_DN) {
dev_err(&netdev->dev, "RX: dribble nibble\n");
netdev->stats.rx_frame_errors++;
}
if (bd->stat & RX_BD_CRC) {
dev_err(&netdev->dev, "RX: wrong CRC\n");
netdev->stats.rx_crc_errors++;
ret++;
}
if (bd->stat & RX_BD_OR) {
dev_err(&netdev->dev, "RX: overrun\n");
netdev->stats.rx_over_errors++;
ret++;
}
if (bd->stat & RX_BD_MISS)
netdev->stats.rx_missed_errors++;
if (bd->stat & RX_BD_LC) {
dev_err(&netdev->dev, "RX: late collision\n");
netdev->stats.collisions++;
ret++;
}
return ret;
}
static int ethoc_rx(struct net_device *dev, int limit)
{
struct ethoc *priv = netdev_priv(dev);
int count;
for (count = 0; count < limit; ++count) {
unsigned int entry;
struct ethoc_bd bd;
entry = priv->num_tx + priv->cur_rx;
ethoc_read_bd(priv, entry, &bd);
if (bd.stat & RX_BD_EMPTY) {
ethoc_ack_irq(priv, INT_MASK_RX);
ethoc_read_bd(priv, entry, &bd);
if (bd.stat & RX_BD_EMPTY)
break;
}
if (ethoc_update_rx_stats(priv, &bd) == 0) {
int size = bd.stat >> 16;
struct sk_buff *skb;
size -= 4;
skb = netdev_alloc_skb_ip_align(dev, size);
if (likely(skb)) {
void *src = priv->vma[entry];
memcpy_fromio(skb_put(skb, size), src, size);
skb->protocol = eth_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += size;
netif_receive_skb(skb);
} else {
if (net_ratelimit())
dev_warn(&dev->dev,
"low on memory - packet dropped\n");
dev->stats.rx_dropped++;
break;
}
}
bd.stat &= ~RX_BD_STATS;
bd.stat |= RX_BD_EMPTY;
ethoc_write_bd(priv, entry, &bd);
if (++priv->cur_rx == priv->num_rx)
priv->cur_rx = 0;
}
return count;
}
static void ethoc_update_tx_stats(struct ethoc *dev, struct ethoc_bd *bd)
{
struct net_device *netdev = dev->netdev;
if (bd->stat & TX_BD_LC) {
dev_err(&netdev->dev, "TX: late collision\n");
netdev->stats.tx_window_errors++;
}
if (bd->stat & TX_BD_RL) {
dev_err(&netdev->dev, "TX: retransmit limit\n");
netdev->stats.tx_aborted_errors++;
}
if (bd->stat & TX_BD_UR) {
dev_err(&netdev->dev, "TX: underrun\n");
netdev->stats.tx_fifo_errors++;
}
if (bd->stat & TX_BD_CS) {
dev_err(&netdev->dev, "TX: carrier sense lost\n");
netdev->stats.tx_carrier_errors++;
}
if (bd->stat & TX_BD_STATS)
netdev->stats.tx_errors++;
netdev->stats.collisions += (bd->stat >> 4) & 0xf;
netdev->stats.tx_bytes += bd->stat >> 16;
netdev->stats.tx_packets++;
}
static int ethoc_tx(struct net_device *dev, int limit)
{
struct ethoc *priv = netdev_priv(dev);
int count;
struct ethoc_bd bd;
for (count = 0; count < limit; ++count) {
unsigned int entry;
entry = priv->dty_tx & (priv->num_tx-1);
ethoc_read_bd(priv, entry, &bd);
if (bd.stat & TX_BD_READY || (priv->dty_tx == priv->cur_tx)) {
ethoc_ack_irq(priv, INT_MASK_TX);
ethoc_read_bd(priv, entry, &bd);
if (bd.stat & TX_BD_READY ||
(priv->dty_tx == priv->cur_tx))
break;
}
ethoc_update_tx_stats(priv, &bd);
priv->dty_tx++;
}
if ((priv->cur_tx - priv->dty_tx) <= (priv->num_tx / 2))
netif_wake_queue(dev);
return count;
}
static irqreturn_t ethoc_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct ethoc *priv = netdev_priv(dev);
u32 pending;
u32 mask;
mask = ethoc_read(priv, INT_MASK);
pending = ethoc_read(priv, INT_SOURCE);
pending &= mask;
if (unlikely(pending == 0))
return IRQ_NONE;
ethoc_ack_irq(priv, pending);
if (pending & INT_MASK_BUSY) {
dev_err(&dev->dev, "packet dropped\n");
dev->stats.rx_dropped++;
}
if (pending & (INT_MASK_TX | INT_MASK_RX)) {
ethoc_disable_irq(priv, INT_MASK_TX | INT_MASK_RX);
napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
static int ethoc_get_mac_address(struct net_device *dev, void *addr)
{
struct ethoc *priv = netdev_priv(dev);
u8 *mac = (u8 *)addr;
u32 reg;
reg = ethoc_read(priv, MAC_ADDR0);
mac[2] = (reg >> 24) & 0xff;
mac[3] = (reg >> 16) & 0xff;
mac[4] = (reg >> 8) & 0xff;
mac[5] = (reg >> 0) & 0xff;
reg = ethoc_read(priv, MAC_ADDR1);
mac[0] = (reg >> 8) & 0xff;
mac[1] = (reg >> 0) & 0xff;
return 0;
}
static int ethoc_poll(struct napi_struct *napi, int budget)
{
struct ethoc *priv = container_of(napi, struct ethoc, napi);
int rx_work_done = 0;
int tx_work_done = 0;
rx_work_done = ethoc_rx(priv->netdev, budget);
tx_work_done = ethoc_tx(priv->netdev, budget);
if (rx_work_done < budget && tx_work_done < budget) {
napi_complete(napi);
ethoc_enable_irq(priv, INT_MASK_TX | INT_MASK_RX);
}
return rx_work_done;
}
static int ethoc_mdio_read(struct mii_bus *bus, int phy, int reg)
{
struct ethoc *priv = bus->priv;
int i;
ethoc_write(priv, MIIADDRESS, MIIADDRESS_ADDR(phy, reg));
ethoc_write(priv, MIICOMMAND, MIICOMMAND_READ);
for (i = 0; i < 5; i++) {
u32 status = ethoc_read(priv, MIISTATUS);
if (!(status & MIISTATUS_BUSY)) {
u32 data = ethoc_read(priv, MIIRX_DATA);
ethoc_write(priv, MIICOMMAND, 0);
return data;
}
usleep_range(100, 200);
}
return -EBUSY;
}
static int ethoc_mdio_write(struct mii_bus *bus, int phy, int reg, u16 val)
{
struct ethoc *priv = bus->priv;
int i;
ethoc_write(priv, MIIADDRESS, MIIADDRESS_ADDR(phy, reg));
ethoc_write(priv, MIITX_DATA, val);
ethoc_write(priv, MIICOMMAND, MIICOMMAND_WRITE);
for (i = 0; i < 5; i++) {
u32 stat = ethoc_read(priv, MIISTATUS);
if (!(stat & MIISTATUS_BUSY)) {
ethoc_write(priv, MIICOMMAND, 0);
return 0;
}
usleep_range(100, 200);
}
return -EBUSY;
}
static int ethoc_mdio_reset(struct mii_bus *bus)
{
return 0;
}
static void ethoc_mdio_poll(struct net_device *dev)
{
}
static int ethoc_mdio_probe(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
struct phy_device *phy;
int err;
if (priv->phy_id != -1)
phy = priv->mdio->phy_map[priv->phy_id];
else
phy = phy_find_first(priv->mdio);
if (!phy) {
dev_err(&dev->dev, "no PHY found\n");
return -ENXIO;
}
err = phy_connect_direct(dev, phy, ethoc_mdio_poll,
PHY_INTERFACE_MODE_GMII);
if (err) {
dev_err(&dev->dev, "could not attach to PHY\n");
return err;
}
priv->phy = phy;
return 0;
}
static int ethoc_open(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
int ret;
ret = request_irq(dev->irq, ethoc_interrupt, IRQF_SHARED,
dev->name, dev);
if (ret)
return ret;
ethoc_init_ring(priv, dev->mem_start);
ethoc_reset(priv);
if (netif_queue_stopped(dev)) {
dev_dbg(&dev->dev, " resuming queue\n");
netif_wake_queue(dev);
} else {
dev_dbg(&dev->dev, " starting queue\n");
netif_start_queue(dev);
}
phy_start(priv->phy);
napi_enable(&priv->napi);
if (netif_msg_ifup(priv)) {
dev_info(&dev->dev, "I/O: %08lx Memory: %08lx-%08lx\n",
dev->base_addr, dev->mem_start, dev->mem_end);
}
return 0;
}
static int ethoc_stop(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
napi_disable(&priv->napi);
if (priv->phy)
phy_stop(priv->phy);
ethoc_disable_rx_and_tx(priv);
free_irq(dev->irq, dev);
if (!netif_queue_stopped(dev))
netif_stop_queue(dev);
return 0;
}
static int ethoc_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct ethoc *priv = netdev_priv(dev);
struct mii_ioctl_data *mdio = if_mii(ifr);
struct phy_device *phy = NULL;
if (!netif_running(dev))
return -EINVAL;
if (cmd != SIOCGMIIPHY) {
if (mdio->phy_id >= PHY_MAX_ADDR)
return -ERANGE;
phy = priv->mdio->phy_map[mdio->phy_id];
if (!phy)
return -ENODEV;
} else {
phy = priv->phy;
}
return phy_mii_ioctl(phy, ifr, cmd);
}
static int ethoc_config(struct net_device *dev, struct ifmap *map)
{
return -ENOSYS;
}
static void ethoc_do_set_mac_address(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
unsigned char *mac = dev->dev_addr;
ethoc_write(priv, MAC_ADDR0, (mac[2] << 24) | (mac[3] << 16) |
(mac[4] << 8) | (mac[5] << 0));
ethoc_write(priv, MAC_ADDR1, (mac[0] << 8) | (mac[1] << 0));
}
static int ethoc_set_mac_address(struct net_device *dev, void *p)
{
const struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
ethoc_do_set_mac_address(dev);
return 0;
}
static void ethoc_set_multicast_list(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
u32 mode = ethoc_read(priv, MODER);
struct netdev_hw_addr *ha;
u32 hash[2] = { 0, 0 };
if (dev->flags & IFF_LOOPBACK)
mode |= MODER_LOOP;
else
mode &= ~MODER_LOOP;
if (dev->flags & IFF_BROADCAST)
mode &= ~MODER_BRO;
else
mode |= MODER_BRO;
if (dev->flags & IFF_PROMISC)
mode |= MODER_PRO;
else
mode &= ~MODER_PRO;
ethoc_write(priv, MODER, mode);
if (dev->flags & IFF_ALLMULTI) {
hash[0] = 0xffffffff;
hash[1] = 0xffffffff;
} else {
netdev_for_each_mc_addr(ha, dev) {
u32 crc = ether_crc(ETH_ALEN, ha->addr);
int bit = (crc >> 26) & 0x3f;
hash[bit >> 5] |= 1 << (bit & 0x1f);
}
}
ethoc_write(priv, ETH_HASH0, hash[0]);
ethoc_write(priv, ETH_HASH1, hash[1]);
}
static int ethoc_change_mtu(struct net_device *dev, int new_mtu)
{
return -ENOSYS;
}
static void ethoc_tx_timeout(struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
u32 pending = ethoc_read(priv, INT_SOURCE);
if (likely(pending))
ethoc_interrupt(dev->irq, dev);
}
static netdev_tx_t ethoc_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ethoc *priv = netdev_priv(dev);
struct ethoc_bd bd;
unsigned int entry;
void *dest;
if (unlikely(skb->len > ETHOC_BUFSIZ)) {
dev->stats.tx_errors++;
goto out;
}
entry = priv->cur_tx % priv->num_tx;
spin_lock_irq(&priv->lock);
priv->cur_tx++;
ethoc_read_bd(priv, entry, &bd);
if (unlikely(skb->len < ETHOC_ZLEN))
bd.stat |= TX_BD_PAD;
else
bd.stat &= ~TX_BD_PAD;
dest = priv->vma[entry];
memcpy_toio(dest, skb->data, skb->len);
bd.stat &= ~(TX_BD_STATS | TX_BD_LEN_MASK);
bd.stat |= TX_BD_LEN(skb->len);
ethoc_write_bd(priv, entry, &bd);
bd.stat |= TX_BD_READY;
ethoc_write_bd(priv, entry, &bd);
if (priv->cur_tx == (priv->dty_tx + priv->num_tx)) {
dev_dbg(&dev->dev, "stopping queue\n");
netif_stop_queue(dev);
}
spin_unlock_irq(&priv->lock);
skb_tx_timestamp(skb);
out:
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ethoc_probe(struct platform_device *pdev)
{
struct net_device *netdev = NULL;
struct resource *res = NULL;
struct resource *mmio = NULL;
struct resource *mem = NULL;
struct ethoc *priv = NULL;
unsigned int phy;
int num_bd;
int ret = 0;
bool random_mac = false;
netdev = alloc_etherdev(sizeof(struct ethoc));
if (!netdev) {
ret = -ENOMEM;
goto out;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
platform_set_drvdata(pdev, netdev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "cannot obtain I/O memory space\n");
ret = -ENXIO;
goto free;
}
mmio = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), res->name);
if (!mmio) {
dev_err(&pdev->dev, "cannot request I/O memory space\n");
ret = -ENXIO;
goto free;
}
netdev->base_addr = mmio->start;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res) {
mem = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), res->name);
if (!mem) {
dev_err(&pdev->dev, "cannot request memory space\n");
ret = -ENXIO;
goto free;
}
netdev->mem_start = mem->start;
netdev->mem_end = mem->end;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "cannot obtain IRQ\n");
ret = -ENXIO;
goto free;
}
netdev->irq = res->start;
priv = netdev_priv(netdev);
priv->netdev = netdev;
priv->dma_alloc = 0;
priv->io_region_size = resource_size(mmio);
priv->iobase = devm_ioremap_nocache(&pdev->dev, netdev->base_addr,
resource_size(mmio));
if (!priv->iobase) {
dev_err(&pdev->dev, "cannot remap I/O memory space\n");
ret = -ENXIO;
goto error;
}
if (netdev->mem_end) {
priv->membase = devm_ioremap_nocache(&pdev->dev,
netdev->mem_start, resource_size(mem));
if (!priv->membase) {
dev_err(&pdev->dev, "cannot remap memory space\n");
ret = -ENXIO;
goto error;
}
} else {
priv->membase = dmam_alloc_coherent(&pdev->dev,
buffer_size, (void *)&netdev->mem_start,
GFP_KERNEL);
if (!priv->membase) {
dev_err(&pdev->dev, "cannot allocate %dB buffer\n",
buffer_size);
ret = -ENOMEM;
goto error;
}
netdev->mem_end = netdev->mem_start + buffer_size;
priv->dma_alloc = buffer_size;
}
num_bd = min_t(unsigned int,
128, (netdev->mem_end - netdev->mem_start + 1) / ETHOC_BUFSIZ);
if (num_bd < 4) {
ret = -ENODEV;
goto error;
}
priv->num_tx = rounddown_pow_of_two(num_bd >> 1);
priv->num_rx = num_bd - priv->num_tx;
dev_dbg(&pdev->dev, "ethoc: num_tx: %d num_rx: %d\n",
priv->num_tx, priv->num_rx);
priv->vma = devm_kzalloc(&pdev->dev, num_bd*sizeof(void *), GFP_KERNEL);
if (!priv->vma) {
ret = -ENOMEM;
goto error;
}
if (dev_get_platdata(&pdev->dev)) {
struct ethoc_platform_data *pdata = dev_get_platdata(&pdev->dev);
memcpy(netdev->dev_addr, pdata->hwaddr, IFHWADDRLEN);
priv->phy_id = pdata->phy_id;
} else {
priv->phy_id = -1;
#ifdef CONFIG_OF
{
const uint8_t *mac;
mac = of_get_property(pdev->dev.of_node,
"local-mac-address",
NULL);
if (mac)
memcpy(netdev->dev_addr, mac, IFHWADDRLEN);
}
#endif
}
if (!is_valid_ether_addr(netdev->dev_addr))
ethoc_get_mac_address(netdev, netdev->dev_addr);
if (!is_valid_ether_addr(netdev->dev_addr)) {
eth_random_addr(netdev->dev_addr);
random_mac = true;
}
ethoc_do_set_mac_address(netdev);
if (random_mac)
netdev->addr_assign_type = NET_ADDR_RANDOM;
priv->mdio = mdiobus_alloc();
if (!priv->mdio) {
ret = -ENOMEM;
goto free;
}
priv->mdio->name = "ethoc-mdio";
snprintf(priv->mdio->id, MII_BUS_ID_SIZE, "%s-%d",
priv->mdio->name, pdev->id);
priv->mdio->read = ethoc_mdio_read;
priv->mdio->write = ethoc_mdio_write;
priv->mdio->reset = ethoc_mdio_reset;
priv->mdio->priv = priv;
priv->mdio->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!priv->mdio->irq) {
ret = -ENOMEM;
goto free_mdio;
}
for (phy = 0; phy < PHY_MAX_ADDR; phy++)
priv->mdio->irq[phy] = PHY_POLL;
ret = mdiobus_register(priv->mdio);
if (ret) {
dev_err(&netdev->dev, "failed to register MDIO bus\n");
goto free_mdio;
}
ret = ethoc_mdio_probe(netdev);
if (ret) {
dev_err(&netdev->dev, "failed to probe MDIO bus\n");
goto error;
}
ether_setup(netdev);
netdev->netdev_ops = &ethoc_netdev_ops;
netdev->watchdog_timeo = ETHOC_TIMEOUT;
netdev->features |= 0;
netif_napi_add(netdev, &priv->napi, ethoc_poll, 64);
spin_lock_init(&priv->lock);
ret = register_netdev(netdev);
if (ret < 0) {
dev_err(&netdev->dev, "failed to register interface\n");
goto error2;
}
goto out;
error2:
netif_napi_del(&priv->napi);
error:
mdiobus_unregister(priv->mdio);
free_mdio:
kfree(priv->mdio->irq);
mdiobus_free(priv->mdio);
free:
free_netdev(netdev);
out:
return ret;
}
static int ethoc_remove(struct platform_device *pdev)
{
struct net_device *netdev = platform_get_drvdata(pdev);
struct ethoc *priv = netdev_priv(netdev);
if (netdev) {
netif_napi_del(&priv->napi);
phy_disconnect(priv->phy);
priv->phy = NULL;
if (priv->mdio) {
mdiobus_unregister(priv->mdio);
kfree(priv->mdio->irq);
mdiobus_free(priv->mdio);
}
unregister_netdev(netdev);
free_netdev(netdev);
}
return 0;
}
static int ethoc_suspend(struct platform_device *pdev, pm_message_t state)
{
return -ENOSYS;
}
static int ethoc_resume(struct platform_device *pdev)
{
return -ENOSYS;
}
