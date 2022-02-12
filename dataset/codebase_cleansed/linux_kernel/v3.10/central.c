static int clock_board_calc_nslots(struct clock_board *p)
{
u8 reg = upa_readb(p->clock_regs + CLOCK_STAT1) & 0xc0;
switch (reg) {
case 0x40:
return 16;
case 0xc0:
return 8;
case 0x80:
reg = 0;
if (p->clock_ver_reg)
reg = upa_readb(p->clock_ver_reg);
if (reg) {
if (reg & 0x80)
return 4;
else
return 5;
}
default:
return 4;
}
}
static int clock_board_probe(struct platform_device *op)
{
struct clock_board *p = kzalloc(sizeof(*p), GFP_KERNEL);
int err = -ENOMEM;
if (!p) {
printk(KERN_ERR "clock_board: Cannot allocate struct clock_board\n");
goto out;
}
p->clock_freq_regs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]),
"clock_board_freq");
if (!p->clock_freq_regs) {
printk(KERN_ERR "clock_board: Cannot map clock_freq_regs\n");
goto out_free;
}
p->clock_regs = of_ioremap(&op->resource[1], 0,
resource_size(&op->resource[1]),
"clock_board_regs");
if (!p->clock_regs) {
printk(KERN_ERR "clock_board: Cannot map clock_regs\n");
goto out_unmap_clock_freq_regs;
}
if (op->resource[2].flags) {
p->clock_ver_reg = of_ioremap(&op->resource[2], 0,
resource_size(&op->resource[2]),
"clock_ver_reg");
if (!p->clock_ver_reg) {
printk(KERN_ERR "clock_board: Cannot map clock_ver_reg\n");
goto out_unmap_clock_regs;
}
}
p->num_slots = clock_board_calc_nslots(p);
p->leds_resource.start = (unsigned long)
(p->clock_regs + CLOCK_CTRL);
p->leds_resource.end = p->leds_resource.start;
p->leds_resource.name = "leds";
p->leds_pdev.name = "sunfire-clockboard-leds";
p->leds_pdev.id = -1;
p->leds_pdev.resource = &p->leds_resource;
p->leds_pdev.num_resources = 1;
p->leds_pdev.dev.parent = &op->dev;
err = platform_device_register(&p->leds_pdev);
if (err) {
printk(KERN_ERR "clock_board: Could not register LEDS "
"platform device\n");
goto out_unmap_clock_ver_reg;
}
printk(KERN_INFO "clock_board: Detected %d slot Enterprise system.\n",
p->num_slots);
err = 0;
out:
return err;
out_unmap_clock_ver_reg:
if (p->clock_ver_reg)
of_iounmap(&op->resource[2], p->clock_ver_reg,
resource_size(&op->resource[2]));
out_unmap_clock_regs:
of_iounmap(&op->resource[1], p->clock_regs,
resource_size(&op->resource[1]));
out_unmap_clock_freq_regs:
of_iounmap(&op->resource[0], p->clock_freq_regs,
resource_size(&op->resource[0]));
out_free:
kfree(p);
goto out;
}
static int fhc_probe(struct platform_device *op)
{
struct fhc *p = kzalloc(sizeof(*p), GFP_KERNEL);
int err = -ENOMEM;
u32 reg;
if (!p) {
printk(KERN_ERR "fhc: Cannot allocate struct fhc\n");
goto out;
}
if (!strcmp(op->dev.of_node->parent->name, "central"))
p->central = true;
p->pregs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]),
"fhc_pregs");
if (!p->pregs) {
printk(KERN_ERR "fhc: Cannot map pregs\n");
goto out_free;
}
if (p->central) {
reg = upa_readl(p->pregs + FHC_PREGS_BSR);
p->board_num = ((reg >> 16) & 1) | ((reg >> 12) & 0x0e);
} else {
p->board_num = of_getintprop_default(op->dev.of_node, "board#", -1);
if (p->board_num == -1) {
printk(KERN_ERR "fhc: No board# property\n");
goto out_unmap_pregs;
}
if (upa_readl(p->pregs + FHC_PREGS_JCTRL) & FHC_JTAG_CTRL_MENAB)
p->jtag_master = true;
}
if (!p->central) {
p->leds_resource.start = (unsigned long)
(p->pregs + FHC_PREGS_CTRL);
p->leds_resource.end = p->leds_resource.start;
p->leds_resource.name = "leds";
p->leds_pdev.name = "sunfire-fhc-leds";
p->leds_pdev.id = p->board_num;
p->leds_pdev.resource = &p->leds_resource;
p->leds_pdev.num_resources = 1;
p->leds_pdev.dev.parent = &op->dev;
err = platform_device_register(&p->leds_pdev);
if (err) {
printk(KERN_ERR "fhc: Could not register LEDS "
"platform device\n");
goto out_unmap_pregs;
}
}
reg = upa_readl(p->pregs + FHC_PREGS_CTRL);
if (!p->central)
reg |= FHC_CONTROL_IXIST;
reg &= ~(FHC_CONTROL_AOFF |
FHC_CONTROL_BOFF |
FHC_CONTROL_SLINE);
upa_writel(reg, p->pregs + FHC_PREGS_CTRL);
upa_readl(p->pregs + FHC_PREGS_CTRL);
reg = upa_readl(p->pregs + FHC_PREGS_ID);
printk(KERN_INFO "fhc: Board #%d, Version[%x] PartID[%x] Manuf[%x] %s\n",
p->board_num,
(reg & FHC_ID_VERS) >> 28,
(reg & FHC_ID_PARTID) >> 12,
(reg & FHC_ID_MANUF) >> 1,
(p->jtag_master ?
"(JTAG Master)" :
(p->central ? "(Central)" : "")));
err = 0;
out:
return err;
out_unmap_pregs:
of_iounmap(&op->resource[0], p->pregs, resource_size(&op->resource[0]));
out_free:
kfree(p);
goto out;
}
static int __init sunfire_init(void)
{
(void) platform_driver_register(&fhc_driver);
(void) platform_driver_register(&clock_board_driver);
return 0;
}
