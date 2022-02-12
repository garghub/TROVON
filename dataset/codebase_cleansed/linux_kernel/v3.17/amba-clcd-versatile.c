struct clcd_panel *versatile_clcd_get_panel(const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(panels); i++)
if (strcmp(panels[i]->mode.name, name) == 0)
break;
if (i < ARRAY_SIZE(panels))
return panels[i];
pr_err("CLCD: couldn't get parameters for panel %s\n", name);
return NULL;
}
int versatile_clcd_setup_dma(struct clcd_fb *fb, unsigned long framesize)
{
dma_addr_t dma;
fb->fb.screen_base = dma_alloc_writecombine(&fb->dev->dev, framesize,
&dma, GFP_KERNEL);
if (!fb->fb.screen_base) {
pr_err("CLCD: unable to map framebuffer\n");
return -ENOMEM;
}
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = framesize;
return 0;
}
int versatile_clcd_mmap_dma(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_writecombine(&fb->dev->dev, vma,
fb->fb.screen_base,
fb->fb.fix.smem_start,
fb->fb.fix.smem_len);
}
void versatile_clcd_remove_dma(struct clcd_fb *fb)
{
dma_free_writecombine(&fb->dev->dev, fb->fb.fix.smem_len,
fb->fb.screen_base, fb->fb.fix.smem_start);
}
