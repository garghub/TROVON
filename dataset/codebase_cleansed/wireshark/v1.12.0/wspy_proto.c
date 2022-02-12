hf_register_info *hf_register_info_create(const guint8 size)
{
hf_register_info *hf = g_malloc0(sizeof(hf_register_info) * size);
return hf;
}
void hf_register_info_destroy(hf_register_info *hf)
{
if (hf) {
g_free(hf);
}
}
void hf_register_info_add(hf_register_info *hf, guint8 index,
int *p_id, const char *name, const char *abbrev,
enum ftenum type, int display, const void *strings,
guint32 bitmask, const char *blurb)
{
hf[index].p_id = p_id;
hf[index].hfinfo.name = name;
hf[index].hfinfo.abbrev = abbrev;
hf[index].hfinfo.type = type;
hf[index].hfinfo.display = display;
hf[index].hfinfo.strings = strings;
hf[index].hfinfo.bitmask = bitmask;
hf[index].hfinfo.blurb = blurb;
hf[index].hfinfo.id = 0;
hf[index].hfinfo.parent = 0;
hf[index].hfinfo.ref_type = HF_REF_TYPE_NONE;
hf[index].hfinfo.same_name_next = NULL;
hf[index].hfinfo.same_name_prev_id = -1;
}
void hf_register_info_print(hf_register_info *hf, guint8 size)
{
guint8 c;
if (!hf)
return;
for (c = 0; c < size; c++) {
printf("%s : %s : %s\n", hf[c].hfinfo.name,
hf[c].hfinfo.abbrev,
hf[c].hfinfo.blurb);
}
}
