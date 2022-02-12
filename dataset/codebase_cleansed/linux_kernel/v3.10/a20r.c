static u32 a20r_ack_hwint(void)
{
u32 status = read_c0_status();
write_c0_status(status | 0x00010000);
asm volatile(
" .set push \n"
" .set noat \n"
" .set noreorder \n"
" lw $1, 0(%0) \n"
" sb $0, 0(%1) \n"
" sync \n"
" lb %1, 0(%1) \n"
" b 1f \n"
" ori %1, $1, 2 \n"
" .align 8 \n"
"1: \n"
" nop \n"
" sw %1, 0(%0) \n"
" sync \n"
" li %1, 0x20 \n"
"2: \n"
" nop \n"
" bnez %1,2b \n"
" addiu %1, -1 \n"
" sw $1, 0(%0) \n"
" sync \n"
".set pop \n"
:
: "Jr" (PCIMT_UCONF), "Jr" (0xbc000000));
write_c0_status(status);
return status;
}
static inline void unmask_a20r_irq(struct irq_data *d)
{
set_c0_status(0x100 << (d->irq - SNI_A20R_IRQ_BASE));
irq_enable_hazard();
}
static inline void mask_a20r_irq(struct irq_data *d)
{
clear_c0_status(0x100 << (d->irq - SNI_A20R_IRQ_BASE));
irq_disable_hazard();
}
static void a20r_hwint(void)
{
u32 cause, status;
int irq;
clear_c0_status(IE_IRQ0);
status = a20r_ack_hwint();
cause = read_c0_cause();
irq = ffs(((cause & status) >> 8) & 0xf8);
if (likely(irq > 0))
do_IRQ(SNI_A20R_IRQ_BASE + irq - 1);
set_c0_status(IE_IRQ0);
}
void __init sni_a20r_irq_init(void)
{
int i;
for (i = SNI_A20R_IRQ_BASE + 2 ; i < SNI_A20R_IRQ_BASE + 8; i++)
irq_set_chip_and_handler(i, &a20r_irq_type, handle_level_irq);
sni_hwint = a20r_hwint;
change_c0_status(ST0_IM, IE_IRQ0);
setup_irq(SNI_A20R_IRQ_BASE + 3, &sni_isa_irq);
}
void sni_a20r_init(void)
{
}
static int __init snirm_a20r_setup_devinit(void)
{
switch (sni_brd_type) {
case SNI_BRD_TOWER_OASIC:
case SNI_BRD_MINITOWER:
platform_device_register(&snirm_82596_pdev);
platform_device_register(&snirm_53c710_pdev);
platform_device_register(&sc26xx_pdev);
platform_device_register(&a20r_serial8250_device);
platform_device_register(&a20r_ds1216_device);
sni_eisa_root_init();
break;
}
return 0;
}
