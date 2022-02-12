CsrTime CsrTimeGet(CsrTime *high)
{
struct timespec ts;
u64 time;
CsrTime low;
ts = current_kernel_time();
time = (u64) ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
if (high != NULL)
*high = (CsrTime) ((time >> 32) & 0xFFFFFFFF);
low = (CsrTime) (time & 0xFFFFFFFF);
return low;
}
