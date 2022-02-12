static int wil_if_pcie_enable(struct wil6210_priv *wil)
{
struct pci_dev *pdev = wil->pdev;
int rc;
int msi_only = pdev->msi_enabled;
pdev->msi_enabled = 0;
pci_set_master(pdev);
switch (use_msi) {
case 3:
case 1:
wil_dbg_misc(wil, "Setup %d MSI interrupts\n", use_msi);
break;
case 0:
wil_dbg_misc(wil, "MSI interrupts disabled, use INTx\n");
break;
default:
wil_err(wil, "Invalid use_msi=%d, default to 1\n", use_msi);
use_msi = 1;
}
if (use_msi == 3 && pci_enable_msi_range(pdev, 3, 3) < 0) {
wil_err(wil, "3 MSI mode failed, try 1 MSI\n");
use_msi = 1;
}
if (use_msi == 1 && pci_enable_msi(pdev)) {
wil_err(wil, "pci_enable_msi failed, use INTx\n");
use_msi = 0;
}
wil->n_msi = use_msi;
if ((wil->n_msi == 0) && msi_only) {
wil_err(wil, "Interrupt pin not routed, unable to use INTx\n");
rc = -ENODEV;
goto stop_master;
}
rc = wil6210_init_irq(wil, pdev->irq);
if (rc)
goto stop_master;
mutex_lock(&wil->mutex);
rc = wil_reset(wil);
mutex_unlock(&wil->mutex);
if (debug_fw)
rc = 0;
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
pci_clear_master(pdev);
wil6210_fini_irq(wil, pdev->irq);
pci_disable_msi(pdev);
return 0;
}
static int wil_pcie_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct wil6210_priv *wil;
struct device *dev = &pdev->dev;
void __iomem *csr;
struct wil_board *board = (struct wil_board *)id->driver_data;
int rc;
dev_info(&pdev->dev, WIL_NAME
" \"%s\" device found [%04x:%04x] (rev %x)\n", board->name,
(int)pdev->vendor, (int)pdev->device, (int)pdev->revision);
if (pci_resource_len(pdev, 0) != WIL6210_MEM_SIZE) {
dev_err(&pdev->dev, "Not " WIL_NAME "? "
"BAR0 size is %lu while expecting %lu\n",
(ulong)pci_resource_len(pdev, 0), WIL6210_MEM_SIZE);
return -ENODEV;
}
rc = pci_enable_device(pdev);
if (rc) {
dev_err(&pdev->dev,
"pci_enable_device failed, retry with MSI only\n");
pdev->msi_enabled = 1;
rc = pci_enable_device(pdev);
}
if (rc)
return -ENODEV;
rc = pci_request_region(pdev, 0, WIL_NAME);
if (rc) {
dev_err(&pdev->dev, "pci_request_region failed\n");
goto err_disable_pdev;
}
csr = pci_ioremap_bar(pdev, 0);
if (!csr) {
dev_err(&pdev->dev, "pci_ioremap_bar failed\n");
rc = -ENODEV;
goto err_release_reg;
}
dev_info(&pdev->dev, "CSR at %pR -> 0x%p\n", &pdev->resource[0], csr);
wil = wil_if_alloc(dev, csr);
if (IS_ERR(wil)) {
rc = (int)PTR_ERR(wil);
dev_err(dev, "wil_if_alloc failed: %d\n", rc);
goto err_iounmap;
}
pci_set_drvdata(pdev, wil);
wil->pdev = pdev;
wil->board = board;
wil6210_clear_irq(wil);
rc = wil_if_pcie_enable(wil);
if (rc) {
wil_err(wil, "Enable device failed\n");
goto if_free;
}
rc = wil_if_add(wil);
if (rc) {
wil_err(wil, "wil_if_add failed: %d\n", rc);
goto bus_disable;
}
wil6210_debugfs_init(wil);
wmi_echo(wil);
return 0;
bus_disable:
wil_if_pcie_disable(wil);
if_free:
wil_if_free(wil);
err_iounmap:
pci_iounmap(pdev, csr);
err_release_reg:
pci_release_region(pdev, 0);
err_disable_pdev:
pci_disable_device(pdev);
return rc;
}
static void wil_pcie_remove(struct pci_dev *pdev)
{
struct wil6210_priv *wil = pci_get_drvdata(pdev);
wil6210_debugfs_remove(wil);
wil_if_pcie_disable(wil);
wil_if_remove(wil);
wil_if_free(wil);
pci_iounmap(pdev, wil->csr);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
}
