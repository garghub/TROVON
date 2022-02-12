static int fsi_bus_match(struct device *dev, struct device_driver *drv)
{
struct fsi_device *fsi_dev = to_fsi_dev(dev);
struct fsi_driver *fsi_drv = to_fsi_drv(drv);
const struct fsi_device_id *id;
if (!fsi_drv->id_table)
return 0;
for (id = fsi_drv->id_table; id->engine_type; id++) {
if (id->engine_type != fsi_dev->engine_type)
continue;
if (id->version == FSI_VERSION_ANY ||
id->version == fsi_dev->version)
return 1;
}
return 0;
}
static int fsi_init(void)
{
return bus_register(&fsi_bus_type);
}
static void fsi_exit(void)
{
bus_unregister(&fsi_bus_type);
}
