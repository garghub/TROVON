const struct x86_cpu_id *x86_match_cpu(const struct x86_cpu_id *match)
{
const struct x86_cpu_id *m;
struct cpuinfo_x86 *c = &boot_cpu_data;
for (m = match; m->vendor | m->family | m->model | m->feature; m++) {
if (m->vendor != X86_VENDOR_ANY && c->x86_vendor != m->vendor)
continue;
if (m->family != X86_FAMILY_ANY && c->x86 != m->family)
continue;
if (m->model != X86_MODEL_ANY && c->x86_model != m->model)
continue;
if (m->feature != X86_FEATURE_ANY && !cpu_has(c, m->feature))
continue;
return m;
}
return NULL;
}
