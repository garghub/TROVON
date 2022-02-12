static int iwl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct iwl_cfg *cfg = (struct iwl_cfg *)(ent->driver_data);
struct iwl_trans *iwl_trans;
struct iwl_trans_pcie *trans_pcie;
int ret;
iwl_trans = iwl_trans_pcie_alloc(pdev, ent, cfg);
if (iwl_trans == NULL)
return -ENOMEM;
pci_set_drvdata(pdev, iwl_trans);
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(iwl_trans);
trans_pcie->drv = iwl_drv_start(iwl_trans, cfg);
if (IS_ERR_OR_NULL(trans_pcie->drv)) {
ret = PTR_ERR(trans_pcie->drv);
goto out_free_trans;
}
ret = iwl_trans_dbgfs_register(iwl_trans, iwl_trans->dbgfs_dir);
if (ret)
goto out_free_drv;
return 0;
out_free_drv:
iwl_drv_stop(trans_pcie->drv);
out_free_trans:
iwl_trans_pcie_free(iwl_trans);
pci_set_drvdata(pdev, NULL);
return ret;
}
static void iwl_pci_remove(struct pci_dev *pdev)
{
struct iwl_trans *trans = pci_get_drvdata(pdev);
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
iwl_drv_stop(trans_pcie->drv);
iwl_trans_pcie_free(trans);
pci_set_drvdata(pdev, NULL);
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
