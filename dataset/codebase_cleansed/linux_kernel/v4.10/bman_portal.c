static struct bman_portal *init_pcfg(struct bm_portal_config *pcfg)
{
struct bman_portal *p = bman_create_affine_portal(pcfg);
if (!p) {
dev_crit(pcfg->dev, "%s: Portal failure on cpu %d\n",
__func__, pcfg->cpu);
return NULL;
}
bman_p_irqsource_add(p, BM_PIRQ_RCRI);
affine_bportals[pcfg->cpu] = p;
dev_info(pcfg->dev, "Portal initialised, cpu %d\n", pcfg->cpu);
return p;
}
static int bman_offline_cpu(unsigned int cpu)
{
struct bman_portal *p = affine_bportals[cpu];
const struct bm_portal_config *pcfg;
if (!p)
return 0;
pcfg = bman_get_bm_portal_config(p);
if (!pcfg)
return 0;
irq_set_affinity(pcfg->irq, cpumask_of(0));
return 0;
}
static int bman_online_cpu(unsigned int cpu)
{
struct bman_portal *p = affine_bportals[cpu];
const struct bm_portal_config *pcfg;
if (!p)
return 0;
pcfg = bman_get_bm_portal_config(p);
if (!pcfg)
return 0;
irq_set_affinity(pcfg->irq, cpumask_of(cpu));
return 0;
}
static int bman_portal_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct bm_portal_config *pcfg;
struct resource *addr_phys[2];
void __iomem *va;
int irq, cpu;
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
pcfg->cpu = -1;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "Can't get %s IRQ'\n", node->full_name);
return -ENXIO;
}
pcfg->irq = irq;
va = ioremap_prot(addr_phys[0]->start, resource_size(addr_phys[0]), 0);
if (!va) {
dev_err(dev, "ioremap::CE failed\n");
goto err_ioremap1;
}
pcfg->addr_virt[DPAA_PORTAL_CE] = va;
va = ioremap_prot(addr_phys[1]->start, resource_size(addr_phys[1]),
_PAGE_GUARDED | _PAGE_NO_CACHE);
if (!va) {
dev_err(dev, "ioremap::CI failed\n");
goto err_ioremap2;
}
pcfg->addr_virt[DPAA_PORTAL_CI] = va;
spin_lock(&bman_lock);
cpu = cpumask_next_zero(-1, &portal_cpus);
if (cpu >= nr_cpu_ids) {
spin_unlock(&bman_lock);
return 0;
}
cpumask_set_cpu(cpu, &portal_cpus);
spin_unlock(&bman_lock);
pcfg->cpu = cpu;
if (!init_pcfg(pcfg)) {
dev_err(dev, "portal init failed\n");
goto err_portal_init;
}
if (!cpu_online(cpu))
bman_offline_cpu(cpu);
return 0;
err_portal_init:
iounmap(pcfg->addr_virt[DPAA_PORTAL_CI]);
err_ioremap2:
iounmap(pcfg->addr_virt[DPAA_PORTAL_CE]);
err_ioremap1:
return -ENXIO;
}
static int __init bman_portal_driver_register(struct platform_driver *drv)
{
int ret;
ret = platform_driver_register(drv);
if (ret < 0)
return ret;
ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN,
"soc/qbman_portal:online",
bman_online_cpu, bman_offline_cpu);
if (ret < 0) {
pr_err("bman: failed to register hotplug callbacks.\n");
platform_driver_unregister(drv);
return ret;
}
return 0;
}
