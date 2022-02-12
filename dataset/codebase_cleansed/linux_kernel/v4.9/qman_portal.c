static void portal_set_cpu(struct qm_portal_config *pcfg, int cpu)
{
#ifdef CONFIG_FSL_PAMU
struct device *dev = pcfg->dev;
int window_count = 1;
struct iommu_domain_geometry geom_attr;
struct pamu_stash_attribute stash_attr;
int ret;
pcfg->iommu_domain = iommu_domain_alloc(&platform_bus_type);
if (!pcfg->iommu_domain) {
dev_err(dev, "%s(): iommu_domain_alloc() failed", __func__);
goto no_iommu;
}
geom_attr.aperture_start = 0;
geom_attr.aperture_end =
((dma_addr_t)1 << min(8 * sizeof(dma_addr_t), (size_t)36)) - 1;
geom_attr.force_aperture = true;
ret = iommu_domain_set_attr(pcfg->iommu_domain, DOMAIN_ATTR_GEOMETRY,
&geom_attr);
if (ret < 0) {
dev_err(dev, "%s(): iommu_domain_set_attr() = %d", __func__,
ret);
goto out_domain_free;
}
ret = iommu_domain_set_attr(pcfg->iommu_domain, DOMAIN_ATTR_WINDOWS,
&window_count);
if (ret < 0) {
dev_err(dev, "%s(): iommu_domain_set_attr() = %d", __func__,
ret);
goto out_domain_free;
}
stash_attr.cpu = cpu;
stash_attr.cache = PAMU_ATTR_CACHE_L1;
ret = iommu_domain_set_attr(pcfg->iommu_domain,
DOMAIN_ATTR_FSL_PAMU_STASH,
&stash_attr);
if (ret < 0) {
dev_err(dev, "%s(): iommu_domain_set_attr() = %d",
__func__, ret);
goto out_domain_free;
}
ret = iommu_domain_window_enable(pcfg->iommu_domain, 0, 0, 1ULL << 36,
IOMMU_READ | IOMMU_WRITE);
if (ret < 0) {
dev_err(dev, "%s(): iommu_domain_window_enable() = %d",
__func__, ret);
goto out_domain_free;
}
ret = iommu_attach_device(pcfg->iommu_domain, dev);
if (ret < 0) {
dev_err(dev, "%s(): iommu_device_attach() = %d", __func__,
ret);
goto out_domain_free;
}
ret = iommu_domain_set_attr(pcfg->iommu_domain,
DOMAIN_ATTR_FSL_PAMU_ENABLE,
&window_count);
if (ret < 0) {
dev_err(dev, "%s(): iommu_domain_set_attr() = %d", __func__,
ret);
goto out_detach_device;
}
no_iommu:
#endif
qman_set_sdest(pcfg->channel, cpu);
return;
#ifdef CONFIG_FSL_PAMU
out_detach_device:
iommu_detach_device(pcfg->iommu_domain, NULL);
out_domain_free:
iommu_domain_free(pcfg->iommu_domain);
pcfg->iommu_domain = NULL;
#endif
}
static struct qman_portal *init_pcfg(struct qm_portal_config *pcfg)
{
struct qman_portal *p;
u32 irq_sources = 0;
qman_liodn_fixup(pcfg->channel);
pcfg->iommu_domain = NULL;
portal_set_cpu(pcfg, pcfg->cpu);
p = qman_create_affine_portal(pcfg, NULL);
if (!p) {
dev_crit(pcfg->dev, "%s: Portal failure on cpu %d\n",
__func__, pcfg->cpu);
return NULL;
}
#ifdef CONFIG_FSL_DPA_PIRQ_SLOW
irq_sources |= QM_PIRQ_EQCI | QM_PIRQ_EQRI | QM_PIRQ_MRI |
QM_PIRQ_CSCI;
#endif
#ifdef CONFIG_FSL_DPA_PIRQ_FAST
irq_sources |= QM_PIRQ_DQRI;
#endif
qman_p_irqsource_add(p, irq_sources);
spin_lock(&qman_lock);
if (cpumask_equal(&portal_cpus, cpu_possible_mask)) {
qman_init_cgr_all();
}
spin_unlock(&qman_lock);
dev_info(pcfg->dev, "Portal initialised, cpu %d\n", pcfg->cpu);
return p;
}
static void qman_portal_update_sdest(const struct qm_portal_config *pcfg,
unsigned int cpu)
{
#ifdef CONFIG_FSL_PAMU
struct pamu_stash_attribute stash_attr;
int ret;
if (pcfg->iommu_domain) {
stash_attr.cpu = cpu;
stash_attr.cache = PAMU_ATTR_CACHE_L1;
ret = iommu_domain_set_attr(pcfg->iommu_domain,
DOMAIN_ATTR_FSL_PAMU_STASH, &stash_attr);
if (ret < 0) {
dev_err(pcfg->dev,
"Failed to update pamu stash setting\n");
return;
}
}
#endif
qman_set_sdest(pcfg->channel, cpu);
}
static void qman_offline_cpu(unsigned int cpu)
{
struct qman_portal *p;
const struct qm_portal_config *pcfg;
p = affine_portals[cpu];
if (p) {
pcfg = qman_get_qm_portal_config(p);
if (pcfg) {
irq_set_affinity(pcfg->irq, cpumask_of(0));
qman_portal_update_sdest(pcfg, 0);
}
}
}
static void qman_online_cpu(unsigned int cpu)
{
struct qman_portal *p;
const struct qm_portal_config *pcfg;
p = affine_portals[cpu];
if (p) {
pcfg = qman_get_qm_portal_config(p);
if (pcfg) {
irq_set_affinity(pcfg->irq, cpumask_of(cpu));
qman_portal_update_sdest(pcfg, cpu);
}
}
}
static int qman_hotplug_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
qman_online_cpu(cpu);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
qman_offline_cpu(cpu);
default:
break;
}
return NOTIFY_OK;
}
static int qman_portal_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct qm_portal_config *pcfg;
struct resource *addr_phys[2];
const u32 *channel;
void __iomem *va;
int irq, len, cpu;
pcfg = devm_kmalloc(dev, sizeof(*pcfg), GFP_KERNEL);
if (!pcfg)
return -ENOMEM;
pcfg->dev = dev;
addr_phys[0] = platform_get_resource(pdev, IORESOURCE_MEM,
DPAA_PORTAL_CE);
if (!addr_phys[0]) {
dev_err(dev, "Can't get %s property 'reg::CE'\n",
node->full_name);
return -ENXIO;
}
addr_phys[1] = platform_get_resource(pdev, IORESOURCE_MEM,
DPAA_PORTAL_CI);
if (!addr_phys[1]) {
dev_err(dev, "Can't get %s property 'reg::CI'\n",
node->full_name);
return -ENXIO;
}
channel = of_get_property(node, "cell-index", &len);
if (!channel || (len != 4)) {
dev_err(dev, "Can't get %s property 'cell-index'\n",
node->full_name);
return -ENXIO;
}
pcfg->channel = *channel;
pcfg->cpu = -1;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "Can't get %s IRQ\n", node->full_name);
return -ENXIO;
}
pcfg->irq = irq;
va = ioremap_prot(addr_phys[0]->start, resource_size(addr_phys[0]), 0);
if (!va)
goto err_ioremap1;
pcfg->addr_virt[DPAA_PORTAL_CE] = va;
va = ioremap_prot(addr_phys[1]->start, resource_size(addr_phys[1]),
_PAGE_GUARDED | _PAGE_NO_CACHE);
if (!va)
goto err_ioremap2;
pcfg->addr_virt[DPAA_PORTAL_CI] = va;
pcfg->pools = qm_get_pools_sdqcr();
spin_lock(&qman_lock);
cpu = cpumask_next_zero(-1, &portal_cpus);
if (cpu >= nr_cpu_ids) {
spin_unlock(&qman_lock);
return 0;
}
cpumask_set_cpu(cpu, &portal_cpus);
spin_unlock(&qman_lock);
pcfg->cpu = cpu;
if (!init_pcfg(pcfg))
goto err_ioremap2;
if (!cpu_online(cpu))
qman_offline_cpu(cpu);
return 0;
err_ioremap2:
iounmap(pcfg->addr_virt[DPAA_PORTAL_CE]);
err_ioremap1:
dev_err(dev, "ioremap failed\n");
return -ENXIO;
}
static int __init qman_portal_driver_register(struct platform_driver *drv)
{
int ret;
ret = platform_driver_register(drv);
if (ret < 0)
return ret;
register_hotcpu_notifier(&qman_hotplug_cpu_notifier);
return 0;
}
