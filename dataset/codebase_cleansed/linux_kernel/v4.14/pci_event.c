static void __zpci_event_error(struct zpci_ccdf_err *ccdf)
{
struct zpci_dev *zdev = get_zdev_by_fid(ccdf->fid);
struct pci_dev *pdev = NULL;
zpci_err("error CCDF:\n");
zpci_err_hex(ccdf, sizeof(*ccdf));
if (zdev)
pdev = pci_get_slot(zdev->bus, ZPCI_DEVFN);
pr_err("%s: Event 0x%x reports an error for PCI function 0x%x\n",
pdev ? pci_name(pdev) : "n/a", ccdf->pec, ccdf->fid);
if (!pdev)
return;
pdev->error_state = pci_channel_io_perm_failure;
pci_dev_put(pdev);
}
void zpci_event_error(void *data)
{
if (zpci_is_enabled())
__zpci_event_error(data);
}
static void __zpci_event_availability(struct zpci_ccdf_avail *ccdf)
{
struct zpci_dev *zdev = get_zdev_by_fid(ccdf->fid);
struct pci_dev *pdev = NULL;
enum zpci_state state;
int ret;
if (zdev)
pdev = pci_get_slot(zdev->bus, ZPCI_DEVFN);
pr_info("%s: Event 0x%x reconfigured PCI function 0x%x\n",
pdev ? pci_name(pdev) : "n/a", ccdf->pec, ccdf->fid);
zpci_err("avail CCDF:\n");
zpci_err_hex(ccdf, sizeof(*ccdf));
switch (ccdf->pec) {
case 0x0301:
if (!zdev) {
ret = clp_add_pci_device(ccdf->fid, ccdf->fh, 0);
if (ret)
break;
zdev = get_zdev_by_fid(ccdf->fid);
}
if (!zdev || zdev->state != ZPCI_FN_STATE_STANDBY)
break;
zdev->state = ZPCI_FN_STATE_CONFIGURED;
zdev->fh = ccdf->fh;
ret = zpci_enable_device(zdev);
if (ret)
break;
pci_lock_rescan_remove();
pci_rescan_bus(zdev->bus);
pci_unlock_rescan_remove();
break;
case 0x0302:
if (!zdev)
clp_add_pci_device(ccdf->fid, ccdf->fh, 0);
break;
case 0x0303:
if (!zdev)
break;
if (pdev)
pci_stop_and_remove_bus_device_locked(pdev);
ret = zpci_disable_device(zdev);
if (ret)
break;
ret = sclp_pci_deconfigure(zdev->fid);
zpci_dbg(3, "deconf fid:%x, rc:%d\n", zdev->fid, ret);
if (!ret)
zdev->state = ZPCI_FN_STATE_STANDBY;
break;
case 0x0304:
if (!zdev)
break;
if (pdev) {
pdev->error_state = pci_channel_io_perm_failure;
pci_stop_and_remove_bus_device_locked(pdev);
}
zdev->fh = ccdf->fh;
zpci_disable_device(zdev);
zdev->state = ZPCI_FN_STATE_STANDBY;
if (!clp_get_state(ccdf->fid, &state) &&
state == ZPCI_FN_STATE_RESERVED) {
zpci_remove_device(zdev);
}
break;
case 0x0306:
clp_rescan_pci_devices();
break;
case 0x0308:
if (!zdev)
break;
zpci_remove_device(zdev);
break;
default:
break;
}
pci_dev_put(pdev);
}
void zpci_event_availability(void *data)
{
if (zpci_is_enabled())
__zpci_event_availability(data);
}
