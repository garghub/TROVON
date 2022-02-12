void msp7120_reset(void)
{
void *start, *end, *iptr;
register int i;
local_irq_disable();
#ifdef CONFIG_SYS_SUPPORTS_MULTITHREADING
dvpe();
#endif
__asm__ __volatile__ (
" .set push \n"
" .set arch=r4000 \n"
" la %0,startpoint \n"
" la %1,endpoint \n"
" .set pop \n"
: "=r" (start), "=r" (end)
:
);
for (iptr = (void *)((unsigned int)start & ~(L1_CACHE_BYTES - 1));
iptr < end; iptr += L1_CACHE_BYTES)
cache_op(Fill, iptr);
__asm__ __volatile__ (
"startpoint: \n"
);
DDRC_INDIRECT_WRITE(DDRC_CTL(10), 0xb, 1 << 16);
for (i = 0; i < 100000000; i++);
#if defined(CONFIG_PMC_MSP7120_GW)
set_value_reg32(GPIO_CFG3_REG, 0xf000, 0x8000);
set_reg32(GPIO_DATA3_REG, 8);
#endif
*RST_SET_REG = 0x00000001;
__asm__ __volatile__ (
"endpoint: \n"
);
}
void msp_restart(char *command)
{
printk(KERN_WARNING "Now rebooting .......\n");
#if defined(CONFIG_PMC_MSP7120_EVAL) || \
defined(CONFIG_PMC_MSP7120_GW) || \
defined(CONFIG_PMC_MSP7120_FPGA)
msp7120_reset();
#else
set_c0_status(ST0_BEV | ST0_ERL);
change_c0_config(CONF_CM_CMASK, CONF_CM_UNCACHED);
flush_cache_all();
write_c0_wired(0);
__asm__ __volatile__("jr\t%0"::"r"(0xbfc00000));
#endif
}
void msp_halt(void)
{
printk(KERN_WARNING "\n** You can safely turn off the power\n");
while (1)
if (cpu_wait)
(*cpu_wait)();
else
__asm__(".set\tmips3\n\t" "wait\n\t" ".set\tmips0");
}
void msp_power_off(void)
{
msp_halt();
}
void __init plat_mem_setup(void)
{
_machine_restart = msp_restart;
_machine_halt = msp_halt;
pm_power_off = msp_power_off;
}
void __init prom_init(void)
{
unsigned long family;
unsigned long revision;
prom_argc = fw_arg0;
prom_argv = (char **)fw_arg1;
prom_envp = (char **)fw_arg2;
family = identify_family();
revision = identify_revision();
switch (family) {
case FAMILY_FPGA:
if (FPGA_IS_MSP4200(revision)) {
mips_machtype = MACH_MSP4200_FPGA;
} else {
mips_machtype = MACH_MSP_OTHER;
}
break;
case FAMILY_MSP4200:
#if defined(CONFIG_PMC_MSP4200_EVAL)
mips_machtype = MACH_MSP4200_EVAL;
#elif defined(CONFIG_PMC_MSP4200_GW)
mips_machtype = MACH_MSP4200_GW;
#else
mips_machtype = MACH_MSP_OTHER;
#endif
break;
case FAMILY_MSP4200_FPGA:
mips_machtype = MACH_MSP4200_FPGA;
break;
case FAMILY_MSP7100:
#if defined(CONFIG_PMC_MSP7120_EVAL)
mips_machtype = MACH_MSP7120_EVAL;
#elif defined(CONFIG_PMC_MSP7120_GW)
mips_machtype = MACH_MSP7120_GW;
#else
mips_machtype = MACH_MSP_OTHER;
#endif
break;
case FAMILY_MSP7100_FPGA:
mips_machtype = MACH_MSP7120_FPGA;
break;
default:
mips_machtype = MACH_UNKNOWN;
panic("***Bogosity factor five***, exiting");
break;
}
prom_init_cmdline();
prom_meminit();
msp_serial_setup();
register_vsmp_smp_ops();
}
