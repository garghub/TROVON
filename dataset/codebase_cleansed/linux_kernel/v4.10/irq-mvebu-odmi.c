static void odmi_compose_msi_msg(struct irq_data *d, struct msi_msg *msg)
{
struct odmi_data *odmi;
phys_addr_t addr;
unsigned int odmin;
if (WARN_ON(d->hwirq >= odmis_count * NODMIS_PER_FRAME))
return;
odmi = &odmis[d->hwirq >> NODMIS_SHIFT];
odmin = d->hwirq & NODMIS_MASK;
addr = odmi->res.start + GICP_ODMIN_SET;
msg->address_hi = upper_32_bits(addr);
msg->address_lo = lower_32_bits(addr);
msg->data = odmin << GICP_ODMI_INT_NUM_SHIFT;
}
static int odmi_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct odmi_data *odmi = NULL;
struct irq_fwspec fwspec;
struct irq_data *d;
unsigned int hwirq, odmin;
int ret;
spin_lock(&odmis_bm_lock);
hwirq = find_first_zero_bit(odmis_bm, NODMIS_PER_FRAME * odmis_count);
if (hwirq >= NODMIS_PER_FRAME * odmis_count) {
spin_unlock(&odmis_bm_lock);
return -ENOSPC;
}
__set_bit(hwirq, odmis_bm);
spin_unlock(&odmis_bm_lock);
odmi = &odmis[hwirq >> NODMIS_SHIFT];
odmin = hwirq & NODMIS_MASK;
fwspec.fwnode = domain->parent->fwnode;
fwspec.param_count = 3;
fwspec.param[0] = GIC_SPI;
fwspec.param[1] = odmi->spi_base - 32 + odmin;
fwspec.param[2] = IRQ_TYPE_EDGE_RISING;
ret = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
if (ret) {
pr_err("Cannot allocate parent IRQ\n");
spin_lock(&odmis_bm_lock);
__clear_bit(odmin, odmis_bm);
spin_unlock(&odmis_bm_lock);
return ret;
}
d = irq_domain_get_irq_data(domain->parent, virq);
d->chip->irq_set_type(d, IRQ_TYPE_EDGE_RISING);
irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
&odmi_irq_chip, NULL);
return 0;
}
static void odmi_irq_domain_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
if (d->hwirq >= odmis_count * NODMIS_PER_FRAME) {
pr_err("Failed to teardown msi. Invalid hwirq %lu\n", d->hwirq);
return;
}
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
spin_lock(&odmis_bm_lock);
__clear_bit(d->hwirq, odmis_bm);
spin_unlock(&odmis_bm_lock);
}
static int __init mvebu_odmi_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *inner_domain, *plat_domain;
int ret, i;
if (of_property_read_u32(node, "marvell,odmi-frames", &odmis_count))
return -EINVAL;
odmis = kcalloc(odmis_count, sizeof(struct odmi_data), GFP_KERNEL);
if (!odmis)
return -ENOMEM;
odmis_bm = kcalloc(BITS_TO_LONGS(odmis_count * NODMIS_PER_FRAME),
sizeof(long), GFP_KERNEL);
if (!odmis_bm) {
ret = -ENOMEM;
goto err_alloc;
}
for (i = 0; i < odmis_count; i++) {
struct odmi_data *odmi = &odmis[i];
ret = of_address_to_resource(node, i, &odmi->res);
if (ret)
goto err_unmap;
odmi->base = of_io_request_and_map(node, i, "odmi");
if (IS_ERR(odmi->base)) {
ret = PTR_ERR(odmi->base);
goto err_unmap;
}
if (of_property_read_u32_index(node, "marvell,spi-base",
i, &odmi->spi_base)) {
ret = -EINVAL;
goto err_unmap;
}
}
inner_domain = irq_domain_create_linear(of_node_to_fwnode(node),
odmis_count * NODMIS_PER_FRAME,
&odmi_domain_ops, NULL);
if (!inner_domain) {
ret = -ENOMEM;
goto err_unmap;
}
inner_domain->parent = irq_find_host(parent);
plat_domain = platform_msi_create_irq_domain(of_node_to_fwnode(node),
&odmi_msi_domain_info,
inner_domain);
if (!plat_domain) {
ret = -ENOMEM;
goto err_remove_inner;
}
return 0;
err_remove_inner:
irq_domain_remove(inner_domain);
err_unmap:
for (i = 0; i < odmis_count; i++) {
struct odmi_data *odmi = &odmis[i];
if (odmi->base && !IS_ERR(odmi->base))
iounmap(odmis[i].base);
}
kfree(odmis_bm);
err_alloc:
kfree(odmis);
return ret;
}
