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
int arch__compare_symbol_names_n(const char *namea, const char *nameb,
unsigned int n)
{
if (*namea == '.')
namea++;
if (*nameb == '.')
nameb++;
return strncmp(namea, nameb, n);
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
if (pev->point.offset || !map || !sym)
return;
if (!pev->uprobes && pev->point.retprobe) {
#ifdef HAVE_LIBELF_SUPPORT
if (!kretprobe_offset_is_supported())
#endif
return;
}
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
void arch__post_process_probe_trace_events(struct perf_probe_event *pev,
int ntevs)
{
struct probe_trace_event *tev;
struct map *map;
struct symbol *sym = NULL;
struct rb_node *tmp;
int i = 0;
map = get_target_map(pev->target, pev->uprobes);
if (!map || map__load(map) < 0)
return;
for (i = 0; i < ntevs; i++) {
tev = &pev->tevs[i];
map__for_each_symbol(map, sym, tmp) {
if (map->unmap_ip(map, sym->start) == tev->point.address)
arch__fix_tev_from_maps(pev, tev, map, sym);
}
}
}
