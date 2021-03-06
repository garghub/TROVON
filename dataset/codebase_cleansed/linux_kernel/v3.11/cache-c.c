void blackfin_invalidate_entire_dcache(void)
{
u32 dmem = bfin_read_DMEM_CONTROL();
bfin_write_DMEM_CONTROL(dmem & ~0xc);
SSYNC();
bfin_write_DMEM_CONTROL(dmem);
SSYNC();
}
void blackfin_invalidate_entire_icache(void)
{
u32 imem = bfin_read_IMEM_CONTROL();
bfin_write_IMEM_CONTROL(imem & ~0x4);
SSYNC();
bfin_write_IMEM_CONTROL(imem);
SSYNC();
}
static void
bfin_cache_init(struct cplb_entry *cplb_tbl, unsigned long cplb_addr,
unsigned long cplb_data, unsigned long mem_control,
unsigned long mem_mask)
{
int i;
for (i = 0; i < MAX_CPLBS; i++) {
bfin_write32(cplb_addr + i * 4, cplb_tbl[i].addr);
bfin_write32(cplb_data + i * 4, cplb_tbl[i].data);
}
_enable_cplb(mem_control, mem_mask);
}
void bfin_icache_init(struct cplb_entry *icplb_tbl)
{
bfin_cache_init(icplb_tbl, ICPLB_ADDR0, ICPLB_DATA0, IMEM_CONTROL,
(IMC | ENICPLB));
}
void bfin_dcache_init(struct cplb_entry *dcplb_tbl)
{
bfin_cache_init(dcplb_tbl, DCPLB_ADDR0, DCPLB_DATA0, DMEM_CONTROL,
(DMEM_CNTR | PORT_PREF0 | (ANOMALY_05000287 ? PORT_PREF1 : 0)));
}
