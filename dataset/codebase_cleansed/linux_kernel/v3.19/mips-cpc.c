phys_addr_t __weak mips_cpc_phys_base(void)
{
u32 cpc_base;
if (!mips_cm_present())
return 0;
if (!(read_gcr_cpc_status() & CM_GCR_CPC_STATUS_EX_MSK))
return 0;
cpc_base = read_gcr_cpc_base();
if (cpc_base & CM_GCR_CPC_BASE_CPCEN_MSK)
return cpc_base & CM_GCR_CPC_BASE_CPCBASE_MSK;
cpc_base = mips_cpc_default_phys_base();
write_gcr_cpc_base(cpc_base | CM_GCR_CPC_BASE_CPCEN_MSK);
return cpc_base;
}
int mips_cpc_probe(void)
{
phys_addr_t addr;
unsigned cpu;
for_each_possible_cpu(cpu)
spin_lock_init(&per_cpu(cpc_core_lock, cpu));
addr = mips_cpc_phys_base();
if (!addr)
return -ENODEV;
mips_cpc_base = ioremap_nocache(addr, 0x8000);
if (!mips_cpc_base)
return -ENXIO;
return 0;
}
void mips_cpc_lock_other(unsigned int core)
{
unsigned curr_core;
preempt_disable();
curr_core = current_cpu_data.core;
spin_lock_irqsave(&per_cpu(cpc_core_lock, curr_core),
per_cpu(cpc_core_lock_flags, curr_core));
write_cpc_cl_other(core << CPC_Cx_OTHER_CORENUM_SHF);
}
void mips_cpc_unlock_other(void)
{
unsigned curr_core = current_cpu_data.core;
spin_unlock_irqrestore(&per_cpu(cpc_core_lock, curr_core),
per_cpu(cpc_core_lock_flags, curr_core));
preempt_enable();
}
