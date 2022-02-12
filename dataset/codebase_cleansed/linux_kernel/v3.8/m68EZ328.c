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
void config_BSP(char *command, int len)
{
unsigned char *p;
printk(KERN_INFO "\n68EZ328 DragonBallEZ support (C) 1999 Rt-Control, Inc\n");
#ifdef CONFIG_UCSIMM
printk(KERN_INFO "uCsimm serial string [%s]\n",getserialnum());
p = cs8900a_hwaddr = gethwaddr(0);
printk(KERN_INFO "uCsimm hwaddr %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
p[0], p[1], p[2], p[3], p[4], p[5]);
p = getbenv("APPEND");
if (p) strcpy(p,command);
else command[0] = 0;
#endif
mach_hwclk = m68328_hwclk;
mach_reset = m68ez328_reset;
}
