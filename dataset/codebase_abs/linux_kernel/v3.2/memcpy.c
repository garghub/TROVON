void * memcpy ( void * V_1 , const void * V_2 , T_1 V_3 )
{
void * V_4 = V_1 ;
T_1 V_5 , V_6 ;
if ( ! V_3 )
return V_4 ;
if ( ( long ) V_1 & 1 ) {
char * V_7 = V_1 ;
const char * V_8 = V_2 ;
* V_7 ++ = * V_8 ++ ;
V_1 = V_7 ;
V_2 = V_8 ;
V_3 -- ;
}
#if F_1 ( V_9 )
if ( ( long ) V_2 & 1 ) {
char * V_7 = V_1 ;
const char * V_8 = V_2 ;
for (; V_3 ; V_3 -- )
* V_7 ++ = * V_8 ++ ;
return V_4 ;
}
#endif
if ( V_3 > 2 && ( long ) V_1 & 2 ) {
short * V_10 = V_1 ;
const short * V_11 = V_2 ;
* V_10 ++ = * V_11 ++ ;
V_1 = V_10 ;
V_2 = V_11 ;
V_3 -= 2 ;
}
V_5 = V_3 >> 2 ;
if ( V_5 ) {
long * V_12 = V_1 ;
const long * V_13 = V_2 ;
#if F_1 ( V_9 ) || F_1 ( V_14 )
for (; V_5 ; V_5 -- )
* V_12 ++ = * V_13 ++ ;
#else
asm volatile (
" movel %2,%3\n"
" andw #7,%3\n"
" lsrl #3,%2\n"
" negw %3\n"
" jmp %%pc@(1f,%3:w:2)\n"
"4: movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
" movel %0@+,%1@+\n"
"1: dbra %2,4b\n"
" clrw %2\n"
" subql #1,%2\n"
" jpl 4b"
: "=a" (lfrom), "=a" (lto), "=d" (temp), "=&d" (temp1)
: "0" (lfrom), "1" (lto), "2" (temp));
#endif
V_1 = V_12 ;
V_2 = V_13 ;
}
if ( V_3 & 2 ) {
short * V_10 = V_1 ;
const short * V_11 = V_2 ;
* V_10 ++ = * V_11 ++ ;
V_1 = V_10 ;
V_2 = V_11 ;
}
if ( V_3 & 1 ) {
char * V_7 = V_1 ;
const char * V_8 = V_2 ;
* V_7 = * V_8 ;
}
return V_4 ;
}
