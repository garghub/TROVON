static void rt2x00pci_free_reg(struct rt2x00_dev *rt2x00dev)
{
kfree(rt2x00dev->rf);
rt2x00dev->rf = NULL;
kfree(rt2x00dev->eeprom);
rt2x00dev->eeprom = NULL;
if (rt2x00dev->csr.base) {
iounmap(rt2x00dev->csr.base);
rt2x00dev->csr.base = NULL;
}
}
static int rt2x00pci_alloc_reg(struct rt2x00_dev *rt2x00dev)
{
struct pci_dev *pci_dev = to_pci_dev(rt2x00dev->dev);
rt2x00dev->csr.base = pci_ioremap_bar(pci_dev, 0);
if (!rt2x00dev->csr.base)
goto exit;
rt2x00dev->eeprom = kzalloc(rt2x00dev->ops->eeprom_size, GFP_KERNEL);
if (!rt2x00dev->eeprom)
goto exit;
rt2x00dev->rf = kzalloc(rt2x00dev->ops->rf_size, GFP_KERNEL);
if (!rt2x00dev->rf)
goto exit;
return 0;
exit:
rt2x00_probe_err("Failed to allocate registers\n");
rt2x00pci_free_reg(rt2x00dev);
return -ENOMEM;
}
int rt2x00pci_probe(struct pci_dev *pci_dev, const struct rt2x00_ops *ops)
{
struct ieee80211_hw *hw;
struct rt2x00_dev *rt2x00dev;
int retval;
u16 chip;
retval = pci_enable_device(pci_dev);
if (retval) {
rt2x00_probe_err("Enable device failed\n");
return retval;
}
retval = pci_request_regions(pci_dev, pci_name(pci_dev));
if (retval) {
rt2x00_probe_err("PCI request regions failed\n");
goto exit_disable_device;
}
pci_set_master(pci_dev);
if (pci_set_mwi(pci_dev))
rt2x00_probe_err("MWI not available\n");
if (dma_set_mask(&pci_dev->dev, DMA_BIT_MASK(32))) {
rt2x00_probe_err("PCI DMA not supported\n");
retval = -EIO;
goto exit_release_regions;
}
hw = ieee80211_alloc_hw(sizeof(struct rt2x00_dev), ops->hw);
if (!hw) {
rt2x00_probe_err("Failed to allocate hardware\n");
retval = -ENOMEM;
goto exit_release_regions;
}
pci_set_drvdata(pci_dev, hw);
rt2x00dev = hw->priv;
rt2x00dev->dev = &pci_dev->dev;
rt2x00dev->ops = ops;
rt2x00dev->hw = hw;
rt2x00dev->irq = pci_dev->irq;
rt2x00dev->name = ops->name;
if (pci_is_pcie(pci_dev))
rt2x00_set_chip_intf(rt2x00dev, RT2X00_CHIP_INTF_PCIE);
else
rt2x00_set_chip_intf(rt2x00dev, RT2X00_CHIP_INTF_PCI);
retval = rt2x00pci_alloc_reg(rt2x00dev);
if (retval)
goto exit_free_device;
pci_read_config_word(pci_dev, PCI_DEVICE_ID, &chip);
rt2x00dev->chip.rt = chip;
retval = rt2x00lib_probe_dev(rt2x00dev);
if (retval)
goto exit_free_reg;
return 0;
exit_free_reg:
rt2x00pci_free_reg(rt2x00dev);
exit_free_device:
ieee80211_free_hw(hw);
exit_release_regions:
pci_release_regions(pci_dev);
exit_disable_device:
pci_disable_device(pci_dev);
pci_set_drvdata(pci_dev, NULL);
return retval;
}
void rt2x00pci_remove(struct pci_dev *pci_dev)
{
struct ieee80211_hw *hw = pci_get_drvdata(pci_dev);
struct rt2x00_dev *rt2x00dev = hw->priv;
rt2x00lib_remove_dev(rt2x00dev);
rt2x00pci_free_reg(rt2x00dev);
ieee80211_free_hw(hw);
pci_set_drvdata(pci_dev, NULL);
pci_disable_device(pci_dev);
pci_release_regions(pci_dev);
}
int rt2x00pci_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
struct ieee80211_hw *hw = pci_get_drvdata(pci_dev);
struct rt2x00_dev *rt2x00dev = hw->priv;
int retval;
retval = rt2x00lib_suspend(rt2x00dev, state);
if (retval)
return retval;
pci_save_state(pci_dev);
pci_disable_device(pci_dev);
return pci_set_power_state(pci_dev, pci_choose_state(pci_dev, state));
}
int rt2x00pci_resume(struct pci_dev *pci_dev)
{
struct ieee80211_hw *hw = pci_get_drvdata(pci_dev);
struct rt2x00_dev *rt2x00dev = hw->priv;
if (pci_set_power_state(pci_dev, PCI_D0) ||
pci_enable_device(pci_dev)) {
rt2x00_err(rt2x00dev, "Failed to resume device\n");
return -EIO;
}
pci_restore_state(pci_dev);
return rt2x00lib_resume(rt2x00dev);
}
