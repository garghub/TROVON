bool elf__needs_adjust_symbols(GElf_Ehdr ehdr)
{
return ehdr.e_type == ET_EXEC ||
ehdr.e_type == ET_REL ||
ehdr.e_type == ET_DYN;
}
int arch__choose_best_symbol(struct symbol *syma,
struct symbol *symb __maybe_unused)
{
char *sym = syma->name;
if (*sym == '.')
sym++;
if (strlen(sym) >= 3 && !strncmp(sym, "SyS", 3))
return SYMBOL_B;
if (strlen(sym) >= 10 && !strncmp(sym, "compat_SyS", 10))
return SYMBOL_B;
return SYMBOL_A;
}
int arch__compare_symbol_names(const char *namea, const char *nameb)
{
if (*namea == '.')
namea++;
if (*nameb == '.')
nameb++;
return strcmp(namea, nameb);
}
bool arch__prefers_symtab(void)
{
return true;
}
void arch__sym_update(struct symbol *s, GElf_Sym *sym)
{
s->arch_sym = sym->st_other;
}
void arch__fix_tev_from_maps(struct perf_probe_event *pev,
struct probe_trace_event *tev, struct map *map,
struct symbol *sym)
{
int lep_offset;
if (pev->point.offset || pev->point.retprobe || !map || !sym)
return;
lep_offset = PPC64_LOCAL_ENTRY_OFFSET(sym->arch_sym);
if (map->dso->symtab_type == DSO_BINARY_TYPE__KALLSYMS)
tev->point.offset += PPC64LE_LEP_OFFSET;
else if (lep_offset) {
if (pev->uprobes)
tev->point.address += lep_offset;
else
tev->point.offset += lep_offset;
}
}
