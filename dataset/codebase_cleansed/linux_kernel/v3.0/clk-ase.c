unsigned int ltq_get_io_region_clock(void)
{
return CLOCK_133M;
}
unsigned int ltq_get_fpi_bus_clock(int fpi)
{
return CLOCK_133M;
}
unsigned int ltq_get_cpu_hz(void)
{
if (ltq_cgu_r32(LTQ_CGU_SYS) & (1 << 5))
return CLOCK_266M;
else
return CLOCK_133M;
}
unsigned int ltq_get_fpi_hz(void)
{
return CLOCK_133M;
}
