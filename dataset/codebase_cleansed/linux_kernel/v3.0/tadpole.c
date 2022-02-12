static inline unsigned int ldphys(unsigned int addr)
{
unsigned long data;
__asm__ __volatile__("\n\tlda [%1] %2, %0\n\t" :
"=r" (data) :
"r" (addr), "i" (ASI_M_BYPASS));
return data;
}
static void clk_init(void)
{
__asm__ __volatile__("mov 0x6c, %%g1\n\t"
"mov 0x4c, %%g2\n\t"
"mov 0xdf, %%g3\n\t"
"stb %%g1, [%0+3]\n\t"
"stb %%g2, [%0+3]\n\t"
"stb %%g3, [%0+3]\n\t" : :
"r" (clk_ctrl) :
"g1", "g2", "g3");
}
static void clk_slow(void)
{
__asm__ __volatile__("mov 0xcc, %%g2\n\t"
"mov 0x4c, %%g3\n\t"
"mov 0xcf, %%g4\n\t"
"mov 0xdf, %%g5\n\t"
"stb %%g2, [%0+3]\n\t"
"stb %%g3, [%0+3]\n\t"
"stb %%g4, [%0+3]\n\t"
"stb %%g5, [%0+3]\n\t" : :
"r" (clk_ctrl) :
"g2", "g3", "g4", "g5");
}
static void tsu_clockstop(void)
{
unsigned int mcsr;
unsigned long flags;
if (!clk_ctrl)
return;
if (!(clk_state & CLOCK_INIT_DONE)) {
local_irq_save(flags);
clk_init();
clk_state |= CLOCK_INIT_DONE;
local_irq_restore(flags);
return;
}
if (!(clk_ctrl[2] & 1))
return;
local_irq_save(flags);
mcsr = ldphys(MACIO_SCSI_CSR_ADDR);
if ((mcsr&MACIO_EN_DMA) != 0) {
local_irq_restore(flags);
return;
}
clk_slow();
local_irq_restore(flags);
}
static void swift_clockstop(void)
{
if (!clk_ctrl)
return;
clk_ctrl[0] = 0;
}
void __init clock_stop_probe(void)
{
phandle node, clk_nd;
char name[20];
prom_getstring(prom_root_node, "name", name, sizeof(name));
if (strncmp(name, "Tadpole", 7))
return;
node = prom_getchild(prom_root_node);
node = prom_searchsiblings(node, "obio");
node = prom_getchild(node);
clk_nd = prom_searchsiblings(node, "clk-ctrl");
if (!clk_nd)
return;
printk("Clock Stopping h/w detected... ");
clk_ctrl = (char *) prom_getint(clk_nd, "address");
clk_state = 0;
if (name[10] == '\0') {
cpu_pwr_save = tsu_clockstop;
printk("enabled (S3)\n");
} else if ((name[10] == 'X') || (name[10] == 'G')) {
cpu_pwr_save = swift_clockstop;
printk("enabled (%s)\n",name+7);
} else
printk("disabled %s\n",name+7);
}
