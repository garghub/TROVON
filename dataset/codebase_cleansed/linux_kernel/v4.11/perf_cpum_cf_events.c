const struct attribute_group **cpumf_cf_event_group(void)
{
struct attribute **combined, **model;
struct cpuid cpu_id;
get_cpu_id(&cpu_id);
switch (cpu_id.machine) {
case 0x2097:
case 0x2098:
model = cpumcf_z10_pmu_event_attr;
break;
case 0x2817:
case 0x2818:
model = cpumcf_z196_pmu_event_attr;
break;
case 0x2827:
case 0x2828:
model = cpumcf_zec12_pmu_event_attr;
break;
default:
model = NULL;
break;
}
if (!model)
goto out;
combined = merge_attr(cpumcf_pmu_event_attr, model);
if (combined)
cpumsf_pmu_events_group.attrs = combined;
out:
return cpumsf_pmu_attr_groups;
}
