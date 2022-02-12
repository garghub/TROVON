static inline u32 ltq_calc_bar11mask(void)
{
u32 mem, bar11mask;
mem = get_num_physpages() * PAGE_SIZE;
bar11mask = (0x0ffffff0 & ~((1 << (fls(mem) - 1)) - 1)) | 8;
return bar11mask;
}
static int ltq_pci_startup(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
const __be32 *req_mask, *bus_clk;
u32 temp_buffer;
clk_pci = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk_pci)) {
dev_err(&pdev->dev, "failed to get pci clock\n");
return PTR_ERR(clk_pci);
}
clk_external = clk_get(&pdev->dev, "external");
if (IS_ERR(clk_external)) {
clk_put(clk_pci);
dev_err(&pdev->dev, "failed to get external pci clock\n");
return PTR_ERR(clk_external);
}
bus_clk = of_get_property(node, "lantiq,bus-clock", NULL);
if (bus_clk)
clk_set_rate(clk_pci, *bus_clk);
clk_enable(clk_pci);
if (of_find_property(node, "lantiq,external-clock", NULL))
clk_enable(clk_external);
else
clk_disable(clk_external);
reset_gpio = of_get_named_gpio(node, "gpio-reset", 0);
if (gpio_is_valid(reset_gpio)) {
int ret = devm_gpio_request(&pdev->dev,
reset_gpio, "pci-reset");
if (ret) {
dev_err(&pdev->dev,
"failed to request gpio %d\n", reset_gpio);
return ret;
}
gpio_direction_output(reset_gpio, 1);
}
ltq_pci_w32(0xa, PCI_CR_CLK_CTRL);
ltq_pci_w32(ltq_pci_r32(PCI_CR_PCI_MOD) & ~(1 << 24), PCI_CR_PCI_MOD);
wmb();
ltq_pci_cfg_w32(ltq_pci_cfg_r32(PCI_CS_STS_CMD) | 7, PCI_CS_STS_CMD);
temp_buffer = ltq_pci_r32(PCI_CR_PC_ARB);
req_mask = of_get_property(node, "req-mask", NULL);
if (req_mask)
temp_buffer &= ~((*req_mask & 0xf) << 16);
else
temp_buffer &= ~0xf0000;
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
if (gpio_is_valid(reset_gpio)) {
__gpio_set_value(reset_gpio, 0);
wmb();
mdelay(1);
__gpio_set_value(reset_gpio, 1);
}
return 0;
}
static int ltq_pci_probe(struct platform_device *pdev)
{
struct resource *res_cfg, *res_bridge;
pci_clear_flags(PCI_PROBE_ONLY);
res_bridge = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ltq_pci_membase = devm_ioremap_resource(&pdev->dev, res_bridge);
if (IS_ERR(ltq_pci_membase))
return PTR_ERR(ltq_pci_membase);
res_cfg = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ltq_pci_mapped_cfg = devm_ioremap_resource(&pdev->dev, res_cfg);
if (IS_ERR(ltq_pci_mapped_cfg))
return PTR_ERR(ltq_pci_mapped_cfg);
ltq_pci_startup(pdev);
pci_load_of_ranges(&pci_controller, pdev->dev.of_node);
register_pci_controller(&pci_controller);
return 0;
}
int __init pcibios_init(void)
{
int ret = platform_driver_register(&ltq_pci_driver);
if (ret)
pr_info("pci-xway: Error registering platform driver!");
return ret;
}
