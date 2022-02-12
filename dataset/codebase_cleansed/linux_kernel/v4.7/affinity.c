static inline void init_cpu_mask_set(struct cpu_mask_set *set)
{
cpumask_clear(&set->mask);
cpumask_clear(&set->used);
set->gen = 0;
}
int init_real_cpu_mask(struct hfi1_devdata *dd)
{
struct hfi1_affinity *info;
int possible, curr_cpu, i, ht;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
cpumask_clear(&info->real_cpu_mask);
cpumask_copy(&info->real_cpu_mask, cpu_online_mask);
possible = cpumask_weight(&info->real_cpu_mask);
ht = cpumask_weight(topology_sibling_cpumask(
cpumask_first(&info->real_cpu_mask)));
curr_cpu = cpumask_first(&info->real_cpu_mask);
for (i = 0; i < possible / ht; i++)
curr_cpu = cpumask_next(curr_cpu, &info->real_cpu_mask);
for (; i < possible; i++) {
cpumask_clear_cpu(curr_cpu, &info->real_cpu_mask);
curr_cpu = cpumask_next(curr_cpu, &info->real_cpu_mask);
}
dd->affinity = info;
return 0;
}
void hfi1_dev_affinity_init(struct hfi1_devdata *dd)
{
int node = pcibus_to_node(dd->pcidev->bus);
struct hfi1_affinity *info = dd->affinity;
const struct cpumask *local_mask;
int curr_cpu, possible, i;
if (node < 0)
node = numa_node_id();
dd->node = node;
spin_lock_init(&info->lock);
init_cpu_mask_set(&info->def_intr);
init_cpu_mask_set(&info->rcv_intr);
init_cpu_mask_set(&info->proc);
local_mask = cpumask_of_node(dd->node);
if (cpumask_first(local_mask) >= nr_cpu_ids)
local_mask = topology_core_cpumask(0);
cpumask_and(&info->def_intr.mask, &info->real_cpu_mask, local_mask);
possible = cpumask_weight(&info->def_intr.mask);
curr_cpu = cpumask_first(&info->def_intr.mask);
if (possible == 1) {
cpumask_set_cpu(curr_cpu, &info->rcv_intr.mask);
} else {
curr_cpu = cpumask_next(curr_cpu, &info->def_intr.mask);
for (i = 0; i < dd->n_krcv_queues - 1; i++) {
cpumask_clear_cpu(curr_cpu, &info->def_intr.mask);
cpumask_set_cpu(curr_cpu, &info->rcv_intr.mask);
curr_cpu = cpumask_next(curr_cpu, &info->def_intr.mask);
if (curr_cpu >= nr_cpu_ids)
break;
}
}
cpumask_copy(&info->proc.mask, cpu_online_mask);
}
void hfi1_dev_affinity_free(struct hfi1_devdata *dd)
{
kfree(dd->affinity);
}
int hfi1_get_irq_affinity(struct hfi1_devdata *dd, struct hfi1_msix_entry *msix)
{
int ret;
cpumask_var_t diff;
struct cpu_mask_set *set;
struct sdma_engine *sde = NULL;
struct hfi1_ctxtdata *rcd = NULL;
char extra[64];
int cpu = -1;
extra[0] = '\0';
cpumask_clear(&msix->mask);
ret = zalloc_cpumask_var(&diff, GFP_KERNEL);
if (!ret)
return -ENOMEM;
switch (msix->type) {
case IRQ_SDMA:
sde = (struct sdma_engine *)msix->arg;
scnprintf(extra, 64, "engine %u", sde->this_idx);
case IRQ_GENERAL:
set = &dd->affinity->def_intr;
break;
case IRQ_RCVCTXT:
rcd = (struct hfi1_ctxtdata *)msix->arg;
if (rcd->ctxt == HFI1_CTRL_CTXT) {
set = &dd->affinity->def_intr;
cpu = cpumask_first(&set->mask);
} else {
set = &dd->affinity->rcv_intr;
}
scnprintf(extra, 64, "ctxt %u", rcd->ctxt);
break;
default:
dd_dev_err(dd, "Invalid IRQ type %d\n", msix->type);
return -EINVAL;
}
if (cpu == -1) {
spin_lock(&dd->affinity->lock);
if (cpumask_equal(&set->mask, &set->used)) {
set->gen++;
cpumask_clear(&set->used);
}
cpumask_andnot(diff, &set->mask, &set->used);
cpu = cpumask_first(diff);
cpumask_set_cpu(cpu, &set->used);
spin_unlock(&dd->affinity->lock);
}
switch (msix->type) {
case IRQ_SDMA:
sde->cpu = cpu;
break;
case IRQ_GENERAL:
case IRQ_RCVCTXT:
case IRQ_OTHER:
break;
}
cpumask_set_cpu(cpu, &msix->mask);
dd_dev_info(dd, "IRQ vector: %u, type %s %s -> cpu: %d\n",
msix->msix.vector, irq_type_names[msix->type],
extra, cpu);
irq_set_affinity_hint(msix->msix.vector, &msix->mask);
free_cpumask_var(diff);
return 0;
}
void hfi1_put_irq_affinity(struct hfi1_devdata *dd,
struct hfi1_msix_entry *msix)
{
struct cpu_mask_set *set = NULL;
struct hfi1_ctxtdata *rcd;
switch (msix->type) {
case IRQ_SDMA:
case IRQ_GENERAL:
set = &dd->affinity->def_intr;
break;
case IRQ_RCVCTXT:
rcd = (struct hfi1_ctxtdata *)msix->arg;
if (rcd->ctxt != HFI1_CTRL_CTXT)
set = &dd->affinity->rcv_intr;
break;
default:
return;
}
if (set) {
spin_lock(&dd->affinity->lock);
cpumask_andnot(&set->used, &set->used, &msix->mask);
if (cpumask_empty(&set->used) && set->gen) {
set->gen--;
cpumask_copy(&set->used, &set->mask);
}
spin_unlock(&dd->affinity->lock);
}
irq_set_affinity_hint(msix->msix.vector, NULL);
cpumask_clear(&msix->mask);
}
int hfi1_get_proc_affinity(struct hfi1_devdata *dd, int node)
{
int cpu = -1, ret;
cpumask_var_t diff, mask, intrs;
const struct cpumask *node_mask,
*proc_mask = tsk_cpus_allowed(current);
struct cpu_mask_set *set = &dd->affinity->proc;
if (cpumask_weight(proc_mask) == 1) {
hfi1_cdbg(PROC, "PID %u %s affinity set to CPU %*pbl",
current->pid, current->comm,
cpumask_pr_args(proc_mask));
cpu = cpumask_first(proc_mask);
cpumask_set_cpu(cpu, &set->used);
goto done;
} else if (cpumask_weight(proc_mask) < cpumask_weight(&set->mask)) {
hfi1_cdbg(PROC, "PID %u %s affinity set to CPU set(s) %*pbl",
current->pid, current->comm,
cpumask_pr_args(proc_mask));
goto done;
}
ret = zalloc_cpumask_var(&diff, GFP_KERNEL);
if (!ret)
goto done;
ret = zalloc_cpumask_var(&mask, GFP_KERNEL);
if (!ret)
goto free_diff;
ret = zalloc_cpumask_var(&intrs, GFP_KERNEL);
if (!ret)
goto free_mask;
spin_lock(&dd->affinity->lock);
if (cpumask_equal(&set->mask, &set->used)) {
set->gen++;
cpumask_clear(&set->used);
}
cpumask_copy(intrs, (dd->affinity->def_intr.gen ?
&dd->affinity->def_intr.mask :
&dd->affinity->def_intr.used));
cpumask_or(intrs, intrs, (dd->affinity->rcv_intr.gen ?
&dd->affinity->rcv_intr.mask :
&dd->affinity->rcv_intr.used));
hfi1_cdbg(PROC, "CPUs used by interrupts: %*pbl",
cpumask_pr_args(intrs));
if (node == -1)
node = dd->node;
node_mask = cpumask_of_node(node);
hfi1_cdbg(PROC, "device on NUMA %u, CPUs %*pbl", node,
cpumask_pr_args(node_mask));
cpumask_andnot(diff, &set->mask, &set->used);
hfi1_cdbg(PROC, "unused CPUs (all) %*pbl", cpumask_pr_args(diff));
cpumask_and(mask, diff, node_mask);
hfi1_cdbg(PROC, "available cpus on NUMA %*pbl", cpumask_pr_args(mask));
cpumask_andnot(diff, mask, intrs);
if (!cpumask_empty(diff))
cpumask_copy(mask, diff);
if (cpumask_empty(mask)) {
cpumask_andnot(diff, &set->mask, &set->used);
cpumask_andnot(mask, diff, node_mask);
}
hfi1_cdbg(PROC, "possible CPUs for process %*pbl",
cpumask_pr_args(mask));
cpu = cpumask_first(mask);
if (cpu >= nr_cpu_ids)
cpu = -1;
else
cpumask_set_cpu(cpu, &set->used);
spin_unlock(&dd->affinity->lock);
free_cpumask_var(intrs);
free_mask:
free_cpumask_var(mask);
free_diff:
free_cpumask_var(diff);
done:
return cpu;
}
void hfi1_put_proc_affinity(struct hfi1_devdata *dd, int cpu)
{
struct cpu_mask_set *set = &dd->affinity->proc;
if (cpu < 0)
return;
spin_lock(&dd->affinity->lock);
cpumask_clear_cpu(cpu, &set->used);
if (cpumask_empty(&set->used) && set->gen) {
set->gen--;
cpumask_copy(&set->used, &set->mask);
}
spin_unlock(&dd->affinity->lock);
}
