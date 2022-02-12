void m68ez328_reset(void)
{
local_irq_disable();
asm volatile (
"moveal #0x10c00000, %a0;\n"
"moveb #0, 0xFFFFF300;\n"
"moveal 0(%a0), %sp;\n"
"moveal 4(%a0), %a0;\n"
"jmp (%a0);\n"
);
}
void __init config_BSP(char *command, int len)
{
unsigned char *p;
pr_info("68EZ328 DragonBallEZ support (C) 1999 Rt-Control, Inc\n");
#ifdef CONFIG_UCSIMM
pr_info("uCsimm serial string [%s]\n", getserialnum());
p = cs8900a_hwaddr = gethwaddr(0);
pr_info("uCsimm hwaddr %pM\n", p);
p = getbenv("APPEND");
if (p) strcpy(p,command);
else command[0] = 0;
#endif
mach_sched_init = hw_timer_init;
mach_hwclk = m68328_hwclk;
mach_reset = m68ez328_reset;
}
