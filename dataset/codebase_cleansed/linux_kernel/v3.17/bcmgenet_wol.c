void bcmgenet_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg;
wol->supported = WAKE_MAGIC | WAKE_MAGICSECURE;
wol->wolopts = priv->wolopts;
memset(wol->sopass, 0, sizeof(wol->sopass));
if (wol->wolopts & WAKE_MAGICSECURE) {
reg = bcmgenet_umac_readl(priv, UMAC_MPD_PW_MS);
put_unaligned_be16(reg, &wol->sopass[0]);
reg = bcmgenet_umac_readl(priv, UMAC_MPD_PW_LS);
put_unaligned_be32(reg, &wol->sopass[2]);
}
}
int bcmgenet_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
u32 reg;
if (!device_can_wakeup(kdev))
return -ENOTSUPP;
if (wol->wolopts & ~(WAKE_MAGIC | WAKE_MAGICSECURE))
return -EINVAL;
if (wol->wolopts & WAKE_MAGICSECURE) {
bcmgenet_umac_writel(priv, get_unaligned_be16(&wol->sopass[0]),
UMAC_MPD_PW_MS);
bcmgenet_umac_writel(priv, get_unaligned_be32(&wol->sopass[2]),
UMAC_MPD_PW_LS);
reg = bcmgenet_umac_readl(priv, UMAC_MPD_CTRL);
reg |= MPD_PW_EN;
bcmgenet_umac_writel(priv, reg, UMAC_MPD_CTRL);
}
if (wol->wolopts) {
device_set_wakeup_enable(kdev, 1);
enable_irq_wake(priv->wol_irq);
priv->wol_irq_disabled = false;
} else {
device_set_wakeup_enable(kdev, 0);
if (!priv->wol_irq_disabled)
disable_irq_wake(priv->wol_irq);
priv->wol_irq_disabled = true;
}
priv->wolopts = wol->wolopts;
return 0;
}
static int bcmgenet_poll_wol_status(struct bcmgenet_priv *priv)
{
struct net_device *dev = priv->dev;
int retries = 0;
while (!(bcmgenet_rbuf_readl(priv, RBUF_STATUS)
& RBUF_STATUS_WOL)) {
retries++;
if (retries > 5) {
netdev_crit(dev, "polling wol mode timeout\n");
return -ETIMEDOUT;
}
mdelay(1);
}
return retries;
}
int bcmgenet_wol_power_down_cfg(struct bcmgenet_priv *priv,
enum bcmgenet_power_mode mode)
{
struct net_device *dev = priv->dev;
u32 cpu_mask_clear;
int retries = 0;
u32 reg;
if (mode != GENET_POWER_WOL_MAGIC) {
netif_err(priv, wol, dev, "unsupported mode: %d\n", mode);
return -EINVAL;
}
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~CMD_RX_EN;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
mdelay(10);
reg = bcmgenet_umac_readl(priv, UMAC_MPD_CTRL);
reg |= MPD_EN;
bcmgenet_umac_writel(priv, reg, UMAC_MPD_CTRL);
retries = bcmgenet_poll_wol_status(priv);
if (retries < 0) {
reg = bcmgenet_umac_readl(priv, UMAC_MPD_CTRL);
reg &= ~MPD_EN;
bcmgenet_umac_writel(priv, reg, UMAC_MPD_CTRL);
return retries;
}
netif_dbg(priv, wol, dev, "MPD WOL-ready status set after %d msec\n",
retries);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
priv->crc_fwd_en = 1;
reg |= CMD_CRC_FWD;
reg |= CMD_RX_EN;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
if (priv->hw_params->flags & GENET_HAS_EXT) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg &= ~EXT_ENERGY_DET_MASK;
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
}
cpu_mask_clear = UMAC_IRQ_MPD_R;
bcmgenet_intrl2_0_writel(priv, cpu_mask_clear, INTRL2_CPU_MASK_CLEAR);
return 0;
}
void bcmgenet_wol_power_up_cfg(struct bcmgenet_priv *priv,
enum bcmgenet_power_mode mode)
{
u32 cpu_mask_set;
u32 reg;
if (mode != GENET_POWER_WOL_MAGIC) {
netif_err(priv, wol, priv->dev, "invalid mode: %d\n", mode);
return;
}
reg = bcmgenet_umac_readl(priv, UMAC_MPD_CTRL);
reg &= ~MPD_EN;
bcmgenet_umac_writel(priv, reg, UMAC_MPD_CTRL);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~CMD_CRC_FWD;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
priv->crc_fwd_en = 0;
cpu_mask_set = UMAC_IRQ_MPD_R;
bcmgenet_intrl2_0_writel(priv, cpu_mask_set, INTRL2_CPU_MASK_SET);
}
