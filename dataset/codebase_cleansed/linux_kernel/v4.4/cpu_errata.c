static bool __maybe_unused
is_affected_midr_range(const struct arm64_cpu_capabilities *entry)
{
u32 midr = read_cpuid_id();
if ((midr & CPU_MODEL_MASK) != entry->midr_model)
return false;
midr &= MIDR_REVISION_MASK | MIDR_VARIANT_MASK;
return (midr >= entry->midr_range_min && midr <= entry->midr_range_max);
}
void check_local_cpu_errata(void)
{
update_cpu_capabilities(arm64_errata, "enabling workaround for");
}
