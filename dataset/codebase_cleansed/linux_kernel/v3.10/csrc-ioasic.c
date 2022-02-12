static cycle_t dec_ioasic_hpt_read(struct clocksource *cs)
{
return ioasic_read(IO_REG_FCTR);
}
void __init dec_ioasic_clocksource_init(void)
{
unsigned int freq;
u32 start, end;
int i = HZ / 10;
while (!ds1287_timer_state())
;
start = dec_ioasic_hpt_read(&clocksource_dec);
while (i--)
while (!ds1287_timer_state())
;
end = dec_ioasic_hpt_read(&clocksource_dec);
freq = (end - start) * 10;
printk(KERN_INFO "I/O ASIC clock frequency %dHz\n", freq);
clocksource_dec.rating = 200 + freq / 10000000;
clocksource_register_hz(&clocksource_dec, freq);
}
