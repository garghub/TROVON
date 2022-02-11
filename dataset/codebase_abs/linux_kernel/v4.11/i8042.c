static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
enum V_4 * V_5 = V_3 -> V_5 ;
int error ;
bool V_6 ;
if ( V_1 ) {
error = F_2 ( V_1 , & V_6 ) ;
if ( error )
return error ;
} else {
V_6 = true ;
}
* V_5 = V_6 ? V_7 : V_8 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( & V_9 ) ;
}
void F_5 ( void )
{
F_6 ( & V_9 ) ;
}
int F_7 ( bool (* F_8)( unsigned char V_10 , unsigned char V_11 ,
struct V_12 * V_12 ) )
{
unsigned long V_13 ;
int V_14 = 0 ;
F_9 ( & V_15 , V_13 ) ;
if ( V_16 ) {
V_14 = - V_17 ;
goto V_18;
}
V_16 = F_8 ;
V_18:
F_10 ( & V_15 , V_13 ) ;
return V_14 ;
}
int F_11 ( bool (* F_8)( unsigned char V_10 , unsigned char V_11 ,
struct V_12 * V_19 ) )
{
unsigned long V_13 ;
int V_14 = 0 ;
F_9 ( & V_15 , V_13 ) ;
if ( V_16 != F_8 ) {
V_14 = - V_20 ;
goto V_18;
}
V_16 = NULL ;
V_18:
F_10 ( & V_15 , V_13 ) ;
return V_14 ;
}
static int F_12 ( void )
{
int V_21 = 0 ;
while ( ( ~ F_13 () & V_22 ) && ( V_21 < V_23 ) ) {
F_14 ( 50 ) ;
V_21 ++ ;
}
return - ( V_21 == V_23 ) ;
}
static int F_15 ( void )
{
int V_21 = 0 ;
while ( ( F_13 () & V_24 ) && ( V_21 < V_23 ) ) {
F_14 ( 50 ) ;
V_21 ++ ;
}
return - ( V_21 == V_23 ) ;
}
static int F_16 ( void )
{
unsigned long V_13 ;
unsigned char V_10 , V_11 ;
int V_25 = 0 ;
int V_26 = 0 ;
F_9 ( & V_15 , V_13 ) ;
while ( ( V_11 = F_13 () ) & V_22 ) {
if ( V_25 ++ < V_27 ) {
F_14 ( 50 ) ;
V_10 = F_17 () ;
F_18 ( L_1 ,
V_10 , V_11 & V_28 ? L_2 : L_3 ) ;
} else {
V_26 = - V_29 ;
break;
}
}
F_10 ( & V_15 , V_13 ) ;
return V_26 ;
}
static int F_19 ( unsigned char * V_30 , int V_31 )
{
int V_21 , error ;
if ( V_32 && V_31 == V_33 )
return - 1 ;
error = F_15 () ;
if ( error )
return error ;
F_18 ( L_4 , V_31 & 0xff ) ;
F_20 ( V_31 & 0xff ) ;
for ( V_21 = 0 ; V_21 < ( ( V_31 >> 12 ) & 0xf ) ; V_21 ++ ) {
error = F_15 () ;
if ( error ) {
F_18 ( L_5 ) ;
return error ;
}
F_18 ( L_6 , V_30 [ V_21 ] ) ;
F_21 ( V_30 [ V_21 ] ) ;
}
for ( V_21 = 0 ; V_21 < ( ( V_31 >> 8 ) & 0xf ) ; V_21 ++ ) {
error = F_12 () ;
if ( error ) {
F_18 ( L_7 ) ;
return error ;
}
if ( V_31 == V_33 &&
! ( F_13 () & V_28 ) ) {
F_18 ( L_8 ) ;
return - 1 ;
}
V_30 [ V_21 ] = F_17 () ;
F_18 ( L_9 , V_30 [ V_21 ] ) ;
}
return 0 ;
}
int F_22 ( unsigned char * V_30 , int V_31 )
{
unsigned long V_13 ;
int V_26 ;
F_9 ( & V_15 , V_13 ) ;
V_26 = F_19 ( V_30 , V_31 ) ;
F_10 ( & V_15 , V_13 ) ;
return V_26 ;
}
static int F_23 ( struct V_12 * V_19 , unsigned char V_34 )
{
unsigned long V_13 ;
int V_26 = 0 ;
F_9 ( & V_15 , V_13 ) ;
if ( ! ( V_26 = F_15 () ) ) {
F_18 ( L_10 , V_34 ) ;
F_21 ( V_34 ) ;
}
F_10 ( & V_15 , V_13 ) ;
return V_26 ;
}
static int F_24 ( struct V_12 * V_12 , unsigned char V_34 )
{
struct V_35 * V_19 = V_12 -> V_36 ;
return F_22 ( & V_34 , V_19 -> V_37 == - 1 ?
V_38 :
V_39 + V_19 -> V_37 ) ;
}
static void F_25 ( struct V_12 * V_12 )
{
int V_40 ;
int V_41 ;
const char * V_42 ;
if ( V_12 == V_43 [ V_44 ] . V_12 ) {
V_40 = V_45 ;
V_41 = V_46 ;
V_42 = L_11 ;
} else {
V_40 = V_47 ;
V_41 = V_48 ;
V_42 = L_12 ;
}
V_49 &= ~ V_40 ;
if ( F_22 ( & V_49 , V_50 ) )
F_26 ( L_13 , V_42 ) ;
F_14 ( 50 ) ;
V_49 &= ~ V_41 ;
V_49 |= V_40 ;
if ( F_22 ( & V_49 , V_50 ) )
F_27 ( L_14 , V_42 ) ;
F_28 ( 0 , NULL ) ;
}
static int F_29 ( struct V_12 * V_12 )
{
struct V_35 * V_19 = V_12 -> V_36 ;
V_19 -> V_51 = true ;
F_30 () ;
return 0 ;
}
static void F_31 ( struct V_12 * V_12 )
{
struct V_35 * V_19 = V_12 -> V_36 ;
V_19 -> V_51 = false ;
F_32 ( V_52 ) ;
F_32 ( V_53 ) ;
V_19 -> V_12 = NULL ;
}
static bool F_33 ( unsigned char V_10 , unsigned char V_11 ,
struct V_12 * V_12 )
{
if ( F_34 ( V_54 ) ) {
if ( ( ~ V_11 & V_28 ) &&
( V_10 == 0xfa || V_10 == 0xfe ) ) {
V_54 -- ;
F_18 ( L_15 ) ;
return true ;
}
}
if ( V_16 && V_16 ( V_10 , V_11 , V_12 ) ) {
F_18 ( L_16 ) ;
return true ;
}
return false ;
}
static T_1 F_28 ( int V_55 , void * V_56 )
{
struct V_35 * V_19 ;
struct V_12 * V_12 ;
unsigned long V_13 ;
unsigned char V_11 , V_10 ;
unsigned int V_57 ;
unsigned int V_58 ;
bool V_59 ;
int V_14 = 1 ;
F_9 ( & V_15 , V_13 ) ;
V_11 = F_13 () ;
if ( F_34 ( ~ V_11 & V_22 ) ) {
F_10 ( & V_15 , V_13 ) ;
if ( V_55 )
F_18 ( L_17 , V_55 ) ;
V_14 = 0 ;
goto V_18;
}
V_10 = F_17 () ;
if ( V_60 && ( V_11 & V_28 ) ) {
static unsigned long V_61 ;
static unsigned char V_62 ;
V_57 = 0 ;
if ( V_11 & V_63 ) {
F_18 ( L_18 ,
V_11 , V_10 ) ;
switch ( V_10 ) {
default:
if ( F_35 ( V_64 , V_61 + V_65 / 10 ) ) {
V_11 = V_62 ;
break;
}
case 0xfc :
case 0xfd :
case 0xfe : V_57 = V_66 ; V_10 = 0xfe ; break;
case 0xff : V_57 = V_67 ; V_10 = 0xfe ; break;
}
}
V_58 = V_68 + ( ( V_11 >> 6 ) & 3 ) ;
V_62 = V_11 ;
V_61 = V_64 ;
} else {
V_57 = ( ( V_11 & V_69 ) ? V_67 : 0 ) |
( ( V_11 & V_70 && ! V_71 ) ? V_66 : 0 ) ;
V_58 = ( V_11 & V_28 ) ?
V_44 : V_72 ;
}
V_19 = & V_43 [ V_58 ] ;
V_12 = V_19 -> V_51 ? V_19 -> V_12 : NULL ;
F_36 ( V_19 -> V_73 , V_10 , L_19 ,
V_58 , V_55 ,
V_57 & V_67 ? L_20 : L_21 ,
V_57 & V_66 ? L_22 : L_21 ) ;
V_59 = F_33 ( V_10 , V_11 , V_12 ) ;
F_10 ( & V_15 , V_13 ) ;
if ( F_37 ( V_19 -> V_51 && ! V_59 ) )
F_38 ( V_12 , V_10 , V_57 ) ;
V_18:
return F_39 ( V_14 ) ;
}
static int F_40 ( void )
{
V_49 &= ~ V_48 ;
V_49 |= V_47 ;
if ( F_22 ( & V_49 , V_50 ) ) {
V_49 &= ~ V_47 ;
V_49 |= V_48 ;
F_27 ( L_23 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_41 ( void )
{
V_49 &= ~ V_46 ;
V_49 |= V_45 ;
if ( F_22 ( & V_49 , V_50 ) ) {
V_49 &= ~ V_45 ;
V_49 |= V_46 ;
F_27 ( L_24 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_42 ( void )
{
unsigned char V_30 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_74 ; V_21 ++ ) {
F_22 ( & V_30 , V_75 + V_21 ) ;
F_22 ( & V_30 , V_76 ) ;
}
return F_41 () ;
}
static int F_43 ( bool V_77 , unsigned char * V_78 )
{
unsigned char V_30 , V_1 ;
F_16 () ;
V_30 = V_1 = 0xf0 ;
if ( F_22 ( & V_30 , V_33 ) || V_30 != V_1 )
return - 1 ;
V_30 = V_1 = V_77 ? 0x56 : 0xf6 ;
if ( F_22 ( & V_30 , V_33 ) || V_30 != V_1 )
return - 1 ;
V_30 = V_1 = V_77 ? 0xa4 : 0xa5 ;
if ( F_22 ( & V_30 , V_33 ) || V_30 == V_1 )
return - 1 ;
if ( V_30 == 0xac )
return - 1 ;
if ( V_78 )
* V_78 = V_30 ;
return 0 ;
}
static int T_2 F_44 ( void )
{
unsigned char V_78 ;
if ( F_43 ( true , & V_78 ) )
return - 1 ;
F_45 ( L_25 ,
( V_78 >> 4 ) & 0xf , V_78 & 0xf ) ;
V_49 |= V_46 ;
V_49 &= ~ V_45 ;
if ( F_22 ( & V_49 , V_50 ) ) {
F_27 ( L_26 ) ;
return - V_29 ;
}
V_60 = true ;
return 0 ;
}
static T_1 T_2 F_46 ( int V_55 , void * V_56 )
{
unsigned long V_13 ;
unsigned char V_11 , V_10 ;
int V_14 = 0 ;
F_9 ( & V_15 , V_13 ) ;
V_11 = F_13 () ;
if ( V_11 & V_22 ) {
V_10 = F_17 () ;
F_18 ( L_27 ,
V_10 , V_11 & V_28 ? L_2 : L_3 ) ;
if ( V_79 &&
V_10 == 0xa5 && ( V_11 & V_28 ) )
F_47 ( & V_80 ) ;
V_14 = 1 ;
}
F_10 ( & V_15 , V_13 ) ;
return F_39 ( V_14 ) ;
}
static int T_2 F_48 ( bool V_81 )
{
unsigned char V_30 ;
int V_21 ;
if ( F_22 ( & V_30 ,
V_81 ? V_76 : V_82 ) )
return - 1 ;
for ( V_21 = 0 ; V_21 < 100 ; V_21 ++ ) {
F_14 ( 50 ) ;
if ( F_22 ( & V_30 , V_83 ) )
return - 1 ;
if ( ! ( V_30 & V_46 ) == V_81 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_49 ( void )
{
int V_26 = - 1 ;
bool V_84 = false ;
bool V_85 = false ;
unsigned long V_13 ;
unsigned char V_30 ;
F_16 () ;
V_30 = 0x5a ;
V_26 = F_22 ( & V_30 , V_33 ) ;
if ( V_26 || V_30 != 0x5a ) {
if ( F_22 ( & V_30 , V_86 ) ||
( V_30 && V_30 != 0xfa && V_30 != 0xff ) )
return - 1 ;
if ( ! V_26 )
V_85 = true ;
}
if ( F_48 ( false ) ) {
F_26 ( L_28 ) ;
F_26 ( L_29 ) ;
}
if ( F_48 ( true ) )
return - 1 ;
if ( V_87 ) {
F_26 ( L_30 ) ;
F_23 ( NULL , ( unsigned char ) 0xff ) ;
}
if ( V_32 || V_88 || V_85 ) {
V_26 = 0 ;
goto V_18;
}
if ( F_50 ( V_52 , F_46 , V_89 ,
L_31 , V_90 ) )
goto V_18;
V_84 = true ;
if ( F_41 () )
goto V_18;
F_9 ( & V_15 , V_13 ) ;
F_51 ( & V_80 ) ;
V_79 = true ;
V_30 = 0xa5 ;
V_26 = F_19 ( & V_30 , V_33 & 0xf0ff ) ;
F_10 ( & V_15 , V_13 ) ;
if ( V_26 )
goto V_18;
if ( F_52 ( & V_80 ,
F_53 ( 250 ) ) == 0 ) {
F_18 ( L_32 ) ;
F_16 () ;
V_26 = - 1 ;
}
V_18:
V_49 |= V_46 ;
V_49 &= ~ V_45 ;
if ( F_22 ( & V_49 , V_50 ) )
V_26 = - 1 ;
if ( V_84 )
F_54 ( V_52 , V_90 ) ;
return V_26 ;
}
static int F_55 ( void )
{
if ( F_16 () ) {
F_45 ( L_33 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_56 ( void )
{
unsigned char V_30 ;
int V_21 = 0 ;
do {
if ( F_22 ( & V_30 , V_92 ) ) {
F_27 ( L_34 ) ;
return - V_91 ;
}
if ( V_30 == V_93 )
return 0 ;
F_18 ( L_35 ,
V_30 , V_93 ) ;
F_57 ( 50 ) ;
} while ( V_21 ++ < 5 );
#ifdef F_58
F_45 ( L_36 ) ;
return 0 ;
#else
F_27 ( L_37 ) ;
return - V_29 ;
#endif
}
static int F_59 ( void )
{
unsigned long V_13 ;
int V_94 = 0 ;
unsigned char V_95 [ 2 ] ;
do {
if ( V_94 >= 10 ) {
F_27 ( L_38 ) ;
return - V_29 ;
}
if ( V_94 != 0 )
F_14 ( 50 ) ;
if ( F_22 ( & V_95 [ V_94 ++ % 2 ] , V_83 ) ) {
F_27 ( L_39 ) ;
return - V_29 ;
}
} while ( V_94 < 2 || V_95 [ 0 ] != V_95 [ 1 ] );
V_96 = V_49 = V_95 [ 0 ] ;
V_49 |= V_48 ;
V_49 &= ~ V_47 ;
F_9 ( & V_15 , V_13 ) ;
if ( ~ F_13 () & V_97 ) {
if ( V_98 )
V_49 |= V_99 ;
else
F_26 ( L_40 ) ;
}
F_10 ( & V_15 , V_13 ) ;
if ( ~ V_49 & V_100 )
V_101 = true ;
if ( V_101 )
V_49 &= ~ V_100 ;
if ( F_22 ( & V_49 , V_50 ) ) {
F_27 ( L_41 ) ;
return - V_29 ;
}
F_16 () ;
return 0 ;
}
static void F_60 ( bool V_102 )
{
F_16 () ;
V_49 |= V_48 | V_46 ;
V_49 &= ~ ( V_47 | V_45 ) ;
if ( F_22 ( & V_49 , V_50 ) )
F_26 ( L_42 ) ;
if ( V_60 )
F_43 ( false , NULL ) ;
if ( V_103 == V_7 ||
( V_103 == V_104 && V_102 ) ) {
F_56 () ;
}
if ( F_22 ( & V_96 , V_50 ) )
F_26 ( L_43 ) ;
}
static long F_61 ( int V_105 )
{
long V_106 = 0 ;
char V_107 ;
V_107 = ( V_105 ) ? 0x01 | 0x04 : 0 ;
while ( F_13 () & V_24 )
V_108 ;
F_18 ( L_44 , 0xed ) ;
V_54 = 2 ;
F_21 ( 0xed ) ;
V_108 ;
while ( F_13 () & V_24 )
V_108 ;
V_108 ;
F_18 ( L_44 , V_107 ) ;
F_21 ( V_107 ) ;
V_108 ;
return V_106 ;
}
static void F_62 ( void )
{
unsigned char V_30 = 0x90 ;
int error ;
error = F_22 ( & V_30 , 0x1059 ) ;
if ( error )
F_26 ( L_45 , error ) ;
}
static int F_63 ( bool V_102 )
{
int error ;
error = F_55 () ;
if ( error )
return error ;
if ( V_103 == V_7 ||
( V_103 == V_104 && V_102 ) ) {
error = F_56 () ;
if ( error )
return error ;
}
V_49 = V_96 ;
if ( V_101 )
V_49 &= ~ V_100 ;
V_49 |= V_46 | V_48 ;
V_49 &= ~ ( V_45 | V_47 ) ;
if ( F_22 ( & V_49 , V_50 ) ) {
F_26 ( L_46 ) ;
F_57 ( 50 ) ;
if ( F_22 ( & V_49 , V_50 ) ) {
F_27 ( L_47 ) ;
return - V_29 ;
}
}
#ifdef F_58
if ( V_109 )
F_62 () ;
#endif
if ( V_60 ) {
if ( F_43 ( true , NULL ) || F_42 () )
F_26 ( L_48 ) ;
} else if ( V_43 [ V_44 ] . V_12 )
F_41 () ;
if ( V_43 [ V_72 ] . V_12 )
F_40 () ;
F_28 ( 0 , NULL ) ;
return 0 ;
}
static int F_64 ( struct V_110 * V_111 )
{
int V_21 ;
if ( F_65 () )
F_60 ( true ) ;
for ( V_21 = 0 ; V_21 < V_112 ; V_21 ++ ) {
struct V_12 * V_12 = V_43 [ V_21 ] . V_12 ;
if ( V_12 && F_66 ( & V_12 -> V_111 ) )
F_67 ( V_43 [ V_21 ] . V_55 ) ;
}
return 0 ;
}
static int F_68 ( struct V_110 * V_111 )
{
if ( ! F_69 () )
F_28 ( 0 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_110 * V_111 )
{
bool V_113 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_112 ; V_21 ++ ) {
struct V_12 * V_12 = V_43 [ V_21 ] . V_12 ;
if ( V_12 && F_66 ( & V_12 -> V_111 ) )
F_71 ( V_43 [ V_21 ] . V_55 ) ;
}
if ( ! F_65 () )
return 0 ;
V_113 = F_69 () ;
return F_63 ( V_113 ) ;
}
static int F_72 ( struct V_110 * V_111 )
{
F_28 ( 0 , NULL ) ;
return 0 ;
}
static int F_73 ( struct V_110 * V_111 )
{
F_60 ( false ) ;
return 0 ;
}
static int F_74 ( struct V_110 * V_111 )
{
return F_63 ( false ) ;
}
static void F_75 ( struct V_114 * V_111 )
{
F_60 ( false ) ;
}
static int T_2 F_76 ( void )
{
struct V_12 * V_12 ;
struct V_35 * V_19 = & V_43 [ V_72 ] ;
V_12 = F_77 ( sizeof( struct V_12 ) , V_115 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_117 . type = V_101 ? V_118 : V_119 ;
V_12 -> V_120 = V_121 ? NULL : F_23 ;
V_12 -> V_122 = F_29 ;
V_12 -> V_123 = F_31 ;
V_12 -> V_124 = F_25 ;
V_12 -> V_125 = & V_9 ;
V_12 -> V_36 = V_19 ;
V_12 -> V_111 . V_126 = & V_90 -> V_111 ;
F_78 ( V_12 -> V_127 , L_49 , sizeof( V_12 -> V_127 ) ) ;
F_78 ( V_12 -> V_128 , V_129 , sizeof( V_12 -> V_128 ) ) ;
F_78 ( V_12 -> V_130 , V_131 ,
sizeof( V_12 -> V_130 ) ) ;
V_19 -> V_12 = V_12 ;
V_19 -> V_55 = V_53 ;
return 0 ;
}
static int T_2 F_79 ( int V_132 )
{
struct V_12 * V_12 ;
int V_58 = V_132 < 0 ? V_44 : V_68 + V_132 ;
struct V_35 * V_19 = & V_43 [ V_58 ] ;
V_12 = F_77 ( sizeof( struct V_12 ) , V_115 ) ;
if ( ! V_12 )
return - V_116 ;
V_12 -> V_117 . type = V_118 ;
V_12 -> V_120 = F_24 ;
V_12 -> V_122 = F_29 ;
V_12 -> V_123 = F_31 ;
V_12 -> V_125 = & V_9 ;
V_12 -> V_36 = V_19 ;
V_12 -> V_111 . V_126 = & V_90 -> V_111 ;
if ( V_132 < 0 ) {
F_78 ( V_12 -> V_127 , L_50 , sizeof( V_12 -> V_127 ) ) ;
F_78 ( V_12 -> V_128 , V_133 , sizeof( V_12 -> V_128 ) ) ;
F_78 ( V_12 -> V_130 , V_134 ,
sizeof( V_12 -> V_130 ) ) ;
V_12 -> V_124 = F_25 ;
} else {
snprintf ( V_12 -> V_127 , sizeof( V_12 -> V_127 ) , L_51 , V_132 ) ;
snprintf ( V_12 -> V_128 , sizeof( V_12 -> V_128 ) , V_135 , V_132 + 1 ) ;
F_78 ( V_12 -> V_130 , V_134 ,
sizeof( V_12 -> V_130 ) ) ;
}
V_19 -> V_12 = V_12 ;
V_19 -> V_37 = V_132 ;
V_19 -> V_55 = V_52 ;
return 0 ;
}
static void T_2 F_80 ( void )
{
F_81 ( V_43 [ V_72 ] . V_12 ) ;
V_43 [ V_72 ] . V_12 = NULL ;
}
static void T_2 F_82 ( void )
{
int V_21 ;
for ( V_21 = V_44 ; V_21 < V_112 ; V_21 ++ ) {
F_81 ( V_43 [ V_21 ] . V_12 ) ;
V_43 [ V_21 ] . V_12 = NULL ;
}
}
static void T_2 F_83 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_112 ; V_21 ++ ) {
struct V_12 * V_12 = V_43 [ V_21 ] . V_12 ;
if ( V_12 ) {
F_84 ( V_136 L_52 ,
V_12 -> V_127 ,
( unsigned long ) V_137 ,
( unsigned long ) V_138 ,
V_43 [ V_21 ] . V_55 ) ;
F_85 ( V_12 ) ;
F_86 ( & V_12 -> V_111 , true ) ;
}
}
}
static void F_87 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_112 ; V_21 ++ ) {
if ( V_43 [ V_21 ] . V_12 ) {
F_88 ( V_43 [ V_21 ] . V_12 ) ;
V_43 [ V_21 ] . V_12 = NULL ;
}
}
}
static void F_89 ( void )
{
if ( V_139 )
F_54 ( V_52 , V_90 ) ;
if ( V_140 )
F_54 ( V_53 , V_90 ) ;
V_139 = V_140 = false ;
}
static int T_2 F_90 ( void )
{
int (* F_91)( void );
int error ;
int V_21 ;
if ( F_49 () )
return - V_91 ;
if ( V_141 || F_44 () ) {
error = F_79 ( - 1 ) ;
if ( error )
goto V_142;
F_91 = F_41 ;
} else {
for ( V_21 = 0 ; V_21 < V_74 ; V_21 ++ ) {
error = F_79 ( V_21 ) ;
if ( error )
goto V_142;
}
F_91 = F_42 ;
}
error = F_50 ( V_52 , F_28 , V_89 ,
L_31 , V_90 ) ;
if ( error )
goto V_142;
if ( F_91 () )
goto V_143;
V_139 = true ;
return 0 ;
V_143:
F_54 ( V_52 , V_90 ) ;
V_142:
F_82 () ;
return error ;
}
static int T_2 F_92 ( void )
{
int error ;
error = F_76 () ;
if ( error )
return error ;
error = F_50 ( V_53 , F_28 , V_89 ,
L_31 , V_90 ) ;
if ( error )
goto V_144;
error = F_40 () ;
if ( error )
goto V_143;
V_140 = true ;
return 0 ;
V_143:
F_54 ( V_53 , V_90 ) ;
V_144:
F_80 () ;
return error ;
}
static int F_93 ( struct V_145 * V_146 ,
unsigned long V_147 , void * V_10 )
{
struct V_110 * V_111 = V_10 ;
struct V_12 * V_12 = F_94 ( V_111 ) ;
struct V_35 * V_19 = V_12 -> V_36 ;
if ( V_12 != V_43 [ V_72 ] . V_12 )
return 0 ;
switch ( V_147 ) {
case V_148 :
V_19 -> V_73 = true ;
break;
case V_149 :
V_19 -> V_73 = false ;
break;
}
return 0 ;
}
static int T_2 F_95 ( struct V_114 * V_111 )
{
int error ;
V_90 = V_111 ;
if ( V_103 == V_7 ) {
error = F_56 () ;
if ( error )
return error ;
}
error = F_59 () ;
if ( error )
return error ;
#ifdef F_58
if ( V_109 )
F_62 () ;
#endif
if ( ! V_150 ) {
error = F_90 () ;
if ( error && error != - V_91 && error != - V_17 )
goto V_151;
}
if ( ! V_152 ) {
error = F_92 () ;
if ( error )
goto V_151;
}
F_83 () ;
return 0 ;
V_151:
F_82 () ;
F_89 () ;
F_60 ( false ) ;
V_90 = NULL ;
return error ;
}
static int F_96 ( struct V_114 * V_111 )
{
F_87 () ;
F_89 () ;
F_60 ( false ) ;
V_90 = NULL ;
return 0 ;
}
static int T_2 F_97 ( void )
{
struct V_114 * V_153 ;
int V_154 ;
F_98 () ;
V_154 = F_99 () ;
if ( V_154 )
return V_154 ;
V_154 = F_55 () ;
if ( V_154 )
goto V_155;
V_153 = F_100 ( & V_156 , F_95 , NULL , 0 , NULL , 0 ) ;
if ( F_101 ( V_153 ) ) {
V_154 = F_102 ( V_153 ) ;
goto V_155;
}
F_103 ( & V_157 , & V_158 ) ;
V_159 = F_61 ;
return 0 ;
V_155:
F_104 () ;
return V_154 ;
}
static void T_3 F_105 ( void )
{
F_106 ( V_90 ) ;
F_107 ( & V_156 ) ;
F_104 () ;
F_108 ( & V_157 , & V_158 ) ;
V_159 = NULL ;
}
