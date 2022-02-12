u32 CsrTimeGet(u32 *high)
{
struct timespec ts;
u64 time;
u32 low;
ts = current_kernel_time();
time = (u64) ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
if (high != NULL)
*high = (u32) ((time >> 32) & 0xFFFFFFFF);
low = (u32) (time & 0xFFFFFFFF);
return low;
}
