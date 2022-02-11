static void F_1 ( void )
{
struct V_1 * T_1 V_2 = & V_3 ;
F_2 ( V_4 , V_5 | V_6 | V_7 |
V_8 | V_9 | V_10 ) ;
#ifdef F_3
if ( V_11 )
F_4 ( T_1 , ( F_5 () >> V_12 ) &
V_13 ) ;
#endif
}
static void F_6 ( void )
{
F_7 ( L_1 , F_8 () , V_14 ) ;
F_9 ( F_10 () + ( 8 * V_15 / V_16 ) ) ;
#ifdef F_11
if ( V_17 )
F_12 ( F_8 () , & V_18 ) ;
#endif
F_13 () ;
}
static int F_14 ( int V_19 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
unsigned long V_24 = F_16 ( V_21 ) ;
unsigned long V_25 = ( unsigned long ) & V_26 ;
unsigned long V_27 = 0 ;
F_7 ( L_2 , F_8 () ,
V_14 , V_19 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_17 ( V_19 , V_25 , V_24 , ( unsigned long ) V_23 , V_27 ) ;
return 0 ;
}
void T_2 F_18 ( void )
{
int V_28 ;
int V_29 = 0 ;
F_7 ( L_1 , F_8 () , V_14 ) ;
#ifdef F_11
if ( V_17 )
F_12 ( 0 , & V_18 ) ;
#endif
for ( V_28 = 1 ; V_28 < V_30 ; V_28 ++ ) {
if ( F_19 ( V_28 ) ) {
F_20 ( V_28 , true ) ;
V_31 [ V_28 ] = ++ V_29 ;
V_32 [ V_29 ] = V_28 ;
}
}
if ( V_11 ) {
unsigned int V_33 = 1 ;
#ifdef F_3
unsigned int V_34 = F_21 () ;
V_33 = ( ( V_34 & V_35 ) >> V_36 ) + 1 ;
#endif
V_37 = V_33 ;
}
F_22 ( L_3 , V_29 ) ;
}
void T_2 F_23 ( unsigned int V_38 )
{
F_7 ( L_4 ,
F_8 () , V_14 , V_38 ) ;
#ifdef F_24
F_25 () ;
#endif
}
