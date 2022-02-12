phys_addr_t __mips_cm_phys_base(void)
{
u32 config3 = read_c0_config3();
unsigned long cmgcr;
if (!(config3 & MIPS_CONF3_CMGCR))
return 0;
cmgcr = read_c0_cmgcrbase();
return (cmgcr & MIPS_CMGCRF_BASE) << (36 - 32);
}
phys_addr_t __mips_cm_l2sync_phys_base(void)
{
u32 base_reg;
base_reg = read_gcr_l2_only_sync_base();
if (base_reg & CM_GCR_L2_ONLY_SYNC_BASE_SYNCEN)
return base_reg & CM_GCR_L2_ONLY_SYNC_BASE_SYNCBASE;
return mips_cm_phys_base() + MIPS_CM_GCR_SIZE;
}
static void mips_cm_probe_l2sync(void)
{
unsigned major_rev;
phys_addr_t addr;
major_rev = (read_gcr_rev() & CM_GCR_REV_MAJOR) >>
__ffs(CM_GCR_REV_MAJOR);
if (major_rev < 6)
return;
addr = mips_cm_l2sync_phys_base();
BUG_ON((addr & CM_GCR_L2_ONLY_SYNC_BASE_SYNCBASE) != addr);
if (!addr)
return;
write_gcr_l2_only_sync_base(addr | CM_GCR_L2_ONLY_SYNC_BASE_SYNCEN);
mips_cm_l2sync_base = ioremap_nocache(addr, MIPS_CM_L2SYNC_SIZE);
}
int mips_cm_probe(void)
{
phys_addr_t addr;
u32 base_reg;
unsigned cpu;
if (mips_gcr_base)
return 0;
addr = mips_cm_phys_base();
BUG_ON((addr & CM_GCR_BASE_GCRBASE) != addr);
if (!addr)
return -ENODEV;
mips_gcr_base = ioremap_nocache(addr, MIPS_CM_GCR_SIZE);
if (!mips_gcr_base)
return -ENXIO;
base_reg = read_gcr_base();
if ((base_reg & CM_GCR_BASE_GCRBASE) != addr) {
pr_err("GCRs appear to have been moved (expected them at 0x%08lx)!\n",
(unsigned long)addr);
mips_gcr_base = NULL;
return -ENODEV;
}
change_gcr_base(CM_GCR_BASE_CMDEFTGT, CM_GCR_BASE_CMDEFTGT_MEM);
write_gcr_reg0_base(CM_GCR_REGn_BASE_BASEADDR);
write_gcr_reg0_mask(CM_GCR_REGn_MASK_ADDRMASK);
write_gcr_reg1_base(CM_GCR_REGn_BASE_BASEADDR);
write_gcr_reg1_mask(CM_GCR_REGn_MASK_ADDRMASK);
write_gcr_reg2_base(CM_GCR_REGn_BASE_BASEADDR);
write_gcr_reg2_mask(CM_GCR_REGn_MASK_ADDRMASK);
write_gcr_reg3_base(CM_GCR_REGn_BASE_BASEADDR);
write_gcr_reg3_mask(CM_GCR_REGn_MASK_ADDRMASK);
mips_cm_probe_l2sync();
mips_cm_is64 = IS_ENABLED(CONFIG_64BIT) && (mips_cm_revision() >= CM_REV_CM3);
for_each_possible_cpu(cpu)
spin_lock_init(&per_cpu(cm_core_lock, cpu));
return 0;
}
void mips_cm_lock_other(unsigned int cluster, unsigned int core,
unsigned int vp, unsigned int block)
{
unsigned int curr_core, cm_rev;
u32 val;
cm_rev = mips_cm_revision();
preempt_disable();
if (cm_rev >= CM_REV_CM3) {
val = core << __ffs(CM3_GCR_Cx_OTHER_CORE);
val |= vp << __ffs(CM3_GCR_Cx_OTHER_VP);
if (cm_rev >= CM_REV_CM3_5) {
val |= CM_GCR_Cx_OTHER_CLUSTER_EN;
val |= cluster << __ffs(CM_GCR_Cx_OTHER_CLUSTER);
val |= block << __ffs(CM_GCR_Cx_OTHER_BLOCK);
} else {
WARN_ON(cluster != 0);
WARN_ON(block != CM_GCR_Cx_OTHER_BLOCK_LOCAL);
}
spin_lock_irqsave(this_cpu_ptr(&cm_core_lock),
*this_cpu_ptr(&cm_core_lock_flags));
} else {
WARN_ON(cluster != 0);
WARN_ON(vp != 0);
WARN_ON(block != CM_GCR_Cx_OTHER_BLOCK_LOCAL);
curr_core = cpu_core(&current_cpu_data);
spin_lock_irqsave(&per_cpu(cm_core_lock, curr_core),
per_cpu(cm_core_lock_flags, curr_core));
val = core << __ffs(CM_GCR_Cx_OTHER_CORENUM);
}
write_gcr_cl_other(val);
mb();
}
void mips_cm_unlock_other(void)
{
unsigned int curr_core;
if (mips_cm_revision() < CM_REV_CM3) {
curr_core = cpu_core(&current_cpu_data);
spin_unlock_irqrestore(&per_cpu(cm_core_lock, curr_core),
per_cpu(cm_core_lock_flags, curr_core));
} else {
spin_unlock_irqrestore(this_cpu_ptr(&cm_core_lock),
*this_cpu_ptr(&cm_core_lock_flags));
}
preempt_enable();
}
void mips_cm_error_report(void)
{
u64 cm_error, cm_addr, cm_other;
unsigned long revision;
int ocause, cause;
char buf[256];
if (!mips_cm_present())
return;
revision = mips_cm_revision();
cm_error = read_gcr_error_cause();
cm_addr = read_gcr_error_addr();
cm_other = read_gcr_error_mult();
if (revision < CM_REV_CM3) {
cause = cm_error >> __ffs(CM_GCR_ERROR_CAUSE_ERRTYPE);
ocause = cm_other >> __ffs(CM_GCR_ERROR_MULT_ERR2ND);
if (!cause)
return;
if (cause < 16) {
unsigned long cca_bits = (cm_error >> 15) & 7;
unsigned long tr_bits = (cm_error >> 12) & 7;
unsigned long cmd_bits = (cm_error >> 7) & 0x1f;
unsigned long stag_bits = (cm_error >> 3) & 15;
unsigned long sport_bits = (cm_error >> 0) & 7;
snprintf(buf, sizeof(buf),
"CCA=%lu TR=%s MCmd=%s STag=%lu "
"SPort=%lu\n", cca_bits, cm2_tr[tr_bits],
cm2_cmd[cmd_bits], stag_bits, sport_bits);
} else {
unsigned long c3_bits = (cm_error >> 18) & 7;
unsigned long c2_bits = (cm_error >> 15) & 7;
unsigned long c1_bits = (cm_error >> 12) & 7;
unsigned long c0_bits = (cm_error >> 9) & 7;
unsigned long sc_bit = (cm_error >> 8) & 1;
unsigned long cmd_bits = (cm_error >> 3) & 0x1f;
unsigned long sport_bits = (cm_error >> 0) & 7;
snprintf(buf, sizeof(buf),
"C3=%s C2=%s C1=%s C0=%s SC=%s "
"MCmd=%s SPort=%lu\n",
cm2_core[c3_bits], cm2_core[c2_bits],
cm2_core[c1_bits], cm2_core[c0_bits],
sc_bit ? "True" : "False",
cm2_cmd[cmd_bits], sport_bits);
}
pr_err("CM_ERROR=%08llx %s <%s>\n", cm_error,
cm2_causes[cause], buf);
pr_err("CM_ADDR =%08llx\n", cm_addr);
pr_err("CM_OTHER=%08llx %s\n", cm_other, cm2_causes[ocause]);
} else {
ulong core_id_bits, vp_id_bits, cmd_bits, cmd_group_bits;
ulong cm3_cca_bits, mcp_bits, cm3_tr_bits, sched_bit;
cause = cm_error >> __ffs64(CM3_GCR_ERROR_CAUSE_ERRTYPE);
ocause = cm_other >> __ffs(CM_GCR_ERROR_MULT_ERR2ND);
if (!cause)
return;
core_id_bits = (cm_error >> 22) & 0xf;
vp_id_bits = (cm_error >> 18) & 0xf;
cmd_bits = (cm_error >> 14) & 0xf;
cmd_group_bits = (cm_error >> 11) & 0xf;
cm3_cca_bits = (cm_error >> 8) & 7;
mcp_bits = (cm_error >> 5) & 0xf;
cm3_tr_bits = (cm_error >> 1) & 0xf;
sched_bit = cm_error & 0x1;
if (cause == 1 || cause == 3) {
unsigned long tag_ecc = (cm_error >> 57) & 0x1;
unsigned long tag_way_bits = (cm_error >> 29) & 0xffff;
unsigned long dword_bits = (cm_error >> 49) & 0xff;
unsigned long data_way_bits = (cm_error >> 45) & 0xf;
unsigned long data_sets_bits = (cm_error >> 29) & 0xfff;
unsigned long bank_bit = (cm_error >> 28) & 0x1;
snprintf(buf, sizeof(buf),
"%s ECC Error: Way=%lu (DWORD=%lu, Sets=%lu)"
"Bank=%lu CoreID=%lu VPID=%lu Command=%s"
"Command Group=%s CCA=%lu MCP=%d"
"Transaction type=%s Scheduler=%lu\n",
tag_ecc ? "TAG" : "DATA",
tag_ecc ? (unsigned long)ffs(tag_way_bits) - 1 :
data_way_bits, bank_bit, dword_bits,
data_sets_bits,
core_id_bits, vp_id_bits,
cm3_cmd[cmd_bits],
cm3_cmd_group[cmd_group_bits],
cm3_cca_bits, 1 << mcp_bits,
cm3_tr[cm3_tr_bits], sched_bit);
} else if (cause == 2) {
unsigned long data_error_type = (cm_error >> 41) & 0xfff;
unsigned long data_decode_cmd = (cm_error >> 37) & 0xf;
unsigned long data_decode_group = (cm_error >> 34) & 0x7;
unsigned long data_decode_destination_id = (cm_error >> 28) & 0x3f;
snprintf(buf, sizeof(buf),
"Decode Request Error: Type=%lu, Command=%lu"
"Command Group=%lu Destination ID=%lu"
"CoreID=%lu VPID=%lu Command=%s"
"Command Group=%s CCA=%lu MCP=%d"
"Transaction type=%s Scheduler=%lu\n",
data_error_type, data_decode_cmd,
data_decode_group, data_decode_destination_id,
core_id_bits, vp_id_bits,
cm3_cmd[cmd_bits],
cm3_cmd_group[cmd_group_bits],
cm3_cca_bits, 1 << mcp_bits,
cm3_tr[cm3_tr_bits], sched_bit);
} else {
buf[0] = 0;
}
pr_err("CM_ERROR=%llx %s <%s>\n", cm_error,
cm3_causes[cause], buf);
pr_err("CM_ADDR =%llx\n", cm_addr);
pr_err("CM_OTHER=%llx %s\n", cm_other, cm3_causes[ocause]);
}
write_gcr_error_cause(0);
}
