const struct attribute_group **cpumf_cf_event_group(void)
{
struct attribute **combined, **model;
struct attribute *none[] = { NULL };
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
case 0x2964:
case 0x2965:
model = cpumcf_z13_pmu_event_attr;
break;
default:
model = none;
break;
}
combined = merge_attr(cpumcf_pmu_event_attr, model);
if (combined)
cpumcf_pmu_events_group.attrs = combined;
return cpumcf_pmu_attr_groups;
}
