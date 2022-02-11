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
static void F_6 ( unsigned long V_7 )
{
unsigned long long V_8 , V_9 ;
V_8 = F_7 () ;
if ( V_8 > V_10 )
V_9 = V_8 - V_10 ;
else
V_9 = ( V_8 + ( ~ 0ULL - V_10 ) ) ;
if ( V_9 > V_11 ) {
if ( V_6 ) {
F_8 ( V_12 L_1 ) ;
#ifdef F_9
F_10 ( 't' ) ;
#endif
}
if ( V_5 ) {
F_8 ( V_12 L_2 ) ;
F_11 () ;
} else {
F_8 ( V_12 L_3 ) ;
}
}
#if 0
printk("Hangcheck: called %Ld ns since last time (%Ld ns overshoot)\n",
tsc_diff, tsc_diff - hangcheck_tick*TIMER_FREQ);
#endif
F_12 ( & V_13 , V_14 + ( V_3 * V_15 ) ) ;
V_10 = F_7 () ;
}
static int T_1 F_13 ( void )
{
F_8 ( L_4 ,
V_16 , V_3 , V_4 ) ;
V_11 =
( unsigned long long ) V_4 + V_3 ;
V_11 *= V_17 ;
V_10 = F_7 () ;
F_12 ( & V_13 , V_14 + ( V_3 * V_15 ) ) ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_13 ) ;
F_8 ( L_5 ) ;
}
