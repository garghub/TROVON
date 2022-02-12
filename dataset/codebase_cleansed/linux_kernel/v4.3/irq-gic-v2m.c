static void gicv2m_mask_msi_irq(struct irq_data *d)
{
pci_msi_mask_irq(d);
irq_chip_mask_parent(d);
}
static void gicv2m_unmask_msi_irq(struct irq_data *d)
{
pci_msi_unmask_irq(d);
irq_chip_unmask_parent(d);
}
static int gicv2m_set_affinity(struct irq_data *irq_data,
const struct cpumask *mask, bool force)
{
int ret;
ret = irq_chip_set_affinity_parent(irq_data, mask, force);
if (ret == IRQ_SET_MASK_OK)
ret = IRQ_SET_MASK_OK_DONE;
return ret;
}
static void gicv2m_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct v2m_data *v2m = irq_data_get_irq_chip_data(data);
phys_addr_t addr = v2m->res.start + V2M_MSI_SETSPI_NS;
msg->address_hi = upper_32_bits(addr);
msg->address_lo = lower_32_bits(addr);
msg->data = data->hwirq;
}
static int gicv2m_irq_gic_domain_alloc(struct irq_domain *domain,
unsigned int virq,
irq_hw_number_t hwirq)
{
struct of_phandle_args args;
struct irq_data *d;
int err;
args.np = domain->parent->of_node;
args.args_count = 3;
args.args[0] = 0;
args.args[1] = hwirq - 32;
args.args[2] = IRQ_TYPE_EDGE_RISING;
err = irq_domain_alloc_irqs_parent(domain, virq, 1, &args);
if (err)
return err;
d = irq_domain_get_irq_data(domain->parent, virq);
d->chip->irq_set_type(d, IRQ_TYPE_EDGE_RISING);
return 0;
}
static void gicv2m_unalloc_msi(struct v2m_data *v2m, unsigned int hwirq)
{
int pos;
pos = hwirq - v2m->spi_start;
if (pos < 0 || pos >= v2m->nr_spis) {
pr_err("Failed to teardown msi. Invalid hwirq %d\n", hwirq);
return;
}
spin_lock(&v2m->msi_cnt_lock);
__clear_bit(pos, v2m->bm);
spin_unlock(&v2m->msi_cnt_lock);
}
static int gicv2m_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct v2m_data *v2m = domain->host_data;
int hwirq, offset, err = 0;
spin_lock(&v2m->msi_cnt_lock);
offset = find_first_zero_bit(v2m->bm, v2m->nr_spis);
if (offset < v2m->nr_spis)
__set_bit(offset, v2m->bm);
else
err = -ENOSPC;
spin_unlock(&v2m->msi_cnt_lock);
if (err)
return err;
hwirq = v2m->spi_start + offset;
err = gicv2m_irq_gic_domain_alloc(domain, virq, hwirq);
if (err) {
gicv2m_unalloc_msi(v2m, hwirq);
return err;
}
irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
&gicv2m_irq_chip, v2m);
return 0;
}
static void gicv2m_irq_domain_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
struct v2m_data *v2m = irq_data_get_irq_chip_data(d);
BUG_ON(nr_irqs != 1);
gicv2m_unalloc_msi(v2m, d->hwirq);
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}
static bool is_msi_spi_valid(u32 base, u32 num)
{
if (base < V2M_MIN_SPI) {
pr_err("Invalid MSI base SPI (base:%u)\n", base);
return false;
}
if ((num == 0) || (base + num > V2M_MAX_SPI)) {
pr_err("Number of SPIs (%u) exceed maximum (%u)\n",
num, V2M_MAX_SPI - V2M_MIN_SPI + 1);
return false;
}
return true;
}
static int __init gicv2m_init_one(struct device_node *node,
struct irq_domain *parent)
{
int ret;
struct v2m_data *v2m;
struct irq_domain *inner_domain, *pci_domain, *plat_domain;
v2m = kzalloc(sizeof(struct v2m_data), GFP_KERNEL);
if (!v2m) {
pr_err("Failed to allocate struct v2m_data.\n");
return -ENOMEM;
}
ret = of_address_to_resource(node, 0, &v2m->res);
if (ret) {
pr_err("Failed to allocate v2m resource.\n");
goto err_free_v2m;
}
v2m->base = ioremap(v2m->res.start, resource_size(&v2m->res));
if (!v2m->base) {
pr_err("Failed to map GICv2m resource\n");
ret = -ENOMEM;
goto err_free_v2m;
}
if (!of_property_read_u32(node, "arm,msi-base-spi", &v2m->spi_start) &&
!of_property_read_u32(node, "arm,msi-num-spis", &v2m->nr_spis)) {
pr_info("Overriding V2M MSI_TYPER (base:%u, num:%u)\n",
v2m->spi_start, v2m->nr_spis);
} else {
u32 typer = readl_relaxed(v2m->base + V2M_MSI_TYPER);
v2m->spi_start = V2M_MSI_TYPER_BASE_SPI(typer);
v2m->nr_spis = V2M_MSI_TYPER_NUM_SPI(typer);
}
if (!is_msi_spi_valid(v2m->spi_start, v2m->nr_spis)) {
ret = -EINVAL;
goto err_iounmap;
}
v2m->bm = kzalloc(sizeof(long) * BITS_TO_LONGS(v2m->nr_spis),
GFP_KERNEL);
if (!v2m->bm) {
ret = -ENOMEM;
goto err_iounmap;
}
inner_domain = irq_domain_add_tree(node, &gicv2m_domain_ops, v2m);
if (!inner_domain) {
pr_err("Failed to create GICv2m domain\n");
ret = -ENOMEM;
goto err_free_bm;
}
inner_domain->bus_token = DOMAIN_BUS_NEXUS;
inner_domain->parent = parent;
pci_domain = pci_msi_create_irq_domain(node, &gicv2m_msi_domain_info,
inner_domain);
plat_domain = platform_msi_create_irq_domain(node,
&gicv2m_pmsi_domain_info,
inner_domain);
if (!pci_domain || !plat_domain) {
pr_err("Failed to create MSI domains\n");
ret = -ENOMEM;
goto err_free_domains;
}
spin_lock_init(&v2m->msi_cnt_lock);
pr_info("Node %s: range[%#lx:%#lx], SPI[%d:%d]\n", node->name,
(unsigned long)v2m->res.start, (unsigned long)v2m->res.end,
v2m->spi_start, (v2m->spi_start + v2m->nr_spis));
return 0;
err_free_domains:
if (plat_domain)
irq_domain_remove(plat_domain);
if (pci_domain)
irq_domain_remove(pci_domain);
if (inner_domain)
irq_domain_remove(inner_domain);
err_free_bm:
kfree(v2m->bm);
err_iounmap:
iounmap(v2m->base);
err_free_v2m:
kfree(v2m);
return ret;
}
int __init gicv2m_of_init(struct device_node *node, struct irq_domain *parent)
{
int ret = 0;
struct device_node *child;
for (child = of_find_matching_node(node, gicv2m_device_id); child;
child = of_find_matching_node(child, gicv2m_device_id)) {
if (!of_find_property(child, "msi-controller", NULL))
continue;
ret = gicv2m_init_one(child, parent);
if (ret) {
of_node_put(node);
break;
}
}
return ret;
}
