static int atari_startup_irq(unsigned int irq)
{
m68k_irq_startup(irq);
atari_turnon_irq(irq);
atari_enable_irq(irq);
return 0;
}
static void atari_shutdown_irq(unsigned int irq)
{
atari_disable_irq(irq);
atari_turnoff_irq(irq);
m68k_irq_shutdown(irq);
if (irq == IRQ_AUTO_4)
vectors[VEC_INT4] = falcon_hblhandler;
}
void __init atari_init_IRQ(void)
{
m68k_setup_user_interrupt(VEC_USER, NUM_ATARI_SOURCES - IRQ_USER, NULL);
m68k_setup_irq_controller(&atari_irq_controller, 1, NUM_ATARI_SOURCES - 1);
#ifdef ATARI_USE_SOFTWARE_EOI
st_mfp.vec_adr = 0x48;
#else
st_mfp.vec_adr = 0x40;
#endif
st_mfp.int_en_a = 0x00;
st_mfp.int_en_b = 0x00;
st_mfp.int_mk_a = 0xff;
st_mfp.int_mk_b = 0xff;
if (ATARIHW_PRESENT(TT_MFP)) {
#ifdef ATARI_USE_SOFTWARE_EOI
tt_mfp.vec_adr = 0x58;
#else
tt_mfp.vec_adr = 0x50;
#endif
tt_mfp.int_en_a = 0x00;
tt_mfp.int_en_b = 0x00;
tt_mfp.int_mk_a = 0xff;
tt_mfp.int_mk_b = 0xff;
}
if (ATARIHW_PRESENT(SCC) && !atari_SCC_reset_done) {
atari_scc.cha_a_ctrl = 9;
MFPDELAY();
atari_scc.cha_a_ctrl = (char) 0xc0;
}
if (ATARIHW_PRESENT(SCU)) {
tt_scu.sys_mask = 0x10;
tt_scu.vme_mask = 0x60;
} else {
vectors[VEC_INT2] = falcon_hblhandler;
vectors[VEC_INT4] = falcon_hblhandler;
}
if (ATARIHW_PRESENT(PCM_8BIT) && ATARIHW_PRESENT(MICROWIRE)) {
atari_microwire_cmd(MW_LM1992_PSG_HIGH);
}
stdma_init();
sound_ym.rd_data_reg_sel = 7;
sound_ym.wd_data = 0xff;
}
unsigned long atari_register_vme_int(void)
{
int i;
for (i = 0; i < 32; i++)
if ((free_vme_vec_bitmap & (1 << i)) == 0)
break;
if (i == 16)
return 0;
free_vme_vec_bitmap |= 1 << i;
return VME_SOURCE_BASE + i;
}
void atari_unregister_vme_int(unsigned long irq)
{
if (irq >= VME_SOURCE_BASE && irq < VME_SOURCE_BASE + VME_MAX_SOURCES) {
irq -= VME_SOURCE_BASE;
free_vme_vec_bitmap &= ~(1 << irq);
}
}
