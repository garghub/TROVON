static inline cycles_t get_cycles_inline(void)
{
unsigned int high = __insn_mfspr(SPR_CYCLE_HIGH);
unsigned int low = __insn_mfspr(SPR_CYCLE_LOW);
unsigned int high2 = __insn_mfspr(SPR_CYCLE_HIGH);
while (unlikely(high != high2)) {
low = __insn_mfspr(SPR_CYCLE_LOW);
high = high2;
high2 = __insn_mfspr(SPR_CYCLE_HIGH);
}
return (((cycles_t)high) << 32) | low;
}
inline unsigned long get_datapage(void)
{
unsigned long ret;
asm volatile ("lnk %0" : "=r"(ret));
ret &= ~(PAGE_SIZE - 1);
ret += PAGE_SIZE;
return ret;
}
int __vdso_gettimeofday(struct timeval *tv, struct timezone *tz)
{
cycles_t cycles;
unsigned long count, sec, ns;
volatile struct vdso_data *vdso_data;
vdso_data = (struct vdso_data *)get_datapage();
if (unlikely(tz != NULL)) {
while (1) {
count = vdso_data->tz_update_count;
if (count & 1)
continue;
tz->tz_minuteswest = vdso_data->tz_minuteswest;
tz->tz_dsttime = vdso_data->tz_dsttime;
if (count == vdso_data->tz_update_count)
break;
}
}
if (unlikely(tv == NULL))
return 0;
while (1) {
count = vdso_data->tb_update_count;
if (count & 1)
continue;
sec = vdso_data->xtime_clock_sec;
cycles = get_cycles() - vdso_data->xtime_tod_stamp;
ns = (cycles * vdso_data->mult) + vdso_data->xtime_clock_nsec;
ns >>= vdso_data->shift;
if (ns >= NSEC_PER_SEC) {
ns -= NSEC_PER_SEC;
sec += 1;
}
if (count == vdso_data->tb_update_count)
break;
}
tv->tv_sec = sec;
tv->tv_usec = ns / 1000;
return 0;
}
