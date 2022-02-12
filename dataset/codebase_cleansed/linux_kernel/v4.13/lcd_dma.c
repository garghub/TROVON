int omap_lcd_dma_running(void)
{
if (cpu_is_omap15xx())
if (omap_readw(OMAP_LCDC_CONTROL) & OMAP_LCDC_CTRL_LCD_EN)
return 1;
if (cpu_is_omap16xx())
if (omap_readw(OMAP1610_DMA_LCD_CCR) & OMAP_DMA_CCR_EN)
return 1;
return 0;
}
void omap_set_lcd_dma_b1(unsigned long addr, u16 fb_xres, u16 fb_yres,
int data_type)
{
lcd_dma.addr = addr;
lcd_dma.data_type = data_type;
lcd_dma.xres = fb_xres;
lcd_dma.yres = fb_yres;
}
void omap_set_lcd_dma_ext_controller(int external)
{
lcd_dma.ext_ctrl = external;
}
void omap_set_lcd_dma_single_transfer(int single)
{
lcd_dma.single_transfer = single;
}
void omap_set_lcd_dma_b1_rotation(int rotate)
{
if (cpu_is_omap15xx()) {
printk(KERN_ERR "DMA rotation is not supported in 1510 mode\n");
BUG();
return;
}
lcd_dma.rotate = rotate;
}
void omap_set_lcd_dma_b1_mirror(int mirror)
{
if (cpu_is_omap15xx()) {
printk(KERN_ERR "DMA mirror is not supported in 1510 mode\n");
BUG();
}
lcd_dma.mirror = mirror;
}
void omap_set_lcd_dma_b1_vxres(unsigned long vxres)
{
if (cpu_is_omap15xx()) {
pr_err("DMA virtual resolution is not supported in 1510 mode\n");
BUG();
}
lcd_dma.vxres = vxres;
}
void omap_set_lcd_dma_b1_scale(unsigned int xscale, unsigned int yscale)
{
if (cpu_is_omap15xx()) {
printk(KERN_ERR "DMA scale is not supported in 1510 mode\n");
BUG();
}
lcd_dma.xscale = xscale;
lcd_dma.yscale = yscale;
}
static void set_b1_regs(void)
{
unsigned long top, bottom;
int es;
u16 w;
unsigned long en, fn;
long ei, fi;
unsigned long vxres;
unsigned int xscale, yscale;
switch (lcd_dma.data_type) {
case OMAP_DMA_DATA_TYPE_S8:
es = 1;
break;
case OMAP_DMA_DATA_TYPE_S16:
es = 2;
break;
case OMAP_DMA_DATA_TYPE_S32:
es = 4;
break;
default:
BUG();
return;
}
vxres = lcd_dma.vxres ? lcd_dma.vxres : lcd_dma.xres;
xscale = lcd_dma.xscale ? lcd_dma.xscale : 1;
yscale = lcd_dma.yscale ? lcd_dma.yscale : 1;
BUG_ON(vxres < lcd_dma.xres);
#define PIXADDR(x, y) (lcd_dma.addr + \
((y) * vxres * yscale + (x) * xscale) * es)
#define PIXSTEP(sx, sy, dx, dy) (PIXADDR(dx, dy) - PIXADDR(sx, sy) - es + 1)
switch (lcd_dma.rotate) {
case 0:
if (!lcd_dma.mirror) {
top = PIXADDR(0, 0);
bottom = PIXADDR(lcd_dma.xres - 1, lcd_dma.yres - 1);
if (cpu_is_omap15xx() &&
lcd_dma.data_type == OMAP_DMA_DATA_TYPE_S32)
bottom += 2;
ei = PIXSTEP(0, 0, 1, 0);
fi = PIXSTEP(lcd_dma.xres - 1, 0, 0, 1);
} else {
top = PIXADDR(lcd_dma.xres - 1, 0);
bottom = PIXADDR(0, lcd_dma.yres - 1);
ei = PIXSTEP(1, 0, 0, 0);
fi = PIXSTEP(0, 0, lcd_dma.xres - 1, 1);
}
en = lcd_dma.xres;
fn = lcd_dma.yres;
break;
case 90:
if (!lcd_dma.mirror) {
top = PIXADDR(0, lcd_dma.yres - 1);
bottom = PIXADDR(lcd_dma.xres - 1, 0);
ei = PIXSTEP(0, 1, 0, 0);
fi = PIXSTEP(0, 0, 1, lcd_dma.yres - 1);
} else {
top = PIXADDR(lcd_dma.xres - 1, lcd_dma.yres - 1);
bottom = PIXADDR(0, 0);
ei = PIXSTEP(0, 1, 0, 0);
fi = PIXSTEP(1, 0, 0, lcd_dma.yres - 1);
}
en = lcd_dma.yres;
fn = lcd_dma.xres;
break;
case 180:
if (!lcd_dma.mirror) {
top = PIXADDR(lcd_dma.xres - 1, lcd_dma.yres - 1);
bottom = PIXADDR(0, 0);
ei = PIXSTEP(1, 0, 0, 0);
fi = PIXSTEP(0, 1, lcd_dma.xres - 1, 0);
} else {
top = PIXADDR(0, lcd_dma.yres - 1);
bottom = PIXADDR(lcd_dma.xres - 1, 0);
ei = PIXSTEP(0, 0, 1, 0);
fi = PIXSTEP(lcd_dma.xres - 1, 1, 0, 0);
}
en = lcd_dma.xres;
fn = lcd_dma.yres;
break;
case 270:
if (!lcd_dma.mirror) {
top = PIXADDR(lcd_dma.xres - 1, 0);
bottom = PIXADDR(0, lcd_dma.yres - 1);
ei = PIXSTEP(0, 0, 0, 1);
fi = PIXSTEP(1, lcd_dma.yres - 1, 0, 0);
} else {
top = PIXADDR(0, 0);
bottom = PIXADDR(lcd_dma.xres - 1, lcd_dma.yres - 1);
ei = PIXSTEP(0, 0, 0, 1);
fi = PIXSTEP(0, lcd_dma.yres - 1, 1, 0);
}
en = lcd_dma.yres;
fn = lcd_dma.xres;
break;
default:
BUG();
return;
}
if (cpu_is_omap15xx()) {
omap_writew(top >> 16, OMAP1510_DMA_LCD_TOP_F1_U);
omap_writew(top, OMAP1510_DMA_LCD_TOP_F1_L);
omap_writew(bottom >> 16, OMAP1510_DMA_LCD_BOT_F1_U);
omap_writew(bottom, OMAP1510_DMA_LCD_BOT_F1_L);
return;
}
omap_writew(top >> 16, OMAP1610_DMA_LCD_TOP_B1_U);
omap_writew(top, OMAP1610_DMA_LCD_TOP_B1_L);
omap_writew(bottom >> 16, OMAP1610_DMA_LCD_BOT_B1_U);
omap_writew(bottom, OMAP1610_DMA_LCD_BOT_B1_L);
omap_writew(en, OMAP1610_DMA_LCD_SRC_EN_B1);
omap_writew(fn, OMAP1610_DMA_LCD_SRC_FN_B1);
w = omap_readw(OMAP1610_DMA_LCD_CSDP);
w &= ~0x03;
w |= lcd_dma.data_type;
omap_writew(w, OMAP1610_DMA_LCD_CSDP);
w = omap_readw(OMAP1610_DMA_LCD_CTRL);
w &= ~(0x03 << 6);
if (lcd_dma.callback != NULL)
w |= 1 << 1;
else
w &= ~(1 << 1);
omap_writew(w, OMAP1610_DMA_LCD_CTRL);
if (!(lcd_dma.rotate || lcd_dma.mirror ||
lcd_dma.vxres || lcd_dma.xscale || lcd_dma.yscale))
return;
w = omap_readw(OMAP1610_DMA_LCD_CCR);
w |= (0x03 << 12);
omap_writew(w, OMAP1610_DMA_LCD_CCR);
omap_writew(ei, OMAP1610_DMA_LCD_SRC_EI_B1);
omap_writew(fi >> 16, OMAP1610_DMA_LCD_SRC_FI_B1_U);
omap_writew(fi, OMAP1610_DMA_LCD_SRC_FI_B1_L);
}
static irqreturn_t lcd_dma_irq_handler(int irq, void *dev_id)
{
u16 w;
w = omap_readw(OMAP1610_DMA_LCD_CTRL);
if (unlikely(!(w & (1 << 3)))) {
printk(KERN_WARNING "Spurious LCD DMA IRQ\n");
return IRQ_NONE;
}
w |= (1 << 3);
omap_writew(w, OMAP1610_DMA_LCD_CTRL);
lcd_dma.active = 0;
if (lcd_dma.callback != NULL)
lcd_dma.callback(w, lcd_dma.cb_data);
return IRQ_HANDLED;
}
int omap_request_lcd_dma(void (*callback)(u16 status, void *data),
void *data)
{
spin_lock_irq(&lcd_dma.lock);
if (lcd_dma.reserved) {
spin_unlock_irq(&lcd_dma.lock);
printk(KERN_ERR "LCD DMA channel already reserved\n");
BUG();
return -EBUSY;
}
lcd_dma.reserved = 1;
spin_unlock_irq(&lcd_dma.lock);
lcd_dma.callback = callback;
lcd_dma.cb_data = data;
lcd_dma.active = 0;
lcd_dma.single_transfer = 0;
lcd_dma.rotate = 0;
lcd_dma.vxres = 0;
lcd_dma.mirror = 0;
lcd_dma.xscale = 0;
lcd_dma.yscale = 0;
lcd_dma.ext_ctrl = 0;
lcd_dma.src_port = 0;
return 0;
}
void omap_free_lcd_dma(void)
{
spin_lock(&lcd_dma.lock);
if (!lcd_dma.reserved) {
spin_unlock(&lcd_dma.lock);
printk(KERN_ERR "LCD DMA is not reserved\n");
BUG();
return;
}
if (!cpu_is_omap15xx())
omap_writew(omap_readw(OMAP1610_DMA_LCD_CCR) & ~1,
OMAP1610_DMA_LCD_CCR);
lcd_dma.reserved = 0;
spin_unlock(&lcd_dma.lock);
}
void omap_enable_lcd_dma(void)
{
u16 w;
if (cpu_is_omap15xx() || !lcd_dma.ext_ctrl)
return;
w = omap_readw(OMAP1610_DMA_LCD_CTRL);
w |= 1 << 8;
omap_writew(w, OMAP1610_DMA_LCD_CTRL);
lcd_dma.active = 1;
w = omap_readw(OMAP1610_DMA_LCD_CCR);
w |= 1 << 7;
omap_writew(w, OMAP1610_DMA_LCD_CCR);
}
void omap_setup_lcd_dma(void)
{
BUG_ON(lcd_dma.active);
if (!cpu_is_omap15xx()) {
omap_writew(0x5440, OMAP1610_DMA_LCD_CCR);
omap_writew(0x9102, OMAP1610_DMA_LCD_CSDP);
omap_writew(0x0004, OMAP1610_DMA_LCD_LCH_CTRL);
}
set_b1_regs();
if (!cpu_is_omap15xx()) {
u16 w;
w = omap_readw(OMAP1610_DMA_LCD_CCR);
w |= 1 << 11;
if (!lcd_dma.single_transfer)
w |= (3 << 8);
omap_writew(w, OMAP1610_DMA_LCD_CCR);
}
}
void omap_stop_lcd_dma(void)
{
u16 w;
lcd_dma.active = 0;
if (cpu_is_omap15xx() || !lcd_dma.ext_ctrl)
return;
w = omap_readw(OMAP1610_DMA_LCD_CCR);
w &= ~(1 << 7);
omap_writew(w, OMAP1610_DMA_LCD_CCR);
w = omap_readw(OMAP1610_DMA_LCD_CTRL);
w &= ~(1 << 8);
omap_writew(w, OMAP1610_DMA_LCD_CTRL);
}
static int __init omap_init_lcd_dma(void)
{
int r;
if (!cpu_class_is_omap1())
return -ENODEV;
if (cpu_is_omap16xx()) {
u16 w;
w = omap_readw(OMAP1610_DMA_LCD_CTRL);
w &= ~(1 << 8);
omap_writew(w, OMAP1610_DMA_LCD_CTRL);
}
spin_lock_init(&lcd_dma.lock);
r = request_irq(INT_DMA_LCD, lcd_dma_irq_handler, 0,
"LCD DMA", NULL);
if (r != 0)
pr_err("unable to request IRQ for LCD DMA (error %d)\n", r);
return r;
}
