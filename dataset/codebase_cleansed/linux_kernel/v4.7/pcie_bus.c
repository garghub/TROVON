static
void wil_set_capabilities(struct wil6210_priv *wil)
{
u32 rev_id = wil_r(wil, RGF_USER_JTAG_DEV_ID);
bitmap_zero(wil->hw_capabilities, hw_capability_last);
switch (rev_id) {
case JTAG_DEV_ID_SPARROW_B0:
wil->hw_name = "Sparrow B0";
wil->hw_version = HW_VER_SPARROW_B0;
break;
default:
wil_err(wil, "Unknown board hardware 0x%08x\n", rev_id);
wil->hw_name = "Unknown";
wil->hw_version = HW_VER_UNKNOWN;
}
wil_info(wil, "Board hardware is %s\n", wil->hw_name);
}
void wil_disable_irq(struct wil6210_priv *wil)
{
disable_irq(wil->pdev->irq);
}
void wil_enable_irq(struct wil6210_priv *wil)
{
enable_irq(wil->pdev->irq);
}
static int wil_if_pcie_enable(struct wil6210_priv *wil)
{
struct pci_dev *pdev = wil->pdev;
int rc;
int msi_only = pdev->msi_enabled;
bool _use_msi = use_msi;
wil_dbg_misc(wil, "%s()\n", __func__);
pdev->msi_enabled = 0;
pci_set_master(pdev);
wil_dbg_misc(wil, "Setup %s interrupt\n", use_msi ? "MSI" : "INTx");
if (use_msi && pci_enable_msi(pdev)) {
wil_err(wil, "pci_enable_msi failed, use INTx\n");
_use_msi = false;
}
if (!_use_msi && msi_only) {
wil_err(wil, "Interrupt pin not routed, unable to use INTx\n");
rc = -ENODEV;
goto stop_master;
}
rc = wil6210_init_irq(wil, pdev->irq, _use_msi);
if (rc)
goto stop_master;
mutex_lock(&wil->mutex);
rc = wil_reset(wil, false);
mutex_unlock(&wil->mutex);
if (rc)
goto release_irq;
return 0;
release_irq:
wil6210_fini_irq(wil, pdev->irq);
pci_disable_msi(pdev);
stop_master:
pci_clear_master(pdev);
return rc;
}
static int wil_if_pcie_disable(struct wil6210_priv *wil)
{
struct pci_dev *pdev = wil->pdev;
wil_dbg_misc(wil, "%s()\n", __func__);
pci_clear_master(pdev);
wil6210_fini_irq(wil, pdev->irq);
pci_disable_msi(pdev);
return 0;
}
static int wil_platform_rop_ramdump(void *wil_handle, void *buf, uint32_t size)
{
struct wil6210_priv *wil = wil_handle;
if (!wil)
return -EINVAL;
return wil_fw_copy_crash_dump(wil, buf, size);
}
static int wil_platform_rop_fw_recovery(void *wil_handle)
{
struct wil6210_priv *wil = wil_handle;
if (!wil)
return -EINVAL;
wil_fw_error_recovery(wil);
return 0;
}
static int wil_pcie_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct wil6210_priv *wil;
struct device *dev = &pdev->dev;
int rc;
const struct wil_platform_rops rops = {
.ramdump = wil_platform_rop_ramdump,
.fw_recovery = wil_platform_rop_fw_recovery,
};
dev_info(&pdev->dev, WIL_NAME
" device found [%04x:%04x] (rev %x)\n",
(int)pdev->vendor, (int)pdev->device, (int)pdev->revision);
if (pci_resource_len(pdev, 0) != WIL6210_MEM_SIZE) {
dev_err(&pdev->dev, "Not " WIL_NAME "? "
"BAR0 size is %lu while expecting %lu\n",
(ulong)pci_resource_len(pdev, 0), WIL6210_MEM_SIZE);
return -ENODEV;
}
wil = wil_if_alloc(dev);
if (IS_ERR(wil)) {
rc = (int)PTR_ERR(wil);
dev_err(dev, "wil_if_alloc failed: %d\n", rc);
return rc;
}
wil->pdev = pdev;
pci_set_drvdata(pdev, wil);
wil->platform_handle =
wil_platform_init(&pdev->dev, &wil->platform_ops, &rops, wil);
if (!wil->platform_handle) {
rc = -ENODEV;
wil_err(wil, "wil_platform_init failed\n");
goto if_free;
}
rc = pci_enable_device(pdev);
if (rc) {
wil_err(wil,
"pci_enable_device failed, retry with MSI only\n");
pdev->msi_enabled = 1;
rc = pci_enable_device(pdev);
}
if (rc) {
wil_err(wil,
"pci_enable_device failed, even with MSI only\n");
goto err_plat;
}
rc = pci_request_region(pdev, 0, WIL_NAME);
if (rc) {
wil_err(wil, "pci_request_region failed\n");
goto err_disable_pdev;
}
wil->csr = pci_ioremap_bar(pdev, 0);
if (!wil->csr) {
wil_err(wil, "pci_ioremap_bar failed\n");
rc = -ENODEV;
goto err_release_reg;
}
wil_info(wil, "CSR at %pR -> 0x%p\n", &pdev->resource[0], wil->csr);
wil_set_capabilities(wil);
wil6210_clear_irq(wil);
rc = wil_if_pcie_enable(wil);
if (rc) {
wil_err(wil, "Enable device failed\n");
goto err_iounmap;
}
rc = wil_if_add(wil);
if (rc) {
wil_err(wil, "wil_if_add failed: %d\n", rc);
goto bus_disable;
}
wil6210_debugfs_init(wil);
return 0;
bus_disable:
wil_if_pcie_disable(wil);
err_iounmap:
pci_iounmap(pdev, wil->csr);
err_release_reg:
pci_release_region(pdev, 0);
err_disable_pdev:
pci_disable_device(pdev);
err_plat:
if (wil->platform_ops.uninit)
wil->platform_ops.uninit(wil->platform_handle);
if_free:
wil_if_free(wil);
return rc;
}
static void wil_pcie_remove(struct pci_dev *pdev)
{
struct wil6210_priv *wil = pci_get_drvdata(pdev);
void __iomem *csr = wil->csr;
wil_dbg_misc(wil, "%s()\n", __func__);
wil6210_debugfs_remove(wil);
wil_if_remove(wil);
wil_if_pcie_disable(wil);
pci_iounmap(pdev, csr);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
if (wil->platform_ops.uninit)
wil->platform_ops.uninit(wil->platform_handle);
wil_p2p_wdev_free(wil);
wil_if_free(wil);
}
static int wil6210_suspend(struct device *dev, bool is_runtime)
{
int rc = 0;
struct pci_dev *pdev = to_pci_dev(dev);
struct wil6210_priv *wil = pci_get_drvdata(pdev);
wil_dbg_pm(wil, "%s(%s)\n", __func__,
is_runtime ? "runtime" : "system");
rc = wil_can_suspend(wil, is_runtime);
if (rc)
goto out;
rc = wil_suspend(wil, is_runtime);
if (rc)
goto out;
pci_clear_master(pdev);
out:
return rc;
}
static int wil6210_resume(struct device *dev, bool is_runtime)
{
int rc = 0;
struct pci_dev *pdev = to_pci_dev(dev);
struct wil6210_priv *wil = pci_get_drvdata(pdev);
wil_dbg_pm(wil, "%s(%s)\n", __func__,
is_runtime ? "runtime" : "system");
pci_set_master(pdev);
rc = wil_resume(wil, is_runtime);
if (rc)
pci_clear_master(pdev);
return rc;
}
static int wil6210_pm_suspend(struct device *dev)
{
return wil6210_suspend(dev, false);
}
static int wil6210_pm_resume(struct device *dev)
{
return wil6210_resume(dev, false);
}
static int __init wil6210_driver_init(void)
{
int rc;
rc = wil_platform_modinit();
if (rc)
return rc;
rc = pci_register_driver(&wil6210_driver);
if (rc)
wil_platform_modexit();
return rc;
}
static void __exit wil6210_driver_exit(void)
{
pci_unregister_driver(&wil6210_driver);
wil_platform_modexit();
}
