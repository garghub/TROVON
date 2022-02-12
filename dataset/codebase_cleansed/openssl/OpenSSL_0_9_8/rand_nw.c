int RAND_poll(void)
{
unsigned long l;
unsigned long tsc;
int i;
l = GetProcessSwitchCount();
RAND_add(&l,sizeof(l),1);
l=RunningProcess;
RAND_add(&l,sizeof(l),1);
for( i=2; i<ENTROPY_NEEDED; i++)
{
#ifdef __MWERKS__
asm
{
rdtsc
mov tsc, eax
}
#else
asm volatile("rdtsc":"=A" (tsc));
#endif
RAND_add(&tsc, sizeof(tsc), 1);
l = GetSuperHighResolutionTimer();
RAND_add(&l, sizeof(l), 0);
# if defined(NETWARE_LIBC)
NXThreadYield();
# else
ThreadSwitchWithDelay();
# endif
}
return 1;
}
