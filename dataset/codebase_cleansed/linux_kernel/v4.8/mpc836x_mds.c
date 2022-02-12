static void __init mpc836x_mds_setup_arch(void)
{
struct device_node *np;
u8 __iomem *bcsr_regs = NULL;
if (ppc_md.progress)
ppc_md.progress("mpc836x_mds_setup_arch()", 0);
np = of_find_node_by_name(NULL, "bcsr");
if (np) {
struct resource res;
of_address_to_resource(np, 0, &res);
bcsr_regs = ioremap(res.start, resource_size(&res));
of_node_put(np);
}
mpc83xx_setup_pci();
#ifdef CONFIG_QUICC_ENGINE
if ((np = of_find_node_by_name(NULL, "par_io")) != NULL) {
par_io_init(np);
of_node_put(np);
for (np = NULL; (np = of_find_node_by_name(np, "ucc")) != NULL;)
par_io_of_config(np);
#ifdef CONFIG_QE_USB
par_io_config_pin(1, 2, 1, 0, 3, 0);
par_io_config_pin(1, 3, 1, 0, 3, 0);
par_io_config_pin(1, 8, 1, 0, 1, 0);
par_io_config_pin(1, 10, 2, 0, 3, 0);
par_io_config_pin(1, 9, 2, 1, 3, 0);
par_io_config_pin(1, 11, 2, 1, 3, 0);
par_io_config_pin(2, 20, 2, 0, 1, 0);
#endif
}
if ((np = of_find_compatible_node(NULL, "network", "ucc_geth"))
!= NULL){
uint svid;
#define BCSR9_GETHRST 0x20
clrbits8(&bcsr_regs[9], BCSR9_GETHRST);
udelay(1000);
setbits8(&bcsr_regs[9], BCSR9_GETHRST);
svid = mfspr(SPRN_SVR);
if (svid == 0x80480021) {
void __iomem *immap;
immap = ioremap(get_immrbase() + 0x14a8, 8);
setbits32(immap, 0x0c003000);
clrsetbits_be32(immap + 4, 0xff0, 0xaa0);
iounmap(immap);
}
iounmap(bcsr_regs);
of_node_put(np);
}
#endif
}
static int __init mpc836x_usb_cfg(void)
{
u8 __iomem *bcsr;
struct device_node *np;
const char *mode;
int ret = 0;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc8360mds-bcsr");
if (!np)
return -ENODEV;
bcsr = of_iomap(np, 0);
of_node_put(np);
if (!bcsr)
return -ENOMEM;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc8323-qe-usb");
if (!np) {
ret = -ENODEV;
goto err;
}
#define BCSR8_TSEC1M_MASK (0x3 << 6)
#define BCSR8_TSEC1M_RGMII (0x0 << 6)
#define BCSR8_TSEC2M_MASK (0x3 << 4)
#define BCSR8_TSEC2M_RGMII (0x0 << 4)
clrsetbits_8(&bcsr[8], BCSR8_TSEC1M_MASK | BCSR8_TSEC2M_MASK,
BCSR8_TSEC1M_RGMII | BCSR8_TSEC2M_RGMII);
#define BCSR13_USBMASK 0x0f
#define BCSR13_nUSBEN 0x08
#define BCSR13_USBSPEED 0x04
#define BCSR13_USBMODE 0x02
#define BCSR13_nUSBVCC 0x01
clrsetbits_8(&bcsr[13], BCSR13_USBMASK, BCSR13_USBSPEED);
mode = of_get_property(np, "mode", NULL);
if (mode && !strcmp(mode, "peripheral")) {
setbits8(&bcsr[13], BCSR13_nUSBVCC);
qe_usb_clock_set(QE_CLK21, 48000000);
} else {
setbits8(&bcsr[13], BCSR13_USBMODE);
simple_gpiochip_init("fsl,mpc8360mds-bcsr-gpio");
}
of_node_put(np);
err:
iounmap(bcsr);
return ret;
}
static int __init mpc836x_mds_probe(void)
{
return of_machine_is_compatible("MPC836xMDS");
}
