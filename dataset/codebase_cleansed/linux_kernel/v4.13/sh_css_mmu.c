void
ia_css_mmu_invalidate_cache(void)
{
const struct ia_css_fw_info *fw = &sh_css_sp_fw;
unsigned int HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_mmu_invalidate_cache() enter\n");
if (sh_css_sp_is_running()) {
HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb = fw->info.sp.invalidate_tlb;
(void)HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(ia_css_dmaproxy_sp_invalidate_tlb),
true);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_mmu_invalidate_cache() leave\n");
}
void
sh_css_mmu_set_page_table_base_index(hrt_data base_index)
{
int i;
IA_CSS_ENTER_PRIVATE("base_index=0x%08x\n", base_index);
for (i = 0; i < N_MMU_ID; i++) {
mmu_ID_t mmu_id = i;
mmu_set_page_table_base_index(mmu_id, base_index);
mmu_invalidate_cache(mmu_id);
}
IA_CSS_LEAVE_PRIVATE("");
}
