static phy_interface_t lpc_phy_interface_mode(struct device *dev)
{
if (dev && dev->of_node) {
const char *mode = of_get_property(dev->of_node,
"phy-mode", NULL);
if (mode && !strcmp(mode, "mii"))
return PHY_INTERFACE_MODE_MII;
return PHY_INTERFACE_MODE_RMII;
}
#ifdef CONFIG_ARCH_LPC32XX_MII_SUPPORT
return PHY_INTERFACE_MODE_MII;
#else
return PHY_INTERFACE_MODE_RMII;
#endif
}
static bool use_iram_for_net(struct device *dev)
{
if (dev && dev->of_node)
return of_property_read_bool(dev->of_node, "use-iram");
#ifdef CONFIG_ARCH_LPC32XX_IRAM_FOR_NET
return true;
#else
return false;
#endif
}
static void __lpc_set_mac(struct netdata_local *pldat, u8 *mac)
{
u32 tmp;
tmp = mac[0] | ((u32)mac[1] << 8);
writel(tmp, LPC_ENET_SA2(pldat->net_base));
tmp = mac[2] | ((u32)mac[3] << 8);
writel(tmp, LPC_ENET_SA1(pldat->net_base));
tmp = mac[4] | ((u32)mac[5] << 8);
writel(tmp, LPC_ENET_SA0(pldat->net_base));
netdev_dbg(pldat->ndev, "Ethernet MAC address %pM\n", mac);
}
static void __lpc_get_mac(struct netdata_local *pldat, u8 *mac)
{
u32 tmp;
tmp = readl(LPC_ENET_SA2(pldat->net_base));
mac[0] = tmp & 0xFF;
mac[1] = tmp >> 8;
tmp = readl(LPC_ENET_SA1(pldat->net_base));
mac[2] = tmp & 0xFF;
mac[3] = tmp >> 8;
tmp = readl(LPC_ENET_SA0(pldat->net_base));
mac[4] = tmp & 0xFF;
mac[5] = tmp >> 8;
}
static void __lpc_eth_clock_enable(struct netdata_local *pldat,
bool enable)
{
if (enable)
clk_enable(pldat->clk);
else
clk_disable(pldat->clk);
}
static void __lpc_params_setup(struct netdata_local *pldat)
{
u32 tmp;
if (pldat->duplex == DUPLEX_FULL) {
tmp = readl(LPC_ENET_MAC2(pldat->net_base));
tmp |= LPC_MAC2_FULL_DUPLEX;
writel(tmp, LPC_ENET_MAC2(pldat->net_base));
tmp = readl(LPC_ENET_COMMAND(pldat->net_base));
tmp |= LPC_COMMAND_FULLDUPLEX;
writel(tmp, LPC_ENET_COMMAND(pldat->net_base));
writel(LPC_IPGT_LOAD(0x15), LPC_ENET_IPGT(pldat->net_base));
} else {
tmp = readl(LPC_ENET_MAC2(pldat->net_base));
tmp &= ~LPC_MAC2_FULL_DUPLEX;
writel(tmp, LPC_ENET_MAC2(pldat->net_base));
tmp = readl(LPC_ENET_COMMAND(pldat->net_base));
tmp &= ~LPC_COMMAND_FULLDUPLEX;
writel(tmp, LPC_ENET_COMMAND(pldat->net_base));
writel(LPC_IPGT_LOAD(0x12), LPC_ENET_IPGT(pldat->net_base));
}
if (pldat->speed == SPEED_100)
writel(LPC_SUPP_SPEED, LPC_ENET_SUPP(pldat->net_base));
else
writel(0, LPC_ENET_SUPP(pldat->net_base));
}
static void __lpc_eth_reset(struct netdata_local *pldat)
{
writel((LPC_MAC1_RESET_TX | LPC_MAC1_RESET_MCS_TX | LPC_MAC1_RESET_RX |
LPC_MAC1_RESET_MCS_RX | LPC_MAC1_SIMULATION_RESET |
LPC_MAC1_SOFT_RESET), LPC_ENET_MAC1(pldat->net_base));
writel((LPC_COMMAND_REG_RESET | LPC_COMMAND_TXRESET |
LPC_COMMAND_RXRESET), LPC_ENET_COMMAND(pldat->net_base));
}
static int __lpc_mii_mngt_reset(struct netdata_local *pldat)
{
writel(LPC_MCFG_RESET_MII_MGMT, LPC_ENET_MCFG(pldat->net_base));
writel(LPC_MCFG_CLOCK_SELECT(LPC_MCFG_CLOCK_HOST_DIV_28),
LPC_ENET_MCFG(pldat->net_base));
return 0;
}
static inline phys_addr_t __va_to_pa(void *addr, struct netdata_local *pldat)
{
phys_addr_t phaddr;
phaddr = addr - pldat->dma_buff_base_v;
phaddr += pldat->dma_buff_base_p;
return phaddr;
}
static void lpc_eth_enable_int(void __iomem *regbase)
{
writel((LPC_MACINT_RXDONEINTEN | LPC_MACINT_TXDONEINTEN),
LPC_ENET_INTENABLE(regbase));
}
static void lpc_eth_disable_int(void __iomem *regbase)
{
writel(0, LPC_ENET_INTENABLE(regbase));
}
static void __lpc_txrx_desc_setup(struct netdata_local *pldat)
{
u32 *ptxstat;
void *tbuff;
int i;
struct txrx_desc_t *ptxrxdesc;
struct rx_status_t *prxstat;
tbuff = PTR_ALIGN(pldat->dma_buff_base_v, 16);
pldat->tx_desc_v = tbuff;
tbuff += sizeof(struct txrx_desc_t) * ENET_TX_DESC;
pldat->tx_stat_v = tbuff;
tbuff += sizeof(u32) * ENET_TX_DESC;
tbuff = PTR_ALIGN(tbuff, 16);
pldat->tx_buff_v = tbuff;
tbuff += ENET_MAXF_SIZE * ENET_TX_DESC;
pldat->rx_desc_v = tbuff;
tbuff += sizeof(struct txrx_desc_t) * ENET_RX_DESC;
tbuff = PTR_ALIGN(tbuff, 16);
pldat->rx_stat_v = tbuff;
tbuff += sizeof(struct rx_status_t) * ENET_RX_DESC;
tbuff = PTR_ALIGN(tbuff, 16);
pldat->rx_buff_v = tbuff;
tbuff += ENET_MAXF_SIZE * ENET_RX_DESC;
for (i = 0; i < ENET_TX_DESC; i++) {
ptxstat = &pldat->tx_stat_v[i];
ptxrxdesc = &pldat->tx_desc_v[i];
ptxrxdesc->packet = __va_to_pa(
pldat->tx_buff_v + i * ENET_MAXF_SIZE, pldat);
ptxrxdesc->control = 0;
*ptxstat = 0;
}
for (i = 0; i < ENET_RX_DESC; i++) {
prxstat = &pldat->rx_stat_v[i];
ptxrxdesc = &pldat->rx_desc_v[i];
ptxrxdesc->packet = __va_to_pa(
pldat->rx_buff_v + i * ENET_MAXF_SIZE, pldat);
ptxrxdesc->control = RXDESC_CONTROL_INT | (ENET_MAXF_SIZE - 1);
prxstat->statusinfo = 0;
prxstat->statushashcrc = 0;
}
writel((ENET_TX_DESC - 1),
LPC_ENET_TXDESCRIPTORNUMBER(pldat->net_base));
writel(__va_to_pa(pldat->tx_desc_v, pldat),
LPC_ENET_TXDESCRIPTOR(pldat->net_base));
writel(__va_to_pa(pldat->tx_stat_v, pldat),
LPC_ENET_TXSTATUS(pldat->net_base));
writel((ENET_RX_DESC - 1),
LPC_ENET_RXDESCRIPTORNUMBER(pldat->net_base));
writel(__va_to_pa(pldat->rx_desc_v, pldat),
LPC_ENET_RXDESCRIPTOR(pldat->net_base));
writel(__va_to_pa(pldat->rx_stat_v, pldat),
LPC_ENET_RXSTATUS(pldat->net_base));
}
static void __lpc_eth_init(struct netdata_local *pldat)
{
u32 tmp;
tmp = readl(LPC_ENET_COMMAND(pldat->net_base));
tmp &= ~LPC_COMMAND_RXENABLE | LPC_COMMAND_TXENABLE;
writel(tmp, LPC_ENET_COMMAND(pldat->net_base));
tmp = readl(LPC_ENET_MAC1(pldat->net_base));
tmp &= ~LPC_MAC1_RECV_ENABLE;
writel(tmp, LPC_ENET_MAC1(pldat->net_base));
writel(LPC_MAC1_PASS_ALL_RX_FRAMES, LPC_ENET_MAC1(pldat->net_base));
writel((LPC_MAC2_PAD_CRC_ENABLE | LPC_MAC2_CRC_ENABLE),
LPC_ENET_MAC2(pldat->net_base));
writel(ENET_MAXF_SIZE, LPC_ENET_MAXF(pldat->net_base));
writel((LPC_CLRT_LOAD_RETRY_MAX(0xF) |
LPC_CLRT_LOAD_COLLISION_WINDOW(0x37)),
LPC_ENET_CLRT(pldat->net_base));
writel(LPC_IPGR_LOAD_PART2(0x12), LPC_ENET_IPGR(pldat->net_base));
if (lpc_phy_interface_mode(&pldat->pdev->dev) == PHY_INTERFACE_MODE_MII)
writel(LPC_COMMAND_PASSRUNTFRAME,
LPC_ENET_COMMAND(pldat->net_base));
else {
writel((LPC_COMMAND_PASSRUNTFRAME | LPC_COMMAND_RMII),
LPC_ENET_COMMAND(pldat->net_base));
writel(LPC_SUPP_RESET_RMII, LPC_ENET_SUPP(pldat->net_base));
}
__lpc_params_setup(pldat);
__lpc_txrx_desc_setup(pldat);
writel((LPC_RXFLTRW_ACCEPTUBROADCAST | LPC_RXFLTRW_ACCEPTPERFECT),
LPC_ENET_RXFILTER_CTRL(pldat->net_base));
pldat->num_used_tx_buffs = 0;
pldat->last_tx_idx =
readl(LPC_ENET_TXCONSUMEINDEX(pldat->net_base));
writel(0xFFFF, LPC_ENET_INTCLEAR(pldat->net_base));
smp_wmb();
lpc_eth_enable_int(pldat->net_base);
tmp = readl(LPC_ENET_COMMAND(pldat->net_base));
tmp |= LPC_COMMAND_RXENABLE | LPC_COMMAND_TXENABLE;
writel(tmp, LPC_ENET_COMMAND(pldat->net_base));
tmp = readl(LPC_ENET_MAC1(pldat->net_base));
tmp |= LPC_MAC1_RECV_ENABLE;
writel(tmp, LPC_ENET_MAC1(pldat->net_base));
}
static void __lpc_eth_shutdown(struct netdata_local *pldat)
{
__lpc_eth_reset(pldat);
writel(0, LPC_ENET_MAC1(pldat->net_base));
writel(0, LPC_ENET_MAC2(pldat->net_base));
}
static int lpc_mdio_read(struct mii_bus *bus, int phy_id, int phyreg)
{
struct netdata_local *pldat = bus->priv;
unsigned long timeout = jiffies + msecs_to_jiffies(100);
int lps;
writel(((phy_id << 8) | phyreg), LPC_ENET_MADR(pldat->net_base));
writel(LPC_MCMD_READ, LPC_ENET_MCMD(pldat->net_base));
while (readl(LPC_ENET_MIND(pldat->net_base)) & LPC_MIND_BUSY) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
lps = readl(LPC_ENET_MRDD(pldat->net_base));
writel(0, LPC_ENET_MCMD(pldat->net_base));
return lps;
}
static int lpc_mdio_write(struct mii_bus *bus, int phy_id, int phyreg,
u16 phydata)
{
struct netdata_local *pldat = bus->priv;
unsigned long timeout = jiffies + msecs_to_jiffies(100);
writel(((phy_id << 8) | phyreg), LPC_ENET_MADR(pldat->net_base));
writel(phydata, LPC_ENET_MWTD(pldat->net_base));
while (readl(LPC_ENET_MIND(pldat->net_base)) & LPC_MIND_BUSY) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
return 0;
}
static int lpc_mdio_reset(struct mii_bus *bus)
{
return __lpc_mii_mngt_reset((struct netdata_local *)bus->priv);
}
static void lpc_handle_link_change(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct phy_device *phydev = pldat->phy_dev;
unsigned long flags;
bool status_change = false;
spin_lock_irqsave(&pldat->lock, flags);
if (phydev->link) {
if ((pldat->speed != phydev->speed) ||
(pldat->duplex != phydev->duplex)) {
pldat->speed = phydev->speed;
pldat->duplex = phydev->duplex;
status_change = true;
}
}
if (phydev->link != pldat->link) {
if (!phydev->link) {
pldat->speed = 0;
pldat->duplex = -1;
}
pldat->link = phydev->link;
status_change = true;
}
spin_unlock_irqrestore(&pldat->lock, flags);
if (status_change)
__lpc_params_setup(pldat);
}
static int lpc_mii_probe(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct phy_device *phydev = phy_find_first(pldat->mii_bus);
if (!phydev) {
netdev_err(ndev, "no PHY found\n");
return -ENODEV;
}
if (lpc_phy_interface_mode(&pldat->pdev->dev) == PHY_INTERFACE_MODE_MII)
netdev_info(ndev, "using MII interface\n");
else
netdev_info(ndev, "using RMII interface\n");
phydev = phy_connect(ndev, dev_name(&phydev->dev),
&lpc_handle_link_change, 0,
lpc_phy_interface_mode(&pldat->pdev->dev));
if (IS_ERR(phydev)) {
netdev_err(ndev, "Could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= PHY_BASIC_FEATURES;
phydev->advertising = phydev->supported;
pldat->link = 0;
pldat->speed = 0;
pldat->duplex = -1;
pldat->phy_dev = phydev;
netdev_info(ndev,
"attached PHY driver [%s] (mii_bus:phy_addr=%s, irq=%d)\n",
phydev->drv->name, dev_name(&phydev->dev), phydev->irq);
return 0;
}
static int lpc_mii_init(struct netdata_local *pldat)
{
int err = -ENXIO, i;
pldat->mii_bus = mdiobus_alloc();
if (!pldat->mii_bus) {
err = -ENOMEM;
goto err_out;
}
if (lpc_phy_interface_mode(&pldat->pdev->dev) == PHY_INTERFACE_MODE_MII)
writel(LPC_COMMAND_PASSRUNTFRAME,
LPC_ENET_COMMAND(pldat->net_base));
else {
writel((LPC_COMMAND_PASSRUNTFRAME | LPC_COMMAND_RMII),
LPC_ENET_COMMAND(pldat->net_base));
writel(LPC_SUPP_RESET_RMII, LPC_ENET_SUPP(pldat->net_base));
}
pldat->mii_bus->name = "lpc_mii_bus";
pldat->mii_bus->read = &lpc_mdio_read;
pldat->mii_bus->write = &lpc_mdio_write;
pldat->mii_bus->reset = &lpc_mdio_reset;
snprintf(pldat->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pldat->pdev->name, pldat->pdev->id);
pldat->mii_bus->priv = pldat;
pldat->mii_bus->parent = &pldat->pdev->dev;
pldat->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!pldat->mii_bus->irq) {
err = -ENOMEM;
goto err_out_1;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
pldat->mii_bus->irq[i] = PHY_POLL;
platform_set_drvdata(pldat->pdev, pldat->mii_bus);
if (mdiobus_register(pldat->mii_bus))
goto err_out_free_mdio_irq;
if (lpc_mii_probe(pldat->ndev) != 0)
goto err_out_unregister_bus;
return 0;
err_out_unregister_bus:
mdiobus_unregister(pldat->mii_bus);
err_out_free_mdio_irq:
kfree(pldat->mii_bus->irq);
err_out_1:
mdiobus_free(pldat->mii_bus);
err_out:
return err;
}
static void __lpc_handle_xmit(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct sk_buff *skb;
u32 txcidx, *ptxstat, txstat;
txcidx = readl(LPC_ENET_TXCONSUMEINDEX(pldat->net_base));
while (pldat->last_tx_idx != txcidx) {
skb = pldat->skb[pldat->last_tx_idx];
ptxstat = &pldat->tx_stat_v[pldat->last_tx_idx];
txstat = *ptxstat;
pldat->num_used_tx_buffs--;
pldat->last_tx_idx++;
if (pldat->last_tx_idx >= ENET_TX_DESC)
pldat->last_tx_idx = 0;
ndev->stats.collisions += TXSTATUS_COLLISIONS_GET(txstat);
if (txstat & TXSTATUS_ERROR) {
if (txstat & TXSTATUS_UNDERRUN) {
ndev->stats.tx_fifo_errors++;
}
if (txstat & TXSTATUS_LATECOLL) {
ndev->stats.tx_aborted_errors++;
}
if (txstat & TXSTATUS_EXCESSCOLL) {
ndev->stats.tx_aborted_errors++;
}
if (txstat & TXSTATUS_EXCESSDEFER) {
ndev->stats.tx_aborted_errors++;
}
ndev->stats.tx_errors++;
} else {
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += skb->len;
}
dev_kfree_skb_irq(skb);
txcidx = readl(LPC_ENET_TXCONSUMEINDEX(pldat->net_base));
}
if (pldat->num_used_tx_buffs <= ENET_TX_DESC/2) {
if (netif_queue_stopped(ndev))
netif_wake_queue(ndev);
}
}
static int __lpc_handle_recv(struct net_device *ndev, int budget)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct sk_buff *skb;
u32 rxconsidx, len, ethst;
struct rx_status_t *prxstat;
u8 *prdbuf;
int rx_done = 0;
rxconsidx = readl(LPC_ENET_RXCONSUMEINDEX(pldat->net_base));
while (rx_done < budget && rxconsidx !=
readl(LPC_ENET_RXPRODUCEINDEX(pldat->net_base))) {
prxstat = &pldat->rx_stat_v[rxconsidx];
len = (prxstat->statusinfo & RXSTATUS_SIZE) + 1;
ethst = prxstat->statusinfo;
if ((ethst & (RXSTATUS_ERROR | RXSTATUS_STATUS_ERROR)) ==
(RXSTATUS_ERROR | RXSTATUS_RANGE))
ethst &= ~RXSTATUS_ERROR;
if (ethst & RXSTATUS_ERROR) {
int si = prxstat->statusinfo;
if (si & RXSTATUS_OVERRUN) {
ndev->stats.rx_fifo_errors++;
} else if (si & RXSTATUS_CRC) {
ndev->stats.rx_crc_errors++;
} else if (si & RXSTATUS_LENGTH) {
ndev->stats.rx_length_errors++;
} else if (si & RXSTATUS_ERROR) {
ndev->stats.rx_length_errors++;
}
ndev->stats.rx_errors++;
} else {
skb = dev_alloc_skb(len);
if (!skb) {
ndev->stats.rx_dropped++;
} else {
prdbuf = skb_put(skb, len);
memcpy(prdbuf, pldat->rx_buff_v +
rxconsidx * ENET_MAXF_SIZE, len);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += len;
}
}
rxconsidx = rxconsidx + 1;
if (rxconsidx >= ENET_RX_DESC)
rxconsidx = 0;
writel(rxconsidx,
LPC_ENET_RXCONSUMEINDEX(pldat->net_base));
rx_done++;
}
return rx_done;
}
static int lpc_eth_poll(struct napi_struct *napi, int budget)
{
struct netdata_local *pldat = container_of(napi,
struct netdata_local, napi);
struct net_device *ndev = pldat->ndev;
int rx_done = 0;
struct netdev_queue *txq = netdev_get_tx_queue(ndev, 0);
__netif_tx_lock(txq, smp_processor_id());
__lpc_handle_xmit(ndev);
__netif_tx_unlock(txq);
rx_done = __lpc_handle_recv(ndev, budget);
if (rx_done < budget) {
napi_complete(napi);
lpc_eth_enable_int(pldat->net_base);
}
return rx_done;
}
static irqreturn_t __lpc_eth_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct netdata_local *pldat = netdev_priv(ndev);
u32 tmp;
spin_lock(&pldat->lock);
tmp = readl(LPC_ENET_INTSTATUS(pldat->net_base));
writel(tmp, LPC_ENET_INTCLEAR(pldat->net_base));
lpc_eth_disable_int(pldat->net_base);
if (likely(napi_schedule_prep(&pldat->napi)))
__napi_schedule(&pldat->napi);
spin_unlock(&pldat->lock);
return IRQ_HANDLED;
}
static int lpc_eth_close(struct net_device *ndev)
{
unsigned long flags;
struct netdata_local *pldat = netdev_priv(ndev);
if (netif_msg_ifdown(pldat))
dev_dbg(&pldat->pdev->dev, "shutting down %s\n", ndev->name);
napi_disable(&pldat->napi);
netif_stop_queue(ndev);
if (pldat->phy_dev)
phy_stop(pldat->phy_dev);
spin_lock_irqsave(&pldat->lock, flags);
__lpc_eth_reset(pldat);
netif_carrier_off(ndev);
writel(0, LPC_ENET_MAC1(pldat->net_base));
writel(0, LPC_ENET_MAC2(pldat->net_base));
spin_unlock_irqrestore(&pldat->lock, flags);
__lpc_eth_clock_enable(pldat, false);
return 0;
}
static int lpc_eth_hard_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
u32 len, txidx;
u32 *ptxstat;
struct txrx_desc_t *ptxrxdesc;
len = skb->len;
spin_lock_irq(&pldat->lock);
if (pldat->num_used_tx_buffs >= (ENET_TX_DESC - 1)) {
netif_stop_queue(ndev);
spin_unlock_irq(&pldat->lock);
WARN(1, "BUG! TX request when no free TX buffers!\n");
return NETDEV_TX_BUSY;
}
txidx = readl(LPC_ENET_TXPRODUCEINDEX(pldat->net_base));
ptxstat = &pldat->tx_stat_v[txidx];
*ptxstat = 0;
ptxrxdesc = &pldat->tx_desc_v[txidx];
ptxrxdesc->control =
(len - 1) | TXDESC_CONTROL_LAST | TXDESC_CONTROL_INT;
memcpy(pldat->tx_buff_v + txidx * ENET_MAXF_SIZE, skb->data, len);
pldat->skb[txidx] = skb;
pldat->num_used_tx_buffs++;
txidx++;
if (txidx >= ENET_TX_DESC)
txidx = 0;
writel(txidx, LPC_ENET_TXPRODUCEINDEX(pldat->net_base));
if (pldat->num_used_tx_buffs >= (ENET_TX_DESC - 1))
netif_stop_queue(ndev);
spin_unlock_irq(&pldat->lock);
return NETDEV_TX_OK;
}
static int lpc_set_mac_address(struct net_device *ndev, void *p)
{
struct sockaddr *addr = p;
struct netdata_local *pldat = netdev_priv(ndev);
unsigned long flags;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ETH_ALEN);
spin_lock_irqsave(&pldat->lock, flags);
__lpc_set_mac(pldat, ndev->dev_addr);
spin_unlock_irqrestore(&pldat->lock, flags);
return 0;
}
static void lpc_eth_set_multicast_list(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct netdev_hw_addr_list *mcptr = &ndev->mc;
struct netdev_hw_addr *ha;
u32 tmp32, hash_val, hashlo, hashhi;
unsigned long flags;
spin_lock_irqsave(&pldat->lock, flags);
__lpc_set_mac(pldat, ndev->dev_addr);
tmp32 = LPC_RXFLTRW_ACCEPTUBROADCAST | LPC_RXFLTRW_ACCEPTPERFECT;
if (ndev->flags & IFF_PROMISC)
tmp32 |= LPC_RXFLTRW_ACCEPTUNICAST |
LPC_RXFLTRW_ACCEPTUMULTICAST;
if (ndev->flags & IFF_ALLMULTI)
tmp32 |= LPC_RXFLTRW_ACCEPTUMULTICAST;
if (netdev_hw_addr_list_count(mcptr))
tmp32 |= LPC_RXFLTRW_ACCEPTUMULTICASTHASH;
writel(tmp32, LPC_ENET_RXFILTER_CTRL(pldat->net_base));
hashlo = 0x0;
hashhi = 0x0;
netdev_hw_addr_list_for_each(ha, mcptr) {
hash_val = (ether_crc(6, ha->addr) >> 23) & 0x3F;
if (hash_val >= 32)
hashhi |= 1 << (hash_val - 32);
else
hashlo |= 1 << hash_val;
}
writel(hashlo, LPC_ENET_HASHFILTERL(pldat->net_base));
writel(hashhi, LPC_ENET_HASHFILTERH(pldat->net_base));
spin_unlock_irqrestore(&pldat->lock, flags);
}
static int lpc_eth_ioctl(struct net_device *ndev, struct ifreq *req, int cmd)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct phy_device *phydev = pldat->phy_dev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
return phy_mii_ioctl(phydev, req, cmd);
}
static int lpc_eth_open(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
if (netif_msg_ifup(pldat))
dev_dbg(&pldat->pdev->dev, "enabling %s\n", ndev->name);
if (!is_valid_ether_addr(ndev->dev_addr))
return -EADDRNOTAVAIL;
__lpc_eth_clock_enable(pldat, true);
__lpc_eth_reset(pldat);
__lpc_eth_init(pldat);
phy_start(pldat->phy_dev);
netif_start_queue(ndev);
napi_enable(&pldat->napi);
return 0;
}
static void lpc_eth_ethtool_getdrvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, MODNAME);
strcpy(info->version, DRV_VERSION);
strcpy(info->bus_info, dev_name(ndev->dev.parent));
}
static u32 lpc_eth_ethtool_getmsglevel(struct net_device *ndev)
{
struct netdata_local *pldat = netdev_priv(ndev);
return pldat->msg_enable;
}
static void lpc_eth_ethtool_setmsglevel(struct net_device *ndev, u32 level)
{
struct netdata_local *pldat = netdev_priv(ndev);
pldat->msg_enable = level;
}
static int lpc_eth_ethtool_getsettings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct phy_device *phydev = pldat->phy_dev;
if (!phydev)
return -EOPNOTSUPP;
return phy_ethtool_gset(phydev, cmd);
}
static int lpc_eth_ethtool_setsettings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct netdata_local *pldat = netdev_priv(ndev);
struct phy_device *phydev = pldat->phy_dev;
if (!phydev)
return -EOPNOTSUPP;
return phy_ethtool_sset(phydev, cmd);
}
static int lpc_eth_drv_probe(struct platform_device *pdev)
{
struct resource *res;
struct net_device *ndev;
struct netdata_local *pldat;
struct phy_device *phydev;
dma_addr_t dma_handle;
int irq, ret;
u32 tmp;
tmp = __raw_readl(LPC32XX_CLKPWR_MACCLK_CTRL);
tmp &= ~LPC32XX_CLKPWR_MACCTRL_PINS_MSK;
if (lpc_phy_interface_mode(&pdev->dev) == PHY_INTERFACE_MODE_MII)
tmp |= LPC32XX_CLKPWR_MACCTRL_USE_MII_PINS;
else
tmp |= LPC32XX_CLKPWR_MACCTRL_USE_RMII_PINS;
__raw_writel(tmp, LPC32XX_CLKPWR_MACCLK_CTRL);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if ((!res) || (irq < 0) || (irq >= NR_IRQS)) {
dev_err(&pdev->dev, "error getting resources.\n");
ret = -ENXIO;
goto err_exit;
}
ndev = alloc_etherdev(sizeof(struct netdata_local));
if (!ndev) {
dev_err(&pdev->dev, "could not allocate device.\n");
ret = -ENOMEM;
goto err_exit;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
pldat = netdev_priv(ndev);
pldat->pdev = pdev;
pldat->ndev = ndev;
spin_lock_init(&pldat->lock);
ndev->irq = irq;
pldat->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(pldat->clk)) {
dev_err(&pdev->dev, "error getting clock.\n");
ret = PTR_ERR(pldat->clk);
goto err_out_free_dev;
}
__lpc_eth_clock_enable(pldat, true);
pldat->net_base = ioremap(res->start, res->end - res->start + 1);
if (!pldat->net_base) {
dev_err(&pdev->dev, "failed to map registers\n");
ret = -ENOMEM;
goto err_out_disable_clocks;
}
ret = request_irq(ndev->irq, __lpc_eth_interrupt, 0,
ndev->name, ndev);
if (ret) {
dev_err(&pdev->dev, "error requesting interrupt.\n");
goto err_out_iounmap;
}
ether_setup(ndev);
ndev->netdev_ops = &lpc_netdev_ops;
ndev->ethtool_ops = &lpc_eth_ethtool_ops;
ndev->watchdog_timeo = msecs_to_jiffies(2500);
pldat->dma_buff_size = (ENET_TX_DESC + ENET_RX_DESC) * (ENET_MAXF_SIZE +
sizeof(struct txrx_desc_t) + sizeof(struct rx_status_t));
pldat->dma_buff_base_v = 0;
if (use_iram_for_net(&pldat->pdev->dev)) {
dma_handle = LPC32XX_IRAM_BASE;
if (pldat->dma_buff_size <= lpc32xx_return_iram_size())
pldat->dma_buff_base_v =
io_p2v(LPC32XX_IRAM_BASE);
else
netdev_err(ndev,
"IRAM not big enough for net buffers, using SDRAM instead.\n");
}
if (pldat->dma_buff_base_v == 0) {
pldat->pdev->dev.coherent_dma_mask = 0xFFFFFFFF;
pldat->pdev->dev.dma_mask = &pldat->pdev->dev.coherent_dma_mask;
pldat->dma_buff_size = PAGE_ALIGN(pldat->dma_buff_size);
pldat->dma_buff_base_v =
dma_alloc_coherent(&pldat->pdev->dev,
pldat->dma_buff_size, &dma_handle,
GFP_KERNEL);
if (pldat->dma_buff_base_v == NULL) {
dev_err(&pdev->dev, "error getting DMA region.\n");
ret = -ENOMEM;
goto err_out_free_irq;
}
}
pldat->dma_buff_base_p = dma_handle;
netdev_dbg(ndev, "IO address start :0x%08x\n",
res->start);
netdev_dbg(ndev, "IO address size :%d\n",
res->end - res->start + 1);
netdev_err(ndev, "IO address (mapped) :0x%p\n",
pldat->net_base);
netdev_dbg(ndev, "IRQ number :%d\n", ndev->irq);
netdev_dbg(ndev, "DMA buffer size :%d\n", pldat->dma_buff_size);
netdev_dbg(ndev, "DMA buffer P address :0x%08x\n",
pldat->dma_buff_base_p);
netdev_dbg(ndev, "DMA buffer V address :0x%p\n",
pldat->dma_buff_base_v);
__lpc_get_mac(pldat, ndev->dev_addr);
#ifdef CONFIG_OF_NET
if (!is_valid_ether_addr(ndev->dev_addr)) {
const char *macaddr = of_get_mac_address(pdev->dev.of_node);
if (macaddr)
memcpy(ndev->dev_addr, macaddr, ETH_ALEN);
}
#endif
if (!is_valid_ether_addr(ndev->dev_addr))
eth_hw_addr_random(ndev);
__lpc_eth_reset(pldat);
__lpc_eth_shutdown(pldat);
pldat->msg_enable = NETIF_MSG_LINK;
__lpc_mii_mngt_reset(pldat);
pldat->link = 0;
pldat->speed = 100;
pldat->duplex = DUPLEX_FULL;
__lpc_params_setup(pldat);
netif_napi_add(ndev, &pldat->napi, lpc_eth_poll, NAPI_WEIGHT);
ret = register_netdev(ndev);
if (ret) {
dev_err(&pdev->dev, "Cannot register net device, aborting.\n");
goto err_out_dma_unmap;
}
platform_set_drvdata(pdev, ndev);
if (lpc_mii_init(pldat) != 0)
goto err_out_unregister_netdev;
netdev_info(ndev, "LPC mac at 0x%08x irq %d\n",
res->start, ndev->irq);
phydev = pldat->phy_dev;
device_init_wakeup(&pdev->dev, 1);
device_set_wakeup_enable(&pdev->dev, 0);
return 0;
err_out_unregister_netdev:
platform_set_drvdata(pdev, NULL);
unregister_netdev(ndev);
err_out_dma_unmap:
if (!use_iram_for_net(&pldat->pdev->dev) ||
pldat->dma_buff_size > lpc32xx_return_iram_size())
dma_free_coherent(&pldat->pdev->dev, pldat->dma_buff_size,
pldat->dma_buff_base_v,
pldat->dma_buff_base_p);
err_out_free_irq:
free_irq(ndev->irq, ndev);
err_out_iounmap:
iounmap(pldat->net_base);
err_out_disable_clocks:
clk_disable(pldat->clk);
clk_put(pldat->clk);
err_out_free_dev:
free_netdev(ndev);
err_exit:
pr_err("%s: not found (%d).\n", MODNAME, ret);
return ret;
}
static int lpc_eth_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct netdata_local *pldat = netdev_priv(ndev);
unregister_netdev(ndev);
platform_set_drvdata(pdev, NULL);
if (!use_iram_for_net(&pldat->pdev->dev) ||
pldat->dma_buff_size > lpc32xx_return_iram_size())
dma_free_coherent(&pldat->pdev->dev, pldat->dma_buff_size,
pldat->dma_buff_base_v,
pldat->dma_buff_base_p);
free_irq(ndev->irq, ndev);
iounmap(pldat->net_base);
mdiobus_free(pldat->mii_bus);
clk_disable(pldat->clk);
clk_put(pldat->clk);
free_netdev(ndev);
return 0;
}
static int lpc_eth_drv_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct netdata_local *pldat = netdev_priv(ndev);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(ndev->irq);
if (ndev) {
if (netif_running(ndev)) {
netif_device_detach(ndev);
__lpc_eth_shutdown(pldat);
clk_disable(pldat->clk);
__lpc_eth_reset(pldat);
}
}
return 0;
}
static int lpc_eth_drv_resume(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct netdata_local *pldat;
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(ndev->irq);
if (ndev) {
if (netif_running(ndev)) {
pldat = netdev_priv(ndev);
clk_enable(pldat->clk);
__lpc_eth_reset(pldat);
__lpc_eth_init(pldat);
netif_device_attach(ndev);
}
}
return 0;
}
