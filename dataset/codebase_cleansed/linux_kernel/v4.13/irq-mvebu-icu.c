static void mvebu_icu_write_msg(struct msi_desc *desc, struct msi_msg *msg)
{
struct irq_data *d = irq_get_irq_data(desc->irq);
struct mvebu_icu_irq_data *icu_irqd = d->chip_data;
struct mvebu_icu *icu = icu_irqd->icu;
unsigned int icu_int;
if (msg->address_lo || msg->address_hi) {
icu_int = msg->data | ICU_INT_ENABLE;
if (icu_irqd->type & IRQ_TYPE_EDGE_RISING)
icu_int |= ICU_IS_EDGE;
icu_int |= icu_irqd->icu_group << ICU_GROUP_SHIFT;
} else {
icu_int = 0;
}
writel_relaxed(icu_int, icu->base + ICU_INT_CFG(d->hwirq));
if (d->hwirq == ICU_SATA0_ICU_ID || d->hwirq == ICU_SATA1_ICU_ID) {
writel_relaxed(icu_int,
icu->base + ICU_INT_CFG(ICU_SATA0_ICU_ID));
writel_relaxed(icu_int,
icu->base + ICU_INT_CFG(ICU_SATA1_ICU_ID));
}
}
static int
mvebu_icu_irq_domain_translate(struct irq_domain *d, struct irq_fwspec *fwspec,
unsigned long *hwirq, unsigned int *type)
{
struct mvebu_icu *icu = d->host_data;
unsigned int icu_group;
if (WARN_ON(fwspec->param_count < 3)) {
dev_err(icu->dev, "wrong ICU parameter count %d\n",
fwspec->param_count);
return -EINVAL;
}
icu_group = fwspec->param[0];
if (icu_group != ICU_GRP_NSR && icu_group != ICU_GRP_SR &&
icu_group != ICU_GRP_SEI && icu_group != ICU_GRP_REI) {
dev_err(icu->dev, "wrong ICU group type %x\n", icu_group);
return -EINVAL;
}
*hwirq = fwspec->param[1];
if (*hwirq >= ICU_MAX_IRQS) {
dev_err(icu->dev, "invalid interrupt number %ld\n", *hwirq);
return -EINVAL;
}
*type = fwspec->param[2] & IRQ_TYPE_SENSE_MASK;
return 0;
}
static int
mvebu_icu_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
int err;
unsigned long hwirq;
struct irq_fwspec *fwspec = args;
struct mvebu_icu *icu = platform_msi_get_host_data(domain);
struct mvebu_icu_irq_data *icu_irqd;
icu_irqd = kmalloc(sizeof(*icu_irqd), GFP_KERNEL);
if (!icu_irqd)
return -ENOMEM;
err = mvebu_icu_irq_domain_translate(domain, fwspec, &hwirq,
&icu_irqd->type);
if (err) {
dev_err(icu->dev, "failed to translate ICU parameters\n");
goto free_irqd;
}
icu_irqd->icu_group = fwspec->param[0];
icu_irqd->icu = icu;
err = platform_msi_domain_alloc(domain, virq, nr_irqs);
if (err) {
dev_err(icu->dev, "failed to allocate ICU interrupt in parent domain\n");
goto free_irqd;
}
err = irq_set_irqchip_state(virq, IRQCHIP_STATE_PENDING, false);
if (err)
goto free_msi;
err = irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
&icu->irq_chip, icu_irqd);
if (err) {
dev_err(icu->dev, "failed to set the data to IRQ domain\n");
goto free_msi;
}
return 0;
free_msi:
platform_msi_domain_free(domain, virq, nr_irqs);
free_irqd:
kfree(icu_irqd);
return err;
}
static void
mvebu_icu_irq_domain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *d = irq_get_irq_data(virq);
struct mvebu_icu_irq_data *icu_irqd = d->chip_data;
kfree(icu_irqd);
platform_msi_domain_free(domain, virq, nr_irqs);
}
static int mvebu_icu_probe(struct platform_device *pdev)
{
struct mvebu_icu *icu;
struct device_node *node = pdev->dev.of_node;
struct device_node *gicp_dn;
struct resource *res;
phys_addr_t setspi, clrspi;
u32 i, icu_int;
int ret;
icu = devm_kzalloc(&pdev->dev, sizeof(struct mvebu_icu),
GFP_KERNEL);
if (!icu)
return -ENOMEM;
icu->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
icu->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(icu->base)) {
dev_err(&pdev->dev, "Failed to map icu base address.\n");
return PTR_ERR(icu->base);
}
icu->irq_chip.name = devm_kasprintf(&pdev->dev, GFP_KERNEL,
"ICU.%x",
(unsigned int)res->start);
if (!icu->irq_chip.name)
return -ENOMEM;
icu->irq_chip.irq_mask = irq_chip_mask_parent;
icu->irq_chip.irq_unmask = irq_chip_unmask_parent;
icu->irq_chip.irq_eoi = irq_chip_eoi_parent;
icu->irq_chip.irq_set_type = irq_chip_set_type_parent;
#ifdef CONFIG_SMP
icu->irq_chip.irq_set_affinity = irq_chip_set_affinity_parent;
#endif
pdev->dev.msi_domain = of_msi_get_domain(&pdev->dev, node,
DOMAIN_BUS_PLATFORM_MSI);
if (!pdev->dev.msi_domain)
return -EPROBE_DEFER;
gicp_dn = irq_domain_get_of_node(pdev->dev.msi_domain);
if (!gicp_dn)
return -ENODEV;
ret = mvebu_gicp_get_doorbells(gicp_dn, &setspi, &clrspi);
if (ret)
return ret;
writel_relaxed(upper_32_bits(setspi), icu->base + ICU_SETSPI_NSR_AH);
writel_relaxed(lower_32_bits(setspi), icu->base + ICU_SETSPI_NSR_AL);
writel_relaxed(upper_32_bits(clrspi), icu->base + ICU_CLRSPI_NSR_AH);
writel_relaxed(lower_32_bits(clrspi), icu->base + ICU_CLRSPI_NSR_AL);
for (i = 0 ; i < ICU_MAX_IRQS ; i++) {
icu_int = readl(icu->base + ICU_INT_CFG(i));
if ((icu_int >> ICU_GROUP_SHIFT) == ICU_GRP_NSR)
writel_relaxed(0x0, icu->base + ICU_INT_CFG(i));
}
icu->domain =
platform_msi_create_device_domain(&pdev->dev, ICU_MAX_IRQS,
mvebu_icu_write_msg,
&mvebu_icu_domain_ops, icu);
if (!icu->domain) {
dev_err(&pdev->dev, "Failed to create ICU domain\n");
return -ENOMEM;
}
return 0;
}
