static void alpine_msix_mask_msi_irq(struct irq_data *d)
{
pci_msi_mask_irq(d);
irq_chip_mask_parent(d);
}
static void alpine_msix_unmask_msi_irq(struct irq_data *d)
{
pci_msi_unmask_irq(d);
irq_chip_unmask_parent(d);
}
static int alpine_msix_allocate_sgi(struct alpine_msix_data *priv, int num_req)
{
int first;
spin_lock(&priv->msi_map_lock);
first = bitmap_find_next_zero_area(priv->msi_map, priv->num_spis, 0,
num_req, 0);
if (first >= priv->num_spis) {
spin_unlock(&priv->msi_map_lock);
return -ENOSPC;
}
bitmap_set(priv->msi_map, first, num_req);
spin_unlock(&priv->msi_map_lock);
return priv->spi_first + first;
}
static void alpine_msix_free_sgi(struct alpine_msix_data *priv, unsigned sgi,
int num_req)
{
int first = sgi - priv->spi_first;
spin_lock(&priv->msi_map_lock);
bitmap_clear(priv->msi_map, first, num_req);
spin_unlock(&priv->msi_map_lock);
}
static void alpine_msix_compose_msi_msg(struct irq_data *data,
struct msi_msg *msg)
{
struct alpine_msix_data *priv = irq_data_get_irq_chip_data(data);
phys_addr_t msg_addr = priv->addr;
msg_addr |= (data->hwirq << 3);
msg->address_hi = upper_32_bits(msg_addr);
msg->address_lo = lower_32_bits(msg_addr);
msg->data = 0;
}
static int alpine_msix_gic_domain_alloc(struct irq_domain *domain,
unsigned int virq, int sgi)
{
struct irq_fwspec fwspec;
struct irq_data *d;
int ret;
if (!is_of_node(domain->parent->fwnode))
return -EINVAL;
fwspec.fwnode = domain->parent->fwnode;
fwspec.param_count = 3;
fwspec.param[0] = 0;
fwspec.param[1] = sgi;
fwspec.param[2] = IRQ_TYPE_EDGE_RISING;
ret = irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
if (ret)
return ret;
d = irq_domain_get_irq_data(domain->parent, virq);
d->chip->irq_set_type(d, IRQ_TYPE_EDGE_RISING);
return 0;
}
static int alpine_msix_middle_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct alpine_msix_data *priv = domain->host_data;
int sgi, err, i;
sgi = alpine_msix_allocate_sgi(priv, nr_irqs);
if (sgi < 0)
return sgi;
for (i = 0; i < nr_irqs; i++) {
err = alpine_msix_gic_domain_alloc(domain, virq + i, sgi + i);
if (err)
goto err_sgi;
irq_domain_set_hwirq_and_chip(domain, virq + i, sgi + i,
&middle_irq_chip, priv);
}
return 0;
err_sgi:
while (--i >= 0)
irq_domain_free_irqs_parent(domain, virq, i);
alpine_msix_free_sgi(priv, sgi, nr_irqs);
return err;
}
static void alpine_msix_middle_domain_free(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
struct alpine_msix_data *priv = irq_data_get_irq_chip_data(d);
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
alpine_msix_free_sgi(priv, d->hwirq, nr_irqs);
}
static int alpine_msix_init_domains(struct alpine_msix_data *priv,
struct device_node *node)
{
struct irq_domain *middle_domain, *msi_domain, *gic_domain;
struct device_node *gic_node;
gic_node = of_irq_find_parent(node);
if (!gic_node) {
pr_err("Failed to find the GIC node\n");
return -ENODEV;
}
gic_domain = irq_find_host(gic_node);
if (!gic_domain) {
pr_err("Failed to find the GIC domain\n");
return -ENXIO;
}
middle_domain = irq_domain_add_tree(NULL,
&alpine_msix_middle_domain_ops,
priv);
if (!middle_domain) {
pr_err("Failed to create the MSIX middle domain\n");
return -ENOMEM;
}
middle_domain->parent = gic_domain;
msi_domain = pci_msi_create_irq_domain(of_node_to_fwnode(node),
&alpine_msix_domain_info,
middle_domain);
if (!msi_domain) {
pr_err("Failed to create MSI domain\n");
irq_domain_remove(middle_domain);
return -ENOMEM;
}
return 0;
}
static int alpine_msix_init(struct device_node *node,
struct device_node *parent)
{
struct alpine_msix_data *priv;
struct resource res;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->msi_map_lock);
ret = of_address_to_resource(node, 0, &res);
if (ret) {
pr_err("Failed to allocate resource\n");
goto err_priv;
}
priv->addr = res.start & GENMASK_ULL(63,20);
priv->addr |= ALPINE_MSIX_SPI_TARGET_CLUSTER0;
if (of_property_read_u32(node, "al,msi-base-spi", &priv->spi_first)) {
pr_err("Unable to parse MSI base\n");
ret = -EINVAL;
goto err_priv;
}
if (of_property_read_u32(node, "al,msi-num-spis", &priv->num_spis)) {
pr_err("Unable to parse MSI numbers\n");
ret = -EINVAL;
goto err_priv;
}
priv->msi_map = kzalloc(sizeof(*priv->msi_map) * BITS_TO_LONGS(priv->num_spis),
GFP_KERNEL);
if (!priv->msi_map) {
ret = -ENOMEM;
goto err_priv;
}
pr_debug("Registering %d msixs, starting at %d\n",
priv->num_spis, priv->spi_first);
ret = alpine_msix_init_domains(priv, node);
if (ret)
goto err_map;
return 0;
err_map:
kfree(priv->msi_map);
err_priv:
kfree(priv);
return ret;
}
