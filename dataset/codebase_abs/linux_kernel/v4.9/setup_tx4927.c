static void T_1 F_1 ( void )
{
if ( F_2 ( & V_1 -> V_2 ) & V_3 )
F_3 ( L_1 ,
F_4 () ) ;
F_5 ( V_3 ) ;
F_5 ( V_4 ) ;
}
void T_1 F_6 ( void )
{
F_7 ( F_8 ( 2 ) & 0xfffffffffULL ) ;
}
static void F_9 ( char * V_5 )
{
F_10 () ;
F_11 ( L_2 ,
( F_2 ( & V_1 -> V_2 ) & V_6 ) ?
L_3 : L_4 ) ;
F_5 ( V_3 ) ;
F_12 ( F_8 ( 2 ) & 0xfffffffffULL ) ;
while ( ! ( F_2 ( & V_1 -> V_2 ) & V_3 ) )
;
F_13 ( 10 ) ;
if ( F_2 ( & V_1 -> V_2 ) & V_6 ) {
F_11 ( L_5 ) ;
F_14 ( V_6 ) ;
}
(* F_15)() ;
}
static int F_16 ( struct V_7 * V_8 , int V_9 )
{
int V_10 = V_8 -> V_11 & 4 ;
F_17 () ;
F_18 ( L_6 , V_10 ? 'D' : 'I' , V_8 -> V_12 ) ;
F_18 ( L_7 ,
( unsigned long long ) F_2 ( & V_1 -> V_2 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_13 ) ) ;
#ifdef F_19
F_20 () ;
#endif
F_21 ( V_8 ) ;
F_22 ( L_8 ) ;
}
static void T_1 F_23 ( void )
{
V_14 = F_16 ;
}
void T_1 F_24 ( void )
{
int V_15 ;
T_2 V_16 ;
unsigned int V_17 = 0 ;
T_3 V_2 ;
F_25 ( F_26 () , V_18 ,
V_19 ) ;
F_27 ( V_20 ) ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
if ( ! ( F_28 ( V_15 ) & 0x8 ) )
continue;
V_21 [ V_15 ] . V_22 = ( unsigned long ) F_29 ( V_15 ) ;
V_21 [ V_15 ] . V_23 =
V_21 [ V_15 ] . V_22 + F_30 ( V_15 ) - 1 ;
F_31 ( & V_24 , & V_21 [ V_15 ] ) ;
}
V_2 = F_2 ( & V_1 -> V_2 ) ;
if ( V_25 ) {
V_16 = ( T_2 ) V_2 & V_26 ;
switch ( V_16 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_31 = V_25 * 4 ; break;
default:
V_31 = V_25 ;
}
switch ( V_16 ) {
case V_32 :
case V_27 :
V_17 = V_31 * 2 ; break;
case V_33 :
case V_28 :
V_17 = V_31 * 5 / 2 ; break;
case V_34 :
case V_29 :
V_17 = V_31 * 3 ; break;
case V_35 :
case V_30 :
V_17 = V_31 * 4 ; break;
}
V_36 = V_17 ;
} else {
if ( V_36 == 0 )
V_36 = 200000000 ;
V_17 = V_36 ;
V_16 = ( T_2 ) V_2 & V_26 ;
switch ( V_16 ) {
case V_32 :
case V_27 :
V_31 = V_17 / 2 ; break;
case V_33 :
case V_28 :
V_31 = V_17 * 2 / 5 ; break;
case V_34 :
case V_29 :
V_31 = V_17 / 3 ; break;
case V_35 :
case V_30 :
V_31 = V_17 / 4 ; break;
}
switch ( V_16 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_25 = V_31 / 4 ; break;
default:
V_25 = V_31 ;
}
}
V_37 = V_36 / V_38 / 2 ;
F_1 () ;
F_5 ( V_39 ) ;
if ( V_40 )
F_5 ( V_41 ) ;
F_32 ( & V_1 -> V_42 , V_43 ) ;
if ( ! ( F_2 ( & V_1 -> V_2 ) & V_44 ) )
F_32 ( & V_1 -> V_42 , V_45 ) ;
F_33 ( V_46 L_9 ,
V_47 ,
( V_17 + 500000 ) / 1000000 ,
( V_25 + 500000 ) / 1000000 ,
( T_2 ) F_2 ( & V_1 -> V_48 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_2 ) ,
( unsigned long long ) F_2 ( & V_1 -> V_42 ) ) ;
F_33 ( V_46 L_10 , V_47 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
T_4 V_49 = F_34 ( V_15 ) ;
unsigned long V_50 , V_51 ;
if ( ! ( ( T_2 ) V_49 & 0x00000400 ) )
continue;
V_50 = ( unsigned long ) ( V_49 >> 49 ) << 21 ;
V_51 = ( ( ( unsigned long ) ( V_49 >> 33 ) & 0x7fff ) + 1 ) << 21 ;
F_33 ( L_11 , V_15 , ( unsigned long long ) V_49 ) ;
V_52 [ V_15 ] . V_53 = L_12 ;
V_52 [ V_15 ] . V_22 = V_50 ;
V_52 [ V_15 ] . V_23 = V_50 + V_51 - 1 ;
V_52 [ V_15 ] . V_54 = V_55 ;
F_31 ( & V_24 , & V_52 [ V_15 ] ) ;
}
F_33 ( L_13 ,
( unsigned long long ) F_2 ( & V_56 -> V_57 ) ) ;
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ )
F_35 ( F_8 ( V_15 ) & 0xfffffffffULL ) ;
F_36 ( 0 , & V_59 -> V_60 ) ;
F_36 ( 0 , & V_59 -> V_61 ) ;
V_62 = F_9 ;
V_63 = F_23 ;
}
void T_1 F_37 ( unsigned int V_64 )
{
if ( F_2 ( & V_1 -> V_2 ) & V_65 )
F_38 ( F_8 ( V_64 ) & 0xfffffffffULL ,
V_66 + F_39 ( V_64 ) ,
V_67 ) ;
}
void T_1 F_40 ( unsigned int V_68 , unsigned int V_69 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ )
F_41 ( F_42 ( V_15 ) & 0xfffffffffULL ,
V_66 + F_43 ( V_15 ) ,
V_15 , V_68 , ( 1 << V_15 ) & V_69 ) ;
}
void T_1 F_44 ( int V_70 )
{
struct V_71 V_72 = {
. V_73 = F_45 ( V_70 ) / 8 ,
} ;
unsigned long V_22 = V_21 [ V_70 ] . V_22 ;
unsigned long V_51 = V_21 [ V_70 ] . V_23 - V_22 + 1 ;
if ( ! ( F_28 ( V_70 ) & 0x8 ) )
return;
F_46 ( V_70 , V_22 , V_51 , & V_72 ) ;
}
void T_1 F_47 ( int V_74 )
{
struct V_75 V_76 = {
. V_74 = V_74 ,
. V_77 = true ,
} ;
F_48 ( 0 , V_78 & 0xfffffffffULL ,
V_66 + F_49 ( 0 ) , & V_76 ) ;
}
void T_1 F_50 ( unsigned int V_79 ,
unsigned int V_80 )
{
T_3 V_42 = F_51 ( & V_1 -> V_42 ) ;
T_4 V_81 = 0 , V_82 = 0 ;
unsigned long V_54 ;
if ( ! ( V_42 & V_83 ) )
return;
switch ( V_79 ) {
case 0 :
V_81 |= V_84 ;
V_82 |= V_85 ;
break;
case 2 :
V_81 |= V_86 ;
V_82 |= V_87 ;
break;
default:
return;
}
switch ( V_80 ) {
case 1 :
V_81 |= V_88 ;
V_82 |= V_89 ;
break;
case 3 :
V_81 |= V_90 ;
V_82 |= V_91 ;
break;
default:
return;
}
F_52 ( V_54 ) ;
F_32 ( & V_1 -> V_42 , V_81 ) ;
F_53 ( & V_1 -> V_42 , V_82 ) ;
F_54 ( V_54 ) ;
F_55 ( V_92 & 0xfffffffffULL ,
V_66 + V_93 ,
0 , V_79 , V_80 ) ;
}
static void T_1 F_56 ( void )
{
T_4 V_42 , V_94 = 0 , V_95 = 0 ;
char V_96 [ 128 ] ;
V_96 [ 0 ] = '\0' ;
F_10 () ;
V_42 = F_2 ( & V_1 -> V_42 ) ;
if ( ! ( V_42 & V_83 ) ) {
V_94 |= V_97 ;
V_95 |= V_98 ;
strcat ( V_96 , L_14 ) ;
}
if ( V_94 | V_95 ) {
F_53 ( & V_1 -> V_99 , V_94 ) ;
F_53 ( & V_1 -> V_99 , V_95 ) ;
}
F_57 () ;
if ( V_96 [ 0 ] )
F_58 ( L_15 , V_47 , V_96 ) ;
}
static int T_1 F_59 ( void )
{
if ( V_100 != 0x4927 )
return - V_101 ;
F_56 () ;
return 0 ;
}
