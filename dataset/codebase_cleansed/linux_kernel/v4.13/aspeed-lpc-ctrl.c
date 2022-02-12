static struct aspeed_lpc_ctrl *file_aspeed_lpc_ctrl(struct file *file)
{
return container_of(file->private_data, struct aspeed_lpc_ctrl,
miscdev);
}
static int aspeed_lpc_ctrl_mmap(struct file *file, struct vm_area_struct *vma)
{
struct aspeed_lpc_ctrl *lpc_ctrl = file_aspeed_lpc_ctrl(file);
unsigned long vsize = vma->vm_end - vma->vm_start;
pgprot_t prot = vma->vm_page_prot;
if (vma->vm_pgoff + vsize > lpc_ctrl->mem_base + lpc_ctrl->mem_size)
return -EINVAL;
prot = pgprot_noncached(prot);
if (remap_pfn_range(vma, vma->vm_start,
(lpc_ctrl->mem_base >> PAGE_SHIFT) + vma->vm_pgoff,
vsize, prot))
return -EAGAIN;
return 0;
}
static long aspeed_lpc_ctrl_ioctl(struct file *file, unsigned int cmd,
unsigned long param)
{
struct aspeed_lpc_ctrl *lpc_ctrl = file_aspeed_lpc_ctrl(file);
void __user *p = (void __user *)param;
struct aspeed_lpc_ctrl_mapping map;
u32 addr;
u32 size;
long rc;
if (copy_from_user(&map, p, sizeof(map)))
return -EFAULT;
if (map.flags != 0)
return -EINVAL;
switch (cmd) {
case ASPEED_LPC_CTRL_IOCTL_GET_SIZE:
if (map.window_type != ASPEED_LPC_CTRL_WINDOW_MEMORY)
return -EINVAL;
if (map.window_id != 0)
return -EINVAL;
map.size = lpc_ctrl->mem_size;
return copy_to_user(p, &map, sizeof(map)) ? -EFAULT : 0;
case ASPEED_LPC_CTRL_IOCTL_MAP:
if ((map.size & 0x0000ffff) || (map.offset & 0x0000ffff))
return -EINVAL;
if (map.offset & (map.size - 1))
return -EINVAL;
if (map.window_type == ASPEED_LPC_CTRL_WINDOW_FLASH) {
addr = lpc_ctrl->pnor_base;
size = lpc_ctrl->pnor_size;
} else if (map.window_type == ASPEED_LPC_CTRL_WINDOW_MEMORY) {
addr = lpc_ctrl->mem_base;
size = lpc_ctrl->mem_size;
} else {
return -EINVAL;
}
if (map.offset + map.size < map.offset ||
map.offset + map.size > size)
return -EINVAL;
if (map.size == 0 || map.size > size)
return -EINVAL;
addr += map.offset;
rc = regmap_write(lpc_ctrl->regmap, HICR7,
(addr | (map.addr >> 16)));
if (rc)
return rc;
return regmap_write(lpc_ctrl->regmap, HICR8,
(~(map.size - 1)) | ((map.size >> 16) - 1));
}
return -EINVAL;
}
static int aspeed_lpc_ctrl_probe(struct platform_device *pdev)
{
struct aspeed_lpc_ctrl *lpc_ctrl;
struct device_node *node;
struct resource resm;
struct device *dev;
int rc;
dev = &pdev->dev;
lpc_ctrl = devm_kzalloc(dev, sizeof(*lpc_ctrl), GFP_KERNEL);
if (!lpc_ctrl)
return -ENOMEM;
node = of_parse_phandle(dev->of_node, "flash", 0);
if (!node) {
dev_err(dev, "Didn't find host pnor flash node\n");
return -ENODEV;
}
rc = of_address_to_resource(node, 1, &resm);
of_node_put(node);
if (rc) {
dev_err(dev, "Couldn't address to resource for flash\n");
return rc;
}
lpc_ctrl->pnor_size = resource_size(&resm);
lpc_ctrl->pnor_base = resm.start;
dev_set_drvdata(&pdev->dev, lpc_ctrl);
node = of_parse_phandle(dev->of_node, "memory-region", 0);
if (!node) {
dev_err(dev, "Didn't find reserved memory\n");
return -EINVAL;
}
rc = of_address_to_resource(node, 0, &resm);
of_node_put(node);
if (rc) {
dev_err(dev, "Couldn't address to resource for reserved memory\n");
return -ENOMEM;
}
lpc_ctrl->mem_size = resource_size(&resm);
lpc_ctrl->mem_base = resm.start;
lpc_ctrl->regmap = syscon_node_to_regmap(
pdev->dev.parent->of_node);
if (IS_ERR(lpc_ctrl->regmap)) {
dev_err(dev, "Couldn't get regmap\n");
return -ENODEV;
}
lpc_ctrl->miscdev.minor = MISC_DYNAMIC_MINOR;
lpc_ctrl->miscdev.name = DEVICE_NAME;
lpc_ctrl->miscdev.fops = &aspeed_lpc_ctrl_fops;
lpc_ctrl->miscdev.parent = dev;
rc = misc_register(&lpc_ctrl->miscdev);
if (rc)
dev_err(dev, "Unable to register device\n");
else
dev_info(dev, "Loaded at %pr\n", &resm);
return rc;
}
static int aspeed_lpc_ctrl_remove(struct platform_device *pdev)
{
struct aspeed_lpc_ctrl *lpc_ctrl = dev_get_drvdata(&pdev->dev);
misc_deregister(&lpc_ctrl->miscdev);
return 0;
}
