void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
int F_5 ( bool (* F_6)( unsigned char V_2 , unsigned char V_3 ,
struct V_4 * V_4 ) )
{
unsigned long V_5 ;
int V_6 = 0 ;
F_7 ( & V_7 , V_5 ) ;
if ( V_8 ) {
V_6 = - V_9 ;
goto V_10;
}
V_8 = F_6 ;
V_10:
F_8 ( & V_7 , V_5 ) ;
return V_6 ;
}
int F_9 ( bool (* F_6)( unsigned char V_2 , unsigned char V_3 ,
struct V_4 * V_11 ) )
{
unsigned long V_5 ;
int V_6 = 0 ;
F_7 ( & V_7 , V_5 ) ;
if ( V_8 != F_6 ) {
V_6 = - V_12 ;
goto V_10;
}
V_8 = NULL ;
V_10:
F_8 ( & V_7 , V_5 ) ;
return V_6 ;
}
static int F_10 ( void )
{
int V_13 = 0 ;
while ( ( ~ F_11 () & V_14 ) && ( V_13 < V_15 ) ) {
F_12 ( 50 ) ;
V_13 ++ ;
}
return - ( V_13 == V_15 ) ;
}
static int F_13 ( void )
{
int V_13 = 0 ;
while ( ( F_11 () & V_16 ) && ( V_13 < V_15 ) ) {
F_12 ( 50 ) ;
V_13 ++ ;
}
return - ( V_13 == V_15 ) ;
}
static int F_14 ( void )
{
unsigned long V_5 ;
unsigned char V_2 , V_3 ;
int V_17 = 0 ;
int V_18 = 0 ;
F_7 ( & V_7 , V_5 ) ;
while ( ( V_3 = F_11 () ) & V_14 ) {
if ( V_17 ++ < V_19 ) {
F_12 ( 50 ) ;
V_2 = F_15 () ;
F_16 ( L_1 ,
V_2 , V_3 & V_20 ? L_2 : L_3 ) ;
} else {
V_18 = - V_21 ;
break;
}
}
F_8 ( & V_7 , V_5 ) ;
return V_18 ;
}
static int F_17 ( unsigned char * V_22 , int V_23 )
{
int V_13 , error ;
if ( V_24 && V_23 == V_25 )
return - 1 ;
error = F_13 () ;
if ( error )
return error ;
F_16 ( L_4 , V_23 & 0xff ) ;
F_18 ( V_23 & 0xff ) ;
for ( V_13 = 0 ; V_13 < ( ( V_23 >> 12 ) & 0xf ) ; V_13 ++ ) {
error = F_13 () ;
if ( error )
return error ;
F_16 ( L_5 , V_22 [ V_13 ] ) ;
F_19 ( V_22 [ V_13 ] ) ;
}
for ( V_13 = 0 ; V_13 < ( ( V_23 >> 8 ) & 0xf ) ; V_13 ++ ) {
error = F_10 () ;
if ( error ) {
F_16 ( L_6 ) ;
return error ;
}
if ( V_23 == V_25 &&
! ( F_11 () & V_20 ) ) {
F_16 ( L_7 ) ;
return - 1 ;
}
V_22 [ V_13 ] = F_15 () ;
F_16 ( L_8 , V_22 [ V_13 ] ) ;
}
return 0 ;
}
int F_20 ( unsigned char * V_22 , int V_23 )
{
unsigned long V_5 ;
int V_18 ;
F_7 ( & V_7 , V_5 ) ;
V_18 = F_17 ( V_22 , V_23 ) ;
F_8 ( & V_7 , V_5 ) ;
return V_18 ;
}
static int F_21 ( struct V_4 * V_11 , unsigned char V_26 )
{
unsigned long V_5 ;
int V_18 = 0 ;
F_7 ( & V_7 , V_5 ) ;
if ( ! ( V_18 = F_13 () ) ) {
F_16 ( L_9 , V_26 ) ;
F_19 ( V_26 ) ;
}
F_8 ( & V_7 , V_5 ) ;
return V_18 ;
}
static int F_22 ( struct V_4 * V_4 , unsigned char V_26 )
{
struct V_27 * V_11 = V_4 -> V_28 ;
return F_20 ( & V_26 , V_11 -> V_29 == - 1 ?
V_30 :
V_31 + V_11 -> V_29 ) ;
}
static void F_23 ( struct V_4 * V_4 )
{
int V_32 ;
int V_33 ;
const char * V_34 ;
if ( V_4 == V_35 [ V_36 ] . V_4 ) {
V_32 = V_37 ;
V_33 = V_38 ;
V_34 = L_10 ;
} else {
V_32 = V_39 ;
V_33 = V_40 ;
V_34 = L_11 ;
}
V_41 &= ~ V_32 ;
if ( F_20 ( & V_41 , V_42 ) )
F_24 ( L_12 , V_34 ) ;
F_12 ( 50 ) ;
V_41 &= ~ V_33 ;
V_41 |= V_32 ;
if ( F_20 ( & V_41 , V_42 ) )
F_25 ( L_13 , V_34 ) ;
F_26 ( 0 , NULL ) ;
}
static int F_27 ( struct V_4 * V_4 )
{
struct V_27 * V_11 = V_4 -> V_28 ;
V_11 -> V_43 = true ;
F_28 () ;
return 0 ;
}
static void F_29 ( struct V_4 * V_4 )
{
struct V_27 * V_11 = V_4 -> V_28 ;
V_11 -> V_43 = false ;
F_30 ( V_44 ) ;
F_30 ( V_45 ) ;
V_11 -> V_4 = NULL ;
}
static bool F_31 ( unsigned char V_2 , unsigned char V_3 ,
struct V_4 * V_4 )
{
if ( F_32 ( V_46 ) ) {
if ( ( ~ V_3 & V_20 ) &&
( V_2 == 0xfa || V_2 == 0xfe ) ) {
V_46 -- ;
F_16 ( L_14 ) ;
return true ;
}
}
if ( V_8 && V_8 ( V_2 , V_3 , V_4 ) ) {
F_16 ( L_15 ) ;
return true ;
}
return false ;
}
static T_1 F_26 ( int V_47 , void * V_48 )
{
struct V_27 * V_11 ;
struct V_4 * V_4 ;
unsigned long V_5 ;
unsigned char V_3 , V_2 ;
unsigned int V_49 ;
unsigned int V_50 ;
bool V_51 ;
int V_6 = 1 ;
F_7 ( & V_7 , V_5 ) ;
V_3 = F_11 () ;
if ( F_32 ( ~ V_3 & V_14 ) ) {
F_8 ( & V_7 , V_5 ) ;
if ( V_47 )
F_16 ( L_16 , V_47 ) ;
V_6 = 0 ;
goto V_10;
}
V_2 = F_15 () ;
if ( V_52 && ( V_3 & V_20 ) ) {
static unsigned long V_53 ;
static unsigned char V_54 ;
V_49 = 0 ;
if ( V_3 & V_55 ) {
F_16 ( L_17 ,
V_3 , V_2 ) ;
switch ( V_2 ) {
default:
if ( F_33 ( V_56 , V_53 + V_57 / 10 ) ) {
V_3 = V_54 ;
break;
}
case 0xfc :
case 0xfd :
case 0xfe : V_49 = V_58 ; V_2 = 0xfe ; break;
case 0xff : V_49 = V_59 ; V_2 = 0xfe ; break;
}
}
V_50 = V_60 + ( ( V_3 >> 6 ) & 3 ) ;
V_54 = V_3 ;
V_53 = V_56 ;
} else {
V_49 = ( ( V_3 & V_61 ) ? V_59 : 0 ) |
( ( V_3 & V_62 && ! V_63 ) ? V_58 : 0 ) ;
V_50 = ( V_3 & V_20 ) ?
V_36 : V_64 ;
}
V_11 = & V_35 [ V_50 ] ;
V_4 = V_11 -> V_43 ? V_11 -> V_4 : NULL ;
F_16 ( L_18 ,
V_2 , V_50 , V_47 ,
V_49 & V_59 ? L_19 : L_20 ,
V_49 & V_58 ? L_21 : L_20 ) ;
V_51 = F_31 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_7 , V_5 ) ;
if ( F_34 ( V_11 -> V_43 && ! V_51 ) )
F_35 ( V_4 , V_2 , V_49 ) ;
V_10:
return F_36 ( V_6 ) ;
}
static int F_37 ( void )
{
V_41 &= ~ V_40 ;
V_41 |= V_39 ;
if ( F_20 ( & V_41 , V_42 ) ) {
V_41 &= ~ V_39 ;
V_41 |= V_40 ;
F_25 ( L_22 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_38 ( void )
{
V_41 &= ~ V_38 ;
V_41 |= V_37 ;
if ( F_20 ( & V_41 , V_42 ) ) {
V_41 &= ~ V_37 ;
V_41 |= V_38 ;
F_25 ( L_23 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_39 ( void )
{
unsigned char V_22 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_65 ; V_13 ++ ) {
F_20 ( & V_22 , V_66 + V_13 ) ;
F_20 ( & V_22 , V_67 ) ;
}
return F_38 () ;
}
static int F_40 ( bool V_68 , unsigned char * V_69 )
{
unsigned char V_22 , V_70 ;
F_14 () ;
V_22 = V_70 = 0xf0 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 != V_70 )
return - 1 ;
V_22 = V_70 = V_68 ? 0x56 : 0xf6 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 != V_70 )
return - 1 ;
V_22 = V_70 = V_68 ? 0xa4 : 0xa5 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 == V_70 )
return - 1 ;
if ( V_22 == 0xac )
return - 1 ;
if ( V_69 )
* V_69 = V_22 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
unsigned char V_69 ;
if ( F_40 ( true , & V_69 ) )
return - 1 ;
F_42 ( L_24 ,
( V_69 >> 4 ) & 0xf , V_69 & 0xf ) ;
V_41 |= V_38 ;
V_41 &= ~ V_37 ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_25 ) ;
return - V_21 ;
}
V_52 = true ;
return 0 ;
}
static T_1 T_2 F_43 ( int V_47 , void * V_48 )
{
unsigned long V_5 ;
unsigned char V_3 , V_2 ;
int V_6 = 0 ;
F_7 ( & V_7 , V_5 ) ;
V_3 = F_11 () ;
if ( V_3 & V_14 ) {
V_2 = F_15 () ;
F_16 ( L_26 ,
V_2 , V_3 & V_20 ? L_2 : L_3 ) ;
if ( V_71 &&
V_2 == 0xa5 && ( V_3 & V_20 ) )
F_44 ( & V_72 ) ;
V_6 = 1 ;
}
F_8 ( & V_7 , V_5 ) ;
return F_36 ( V_6 ) ;
}
static int T_2 F_45 ( bool V_73 )
{
unsigned char V_22 ;
int V_13 ;
if ( F_20 ( & V_22 ,
V_73 ? V_67 : V_74 ) )
return - 1 ;
for ( V_13 = 0 ; V_13 < 100 ; V_13 ++ ) {
F_12 ( 50 ) ;
if ( F_20 ( & V_22 , V_75 ) )
return - 1 ;
if ( ! ( V_22 & V_38 ) == V_73 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_46 ( void )
{
int V_18 = - 1 ;
bool V_76 = false ;
bool V_77 = false ;
unsigned long V_5 ;
unsigned char V_22 ;
F_14 () ;
V_22 = 0x5a ;
V_18 = F_20 ( & V_22 , V_25 ) ;
if ( V_18 || V_22 != 0x5a ) {
if ( F_20 ( & V_22 , V_78 ) ||
( V_22 && V_22 != 0xfa && V_22 != 0xff ) )
return - 1 ;
if ( ! V_18 )
V_77 = true ;
}
if ( F_45 ( false ) ) {
F_24 ( L_27 ) ;
F_24 ( L_28 ) ;
}
if ( F_45 ( true ) )
return - 1 ;
if ( V_79 ) {
F_24 ( L_29 ) ;
F_21 ( NULL , ( unsigned char ) 0xff ) ;
}
if ( V_24 || V_80 || V_77 ) {
V_18 = 0 ;
goto V_10;
}
if ( F_47 ( V_44 , F_43 , V_81 ,
L_30 , V_82 ) )
goto V_10;
V_76 = true ;
if ( F_38 () )
goto V_10;
F_7 ( & V_7 , V_5 ) ;
F_48 ( & V_72 ) ;
V_71 = true ;
V_22 = 0xa5 ;
V_18 = F_17 ( & V_22 , V_25 & 0xf0ff ) ;
F_8 ( & V_7 , V_5 ) ;
if ( V_18 )
goto V_10;
if ( F_49 ( & V_72 ,
F_50 ( 250 ) ) == 0 ) {
F_16 ( L_31 ) ;
F_14 () ;
V_18 = - 1 ;
}
V_10:
V_41 |= V_38 ;
V_41 &= ~ V_37 ;
if ( F_20 ( & V_41 , V_42 ) )
V_18 = - 1 ;
if ( V_76 )
F_51 ( V_44 , V_82 ) ;
return V_18 ;
}
static int F_52 ( void )
{
if ( F_14 () ) {
F_25 ( L_32 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_53 ( void )
{
unsigned char V_22 ;
int V_13 = 0 ;
do {
if ( F_20 ( & V_22 , V_84 ) ) {
F_25 ( L_33 ) ;
return - V_83 ;
}
if ( V_22 == V_85 )
return 0 ;
F_16 ( L_34 ,
V_22 , V_85 ) ;
F_54 ( 50 ) ;
} while ( V_13 ++ < 5 );
#ifdef F_55
F_42 ( L_35 ) ;
return 0 ;
#else
F_25 ( L_36 ) ;
return - V_21 ;
#endif
}
static int F_56 ( void )
{
unsigned long V_5 ;
int V_86 = 0 ;
unsigned char V_87 [ 2 ] ;
do {
if ( V_86 >= 10 ) {
F_25 ( L_37 ) ;
return - V_21 ;
}
if ( V_86 != 0 )
F_12 ( 50 ) ;
if ( F_20 ( & V_87 [ V_86 ++ % 2 ] , V_75 ) ) {
F_25 ( L_38 ) ;
return - V_21 ;
}
} while ( V_86 < 2 || V_87 [ 0 ] != V_87 [ 1 ] );
V_88 = V_41 = V_87 [ 0 ] ;
V_41 |= V_40 ;
V_41 &= ~ V_39 ;
F_7 ( & V_7 , V_5 ) ;
if ( ~ F_11 () & V_89 ) {
if ( V_90 )
V_41 |= V_91 ;
else
F_24 ( L_39 ) ;
}
F_8 ( & V_7 , V_5 ) ;
if ( ~ V_41 & V_92 )
V_93 = true ;
if ( V_93 )
V_41 &= ~ V_92 ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_40 ) ;
return - V_21 ;
}
F_14 () ;
return 0 ;
}
static void F_57 ( bool V_94 )
{
F_14 () ;
V_41 |= V_40 | V_38 ;
V_41 &= ~ ( V_39 | V_37 ) ;
if ( F_20 ( & V_41 , V_42 ) )
F_24 ( L_41 ) ;
if ( V_52 )
F_40 ( false , NULL ) ;
if ( V_95 || V_94 )
F_53 () ;
if ( F_20 ( & V_88 , V_42 ) )
F_24 ( L_42 ) ;
}
static long F_58 ( int V_96 )
{
long V_97 = 0 ;
char V_98 ;
V_98 = ( V_96 ) ? 0x01 | 0x04 : 0 ;
while ( F_11 () & V_16 )
V_99 ;
F_16 ( L_43 , 0xed ) ;
V_46 = 2 ;
F_19 ( 0xed ) ;
V_99 ;
while ( F_11 () & V_16 )
V_99 ;
V_99 ;
F_16 ( L_43 , V_98 ) ;
F_19 ( V_98 ) ;
V_99 ;
return V_97 ;
}
static void F_59 ( void )
{
unsigned char V_22 = 0x90 ;
int error ;
error = F_20 ( & V_22 , 0x1059 ) ;
if ( error )
F_24 ( L_44 , error ) ;
}
static int F_60 ( bool V_94 )
{
int error ;
error = F_52 () ;
if ( error )
return error ;
if ( V_95 || V_94 ) {
error = F_53 () ;
if ( error )
return error ;
}
V_41 = V_88 ;
if ( V_93 )
V_41 &= ~ V_92 ;
V_41 |= V_38 | V_40 ;
V_41 &= ~ ( V_37 | V_39 ) ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_24 ( L_45 ) ;
F_54 ( 50 ) ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_46 ) ;
return - V_21 ;
}
}
#ifdef F_55
if ( V_100 )
F_59 () ;
#endif
if ( V_52 ) {
if ( F_40 ( true , NULL ) || F_39 () )
F_24 ( L_47 ) ;
} else if ( V_35 [ V_36 ] . V_4 )
F_38 () ;
if ( V_35 [ V_64 ] . V_4 )
F_37 () ;
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_61 ( struct V_101 * V_102 )
{
F_57 ( true ) ;
return 0 ;
}
static int F_62 ( struct V_101 * V_102 )
{
return F_60 ( true ) ;
}
static int F_63 ( struct V_101 * V_102 )
{
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_64 ( struct V_101 * V_102 )
{
F_57 ( false ) ;
return 0 ;
}
static int F_65 ( struct V_101 * V_102 )
{
return F_60 ( false ) ;
}
static void F_66 ( struct V_103 * V_102 )
{
F_57 ( false ) ;
}
static int T_2 F_67 ( void )
{
struct V_4 * V_4 ;
struct V_27 * V_11 = & V_35 [ V_64 ] ;
V_4 = F_68 ( sizeof( struct V_4 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
V_4 -> V_106 . type = V_93 ? V_107 : V_108 ;
V_4 -> V_109 = V_110 ? NULL : F_21 ;
V_4 -> V_111 = F_27 ;
V_4 -> V_112 = F_29 ;
V_4 -> V_113 = F_23 ;
V_4 -> V_28 = V_11 ;
V_4 -> V_102 . V_114 = & V_82 -> V_102 ;
F_69 ( V_4 -> V_115 , L_48 , sizeof( V_4 -> V_115 ) ) ;
F_69 ( V_4 -> V_116 , V_117 , sizeof( V_4 -> V_116 ) ) ;
F_69 ( V_4 -> V_118 , V_119 ,
sizeof( V_4 -> V_118 ) ) ;
V_11 -> V_4 = V_4 ;
V_11 -> V_47 = V_45 ;
return 0 ;
}
static int T_2 F_70 ( int V_120 )
{
struct V_4 * V_4 ;
int V_50 = V_120 < 0 ? V_36 : V_60 + V_120 ;
struct V_27 * V_11 = & V_35 [ V_50 ] ;
V_4 = F_68 ( sizeof( struct V_4 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
V_4 -> V_106 . type = V_107 ;
V_4 -> V_109 = F_22 ;
V_4 -> V_111 = F_27 ;
V_4 -> V_112 = F_29 ;
V_4 -> V_28 = V_11 ;
V_4 -> V_102 . V_114 = & V_82 -> V_102 ;
if ( V_120 < 0 ) {
F_69 ( V_4 -> V_115 , L_49 , sizeof( V_4 -> V_115 ) ) ;
F_69 ( V_4 -> V_116 , V_121 , sizeof( V_4 -> V_116 ) ) ;
F_69 ( V_4 -> V_118 , V_122 ,
sizeof( V_4 -> V_118 ) ) ;
V_4 -> V_113 = F_23 ;
} else {
snprintf ( V_4 -> V_115 , sizeof( V_4 -> V_115 ) , L_50 , V_120 ) ;
snprintf ( V_4 -> V_116 , sizeof( V_4 -> V_116 ) , V_123 , V_120 + 1 ) ;
F_69 ( V_4 -> V_118 , V_122 ,
sizeof( V_4 -> V_118 ) ) ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_29 = V_120 ;
V_11 -> V_47 = V_44 ;
return 0 ;
}
static void T_2 F_71 ( void )
{
F_72 ( V_35 [ V_64 ] . V_4 ) ;
V_35 [ V_64 ] . V_4 = NULL ;
}
static void T_2 F_73 ( void )
{
int V_13 ;
for ( V_13 = V_36 ; V_13 < V_124 ; V_13 ++ ) {
F_72 ( V_35 [ V_13 ] . V_4 ) ;
V_35 [ V_13 ] . V_4 = NULL ;
}
}
static void T_2 F_74 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_124 ; V_13 ++ ) {
if ( V_35 [ V_13 ] . V_4 ) {
F_75 ( V_125 L_51 ,
V_35 [ V_13 ] . V_4 -> V_115 ,
( unsigned long ) V_126 ,
( unsigned long ) V_127 ,
V_35 [ V_13 ] . V_47 ) ;
F_76 ( V_35 [ V_13 ] . V_4 ) ;
}
}
}
static void F_77 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_124 ; V_13 ++ ) {
if ( V_35 [ V_13 ] . V_4 ) {
F_78 ( V_35 [ V_13 ] . V_4 ) ;
V_35 [ V_13 ] . V_4 = NULL ;
}
}
}
bool F_79 ( const struct V_4 * V_11 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_124 ; V_13 ++ )
if ( V_35 [ V_13 ] . V_4 == V_11 )
return true ;
return false ;
}
static void F_80 ( void )
{
if ( V_128 )
F_51 ( V_44 , V_82 ) ;
if ( V_129 )
F_51 ( V_45 , V_82 ) ;
V_128 = V_129 = false ;
}
static int T_2 F_81 ( void )
{
int (* F_82)( void );
int error ;
int V_13 ;
if ( F_46 () )
return - V_83 ;
if ( V_130 || F_41 () ) {
error = F_70 ( - 1 ) ;
if ( error )
goto V_131;
F_82 = F_38 ;
} else {
for ( V_13 = 0 ; V_13 < V_65 ; V_13 ++ ) {
error = F_70 ( V_13 ) ;
if ( error )
goto V_131;
}
F_82 = F_39 ;
}
error = F_47 ( V_44 , F_26 , V_81 ,
L_30 , V_82 ) ;
if ( error )
goto V_131;
if ( F_82 () )
goto V_132;
V_128 = true ;
return 0 ;
V_132:
F_51 ( V_44 , V_82 ) ;
V_131:
F_73 () ;
return error ;
}
static int T_2 F_83 ( void )
{
int error ;
error = F_67 () ;
if ( error )
return error ;
error = F_47 ( V_45 , F_26 , V_81 ,
L_30 , V_82 ) ;
if ( error )
goto V_133;
error = F_37 () ;
if ( error )
goto V_132;
V_129 = true ;
return 0 ;
V_132:
F_51 ( V_45 , V_82 ) ;
V_133:
F_71 () ;
return error ;
}
static int T_2 F_84 ( struct V_103 * V_102 )
{
int error ;
V_82 = V_102 ;
if ( V_95 ) {
error = F_53 () ;
if ( error )
return error ;
}
error = F_56 () ;
if ( error )
return error ;
#ifdef F_55
if ( V_100 )
F_59 () ;
#endif
if ( ! V_134 ) {
error = F_81 () ;
if ( error && error != - V_83 && error != - V_9 )
goto V_135;
}
if ( ! V_136 ) {
error = F_83 () ;
if ( error )
goto V_135;
}
F_74 () ;
return 0 ;
V_135:
F_73 () ;
F_80 () ;
F_57 ( false ) ;
V_82 = NULL ;
return error ;
}
static int F_85 ( struct V_103 * V_102 )
{
F_77 () ;
F_80 () ;
F_57 ( false ) ;
V_82 = NULL ;
return 0 ;
}
static int T_2 F_86 ( void )
{
struct V_103 * V_137 ;
int V_138 ;
F_87 () ;
V_138 = F_88 () ;
if ( V_138 )
return V_138 ;
V_138 = F_52 () ;
if ( V_138 )
goto V_139;
V_137 = F_89 ( & V_140 , F_84 , NULL , 0 , NULL , 0 ) ;
if ( F_90 ( V_137 ) ) {
V_138 = F_91 ( V_137 ) ;
goto V_139;
}
V_141 = F_58 ;
return 0 ;
V_139:
F_92 () ;
return V_138 ;
}
static void T_3 F_93 ( void )
{
F_94 ( V_82 ) ;
F_95 ( & V_140 ) ;
F_92 () ;
V_141 = NULL ;
}
