static void sa1100_set_vpp(struct map_info *map, int on)
{
struct sa_subdev_info *subdev = container_of(map, struct sa_subdev_info, map);
unsigned long flags;
spin_lock_irqsave(&sa1100_vpp_lock, flags);
if (on) {
if (++sa1100_vpp_refcnt == 1)
subdev->plat->set_vpp(1);
} else {
if (--sa1100_vpp_refcnt == 0)
subdev->plat->set_vpp(0);
}
spin_unlock_irqrestore(&sa1100_vpp_lock, flags);
}
static void sa1100_destroy_subdev(struct sa_subdev_info *subdev)
{
if (subdev->mtd)
map_destroy(subdev->mtd);
if (subdev->map.virt)
iounmap(subdev->map.virt);
release_mem_region(subdev->map.phys, subdev->map.size);
}
static int sa1100_probe_subdev(struct sa_subdev_info *subdev, struct resource *res)
{
unsigned long phys;
unsigned int size;
int ret;
phys = res->start;
size = res->end - phys + 1;
switch (phys) {
default:
printk(KERN_WARNING "SA1100 flash: unknown base address "
"0x%08lx, assuming CS0\n", phys);
case SA1100_CS0_PHYS:
subdev->map.bankwidth = (MSC0 & MSC_RBW) ? 2 : 4;
break;
case SA1100_CS1_PHYS:
subdev->map.bankwidth = ((MSC0 >> 16) & MSC_RBW) ? 2 : 4;
break;
}
if (!request_mem_region(phys, size, subdev->name)) {
ret = -EBUSY;
goto out;
}
if (subdev->plat->set_vpp)
subdev->map.set_vpp = sa1100_set_vpp;
subdev->map.phys = phys;
subdev->map.size = size;
subdev->map.virt = ioremap(phys, size);
if (!subdev->map.virt) {
ret = -ENOMEM;
goto err;
}
simple_map_init(&subdev->map);
subdev->mtd = do_map_probe(subdev->plat->map_name, &subdev->map);
if (subdev->mtd == NULL) {
ret = -ENXIO;
goto err;
}
subdev->mtd->owner = THIS_MODULE;
printk(KERN_INFO "SA1100 flash: CFI device at 0x%08lx, %uMiB, %d-bit\n",
phys, (unsigned)(subdev->mtd->size >> 20),
subdev->map.bankwidth * 8);
return 0;
err:
sa1100_destroy_subdev(subdev);
out:
return ret;
}
static void sa1100_destroy(struct sa_info *info, struct flash_platform_data *plat)
{
int i;
if (info->mtd) {
mtd_device_unregister(info->mtd);
if (info->mtd != info->subdev[0].mtd)
mtd_concat_destroy(info->mtd);
}
for (i = info->num_subdev - 1; i >= 0; i--)
sa1100_destroy_subdev(&info->subdev[i]);
kfree(info);
if (plat->exit)
plat->exit();
}
static struct sa_info *sa1100_setup_mtd(struct platform_device *pdev,
struct flash_platform_data *plat)
{
struct sa_info *info;
int nr, size, i, ret = 0;
for (nr = 0; ; nr++)
if (!platform_get_resource(pdev, IORESOURCE_MEM, nr))
break;
if (nr == 0) {
ret = -ENODEV;
goto out;
}
size = sizeof(struct sa_info) + sizeof(struct sa_subdev_info) * nr;
info = kzalloc(size, GFP_KERNEL);
if (!info) {
ret = -ENOMEM;
goto out;
}
if (plat->init) {
ret = plat->init();
if (ret)
goto err;
}
for (i = 0; i < nr; i++) {
struct sa_subdev_info *subdev = &info->subdev[i];
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
break;
subdev->map.name = subdev->name;
sprintf(subdev->name, "%s-%d", plat->name, i);
subdev->plat = plat;
ret = sa1100_probe_subdev(subdev, res);
if (ret)
break;
}
info->num_subdev = i;
if (ret != 0 && !(ret == -ENXIO && info->num_subdev > 0))
goto err;
if (info->num_subdev == 1) {
strcpy(info->subdev[0].name, plat->name);
info->mtd = info->subdev[0].mtd;
ret = 0;
} else if (info->num_subdev > 1) {
struct mtd_info *cdev[nr];
for (i = 0; i < info->num_subdev; i++)
cdev[i] = info->subdev[i].mtd;
info->mtd = mtd_concat_create(cdev, info->num_subdev,
plat->name);
if (info->mtd == NULL)
ret = -ENXIO;
}
if (ret == 0)
return info;
err:
sa1100_destroy(info, plat);
out:
return ERR_PTR(ret);
}
static int sa1100_mtd_probe(struct platform_device *pdev)
{
struct flash_platform_data *plat = dev_get_platdata(&pdev->dev);
struct sa_info *info;
int err;
if (!plat)
return -ENODEV;
info = sa1100_setup_mtd(pdev, plat);
if (IS_ERR(info)) {
err = PTR_ERR(info);
goto out;
}
mtd_device_parse_register(info->mtd, part_probes, NULL, plat->parts,
plat->nr_parts);
platform_set_drvdata(pdev, info);
err = 0;
out:
return err;
}
static int sa1100_mtd_remove(struct platform_device *pdev)
{
struct sa_info *info = platform_get_drvdata(pdev);
struct flash_platform_data *plat = dev_get_platdata(&pdev->dev);
sa1100_destroy(info, plat);
return 0;
}
