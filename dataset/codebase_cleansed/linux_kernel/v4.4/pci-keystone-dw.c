static inline struct pcie_port *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
static inline void update_reg_offset_bit_pos(u32 offset, u32 *reg_offset,
u32 *bit_pos)
{
*reg_offset = offset % 8;
*bit_pos = offset >> 3;
}
phys_addr_t ks_dw_pcie_get_msi_addr(struct pcie_port *pp)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
return ks_pcie->app.start + MSI_IRQ;
}
void ks_dw_pcie_handle_msi_irq(struct keystone_pcie *ks_pcie, int offset)
{
struct pcie_port *pp = &ks_pcie->pp;
u32 pending, vector;
int src, virq;
pending = readl(ks_pcie->va_app_base + MSI0_IRQ_STATUS + (offset << 4));
for (src = 0; src < 4; src++) {
if (BIT(src) & pending) {
vector = offset + (src << 3);
virq = irq_linear_revmap(pp->irq_domain, vector);
dev_dbg(pp->dev, "irq: bit %d, vector %d, virq %d\n",
src, vector, virq);
generic_handle_irq(virq);
}
}
}
static void ks_dw_pcie_msi_irq_ack(struct irq_data *d)
{
u32 offset, reg_offset, bit_pos;
struct keystone_pcie *ks_pcie;
struct msi_desc *msi;
struct pcie_port *pp;
msi = irq_data_get_msi_desc(d);
pp = sys_to_pcie(msi_desc_to_pci_sysdata(msi));
ks_pcie = to_keystone_pcie(pp);
offset = d->irq - irq_linear_revmap(pp->irq_domain, 0);
update_reg_offset_bit_pos(offset, &reg_offset, &bit_pos);
writel(BIT(bit_pos),
ks_pcie->va_app_base + MSI0_IRQ_STATUS + (reg_offset << 4));
writel(reg_offset + MSI_IRQ_OFFSET, ks_pcie->va_app_base + IRQ_EOI);
}
void ks_dw_pcie_msi_set_irq(struct pcie_port *pp, int irq)
{
u32 reg_offset, bit_pos;
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
update_reg_offset_bit_pos(irq, &reg_offset, &bit_pos);
writel(BIT(bit_pos),
ks_pcie->va_app_base + MSI0_IRQ_ENABLE_SET + (reg_offset << 4));
}
void ks_dw_pcie_msi_clear_irq(struct pcie_port *pp, int irq)
{
u32 reg_offset, bit_pos;
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
update_reg_offset_bit_pos(irq, &reg_offset, &bit_pos);
writel(BIT(bit_pos),
ks_pcie->va_app_base + MSI0_IRQ_ENABLE_CLR + (reg_offset << 4));
}
static void ks_dw_pcie_msi_irq_mask(struct irq_data *d)
{
struct keystone_pcie *ks_pcie;
struct msi_desc *msi;
struct pcie_port *pp;
u32 offset;
msi = irq_data_get_msi_desc(d);
pp = sys_to_pcie(msi_desc_to_pci_sysdata(msi));
ks_pcie = to_keystone_pcie(pp);
offset = d->irq - irq_linear_revmap(pp->irq_domain, 0);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
if (msi->msi_attrib.maskbit)
pci_msi_mask_irq(d);
}
ks_dw_pcie_msi_clear_irq(pp, offset);
}
static void ks_dw_pcie_msi_irq_unmask(struct irq_data *d)
{
struct keystone_pcie *ks_pcie;
struct msi_desc *msi;
struct pcie_port *pp;
u32 offset;
msi = irq_data_get_msi_desc(d);
pp = sys_to_pcie(msi_desc_to_pci_sysdata(msi));
ks_pcie = to_keystone_pcie(pp);
offset = d->irq - irq_linear_revmap(pp->irq_domain, 0);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
if (msi->msi_attrib.maskbit)
pci_msi_unmask_irq(d);
}
ks_dw_pcie_msi_set_irq(pp, offset);
}
static int ks_dw_pcie_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &ks_dw_pcie_msi_irq_chip,
handle_level_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
int ks_dw_pcie_msi_host_init(struct pcie_port *pp, struct msi_controller *chip)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
int i;
pp->irq_domain = irq_domain_add_linear(ks_pcie->msi_intc_np,
MAX_MSI_IRQS,
&ks_dw_pcie_msi_domain_ops,
chip);
if (!pp->irq_domain) {
dev_err(pp->dev, "irq domain init failed\n");
return -ENXIO;
}
for (i = 0; i < MAX_MSI_IRQS; i++)
irq_create_mapping(pp->irq_domain, i);
return 0;
}
void ks_dw_pcie_enable_legacy_irqs(struct keystone_pcie *ks_pcie)
{
int i;
for (i = 0; i < MAX_LEGACY_IRQS; i++)
writel(0x1, ks_pcie->va_app_base + IRQ_ENABLE_SET + (i << 4));
}
void ks_dw_pcie_handle_legacy_irq(struct keystone_pcie *ks_pcie, int offset)
{
struct pcie_port *pp = &ks_pcie->pp;
u32 pending;
int virq;
pending = readl(ks_pcie->va_app_base + IRQ_STATUS + (offset << 4));
if (BIT(0) & pending) {
virq = irq_linear_revmap(ks_pcie->legacy_irq_domain, offset);
dev_dbg(pp->dev, ": irq: irq_offset %d, virq %d\n", offset,
virq);
generic_handle_irq(virq);
}
writel(offset, ks_pcie->va_app_base + IRQ_EOI);
}
static void ks_dw_pcie_ack_legacy_irq(struct irq_data *d)
{
}
static void ks_dw_pcie_mask_legacy_irq(struct irq_data *d)
{
}
static void ks_dw_pcie_unmask_legacy_irq(struct irq_data *d)
{
}
static int ks_dw_pcie_init_legacy_irq_map(struct irq_domain *d,
unsigned int irq, irq_hw_number_t hw_irq)
{
irq_set_chip_and_handler(irq, &ks_dw_pcie_legacy_irq_chip,
handle_level_irq);
irq_set_chip_data(irq, d->host_data);
return 0;
}
static void ks_dw_pcie_set_dbi_mode(void __iomem *reg_virt)
{
u32 val;
writel(DBI_CS2_EN_VAL | readl(reg_virt + CMD_STATUS),
reg_virt + CMD_STATUS);
do {
val = readl(reg_virt + CMD_STATUS);
} while (!(val & DBI_CS2_EN_VAL));
}
static void ks_dw_pcie_clear_dbi_mode(void __iomem *reg_virt)
{
u32 val;
writel(~DBI_CS2_EN_VAL & readl(reg_virt + CMD_STATUS),
reg_virt + CMD_STATUS);
do {
val = readl(reg_virt + CMD_STATUS);
} while (val & DBI_CS2_EN_VAL);
}
void ks_dw_pcie_setup_rc_app_regs(struct keystone_pcie *ks_pcie)
{
struct pcie_port *pp = &ks_pcie->pp;
u32 start = pp->mem->start, end = pp->mem->end;
int i, tr_size;
ks_dw_pcie_set_dbi_mode(ks_pcie->va_app_base);
writel(0, pp->dbi_base + PCI_BASE_ADDRESS_0);
writel(0, pp->dbi_base + PCI_BASE_ADDRESS_1);
ks_dw_pcie_clear_dbi_mode(ks_pcie->va_app_base);
writel(CFG_PCIM_WIN_SZ_IDX & 0x7, ks_pcie->va_app_base + OB_SIZE);
tr_size = (1 << (CFG_PCIM_WIN_SZ_IDX & 0x7)) * SZ_1M;
for (i = 0; (i < CFG_PCIM_WIN_CNT) && (start < end); i++) {
writel(start | 1, ks_pcie->va_app_base + OB_OFFSET_INDEX(i));
writel(0, ks_pcie->va_app_base + OB_OFFSET_HI(i));
start += tr_size;
}
writel(OB_XLAT_EN_VAL | readl(ks_pcie->va_app_base + CMD_STATUS),
ks_pcie->va_app_base + CMD_STATUS);
}
static void __iomem *ks_pcie_cfg_setup(struct keystone_pcie *ks_pcie, u8 bus,
unsigned int devfn)
{
u8 device = PCI_SLOT(devfn), function = PCI_FUNC(devfn);
struct pcie_port *pp = &ks_pcie->pp;
u32 regval;
if (bus == 0)
return pp->dbi_base;
regval = (bus << 16) | (device << 8) | function;
if (bus != 1)
regval |= BIT(24);
writel(regval, ks_pcie->va_app_base + CFG_SETUP);
return pp->va_cfg0_base;
}
int ks_dw_pcie_rd_other_conf(struct pcie_port *pp, struct pci_bus *bus,
unsigned int devfn, int where, int size, u32 *val)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
u8 bus_num = bus->number;
void __iomem *addr;
addr = ks_pcie_cfg_setup(ks_pcie, bus_num, devfn);
return dw_pcie_cfg_read(addr + where, size, val);
}
int ks_dw_pcie_wr_other_conf(struct pcie_port *pp, struct pci_bus *bus,
unsigned int devfn, int where, int size, u32 val)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
u8 bus_num = bus->number;
void __iomem *addr;
addr = ks_pcie_cfg_setup(ks_pcie, bus_num, devfn);
return dw_pcie_cfg_write(addr + where, size, val);
}
void ks_dw_pcie_v3_65_scan_bus(struct pcie_port *pp)
{
struct keystone_pcie *ks_pcie = to_keystone_pcie(pp);
ks_dw_pcie_set_dbi_mode(ks_pcie->va_app_base);
writel(1, pp->dbi_base + PCI_BASE_ADDRESS_0);
writel(SZ_4K - 1, pp->dbi_base + PCI_BASE_ADDRESS_0);
ks_dw_pcie_clear_dbi_mode(ks_pcie->va_app_base);
writel(ks_pcie->app.start, pp->dbi_base + PCI_BASE_ADDRESS_0);
}
int ks_dw_pcie_link_up(struct pcie_port *pp)
{
u32 val = readl(pp->dbi_base + DEBUG0);
return (val & LTSSM_STATE_MASK) == LTSSM_STATE_L0;
}
void ks_dw_pcie_initiate_link_train(struct keystone_pcie *ks_pcie)
{
u32 val;
val = readl(ks_pcie->va_app_base + CMD_STATUS);
val &= ~LTSSM_EN_VAL;
writel(LTSSM_EN_VAL | val, ks_pcie->va_app_base + CMD_STATUS);
val = readl(ks_pcie->va_app_base + CMD_STATUS);
writel(LTSSM_EN_VAL | val, ks_pcie->va_app_base + CMD_STATUS);
}
int __init ks_dw_pcie_host_init(struct keystone_pcie *ks_pcie,
struct device_node *msi_intc_np)
{
struct pcie_port *pp = &ks_pcie->pp;
struct platform_device *pdev = to_platform_device(pp->dev);
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pp->dbi_base = devm_ioremap_resource(pp->dev, res);
if (IS_ERR(pp->dbi_base))
return PTR_ERR(pp->dbi_base);
pp->va_cfg0_base = pp->dbi_base + SPACE0_REMOTE_CFG_OFFSET;
pp->va_cfg1_base = pp->va_cfg0_base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ks_pcie->va_app_base = devm_ioremap_resource(pp->dev, res);
if (IS_ERR(ks_pcie->va_app_base))
return PTR_ERR(ks_pcie->va_app_base);
ks_pcie->app = *res;
ks_pcie->legacy_irq_domain =
irq_domain_add_linear(ks_pcie->legacy_intc_np,
MAX_LEGACY_IRQS,
&ks_dw_pcie_legacy_irq_domain_ops,
NULL);
if (!ks_pcie->legacy_irq_domain) {
dev_err(pp->dev, "Failed to add irq domain for legacy irqs\n");
return -EINVAL;
}
return dw_pcie_host_init(pp);
}
