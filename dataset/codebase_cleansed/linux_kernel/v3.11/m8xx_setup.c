static irqreturn_t timebase_interrupt(int irq, void *dev)
{
printk ("timebase_interrupt()\n");
return IRQ_HANDLED;
}
static int __init get_freq(char *name, unsigned long *val)
{
struct device_node *cpu;
const unsigned int *fp;
int found = 0;
cpu = of_find_node_by_type(NULL, "cpu");
if (cpu) {
fp = of_get_property(cpu, name, NULL);
if (fp) {
found = 1;
*val = *fp;
}
of_node_put(cpu);
}
return found;
}
void __init mpc8xx_calibrate_decr(void)
{
struct device_node *cpu;
cark8xx_t __iomem *clk_r1;
car8xx_t __iomem *clk_r2;
sitk8xx_t __iomem *sys_tmr1;
sit8xx_t __iomem *sys_tmr2;
int irq, virq;
clk_r1 = immr_map(im_clkrstk);
out_be32(&clk_r1->cark_sccrk, ~KAPWR_KEY);
out_be32(&clk_r1->cark_sccrk, KAPWR_KEY);
immr_unmap(clk_r1);
clk_r2 = immr_map(im_clkrst);
setbits32(&clk_r2->car_sccr, 0x02000000);
immr_unmap(clk_r2);
ppc_proc_freq = 50000000;
if (!get_freq("clock-frequency", &ppc_proc_freq))
printk(KERN_ERR "WARNING: Estimating processor frequency "
"(not found)\n");
ppc_tb_freq = ppc_proc_freq / 16;
printk("Decrementer Frequency = 0x%lx\n", ppc_tb_freq);
sys_tmr1 = immr_map(im_sitk);
out_be32(&sys_tmr1->sitk_tbscrk, ~KAPWR_KEY);
out_be32(&sys_tmr1->sitk_rtcsck, ~KAPWR_KEY);
out_be32(&sys_tmr1->sitk_tbk, ~KAPWR_KEY);
out_be32(&sys_tmr1->sitk_tbscrk, KAPWR_KEY);
out_be32(&sys_tmr1->sitk_rtcsck, KAPWR_KEY);
out_be32(&sys_tmr1->sitk_tbk, KAPWR_KEY);
immr_unmap(sys_tmr1);
init_internal_rtc();
cpu = of_find_node_by_type(NULL, "cpu");
virq= irq_of_parse_and_map(cpu, 0);
irq = virq_to_hw(virq);
sys_tmr2 = immr_map(im_sit);
out_be16(&sys_tmr2->sit_tbscr, ((1 << (7 - (irq/2))) << 8) |
(TBSCR_TBF | TBSCR_TBE));
immr_unmap(sys_tmr2);
if (setup_irq(virq, &tbint_irqaction))
panic("Could not allocate timer IRQ!");
}
int mpc8xx_set_rtc_time(struct rtc_time *tm)
{
sitk8xx_t __iomem *sys_tmr1;
sit8xx_t __iomem *sys_tmr2;
int time;
sys_tmr1 = immr_map(im_sitk);
sys_tmr2 = immr_map(im_sit);
time = mktime(tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
out_be32(&sys_tmr1->sitk_rtck, KAPWR_KEY);
out_be32(&sys_tmr2->sit_rtc, time);
out_be32(&sys_tmr1->sitk_rtck, ~KAPWR_KEY);
immr_unmap(sys_tmr2);
immr_unmap(sys_tmr1);
return 0;
}
void mpc8xx_get_rtc_time(struct rtc_time *tm)
{
unsigned long data;
sit8xx_t __iomem *sys_tmr = immr_map(im_sit);
data = in_be32(&sys_tmr->sit_rtc);
to_tm(data, tm);
tm->tm_year -= 1900;
tm->tm_mon -= 1;
immr_unmap(sys_tmr);
return;
}
void mpc8xx_restart(char *cmd)
{
car8xx_t __iomem *clk_r = immr_map(im_clkrst);
local_irq_disable();
setbits32(&clk_r->car_plprcr, 0x00000080);
mtmsr(mfmsr() & ~0x1000);
in_8(&clk_r->res[0]);
panic("Restart failed\n");
}
static void cpm_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
int cascade_irq = cpm_get_irq();
if (cascade_irq >= 0)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
void __init mpc8xx_pics_init(void)
{
int irq;
if (mpc8xx_pic_init()) {
printk(KERN_ERR "Failed interrupt 8xx controller initialization\n");
return;
}
irq = cpm_pic_init();
if (irq != NO_IRQ)
irq_set_chained_handler(irq, cpm_cascade);
}
