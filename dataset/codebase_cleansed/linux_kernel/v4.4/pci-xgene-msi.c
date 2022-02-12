static u32 xgene_msi_ir_read(struct xgene_msi *msi,
u32 msi_grp, u32 msir_idx)
{
return readl_relaxed(msi->msi_regs + MSI_IR0 +
(msi_grp << 19) + (msir_idx << 16));
}
static u32 xgene_msi_int_read(struct xgene_msi *msi, u32 msi_grp)
{
return readl_relaxed(msi->msi_regs + MSI_INT0 + (msi_grp << 16));
}
static u32 hwirq_to_reg_set(unsigned long hwirq)
{
return (hwirq / (NR_HW_IRQS * IRQS_PER_IDX));
}
static u32 hwirq_to_group(unsigned long hwirq)
{
return (hwirq % NR_HW_IRQS);
}
static u32 hwirq_to_msi_data(unsigned long hwirq)
{
return ((hwirq / NR_HW_IRQS) % IRQS_PER_IDX);
}
static void xgene_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct xgene_msi *msi = irq_data_get_irq_chip_data(data);
u32 reg_set = hwirq_to_reg_set(data->hwirq);
u32 group = hwirq_to_group(data->hwirq);
u64 target_addr = msi->msi_addr + (((8 * group) + reg_set) << 16);
msg->address_hi = upper_32_bits(target_addr);
msg->address_lo = lower_32_bits(target_addr);
msg->data = hwirq_to_msi_data(data->hwirq);
}
static int hwirq_to_cpu(unsigned long hwirq)
{
return (hwirq % xgene_msi_ctrl.num_cpus);
}
static unsigned long hwirq_to_canonical_hwirq(unsigned long hwirq)
{
return (hwirq - hwirq_to_cpu(hwirq));
}
static int xgene_msi_set_affinity(struct irq_data *irqdata,
const struct cpumask *mask, bool force)
{
int target_cpu = cpumask_first(mask);
int curr_cpu;
curr_cpu = hwirq_to_cpu(irqdata->hwirq);
if (curr_cpu == target_cpu)
return IRQ_SET_MASK_OK_DONE;
irqdata->hwirq = hwirq_to_canonical_hwirq(irqdata->hwirq) + target_cpu;
return IRQ_SET_MASK_OK;
}
static int xgene_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct xgene_msi *msi = domain->host_data;
int msi_irq;
mutex_lock(&msi->bitmap_lock);
msi_irq = bitmap_find_next_zero_area(msi->bitmap, NR_MSI_VEC, 0,
msi->num_cpus, 0);
if (msi_irq < NR_MSI_VEC)
bitmap_set(msi->bitmap, msi_irq, msi->num_cpus);
else
msi_irq = -ENOSPC;
mutex_unlock(&msi->bitmap_lock);
if (msi_irq < 0)
return msi_irq;
irq_domain_set_info(domain, virq, msi_irq,
&xgene_msi_bottom_irq_chip, domain->host_data,
handle_simple_irq, NULL, NULL);
return 0;
}
static void xgene_irq_domain_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
struct xgene_msi *msi = irq_data_get_irq_chip_data(d);
u32 hwirq;
mutex_lock(&msi->bitmap_lock);
hwirq = hwirq_to_canonical_hwirq(d->hwirq);
bitmap_clear(msi->bitmap, hwirq, msi->num_cpus);
mutex_unlock(&msi->bitmap_lock);
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}
static int xgene_allocate_domains(struct xgene_msi *msi)
{
msi->inner_domain = irq_domain_add_linear(NULL, NR_MSI_VEC,
&msi_domain_ops, msi);
if (!msi->inner_domain)
return -ENOMEM;
msi->msi_domain = pci_msi_create_irq_domain(of_node_to_fwnode(msi->node),
&xgene_msi_domain_info,
msi->inner_domain);
if (!msi->msi_domain) {
irq_domain_remove(msi->inner_domain);
return -ENOMEM;
}
return 0;
}
static void xgene_free_domains(struct xgene_msi *msi)
{
if (msi->msi_domain)
irq_domain_remove(msi->msi_domain);
if (msi->inner_domain)
irq_domain_remove(msi->inner_domain);
}
static int xgene_msi_init_allocator(struct xgene_msi *xgene_msi)
{
int size = BITS_TO_LONGS(NR_MSI_VEC) * sizeof(long);
xgene_msi->bitmap = kzalloc(size, GFP_KERNEL);
if (!xgene_msi->bitmap)
return -ENOMEM;
mutex_init(&xgene_msi->bitmap_lock);
xgene_msi->msi_groups = kcalloc(NR_HW_IRQS,
sizeof(struct xgene_msi_group),
GFP_KERNEL);
if (!xgene_msi->msi_groups)
return -ENOMEM;
return 0;
}
static void xgene_msi_isr(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct xgene_msi_group *msi_groups;
struct xgene_msi *xgene_msi;
unsigned int virq;
int msir_index, msir_val, hw_irq;
u32 intr_index, grp_select, msi_grp;
chained_irq_enter(chip, desc);
msi_groups = irq_desc_get_handler_data(desc);
xgene_msi = msi_groups->msi;
msi_grp = msi_groups->msi_grp;
grp_select = xgene_msi_int_read(xgene_msi, msi_grp);
while (grp_select) {
msir_index = ffs(grp_select) - 1;
msir_val = xgene_msi_ir_read(xgene_msi, msi_grp, msir_index);
while (msir_val) {
intr_index = ffs(msir_val) - 1;
hw_irq = (((msir_index * IRQS_PER_IDX) + intr_index) *
NR_HW_IRQS) + msi_grp;
hw_irq = hwirq_to_canonical_hwirq(hw_irq);
virq = irq_find_mapping(xgene_msi->inner_domain, hw_irq);
WARN_ON(!virq);
if (virq != 0)
generic_handle_irq(virq);
msir_val &= ~(1 << intr_index);
}
grp_select &= ~(1 << msir_index);
if (!grp_select) {
grp_select = xgene_msi_int_read(xgene_msi, msi_grp);
}
}
chained_irq_exit(chip, desc);
}
static int xgene_msi_remove(struct platform_device *pdev)
{
int virq, i;
struct xgene_msi *msi = platform_get_drvdata(pdev);
for (i = 0; i < NR_HW_IRQS; i++) {
virq = msi->msi_groups[i].gic_irq;
if (virq != 0)
irq_set_chained_handler_and_data(virq, NULL, NULL);
}
kfree(msi->msi_groups);
kfree(msi->bitmap);
msi->bitmap = NULL;
xgene_free_domains(msi);
return 0;
}
static int xgene_msi_hwirq_alloc(unsigned int cpu)
{
struct xgene_msi *msi = &xgene_msi_ctrl;
struct xgene_msi_group *msi_group;
cpumask_var_t mask;
int i;
int err;
for (i = cpu; i < NR_HW_IRQS; i += msi->num_cpus) {
msi_group = &msi->msi_groups[i];
if (!msi_group->gic_irq)
continue;
irq_set_chained_handler(msi_group->gic_irq,
xgene_msi_isr);
err = irq_set_handler_data(msi_group->gic_irq, msi_group);
if (err) {
pr_err("failed to register GIC IRQ handler\n");
return -EINVAL;
}
if (alloc_cpumask_var(&mask, GFP_KERNEL)) {
cpumask_clear(mask);
cpumask_set_cpu(cpu, mask);
err = irq_set_affinity(msi_group->gic_irq, mask);
if (err)
pr_err("failed to set affinity for GIC IRQ");
free_cpumask_var(mask);
} else {
pr_err("failed to alloc CPU mask for affinity\n");
err = -EINVAL;
}
if (err) {
irq_set_chained_handler_and_data(msi_group->gic_irq,
NULL, NULL);
return err;
}
}
return 0;
}
static void xgene_msi_hwirq_free(unsigned int cpu)
{
struct xgene_msi *msi = &xgene_msi_ctrl;
struct xgene_msi_group *msi_group;
int i;
for (i = cpu; i < NR_HW_IRQS; i += msi->num_cpus) {
msi_group = &msi->msi_groups[i];
if (!msi_group->gic_irq)
continue;
irq_set_chained_handler_and_data(msi_group->gic_irq, NULL,
NULL);
}
}
static int xgene_msi_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned cpu = (unsigned long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
xgene_msi_hwirq_alloc(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
xgene_msi_hwirq_free(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static int xgene_msi_probe(struct platform_device *pdev)
{
struct resource *res;
int rc, irq_index;
struct xgene_msi *xgene_msi;
unsigned int cpu;
int virt_msir;
u32 msi_val, msi_idx;
xgene_msi = &xgene_msi_ctrl;
platform_set_drvdata(pdev, xgene_msi);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xgene_msi->msi_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xgene_msi->msi_regs)) {
dev_err(&pdev->dev, "no reg space\n");
rc = -EINVAL;
goto error;
}
xgene_msi->msi_addr = res->start;
xgene_msi->node = pdev->dev.of_node;
xgene_msi->num_cpus = num_possible_cpus();
rc = xgene_msi_init_allocator(xgene_msi);
if (rc) {
dev_err(&pdev->dev, "Error allocating MSI bitmap\n");
goto error;
}
rc = xgene_allocate_domains(xgene_msi);
if (rc) {
dev_err(&pdev->dev, "Failed to allocate MSI domain\n");
goto error;
}
for (irq_index = 0; irq_index < NR_HW_IRQS; irq_index++) {
virt_msir = platform_get_irq(pdev, irq_index);
if (virt_msir < 0) {
dev_err(&pdev->dev, "Cannot translate IRQ index %d\n",
irq_index);
rc = -EINVAL;
goto error;
}
xgene_msi->msi_groups[irq_index].gic_irq = virt_msir;
xgene_msi->msi_groups[irq_index].msi_grp = irq_index;
xgene_msi->msi_groups[irq_index].msi = xgene_msi;
}
for (irq_index = 0; irq_index < NR_HW_IRQS; irq_index++) {
for (msi_idx = 0; msi_idx < IDX_PER_GROUP; msi_idx++)
msi_val = xgene_msi_ir_read(xgene_msi, irq_index,
msi_idx);
msi_val = xgene_msi_int_read(xgene_msi, irq_index);
if (msi_val) {
dev_err(&pdev->dev, "Failed to clear spurious IRQ\n");
rc = -EINVAL;
goto error;
}
}
cpu_notifier_register_begin();
for_each_online_cpu(cpu)
if (xgene_msi_hwirq_alloc(cpu)) {
dev_err(&pdev->dev, "failed to register MSI handlers\n");
cpu_notifier_register_done();
goto error;
}
rc = __register_hotcpu_notifier(&xgene_msi_cpu_notifier);
if (rc) {
dev_err(&pdev->dev, "failed to add CPU MSI notifier\n");
cpu_notifier_register_done();
goto error;
}
cpu_notifier_register_done();
dev_info(&pdev->dev, "APM X-Gene PCIe MSI driver loaded\n");
return 0;
error:
xgene_msi_remove(pdev);
return rc;
}
static int __init xgene_pcie_msi_init(void)
{
return platform_driver_register(&xgene_msi_driver);
}
