static map_word
ltq_read16(struct map_info *map, unsigned long adr)
{
unsigned long flags;
map_word temp;
if (map->map_priv_1 == LTQ_NOR_PROBING)
adr ^= 2;
spin_lock_irqsave(&ebu_lock, flags);
temp.x[0] = *(u16 *)(map->virt + adr);
spin_unlock_irqrestore(&ebu_lock, flags);
return temp;
}
static void
ltq_write16(struct map_info *map, map_word d, unsigned long adr)
{
unsigned long flags;
if (map->map_priv_1 == LTQ_NOR_PROBING)
adr ^= 2;
spin_lock_irqsave(&ebu_lock, flags);
*(u16 *)(map->virt + adr) = d.x[0];
spin_unlock_irqrestore(&ebu_lock, flags);
}
static void
ltq_copy_from(struct map_info *map, void *to,
unsigned long from, ssize_t len)
{
unsigned char *f = (unsigned char *)map->virt + from;
unsigned char *t = (unsigned char *)to;
unsigned long flags;
spin_lock_irqsave(&ebu_lock, flags);
while (len--)
*t++ = *f++;
spin_unlock_irqrestore(&ebu_lock, flags);
}
static void
ltq_copy_to(struct map_info *map, unsigned long to,
const void *from, ssize_t len)
{
unsigned char *f = (unsigned char *)from;
unsigned char *t = (unsigned char *)map->virt + to;
unsigned long flags;
spin_lock_irqsave(&ebu_lock, flags);
while (len--)
*t++ = *f++;
spin_unlock_irqrestore(&ebu_lock, flags);
}
static int __init
ltq_mtd_probe(struct platform_device *pdev)
{
struct physmap_flash_data *ltq_mtd_data = dev_get_platdata(&pdev->dev);
struct ltq_mtd *ltq_mtd;
struct resource *res;
struct cfi_private *cfi;
int err;
ltq_mtd = kzalloc(sizeof(struct ltq_mtd), GFP_KERNEL);
platform_set_drvdata(pdev, ltq_mtd);
ltq_mtd->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!ltq_mtd->res) {
dev_err(&pdev->dev, "failed to get memory resource");
err = -ENOENT;
goto err_out;
}
res = devm_request_mem_region(&pdev->dev, ltq_mtd->res->start,
resource_size(ltq_mtd->res), dev_name(&pdev->dev));
if (!ltq_mtd->res) {
dev_err(&pdev->dev, "failed to request mem resource");
err = -EBUSY;
goto err_out;
}
ltq_mtd->map = kzalloc(sizeof(struct map_info), GFP_KERNEL);
ltq_mtd->map->phys = res->start;
ltq_mtd->map->size = resource_size(res);
ltq_mtd->map->virt = devm_ioremap_nocache(&pdev->dev,
ltq_mtd->map->phys, ltq_mtd->map->size);
if (!ltq_mtd->map->virt) {
dev_err(&pdev->dev, "failed to ioremap!\n");
err = -ENOMEM;
goto err_free;
}
ltq_mtd->map->name = ltq_map_name;
ltq_mtd->map->bankwidth = 2;
ltq_mtd->map->read = ltq_read16;
ltq_mtd->map->write = ltq_write16;
ltq_mtd->map->copy_from = ltq_copy_from;
ltq_mtd->map->copy_to = ltq_copy_to;
ltq_mtd->map->map_priv_1 = LTQ_NOR_PROBING;
ltq_mtd->mtd = do_map_probe("cfi_probe", ltq_mtd->map);
ltq_mtd->map->map_priv_1 = LTQ_NOR_NORMAL;
if (!ltq_mtd->mtd) {
dev_err(&pdev->dev, "probing failed\n");
err = -ENXIO;
goto err_free;
}
ltq_mtd->mtd->owner = THIS_MODULE;
cfi = ltq_mtd->map->fldrv_priv;
cfi->addr_unlock1 ^= 1;
cfi->addr_unlock2 ^= 1;
err = mtd_device_parse_register(ltq_mtd->mtd, ltq_probe_types, NULL,
ltq_mtd_data->parts,
ltq_mtd_data->nr_parts);
if (err) {
dev_err(&pdev->dev, "failed to add partitions\n");
goto err_destroy;
}
return 0;
err_destroy:
map_destroy(ltq_mtd->mtd);
err_free:
kfree(ltq_mtd->map);
err_out:
kfree(ltq_mtd);
return err;
}
static int __devexit
ltq_mtd_remove(struct platform_device *pdev)
{
struct ltq_mtd *ltq_mtd = platform_get_drvdata(pdev);
if (ltq_mtd) {
if (ltq_mtd->mtd) {
mtd_device_unregister(ltq_mtd->mtd);
map_destroy(ltq_mtd->mtd);
}
kfree(ltq_mtd->map);
kfree(ltq_mtd);
}
return 0;
}
static int __init
init_ltq_mtd(void)
{
int ret = platform_driver_probe(&ltq_mtd_driver, ltq_mtd_probe);
if (ret)
pr_err("ltq_nor: error registering platform driver");
return ret;
}
static void __exit
exit_ltq_mtd(void)
{
platform_driver_unregister(&ltq_mtd_driver);
}
