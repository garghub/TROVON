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
case V_31 :
V_32 = V_25 * 4 ; break;
default:
V_32 = V_25 ;
}
switch ( V_16 ) {
case V_33 :
case V_27 :
V_17 = V_32 * 2 ; break;
case V_34 :
case V_28 :
V_17 = V_32 * 5 / 2 ; break;
case V_35 :
case V_29 :
V_17 = V_32 * 3 ; break;
case V_36 :
case V_30 :
V_17 = V_32 * 4 ; break;
case V_37 :
case V_31 :
V_17 = V_32 * 9 / 2 ; break;
}
V_38 = V_17 ;
} else {
if ( V_38 == 0 )
V_38 = 300000000 ;
V_17 = V_38 ;
V_16 = ( T_2 ) V_2 & V_26 ;
switch ( V_16 ) {
case V_33 :
case V_27 :
V_32 = V_17 / 2 ; break;
case V_34 :
case V_28 :
V_32 = V_17 * 2 / 5 ; break;
case V_35 :
case V_29 :
V_32 = V_17 / 3 ; break;
case V_36 :
case V_30 :
V_32 = V_17 / 4 ; break;
case V_37 :
case V_31 :
V_32 = V_17 * 2 / 9 ; break;
}
switch ( V_16 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_25 = V_32 / 4 ; break;
default:
V_25 = V_32 ;
}
}
V_39 = V_38 / V_40 / 2 ;
F_1 () ;
F_5 ( V_41 ) ;
if ( V_42 )
F_5 ( V_43 ) ;
F_32 ( & V_1 -> V_44 , V_45 ) ;
if ( ! ( F_2 ( & V_1 -> V_2 ) & V_46 ) )
F_32 ( & V_1 -> V_44 , V_47 ) ;
F_33 ( L_9 ,
V_48 , ( V_17 + 500000 ) / 1000000 ,
( V_25 + 500000 ) / 1000000 ,
( T_2 ) F_2 ( & V_1 -> V_49 ) ,
F_2 ( & V_1 -> V_2 ) ,
F_2 ( & V_1 -> V_44 ) ) ;
F_33 ( L_10 , V_48 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
T_4 V_50 = F_34 ( V_15 ) ;
unsigned long V_51 , V_52 ;
if ( ! ( ( T_2 ) V_50 & 0x00000400 ) )
continue;
V_51 = ( unsigned long ) ( V_50 >> 49 ) << 21 ;
V_52 = ( ( ( unsigned long ) ( V_50 >> 33 ) & 0x7fff ) + 1 ) << 21 ;
F_35 ( L_11 , V_15 , V_50 ) ;
V_53 [ V_15 ] . V_54 = L_12 ;
V_53 [ V_15 ] . V_22 = V_51 ;
V_53 [ V_15 ] . V_23 = V_51 + V_52 - 1 ;
V_53 [ V_15 ] . V_55 = V_56 ;
F_31 ( & V_24 , & V_53 [ V_15 ] ) ;
}
F_35 ( L_13 , F_2 ( & V_57 -> V_58 ) ) ;
if ( V_59 == 0x4938 && F_2 ( & V_60 -> V_50 ) & 1 ) {
unsigned int V_52 = V_61 ;
V_62 . V_54 = L_14 ;
V_62 . V_22 =
( F_2 ( & V_60 -> V_50 ) >> ( 39 - 11 ) )
& ~ ( V_52 - 1 ) ;
V_62 . V_23 =
V_62 . V_22 + V_61 - 1 ;
V_62 . V_55 = V_56 ;
F_31 ( & V_24 , & V_62 ) ;
}
for ( V_15 = 0 ; V_15 < V_63 ; V_15 ++ )
F_36 ( F_8 ( V_15 ) & 0xfffffffffULL ) ;
F_37 ( 0 , & V_64 -> V_65 ) ;
F_37 ( 0 , & V_64 -> V_66 ) ;
if ( V_59 == 0x4938 ) {
T_4 V_44 = F_2 ( & V_1 -> V_44 ) ;
F_38 ( & V_1 -> V_67 , V_68 ) ;
if ( V_44 & ( V_69 | V_70 ) ) {
F_13 ( 1 ) ;
F_32 ( & V_1 -> V_67 ,
V_68 ) ;
} else {
F_33 ( L_15 , V_48 ) ;
F_38 ( & V_1 -> V_67 ,
V_71 ) ;
}
if ( ! ( V_44 & V_69 ) ) {
F_33 ( L_16 , V_48 ) ;
F_38 ( & V_1 -> V_67 ,
V_72 ) ;
F_38 ( & V_1 -> V_67 ,
V_73 ) ;
}
if ( ! ( V_44 & V_70 ) ) {
F_33 ( L_17 , V_48 ) ;
F_38 ( & V_1 -> V_67 ,
V_74 ) ;
F_38 ( & V_1 -> V_67 ,
V_75 ) ;
}
}
V_76 = F_9 ;
V_77 = F_23 ;
}
void T_1 F_39 ( unsigned int V_78 )
{
if ( F_2 ( & V_1 -> V_2 ) & V_79 )
F_40 ( F_8 ( V_78 ) & 0xfffffffffULL ,
V_80 + F_41 ( V_78 ) ,
V_81 ) ;
}
void T_1 F_42 ( unsigned int V_82 , unsigned int V_83 )
{
int V_15 ;
unsigned int V_84 = 0 ;
if ( F_43 ( & V_1 -> V_44 ) & V_69 )
V_84 |= 1 << 1 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
if ( ( 1 << V_15 ) & V_84 )
continue;
F_44 ( F_45 ( V_15 ) & 0xfffffffffULL ,
V_80 + F_46 ( V_15 ) ,
V_15 , V_82 , ( 1 << V_15 ) & V_83 ) ;
}
}
void T_1 F_47 ( int V_85 )
{
F_48 ( V_85 , V_86 & 0xfffffffffULL ,
V_80 + V_87 ) ;
}
void T_1 F_49 ( unsigned char * V_88 , unsigned char * V_89 )
{
T_3 V_44 = F_43 ( & V_1 -> V_44 ) ;
if ( V_88 && ( V_44 & V_69 ) )
F_50 ( V_80 + V_90 , V_88 ) ;
if ( V_89 && ( V_44 & V_70 ) )
F_50 ( V_80 + V_91 , V_89 ) ;
}
void T_1 F_51 ( int V_92 )
{
struct V_93 V_94 = {
. V_95 = F_52 ( V_92 ) / 8 ,
} ;
unsigned long V_22 = V_21 [ V_92 ] . V_22 ;
unsigned long V_52 = V_21 [ V_92 ] . V_23 - V_22 + 1 ;
if ( ! ( F_28 ( V_92 ) & 0x8 ) )
return;
F_53 ( V_92 , V_22 , V_52 , & V_94 ) ;
}
void T_1 F_54 ( unsigned int V_96 , unsigned int V_97 , int V_98 )
{
struct V_99 * V_100 ;
struct V_101 V_102 [] = {
{
. V_55 = V_56 ,
} , {
. V_22 = V_96 ,
. V_55 = V_103 ,
} ,
} ;
struct V_104 V_94 = {
. V_105 = V_97 ,
. V_106 = V_98 ? V_32 : 0 ,
} ;
T_3 V_107 ;
int V_15 ;
if ( ( F_43 ( & V_1 -> V_44 ) &
( V_108 | V_109 ) )
!= V_108 )
return;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
V_107 = F_43 ( & V_110 -> V_50 [ V_15 ] ) ;
if ( ( V_107 & 0x00f00008 ) == 0x00e00008 )
break;
}
if ( V_15 == 8 )
return;
V_94 . V_111 = V_15 ;
V_102 [ 0 ] . V_22 = ( ( V_107 >> 48 ) << 20 ) + 0x10000 ;
V_102 [ 0 ] . V_23 = V_102 [ 0 ] . V_22 + 0x20000 - 1 ;
V_100 = F_55 ( L_18 , - 1 ) ;
if ( ! V_100 ||
F_56 ( V_100 , V_102 , F_57 ( V_102 ) ) ||
F_58 ( V_100 , & V_94 , sizeof( V_94 ) ) ||
F_59 ( V_100 ) )
F_60 ( V_100 ) ;
}
void T_1 F_61 ( unsigned int V_112 , unsigned int V_113 )
{
struct V_114 V_115 = {
. V_97 = 1 ,
. V_106 = V_32 ,
. V_112 = V_112 ,
. V_113 = V_113 ,
. V_84 = 1 ,
} ;
unsigned long V_116 = V_117 & 0xfffffffffULL ;
#ifdef F_62
V_116 += 4 ;
#endif
if ( ( F_43 ( & V_1 -> V_44 ) &
( V_108 | V_118 | V_109 ) ) ==
V_109 )
F_63 ( V_116 , & V_115 ) ;
}
void T_1 F_64 ( int V_119 , int V_120 )
{
struct V_121 V_115 = {
. V_122 = true ,
} ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_115 . V_123 = V_15 ? V_120 : V_119 ;
F_65 ( V_15 , F_66 ( V_15 ) & 0xfffffffffULL ,
V_80 + F_67 ( V_15 , 0 ) ,
& V_115 ) ;
}
}
void T_1 F_68 ( void )
{
T_3 V_44 = F_43 ( & V_1 -> V_44 ) ;
if ( ( V_44 & V_124 ) &&
! ( V_44 & V_69 ) )
F_69 ( V_125 & 0xfffffffffULL ,
V_80 + V_126 ,
1 , 0 , 1 ) ;
}
void T_1 F_70 ( void )
{
if ( V_62 . V_22 )
F_71 ( & V_62 ) ;
}
static void T_1 F_72 ( void )
{
T_4 V_44 , V_127 = 0 , V_128 = 0 ;
char V_129 [ 128 ] ;
V_129 [ 0 ] = '\0' ;
F_10 () ;
V_44 = F_2 ( & V_1 -> V_44 ) ;
switch ( V_59 ) {
case 0x4937 :
if ( ! ( V_44 & V_124 ) ) {
V_127 |= V_130 ;
V_128 |= V_131 ;
strcat ( V_129 , L_19 ) ;
}
break;
case 0x4938 :
if ( ! ( V_44 & V_124 ) ||
( V_44 & V_69 ) ) {
V_127 |= V_130 ;
V_128 |= V_131 ;
strcat ( V_129 , L_19 ) ;
}
if ( ( V_44 &
( V_108 | V_118 |
V_109 ) )
!= V_109 ) {
V_127 |= V_132 ;
V_128 |= V_133 ;
strcat ( V_129 , L_20 ) ;
}
if ( ! ( V_44 & V_134 ) ) {
V_127 |= V_135 ;
V_128 |= V_136 ;
strcat ( V_129 , L_21 ) ;
}
break;
}
if ( V_127 | V_128 ) {
F_38 ( & V_1 -> V_67 , V_127 ) ;
F_38 ( & V_1 -> V_67 , V_128 ) ;
}
F_73 () ;
if ( V_129 [ 0 ] )
F_33 ( L_22 , V_48 , V_129 ) ;
}
static int T_1 F_74 ( void )
{
if ( V_59 != 0x4937 && V_59 != 0x4938 )
return - V_137 ;
F_72 () ;
return 0 ;
}
