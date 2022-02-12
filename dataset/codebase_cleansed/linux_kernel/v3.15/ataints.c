static unsigned int atari_irq_startup(struct irq_data *data)
{
unsigned int irq = data->irq;
m68k_irq_startup(data);
atari_turnon_irq(irq);
atari_enable_irq(irq);
return 0;
}
static void atari_irq_shutdown(struct irq_data *data)
{
unsigned int irq = data->irq;
atari_disable_irq(irq);
atari_turnoff_irq(irq);
m68k_irq_shutdown(data);
if (irq == IRQ_AUTO_4)
vectors[VEC_INT4] = falcon_hblhandler;
}
static void atari_irq_enable(struct irq_data *data)
{
atari_enable_irq(data->irq);
}
static void atari_irq_disable(struct irq_data *data)
{
atari_disable_irq(data->irq);
}
static irqreturn_t mfptimer_handler(int irq, void *dev_id)
{
struct mfptimerbase *base = dev_id;
int mach_irq;
unsigned char ints;
mach_irq = base->mfptimer_irq;
ints = base->int_mask;
for (; ints; mach_irq++, ints >>= 1) {
if (ints & 1)
generic_handle_irq(mach_irq);
}
return IRQ_HANDLED;
}
static void atari_mfptimer_enable(struct irq_data *data)
{
int mfp_num = data->irq - IRQ_MFP_TIMER1;
stmfp_base.int_mask |= 1 << mfp_num;
atari_enable_irq(IRQ_MFP_TIMD);
}
static void atari_mfptimer_disable(struct irq_data *data)
{
int mfp_num = data->irq - IRQ_MFP_TIMER1;
stmfp_base.int_mask &= ~(1 << mfp_num);
if (!stmfp_base.int_mask)
atari_disable_irq(IRQ_MFP_TIMD);
}
static unsigned int atari_ethernat_startup(struct irq_data *data)
{
int enat_num = 140 - data->irq + 1;
m68k_irq_startup(data);
if (!enat_cpld)
enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
if (enat_num == 1)
*enat_cpld |= 1 << enat_num;
return 0;
}
static void atari_ethernat_enable(struct irq_data *data)
{
int enat_num = 140 - data->irq + 1;
if (!enat_cpld)
enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
*enat_cpld |= 1 << enat_num;
}
static void atari_ethernat_disable(struct irq_data *data)
{
int enat_num = 140 - data->irq + 1;
if (!enat_cpld)
enat_cpld = (unsigned char *)ioremap((ATARI_ETHERNAT_PHYS_ADDR+0x23), 0x2);
*enat_cpld &= ~(1 << enat_num);
}
static void atari_ethernat_shutdown(struct irq_data *data)
{
int enat_num = 140 - data->irq + 1;
if (enat_cpld) {
*enat_cpld &= ~(1 << enat_num);
iounmap(enat_cpld);
enat_cpld = NULL;
}
}
void __init atari_init_IRQ(void)
{
m68k_setup_user_interrupt(VEC_USER, NUM_ATARI_SOURCES - IRQ_USER);
m68k_setup_irq_controller(&atari_irq_chip, handle_simple_irq, 1,
NUM_ATARI_SOURCES - 1);
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
m68k_setup_irq_controller(&atari_mfptimer_chip, handle_simple_irq,
IRQ_MFP_TIMER1, 8);
irq_set_status_flags(IRQ_MFP_TIMER1, IRQ_IS_POLLED);
irq_set_status_flags(IRQ_MFP_TIMER2, IRQ_IS_POLLED);
st_mfp.tim_dt_d = 254;
st_mfp.tim_ct_cd = (st_mfp.tim_ct_cd & 0xf0) | 0x6;
if (request_irq(IRQ_MFP_TIMD, mfptimer_handler, IRQF_SHARED,
stmfp_base.name, &stmfp_base))
pr_err("Couldn't register %s interrupt\n", stmfp_base.name);
m68k_setup_irq_controller(&atari_ethernat_chip, handle_simple_irq,
139, 2);
}
unsigned int atari_register_vme_int(void)
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
void atari_unregister_vme_int(unsigned int irq)
{
if (irq >= VME_SOURCE_BASE && irq < VME_SOURCE_BASE + VME_MAX_SOURCES) {
irq -= VME_SOURCE_BASE;
free_vme_vec_bitmap &= ~(1 << irq);
}
}
