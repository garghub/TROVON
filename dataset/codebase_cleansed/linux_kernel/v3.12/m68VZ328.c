static void m68vz328_reset(void)
{
local_irq_disable();
#ifdef CONFIG_INIT_LCD
PBDATA |= 0x20;
PKDATA |= 0x4;
LCKCON = 0;
#endif
__asm__ __volatile__(
"reset\n\t"
"moveal #0x04000000, %a0\n\t"
"moveal 0(%a0), %sp\n\t"
"moveal 4(%a0), %a0\n\t"
"jmp (%a0)"
);
}
static void __init init_hardware(char *command, int size)
{
#ifdef CONFIG_DIRECT_IO_ACCESS
SCR = 0x10;
#endif
CSGBB = 0x4000;
CSB = 0x1a1;
PKSEL |= PK(3);
PKDIR |= PK(3);
PKDATA |= PK(3);
PFSEL |= PF(5);
PFDIR |= PF(5);
PFDATA &= ~PF(5);
PFDATA |= PF(5);
{ int i; for (i = 0; i < 32000; ++i); }
PFDATA &= ~PF(5);
PDPOL &= ~PD(1);
PDIQEG &= ~PD(1);
PDIRQEN |= PD(1);
#ifdef CONFIG_INIT_LCD
LSSA = (long) screen_bits;
LVPW = 0x14;
LXMAX = 0x140;
LYMAX = 0xef;
LRRA = 0;
LPXCD = 3;
LPICF = 0x08;
LPOLCF = 0;
LCKCON = 0x80;
PCPDEN = 0xff;
PCSEL = 0;
PKDIR |= 0x4;
PKSEL |= 0x4;
PKDATA &= ~0x4;
PBDIR |= 0x20;
PBSEL |= 0x20;
PBDATA &= ~0x20;
PFDIR |= 0x1;
PFSEL &= ~0x1;
PWMR = 0x037F;
#endif
}
static void m68vz328_reset(void)
{
local_irq_disable();
asm volatile (
"moveal #0x10c00000, %a0;\n\t"
"moveb #0, 0xFFFFF300;\n\t"
"moveal 0(%a0), %sp;\n\t"
"moveal 4(%a0), %a0;\n\t"
"jmp (%a0);\n"
);
}
static void __init init_hardware(char *command, int size)
{
char *p;
printk(KERN_INFO "uCdimm serial string [%s]\n", getserialnum());
p = cs8900a_hwaddr = gethwaddr(0);
printk(KERN_INFO "uCdimm hwaddr %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
p[0], p[1], p[2], p[3], p[4], p[5]);
p = getbenv("APPEND");
if (p)
strcpy(p, command);
else
command[0] = 0;
}
static void m68vz328_reset(void)
{
}
static void __init init_hardware(char *command, int size)
{
}
void __init config_BSP(char *command, int size)
{
printk(KERN_INFO "68VZ328 DragonBallVZ support (c) 2001 Lineo, Inc.\n");
init_hardware(command, size);
mach_hwclk = m68328_hwclk;
mach_reset = m68vz328_reset;
}
