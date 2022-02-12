const char *get_arch_regstr(unsigned int n)
{
const struct pt_regs_dwarfnum *roff;
for (roff = regdwarfnum_table; roff->name != NULL; roff++)
if (roff->dwarfnum == n)
return roff->name;
return NULL;
}
int regs_query_register_offset(const char *name)
{
const struct pt_regs_dwarfnum *roff;
for (roff = regdwarfnum_table; roff->name != NULL; roff++)
if (!strcmp(roff->name, name))
return DWARFNUM2OFFSET(roff->dwarfnum);
return -EINVAL;
}
