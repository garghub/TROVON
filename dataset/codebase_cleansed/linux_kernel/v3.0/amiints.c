void __init amiga_init_IRQ(void)
{
if (request_irq(IRQ_AUTO_1, ami_int1, 0, "int1", NULL))
pr_err("Couldn't register int%d\n", 1);
if (request_irq(IRQ_AUTO_3, ami_int3, 0, "int3", NULL))
pr_err("Couldn't register int%d\n", 3);
if (request_irq(IRQ_AUTO_4, ami_int4, 0, "int4", NULL))
pr_err("Couldn't register int%d\n", 4);
if (request_irq(IRQ_AUTO_5, ami_int5, 0, "int5", NULL))
pr_err("Couldn't register int%d\n", 5);
m68k_setup_irq_controller(&amiga_irq_controller, IRQ_USER, AMI_STD_IRQS);
if (AMIGAHW_PRESENT(PCMCIA))
gayle.inten = GAYLE_IRQ_IDE;
amiga_custom.intena = 0x7fff;
amiga_custom.intreq = 0x7fff;
amiga_custom.intena = IF_SETCLR | IF_INTEN;
cia_init_IRQ(&ciaa_base);
cia_init_IRQ(&ciab_base);
}
static void amiga_enable_irq(unsigned int irq)
{
amiga_custom.intena = IF_SETCLR | (1 << (irq - IRQ_USER));
}
static void amiga_disable_irq(unsigned int irq)
{
amiga_custom.intena = 1 << (irq - IRQ_USER);
}
static irqreturn_t ami_int1(int irq, void *dev_id)
{
unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;
if (ints & IF_TBE) {
amiga_custom.intreq = IF_TBE;
m68k_handle_int(IRQ_AMIGA_TBE);
}
if (ints & IF_DSKBLK) {
amiga_custom.intreq = IF_DSKBLK;
m68k_handle_int(IRQ_AMIGA_DSKBLK);
}
if (ints & IF_SOFT) {
amiga_custom.intreq = IF_SOFT;
m68k_handle_int(IRQ_AMIGA_SOFT);
}
return IRQ_HANDLED;
}
static irqreturn_t ami_int3(int irq, void *dev_id)
{
unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;
if (ints & IF_BLIT) {
amiga_custom.intreq = IF_BLIT;
m68k_handle_int(IRQ_AMIGA_BLIT);
}
if (ints & IF_COPER) {
amiga_custom.intreq = IF_COPER;
m68k_handle_int(IRQ_AMIGA_COPPER);
}
if (ints & IF_VERTB) {
amiga_custom.intreq = IF_VERTB;
m68k_handle_int(IRQ_AMIGA_VERTB);
}
return IRQ_HANDLED;
}
static irqreturn_t ami_int4(int irq, void *dev_id)
{
unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;
if (ints & IF_AUD0) {
amiga_custom.intreq = IF_AUD0;
m68k_handle_int(IRQ_AMIGA_AUD0);
}
if (ints & IF_AUD1) {
amiga_custom.intreq = IF_AUD1;
m68k_handle_int(IRQ_AMIGA_AUD1);
}
if (ints & IF_AUD2) {
amiga_custom.intreq = IF_AUD2;
m68k_handle_int(IRQ_AMIGA_AUD2);
}
if (ints & IF_AUD3) {
amiga_custom.intreq = IF_AUD3;
m68k_handle_int(IRQ_AMIGA_AUD3);
}
return IRQ_HANDLED;
}
static irqreturn_t ami_int5(int irq, void *dev_id)
{
unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;
if (ints & IF_RBF) {
m68k_handle_int(IRQ_AMIGA_RBF);
}
if (ints & IF_DSKSYN) {
amiga_custom.intreq = IF_DSKSYN;
m68k_handle_int(IRQ_AMIGA_DSKSYN);
}
return IRQ_HANDLED;
}
