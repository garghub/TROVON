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
}
void check_local_cpu_features(void)
{
check_cpu_capabilities(arm64_features, "detected feature");
}
