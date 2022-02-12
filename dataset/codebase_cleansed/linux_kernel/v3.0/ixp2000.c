static inline unsigned long flash_bank_setup(struct map_info *map, unsigned long ofs)
{
unsigned long (*set_bank)(unsigned long) =
(unsigned long(*)(unsigned long))map->map_priv_2;
return (set_bank ? set_bank(ofs) : ofs);
}
static inline unsigned long address_fix8_write(unsigned long addr)
{
if (erratum44_workaround) {
return (addr ^ 3);
}
return addr;
}
static map_word ixp2000_flash_read8(struct map_info *map, unsigned long ofs)
{
map_word val;
val.x[0] = *((u8 *)(map->map_priv_1 + flash_bank_setup(map, ofs)));
return val;
}
static void ixp2000_flash_copy_from(struct map_info *map, void *to,
unsigned long from, ssize_t len)
{
from = flash_bank_setup(map, from);
while(len--)
*(__u8 *) to++ = *(__u8 *)(map->map_priv_1 + from++);
}
static void ixp2000_flash_write8(struct map_info *map, map_word d, unsigned long ofs)
{
*(__u8 *) (address_fix8_write(map->map_priv_1 +
flash_bank_setup(map, ofs))) = d.x[0];
}
static void ixp2000_flash_copy_to(struct map_info *map, unsigned long to,
const void *from, ssize_t len)
{
to = flash_bank_setup(map, to);
while(len--) {
unsigned long tmp = address_fix8_write(map->map_priv_1 + to++);
*(__u8 *)(tmp) = *(__u8 *)(from++);
}
}
static int ixp2000_flash_remove(struct platform_device *dev)
{
struct flash_platform_data *plat = dev->dev.platform_data;
struct ixp2000_flash_info *info = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
if(!info)
return 0;
if (info->mtd) {
mtd_device_unregister(info->mtd);
map_destroy(info->mtd);
}
if (info->map.map_priv_1)
iounmap((void *) info->map.map_priv_1);
kfree(info->partitions);
if (info->res) {
release_resource(info->res);
kfree(info->res);
}
if (plat->exit)
plat->exit();
return 0;
}
static int ixp2000_flash_probe(struct platform_device *dev)
{
static const char *probes[] = { "RedBoot", "cmdlinepart", NULL };
struct ixp2000_flash_data *ixp_data = dev->dev.platform_data;
struct flash_platform_data *plat;
struct ixp2000_flash_info *info;
unsigned long window_size;
int err = -1;
if (!ixp_data)
return -ENODEV;
plat = ixp_data->platform_data;
if (!plat)
return -ENODEV;
window_size = dev->resource->end - dev->resource->start + 1;
dev_info(&dev->dev, "Probe of IXP2000 flash(%d banks x %dMiB)\n",
ixp_data->nr_banks, ((u32)window_size >> 20));
if (plat->width != 1) {
dev_err(&dev->dev, "IXP2000 MTD map only supports 8-bit mode, asking for %d\n",
plat->width * 8);
return -EIO;
}
info = kzalloc(sizeof(struct ixp2000_flash_info), GFP_KERNEL);
if(!info) {
err = -ENOMEM;
goto Error;
}
platform_set_drvdata(dev, info);
info->map.phys = NO_XIP;
info->map.size = ixp_data->nr_banks * window_size;
info->map.bankwidth = 1;
info->map.map_priv_2 = (unsigned long) ixp_data->bank_setup;
info->map.name = dev_name(&dev->dev);
info->map.read = ixp2000_flash_read8;
info->map.write = ixp2000_flash_write8;
info->map.copy_from = ixp2000_flash_copy_from;
info->map.copy_to = ixp2000_flash_copy_to;
info->res = request_mem_region(dev->resource->start,
dev->resource->end - dev->resource->start + 1,
dev_name(&dev->dev));
if (!info->res) {
dev_err(&dev->dev, "Could not reserve memory region\n");
err = -ENOMEM;
goto Error;
}
info->map.map_priv_1 = (unsigned long) ioremap(dev->resource->start,
dev->resource->end - dev->resource->start + 1);
if (!info->map.map_priv_1) {
dev_err(&dev->dev, "Failed to ioremap flash region\n");
err = -EIO;
goto Error;
}
#if defined(__ARMEB__)
erratum44_workaround = ixp2000_has_broken_slowport();
dev_info(&dev->dev, "Erratum 44 workaround %s\n",
erratum44_workaround ? "enabled" : "disabled");
#endif
info->mtd = do_map_probe(plat->map_name, &info->map);
if (!info->mtd) {
dev_err(&dev->dev, "map_probe failed\n");
err = -ENXIO;
goto Error;
}
info->mtd->owner = THIS_MODULE;
err = parse_mtd_partitions(info->mtd, probes, &info->partitions, 0);
if (err > 0) {
err = mtd_device_register(info->mtd, info->partitions, err);
if(err)
dev_err(&dev->dev, "Could not parse partitions\n");
}
if (err)
goto Error;
return 0;
Error:
ixp2000_flash_remove(dev);
return err;
}
static int __init ixp2000_flash_init(void)
{
return platform_driver_register(&ixp2000_flash_driver);
}
static void __exit ixp2000_flash_exit(void)
{
platform_driver_unregister(&ixp2000_flash_driver);
}
