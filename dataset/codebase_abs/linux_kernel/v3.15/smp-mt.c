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
int V_23 ;
unsigned long V_24 ;
int V_25 ;
#ifdef F_25
if ( V_26 ) {
F_26 ( V_21 , V_22 ) ;
return;
}
#endif
F_27 ( V_24 ) ;
V_25 = F_28 () ;
switch ( V_22 ) {
case V_27 :
V_23 = V_28 ;
break;
case V_29 :
default:
V_23 = V_30 ;
break;
}
F_29 ( V_21 ) ;
F_6 ( F_30 () | V_23 ) ;
F_31 ( V_25 ) ;
F_32 ( V_24 ) ;
}
static void F_33 ( const struct V_31 * V_32 , unsigned int V_22 )
{
unsigned int V_23 ;
F_34 (i, mask)
F_24 ( V_23 , V_22 ) ;
}
static void F_35 ( void )
{
#ifdef F_25
if ( V_26 )
F_36 ( V_1 , V_33 | V_34 |
V_35 | V_36 ) ;
else
#endif
F_36 ( V_1 , V_37 | V_38 |
V_35 | V_36 ) ;
}
static void F_37 ( void )
{
F_38 ( F_10 () + ( 8 * V_39 / V_40 ) ) ;
#ifdef F_39
if ( V_41 )
F_40 ( F_41 () , V_42 ) ;
#endif
F_42 () ;
}
static void F_43 ( void )
{
}
static void F_44 ( int V_21 , struct V_43 * V_44 )
{
struct V_45 * V_46 = F_45 ( V_44 ) ;
F_28 () ;
F_46 ( V_47 ) ;
F_29 ( V_21 ) ;
F_47 ( ( unsigned long ) & V_48 ) ;
F_22 ( ( F_21 () & ~ V_19 ) | V_17 ) ;
F_23 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_48 ( F_49 ( V_44 ) ) ;
F_50 ( ( unsigned long ) V_46 ) ;
F_51 ( ( unsigned long ) V_46 ,
( unsigned long ) ( V_46 + sizeof( struct V_45 ) ) ) ;
F_52 ( V_47 ) ;
F_31 ( V_49 ) ;
}
static void T_1 F_53 ( void )
{
unsigned int V_6 , V_50 , V_5 , V_7 = 0 ;
unsigned int V_51 ;
#ifdef F_39
if ( V_41 )
F_40 ( 0 , V_42 ) ;
#endif
if ( ! V_52 )
return;
F_28 () ;
F_54 () ;
F_46 ( V_47 ) ;
V_6 = F_55 () ;
V_50 = ( V_6 & V_53 ) >> V_54 ;
V_51 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_55 = V_51 ;
for ( V_5 = 0 ; V_5 <= V_50 ; V_5 ++ ) {
F_29 ( V_5 ) ;
F_18 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_52 ( V_47 ) ;
F_56 ( V_56 L_1 , V_7 ) ;
}
static void T_1 F_57 ( unsigned int V_57 )
{
F_58 () ;
}
static int F_59 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
struct V_64 * V_65 = V_63 -> V_65 ;
unsigned long V_66 = V_63 -> V_66 ;
if ( ! V_52 )
return V_67 ;
F_60 ( V_65 , L_2 , V_68 [ V_66 ] . V_69 ) ;
return V_67 ;
}
static int T_1 F_61 ( void )
{
return F_62 ( F_59 , 0 ) ;
}
