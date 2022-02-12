static bool
feature_matches(u64 reg, const struct arm64_cpu_capabilities *entry)
{
int val = cpuid_feature_extract_field(reg, entry->field_pos);
return val >= entry->min_field_value;
}
void check_cpu_capabilities(const struct arm64_cpu_capabilities *caps,
const char *info)
{
int i;
for (i = 0; caps[i].desc; i++) {
if (!caps[i].matches(&caps[i]))
continue;
if (!cpus_have_cap(caps[i].capability))
pr_info("%s %s\n", info, caps[i].desc);
cpus_set_cap(caps[i].capability);
}
for (i = 0; caps[i].desc; i++) {
if (cpus_have_cap(caps[i].capability) && caps[i].enable)
caps[i].enable();
}
}
void check_local_cpu_features(void)
{
check_cpu_capabilities(arm64_features, "detected feature:");
}
