static void xilinx_fb_out_be32(struct xilinxfb_drvdata *drvdata, u32 offset,
u32 val)
{
if (drvdata->flags & PLB_ACCESS_FLAG)
out_be32(drvdata->regs + (offset << 2), val);
#ifdef CONFIG_PPC_DCR
else
dcr_write(drvdata->dcr_host, offset, val);
#endif
}
static int
xilinx_fb_setcolreg(unsigned regno, unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *fbi)
{
u32 *palette = fbi->pseudo_palette;
if (regno >= PALETTE_ENTRIES_NO)
return -EINVAL;
if (fbi->var.grayscale) {
red = green = blue =
(red * 77 + green * 151 + blue * 28 + 127) >> 8;
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
xilinx_fb_out_be32(drvdata, REG_CTRL, drvdata->reg_ctrl_default);
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
xilinx_fb_out_be32(drvdata, REG_CTRL, 0);
default:
break;
}
return 0;
}
static int xilinxfb_assign(struct device *dev,
struct xilinxfb_drvdata *drvdata,
unsigned long physaddr,
struct xilinxfb_platform_data *pdata)
{
int rc;
int fbsize = pdata->xvirt * pdata->yvirt * BYTES_PER_PIXEL;
if (drvdata->flags & PLB_ACCESS_FLAG) {
if (!request_mem_region(physaddr, 8, DRIVER_NAME)) {
dev_err(dev, "Couldn't lock memory region at 0x%08lX\n",
physaddr);
rc = -ENODEV;
goto err_region;
}
drvdata->regs_phys = physaddr;
drvdata->regs = ioremap(physaddr, 8);
if (!drvdata->regs) {
dev_err(dev, "Couldn't lock memory region at 0x%08lX\n",
physaddr);
rc = -ENODEV;
goto err_map;
}
}
if (pdata->fb_phys) {
drvdata->fb_phys = pdata->fb_phys;
drvdata->fb_virt = ioremap(pdata->fb_phys, fbsize);
} else {
drvdata->fb_alloced = 1;
drvdata->fb_virt = dma_alloc_coherent(dev, PAGE_ALIGN(fbsize),
&drvdata->fb_phys, GFP_KERNEL);
}
if (!drvdata->fb_virt) {
dev_err(dev, "Could not allocate frame buffer memory\n");
rc = -ENOMEM;
if (drvdata->flags & PLB_ACCESS_FLAG)
goto err_fbmem;
else
goto err_region;
}
memset_io((void __iomem *)drvdata->fb_virt, 0, fbsize);
xilinx_fb_out_be32(drvdata, REG_FB_ADDR, drvdata->fb_phys);
drvdata->reg_ctrl_default = REG_CTRL_ENABLE;
if (pdata->rotate_screen)
drvdata->reg_ctrl_default |= REG_CTRL_ROTATE;
xilinx_fb_out_be32(drvdata, REG_CTRL,
drvdata->reg_ctrl_default);
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
if (drvdata->flags & PLB_ACCESS_FLAG) {
dev_dbg(dev, "regs: phys=%lx, virt=%p\n", physaddr,
drvdata->regs);
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
xilinx_fb_out_be32(drvdata, REG_CTRL, 0);
err_fbmem:
if (drvdata->flags & PLB_ACCESS_FLAG)
iounmap(drvdata->regs);
err_map:
if (drvdata->flags & PLB_ACCESS_FLAG)
release_mem_region(physaddr, 8);
err_region:
kfree(drvdata);
dev_set_drvdata(dev, NULL);
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
xilinx_fb_out_be32(drvdata, REG_CTRL, 0);
if (drvdata->flags & PLB_ACCESS_FLAG) {
iounmap(drvdata->regs);
release_mem_region(drvdata->regs_phys, 8);
}
#ifdef CONFIG_PPC_DCR
else
dcr_unmap(drvdata->dcr_host, drvdata->dcr_len);
#endif
kfree(drvdata);
dev_set_drvdata(dev, NULL);
return 0;
}
static int xilinxfb_of_probe(struct platform_device *op)
{
const u32 *prop;
u32 *p;
u32 tft_access;
struct xilinxfb_platform_data pdata;
struct resource res;
int size, rc;
struct xilinxfb_drvdata *drvdata;
pdata = xilinx_fb_default_pdata;
drvdata = kzalloc(sizeof(*drvdata), GFP_KERNEL);
if (!drvdata) {
dev_err(&op->dev, "Couldn't allocate device private record\n");
return -ENOMEM;
}
p = (u32 *)of_get_property(op->dev.of_node, "xlnx,dcr-splb-slave-if", NULL);
tft_access = p ? *p : 0;
if (tft_access) {
drvdata->flags |= PLB_ACCESS_FLAG;
rc = of_address_to_resource(op->dev.of_node, 0, &res);
if (rc) {
dev_err(&op->dev, "invalid address\n");
goto err;
}
}
#ifdef CONFIG_PPC_DCR
else {
int start;
res.start = 0;
start = dcr_resource_start(op->dev.of_node, 0);
drvdata->dcr_len = dcr_resource_len(op->dev.of_node, 0);
drvdata->dcr_host = dcr_map(op->dev.of_node, start, drvdata->dcr_len);
if (!DCR_MAP_OK(drvdata->dcr_host)) {
dev_err(&op->dev, "invalid DCR address\n");
goto err;
}
}
#endif
prop = of_get_property(op->dev.of_node, "phys-size", &size);
if ((prop) && (size >= sizeof(u32)*2)) {
pdata.screen_width_mm = prop[0];
pdata.screen_height_mm = prop[1];
}
prop = of_get_property(op->dev.of_node, "resolution", &size);
if ((prop) && (size >= sizeof(u32)*2)) {
pdata.xres = prop[0];
pdata.yres = prop[1];
}
prop = of_get_property(op->dev.of_node, "virtual-resolution", &size);
if ((prop) && (size >= sizeof(u32)*2)) {
pdata.xvirt = prop[0];
pdata.yvirt = prop[1];
}
if (of_find_property(op->dev.of_node, "rotate-display", NULL))
pdata.rotate_screen = 1;
dev_set_drvdata(&op->dev, drvdata);
return xilinxfb_assign(&op->dev, drvdata, res.start, &pdata);
err:
kfree(drvdata);
return -ENODEV;
}
static int xilinxfb_of_remove(struct platform_device *op)
{
return xilinxfb_release(&op->dev);
}
