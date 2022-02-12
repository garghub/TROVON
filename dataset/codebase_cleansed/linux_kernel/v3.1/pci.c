static void ath5k_pci_read_cachesize(struct ath_common *common, int *csz)
{
struct ath5k_hw *ah = (struct ath5k_hw *) common->priv;
u8 u8tmp;
pci_read_config_byte(ah->pdev, PCI_CACHE_LINE_SIZE, &u8tmp);
*csz = (int)u8tmp;
if (*csz == 0)
*csz = L1_CACHE_BYTES >> 2;
}
static bool
ath5k_pci_eeprom_read(struct ath_common *common, u32 offset, u16 *data)
{
struct ath5k_hw *ah = (struct ath5k_hw *) common->ah;
u32 status, timeout;
if (ah->ah_version == AR5K_AR5210) {
AR5K_REG_ENABLE_BITS(ah, AR5K_PCICFG, AR5K_PCICFG_EEAE);
(void)ath5k_hw_reg_read(ah, AR5K_EEPROM_BASE + (4 * offset));
} else {
ath5k_hw_reg_write(ah, offset, AR5K_EEPROM_BASE);
AR5K_REG_ENABLE_BITS(ah, AR5K_EEPROM_CMD,
AR5K_EEPROM_CMD_READ);
}
for (timeout = AR5K_TUNE_REGISTER_TIMEOUT; timeout > 0; timeout--) {
status = ath5k_hw_reg_read(ah, AR5K_EEPROM_STATUS);
if (status & AR5K_EEPROM_STAT_RDDONE) {
if (status & AR5K_EEPROM_STAT_RDERR)
return false;
*data = (u16)(ath5k_hw_reg_read(ah, AR5K_EEPROM_DATA) &
0xffff);
return true;
}
udelay(15);
}
return false;
}
int ath5k_hw_read_srev(struct ath5k_hw *ah)
{
ah->ah_mac_srev = ath5k_hw_reg_read(ah, AR5K_SREV);
return 0;
}
static int ath5k_pci_eeprom_read_mac(struct ath5k_hw *ah, u8 *mac)
{
u8 mac_d[ETH_ALEN] = {};
u32 total, offset;
u16 data;
int octet;
AR5K_EEPROM_READ(0x20, data);
for (offset = 0x1f, octet = 0, total = 0; offset >= 0x1d; offset--) {
AR5K_EEPROM_READ(offset, data);
total += data;
mac_d[octet + 1] = data & 0xff;
mac_d[octet] = data >> 8;
octet += 2;
}
if (!total || total == 3 * 0xffff)
return -EINVAL;
memcpy(mac, mac_d, ETH_ALEN);
return 0;
}
static int __devinit
ath5k_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
void __iomem *mem;
struct ath5k_hw *ah;
struct ieee80211_hw *hw;
int ret;
u8 csz;
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S);
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "can't enable device\n");
goto err;
}
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret) {
dev_err(&pdev->dev, "32-bit DMA not available\n");
goto err_dis;
}
pci_read_config_byte(pdev, PCI_CACHE_LINE_SIZE, &csz);
if (csz == 0) {
csz = L1_CACHE_BYTES >> 2;
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE, csz);
}
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0xa8);
pci_set_master(pdev);
pci_write_config_byte(pdev, 0x41, 0);
ret = pci_request_region(pdev, 0, "ath5k");
if (ret) {
dev_err(&pdev->dev, "cannot reserve PCI memory region\n");
goto err_dis;
}
mem = pci_iomap(pdev, 0, 0);
if (!mem) {
dev_err(&pdev->dev, "cannot remap PCI memory region\n");
ret = -EIO;
goto err_reg;
}
hw = ieee80211_alloc_hw(sizeof(*ah), &ath5k_hw_ops);
if (hw == NULL) {
dev_err(&pdev->dev, "cannot allocate ieee80211_hw\n");
ret = -ENOMEM;
goto err_map;
}
dev_info(&pdev->dev, "registered as '%s'\n", wiphy_name(hw->wiphy));
ah = hw->priv;
ah->hw = hw;
ah->pdev = pdev;
ah->dev = &pdev->dev;
ah->irq = pdev->irq;
ah->devid = id->device;
ah->iobase = mem;
ret = ath5k_init_softc(ah, &ath_pci_bus_ops);
if (ret)
goto err_free;
pci_set_drvdata(pdev, hw);
return 0;
err_free:
ieee80211_free_hw(hw);
err_map:
pci_iounmap(pdev, mem);
err_reg:
pci_release_region(pdev, 0);
err_dis:
pci_disable_device(pdev);
err:
return ret;
}
static void __devexit
ath5k_pci_remove(struct pci_dev *pdev)
{
struct ieee80211_hw *hw = pci_get_drvdata(pdev);
struct ath5k_hw *ah = hw->priv;
ath5k_deinit_softc(ah);
pci_iounmap(pdev, ah->iobase);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
ieee80211_free_hw(hw);
}
static int ath5k_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct ieee80211_hw *hw = pci_get_drvdata(pdev);
struct ath5k_hw *ah = hw->priv;
ath5k_led_off(ah);
return 0;
}
static int ath5k_pci_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct ieee80211_hw *hw = pci_get_drvdata(pdev);
struct ath5k_hw *ah = hw->priv;
pci_write_config_byte(pdev, 0x41, 0);
ath5k_led_enable(ah);
return 0;
}
static int __init
init_ath5k_pci(void)
{
int ret;
ret = pci_register_driver(&ath5k_pci_driver);
if (ret) {
printk(KERN_ERR "ath5k_pci: can't register pci driver\n");
return ret;
}
return 0;
}
static void __exit
exit_ath5k_pci(void)
{
pci_unregister_driver(&ath5k_pci_driver);
}
