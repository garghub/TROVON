static inline void F_1 ( T_1 * V_1 )
{
__asm__ __volatile__ (
"mrrc p0, 0, %0, %1, c0\n"
: "=r" (state[0]), "=r" (state[1]));
}
static inline void F_2 ( T_1 * V_1 )
{
__asm__ __volatile__ (
"mcrr p0, 0, %0, %1, c0\n"
: : "r" (state[0]), "r" (state[1]));
}
static int F_3 ( struct V_2 * V_3 , unsigned long V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
switch ( V_4 ) {
case V_8 :
V_7 -> V_9 . V_10 [ 0 ] = 0 ;
V_7 -> V_9 . V_10 [ 1 ] = 0 ;
break;
case V_11 :
F_1 ( F_4 () -> V_9 . V_10 ) ;
F_2 ( V_7 -> V_9 . V_10 ) ;
break;
}
return V_12 ;
}
static int F_5 ( struct V_2 * V_3 , unsigned long V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
switch ( V_4 ) {
case V_8 :
case V_13 :
F_6 ( V_7 ) ;
break;
case V_11 :
F_7 ( V_7 ) ;
break;
}
return V_12 ;
}
static T_1 T_2 F_8 ( void )
{
T_1 V_14 ;
__asm__ __volatile__ (
"mrc p15, 0, %0, c15, c1, 0\n\t"
: "=r" (value));
return V_14 ;
}
static void T_2 F_9 ( T_1 V_14 )
{
T_1 V_15 ;
__asm__ __volatile__ (
"mcr p15, 0, %1, c15, c1, 0\n\t"
"mrc p15, 0, %0, c15, c1, 0\n\t"
"mov %0, %0\n\t"
"sub pc, pc, #4\n\t"
: "=r" (temp) : "r" (value));
}
static int T_2 F_10 ( void )
{
T_1 V_16 ;
T_1 V_17 ;
__asm__ __volatile__ (
"mcrr p0, 0, %2, %3, c0\n"
"mrrc p0, 0, %0, %1, c0\n"
: "=r" (lo), "=r" (hi)
: "r" (0), "r" (0x100));
return ! ! V_17 ;
}
static int T_2 F_11 ( void )
{
T_1 V_18 ;
V_18 = F_8 () & ~ 3 ;
F_9 ( V_18 | 1 ) ;
if ( F_10 () ) {
#ifndef F_12
F_13 ( V_19 L_1
L_2 ) ;
#else
F_13 ( V_20 L_3 ) ;
V_21 |= V_22 ;
F_14 ( & V_23 ) ;
#endif
} else {
F_13 ( V_20 L_4 ) ;
F_14 ( & V_24 ) ;
V_18 |= 1 ;
}
F_9 ( V_18 ) ;
return 0 ;
}
