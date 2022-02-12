static cycle_t read_hrt(struct clocksource *cs)
{
return (cycle_t) inl(scx200_cb_base + SCx200_TIMER_OFFSET);
}
static int __init init_hrt_clocksource(void)
{
u32 freq;
if (!scx200_cb_present())
return -ENODEV;
if (!request_region(scx200_cb_base + SCx200_TIMER_OFFSET,
SCx200_TIMER_SIZE,
"NatSemi SCx200 High-Resolution Timer")) {
pr_warn("unable to lock timer region\n");
return -ENODEV;
}
outb(HR_TMEN | (mhz27 ? HR_TMCLKSEL : 0),
scx200_cb_base + SCx200_TMCNFG_OFFSET);
freq = (HRT_FREQ + ppm);
if (mhz27)
freq *= 27;
pr_info("enabling scx200 high-res timer (%s MHz +%d ppm)\n", mhz27 ? "27":"1", ppm);
return clocksource_register_hz(&cs_hrt, freq);
}
