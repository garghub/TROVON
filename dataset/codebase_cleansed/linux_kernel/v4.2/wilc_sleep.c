void WILC_Sleep(u32 u32TimeMilliSec)
{
if (u32TimeMilliSec <= 4000000) {
u32 u32Temp = u32TimeMilliSec * 1000;
usleep_range(u32Temp, u32Temp);
} else {
msleep(u32TimeMilliSec);
}
}
