static int whack_reset(struct fec __iomem *fecp)
{
int i;
FW(fecp, ecntrl, FEC_ECNTRL_PINMUX | FEC_ECNTRL_RESET);
for (i = 0; i < FEC_RESET_DELAY; i++) {
if ((FR(fecp, ecntrl) & FEC_ECNTRL_RESET) == 0)
return 0;
udelay(1);
}
return -1;
}
static int do_pd_setup(struct fs_enet_private *fep)
{
struct platform_device *ofdev = to_platform_device(fep->dev);
fep->interrupt = irq_of_parse_and_map(ofdev->dev.of_node, 0);
if (fep->interrupt == NO_IRQ)
return -EINVAL;
fep->fec.fecp = of_iomap(ofdev->dev.of_node, 0);
if (!fep->fcc.fccp)
return -EINVAL;
return 0;
}
static int setup_data(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
if (do_pd_setup(fep) != 0)
return -EINVAL;
fep->fec.hthi = 0;
fep->fec.htlo = 0;
fep->ev_napi_rx = FEC_NAPI_RX_EVENT_MSK;
fep->ev_napi_tx = FEC_NAPI_TX_EVENT_MSK;
fep->ev_rx = FEC_RX_EVENT;
fep->ev_tx = FEC_TX_EVENT;
fep->ev_err = FEC_ERR_EVENT_MSK;
return 0;
}
static int allocate_bd(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
const struct fs_platform_info *fpi = fep->fpi;
fep->ring_base = (void __force __iomem *)dma_alloc_coherent(fep->dev,
(fpi->tx_ring + fpi->rx_ring) *
sizeof(cbd_t), &fep->ring_mem_addr,
GFP_KERNEL);
if (fep->ring_base == NULL)
return -ENOMEM;
return 0;
}
static void free_bd(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
const struct fs_platform_info *fpi = fep->fpi;
if(fep->ring_base)
dma_free_coherent(fep->dev, (fpi->tx_ring + fpi->rx_ring)
* sizeof(cbd_t),
(void __force *)fep->ring_base,
fep->ring_mem_addr);
}
static void cleanup_data(struct net_device *dev)
{
}
static void set_promiscuous_mode(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FS(fecp, r_cntrl, FEC_RCNTRL_PROM);
}
static void set_multicast_start(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
fep->fec.hthi = 0;
fep->fec.htlo = 0;
}
static void set_multicast_one(struct net_device *dev, const u8 *mac)
{
struct fs_enet_private *fep = netdev_priv(dev);
int temp, hash_index, i, j;
u32 crc, csrVal;
u8 byte, msb;
crc = 0xffffffff;
for (i = 0; i < 6; i++) {
byte = mac[i];
for (j = 0; j < 8; j++) {
msb = crc >> 31;
crc <<= 1;
if (msb ^ (byte & 0x1))
crc ^= FEC_CRC_POLY;
byte >>= 1;
}
}
temp = (crc & 0x3f) >> 1;
hash_index = ((temp & 0x01) << 4) |
((temp & 0x02) << 2) |
((temp & 0x04)) |
((temp & 0x08) >> 2) |
((temp & 0x10) >> 4);
csrVal = 1 << hash_index;
if (crc & 1)
fep->fec.hthi |= csrVal;
else
fep->fec.htlo |= csrVal;
}
static void set_multicast_finish(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
if ((dev->flags & IFF_ALLMULTI) != 0 ||
netdev_mc_count(dev) > FEC_MAX_MULTICAST_ADDRS) {
fep->fec.hthi = 0xffffffffU;
fep->fec.htlo = 0xffffffffU;
}
FC(fecp, r_cntrl, FEC_RCNTRL_PROM);
FW(fecp, grp_hash_table_high, fep->fec.hthi);
FW(fecp, grp_hash_table_low, fep->fec.htlo);
}
static void set_multicast_list(struct net_device *dev)
{
struct netdev_hw_addr *ha;
if ((dev->flags & IFF_PROMISC) == 0) {
set_multicast_start(dev);
netdev_for_each_mc_addr(ha, dev)
set_multicast_one(dev, ha->addr);
set_multicast_finish(dev);
} else
set_promiscuous_mode(dev);
}
static void restart(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
const struct fs_platform_info *fpi = fep->fpi;
dma_addr_t rx_bd_base_phys, tx_bd_base_phys;
int r;
u32 addrhi, addrlo;
struct mii_bus *mii = dev->phydev->mdio.bus;
struct fec_info* fec_inf = mii->priv;
r = whack_reset(fep->fec.fecp);
if (r != 0)
dev_err(fep->dev, "FEC Reset FAILED!\n");
addrhi = ((u32) dev->dev_addr[0] << 24) |
((u32) dev->dev_addr[1] << 16) |
((u32) dev->dev_addr[2] << 8) |
(u32) dev->dev_addr[3];
addrlo = ((u32) dev->dev_addr[4] << 24) |
((u32) dev->dev_addr[5] << 16);
FW(fecp, addr_low, addrhi);
FW(fecp, addr_high, addrlo);
FW(fecp, grp_hash_table_high, fep->fec.hthi);
FW(fecp, grp_hash_table_low, fep->fec.htlo);
FW(fecp, r_buff_size, PKT_MAXBLR_SIZE);
#ifdef CONFIG_FS_ENET_MPC5121_FEC
FW(fecp, r_cntrl, PKT_MAXBUF_SIZE << 16);
#else
FW(fecp, r_hash, PKT_MAXBUF_SIZE);
#endif
rx_bd_base_phys = fep->ring_mem_addr;
tx_bd_base_phys = rx_bd_base_phys + sizeof(cbd_t) * fpi->rx_ring;
FW(fecp, r_des_start, rx_bd_base_phys);
FW(fecp, x_des_start, tx_bd_base_phys);
fs_init_bds(dev);
#ifdef CONFIG_FS_ENET_MPC5121_FEC
FS(fecp, dma_control, 0xC0000000);
#else
FW(fecp, fun_code, 0x78000000);
#endif
FW(fecp, mii_speed, fec_inf->mii_speed);
FW(fecp, ievent, 0xffc0);
#ifndef CONFIG_FS_ENET_MPC5121_FEC
FW(fecp, ivec, (virq_to_hw(fep->interrupt) / 2) << 29);
FW(fecp, r_cntrl, FEC_RCNTRL_MII_MODE);
#else
FS(fecp, r_cntrl, fpi->use_rmii ?
FEC_RCNTRL_RMII_MODE : FEC_RCNTRL_MII_MODE);
#endif
if (dev->phydev->duplex) {
FC(fecp, r_cntrl, FEC_RCNTRL_DRT);
FS(fecp, x_cntrl, FEC_TCNTRL_FDEN);
} else {
FS(fecp, r_cntrl, FEC_RCNTRL_DRT);
FC(fecp, x_cntrl, FEC_TCNTRL_FDEN);
}
set_multicast_list(dev);
FW(fecp, imask, FEC_ENET_TXF | FEC_ENET_TXB |
FEC_ENET_RXF | FEC_ENET_RXB);
FW(fecp, ecntrl, FEC_ECNTRL_PINMUX | FEC_ECNTRL_ETHER_EN);
FW(fecp, r_des_active, 0x01000000);
}
static void stop(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
const struct fs_platform_info *fpi = fep->fpi;
struct fec __iomem *fecp = fep->fec.fecp;
struct fec_info *feci = dev->phydev->mdio.bus->priv;
int i;
if ((FR(fecp, ecntrl) & FEC_ECNTRL_ETHER_EN) == 0)
return;
FW(fecp, x_cntrl, 0x01);
for (i = 0; ((FR(fecp, ievent) & 0x10000000) == 0) &&
i < FEC_RESET_DELAY; i++)
udelay(1);
if (i == FEC_RESET_DELAY)
dev_warn(fep->dev, "FEC timeout on graceful transmit stop\n");
FW(fecp, imask, 0);
FC(fecp, ecntrl, FEC_ECNTRL_ETHER_EN);
fs_cleanup_bds(dev);
if (fpi->has_phy) {
FS(fecp, r_cntrl, fpi->use_rmii ?
FEC_RCNTRL_RMII_MODE :
FEC_RCNTRL_MII_MODE);
FS(fecp, ecntrl, FEC_ECNTRL_PINMUX | FEC_ECNTRL_ETHER_EN);
FW(fecp, ievent, FEC_ENET_MII);
FW(fecp, mii_speed, feci->mii_speed);
}
}
static void napi_clear_rx_event(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FW(fecp, ievent, FEC_NAPI_RX_EVENT_MSK);
}
static void napi_enable_rx(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FS(fecp, imask, FEC_NAPI_RX_EVENT_MSK);
}
static void napi_disable_rx(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FC(fecp, imask, FEC_NAPI_RX_EVENT_MSK);
}
static void napi_clear_tx_event(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FW(fecp, ievent, FEC_NAPI_TX_EVENT_MSK);
}
static void napi_enable_tx(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FS(fecp, imask, FEC_NAPI_TX_EVENT_MSK);
}
static void napi_disable_tx(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FC(fecp, imask, FEC_NAPI_TX_EVENT_MSK);
}
static void rx_bd_done(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FW(fecp, r_des_active, 0x01000000);
}
static void tx_kickstart(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FW(fecp, x_des_active, 0x01000000);
}
static u32 get_int_events(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
return FR(fecp, ievent) & FR(fecp, imask);
}
static void clear_int_events(struct net_device *dev, u32 int_events)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fec __iomem *fecp = fep->fec.fecp;
FW(fecp, ievent, int_events);
}
static void ev_error(struct net_device *dev, u32 int_events)
{
struct fs_enet_private *fep = netdev_priv(dev);
dev_warn(fep->dev, "FEC ERROR(s) 0x%x\n", int_events);
}
static int get_regs(struct net_device *dev, void *p, int *sizep)
{
struct fs_enet_private *fep = netdev_priv(dev);
if (*sizep < sizeof(struct fec))
return -EINVAL;
memcpy_fromio(p, fep->fec.fecp, sizeof(struct fec));
return 0;
}
static int get_regs_len(struct net_device *dev)
{
return sizeof(struct fec);
}
static void tx_restart(struct net_device *dev)
{
}
