static int pch_wpt_init(struct pch_thermal_device *ptd, int *nr_trips)
{
u8 tsel;
u16 trip_temp;
*nr_trips = 0;
if (WPT_TSS_TSDSS & readb(ptd->hw_base + WPT_TSS))
goto read_trips;
tsel = readb(ptd->hw_base + WPT_TSEL);
if (tsel & WPT_TSEL_PLDB) {
dev_err(&ptd->pdev->dev, "Sensor can't be enabled\n");
return -ENODEV;
}
writeb(tsel|WPT_TSEL_ETS, ptd->hw_base + WPT_TSEL);
if (!(WPT_TSS_TSDSS & readb(ptd->hw_base + WPT_TSS))) {
dev_err(&ptd->pdev->dev, "Sensor can't be enabled\n");
return -ENODEV;
}
read_trips:
ptd->crt_trip_id = -1;
trip_temp = readw(ptd->hw_base + WPT_CTT);
trip_temp &= 0x1FF;
if (trip_temp) {
ptd->crt_temp = trip_temp * 1000 / 2 - 50000;
ptd->crt_trip_id = 0;
++(*nr_trips);
}
ptd->hot_trip_id = -1;
trip_temp = readw(ptd->hw_base + WPT_PHL);
trip_temp &= 0x1FF;
if (trip_temp) {
ptd->hot_temp = trip_temp * 1000 / 2 - 50000;
ptd->hot_trip_id = *nr_trips;
++(*nr_trips);
}
return 0;
}
static int pch_wpt_get_temp(struct pch_thermal_device *ptd, int *temp)
{
u8 wpt_temp;
wpt_temp = WPT_TEMP_TSR & readl(ptd->hw_base + WPT_TEMP);
*temp = (wpt_temp * 1000 / 2 - 50000);
return 0;
}
static int pch_thermal_get_temp(struct thermal_zone_device *tzd, int *temp)
{
struct pch_thermal_device *ptd = tzd->devdata;
return ptd->ops->get_temp(ptd, temp);
}
static int pch_get_trip_type(struct thermal_zone_device *tzd, int trip,
enum thermal_trip_type *type)
{
struct pch_thermal_device *ptd = tzd->devdata;
if (ptd->crt_trip_id == trip)
*type = THERMAL_TRIP_CRITICAL;
else if (ptd->hot_trip_id == trip)
*type = THERMAL_TRIP_HOT;
else
return -EINVAL;
return 0;
}
static int pch_get_trip_temp(struct thermal_zone_device *tzd, int trip, int *temp)
{
struct pch_thermal_device *ptd = tzd->devdata;
if (ptd->crt_trip_id == trip)
*temp = ptd->crt_temp;
else if (ptd->hot_trip_id == trip)
*temp = ptd->hot_temp;
else
return -EINVAL;
return 0;
}
static int intel_pch_thermal_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct pch_thermal_device *ptd;
int err;
int nr_trips;
char *dev_name;
ptd = devm_kzalloc(&pdev->dev, sizeof(*ptd), GFP_KERNEL);
if (!ptd)
return -ENOMEM;
switch (pdev->device) {
case PCH_THERMAL_DID_WPT:
ptd->ops = &pch_dev_ops_wpt;
dev_name = "pch_wildcat_point";
break;
default:
dev_err(&pdev->dev, "unknown pch thermal device\n");
return -ENODEV;
}
pci_set_drvdata(pdev, ptd);
ptd->pdev = pdev;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable pci device\n");
return err;
}
err = pci_request_regions(pdev, driver_name);
if (err) {
dev_err(&pdev->dev, "failed to request pci region\n");
goto error_disable;
}
ptd->hw_base = pci_ioremap_bar(pdev, 0);
if (!ptd->hw_base) {
err = -ENOMEM;
dev_err(&pdev->dev, "failed to map mem base\n");
goto error_release;
}
err = ptd->ops->hw_init(ptd, &nr_trips);
if (err)
goto error_cleanup;
ptd->tzd = thermal_zone_device_register(dev_name, nr_trips, 0, ptd,
&tzd_ops, NULL, 0, 0);
if (IS_ERR(ptd->tzd)) {
dev_err(&pdev->dev, "Failed to register thermal zone %s\n",
dev_name);
err = PTR_ERR(ptd->tzd);
goto error_cleanup;
}
return 0;
error_cleanup:
iounmap(ptd->hw_base);
error_release:
pci_release_regions(pdev);
error_disable:
pci_disable_device(pdev);
dev_err(&pdev->dev, "pci device failed to probe\n");
return err;
}
static void intel_pch_thermal_remove(struct pci_dev *pdev)
{
struct pch_thermal_device *ptd = pci_get_drvdata(pdev);
thermal_zone_device_unregister(ptd->tzd);
iounmap(ptd->hw_base);
pci_set_drvdata(pdev, NULL);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
}
