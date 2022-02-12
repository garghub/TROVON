static bool __maybe_unused
is_affected_midr_range(const struct arm64_cpu_capabilities *entry, int scope)
{
WARN_ON(scope != SCOPE_LOCAL_CPU || preemptible());
return MIDR_IS_CPU_MODEL_RANGE(read_cpuid_id(), entry->midr_model,
entry->midr_range_min,
entry->midr_range_max);
}
void verify_local_cpu_errata(void)
{
const struct arm64_cpu_capabilities *caps = arm64_errata;
for (; caps->matches; caps++)
if (!cpus_have_cap(caps->capability) &&
caps->matches(caps, SCOPE_LOCAL_CPU)) {
pr_crit("CPU%d: Requires work around for %s, not detected"
" at boot time\n",
smp_processor_id(),
caps->desc ? : "an erratum");
cpu_die_early();
}
}
void check_local_cpu_errata(void)
{
update_cpu_capabilities(arm64_errata, "enabling workaround for");
}
void __init enable_errata_workarounds(void)
{
enable_cpu_capabilities(arm64_errata);
}
