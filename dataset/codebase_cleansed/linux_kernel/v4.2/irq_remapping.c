static void irq_remapping_disable_io_apic(void)
{
if (cpu_has_apic || apic_from_smp_config())
disconnect_bsp_APIC(0);
}
static void __init irq_remapping_modify_x86_ops(void)
{
x86_io_apic_ops.disable = irq_remapping_disable_io_apic;
}
static __init int setup_nointremap(char *str)
{
disable_irq_remap = 1;
return 0;
}
static __init int setup_irqremap(char *str)
{
if (!str)
return -EINVAL;
while (*str) {
if (!strncmp(str, "on", 2))
disable_irq_remap = 0;
else if (!strncmp(str, "off", 3))
disable_irq_remap = 1;
else if (!strncmp(str, "nosid", 5))
disable_sourceid_checking = 1;
else if (!strncmp(str, "no_x2apic_optout", 16))
no_x2apic_optout = 1;
str += strcspn(str, ",");
while (*str == ',')
str++;
}
return 0;
}
void set_irq_remapping_broken(void)
{
irq_remap_broken = 1;
}
bool irq_remapping_cap(enum irq_remap_cap cap)
{
if (!remap_ops || disable_irq_post)
return 0;
return (remap_ops->capability & (1 << cap));
}
int __init irq_remapping_prepare(void)
{
if (disable_irq_remap)
return -ENOSYS;
if (intel_irq_remap_ops.prepare() == 0)
remap_ops = &intel_irq_remap_ops;
else if (IS_ENABLED(CONFIG_AMD_IOMMU) &&
amd_iommu_irq_ops.prepare() == 0)
remap_ops = &amd_iommu_irq_ops;
else
return -ENOSYS;
return 0;
}
int __init irq_remapping_enable(void)
{
int ret;
if (!remap_ops->enable)
return -ENODEV;
ret = remap_ops->enable();
if (irq_remapping_enabled)
irq_remapping_modify_x86_ops();
return ret;
}
void irq_remapping_disable(void)
{
if (irq_remapping_enabled && remap_ops->disable)
remap_ops->disable();
}
int irq_remapping_reenable(int mode)
{
if (irq_remapping_enabled && remap_ops->reenable)
return remap_ops->reenable(mode);
return 0;
}
int __init irq_remap_enable_fault_handling(void)
{
if (!irq_remapping_enabled)
return 0;
if (!remap_ops->enable_faulting)
return -ENODEV;
return remap_ops->enable_faulting();
}
void panic_if_irq_remap(const char *msg)
{
if (irq_remapping_enabled)
panic(msg);
}
void ir_ack_apic_edge(struct irq_data *data)
{
ack_APIC_irq();
}
struct irq_domain *
irq_remapping_get_ir_irq_domain(struct irq_alloc_info *info)
{
if (!remap_ops || !remap_ops->get_ir_irq_domain)
return NULL;
return remap_ops->get_ir_irq_domain(info);
}
struct irq_domain *
irq_remapping_get_irq_domain(struct irq_alloc_info *info)
{
if (!remap_ops || !remap_ops->get_irq_domain)
return NULL;
return remap_ops->get_irq_domain(info);
}
