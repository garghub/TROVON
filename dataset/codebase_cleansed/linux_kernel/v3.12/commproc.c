void __init m360_cpm_reset()
{
pquicc = (struct quicc *)(_quicc_base);
pquicc->cp_cr = (SOFTWARE_RESET | CMD_FLAG);
while (pquicc->cp_cr & CMD_FLAG);
pquicc->sdma_sdcr = 0x0740;
dp_alloc_base = CPM_DATAONLY_BASE;
dp_alloc_top = dp_alloc_base + CPM_DATAONLY_SIZE;
}
void
cpm_interrupt_init(void)
{
pquicc->intr_cicr =
(CICR_SCD_SCC4 | CICR_SCC_SCC3 | CICR_SCB_SCC2 | CICR_SCA_SCC1) |
(CPM_INTERRUPT << 13) |
CICR_HP_MASK |
(CPM_VECTOR_BASE << 5) |
CICR_SPS;
pquicc->intr_cimr = 0;
}
static void
cpm_interrupt(int irq, void * dev, struct pt_regs * regs)
{
#if 0
((volatile immap_t *)IMAP_ADDR)->im_cpic.cpic_civr = 1;
vec = ((volatile immap_t *)IMAP_ADDR)->im_cpic.cpic_civr;
vec >>= 11;
if (cpm_vecs[vec].handler != 0)
(*cpm_vecs[vec].handler)(cpm_vecs[vec].dev_id);
else
((immap_t *)IMAP_ADDR)->im_cpic.cpic_cimr &= ~(1 << vec);
((immap_t *)IMAP_ADDR)->im_cpic.cpic_cisr |= (1 << vec);
#endif
}
static void
cpm_error_interrupt(void *dev)
{
}
void
cpm_install_handler(int vec, void (*handler)(), void *dev_id)
{
request_irq(vec, handler, 0, "timer", dev_id);
}
void
cpm_free_handler(int vec)
{
cpm_vecs[vec].handler = NULL;
cpm_vecs[vec].dev_id = NULL;
pquicc->intr_cimr &= ~(1 << vec);
}
uint
m360_cpm_dpalloc(uint size)
{
uint retloc;
if ((dp_alloc_base + size) >= dp_alloc_top)
return(CPM_DP_NOSPACE);
retloc = dp_alloc_base;
dp_alloc_base += size;
return(retloc);
}
void
m360_cpm_setbrg(uint brg, uint rate)
{
volatile uint *bp;
bp = (volatile uint *)(&pquicc->brgc[0].l);
bp += brg;
*bp = ((BRG_UART_CLK / rate - 1) << 1) | CPM_BRG_EN;
}
