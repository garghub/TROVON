static u64 splx_get_pwr_limit(struct iwl_trans *trans, union acpi_object *splx)
{
union acpi_object *limits, *domain_type, *power_limit;
if (splx->type != ACPI_TYPE_PACKAGE ||
splx->package.count != 2 ||
splx->package.elements[0].type != ACPI_TYPE_INTEGER ||
splx->package.elements[0].integer.value != 0) {
IWL_ERR(trans, "Unsupported splx structure\n");
return 0;
}
limits = &splx->package.elements[1];
if (limits->type != ACPI_TYPE_PACKAGE ||
limits->package.count < 2 ||
limits->package.elements[0].type != ACPI_TYPE_INTEGER ||
limits->package.elements[1].type != ACPI_TYPE_INTEGER) {
IWL_ERR(trans, "Invalid limits element\n");
return 0;
}
domain_type = &limits->package.elements[0];
power_limit = &limits->package.elements[1];
if (!(domain_type->integer.value & SPL_DOMAINTYPE_WIFI)) {
IWL_DEBUG_INFO(trans, "WiFi power is not limited\n");
return 0;
}
return power_limit->integer.value;
}
static void set_dflt_pwr_limit(struct iwl_trans *trans, struct pci_dev *pdev)
{
acpi_handle pxsx_handle;
acpi_handle handle;
struct acpi_buffer splx = {ACPI_ALLOCATE_BUFFER, NULL};
acpi_status status;
pxsx_handle = ACPI_HANDLE(&pdev->dev);
if (!pxsx_handle) {
IWL_DEBUG_INFO(trans,
"Could not retrieve root port ACPI handle\n");
return;
}
status = acpi_get_handle(pxsx_handle, (acpi_string)SPL_METHOD, &handle);
if (ACPI_FAILURE(status)) {
IWL_DEBUG_INFO(trans, "SPL method not found\n");
return;
}
status = acpi_evaluate_object(handle, NULL, NULL, &splx);
if (ACPI_FAILURE(status)) {
IWL_ERR(trans, "SPLC invocation failed (0x%x)\n", status);
return;
}
trans->dflt_pwr_limit = splx_get_pwr_limit(trans, splx.pointer);
IWL_DEBUG_INFO(trans, "Default power limit set to %lld\n",
trans->dflt_pwr_limit);
kfree(splx.pointer);
}
static void set_dflt_pwr_limit(struct iwl_trans *trans, struct pci_dev *pdev) {}
static int iwl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct iwl_cfg *cfg = (struct iwl_cfg *)(ent->driver_data);
const struct iwl_cfg *cfg_7265d __maybe_unused = NULL;
struct iwl_trans *iwl_trans;
struct iwl_trans_pcie *trans_pcie;
int ret;
iwl_trans = iwl_trans_pcie_alloc(pdev, ent, cfg);
if (IS_ERR(iwl_trans))
return PTR_ERR(iwl_trans);
#if IS_ENABLED(CONFIG_IWLMVM)
if (cfg == &iwl7265_2ac_cfg)
cfg_7265d = &iwl7265d_2ac_cfg;
else if (cfg == &iwl7265_2n_cfg)
cfg_7265d = &iwl7265d_2n_cfg;
else if (cfg == &iwl7265_n_cfg)
cfg_7265d = &iwl7265d_n_cfg;
if (cfg_7265d &&
(iwl_trans->hw_rev & CSR_HW_REV_TYPE_MSK) == CSR_HW_REV_TYPE_7265D) {
cfg = cfg_7265d;
iwl_trans->cfg = cfg_7265d;
}
#endif
pci_set_drvdata(pdev, iwl_trans);
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(iwl_trans);
trans_pcie->drv = iwl_drv_start(iwl_trans, cfg);
if (IS_ERR(trans_pcie->drv)) {
ret = PTR_ERR(trans_pcie->drv);
goto out_free_trans;
}
set_dflt_pwr_limit(iwl_trans, pdev);
ret = iwl_trans_dbgfs_register(iwl_trans, iwl_trans->dbgfs_dir);
if (ret)
goto out_free_drv;
return 0;
out_free_drv:
iwl_drv_stop(trans_pcie->drv);
out_free_trans:
iwl_trans_pcie_free(iwl_trans);
return ret;
}
static void iwl_pci_remove(struct pci_dev *pdev)
{
struct iwl_trans *trans = pci_get_drvdata(pdev);
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
iwl_drv_stop(trans_pcie->drv);
iwl_trans_pcie_free(trans);
}
static int iwl_pci_suspend(struct device *device)
{
return 0;
}
static int iwl_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *trans = pci_get_drvdata(pdev);
bool hw_rfkill;
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
if (!trans->op_mode)
return 0;
if (trans->wowlan_d0i3) {
iwl_pcie_reset_ict(trans);
iwl_enable_interrupts(trans);
} else {
iwl_enable_rfkill_int(trans);
}
hw_rfkill = iwl_is_rfkill_set(trans);
iwl_trans_pcie_rf_kill(trans, hw_rfkill);
return 0;
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
