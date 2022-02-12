insn_attr_t inat_get_opcode_attribute(insn_byte_t opcode)
{
return inat_primary_table[opcode];
}
insn_attr_t inat_get_escape_attribute(insn_byte_t opcode, insn_byte_t last_pfx,
insn_attr_t esc_attr)
{
const insn_attr_t *table;
insn_attr_t lpfx_attr;
int n, m = 0;
n = inat_escape_id(esc_attr);
if (last_pfx) {
lpfx_attr = inat_get_opcode_attribute(last_pfx);
m = inat_last_prefix_id(lpfx_attr);
}
table = inat_escape_tables[n][0];
if (!table)
return 0;
if (inat_has_variant(table[opcode]) && m) {
table = inat_escape_tables[n][m];
if (!table)
return 0;
}
return table[opcode];
}
insn_attr_t inat_get_group_attribute(insn_byte_t modrm, insn_byte_t last_pfx,
insn_attr_t grp_attr)
{
const insn_attr_t *table;
insn_attr_t lpfx_attr;
int n, m = 0;
n = inat_group_id(grp_attr);
if (last_pfx) {
lpfx_attr = inat_get_opcode_attribute(last_pfx);
m = inat_last_prefix_id(lpfx_attr);
}
table = inat_group_tables[n][0];
if (!table)
return inat_group_common_attribute(grp_attr);
if (inat_has_variant(table[X86_MODRM_REG(modrm)]) && m) {
table = inat_group_tables[n][m];
if (!table)
return inat_group_common_attribute(grp_attr);
}
return table[X86_MODRM_REG(modrm)] |
inat_group_common_attribute(grp_attr);
}
insn_attr_t inat_get_avx_attribute(insn_byte_t opcode, insn_byte_t vex_m,
insn_byte_t vex_p)
{
const insn_attr_t *table;
if (vex_m > X86_VEX_M_MAX || vex_p > INAT_LSTPFX_MAX)
return 0;
table = inat_avx_tables[vex_m][0];
if (!table)
return 0;
if (!inat_is_group(table[opcode]) && vex_p) {
table = inat_avx_tables[vex_m][vex_p];
if (!table)
return 0;
}
return table[opcode];
}
