int nspire_clcd_setup(struct clcd_fb *fb)
{
struct clcd_panel *panel;
size_t panel_size;
const char *type;
dma_addr_t dma;
int err;
BUG_ON(!fb->dev->dev.of_node);
err = of_property_read_string(fb->dev->dev.of_node, "lcd-type", &type);
if (err) {
pr_err("CLCD: Could not find lcd-type property\n");
return err;
}
if (!strcmp(type, "cx")) {
panel = &nspire_cx_lcd_panel;
} else if (!strcmp(type, "classic")) {
panel = &nspire_classic_lcd_panel;
} else {
pr_err("CLCD: Unknown lcd-type %s\n", type);
return -EINVAL;
}
panel_size = ((panel->mode.xres * panel->mode.yres) * panel->bpp) / 8;
panel_size = ALIGN(panel_size, PAGE_SIZE);
fb->fb.screen_base = dma_alloc_writecombine(&fb->dev->dev,
panel_size, &dma, GFP_KERNEL);
if (!fb->fb.screen_base) {
pr_err("CLCD: unable to map framebuffer\n");
return -ENOMEM;
}
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = panel_size;
fb->panel = panel;
return 0;
}
int nspire_clcd_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_writecombine(&fb->dev->dev, vma,
fb->fb.screen_base, fb->fb.fix.smem_start,
fb->fb.fix.smem_len);
}
void nspire_clcd_remove(struct clcd_fb *fb)
{
dma_free_writecombine(&fb->dev->dev, fb->fb.fix.smem_len,
fb->fb.screen_base, fb->fb.fix.smem_start);
}
