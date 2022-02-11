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
V_13 [ V_5 ] = ++ V_7 ;
V_14 [ V_7 ] = V_5 ;
}
F_15 ( F_16 () & ~ V_15 ) ;
if ( V_5 != 0 )
F_1 () ;
return V_7 ;
}
static void T_1 F_17 ( unsigned int V_5 , unsigned int V_6 )
{
unsigned long V_10 ;
if ( ! V_5 )
return;
if ( V_5 >= ( ( ( V_6 & V_8 ) >> V_9 ) + 1 ) )
F_18 ( F_19 () | ( ( V_6 & V_8 ) >> V_9 ) ) ;
else {
F_18 ( F_19 () | V_5 ) ;
F_13 ( F_12 () | ( V_5 << V_16 ) ) ;
}
V_10 = F_20 () ;
V_10 &= ~ ( V_17 | V_18 ) ;
V_10 |= V_19 ;
F_21 ( V_10 ) ;
F_22 ( V_20 ) ;
}
static void F_23 ( int V_21 , unsigned int V_22 )
{
int V_23 ;
unsigned long V_24 ;
int V_25 ;
F_24 ( V_24 ) ;
V_25 = F_25 () ;
switch ( V_22 ) {
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
default:
V_23 = V_29 ;
break;
}
F_26 ( V_21 ) ;
F_6 ( F_27 () | V_23 ) ;
F_28 ( V_25 ) ;
F_29 ( V_24 ) ;
}
static void F_30 ( const struct V_30 * V_31 , unsigned int V_22 )
{
unsigned int V_23 ;
F_31 (i, mask)
F_23 ( V_23 , V_22 ) ;
}
static void T_2 F_32 ( void )
{
#ifdef F_33
extern int V_32 ;
if ( V_32 )
F_34 ( V_1 , V_33 | V_34 |
V_35 | V_36 ) ;
else
#endif
F_34 ( V_1 , V_37 | V_38 |
V_35 | V_36 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( F_10 () + ( 8 * V_39 / V_40 ) ) ;
#ifdef F_37
if ( V_41 )
F_38 ( F_39 () , V_42 ) ;
#endif
F_40 () ;
}
static void F_41 ( void )
{
}
static void T_2 F_42 ( int V_21 , struct V_43 * V_44 )
{
struct V_45 * V_46 = F_43 ( V_44 ) ;
F_25 () ;
F_44 ( V_47 ) ;
F_26 ( V_21 ) ;
F_45 ( ( unsigned long ) & V_48 ) ;
F_21 ( ( F_20 () & ~ V_19 ) | V_17 ) ;
F_22 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_46 ( F_47 ( V_44 ) ) ;
F_48 ( ( unsigned long ) V_46 ) ;
F_49 ( ( unsigned long ) V_46 ,
( unsigned long ) ( V_46 + sizeof( struct V_45 ) ) ) ;
F_50 ( V_47 ) ;
F_28 ( V_49 ) ;
}
static void T_1 F_51 ( void )
{
unsigned int V_6 , V_50 , V_5 , V_7 = 0 ;
unsigned int V_51 ;
#ifdef F_37
if ( V_41 )
F_38 ( 0 , V_42 ) ;
#endif
if ( ! V_52 )
return;
F_25 () ;
F_52 () ;
F_44 ( V_47 ) ;
V_6 = F_53 () ;
V_50 = ( V_6 & V_53 ) >> V_54 ;
V_51 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_55 = V_51 ;
for ( V_5 = 0 ; V_5 <= V_50 ; V_5 ++ ) {
F_26 ( V_5 ) ;
F_17 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_50 ( V_47 ) ;
F_54 ( V_56 L_1 , V_7 ) ;
}
static void T_1 F_55 ( unsigned int V_57 )
{
F_56 () ;
}
