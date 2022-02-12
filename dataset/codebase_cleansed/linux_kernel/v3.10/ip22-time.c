static unsigned long dosample(void)
{
u32 ct0, ct1;
u8 msb;
sgint->tcword = (SGINT_TCWORD_CNT2 | SGINT_TCWORD_CALL |
SGINT_TCWORD_MRGEN);
sgint->tcnt2 = SGINT_TCSAMP_COUNTER & 0xff;
sgint->tcnt2 = SGINT_TCSAMP_COUNTER >> 8;
ct0 = read_c0_count();
do {
writeb(SGINT_TCWORD_CNT2 | SGINT_TCWORD_CLAT, &sgint->tcword);
(void) readb(&sgint->tcnt2);
msb = readb(&sgint->tcnt2);
ct1 = read_c0_count();
} while (msb);
writeb(SGINT_TCWORD_CNT2 | SGINT_TCWORD_CALL | SGINT_TCWORD_MSWST,
&sgint->tcword);
return (ct1 - ct0) / (500000/HZ) * (500000/HZ);
}
__init void plat_time_init(void)
{
unsigned long r4k_ticks[3];
unsigned long r4k_tick;
printk(KERN_INFO "Calibrating system timer... ");
dosample();
dosample();
do {
r4k_ticks[0] = dosample();
} while (!r4k_ticks[0]);
do {
r4k_ticks[1] = dosample();
} while (!r4k_ticks[1]);
if (r4k_ticks[0] != r4k_ticks[1]) {
printk("warning: timer counts differ, retrying... ");
r4k_ticks[2] = dosample();
if (r4k_ticks[2] == r4k_ticks[0]
|| r4k_ticks[2] == r4k_ticks[1])
r4k_tick = r4k_ticks[2];
else {
printk("disagreement, using average... ");
r4k_tick = (r4k_ticks[0] + r4k_ticks[1]
+ r4k_ticks[2]) / 3;
}
} else
r4k_tick = r4k_ticks[0];
printk("%d [%d.%04d MHz CPU]\n", (int) r4k_tick,
(int) (r4k_tick / (500000 / HZ)),
(int) (r4k_tick % (500000 / HZ)));
mips_hpt_frequency = r4k_tick * HZ;
if (ip22_is_fullhouse())
setup_pit_timer();
}
void __irq_entry indy_8254timer_irq(void)
{
int irq = SGI_8254_0_IRQ;
ULONG cnt;
char c;
irq_enter();
kstat_incr_irqs_this_cpu(irq, irq_to_desc(irq));
printk(KERN_ALERT "Oops, got 8254 interrupt.\n");
ArcRead(0, &c, 1, &cnt);
ArcEnterInteractiveMode();
irq_exit();
}
