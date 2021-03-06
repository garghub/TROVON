int create_orc(struct objtool_file *file)
{
struct instruction *insn;
for_each_insn(file, insn) {
struct orc_entry *orc = &insn->orc;
struct cfi_reg *cfa = &insn->state.cfa;
struct cfi_reg *bp = &insn->state.regs[CFI_BP];
if (cfa->base == CFI_UNDEFINED) {
orc->sp_reg = ORC_REG_UNDEFINED;
continue;
}
switch (cfa->base) {
case CFI_SP:
orc->sp_reg = ORC_REG_SP;
break;
case CFI_SP_INDIRECT:
orc->sp_reg = ORC_REG_SP_INDIRECT;
break;
case CFI_BP:
orc->sp_reg = ORC_REG_BP;
break;
case CFI_BP_INDIRECT:
orc->sp_reg = ORC_REG_BP_INDIRECT;
break;
case CFI_R10:
orc->sp_reg = ORC_REG_R10;
break;
case CFI_R13:
orc->sp_reg = ORC_REG_R13;
break;
case CFI_DI:
orc->sp_reg = ORC_REG_DI;
break;
case CFI_DX:
orc->sp_reg = ORC_REG_DX;
break;
default:
WARN_FUNC("unknown CFA base reg %d",
insn->sec, insn->offset, cfa->base);
return -1;
}
switch(bp->base) {
case CFI_UNDEFINED:
orc->bp_reg = ORC_REG_UNDEFINED;
break;
case CFI_CFA:
orc->bp_reg = ORC_REG_PREV_SP;
break;
case CFI_BP:
orc->bp_reg = ORC_REG_BP;
break;
default:
WARN_FUNC("unknown BP base reg %d",
insn->sec, insn->offset, bp->base);
return -1;
}
orc->sp_offset = cfa->offset;
orc->bp_offset = bp->offset;
orc->type = insn->state.type;
}
return 0;
}
static int create_orc_entry(struct section *u_sec, struct section *ip_relasec,
unsigned int idx, struct section *insn_sec,
unsigned long insn_off, struct orc_entry *o)
{
struct orc_entry *orc;
struct rela *rela;
orc = (struct orc_entry *)u_sec->data->d_buf + idx;
memcpy(orc, o, sizeof(*orc));
rela = malloc(sizeof(*rela));
if (!rela) {
perror("malloc");
return -1;
}
memset(rela, 0, sizeof(*rela));
rela->sym = insn_sec->sym;
rela->addend = insn_off;
rela->type = R_X86_64_PC32;
rela->offset = idx * sizeof(int);
list_add_tail(&rela->list, &ip_relasec->rela_list);
hash_add(ip_relasec->rela_hash, &rela->hash, rela->offset);
return 0;
}
int create_orc_sections(struct objtool_file *file)
{
struct instruction *insn, *prev_insn;
struct section *sec, *u_sec, *ip_relasec;
unsigned int idx;
struct orc_entry empty = {
.sp_reg = ORC_REG_UNDEFINED,
.bp_reg = ORC_REG_UNDEFINED,
.type = ORC_TYPE_CALL,
};
sec = find_section_by_name(file->elf, ".orc_unwind");
if (sec) {
WARN("file already has .orc_unwind section, skipping");
return -1;
}
idx = 0;
for_each_sec(file, sec) {
if (!sec->text)
continue;
prev_insn = NULL;
sec_for_each_insn(file, sec, insn) {
if (!prev_insn ||
memcmp(&insn->orc, &prev_insn->orc,
sizeof(struct orc_entry))) {
idx++;
}
prev_insn = insn;
}
if (prev_insn)
idx++;
}
if (!idx)
return -1;
sec = elf_create_section(file->elf, ".orc_unwind_ip", sizeof(int), idx);
ip_relasec = elf_create_rela_section(file->elf, sec);
if (!ip_relasec)
return -1;
u_sec = elf_create_section(file->elf, ".orc_unwind",
sizeof(struct orc_entry), idx);
idx = 0;
for_each_sec(file, sec) {
if (!sec->text)
continue;
prev_insn = NULL;
sec_for_each_insn(file, sec, insn) {
if (!prev_insn || memcmp(&insn->orc, &prev_insn->orc,
sizeof(struct orc_entry))) {
if (create_orc_entry(u_sec, ip_relasec, idx,
insn->sec, insn->offset,
&insn->orc))
return -1;
idx++;
}
prev_insn = insn;
}
if (prev_insn) {
if (create_orc_entry(u_sec, ip_relasec, idx,
prev_insn->sec,
prev_insn->offset + prev_insn->len,
&empty))
return -1;
idx++;
}
}
if (elf_rebuild_rela_section(ip_relasec))
return -1;
return 0;
}
