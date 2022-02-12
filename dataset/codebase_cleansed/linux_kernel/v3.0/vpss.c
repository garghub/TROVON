static inline u32 bl_regr(u32 offset)
{
return __raw_readl(oper_cfg.vpss_regs_base0 + offset);
}
static inline void bl_regw(u32 val, u32 offset)
{
__raw_writel(val, oper_cfg.vpss_regs_base0 + offset);
}
static inline u32 vpss_regr(u32 offset)
{
return __raw_readl(oper_cfg.vpss_regs_base1 + offset);
}
static inline void vpss_regw(u32 val, u32 offset)
{
__raw_writel(val, oper_cfg.vpss_regs_base1 + offset);
}
static inline u32 isp5_read(u32 offset)
{
return __raw_readl(oper_cfg.vpss_regs_base0 + offset);
}
static inline void isp5_write(u32 val, u32 offset)
{
__raw_writel(val, oper_cfg.vpss_regs_base0 + offset);
}
static void dm365_select_ccdc_source(enum vpss_ccdc_source_sel src_sel)
{
u32 temp = isp5_read(DM365_ISP5_CCDCMUX) & ~CCD_SRC_SEL_MASK;
if (src_sel == VPSS_PGLPBK || src_sel == VPSS_CCDCPG)
temp |= 0x08;
temp |= (src_sel << CCD_SRC_SEL_SHIFT);
isp5_write(temp, DM365_ISP5_CCDCMUX);
}
static void dm355_select_ccdc_source(enum vpss_ccdc_source_sel src_sel)
{
bl_regw(src_sel << VPSS_HSSISEL_SHIFT, DM355_VPSSBL_CCDCMUX);
}
int vpss_select_ccdc_source(enum vpss_ccdc_source_sel src_sel)
{
if (!oper_cfg.hw_ops.select_ccdc_source)
return -EINVAL;
oper_cfg.hw_ops.select_ccdc_source(src_sel);
return 0;
}
static int dm644x_clear_wbl_overflow(enum vpss_wbl_sel wbl_sel)
{
u32 mask = 1, val;
if (wbl_sel < VPSS_PCR_AEW_WBL_0 ||
wbl_sel > VPSS_PCR_CCDC_WBL_O)
return -EINVAL;
mask = ~(mask << wbl_sel);
val = bl_regr(DM644X_SBL_PCR_VPSS) & mask;
bl_regw(val, DM644X_SBL_PCR_VPSS);
return 0;
}
int vpss_clear_wbl_overflow(enum vpss_wbl_sel wbl_sel)
{
if (!oper_cfg.hw_ops.clear_wbl_overflow)
return -EINVAL;
return oper_cfg.hw_ops.clear_wbl_overflow(wbl_sel);
}
static int dm355_enable_clock(enum vpss_clock_sel clock_sel, int en)
{
unsigned long flags;
u32 utemp, mask = 0x1, shift = 0;
switch (clock_sel) {
case VPSS_VPBE_CLOCK:
break;
case VPSS_VENC_CLOCK_SEL:
shift = 2;
break;
case VPSS_CFALD_CLOCK:
shift = 3;
break;
case VPSS_H3A_CLOCK:
shift = 4;
break;
case VPSS_IPIPE_CLOCK:
shift = 5;
break;
case VPSS_CCDC_CLOCK:
shift = 6;
break;
default:
printk(KERN_ERR "dm355_enable_clock:"
" Invalid selector: %d\n", clock_sel);
return -EINVAL;
}
spin_lock_irqsave(&oper_cfg.vpss_lock, flags);
utemp = vpss_regr(DM355_VPSSCLK_CLKCTRL);
if (!en)
utemp &= ~(mask << shift);
else
utemp |= (mask << shift);
vpss_regw(utemp, DM355_VPSSCLK_CLKCTRL);
spin_unlock_irqrestore(&oper_cfg.vpss_lock, flags);
return 0;
}
static int dm365_enable_clock(enum vpss_clock_sel clock_sel, int en)
{
unsigned long flags;
u32 utemp, mask = 0x1, shift = 0, offset = DM365_ISP5_PCCR;
u32 (*read)(u32 offset) = isp5_read;
void(*write)(u32 val, u32 offset) = isp5_write;
switch (clock_sel) {
case VPSS_BL_CLOCK:
break;
case VPSS_CCDC_CLOCK:
shift = 1;
break;
case VPSS_H3A_CLOCK:
shift = 2;
break;
case VPSS_RSZ_CLOCK:
shift = 3;
break;
case VPSS_IPIPE_CLOCK:
shift = 4;
break;
case VPSS_IPIPEIF_CLOCK:
shift = 5;
break;
case VPSS_PCLK_INTERNAL:
shift = 6;
break;
case VPSS_PSYNC_CLOCK_SEL:
shift = 7;
break;
case VPSS_VPBE_CLOCK:
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
case VPSS_VENC_CLOCK_SEL:
shift = 2;
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
case VPSS_LDC_CLOCK:
shift = 3;
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
case VPSS_FDIF_CLOCK:
shift = 4;
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
case VPSS_OSD_CLOCK_SEL:
shift = 6;
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
case VPSS_LDC_CLOCK_SEL:
shift = 7;
read = vpss_regr;
write = vpss_regw;
offset = DM365_VPBE_CLK_CTRL;
break;
default:
printk(KERN_ERR "dm365_enable_clock: Invalid selector: %d\n",
clock_sel);
return -1;
}
spin_lock_irqsave(&oper_cfg.vpss_lock, flags);
utemp = read(offset);
if (!en) {
mask = ~mask;
utemp &= (mask << shift);
} else
utemp |= (mask << shift);
write(utemp, offset);
spin_unlock_irqrestore(&oper_cfg.vpss_lock, flags);
return 0;
}
int vpss_enable_clock(enum vpss_clock_sel clock_sel, int en)
{
if (!oper_cfg.hw_ops.enable_clock)
return -EINVAL;
return oper_cfg.hw_ops.enable_clock(clock_sel, en);
}
void dm365_vpss_set_sync_pol(struct vpss_sync_pol sync)
{
int val = 0;
val = isp5_read(DM365_ISP5_CCDCMUX);
val |= (sync.ccdpg_hdpol << DM365_CCDC_PG_HD_POL_SHIFT);
val |= (sync.ccdpg_vdpol << DM365_CCDC_PG_VD_POL_SHIFT);
isp5_write(val, DM365_ISP5_CCDCMUX);
}
void dm365_vpss_set_pg_frame_size(struct vpss_pg_frame_size frame_size)
{
int current_reg = ((frame_size.hlpfr >> 1) - 1) << 16;
current_reg |= (frame_size.pplen - 1);
isp5_write(current_reg, DM365_ISP5_PG_FRAME_SIZE);
}
static int __init vpss_probe(struct platform_device *pdev)
{
struct resource *r1, *r2;
char *platform_name;
int status;
if (!pdev->dev.platform_data) {
dev_err(&pdev->dev, "no platform data\n");
return -ENOENT;
}
platform_name = pdev->dev.platform_data;
if (!strcmp(platform_name, "dm355_vpss"))
oper_cfg.platform = DM355;
else if (!strcmp(platform_name, "dm365_vpss"))
oper_cfg.platform = DM365;
else if (!strcmp(platform_name, "dm644x_vpss"))
oper_cfg.platform = DM644X;
else {
dev_err(&pdev->dev, "vpss driver not supported on"
" this platform\n");
return -ENODEV;
}
dev_info(&pdev->dev, "%s vpss probed\n", platform_name);
r1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r1)
return -ENOENT;
r1 = request_mem_region(r1->start, resource_size(r1), r1->name);
if (!r1)
return -EBUSY;
oper_cfg.vpss_regs_base0 = ioremap(r1->start, resource_size(r1));
if (!oper_cfg.vpss_regs_base0) {
status = -EBUSY;
goto fail1;
}
if (oper_cfg.platform == DM355 || oper_cfg.platform == DM365) {
r2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!r2) {
status = -ENOENT;
goto fail2;
}
r2 = request_mem_region(r2->start, resource_size(r2), r2->name);
if (!r2) {
status = -EBUSY;
goto fail2;
}
oper_cfg.vpss_regs_base1 = ioremap(r2->start,
resource_size(r2));
if (!oper_cfg.vpss_regs_base1) {
status = -EBUSY;
goto fail3;
}
}
if (oper_cfg.platform == DM355) {
oper_cfg.hw_ops.enable_clock = dm355_enable_clock;
oper_cfg.hw_ops.select_ccdc_source = dm355_select_ccdc_source;
bl_regw(DM355_VPSSBL_INTSEL_DEFAULT, DM355_VPSSBL_INTSEL);
bl_regw(DM355_VPSSBL_EVTSEL_DEFAULT, DM355_VPSSBL_EVTSEL);
} else if (oper_cfg.platform == DM365) {
oper_cfg.hw_ops.enable_clock = dm365_enable_clock;
oper_cfg.hw_ops.select_ccdc_source = dm365_select_ccdc_source;
isp5_write(DM365_ISP5_INTSEL1_DEFAULT, DM365_ISP5_INTSEL1);
isp5_write(DM365_ISP5_INTSEL2_DEFAULT, DM365_ISP5_INTSEL2);
isp5_write(DM365_ISP5_INTSEL3_DEFAULT, DM365_ISP5_INTSEL3);
} else
oper_cfg.hw_ops.clear_wbl_overflow = dm644x_clear_wbl_overflow;
spin_lock_init(&oper_cfg.vpss_lock);
dev_info(&pdev->dev, "%s vpss probe success\n", platform_name);
return 0;
fail3:
release_mem_region(r2->start, resource_size(r2));
fail2:
iounmap(oper_cfg.vpss_regs_base0);
fail1:
release_mem_region(r1->start, resource_size(r1));
return status;
}
static int __devexit vpss_remove(struct platform_device *pdev)
{
struct resource *res;
iounmap(oper_cfg.vpss_regs_base0);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
if (oper_cfg.platform == DM355 || oper_cfg.platform == DM365) {
iounmap(oper_cfg.vpss_regs_base1);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
release_mem_region(res->start, resource_size(res));
}
return 0;
}
static void vpss_exit(void)
{
platform_driver_unregister(&vpss_driver);
}
static int __init vpss_init(void)
{
return platform_driver_register(&vpss_driver);
}
