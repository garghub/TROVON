static inline void sa1100fb_schedule_work(struct sa1100fb_info *fbi, u_int state)
{
unsigned long flags;
local_irq_save(flags);
if (fbi->task_state == C_ENABLE && state == C_REENABLE)
state = (u_int) -1;
if (fbi->task_state == C_DISABLE && state == C_ENABLE)
state = C_REENABLE;
if (state != (u_int)-1) {
fbi->task_state = state;
schedule_work(&fbi->task);
}
local_irq_restore(flags);
}
static inline u_int chan_to_field(u_int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static inline u_int palette_pbs(struct fb_var_screeninfo *var)
{
int ret = 0;
switch (var->bits_per_pixel) {
case 4: ret = 0 << 12; break;
case 8: ret = 1 << 12; break;
case 16: ret = 2 << 12; break;
}
return ret;
}
static int
sa1100fb_setpalettereg(u_int regno, u_int red, u_int green, u_int blue,
u_int trans, struct fb_info *info)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
u_int val, ret = 1;
if (regno < fbi->palette_size) {
val = ((red >> 4) & 0xf00);
val |= ((green >> 8) & 0x0f0);
val |= ((blue >> 12) & 0x00f);
if (regno == 0)
val |= palette_pbs(&fbi->fb.var);
fbi->palette_cpu[regno] = val;
ret = 0;
}
return ret;
}
static int
sa1100fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int trans, struct fb_info *info)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
unsigned int val;
int ret = 1;
if (fbi->inf->cmap_inverse) {
red = 0xffff - red;
green = 0xffff - green;
blue = 0xffff - blue;
}
if (fbi->fb.var.grayscale)
red = green = blue = (19595 * red + 38470 * green +
7471 * blue) >> 16;
switch (fbi->fb.fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = fbi->fb.pseudo_palette;
val = chan_to_field(red, &fbi->fb.var.red);
val |= chan_to_field(green, &fbi->fb.var.green);
val |= chan_to_field(blue, &fbi->fb.var.blue);
pal[regno] = val;
ret = 0;
}
break;
case FB_VISUAL_STATIC_PSEUDOCOLOR:
case FB_VISUAL_PSEUDOCOLOR:
ret = sa1100fb_setpalettereg(regno, red, green, blue, trans, info);
break;
}
return ret;
}
static inline unsigned int sa1100fb_display_dma_period(struct fb_var_screeninfo *var)
{
return var->pixclock * 8 * 16 / var->bits_per_pixel;
}
static int
sa1100fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
int rgbidx;
if (var->xres < MIN_XRES)
var->xres = MIN_XRES;
if (var->yres < MIN_YRES)
var->yres = MIN_YRES;
if (var->xres > fbi->inf->xres)
var->xres = fbi->inf->xres;
if (var->yres > fbi->inf->yres)
var->yres = fbi->inf->yres;
var->xres_virtual = max(var->xres_virtual, var->xres);
var->yres_virtual = max(var->yres_virtual, var->yres);
dev_dbg(fbi->dev, "var->bits_per_pixel=%d\n", var->bits_per_pixel);
switch (var->bits_per_pixel) {
case 4:
rgbidx = RGB_4;
break;
case 8:
rgbidx = RGB_8;
break;
case 16:
rgbidx = RGB_16;
break;
default:
return -EINVAL;
}
var->red = fbi->rgb[rgbidx]->red;
var->green = fbi->rgb[rgbidx]->green;
var->blue = fbi->rgb[rgbidx]->blue;
var->transp = fbi->rgb[rgbidx]->transp;
dev_dbg(fbi->dev, "RGBT length = %d:%d:%d:%d\n",
var->red.length, var->green.length, var->blue.length,
var->transp.length);
dev_dbg(fbi->dev, "RGBT offset = %d:%d:%d:%d\n",
var->red.offset, var->green.offset, var->blue.offset,
var->transp.offset);
#ifdef CONFIG_CPU_FREQ
dev_dbg(fbi->dev, "dma period = %d ps, clock = %d kHz\n",
sa1100fb_display_dma_period(var),
cpufreq_get(smp_processor_id()));
#endif
return 0;
}
static void sa1100fb_set_visual(struct sa1100fb_info *fbi, u32 visual)
{
if (fbi->inf->set_visual)
fbi->inf->set_visual(visual);
}
static int sa1100fb_set_par(struct fb_info *info)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
struct fb_var_screeninfo *var = &info->var;
unsigned long palette_mem_size;
dev_dbg(fbi->dev, "set_par\n");
if (var->bits_per_pixel == 16)
fbi->fb.fix.visual = FB_VISUAL_TRUECOLOR;
else if (!fbi->inf->cmap_static)
fbi->fb.fix.visual = FB_VISUAL_PSEUDOCOLOR;
else {
fbi->fb.fix.visual = FB_VISUAL_STATIC_PSEUDOCOLOR;
}
fbi->fb.fix.line_length = var->xres_virtual *
var->bits_per_pixel / 8;
fbi->palette_size = var->bits_per_pixel == 8 ? 256 : 16;
palette_mem_size = fbi->palette_size * sizeof(u16);
dev_dbg(fbi->dev, "palette_mem_size = 0x%08lx\n", palette_mem_size);
fbi->palette_cpu = (u16 *)(fbi->map_cpu + PAGE_SIZE - palette_mem_size);
fbi->palette_dma = fbi->map_dma + PAGE_SIZE - palette_mem_size;
sa1100fb_set_visual(fbi, fbi->fb.fix.visual);
sa1100fb_activate_var(var, fbi);
return 0;
}
static int sa1100fb_blank(int blank, struct fb_info *info)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
int i;
dev_dbg(fbi->dev, "sa1100fb_blank: blank=%d\n", blank);
switch (blank) {
case FB_BLANK_POWERDOWN:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
if (fbi->fb.fix.visual == FB_VISUAL_PSEUDOCOLOR ||
fbi->fb.fix.visual == FB_VISUAL_STATIC_PSEUDOCOLOR)
for (i = 0; i < fbi->palette_size; i++)
sa1100fb_setpalettereg(i, 0, 0, 0, 0, info);
sa1100fb_schedule_work(fbi, C_DISABLE);
break;
case FB_BLANK_UNBLANK:
if (fbi->fb.fix.visual == FB_VISUAL_PSEUDOCOLOR ||
fbi->fb.fix.visual == FB_VISUAL_STATIC_PSEUDOCOLOR)
fb_set_cmap(&fbi->fb.cmap, info);
sa1100fb_schedule_work(fbi, C_ENABLE);
}
return 0;
}
static int sa1100fb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct sa1100fb_info *fbi = (struct sa1100fb_info *)info;
unsigned long off = vma->vm_pgoff << PAGE_SHIFT;
if (off < info->fix.smem_len) {
vma->vm_pgoff += 1;
return dma_mmap_writecombine(fbi->dev, vma, fbi->map_cpu,
fbi->map_dma, fbi->map_size);
}
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return vm_iomap_memory(vma, info->fix.mmio_start, info->fix.mmio_len);
}
static inline unsigned int get_pcd(unsigned int pixclock, unsigned int cpuclock)
{
unsigned int pcd = cpuclock / 100;
pcd *= pixclock;
pcd /= 10000000;
return pcd + 1;
}
static int sa1100fb_activate_var(struct fb_var_screeninfo *var, struct sa1100fb_info *fbi)
{
struct sa1100fb_lcd_reg new_regs;
u_int half_screen_size, yres, pcd;
u_long flags;
dev_dbg(fbi->dev, "Configuring SA1100 LCD\n");
dev_dbg(fbi->dev, "var: xres=%d hslen=%d lm=%d rm=%d\n",
var->xres, var->hsync_len,
var->left_margin, var->right_margin);
dev_dbg(fbi->dev, "var: yres=%d vslen=%d um=%d bm=%d\n",
var->yres, var->vsync_len,
var->upper_margin, var->lower_margin);
#if DEBUG_VAR
if (var->xres < 16 || var->xres > 1024)
dev_err(fbi->dev, "%s: invalid xres %d\n",
fbi->fb.fix.id, var->xres);
if (var->hsync_len < 1 || var->hsync_len > 64)
dev_err(fbi->dev, "%s: invalid hsync_len %d\n",
fbi->fb.fix.id, var->hsync_len);
if (var->left_margin < 1 || var->left_margin > 255)
dev_err(fbi->dev, "%s: invalid left_margin %d\n",
fbi->fb.fix.id, var->left_margin);
if (var->right_margin < 1 || var->right_margin > 255)
dev_err(fbi->dev, "%s: invalid right_margin %d\n",
fbi->fb.fix.id, var->right_margin);
if (var->yres < 1 || var->yres > 1024)
dev_err(fbi->dev, "%s: invalid yres %d\n",
fbi->fb.fix.id, var->yres);
if (var->vsync_len < 1 || var->vsync_len > 64)
dev_err(fbi->dev, "%s: invalid vsync_len %d\n",
fbi->fb.fix.id, var->vsync_len);
if (var->upper_margin < 0 || var->upper_margin > 255)
dev_err(fbi->dev, "%s: invalid upper_margin %d\n",
fbi->fb.fix.id, var->upper_margin);
if (var->lower_margin < 0 || var->lower_margin > 255)
dev_err(fbi->dev, "%s: invalid lower_margin %d\n",
fbi->fb.fix.id, var->lower_margin);
#endif
new_regs.lccr0 = fbi->inf->lccr0 |
LCCR0_LEN | LCCR0_LDM | LCCR0_BAM |
LCCR0_ERM | LCCR0_LtlEnd | LCCR0_DMADel(0);
new_regs.lccr1 =
LCCR1_DisWdth(var->xres) +
LCCR1_HorSnchWdth(var->hsync_len) +
LCCR1_BegLnDel(var->left_margin) +
LCCR1_EndLnDel(var->right_margin);
yres = var->yres;
if (fbi->inf->lccr0 & LCCR0_Dual)
yres /= 2;
new_regs.lccr2 =
LCCR2_DisHght(yres) +
LCCR2_VrtSnchWdth(var->vsync_len) +
LCCR2_BegFrmDel(var->upper_margin) +
LCCR2_EndFrmDel(var->lower_margin);
pcd = get_pcd(var->pixclock, cpufreq_get(0));
new_regs.lccr3 = LCCR3_PixClkDiv(pcd) | fbi->inf->lccr3 |
(var->sync & FB_SYNC_HOR_HIGH_ACT ? LCCR3_HorSnchH : LCCR3_HorSnchL) |
(var->sync & FB_SYNC_VERT_HIGH_ACT ? LCCR3_VrtSnchH : LCCR3_VrtSnchL);
dev_dbg(fbi->dev, "nlccr0 = 0x%08lx\n", new_regs.lccr0);
dev_dbg(fbi->dev, "nlccr1 = 0x%08lx\n", new_regs.lccr1);
dev_dbg(fbi->dev, "nlccr2 = 0x%08lx\n", new_regs.lccr2);
dev_dbg(fbi->dev, "nlccr3 = 0x%08lx\n", new_regs.lccr3);
half_screen_size = var->bits_per_pixel;
half_screen_size = half_screen_size * var->xres * var->yres / 16;
local_irq_save(flags);
fbi->dbar1 = fbi->palette_dma;
fbi->dbar2 = fbi->screen_dma + half_screen_size;
fbi->reg_lccr0 = new_regs.lccr0;
fbi->reg_lccr1 = new_regs.lccr1;
fbi->reg_lccr2 = new_regs.lccr2;
fbi->reg_lccr3 = new_regs.lccr3;
local_irq_restore(flags);
if (readl_relaxed(fbi->base + LCCR0) != fbi->reg_lccr0 ||
readl_relaxed(fbi->base + LCCR1) != fbi->reg_lccr1 ||
readl_relaxed(fbi->base + LCCR2) != fbi->reg_lccr2 ||
readl_relaxed(fbi->base + LCCR3) != fbi->reg_lccr3 ||
readl_relaxed(fbi->base + DBAR1) != fbi->dbar1 ||
readl_relaxed(fbi->base + DBAR2) != fbi->dbar2)
sa1100fb_schedule_work(fbi, C_REENABLE);
return 0;
}
static inline void __sa1100fb_backlight_power(struct sa1100fb_info *fbi, int on)
{
dev_dbg(fbi->dev, "backlight o%s\n", on ? "n" : "ff");
if (fbi->inf->backlight_power)
fbi->inf->backlight_power(on);
}
static inline void __sa1100fb_lcd_power(struct sa1100fb_info *fbi, int on)
{
dev_dbg(fbi->dev, "LCD power o%s\n", on ? "n" : "ff");
if (fbi->inf->lcd_power)
fbi->inf->lcd_power(on);
}
static void sa1100fb_setup_gpio(struct sa1100fb_info *fbi)
{
u_int mask = 0;
if ((fbi->reg_lccr0 & LCCR0_CMS) == LCCR0_Color &&
(fbi->reg_lccr0 & (LCCR0_Dual|LCCR0_Act)) != 0) {
mask = GPIO_LDD11 | GPIO_LDD10 | GPIO_LDD9 | GPIO_LDD8;
if (fbi->fb.var.bits_per_pixel > 8 ||
(fbi->reg_lccr0 & (LCCR0_Dual|LCCR0_Act)) == LCCR0_Dual)
mask |= GPIO_LDD15 | GPIO_LDD14 | GPIO_LDD13 | GPIO_LDD12;
}
if (mask) {
unsigned long flags;
local_irq_save(flags);
GPDR |= mask;
GAFR |= mask;
local_irq_restore(flags);
}
}
static void sa1100fb_enable_controller(struct sa1100fb_info *fbi)
{
dev_dbg(fbi->dev, "Enabling LCD controller\n");
fbi->palette_cpu[0] &= 0xcfff;
fbi->palette_cpu[0] |= palette_pbs(&fbi->fb.var);
writel_relaxed(fbi->reg_lccr3, fbi->base + LCCR3);
writel_relaxed(fbi->reg_lccr2, fbi->base + LCCR2);
writel_relaxed(fbi->reg_lccr1, fbi->base + LCCR1);
writel_relaxed(fbi->reg_lccr0 & ~LCCR0_LEN, fbi->base + LCCR0);
writel_relaxed(fbi->dbar1, fbi->base + DBAR1);
writel_relaxed(fbi->dbar2, fbi->base + DBAR2);
writel_relaxed(fbi->reg_lccr0 | LCCR0_LEN, fbi->base + LCCR0);
if (machine_is_shannon())
gpio_set_value(SHANNON_GPIO_DISP_EN, 1);
dev_dbg(fbi->dev, "DBAR1: 0x%08x\n", readl_relaxed(fbi->base + DBAR1));
dev_dbg(fbi->dev, "DBAR2: 0x%08x\n", readl_relaxed(fbi->base + DBAR2));
dev_dbg(fbi->dev, "LCCR0: 0x%08x\n", readl_relaxed(fbi->base + LCCR0));
dev_dbg(fbi->dev, "LCCR1: 0x%08x\n", readl_relaxed(fbi->base + LCCR1));
dev_dbg(fbi->dev, "LCCR2: 0x%08x\n", readl_relaxed(fbi->base + LCCR2));
dev_dbg(fbi->dev, "LCCR3: 0x%08x\n", readl_relaxed(fbi->base + LCCR3));
}
static void sa1100fb_disable_controller(struct sa1100fb_info *fbi)
{
DECLARE_WAITQUEUE(wait, current);
u32 lccr0;
dev_dbg(fbi->dev, "Disabling LCD controller\n");
if (machine_is_shannon())
gpio_set_value(SHANNON_GPIO_DISP_EN, 0);
set_current_state(TASK_UNINTERRUPTIBLE);
add_wait_queue(&fbi->ctrlr_wait, &wait);
writel_relaxed(~0, fbi->base + LCSR);
lccr0 = readl_relaxed(fbi->base + LCCR0);
lccr0 &= ~LCCR0_LDM;
writel_relaxed(lccr0, fbi->base + LCCR0);
lccr0 &= ~LCCR0_LEN;
writel_relaxed(lccr0, fbi->base + LCCR0);
schedule_timeout(20 * HZ / 1000);
remove_wait_queue(&fbi->ctrlr_wait, &wait);
}
static irqreturn_t sa1100fb_handle_irq(int irq, void *dev_id)
{
struct sa1100fb_info *fbi = dev_id;
unsigned int lcsr = readl_relaxed(fbi->base + LCSR);
if (lcsr & LCSR_LDD) {
u32 lccr0 = readl_relaxed(fbi->base + LCCR0) | LCCR0_LDM;
writel_relaxed(lccr0, fbi->base + LCCR0);
wake_up(&fbi->ctrlr_wait);
}
writel_relaxed(lcsr, fbi->base + LCSR);
return IRQ_HANDLED;
}
static void set_ctrlr_state(struct sa1100fb_info *fbi, u_int state)
{
u_int old_state;
mutex_lock(&fbi->ctrlr_lock);
old_state = fbi->state;
if (old_state == C_STARTUP && state == C_REENABLE)
state = C_ENABLE;
switch (state) {
case C_DISABLE_CLKCHANGE:
if (old_state != C_DISABLE && old_state != C_DISABLE_PM) {
fbi->state = state;
sa1100fb_disable_controller(fbi);
}
break;
case C_DISABLE_PM:
case C_DISABLE:
if (old_state != C_DISABLE) {
fbi->state = state;
__sa1100fb_backlight_power(fbi, 0);
if (old_state != C_DISABLE_CLKCHANGE)
sa1100fb_disable_controller(fbi);
__sa1100fb_lcd_power(fbi, 0);
}
break;
case C_ENABLE_CLKCHANGE:
if (old_state == C_DISABLE_CLKCHANGE) {
fbi->state = C_ENABLE;
sa1100fb_enable_controller(fbi);
}
break;
case C_REENABLE:
if (old_state == C_ENABLE) {
sa1100fb_disable_controller(fbi);
sa1100fb_setup_gpio(fbi);
sa1100fb_enable_controller(fbi);
}
break;
case C_ENABLE_PM:
if (old_state != C_DISABLE_PM)
break;
case C_ENABLE:
if (old_state != C_ENABLE) {
fbi->state = C_ENABLE;
sa1100fb_setup_gpio(fbi);
__sa1100fb_lcd_power(fbi, 1);
sa1100fb_enable_controller(fbi);
__sa1100fb_backlight_power(fbi, 1);
}
break;
}
mutex_unlock(&fbi->ctrlr_lock);
}
static void sa1100fb_task(struct work_struct *w)
{
struct sa1100fb_info *fbi = container_of(w, struct sa1100fb_info, task);
u_int state = xchg(&fbi->task_state, -1);
set_ctrlr_state(fbi, state);
}
static unsigned int sa1100fb_min_dma_period(struct sa1100fb_info *fbi)
{
#if 0
unsigned int min_period = (unsigned int)-1;
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct display *disp = &fb_display[i];
unsigned int period;
if (disp->fb_info != &fbi->fb)
continue;
period = sa1100fb_display_dma_period(&disp->var);
if (period < min_period)
min_period = period;
}
return min_period;
#else
return sa1100fb_display_dma_period(&fbi->fb.var);
#endif
}
static int
sa1100fb_freq_transition(struct notifier_block *nb, unsigned long val,
void *data)
{
struct sa1100fb_info *fbi = TO_INF(nb, freq_transition);
struct cpufreq_freqs *f = data;
u_int pcd;
switch (val) {
case CPUFREQ_PRECHANGE:
set_ctrlr_state(fbi, C_DISABLE_CLKCHANGE);
break;
case CPUFREQ_POSTCHANGE:
pcd = get_pcd(fbi->fb.var.pixclock, f->new);
fbi->reg_lccr3 = (fbi->reg_lccr3 & ~0xff) | LCCR3_PixClkDiv(pcd);
set_ctrlr_state(fbi, C_ENABLE_CLKCHANGE);
break;
}
return 0;
}
static int
sa1100fb_freq_policy(struct notifier_block *nb, unsigned long val,
void *data)
{
struct sa1100fb_info *fbi = TO_INF(nb, freq_policy);
struct cpufreq_policy *policy = data;
switch (val) {
case CPUFREQ_ADJUST:
case CPUFREQ_INCOMPATIBLE:
dev_dbg(fbi->dev, "min dma period: %d ps, "
"new clock %d kHz\n", sa1100fb_min_dma_period(fbi),
policy->max);
break;
case CPUFREQ_NOTIFY:
do {} while(0);
break;
}
return 0;
}
static int sa1100fb_suspend(struct platform_device *dev, pm_message_t state)
{
struct sa1100fb_info *fbi = platform_get_drvdata(dev);
set_ctrlr_state(fbi, C_DISABLE_PM);
return 0;
}
static int sa1100fb_resume(struct platform_device *dev)
{
struct sa1100fb_info *fbi = platform_get_drvdata(dev);
set_ctrlr_state(fbi, C_ENABLE_PM);
return 0;
}
static int sa1100fb_map_video_memory(struct sa1100fb_info *fbi)
{
fbi->map_size = PAGE_ALIGN(fbi->fb.fix.smem_len + PAGE_SIZE);
fbi->map_cpu = dma_alloc_writecombine(fbi->dev, fbi->map_size,
&fbi->map_dma, GFP_KERNEL);
if (fbi->map_cpu) {
fbi->fb.screen_base = fbi->map_cpu + PAGE_SIZE;
fbi->screen_dma = fbi->map_dma + PAGE_SIZE;
fbi->fb.fix.smem_start = fbi->screen_dma;
}
return fbi->map_cpu ? 0 : -ENOMEM;
}
static struct sa1100fb_info *sa1100fb_init_fbinfo(struct device *dev)
{
struct sa1100fb_mach_info *inf = dev->platform_data;
struct sa1100fb_info *fbi;
unsigned i;
fbi = kmalloc(sizeof(struct sa1100fb_info) + sizeof(u32) * 16,
GFP_KERNEL);
if (!fbi)
return NULL;
memset(fbi, 0, sizeof(struct sa1100fb_info));
fbi->dev = dev;
strcpy(fbi->fb.fix.id, SA1100_NAME);
fbi->fb.fix.type = FB_TYPE_PACKED_PIXELS;
fbi->fb.fix.type_aux = 0;
fbi->fb.fix.xpanstep = 0;
fbi->fb.fix.ypanstep = 0;
fbi->fb.fix.ywrapstep = 0;
fbi->fb.fix.accel = FB_ACCEL_NONE;
fbi->fb.var.nonstd = 0;
fbi->fb.var.activate = FB_ACTIVATE_NOW;
fbi->fb.var.height = -1;
fbi->fb.var.width = -1;
fbi->fb.var.accel_flags = 0;
fbi->fb.var.vmode = FB_VMODE_NONINTERLACED;
fbi->fb.fbops = &sa1100fb_ops;
fbi->fb.flags = FBINFO_DEFAULT;
fbi->fb.monspecs = monspecs;
fbi->fb.pseudo_palette = (fbi + 1);
fbi->rgb[RGB_4] = &rgb_4;
fbi->rgb[RGB_8] = &rgb_8;
fbi->rgb[RGB_16] = &def_rgb_16;
if (inf->lccr3 & (LCCR3_VrtSnchL|LCCR3_HorSnchL|0xff) ||
inf->pixclock == 0)
panic("sa1100fb error: invalid LCCR3 fields set or zero "
"pixclock.");
fbi->fb.var.xres = inf->xres;
fbi->fb.var.xres_virtual = inf->xres;
fbi->fb.var.yres = inf->yres;
fbi->fb.var.yres_virtual = inf->yres;
fbi->fb.var.bits_per_pixel = inf->bpp;
fbi->fb.var.pixclock = inf->pixclock;
fbi->fb.var.hsync_len = inf->hsync_len;
fbi->fb.var.left_margin = inf->left_margin;
fbi->fb.var.right_margin = inf->right_margin;
fbi->fb.var.vsync_len = inf->vsync_len;
fbi->fb.var.upper_margin = inf->upper_margin;
fbi->fb.var.lower_margin = inf->lower_margin;
fbi->fb.var.sync = inf->sync;
fbi->fb.var.grayscale = inf->cmap_greyscale;
fbi->state = C_STARTUP;
fbi->task_state = (u_char)-1;
fbi->fb.fix.smem_len = inf->xres * inf->yres *
inf->bpp / 8;
fbi->inf = inf;
for (i = 0; i < NR_RGB; i++)
if (inf->rgb[i])
fbi->rgb[i] = inf->rgb[i];
init_waitqueue_head(&fbi->ctrlr_wait);
INIT_WORK(&fbi->task, sa1100fb_task);
mutex_init(&fbi->ctrlr_lock);
return fbi;
}
static int sa1100fb_probe(struct platform_device *pdev)
{
struct sa1100fb_info *fbi;
struct resource *res;
int ret, irq;
if (!pdev->dev.platform_data) {
dev_err(&pdev->dev, "no platform LCD data\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (irq < 0 || !res)
return -EINVAL;
if (!request_mem_region(res->start, resource_size(res), "LCD"))
return -EBUSY;
fbi = sa1100fb_init_fbinfo(&pdev->dev);
ret = -ENOMEM;
if (!fbi)
goto failed;
fbi->base = ioremap(res->start, resource_size(res));
if (!fbi->base)
goto failed;
ret = sa1100fb_map_video_memory(fbi);
if (ret)
goto failed;
ret = request_irq(irq, sa1100fb_handle_irq, 0, "LCD", fbi);
if (ret) {
dev_err(&pdev->dev, "request_irq failed: %d\n", ret);
goto failed;
}
if (machine_is_shannon()) {
ret = gpio_request_one(SHANNON_GPIO_DISP_EN,
GPIOF_OUT_INIT_LOW, "display enable");
if (ret)
goto err_free_irq;
}
sa1100fb_check_var(&fbi->fb.var, &fbi->fb);
platform_set_drvdata(pdev, fbi);
ret = register_framebuffer(&fbi->fb);
if (ret < 0)
goto err_reg_fb;
#ifdef CONFIG_CPU_FREQ
fbi->freq_transition.notifier_call = sa1100fb_freq_transition;
fbi->freq_policy.notifier_call = sa1100fb_freq_policy;
cpufreq_register_notifier(&fbi->freq_transition, CPUFREQ_TRANSITION_NOTIFIER);
cpufreq_register_notifier(&fbi->freq_policy, CPUFREQ_POLICY_NOTIFIER);
#endif
return 0;
err_reg_fb:
if (machine_is_shannon())
gpio_free(SHANNON_GPIO_DISP_EN);
err_free_irq:
free_irq(irq, fbi);
failed:
if (fbi)
iounmap(fbi->base);
kfree(fbi);
release_mem_region(res->start, resource_size(res));
return ret;
}
int __init sa1100fb_init(void)
{
if (fb_get_options("sa1100fb", NULL))
return -ENODEV;
return platform_driver_register(&sa1100fb_driver);
}
int __init sa1100fb_setup(char *options)
{
#if 0
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "bpp:", 4))
current_par.max_bpp =
simple_strtoul(this_opt + 4, NULL, 0);
if (!strncmp(this_opt, "lccr0:", 6))
lcd_shadow.lccr0 =
simple_strtoul(this_opt + 6, NULL, 0);
if (!strncmp(this_opt, "lccr1:", 6)) {
lcd_shadow.lccr1 =
simple_strtoul(this_opt + 6, NULL, 0);
current_par.max_xres =
(lcd_shadow.lccr1 & 0x3ff) + 16;
}
if (!strncmp(this_opt, "lccr2:", 6)) {
lcd_shadow.lccr2 =
simple_strtoul(this_opt + 6, NULL, 0);
current_par.max_yres =
(lcd_shadow.
lccr0 & LCCR0_SDS) ? ((lcd_shadow.
lccr2 & 0x3ff) +
1) *
2 : ((lcd_shadow.lccr2 & 0x3ff) + 1);
}
if (!strncmp(this_opt, "lccr3:", 6))
lcd_shadow.lccr3 =
simple_strtoul(this_opt + 6, NULL, 0);
}
#endif
return 0;
}
