static void zpci_event_log_err(struct zpci_ccdf_err *ccdf)
{
struct zpci_dev *zdev = get_zdev_by_fid(ccdf->fid);
zpci_err("SEI error CCD:\n");
zpci_err_hex(ccdf, sizeof(*ccdf));
dev_err(&zdev->pdev->dev, "event code: 0x%x\n", ccdf->pec);
}
static void zpci_event_log_avail(struct zpci_ccdf_avail *ccdf)
{
struct zpci_dev *zdev = get_zdev_by_fid(ccdf->fid);
pr_err("%s%s: availability event: fh: 0x%x fid: 0x%x event code: 0x%x reason:",
(zdev) ? dev_driver_string(&zdev->pdev->dev) : "?",
(zdev) ? dev_name(&zdev->pdev->dev) : "?",
ccdf->fh, ccdf->fid, ccdf->pec);
print_hex_dump(KERN_CONT, "ccdf", DUMP_PREFIX_OFFSET,
16, 1, ccdf, sizeof(*ccdf), false);
switch (ccdf->pec) {
case 0x0301:
zpci_enable_device(zdev);
break;
case 0x0302:
clp_add_pci_device(ccdf->fid, ccdf->fh, 0);
break;
case 0x0306:
clp_find_pci_devices();
break;
default:
break;
}
}
void zpci_event_error(void *data)
{
struct zpci_ccdf_err *ccdf = data;
struct zpci_dev *zdev;
zpci_event_log_err(ccdf);
zdev = get_zdev_by_fid(ccdf->fid);
if (!zdev) {
pr_err("Error event for unknown fid: %x", ccdf->fid);
return;
}
}
void zpci_event_availability(void *data)
{
zpci_event_log_avail(data);
}
