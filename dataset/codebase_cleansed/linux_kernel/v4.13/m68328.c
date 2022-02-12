void m68328_reset (void)
{
local_irq_disable();
asm volatile ("moveal #0x10c00000, %a0;\n\t"
"moveb #0, 0xFFFFF300;\n\t"
"moveal 0(%a0), %sp;\n\t"
"moveal 4(%a0), %a0;\n\t"
"jmp (%a0);");
}
void __init config_BSP(char *command, int len)
{
pr_info("68328 support D. Jeff Dionne <jeff@uclinux.org>\n");
pr_info("68328 support Kenneth Albanowski <kjahds@kjshds.com>\n");
pr_info("68328/Pilot support Bernhard Kuhn <kuhn@lpr.e-technik.tu-muenchen.de>\n");
mach_hwclk = m68328_hwclk;
mach_reset = m68328_reset;
}
