static bool __maybe_unused
is_affected_midr_range(struct arm64_cpu_capabilities *entry)
{
u32 midr = read_cpuid_id();
if ((midr & CPU_MODEL_MASK) != entry->midr_model)
return false;
midr &= MIDR_REVISION_MASK | MIDR_VARIANT_MASK;
return (midr >= entry->midr_range_min && midr <= entry->midr_range_max);
}
void check_local_cpu_errata(void)
{
struct arm64_cpu_capabilities *cpus = arm64_errata;
int i;
for (i = 0; cpus[i].desc; i++) {
if (!cpus[i].is_affected(&cpus[i]))
continue;
if (!cpus_have_cap(cpus[i].capability))
pr_info("enabling workaround for %s\n", cpus[i].desc);
cpus_set_cap(cpus[i].capability);
}
}
