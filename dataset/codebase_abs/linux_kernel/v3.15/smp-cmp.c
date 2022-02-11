static void F_1 ( void )
{
struct V_1 * T_1 V_2 = & V_3 ;
F_2 ( V_4 , V_5 | V_6 | V_7 |
V_8 ) ;
#if F_3 ( V_9 ) || F_3 ( V_10 )
if ( V_11 )
T_1 -> V_12 = ( F_4 () >> V_13 ) &
V_14 ;
#endif
#ifdef V_10
T_1 -> V_15 = ( F_4 () & V_16 ) >> V_17 ;
#endif
}
static void F_5 ( void )
{
F_6 ( L_1 , F_7 () , V_18 ) ;
F_8 ( F_9 () + ( 8 * V_19 / V_20 ) ) ;
#ifdef F_10
if ( V_21 )
F_11 ( F_7 () , V_22 ) ;
#endif
F_12 () ;
}
static void F_13 ( void )
{
F_6 ( L_1 , F_7 () , V_18 ) ;
}
static void F_14 ( int V_23 , struct V_24 * V_25 )
{
struct V_26 * V_27 = F_15 ( V_25 ) ;
unsigned long V_28 = F_16 ( V_25 ) ;
unsigned long V_29 = ( unsigned long ) & V_30 ;
unsigned long V_31 = 0 ;
F_6 ( L_2 , F_7 () ,
V_18 , V_23 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_17 ( V_23 , V_29 , V_28 , ( unsigned long ) V_27 , V_31 ) ;
}
void T_2 F_18 ( void )
{
int V_32 ;
int V_33 = 0 ;
F_6 ( L_1 , F_7 () , V_18 ) ;
#ifdef F_10
if ( V_21 )
F_11 ( 0 , V_22 ) ;
#endif
for ( V_32 = 1 ; V_32 < V_34 ; V_32 ++ ) {
if ( F_19 ( V_32 ) ) {
F_20 ( V_32 , true ) ;
V_35 [ V_32 ] = ++ V_33 ;
V_36 [ V_33 ] = V_32 ;
}
}
if ( V_11 ) {
unsigned int V_37 = 1 ;
#ifdef V_9
unsigned int V_38 = F_21 () ;
V_37 = ( ( V_38 & V_39 ) >> V_40 ) + 1 ;
#elif F_3 ( V_10 )
unsigned int V_38 = F_21 () ;
V_37 = ( ( V_38 & V_41 ) >> V_42 ) + 1 ;
#endif
V_43 = V_37 ;
}
F_22 ( L_3 , V_33 ) ;
}
void T_2 F_23 ( unsigned int V_44 )
{
F_6 ( L_4 ,
F_7 () , V_18 , V_44 ) ;
#ifdef F_24
F_25 () ;
#endif
}
