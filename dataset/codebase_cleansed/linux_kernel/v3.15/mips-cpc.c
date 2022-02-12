phys_t __weak mips_cpc_phys_base(void)
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
phys_t addr;
addr = mips_cpc_phys_base();
if (!addr)
return -ENODEV;
mips_cpc_base = ioremap_nocache(addr, 0x8000);
if (!mips_cpc_base)
return -ENXIO;
return 0;
}
