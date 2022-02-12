static void ath5k_ahb_read_cachesize(struct ath_common *common, int *csz)
{
*csz = L1_CACHE_BYTES >> 2;
}
static bool
ath5k_ahb_eeprom_read(struct ath_common *common, u32 off, u16 *data)
{
struct ath5k_hw *ah = common->priv;
struct platform_device *pdev = to_platform_device(ah->dev);
struct ar231x_board_config *bcfg = pdev->dev.platform_data;
u16 *eeprom, *eeprom_end;
bcfg = pdev->dev.platform_data;
eeprom = (u16 *) bcfg->radio;
eeprom_end = ((void *) bcfg->config) + BOARD_CONFIG_BUFSZ;
eeprom += off;
if (eeprom > eeprom_end)
return false;
*data = *eeprom;
return true;
}
int ath5k_hw_read_srev(struct ath5k_hw *ah)
{
struct platform_device *pdev = to_platform_device(ah->dev);
struct ar231x_board_config *bcfg = pdev->dev.platform_data;
ah->ah_mac_srev = bcfg->devid;
return 0;
}
static int ath5k_ahb_eeprom_read_mac(struct ath5k_hw *ah, u8 *mac)
{
struct platform_device *pdev = to_platform_device(ah->dev);
struct ar231x_board_config *bcfg = pdev->dev.platform_data;
u8 *cfg_mac;
if (to_platform_device(ah->dev)->id == 0)
cfg_mac = bcfg->config->wlan0_mac;
else
cfg_mac = bcfg->config->wlan1_mac;
memcpy(mac, cfg_mac, ETH_ALEN);
return 0;
}
static int ath_ahb_probe(struct platform_device *pdev)
{
struct ar231x_board_config *bcfg = pdev->dev.platform_data;
struct ath5k_hw *ah;
struct ieee80211_hw *hw;
struct resource *res;
void __iomem *mem;
int irq;
int ret = 0;
u32 reg;
if (!pdev->dev.platform_data) {
dev_err(&pdev->dev, "no platform data specified\n");
ret = -EINVAL;
goto err_out;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no memory resource found\n");
ret = -ENXIO;
goto err_out;
}
mem = ioremap_nocache(res->start, resource_size(res));
if (mem == NULL) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_out;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no IRQ resource found\n");
ret = -ENXIO;
goto err_out;
}
irq = res->start;
hw = ieee80211_alloc_hw(sizeof(struct ath5k_hw), &ath5k_hw_ops);
if (hw == NULL) {
dev_err(&pdev->dev, "no memory for ieee80211_hw\n");
ret = -ENOMEM;
goto err_out;
}
ah = hw->priv;
ah->hw = hw;
ah->dev = &pdev->dev;
ah->iobase = mem;
ah->irq = irq;
ah->devid = bcfg->devid;
if (bcfg->devid >= AR5K_SREV_AR2315_R6) {
reg = __raw_readl((void __iomem *) AR5K_AR2315_AHB_ARB_CTL);
reg |= AR5K_AR2315_AHB_ARB_CTL_WLAN;
__raw_writel(reg, (void __iomem *) AR5K_AR2315_AHB_ARB_CTL);
reg = __raw_readl((void __iomem *) AR5K_AR2315_BYTESWAP);
reg |= AR5K_AR2315_BYTESWAP_WMAC;
__raw_writel(reg, (void __iomem *) AR5K_AR2315_BYTESWAP);
} else {
reg = __raw_readl((void __iomem *) AR5K_AR5312_ENABLE);
if (to_platform_device(ah->dev)->id == 0)
reg |= AR5K_AR5312_ENABLE_WLAN0;
else
reg |= AR5K_AR5312_ENABLE_WLAN1;
__raw_writel(reg, (void __iomem *) AR5K_AR5312_ENABLE);
if (to_platform_device(ah->dev)->id == 0 &&
(bcfg->config->flags & (BD_WLAN0 | BD_WLAN1)) ==
(BD_WLAN1 | BD_WLAN0))
__set_bit(ATH_STAT_2G_DISABLED, ah->status);
}
ret = ath5k_init_softc(ah, &ath_ahb_bus_ops);
if (ret != 0) {
dev_err(&pdev->dev, "failed to attach device, err=%d\n", ret);
ret = -ENODEV;
goto err_free_hw;
}
platform_set_drvdata(pdev, hw);
return 0;
err_free_hw:
ieee80211_free_hw(hw);
platform_set_drvdata(pdev, NULL);
err_out:
return ret;
}
static int ath_ahb_remove(struct platform_device *pdev)
{
struct ar231x_board_config *bcfg = pdev->dev.platform_data;
struct ieee80211_hw *hw = platform_get_drvdata(pdev);
struct ath5k_hw *ah;
u32 reg;
if (!hw)
return 0;
ah = hw->priv;
if (bcfg->devid >= AR5K_SREV_AR2315_R6) {
reg = __raw_readl((void __iomem *) AR5K_AR2315_AHB_ARB_CTL);
reg &= ~AR5K_AR2315_AHB_ARB_CTL_WLAN;
__raw_writel(reg, (void __iomem *) AR5K_AR2315_AHB_ARB_CTL);
} else {
reg = __raw_readl((void __iomem *) AR5K_AR5312_ENABLE);
if (to_platform_device(ah->dev)->id == 0)
reg &= ~AR5K_AR5312_ENABLE_WLAN0;
else
reg &= ~AR5K_AR5312_ENABLE_WLAN1;
__raw_writel(reg, (void __iomem *) AR5K_AR5312_ENABLE);
}
ath5k_deinit_softc(ah);
platform_set_drvdata(pdev, NULL);
ieee80211_free_hw(hw);
return 0;
}
static int __init
ath5k_ahb_init(void)
{
return platform_driver_register(&ath_ahb_driver);
}
static void __exit
ath5k_ahb_exit(void)
{
platform_driver_unregister(&ath_ahb_driver);
}
