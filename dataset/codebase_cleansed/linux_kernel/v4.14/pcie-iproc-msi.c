static inline u32 iproc_msi_read_reg(struct iproc_msi *msi,
enum iproc_msi_reg reg,
unsigned int eq)
{
struct iproc_pcie *pcie = msi->pcie;
return readl_relaxed(pcie->base + msi->reg_offsets[eq][reg]);
}
static inline void iproc_msi_write_reg(struct iproc_msi *msi,
enum iproc_msi_reg reg,
int eq, u32 val)
{
struct iproc_pcie *pcie = msi->pcie;
writel_relaxed(val, pcie->base + msi->reg_offsets[eq][reg]);
}
static inline u32 hwirq_to_group(struct iproc_msi *msi, unsigned long hwirq)
{
return (hwirq % msi->nr_irqs);
}
static inline unsigned int iproc_msi_addr_offset(struct iproc_msi *msi,
unsigned long hwirq)
{
if (msi->nr_msi_region > 1)
return hwirq_to_group(msi, hwirq) * MSI_MEM_REGION_SIZE;
else
return hwirq_to_group(msi, hwirq) * sizeof(u32);
}
static inline unsigned int iproc_msi_eq_offset(struct iproc_msi *msi, u32 eq)
{
if (msi->nr_eq_region > 1)
return eq * EQ_MEM_REGION_SIZE;
else
return eq * EQ_LEN * sizeof(u32);
}
static inline int hwirq_to_cpu(struct iproc_msi *msi, unsigned long hwirq)
{
return (hwirq % msi->nr_cpus);
}
static inline unsigned long hwirq_to_canonical_hwirq(struct iproc_msi *msi,
unsigned long hwirq)
{
return (hwirq - hwirq_to_cpu(msi, hwirq));
}
static int iproc_msi_irq_set_affinity(struct irq_data *data,
const struct cpumask *mask, bool force)
{
struct iproc_msi *msi = irq_data_get_irq_chip_data(data);
int target_cpu = cpumask_first(mask);
int curr_cpu;
curr_cpu = hwirq_to_cpu(msi, data->hwirq);
if (curr_cpu == target_cpu)
return IRQ_SET_MASK_OK_DONE;
data->hwirq = hwirq_to_canonical_hwirq(msi, data->hwirq) + target_cpu;
return IRQ_SET_MASK_OK;
}
static void iproc_msi_irq_compose_msi_msg(struct irq_data *data,
struct msi_msg *msg)
{
struct iproc_msi *msi = irq_data_get_irq_chip_data(data);
dma_addr_t addr;
addr = msi->msi_addr + iproc_msi_addr_offset(msi, data->hwirq);
msg->address_lo = lower_32_bits(addr);
msg->address_hi = upper_32_bits(addr);
msg->data = data->hwirq;
}
static int iproc_msi_irq_domain_alloc(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs,
void *args)
{
struct iproc_msi *msi = domain->host_data;
int hwirq;
mutex_lock(&msi->bitmap_lock);
hwirq = bitmap_find_next_zero_area(msi->bitmap, msi->nr_msi_vecs, 0,
msi->nr_cpus, 0);
if (hwirq < msi->nr_msi_vecs) {
bitmap_set(msi->bitmap, hwirq, msi->nr_cpus);
} else {
mutex_unlock(&msi->bitmap_lock);
return -ENOSPC;
}
mutex_unlock(&msi->bitmap_lock);
irq_domain_set_info(domain, virq, hwirq, &iproc_msi_bottom_irq_chip,
domain->host_data, handle_simple_irq, NULL, NULL);
return 0;
}
static void iproc_msi_irq_domain_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *data = irq_domain_get_irq_data(domain, virq);
struct iproc_msi *msi = irq_data_get_irq_chip_data(data);
unsigned int hwirq;
mutex_lock(&msi->bitmap_lock);
hwirq = hwirq_to_canonical_hwirq(msi, data->hwirq);
bitmap_clear(msi->bitmap, hwirq, msi->nr_cpus);
mutex_unlock(&msi->bitmap_lock);
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}
static inline u32 decode_msi_hwirq(struct iproc_msi *msi, u32 eq, u32 head)
{
u32 *msg, hwirq;
unsigned int offs;
offs = iproc_msi_eq_offset(msi, eq) + head * sizeof(u32);
msg = (u32 *)(msi->eq_cpu + offs);
hwirq = *msg & IPROC_MSI_EQ_MASK;
return hwirq_to_canonical_hwirq(msi, hwirq);
}
static void iproc_msi_handler(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct iproc_msi_grp *grp;
struct iproc_msi *msi;
u32 eq, head, tail, nr_events;
unsigned long hwirq;
int virq;
chained_irq_enter(chip, desc);
grp = irq_desc_get_handler_data(desc);
msi = grp->msi;
eq = grp->eq;
head = iproc_msi_read_reg(msi, IPROC_MSI_EQ_HEAD,
eq) & IPROC_MSI_EQ_MASK;
do {
tail = iproc_msi_read_reg(msi, IPROC_MSI_EQ_TAIL,
eq) & IPROC_MSI_EQ_MASK;
nr_events = (tail < head) ?
(EQ_LEN - (head - tail)) : (tail - head);
if (!nr_events)
break;
while (nr_events--) {
hwirq = decode_msi_hwirq(msi, eq, head);
virq = irq_find_mapping(msi->inner_domain, hwirq);
generic_handle_irq(virq);
head++;
head %= EQ_LEN;
}
iproc_msi_write_reg(msi, IPROC_MSI_EQ_HEAD, eq, head);
} while (true);
chained_irq_exit(chip, desc);
}
static void iproc_msi_enable(struct iproc_msi *msi)
{
int i, eq;
u32 val;
for (i = 0; i < msi->nr_eq_region; i++) {
dma_addr_t addr = msi->eq_dma + (i * EQ_MEM_REGION_SIZE);
iproc_msi_write_reg(msi, IPROC_MSI_EQ_PAGE, i,
lower_32_bits(addr));
iproc_msi_write_reg(msi, IPROC_MSI_EQ_PAGE_UPPER, i,
upper_32_bits(addr));
}
for (i = 0; i < msi->nr_msi_region; i++) {
phys_addr_t addr = msi->msi_addr + (i * MSI_MEM_REGION_SIZE);
iproc_msi_write_reg(msi, IPROC_MSI_PAGE, i,
lower_32_bits(addr));
iproc_msi_write_reg(msi, IPROC_MSI_PAGE_UPPER, i,
upper_32_bits(addr));
}
for (eq = 0; eq < msi->nr_irqs; eq++) {
val = IPROC_MSI_INTR_EN | IPROC_MSI_INT_N_EVENT |
IPROC_MSI_EQ_EN;
iproc_msi_write_reg(msi, IPROC_MSI_CTRL, eq, val);
if (msi->has_inten_reg) {
val = iproc_msi_read_reg(msi, IPROC_MSI_INTS_EN, eq);
val |= BIT(eq);
iproc_msi_write_reg(msi, IPROC_MSI_INTS_EN, eq, val);
}
}
}
static void iproc_msi_disable(struct iproc_msi *msi)
{
u32 eq, val;
for (eq = 0; eq < msi->nr_irqs; eq++) {
if (msi->has_inten_reg) {
val = iproc_msi_read_reg(msi, IPROC_MSI_INTS_EN, eq);
val &= ~BIT(eq);
iproc_msi_write_reg(msi, IPROC_MSI_INTS_EN, eq, val);
}
val = iproc_msi_read_reg(msi, IPROC_MSI_CTRL, eq);
val &= ~(IPROC_MSI_INTR_EN | IPROC_MSI_INT_N_EVENT |
IPROC_MSI_EQ_EN);
iproc_msi_write_reg(msi, IPROC_MSI_CTRL, eq, val);
}
}
static int iproc_msi_alloc_domains(struct device_node *node,
struct iproc_msi *msi)
{
msi->inner_domain = irq_domain_add_linear(NULL, msi->nr_msi_vecs,
&msi_domain_ops, msi);
if (!msi->inner_domain)
return -ENOMEM;
msi->msi_domain = pci_msi_create_irq_domain(of_node_to_fwnode(node),
&iproc_msi_domain_info,
msi->inner_domain);
if (!msi->msi_domain) {
irq_domain_remove(msi->inner_domain);
return -ENOMEM;
}
return 0;
}
static void iproc_msi_free_domains(struct iproc_msi *msi)
{
if (msi->msi_domain)
irq_domain_remove(msi->msi_domain);
if (msi->inner_domain)
irq_domain_remove(msi->inner_domain);
}
static void iproc_msi_irq_free(struct iproc_msi *msi, unsigned int cpu)
{
int i;
for (i = cpu; i < msi->nr_irqs; i += msi->nr_cpus) {
irq_set_chained_handler_and_data(msi->grps[i].gic_irq,
NULL, NULL);
}
}
static int iproc_msi_irq_setup(struct iproc_msi *msi, unsigned int cpu)
{
int i, ret;
cpumask_var_t mask;
struct iproc_pcie *pcie = msi->pcie;
for (i = cpu; i < msi->nr_irqs; i += msi->nr_cpus) {
irq_set_chained_handler_and_data(msi->grps[i].gic_irq,
iproc_msi_handler,
&msi->grps[i]);
if (alloc_cpumask_var(&mask, GFP_KERNEL)) {
cpumask_clear(mask);
cpumask_set_cpu(cpu, mask);
ret = irq_set_affinity(msi->grps[i].gic_irq, mask);
if (ret)
dev_err(pcie->dev,
"failed to set affinity for IRQ%d\n",
msi->grps[i].gic_irq);
free_cpumask_var(mask);
} else {
dev_err(pcie->dev, "failed to alloc CPU mask\n");
ret = -EINVAL;
}
if (ret) {
iproc_msi_irq_free(msi, cpu);
return ret;
}
}
return 0;
}
int iproc_msi_init(struct iproc_pcie *pcie, struct device_node *node)
{
struct iproc_msi *msi;
int i, ret;
unsigned int cpu;
if (!of_device_is_compatible(node, "brcm,iproc-msi"))
return -ENODEV;
if (!of_find_property(node, "msi-controller", NULL))
return -ENODEV;
if (pcie->msi)
return -EBUSY;
msi = devm_kzalloc(pcie->dev, sizeof(*msi), GFP_KERNEL);
if (!msi)
return -ENOMEM;
msi->pcie = pcie;
pcie->msi = msi;
msi->msi_addr = pcie->base_addr;
mutex_init(&msi->bitmap_lock);
msi->nr_cpus = num_possible_cpus();
msi->nr_irqs = of_irq_count(node);
if (!msi->nr_irqs) {
dev_err(pcie->dev, "found no MSI GIC interrupt\n");
return -ENODEV;
}
if (msi->nr_irqs > NR_HW_IRQS) {
dev_warn(pcie->dev, "too many MSI GIC interrupts defined %d\n",
msi->nr_irqs);
msi->nr_irqs = NR_HW_IRQS;
}
if (msi->nr_irqs < msi->nr_cpus) {
dev_err(pcie->dev,
"not enough GIC interrupts for MSI affinity\n");
return -EINVAL;
}
if (msi->nr_irqs % msi->nr_cpus != 0) {
msi->nr_irqs -= msi->nr_irqs % msi->nr_cpus;
dev_warn(pcie->dev, "Reducing number of interrupts to %d\n",
msi->nr_irqs);
}
switch (pcie->type) {
case IPROC_PCIE_PAXB_BCMA:
case IPROC_PCIE_PAXB:
msi->reg_offsets = iproc_msi_reg_paxb;
msi->nr_eq_region = 1;
msi->nr_msi_region = 1;
break;
case IPROC_PCIE_PAXC:
msi->reg_offsets = iproc_msi_reg_paxc;
msi->nr_eq_region = msi->nr_irqs;
msi->nr_msi_region = msi->nr_irqs;
break;
default:
dev_err(pcie->dev, "incompatible iProc PCIe interface\n");
return -EINVAL;
}
if (of_find_property(node, "brcm,pcie-msi-inten", NULL))
msi->has_inten_reg = true;
msi->nr_msi_vecs = msi->nr_irqs * EQ_LEN;
msi->bitmap = devm_kcalloc(pcie->dev, BITS_TO_LONGS(msi->nr_msi_vecs),
sizeof(*msi->bitmap), GFP_KERNEL);
if (!msi->bitmap)
return -ENOMEM;
msi->grps = devm_kcalloc(pcie->dev, msi->nr_irqs, sizeof(*msi->grps),
GFP_KERNEL);
if (!msi->grps)
return -ENOMEM;
for (i = 0; i < msi->nr_irqs; i++) {
unsigned int irq = irq_of_parse_and_map(node, i);
if (!irq) {
dev_err(pcie->dev, "unable to parse/map interrupt\n");
ret = -ENODEV;
goto free_irqs;
}
msi->grps[i].gic_irq = irq;
msi->grps[i].msi = msi;
msi->grps[i].eq = i;
}
msi->eq_cpu = dma_zalloc_coherent(pcie->dev,
msi->nr_eq_region * EQ_MEM_REGION_SIZE,
&msi->eq_dma, GFP_KERNEL);
if (!msi->eq_cpu) {
ret = -ENOMEM;
goto free_irqs;
}
ret = iproc_msi_alloc_domains(node, msi);
if (ret) {
dev_err(pcie->dev, "failed to create MSI domains\n");
goto free_eq_dma;
}
for_each_online_cpu(cpu) {
ret = iproc_msi_irq_setup(msi, cpu);
if (ret)
goto free_msi_irq;
}
iproc_msi_enable(msi);
return 0;
free_msi_irq:
for_each_online_cpu(cpu)
iproc_msi_irq_free(msi, cpu);
iproc_msi_free_domains(msi);
free_eq_dma:
dma_free_coherent(pcie->dev, msi->nr_eq_region * EQ_MEM_REGION_SIZE,
msi->eq_cpu, msi->eq_dma);
free_irqs:
for (i = 0; i < msi->nr_irqs; i++) {
if (msi->grps[i].gic_irq)
irq_dispose_mapping(msi->grps[i].gic_irq);
}
pcie->msi = NULL;
return ret;
}
void iproc_msi_exit(struct iproc_pcie *pcie)
{
struct iproc_msi *msi = pcie->msi;
unsigned int i, cpu;
if (!msi)
return;
iproc_msi_disable(msi);
for_each_online_cpu(cpu)
iproc_msi_irq_free(msi, cpu);
iproc_msi_free_domains(msi);
dma_free_coherent(pcie->dev, msi->nr_eq_region * EQ_MEM_REGION_SIZE,
msi->eq_cpu, msi->eq_dma);
for (i = 0; i < msi->nr_irqs; i++) {
if (msi->grps[i].gic_irq)
irq_dispose_mapping(msi->grps[i].gic_irq);
}
}
