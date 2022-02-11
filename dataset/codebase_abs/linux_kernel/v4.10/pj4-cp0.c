static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
switch ( V_3 ) {
case V_7 :
case V_8 :
F_2 ( V_6 ) ;
break;
case V_9 :
F_3 ( V_6 ) ;
break;
}
return V_10 ;
}
static T_1 T_2 F_4 ( void )
{
T_1 V_11 ;
__asm__ __volatile__ (
"mrc p15, 0, %0, c1, c0, 2\n\t"
: "=r" (value));
return V_11 ;
}
static void T_2 F_5 ( T_1 V_11 )
{
T_1 V_12 ;
__asm__ __volatile__ (
"mcr p15, 0, %1, c1, c0, 2\n\t"
#ifdef F_6
"isb\n\t"
#else
"mrc p15, 0, %0, c1, c0, 2\n\t"
"mov %0, %0\n\t"
"sub pc, pc, #4\n\t"
#endif
: "=r" (temp) : "r" (value));
}
static int T_2 F_7 ( void )
{
T_1 V_13 , V_14 ;
V_13 = F_4 () ;
F_5 ( V_13 | 0xf ) ;
if ( ( F_4 () & 0xf ) != 0xf ) {
F_5 ( V_13 ) ;
return - V_15 ;
}
__asm__ __volatile__ ("mrc p1, 0, %0, c0, c0, 0\n" : "=r" (wcid));
F_5 ( V_13 ) ;
if ( ( V_14 & 0xffffff00 ) == 0x56051000 )
return 1 ;
if ( ( V_14 & 0xffffff00 ) == 0x56052000 )
return 2 ;
return - V_16 ;
}
static int T_2 F_8 ( void )
{
T_1 T_3 V_13 ;
int V_17 ;
if ( ! F_9 () )
return 0 ;
V_17 = F_7 () ;
if ( V_17 < 0 )
return 0 ;
#ifndef F_10
F_11 ( L_1 ) ;
#else
V_13 = F_4 () & ~ 0xf ;
F_5 ( V_13 ) ;
F_11 ( L_2 , V_17 ) ;
V_18 |= V_19 ;
F_12 ( & V_20 ) ;
#endif
return 0 ;
}
