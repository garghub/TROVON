int F_1 ( T_1 clock , struct V_1 * V_2 )
{
long V_3 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_clock_gettime), "D" (clock), "S" (ts) : "memory");
return V_3 ;
}
int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
long V_3 ;
asm("syscall" : "=a" (ret) :
"0" (__NR_gettimeofday), "D" (tv), "S" (tz) : "memory");
return V_3 ;
}
T_2 F_3 ( T_2 * V_8 )
{
long V_9 ;
asm volatile("syscall"
: "=a" (secs)
: "0" (__NR_time), "D" (t) : "cc", "r11", "cx", "memory");
return V_9 ;
}
long
F_4 ( unsigned * V_10 , unsigned * V_11 , struct V_12 * V_13 )
{
if ( V_10 )
* V_10 = 0 ;
if ( V_11 )
* V_11 = 0 ;
return 0 ;
}
