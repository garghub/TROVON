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
V_16 [ V_7 ] . V_17 = V_5 ;
return V_7 ;
}
static void T_1 F_18 ( unsigned int V_5 , unsigned int V_6 )
{
unsigned long V_10 ;
if ( ! V_5 )
return;
if ( V_5 >= ( ( ( V_6 & V_8 ) >> V_9 ) + 1 ) )
F_19 ( F_20 () | ( ( V_6 & V_8 ) >> V_9 ) ) ;
else {
F_19 ( F_20 () | V_5 ) ;
F_13 ( F_12 () | ( V_5 << V_18 ) ) ;
}
V_10 = F_21 () ;
V_10 &= ~ ( V_19 | V_20 ) ;
V_10 |= V_21 ;
F_22 ( V_10 ) ;
F_23 ( V_22 ) ;
}
static void F_24 ( void )
{
#ifdef F_25
if ( V_23 )
F_26 ( V_1 , V_24 | V_25 |
V_26 | V_27 |
V_28 | V_29 ) ;
else
#endif
F_26 ( V_1 , V_30 | V_31 |
V_28 | V_29 ) ;
}
static void F_27 ( void )
{
F_28 ( F_10 () + ( 8 * V_32 / V_33 ) ) ;
#ifdef F_29
if ( V_34 )
F_30 ( F_31 () , & V_35 ) ;
#endif
F_32 () ;
}
static void F_33 ( int V_36 , struct V_37 * V_38 )
{
struct V_39 * V_40 = F_34 ( V_38 ) ;
F_35 () ;
F_36 ( V_41 ) ;
F_37 ( V_36 ) ;
F_38 ( ( unsigned long ) & V_42 ) ;
F_22 ( ( F_21 () & ~ V_21 ) | V_19 ) ;
F_23 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_39 ( F_40 ( V_38 ) ) ;
F_41 ( ( unsigned long ) V_40 ) ;
F_42 ( ( unsigned long ) V_40 ,
( unsigned long ) ( V_40 + sizeof( struct V_39 ) ) ) ;
F_43 ( V_41 ) ;
F_44 ( V_43 ) ;
}
static void T_1 F_45 ( void )
{
unsigned int V_6 , V_44 , V_5 , V_7 = 0 ;
unsigned int V_45 ;
#ifdef F_29
if ( V_34 )
F_30 ( 0 , & V_35 ) ;
#endif
if ( ! V_46 )
return;
F_35 () ;
F_46 () ;
F_36 ( V_41 ) ;
V_6 = F_47 () ;
V_44 = ( V_6 & V_47 ) >> V_48 ;
V_45 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_49 = V_45 ;
for ( V_5 = 0 ; V_5 <= V_44 ; V_5 ++ ) {
F_37 ( V_5 ) ;
F_18 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_43 ( V_41 ) ;
F_48 ( V_50 L_1 , V_7 ) ;
}
static void T_1 F_49 ( unsigned int V_51 )
{
F_50 () ;
}
