int pcibios_plat_dev_init(struct pci_dev *dev)
{
if (ltqpci_plat_dev_init)
return ltqpci_plat_dev_init(dev);
return 0;
}
static u32 ltq_calc_bar11mask(void)
{
u32 mem, bar11mask;
mem = num_physpages * PAGE_SIZE;
bar11mask = (0x0ffffff0 & ~((1 << (fls(mem) - 1)) - 1)) | 8;
return bar11mask;
}
static void ltq_pci_setup_gpio(int gpio)
{
int i;
for (i = 0; i < ARRAY_SIZE(ltq_pci_gpio_map); i++) {
if (gpio & (1 << i)) {
ltq_gpio_request(ltq_pci_gpio_map[i].pin,
ltq_pci_gpio_map[i].alt0,
ltq_pci_gpio_map[i].alt1,
ltq_pci_gpio_map[i].dir,
ltq_pci_gpio_map[i].name);
}
}
ltq_gpio_request(21, 0, 0, 1, "pci-reset");
ltq_pci_req_mask = (gpio >> PCI_REQ_SHIFT) & PCI_REQ_MASK;
}
static int __devinit ltq_pci_startup(struct ltq_pci_data *conf)
{
u32 temp_buffer;
if (ltq_is_ar9()) {
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) & ~0x1f00000, LTQ_CGU_IFCCR);
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) | 0xe00000, LTQ_CGU_IFCCR);
} else {
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) & ~0xf00000, LTQ_CGU_IFCCR);
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) | 0x800000, LTQ_CGU_IFCCR);
}
if (conf->clock) {
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) & ~(1 << 16),
LTQ_CGU_IFCCR);
ltq_cgu_w32((1 << 30), LTQ_CGU_PCICR);
} else {
ltq_cgu_w32(ltq_cgu_r32(LTQ_CGU_IFCCR) | (1 << 16),
LTQ_CGU_IFCCR);
ltq_cgu_w32((1 << 31) | (1 << 30), LTQ_CGU_PCICR);
}
ltq_pci_setup_gpio(conf->gpio);
ltq_pci_w32(0xa, PCI_CR_CLK_CTRL);
ltq_pci_w32(ltq_pci_r32(PCI_CR_PCI_MOD) & ~(1 << 24), PCI_CR_PCI_MOD);
wmb();
ltq_pci_cfg_w32(ltq_pci_cfg_r32(PCI_CS_STS_CMD) | 7, PCI_CS_STS_CMD);
temp_buffer = ltq_pci_r32(PCI_CR_PC_ARB);
temp_buffer &= (~(ltq_pci_req_mask << 16));
temp_buffer |= (1 << INTERNAL_ARB_ENABLE_BIT);
temp_buffer &= (~(3 << PCI_MASTER0_REQ_MASK_2BITS));
temp_buffer &= (~(3 << PCI_MASTER1_REQ_MASK_2BITS));
temp_buffer &= (~(3 << PCI_MASTER2_REQ_MASK_2BITS));
ltq_pci_w32(temp_buffer, PCI_CR_PC_ARB);
wmb();
ltq_pci_w32(0x18000000, PCI_CR_FCI_ADDR_MAP0);
ltq_pci_w32(0x18400000, PCI_CR_FCI_ADDR_MAP1);
ltq_pci_w32(0x18800000, PCI_CR_FCI_ADDR_MAP2);
ltq_pci_w32(0x18c00000, PCI_CR_FCI_ADDR_MAP3);
ltq_pci_w32(0x19000000, PCI_CR_FCI_ADDR_MAP4);
ltq_pci_w32(0x19400000, PCI_CR_FCI_ADDR_MAP5);
ltq_pci_w32(0x19800000, PCI_CR_FCI_ADDR_MAP6);
ltq_pci_w32(0x19c00000, PCI_CR_FCI_ADDR_MAP7);
ltq_pci_w32(0x1ae00000, PCI_CR_FCI_ADDR_MAP11hg);
ltq_pci_w32(ltq_calc_bar11mask(), PCI_CR_BAR11MASK);
ltq_pci_w32(0, PCI_CR_PCI_ADDR_MAP11);
ltq_pci_w32(0, PCI_CS_BASE_ADDR1);
ltq_pci_w32(ltq_pci_r32(PCI_CR_PCI_EOI) | 3, PCI_CR_PCI_EOI);
wmb();
ltq_pci_w32(ltq_pci_r32(PCI_CR_BAR12MASK) | 0x80000000,
PCI_CR_BAR12MASK);
ltq_pci_w32(ltq_pci_r32(PCI_CR_BAR13MASK) | 0x80000000,
PCI_CR_BAR13MASK);
ltq_pci_w32(0x303, PCI_CR_FCI_BURST_LENGTH);
ltq_pci_w32(ltq_pci_r32(PCI_CR_PCI_MOD) | (1 << 24), PCI_CR_PCI_MOD);
wmb();
ltq_ebu_w32(ltq_ebu_r32(LTQ_EBU_PCC_CON) | 0xc, LTQ_EBU_PCC_CON);
ltq_ebu_w32(ltq_ebu_r32(LTQ_EBU_PCC_IEN) | 0x10, LTQ_EBU_PCC_IEN);
__gpio_set_value(21, 0);
wmb();
mdelay(1);
__gpio_set_value(21, 1);
return 0;
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (ltq_pci_irq_map[slot])
return ltq_pci_irq_map[slot];
printk(KERN_ERR "lq_pci: trying to map irq for unknown slot %d\n",
slot);
return 0;
}
static int __devinit ltq_pci_probe(struct platform_device *pdev)
{
struct ltq_pci_data *ltq_pci_data =
(struct ltq_pci_data *) pdev->dev.platform_data;
pci_clear_flags(PCI_PROBE_ONLY);
ltq_pci_irq_map = ltq_pci_data->irq;
ltq_pci_membase = ioremap_nocache(PCI_CR_BASE_ADDR, PCI_CR_SIZE);
ltq_pci_mapped_cfg =
ioremap_nocache(LTQ_PCI_CFG_BASE, LTQ_PCI_CFG_BASE);
ltq_pci_controller.io_map_base =
(unsigned long)ioremap(LTQ_PCI_IO_BASE, LTQ_PCI_IO_SIZE - 1);
ltq_pci_startup(ltq_pci_data);
register_pci_controller(&ltq_pci_controller);
return 0;
}
int __init pcibios_init(void)
{
int ret = platform_driver_register(&ltq_pci_driver);
if (ret)
printk(KERN_INFO "ltq_pci: Error registering platfom driver!");
return ret;
}
