static int valkyriefb_set_par(struct fb_info *info)
{
struct fb_info_valkyrie *p =
container_of(info, struct fb_info_valkyrie, info);
volatile struct valkyrie_regs __iomem *valkyrie_regs = p->valkyrie_regs;
struct fb_par_valkyrie *par = info->par;
struct valkyrie_regvals *init;
int err;
if ((err = valkyrie_var_to_par(&info->var, par, info)))
return err;
valkyrie_par_to_fix(par, &info->fix);
out_8(&valkyrie_regs->status.r, 0);
udelay(100);
init = par->init;
out_8(&valkyrie_regs->mode.r, init->mode | 0x80);
out_8(&valkyrie_regs->depth.r, par->cmode + 3);
set_valkyrie_clock(init->clock_params);
udelay(100);
out_8(&valkyrie_regs->mode.r, init->mode);
return 0;
}
static inline int valkyrie_par_to_var(struct fb_par_valkyrie *par,
struct fb_var_screeninfo *var)
{
return mac_vmode_to_var(par->vmode, par->cmode, var);
}
static int
valkyriefb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
int err;
struct fb_par_valkyrie par;
if ((err = valkyrie_var_to_par(var, &par, info)))
return err;
valkyrie_par_to_var(&par, var);
return 0;
}
static int valkyriefb_blank(int blank_mode, struct fb_info *info)
{
struct fb_info_valkyrie *p =
container_of(info, struct fb_info_valkyrie, info);
struct fb_par_valkyrie *par = info->par;
struct valkyrie_regvals *init = par->init;
if (init == NULL)
return 1;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
out_8(&p->valkyrie_regs->mode.r, init->mode);
break;
case FB_BLANK_NORMAL:
return 1;
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
out_8(&p->valkyrie_regs->mode.r, init->mode | 0x40);
break;
case FB_BLANK_POWERDOWN:
out_8(&p->valkyrie_regs->mode.r, 0x66);
break;
}
return 0;
}
static int valkyriefb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct fb_info_valkyrie *p =
container_of(info, struct fb_info_valkyrie, info);
volatile struct cmap_regs __iomem *cmap_regs = p->cmap_regs;
struct fb_par_valkyrie *par = info->par;
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
out_8(&p->cmap_regs->addr, regno);
udelay(1);
out_8(&cmap_regs->lut, red);
out_8(&cmap_regs->lut, green);
out_8(&cmap_regs->lut, blue);
if (regno < 16 && par->cmode == CMODE_16)
((u32 *)info->pseudo_palette)[regno] =
(regno << 10) | (regno << 5) | regno;
return 0;
}
static inline int valkyrie_vram_reqd(int video_mode, int color_mode)
{
int pitch;
struct valkyrie_regvals *init = valkyrie_reg_init[video_mode-1];
if ((pitch = init->pitch[color_mode]) == 0)
pitch = 2 * init->pitch[0];
return init->vres * pitch;
}
static void set_valkyrie_clock(unsigned char *params)
{
#ifdef CONFIG_ADB_CUDA
struct adb_request req;
int i;
for (i = 0; i < 3; ++i) {
cuda_request(&req, NULL, 5, CUDA_PACKET, CUDA_GET_SET_IIC,
0x50, i + 1, params[i]);
while (!req.complete)
cuda_poll();
}
#endif
}
static void __init valkyrie_choose_mode(struct fb_info_valkyrie *p)
{
p->sense = read_valkyrie_sense(p);
printk(KERN_INFO "Monitor sense value = 0x%x\n", p->sense);
#if !defined(CONFIG_MAC) && defined(CONFIG_NVRAM)
if (default_vmode == VMODE_NVRAM) {
default_vmode = nvram_read_byte(NV_VMODE);
if (default_vmode <= 0
|| default_vmode > VMODE_MAX
|| !valkyrie_reg_init[default_vmode - 1])
default_vmode = VMODE_CHOOSE;
}
#endif
if (default_vmode == VMODE_CHOOSE)
default_vmode = mac_map_monitor_sense(p->sense);
if (!valkyrie_reg_init[default_vmode - 1])
default_vmode = VMODE_640_480_67;
#if !defined(CONFIG_MAC) && defined(CONFIG_NVRAM)
if (default_cmode == CMODE_NVRAM)
default_cmode = nvram_read_byte(NV_CMODE);
#endif
if (default_cmode < CMODE_8 || default_cmode > CMODE_16
|| valkyrie_reg_init[default_vmode-1]->pitch[default_cmode] == 0
|| valkyrie_vram_reqd(default_vmode, default_cmode) > p->total_vram)
default_cmode = CMODE_8;
printk(KERN_INFO "using video mode %d and color mode %d.\n",
default_vmode, default_cmode);
}
int __init valkyriefb_init(void)
{
struct fb_info_valkyrie *p;
unsigned long frame_buffer_phys, cmap_regs_phys, flags;
int err;
char *option = NULL;
if (fb_get_options("valkyriefb", &option))
return -ENODEV;
valkyriefb_setup(option);
#ifdef CONFIG_MAC
if (!MACH_IS_MAC)
return -ENODEV;
if (!(mac_bi_data.id == MAC_MODEL_Q630
|| mac_bi_data.id == MAC_MODEL_P588))
return -ENODEV;
frame_buffer_phys = 0xf9000000;
cmap_regs_phys = 0x50f24000;
flags = IOMAP_NOCACHE_SER;
#else
{
struct device_node *dp;
struct resource r;
dp = of_find_node_by_name(NULL, "valkyrie");
if (dp == 0)
return 0;
if (of_address_to_resource(dp, 0, &r)) {
printk(KERN_ERR "can't find address for valkyrie\n");
return 0;
}
frame_buffer_phys = r.start;
cmap_regs_phys = r.start + 0x304000;
flags = _PAGE_WRITETHRU;
}
#endif
p = kzalloc(sizeof(*p), GFP_ATOMIC);
if (p == 0)
return -ENOMEM;
if (!request_mem_region(frame_buffer_phys, 0x100000, "valkyriefb")) {
kfree(p);
return 0;
}
p->total_vram = 0x100000;
p->frame_buffer_phys = frame_buffer_phys;
p->frame_buffer = __ioremap(frame_buffer_phys, p->total_vram, flags);
p->cmap_regs_phys = cmap_regs_phys;
p->cmap_regs = ioremap(p->cmap_regs_phys, 0x1000);
p->valkyrie_regs_phys = cmap_regs_phys+0x6000;
p->valkyrie_regs = ioremap(p->valkyrie_regs_phys, 0x1000);
err = -ENOMEM;
if (p->frame_buffer == NULL || p->cmap_regs == NULL
|| p->valkyrie_regs == NULL) {
printk(KERN_ERR "valkyriefb: couldn't map resources\n");
goto out_free;
}
valkyrie_choose_mode(p);
mac_vmode_to_var(default_vmode, default_cmode, &p->info.var);
err = valkyrie_init_info(&p->info, p);
if (err < 0)
goto out_free;
valkyrie_init_fix(&p->info.fix, p);
if (valkyriefb_set_par(&p->info))
printk(KERN_ERR "valkyriefb: can't set default video mode\n");
if ((err = register_framebuffer(&p->info)) != 0)
goto out_cmap_free;
fb_info(&p->info, "valkyrie frame buffer device\n");
return 0;
out_cmap_free:
fb_dealloc_cmap(&p->info.cmap);
out_free:
if (p->frame_buffer)
iounmap(p->frame_buffer);
if (p->cmap_regs)
iounmap(p->cmap_regs);
if (p->valkyrie_regs)
iounmap(p->valkyrie_regs);
kfree(p);
return err;
}
static int read_valkyrie_sense(struct fb_info_valkyrie *p)
{
int sense, in;
out_8(&p->valkyrie_regs->msense.r, 0);
__delay(20000);
sense = ((in = in_8(&p->valkyrie_regs->msense.r)) & 0x70) << 4;
out_8(&p->valkyrie_regs->msense.r, 4);
__delay(20000);
sense |= ((in = in_8(&p->valkyrie_regs->msense.r)) & 0x30);
out_8(&p->valkyrie_regs->msense.r, 2);
__delay(20000);
sense |= ((in = in_8(&p->valkyrie_regs->msense.r)) & 0x40) >> 3;
sense |= (in & 0x10) >> 2;
out_8(&p->valkyrie_regs->msense.r, 1);
__delay(20000);
sense |= ((in = in_8(&p->valkyrie_regs->msense.r)) & 0x60) >> 5;
out_8(&p->valkyrie_regs->msense.r, 7);
return sense;
}
static int valkyrie_var_to_par(struct fb_var_screeninfo *var,
struct fb_par_valkyrie *par, const struct fb_info *fb_info)
{
int vmode, cmode;
struct valkyrie_regvals *init;
struct fb_info_valkyrie *p =
container_of(fb_info, struct fb_info_valkyrie, info);
if (mac_var_to_vmode(var, &vmode, &cmode) != 0) {
printk(KERN_ERR "valkyriefb: can't do %dx%dx%d.\n",
var->xres, var->yres, var->bits_per_pixel);
return -EINVAL;
}
if (vmode < 1 || vmode > VMODE_MAX || !valkyrie_reg_init[vmode-1]) {
printk(KERN_ERR "valkyriefb: vmode %d not valid.\n", vmode);
return -EINVAL;
}
if (cmode != CMODE_8 && cmode != CMODE_16) {
printk(KERN_ERR "valkyriefb: cmode %d not valid.\n", cmode);
return -EINVAL;
}
if (var->xres_virtual > var->xres || var->yres_virtual > var->yres
|| var->xoffset != 0 || var->yoffset != 0) {
return -EINVAL;
}
init = valkyrie_reg_init[vmode-1];
if (init->pitch[cmode] == 0) {
printk(KERN_ERR "valkyriefb: vmode %d does not support "
"cmode %d.\n", vmode, cmode);
return -EINVAL;
}
if (valkyrie_vram_reqd(vmode, cmode) > p->total_vram) {
printk(KERN_ERR "valkyriefb: not enough ram for vmode %d, "
"cmode %d.\n", vmode, cmode);
return -EINVAL;
}
par->vmode = vmode;
par->cmode = cmode;
par->init = init;
par->xres = var->xres;
par->yres = var->yres;
par->vxres = par->xres;
par->vyres = par->yres;
return 0;
}
static void valkyrie_init_fix(struct fb_fix_screeninfo *fix, struct fb_info_valkyrie *p)
{
memset(fix, 0, sizeof(*fix));
strcpy(fix->id, "valkyrie");
fix->mmio_start = p->valkyrie_regs_phys;
fix->mmio_len = sizeof(struct valkyrie_regs);
fix->type = FB_TYPE_PACKED_PIXELS;
fix->smem_start = p->frame_buffer_phys + 0x1000;
fix->smem_len = p->total_vram;
fix->type_aux = 0;
fix->ywrapstep = 0;
fix->ypanstep = 0;
fix->xpanstep = 0;
}
static void valkyrie_par_to_fix(struct fb_par_valkyrie *par,
struct fb_fix_screeninfo *fix)
{
fix->smem_len = valkyrie_vram_reqd(par->vmode, par->cmode);
fix->visual = (par->cmode == CMODE_8) ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_DIRECTCOLOR;
fix->line_length = par->vxres << par->cmode;
}
static int __init valkyrie_init_info(struct fb_info *info,
struct fb_info_valkyrie *p)
{
info->fbops = &valkyriefb_ops;
info->screen_base = p->frame_buffer + 0x1000;
info->flags = FBINFO_DEFAULT;
info->pseudo_palette = p->pseudo_palette;
info->par = &p->par;
return fb_alloc_cmap(&info->cmap, 256, 0);
}
int __init valkyriefb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "vmode:", 6)) {
int vmode = simple_strtoul(this_opt+6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX)
default_vmode = vmode;
}
else if (!strncmp(this_opt, "cmode:", 6)) {
int depth = simple_strtoul(this_opt+6, NULL, 0);
switch (depth) {
case 8:
default_cmode = CMODE_8;
break;
case 15:
case 16:
default_cmode = CMODE_16;
break;
}
}
}
return 0;
}
