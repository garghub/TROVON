static void T_1 F_1 ( void )
{
F_2 (
( F_3 () & ~ ( V_1 | V_2 | V_3 ) ) | V_4 ) ;
F_4 ( F_5 () ) ;
F_6 ( 0 ) ;
F_7 ( F_8 () ) ;
F_9 ( F_10 () ) ;
}
static unsigned int T_1 F_11 ( unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 )
{
if ( V_5 > ( ( V_6 & V_8 ) >> V_9 ) )
return V_7 ;
if ( V_5 != 0 ) {
unsigned long V_10 = F_12 () ;
V_10 &= ~ V_11 ;
V_10 |= V_12 ;
F_13 ( V_10 ) ;
F_14 ( V_5 , true ) ;
F_15 ( V_5 , true ) ;
V_13 [ V_5 ] = ++ V_7 ;
V_14 [ V_7 ] = V_5 ;
}
F_16 ( F_17 () & ~ V_15 ) ;
if ( V_5 != 0 )
F_1 () ;
F_18 ( & V_16 [ V_7 ] , V_5 ) ;
return V_7 ;
}
static void T_1 F_19 ( unsigned int V_5 , unsigned int V_6 )
{
unsigned long V_10 ;
if ( ! V_5 )
return;
if ( V_5 >= ( ( ( V_6 & V_8 ) >> V_9 ) + 1 ) )
F_20 ( F_21 () | ( ( V_6 & V_8 ) >> V_9 ) ) ;
else {
F_20 ( F_21 () | V_5 ) ;
F_13 ( F_12 () | ( V_5 << V_17 ) ) ;
}
V_10 = F_22 () ;
V_10 &= ~ ( V_18 | V_19 ) ;
V_10 |= V_20 ;
F_23 ( V_10 ) ;
F_24 ( V_21 ) ;
}
static void F_25 ( void )
{
if ( F_26 () )
F_27 ( V_1 , V_22 | V_23 |
V_24 | V_25 |
V_26 | V_27 ) ;
else
F_27 ( V_1 , V_28 | V_29 |
V_26 | V_27 ) ;
}
static void F_28 ( void )
{
F_29 ( F_10 () + ( 8 * V_30 / V_31 ) ) ;
#ifdef F_30
if ( V_32 )
F_31 ( F_32 () , & V_33 ) ;
#endif
F_33 () ;
}
static int F_34 ( int V_34 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_35 ( V_36 ) ;
F_36 () ;
F_37 ( V_39 ) ;
F_38 ( V_34 ) ;
F_39 ( ( unsigned long ) & V_40 ) ;
F_23 ( ( F_22 () & ~ V_20 ) | V_18 ) ;
F_24 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_40 ( F_41 ( V_36 ) ) ;
F_42 ( ( unsigned long ) V_38 ) ;
F_43 ( ( unsigned long ) V_38 ,
( unsigned long ) ( V_38 + sizeof( struct V_37 ) ) ) ;
F_44 ( V_39 ) ;
F_45 ( V_41 ) ;
return 0 ;
}
static void T_1 F_46 ( void )
{
unsigned int V_6 , V_42 , V_5 , V_7 = 0 ;
unsigned int V_43 ;
#ifdef F_30
if ( V_32 )
F_31 ( 0 , & V_33 ) ;
#endif
if ( ! V_44 )
return;
F_36 () ;
F_47 () ;
F_37 ( V_39 ) ;
V_6 = F_48 () ;
V_42 = ( V_6 & V_45 ) >> V_46 ;
V_43 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_47 = V_43 ;
for ( V_5 = 0 ; V_5 <= V_42 ; V_5 ++ ) {
F_38 ( V_5 ) ;
F_19 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_44 ( V_39 ) ;
F_49 ( V_48 L_1 , V_7 ) ;
}
static void T_1 F_50 ( unsigned int V_49 )
{
F_51 () ;
}
