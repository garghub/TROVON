static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static void F_2 ( void )
{
F_3 ( & V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
}
static void F_4 ( void )
{
F_5 ( & V_5 ) ;
}
static void T_1 F_6 ( const struct V_8 * V_9 )
{
int V_10 = ( V_9 -> V_11 - 11 ) / sizeof( struct V_12 ) - 1 ;
struct V_12 * V_13 ;
struct V_14 * V_15 =
F_7 ( V_9 , struct V_14 , V_16 ) ;
if ( V_9 -> V_11 < 17 )
return;
V_17 = V_15 -> V_18 ;
V_19 = V_15 -> V_20 ;
V_13 = F_8 ( V_21 , ( V_22 + V_10 ) *
sizeof( struct V_12 ) ,
V_23 ) ;
if ( ! V_13 )
return;
V_21 = V_13 ;
memcpy ( V_21 + V_22 , V_15 -> V_10 ,
sizeof( struct V_12 ) * V_10 ) ;
V_22 += V_10 ;
}
static void T_1 F_9 ( const struct V_8 * V_9 , void * V_24 )
{
switch ( V_9 -> type ) {
case 0xd4 :
case 0xd5 :
case 0xd6 :
break;
case 0xda :
F_6 ( V_9 ) ;
break;
}
}
static int F_10 ( int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( V_21 [ V_26 ] . V_27 == V_25 )
return V_26 ;
}
return - 1 ;
}
static int F_11 ( int V_25 )
{
int V_28 ;
V_28 = F_10 ( V_25 ) ;
if ( V_28 == - 1 )
return - 1 ;
return V_21 [ V_28 ] . V_29 ;
}
static struct V_7 *
F_12 ( struct V_7 * V_6 , int V_30 ,
int V_31 )
{
struct V_32 V_33 ;
V_33 . V_34 = V_35 ;
V_33 . V_36 = V_17 ;
V_33 . V_37 = V_19 ;
V_33 . V_38 = F_13 ( V_6 ) ;
V_33 . V_39 = 0x42534931 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_31 = V_31 ;
F_14 ( & V_33 ) ;
return V_6 ;
}
static inline int F_15 ( int V_40 )
{
switch ( V_40 ) {
case 0 :
return 0 ;
case - 1 :
return - V_41 ;
case - 2 :
return - V_42 ;
default:
return - V_43 ;
}
}
static int F_16 ( void * V_44 , bool V_45 )
{
int V_46 = V_45 ? 1 : 0 ;
unsigned long V_47 = ( unsigned long ) V_44 ;
int V_48 = ( unsigned long ) V_44 - 1 ;
F_2 () ;
F_12 ( V_6 , 17 , 11 ) ;
if ( ( V_49 & F_17 ( V_48 ) ) &&
! ( V_6 -> V_50 [ 1 ] & F_17 ( 16 ) ) )
V_46 = 1 ;
V_6 -> V_51 [ 0 ] = ( 1 | ( V_47 << 8 ) | ( V_46 << 16 ) ) ;
F_12 ( V_6 , 17 , 11 ) ;
F_4 () ;
return 0 ;
}
static void F_18 ( struct V_52 * V_52 , int V_47 ,
int V_53 )
{
if ( V_53 & F_17 ( 0 ) ) {
int V_54 = F_19 ( V_52 ) ;
V_6 -> V_51 [ 0 ] = ( 1 | ( V_47 << 8 ) | ( V_54 << 16 ) ) ;
F_12 ( V_6 , 17 , 11 ) ;
} else {
F_20 ( V_52 , ! ! ( V_53 & F_17 ( V_47 + 16 ) ) ) ;
}
}
static void F_21 ( struct V_52 * V_52 , int V_47 ,
int V_53 )
{
if ( V_49 & ( F_17 ( V_47 - 1 ) ) )
F_22 ( V_52 , ! ( V_53 & F_17 ( 16 ) ) ) ;
}
static void F_23 ( struct V_52 * V_52 , void * V_44 )
{
int V_53 ;
F_2 () ;
F_12 ( V_6 , 17 , 11 ) ;
V_53 = V_6 -> V_50 [ 1 ] ;
F_21 ( V_52 , ( unsigned long ) V_44 , V_53 ) ;
F_4 () ;
}
static int F_24 ( struct V_55 * V_56 , void * V_44 )
{
int V_53 ;
F_2 () ;
F_12 ( V_6 , 17 , 11 ) ;
V_53 = V_6 -> V_50 [ 1 ] ;
F_4 () ;
F_25 ( V_56 , L_1 , V_53 ) ;
F_25 ( V_56 , L_2 ,
V_53 & F_17 ( 0 ) ) ;
F_25 ( V_56 , L_3 ,
( V_53 & F_17 ( 1 ) ) >> 1 ) ;
F_25 ( V_56 , L_4 ,
( V_53 & F_17 ( 2 ) ) >> 2 ) ;
F_25 ( V_56 , L_5 ,
( V_53 & F_17 ( 3 ) ) >> 3 ) ;
F_25 ( V_56 , L_6 ,
( V_53 & F_17 ( 4 ) ) >> 4 ) ;
F_25 ( V_56 , L_7 ,
( V_53 & F_17 ( 5 ) ) >> 5 ) ;
F_25 ( V_56 , L_8 ,
( V_53 & F_17 ( 8 ) ) >> 8 ) ;
F_25 ( V_56 , L_9 ,
( V_53 & F_17 ( 9 ) ) >> 9 ) ;
F_25 ( V_56 , L_10 ,
( V_53 & F_17 ( 10 ) ) >> 10 ) ;
F_25 ( V_56 , L_11 ,
( V_53 & F_17 ( 16 ) ) >> 16 ) ;
F_25 ( V_56 , L_12 ,
( V_53 & F_17 ( 17 ) ) >> 17 ) ;
F_25 ( V_56 , L_13 ,
( V_53 & F_17 ( 18 ) ) >> 18 ) ;
F_25 ( V_56 , L_14 ,
( V_53 & F_17 ( 19 ) ) >> 19 ) ;
F_25 ( V_56 , L_15 , V_49 ) ;
F_25 ( V_56 , L_16 ,
V_49 & F_17 ( 0 ) ) ;
F_25 ( V_56 , L_17 ,
( V_49 & F_17 ( 1 ) ) >> 1 ) ;
F_25 ( V_56 , L_18 ,
( V_49 & F_17 ( 2 ) ) >> 2 ) ;
F_25 ( V_56 , L_19 ,
( V_49 & F_17 ( 7 ) ) >> 7 ) ;
F_25 ( V_56 , L_20 ,
( V_49 & F_17 ( 8 ) ) >> 8 ) ;
F_25 ( V_56 , L_21 ,
( V_49 & F_17 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_26 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_27 ( V_58 , F_24 , V_57 -> V_59 ) ;
}
static void F_28 ( struct V_60 * V_61 )
{
int V_53 ;
F_2 () ;
F_12 ( V_6 , 17 , 11 ) ;
V_53 = V_6 -> V_50 [ 1 ] ;
if ( V_62 ) {
F_21 ( V_62 , 1 , V_53 ) ;
F_18 ( V_62 , 1 , V_53 ) ;
}
if ( V_63 ) {
F_21 ( V_63 , 2 , V_53 ) ;
F_18 ( V_63 , 2 , V_53 ) ;
}
if ( V_64 ) {
F_21 ( V_64 , 3 , V_53 ) ;
F_18 ( V_64 , 3 , V_53 ) ;
}
F_4 () ;
}
static bool F_29 ( unsigned char V_44 , unsigned char V_65 ,
struct V_66 * V_67 )
{
static bool V_68 ;
if ( V_65 & V_69 )
return false ;
if ( F_30 ( V_44 == 0xe0 ) ) {
V_68 = true ;
return false ;
} else if ( F_30 ( V_68 ) ) {
switch ( V_44 ) {
case 0x8 :
F_31 ( & V_70 ,
F_32 ( V_71 / 4 ) ) ;
break;
}
V_68 = false ;
}
return false ;
}
static int T_1 F_33 ( void )
{
int V_53 , V_72 , V_73 ;
const char * V_74 ;
V_73 = 0 ;
V_74 = F_34 ( V_75 ) ;
if ( V_74 && ( strncmp ( V_74 , L_22 , 8 ) == 0 ||
strncmp ( V_74 , L_23 , 9 ) == 0 ) )
V_73 = 1 ;
if ( ! V_76 && ! V_73 )
return 0 ;
F_2 () ;
F_12 ( V_6 , 17 , 11 ) ;
V_53 = V_6 -> V_50 [ 1 ] ;
V_6 -> V_51 [ 0 ] = 0x2 ;
F_12 ( V_6 , 17 , 11 ) ;
V_49 = V_6 -> V_50 [ 1 ] ;
F_4 () ;
if ( ! ( V_53 & F_17 ( 0 ) ) ) {
if ( V_76 ) {
V_49 &= ~ 7 ;
} else {
return 0 ;
}
}
if ( ( V_53 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_62 = F_35 ( L_24 , & V_77 -> V_78 ,
V_79 ,
& V_80 , ( void * ) 1 ) ;
if ( ! V_62 ) {
V_72 = - V_81 ;
goto V_82;
}
V_72 = F_36 ( V_62 ) ;
if ( V_72 )
goto V_82;
}
if ( ( V_53 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_63 = F_35 ( L_25 ,
& V_77 -> V_78 ,
V_83 ,
& V_80 , ( void * ) 2 ) ;
if ( ! V_63 ) {
V_72 = - V_81 ;
goto V_84;
}
V_72 = F_36 ( V_63 ) ;
if ( V_72 )
goto V_84;
}
if ( ( V_53 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_64 = F_35 ( L_26 ,
& V_77 -> V_78 ,
V_85 ,
& V_80 , ( void * ) 3 ) ;
if ( ! V_64 ) {
V_72 = - V_81 ;
goto V_86;
}
V_72 = F_36 ( V_64 ) ;
if ( V_72 )
goto V_86;
}
V_72 = F_37 ( F_29 ) ;
if ( V_72 ) {
F_38 ( L_27 ) ;
goto V_87;
}
return 0 ;
V_87:
if ( V_64 )
F_39 ( V_64 ) ;
V_86:
F_40 ( V_64 ) ;
if ( V_63 )
F_39 ( V_63 ) ;
V_84:
F_40 ( V_63 ) ;
if ( V_62 )
F_39 ( V_62 ) ;
V_82:
F_40 ( V_62 ) ;
return V_72 ;
}
static void F_41 ( void )
{
if ( V_62 ) {
F_39 ( V_62 ) ;
F_40 ( V_62 ) ;
}
if ( V_63 ) {
F_39 ( V_63 ) ;
F_40 ( V_63 ) ;
}
if ( V_64 ) {
F_39 ( V_64 ) ;
F_40 ( V_64 ) ;
}
}
static int F_42 ( struct V_88 * V_89 )
{
int V_72 = 0 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = F_11 ( V_90 ) ;
V_6 -> V_51 [ 1 ] = V_89 -> V_91 . V_92 ;
if ( V_6 -> V_51 [ 0 ] == - 1 ) {
V_72 = - V_93 ;
goto V_94;
}
if ( F_43 () > 0 )
F_12 ( V_6 , 1 , 2 ) ;
else
F_12 ( V_6 , 1 , 1 ) ;
V_94:
F_4 () ;
return V_72 ;
}
static int F_44 ( struct V_88 * V_89 )
{
int V_72 = 0 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = F_11 ( V_90 ) ;
if ( V_6 -> V_51 [ 0 ] == - 1 ) {
V_72 = - V_93 ;
goto V_94;
}
if ( F_43 () > 0 )
F_12 ( V_6 , 0 , 2 ) ;
else
F_12 ( V_6 , 0 , 1 ) ;
V_72 = V_6 -> V_50 [ 1 ] ;
V_94:
F_4 () ;
return V_72 ;
}
static void F_45 ( void )
{
int V_33 = 0x97 ;
char V_44 = 1 ;
F_46 ( & V_44 , V_33 | 1 << 12 ) ;
}
static void F_47 ( void )
{
int V_33 = 0x97 ;
char V_44 = 2 ;
F_46 ( & V_44 , V_33 | 1 << 12 ) ;
}
static void F_48 ( struct V_95 * V_96 ,
enum V_97 V_40 )
{
if ( V_40 > 0 )
F_45 () ;
else
F_47 () ;
}
static int T_1 F_49 ( struct V_98 * V_78 )
{
return F_50 ( V_78 , & V_99 ) ;
}
static void F_51 ( void )
{
F_52 ( & V_99 ) ;
}
static int F_53 ( struct V_100 * V_101 )
{
T_2 V_102 ;
int V_72 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = 0x0 ;
F_12 ( V_6 , 4 , 11 ) ;
V_72 = V_6 -> V_50 [ 0 ] ;
if ( V_72 ) {
V_72 = F_15 ( V_72 ) ;
goto V_94;
}
V_101 -> V_103 = V_6 -> V_50 [ 1 ] & 0xFFFF ;
V_101 -> type = ( V_6 -> V_50 [ 1 ] >> 24 ) & 0xFF ;
V_101 -> V_104 = V_6 -> V_50 [ 2 ] & 0xFF ;
V_102 = ( V_6 -> V_50 [ 2 ] >> 8 ) & 0xFF ;
V_101 -> V_105 = ( V_6 -> V_50 [ 2 ] >> 16 ) & 0xFF ;
if ( V_102 & F_17 ( 0 ) )
V_101 -> V_106 = ( V_6 -> V_50 [ 3 ] >> 0 ) & 0xFF ;
if ( V_102 & F_17 ( 1 ) )
V_101 -> V_107 = ( V_6 -> V_50 [ 3 ] >> 8 ) & 0xFF ;
if ( V_102 & F_17 ( 2 ) )
V_101 -> V_108 = ( V_6 -> V_50 [ 3 ] >> 16 ) & 0xFF ;
if ( V_102 & F_17 ( 3 ) )
V_101 -> V_109 = ( V_6 -> V_50 [ 3 ] >> 24 ) & 0xFF ;
V_94:
F_4 () ;
return V_72 ;
}
static unsigned int F_54 ( void )
{
if ( V_100 . V_105 != 0 )
return V_100 . V_105 ;
if ( V_110 > 0 )
return V_110 - 1 ;
return 0 ;
}
static int F_55 ( struct V_111 * V_112 )
{
int V_26 ;
if ( V_100 . V_105 != 0 )
return V_112 -> V_113 ;
if ( V_110 > 0 ) {
for ( V_26 = 0 ; V_26 < V_110 ; ++ V_26 )
if ( V_114 [ V_26 ] == V_112 -> V_115 )
return V_26 ;
return 0 ;
}
return - V_43 ;
}
static int F_56 ( struct V_111 * V_112 , T_2 V_113 )
{
if ( V_100 . V_105 != 0 ) {
if ( V_113 != 0 )
V_116 = V_113 ;
if ( V_112 -> V_113 == V_113 )
return 0 ;
V_112 -> V_113 = V_113 ;
if ( V_113 != 0 && V_112 -> V_115 == V_117 )
V_112 -> V_115 = V_118 ;
else if ( V_113 == 0 && V_112 -> V_115 != V_117 ) {
V_118 = V_112 -> V_115 ;
V_112 -> V_115 = V_117 ;
}
return 0 ;
}
if ( V_110 > 0 && V_113 < V_110 ) {
if ( V_113 != 0 )
V_116 = V_113 ;
V_112 -> V_115 = V_114 [ V_113 ] ;
return 0 ;
}
return - V_43 ;
}
static int F_57 ( struct V_111 * V_112 )
{
int V_72 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = 0x1 ;
F_12 ( V_6 , 4 , 11 ) ;
V_72 = V_6 -> V_50 [ 0 ] ;
if ( V_72 ) {
V_72 = F_15 ( V_72 ) ;
goto V_94;
}
V_112 -> V_115 = F_58 ( V_6 -> V_50 [ 1 ] & 0xFFFF ) ;
if ( V_112 -> V_115 != 0 )
V_112 -> V_115 -- ;
V_112 -> V_104 = ( V_6 -> V_50 [ 1 ] >> 16 ) & 0xFF ;
V_112 -> V_119 = ( V_6 -> V_50 [ 1 ] >> 24 ) & 0x3F ;
V_112 -> V_120 = ( V_6 -> V_50 [ 1 ] >> 30 ) & 0x3 ;
V_112 -> V_121 = V_6 -> V_50 [ 2 ] & 0xFF ;
V_112 -> V_122 = ( V_6 -> V_50 [ 2 ] >> 8 ) & 0xFF ;
V_112 -> V_113 = ( V_6 -> V_50 [ 2 ] >> 16 ) & 0xFF ;
V_94:
F_4 () ;
return V_72 ;
}
static int F_59 ( struct V_111 * V_112 )
{
int V_72 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = 0x2 ;
V_6 -> V_51 [ 1 ] = F_17 ( V_112 -> V_115 ) & 0xFFFF ;
V_6 -> V_51 [ 1 ] |= ( V_112 -> V_104 & 0xFF ) << 16 ;
V_6 -> V_51 [ 1 ] |= ( V_112 -> V_119 & 0x3F ) << 24 ;
V_6 -> V_51 [ 1 ] |= ( V_112 -> V_120 & 0x3 ) << 30 ;
V_6 -> V_51 [ 2 ] = V_112 -> V_121 & 0xFF ;
V_6 -> V_51 [ 2 ] |= ( V_112 -> V_113 & 0xFF ) << 16 ;
F_12 ( V_6 , 4 , 11 ) ;
V_72 = V_6 -> V_50 [ 0 ] ;
F_4 () ;
return F_15 ( V_72 ) ;
}
static int F_60 ( struct V_111 * V_112 , struct V_111 * V_123 )
{
int V_72 ;
V_72 = F_59 ( V_112 ) ;
if ( V_72 == 0 )
return 0 ;
if ( F_59 ( V_123 ) )
F_61 ( L_28 ) ;
return V_72 ;
}
static int F_62 ( T_2 V_124 )
{
int V_28 ;
int V_72 ;
if ( V_124 >= F_63 ( V_125 ) )
return - V_43 ;
V_28 = F_10 ( V_125 [ V_124 ] ) ;
if ( V_28 == - 1 )
return - V_43 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = V_21 [ V_28 ] . V_29 ;
V_6 -> V_51 [ 1 ] = V_21 [ V_28 ] . V_40 ;
F_12 ( V_6 , 1 , 0 ) ;
V_72 = V_6 -> V_50 [ 0 ] ;
F_4 () ;
return F_15 ( V_72 ) ;
}
static int F_64 ( T_2 V_124 )
{
int V_28 ;
int V_72 ;
int V_126 ;
if ( V_124 >= F_63 ( V_125 ) )
return - V_43 ;
V_28 = F_10 ( V_125 [ V_124 ] ) ;
if ( V_28 == - 1 )
return - V_43 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = V_21 [ V_28 ] . V_29 ;
F_12 ( V_6 , 0 , 0 ) ;
V_72 = V_6 -> V_50 [ 0 ] ;
V_126 = V_6 -> V_50 [ 1 ] ;
F_4 () ;
if ( V_72 )
return F_15 ( V_72 ) ;
return ( V_126 == V_21 [ V_28 ] . V_40 ) ;
}
static int F_65 ( void )
{
int V_26 ;
int V_72 ;
for ( V_26 = 0 ; V_26 < F_63 ( V_125 ) ; ++ V_26 ) {
V_72 = F_64 ( V_26 ) ;
if ( V_72 == 1 )
return V_26 ;
}
return V_72 ;
}
static int F_66 ( void )
{
return F_67 ( V_127 ) ;
}
static inline int F_68 ( void )
{
struct V_111 V_112 ;
int V_72 ;
int V_26 ;
V_72 = F_53 ( & V_100 ) ;
if ( V_72 )
return V_72 ;
F_57 ( & V_112 ) ;
if ( V_100 . V_106 > 63 )
V_100 . V_106 = 63 ;
if ( V_100 . V_107 > 63 )
V_100 . V_107 = 63 ;
if ( V_100 . V_108 > 63 )
V_100 . V_108 = 63 ;
if ( V_100 . V_109 > 63 )
V_100 . V_109 = 63 ;
V_100 . V_103 &= ~ F_17 ( V_128 ) ;
V_116 = F_55 ( & V_112 ) ;
V_118 = V_112 . V_115 ;
if ( V_116 == 0 && F_54 () != 0 )
V_116 = 1 ;
if ( V_118 == V_117 ) {
V_118 =
F_58 ( V_100 . V_103 & ~ F_17 ( V_117 ) ) ;
if ( V_118 != 0 )
V_118 -- ;
}
if ( V_100 . V_103 & ( F_17 ( V_129 ) |
F_17 ( V_130 ) ) )
V_131 = true ;
if ( V_100 . V_103 & (
F_17 ( V_130 ) | F_17 ( V_132 ) |
F_17 ( V_133 ) | F_17 ( V_134 ) |
F_17 ( V_135 ) | F_17 ( V_136 )
) )
V_137 = true ;
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 )
if ( F_69 ( V_26 ) && ( F_17 ( V_26 ) & V_100 . V_103 ) )
V_114 [ 1 + V_110 ++ ] = V_26 ;
if ( V_110 > 0 ) {
for ( V_26 = 0 ; V_26 < 16 ; ++ V_26 ) {
if ( F_17 ( V_26 ) & V_100 . V_103 ) {
V_114 [ 0 ] = V_26 ;
break;
}
}
V_110 ++ ;
}
return 0 ;
}
static inline void F_70 ( void )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < F_63 ( V_125 ) ; ++ V_26 )
if ( F_10 ( V_125 [ V_26 ] ) != - 1 )
V_127 |= F_17 ( V_26 ) ;
}
static void F_71 ( void )
{
int V_72 ;
V_72 = F_68 () ;
F_70 () ;
if ( V_127 != 0 || V_72 == 0 )
V_138 = true ;
}
static T_3 F_72 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
const char * V_141 , T_4 V_142 )
{
struct V_111 V_143 ;
struct V_111 V_112 ;
bool V_144 ;
int V_40 ;
int V_72 ;
char V_145 ;
T_2 V_146 ;
int V_26 ;
V_72 = sscanf ( V_141 , L_29 , & V_40 , & V_145 ) ;
if ( V_72 < 1 )
return - V_43 ;
else if ( V_72 == 1 )
V_145 = 's' ;
if ( V_40 < 0 )
return - V_43 ;
V_144 = false ;
switch ( V_145 ) {
case 's' :
if ( V_40 > V_100 . V_106 )
V_144 = true ;
V_146 = V_147 ;
break;
case 'm' :
if ( V_40 > V_100 . V_107 )
V_144 = true ;
V_146 = V_148 ;
break;
case 'h' :
if ( V_40 > V_100 . V_108 )
V_144 = true ;
V_146 = V_149 ;
break;
case 'd' :
if ( V_40 > V_100 . V_109 )
V_144 = true ;
V_146 = V_150 ;
break;
default:
return - V_43 ;
}
if ( V_3 && V_3 -> V_151 )
V_144 = true ;
if ( V_144 ) {
switch ( V_146 ) {
case V_150 :
V_40 *= 24 ;
case V_149 :
V_40 *= 60 ;
case V_148 :
V_40 *= 60 ;
V_146 = V_147 ;
}
if ( V_3 && V_3 -> V_151 ) {
for ( V_26 = 0 ; V_3 -> V_152 [ V_26 ] != - 1 ; V_26 ++ ) {
if ( V_40 <= V_3 -> V_152 [ V_26 ] ) {
V_40 = V_3 -> V_152 [ V_26 ] ;
break;
}
}
}
if ( V_40 <= V_100 . V_106 && V_100 . V_106 ) {
V_146 = V_147 ;
} else if ( V_40 / 60 <= V_100 . V_107 && V_100 . V_107 ) {
V_40 /= 60 ;
V_146 = V_148 ;
} else if ( V_40 / ( 60 * 60 ) <= V_100 . V_108 && V_100 . V_108 ) {
V_40 /= ( 60 * 60 ) ;
V_146 = V_149 ;
} else if ( V_40 / ( 60 * 60 * 24 ) <= V_100 . V_109 && V_100 . V_109 ) {
V_40 /= ( 60 * 60 * 24 ) ;
V_146 = V_150 ;
} else {
return - V_43 ;
}
}
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
V_143 = V_112 ;
V_143 . V_119 = V_40 ;
V_143 . V_120 = V_146 ;
V_72 = F_60 ( & V_143 , & V_112 ) ;
if ( V_72 )
return V_72 ;
return V_142 ;
}
static T_3 F_73 ( struct V_98 * V_78 ,
struct V_139 * V_140 , char * V_141 )
{
struct V_111 V_112 ;
int V_72 ;
int V_153 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
V_153 = sprintf ( V_141 , L_30 , V_112 . V_119 ) ;
switch ( V_112 . V_120 ) {
case V_147 :
return V_153 + sprintf ( V_141 + V_153 , L_31 ) ;
case V_148 :
return V_153 + sprintf ( V_141 + V_153 , L_32 ) ;
case V_149 :
return V_153 + sprintf ( V_141 + V_153 , L_33 ) ;
case V_150 :
return V_153 + sprintf ( V_141 + V_153 , L_34 ) ;
default:
return - V_43 ;
}
return V_153 ;
}
static T_3 F_74 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
const char * V_141 , T_4 V_142 )
{
struct V_111 V_143 ;
struct V_111 V_112 ;
bool V_154 = false ;
int V_155 = - 1 ;
char V_156 [ 21 ] ;
int V_26 , V_72 ;
V_72 = sscanf ( V_141 , L_35 , V_156 ) ;
if ( V_72 != 1 )
return - V_43 ;
if ( V_156 [ 0 ] != '+' && V_156 [ 0 ] != '-' )
return - V_43 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
if ( V_137 )
V_154 = F_75 ( V_112 . V_115 ) ;
if ( V_137 ) {
for ( V_26 = 0 ; V_26 < F_63 ( V_157 ) ; ++ V_26 ) {
if ( ! ( V_100 . V_104 & F_17 ( V_26 ) ) )
continue;
if ( ! V_157 [ V_26 ] )
continue;
if ( strcmp ( V_156 + 1 , V_157 [ V_26 ] ) != 0 )
continue;
if ( V_156 [ 0 ] == '+' &&
V_154 && ( V_112 . V_104 & F_17 ( V_26 ) ) )
return V_142 ;
if ( V_156 [ 0 ] == '-' &&
( ! V_154 || ! ( V_112 . V_104 & F_17 ( V_26 ) ) ) )
return V_142 ;
V_155 = V_26 ;
break;
}
}
if ( V_155 != - 1 ) {
V_143 = V_112 ;
if ( V_156 [ 0 ] == '+' )
V_143 . V_104 |= F_17 ( V_155 ) ;
else {
V_143 . V_104 &= ~ F_17 ( V_155 ) ;
if ( V_155 == 1 )
V_143 . V_104 &= ~ F_17 ( 2 ) ;
}
if ( ( V_100 . V_104 & V_143 . V_104 ) !=
V_143 . V_104 )
return - V_43 ;
if ( V_143 . V_104 && ! V_154 ) {
V_143 . V_115 = V_132 ;
F_56 ( & V_143 , V_116 ) ;
} else if ( V_143 . V_104 == 0 ) {
F_56 ( & V_143 , 0 ) ;
}
if ( ! ( V_100 . V_103 & F_17 ( V_143 . V_115 ) ) )
return - V_43 ;
V_72 = F_60 ( & V_143 , & V_112 ) ;
if ( V_72 )
return V_72 ;
if ( V_143 . V_115 != V_117 )
V_118 = V_143 . V_115 ;
return V_142 ;
}
return - V_43 ;
}
static T_3 F_76 ( struct V_98 * V_78 ,
struct V_139 * V_140 , char * V_141 )
{
struct V_111 V_112 ;
bool V_154 ;
int V_113 , V_26 , V_72 ;
int V_153 = 0 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
V_153 = 0 ;
if ( V_137 ) {
V_154 = F_75 ( V_112 . V_115 ) ;
V_113 = F_55 ( & V_112 ) ;
for ( V_26 = 0 ; V_26 < F_63 ( V_157 ) ; ++ V_26 ) {
if ( ! ( V_100 . V_104 & F_17 ( V_26 ) ) )
continue;
if ( ! V_157 [ V_26 ] )
continue;
if ( ( V_154 || V_113 <= 0 ) &&
( V_112 . V_104 & F_17 ( V_26 ) ) )
V_141 [ V_153 ++ ] = '+' ;
else
V_141 [ V_153 ++ ] = '-' ;
V_153 += sprintf ( V_141 + V_153 , L_36 , V_157 [ V_26 ] ) ;
}
}
if ( V_153 )
V_141 [ V_153 - 1 ] = '\n' ;
return V_153 ;
}
static T_3 F_77 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
const char * V_141 , T_4 V_142 )
{
struct V_111 V_143 ;
struct V_111 V_112 ;
bool V_154 = false ;
int V_158 ;
int V_72 ;
V_72 = F_78 ( V_141 , 0 , & V_158 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
if ( V_158 == F_79 ( V_112 . V_115 ) )
return V_142 ;
V_143 = V_112 ;
if ( V_137 )
V_154 = F_75 ( V_112 . V_115 ) ;
if ( V_158 ) {
if ( V_154 )
V_143 . V_115 = V_130 ;
else
V_143 . V_115 = V_129 ;
} else {
if ( V_154 ) {
V_143 . V_115 = V_132 ;
F_56 ( & V_143 , V_116 ) ;
} else {
V_143 . V_115 = V_128 ;
}
}
if ( ! ( V_100 . V_103 & F_17 ( V_143 . V_115 ) ) )
return - V_43 ;
V_72 = F_60 ( & V_143 , & V_112 ) ;
if ( V_72 )
return V_72 ;
V_118 = V_143 . V_115 ;
return V_142 ;
}
static T_3 F_80 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
char * V_141 )
{
struct V_111 V_112 ;
bool V_159 = false ;
int V_72 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
V_159 = F_79 ( V_112 . V_115 ) ;
return sprintf ( V_141 , L_37 , V_159 ? 1 : 0 ) ;
}
static T_3 F_81 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
const char * V_141 , T_4 V_142 )
{
struct V_111 V_112 ;
struct V_111 V_143 ;
T_2 V_160 ;
int V_72 ;
V_72 = F_82 ( V_141 , 10 , & V_160 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
V_143 = V_112 ;
V_143 . V_121 = V_160 ;
V_72 = F_60 ( & V_143 , & V_112 ) ;
if ( V_72 )
return V_72 ;
return V_142 ;
}
static T_3 F_83 ( struct V_98 * V_78 ,
struct V_139 * V_140 ,
char * V_141 )
{
struct V_111 V_112 ;
int V_72 ;
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return V_72 ;
return sprintf ( V_141 , L_37 , V_112 . V_121 ) ;
}
static enum V_97 F_84 ( struct V_95 * V_96 )
{
int V_72 ;
T_5 V_161 ;
struct V_111 V_112 ;
if ( F_54 () ) {
V_72 = F_57 ( & V_112 ) ;
if ( V_72 )
return 0 ;
V_72 = F_55 ( & V_112 ) ;
if ( V_72 < 0 )
return 0 ;
return V_72 ;
}
if ( F_66 () ) {
V_72 = F_65 () ;
if ( V_72 < 0 )
return 0 ;
for ( V_161 = V_127 ; V_161 != 0 && V_72 > 0 ; -- V_72 )
V_161 &= V_161 - 1 ;
if ( V_161 == 0 )
return 0 ;
return F_58 ( V_161 ) - 1 ;
}
F_38 ( L_38 ) ;
return 0 ;
}
static void F_85 ( struct V_95 * V_96 ,
enum V_97 V_40 )
{
struct V_111 V_112 ;
struct V_111 V_143 ;
T_5 V_161 ;
if ( F_54 () ) {
if ( F_57 ( & V_112 ) )
return;
V_143 = V_112 ;
if ( F_56 ( & V_143 , V_40 ) )
return;
F_60 ( & V_143 , & V_112 ) ;
return;
}
if ( F_66 () ) {
for ( V_161 = V_127 ; V_161 != 0 && V_40 > 0 ; -- V_40 )
V_161 &= V_161 - 1 ;
if ( V_161 == 0 )
return;
F_62 ( F_58 ( V_161 ) - 1 ) ;
return;
}
F_38 ( L_38 ) ;
}
static int T_1 F_86 ( struct V_98 * V_78 )
{
F_71 () ;
if ( ! V_138 )
return - V_93 ;
if ( ! V_131 )
V_162 [ 1 ] = NULL ;
V_163 . V_164 = F_54 () ;
if ( ! V_163 . V_164 ) {
V_163 . V_164 = F_66 () ;
if ( V_163 . V_164 )
V_163 . V_164 -- ;
}
return F_50 ( V_78 , & V_163 ) ;
}
static void F_87 ( struct V_95 * V_96 ,
enum V_97 V_40 )
{
}
static void F_88 ( void )
{
if ( ! V_138 )
return;
V_163 . V_165 = F_87 ;
F_52 ( & V_163 ) ;
}
static int T_1 F_89 ( void )
{
int V_166 = 0 ;
int V_72 ;
if ( ! F_90 ( V_167 ) )
return - V_93 ;
V_3 = NULL ;
F_90 ( V_168 ) ;
F_91 ( F_9 , NULL ) ;
if ( ! V_21 ) {
F_92 ( L_39 ) ;
return - V_93 ;
}
V_72 = F_93 ( & V_169 ) ;
if ( V_72 )
goto V_170;
V_77 = F_94 ( L_40 , - 1 ) ;
if ( ! V_77 ) {
V_72 = - V_81 ;
goto V_171;
}
V_72 = F_95 ( V_77 ) ;
if ( V_72 )
goto V_172;
V_173 = F_96 ( V_23 | V_174 ) ;
if ( ! V_173 ) {
V_72 = - V_81 ;
goto V_175;
}
V_6 = F_97 ( V_173 ) ;
V_72 = F_33 () ;
if ( V_72 ) {
F_38 ( L_41 ) ;
goto V_176;
}
if ( V_3 && V_3 -> V_99 )
F_49 ( & V_77 -> V_78 ) ;
F_86 ( & V_77 -> V_78 ) ;
V_177 = F_98 ( L_42 , NULL ) ;
if ( V_177 != NULL )
F_99 ( L_43 , 0444 , V_177 , NULL ,
& V_178 ) ;
#ifdef F_100
if ( F_101 () )
return 0 ;
#endif
F_2 () ;
V_6 -> V_51 [ 0 ] = F_11 ( V_90 ) ;
if ( V_6 -> V_51 [ 0 ] != - 1 ) {
F_12 ( V_6 , 0 , 2 ) ;
V_166 = V_6 -> V_50 [ 3 ] ;
}
F_4 () ;
if ( V_166 ) {
struct V_179 V_91 ;
memset ( & V_91 , 0 , sizeof( struct V_179 ) ) ;
V_91 . type = V_180 ;
V_91 . V_164 = V_166 ;
V_181 = F_102 ( L_44 ,
& V_77 -> V_78 ,
NULL ,
& V_182 ,
& V_91 ) ;
if ( F_103 ( V_181 ) ) {
V_72 = F_104 ( V_181 ) ;
V_181 = NULL ;
goto V_183;
}
V_181 -> V_91 . V_92 =
F_44 ( V_181 ) ;
F_105 ( V_181 ) ;
}
return 0 ;
V_183:
F_106 ( F_29 ) ;
F_107 ( & V_70 ) ;
F_41 () ;
V_176:
F_108 ( ( unsigned long ) V_173 ) ;
V_175:
F_109 ( V_77 ) ;
V_172:
F_110 ( V_77 ) ;
V_171:
F_111 ( & V_169 ) ;
V_170:
F_112 ( V_21 ) ;
return V_72 ;
}
static void T_6 F_113 ( void )
{
F_114 ( V_177 ) ;
if ( V_3 && V_3 -> V_99 )
F_51 () ;
F_88 () ;
F_106 ( F_29 ) ;
F_107 ( & V_70 ) ;
F_115 ( V_181 ) ;
F_41 () ;
if ( V_77 ) {
F_116 ( V_77 ) ;
F_111 ( & V_169 ) ;
}
F_112 ( V_21 ) ;
F_108 ( ( unsigned long ) V_6 ) ;
}
