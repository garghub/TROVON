void
__delay(int loops)
{
int tmp;
__asm__ __volatile__(
" rpcc %0\n"
" addl %1,%0,%1\n"
"1: rpcc %0\n"
" subl %1,%0,%0\n"
" bgt %0,1b"
: "=&r" (tmp), "=r" (loops) : "1"(loops));
}
void
udelay(unsigned long usecs)
{
usecs *= (((unsigned long)HZ << 32) / 1000000) * LPJ;
__delay((long)usecs >> 32);
}
void
ndelay(unsigned long nsecs)
{
nsecs *= (((unsigned long)HZ << 32) / 1000000000) * LPJ;
__delay((long)nsecs >> 32);
}
