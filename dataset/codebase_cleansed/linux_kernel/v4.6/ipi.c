void __default_send_IPI_shortcut(unsigned int shortcut, int vector, unsigned int dest)
{
unsigned int cfg;
__xapic_wait_icr_idle();
cfg = __prepare_ICR(shortcut, vector, dest);
native_apic_mem_write(APIC_ICR, cfg);
}
void __default_send_IPI_dest_field(unsigned int mask, int vector, unsigned int dest)
{
unsigned long cfg;
if (unlikely(vector == NMI_VECTOR))
safe_apic_wait_icr_idle();
else
__xapic_wait_icr_idle();
cfg = __prepare_ICR2(mask);
native_apic_mem_write(APIC_ICR2, cfg);
cfg = __prepare_ICR(0, vector, dest);
native_apic_mem_write(APIC_ICR, cfg);
}
void default_send_IPI_single_phys(int cpu, int vector)
{
unsigned long flags;
local_irq_save(flags);
__default_send_IPI_dest_field(per_cpu(x86_cpu_to_apicid, cpu),
vector, APIC_DEST_PHYSICAL);
local_irq_restore(flags);
}
void default_send_IPI_mask_sequence_phys(const struct cpumask *mask, int vector)
{
unsigned long query_cpu;
unsigned long flags;
local_irq_save(flags);
for_each_cpu(query_cpu, mask) {
__default_send_IPI_dest_field(per_cpu(x86_cpu_to_apicid,
query_cpu), vector, APIC_DEST_PHYSICAL);
}
local_irq_restore(flags);
}
void default_send_IPI_mask_allbutself_phys(const struct cpumask *mask,
int vector)
{
unsigned int this_cpu = smp_processor_id();
unsigned int query_cpu;
unsigned long flags;
local_irq_save(flags);
for_each_cpu(query_cpu, mask) {
if (query_cpu == this_cpu)
continue;
__default_send_IPI_dest_field(per_cpu(x86_cpu_to_apicid,
query_cpu), vector, APIC_DEST_PHYSICAL);
}
local_irq_restore(flags);
}
void default_send_IPI_single(int cpu, int vector)
{
apic->send_IPI_mask(cpumask_of(cpu), vector);
}
void default_send_IPI_mask_sequence_logical(const struct cpumask *mask,
int vector)
{
unsigned long flags;
unsigned int query_cpu;
local_irq_save(flags);
for_each_cpu(query_cpu, mask)
__default_send_IPI_dest_field(
early_per_cpu(x86_cpu_to_logical_apicid, query_cpu),
vector, apic->dest_logical);
local_irq_restore(flags);
}
void default_send_IPI_mask_allbutself_logical(const struct cpumask *mask,
int vector)
{
unsigned long flags;
unsigned int query_cpu;
unsigned int this_cpu = smp_processor_id();
local_irq_save(flags);
for_each_cpu(query_cpu, mask) {
if (query_cpu == this_cpu)
continue;
__default_send_IPI_dest_field(
early_per_cpu(x86_cpu_to_logical_apicid, query_cpu),
vector, apic->dest_logical);
}
local_irq_restore(flags);
}
void default_send_IPI_mask_logical(const struct cpumask *cpumask, int vector)
{
unsigned long mask = cpumask_bits(cpumask)[0];
unsigned long flags;
if (!mask)
return;
local_irq_save(flags);
WARN_ON(mask & ~cpumask_bits(cpu_online_mask)[0]);
__default_send_IPI_dest_field(mask, vector, apic->dest_logical);
local_irq_restore(flags);
}
void default_send_IPI_allbutself(int vector)
{
if (!(num_online_cpus() > 1))
return;
__default_local_send_IPI_allbutself(vector);
}
void default_send_IPI_all(int vector)
{
__default_local_send_IPI_all(vector);
}
void default_send_IPI_self(int vector)
{
__default_send_IPI_shortcut(APIC_DEST_SELF, vector, apic->dest_logical);
}
static int convert_apicid_to_cpu(int apic_id)
{
int i;
for_each_possible_cpu(i) {
if (per_cpu(x86_cpu_to_apicid, i) == apic_id)
return i;
}
return -1;
}
int safe_smp_processor_id(void)
{
int apicid, cpuid;
if (!cpu_has_apic)
return 0;
apicid = hard_smp_processor_id();
if (apicid == BAD_APICID)
return 0;
cpuid = convert_apicid_to_cpu(apicid);
return cpuid >= 0 ? cpuid : 0;
}
