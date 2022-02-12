void CsrThreadSleep(u16 sleepTimeInMs)
{
unsigned long t;
t = ((sleepTimeInMs * HZ) + 999) / 1000;
schedule_timeout_uninterruptible(t);
}
