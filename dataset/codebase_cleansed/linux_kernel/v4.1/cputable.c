static struct cpu_spec * __init setup_cpu_spec(unsigned long offset,
struct cpu_spec *s)
{
struct cpu_spec *t = &the_cpu_spec;
struct cpu_spec old;
t = PTRRELOC(t);
old = *t;
*t = *s;
if (old.num_pmcs && !s->num_pmcs) {
t->num_pmcs = old.num_pmcs;
t->pmc_type = old.pmc_type;
t->oprofile_type = old.oprofile_type;
t->oprofile_mmcra_sihv = old.oprofile_mmcra_sihv;
t->oprofile_mmcra_sipr = old.oprofile_mmcra_sipr;
t->oprofile_mmcra_clear = old.oprofile_mmcra_clear;
if (old.oprofile_cpu_type != NULL) {
t->oprofile_cpu_type = old.oprofile_cpu_type;
t->oprofile_type = old.oprofile_type;
}
}
*PTRRELOC(&cur_cpu_spec) = &the_cpu_spec;
if (*PTRRELOC(&powerpc_base_platform) == NULL)
*PTRRELOC(&powerpc_base_platform) = t->platform;
#if defined(CONFIG_PPC64) || defined(CONFIG_BOOKE)
if (t->cpu_setup) {
t->cpu_setup(offset, t);
}
#endif
return t;
}
struct cpu_spec * __init identify_cpu(unsigned long offset, unsigned int pvr)
{
struct cpu_spec *s = cpu_specs;
int i;
s = PTRRELOC(s);
for (i = 0; i < ARRAY_SIZE(cpu_specs); i++,s++) {
if ((pvr & s->pvr_mask) == s->pvr_value)
return setup_cpu_spec(offset, s);
}
BUG();
return NULL;
}
