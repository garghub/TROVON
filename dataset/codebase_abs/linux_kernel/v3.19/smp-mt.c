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
V_35 | V_36 |
V_37 | V_38 ) ;
else
#endif
F_36 ( V_1 , V_39 | V_40 |
V_37 | V_38 ) ;
}
static void F_37 ( void )
{
F_38 ( F_10 () + ( 8 * V_41 / V_42 ) ) ;
#ifdef F_39
if ( V_43 )
F_40 ( F_41 () , V_44 ) ;
#endif
F_42 () ;
}
static void F_43 ( int V_21 , struct V_45 * V_46 )
{
struct V_47 * V_48 = F_44 ( V_46 ) ;
F_28 () ;
F_45 ( V_49 ) ;
F_29 ( V_21 ) ;
F_46 ( ( unsigned long ) & V_50 ) ;
F_22 ( ( F_21 () & ~ V_19 ) | V_17 ) ;
F_23 ( 0 ) ;
F_13 ( F_12 () | V_11 ) ;
F_47 ( F_48 ( V_46 ) ) ;
F_49 ( ( unsigned long ) V_48 ) ;
F_50 ( ( unsigned long ) V_48 ,
( unsigned long ) ( V_48 + sizeof( struct V_47 ) ) ) ;
F_51 ( V_49 ) ;
F_31 ( V_51 ) ;
}
static void T_1 F_52 ( void )
{
unsigned int V_6 , V_52 , V_5 , V_7 = 0 ;
unsigned int V_53 ;
#ifdef F_39
if ( V_43 )
F_40 ( 0 , V_44 ) ;
#endif
if ( ! V_54 )
return;
F_28 () ;
F_53 () ;
F_45 ( V_49 ) ;
V_6 = F_54 () ;
V_52 = ( V_6 & V_55 ) >> V_56 ;
V_53 = ( ( V_6 & V_8 ) >> V_9 ) + 1 ;
V_57 = V_53 ;
for ( V_5 = 0 ; V_5 <= V_52 ; V_5 ++ ) {
F_29 ( V_5 ) ;
F_18 ( V_5 , V_6 ) ;
V_7 = F_11 ( V_5 , V_6 , V_7 ) ;
}
F_51 ( V_49 ) ;
F_55 ( V_58 L_1 , V_7 ) ;
}
static void T_1 F_56 ( unsigned int V_59 )
{
F_57 () ;
}
static int F_58 ( struct V_60 * V_61 ,
unsigned long V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
struct V_66 * V_67 = V_65 -> V_67 ;
unsigned long V_68 = V_65 -> V_68 ;
if ( ! V_54 )
return V_69 ;
F_59 ( V_67 , L_2 , V_70 [ V_68 ] . V_71 ) ;
return V_69 ;
}
static int T_1 F_60 ( void )
{
return F_61 ( F_58 , 0 ) ;
}
