static void noop_init_apic_ldr(void) { }
static void noop_send_IPI_mask(const struct cpumask *cpumask, int vector) { }
static void noop_send_IPI_mask_allbutself(const struct cpumask *cpumask, int vector) { }
static void noop_send_IPI_allbutself(int vector) { }
static void noop_send_IPI_all(int vector) { }
static void noop_send_IPI_self(int vector) { }
static void noop_apic_wait_icr_idle(void) { }
static void noop_apic_icr_write(u32 low, u32 id) { }
static int noop_wakeup_secondary_cpu(int apicid, unsigned long start_eip)
{
return -1;
}
static u32 noop_safe_apic_wait_icr_idle(void)
{
return 0;
}
static u64 noop_apic_icr_read(void)
{
return 0;
}
static int noop_phys_pkg_id(int cpuid_apic, int index_msb)
{
return 0;
}
static unsigned int noop_get_apic_id(unsigned long x)
{
return 0;
}
static int noop_probe(void)
{
return 0;
}
static int noop_apic_id_registered(void)
{
return physid_isset(0, phys_cpu_present_map);
}
static const struct cpumask *noop_target_cpus(void)
{
return cpumask_of(0);
}
static unsigned long noop_check_apicid_used(physid_mask_t *map, int apicid)
{
return physid_isset(apicid, *map);
}
static unsigned long noop_check_apicid_present(int bit)
{
return physid_isset(bit, phys_cpu_present_map);
}
static void noop_vector_allocation_domain(int cpu, struct cpumask *retmask,
const struct cpumask *mask)
{
if (cpu != 0)
pr_warning("APIC: Vector allocated for non-BSP cpu\n");
cpumask_copy(retmask, cpumask_of(cpu));
}
static u32 noop_apic_read(u32 reg)
{
WARN_ON_ONCE((cpu_has_apic && !disable_apic));
return 0;
}
static void noop_apic_write(u32 reg, u32 v)
{
WARN_ON_ONCE(cpu_has_apic && !disable_apic);
}
