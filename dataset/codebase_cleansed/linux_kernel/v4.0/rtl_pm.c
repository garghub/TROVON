int rtl8192E_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct r8192_priv *priv = rtllib_priv(dev);
u32 ulRegRead;
printk(KERN_INFO "============> r8192E suspend call.\n");
del_timer_sync(&priv->gpio_polling_timer);
cancel_delayed_work(&priv->gpio_change_rf_wq);
priv->polling_timer_on = 0;
if (!netif_running(dev)) {
printk(KERN_INFO "RTL819XE:UI is open out of suspend "
"function\n");
goto out_pci_suspend;
}
if (dev->netdev_ops->ndo_stop)
dev->netdev_ops->ndo_stop(dev);
netif_device_detach(dev);
if (!priv->rtllib->bSupportRemoteWakeUp) {
MgntActSet_RF_State(dev, eRfOff, RF_CHANGE_BY_INIT, true);
ulRegRead = read_nic_dword(dev, CPU_GEN);
ulRegRead |= CPU_GEN_SYSTEM_RESET;
write_nic_dword(dev, CPU_GEN, ulRegRead);
} else {
write_nic_dword(dev, WFCRC0, 0xffffffff);
write_nic_dword(dev, WFCRC1, 0xffffffff);
write_nic_dword(dev, WFCRC2, 0xffffffff);
write_nic_byte(dev, PMR, 0x5);
write_nic_byte(dev, MacBlkCtrl, 0xa);
}
out_pci_suspend:
printk("r8192E support WOL call??????????????????????\n");
if (priv->rtllib->bSupportRemoteWakeUp)
RT_TRACE(COMP_POWER, "r8192E support WOL call!!!!!!!"
"!!!!!!!!!!!.\n");
pci_save_state(pdev);
pci_disable_device(pdev);
pci_enable_wake(pdev, pci_choose_state(pdev, state),
priv->rtllib->bSupportRemoteWakeUp ? 1 : 0);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
mdelay(20);
return 0;
}
int rtl8192E_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct r8192_priv *priv = rtllib_priv(dev);
int err;
u32 val;
printk(KERN_INFO "================>r8192E resume call.\n");
pci_set_power_state(pdev, PCI_D0);
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR "%s: pci_enable_device failed on resume\n",
dev->name);
return err;
}
pci_restore_state(pdev);
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
pci_enable_wake(pdev, PCI_D0, 0);
if (priv->polling_timer_on == 0)
check_rfctrl_gpio_timer((unsigned long)dev);
if (!netif_running(dev)) {
printk(KERN_INFO "RTL819XE:UI is open out of resume "
"function\n");
goto out;
}
netif_device_attach(dev);
if (dev->netdev_ops->ndo_open)
dev->netdev_ops->ndo_open(dev);
if (!priv->rtllib->bSupportRemoteWakeUp)
MgntActSet_RF_State(dev, eRfOn, RF_CHANGE_BY_INIT, true);
out:
RT_TRACE(COMP_POWER, "<================r8192E resume call.\n");
return 0;
}
