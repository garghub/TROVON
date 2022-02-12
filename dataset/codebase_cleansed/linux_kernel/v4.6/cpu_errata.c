static bool __maybe_unused
is_affected_midr_range(const struct arm64_cpu_capabilities *entry)
{
return MIDR_IS_CPU_MODEL_RANGE(read_cpuid_id(), entry->midr_model,
entry->midr_range_min,
entry->midr_range_max);
}
void check_local_cpu_errata(void)
{
update_cpu_capabilities(arm64_errata, "enabling workaround for");
}
