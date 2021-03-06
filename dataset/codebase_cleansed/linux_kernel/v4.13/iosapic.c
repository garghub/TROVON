static inline void
iosapic_write(struct iosapic *iosapic, unsigned int reg, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&iosapic->lock, flags);
__iosapic_write(iosapic->addr, reg, val);
spin_unlock_irqrestore(&iosapic->lock, flags);
}
static inline int
find_iosapic (unsigned int gsi)
{
int i;
for (i = 0; i < NR_IOSAPICS; i++) {
if ((unsigned) (gsi - iosapic_lists[i].gsi_base) <
iosapic_lists[i].num_rte)
return i;
}
return -1;
}
static inline int __gsi_to_irq(unsigned int gsi)
{
int irq;
struct iosapic_intr_info *info;
struct iosapic_rte_info *rte;
for (irq = 0; irq < NR_IRQS; irq++) {
info = &iosapic_intr_info[irq];
list_for_each_entry(rte, &info->rtes, rte_list)
if (rte->iosapic->gsi_base + rte->rte_index == gsi)
return irq;
}
return -1;
}
int
gsi_to_irq (unsigned int gsi)
{
unsigned long flags;
int irq;
spin_lock_irqsave(&iosapic_lock, flags);
irq = __gsi_to_irq(gsi);
spin_unlock_irqrestore(&iosapic_lock, flags);
return irq;
}
static struct iosapic_rte_info *find_rte(unsigned int irq, unsigned int gsi)
{
struct iosapic_rte_info *rte;
list_for_each_entry(rte, &iosapic_intr_info[irq].rtes, rte_list)
if (rte->iosapic->gsi_base + rte->rte_index == gsi)
return rte;
return NULL;
}
static void
set_rte (unsigned int gsi, unsigned int irq, unsigned int dest, int mask)
{
unsigned long pol, trigger, dmode;
u32 low32, high32;
int rte_index;
char redir;
struct iosapic_rte_info *rte;
ia64_vector vector = irq_to_vector(irq);
DBG(KERN_DEBUG"IOSAPIC: routing vector %d to 0x%x\n", vector, dest);
rte = find_rte(irq, gsi);
if (!rte)
return;
rte_index = rte->rte_index;
pol = iosapic_intr_info[irq].polarity;
trigger = iosapic_intr_info[irq].trigger;
dmode = iosapic_intr_info[irq].dmode;
redir = (dmode == IOSAPIC_LOWEST_PRIORITY) ? 1 : 0;
#ifdef CONFIG_SMP
set_irq_affinity_info(irq, (int)(dest & 0xffff), redir);
#endif
low32 = ((pol << IOSAPIC_POLARITY_SHIFT) |
(trigger << IOSAPIC_TRIGGER_SHIFT) |
(dmode << IOSAPIC_DELIVERY_SHIFT) |
((mask ? 1 : 0) << IOSAPIC_MASK_SHIFT) |
vector);
high32 = (dest << IOSAPIC_DEST_SHIFT);
iosapic_write(rte->iosapic, IOSAPIC_RTE_HIGH(rte_index), high32);
iosapic_write(rte->iosapic, IOSAPIC_RTE_LOW(rte_index), low32);
iosapic_intr_info[irq].low32 = low32;
iosapic_intr_info[irq].dest = dest;
}
static void
iosapic_nop (struct irq_data *data)
{
}
void
kexec_disable_iosapic(void)
{
struct iosapic_intr_info *info;
struct iosapic_rte_info *rte;
ia64_vector vec;
int irq;
for (irq = 0; irq < NR_IRQS; irq++) {
info = &iosapic_intr_info[irq];
vec = irq_to_vector(irq);
list_for_each_entry(rte, &info->rtes,
rte_list) {
iosapic_write(rte->iosapic,
IOSAPIC_RTE_LOW(rte->rte_index),
IOSAPIC_MASK|vec);
iosapic_eoi(rte->iosapic->addr, vec);
}
}
}
static void
mask_irq (struct irq_data *data)
{
unsigned int irq = data->irq;
u32 low32;
int rte_index;
struct iosapic_rte_info *rte;
if (!iosapic_intr_info[irq].count)
return;
low32 = iosapic_intr_info[irq].low32 |= IOSAPIC_MASK;
list_for_each_entry(rte, &iosapic_intr_info[irq].rtes, rte_list) {
rte_index = rte->rte_index;
iosapic_write(rte->iosapic, IOSAPIC_RTE_LOW(rte_index), low32);
}
}
static void
unmask_irq (struct irq_data *data)
{
unsigned int irq = data->irq;
u32 low32;
int rte_index;
struct iosapic_rte_info *rte;
if (!iosapic_intr_info[irq].count)
return;
low32 = iosapic_intr_info[irq].low32 &= ~IOSAPIC_MASK;
list_for_each_entry(rte, &iosapic_intr_info[irq].rtes, rte_list) {
rte_index = rte->rte_index;
iosapic_write(rte->iosapic, IOSAPIC_RTE_LOW(rte_index), low32);
}
}
static int
iosapic_set_affinity(struct irq_data *data, const struct cpumask *mask,
bool force)
{
#ifdef CONFIG_SMP
unsigned int irq = data->irq;
u32 high32, low32;
int cpu, dest, rte_index;
int redir = (irq & IA64_IRQ_REDIRECTED) ? 1 : 0;
struct iosapic_rte_info *rte;
struct iosapic *iosapic;
irq &= (~IA64_IRQ_REDIRECTED);
cpu = cpumask_first_and(cpu_online_mask, mask);
if (cpu >= nr_cpu_ids)
return -1;
if (irq_prepare_move(irq, cpu))
return -1;
dest = cpu_physical_id(cpu);
if (!iosapic_intr_info[irq].count)
return -1;
set_irq_affinity_info(irq, dest, redir);
high32 = dest << IOSAPIC_DEST_SHIFT;
low32 = iosapic_intr_info[irq].low32 & ~(7 << IOSAPIC_DELIVERY_SHIFT);
if (redir)
low32 |= (IOSAPIC_LOWEST_PRIORITY << IOSAPIC_DELIVERY_SHIFT);
else
low32 |= (IOSAPIC_FIXED << IOSAPIC_DELIVERY_SHIFT);
low32 &= IOSAPIC_VECTOR_MASK;
low32 |= irq_to_vector(irq);
iosapic_intr_info[irq].low32 = low32;
iosapic_intr_info[irq].dest = dest;
list_for_each_entry(rte, &iosapic_intr_info[irq].rtes, rte_list) {
iosapic = rte->iosapic;
rte_index = rte->rte_index;
iosapic_write(iosapic, IOSAPIC_RTE_HIGH(rte_index), high32);
iosapic_write(iosapic, IOSAPIC_RTE_LOW(rte_index), low32);
}
#endif
return 0;
}
static unsigned int
iosapic_startup_level_irq (struct irq_data *data)
{
unmask_irq(data);
return 0;
}
static void
iosapic_unmask_level_irq (struct irq_data *data)
{
unsigned int irq = data->irq;
ia64_vector vec = irq_to_vector(irq);
struct iosapic_rte_info *rte;
int do_unmask_irq = 0;
irq_complete_move(irq);
if (unlikely(irqd_is_setaffinity_pending(data))) {
do_unmask_irq = 1;
mask_irq(data);
} else
unmask_irq(data);
list_for_each_entry(rte, &iosapic_intr_info[irq].rtes, rte_list)
iosapic_eoi(rte->iosapic->addr, vec);
if (unlikely(do_unmask_irq)) {
irq_move_masked_irq(data);
unmask_irq(data);
}
}
static unsigned int
iosapic_startup_edge_irq (struct irq_data *data)
{
unmask_irq(data);
return 0;
}
static void
iosapic_ack_edge_irq (struct irq_data *data)
{
irq_complete_move(data->irq);
irq_move_irq(data);
}
static unsigned int
iosapic_version (char __iomem *addr)
{
return __iosapic_read(addr, IOSAPIC_VERSION);
}
static int iosapic_find_sharable_irq(unsigned long trigger, unsigned long pol)
{
int i, irq = -ENOSPC, min_count = -1;
struct iosapic_intr_info *info;
if (trigger == IOSAPIC_EDGE)
return -EINVAL;
for (i = 0; i < NR_IRQS; i++) {
info = &iosapic_intr_info[i];
if (info->trigger == trigger && info->polarity == pol &&
(info->dmode == IOSAPIC_FIXED ||
info->dmode == IOSAPIC_LOWEST_PRIORITY) &&
can_request_irq(i, IRQF_SHARED)) {
if (min_count == -1 || info->count < min_count) {
irq = i;
min_count = info->count;
}
}
}
return irq;
}
static void __init
iosapic_reassign_vector (int irq)
{
int new_irq;
if (iosapic_intr_info[irq].count) {
new_irq = create_irq();
if (new_irq < 0)
panic("%s: out of interrupt vectors!\n", __func__);
printk(KERN_INFO "Reassigning vector %d to %d\n",
irq_to_vector(irq), irq_to_vector(new_irq));
memcpy(&iosapic_intr_info[new_irq], &iosapic_intr_info[irq],
sizeof(struct iosapic_intr_info));
INIT_LIST_HEAD(&iosapic_intr_info[new_irq].rtes);
list_move(iosapic_intr_info[irq].rtes.next,
&iosapic_intr_info[new_irq].rtes);
memset(&iosapic_intr_info[irq], 0,
sizeof(struct iosapic_intr_info));
iosapic_intr_info[irq].low32 = IOSAPIC_MASK;
INIT_LIST_HEAD(&iosapic_intr_info[irq].rtes);
}
}
static inline int irq_is_shared (int irq)
{
return (iosapic_intr_info[irq].count > 1);
}
struct irq_chip*
ia64_native_iosapic_get_irq_chip(unsigned long trigger)
{
if (trigger == IOSAPIC_EDGE)
return &irq_type_iosapic_edge;
else
return &irq_type_iosapic_level;
}
static int
register_intr (unsigned int gsi, int irq, unsigned char delivery,
unsigned long polarity, unsigned long trigger)
{
struct irq_chip *chip, *irq_type;
int index;
struct iosapic_rte_info *rte;
index = find_iosapic(gsi);
if (index < 0) {
printk(KERN_WARNING "%s: No IOSAPIC for GSI %u\n",
__func__, gsi);
return -ENODEV;
}
rte = find_rte(irq, gsi);
if (!rte) {
rte = kzalloc(sizeof (*rte), GFP_ATOMIC);
if (!rte) {
printk(KERN_WARNING "%s: cannot allocate memory\n",
__func__);
return -ENOMEM;
}
rte->iosapic = &iosapic_lists[index];
rte->rte_index = gsi - rte->iosapic->gsi_base;
rte->refcnt++;
list_add_tail(&rte->rte_list, &iosapic_intr_info[irq].rtes);
iosapic_intr_info[irq].count++;
iosapic_lists[index].rtes_inuse++;
}
else if (rte->refcnt == NO_REF_RTE) {
struct iosapic_intr_info *info = &iosapic_intr_info[irq];
if (info->count > 0 &&
(info->trigger != trigger || info->polarity != polarity)){
printk (KERN_WARNING
"%s: cannot override the interrupt\n",
__func__);
return -EINVAL;
}
rte->refcnt++;
iosapic_intr_info[irq].count++;
iosapic_lists[index].rtes_inuse++;
}
iosapic_intr_info[irq].polarity = polarity;
iosapic_intr_info[irq].dmode = delivery;
iosapic_intr_info[irq].trigger = trigger;
irq_type = iosapic_get_irq_chip(trigger);
chip = irq_get_chip(irq);
if (irq_type != NULL && chip != irq_type) {
if (chip != &no_irq_chip)
printk(KERN_WARNING
"%s: changing vector %d from %s to %s\n",
__func__, irq_to_vector(irq),
chip->name, irq_type->name);
chip = irq_type;
}
irq_set_chip_handler_name_locked(irq_get_irq_data(irq), chip,
trigger == IOSAPIC_EDGE ? handle_edge_irq : handle_level_irq,
NULL);
return 0;
}
static unsigned int
get_target_cpu (unsigned int gsi, int irq)
{
#ifdef CONFIG_SMP
static int cpu = -1;
extern int cpe_vector;
cpumask_t domain = irq_to_domain(irq);
if (iosapic_intr_info[irq].count)
return iosapic_intr_info[irq].dest;
if (smp_int_redirect & SMP_IRQ_REDIRECTION)
return cpu_physical_id(smp_processor_id());
if (!cpu_online(smp_processor_id()))
return cpu_physical_id(smp_processor_id());
#ifdef CONFIG_ACPI
if (cpe_vector > 0 && irq_to_vector(irq) == IA64_CPEP_VECTOR)
return get_cpei_target_cpu();
#endif
#ifdef CONFIG_NUMA
{
int num_cpus, cpu_index, iosapic_index, numa_cpu, i = 0;
const struct cpumask *cpu_mask;
iosapic_index = find_iosapic(gsi);
if (iosapic_index < 0 ||
iosapic_lists[iosapic_index].node == MAX_NUMNODES)
goto skip_numa_setup;
cpu_mask = cpumask_of_node(iosapic_lists[iosapic_index].node);
num_cpus = 0;
for_each_cpu_and(numa_cpu, cpu_mask, &domain) {
if (cpu_online(numa_cpu))
num_cpus++;
}
if (!num_cpus)
goto skip_numa_setup;
cpu_index = irq % num_cpus;
for_each_cpu_and(numa_cpu, cpu_mask, &domain)
if (cpu_online(numa_cpu) && i++ >= cpu_index)
break;
if (numa_cpu < nr_cpu_ids)
return cpu_physical_id(numa_cpu);
}
skip_numa_setup:
#endif
do {
if (++cpu >= nr_cpu_ids)
cpu = 0;
} while (!cpu_online(cpu) || !cpumask_test_cpu(cpu, &domain));
return cpu_physical_id(cpu);
#else
return cpu_physical_id(smp_processor_id());
#endif
}
static inline unsigned char choose_dmode(void)
{
#ifdef CONFIG_SMP
if (smp_int_redirect & SMP_IRQ_REDIRECTION)
return IOSAPIC_LOWEST_PRIORITY;
#endif
return IOSAPIC_FIXED;
}
int
iosapic_register_intr (unsigned int gsi,
unsigned long polarity, unsigned long trigger)
{
int irq, mask = 1, err;
unsigned int dest;
unsigned long flags;
struct iosapic_rte_info *rte;
u32 low32;
unsigned char dmode;
struct irq_desc *desc;
spin_lock_irqsave(&iosapic_lock, flags);
irq = __gsi_to_irq(gsi);
if (irq > 0) {
rte = find_rte(irq, gsi);
if(iosapic_intr_info[irq].count == 0) {
assign_irq_vector(irq);
irq_init_desc(irq);
} else if (rte->refcnt != NO_REF_RTE) {
rte->refcnt++;
goto unlock_iosapic_lock;
}
} else
irq = create_irq();
if (irq < 0) {
irq = iosapic_find_sharable_irq(trigger, polarity);
if (irq < 0)
goto unlock_iosapic_lock;
}
desc = irq_to_desc(irq);
raw_spin_lock(&desc->lock);
dest = get_target_cpu(gsi, irq);
dmode = choose_dmode();
err = register_intr(gsi, irq, dmode, polarity, trigger);
if (err < 0) {
raw_spin_unlock(&desc->lock);
irq = err;
goto unlock_iosapic_lock;
}
low32 = iosapic_intr_info[irq].low32;
if (irq_is_shared(irq) && !(low32 & IOSAPIC_MASK))
mask = 0;
set_rte(gsi, irq, dest, mask);
printk(KERN_INFO "GSI %u (%s, %s) -> CPU %d (0x%04x) vector %d\n",
gsi, (trigger == IOSAPIC_EDGE ? "edge" : "level"),
(polarity == IOSAPIC_POL_HIGH ? "high" : "low"),
cpu_logical_id(dest), dest, irq_to_vector(irq));
raw_spin_unlock(&desc->lock);
unlock_iosapic_lock:
spin_unlock_irqrestore(&iosapic_lock, flags);
return irq;
}
void
iosapic_unregister_intr (unsigned int gsi)
{
unsigned long flags;
int irq, index;
u32 low32;
unsigned long trigger, polarity;
unsigned int dest;
struct iosapic_rte_info *rte;
irq = gsi_to_irq(gsi);
if (irq < 0) {
printk(KERN_ERR "iosapic_unregister_intr(%u) unbalanced\n",
gsi);
WARN_ON(1);
return;
}
spin_lock_irqsave(&iosapic_lock, flags);
if ((rte = find_rte(irq, gsi)) == NULL) {
printk(KERN_ERR "iosapic_unregister_intr(%u) unbalanced\n",
gsi);
WARN_ON(1);
goto out;
}
if (--rte->refcnt > 0)
goto out;
rte->refcnt = NO_REF_RTE;
low32 = iosapic_intr_info[irq].low32 | IOSAPIC_MASK;
iosapic_write(rte->iosapic, IOSAPIC_RTE_LOW(rte->rte_index), low32);
iosapic_intr_info[irq].count--;
index = find_iosapic(gsi);
iosapic_lists[index].rtes_inuse--;
WARN_ON(iosapic_lists[index].rtes_inuse < 0);
trigger = iosapic_intr_info[irq].trigger;
polarity = iosapic_intr_info[irq].polarity;
dest = iosapic_intr_info[irq].dest;
printk(KERN_INFO
"GSI %u (%s, %s) -> CPU %d (0x%04x) vector %d unregistered\n",
gsi, (trigger == IOSAPIC_EDGE ? "edge" : "level"),
(polarity == IOSAPIC_POL_HIGH ? "high" : "low"),
cpu_logical_id(dest), dest, irq_to_vector(irq));
if (iosapic_intr_info[irq].count == 0) {
#ifdef CONFIG_SMP
cpumask_setall(irq_get_affinity_mask(irq));
#endif
iosapic_intr_info[irq].dest = 0;
iosapic_intr_info[irq].dmode = 0;
iosapic_intr_info[irq].polarity = 0;
iosapic_intr_info[irq].trigger = 0;
iosapic_intr_info[irq].low32 |= IOSAPIC_MASK;
destroy_and_reserve_irq(irq);
}
out:
spin_unlock_irqrestore(&iosapic_lock, flags);
}
int __init
iosapic_register_platform_intr (u32 int_type, unsigned int gsi,
int iosapic_vector, u16 eid, u16 id,
unsigned long polarity, unsigned long trigger)
{
static const char * const name[] = {"unknown", "PMI", "INIT", "CPEI"};
unsigned char delivery;
int irq, vector, mask = 0;
unsigned int dest = ((id << 8) | eid) & 0xffff;
switch (int_type) {
case ACPI_INTERRUPT_PMI:
irq = vector = iosapic_vector;
bind_irq_vector(irq, vector, CPU_MASK_ALL);
iosapic_reassign_vector(irq);
delivery = IOSAPIC_PMI;
break;
case ACPI_INTERRUPT_INIT:
irq = create_irq();
if (irq < 0)
panic("%s: out of interrupt vectors!\n", __func__);
vector = irq_to_vector(irq);
delivery = IOSAPIC_INIT;
break;
case ACPI_INTERRUPT_CPEI:
irq = vector = IA64_CPE_VECTOR;
BUG_ON(bind_irq_vector(irq, vector, CPU_MASK_ALL));
delivery = IOSAPIC_FIXED;
mask = 1;
break;
default:
printk(KERN_ERR "%s: invalid int type 0x%x\n", __func__,
int_type);
return -1;
}
register_intr(gsi, irq, delivery, polarity, trigger);
printk(KERN_INFO
"PLATFORM int %s (0x%x): GSI %u (%s, %s) -> CPU %d (0x%04x)"
" vector %d\n",
int_type < ARRAY_SIZE(name) ? name[int_type] : "unknown",
int_type, gsi, (trigger == IOSAPIC_EDGE ? "edge" : "level"),
(polarity == IOSAPIC_POL_HIGH ? "high" : "low"),
cpu_logical_id(dest), dest, vector);
set_rte(gsi, irq, dest, mask);
return vector;
}
void iosapic_override_isa_irq(unsigned int isa_irq, unsigned int gsi,
unsigned long polarity, unsigned long trigger)
{
int vector, irq;
unsigned int dest = cpu_physical_id(smp_processor_id());
unsigned char dmode;
irq = vector = isa_irq_to_vector(isa_irq);
BUG_ON(bind_irq_vector(irq, vector, CPU_MASK_ALL));
dmode = choose_dmode();
register_intr(gsi, irq, dmode, polarity, trigger);
DBG("ISA: IRQ %u -> GSI %u (%s,%s) -> CPU %d (0x%04x) vector %d\n",
isa_irq, gsi, trigger == IOSAPIC_EDGE ? "edge" : "level",
polarity == IOSAPIC_POL_HIGH ? "high" : "low",
cpu_logical_id(dest), dest, vector);
set_rte(gsi, irq, dest, 1);
}
void __init
ia64_native_iosapic_pcat_compat_init(void)
{
if (pcat_compat) {
printk(KERN_INFO
"%s: Disabling PC-AT compatible 8259 interrupts\n",
__func__);
outb(0xff, 0xA1);
outb(0xff, 0x21);
}
}
void __init
iosapic_system_init (int system_pcat_compat)
{
int irq;
for (irq = 0; irq < NR_IRQS; ++irq) {
iosapic_intr_info[irq].low32 = IOSAPIC_MASK;
INIT_LIST_HEAD(&iosapic_intr_info[irq].rtes);
iosapic_intr_info[irq].count = 0;
}
pcat_compat = system_pcat_compat;
if (pcat_compat)
iosapic_pcat_compat_init();
}
static inline int
iosapic_alloc (void)
{
int index;
for (index = 0; index < NR_IOSAPICS; index++)
if (!iosapic_lists[index].addr)
return index;
printk(KERN_WARNING "%s: failed to allocate iosapic\n", __func__);
return -1;
}
static inline void
iosapic_free (int index)
{
memset(&iosapic_lists[index], 0, sizeof(iosapic_lists[0]));
}
static inline int
iosapic_check_gsi_range (unsigned int gsi_base, unsigned int ver)
{
int index;
unsigned int gsi_end, base, end;
gsi_end = gsi_base + ((ver >> 16) & 0xff);
for (index = 0; index < NR_IOSAPICS; index++) {
if (!iosapic_lists[index].addr)
continue;
base = iosapic_lists[index].gsi_base;
end = base + iosapic_lists[index].num_rte - 1;
if (gsi_end < base || end < gsi_base)
continue;
return -EBUSY;
}
return 0;
}
static int
iosapic_delete_rte(unsigned int irq, unsigned int gsi)
{
struct iosapic_rte_info *rte, *temp;
list_for_each_entry_safe(rte, temp, &iosapic_intr_info[irq].rtes,
rte_list) {
if (rte->iosapic->gsi_base + rte->rte_index == gsi) {
if (rte->refcnt)
return -EBUSY;
list_del(&rte->rte_list);
kfree(rte);
return 0;
}
}
return -EINVAL;
}
int iosapic_init(unsigned long phys_addr, unsigned int gsi_base)
{
int num_rte, err, index;
unsigned int isa_irq, ver;
char __iomem *addr;
unsigned long flags;
spin_lock_irqsave(&iosapic_lock, flags);
index = find_iosapic(gsi_base);
if (index >= 0) {
spin_unlock_irqrestore(&iosapic_lock, flags);
return -EBUSY;
}
addr = ioremap(phys_addr, 0);
if (addr == NULL) {
spin_unlock_irqrestore(&iosapic_lock, flags);
return -ENOMEM;
}
ver = iosapic_version(addr);
if ((err = iosapic_check_gsi_range(gsi_base, ver))) {
iounmap(addr);
spin_unlock_irqrestore(&iosapic_lock, flags);
return err;
}
num_rte = ((ver >> 16) & 0xff) + 1;
index = iosapic_alloc();
iosapic_lists[index].addr = addr;
iosapic_lists[index].gsi_base = gsi_base;
iosapic_lists[index].num_rte = num_rte;
#ifdef CONFIG_NUMA
iosapic_lists[index].node = MAX_NUMNODES;
#endif
spin_lock_init(&iosapic_lists[index].lock);
spin_unlock_irqrestore(&iosapic_lock, flags);
if ((gsi_base == 0) && pcat_compat) {
for (isa_irq = 0; isa_irq < 16; ++isa_irq)
iosapic_override_isa_irq(isa_irq, isa_irq,
IOSAPIC_POL_HIGH,
IOSAPIC_EDGE);
}
return 0;
}
int iosapic_remove(unsigned int gsi_base)
{
int i, irq, index, err = 0;
unsigned long flags;
spin_lock_irqsave(&iosapic_lock, flags);
index = find_iosapic(gsi_base);
if (index < 0) {
printk(KERN_WARNING "%s: No IOSAPIC for GSI base %u\n",
__func__, gsi_base);
goto out;
}
if (iosapic_lists[index].rtes_inuse) {
err = -EBUSY;
printk(KERN_WARNING "%s: IOSAPIC for GSI base %u is busy\n",
__func__, gsi_base);
goto out;
}
for (i = gsi_base; i < gsi_base + iosapic_lists[index].num_rte; i++) {
irq = __gsi_to_irq(i);
if (irq < 0)
continue;
err = iosapic_delete_rte(irq, i);
if (err)
goto out;
}
iounmap(iosapic_lists[index].addr);
iosapic_free(index);
out:
spin_unlock_irqrestore(&iosapic_lock, flags);
return err;
}
void map_iosapic_to_node(unsigned int gsi_base, int node)
{
int index;
index = find_iosapic(gsi_base);
if (index < 0) {
printk(KERN_WARNING "%s: No IOSAPIC for GSI %u\n",
__func__, gsi_base);
return;
}
iosapic_lists[index].node = node;
return;
}
