static void kempld_get_hardware_mutex(struct kempld_device_data *pld)
{
while (ioread8(pld->io_index) & KEMPLD_MUTEX_KEY)
msleep(1);
}
static void kempld_release_hardware_mutex(struct kempld_device_data *pld)
{
iowrite8(KEMPLD_MUTEX_KEY, pld->io_index);
}
static int kempld_get_info_generic(struct kempld_device_data *pld)
{
u16 version;
u8 spec;
kempld_get_mutex(pld);
version = kempld_read16(pld, KEMPLD_VERSION);
spec = kempld_read8(pld, KEMPLD_SPEC);
pld->info.buildnr = kempld_read16(pld, KEMPLD_BUILDNR);
pld->info.minor = KEMPLD_VERSION_GET_MINOR(version);
pld->info.major = KEMPLD_VERSION_GET_MAJOR(version);
pld->info.number = KEMPLD_VERSION_GET_NUMBER(version);
pld->info.type = KEMPLD_VERSION_GET_TYPE(version);
if (spec == 0xff) {
pld->info.spec_minor = 0;
pld->info.spec_major = 1;
} else {
pld->info.spec_minor = KEMPLD_SPEC_GET_MINOR(spec);
pld->info.spec_major = KEMPLD_SPEC_GET_MAJOR(spec);
}
if (pld->info.spec_major > 0)
pld->feature_mask = kempld_read16(pld, KEMPLD_FEATURE);
else
pld->feature_mask = 0;
kempld_release_mutex(pld);
return 0;
}
static int kempld_register_cells_generic(struct kempld_device_data *pld)
{
struct mfd_cell devs[KEMPLD_MAX_DEVS];
int i = 0;
if (pld->feature_mask & KEMPLD_FEATURE_BIT_I2C)
devs[i++] = kempld_devs[KEMPLD_I2C];
if (pld->feature_mask & KEMPLD_FEATURE_BIT_WATCHDOG)
devs[i++] = kempld_devs[KEMPLD_WDT];
if (pld->feature_mask & KEMPLD_FEATURE_BIT_GPIO)
devs[i++] = kempld_devs[KEMPLD_GPIO];
if (pld->feature_mask & KEMPLD_FEATURE_MASK_UART)
devs[i++] = kempld_devs[KEMPLD_UART];
return mfd_add_devices(pld->dev, -1, devs, i, NULL, 0, NULL);
}
static int kempld_create_platform_device(const struct dmi_system_id *id)
{
struct kempld_platform_data *pdata = id->driver_data;
int ret;
kempld_pdev = platform_device_alloc("kempld", -1);
if (!kempld_pdev)
return -ENOMEM;
ret = platform_device_add_data(kempld_pdev, pdata, sizeof(*pdata));
if (ret)
goto err;
ret = platform_device_add_resources(kempld_pdev, pdata->ioresource, 1);
if (ret)
goto err;
ret = platform_device_add(kempld_pdev);
if (ret)
goto err;
return 0;
err:
platform_device_put(kempld_pdev);
return ret;
}
u8 kempld_read8(struct kempld_device_data *pld, u8 index)
{
iowrite8(index, pld->io_index);
return ioread8(pld->io_data);
}
void kempld_write8(struct kempld_device_data *pld, u8 index, u8 data)
{
iowrite8(index, pld->io_index);
iowrite8(data, pld->io_data);
}
u16 kempld_read16(struct kempld_device_data *pld, u8 index)
{
return kempld_read8(pld, index) | kempld_read8(pld, index + 1) << 8;
}
void kempld_write16(struct kempld_device_data *pld, u8 index, u16 data)
{
kempld_write8(pld, index, (u8)data);
kempld_write8(pld, index + 1, (u8)(data >> 8));
}
u32 kempld_read32(struct kempld_device_data *pld, u8 index)
{
return kempld_read16(pld, index) | kempld_read16(pld, index + 2) << 16;
}
void kempld_write32(struct kempld_device_data *pld, u8 index, u32 data)
{
kempld_write16(pld, index, (u16)data);
kempld_write16(pld, index + 2, (u16)(data >> 16));
}
void kempld_get_mutex(struct kempld_device_data *pld)
{
struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
mutex_lock(&pld->lock);
pdata->get_hardware_mutex(pld);
}
void kempld_release_mutex(struct kempld_device_data *pld)
{
struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
pdata->release_hardware_mutex(pld);
mutex_unlock(&pld->lock);
}
static int kempld_get_info(struct kempld_device_data *pld)
{
struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
return pdata->get_info(pld);
}
static int kempld_register_cells(struct kempld_device_data *pld)
{
struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
return pdata->register_cells(pld);
}
static int kempld_detect_device(struct kempld_device_data *pld)
{
char *version_type;
u8 index_reg;
int ret;
mutex_lock(&pld->lock);
index_reg = ioread8(pld->io_index);
if (index_reg == 0xff && ioread8(pld->io_data) == 0xff) {
mutex_unlock(&pld->lock);
return -ENODEV;
}
if (!(index_reg & KEMPLD_MUTEX_KEY))
iowrite8(KEMPLD_MUTEX_KEY, pld->io_index);
mutex_unlock(&pld->lock);
ret = kempld_get_info(pld);
if (ret)
return ret;
switch (pld->info.type) {
case 0:
version_type = "release";
break;
case 1:
version_type = "debug";
break;
case 2:
version_type = "custom";
break;
default:
version_type = "unspecified";
}
dev_info(pld->dev, "Found Kontron PLD %d\n", pld->info.number);
dev_info(pld->dev, "%s version %d.%d build %d, specification %d.%d\n",
version_type, pld->info.major, pld->info.minor,
pld->info.buildnr, pld->info.spec_major,
pld->info.spec_minor);
return kempld_register_cells(pld);
}
static int kempld_probe(struct platform_device *pdev)
{
struct kempld_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device *dev = &pdev->dev;
struct kempld_device_data *pld;
struct resource *ioport;
int ret;
pld = devm_kzalloc(dev, sizeof(*pld), GFP_KERNEL);
if (!pld)
return -ENOMEM;
ioport = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!ioport)
return -EINVAL;
pld->io_base = devm_ioport_map(dev, ioport->start,
ioport->end - ioport->start);
if (!pld->io_base)
return -ENOMEM;
pld->io_index = pld->io_base;
pld->io_data = pld->io_base + 1;
pld->pld_clock = pdata->pld_clock;
pld->dev = dev;
mutex_init(&pld->lock);
platform_set_drvdata(pdev, pld);
ret = kempld_detect_device(pld);
if (ret)
return ret;
return 0;
}
static int kempld_remove(struct platform_device *pdev)
{
struct kempld_device_data *pld = platform_get_drvdata(pdev);
struct kempld_platform_data *pdata = dev_get_platdata(pld->dev);
mfd_remove_devices(&pdev->dev);
pdata->release_hardware_mutex(pld);
return 0;
}
static int __init kempld_init(void)
{
const struct dmi_system_id *id;
int ret;
if (force_device_id[0]) {
for (id = kempld_dmi_table; id->matches[0].slot != DMI_NONE; id++)
if (strstr(id->ident, force_device_id))
if (id->callback && id->callback(id))
break;
if (id->matches[0].slot == DMI_NONE)
return -ENODEV;
} else {
if (!dmi_check_system(kempld_dmi_table))
return -ENODEV;
}
ret = platform_driver_register(&kempld_driver);
if (ret)
return ret;
return 0;
}
static void __exit kempld_exit(void)
{
if (kempld_pdev)
platform_device_unregister(kempld_pdev);
platform_driver_unregister(&kempld_driver);
}
