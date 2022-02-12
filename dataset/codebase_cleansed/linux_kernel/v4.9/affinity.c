static inline void init_cpu_mask_set(struct cpu_mask_set *set)
{
cpumask_clear(&set->mask);
cpumask_clear(&set->used);
set->gen = 0;
}
void init_real_cpu_mask(void)
{
int possible, curr_cpu, i, ht;
cpumask_clear(&node_affinity.real_cpu_mask);
cpumask_copy(&node_affinity.real_cpu_mask, cpu_online_mask);
possible = cpumask_weight(&node_affinity.real_cpu_mask);
ht = cpumask_weight(topology_sibling_cpumask(
cpumask_first(&node_affinity.real_cpu_mask)));
curr_cpu = cpumask_first(&node_affinity.real_cpu_mask);
for (i = 0; i < possible / ht; i++)
curr_cpu = cpumask_next(curr_cpu, &node_affinity.real_cpu_mask);
for (; i < possible; i++) {
cpumask_clear_cpu(curr_cpu, &node_affinity.real_cpu_mask);
curr_cpu = cpumask_next(curr_cpu, &node_affinity.real_cpu_mask);
}
}
int node_affinity_init(void)
{
int node;
struct pci_dev *dev = NULL;
const struct pci_device_id *ids = hfi1_pci_tbl;
cpumask_clear(&node_affinity.proc.used);
cpumask_copy(&node_affinity.proc.mask, cpu_online_mask);
node_affinity.proc.gen = 0;
node_affinity.num_core_siblings =
cpumask_weight(topology_sibling_cpumask(
cpumask_first(&node_affinity.proc.mask)
));
node_affinity.num_online_nodes = num_online_nodes();
node_affinity.num_online_cpus = num_online_cpus();
init_real_cpu_mask();
hfi1_per_node_cntr = kcalloc(num_possible_nodes(),
sizeof(*hfi1_per_node_cntr), GFP_KERNEL);
if (!hfi1_per_node_cntr)
return -ENOMEM;
while (ids->vendor) {
dev = NULL;
while ((dev = pci_get_device(ids->vendor, ids->device, dev))) {
node = pcibus_to_node(dev->bus);
if (node < 0)
node = numa_node_id();
hfi1_per_node_cntr[node]++;
}
ids++;
}
return 0;
}
void node_affinity_destroy(void)
{
struct list_head *pos, *q;
struct hfi1_affinity_node *entry;
mutex_lock(&node_affinity.lock);
list_for_each_safe(pos, q, &node_affinity.list) {
entry = list_entry(pos, struct hfi1_affinity_node,
list);
list_del(pos);
kfree(entry);
}
mutex_unlock(&node_affinity.lock);
kfree(hfi1_per_node_cntr);
}
static struct hfi1_affinity_node *node_affinity_allocate(int node)
{
struct hfi1_affinity_node *entry;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return NULL;
entry->node = node;
INIT_LIST_HEAD(&entry->list);
return entry;
}
static void node_affinity_add_tail(struct hfi1_affinity_node *entry)
{
list_add_tail(&entry->list, &node_affinity.list);
}
static struct hfi1_affinity_node *node_affinity_lookup(int node)
{
struct list_head *pos;
struct hfi1_affinity_node *entry;
list_for_each(pos, &node_affinity.list) {
entry = list_entry(pos, struct hfi1_affinity_node, list);
if (entry->node == node)
return entry;
}
return NULL;
}
int hfi1_dev_affinity_init(struct hfi1_devdata *dd)
{
int node = pcibus_to_node(dd->pcidev->bus);
struct hfi1_affinity_node *entry;
const struct cpumask *local_mask;
int curr_cpu, possible, i;
if (node < 0)
node = numa_node_id();
dd->node = node;
local_mask = cpumask_of_node(dd->node);
if (cpumask_first(local_mask) >= nr_cpu_ids)
local_mask = topology_core_cpumask(0);
mutex_lock(&node_affinity.lock);
entry = node_affinity_lookup(dd->node);
if (!entry) {
entry = node_affinity_allocate(node);
if (!entry) {
dd_dev_err(dd,
"Unable to allocate global affinity node\n");
mutex_unlock(&node_affinity.lock);
return -ENOMEM;
}
init_cpu_mask_set(&entry->def_intr);
init_cpu_mask_set(&entry->rcv_intr);
cpumask_clear(&entry->general_intr_mask);
cpumask_and(&entry->def_intr.mask, &node_affinity.real_cpu_mask,
local_mask);
possible = cpumask_weight(&entry->def_intr.mask);
curr_cpu = cpumask_first(&entry->def_intr.mask);
if (possible == 1) {
cpumask_set_cpu(curr_cpu, &entry->rcv_intr.mask);
cpumask_set_cpu(curr_cpu, &entry->general_intr_mask);
} else {
cpumask_clear_cpu(curr_cpu, &entry->def_intr.mask);
cpumask_set_cpu(curr_cpu, &entry->general_intr_mask);
curr_cpu = cpumask_next(curr_cpu,
&entry->def_intr.mask);
for (i = 0;
i < (dd->n_krcv_queues - 1) *
hfi1_per_node_cntr[dd->node];
i++) {
cpumask_clear_cpu(curr_cpu,
&entry->def_intr.mask);
cpumask_set_cpu(curr_cpu,
&entry->rcv_intr.mask);
curr_cpu = cpumask_next(curr_cpu,
&entry->def_intr.mask);
if (curr_cpu >= nr_cpu_ids)
break;
}
if (cpumask_weight(&entry->def_intr.mask) == 0)
cpumask_copy(&entry->def_intr.mask,
&entry->general_intr_mask);
}
node_affinity_add_tail(entry);
}
mutex_unlock(&node_affinity.lock);
return 0;
}
static void hfi1_update_sdma_affinity(struct hfi1_msix_entry *msix, int cpu)
{
struct sdma_engine *sde = msix->arg;
struct hfi1_devdata *dd = sde->dd;
struct hfi1_affinity_node *entry;
struct cpu_mask_set *set;
int i, old_cpu;
if (cpu > num_online_cpus() || cpu == sde->cpu)
return;
mutex_lock(&node_affinity.lock);
entry = node_affinity_lookup(dd->node);
if (!entry)
goto unlock;
old_cpu = sde->cpu;
sde->cpu = cpu;
cpumask_clear(&msix->mask);
cpumask_set_cpu(cpu, &msix->mask);
dd_dev_dbg(dd, "IRQ vector: %u, type %s engine %u -> cpu: %d\n",
msix->msix.vector, irq_type_names[msix->type],
sde->this_idx, cpu);
irq_set_affinity_hint(msix->msix.vector, &msix->mask);
set = &entry->def_intr;
cpumask_set_cpu(cpu, &set->mask);
cpumask_set_cpu(cpu, &set->used);
for (i = 0; i < dd->num_msix_entries; i++) {
struct hfi1_msix_entry *other_msix;
other_msix = &dd->msix_entries[i];
if (other_msix->type != IRQ_SDMA || other_msix == msix)
continue;
if (cpumask_test_cpu(old_cpu, &other_msix->mask))
goto unlock;
}
cpumask_clear_cpu(old_cpu, &set->mask);
cpumask_clear_cpu(old_cpu, &set->used);
unlock:
mutex_unlock(&node_affinity.lock);
}
static void hfi1_irq_notifier_notify(struct irq_affinity_notify *notify,
const cpumask_t *mask)
{
int cpu = cpumask_first(mask);
struct hfi1_msix_entry *msix = container_of(notify,
struct hfi1_msix_entry,
notify);
hfi1_update_sdma_affinity(msix, cpu);
}
static void hfi1_irq_notifier_release(struct kref *ref)
{
}
static void hfi1_setup_sdma_notifier(struct hfi1_msix_entry *msix)
{
struct irq_affinity_notify *notify = &msix->notify;
notify->irq = msix->msix.vector;
notify->notify = hfi1_irq_notifier_notify;
notify->release = hfi1_irq_notifier_release;
if (irq_set_affinity_notifier(notify->irq, notify))
pr_err("Failed to register sdma irq affinity notifier for irq %d\n",
notify->irq);
}
static void hfi1_cleanup_sdma_notifier(struct hfi1_msix_entry *msix)
{
struct irq_affinity_notify *notify = &msix->notify;
if (irq_set_affinity_notifier(notify->irq, NULL))
pr_err("Failed to cleanup sdma irq affinity notifier for irq %d\n",
notify->irq);
}
static int get_irq_affinity(struct hfi1_devdata *dd,
struct hfi1_msix_entry *msix)
{
int ret;
cpumask_var_t diff;
struct hfi1_affinity_node *entry;
struct cpu_mask_set *set = NULL;
struct sdma_engine *sde = NULL;
struct hfi1_ctxtdata *rcd = NULL;
char extra[64];
int cpu = -1;
extra[0] = '\0';
cpumask_clear(&msix->mask);
ret = zalloc_cpumask_var(&diff, GFP_KERNEL);
if (!ret)
return -ENOMEM;
entry = node_affinity_lookup(dd->node);
switch (msix->type) {
case IRQ_SDMA:
sde = (struct sdma_engine *)msix->arg;
scnprintf(extra, 64, "engine %u", sde->this_idx);
set = &entry->def_intr;
break;
case IRQ_GENERAL:
cpu = cpumask_first(&entry->general_intr_mask);
break;
case IRQ_RCVCTXT:
rcd = (struct hfi1_ctxtdata *)msix->arg;
if (rcd->ctxt == HFI1_CTRL_CTXT)
cpu = cpumask_first(&entry->general_intr_mask);
else
set = &entry->rcv_intr;
scnprintf(extra, 64, "ctxt %u", rcd->ctxt);
break;
default:
dd_dev_err(dd, "Invalid IRQ type %d\n", msix->type);
return -EINVAL;
}
if (cpu == -1 && set) {
if (cpumask_equal(&set->mask, &set->used)) {
set->gen++;
cpumask_clear(&set->used);
}
cpumask_andnot(diff, &set->mask, &set->used);
cpu = cpumask_first(diff);
cpumask_set_cpu(cpu, &set->used);
}
cpumask_set_cpu(cpu, &msix->mask);
dd_dev_info(dd, "IRQ vector: %u, type %s %s -> cpu: %d\n",
msix->msix.vector, irq_type_names[msix->type],
extra, cpu);
irq_set_affinity_hint(msix->msix.vector, &msix->mask);
if (msix->type == IRQ_SDMA) {
sde->cpu = cpu;
hfi1_setup_sdma_notifier(msix);
}
free_cpumask_var(diff);
return 0;
}
int hfi1_get_irq_affinity(struct hfi1_devdata *dd, struct hfi1_msix_entry *msix)
{
int ret;
mutex_lock(&node_affinity.lock);
ret = get_irq_affinity(dd, msix);
mutex_unlock(&node_affinity.lock);
return ret;
}
void hfi1_put_irq_affinity(struct hfi1_devdata *dd,
struct hfi1_msix_entry *msix)
{
struct cpu_mask_set *set = NULL;
struct hfi1_ctxtdata *rcd;
struct hfi1_affinity_node *entry;
mutex_lock(&node_affinity.lock);
entry = node_affinity_lookup(dd->node);
switch (msix->type) {
case IRQ_SDMA:
set = &entry->def_intr;
hfi1_cleanup_sdma_notifier(msix);
break;
case IRQ_GENERAL:
break;
case IRQ_RCVCTXT:
rcd = (struct hfi1_ctxtdata *)msix->arg;
if (rcd->ctxt != HFI1_CTRL_CTXT)
set = &entry->rcv_intr;
break;
default:
mutex_unlock(&node_affinity.lock);
return;
}
if (set) {
cpumask_andnot(&set->used, &set->used, &msix->mask);
if (cpumask_empty(&set->used) && set->gen) {
set->gen--;
cpumask_copy(&set->used, &set->mask);
}
}
irq_set_affinity_hint(msix->msix.vector, NULL);
cpumask_clear(&msix->mask);
mutex_unlock(&node_affinity.lock);
}
static void find_hw_thread_mask(uint hw_thread_no, cpumask_var_t hw_thread_mask,
struct hfi1_affinity_node_list *affinity)
{
int possible, curr_cpu, i;
uint num_cores_per_socket = node_affinity.num_online_cpus /
affinity->num_core_siblings /
node_affinity.num_online_nodes;
cpumask_copy(hw_thread_mask, &affinity->proc.mask);
if (affinity->num_core_siblings > 0) {
possible = cpumask_weight(hw_thread_mask);
curr_cpu = cpumask_first(hw_thread_mask);
for (i = 0;
i < num_cores_per_socket * node_affinity.num_online_nodes;
i++)
curr_cpu = cpumask_next(curr_cpu, hw_thread_mask);
for (; i < possible; i++) {
cpumask_clear_cpu(curr_cpu, hw_thread_mask);
curr_cpu = cpumask_next(curr_cpu, hw_thread_mask);
}
cpumask_shift_left(hw_thread_mask, hw_thread_mask,
num_cores_per_socket *
node_affinity.num_online_nodes *
hw_thread_no);
}
}
int hfi1_get_proc_affinity(int node)
{
int cpu = -1, ret, i;
struct hfi1_affinity_node *entry;
cpumask_var_t diff, hw_thread_mask, available_mask, intrs_mask;
const struct cpumask *node_mask,
*proc_mask = tsk_cpus_allowed(current);
struct hfi1_affinity_node_list *affinity = &node_affinity;
struct cpu_mask_set *set = &affinity->proc;
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
ret = zalloc_cpumask_var(&hw_thread_mask, GFP_KERNEL);
if (!ret)
goto free_diff;
ret = zalloc_cpumask_var(&available_mask, GFP_KERNEL);
if (!ret)
goto free_hw_thread_mask;
ret = zalloc_cpumask_var(&intrs_mask, GFP_KERNEL);
if (!ret)
goto free_available_mask;
mutex_lock(&affinity->lock);
if (cpumask_equal(&set->mask, &set->used)) {
set->gen++;
cpumask_clear(&set->used);
}
entry = node_affinity_lookup(node);
if (entry) {
cpumask_copy(intrs_mask, (entry->def_intr.gen ?
&entry->def_intr.mask :
&entry->def_intr.used));
cpumask_or(intrs_mask, intrs_mask, (entry->rcv_intr.gen ?
&entry->rcv_intr.mask :
&entry->rcv_intr.used));
cpumask_or(intrs_mask, intrs_mask, &entry->general_intr_mask);
}
hfi1_cdbg(PROC, "CPUs used by interrupts: %*pbl",
cpumask_pr_args(intrs_mask));
cpumask_copy(hw_thread_mask, &set->mask);
if (affinity->num_core_siblings > 0) {
for (i = 0; i < affinity->num_core_siblings; i++) {
find_hw_thread_mask(i, hw_thread_mask, affinity);
cpumask_andnot(diff, hw_thread_mask, &set->used);
if (!cpumask_empty(diff))
break;
}
}
hfi1_cdbg(PROC, "Same available HW thread on all physical CPUs: %*pbl",
cpumask_pr_args(hw_thread_mask));
node_mask = cpumask_of_node(node);
hfi1_cdbg(PROC, "Device on NUMA %u, CPUs %*pbl", node,
cpumask_pr_args(node_mask));
cpumask_and(available_mask, hw_thread_mask, node_mask);
cpumask_andnot(available_mask, available_mask, &set->used);
hfi1_cdbg(PROC, "Available CPUs on NUMA %u: %*pbl", node,
cpumask_pr_args(available_mask));
cpumask_andnot(diff, available_mask, intrs_mask);
if (!cpumask_empty(diff))
cpumask_copy(available_mask, diff);
if (cpumask_empty(available_mask)) {
cpumask_andnot(available_mask, hw_thread_mask, &set->used);
cpumask_andnot(available_mask, available_mask, node_mask);
hfi1_cdbg(PROC,
"Preferred NUMA node cores are taken, cores available in other NUMA nodes: %*pbl",
cpumask_pr_args(available_mask));
cpumask_andnot(diff, available_mask, intrs_mask);
if (!cpumask_empty(diff))
cpumask_copy(available_mask, diff);
}
hfi1_cdbg(PROC, "Possible CPUs for process: %*pbl",
cpumask_pr_args(available_mask));
cpu = cpumask_first(available_mask);
if (cpu >= nr_cpu_ids)
cpu = -1;
else
cpumask_set_cpu(cpu, &set->used);
mutex_unlock(&affinity->lock);
hfi1_cdbg(PROC, "Process assigned to CPU %d", cpu);
free_cpumask_var(intrs_mask);
free_available_mask:
free_cpumask_var(available_mask);
free_hw_thread_mask:
free_cpumask_var(hw_thread_mask);
free_diff:
free_cpumask_var(diff);
done:
return cpu;
}
void hfi1_put_proc_affinity(int cpu)
{
struct hfi1_affinity_node_list *affinity = &node_affinity;
struct cpu_mask_set *set = &affinity->proc;
if (cpu < 0)
return;
mutex_lock(&affinity->lock);
cpumask_clear_cpu(cpu, &set->used);
hfi1_cdbg(PROC, "Returning CPU %d for future process assignment", cpu);
if (cpumask_empty(&set->used) && set->gen) {
set->gen--;
cpumask_copy(&set->used, &set->mask);
}
mutex_unlock(&affinity->lock);
}
