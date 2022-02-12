static inline u16 flash_read16(void __iomem *addr)
{
return be16_to_cpu(__raw_readw((void __iomem *)((unsigned long)addr ^ 0x2)));
}
static inline void flash_write16(u16 d, void __iomem *addr)
{
__raw_writew(cpu_to_be16(d), (void __iomem *)((unsigned long)addr ^ 0x2));
}
static inline u16 flash_read16(const void __iomem *addr)
{
return __raw_readw(addr);
}
static inline void flash_write16(u16 d, void __iomem *addr)
{
__raw_writew(d, addr);
}
static map_word ixp4xx_read16(struct map_info *map, unsigned long ofs)
{
map_word val;
val.x[0] = flash_read16(map->virt + ofs);
return val;
}
static void ixp4xx_copy_from(struct map_info *map, void *to,
unsigned long from, ssize_t len)
{
u8 *dest = (u8 *) to;
void __iomem *src = map->virt + from;
if (len <= 0)
return;
if (from & 1) {
*dest++ = BYTE1(flash_read16(src-1));
src++;
--len;
}
while (len >= 2) {
u16 data = flash_read16(src);
*dest++ = BYTE0(data);
*dest++ = BYTE1(data);
src += 2;
len -= 2;
}
if (len > 0)
*dest++ = BYTE0(flash_read16(src));
}
static void ixp4xx_probe_write16(struct map_info *map, map_word d, unsigned long adr)
{
if (!(adr & 1))
flash_write16(d.x[0], map->virt + adr);
}
static void ixp4xx_write16(struct map_info *map, map_word d, unsigned long adr)
{
flash_write16(d.x[0], map->virt + adr);
}
static int ixp4xx_flash_remove(struct platform_device *dev)
{
struct flash_platform_data *plat = dev->dev.platform_data;
struct ixp4xx_flash_info *info = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
if(!info)
return 0;
if (info->mtd) {
mtd_device_unregister(info->mtd);
map_destroy(info->mtd);
}
if (info->map.virt)
iounmap(info->map.virt);
if (info->res) {
release_resource(info->res);
kfree(info->res);
}
if (plat->exit)
plat->exit();
return 0;
}
static int ixp4xx_flash_probe(struct platform_device *dev)
{
struct flash_platform_data *plat = dev->dev.platform_data;
struct ixp4xx_flash_info *info;
struct mtd_part_parser_data ppdata = {
.origin = dev->resource->start,
};
int err = -1;
if (!plat)
return -ENODEV;
if (plat->init) {
err = plat->init();
if (err)
return err;
}
info = kzalloc(sizeof(struct ixp4xx_flash_info), GFP_KERNEL);
if(!info) {
err = -ENOMEM;
goto Error;
}
platform_set_drvdata(dev, info);
info->map.phys = NO_XIP;
info->map.size = resource_size(dev->resource);
info->map.bankwidth = 2;
info->map.name = dev_name(&dev->dev);
info->map.read = ixp4xx_read16;
info->map.write = ixp4xx_probe_write16;
info->map.copy_from = ixp4xx_copy_from;
info->res = request_mem_region(dev->resource->start,
resource_size(dev->resource),
"IXP4XXFlash");
if (!info->res) {
printk(KERN_ERR "IXP4XXFlash: Could not reserve memory region\n");
err = -ENOMEM;
goto Error;
}
info->map.virt = ioremap(dev->resource->start,
resource_size(dev->resource));
if (!info->map.virt) {
printk(KERN_ERR "IXP4XXFlash: Failed to ioremap region\n");
err = -EIO;
goto Error;
}
info->mtd = do_map_probe(plat->map_name, &info->map);
if (!info->mtd) {
printk(KERN_ERR "IXP4XXFlash: map_probe failed\n");
err = -ENXIO;
goto Error;
}
info->mtd->owner = THIS_MODULE;
info->map.write = ixp4xx_write16;
err = mtd_device_parse_register(info->mtd, probes, &ppdata,
plat->parts, plat->nr_parts);
if (err) {
printk(KERN_ERR "Could not parse partitions\n");
goto Error;
}
return 0;
Error:
ixp4xx_flash_remove(dev);
return err;
}
