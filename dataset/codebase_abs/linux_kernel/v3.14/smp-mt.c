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
F_13 ( F_12 () | ( V_5 << V_16 ) ) ;
}
V_10 = F_21 () ;
V_10 &= ~ ( V_17 | V_18 ) ;
V_10 |= V_19 ;
F_22 ( V_10 ) ;
F_23 ( V_20 ) ;
}
static void F_24 ( int V_21 , unsigned int V_22 )
{
unsigned long V_23 ;
F_25 ( V_23 ) ;
switch ( V_22 ) {
case V_24 :
F_26 ( F_27 ( V_21 ) ) ;
break;
case V_25 :
F_26 ( F_28 ( V_21 ) ) ;
break;
}
F_29 ( V_23 ) ;
}
static void F_30 ( int V_21 , unsigned int V_22 )
{
int V_26 ;
unsigned long V_23 ;
int V_27 ;
#ifdef F_31
if ( V_28 ) {
F_24 ( V_21 , V_22 ) ;
return;
}
#endif
F_25 ( V_23 ) ;
V_27 = F_32 () ;
switch ( V_22 ) {
case V_24 :
V_26 = V_29 ;
break;
case V_25 :
default:
V_26 = V_30 ;
break;
}
F_33 ( V_21 ) ;
F_6 ( F_34 () | V_26 ) ;
F_35 ( V_27 ) ;
F_29 ( V_23 ) ;
}
static void F_36 ( const struct V_31 * V_32 , unsigned int V_22 )
{
unsigned int V_26 ;
F_37 (i, mask)
F_30 ( V_26 , V_22 ) ;
}
static void F_38 ( void )
{
#ifdef F_31
if ( V_28 )
F_39 ( V_1 , V_33 | V_34 |
V_35 | V_36 ) ;
else
#endif
F_39 ( V_1 , V_37 | V_38 |
V_35 | V_36 ) ;
}
static void F_40 ( void )
{
F_41 ( F_10 () + ( 8 * V_39 / V_40 ) ) ;
#ifdef F_42
if ( V_41 )
F_43 ( F_44 () , V_42 ) ;
#endif
F_45 () ;
}
static void F_46 ( void )
{
}
static void F_47 ( int V_21 , struct V_43 * V_44 )
{
struct V_45 * V_46 = F_48 ( V_44 ) ;
F_32 () ;
F_49 ( V_47 ) ;
F_33 ( V_21 ) ;
F_50 ( ( unsigned long ) & V_48 ) ;
F_22 ( ( F_21 () & ~ V_19 ) | V_17 ) ;
F_23 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_51 ( F_52 ( V_44 ) ) ;
F_53 ( ( unsigned long ) V_46 ) ;
F_54 ( ( unsigned long ) V_46 ,
( unsigned long ) ( V_46 + sizeof( struct V_45 ) ) ) ;
F_55 ( V_47 ) ;
F_35 ( V_49 ) ;
}
static void T_1 F_56 ( void )
{
unsigned int V_6 , V_50 , V_5 , V_7 = 0 ;
unsigned int V_51 ;
#ifdef F_42
if ( V_41 )
F_43 ( 0 , V_42 ) ;
#endif
if ( ! V_52 )
return;
F_32 () ;
F_57 () ;
F_49 ( V_47 ) ;
V_6 = F_58 () ;
V_50 = ( V_6 & V_53 ) >> V_54 ;
V_51 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_55 = V_51 ;
for ( V_5 = 0 ; V_5 <= V_50 ; V_5 ++ ) {
F_33 ( V_5 ) ;
F_18 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_55 ( V_47 ) ;
F_59 ( V_56 L_1 , V_7 ) ;
}
static void T_1 F_60 ( unsigned int V_57 )
{
F_61 () ;
}
