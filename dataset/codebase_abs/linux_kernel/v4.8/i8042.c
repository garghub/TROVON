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
F_34 ( V_11 -> V_65 , V_2 , L_18 ,
V_50 , V_47 ,
V_49 & V_59 ? L_19 : L_20 ,
V_49 & V_58 ? L_21 : L_20 ) ;
V_51 = F_31 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_7 , V_5 ) ;
if ( F_35 ( V_11 -> V_43 && ! V_51 ) )
F_36 ( V_4 , V_2 , V_49 ) ;
V_10:
return F_37 ( V_6 ) ;
}
static int F_38 ( void )
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
static int F_39 ( void )
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
static int F_40 ( void )
{
unsigned char V_22 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_66 ; V_13 ++ ) {
F_20 ( & V_22 , V_67 + V_13 ) ;
F_20 ( & V_22 , V_68 ) ;
}
return F_39 () ;
}
static int F_41 ( bool V_69 , unsigned char * V_70 )
{
unsigned char V_22 , V_71 ;
F_14 () ;
V_22 = V_71 = 0xf0 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 != V_71 )
return - 1 ;
V_22 = V_71 = V_69 ? 0x56 : 0xf6 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 != V_71 )
return - 1 ;
V_22 = V_71 = V_69 ? 0xa4 : 0xa5 ;
if ( F_20 ( & V_22 , V_25 ) || V_22 == V_71 )
return - 1 ;
if ( V_22 == 0xac )
return - 1 ;
if ( V_70 )
* V_70 = V_22 ;
return 0 ;
}
static int T_2 F_42 ( void )
{
unsigned char V_70 ;
if ( F_41 ( true , & V_70 ) )
return - 1 ;
F_43 ( L_24 ,
( V_70 >> 4 ) & 0xf , V_70 & 0xf ) ;
V_41 |= V_38 ;
V_41 &= ~ V_37 ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_25 ) ;
return - V_21 ;
}
V_52 = true ;
return 0 ;
}
static T_1 T_2 F_44 ( int V_47 , void * V_48 )
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
if ( V_72 &&
V_2 == 0xa5 && ( V_3 & V_20 ) )
F_45 ( & V_73 ) ;
V_6 = 1 ;
}
F_8 ( & V_7 , V_5 ) ;
return F_37 ( V_6 ) ;
}
static int T_2 F_46 ( bool V_74 )
{
unsigned char V_22 ;
int V_13 ;
if ( F_20 ( & V_22 ,
V_74 ? V_68 : V_75 ) )
return - 1 ;
for ( V_13 = 0 ; V_13 < 100 ; V_13 ++ ) {
F_12 ( 50 ) ;
if ( F_20 ( & V_22 , V_76 ) )
return - 1 ;
if ( ! ( V_22 & V_38 ) == V_74 )
return 0 ;
}
return - 1 ;
}
static int T_2 F_47 ( void )
{
int V_18 = - 1 ;
bool V_77 = false ;
bool V_78 = false ;
unsigned long V_5 ;
unsigned char V_22 ;
F_14 () ;
V_22 = 0x5a ;
V_18 = F_20 ( & V_22 , V_25 ) ;
if ( V_18 || V_22 != 0x5a ) {
if ( F_20 ( & V_22 , V_79 ) ||
( V_22 && V_22 != 0xfa && V_22 != 0xff ) )
return - 1 ;
if ( ! V_18 )
V_78 = true ;
}
if ( F_46 ( false ) ) {
F_24 ( L_27 ) ;
F_24 ( L_28 ) ;
}
if ( F_46 ( true ) )
return - 1 ;
if ( V_80 ) {
F_24 ( L_29 ) ;
F_21 ( NULL , ( unsigned char ) 0xff ) ;
}
if ( V_24 || V_81 || V_78 ) {
V_18 = 0 ;
goto V_10;
}
if ( F_48 ( V_44 , F_44 , V_82 ,
L_30 , V_83 ) )
goto V_10;
V_77 = true ;
if ( F_39 () )
goto V_10;
F_7 ( & V_7 , V_5 ) ;
F_49 ( & V_73 ) ;
V_72 = true ;
V_22 = 0xa5 ;
V_18 = F_17 ( & V_22 , V_25 & 0xf0ff ) ;
F_8 ( & V_7 , V_5 ) ;
if ( V_18 )
goto V_10;
if ( F_50 ( & V_73 ,
F_51 ( 250 ) ) == 0 ) {
F_16 ( L_31 ) ;
F_14 () ;
V_18 = - 1 ;
}
V_10:
V_41 |= V_38 ;
V_41 &= ~ V_37 ;
if ( F_20 ( & V_41 , V_42 ) )
V_18 = - 1 ;
if ( V_77 )
F_52 ( V_44 , V_83 ) ;
return V_18 ;
}
static int F_53 ( void )
{
if ( F_14 () ) {
F_43 ( L_32 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_54 ( void )
{
unsigned char V_22 ;
int V_13 = 0 ;
do {
if ( F_20 ( & V_22 , V_85 ) ) {
F_25 ( L_33 ) ;
return - V_84 ;
}
if ( V_22 == V_86 )
return 0 ;
F_16 ( L_34 ,
V_22 , V_86 ) ;
F_55 ( 50 ) ;
} while ( V_13 ++ < 5 );
#ifdef F_56
F_43 ( L_35 ) ;
return 0 ;
#else
F_25 ( L_36 ) ;
return - V_21 ;
#endif
}
static int F_57 ( void )
{
unsigned long V_5 ;
int V_87 = 0 ;
unsigned char V_88 [ 2 ] ;
do {
if ( V_87 >= 10 ) {
F_25 ( L_37 ) ;
return - V_21 ;
}
if ( V_87 != 0 )
F_12 ( 50 ) ;
if ( F_20 ( & V_88 [ V_87 ++ % 2 ] , V_76 ) ) {
F_25 ( L_38 ) ;
return - V_21 ;
}
} while ( V_87 < 2 || V_88 [ 0 ] != V_88 [ 1 ] );
V_89 = V_41 = V_88 [ 0 ] ;
V_41 |= V_40 ;
V_41 &= ~ V_39 ;
F_7 ( & V_7 , V_5 ) ;
if ( ~ F_11 () & V_90 ) {
if ( V_91 )
V_41 |= V_92 ;
else
F_24 ( L_39 ) ;
}
F_8 ( & V_7 , V_5 ) ;
if ( ~ V_41 & V_93 )
V_94 = true ;
if ( V_94 )
V_41 &= ~ V_93 ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_40 ) ;
return - V_21 ;
}
F_14 () ;
return 0 ;
}
static void F_58 ( bool V_95 )
{
F_14 () ;
V_41 |= V_40 | V_38 ;
V_41 &= ~ ( V_39 | V_37 ) ;
if ( F_20 ( & V_41 , V_42 ) )
F_24 ( L_41 ) ;
if ( V_52 )
F_41 ( false , NULL ) ;
if ( V_96 || V_95 )
F_54 () ;
if ( F_20 ( & V_89 , V_42 ) )
F_24 ( L_42 ) ;
}
static long F_59 ( int V_97 )
{
long V_98 = 0 ;
char V_99 ;
V_99 = ( V_97 ) ? 0x01 | 0x04 : 0 ;
while ( F_11 () & V_16 )
V_100 ;
F_16 ( L_43 , 0xed ) ;
V_46 = 2 ;
F_19 ( 0xed ) ;
V_100 ;
while ( F_11 () & V_16 )
V_100 ;
V_100 ;
F_16 ( L_43 , V_99 ) ;
F_19 ( V_99 ) ;
V_100 ;
return V_98 ;
}
static void F_60 ( void )
{
unsigned char V_22 = 0x90 ;
int error ;
error = F_20 ( & V_22 , 0x1059 ) ;
if ( error )
F_24 ( L_44 , error ) ;
}
static int F_61 ( bool V_95 )
{
int error ;
error = F_53 () ;
if ( error )
return error ;
if ( V_96 || V_95 ) {
error = F_54 () ;
if ( error )
return error ;
}
V_41 = V_89 ;
if ( V_94 )
V_41 &= ~ V_93 ;
V_41 |= V_38 | V_40 ;
V_41 &= ~ ( V_37 | V_39 ) ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_24 ( L_45 ) ;
F_55 ( 50 ) ;
if ( F_20 ( & V_41 , V_42 ) ) {
F_25 ( L_46 ) ;
return - V_21 ;
}
}
#ifdef F_56
if ( V_101 )
F_60 () ;
#endif
if ( V_52 ) {
if ( F_41 ( true , NULL ) || F_40 () )
F_24 ( L_47 ) ;
} else if ( V_35 [ V_36 ] . V_4 )
F_39 () ;
if ( V_35 [ V_64 ] . V_4 )
F_38 () ;
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_62 ( struct V_102 * V_103 )
{
int V_13 ;
if ( F_63 () )
F_58 ( true ) ;
for ( V_13 = 0 ; V_13 < V_104 ; V_13 ++ ) {
struct V_4 * V_4 = V_35 [ V_13 ] . V_4 ;
if ( V_4 && F_64 ( & V_4 -> V_103 ) )
F_65 ( V_35 [ V_13 ] . V_47 ) ;
}
return 0 ;
}
static int F_66 ( struct V_102 * V_103 )
{
if ( ! F_67 () )
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_68 ( struct V_102 * V_103 )
{
bool V_95 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_104 ; V_13 ++ ) {
struct V_4 * V_4 = V_35 [ V_13 ] . V_4 ;
if ( V_4 && F_64 ( & V_4 -> V_103 ) )
F_69 ( V_35 [ V_13 ] . V_47 ) ;
}
if ( ! F_63 () )
return 0 ;
V_95 = F_67 () ;
return F_61 ( V_95 ) ;
}
static int F_70 ( struct V_102 * V_103 )
{
F_26 ( 0 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_102 * V_103 )
{
F_58 ( false ) ;
return 0 ;
}
static int F_72 ( struct V_102 * V_103 )
{
return F_61 ( false ) ;
}
static void F_73 ( struct V_105 * V_103 )
{
F_58 ( false ) ;
}
static int T_2 F_74 ( void )
{
struct V_4 * V_4 ;
struct V_27 * V_11 = & V_35 [ V_64 ] ;
V_4 = F_75 ( sizeof( struct V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_107 ;
V_4 -> V_108 . type = V_94 ? V_109 : V_110 ;
V_4 -> V_111 = V_112 ? NULL : F_21 ;
V_4 -> V_113 = F_27 ;
V_4 -> V_114 = F_29 ;
V_4 -> V_115 = F_23 ;
V_4 -> V_116 = & V_1 ;
V_4 -> V_28 = V_11 ;
V_4 -> V_103 . V_117 = & V_83 -> V_103 ;
F_76 ( V_4 -> V_118 , L_48 , sizeof( V_4 -> V_118 ) ) ;
F_76 ( V_4 -> V_119 , V_120 , sizeof( V_4 -> V_119 ) ) ;
F_76 ( V_4 -> V_121 , V_122 ,
sizeof( V_4 -> V_121 ) ) ;
V_11 -> V_4 = V_4 ;
V_11 -> V_47 = V_45 ;
return 0 ;
}
static int T_2 F_77 ( int V_123 )
{
struct V_4 * V_4 ;
int V_50 = V_123 < 0 ? V_36 : V_60 + V_123 ;
struct V_27 * V_11 = & V_35 [ V_50 ] ;
V_4 = F_75 ( sizeof( struct V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_107 ;
V_4 -> V_108 . type = V_109 ;
V_4 -> V_111 = F_22 ;
V_4 -> V_113 = F_27 ;
V_4 -> V_114 = F_29 ;
V_4 -> V_116 = & V_1 ;
V_4 -> V_28 = V_11 ;
V_4 -> V_103 . V_117 = & V_83 -> V_103 ;
if ( V_123 < 0 ) {
F_76 ( V_4 -> V_118 , L_49 , sizeof( V_4 -> V_118 ) ) ;
F_76 ( V_4 -> V_119 , V_124 , sizeof( V_4 -> V_119 ) ) ;
F_76 ( V_4 -> V_121 , V_125 ,
sizeof( V_4 -> V_121 ) ) ;
V_4 -> V_115 = F_23 ;
} else {
snprintf ( V_4 -> V_118 , sizeof( V_4 -> V_118 ) , L_50 , V_123 ) ;
snprintf ( V_4 -> V_119 , sizeof( V_4 -> V_119 ) , V_126 , V_123 + 1 ) ;
F_76 ( V_4 -> V_121 , V_125 ,
sizeof( V_4 -> V_121 ) ) ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_29 = V_123 ;
V_11 -> V_47 = V_44 ;
return 0 ;
}
static void T_2 F_78 ( void )
{
F_79 ( V_35 [ V_64 ] . V_4 ) ;
V_35 [ V_64 ] . V_4 = NULL ;
}
static void T_2 F_80 ( void )
{
int V_13 ;
for ( V_13 = V_36 ; V_13 < V_104 ; V_13 ++ ) {
F_79 ( V_35 [ V_13 ] . V_4 ) ;
V_35 [ V_13 ] . V_4 = NULL ;
}
}
static void T_2 F_81 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_104 ; V_13 ++ ) {
struct V_4 * V_4 = V_35 [ V_13 ] . V_4 ;
if ( V_4 ) {
F_82 ( V_127 L_51 ,
V_4 -> V_118 ,
( unsigned long ) V_128 ,
( unsigned long ) V_129 ,
V_35 [ V_13 ] . V_47 ) ;
F_83 ( V_4 ) ;
F_84 ( & V_4 -> V_103 , true ) ;
}
}
}
static void F_85 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_104 ; V_13 ++ ) {
if ( V_35 [ V_13 ] . V_4 ) {
F_86 ( V_35 [ V_13 ] . V_4 ) ;
V_35 [ V_13 ] . V_4 = NULL ;
}
}
}
static void F_87 ( void )
{
if ( V_130 )
F_52 ( V_44 , V_83 ) ;
if ( V_131 )
F_52 ( V_45 , V_83 ) ;
V_130 = V_131 = false ;
}
static int T_2 F_88 ( void )
{
int (* F_89)( void );
int error ;
int V_13 ;
if ( F_47 () )
return - V_84 ;
if ( V_132 || F_42 () ) {
error = F_77 ( - 1 ) ;
if ( error )
goto V_133;
F_89 = F_39 ;
} else {
for ( V_13 = 0 ; V_13 < V_66 ; V_13 ++ ) {
error = F_77 ( V_13 ) ;
if ( error )
goto V_133;
}
F_89 = F_40 ;
}
error = F_48 ( V_44 , F_26 , V_82 ,
L_30 , V_83 ) ;
if ( error )
goto V_133;
if ( F_89 () )
goto V_134;
V_130 = true ;
return 0 ;
V_134:
F_52 ( V_44 , V_83 ) ;
V_133:
F_80 () ;
return error ;
}
static int T_2 F_90 ( void )
{
int error ;
error = F_74 () ;
if ( error )
return error ;
error = F_48 ( V_45 , F_26 , V_82 ,
L_30 , V_83 ) ;
if ( error )
goto V_135;
error = F_38 () ;
if ( error )
goto V_134;
V_131 = true ;
return 0 ;
V_134:
F_52 ( V_45 , V_83 ) ;
V_135:
F_78 () ;
return error ;
}
static int F_91 ( struct V_136 * V_137 ,
unsigned long V_138 , void * V_2 )
{
struct V_102 * V_103 = V_2 ;
struct V_4 * V_4 = F_92 ( V_103 ) ;
struct V_27 * V_11 = V_4 -> V_28 ;
if ( V_4 != V_35 [ V_64 ] . V_4 )
return 0 ;
switch ( V_138 ) {
case V_139 :
V_11 -> V_65 = true ;
break;
case V_140 :
V_11 -> V_65 = false ;
break;
}
return 0 ;
}
static int T_2 F_93 ( struct V_105 * V_103 )
{
int error ;
V_83 = V_103 ;
if ( V_96 ) {
error = F_54 () ;
if ( error )
return error ;
}
error = F_57 () ;
if ( error )
return error ;
#ifdef F_56
if ( V_101 )
F_60 () ;
#endif
if ( ! V_141 ) {
error = F_88 () ;
if ( error && error != - V_84 && error != - V_9 )
goto V_142;
}
if ( ! V_143 ) {
error = F_90 () ;
if ( error )
goto V_142;
}
F_81 () ;
return 0 ;
V_142:
F_80 () ;
F_87 () ;
F_58 ( false ) ;
V_83 = NULL ;
return error ;
}
static int F_94 ( struct V_105 * V_103 )
{
F_85 () ;
F_87 () ;
F_58 ( false ) ;
V_83 = NULL ;
return 0 ;
}
static int T_2 F_95 ( void )
{
struct V_105 * V_144 ;
int V_145 ;
F_96 () ;
V_145 = F_97 () ;
if ( V_145 )
return V_145 ;
V_145 = F_53 () ;
if ( V_145 )
goto V_146;
V_144 = F_98 ( & V_147 , F_93 , NULL , 0 , NULL , 0 ) ;
if ( F_99 ( V_144 ) ) {
V_145 = F_100 ( V_144 ) ;
goto V_146;
}
F_101 ( & V_148 , & V_149 ) ;
V_150 = F_59 ;
return 0 ;
V_146:
F_102 () ;
return V_145 ;
}
static void T_3 F_103 ( void )
{
F_104 ( V_83 ) ;
F_105 ( & V_147 ) ;
F_102 () ;
F_106 ( & V_148 , & V_149 ) ;
V_150 = NULL ;
}
