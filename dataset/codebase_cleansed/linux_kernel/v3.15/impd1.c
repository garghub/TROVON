void impd1_tweak_control(struct device *dev, u32 mask, u32 val)
{
struct impd1_module *impd1 = dev_get_drvdata(dev);
u32 cur;
val &= mask;
cur = readl(impd1->base + IMPD1_CTRL) & ~mask;
writel(cur | val, impd1->base + IMPD1_CTRL);
}
static void impd1fb_clcd_disable(struct clcd_fb *fb)
{
impd1_tweak_control(fb->dev->dev.parent, IMPD1_CTRL_DISP_MASK, 0);
}
static void impd1fb_clcd_enable(struct clcd_fb *fb)
{
impd1_tweak_control(fb->dev->dev.parent, IMPD1_CTRL_DISP_MASK,
fb->panel->connector | IMPD1_CTRL_DISP_ENABLE);
}
static int impd1fb_clcd_setup(struct clcd_fb *fb)
{
unsigned long framebase = fb->dev->res.start + 0x01000000;
unsigned long framesize = SZ_1M;
int ret = 0;
fb->panel = &PANELTYPE;
if (!request_mem_region(framebase, framesize, "clcd framebuffer")) {
printk(KERN_ERR "IM-PD1: unable to reserve framebuffer\n");
return -EBUSY;
}
fb->fb.screen_base = ioremap(framebase, framesize);
if (!fb->fb.screen_base) {
printk(KERN_ERR "IM-PD1: unable to map framebuffer\n");
ret = -ENOMEM;
goto free_buffer;
}
fb->fb.fix.smem_start = framebase;
fb->fb.fix.smem_len = framesize;
return 0;
free_buffer:
release_mem_region(framebase, framesize);
return ret;
}
static int impd1fb_clcd_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
unsigned long start, size;
start = vma->vm_pgoff + (fb->fb.fix.smem_start >> PAGE_SHIFT);
size = vma->vm_end - vma->vm_start;
return remap_pfn_range(vma, vma->vm_start, start, size,
vma->vm_page_prot);
}
static void impd1fb_clcd_remove(struct clcd_fb *fb)
{
iounmap(fb->fb.screen_base);
release_mem_region(fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}
static int __init impd1_probe(struct lm_device *dev)
{
struct impd1_module *impd1;
int irq_base;
int i;
if (dev->id != module_id)
return -EINVAL;
if (!devm_request_mem_region(&dev->dev, dev->resource.start,
SZ_4K, "LM registers"))
return -EBUSY;
impd1 = devm_kzalloc(&dev->dev, sizeof(struct impd1_module),
GFP_KERNEL);
if (!impd1)
return -ENOMEM;
impd1->base = devm_ioremap(&dev->dev, dev->resource.start, SZ_4K);
if (!impd1->base)
return -ENOMEM;
integrator_impd1_clk_init(impd1->base, dev->id);
if (!devm_request_mem_region(&dev->dev,
dev->resource.start + 0x03000000,
SZ_4K, "VIC"))
return -EBUSY;
impd1->vic_base = devm_ioremap(&dev->dev,
dev->resource.start + 0x03000000,
SZ_4K);
if (!impd1->vic_base)
return -ENOMEM;
irq_base = vic_init_cascaded(impd1->vic_base, dev->irq,
IMPD1_VALID_IRQS, 0);
lm_set_drvdata(dev, impd1);
dev_info(&dev->dev, "IM-PD1 found at 0x%08lx\n",
(unsigned long)dev->resource.start);
for (i = 0; i < ARRAY_SIZE(impd1_devs); i++) {
struct impd1_device *idev = impd1_devs + i;
struct amba_device *d;
unsigned long pc_base;
char devname[32];
int irq1 = idev->irq[0];
int irq2 = idev->irq[1];
if (irq1)
irq1 += irq_base;
if (irq2)
irq2 += irq_base;
pc_base = dev->resource.start + idev->offset;
snprintf(devname, 32, "lm%x:%5.5lx", dev->id, idev->offset >> 12);
d = amba_ahb_device_add_res(&dev->dev, devname, pc_base, SZ_4K,
irq1, irq2,
idev->platform_data, idev->id,
&dev->resource);
if (IS_ERR(d)) {
dev_err(&dev->dev, "unable to register device: %ld\n", PTR_ERR(d));
continue;
}
}
return 0;
}
static int impd1_remove_one(struct device *dev, void *data)
{
device_unregister(dev);
return 0;
}
static void impd1_remove(struct lm_device *dev)
{
device_for_each_child(&dev->dev, NULL, impd1_remove_one);
integrator_impd1_clk_exit(dev->id);
lm_set_drvdata(dev, NULL);
}
static int __init impd1_init(void)
{
return lm_driver_register(&impd1_driver);
}
static void __exit impd1_exit(void)
{
lm_driver_unregister(&impd1_driver);
}
