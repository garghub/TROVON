phys_addr_t __mips_cm_phys_base(void)
{
u32 config3 = read_c0_config3();
u32 cmgcr;
if (!(config3 & MIPS_CONF3_CMGCR))
return 0;
cmgcr = read_c0_cmgcrbase();
return (cmgcr & MIPS_CMGCRF_BASE) << (36 - 32);
}
phys_addr_t __mips_cm_l2sync_phys_base(void)
{
u32 base_reg;
base_reg = read_gcr_l2_only_sync_base();
if (base_reg & CM_GCR_L2_ONLY_SYNC_BASE_SYNCEN_MSK)
return base_reg & CM_GCR_L2_ONLY_SYNC_BASE_SYNCBASE_MSK;
return mips_cm_phys_base() + MIPS_CM_GCR_SIZE;
}
static void mips_cm_probe_l2sync(void)
{
unsigned major_rev;
phys_addr_t addr;
major_rev = (read_gcr_rev() & CM_GCR_REV_MAJOR_MSK) >>
CM_GCR_REV_MAJOR_SHF;
if (major_rev < 6)
return;
addr = mips_cm_l2sync_phys_base();
BUG_ON((addr & CM_GCR_L2_ONLY_SYNC_BASE_SYNCBASE_MSK) != addr);
if (!addr)
return;
write_gcr_l2_only_sync_base(addr | CM_GCR_L2_ONLY_SYNC_BASE_SYNCEN_MSK);
mips_cm_l2sync_base = ioremap_nocache(addr, MIPS_CM_L2SYNC_SIZE);
}
int mips_cm_probe(void)
{
phys_addr_t addr;
u32 base_reg;
addr = mips_cm_phys_base();
BUG_ON((addr & CM_GCR_BASE_GCRBASE_MSK) != addr);
if (!addr)
return -ENODEV;
mips_cm_base = ioremap_nocache(addr, MIPS_CM_GCR_SIZE);
if (!mips_cm_base)
return -ENXIO;
base_reg = read_gcr_base();
if ((base_reg & CM_GCR_BASE_GCRBASE_MSK) != addr) {
pr_err("GCRs appear to have been moved (expected them at 0x%08lx)!\n",
(unsigned long)addr);
mips_cm_base = NULL;
return -ENODEV;
}
base_reg &= ~CM_GCR_BASE_CMDEFTGT_MSK;
base_reg |= CM_GCR_BASE_CMDEFTGT_MEM;
write_gcr_base(base_reg);
write_gcr_reg0_base(CM_GCR_REGn_BASE_BASEADDR_MSK);
write_gcr_reg0_mask(CM_GCR_REGn_MASK_ADDRMASK_MSK);
write_gcr_reg1_base(CM_GCR_REGn_BASE_BASEADDR_MSK);
write_gcr_reg1_mask(CM_GCR_REGn_MASK_ADDRMASK_MSK);
write_gcr_reg2_base(CM_GCR_REGn_BASE_BASEADDR_MSK);
write_gcr_reg2_mask(CM_GCR_REGn_MASK_ADDRMASK_MSK);
write_gcr_reg3_base(CM_GCR_REGn_BASE_BASEADDR_MSK);
write_gcr_reg3_mask(CM_GCR_REGn_MASK_ADDRMASK_MSK);
mips_cm_probe_l2sync();
return 0;
}
