static inline void mac0_int_dispatch(void) { do_IRQ(MSP_INT_MAC0); }
static inline void mac1_int_dispatch(void) { do_IRQ(MSP_INT_MAC1); }
static inline void mac2_int_dispatch(void) { do_IRQ(MSP_INT_SAR); }
static inline void usb_int_dispatch(void) { do_IRQ(MSP_INT_USB); }
static inline void sec_int_dispatch(void) { do_IRQ(MSP_INT_SEC); }
asmlinkage void plat_irq_dispatch(struct pt_regs *regs)
{
u32 pending;
pending = read_c0_status() & read_c0_cause();
#ifdef CONFIG_IRQ_MSP_CIC
if (pending & C_IRQ4)
msp_cic_irq_dispatch();
else if (pending & C_IRQ0)
do_IRQ(MSP_INT_MAC0);
else if (pending & C_IRQ1)
do_IRQ(MSP_INT_MAC1);
else if (pending & C_IRQ2)
do_IRQ(MSP_INT_USB);
else if (pending & C_IRQ3)
do_IRQ(MSP_INT_SAR);
else if (pending & C_IRQ5)
do_IRQ(MSP_INT_SEC);
#else
if (pending & C_IRQ5)
do_IRQ(MSP_INT_TIMER);
else if (pending & C_IRQ0)
do_IRQ(MSP_INT_MAC0);
else if (pending & C_IRQ1)
do_IRQ(MSP_INT_MAC1);
else if (pending & C_IRQ3)
do_IRQ(MSP_INT_VE);
else if (pending & C_IRQ4)
msp_slp_irq_dispatch();
#endif
else if (pending & C_SW0)
do_IRQ(MSP_INT_SW0);
else if (pending & C_SW1)
do_IRQ(MSP_INT_SW1);
}
void __init arch_init_irq(void)
{
#ifdef CONFIG_MIPS_MT
BUG_ON(!cpu_has_vint);
#endif
mips_cpu_irq_init();
#ifdef CONFIG_IRQ_MSP_CIC
msp_cic_irq_init();
#ifdef CONFIG_MIPS_MT
set_vi_handler(MSP_INT_CIC, msp_cic_irq_dispatch);
set_vi_handler(MSP_INT_MAC0, mac0_int_dispatch);
set_vi_handler(MSP_INT_MAC1, mac1_int_dispatch);
set_vi_handler(MSP_INT_SAR, mac2_int_dispatch);
set_vi_handler(MSP_INT_USB, usb_int_dispatch);
set_vi_handler(MSP_INT_SEC, sec_int_dispatch);
#ifdef CONFIG_MIPS_MT_SMP
msp_vsmp_int_init();
#endif
#endif
setup_irq(MSP_INT_CIC, &cic_cascade_msp);
setup_irq(MSP_INT_PER, &per_cascade_msp);
#else
msp_slp_irq_init();
setup_irq(MSP_INT_SLP, &cic_cascade_msp);
setup_irq(MSP_INT_PER, &per_cascade_msp);
#endif
}
