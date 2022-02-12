static cycle_t dec_ioasic_hpt_read(struct clocksource *cs)
{
return ioasic_read(IO_REG_FCTR);
}
static u64 notrace dec_ioasic_read_sched_clock(void)
{
return ioasic_read(IO_REG_FCTR);
}
int __init dec_ioasic_clocksource_init(void)
{
unsigned int freq;
u32 start, end;
int i = HZ / 8;
ds1287_timer_state();
while (!ds1287_timer_state())
;
start = dec_ioasic_hpt_read(&clocksource_dec);
while (i--)
while (!ds1287_timer_state())
;
end = dec_ioasic_hpt_read(&clocksource_dec);
freq = (end - start) * 8;
if (!freq)
return -ENXIO;
printk(KERN_INFO "I/O ASIC clock frequency %dHz\n", freq);
clocksource_dec.rating = 200 + freq / 10000000;
clocksource_register_hz(&clocksource_dec, freq);
sched_clock_register(dec_ioasic_read_sched_clock, 32, freq);
return 0;
}
