void arch_klp_init_object_loaded(struct klp_patch *patch,
struct klp_object *obj)
{
int cnt;
struct klp_modinfo *info;
Elf_Shdr *s, *alt = NULL, *para = NULL;
void *aseg, *pseg;
const char *objname;
char sec_objname[MODULE_NAME_LEN];
char secname[KSYM_NAME_LEN];
info = patch->mod->klp_info;
objname = obj->name ? obj->name : "vmlinux";
BUILD_BUG_ON(MODULE_NAME_LEN < 56 || KSYM_NAME_LEN != 128);
for (s = info->sechdrs; s < info->sechdrs + info->hdr.e_shnum; s++) {
cnt = sscanf(info->secstrings + s->sh_name,
".klp.arch.%55[^.].%127s",
sec_objname, secname);
if (cnt != 2)
continue;
if (strcmp(sec_objname, objname))
continue;
if (!strcmp(".altinstructions", secname))
alt = s;
if (!strcmp(".parainstructions", secname))
para = s;
}
if (alt) {
aseg = (void *) alt->sh_addr;
apply_alternatives(aseg, aseg + alt->sh_size);
}
if (para) {
pseg = (void *) para->sh_addr;
apply_paravirt(pseg, pseg + para->sh_size);
}
}
