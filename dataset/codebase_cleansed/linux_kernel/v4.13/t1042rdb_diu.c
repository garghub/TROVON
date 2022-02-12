static void t1042rdb_set_monitor_port(enum fsl_diu_monitor_port port)
{
static void __iomem *cpld_base;
cpld_base = of_iomap(cpld_node, 0);
if (!cpld_base) {
pr_err("%s: Could not map cpld registers\n", __func__);
goto exit;
}
switch (port) {
case FSL_DIU_PORT_DVI:
clrbits8(cpld_base + CPLD_DIUCSR, CPLD_DIUCSR_DVIEN);
break;
case FSL_DIU_PORT_LVDS:
setbits8(cpld_base + CPLD_DIUCSR, 0x01 << 8);
setbits8(cpld_base + CPLD_DIUCSR, 0x01 << 4);
setbits8(cpld_base + CPLD_DIUCSR, CPLD_DIUCSR_BACKLIGHT);
break;
default:
pr_err("%s: Unsupported monitor port %i\n", __func__, port);
}
iounmap(cpld_base);
exit:
of_node_put(cpld_node);
}
static void t1042rdb_set_pixel_clock(unsigned int pixclock)
{
struct device_node *scfg_np;
void __iomem *scfg;
unsigned long freq;
u64 temp;
u32 pxclk;
scfg_np = of_find_compatible_node(NULL, NULL, "fsl,t1040-scfg");
if (!scfg_np) {
pr_err("%s: Missing scfg node. Can not display video.\n",
__func__);
return;
}
scfg = of_iomap(scfg_np, 0);
of_node_put(scfg_np);
if (!scfg) {
pr_err("%s: Could not map device. Can not display video.\n",
__func__);
return;
}
temp = 1000000000000ULL;
do_div(temp, pixclock);
freq = temp;
pxclk = DIV_ROUND_CLOSEST(fsl_get_sys_freq(), freq);
pxclk = clamp_t(u32, pxclk, 2, 255);
clrbits32(scfg + CCSR_SCFG_PIXCLKCR,
PIXCLKCR_PXCKEN | PIXCLKCR_PXCKDLY | PIXCLKCR_PXCLK_MASK);
setbits32(scfg + CCSR_SCFG_PIXCLKCR, PIXCLKCR_PXCKEN | (pxclk << 16));
iounmap(scfg);
}
static enum fsl_diu_monitor_port
t1042rdb_valid_monitor_port(enum fsl_diu_monitor_port port)
{
switch (port) {
case FSL_DIU_PORT_DVI:
case FSL_DIU_PORT_LVDS:
return port;
default:
return FSL_DIU_PORT_DVI;
}
}
static int __init t1042rdb_diu_init(void)
{
cpld_node = of_find_compatible_node(NULL, NULL, "fsl,t1042rdb-cpld");
if (!cpld_node)
return 0;
diu_ops.set_monitor_port = t1042rdb_set_monitor_port;
diu_ops.set_pixel_clock = t1042rdb_set_pixel_clock;
diu_ops.valid_monitor_port = t1042rdb_valid_monitor_port;
return 0;
}
