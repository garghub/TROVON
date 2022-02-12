int its_alloc_vcpu_irqs(struct its_vm *vm)
{
int vpe_base_irq, i;
vm->fwnode = irq_domain_alloc_named_id_fwnode("GICv4-vpe",
task_pid_nr(current));
if (!vm->fwnode)
goto err;
vm->domain = irq_domain_create_hierarchy(gic_domain, 0, vm->nr_vpes,
vm->fwnode, vpe_domain_ops,
vm);
if (!vm->domain)
goto err;
for (i = 0; i < vm->nr_vpes; i++) {
vm->vpes[i]->its_vm = vm;
vm->vpes[i]->idai = true;
}
vpe_base_irq = __irq_domain_alloc_irqs(vm->domain, -1, vm->nr_vpes,
NUMA_NO_NODE, vm,
false, NULL);
if (vpe_base_irq <= 0)
goto err;
for (i = 0; i < vm->nr_vpes; i++)
vm->vpes[i]->irq = vpe_base_irq + i;
return 0;
err:
if (vm->domain)
irq_domain_remove(vm->domain);
if (vm->fwnode)
irq_domain_free_fwnode(vm->fwnode);
return -ENOMEM;
}
void its_free_vcpu_irqs(struct its_vm *vm)
{
irq_domain_free_irqs(vm->vpes[0]->irq, vm->nr_vpes);
irq_domain_remove(vm->domain);
irq_domain_free_fwnode(vm->fwnode);
}
static int its_send_vpe_cmd(struct its_vpe *vpe, struct its_cmd_info *info)
{
return irq_set_vcpu_affinity(vpe->irq, info);
}
int its_schedule_vpe(struct its_vpe *vpe, bool on)
{
struct its_cmd_info info;
WARN_ON(preemptible());
info.cmd_type = on ? SCHEDULE_VPE : DESCHEDULE_VPE;
return its_send_vpe_cmd(vpe, &info);
}
int its_invall_vpe(struct its_vpe *vpe)
{
struct its_cmd_info info = {
.cmd_type = INVALL_VPE,
};
return its_send_vpe_cmd(vpe, &info);
}
int its_map_vlpi(int irq, struct its_vlpi_map *map)
{
struct its_cmd_info info = {
.cmd_type = MAP_VLPI,
{
.map = map,
},
};
irq_set_status_flags(irq, IRQ_DISABLE_UNLAZY);
return irq_set_vcpu_affinity(irq, &info);
}
int its_get_vlpi(int irq, struct its_vlpi_map *map)
{
struct its_cmd_info info = {
.cmd_type = GET_VLPI,
{
.map = map,
},
};
return irq_set_vcpu_affinity(irq, &info);
}
int its_unmap_vlpi(int irq)
{
irq_clear_status_flags(irq, IRQ_DISABLE_UNLAZY);
return irq_set_vcpu_affinity(irq, NULL);
}
int its_prop_update_vlpi(int irq, u8 config, bool inv)
{
struct its_cmd_info info = {
.cmd_type = inv ? PROP_UPDATE_AND_INV_VLPI : PROP_UPDATE_VLPI,
{
.config = config,
},
};
return irq_set_vcpu_affinity(irq, &info);
}
int its_init_v4(struct irq_domain *domain, const struct irq_domain_ops *ops)
{
if (domain) {
pr_info("ITS: Enabling GICv4 support\n");
gic_domain = domain;
vpe_domain_ops = ops;
return 0;
}
pr_err("ITS: No GICv4 VPE domain allocated\n");
return -ENODEV;
}
