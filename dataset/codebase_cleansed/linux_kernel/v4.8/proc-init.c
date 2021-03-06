asmlinkage void __init processor_init(void)
{
int loop;
for (loop = 0x000; loop < 0x400; loop += 8)
__set_intr_stub(loop, __common_exception);
__set_intr_stub(EXCEP_ITLBMISS, itlb_miss);
__set_intr_stub(EXCEP_DTLBMISS, dtlb_miss);
__set_intr_stub(EXCEP_IAERROR, itlb_aerror);
__set_intr_stub(EXCEP_DAERROR, dtlb_aerror);
__set_intr_stub(EXCEP_BUSERROR, raw_bus_error);
__set_intr_stub(EXCEP_DOUBLE_FAULT, double_fault);
__set_intr_stub(EXCEP_FPU_DISABLED, fpu_disabled);
__set_intr_stub(EXCEP_SYSCALL0, system_call);
__set_intr_stub(EXCEP_NMI, nmi_handler);
__set_intr_stub(EXCEP_WDT, nmi_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL0, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL1, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL2, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL3, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL4, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL5, irq_handler);
__set_intr_stub(EXCEP_IRQ_LEVEL6, irq_handler);
IVAR0 = EXCEP_IRQ_LEVEL0;
IVAR1 = EXCEP_IRQ_LEVEL1;
IVAR2 = EXCEP_IRQ_LEVEL2;
IVAR3 = EXCEP_IRQ_LEVEL3;
IVAR4 = EXCEP_IRQ_LEVEL4;
IVAR5 = EXCEP_IRQ_LEVEL5;
IVAR6 = EXCEP_IRQ_LEVEL6;
#ifndef CONFIG_MN10300_HAS_CACHE_SNOOP
mn10300_dcache_flush_inv();
mn10300_icache_inv();
#endif
#ifdef CONFIG_SMP
for (loop = 0; loop < GxICR_NUM_IRQS; loop++)
GxICR(loop) = GxICR_LEVEL_6 | GxICR_DETECT;
#else
for (loop = 0; loop < NR_IRQS; loop++)
GxICR(loop) = GxICR_LEVEL_6 | GxICR_DETECT;
#endif
TM0MD = 0;
TM1MD = 0;
TM2MD = 0;
TM3MD = 0;
TM4MD = 0;
TM5MD = 0;
TM6MD = 0;
TM6MDA = 0;
TM6MDB = 0;
TM7MD = 0;
TM8MD = 0;
TM9MD = 0;
TM10MD = 0;
TM11MD = 0;
TM12MD = 0;
TM13MD = 0;
TM14MD = 0;
TM15MD = 0;
calibrate_clock();
}
void __init get_mem_info(unsigned long *mem_base, unsigned long *mem_size)
{
unsigned long memconf = MEMCONF;
unsigned long size = 0;
*mem_base = 0x90000000;
switch (memconf & 0x00000003) {
case 0x01:
size = 256 / 8;
break;
case 0x02:
size = 512 / 8;
break;
case 0x03:
size = 1024 / 8;
break;
default:
panic("Invalid SDRAM size");
break;
}
printk(KERN_INFO "DDR2-SDRAM: %luMB x 2 @%08lx\n", size, *mem_base);
*mem_size = (size * 2) << 20;
}
