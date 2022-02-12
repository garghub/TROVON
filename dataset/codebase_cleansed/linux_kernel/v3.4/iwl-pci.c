static int iwl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct iwl_cfg *cfg = (struct iwl_cfg *)(ent->driver_data);
struct iwl_shared *shrd;
struct iwl_trans *iwl_trans;
int err;
shrd = kzalloc(sizeof(*iwl_trans->shrd), GFP_KERNEL);
if (!shrd) {
dev_printk(KERN_ERR, &pdev->dev,
"Couldn't allocate iwl_shared");
err = -ENOMEM;
goto out_free_bus;
}
#ifdef CONFIG_IWLWIFI_IDI
iwl_trans = iwl_trans_idi_alloc(shrd, pdev, ent);
#else
iwl_trans = iwl_trans_pcie_alloc(shrd, pdev, ent);
#endif
if (iwl_trans == NULL) {
err = -ENOMEM;
goto out_free_bus;
}
shrd->trans = iwl_trans;
pci_set_drvdata(pdev, iwl_trans);
err = iwl_drv_start(shrd, iwl_trans, cfg);
if (err)
goto out_free_trans;
return 0;
out_free_trans:
iwl_trans_free(iwl_trans);
pci_set_drvdata(pdev, NULL);
out_free_bus:
kfree(shrd);
return err;
}
static void __devexit iwl_pci_remove(struct pci_dev *pdev)
{
struct iwl_trans *iwl_trans = pci_get_drvdata(pdev);
struct iwl_shared *shrd = iwl_trans->shrd;
iwl_drv_stop(shrd);
iwl_trans_free(shrd->trans);
pci_set_drvdata(pdev, NULL);
kfree(shrd);
}
static int iwl_pci_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *iwl_trans = pci_get_drvdata(pdev);
return iwl_trans_suspend(iwl_trans);
}
static int iwl_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *iwl_trans = pci_get_drvdata(pdev);
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
return iwl_trans_resume(iwl_trans);
}
int __must_check iwl_pci_register_driver(void)
{
int ret;
ret = pci_register_driver(&iwl_pci_driver);
if (ret)
pr_err("Unable to initialize PCI module\n");
return ret;
}
void iwl_pci_unregister_driver(void)
{
pci_unregister_driver(&iwl_pci_driver);
}
