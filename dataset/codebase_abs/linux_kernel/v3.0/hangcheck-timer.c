static int T_1 F_1 ( char * V_1 )
{
int V_2 ;
if ( F_2 ( & V_1 , & V_2 ) )
V_3 = V_2 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
int V_2 ;
if ( F_2 ( & V_1 , & V_2 ) )
V_4 = V_2 ;
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
int V_2 ;
if ( F_2 ( & V_1 , & V_2 ) )
V_5 = V_2 ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
int V_2 ;
if ( F_2 ( & V_1 , & V_2 ) )
V_6 = V_2 ;
return 1 ;
}
static inline unsigned long long F_6 ( void )
{
struct V_7 V_8 ;
F_7 ( & V_8 ) ;
return F_8 ( & V_8 ) ;
}
static void F_9 ( unsigned long V_9 )
{
unsigned long long V_10 , V_11 ;
V_10 = F_6 () ;
if ( V_10 > V_12 )
V_11 = V_10 - V_12 ;
else
V_11 = ( V_10 + ( ~ 0ULL - V_12 ) ) ;
if ( V_11 > V_13 ) {
if ( V_6 ) {
F_10 ( V_14 L_1 ) ;
#ifdef F_11
F_12 ( 't' ) ;
#endif
}
if ( V_5 ) {
F_10 ( V_14 L_2 ) ;
F_13 () ;
} else {
F_10 ( V_14 L_3 ) ;
}
}
#if 0
printk("Hangcheck: called %Ld ns since last time (%Ld ns overshoot)\n",
tsc_diff, tsc_diff - hangcheck_tick*TIMER_FREQ);
#endif
F_14 ( & V_15 , V_16 + ( V_3 * V_17 ) ) ;
V_12 = F_6 () ;
}
static int T_1 F_15 ( void )
{
F_10 ( L_4 ,
V_18 , V_3 , V_4 ) ;
#if F_16 ( V_19 )
F_10 ( L_5 ) ;
#else
F_10 ( L_6 ) ;
#endif
V_13 =
( unsigned long long ) ( V_4 + V_3 ) ;
V_13 *= ( unsigned long long ) V_20 ;
V_12 = F_6 () ;
F_14 ( & V_15 , V_16 + ( V_3 * V_17 ) ) ;
return 0 ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_15 ) ;
F_10 ( L_7 ) ;
}
