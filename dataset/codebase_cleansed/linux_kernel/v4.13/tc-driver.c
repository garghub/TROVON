int tc_register_driver(struct tc_driver *tdrv)
{
return driver_register(&tdrv->driver);
}
void tc_unregister_driver(struct tc_driver *tdrv)
{
driver_unregister(&tdrv->driver);
}
const struct tc_device_id *tc_match_device(struct tc_driver *tdrv,
struct tc_dev *tdev)
{
const struct tc_device_id *id = tdrv->id_table;
if (id) {
while (id->name[0] || id->vendor[0]) {
if (strcmp(tdev->name, id->name) == 0 &&
strcmp(tdev->vendor, id->vendor) == 0)
return id;
id++;
}
}
return NULL;
}
static int tc_bus_match(struct device *dev, struct device_driver *drv)
{
struct tc_dev *tdev = to_tc_dev(dev);
struct tc_driver *tdrv = to_tc_driver(drv);
const struct tc_device_id *id;
id = tc_match_device(tdrv, tdev);
if (id)
return 1;
return 0;
}
static int __init tc_driver_init(void)
{
return bus_register(&tc_bus_type);
}
