static int crvml_sys_restore(struct vml_sys *sys)
{
void __iomem *clock_reg = mch_regs_base + CRVML_REG_CLOCK;
iowrite32(saved_clock, clock_reg);
ioread32(clock_reg);
return 0;
}
static int crvml_sys_save(struct vml_sys *sys)
{
void __iomem *clock_reg = mch_regs_base + CRVML_REG_CLOCK;
saved_clock = ioread32(clock_reg);
return 0;
}
static int crvml_nearest_index(const struct vml_sys *sys, int clock)
{
int i;
int cur_index = 0;
int cur_diff;
int diff;
cur_diff = clock - crvml_clocks[0];
cur_diff = (cur_diff < 0) ? -cur_diff : cur_diff;
for (i = 1; i < crvml_num_clocks; ++i) {
diff = clock - crvml_clocks[i];
diff = (diff < 0) ? -diff : diff;
if (diff < cur_diff) {
cur_index = i;
cur_diff = diff;
}
}
return cur_index;
}
static int crvml_nearest_clock(const struct vml_sys *sys, int clock)
{
return crvml_clocks[crvml_nearest_index(sys, clock)];
}
static int crvml_set_clock(struct vml_sys *sys, int clock)
{
void __iomem *clock_reg = mch_regs_base + CRVML_REG_CLOCK;
int index;
u32 clock_val;
index = crvml_nearest_index(sys, clock);
if (crvml_clocks[index] != clock)
return -EINVAL;
clock_val = ioread32(clock_reg) & ~CRVML_CLOCK_MASK;
clock_val = crvml_clock_bits[index] << CRVML_CLOCK_SHIFT;
iowrite32(clock_val, clock_reg);
ioread32(clock_reg);
return 0;
}
static int __init cr_pll_init(void)
{
int err;
u32 dev_en;
mch_dev = pci_get_device(PCI_VENDOR_ID_INTEL,
CRVML_DEVICE_MCH, NULL);
if (!mch_dev) {
printk(KERN_ERR
"Could not find Carillo Ranch MCH device.\n");
return -ENODEV;
}
pci_read_config_dword(mch_dev, CRVML_REG_MCHEN, &dev_en);
if (!(dev_en & CRVML_MCHEN_BIT)) {
printk(KERN_ERR
"Carillo Ranch MCH device was not enabled.\n");
pci_dev_put(mch_dev);
return -ENODEV;
}
pci_read_config_dword(mch_dev, CRVML_REG_MCHBAR,
&mch_bar);
mch_regs_base =
ioremap_nocache(mch_bar, CRVML_MCHMAP_SIZE);
if (!mch_regs_base) {
printk(KERN_ERR
"Carillo Ranch MCH device was not enabled.\n");
pci_dev_put(mch_dev);
return -ENODEV;
}
err = vmlfb_register_subsys(&cr_pll_ops);
if (err) {
printk(KERN_ERR
"Carillo Ranch failed to initialize vml_sys.\n");
pci_dev_put(mch_dev);
return err;
}
return 0;
}
static void __exit cr_pll_exit(void)
{
vmlfb_unregister_subsys(&cr_pll_ops);
iounmap(mch_regs_base);
pci_dev_put(mch_dev);
}
