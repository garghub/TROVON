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
const struct iwl_cfg *cfg_9260lc __maybe_unused = NULL;
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
if (iwl_trans->cfg->rf_id) {
if (cfg == &iwl9260_2ac_cfg)
cfg_9260lc = &iwl9260lc_2ac_cfg;
if (cfg_9260lc && iwl_trans->hw_rf_id == CSR_HW_RF_ID_TYPE_LC) {
cfg = cfg_9260lc;
iwl_trans->cfg = cfg_9260lc;
}
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
ret = iwl_trans_pcie_dbgfs_register(iwl_trans);
if (ret)
goto out_free_drv;
if (iwl_trans->runtime_pm_mode != IWL_PLAT_PM_MODE_DISABLED) {
pm_runtime_set_active(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev,
iwlwifi_mod_params.d0i3_entry_delay);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_allow(&pdev->dev);
}
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
if (trans->runtime_pm_mode != IWL_PLAT_PM_MODE_DISABLED) {
pm_runtime_forbid(trans->dev);
}
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
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
bool hw_rfkill;
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
if (!trans->op_mode)
return 0;
iwl_enable_rfkill_int(trans);
hw_rfkill = iwl_is_rfkill_set(trans);
mutex_lock(&trans_pcie->mutex);
iwl_trans_pcie_rf_kill(trans, hw_rfkill);
mutex_unlock(&trans_pcie->mutex);
return 0;
}
int iwl_pci_fw_enter_d0i3(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int ret;
if (test_bit(STATUS_FW_ERROR, &trans->status))
return 0;
set_bit(STATUS_TRANS_GOING_IDLE, &trans->status);
ret = iwl_op_mode_enter_d0i3(trans->op_mode);
if (ret == 1) {
IWL_DEBUG_RPM(trans, "aborting d0i3 entrance\n");
clear_bit(STATUS_TRANS_GOING_IDLE, &trans->status);
return -EBUSY;
}
if (ret)
goto err;
ret = wait_event_timeout(trans_pcie->d0i3_waitq,
test_bit(STATUS_TRANS_IDLE, &trans->status),
msecs_to_jiffies(IWL_TRANS_IDLE_TIMEOUT));
if (!ret) {
IWL_ERR(trans, "Timeout entering D0i3\n");
ret = -ETIMEDOUT;
goto err;
}
clear_bit(STATUS_TRANS_GOING_IDLE, &trans->status);
return 0;
err:
clear_bit(STATUS_TRANS_GOING_IDLE, &trans->status);
iwl_trans_fw_error(trans);
return ret;
}
int iwl_pci_fw_exit_d0i3(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int ret;
if (!test_bit(STATUS_TRANS_IDLE, &trans->status))
return 0;
ret = iwl_op_mode_exit_d0i3(trans->op_mode);
if (ret)
goto err;
ret = wait_event_timeout(trans_pcie->d0i3_waitq,
!test_bit(STATUS_TRANS_IDLE, &trans->status),
msecs_to_jiffies(IWL_TRANS_IDLE_TIMEOUT));
if (!ret) {
IWL_ERR(trans, "Timeout exiting D0i3\n");
ret = -ETIMEDOUT;
goto err;
}
return 0;
err:
clear_bit(STATUS_TRANS_IDLE, &trans->status);
iwl_trans_fw_error(trans);
return ret;
}
static int iwl_pci_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *trans = pci_get_drvdata(pdev);
int ret;
IWL_DEBUG_RPM(trans, "entering runtime suspend\n");
if (test_bit(STATUS_DEVICE_ENABLED, &trans->status)) {
ret = iwl_pci_fw_enter_d0i3(trans);
if (ret < 0)
return ret;
}
trans->system_pm_mode = IWL_PLAT_PM_MODE_D0I3;
iwl_trans_d3_suspend(trans, false, false);
return 0;
}
static int iwl_pci_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *trans = pci_get_drvdata(pdev);
enum iwl_d3_status d3_status;
IWL_DEBUG_RPM(trans, "exiting runtime suspend (resume)\n");
iwl_trans_d3_resume(trans, &d3_status, false, false);
if (test_bit(STATUS_DEVICE_ENABLED, &trans->status))
return iwl_pci_fw_exit_d0i3(trans);
return 0;
}
static int iwl_pci_system_prepare(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *trans = pci_get_drvdata(pdev);
IWL_DEBUG_RPM(trans, "preparing for system suspend\n");
trans->suspending = true;
pm_runtime_resume(device);
return 0;
}
static void iwl_pci_system_complete(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_trans *trans = pci_get_drvdata(pdev);
IWL_DEBUG_RPM(trans, "completing system suspend\n");
trans->suspending = false;
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
