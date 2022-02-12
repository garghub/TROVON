void nlm_hal_init(void)
{
nlm_io_base = CKSEG1ADDR(XLP_DEFAULT_IO_BASE);
nlm_sys_base = nlm_get_sys_regbase(0);
nlm_pic_base = nlm_get_pic_regbase(0);
}
int nlm_irq_to_irt(int irq)
{
if (!PIC_IRQ_IS_IRT(irq))
return -1;
switch (irq) {
case PIC_UART_0_IRQ:
return PIC_IRT_UART_0_INDEX;
case PIC_UART_1_IRQ:
return PIC_IRT_UART_1_INDEX;
default:
return -1;
}
}
int nlm_irt_to_irq(int irt)
{
switch (irt) {
case PIC_IRT_UART_0_INDEX:
return PIC_UART_0_IRQ;
case PIC_IRT_UART_1_INDEX:
return PIC_UART_1_IRQ;
default:
return -1;
}
}
unsigned int nlm_get_core_frequency(int core)
{
unsigned int pll_divf, pll_divr, dfs_div, ext_div;
unsigned int rstval, dfsval, denom;
uint64_t num;
rstval = nlm_read_sys_reg(nlm_sys_base, SYS_POWER_ON_RESET_CFG);
dfsval = nlm_read_sys_reg(nlm_sys_base, SYS_CORE_DFS_DIV_VALUE);
pll_divf = ((rstval >> 10) & 0x7f) + 1;
pll_divr = ((rstval >> 8) & 0x3) + 1;
ext_div = ((rstval >> 30) & 0x3) + 1;
dfs_div = ((dfsval >> (core * 4)) & 0xf) + 1;
num = 800000000ULL * pll_divf;
denom = 3 * pll_divr * ext_div * dfs_div;
do_div(num, denom);
return (unsigned int)num;
}
unsigned int nlm_get_cpu_frequency(void)
{
return nlm_get_core_frequency(0);
}
