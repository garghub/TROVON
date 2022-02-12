static int get_alt_entry(struct elf *elf, struct special_entry *entry,
struct section *sec, int idx,
struct special_alt *alt)
{
struct rela *orig_rela, *new_rela;
unsigned long offset;
offset = idx * entry->size;
alt->group = entry->group;
alt->jump_or_nop = entry->jump_or_nop;
if (alt->group) {
alt->orig_len = *(unsigned char *)(sec->data->d_buf + offset +
entry->orig_len);
alt->new_len = *(unsigned char *)(sec->data->d_buf + offset +
entry->new_len);
}
if (entry->feature) {
unsigned short feature;
feature = *(unsigned short *)(sec->data->d_buf + offset +
entry->feature);
if (feature == X86_FEATURE_POPCNT)
alt->skip_orig = true;
}
orig_rela = find_rela_by_dest(sec, offset + entry->orig);
if (!orig_rela) {
WARN_FUNC("can't find orig rela", sec, offset + entry->orig);
return -1;
}
if (orig_rela->sym->type != STT_SECTION) {
WARN_FUNC("don't know how to handle non-section rela symbol %s",
sec, offset + entry->orig, orig_rela->sym->name);
return -1;
}
alt->orig_sec = orig_rela->sym->sec;
alt->orig_off = orig_rela->addend;
if (!entry->group || alt->new_len) {
new_rela = find_rela_by_dest(sec, offset + entry->new);
if (!new_rela) {
WARN_FUNC("can't find new rela",
sec, offset + entry->new);
return -1;
}
alt->new_sec = new_rela->sym->sec;
alt->new_off = (unsigned int)new_rela->addend;
if (alt->new_off >= 0x7ffffff0)
alt->new_off -= 0x7ffffff0;
}
return 0;
}
int special_get_alts(struct elf *elf, struct list_head *alts)
{
struct special_entry *entry;
struct section *sec;
unsigned int nr_entries;
struct special_alt *alt;
int idx, ret;
INIT_LIST_HEAD(alts);
for (entry = entries; entry->sec; entry++) {
sec = find_section_by_name(elf, entry->sec);
if (!sec)
continue;
if (sec->len % entry->size != 0) {
WARN("%s size not a multiple of %d",
sec->name, entry->size);
return -1;
}
nr_entries = sec->len / entry->size;
for (idx = 0; idx < nr_entries; idx++) {
alt = malloc(sizeof(*alt));
if (!alt) {
WARN("malloc failed");
return -1;
}
memset(alt, 0, sizeof(*alt));
ret = get_alt_entry(elf, entry, sec, idx, alt);
if (ret)
return ret;
list_add_tail(&alt->list, alts);
}
}
return 0;
}
