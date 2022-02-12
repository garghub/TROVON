bool elf__needs_adjust_symbols(GElf_Ehdr ehdr)
{
return ehdr.e_type == ET_EXEC ||
ehdr.e_type == ET_REL ||
ehdr.e_type == ET_DYN;
}
void arch__elf_sym_adjust(GElf_Sym *sym)
{
sym->st_value += PPC64_LOCAL_ENTRY_OFFSET(sym->st_other);
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
void arch__fix_tev_from_maps(struct perf_probe_event *pev,
struct probe_trace_event *tev, struct map *map)
{
if (!pev->uprobes && map->dso->symtab_type == DSO_BINARY_TYPE__KALLSYMS) {
tev->point.address += PPC64LE_LEP_OFFSET;
tev->point.offset += PPC64LE_LEP_OFFSET;
}
}
