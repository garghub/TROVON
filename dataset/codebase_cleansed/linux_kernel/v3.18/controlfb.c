static inline int PAR_EQUAL(struct fb_par_control *x, struct fb_par_control *y)
{
int i, results;
results = 1;
for (i = 0; i < 3; i++)
results &= !DIRTY(regvals.clock_params[i]);
if (!results)
return 0;
for (i = 0; i < 16; i++)
results &= !DIRTY(regvals.regs[i]);
if (!results)
return 0;
return (!DIRTY(cmode) && !DIRTY(xres) && !DIRTY(yres)
&& !DIRTY(vxres) && !DIRTY(vyres));
}
static inline int VAR_MATCH(struct fb_var_screeninfo *x, struct fb_var_screeninfo *y)
{
return (!DIRTY(bits_per_pixel) && !DIRTY(xres)
&& !DIRTY(yres) && !DIRTY(xres_virtual)
&& !DIRTY(yres_virtual)
&& !DIRTY_CMAP(red) && !DIRTY_CMAP(green) && !DIRTY_CMAP(blue));
}
int init_module(void)
{
struct device_node *dp;
int ret = -ENXIO;
dp = of_find_node_by_name(NULL, "control");
if (dp != 0 && !control_of_init(dp))
ret = 0;
of_node_put(dp);
return ret;
}
void cleanup_module(void)
{
control_cleanup();
}
static int controlfb_check_var (struct fb_var_screeninfo *var, struct fb_info *info)
{
struct fb_par_control par;
int err;
err = control_var_to_par(var, &par, info);
if (err)
return err;
control_par_to_var(&par, var);
return 0;
}
static int controlfb_set_par (struct fb_info *info)
{
struct fb_info_control *p =
container_of(info, struct fb_info_control, info);
struct fb_par_control par;
int err;
if((err = control_var_to_par(&info->var, &par, info))) {
printk (KERN_ERR "controlfb_set_par: error calling"
" control_var_to_par: %d.\n", err);
return err;
}
control_set_hardware(p, &par);
info->fix.visual = (p->par.cmode == CMODE_8) ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_DIRECTCOLOR;
info->fix.line_length = p->par.pitch;
info->fix.xpanstep = 32 >> p->par.cmode;
info->fix.ypanstep = 1;
return 0;
}
static inline void set_screen_start(int xoffset, int yoffset,
struct fb_info_control *p)
{
struct fb_par_control *par = &p->par;
par->xoffset = xoffset;
par->yoffset = yoffset;
out_le32(CNTRL_REG(p,start_addr),
par->yoffset * par->pitch + (par->xoffset << par->cmode));
}
static int controlfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
unsigned int xoffset, hstep;
struct fb_info_control *p =
container_of(info, struct fb_info_control, info);
struct fb_par_control *par = &p->par;
hstep = 0x1f >> par->cmode;
xoffset = (var->xoffset + hstep) & ~hstep;
if (xoffset+par->xres > par->vxres ||
var->yoffset+par->yres > par->vyres)
return -EINVAL;
set_screen_start(xoffset, var->yoffset, p);
return 0;
}
static int controlfb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
unsigned long mmio_pgoff;
unsigned long start;
u32 len;
start = info->fix.smem_start;
len = info->fix.smem_len;
mmio_pgoff = PAGE_ALIGN((start & ~PAGE_MASK) + len) >> PAGE_SHIFT;
if (vma->vm_pgoff >= mmio_pgoff) {
if (info->var.accel_flags)
return -EINVAL;
vma->vm_pgoff -= mmio_pgoff;
start = info->fix.mmio_start;
len = info->fix.mmio_len;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
} else {
vma->vm_page_prot = pgprot_cached_wthru(vma->vm_page_prot);
}
return vm_iomap_memory(vma, start, len);
}
static int controlfb_blank(int blank_mode, struct fb_info *info)
{
struct fb_info_control *p =
container_of(info, struct fb_info_control, info);
unsigned ctrl;
ctrl = ld_le32(CNTRL_REG(p,ctrl));
if (blank_mode > 0)
switch (blank_mode) {
case FB_BLANK_VSYNC_SUSPEND:
ctrl &= ~3;
break;
case FB_BLANK_HSYNC_SUSPEND:
ctrl &= ~0x30;
break;
case FB_BLANK_POWERDOWN:
ctrl &= ~0x33;
case FB_BLANK_NORMAL:
ctrl |= 0x400;
break;
default:
break;
}
else {
ctrl &= ~0x400;
ctrl |= 0x33;
}
out_le32(CNTRL_REG(p,ctrl), ctrl);
return 0;
}
static int controlfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct fb_info_control *p =
container_of(info, struct fb_info_control, info);
__u8 r, g, b;
if (regno > 255)
return 1;
r = red >> 8;
g = green >> 8;
b = blue >> 8;
out_8(&p->cmap_regs->addr, regno);
out_8(&p->cmap_regs->lut, r);
out_8(&p->cmap_regs->lut, g);
out_8(&p->cmap_regs->lut, b);
if (regno < 16) {
int i;
switch (p->par.cmode) {
case CMODE_16:
p->pseudo_palette[regno] =
(regno << 10) | (regno << 5) | regno;
break;
case CMODE_32:
i = (regno << 8) | regno;
p->pseudo_palette[regno] = (i << 16) | i;
break;
}
}
return 0;
}
static void set_control_clock(unsigned char *params)
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
static int __init init_control(struct fb_info_control *p)
{
int full, sense, vmode, cmode, vyres;
struct fb_var_screeninfo var;
int rc;
printk(KERN_INFO "controlfb: ");
full = p->total_vram == 0x400000;
#ifdef CONFIG_NVRAM
if (default_cmode == CMODE_NVRAM) {
cmode = nvram_read_byte(NV_CMODE);
if(cmode < CMODE_8 || cmode > CMODE_32)
cmode = CMODE_8;
} else
#endif
cmode=default_cmode;
#ifdef CONFIG_NVRAM
if (default_vmode == VMODE_NVRAM) {
vmode = nvram_read_byte(NV_VMODE);
if (vmode < 1 || vmode > VMODE_MAX ||
control_mac_modes[vmode - 1].m[full] < cmode) {
sense = read_control_sense(p);
printk("Monitor sense value = 0x%x, ", sense);
vmode = mac_map_monitor_sense(sense);
if (control_mac_modes[vmode - 1].m[full] < cmode)
vmode = VMODE_640_480_60;
}
} else
#endif
{
vmode=default_vmode;
if (control_mac_modes[vmode - 1].m[full] < cmode) {
if (cmode > CMODE_8)
cmode--;
else
vmode = VMODE_640_480_60;
}
}
control_init_info(&p->info, p);
if (mac_vmode_to_var(vmode, cmode, &var) < 0) {
printk("mac_vmode_to_var(%d, %d,) failed\n", vmode, cmode);
try_again:
vmode = VMODE_640_480_60;
cmode = CMODE_8;
if (mac_vmode_to_var(vmode, cmode, &var) < 0) {
printk(KERN_ERR "controlfb: mac_vmode_to_var() failed\n");
return -ENXIO;
}
printk(KERN_INFO "controlfb: ");
}
printk("using video mode %d and color mode %d.\n", vmode, cmode);
vyres = (p->total_vram - CTRLFB_OFF) / (var.xres << cmode);
if (vyres > var.yres)
var.yres_virtual = vyres;
var.activate = FB_ACTIVATE_NOW;
rc = fb_set_var(&p->info, &var);
if (rc && (vmode != VMODE_640_480_60 || cmode != CMODE_8))
goto try_again;
if (register_framebuffer(&p->info) < 0)
return -ENXIO;
fb_info(&p->info, "control display adapter\n");
return 0;
}
static void control_set_hardware(struct fb_info_control *p, struct fb_par_control *par)
{
struct control_regvals *r;
volatile struct preg __iomem *rp;
int i, cmode;
if (PAR_EQUAL(&p->par, par)) {
if (p->par.xoffset != par->xoffset ||
p->par.yoffset != par->yoffset)
set_screen_start(par->xoffset, par->yoffset, p);
return;
}
p->par = *par;
cmode = p->par.cmode;
r = &par->regvals;
out_le32(CNTRL_REG(p,ctrl), 0x400 | par->ctrl);
set_control_clock(r->clock_params);
RADACAL_WRITE(0x20, r->radacal_ctrl);
RADACAL_WRITE(0x21, p->control_use_bank2 ? 0 : 1);
RADACAL_WRITE(0x10, 0);
RADACAL_WRITE(0x11, 0);
rp = &p->control_regs->vswin;
for (i = 0; i < 16; ++i, ++rp)
out_le32(&rp->r, r->regs[i]);
out_le32(CNTRL_REG(p,pitch), par->pitch);
out_le32(CNTRL_REG(p,mode), r->mode);
out_le32(CNTRL_REG(p,vram_attr), p->vram_attr);
out_le32(CNTRL_REG(p,start_addr), par->yoffset * par->pitch
+ (par->xoffset << cmode));
out_le32(CNTRL_REG(p,rfrcnt), 0x1e5);
out_le32(CNTRL_REG(p,intr_ena), 0);
out_le32(CNTRL_REG(p,ctrl), par->ctrl);
#ifdef CONFIG_BOOTX_TEXT
btext_update_display(p->frame_buffer_phys + CTRLFB_OFF,
p->par.xres, p->par.yres,
(cmode == CMODE_32? 32: cmode == CMODE_16? 16: 8),
p->par.pitch);
#endif
}
static void __init control_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "vmode:", 6)) {
int vmode = simple_strtoul(this_opt+6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX &&
control_mac_modes[vmode - 1].m[1] >= 0)
default_vmode = vmode;
} else if (!strncmp(this_opt, "cmode:", 6)) {
int depth = simple_strtoul(this_opt+6, NULL, 0);
switch (depth) {
case CMODE_8:
case CMODE_16:
case CMODE_32:
default_cmode = depth;
break;
case 8:
default_cmode = CMODE_8;
break;
case 15:
case 16:
default_cmode = CMODE_16;
break;
case 24:
case 32:
default_cmode = CMODE_32;
break;
}
}
}
}
static int __init control_init(void)
{
struct device_node *dp;
char *option = NULL;
int ret = -ENXIO;
if (fb_get_options("controlfb", &option))
return -ENODEV;
control_setup(option);
dp = of_find_node_by_name(NULL, "control");
if (dp != 0 && !control_of_init(dp))
ret = 0;
of_node_put(dp);
return ret;
}
static void __init find_vram_size(struct fb_info_control *p)
{
int bank1, bank2;
out_le32(CNTRL_REG(p,vram_attr), 0x31);
out_8(&p->frame_buffer[0x600000], 0xb3);
out_8(&p->frame_buffer[0x600001], 0x71);
asm volatile("eieio; dcbf 0,%0" : : "r" (&p->frame_buffer[0x600000])
: "memory" );
mb();
asm volatile("eieio; dcbi 0,%0" : : "r" (&p->frame_buffer[0x600000])
: "memory" );
mb();
bank2 = (in_8(&p->frame_buffer[0x600000]) == 0xb3)
&& (in_8(&p->frame_buffer[0x600001]) == 0x71);
out_le32(CNTRL_REG(p,vram_attr), 0x39);
out_8(&p->frame_buffer[0], 0x5a);
out_8(&p->frame_buffer[1], 0xc7);
asm volatile("eieio; dcbf 0,%0" : : "r" (&p->frame_buffer[0])
: "memory" );
mb();
asm volatile("eieio; dcbi 0,%0" : : "r" (&p->frame_buffer[0])
: "memory" );
mb();
bank1 = (in_8(&p->frame_buffer[0]) == 0x5a)
&& (in_8(&p->frame_buffer[1]) == 0xc7);
if (bank2) {
if (!bank1) {
p->control_use_bank2 = 1;
p->vram_attr = 0x39;
p->frame_buffer += 0x600000;
p->frame_buffer_phys += 0x600000;
} else {
p->vram_attr = 0x51;
}
} else {
p->vram_attr = 0x31;
}
p->total_vram = (bank1 + bank2) * 0x200000;
printk(KERN_INFO "controlfb: VRAM Total = %dMB "
"(%dMB @ bank 1, %dMB @ bank 2)\n",
(bank1 + bank2) << 1, bank1 << 1, bank2 << 1);
}
static int __init control_of_init(struct device_node *dp)
{
struct fb_info_control *p;
struct resource fb_res, reg_res;
if (control_fb) {
printk(KERN_ERR "controlfb: only one control is supported\n");
return -ENXIO;
}
if (of_pci_address_to_resource(dp, 2, &fb_res) ||
of_pci_address_to_resource(dp, 1, &reg_res)) {
printk(KERN_ERR "can't get 2 addresses for control\n");
return -ENXIO;
}
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (p == 0)
return -ENXIO;
control_fb = p;
p->fb_orig_base = fb_res.start;
p->fb_orig_size = resource_size(&fb_res);
p->frame_buffer_phys = fb_res.start + 0x800000;
p->control_regs_phys = reg_res.start;
p->control_regs_size = resource_size(&reg_res);
if (!p->fb_orig_base ||
!request_mem_region(p->fb_orig_base,p->fb_orig_size,"controlfb")) {
p->fb_orig_base = 0;
goto error_out;
}
p->frame_buffer = __ioremap(p->frame_buffer_phys, 0x800000,
_PAGE_WRITETHRU);
if (!p->control_regs_phys ||
!request_mem_region(p->control_regs_phys, p->control_regs_size,
"controlfb regs")) {
p->control_regs_phys = 0;
goto error_out;
}
p->control_regs = ioremap(p->control_regs_phys, p->control_regs_size);
p->cmap_regs_phys = 0xf301b000;
if (!request_mem_region(p->cmap_regs_phys, 0x1000, "controlfb cmap")) {
p->cmap_regs_phys = 0;
goto error_out;
}
p->cmap_regs = ioremap(p->cmap_regs_phys, 0x1000);
if (!p->cmap_regs || !p->control_regs || !p->frame_buffer)
goto error_out;
find_vram_size(p);
if (!p->total_vram)
goto error_out;
if (init_control(p) < 0)
goto error_out;
return 0;
error_out:
control_cleanup();
return -ENXIO;
}
static int read_control_sense(struct fb_info_control *p)
{
int sense;
out_le32(CNTRL_REG(p,mon_sense), 7);
__delay(200);
out_le32(CNTRL_REG(p,mon_sense), 077);
__delay(2000);
sense = (in_le32(CNTRL_REG(p,mon_sense)) & 0x1c0) << 2;
out_le32(CNTRL_REG(p,mon_sense), 033);
__delay(2000);
sense |= (in_le32(CNTRL_REG(p,mon_sense)) & 0xc0) >> 2;
out_le32(CNTRL_REG(p,mon_sense), 055);
__delay(2000);
sense |= ((in_le32(CNTRL_REG(p,mon_sense)) & 0x100) >> 5)
| ((in_le32(CNTRL_REG(p,mon_sense)) & 0x40) >> 4);
out_le32(CNTRL_REG(p,mon_sense), 066);
__delay(2000);
sense |= (in_le32(CNTRL_REG(p,mon_sense)) & 0x180) >> 7;
out_le32(CNTRL_REG(p,mon_sense), 077);
return sense;
}
static int calc_clock_params(unsigned long clk, unsigned char *param)
{
unsigned long p0, p1, p2, k, l, m, n, min;
if (clk > (CONTROL_PIXCLOCK_BASE << 3))
return 1;
p2 = ((clk << 4) < CONTROL_PIXCLOCK_BASE)? 3: 2;
l = clk << p2;
p0 = 0;
p1 = 0;
for (k = 1, min = l; k < 32; k++) {
unsigned long rem;
m = CONTROL_PIXCLOCK_BASE * k;
n = m / l;
rem = m % l;
if (n && (n < 128) && rem < min) {
p0 = k;
p1 = n;
min = rem;
}
}
if (!p0 || !p1)
return 1;
param[0] = p0;
param[1] = p1;
param[2] = p2;
return 0;
}
static int control_var_to_par(struct fb_var_screeninfo *var,
struct fb_par_control *par, const struct fb_info *fb_info)
{
int cmode, piped_diff, hstep;
unsigned hperiod, hssync, hsblank, hesync, heblank, piped, heq, hlfln,
hserr, vperiod, vssync, vesync, veblank, vsblank, vswin, vewin;
unsigned long pixclock;
struct fb_info_control *p =
container_of(fb_info, struct fb_info_control, info);
struct control_regvals *r = &par->regvals;
switch (var->bits_per_pixel) {
case 8:
par->cmode = CMODE_8;
if (p->total_vram > 0x200000) {
r->mode = 3;
r->radacal_ctrl = 0x20;
piped_diff = 13;
} else {
r->mode = 2;
r->radacal_ctrl = 0x10;
piped_diff = 9;
}
break;
case 15:
case 16:
par->cmode = CMODE_16;
if (p->total_vram > 0x200000) {
r->mode = 2;
r->radacal_ctrl = 0x24;
piped_diff = 5;
} else {
r->mode = 1;
r->radacal_ctrl = 0x14;
piped_diff = 3;
}
break;
case 32:
par->cmode = CMODE_32;
if (p->total_vram > 0x200000) {
r->mode = 1;
r->radacal_ctrl = 0x28;
} else {
r->mode = 0;
r->radacal_ctrl = 0x18;
}
piped_diff = 1;
break;
default:
return -EINVAL;
}
hstep = 31 >> par->cmode;
par->xres = (var->xres + hstep) & ~hstep;
par->vxres = (var->xres_virtual + hstep) & ~hstep;
par->xoffset = (var->xoffset + hstep) & ~hstep;
if (par->vxres < par->xres)
par->vxres = par->xres;
par->pitch = par->vxres << par->cmode;
par->yres = var->yres;
par->vyres = var->yres_virtual;
par->yoffset = var->yoffset;
if (par->vyres < par->yres)
par->vyres = par->yres;
par->sync = var->sync;
if (par->pitch * par->vyres + CTRLFB_OFF > p->total_vram)
return -EINVAL;
if (par->xoffset + par->xres > par->vxres)
par->xoffset = par->vxres - par->xres;
if (par->yoffset + par->yres > par->vyres)
par->yoffset = par->vyres - par->yres;
pixclock = (var->pixclock < CONTROL_PIXCLOCK_MIN)? CONTROL_PIXCLOCK_MIN:
var->pixclock;
if (calc_clock_params(pixclock, r->clock_params))
return -EINVAL;
hperiod = ((var->left_margin + par->xres + var->right_margin
+ var->hsync_len) >> 1) - 2;
hssync = hperiod + 1;
hsblank = hssync - (var->right_margin >> 1);
hesync = (var->hsync_len >> 1) - 1;
heblank = (var->left_margin >> 1) + hesync;
piped = heblank - piped_diff;
heq = var->hsync_len >> 2;
hlfln = (hperiod+2) >> 1;
hserr = hssync-hesync;
vperiod = (var->vsync_len + var->lower_margin + par->yres
+ var->upper_margin) << 1;
vssync = vperiod - 2;
vesync = (var->vsync_len << 1) - vperiod + vssync;
veblank = (var->upper_margin << 1) + vesync;
vsblank = vssync - (var->lower_margin << 1);
vswin = (vsblank+vssync) >> 1;
vewin = (vesync+veblank) >> 1;
r->regs[0] = vswin;
r->regs[1] = vsblank;
r->regs[2] = veblank;
r->regs[3] = vewin;
r->regs[4] = vesync;
r->regs[5] = vssync;
r->regs[6] = vperiod;
r->regs[7] = piped;
r->regs[8] = hperiod;
r->regs[9] = hsblank;
r->regs[10] = heblank;
r->regs[11] = hesync;
r->regs[12] = hssync;
r->regs[13] = heq;
r->regs[14] = hlfln;
r->regs[15] = hserr;
if (par->xres >= 1280 && par->cmode >= CMODE_16)
par->ctrl = 0x7f;
else
par->ctrl = 0x3b;
if (mac_var_to_vmode(var, &par->vmode, &cmode))
par->vmode = 0;
return 0;
}
static void control_par_to_var(struct fb_par_control *par, struct fb_var_screeninfo *var)
{
struct control_regints *rv;
rv = (struct control_regints *) par->regvals.regs;
memset(var, 0, sizeof(*var));
var->xres = par->xres;
var->yres = par->yres;
var->xres_virtual = par->vxres;
var->yres_virtual = par->vyres;
var->xoffset = par->xoffset;
var->yoffset = par->yoffset;
switch(par->cmode) {
default:
case CMODE_8:
var->bits_per_pixel = 8;
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
break;
case CMODE_16:
var->bits_per_pixel = 16;
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 5;
var->blue.length = 5;
break;
case CMODE_32:
var->bits_per_pixel = 32;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.length = 8;
var->transp.offset = 24;
var->transp.length = 8;
break;
}
var->height = -1;
var->width = -1;
var->vmode = FB_VMODE_NONINTERLACED;
var->left_margin = (rv->heblank - rv->hesync) << 1;
var->right_margin = (rv->hssync - rv->hsblank) << 1;
var->hsync_len = (rv->hperiod + 2 - rv->hssync + rv->hesync) << 1;
var->upper_margin = (rv->veblank - rv->vesync) >> 1;
var->lower_margin = (rv->vssync - rv->vsblank) >> 1;
var->vsync_len = (rv->vperiod - rv->vssync + rv->vesync) >> 1;
var->sync = par->sync;
var->pixclock = CONTROL_PIXCLOCK_BASE * par->regvals.clock_params[0];
var->pixclock /= par->regvals.clock_params[1];
var->pixclock >>= par->regvals.clock_params[2];
}
static void __init control_init_info(struct fb_info *info, struct fb_info_control *p)
{
info->par = &p->par;
info->fbops = &controlfb_ops;
info->pseudo_palette = p->pseudo_palette;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
info->screen_base = p->frame_buffer + CTRLFB_OFF;
fb_alloc_cmap(&info->cmap, 256, 0);
strcpy(info->fix.id, "control");
info->fix.mmio_start = p->control_regs_phys;
info->fix.mmio_len = sizeof(struct control_regs);
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.smem_start = p->frame_buffer_phys + CTRLFB_OFF;
info->fix.smem_len = p->total_vram - CTRLFB_OFF;
info->fix.ywrapstep = 0;
info->fix.type_aux = 0;
info->fix.accel = FB_ACCEL_NONE;
}
static void control_cleanup(void)
{
struct fb_info_control *p = control_fb;
if (!p)
return;
if (p->cmap_regs)
iounmap(p->cmap_regs);
if (p->control_regs)
iounmap(p->control_regs);
if (p->frame_buffer) {
if (p->control_use_bank2)
p->frame_buffer -= 0x600000;
iounmap(p->frame_buffer);
}
if (p->cmap_regs_phys)
release_mem_region(p->cmap_regs_phys, 0x1000);
if (p->control_regs_phys)
release_mem_region(p->control_regs_phys, p->control_regs_size);
if (p->fb_orig_base)
release_mem_region(p->fb_orig_base, p->fb_orig_size);
kfree(p);
}
