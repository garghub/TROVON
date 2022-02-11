static void F_1 ( void )
{
struct V_1 * T_1 V_2 = & V_3 ;
F_2 ( V_4 , V_5 | V_6 | V_7 |
V_8 | V_9 | V_10 ) ;
#ifdef F_3
if ( V_11 )
T_1 -> V_12 = ( F_4 () >> V_13 ) &
V_14 ;
#endif
}
static void F_5 ( void )
{
F_6 ( L_1 , F_7 () , V_15 ) ;
F_8 ( F_9 () + ( 8 * V_16 / V_17 ) ) ;
#ifdef F_10
if ( V_18 )
F_11 ( F_7 () , V_19 ) ;
#endif
F_12 () ;
}
static void F_13 ( int V_20 , struct V_21 * V_22 )
{
struct V_23 * V_24 = F_14 ( V_22 ) ;
unsigned long V_25 = F_15 ( V_22 ) ;
unsigned long V_26 = ( unsigned long ) & V_27 ;
unsigned long V_28 = 0 ;
F_6 ( L_2 , F_7 () ,
V_15 , V_20 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_16 ( V_20 , V_26 , V_25 , ( unsigned long ) V_24 , V_28 ) ;
}
void T_2 F_17 ( void )
{
int V_29 ;
int V_30 = 0 ;
F_6 ( L_1 , F_7 () , V_15 ) ;
#ifdef F_10
if ( V_18 )
F_11 ( 0 , V_19 ) ;
#endif
for ( V_29 = 1 ; V_29 < V_31 ; V_29 ++ ) {
if ( F_18 ( V_29 ) ) {
F_19 ( V_29 , true ) ;
V_32 [ V_29 ] = ++ V_30 ;
V_33 [ V_30 ] = V_29 ;
}
}
if ( V_11 ) {
unsigned int V_34 = 1 ;
#ifdef F_3
unsigned int V_35 = F_20 () ;
V_34 = ( ( V_35 & V_36 ) >> V_37 ) + 1 ;
#endif
V_38 = V_34 ;
}
F_21 ( L_3 , V_30 ) ;
}
void T_2 F_22 ( unsigned int V_39 )
{
F_6 ( L_4 ,
F_7 () , V_15 , V_39 ) ;
#ifdef F_23
F_24 () ;
#endif
}
