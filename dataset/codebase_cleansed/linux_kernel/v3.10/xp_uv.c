static unsigned long
xp_pa_uv(void *addr)
{
return uv_gpa(addr);
}
static unsigned long
xp_socket_pa_uv(unsigned long gpa)
{
return uv_gpa_to_soc_phys_ram(gpa);
}
static enum xp_retval
xp_remote_mmr_read(unsigned long dst_gpa, const unsigned long src_gpa,
size_t len)
{
int ret;
unsigned long *dst_va = __va(uv_gpa_to_soc_phys_ram(dst_gpa));
BUG_ON(!uv_gpa_in_mmr_space(src_gpa));
BUG_ON(len != 8);
ret = gru_read_gpa(dst_va, src_gpa);
if (ret == 0)
return xpSuccess;
dev_err(xp, "gru_read_gpa() failed, dst_gpa=0x%016lx src_gpa=0x%016lx "
"len=%ld\n", dst_gpa, src_gpa, len);
return xpGruCopyError;
}
static enum xp_retval
xp_remote_memcpy_uv(unsigned long dst_gpa, const unsigned long src_gpa,
size_t len)
{
int ret;
if (uv_gpa_in_mmr_space(src_gpa))
return xp_remote_mmr_read(dst_gpa, src_gpa, len);
ret = gru_copy_gpa(dst_gpa, src_gpa, len);
if (ret == 0)
return xpSuccess;
dev_err(xp, "gru_copy_gpa() failed, dst_gpa=0x%016lx src_gpa=0x%016lx "
"len=%ld\n", dst_gpa, src_gpa, len);
return xpGruCopyError;
}
static int
xp_cpu_to_nasid_uv(int cpuid)
{
return UV_PNODE_TO_NASID(uv_cpu_to_pnode(cpuid));
}
static enum xp_retval
xp_expand_memprotect_uv(unsigned long phys_addr, unsigned long size)
{
int ret;
#if defined CONFIG_X86_64
ret = uv_bios_change_memprotect(phys_addr, size, UV_MEMPROT_ALLOW_RW);
if (ret != BIOS_STATUS_SUCCESS) {
dev_err(xp, "uv_bios_change_memprotect(,, "
"UV_MEMPROT_ALLOW_RW) failed, ret=%d\n", ret);
return xpBiosError;
}
#elif defined CONFIG_IA64_GENERIC || defined CONFIG_IA64_SGI_UV
u64 nasid_array;
ret = sn_change_memprotect(phys_addr, size, SN_MEMPROT_ACCESS_CLASS_1,
&nasid_array);
if (ret != 0) {
dev_err(xp, "sn_change_memprotect(,, "
"SN_MEMPROT_ACCESS_CLASS_1,) failed ret=%d\n", ret);
return xpSalError;
}
#else
#error not a supported configuration
#endif
return xpSuccess;
}
static enum xp_retval
xp_restrict_memprotect_uv(unsigned long phys_addr, unsigned long size)
{
int ret;
#if defined CONFIG_X86_64
ret = uv_bios_change_memprotect(phys_addr, size,
UV_MEMPROT_RESTRICT_ACCESS);
if (ret != BIOS_STATUS_SUCCESS) {
dev_err(xp, "uv_bios_change_memprotect(,, "
"UV_MEMPROT_RESTRICT_ACCESS) failed, ret=%d\n", ret);
return xpBiosError;
}
#elif defined CONFIG_IA64_GENERIC || defined CONFIG_IA64_SGI_UV
u64 nasid_array;
ret = sn_change_memprotect(phys_addr, size, SN_MEMPROT_ACCESS_CLASS_0,
&nasid_array);
if (ret != 0) {
dev_err(xp, "sn_change_memprotect(,, "
"SN_MEMPROT_ACCESS_CLASS_0,) failed ret=%d\n", ret);
return xpSalError;
}
#else
#error not a supported configuration
#endif
return xpSuccess;
}
enum xp_retval
xp_init_uv(void)
{
BUG_ON(!is_uv());
xp_max_npartitions = XP_MAX_NPARTITIONS_UV;
xp_partition_id = sn_partition_id;
xp_region_size = sn_region_size;
xp_pa = xp_pa_uv;
xp_socket_pa = xp_socket_pa_uv;
xp_remote_memcpy = xp_remote_memcpy_uv;
xp_cpu_to_nasid = xp_cpu_to_nasid_uv;
xp_expand_memprotect = xp_expand_memprotect_uv;
xp_restrict_memprotect = xp_restrict_memprotect_uv;
return xpSuccess;
}
void
xp_exit_uv(void)
{
BUG_ON(!is_uv());
}
