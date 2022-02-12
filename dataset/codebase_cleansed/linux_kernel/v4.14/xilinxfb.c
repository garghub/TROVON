static void xilinx_fb_out32(struct xilinxfb_drvdata *drvdata, u32 offset,
u32 val)
{
if (drvdata->flags & BUS_ACCESS_FLAG) {
if (drvdata->flags & LITTLE_ENDIAN_ACCESS)
iowrite32(val, drvdata->regs + (offset << 2));
else
iowrite32be(val, drvdata->regs + (offset << 2));
}
#ifdef CONFIG_PPC_DCR
else
dcr_write(drvdata->dcr_host, offset, val);
#endif
}
static u32 xilinx_fb_in32(struct xilinxfb_drvdata *drvdata, u32 offset)
{
if (drvdata->flags & BUS_ACCESS_FLAG) {
if (drvdata->flags & LITTLE_ENDIAN_ACCESS)
return ioread32(drvdata->regs + (offset << 2));
else
return ioread32be(drvdata->regs + (offset << 2));
}
#ifdef CONFIG_PPC_DCR
else
return dcr_read(drvdata->dcr_host, offset);
#endif
return 0;
}
static int
xilinx_fb_setcolreg(unsigned int regno, unsigned int red, unsigned int green,
unsigned int blue, unsigned int transp, struct fb_info *fbi)
{
u32 *palette = fbi->pseudo_palette;
if (regno >= PALETTE_ENTRIES_NO)
return -EINVAL;
if (fbi->var.grayscale) {
blue = (red * 77 + green * 151 + blue * 28 + 127) >> 8;
green = blue;
red = green;
}
red >>= 8;
green >>= 8;
blue >>= 8;
palette[regno] = (red << RED_SHIFT) | (green << GREEN_SHIFT) |
(blue << BLUE_SHIFT);
return 0;
}
static int
xilinx_fb_blank(int blank_mode, struct fb_info *fbi)
{
struct xilinxfb_drvdata *drvdata = to_xilinxfb_drvdata(fbi);
switch (blank_mode) {
case FB_BLANK_UNBLANK:
xilinx_fb_out32(drvdata, REG_CTRL, drvdata->reg_ctrl_default);
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
xilinx_fb_out32(drvdata, REG_CTRL, 0);
default:
break;
}
return 0;
}
static int xilinxfb_assign(struct platform_device *pdev,
struct xilinxfb_drvdata *drvdata,
struct xilinxfb_platform_data *pdata)
{
int rc;
struct device *dev = &pdev->dev;
int fbsize = pdata->xvirt * pdata->yvirt * BYTES_PER_PIXEL;
if (drvdata->flags & BUS_ACCESS_FLAG) {
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
drvdata->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(drvdata->regs))
return PTR_ERR(drvdata->regs);
drvdata->regs_phys = res->start;
}
if (pdata->fb_phys) {
drvdata->fb_phys = pdata->fb_phys;
drvdata->fb_virt = ioremap(pdata->fb_phys, fbsize);
} else {
drvdata->fb_alloced = 1;
drvdata->fb_virt = dma_alloc_coherent(dev, PAGE_ALIGN(fbsize),
&drvdata->fb_phys,
GFP_KERNEL);
}
if (!drvdata->fb_virt) {
dev_err(dev, "Could not allocate frame buffer memory\n");
return -ENOMEM;
}
memset_io((void __iomem *)drvdata->fb_virt, 0, fbsize);
xilinx_fb_out32(drvdata, REG_FB_ADDR, drvdata->fb_phys);
rc = xilinx_fb_in32(drvdata, REG_FB_ADDR);
if (rc != drvdata->fb_phys) {
drvdata->flags |= LITTLE_ENDIAN_ACCESS;
xilinx_fb_out32(drvdata, REG_FB_ADDR, drvdata->fb_phys);
}
drvdata->reg_ctrl_default = REG_CTRL_ENABLE;
if (pdata->rotate_screen)
drvdata->reg_ctrl_default |= REG_CTRL_ROTATE;
xilinx_fb_out32(drvdata, REG_CTRL, drvdata->reg_ctrl_default);
drvdata->info.device = dev;
drvdata->info.screen_base = (void __iomem *)drvdata->fb_virt;
drvdata->info.fbops = &xilinxfb_ops;
drvdata->info.fix = xilinx_fb_fix;
drvdata->info.fix.smem_start = drvdata->fb_phys;
drvdata->info.fix.smem_len = fbsize;
drvdata->info.fix.line_length = pdata->xvirt * BYTES_PER_PIXEL;
drvdata->info.pseudo_palette = drvdata->pseudo_palette;
drvdata->info.flags = FBINFO_DEFAULT;
drvdata->info.var = xilinx_fb_var;
drvdata->info.var.height = pdata->screen_height_mm;
drvdata->info.var.width = pdata->screen_width_mm;
drvdata->info.var.xres = pdata->xres;
drvdata->info.var.yres = pdata->yres;
drvdata->info.var.xres_virtual = pdata->xvirt;
drvdata->info.var.yres_virtual = pdata->yvirt;
rc = fb_alloc_cmap(&drvdata->info.cmap, PALETTE_ENTRIES_NO, 0);
if (rc) {
dev_err(dev, "Fail to allocate colormap (%d entries)\n",
PALETTE_ENTRIES_NO);
goto err_cmap;
}
rc = register_framebuffer(&drvdata->info);
if (rc) {
dev_err(dev, "Could not register frame buffer\n");
goto err_regfb;
}
if (drvdata->flags & BUS_ACCESS_FLAG) {
dev_dbg(dev, "regs: phys=%pa, virt=%p\n",
&drvdata->regs_phys, drvdata->regs);
}
dev_dbg(dev, "fb: phys=%llx, virt=%p, size=%x\n",
(unsigned long long)drvdata->fb_phys, drvdata->fb_virt, fbsize);
return 0;
err_regfb:
fb_dealloc_cmap(&drvdata->info.cmap);
err_cmap:
if (drvdata->fb_alloced)
dma_free_coherent(dev, PAGE_ALIGN(fbsize), drvdata->fb_virt,
drvdata->fb_phys);
else
iounmap(drvdata->fb_virt);
xilinx_fb_out32(drvdata, REG_CTRL, 0);
return rc;
}
static int xilinxfb_release(struct device *dev)
{
struct xilinxfb_drvdata *drvdata = dev_get_drvdata(dev);
#if !defined(CONFIG_FRAMEBUFFER_CONSOLE) && defined(CONFIG_LOGO)
xilinx_fb_blank(VESA_POWERDOWN, &drvdata->info);
#endif
unregister_framebuffer(&drvdata->info);
fb_dealloc_cmap(&drvdata->info.cmap);
if (drvdata->fb_alloced)
dma_free_coherent(dev, PAGE_ALIGN(drvdata->info.fix.smem_len),
drvdata->fb_virt, drvdata->fb_phys);
else
iounmap(drvdata->fb_virt);
xilinx_fb_out32(drvdata, REG_CTRL, 0);
#ifdef CONFIG_PPC_DCR
if (!(drvdata->flags & BUS_ACCESS_FLAG))
dcr_unmap(drvdata->dcr_host, drvdata->dcr_len);
#endif
return 0;
}
static int xilinxfb_of_probe(struct platform_device *pdev)
{
const u32 *prop;
u32 tft_access = 0;
struct xilinxfb_platform_data pdata;
int size;
struct xilinxfb_drvdata *drvdata;
pdata = xilinx_fb_default_pdata;
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
of_property_read_u32(pdev->dev.of_node, "xlnx,dcr-splb-slave-if",
&tft_access);
if (tft_access)
drvdata->flags |= BUS_ACCESS_FLAG;
#ifdef CONFIG_PPC_DCR
else {
int start;
start = dcr_resource_start(pdev->dev.of_node, 0);
drvdata->dcr_len = dcr_resource_len(pdev->dev.of_node, 0);
drvdata->dcr_host = dcr_map(pdev->dev.of_node, start, drvdata->dcr_len);
if (!DCR_MAP_OK(drvdata->dcr_host)) {
dev_err(&pdev->dev, "invalid DCR address\n");
return -ENODEV;
}
}
#endif
prop = of_get_property(pdev->dev.of_node, "phys-size", &size);
if ((prop) && (size >= sizeof(u32) * 2)) {
pdata.screen_width_mm = prop[0];
pdata.screen_height_mm = prop[1];
}
prop = of_get_property(pdev->dev.of_node, "resolution", &size);
if ((prop) && (size >= sizeof(u32) * 2)) {
pdata.xres = prop[0];
pdata.yres = prop[1];
}
prop = of_get_property(pdev->dev.of_node, "virtual-resolution", &size);
if ((prop) && (size >= sizeof(u32) * 2)) {
pdata.xvirt = prop[0];
pdata.yvirt = prop[1];
}
if (of_find_property(pdev->dev.of_node, "rotate-display", NULL))
pdata.rotate_screen = 1;
dev_set_drvdata(&pdev->dev, drvdata);
return xilinxfb_assign(pdev, drvdata, &pdata);
}
static int xilinxfb_of_remove(struct platform_device *op)
{
return xilinxfb_release(&op->dev);
}
