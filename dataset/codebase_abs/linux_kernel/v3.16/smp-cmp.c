static void F_1 ( void )
{
struct V_1 * T_1 V_2 = & V_3 ;
F_2 ( V_4 , V_5 | V_6 | V_7 |
V_8 ) ;
#ifdef F_3
if ( V_9 )
T_1 -> V_10 = ( F_4 () >> V_11 ) &
V_12 ;
#endif
}
static void F_5 ( void )
{
F_6 ( L_1 , F_7 () , V_13 ) ;
F_8 ( F_9 () + ( 8 * V_14 / V_15 ) ) ;
#ifdef F_10
if ( V_16 )
F_11 ( F_7 () , V_17 ) ;
#endif
F_12 () ;
}
static void F_13 ( int V_18 , struct V_19 * V_20 )
{
struct V_21 * V_22 = F_14 ( V_20 ) ;
unsigned long V_23 = F_15 ( V_20 ) ;
unsigned long V_24 = ( unsigned long ) & V_25 ;
unsigned long V_26 = 0 ;
F_6 ( L_2 , F_7 () ,
V_13 , V_18 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_16 ( V_18 , V_24 , V_23 , ( unsigned long ) V_22 , V_26 ) ;
}
void T_2 F_17 ( void )
{
int V_27 ;
int V_28 = 0 ;
F_6 ( L_1 , F_7 () , V_13 ) ;
#ifdef F_10
if ( V_16 )
F_11 ( 0 , V_17 ) ;
#endif
for ( V_27 = 1 ; V_27 < V_29 ; V_27 ++ ) {
if ( F_18 ( V_27 ) ) {
F_19 ( V_27 , true ) ;
V_30 [ V_27 ] = ++ V_28 ;
V_31 [ V_28 ] = V_27 ;
}
}
if ( V_9 ) {
unsigned int V_32 = 1 ;
#ifdef F_3
unsigned int V_33 = F_20 () ;
V_32 = ( ( V_33 & V_34 ) >> V_35 ) + 1 ;
#endif
V_36 = V_32 ;
}
F_21 ( L_3 , V_28 ) ;
}
void T_2 F_22 ( unsigned int V_37 )
{
F_6 ( L_4 ,
F_7 () , V_13 , V_37 ) ;
#ifdef F_23
F_24 () ;
#endif
}
