static void __init
sx164_init_irq(void)
{
outb(0, DMA1_RESET_REG);
outb(0, DMA2_RESET_REG);
outb(DMA_MODE_CASCADE, DMA2_MODE_REG);
outb(0, DMA2_MASK_REG);
if (alpha_using_srm)
alpha_mv.device_interrupt = srm_device_interrupt;
init_i8259a_irqs();
if (alpha_using_srm)
init_srm_irqs(40, 0x3f0000);
else
init_pyxis_irqs(0xff00003f0000UL);
setup_irq(16+6, &timer_cascade_irqaction);
}
static int __init
sx164_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[5][5] __initdata = {
{ 16+ 9, 16+ 9, 16+13, 16+17, 16+21},
{ 16+11, 16+11, 16+15, 16+19, 16+23},
{ 16+10, 16+10, 16+14, 16+18, 16+22},
{ -1, -1, -1, -1, -1},
{ 16+ 8, 16+ 8, 16+12, 16+16, 16+20}
};
const long min_idsel = 5, max_idsel = 9, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static void __init
sx164_init_pci(void)
{
cia_init_pci();
SMC669_Init(0);
}
static void __init
sx164_init_arch(void)
{
struct percpu_struct *cpu = (struct percpu_struct*)
((char*)hwrpb + hwrpb->processor_offset);
if (amask(AMASK_MAX) != 0
&& alpha_using_srm
&& (cpu->pal_revision & 0xffff) <= 0x117) {
__asm__ __volatile__(
"lda $16,8($31)\n"
"call_pal 9\n"
".long 0x64000118\n\n"
"ldah $16,(1<<(19-16))($31)\n"
"or $0,$16,$0\n"
".long 0x74000118\n"
"lda $16,9($31)\n"
"call_pal 9"
: : : "$0", "$16");
printk("PCA56 MVI set enabled\n");
}
pyxis_init_arch();
}
