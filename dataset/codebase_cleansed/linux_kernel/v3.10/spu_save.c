static inline void save_event_mask(void)
{
unsigned int offset;
offset = LSCSA_QW_OFFSET(event_mask);
regs_spill[offset].slot[0] = spu_readch(SPU_RdEventMask);
}
static inline void save_tag_mask(void)
{
unsigned int offset;
offset = LSCSA_QW_OFFSET(tag_mask);
regs_spill[offset].slot[0] = spu_readch(MFC_RdTagMask);
}
static inline void save_upper_240kb(addr64 lscsa_ea)
{
unsigned int ls = 16384;
unsigned int list = (unsigned int)&dma_list[0];
unsigned int size = sizeof(dma_list);
unsigned int tag_id = 0;
unsigned int cmd = 0x24;
spu_writech(MFC_LSA, ls);
spu_writech(MFC_EAH, lscsa_ea.ui[0]);
spu_writech(MFC_EAL, list);
spu_writech(MFC_Size, size);
spu_writech(MFC_TagID, tag_id);
spu_writech(MFC_Cmd, cmd);
}
static inline void save_fpcr(void)
{
unsigned int offset;
offset = LSCSA_QW_OFFSET(fpcr);
regs_spill[offset].v = spu_mffpscr();
}
static inline void save_decr(void)
{
unsigned int offset;
offset = LSCSA_QW_OFFSET(decr);
regs_spill[offset].slot[0] = spu_readch(SPU_RdDec);
}
static inline void save_srr0(void)
{
unsigned int offset;
offset = LSCSA_QW_OFFSET(srr0);
regs_spill[offset].slot[0] = spu_readch(SPU_RdSRR0);
}
static inline void spill_regs_to_mem(addr64 lscsa_ea)
{
unsigned int ls = (unsigned int)&regs_spill[0];
unsigned int size = sizeof(regs_spill);
unsigned int tag_id = 0;
unsigned int cmd = 0x20;
spu_writech(MFC_LSA, ls);
spu_writech(MFC_EAH, lscsa_ea.ui[0]);
spu_writech(MFC_EAL, lscsa_ea.ui[1]);
spu_writech(MFC_Size, size);
spu_writech(MFC_TagID, tag_id);
spu_writech(MFC_Cmd, cmd);
}
static inline void enqueue_sync(addr64 lscsa_ea)
{
unsigned int tag_id = 0;
unsigned int cmd = 0xCC;
spu_writech(MFC_TagID, tag_id);
spu_writech(MFC_Cmd, cmd);
}
static inline void save_complete(void)
{
spu_stop(SPU_SAVE_COMPLETE);
}
int main()
{
addr64 lscsa_ea;
lscsa_ea.ui[0] = spu_readch(SPU_RdSigNotify1);
lscsa_ea.ui[1] = spu_readch(SPU_RdSigNotify2);
save_event_mask();
save_tag_mask();
set_event_mask();
set_tag_mask();
build_dma_list(lscsa_ea);
save_upper_240kb(lscsa_ea);
save_fpcr();
save_decr();
save_srr0();
enqueue_putllc(lscsa_ea);
spill_regs_to_mem(lscsa_ea);
enqueue_sync(lscsa_ea);
set_tag_update();
read_tag_status();
read_llar_status();
save_complete();
return 0;
}
