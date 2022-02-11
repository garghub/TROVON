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
int V_13 = 0 ;
F_7 ( & V_7 , V_5 ) ;
while ( ( ( V_3 = F_11 () ) & V_14 ) && ( V_13 < V_17 ) ) {
F_12 ( 50 ) ;
V_2 = F_15 () ;
V_13 ++ ;
F_16 ( L_1 ,
V_2 , V_3 & V_18 ? L_2 : L_3 ) ;
}
F_8 ( & V_7 , V_5 ) ;
return V_13 ;
}
static int F_17 ( unsigned char * V_19 , int V_20 )
{
int V_13 , error ;
if ( V_21 && V_20 == V_22 )
return - 1 ;
error = F_13 () ;
if ( error )
return error ;
F_16 ( L_4 , V_20 & 0xff ) ;
F_18 ( V_20 & 0xff ) ;
for ( V_13 = 0 ; V_13 < ( ( V_20 >> 12 ) & 0xf ) ; V_13 ++ ) {
error = F_13 () ;
if ( error )
return error ;
F_16 ( L_5 , V_19 [ V_13 ] ) ;
F_19 ( V_19 [ V_13 ] ) ;
}
for ( V_13 = 0 ; V_13 < ( ( V_20 >> 8 ) & 0xf ) ; V_13 ++ ) {
error = F_10 () ;
if ( error ) {
F_16 ( L_6 ) ;
return error ;
}
if ( V_20 == V_22 &&
! ( F_11 () & V_18 ) ) {
F_16 ( L_7 ) ;
return - 1 ;
}
V_19 [ V_13 ] = F_15 () ;
F_16 ( L_8 , V_19 [ V_13 ] ) ;
}
return 0 ;
}
int F_20 ( unsigned char * V_19 , int V_20 )
{
unsigned long V_5 ;
int V_23 ;
F_7 ( & V_7 , V_5 ) ;
V_23 = F_17 ( V_19 , V_20 ) ;
F_8 ( & V_7 , V_5 ) ;
return V_23 ;
}
static int F_21 ( struct V_4 * V_11 , unsigned char V_24 )
{
unsigned long V_5 ;
int V_23 = 0 ;
F_7 ( & V_7 , V_5 ) ;
if ( ! ( V_23 = F_13 () ) ) {
F_16 ( L_9 , V_24 ) ;
F_19 ( V_24 ) ;
}
F_8 ( & V_7 , V_5 ) ;
return V_23 ;
}
static int F_22 ( struct V_4 * V_4 , unsigned char V_24 )
{
struct V_25 * V_11 = V_4 -> V_26 ;
return F_20 ( & V_24 , V_11 -> V_27 == - 1 ?
V_28 :
V_29 + V_11 -> V_27 ) ;
}
static void F_23 ( struct V_4 * V_4 )
{
int V_30 ;
int V_31 ;
const char * V_32 ;
if ( V_4 == V_33 [ V_34 ] . V_4 ) {
V_30 = V_35 ;
V_31 = V_36 ;
V_32 = L_10 ;
} else {
V_30 = V_37 ;
V_31 = V_38 ;
V_32 = L_11 ;
}
V_39 &= ~ V_30 ;
if ( F_20 ( & V_39 , V_40 ) )
F_24 ( L_12 , V_32 ) ;
F_12 ( 50 ) ;
V_39 &= ~ V_31 ;
V_39 |= V_30 ;
if ( F_20 ( & V_39 , V_40 ) )
F_25 ( L_13 , V_32 ) ;
F_26 ( 0 , NULL ) ;
}
static int F_27 ( struct V_4 * V_4 )
{
struct V_25 * V_11 = V_4 -> V_26 ;
V_11 -> V_41 = true ;
F_28 () ;
return 0 ;
}
static void F_29 ( struct V_4 * V_4 )
{
struct V_25 * V_11 = V_4 -> V_26 ;
V_11 -> V_41 = false ;
F_30 ( V_42 ) ;
F_30 ( V_43 ) ;
V_11 -> V_4 = NULL ;
}
static bool F_31 ( unsigned char V_2 , unsigned char V_3 ,
struct V_4 * V_4 )
{
if ( F_32 ( V_44 ) ) {
if ( ( ~ V_3 & V_18 ) &&
( V_2 == 0xfa || V_2 == 0xfe ) ) {
V_44 -- ;
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
static T_1 F_26 ( int V_45 , void * V_46 )
{
struct V_25 * V_11 ;
struct V_4 * V_4 ;
unsigned long V_5 ;
unsigned char V_3 , V_2 ;
unsigned int V_47 ;
unsigned int V_48 ;
bool V_49 ;
int V_6 = 1 ;
F_7 ( & V_7 , V_5 ) ;
V_3 = F_11 () ;
if ( F_32 ( ~ V_3 & V_14 ) ) {
F_8 ( & V_7 , V_5 ) ;
if ( V_45 )
F_16 ( L_16 , V_45 ) ;
V_6 = 0 ;
goto V_10;
}
V_2 = F_15 () ;
if ( V_50 && ( V_3 & V_18 ) ) {
static unsigned long V_51 ;
static unsigned char V_52 ;
V_47 = 0 ;
if ( V_3 & V_53 ) {
F_16 ( L_17 ,
V_3 , V_2 ) ;
switch ( V_2 ) {
default:
if ( F_33 ( V_54 , V_51 + V_55 / 10 ) ) {
V_3 = V_52 ;
break;
}
case 0xfc :
case 0xfd :
case 0xfe : V_47 = V_56 ; V_2 = 0xfe ; break;
case 0xff : V_47 = V_57 ; V_2 = 0xfe ; break;
}
}
V_48 = V_58 + ( ( V_3 >> 6 ) & 3 ) ;
V_52 = V_3 ;
V_51 = V_54 ;
} else {
V_47 = ( ( V_3 & V_59 ) ? V_57 : 0 ) |
( ( V_3 & V_60 && ! V_61 ) ? V_56 : 0 ) ;
V_48 = ( V_3 & V_18 ) ?
V_34 : V_62 ;
}
V_11 = & V_33 [ V_48 ] ;
V_4 = V_11 -> V_41 ? V_11 -> V_4 : NULL ;
F_16 ( L_18 ,
V_2 , V_48 , V_45 ,
V_47 & V_57 ? L_19 : L_20 ,
V_47 & V_56 ? L_21 : L_20 ) ;
V_49 = F_31 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_7 , V_5 ) ;
if ( F_34 ( V_11 -> V_41 && ! V_49 ) )
F_35 ( V_4 , V_2 , V_47 ) ;
V_10:
return F_36 ( V_6 ) ;
}
static int F_37 ( void )
{
V_39 &= ~ V_38 ;
V_39 |= V_37 ;
if ( F_20 ( & V_39 , V_40 ) ) {
V_39 &= ~ V_37 ;
V_39 |= V_38 ;
F_25 ( L_22 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_38 ( void )
{
V_39 &= ~ V_36 ;
V_39 |= V_35 ;
if ( F_20 ( & V_39 , V_40 ) ) {
V_39 &= ~ V_35 ;
V_39 |= V_36 ;
F_25 ( L_23 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_39 ( void )
{
unsigned char V_19 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_64 ; V_13 ++ ) {
F_20 ( & V_19 , V_65 + V_13 ) ;
F_20 ( & V_19 , V_66 ) ;
}
return F_38 () ;
}
static int F_40 ( bool V_67 , unsigned char * V_68 )
{
unsigned char V_19 , V_69 ;
F_14 () ;
V_19 = V_69 = 0xf0 ;
if ( F_20 ( & V_19 , V_22 ) || V_19 != V_69 )
return - 1 ;
V_19 = V_69 = V_67 ? 0x56 : 0xf6 ;
if ( F_20 ( & V_19 , V_22 ) || V_19 != V_69 )
return - 1 ;
V_19 = V_69 = V_67 ? 0xa4 : 0xa5 ;
if ( F_20 ( & V_19 , V_22 ) || V_19 == V_69 )
return - 1 ;
if ( V_19 == 0xac )
return - 1 ;
if ( V_68 )
* V_68 = V_19 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
unsigned char V_68 ;
if ( F_40 ( true , & V_68 ) )
return - 1 ;
F_42 ( L_24 ,
( V_68 >> 4 ) & 0xf , V_68 & 0xf ) ;
V_39 |= V_36 ;
V_39 &= ~ V_35 ;
if ( F_20 ( & V_39 , V_40 ) ) {
F_25 ( L_25 ) ;
return - V_63 ;
}
V_50 = true ;
return 0 ;
}
static T_1 T_2 F_43 ( int V_45 , void * V_46 )
{
unsigned long V_5 ;
unsigned char V_3 , V_2 ;
int V_6 = 0 ;
F_7 ( & V_7 , V_5 ) ;
V_3 = F_11 () ;
if ( V_3 & V_14 ) {
V_2 = F_15 () ;
F_16 ( L_26 ,
V_2 , V_3 & V_18 ? L_2 : L_3 ) ;
if ( V_70 &&
V_2 == 0xa5 && ( V_3 & V_18 ) )
F_44 ( & V_71 ) ;
V_6 = 1 ;
}
F_8 ( & V_7 , V_5 ) ;
return F_36 ( V_6 ) ;
}
static int T_2 F_45 ( bool V_72 )
{
unsigned char V_19 ;
int V_13 ;
if ( F_20 ( & V_19 ,
V_72 ? V_66 : V_73 ) )
return - 1 ;
for ( V_13 = 0 ; V_13 < 100 ; V_13 ++ ) {
F_12 ( 50 ) ;
if ( F_20 ( & V_19 , V_74 ) )
return - 1 ;
if ( ! ( V_19 & V_36 ) == V_72 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_46 ( void )
{
int V_23 = - 1 ;
bool V_75 = false ;
bool V_76 = false ;
unsigned long V_5 ;
unsigned char V_19 ;
F_14 () ;
V_19 = 0x5a ;
V_23 = F_20 ( & V_19 , V_22 ) ;
if ( V_23 || V_19 != 0x5a ) {
if ( F_20 ( & V_19 , V_77 ) ||
( V_19 && V_19 != 0xfa && V_19 != 0xff ) )
return - 1 ;
if ( ! V_23 )
V_76 = true ;
}
if ( F_45 ( false ) ) {
F_24 ( L_27 ) ;
F_24 ( L_28 ) ;
}
if ( F_45 ( true ) )
return - 1 ;
if ( V_21 || V_78 || V_76 ) {
V_23 = 0 ;
goto V_10;
}
if ( F_47 ( V_42 , F_43 , V_79 ,
L_29 , V_80 ) )
goto V_10;
V_75 = true ;
if ( F_38 () )
goto V_10;
F_7 ( & V_7 , V_5 ) ;
F_48 ( & V_71 ) ;
V_70 = true ;
V_19 = 0xa5 ;
V_23 = F_17 ( & V_19 , V_22 & 0xf0ff ) ;
F_8 ( & V_7 , V_5 ) ;
if ( V_23 )
goto V_10;
if ( F_49 ( & V_71 ,
F_50 ( 250 ) ) == 0 ) {
F_16 ( L_30 ) ;
F_14 () ;
V_23 = - 1 ;
}
V_10:
V_39 |= V_36 ;
V_39 &= ~ V_35 ;
if ( F_20 ( & V_39 , V_40 ) )
V_23 = - 1 ;
if ( V_75 )
F_51 ( V_42 , V_80 ) ;
return V_23 ;
}
static int F_52 ( void )
{
if ( F_14 () == V_17 ) {
F_25 ( L_31 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_53 ( void )
{
unsigned char V_19 ;
int V_13 = 0 ;
do {
if ( F_20 ( & V_19 , V_82 ) ) {
F_25 ( L_32 ) ;
return - V_81 ;
}
if ( V_19 == V_83 )
return 0 ;
F_16 ( L_33 ,
V_19 , V_83 ) ;
F_54 ( 50 ) ;
} while ( V_13 ++ < 5 );
#ifdef F_55
F_42 ( L_34 ) ;
return 0 ;
#else
F_25 ( L_35 ) ;
return - V_63 ;
#endif
}
static int F_56 ( void )
{
unsigned long V_5 ;
int V_84 = 0 ;
unsigned char V_85 [ 2 ] ;
do {
if ( V_84 >= 10 ) {
F_25 ( L_36 ) ;
return - V_63 ;
}
if ( V_84 != 0 )
F_12 ( 50 ) ;
if ( F_20 ( & V_85 [ V_84 ++ % 2 ] , V_74 ) ) {
F_25 ( L_37 ) ;
return - V_63 ;
}
} while ( V_84 < 2 || V_85 [ 0 ] != V_85 [ 1 ] );
V_86 = V_39 = V_85 [ 0 ] ;
V_39 |= V_38 ;
V_39 &= ~ V_37 ;
F_7 ( & V_7 , V_5 ) ;
if ( ~ F_11 () & V_87 ) {
if ( V_88 )
V_39 |= V_89 ;
else
F_24 ( L_38 ) ;
}
F_8 ( & V_7 , V_5 ) ;
if ( ~ V_39 & V_90 )
V_91 = true ;
if ( V_91 )
V_39 &= ~ V_90 ;
if ( F_20 ( & V_39 , V_40 ) ) {
F_25 ( L_39 ) ;
return - V_63 ;
}
F_14 () ;
return 0 ;
}
static void F_57 ( void )
{
F_14 () ;
V_39 |= V_38 | V_36 ;
V_39 &= ~ ( V_37 | V_35 ) ;
if ( F_20 ( & V_39 , V_40 ) )
F_24 ( L_40 ) ;
if ( V_50 )
F_40 ( false , NULL ) ;
if ( V_92 )
F_53 () ;
if ( F_20 ( & V_86 , V_40 ) )
F_24 ( L_41 ) ;
}
static long F_58 ( int V_93 )
{
long V_94 = 0 ;
char V_95 ;
V_95 = ( V_93 ) ? 0x01 | 0x04 : 0 ;
while ( F_11 () & V_16 )
V_96 ;
F_16 ( L_42 , 0xed ) ;
V_44 = 2 ;
F_19 ( 0xed ) ;
V_96 ;
while ( F_11 () & V_16 )
V_96 ;
V_96 ;
F_16 ( L_42 , V_95 ) ;
F_19 ( V_95 ) ;
V_96 ;
return V_94 ;
}
static void F_59 ( void )
{
unsigned char V_19 = 0x90 ;
int error ;
error = F_20 ( & V_19 , 0x1059 ) ;
if ( error )
F_24 ( L_43 , error ) ;
}
static int F_60 ( bool V_97 )
{
int error ;
error = F_52 () ;
if ( error )
return error ;
if ( V_92 || V_97 ) {
error = F_53 () ;
if ( error )
return error ;
}
V_39 = V_86 ;
if ( V_91 )
V_39 &= ~ V_90 ;
V_39 |= V_36 | V_38 ;
V_39 &= ~ ( V_35 | V_37 ) ;
if ( F_20 ( & V_39 , V_40 ) ) {
F_24 ( L_44 ) ;
F_54 ( 50 ) ;
if ( F_20 ( & V_39 , V_40 ) ) {
F_25 ( L_45 ) ;
return - V_63 ;
}
}
#ifdef F_55
if ( V_98 )
F_59 () ;
#endif
if ( V_50 ) {
if ( F_40 ( true , NULL ) || F_39 () )
F_24 ( L_46 ) ;
} else if ( V_33 [ V_34 ] . V_4 )
F_38 () ;
if ( V_33 [ V_62 ] . V_4 )
F_37 () ;
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_61 ( struct V_99 * V_100 )
{
F_57 () ;
return 0 ;
}
static int F_62 ( struct V_99 * V_100 )
{
return F_60 ( true ) ;
}
static int F_63 ( struct V_99 * V_100 )
{
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_64 ( struct V_99 * V_100 )
{
return F_60 ( false ) ;
}
static void F_65 ( struct V_101 * V_100 )
{
F_57 () ;
}
static int T_2 F_66 ( void )
{
struct V_4 * V_4 ;
struct V_25 * V_11 = & V_33 [ V_62 ] ;
V_4 = F_67 ( sizeof( struct V_4 ) , V_102 ) ;
if ( ! V_4 )
return - V_103 ;
V_4 -> V_104 . type = V_91 ? V_105 : V_106 ;
V_4 -> V_107 = V_108 ? NULL : F_21 ;
V_4 -> V_109 = F_27 ;
V_4 -> V_110 = F_29 ;
V_4 -> V_111 = F_23 ;
V_4 -> V_26 = V_11 ;
V_4 -> V_100 . V_112 = & V_80 -> V_100 ;
F_68 ( V_4 -> V_113 , L_47 , sizeof( V_4 -> V_113 ) ) ;
F_68 ( V_4 -> V_114 , V_115 , sizeof( V_4 -> V_114 ) ) ;
V_11 -> V_4 = V_4 ;
V_11 -> V_45 = V_43 ;
return 0 ;
}
static int T_2 F_69 ( int V_116 )
{
struct V_4 * V_4 ;
int V_48 = V_116 < 0 ? V_34 : V_58 + V_116 ;
struct V_25 * V_11 = & V_33 [ V_48 ] ;
V_4 = F_67 ( sizeof( struct V_4 ) , V_102 ) ;
if ( ! V_4 )
return - V_103 ;
V_4 -> V_104 . type = V_105 ;
V_4 -> V_107 = F_22 ;
V_4 -> V_109 = F_27 ;
V_4 -> V_110 = F_29 ;
V_4 -> V_26 = V_11 ;
V_4 -> V_100 . V_112 = & V_80 -> V_100 ;
if ( V_116 < 0 ) {
F_68 ( V_4 -> V_113 , L_48 , sizeof( V_4 -> V_113 ) ) ;
F_68 ( V_4 -> V_114 , V_117 , sizeof( V_4 -> V_114 ) ) ;
V_4 -> V_111 = F_23 ;
} else {
snprintf ( V_4 -> V_113 , sizeof( V_4 -> V_113 ) , L_49 , V_116 ) ;
snprintf ( V_4 -> V_114 , sizeof( V_4 -> V_114 ) , V_118 , V_116 + 1 ) ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_27 = V_116 ;
V_11 -> V_45 = V_42 ;
return 0 ;
}
static void T_2 F_70 ( void )
{
F_71 ( V_33 [ V_62 ] . V_4 ) ;
V_33 [ V_62 ] . V_4 = NULL ;
}
static void T_2 F_72 ( void )
{
int V_13 ;
for ( V_13 = V_34 ; V_13 < V_119 ; V_13 ++ ) {
F_71 ( V_33 [ V_13 ] . V_4 ) ;
V_33 [ V_13 ] . V_4 = NULL ;
}
}
static void T_2 F_73 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
if ( V_33 [ V_13 ] . V_4 ) {
F_74 ( V_120 L_50 ,
V_33 [ V_13 ] . V_4 -> V_113 ,
( unsigned long ) V_121 ,
( unsigned long ) V_122 ,
V_33 [ V_13 ] . V_45 ) ;
F_75 ( V_33 [ V_13 ] . V_4 ) ;
}
}
}
static void T_3 F_76 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
if ( V_33 [ V_13 ] . V_4 ) {
F_77 ( V_33 [ V_13 ] . V_4 ) ;
V_33 [ V_13 ] . V_4 = NULL ;
}
}
}
bool F_78 ( const struct V_4 * V_11 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ )
if ( V_33 [ V_13 ] . V_4 == V_11 )
return true ;
return false ;
}
static void F_79 ( void )
{
if ( V_123 )
F_51 ( V_42 , V_80 ) ;
if ( V_124 )
F_51 ( V_43 , V_80 ) ;
V_123 = V_124 = false ;
}
static int T_2 F_80 ( void )
{
int (* F_81)( void );
int error ;
int V_13 ;
if ( F_46 () )
return - V_81 ;
if ( V_125 || F_41 () ) {
error = F_69 ( - 1 ) ;
if ( error )
goto V_126;
F_81 = F_38 ;
} else {
for ( V_13 = 0 ; V_13 < V_64 ; V_13 ++ ) {
error = F_69 ( V_13 ) ;
if ( error )
goto V_126;
}
F_81 = F_39 ;
}
error = F_47 ( V_42 , F_26 , V_79 ,
L_29 , V_80 ) ;
if ( error )
goto V_126;
if ( F_81 () )
goto V_127;
V_123 = true ;
return 0 ;
V_127:
F_51 ( V_42 , V_80 ) ;
V_126:
F_72 () ;
return error ;
}
static int T_2 F_82 ( void )
{
int error ;
error = F_66 () ;
if ( error )
return error ;
error = F_47 ( V_43 , F_26 , V_79 ,
L_29 , V_80 ) ;
if ( error )
goto V_128;
error = F_37 () ;
if ( error )
goto V_127;
V_124 = true ;
return 0 ;
V_127:
F_51 ( V_43 , V_80 ) ;
V_128:
F_70 () ;
return error ;
}
static int T_2 F_83 ( struct V_101 * V_100 )
{
int error ;
V_80 = V_100 ;
if ( V_92 ) {
error = F_53 () ;
if ( error )
return error ;
}
error = F_56 () ;
if ( error )
return error ;
#ifdef F_55
if ( V_98 )
F_59 () ;
#endif
if ( ! V_129 ) {
error = F_80 () ;
if ( error && error != - V_81 && error != - V_9 )
goto V_130;
}
if ( ! V_131 ) {
error = F_82 () ;
if ( error )
goto V_130;
}
F_73 () ;
return 0 ;
V_130:
F_72 () ;
F_79 () ;
F_57 () ;
V_80 = NULL ;
return error ;
}
static int T_3 F_84 ( struct V_101 * V_100 )
{
F_76 () ;
F_79 () ;
F_57 () ;
V_80 = NULL ;
return 0 ;
}
static int T_2 F_85 ( void )
{
struct V_101 * V_132 ;
int V_133 ;
F_86 () ;
V_133 = F_87 () ;
if ( V_133 )
return V_133 ;
V_133 = F_52 () ;
if ( V_133 )
goto V_134;
V_132 = F_88 ( & V_135 , F_83 , NULL , 0 , NULL , 0 ) ;
if ( F_89 ( V_132 ) ) {
V_133 = F_90 ( V_132 ) ;
goto V_134;
}
V_136 = F_58 ;
return 0 ;
V_134:
F_91 () ;
return V_133 ;
}
static void T_4 F_92 ( void )
{
F_93 ( V_80 ) ;
F_94 ( & V_135 ) ;
F_91 () ;
V_136 = NULL ;
}
