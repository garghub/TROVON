static int sun8i_dwmac_dma_reset(void __iomem *ioaddr)
{
writel(0, ioaddr + EMAC_RX_CTL1);
writel(0, ioaddr + EMAC_TX_CTL1);
writel(0, ioaddr + EMAC_RX_FRM_FLT);
writel(0, ioaddr + EMAC_RX_DESC_LIST);
writel(0, ioaddr + EMAC_TX_DESC_LIST);
writel(0, ioaddr + EMAC_INT_EN);
writel(0x1FFFFFF, ioaddr + EMAC_INT_STA);
return 0;
}
static void sun8i_dwmac_dma_init(void __iomem *ioaddr,
struct stmmac_dma_cfg *dma_cfg,
u32 dma_tx, u32 dma_rx, int atds)
{
writel(dma_rx, ioaddr + EMAC_RX_DESC_LIST);
writel(dma_tx, ioaddr + EMAC_TX_DESC_LIST);
writel(EMAC_RX_INT | EMAC_TX_INT, ioaddr + EMAC_INT_EN);
writel(0x1FFFFFF, ioaddr + EMAC_INT_STA);
}
static void sun8i_dwmac_dump_regs(void __iomem *ioaddr, u32 *reg_space)
{
int i;
for (i = 0; i < 0xC8; i += 4) {
if (i == 0x32 || i == 0x3C)
continue;
reg_space[i / 4] = readl(ioaddr + i);
}
}
static void sun8i_dwmac_dump_mac_regs(struct mac_device_info *hw,
u32 *reg_space)
{
int i;
void __iomem *ioaddr = hw->pcsr;
for (i = 0; i < 0xC8; i += 4) {
if (i == 0x32 || i == 0x3C)
continue;
reg_space[i / 4] = readl(ioaddr + i);
}
}
static void sun8i_dwmac_enable_dma_irq(void __iomem *ioaddr, u32 chan)
{
writel(EMAC_RX_INT | EMAC_TX_INT, ioaddr + EMAC_INT_EN);
}
static void sun8i_dwmac_disable_dma_irq(void __iomem *ioaddr, u32 chan)
{
writel(0, ioaddr + EMAC_INT_EN);
}
static void sun8i_dwmac_dma_start_tx(void __iomem *ioaddr, u32 chan)
{
u32 v;
v = readl(ioaddr + EMAC_TX_CTL1);
v |= EMAC_TX_DMA_START;
v |= EMAC_TX_DMA_EN;
writel(v, ioaddr + EMAC_TX_CTL1);
}
static void sun8i_dwmac_enable_dma_transmission(void __iomem *ioaddr)
{
u32 v;
v = readl(ioaddr + EMAC_TX_CTL1);
v |= EMAC_TX_DMA_START;
v |= EMAC_TX_DMA_EN;
writel(v, ioaddr + EMAC_TX_CTL1);
}
static void sun8i_dwmac_dma_stop_tx(void __iomem *ioaddr, u32 chan)
{
u32 v;
v = readl(ioaddr + EMAC_TX_CTL1);
v &= ~EMAC_TX_DMA_EN;
writel(v, ioaddr + EMAC_TX_CTL1);
}
static void sun8i_dwmac_dma_start_rx(void __iomem *ioaddr, u32 chan)
{
u32 v;
v = readl(ioaddr + EMAC_RX_CTL1);
v |= EMAC_RX_DMA_START;
v |= EMAC_RX_DMA_EN;
writel(v, ioaddr + EMAC_RX_CTL1);
}
static void sun8i_dwmac_dma_stop_rx(void __iomem *ioaddr, u32 chan)
{
u32 v;
v = readl(ioaddr + EMAC_RX_CTL1);
v &= ~EMAC_RX_DMA_EN;
writel(v, ioaddr + EMAC_RX_CTL1);
}
static int sun8i_dwmac_dma_interrupt(void __iomem *ioaddr,
struct stmmac_extra_stats *x, u32 chan)
{
u32 v;
int ret = 0;
v = readl(ioaddr + EMAC_INT_STA);
if (v & EMAC_TX_INT) {
ret |= handle_tx;
x->tx_normal_irq_n++;
}
if (v & EMAC_TX_DMA_STOP_INT)
x->tx_process_stopped_irq++;
if (v & EMAC_TX_BUF_UA_INT)
x->tx_process_stopped_irq++;
if (v & EMAC_TX_TIMEOUT_INT)
ret |= tx_hard_error;
if (v & EMAC_TX_UNDERFLOW_INT) {
ret |= tx_hard_error;
x->tx_undeflow_irq++;
}
if (v & EMAC_TX_EARLY_INT)
x->tx_early_irq++;
if (v & EMAC_RX_INT) {
ret |= handle_rx;
x->rx_normal_irq_n++;
}
if (v & EMAC_RX_BUF_UA_INT)
x->rx_buf_unav_irq++;
if (v & EMAC_RX_DMA_STOP_INT)
x->rx_process_stopped_irq++;
if (v & EMAC_RX_TIMEOUT_INT)
ret |= tx_hard_error;
if (v & EMAC_RX_OVERFLOW_INT) {
ret |= tx_hard_error;
x->rx_overflow_irq++;
}
if (v & EMAC_RX_EARLY_INT)
x->rx_early_irq++;
if (v & EMAC_RGMII_STA_INT)
x->irq_rgmii_n++;
writel(v, ioaddr + EMAC_INT_STA);
return ret;
}
static void sun8i_dwmac_dma_operation_mode(void __iomem *ioaddr, int txmode,
int rxmode, int rxfifosz)
{
u32 v;
v = readl(ioaddr + EMAC_TX_CTL1);
if (txmode == SF_DMA_MODE) {
v |= EMAC_TX_MD;
v |= EMAC_TX_NEXT_FRM;
} else {
v &= ~EMAC_TX_MD;
v &= ~EMAC_TX_TH_MASK;
if (txmode < 64)
v |= EMAC_TX_TH_64;
else if (txmode < 128)
v |= EMAC_TX_TH_128;
else if (txmode < 192)
v |= EMAC_TX_TH_192;
else if (txmode < 256)
v |= EMAC_TX_TH_256;
}
writel(v, ioaddr + EMAC_TX_CTL1);
v = readl(ioaddr + EMAC_RX_CTL1);
if (rxmode == SF_DMA_MODE) {
v |= EMAC_RX_MD;
} else {
v &= ~EMAC_RX_MD;
v &= ~EMAC_RX_TH_MASK;
if (rxmode < 32)
v |= EMAC_RX_TH_32;
else if (rxmode < 64)
v |= EMAC_RX_TH_64;
else if (rxmode < 96)
v |= EMAC_RX_TH_96;
else if (rxmode < 128)
v |= EMAC_RX_TH_128;
}
writel(v, ioaddr + EMAC_RX_CTL1);
}
static int sun8i_dwmac_init(struct platform_device *pdev, void *priv)
{
struct sunxi_priv_data *gmac = priv;
int ret;
if (gmac->regulator) {
ret = regulator_enable(gmac->regulator);
if (ret) {
dev_err(&pdev->dev, "Fail to enable regulator\n");
return ret;
}
}
ret = clk_prepare_enable(gmac->tx_clk);
if (ret) {
if (gmac->regulator)
regulator_disable(gmac->regulator);
dev_err(&pdev->dev, "Could not enable AHB clock\n");
return ret;
}
return 0;
}
static void sun8i_dwmac_core_init(struct mac_device_info *hw, int mtu)
{
void __iomem *ioaddr = hw->pcsr;
u32 v;
v = (8 << EMAC_BURSTLEN_SHIFT);
writel(v, ioaddr + EMAC_BASIC_CTL1);
}
static void sun8i_dwmac_set_mac(void __iomem *ioaddr, bool enable)
{
u32 t, r;
t = readl(ioaddr + EMAC_TX_CTL0);
r = readl(ioaddr + EMAC_RX_CTL0);
if (enable) {
t |= EMAC_TX_TRANSMITTER_EN;
r |= EMAC_RX_RECEIVER_EN;
} else {
t &= ~EMAC_TX_TRANSMITTER_EN;
r &= ~EMAC_RX_RECEIVER_EN;
}
writel(t, ioaddr + EMAC_TX_CTL0);
writel(r, ioaddr + EMAC_RX_CTL0);
}
static void sun8i_dwmac_set_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
u32 v;
if (!addr) {
writel(0, ioaddr + EMAC_MACADDR_HI(reg_n));
return;
}
stmmac_set_mac_addr(ioaddr, addr, EMAC_MACADDR_HI(reg_n),
EMAC_MACADDR_LO(reg_n));
if (reg_n > 0) {
v = readl(ioaddr + EMAC_MACADDR_HI(reg_n));
v |= MAC_ADDR_TYPE_DST;
writel(v, ioaddr + EMAC_MACADDR_HI(reg_n));
}
}
static void sun8i_dwmac_get_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_get_mac_addr(ioaddr, addr, EMAC_MACADDR_HI(reg_n),
EMAC_MACADDR_LO(reg_n));
}
static int sun8i_dwmac_rx_ipc_enable(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
u32 v;
v = readl(ioaddr + EMAC_RX_CTL0);
v |= EMAC_RX_DO_CRC;
writel(v, ioaddr + EMAC_RX_CTL0);
return 1;
}
static void sun8i_dwmac_set_filter(struct mac_device_info *hw,
struct net_device *dev)
{
void __iomem *ioaddr = hw->pcsr;
u32 v;
int i = 1;
struct netdev_hw_addr *ha;
int macaddrs = netdev_uc_count(dev) + netdev_mc_count(dev) + 1;
v = EMAC_FRM_FLT_CTL;
if (dev->flags & IFF_PROMISC) {
v = EMAC_FRM_FLT_RXALL;
} else if (dev->flags & IFF_ALLMULTI) {
v |= EMAC_FRM_FLT_MULTICAST;
} else if (macaddrs <= hw->unicast_filter_entries) {
if (!netdev_mc_empty(dev)) {
netdev_for_each_mc_addr(ha, dev) {
sun8i_dwmac_set_umac_addr(hw, ha->addr, i);
i++;
}
}
if (!netdev_uc_empty(dev)) {
netdev_for_each_uc_addr(ha, dev) {
sun8i_dwmac_set_umac_addr(hw, ha->addr, i);
i++;
}
}
} else {
netdev_info(dev, "Too many address, switching to promiscuous\n");
v = EMAC_FRM_FLT_RXALL;
}
while (i < hw->unicast_filter_entries)
sun8i_dwmac_set_umac_addr(hw, NULL, i++);
writel(v, ioaddr + EMAC_RX_FRM_FLT);
}
static void sun8i_dwmac_flow_ctrl(struct mac_device_info *hw,
unsigned int duplex, unsigned int fc,
unsigned int pause_time, u32 tx_cnt)
{
void __iomem *ioaddr = hw->pcsr;
u32 v;
v = readl(ioaddr + EMAC_RX_CTL0);
if (fc == FLOW_AUTO)
v |= EMAC_RX_FLOW_CTL_EN;
else
v &= ~EMAC_RX_FLOW_CTL_EN;
writel(v, ioaddr + EMAC_RX_CTL0);
v = readl(ioaddr + EMAC_TX_FLOW_CTL);
if (fc == FLOW_AUTO)
v |= EMAC_TX_FLOW_CTL_EN;
else
v &= ~EMAC_TX_FLOW_CTL_EN;
writel(v, ioaddr + EMAC_TX_FLOW_CTL);
}
static int sun8i_dwmac_reset(struct stmmac_priv *priv)
{
u32 v;
int err;
v = readl(priv->ioaddr + EMAC_BASIC_CTL1);
writel(v | 0x01, priv->ioaddr + EMAC_BASIC_CTL1);
err = readl_poll_timeout(priv->ioaddr + EMAC_BASIC_CTL1, v,
!(v & 0x01), 100, 100000);
if (err) {
dev_err(priv->device, "EMAC reset timeout\n");
return -EFAULT;
}
return 0;
}
static int sun8i_dwmac_set_syscon(struct stmmac_priv *priv)
{
struct sunxi_priv_data *gmac = priv->plat->bsp_priv;
struct device_node *node = priv->device->of_node;
int ret;
u32 reg, val;
regmap_read(gmac->regmap, SYSCON_EMAC_REG, &val);
reg = gmac->variant->default_syscon_value;
if (reg != val)
dev_warn(priv->device,
"Current syscon value is not the default %x (expect %x)\n",
val, reg);
if (gmac->variant->internal_phy) {
if (!gmac->use_internal_phy) {
reg &= ~H3_EPHY_SELECT;
} else {
reg |= H3_EPHY_SELECT;
reg &= ~H3_EPHY_SHUTDOWN;
dev_dbg(priv->device, "Select internal_phy %x\n", reg);
if (of_property_read_bool(priv->plat->phy_node,
"allwinner,leds-active-low"))
reg |= H3_EPHY_LED_POL;
else
reg &= ~H3_EPHY_LED_POL;
reg |= H3_EPHY_CLK_SEL;
ret = of_mdio_parse_addr(priv->device,
priv->plat->phy_node);
if (ret < 0) {
dev_err(priv->device, "Could not parse MDIO addr\n");
return ret;
}
reg |= ret << H3_EPHY_ADDR_SHIFT;
}
}
if (!of_property_read_u32(node, "allwinner,tx-delay-ps", &val)) {
if (val % 100) {
dev_err(priv->device, "tx-delay must be a multiple of 100\n");
return -EINVAL;
}
val /= 100;
dev_dbg(priv->device, "set tx-delay to %x\n", val);
if (val <= SYSCON_ETXDC_MASK) {
reg &= ~(SYSCON_ETXDC_MASK << SYSCON_ETXDC_SHIFT);
reg |= (val << SYSCON_ETXDC_SHIFT);
} else {
dev_err(priv->device, "Invalid TX clock delay: %d\n",
val);
return -EINVAL;
}
}
if (!of_property_read_u32(node, "allwinner,rx-delay-ps", &val)) {
if (val % 100) {
dev_err(priv->device, "rx-delay must be a multiple of 100\n");
return -EINVAL;
}
val /= 100;
dev_dbg(priv->device, "set rx-delay to %x\n", val);
if (val <= SYSCON_ERXDC_MASK) {
reg &= ~(SYSCON_ERXDC_MASK << SYSCON_ERXDC_SHIFT);
reg |= (val << SYSCON_ERXDC_SHIFT);
} else {
dev_err(priv->device, "Invalid RX clock delay: %d\n",
val);
return -EINVAL;
}
}
reg &= ~(SYSCON_ETCS_MASK | SYSCON_EPIT);
if (gmac->variant->support_rmii)
reg &= ~SYSCON_RMII_EN;
switch (priv->plat->interface) {
case PHY_INTERFACE_MODE_MII:
break;
case PHY_INTERFACE_MODE_RGMII:
reg |= SYSCON_EPIT | SYSCON_ETCS_INT_GMII;
break;
case PHY_INTERFACE_MODE_RMII:
reg |= SYSCON_RMII_EN | SYSCON_ETCS_EXT_GMII;
break;
default:
dev_err(priv->device, "Unsupported interface mode: %s",
phy_modes(priv->plat->interface));
return -EINVAL;
}
regmap_write(gmac->regmap, SYSCON_EMAC_REG, reg);
return 0;
}
static void sun8i_dwmac_unset_syscon(struct sunxi_priv_data *gmac)
{
u32 reg = gmac->variant->default_syscon_value;
regmap_write(gmac->regmap, SYSCON_EMAC_REG, reg);
}
static int sun8i_dwmac_power_internal_phy(struct stmmac_priv *priv)
{
struct sunxi_priv_data *gmac = priv->plat->bsp_priv;
int ret;
if (!gmac->use_internal_phy)
return 0;
ret = clk_prepare_enable(gmac->ephy_clk);
if (ret) {
dev_err(priv->device, "Cannot enable ephy\n");
return ret;
}
reset_control_assert(gmac->rst_ephy);
ret = reset_control_deassert(gmac->rst_ephy);
if (ret) {
dev_err(priv->device, "Cannot deassert ephy\n");
clk_disable_unprepare(gmac->ephy_clk);
return ret;
}
return 0;
}
static int sun8i_dwmac_unpower_internal_phy(struct sunxi_priv_data *gmac)
{
if (!gmac->use_internal_phy)
return 0;
clk_disable_unprepare(gmac->ephy_clk);
reset_control_assert(gmac->rst_ephy);
return 0;
}
static int sun8i_power_phy(struct stmmac_priv *priv)
{
int ret;
ret = sun8i_dwmac_power_internal_phy(priv);
if (ret)
return ret;
ret = sun8i_dwmac_set_syscon(priv);
if (ret)
return ret;
ret = sun8i_dwmac_reset(priv);
if (ret)
return ret;
return 0;
}
static void sun8i_unpower_phy(struct sunxi_priv_data *gmac)
{
sun8i_dwmac_unset_syscon(gmac);
sun8i_dwmac_unpower_internal_phy(gmac);
}
static void sun8i_dwmac_exit(struct platform_device *pdev, void *priv)
{
struct sunxi_priv_data *gmac = priv;
sun8i_unpower_phy(gmac);
clk_disable_unprepare(gmac->tx_clk);
if (gmac->regulator)
regulator_disable(gmac->regulator);
}
static struct mac_device_info *sun8i_dwmac_setup(void *ppriv)
{
struct mac_device_info *mac;
struct stmmac_priv *priv = ppriv;
int ret;
mac = devm_kzalloc(priv->device, sizeof(*mac), GFP_KERNEL);
if (!mac)
return NULL;
ret = sun8i_power_phy(priv);
if (ret)
return NULL;
mac->pcsr = priv->ioaddr;
mac->mac = &sun8i_dwmac_ops;
mac->dma = &sun8i_dwmac_dma_ops;
mac->link.speed_mask = GENMASK(3, 2) | EMAC_LOOPBACK;
mac->link.speed10 = EMAC_SPEED_10;
mac->link.speed100 = EMAC_SPEED_100;
mac->link.speed1000 = EMAC_SPEED_1000;
mac->link.duplex = EMAC_DUPLEX_FULL;
mac->mii.addr = EMAC_MDIO_CMD;
mac->mii.data = EMAC_MDIO_DATA;
mac->mii.reg_shift = 4;
mac->mii.reg_mask = GENMASK(8, 4);
mac->mii.addr_shift = 12;
mac->mii.addr_mask = GENMASK(16, 12);
mac->mii.clk_csr_shift = 20;
mac->mii.clk_csr_mask = GENMASK(22, 20);
mac->unicast_filter_entries = 8;
priv->synopsys_id = 0;
return mac;
}
static int sun8i_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct sunxi_priv_data *gmac;
struct device *dev = &pdev->dev;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
gmac = devm_kzalloc(dev, sizeof(*gmac), GFP_KERNEL);
if (!gmac)
return -ENOMEM;
gmac->variant = of_device_get_match_data(&pdev->dev);
if (!gmac->variant) {
dev_err(&pdev->dev, "Missing dwmac-sun8i variant\n");
return -EINVAL;
}
gmac->tx_clk = devm_clk_get(dev, "stmmaceth");
if (IS_ERR(gmac->tx_clk)) {
dev_err(dev, "Could not get TX clock\n");
return PTR_ERR(gmac->tx_clk);
}
gmac->regulator = devm_regulator_get_optional(dev, "phy");
if (IS_ERR(gmac->regulator)) {
if (PTR_ERR(gmac->regulator) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "No regulator found\n");
gmac->regulator = NULL;
}
gmac->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"syscon");
if (IS_ERR(gmac->regmap)) {
ret = PTR_ERR(gmac->regmap);
dev_err(&pdev->dev, "Unable to map syscon: %d\n", ret);
return ret;
}
plat_dat->interface = of_get_phy_mode(dev->of_node);
if (plat_dat->interface == gmac->variant->internal_phy) {
dev_info(&pdev->dev, "Will use internal PHY\n");
gmac->use_internal_phy = true;
gmac->ephy_clk = of_clk_get(plat_dat->phy_node, 0);
if (IS_ERR(gmac->ephy_clk)) {
ret = PTR_ERR(gmac->ephy_clk);
dev_err(&pdev->dev, "Cannot get EPHY clock: %d\n", ret);
return -EINVAL;
}
gmac->rst_ephy = of_reset_control_get(plat_dat->phy_node, NULL);
if (IS_ERR(gmac->rst_ephy)) {
ret = PTR_ERR(gmac->rst_ephy);
if (ret == -EPROBE_DEFER)
return ret;
dev_err(&pdev->dev, "No EPHY reset control found %d\n",
ret);
return -EINVAL;
}
} else {
dev_info(&pdev->dev, "Will use external PHY\n");
gmac->use_internal_phy = false;
}
plat_dat->rx_coe = STMMAC_RX_COE_TYPE2;
plat_dat->tx_coe = 1;
plat_dat->has_sun8i = true;
plat_dat->bsp_priv = gmac;
plat_dat->init = sun8i_dwmac_init;
plat_dat->exit = sun8i_dwmac_exit;
plat_dat->setup = sun8i_dwmac_setup;
ret = sun8i_dwmac_init(pdev, plat_dat->bsp_priv);
if (ret)
return ret;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
sun8i_dwmac_exit(pdev, plat_dat->bsp_priv);
return ret;
}
