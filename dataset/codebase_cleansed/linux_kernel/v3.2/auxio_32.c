void __init auxio_probe(void)
{
phandle node, auxio_nd;
struct linux_prom_registers auxregs[1];
struct resource r;
switch (sparc_cpu_model) {
case sparc_leon:
case sun4d:
case sun4:
return;
default:
break;
}
node = prom_getchild(prom_root_node);
auxio_nd = prom_searchsiblings(node, "auxiliary-io");
if(!auxio_nd) {
node = prom_searchsiblings(node, "obio");
node = prom_getchild(node);
auxio_nd = prom_searchsiblings(node, "auxio");
if(!auxio_nd) {
#ifdef CONFIG_PCI
return;
#else
if(prom_searchsiblings(node, "leds")) {
return;
}
prom_printf("Cannot find auxio node, cannot continue...\n");
prom_halt();
#endif
}
}
if(prom_getproperty(auxio_nd, "reg", (char *) auxregs, sizeof(auxregs)) <= 0)
return;
prom_apply_obio_ranges(auxregs, 0x1);
r.flags = auxregs[0].which_io & 0xF;
r.start = auxregs[0].phys_addr;
r.end = auxregs[0].phys_addr + auxregs[0].reg_size - 1;
auxio_register = of_ioremap(&r, 0, auxregs[0].reg_size, "auxio");
if((((unsigned long) auxregs[0].phys_addr) & 3) == 3 ||
sparc_cpu_model == sun4c)
auxio_register += (3 - ((unsigned long)auxio_register & 3));
set_auxio(AUXIO_LED, 0);
}
unsigned char get_auxio(void)
{
if(auxio_register)
return sbus_readb(auxio_register);
return 0;
}
void set_auxio(unsigned char bits_on, unsigned char bits_off)
{
unsigned char regval;
unsigned long flags;
spin_lock_irqsave(&auxio_lock, flags);
switch(sparc_cpu_model) {
case sun4c:
regval = sbus_readb(auxio_register);
sbus_writeb(((regval | bits_on) & ~bits_off) | AUXIO_ORMEIN,
auxio_register);
break;
case sun4m:
if(!auxio_register)
break;
regval = sbus_readb(auxio_register);
sbus_writeb(((regval | bits_on) & ~bits_off) | AUXIO_ORMEIN4M,
auxio_register);
break;
case sun4d:
break;
default:
panic("Can't set AUXIO register on this machine.");
}
spin_unlock_irqrestore(&auxio_lock, flags);
}
void __init auxio_power_probe(void)
{
struct linux_prom_registers regs;
phandle node;
struct resource r;
node = prom_getchild(prom_root_node);
node = prom_searchsiblings(node, "obio");
node = prom_getchild(node);
node = prom_searchsiblings(node, "power");
if (node == 0 || (s32)node == -1)
return;
if (prom_getproperty(node, "reg", (char *)&regs, sizeof(regs)) <= 0)
return;
prom_apply_obio_ranges(&regs, 1);
memset(&r, 0, sizeof(r));
r.flags = regs.which_io & 0xF;
r.start = regs.phys_addr;
r.end = regs.phys_addr + regs.reg_size - 1;
auxio_power_register = (unsigned char *) of_ioremap(&r, 0,
regs.reg_size, "auxpower");
if (auxio_power_register)
printk(KERN_INFO "Power off control detected.\n");
}
