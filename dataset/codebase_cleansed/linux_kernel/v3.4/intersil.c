unsigned long sun3_gettimeoffset(void)
{
return 1;
}
int sun3_hwclk(int set, struct rtc_time *t)
{
volatile struct intersil_dt *todintersil;
unsigned long flags;
todintersil = (struct intersil_dt *) &intersil_clock->counter;
local_irq_save(flags);
intersil_clock->cmd_reg = STOP_VAL;
if(set) {
todintersil->csec = 0;
todintersil->hour = t->tm_hour;
todintersil->minute = t->tm_min;
todintersil->second = t->tm_sec;
todintersil->month = t->tm_mon;
todintersil->day = t->tm_mday;
todintersil->year = t->tm_year - 68;
todintersil->weekday = t->tm_wday;
} else {
t->tm_sec = todintersil->csec;
t->tm_hour = todintersil->hour;
t->tm_min = todintersil->minute;
t->tm_sec = todintersil->second;
t->tm_mon = todintersil->month;
t->tm_mday = todintersil->day;
t->tm_year = todintersil->year + 68;
t->tm_wday = todintersil->weekday;
}
intersil_clock->cmd_reg = START_VAL;
local_irq_restore(flags);
return 0;
}
