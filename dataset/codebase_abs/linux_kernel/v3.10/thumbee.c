static inline unsigned long F_1 ( void )
{
unsigned long V_1 ;
asm("mrc p14, 6, %0, c1, c0, 0\n" : "=r" (v));
return V_1 ;
}
static inline void F_2 ( unsigned long V_1 )
{
asm("mcr p14, 6, %0, c1, c0, 0\n" : : "r" (v));
}
static int F_3 ( struct V_2 * V_3 , unsigned long V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
switch ( V_4 ) {
case V_8 :
V_7 -> V_9 = 0 ;
break;
case V_10 :
F_4 () -> V_9 = F_1 () ;
F_2 ( V_7 -> V_9 ) ;
break;
}
return V_11 ;
}
static int T_1 F_5 ( void )
{
unsigned long V_12 ;
unsigned int V_13 = F_6 () ;
if ( V_13 < V_14 )
return 0 ;
V_12 = F_7 ( V_15 ) ;
if ( ( V_12 & 0x0000f000 ) != 0x00001000 )
return 0 ;
F_8 ( V_16 L_1 ) ;
V_17 |= V_18 ;
F_9 ( & V_19 ) ;
return 0 ;
}
