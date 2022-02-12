static int mpc837xmds_usb_cfg(void)
{
struct device_node *np;
const void *phy_type, *mode;
void __iomem *bcsr_regs = NULL;
u8 bcsr12;
int ret;
ret = mpc837x_usb_cfg();
if (ret)
return ret;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc837xmds-bcsr");
if (np) {
bcsr_regs = of_iomap(np, 0);
of_node_put(np);
}
if (!bcsr_regs)
return -1;
np = of_find_node_by_name(NULL, "usb");
if (!np) {
ret = -ENODEV;
goto out;
}
phy_type = of_get_property(np, "phy_type", NULL);
if (phy_type && !strcmp(phy_type, "ulpi")) {
clrbits8(bcsr_regs + 12, BCSR12_USB_SER_PIN);
} else if (phy_type && !strcmp(phy_type, "serial")) {
mode = of_get_property(np, "dr_mode", NULL);
bcsr12 = in_8(bcsr_regs + 12) & ~BCSR12_USB_SER_MASK;
bcsr12 |= BCSR12_USB_SER_PIN;
if (mode && !strcmp(mode, "peripheral"))
bcsr12 |= BCSR12_USB_SER_DEVICE;
out_8(bcsr_regs + 12, bcsr12);
} else {
printk(KERN_ERR "USB DR: unsupported PHY\n");
}
of_node_put(np);
out:
iounmap(bcsr_regs);
return ret;
}
static void __init mpc837x_mds_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc837x_mds_setup_arch()", 0);
mpc83xx_setup_pci();
mpc837xmds_usb_cfg();
}
static int __init mpc837x_mds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc837xmds");
}
